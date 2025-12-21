#include <stdio.h>
#include <string.h>

// EE library
#include <PREFIX_PS2_DEBUG.h>
#include <eeregs.h>

#include "override_katana.h"
// KATANA library
#include <ninja.h>
#include <katana_extra.h>

#include "types.h"
#include "enums.h"
#include "macros.h"

#include "main.h"
#include "backup.h"
#include "expand.h"
#include "fileview.h"
#include "flag.h"
#include "njplus.h"
#include "ps2_dummy.h"
#include "ps2_sg_maloc.h"
#include "ps2_sg_sybt.h"
#include "sbinit.h"
#include "sdfunc.h"
#include "sync.h"
#include "system.h"

#include "face_bh.c"
#include "face.c"
#include "hitchk.c"
#include "hitchkl.c"
#include "item.c"
#include "pl_evt.c"
#include "playpch2.c"
#include "ps2_MovieWork.c"
#include "ps2_NaColi.c"
#include "ps2_NaSprite.c"
#include "ps2_NinjaCnk_prog.h"
#include "ps2_SaveScreen.c"
#include "ps2_Vu1Scissor2.c"
#include "rutchk.c"
#include "subpl.c"
#include "weapon.c"
#include "zonzon.c"
#include "zonzon1.c"
#include "en01.c"
#include "en01b.c"
#include "en01sub.c"
#include "en02.c"
#include "en02sub.c"
#include "en03.c"
#include "en03sub.c"
#include "en04.c"
#include "en05.c"
#include "en05sub.c"
#include "en06.c"
#include "en06sub.c"
#include "en07.c"
#include "en08.c"
#include "en09.c"
#include "en10.c"
#include "en11.c"
#include "en12.c"
#include "en13.c"
#include "en13sub.c"
#include "en14.c"
#include "en15.c"
#include "en16.c"
#include "en17.c"
#include "en17sub.c"
#include "en18.c"
#include "en19.c"
#include "en20.c"
#include "en21.c"
#include "en22.c"
#include "en23.c"
#include "en24.c"
#include "en25.c"
#include "en26.c"
#include "en27.c"
#include "en29.c"
#include "en30.c"
#include "en54.c"
#include "en55.c"
#include "en71.c"
#include "enemy.h"
#include "binfunc.c"
#include "itemview.c"
#include "fileview.c"
#include "effsub0.c"
#include "effsub1.c"
#include "effsub1b.c"
#include "effsub2.c"
#include "effsub3.c"
#include "effsub4.c"
#include "effsub5.c"
#include "effsub6.c"
#include "ps2_NinjaPtcl.c"
#include "ps2_cri_adxt.c"
#include "Motion.c"
#include "playpch.c"

typedef void(*fn)();

BH_PWORK ene[128];
BH_PWORK ply;
BH_PWORK* plp = &ply;
NJS_TEXMEMLIST tbuf[256];
NJS_VIEW view;
HWS_WORK hwsp;
HWS_WORK* hws = &hwsp;
SYS_WORK sysp;
SYS_WORK* sys = &sysp;
char BIO_CURRENT[64]; /* unused */
float BHD_ASPECT_X = 1.174f;
float BHD_ASPECT_Y = 1.0f;
NJS_MATRIX crmat;
NJS_MATRIX* cmat = &crmat;
float mbuf[128][16] __attribute__((aligned(64)));
fn bhSysTaskJumpTab[23] = 
{
    bhSysCallInit,
    bhSysCallWarning,
    bhSysCallIpl,
    bhSysCallFirstmovie,
    bhSysCallTitle,
    bhSysCallOpening,
    bhSysCallPad,
    bhSysCallGame,
    bhSysCallEvent, 
    bhSysCallItemselect, 
    bhSysCallMap,
    bhSysCallDoordemo,
    bhSysCallMovie,
    bhSysCallEnding,
    bhSysCallGameover,
    bhSysCallTypewriter,
    bhSysCallOption,
    bhSysCallCompEvent,
    bhSysCallDiscChange,
    bhSysCallSoundMuseum,
    bhSysCallMonitor,
    bhSysCallSndMonitor,
    bhSysCallScreenSaver
};
int pd_port = -1;
unsigned char* Ps2_PXLCONV __attribute__((aligned(64)));
unsigned char* freemem;
unsigned char* fsize; /* unused */
unsigned char* keepmem;
unsigned char* njpmemp __attribute__((aligned(64)));
unsigned char* vebmemp;
unsigned char* vwbmemp;
unsigned int Ps2_sys_cnt;
O_WRK eff[512];
ROM_WORK romp;
ROM_WORK* rom = &romp;
unsigned int palbuf[4096] __attribute__((aligned(64)));
float Ps2_zbuff_a;
float Ps2_zbuff_b;
/*static */ float SinTable[16384];
unsigned char Ps2_PBUFF[1835008] __attribute__((aligned(64)));
sceGsDBuffDc Db;
PS2_GS_SAVE Ps2_gs_save __attribute__((aligned(64)));
unsigned int Ps2_current_texno;
NJS_TEXLIST* Ps2_current_texlist;
NJS_TEXMEMLIST* Ps2_current_texmemlist __attribute__((aligned(64)));
int iRingBufNum = 20;
int iop_read_buff;
unsigned int StatusUpdateCounter;
unsigned int DiscOpenTrayFlag;
PAD_ACT Pad_act[20];
BUTTON_INFO ButtonInfo[5] = 
{
    { 1, 55541},
    { 2, 55541},
    { 3, 55541},
    { 4, 55541},
    {-1, 0    }
}; 
PAD_WRK Pad[4] __attribute__((aligned(64))); 
int SoftResetFlag;
PAD_INFO Ps2_pad;
unsigned int Ps2_sys_cnt;
int CurrentPortId;
char ADX_STREAM_BUFFER[471040] __attribute__((aligned(64)));
int iop_data_buff;
SND_STATUS get_iop_snddata __attribute__((aligned(64)));
char sound_flag;
unsigned int SddFirstFlag;
char SdcGdDaVolume;
SYS_BT_SYSTEMID BootDiscSystemId;
int PatId[4] = { -1, -1, -1, -1 };
int OpenDriveTrayFlag;
unsigned char BackColorFlag;
unsigned char Pause_Flag;
unsigned char FontSz[126];
float FontScaleX;
float FontScaleCR;
SELECTFILEWINDOW SelectFileWindow;
SELECTFILEINFO SelectFileInfo[15] __attribute__((aligned(64)));
char* cpNameList[18] = 
{
    "icon.sys", "bio_cv.ico", "BASLUS-20184", "SAVEDATA-00", "SAVEDATA-01", "SAVEDATA-02", "SAVEDATA-03",
    "SAVEDATA-04", "SAVEDATA-05", "SAVEDATA-06", "SAVEDATA-07", "SAVEDATA-08", "SAVEDATA-09", "SAVEDATA-10",
    "SAVEDATA-11", "SAVEDATA-12", "SAVEDATA-13", "SAVEDATA-14"
}; 
ICONINFORMATION IconInfo;
MEMORYCARDSTATE McState;
SAVEFILE SaveFile;
CONFIGFILE ConfigFile;
unsigned char pl_sleep_cnt;
unsigned int Ps2_albinoid_flag;
CAM_WORK cam;
unsigned int Ps2_quad_color;
int Ps2_quad_trans; 
unsigned int Ps2_current_texno_bk;
NJS_TEXLIST* Ps2_current_texlist_bk;
int movie_draw;
u_long128 test_tag[1400] __attribute__((aligned(64)));
VoBuf voBuf __attribute__((aligned(64)));
RMI_WORK rmi;

