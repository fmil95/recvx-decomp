#ifndef _BACKUP_H_
#define _BACKUP_H_

void BupInit(void);
void BupExit(void);
static void ClearInfo(Sint32 drive);
static Sint32 BupComplete(Sint32 drive, Sint32 op, Sint32 stat, Uint32 param);
static Sint32 BupProgress(Sint32 drive, Sint32 op, Sint32 count, Sint32 max);
static void BupInitCallback(void);

#endif
