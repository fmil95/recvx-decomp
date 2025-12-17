#include "ps2_LoadScreen.h"
#include "message.h"
#include "ps2_McSaveFile.h"
#include "ps2_MemoryCard.h"
#include "sdfunc.h"
#include "main.h"

// 100% matching!
LOAD_SCREEN* CreateLoadScreen(LOAD_SCREEN* pLoad, void* vpWorkPtrSys) // second parameter is not present on the debugging symbols
{
    pLoad->ulState = 0;
    pLoad->ulSubState = 0;
    
    pLoad->ulMemCheckCountTimer = 0;
    
    pLoad->ulFileSize = 0;
    
    pLoad->lCardState = 0;
    
    pLoad->sCursorX = 0;
    pLoad->sCursorY = 0;
    
    pLoad->sSelectCur = 0;
    
    pLoad->usExitFlag = 0;
    
    pLoad->usSaveEnd = 0;
    
    pLoad->usLoopCount = 0;
    
    pLoad->cMesFlag = 0;
    pLoad->cCgFlag = 0;
    
    pLoad->pConfigFile = mcCreateConfigInit(&ConfigFile);
    pLoad->pSaveFile = mcCreateSaveFileInit(&SaveFile);
    
    pLoad->pMcState = CreateMemoryCard(&McState);
    
    pLoad->pIconInfo = mcCreateIconInit(&IconInfo, cpNameList, 1);
    
    pLoad->pSelectFileInfo = mcSelectFileInfoInit(SelectFileInfo);
    pLoad->pSelectFileWindow = mcCreateFileSelectWindow(&SelectFileWindow, pLoad->pSelectFileInfo, 15);
    
    CheckMemoryCardChangeConnectTypeAll(pLoad->pMcState);
    
    return pLoad;
}

// 98.69% matching
void DispLoadMessageSelect(char cSelectMes)
{
    bhFontScaleSet(0.71f, 0.71f, 0.75f);

    switch (cSelectMes) 
    {
    case 0:
        SetDispLoadSelectMessage();
        break;
    case 1:
    case 2:
        bhDispMessage(160.0f, 224.0f, -1.0f, 1, 455, 3, 0);
        
        SetDispLoadSelectMessage();
        break;
    case 3:
        bhDispMessage(100.0f, 194.0f, -1.0f, 1, 456, 3, 0);
        break;
    case 4:
        bhDispMessage(50.0f, 194.0f, -1.0f, 1, 457, 3, 0);
        break;
    case 5:
        break;
    case 6:
        bhDispMessage(275.0f, 194.0f, -1.0f, 1, 458, 3, 0);
        break;
    case 7:
        bhDispMessage(240.0f, 311.0f, -1.0f, 1, 459, 0, 0);
        bhDispMessage(290.0f, 360.0f, -1.0f, 1, 466, 0, 0);
        break;
    case 8:
        bhDispMessage(90.0f, 311.0f, -1.0f, 1, 460, 0, 0);
        break;
    case 9:
        bhDispMessage(242.0f, 194.0f, -1.0f, 1, 461, 3, 0);
        break;
    case 10:
        bhDispMessage(210.0f, 194.0f, -1.0f, 1, 462, 3, 0);
        break;
    case 11:
        bhDispMessage(90.0f, 194.0f, -1.0f, 1, 451, 0, 0);
        break;
    }
    
    bhFontScaleSet(1.0f, 1.0f, 1.0f);
}

// 99.59% matching
void DispLoadTexture(LOAD_SCREEN* pLoad)
{
    int DispLoadPortCard;
    
    switch (pLoad->cCgFlag) 
    {
    case 0:
        CheckDispLoadMemoryCard(pLoad);
        break;
    case 1:
        DispLoadPortCard = GetMemoryCardCurrentPort(pLoad->pMcState);
        
        mcDisplayFileSelectWindow(pLoad->pSelectFileWindow, 60.0f, 108.0f, DispLoadPortCard);
        break;
    case 2:
        DispLoadPortCard = GetMemoryCardCurrentPort(pLoad->pMcState);
        
        mcDisplayFileSelectWindow(pLoad->pSelectFileWindow, 60.0f, 108.f, DispLoadPortCard);
        
        DispUpDownCursol(256.0f, 358.0f, pLoad->sSelectCur + 2);
        break;
    }
}

