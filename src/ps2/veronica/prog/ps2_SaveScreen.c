#include "ps2_SaveScreen.h"
#include "message.h"
#include "ps2_McSaveFile.h"
#include "ps2_MemoryCard.h"
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

// 
// Start address: 0x26fa70
void SetStateSaveScreenExit(SAVE_SCREEN* pSave)
{
	// Line 982, Address: 0x26fa70, Func Offset: 0
	// Line 984, Address: 0x26fa78, Func Offset: 0x8
	// Line 986, Address: 0x26fa80, Func Offset: 0x10
	// Line 988, Address: 0x26fa84, Func Offset: 0x14
	// Line 990, Address: 0x26fa8c, Func Offset: 0x1c
	// Func End, Address: 0x26fa98, Func Offset: 0x28
}

// 
// Start address: 0x26faa0
void ExecuteStateSaveScreenExit(SAVE_SCREEN* pSave)
{
	// Line 1006, Address: 0x26faa0, Func Offset: 0
	// Line 1010, Address: 0x26faac, Func Offset: 0xc
	// Line 1012, Address: 0x26facc, Func Offset: 0x2c
	// Line 1014, Address: 0x26fadc, Func Offset: 0x3c
	// Line 1016, Address: 0x26fae0, Func Offset: 0x40
	// Line 1019, Address: 0x26fae8, Func Offset: 0x48
	// Line 1021, Address: 0x26faf4, Func Offset: 0x54
	// Func End, Address: 0x26fb04, Func Offset: 0x64
}

// 
// Start address: 0x26fb10
void SetSaveScreenSpecialSave(SAVE_SCREEN* pSave)
{
	// Line 1038, Address: 0x26fb10, Func Offset: 0
	// Line 1040, Address: 0x26fb18, Func Offset: 0x8
	// Line 1042, Address: 0x26fb20, Func Offset: 0x10
	// Line 1044, Address: 0x26fb28, Func Offset: 0x18
	// Line 1045, Address: 0x26fb2c, Func Offset: 0x1c
	// Func End, Address: 0x26fb34, Func Offset: 0x24
}

// 
// Start address: 0x26fb40
void ExecuteStateSaveScreenSpecialSave(SAVE_SCREEN* pSave)
{
	// Line 1060, Address: 0x26fb40, Func Offset: 0
	// Line 1064, Address: 0x26fb48, Func Offset: 0x8
	// Line 1066, Address: 0x26fb68, Func Offset: 0x28
	// Line 1069, Address: 0x26fb6c, Func Offset: 0x2c
	// Line 1066, Address: 0x26fb70, Func Offset: 0x30
	// Line 1067, Address: 0x26fb78, Func Offset: 0x38
	// Line 1069, Address: 0x26fb84, Func Offset: 0x44
	// Line 1070, Address: 0x26fb8c, Func Offset: 0x4c
	// Line 1071, Address: 0x26fb94, Func Offset: 0x54
	// Line 1073, Address: 0x26fba0, Func Offset: 0x60
	// Line 1076, Address: 0x26fba4, Func Offset: 0x64
	// Line 1073, Address: 0x26fba8, Func Offset: 0x68
	// Line 1074, Address: 0x26fbb0, Func Offset: 0x70
	// Line 1076, Address: 0x26fbbc, Func Offset: 0x7c
	// Line 1077, Address: 0x26fbc4, Func Offset: 0x84
	// Line 1079, Address: 0x26fbcc, Func Offset: 0x8c
	// Line 1082, Address: 0x26fbd8, Func Offset: 0x98
	// Line 1085, Address: 0x26fbe8, Func Offset: 0xa8
	// Line 1086, Address: 0x26fbf0, Func Offset: 0xb0
	// Line 1090, Address: 0x26fbf8, Func Offset: 0xb8
	// Line 1093, Address: 0x26fbfc, Func Offset: 0xbc
	// Line 1094, Address: 0x26fc08, Func Offset: 0xc8
	// Line 1096, Address: 0x26fc10, Func Offset: 0xd0
	// Line 1099, Address: 0x26fc1c, Func Offset: 0xdc
	// Line 1101, Address: 0x26fc24, Func Offset: 0xe4
	// Line 1102, Address: 0x26fc30, Func Offset: 0xf0
	// Line 1106, Address: 0x26fc38, Func Offset: 0xf8
	// Line 1109, Address: 0x26fc54, Func Offset: 0x114
	// Line 1112, Address: 0x26fc5c, Func Offset: 0x11c
	// Func End, Address: 0x26fc68, Func Offset: 0x128
}

// 
// Start address: 0x26fc70
void SetStateSaveScreenLostDirCheck(SAVE_SCREEN* pSave)
{
	// Line 1127, Address: 0x26fc70, Func Offset: 0
	// Line 1129, Address: 0x26fc7c, Func Offset: 0xc
	// Line 1131, Address: 0x26fc84, Func Offset: 0x14
	// Line 1133, Address: 0x26fc8c, Func Offset: 0x1c
	// Line 1135, Address: 0x26fc94, Func Offset: 0x24
	// Line 1139, Address: 0x26fc98, Func Offset: 0x28
	// Line 1137, Address: 0x26fc9c, Func Offset: 0x2c
	// Line 1139, Address: 0x26fca4, Func Offset: 0x34
	// Line 1141, Address: 0x26fca8, Func Offset: 0x38
	// Line 1143, Address: 0x26fcb4, Func Offset: 0x44
	// Line 1145, Address: 0x26fcc0, Func Offset: 0x50
	// Line 1147, Address: 0x26fccc, Func Offset: 0x5c
	// Func End, Address: 0x26fcdc, Func Offset: 0x6c
}

