#ifndef _IT2_TYPES_H_
#define _IT2_TYPES_H_

#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/diskfont.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <math.h>
#include <hardware/custom.h>
#include <graphics/gfxmacros.h>
#include <utility/tagitem.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "IT2_Defines.h"

typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned long   uint32;
typedef signed char     sint8;
typedef signed short    sint16;
typedef signed long     sint32;


//typedef struct TagArr { uint32	data[14]; } TagArr;
typedef struct TagArr { struct TagItem data[7]; } TagArr;

typedef struct PenArr { uint16      data[13]; } PenArr;

typedef struct ColSpecArr { sint16  data[5]; } ColSpecArr;

typedef struct StrArr           { char  data[MAXSYSTEMS+1][12]; } StrArr;
typedef struct StrArr11         { char  data[12][15];           } StrArr11;
typedef struct StrArr16         { char  data[17][60];           } StrArr16;
typedef struct StrArr42         { char  data[43][30];           } StrArr42;
typedef struct StrArrMAXPLANETS { char  data[MAXSYSTEMS+1][6];  } StrArrMAXPLANETS;

typedef struct ByteArr22 { uint8    data[23]; } ByteArr22;
typedef struct ByteArr42 { uint8    data[43]; } ByteArr42;

typedef struct LongArr42 { sint32   data[43]; } LongArr42;

typedef struct WordArr32 { uint16   data[35]; } WordArr32;

typedef struct r_Coords { double    data[41]; } r_Coords;

typedef struct PlaneArr { PLANEPTR  data[8]; } PlaneArr;

typedef struct FontArr16 { uint8    data[17]; } FontArr16;

typedef struct ITBitMap {
    uint16          BytesPerRow, Rows;
    uint8           Flags, Depth;
    uint16          pad;
    PLANEPTR        PPtr[8];
    APTR            MemA;
    uint32          MemL;
} ITBitMap;

typedef struct r_ShipData {
    uint8           MaxLoad, MaxShield, MaxMove, WeaponPower;
} r_ShipData;

typedef struct r_ShipHeader {
    uint8           Age, SType, Owner, Flags, ShieldBonus, Ladung, Fracht;
    sint16          PosX, PosY;
    uint8           Shield, Weapon, Repair;
    sint16          Moving, Source, Target, Tactical;
    struct r_ShipHeader*    TargetShip;
    struct r_ShipHeader*    BeforeShip;
    struct r_ShipHeader*    NextShip;
} r_ShipHeader;

typedef struct r_SystemHeader {
    APTR            PlanetMemA;
    uint8           State;
    r_ShipHeader    FirstShip;
    uint8           Planets, vNS, SysOwner;
} r_SystemHeader;

typedef struct r_PlanetHeader {
    uint8           Class, Size, PFlags, Ethno;
    char            PName[16];
    double          PosX, PosY;
    uint32          Population, Water;
    uint8           Biosphaere, Infrastruktur, Industrie;
    sint32          XProjectCosts, XProjectPayed;
    sint16          ProjectID;
    r_ShipHeader    FirstShip;
    struct ByteArr42*       ProjectPtr;
} r_PlanetHeader;

typedef struct r_HiScore {
    char    Player[8][20];
    uint8   CivVar[8];
    uint32  Points[8];
} r_HiScore;

// typedef struct r_WormHole {
    // uint8   System[3];
    // sint16  PosX[3], PosY[3];
    // uint8   CivKnowledge[MAXCIVS+1];
// } r_WormHole;
typedef struct r_WormHole {
    uint8   System[2];
    sint16  PosX[2], PosY[2];
    uint8   CivKnowledge[MAXCIVS];
} r_WormHole;


typedef struct r_Col {
    uint8   r, g, b;
} r_Col;

typedef struct r_Save {
    uint8       WarState[MAXCIVS+1][MAXCIVS+1];
    uint8       LastWarState[MAXCIVS+1][MAXCIVS+1];
    sint32      Staatstopf[MAXCIVS+1];
    uint32      Bevoelkerung[MAXCIVS+1];
    uint32      WarPower[MAXCIVS+1];
    uint32      MaxWarPower[MAXCIVS+1];
    uint32      ImperatorState[MAXCIVS+1];
    uint32      SSMoney[MAXCIVS+1][MAXCIVS+1];
    LongArr42   TechCosts[MAXCIVS+1];
    LongArr42   ProjectCosts[MAXCIVS+1];
    sint8       ActTech[MAXCIVS+1];
    uint8       GlobalFlags[MAXCIVS+1];
    sint8       GSteuer[MAXCIVS+1];
    uint8       JSteuer[MAXCIVS+1];
    uint8       stProject[MAXCIVS+1];
    uint8       SService[MAXCIVS+1];
    uint8       Military[MAXCIVS+1];
    BOOL        PlayMySelf, SmallFight, SmallLand, FastMove, NoWorm;
    uint8       WorldFlag, Systems, CivilWar;
    StrArr      SystemName;
    uint8       CivPlayer[MAXCIVS+1];
} r_Save;

typedef struct VectorObj {
    sint16  PosX, PosY;
    uint8   Flag, Size1, Size2;
    double  X1[6],Y1[6],Z1[6],X2[6],Y2[6],Z2[6];
} VectorObj;

#endif
