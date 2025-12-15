#include "ps2_LoadScreen.h"
#include "message.h"
#include "ps2_McSaveFile.h"
#include "ps2_MemoryCard.h"

SELECTFILEWINDOW SelectFileWindow;
SELECTFILEINFO SelectFileInfo[15];
char* cpNameList[18];
ICONINFORMATION IconInfo;
MEMORYCARDSTATE McState;
SAVEFILE SaveFile;
CONFIGFILE ConfigFile;
SYS_WORK* sys;

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

// 
// Start address: 0x275a00
void ExecuteStateLoadScreenAwarenessCard(LOAD_SCREEN* pLoad)
{
	int lPort1State;
	int lPort0State;
	// Line 386, Address: 0x275a00, Func Offset: 0
	// Line 389, Address: 0x275a10, Func Offset: 0x10
	// Line 393, Address: 0x275a4c, Func Offset: 0x4c
	// Line 395, Address: 0x275a58, Func Offset: 0x58
	// Line 397, Address: 0x275a68, Func Offset: 0x68
	// Line 400, Address: 0x275a7c, Func Offset: 0x7c
	// Line 401, Address: 0x275a88, Func Offset: 0x88
	// Line 403, Address: 0x275a90, Func Offset: 0x90
	// Line 407, Address: 0x275ab4, Func Offset: 0xb4
	// Line 408, Address: 0x275ac0, Func Offset: 0xc0
	// Line 413, Address: 0x275ac8, Func Offset: 0xc8
	// Line 415, Address: 0x275ad4, Func Offset: 0xd4
	// Line 418, Address: 0x275adc, Func Offset: 0xdc
	// Line 419, Address: 0x275ae4, Func Offset: 0xe4
	// Line 422, Address: 0x275aec, Func Offset: 0xec
	// Line 423, Address: 0x275af4, Func Offset: 0xf4
	// Line 426, Address: 0x275afc, Func Offset: 0xfc
	// Line 429, Address: 0x275b04, Func Offset: 0x104
	// Func End, Address: 0x275b18, Func Offset: 0x118
}

// 
// Start address: 0x275b20
void SetStateLoadScreenErrLostCard(LOAD_SCREEN* pLoad)
{
	// Line 446, Address: 0x275b20, Func Offset: 0
	// Line 448, Address: 0x275b28, Func Offset: 0x8
	// Line 451, Address: 0x275b2c, Func Offset: 0xc
	// Func End, Address: 0x275b34, Func Offset: 0x14
}

// 
// Start address: 0x275b40
void ExecuteStateLoadScreenErrLostCard(LOAD_SCREEN* pLoad)
{
	int lPort1State;
	int lPort0State;
	// Line 466, Address: 0x275b40, Func Offset: 0
	// Line 470, Address: 0x275b50, Func Offset: 0x10
	// Line 473, Address: 0x275b70, Func Offset: 0x30
	// Line 475, Address: 0x275b78, Func Offset: 0x38
	// Line 476, Address: 0x275b84, Func Offset: 0x44
	// Line 480, Address: 0x275b8c, Func Offset: 0x4c
	// Line 484, Address: 0x275bbc, Func Offset: 0x7c
	// Line 486, Address: 0x275bc8, Func Offset: 0x88
	// Line 488, Address: 0x275bd8, Func Offset: 0x98
	// Line 491, Address: 0x275bec, Func Offset: 0xac
	// Line 492, Address: 0x275bf8, Func Offset: 0xb8
	// Line 494, Address: 0x275c00, Func Offset: 0xc0
	// Line 498, Address: 0x275c24, Func Offset: 0xe4
	// Line 500, Address: 0x275c30, Func Offset: 0xf0
	// Line 503, Address: 0x275c38, Func Offset: 0xf8
	// Line 504, Address: 0x275c40, Func Offset: 0x100
	// Line 507, Address: 0x275c48, Func Offset: 0x108
	// Line 511, Address: 0x275c50, Func Offset: 0x110
	// Func End, Address: 0x275c64, Func Offset: 0x124
}

// 
// Start address: 0x275c70
void SetStateLoadScreenErrUnPS2MemCard(LOAD_SCREEN* pLoad)
{
	// Line 528, Address: 0x275c70, Func Offset: 0
	// Line 530, Address: 0x275c78, Func Offset: 0x8
	// Line 533, Address: 0x275c7c, Func Offset: 0xc
	// Func End, Address: 0x275c84, Func Offset: 0x14
}

