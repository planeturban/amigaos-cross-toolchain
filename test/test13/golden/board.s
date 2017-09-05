#NO_APP
	.text
	.align	2
	.globl	_diagAttack
_diagAttack:
	move.l d2,-(sp)
	move.l 16(sp),a0
	move.l 12(sp),d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L7
	lea _board,a1
	move.b (a1,d1.l),d2
	jne .L3
.L5:
	add.l a0,d1
	moveq #119,d2
	not.b d2
	and.l d1,d2
	jne .L1
	move.b (a1,d1.l),d2
	jeq .L5
.L3:
	moveq #8,d1
	and.l d2,d1
	cmp.l 8(sp),d1
	jeq .L12
.L1:
	move.l (sp)+,d2
	rts
.L12:
	and.b #5,d2
	cmp.b #5,d2
	seq d0
	ext.w d0
	ext.l d0
	neg.l d0
	move.l (sp)+,d2
	rts
.L7:
	moveq #0,d0
	move.l (sp)+,d2
	rts
	.align	2
	.globl	_straightAttack
_straightAttack:
	move.l d2,-(sp)
	move.l 16(sp),a0
	move.l 12(sp),d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L19
	lea _board,a1
	move.b (a1,d1.l),d2
	jne .L15
.L17:
	add.l a0,d1
	moveq #119,d2
	not.b d2
	and.l d1,d2
	jne .L13
	move.b (a1,d1.l),d2
	jeq .L17
.L15:
	moveq #8,d1
	and.l d2,d1
	cmp.l 8(sp),d1
	jeq .L24
.L13:
	move.l (sp)+,d2
	rts
.L24:
	moveq #7,d0
	and.l d0,d2
	subq.l #6,d2
	moveq #1,d0
	cmp.l d2,d0
	scc d0
	ext.w d0
	ext.l d0
	neg.l d0
	move.l (sp)+,d2
	rts
.L19:
	moveq #0,d0
	move.l (sp)+,d2
	rts
	.align	2
	.globl	_isAttacked
_isAttacked:
	subq.l #4,sp
	movem.l #16190,-(sp)
	move.l 52(sp),a5
	move.l 56(sp),a0
	cmp.w #0,a5
	jne .L26
	moveq #-15,d4
	add.l a0,d4
	moveq #119,d0
	not.b d0
	and.l d4,d0
	jeq .L168
	moveq #-17,d6
	add.l a0,d6
	moveq #119,d1
	not.b d1
	and.l d6,d1
	jne .L29
.L174:
	lea _board,a1
	cmp.b #1,(a1,d6.l)
	jeq .L140
	moveq #-33,d2
	add.l a0,d2
	moveq #119,d3
	not.b d3
	and.l d2,d3
	jne .L97
.L96:
	cmp.b #3,(a1,d2.l)
	jeq .L140
	tst.l d1
	jne .L31
.L97:
	cmp.b #2,(a1,d6.l)
	jeq .L140
.L31:
	moveq #-31,d1
	add.l a0,d1
	moveq #119,d2
	not.b d2
	and.l d1,d2
	jne .L32
.L175:
	lea _board,a1
	cmp.b #3,(a1,d1.l)
	jeq .L140
.L32:
	moveq #-16,d3
	add.l a0,d3
	moveq #119,d1
	not.b d1
	and.l d3,d1
	jne .L33
	lea _board,a1
	cmp.b #2,(a1,d3.l)
	jeq .L140
.L33:
	moveq #-18,d1
	add.l a0,d1
	moveq #119,d2
	not.b d2
	and.l d1,d2
	jne .L34
	lea _board,a1
	cmp.b #3,(a1,d1.l)
	jeq .L140
.L34:
	tst.l d0
	jne .L35
	lea _board,a1
	cmp.b #2,(a1,d4.l)
	jeq .L140
.L35:
	moveq #-14,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L36
	lea _board,a1
	cmp.b #3,(a1,d0.l)
	jeq .L140
.L36:
	lea (1,a0),a2
	moveq #119,d1
	not.b d1
	move.l a2,d0
	and.l d0,d1
	jne .L37
	lea _board,a1
	cmp.b #2,(a1,a2.l)
	jeq .L140
.L37:
	moveq #14,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L38
	lea _board,a1
	cmp.b #3,(a1,d0.l)
	jeq .L140
.L38:
	lea (-1,a0),a6
	moveq #119,d0
	not.b d0
	move.l a6,d1
	and.l d1,d0
	jne .L39
	lea _board,a1
	cmp.b #2,(a1,a6.l)
	jeq .L140
.L39:
	moveq #18,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L40
	lea _board,a1
	cmp.b #3,(a1,d0.l)
	jeq .L140
.L40:
	moveq #15,d7
	add.l a0,d7
	moveq #119,d0
	not.b d0
	and.l d7,d0
	jne .L41
	lea _board,a1
	cmp.b #2,(a1,d7.l)
	jeq .L140
.L41:
	moveq #31,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L42
	lea _board,a1
	cmp.b #3,(a1,d0.l)
	jeq .L140
.L42:
	moveq #16,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L43
	lea _board,a1
	cmp.b #2,(a1,d1.l)
	jeq .L140
.L43:
	lea (33,a0),a1
	move.l a1,d2
	moveq #119,d0
	not.b d0
	and.l d0,d2
	jne .L44
	lea _board,a3
	cmp.b #3,(a3,a1.l)
	jeq .L140
.L44:
	moveq #17,d5
	add.l a0,d5
	moveq #119,d0
	not.b d0
	and.l d5,d0
	jeq .L169