// 100% matching! 
int ExecuteLoadScreen(LOAD_SCREEN* pLoad)
{
    pLoad->lCardState = ExecuteMemoryCard(pLoad->pMcState);
    
    DispBackGroundTexture();
    
    switch (pLoad->ulState) 
    {                              
    case 0:
        ExecuteStateLoadScreenAwarenessCard(pLoad);
        break;
    case 1:
        ExecuteStateLoadScreenErrLostCard(pLoad);
        break;
    case 2:
        ExecuteStateLoadScreenErrUnPS2MemCard(pLoad);
        break;
    case 10:
        ExecuteStateLoadScreenSelectCard(pLoad);
        break;
    case 11:
        ExecuteStateLoadScreenTitleExit(pLoad);
        break;
    case 12:
        ExecuteStateLoadScreenErrUnFormat(pLoad);
        break;
    case 13:
        ExecuteStateLoadScreenErrLostDirCheck(pLoad);
        break;
    case 14:
        ExecuteStateLoadScreenDirCheck(pLoad);
        break;
    case 15:
        ExecuteStateLoadScreenDirFileBroken(pLoad);
        break;
    case 20:
        ExecuteStateLoadScreenSelectFile(pLoad);
        break;
    case 21:
        ExecuteStateLoadScreenNoSave(pLoad);
        break;
    case 30:
        ExecuteStateLoadScreenLoadCursor(pLoad);
        break;
    case 31:
        ExecuteStateLoadScreenLoad(pLoad);
        break;
    case 32:
        ExecuteStateLoadScreenFileBroken(pLoad);
        break;
    case 33:
        ExecuteStateLoadScreenErrCardRead(pLoad);
        break;
    case 34:
        ExecuteStateLoadScreenLoadExit(pLoad);
        break;
    }
    
    DispLoadTexture(pLoad);
    DispLoadMessageSelect(pLoad->cMesFlag);
    
    return 0;
}

// 100% matching! 
void SetStateLoadScreenAwarenessCard(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 0;
    pLoad->ulSubState = 0;
    
    pLoad->usLoopCount = 0;
    
    SetCheckMcFlag(pLoad->pMcState, 0);
}

// 100% matching! 
void ExecuteStateLoadScreenAwarenessCard(LOAD_SCREEN* pLoad)
{
    int lPort0State;
    int lPort1State;
    
    switch (pLoad->lCardState)
    {                              
    case 100:
        lPort0State = GetMemoryCardSelectPortState(pLoad->pMcState, 0);
        lPort1State = GetMemoryCardSelectPortState(pLoad->pMcState, 1);
        
        if ((lPort0State == 2) || (lPort1State == 2))
        {                     
            SetStateLoadScreenSelectCard(pLoad);
        }
        else if (((lPort0State != 2) && (lPort0State != 0)) || ((lPort1State != 2) && (lPort1State != 0))) 
        {
            SetStateLoadScreenErrUnPS2MemCard(pLoad);
        }
        else 
        {
            SetStateLoadScreenErrLostCard(pLoad);
        }
                
        break;
    case 101:
        SetStateLoadScreenSelectCard(pLoad);
        break;
    case 102:
        SetStateLoadScreenErrUnPS2MemCard(pLoad);
        break;
    case 103:
        SetStateLoadScreenErrLostCard(pLoad);
        break;
    }
}

// 100% matching! 
void SetStateLoadScreenErrLostCard(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 1;
    
    pLoad->cMesFlag = 1;
    pLoad->cCgFlag = 0;
}

