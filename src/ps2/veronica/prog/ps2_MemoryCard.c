#include "ps2_MemoryCard.h"

// 100% matching!
MEMORYCARDSTATE* CreateMemoryCard(MEMORYCARDSTATE* pCard)
{ 
    pCard->ulState = 0; 
    
    pCard->ulError = 0; 
    
    pCard->ulMcSubState = 0;  
    
    pCard->ulFileSize = 0; 
    
    pCard->lCurrentPort = 0; 
    
    pCard->lOpenFileNumber = 0; 
    
    pCard->lSelectFileNumber = 0;
    
    pCard->lOpenMode = 0; 
    
    pCard->usMcSysState = 0; 
    
    pCard->vpAddr = NULL; 
    
    pCard->cRetryCount = 0; 
    
    pCard->cMcCheckFlag = 0; 
    
    pCard->cCheckMcFlag = 0; 
    
    SetMemoryCardCurrentDirectoryAbsolute(pCard, "/BASLUS-20184"); 
    
    strcpy(pCard->cOpenFileName, "BASLUS-20184"); 
    
    return pCard; 
} 

// 100% matching!
int ExecuteMemoryCard(MEMORYCARDSTATE* pCard)
{ 
    if (pCard->ulError != 0) 
    {
        return -1; 
    }
    
    switch (pCard->ulState) 
    {
    case 0:
        return ExecuteMemoryCardStandby(pCard);
    case 1:
        ExecuteMemoryCardRead(pCard); 
        break; 
    case 2:
        ExecuteMemoryCardWrite(pCard);
        break;
    case 4:
        ExecuteMemoryCardFormat(pCard); 
        break; 
    case 5:
        ExecuteMemoryCardUnFormat(pCard); 
        break; 
    case 7:
        ExecuteMemoryCardDelete(pCard);  
        break; 
    case 17:
        ExecuteAnalyzeMemoryCardAll(pCard);  
        break;
    }
    
    return 104; 
} 

// 100% matching!
int ExecuteMemoryCardStandby(MEMORYCARDSTATE* pCard) 
{ 
    int lCmd;
    int lResult;
	
    if ((pCard->cCheckMcFlag == 0) && (sceMcSync(1, &lCmd, &lResult) == -1))  
    {
        return CheckMemoryCardChangeConnectTypeAll(pCard); 
    }
    
    return 0; 
} 

// 100% matching!
int AnalyzeMemoryCardAll(MEMORYCARDSTATE* pCard)
{
    if (pCard->ulState != 0)  
    {
        return 0;
    }
    
    pCard->ulState = 17; 
    
    pCard->ulError = 0; 

    pCard->ulMcSubState = 0; 
    
    return 1; 
} 

// 100% matching!
int ExecuteAnalyzeMemoryCardAll(MEMORYCARDSTATE* pCard)
{ 
    int lCmd;
    int lResult;
    int lSyncResult;
    
    switch (pCard->usMcSysState) 
    {
    case 0:
        pCard->cRetryCount = 5; 
        
        pCard->usMcSysState = 1;
    case 1:
        lResult = sceMcGetInfo(0, 0, &pCard->Port[0].lCrntType, &pCard->Port[0].lFreeSize, &pCard->Port[0].lFormatType); 
        
        if (lResult == -1) 
        { 
            return 0; 
        }
        else if ((lResult == 0) || (pCard->cRetryCount == 0)) 
        { 
            pCard->usMcSysState = 2; 
            break;
        } 
        
        pCard->cRetryCount--; 
        break; 
    case 2:
        lSyncResult = sceMcSync(1, &lCmd, &lResult); 

        if (lSyncResult == 1) 
        { 
            if (pCard->cRetryCount < 5) 
            { 
                pCard->usMcSysState = 0;
            } 
            else 
            { 
                pCard->Port[0].lFreeSize -= 2; 
                
                if (pCard->Port[0].lFreeSize < 0) 
                { 
                    pCard->Port[0].lFreeSize = 0; 
                }
                
                pCard->cRetryCount = 0; 
                
                pCard->usMcSysState = 3; 
            }
        } 
        else if (lSyncResult == -1)
        { 
            pCard->ulState = 0; 
            
            pCard->ulError = 9; 
            
            pCard->usMcSysState = 0; 
            
            pCard->cRetryCount = 0;
            
            return -1; 
        }
        
        break;
    case 3:
        pCard->cRetryCount = 5; 
        
        pCard->usMcSysState = 4;
    case 4:
        lResult = sceMcGetInfo(1, 0, &pCard->Port[1].lCrntType, &pCard->Port[1].lFreeSize, &pCard->Port[1].lFormatType); 
        
        if (lResult == -1) 
        { 
            return 0; 
        } 
        else if ((lResult == 0) || (pCard->cRetryCount == 0)) 
        { 
            pCard->usMcSysState = 5; 
            break;
        } 
        
        pCard->cRetryCount--; 
        break; 
    case 5:
        lSyncResult = sceMcSync(1, &lCmd, &lResult); 
        
        if (lSyncResult == 1) 
        { 
            if (pCard->cRetryCount < 5) 
            { 
                pCard->usMcSysState = 3; 
            } 
            else
            { 
                pCard->Port[1].lFreeSize -= 2; 
                
                if (pCard->Port[1].lFreeSize < 0) 
                {
                    pCard->Port[1].lFreeSize = 0;
                }
                
                pCard->ulState = 18; 
                
                pCard->ulError = 0; 
                
                pCard->cRetryCount = 0; 
                
                pCard->usMcSysState = 0;
            }
        } 
        else if (lSyncResult == -1)
        { 
            pCard->ulState = 0;  
            
            pCard->ulError = 9; 
            
            pCard->cRetryCount = 0; 
            
            pCard->usMcSysState = 0;
            
            return -1; 
        }
        
        break;
    }
    
    return 0; 
} 