.L45:
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L63
	lea _board,a1
	move.b (a1,d1.l),d1
	jne .L64
	moveq #32,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L63
	move.b (a1,d1.l),d1
	jne .L64
	moveq #48,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L63
	move.b (a1,d1.l),d1
	jne .L64
	moveq #64,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L63
	move.b (a1,d1.l),d1
	jne .L64
	moveq #80,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L63
	move.b (a1,d1.l),d1
	jne .L64
	moveq #96,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L63
	move.b (a1,d1.l),d1
	jne .L64
	moveq #112,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L63
	move.b (a1,d1.l),d1
	jne .L64
	move.l a0,d1
	add.l #128,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L63
	move.b (a1,d1.l),d1
	jne .L64
	move.l a0,d1
	add.l #144,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L63
	move.b (a1,d1.l),d1
	jne .L64
.L63:
	moveq #119,d0
	not.b d0
	and.l d3,d0
	jne .L67
	lea _board,a1
	move.b (a1,d3.l),d1
	jne .L82
	moveq #-32,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L67
	move.b (a1,d1.l),d1
	jne .L82
	moveq #-48,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L67
	move.b (a1,d1.l),d1
	jne .L82
	moveq #-64,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L67
	move.b (a1,d1.l),d1
	jne .L82
	moveq #-80,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L67
	move.b (a1,d1.l),d1
	jne .L82
	moveq #-96,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L67
	move.b (a1,d1.l),d1
	jne .L82
	moveq #-112,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L67
	move.b (a1,d1.l),d1
	jne .L82
	moveq #-128,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L67
	move.b (a1,d1.l),d1
	jne .L82
	move.l a0,d1
	add.l #-144,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L67
	move.b (a1,d1.l),d1
	jne .L82
.L67:
	move.l a2,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L70
	lea _board,a1
	move.b (a1,a2.l),d1
	jne .L84
.L69:
	addq.l #1,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L70
	move.b (a1,d0.l),d1
	jeq .L69
.L84:
	moveq #8,d0
	and.l d1,d0
	cmp.l a5,d0
	jeq .L170
.L70:
	move.l a6,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L73
	lea _board,a1
	move.b (a1,a6.l),d0
	jne .L86
.L72:
	subq.l #1,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L73
	move.b (a1,d1.l),d0
	jeq .L72
.L86:
	moveq #8,d1
	and.l d0,d1
	cmp.l a5,d1
	jeq .L171
.L73:
	moveq #119,d0
	not.b d0
	and.l d5,d0
	jne .L75
	lea _board,a1
	move.b (a1,d5.l),d0
	jne .L88
	moveq #34,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L75
	move.b (a1,d0.l),d0
	jne .L88
	moveq #51,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L75
	move.b (a1,d0.l),d0
	jne .L88
	moveq #68,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L75
	move.b (a1,d0.l),d0
	jne .L88
	moveq #85,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L75
	move.b (a1,d0.l),d0
	jne .L88
	moveq #102,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L75
	move.b (a1,d0.l),d0
	jne .L88
	moveq #119,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L75
	move.b (a1,d0.l),d0
	jne .L88
	move.l a0,d0
	add.l #136,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L75
	move.b (a1,d0.l),d0
	jne .L88
	move.l a0,d0
	add.l #153,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L75
	move.b (a1,d0.l),d0
	jne .L88
.L75:
	moveq #119,d0
	not.b d0
	and.l d4,d0
	jne .L77
	lea _board,a1
	move.b (a1,d4.l),d0
	jne .L90
	moveq #-30,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L77
	move.b (a1,d0.l),d0
	jne .L90
	moveq #-45,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L77
	move.b (a1,d0.l),d0
	jne .L90
	moveq #-60,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L77
	move.b (a1,d0.l),d0
	jne .L90
	moveq #-75,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L77
	move.b (a1,d0.l),d0
	jne .L90
	moveq #-90,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L77
	move.b (a1,d0.l),d0
	jne .L90
	moveq #-105,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L77
	move.b (a1,d0.l),d0
	jne .L90
	moveq #-120,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L77
	move.b (a1,d0.l),d0
	jne .L90
	move.l a0,d0
	add.l #-135,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L77
	move.b (a1,d0.l),d0
	jne .L90
	move.l a0,d0
	add.l #-150,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L77
	move.b (a1,d0.l),d0
	jne .L90
.L77:
	moveq #119,d0
	not.b d0
	and.l d7,d0
	jne .L79
.L176:
	lea _board,a1
	move.b (a1,d7.l),d0
	jne .L92
	moveq #30,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L79
	move.b (a1,d0.l),d0
	jne .L92
	moveq #45,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L79
	move.b (a1,d0.l),d0
	jne .L92
	moveq #60,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L79
	move.b (a1,d0.l),d0
	jne .L92
	moveq #75,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L79
	move.b (a1,d0.l),d0
	jne .L92
	moveq #90,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L79
	move.b (a1,d0.l),d0
	jne .L92
	moveq #105,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L79
	move.b (a1,d0.l),d0
	jne .L92
	moveq #120,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L79
	move.b (a1,d0.l),d0
	jne .L92
	move.l a0,d0
	add.l #135,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L79
	move.b (a1,d0.l),d0
	jne .L92
	move.l a0,d0
	add.l #150,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L79
	move.b (a1,d0.l),d0
	jne .L92
