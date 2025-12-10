#ifndef _PS2_LOADTIM2_H_
#define _PS2_LOADTIM2_H_

#include "types.h"

int Tim2CalcBufWidth(int psm, int w);
void Set_GsTex(TIM2_PICTUREHEADER* ph, unsigned long send_image_adr, unsigned long send_clut_adr);
u_long128* MakeRenderTexHeader(void* tex_adr);
void StoreRenderTex(void* tex_adr);
int LoadToVram(unsigned long tbp, u_long128* addr, int tbw, int psm, int pos, int width, int height, int size);
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

void *UncAddr(void *val);

#endif
