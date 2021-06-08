"""
Utility to dump StaticR.rel to its individual pieces
and/or reconstruct it back to its original form.
"""

import argparse

from mkw.rel import Rel, dump_staticr, reconstruct_staticr

parser = argparse.ArgumentParser(description="Repack StaticR.Rel")
parser.add_argument(
    "--dump",
    action="store_true",
    default=False,
    help="Dump relocs and sections from StaticR.rel",
)
parser.add_argument(
    "--reconstruct",
    action="store_true",
    default=False,
    help="Regenerate StaticR.rel from dump",
)
parser.add_argument("--rel", type=str, required=True, help="Path to StaticR.rel")
parser.add_argument("--dir", type=str, required=True, help="Path to dump dir")
args = parser.parse_args()


if not args.dump and not args.dump:
    parser.print_usage()
    print("rel_repack.py: error: --dump and/or --reconstruct required")

if args.dump:
    print(f"Dumping {args.rel} to {args.dir}")
    with open(args.rel, "rb") as file:
        rel = Rel(file)
        dump_staticr(rel, args.dir)

if args.reconstruct:
    print(f"Reconstructing {args.rel} from {args.dir}")
    rel = reconstruct_staticr(args.dir)
    with open(args.rel, "wb") as file:
        rel.reconstruct(file)