// 100% matching! 
void ExecuteStateLoadScreenErrLostCard(LOAD_SCREEN* pLoad)
{
    int lPort0State;
    int lPort1State;
    
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateLoadScreenTitleExit(pLoad);
        
        CallSystemSe(0, 3);
        return;
    }
    
    switch (pLoad->lCardState) 
    {
    case 100:
        lPort0State = GetMemoryCardSelectPortState(pLoad->pMcState, 0);
        lPort1State = GetMemoryCardSelectPortState(pLoad->pMcState, 1);
        
        if ((lPort0State == 2) || (lPort1State == 2))
        {                     
            SetStateLoadScreenSelectCard(pLoad);
        }
        else if (((lPort0State != 2) && (lPort0State != 0)) || ((lPort1State != 2) && (lPort1State != 0))) 
        {
            SetStateLoadScreenErrUnPS2MemCard(pLoad);
        }
                
        break;
    case 101:
        SetStateLoadScreenAwarenessCard(pLoad);
        break;
    case 102:
        SetStateLoadScreenErrUnPS2MemCard(pLoad);
        break;
    }
}

// 100% matching! 
void SetStateLoadScreenErrUnPS2MemCard(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 2;
    
    pLoad->cMesFlag = 2;
    pLoad->cCgFlag = 0;
}

// 100% matching! 
void ExecuteStateLoadScreenErrUnPS2MemCard(LOAD_SCREEN* pLoad)
{
    int lPort0State;
    int lPort1State;
 
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateLoadScreenTitleExit(pLoad);
        
        CallSystemSe(0, 3);
        return;
    }
    
    switch (pLoad->lCardState) 
    {
    case 100:  
        lPort0State = GetMemoryCardSelectPortState(pLoad->pMcState, 0);
        lPort1State = GetMemoryCardSelectPortState(pLoad->pMcState, 1);

        if ((lPort0State == 2) || (lPort1State == 2)) 
        {
            SetStateLoadScreenSelectCard(pLoad);
        } 
        else if ((lPort0State == 0) && (lPort1State == 0))
        {
            SetStateLoadScreenErrLostCard(pLoad);
        }
        
        break;
    case 101:  
        SetStateLoadScreenAwarenessCard(pLoad);
        break;
    case 103:  
        SetStateLoadScreenErrLostCard(pLoad);
        break;
    }
}

// 100% matching! 
void SetStateLoadScreenSelectCard(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 10;
    
    pLoad->sCursorY = 0;
    
    pLoad->sSelectCur = 0;

    pLoad->cMesFlag = 0;
    pLoad->cCgFlag = 0;
    
    SetMemoryCardFileNumber(pLoad->pMcState, 0);

    mcSetFileSelectWindowCursolInit(pLoad->pSelectFileWindow);
}

// 100% matching! 
void ExecuteStateLoadScreenSelectCard(LOAD_SCREEN* pLoad)
{
    if ((sys->pad_ps & 0x1)) 
    {
        pLoad->sCursorY--;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x2))
    {
        pLoad->sCursorY++;
        
        CallSystemSe(0, 2);
    }
    
    pLoad->sCursorY &= 0x1;
    
    if ((pLoad->sCursorY == 0) && ((GetMemoryCardSelectPortState(pLoad->pMcState, 0) == 2) && (GetMemoryCardSelectPortState(pLoad->pMcState, 1) == 2)))
    {
        if ((sys->pad_ps & 0x4)) 
        {
            pLoad->sCursorX--;
            
            CallSystemSe(0, 2);
        }
        else if ((sys->pad_ps & 0x8)) 
        {
            pLoad->sCursorX++;
            
            CallSystemSe(0, 2);
        }
        
        pLoad->sCursorX &= 0x1;
        
        pLoad->sSelectCur = pLoad->sCursorX;
    }
    
    if ((sys->pad_ps & 0x800)) 
    {
        if (pLoad->sCursorY == 1) 
        {
            SetStateLoadScreenTitleExit(pLoad);
        } 
        else 
        {
            SetStateLoadScreenDirCheck(pLoad);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateLoadScreenTitleExit(pLoad);
        
        CallSystemSe(0, 0);
    }
    else if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
}

// 100% matching! 
void SetStateLoadScreenTitleExit(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 11;
    
    pLoad->cMesFlag = 100;
    pLoad->cCgFlag = 100;
    
    pLoad->ulMemCheckCountTimer = 1;
}

// 100% matching! 
void ExecuteStateLoadScreenTitleExit(LOAD_SCREEN* pLoad)
{
    if (--pLoad->ulMemCheckCountTimer == 0) 
    {
        pLoad->usExitFlag = 1;
    }
}

