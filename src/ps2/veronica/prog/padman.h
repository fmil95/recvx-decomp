#ifndef _PADMAN_H_
#define _PADMAN_H_

#include "types.h"

void InitReadKeyEx(int MaxPlayer);
void SetRepeatKeyTimer(unsigned int FirstTimer, unsigned int NextTimer);
int CheckSoftResetKeyFlag(int ControllerId);
void ClearSoftResetKeyFlag(int ControllerId);

extern PAD_WRK Pad[4] __attribute__((aligned(64)));
extern int SoftResetFlag;
extern int CurrentPortId;

#endif
