#include "ps2_SystemLoadScreen.h"
#include "adv.h"
#include "message.h"
#include "ps2_McSaveFile.h"
#include "ps2_MemoryCard.h"
#include "vibman.h"
#include "main.h"

#include <string.h>

// 100% matching!
SYSLOAD_SCREEN* CreateSysLoadScreen(SYSLOAD_SCREEN* pSysLoad, void* vpWorkPtrSys)
{
    pSysLoad->ulState = 0;
    pSysLoad->ulSubState = 0;
    
    pSysLoad->ulFileSize = 0;
    
    pSysLoad->ulMemCheckCountTimer = 0;
    
    pSysLoad->lCardState = 0;
    
    pSysLoad->usExitFlag = 0;
    
    pSysLoad->usLoopCount = 0;
    
    pSysLoad->cMesFlag = 0;
    
    pSysLoad->pConfigFile = mcCreateConfigInit(&ConfigFile);
    pSysLoad->pSaveFile = mcCreateSaveFileInit(&SaveFile);
    
    pSysLoad->pMcState = CreateMemoryCard(&McState);
    
    pSysLoad->pIconInfo = mcCreateIconInit(&IconInfo, cpNameList, 1);
    
    pSysLoad->pSelectFileInfo = mcSelectFileInfoInit(SelectFileInfo);
    pSysLoad->pSelectFileWindow = mcCreateFileSelectWindow(&SelectFileWindow, pSysLoad->pSelectFileInfo, 15);
    
    pSysLoad->vpReadBuffer = vpWorkPtrSys;
    
    AnalyzeMemoryCardAll(pSysLoad->pMcState);
    
    return pSysLoad;
}

// 99.37% matching
void DispSysLoadMessageSelect(int slSelectMes)
{ 
    bhFontScaleSet(0.71f, 0.71f, 0.75f); 

    switch (slSelectMes) 
    {  
    case 0:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 0);
        break; 
    case 1:
        AutoSaveLoadEasyDispMessage(-1.0f, 88.0f, SaveLoadMessage, 10); 
        break;
    case 2:
        AutoSaveLoadEasyDispMessage(-1.0f, 88.0f, SaveLoadMessage, 11);
        break;
    case 3:
        AutoSaveLoadEasyDispMessage(-1.0f, 56.0f, SaveLoadMessage, 12);
        break;
    case 4:
        AutoSaveLoadEasyDispMessage(-1.0f, 56.0f, SaveLoadMessage, 13);
        break;
    case 5:
        AutoSaveLoadEasyDispMessage(-1.0f, 56.0f, SaveLoadMessage, 14);
        break;
    case 6:
        AutoSaveLoadEasyDispMessage(-1.0f, 132.0f, SaveLoadMessage, 15);
        break;
    case 7:
    case 8:
        AutoSaveLoadEasyDispMessage(-1.0f, 88.0f, SaveLoadMessage, 16);
        break;
    case 9:
        AutoSaveLoadEasyDispMessage(-1.0f, 176.0f, SaveLoadMessage, 17);
        break;
    case 10:
        AutoSaveLoadEasyDispMessage(-1.0f, 132.0f, SaveLoadMessage, 18);
        break;
    case 11:
        AutoSaveLoadEasyDispMessage(-1.0f, 132.0f, SaveLoadMessage, 19);
        break;
    case 12:
        break;
    }
    
    bhFontScaleSet(1.0f, 1.0f, 1.0f); 
} 

// 100% matching!
int ExecuteSysLoadScreen(SYSLOAD_SCREEN* pSysLoad) 
{ 
    pSysLoad->lCardState = ExecuteMemoryCard(pSysLoad->pMcState); 
    
    switch (pSysLoad->ulState) 
    { 
    case 0:
        ExecuteStateSysLoadScreenAwarenessCard(pSysLoad); 
        break; 
    case 1:
        ExecuteStateSysLoadScreenErrAwareness(pSysLoad); 
        break; 
    case 10:
        ExecuteStateSysLoadScreenDirCheck(pSysLoad); 
        break; 
    case 11:
        ExecuteStateSysLoadScreenFreeCapacity(pSysLoad); 
        break; 
    case 12:
        ExecuteStateSysLoadScreenErrFreeCapacity(pSysLoad); 
        break; 
    case 13:
        ExecuteStateSysLoadScreenNoSysFile(pSysLoad); 
        break; 
    case 30:
        ExecuteStateSysLoadScreenSysLoad(pSysLoad); 
        break; 
    case 31:
        ExecuteStateSysLoadScreenFileBroken(pSysLoad); 
        break; 
    case 32:
        ExecuteStateSysLoadScreenErrCardRead(pSysLoad); 
        break; 
    case 40:
        ExecuteStateSysLoadScreenTitleExit(); 
        break;
    }

    DispSysLoadMessageSelect(pSysLoad->cMesFlag); 

    return pSysLoad->usExitFlag; 
} 

