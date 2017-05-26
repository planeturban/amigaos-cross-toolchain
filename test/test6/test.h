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

#define __section(x)
#define DISK_SECTOR_ALIGN
#define NOINLINE

extern int16_t game_cameraX;
extern int16_t game_screenScrollX;
extern frame_buffer_t game_onScreenBuffer;
extern frame_buffer_t game_offScreenBuffer;
extern frame_buffer_t game_scoreBoardFrameBuffer;
extern uint16_t game_over;
extern uint16_t game_numPlayers;
extern uint16_t game_wave;
extern uint16_t game_nextWave;
extern uint32_t game_player1Score;
extern uint32_t game_player2Score;

#define GAME_PAVEMENT_START 66

#define SPRITE_SHEET_WIDTH  272
#define SPRITE_SHEET_HEIGHT 594
#define SPRITE_SHEET_WIDTH_BYTES (SPRITE_SHEET_WIDTH/8)


#define TILE_SHEET_WIDTH  272
#define TILE_SHEET_HEIGHT 112
#define TILE_SHEET_WIDTH_BYTES (TILE_SHEET_WIDTH/8)

#define SCREEN_WIDTH_BYTES  (SCREEN_WIDTH/8)

#define FRAME_BUFFER_WIDTH_BYTES  (FRAME_BUFFER_WIDTH/8)
#define SCREEN_WIDTH_WORDS  (SCREEN_WIDTH/16)
#define SCREEN_BIT_DEPTH    5
#define SCREEN_NUM_COLORS   (1<<SCREEN_BIT_DEPTH)
#define SCREEN_RES	    8 // 8=lo resolution, 4=hi resolution
#define RASTER_X_START	    (0x81+((320-SCREEN_WIDTH)/2)) /* hard coded coordinates from hardware manual */
#define RASTER_Y_START	    0x25
#define RASTER_X_STOP	    RASTER_X_START+SCREEN_WIDTH
#define GAME_RASTER_Y_STOP	    RASTER_Y_START+PLAYAREA_HEIGHT+SCOREBOARD_HEIGHT
#define SCREEN_RASTER_Y_STOP  RASTER_Y_START+SCREEN_HEIGHT
#define SCOREBOARD_HEIGHT   43
#define GAME_PAVEMENT_START 66

#define WORLD_HEIGHT        (MAP_TILE_HEIGHT*TILE_HEIGHT)
#define WORLD_WIDTH         (MAP_TILE_WIDTH*TILE_WIDTH)
#define SCROLL_PIXELS       4


#define MAP_TILE_WIDTH      100
#define MAP_TILE_HEIGHT     13
#define TILE_WIDTH          16
#define TILE_HEIGHT         16

#define SCREEN_WIDTH          320
#define SCREEN_HEIGHT          256
#define PLAYAREA_HEIGHT        MAP_TILE_HEIGHT*TILE_HEIGHT

#ifndef __OBJECT_H
#define __OBJECT_H

#define OBJECT_MAX_OBJECTS    12
#define OBJECT_PHYSICS_FACTOR 2
#define OBJECT_WIDTH 32