// 
// Start address: 0x26fce0
void ExecuteStateSaveScreenLostDirCheck(SAVE_SCREEN* pSave)
{
	int lResult;
	// Line 1162, Address: 0x26fce0, Func Offset: 0
	// Line 1165, Address: 0x26fcec, Func Offset: 0xc
	// Line 1169, Address: 0x26fd18, Func Offset: 0x38
	// Line 1171, Address: 0x26fd20, Func Offset: 0x40
	// Line 1174, Address: 0x26fd2c, Func Offset: 0x4c
	// Line 1177, Address: 0x26fd3c, Func Offset: 0x5c
	// Line 1178, Address: 0x26fd44, Func Offset: 0x64
	// Line 1182, Address: 0x26fd4c, Func Offset: 0x6c
	// Line 1186, Address: 0x26fd58, Func Offset: 0x78
	// Line 1188, Address: 0x26fd60, Func Offset: 0x80
	// Line 1191, Address: 0x26fd6c, Func Offset: 0x8c
	// Line 1193, Address: 0x26fd78, Func Offset: 0x98
	// Line 1195, Address: 0x26fd80, Func Offset: 0xa0
	// Line 1197, Address: 0x26fd84, Func Offset: 0xa4
	// Line 1200, Address: 0x26fd8c, Func Offset: 0xac
	// Line 1201, Address: 0x26fd94, Func Offset: 0xb4
	// Line 1204, Address: 0x26fda0, Func Offset: 0xc0
	// Line 1205, Address: 0x26fda4, Func Offset: 0xc4
	// Line 1206, Address: 0x26fdac, Func Offset: 0xcc
	// Line 1209, Address: 0x26fdb8, Func Offset: 0xd8
	// Line 1211, Address: 0x26fdc4, Func Offset: 0xe4
	// Line 1213, Address: 0x26fdc8, Func Offset: 0xe8
	// Line 1217, Address: 0x26fdd0, Func Offset: 0xf0
	// Line 1218, Address: 0x26fde4, Func Offset: 0x104
	// Line 1220, Address: 0x26fdec, Func Offset: 0x10c
	// Line 1222, Address: 0x26fdf4, Func Offset: 0x114
	// Line 1224, Address: 0x26fe00, Func Offset: 0x120
	// Line 1225, Address: 0x26fe08, Func Offset: 0x128
	// Line 1226, Address: 0x26fe10, Func Offset: 0x130
	// Line 1229, Address: 0x26fe1c, Func Offset: 0x13c
	// Line 1231, Address: 0x26fe20, Func Offset: 0x140
	// Line 1235, Address: 0x26fe28, Func Offset: 0x148
	// Line 1237, Address: 0x26fe4c, Func Offset: 0x16c
	// Line 1239, Address: 0x26fe50, Func Offset: 0x170
	// Line 1242, Address: 0x26fe58, Func Offset: 0x178
	// Line 1243, Address: 0x26fe68, Func Offset: 0x188
	// Line 1245, Address: 0x26fe74, Func Offset: 0x194
	// Line 1246, Address: 0x26fe84, Func Offset: 0x1a4
	// Line 1249, Address: 0x26fea0, Func Offset: 0x1c0
	// Line 1250, Address: 0x26fea8, Func Offset: 0x1c8
	// Line 1253, Address: 0x26feb0, Func Offset: 0x1d0
	// Line 1255, Address: 0x26feb4, Func Offset: 0x1d4
	// Line 1256, Address: 0x26febc, Func Offset: 0x1dc
	// Line 1259, Address: 0x26fec8, Func Offset: 0x1e8
	// Line 1261, Address: 0x26fed0, Func Offset: 0x1f0
	// Line 1263, Address: 0x26fedc, Func Offset: 0x1fc
	// Line 1265, Address: 0x26fee4, Func Offset: 0x204
	// Line 1268, Address: 0x26feec, Func Offset: 0x20c
	// Line 1271, Address: 0x26fefc, Func Offset: 0x21c
	// Line 1273, Address: 0x26ff04, Func Offset: 0x224
	// Line 1276, Address: 0x26ff0c, Func Offset: 0x22c
	// Line 1279, Address: 0x26ff1c, Func Offset: 0x23c
	// Line 1284, Address: 0x26ff24, Func Offset: 0x244
	// Line 1287, Address: 0x26ff40, Func Offset: 0x260
	// Line 1289, Address: 0x26ff48, Func Offset: 0x268
	// Func End, Address: 0x26ff58, Func Offset: 0x278
}

// 
// Start address: 0x26ff60
void SetStateSaveScreenFreeCapacity(SAVE_SCREEN* pSave)
{
	// Line 1306, Address: 0x26ff60, Func Offset: 0
	// Line 1308, Address: 0x26ff68, Func Offset: 0x8
	// Line 1310, Address: 0x26ff70, Func Offset: 0x10
	// Line 1311, Address: 0x26ff74, Func Offset: 0x14
	// Func End, Address: 0x26ff7c, Func Offset: 0x1c
}

// 
// Start address: 0x26ff80
void ExecuteStateSaveScreenFreeCapacity(SAVE_SCREEN* pSave)
{
	int lResult;
	// Line 1326, Address: 0x26ff80, Func Offset: 0
	// Line 1329, Address: 0x26ff94, Func Offset: 0x14
	// Line 1331, Address: 0x26ff9c, Func Offset: 0x1c
	// Line 1334, Address: 0x26ffb0, Func Offset: 0x30
	// Line 1337, Address: 0x26ffbc, Func Offset: 0x3c
	// Line 1340, Address: 0x26ffc4, Func Offset: 0x44
	// Line 1347, Address: 0x26ffd0, Func Offset: 0x50
	// Line 1349, Address: 0x26ffd8, Func Offset: 0x58
	// Line 1354, Address: 0x26ffe0, Func Offset: 0x60
	// Line 1356, Address: 0x26ffec, Func Offset: 0x6c
	// Func End, Address: 0x270000, Func Offset: 0x80
}

// 
// Start address: 0x270000
void SetStateSaveScreenErrFreeCapacity(SAVE_SCREEN* pSave)
{
	// Line 1373, Address: 0x270000, Func Offset: 0
	// Line 1375, Address: 0x270008, Func Offset: 0x8
	// Line 1377, Address: 0x270010, Func Offset: 0x10
	// Line 1378, Address: 0x270014, Func Offset: 0x14
	// Func End, Address: 0x27001c, Func Offset: 0x1c
}

// 
// Start address: 0x270020
void ExecuteStateSaveScreenErrFreeCapacity(SAVE_SCREEN* pSave)
{
	// Line 1393, Address: 0x270020, Func Offset: 0
	// Line 1395, Address: 0x270028, Func Offset: 0x8
	// Line 1398, Address: 0x270048, Func Offset: 0x28
	// Line 1400, Address: 0x270050, Func Offset: 0x30
	// Line 1401, Address: 0x27005c, Func Offset: 0x3c
	// Line 1405, Address: 0x270064, Func Offset: 0x44
	// Line 1408, Address: 0x270080, Func Offset: 0x60
	// Line 1411, Address: 0x270088, Func Offset: 0x68
	// Func End, Address: 0x270094, Func Offset: 0x74
}

// 
// Start address: 0x2700a0
void SetStateSaveScreenCreateSaveFileCheck(SAVE_SCREEN* pSave)
{
	// Line 1428, Address: 0x2700a0, Func Offset: 0
	// Line 1430, Address: 0x2700a8, Func Offset: 0x8
	// Line 1432, Address: 0x2700b0, Func Offset: 0x10
	// Line 1435, Address: 0x2700b8, Func Offset: 0x18
	// Func End, Address: 0x2700c0, Func Offset: 0x20
}

