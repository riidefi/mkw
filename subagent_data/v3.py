import sqlite3
c=sqlite3.connect("subagents.db")
for r in c.execute("SELECT agent_id,kind,substr(statement,1,70) FROM findings WHERE agent_id IN ('D2','D3','D5')"):
    print("  ",r)
