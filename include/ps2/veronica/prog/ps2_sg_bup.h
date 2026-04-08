#ifndef _PS2_SG_BUP_H_
#define _PS2_SG_BUP_H_

#include "types.h"
#include "katana_extra.h"

Sint32 buExit(void);
Sint32 buGetDiskInfo(Sint32 drive, BUS_DISKINFO* info);
Sint32 buInit(Sint32 capacity, Sint32 drives, void* work, BU_INITCALLBACK func);
void buSetCompleteCallback(BU_COMPLETECALLBACK func);
void buSetProgressCallback(BU_PROGRESSCALLBACK func);

#endif
