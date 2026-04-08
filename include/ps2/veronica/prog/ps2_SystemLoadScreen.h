#ifndef _PS2_SYSTEMLOADSCREEN_H_
#define _PS2_SYSTEMLOADSCREEN_H_

#include "types.h"

typedef struct SYSLOAD_SCREEN 
{
    // total size: 0x38
    unsigned int ulState;                // offset 0x0, size 0x4
    unsigned int ulSubState;             // offset 0x4, size 0x4
    unsigned int ulMemCheckCountTimer;   // offset 0x8, size 0x4
    unsigned int ulFileSize;             // offset 0xC, size 0x4
    unsigned short usExitFlag;           // offset 0x10, size 0x2
    unsigned short usLoopCount;          // offset 0x12, size 0x2
    int lCardState;                      // offset 0x14, size 0x4
    char cMesFlag;                       // offset 0x18, size 0x1
    CONFIGFILE* pConfigFile;             // offset 0x1C, size 0x4
    SAVEFILE* pSaveFile;                 // offset 0x20, size 0x4
    ICONINFORMATION* pIconInfo;          // offset 0x24, size 0x4
    MEMORYCARDSTATE* pMcState;           // offset 0x28, size 0x4
    SELECTFILEINFO* pSelectFileInfo;     // offset 0x2C, size 0x4
    SELECTFILEWINDOW* pSelectFileWindow; // offset 0x30, size 0x4
    void* vpReadBuffer;                  // offset 0x34, size 0x4
} SYSLOAD_SCREEN;

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
