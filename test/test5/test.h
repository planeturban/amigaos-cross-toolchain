typedef unsigned char uint8_t;
typedef short int int16_t;
typedef unsigned short int uint16_t;
typedef unsigned long uint32_t;
typedef long int32_t;
typedef unsigned short UWORD;
typedef uint32_t* APTR;
typedef uint32_t ULONG;
typedef unsigned char UBYTE;

typedef uint8_t* frame_buffer_t;

#define SCREEN_WIDTH_BYTES 40
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 256
#define SCREEN_BIT_DEPTH 5

extern uint8_t* game_offScreenBuffer;


#ifndef	HARDWARE_BLIT_H
#define	HARDWARE_BLIT_H
/*
**	$VER: blit.h 39.1 (18.9.1992)
**	Includes Release 45.1
**
**	Defines for direct hardware use of the blitter.
**
**	(C) Copyright 1985-2001 Amiga, Inc.
**	    All Rights Reserved
*/

#define HSIZEBITS 6
#define VSIZEBITS 16-HSIZEBITS
#define HSIZEMASK 0x3f	      /* 2^6 -- 1 */
#define VSIZEMASK 0x3FF       /* 2^10 - 1 */

/* all agnii support horizontal blit of at least 1024 bits (128 bytes) wide */
/* some agnii support horizontal blit of up to 32768 bits (4096 bytes) wide */

#ifndef	 NO_BIG_BLITS
#define  MINBYTESPERROW 128
#define  MAXBYTESPERROW 4096
#else
#define  MAXBYTESPERROW 128
#endif

/* definitions for blitter control register 0 */

#define ABC    0x80
#define ABNC   0x40
#define ANBC   0x20
#define ANBNC  0x10
#define NABC   0x8
#define NABNC  0x4
#define NANBC  0x2
#define NANBNC 0x1

/* some commonly used operations */
#define A_OR_B	  ABC|ANBC|NABC | ABNC|ANBNC|NABNC
#define A_OR_C	  ABC|NABC|ABNC | ANBC|NANBC|ANBNC
#define A_XOR_C   NABC|ABNC   | NANBC|ANBNC
#define A_TO_D	  ABC|ANBC|ABNC|ANBNC

#define BC0B_DEST 8
#define BC0B_SRCC 9
#define BC0B_SRCB   10
#define BC0B_SRCA 11
#define BC0F_DEST 0x100
#define BC0F_SRCC 0x200
#define BC0F_SRCB 0x400
#define BC0F_SRCA 0x800

#define BC1F_DESC   2	      /* blitter descend direction */

#define DEST 0x100
#define SRCC 0x200
#define SRCB 0x400
#define SRCA 0x800

#define ASHIFTSHIFT  12       /* bits to right align ashift value */
#define BSHIFTSHIFT  12       /* bits to right align bshift value */

/* definations for blitter control register 1 */
#define LINEMODE     0x1
#define FILL_OR      0x8
#define FILL_XOR     0x10
#define FILL_CARRYIN 0x4
#define ONEDOT	     0x2      /* one dot per horizontal line */
#define OVFLAG	     0x20
#define SIGNFLAG     0x40
#define BLITREVERSE  0x2

#define SUD	     0x10
#define SUL	     0x8
#define AUL	     0x4

#define OCTANT8   24
#define OCTANT7   4
#define OCTANT6   12
#define OCTANT5   28
#define OCTANT4   20
#define OCTANT3   8
#define OCTANT2   0
#define OCTANT1   16

/* stuff for blit qeuer */
struct bltnode
{
    struct  bltnode *n;
    int     (*function)();
    char    stat;
    short   blitsize;
    short   beamsync;
    int     (*cleanup)();
};

/* defined bits for bltstat */
#define CLEANUP 0x40
#define CLEANME CLEANUP

#endif	/* HARDWARE_BLIT_H */


struct Custom {
    UWORD   bltddat;
    UWORD   dmaconr;
    UWORD   vposr;
    UWORD   vhposr;
    UWORD   dskdatr;
    UWORD   joy0dat;
    UWORD   joy1dat;
    UWORD   clxdat;
    UWORD   adkconr;
    UWORD   pot0dat;
    UWORD   pot1dat;
    UWORD   potinp;
    UWORD   serdatr;
    UWORD   dskbytr;
    UWORD   intenar;
    UWORD   intreqr;
    APTR    dskpt;
    UWORD   dsklen;
    UWORD   dskdat;
    UWORD   refptr;
    UWORD   vposw;
    UWORD   vhposw;
    UWORD   copcon;
    UWORD   serdat;
    UWORD   serper;
    UWORD   potgo;
    UWORD   joytest;
    UWORD   strequ;
    UWORD   strvbl;
    UWORD   strhor;
    UWORD   strlong;
    UWORD   bltcon0;
    UWORD   bltcon1;
    UWORD   bltafwm;
    UWORD   bltalwm;
    APTR    bltcpt;
    APTR    bltbpt;
    APTR    bltapt;
    APTR    bltdpt;
    UWORD   bltsize;
    UBYTE   pad2d;
    UBYTE   bltcon0l;	/* low 8 bits of bltcon0, write only */
    UWORD   bltsizv;
    UWORD   bltsizh;	/* 5e */
    UWORD   bltcmod;
    UWORD   bltbmod;
    UWORD   bltamod;
    UWORD   bltdmod;
    UWORD   pad34[4];
    UWORD   bltcdat;
    UWORD   bltbdat;
    UWORD   bltadat;
    UWORD   pad3b[3];
    UWORD   deniseid;	/* 7c */
    UWORD   dsksync;
    ULONG   cop1lc;
    ULONG   cop2lc;
    UWORD   copjmp1;
    UWORD   copjmp2;
    UWORD   copins;
    UWORD   diwstrt;
    UWORD   diwstop;
    UWORD   ddfstrt;
    UWORD   ddfstop;
    UWORD   dmacon;
    UWORD   clxcon;
    UWORD   intena;
    UWORD   intreq;
    UWORD   adkcon;
    struct  AudChannel {
      UWORD *ac_ptr; /* ptr to start of waveform data */
      UWORD ac_len;	/* length of waveform in words */
      UWORD ac_per;	/* sample period */
      UWORD ac_vol;	/* volume */
      UWORD ac_dat;	/* sample pair */
      UWORD ac_pad[2];	/* unused */
    } aud[4];
    APTR    bplpt[8];
    UWORD   bplcon0;
    UWORD   bplcon1;
    UWORD   bplcon2;
    UWORD   bplcon3;
    UWORD   bpl1mod;
    UWORD   bpl2mod;
    UWORD   bplcon4;
    UWORD   clxcon2;
    UWORD   bpldat[8];
    APTR    sprpt[8];
    struct  SpriteDef {
      UWORD pos;
      UWORD ctl;
      UWORD dataa;
      UWORD datab;
    } spr[8];
    UWORD   color[32];
    UWORD htotal;
    UWORD hsstop;
    UWORD hbstrt;
    UWORD hbstop;
    UWORD vtotal;
    UWORD vsstop;
    UWORD vbstrt;
    UWORD vbstop;
    UWORD sprhstrt;
    UWORD sprhstop;
    UWORD bplhstrt;
    UWORD bplhstop;
    UWORD hhposw;
    UWORD hhposr;
    UWORD beamcon0;
    UWORD hsstrt;
    UWORD vsstrt;
    UWORD hcenter;
    UWORD diwhigh;	/* 1e4 */
    UWORD padf3[11];
    UWORD fmode;
};


typedef volatile struct Custom* custom_t;

#define CUSTOM ((custom_t)0xdff000)