// 100% matching! 
void SetStateLoadScreenErrUnFormat(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 12;
    
    pLoad->cMesFlag = 3;
    pLoad->cCgFlag = 100;
    
    SetCheckMcFlag(pLoad->pMcState, 0);
}

// 100% matching! 
void ExecuteStateLoadScreenErrUnFormat(LOAD_SCREEN* pLoad)
{
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
        
        CallSystemSe(0, 3);
    }
    else if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
}

// 100% matching! 
void SetStateLoadScreenErrLostDirCheck(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 13;
    
    pLoad->cMesFlag = 4;
    pLoad->cCgFlag = 100;
}

// 100% matching! 
void ExecuteStateLoadScreenErrLostDirCheck(LOAD_SCREEN* pLoad)
{
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
        
        CallSystemSe(0, 3);
    }
    else if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
}

// 100% matching! 
void SetStateLoadScreenDirCheck(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 14;
    
    pLoad->cMesFlag = 11;
    pLoad->cCgFlag = 100;
    
    pLoad->ulSubState = 0;
    
    pLoad->usLoopCount = 0;
    
    pLoad->ulMemCheckCountTimer = 10;
    
    SetMemoryCardFileNumber(pLoad->pMcState, 0);
    SetMemoryCardCurrentPort(pLoad->pMcState, pLoad->sCursorX);
    
    SetCheckMcFlag(pLoad->pMcState, 1);
}

// 100% matching! 
void ExecuteStateLoadScreenDirCheck(LOAD_SCREEN* pLoad)
{
    int lResult;
    
    switch (pLoad->ulSubState)
    {
    case 0:
        lResult = CheckMemoryCardFormatStatus(pLoad->pMcState);
        
        if (lResult == 1)
        {
            if (--pLoad->ulMemCheckCountTimer == 0)
            {
                SetStateLoadScreenErrUnFormat(pLoad);
            }
            
            return;
        }
        else if (lResult == 2)
        {
            pLoad->ulSubState = 1;
        }
        else if (lResult == -1)
        {
            SetCheckMcFlag(pLoad->pMcState, 0);
            
            RecoveryMemoryCardError(pLoad->pMcState);
            
            pLoad->ulSubState = 6;
        }
        
        break;
    case 1:
        lResult = CheckMemoryCardExistSubDirectory(pLoad->pMcState);
        
        if (lResult == 1)
        {
            pLoad->ulSubState = 2;
        }
        else if (lResult == -1)
        {
            SetCheckMcFlag(pLoad->pMcState, 0);
            
            pLoad->ulSubState = 5;
        }
        
        break;
    case 2:
        lResult = CheckMemoryCardExistFileList(pLoad->pMcState, cpNameList, 18);
        
        if (lResult < 0)
        {
            pLoad->ulSubState = 6;
            
            SetCheckMcFlag(pLoad->pMcState, 0);
            
            RecoveryMemoryCardError(pLoad->pMcState);
        }
        else if (lResult == 1)
        {
            pLoad->ulSubState = 3;
        }
        
        break;
    case 3:
        lResult = mcReadStartSaveFile(pLoad->pSaveFile, pLoad->pMcState, cpNameList, pLoad->usLoopCount);
        
        if (lResult == 1)
        {
            pLoad->ulSubState = 4;
        }
        
        break;
    case 4:
        lResult = mcCheckReadStartSaveFile(pLoad->pSaveFile, pLoad->pMcState, 0);
        
        if (lResult == 1)
        {
            mcGetPortSelectDirInfo(pLoad->pSaveFile, pLoad->pSelectFileWindow, pLoad->usLoopCount);
            
            if (++pLoad->usLoopCount > 14)
            {
                SetStateLoadScreenSelectFile(pLoad);
            }
            else
            {
                pLoad->ulSubState = 3;
            }
        }
        else if (lResult <= -1)
        {
            pLoad->ulSubState = 6;
            
            SetCheckMcFlag(pLoad->pMcState, 0);
            
            RecoveryMemoryCardError(pLoad->pMcState);
        }
        
        break;
    case 5:
        if (pLoad->lCardState == 100)
        {
            SetStateLoadScreenErrLostDirCheck(pLoad);
        }
        
        break;
    case 6:
        if (pLoad->lCardState == 100)
        {
            SetStateLoadScreenDirFileBroken(pLoad);
        }
        
        break;
    }
    
    if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104))
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
}

