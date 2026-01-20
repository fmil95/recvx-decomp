#include "ps2_SystemSaveScreen.h"
#include "adv.h"
#include "message.h"
#include "padman.h"
#include "ps2_McSaveFile.h"
#include "ps2_MemoryCard..h"
#include "sdfunc.h"
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

// 100% matching!
void ExecuteStateSysSaveErrUnPS2MemCard(SYSSAVE_SCREEN* pSysSave)
{
	int lPort0State;
    int lPort1State;

    if ((Pad->press & 0x800))
    {
        pSysSave->usExitFlag = 1;
        
        SetStateSysSaveTitleExit(pSysSave);
        return;
    }
    
    switch (pSysSave->lCardState)
    {
    case 100:
    case 101:
        lPort0State = GetMemoryCardSelectPortState(pSysSave->pMcState, 0);
        lPort1State = GetMemoryCardSelectPortState(pSysSave->pMcState, 1);
        
        if (lPort0State == 2)
        {
            SetStateSysSaveAwarenessCard(pSysSave);
        }
        else if (lPort1State == 2)
        {
            SetStateSysSaveErrPort2(pSysSave);
        }
        else if ((lPort0State == 0) && (lPort1State == 0))
        {
            SetStateSysSaveErrLostCard(pSysSave);
        }
        
        break;
    case 103:
        SetStateSysSaveErrLostCard(pSysSave);
        break;
    }
}

// 100% matching!
void SetStateSysSaveErrLostCard(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 2;
    
    pSysSave->cMesFlag = 1;
}

// 100% matching!
void ExecuteStateSysSaveErrLostCard(SYSSAVE_SCREEN* pSysSave)
{
    int lPort0State;
    int lPort1State;

    if ((Pad->press & 0x800))
    {
        pSysSave->usExitFlag = 1;
        
        SetStateSysSaveTitleExit(pSysSave);
        return;
    }
    
    switch (pSysSave->lCardState)
    {
    case 100:
    case 101:
        lPort0State = GetMemoryCardSelectPortState(pSysSave->pMcState, 0);
        lPort1State = GetMemoryCardSelectPortState(pSysSave->pMcState, 1);
        
        if (lPort0State == 2)
        {
            SetStateSysSaveAwarenessCard(pSysSave);
        }
        else if (lPort1State == 2)
        {
            SetStateSysSaveErrPort2(pSysSave);
        }
        else if (((lPort0State != 2) && (lPort0State != 0)) || ((lPort1State != 2) && (lPort1State != 0))) 
        {
            SetStateSysSaveErrUnPS2MemCard(pSysSave);
        }
        
        break;
    case 102:
        SetStateSysSaveErrUnPS2MemCard(pSysSave);
        break;
    }
}

// 100% matching!
void SetStateSysSaveErrPort2(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 3;
    
    pSysSave->cMesFlag = 1;
}