// 
// Start address: 0x275c90
void ExecuteStateLoadScreenErrUnPS2MemCard(LOAD_SCREEN* pLoad)
{
	int lPort1State;
	int lPort0State;
	// Line 548, Address: 0x275c90, Func Offset: 0
	// Line 552, Address: 0x275ca0, Func Offset: 0x10
	// Line 555, Address: 0x275cc0, Func Offset: 0x30
	// Line 557, Address: 0x275cc8, Func Offset: 0x38
	// Line 558, Address: 0x275cd4, Func Offset: 0x44
	// Line 562, Address: 0x275cdc, Func Offset: 0x4c
	// Line 566, Address: 0x275d0c, Func Offset: 0x7c
	// Line 568, Address: 0x275d18, Func Offset: 0x88
	// Line 570, Address: 0x275d28, Func Offset: 0x98
	// Line 573, Address: 0x275d3c, Func Offset: 0xac
	// Line 574, Address: 0x275d48, Func Offset: 0xb8
	// Line 575, Address: 0x275d50, Func Offset: 0xc0
	// Line 578, Address: 0x275d60, Func Offset: 0xd0
	// Line 580, Address: 0x275d68, Func Offset: 0xd8
	// Line 583, Address: 0x275d70, Func Offset: 0xe0
	// Line 584, Address: 0x275d78, Func Offset: 0xe8
	// Line 587, Address: 0x275d80, Func Offset: 0xf0
	// Line 591, Address: 0x275d88, Func Offset: 0xf8
	// Func End, Address: 0x275d9c, Func Offset: 0x10c
}

// 
// Start address: 0x275da0
void SetStateLoadScreenSelectCard(LOAD_SCREEN* pLoad)
{
	// Line 606, Address: 0x275da0, Func Offset: 0
	// Line 608, Address: 0x275dac, Func Offset: 0xc
	// Line 610, Address: 0x275db4, Func Offset: 0x14
	// Line 612, Address: 0x275db8, Func Offset: 0x18
	// Line 614, Address: 0x275dbc, Func Offset: 0x1c
	// Line 616, Address: 0x275dc4, Func Offset: 0x24
	// Line 618, Address: 0x275dc8, Func Offset: 0x28
	// Line 620, Address: 0x275dd4, Func Offset: 0x34
	// Line 621, Address: 0x275ddc, Func Offset: 0x3c
	// Func End, Address: 0x275dec, Func Offset: 0x4c
}

// 
// Start address: 0x275df0
void ExecuteStateLoadScreenSelectCard(LOAD_SCREEN* pLoad)
{
	// Line 636, Address: 0x275df0, Func Offset: 0
	// Line 639, Address: 0x275dfc, Func Offset: 0xc
	// Line 642, Address: 0x275e20, Func Offset: 0x30
	// Line 644, Address: 0x275e24, Func Offset: 0x34
	// Line 642, Address: 0x275e2c, Func Offset: 0x3c
	// Line 644, Address: 0x275e30, Func Offset: 0x40
	// Line 645, Address: 0x275e38, Func Offset: 0x48
	// Line 646, Address: 0x275e40, Func Offset: 0x50
	// Line 649, Address: 0x275e4c, Func Offset: 0x5c
	// Line 651, Address: 0x275e50, Func Offset: 0x60
	// Line 649, Address: 0x275e58, Func Offset: 0x68
	// Line 651, Address: 0x275e5c, Func Offset: 0x6c
	// Line 654, Address: 0x275e64, Func Offset: 0x74
	// Line 657, Address: 0x275e70, Func Offset: 0x80
	// Line 660, Address: 0x275e7c, Func Offset: 0x8c
	// Line 664, Address: 0x275eac, Func Offset: 0xbc
	// Line 667, Address: 0x275ecc, Func Offset: 0xdc
	// Line 669, Address: 0x275ed0, Func Offset: 0xe0
	// Line 667, Address: 0x275ed4, Func Offset: 0xe4
	// Line 669, Address: 0x275ed8, Func Offset: 0xe8
	// Line 670, Address: 0x275ee0, Func Offset: 0xf0
	// Line 672, Address: 0x275ee8, Func Offset: 0xf8
	// Line 675, Address: 0x275ef4, Func Offset: 0x104
	// Line 677, Address: 0x275ef8, Func Offset: 0x108
	// Line 675, Address: 0x275efc, Func Offset: 0x10c
	// Line 677, Address: 0x275f00, Func Offset: 0x110
	// Line 680, Address: 0x275f08, Func Offset: 0x118
	// Line 682, Address: 0x275f14, Func Offset: 0x124
	// Line 687, Address: 0x275f1c, Func Offset: 0x12c
	// Line 690, Address: 0x275f3c, Func Offset: 0x14c
	// Line 693, Address: 0x275f4c, Func Offset: 0x15c
	// Line 694, Address: 0x275f54, Func Offset: 0x164
	// Line 698, Address: 0x275f5c, Func Offset: 0x16c
	// Line 701, Address: 0x275f68, Func Offset: 0x178
	// Line 702, Address: 0x275f74, Func Offset: 0x184
	// Line 704, Address: 0x275f7c, Func Offset: 0x18c
	// Line 707, Address: 0x275f88, Func Offset: 0x198
	// Line 709, Address: 0x275f90, Func Offset: 0x1a0
	// Line 710, Address: 0x275f9c, Func Offset: 0x1ac
	// Line 714, Address: 0x275fa4, Func Offset: 0x1b4
	// Line 717, Address: 0x275fc0, Func Offset: 0x1d0
	// Line 730, Address: 0x275fc8, Func Offset: 0x1d8
	// Func End, Address: 0x275fd8, Func Offset: 0x1e8
}

