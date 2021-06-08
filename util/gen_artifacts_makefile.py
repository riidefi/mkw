import argparse

import jinja2

parser = argparse.ArgumentParser()
parser.add_argument("--artifacts_dir", type=str, required=True, help="Path to artifacts dir")
parser.add_argument("--pack_dir", type=str, required=True, help="Path to pack dir")
args = parser.parse_args()