// 100% matching! 
int RecoveryMemoryCardAnalyzeAllEnd(MEMORYCARDSTATE* pCard) 
{
    if (pCard->ulState != 18) 
    {
        return (GetMemoryCardError(pCard) == 0) ? 0 : -1;
    }
    
    pCard->ulState = 0;
    
    return 1;
}

// 100% matching! 
void SetCheckMcFlag(MEMORYCARDSTATE* pCard, unsigned int ulFlag)
{
    pCard->cCheckMcFlag = ulFlag;

    if (ulFlag == 1) 
    { 
        pCard->cMcCheckFlag = 0; 
    }
} 

// 100% matching!
int ExecuteMemoryCardRead(MEMORYCARDSTATE* pCard) 
{ 
    int lResult;

    switch (pCard->ulMcSubState)
    {
    case 0:
        lResult = MemoryCardFileOpen(pCard); 
        
        if (lResult == -1) 
        {
            pCard->ulState = 0; 
            
            pCard->ulError = 3; 
            
            return -1; 
        }
        
        if (lResult == 1) 
        {
            pCard->ulMcSubState = 1;
        }
        
        break; 
    case 1:
        lResult = MemoryCardFileRead(pCard);
        
        if (lResult == 1)
        {
            pCard->ulMcSubState = 2; 
        } 
        else if (lResult == -1) 
        {
            return -1; 
        }
        
        break;
    case 2:
        lResult = MemoryCardFileClose(pCard); 
        
        if (lResult == -1) 
        {
            pCard->ulState = 0; 
            
            pCard->ulError = 8;  
            
            return -1;
        }
        
        if (lResult == 1) 
        {
            pCard->ulState = 9;
            
            pCard->ulError = 0;
            
            return 1; 
        }
        
        break;
    }
    
    return 0; 
} 

// 100% matching!
int ExecuteMemoryCardWrite(MEMORYCARDSTATE* pCard) 
{
    int lResult;

    switch (pCard->ulMcSubState) 
    {
    case 0:
        lResult = MemoryCardFileOpen(pCard); 
        
        if (lResult == -1) 
        {
            pCard->ulState = 0;  
            
            pCard->ulError = 3; 
            
            pCard->cRetryCount = 5;  
            
            return -1; 
        }
        else if (lResult == 1) 
        {
            pCard->ulMcSubState = 1; 
            
            pCard->cRetryCount = 5; 
        }
        
        break; 
    case 1:
        lResult = MemoryCardFileWrite(pCard); 
        
        if (lResult == 1) 
        {
            pCard->ulMcSubState = 2; 
            
            pCard->cRetryCount = 5;
        } 
        else if (lResult == -1) 
        {
            return -1; 
        }
        
        break;
    case 2:
        lResult = MemoryCardFileClose(pCard); 
        
        if (lResult == 1) 
        {
            pCard->ulMcSubState = 3; 
        }  
        else if (lResult == -1) 
        {
            return -1; 
        }
        
        break;
    case 3:
        lResult = CheckMemoryCardExistFile(pCard);
        
        if (lResult == -1) 
        {
            pCard->ulState = 0; 
            
            pCard->ulError = 2; 
            
            return -1;
        }
        else if (lResult == 1)
        {
            pCard->ulState = 10; 
            
            pCard->ulError = 0;                 
            
            return 1; 
        }
        
        break;
    }

    return 0;
} 

