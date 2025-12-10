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
void	njRenderTextureNum(Uint32 n);
void	njRenderTextureNumG(Uint32 globalIndex);
void	njSetRenderWidth(Uint32 nWidth);
void 	njSetPaletteBankNum(Uint32 n,Sint32 bank);
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

#endif
