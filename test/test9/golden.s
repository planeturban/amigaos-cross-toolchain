#NO_APP
	.text
	.align	2
	.globl	_sort5
_sort5:
	movem.l #14398,-(sp)
	move.l (a0),a5
	move.w 20(a5),d3
	move.l 4(a0),a3
	move.w 20(a3),d1
	cmp.w d3,d1
	jle .L2
	move.w d3,d0
	move.w d1,d3
	move.w d0,d1
	move.l a5,d0
	move.l a3,a5
	move.l d0,a3
.L2:
	move.l 12(a0),a2
	move.w 20(a2),a1
	move.l 16(a0),a6
	move.w 20(a6),d2
	cmp.w a1,d2
	jgt .L3
	move.w d2,d0
	move.w a1,d2
	move.w d0,a1
	move.l a6,d0
	move.l a2,a6
	move.l d0,a2
.L3:
	move.l 8(a0),a4
	move.w 20(a4),d0
	cmp.w d0,d2
	jgt .L4
	move.w d0,d4
	move.w d2,d0
	move.w d4,d2
	move.l a6,d4
	move.l a4,a6
	move.l d4,a4
.L4:
	cmp.w a1,d0
	jge .L5
	move.w d0,d4
	move.w a1,d0
	move.w d4,a1
	move.l a4,d4
	move.l a2,a4
	move.l d4,a2
.L5:
	cmp.w d3,d2
	jgt .L6
	move.w d2,d3
	move.l a6,d2
	move.l a5,a6
	move.l d2,a5
.L6:
	move.l a6,16(a0)
	cmp.w d1,d0
	jle .L7
	move.w d0,d2
	move.w d1,d0
	move.w d2,d1
	move.l a3,d2
	move.l a4,a3
	move.l d2,a4
.L7:
	cmp.w a1,d0
	jlt .L8
	move.w d0,a1
	move.l a2,d0
	move.l a4,a2
	move.l d0,a4
.L8:
	move.l a4,(a0)
	cmp.w d3,d1
	jle .L9
	move.w d3,d1
	move.l a5,d0
	move.l a3,a5
	move.l d0,a3
.L9:
	move.l a5,12(a0)
	cmp.w a1,d1
	jlt .L10
	move.l a2,d0
	move.l a3,a2
	move.l d0,a3
.L10:
	move.l a3,4(a0)
	move.l a2,8(a0)
	movem.l (sp)+,#31772
	rts
