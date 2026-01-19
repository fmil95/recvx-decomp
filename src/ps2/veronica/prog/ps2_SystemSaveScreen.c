#include "ps2_SystemSaveScreen.h"
#include "adv.h"
#include "message.h"
#include "ps2_McSaveFile.h"
#include "ps2_MemoryCard..h"
#include "main.h"

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

// 100% matching!
SYSSAVE_SCREEN* CreateSysSaveScreen(SYSSAVE_SCREEN* pSysSave, void* vpWorkPtrSys, unsigned short usSaveMesMode, unsigned short usSaveWriteMode)
{
    pSysSave->ulState = 0;
    pSysSave->ulSubState = 0;
    
    pSysSave->ulMemCheckCountTimer = 0;
    
    pSysSave->ulFileSize = 0;
    
    pSysSave->lCardState = 0;
    
    pSysSave->usExitFlag = 0;
    
    pSysSave->usMesMode = usSaveMesMode;
    pSysSave->usSaveMode = usSaveWriteMode;
    
    pSysSave->usLoopCount = 0;
    
    pSysSave->sSelectCur = 0;
    
    pSysSave->cMesFlag = 0;
    
    pSysSave->pConfigFile = mcCreateConfigInit(&ConfigFile);
    pSysSave->pSaveFile = mcCreateSaveFileInit(&SaveFile);
    
    pSysSave->pMcState = CreateMemoryCard(&McState);
    
    pSysSave->pIconInfo = mcCreateIconInit(&IconInfo, cpNameList, 1);
    
    pSysSave->pSelectFileInfo = mcSelectFileInfoInit(SelectFileInfo);
    pSysSave->pSelectFileWindow = mcCreateFileSelectWindow(&SelectFileWindow, pSysSave->pSelectFileInfo, 15);
    
    pSysSave->vpReadBuffer = vpWorkPtrSys;
    
    CheckMemoryCardChangeConnectTypeAll(pSysSave->pMcState);
    
    return pSysSave;
}

// 99.56% matching
void DispSysSaveMessageSelect(SYSSAVE_SCREEN* pSysSave)
{
    bhFontScaleSet(0.75f, 0.75f, 0.75f);

    switch (pSysSave->cMesFlag)
    {
    case 0:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 0);
        break;
    case 1:
        AutoSaveLoadEasyDispMessage(-1.0f, 92.0f, SaveLoadMessage, 30);
        break;
    case 2:
        AutoSaveLoadEasyDispMessage(-1.0f, 84.0f, SaveLoadMessage, 31);
        break;
    case 3:
        AutoSaveLoadEasyDispMessage(-1.0f, 162.0f, SaveLoadMessage, 32);
        
        DispUpDownCursol(270.0f, 275.0f, pSysSave->sSelectCur + 2);
        break;
    case 4:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 33);
        break;
    case 5:
        AutoSaveLoadEasyDispMessage(-1.0f, 190.0f, SaveLoadMessage, 34);
        break;
    case 6:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 35);
        break;
    case 7:
        AutoSaveLoadEasyDispMessage(-1.0f, 162.0f, SaveLoadMessage, 36);
        
        DispUpDownCursol(270.0f, 320.0f, pSysSave->sSelectCur + 2);
        break;
    case 8:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 37);
        break;
    case 9:
        AutoSaveLoadEasyDispMessage(-1.0f, 204.0f, SaveLoadMessage, 38);
        break;
    case 10:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 39);
        break;
    case 11:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 40);
        break;
    case 12:
        AutoSaveLoadEasyDispMessage(-1.0f, 204.0f, SaveLoadMessage, 41);
        break;
    case 13:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 42);
        break;
    case 14:
        AutoSaveLoadEasyDispMessage(-1.0f, 136.0f, SaveLoadMessage, 43);
        break;
    case 15:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 44);
        
        DispUpDownCursol(270.0f, 221.0f, pSysSave->sSelectCur + 2);
        break;
    }

    bhFontScaleSet(1.0f, 1.0f, 1.0f);
}

// 100% matching!
int ExecuteSysSaveScreen(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->lCardState = ExecuteMemoryCard(pSysSave->pMcState);
    
    switch (pSysSave->ulState)
    {                          
    case 0:
        ExecuteStateSysSaveAwarenessCard(pSysSave);
        break;
    case 1:
        ExecuteStateSysSaveErrUnPS2MemCard(pSysSave);
        break;
    case 2:
        ExecuteStateSysSaveErrLostCard(pSysSave);
        break;
    case 3:
        ExecuteStateSysSaveErrPort2(pSysSave);
        break;
    case 10:
        ExecuteStateSysSaveDirCheck(pSysSave);
        break;
    case 11:
        ExecuteStateSysSaveFreeCapacity(pSysSave);
        break;
    case 12:
        ExecuteStateSysSaveErrFreeCapacity(pSysSave);
        break;
    case 13:
        ExecuteStateSysSaveCheckWriteSysData(pSysSave);
        break;
    case 14:
        ExecuteStateSysSaveWriteSysData(pSysSave);
        break;
    case 15:
        ExecuteStateSysSaveSuccessWriteSysData(pSysSave);
        break;
    case 16:
        ExecuteStateSysSaveErrWriteSysData(pSysSave);
        break;
    case 17:
        ExecuteStateSysSaveFileBroken(pSysSave);
        break;
    case 18:
        ExecuteStateSysSaveExitWriteSysData(pSysSave);
        break;
    case 20:
        ExecuteStateWriteRankingData(pSysSave);
        break;
    case 30:
        ExecuteStateSysSave(pSysSave);
        break;
    case 31:
        ExecuteStateSysSaveErrCardWrite(pSysSave);
        break;
    case 40:
        ExecuteStateSysSaveFormat(pSysSave);
        break;
    case 41:
        ExecuteStateSysSaveStartFormat(pSysSave);
        break;
    case 42:
        ExecuteStateSysSaveExitFormat(pSysSave);
        break;
    case 43:
        ExecuteStateSysSaveSuccessFormat(pSysSave);
        break;
    case 44:
        ExecuteStateSysSaveErrFormat(pSysSave);
        break;
    case 50:
        ExecuteStateSysSaveTitleExit();
        break;
    }
    
    DispSysSaveMessageSelect(pSysSave);
    
    return pSysSave->usExitFlag;
}

// 100% matching!
void SetStateSysSaveAwarenessCard(SYSSAVE_SCREEN* pSysSave)
{   
    pSysSave->ulState = 0;
    
    SetMemoryCardCurrentPort(pSysSave->pMcState, 0);
    
    RecoveryMemoryCardError((MEMORYCARDSTATE*)pSysSave);
}

