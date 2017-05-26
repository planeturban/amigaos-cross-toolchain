#NO_APP
	.text
	.align	2
	.globl	_conductor_init
_conductor_init:
	clr.w _conductor_scrollTarget
	move.l a0,_conductor_instructions
	clr.w _conductor_instructionIndex
	tst.w (a0)
	jeq .L1
	moveq #0,d0
	move.w 2(a0),d0
	move.w _game_cameraX,a1
	cmp.l d0,a1
	jlt .L14
.L9:
	move.l 6(a0),a1
	moveq #0,d0
	move.w 4(a0),d0
	jsr (a1)
	tst.w d0
	jeq .L1
	move.w _conductor_instructionIndex,a0
	addq.w #1,a0
	move.w a0,_conductor_instructionIndex
	moveq #0,d0
	move.w a0,d0
	move.l d0,a0
	add.l d0,a0
	add.l a0,a0
	add.l d0,a0
	add.l a0,a0
	add.l _conductor_instructions,a0
	tst.w (a0)
	jeq .L1
	moveq #0,d0
	move.w 2(a0),d0
	move.w _game_cameraX,a1
	cmp.l d0,a1
	jge .L9
.L1:
	rts
.L14:
	rts
	.align	2
	.globl	_conductor_process
_conductor_process:
	moveq #0,d0
	move.w _conductor_instructionIndex,d0
	move.l d0,a0
	add.l d0,a0
	add.l a0,a0
	add.l d0,a0
	add.l a0,a0
	add.l _conductor_instructions,a0
	tst.w (a0)
	jeq .L15
	moveq #0,d0
	move.w 2(a0),d0
	move.w _game_cameraX,a1
	cmp.l d0,a1
	jlt .L28
.L23:
	move.l 6(a0),a1
	moveq #0,d0
	move.w 4(a0),d0
	jsr (a1)
	tst.w d0
	jeq .L15
	move.w _conductor_instructionIndex,a0
	addq.w #1,a0
	move.w a0,_conductor_instructionIndex
	moveq #0,d0
	move.w a0,d0
	move.l d0,a0
	add.l d0,a0
	add.l a0,a0
	add.l d0,a0
	add.l a0,a0
	add.l _conductor_instructions,a0
	tst.w (a0)
	jeq .L15
	moveq #0,d0
	move.w 2(a0),d0
	move.w _game_cameraX,a1
	cmp.l d0,a1
	jge .L23
.L15:
	rts
.L28:
	rts
	.align	2
	.globl	_conductor_complete
_conductor_complete:
	moveq #0,d1
	move.w _conductor_instructionIndex,d1
	move.l d1,d0
	add.l d1,d0
	add.l d0,d0
	add.l d1,d0
	add.l d0,d0
	move.l _conductor_instructions,a0
	tst.w (a0,d0.l)
	seq d0
	ext.w d0
	neg.w d0
	rts
	.align	2
	.globl	_conductor_setScrollTarget
_conductor_setScrollTarget:
	move.w d0,_conductor_scrollTarget
	rts
.lcomm _conductor_instructions,4
.comm _conductor_instructionIndex,2
.comm _conductor_scrollTarget,2