// 100% matching! 
void SetStateLoadScreenDirFileBroken(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 15;
    
    pLoad->cMesFlag = 9;
    pLoad->cCgFlag = 100;
}

// 100% matching! 
void ExecuteStateLoadScreenDirFileBroken(LOAD_SCREEN* pLoad)
{
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
        
        CallSystemSe(0, 3);
    }
    else if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
}

// 100% matching! 
void SetStateLoadScreenSelectFile(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 20;
    
    pLoad->cMesFlag = 100;
    pLoad->cCgFlag = 1;

    pLoad->usLoopCount = 0;
    
    pLoad->sCursorY = GetMemoryCardFileNumber(pLoad->pMcState);

    pLoad->sSelectCur = 0;
    
    SetCheckMcFlag(pLoad->pMcState, 0);
}

// 99.48% matching
void ExecuteStateLoadScreenSelectFile(LOAD_SCREEN* pLoad)
{
    static unsigned int KeyWait00;
	static unsigned int KeyWait01;

    if (!(sys->pad_ps & 0x1800)) 
    {
        if ((sys->pad_on & 0xF)) 
        {
            if (KeyWait00 > 4) 
            {
                KeyWait01++;
            } 
            else
            {
                KeyWait00++;
            }
        }
        else
        {
            KeyWait00 = 0;
            KeyWait01 = 0;
        }
        
        if ((KeyWait01 >= 3) || (KeyWait00 == 1)) 
        {
            KeyWait01 = 0;
            
            if ((sys->pad_on & 0x1))
            {
                pLoad->sCursorY--;
                
                mcSetFileSelectWindowCursol(pLoad->pSelectFileWindow, -1);
                
                CallSystemSe(0, 2);
                
                if (pLoad->sCursorY < 0) 
                {
                    pLoad->sCursorY = 14;
                    
                    mcSetFileSelectWindowCursol(pLoad->pSelectFileWindow, 4);
                } 
                else if (mcGetFileSelectWindowCursol(pLoad->pSelectFileWindow) < 0) 
                {
                    mcSetFileSelectWindowCursol(pLoad->pSelectFileWindow, 0);
                }
                
                mcMoveFileSelectWindowCursor(pLoad->pSelectFileWindow, -1);
            } 
            else if ((sys->pad_on & 0x2)) 
            {
                pLoad->sCursorY++;
                
                mcSetFileSelectWindowCursol(pLoad->pSelectFileWindow, 1);
                
                CallSystemSe(0, 2);
                
                if (pLoad->sCursorY > 14) 
                {
                    pLoad->sCursorY = 0;
                    
                    mcSetFileSelectWindowCursol(pLoad->pSelectFileWindow, 0);
                } 
                else if (mcGetFileSelectWindowCursol(pLoad->pSelectFileWindow) > 4) 
                {
                    mcSetFileSelectWindowCursol(pLoad->pSelectFileWindow, 4);
                }
                
                mcMoveFileSelectWindowCursor(pLoad->pSelectFileWindow, 1);
            }
        }
    } 
    else if ((sys->pad_ps & 0x800)) 
    {
        LoadScreenCheckSave(pLoad);
    } 
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateLoadScreenSelectCard(pLoad);
        
        CallSystemSe(0, 0);
    }
    
    if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
    
    if (++pLoad->ulMemCheckCountTimer == 60) 
    {
        pLoad->ulMemCheckCountTimer = 0;
    }
    
    if ((pLoad->ulMemCheckCountTimer % 30) < 20) 
    {
        DispUpDownCursol(320.0f, 90.0f, 0);
        DispUpDownCursol(320.0f, 90.0f, 1);
    }
}

// 100% matching! 
void LoadScreenCheckSave(LOAD_SCREEN* pLoad)
{
    SetMemoryCardFileNumber(pLoad->pMcState, pLoad->sCursorY);
    
    if (mcSelectSaveFileCheck(pLoad->pSelectFileWindow, pLoad->sCursorY) == 0) 
    {
        SetStateLoadScreenLoadCursor(pLoad);
        
        CallSystemSe(0, 3);
    }
    else 
    {
        SetStateLoadScreenNoSave(pLoad);
        
        CallSystemSe(0, 1);
    }
}

