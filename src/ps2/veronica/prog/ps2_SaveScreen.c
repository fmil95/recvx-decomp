#include "ps2_SaveScreen.h"
#include "flag.h"
#include "message.h"
#include "ps2_McSaveFile.h"
#include "ps2_MemoryCard.h"
#include "room.h"
#include "sdfunc.h"
#include "main.h"

/*char cIconSys[9];
char cBioCvIco[11];
char cSysData[13];
char cSaveData00[12];
char cSaveData01[12];
char cSaveData02[12];
char cSaveData03[12];
char cSaveData04[12];
char cSaveData05[12];
char cSaveData06[12];
char cSaveData07[12];
char cSaveData08[12];
char cSaveData09[12];
char cSaveData10[12];
char cSaveData11[12];
char cSaveData12[12];
char cSaveData13[12];
char cSaveData14[12];
char* cpNameList[18];
tagSELECTFILEWINDOW SelectFileWindow;
tagSELECTFILEINFO SelectFileInfo[15];
tagICONINFORMATION IconInfo;
tagMEMORYCARDSTATE McState;
tagSAVEFILE SaveFile;
tagCONFIGFILE ConfigFile;
_anon11* sys;*/

// 100% matching! 
SAVE_SCREEN* CreateSaveScreen(SAVE_SCREEN* pSave, void* vpWorkPtrSys) 
{
    pSave->ulState = 0;
    pSave->ulSubState = 0;
    
    pSave->ulMemCheckCountTimer = 0;
    
    pSave->ulFileSize = 0;
    
    pSave->lCardState = 0;
    
    pSave->sCursorX = 0;
    pSave->sCursorY = 0;
    
    pSave->sSelectCur = 0;
    
    pSave->usExitFlag = 0;
    
    pSave->usSaveEnd = 0;
    
    pSave->usLoopCount = 0;
    
    pSave->cMesFlag = 0;
    pSave->cCgFlag = 0;
    
    pSave->pConfigFile = mcCreateConfigInit(&ConfigFile);
    pSave->pSaveFile = mcCreateSaveFileInit(&SaveFile);
    
    pSave->pMcState = CreateMemoryCard(&McState);
    
    pSave->pIconInfo = mcCreateIconInit(&IconInfo, cpNameList, 1);
    
    pSave->pSelectFileInfo = mcSelectFileInfoInit(SelectFileInfo);
    pSave->pSelectFileWindow = mcCreateFileSelectWindow(&SelectFileWindow, pSave->pSelectFileInfo, 15);
    
    pSave->vpReadBuffer = vpWorkPtrSys;
    
    CheckMemoryCardChangeConnectTypeAll(pSave->pMcState);
    
    return pSave;
}

// 96.80% matching
void DispMessageSelect(char cSelectMes)
{
    bhFontScaleSet(0.71f, 0.71f, 0.75f);

    switch (cSelectMes) 
    {
    case 0:
        SetDispSelectMessage();
        break;
    case 1:
    case 2:
        bhDispMessage(90.0f, 194.0f, -0.1f, 1, 475, 3, 0);
        
        SetDispSelectMessage();
        break;
    case 3:
        bhDispMessage(90.0f, 194.0f, -0.1f, 1, 471, 0, 0);
        break;
    case 4:
        bhDispMessage(90.0f, 194.0f, -0.1f, 1, 476, 3, 0);
        break;
    case 5:
        bhDispMessage(90.0f, 120.0f, -0.1f, 1, 477, 0, 0);
        bhDispMessage(290.0f, 280.0f, -0.1f, 1, 466, 0, 0);
        break;
    case 6:
        bhDispMessage(90.0f, 194.0f, -0.1f, 1, 478, 0, 0);
        break;
    case 7:
        bhDispMessage(206.0f, 224.0f, -0.1f, 1, 480, 3, 0);
        break;
    case 8:
        bhDispMessage(240.0f, 311.0f, -0.1f, 1, 253, 3, 0);
        bhDispMessage(290.0f, 360.0f, -0.1f, 1, 466, 3, 0);
        break;
    case 9:
        bhDispMessage(240.0f, 224.0f, -0.1f, 1, 461, 3, 0);
        break;
    case 10:
        bhDispMessage(240.0f, 311.0f, -0.1f, 1, 483, 0, 0);
        bhDispMessage(290.0f, 360.0f, -0.1f, 1, 466, 0, 0);
        break;
    case 11:
        bhDispMessage(210.0f, 311.0f, -0.1f, 1, 482, 0, 0);
        bhDispMessage(290.0f, 360.0f, -0.1f, 1, 466, 0, 0);
        break;
    case 12:
        bhDispMessage(90.0f, 311.0f, -0.1f, 1, 484, 0, 0);
        break;
    case 13:
        bhDispMessage(236.0f, 311.0f, -0.1f, 1, 485, 0, 0);
        break;
    case 14:
        bhDispMessage(226.0f, 224.0f, -0.1f, 1, 486, 3, 0);
        break;
    case 15:
        bhDispMessage(90.0f, 120.0f, -0.1f, 1, 487, 0, 0);
        bhDispMessage(290.0f, 204.0f, -0.1f, 1, 466, 0, 0);
        break;
    case 16:
        bhDispMessage(90.0f, 180.0f, -0.1f, 1, 488, 0, 0);
        break;
    case 17:
        bhDispMessage(200.0f, 180.0f, -0.1f, 1, 481, 0, 0);
        bhDispMessage(290.0f, 227.0f, -0.1f, 1, 466, 0, 0);
        break;
    case 18:
        bhDispMessage(230.0f, 224.0f, -0.1f, 1, 489, 0, 0);
        break;
    case 19:
        bhDispMessage(208.0f, 224.0f, -0.1f, 1, 490, 3, 0);
        break;
    case 20:
        bhDispMessage(180.0f, 224.0f, -0.1f, 1, 479, 0, 0);
        break;
    }
    
    bhFontScaleSet(1.0f, 1.0f, 1.0f);
}