// 
// Start address: 0x275fe0
void SetStateLoadScreenTitleExit(LOAD_SCREEN* pLoad)
{
	// Line 747, Address: 0x275fe0, Func Offset: 0
	// Line 749, Address: 0x275fe8, Func Offset: 0x8
	// Line 751, Address: 0x275ff0, Func Offset: 0x10
	// Line 753, Address: 0x275ff4, Func Offset: 0x14
	// Line 754, Address: 0x275ff8, Func Offset: 0x18
	// Func End, Address: 0x276000, Func Offset: 0x20
}

// 
// Start address: 0x276000
void ExecuteStateLoadScreenTitleExit(LOAD_SCREEN* pLoad)
{
	// Line 773, Address: 0x276000, Func Offset: 0
	// Line 775, Address: 0x276010, Func Offset: 0x10
	// Line 777, Address: 0x276018, Func Offset: 0x18
	// Func End, Address: 0x276020, Func Offset: 0x20
}

// 
// Start address: 0x276020
void SetStateLoadScreenErrUnFormat(LOAD_SCREEN* pLoad)
{
	// Line 794, Address: 0x276020, Func Offset: 0
	// Line 796, Address: 0x276028, Func Offset: 0x8
	// Line 798, Address: 0x276030, Func Offset: 0x10
	// Line 800, Address: 0x276038, Func Offset: 0x18
	// Func End, Address: 0x276044, Func Offset: 0x24
}

// 
// Start address: 0x276050
void ExecuteStateLoadScreenErrUnFormat(LOAD_SCREEN* pLoad)
{
	// Line 815, Address: 0x276050, Func Offset: 0
	// Line 817, Address: 0x276058, Func Offset: 0x8
	// Line 820, Address: 0x276078, Func Offset: 0x28
	// Line 822, Address: 0x276080, Func Offset: 0x30
	// Line 823, Address: 0x27608c, Func Offset: 0x3c
	// Line 827, Address: 0x276094, Func Offset: 0x44
	// Line 830, Address: 0x2760b0, Func Offset: 0x60
	// Line 833, Address: 0x2760b8, Func Offset: 0x68
	// Func End, Address: 0x2760c4, Func Offset: 0x74
}

// 
// Start address: 0x2760d0
void SetStateLoadScreenErrLostDirCheck(LOAD_SCREEN* pLoad)
{
	// Line 850, Address: 0x2760d0, Func Offset: 0
	// Line 852, Address: 0x2760d8, Func Offset: 0x8
	// Line 854, Address: 0x2760e0, Func Offset: 0x10
	// Line 855, Address: 0x2760e4, Func Offset: 0x14
	// Func End, Address: 0x2760ec, Func Offset: 0x1c
}

// 
// Start address: 0x2760f0
void ExecuteStateLoadScreenErrLostDirCheck(LOAD_SCREEN* pLoad)
{
	// Line 870, Address: 0x2760f0, Func Offset: 0
	// Line 872, Address: 0x2760f8, Func Offset: 0x8
	// Line 875, Address: 0x276118, Func Offset: 0x28
	// Line 877, Address: 0x276120, Func Offset: 0x30
	// Line 878, Address: 0x27612c, Func Offset: 0x3c
	// Line 882, Address: 0x276134, Func Offset: 0x44
	// Line 885, Address: 0x276150, Func Offset: 0x60
	// Line 888, Address: 0x276158, Func Offset: 0x68
	// Func End, Address: 0x276164, Func Offset: 0x74
}

// 
// Start address: 0x276170
void SetStateLoadScreenDirCheck(LOAD_SCREEN* pLoad)
{
	// Line 903, Address: 0x276170, Func Offset: 0
	// Line 905, Address: 0x27617c, Func Offset: 0xc
	// Line 907, Address: 0x276184, Func Offset: 0x14
	// Line 909, Address: 0x27618c, Func Offset: 0x1c
	// Line 911, Address: 0x276194, Func Offset: 0x24
	// Line 915, Address: 0x276198, Func Offset: 0x28
	// Line 913, Address: 0x27619c, Func Offset: 0x2c
	// Line 915, Address: 0x2761a4, Func Offset: 0x34
	// Line 917, Address: 0x2761a8, Func Offset: 0x38
	// Line 919, Address: 0x2761b4, Func Offset: 0x44
	// Line 921, Address: 0x2761c0, Func Offset: 0x50
	// Line 922, Address: 0x2761cc, Func Offset: 0x5c
	// Func End, Address: 0x2761dc, Func Offset: 0x6c
}