// 100% matching! 
void SetStateLoadScreenNoSave(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 21;
    
    pLoad->cMesFlag = 6;
    pLoad->cCgFlag = 100;
}

// 100% matching! 
void ExecuteStateLoadScreenNoSave(LOAD_SCREEN* pLoad)
{
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateLoadScreenSelectFile(pLoad);
        
        CallSystemSe(0, 3);
    }
    else if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
}

// 100% matching! 
void SetStateLoadScreenLoadCursor(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 30;
    
    pLoad->cMesFlag = 7;
    pLoad->cCgFlag = 2;
    
    pLoad->sSelectCur = 0;
}

// 100% matching! 
void ExecuteStateLoadScreenLoadCursor(LOAD_SCREEN* pLoad)
{
    if ((sys->pad_ps & 0x1)) 
    {
        pLoad->sSelectCur--;

        pLoad->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x2))
    {
        pLoad->sSelectCur++;
        
        pLoad->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x800)) 
    {
        if (pLoad->sSelectCur == 1) 
        {
            SetStateLoadScreenSelectFile(pLoad);
            
            CallSystemSe(0, 3);
        } 
        else 
        {
            SetStateLoadScreenLoad(pLoad);
            
            CallSystemSe(0, 3);
        }
    }
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateLoadScreenSelectFile(pLoad);
        
        CallSystemSe(0, 0);
    }
    else if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
}

// 100% matching! 
void SetStateLoadScreenLoad(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 31;
    pLoad->ulSubState = 0;
    
    pLoad->cMesFlag = 8;
    pLoad->cCgFlag = 1;
    
    SetCheckMcFlag(pLoad->pMcState, 1);
}

// 100% matching!
void ExecuteStateLoadScreenLoad(LOAD_SCREEN* pLoad)
{
    int lResult;
    int lFileNumber;

    switch (pLoad->ulSubState) 
    {
    case 0:
        lFileNumber = GetMemoryCardFileNumber(pLoad->pMcState);
        
        lResult = mcReadStartSaveFile(pLoad->pSaveFile, pLoad->pMcState, cpNameList, lFileNumber);
        
        if (lResult == 1) 
        {
            pLoad->ulSubState = 1;
        }
        
        break;
    case 1:
        lResult = mcCheckReadStartSaveFile(pLoad->pSaveFile, pLoad->pMcState, 1);
        
        if (lResult == 1) 
        {
            SetStateLoadScreenLoadExit(pLoad);
        } 
        else if (lResult == -1)
        {
            SetCheckMcFlag(pLoad->pMcState, 0);
            
            RecoveryMemoryCardError(pLoad->pMcState);
            
            pLoad->ulSubState = 3;
        }
        else if (lResult == -2)
        {
            SetCheckMcFlag(pLoad->pMcState, 0);
            
            RecoveryMemoryCardError(pLoad->pMcState);
            
            pLoad->ulSubState = 2;
        }
        
        break;
    case 2:
        if (pLoad->lCardState != 100)
        {
            break;
        }
        
        SetStateLoadScreenFileBroken(pLoad);
        break;
    case 3:
        if (pLoad->lCardState == 100) 
        {
            SetStateLoadScreenErrCardRead(pLoad);
        }
        
        break;
    }
}

// 100% matching!
void SetStateLoadScreenFileBroken(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 32;
    
    pLoad->cMesFlag = 9;
    pLoad->cCgFlag = 100;
}

// 100% matching!
void ExecuteStateLoadScreenFileBroken(LOAD_SCREEN* pLoad)
{
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
        
        CallSystemSe(0, 3);
    }
    else if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
}

// 100% matching!
void SetStateLoadScreenErrCardRead(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 33;
    
    pLoad->cMesFlag = 10;
    pLoad->cCgFlag = 100;
}