// 100% matching!
void njUserInit(void)
{ 
    switch (syCblCheck())
    {              
    case 1:
        hws->mode = 0x31; 
        
        hws->frame = 0; 
        
        hws->count = 2; 
        break; 
    case 2:
        hws->mode = 0x60076; 
        
        hws->frame = 0; 
        
        hws->count = 1; 
        break; 
    default:
        hws->mode = 0x34; 
        
        hws->frame = 0; 
        
        hws->count = 1; 
    }
    
    hws->vtx_opq_a = 0xFFF70000; 
    hws->vtx_opq_b = 32768; 
    
    hws->vtx_trs_a = 327680; 
    hws->vtx_trs_b = 32768; 
    
    hws->vtx_punch = 32512; 
    
    hws->vtx_total = bhCalcVtxBuffer(327680, 32768, 0xFFF70000); 
    
    InitFirstSofdec(); 
    
    njSetBorderColor(0x00000000);
    
    sbInitSystem(hws->mode, hws->frame, hws->count); 
    
    pdSetMode(0); 
    
    npSetMemory((unsigned char*)sys, sizeof(SYS_WORK), 0); 
    
    sys->ss_flg = 0x30000; 
   
    freemem = syMalloc(12845056); 
    
    njpmemp = freemem + (12255232 - hws->vtx_total); 
    
    Ps2_PXLCONV = njpmemp + 4294639616;
    
    vwbmemp = freemem + (12517376 - hws->vtx_total); 
    vebmemp = freemem + (12845056 - hws->vtx_total); 
    
    njInitTextureBuffer((signed char*)vwbmemp, 327680);
    
    njSetVertexBuffer((unsigned int*)vebmemp, hws->vtx_total); 

    njInitVertexBuffer(hws->vtx_opq_a, hws->vtx_opq_b, hws->vtx_trs_a, hws->vtx_trs_b, hws->vtx_punch);
    njInit3D((NJS_VERTEX_BUF*)vwbmemp, 8192); 
    njInitMatrix((NJS_MATRIX*)&mbuf, 128, 0);
    njInitPrint(NULL, 0, 0); 
    
    njPolygonCullingMode(0);
    
    njTextureShadingMode(2);
    
    njInitView(&view);
    
    njSetView(&view); 
    
    njGetMatrix(&crmat); 
    
    npPlusInit(); 
    
    njInitTexture((NJS_TEXMEMLIST*)&tbuf, 256); 
    
    njSetPaletteMode(2); 
    
    njPrintSize(13); 
    
    njSetAspect(BHD_ASPECT_X, BHD_ASPECT_Y); 
    
    njClipZ(-2.0f, -20000.0f); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000); 
    
    sys->ss_flg = 0;
    sys->tk_flg = 0x1; 

    BupInit(); 
  
    InitSoundProgram(0);
    
    Init_Expand(); 
}

// 100% matching!
Sint32 njUserMain(void) 
{ 
    int i; 

    Ps2_sys_cnt++; 
  
    for (i = 0; i < 23; i++) 
    { 
        if (((sys->tk_flg & (1 << i))) && (!(sys->ts_flg & (1 << i)))) 
        { 
            bhSysTaskJumpTab[i](); 
        } 
    } 
    
    PS2_jikken(); 
    
    bhCheckSoftReset(); 
    
    return 0; 
} 

// 100% matching!
void njUserExit(void)
{ 
    ExitSoundProgram();
    
    BupExit(); 
    
    njExitTexture();
    njExitPrint(); 
    
    sbExitSystem(); 
    
    syBtExit(); 
} 