// 100% matching!
void ExecuteStateSysSaveAwarenessCard(SYSSAVE_SCREEN* pSysSave)
{
    int lPort0State;
    int lPort1State;
    int lResult;
	
    switch (pSysSave->lCardState)
    {
    case 100:
    case 101:
        lPort0State = GetMemoryCardSelectPortState(pSysSave->pMcState, 0);
        lPort1State = GetMemoryCardSelectPortState(pSysSave->pMcState, 1);
        
        if (lPort0State == 2)
        {
            lResult = CheckMemoryCardFormatStatus(pSysSave->pMcState);
            
            if (lResult == 1)
            {
                SetStateSysSaveFormat(pSysSave);
            }
            else if (lResult == 2)
            {
                SetStateSysSaveDirCheck(pSysSave);
            }
        }
        else 
        {
            if (lPort1State == 2)
            {
                SetStateSysSaveErrPort2(pSysSave);
            }
            else if (((lPort0State != 2) && (lPort0State != 0)) || ((lPort1State != 2) && (lPort1State != 0))) 
            {
                SetStateSysSaveErrUnPS2MemCard(pSysSave);
            }
            else 
            {
                SetStateSysSaveErrLostCard(pSysSave);
            }
        }
        
        break;
    case 102:
        SetStateSysSaveErrUnPS2MemCard(pSysSave);
        break;
    case 103:
        SetStateSysSaveErrLostCard(pSysSave);
        break;
    }
}

// 100% matching!
void SetStateSysSaveErrUnPS2MemCard(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 1;
    
    pSysSave->cMesFlag = 1;
}

// 
// Start address: 0x278810
void ExecuteStateSysSaveErrUnPS2MemCard(SYSSAVE_SCREEN* pSysSave)
{
	int lPort1State;
	int lPort0State;
	// Line 518, Address: 0x278810, Func Offset: 0
	// Line 523, Address: 0x278820, Func Offset: 0x10
	// Line 525, Address: 0x278834, Func Offset: 0x24
	// Line 527, Address: 0x278838, Func Offset: 0x28
	// Line 528, Address: 0x278840, Func Offset: 0x30
	// Line 532, Address: 0x278848, Func Offset: 0x38
	// Line 537, Address: 0x278878, Func Offset: 0x68
	// Line 539, Address: 0x278884, Func Offset: 0x74
	// Line 541, Address: 0x278894, Func Offset: 0x84
	// Line 544, Address: 0x2788a0, Func Offset: 0x90
	// Line 545, Address: 0x2788a8, Func Offset: 0x98
	// Line 547, Address: 0x2788b0, Func Offset: 0xa0
	// Line 550, Address: 0x2788b8, Func Offset: 0xa8
	// Line 551, Address: 0x2788c0, Func Offset: 0xb0
	// Line 553, Address: 0x2788c8, Func Offset: 0xb8
	// Line 556, Address: 0x2788d8, Func Offset: 0xc8
	// Line 558, Address: 0x2788e0, Func Offset: 0xd0
	// Line 562, Address: 0x2788e8, Func Offset: 0xd8
	// Line 566, Address: 0x2788f0, Func Offset: 0xe0
	// Func End, Address: 0x278904, Func Offset: 0xf4
}

// 
// Start address: 0x278910
void SetStateSysSaveErrLostCard(SYSSAVE_SCREEN* pSysSave)
{
	// Line 583, Address: 0x278910, Func Offset: 0
	// Line 585, Address: 0x278918, Func Offset: 0x8
	// Line 586, Address: 0x27891c, Func Offset: 0xc
	// Func End, Address: 0x278924, Func Offset: 0x14
}

// 
// Start address: 0x278930
void ExecuteStateSysSaveErrLostCard(SYSSAVE_SCREEN* pSysSave)
{
	int lPort1State;
	int lPort0State;
	// Line 601, Address: 0x278930, Func Offset: 0
	// Line 605, Address: 0x278940, Func Offset: 0x10
	// Line 607, Address: 0x278954, Func Offset: 0x24
	// Line 609, Address: 0x278958, Func Offset: 0x28
	// Line 610, Address: 0x278960, Func Offset: 0x30
	// Line 614, Address: 0x278968, Func Offset: 0x38
	// Line 619, Address: 0x278998, Func Offset: 0x68
	// Line 621, Address: 0x2789a4, Func Offset: 0x74
	// Line 623, Address: 0x2789b4, Func Offset: 0x84
	// Line 626, Address: 0x2789c0, Func Offset: 0x90
	// Line 627, Address: 0x2789c8, Func Offset: 0x98
	// Line 629, Address: 0x2789d0, Func Offset: 0xa0
	// Line 632, Address: 0x2789d8, Func Offset: 0xa8
	// Line 633, Address: 0x2789e0, Func Offset: 0xb0
	// Line 635, Address: 0x2789e8, Func Offset: 0xb8
	// Line 639, Address: 0x278a0c, Func Offset: 0xdc
	// Line 641, Address: 0x278a18, Func Offset: 0xe8
	// Line 645, Address: 0x278a20, Func Offset: 0xf0
	// Line 658, Address: 0x278a28, Func Offset: 0xf8
	// Func End, Address: 0x278a3c, Func Offset: 0x10c
}

// 
// Start address: 0x278a40
void SetStateSysSaveErrPort2(SYSSAVE_SCREEN* pSysSave)
{
	// Line 675, Address: 0x278a40, Func Offset: 0
	// Line 677, Address: 0x278a48, Func Offset: 0x8
	// Line 678, Address: 0x278a4c, Func Offset: 0xc
	// Func End, Address: 0x278a54, Func Offset: 0x14
}

// 
// Start address: 0x278a60
void ExecuteStateSysSaveErrPort2(SYSSAVE_SCREEN* pSysSave)
{
	// Line 692, Address: 0x278a60, Func Offset: 0
	// Line 694, Address: 0x278a68, Func Offset: 0x8
	// Line 697, Address: 0x278a7c, Func Offset: 0x1c
	// Line 699, Address: 0x278a80, Func Offset: 0x20
	// Line 700, Address: 0x278a88, Func Offset: 0x28
	// Line 704, Address: 0x278a90, Func Offset: 0x30
	// Line 707, Address: 0x278aac, Func Offset: 0x4c
	// Line 710, Address: 0x278ab4, Func Offset: 0x54
	// Func End, Address: 0x278ac0, Func Offset: 0x60
}

// 
// Start address: 0x278ac0
void SetStateSysSaveDirCheck(SYSSAVE_SCREEN* pSysSave)
{
	// Line 726, Address: 0x278ac0, Func Offset: 0
	// Line 728, Address: 0x278acc, Func Offset: 0xc
	// Line 730, Address: 0x278ad8, Func Offset: 0x18
	// Line 732, Address: 0x278adc, Func Offset: 0x1c
	// Line 734, Address: 0x278ae8, Func Offset: 0x28
	// Line 735, Address: 0x278af4, Func Offset: 0x34
	// Func End, Address: 0x278b04, Func Offset: 0x44
}