// 98.95% matching
void DispTexture(SAVE_SCREEN* pSave)
{
    int DispSavePortCard;
    
    switch (pSave->cCgFlag) 
    {
    case 0:
        CheckDispMemoryCard(pSave);
        break;
    case 1:
        DispUpDownCursol(254.0f, 279.0f, pSave->sSelectCur + 2);
        break;
    case 2:
        DispUpDownCursol(256.0f, 359.0f, pSave->sSelectCur + 2);
        break;
    case 3:
        DispSavePortCard = GetMemoryCardCurrentPort(pSave->pMcState);
        
        mcDisplayFileSelectWindow(pSave->pSelectFileWindow, 60.0f, 108.0f, DispSavePortCard);
        
        DispUpDownCursol(256.0f, 359.0f, pSave->sSelectCur + 2);
        break;
    case 4:
        DispSavePortCard = GetMemoryCardCurrentPort(pSave->pMcState);
        
        mcDisplayFileSelectWindow(pSave->pSelectFileWindow, 60.0f, 108.f, DispSavePortCard);
        break;
    case 5:
        DispUpDownCursol(254.0f, 205.0f, pSave->sSelectCur + 2);
        break;
    case 6:
        DispUpDownCursol(254.0f, 227.0f, pSave->sSelectCur + 2);
        break;
    }
}

// 100% matching! 
int ExecuteSaveScreen(SAVE_SCREEN* pSave) 
{
    pSave->lCardState = ExecuteMemoryCard(pSave->pMcState);
    
    DispBackGroundTexture();
    
    switch (pSave->ulState) 
    {                           
    case 0:
        ExecuteStateSaveScreenAwarenessCard(pSave);
        break;
    case 1:
        ExecuteStateSaveScreenErrLostCard(pSave);
        break;
    case 2:
        ExecuteStateSaveScreenErrUnPS2MemCard(pSave);
        break;
    case 10:
        ExecuteStateSaveScreenSelectCard(pSave);
        break;
    case 11:
        ExecuteStateSaveScreenExit(pSave);
        break;
    case 12:
        ExecuteStateSaveScreenLostDirCheck(pSave);
        break;
    case 13:
        ExecuteStateSaveScreenFreeCapacity(pSave);
        break;
    case 14:
        ExecuteStateSaveScreenErrFreeCapacity(pSave);
        break;
    case 15:
        ExecuteStateSaveScreenCreateSaveFileCheck(pSave);
        break;
    case 16:
        ExecuteStateSaveScreenCreateSaveFile(pSave);
        break;
    case 17:
        ExecuteStateSaveScreenErrCreateSaveFile(pSave);
        break;
    case 18:
        ExecuteStateSaveScreenSpecialSave(pSave);
        break;
    case 20:
        ExecuteStateSaveScreenSelectFile(pSave);
        break;
    case 21:
        ExecuteStateSaveScreenErrDer(pSave);
        break;
    case 30:
        ExecuteStateSaveScreenSaveCursor(pSave);
        break;
    case 31:
        ExecuteStateSaveScreenSaveCursorOld(pSave);
        break;
    case 32:
        ExecuteStateSaveScreenSaveCursorNew(pSave);
        break;
    case 33:
        ExecuteStateSaveScreenSave(pSave);
        break;
    case 35:
        ExecuteStateSaveScreenSuccessCardWrite(pSave);
        break;
    case 36:
        ExecuteStateSaveScreenSuccessCardWriteMessage(pSave);
        break;
    case 37:
        ExecuteStateSaveScreenErrCardWrite(pSave);
        break;
    case 40:
        ExecuteStateSaveScreenFormat(pSave);
        break;
    case 41:
        ExecuteStateSaveScreenStartFormat(pSave);
        break;
    case 42:
        ExecuteStateSaveScreenExitFormat(pSave);
        break;
    case 43:
        ExecuteStateSaveScreenSuccessFormat(pSave);
        break;
    case 44:
        ExecuteStateSaveScreenErrFormat(pSave);
        break;
    }
    
    DispTexture(pSave);
    DispMessageSelect(pSave->cMesFlag);
    
    return 0;
}

// 100% matching! 
void SetStateSaveScreenAwarenessCard(SAVE_SCREEN* pSave) 
{
    pSave->ulState = 0;
    pSave->ulSubState = 0;
    
    pSave->usLoopCount = 0;
    
    SetCheckMcFlag(pSave->pMcState, 0);
}

// 100% matching! 
void ExecuteStateSaveScreenAwarenessCard(SAVE_SCREEN* pSave)
{
	int lPort0State;
    int lPort1State;
    
    switch (pSave->lCardState)
    {                              
    case 100:
        lPort0State = GetMemoryCardSelectPortState(pSave->pMcState, 0);
        lPort1State = GetMemoryCardSelectPortState(pSave->pMcState, 1);
        
        if ((lPort0State == 2) || (lPort1State == 2))
        {                     
            SetStateSaveScreenSelectCard(pSave);
        }
        else if (((lPort0State != 2) && (lPort0State != 0)) || ((lPort1State != 2) && (lPort1State != 0))) 
        {
            SetStateSaveScreenErrUnPS2MemCard(pSave);
        }
        else 
        {
            SetStateSaveScreenErrLostCard(pSave);
        }
                
        break;
    case 101:
        SetStateSaveScreenSelectCard(pSave);
        break;
    case 102:
        SetStateSaveScreenErrUnPS2MemCard(pSave);
        break;
    case 103:
        SetStateSaveScreenErrLostCard(pSave);
        break;
    }
}

