#NO_APP
	.text
	.align	2
	.globl	_strcpy
_strcpy:
	move.l a2,-(sp)
	move.l a0,d0
	move.l a0,a2
.L2:
	move.b (a1)+,d1
	move.b d1,(a2)+
	jne .L2
	move.l (sp)+,a2
	rts
.LC0:
	.ascii "A NEW HIGH SCORE!!!\0"
.LC1:
	.ascii "YOU ARE ON THE SCORE BOARD!\0"
	.align	2
	.globl	_hiscore_addScore
_hiscore_addScore:
	move.l a2,-(sp)
	move.l d2,-(sp)
	lea _hiscore+72,a2
	moveq #9,d2
	cmp.l (a2),d0
	jcs .L7
.L26:
	tst.l d2
	jeq .L8
	lea (4,a2),a1
	lea (-4,a2),a0
.L9:
	move.b (a0)+,d1
	move.b d1,(a1)+
	jne .L9
	subq.l #1,d2
	subq.l #8,a2
	cmp.l (a2),d0
	jcc .L26
.L7:
	cmp.w #9,d2
	jne .L27
.L6:
	move.l (sp)+,d2
	move.l (sp)+,a2
	rts
.L27:
	lea .LC1,a0
	jsr _hiscore_prompt
	lsl.l #3,d2
	move.l d2,a0
	add.l #_hiscore+12,a0
	move.l d0,a1
.L13:
	move.b (a1)+,d1
	move.b d1,(a0)+
	jeq .L6
	move.b (a1)+,d1
	move.b d1,(a0)+
	jne .L13
	jra .L6
.L8:
	lea .LC0,a0
	jsr _hiscore_prompt
	lea _hiscore+4,a0
.L11:
	move.l d0,a1
	move.b (a1)+,d1
	move.l a1,d0
	move.b d1,(a0)+
	jne .L11
	move.l (sp)+,d2
	move.l (sp)+,a2
	rts
.lcomm _hiscore,80
.comm _game_over,4
.comm _game_collisions,4