typedef enum {
  SPRITE_PLAYER1_STAND_RIGHT,
  SPRITE_PLAYER1_RUN_RIGHT_1,
  SPRITE_PLAYER1_RUN_RIGHT_2,
  SPRITE_PLAYER1_RUN_RIGHT_3,
  SPRITE_PLAYER1_RUN_RIGHT_4,
  SPRITE_PLAYER1_STAND_LEFT,
  SPRITE_PLAYER1_RUN_LEFT_1,
  SPRITE_PLAYER1_RUN_LEFT_2,
  SPRITE_PLAYER1_RUN_LEFT_3,
  SPRITE_PLAYER1_RUN_LEFT_4,
  SPRITE_PLAYER1_PUNCH_LEFT_1,
  SPRITE_PLAYER1_PUNCH_LEFT_2,
  SPRITE_PLAYER1_PUNCH_RIGHT_1,
  SPRITE_PLAYER1_PUNCH_RIGHT_2,
  SPRITE_PLAYER1_HIT_LEFT,
  SPRITE_PLAYER1_HIT_RIGHT,

  SPRITE_PLAYER2_STAND_RIGHT,
  SPRITE_PLAYER2_RUN_RIGHT_1,
  SPRITE_PLAYER2_RUN_RIGHT_2,
  SPRITE_PLAYER2_RUN_RIGHT_3,
  SPRITE_PLAYER2_RUN_RIGHT_4,
  SPRITE_PLAYER2_STAND_LEFT,
  SPRITE_PLAYER2_RUN_LEFT_1,
  SPRITE_PLAYER2_RUN_LEFT_2,
  SPRITE_PLAYER2_RUN_LEFT_3,
  SPRITE_PLAYER2_RUN_LEFT_4,   
  SPRITE_PLAYER2_PUNCH_LEFT_1,
  SPRITE_PLAYER2_PUNCH_LEFT_2,
  SPRITE_PLAYER2_PUNCH_RIGHT_1,
  SPRITE_PLAYER2_PUNCH_RIGHT_2,
  SPRITE_PLAYER2_HIT_LEFT,
  SPRITE_PLAYER2_HIT_RIGHT,    
  SPRITE_PLAYER2_KICK_LEFT_1,
  SPRITE_PLAYER2_KICK_LEFT_2,
  SPRITE_PLAYER2_KICK_LEFT_3,  
  SPRITE_PLAYER2_KICK_RIGHT_1,
  SPRITE_PLAYER2_KICK_RIGHT_2,
  SPRITE_PLAYER2_KICK_RIGHT_3,      

  
  SPRITE_PLAYER3_STAND_RIGHT,
  SPRITE_PLAYER3_RUN_RIGHT_1,
  SPRITE_PLAYER3_RUN_RIGHT_2,
  SPRITE_PLAYER3_RUN_RIGHT_3,
  SPRITE_PLAYER3_RUN_RIGHT_4,
  SPRITE_PLAYER3_STAND_LEFT,
  SPRITE_PLAYER3_RUN_LEFT_1,
  SPRITE_PLAYER3_RUN_LEFT_2,
  SPRITE_PLAYER3_RUN_LEFT_3,
  SPRITE_PLAYER3_RUN_LEFT_4 ,
  SPRITE_PLAYER3_PUNCH_LEFT_1,
  SPRITE_PLAYER3_PUNCH_LEFT_2,
  SPRITE_PLAYER3_PUNCH_RIGHT_1,
  SPRITE_PLAYER3_PUNCH_RIGHT_2,
  SPRITE_PLAYER3_HIT_LEFT,
  SPRITE_PLAYER3_HIT_RIGHT,
  SPRITE_PLAYER3_KICK_LEFT_1,
  SPRITE_PLAYER3_KICK_LEFT_2,
  SPRITE_PLAYER3_KICK_LEFT_3,  
  SPRITE_PLAYER3_KICK_RIGHT_1,
  SPRITE_PLAYER3_KICK_RIGHT_2,
  SPRITE_PLAYER3_KICK_RIGHT_3,      

  
  SPRITE_PLAYER4_STAND_RIGHT,
  SPRITE_PLAYER4_RUN_RIGHT_1,
  SPRITE_PLAYER4_RUN_RIGHT_2,
  SPRITE_PLAYER4_RUN_RIGHT_3,
  SPRITE_PLAYER4_RUN_RIGHT_4,
  SPRITE_PLAYER4_STAND_LEFT,
  SPRITE_PLAYER4_RUN_LEFT_1,
  SPRITE_PLAYER4_RUN_LEFT_2,
  SPRITE_PLAYER4_RUN_LEFT_3,
  SPRITE_PLAYER4_RUN_LEFT_4 ,
  SPRITE_PLAYER4_PUNCH_LEFT_1,
  SPRITE_PLAYER4_PUNCH_LEFT_2,
  SPRITE_PLAYER4_PUNCH_RIGHT_1,
  SPRITE_PLAYER4_PUNCH_RIGHT_2,
  SPRITE_PLAYER4_HIT_LEFT,
  SPRITE_PLAYER4_HIT_RIGHT,
  
  SPRITE_BOSS_STAND_RIGHT,
  SPRITE_BOSS_RUN_RIGHT_1,
  SPRITE_BOSS_RUN_RIGHT_2,
  SPRITE_BOSS_RUN_RIGHT_3,
  SPRITE_BOSS_RUN_RIGHT_4,
  SPRITE_BOSS_STAND_LEFT,
  SPRITE_BOSS_RUN_LEFT_1,
  SPRITE_BOSS_RUN_LEFT_2,
  SPRITE_BOSS_RUN_LEFT_3,
  SPRITE_BOSS_RUN_LEFT_4 ,
  SPRITE_BOSS_ATTACK_LEFT_1,
  SPRITE_BOSS_ATTACK_LEFT_2,
  SPRITE_BOSS_ATTACK_LEFT_3,  
  SPRITE_BOSS_ATTACK_RIGHT_1,
  SPRITE_BOSS_ATTACK_RIGHT_2,
  SPRITE_BOSS_ATTACK_RIGHT_3,  
  SPRITE_BOSS_HIT_LEFT,
  SPRITE_BOSS_HIT_RIGHT,      

  SPRITE_HAND,
  SPRITE_DOOR,
  SPRITE_JOYSTICK1,
  SPRITE_JOYSTICK2,
  SPRITE_GAMEOVER,
  SPRITE_GAMECOMPLETE,  

  SPRITE_PHONEBOOTH,
  SPRITE_PHONEBOOTH_BROKEN,
  SPRITE_PHONEBOOTH_JUNK1,
  SPRITE_PHONEBOOTH_JUNK2,
  SPRITE_PHONEBOOTH_JUNK3,
  
  SPRITE_POSTBOX,
  SPRITE_POSTBOX_BROKEN,
  SPRITE_POSTBOX_JUNK1,
  SPRITE_POSTBOX_JUNK2,
  SPRITE_POSTBOX_JUNK3,  

  SPRITE_BONUS_BURGER,
  SPRITE_BONUS_COLA,
  SPRITE_STAR,  
} sprite_id_t;