// 100% matching! 
void SetStateSaveScreenErrLostCard(SAVE_SCREEN* pSave)
{
    pSave->ulState = 1;
    
    pSave->cMesFlag = 1;
    pSave->cCgFlag = 0;
}

// 100% matching! 
void ExecuteStateSaveScreenErrLostCard(SAVE_SCREEN* pSave) 
{
    int lPort0State;
    int lPort1State;
    
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateSaveScreenExit(pSave);
        
        CallSystemSe(0, 3);
        return;
    }
    
    switch (pSave->lCardState) 
    {
    case 100:
        lPort0State = GetMemoryCardSelectPortState(pSave->pMcState, 0);
        lPort1State = GetMemoryCardSelectPortState(pSave->pMcState, 1);
        
        if ((lPort0State == 2) || (lPort1State == 2))
        {                     
            SetStateSaveScreenSelectCard(pSave);
        }
        else if (((lPort0State != 2) && (lPort0State != 0)) || ((lPort1State != 2) && (lPort1State != 0))) 
        {
            SetStateSaveScreenErrUnPS2MemCard(pSave);
        }
                
        break;
    case 101:
        SetStateSaveScreenAwarenessCard(pSave);
        break;
    case 102:
        SetStateSaveScreenErrUnPS2MemCard(pSave);
        break;
    }
}

// 100% matching! 
void SetStateSaveScreenErrUnPS2MemCard(SAVE_SCREEN* pSave)
{
    pSave->ulState = 2;
    
    pSave->cMesFlag = 2;
    pSave->cCgFlag = 0;
}

// 100% matching! 
void ExecuteStateSaveScreenErrUnPS2MemCard(SAVE_SCREEN* pSave) 
{
    int lPort0State;
    int lPort1State;
 
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateSaveScreenExit(pSave);
        
        CallSystemSe(0, 3);
        return;
    }
    
    switch (pSave->lCardState) 
    {
    case 100:  
        lPort0State = GetMemoryCardSelectPortState(pSave->pMcState, 0);
        lPort1State = GetMemoryCardSelectPortState(pSave->pMcState, 1);

        if ((lPort0State == 2) || (lPort1State == 2)) 
        {
            SetStateSaveScreenSelectCard(pSave);
        } 
        else if ((lPort0State == 0) && (lPort1State == 0))
        {
            SetStateSaveScreenErrLostCard(pSave);
        }
        
        break;
    case 101:  
        SetStateSaveScreenAwarenessCard(pSave);
        break;
    case 103:  
        SetStateSaveScreenErrLostCard(pSave);
        break;
    }
}

// 100% matching! 
void SetStateSaveScreenSelectCard(SAVE_SCREEN* pSave)
{
    pSave->ulState = 10;
    
    pSave->cMesFlag = 0;
    pSave->cCgFlag = 0;
    
    pSave->sCursorY = 0;
    
    pSave->sSelectCur = 0;
    
    mcSetFileSelectWindowCursolInit(pSave->pSelectFileWindow);
    
    SetCheckMcFlag(pSave->pMcState, 0);
}