.L79:
	moveq #119,d0
	not.b d0
	and.l d6,d0
	jne .L147
	lea _board,a1
	move.b (a1,d6.l),d1
	jne .L94
	moveq #-34,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L147
	move.b (a1,d1.l),d1
	jne .L94
	moveq #-51,d1
	add.l a0,d1
	moveq #119,d2
	not.b d2
	and.l d1,d2
	jne .L25
	move.b (a1,d1.l),d1
	jne .L94
	moveq #-68,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L147
	move.b (a1,d1.l),d1
	jne .L94
	moveq #-85,d1
	add.l a0,d1
	moveq #119,d2
	not.b d2
	and.l d1,d2
	jne .L25
	move.b (a1,d1.l),d1
	jne .L94
	moveq #-102,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L147
	move.b (a1,d1.l),d1
	jne .L94
	moveq #-119,d1
	add.l a0,d1
	moveq #119,d2
	not.b d2
	and.l d1,d2
	jne .L25
	move.b (a1,d1.l),d1
	jne .L94
	move.l a0,d1
	add.l #-136,d1
	moveq #119,d2
	not.b d2
	and.l d1,d2
	jne .L25
	move.b (a1,d1.l),d1
	jne .L94
	lea (-153,a0),a0
	move.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d1,d0
	jne .L147
	move.b (a1,a0.l),d1
	jne .L94
.L25:
	movem.l (sp)+,#31996
	addq.l #4,sp
	rts
.L26:
	moveq #17,d5
	add.l a0,d5
	moveq #119,d0
	not.b d0
	and.l d5,d0
	move.l d0,a1
	jeq .L172
.L46:
	moveq #15,d7
	add.l a0,d7
	moveq #119,d0
	not.b d0
	and.l d7,d0
	move.l d0,44(sp)
	jne .L47
	lea _board,a2
	cmp.b #9,(a2,d7.l)
	jeq .L140
.L47:
	moveq #-33,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L48
	lea _board,a2
	cmp.b #11,(a2,d0.l)
	jeq .L140
.L48:
	moveq #-17,d6
	add.l a0,d6
	moveq #119,d0
	not.b d0
	and.l d6,d0
	jne .L49
	lea _board,a2
	cmp.b #10,(a2,d6.l)
	jeq .L140
.L49:
	moveq #-31,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L50
	lea _board,a2
	cmp.b #11,(a2,d0.l)
	jeq .L140
.L50:
	moveq #-16,d3
	add.l a0,d3
	moveq #119,d0
	not.b d0
	and.l d3,d0
	jne .L51
	lea _board,a2
	cmp.b #10,(a2,d3.l)
	jeq .L140
.L51:
	moveq #-18,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L52
	lea _board,a2
	cmp.b #11,(a2,d0.l)
	jeq .L140
.L52:
	moveq #-15,d4
	add.l a0,d4
	moveq #119,d0
	not.b d0
	and.l d4,d0
	jne .L53
	lea _board,a2
	cmp.b #10,(a2,d4.l)
	jeq .L140
.L53:
	moveq #-14,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L54
	lea _board,a2
	cmp.b #11,(a2,d0.l)
	jeq .L140
.L54:
	lea (1,a0),a2
	moveq #119,d1
	not.b d1
	move.l a2,d0
	and.l d0,d1
	jne .L55
	lea _board,a3
	cmp.b #10,(a3,a2.l)
	jeq .L140
.L55:
	moveq #14,d0
	add.l a0,d0
	moveq #119,d1
	not.b d1
	and.l d0,d1
	jne .L56
	lea _board,a3
	cmp.b #11,(a3,d0.l)
	jeq .L140
.L56:
	lea (-1,a0),a6
	moveq #119,d1
	not.b d1
	move.l a6,d0
	and.l d0,d1
	jne .L57
	lea _board,a3
	cmp.b #10,(a3,a6.l)
	jeq .L140
.L57:
	lea (18,a0),a3
	move.l a3,d0
	moveq #119,d1
	not.b d1
	and.l d1,d0
	jne .L58
	lea _board,a4
	cmp.b #11,(a4,a3.l)
	jeq .L140
.L58:
	tst.l 44(sp)
	jne .L59
	lea _board,a3
	cmp.b #10,(a3,d7.l)
	jeq .L140
.L59:
	moveq #31,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L60
	lea _board,a3
	cmp.b #11,(a3,d1.l)
	jeq .L140
.L60:
	moveq #16,d1
	add.l a0,d1
	moveq #119,d0
	not.b d0
	and.l d1,d0
	jne .L61
	lea _board,a3
	cmp.b #10,(a3,d1.l)
	jeq .L140
.L61:
	lea (33,a0),a3
	move.l a3,d0
	moveq #119,d2
	not.b d2
	and.l d2,d0
	jne .L62
	lea _board,a4
	cmp.b #11,(a4,a3.l)
	jeq .L140
.L62:
	cmp.w #0,a1
	jne .L45
	lea _board,a1
	cmp.b #10,(a1,d5.l)
	jne .L45
.L140:
	moveq #1,d0
.L173:
	movem.l (sp)+,#31996
	addq.l #4,sp
	rts
.L172:
	lea _board,a2
	cmp.b #9,(a2,d5.l)
	jne .L46
	moveq #1,d0
	jra .L173
.L168:
	lea _board,a1
	cmp.b #1,(a1,d4.l)
	jeq .L140
	moveq #-17,d6
	add.l a0,d6
	moveq #119,d1
	not.b d1
	and.l d6,d1
	jeq .L174
.L29:
	moveq #-33,d2
	add.l a0,d2
	moveq #119,d3
	not.b d3
	and.l d2,d3
	lea _board,a1
	jeq .L96
	moveq #-31,d1
	add.l a0,d1
	moveq #119,d2
	not.b d2
	and.l d1,d2
	jne .L32
	jra .L175
.L64:
	moveq #8,d0
	and.l d1,d0
	cmp.l a5,d0
	jne .L63
	moveq #7,d0
	and.l d0,d1
	subq.l #6,d1
	moveq #1,d0
	cmp.l d1,d0
	jcs .L63
	jra .L173
.L169:
	lea _board,a1
	cmp.b #2,(a1,d5.l)
	jne .L45
	moveq #1,d0
	jra .L173
.L82:
	moveq #8,d0
	and.l d1,d0
	cmp.l a5,d0
	jne .L67
	moveq #7,d0
	and.l d0,d1
	subq.l #6,d1
	moveq #1,d0
	cmp.l d1,d0
	jcs .L67
	jra .L173
.L170:
	moveq #7,d0
	and.l d0,d1
	move.l d1,d0
	subq.l #6,d0
	moveq #1,d1
	cmp.l d0,d1
	jcs .L70
	moveq #1,d0
	jra .L173
.L171:
	moveq #7,d1
	and.l d1,d0
	subq.l #6,d0
	moveq #1,d1
	cmp.l d0,d1
	jcs .L73
	moveq #1,d0
	jra .L173
.L88:
	moveq #8,d1
	and.l d0,d1
	cmp.l a5,d1
	jne .L75
	and.b #5,d0
	cmp.b #5,d0
	jne .L75
	moveq #1,d0
	jra .L173
.L90:
	moveq #8,d1
	and.l d0,d1
	cmp.l a5,d1
	jne .L77
	and.b #5,d0
	cmp.b #5,d0
	jeq .L140
	moveq #119,d0
	not.b d0
	and.l d7,d0
	jeq .L176
	jra .L79
.L92:
	moveq #8,d1
	and.l d0,d1
	cmp.l a5,d1
	jne .L79
	and.b #5,d0
	cmp.b #5,d0
	jne .L79
	moveq #1,d0
	jra .L173
.L94:
	moveq #8,d0
	and.l d1,d0
	cmp.l a5,d0
	jeq .L177
.L147:
	moveq #0,d0
	movem.l (sp)+,#31996
	addq.l #4,sp
	rts
.L177:
	and.b #5,d1
	cmp.b #5,d1
	seq d0
	ext.w d0
	ext.l d0
	neg.l d0
	movem.l (sp)+,#31996
	addq.l #4,sp
	rts
	.align	2
	.globl	_sq2algebraic
_sq2algebraic:
	move.l d2,-(sp)
	move.l 8(sp),d1
	move.l #_buf.2800,d0
	move.b d1,d2
	and.b #7,d2
	add.b #97,d2
	move.l d0,a0
	move.b d2,(a0)
	lsr.b #4,d1
	add.b #49,d1
	move.b d1,_buf.2800+1
	clr.b _buf.2800+2
	move.l (sp)+,d2
	rts
.LC0:
	.ascii "\12\0"
.LC1:
	.ascii "%4d\0"
	.align	2
	.globl	_printpsq
_printpsq:
	movem.l #8240,-(sp)
	move.l 20(sp),d0
	lsl.l #8,d0
	move.l 16(sp),a2
	add.l d0,a2
	moveq #0,d2
	lea _printf,a3
.L181:
	moveq #7,d0
	and.l d2,d0
	jeq .L185
	move.l (a2)+,-(sp)
	pea .LC1
	jsr (a3)
	addq.l #1,d2
	addq.l #8,sp
	moveq #64,d0
	cmp.l d2,d0
	jne .L181
.L186:
	move.l #.LC0,16(sp)
	movem.l (sp)+,#3076
	jra _printf
.L185:
	pea .LC0
	jsr (a3)
	addq.l #4,sp
	move.l (a2)+,-(sp)
	pea .LC1
	jsr (a3)
	addq.l #1,d2
	addq.l #8,sp
	moveq #64,d0
	cmp.l d2,d0
	jne .L181
	jra .L186
	.align	2
	.globl	_board2fen
_board2fen:
	movem.l #15904,-(sp)
	lea _board+112,a0
	move.l #_board-16,d3
	move.l #_board,d2
	moveq #0,d4
	lea _buf.2819,a1
	lea _lookup.2820,a2
.L188:
	move.b (a0),d0
	jeq .L190
	move.l d4,d1
	addq.l #1,d1
	and.l #255,d0
	move.b (a2,d0.l),(a1,d4.l)
	move.b 1(a0),d0
	jne .L229
	moveq #2,d0
	moveq #49,d5
.L227:
	move.b 2(a0),d4
	jeq .L193
	move.b d5,(a1,d1.l)
	addq.l #1,d1
.L194:
	move.l d1,d5
	addq.l #1,d5
	and.l #255,d4
	move.b (a2,d4.l),(a1,d1.l)
	move.b 3(a0),d4
	jne .L197
	moveq #1,d0
	move.b 4(a0),d1
	jeq .L257
.L199:
	move.l d5,d6
	addq.l #1,d6
	add.b #48,d0
	move.b d0,(a1,d5.l)
.L201:
	move.l d6,d4
	addq.l #1,d4
	and.l #255,d1
	move.b (a2,d1.l),(a1,d6.l)
	move.b 5(a0),d1
	jne .L205
	moveq #1,d0
	move.b 6(a0),d1
	jeq .L246
.L262:
	move.l d4,d5
	addq.l #1,d5
	add.b #48,d0
	move.b d0,(a1,d4.l)
.L209:
	move.l d5,d4
	addq.l #1,d4
	and.l #255,d1
	move.b (a2,d1.l),(a1,d5.l)
	move.b 7(a0),d1
	jne .L213
	moveq #49,d0
	move.l d4,d5
	addq.l #1,d5
	move.b d0,(a1,d4.l)
.L215:
	move.l d5,d4
	cmp.l d2,a0
	jeq .L189
	addq.l #1,d4
	move.b #47,(a1,d5.l)
	lea (-16,a0),a0
	cmp.l d3,a0
	jne .L188