// 100% matching! 
void SetStateSysLoadScreenAwarenessCard(SYSLOAD_SCREEN* pSysLoad)
{
    pSysLoad->ulState = 0;
    
    pSysLoad->cMesFlag = 0;
    
    RecoveryMemoryCardError(pSysLoad->pMcState);
    
    AnalyzeMemoryCardAll(pSysLoad->pMcState);
}

// 100% matching!
void ExecuteStateSysLoadScreenAwarenessCard(SYSLOAD_SCREEN* pSysLoad)
{ 
    int lResult;

    lResult = RecoveryMemoryCardAnalyzeAllEnd(pSysLoad->pMcState); 
    
    if (lResult == -1) 
    { 
        SetStateSysLoadScreenAwarenessCard(pSysLoad); 
    }
    else if (lResult == 0) 
    { 
        return;
    }

    if ((GetMemoryCardSelectPortState(pSysLoad->pMcState, 0) == 2) && (GetMemoryCardSelectPortFormatType(pSysLoad->pMcState, 0) == 1)) 
    { 
        SetStateSysLoadScreenDirCheck(pSysLoad); 
    } 
    else 
    { 
        SetStateSysLoadScreenErrAwareness(pSysLoad); 
    }
} 

// 99.90% matching
void SetStateSysLoadScreenErrAwareness(SYSLOAD_SCREEN* pSysLoad) 
{
    static unsigned char MesTbl[3][5] =
    { 
        { 1, 1, 5, 2, 2 }, 
        { 1, 1, 5, 2, 2 }, 
        { 6, 6, 6, 6, 6 } 
    };
    int lType1;
    int lType2;
    int lSlot1;
    int lSlot2;
    int lFree2;
    int lDir2;
    char cFormat1;
    char cFormat2;

    lSlot1 = GetMemoryCardSelectPortState(pSysLoad->pMcState, 0);
    lSlot2 = GetMemoryCardSelectPortState(pSysLoad->pMcState, 1);
    
    cFormat1 = GetMemoryCardSelectPortFormatType(pSysLoad->pMcState, 0);
    cFormat2 = GetMemoryCardSelectPortFormatType(pSysLoad->pMcState, 1);
    
    lFree2 = GetMemoryCardSelectPortFreeCapacity(pSysLoad->pMcState, 1);
    
    SetMemoryCardCurrentPort(pSysLoad->pMcState, 1);
    
    lDir2 = CheckMemoryCardExistSubDirectory(pSysLoad->pMcState);
    
    if (lSlot1 == 0)
    {
        lType1 = 0;
    }
    else if ((lSlot1 != 0) && (lSlot1 != 2))
    {
        lType1 = 1;
    } 
    else if (cFormat1 == 0)
    {
        lType1 = 2;
    } 
    else 
    {
        lType1 = 0;
    }

    if (lSlot2 == 0) 
    {
        lType2 = 0;
    }
    else if ((lSlot2 != 0) && (lSlot2 != 2))
    {
        lType2 = 1;
    } 
    else if (cFormat2 == 0) 
    {
        lType2 = 4;
    } 
    else if (lDir2 == 1)
    {
        lType2 = 3;
    }
    else if ((0 <= lFree2) && (lFree2 < mcGetFreeCapacitySize())) 
    {
        lType2 = 2;
    } 
    else if (lFree2 >= mcGetFreeCapacitySize())
    {
        lType2 = 3;
    } 
    else 
    {
        lType2 = 0;
    }
    
    pSysLoad->cMesFlag = MesTbl[lType1][lType2];
    
    pSysLoad->ulState = 1;
}

// 100% matching! 
void ExecuteStateSysLoadScreenErrAwareness(SYSLOAD_SCREEN* pSysLoad)
{
    if ((Pad->press & 0x800)) 
    {
        pSysLoad->usExitFlag = 1;
        
        SetStateSysLoadScreenTitleExit(pSysLoad);
    }
    else if ((pSysLoad->lCardState > 100) && (pSysLoad->lCardState < 104)) 
    {
        SetStateSysLoadScreenAwarenessCard(pSysLoad);
    }
}

// 100% matching! 
void SetStateSysLoadScreenDirCheck(SYSLOAD_SCREEN* pSysLoad)
{
    pSysLoad->ulState = 10;
    pSysLoad->ulSubState = 0;
    
    pSysLoad->cMesFlag = 0;
    
    pSysLoad->ulMemCheckCountTimer = 10;
    
    SetMemoryCardCurrentPort(pSysLoad->pMcState, 0);
    SetCheckMcFlag(pSysLoad->pMcState, 1);
}