typedef enum {
  OBJECT_ID_ENEMY = 0,
  OBJECT_ID_PLAYER1 = 1,
  OBJECT_ID_PLAYER2 = 2,
  OBJECT_ID_BOSS = 3,  
  OBJECT_ID_HAND = 4,
  OBJECT_ID_DOOR = 5,
  OBJECT_ID_JOYSTICK = 6,
  OBJECT_ID_GAMEOVER = 7,
  OBJECT_ID_GAMECOMPLETE = 8,  
  OBJECT_ID_PHONEBOOTH = 9,
  OBJECT_ID_POSTBOX = 10,  
  OBJECT_ID_JUNK = 11,
  OBJECT_ID_BONUS = 12,
} object_id_t;

typedef enum {
  OBJECT_STAND_RIGHT = 0,
  OBJECT_RUN_RIGHT = 1,
  OBJECT_RUN_LEFT = 2,
  OBJECT_STAND_LEFT = 3,
  OBJECT_PUNCH_LEFT1 = 4,
  OBJECT_PUNCH_LEFT2 = 5,
  OBJECT_KICK_LEFT = 6,
  OBJECT_PUNCH_RIGHT1 = 7,
  OBJECT_PUNCH_RIGHT2 = 8,
  OBJECT_KICK_RIGHT = 9,    
  OBJECT_HIT_LEFT = 10,
  OBJECT_HIT_RIGHT = 11,

} object_action_t;

