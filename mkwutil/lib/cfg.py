from itertools import chain
from mkwutil.ppc_dis import *

def is_flow_control_instr(instr):
  if not instr.is_branch():
    return False

  # Ignore bl/bctrl
  if instr.is_link():
    return False

  # Jump tables not supported yet
  assert instr != "bctr"

  # TODO: Handle tailcalls

  return True

def basic_slices_of(instructions):
  slices = []
  for i, instr in enumerate(instructions):
    if not is_flow_control_instr(instr):
      continue

    # returns
    if instr.is_blr():
      yield i + 1
      continue

    fallthrough = i + 1
    branch_dest = instr.instruction_step() + i    

    if instr.is_conditional():
      yield fallthrough # The next instruction is not part of this block
    
    yield branch_dest # The branch dest starts a new basic block

class BasicBlock:
  def __init__(self, instruction_start_addr, instructions):
    self.instructions = instructions
    self.instruction_start_addr = instruction_start_addr

    self.pred = []
    self.succ = []

    self.dominates = []
    self.dominated = []

def basic_block_id_from_addr(blocks, addr):
  for i, block in enumerate(blocks):
    if block.instruction_start_addr == addr:
      return i

  raise RuntimeError("Cannot find basic block with block index %s" % addr)

def split_by_indices(some_list, *args):
  if args:
    args = (0,) + tuple(data for data in args) + (len(some_list)+1,)

  return [some_list[start:end] for start, end in zip(args, args[1:])]
  
def orphaned_basic_blocks_of(instructions):
  slices = set()

  for slice in basic_slices_of(instructions):
    # Nothing we can do
    if slice <= 0 or slice > len(instructions):
      continue

    slices.add(slice)

  blocks = []

  addr = 0
  for b in split_by_indices(instructions, *sorted(slices)):
    blocks.append(BasicBlock(addr, b))
    addr += len(b) 

  return blocks

def compute_succ_pred(basic_blocks):
  for block_id, block in enumerate(basic_blocks):
    flow_control = block.instructions[-1]
    flow_control_idx = block.instruction_start_addr + len(block.instructions) - 1
    
    if flow_control.is_blr():
      continue

    fallthrough = flow_control_idx + 1
    
    if not is_flow_control_instr(flow_control):
      fallthrough_blockid = basic_block_id_from_addr(basic_blocks, fallthrough)
      block.succ.append(fallthrough_blockid)
      basic_blocks[fallthrough_blockid].pred.append(block_id)
      return

    branch_dest = flow_control_idx + flow_control.instruction_step()

    if flow_control.is_conditional():
      fallthrough_blockid = basic_block_id_from_addr(basic_blocks, fallthrough)
      block.succ.append(fallthrough_blockid)
      basic_blocks[fallthrough_blockid].pred.append(block_id)

    branch_dest_blockid = basic_block_id_from_addr(basic_blocks, branch_dest)
    block.succ.append(branch_dest_blockid)
    basic_blocks[branch_dest_blockid].pred.append(block_id)

def dump_cfg(basic_blocks):
  print("digraph func {")
  print("node [shape=record fontname=Arial];")
  for block_id, block in enumerate(basic_blocks):
    print("%s [label=\"%s\"]" % (block_id, "\\n".join(ins.disassemble()[len("/* 8019B3A8  2C 03 00 00 */"):] for ins in block.instructions)))

  # Succeeds
  for block_id, block in enumerate(basic_blocks):
    for succ in block.succ:
      print("%s -> %s" % (block_id, succ))

  # Strictly Dominates
  # for block_id, block in enumerate(basic_blocks):
  #   for dom in block.dominates:
  #     if dom != block_id:
  #       print("%s -> %s" % (block_id, dom))
  
  print("}")

class CFG:
  def __init__(self, blocks):
    self.blocks = []

# so_far prevents infinite recursion on back-edges
def all_reachable_by(basic_blocks, block, so_far):
  if not basic_blocks[block].succ:
    return []

  blocks = [block]

  for s in basic_blocks[block].succ:
    blocks += [s]
    if s not in so_far:
      blocks += all_reachable_by(basic_blocks, s, blocks)

  return sorted(list(set(blocks)))

# Compute dominator set of node n
def compute_dom(blocks, n, seen = []):
  pred_doms = []
  for p in blocks[n].pred:
    if p not in seen:
      pred_doms.append(compute_dom(blocks, p, seen))
      seen.append(p)

  for i in range(1, len(pred_doms)):
    pred_doms[0] = pred_doms[0].intersection(pred_doms[i])

  if not pred_doms:
    return set([n])

  return set([n]).union(pred_doms[0])


def compute_dominators(basic_blocks):
  # TODO: this is a shit algorithm, and we could at least memoise it
  for block_id, block in enumerate(basic_blocks):
    block.reaches = all_reachable_by(basic_blocks, block_id, [])
    block.reached_by = []
  for block_id, block in enumerate(basic_blocks):
    for r in block.reaches:
      basic_blocks[r].reached_by.append(block_id)

  for b in range(len(basic_blocks)):
    basic_blocks[b].dominated = compute_dom(basic_blocks, b)
    print(basic_blocks[b].dominated)
    for d in basic_blocks[b].dominated:
      print(d)
      basic_blocks[d].dominates.append(b)


def compute_basic_blocks(instructions):
  basic_blocks = orphaned_basic_blocks_of(instructions)

  compute_succ_pred(basic_blocks)
  # compute_dominators(basic_blocks)
  dump_cfg(basic_blocks)

  return basic_blocks

def has_prologue(entry):
  return entry.instructions[0].insn.id == PPC_INS_STWU

def stack_store_reg(stack_size):
  stack_size = stack_size[:stack_size.rfind('(r1)')]
  stack_size = stack_size[stack_size.find(' ')+1:]
  stack_size = int(stack_size, 16)
  return stack_size

def stack_store_offset(stack_size):
  stack_size = stack_size[1:stack_size.find(',')]
  stack_size = int(stack_size)
  return stack_size

def compute_flow(instructions):
  basic_blocks = compute_basic_blocks(instructions)

  # Assume one exit point (cw)
  entry = basic_blocks[0]
  exit = next(b for b in basic_blocks if not len(b.succ))
  # It's possible entry == exit, if the function is only one basic block

  if not has_prologue(entry):
    return

  stack_size = -stack_store_offset(entry.instructions[0].insn.op_str)

  assert entry.instructions[1].insn.id == PPC_INS_MFLR
  
  pro_candidates = []
  for i, ins in enumerate(entry.instructions[2:]):
    if ins.insn.id != PPC_INS_STW:
      continue
    op = ins.insn.op_str
    if '(r1)' not in op:
      continue
    reg = stack_store_reg(op)
    ofs = stack_store_offset(op)

    if reg == 0:
      continue

    if reg < 25:
      continue

    pro_candidates.append((i + 2, reg, ofs))

  # TODO: Verify candidates by checking epilogue

  return list

  raise SystemExit("Test")
  