// 100% matching!
int ExecuteMemoryCardFormat(MEMORYCARDSTATE* pCard)
{ 
    int lResult;

    lResult = MemoryCardFormat(pCard); 

    if (lResult == -1)
    { 
        pCard->ulState = 0;
        
        pCard->ulError = 4; 
        
        pCard->cRetryCount = 5;
        
        return -1; 
    } 
    else if (lResult == 1) 
    { 
        pCard->ulState = 12; 
        
        pCard->ulError = 0; 

        return 1; 
    }   
    
    return 0; 
} 

// 100% matching!
int ExecuteMemoryCardUnFormat(MEMORYCARDSTATE* pCard)
{
    int lCmd;
    int lResult;

    switch (pCard->ulMcSubState)
    {
    case 0:
        lResult = MemoryCardUnFormat(pCard);

        if (lResult != 0) 
        {
            if (--pCard->cRetryCount != 0)
            {
                return 0;
            }
            
            pCard->ulState = 0;
            
            pCard->ulError = 5;
            
            pCard->cRetryCount = 5;
            
            return -1; 
        } 
        
        pCard->ulMcSubState = 1;
        
        pCard->cRetryCount = 5;
        break;
    case 1:
        if (sceMcSync(1, &lCmd, &lResult) == 1)
        {
            if (lResult < 0) 
            {
                pCard->ulState = 0;
                
                pCard->ulError = 5;
                
                return -1; 
            }
            else 
            {
                pCard->ulState = 13; 
            
                pCard->ulError = 0;
                
                return 1; 
            }
        }
    }
    
    return 0;
}

// 100% matching!
int ExecuteMemoryCardDelete(MEMORYCARDSTATE* pCard)
{
    int lCmd;
    int lResult;

    switch (pCard->ulMcSubState)
    {
    case 0:
        lResult = DeleteMemoryCard(pCard);

        if (lResult != 0) 
        {
            if (--pCard->cRetryCount != 0)
            {
                return 0;
            }
            
            pCard->ulState = 0;
            
            pCard->ulError = 7;
            
            pCard->cRetryCount = 5;
            
            return -1; 
        } 
        
        pCard->ulMcSubState = 1;
        
        pCard->cRetryCount = 5;
        break;
    case 1:
        if (sceMcSync(1, &lCmd, &lResult) == 1)
        {
            if (lResult < 0) 
            {
                pCard->ulState = 0;
                
                pCard->ulError = 7;
                
                return -1; 
            }
            else 
            {
                pCard->ulState = 15; 
            
                pCard->ulError = 0;
                
                return 1; 
            }
        }
    }
    
    return 0;
}

// 100% matching!
unsigned int GetMemoryCardError(MEMORYCARDSTATE* pCard) 
{
    return pCard->ulError;
}

// 100% matching! 
void RecoveryMemoryCardError(MEMORYCARDSTATE* pCard)
{
    pCard->ulState = 0;
    
    pCard->ulError = 0;
}

// 100% matching! 
void SetMemoryCardCurrentPort(MEMORYCARDSTATE* pCard, int lPort) 
{
    pCard->lCurrentPort = lPort;
} 

// 100% matching!
int GetMemoryCardCurrentPort(MEMORYCARDSTATE* pCard) 
{
    return pCard->lCurrentPort;
}

// 100% matching! 
void SetMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort, unsigned int ulResult) 
{
    pCard->Port[ulPort].lCrntType = ulResult; 
} 

// 100% matching!
void SaveMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort) 
{
    pCard->Port[ulPort].lPrevType = pCard->Port[ulPort].lCrntType; 
} 

// 100% matching!
int CompMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort)
{
    if (pCard->Port[ulPort].lPrevType == pCard->Port[ulPort].lCrntType) 
    {
        return 0;
    } 
    
    return 1;
}

