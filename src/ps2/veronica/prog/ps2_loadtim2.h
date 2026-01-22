#ifndef _PS2_LOADTIM2_H_
#define _PS2_LOADTIM2_H_

#include "types.h"

typedef struct TIM2_FILEHEADER
{
    // total size: 0x10
    char FileId[4];              // offset 0x0, size 0x4
    unsigned char FormatVersion; // offset 0x4, size 0x1
    unsigned char FormatId;      // offset 0x5, size 0x1
    unsigned short Pictures;     // offset 0x6, size 0x2
    char Reserved[8];            // offset 0x8, size 0x8
} TIM2_FILEHEADER;

static int Tim2CalcBufWidth(int psm, int w);
void Set_GsTex(TIM2_PICTUREHEADER* ph, unsigned long send_image_adr, unsigned long send_clut_adr);
u_long128* MakeRenderTexHeader(void* tex_adr);
void StoreRenderTex(void* tex_adr);
int LoadToVram(unsigned long tbp, u_long128* addr, int tbw, int psm, int pos, int width, int height, int size);
void *UncAddr(void *val);
int Send_1024_Clut_data(void* clt_adr, unsigned long send_clut_adr);
int Send_Tim2_dataEx(void* tim2_top_adr, unsigned long send_image_adr, unsigned long send_clut_adr);
int Clut_Load_Func(TIM2_PICTUREHEADER* ph, unsigned long clut_addr);
int P32_Image_Load(TIM2_PICTUREHEADER* ph, unsigned long image_addr);
int Tim2_Image_Load(TIM2_PICTUREHEADER* ph, unsigned long image_addr);
void Ps2PxlconvCheck(void* timadr);
void SyncPath();
void D2_SyncTag();
void loadImage(void* tags);
void ClearVram();

#endif
