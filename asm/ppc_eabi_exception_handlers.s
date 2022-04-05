.include "macros.inc"

.section .init, "ax" # { 80004000..80005f34 (init) }

# Symbol: interrupt_system_reset
# PAL: 0x80004100..0x80004200
.global interrupt_system_reset
interrupt_system_reset:
b unk_8001c660
.balign 0x100, 0

# Symbol: interrupt_machine_check
# PAL: 0x80004200..0x80004300
.global interrupt_machine_check
interrupt_machine_check:
mtspr 0x111, r2
mfspr r2, 0x1a
icbi 0, r2
mfdar r2
dcbi 0, r2
mfspr r2, 0x111
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x200
rfi
.balign 0x100, 0

# Symbol: interrupt_data_storage
# PAL: 0x80004300..0x80004400
.global interrupt_data_storage
interrupt_data_storage:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x300
rfi
.balign 0x100, 0

# Symbol: interrupt_instruction_storage
# PAL: 0x80004400..0x80004500
.global interrupt_instruction_storage
interrupt_instruction_storage:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x400
rfi
.balign 0x100, 0

# Symbol: interrupt_external_interrupt
# PAL: 0x80004500..0x80004600
.global interrupt_external_interrupt
interrupt_external_interrupt:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x500
rfi
.balign 0x100, 0

# Symbol: interrupt_alignment
# PAL: 0x80004600..0x80004700
.global interrupt_alignment
interrupt_alignment:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x600
rfi
.balign 0x100, 0

# Symbol: interrupt_program
# PAL: 0x80004700..0x80004800
.global interrupt_program
interrupt_program:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x700
rfi
.balign 0x100, 0

# Symbol: interrupt_floating_point_unavailable
# PAL: 0x80004800..0x80004900
.global interrupt_floating_point_unavailable
interrupt_floating_point_unavailable:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x800
rfi
.balign 0x100, 0

# Symbol: interrupt_decrementer
# PAL: 0x80004900..0x80004a00
.global interrupt_decrementer
interrupt_decrementer:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x900
rfi
.balign 0x100, 0

# Symbol: interrupt_reserved_4a00
# PAL: 0x80004a00..0x80004b00
.4byte 0
.balign 0x100, 0

# Symbol: interrupt_reserved_4b00
# PAL: 0x80004b00..0x80004c00
.4byte 0
.balign 0x100, 0

# Symbol: interrupt_system_call
# PAL: 0x80004c00..0x80004d00
.global interrupt_system_call
interrupt_system_call:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0xc00
rfi
.balign 0x100, 0

# Symbol: interrupt_trace
# PAL: 0x80004d00..0x80004e00
.global interrupt_trace
interrupt_trace:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0xd00
rfi
.balign 0x100, 0

# Symbol: interrupt_floating_point_assist
# PAL: 0x80004e00..0x80004f00
.global interrupt_floating_point_assist
interrupt_floating_point_assist:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0xe00
rfi
.balign 0x100, 0

# Symbol: interrupt_unknown_4f00
# PAL: 0x80004f00..0x80005000
.global interrupt_unknown_4f00
interrupt_unknown_4f00:
b lbl_80004f54
.skip 0x1c
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0xf20
rfi
lbl_80004f54:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0xf00
rfi
.balign 0x100, 0

# Symbol: interrupt_software_emulation
# PAL: 0x80005000..0x80005100
.global interrupt_software_emulation
interrupt_software_emulation:
mtspr 0x111, r2
mfcr r2
mtspr 0x112, r2
mfmsr r2
andis. r2, r2, 2
beq lbl_80005030
mfmsr r2
xoris r2, r2, 2
sync
mtmsr r2
sync
mtspr 0x111, r2
lbl_80005030:
mfspr r2, 0x112
mtcrf 0xff, r2
mfspr r2, 0x111
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1000
rfi
.balign 0x100, 0