// 
// Start address: 0x278b10
void ExecuteStateSysSaveDirCheck(SYSSAVE_SCREEN* pSysSave)
{
	int lResult;
	// Line 750, Address: 0x278b10, Func Offset: 0
	// Line 753, Address: 0x278b1c, Func Offset: 0xc
	// Line 757, Address: 0x278b54, Func Offset: 0x44
	// Line 758, Address: 0x278b5c, Func Offset: 0x4c
	// Line 762, Address: 0x278b68, Func Offset: 0x58
	// Line 763, Address: 0x278b70, Func Offset: 0x60
	// Line 766, Address: 0x278b78, Func Offset: 0x68
	// Line 768, Address: 0x278b84, Func Offset: 0x74
	// Line 770, Address: 0x278b8c, Func Offset: 0x7c
	// Line 772, Address: 0x278b90, Func Offset: 0x80
	// Line 776, Address: 0x278b98, Func Offset: 0x88
	// Line 777, Address: 0x278bac, Func Offset: 0x9c
	// Line 779, Address: 0x278bb4, Func Offset: 0xa4
	// Line 781, Address: 0x278bbc, Func Offset: 0xac
	// Line 783, Address: 0x278bc8, Func Offset: 0xb8
	// Line 784, Address: 0x278bd0, Func Offset: 0xc0
	// Line 785, Address: 0x278bd8, Func Offset: 0xc8
	// Line 788, Address: 0x278be4, Func Offset: 0xd4
	// Line 791, Address: 0x278bf0, Func Offset: 0xe0
	// Line 792, Address: 0x278bf8, Func Offset: 0xe8
	// Line 797, Address: 0x278c00, Func Offset: 0xf0
	// Line 800, Address: 0x278c0c, Func Offset: 0xfc
	// Line 803, Address: 0x278c14, Func Offset: 0x104
	// Line 806, Address: 0x278c24, Func Offset: 0x114
	// Line 808, Address: 0x278c2c, Func Offset: 0x11c
	// Line 813, Address: 0x278c34, Func Offset: 0x124
	// Line 815, Address: 0x278c44, Func Offset: 0x134
	// Line 820, Address: 0x278c4c, Func Offset: 0x13c
	// Line 823, Address: 0x278c68, Func Offset: 0x158
	// Line 825, Address: 0x278c70, Func Offset: 0x160
	// Func End, Address: 0x278c80, Func Offset: 0x170
}

// 
// Start address: 0x278c80
void SetStateSysSaveFreeCapacity(SYSSAVE_SCREEN* pSysSave)
{
	// Line 842, Address: 0x278c80, Func Offset: 0
	// Line 843, Address: 0x278c84, Func Offset: 0x4
	// Func End, Address: 0x278c8c, Func Offset: 0xc
}

// 
// Start address: 0x278c90
void ExecuteStateSysSaveFreeCapacity(SYSSAVE_SCREEN* pSysSave)
{
	int lResult;
	// Line 858, Address: 0x278c90, Func Offset: 0
	// Line 861, Address: 0x278ca4, Func Offset: 0x14
	// Line 863, Address: 0x278cac, Func Offset: 0x1c
	// Line 866, Address: 0x278cc0, Func Offset: 0x30
	// Line 869, Address: 0x278ccc, Func Offset: 0x3c
	// Line 872, Address: 0x278cd4, Func Offset: 0x44
	// Line 879, Address: 0x278ce0, Func Offset: 0x50
	// Line 881, Address: 0x278ce8, Func Offset: 0x58
	// Line 886, Address: 0x278cf0, Func Offset: 0x60
	// Line 888, Address: 0x278cfc, Func Offset: 0x6c
	// Func End, Address: 0x278d10, Func Offset: 0x80
}

// 
// Start address: 0x278d10
void SetStateSysSaveErrFreeCapacity(SYSSAVE_SCREEN* pSysSave)
{
	// Line 905, Address: 0x278d10, Func Offset: 0
	// Line 907, Address: 0x278d18, Func Offset: 0x8
	// Line 908, Address: 0x278d1c, Func Offset: 0xc
	// Func End, Address: 0x278d24, Func Offset: 0x14
}

// 
// Start address: 0x278d30
void ExecuteStateSysSaveErrFreeCapacity(SYSSAVE_SCREEN* pSysSave)
{
	// Line 922, Address: 0x278d30, Func Offset: 0
	// Line 924, Address: 0x278d38, Func Offset: 0x8
	// Line 927, Address: 0x278d4c, Func Offset: 0x1c
	// Line 929, Address: 0x278d50, Func Offset: 0x20
	// Line 930, Address: 0x278d58, Func Offset: 0x28
	// Line 934, Address: 0x278d60, Func Offset: 0x30
	// Line 937, Address: 0x278d7c, Func Offset: 0x4c
	// Line 940, Address: 0x278d84, Func Offset: 0x54
	// Func End, Address: 0x278d90, Func Offset: 0x60
}

// 
// Start address: 0x278d90
void SetStateSysSaveCheckWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 957, Address: 0x278d90, Func Offset: 0
	// Line 959, Address: 0x278d98, Func Offset: 0x8
	// Line 961, Address: 0x278da0, Func Offset: 0x10
	// Line 962, Address: 0x278da4, Func Offset: 0x14
	// Func End, Address: 0x278dac, Func Offset: 0x1c
}

