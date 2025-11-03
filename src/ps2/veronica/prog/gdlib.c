#include "gdlib.h"
#include "ps2_sg_maloc.h"
#include "main.h"

unsigned int MaxDirectoryEntry = 512;
unsigned int NewDiscCheckSw;
unsigned int GdErrorFlag;
LFOPEN_INFO LfOpenInfo[14];
GDFS_DIRREC GdDirRec;
unsigned char* pDirTbl;
unsigned char* pDirWork;
unsigned int RequestMultiReadFlag;
unsigned int RequestReadBufferFlag;
unsigned int RequestReadFlag;
GDFS CurrentGdFs;
GDFS CurrentGdFsBuf;
GDFS LfGdFs;

// 100% matching!
void LfInitLib() 
{
    unsigned int i;
    
    for (i = 0; i < 14; i++) 
    { 
        LfOpenInfo[i].Flag = 0; 
    } 
} 

// 100% matching! 
void CallbackGdErrorFunc(int param, int err) // first parameter is not present on the debugging symbols
{
    if ((err == -23) || (err == -33)) 
    { 
        GdErrorFlag = 1; 
    }
}

// 99.18% matching
unsigned int InitGdSystem() 
{ 
    unsigned int i;
    int GdErrorCode;

    pDirWork = syMalloc(5484); 
    pDirTbl = syMalloc((MaxDirectoryEntry * 44) + 16);

    RequestReadFlag = 0; 
    RequestReadBufferFlag = 0; 
    RequestMultiReadFlag = 0; 

    LfInitLib();

    for (i = 0; i < 128; i++) 
    { 
        GdErrorCode = gdFsInit(14, pDirWork, MaxDirectoryEntry, pDirTbl); 

        if ((GdErrorCode == -23) || (GdErrorCode == -33)) 
        {
            break;
        }

        if (GdErrorCode == 0) 
        {
            GdDirRec = gdFsCreateDirhn(pDirTbl, MaxDirectoryEntry);
            
            gdFsLoadDir("\\", GdDirRec); 
            gdFsSetDir(GdDirRec);

            gdFsEntryErrFuncAll((GDFS_ERRFUNC)CallbackGdErrorFunc, NULL); 

            return 0; 
        }
    } 

    return 1; 
} 

// 100% matching!
unsigned int InitGdSystemEx(unsigned int MaxDirNum)
{
    MaxDirectoryEntry = MaxDirNum; 
    
    InitGdSystem(); 
}

// 100% matching! 
void ExitGdSystem() 
{ 
    syFree(pDirTbl); 
    syFree(pDirWork); 

    gdFsFinish(); 
} 

// 100% matching! 
int GetFileSize(char* FileName)
{ 
    GDFS_DIRINFO DirInfo;

    if (gdFsGetDirInfo(FileName, &DirInfo) == 0) 
    {
        return DirInfo.fsize;
    }
    else 
    {
        return 0;
    }
} 

// 100% matching! 
int ReadFileEx(char* FileName, void* ReadAddress)
{
    GDFS GdFs;
    int FileSize;

    if (DiscOpenTrayFlag == -1) 
    { 
        return 1; 
    }

    if ((GdFs = gdFsOpen(FileName, GdDirRec)) == NULL)
    {
        return 1; 
    }

    gdFsGetFileSize(GdFs, &FileSize);

    if (gdFsRead(GdFs, (FileSize + 2047) / 2048, ReadAddress) != 0)
    { 
        return 1; 
    }

    gdFsClose(GdFs);

    return 0; 
} 

// 100% matching! 
unsigned int CheckOpenTray()
{ 
    int Stat;

    Stat = gdFsGetDrvStat(); 

    if ((Stat == 6) || (Stat == 9))
    {
        DiscOpenTrayFlag = -1; 
        
        return -1; 
    }

    StatusUpdateCounter--; 
    
    if (!(StatusUpdateCounter & 0x1F)) 
    { 
        gdFsReqDrvStat(); 
    }

    DiscOpenTrayFlag = 0;
    
    return 0; 
} 
