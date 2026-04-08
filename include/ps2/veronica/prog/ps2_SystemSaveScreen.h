#ifndef _PS2_SYSTEMSAVESCREEN_H_
#define _PS2_SYSTEMSAVESCREEN_H_

#include "types.h"

typedef struct SYSSAVE_SCREEN 
{
    // total size: 0x3C
    unsigned int ulState;                // offset 0x0, size 0x4
    unsigned int ulSubState;             // offset 0x4, size 0x4
    unsigned int ulMemCheckCountTimer;   // offset 0x8, size 0x4
    unsigned int ulFileSize;             // offset 0xC, size 0x4
    int lCardState;                      // offset 0x10, size 0x4
    short sSelectCur;                    // offset 0x14, size 0x2
    unsigned short usExitFlag;           // offset 0x16, size 0x2
    unsigned short usMesMode;            // offset 0x18, size 0x2
    unsigned short usSaveMode;           // offset 0x1A, size 0x2
    unsigned short usLoopCount;          // offset 0x1C, size 0x2
    char cMesFlag;                       // offset 0x1E, size 0x1
    CONFIGFILE* pConfigFile;             // offset 0x20, size 0x4
    SAVEFILE* pSaveFile;                 // offset 0x24, size 0x4
    ICONINFORMATION* pIconInfo;          // offset 0x28, size 0x4
    MEMORYCARDSTATE* pMcState;           // offset 0x2C, size 0x4
    SELECTFILEINFO* pSelectFileInfo;     // offset 0x30, size 0x4
    SELECTFILEWINDOW* pSelectFileWindow; // offset 0x34, size 0x4
    void* vpReadBuffer;                  // offset 0x38, size 0x4
} SYSSAVE_SCREEN;

SYSSAVE_SCREEN* CreateSysSaveScreen(SYSSAVE_SCREEN* pSysSave, void* vpWorkPtrSys, unsigned short usSaveMesMode, unsigned short usSaveWriteMode);
void DispSysSaveMessageSelect(SYSSAVE_SCREEN* pSysSave);
int ExecuteSysSaveScreen(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveAwarenessCard(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveAwarenessCard(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveErrUnPS2MemCard(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveErrUnPS2MemCard(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveErrLostCard(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveErrLostCard(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveErrPort2(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveErrPort2(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveDirCheck(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveDirCheck(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveFreeCapacity(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveFreeCapacity(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveErrFreeCapacity(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveErrFreeCapacity(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveCheckWriteSysData(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveCheckWriteSysData(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveWriteSysData(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveWriteSysData(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveSuccessWriteSysData(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveSuccessWriteSysData(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveErrWriteSysData(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveErrWriteSysData(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveFileBroken(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveFileBroken(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveExitWriteSysData(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveExitWriteSysData(SYSSAVE_SCREEN* pSysSave);
void SetStateWriteRankingData(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateWriteRankingData(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSave(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSave(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveErrCardWrite(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveErrCardWrite(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveFormat(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveFormat(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveStartFormat(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveStartFormat(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveExitFormat(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveExitFormat(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveSuccessFormat(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveSuccessFormat(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveErrFormat(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveErrFormat(SYSSAVE_SCREEN* pSysSave);
void SetStateSysSaveTitleExit(SYSSAVE_SCREEN* pSysSave);
void ExecuteStateSysSaveTitleExit();
void SysSaveHikaku(CONFIGFILE* pConfig);
unsigned int GetOkButton();
unsigned int GetCancelButton();

#endif
