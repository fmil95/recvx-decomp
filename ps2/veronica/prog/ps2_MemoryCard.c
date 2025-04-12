/*typedef struct _anon0;
typedef struct tagMEMORYCARDSTATE;
typedef struct _anon1;
typedef struct tagMEMORYCARDPORT;
typedef struct _anon2;


typedef char type_0[32];
typedef unsigned char type_1[32];
typedef char type_2[50];
typedef char type_3[32];
typedef tagMEMORYCARDPORT type_4[2];
typedef _anon1 type_5[21];

struct _anon0
{
	unsigned char Resv2;
	unsigned char Sec;
	unsigned char Min;
	unsigned char Hour;
	unsigned char Day;
	unsigned char Month;
	unsigned short Year;
};

struct tagMEMORYCARDSTATE
{
	unsigned int ulState;
	unsigned int ulError;
	unsigned int ulMcSubState;
	unsigned int ulFileSize;
	int lCurrentPort;
	int lOpenFileNumber;
	int lSelectFileNumber;
	int lOpenMode;
	unsigned short usMcSysState;
	void* vpAddr;
	char cCurrentDir[50];
	char cOpenFileName[32];
	char cRetryCount;
	char cMcCheckFlag;
	char cCheckMcFlag;
	tagMEMORYCARDPORT Port[2];
};

struct _anon1
{
	_anon2 _Create;
	_anon0 _Modify;
	unsigned int FileSizeByte;
	unsigned short AttrFile;
	unsigned short Reserve1;
	unsigned int Reserve2;
	unsigned int PdaAplNo;
	unsigned char EntryName[32];
};

struct tagMEMORYCARDPORT
{
	int lCrntType;
	int lPrevType;
	int lFreeSize;
	int lFormatType;
};

struct _anon2
{
	unsigned char Resv2;
	unsigned char Sec;
	unsigned char Min;
	unsigned char Hour;
	unsigned char Day;
	unsigned char Month;
	unsigned short Year;
};


tagMEMORYCARDSTATE* CreateMemoryCard(tagMEMORYCARDSTATE* pCard);
int ExecuteMemoryCard(tagMEMORYCARDSTATE* pCard);
int ExecuteMemoryCardStandby(tagMEMORYCARDSTATE* pCard);
int AnalyzeMemoryCardAll(tagMEMORYCARDSTATE* pCard);
int ExecuteAnalyzeMemoryCardAll(tagMEMORYCARDSTATE* pCard);
int RecoveryMemoryCardAnalyzeAllEnd(tagMEMORYCARDSTATE* pCard);
void SetCheckMcFlag(tagMEMORYCARDSTATE* pCard, unsigned int ulFlag);
int ExecuteMemoryCardRead(tagMEMORYCARDSTATE* pCard);
int ExecuteMemoryCardWrite(tagMEMORYCARDSTATE* pCard);
int ExecuteMemoryCardFormat(tagMEMORYCARDSTATE* pCard);
int ExecuteMemoryCardUnFormat(tagMEMORYCARDSTATE* pCard);
int ExecuteMemoryCardDelete(tagMEMORYCARDSTATE* pCard);
unsigned int GetMemoryCardError(tagMEMORYCARDSTATE* pCard);
void RecoveryMemoryCardError(tagMEMORYCARDSTATE* pCard);
void SetMemoryCardCurrentPort(tagMEMORYCARDSTATE* pCard, int lPort);
int GetMemoryCardCurrentPort(tagMEMORYCARDSTATE* pCard);
void SetMemoryCardSelectPortState(tagMEMORYCARDSTATE* pCard, unsigned int ulPort, unsigned int ulResult);
void SaveMemoryCardSelectPortState(tagMEMORYCARDSTATE* pCard, unsigned int ulPort);
int CompMemoryCardSelectPortState(tagMEMORYCARDSTATE* pCard, unsigned int ulPort);
int GetMemoryCardSelectPortState(tagMEMORYCARDSTATE* pCard, unsigned int ulPort);
int GetMemoryCardFileNumber(tagMEMORYCARDSTATE* pCard);
void SetMemoryCardFileNumber(tagMEMORYCARDSTATE* pCard, int lFileNumber);
int SetMemoryCardCurrentDirectoryAbsolute(tagMEMORYCARDSTATE* pCard, char* cpPath);
int ReadMemoryCard(tagMEMORYCARDSTATE* pCard, void* pvReadFile, unsigned int ulFileSize, char* cpFileName, int lMode);
int RecoveryMemoryCardReadEnd(tagMEMORYCARDSTATE* pCard);
int WriteMemoryCard(tagMEMORYCARDSTATE* pCard, void* pvReadFile, unsigned int ulFileSize, char* cpFileName, int lMode);
int RecoveryMemoryCardWriteEnd(tagMEMORYCARDSTATE* pCard);
int FormatMemoryCard(tagMEMORYCARDSTATE* pCard);
int RecoveryMemoryCardFormatEnd(tagMEMORYCARDSTATE* pCard);
int GetMcSelectPortType(tagMEMORYCARDSTATE* pCard, unsigned int ulPort);
int CheckMemoryCardChangeConnectTypeAll(tagMEMORYCARDSTATE* pCard);
int SetMemoryCardFreeCapacity(tagMEMORYCARDSTATE* pCard, int Free);
int GetMemoryCardFreeCapacity(tagMEMORYCARDSTATE* pCard);
int GetMemoryCardSelectPortFreeCapacity(tagMEMORYCARDSTATE* pCard, unsigned int ulPort);
int CheckMemoryCardFormatStatus(tagMEMORYCARDSTATE* pCard);
int CreateMemoryCardSubDirectory(tagMEMORYCARDSTATE* pCard);
int CheckMemoryCardExistSubDirectory(tagMEMORYCARDSTATE* pCard);
int CheckMemoryCardExistFile(tagMEMORYCARDSTATE* pCard);
int CheckMemoryCardExistFileList(tagMEMORYCARDSTATE* pCard, char** cppPathList, unsigned int FileCount);
int MemoryCardGetSum(unsigned char* ucpTop, unsigned int ulSize);
int GetMemoryCardSelectPortFormatType(tagMEMORYCARDSTATE* pCard, unsigned int ulPort);
int CheckMcSelectPortInfoType(unsigned int ulPort);
int CheckMemoryCardInfoFree(tagMEMORYCARDSTATE* pCard);
int CheckMcSelectPortInfoState(unsigned int ulPort);
int CheckMemoryCardInfoUnformat(tagMEMORYCARDSTATE* pCard);
int GetMemoryCardDir(tagMEMORYCARDSTATE* pCard, char* cpPath, int lFlag, int lMaxent, _anon1* pbuff);
int ChangeMemoryCardDir(tagMEMORYCARDSTATE* pCard, char* cpPath, char* cpbuff);
int MakeMemoryCardDir(tagMEMORYCARDSTATE* pCard);
int MemoryCardFormat(tagMEMORYCARDSTATE* pCard);
int MemoryCardUnFormat();
int DeleteMemoryCard();
int MemoryCardFileOpen(tagMEMORYCARDSTATE* pCard);
int MemoryCardFileClose(tagMEMORYCARDSTATE* pCard);
int MemoryCardFileRead(tagMEMORYCARDSTATE* pCard);
int MemoryCardFileWrite(tagMEMORYCARDSTATE* pCard);*/

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

