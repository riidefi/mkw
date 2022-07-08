"""
Creates the expected folder for diff.py
"""

from shutil import copytree, rmtree

# Remove it if already existing
try:
    rmtree("expected")
except FileNotFoundError:
    pass

# Copy in out and artifacts directories
copytree("out", "expected/out")
