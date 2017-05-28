#ifndef _IT2_DEFINES_H_
#define _IT2_DEFINES_H_

#include "IT2_PText_Defines.h"

#define FLAG_UNKNOWN    0
#define FLAG_KNOWN      0x80
#define FLAG_TERRA      20
#define FLAG_KLEGAN     8
#define FLAG_REMALO     96
#define FLAG_CARDAC     10
#define FLAG_FERAGI     67
#define FLAG_BAROJA     11
#define FLAG_VOLKAN     27
#define FLAG_OTHER      1
#define FLAG_MAQUES     12
#define FLAG_CIV_MASK   (FLAG_TERRA | FLAG_KLEGAN | FLAG_REMALO | FLAG_CARDAC | FLAG_FERAGI | FLAG_BAROJA | FLAG_VOLKAN | FLAG_OTHER | FLAG_MAQUES)

#define WFLAG_CEBORC    2
#define WFLAG_DCON      3
#define WFLAG_FIELD     4
#define WFLAG_JAHADR    5

#define MASK_LTRUPPS    0x0f
#define MASK_SIEDLER    0xf0

#define RDELAY          1
#define LOGOSIZE        14500
#define PAUSE           85

#define GFLAG_EXPLORE   1
#define GFLAG_ATTACK    2

#define SHIPFLAG_NONE   0
#define SHIPFLAG_WATER  1

#define LEVEL_DIED      0
#define LEVEL_UNKNOWN   1
#define LEVEL_PEACE     2
#define LEVEL_WAR       3
#define LEVEL_ALLIANZ   4
#define LEVEL_NO_ALLIANZ  5
#define LEVEL_COLDWAR   6

#define TYPE_PLANET     2
#define TYPE_SHIP       4
#define TYPE_STARGATE   16
#define TYPE_WORMHOLE   32
#define SHIPTYPE_FLEET  200

#define CLASS_STONES    0   /*T*/
#define CLASS_GAS       1   /*G*/
#define CLASS_WATER     2   /*W*/
#define CLASS_SATURN    3   /*S*/
#define CLASS_HALFEARTH 4   /*H*/
#define CLASS_DESERT    5   /*D*/
#define CLASS_EARTH     6   /*M*/
#define CLASS_PHANTOM   7   /*P*/
#define CLASS_ICE       8   /*I*/

#define WEAPON_GUN       1
#define WEAPON_LASER     3
#define WEAPON_PHASER    5
#define WEAPON_DISRUPTOR 7
#define WEAPON_PTORPEDO  9

#define MODE_REFRESH    0
#define MODE_REDRAW     1
#define MODE_FLEET      2
#define MODE_STARGATE   3
#define MODE_ONCE       4
#define MODE_ALL        5
#define MODE_OFFENSIV   8
#define MODE_DEFENSIV   9
#define MODE_SHIPS      10
#define MODE_TERRITORIUM  11
#define MODE_BELEIDIGUNG  12
#define MODE_MONEY      13
#define MODE_FORCE      14

#define STATE_ALL_OCC   1
#define STATE_ENEMY     2
#define STATE_TACTICAL  3

#define SCREEN_PLANET   1
#define SCREEN_INVENTION  2
#define SCREEN_HISCORE  3
#define SCREEN_TECH     4

#define TARGET_POSITION  127
#define TARGET_STARGATE  26
#define TARGET_ENEMY_SHIP  126

#define INFLATION       ((double) 1.03)

#define MODULES         4

#define MAXSYSTEMS      25
#define MAXMAQUES       5
#define MAXHOLES        3

#define SOUNDS          4
#define CACHES          4
#define IMAGES          2
#define GADGETS         3
#define FONTS           5

#define MAXPLANETS      11
#define MAXCIVS         9

#define PATHS           11

#define MAXPMONEY       102000L
#define MAXSTR          900

#define ROTATE_PX       1
#define ROTATE_PY       2
#define ROTATE_PZ       4
#define ROTATE_NX       8
#define ROTATE_NY       16
#define ROTATE_NZ       32

#define false           FALSE
#define true            TRUE
#define bool            BOOL

#define _COLOR_CMAP_TEXT_ (0x434D4150)

#define LMB_PRESSED     ((*LData & 64) == 0)
#define LMB_NOTPRESSED  ((*LData & 64) != 0)
#define RMB_PRESSED     ((*RData & 1024) == 0)
#define RMB_NOTPRESSED  ((*RData & 1024) != 0)

#endif
