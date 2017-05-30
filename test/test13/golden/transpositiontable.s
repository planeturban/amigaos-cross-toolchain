#NO_APP
	.text
	.align	2
	.globl	_TT_free
_TT_free:
	move.l _board+32336,d0
	jeq .L1
	move.l d0,-(sp)
	jsr _free
	addq.l #4,sp
.L1:
	rts
.LC0:
	.ascii "Hash table memory allocation problem.  Exiting...\12\0"
.LC1:
	.ascii "Transposition Table: %lld entries allocated...%lld bytes.\12\0"
	.align	2
	.globl	_TT_set_size
_TT_set_size:
	movem.l #16128,-(sp)
	move.l 28(sp),d0
	lsl.w #4,d0
	swap d0
	clr.w d0
	move.l d0,d7
	moveq #0,d6
	cmp.l #32767,d0
	jls .L19
	clr.l d0
	move.l #1024,d1
.L10:
	add.l d1,d1
	addx.l d0,d0
	move.l d1,d3
	moveq #27,d2
	lsr.l d2,d3
	move.l d0,d2
	lsl.l #5,d2
	or.l d3,d2
	move.l d1,d3
	lsl.l #5,d3
	move.l d2,d4
	move.l d3,d5
	sub.l d7,d5
	subx.l d6,d4
	jls .L10
	move.l d1,d5
	lsl.l #4,d5
	moveq #-1,d2
	moveq #-1,d3
	add.l d1,d3
	addx.l d0,d2
	move.l d3,d4
	lsl.l #4,d4
.L9:
	move.l _board+32336,d0
	jeq .L11
	move.l d0,-(sp)
	jsr _free
	addq.l #4,sp
.L11:
	move.l d5,-(sp)
	jsr _malloc
	move.l d0,_board+32336
	move.l d2,_board+32340
	move.l d3,_board+32344
	addq.l #4,sp
	tst.l d0
	jeq .L27
	move.l d3,d1
	moveq #28,d0
	lsr.l d0,d1
	move.l d2,d0
	lsl.l #4,d0
	or.l d1,d0
	move.l d3,d1
	lsl.l #4,d1
	move.l d1,-(sp)
	move.l d0,-(sp)
	move.l d3,-(sp)
	move.l d2,-(sp)
	pea .LC1
	jsr _printf
	lea (20,sp),sp
.L13:
	tst.l d4
	jeq .L8
	move.l _board+32336,a0
	moveq #64,d0
	cmp.l d4,d0
	jcs .L28
	move.l a0,d0
	add.l d4,d0
.L17:
	clr.b (a0)+
	cmp.l a0,d0
	jne .L17
.L8:
	movem.l (sp)+,#252
	rts
.L28:
	move.l d4,-(sp)
	clr.l -(sp)
	move.l a0,-(sp)
	jsr ___memset64
	lea (12,sp),sp
	movem.l (sp)+,#252
	rts
.L27:
	pea .LC0
	jsr _printf
	pea 1.w
	jsr _exit
	addq.l #8,sp
	jra .L13
.L19:
	move.l #16368,d4
	clr.l d2
	move.l #1023,d3
	move.l #16384,d5
	jra .L9
	.align	2
	.globl	_TT_clear
_TT_clear:
	move.l _board+32336,a0
	cmp.w #0,a0
	jeq .L29
	move.l _board+32344,d0
	lsl.l #4,d0
	jeq .L29
	moveq #64,d1
	cmp.l d0,d1
	jcs .L41
	add.l a0,d0
.L34:
	clr.b (a0)+
	cmp.l a0,d0
	jne .L34
.L29:
	rts
.L41:
	move.l d0,-(sp)
	clr.l -(sp)
	move.l a0,-(sp)
	jsr ___memset64
	lea (12,sp),sp
	rts
	.align	2
	.globl	_TT_RecordHash
_TT_RecordHash:
	movem.l #12320,-(sp)
	move.l 20(sp),a1
	lea _board,a2
	move.l 134(a2),d2
	move.l 138(a2),d3
	move.l 32344(a2),d0
	and.l d3,d0
	lsl.l #4,d0
	move.l 32336(a2),a0
	add.l d0,a0
	move.l (a0),d0
	move.l 4(a0),d1
	sub.l d3,d1
	subx.l d2,d0
	jeq .L49
	cmp.w #30800,a1
	jgt .L50
.L45:
	cmp.w #-30800,a1
	jge .L46
	sub.w _board+132,a1
.L46:
	move.l d2,(a0)
	move.l d3,4(a0)
	move.l 28(sp),12(a0)
	move.w a1,10(a0)
	move.b 27(sp),9(a0)
	move.b 19(sp),8(a0)
.L42:
	movem.l (sp)+,#1036
	rts
.L50:
	move.w _board+132,a2
	add.l a2,a1
	move.l d2,(a0)
	move.l d3,4(a0)
	move.l 28(sp),12(a0)
	move.w a1,10(a0)
	move.b 27(sp),9(a0)
	move.b 19(sp),8(a0)
	jra .L42
.L49:
	moveq #0,d0
	move.b 8(a0),d0
	cmp.l 16(sp),d0
	jgt .L42
	cmp.w #30800,a1
	jle .L45
	jra .L50
	.align	2
	.globl	_TT_probe
