#ifndef _PS2_LOADSCREEN_H_
#define _PS2_LOADSCREEN_H_

#include "types.h"

typedef struct LOAD_SCREEN 
{
    // total size: 0x3C
    unsigned int ulState;                // offset 0x0, size 0x4
    unsigned int ulSubState;             // offset 0x4, size 0x4
    unsigned int ulMemCheckCountTimer;   // offset 0x8, size 0x4
    unsigned int ulFileSize;             // offset 0xC, size 0x4
    int lCardState;                      // offset 0x10, size 0x4
    short sCursorX;                      // offset 0x14, size 0x2
    short sCursorY;                      // offset 0x16, size 0x2
    short sSelectCur;                    // offset 0x18, size 0x2
    unsigned short usExitFlag;           // offset 0x1A, size 0x2
    unsigned short usSaveEnd;            // offset 0x1C, size 0x2
    unsigned short usLoopCount;          // offset 0x1E, size 0x2
    char cMesFlag;                       // offset 0x20, size 0x1
    char cCgFlag;                        // offset 0x21, size 0x1
    CONFIGFILE* pConfigFile;             // offset 0x24, size 0x4
    SAVEFILE* pSaveFile;                 // offset 0x28, size 0x4
    ICONINFORMATION* pIconInfo;          // offset 0x2C, size 0x4
    MEMORYCARDSTATE* pMcState;           // offset 0x30, size 0x4
    SELECTFILEINFO* pSelectFileInfo;     // offset 0x34, size 0x4
    SELECTFILEWINDOW* pSelectFileWindow; // offset 0x38, size 0x4
} LOAD_SCREEN;

LOAD_SCREEN* CreateLoadScreen(LOAD_SCREEN* pLoad, void* vpWorkPtrSys);
void DispLoadMessageSelect(char cSelectMes);
void DispLoadTexture(LOAD_SCREEN* pLoad);
int ExecuteLoadScreen(LOAD_SCREEN* pLoad);
void SetStateLoadScreenAwarenessCard(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenAwarenessCard(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrLostCard(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrLostCard(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrUnPS2MemCard(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrUnPS2MemCard(LOAD_SCREEN* pLoad);
void SetStateLoadScreenSelectCard(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenSelectCard(LOAD_SCREEN* pLoad);
void SetStateLoadScreenTitleExit(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenTitleExit(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrUnFormat(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrUnFormat(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrLostDirCheck(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrLostDirCheck(LOAD_SCREEN* pLoad);
void SetStateLoadScreenDirCheck(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenDirCheck(LOAD_SCREEN* pLoad);
void SetStateLoadScreenDirFileBroken(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenDirFileBroken(LOAD_SCREEN* pLoad);
void SetStateLoadScreenSelectFile(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenSelectFile(LOAD_SCREEN* pLoad);
void LoadScreenCheckSave(LOAD_SCREEN* pLoad);
void SetStateLoadScreenNoSave(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenNoSave(LOAD_SCREEN* pLoad);
void SetStateLoadScreenLoadCursor(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenLoadCursor(LOAD_SCREEN* pLoad);
void SetStateLoadScreenLoad(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenLoad(LOAD_SCREEN* pLoad);
void SetStateLoadScreenFileBroken(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenFileBroken(LOAD_SCREEN* pLoad);
void SetStateLoadScreenErrCardRead(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrCardRead(LOAD_SCREEN* pLoad);
void SetStateLoadScreenLoadExit(LOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenLoadExit(LOAD_SCREEN* pLoad);
void SetDispLoadSelectMessage();
void CheckDispLoadMemoryCard(LOAD_SCREEN* pLoad);

#endif
