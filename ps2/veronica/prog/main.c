
#include <PREFIX_PS2_DEBUG.h>

// EE library
#include <eekernel.h>
#include <eeregs.h>
#include <eestruct.h>
#include <libdev.h>
#include <libdma.h>
#include <libgraph.h>
#include <libpkt.h>
#include <libvu0.h>
#include <sifdev.h>
#include <libmc.h>
#include <libcdvd.h>
#include <libpad.h>
#include <csl.h>
#include <libssyn.h>
#include <libsdr.h>

#include "override_katana.h"
// KATANA library
#include <ninja.h>
#include <sg_sycbl.h>
#include <sg_bup.h>
#include <sg_gd.h>
#include <sg_syrtc.h>
#include <sg_sd2.h>
#include <sg_pdvib.h>
#include <sg_mw.h>
#include <limits.h>

#include <katana_extra.h>

// CRIWARE library
#include <cri_adxf.h>
#include <cri_adxt.h>
#include <adx_ps2.h>

#include "types.h"
#include "enums.h"
#include "macros.h"

#include "ps2_NaMem.c"
#include "camera.c"
#include "eneset.c"
#include "objitm.c"
#include "room.c"
#include "dread.c"
#include "ps2_MemoryCard.c"
#include "ps2_McSaveFile.c"
#include "ps2_SystemLoadScreen.c"
#include "ps2_sg_maloc.c"
#include "backup.c"
#include "expand.c"
#include "njplus.c"
#include "ps2_event.c"
#include "ps2_NaDebugFontFunction.c"
#include "ps2_NaDraw2D.c"
#include "ps2_NaMath.c"
#include "ps2_NaMatrix.c"
#include "ps2_pxlconv.c"
#include "ps2_loadtim2.c"
#include "ps2_NaSystem.c"
#include "ps2_texture.c"
#include "ps2_NaTextureFunction.c"
#include "ps2_NaView.c"
#include "ps2_NinjaCnk.c"
#include "ps2_sfd_mw.c"
#include "ps2_sg_bup.c"
#include "ps2_dvd_image.c"
#include "ps2_sg_gd.c"
#include "gdlib.c"
#include "ps2_sg_pdvib.c"
#include "ps2_sg_pad.c"
#include "ps2_dummy.c"
#include "ps2_NaDraw.c"
#include "ps2_sg_sybt.c"
#include "ps2_sg_sycbl.c"
#include "cri_placeholders.c"
#include "adxwrap.c"
#include "ps2_snddrv.c"
#include "ps2_MovieFunc.c"
#include "ps2_sg_sd.c"
#include "sdc.c"
#include "pad.c"
#include "padman.c"
#include "mwwrap.c"
#include "sdfunc.c"
#include "sdcwrap.c"
#include "sync.c"
#include "ps2_NaFog.c"
#include "game.c"
#include "gameover.c"
#include "ranking.c"
#include "sp_evt.c"
#include "pwksub.c"
#include "bup_00.c"
#include "message.c"
#include "player.c"
#include "screen.c"
#include "door.c"
#include "sub1.c"
#include "map.c"
#include "effect.c"
#include "event.c"
#include "adv.c"
#include "system.c"

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
char BIO_CURRENT[64];
float BHD_ASPECT_X = 1.174000025f;
float BHD_ASPECT_Y = 1.0f;
NJS_MATRIX crmat;
NJS_MATRIX* cmat = &crmat;
float mbuf[128][16];
fn bhSysTaskJumpTab[23] = {
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
unsigned char* Ps2_PXLCONV;
unsigned char* freemem;
unsigned char* fsize;
unsigned char* keepmem;
unsigned char* njpmemp;
unsigned char* vebmemp;
unsigned char* vwbmemp;
unsigned int Ps2_sys_cnt;
//_anon18 cam;
//_anon27 eff[512];
ROM_WORK romp;
ROM_WORK* rom = &romp;

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
