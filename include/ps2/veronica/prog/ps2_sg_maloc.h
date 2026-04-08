#ifndef _PS2_SG_MALOC_H_
#define _PS2_SG_MALOC_H_

#include "types.h"
#include "macros.h"

typedef struct HM HM; 
struct HM
{
    // total size: 0x40
	unsigned int Use_size;    // offset 0x0, size 0x4
    unsigned int Total_size;  // offset 0x4, size 0x4
    unsigned int dummy;       // offset 0x8, size 0x4
	HM* pNext_work;           // offset 0xC, size 0x4
	unsigned int dummy64[12]; // offset 0x10, size 0x30
};

void syFree(void* ap);
void* syMalloc(unsigned int nbytes);
Void syMallocFinish(Void);
Void syMallocInit(Void *heap, Uint32 size);
Void syMallocStat(Uint32 *wholeFreeSize, Uint32 *biggestFreeBlockSize);

#endif