// 
// Start address: 0x273a00
int RecoveryMemoryCardAnalyzeAllEnd(MEMORYCARDSTATE* pCard)
{
	// Line 411, Address: 0x273a00, Func Offset: 0
	// Line 413, Address: 0x273a08, Func Offset: 0x8
	// Line 417, Address: 0x273a18, Func Offset: 0x18
	// Line 429, Address: 0x273a34, Func Offset: 0x34
	// Line 426, Address: 0x273a38, Func Offset: 0x38
	// Line 430, Address: 0x273a3c, Func Offset: 0x3c
	// Func End, Address: 0x273a48, Func Offset: 0x48
	scePrintf("RecoveryMemoryCardAnalyzeAllEnd - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x273a50
void SetCheckMcFlag(MEMORYCARDSTATE* pCard, unsigned int ulFlag)
{
	// Line 450, Address: 0x273a50, Func Offset: 0
	// Line 452, Address: 0x273a5c, Func Offset: 0xc
	// Line 454, Address: 0x273a60, Func Offset: 0x10
	// Func End, Address: 0x273a68, Func Offset: 0x18
	scePrintf("SetCheckMcFlag - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x273f60
void RecoveryMemoryCardError(MEMORYCARDSTATE* pCard)
{
	// Line 879, Address: 0x273f60, Func Offset: 0
	// Line 882, Address: 0x273f64, Func Offset: 0x4
	// Func End, Address: 0x273f6c, Func Offset: 0xc
	scePrintf("RecoveryMemoryCardError - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x273f70
void SetMemoryCardCurrentPort(MEMORYCARDSTATE* pCard, int lPort)
{
	// Line 917, Address: 0x273f70, Func Offset: 0
	// Func End, Address: 0x273f78, Func Offset: 0x8
	scePrintf("SetMemoryCardCurrentPort - UNIMPLEMENTED!\n");
}

// 100% matching!
int GetMemoryCardCurrentPort(MEMORYCARDSTATE* pCard) 
{
    return pCard->lCurrentPort;
}

// 
// Start address: 0x273f90
void SetMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort, unsigned int ulResult)
{
	// Line 1020, Address: 0x273f90, Func Offset: 0
	// Line 1021, Address: 0x273f98, Func Offset: 0x8
	// Func End, Address: 0x273fa0, Func Offset: 0x10
	scePrintf("SetMemoryCardSelectPortState - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x273fa0
void SaveMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort)
{
	// Line 1040, Address: 0x273fa0, Func Offset: 0
	// Line 1041, Address: 0x273fac, Func Offset: 0xc
	// Func End, Address: 0x273fb4, Func Offset: 0x14
	scePrintf("SaveMemoryCardSelectPortState - UNIMPLEMENTED!\n");
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

/*// 
// Start address: 0x274010
void SetMemoryCardFileNumber(tagMEMORYCARDSTATE* pCard, int lFileNumber)
{
	// Line 1150, Address: 0x274010, Func Offset: 0
	// Func End, Address: 0x274018, Func Offset: 0x8
}*/

// 
// Start address: 0x274020
int SetMemoryCardCurrentDirectoryAbsolute(MEMORYCARDSTATE* pCard, char* cpPath)
{
	char* src;
	char* dest;
	// Line 1172, Address: 0x274020, Func Offset: 0
	// Line 1174, Address: 0x274028, Func Offset: 0x8
	// Line 1175, Address: 0x274034, Func Offset: 0x14
	// Line 1176, Address: 0x274048, Func Offset: 0x28
	// Line 1179, Address: 0x27404c, Func Offset: 0x2c
	// Func End, Address: 0x274054, Func Offset: 0x34
	scePrintf("SetMemoryCardCurrentDirectoryAbsolute - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x274120
int RecoveryMemoryCardReadEnd(MEMORYCARDSTATE* pCard)
{
	// Line 1279, Address: 0x274120, Func Offset: 0
	// Line 1280, Address: 0x274128, Func Offset: 0x8
	// Line 1284, Address: 0x274138, Func Offset: 0x18
	// Line 1296, Address: 0x274154, Func Offset: 0x34
	// Line 1293, Address: 0x274158, Func Offset: 0x38
	// Line 1297, Address: 0x27415c, Func Offset: 0x3c
	// Func End, Address: 0x274168, Func Offset: 0x48
	scePrintf("RecoveryMemoryCardReadEnd - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x274170
int WriteMemoryCard(MEMORYCARDSTATE* pCard, void* pvReadFile, unsigned int ulFileSize, char* cpFileName, int lMode)
{
	// Line 1321, Address: 0x274170, Func Offset: 0
	// Line 1323, Address: 0x27418c, Func Offset: 0x1c
	// Line 1325, Address: 0x2741a8, Func Offset: 0x38
	// Line 1329, Address: 0x2741b0, Func Offset: 0x40
	// Line 1330, Address: 0x2741c0, Func Offset: 0x50
	// Line 1331, Address: 0x2741d0, Func Offset: 0x60
	// Line 1333, Address: 0x2741dc, Func Offset: 0x6c
	// Line 1335, Address: 0x2741e8, Func Offset: 0x78
	// Line 1337, Address: 0x2741ec, Func Offset: 0x7c
	// Line 1341, Address: 0x2741f0, Func Offset: 0x80
	// Line 1339, Address: 0x2741f4, Func Offset: 0x84
	// Line 1341, Address: 0x2741f8, Func Offset: 0x88
	// Line 1343, Address: 0x2741fc, Func Offset: 0x8c
	// Line 1347, Address: 0x274200, Func Offset: 0x90
	// Line 1345, Address: 0x274204, Func Offset: 0x94
	// Line 1347, Address: 0x274208, Func Offset: 0x98
	// Line 1349, Address: 0x27420c, Func Offset: 0x9c
	// Line 1350, Address: 0x274210, Func Offset: 0xa0
	// Func End, Address: 0x274230, Func Offset: 0xc0
	scePrintf("WriteMemoryCard - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x274230
int RecoveryMemoryCardWriteEnd(MEMORYCARDSTATE* pCard)
{
	// Line 1366, Address: 0x274230, Func Offset: 0
	// Line 1368, Address: 0x274238, Func Offset: 0x8
	// Line 1374, Address: 0x274248, Func Offset: 0x18
	// Line 1388, Address: 0x274264, Func Offset: 0x34
	// Line 1385, Address: 0x274268, Func Offset: 0x38
	// Line 1389, Address: 0x27426c, Func Offset: 0x3c
	// Func End, Address: 0x274278, Func Offset: 0x48
	scePrintf("RecoveryMemoryCardWriteEnd - UNIMPLEMENTED!\n");
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

/*// 
// Start address: 0x2742b0
int RecoveryMemoryCardFormatEnd(tagMEMORYCARDSTATE* pCard)
{
	// Line 1435, Address: 0x2742b0, Func Offset: 0
	// Line 1437, Address: 0x2742b8, Func Offset: 0x8
	// Line 1441, Address: 0x2742c8, Func Offset: 0x18
	// Line 1453, Address: 0x2742e4, Func Offset: 0x34
	// Line 1450, Address: 0x2742e8, Func Offset: 0x38
	// Line 1454, Address: 0x2742ec, Func Offset: 0x3c
	// Func End, Address: 0x2742f8, Func Offset: 0x48
}*/

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

// 
// Start address: 0x2744e0
int SetMemoryCardFreeCapacity(MEMORYCARDSTATE* pCard, int Free)
{
	// Line 1826, Address: 0x2744e0, Func Offset: 0
	// Line 1829, Address: 0x2744f0, Func Offset: 0x10
	// Line 1830, Address: 0x2744fc, Func Offset: 0x1c
	// Func End, Address: 0x274504, Func Offset: 0x24
	scePrintf("SetMemoryCardFreeCapacity - UNIMPLEMENTED!\n");
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