// 100% matching! 
void ExecuteStateSaveScreenSelectCard(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1)) 
    {
        pSave->sCursorY--;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x2))
    {
        pSave->sCursorY++;
        
        CallSystemSe(0, 2);
    }
    
    pSave->sCursorY &= 0x1;
    
    if ((pSave->sCursorY == 0) && ((GetMemoryCardSelectPortState(pSave->pMcState, 0) == 2) && (GetMemoryCardSelectPortState(pSave->pMcState, 1) == 2)))
    {
        if ((sys->pad_ps & 0x4)) 
        {
            pSave->sCursorX--;
            
            CallSystemSe(0, 2);
        }
        else if ((sys->pad_ps & 0x8)) 
        {
            pSave->sCursorX++;
            
            CallSystemSe(0, 2);
        }
        
        pSave->sCursorX &= 0x1;
        
        pSave->sSelectCur = pSave->sCursorX;
    }
    
    if ((sys->pad_ps & 0x800)) 
    {
        if (pSave->sCursorY == 1) 
        {
            SetStateSaveScreenExit(pSave);
        } 
        else 
        {
            SetStateSaveScreenLostDirCheck(pSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateSaveScreenExit(pSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching! 
void SetStateSaveScreenExit(SAVE_SCREEN* pSave)
{
    pSave->ulState = 11;
    
    pSave->cMesFlag = 100;
    pSave->cCgFlag = 100;
    
    pSave->ulMemCheckCountTimer = 1;
    
    SetCheckMcFlag(pSave->pMcState, 0);
}

// 100% matching! 
void ExecuteStateSaveScreenExit(SAVE_SCREEN* pSave)
{
    if (bhCkFlg(sys->ev_flg, 56) == 0) 
    {
        if (--pSave->ulMemCheckCountTimer == 0) 
        {
            pSave->usExitFlag = 1;
        }
    }
    else
    {
        SetSaveScreenSpecialSave(pSave);
    }
}

// 100% matching! 
void SetSaveScreenSpecialSave(SAVE_SCREEN* pSave)
{
    pSave->ulState = 18;
    
    pSave->cMesFlag = 8;
    pSave->cCgFlag = 2;
    
    pSave->sSelectCur = 1;
}

// 100% matching! 
void ExecuteStateSaveScreenSpecialSave(SAVE_SCREEN* pSave) 
{
    if ((sys->pad_ps & 0x1)) 
    {
        pSave->sSelectCur--;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x2)) 
    {
        pSave->sSelectCur++;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x800))
    {
        if (pSave->sSelectCur == 1)
        {
            SetStateSaveScreenAwarenessCard(pSave);
        } 
        else
        {
            pSave->usExitFlag = 1;
        }
        
        CallSystemSe(0, 3);
    }
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching! 
void SetStateSaveScreenLostDirCheck(SAVE_SCREEN* pSave)
{
    pSave->ulState = 12;
    
    pSave->cMesFlag = 3;
    pSave->cCgFlag = 100;
    
    pSave->ulSubState = 0;
    
    pSave->usLoopCount = 0;
    
    pSave->ulMemCheckCountTimer = 10;
    
    SetMemoryCardFileNumber(pSave->pMcState, 0);
    SetMemoryCardCurrentPort(pSave->pMcState, pSave->sCursorX);
    
    SetCheckMcFlag(pSave->pMcState, 1);
}

// 100% matching! 
void ExecuteStateSaveScreenLostDirCheck(SAVE_SCREEN* pSave)
{
    int lResult;
    
    switch (pSave->ulSubState)
    {
    case 0:
        lResult = CheckMemoryCardFormatStatus(pSave->pMcState);
        
        if (lResult == 1)
        {
            if (--pSave->ulMemCheckCountTimer == 0)
            {
                SetStateSaveScreenFormat(pSave);
                return;
            }
        }
        else if (lResult == 2)
        {
            pSave->ulSubState = 1;
        }
        else if (lResult == -1)
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
            
            pSave->ulSubState = 6;
        }
        
        break;
    case 1:
        lResult = CheckMemoryCardExistSubDirectory(pSave->pMcState);
        
        if (lResult == 1)
        {
            pSave->ulSubState = 2;
        }
        else if (lResult == -1)
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            pSave->ulSubState = 5;
        }
        
        break;
    case 2:
        lResult = CheckMemoryCardExistFileList(pSave->pMcState, cpNameList, 18);
        
        if (lResult < 0)
        {
            pSave->ulSubState = 6;
            
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
        }
        else if (lResult == 1)
        {
            pSave->ulSubState = 3;
        }
        
        break;
    case 3:
        lResult = mcReadStartSaveFile(pSave->pSaveFile, pSave->pMcState, cpNameList, pSave->usLoopCount);
        
        if (lResult == 1)
        {
            pSave->ulSubState = 4;
        }
        
        break;
    case 4:
        lResult = mcCheckReadStartSaveFile(pSave->pSaveFile, pSave->pMcState, 0);
        
        if (lResult == 1)
        {
            mcGetPortSelectDirInfo(pSave->pSaveFile, pSave->pSelectFileWindow, pSave->usLoopCount);
            
            if (++pSave->usLoopCount > 14)
            {
                SetStateSaveScreenSelectFile(pSave);
            }
            else
            {
                pSave->ulSubState = 3;
            }
        }
        else if (lResult <= -1)
        {
            pSave->ulSubState = 6;
            
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
        }
        
        break;
    case 5:
        if (pSave->lCardState == 100)
        {
            SetStateSaveScreenFreeCapacity(pSave);
        }
        
        break;
    case 6:
        if (pSave->lCardState == 100)
        {
            SetStateSaveScreenErrDer(pSave);
        }
        
        break;
    }
    
    if ((pSave->lCardState > 100) && (pSave->lCardState < 104))
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching! 
void SetStateSaveScreenFreeCapacity(SAVE_SCREEN* pSave)
{
    pSave->ulState = 13;
    
    pSave->cMesFlag = 3;
    pSave->cCgFlag = 100;
}

// 100% matching! 
void ExecuteStateSaveScreenFreeCapacity(SAVE_SCREEN* pSave)
{
    int lResult;

    lResult = GetMemoryCardFreeCapacity(pSave->pMcState);
    
    if (lResult < mcGetFreeCapacitySize()) 
    {
        if (lResult == -1) 
        {
            SetStateSaveScreenAwarenessCard(pSave);
        }
        
        if (lResult != -2) 
        {
            SetStateSaveScreenErrFreeCapacity(pSave);
        }
    }
    else
    {
        SetStateSaveScreenCreateSaveFileCheck(pSave);
    }
}

// 100% matching! 
void SetStateSaveScreenErrFreeCapacity(SAVE_SCREEN* pSave)
{
    pSave->ulState = 14;
    
    pSave->cMesFlag = 4;
    pSave->cCgFlag = 100;
}

// 100% matching! 
void ExecuteStateSaveScreenErrFreeCapacity(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1800))
    {
        SetStateSaveScreenAwarenessCard(pSave);
        
        CallSystemSe(0, 3);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104))
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching! 
void SetStateSaveScreenCreateSaveFileCheck(SAVE_SCREEN* pSave)
{
    pSave->ulState = 15;
    
    pSave->cMesFlag = 5;
    pSave->cCgFlag = 1;
    
    pSave->sSelectCur = 1;
}

