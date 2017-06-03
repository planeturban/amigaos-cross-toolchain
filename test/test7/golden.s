#NO_APP
	.text
	.align	2
	.globl	_object_collision
_object_collision:
	movem.l #16190,-(sp)
	move.l a0,a3
	move.l a1,a5
	move.w 50(sp),d4
	move.w 28(a0),a1
	move.w 26(a0),a0
	cmp.w #2,d0
	jeq .L13
.L2:
	move.l _object_activeList,a2
	clr.l 12(a5)
	clr.l 8(a5)
	clr.l 4(a5)
	clr.l (a5)
	move.w 24(a3),a4
	lea (a4,a1.w),a4
	move.l a4,d0
	jpl .L15
	addq.l #1,d0
.L15:
	asr.l #1,d0
	move.l d0,a4
	move.w d0,d5
	move.w 22(a3),a1
	lea (a1,a0.w),a0
	move.l a0,d0
	jpl .L16
	addq.l #1,d0
.L16:
	asr.l #1,d0
	move.w 90(a3),a0
	move.w a0,d6
	sub.w d1,d6
	add.w d0,d6
	move.w 92(a3),d2
	add.w d1,d2
	sub.w a0,d2
	add.w d0,d2
	clr.w d7
	cmp.w #0,a2
	jeq .L1
	lea _abs,a6
	and.l #65535,d4
.L8:
	tst.w 94(a2)
	jeq .L4
	cmp.l a3,a2
	jeq .L4
	move.w 18(a2),d3
	move.l a4,a0
	sub.w d3,a0
	move.l a0,d0
	jsr (a6)
	cmp.l d0,d4
	jlt .L4
	move.w 16(a2),d1
	move.w 90(a2),a0
	move.w d1,d0
	sub.w a0,d0
	add.w 92(a2),d0
	cmp.w d6,d0
	jle .L4
	add.w a0,d1
	cmp.w d2,d1
	jge .L4
	cmp.w d5,d3
	jlt .L5
	move.l a2,(a5)
	cmp.w d6,d1
	jlt .L7
.L14:
	move.l a2,12(a5)
	moveq #1,d7
.L4:
	move.l 8(a2),a2
	cmp.w #0,a2
	jne .L8
.L1:
	move.w d7,d0
	movem.l (sp)+,#31996
	rts
.L13:
	add.w a0,a0
	add.w a1,a1
	jra .L2
.L5:
	move.l a2,4(a5)
	cmp.w d6,d1
	jge .L14
.L7:
	move.l a2,8(a5)
	moveq #1,d7
	move.l 8(a2),a2
	cmp.w #0,a2
	jne .L8
	jra .L1
	.align	2
	.globl	_enemy_closestPlayer
_enemy_closestPlayer:
	movem.l #12336,-(sp)
	move.l a0,a2
	move.l _game_player2,d0
	jeq .L29
	move.l _game_player1,a1
	cmp.w #0,a1
	jeq .L17
	move.l d0,a0
	cmp.w #1,76(a1)
	jeq .L34
	cmp.w #1,76(a0)
	jeq .L35
	move.w 16(a2),a0
	lea _abs,a3
	sub.w 16(a1),a0
	move.l a0,d0
	jsr (a3)
	move.l d0,d3
	move.w 18(a2),a1
	move.l _game_player1,a0
	sub.w 18(a0),a1
	move.l a1,d0
	jsr (a3)
	add.l d0,d3
	move.w 16(a2),a1
	move.l _game_player2,a0
	sub.w 16(a0),a1
	move.l a1,d0
	jsr (a3)
	move.l d0,d2
	move.w 18(a2),a1
	move.l _game_player2,a0
	sub.w 18(a0),a1
	move.l a1,d0
	jsr (a3)
	add.l d2,d0
	cmp.l d3,d0
	jgt .L29
	move.l _game_player2,d0
.L17:
	movem.l (sp)+,#3084
	rts
.L29:
	move.l _game_player1,d0
	movem.l (sp)+,#3084
	rts
.L34:
	cmp.w #1,76(a0)
	jne .L17
	moveq #0,d0
	movem.l (sp)+,#3084
	rts
.L35:
	move.l a1,d0
	movem.l (sp)+,#3084
	rts
	.align	2
	.globl	_level1_doorIntelligence
_level1_doorIntelligence:
	lea (-16,sp),sp
	movem.l #15420,-(sp)
	move.l d0,d3
	move.l a0,a2
	move.l a1,a3
	move.w 18(a0),d0
	cmp.w #63,d0
	jeq .L78
	cmp.w #65,d0
	jle .L38
	move.w 76(a0),d2
	jne .L62
	move.w 24(a1),d0
	jle .L41
	sub.w d3,d0
	move.w d0,24(a1)
