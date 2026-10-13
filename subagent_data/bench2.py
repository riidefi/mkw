import sqlite3, time, os
c=sqlite3.connect("subagents.db")
print("indexes:", len([r for r in c.execute("SELECT name FROM sqlite_master WHERE type='index'")]), "size", os.path.getsize("subagents.db"))
print("trial_colour rows:", c.execute("SELECT count(*) FROM trial_colour").fetchone()[0])
print("pe=r30 in trial_colour:", c.execute("SELECT count(*) FROM trial_colour WHERE pe='r30'").fetchone()[0])
def bench(label, fn, n=500):
    t=time.perf_counter()
    for _ in range(n): fn()
    print("  %-44s %6.3f ms/iter" % (label,(time.perf_counter()-t)*1000/n))
bench("join trials x agents (indexed)", lambda: c.execute("SELECT t.label,a.round FROM trials t JOIN agents a ON a.agent_id=t.agent_id WHERE t.beat=1").fetchall())
bench("trials by category (indexed)", lambda: c.execute("SELECT count(*) FROM trials WHERE category='lifetime-split'").fetchall())
bench("colour pe='r30' (normalized+indexed)", lambda: c.execute("SELECT count(*) FROM trial_colour WHERE pe='r30'").fetchall())
bench("regalloc by build+name (indexed)", lambda: c.execute("SELECT reg FROM regalloc WHERE build_id='base93' AND name='pe'").fetchall())
