#ifndef _EXTERN_
#define _EXTERN_ extern
#endif

#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/diskfont.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <intuition/intuition.h>
#include <utility/tagitem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "IT2_Types.h"

/* _EXTERN_  TagArr     Tags; */
_EXTERN_  struct TagItem    Tags[7];
_EXTERN_  PenArr            Pens;
_EXTERN_  ColSpecArr        ColSpec;

_EXTERN_  struct NewScreen  NeuScreen;
_EXTERN_  struct Screen*    MyScreen[3];
_EXTERN_  struct NewWindow  NeuWindow;
_EXTERN_  struct Window*    MyWindow[3];
_EXTERN_  struct Screen*    XScreen;
_EXTERN_  struct ITBitMap   ImgBitMap4, ImgBitMap7, ImgBitMap8;
_EXTERN_  struct Image      Img, GadImg1, GadImg2;

_EXTERN_  struct TextAttr   CustomTA[FONTS+1];
_EXTERN_  struct TextFont*  CustomFont[FONTS+1];
_EXTERN_  struct IntuitionBase* IBase;
_EXTERN_  struct IntuiMessage*  IMsg;
_EXTERN_  struct Process*   Process_Ptr;
_EXTERN_  BPTR              OldWindow_Ptr;

// _EXTERN_  r_WormHole        MyWormHole[MAXHOLES+1];
_EXTERN_  r_WormHole        MyWormHole[MAXHOLES];
_EXTERN_  StrArrMAXPLANETS  Romanum;
_EXTERN_  StrArr11          PNames[MAXCIVS-1];
_EXTERN_  sint16            SystemX[MAXSYSTEMS+1];
_EXTERN_  sint16            SystemY[MAXSYSTEMS+1];
_EXTERN_  uint8             SystemFlags[MAXCIVS+1][MAXSYSTEMS+1];
_EXTERN_  r_SystemHeader    SystemHeader[MAXSYSTEMS+1];
_EXTERN_  StrArr42          Technology, TechnologyL, Project;
_EXTERN_  ByteArr42         TechUse1, TechUse2, ProjectNeedsTech, ProjectNeedsProject;
_EXTERN_  ByteArr22         PriorityList;

_EXTERN_  APTR          SoundMemA[SOUNDS+1];
_EXTERN_  uint16        SoundSize[SOUNDS+1];
_EXTERN_  APTR          CacheMemA[CACHES+1];
_EXTERN_  uint32        CacheMemL[CACHES+1];
_EXTERN_  APTR          LogoMemA[MAXCIVS-1];
_EXTERN_  APTR          LogoSMemA[MAXCIVS-1];
_EXTERN_  uint32        LogoSMemL[MAXCIVS-1];
_EXTERN_  APTR          ZeroSound;
_EXTERN_  APTR          IMemA[IMAGES+1];
_EXTERN_  uint32        IMemL[IMAGES+1];
_EXTERN_  APTR          ModMemA[MODULES+1];
_EXTERN_  uint32        ModMemL[MODULES+1];
_EXTERN_  struct Gadget     DKnopf[GADGETS+1];
_EXTERN_  struct IntuiText  DKnopfTx[GADGETS+1];
_EXTERN_  char*         PathStr[PATHS+1];
_EXTERN_  r_ShipData    ShipData[25+1];

_EXTERN_  sint32        AllCreative[MAXCIVS+1];
_EXTERN_  uint32        Militaerausgaben[MAXCIVS+1];
_EXTERN_  uint32        Verschrottung[MAXCIVS+1];
_EXTERN_  uint8         LastDisplay[MAXCIVS+1];
_EXTERN_  uint8         Warnung[MAXCIVS+1];
_EXTERN_  APTR          TextMemA, PathMemA;
_EXTERN_  uint32        TextMemL, PathMemL, HelpID, TMPtr, l1, l2, MaquesShips;
_EXTERN_  sint32        Year;
_EXTERN_  sint16        OffsetX, OffsetY, OldX, OldY;
_EXTERN_  volatile uint16*  RData;
_EXTERN_  volatile uint8*   LData;
_EXTERN_  uint8         Screen2, ObjType, LastSystem, Level, b, RawCode;
_EXTERN_  uint8         ActPlayer,ActPlayerFlag,LastPlayer,Display;
_EXTERN_  uint8         HomePlanets;
_EXTERN_  void*         ObjPtr;
_EXTERN_  void*         MTBase;
_EXTERN_  void*         MDBBase;
_EXTERN_  BOOL          WBench,Bool_var,Valid,IMemID,DoClock,MultiPlayer,Informed;
_EXTERN_  r_HiScore     HiScore;

_EXTERN_  struct r_PlanetHeader*    GetPlanet[MAXCIVS+1];
_EXTERN_  uint8                     GetPlanetSys[MAXCIVS+1];
_EXTERN_  BOOL          vNSonde[MAXCIVS+1];
//_EXTERN_  int           i, j, k;
_EXTERN_  char*         PText[MAXSTR+1];

_EXTERN_  r_Save        Save;

// added ...
_EXTERN_  int           MOVESHIP_ToX, MOVESHIP_ToY, MOVESHIP_FromX, MOVESHIP_FromY;
_EXTERN_  uint32        MOVESHIP_x, MOVESHIP_y;

_EXTERN_  r_ShipHeader  DefaultShip;
extern struct Custom custom;
