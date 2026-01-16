#ifndef _DREAD_H_
#define _DREAD_H_

#include "types.h"

#define SKIN_MAGIC (0x4E494B53)

void bhReadPlayerData();
void bhReadWeaponData();
unsigned char* bhKeepObjWork(ML_WORK* mp, unsigned char* sp);

#endif