typedef enum {
  OBJECT_ANIM_PLAYER1_STAND_RIGHT = 0,
  OBJECT_ANIM_PLAYER1_RUN_RIGHT = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_PLAYER1_STAND_LEFT = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_PLAYER1_RUN_LEFT  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_PLAYER1_PUNCH_LEFT1  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_PLAYER1_PUNCH_LEFT2  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_PLAYER1_PUNCH_RIGHT1  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_PLAYER1_PUNCH_RIGHT2  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,
  OBJECT_ANIM_PLAYER1_HIT_LEFT  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_PLAYER1_HIT_RIGHT  = OBJECT_ANIM_PLAYER1_STAND_RIGHT + OBJECT_HIT_RIGHT,

  OBJECT_ANIM_PLAYER2_STAND_RIGHT = OBJECT_ANIM_PLAYER1_HIT_RIGHT + 1,
  OBJECT_ANIM_PLAYER2_RUN_RIGHT = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_PLAYER2_STAND_LEFT = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_PLAYER2_RUN_LEFT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_PLAYER2_PUNCH_LEFT1  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_PLAYER2_PUNCH_LEFT2  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_PLAYER2_KICK_LEFT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_KICK_LEFT,
  OBJECT_ANIM_PLAYER2_PUNCH_RIGHT1  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_PLAYER2_PUNCH_RIGHT2  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,
  OBJECT_ANIM_PLAYER2_KICK_RIGHT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_KICK_RIGHT,
  OBJECT_ANIM_PLAYER2_HIT_LEFT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_PLAYER2_HIT_RIGHT  = OBJECT_ANIM_PLAYER2_STAND_RIGHT + OBJECT_HIT_RIGHT,

  
  OBJECT_ANIM_PLAYER3_STAND_RIGHT = OBJECT_ANIM_PLAYER2_HIT_RIGHT + 1,
  OBJECT_ANIM_PLAYER3_RUN_RIGHT = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_PLAYER3_STAND_LEFT = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_PLAYER3_RUN_LEFT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_PLAYER3_PUNCH_LEFT1  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_PLAYER3_PUNCH_LEFT2  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_PLAYER3_KICK_LEFT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_KICK_LEFT,
  OBJECT_ANIM_PLAYER3_PUNCH_RIGHT1  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_PLAYER3_PUNCH_RIGHT2  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,
  OBJECT_ANIM_PLAYER3_KICK_RIGHT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_KICK_RIGHT,  
  OBJECT_ANIM_PLAYER3_HIT_LEFT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_PLAYER3_HIT_RIGHT  = OBJECT_ANIM_PLAYER3_STAND_RIGHT + OBJECT_HIT_RIGHT,

  OBJECT_ANIM_PLAYER4_STAND_RIGHT = OBJECT_ANIM_PLAYER3_HIT_RIGHT + 1,
  OBJECT_ANIM_PLAYER4_RUN_RIGHT = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_PLAYER4_STAND_LEFT = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_PLAYER4_RUN_LEFT  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_PLAYER4_PUNCH_LEFT1  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_PLAYER4_PUNCH_LEFT2  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_PLAYER4_PUNCH_RIGHT1  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_PLAYER4_PUNCH_RIGHT2  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,  
  OBJECT_ANIM_PLAYER4_HIT_LEFT  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_PLAYER4_HIT_RIGHT  = OBJECT_ANIM_PLAYER4_STAND_RIGHT + OBJECT_HIT_RIGHT,

  OBJECT_ANIM_BOSS_STAND_RIGHT = OBJECT_ANIM_PLAYER4_HIT_RIGHT + 1,
  OBJECT_ANIM_BOSS_RUN_RIGHT = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_RUN_RIGHT,
  OBJECT_ANIM_BOSS_STAND_LEFT = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_STAND_LEFT,
  OBJECT_ANIM_BOSS_RUN_LEFT  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_RUN_LEFT,
  OBJECT_ANIM_BOSS_ATTACK_LEFT1  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_PUNCH_LEFT1,
  OBJECT_ANIM_BOSS_ATTACK_LEFT2  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_PUNCH_LEFT2,
  OBJECT_ANIM_BOSS_ATTACK_RIGHT1  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_PUNCH_RIGHT1,
  OBJECT_ANIM_BOSS_ATTACK_RIGHT2  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_PUNCH_RIGHT2,  
  OBJECT_ANIM_BOSS_HIT_LEFT  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_HIT_LEFT,
  OBJECT_ANIM_BOSS_HIT_RIGHT  = OBJECT_ANIM_BOSS_STAND_RIGHT + OBJECT_HIT_RIGHT,  

  OBJECT_ANIM_HAND = OBJECT_ANIM_BOSS_HIT_RIGHT + 1,
  OBJECT_ANIM_DOOR = OBJECT_ANIM_HAND + 1,
  OBJECT_ANIM_JOYSTICK = OBJECT_ANIM_DOOR + 1,
  OBJECT_ANIM_GAMEOVER = OBJECT_ANIM_JOYSTICK + 1,
  OBJECT_ANIM_GAMECOMPLETE = OBJECT_ANIM_GAMEOVER + 1,  

  OBJECT_ANIM_PHONEBOOTH = OBJECT_ANIM_GAMECOMPLETE + 1,
  OBJECT_ANIM_PHONEBOOTH_BROKEN = OBJECT_ANIM_PHONEBOOTH + 1,

  OBJECT_ANIM_PHONEBOOTH_JUNK1 = OBJECT_ANIM_PHONEBOOTH_BROKEN + 1,
  OBJECT_ANIM_PHONEBOOTH_JUNK2 = OBJECT_ANIM_PHONEBOOTH_JUNK1 + 1,
  OBJECT_ANIM_PHONEBOOTH_JUNK3 = OBJECT_ANIM_PHONEBOOTH_JUNK2 + 1,

  OBJECT_ANIM_POSTBOX = OBJECT_ANIM_PHONEBOOTH_JUNK3 + 1,
  OBJECT_ANIM_POSTBOX_BROKEN = OBJECT_ANIM_POSTBOX + 1,

  OBJECT_ANIM_POSTBOX_JUNK1 = OBJECT_ANIM_POSTBOX_BROKEN + 1,
  OBJECT_ANIM_POSTBOX_JUNK2 = OBJECT_ANIM_POSTBOX_JUNK1 + 1,
  OBJECT_ANIM_POSTBOX_JUNK3 = OBJECT_ANIM_POSTBOX_JUNK2 + 1,

  
  OBJECT_ANIM_BONUS_BURGER = OBJECT_ANIM_POSTBOX_JUNK3 + 1,
  OBJECT_ANIM_BONUS_COLA = OBJECT_ANIM_BONUS_BURGER + 1,

  OBJECT_ANIM_STAR = OBJECT_ANIM_BONUS_COLA + 1,      
  
} object_animation_id_t;

