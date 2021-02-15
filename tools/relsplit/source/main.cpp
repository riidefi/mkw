#include "RelFile.hpp"
#include "low/LowRel.hpp"
#include <fstream>
#include <vector>

auto read_file(const char* path) {
  std::ifstream input(path, std::ios::binary);

  // copies all data into buffer
  std::vector<char> buffer(std::istreambuf_iterator<char>(input), {});
  return buffer;
}

const char* to_str(low::R type) {
  switch (type) {
  case low::R::R_PPC_NONE:
    return "R_PPC_NONE";
  case low::R::R_PPC_ADDR32:
    return "R_PPC_ADDR32";
  case low::R::R_PPC_ADDR24:
    return "R_PPC_ADDR24";
  case low::R::R_PPC_ADDR16:
    return "R_PPC_ADDR16";
  case low::R::R_PPC_ADDR16_LO:
    return "R_PPC_ADDR16_LO";
  case low::R::R_PPC_ADDR16_HI:
    return "R_PPC_ADDR16_HI";
  case low::R::R_PPC_ADDR16_HA:
    return "R_PPC_ADDR16_HA";
  case low::R::R_PPC_ADDR14:
    return "R_PPC_ADDR14";
  case low::R::R_PPC_ADDR14_BRTAKEN:
    return "R_PPC_ADDR14_BRTAKEN";
  case low::R::R_PPC_ADDR14_BRNTAKEN:
    return "R_PPC_ADDR14_BRNTAKEN";
  case low::R::R_PPC_REL24:
    return "R_PPC_REL24";
  case low::R::R_PPC_REL14:
    return "R_PPC_REL14";
  case low::R::R_PPC_REL14_BRTAKEN:
    return "R_PPC_REL14_BRTAKEN";
  case low::R::R_PPC_REL14_BRNTAKEN:
    return "R_PPC_REL14_BRNTAKEN";
  case low::R::R_RVL_NONE:
    return "R_RVL_NONE";
  case low::R::R_RVL_SECT:
    return "R_RVL_SECT";
  case low::R::R_RVL_STOP:
    return "R_RVL_STOP";
  default:
    return "Unknown";
  }
}

void dump_relocs(const u8* data_begin, const u8* data_end, bool is_main_dol,
                 std::vector<u32>& sizes) {
  auto* start = data_begin;
  while (data_begin < data_end) {
    low::Reloc reloc = *(low::Reloc*)data_begin;
    data_begin += sizeof(low::Reloc);
    low::flip(reloc);

    if ((low::R)reloc.type == low::R::R_RVL_SECT)
      printf("offset: %u, type: %s, section: %u, addend: 0x%x\n",
             (unsigned)reloc.offset, to_str((low::R)reloc.type),
             (unsigned)reloc.section, (unsigned)reloc.addend);

    if ((low::R)reloc.type == low::R::R_RVL_STOP) {
      sizes.push_back(data_begin - start);
      return;
    }
  }

  throw "Failure";
}

void main() {
  auto buf = read_file("C:\\Users\\rii\\Downloads\\StaticR.rel");
  low::RelHeader rel_header;
  memcpy(&rel_header, buf.data(), sizeof(rel_header));
  low::flip(rel_header);

  std::vector<low::Imp> imps(rel_header.impSize / sizeof(low::Imp));
  memcpy(imps.data(), buf.data() + rel_header.impOffset, rel_header.impSize);

  for (auto& x : imps)
    low::flip(x);

  std::vector<u32> imp_sizes;

  printf("Dumping Relocation Tables..\n");
  for (int i = 0; i < imps.size(); ++i) {
    auto& imp = imps[i];
    printf("Table %i: %s\n---\n", i,
           imps[i].module_id == 0 ? "main.dol" : "StaticR.rel");

    dump_relocs((u8*)buf.data() + imp.offset, (u8*)buf.data() + buf.size(),
                imp.module_id == 0, imp_sizes);
  }

  auto* rel_relocs = fopen("rel_relocs.cache", "wb");
  auto* dol_relocs = fopen("dol_relocs.cache", "wb");

  fwrite(buf.data() + imps[0].offset, 1, imp_sizes[0], rel_relocs);
  fwrite(buf.data() + imps[1].offset, 1, imp_sizes[1], dol_relocs);

  fclose(rel_relocs);
  fclose(dol_relocs);

  auto REL = Lift(buf);
  auto REL_BIN = Lower(REL);
  auto* rel_dot_bin = fopen("new_rel.rel", "wb");
  fwrite(REL_BIN.data(), 1, REL_BIN.size(), rel_dot_bin);
  fclose(rel_dot_bin);

  low::RelHeader rebuilt;
  memcpy(&rebuilt, REL_BIN.data(), sizeof(rebuilt));
  low::flip(rebuilt);
}