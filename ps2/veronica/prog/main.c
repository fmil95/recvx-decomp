#include "main.h"
#include "backup.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_NaDebugFontFunction.h"
#include "sbinit.h"
#include "ps2_sg_sybt.h"
#include "sdfunc.h"
#include "sync.h"
#include "ps2_dummy.h"
#include "njplus.h"
#include "expand.h"
#include "system.h"
#include "ps2_NaView.h"
#include "ps2_NinjaCnk.h"
#include "ps2_NaMatrix.h"

float cmat[16];
float BHD_ASPECT_X;
float BHD_ASPECT_Y;
int pd_port;
NO_NAME_13* hws;
SYS_WORK* sys;
_anon32* rom;
BH_PWORK* plp;

// void(*bhSysTaskJumpTab)()[23]; 
typedef void(*fn)(SYS_WORK* sys);
fn bhSysTaskJumpTab[23];

NJS_TEXMEMLIST tbuf[256];
float crmat[16];
NO_NAME_12 view;
float mbuf[128][16]; 
unsigned char* vwbmemp;
unsigned char* vebmemp;
unsigned char* Ps2_PXLCONV;
unsigned char* njpmemp;
unsigned char* freemem;
unsigned int Ps2_sys_cnt;
unsigned char* keepmem;
unsigned char* fsize;
_anon27 eff[512];
BH_PWORK ene[128];
BH_PWORK ply;
_anon18 cam;
_anon32 romp;
_anon46 sysp;
_anon11 hwsp;
char BIO_CURRENT[64];

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
    
    // npSetMemory((unsigned char*)sys, sizeof(SYS_WORK), 0); 
    npSetMemory((unsigned char*)sys, 0x2ACF0, 0); 
    
    sys->ss_flg = 0x30000; 
   
    freemem = syMalloc(12845056); 
    
    njpmemp = freemem + (12255232 - hws->vtx_total); 
    
    Ps2_PXLCONV = njpmemp + 4294639616;
    
    vwbmemp = freemem + (12517376 - hws->vtx_total); 
    vebmemp = freemem + (12845056 - hws->vtx_total); 
    
    njInitTextureBuffer((signed char*)vwbmemp, 327680);
    
    njSetVertexBuffer((unsigned long*)vebmemp, hws->vtx_total); 

    njInitVertexBuffer(hws->vtx_opq_a, hws->vtx_opq_b, hws->vtx_trs_a, hws->vtx_trs_b, hws->vtx_punch);
    njInit3D((NJS_VERTEX_BUF*)vwbmemp, 8192); 
    njInitMatrix((NJS_MATRIX*)&mbuf, 128, 0);
    njInitPrint(NULL, 0, 0); 
    
    njPolygonCullingMode(0);
    
    njTextureShadingMode(2);
    
    njInitView((NJS_VIEW*)&view);
    
    njSetView((NJS_VIEW*)&view); 
    
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
            bhSysTaskJumpTab[i](sys); 
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
