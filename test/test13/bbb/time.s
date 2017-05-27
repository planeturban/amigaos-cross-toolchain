#NO_APP
	.text
	.align	2
	.globl	_get_ms
_get_ms:
	lea (-12,sp),sp
	move.l a6,-(sp)
	move.l _DOSBase,a6
	move.l sp,d1
	addq.l #4,d1
#APP
| 44 "src/time.c" 1
	jsr a6@(-0xc0:W)
#NO_APP
	move.l 8(sp),d0
	move.l d0,d1
	lsl.l #5,d1
	sub.l d0,d1
	add.l d1,d1
	add.l d1,d1
	add.l d0,d1
	move.l d1,d0
	lsl.l #4,d0
	sub.l d1,d0
	lsl.l #5,d0
	move.l 12(sp),a0
	move.l a0,d1
	add.l a0,d1
	add.l d1,d1
	add.l a0,d1
	add.l d1,d1
	add.l d1,d1
	add.l d1,d0
	move.l (sp)+,a6
	lea (12,sp),sp
	rts
	.align	2
	.globl	_InputWaiting
_InputWaiting:
	moveq #0,d0
	rts
	.align	2
	.globl	_ReadInput
_ReadInput:
	rts