.L36:
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L62:
	clr.w d1
	move.w d1,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L78:
	cmp.w #1456,16(a0)
	jgt .L79
.L38:
	clr.w 26(a2)
	move.w #1,28(a2)
	clr.w d1
	move.w d1,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L79:
	move.w #-1,26(a0)
	clr.w d1
	move.w d1,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L41:
	move.l _game_player2,a4
	cmp.w #0,a4
	jeq .L74
	move.l _game_player1,a0
	cmp.w #0,a0
	jeq .L43
	cmp.w #1,76(a0)
	jeq .L80
	cmp.w #1,76(a4)
	jeq .L81
	move.w 16(a2),a1
	lea _abs,a4
	sub.w 16(a0),a1
	move.l a1,d0
	jsr (a4)
	move.l d0,d5
	move.w 18(a2),a1
	move.l _game_player1,a0
	sub.w 18(a0),a1
	move.l a1,d0
	jsr (a4)
	add.l d0,d5
	move.w 16(a2),a1
	move.l _game_player2,a0
	sub.w 16(a0),a1
	move.l a1,d0
	jsr (a4)
	move.l d0,d4
	move.w 18(a2),a1
	move.l _game_player2,a0
	sub.w 18(a0),a1
	move.l a1,d0
	jsr (a4)
	add.l d4,d0
	cmp.l d5,d0
	jgt .L74
	move.l _game_player2,a4
	cmp.w #0,a4
	jeq .L45
.L43:
	move.w 16(a2),a0
	sub.w _game_cameraX,a0
	cmp.w #0,a0
	jle .L82
.L48:
	cmp.w #319,a0
	jle .L50
	move.w #50,24(a3)
	move.w #-1,26(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L82:
	move.w #50,24(a3)
	move.w #1,26(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L80:
	cmp.w #1,76(a4)
	jne .L43