# Symbol: interrupt_instruction_tlb_miss
# PAL: 0x80005100..0x80005200
.global interrupt_instruction_tlb_miss
interrupt_instruction_tlb_miss:
mtspr 0x111, r2
mfcr r2
mtspr 0x112, r2
mfmsr r2
andis. r2, r2, 2
beq lbl_80005130
mfmsr r2
xoris r2, r2, 2
sync
mtmsr r2
sync
mtspr 0x111, r2
lbl_80005130:
mfspr r2, 0x112
mtcrf 0xff, r2
mfspr r2, 0x111
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1100
rfi
.balign 0x100, 0

# Symbol: interrupt_data_tlb_miss
# PAL: 0x80005200..0x80005300
.global interrupt_data_tlb_miss
interrupt_data_tlb_miss:
mtspr 0x111, r2
mfcr r2
mtspr 0x112, r2
mfmsr r2
andis. r2, r2, 2
beq lbl_80005230
mfmsr r2
xoris r2, r2, 2
sync
mtmsr r2
sync
mtspr 0x111, r2
lbl_80005230:
mfspr r2, 0x112
mtcrf 0xff, r2
mfspr r2, 0x111
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1200
rfi
.balign 0x100, 0

# Symbol: interrupt_instruction_tlb_error
# PAL: 0x80005300..0x80005400
.global interrupt_instruction_tlb_error
interrupt_instruction_tlb_error:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1300
rfi
.balign 0x100, 0

# Symbol: interrupt_data_tlb_error
# PAL: 0x80005400..0x80005500
.global interrupt_data_tlb_error
interrupt_data_tlb_error:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1400
rfi
.balign 0x100, 0

# Symbol: interrupt_reserved_5500
# PAL: 0x80005500..0x80005600
.4byte 0
.balign 0x100, 0

# Symbol: interrupt_reserved_5600
# PAL: 0x80005600..0x80005700
.global interrupt_reserved_5600
interrupt_reserved_5600:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1600
rfi
.balign 0x100, 0

# Symbol: interrupt_reserved_5700
# PAL: 0x80005700..0x80005800
.global interrupt_reserved_5700
interrupt_reserved_5700:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1700
rfi
.balign 0x100, 0

# Symbol: interrupt_reserved_5800
# PAL: 0x80005800..0x80005900
.4byte 0
.balign 0x100, 0

# Symbol: interrupt_reserved_5900
# PAL: 0x80005900..0x80005a00
.4byte 0
.balign 0x100, 0

# Symbol: interrupt_reserved_5a00
# PAL: 0x80005a00..0x80005b00
.4byte 0
.balign 0x100, 0

# Symbol: interrupt_reserved_5b00
# PAL: 0x80005b00..0x80005c00
.4byte 0
.balign 0x100, 0

# Symbol: interrupt_data_breakpoint
# PAL: 0x80005c00..0x80005d00
.global interrupt_data_breakpoint
interrupt_data_breakpoint:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1c00
rfi
.balign 0x100, 0

# Symbol: interrupt_instruction_breakpoint
# PAL: 0x80005d00..0x80005e00
.global interrupt_instruction_breakpoint
interrupt_instruction_breakpoint:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1d00
rfi
.balign 0x100, 0

# Symbol: interrupt_peripheral_breakpoint
# PAL: 0x80005e00..0x80005f00
.global interrupt_peripheral_breakpoint
interrupt_peripheral_breakpoint:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1e00
rfi
.balign 0x100, 0

# Symbol: interrupt_non_maskable_development_port
# PAL: 0x80005f00..0x80005f34
.global interrupt_non_maskable_development_port
interrupt_non_maskable_development_port:
mtspr 0x111, r2
mtspr 0x112, r3
mtspr 0x113, r4
mfspr r2, 0x1a
mfspr r4, 0x1b
mfmsr r3
ori r3, r3, 0x30
mtspr 0x1b, r3
lis r3, 0x8001
ori r3, r3, 0xfdec
mtspr 0x1a, r3
li r3, 0x1f00
rfi
