CREATE TABLE agents(
          agent_id TEXT PRIMARY KEY, round TEXT, angle TEXT, model TEXT,
          status TEXT, best_score REAL, beat_base INTEGER,
          summary TEXT, key_finding TEXT)
CREATE TABLE trials(
          trial_id INTEGER PRIMARY KEY AUTOINCREMENT,
          agent_id TEXT, label TEXT, category TEXT,
          edit_from TEXT, edit_to TEXT,
          score REAL, base REAL, delta REAL,
          registers TEXT, instr_count INTEGER, beat INTEGER, notes TEXT)
CREATE TABLE sqlite_sequence(name,seq)
CREATE TABLE regalloc(
          id INTEGER PRIMARY KEY AUTOINCREMENT,
          build_id TEXT, source TEXT, name TEXT, vreg INTEGER,
          degree INTEGER, reg TEXT, flags TEXT)
CREATE TABLE findings(
          finding_id INTEGER PRIMARY KEY AUTOINCREMENT,
          agent_id TEXT, kind TEXT, statement TEXT, evidence TEXT)
CREATE TABLE rules(
          rule_id TEXT PRIMARY KEY, statement TEXT, evidence TEXT, consequence TEXT)
CREATE VIRTUAL TABLE fts_trials USING fts5(label, category, edit_from, edit_to, notes, content='trials', content_rowid='trial_id')
CREATE TABLE 'fts_trials_data'(id INTEGER PRIMARY KEY, block BLOB)
CREATE TABLE 'fts_trials_idx'(segid, term, pgno, PRIMARY KEY(segid, term)) WITHOUT ROWID
CREATE TABLE 'fts_trials_docsize'(id INTEGER PRIMARY KEY, sz BLOB)
CREATE TABLE 'fts_trials_config'(k PRIMARY KEY, v) WITHOUT ROWID
CREATE VIRTUAL TABLE fts_findings USING fts5(statement, evidence, kind, content='findings', content_rowid='finding_id')
CREATE TABLE 'fts_findings_data'(id INTEGER PRIMARY KEY, block BLOB)
CREATE TABLE 'fts_findings_idx'(segid, term, pgno, PRIMARY KEY(segid, term)) WITHOUT ROWID
CREATE TABLE 'fts_findings_docsize'(id INTEGER PRIMARY KEY, sz BLOB)
CREATE TABLE 'fts_findings_config'(k PRIMARY KEY, v) WITHOUT ROWID
CREATE VIRTUAL TABLE fts_agents USING fts5(angle, summary, key_finding, content='agents')
CREATE TABLE 'fts_agents_data'(id INTEGER PRIMARY KEY, block BLOB)
CREATE TABLE 'fts_agents_idx'(segid, term, pgno, PRIMARY KEY(segid, term)) WITHOUT ROWID
CREATE TABLE 'fts_agents_docsize'(id INTEGER PRIMARY KEY, sz BLOB)
CREATE TABLE 'fts_agents_config'(k PRIMARY KEY, v) WITHOUT ROWID