// 100% matching! 
void ExecuteStateSaveScreenCreateSaveFileCheck(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1)) 
    {
        pSave->sSelectCur--;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x2)) 
    {
        pSave->sSelectCur++;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x800)) 
    {
        if (pSave->sSelectCur == 1)
        {
            SetStateSaveScreenSelectCard(pSave);
        } 
        else 
        {
            SetStateSaveScreenCreateSaveFile(pSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((sys->pad_ps & 0x1000))
    {
        SetStateSaveScreenSelectCard(pSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104))
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching! 
void SetStateSaveScreenCreateSaveFile(SAVE_SCREEN* pSave)
{
    pSave->ulState = 16;
    pSave->ulSubState = 0;
    
    pSave->usLoopCount = 0;
    
    pSave->cMesFlag = 6;
    pSave->cCgFlag = 100;
    
    pSave->ulMemCheckCountTimer = 30;
    
    SetCheckMcFlag(pSave->pMcState, 1);
}

// 100% matching! 
void ExecuteStateSaveScreenCreateSaveFile(SAVE_SCREEN* pSave)
{
    int lResult;
    
    switch (pSave->ulSubState)
    {
    case 0:
        lResult = CreateMemoryCardSubDirectory(pSave->pMcState);
        
        if (lResult == -1) 
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
            
            pSave->ulSubState = 8;
        }
        else if (lResult == 1) 
        {
            lResult = mcNewCreateIcon(pSave->pIconInfo, pSave->pMcState, cpNameList, 0);
            
            if (lResult == 1)
            {
                pSave->ulSubState = 1;
            }
        }
        
        break;
    case 1: 
        lResult = RecoveryMemoryCardWriteEnd(pSave->pMcState);
        
        if (lResult == 1) 
        {
            pSave->ulSubState = 2;
        }
        else if (lResult == -1) 
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
            
            pSave->ulSubState = 8;
        }
        
        break;
    case 2: 
        lResult = mcReadIconData(pSave->vpReadBuffer, cpNameList, 1);
        
        pSave->ulFileSize = lResult;
        
        if (pSave->ulFileSize == 0) 
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
            
            pSave->ulSubState = 8;
            break;
        }
        
        lResult = mcWriteIconData(pSave->pMcState, pSave->vpReadBuffer, pSave->ulFileSize, cpNameList, 1);
        
        if (lResult == 1)
        {
            pSave->ulSubState = 3;
        }
        
        break;
    case 3: 
        lResult = RecoveryMemoryCardWriteEnd(pSave->pMcState);
        
        if (lResult == -1) 
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
            
            pSave->ulSubState = 8;
        }
        else if (lResult == 1)
        {
            lResult = mcNewCreateConfigFile(pSave->pMcState, pSave->pConfigFile);
            
            if (lResult == 1) 
            {
                pSave->ulSubState = 4;
            }
        }
        
        break;
    case 4: 
        lResult = RecoveryMemoryCardWriteEnd(pSave->pMcState);
        
        if (lResult == 1) 
        {
            pSave->ulSubState = 5;
        }
        else if (lResult == -1) 
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
            
            pSave->ulSubState = 8;
        }
        
        break;
    case 5: 
        lResult = mcNewCreateSaveFile(pSave->pMcState, pSave->pSaveFile, cpNameList, pSave->usLoopCount);
        
        if (lResult == 1) 
        {
            pSave->ulSubState = 6;
        }
        
        break;
    case 6: 
        lResult = RecoveryMemoryCardWriteEnd(pSave->pMcState);
        
        if (lResult == 1) 
        {
            if (++pSave->usLoopCount > 14)
            {
                pSave->ulSubState = 7;
                
                pSave->usLoopCount = 0;
                
                pSave->cMesFlag = 20;
                
                SetCheckMcFlag(pSave->pMcState, 0);
            } 
            else 
            {
                pSave->ulSubState = 5;
            }
        }
        else if (lResult == -1) 
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
            
            pSave->ulSubState = 8;
        }
        
        break;
    case 7: 
        if ((--pSave->ulMemCheckCountTimer == 0) && (pSave->lCardState == 100))
        {
            SetStateSaveScreenLostDirCheck(pSave);
        }
        
        break;
    case 8: 
        if (pSave->lCardState == 100) 
        {
            SetStateSaveScreenErrCreateSaveFile(pSave);
        }
        
        break;
    }
}

// 100% matching! 
void SetStateSaveScreenErrCreateSaveFile(SAVE_SCREEN* pSave)
{
    pSave->ulState = 17;
    
    pSave->cMesFlag = 7;
    pSave->cCgFlag = 100;
    
    pSave->ulSubState = 0;
    
    pSave->usLoopCount = 0;
}

// 100% matching! 
void ExecuteStateSaveScreenErrCreateSaveFile(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1800))
    {
        SetStateSaveScreenAwarenessCard(pSave);
        
        CallSystemSe(0, 3);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104))
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching! 
void SetStateSaveScreenSelectFile(SAVE_SCREEN* pSave)
{
    pSave->ulState = 20;
    
    pSave->cMesFlag = 100;
    pSave->cCgFlag = 4;
    
    pSave->usLoopCount = 0;
    
    pSave->ulMemCheckCountTimer = 0;
    
    pSave->sCursorY = GetMemoryCardFileNumber(pSave->pMcState);
    
    SetCheckMcFlag(pSave->pMcState, 0);
}

