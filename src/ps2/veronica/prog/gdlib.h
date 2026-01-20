#ifndef _GDLIB_H_
#define _GDLIB_H_

#include "override_katana.h"
#include <sg_gd.h>

typedef struct LFOPEN_INFO
{
	// total size: 0x8
    unsigned int Flag; // offset 0x0, size 0x4
    GDFS GdFs;         // offset 0x4, size 0x4
} LFOPEN_INFO;

void LfInitLib();
void CallbackGdErrorFunc(int param, int err);
unsigned int InitGdSystem();
unsigned int InitGdSystemEx(unsigned int MaxDirNum);
void ExitGdSystem();
int GetFileSize(char* FileName);
int ReadFileEx(char* FileName, void* ReadAddress);
unsigned int CheckOpenTray();

extern unsigned int StatusUpdateCounter;
extern unsigned int DiscOpenTrayFlag;

#endif
