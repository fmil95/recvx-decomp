#ifndef _PS2_NATEXTUREFUNCTION_H_
#define _PS2_NATEXTUREFUNCTION_H_

#include "types.h"
#include "macros.h"

void Ps2MemCopy4(void* vpDst, void* vpSrc, int lNum);
void	njInitTextureBuffer(Sint8 *addr,Uint32 size);
void	njInitTexture(NJS_TEXMEMLIST *addr,Uint32 n);
void	njExitTexture(void);
int SearchNumber(unsigned int global_index, unsigned int bank);
int SearchNullNumber();
Sint32	njLoadTexture(NJS_TEXLIST *texlist);
Sint32	njSetTexture(NJS_TEXLIST *texlist);
Sint32	njSetTextureNum(Uint32 n);
Sint32	njSetTextureNumG(Uint32 globalIndex);
int njSetTextureNumSys(unsigned int n);
void	njReleaseTextureAll(void);
Sint32	njReleaseTexture(NJS_TEXLIST *texlist);
Uint32	njCalcTexture(Uint32 flag);
void	njSetTextureInfo(NJS_TEXINFO *info,Uint16 *tex,Sint32 Type,Sint32 nWidth,Sint32 nHeight);
void	njSetTextureName(NJS_TEXNAME *texname,void *addr,Uint32 globalIndex,Uint32 attr);
/*void njRenderTextureNum();
void njRenderTextureNumG(unsigned int globalIndex);
void njSetRenderWidth(unsigned int nWidth);
void njSetPaletteBankNum(unsigned int n, int bank);*/
void 	njSetPaletteMode(Uint32 mode);
Uint32	njGetPaletteMode(void);
void 	njSetPaletteData(Sint32 offset,Sint32 count,void* data);
void	njGarbageTexture(NJS_TEXMEMLIST *addr,Uint32 n);
unsigned int Ps2GetTim2Size(void* p);
int Ps2TextureMalloc(NJS_TEXMEMLIST* p);
int Ps2TextureFree(NJS_TEXMEMLIST* p);
int Ps2ReplaceTexAddr(unsigned int gindex, void* rep_addr);
int Ps2TextureGarbageCollectionAll();
int ring_check();

/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;

typedef char*(*type_3)(char*, int);

typedef unsigned int type_0[1024];
typedef unsigned int type_1[4096];
typedef char type_2[4];
typedef unsigned int type_4[27];

struct _anon0
{
	void* texaddr;
	_anon10 texsurface;
};

struct _anon1
{
	unsigned int globalIndex;
	unsigned int bank;
	unsigned int tspparambuffer;
	unsigned int texparambuffer;
	unsigned int texaddr;
	_anon0 texinfo;
	unsigned short count;
	unsigned short dummy;
};

struct _anon2
{
	_anon3* textures;
	unsigned int nbTexture;
};

struct _anon3
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon4
{
	char FileId[4];
	unsigned char FormatVersion;
	unsigned char FormatId;
	unsigned short Pictures;
	unsigned int Gindex;
	unsigned char OrgColorType;
	unsigned char OrgTexType;
	unsigned short ClutChange;
	unsigned int PalNum;
	unsigned int PalData[27];
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
	_anon6 GsTex0;
	_anon9 GsTex1;
	unsigned int GsRegs;
	unsigned int GsTexClut;
	_anon8 admin;
	unsigned int TpFlag;
	unsigned int ClampFlag;
};

struct _anon5
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon6
{
	struct
	{
		unsigned long TBP0 : 14;
		unsigned long TBW : 6;
		unsigned long PSM : 6;
		unsigned long TW : 4;
		unsigned long TH : 4;
		unsigned long TCC : 1;
		unsigned long TFX : 2;
		unsigned long CBP : 14;
		unsigned long CPSM : 4;
		unsigned long CSM : 1;
		unsigned long CSA : 5;
		unsigned long CLD : 3;
	};
};

struct _anon7
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon8
{
	unsigned int gindex;
	unsigned int size;
	unsigned int count;
	void* addr;
	void* before;
	void* after;
};

struct _anon9
{
	struct
	{
		unsigned long LCM : 1;
		unsigned long pad01 : 1;
		unsigned long MXL : 3;
		unsigned long MMAG : 1;
		unsigned long MMIN : 3;
		unsigned long MTBA : 1;
		unsigned long pad10 : 9;
		unsigned long L : 2;
		unsigned long pad21 : 11;
		unsigned long K : 12;
		unsigned long pad44 : 20;
	};
};

struct _anon10
{
	unsigned int Type;
	unsigned int BitDepth;
	unsigned int PixelFormat;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int TextureSize;
	unsigned int fSurfaceFlags;
	unsigned int* pSurface;
	unsigned int* pVirtual;
	unsigned int* pPhysical;
};*/

#endif
