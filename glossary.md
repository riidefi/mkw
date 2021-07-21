# Glossary

### Section

An area of program address space with a specific kind of content.

| Name         | Purpose                                 | DOL | REL |
| ------------ | --------------------------------------- | --- | --- |
| `init`       | Program entrypoint                      | Yes | No  |
| `extab`      | Exception Table                         | Yes | No  |
| `extabindex` | Exception Table                         | Yes | No  |
| `text`       | Program code                            | Yes | Yes |
| `ctors`      | Pointers to code to execute on startup  | Yes | Yes |
| `dtors`      | Pointers to code to execute on shutdown | Yes | Yes |
| `rodata`     | Read-only data                          | Yes | Yes |
| `data`       | Mutable data                            | Yes | Yes |
| `bss`        | Zero-initialized data                   | Yes | Yes |
| `sdata`      | Small mutable data (≤ 8 bytes)          | Yes | No  |
| `sbss`       | Small zero-init. data (≤ 8 bytes)       | Yes | No  |
| `sdata2`     | Small read-only data (≤ 8 bytes)        | Yes | No  |
| `sbss2`      | Small read-only zero bytes              | Yes | No  |

### Segment

A part of the binary executable. Gets unpacked into one or more sections.

The BSS segment is special.
Since it just contains zeros, only the address and length is saved.

| Name         | Sections               | DOL    |
| ------------ | ---------------------- | ------ |
| `init`       | `init`                 | `0x00` |
| `text`       | `text`                 | `0x01` |
| `extab`      | `extab`                | `0x07` |
| `extabindex` | `extabindex`           | `0x08` |
| `ctors`      | `ctors`                | `0x09` |
| `dtors`      | `dtors`                | `0x0a` |
| `rodata`     | `rodata`               | `0x0b` |
| `data`       | `data`                 | `0x0c` |
| `sdata`      | `sdata`                | `0x0d` |
| `sdata2`     | `sdata2`               | `0x0e` |
| `bss`        | `bss`, `sdata`, `sbss` | `bss`  |

### Small data area (SDA)

A special area in memory mainly used to load/store global 4 byte values (pointers, floating point literals) with a single instruction.
Register `r13` points into the middle of the SDA.
It is accessed using relative address. The offset is signed:
- Load: `lwz <register> <offset>(r13)`
- Store: `stw <register> <offset>(r13)`