// 100% matching!
int GetMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort) 
{
    return pCard->Port[ulPort].lCrntType; 
} 

// 100% matching!
int GetMemoryCardFileNumber(MEMORYCARDSTATE* pCard) 
{
    return pCard->lSelectFileNumber;
}

// 100% matching! 
void SetMemoryCardFileNumber(MEMORYCARDSTATE* pCard, int lFileNumber) 
{
    pCard->lSelectFileNumber = lFileNumber;
} 

// 100% matching! 
int SetMemoryCardCurrentDirectoryAbsolute(MEMORYCARDSTATE *pCard, char *cpPath)
{
    char* dest;
    char* src;
	
    dest = pCard->cCurrentDir;

    src = cpPath;
    
    while (*src != 0)
    {     
        *dest++ = *src++;
    } 
    
    *dest = 0;
    
    return 0;
} 

// 100% matching! 
int ReadMemoryCard(MEMORYCARDSTATE* pCard, void* pvReadFile, unsigned int ulFileSize, char* cpFileName, int lMode) 
{ 
    if (pCard->ulState != 0) 
    {
        return 0;               
    }
    
    strcpy(pCard->cCurrentDir, "/BASLUS-20184"); 
    
    strcat(pCard->cCurrentDir, "/"); 
    strcat(pCard->cCurrentDir, cpFileName); 
    
    strcpy(pCard->cOpenFileName, cpFileName); 
    
    pCard->lOpenMode = lMode; 
    
    pCard->ulFileSize = ulFileSize; 
    
    pCard->vpAddr = pvReadFile; 
    
    pCard->ulState = 1; 
    
    pCard->ulMcSubState = 0; 
    
    pCard->usMcSysState = 0; 
    
    pCard->cRetryCount = 5; 
    
    return 1; 
} 

// 100% matching! 
int RecoveryMemoryCardReadEnd(MEMORYCARDSTATE* pCard)
{
    if (pCard->ulState != 9) 
    {
        return (GetMemoryCardError(pCard) == 0) ? 0 : -1;
    }
    
    pCard->ulState = 0;
    
    return 1;
}

// 100% matching! 
int WriteMemoryCard(MEMORYCARDSTATE* pCard, void* pvReadFile, unsigned int ulFileSize, char* cpFileName, int lMode)
{ 
    if (pCard->ulState != 0) 
    {
        return 0;               
    }
    
    strcpy(pCard->cCurrentDir, "/BASLUS-20184"); 
    
    strcat(pCard->cCurrentDir, "/"); 
    strcat(pCard->cCurrentDir, cpFileName); 
    
    strcpy(pCard->cOpenFileName, cpFileName); 
    
    pCard->lOpenMode = lMode; 
    
    pCard->ulFileSize = ulFileSize; 
    
    pCard->vpAddr = pvReadFile; 
    
    pCard->ulState = 2; 
    
    pCard->ulMcSubState = 0; 
    
    pCard->usMcSysState = 0; 
    
    pCard->cRetryCount = 5; 
    
    return 1; 
} 

// 100% matching! 
int RecoveryMemoryCardWriteEnd(MEMORYCARDSTATE* pCard)
{
    if (pCard->ulState != 10) 
    {
        return (GetMemoryCardError(pCard) == 0) ? 0 : -1;
    }
    
    pCard->ulState = 0;
    
    return 1;
}

// 100% matching!
int FormatMemoryCard(MEMORYCARDSTATE* pCard) 
{ 
    if (pCard->ulState != 0) 
    { 
        return 0; 
    }
    
    pCard->ulState = 4; 
    
    pCard->ulMcSubState = 0; 
    
    return 1; 
} 

// 100% matching! 
int RecoveryMemoryCardFormatEnd(MEMORYCARDSTATE* pCard)
{
    if (pCard->ulState != 12) 
    {
        return (GetMemoryCardError(pCard) == 0) ? 0 : -1;
    }
    
    pCard->ulState = 0;
    
    return 1;
}

// 100% matching!
int GetMcSelectPortType(MEMORYCARDSTATE* pCard, unsigned int ulPort) 
{ 
    int lResult;

    if (pCard->ulState != 0)  
    {
        return 0; 
    }
    
    lResult = CheckMcSelectPortInfoType(ulPort); 

    if (lResult > 0)
    { 
        SetMemoryCardSelectPortState(pCard, ulPort, lResult); 
        
        return lResult;
    }
    
    if (lResult <= 0)  
    { 
        SetMemoryCardSelectPortState(pCard, ulPort, 0); 
        
        return 4; 
    }
    
    return -1; 
}  

