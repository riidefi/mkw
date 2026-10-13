import importlib.util, sqlite3
for m in ("duckdb","pandas","polars","pyarrow"):
    print(m, "OK" if importlib.util.find_spec(m) else "MISSING")
c=sqlite3.connect(r"C:\Users\nnnn\Documents\mkwii\subagent_data\subagents.db")
print("indexes:", [r[0] for r in c.execute("SELECT name FROM sqlite_master WHERE type='index'")])
