#include "ps2_McSaveFile.h"
#include "bup_00.h"
#include "flag.h"
#include "message.h" // TODO: in the original codebase, they forgot to include this, find a way to obtain a match
#include "ps2_MemoryCard..h"
#include "ps2_NaDraw.h"
#include "sdfunc.h"
#include "sub1.h"
#include "main.h"

//#include <string.h>

const int Type_Space[18][3] __attribute__((aligned(64))); // TODO: define data for this
static char cSubDirName[13] = "BASLUS-20184";
unsigned short MesNumTbl[10] = { 0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017, 0x0018, 0x0019 };

// 100% matching!
SELECTFILEINFO* mcSelectFileInfoInit(SELECTFILEINFO* pFileInfo)
{
    unsigned int ulCnt; 
    SELECTFILEINFO* pBackUpInfo; 

    pBackUpInfo = pFileInfo;

    for (ulCnt = 1; ulCnt < 16; ulCnt++, pFileInfo++) 
    {
        pFileInfo->save_ct = 0;
        
        pFileInfo->gm_mode = 0;
        
        pFileInfo->ply_id = 0;
        
        pFileInfo->saveroom = 0;
        
        pFileInfo->FileNumber = ulCnt;
    }
    
    return pBackUpInfo;
}

// 100% matching!
SAVEFILE* mcCreateSaveFileInit(SAVEFILE* pSaveFile)
{
    memset(pSaveFile, 0, sizeof(SAVEFILE));
    
    return pSaveFile;
}

// 100% matching!
CONFIGFILE* mcCreateConfigInit(CONFIGFILE* pConfigFile)
{
    pConfigFile->ssd_ver = 0;     
    
    pConfigFile->ssd_flg = 0;      
    
    pConfigFile->ssd_reserve = 0;    
    
    pConfigFile->keytype = 0;        
    
    pConfigFile->adjust_x = 0;       
    pConfigFile->adjust_y = 0;       
    
    pConfigFile->vibration = 1;      
    
    pConfigFile->best_tm[0] = 0;    
    pConfigFile->best_tm[1] = 0;    
    pConfigFile->best_tm[2] = 0;     
    pConfigFile->best_tm[3] = 0;    
    pConfigFile->best_tm[4] = 0;    
    pConfigFile->best_tm[5] = 0;     
    pConfigFile->best_tm[6] = 0;     
    pConfigFile->best_tm[7] = 0;   
    
    pConfigFile->Check_Sam = MemoryCardGetSum((unsigned char*)pConfigFile, (char*)&pConfigFile->Check_Sam - (char*)pConfigFile);
   
    return pConfigFile;
}

// 100% matching!
int mcGetSaveFileCapacitySize()
{
    return sizeof(SAVEFILE);
}

