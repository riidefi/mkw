import sqlite3
c=sqlite3.connect("subagents.db")
print("E agents:", [r[0] for r in c.execute("SELECT agent_id FROM agents WHERE round='E'")])
print("E findings:", c.execute("SELECT count(*) FROM findings WHERE agent_id IN ('E1','E3','E4','E5')").fetchone()[0])
print("E trials:", [r[0] for r in c.execute("SELECT label FROM trials WHERE agent_id LIKE 'E%'")])
print("proofs:", [r[0] for r in c.execute("SELECT kind FROM proofs")])