// 100% matching!
int CheckMemoryCardChangeConnectTypeAll(MEMORYCARDSTATE* pCard)
{
    int lPort1Result;
	int lPort0Result;

    if (pCard->ulState != 0)
    {
        return 0;
    }

    if (pCard->cMcCheckFlag == 0)
    {
        SaveMemoryCardSelectPortState(pCard, 0);
        
        SetMemoryCardSelectPortState(pCard, 0, CheckMcSelectPortInfoType(0));
        
        pCard->cMcCheckFlag = 1;
        
        return 104;
    }

    SaveMemoryCardSelectPortState(pCard, 1);
    
    lPort0Result = GetMemoryCardSelectPortState(pCard, 0);
    
    lPort1Result = CheckMcSelectPortInfoType(1);
    
    SetMemoryCardSelectPortState(pCard, 1, lPort1Result);
    
    pCard->cMcCheckFlag = 0;

    if ((CompMemoryCardSelectPortState(pCard, 0) == 0) && (CompMemoryCardSelectPortState(pCard, 1) == 0))
    {
        return 100;
    }

    if ((lPort0Result == 2) || (lPort1Result == 2))
    {
        return 101;
    }

    if (((lPort0Result != 2) && (lPort0Result != 0)) || ((lPort1Result != 2) && (lPort1Result != 0))) 
    {
        return 102;
    } 
    
    return 103;
}

// 100% matching! 
int SetMemoryCardFreeCapacity(MEMORYCARDSTATE* pCard, int Free)
{
    pCard->Port[pCard->lCurrentPort].lFreeSize = Free;
    
    return pCard->Port[pCard->lCurrentPort].lFreeSize;
}

// 100% matching!
int GetMemoryCardFreeCapacity(MEMORYCARDSTATE* pCard)
{ 
    int lResult;

    if (pCard->ulState != 0) 
    {
        return -2; 
    }

    lResult = CheckMemoryCardInfoFree(pCard); 

    if (lResult > 0) 
    { 
        return SetMemoryCardFreeCapacity(pCard, lResult); 
    }

    if (lResult == -1) 
    {
        return -1; 
    }

    return 0;
} 

// 100% matching!
int GetMemoryCardSelectPortFreeCapacity(MEMORYCARDSTATE* pCard, unsigned int ulPort) 
{
    return pCard->Port[ulPort].lFreeSize; 
} 

// 100% matching!
int CheckMemoryCardFormatStatus(MEMORYCARDSTATE* pCard) 
{ 
    int lResult;

    if (pCard->ulState != 0)  
    {
        return 0; 
    }
    
    lResult = CheckMemoryCardInfoUnformat(pCard); 
    
    if (lResult == 0) 
    {
        return 1; 
    }
    else if (lResult == 1)   
    { 
        return 2; 
    }
    
    return -1;
} 

// 100% matching!
int CreateMemoryCardSubDirectory(MEMORYCARDSTATE* pCard)
{ 
    if (pCard->ulState != 0) 
    { 
        return 0;
    }
    
    if (MakeMemoryCardDir(pCard) == 0) 
    {
        return -1; 
    }
    
    pCard->cRetryCount = 5;
    
    return 1; 
} 

// 100% matching!
int CheckMemoryCardExistSubDirectory(MEMORYCARDSTATE* pCard) 
{ 
    if (pCard->ulState != 0)  
    {
        return 0; 
    }
    
    strcpy(pCard->cCurrentDir, "/BASLUS-20184");
    
    return ChangeMemoryCardDir(pCard, pCard->cCurrentDir, NULL); 
} 

// 99.06% matching
int CheckMemoryCardExistFile(MEMORYCARDSTATE* pCard) 
{ 
    static sceMcTblGetDir CardInfo; 
    
    if (GetMemoryCardDir(pCard, pCard->cCurrentDir, 0, 1, &CardInfo) < 0)
    { 
        return -1; 
    }
    
    if (strcmp(&CardInfo.EntryName, pCard->cOpenFileName) == 0)  
    {
        if ((CardInfo.AttrFile & 0x80)) 
        {
            return 1; 
        }
        else 
        {
            return -1;
        }
    }
    
    return -1; 
} 