// 
// Start address: 0x2761e0
void ExecuteStateLoadScreenDirCheck(LOAD_SCREEN* pLoad)
{
	int lResult;
	// Line 937, Address: 0x2761e0, Func Offset: 0
	// Line 940, Address: 0x2761ec, Func Offset: 0xc
	// Line 944, Address: 0x276218, Func Offset: 0x38
	// Line 946, Address: 0x276220, Func Offset: 0x40
	// Line 948, Address: 0x27622c, Func Offset: 0x4c
	// Line 951, Address: 0x27623c, Func Offset: 0x5c
	// Line 953, Address: 0x276244, Func Offset: 0x64
	// Line 956, Address: 0x27624c, Func Offset: 0x6c
	// Line 960, Address: 0x276254, Func Offset: 0x74
	// Line 962, Address: 0x27625c, Func Offset: 0x7c
	// Line 965, Address: 0x276264, Func Offset: 0x84
	// Line 967, Address: 0x276270, Func Offset: 0x90
	// Line 969, Address: 0x276278, Func Offset: 0x98
	// Line 971, Address: 0x27627c, Func Offset: 0x9c
	// Line 975, Address: 0x276284, Func Offset: 0xa4
	// Line 976, Address: 0x27628c, Func Offset: 0xac
	// Line 979, Address: 0x276298, Func Offset: 0xb8
	// Line 980, Address: 0x27629c, Func Offset: 0xbc
	// Line 981, Address: 0x2762a4, Func Offset: 0xc4
	// Line 984, Address: 0x2762ac, Func Offset: 0xcc
	// Line 986, Address: 0x2762b8, Func Offset: 0xd8
	// Line 988, Address: 0x2762bc, Func Offset: 0xdc
	// Line 992, Address: 0x2762c4, Func Offset: 0xe4
	// Line 993, Address: 0x2762d8, Func Offset: 0xf8
	// Line 995, Address: 0x2762e0, Func Offset: 0x100
	// Line 997, Address: 0x2762e8, Func Offset: 0x108
	// Line 999, Address: 0x2762f4, Func Offset: 0x114
	// Line 1000, Address: 0x2762fc, Func Offset: 0x11c
	// Line 1001, Address: 0x276304, Func Offset: 0x124
	// Line 1006, Address: 0x27630c, Func Offset: 0x12c
	// Line 1010, Address: 0x276314, Func Offset: 0x134
	// Line 1015, Address: 0x276338, Func Offset: 0x158
	// Line 1018, Address: 0x276340, Func Offset: 0x160
	// Line 1019, Address: 0x276350, Func Offset: 0x170
	// Line 1022, Address: 0x27635c, Func Offset: 0x17c
	// Line 1023, Address: 0x27636c, Func Offset: 0x18c
	// Line 1026, Address: 0x276388, Func Offset: 0x1a8
	// Line 1027, Address: 0x276390, Func Offset: 0x1b0
	// Line 1033, Address: 0x276398, Func Offset: 0x1b8
	// Line 1034, Address: 0x2763a0, Func Offset: 0x1c0
	// Line 1037, Address: 0x2763a8, Func Offset: 0x1c8
	// Line 1039, Address: 0x2763b0, Func Offset: 0x1d0
	// Line 1041, Address: 0x2763bc, Func Offset: 0x1dc
	// Line 1043, Address: 0x2763c4, Func Offset: 0x1e4
	// Line 1046, Address: 0x2763cc, Func Offset: 0x1ec
	// Line 1049, Address: 0x2763dc, Func Offset: 0x1fc
	// Line 1051, Address: 0x2763e4, Func Offset: 0x204
	// Line 1054, Address: 0x2763ec, Func Offset: 0x20c
	// Line 1057, Address: 0x2763fc, Func Offset: 0x21c
	// Line 1062, Address: 0x276404, Func Offset: 0x224
	// Line 1065, Address: 0x27641c, Func Offset: 0x23c
	// Line 1067, Address: 0x276424, Func Offset: 0x244
	// Func End, Address: 0x276434, Func Offset: 0x254
}

// 
// Start address: 0x276440
void SetStateLoadScreenDirFileBroken(LOAD_SCREEN* pLoad)
{
	// Line 1084, Address: 0x276440, Func Offset: 0
	// Line 1086, Address: 0x276448, Func Offset: 0x8
	// Line 1088, Address: 0x276450, Func Offset: 0x10
	// Line 1089, Address: 0x276454, Func Offset: 0x14
	// Func End, Address: 0x27645c, Func Offset: 0x1c
}

// 
// Start address: 0x276460
void ExecuteStateLoadScreenDirFileBroken(LOAD_SCREEN* pLoad)
{
	// Line 1104, Address: 0x276460, Func Offset: 0
	// Line 1105, Address: 0x276468, Func Offset: 0x8
	// Line 1108, Address: 0x276488, Func Offset: 0x28
	// Line 1110, Address: 0x276490, Func Offset: 0x30
	// Line 1111, Address: 0x27649c, Func Offset: 0x3c
	// Line 1115, Address: 0x2764a4, Func Offset: 0x44
	// Line 1118, Address: 0x2764c0, Func Offset: 0x60
	// Line 1121, Address: 0x2764c8, Func Offset: 0x68
	// Func End, Address: 0x2764d4, Func Offset: 0x74
}