typedef enum {
  FACING_LEFT,
  FACING_RIGHT
} object_direction_t;

typedef enum {
  OBJECT_STATE_ALIVE,
  OBJECT_STATE_REMOVED,
  OBJECT_STATE_DEAD,
  OBJECT_STATE_HIT,
  OBJECT_STATE_FLASHING
} object_state_t;

typedef struct {
  int16_t start;
  int16_t stop;
  int16_t speed;
  object_direction_t facing;
} object_animation_t;

typedef struct {
  int16_t x;
  int16_t y;
  int16_t w;
  int16_t h;
  int16_t dx;
  int16_t dy;
} object_image_t;

typedef struct {
  int16_t x;
  int16_t y;
  int16_t dx;
  int16_t dy;
  int16_t ix;
} object_velocity_t;

typedef enum {
  OBJECT_CLASS_FIGHTER,
  OBJECT_CLASS_THING,
  OBJECT_CLASS_JUNK,  
  OBJECT_CLASS_DECORATION
} object_class_t;

typedef struct {
  int16_t x;
  int16_t y;
  int16_t w;
  int16_t h;
} object_position_t;

typedef struct {
  object_position_t positions[2];
  object_position_t* position;
} object_save_t;

typedef struct object {
  uint16_t id;
  uint16_t class;
  void* data;
  struct object* next;
  struct object* prev;
  int16_t _x;
  int16_t _y;
  int16_t _z;
  int16_t _px;
  int16_t _py;
  object_velocity_t velocity;
  int16_t imageIndex;
  object_image_t* image;
  uint16_t baseId;
  uint16_t animId;
  uint16_t actionId;
  object_animation_t* anim;  
  object_save_t save;
  uint16_t frameCounter;
  uint16_t deadRenderCount;
  uint16_t _state;
  void (*update)(uint16_t deltaT, struct object* ptr);
  void (*freeData)(void* data);
  uint16_t visible;
  uint16_t tileRender;

  uint16_t widthOffset;
  uint16_t width;

  uint16_t collidable;
} object_t;