// 100% matching! 
void ExecuteStateSysLoadScreenDirCheck(SYSLOAD_SCREEN* pSysLoad)
{
    int lResult;
    
    switch (pSysLoad->ulSubState) 
    {                           
    case 0:
        lResult = CheckMemoryCardExistSubDirectory(pSysLoad->pMcState);
        
        if (lResult == 1)
        {
            pSysLoad->ulSubState = 1;
        }
        else if (lResult < 0)
        {
            SetCheckMcFlag(pSysLoad->pMcState, 0);
            
            pSysLoad->ulSubState = 2;
        }
        
        break;
    case 1:
        lResult = CheckMemoryCardExistFileList(pSysLoad->pMcState, cpNameList, 18);
        
        if (lResult < 0)
        {
            SetCheckMcFlag(pSysLoad->pMcState, 0);
            
            pSysLoad->ulSubState = 3;
        } 
        else if (lResult == 1)
        {
            SetStateSysLoadScreenSysLoad(pSysLoad);
        }
        
        break;
    case 2:
        if (pSysLoad->lCardState == 100) 
        {
            SetStateSysLoadScreenFreeCapacity(pSysLoad);
        }
        
        break;
    case 3:
        if (pSysLoad->lCardState == 100) 
        {
            SetStateSysLoadScreenFileBroken(pSysLoad);
        }
        
        break;
    }
    
    if ((pSysLoad->lCardState > 100) && (pSysLoad->lCardState < 104))
    {
        SetStateSysLoadScreenAwarenessCard(pSysLoad);
    }
}

// 100% matching! 
void SetStateSysLoadScreenFreeCapacity(SYSLOAD_SCREEN* pSysLoad)
{
    pSysLoad->ulState = 11;
    
    pSysLoad->cMesFlag = 0;
}

// 100% matching! 
void ExecuteStateSysLoadScreenFreeCapacity(SYSLOAD_SCREEN* pSysLoad)
{
    int lFree1;

    lFree1 = GetMemoryCardSelectPortFreeCapacity(pSysLoad->pMcState, 0);
    
    if (lFree1 < mcGetFreeCapacitySize()) 
    {
        SetStateSysLoadScreenErrFreeCapacity(pSysLoad);
    }
    else 
    {
        SetStateSysLoadScreenNoSysFile(pSysLoad);
    }
}

// 99.86% match
void SetStateSysLoadScreenErrFreeCapacity(SYSLOAD_SCREEN* pSysLoad)
{
    static unsigned char MesTbl[1][5] =
    { 
        { 4, 4, 3, 4, 4 } 
    };
    int lType2;
    int lSlot2;
    int lFree2;
    int lDir2;
    char cFormat2;

    lSlot2 = GetMemoryCardSelectPortState(pSysLoad->pMcState, 1);
    
    lFree2 = GetMemoryCardSelectPortFreeCapacity(pSysLoad->pMcState, 1);

    cFormat2 = GetMemoryCardSelectPortFormatType(pSysLoad->pMcState, 1);
    
    SetMemoryCardCurrentPort(pSysLoad->pMcState, 1);
    
    lDir2 = CheckMemoryCardExistSubDirectory(pSysLoad->pMcState);
    
    if (lSlot2 == 0) 
    {
        lType2 = 0;
    }
    else if ((lSlot2 != 0) && (lSlot2 != 2))
    {
        lType2 = 1;
    } 
    else if (cFormat2 == 0) 
    {
        lType2 = 4;
    } 
    else if (lDir2 == 1)
    {
        lType2 = 3;
    }
    else if ((0 <= lFree2) && (lFree2 < mcGetFreeCapacitySize())) 
    {
        lType2 = 2;
    } 
    else if (lFree2 >= mcGetFreeCapacitySize())
    {
        lType2 = 3;
    } 
    else 
    {
        lType2 = 0;
    }
    
    pSysLoad->cMesFlag = MesTbl[0][lType2];
    
    pSysLoad->ulState = 12;
}

// 100% matching!
void ExecuteStateSysLoadScreenErrFreeCapacity(SYSLOAD_SCREEN* pSysLoad)
{
    if ((Pad->press & 0x800)) 
    {
        pSysLoad->usExitFlag = 1;
        
        SetStateSysLoadScreenTitleExit(pSysLoad);
    }
    else if ((pSysLoad->lCardState > 100) && (pSysLoad->lCardState < 104)) 
    {
        SetStateSysLoadScreenAwarenessCard(pSysLoad);
    }
}

// 100% matching!
void SetStateSysLoadScreenNoSysFile(SYSLOAD_SCREEN* pSysLoad)
{
    pSysLoad->ulState = 13;
    
    pSysLoad->cMesFlag = 8;
}