// 99.76% matching
int CheckMemoryCardExistFileList(MEMORYCARDSTATE* pCard, char** cppPathList, unsigned int FileCount)
{
    static sceMcTblGetDir CardInfo[21];
    int lResult;
    unsigned short usCheckFileNameCounter;
    unsigned short usCheckCounter;
    char cEntryName[32];
    
    if (pCard->ulState != 0) 
    {
        return 0;
    }

    strcpy(cEntryName, "/BASLUS-20184");
    
    strcat(cEntryName, "/*");

    lResult = GetMemoryCardDir(pCard, cEntryName, 0, FileCount + 2, CardInfo);

    if (lResult != (FileCount + 2))
    {
        return -1;
    }

    for (usCheckCounter = 2; usCheckCounter < (FileCount + 2); usCheckCounter++) 
    {
        for (usCheckFileNameCounter = 0; usCheckFileNameCounter < FileCount; usCheckFileNameCounter++) 
        {
            if (strcmp(CardInfo[usCheckCounter].EntryName, cppPathList[usCheckFileNameCounter]) == 0)
            {
                break;
            }
            
            if (usCheckFileNameCounter >= 17) 
            {
                return -1;
            }
        }
    }

    return 1;
}

// 100% matching! 
int MemoryCardGetSum(unsigned char* ucpTop, unsigned int ulSize)
{ 
    unsigned int ulSum;

    for (ulSum = 0; ulSize != 0; ulSize--) 
    {
        ulSum += *ucpTop++; 
    }

    return ulSum;
}

// 100% matching!
int GetMemoryCardSelectPortFormatType(MEMORYCARDSTATE* pCard, unsigned int ulPort)
{
    return pCard->Port[ulPort].lFormatType; 
} 

// 100% matching!
int CheckMcSelectPortInfoType(unsigned int ulPort)
{ 
    int lCmd;
    int lResult;
	int lRetry; 
    int lPortResult;

    for (lRetry = 5; lRetry != 0; ) 
    { 
        if (sceMcGetInfo(ulPort, 0, &lPortResult, NULL, NULL) == 0) 
        { 
            if (sceMcSync(0, &lCmd, &lResult) == 1) 
            {  
                return lPortResult;  
            }
            
            lRetry--; 
        }
        else 
        {
            lRetry--; 
        }
    } 
    
    return 0; 
} 

// 100% matching!
int CheckMemoryCardInfoFree(MEMORYCARDSTATE* pCard)
{  
    int lCmd;
    int lRetry;
    int lResult;
	int lResultFreeCapacity;
    
    for (lRetry = 5; lRetry != 0; )
    {
        if (sceMcGetInfo(pCard->lCurrentPort, 0, NULL, &lResultFreeCapacity, NULL) == 0)
        {
            if (sceMcSync(0, &lCmd, &lResult) == 1) 
            {
                if (lResult >= -2)
                {
                    lResultFreeCapacity -= 2;
                    
                    return (lResultFreeCapacity < 0) ? 0 : lResultFreeCapacity; 
                }
                
                return -1;   
            }
            
            lRetry--;    
        }
        else 
        {
            lRetry--;   
        }
    }   

    return -1; 
} 

// 100% matching!
int CheckMcSelectPortInfoState(unsigned int ulPort)
{ 
    int lCmd;
    int lResult;
	int lRetry; 
    int lPortResult;

    for (lRetry = 5; lRetry != 0; ) 
    { 
        if (sceMcGetInfo(ulPort, 0, &lPortResult, NULL, NULL) == 0) 
        { 
            if (sceMcSync(0, &lCmd, &lResult) == 1) 
            {  
                return (lPortResult == 2) ? 1 : 0;  
            }
            
            lRetry--; 
        }
        else 
        {
            lRetry--; 
        }
    } 
    
    return 0; 
} 

// 100% matching!
int CheckMemoryCardInfoUnformat(MEMORYCARDSTATE* pCard)
{ 
    int lCmd;
    int lRetry;
    int lResult;
    int lPortFormt;

    for (lRetry = 5; lRetry != 0; ) 
    {
        if (sceMcGetInfo(pCard->lCurrentPort, 0, NULL, NULL, &lPortFormt) == 0) 
        {
            if (sceMcSync(0, &lCmd, &lResult) == 1)
            {
                switch (lResult) 
                {
                case 0:
                case -1:
                case -2:
                    return lPortFormt; 
                default:
                    return -1; 
                }
            }

            lRetry--;
        } 
        else 
        { 
            lRetry--; 
        }
    } 

    return -1;
}