// 
// Start address: 0x278db0
void ExecuteStateSysSaveCheckWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 977, Address: 0x278db0, Func Offset: 0
	// Line 981, Address: 0x278dbc, Func Offset: 0xc
	// Line 984, Address: 0x278dd0, Func Offset: 0x20
	// Line 988, Address: 0x278dd4, Func Offset: 0x24
	// Line 984, Address: 0x278ddc, Func Offset: 0x2c
	// Line 986, Address: 0x278de4, Func Offset: 0x34
	// Line 988, Address: 0x278dec, Func Offset: 0x3c
	// Line 989, Address: 0x278df4, Func Offset: 0x44
	// Line 990, Address: 0x278dfc, Func Offset: 0x4c
	// Line 993, Address: 0x278e08, Func Offset: 0x58
	// Line 997, Address: 0x278e0c, Func Offset: 0x5c
	// Line 993, Address: 0x278e14, Func Offset: 0x64
	// Line 995, Address: 0x278e1c, Func Offset: 0x6c
	// Line 997, Address: 0x278e24, Func Offset: 0x74
	// Line 998, Address: 0x278e2c, Func Offset: 0x7c
	// Line 999, Address: 0x278e34, Func Offset: 0x84
	// Line 1001, Address: 0x278e50, Func Offset: 0xa0
	// Line 1004, Address: 0x278e5c, Func Offset: 0xac
	// Line 1005, Address: 0x278e64, Func Offset: 0xb4
	// Line 1009, Address: 0x278e6c, Func Offset: 0xbc
	// Line 1012, Address: 0x278e78, Func Offset: 0xc8
	// Line 1013, Address: 0x278e84, Func Offset: 0xd4
	// Line 1014, Address: 0x278e8c, Func Offset: 0xdc
	// Line 1017, Address: 0x278ea8, Func Offset: 0xf8
	// Line 1019, Address: 0x278eb0, Func Offset: 0x100
	// Line 1020, Address: 0x278ebc, Func Offset: 0x10c
	// Line 1024, Address: 0x278ec4, Func Offset: 0x114
	// Line 1027, Address: 0x278ee0, Func Offset: 0x130
	// Line 1030, Address: 0x278ee8, Func Offset: 0x138
	// Func End, Address: 0x278ef8, Func Offset: 0x148
}

// 
// Start address: 0x278f00
void SetStateSysSaveWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1047, Address: 0x278f00, Func Offset: 0
	// Line 1049, Address: 0x278f08, Func Offset: 0x8
	// Line 1053, Address: 0x278f0c, Func Offset: 0xc
	// Line 1051, Address: 0x278f10, Func Offset: 0x10
	// Line 1055, Address: 0x278f14, Func Offset: 0x14
	// Line 1053, Address: 0x278f18, Func Offset: 0x18
	// Line 1055, Address: 0x278f1c, Func Offset: 0x1c
	// Line 1057, Address: 0x278f20, Func Offset: 0x20
	// Func End, Address: 0x278f28, Func Offset: 0x28
}

// 
// Start address: 0x278f30
void ExecuteStateSysSaveWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	int lResult;
	// Line 1073, Address: 0x278f30, Func Offset: 0
	// Line 1077, Address: 0x278f3c, Func Offset: 0xc
	// Line 1080, Address: 0x278f68, Func Offset: 0x38
	// Line 1082, Address: 0x278f70, Func Offset: 0x40
	// Line 1085, Address: 0x278f7c, Func Offset: 0x4c
	// Line 1087, Address: 0x278f88, Func Offset: 0x58
	// Line 1089, Address: 0x278f90, Func Offset: 0x60
	// Line 1090, Address: 0x278f94, Func Offset: 0x64
	// Line 1092, Address: 0x278f9c, Func Offset: 0x6c
	// Line 1095, Address: 0x278fa8, Func Offset: 0x78
	// Line 1100, Address: 0x278fcc, Func Offset: 0x9c
	// Line 1104, Address: 0x278fd4, Func Offset: 0xa4
	// Line 1106, Address: 0x278fdc, Func Offset: 0xac
	// Line 1108, Address: 0x278fe8, Func Offset: 0xb8
	// Line 1109, Address: 0x278fec, Func Offset: 0xbc
	// Line 1111, Address: 0x278ff4, Func Offset: 0xc4
	// Line 1114, Address: 0x279000, Func Offset: 0xd0
	// Line 1116, Address: 0x27900c, Func Offset: 0xdc
	// Line 1118, Address: 0x279014, Func Offset: 0xe4
	// Line 1120, Address: 0x279018, Func Offset: 0xe8
	// Line 1124, Address: 0x279020, Func Offset: 0xf0
	// Line 1126, Address: 0x279038, Func Offset: 0x108
	// Line 1129, Address: 0x279044, Func Offset: 0x114
	// Line 1131, Address: 0x279050, Func Offset: 0x120
	// Line 1133, Address: 0x279058, Func Offset: 0x128
	// Line 1134, Address: 0x27905c, Func Offset: 0x12c
	// Line 1139, Address: 0x279064, Func Offset: 0x134
	// Line 1141, Address: 0x279088, Func Offset: 0x158
	// Line 1145, Address: 0x27908c, Func Offset: 0x15c
	// Line 1149, Address: 0x279094, Func Offset: 0x164
	// Line 1151, Address: 0x27909c, Func Offset: 0x16c
	// Line 1154, Address: 0x2790a8, Func Offset: 0x178
	// Line 1156, Address: 0x2790b4, Func Offset: 0x184
	// Line 1158, Address: 0x2790bc, Func Offset: 0x18c
	// Line 1159, Address: 0x2790c0, Func Offset: 0x190
	// Line 1161, Address: 0x2790c8, Func Offset: 0x198
	// Line 1164, Address: 0x2790d4, Func Offset: 0x1a4
	// Line 1166, Address: 0x2790ec, Func Offset: 0x1bc
	// Line 1169, Address: 0x2790f0, Func Offset: 0x1c0
	// Line 1173, Address: 0x2790f8, Func Offset: 0x1c8
	// Line 1175, Address: 0x279100, Func Offset: 0x1d0
	// Line 1177, Address: 0x27910c, Func Offset: 0x1dc
	// Line 1178, Address: 0x279110, Func Offset: 0x1e0
	// Line 1180, Address: 0x279118, Func Offset: 0x1e8
	// Line 1183, Address: 0x279124, Func Offset: 0x1f4
	// Line 1185, Address: 0x279130, Func Offset: 0x200
	// Line 1187, Address: 0x279138, Func Offset: 0x208
	// Line 1189, Address: 0x27913c, Func Offset: 0x20c
	// Line 1193, Address: 0x279144, Func Offset: 0x214
	// Line 1195, Address: 0x279164, Func Offset: 0x234
	// Line 1197, Address: 0x279168, Func Offset: 0x238
	// Line 1201, Address: 0x279170, Func Offset: 0x240
	// Line 1203, Address: 0x279178, Func Offset: 0x248
	// Line 1205, Address: 0x279184, Func Offset: 0x254
	// Line 1208, Address: 0x2791a0, Func Offset: 0x270
	// Line 1212, Address: 0x2791a8, Func Offset: 0x278
	// Line 1210, Address: 0x2791ac, Func Offset: 0x27c
	// Line 1212, Address: 0x2791b0, Func Offset: 0x280
	// Line 1214, Address: 0x2791b4, Func Offset: 0x284
	// Line 1215, Address: 0x2791c0, Func Offset: 0x290
	// Line 1219, Address: 0x2791c8, Func Offset: 0x298
	// Line 1221, Address: 0x2791cc, Func Offset: 0x29c
	// Line 1223, Address: 0x2791d4, Func Offset: 0x2a4
	// Line 1226, Address: 0x2791e0, Func Offset: 0x2b0
	// Line 1228, Address: 0x2791ec, Func Offset: 0x2bc
	// Line 1230, Address: 0x2791f4, Func Offset: 0x2c4
	// Line 1232, Address: 0x2791f8, Func Offset: 0x2c8
	// Line 1235, Address: 0x279200, Func Offset: 0x2d0
	// Line 1238, Address: 0x279210, Func Offset: 0x2e0
	// Line 1240, Address: 0x279218, Func Offset: 0x2e8
	// Line 1243, Address: 0x279220, Func Offset: 0x2f0
	// Line 1246, Address: 0x279230, Func Offset: 0x300
	// Line 1250, Address: 0x279238, Func Offset: 0x308
	// Func End, Address: 0x279248, Func Offset: 0x318
}

