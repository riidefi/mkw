
.include "macros.inc"

.section .init, "ax" # 0x80004000 - 0x80006460
/* 80004000  4D 65 74 72 */	.4byte 0x4D657472  /* unknown instruction */
/* 80004004  6F 77 65 72 */	xoris r23, r27, 0x6572
/* 80004008  6B 73 20 54 */	xori r19, r27, 0x2054
/* 8000400C  61 72 67 65 */	ori r18, r11, 0x6765
/* 80004010  74 20 52 65 */	andis. r0, r1, 0x5265
/* 80004014  73 69 64 65 */	andi. r9, r27, 0x6465
/* 80004018  6E 74 20 4B */	xoris r20, r19, 0x204b
/* 8000401C  65 72 6E 65 */	oris r18, r11, 0x6e65
/* 80004020  6C 20 66 6F */	xoris r0, r1, 0x666f
/* 80004024  72 20 50 6F */	andi. r0, r17, 0x506f
/* 80004028  77 65 72 50 */	andis. r5, r27, 0x7250
/* 8000402C  43 00 00 00 */	.4byte 0x43000000  /* unknown instruction */
/* 80004030  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004034  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004038  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000403C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004040  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004044  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004048  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000404C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004050  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004054  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004058  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000405C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004060  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004064  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004068  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000406C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004070  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004074  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004078  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000407C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004080  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004084  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004088  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000408C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004090  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004094  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004098  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000409C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800040FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004100  48 01 85 60 */	b 0x18560
/* 80004104  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004108  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000410C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004110  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004114  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004118  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000411C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004120  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004124  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004128  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000412C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004130  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004134  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004138  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000413C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004140  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004144  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004148  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000414C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004150  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004154  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004158  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000415C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004160  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004164  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004168  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000416C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004170  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004174  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004178  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000417C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004180  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004184  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004188  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000418C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004190  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004194  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004198  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000419C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800041FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004200  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004204  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004208  7C 00 17 AC */	icbi 0, r2
/* 8000420C  7C 53 02 A6 */	mfdar r2
/* 80004210  7C 00 13 AC */	dcbi 0, r2
/* 80004214  7C 51 42 A6 */	mfspr r2, 0x111
/* 80004218  7C 51 43 A6 */	mtspr 0x111, r2
/* 8000421C  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004220  7C 93 43 A6 */	mtspr 0x113, r4
/* 80004224  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004228  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 8000422C  7C 60 00 A6 */	mfmsr r3
/* 80004230  60 63 00 30 */	ori r3, r3, 0x30
/* 80004234  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004238  3C 60 80 01 */	lis r3, 0x8001
/* 8000423C  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004240  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80004244  38 60 02 00 */	li r3, 0x200
/* 80004248  4C 00 00 64 */	rfi 
/* 8000424C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004250  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004254  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004258  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000425C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004260  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004264  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004268  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000426C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004270  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004274  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004278  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000427C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004280  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004284  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004288  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000428C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004290  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004294  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004298  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000429C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800042FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004300  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004304  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004308  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000430C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004310  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004314  7C 60 00 A6 */	mfmsr r3
/* 80004318  60 63 00 30 */	ori r3, r3, 0x30
/* 8000431C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004320  3C 60 80 01 */	lis r3, 0x8001
/* 80004324  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004328  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000432C  38 60 03 00 */	li r3, 0x300
/* 80004330  4C 00 00 64 */	rfi 
/* 80004334  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004338  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000433C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004340  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004344  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004348  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000434C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004350  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004354  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004358  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000435C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004360  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004364  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004368  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000436C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004370  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004374  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004378  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000437C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004380  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004384  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004388  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000438C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004390  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004394  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004398  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000439C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800043FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004400  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004404  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004408  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000440C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004410  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004414  7C 60 00 A6 */	mfmsr r3
/* 80004418  60 63 00 30 */	ori r3, r3, 0x30
/* 8000441C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004420  3C 60 80 01 */	lis r3, 0x8001
/* 80004424  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004428  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000442C  38 60 04 00 */	li r3, 0x400
/* 80004430  4C 00 00 64 */	rfi 
/* 80004434  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004438  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000443C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004440  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004444  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004448  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000444C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004450  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004454  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004458  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000445C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004460  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004464  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004468  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000446C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004470  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004474  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004478  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000447C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004480  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004484  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004488  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000448C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004490  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004494  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004498  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000449C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800044FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004500  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004504  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004508  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000450C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004510  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004514  7C 60 00 A6 */	mfmsr r3
/* 80004518  60 63 00 30 */	ori r3, r3, 0x30
/* 8000451C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004520  3C 60 80 01 */	lis r3, 0x8001
/* 80004524  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004528  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000452C  38 60 05 00 */	li r3, 0x500
/* 80004530  4C 00 00 64 */	rfi 
/* 80004534  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004538  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000453C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004540  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004544  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004548  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000454C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004550  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004554  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004558  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000455C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004560  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004564  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004568  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000456C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004570  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004574  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004578  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000457C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004580  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004584  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004588  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000458C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004590  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004594  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004598  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000459C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800045FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004600  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004604  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004608  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000460C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004610  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004614  7C 60 00 A6 */	mfmsr r3
/* 80004618  60 63 00 30 */	ori r3, r3, 0x30
/* 8000461C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004620  3C 60 80 01 */	lis r3, 0x8001
/* 80004624  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004628  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000462C  38 60 06 00 */	li r3, 0x600
/* 80004630  4C 00 00 64 */	rfi 
/* 80004634  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004638  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000463C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004640  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004644  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004648  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000464C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004650  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004654  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004658  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000465C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004660  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004664  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004668  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000466C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004670  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004674  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004678  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000467C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004680  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004684  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004688  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000468C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004690  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004694  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004698  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000469C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800046FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004700  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004704  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004708  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000470C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004710  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004714  7C 60 00 A6 */	mfmsr r3
/* 80004718  60 63 00 30 */	ori r3, r3, 0x30
/* 8000471C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004720  3C 60 80 01 */	lis r3, 0x8001
/* 80004724  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004728  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000472C  38 60 07 00 */	li r3, 0x700
/* 80004730  4C 00 00 64 */	rfi 
/* 80004734  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004738  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000473C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004740  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004744  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004748  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000474C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004750  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004754  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004758  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000475C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004760  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004764  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004768  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000476C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004770  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004774  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004778  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000477C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004780  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004784  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004788  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000478C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004790  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004794  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004798  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000479C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800047FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004800  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004804  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004808  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000480C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004810  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004814  7C 60 00 A6 */	mfmsr r3
/* 80004818  60 63 00 30 */	ori r3, r3, 0x30
/* 8000481C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004820  3C 60 80 01 */	lis r3, 0x8001
/* 80004824  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004828  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000482C  38 60 08 00 */	li r3, 0x800
/* 80004830  4C 00 00 64 */	rfi 
/* 80004834  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004838  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000483C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004840  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004844  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004848  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000484C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004850  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004854  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004858  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000485C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004860  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004864  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004868  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000486C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004870  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004874  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004878  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000487C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004880  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004884  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004888  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000488C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004890  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004894  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004898  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000489C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800048FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004900  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004904  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004908  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000490C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004910  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004914  7C 60 00 A6 */	mfmsr r3
/* 80004918  60 63 00 30 */	ori r3, r3, 0x30
/* 8000491C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004920  3C 60 80 01 */	lis r3, 0x8001
/* 80004924  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004928  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000492C  38 60 09 00 */	li r3, 0x900
/* 80004930  4C 00 00 64 */	rfi 
/* 80004934  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004938  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000493C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004940  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004944  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004948  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000494C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004950  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004954  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004958  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000495C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004960  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004964  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004968  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000496C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004970  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004974  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004978  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000497C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004980  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004984  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004988  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000498C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004990  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004994  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004998  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000499C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800049FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A00  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A04  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A08  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A0C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A10  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A14  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A20  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A24  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A28  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A2C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A30  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004A9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004ABC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004ACC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AD0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AD4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004ADC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004AFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B00  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B04  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B08  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B0C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B10  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B14  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B20  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B24  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B28  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B2C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B30  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004B9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BCC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BD0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BD4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004BFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C00  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004C04  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004C08  7C 93 43 A6 */	mtspr 0x113, r4
/* 80004C0C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004C10  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004C14  7C 60 00 A6 */	mfmsr r3
/* 80004C18  60 63 00 30 */	ori r3, r3, 0x30
/* 80004C1C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004C20  3C 60 80 01 */	lis r3, 0x8001
/* 80004C24  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004C28  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80004C2C  38 60 0C 00 */	li r3, 0xc00
/* 80004C30  4C 00 00 64 */	rfi 
/* 80004C34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004C9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CCC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CD0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CD4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004CFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D00  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004D04  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004D08  7C 93 43 A6 */	mtspr 0x113, r4
/* 80004D0C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004D10  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004D14  7C 60 00 A6 */	mfmsr r3
/* 80004D18  60 63 00 30 */	ori r3, r3, 0x30
/* 80004D1C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004D20  3C 60 80 01 */	lis r3, 0x8001
/* 80004D24  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004D28  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80004D2C  38 60 0D 00 */	li r3, 0xd00
/* 80004D30  4C 00 00 64 */	rfi 
/* 80004D34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004D9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DCC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DD0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DD4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004DFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E00  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004E04  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004E08  7C 93 43 A6 */	mtspr 0x113, r4
/* 80004E0C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004E10  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004E14  7C 60 00 A6 */	mfmsr r3
/* 80004E18  60 63 00 30 */	ori r3, r3, 0x30
/* 80004E1C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004E20  3C 60 80 01 */	lis r3, 0x8001
/* 80004E24  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004E28  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80004E2C  38 60 0E 00 */	li r3, 0xe00
/* 80004E30  4C 00 00 64 */	rfi 
/* 80004E34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004E9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004ECC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004ED0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004ED4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004ED8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004EFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F00  48 00 00 54 */	b 0x54
/* 80004F04  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F08  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F0C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F10  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F14  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F20  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004F24  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004F28  7C 93 43 A6 */	mtspr 0x113, r4
/* 80004F2C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004F30  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004F34  7C 60 00 A6 */	mfmsr r3
/* 80004F38  60 63 00 30 */	ori r3, r3, 0x30
/* 80004F3C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004F40  3C 60 80 01 */	lis r3, 0x8001
/* 80004F44  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004F48  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80004F4C  38 60 0F 20 */	li r3, 0xf20
/* 80004F50  4C 00 00 64 */	rfi 
/* 80004F54  7C 51 43 A6 */	mtspr 0x111, r2
/* 80004F58  7C 72 43 A6 */	mtspr 0x112, r3
/* 80004F5C  7C 93 43 A6 */	mtspr 0x113, r4
/* 80004F60  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80004F64  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80004F68  7C 60 00 A6 */	mfmsr r3
/* 80004F6C  60 63 00 30 */	ori r3, r3, 0x30
/* 80004F70  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80004F74  3C 60 80 01 */	lis r3, 0x8001
/* 80004F78  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80004F7C  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80004F80  38 60 0F 00 */	li r3, 0xf00
/* 80004F84  4C 00 00 64 */	rfi 
/* 80004F88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004F9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FCC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FD0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FD4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80004FFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005000  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005004  7C 40 00 26 */	mfcr r2
/* 80005008  7C 52 43 A6 */	mtspr 0x112, r2
/* 8000500C  7C 40 00 A6 */	mfmsr r2
/* 80005010  74 42 00 02 */	andis. r2, r2, 2
/* 80005014  41 82 00 1C */	beq 0x1c
/* 80005018  7C 40 00 A6 */	mfmsr r2
/* 8000501C  6C 42 00 02 */	xoris r2, r2, 2
/* 80005020  7C 00 04 AC */	sync 0
/* 80005024  7C 40 01 24 */	mtmsr r2
/* 80005028  7C 00 04 AC */	sync 0
/* 8000502C  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005030  7C 52 42 A6 */	mfspr r2, 0x112
/* 80005034  7C 4F F1 20 */	mtcrf 0xff, r2
/* 80005038  7C 51 42 A6 */	mfspr r2, 0x111
/* 8000503C  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005040  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005044  7C 93 43 A6 */	mtspr 0x113, r4
/* 80005048  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 8000504C  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005050  7C 60 00 A6 */	mfmsr r3
/* 80005054  60 63 00 30 */	ori r3, r3, 0x30
/* 80005058  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 8000505C  3C 60 80 01 */	lis r3, 0x8001
/* 80005060  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005064  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80005068  38 60 10 00 */	li r3, 0x1000
/* 8000506C  4C 00 00 64 */	rfi 
/* 80005070  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005074  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005078  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000507C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005080  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005084  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005088  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000508C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005090  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005094  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005098  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000509C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800050FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005100  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005104  7C 40 00 26 */	mfcr r2
/* 80005108  7C 52 43 A6 */	mtspr 0x112, r2
/* 8000510C  7C 40 00 A6 */	mfmsr r2
/* 80005110  74 42 00 02 */	andis. r2, r2, 2
/* 80005114  41 82 00 1C */	beq 0x1c
/* 80005118  7C 40 00 A6 */	mfmsr r2
/* 8000511C  6C 42 00 02 */	xoris r2, r2, 2
/* 80005120  7C 00 04 AC */	sync 0
/* 80005124  7C 40 01 24 */	mtmsr r2
/* 80005128  7C 00 04 AC */	sync 0
/* 8000512C  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005130  7C 52 42 A6 */	mfspr r2, 0x112
/* 80005134  7C 4F F1 20 */	mtcrf 0xff, r2
/* 80005138  7C 51 42 A6 */	mfspr r2, 0x111
/* 8000513C  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005140  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005144  7C 93 43 A6 */	mtspr 0x113, r4
/* 80005148  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 8000514C  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005150  7C 60 00 A6 */	mfmsr r3
/* 80005154  60 63 00 30 */	ori r3, r3, 0x30
/* 80005158  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 8000515C  3C 60 80 01 */	lis r3, 0x8001
/* 80005160  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005164  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80005168  38 60 11 00 */	li r3, 0x1100
/* 8000516C  4C 00 00 64 */	rfi 
/* 80005170  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005174  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005178  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000517C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005180  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005184  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005188  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000518C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005190  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005194  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005198  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000519C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800051FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005200  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005204  7C 40 00 26 */	mfcr r2
/* 80005208  7C 52 43 A6 */	mtspr 0x112, r2
/* 8000520C  7C 40 00 A6 */	mfmsr r2
/* 80005210  74 42 00 02 */	andis. r2, r2, 2
/* 80005214  41 82 00 1C */	beq 0x1c
/* 80005218  7C 40 00 A6 */	mfmsr r2
/* 8000521C  6C 42 00 02 */	xoris r2, r2, 2
/* 80005220  7C 00 04 AC */	sync 0
/* 80005224  7C 40 01 24 */	mtmsr r2
/* 80005228  7C 00 04 AC */	sync 0
/* 8000522C  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005230  7C 52 42 A6 */	mfspr r2, 0x112
/* 80005234  7C 4F F1 20 */	mtcrf 0xff, r2
/* 80005238  7C 51 42 A6 */	mfspr r2, 0x111
/* 8000523C  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005240  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005244  7C 93 43 A6 */	mtspr 0x113, r4
/* 80005248  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 8000524C  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005250  7C 60 00 A6 */	mfmsr r3
/* 80005254  60 63 00 30 */	ori r3, r3, 0x30
/* 80005258  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 8000525C  3C 60 80 01 */	lis r3, 0x8001
/* 80005260  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005264  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80005268  38 60 12 00 */	li r3, 0x1200
/* 8000526C  4C 00 00 64 */	rfi 
/* 80005270  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005274  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005278  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000527C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005280  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005284  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005288  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000528C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005290  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005294  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005298  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000529C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800052FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005300  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005304  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005308  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000530C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80005310  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005314  7C 60 00 A6 */	mfmsr r3
/* 80005318  60 63 00 30 */	ori r3, r3, 0x30
/* 8000531C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80005320  3C 60 80 01 */	lis r3, 0x8001
/* 80005324  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005328  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000532C  38 60 13 00 */	li r3, 0x1300
/* 80005330  4C 00 00 64 */	rfi 
/* 80005334  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005338  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000533C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005340  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005344  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005348  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000534C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005350  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005354  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005358  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000535C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005360  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005364  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005368  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000536C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005370  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005374  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005378  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000537C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005380  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005384  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005388  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000538C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005390  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005394  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005398  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000539C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800053FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005400  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005404  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005408  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000540C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80005410  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005414  7C 60 00 A6 */	mfmsr r3
/* 80005418  60 63 00 30 */	ori r3, r3, 0x30
/* 8000541C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80005420  3C 60 80 01 */	lis r3, 0x8001
/* 80005424  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005428  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000542C  38 60 14 00 */	li r3, 0x1400
/* 80005430  4C 00 00 64 */	rfi 
/* 80005434  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005438  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000543C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005440  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005444  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005448  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000544C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005450  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005454  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005458  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000545C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005460  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005464  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005468  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000546C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005470  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005474  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005478  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000547C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005480  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005484  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005488  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000548C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005490  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005494  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005498  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000549C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005500  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005504  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005508  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000550C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005510  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005514  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005518  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000551C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005520  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005524  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005528  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000552C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005530  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005534  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005538  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000553C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005540  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005544  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005548  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000554C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005550  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005554  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005558  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000555C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005560  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005564  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005568  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000556C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005570  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005574  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005578  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000557C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005580  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005584  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005588  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000558C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005590  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005594  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005598  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000559C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005600  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005604  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005608  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000560C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80005610  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005614  7C 60 00 A6 */	mfmsr r3
/* 80005618  60 63 00 30 */	ori r3, r3, 0x30
/* 8000561C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80005620  3C 60 80 01 */	lis r3, 0x8001
/* 80005624  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005628  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000562C  38 60 16 00 */	li r3, 0x1600
/* 80005630  4C 00 00 64 */	rfi 
/* 80005634  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005638  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000563C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005640  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005644  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005648  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000564C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005650  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005654  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005658  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000565C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005660  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005664  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005668  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000566C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005670  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005674  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005678  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000567C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005680  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005684  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005688  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000568C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005690  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005694  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005698  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000569C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800056FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005700  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005704  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005708  7C 93 43 A6 */	mtspr 0x113, r4
/* 8000570C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80005710  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005714  7C 60 00 A6 */	mfmsr r3
/* 80005718  60 63 00 30 */	ori r3, r3, 0x30
/* 8000571C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80005720  3C 60 80 01 */	lis r3, 0x8001
/* 80005724  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005728  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 8000572C  38 60 17 00 */	li r3, 0x1700
/* 80005730  4C 00 00 64 */	rfi 
/* 80005734  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005738  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000573C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005740  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005744  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005748  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000574C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005750  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005754  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005758  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000575C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005760  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005764  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005768  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000576C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005770  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005774  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005778  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000577C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005780  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005784  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005788  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000578C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005790  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005794  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005798  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000579C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800057FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005800  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005804  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005808  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000580C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005810  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005814  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005818  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000581C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005820  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005824  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005828  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000582C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005830  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005834  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005838  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000583C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005840  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005844  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005848  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000584C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005850  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005854  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005858  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000585C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005860  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005864  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005868  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000586C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005870  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005874  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005878  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000587C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005880  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005884  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005888  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000588C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005890  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005894  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005898  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000589C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800058FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005900  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005904  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005908  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000590C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005910  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005914  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005918  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000591C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005920  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005924  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005928  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000592C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005930  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005934  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005938  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000593C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005940  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005944  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005948  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000594C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005950  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005954  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005958  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000595C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005960  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005964  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005968  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000596C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005970  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005974  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005978  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000597C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005980  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005984  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005988  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000598C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005990  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005994  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005998  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000599C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059C0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059E0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800059FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A00  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A04  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A08  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A0C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A10  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A14  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A20  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A24  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A28  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A2C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A30  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005A9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005ABC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005ACC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AD0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AD4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005ADC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005AFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B00  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B04  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B08  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B0C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B10  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B14  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B20  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B24  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B28  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B2C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B30  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005B9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BCC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BD0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BD4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005BFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C00  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005C04  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005C08  7C 93 43 A6 */	mtspr 0x113, r4
/* 80005C0C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80005C10  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005C14  7C 60 00 A6 */	mfmsr r3
/* 80005C18  60 63 00 30 */	ori r3, r3, 0x30
/* 80005C1C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80005C20  3C 60 80 01 */	lis r3, 0x8001
/* 80005C24  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005C28  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80005C2C  38 60 1C 00 */	li r3, 0x1c00
/* 80005C30  4C 00 00 64 */	rfi 
/* 80005C34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005C9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CCC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CD0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CD4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005CFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D00  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005D04  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005D08  7C 93 43 A6 */	mtspr 0x113, r4
/* 80005D0C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80005D10  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005D14  7C 60 00 A6 */	mfmsr r3
/* 80005D18  60 63 00 30 */	ori r3, r3, 0x30
/* 80005D1C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80005D20  3C 60 80 01 */	lis r3, 0x8001
/* 80005D24  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005D28  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80005D2C  38 60 1D 00 */	li r3, 0x1d00
/* 80005D30  4C 00 00 64 */	rfi 
/* 80005D34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005D9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DCC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DD0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DD4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005DFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E00  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005E04  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005E08  7C 93 43 A6 */	mtspr 0x113, r4
/* 80005E0C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80005E10  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005E14  7C 60 00 A6 */	mfmsr r3
/* 80005E18  60 63 00 30 */	ori r3, r3, 0x30
/* 80005E1C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80005E20  3C 60 80 01 */	lis r3, 0x8001
/* 80005E24  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005E28  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80005E2C  38 60 1E 00 */	li r3, 0x1e00
/* 80005E30  4C 00 00 64 */	rfi 
/* 80005E34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E40  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E60  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E80  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005E9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EA0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EB0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EC0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EC4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005ECC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005ED0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005ED4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005ED8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EE0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EE4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005EFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005F00  7C 51 43 A6 */	mtspr 0x111, r2
/* 80005F04  7C 72 43 A6 */	mtspr 0x112, r3
/* 80005F08  7C 93 43 A6 */	mtspr 0x113, r4
/* 80005F0C  7C 5A 02 A6 */	mfspr r2, 0x1a
/* 80005F10  7C 9B 02 A6 */	mfspr r4, 0x1b
/* 80005F14  7C 60 00 A6 */	mfmsr r3
/* 80005F18  60 63 00 30 */	ori r3, r3, 0x30
/* 80005F1C  7C 7B 03 A6 */	mtspr 0x1b, r3
/* 80005F20  3C 60 80 01 */	lis r3, 0x8001
/* 80005F24  60 63 FD EC */	ori r3, r3, 0xfdec
/* 80005F28  7C 7A 03 A6 */	mtspr 0x1a, r3
/* 80005F2C  38 60 1F 00 */	li r3, 0x1f00
/* 80005F30  4C 00 00 64 */	rfi 
/* 80005F34  7C 04 18 40 */	cmplw r4, r3
/* 80005F38  41 80 00 28 */	blt 0x28
/* 80005F3C  38 84 FF FF */	addi r4, r4, -1
/* 80005F40  38 C3 FF FF */	addi r6, r3, -1
/* 80005F44  38 A5 00 01 */	addi r5, r5, 1
/* 80005F48  48 00 00 0C */	b 0xc
/* 80005F4C  8C 04 00 01 */	lbzu r0, 1(r4)
/* 80005F50  9C 06 00 01 */	stbu r0, 1(r6)
/* 80005F54  34 A5 FF FF */	addic. r5, r5, -1
/* 80005F58  40 82 FF F4 */	bne -0xc
/* 80005F5C  4E 80 00 20 */	blr 
/* 80005F60  7C 84 2A 14 */	add r4, r4, r5
/* 80005F64  7C C3 2A 14 */	add r6, r3, r5
/* 80005F68  38 A5 00 01 */	addi r5, r5, 1
/* 80005F6C  48 00 00 0C */	b 0xc
/* 80005F70  8C 04 FF FF */	lbzu r0, -1(r4)
/* 80005F74  9C 06 FF FF */	stbu r0, -1(r6)
/* 80005F78  34 A5 FF FF */	addic. r5, r5, -1
/* 80005F7C  40 82 FF F4 */	bne -0xc
/* 80005F80  4E 80 00 20 */	blr 
/* 80005F84  28 05 00 20 */	cmplwi r5, 0x20
/* 80005F88  54 87 06 3E */	clrlwi r7, r4, 0x18
/* 80005F8C  38 C3 FF FF */	addi r6, r3, -1
/* 80005F90  41 80 00 90 */	blt 0x90
/* 80005F94  7C C0 30 F8 */	nor r0, r6, r6
/* 80005F98  54 00 07 BF */	clrlwi. r0, r0, 0x1e
/* 80005F9C  41 82 00 14 */	beq 0x14
/* 80005FA0  7C A0 28 50 */	subf r5, r0, r5
/* 80005FA4  34 00 FF FF */	addic. r0, r0, -1
/* 80005FA8  9C E6 00 01 */	stbu r7, 1(r6)
/* 80005FAC  40 82 FF F8 */	bne -0x8
/* 80005FB0  2C 07 00 00 */	cmpwi r7, 0
/* 80005FB4  41 82 00 1C */	beq 0x1c
/* 80005FB8  54 E4 40 2E */	slwi r4, r7, 8
/* 80005FBC  54 E3 C0 0E */	slwi r3, r7, 0x18
/* 80005FC0  54 E0 80 1E */	slwi r0, r7, 0x10
/* 80005FC4  7C E4 23 78 */	or r4, r7, r4
/* 80005FC8  7C 60 03 78 */	or r0, r3, r0
/* 80005FCC  7C 87 03 78 */	or r7, r4, r0
/* 80005FD0  54 A0 D9 7F */	rlwinm. r0, r5, 0x1b, 5, 0x1f
/* 80005FD4  38 66 FF FD */	addi r3, r6, -3
/* 80005FD8  41 82 00 2C */	beq 0x2c
/* 80005FDC  90 E3 00 04 */	stw r7, 4(r3)
/* 80005FE0  34 00 FF FF */	addic. r0, r0, -1
/* 80005FE4  90 E3 00 08 */	stw r7, 8(r3)
/* 80005FE8  90 E3 00 0C */	stw r7, 0xc(r3)
/* 80005FEC  90 E3 00 10 */	stw r7, 0x10(r3)
/* 80005FF0  90 E3 00 14 */	stw r7, 0x14(r3)
/* 80005FF4  90 E3 00 18 */	stw r7, 0x18(r3)
/* 80005FF8  90 E3 00 1C */	stw r7, 0x1c(r3)
/* 80005FFC  94 E3 00 20 */	stwu r7, 0x20(r3)
/* 80006000  40 82 FF DC */	bne -0x24
/* 80006004  54 A0 F7 7F */	rlwinm. r0, r5, 0x1e, 0x1d, 0x1f
/* 80006008  41 82 00 10 */	beq 0x10
/* 8000600C  34 00 FF FF */	addic. r0, r0, -1
/* 80006010  94 E3 00 04 */	stwu r7, 4(r3)
/* 80006014  40 82 FF F8 */	bne -0x8
/* 80006018  38 C3 00 03 */	addi r6, r3, 3
/* 8000601C  54 A5 07 BE */	clrlwi r5, r5, 0x1e
/* 80006020  2C 05 00 00 */	cmpwi r5, 0
/* 80006024  4D 82 00 20 */	beqlr 
/* 80006028  34 A5 FF FF */	addic. r5, r5, -1
/* 8000602C  9C E6 00 01 */	stbu r7, 1(r6)
/* 80006030  40 82 FF F8 */	bne -0x8
/* 80006034  4E 80 00 20 */	blr 
/* 80006038  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8000603C  7C 08 02 A6 */	mflr r0
/* 80006040  90 01 00 14 */	stw r0, 0x14(r1)
/* 80006044  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80006048  7C 7F 1B 78 */	mr r31, r3
/* 8000604C  4B FF FF 39 */	bl -0xc8
/* 80006050  7F E3 FB 78 */	mr r3, r31
/* 80006054  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80006058  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8000605C  7C 08 03 A6 */	mtlr r0
/* 80006060  38 21 00 10 */	addi r1, r1, 0x10
/* 80006064  4E 80 00 20 */	blr 
/* 80006068  3C 60 80 00 */	lis r3, 0x8000
/* 8000606C  A0 03 30 E4 */	lhz r0, 0x30e4(r3)
/* 80006070  70 00 0E EF */	andi. r0, r0, 0xeef
/* 80006074  2C 00 0E EF */	cmpwi r0, 0xeef
/* 80006078  4C 82 00 20 */	bnelr 
/* 8000607C  38 60 00 00 */	li r3, 0
/* 80006080  38 80 00 00 */	li r4, 0
/* 80006084  38 A0 00 00 */	li r5, 0
/* 80006088  48 1A 29 F8 */	b 0x1a29f8
/* 8000608C  4E 80 00 20 */	blr 
/* 80006090  38 00 00 01 */	li r0, 1
/* 80006094  98 0D 9D 50 */	stb r0, -0x62b0(r13)
/* 80006098  4E 80 00 20 */	blr 
/* 8000609C  88 6D 9D 50 */	lbz r3, -0x62b0(r13)
/* 800060A0  4E 80 00 20 */	blr 
/* 800060A4  48 00 01 6D */	bl 0x16c
/* 800060A8  48 00 02 A1 */	bl 0x2a0
/* 800060AC  38 00 FF FF */	li r0, -1
/* 800060B0  94 21 FF F8 */	stwu r1, -8(r1)
/* 800060B4  90 01 00 04 */	stw r0, 4(r1)
/* 800060B8  90 01 00 00 */	stw r0, 0(r1)
/* 800060BC  48 00 01 E5 */	bl 0x1e4
/* 800060C0  38 00 00 00 */	li r0, 0
/* 800060C4  3C C0 80 00 */	lis r6, 0x8000
/* 800060C8  38 C6 00 44 */	addi r6, r6, 0x44
/* 800060CC  90 06 00 00 */	stw r0, 0(r6)
/* 800060D0  3C C0 80 00 */	lis r6, 0x8000
/* 800060D4  38 C6 00 F4 */	addi r6, r6, 0xf4
/* 800060D8  80 C6 00 00 */	lwz r6, 0(r6)
/* 800060DC  28 06 00 00 */	cmplwi r6, 0
/* 800060E0  41 82 00 0C */	beq 0xc
/* 800060E4  80 E6 00 0C */	lwz r7, 0xc(r6)
/* 800060E8  48 00 00 24 */	b 0x24
/* 800060EC  3C A0 80 00 */	lis r5, 0x8000
/* 800060F0  38 A5 00 34 */	addi r5, r5, 0x34
/* 800060F4  80 A5 00 00 */	lwz r5, 0(r5)
/* 800060F8  28 05 00 00 */	cmplwi r5, 0
/* 800060FC  41 82 00 4C */	beq 0x4c
/* 80006100  3C E0 80 00 */	lis r7, 0x8000
/* 80006104  38 E7 30 E8 */	addi r7, r7, 0x30e8
/* 80006108  80 E7 00 00 */	lwz r7, 0(r7)
/* 8000610C  38 A0 00 00 */	li r5, 0
/* 80006110  28 07 00 02 */	cmplwi r7, 2
/* 80006114  41 82 00 24 */	beq 0x24
/* 80006118  28 07 00 03 */	cmplwi r7, 3
/* 8000611C  38 A0 00 01 */	li r5, 1
/* 80006120  41 82 00 18 */	beq 0x18
/* 80006124  28 07 00 04 */	cmplwi r7, 4
/* 80006128  40 82 00 20 */	bne 0x20
/* 8000612C  38 A0 00 02 */	li r5, 2
/* 80006130  4B FF FF 61 */	bl -0xa0
/* 80006134  48 00 00 14 */	b 0x14
/* 80006138  3C C0 80 02 */	lis r6, 0x8002
/* 8000613C  38 C6 C3 4C */	addi r6, r6, -15540
/* 80006140  7C C8 03 A6 */	mtlr r6
/* 80006144  4E 80 00 21 */	blrl 
/* 80006148  3C C0 80 00 */	lis r6, 0x8000
/* 8000614C  38 C6 00 F4 */	addi r6, r6, 0xf4
/* 80006150  80 A6 00 00 */	lwz r5, 0(r6)
/* 80006154  28 05 00 00 */	cmplwi r5, 0
/* 80006158  41 A2 00 60 */	beq+ 0x60
/* 8000615C  80 C5 00 08 */	lwz r6, 8(r5)
/* 80006160  28 06 00 00 */	cmplwi r6, 0
/* 80006164  41 A2 00 54 */	beq+ 0x54
/* 80006168  7C C5 32 14 */	add r6, r5, r6
/* 8000616C  81 C6 00 00 */	lwz r14, 0(r6)
/* 80006170  28 0E 00 00 */	cmplwi r14, 0
/* 80006174  41 82 00 44 */	beq 0x44
/* 80006178  39 E6 00 04 */	addi r15, r6, 4
/* 8000617C  7D C9 03 A6 */	mtctr r14
/* 80006180  38 C6 00 04 */	addi r6, r6, 4
/* 80006184  80 E6 00 00 */	lwz r7, 0(r6)
/* 80006188  7C E7 2A 14 */	add r7, r7, r5
/* 8000618C  90 E6 00 00 */	stw r7, 0(r6)
/* 80006190  42 00 FF F0 */	bdnz -0x10
/* 80006194  3C A0 80 00 */	lis r5, 0x8000
/* 80006198  38 A5 00 34 */	addi r5, r5, 0x34
/* 8000619C  55 E7 00 34 */	rlwinm r7, r15, 0, 0, 0x1a
/* 800061A0  90 E5 00 00 */	stw r7, 0(r5)
/* 800061A4  3C A0 80 00 */	lis r5, 0x8000
/* 800061A8  38 A5 31 10 */	addi r5, r5, 0x3110
/* 800061AC  55 E7 00 34 */	rlwinm r7, r15, 0, 0, 0x1a
/* 800061B0  90 E5 00 00 */	stw r7, 0(r5)
/* 800061B4  48 00 00 0C */	b 0xc
/* 800061B8  39 C0 00 00 */	li r14, 0
/* 800061BC  39 E0 00 00 */	li r15, 0
/* 800061C0  48 15 71 55 */	bl 0x157154
/* 800061C4  48 19 9A A5 */	bl 0x199aa4
/* 800061C8  3C 80 80 00 */	lis r4, 0x8000
/* 800061CC  38 84 30 E6 */	addi r4, r4, 0x30e6
/* 800061D0  A0 64 00 00 */	lhz r3, 0(r4)
/* 800061D4  70 65 80 00 */	andi. r5, r3, 0x8000
/* 800061D8  41 82 00 10 */	beq 0x10
/* 800061DC  70 63 7F FF */	andi. r3, r3, 0x7fff
/* 800061E0  28 03 00 01 */	cmplwi r3, 1
/* 800061E4  40 82 00 08 */	bne 0x8
/* 800061E8  4B FF FE 81 */	bl -0x180
/* 800061EC  4B FF FE B1 */	bl -0x150
/* 800061F0  28 03 00 01 */	cmplwi r3, 1
/* 800061F4  40 82 00 08 */	bne 0x8
/* 800061F8  48 01 61 ED */	bl 0x161ec
/* 800061FC  48 1A 83 29 */	bl 0x1a8328
/* 80006200  7D C3 73 78 */	mr r3, r14
/* 80006204  7D E4 7B 78 */	mr r4, r15
/* 80006208  48 00 54 A9 */	bl 0x54a8
/* 8000620C  48 1A 83 80 */	b 0x1a8380
/* 80006210  38 00 00 00 */	li r0, 0
/* 80006214  38 60 00 00 */	li r3, 0
/* 80006218  38 80 00 00 */	li r4, 0
/* 8000621C  38 A0 00 00 */	li r5, 0
/* 80006220  38 C0 00 00 */	li r6, 0
/* 80006224  38 E0 00 00 */	li r7, 0
/* 80006228  39 00 00 00 */	li r8, 0
/* 8000622C  39 20 00 00 */	li r9, 0
/* 80006230  39 40 00 00 */	li r10, 0
/* 80006234  39 60 00 00 */	li r11, 0
/* 80006238  39 80 00 00 */	li r12, 0
/* 8000623C  39 C0 00 00 */	li r14, 0
/* 80006240  39 E0 00 00 */	li r15, 0
/* 80006244  3A 00 00 00 */	li r16, 0
/* 80006248  3A 20 00 00 */	li r17, 0
/* 8000624C  3A 40 00 00 */	li r18, 0
/* 80006250  3A 60 00 00 */	li r19, 0
/* 80006254  3A 80 00 00 */	li r20, 0
/* 80006258  3A A0 00 00 */	li r21, 0
/* 8000625C  3A C0 00 00 */	li r22, 0
/* 80006260  3A E0 00 00 */	li r23, 0
/* 80006264  3B 00 00 00 */	li r24, 0
/* 80006268  3B 20 00 00 */	li r25, 0
/* 8000626C  3B 40 00 00 */	li r26, 0
/* 80006270  3B 60 00 00 */	li r27, 0
/* 80006274  3B 80 00 00 */	li r28, 0
/* 80006278  3B A0 00 00 */	li r29, 0
/* 8000627C  3B C0 00 00 */	li r30, 0
/* 80006280  3B E0 00 00 */	li r31, 0
/* 80006284  3C 20 80 39 */	lis r1, 0x8039
/* 80006288  60 21 91 80 */	ori r1, r1, 0x9180
/* 8000628C  3C 40 80 38 */	lis r2, 0x8038
/* 80006290  60 42 EF A0 */	ori r2, r2, 0xefa0
/* 80006294  3D A0 80 38 */	lis r13, 0x8038
/* 80006298  61 AD CC 00 */	ori r13, r13, 0xcc00
/* 8000629C  4E 80 00 20 */	blr 
/* 800062A0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800062A4  7C 08 02 A6 */	mflr r0
/* 800062A8  90 01 00 24 */	stw r0, 0x24(r1)
/* 800062AC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800062B0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800062B4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800062B8  3F A0 80 00 */	lis r29, 0x8000
/* 800062BC  3B BD 63 A0 */	addi r29, r29, 0x63a0
/* 800062C0  83 DD 00 08 */	lwz r30, 8(r29)
/* 800062C4  2C 1E 00 00 */	cmpwi r30, 0
/* 800062C8  41 82 00 38 */	beq 0x38
/* 800062CC  80 9D 00 00 */	lwz r4, 0(r29)
/* 800062D0  83 FD 00 04 */	lwz r31, 4(r29)
/* 800062D4  41 82 00 24 */	beq 0x24
/* 800062D8  7C 1F 20 40 */	cmplw r31, r4
/* 800062DC  41 82 00 1C */	beq 0x1c
/* 800062E0  7F E3 FB 78 */	mr r3, r31
/* 800062E4  7F C5 F3 78 */	mr r5, r30
/* 800062E8  4B FF FC 4D */	bl -0x3b4
/* 800062EC  7F E3 FB 78 */	mr r3, r31
/* 800062F0  7F C4 F3 78 */	mr r4, r30
/* 800062F4  48 00 00 79 */	bl 0x78
/* 800062F8  3B BD 00 0C */	addi r29, r29, 0xc
/* 800062FC  4B FF FF C4 */	b -0x3c
/* 80006300  3F A0 80 00 */	lis r29, 0x8000
/* 80006304  3B BD 64 24 */	addi r29, r29, 0x6424
/* 80006308  80 BD 00 04 */	lwz r5, 4(r29)
/* 8000630C  2C 05 00 00 */	cmpwi r5, 0
/* 80006310  41 82 00 1C */	beq 0x1c
/* 80006314  80 7D 00 00 */	lwz r3, 0(r29)
/* 80006318  41 82 00 0C */	beq 0xc
/* 8000631C  38 80 00 00 */	li r4, 0
/* 80006320  4B FF FD 19 */	bl -0x2e8
/* 80006324  3B BD 00 08 */	addi r29, r29, 8
/* 80006328  4B FF FF E0 */	b -0x20
/* 8000632C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80006330  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80006334  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80006338  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8000633C  7C 08 03 A6 */	mtlr r0
/* 80006340  38 21 00 20 */	addi r1, r1, 0x20
/* 80006344  4E 80 00 20 */	blr 
/* 80006348  7C 00 00 A6 */	mfmsr r0
/* 8000634C  60 00 20 00 */	ori r0, r0, 0x2000
/* 80006350  7C 00 01 24 */	mtmsr r0
/* 80006354  7F E8 02 A6 */	mflr r31
/* 80006358  48 19 A1 49 */	bl 0x19a148
/* 8000635C  48 19 8E 4D */	bl 0x198e4c
/* 80006360  48 19 B7 85 */	bl 0x19b784
/* 80006364  7F E8 03 A6 */	mtlr r31
/* 80006368  4E 80 00 20 */	blr 
/* 8000636C  3C A0 FF FF */	lis r5, 0xffff
/* 80006370  60 A5 FF F1 */	ori r5, r5, 0xfff1
/* 80006374  7C A5 18 38 */	and r5, r5, r3
/* 80006378  7C 65 18 50 */	subf r3, r5, r3
/* 8000637C  7C 84 1A 14 */	add r4, r4, r3
/* 80006380  7C 00 28 6C */	dcbst 0, r5
/* 80006384  7C 00 04 AC */	sync 0
/* 80006388  7C 00 2F AC */	icbi 0, r5
/* 8000638C  30 A5 00 08 */	addic r5, r5, 8
/* 80006390  34 84 FF F8 */	addic. r4, r4, -8
/* 80006394  40 80 FF EC */	bge -0x14
/* 80006398  4C 00 01 2C */	isync 
/* 8000639C  4E 80 00 20 */	blr 
/* 800063A0  80 00 40 00 */	lwz r0, 0x4000(0)
/* 800063A4  80 00 40 00 */	lwz r0, 0x4000(0)
/* 800063A8  00 00 24 44 */	.4byte 0x00002444  /* unknown instruction */
/* 800063AC  80 00 64 60 */	lwz r0, 0x6460(0)
/* 800063B0  80 00 64 60 */	lwz r0, 0x6460(0)
/* 800063B4  00 00 05 C0 */	.4byte 0x000005C0  /* unknown instruction */
/* 800063B8  80 00 6A 20 */	lwz r0, 0x6a20(0)
/* 800063BC  80 00 6A 20 */	lwz r0, 0x6a20(0)
/* 800063C0  00 00 08 90 */	.4byte 0x00000890  /* unknown instruction */
/* 800063C4  80 00 72 C0 */	lwz r0, 0x72c0(0)
/* 800063C8  80 00 72 C0 */	lwz r0, 0x72c0(0)
/* 800063CC  00 23 DB 14 */	.4byte 0x0023DB14  /* unknown instruction */
/* 800063D0  80 24 4D E0 */	lwz r1, 0x4de0(r4)
/* 800063D4  80 24 4D E0 */	lwz r1, 0x4de0(r4)
/* 800063D8  00 00 00 B0 */	.4byte 0x000000B0  /* unknown instruction */
/* 800063DC  80 24 4E A0 */	lwz r1, 0x4ea0(r4)
/* 800063E0  80 24 4E A0 */	lwz r1, 0x4ea0(r4)
/* 800063E4  00 00 00 0C */	.4byte 0x0000000C  /* unknown instruction */
/* 800063E8  80 24 4E C0 */	lwz r1, 0x4ec0(r4)
/* 800063EC  80 24 4E C0 */	lwz r1, 0x4ec0(r4)
/* 800063F0  00 01 36 AC */	.4byte 0x000136AC  /* unknown instruction */
/* 800063F4  80 25 85 80 */	lwz r1, -0x7a80(r5)
/* 800063F8  80 25 85 80 */	lwz r1, -0x7a80(r5)
/* 800063FC  00 04 BA BC */	.4byte 0x0004BABC  /* unknown instruction */
/* 80006400  80 38 4C 00 */	lwz r1, 0x4c00(r24)
/* 80006404  80 38 4C 00 */	lwz r1, 0x4c00(r24)
/* 80006408  00 00 13 C0 */	.4byte 0x000013C0  /* unknown instruction */
/* 8000640C  80 38 6F A0 */	lwz r1, 0x6fa0(r24)
/* 80006410  80 38 6F A0 */	lwz r1, 0x6fa0(r24)
/* 80006414  00 00 21 9C */	.4byte 0x0000219C  /* unknown instruction */
/* 80006418  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000641C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80006420  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80006424  80 2A 40 80 */	lwz r1, 0x4080(r10)
/* 80006428  00 0E 0B 74 */	.4byte 0x000E0B74  /* unknown instruction */
/* 8000642C  80 38 5F C0 */	lwz r1, 0x5fc0(r24)
/* 80006430  00 00 0F D0 */	.4byte 0x00000FD0  /* unknown instruction */
/* 80006434  80 38 91 40 */	lwz r1, -0x6ec0(r24)
/* 80006438  00 00 00 3C */	.4byte 0x0000003C  /* unknown instruction */
/* 8000643C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80006440  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80006444  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80006448  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000644C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80006450  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80006454  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80006458  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000645C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
