import sqlite3
c=sqlite3.connect("subagents.db")
for r in c.execute("SELECT category,count(*) FROM processes GROUP BY category ORDER BY 2 DESC"): print("  ",r)
print("comparisons:", c.execute("SELECT count(*) FROM comparisons").fetchone()[0])
print("by relationship:", [r for r in c.execute("SELECT relationship,count(*) FROM comparisons GROUP BY 1")])