// 100% matching!
int GetMemoryCardDir(MEMORYCARDSTATE* pCard, char* cpPath, int lFlag, int lMaxent, sceMcTblGetDir* pbuff)
{ 
    int lCmd;
    int lRetry;
    int lResult;
    
    for (lRetry = 5; lRetry != 0; )  
    {
        if (sceMcGetDir(pCard->lCurrentPort, 0, cpPath, lFlag, lMaxent, pbuff) == 0)  
        {
            if (sceMcSync(0, &lCmd, &lResult) == 1) 
            {
                if (lResult >= 0)  
                {
                    return lResult;  
                }
                    
                return -1;  
            }
            
            lRetry--;  
        } 
        else
        {
            lRetry--;  
        }
    }

    return -2; 
}  

// 100% matching!
int ChangeMemoryCardDir(MEMORYCARDSTATE* pCard, char* cpPath, char* cpbuff)
{   
    int lCmd;
    int lResult;
    int lRetry;  

    for (lRetry = 5; lRetry != 0; ) 
    { 
        if (sceMcChdir(pCard->lCurrentPort, 0, cpPath, cpbuff) == 0)    
        {
            if (sceMcSync(0, &lCmd, &lResult) == 1)
            {    
                return (lResult == 0) ? 1 : -1;   
            }
    
            lRetry--;     
        }
        else 
        {
            lRetry--; 
        }   
    }
    
    return -1;     
} 

// 100% matching!
int MakeMemoryCardDir(MEMORYCARDSTATE* pCard) 
{ 
    int lCmd;
    int lResult;
    int lRetry;

    for (lRetry = 5; lRetry != 0; ) 
    {
        if (sceMcMkdir(pCard->lCurrentPort, 0, pCard->cCurrentDir) == 0)  
        {
            if (sceMcSync(0, &lCmd, &lResult) == 1)
            {
                return (lResult == 0) ? 1 : 0; 
            }
            
            lRetry--; 
        } 
        else 
        { 
            lRetry--; 
        } 
    }
        
    return 0; 
} 

// 100% matching! 
int MemoryCardFormat(MEMORYCARDSTATE* pCard) 
{
    int lCmd;
    int lResult;
    int lSyncResult;

    switch (pCard->usMcSysState) 
    {
    case 0:
        lResult = sceMcFormat(pCard->lCurrentPort, 0); 
        
        if (lResult < 0) 
        {
            if (--pCard->cRetryCount != 0)
            {
                return 0;
            }
               
            return -1;
        }
        else if (lResult == 0)
        {
            pCard->usMcSysState = 1; 
        }
        
        break; 
    case 1:
        lSyncResult = sceMcSync(1, &lCmd, &lResult); 
        
        if (lSyncResult == 1) 
        {
            if (lResult < 0) 
            {
                pCard->usMcSysState = 0;
                
                return -1; 
            }
            else 
            {
                pCard->usMcSysState = 0;
            
                return 1; 
            }
        }
        else if (lSyncResult == -1) 
        {
            pCard->usMcSysState = 0; 
            
            return -1; 
        }
    }

    return 0; 
} 

// 100% matching! 
int MemoryCardUnFormat()
{
    return 0;
}

// 100% matching!
int DeleteMemoryCard() 
{
    return 0;
}

// 100% matching! 
int MemoryCardFileOpen(MEMORYCARDSTATE* pCard)
{
    int lCmd;
    int lResult;
    int lSyncResult;

    switch (pCard->usMcSysState)
    {
    case 0:
        lResult = sceMcOpen(pCard->lCurrentPort, 0, pCard->cCurrentDir, pCard->lOpenMode);
        
        if (lResult < 0)
        {
            if (--pCard->cRetryCount != 0)
            {
                return 0;
            }
            
            return -1;
        }
        else if (lResult == 0)
        {
            pCard->usMcSysState = 1;
        }
        
        break;
    case 1:
        lSyncResult = sceMcSync(1, &lCmd, &lResult);
        
        if (lSyncResult == 1)
        {
            if (lResult < 0)
            {
                pCard->usMcSysState = 0;
                
                return -1;
            }
            else 
            {
                pCard->usMcSysState = 0;
                
                return 1;
            }
        }
        else if (lSyncResult == -1)
        {
            pCard->usMcSysState = 0;
            
            return -1;
        }
        
        break;
    }

    return 0;
}

