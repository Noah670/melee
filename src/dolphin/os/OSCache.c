#include <dolphin/types.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/base/PPCArch.h>
#include <dolphin/os/os.h>
#include <dolphin/os/OSError.h>

#pragma push
asm unk_t DCEnable()
{ // clang-format off
    nofralloc
/* 803447C8 003413A8  7C 00 04 AC */	sync
/* 803447CC 003413AC  7C 70 FA A6 */	mfspr r3, 0x3f0
/* 803447D0 003413B0  60 63 40 00 */	ori r3, r3, 0x4000
/* 803447D4 003413B4  7C 70 FB A6 */	mtspr 0x3f0, r3
/* 803447D8 003413B8  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t DCInvalidateRange()
{ // clang-format off
    nofralloc
/* 803447DC 003413BC  28 04 00 00 */	cmplwi r4, 0
/* 803447E0 003413C0  4C 81 00 20 */	blelr 
/* 803447E4 003413C4  54 65 06 FF */	clrlwi. r5, r3, 0x1b
/* 803447E8 003413C8  41 82 00 08 */	beq lbl_803447F0
/* 803447EC 003413CC  38 84 00 20 */	addi r4, r4, 0x20
lbl_803447F0:
/* 803447F0 003413D0  38 84 00 1F */	addi r4, r4, 0x1f
/* 803447F4 003413D4  54 84 D9 7E */	srwi r4, r4, 5
/* 803447F8 003413D8  7C 89 03 A6 */	mtctr r4
lbl_803447FC:
/* 803447FC 003413DC  7C 00 1B AC */	dcbi 0, r3
/* 80344800 003413E0  38 63 00 20 */	addi r3, r3, 0x20
/* 80344804 003413E4  42 00 FF F8 */	bdnz lbl_803447FC
/* 80344808 003413E8  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

// https://decomp.me/scratch/y3hWw
#pragma push
asm unk_t DCFlushRange()
{ // clang-format off
    nofralloc
/* 8034480C 003413EC  28 04 00 00 */	cmplwi r4, 0
/* 80344810 003413F0  4C 81 00 20 */	blelr 
/* 80344814 003413F4  54 65 06 FF */	clrlwi. r5, r3, 0x1b
/* 80344818 003413F8  41 82 00 08 */	beq lbl_80344820
/* 8034481C 003413FC  38 84 00 20 */	addi r4, r4, 0x20
lbl_80344820:
/* 80344820 00341400  38 84 00 1F */	addi r4, r4, 0x1f
/* 80344824 00341404  54 84 D9 7E */	srwi r4, r4, 5
/* 80344828 00341408  7C 89 03 A6 */	mtctr r4
lbl_8034482C:
/* 8034482C 0034140C  7C 00 18 AC */	dcbf 0, r3
/* 80344830 00341410  38 63 00 20 */	addi r3, r3, 0x20
/* 80344834 00341414  42 00 FF F8 */	bdnz lbl_8034482C
/* 80344838 00341418  44 00 00 02 */	sc 
/* 8034483C 0034141C  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t DCStoreRange()
{ // clang-format off
    nofralloc
/* 80344840 00341420  28 04 00 00 */	cmplwi r4, 0
/* 80344844 00341424  4C 81 00 20 */	blelr 
/* 80344848 00341428  54 65 06 FF */	clrlwi. r5, r3, 0x1b
/* 8034484C 0034142C  41 82 00 08 */	beq lbl_80344854
/* 80344850 00341430  38 84 00 20 */	addi r4, r4, 0x20
lbl_80344854:
/* 80344854 00341434  38 84 00 1F */	addi r4, r4, 0x1f
/* 80344858 00341438  54 84 D9 7E */	srwi r4, r4, 5
/* 8034485C 0034143C  7C 89 03 A6 */	mtctr r4
lbl_80344860:
/* 80344860 00341440  7C 00 18 6C */	dcbst 0, r3
/* 80344864 00341444  38 63 00 20 */	addi r3, r3, 0x20
/* 80344868 00341448  42 00 FF F8 */	bdnz lbl_80344860
/* 8034486C 0034144C  44 00 00 02 */	sc 
/* 80344870 00341450  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t DCFlushRangeNoSync()
{ // clang-format off
    nofralloc
/* 80344874 00341454  28 04 00 00 */	cmplwi r4, 0
/* 80344878 00341458  4C 81 00 20 */	blelr 
/* 8034487C 0034145C  54 65 06 FF */	clrlwi. r5, r3, 0x1b
/* 80344880 00341460  41 82 00 08 */	beq lbl_80344888
/* 80344884 00341464  38 84 00 20 */	addi r4, r4, 0x20
lbl_80344888:
/* 80344888 00341468  38 84 00 1F */	addi r4, r4, 0x1f
/* 8034488C 0034146C  54 84 D9 7E */	srwi r4, r4, 5
/* 80344890 00341470  7C 89 03 A6 */	mtctr r4
lbl_80344894:
/* 80344894 00341474  7C 00 18 AC */	dcbf 0, r3
/* 80344898 00341478  38 63 00 20 */	addi r3, r3, 0x20
/* 8034489C 0034147C  42 00 FF F8 */	bdnz lbl_80344894
/* 803448A0 00341480  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t DCZeroRange()
{ // clang-format off
    nofralloc
/* 803448A4 00341484  28 04 00 00 */	cmplwi r4, 0
/* 803448A8 00341488  4C 81 00 20 */	blelr 
/* 803448AC 0034148C  54 65 06 FF */	clrlwi. r5, r3, 0x1b
/* 803448B0 00341490  41 82 00 08 */	beq lbl_803448B8
/* 803448B4 00341494  38 84 00 20 */	addi r4, r4, 0x20
lbl_803448B8:
/* 803448B8 00341498  38 84 00 1F */	addi r4, r4, 0x1f
/* 803448BC 0034149C  54 84 D9 7E */	srwi r4, r4, 5
/* 803448C0 003414A0  7C 89 03 A6 */	mtctr r4
lbl_803448C4:
/* 803448C4 003414A4  7C 00 1F EC */	dcbz 0, r3
/* 803448C8 003414A8  38 63 00 20 */	addi r3, r3, 0x20
/* 803448CC 003414AC  42 00 FF F8 */	bdnz lbl_803448C4
/* 803448D0 003414B0  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t ICInvalidateRange()
{ // clang-format off
    nofralloc
/* 803448D4 003414B4  28 04 00 00 */	cmplwi r4, 0
/* 803448D8 003414B8  4C 81 00 20 */	blelr 
/* 803448DC 003414BC  54 65 06 FF */	clrlwi. r5, r3, 0x1b
/* 803448E0 003414C0  41 82 00 08 */	beq lbl_803448E8
/* 803448E4 003414C4  38 84 00 20 */	addi r4, r4, 0x20
lbl_803448E8:
/* 803448E8 003414C8  38 84 00 1F */	addi r4, r4, 0x1f
/* 803448EC 003414CC  54 84 D9 7E */	srwi r4, r4, 5
/* 803448F0 003414D0  7C 89 03 A6 */	mtctr r4
lbl_803448F4:
/* 803448F4 003414D4  7C 00 1F AC */	icbi 0, r3
/* 803448F8 003414D8  38 63 00 20 */	addi r3, r3, 0x20
/* 803448FC 003414DC  42 00 FF F8 */	bdnz lbl_803448F4
/* 80344900 003414E0  7C 00 04 AC */	sync
/* 80344904 003414E4  4C 00 01 2C */	isync 
/* 80344908 003414E8  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t ICFlashInvalidate()
{ // clang-format off
    nofralloc
/* 8034490C 003414EC  7C 70 FA A6 */	mfspr r3, 0x3f0
/* 80344910 003414F0  60 63 08 00 */	ori r3, r3, 0x800
/* 80344914 003414F4  7C 70 FB A6 */	mtspr 0x3f0, r3
/* 80344918 003414F8  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t ICEnable()
{ // clang-format off
    nofralloc
/* 8034491C 003414FC  4C 00 01 2C */	isync 
/* 80344920 00341500  7C 70 FA A6 */	mfspr r3, 0x3f0
/* 80344924 00341504  60 63 80 00 */	ori r3, r3, 0x8000
/* 80344928 00341508  7C 70 FB A6 */	mtspr 0x3f0, r3
/* 8034492C 0034150C  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t __LCEnable()
{ // clang-format off
    nofralloc
/* 80344930 00341510  7C A0 00 A6 */	mfmsr r5
/* 80344934 00341514  60 A5 10 00 */	ori r5, r5, 0x1000
/* 80344938 00341518  7C A0 01 24 */	mtmsr r5
/* 8034493C 0034151C  3C 60 80 00 */	lis r3, 0x80000020@ha
/* 80344940 00341520  38 80 04 00 */	li r4, 0x400
/* 80344944 00341524  7C 89 03 A6 */	mtctr r4
lbl_80344948:
/* 80344948 00341528  7C 00 1A 2C */	dcbt 0, r3
/* 8034494C 0034152C  7C 00 18 6C */	dcbst 0, r3
/* 80344950 00341530  38 63 00 20 */	addi r3, r3, 0x80000020@l
/* 80344954 00341534  42 00 FF F4 */	bdnz lbl_80344948
/* 80344958 00341538  7C 98 E2 A6 */	mfspr r4, 0x398
/* 8034495C 0034153C  64 84 10 0F */	oris r4, r4, 0x100f
/* 80344960 00341540  7C 98 E3 A6 */	mtspr 0x398, r4
/* 80344964 00341544  60 00 00 00 */	nop 
/* 80344968 00341548  60 00 00 00 */	nop 
/* 8034496C 0034154C  60 00 00 00 */	nop 
/* 80344970 00341550  60 00 00 00 */	nop 
/* 80344974 00341554  60 00 00 00 */	nop 
/* 80344978 00341558  60 00 00 00 */	nop 
/* 8034497C 0034155C  60 00 00 00 */	nop 
/* 80344980 00341560  60 00 00 00 */	nop 
/* 80344984 00341564  60 00 00 00 */	nop 
/* 80344988 00341568  60 00 00 00 */	nop 
/* 8034498C 0034156C  60 00 00 00 */	nop 
/* 80344990 00341570  60 00 00 00 */	nop 
/* 80344994 00341574  3C 60 E0 00 */	lis r3, 0xE0000002@h
/* 80344998 00341578  60 63 00 02 */	ori r3, r3, 0xE0000002@l
/* 8034499C 0034157C  7C 7F 83 A6 */	mtdbatl 3, r3
/* 803449A0 00341580  60 63 01 FE */	ori r3, r3, 0x1fe
/* 803449A4 00341584  7C 7E 83 A6 */	mtdbatu 3, r3
/* 803449A8 00341588  4C 00 01 2C */	isync 
/* 803449AC 0034158C  3C 60 E0 00 */	lis r3, 0xE0000020@ha
/* 803449B0 00341590  38 C0 02 00 */	li r6, 0x200
/* 803449B4 00341594  7C C9 03 A6 */	mtctr r6
/* 803449B8 00341598  38 C0 00 00 */	li r6, 0
lbl_803449BC:
/* 803449BC 0034159C  10 06 1F EC */	dcbz_l r6, r3
/* 803449C0 003415A0  38 63 00 20 */	addi r3, r3, 0xE0000020@l
/* 803449C4 003415A4  42 00 FF F8 */	bdnz lbl_803449BC
/* 803449C8 003415A8  60 00 00 00 */	nop 
/* 803449CC 003415AC  60 00 00 00 */	nop 
/* 803449D0 003415B0  60 00 00 00 */	nop 
/* 803449D4 003415B4  60 00 00 00 */	nop 
/* 803449D8 003415B8  60 00 00 00 */	nop 
/* 803449DC 003415BC  60 00 00 00 */	nop 
/* 803449E0 003415C0  60 00 00 00 */	nop 
/* 803449E4 003415C4  60 00 00 00 */	nop 
/* 803449E8 003415C8  60 00 00 00 */	nop 
/* 803449EC 003415CC  60 00 00 00 */	nop 
/* 803449F0 003415D0  60 00 00 00 */	nop 
/* 803449F4 003415D4  60 00 00 00 */	nop 
/* 803449F8 003415D8  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t LCEnable()
{ // clang-format off
    nofralloc
/* 803449FC 003415DC  7C 08 02 A6 */	mflr r0
/* 80344A00 003415E0  90 01 00 04 */	stw r0, 4(r1)
/* 80344A04 003415E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80344A08 003415E8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80344A0C 003415EC  48 00 29 59 */	bl OSDisableInterrupts
/* 80344A10 003415F0  7C 7F 1B 78 */	mr r31, r3
/* 80344A14 003415F4  4B FF FF 1D */	bl __LCEnable
/* 80344A18 003415F8  7F E3 FB 78 */	mr r3, r31
/* 80344A1C 003415FC  48 00 29 71 */	bl OSRestoreInterrupts
/* 80344A20 00341600  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80344A24 00341604  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80344A28 00341608  38 21 00 10 */	addi r1, r1, 0x10
/* 80344A2C 0034160C  7C 08 03 A6 */	mtlr r0
/* 80344A30 00341610  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t LCDisable()
{ // clang-format off
    nofralloc
/* 80344A34 00341614  3C 60 E0 00 */	lis r3, 0xE0000020@ha
/* 80344A38 00341618  38 80 02 00 */	li r4, 0x200
/* 80344A3C 0034161C  7C 89 03 A6 */	mtctr r4
lbl_80344A40:
/* 80344A40 00341620  7C 00 1B AC */	dcbi 0, r3
/* 80344A44 00341624  38 63 00 20 */	addi r3, r3, 0xE0000020@l
/* 80344A48 00341628  42 00 FF F8 */	bdnz lbl_80344A40
/* 80344A4C 0034162C  7C 98 E2 A6 */	mfspr r4, 0x398
/* 80344A50 00341630  54 84 01 04 */	rlwinm r4, r4, 0, 4, 2
/* 80344A54 00341634  7C 98 E3 A6 */	mtspr 0x398, r4
/* 80344A58 00341638  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t LCStoreBlocks()
{ // clang-format off
    nofralloc
/* 80344A5C 0034163C  54 A6 F6 FE */	rlwinm r6, r5, 0x1e, 0x1b, 0x1f
/* 80344A60 00341640  54 63 01 3E */	clrlwi r3, r3, 4
/* 80344A64 00341644  7C C6 1B 78 */	or r6, r6, r3
/* 80344A68 00341648  7C DA E3 A6 */	mtspr 0x39a, r6
/* 80344A6C 0034164C  54 A6 17 3A */	rlwinm r6, r5, 2, 0x1c, 0x1d
/* 80344A70 00341650  7C C6 23 78 */	or r6, r6, r4
/* 80344A74 00341654  60 C6 00 02 */	ori r6, r6, 2
/* 80344A78 00341658  7C DB E3 A6 */	mtspr 0x39b, r6
/* 80344A7C 0034165C  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t LCStoreData()
{ // clang-format off
    nofralloc
/* 80344A80 00341660  7C 08 02 A6 */	mflr r0
/* 80344A84 00341664  90 01 00 04 */	stw r0, 4(r1)
/* 80344A88 00341668  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80344A8C 0034166C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80344A90 00341670  93 C1 00 20 */	stw r30, 0x20(r1)
/* 80344A94 00341674  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 80344A98 00341678  93 81 00 18 */	stw r28, 0x18(r1)
/* 80344A9C 0034167C  7C 7C 1B 78 */	mr r28, r3
/* 80344AA0 00341680  7C 9D 23 78 */	mr r29, r4
/* 80344AA4 00341684  38 05 00 1F */	addi r0, r5, 0x1f
/* 80344AA8 00341688  54 03 D9 7E */	srwi r3, r0, 5
/* 80344AAC 0034168C  38 03 00 7F */	addi r0, r3, 0x7f
/* 80344AB0 00341690  7C 7F 1B 78 */	mr r31, r3
/* 80344AB4 00341694  54 1E C9 FE */	srwi r30, r0, 7
/* 80344AB8 00341698  48 00 00 04 */	b lbl_80344ABC
lbl_80344ABC:
/* 80344ABC 0034169C  48 00 00 04 */	b lbl_80344AC0
lbl_80344AC0:
/* 80344AC0 003416A0  48 00 00 40 */	b lbl_80344B00
lbl_80344AC4:
/* 80344AC4 003416A4  28 1F 00 80 */	cmplwi r31, 0x80
/* 80344AC8 003416A8  40 80 00 1C */	bge lbl_80344AE4
/* 80344ACC 003416AC  7F 83 E3 78 */	mr r3, r28
/* 80344AD0 003416B0  7F A4 EB 78 */	mr r4, r29
/* 80344AD4 003416B4  7F E5 FB 78 */	mr r5, r31
/* 80344AD8 003416B8  4B FF FF 85 */	bl LCStoreBlocks
/* 80344ADC 003416BC  3B E0 00 00 */	li r31, 0
/* 80344AE0 003416C0  48 00 00 20 */	b lbl_80344B00
lbl_80344AE4:
/* 80344AE4 003416C4  7F 83 E3 78 */	mr r3, r28
/* 80344AE8 003416C8  7F A4 EB 78 */	mr r4, r29
/* 80344AEC 003416CC  38 A0 00 00 */	li r5, 0
/* 80344AF0 003416D0  4B FF FF 6D */	bl LCStoreBlocks
/* 80344AF4 003416D4  3B FF FF 80 */	addi r31, r31, -128
/* 80344AF8 003416D8  3B 9C 10 00 */	addi r28, r28, 0x1000
/* 80344AFC 003416DC  3B BD 10 00 */	addi r29, r29, 0x1000
lbl_80344B00:
/* 80344B00 003416E0  28 1F 00 00 */	cmplwi r31, 0
/* 80344B04 003416E4  40 82 FF C0 */	bne lbl_80344AC4
/* 80344B08 003416E8  7F C3 F3 78 */	mr r3, r30
/* 80344B0C 003416EC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80344B10 003416F0  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80344B14 003416F4  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 80344B18 003416F8  7C 08 03 A6 */	mtlr r0
/* 80344B1C 003416FC  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 80344B20 00341700  83 81 00 18 */	lwz r28, 0x18(r1)
/* 80344B24 00341704  38 21 00 28 */	addi r1, r1, 0x28
/* 80344B28 00341708  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t LCQueueWait()
{ // clang-format off
    nofralloc
/* 80344B2C 0034170C  38 63 00 01 */	addi r3, r3, 1
lbl_80344B30:
/* 80344B30 00341710  7C 98 E2 A6 */	mfspr r4, 0x398
/* 80344B34 00341714  54 84 47 3E */	rlwinm r4, r4, 8, 0x1c, 0x1f
/* 80344B38 00341718  7D 04 18 00 */	cmpw cr2, r4, r3
/* 80344B3C 0034171C  40 88 FF F4 */	bge cr2, lbl_80344B30
/* 80344B40 00341720  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

extern char* lbl_80401BF0[];
extern unk_t DBPrintf();

#pragma push
asm unk_t L2GlobalInvalidate()
{ // clang-format off
    nofralloc
/* 80344B44 00341724  7C 08 02 A6 */	mflr r0
/* 80344B48 00341728  90 01 00 04 */	stw r0, 4(r1)
/* 80344B4C 0034172C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80344B50 00341730  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80344B54 00341734  7C 00 04 AC */	sync
/* 80344B58 00341738  4B FF 13 1D */	bl PPCMfl2cr
/* 80344B5C 0034173C  54 63 00 7E */	clrlwi r3, r3, 1
/* 80344B60 00341740  4B FF 13 1D */	bl PPCMtl2cr
/* 80344B64 00341744  7C 00 04 AC */	sync
/* 80344B68 00341748  4B FF 13 0D */	bl PPCMfl2cr
/* 80344B6C 0034174C  64 63 00 20 */	oris r3, r3, 0x20
/* 80344B70 00341750  4B FF 13 0D */	bl PPCMtl2cr
/* 80344B74 00341754  48 00 00 04 */	b lbl_80344B78
lbl_80344B78:
/* 80344B78 00341758  48 00 00 04 */	b lbl_80344B7C
lbl_80344B7C:
/* 80344B7C 0034175C  4B FF 12 F9 */	bl PPCMfl2cr
/* 80344B80 00341760  54 60 07 FE */	clrlwi r0, r3, 0x1f
/* 80344B84 00341764  28 00 00 00 */	cmplwi r0, 0
/* 80344B88 00341768  40 82 FF F4 */	bne lbl_80344B7C
/* 80344B8C 0034176C  4B FF 12 E9 */	bl PPCMfl2cr
/* 80344B90 00341770  54 63 02 D2 */	rlwinm r3, r3, 0, 0xb, 9
/* 80344B94 00341774  4B FF 12 E9 */	bl PPCMtl2cr
/* 80344B98 00341778  48 00 00 04 */	b lbl_80344B9C
lbl_80344B9C:
/* 80344B9C 0034177C  3C 60 80 40 */	lis r3, lbl_80401BF0@ha
/* 80344BA0 00341780  3B E3 1B F0 */	addi r31, r3, lbl_80401BF0@l
/* 80344BA4 00341784  48 00 00 04 */	b lbl_80344BA8
lbl_80344BA8:
/* 80344BA8 00341788  48 00 00 10 */	b lbl_80344BB8
lbl_80344BAC:
/* 80344BAC 0034178C  7F E3 FB 78 */	mr r3, r31
/* 80344BB0 00341790  4C C6 31 82 */	crclr 6
/* 80344BB4 00341794  4B FF 13 C5 */	bl DBPrintf
lbl_80344BB8:
/* 80344BB8 00341798  4B FF 12 BD */	bl PPCMfl2cr
/* 80344BBC 0034179C  54 60 07 FE */	clrlwi r0, r3, 0x1f
/* 80344BC0 003417A0  28 00 00 00 */	cmplwi r0, 0
/* 80344BC4 003417A4  40 82 FF E8 */	bne lbl_80344BAC
/* 80344BC8 003417A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80344BCC 003417AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80344BD0 003417B0  38 21 00 10 */	addi r1, r1, 0x10
/* 80344BD4 003417B4  7C 08 03 A6 */	mtlr r0
/* 80344BD8 003417B8  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t DMAErrorHandler()
{ // clang-format off
    nofralloc
/* 80344BDC 003417BC  7C 08 02 A6 */	mflr r0
/* 80344BE0 003417C0  90 01 00 04 */	stw r0, 4(r1)
/* 80344BE4 003417C4  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 80344BE8 003417C8  93 E1 00 7C */	stw r31, 0x7c(r1)
/* 80344BEC 003417CC  93 C1 00 78 */	stw r30, 0x78(r1)
/* 80344BF0 003417D0  93 A1 00 74 */	stw r29, 0x74(r1)
/* 80344BF4 003417D4  40 86 00 24 */	bne cr1, lbl_80344C18
/* 80344BF8 003417D8  D8 21 00 28 */	stfd f1, 0x28(r1)
/* 80344BFC 003417DC  D8 41 00 30 */	stfd f2, 0x30(r1)
/* 80344C00 003417E0  D8 61 00 38 */	stfd f3, 0x38(r1)
/* 80344C04 003417E4  D8 81 00 40 */	stfd f4, 0x40(r1)
/* 80344C08 003417E8  D8 A1 00 48 */	stfd f5, 0x48(r1)
/* 80344C0C 003417EC  D8 C1 00 50 */	stfd f6, 0x50(r1)
/* 80344C10 003417F0  D8 E1 00 58 */	stfd f7, 0x58(r1)
/* 80344C14 003417F4  D9 01 00 60 */	stfd f8, 0x60(r1)
lbl_80344C18:
/* 80344C18 003417F8  90 61 00 08 */	stw r3, 8(r1)
/* 80344C1C 003417FC  90 81 00 0C */	stw r4, 0xc(r1)
/* 80344C20 00341800  90 A1 00 10 */	stw r5, 0x10(r1)
/* 80344C24 00341804  90 C1 00 14 */	stw r6, 0x14(r1)
/* 80344C28 00341808  90 E1 00 18 */	stw r7, 0x18(r1)
/* 80344C2C 0034180C  91 01 00 1C */	stw r8, 0x1c(r1)
/* 80344C30 00341810  91 21 00 20 */	stw r9, 0x20(r1)
/* 80344C34 00341814  91 41 00 24 */	stw r10, 0x24(r1)
/* 80344C38 00341818  7C 9D 23 78 */	mr r29, r4
/* 80344C3C 0034181C  3C 60 80 40 */	lis r3, lbl_80401BF0@ha
/* 80344C40 00341820  3B E3 1B F0 */	addi r31, r3, lbl_80401BF0@l
/* 80344C44 00341824  4B FF 12 65 */	bl PPCMfhid2
/* 80344C48 00341828  7C 7E 1B 78 */	mr r30, r3
/* 80344C4C 0034182C  4C C6 31 82 */	crclr 6
/* 80344C50 00341830  38 7F 00 2C */	addi r3, r31, 0x2c
/* 80344C54 00341834  48 00 0A 55 */	bl OSReport
/* 80344C58 00341838  80 BD 01 9C */	lwz r5, 0x19c(r29)
/* 80344C5C 0034183C  7F C4 F3 78 */	mr r4, r30
/* 80344C60 00341840  38 7F 00 44 */	addi r3, r31, 0x44
/* 80344C64 00341844  4C C6 31 82 */	crclr 6
/* 80344C68 00341848  48 00 0A 41 */	bl OSReport
/* 80344C6C 0034184C  57 C0 02 16 */	rlwinm r0, r30, 0, 8, 0xb
/* 80344C70 00341850  28 00 00 00 */	cmplwi r0, 0
/* 80344C74 00341854  41 82 00 14 */	beq lbl_80344C88
/* 80344C78 00341858  80 1D 01 9C */	lwz r0, 0x19c(r29)
/* 80344C7C 0034185C  54 00 02 94 */	rlwinm r0, r0, 0, 0xa, 0xa
/* 80344C80 00341860  28 00 00 00 */	cmplwi r0, 0
/* 80344C84 00341864  40 82 00 1C */	bne lbl_80344CA0
lbl_80344C88:
/* 80344C88 00341868  38 7F 00 60 */	addi r3, r31, 0x60
/* 80344C8C 0034186C  4C C6 31 82 */	crclr 6
/* 80344C90 00341870  48 00 0A 19 */	bl OSReport
/* 80344C94 00341874  7F A3 EB 78 */	mr r3, r29
/* 80344C98 00341878  48 00 06 9D */	bl OSDumpContext
/* 80344C9C 0034187C  4B FF 11 F9 */	bl PPCHalt
lbl_80344CA0:
/* 80344CA0 00341880  38 7F 00 90 */	addi r3, r31, 0x90
/* 80344CA4 00341884  4C C6 31 82 */	crclr 6
/* 80344CA8 00341888  48 00 0A 01 */	bl OSReport
/* 80344CAC 0034188C  38 7F 00 CC */	addi r3, r31, 0xcc
/* 80344CB0 00341890  4C C6 31 82 */	crclr 6
/* 80344CB4 00341894  48 00 09 F5 */	bl OSReport
/* 80344CB8 00341898  57 C0 02 10 */	rlwinm r0, r30, 0, 8, 8
/* 80344CBC 0034189C  28 00 00 00 */	cmplwi r0, 0
/* 80344CC0 003418A0  41 82 00 10 */	beq lbl_80344CD0
/* 80344CC4 003418A4  38 7F 01 04 */	addi r3, r31, 0x104
/* 80344CC8 003418A8  4C C6 31 82 */	crclr 6
/* 80344CCC 003418AC  48 00 09 DD */	bl OSReport
lbl_80344CD0:
/* 80344CD0 003418B0  57 C0 02 52 */	rlwinm r0, r30, 0, 9, 9
/* 80344CD4 003418B4  28 00 00 00 */	cmplwi r0, 0
/* 80344CD8 003418B8  41 82 00 10 */	beq lbl_80344CE8
/* 80344CDC 003418BC  38 7F 01 44 */	addi r3, r31, 0x144
/* 80344CE0 003418C0  4C C6 31 82 */	crclr 6
/* 80344CE4 003418C4  48 00 09 C5 */	bl OSReport
lbl_80344CE8:
/* 80344CE8 003418C8  57 C0 02 94 */	rlwinm r0, r30, 0, 0xa, 0xa
/* 80344CEC 003418CC  28 00 00 00 */	cmplwi r0, 0
/* 80344CF0 003418D0  41 82 00 10 */	beq lbl_80344D00
/* 80344CF4 003418D4  38 7F 01 70 */	addi r3, r31, 0x170
/* 80344CF8 003418D8  4C C6 31 82 */	crclr 6
/* 80344CFC 003418DC  48 00 09 AD */	bl OSReport
lbl_80344D00:
/* 80344D00 003418E0  57 C0 02 D6 */	rlwinm r0, r30, 0, 0xb, 0xb
/* 80344D04 003418E4  28 00 00 00 */	cmplwi r0, 0
/* 80344D08 003418E8  41 82 00 10 */	beq lbl_80344D18
/* 80344D0C 003418EC  38 7F 01 90 */	addi r3, r31, 0x190
/* 80344D10 003418F0  4C C6 31 82 */	crclr 6
/* 80344D14 003418F4  48 00 09 95 */	bl OSReport
lbl_80344D18:
/* 80344D18 003418F8  7F C3 F3 78 */	mr r3, r30
/* 80344D1C 003418FC  4B FF 11 95 */	bl PPCMthid2
/* 80344D20 00341900  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80344D24 00341904  83 E1 00 7C */	lwz r31, 0x7c(r1)
/* 80344D28 00341908  83 C1 00 78 */	lwz r30, 0x78(r1)
/* 80344D2C 0034190C  7C 08 03 A6 */	mtlr r0
/* 80344D30 00341910  83 A1 00 74 */	lwz r29, 0x74(r1)
/* 80344D34 00341914  38 21 00 80 */	addi r1, r1, 0x80
/* 80344D38 00341918  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t __OSCacheInit()
{ // clang-format off
    nofralloc
/* 80344D3C 0034191C  7C 08 02 A6 */	mflr r0
/* 80344D40 00341920  90 01 00 04 */	stw r0, 4(r1)
/* 80344D44 00341924  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80344D48 00341928  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80344D4C 0034192C  93 C1 00 08 */	stw r30, 8(r1)
/* 80344D50 00341930  3C 60 80 40 */	lis r3, lbl_80401BF0@ha
/* 80344D54 00341934  3B E3 1B F0 */	addi r31, r3, lbl_80401BF0@l
/* 80344D58 00341938  4B FF 11 15 */	bl PPCMfhid0
/* 80344D5C 0034193C  54 60 04 20 */	rlwinm r0, r3, 0, 0x10, 0x10
/* 80344D60 00341940  28 00 00 00 */	cmplwi r0, 0
/* 80344D64 00341944  40 82 00 14 */	bne lbl_80344D78
/* 80344D68 00341948  4B FF FB B5 */	bl ICEnable
/* 80344D6C 0034194C  38 7F 01 AC */	addi r3, r31, 0x1ac
/* 80344D70 00341950  4C C6 31 82 */	crclr 6
/* 80344D74 00341954  4B FF 12 05 */	bl DBPrintf
lbl_80344D78:
/* 80344D78 00341958  4B FF 10 F5 */	bl PPCMfhid0
/* 80344D7C 0034195C  54 60 04 62 */	rlwinm r0, r3, 0, 0x11, 0x11
/* 80344D80 00341960  28 00 00 00 */	cmplwi r0, 0
/* 80344D84 00341964  40 82 00 14 */	bne lbl_80344D98
/* 80344D88 00341968  4B FF FA 41 */	bl DCEnable
/* 80344D8C 0034196C  38 7F 01 C8 */	addi r3, r31, 0x1c8
/* 80344D90 00341970  4C C6 31 82 */	crclr 6
/* 80344D94 00341974  4B FF 11 E5 */	bl DBPrintf
lbl_80344D98:
/* 80344D98 00341978  4B FF 10 DD */	bl PPCMfl2cr
/* 80344D9C 0034197C  54 60 00 00 */	rlwinm r0, r3, 0, 0, 0
/* 80344DA0 00341980  28 00 00 00 */	cmplwi r0, 0
/* 80344DA4 00341984  40 82 00 58 */	bne lbl_80344DFC
/* 80344DA8 00341988  4B FF 10 B5 */	bl PPCMfmsr
/* 80344DAC 0034198C  7C 7E 1B 78 */	mr r30, r3
/* 80344DB0 00341990  7C 00 04 AC */	sync
/* 80344DB4 00341994  38 60 00 30 */	li r3, 0x30
/* 80344DB8 00341998  4B FF 10 AD */	bl PPCMtmsr
/* 80344DBC 0034199C  7C 00 04 AC */	sync
/* 80344DC0 003419A0  7C 00 04 AC */	sync
/* 80344DC4 003419A4  4B FF 10 B1 */	bl PPCMfl2cr
/* 80344DC8 003419A8  54 63 00 7E */	clrlwi r3, r3, 1
/* 80344DCC 003419AC  4B FF 10 B1 */	bl PPCMtl2cr
/* 80344DD0 003419B0  7C 00 04 AC */	sync
/* 80344DD4 003419B4  4B FF FD 71 */	bl L2GlobalInvalidate
/* 80344DD8 003419B8  7F C3 F3 78 */	mr r3, r30
/* 80344DDC 003419BC  4B FF 10 89 */	bl PPCMtmsr
/* 80344DE0 003419C0  4B FF 10 95 */	bl PPCMfl2cr
/* 80344DE4 003419C4  64 60 80 00 */	oris r0, r3, 0x8000
/* 80344DE8 003419C8  54 03 02 D2 */	rlwinm r3, r0, 0, 0xb, 9
/* 80344DEC 003419CC  4B FF 10 91 */	bl PPCMtl2cr
/* 80344DF0 003419D0  38 7F 01 E4 */	addi r3, r31, 0x1e4
/* 80344DF4 003419D4  4C C6 31 82 */	crclr 6
/* 80344DF8 003419D8  4B FF 11 81 */	bl DBPrintf
lbl_80344DFC:
/* 80344DFC 003419DC  3C 60 80 34 */	lis r3, DMAErrorHandler@ha
/* 80344E00 003419E0  38 83 4B DC */	addi r4, r3, DMAErrorHandler@l
/* 80344E04 003419E4  38 60 00 01 */	li r3, 1
/* 80344E08 003419E8  48 00 0A 4D */	bl OSSetErrorHandler
/* 80344E0C 003419EC  38 7F 01 FC */	addi r3, r31, 0x1fc
/* 80344E10 003419F0  4C C6 31 82 */	crclr 6
/* 80344E14 003419F4  4B FF 11 65 */	bl DBPrintf
/* 80344E18 003419F8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80344E1C 003419FC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80344E20 00341A00  83 C1 00 08 */	lwz r30, 8(r1)
/* 80344E24 00341A04  7C 08 03 A6 */	mtlr r0
/* 80344E28 00341A08  38 21 00 10 */	addi r1, r1, 0x10
/* 80344E2C 00341A0C  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop
