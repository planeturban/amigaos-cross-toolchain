#NO_APP
	.text
	.align	2
	.globl	_init
_init:
	jsr _initHash
	jsr _InitMvvLva
	jsr _initBoard
	lea _board+142,a0
	clr.w (a0)
	clr.l 32194(a0)
	clr.l 32198(a0)
	clr.l 32202(a0)
	pea 4.w
	jsr _TT_set_size
	addq.l #4,sp
	rts
.LC0:
	.ascii "r\0"
.LC1:
	.ascii "/home/alex/git/local/amichess/src/perfsuite.epd\0"
.LC2:
	.ascii "Correct: %d -- Error: %d\12\0"
.LC3:
	.ascii "\0"
.LC4:
	.ascii "#%3d Depth: %d, value=%d - Perft: %d %s\12\0"
	.align	2
	.globl	_testPerft
_testPerft:
	lea (-380,sp),sp
	movem.l #16190,-(sp)
	move.l 428(sp),a4
	pea .LC0
	pea .LC1
	jsr _fopen
	move.l d0,d6
	addq.l #8,sp
	moveq #1,d5
	moveq #0,d7
	clr.l 44(sp)
	move.l sp,d4
	add.l #168,d4
	lea _fgets,a5
	lea _strchr,a3
	lea _atol,a6
	move.l d6,-(sp)
	pea 256.w
	move.l d4,-(sp)
	jsr (a5)
	lea (12,sp),sp
	tst.l d0
	jeq .L19
.L11:
	pea 59.w
	move.l d4,-(sp)
	jsr (a3)
	move.l d0,a2
	clr.b (a2)
	lea (56,sp),a1
	addq.l #8,sp
	move.l d4,a0
.L4:
	move.b (a0)+,(a1)+
	jne .L4
	cmp.w #0,a4
	jeq .L5
	move.l a4,d2
	move.l a2,d3
	addq.l #1,d3
	pea 59.w
	move.l d3,-(sp)
	jsr (a3)
	addq.l #8,sp
	tst.l d0
	jeq .L20
.L6:
	move.l d0,a0
	clr.b (a0)
	subq.l #1,d2
	jeq .L21
.L12:
	move.l d0,a2
	move.l a2,d3
	addq.l #1,d3
	pea 59.w
	move.l d3,-(sp)
	jsr (a3)
	addq.l #8,sp
	tst.l d0
	jne .L6
.L20:
	pea 10.w
	move.l d3,-(sp)
	jsr (a3)
	addq.l #8,sp
	move.l d0,a0
	clr.b (a0)
	subq.l #1,d2
	jne .L12
.L21:
	cmp.b #68,1(a2)
	jeq .L22
	addq.l #1,d5
.L24:
	move.l d6,-(sp)
	pea 256.w
	move.l d4,-(sp)
	jsr (a5)
	lea (12,sp),sp
	tst.l d0
	jne .L11
.L19:
	move.l d7,-(sp)
	move.l 48(sp),-(sp)
	pea .LC2
	jsr _printf
	move.l d6,-(sp)
	jsr _fclose
	lea (16,sp),sp
	movem.l (sp)+,#31996
	lea (380,sp),sp
	rts
.L22:
	move.b 2(a2),d0
	ext.w d0
	move.w d0,a0
	moveq #-48,d2
	add.l a0,d2
	pea 4(a2)
	jsr (a6)
	move.l d0,d3
	pea 52(sp)
	jsr _fen2board
	moveq #0,d0
	not.b d0
	and.l d2,d0
	move.l d0,-(sp)
	jsr _Perft
	lea (12,sp),sp
	cmp.l d3,d1
	jeq .L23
	pea 48(sp)
	move.l d1,-(sp)
	move.l d3,-(sp)
	move.l d2,-(sp)
	move.l d5,-(sp)
	pea .LC4
	jsr _printf
	addq.l #1,d7
	lea (24,sp),sp
	addq.l #1,d5
	jra .L24
.L5:
	move.b (a4),d0
	trap #7
.L23:
	pea .LC3
	move.l d3,-(sp)
	move.l d3,-(sp)
	move.l d2,-(sp)
	move.l d5,-(sp)
	pea .LC4
	jsr _printf
	addq.l #1,68(sp)
	lea (24,sp),sp
	addq.l #1,d5
	jra .L24
.LC5:
	.ascii "No id!!!\12\0"
.LC6:
	.ascii "NOT SOLVED\0"
.LC7:
	.ascii "SOLVED\0"
.LC8:
	.ascii "Can't open \"%s\" for reading.\12\0"
.LC9:
	.ascii "bm \0"
.LC10:
	.ascii "Can't find bm (best move start marker) at line %d\12\0"
.LC11:
	.ascii "%d/%d (%s) Engine: %s (D:%d) EPD: %s -- %s\12\0"
.LC12:
	.ascii "cmd: testepd %d %s\0"
.LC13:
	.ascii "Time: %dms Nodes: %lld %d/%d Avg.Depth: %g (%s)\12%s\12\0"
	.align	2
	.globl	_testEPD
_testEPD:
	lea (-3588,sp),sp
	movem.l #16190,-(sp)
	moveq #2,d0
	move.l d0,176(sp)
	pea .LC0
	move.l 3640(sp),-(sp)
	jsr _fopen
	move.l d0,68(sp)
	addq.l #8,sp
	jeq .L44
	lea _get_ms,a2
	jsr (a2)
	move.l d0,64(sp)
	moveq #1,d3
	clr.l 44(sp)
	clr.l 48(sp)
	clr.l 52(sp)
	moveq #0,d5
	move.l sp,d2
	add.l #304,d2
	move.l sp,d6
	add.l #560,d6
	lea _strstr,a3
	lea (80,sp),a4
	moveq #68,d7
	add.l sp,d7
	move.l d3,d4
	subq.l #1,d4
	move.l 60(sp),-(sp)
	pea 256.w
	move.l d2,-(sp)
	jsr _fgets
	lea (12,sp),sp
	tst.l d0
	jeq .L31
.L36:
	pea .LC9
	move.l d2,-(sp)
	jsr (a3)
	move.l d0,a6
	pea 59.w
	move.l d2,-(sp)
	jsr _strchr
	move.l d0,a5
	lea (16,sp),sp
	move.l d2,a0
.L29:
	tst.b (a0)+
	jne .L29
	move.l d2,d0
	sub.l a0,d0
	lea (3632,sp),a0
	sub.l d0,a0
	clr.b -3330(a0)
	cmp.w #0,a6
	jeq .L45
	move.l a6,d4
	addq.l #3,d4
	clr.b 2(a6)
	lea (184,sp),a1
	move.l d2,a0
.L32:
	move.b (a0)+,(a1)+
	jne .L32
	pea 184(sp)
	jsr _fen2board
	addq.l #4,sp
	cmp.w #0,a5
	jeq .L38
	move.l a5,a6
	clr.b (a6)+
	cmp.b #32,1(a5)
	jne .L33
.L34:
	addq.l #1,a6
	cmp.b #32,(a6)
	jeq .L34
.L33:
	jsr _TT_clear
	jsr (a2)
	move.l d0,84(sp)
	jsr (a2)
	add.l 3640(sp),d0
	move.l d0,88(sp)
	clr.l 124(sp)
	moveq #1,d0
	move.l d0,96(sp)
	move.l a4,-(sp)
	jsr _think
	move.l d0,72(sp)
	move.l d6,-(sp)
	jsr _generateLegalMoves
	move.l d0,a5
	move.l d7,-(sp)
	jsr _move_make
	move.l d6,-(sp)
	move.l a5,-(sp)
	move.l a4,a0
	move.l -(a0),-(sp)
	move.l -(a0),-(sp)
	move.l -4(a0),-(sp)
	jsr _move_to_san
	move.l d0,a5
	lea (28,sp),sp
	move.l d0,(sp)
	move.l d4,-(sp)
	jsr (a3)
	move.l d0,64(sp)
	move.l d7,-(sp)
	jsr _move_unmake
	lea (12,sp),sp
	tst.l 56(sp)
	jeq .L35
	addq.l #1,d5
	move.l 92(sp),d0
	add.l d0,52(sp)
	lea .LC7,a0
	move.l a0,-(sp)
	move.l d4,-(sp)
	move.l d0,-(sp)
	move.l a5,-(sp)
	move.l a6,-(sp)
	move.l d3,-(sp)
	move.l d5,-(sp)
	pea .LC11
	jsr _printf
	move.l 136(sp),d0
	move.l 140(sp),d1
	add.l d1,80(sp)
	move.l 76(sp),d4
	addx.l d0,d4
	move.l d4,76(sp)
	addq.l #1,d3
	lea (32,sp),sp
.L46:
	move.l d3,d4
	subq.l #1,d4
	move.l 60(sp),-(sp)
	pea 256.w
	move.l d2,-(sp)
	jsr _fgets
	lea (12,sp),sp
	tst.l d0
	jne .L36
.L31:
	jsr (a2)
	move.l d0,d7
	move.l 3636(sp),-(sp)
	move.l 3644(sp),-(sp)
	pea .LC12
	move.l d6,-(sp)
	jsr _sprintf
	jsr _getCPUModel
	move.l d6,-(sp)
	move.l d0,-(sp)
	lea ___floatsidf,a2
	move.l 76(sp),-(sp)
	jsr (a2)
	move.l d0,d2
	move.l d1,d3
	move.l d4,(sp)
	jsr (a2)
	move.l d1,(sp)
	move.l d0,-(sp)
	move.l d3,-(sp)
	move.l d2,-(sp)
	jsr ___divdf3
	lea (12,sp),sp
	move.l d1,(sp)
	move.l d0,-(sp)
	move.l d4,-(sp)
	move.l d5,-(sp)
	move.l 88(sp),-(sp)
	move.l 88(sp),-(sp)
	sub.l 112(sp),d7
	move.l d7,-(sp)
	pea .LC13
	jsr _printf
	lea (56,sp),sp
	move.l 60(sp),-(sp)
	jsr _fclose
	addq.l #4,sp
.L25:
	movem.l (sp)+,#31996
	lea (3588,sp),sp
	rts
.L35:
	move.l 92(sp),d0
	add.l d0,52(sp)
	lea .LC6,a0
	move.l a0,-(sp)
	move.l d4,-(sp)
	move.l d0,-(sp)
	move.l a5,-(sp)
	move.l a6,-(sp)
	move.l d3,-(sp)
	move.l d5,-(sp)
	pea .LC11
	jsr _printf
	move.l 136(sp),d0
	move.l 140(sp),d1
	add.l d1,80(sp)
	move.l 76(sp),d4
	addx.l d0,d4
	move.l d4,76(sp)
	addq.l #1,d3
	lea (32,sp),sp
	jra .L46
.L38:
	lea .LC5,a6
	jra .L33
.L45:
	clr.l -(sp)
	pea .LC10
	jsr _printf
	addq.l #8,sp
	jsr (a2)
	move.l d0,d7
	move.l 3636(sp),-(sp)
	move.l 3644(sp),-(sp)
	pea .LC12
	move.l d6,-(sp)
	jsr _sprintf
	jsr _getCPUModel
	move.l d6,-(sp)
	move.l d0,-(sp)
	lea ___floatsidf,a2
	move.l 76(sp),-(sp)
	jsr (a2)
	move.l d0,d2
	move.l d1,d3
	move.l d4,(sp)
	jsr (a2)
	move.l d1,(sp)
	move.l d0,-(sp)
	move.l d3,-(sp)
	move.l d2,-(sp)
	jsr ___divdf3
	lea (12,sp),sp
	move.l d1,(sp)
	move.l d0,-(sp)
	move.l d4,-(sp)
	move.l d5,-(sp)
	move.l 88(sp),-(sp)
	move.l 88(sp),-(sp)
	sub.l 112(sp),d7
	move.l d7,-(sp)
	pea .LC13
	jsr _printf
	lea (56,sp),sp
	move.l 60(sp),-(sp)
	jsr _fclose
	addq.l #4,sp
	jra .L25
.L44:
	move.l 3636(sp),-(sp)
	pea .LC8
	jsr _printf
	addq.l #8,sp
	movem.l (sp)+,#31996
	lea (3588,sp),sp
	rts
.LC14:
	.ascii "-bench\0"
.LC15:
	.ascii "-bench2\0"
.LC16:
	.ascii "-bench3\0"
.LC17:
	.ascii "-bench4\0"
.LC18:
	.ascii "../src/wac.epd\0"
.LC19:
	.ascii "8/k7/3p4/p2P1p2/P2P1P2/8/8/K7 w - -\0"
.LC20:
	.ascii "2Q5/8/3K4/8/2k5/8/P7/8 b - - 2 62\0"
	.text
	.align	2
	.globl	_main
_main:
	link.w a5,#-104
	move.l a2,-(sp)
	clr.l -8(a5)
	jsr _init
	moveq #1,d0
	cmp.l 8(a5),d0
	jge .L48
	move.l 12(a5),a0
	move.l 4(a0),a0
	move.l a0,a2
	lea .LC14,a1
.L50:
	move.b (a2)+,d0
	cmp.b (a1)+,d0
	jne .L49
	tst.b d0
	jne .L50
	pea 100.w
	pea .LC18
	jsr _testEPD
	jsr _TT_free
	moveq #0,d0
	move.l -108(a5),a2
	unlk a5
	rts
.L49:
	move.l a0,a2
	lea .LC15,a1
.L53:
	move.b (a2)+,d0
	cmp.b (a1)+,d0
	jne .L52
	tst.b d0
	jne .L53
	jsr _get_ms
	move.l d0,-100(a5)
	clr.l -88(a5)
	moveq #8,d0
	move.l d0,-92(a5)
	pea -104(a5)
	jsr _think
	jsr _TT_free
	moveq #0,d0
	move.l -108(a5),a2
	unlk a5
	rts
.L52:
	move.l a0,a2
	lea .LC16,a1
.L55:
	move.b (a2)+,d0
	cmp.b (a1)+,d0
	jne .L54
	tst.b d0
	jne .L55
	pea .LC19
	jsr _fen2board
	jsr _get_ms
	move.l d0,-100(a5)
	add.l #30000,d0
	move.l d0,-96(a5)
	moveq #1,d0
	move.l d0,-88(a5)
	pea -104(a5)
	jsr _think
.L64:
	jsr _TT_free
	moveq #0,d0
	move.l -108(a5),a2
	unlk a5
	rts
.L54:
	lea .LC17,a1
.L56:
	move.b (a0)+,d0
	cmp.b (a1)+,d0
	jne .L48
	tst.b d0
	jne .L56
	pea .LC20
	jsr _fen2board
	jsr _get_ms
	move.l d0,-100(a5)
	add.l #30000,d0
	move.l d0,-96(a5)
	moveq #1,d0
	move.l d0,-88(a5)
	pea -104(a5)
	jsr _think
	jra .L64
.L48:
	pea -104(a5)
	jsr _input_loop
	jsr _TT_free
	moveq #0,d0
	move.l -108(a5),a2
	unlk a5
	rts
.comm _board,32396