.L189:
	move.l d4,d1
	addq.l #1,d1
	move.b #32,(a1,d4.l)
	move.l d4,a0
	addq.l #2,a0
	tst.b _board+128
	jne .L230
	moveq #119,d0
	move.b d0,(a1,d1.l)
	move.l d4,d1
	addq.l #3,d1
	move.b #32,(a1,a0.l)
	move.b _board+129,d0
	jne .L217
.L263:
	move.b #45,(a1,d1.l)
	addq.l #1,d1
.L218:
	move.l d1,a2
	addq.l #1,a2
	move.b #32,(a1,d1.l)
	move.b _board+130,d2
	cmp.b #127,d2
	jeq .L258
.L222:
	move.b d2,d0
	and.b #7,d0
	add.b #97,d0
	lea _buf.2800,a0
	move.b d0,(a0)
	lsr.b #4,d2
	add.b #49,d2
	move.b d2,_buf.2800+1
	clr.b _buf.2800+2
	add.l #_buf.2819,a2
	addq.l #1,a0
	move.b d0,(a2)+
	jeq .L224
.L259:
	move.b (a0),d0
	addq.l #1,a0
	move.b d0,(a2)+
	jne .L259
.L224:
	addq.l #3,d1
	clr.b (a1,d1.l)
	move.l #_buf.2819,d0
	movem.l (sp)+,#1148
	rts
.L229:
	move.l d1,d5
.L191:
	move.l d5,d1
	addq.l #1,d1
	and.l #255,d0
	move.b (a2,d0.l),(a1,d5.l)
	move.b 2(a0),d4
	jne .L194
	moveq #1,d0
.L193:
	move.b 3(a0),d4
	jeq .L260
	move.l d1,d5
	addq.l #1,d5
	add.b #48,d0
	move.b d0,(a1,d1.l)
.L197:
	move.l d5,d6
	addq.l #1,d6
	and.l #255,d4
	move.b (a2,d4.l),(a1,d5.l)
	move.b 4(a0),d1
	jne .L201
	moveq #1,d0
.L202:
	move.b 5(a0),d1
	jeq .L245
	move.l d6,d4
	addq.l #1,d4
	add.b #48,d0
	move.b d0,(a1,d6.l)
.L205:
	move.l d4,d5
	addq.l #1,d5
	and.l #255,d1
	move.b (a2,d1.l),(a1,d4.l)
	move.b 6(a0),d1
	jne .L209
	moveq #1,d0
	move.b 7(a0),d1
	jeq .L261
.L211:
	move.l d5,d4
	addq.l #1,d4
	add.b #48,d0
	move.b d0,(a1,d5.l)
.L213:
	move.l d4,d5
	addq.l #1,d5
	and.l #255,d1
	move.b (a2,d1.l),(a1,d4.l)
	jra .L215
.L190:
	move.b 1(a0),d0
	jne .L226
	move.l d4,d1
	moveq #3,d0
	moveq #50,d5
	jra .L227
.L245:
	addq.l #1,d0
	move.l d6,d4
	move.b 6(a0),d1
	jne .L262
.L246:
	addq.l #1,d0
	move.l d4,d5
	move.b 7(a0),d1
	jne .L211
.L261:
	add.b #49,d0
	move.l d5,d1
	addq.l #1,d5
	move.b d0,(a1,d1.l)
	jra .L215
.L260:
	addq.l #1,d0
	move.l d1,d5
	move.b 4(a0),d1
	jne .L199
.L257:
	addq.l #1,d0
	move.l d5,d6
	jra .L202
.L226:
	move.l d4,d5
	addq.l #1,d5
	move.b #49,(a1,d4.l)
	jra .L191
.L230:
	moveq #98,d0
	move.b d0,(a1,d1.l)
	move.l d4,d1
	addq.l #3,d1
	move.b #32,(a1,a0.l)
	move.b _board+129,d0
	jeq .L263
.L217:
	btst #3,d0
	jeq .L219
	move.b #75,(a1,d1.l)
	move.l d4,d1
	addq.l #4,d1
.L219:
	btst #2,d0
	jeq .L220
	move.b #81,(a1,d1.l)
	addq.l #1,d1
.L220:
	btst #1,d0
	jeq .L221
	move.b #107,(a1,d1.l)
	addq.l #1,d1
.L221:
	btst #0,d0
	jeq .L218
	move.b #113,(a1,d1.l)
	addq.l #1,d1
	move.l d1,a2
	addq.l #1,a2
	move.b #32,(a1,d1.l)
	move.b _board+130,d2
	cmp.b #127,d2
	jne .L222
.L258:
	addq.l #2,d1
	move.b #45,(a1,a2.l)
	clr.b (a1,d1.l)
	move.l #_buf.2819,d0
	movem.l (sp)+,#1148
	rts
.LC2:
	.ascii " -\0"
.LC3:
	.ascii "white\0"
.LC4:
	.ascii "black\0"
.LC5:
	.ascii "\12   a b c d e f g h\12\12\0"
.LC6:
	.ascii "%d \0"
.LC7:
	.ascii "*\0"
.LC8:
	.ascii " \0"
.LC9:
	.ascii "%c\0"
.LC10:
	.ascii "\12   a b c d e f g h\11\11Position key: %llX\0"
.LC11:
	.ascii "\12Side to move: %s e.p.: %s\12\0"
.LC12:
	.ascii "Fen: %s\12\0"
	.align	2
	.globl	_printBoard
_printBoard:
	movem.l #15420,-(sp)
	pea .LC5
	lea _printf,a4
	jsr (a4)
	lea _board+112,a5
	addq.l #4,sp
	moveq #8,d5
	moveq #32,d4
.L265:
	move.l a5,a2
	clr.w d2