// 
// Start address: 0x2764e0
void SetStateLoadScreenSelectFile(LOAD_SCREEN* pLoad)
{
	// Line 1136, Address: 0x2764e0, Func Offset: 0
	// Line 1138, Address: 0x2764ec, Func Offset: 0xc
	// Line 1140, Address: 0x2764f4, Func Offset: 0x14
	// Line 1142, Address: 0x2764fc, Func Offset: 0x1c
	// Line 1144, Address: 0x276508, Func Offset: 0x28
	// Line 1146, Address: 0x27650c, Func Offset: 0x2c
	// Line 1148, Address: 0x276518, Func Offset: 0x38
	// Line 1150, Address: 0x27651c, Func Offset: 0x3c
	// Line 1151, Address: 0x276528, Func Offset: 0x48
	// Func End, Address: 0x276538, Func Offset: 0x58
}

// 
// Start address: 0x276540
void ExecuteStateLoadScreenSelectFile(LOAD_SCREEN* pLoad)
{
	unsigned int KeyWait01;
	unsigned int KeyWait00;
	// Line 1166, Address: 0x276540, Func Offset: 0
	// Line 1171, Address: 0x27654c, Func Offset: 0xc
	// Line 1173, Address: 0x27656c, Func Offset: 0x2c
	// Line 1175, Address: 0x276588, Func Offset: 0x48
	// Line 1177, Address: 0x27659c, Func Offset: 0x5c
	// Line 1178, Address: 0x2765ac, Func Offset: 0x6c
	// Line 1181, Address: 0x2765b4, Func Offset: 0x74
	// Line 1183, Address: 0x2765bc, Func Offset: 0x7c
	// Line 1186, Address: 0x2765c4, Func Offset: 0x84
	// Line 1187, Address: 0x2765cc, Func Offset: 0x8c
	// Line 1189, Address: 0x2765d4, Func Offset: 0x94
	// Line 1191, Address: 0x2765fc, Func Offset: 0xbc
	// Line 1192, Address: 0x276604, Func Offset: 0xc4
	// Line 1194, Address: 0x276614, Func Offset: 0xd4
	// Line 1196, Address: 0x276620, Func Offset: 0xe0
	// Line 1198, Address: 0x27662c, Func Offset: 0xec
	// Line 1199, Address: 0x276638, Func Offset: 0xf8
	// Line 1201, Address: 0x276644, Func Offset: 0x104
	// Line 1203, Address: 0x27664c, Func Offset: 0x10c
	// Line 1204, Address: 0x276658, Func Offset: 0x118
	// Line 1205, Address: 0x276660, Func Offset: 0x120
	// Line 1209, Address: 0x276670, Func Offset: 0x130
	// Line 1211, Address: 0x27667c, Func Offset: 0x13c
	// Line 1212, Address: 0x276688, Func Offset: 0x148
	// Line 1213, Address: 0x276690, Func Offset: 0x150
	// Line 1215, Address: 0x27669c, Func Offset: 0x15c
	// Line 1217, Address: 0x2766a8, Func Offset: 0x168
	// Line 1219, Address: 0x2766b4, Func Offset: 0x174
	// Line 1221, Address: 0x2766c0, Func Offset: 0x180
	// Line 1223, Address: 0x2766d0, Func Offset: 0x190
	// Line 1225, Address: 0x2766d4, Func Offset: 0x194
	// Line 1226, Address: 0x2766e0, Func Offset: 0x1a0
	// Line 1227, Address: 0x2766e8, Func Offset: 0x1a8
	// Line 1230, Address: 0x2766fc, Func Offset: 0x1bc
	// Line 1232, Address: 0x276708, Func Offset: 0x1c8
	// Line 1235, Address: 0x276714, Func Offset: 0x1d4
	// Line 1238, Address: 0x27671c, Func Offset: 0x1dc
	// Line 1241, Address: 0x276728, Func Offset: 0x1e8
	// Line 1242, Address: 0x276730, Func Offset: 0x1f0
	// Line 1243, Address: 0x276738, Func Offset: 0x1f8
	// Line 1246, Address: 0x276744, Func Offset: 0x204
	// Line 1248, Address: 0x27674c, Func Offset: 0x20c
	// Line 1254, Address: 0x276758, Func Offset: 0x218
	// Line 1257, Address: 0x276774, Func Offset: 0x234
	// Line 1261, Address: 0x27677c, Func Offset: 0x23c
	// Line 1263, Address: 0x276790, Func Offset: 0x250
	// Line 1266, Address: 0x276794, Func Offset: 0x254
	// Line 1268, Address: 0x2767b8, Func Offset: 0x278
	// Line 1269, Address: 0x2767d0, Func Offset: 0x290
	// Line 1271, Address: 0x2767e8, Func Offset: 0x2a8
	// Func End, Address: 0x2767f8, Func Offset: 0x2b8
}

// 
// Start address: 0x276800
void LoadScreenCheckSave(LOAD_SCREEN* pLoad)
{
	// Line 1286, Address: 0x276800, Func Offset: 0
	// Line 1288, Address: 0x27680c, Func Offset: 0xc
	// Line 1291, Address: 0x27681c, Func Offset: 0x1c
	// Line 1294, Address: 0x276830, Func Offset: 0x30
	// Line 1296, Address: 0x276838, Func Offset: 0x38
	// Line 1297, Address: 0x276844, Func Offset: 0x44
	// Line 1302, Address: 0x27684c, Func Offset: 0x4c
	// Line 1304, Address: 0x276858, Func Offset: 0x58
	// Line 1306, Address: 0x276864, Func Offset: 0x64
	// Func End, Address: 0x276874, Func Offset: 0x74
}

