#include "main.h"
#include "backup.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_NaDebugFontFunction.h"
#include "sbinit.h"
#include "ps2_sg_sybt.h"
#include "sdfunc.h"

float cmat[16];
float BHD_ASPECT_X;
float BHD_ASPECT_Y;
int pd_port;
_anon11* hws;
SYS_WORK* sys;
_anon32* rom;
BH_PWORK* plp;

// void(*bhSysTaskJumpTab)()[23]; 
typedef void(*fn)(SYS_WORK*);
fn bhSysTaskJumpTab[23];

_anon24 tbuf[256];
float crmat[16];
_anon45 view;
float mbuf[16][128];
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
    int temp; // not from the debugging symbols

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
    
    njSetBorderColor(0);
    
    sbInitSystem(hws->mode, hws->frame, hws->count); 
    
    pdSetMode(0); 
    
    npSetMemory((unsigned char*)sys, sizeof(System), 0); 
    
    sys->ss_flg = 0x30000; 
   
    freemem = syMalloc(12845056); 
    
    temp = hws->vtx_total; 
    
    njpmemp = freemem + (12255232 - temp); 
    
    Ps2_PXLCONV = njpmemp + 4294639616;
    
    vwbmemp = freemem + (12517376 - hws->vtx_total); 
    vebmemp = freemem + (12845056 - hws->vtx_total); 
    
    njInitTextureBuffer(vwbmemp, 327680, temp, hws);
    
    njSetVertexBuffer((VertexBuffer*)vebmemp, hws->vtx_total); 

    njInitVertexBuffer(hws->vtx_opq_a, hws->vtx_opq_b, hws->vtx_trs_a, hws->vtx_trs_b, hws->vtx_punch);
    njInit3D(vwbmemp, 8192); 
    njInitMatrix(&mbuf[0][0], 128, 0);
    njInitPrint(0, 0, 0); 
    
    njPolygonCullingMode(0);
    
    njTextureShadingMode(2);
    
    njInitView(&view);
    
    njSetView(&view); 
    
    njGetMatrix(&crmat[0]); 
    
    npPlusInit(); 
    
    njInitTexture(&tbuf, 256); 
    
    njSetPaletteMode(2); 
    
    njPrintSize(13); 
    
    njSetAspect(BHD_ASPECT_X, BHD_ASPECT_Y); 
    
    njClipZ(-2.0f, -20000.0f); 
    
    njSetBackColor(0, 0, 0); 
    
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