// 
// Start address: 0x2700c0
void ExecuteStateSaveScreenCreateSaveFileCheck(SAVE_SCREEN* pSave)
{
	// Line 1450, Address: 0x2700c0, Func Offset: 0
	// Line 1454, Address: 0x2700c8, Func Offset: 0x8
	// Line 1456, Address: 0x2700e8, Func Offset: 0x28
	// Line 1459, Address: 0x2700ec, Func Offset: 0x2c
	// Line 1456, Address: 0x2700f0, Func Offset: 0x30
	// Line 1457, Address: 0x2700f8, Func Offset: 0x38
	// Line 1459, Address: 0x270104, Func Offset: 0x44
	// Line 1460, Address: 0x27010c, Func Offset: 0x4c
	// Line 1462, Address: 0x270114, Func Offset: 0x54
	// Line 1464, Address: 0x270120, Func Offset: 0x60
	// Line 1467, Address: 0x270124, Func Offset: 0x64
	// Line 1464, Address: 0x270128, Func Offset: 0x68
	// Line 1465, Address: 0x270130, Func Offset: 0x70
	// Line 1467, Address: 0x27013c, Func Offset: 0x7c
	// Line 1468, Address: 0x270144, Func Offset: 0x84
	// Line 1470, Address: 0x27014c, Func Offset: 0x8c
	// Line 1472, Address: 0x270158, Func Offset: 0x98
	// Line 1475, Address: 0x270168, Func Offset: 0xa8
	// Line 1476, Address: 0x270170, Func Offset: 0xb0
	// Line 1480, Address: 0x270178, Func Offset: 0xb8
	// Line 1483, Address: 0x270180, Func Offset: 0xc0
	// Line 1484, Address: 0x27018c, Func Offset: 0xcc
	// Line 1486, Address: 0x270194, Func Offset: 0xd4
	// Line 1488, Address: 0x2701a0, Func Offset: 0xe0
	// Line 1490, Address: 0x2701a8, Func Offset: 0xe8
	// Line 1491, Address: 0x2701b4, Func Offset: 0xf4
	// Line 1495, Address: 0x2701bc, Func Offset: 0xfc
	// Line 1498, Address: 0x2701d8, Func Offset: 0x118
	// Line 1501, Address: 0x2701e0, Func Offset: 0x120
	// Func End, Address: 0x2701ec, Func Offset: 0x12c
}

// 
// Start address: 0x2701f0
void SetStateSaveScreenCreateSaveFile(SAVE_SCREEN* pSave)
{
	// Line 1518, Address: 0x2701f0, Func Offset: 0
	// Line 1520, Address: 0x2701f8, Func Offset: 0x8
	// Line 1524, Address: 0x2701fc, Func Offset: 0xc
	// Line 1522, Address: 0x270200, Func Offset: 0x10
	// Line 1524, Address: 0x270204, Func Offset: 0x14
	// Line 1526, Address: 0x270208, Func Offset: 0x18
	// Line 1528, Address: 0x270210, Func Offset: 0x20
	// Line 1530, Address: 0x270218, Func Offset: 0x28
	// Func End, Address: 0x270224, Func Offset: 0x34
}

// 
// Start address: 0x270230
void ExecuteStateSaveScreenCreateSaveFile(SAVE_SCREEN* pSave)
{
	int lResult;
	// Line 1546, Address: 0x270230, Func Offset: 0
	// Line 1549, Address: 0x27023c, Func Offset: 0xc
	// Line 1552, Address: 0x270268, Func Offset: 0x38
	// Line 1554, Address: 0x270270, Func Offset: 0x40
	// Line 1557, Address: 0x27027c, Func Offset: 0x4c
	// Line 1559, Address: 0x270288, Func Offset: 0x58
	// Line 1561, Address: 0x270290, Func Offset: 0x60
	// Line 1562, Address: 0x270294, Func Offset: 0x64
	// Line 1563, Address: 0x27029c, Func Offset: 0x6c
	// Line 1566, Address: 0x2702a8, Func Offset: 0x78
	// Line 1571, Address: 0x2702cc, Func Offset: 0x9c
	// Line 1574, Address: 0x2702d4, Func Offset: 0xa4
	// Line 1575, Address: 0x2702dc, Func Offset: 0xac
	// Line 1577, Address: 0x2702e8, Func Offset: 0xb8
	// Line 1578, Address: 0x2702ec, Func Offset: 0xbc
	// Line 1579, Address: 0x2702f4, Func Offset: 0xc4
	// Line 1582, Address: 0x270300, Func Offset: 0xd0
	// Line 1584, Address: 0x27030c, Func Offset: 0xdc
	// Line 1586, Address: 0x270314, Func Offset: 0xe4
	// Line 1588, Address: 0x270318, Func Offset: 0xe8
	// Line 1592, Address: 0x270320, Func Offset: 0xf0
	// Line 1593, Address: 0x270338, Func Offset: 0x108
	// Line 1596, Address: 0x270344, Func Offset: 0x114
	// Line 1598, Address: 0x270350, Func Offset: 0x120
	// Line 1600, Address: 0x270358, Func Offset: 0x128
	// Line 1601, Address: 0x27035c, Func Offset: 0x12c
	// Line 1605, Address: 0x270364, Func Offset: 0x134
	// Line 1607, Address: 0x270388, Func Offset: 0x158
	// Line 1610, Address: 0x27038c, Func Offset: 0x15c
	// Line 1613, Address: 0x270394, Func Offset: 0x164
	// Line 1614, Address: 0x27039c, Func Offset: 0x16c
	// Line 1617, Address: 0x2703a8, Func Offset: 0x178
	// Line 1619, Address: 0x2703b4, Func Offset: 0x184
	// Line 1621, Address: 0x2703bc, Func Offset: 0x18c
	// Line 1622, Address: 0x2703c0, Func Offset: 0x190
	// Line 1623, Address: 0x2703c8, Func Offset: 0x198
	// Line 1626, Address: 0x2703d4, Func Offset: 0x1a4
	// Line 1628, Address: 0x2703ec, Func Offset: 0x1bc
	// Line 1631, Address: 0x2703f0, Func Offset: 0x1c0
	// Line 1634, Address: 0x2703f8, Func Offset: 0x1c8
	// Line 1635, Address: 0x270400, Func Offset: 0x1d0
	// Line 1637, Address: 0x27040c, Func Offset: 0x1dc
	// Line 1638, Address: 0x270410, Func Offset: 0x1e0
	// Line 1639, Address: 0x270418, Func Offset: 0x1e8
	// Line 1642, Address: 0x270424, Func Offset: 0x1f4
	// Line 1644, Address: 0x270430, Func Offset: 0x200
	// Line 1646, Address: 0x270438, Func Offset: 0x208
	// Line 1648, Address: 0x27043c, Func Offset: 0x20c
	// Line 1652, Address: 0x270444, Func Offset: 0x214
	// Line 1654, Address: 0x270468, Func Offset: 0x238
	// Line 1656, Address: 0x27046c, Func Offset: 0x23c
	// Line 1659, Address: 0x270474, Func Offset: 0x244
	// Line 1660, Address: 0x27047c, Func Offset: 0x24c
	// Line 1662, Address: 0x270488, Func Offset: 0x258
	// Line 1665, Address: 0x2704a4, Func Offset: 0x274
	// Line 1669, Address: 0x2704ac, Func Offset: 0x27c
	// Line 1667, Address: 0x2704b0, Func Offset: 0x280
	// Line 1669, Address: 0x2704b4, Func Offset: 0x284
	// Line 1671, Address: 0x2704b8, Func Offset: 0x288
	// Line 1672, Address: 0x2704c4, Func Offset: 0x294
	// Line 1675, Address: 0x2704cc, Func Offset: 0x29c
	// Line 1677, Address: 0x2704d0, Func Offset: 0x2a0
	// Line 1678, Address: 0x2704d8, Func Offset: 0x2a8
	// Line 1681, Address: 0x2704e4, Func Offset: 0x2b4
	// Line 1683, Address: 0x2704f0, Func Offset: 0x2c0
	// Line 1685, Address: 0x2704f8, Func Offset: 0x2c8
	// Line 1687, Address: 0x2704fc, Func Offset: 0x2cc
	// Line 1690, Address: 0x270504, Func Offset: 0x2d4
	// Line 1692, Address: 0x270514, Func Offset: 0x2e4
	// Line 1695, Address: 0x270524, Func Offset: 0x2f4
	// Line 1698, Address: 0x27052c, Func Offset: 0x2fc
	// Line 1701, Address: 0x270534, Func Offset: 0x304
	// Line 1704, Address: 0x270544, Func Offset: 0x314
	// Line 1709, Address: 0x27054c, Func Offset: 0x31c
	// Func End, Address: 0x27055c, Func Offset: 0x32c
}