// 
// Start address: 0x276880
void SetStateLoadScreenNoSave(LOAD_SCREEN* pLoad)
{
	// Line 1323, Address: 0x276880, Func Offset: 0
	// Line 1325, Address: 0x276888, Func Offset: 0x8
	// Line 1327, Address: 0x276890, Func Offset: 0x10
	// Line 1328, Address: 0x276894, Func Offset: 0x14
	// Func End, Address: 0x27689c, Func Offset: 0x1c
}

// 
// Start address: 0x2768a0
void ExecuteStateLoadScreenNoSave(LOAD_SCREEN* pLoad)
{
	// Line 1343, Address: 0x2768a0, Func Offset: 0
	// Line 1345, Address: 0x2768a8, Func Offset: 0x8
	// Line 1348, Address: 0x2768c8, Func Offset: 0x28
	// Line 1350, Address: 0x2768d0, Func Offset: 0x30
	// Line 1351, Address: 0x2768dc, Func Offset: 0x3c
	// Line 1355, Address: 0x2768e4, Func Offset: 0x44
	// Line 1358, Address: 0x276900, Func Offset: 0x60
	// Line 1361, Address: 0x276908, Func Offset: 0x68
	// Func End, Address: 0x276914, Func Offset: 0x74
}

// 
// Start address: 0x276920
void SetStateLoadScreenLoadCursor(LOAD_SCREEN* pLoad)
{
	// Line 1378, Address: 0x276920, Func Offset: 0
	// Line 1380, Address: 0x276928, Func Offset: 0x8
	// Line 1382, Address: 0x276930, Func Offset: 0x10
	// Line 1385, Address: 0x276938, Func Offset: 0x18
	// Func End, Address: 0x276940, Func Offset: 0x20
}

// 
// Start address: 0x276940
void ExecuteStateLoadScreenLoadCursor(LOAD_SCREEN* pLoad)
{
	// Line 1400, Address: 0x276940, Func Offset: 0
	// Line 1404, Address: 0x276948, Func Offset: 0x8
	// Line 1407, Address: 0x276968, Func Offset: 0x28
	// Line 1411, Address: 0x27696c, Func Offset: 0x2c
	// Line 1407, Address: 0x276970, Func Offset: 0x30
	// Line 1409, Address: 0x276978, Func Offset: 0x38
	// Line 1411, Address: 0x276984, Func Offset: 0x44
	// Line 1412, Address: 0x27698c, Func Offset: 0x4c
	// Line 1414, Address: 0x276994, Func Offset: 0x54
	// Line 1417, Address: 0x2769a0, Func Offset: 0x60
	// Line 1421, Address: 0x2769a4, Func Offset: 0x64
	// Line 1417, Address: 0x2769a8, Func Offset: 0x68
	// Line 1419, Address: 0x2769b0, Func Offset: 0x70
	// Line 1421, Address: 0x2769bc, Func Offset: 0x7c
	// Line 1422, Address: 0x2769c4, Func Offset: 0x84
	// Line 1424, Address: 0x2769cc, Func Offset: 0x8c
	// Line 1426, Address: 0x2769d8, Func Offset: 0x98
	// Line 1429, Address: 0x2769e8, Func Offset: 0xa8
	// Line 1431, Address: 0x2769f0, Func Offset: 0xb0
	// Line 1432, Address: 0x2769fc, Func Offset: 0xbc
	// Line 1436, Address: 0x276a04, Func Offset: 0xc4
	// Line 1438, Address: 0x276a0c, Func Offset: 0xcc
	// Line 1440, Address: 0x276a18, Func Offset: 0xd8
	// Line 1442, Address: 0x276a20, Func Offset: 0xe0
	// Line 1445, Address: 0x276a2c, Func Offset: 0xec
	// Line 1447, Address: 0x276a34, Func Offset: 0xf4
	// Line 1448, Address: 0x276a40, Func Offset: 0x100
	// Line 1452, Address: 0x276a48, Func Offset: 0x108
	// Line 1455, Address: 0x276a64, Func Offset: 0x124
	// Line 1458, Address: 0x276a6c, Func Offset: 0x12c
	// Func End, Address: 0x276a78, Func Offset: 0x138
}

// 
// Start address: 0x276a80
void SetStateLoadScreenLoad(LOAD_SCREEN* pLoad)
{
	// Line 1475, Address: 0x276a80, Func Offset: 0
	// Line 1479, Address: 0x276a88, Func Offset: 0x8
	// Line 1477, Address: 0x276a8c, Func Offset: 0xc
	// Line 1481, Address: 0x276a90, Func Offset: 0x10
	// Line 1479, Address: 0x276a94, Func Offset: 0x14
	// Line 1481, Address: 0x276a98, Func Offset: 0x18
	// Line 1483, Address: 0x276a9c, Func Offset: 0x1c
	// Func End, Address: 0x276aa4, Func Offset: 0x24
}