// 100% matching!
void ExecuteStateLoadScreenErrCardRead(LOAD_SCREEN* pLoad)
{
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
        
        CallSystemSe(0, 3);
    }
    else if ((pLoad->lCardState > 100) && (pLoad->lCardState < 104)) 
    {
        SetStateLoadScreenAwarenessCard(pLoad);
    }
}

// 100% matching!
void SetStateLoadScreenLoadExit(LOAD_SCREEN* pLoad)
{
    pLoad->ulState = 34;
    
    pLoad->cMesFlag = 100;
    pLoad->cCgFlag = 100;
    
    pLoad->ulMemCheckCountTimer = 1;
    
    SetCheckMcFlag(pLoad->pMcState, 0);
}

// 100% matching!
void ExecuteStateLoadScreenLoadExit(LOAD_SCREEN* pLoad)
{
    if (--pLoad->ulMemCheckCountTimer == 0) 
    {
        SetCheckMcFlag(pLoad->pMcState, 0);
        
        sys->typ_flg |= 0x10;
        
        pLoad->usExitFlag = 1;
    }
}

// 98.37% matching
void SetDispLoadSelectMessage()
{
    bhFontScaleSet(0.71f, 0.71f, 0.75f);
    
    bhDispMessage(96.0f, 82.0f, -1.0f, 1, 452, 0, 0);
    bhDispMessage(90.0f, 136.0f, -1.0f, 1, 463, 0, 0);
    bhDispMessage(153.0f, 158.0f, -1.0f, 1, 464, 0, 0);
    bhDispMessage(360.0f, 136.0f, -1.0f, 1, 463, 0, 0);
    bhDispMessage(423.0f, 158.0f, -1.0f, 1, 465, 0, 0);
    bhDispMessage(90.0f, 395.0f, -1.0f, 1, 453, 0, 0);
    
    bhFontScaleSet(1.0f, 1.0f, 1.0f);
}

// 100% matching!
void CheckDispLoadMemoryCard(LOAD_SCREEN* pLoad)
{
    int lPort0Card, lPort1Card;
    int lPort0CurX, lPort1CurX; 
    int lPort0CurY, lPort1CurY; // not from the debugging symbols
    short temp; // not from the debugging symbols
    
    lPort0Card = GetMemoryCardSelectPortState(pLoad->pMcState, 0); 
    lPort1Card = GetMemoryCardSelectPortState(pLoad->pMcState, 1);
    
    lPort0CurY = 2;
    
    if ((lPort0Card == 2) && (lPort1Card == 2)) 
    {
        temp = pLoad->sCursorX;
        
        lPort1CurY = 2;
        
        pLoad->sSelectCur = temp;
        
        lPort0CurX = temp ^ 1;
        lPort1CurX = temp & 1;
    } 
    else
    {
        lPort0CurY = 2;
        lPort1CurY = 2;
        
        if ((lPort0Card == 2) && (lPort1Card != 2))
        {
            pLoad->sCursorX = 0;
            
            lPort0CurX = 1;
            
            pLoad->sSelectCur = 0;
            
            lPort1CurY = 0;
            lPort1CurX = 0;
        } 
        else if ((lPort0Card != 2) && (lPort1Card == 2)) 
        {
            lPort0CurY = 0;
            lPort0CurX = 0;
            
            pLoad->sCursorX = 1;
            
            lPort1CurX = 1;
            lPort1CurY = 2;
            
            pLoad->sSelectCur = 1;
        }
        else 
        {
            pLoad->sSelectCur = 0;
            
            lPort0CurY = 0;
            lPort1CurY = 0;
            
            lPort0CurX = 0;
            lPort1CurX = 0;
            
            pLoad->sCursorY = 1;
        }
    }
    
    if (pLoad->sCursorY == 1) 
    {
        pLoad->sSelectCur = 0;
        
        pLoad->sCursorX = 0;
        
        lPort0CurX = 0;
        lPort1CurX = 0;
    }
    
    DispMemoryCardTexture(128.0f, 200.0f, lPort0CurX, lPort0CurY);
    DispMemoryCardTexture(400.0f, 200.0f, lPort1CurX, lPort1CurY);
    
    DispCursolTexture(70.0f + (268.0f * pLoad->sSelectCur), 129.0f + (258.0f * pLoad->sCursorY), 0xFF808080);
}