.L279:
	move.b (a2)+,d3
	moveq #7,d0
	and.l d3,d0
	add.l d0,d0
	move.w .L268(pc,d0.l),d0
	jmp %pc@(2,d0:w)
	.balignw 2,0x284c
.L268:
	.word .L267-.L268
	.word .L283-.L268
	.word .L270-.L268
	.word .L271-.L268
	.word .L266-.L268
	.word .L272-.L268
	.word .L273-.L268
	.word .L274-.L268
.L283:
	move.w #80,a3
	moveq #80,d4
	tst.w d2
	jeq .L289
.L275:
	btst #3,d3
	jne .L290
	pea .LC8
	jsr (a4)
	addq.l #4,sp
.L278:
	move.l a3,-(sp)
	pea .LC9
	jsr (a4)
	addq.w #1,d2
	addq.l #8,sp
	cmp.w #8,d2
	jne .L279
.L292:
	pea .LC0
	jsr (a4)
	subq.l #1,d5
	lea (-16,a5),a5
	addq.l #4,sp
	jne .L265
	lea _board,a2
	move.l 138(a2),-(sp)
	move.l 134(a2),-(sp)
	pea .LC10
	jsr (a4)
	move.b 130(a2),d0
	lea (12,sp),sp
	cmp.b #127,d0
	jeq .L284
	lea _buf.2800,a0
	move.b d0,d1
	and.b #7,d1
	add.b #97,d1
	move.b d1,(a0)
	lsr.b #4,d0
	add.b #49,d0
	move.b d0,_buf.2800+1
	clr.b _buf.2800+2
.L281:
	tst.b _board+128
	jeq .L291
	move.l #.LC4,d0
	move.l a0,-(sp)
	move.l d0,-(sp)
	pea .LC11
	jsr (a4)
	jsr _board2fen
	move.l d0,-(sp)
	pea .LC12
	jsr (a4)
	lea (20,sp),sp
	movem.l (sp)+,#15420
	rts
.L267:
	move.w #46,a3
	moveq #46,d4
	tst.w d2
	jne .L275
	jra .L289
.L273:
	move.w #82,a3
	moveq #82,d4
	tst.w d2
	jne .L275
	jra .L289
.L272:
	move.w #66,a3
	moveq #66,d4
	tst.w d2
	jne .L275
	jra .L289
.L271:
	move.w #78,a3
	moveq #78,d4
	tst.w d2
	jne .L275
	jra .L289
.L270:
	move.w #75,a3
	moveq #75,d4
	tst.w d2
	jne .L275
	jra .L289
.L274:
	move.w #81,a3
	moveq #81,d4
	tst.w d2
	jne .L275
	jra .L289
.L266:
	moveq #0,d0
	move.b d4,d0
	move.l d0,a3
	tst.w d2
	jne .L275
	jra .L289
.L290:
	pea .LC7
	jsr (a4)
	moveq #0,d0
	move.b d4,d0
	addq.l #4,sp
	move.l __ctype_,a0
	btst #0,1(a0,d0.l)
	jeq .L278
	lea (32,a3),a3
	move.l a3,-(sp)
	pea .LC9
	jsr (a4)
	addq.w #1,d2
	addq.l #8,sp
	cmp.w #8,d2
	jne .L279
	jra .L292
.L291:
	move.l #.LC3,d0
	move.l a0,-(sp)
	move.l d0,-(sp)
	pea .LC11
	jsr (a4)
	jsr _board2fen
	move.l d0,-(sp)
	pea .LC12
	jsr (a4)
	lea (20,sp),sp
	movem.l (sp)+,#15420
	rts
.L284:
	lea .LC2,a0
	jra .L281
.L289:
	move.l d5,-(sp)
	pea .LC6
	jsr (a4)
	addq.l #8,sp
	jra .L275
	.align	2
	.globl	_fen2board
_fen2board:
	movem.l #15422,-(sp)
	move.l 40(sp),a1
	lea _board,a2
	move.l a2,a0
	move.l #_board+128,d0
.L294:
	clr.b (a0)+
	cmp.l d0,a0
	jne .L294
	lea _board+32364,a0
	clr.l 28(a0)
	clr.l 24(a0)
	clr.l 4(a0)
	clr.l (a0)
	clr.l 20(a0)
	clr.l 16(a0)
	sub.l a0,a0
	moveq #7,d2
	move.l #_psq_pawns,d3
	move.l #_kingLoc,d4
	lea _psq_queens,a6
	lea _psq_bishops,a5
	lea _psq_knights,a4
	move.l #_psq_rooks,d5
.L295:
	move.b (a1)+,d1
	jeq .L314
.L313:
	move.b d1,d0
	add.b #-49,d0
	cmp.b #65,d0
	jhi .L296
	and.l #255,d0
	add.l d0,d0
	move.w .L298(pc,d0.l),d0
	jmp %pc@(2,d0:w)
	.balignw 2,0x284c
.L298:
	.word .L297-.L298
	.word .L297-.L298
	.word .L297-.L298
	.word .L297-.L298
	.word .L297-.L298
	.word .L297-.L298
	.word .L297-.L298
	.word .L297-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L299-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L300-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L301-.L298
	.word .L296-.L298
	.word .L302-.L298
	.word .L303-.L298
	.word .L304-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L305-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L306-.L298
	.word .L296-.L298
	.word .L296-.L298
	.word .L307-.L298
	.word .L296-.L298
	.word .L308-.L298
	.word .L309-.L298
	.word .L310-.L298
.L310:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #14,(a3,d0.l)
	addq.l #1,_board+32392
	move.l d2,d0
	lsl.l #3,d0
	lea 64(a0,d0.l),a3
	move.l a3,d0
	add.l a3,d0
	add.l d0,d0
	move.l d0,a3
	move.l (a3,d5.l),d0
	add.l _matValues+56,d0
	add.l d0,_board+32368
	addq.l #1,a0