.L45:
	clr.w 26(a2)
	clr.w 28(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L74:
	move.l _game_player1,a4
	cmp.w #0,a4
	jne .L43
	jra .L45
.L50:
	pea 1.w
	moveq #1,d1
	lea (36,sp),a1
	move.l a2,a0
	move.w d3,d0
	ext.l d0
	jsr _object_collision
	move.w d0,d4
	addq.l #4,sp
	jeq .L51
	tst.l 40(sp)
	jeq .L52
	move.w #1,26(a2)
	clr.w 28(a2)
	move.w #50,24(a3)
.L84:
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L81:
	move.l a0,a4
	move.w 16(a2),a0
	sub.w _game_cameraX,a0
	cmp.w #0,a0
	jgt .L48
	jra .L82
.L51:
	move.l 38(a4),a0
	move.w 4(a0),a1
	move.w a1,d0
	asr.w #2,d0
	move.w d0,a1
	add.w 16(a4),a1
	move.w a1,a1
	move.l 38(a2),a0
	move.w 4(a0),d0
	asr.w #2,d0
	add.w 16(a2),d0
	lea _abs,a5
	sub.w d0,a1
	move.l a1,d0
	jsr (a5)
	moveq #31,d1
	cmp.l d0,d1
	jge .L56
	move.w 16(a2),d0
	cmp.w 16(a4),d0
	sge d0
	ext.w d0
	or.w #1,d0
.L56:
	move.w d0,26(a2)
	move.w 18(a2),a0
	sub.w 18(a4),a0
	move.l a0,d0
	jsr (a5)
	move.w 14(a3),a0
	cmp.l d0,a0
	jlt .L57
	tst.w 26(a2)
	jne .L58
	move.w 40(a3),d0
	jle .L83
	sub.w d3,d0
	move.w d0,40(a3)
.L58:
	clr.w 28(a2)
.L85:
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L57:
	move.w 18(a2),d1
	move.w 18(a4),d0
	cmp.w d1,d0
	jle .L60
	move.w 48(a3),28(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L52:
	tst.l 44(sp)
	jeq .L54
	move.w #-1,26(a2)
	clr.w 28(a2)
	move.w #50,24(a3)
	jra .L84
.L60:
	cmp.w d1,d0
	jge .L36
	move.w 48(a3),d0
	neg.w d0
	move.w d0,28(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L83:
	move.w 42(a3),40(a3)
	moveq #1,d2
	clr.w 28(a2)
	jra .L85
.L54:
	tst.l 32(sp)
	jeq .L55
	clr.w 26(a2)
	move.w #1,28(a2)
	move.w #50,24(a3)
	jra .L84
.L55:
	clr.w 26(a2)
	move.w #-1,28(a2)
	move.w #50,24(a3)
	jra .L84
	.align	2
	.globl	_enemy_intelligence
_enemy_intelligence:
	lea (-16,sp),sp
	movem.l #15420,-(sp)
	move.l d0,d3
	move.l a0,a2
	move.l a1,a3
	move.w 76(a0),d2
	jne .L109
	move.w 24(a1),d0
	jle .L88
	sub.w d3,d0
	move.w d0,24(a1)
.L86:
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L109:
	clr.w d1
	move.w d1,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L88:
	move.l _game_player2,a4
	cmp.w #0,a4
	jeq .L121
	move.l _game_player1,a0
	cmp.w #0,a0
	jeq .L90
	cmp.w #1,76(a0)
	jeq .L125
	cmp.w #1,76(a4)
	jeq .L126
	move.w 16(a2),a1
	lea _abs,a4
	sub.w 16(a0),a1
	move.l a1,d0
	jsr (a4)
	move.l d0,d5
	move.w 18(a2),a1
	move.l _game_player1,a0
	sub.w 18(a0),a1
	move.l a1,d0
	jsr (a4)
	add.l d0,d5
	move.w 16(a2),a1
	move.l _game_player2,a0
	sub.w 16(a0),a1
	move.l a1,d0
	jsr (a4)
	move.l d0,d4
	move.w 18(a2),a1
	move.l _game_player2,a0
	sub.w 18(a0),a1
	move.l a1,d0
	jsr (a4)
	add.l d4,d0
	cmp.l d5,d0
	jgt .L121
	move.l _game_player2,a4
	cmp.w #0,a4
	jeq .L92
.L90:
	move.w 16(a2),a0
	sub.w _game_cameraX,a0
	cmp.w #0,a0
	jle .L127
	cmp.w #319,a0
	jle .L97
	move.w #50,24(a3)
	move.w #-1,26(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L121:
	move.l _game_player1,a4
	cmp.w #0,a4
	jne .L90
	jra .L92
.L125:
	cmp.w #1,76(a4)
	jne .L90
.L92:
	clr.w 26(a2)
	clr.w 28(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L127:
	move.w #50,24(a3)
	move.w #1,26(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L97:
	pea 1.w
	moveq #1,d1
	lea (36,sp),a1
	move.l a2,a0
	move.w d3,d0
	ext.l d0
	jsr _object_collision
	move.w d0,d4
	addq.l #4,sp
	jeq .L98
	tst.l 40(sp)
	jeq .L99
	move.w #1,26(a2)
	clr.w 28(a2)
	move.w #50,24(a3)
.L129:
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L126:
	move.l a0,a4
	jra .L90
.L98:
	move.l 38(a4),a0
	move.w 4(a0),a1
	move.w a1,d0
	asr.w #2,d0
	move.w d0,a1
	add.w 16(a4),a1
	move.w a1,a1
	move.l 38(a2),a0
	move.w 4(a0),d0
	asr.w #2,d0
	add.w 16(a2),d0
	lea _abs,a5
	sub.w d0,a1
	move.l a1,d0
	jsr (a5)
	moveq #31,d1
	cmp.l d0,d1
	jge .L103
	move.w 16(a2),d0
	cmp.w 16(a4),d0
	sge d0
	ext.w d0
	or.w #1,d0
.L103:
	move.w d0,26(a2)
	move.w 18(a2),a0
	sub.w 18(a4),a0
	move.l a0,d0
	jsr (a5)
	move.w 14(a3),a0
	cmp.l d0,a0
	jlt .L104
	tst.w 26(a2)
	jne .L105
	move.w 40(a3),d0
	jle .L128
	sub.w d3,d0
	move.w d0,40(a3)
.L105:
	clr.w 28(a2)
.L130:
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L104:
	move.w 18(a2),d1
	move.w 18(a4),d0
	cmp.w d1,d0
	jle .L107
	move.w 48(a3),28(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L99:
	tst.l 44(sp)
	jeq .L101
	move.w #-1,26(a2)
	clr.w 28(a2)
	move.w #50,24(a3)
	jra .L129
.L107:
	cmp.w d1,d0
	jge .L86
	move.w 48(a3),d0
	neg.w d0
	move.w d0,28(a2)
	move.w d2,d0
	movem.l (sp)+,#15420
	lea (16,sp),sp
	rts
.L128:
	move.w 42(a3),40(a3)
	moveq #1,d2
	clr.w 28(a2)
	jra .L130
.L101:
	tst.l 32(sp)
	jeq .L102
	clr.w 26(a2)
	move.w #1,28(a2)
	move.w #50,24(a3)
	jra .L129
.L102:
	clr.w 26(a2)
	move.w #-1,28(a2)
	move.w #50,24(a3)
	jra .L129
