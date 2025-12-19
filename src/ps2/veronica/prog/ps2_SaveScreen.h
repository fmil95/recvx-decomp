#ifndef _PS2_SAVESCREEN_H_
#define _PS2_SAVESCREEN_H_

typedef struct SAVE_SCREEN 
{
    // total size: 0x40
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
    void* vpReadBuffer;                  // offset 0x3C, size 0x4
} SAVE_SCREEN;

SAVE_SCREEN* CreateSaveScreen(SAVE_SCREEN* pSave, void* vpWorkPtrSys);
void DispMessageSelect(char cSelectMes);
void DispTexture(SAVE_SCREEN* pSave);
int ExecuteSaveScreen(SAVE_SCREEN* pSave);
void SetStateSaveScreenAwarenessCard(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenAwarenessCard(SAVE_SCREEN* pSave);
void SetStateSaveScreenErrLostCard(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenErrLostCard(SAVE_SCREEN* pSave);
void SetStateSaveScreenErrUnPS2MemCard(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenErrUnPS2MemCard(SAVE_SCREEN* pSave);
void SetStateSaveScreenSelectCard(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSelectCard(SAVE_SCREEN* pSave);
void SetStateSaveScreenExit(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenExit(SAVE_SCREEN* pSave);
void SetSaveScreenSpecialSave(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSpecialSave(SAVE_SCREEN* pSave);
void SetStateSaveScreenLostDirCheck(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenLostDirCheck(SAVE_SCREEN* pSave);
void SetStateSaveScreenFreeCapacity(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenFreeCapacity(SAVE_SCREEN* pSave);
void SetStateSaveScreenErrFreeCapacity(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenErrFreeCapacity(SAVE_SCREEN* pSave);
void SetStateSaveScreenCreateSaveFileCheck(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenCreateSaveFileCheck(SAVE_SCREEN* pSave);
void SetStateSaveScreenCreateSaveFile(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenCreateSaveFile(SAVE_SCREEN* pSave);
void SetStateSaveScreenErrCreateSaveFile(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenErrCreateSaveFile(SAVE_SCREEN* pSave);
void SetStateSaveScreenSelectFile(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSelectFile(SAVE_SCREEN* pSave);
void SetStateSaveScreenSaveCursor(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSaveCursor(SAVE_SCREEN* pSave);
void SetStateSaveScreenSaveCursorOld(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSaveCursorOld(SAVE_SCREEN* pSave);
void SetStateSaveScreenSaveCursorNew(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSaveCursorNew(SAVE_SCREEN* pSave);
void SetStateSaveScreenSave(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSave(SAVE_SCREEN* pSave);
void SetStateSaveScreenSuccessCardWrite(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSuccessCardWrite(SAVE_SCREEN* pSave);
void SetStateSaveScreenSuccessCardWriteMessage(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSuccessCardWriteMessage(SAVE_SCREEN* pSave);
void SetStateSaveScreenErrCardWrite(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenErrCardWrite(SAVE_SCREEN* pSave);
void SetStateSaveScreenFormat(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenFormat(SAVE_SCREEN* pSave);
void SetStateSaveScreenStartFormat(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenStartFormat(SAVE_SCREEN* pSave);
void SetStateSaveScreenExitFormat(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenExitFormat(SAVE_SCREEN* pSave);
void SetStateSaveScreenSuccessFormat(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenSuccessFormat(SAVE_SCREEN* pSave);
void SetStateSaveScreenErrFormat(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenErrFormat(SAVE_SCREEN* pSave);
void SetStateSaveScreenErrDer(SAVE_SCREEN* pSave);
void ExecuteStateSaveScreenErrDer(SAVE_SCREEN* pSave);
void SetDispSelectMessage();
void CheckDispMemoryCard(SAVE_SCREEN* pSave);

#endif