.L296:
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
.L365:
	subq.l #1,d2
	jmi .L314
	sub.l a0,a0
	move.b (a1)+,d1
	jne .L313
.L314:
	move.l a1,d2
	moveq #0,d0
.L312:
	move.l d2,a0
	move.b (a0),d1
	addq.l #1,d2
	cmp.b #32,d1
	jeq .L315
	cmp.b #59,d1
	jne .L364
.L315:
	addq.l #1,d0
	jra .L312
.L309:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #15,(a3,d0.l)
	addq.l #1,_board+32392
	move.l d2,d0
	lsl.l #3,d0
	lea 64(a0,d0.l),a3
	move.l a3,d0
	add.l a3,d0
	add.l d0,d0
	move.l (a6,d0.l),d0
	add.l _matValues+60,d0
	add.l d0,_board+32368
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L308:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #9,(a3,d0.l)
	addq.l #1,_board+32384
	move.l d2,d0
	lsl.l #3,d0
	lea 64(a0,d0.l),a3
	move.l a3,d0
	add.l a3,d0
	add.l d0,d0
	move.l d0,a3
	move.l (a3,d3.l),d0
	add.l _matValues+36,d0
	add.l d0,_board+32368
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L307:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #11,(a3,d0.l)
	addq.l #1,_board+32392
	move.l d2,d0
	lsl.l #3,d0
	lea 64(a0,d0.l),a3
	move.l a3,d0
	add.l a3,d0
	add.l d0,d0
	move.l (a4,d0.l),d0
	add.l _matValues+44,d0
	add.l d0,_board+32368
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L306:
	move.l d2,d0
	lsl.l #4,d0
	add.l a0,d0
	move.b #10,(a2,d0.l)
	move.l d0,_kingLoc+4
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L305:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #13,(a3,d0.l)
	addq.l #1,_board+32392
	move.l d2,d0
	lsl.l #3,d0
	lea 64(a0,d0.l),a3
	move.l a3,d0
	add.l a3,d0
	add.l d0,d0
	move.l (a5,d0.l),d0
	add.l _matValues+52,d0
	add.l d0,_board+32368
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L304:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #6,(a3,d0.l)
	addq.l #1,_board+32388
	move.l d2,d0
	lsl.l #3,d0
	add.l a0,d0
	add.l d0,d0
	add.l d0,d0
	move.l d0,a3
	move.l (a3,d5.l),d0
	add.l _matValues+24,d0
	add.l d0,_board+32364
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L303:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #7,(a3,d0.l)
	addq.l #1,_board+32388
	move.l d2,d0
	lsl.l #3,d0
	add.l a0,d0
	add.l d0,d0
	add.l d0,d0
	move.l (a6,d0.l),d0
	add.l _matValues+28,d0
	add.l d0,_board+32364
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L302:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #1,(a3,d0.l)
	addq.l #1,_board+32380
	move.l d2,d0
	lsl.l #3,d0
	add.l a0,d0
	add.l d0,d0
	add.l d0,d0
	move.l d0,a3
	move.l (a3,d3.l),d0
	add.l _matValues+4,d0
	add.l d0,_board+32364
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L299:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #5,(a3,d0.l)
	addq.l #1,_board+32388
	move.l d2,d0
	lsl.l #3,d0
	add.l a0,d0
	add.l d0,d0
	add.l d0,d0
	move.l (a5,d0.l),d0
	add.l _matValues+20,d0
	add.l d0,_board+32364
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L297:
	ext.w d1
	lea -48(a0,d1.w),a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L301:
	move.l a2,d1
	add.l a0,d1
	move.l d2,d0
	lsl.l #4,d0
	move.l d1,a3
	move.b #3,(a3,d0.l)
	addq.l #1,_board+32388
	move.l d2,d0
	lsl.l #3,d0
	add.l a0,d0
	add.l d0,d0
	add.l d0,d0
	move.l (a4,d0.l),d0
	add.l _matValues+12,d0
	add.l d0,_board+32364
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L300:
	move.l d2,d0
	lsl.l #4,d0
	add.l a0,d0
	move.b #2,(a2,d0.l)
	move.l d4,a3
	move.l d0,(a3)
	addq.l #1,a0
	moveq #8,d0
	cmp.l a0,d0
	jne .L295
	jra .L365
.L364:
	cmp.b #98,d1
	jeq .L366
	cmp.b #119,d1
	jeq .L367
.L317:
	tst.b d1
	jeq .L318
.L372:
	addq.l #1,d0
	move.b (a1,d0.l),d1
	jeq .L318
.L319:
	cmp.b #32,d1
	jeq .L321
	cmp.b #59,d1
	jne .L368
.L321:
	addq.l #1,d0
	move.b (a1,d0.l),d1
	jra .L319
.L368:
	cmp.b #45,d1
	jeq .L322
	moveq #0,d2
	sub.l a0,a0
.L327:
	cmp.b #75,d1
	jeq .L369
	cmp.b #81,d1
	jeq .L370
	cmp.b #107,d1
	jne .L326
	addq.l #2,d2
.L324:
	addq.l #1,d0
	move.b (a1,d0.l),d1
	cmp.b #32,d1
	jne .L327
.L373:
	add.l a0,a0
	move.l a0,d1
	add.l a0,d1
	or.b d2,d1
	move.b d1,_board+129
	lea (a1,d0.l),a0
.L329:
	move.l a0,a2
	move.b (a0)+,d1
	cmp.b #32,d1
	jeq .L330
	cmp.b #59,d1
	jne .L371
.L330:
	addq.l #1,d0
	jra .L329