// 99.49% matching
void ExecuteStateSaveScreenSelectFile(SAVE_SCREEN* pSave)
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
                pSave->sCursorY--;
                
                mcSetFileSelectWindowCursol(pSave->pSelectFileWindow, -1);
                
                CallSystemSe(0, 2);
                
                if (pSave->sCursorY < 0) 
                {
                    pSave->sCursorY = 14;
                    
                    mcSetFileSelectWindowCursol(pSave->pSelectFileWindow, 4);
                } 
                else if (mcGetFileSelectWindowCursol(pSave->pSelectFileWindow) < 0) 
                {
                    mcSetFileSelectWindowCursol(pSave->pSelectFileWindow, 0);
                }
                
                mcMoveFileSelectWindowCursor(pSave->pSelectFileWindow, -1);
            } 
            else if ((sys->pad_on & 0x2)) 
            {
                pSave->sCursorY++;
                
                mcSetFileSelectWindowCursol(pSave->pSelectFileWindow, 1);
                
                CallSystemSe(0, 2);
                
                if (pSave->sCursorY > 14) 
                {
                    pSave->sCursorY = 0;
                    
                    mcSetFileSelectWindowCursol(pSave->pSelectFileWindow, 0);
                } 
                else if (mcGetFileSelectWindowCursol(pSave->pSelectFileWindow) > 4) 
                {
                    mcSetFileSelectWindowCursol(pSave->pSelectFileWindow, 4);
                }
                
                mcMoveFileSelectWindowCursor(pSave->pSelectFileWindow, 1);
            }
        }
    } 
    else if ((sys->pad_ps & 0x800)) 
    {
        SetStateSaveScreenSaveCursor(pSave);
        
        CallSystemSe(0, 3);
    } 
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateSaveScreenSelectCard(pSave);
        
        CallSystemSe(0, 0);
    }
    
    if ((pSave->lCardState > 100) && (pSave->lCardState < 104)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
    
    if (++pSave->ulMemCheckCountTimer == 60) 
    {
        pSave->ulMemCheckCountTimer = 0;
    }
    
    if ((pSave->ulMemCheckCountTimer % 30) < 20) 
    {
        DispUpDownCursol(320.0f, 90.0f, 0);
        DispUpDownCursol(320.0f, 90.0f, 1);
    }
}

// 100% matching! 
void SetStateSaveScreenSaveCursor(SAVE_SCREEN* pSave)
{
    SetMemoryCardFileNumber(pSave->pMcState, pSave->sCursorY);
    
    pSave->ulState = 30;
    
    pSave->cMesFlag = 100;
    pSave->cCgFlag = 4;
    
    pSave->sCursorY = 0;
}

// 100% matching! 
void ExecuteStateSaveScreenSaveCursor(SAVE_SCREEN* pSave)
{
    if (mcSelectSaveFileCheck(pSave->pSelectFileWindow, GetMemoryCardFileNumber(pSave->pMcState)) == 0)
    {
        SetStateSaveScreenSaveCursorOld(pSave);
    }
    else 
    {
        SetStateSaveScreenSaveCursorNew(pSave);
    }
}

// 100% matching! 
void SetStateSaveScreenSaveCursorOld(SAVE_SCREEN* pSave)
{
    pSave->ulState = 31;
    
    pSave->cMesFlag = 10;
    pSave->cCgFlag = 3;
    
    pSave->sSelectCur = 1;
}