// 
// Start address: 0x270560
void SetStateSaveScreenErrCreateSaveFile(SAVE_SCREEN* pSave)
{
	// Line 1726, Address: 0x270560, Func Offset: 0
	// Line 1728, Address: 0x270568, Func Offset: 0x8
	// Line 1730, Address: 0x270570, Func Offset: 0x10
	// Line 1732, Address: 0x270578, Func Offset: 0x18
	// Line 1735, Address: 0x27057c, Func Offset: 0x1c
	// Func End, Address: 0x270584, Func Offset: 0x24
}

// 
// Start address: 0x270590
void ExecuteStateSaveScreenErrCreateSaveFile(SAVE_SCREEN* pSave)
{
	// Line 1750, Address: 0x270590, Func Offset: 0
	// Line 1754, Address: 0x270598, Func Offset: 0x8
	// Line 1757, Address: 0x2705b8, Func Offset: 0x28
	// Line 1759, Address: 0x2705c0, Func Offset: 0x30
	// Line 1760, Address: 0x2705cc, Func Offset: 0x3c
	// Line 1764, Address: 0x2705d4, Func Offset: 0x44
	// Line 1767, Address: 0x2705f0, Func Offset: 0x60
	// Line 1770, Address: 0x2705f8, Func Offset: 0x68
	// Func End, Address: 0x270604, Func Offset: 0x74
}

// 
// Start address: 0x270610
void SetStateSaveScreenSelectFile(SAVE_SCREEN* pSave)
{
	// Line 1785, Address: 0x270610, Func Offset: 0
	// Line 1787, Address: 0x27061c, Func Offset: 0xc
	// Line 1789, Address: 0x270624, Func Offset: 0x14
	// Line 1791, Address: 0x27062c, Func Offset: 0x1c
	// Line 1793, Address: 0x270634, Func Offset: 0x24
	// Line 1795, Address: 0x27063c, Func Offset: 0x2c
	// Line 1797, Address: 0x270640, Func Offset: 0x30
	// Line 1799, Address: 0x27064c, Func Offset: 0x3c
	// Line 1800, Address: 0x270658, Func Offset: 0x48
	// Func End, Address: 0x270668, Func Offset: 0x58
}

// 
// Start address: 0x270670
void ExecuteStateSaveScreenSelectFile(SAVE_SCREEN* pSave)
{
	unsigned int KeyWait01;
	unsigned int KeyWait00;
	// Line 1815, Address: 0x270670, Func Offset: 0
	// Line 1820, Address: 0x27067c, Func Offset: 0xc
	// Line 1822, Address: 0x27069c, Func Offset: 0x2c
	// Line 1824, Address: 0x2706b8, Func Offset: 0x48
	// Line 1826, Address: 0x2706cc, Func Offset: 0x5c
	// Line 1827, Address: 0x2706dc, Func Offset: 0x6c
	// Line 1830, Address: 0x2706e4, Func Offset: 0x74
	// Line 1832, Address: 0x2706ec, Func Offset: 0x7c
	// Line 1835, Address: 0x2706f4, Func Offset: 0x84
	// Line 1836, Address: 0x2706fc, Func Offset: 0x8c
	// Line 1838, Address: 0x270704, Func Offset: 0x94
	// Line 1840, Address: 0x27072c, Func Offset: 0xbc
	// Line 1841, Address: 0x270734, Func Offset: 0xc4
	// Line 1843, Address: 0x270744, Func Offset: 0xd4
	// Line 1845, Address: 0x270750, Func Offset: 0xe0
	// Line 1847, Address: 0x27075c, Func Offset: 0xec
	// Line 1848, Address: 0x270768, Func Offset: 0xf8
	// Line 1850, Address: 0x270774, Func Offset: 0x104
	// Line 1852, Address: 0x27077c, Func Offset: 0x10c
	// Line 1853, Address: 0x270788, Func Offset: 0x118
	// Line 1854, Address: 0x270790, Func Offset: 0x120
	// Line 1857, Address: 0x2707a0, Func Offset: 0x130
	// Line 1859, Address: 0x2707ac, Func Offset: 0x13c
	// Line 1860, Address: 0x2707b8, Func Offset: 0x148
	// Line 1861, Address: 0x2707c0, Func Offset: 0x150
	// Line 1863, Address: 0x2707cc, Func Offset: 0x15c
	// Line 1865, Address: 0x2707d8, Func Offset: 0x168
	// Line 1867, Address: 0x2707e4, Func Offset: 0x174
	// Line 1869, Address: 0x2707f0, Func Offset: 0x180
	// Line 1871, Address: 0x270800, Func Offset: 0x190
	// Line 1873, Address: 0x270804, Func Offset: 0x194
	// Line 1874, Address: 0x270810, Func Offset: 0x1a0
	// Line 1875, Address: 0x270818, Func Offset: 0x1a8
	// Line 1879, Address: 0x27082c, Func Offset: 0x1bc
	// Line 1881, Address: 0x270838, Func Offset: 0x1c8
	// Line 1884, Address: 0x270844, Func Offset: 0x1d4
	// Line 1887, Address: 0x27084c, Func Offset: 0x1dc
	// Line 1890, Address: 0x270858, Func Offset: 0x1e8
	// Line 1892, Address: 0x270860, Func Offset: 0x1f0
	// Line 1893, Address: 0x27086c, Func Offset: 0x1fc
	// Line 1894, Address: 0x270874, Func Offset: 0x204
	// Line 1897, Address: 0x270880, Func Offset: 0x210
	// Line 1899, Address: 0x270888, Func Offset: 0x218
	// Line 1905, Address: 0x270894, Func Offset: 0x224
	// Line 1908, Address: 0x2708b0, Func Offset: 0x240
	// Line 1912, Address: 0x2708b8, Func Offset: 0x248
	// Line 1914, Address: 0x2708cc, Func Offset: 0x25c
	// Line 1917, Address: 0x2708d0, Func Offset: 0x260
	// Line 1919, Address: 0x2708f4, Func Offset: 0x284
	// Line 1920, Address: 0x27090c, Func Offset: 0x29c
	// Line 1922, Address: 0x270924, Func Offset: 0x2b4
	// Func End, Address: 0x270934, Func Offset: 0x2c4
}

