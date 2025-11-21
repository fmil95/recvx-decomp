#ifndef _PS2_PXLCONV_H_
#define _PS2_PXLCONV_H_

#include "types.h"

#define PSMT4_BLOCK_WIDTH 32
#define PSMT4_BLOCK_HEIGHT 16

#define PSMCT32_BLOCK_WIDTH 8
#define PSMCT32_BLOCK_HEIGHT 8

#define PSMT4_PAGE_WIDTH    128
#define PSMT4_PAGE_HEIGHT   128
#define PSMCT32_PAGE_WIDTH  64
#define PSMCT32_PAGE_HEIGHT 32

void Tim2_Format_Check(void* tim2_ptr);

/*typedef struct _anon0;
typedef struct tagTIM2_FILEHEADER;


typedef unsigned int type_0[32];
typedef unsigned char type_1[8192];
typedef unsigned int type_2[32];
typedef unsigned int type_3[32];
typedef unsigned char type_4[8192];
typedef char type_5[4];
typedef unsigned int type_6[128];
typedef unsigned int type_7[32];
typedef unsigned int type_8[128];
typedef char type_9[8];
typedef unsigned char type_10[256];
typedef unsigned char type_11[19];
typedef unsigned int type_12[128];
typedef unsigned char type_13[256];
typedef int type_14[128];
typedef unsigned char type_15[8192];
typedef unsigned int type_16[2];
typedef unsigned int type_17[2];
typedef unsigned int type_18[128];
typedef unsigned char type_19[256];
typedef unsigned char type_20[8192];
typedef unsigned char type_21[256];
typedef int type_22[256];

struct _anon0
{
	unsigned int TotalSize;
	unsigned int ClutSize;
	unsigned int ImageSize;
	unsigned short HeaderSize;
	unsigned short ClutColors;
	unsigned char PictFormat;
	unsigned char MipMapTextures;
	unsigned char ClutType;
	unsigned char ImageType;
	unsigned short ImageWidth;
	unsigned short ImageHeight;
	unsigned int GsTex0[2];
	unsigned int GsTex1[2];
	unsigned int GsRegs;
	unsigned int GsTexClut;
};

struct tagTIM2_FILEHEADER
{
	char FileId[4];
	unsigned char FormatVersion;
	unsigned char FormatId;
	unsigned short Pictures;
	char Reserved[8];
};*/

#endif
