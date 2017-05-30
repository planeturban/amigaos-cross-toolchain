#NO_APP
	.text
	.align	2
	.globl	_initHash
_initHash:
	movem.l #14392,-(sp)
	clr.l -(sp)
	jsr _rkissSeed
	lea _castleKeys,a4
	move.l #_pieceKeys,d3
	move.l #_castleKeys+128,d4
	addq.l #4,sp
	lea _rand64,a3
.L4:
	jsr (a3)
	move.l d0,(a4)+
	move.l d1,(a4)+
	move.l d3,a2
	moveq #0,d2
.L3:
	moveq #119,d0
	not.b d0
	and.l d2,d0
	jeq .L9
	addq.l #1,d2
	addq.l #8,a2
	cmp.l #128,d2
	jne .L3
.L10:
	add.l #1024,d3
	cmp.l a4,d4
	jne .L4
	jsr (a3)
	move.l d0,_side
	move.l d1,_side+4
	movem.l (sp)+,#7196
	rts
.L9:
	jsr (a3)
	move.l d0,(a2)
	move.l d1,4(a2)
	addq.l #1,d2
	addq.l #8,a2
	cmp.l #128,d2
	jne .L3
	jra .L10
	.align	2
	.globl	_generatePosKey
_generatePosKey:
	movem.l #14368,-(sp)
	moveq #0,d3
	moveq #0,d2
	moveq #0,d1
	lea _board,a2
	lea _pieceKeys,a1
.L13:
	moveq #-8,d0
	and.l d1,d0
	move.l d0,a0
	add.l d1,a0
	move.b (a2,a0.l),d0
	jeq .L12
	and.l #255,d0
	lsl.l #7,d0
	add.l a0,d0
	lsl.l #3,d0
	move.l (a1,d0.l),d4
	eor.l d4,d3
	move.l 4(a1,d0.l),d0
	eor.l d0,d2
.L12:
	addq.l #1,d1
	moveq #64,d0
	cmp.l d1,d0
	jne .L13
	move.b _board+130,d0
	cmp.b #127,d0
	jeq .L14
	lea _pieceKeys,a0
	and.l #255,d0
	lsl.l #3,d0
	move.l (a0,d0.l),d1
	eor.l d1,d3
	move.l 4(a0,d0.l),d0
	eor.l d0,d2
.L14:
	lea _castleKeys,a0
	moveq #0,d1
	move.b _board+129,d1
	lsl.l #3,d1
	move.l (a0,d1.l),d0
	eor.l d3,d0
	move.l 4(a0,d1.l),d1
	eor.l d2,d1
	tst.b _board+128
	jeq .L11
	move.l _side,d2
	eor.l d2,d0
	move.l _side+4,d2
	eor.l d2,d1
.L11:
	movem.l (sp)+,#1052
	rts
.comm _side,8
.comm _castleKeys,128
.comm _pieceKeys,16384
