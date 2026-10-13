import sqlite3, json
c=sqlite3.connect("subagents.db")
print("TABLES:", [r[0] for r in c.execute("SELECT name FROM sqlite_master WHERE type IN ('table','view')")])
print("\nBEAT-BASE TRIALS:")
for r in c.execute("SELECT agent_id,label,score,base,delta,registers FROM trials WHERE beat=1"):
    print("  ", r)
print("\nMOST-REGRESSING TRIALS:")
for r in c.execute("SELECT label,score,delta FROM trials ORDER BY delta ASC LIMIT 6"):
    print("  ", r)
print("\nFTS: trials matching 'coalesc OR split':")
for r in c.execute("SELECT t.label,t.score FROM fts_trials f JOIN trials t ON t.trial_id=f.rowid WHERE fts_trials MATCH 'coalesc OR split'"):
    print("  ", r)
print("\nREGALLOC base93:")
for r in c.execute("SELECT name,vreg,degree,reg FROM regalloc WHERE build_id='base93' ORDER BY vreg DESC"):
    print("  ", r)
print("\nAGENTS by round:")
for r in c.execute("SELECT round,count(*) FROM agents GROUP BY round"):
    print("  ", r)
