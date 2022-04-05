.include "macros.inc"

.section .init, "ax" # { 800063a0..80006460 (init) }
.global "trk_section_table"
"trk_section_table":
.4byte 0x80004000
.4byte 0x80004000
.4byte 0x00002444

.4byte 0x80006460
.4byte 0x80006460
.4byte 0x000005C0

.4byte 0x80006A20
.4byte 0x80006A20
.4byte 0x00000890

.4byte 0x800072C0
.4byte 0x800072C0
.4byte 0x0023DB14

.4byte 0x80244DE0
.4byte 0x80244DE0
.4byte 0x000000B0

.4byte 0x80244EA0
.4byte 0x80244EA0
.4byte 0x0000000C

.4byte 0x80244EC0
.4byte 0x80244EC0
.4byte 0x000136AC

.4byte 0x80258580
.4byte 0x80258580
.4byte 0x0004BABC

.4byte 0x80384C00
.4byte 0x80384C00
.4byte 0x000013C0

.4byte 0x80386FA0
.4byte 0x80386FA0
.4byte 0x0000219C

.4byte 0x00000000
.4byte 0x00000000
.4byte 0x00000000

.global "trk_bss_entry"
"trk_bss_entry":
.4byte 0x802A4080
.4byte 0x000E0B74

.4byte 0x80385FC0
.4byte 0x00000FD0

.4byte 0x80389140
.4byte 0x0000003C

.4byte 0x00000000
.4byte 0x00000000

.4byte 0x00000000
.4byte 0x00000000

.4byte 0x00000000
.4byte 0x00000000

.4byte 0x00000000
.4byte 0x00000000

.4byte 0x00000000
