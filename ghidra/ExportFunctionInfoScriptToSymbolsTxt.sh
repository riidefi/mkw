#!/bin/sh
# Run this to convert a dump from ExportFunctionInfoScript.java to a symbols.txt dump.
exec jq -r '.[] | "0x\(.entry) \(.name)"'