// 100% matching!
int mcReadStartSaveFile(SAVEFILE* pSaveFile, MEMORYCARDSTATE* pCard, char** cppFileName, unsigned int ulCreatSaveCount)
{
    if (ReadMemoryCard(pCard, pSaveFile, sizeof(SAVEFILE), cppFileName[ulCreatSaveCount + 3], 1) == 1) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
int mcCheckReadStartSaveFile(SAVEFILE* pSaveFile, MEMORYCARDSTATE* pCard, char cMode) 
{
    unsigned int ulDataSize; 
    int lResult; 

    lResult = RecoveryMemoryCardReadEnd(pCard);
    
    if (lResult == 1) 
    {
        ulDataSize = (char*)&pSaveFile->CheckSam - (char*)pSaveFile;
        
        if (pSaveFile->CheckSam != MemoryCardGetSum((unsigned char*)pSaveFile, ulDataSize))
        {
            return -2;
        }
        
        if (cMode == 1) 
        {
            memcpy(&sys->version, pSaveFile, ulDataSize);
        }
        
        return 1;
    }
    
    if (lResult == -1) 
    {
        return -1;
    }
    
    return 0;
}

// 100% matching!
int mcWriteStartSaveFile(SAVEFILE* pSaveFile, MEMORYCARDSTATE* pCard, char** cppFileName, unsigned int ulCreatSaveCount)
{
    unsigned int* wp; 
    unsigned int itemid; 
    unsigned int ulDataSize; 
    
    if (bhCkFlg(sys->ev_flg, 56) == 0)
    {
        if (sys->save_ct != 99) 
        {
            sys->save_ct++;
        }
        
        itemid = 31;
        
        wp = ItemSearch(itemid);
        
        if (wp != NULL) 
        {
            if (!((*wp >> 16) & 0x800)) 
            {
                if (((*wp - 1) & 0xFF)) 
                {
                    *wp -= 1;
                } 
                else 
                {
                    EraseItem(wp);
                }
            }
        }
    }
    else 
    {
        bhCrFlg(sys->ev_flg, 56);
        
        sys->stg_no = 6;
        sys->rom_no = 0;
        
        sys->rcase = 0;
        
        sys->pos_no = 0;
    }
    
    ulDataSize = (char*)&sys->save_end - (char*)&sys->version;
    
    memcpy(pSaveFile, &sys->version, ulDataSize);
    
    pSaveFile->CheckSam = MemoryCardGetSum((unsigned char*)pSaveFile, ulDataSize);
    
    if (WriteMemoryCard(pCard, pSaveFile, sizeof(SAVEFILE), cppFileName[ulCreatSaveCount + 3], 2) == 1) 
    {
        return 1;
    }
    
    return -1;
}

// 100% matching!
int mcCheckWriteStartSaveFile(MEMORYCARDSTATE* pCard)
{
    int lResult;
    
    lResult = RecoveryMemoryCardWriteEnd(pCard);
    
    if (lResult == 1)
    {
        return 1;
    }
    
    if (lResult == -1) 
    {
        bhStFlg(sys->ev_flg, 56);
        
        return -1;
    }
    
    return 0;
}

// 100% matching!
int mcNewCreateSaveFile(MEMORYCARDSTATE* pCard, SAVEFILE* pSaveFile, char** cppFileName, unsigned int ulCreatSaveCount)
{
    if (WriteMemoryCard(pCard, mcCreateSaveFileInit(pSaveFile), sizeof(SAVEFILE), cppFileName[ulCreatSaveCount + 3], 514) == 1)
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
int mcGetConfigCapacitySize() 
{
    return sizeof(CONFIGFILE);
} 

// 100% matching!
int mcReadStartConfigFile(MEMORYCARDSTATE* pCard, CONFIGFILE* pConfigFile)
{
    if (ReadMemoryCard(pCard, pConfigFile, sizeof(CONFIGFILE), cSubDirName, 1) == 1) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
int mcCheckReadStartConfigFile(MEMORYCARDSTATE* pCard, CONFIGFILE* pConfigFile)
{
	unsigned int ulDataSize;
    int lResult;

    lResult = RecoveryMemoryCardReadEnd(pCard);
    
    if (lResult == 1) 
    {
        ulDataSize = (char*)&pConfigFile->Check_Sam - (char*)pConfigFile;
        
        if (pConfigFile->Check_Sam != MemoryCardGetSum((unsigned char*)pConfigFile, ulDataSize)) 
        {
            return -2;
        }
        
        return ulDataSize;
    }
    
    if (lResult == -1)
    {
        return -1;
    }
    
    return 0;
}

// 100% matching!
int mcWriteStartConfigFile(MEMORYCARDSTATE* pCard, CONFIGFILE* pConfigFile) 
{
    unsigned int ulDataSize;
    
    ulDataSize = (char*)&sys->sys_partid - (char*)sys;
    
    memcpy(pConfigFile, sys, ulDataSize);
    
    pConfigFile->Check_Sam = MemoryCardGetSum((unsigned char*)pConfigFile, ulDataSize);
    
    if (WriteMemoryCard(pCard, pConfigFile, sizeof(CONFIGFILE), cSubDirName, 2) == 1) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
int mcCheckWriteStartConfigFile(MEMORYCARDSTATE* pCard) 
{
    int lResult;
    
    lResult = RecoveryMemoryCardWriteEnd(pCard);
    
    if (lResult == 1)
    {
        return 1;
    }
    
    if (lResult == -1) 
    {
        return -1;
    }
    
    return 0;
}

// 100% matching!
int mcNewCreateConfigFile(MEMORYCARDSTATE* pCard, CONFIGFILE* pConfigFile)
{
    if (WriteMemoryCard(pCard, mcCreateConfigInit(pConfigFile), sizeof(CONFIGFILE), cSubDirName, 514) == 1) 
    {
        return 1;
    }
    
    return 0;
}

// 99.33% matching
ICONINFORMATION* mcCreateIconInit(ICONINFORMATION* pIcon, char** cppFileName, unsigned int ulFileNamber)
{
    static int bgcolor[4][4] = {0}; 
    static float lightdir[3][4] = 
    {
        {0.5f, 0.5f, 0.5f, 0}, {-0.5f, -0.5f, -0.5f, 0}, {0, 0, 0, 0}
    }; 
    static float lightcol[3][4] = 
    {
        {0.5f, 0.5f, 0.6f, 0}, {0.5f, 0.5f, 0.6f, 0}, {0, 0, 0, 0}
    }; 
    static float ambient[4] = {0.2f, 0.2f, 0, 0}; 
    
    memset(pIcon, 0, sizeof(ICONINFORMATION));
    
    strcpy(pIcon, "PS2D");
    
    strcpy(pIcon->icon.TitleName, "‚q‚d‚r‚h‚c‚d‚m‚s@‚d‚u‚h‚k?‚b‚n‚c‚dF‚u‚…‚’‚‚Ž‚‰‚ƒ‚?‚w"); 
    
    pIcon->icon.OffsLF = 26;
    
    pIcon->icon.TransRate = 64;
    
    memcpy(pIcon->icon.BgColor, bgcolor, sizeof(int) * (4 * 4));
    
    memcpy(pIcon->icon.LightDir, lightdir, sizeof(float) * (3 * 4));
    memcpy(pIcon->icon.LightColor, lightcol, sizeof(float) * (3 * 4));
    
    memcpy(pIcon->icon.Ambient, ambient, sizeof(float) * 4);
    
    strcpy(pIcon->icon.FnameView, cppFileName[ulFileNamber]);
    strcpy(pIcon->icon.FnameCopy, cppFileName[ulFileNamber]);
    strcpy(pIcon->icon.FnameDel, cppFileName[ulFileNamber]);
    
    return pIcon;
}

// 100% matching!
int mcGetIconCapacitySize()
{
    return sizeof(ICONINFORMATION);
}

// 100% matching!
int mcGetIconFileCapacitySize()
{
    return 0xB3F8; // TODO: find the adecuate sizeof() calculation
}

// 100% matching!
int mcNewCreateIcon(ICONINFORMATION* pIcon, MEMORYCARDSTATE* pCard, char** cppFileName, unsigned int ulCreatSaveCount) 
{
    if (WriteMemoryCard(pCard, pIcon, sizeof(ICONINFORMATION), cppFileName[ulCreatSaveCount], 514) == 1) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
int mcReadIconData(void* vpReadAddr, char** cppIconFileName, int lFileNum)
{
    GDFS_HANDLE* FileHandle; 
    int lFileSize; 
    
    FileHandle = gdFsOpen(cppIconFileName[lFileNum], NULL);
    
    if (FileHandle == NULL) 
    {
        return 0;
    }
    
    if (gdFsGetFileSize(FileHandle, &lFileSize) == FALSE)
    {
        gdFsClose(FileHandle);
        
        return 0;
    }
    
    if (gdFsRead(FileHandle, (lFileSize + 2047) / 2048, vpReadAddr) != 0) 
    {
        gdFsClose(FileHandle);
        
        return 0;
    }
    
    gdFsClose(FileHandle);
    
    return lFileSize;
}

// 100% matching!
int mcWriteIconData(MEMORYCARDSTATE* pCard, void* vpWriteAddr, unsigned int ulDataSize, char** cppFileName, unsigned int ulCreatSaveCount)
{
    if (WriteMemoryCard(pCard, vpWriteAddr, ulDataSize, cppFileName[ulCreatSaveCount], 514) == 1) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
int mcGetFreeCapacitySize()
{
    unsigned int ulGetFileSizeMax; 
    unsigned int ulGetFileSize;
    
    ulGetFileSizeMax = 0;
    
    ulGetFileSizeMax += ((mcGetSaveFileCapacitySize() + 1023) / 1024) * 15;
    ulGetFileSizeMax += (mcGetConfigCapacitySize() + 1023) / 1024;
    ulGetFileSizeMax += (mcGetIconCapacitySize() + 1023) / 1024;
    ulGetFileSizeMax += (mcGetIconFileCapacitySize() + 1023) / 1024;

    ulGetFileSizeMax += 11;
    
    return ulGetFileSizeMax;
}

// 100% matching!
void mcGetPortSelectDirInfo(SAVEFILE* pSaveFile, SELECTFILEWINDOW* pWin, unsigned int ulCheckCounter)
{
    SELECTFILEINFO* pFileInfo; 
    int lCount; 
    
    pFileInfo = pWin->pRecordTop;
    
    for (lCount = 0; lCount < ulCheckCounter; lCount++, pFileInfo++);
    
    pFileInfo->saveroom = RoomNameSwitch(pSaveFile->rom_no + (pSaveFile->stg_no * 100));
    
    pFileInfo->gm_mode = pSaveFile->gm_mode;
    
    pFileInfo->save_ct = pSaveFile->save_ct;
    
    pFileInfo->ply_id = pSaveFile->ply_id;
}

// 100% matching!
int mcSelectSaveFileCheck(SELECTFILEWINDOW* pWin, unsigned short ulSaveCount)
{
    SELECTFILEINFO* pFileInfo; 
    unsigned short sCnt; 
    
    pFileInfo = pWin->pRecordTop;

    for (sCnt = 0; sCnt < ulSaveCount; sCnt++, pFileInfo++);
    
    if ((pFileInfo->save_ct == 0) && (pFileInfo->gm_mode == 0) && (pFileInfo->ply_id == 0) && (pFileInfo->saveroom == 0)) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
SELECTFILEWINDOW* mcCreateFileSelectWindow(SELECTFILEWINDOW* pWin, SELECTFILEINFO* pFileInfo, unsigned int ulRecord) 
{
    pWin->pRecordTop = pFileInfo;
    
    pWin->lRecordMax = ulRecord;
    
    pWin->ulFileState = 0;
    
    pWin->slDispTopNumber = 0;
    pWin->slDispRecordNumber = 5;
    
    pWin->sMesCur = 0;
    
    pWin->sCursol = 0;
    
    pWin->sWaitMesTimer = 6;
    
    pWin->slLineNumber = 40;
    
    pWin->slDispWriteMesMax = 0;
    pWin->slDispWriteMes = 0;
    
    pWin->ulfoundationColor = 0x18808080;
    
    return pWin;
}

// 100% matching!
void mcSetFileSelectWindowCursolInit(SELECTFILEWINDOW* pWin)
{
    pWin->sCursol = 0;
    
    pWin->sMesCur = 0;
    
    pWin->slDispTopNumber = 0;
}

// 100% matching!
void mcSetFileSelectWindowCursol(SELECTFILEWINDOW* pWin, int lCurInfo)
{
    switch (lCurInfo)
    {                               
    case -1:
        pWin->sCursol -= 1;
        break;
    case 0:
        pWin->sCursol = 0;
        break;
    case 1:
        pWin->sCursol += 1;
        break;
    case 4:
        pWin->sCursol = 4;
        break;
    }
}

// 100% matching!
int mcGetFileSelectWindowCursol(SELECTFILEWINDOW* pWin) 
{
    return pWin->sCursol;
}

// 99.82% matching
void mcDisplayFileSelectWindow(SELECTFILEWINDOW* pWin, float fX, float fY, unsigned int port)
{
    static unsigned int ulCall = 1; 
    SELECTFILEINFO* pFileInfo; 
    unsigned int ulDispCount; 

    bhDispMessage(140.0f, 32.0f, 0, 1, 463, 0, 0);
    bhDispMessage(420.0f, 32.0f, 0, 1, port + 464, 0, 0);

    mcDispWindowCurSol(pWin, 32.0f, 103.0f); 
    mcDispWindowFoundtion(16.0f, 96.0f, 616.0f, 310.0f, pWin->ulfoundationColor);

    pFileInfo = pWin->pRecordTop;

    for (ulDispCount = 0; ulDispCount < pWin->slDispRecordNumber; ulDispCount++) 
    {
        if ((pWin->ulFileState == 1) && (pWin->sCursol == ulDispCount)) 
        {
            if (ulCall == 1) 
            {
                pWin->slDispWriteMesMax = mcSetStringSaveFile(&pFileInfo[pWin->slDispTopNumber + ulDispCount]);
                
                ulCall = 0;
            }

            mcDisplaySelectFileInfoMesCount(&pFileInfo[pWin->slDispTopNumber + ulDispCount], fX, fY + (pWin->slLineNumber * ulDispCount), pWin->slDispWriteMes);
            
            if ((pWin->sWaitMesTimer % 6) == 0) 
            {
                mcCallMessageTypeSe(&pFileInfo[pWin->slDispTopNumber + ulDispCount], pWin->slDispWriteMes);
                
                pWin->slDispWriteMes++;
            } 
            else if (pWin->slDispWriteMes >= pWin->slDispWriteMesMax) 
            {
                ulCall = 1;
                
                CallSystemSe(0, 0x80000244); 
                
                pWin->slDispWriteMes++;
            }
            
            pWin->sWaitMesTimer++;
        } 
        else 
        {
            mcDisplaySelectFileInfo(&pFileInfo[pWin->slDispTopNumber + ulDispCount], fX, fY + (pWin->slLineNumber * ulDispCount));
        }
    }
}

// 100% matching!
void mcMoveFileSelectWindowCursor(SELECTFILEWINDOW* pWin, short slCur)
{
    pWin->sMesCur += slCur;
    
    if (pWin->sMesCur < pWin->slDispTopNumber) 
    {
        pWin->slDispTopNumber--;
        
        if (pWin->slDispTopNumber < 0) 
        {
            pWin->slDispTopNumber = 10;
            
            pWin->sMesCur = 14;
        }
    }
    else if ((pWin->slDispTopNumber + pWin->slDispRecordNumber) <= pWin->sMesCur) 
    {
        pWin->slDispTopNumber++;
        
        if ((pWin->slDispTopNumber + pWin->slDispRecordNumber) > 15) 
        {
            pWin->slDispTopNumber = 0;
            
            pWin->sMesCur = 0;
        }
    }
}

// 100% matching!
void mcDisplaySelectFileInfo(SELECTFILEINFO* pFileInfo, float fx, float fy)
{
    mcDispFileNumber(pFileInfo, fx, fy);
    
    mcDispFileName(pFileInfo, fy);
}

// 93.88% matching
void mcDisplaySelectFileInfoMesCount(SELECTFILEINFO* pFileInfo, float fx, float fy, unsigned int CountMes)
{
    NJS_POINT2 pos; 
    unsigned int col; 
    unsigned int ulMesIncrease; 
    unsigned int ulMesPlace; 
    unsigned int ulMaxMes; 

    ulMaxMes = Type_Space[pFileInfo->saveroom - 1][0];
    
    ulMesPlace = Type_Space[pFileInfo->saveroom - 1][1];
    
    ulMesIncrease = Type_Space[pFileInfo->saveroom - 1][2];

    mcDispFileNumber(pFileInfo, fx, fy);

    switch (pFileInfo->gm_mode) 
    {
    case 0:
        col = 0xFFFFFFFF;
        break;
    case 1:
        col = 0xFF20FF20;
        break;
    case 2:
        col = 0xFFFF2020;
        break;
    }

    pos.y = fy;

    if ((CountMes >= 3) && (CountMes <= (8 - pFileInfo->ply_id))) 
    {
        bhDispMessageEx(132.0f, fy, -1.0f, 1, pFileInfo->ply_id + 208, col, CountMes - 2);
    }
    else if (CountMes >= (9 - pFileInfo->ply_id))
    {
        bhDispMessageEx(132.0f, fy, -1.0f, 1, pFileInfo->ply_id + 208, col, 0);
        bhDispMessageEx(132.0f, fy, -1.0f, 1, pFileInfo->ply_id + 208, col, 0);
        
        pos.x = 230.0f;
        
        CountDisplay(15, &pos, col, 1);
    }

    if (CountMes >= (11 - pFileInfo->ply_id))
    {
        pos.x = 262.0f;
        
        bhDispFontEx(&pos, MesNumTbl[pFileInfo->save_ct / 10], col, -1.0f);
    }
    
    if (CountMes >= (12 - pFileInfo->ply_id)) 
    {
        pos.x = 288.0f;
        
        bhDispFontEx(&pos, MesNumTbl[pFileInfo->save_ct % 10], col, -1.0f);
    }
    
    if (CountMes >= (13 - pFileInfo->ply_id)) 
    {
        pos.x = 320.0f;
        
        CountDisplay(15, &pos, col, 1);
    }

    if ((CountMes >= (15 - pFileInfo->ply_id)) && (CountMes <= ((ulMaxMes - 1) - pFileInfo->ply_id))) 
    {
        if (CountMes >= ulMesPlace) 
        {
            bhDispMessageEx(352.0f, fy, -1.0f, 1, pFileInfo->saveroom + 215, col, (CountMes + ulMesIncrease) - 14);
        } 
        else 
        {
            bhDispMessageEx(352.0f, fy, -1.0f, 1, pFileInfo->saveroom + 215, col, CountMes - (14 - pFileInfo->ply_id));
        }
    } 
    else if (CountMes >= (ulMaxMes - pFileInfo->ply_id)) 
    {
        bhDispMessageEx(352.0f, fy, -1.0f, 1, pFileInfo->saveroom + 215, col, 0);
    }
}

// 100% matching!
void mcCallMessageTypeSe(SELECTFILEINFO* pFileInfo, int CountMes) 
{
    if (pFileInfo->ply_id == 0)
    {
        if (!(((CountMes < 0) || (CountMes > 2)) && ((CountMes != 10) && (CountMes != 14)))) 
        {
            return;
        }
        
        if ((CountMes == 9) || (CountMes == 13))
        {
            CallSystemSe(0, 0x80000243);
        }
        else
        {
            CallSystemSe(0, 0x80000242);
        }
    }
    else if (!(((CountMes < 0) || (CountMes > 2)) && ((CountMes != 9) && (CountMes != 13)))) 
    {
        return;
    }
    else if ((CountMes == 8) || (CountMes == 12))
    {
        CallSystemSe(0, 0x80000243);
    }
    else
    {
        CallSystemSe(0, 0x80000242);
    }
}

// 92.35% matching 
void mcDispFileNumber(SELECTFILEINFO* pFileInfo, float fx, float fy)
{
    NJS_POINT2 pos; 
    unsigned int ulTenfigure;
    unsigned int col; 
    
    if ((pFileInfo->save_ct == 0) && (pFileInfo->gm_mode == 0) && (pFileInfo->ply_id == 0) && (pFileInfo->saveroom == 0))
    {
        col = 0xFF606060;
    }
    else
    {
        col = -1;
    }
    
    pos.x = fx;
    pos.y = fy;
    
    ulTenfigure = pFileInfo->FileNumber / 10;

    if (ulTenfigure != 0)
    {
        bhDispFontEx(&pos, MesNumTbl[ulTenfigure], col, -1.0f);
    }
    
    pos.x = 26.0f + fx; 
    
    bhDispFontEx(&pos, MesNumTbl[pFileInfo->FileNumber % 10], col, -1.0f);
    
    pos.x = 58.0f + fx;
    
    CountDisplay(14, &pos, col, 0);
}

// 93.22% matching
void mcDispFileName(SELECTFILEINFO* pFileInfo, float fy)
{
	NJS_POINT2 pos; 
    unsigned int col; 
    
    if ((pFileInfo->save_ct == 0) && (pFileInfo->gm_mode == 0) && (pFileInfo->ply_id == 0) && (pFileInfo->saveroom == 0)) 
    {
        bhDispMessageEx(132.0f, fy, -1.0f, 1, 215, 0xFF606060, 0);
        return;
    }
    
    switch (pFileInfo->gm_mode) 
    {                          
    case 0:
        col = -1;
        break;
    case 1:
        col = 0xFF20FF20;
        break;
    case 2:
        col = 0xFFFF2020;
        break;
    }
    
    bhDispMessageEx(132.0f, fy, -1.0f, 1, pFileInfo->ply_id + 208, col, 0);
    
    pos.x = 230.0f;
    pos.y = fy;
    
    CountDisplay(15, &pos, col, 1);
    
    pos.x = 262.0f;
    
    bhDispFontEx(&pos, MesNumTbl[pFileInfo->save_ct / 10], col, -1.0f);
    
    pos.x = 288.0f;
    
    bhDispFontEx(&pos, MesNumTbl[pFileInfo->save_ct % 10], col, -1.0f);
    
    pos.x = 320.0f;
    
    CountDisplay(15, &pos, col, 1);
    
    bhDispMessageEx(352.0f, fy, -1.0f, 1, pFileInfo->saveroom + 215, col, 0);
}

// 100% matching!
void mcSetTyepWriteMode(SELECTFILEWINDOW* pWin, unsigned int SetState)
{
    pWin->ulFileState = SetState;
}

// 100% matching!
int mcSetStringSaveFile(SELECTFILEINFO* pFileInfo)
{
    return Type_Space[pFileInfo->saveroom][0] - pFileInfo->ply_id;
}

// 100% matching!
int mcGetStringEnd(SELECTFILEWINDOW* pWin, unsigned short usSaveEnd) 
{
    if (pWin->slDispWriteMes > pWin->slDispWriteMesMax)
    {
        pWin->slDispWriteMes = 0;
        
        pWin->ulFileState = 0;
        
        pWin->sWaitMesTimer = -6;
        
        usSaveEnd = 0;
    }
    
    return usSaveEnd;
}

// 100% matching!
void mcDispWindowCurSol(SELECTFILEWINDOW* pWin, float fx, float fy)
{
    DispCursolTexture(fx, fy + (pWin->sCursol * 40.0f), 0xFF808080);
}

// 100% matching!
void DispCursolTexture(float pos_x, float pos_y, unsigned int color)
{
    QUAD twt[18]; 

    njSetTexture((NJS_TEXLIST*)&((COM_EVT_WORK*)sys->typ_exp)->com_tlist);
    
    njQuadTextureStart(1);
    
    twt[12].x1 = pos_x;
    twt[12].y1 = pos_y;
    
    twt[12].x2 = 16.0f + twt[12].x1;
    twt[12].y2 = 30.0f + twt[12].y1;
    
    twt[12].u1 = 0.47070313f;
    twt[12].v1 = 0;
    
    twt[12].u2 = 0.5019531f;
    twt[12].v2 = 0.0625f;
    
    njSetQuadTexture(2, color);
    
    njDrawQuadTexture(&twt[12], 0.3f);
    
    njQuadTextureEnd();
}

// 100% matching! 
void DispUpDownCursol(float fx, float fy, unsigned int mode)
{
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4]; 
    NJS_COLOR col[4]; 
    
    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = NULL;
    
    p2c.num = 4;
    
    switch (mode)
    {                              
    case 0:
        p[0].x = fx;
        p[0].y = fy;
        
        p[1].x = 16.0f + p[0].x;
        p[1].y = p[0].y;
        
        p[2].x = 16.0f + p[0].x;
        p[2].y = p[0].y;
        
        p[3].x = 8.0f + p[0].x;
        p[3].y = p[0].y - 8.0f;
        break;
    case 1:
        p[0].x = fx;
        p[0].y = 226.0f + fy;
        
        p[1].x = 16.0f + p[0].x;
        p[1].y = p[0].y;
        
        p[2].x = 16.0f + p[0].x;
        p[2].y = p[0].y;
        
        p[3].x = 8.0f + p[0].x;
        p[3].y = 8.0f + p[0].y;
        break;
    case 2:
        p[0].x = fx;
        p[0].y = fy;
        
        p[1].x = 8.0f + p[0].x;
        p[1].y = 8.0f + p[0].y;
        
        p[2].x = 8.0f + p[0].x;
        p[2].y = 8.0f + p[0].y;
        
        p[3].x = p[0].x;
        p[3].y = 16.0f + p[0].y;
        break;
    case 3:
        p[0].x = fx;
        p[0].y = 22.0f + fy;
        
        p[1].x = 8.0f + p[0].x;
        p[1].y = 8.0f + p[0].y;
        
        p[2].x = 8.0f + p[0].x;
        p[2].y = 8.0f + p[0].y;
        
        p[3].x = p[0].x;
        p[3].y = 16.0f + p[0].y;
        break;
    }
    
    col[0].color = 0xFFC0C0C0;
    col[1].color = 0xFFC0C0C0;
    col[2].color = 0xFFC0C0C0;
    col[3].color = 0xFFC0C0C0;
    
    njDrawPolygon2D(&p2c, 4, -1.0f, 96);
}

// 100% matching!
void DispBackGroundTexture()
{
    QUAD twt[18]; 

    njSetTexture((NJS_TEXLIST*)&((COM_EVT_WORK*)sys->typ_exp)->com_tlist);
    
    njQuadTextureStart(0);
    
    twt[0].x1 = 0;
    twt[0].y1 = 0;
    
    twt[0].x2 = 512.0f;
    twt[0].y2 = 480.0f;
    
    twt[0].u1 = 0;
    twt[0].v1 = 0;
    
    twt[0].u2 = 1.0f;
    twt[0].v2 = 0.93f;
    
    njSetQuadTexture(0, 0xFF909090);
    
    njDrawQuadTexture(&twt[0], 0.1f);
    
    twt[1].x1 = 512.0f;
    twt[1].y1 = 0;
    
    twt[1].x2 = 640.0f;
    twt[1].y2 = 480.0f;
    
    twt[1].u1 = 0;
    twt[1].v1 = 0;
    
    twt[1].u2 = 0.24f;
    twt[1].v2 = 0.93f;
    
    njSetQuadTexture(1, 0xFF909090);
    
    njDrawQuadTexture(&twt[1], 0.1f);
    
    njQuadTextureEnd();
}

// 100% matching!
void DispMemoryCardTexture(float fx, float fy, unsigned int type, unsigned int mode)
{
    QUAD twt[18]; 

    njSetTexture((NJS_TEXLIST*)&((COM_EVT_WORK*)sys->typ_exp)->com_tlist);
    
    if (mode == 2)
    {
        njQuadTextureStart(0);
    }
    else 
    {
        njQuadTextureStart(1);
    }
    
    twt[2].x1 = fx;
    twt[2].y1 = fy;
    
    twt[2].x2 = 109.0f + twt[2].x1;
    twt[2].y2 = 148.0f + twt[2].y1;
    
    if (type == 1) 
    {
        twt[2].u1 = 0; 
        twt[2].v1 = 0;
        
        twt[2].u2 = 0.21679688f;
        twt[2].v2 = 0.296875f;
    } 
    else 
    {
        twt[2].u1 = 0.21875f;
        twt[2].v1 = 0;
        
        twt[2].u2 = 0.4375f;
        twt[2].v2 = 0.296875f;
    }
    
    njSetQuadTexture(2, 0xFF646464);
    
    njDrawQuadTexture(&twt[2], 0.2f);
    
    njQuadTextureEnd();
}

// 100% matching!
void mcDispWindowFoundtion(float fx, float fy, float fSizeW, float fSizeH, unsigned int Argb)
{
    NJS_POLYGON_VTX poly[4];

    poly[0].x = fx;
    poly[0].y = fy;
    poly[0].z = 0.1f;
    
    poly[0].col = Argb;

    poly[1].x = poly[0].x;
    poly[1].y = fSizeH;
    poly[1].z = 0.1f;
    
    poly[1].col = Argb;

    poly[2].x = fSizeW;
    poly[2].y = poly[0].y;
    poly[2].z = 0.1f;
    
    poly[2].col = Argb;

    poly[3].x = fSizeW;
    poly[3].y = fSizeH;
    poly[3].z = 0.1f;
    
    poly[3].col = Argb;
    
    njDrawPolygon(poly, 4, 1);
}
