#include "IT2_Defines.h"
#include "IT2_Types.h"
#include "IT2_Vars.h"
#include "IT2_Functions.h"

// will be global variables... waste of memory - maybe we can move them to the heap? ...
double      FactorCos, FactorSin, FactorMSin, FactorMCos;
uint8       AScr;

VectorObj   VObj[13];
APTR        SMemA[4];
uint32      SMemL[4];
// ------------------------------

void SETDARKCOLOR(char* FName, r_Col* Colors)
{
    uint32  AddrX, ISize;
    uint8   i;
    uint32* ColorID;
    r_Col*  Col;
    BPTR    FHandle;

    FHandle = OPENSMOOTH(FName, MODE_OLDFILE);
    if (FHandle == 0) { return; }

    ISize = Seek(FHandle, 0, OFFSET_END);
    ISize = Seek(FHandle, 0, OFFSET_BEGINNING);
    (void) Read(FHandle, IMemA[0], ISize);
    Close(FHandle);
    AddrX = (uint32) IMemA[0];
    do
    {
        ColorID = (uint32*) AddrX;
        AddrX += 4;
    }
    while ((AddrX < ((uint32) IMemA[0]+ISize)) && (*ColorID != _COLOR_CMAP_TEXT_));
    if (*ColorID == _COLOR_CMAP_TEXT_)
    {
        AddrX += 4;
        i = 0;
        do
        {
            Col = (r_Col*) AddrX;
            AddrX += 3;
            Colors[i] = *Col;
            SetRGB32(&(MyScreen[1]->ViewPort),i,0,0,0);
            SetRGB32(&(MyScreen[2]->ViewPort),i,0,0,0);
            i++;
        }
        while (AddrX < ((uint32) IMemA[0]+ISize));
    }
    Colors[31] = (r_Col) {45,45,62};
}

void INTROEXIT(PLANEPTR MyRastPtr)
{
    uint8   i;

    SWITCHDISPLAY();
    (void) SetTaskPri(FindTask(NULL),0);
    if (MyRastPtr != NULL) { FreeRaster(MyRastPtr,640,360); }
    MyRastPtr = NULL;
    for (i = 1; i<=2; i++)
    {
        if (MyScreen[i] != NULL)
        {
            RECT(MyScreen[i],0,0,75,639,434);
        }
    }
    for (i = 1; i<=2; i++)
    {
        if (MyScreen[i] != NULL)
        {
            CloseScreen(MyScreen[i]);
            MyScreen[i] = NULL;
        }
    }
    for (i = 1; i<=3; i++)
    {
        if (SMemA[i]>0)
        {
            FreeMem(SMemA[i],SMemL[i]);
            SMemA[i] = 0;
        }
    }
    for (i = 0; i<=1; i++)
    {
        if (IMemA[i] > 0)
        {
            FreeMem(IMemA[i],IMemL[i]);
            IMemA[i] = 0;
        }
    }
    /*    if (TMPtr != 0)
    {
        StopPlayer;
        UnloadModule(TMPtr);
    }

    TMPtr = 0;
*/
    custom.dmacon = BITCLR | DMAF_AUDIO; // 0x000F

}

void ROTATEpX(uint8 k)
{
    int     i;
    double  store;
    if (VObj[k].Size1 == 0) { return; }
    for (i = 0; i<VObj[k].Size1; i++)
    {
        store = VObj[k].Y1[i];
        VObj[k].Y1[i] = store*FactorCos - VObj[k].Z1[i]*FactorSin;
        VObj[k].Z1[i] = store*FactorSin + VObj[k].Z1[i]*FactorCos;
    }
    if (VObj[k].Size2 == 0) { return; }
    for (i = 0; i<VObj[k].Size2; i++)
    {
        store = VObj[k].Y2[i];
        VObj[k].Y2[i] = store*FactorCos - VObj[k].Z2[i]*FactorSin;
        VObj[k].Z2[i] = store*FactorSin + VObj[k].Z2[i]*FactorCos;
    }
}

void ROTATEpY(uint8 k)
{
    int     i;
    double  store;
    if (VObj[k].Size1 == 0) { return; }
    for (i = 0; i<VObj[k].Size1; i++)
    {
        store = VObj[k].X1[i];
        VObj[k].X1[i] = store*FactorCos - VObj[k].Z1[i]*FactorSin;
        VObj[k].Z1[i] = store*FactorSin + VObj[k].Z1[i]*FactorCos;
    }
    if (VObj[k].Size2 == 0) { return; }
    for (i = 0; i<VObj[k].Size2; i++)
    {
        store = VObj[k].X2[i];
        VObj[k].X2[i] = store*FactorCos - VObj[k].Z2[i]*FactorSin;
        VObj[k].Z2[i] = store*FactorSin + VObj[k].Z2[i]*FactorCos;
    }
}

void ROTATEpZ(uint8 k)
{
    int     i;
    double  store;
    if (VObj[k].Size1 == 0) { return; }
    for (i = 0; i<VObj[k].Size1; i++)
    {
        store = VObj[k].X1[i];
        VObj[k].X1[i] = store*FactorCos-VObj[k].Y1[i]*FactorSin;
        VObj[k].Y1[i] = store*FactorSin+VObj[k].Y1[i]*FactorCos;
    }
    if (VObj[k].Size2 == 0) { return; }
    for (i = 0; i<VObj[k].Size2; i++)
    {
        store = VObj[k].X2[i];
        VObj[k].X2[i] = store*FactorCos-VObj[k].Y2[i]*FactorSin;
        VObj[k].Y2[i] = store*FactorSin+VObj[k].Y2[i]*FactorCos;
    }
}

void ROTATEnX(uint8 k)
{
    int     i;
    double  store;
    if (VObj[k].Size1 == 0) { return; }
    for (i = 0; i<VObj[k].Size1; i++)
    {
        store = VObj[k].Y1[i];
        VObj[k].Y1[i] = store*FactorMCos-VObj[k].Z1[i]*FactorMSin;
        VObj[k].Z1[i] = store*FactorMSin+VObj[k].Z1[i]*FactorMCos;
    }
    if (VObj[k].Size2 == 0) { return; }
    for (i = 0; i<VObj[k].Size2; i++)
    {
        store = VObj[k].Y2[i];
        VObj[k].Y2[i] = store*FactorMCos-VObj[k].Z2[i]*FactorMSin;
        VObj[k].Z2[i] = store*FactorMSin+VObj[k].Z2[i]*FactorMCos;
    }
}

void ROTATEnY(uint8 k)
{
    int     i;
    double  store;
    if (VObj[k].Size1 == 0) { return; }
    for (i = 0; i<VObj[k].Size1; i++)
    {
        store = VObj[k].X1[i];
        VObj[k].X1[i] = store*FactorMCos - VObj[k].Z1[i]*FactorMSin;
        VObj[k].Z1[i] = store*FactorMSin + VObj[k].Z1[i]*FactorMCos;
    }
    if (VObj[k].Size2 == 0) { return; }
    for (i = 0; i<VObj[k].Size2; i++)
    {
        store = VObj[k].X2[i];
        VObj[k].X2[i] = store*FactorMCos - VObj[k].Z2[i]*FactorMSin;
        VObj[k].Z2[i] = store*FactorMSin + VObj[k].Z2[i]*FactorMCos;
    }
}