// 
// Start address: 0x270940
void SetStateSaveScreenSaveCursor(SAVE_SCREEN* pSave)
{
	// Line 1937, Address: 0x270940, Func Offset: 0
	// Line 1939, Address: 0x27094c, Func Offset: 0xc
	// Line 1941, Address: 0x27095c, Func Offset: 0x1c
	// Line 1943, Address: 0x270964, Func Offset: 0x24
	// Line 1945, Address: 0x27096c, Func Offset: 0x2c
	// Line 1947, Address: 0x270974, Func Offset: 0x34
	// Line 1948, Address: 0x270978, Func Offset: 0x38
	// Func End, Address: 0x270988, Func Offset: 0x48
}

// 
// Start address: 0x270990
void ExecuteStateSaveScreenSaveCursor(SAVE_SCREEN* pSave)
{
	// Line 1963, Address: 0x270990, Func Offset: 0
	// Line 1965, Address: 0x2709a0, Func Offset: 0x10
	// Line 1968, Address: 0x2709bc, Func Offset: 0x2c
	// Line 1969, Address: 0x2709c4, Func Offset: 0x34
	// Line 1974, Address: 0x2709cc, Func Offset: 0x3c
	// Line 1976, Address: 0x2709d8, Func Offset: 0x48
	// Func End, Address: 0x2709e8, Func Offset: 0x58
}

// 
// Start address: 0x2709f0
void SetStateSaveScreenSaveCursorOld(SAVE_SCREEN* pSave)
{
	// Line 1993, Address: 0x2709f0, Func Offset: 0
	// Line 1995, Address: 0x2709f8, Func Offset: 0x8
	// Line 1997, Address: 0x270a00, Func Offset: 0x10
	// Line 1999, Address: 0x270a08, Func Offset: 0x18
	// Line 2000, Address: 0x270a0c, Func Offset: 0x1c
	// Func End, Address: 0x270a14, Func Offset: 0x24
}

// 
// Start address: 0x270a20
void ExecuteStateSaveScreenSaveCursorOld(SAVE_SCREEN* pSave)
{
	// Line 2015, Address: 0x270a20, Func Offset: 0
	// Line 2019, Address: 0x270a28, Func Offset: 0x8
	// Line 2021, Address: 0x270a48, Func Offset: 0x28
	// Line 2024, Address: 0x270a4c, Func Offset: 0x2c
	// Line 2021, Address: 0x270a50, Func Offset: 0x30
	// Line 2022, Address: 0x270a58, Func Offset: 0x38
	// Line 2024, Address: 0x270a64, Func Offset: 0x44
	// Line 2025, Address: 0x270a6c, Func Offset: 0x4c
	// Line 2027, Address: 0x270a74, Func Offset: 0x54
	// Line 2029, Address: 0x270a80, Func Offset: 0x60
	// Line 2032, Address: 0x270a84, Func Offset: 0x64
	// Line 2029, Address: 0x270a88, Func Offset: 0x68
	// Line 2030, Address: 0x270a90, Func Offset: 0x70
	// Line 2032, Address: 0x270a9c, Func Offset: 0x7c
	// Line 2033, Address: 0x270aa4, Func Offset: 0x84
	// Line 2035, Address: 0x270aac, Func Offset: 0x8c
	// Line 2037, Address: 0x270ab8, Func Offset: 0x98
	// Line 2040, Address: 0x270ac8, Func Offset: 0xa8
	// Line 2041, Address: 0x270ad0, Func Offset: 0xb0
	// Line 2045, Address: 0x270ad8, Func Offset: 0xb8
	// Line 2048, Address: 0x270ae0, Func Offset: 0xc0
	// Line 2049, Address: 0x270aec, Func Offset: 0xcc
	// Line 2051, Address: 0x270af4, Func Offset: 0xd4
	// Line 2054, Address: 0x270b00, Func Offset: 0xe0
	// Line 2056, Address: 0x270b08, Func Offset: 0xe8
	// Line 2057, Address: 0x270b14, Func Offset: 0xf4
	// Line 2061, Address: 0x270b1c, Func Offset: 0xfc
	// Line 2064, Address: 0x270b38, Func Offset: 0x118
	// Line 2067, Address: 0x270b40, Func Offset: 0x120
	// Func End, Address: 0x270b4c, Func Offset: 0x12c
}

// 
// Start address: 0x270b50
void SetStateSaveScreenSaveCursorNew(SAVE_SCREEN* pSave)
{
	// Line 2084, Address: 0x270b50, Func Offset: 0
	// Line 2086, Address: 0x270b58, Func Offset: 0x8
	// Line 2088, Address: 0x270b60, Func Offset: 0x10
	// Line 2091, Address: 0x270b68, Func Offset: 0x18
	// Func End, Address: 0x270b70, Func Offset: 0x20
}