// 
// Start address: 0x276ab0
void ExecuteStateLoadScreenLoad(LOAD_SCREEN* pLoad)
{
	int lFileNumber;
	int lResult;
	// Line 1499, Address: 0x276ab0, Func Offset: 0
	// Line 1502, Address: 0x276abc, Func Offset: 0xc
	// Line 1507, Address: 0x276af4, Func Offset: 0x44
	// Line 1509, Address: 0x276afc, Func Offset: 0x4c
	// Line 1514, Address: 0x276b20, Func Offset: 0x70
	// Line 1517, Address: 0x276b28, Func Offset: 0x78
	// Line 1519, Address: 0x276b34, Func Offset: 0x84
	// Line 1522, Address: 0x276b40, Func Offset: 0x90
	// Line 1523, Address: 0x276b48, Func Offset: 0x98
	// Line 1525, Address: 0x276b50, Func Offset: 0xa0
	// Line 1528, Address: 0x276b5c, Func Offset: 0xac
	// Line 1530, Address: 0x276b68, Func Offset: 0xb8
	// Line 1532, Address: 0x276b70, Func Offset: 0xc0
	// Line 1533, Address: 0x276b74, Func Offset: 0xc4
	// Line 1535, Address: 0x276b7c, Func Offset: 0xcc
	// Line 1538, Address: 0x276b88, Func Offset: 0xd8
	// Line 1540, Address: 0x276b94, Func Offset: 0xe4
	// Line 1542, Address: 0x276b9c, Func Offset: 0xec
	// Line 1544, Address: 0x276ba0, Func Offset: 0xf0
	// Line 1547, Address: 0x276ba8, Func Offset: 0xf8
	// Line 1550, Address: 0x276bb8, Func Offset: 0x108
	// Line 1552, Address: 0x276bc0, Func Offset: 0x110
	// Line 1555, Address: 0x276bc8, Func Offset: 0x118
	// Line 1558, Address: 0x276bd8, Func Offset: 0x128
	// Line 1562, Address: 0x276be0, Func Offset: 0x130
	// Func End, Address: 0x276bf0, Func Offset: 0x140
}

// 
// Start address: 0x276bf0
void SetStateLoadScreenFileBroken(LOAD_SCREEN* pLoad)
{
	// Line 1579, Address: 0x276bf0, Func Offset: 0
	// Line 1581, Address: 0x276bf8, Func Offset: 0x8
	// Line 1583, Address: 0x276c00, Func Offset: 0x10
	// Line 1584, Address: 0x276c04, Func Offset: 0x14
	// Func End, Address: 0x276c0c, Func Offset: 0x1c
}

// 
// Start address: 0x276c10
void ExecuteStateLoadScreenFileBroken(LOAD_SCREEN* pLoad)
{
	// Line 1599, Address: 0x276c10, Func Offset: 0
	// Line 1600, Address: 0x276c18, Func Offset: 0x8
	// Line 1603, Address: 0x276c38, Func Offset: 0x28
	// Line 1605, Address: 0x276c40, Func Offset: 0x30
	// Line 1606, Address: 0x276c4c, Func Offset: 0x3c
	// Line 1610, Address: 0x276c54, Func Offset: 0x44
	// Line 1613, Address: 0x276c70, Func Offset: 0x60
	// Line 1616, Address: 0x276c78, Func Offset: 0x68
	// Func End, Address: 0x276c84, Func Offset: 0x74
}

// 
// Start address: 0x276c90
void SetStateLoadScreenErrCardRead(LOAD_SCREEN* pLoad)
{
	// Line 1633, Address: 0x276c90, Func Offset: 0
	// Line 1635, Address: 0x276c98, Func Offset: 0x8
	// Line 1637, Address: 0x276ca0, Func Offset: 0x10
	// Line 1638, Address: 0x276ca4, Func Offset: 0x14
	// Func End, Address: 0x276cac, Func Offset: 0x1c
}

// 
// Start address: 0x276cb0
void ExecuteStateLoadScreenErrCardRead(LOAD_SCREEN* pLoad)
{
	// Line 1653, Address: 0x276cb0, Func Offset: 0
	// Line 1654, Address: 0x276cb8, Func Offset: 0x8
	// Line 1657, Address: 0x276cd8, Func Offset: 0x28
	// Line 1659, Address: 0x276ce0, Func Offset: 0x30
	// Line 1660, Address: 0x276cec, Func Offset: 0x3c
	// Line 1664, Address: 0x276cf4, Func Offset: 0x44
	// Line 1667, Address: 0x276d10, Func Offset: 0x60
	// Line 1670, Address: 0x276d18, Func Offset: 0x68
	// Func End, Address: 0x276d24, Func Offset: 0x74
}

// 
// Start address: 0x276d30
void SetStateLoadScreenLoadExit(LOAD_SCREEN* pLoad)
{
	// Line 1687, Address: 0x276d30, Func Offset: 0
	// Line 1689, Address: 0x276d38, Func Offset: 0x8
	// Line 1691, Address: 0x276d40, Func Offset: 0x10
	// Line 1693, Address: 0x276d44, Func Offset: 0x14
	// Line 1695, Address: 0x276d4c, Func Offset: 0x1c
	// Func End, Address: 0x276d58, Func Offset: 0x28
}