// 
// Start address: 0x279250
void SetStateSysSaveSuccessWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1267, Address: 0x279250, Func Offset: 0
	// Line 1269, Address: 0x279254, Func Offset: 0x4
	// Line 1267, Address: 0x279258, Func Offset: 0x8
	// Line 1269, Address: 0x27925c, Func Offset: 0xc
	// Line 1271, Address: 0x279260, Func Offset: 0x10
	// Line 1273, Address: 0x279264, Func Offset: 0x14
	// Func End, Address: 0x279270, Func Offset: 0x20
}

// 
// Start address: 0x279270
void ExecuteStateSysSaveSuccessWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1289, Address: 0x279270, Func Offset: 0
	// Line 1290, Address: 0x279278, Func Offset: 0x8
	// Line 1293, Address: 0x279288, Func Offset: 0x18
	// Line 1294, Address: 0x279290, Func Offset: 0x20
	// Line 1298, Address: 0x279298, Func Offset: 0x28
	// Line 1301, Address: 0x2792b4, Func Offset: 0x44
	// Line 1305, Address: 0x2792bc, Func Offset: 0x4c
	// Func End, Address: 0x2792c8, Func Offset: 0x58
}

// 
// Start address: 0x2792d0
void SetStateSysSaveErrWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1322, Address: 0x2792d0, Func Offset: 0
	// Line 1324, Address: 0x2792d8, Func Offset: 0x8
	// Line 1325, Address: 0x2792dc, Func Offset: 0xc
	// Func End, Address: 0x2792e4, Func Offset: 0x14
}

// 
// Start address: 0x2792f0
void ExecuteStateSysSaveErrWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1339, Address: 0x2792f0, Func Offset: 0
	// Line 1341, Address: 0x2792f8, Func Offset: 0x8
	// Line 1344, Address: 0x27930c, Func Offset: 0x1c
	// Line 1346, Address: 0x279310, Func Offset: 0x20
	// Line 1347, Address: 0x279318, Func Offset: 0x28
	// Line 1351, Address: 0x279320, Func Offset: 0x30
	// Line 1354, Address: 0x27933c, Func Offset: 0x4c
	// Line 1357, Address: 0x279344, Func Offset: 0x54
	// Func End, Address: 0x279350, Func Offset: 0x60
}

// 
// Start address: 0x279350
void SetStateSysSaveFileBroken(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1374, Address: 0x279350, Func Offset: 0
	// Line 1376, Address: 0x279358, Func Offset: 0x8
	// Line 1377, Address: 0x27935c, Func Offset: 0xc
	// Func End, Address: 0x279364, Func Offset: 0x14
}

// 
// Start address: 0x279370
void ExecuteStateSysSaveFileBroken(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1391, Address: 0x279370, Func Offset: 0
	// Line 1393, Address: 0x279378, Func Offset: 0x8
	// Line 1395, Address: 0x27938c, Func Offset: 0x1c
	// Line 1397, Address: 0x279390, Func Offset: 0x20
	// Line 1398, Address: 0x279398, Func Offset: 0x28
	// Line 1402, Address: 0x2793a0, Func Offset: 0x30
	// Line 1405, Address: 0x2793bc, Func Offset: 0x4c
	// Line 1408, Address: 0x2793c4, Func Offset: 0x54
	// Func End, Address: 0x2793d0, Func Offset: 0x60
}

// 
// Start address: 0x2793d0
void SetStateSysSaveExitWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1426, Address: 0x2793d0, Func Offset: 0
	// Line 1428, Address: 0x2793d8, Func Offset: 0x8
	// Line 1430, Address: 0x2793e0, Func Offset: 0x10
	// Line 1431, Address: 0x2793e4, Func Offset: 0x14
	// Func End, Address: 0x2793ec, Func Offset: 0x1c
}

// 
// Start address: 0x2793f0
void ExecuteStateSysSaveExitWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1446, Address: 0x2793f0, Func Offset: 0
	// Line 1448, Address: 0x2793fc, Func Offset: 0xc
	// Line 1451, Address: 0x279410, Func Offset: 0x20
	// Line 1455, Address: 0x279414, Func Offset: 0x24
	// Line 1451, Address: 0x27941c, Func Offset: 0x2c
	// Line 1453, Address: 0x279424, Func Offset: 0x34
	// Line 1455, Address: 0x27942c, Func Offset: 0x3c
	// Line 1456, Address: 0x279434, Func Offset: 0x44
	// Line 1457, Address: 0x27943c, Func Offset: 0x4c
	// Line 1460, Address: 0x279448, Func Offset: 0x58
	// Line 1464, Address: 0x27944c, Func Offset: 0x5c
	// Line 1460, Address: 0x279454, Func Offset: 0x64
	// Line 1462, Address: 0x27945c, Func Offset: 0x6c
	// Line 1464, Address: 0x279464, Func Offset: 0x74
	// Line 1465, Address: 0x27946c, Func Offset: 0x7c
	// Line 1466, Address: 0x279474, Func Offset: 0x84
	// Line 1468, Address: 0x279490, Func Offset: 0xa0
	// Line 1471, Address: 0x2794a0, Func Offset: 0xb0
	// Line 1472, Address: 0x2794a8, Func Offset: 0xb8
	// Line 1476, Address: 0x2794b0, Func Offset: 0xc0
	// Line 1478, Address: 0x2794b4, Func Offset: 0xc4
	// Line 1481, Address: 0x2794bc, Func Offset: 0xcc
	// Line 1482, Address: 0x2794c8, Func Offset: 0xd8
	// Line 1483, Address: 0x2794d0, Func Offset: 0xe0
	// Line 1486, Address: 0x2794ec, Func Offset: 0xfc
	// Line 1488, Address: 0x2794f4, Func Offset: 0x104
	// Line 1489, Address: 0x279500, Func Offset: 0x110
	// Line 1493, Address: 0x279508, Func Offset: 0x118
	// Line 1496, Address: 0x279524, Func Offset: 0x134
	// Line 1499, Address: 0x27952c, Func Offset: 0x13c
	// Func End, Address: 0x27953c, Func Offset: 0x14c
}