// 
// Start address: 0x270b70
void ExecuteStateSaveScreenSaveCursorNew(SAVE_SCREEN* pSave)
{
	// Line 2106, Address: 0x270b70, Func Offset: 0
	// Line 2110, Address: 0x270b78, Func Offset: 0x8
	// Line 2112, Address: 0x270b98, Func Offset: 0x28
	// Line 2114, Address: 0x270b9c, Func Offset: 0x2c
	// Line 2112, Address: 0x270ba0, Func Offset: 0x30
	// Line 2113, Address: 0x270ba8, Func Offset: 0x38
	// Line 2114, Address: 0x270bb4, Func Offset: 0x44
	// Line 2115, Address: 0x270bbc, Func Offset: 0x4c
	// Line 2117, Address: 0x270bc4, Func Offset: 0x54
	// Line 2119, Address: 0x270bd0, Func Offset: 0x60
	// Line 2122, Address: 0x270bd4, Func Offset: 0x64
	// Line 2119, Address: 0x270bd8, Func Offset: 0x68
	// Line 2120, Address: 0x270be0, Func Offset: 0x70
	// Line 2122, Address: 0x270bec, Func Offset: 0x7c
	// Line 2123, Address: 0x270bf4, Func Offset: 0x84
	// Line 2125, Address: 0x270bfc, Func Offset: 0x8c
	// Line 2127, Address: 0x270c08, Func Offset: 0x98
	// Line 2130, Address: 0x270c18, Func Offset: 0xa8
	// Line 2131, Address: 0x270c20, Func Offset: 0xb0
	// Line 2135, Address: 0x270c28, Func Offset: 0xb8
	// Line 2138, Address: 0x270c30, Func Offset: 0xc0
	// Line 2139, Address: 0x270c3c, Func Offset: 0xcc
	// Line 2141, Address: 0x270c44, Func Offset: 0xd4
	// Line 2144, Address: 0x270c50, Func Offset: 0xe0
	// Line 2146, Address: 0x270c58, Func Offset: 0xe8
	// Line 2147, Address: 0x270c64, Func Offset: 0xf4
	// Line 2151, Address: 0x270c6c, Func Offset: 0xfc
	// Line 2154, Address: 0x270c88, Func Offset: 0x118
	// Line 2157, Address: 0x270c90, Func Offset: 0x120
	// Func End, Address: 0x270c9c, Func Offset: 0x12c
}

// 
// Start address: 0x270ca0
void SetStateSaveScreenSave(SAVE_SCREEN* pSave)
{
	// Line 2174, Address: 0x270ca0, Func Offset: 0
	// Line 2178, Address: 0x270ca8, Func Offset: 0x8
	// Line 2176, Address: 0x270cac, Func Offset: 0xc
	// Line 2178, Address: 0x270cb0, Func Offset: 0x10
	// Line 2180, Address: 0x270cb4, Func Offset: 0x14
	// Line 2182, Address: 0x270cbc, Func Offset: 0x1c
	// Func End, Address: 0x270cc8, Func Offset: 0x28
}

// 
// Start address: 0x270cd0
void ExecuteStateSaveScreenSave(SAVE_SCREEN* pSave)
{
	int lFileNumber;
	int lSaveResult;
	// Line 2198, Address: 0x270cd0, Func Offset: 0
	// Line 2201, Address: 0x270cdc, Func Offset: 0xc
	// Line 2206, Address: 0x270d14, Func Offset: 0x44
	// Line 2208, Address: 0x270d1c, Func Offset: 0x4c
	// Line 2212, Address: 0x270d40, Func Offset: 0x70
	// Line 2217, Address: 0x270d48, Func Offset: 0x78
	// Line 2219, Address: 0x270d50, Func Offset: 0x80
	// Line 2222, Address: 0x270d5c, Func Offset: 0x8c
	// Line 2223, Address: 0x270d60, Func Offset: 0x90
	// Line 2225, Address: 0x270d68, Func Offset: 0x98
	// Line 2228, Address: 0x270d74, Func Offset: 0xa4
	// Line 2230, Address: 0x270d80, Func Offset: 0xb0
	// Line 2232, Address: 0x270d88, Func Offset: 0xb8
	// Line 2234, Address: 0x270d8c, Func Offset: 0xbc
	// Line 2238, Address: 0x270d94, Func Offset: 0xc4
	// Line 2240, Address: 0x270d9c, Func Offset: 0xcc
	// Line 2242, Address: 0x270dac, Func Offset: 0xdc
	// Line 2243, Address: 0x270db4, Func Offset: 0xe4
	// Line 2246, Address: 0x270dbc, Func Offset: 0xec
	// Line 2249, Address: 0x270dcc, Func Offset: 0xfc
	// Line 2253, Address: 0x270dd4, Func Offset: 0x104
	// Func End, Address: 0x270de4, Func Offset: 0x114
}

// 
// Start address: 0x270df0
void SetStateSaveScreenSuccessCardWrite(SAVE_SCREEN* pSave)
{
	// Line 2270, Address: 0x270df0, Func Offset: 0
	// Line 2272, Address: 0x270df8, Func Offset: 0x8
	// Line 2274, Address: 0x270dfc, Func Offset: 0xc
	// Line 2272, Address: 0x270e00, Func Offset: 0x10
	// Line 2274, Address: 0x270e04, Func Offset: 0x14
	// Line 2276, Address: 0x270e08, Func Offset: 0x18
	// Func End, Address: 0x270e10, Func Offset: 0x20
}

// 
// Start address: 0x270e10
void ExecuteStateSaveScreenSuccessCardWrite(SAVE_SCREEN* pSave)
{
	// Line 2292, Address: 0x270e10, Func Offset: 0
	// Line 2294, Address: 0x270e20, Func Offset: 0x10
	// Line 2296, Address: 0x270e30, Func Offset: 0x20
	// Line 2299, Address: 0x270e3c, Func Offset: 0x2c
	// Line 2301, Address: 0x270e44, Func Offset: 0x34
	// Line 2307, Address: 0x270e4c, Func Offset: 0x3c
	// Func End, Address: 0x270e5c, Func Offset: 0x4c
}

// 
// Start address: 0x270e60
void SetStateSaveScreenSuccessCardWriteMessage(SAVE_SCREEN* pSave)
{
	// Line 2322, Address: 0x270e60, Func Offset: 0
	// Line 2324, Address: 0x270e6c, Func Offset: 0xc
	// Line 2326, Address: 0x270e74, Func Offset: 0x14
	// Line 2328, Address: 0x270e7c, Func Offset: 0x1c
	// Line 2330, Address: 0x270e84, Func Offset: 0x24
	// Line 2332, Address: 0x270e90, Func Offset: 0x30
	// Line 2334, Address: 0x270e9c, Func Offset: 0x3c
	// Line 2335, Address: 0x270ea8, Func Offset: 0x48
	// Func End, Address: 0x270eb8, Func Offset: 0x58
}

