#ifndef _PS2_SG_MALOC_H_
#define _PS2_SG_MALOC_H_

void syFree(void* ap);
void* syMalloc(unsigned int nbytes);
Void syMallocFinish(Void);
Void syMallocInit(Void *heap, Uint32 size);
Void syMallocStat(Uint32 *wholeFreeSize, Uint32 *biggestFreeBlockSize);

#endif