// 
// Start address: 0x279540
void SetStateWriteRankingData(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1515, Address: 0x279540, Func Offset: 0
	// Line 1517, Address: 0x27954c, Func Offset: 0xc
	// Line 1519, Address: 0x279558, Func Offset: 0x18
	// Line 1521, Address: 0x27955c, Func Offset: 0x1c
	// Line 1523, Address: 0x279568, Func Offset: 0x28
	// Line 1524, Address: 0x279570, Func Offset: 0x30
	// Func End, Address: 0x279580, Func Offset: 0x40
}

// 
// Start address: 0x279580
void ExecuteStateWriteRankingData(SYSSAVE_SCREEN* pSysSave)
{
	int ulSaveResult;
	CONFIGFILE* pRankingData;
	CONFIGFILE RankingData;
	// Line 1539, Address: 0x279580, Func Offset: 0
	// Line 1545, Address: 0x279594, Func Offset: 0x14
	// Line 1550, Address: 0x2795c0, Func Offset: 0x40
	// Line 1554, Address: 0x2795d8, Func Offset: 0x58
	// Line 1558, Address: 0x2795e0, Func Offset: 0x60
	// Line 1560, Address: 0x2795f0, Func Offset: 0x70
	// Line 1563, Address: 0x2795f8, Func Offset: 0x78
	// Line 1568, Address: 0x279604, Func Offset: 0x84
	// Line 1574, Address: 0x27960c, Func Offset: 0x8c
	// Line 1568, Address: 0x279610, Func Offset: 0x90
	// Line 1574, Address: 0x279614, Func Offset: 0x94
	// Line 1576, Address: 0x279620, Func Offset: 0xa0
	// Line 1577, Address: 0x279628, Func Offset: 0xa8
	// Line 1586, Address: 0x279630, Func Offset: 0xb0
	// Line 1589, Address: 0x279644, Func Offset: 0xc4
	// Line 1590, Address: 0x279650, Func Offset: 0xd0
	// Line 1592, Address: 0x279658, Func Offset: 0xd8
	// Line 1595, Address: 0x279660, Func Offset: 0xe0
	// Line 1597, Address: 0x27966c, Func Offset: 0xec
	// Line 1599, Address: 0x279674, Func Offset: 0xf4
	// Line 1601, Address: 0x279678, Func Offset: 0xf8
	// Line 1604, Address: 0x279680, Func Offset: 0x100
	// Line 1607, Address: 0x279690, Func Offset: 0x110
	// Line 1612, Address: 0x279698, Func Offset: 0x118
	// Func End, Address: 0x2796b0, Func Offset: 0x130
}

// 
// Start address: 0x2796b0
void SetStateSysSave(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1630, Address: 0x2796b0, Func Offset: 0
	// Line 1634, Address: 0x2796b8, Func Offset: 0x8
	// Line 1632, Address: 0x2796bc, Func Offset: 0xc
	// Line 1634, Address: 0x2796c0, Func Offset: 0x10
	// Line 1636, Address: 0x2796c4, Func Offset: 0x14
	// Func End, Address: 0x2796d0, Func Offset: 0x20
}

// 
// Start address: 0x2796d0
void ExecuteStateSysSave(SYSSAVE_SCREEN* pSysSave)
{
	int ulSaveResult;
	// Line 1652, Address: 0x2796d0, Func Offset: 0
	// Line 1655, Address: 0x2796dc, Func Offset: 0xc
	// Line 1658, Address: 0x279708, Func Offset: 0x38
	// Line 1662, Address: 0x279720, Func Offset: 0x50
	// Line 1665, Address: 0x279728, Func Offset: 0x58
	// Line 1666, Address: 0x279730, Func Offset: 0x60
	// Line 1669, Address: 0x27973c, Func Offset: 0x6c
	// Line 1671, Address: 0x279748, Func Offset: 0x78
	// Line 1673, Address: 0x279750, Func Offset: 0x80
	// Line 1674, Address: 0x279758, Func Offset: 0x88
	// Line 1675, Address: 0x279760, Func Offset: 0x90
	// Line 1678, Address: 0x279768, Func Offset: 0x98
	// Line 1680, Address: 0x279774, Func Offset: 0xa4
	// Line 1682, Address: 0x27977c, Func Offset: 0xac
	// Line 1684, Address: 0x279780, Func Offset: 0xb0
	// Line 1687, Address: 0x279788, Func Offset: 0xb8
	// Line 1689, Address: 0x279798, Func Offset: 0xc8
	// Line 1694, Address: 0x2797a0, Func Offset: 0xd0
	// Func End, Address: 0x2797b0, Func Offset: 0xe0
}

// 
// Start address: 0x2797b0
void SetStateSysSaveErrCardWrite(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1711, Address: 0x2797b0, Func Offset: 0
	// Line 1713, Address: 0x2797b8, Func Offset: 0x8
	// Line 1715, Address: 0x2797c0, Func Offset: 0x10
	// Func End, Address: 0x2797cc, Func Offset: 0x1c
}

// 
// Start address: 0x2797d0
void ExecuteStateSysSaveErrCardWrite(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1730, Address: 0x2797d0, Func Offset: 0
	// Line 1732, Address: 0x2797d8, Func Offset: 0x8
	// Line 1735, Address: 0x2797ec, Func Offset: 0x1c
	// Line 1737, Address: 0x2797f0, Func Offset: 0x20
	// Line 1738, Address: 0x2797f8, Func Offset: 0x28
	// Line 1742, Address: 0x279800, Func Offset: 0x30
	// Line 1745, Address: 0x27981c, Func Offset: 0x4c
	// Line 1748, Address: 0x279824, Func Offset: 0x54
	// Func End, Address: 0x279830, Func Offset: 0x60
}

// 
// Start address: 0x279830
void SetStateSysSaveFormat(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1766, Address: 0x279830, Func Offset: 0
	// Line 1768, Address: 0x279838, Func Offset: 0x8
	// Line 1770, Address: 0x279840, Func Offset: 0x10
	// Line 1771, Address: 0x279844, Func Offset: 0x14
	// Func End, Address: 0x27984c, Func Offset: 0x1c
}

