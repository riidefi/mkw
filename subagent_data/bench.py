import sqlite3, time, os
db="subagents.db"
print("size bytes:", os.path.getsize(db))
c=sqlite3.connect(db)
print("indexes:", [r[0] for r in c.execute("SELECT name FROM sqlite_master WHERE type='index'")])
print("rows:", {t:c.execute("SELECT count(*) FROM "+t).fetchone()[0] for t in ('agents','trials','regalloc','findings','harvest_methods','processes','comparisons')})
def bench(label, fn, n=200):
    t=time.perf_counter()
    for _ in range(n): fn()
    print("  %-42s %6.3f ms/iter" % (label, (time.perf_counter()-t)*1000/n))
# representative workloads
q_scan=lambda: c.execute("SELECT category,count(*),max(delta) FROM trials GROUP BY category").fetchall()
q_join=lambda: c.execute("SELECT t.label,a.round,t.score FROM trials t JOIN agents a ON a.agent_id=t.agent_id WHERE t.beat=1").fetchall()
q_reg=lambda: c.execute("SELECT label FROM trials WHERE registers LIKE 'r30%'").fetchall()
q_fts=lambda: c.execute("SELECT t.label FROM fts_trials f JOIN trials t ON t.trial_id=f.rowid WHERE fts_trials MATCH 'coalesc OR remateriali*'").fetchall()
q_regjoin=lambda: c.execute("SELECT t.label,g.reg FROM trials t JOIN regalloc g ON g.build_id='base93' AND g.name='pe'").fetchall()
for l,f in [("group-by category scan",q_scan),("join trials x agents (beat=1)",q_join),("LIKE registers 'r30%'",q_reg),("FTS match + join",q_fts),("join trials x regalloc",q_regjoin)]:
    bench(l,f)
c.close()