// 100% matching!
int MemoryCardFileClose(MEMORYCARDSTATE* pCard)
{
    int lCmd;
    int lResult;
    int lSyncResult;

    switch (pCard->usMcSysState) 
    {                          
    case 0:
        lResult = sceMcClose(pCard->lOpenFileNumber);
        
        if (lResult < 0) 
        {
            if (--pCard->cRetryCount) 
            {
                return 0;
            }
            
            pCard->ulState = 0;
            
            pCard->ulError = 8;
            
            pCard->cRetryCount = 5;
            
            return -1;
        }
        
        if (lResult > 0) 
        {
            return 0;
        }
        
        pCard->usMcSysState = 1; 
        
        pCard->cRetryCount = 5;
        break;
    case 1:
        lSyncResult = sceMcSync(1, &lCmd, &lResult);
        
        if (lSyncResult == 1) 
        {
            if (lResult < 0) 
            {
                pCard->ulState = 0;
                
                pCard->ulError = 8;
                
                pCard->usMcSysState = 0;
                
                return -1;
            }
            
            pCard->usMcSysState = 0;
            
            return 1;
        }
        
        if (lSyncResult == -1) 
        {
            pCard->ulState = 0;
            
            pCard->ulError = 8;
            
            pCard->usMcSysState = 0;
            
            return -1;
        }
    }
    
    return 0;
}

// 100% matching! 
int MemoryCardFileRead(MEMORYCARDSTATE* pCard)
{ 
    int lCmd;
    int lResult;
    int lSyncResult;

    switch (pCard->usMcSysState) 
    {  
    case 0:
        lResult = sceMcRead(pCard->lOpenFileNumber, pCard->vpAddr, pCard->ulFileSize); 
        
        if (lResult < 0)
        {  
            if (--pCard->cRetryCount != 0)
            { 
                return 0; 
            } 
            
            pCard->ulState = 0; 
            
            pCard->ulError = 1; 
            
            pCard->cRetryCount = 5; 
            
            return -1; 
        }
        else if (lResult > 0) 
        {
            return 0;
        }
        
        pCard->usMcSysState = 1; 
        
        pCard->cRetryCount = 5;
        break;
    case 1:
        lSyncResult = sceMcSync(1, &lCmd, &lResult);
        
        if (lSyncResult == 1) 
        {
            if (lResult < 0) 
            { 
                pCard->ulState = 0; 
                
                pCard->ulError = 1; 
                
                pCard->usMcSysState = 0;
                
                return -1;
            }
            
            pCard->usMcSysState = 0; 
            
            return 1; 
        }
        else if (lSyncResult == -1) 
        { 
            pCard->ulState = 0;
            
            pCard->ulError = 1; 
            
            pCard->usMcSysState = 0; 
            
            return -1; 
        }
    }
    
    return 0; 
} 

// 100% matching! 
int MemoryCardFileWrite(MEMORYCARDSTATE* pCard) 
{
    int lCmd;
    int lResult;
    int lSyncResult;

    switch (pCard->usMcSysState) 
    {
    case 0:
        lResult = sceMcWrite(pCard->lOpenFileNumber, pCard->vpAddr, pCard->ulFileSize);
        
        if (lResult < 0) 
        {
            if (--pCard->cRetryCount) 
            {
                return 0;
            }
            
            pCard->ulState = 0;
            
            pCard->ulError = 2;
            
            pCard->cRetryCount = 5;
            
            return -1;
        }
        else if (lResult > 0)
        {
            return 0;
        }
        
        pCard->usMcSysState = 1;
        
        pCard->cRetryCount = 5;
        break;
    case 1:
        lSyncResult = sceMcSync(1, &lCmd, &lResult);
        
        if (lSyncResult == 1) 
        {
            if (lResult < 0) 
            {
                pCard->ulState = 0;
                
                pCard->ulError = 2;
                
                pCard->usMcSysState = 0;
                
                return -1;
            }
            
            pCard->usMcSysState = 0;
            
            return 1;
        }
        else if (lSyncResult == -1) 
        {
            pCard->ulState = 0;
          
            pCard->ulError = 2;
            
            pCard->usMcSysState = 0;
            
            return -1;
        }
    }
    
    return 0;
}
