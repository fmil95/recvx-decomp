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

/*// 
// Start address: 0x273f50
unsigned int GetMemoryCardError(tagMEMORYCARDSTATE* pCard)
{
	// Line 861, Address: 0x273f50, Func Offset: 0
	// Func End, Address: 0x273f58, Func Offset: 0x8
}*/

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

/*// 
// Start address: 0x273f80
int GetMemoryCardCurrentPort(tagMEMORYCARDSTATE* pCard)
{
	// Line 935, Address: 0x273f80, Func Offset: 0
	// Func End, Address: 0x273f88, Func Offset: 0x8
}*/

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

// 
// Start address: 0x273ff0
int GetMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort)
{
	// Line 1089, Address: 0x273ff0, Func Offset: 0
	// Line 1090, Address: 0x273ff8, Func Offset: 0x8
	// Func End, Address: 0x274000, Func Offset: 0x10
	scePrintf("GetMemoryCardSelectPortState - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x274000
int GetMemoryCardFileNumber(tagMEMORYCARDSTATE* pCard)
{
	// Line 1131, Address: 0x274000, Func Offset: 0
	// Func End, Address: 0x274008, Func Offset: 0x8
}

// 
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

// 
// Start address: 0x274060
int ReadMemoryCard(MEMORYCARDSTATE* pCard, void* pvReadFile, unsigned int ulFileSize, char* cpFileName, int lMode)
{
	// Line 1231, Address: 0x274060, Func Offset: 0
	// Line 1233, Address: 0x27407c, Func Offset: 0x1c
	// Line 1236, Address: 0x274098, Func Offset: 0x38
	// Line 1240, Address: 0x2740a0, Func Offset: 0x40
	// Line 1241, Address: 0x2740b0, Func Offset: 0x50
	// Line 1243, Address: 0x2740c0, Func Offset: 0x60
	// Line 1245, Address: 0x2740cc, Func Offset: 0x6c
	// Line 1247, Address: 0x2740d8, Func Offset: 0x78
	// Line 1249, Address: 0x2740dc, Func Offset: 0x7c
	// Line 1253, Address: 0x2740e0, Func Offset: 0x80
	// Line 1251, Address: 0x2740e4, Func Offset: 0x84
	// Line 1253, Address: 0x2740e8, Func Offset: 0x88
	// Line 1255, Address: 0x2740ec, Func Offset: 0x8c
	// Line 1259, Address: 0x2740f0, Func Offset: 0x90
	// Line 1257, Address: 0x2740f4, Func Offset: 0x94
	// Line 1259, Address: 0x2740f8, Func Offset: 0x98
	// Line 1262, Address: 0x2740fc, Func Offset: 0x9c
	// Func End, Address: 0x27411c, Func Offset: 0xbc
	scePrintf("ReadMemoryCard - UNIMPLEMENTED!\n");
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
}

// 
// Start address: 0x274300
int GetMcSelectPortType(tagMEMORYCARDSTATE* pCard, unsigned int ulPort)
{
	int lResult;
	// Line 1644, Address: 0x274300, Func Offset: 0
	// Line 1648, Address: 0x274314, Func Offset: 0x14
	// Line 1651, Address: 0x274324, Func Offset: 0x24
	// Line 1654, Address: 0x27432c, Func Offset: 0x2c
	// Line 1657, Address: 0x274338, Func Offset: 0x38
	// Line 1660, Address: 0x274340, Func Offset: 0x40
	// Line 1662, Address: 0x274350, Func Offset: 0x50
	// Line 1664, Address: 0x274358, Func Offset: 0x58
	// Line 1667, Address: 0x274360, Func Offset: 0x60
	// Line 1669, Address: 0x274370, Func Offset: 0x70
	// Line 1674, Address: 0x274378, Func Offset: 0x78
	// Line 1676, Address: 0x27437c, Func Offset: 0x7c
	// Func End, Address: 0x274394, Func Offset: 0x94
}*/

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

/*// 
// Start address: 0x2744e0
int SetMemoryCardFreeCapacity(tagMEMORYCARDSTATE* pCard, int Free)
{
	// Line 1826, Address: 0x2744e0, Func Offset: 0
	// Line 1829, Address: 0x2744f0, Func Offset: 0x10
	// Line 1830, Address: 0x2744fc, Func Offset: 0x1c
	// Func End, Address: 0x274504, Func Offset: 0x24
}

// 
// Start address: 0x274510
int GetMemoryCardFreeCapacity(tagMEMORYCARDSTATE* pCard)
{
	int lResult;
	// Line 1848, Address: 0x274510, Func Offset: 0
	// Line 1852, Address: 0x27451c, Func Offset: 0xc
	// Line 1855, Address: 0x274528, Func Offset: 0x18
	// Line 1858, Address: 0x274530, Func Offset: 0x20
	// Line 1861, Address: 0x274538, Func Offset: 0x28
	// Line 1863, Address: 0x274540, Func Offset: 0x30
	// Line 1868, Address: 0x274554, Func Offset: 0x44
	// Line 1875, Address: 0x27456c, Func Offset: 0x5c
	// Func End, Address: 0x27457c, Func Offset: 0x6c
}*/

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

// 
// Start address: 0x274870
int MemoryCardGetSum(unsigned char* ucpTop, unsigned int ulSize)
{
	unsigned int ulSum;
	// Line 2258, Address: 0x274870, Func Offset: 0
	// Line 2260, Address: 0x274878, Func Offset: 0x8
	// Line 2261, Address: 0x27487c, Func Offset: 0xc
	// Line 2260, Address: 0x274880, Func Offset: 0x10
	// Line 2261, Address: 0x274888, Func Offset: 0x18
	// Line 2265, Address: 0x274898, Func Offset: 0x28
	// Func End, Address: 0x2748a0, Func Offset: 0x30
	scePrintf("MemoryCardGetSum - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2748a0
int GetMemoryCardSelectPortFormatType(MEMORYCARDSTATE* pCard, unsigned int ulPort)
{
	// Line 2285, Address: 0x2748a0, Func Offset: 0
	// Line 2286, Address: 0x2748a8, Func Offset: 0x8
	// Func End, Address: 0x2748b0, Func Offset: 0x10
	scePrintf("GetMemoryCardSelectPortFormatType - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x274b70
int GetMemoryCardDir(MEMORYCARDSTATE* pCard, char* cpPath, int lFlag, int lMaxent, sceMcTblGetDir* pbuff)
{
	int lResult;
	int lRetry;
	int lCmd;
	// Line 2608, Address: 0x274b70, Func Offset: 0
	// Line 2611, Address: 0x274b90, Func Offset: 0x20
	// Line 2614, Address: 0x274ba8, Func Offset: 0x38
	// Line 2616, Address: 0x274bcc, Func Offset: 0x5c
	// Line 2620, Address: 0x274be8, Func Offset: 0x78
	// Line 2630, Address: 0x274c08, Func Offset: 0x98
	// Line 2632, Address: 0x274c0c, Func Offset: 0x9c
	// Line 2635, Address: 0x274c14, Func Offset: 0xa4
	// Line 2637, Address: 0x274c18, Func Offset: 0xa8
	// Line 2639, Address: 0x274c20, Func Offset: 0xb0
	// Line 2640, Address: 0x274c24, Func Offset: 0xb4
	// Func End, Address: 0x274c48, Func Offset: 0xd8
	scePrintf("GetMemoryCardDir - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x274d00
int MakeMemoryCardDir(MEMORYCARDSTATE* pCard)
{
	int lRetry;
	int lResult;
	int lCmd;
	// Line 2708, Address: 0x274d00, Func Offset: 0
	// Line 2711, Address: 0x274d10, Func Offset: 0x10
	// Line 2714, Address: 0x274d18, Func Offset: 0x18
	// Line 2716, Address: 0x274d30, Func Offset: 0x30
	// Line 2720, Address: 0x274d4c, Func Offset: 0x4c
	// Line 2729, Address: 0x274d5c, Func Offset: 0x5c
	// Line 2731, Address: 0x274d60, Func Offset: 0x60
	// Line 2734, Address: 0x274d68, Func Offset: 0x68
	// Line 2735, Address: 0x274d6c, Func Offset: 0x6c
	// Line 2736, Address: 0x274d70, Func Offset: 0x70
	// Line 2738, Address: 0x274d78, Func Offset: 0x78
	// Line 2739, Address: 0x274d7c, Func Offset: 0x7c
	// Func End, Address: 0x274d90, Func Offset: 0x90
	scePrintf("MakeMemoryCardDir - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x274d90
int MemoryCardFormat(MEMORYCARDSTATE* pCard)
{
	int lSyncResult;
	int lResult;
	int lCmd;
	// Line 2755, Address: 0x274d90, Func Offset: 0
	// Line 2758, Address: 0x274d9c, Func Offset: 0xc
	// Line 2761, Address: 0x274dc0, Func Offset: 0x30
	// Line 2763, Address: 0x274dd0, Func Offset: 0x40
	// Line 2768, Address: 0x274ddc, Func Offset: 0x4c
	// Line 2775, Address: 0x274e00, Func Offset: 0x70
	// Line 2777, Address: 0x274e08, Func Offset: 0x78
	// Line 2779, Address: 0x274e0c, Func Offset: 0x7c
	// Line 2782, Address: 0x274e14, Func Offset: 0x84
	// Line 2784, Address: 0x274e20, Func Offset: 0x90
	// Line 2786, Address: 0x274e2c, Func Offset: 0x9c
	// Line 2790, Address: 0x274e38, Func Offset: 0xa8
	// Line 2795, Address: 0x274e44, Func Offset: 0xb4
	// Line 2797, Address: 0x274e48, Func Offset: 0xb8
	// Line 2800, Address: 0x274e50, Func Offset: 0xc0
	// Line 2803, Address: 0x274e5c, Func Offset: 0xcc
	// Line 2804, Address: 0x274e60, Func Offset: 0xd0
	// Line 2809, Address: 0x274e68, Func Offset: 0xd8
	// Line 2810, Address: 0x274e6c, Func Offset: 0xdc
	// Func End, Address: 0x274e7c, Func Offset: 0xec
	scePrintf("MemoryCardFormat - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x274e80
int MemoryCardUnFormat()
{
	// Line 2859, Address: 0x274e80, Func Offset: 0
	// Func End, Address: 0x274e88, Func Offset: 0x8
	scePrintf("MemoryCardUnFormat - UNIMPLEMENTED!\n");
}

// 100% matching!
int DeleteMemoryCard() 
{
    return 0;
}

// 
// Start address: 0x274ea0
int MemoryCardFileOpen(MEMORYCARDSTATE* pCard)
{
	int lSyncResult;
	int lResult;
	int lCmd;
	// Line 2918, Address: 0x274ea0, Func Offset: 0
	// Line 2921, Address: 0x274eac, Func Offset: 0xc
	// Line 2926, Address: 0x274ed0, Func Offset: 0x30
	// Line 2927, Address: 0x274ee8, Func Offset: 0x48
	// Line 2932, Address: 0x274ef4, Func Offset: 0x54
	// Line 2939, Address: 0x274f18, Func Offset: 0x78
	// Line 2941, Address: 0x274f20, Func Offset: 0x80
	// Line 2943, Address: 0x274f24, Func Offset: 0x84
	// Line 2946, Address: 0x274f2c, Func Offset: 0x8c
	// Line 2947, Address: 0x274f38, Func Offset: 0x98
	// Line 2949, Address: 0x274f44, Func Offset: 0xa4
	// Line 2953, Address: 0x274f50, Func Offset: 0xb0
	// Line 2958, Address: 0x274f5c, Func Offset: 0xbc
	// Line 2960, Address: 0x274f60, Func Offset: 0xc0
	// Line 2965, Address: 0x274f68, Func Offset: 0xc8
	// Line 2967, Address: 0x274f74, Func Offset: 0xd4
	// Line 2969, Address: 0x274f78, Func Offset: 0xd8
	// Line 2973, Address: 0x274f80, Func Offset: 0xe0
	// Line 2974, Address: 0x274f84, Func Offset: 0xe4
	// Func End, Address: 0x274f94, Func Offset: 0xf4
	scePrintf("MemoryCardFileOpen - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x274fa0
int MemoryCardFileClose(MEMORYCARDSTATE* pCard)
{
	int lSyncResult;
	int lResult;
	int lCmd;
	// Line 2991, Address: 0x274fa0, Func Offset: 0
	// Line 2994, Address: 0x274fac, Func Offset: 0xc
	// Line 2998, Address: 0x274fd0, Func Offset: 0x30
	// Line 3000, Address: 0x274fdc, Func Offset: 0x3c
	// Line 3003, Address: 0x274fe8, Func Offset: 0x48
	// Line 3005, Address: 0x275004, Func Offset: 0x64
	// Line 3012, Address: 0x27500c, Func Offset: 0x6c
	// Line 3010, Address: 0x275010, Func Offset: 0x70
	// Line 3012, Address: 0x275014, Func Offset: 0x74
	// Line 3014, Address: 0x275018, Func Offset: 0x78
	// Line 3015, Address: 0x275020, Func Offset: 0x80
	// Line 3018, Address: 0x275028, Func Offset: 0x88
	// Line 3021, Address: 0x275030, Func Offset: 0x90
	// Line 3025, Address: 0x275038, Func Offset: 0x98
	// Line 3027, Address: 0x275040, Func Offset: 0xa0
	// Line 3029, Address: 0x275044, Func Offset: 0xa4
	// Line 3032, Address: 0x27504c, Func Offset: 0xac
	// Line 3033, Address: 0x275058, Func Offset: 0xb8
	// Line 3035, Address: 0x275064, Func Offset: 0xc4
	// Line 3040, Address: 0x275070, Func Offset: 0xd0
	// Line 3038, Address: 0x275074, Func Offset: 0xd4
	// Line 3040, Address: 0x275078, Func Offset: 0xd8
	// Line 3044, Address: 0x27507c, Func Offset: 0xdc
	// Line 3049, Address: 0x275088, Func Offset: 0xe8
	// Line 3051, Address: 0x27508c, Func Offset: 0xec
	// Line 3054, Address: 0x275094, Func Offset: 0xf4
	// Line 3063, Address: 0x2750a0, Func Offset: 0x100
	// Line 3059, Address: 0x2750a4, Func Offset: 0x104
	// Line 3057, Address: 0x2750a8, Func Offset: 0x108
	// Line 3059, Address: 0x2750ac, Func Offset: 0x10c
	// Line 3063, Address: 0x2750b0, Func Offset: 0x110
	// Line 3067, Address: 0x2750b8, Func Offset: 0x118
	// Line 3068, Address: 0x2750bc, Func Offset: 0x11c
	// Func End, Address: 0x2750cc, Func Offset: 0x12c
	scePrintf("MemoryCardFileClose - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2750d0
int MemoryCardFileRead(MEMORYCARDSTATE* pCard)
{
	int lSyncResult;
	int lResult;
	int lCmd;
	// Line 3087, Address: 0x2750d0, Func Offset: 0
	// Line 3090, Address: 0x2750dc, Func Offset: 0xc
	// Line 3093, Address: 0x275100, Func Offset: 0x30
	// Line 3095, Address: 0x275114, Func Offset: 0x44
	// Line 3098, Address: 0x275120, Func Offset: 0x50
	// Line 3100, Address: 0x27513c, Func Offset: 0x6c
	// Line 3107, Address: 0x275144, Func Offset: 0x74
	// Line 3105, Address: 0x275148, Func Offset: 0x78
	// Line 3107, Address: 0x27514c, Func Offset: 0x7c
	// Line 3109, Address: 0x275150, Func Offset: 0x80
	// Line 3110, Address: 0x275158, Func Offset: 0x88
	// Line 3113, Address: 0x275160, Func Offset: 0x90
	// Line 3116, Address: 0x275168, Func Offset: 0x98
	// Line 3120, Address: 0x275170, Func Offset: 0xa0
	// Line 3121, Address: 0x275178, Func Offset: 0xa8
	// Line 3123, Address: 0x27517c, Func Offset: 0xac
	// Line 3126, Address: 0x275184, Func Offset: 0xb4
	// Line 3127, Address: 0x275190, Func Offset: 0xc0
	// Line 3129, Address: 0x27519c, Func Offset: 0xcc
	// Line 3132, Address: 0x2751a8, Func Offset: 0xd8
	// Line 3134, Address: 0x2751ac, Func Offset: 0xdc
	// Line 3138, Address: 0x2751b0, Func Offset: 0xe0
	// Line 3143, Address: 0x2751bc, Func Offset: 0xec
	// Line 3145, Address: 0x2751c0, Func Offset: 0xf0
	// Line 3148, Address: 0x2751c8, Func Offset: 0xf8
	// Line 3151, Address: 0x2751d4, Func Offset: 0x104
	// Line 3153, Address: 0x2751d8, Func Offset: 0x108
	// Line 3155, Address: 0x2751dc, Func Offset: 0x10c
	// Line 3157, Address: 0x2751e0, Func Offset: 0x110
	// Line 3162, Address: 0x2751e8, Func Offset: 0x118
	// Line 3163, Address: 0x2751ec, Func Offset: 0x11c
	// Func End, Address: 0x2751fc, Func Offset: 0x12c
	scePrintf("MemoryCardFileRead - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x275200
int MemoryCardFileWrite(MEMORYCARDSTATE* pCard)
{
	int lSyncResult;
	int lResult;
	int lCmd;
	// Line 3180, Address: 0x275200, Func Offset: 0
	// Line 3183, Address: 0x27520c, Func Offset: 0xc
	// Line 3186, Address: 0x275230, Func Offset: 0x30
	// Line 3188, Address: 0x275244, Func Offset: 0x44
	// Line 3191, Address: 0x275250, Func Offset: 0x50
	// Line 3193, Address: 0x27526c, Func Offset: 0x6c
	// Line 3200, Address: 0x275274, Func Offset: 0x74
	// Line 3198, Address: 0x275278, Func Offset: 0x78
	// Line 3200, Address: 0x27527c, Func Offset: 0x7c
	// Line 3202, Address: 0x275280, Func Offset: 0x80
	// Line 3203, Address: 0x275288, Func Offset: 0x88
	// Line 3206, Address: 0x275290, Func Offset: 0x90
	// Line 3209, Address: 0x275298, Func Offset: 0x98
	// Line 3213, Address: 0x2752a0, Func Offset: 0xa0
	// Line 3215, Address: 0x2752a8, Func Offset: 0xa8
	// Line 3217, Address: 0x2752ac, Func Offset: 0xac
	// Line 3220, Address: 0x2752b4, Func Offset: 0xb4
	// Line 3222, Address: 0x2752c0, Func Offset: 0xc0
	// Line 3224, Address: 0x2752cc, Func Offset: 0xcc
	// Line 3229, Address: 0x2752d8, Func Offset: 0xd8
	// Line 3227, Address: 0x2752dc, Func Offset: 0xdc
	// Line 3229, Address: 0x2752e0, Func Offset: 0xe0
	// Line 3233, Address: 0x2752e4, Func Offset: 0xe4
	// Line 3238, Address: 0x2752f0, Func Offset: 0xf0
	// Line 3240, Address: 0x2752f4, Func Offset: 0xf4
	// Line 3243, Address: 0x2752fc, Func Offset: 0xfc
	// Line 3252, Address: 0x275308, Func Offset: 0x108
	// Line 3248, Address: 0x27530c, Func Offset: 0x10c
	// Line 3246, Address: 0x275310, Func Offset: 0x110
	// Line 3248, Address: 0x275314, Func Offset: 0x114
	// Line 3252, Address: 0x275318, Func Offset: 0x118
	// Line 3257, Address: 0x275320, Func Offset: 0x120
	// Line 3258, Address: 0x275324, Func Offset: 0x124
	// Func End, Address: 0x275334, Func Offset: 0x134
	scePrintf("MemoryCardFileWrite - UNIMPLEMENTED!\n");
}