.L318:
	clr.b _board+129
	move.b #127,_board+130
	movem.l (sp)+,#31804
	rts
.L371:
	move.b #127,_board+130
	move.b (a2),d1
	cmp.b #45,d1
	jeq .L331
	move.b 1(a1,d0.l),d0
	ext.w d0
	lsl.b #4,d0
	add.b d0,d1
	add.b #-113,d1
	move.b d1,_board+130
.L331:
	jsr _generatePosKey
	lea _board+131,a0
	move.l d0,3(a0)
	move.l d1,7(a0)
	clr.w 1(a0)
	clr.b (a0)
	movem.l (sp)+,#31804
	rts
.L367:
	clr.b _board+128
	move.b (a0),d1
	jeq .L318
	jra .L372
.L366:
	move.b #8,_board+128
	cmp.b #119,d1
	jne .L317
	jra .L367
.L370:
	addq.l #1,a0
	addq.l #1,d0
	move.b (a1,d0.l),d1
	cmp.b #32,d1
	jne .L327
	jra .L373
.L369:
	addq.l #2,a0
	addq.l #1,d0
	move.b (a1,d0.l),d1
	cmp.b #32,d1
	jne .L327
	jra .L373
.L326:
	cmp.b #113,d1
	jne .L324
	addq.l #1,d2
	addq.l #1,d0
	move.b (a1,d0.l),d1
	cmp.b #32,d1
	jne .L327
	jra .L373
.L322:
	addq.l #1,d0
	clr.b d1
	move.b d1,_board+129
	lea (a1,d0.l),a0
	jra .L329
.LC13:
	.ascii "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1\0"
	.align	2
	.globl	_initBoard
_initBoard:
	movem.l #16190,-(sp)
	clr.w _board+142
	pea .LC13
	jsr _fen2board
	moveq #4,d0
	move.l d0,_kingLoc
	moveq #116,d0
	move.l d0,_kingLoc+4
	move.l #_psq_pawns+256,d5
	move.l #_psq_knights+256,d4
	move.l #_psq_bishops+256,d3
	lea _psq_rooks+256,a6
	lea _psq_queens+256,a5
	addq.l #4,sp
	sub.l a0,a0
	moveq #0,d2
	move.l #_psq_pawns,d7
	lea _raw_psq_pawns,a4
	move.l #_raw_psq_knights,d6
	lea _raw_psq_queens,a1
.L376:
	move.l d2,d0
	jlt .L380
	asr.l #3,d0
	moveq #7,d1
	sub.l d0,d1
	move.l d1,d0
	lsl.l #3,d0
	moveq #7,d1
	and.l d2,d1
	add.l d1,d0
	add.l d0,d0
	add.l d0,d0
	move.l (a4,d0.l),(a0,d7.l)
	move.l d5,a2
	move.l (a4,a0.l),d1
	neg.l d1
	move.l d1,(a2)+
	move.l a2,d5
	move.l d6,a2
	move.l (a2,d0.l),d1
	lea _psq_knights,a2
	move.l d1,(a2,a0.l)
	move.l d4,a2
	neg.l d1
	move.l d1,(a2)+
	move.l a2,d4
	lea _psq_bishops,a2
	lea _raw_psq_bishops,a3
	move.l (a3,d0.l),(a2,a0.l)
	move.l d3,a2
	move.l (a3,a0.l),d1
	neg.l d1
	move.l d1,(a2)+
	move.l a2,d3
	lea _psq_rooks,a3
	lea _raw_psq_rooks,a2
	move.l (a2,d0.l),(a3,a0.l)
	move.l (a2,a0.l),d1
	neg.l d1
	move.l d1,(a6)+
	lea _psq_queens,a2
	move.l (a1,d0.l),(a2,a0.l)
	move.l (a1,a0.l),d0
	neg.l d0
	move.l d0,(a5)+
	addq.l #1,d2
	addq.l #4,a0
	moveq #64,d1
	cmp.l d2,d1
	jne .L376
.L381:
	movem.l (sp)+,#31996
	rts
.L380:
	addq.l #7,d0
	asr.l #3,d0
	moveq #7,d1
	sub.l d0,d1
	move.l d1,d0
	lsl.l #3,d0
	moveq #7,d1
	and.l d2,d1
	add.l d1,d0
	add.l d0,d0
	add.l d0,d0
	move.l (a4,d0.l),(a0,d7.l)
	move.l d5,a2
	move.l (a4,a0.l),d1
	neg.l d1
	move.l d1,(a2)+
	move.l a2,d5
	move.l d6,a2
	move.l (a2,d0.l),d1
	lea _psq_knights,a2
	move.l d1,(a2,a0.l)
	move.l d4,a2
	neg.l d1
	move.l d1,(a2)+
	move.l a2,d4
	lea _psq_bishops,a2
	lea _raw_psq_bishops,a3
	move.l (a3,d0.l),(a2,a0.l)
	move.l d3,a2
	move.l (a3,a0.l),d1
	neg.l d1
	move.l d1,(a2)+
	move.l a2,d3
	lea _psq_rooks,a3
	lea _raw_psq_rooks,a2
	move.l (a2,d0.l),(a3,a0.l)
	move.l (a2,a0.l),d1
	neg.l d1
	move.l d1,(a6)+
	lea _psq_queens,a2
	move.l (a1,d0.l),(a2,a0.l)
	move.l (a1,a0.l),d0
	neg.l d0
	move.l d0,(a5)+
	addq.l #1,d2
	addq.l #4,a0
	moveq #64,d1
	cmp.l d2,d1
	jne .L376
	jra .L381
_lookup.2820:
	.ascii " PKN BRQ pkn brq\0"
.lcomm _buf.2819,128
.lcomm _buf.2800,3
