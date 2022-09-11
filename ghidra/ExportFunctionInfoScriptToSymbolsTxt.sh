#!/bin/sh
# Run this to convert a dump from ExportFunctionInfoScript.java to a symbols.yml dump.
exec jq -r '.[] | "0x\(.entry) \(.name)"'