void ROTATEnZ(uint8 k)
{
    int     i;
    double  store;
    if (VObj[k].Size1 == 0) { return; }
    for (i = 0; i<VObj[k].Size1; i++)
    {
        store = VObj[k].X1[i];
        VObj[k].X1[i] = store*FactorMCos-VObj[k].Y1[i]*FactorMSin;
        VObj[k].Y1[i] = store*FactorMSin+VObj[k].Y1[i]*FactorMCos;
    }
    if (VObj[k].Size2 == 0) { return; }
    for (i = 0; i<VObj[k].Size2; i++)
    {
        store = VObj[k].X2[i];
        VObj[k].X2[i] = store*FactorMCos-VObj[k].Y2[i]*FactorMSin;
        VObj[k].Y2[i] = store*FactorMSin+VObj[k].Y2[i]*FactorMCos;
    }
}

void FLY(uint8 k, double Factor)
{
    int     i;
    if (VObj[k].Size1 == 0) { return; }
    for (i = 0; i<VObj[k].Size1; i++)
    {
        VObj[k].X1[i] = VObj[k].X1[i]*Factor;
        VObj[k].Y1[i] = VObj[k].Y1[i]*Factor;
        VObj[k].Z1[i] = VObj[k].Z1[i]*Factor;
        if ((it_round(VObj[k].PosX-VObj[k].X1[i])<0)  || (it_round(VObj[k].PosX-VObj[k].X1[i])>639)
         || (it_round(VObj[k].PosY-VObj[k].Y1[i])<75) || (it_round(VObj[k].PosY-VObj[k].Y1[i])>434))
        {
            VObj[k].Size1 = 0;
            return;
        }
    }
    if (VObj[k].Size2 == 0) { return; }
    for (i = 0; i<VObj[k].Size2; i++)
    {
        VObj[k].X2[i] = VObj[k].X2[i]*Factor;
        VObj[k].Y2[i] = VObj[k].Y2[i]*Factor;
        VObj[k].Z2[i] = VObj[k].Z2[i]*Factor;
        if ((it_round(VObj[k].PosX-VObj[k].X2[i])<0)  || (it_round(VObj[k].PosX-VObj[k].X2[i])>639)
         || (it_round(VObj[k].PosY-VObj[k].Y2[i])<75) || (it_round(VObj[k].PosY-VObj[k].Y2[i])>434))
        {
            VObj[k].Size1 = 0;
            VObj[k].Size2 = 0;
            return;
        }
    }
}

void GREATEFFECT(uint8 Objects, r_Col* Colors)
{
    uint16  Ctr;
    int i, j, k;
    double  Factor;

    WaitTOF();
    Factor = 0.0;
    Ctr = 0;
    do
    {
        ScreenToFront(MyScreen[AScr]);
        AScr = 3-AScr;
        Factor = Factor+0.02;
        Ctr++;
        for (i = 1; i<=31; i++)
        {
            SetRGB32(&(MyScreen[AScr]->ViewPort),i,it_round(Colors[i].r*Factor)<<24,
                                                   it_round(Colors[i].g*Factor)<<24,
                                                   it_round(Colors[i].b*Factor)<<24);
        }
        if (Ctr == 11)
        {
            /* SPAddrD^ = SMemA[2];         SPAddrC^ = SMemA[2]+SMemL[2] div 2;
             SPVolD^ = 64;                SPVolC^ = 64;
             SPFreqD^ = 380;              SPFreqC^ = 380;
             SPLengthD^ = SMemL[2] div 4; SPLengthC^ = SMemL[2] div 4;
             */
            custom.dmacon = BITSET | DMAF_AUD2 | DMAF_AUD3; // 0x800C
        } else if (Ctr == 12)
        {
            /* SPLengthD^ = 1;
            * SPLengthC^ = 1;
            */
        }
    }
    while (Factor < 1);
    SetRGB4(&(MyScreen[3-AScr]->ViewPort),0,8,8,10);
    WaitTOF();
    WaitTOF();
    SetRGB4(&(MyScreen[3-AScr]->ViewPort),0,0,0,0);
    for (i = 1; i<=31; i++)
    {
        SetRGB32(&(MyScreen[3-AScr]->ViewPort),i,Colors[i].r<<24,Colors[i].g<<24,Colors[i].b<<24);
    }
    delay(50);
    do
    {
        ScreenToFront(MyScreen[AScr]);
        AScr = 3-AScr;
        Factor = Factor-0.02;
        SetRGB32(&(MyScreen[AScr]->ViewPort),31,it_round(Colors[31].r*Factor)<<24,
                                                it_round(Colors[31].g*Factor)<<24,
                                                it_round(Colors[31].b*Factor)<<24);
    }
    while (Factor > 0);
    for (i = 0; i<Objects; i++)
    {
        for (j = 0; j<VObj[i].Size1; j++)
        {
            VObj[i].PosX = VObj[i].PosX+VObj[i].X1[j];
            VObj[i].PosY = VObj[i].PosY+VObj[i].Y1[j];
        }
        VObj[i].PosX =     it_round(VObj[i].PosX / (double) VObj[i].Size1);
        VObj[i].PosY = 235+it_round(VObj[i].PosY / (double) VObj[i].Size1);
        for (j = 0; j<VObj[i].Size1; j++)
        { 
            VObj[i].X1[j] = (VObj[i].PosX+1)-VObj[i].X1[j];
            VObj[i].Y1[j] = (VObj[i].PosY+1)-VObj[i].Y1[j]-235;
        }
        if (VObj[i].Size2>0)
        {
            for (j = 0; j<VObj[i].Size2; j++)
            {
                VObj[i].X2[j] = (VObj[i].PosX+1)-VObj[i].X2[j];
                VObj[i].Y2[j] = (VObj[i].PosY+1)-VObj[i].Y2[j]-235;
            }
        }
    }
    
    /* SPAddrD^ = SMemA[3];         SPAddrC^ = SMemA[3]+SMemL[3] div 2;
     SPVolD^ = 64;                SPVolC^ = 64;
     SPFreqD^ = 550;              SPFreqC^ = 550;
     SPLengthD^ = SMemL[3] div 4; SPLengthC^ = SMemL[3] div 4;
    */
    custom.dmacon = BITSET | DMAF_AUD2 | DMAF_AUD3; // 0x800C
    Factor = 1.0025;
    for (i = 1; (i<=29) && LMB_NOTPRESSED; i++)
    {
        Factor = Factor+0.004;
        if (i>1)
        {
            SetAPen(&(MyScreen[AScr]->RastPort),0);
            RectFill(&(MyScreen[AScr]->RastPort),0,150,639,330);    /*75..434*/
        } else {
            for (j = 2; j<=30; j++)
            {
                SetRGB32(&(MyScreen[AScr]->ViewPort), j, (Colors[j].r*0xA)<<20,
                                                         (Colors[j].g*0xA)<<20,
                                                         (Colors[j].b*0xA)<<20);
            }
        }
        if (i>16) { VObj[rand()%13].Size1 = 0; }
        
        for (j = 0; j<Objects; j++)
        {
            if (VObj[j].Size1>0)
            {
                if (j > 1)
                {
                    SetAPen(&(MyScreen[AScr]->RastPort),0);
                    if (VObj[j].Size2>4)
                    {
                        AreaMove(    &(MyScreen[AScr]->RastPort),it_round(VObj[j].PosX-VObj[j].X2[3]),it_round(VObj[j].PosY-VObj[j].Y2[3]));
                        for (k = 4; k<=5; k++)
                        {
                            AreaDraw(&(MyScreen[AScr]->RastPort),it_round(VObj[j].PosX-VObj[j].X2[k]),it_round(VObj[j].PosY-VObj[j].Y2[k]));
                        }
                    }
                    AreaMove(    &(MyScreen[AScr]->RastPort),it_round(VObj[j].PosX-VObj[j].X1[3]),it_round(VObj[j].PosY-VObj[j].Y1[3]));
                    for (k = 4; k<=5; k++)
                    {
                        AreaDraw(&(MyScreen[AScr]->RastPort),it_round(VObj[j].PosX-VObj[j].X1[k]),it_round(VObj[j].PosY-VObj[j].Y1[k]));
                    }
                    AreaEnd(&(MyScreen[AScr]->RastPort));
                }
                SetAPen(&(MyScreen[AScr]->RastPort),1);
                AreaMove(    &(MyScreen[AScr]->RastPort),it_round(VObj[j].PosX-VObj[j].X1[0]),it_round(VObj[j].PosY-VObj[j].Y1[0]));
                for (k = 1; k<VObj[j].Size1; k++)
                {
                    AreaDraw(&(MyScreen[AScr]->RastPort),it_round(VObj[j].PosX-VObj[j].X1[k]),it_round(VObj[j].PosY-VObj[j].Y1[k]));
                }
                AreaEnd(&(MyScreen[AScr]->RastPort));
                if (VObj[j].Size2>0)
                {
                    AreaMove(    &(MyScreen[AScr]->RastPort),it_round(VObj[j].PosX-VObj[j].X2[0]),it_round(VObj[j].PosY-VObj[j].Y2[0]));
                    for (k = 1; k<VObj[j].Size2; k++)
                    {
                        AreaDraw(&(MyScreen[AScr]->RastPort),it_round(VObj[j].PosX-VObj[j].X2[k]),it_round(VObj[j].PosY-VObj[j].Y2[k]));
                    }
                    AreaEnd(&(MyScreen[AScr]->RastPort));
                }
            }
            if ((VObj[j].Flag & ROTATE_PX) != 0) { ROTATEpX(j); }
            if ((VObj[j].Flag & ROTATE_PY) != 0) { ROTATEpY(j); }
            if ((VObj[j].Flag & ROTATE_PZ) != 0) { ROTATEpZ(j); }
            if ((VObj[j].Flag & ROTATE_NX) != 0) { ROTATEnX(j); }
            if ((VObj[j].Flag & ROTATE_NY) != 0) { ROTATEnY(j); }
            if ((VObj[j].Flag & ROTATE_NZ) != 0) { ROTATEnZ(j); }
            FLY(j, Factor);
        }
        ScreenToFront(MyScreen[AScr]);
        AScr = 3-AScr;
        if (i == 1)
        {
            /* SPLengthD^ = 1;
            * SPLengthC^ = 1;
            */
        }
    }
    for (i = 1; i<=2; i++)
    {
        SetAPen(&(MyScreen[AScr]->RastPort),0);
        RectFill(&(MyScreen[AScr]->RastPort),0,75,639,434);
        ScreenToFront(MyScreen[AScr]);
        AScr = 3-AScr;
    }
    custom.dmacon = BITCLR | DMAF_AUD2 | DMAF_AUD3; // 0x000C
}

