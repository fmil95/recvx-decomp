
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
#include <sif.h>
#include <libmpeg.h>
#include <stdarg.h>
#include <va-mips.h>

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

#include "../../../cri/mwlib/ee/lib/libadxe/override_adxf.h"
// CRIWARE library
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxf.h>
#include "../../../cri/mwlib/ee/lib/libadxe/override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>
#include <adx_ps2.h>

#include "types.h"
#include "enums.h"
#include "macros.h"

#include "main.h"

#include "../../../cri/mwlib/ee/lib/libadxe/lsc.c"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_tlk.c"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_tlk2.c"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_tsvr.c"

#include "face_bh.c"
#include "face.c"
#include "gcc_wrapper.c"
#include "hitchk.c"
#include "hitchkl.c"
#include "item.c"
#include "light.c"
#include "MdlPut.c"
#include "pl_evt.c"
#include "playpch2.c"
#include "ps2_MovieWork.c"
#include "ps2_NaColi.c"
#include "ps2_NaGraphics3D.c"
#include "ps2_NaSprite.c"
#include "ps2_NinjaCnk_prog.h"
#include "ps2_Ninjapad.c"
#include "ps2_SaveScreen.c"
#include "ps2_SystemSaveScreen.c"
#include "ps2_Vu1Scissor2.c"
#include "ps2_Vu1Strip.c"
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
#include "cut.c"
#include "itemview.c"
#include "fileview.c"
#include "ps2_NaMem.c"
#include "njplus.c"
#include "effsub0.c"
#include "effsub1.c"
#include "effsub1b.c"
#include "effsub2.c"
#include "effsub3.c"
#include "effsub4.c"
#include "effsub5.c"
#include "effsub6.c"
#include "camera.c"
#include "eneset.c"
#include "objitm.c"
#include "room.c"
#include "dread.c"
#include "sub1.c"
#include "ps2_sg_maloc.c"
#include "backup.c"
#include "expand.c"
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
#include "screen.c"
#include "ps2_sfd_mw.c"
#include "ps2_sg_bup.c"
#include "ps2_dvd_image.c"
#include "ps2_sg_gd.c"
#include "gdlib.c"
#include "ps2_sg_pdvib.c"
#include "ps2_sg_pad.c"
#include "ps2_dummy.c"
#include "ps2_NinjaPtcl.c"
#include "ps2_NaDraw.c"
#include "ps2_sg_sycfg.c" // TODO: find out why this file crashes when including it amongst the other source files in compile_config.json
#include "ps2_sg_sybt.c"
#include "ps2_sg_sycbl.c"
#include "ps2_cri_adxt.c"
#include "adxwrap.c"
#include "ps2_snddrv.c"
#include "ps2_MovieFunc.c"
#include "ps2_sg_sd.c"
#include "sdc.c"
#include "padman.c"
#include "mwwrap.c"
#include "sdfunc.c"
#include "sdcwrap.c"
#include "sync.c"
#include "ps2_NaFog.c"
#include "gameover.c"
#include "message.c"
#include "ranking.c"
#include "sp_evt.c"
#include "pwksub.c"
#include "bup_00.c"
#include "ps2_MemoryCard.c"
#include "ps2_McSaveFile.c"
#include "ps2_LoadScreen.c"
#include "ps2_SystemLoadScreen.c"
#include "Motion.c"
#include "player.c"
#include "door.c"
#include "map.c"
#include "effect.c"
#include "event.c"
#include "adv.c"
#include "pad.c"
#include "game.c"
#include "system.c"
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
char BIO_CURRENT[64];
float BHD_ASPECT_X = 1.174f;
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