// 
// Start address: 0x279850
void ExecuteStateSysSaveFormat(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1786, Address: 0x279850, Func Offset: 0
	// Line 1788, Address: 0x27985c, Func Offset: 0xc
	// Line 1791, Address: 0x279870, Func Offset: 0x20
	// Line 1795, Address: 0x279874, Func Offset: 0x24
	// Line 1791, Address: 0x27987c, Func Offset: 0x2c
	// Line 1793, Address: 0x279884, Func Offset: 0x34
	// Line 1795, Address: 0x27988c, Func Offset: 0x3c
	// Line 1796, Address: 0x279894, Func Offset: 0x44
	// Line 1797, Address: 0x27989c, Func Offset: 0x4c
	// Line 1800, Address: 0x2798a8, Func Offset: 0x58
	// Line 1804, Address: 0x2798ac, Func Offset: 0x5c
	// Line 1800, Address: 0x2798b4, Func Offset: 0x64
	// Line 1802, Address: 0x2798bc, Func Offset: 0x6c
	// Line 1804, Address: 0x2798c4, Func Offset: 0x74
	// Line 1805, Address: 0x2798cc, Func Offset: 0x7c
	// Line 1807, Address: 0x2798d4, Func Offset: 0x84
	// Line 1810, Address: 0x2798f0, Func Offset: 0xa0
	// Line 1813, Address: 0x279900, Func Offset: 0xb0
	// Line 1814, Address: 0x279908, Func Offset: 0xb8
	// Line 1819, Address: 0x279910, Func Offset: 0xc0
	// Line 1822, Address: 0x27991c, Func Offset: 0xcc
	// Line 1823, Address: 0x279928, Func Offset: 0xd8
	// Line 1825, Address: 0x279930, Func Offset: 0xe0
	// Line 1828, Address: 0x27994c, Func Offset: 0xfc
	// Line 1830, Address: 0x279954, Func Offset: 0x104
	// Line 1831, Address: 0x279960, Func Offset: 0x110
	// Line 1835, Address: 0x279968, Func Offset: 0x118
	// Line 1838, Address: 0x279984, Func Offset: 0x134
	// Line 1841, Address: 0x27998c, Func Offset: 0x13c
	// Func End, Address: 0x27999c, Func Offset: 0x14c
}

// 
// Start address: 0x2799a0
void SetStateSysSaveStartFormat(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1858, Address: 0x2799a0, Func Offset: 0
	// Line 1862, Address: 0x2799a8, Func Offset: 0x8
	// Line 1860, Address: 0x2799ac, Func Offset: 0xc
	// Line 1862, Address: 0x2799b0, Func Offset: 0x10
	// Line 1864, Address: 0x2799b4, Func Offset: 0x14
	// Func End, Address: 0x2799c0, Func Offset: 0x20
}

// 
// Start address: 0x2799c0
void ExecuteStateSysSaveStartFormat(SYSSAVE_SCREEN* pSysSave)
{
	int lFormatResult;
	// Line 1880, Address: 0x2799c0, Func Offset: 0
	// Line 1883, Address: 0x2799cc, Func Offset: 0xc
	// Line 1887, Address: 0x279a04, Func Offset: 0x44
	// Line 1891, Address: 0x279a18, Func Offset: 0x58
	// Line 1894, Address: 0x279a20, Func Offset: 0x60
	// Line 1896, Address: 0x279a28, Func Offset: 0x68
	// Line 1899, Address: 0x279a34, Func Offset: 0x74
	// Line 1901, Address: 0x279a40, Func Offset: 0x80
	// Line 1902, Address: 0x279a44, Func Offset: 0x84
	// Line 1904, Address: 0x279a4c, Func Offset: 0x8c
	// Line 1907, Address: 0x279a58, Func Offset: 0x98
	// Line 1909, Address: 0x279a64, Func Offset: 0xa4
	// Line 1911, Address: 0x279a6c, Func Offset: 0xac
	// Line 1913, Address: 0x279a70, Func Offset: 0xb0
	// Line 1917, Address: 0x279a78, Func Offset: 0xb8
	// Line 1920, Address: 0x279a88, Func Offset: 0xc8
	// Line 1922, Address: 0x279a90, Func Offset: 0xd0
	// Line 1925, Address: 0x279a98, Func Offset: 0xd8
	// Line 1928, Address: 0x279aa8, Func Offset: 0xe8
	// Line 1932, Address: 0x279ab0, Func Offset: 0xf0
	// Func End, Address: 0x279ac0, Func Offset: 0x100
}

// 
// Start address: 0x279ac0
void SetStateSysSaveExitFormat(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1949, Address: 0x279ac0, Func Offset: 0
	// Line 1951, Address: 0x279ac8, Func Offset: 0x8
	// Line 1953, Address: 0x279ad0, Func Offset: 0x10
	// Line 1954, Address: 0x279ad4, Func Offset: 0x14
	// Func End, Address: 0x279adc, Func Offset: 0x1c
}

// 
// Start address: 0x279ae0
void ExecuteStateSysSaveExitFormat(SYSSAVE_SCREEN* pSysSave)
{
	// Line 1969, Address: 0x279ae0, Func Offset: 0
	// Line 1971, Address: 0x279aec, Func Offset: 0xc
	// Line 1974, Address: 0x279b00, Func Offset: 0x20
	// Line 1978, Address: 0x279b04, Func Offset: 0x24
	// Line 1974, Address: 0x279b0c, Func Offset: 0x2c
	// Line 1976, Address: 0x279b14, Func Offset: 0x34
	// Line 1978, Address: 0x279b1c, Func Offset: 0x3c
	// Line 1979, Address: 0x279b24, Func Offset: 0x44
	// Line 1980, Address: 0x279b2c, Func Offset: 0x4c
	// Line 1983, Address: 0x279b38, Func Offset: 0x58
	// Line 1987, Address: 0x279b3c, Func Offset: 0x5c
	// Line 1983, Address: 0x279b44, Func Offset: 0x64
	// Line 1985, Address: 0x279b4c, Func Offset: 0x6c
	// Line 1987, Address: 0x279b54, Func Offset: 0x74
	// Line 1988, Address: 0x279b5c, Func Offset: 0x7c
	// Line 1989, Address: 0x279b64, Func Offset: 0x84
	// Line 1991, Address: 0x279b80, Func Offset: 0xa0
	// Line 1994, Address: 0x279b90, Func Offset: 0xb0
	// Line 1995, Address: 0x279b98, Func Offset: 0xb8
	// Line 1999, Address: 0x279ba0, Func Offset: 0xc0
	// Line 2001, Address: 0x279ba4, Func Offset: 0xc4
	// Line 2004, Address: 0x279bac, Func Offset: 0xcc
	// Line 2005, Address: 0x279bb8, Func Offset: 0xd8
	// Line 2006, Address: 0x279bc0, Func Offset: 0xe0
	// Line 2009, Address: 0x279bdc, Func Offset: 0xfc
	// Line 2011, Address: 0x279be4, Func Offset: 0x104
	// Line 2012, Address: 0x279bf0, Func Offset: 0x110
	// Line 2016, Address: 0x279bf8, Func Offset: 0x118
	// Line 2019, Address: 0x279c14, Func Offset: 0x134
	// Line 2022, Address: 0x279c1c, Func Offset: 0x13c
	// Func End, Address: 0x279c2c, Func Offset: 0x14c
}