typedef struct {
  object_t* up;
  object_t* down;
  object_t* left;
  object_t* right;
} object_collision_t;


extern object_image_t object_imageAtlas[];
extern object_animation_t object_animations[];
extern object_t* object_activeList;
extern int16_t object_count;
extern object_t* object_zBuffer[OBJECT_MAX_OBJECTS];
//extern uint16_t object_zBufferValid;

void
object_init(void);
object_t*
object_add(uint16_t id, uint16_t class, int16_t x, int16_t y, int16_t dx, int16_t anim, void (*update)(uint16_t deltaT, object_t* ptr), void* data, void (*freeData)(void*));
void
object_free(object_t* ptr);
void
object_render(frame_buffer_t fb, uint16_t deltaT);
void
object_restoreBackground(frame_buffer_t fb);
void
object_updatePosition(uint16_t deltaT, object_t* ptr);
void
object_setAction(object_t* ptr, object_action_t action);

inline static int16_t
object_x(object_t* ptr) {
  return ptr->_x;
}

inline static int16_t
object_y(object_t* ptr) {
  return ptr->_y;
}

inline static int16_t
object_z(object_t* ptr) {
  return ptr->_z;
}

inline static int16_t
object_px(object_t* ptr) {
  return ptr->_px;
}

inline static int16_t
object_py(object_t* ptr) {
  return ptr->_py;
}

inline static uint16_t
object_get_state(object_t* ptr) {
  return ptr->_state;
}

inline static void
object_set_state(object_t* ptr, uint16_t state) {  
  ptr->_state = state;
  if (state == OBJECT_STATE_ALIVE) {
    if (ptr->class == OBJECT_CLASS_FIGHTER || ptr->class == OBJECT_CLASS_THING) {
      ptr->collidable = 1;
      return;
    }
  } 
  ptr->collidable = 0;
}

#define object_screenx(ptr) (ptr->image->dx + 0xf + ptr->_x-game_cameraX-game_screenScrollX)
#define object_screeny(ptr) (ptr->image->dy + (ptr->_y-ptr->image->h))

inline static void
object_set_px(object_t* ptr, int16_t px)
{
  ptr->_px = px;  
  int16_t oldX = ptr->_x - game_cameraX;
  ptr->_x = ptr->_px / OBJECT_PHYSICS_FACTOR;
  
  if (oldX + OBJECT_WIDTH < SCREEN_WIDTH && (ptr->_x + OBJECT_WIDTH - game_cameraX)>= SCREEN_WIDTH) {
    ptr->_x = game_cameraX + (SCREEN_WIDTH - OBJECT_WIDTH - 1);
    ptr->_px = ptr->_x * OBJECT_PHYSICS_FACTOR;
  } else if (oldX >= 0 && ptr->_x - game_cameraX < 0) {
    ptr->_x = game_cameraX;
    ptr->_px = ptr->_x * OBJECT_PHYSICS_FACTOR;
  }  
}

inline static void
object_set_py(object_t* ptr, int16_t py)
{
  int16_t oldY = ptr->_y;
  ptr->_py = py;  
  ptr->_y = ptr->_py / OBJECT_PHYSICS_FACTOR;


  if (ptr->_y >= PLAYAREA_HEIGHT) {
    ptr->_y = PLAYAREA_HEIGHT-2;
    ptr->_py = ptr->_y * OBJECT_PHYSICS_FACTOR;
  }

  if (oldY >= GAME_PAVEMENT_START && ptr->_y < GAME_PAVEMENT_START) {
    ptr->_y = GAME_PAVEMENT_START;
    ptr->_py = ptr->_y * OBJECT_PHYSICS_FACTOR;
  }
}

inline static void
object_set_py_no_checks(object_t* ptr, int16_t py)
{
  ptr->_py = py;  
  ptr->_y = ptr->_py / OBJECT_PHYSICS_FACTOR;
}

inline static void
object_set_z(object_t* ptr, int16_t z)
{
  ptr->_z = z;
}

void
object_setAnim(object_t* ptr, int16_t anim);

void
object_clear(frame_buffer_t fb, int16_t ox, int16_t oy, int16_t ow, int16_t oh);