// 
// Start address: 0x276d60
void ExecuteStateLoadScreenLoadExit(LOAD_SCREEN* pLoad)
{
	// Line 1711, Address: 0x276d60, Func Offset: 0
	// Line 1715, Address: 0x276d6c, Func Offset: 0xc
	// Line 1718, Address: 0x276d80, Func Offset: 0x20
	// Line 1720, Address: 0x276d8c, Func Offset: 0x2c
	// Line 1722, Address: 0x276d94, Func Offset: 0x34
	// Line 1720, Address: 0x276d98, Func Offset: 0x38
	// Line 1722, Address: 0x276da4, Func Offset: 0x44
	// Line 1724, Address: 0x276da8, Func Offset: 0x48
	// Func End, Address: 0x276db8, Func Offset: 0x58
}

// 
// Start address: 0x276dc0
void SetDispLoadSelectMessage()
{
	// Line 1749, Address: 0x276dc0, Func Offset: 0
	// Line 1738, Address: 0x276dcc, Func Offset: 0xc
	// Line 1749, Address: 0x276dd0, Func Offset: 0x10
	// Line 1738, Address: 0x276dd8, Func Offset: 0x18
	// Line 1749, Address: 0x276ddc, Func Offset: 0x1c
	// Line 1751, Address: 0x276de4, Func Offset: 0x24
	// Line 1753, Address: 0x276e10, Func Offset: 0x50
	// Line 1754, Address: 0x276e3c, Func Offset: 0x7c
	// Line 1756, Address: 0x276e68, Func Offset: 0xa8
	// Line 1757, Address: 0x276e94, Func Offset: 0xd4
	// Line 1759, Address: 0x276ec4, Func Offset: 0x104
	// Line 1760, Address: 0x276ef4, Func Offset: 0x134
	// Line 1762, Address: 0x276f0c, Func Offset: 0x14c
	// Func End, Address: 0x276f18, Func Offset: 0x158
}

// 
// Start address: 0x276f20
void CheckDispLoadMemoryCard(LOAD_SCREEN* pLoad)
{
	int lPort1CurX;
	int lPort0CurX;
	int lPort1Card;
	int lPort0Card;
	// Line 1777, Address: 0x276f20, Func Offset: 0
	// Line 1782, Address: 0x276f38, Func Offset: 0x18
	// Line 1784, Address: 0x276f44, Func Offset: 0x24
	// Line 1787, Address: 0x276f54, Func Offset: 0x34
	// Line 1791, Address: 0x276f68, Func Offset: 0x48
	// Line 1790, Address: 0x276f6c, Func Offset: 0x4c
	// Line 1793, Address: 0x276f70, Func Offset: 0x50
	// Line 1791, Address: 0x276f74, Func Offset: 0x54
	// Line 1794, Address: 0x276f78, Func Offset: 0x58
	// Line 1796, Address: 0x276f80, Func Offset: 0x60
	// Line 1802, Address: 0x276f94, Func Offset: 0x74
	// Line 1800, Address: 0x276f98, Func Offset: 0x78
	// Line 1803, Address: 0x276f9c, Func Offset: 0x7c
	// Line 1799, Address: 0x276fa0, Func Offset: 0x80
	// Line 1804, Address: 0x276fa4, Func Offset: 0x84
	// Line 1806, Address: 0x276fac, Func Offset: 0x8c
	// Line 1811, Address: 0x276fc0, Func Offset: 0xa0
	// Line 1812, Address: 0x276fc4, Func Offset: 0xa4
	// Line 1808, Address: 0x276fc8, Func Offset: 0xa8
	// Line 1810, Address: 0x276fcc, Func Offset: 0xac
	// Line 1814, Address: 0x276fd0, Func Offset: 0xb0
	// Line 1823, Address: 0x276fd8, Func Offset: 0xb8
	// Line 1822, Address: 0x276fdc, Func Offset: 0xbc
	// Line 1818, Address: 0x276fe0, Func Offset: 0xc0
	// Line 1819, Address: 0x276fe4, Func Offset: 0xc4
	// Line 1820, Address: 0x276fe8, Func Offset: 0xc8
	// Line 1821, Address: 0x276fec, Func Offset: 0xcc
	// Line 1823, Address: 0x276ff0, Func Offset: 0xd0
	// Line 1826, Address: 0x276ff4, Func Offset: 0xd4
	// Line 1828, Address: 0x277004, Func Offset: 0xe4
	// Line 1829, Address: 0x277008, Func Offset: 0xe8
	// Line 1830, Address: 0x27700c, Func Offset: 0xec
	// Line 1831, Address: 0x277010, Func Offset: 0xf0
	// Line 1835, Address: 0x277014, Func Offset: 0xf4
	// Line 1836, Address: 0x27702c, Func Offset: 0x10c
	// Line 1838, Address: 0x277048, Func Offset: 0x128
	// Line 1839, Address: 0x2770a0, Func Offset: 0x180
	// Func End, Address: 0x2770b8, Func Offset: 0x198
}