_TT_probe:
	movem.l #12336,-(sp)
	lea _board,a3
	move.l 134(a3),d2
	move.l 138(a3),d3
	move.l 32344(a3),d0
	and.l d3,d0
	lsl.l #4,d0
	move.l 32336(a3),a0
	add.l d0,a0
	move.l (a0),d0
	move.l 4(a0),d1
	sub.l d3,d1
	subx.l d2,d0
	jne .L54
	move.l 20(sp),a1
	move.l 12(a0),(a1)
	moveq #0,d0
	move.b 8(a0),d0
	cmp.l 28(sp),d0
	jlt .L54
	move.b 9(a0),d0
	cmp.b #1,d0
	jeq .L60
	cmp.b #2,d0
	jeq .L61
	cmp.b #3,d0
	jne .L54
	move.w 10(a0),a1
	cmp.l 36(sp),a1
	jlt .L54
	move.l 24(sp),a2
	move.l 36(sp),(a2)
.L51:
	move.l a0,d0
	movem.l (sp)+,#3084
	rts
.L54:
	sub.l a0,a0
	move.l a0,d0
	movem.l (sp)+,#3084
	rts
.L61:
	move.w 10(a0),a1
	cmp.l 32(sp),a1
	jgt .L54
	move.l 24(sp),a1
	move.l 32(sp),(a1)
	move.l a0,d0
	movem.l (sp)+,#3084
	rts
.L60:
	move.w 10(a0),a1
	move.l 24(sp),a2
	move.l a1,(a2)
	cmp.w #30800,a1
	jgt .L62
	cmp.w #-30800,a1
	jge .L51
	move.l a2,a3
	move.w _board+132,a2
	add.l a1,a2
	move.l a2,(a3)
	move.l a0,d0
	movem.l (sp)+,#3084
	rts
.L62:
	sub.w _board+132,a1
	move.l a1,(a2)
	move.l a0,d0
	movem.l (sp)+,#3084
	rts
.LC2:
	.ascii " <--- move not legal\12\0"
.LC3:
	.ascii "No moves from hash table probing!!!\12\0"
	.align	2
	.globl	_TT_fillPVLineFromTT
_TT_fillPVLineFromTT:
	lea (-2412,sp),sp
	movem.l #15422,-(sp)
	move.l 2452(sp),d3
	move.l 2456(sp),a3
	jle .L65
	lea _board,a1
	move.l 134(a1),d4
	move.l 138(a1),d5
	move.l 32344(a1),d0
	and.l d5,d0
	lsl.l #4,d0
	move.l 32336(a1),a0
	add.l d0,a0
	move.l (a0),d0
	move.l 4(a0),d1
	sub.l d5,d1
	subx.l d4,d0
	jne .L65
	lea (48,sp),a2
	move.l a2,a4
	moveq #0,d2
	lea _moveExists,a5
	lea _move_make,a6
.L70:
	move.l 12(a0),d4
	jeq .L67
	move.l d4,-(sp)
	jsr (a5)
	addq.l #4,sp
	tst.l d0
	jeq .L68
	move.l d4,(a4)
	move.l a4,-(sp)
	jsr (a6)
	addq.l #1,d2
	addq.l #4,sp
	cmp.l d3,d2
	jeq .L66
	lea _board,a1
	move.l 134(a1),d4
	move.l 138(a1),d5
	move.l 32344(a1),d0
	and.l d5,d0
	lsl.l #4,d0
	move.l 32336(a1),a0
	add.l d0,a0
	lea (12,a4),a4
	move.l (a0),d0
	move.l 4(a0),d1
	sub.l d5,d1
	subx.l d4,d0
	jeq .L70
.L66:
	move.l d2,d3
	subq.l #1,d3
	jmi .L75
	move.l d3,a4
	add.l d3,a4
	add.l d3,a4
	add.l a4,a4
	add.l a4,a4
	moveq #48,d0
	add.l sp,d0
	add.l d0,a4
	lea _move_unmake,a5
.L74:
	move.l a4,-(sp)
	jsr (a5)
	lea (-12,a4),a4
	addq.l #4,sp
	dbra d3,.L74
	clr.w d3
	subq.l #1,d3
	jcc .L74
.L75:
	tst.l d2
	jle .L73
	lea (4,a3),a0
	move.l d2,d0
	addq.l #1,d0
	add.l d0,d0
	add.l d0,d0
	add.l a3,d0
.L77:
	move.l (a2),(a0)+
	lea (12,a2),a2
	cmp.l a0,d0
	jne .L77
.L73:
	move.l d2,(a3)
	movem.l (sp)+,#31804
	lea (2412,sp),sp
	rts
.L68:
	move.l d4,36(sp)
	jsr _printBoard
	lea (48,sp),a0
	move.l -(a0),-(sp)
	move.l -(a0),-(sp)
	move.l -4(a0),-(sp)
	jsr _printMove
	pea .LC2
	jsr _printf
	lea (16,sp),sp
.L67:
	tst.l d2
	jne .L66
.L65:
	pea .LC3
	jsr _printf
	addq.l #4,sp
	movem.l (sp)+,#31804
	lea (2412,sp),sp
	rts
