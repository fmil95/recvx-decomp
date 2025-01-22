#include "types.h"

float cmat[16]; /* UNUSED */
float BHD_ASPECT_X;
float BHD_ASPECT_Y;
int pd_port; /* UNUSED */
_anon11* hws;
_anon46* sys;
_anon32* rom; /* UNUSED */
BH_PWORK* plp; /* UNUSED */
typedef void(*fn)(System*); // not originally outputted by dwarf2cpp
fn bhSysTaskJumpTab[23]; // modified, below is the original definition 
//void(*bhSysTaskJumpTab)()[23];
_anon24 tbuf[256];
float crmat[16];
_anon45 view;
float mbuf[128][16];
unsigned char* vwbmemp;
unsigned char* vebmemp;
unsigned char* Ps2_PXLCONV;
unsigned char* njpmemp;
unsigned char* freemem;
unsigned int Ps2_sys_cnt;
unsigned char* keepmem; /* UNUSED */
unsigned char* fsize; /* UNUSED */
_anon27 eff[512]; /* UNUSED */
BH_PWORK ene[128]; /* UNUSED */
BH_PWORK ply; /* UNUSED */
_anon18 cam; /* UNUSED */
_anon32 romp; /* UNUSED */
_anon46 sysp; /* UNUSED */
_anon11 hwsp; /* UNUSED */
char BIO_CURRENT[64]; /* UNUSED */

void njUserInit();
int njUserMain();
void njUserExit();














































































































