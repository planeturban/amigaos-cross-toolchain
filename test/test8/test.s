#NO_APP
	.text
	.align	2
	.globl	___powisf2
___powisf2:
	movem.l #15392,-(sp)
	move.l 24(sp),d3
	move.l d0,d5
	move.l d0,d2
	jlt .L14
.L2:
	btst #0,d2
	jeq .L8
	move.l d3,d4
	lea ___mulsf3,a2
.L4:
	lsr.l #1,d2
	jeq .L15
.L6:
	move.l d3,-(sp)
	move.l d3,-(sp)
	jsr (a2)
	addq.l #8,sp
	move.l d0,d3
	btst #0,d2
	jeq .L4
	move.l d0,-(sp)
	move.l d4,-(sp)
	jsr (a2)
	addq.l #8,sp
	move.l d0,d4
	lsr.l #1,d2
	jne .L6
.L15:
	tst.l d5
	jlt .L16
	move.l d4,d0
	movem.l (sp)+,#1084
	rts
.L8:
	move.l #0x3f800000,d4
	lea ___mulsf3,a2
	jra .L4
.L16:
	move.l d4,-(sp)
	move.l #0x3f800000,-(sp)
	jsr ___divsf3
	addq.l #8,sp
	move.l d0,d1
	movem.l (sp)+,#1084
	rts
.L14:
	neg.l d2
	jra .L2
