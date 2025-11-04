#ifndef _PS2_SYSTEMLOADSCREEN_H_
#define _PS2_SYSTEMLOADSCREEN_H_

#include "types.h"

SYSLOAD_SCREEN* CreateSysLoadScreen(SYSLOAD_SCREEN* pSysLoad, void* vpWorkPtrSys);
void DispSysLoadMessageSelect(int slSelectMes);
int ExecuteSysLoadScreen(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenAwarenessCard(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenAwarenessCard(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenErrAwareness(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenErrAwareness(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenDirCheck(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenDirCheck(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenFreeCapacity(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenFreeCapacity(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenErrFreeCapacity(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenErrFreeCapacity(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenNoSysFile(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenNoSysFile(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenSysLoad(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenSysLoad(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenFileBroken(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenFileBroken(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenErrCardRead(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenErrCardRead(SYSLOAD_SCREEN* pSysLoad);
void SetStateSysLoadScreenTitleExit(SYSLOAD_SCREEN* pSysLoad);
void ExecuteStateSysLoadScreenTitleExit();

#endif