BOOL LOADSOUNDS()
{
    uint8   i;
    uint8   path_len;
    uint32  ssize;
    char    s[40];
    BPTR    FHandle;

    //    INITCHANNELS();
    path_len=strlen(PathStr[8]);
    strcpy(s, PathStr[8]);
    strcpy(s+path_len, "Snd0.RAW");
    path_len+=3;
    for (i = 1; i<=3; i++)
    {
        s[path_len] = i+'0';
        FHandle = OPENSMOOTH(s,MODE_OLDFILE);
        if (FHandle != 0)
        {
            ssize = Seek(FHandle,0,OFFSET_END);
            ssize = Seek(FHandle,0,OFFSET_BEGINNING);
            SMemL[i] = ssize;
            SMemA[i] = AllocMem(ssize,MEMF_CHIP+MEMF_CLEAR);
            if (SMemA[i] == 0) { return FALSE; }
            ssize = Read(FHandle, SMemA[i], SMemL[i]);
            Close(FHandle);
        } else {
            return FALSE;
        }
    }
    return TRUE;
}

void MAININTRO()
{
    char        s[35];
    BPTR        FHandle;
    int         pathname_len;
    r_Col       Colors[128];
    PLANEPTR    MyRastPtr;
    ITBitMap    IntroBitMap;
    struct BitMap       MyBitMap;
    struct TmpRas       MyTmpRas;
    struct AreaInfo     MyAI;
    StrArr16    SArr;
    FontArr16   FArr;
    r_Coords    ShipX,ShipY,ShipZ;
    int         LEdge[3], TEdge[3];
    uint8       btx;
    uint32      l, ISize;
    double      SizeFactor;
    double      Factor;
    double      store;
    uint8       i, j ,k;
    
    //    i = SetTaskPri(FindTask(NULL),120);
    TMPtr = 0;
    AScr = 1;
    MyRastPtr = NULL;
    for (i = 1; i<=2; i++) { MyScreen[i] = NULL; }
    for (i = 1; i<=3; i++) { SMemA[i] = NULL; }
    for (i = 0; i<=1; i++) { IMemA[i] = NULL; }
    if (!LOADSOUNDS())
    {
        INTROEXIT(MyRastPtr); return;
    }
    for (i = 1; i<=2; i++)
    {
        MyScreen[i] = OPENCINEMA(5);
        if (MyScreen[i] == NULL)
        {
            INTROEXIT(MyRastPtr); return;
        }
    }
    IMemL[0] = 73500;
    IMemA[0] = AllocMem(IMemL[0],MEMF_CHIP);
    if (IMemA[0] == NULL)
    {
        INTROEXIT(MyRastPtr); return;
    }
    IntroBitMap = (ITBitMap) {80,183,1,5,0, {(PLANEPTR)  IMemA[0],        (PLANEPTR) (IMemA[0]+14640),
                                             (PLANEPTR) (IMemA[0]+29280), (PLANEPTR) (IMemA[0]+43920),
                                             (PLANEPTR) (IMemA[0]+58560), NULL, NULL, NULL},
                                             IMemA[0], IMemL[0]};

    pathname_len = strlen(PathStr[8]);
    (void) strncpy(s, PathStr[8], pathname_len);
    strcpy(s+pathname_len, "Frame0.pal");

    l = SETCOLOR(MyScreen[1],s);
    l = SETCOLOR(MyScreen[2],s);
    strcpy(s+pathname_len, "Frame0.img");   // Touchbyte ...    

    if (!RAWLOADIMAGE(s,0,0,640,183,5,&IntroBitMap))
    {
        INTROEXIT(MyRastPtr); return;
    }
    for (i = 1; i<=8; i++)
    {
        BltBitMapRastPort((struct BitMap*) &IntroBitMap,0,0,&(MyScreen[3-AScr]->RastPort),640-i*5,340,i*5,90,192);
        AScr = 3-AScr;
        ScreenToFront(MyScreen[AScr]);
    }
    l = 590;
    do
    {
        l = l-5;
        BltBitMapRastPort((struct BitMap*) &IntroBitMap, 0,0,&(MyScreen[3-AScr]->RastPort),l   ,340,49,90,192);
        BltBitMapRastPort((struct BitMap*) &IntroBitMap,41,0,&(MyScreen[3-AScr]->RastPort),l+49,340, 5,90,192);
        AScr = 3-AScr;
        ScreenToFront(MyScreen[AScr]);
        if (LMB_PRESSED)
            { INTROEXIT(MyRastPtr); return; }
    }
    while (l > 10);
    ClipBlit(&(MyScreen[AScr]->RastPort),10,340,&(MyScreen[3-AScr]->RastPort),10,340,50,90,192);
    for (i = 1; i<=9; i++)
    {
        BltBitMapRastPort((struct BitMap*) &IntroBitMap,50,0,&(MyScreen[3-AScr]->RastPort),640-i*5,340,i*5,90,192);
        AScr = 3-AScr;
        ScreenToFront(MyScreen[AScr]);
    }
    l = 595;
    SetAPen(&(MyScreen[AScr]->RastPort),0);
    SetAPen(&(MyScreen[3-AScr]->RastPort),0);
    do
    {
        l = l-5;
        BltBitMapRastPort((struct BitMap*) &IntroBitMap,50,0,&(MyScreen[3-AScr]->RastPort),l,340,41,90,192);
        RectFill(&(MyScreen[3-AScr]->RastPort),l+41,340,l+50,430);
        AScr = 3-AScr;
        ScreenToFront(MyScreen[AScr]);
        if (LMB_PRESSED)
            { INTROEXIT(MyRastPtr); return; }
    }
    while (l > 60);
    ClipBlit(&(MyScreen[AScr]->RastPort),10,340,&(MyScreen[3-AScr]->RastPort),10,340,150,90,192);
    delay(5);
    for (i = 1; i<=2; i++)
    {
        BltBitMapRastPort((struct BitMap*) &IntroBitMap,0,0,&(MyScreen[3-AScr]->RastPort),10,340,616,91,192);
        AScr = 3-AScr;
        ScreenToFront(MyScreen[AScr]);
    }
    if (LMB_PRESSED)
        { INTROEXIT(MyRastPtr); return; }
    delay(15);
    BltBitMapRastPort((struct BitMap*) &IntroBitMap,0,90,&(MyScreen[3-AScr]->RastPort),10,337,98,91,192);
    AScr = 3-AScr;
    ScreenToFront(MyScreen[AScr]);
    custom.dmacon = BITCLR | DMAF_AUDIO; // 0x000F
    delay(15);
/*    SPAddrA^ = SMemA[1];         SPAddrB^ = SMemA[1]+SMemL[1] div 2;
    SPVolA^ = 0;                 SPVolB^ = 0;
    SPFreqA^ = 856;              SPFreqB^ = 856;
    SPLengthA^ = SMemL[1] div 4; SPLengthB^ = SMemL[1] div 4;

    SPAddrD^ = SMemA[2];         SPAddrC^ = SMemA[2]+SMemL[2] div 2;
    SPVolD^ = 64;                SPVolC^ = 64;
    SPFreqD^ = 380;              SPFreqC^ = 380;
    SPLengthD^ = 1;              SPLengthC^ = 1;
*/
    custom.dmacon = BITSET | DMAF_AUD0 | DMAF_AUD1; // 0x8003

/*    for (btx = 1; btx<=64; btx++)
    {
        SPVolA^ = btx;
        SPVolB^ = btx;
        WaitTOF();
    }
*/
    delay(25);
    FactorSin = sin(0.04);
    FactorCos = cos(0.03);
    FactorMSin = sin(-0.05);
    FactorMCos = cos(-0.02);
    for (i = 1; i<=2; i++)
    {
        SetAPen(&(MyScreen[3-AScr]->RastPort),0);
        RectFill(&(MyScreen[3-AScr]->RastPort),0,335,640,430);
        AScr = 3-AScr;
        ScreenToFront(MyScreen[AScr]);
    }

    MyRastPtr = AllocRaster(640,360);
    if (MyRastPtr == NULL)
    {
        INTROEXIT(MyRastPtr); return;
    }
    InitTmpRas(&MyTmpRas,MyRastPtr,21000);
    InitArea(&MyAI,IMemA[0],200);
    MyScreen[1]->RastPort.TmpRas = &MyTmpRas;
    MyScreen[2]->RastPort.TmpRas = &MyTmpRas;
    MyScreen[1]->RastPort.AreaInfo = &MyAI;
    MyScreen[2]->RastPort.AreaInfo = &MyAI;

    /*****************************************************************************/
    /* TOUCHBYTE SOFTWARE PRESENTS */
    strcpy(s+pathname_len, "Frame1.pal");
    SETDARKCOLOR(s, Colors);
    strcpy(s+pathname_len, "Frame1.img");
    if (!DISPLAYIMAGE(s,0,235,640,37,5,MyScreen[AScr],0)) { }
    WRITE(320,285,31,16,MyScreen[AScr],5,"PRESENTS");
    ClipBlit(&(MyScreen[AScr]->RastPort),0,235,&(MyScreen[3-AScr]->RastPort),0,235,640,75,192);

    /* T */
    VObj[0] = (VectorObj){0,0,ROTATE_PY+ROTATE_PX,
        6,4,{38, 9, 9, 9, 9,38},{ 2, 2,10,10, 2, 2},{1,1,1,3,3,3},
        {18,18,18,18, 0, 0},{11,36,36,11, 0, 0},{1,1,3,3,0,0}};
    /* U */
    VObj[1] = (VectorObj){0,0,ROTATE_PX+ROTATE_PZ,
        6,6,{91,80,80,80,80,91},{1,1,26,26,1,1},{1,1,1,3,3,3},
        {111,100,100,100,100,111},{1,1,24,24,1,1},{1,1,1,3,3,3}};
    /* H */
    VObj[2] = (VectorObj){0,0,ROTATE_PY+ROTATE_NZ,
        6,6,{163,152,152,152,152,163},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {184,173,173,173,173,184},{2,2,12,12,2,2},{1,1,1,3,3,3}};
    /* B */
    VObj[3] = (VectorObj){0,0,ROTATE_NX+ROTATE_PZ,
        6,6,{209,187,187,187,187,209},{2,2,10,10,2,2},{1,1,1,3,3,3},
        {205,187,187,187,187,205},{15,15,36,36,15,15},{1,1,1,3,3,3}};
    /* Y */
    VObj[4] = (VectorObj){0,0,ROTATE_PZ+ROTATE_NX,
        6,6,{229,217,229,229,217,229},{2,2,19,19,2,2},{1,1,1,3,3,3},
        {254,242,236,236,242,254},{2,2,12,12,2,2},{1,1,1,3,3,3}};
    /* T */
    VObj[5] = (VectorObj){0,0,ROTATE_NX+ROTATE_NY,
        6,4,{285,256,256,256,256,285},{2,2,9,9,1,1},{1,1,1,3,3,3},
        {266,266,266,266,0,0},{11,36,36,11,0,0},{1,1,3,3,0,0}};
    /* E */
    VObj[6] = (VectorObj){0,0,ROTATE_PX+ROTATE_PY,
        6,6,{318,289,289,289,289,318},{2,2,10,10,2,2},{1,1,1,3,3,3},
        {315,289,289,289,289,315},{14,14,36,36,14,14},{1,1,1,3,3,3}};
    /* F */
    VObj[7] = (VectorObj){0,0,ROTATE_NX+ROTATE_PZ,
        6,6,{440,410,410,410,410,440},{2,2,10,10,2,2},{1,1,1,3,3,3},
        {437,410,410,410,410,437},{14,14,36,36,14,14},{1,1,1,3,3,3}};
    /* T */
    VObj[8] = (VectorObj){0,0,ROTATE_NZ+ROTATE_NY,
        6,4,{472,443,443,443,443,472},{2,2,10,10,2,2},{1,1,1,3,3,3},
        {452,452,452,452,0,0},{11,36,36,11,0,0},{1,1,3,3,0,0}};
    /* W */
    VObj[9] = (VectorObj){0,0,ROTATE_PX+ROTATE_PZ,
        6,6,{486,475,486,486,475,486},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {506,497,492,492,497,506},{2,2,16,16,2,2},{1,1,1,3,3,3}};
    /* A */
    VObj[10] = (VectorObj){0,0,ROTATE_PX+ROTATE_PY,
        6,0,{547,536,521,521,536,547},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    /* R */
    VObj[11] = (VectorObj){0,0,ROTATE_PX+ROTATE_PZ,
        6,6,{589,565,565,565,565,589},{3,2,10,10,2,3},{1,1,1,3,3,3},
        {576,565,565,565,565,576},{16,16,36,36,16,16},{1,1,1,3,3,3}};
    /* E */
    VObj[12] = (VectorObj){0,0,ROTATE_NX+ROTATE_NY,
        6,6,{630,601,601,601,601,630},{2,2,10,10,2,2},{1,1,1,3,3,3},
        {627,601,601,601,601,627},{14,14,36,36,14,14},{1,1,1,3,3,3}};

    if (LMB_PRESSED) { INTROEXIT(MyRastPtr); return; }
    GREATEFFECT(13, Colors);
    if (LMB_PRESSED) { INTROEXIT(MyRastPtr); return; }

    /*****************************************************************************/
    /* A VIRTUAL WORLDS PRODUCTION */
    strcpy(s+pathname_len, "Frame2.pal");
    SETDARKCOLOR(s, Colors);
    strcpy(s+pathname_len, "Frame2.img");
    if (!DISPLAYIMAGE(s,0,235,640,37,5,MyScreen[AScr],0)) { }
    WRITE(320,205,31,16,MyScreen[AScr],5,"A");
    WRITE(320,285,31,16,MyScreen[AScr],5,"PRODUCTION");
    ClipBlit(&(MyScreen[AScr]->RastPort),0,200,&(MyScreen[3-AScr]->RastPort),0,200,640,100,192);

    /* V */
    VObj[0] = (VectorObj) {0,0,ROTATE_PY+ROTATE_PX,
        6,6,{98,86,101,101,86,98},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {126,114,106,106,114,126},{2,2,23,23,2,2},{1,1,1,3,3,3}};
    /* I */
    VObj[1] = (VectorObj) {0,0,ROTATE_PX+ROTATE_PZ,
        6,0,{140,129,129,129,129,140},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    /* R */
    VObj[2] = (VectorObj) {0,0,ROTATE_NX+ROTATE_PZ,
        6,6,{167,143,143,143,143,167},{3,2,10,10,2,3},{1,1,1,3,3,3},
        {154,143,143,143,143,154},{16,16,36,36,16,16},{1,1,1,3,3,3}};
    /* T */
    VObj[3] = (VectorObj) {0,0,ROTATE_PY+ROTATE_NZ,
        6,4,{206,177,177,177,177,206},{2,2,10,10,2,2},{1,1,1,3,3,3},
        {186,186,186,186,0,0},{11,36,36,11,0,0},{1,1,3,3,0,0}};
    /* U */
    VObj[4] = (VectorObj) {0,0,ROTATE_NX+ROTATE_PZ,
        6,6,{220,209,209,209,209,220},{2,2,27,27,2,2},{1,1,1,3,3,3},
        {240,229,229,229,229,240},{2,2,25,25,2,2},{1,1,1,3,3,3}};
    /* A */
    VObj[5] = (VectorObj) {0,0,ROTATE_PZ+ROTATE_NX,
        6,0,{266,255,240,240,255,266},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    /* L */
    VObj[6] = (VectorObj) {0,0,ROTATE_NX+ROTATE_NY,
        6,4,{295,284,284,284,284,295},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {311,296,296,311,0,0},{26,26,26,26,0,0},{1,1,3,3,0,0}};
    /* W */
    VObj[7] = (VectorObj) {0,0,ROTATE_PX+ROTATE_PY,
        6,6,{335,324,335,335,324,335},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {355,346,341,341,346,355},{2,2,16,16,2,2},{1,1,1,3,3,3}};
    /* R */
    VObj[8] = (VectorObj) {0,0,ROTATE_NX+ROTATE_PZ,
        6,6,{441,417,417,417,417,441},{3,2,10,10,2,3},{1,1,1,3,3,3},
        {428,417,417,417,417,428},{16,16,36,36,16,16},{1,1,1,3,3,3}};
    /* L */
    VObj[9] = (VectorObj) {0,0,ROTATE_NZ+ROTATE_NY,
        6,4,{464,453,453,453,453,464},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {480,465,465,480,0,0},{26,26,26,26,0,0},{1,1,3,3,0,0}};
    /* D */
    VObj[10] = (VectorObj) {0,0,ROTATE_PX+ROTATE_PZ,
        6,0,{505,483,483,483,483,505},{3,2,36,36,2,3},{1,1,1,3,3,3},
        {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};

    if (LMB_PRESSED) { INTROEXIT(MyRastPtr); return; }
    GREATEFFECT(11, Colors);    
    if (LMB_PRESSED) { INTROEXIT(MyRastPtr); return; }

    /*****************************************************************************/
    /* IMPERIUM TERRANUM */
    strcpy(s+pathname_len, "Frame3.pal");
    SETDARKCOLOR(s, Colors);
    strcpy(s+pathname_len, "Frame3.img");
    if (!DISPLAYIMAGE(s,0,235,640,37,5,MyScreen[AScr],0)) { }
    ClipBlit(&(MyScreen[AScr]->RastPort),0,235,&(MyScreen[3-AScr]->RastPort),0,235,640,37,192);

    /* I */
    VObj[0] = (VectorObj) {0,0,ROTATE_PY+ROTATE_PX,
        6,6,{48,37,37,37,37,48},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {95,84,73,73,84,95},{2,2,18,18,2,2},{1,1,1,3,3,3}};
    /* M */
    VObj[1] = (VectorObj) {0,0,ROTATE_PX+ROTATE_PZ,
        6,0,{62,51,51,51,51,62},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    /* E */  
    VObj[2] = (VectorObj) {0,0,ROTATE_NX+ROTATE_PZ,
        6,6,{161,132,132,132,132,161},{2,2,10,10,2,2},{1,1,1,3,3,3},
        {158,132,132,132,132,158},{14,14,36,36,14,14},{1,1,1,3,3,3}};
    /* I */   
    VObj[3] = (VectorObj) {0,0,ROTATE_PY+ROTATE_NZ,
        6,0,{211,200,200,200,200,211},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    /* U */   
    VObj[4] = (VectorObj) {0,0,ROTATE_NX+ROTATE_PZ,
        6,6,{225,214,214,214,214,225},{2,2,27,27,2,2},{1,1,1,3,3,3},
        {245,234,234,234,234,245},{2,2,25,25,2,2},{1,1,1,3,3,3}};
    /* M */   
    VObj[5] = (VectorObj) {0,0,ROTATE_PZ+ROTATE_NX,
        6,6,{259,248,248,248,248,259},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {292,281,270,270,281,292},{2,2,18,18,2,2},{1,1,1,3,3,3}};
    /* T */   
    VObj[6] = (VectorObj) {0,0,ROTATE_NX+ROTATE_NY,
        6,4,{338,309,309,309,309,338},{2,2,10,10,2,2},{1,1,1,3,3,3},
        {318,318,318,318,0,0},{21,36,36,11,0,0},{1,1,3,3,0,0}};
    /* E */   
    VObj[7] = (VectorObj) {0,0,ROTATE_PX+ROTATE_PY,
        6,6,{370,341,341,341,341,370},{2,2,10,10,2,2},{1,1,1,3,3,3},
        {367,341,341,341,341,367},{14,14,36,36,14,14},{1,1,1,3,3,3}};
    /* R */   
    VObj[8] = (VectorObj) {0,0,ROTATE_NX+ROTATE_PZ,
        6,6,{433,409,409,409,409,433},{3,2,10,10,2,3},{1,1,1,3,3,3},
        {420,409,409,409,409,420},{16,16,36,36,16,16},{1,1,1,3,3,3}};
    /* A */   
    VObj[9] = (VectorObj) {0,0,ROTATE_NZ+ROTATE_NY,
        6,0,{471,460,445,445,460,471},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    /* N */   
    VObj[10] = (VectorObj) {0,0,ROTATE_PX+ROTATE_PZ,
        6,6,{500,489,489,489,489,500},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {521,510,510,510,510,521},{2,2,17,17,2,2},{1,1,1,3,3,3}};
    /* M */   
    VObj[11] = (VectorObj) {0,0,ROTATE_PX+ROTATE_PZ,
        6,6,{569,558,558,558,558,569},{2,2,36,36,2,2},{1,1,1,3,3,3},
        {602,591,580,580,591,602},{2,2,18,18,2,2},{1,1,1,3,3,3}};

    if (LMB_PRESSED) { INTROEXIT(MyRastPtr); return; }
    GREATEFFECT(12, Colors);
    if (LMB_PRESSED) { INTROEXIT(MyRastPtr); return; }

    /*****************************************************************************/
    // cleanup... 
    FreeRaster(MyRastPtr,640,360);
    MyRastPtr = NULL;
    for (i = 1; i<=2; i++)
    {
        if (MyScreen[i] != NULL)
        {
            CloseScreen(MyScreen[i]);
            MyScreen[i] = NULL;
        }
    }
    FreeMem(IMemA[0],IMemL[0]);
    IMemA[0] = NULL;
    for (i = 1; i<=2; i++)
    {
        MyScreen[i] = OPENCINEMA(7);
        if (MyScreen[i] == NULL)
        {
            INTROEXIT(MyRastPtr); return;
        }
    }
    /*****************************************************************************/
    // prepare next effect...
    IMemL[0] = 201856;
    IMemL[1] = 21000;
    for (i = 0; i<=1; i++)
    {
        IMemA[i] = AllocMem(IMemL[i],MEMF_CHIP);
        if (IMemA[i] == NULL)
        {
            INTROEXIT(MyRastPtr); return;
        }
    }
    /*    SPAddrD^ = SMemA[2]+6500;            SPAddrC^ = SMemA[2]+(SMemL[2] div 2)+6500;
    SPVolD^ = 64;                        SPVolC^ = 64;
    SPFreqD^ = 380;                      SPFreqC^ = 380;
    SPLengthD^ = (SMemL[2]-13000) div 4; SPLengthC^ = (SMemL[2]-13000) div 4;
*/
    custom.dmacon = BITSET | DMAF_AUD2 | DMAF_AUD3; // 0x800C
    WaitTOF();
/*    SPLengthD^ = 1; SPLengthC^ = 1;
*/
    btx = 255;
    do
    {
        SetRGB32(&(MyScreen[2]->ViewPort), 0, btx<<24, btx<<24, btx<<24);
        btx = btx-5;
        WaitTOF();
    }
    while (btx > 10);
    SetRGB32(&(MyScreen[2]->ViewPort),0,0,0,0);
    custom.dmacon = BITCLR | DMAF_AUD2 | DMAF_AUD3; // 0x000C
    if (LMB_PRESSED)
        { INTROEXIT(MyRastPtr); return; }

    strcpy(s+pathname_len, "MOD.Intro");
    FHandle = OPENSMOOTH(s,MODE_OLDFILE);
    if (FHandle != 0) { Close(FHandle); }
    //    TMPtr = LoadModule(s);
    //    PlayModule(TMPtr);

    strcpy(s+pathname_len, "Frame4.pal");
    SETDARKCOLOR(s, Colors);
    strcpy(s+pathname_len, "Frame4.img");       // terrain with stars...
    if (!DISPLAYIMAGE(s,0,75,640,360,7,MyScreen[2],0)) { }
    ClipBlit(&(MyScreen[2]->RastPort),0,75,&(MyScreen[1]->RastPort),0,75,640,360,192);

    strcpy(s+pathname_len, "Frame5.img");       // little earth-image..
    FHandle = OPENSMOOTH(s,MODE_OLDFILE);
    if (FHandle != 0)
    {
        ISize = Seek(FHandle,0,OFFSET_END);
        ISize = Seek(FHandle,0,OFFSET_BEGINNING);
        (void) Read(FHandle,(APTR) (IMemA[0]+IMemL[0]-ISize-250), ISize);
        UNPACK(IMemA[0],IMemA[0]+IMemL[0]-ISize-250,20160,0);
        Close(FHandle);
    }
    
    MyBitMap = (struct BitMap) { 20, 144, 1, 7, 0,
        {(PLANEPTR) (IMemA[0]),      (PLANEPTR) (IMemA[0]+2880), (PLANEPTR) (IMemA[0]+5760),
         (PLANEPTR) (IMemA[0]+8640), (PLANEPTR) (IMemA[0]+11520),(PLANEPTR) (IMemA[0]+14400),
         (PLANEPTR) (IMemA[0]+17280), NULL }};

    // fade in....
    Factor = 0;
    ScreenToFront(MyScreen[AScr]);
//    AScr = 3-AScr;
    do
    {
        Factor += 0.05;
        for (i = 1; i<=127; i++)
        {
            SetRGB32(&(MyScreen[AScr]->ViewPort), i, it_round(Colors[i].r*Factor)<<24,
                                                     it_round(Colors[i].g*Factor)<<24,
                                                     it_round(Colors[i].b*Factor)<<24);
        }
    }
    while (Factor < 1);

    for (i = 1; i<=127; i++)
    {
        SetRGB32(&(MyScreen[3-AScr]->ViewPort), i, Colors[i].r<<24,
                                                   Colors[i].g<<24,
                                                   Colors[i].b<<24);
        SetRGB32(&(MyScreen[  AScr]->ViewPort), i, Colors[i].r<<24,
                                                   Colors[i].g<<24,
                                                   Colors[i].b<<24);
   }
    ScrollRaster(&(MyScreen[AScr]->RastPort),0,-4,0,75,639,434);

    for (i = 1; i<=6; i++)
    {
        ScreenToFront(MyScreen[AScr]);
        AScr = 3-AScr;
        ScrollRaster(&(MyScreen[AScr]->RastPort),0,-8,0,75,639,434);
        ClipBlit(&(MyScreen[AScr]->RastPort),0,270,&(MyScreen[AScr]->RastPort),0,75,640,8,192);
        if (LMB_PRESSED)
            { INTROEXIT(MyRastPtr); return; }
    }

    for (i = 1; i<=35; i++)
    {
        ScreenToFront(MyScreen[AScr]);
        AScr = 3-AScr;
        ScrollRaster(&(MyScreen[AScr]->RastPort),0,-8,0,75,639,434);
        ClipBlit(&(MyScreen[AScr]->RastPort),0,270,&(MyScreen[AScr]->RastPort),0,75,640,8,192);
        BltBitMapRastPort(&MyBitMap,0,140-i*4,&(MyScreen[AScr]->RastPort),380,75,160,8,192);
        if (LMB_PRESSED)
            { INTROEXIT(MyRastPtr); return; }
    }


    ScreenToFront(MyScreen[AScr]);
    AScr = 3-AScr;
    ScrollRaster(&(MyScreen[AScr]->RastPort),0,-8,0,75,639,434);
    ClipBlit(&(MyScreen[AScr]->RastPort),0,270,&(MyScreen[AScr]->RastPort),0,75,640,8,192);
    BltBitMapRastPort(&MyBitMap,0,0,&(MyScreen[AScr]->RastPort),380,79,160,4,192);

    for (i = 1; i<=14; i++)
    {
        ScreenToFront(MyScreen[AScr]);
        AScr = 3-AScr;
        ScrollRaster(&(MyScreen[AScr]->RastPort),0,-8,0,75,639,434);
        ClipBlit(&(MyScreen[AScr]->RastPort),0,270,&(MyScreen[AScr]->RastPort),0,75,640,8,192);
        if (LMB_PRESSED)
            { INTROEXIT(MyRastPtr); return; }

    }
    delay(10);
    if (LMB_PRESSED)
        { INTROEXIT(MyRastPtr); return; }

    RECT(MyScreen[AScr],0,0,75,639,434);
    ScreenToFront(MyScreen[AScr]);
    AScr = 3-AScr;
    RECT(MyScreen[AScr],0,0,75,639,434);

    strcpy(s+pathname_len, "Frame6.pal");
    l = SETCOLOR(MyScreen[AScr],s);
    l = SETCOLOR(MyScreen[3-AScr],s);
    SetRGB4(&(MyScreen[AScr]->ViewPort),127,9,9,11);   SetRGB4(&(MyScreen[3-AScr]->ViewPort),127,9,9,11);
    SetRGB4(&(MyScreen[AScr]->ViewPort),126,11,11,15); SetRGB4(&(MyScreen[3-AScr]->ViewPort),126,11,11,15);
    SetRGB4(&(MyScreen[AScr]->ViewPort),125,15,0,15);  SetRGB4(&(MyScreen[3-AScr]->ViewPort),125,15,0,15);
    SetRGB4(&(MyScreen[AScr]->ViewPort),124,13,0,0);   SetRGB4(&(MyScreen[3-AScr]->ViewPort),124,15,2,2);
    SetRGB4(&(MyScreen[AScr]->ViewPort),123,14,14,15); SetRGB4(&(MyScreen[3-AScr]->ViewPort),123,14,14,15);

    strcpy(s+pathname_len, "Frame6.img");
    if (!DISPLAYIMAGE(s,0,75,640,360,7,MyScreen[AScr],0)) { }
    MyBitMap = (struct BitMap) { 80, 360, 1, 7, 0,
       {(PLANEPTR) (IMemA[0]),       (PLANEPTR) (IMemA[0]+28800), (PLANEPTR) (IMemA[0]+57600),
        (PLANEPTR) (IMemA[0]+86400), (PLANEPTR) (IMemA[0]+115200),(PLANEPTR) (IMemA[0]+144000),
        (PLANEPTR) (IMemA[0]+172800)}};
    BltBitMapRastPort(&MyBitMap,0,0,&(MyScreen[3-AScr]->RastPort),0,75,640,360,192);

    MyRastPtr = AllocRaster(640,360);
    if (MyRastPtr == NULL)
    {
        INTROEXIT(MyRastPtr); return;
    }
    InitTmpRas(&MyTmpRas,MyRastPtr,21000);
    InitArea(&MyAI, IMemA[1], 200);
    MyScreen[1]->RastPort.TmpRas = &MyTmpRas;
    MyScreen[2]->RastPort.TmpRas = &MyTmpRas;
    MyScreen[1]->RastPort.AreaInfo = &MyAI;
    MyScreen[2]->RastPort.AreaInfo = &MyAI;

    SArr = (StrArr16){{"",
        "Software & Design",            "Oxygenic",
        "Art Director",                 "Cybertrace",
        "Music by",                     "Ludwig v.Beethoven   N.N. Ikonnikow   Richard Wagner",
        "Special Effects",              "Oxygenic",
        "Credits go to",                "Adam Benjamin   Rikard Cederlund",
        "Jakob Gaardsted   Andy Jones", "George Moore",
        "Surround-Sounds created with", "WaveTracer DS®",
        "Colors in Technicolor®",       "Panaflex® Camera and Lenses by Panavision®"}};     
    FArr = (FontArr16) {{0, 4,5, 4,5, 4,5, 4,5, 4,5, 5,5, 4,5, 4,4}};

    ShipX = (r_Coords) {{ 390, 264,252,186,186,192,256,290,354,360,360,294,282, 252, 256, 290,294, 282,294,294, 258,265,273,281,288, 185,185,190,190, 356,356,361,361,0,0,0,0,0,0,0,0}};
    ShipY = (r_Coords) {{ 315, 174,275,250,188,225,234,234,225,188,250,275,174, 275, 243, 243,275, 174,275,275, 269,342,269,342,269, 187,172,172,187, 187,172,172,187,0,0,0,0,0,0,0,0}};
    ShipZ = (r_Coords) {{-2.5,  -5, -1, -5, -5, -5, -1, -1, -5, -5, -5, -1, -5,  -1,-1.1,-1.1, -1,  -5, -8, -1,  -2, -2, -2, -2, -2,  -5, -5, -5, -5,  -5, -5, -5, -5,0,0,0,0,0,0,0,0}};

    for (i = 1; i<=40; i++)
    {
        ShipX.data[i] = 273-ShipX.data[i];
        ShipY.data[i] = 257-ShipY.data[i];
    }
    FactorSin = sin(0.45);
    FactorCos = cos(0.45);
    for (j = 1; j<=3; j++)
    {
        for (i = 1; i<=40; i++)
        {
            store = ShipY.data[i];
            ShipY.data[i] = store*FactorCos - ShipZ.data[i]*FactorSin; /*X*/
            ShipZ.data[i] = store*FactorSin + ShipZ.data[i]*FactorCos;
        }
    }
    FactorSin = sin(-0.44);
    FactorCos = cos(-0.44);
    for (i = 1; i<=40; i++)
    {
        store = ShipX.data[i];
        ShipX.data[i] = store*FactorCos - ShipZ.data[i]*FactorSin;
        ShipZ.data[i] = store*FactorSin + ShipZ.data[i]*FactorCos;
    }
    FactorSin = sin(-0.08);
    FactorCos = cos(-0.08);
    for (i = 1; i<=40; i++)
    {
        store = ShipX.data[i];
        ShipX.data[i] = store*FactorCos - ShipY.data[i]*FactorSin;
        ShipY.data[i] = store*FactorSin + ShipY.data[i]*FactorCos;
    }
    if (LMB_PRESSED)
        { INTROEXIT(MyRastPtr); return; }

    Factor = 0.0074;
    SizeFactor = 0.009;
    LEdge[1] = 0;
    TEdge[1] = 75;
    LEdge[2] = 0;
    TEdge[2] = 75;
    l = 1;
    ISize = 0;
    do
    {
        ScreenToFront(MyScreen[AScr]);
        AScr = 3-AScr;
        ShipX.data[0] = ShipX.data[0]-Factor-Factor-0.22;
        ShipY.data[0] = ShipY.data[0]-Factor;
        BltBitMapRastPort(&MyBitMap,LEdge[AScr],TEdge[AScr]-75,&(MyScreen[AScr]->RastPort),LEdge[AScr],TEdge[AScr],160,80,192);
        BltBitMapRastPort(&MyBitMap,20,145,&(MyScreen[AScr]->RastPort),20,220,600,55,192);
        LEdge[AScr] = it_round(ShipX.data[0]-90);
        if (LEdge[AScr]<0) { LEdge[AScr] = 0; }
        TEdge[AScr] = it_round(ShipY.data[0]-60);
        if (TEdge[AScr]<75) { TEdge[AScr] = 75; }
        for (i = 1; i<=40; i++)
        {
            if ((ShipX.data[0]-ShipX.data[i]*SizeFactor)<0)
            {
                FactorSin = (ShipX.data[0]+abs(ShipX.data[0]-ShipX.data[i]*SizeFactor))/ShipX.data[0];
                ShipX.data[i] = ShipX.data[0]/SizeFactor;
                ShipY.data[i] = ShipY.data[i]/FactorSin;
            }
        }

        SetAPen(&(MyScreen[AScr]->RastPort),124);
        /*** Antrieb ***/
        AreaMove(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[20]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[20]*SizeFactor));
        for (k = 21; k<=24; k++) { AreaDraw(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[k]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[k]*SizeFactor)); }
        AreaEnd(&(MyScreen[AScr]->RastPort));
        SetAPen(&(MyScreen[AScr]->RastPort),126);

        /*** BodenPlatte hell ***/
        AreaMove(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[13]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[13]*SizeFactor));
        for (k = 14; k<=16; k++) { AreaDraw(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[k]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[k]*SizeFactor)); }
        AreaEnd(&(MyScreen[AScr]->RastPort));

        /*** Seitenwand ***/
        AreaMove(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[17]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[17]*SizeFactor));
        for (k = 18; k<=19; k++) { AreaDraw(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[k]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[k]*SizeFactor)); }
        AreaEnd(&(MyScreen[AScr]->RastPort));
        SetAPen(&(MyScreen[AScr]->RastPort),127);

        /*** BodenPlatte ***/
        AreaMove(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[1]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[1]*SizeFactor));
        for (k = 2; k<=12; k++) { AreaDraw(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[k]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[k]*SizeFactor)); }
        AreaEnd(&(MyScreen[AScr]->RastPort));
        SetAPen(&(MyScreen[AScr]->RastPort),125);

        /*** Waffen ***/
        AreaMove(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[25]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[25]*SizeFactor));
        for (k = 26; k<=28; k++) { AreaDraw(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[k]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[k]*SizeFactor)); }
        AreaEnd(&(MyScreen[AScr]->RastPort));
        AreaMove(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[29]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[29]*SizeFactor));
        for (k = 30; k<=32; k++) { AreaDraw(&(MyScreen[AScr]->RastPort),it_round(ShipX.data[0]-ShipX.data[k]*SizeFactor),it_round(ShipY.data[0]-ShipY.data[k]*SizeFactor)); }
        AreaEnd(&(MyScreen[AScr]->RastPort));
        SetAPen(&(MyScreen[AScr]->RastPort),0);
        RectFill(&(MyScreen[AScr]->RastPort),0,75,0,200);
        if (ISize>1)
        {
            WRITE(320,220,123,16,MyScreen[AScr],FArr.data[l],SArr.data[l]);
            WRITE(320,245,123,16,MyScreen[AScr],FArr.data[l+1],SArr.data[l+1]);
        }
        ISize++;
        if (ISize>55)
        {
            l = l+2;
            ISize = 0;
        }
        Factor = Factor*1.018;
        SizeFactor = SizeFactor*1.0137;
    }
    while ((Factor<=3.2) && (SizeFactor<=3.2) && LMB_NOTPRESSED);
    if (LMB_PRESSED)
        { INTROEXIT(MyRastPtr); return; }
    
    if (l<16)
    {
        do
        {
            ScreenToFront(MyScreen[AScr]);
            AScr = 3-AScr;
            BltBitMapRastPort(&MyBitMap,0,0,&(MyScreen[AScr]->RastPort),0,75,640,360,192);
            if (ISize>0)
            {
                WRITE(320,220,123,16,MyScreen[AScr],FArr.data[l],SArr.data[l]);
                WRITE(320,245,123,16,MyScreen[AScr],FArr.data[l+1],SArr.data[l+1]);
            }
            ISize++;
            if (ISize>20)
            {
                l = l+2;
                ISize = 0;
            }
        }
        while ((l<=16) && LMB_NOTPRESSED);
    }
    INTROEXIT(MyRastPtr);
}