// 100% matching!
void ExecuteStateSysSaveErrPort2(SYSSAVE_SCREEN* pSysSave)
{
    if ((Pad->press & 0x800))
    {
        pSysSave->usExitFlag = 1;
        
        SetStateSysSaveTitleExit(pSysSave);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveDirCheck(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 10;
    pSysSave->ulSubState = 0;
    
    SetMemoryCardCurrentPort(pSysSave->pMcState, 0);
    SetCheckMcFlag(pSysSave->pMcState, 1);
}

// 100% matching!
void ExecuteStateSysSaveDirCheck(SYSSAVE_SCREEN* pSysSave)
{
    int lResult;

    switch (pSysSave->ulSubState)
    {
    case 0:
        lResult = CheckMemoryCardExistSubDirectory(pSysSave->pMcState);
        
        if (lResult == 1)
        {
            pSysSave->ulSubState = 1;
        }
        else if (lResult < 0)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 2;
        }
        
        break;
    case 1:
        lResult = CheckMemoryCardExistFileList(pSysSave->pMcState, cpNameList, 18);
        
        if (lResult < 0)
        {
            pSysSave->ulSubState = 3;
            
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
        }
        else if (lResult == 1)
        {
            if (pSysSave->usSaveMode == 1)
            {
                SetStateWriteRankingData(pSysSave);
            }
            else
            {
                SetStateSysSave(pSysSave);
            }
        }
        
        break;
    case 2:
        lResult = pSysSave->lCardState;
        
        if (lResult == 100)
        {
            SetStateSysSaveFreeCapacity(pSysSave);
        }
        
        break;
    case 3:
        lResult = pSysSave->lCardState;
        
        if (lResult == 100)
        {
            SetStateSysSaveFileBroken(pSysSave);
        }
        
        break;
    }
    
    lResult = pSysSave->lCardState;
    
    if ((lResult > 100) && (lResult < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveFreeCapacity(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 11;
}

// 100% matching!
void ExecuteStateSysSaveFreeCapacity(SYSSAVE_SCREEN* pSysSave)
{
    int lResult;

    lResult = GetMemoryCardFreeCapacity(pSysSave->pMcState);
    
    if (lResult < mcGetFreeCapacitySize())
    {
        if (lResult == -1)
        {
            SetStateSysSaveAwarenessCard(pSysSave);
        }
        
        if (lResult != -2)
        {
            SetStateSysSaveErrFreeCapacity(pSysSave);
        }
    }
    else
    {
        SetStateSysSaveCheckWriteSysData(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveErrFreeCapacity(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 12;
    
    pSysSave->cMesFlag = 2;
}

// 100% matching!
void ExecuteStateSysSaveErrFreeCapacity(SYSSAVE_SCREEN* pSysSave)
{
    if ((Pad->press & 0x800))
    {
        pSysSave->usExitFlag = 1;
        
        SetStateSysSaveTitleExit(pSysSave);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveCheckWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 13;
    
    pSysSave->cMesFlag = 7;
    
    pSysSave->sSelectCur = 1;
}

// 100% matching!
void ExecuteStateSysSaveCheckWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
    if ((Pad->press & 0x1000))
    {
        pSysSave->sSelectCur--;
        
        pSysSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((Pad->press & 0x4000))
    {
        pSysSave->sSelectCur++;
        
        pSysSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((Pad->press & GetOkButton()))
    {
        if (pSysSave->sSelectCur == 0)
        {
            SetStateSysSaveWriteSysData(pSysSave);
        }
        else
        {
            SetStateSysSaveExitWriteSysData(pSysSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((Pad->press & GetCancelButton()))
    {
        SetStateSysSaveExitWriteSysData(pSysSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 14;
    pSysSave->ulSubState = 0;
    
    pSysSave->usLoopCount = 0;
    
    pSysSave->cMesFlag = 8;
    
    pSysSave->sSelectCur = 1;
    
    SetCheckMcFlag(pSysSave->pMcState, 1);
}

// 100% matching!
void ExecuteStateSysSaveWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
    int lResult;

    switch (pSysSave->ulSubState)
    {
    case 0:
        lResult = CreateMemoryCardSubDirectory(pSysSave->pMcState);
        
        if (lResult == -1)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 8;
        }
        else if ((lResult == 1) && (mcNewCreateIcon(pSysSave->pIconInfo, pSysSave->pMcState, cpNameList, 0) == 1))
        {
            pSysSave->ulSubState = 1;
        }
        
        break;
    case 1:
        lResult = RecoveryMemoryCardWriteEnd(pSysSave->pMcState);
        
        if (lResult == 1)
        {
            pSysSave->ulSubState = 2;
        }
        else if (lResult == -1)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 8;
        }
        
        break;
    case 2:
        pSysSave->ulFileSize = mcReadIconData(pSysSave->vpReadBuffer, cpNameList, 1);
        
        if (pSysSave->ulFileSize == 0)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 8;
        }
        else
        {
            lResult = mcWriteIconData(pSysSave->pMcState, pSysSave->vpReadBuffer, pSysSave->ulFileSize, cpNameList, 1);
            
            if (lResult == 1)
            {
                pSysSave->ulSubState = 3;
            }
        }
        
        break;
    case 3:
        lResult = RecoveryMemoryCardWriteEnd(pSysSave->pMcState);
        
        if (lResult == -1)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 8;
        }
        else 
        {
            if (lResult == 1)
            {
                lResult = mcNewCreateConfigFile(pSysSave->pMcState, pSysSave->pConfigFile);

                if (lResult == 1)
                {
                    pSysSave->ulSubState = 4;
                }
            }
        }
        
        break;
    case 4:
        lResult = RecoveryMemoryCardWriteEnd(pSysSave->pMcState);
        
        if (lResult == 1)
        {
            pSysSave->ulSubState = 5;
        }
        else if (lResult == -1)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 8;
        }
        
        break;
    case 5:
        lResult = mcNewCreateSaveFile(pSysSave->pMcState, pSysSave->pSaveFile, cpNameList, pSysSave->usLoopCount);
        
        if (lResult != 0)
        {
            pSysSave->ulSubState = 6;
        }
        
        break;
    case 6:
        lResult = RecoveryMemoryCardWriteEnd(pSysSave->pMcState);
        
        if (lResult == 1)
        {
            if (++pSysSave->usLoopCount > 14)
            {
                pSysSave->ulSubState = 7;
                
                pSysSave->usLoopCount = 0;
                
                pSysSave->cMesFlag = 20;
                
                SetCheckMcFlag(pSysSave->pMcState, 0);
            }
            else
            {
                pSysSave->ulSubState = 5;
            }
        }
        else if (lResult == -1)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 8;
        }
        
        break;
    case 7:
        if (pSysSave->lCardState == 100)
        {
            SetStateSysSaveSuccessWriteSysData(pSysSave);
        }
        
        break;
    case 8:
        if (pSysSave->lCardState == 100)
        {
            SetStateSysSaveErrWriteSysData(pSysSave);
        }

        break;
    }
}

// 100% matching!
void SetStateSysSaveSuccessWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 15;
    
    pSysSave->cMesFlag = 9;
    
    pSysSave->ulMemCheckCountTimer = 15;
    
    SetCheckMcFlag(pSysSave->pMcState, 0);
}

// 100% matching!
void ExecuteStateSysSaveSuccessWriteSysData(SYSSAVE_SCREEN* pSysSave)
{   
    if (--pSysSave->ulMemCheckCountTimer == 0)
    {
        SetStateSysSaveDirCheck(pSysSave);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveErrWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 16;
    
    pSysSave->cMesFlag = 10;
}

// 100% matching!
void ExecuteStateSysSaveErrWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
    if ((Pad->press & 0x800))
    {
        pSysSave->usExitFlag = 1;
        
        SetStateSysSaveTitleExit(pSysSave);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveFileBroken(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 17;
    
    pSysSave->cMesFlag = 14;
}

// 100% matching!
void ExecuteStateSysSaveFileBroken(SYSSAVE_SCREEN* pSysSave)
{
    if ((Pad->press & 0x800))
    {
        pSysSave->usExitFlag = 1;
        
        SetStateSysSaveTitleExit(pSysSave);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveExitWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 18;
    
    pSysSave->cMesFlag = 15;
    
    pSysSave->sSelectCur = 1;
}

// 100% matching!
void ExecuteStateSysSaveExitWriteSysData(SYSSAVE_SCREEN* pSysSave)
{
    if ((Pad->press & 0x1000))
    {
        pSysSave->sSelectCur--;
        
        pSysSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((Pad->press & 0x4000))
    {
        pSysSave->sSelectCur++;
        
        pSysSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((Pad->press & GetOkButton()))
    {
        if (pSysSave->sSelectCur == 1) 
        {
            SetStateSysSaveAwarenessCard(pSysSave);
        } 
        else 
        {
            pSysSave->usExitFlag = 1;
            
            SetStateSysSaveTitleExit(pSysSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((Pad->press & GetCancelButton()))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateWriteRankingData(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 20;
    pSysSave->ulSubState = 0;
    
    SetCheckMcFlag(pSysSave->pMcState, 0);
    
    RecoveryMemoryCardError(pSysSave->pMcState);
}

// 100% matching!
void ExecuteStateWriteRankingData(SYSSAVE_SCREEN* pSysSave)
{
    CONFIGFILE RankingData;
    CONFIGFILE* pRankingData;
    int ulSaveResult;

    switch (pSysSave->ulSubState)
    {
    case 0:
        if (mcReadStartConfigFile(pSysSave->pMcState, pSysSave->pConfigFile) == 1)
        {
            pSysSave->ulSubState = 1;
        }
        
        break;
    case 1:
        ulSaveResult = mcCheckReadStartConfigFile(pSysSave->pMcState, pSysSave->pConfigFile);
        
        if (ulSaveResult > 0)
        {
            if (pSysSave->usSaveMode != 0)
            {
                pRankingData = mcCreateConfigInit(&RankingData);
                
                memcpy(pRankingData, pSysSave->pConfigFile, ulSaveResult);
                
                SysSaveHikaku(pRankingData);
            }
            else
            {
                memcpy(sys, pSysSave->pConfigFile, ulSaveResult);
            }
            
            SetStateSysSave(pSysSave);
        }
        else if (ulSaveResult < 0)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 2;
        }
        
        break;
    case 2:
        if (pSysSave->lCardState == 100)
        {
            SetStateSysSaveFileBroken(pSysSave);
        }
        
        break;
    }
}

// 100% matching!
void SetStateSysSave(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 30;
    pSysSave->ulSubState = 0;
    
    pSysSave->cMesFlag = 11;
    
    SetCheckMcFlag(pSysSave->pMcState, 1);
}

// 100% matching!
void ExecuteStateSysSave(SYSSAVE_SCREEN* pSysSave)
{
    int ulSaveResult;

    switch (pSysSave->ulSubState)
    {
    case 0:
        if (mcWriteStartConfigFile(pSysSave->pMcState, pSysSave->pConfigFile) == 1)
        {
            pSysSave->ulSubState = 1;
        }
        
        break;
    case 1:
        ulSaveResult = mcCheckWriteStartConfigFile(pSysSave->pMcState);
        
        if (ulSaveResult == 1)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            pSysSave->usExitFlag = 2;
            
            SetStateSysSaveTitleExit(pSysSave);
        }
        else if (ulSaveResult < 0)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 2;
        }
        
        break;
    case 2:
        if (pSysSave->lCardState == 100)
        {
            SetStateSysSaveErrCardWrite(pSysSave);
        }
        
        break;
    }
}

// 100% matching!
void SetStateSysSaveErrCardWrite(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 31;
    
    pSysSave->cMesFlag = 13;
    
    SetCheckMcFlag(pSysSave->pMcState, 0);
}

// 100% matching!
void ExecuteStateSysSaveErrCardWrite(SYSSAVE_SCREEN* pSysSave)
{
    if ((Pad->press & 0x800))
    {
        pSysSave->usExitFlag = 1;
        
        SetStateSysSaveTitleExit(pSysSave);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveFormat(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 40;
    
    pSysSave->cMesFlag = 3;
    
    pSysSave->sSelectCur = 1;
}

// 100% matching!
void ExecuteStateSysSaveFormat(SYSSAVE_SCREEN* pSysSave)
{
    if ((Pad->press & 0x1000))
    {
        pSysSave->sSelectCur--;
        
        pSysSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((Pad->press & 0x4000))
    {
        pSysSave->sSelectCur++;
        
        pSysSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((Pad->press & GetOkButton()))
    {
        if (pSysSave->sSelectCur == 1)
        {
            SetStateSysSaveExitFormat(pSysSave);
        }
        else
        {
            SetStateSysSaveStartFormat(pSysSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((Pad->press & GetCancelButton()))
    {
        SetStateSysSaveExitFormat(pSysSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveStartFormat(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 41;
    pSysSave->ulSubState = 0;
    
    pSysSave->cMesFlag = 4;
    
    SetCheckMcFlag(pSysSave->pMcState, 1);
}

// 100% matching!
void ExecuteStateSysSaveStartFormat(SYSSAVE_SCREEN* pSysSave)
{
    int lFormatResult;
    
    switch (pSysSave->ulSubState)
    {
    case 0:
        if (FormatMemoryCard(pSysSave->pMcState) == 1)
        {
            pSysSave->ulSubState = 1;
        }
        
        break;
    case 1:
        lFormatResult = RecoveryMemoryCardFormatEnd(pSysSave->pMcState);

        if (lFormatResult == 1)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            pSysSave->ulSubState = 2;
        }
        else if (lFormatResult == -1)
        {
            SetCheckMcFlag(pSysSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSysSave->pMcState);
            
            pSysSave->ulSubState = 3;
        }
        
        break;
    case 2:
        if (pSysSave->lCardState == 100)
        {
            SetStateSysSaveSuccessFormat(pSysSave);
        }
        
        break;
    case 3:
        if (pSysSave->lCardState == 100)
        {
            SetStateSysSaveErrFormat(pSysSave);
        }
        
        break;
    }
}

// 100% matching!
void SetStateSysSaveExitFormat(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 42;
    
    pSysSave->cMesFlag = 15;
    
    pSysSave->sSelectCur = 1;
}

// 100% matching!
void ExecuteStateSysSaveExitFormat(SYSSAVE_SCREEN* pSysSave)
{
    if ((Pad->press & 0x1000))
    {
        pSysSave->sSelectCur--;

        pSysSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((Pad->press & 0x4000))
    {
        pSysSave->sSelectCur++;
        
        pSysSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((Pad->press & GetOkButton()))
    {
        if (pSysSave->sSelectCur == 1) 
        {
            SetStateSysSaveAwarenessCard(pSysSave);
        }
        else 
        {
            pSysSave->usExitFlag = 1;
            
            SetStateSysSaveTitleExit(pSysSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((Pad->press & GetCancelButton()))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveSuccessFormat(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 43;
    
    pSysSave->cMesFlag = 5;
    
    pSysSave->ulMemCheckCountTimer = 60;
}

// 100% matching!
void ExecuteStateSysSaveSuccessFormat(SYSSAVE_SCREEN* pSysSave)
{
    if (--pSysSave->ulMemCheckCountTimer == 0)
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
    else if ((pSysSave->lCardState > 100) && (pSysSave->lCardState < 104))
    {
        SetStateSysSaveAwarenessCard(pSysSave);
    }
}

// 100% matching!
void SetStateSysSaveErrFormat(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 44;
    
    pSysSave->cMesFlag = 6;
    
    pSysSave->sSelectCur = 0;
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

// 100% matching!
void SetStateSysSaveTitleExit(SYSSAVE_SCREEN* pSysSave)
{
    pSysSave->ulState = 50;
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