// 100% matching!
void ExecuteStateSysLoadScreenNoSysFile(SYSLOAD_SCREEN* pSysLoad)
{
    if ((Pad->press & 0x800)) 
    {
        pSysLoad->usExitFlag = 1;
        
        SetStateSysLoadScreenTitleExit(pSysLoad);
    }
    else if ((pSysLoad->lCardState > 100) && (pSysLoad->lCardState < 104)) 
    {
        SetStateSysLoadScreenAwarenessCard(pSysLoad);
    }
}

// 100% matching!
void SetStateSysLoadScreenSysLoad(SYSLOAD_SCREEN* pSysLoad)
{
    pSysLoad->ulState = 30;
    pSysLoad->ulSubState = 0;
    
    pSysLoad->cMesFlag = 9;
    
    pSysLoad->ulMemCheckCountTimer = 10;
}

// 100% matching!
void ExecuteStateSysLoadScreenSysLoad(SYSLOAD_SCREEN* pSysLoad)
{
    int ulLoadResult;
    
    switch (pSysLoad->ulSubState) 
    {                             
    case 0:
        if (mcReadStartConfigFile(pSysLoad->pMcState, pSysLoad->pConfigFile) == 1) 
        {
            pSysLoad->ulSubState = 1;
        }
        
        break;
    case 1:
        ulLoadResult = mcCheckReadStartConfigFile(pSysLoad->pMcState, pSysLoad->pConfigFile);
        
        if (ulLoadResult > 0) 
        {                     
            memcpy(sys, pSysLoad->pConfigFile, ulLoadResult);
            
            pSysLoad->usExitFlag = 2;
            
            SetUseVibrationUnit(pSysLoad->pConfigFile->vibration);
            SetStateSysLoadScreenTitleExit(pSysLoad);
        }
        else if (ulLoadResult == -1)
        {
            SetCheckMcFlag(pSysLoad->pMcState, 0);
            
            RecoveryMemoryCardError(pSysLoad->pMcState);
            
            pSysLoad->ulSubState = 2;
        }
        else if (ulLoadResult == -2) 
        {      
            SetCheckMcFlag(pSysLoad->pMcState, 0);
            
            RecoveryMemoryCardError(pSysLoad->pMcState);
            
            pSysLoad->ulSubState = 3;
        }
        
        break;
    case 2:
        if (pSysLoad->lCardState == 100) 
        {
            SetStateSysLoadScreenErrCardRead(pSysLoad);
        }
        
        break;
    case 3:
        if (pSysLoad->lCardState == 100) 
        {
            SetStateSysLoadScreenFileBroken(pSysLoad);
        }
        
        break;
    }
}

// 100% matching!
void SetStateSysLoadScreenFileBroken(SYSLOAD_SCREEN* pSysLoad)
{ 
    pSysLoad->ulState = 31; 
    
    pSysLoad->cMesFlag = 11; 
}

// 100% matching!
void ExecuteStateSysLoadScreenFileBroken(SYSLOAD_SCREEN* pSysLoad)
{
    if ((Pad->press & 0x800)) 
    {
        pSysLoad->usExitFlag = 1;
        
        SetStateSysLoadScreenTitleExit(pSysLoad);
    }
    else if ((pSysLoad->lCardState > 100) && (pSysLoad->lCardState < 104)) 
    {
        SetStateSysLoadScreenAwarenessCard(pSysLoad);
    }
}

// 100% matching!
void SetStateSysLoadScreenErrCardRead(SYSLOAD_SCREEN* pSysLoad) 
{ 
    pSysLoad->ulState = 32; 
    
    pSysLoad->cMesFlag = 10; 
}

// 100% matching!
void ExecuteStateSysLoadScreenErrCardRead(SYSLOAD_SCREEN* pSysLoad)
{
    if ((Pad->press & 0x800))
    {
        pSysLoad->usExitFlag = 1;
        
        SetStateSysLoadScreenTitleExit(pSysLoad);
    }
    else if ((pSysLoad->lCardState > 100) && (pSysLoad->lCardState < 104)) 
    {
        SetStateSysLoadScreenAwarenessCard(pSysLoad);
    }
}

// 100% matching!
void SetStateSysLoadScreenTitleExit(SYSLOAD_SCREEN* pSysLoad) 
{ 
    pSysLoad->ulState = 40; 

    pSysLoad->ulMemCheckCountTimer = 1; 

    SetCheckMcFlag(pSysLoad->pMcState, 0); 
    
    RecoveryMemoryCardError(pSysLoad->pMcState); 
} 

// 100% matching!
void ExecuteStateSysLoadScreenTitleExit()
{
    sys->typ_md1 = 0;

    if (!(sys->tk_flg & 0x2000)) 
    {
        sys->typ_md0 = 0;
    }
}