// 100% matching! 
void ExecuteStateSaveScreenSaveCursorOld(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1)) 
    {
        pSave->sSelectCur--;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x2)) 
    {
        pSave->sSelectCur++;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x800))
    {
        if (pSave->sSelectCur == 1)
        {
            SetStateSaveScreenSelectFile(pSave);
        }
        else 
        {
            SetStateSaveScreenSave(pSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateSaveScreenSelectFile(pSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching! 
void SetStateSaveScreenSaveCursorNew(SAVE_SCREEN* pSave)
{
    pSave->ulState = 32;
    
    pSave->cMesFlag = 11;
    pSave->cCgFlag = 3;
    
    pSave->sSelectCur = 0;
}

// 100% matching!
void ExecuteStateSaveScreenSaveCursorNew(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1)) 
    {
        pSave->sSelectCur--;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x2)) 
    {
        pSave->sSelectCur++;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x800))
    {
        if (pSave->sSelectCur == 1)
        {
            SetStateSaveScreenSelectFile(pSave);
        } 
        else 
        {
            SetStateSaveScreenSave(pSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateSaveScreenSelectFile(pSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104))
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching!
void SetStateSaveScreenSave(SAVE_SCREEN* pSave)
{
    pSave->ulState = 33;
    pSave->ulSubState = 0;
    
    pSave->cMesFlag = 12;
    pSave->cCgFlag = 4;
    
    SetCheckMcFlag(pSave->pMcState, 1);
}

// 100% matching!
void ExecuteStateSaveScreenSave(SAVE_SCREEN* pSave)
{
    int lSaveResult;
    int lFileNumber;

    switch (pSave->ulSubState) 
    {
    case 0:
        lFileNumber = GetMemoryCardFileNumber(pSave->pMcState);
        
        lSaveResult = mcWriteStartSaveFile(pSave->pSaveFile, pSave->pMcState, cpNameList, lFileNumber);
        
        if (lSaveResult == 1) 
        {
            pSave->ulSubState = 1;
        }
        
        break;
    case 1:
        lSaveResult = mcCheckWriteStartSaveFile(pSave->pMcState);
        
        if (lSaveResult == 1) 
        {
            pSave->ulSubState = 2;
        } 
        else if (lSaveResult == -1)
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
            
            pSave->ulSubState = 3;
        }
        
        break;
    case 2:
        lFileNumber = GetMemoryCardFileNumber(pSave->pMcState);
        
        mcGetPortSelectDirInfo(pSave->pSaveFile, pSave->pSelectFileWindow, lFileNumber);
        
        SetStateSaveScreenSuccessCardWrite(pSave);
        break;
    case 3:
        if (pSave->lCardState == 100) 
        {
            SetStateSaveScreenErrCardWrite(pSave);
        }
        
        break;
    }
}

// 100% matching!
void SetStateSaveScreenSuccessCardWrite(SAVE_SCREEN* pSave)
{
    pSave->ulState = 35;
    
    pSave->cCgFlag = 4;
    
    pSave->usSaveEnd = 1;
    
    mcSetTyepWriteMode(pSave->pSelectFileWindow, 1);
}

// 100% matching!
void ExecuteStateSaveScreenSuccessCardWrite(SAVE_SCREEN* pSave)
{
    pSave->usSaveEnd = mcGetStringEnd(pSave->pSelectFileWindow, pSave->usSaveEnd);
    
    if (pSave->usSaveEnd == 0) 
    {
        bhPushGameData();
        
        SetStateSaveScreenSuccessCardWriteMessage(pSave);
    }
}

// 100% matching!
void SetStateSaveScreenSuccessCardWriteMessage(SAVE_SCREEN* pSave)
{
    pSave->ulState = 36;

    pSave->cMesFlag = 13;
    pSave->cCgFlag = 4;
    
    pSave->ulMemCheckCountTimer = 20;

    SetCheckMcFlag(pSave->pMcState, 0);
    
    mcSetTyepWriteMode(pSave->pSelectFileWindow, 0);
}

// 100% matching!
void ExecuteStateSaveScreenSuccessCardWriteMessage(SAVE_SCREEN* pSave)
{
    if (pSave->ulMemCheckCountTimer != 0) 
    {
        pSave->ulMemCheckCountTimer--;
    }
    else
    {
        SetStateSaveScreenExit(pSave);
    }
}

// 100% matching!
void SetStateSaveScreenErrCardWrite(SAVE_SCREEN* pSave)
{
    pSave->ulState = 37;

    pSave->cMesFlag = 14;
    pSave->cCgFlag = 100;
}

// 100% matching!
void ExecuteStateSaveScreenErrCardWrite(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1800))
    {
        SetStateSaveScreenAwarenessCard(pSave);
        
        CallSystemSe(0, 3);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching!
void SetStateSaveScreenFormat(SAVE_SCREEN* pSave)
{
    pSave->ulState = 40;

    pSave->cMesFlag = 15;
    pSave->cCgFlag = 5;
    
    pSave->sSelectCur = 1;
    
    SetCheckMcFlag(pSave->pMcState, 0);
}

// 100% matching!
void ExecuteStateSaveScreenFormat(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1)) 
    {
        pSave->sSelectCur--;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x2)) 
    {
        pSave->sSelectCur++;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x800))
    {
        if (pSave->sSelectCur == 1) 
        {
            SetStateSaveScreenExitFormat(pSave);
        } 
        else 
        {
            SetStateSaveScreenStartFormat(pSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateSaveScreenExitFormat(pSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching!
void SetStateSaveScreenStartFormat(SAVE_SCREEN* pSave)
{
    pSave->ulState = 41;
    pSave->ulSubState = 0;

    pSave->cMesFlag = 16;
    pSave->cCgFlag = 100;
    
    SetCheckMcFlag(pSave->pMcState, 1);
}

// 100% matching!
void ExecuteStateSaveScreenStartFormat(SAVE_SCREEN* pSave)
{
    int lFormatResult;

    switch (pSave->ulSubState) 
    {                              
    case 0:
        lFormatResult = FormatMemoryCard(pSave->pMcState);
        
        if (lFormatResult == 1)
        {
            pSave->ulSubState = 1;
        }
        
        break;
    case 1:
        lFormatResult = RecoveryMemoryCardFormatEnd(pSave->pMcState);
        
        if (lFormatResult == 1) 
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            pSave->ulSubState = 2;
        } 
        else if (lFormatResult == -1) 
        {
            SetCheckMcFlag(pSave->pMcState, 0);
            
            RecoveryMemoryCardError(pSave->pMcState);
            
            pSave->ulSubState = 3;
        }
        
        break;
    case 2:
        if (pSave->lCardState == 100)
        {
            SetStateSaveScreenSuccessFormat(pSave);
        }
        
        break;
    case 3:
        if (pSave->lCardState == 100) 
        {
            SetStateSaveScreenErrFormat(pSave);
        }
        
        break;
    }
}

// 100% matching!
void SetStateSaveScreenExitFormat(SAVE_SCREEN* pSave)
{
    pSave->ulState = 42;

    pSave->cMesFlag = 17;
    pSave->cCgFlag = 6;
    
    pSave->sSelectCur = 1;
}

// 100% matching!
void ExecuteStateSaveScreenExitFormat(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1)) 
    {
        pSave->sSelectCur--;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x2))
    {
        pSave->sSelectCur++;
        
        pSave->sSelectCur &= 0x1;
        
        CallSystemSe(0, 2);
    }
    else if ((sys->pad_ps & 0x800))
    {
        if (pSave->sSelectCur == 1) 
        {
            SetStateSaveScreenAwarenessCard(pSave);
        }
        else 
        {
            SetStateSaveScreenExit(pSave);
        }
        
        CallSystemSe(0, 3);
    }
    else if ((sys->pad_ps & 0x1000)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
        
        CallSystemSe(0, 0);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching!
void SetStateSaveScreenSuccessFormat(SAVE_SCREEN* pSave)
{
    pSave->ulState = 43;

    pSave->cMesFlag = 18;
    pSave->cCgFlag = 100;
    
    pSave->ulMemCheckCountTimer = 30;
}

// 100% matching!
void ExecuteStateSaveScreenSuccessFormat(SAVE_SCREEN* pSave)
{
    if (--pSave->ulMemCheckCountTimer == 0) 
    {
        SetStateSaveScreenLostDirCheck(pSave);
    }
}

// 100% matching!
void SetStateSaveScreenErrFormat(SAVE_SCREEN* pSave)
{
    pSave->ulState = 44;

    pSave->cMesFlag = 19;
    pSave->cCgFlag = 100;
    
    pSave->sSelectCur = 0;
}

// 100% matching!
void ExecuteStateSaveScreenErrFormat(SAVE_SCREEN* pSave)
{
    if (sys->pad_ps != 0) 
    {
        SetStateSaveScreenExitFormat(pSave);
        
        CallSystemSe(0, 3);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 100% matching!
void SetStateSaveScreenErrDer(SAVE_SCREEN* pSave)
{
    pSave->ulState = 21;

    pSave->cMesFlag = 9;
    pSave->cCgFlag = 100;
}

// 100% matching!
void ExecuteStateSaveScreenErrDer(SAVE_SCREEN* pSave)
{
    if ((sys->pad_ps & 0x1800)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
        
        CallSystemSe(0, 3);
    }
    else if ((pSave->lCardState > 100) && (pSave->lCardState < 104)) 
    {
        SetStateSaveScreenAwarenessCard(pSave);
    }
}

// 
// Start address: 0x271520
void SetDispSelectMessage()
{
	// Line 2870, Address: 0x271520, Func Offset: 0
	// Line 2858, Address: 0x27152c, Func Offset: 0xc
	// Line 2870, Address: 0x271530, Func Offset: 0x10
	// Line 2858, Address: 0x271538, Func Offset: 0x18
	// Line 2870, Address: 0x27153c, Func Offset: 0x1c
	// Line 2872, Address: 0x271544, Func Offset: 0x24
	// Line 2874, Address: 0x271574, Func Offset: 0x54
	// Line 2875, Address: 0x2715a4, Func Offset: 0x84
	// Line 2877, Address: 0x2715d4, Func Offset: 0xb4
	// Line 2878, Address: 0x271604, Func Offset: 0xe4
	// Line 2880, Address: 0x271638, Func Offset: 0x118
	// Line 2882, Address: 0x27166c, Func Offset: 0x14c
	// Line 2884, Address: 0x271684, Func Offset: 0x164
	// Func End, Address: 0x271690, Func Offset: 0x170
}

// 
// Start address: 0x271690
void CheckDispMemoryCard(SAVE_SCREEN* pSave)
{
	int lPort1CurX;
	int lPort0CurX;
	int lPort1Card;
	int lPort0Card;
	// Line 2899, Address: 0x271690, Func Offset: 0
	// Line 2904, Address: 0x2716a8, Func Offset: 0x18
	// Line 2905, Address: 0x2716b4, Func Offset: 0x24
	// Line 2908, Address: 0x2716c4, Func Offset: 0x34
	// Line 2912, Address: 0x2716d8, Func Offset: 0x48
	// Line 2911, Address: 0x2716dc, Func Offset: 0x4c
	// Line 2914, Address: 0x2716e0, Func Offset: 0x50
	// Line 2912, Address: 0x2716e4, Func Offset: 0x54
	// Line 2915, Address: 0x2716e8, Func Offset: 0x58
	// Line 2917, Address: 0x2716f0, Func Offset: 0x60
	// Line 2923, Address: 0x271704, Func Offset: 0x74
	// Line 2921, Address: 0x271708, Func Offset: 0x78
	// Line 2924, Address: 0x27170c, Func Offset: 0x7c
	// Line 2920, Address: 0x271710, Func Offset: 0x80
	// Line 2925, Address: 0x271714, Func Offset: 0x84
	// Line 2927, Address: 0x27171c, Func Offset: 0x8c
	// Line 2932, Address: 0x271730, Func Offset: 0xa0
	// Line 2933, Address: 0x271734, Func Offset: 0xa4
	// Line 2929, Address: 0x271738, Func Offset: 0xa8
	// Line 2931, Address: 0x27173c, Func Offset: 0xac
	// Line 2935, Address: 0x271740, Func Offset: 0xb0
	// Line 2944, Address: 0x271748, Func Offset: 0xb8
	// Line 2943, Address: 0x27174c, Func Offset: 0xbc
	// Line 2939, Address: 0x271750, Func Offset: 0xc0
	// Line 2940, Address: 0x271754, Func Offset: 0xc4
	// Line 2941, Address: 0x271758, Func Offset: 0xc8
	// Line 2942, Address: 0x27175c, Func Offset: 0xcc
	// Line 2944, Address: 0x271760, Func Offset: 0xd0
	// Line 2947, Address: 0x271764, Func Offset: 0xd4
	// Line 2949, Address: 0x271774, Func Offset: 0xe4
	// Line 2950, Address: 0x271778, Func Offset: 0xe8
	// Line 2951, Address: 0x27177c, Func Offset: 0xec
	// Line 2952, Address: 0x271780, Func Offset: 0xf0
	// Line 2956, Address: 0x271784, Func Offset: 0xf4
	// Line 2957, Address: 0x27179c, Func Offset: 0x10c
	// Line 2959, Address: 0x2717b8, Func Offset: 0x128
	// Line 2960, Address: 0x271810, Func Offset: 0x180
	// Func End, Address: 0x271828, Func Offset: 0x198
}