// 
// Start address: 0x270ec0
void ExecuteStateSaveScreenSuccessCardWriteMessage(SAVE_SCREEN* pSave)
{
	// Line 2350, Address: 0x270ec0, Func Offset: 0
	// Line 2352, Address: 0x270ec8, Func Offset: 0x8
	// Line 2355, Address: 0x270ed4, Func Offset: 0x14
	// Line 2356, Address: 0x270ed8, Func Offset: 0x18
	// Line 2360, Address: 0x270ee0, Func Offset: 0x20
	// Line 2362, Address: 0x270ee8, Func Offset: 0x28
	// Func End, Address: 0x270ef4, Func Offset: 0x34
}

// 
// Start address: 0x270f00
void SetStateSaveScreenErrCardWrite(SAVE_SCREEN* pSave)
{
	// Line 2379, Address: 0x270f00, Func Offset: 0
	// Line 2381, Address: 0x270f08, Func Offset: 0x8
	// Line 2383, Address: 0x270f10, Func Offset: 0x10
	// Line 2384, Address: 0x270f14, Func Offset: 0x14
	// Func End, Address: 0x270f1c, Func Offset: 0x1c
}

// 
// Start address: 0x270f20
void ExecuteStateSaveScreenErrCardWrite(SAVE_SCREEN* pSave)
{
	// Line 2399, Address: 0x270f20, Func Offset: 0
	// Line 2400, Address: 0x270f28, Func Offset: 0x8
	// Line 2403, Address: 0x270f48, Func Offset: 0x28
	// Line 2405, Address: 0x270f50, Func Offset: 0x30
	// Line 2406, Address: 0x270f5c, Func Offset: 0x3c
	// Line 2410, Address: 0x270f64, Func Offset: 0x44
	// Line 2413, Address: 0x270f80, Func Offset: 0x60
	// Line 2416, Address: 0x270f88, Func Offset: 0x68
	// Func End, Address: 0x270f94, Func Offset: 0x74
}

// 
// Start address: 0x270fa0
void SetStateSaveScreenFormat(SAVE_SCREEN* pSave)
{
	// Line 2433, Address: 0x270fa0, Func Offset: 0
	// Line 2435, Address: 0x270fa8, Func Offset: 0x8
	// Line 2437, Address: 0x270fb0, Func Offset: 0x10
	// Line 2439, Address: 0x270fb8, Func Offset: 0x18
	// Line 2441, Address: 0x270fc0, Func Offset: 0x20
	// Func End, Address: 0x270fcc, Func Offset: 0x2c
}

// 
// Start address: 0x270fd0
void ExecuteStateSaveScreenFormat(SAVE_SCREEN* pSave)
{
	// Line 2457, Address: 0x270fd0, Func Offset: 0
	// Line 2460, Address: 0x270fd8, Func Offset: 0x8
	// Line 2462, Address: 0x270ff8, Func Offset: 0x28
	// Line 2465, Address: 0x270ffc, Func Offset: 0x2c
	// Line 2462, Address: 0x271000, Func Offset: 0x30
	// Line 2463, Address: 0x271008, Func Offset: 0x38
	// Line 2465, Address: 0x271014, Func Offset: 0x44
	// Line 2466, Address: 0x27101c, Func Offset: 0x4c
	// Line 2467, Address: 0x271024, Func Offset: 0x54
	// Line 2469, Address: 0x271030, Func Offset: 0x60
	// Line 2472, Address: 0x271034, Func Offset: 0x64
	// Line 2469, Address: 0x271038, Func Offset: 0x68
	// Line 2470, Address: 0x271040, Func Offset: 0x70
	// Line 2472, Address: 0x27104c, Func Offset: 0x7c
	// Line 2473, Address: 0x271054, Func Offset: 0x84
	// Line 2475, Address: 0x27105c, Func Offset: 0x8c
	// Line 2477, Address: 0x271068, Func Offset: 0x98
	// Line 2480, Address: 0x271078, Func Offset: 0xa8
	// Line 2481, Address: 0x271080, Func Offset: 0xb0
	// Line 2486, Address: 0x271088, Func Offset: 0xb8
	// Line 2489, Address: 0x271090, Func Offset: 0xc0
	// Line 2490, Address: 0x27109c, Func Offset: 0xcc
	// Line 2492, Address: 0x2710a4, Func Offset: 0xd4
	// Line 2495, Address: 0x2710b0, Func Offset: 0xe0
	// Line 2497, Address: 0x2710b8, Func Offset: 0xe8
	// Line 2498, Address: 0x2710c4, Func Offset: 0xf4
	// Line 2502, Address: 0x2710cc, Func Offset: 0xfc
	// Line 2505, Address: 0x2710e8, Func Offset: 0x118
	// Line 2508, Address: 0x2710f0, Func Offset: 0x120
	// Func End, Address: 0x2710fc, Func Offset: 0x12c
}

// 
// Start address: 0x271100
void SetStateSaveScreenStartFormat(SAVE_SCREEN* pSave)
{
	// Line 2525, Address: 0x271100, Func Offset: 0
	// Line 2529, Address: 0x271108, Func Offset: 0x8
	// Line 2527, Address: 0x27110c, Func Offset: 0xc
	// Line 2529, Address: 0x271110, Func Offset: 0x10
	// Line 2531, Address: 0x271114, Func Offset: 0x14
	// Line 2533, Address: 0x27111c, Func Offset: 0x1c
	// Func End, Address: 0x271128, Func Offset: 0x28
}

// 
// Start address: 0x271130
void ExecuteStateSaveScreenStartFormat(SAVE_SCREEN* pSave)
{
	int lFormatResult;
	// Line 2550, Address: 0x271130, Func Offset: 0
	// Line 2553, Address: 0x27113c, Func Offset: 0xc
	// Line 2557, Address: 0x271174, Func Offset: 0x44
	// Line 2561, Address: 0x271188, Func Offset: 0x58
	// Line 2564, Address: 0x271190, Func Offset: 0x60
	// Line 2566, Address: 0x271198, Func Offset: 0x68
	// Line 2569, Address: 0x2711a4, Func Offset: 0x74
	// Line 2571, Address: 0x2711b0, Func Offset: 0x80
	// Line 2572, Address: 0x2711b4, Func Offset: 0x84
	// Line 2574, Address: 0x2711bc, Func Offset: 0x8c
	// Line 2577, Address: 0x2711c8, Func Offset: 0x98
	// Line 2579, Address: 0x2711d4, Func Offset: 0xa4
	// Line 2581, Address: 0x2711dc, Func Offset: 0xac
	// Line 2583, Address: 0x2711e0, Func Offset: 0xb0
	// Line 2587, Address: 0x2711e8, Func Offset: 0xb8
	// Line 2590, Address: 0x2711f8, Func Offset: 0xc8
	// Line 2592, Address: 0x271200, Func Offset: 0xd0
	// Line 2595, Address: 0x271208, Func Offset: 0xd8
	// Line 2598, Address: 0x271218, Func Offset: 0xe8
	// Line 2602, Address: 0x271220, Func Offset: 0xf0
	// Func End, Address: 0x271230, Func Offset: 0x100
}