/* 100% match */
void njUserInit() { // Line 149, Address: 0x12b0f0
    int temp; // not originally outputted by dwarf2cpp
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    switch (syCblCheck()) { // Line 165, Address: 0x12b0f8                  
    case 1:
        hws->mode = 0x31; // Line 167, Address: 0x12b120
        hws->frame = 0; // Line 168, Address: 0x12b130
        hws->count = 2; // Line 169, Address: 0x12b13c
        break; // Line 170, Address: 0x12b144
    case 2:
        hws->mode = 0x60076; // Line 172, Address: 0x12b14c, 0x12b160
        hws->frame = 0; // Line 173, Address: 0x12b164
        hws->count = 1; // Line 174, Address: 0x12b15c, 0x12b170
        break; // Line 175, Address: 0x12b178
    default:
        hws->mode = 0x34; // Line 177, Address: 0x12b180
        hws->frame = 0; // Line 178, Address: 0x12b190
        hws->count = 1; // Line 179, Address: 0x12b19c
        break;
    }
    
    hws->vtx_opq_a = 0xFFF70000; // Line 183, Address: 0x12b1a8, 0x12b1c0
    hws->vtx_opq_b = 32768; // Line 184, Address: 0x12b1b4, 0x12b1c4
    hws->vtx_trs_a = 327680; // Line 185, Address: 0x12b1b8, 0x12b1d0
    hws->vtx_trs_b = 32768; // Line 186, Address: 0x12b1dc
    hws->vtx_punch = 32512; // Line 187, Address: 0x12b1bc, 0x12b1e8
    hws->vtx_total = bhCalcVtxBuffer(327680, 32768, 0xFFF70000); // Line 188, Address: 0x12b1f0
    InitFirstSofdec(); // Line 189, Address: 0x12b200
    njSetBorderColor(0); // Line 190, Address: 0x12b208
    sbInitSystem(hws->mode, hws->frame, hws->count); // Line 191, Address: 0x12b210
    pdSetMode(0); // Line 192, Address: 0x12b228
    npSetMemory((unsigned char*)sys, sizeof(System), 0); // Line 193, Address: 0x12b230
    sys->ss_flg = 0x30000; // Line 194, Address: 0x12b248
    
    
    
    
    
    freemem = syMalloc(12845056); // Line 200, Address: 0x12b254
    
    temp = hws->vtx_total; // Line 202, Address: 0x12b268, 0x12b280
    
    njpmemp = freemem + (12255232 - temp); // Line 204, Address: 0x12b29c

    
    Ps2_PXLCONV = njpmemp + 4294639616; // Line 207, Address: 0x12b274, 0x12b2b4
    
    vwbmemp = freemem + (12517376 - hws->vtx_total); // Line 209, Address: 0x12b278, 0x12b2c8, 0x12b2d4
    
    vebmemp = freemem + (12845056 - hws->vtx_total); // Line 211, Address: 0x12b27c, 0x12b2cc, 0x12b2e0
    njInitTextureBuffer(vwbmemp, 327680, temp, hws); // Line 212, Address: 0x12b2e8
    njSetVertexBuffer((VertexBuffer*)vebmemp, hws->vtx_total); // Line 213, Address: 0x12b300



    
    njInitVertexBuffer(hws->vtx_opq_a, hws->vtx_opq_b, hws->vtx_trs_a, hws->vtx_trs_b, hws->vtx_punch); // Line 218, Address: 0x12b320
    njInit3D(vwbmemp, 8192); // Line 219, Address: 0x12b330
    njInitMatrix(&mbuf[0][0], 128, 0); // Line 220, Address: 0x12b344
    njInitPrint(0, 0, 0); // Line 221, Address: 0x12b354
    njPolygonCullingMode(0); // Line 222, Address: 0x12b35c
    
    njTextureShadingMode(2); // Line 224, Address: 0x12b364
    njInitView(&view); // Line 225, Address: 0x12b370
    njSetView(&view); // Line 226, Address: 0x12b37c
    
    njGetMatrix(&crmat[0]); // Line 228, Address: 0x12b388
    
    npPlusInit(); // Line 230, Address: 0x12b390
    njInitTexture(&tbuf, 256); // Line 231, Address: 0x12b3a0
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    njSetPaletteMode(2); // Line 257, Address: 0x12b3a8 

        
        
        
        
        
        
        
        
        
        
        
        
    njPrintSize(13); // Line 271, Address: 0x12b3b0
    njSetAspect(BHD_ASPECT_X, BHD_ASPECT_Y); // Line 272, Address: 0x12b3c4
    njClipZ(-2.0f, -20000.0f); // Line 273, Address: 0x12b3e0
    
    njSetBackColor(0, 0, 0); // Line 275, Address: 0x12b3f0, 0x12b3fc
    
    sys->ss_flg = 0; // Line 277, Address: 0x12b3f8, 0x12b400

    
    sys->tk_flg = 0x1; // Line 280, Address: 0x12b408

    
    BupInit(); // Line 283, Address: 0x12b410
    
        
        
        
        
        
        
        
        
    InitSoundProgram(0); // Line 293, Address: 0x12b418
    Init_Expand(); // Line 294, Address: 0x12b420
}



/* 100% match */
int njUserMain() { // Line 300, Address: 0x12b430
    int i; 

    Ps2_sys_cnt++; // Line 303, Address: 0x12b440, 0x12b454
    
        
        
        
        
        
        
        
        
        
    for (i = 0; i < 23; i++) { // Line 314, Address: 0x12b450
        if (((sys->tk_flg & (1 << i))) && (!(sys->ts_flg & (1 << i)))) { // Line 315, Address: 0x12b460

            
            bhSysTaskJumpTab[i](sys); // Line 318, Address: 0x12b490
        } // Line 319, Address: 0x12b49c
    } // Line 320, Address: 0x12b4a0
    
    PS2_jikken(); // Line 322, Address: 0x12b4b0
    
    bhCheckSoftReset(); // Line 324, Address: 0x12b4b8
    
        
    
        
        
        
        
        
    return 0; // Line 333, Address: 0x12b4cc

    
} // Line 336, Address: 0x12b4c0, 0x12b4d0

// 100% matching!
void njUserExit() 
{ 
    ExitSoundProgram();
    
    BupExit(); 
    
    njExitTexture();
    njExitPrint(); 
    
    sbExitSystem(); 
    
    syBtExit(); 
} 
