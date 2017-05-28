#NO_APP
	.text
.LC0:
	.ascii "%llx\12\0"
	.text
	.align	2
	.globl	_main
_main:
	link.w a5,#0
	move.l #-559030611,-(sp)
	move.l #-559030611,-(sp)
	pea .LC0
	jsr _printf
	moveq #0,d0
	unlk a5
	rts