// 
// Start address: 0x271230
void SetStateSaveScreenExitFormat(SAVE_SCREEN* pSave)
{
	// Line 2619, Address: 0x271230, Func Offset: 0
	// Line 2621, Address: 0x271238, Func Offset: 0x8
	// Line 2623, Address: 0x271240, Func Offset: 0x10
	// Line 2625, Address: 0x271248, Func Offset: 0x18
	// Line 2626, Address: 0x27124c, Func Offset: 0x1c
	// Func End, Address: 0x271254, Func Offset: 0x24
}

// 
// Start address: 0x271260
void ExecuteStateSaveScreenExitFormat(SAVE_SCREEN* pSave)
{
	// Line 2641, Address: 0x271260, Func Offset: 0
	// Line 2643, Address: 0x271268, Func Offset: 0x8
	// Line 2645, Address: 0x271288, Func Offset: 0x28
	// Line 2648, Address: 0x27128c, Func Offset: 0x2c
	// Line 2645, Address: 0x271290, Func Offset: 0x30
	// Line 2646, Address: 0x271298, Func Offset: 0x38
	// Line 2648, Address: 0x2712a4, Func Offset: 0x44
	// Line 2649, Address: 0x2712ac, Func Offset: 0x4c
	// Line 2650, Address: 0x2712b4, Func Offset: 0x54
	// Line 2652, Address: 0x2712c0, Func Offset: 0x60
	// Line 2655, Address: 0x2712c4, Func Offset: 0x64
	// Line 2652, Address: 0x2712c8, Func Offset: 0x68
	// Line 2653, Address: 0x2712d0, Func Offset: 0x70
	// Line 2655, Address: 0x2712dc, Func Offset: 0x7c
	// Line 2656, Address: 0x2712e4, Func Offset: 0x84
	// Line 2657, Address: 0x2712ec, Func Offset: 0x8c
	// Line 2659, Address: 0x2712f8, Func Offset: 0x98
	// Line 2662, Address: 0x271308, Func Offset: 0xa8
	// Line 2663, Address: 0x271310, Func Offset: 0xb0
	// Line 2667, Address: 0x271318, Func Offset: 0xb8
	// Line 2670, Address: 0x271320, Func Offset: 0xc0
	// Line 2671, Address: 0x27132c, Func Offset: 0xcc
	// Line 2672, Address: 0x271334, Func Offset: 0xd4
	// Line 2675, Address: 0x271340, Func Offset: 0xe0
	// Line 2677, Address: 0x271348, Func Offset: 0xe8
	// Line 2678, Address: 0x271354, Func Offset: 0xf4
	// Line 2682, Address: 0x27135c, Func Offset: 0xfc
	// Line 2685, Address: 0x271378, Func Offset: 0x118
	// Line 2688, Address: 0x271380, Func Offset: 0x120
	// Func End, Address: 0x27138c, Func Offset: 0x12c
}

// 
// Start address: 0x271390
void SetStateSaveScreenSuccessFormat(SAVE_SCREEN* pSave)
{
	// Line 2705, Address: 0x271390, Func Offset: 0
	// Line 2707, Address: 0x271398, Func Offset: 0x8
	// Line 2709, Address: 0x2713a0, Func Offset: 0x10
	// Line 2711, Address: 0x2713a8, Func Offset: 0x18
	// Line 2712, Address: 0x2713ac, Func Offset: 0x1c
	// Func End, Address: 0x2713b4, Func Offset: 0x24
}

// 
// Start address: 0x2713c0
void ExecuteStateSaveScreenSuccessFormat(SAVE_SCREEN* pSave)
{
	// Line 2727, Address: 0x2713c0, Func Offset: 0
	// Line 2729, Address: 0x2713c8, Func Offset: 0x8
	// Line 2732, Address: 0x2713d8, Func Offset: 0x18
	// Line 2734, Address: 0x2713e0, Func Offset: 0x20
	// Func End, Address: 0x2713ec, Func Offset: 0x2c
}

// 
// Start address: 0x2713f0
void SetStateSaveScreenErrFormat(SAVE_SCREEN* pSave)
{
	// Line 2751, Address: 0x2713f0, Func Offset: 0
	// Line 2753, Address: 0x2713f8, Func Offset: 0x8
	// Line 2755, Address: 0x271400, Func Offset: 0x10
	// Line 2758, Address: 0x271408, Func Offset: 0x18
	// Func End, Address: 0x271410, Func Offset: 0x20
}

// 
// Start address: 0x271410
void ExecuteStateSaveScreenErrFormat(SAVE_SCREEN* pSave)
{
	// Line 2773, Address: 0x271410, Func Offset: 0
	// Line 2774, Address: 0x271418, Func Offset: 0x8
	// Line 2777, Address: 0x271434, Func Offset: 0x24
	// Line 2779, Address: 0x27143c, Func Offset: 0x2c
	// Line 2780, Address: 0x271448, Func Offset: 0x38
	// Line 2784, Address: 0x271450, Func Offset: 0x40
	// Line 2787, Address: 0x27146c, Func Offset: 0x5c
	// Line 2790, Address: 0x271474, Func Offset: 0x64
	// Func End, Address: 0x271480, Func Offset: 0x70
}

// 
// Start address: 0x271480
void SetStateSaveScreenErrDer(SAVE_SCREEN* pSave)
{
	// Line 2807, Address: 0x271480, Func Offset: 0
	// Line 2809, Address: 0x271488, Func Offset: 0x8
	// Line 2811, Address: 0x271490, Func Offset: 0x10
	// Line 2812, Address: 0x271494, Func Offset: 0x14
	// Func End, Address: 0x27149c, Func Offset: 0x1c
}

// 
// Start address: 0x2714a0
void ExecuteStateSaveScreenErrDer(SAVE_SCREEN* pSave)
{
	// Line 2827, Address: 0x2714a0, Func Offset: 0
	// Line 2828, Address: 0x2714a8, Func Offset: 0x8
	// Line 2831, Address: 0x2714c8, Func Offset: 0x28
	// Line 2833, Address: 0x2714d0, Func Offset: 0x30
	// Line 2834, Address: 0x2714dc, Func Offset: 0x3c
	// Line 2838, Address: 0x2714e4, Func Offset: 0x44
	// Line 2841, Address: 0x271500, Func Offset: 0x60
	// Line 2844, Address: 0x271508, Func Offset: 0x68
	// Func End, Address: 0x271514, Func Offset: 0x74
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