// 
// Start address: 0x279c30
void SetStateSysSaveSuccessFormat(SYSSAVE_SCREEN* pSysSave)
{
	// Line 2039, Address: 0x279c30, Func Offset: 0
	// Line 2041, Address: 0x279c38, Func Offset: 0x8
	// Line 2043, Address: 0x279c40, Func Offset: 0x10
	// Line 2045, Address: 0x279c44, Func Offset: 0x14
	// Func End, Address: 0x279c4c, Func Offset: 0x1c
}

// 
// Start address: 0x279c50
void ExecuteStateSysSaveSuccessFormat(SYSSAVE_SCREEN* pSysSave)
{
	// Line 2060, Address: 0x279c50, Func Offset: 0
	// Line 2062, Address: 0x279c58, Func Offset: 0x8
	// Line 2065, Address: 0x279c64, Func Offset: 0x14
	// Line 2068, Address: 0x279c70, Func Offset: 0x20
	// Line 2069, Address: 0x279c78, Func Offset: 0x28
	// Line 2072, Address: 0x279c80, Func Offset: 0x30
	// Line 2075, Address: 0x279c9c, Func Offset: 0x4c
	// Line 2078, Address: 0x279ca4, Func Offset: 0x54
	// Func End, Address: 0x279cb0, Func Offset: 0x60
}

// 
// Start address: 0x279cb0
void SetStateSysSaveErrFormat(SYSSAVE_SCREEN* pSysSave)
{
	// Line 2095, Address: 0x279cb0, Func Offset: 0
	// Line 2097, Address: 0x279cb8, Func Offset: 0x8
	// Line 2100, Address: 0x279cc0, Func Offset: 0x10
	// Func End, Address: 0x279cc8, Func Offset: 0x18
}

// 
// Start address: 0x279cd0
void ExecuteStateSysSaveErrFormat(SYSSAVE_SCREEN* pSysSave)
{
	// Line 2115, Address: 0x279cd0, Func Offset: 0
	// Line 2116, Address: 0x279cd8, Func Offset: 0x8
	// Line 2119, Address: 0x279cec, Func Offset: 0x1c
	// Line 2120, Address: 0x279cf4, Func Offset: 0x24
	// Line 2124, Address: 0x279cfc, Func Offset: 0x2c
	// Line 2127, Address: 0x279d18, Func Offset: 0x48
	// Line 2130, Address: 0x279d20, Func Offset: 0x50
	// Func End, Address: 0x279d2c, Func Offset: 0x5c
}

// 
// Start address: 0x279d30
void SetStateSysSaveTitleExit(SYSSAVE_SCREEN* pSysSave)
{
	// Line 2147, Address: 0x279d30, Func Offset: 0
	// Line 2148, Address: 0x279d34, Func Offset: 0x4
	// Func End, Address: 0x279d3c, Func Offset: 0xc
}

// 
// Start address: 0x279d40
void ExecuteStateSysSaveTitleExit()
{
	// Line 2162, Address: 0x279d40, Func Offset: 0
	// Line 2164, Address: 0x279d4c, Func Offset: 0xc
	// Line 2166, Address: 0x279d64, Func Offset: 0x24
	// Line 2168, Address: 0x279d68, Func Offset: 0x28
	// Func End, Address: 0x279d70, Func Offset: 0x30
}

// 
// Start address: 0x279d70
void SysSaveHikaku(CONFIGFILE* pConfig)
{
	unsigned int Count;
	// Line 2186, Address: 0x279d70, Func Offset: 0
	// Line 2188, Address: 0x279d7c, Func Offset: 0xc
	// Line 2190, Address: 0x279d84, Func Offset: 0x14
	// Line 2188, Address: 0x279d8c, Func Offset: 0x1c
	// Line 2192, Address: 0x279d98, Func Offset: 0x28
	// Line 2194, Address: 0x279dc4, Func Offset: 0x54
	// Line 2196, Address: 0x279dc8, Func Offset: 0x58
	// Line 2194, Address: 0x279dcc, Func Offset: 0x5c
	// Line 2196, Address: 0x279dd0, Func Offset: 0x60
	// Line 2197, Address: 0x279ddc, Func Offset: 0x6c
	// Line 2200, Address: 0x279de4, Func Offset: 0x74
	// Line 2202, Address: 0x279dec, Func Offset: 0x7c
	// Line 2203, Address: 0x279df8, Func Offset: 0x88
	// Line 2202, Address: 0x279dfc, Func Offset: 0x8c
	// Line 2203, Address: 0x279e00, Func Offset: 0x90
	// Line 2202, Address: 0x279e04, Func Offset: 0x94
	// Line 2203, Address: 0x279e0c, Func Offset: 0x9c
	// Line 2204, Address: 0x279e14, Func Offset: 0xa4
	// Line 2205, Address: 0x279e18, Func Offset: 0xa8
	// Func End, Address: 0x279e20, Func Offset: 0xb0
}

// 
// Start address: 0x279e20
unsigned int GetOkButton()
{
	unsigned int ButtonDef[3];
	// Line 2219, Address: 0x279e20, Func Offset: 0
	// Line 2217, Address: 0x279e30, Func Offset: 0x10
	// Line 2219, Address: 0x279e34, Func Offset: 0x14
	// Line 2225, Address: 0x279e38, Func Offset: 0x18
	// Line 2219, Address: 0x279e3c, Func Offset: 0x1c
	// Line 2225, Address: 0x279e44, Func Offset: 0x24
	// Line 2226, Address: 0x279e58, Func Offset: 0x38
	// Func End, Address: 0x279e60, Func Offset: 0x40
}

// 
// Start address: 0x279e60
unsigned int GetCancelButton()
{
	unsigned int ButtonDef[3];
	// Line 2240, Address: 0x279e60, Func Offset: 0
	// Line 2238, Address: 0x279e70, Func Offset: 0x10
	// Line 2240, Address: 0x279e74, Func Offset: 0x14
	// Line 2246, Address: 0x279e78, Func Offset: 0x18
	// Line 2240, Address: 0x279e7c, Func Offset: 0x1c
	// Line 2246, Address: 0x279e84, Func Offset: 0x24
	// Line 2247, Address: 0x279e98, Func Offset: 0x38
	// Func End, Address: 0x279ea0, Func Offset: 0x40
}
