import sqlite3
c=sqlite3.connect("subagents.db")
print("harvest categories:", [r for r in c.execute("SELECT category,count(*) FROM harvest_methods GROUP BY category ORDER BY 2 DESC")])
print("tools:", [r[0] for r in c.execute("SELECT name FROM tools_built")])
print("proofs:", [r[0] for r in c.execute("SELECT kind FROM proofs")])
