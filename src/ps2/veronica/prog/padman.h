#ifndef _PADMAN_H_
#define _PADMAN_H_

#include "types.h"

typedef struct REPEAT_INFO
{
	// total size: 0xC
    unsigned int WaitFlag; // offset 0x0, size 0x4
    unsigned int WaitCnt;  // offset 0x4, size 0x4
    unsigned int Key;      // offset 0x8, size 0x4
} REPEAT_INFO;

void InitReadKeyEx(int MaxPlayer);
void SetRepeatKeyTimer(unsigned int FirstTimer, unsigned int NextTimer);
int CheckSoftResetKeyFlag(int ControllerId);
void ClearSoftResetKeyFlag(int ControllerId);

extern PAD_WRK Pad[4] __attribute__((aligned(64)));
extern int SoftResetFlag;
extern int CurrentPortId;

#endif
