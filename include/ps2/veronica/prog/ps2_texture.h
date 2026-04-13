#ifndef _PS2_TEXTURE_H_
#define _PS2_TEXTURE_H_

#include "types.h"
#include "macros.h"

typedef struct PS2_TEX_SAVE
{
	// total size: 0x4804
	unsigned int num;         // offset 0x0, size 0x4
	NJS_TEXMEMLIST tmem[256]; // offset 0x4, size 0x4400
	void* addr[256];          // offset 0x4404, size 0x400
} PS2_TEX_SAVE;

void ClutCopy(void* data, void* org_data);
void ClutCopy256(void* data, void* org_data);
int isVQ(unsigned char type);
int bhSetMemPvpTexture(NJS_TEXLIST* tlp, unsigned char* datp, int offset);
void bhReleaseMainTexture();
void Init_PS2_SAVE_TEX();
char* bhCopyTexmem2Mainmem(NJS_TEXLIST* tlp, char* adr);
char* bhCopyTexmem2MainmemSub(NJS_TEXLIST* tlp, char* adr);
void bhCopyMainmem2Texmem(NJS_TEXLIST* tlp);
void bhPushAllTexture();
void bhPopAllTexture();
void bhGarbageTexture(NJS_TEXMEMLIST* addr, unsigned int n);

#endif