int16_t
object_collision(int16_t deltaT, object_t* a, object_collision_t* collision, uint16_t thresholdx, uint16_t thresholdy);
#endif



#ifndef LEVEL_H
#define LEVEL_H

#define LEVEL_NUM_LEVELS 1

typedef struct {
  uint16_t tileAddresses[MAP_TILE_WIDTH][16];
  uint8_t spriteBitplanes[SPRITE_SHEET_WIDTH_BYTES*SCREEN_BIT_DEPTH*SPRITE_SHEET_HEIGHT];

#ifndef GAME_ONE_BITPLANE_SPRITE_MASK
  uint8_t spriteMask[SPRITE_SHEET_WIDTH_BYTES*SCREEN_BIT_DEPTH*SPRITE_SHEET_HEIGHT];
#else
  uint8_t spriteMask[SPRITE_SHEET_WIDTH_BYTES*SPRITE_SHEET_HEIGHT];
#endif

  uint8_t tileBitplanes[TILE_SHEET_WIDTH_BYTES*SCREEN_BIT_DEPTH*TILE_SHEET_HEIGHT];
  uint16_t palette[32];
  uint16_t clouds;
  uint16_t moduleIndex;
  //  conductor_instruction_t* instructions;
#ifdef GAME_RECORDING
  uint8_t recordData[sizeof(record_t)];
  record_t* record;
#endif
  void (*initFunctor)(void);
#if 0
  void (*effectFunctor)(frame_buffer_t fb);
#endif
} level_t DISK_SECTOR_ALIGN;

extern level_t level;

void
level_load(uint16_t index);

#endif

typedef struct {
  frame_buffer_t dest;
  frame_buffer_t source;
  uint16_t mod;
  uint16_t size;  
} gfx_blit_t;


void 
gfx_ctor(void);
void
gfx_screenWidthBitBlit(frame_buffer_t dest, int16_t sx, int16_t sy, int16_t dx, int16_t dy, int16_t w, int16_t h);
void
gfx_screenWidthBitBlitNoMask(frame_buffer_t dest, frame_buffer_t src, int16_t sx, int16_t sy, int16_t dx, int16_t dy, int16_t w, int16_t h);
void
gfx_fillRect(frame_buffer_t fb, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void
gfx_fillRectSmallScreen(frame_buffer_t fb, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void
gfx_renderSprite(frame_buffer_t dest, int16_t sx, int16_t sy, int16_t dx, int16_t dy, int16_t w, int16_t h);
void
gfx_renderSpriteNoMask(frame_buffer_t dest, int16_t sx, int16_t sy, int16_t dx, int16_t dy, int16_t w, int16_t h);
void
gfx_renderSprite16NoShift(frame_buffer_t dest, int16_t sx, int16_t sy, int16_t dx, int16_t dy, int16_t w, int16_t h);
void
gfx_saveSprite(frame_buffer_t source, frame_buffer_t dest, gfx_blit_t* blit, int16_t dx, int16_t dy, int16_t w, int16_t h);
void
gfx_saveSprite16(frame_buffer_t source, frame_buffer_t dest, gfx_blit_t* blit, int16_t dx, int16_t dy, int16_t h);
void
gfx_restoreSprite(gfx_blit_t* blit);
void
gfx_setupQuickRenderSprite(void);
void
gfx_quickRenderSprite(frame_buffer_t dest, int16_t sx, int16_t sy, int16_t dx, int16_t dy);
void
gfx_renderTile(frame_buffer_t dest, int16_t sx, int16_t sy, frame_buffer_t tile);
void
gfx_renderTile(frame_buffer_t fb, int16_t x, int16_t y, frame_buffer_t tile);
void
gfx_setupRenderTile(void);
void
gfx_quickRenderTile(frame_buffer_t dest, int16_t x, int16_t y, frame_buffer_t tile);
void
gfx_renderPartialTile(frame_buffer_t dest, int16_t x, int16_t y, uint16_t h, frame_buffer_t tile);
void
gfx_splitBlitNoMask(frame_buffer_t dest, frame_buffer_t src, int16_t dx, int16_t dy, int16_t sx, int16_t sy, int16_t w, int16_t _h);
