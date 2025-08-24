
typedef void (*CVFS_ERRFN)(void* cvfs_errobj, const Char8* msg, void* obj);

typedef struct _cvfs_vtbl
{
    void    (*ExecServer)();
    void    (*EntryErrFunc)(void* func, void* obj);
    Sint32  (*GetFileSize)(const Char8* fname);
    void    (*unkC)();
    void*   (*Open)(Char8* fname, void* unused, Sint32 rw);
    void    (*Close)(void* dev);
    Sint32  (*Seek)(void* dev, Sint32 ofst, Sint32 whence);
    Sint32  (*Tell)(void* dev);
    Sint32  (*ReqRd)(void* dev, Sint32 nsct, Sint8* buf);
    void    (*unk24)();
    void    (*StopTr)(void* dev);
    Sint8   (*GetStat)(void* dev);
    Sint32  (*GetSctLen)();
    void    (*unk34)();
    Sint32  (*GetNumTr)(void* dev);
    void    (*unk3C)();
    void    (*unk40)();
    void    (*unk44)();
    void    (*unk48)();
    void    (*unk4C)();
    void    (*unk50)();
    void    (*unk54)();
    void    (*unk58)();
    void    (*unk5C)();
    void    (*unk60)();
    void    (*unk64)();
} CVFS_VTBL;

typedef struct cvfs_obj 
{
    CVFS_VTBL* vtbl;
    void*      dev;
} CVFS_OBJ;

typedef CVFS_OBJ *CVFS;

static CVFS_ERRFN cvfs_errfn;
static void* cvfs_errobj; 

// addDevice
// allocCvFsHn

void cvFsAddDev(void* arg0, void* arg1, Sint32 arg2)
{
    scePrintf("cvFsAddDev - UNIMPLEMENTED!\n");
}

// 100% matching!
void cvFsCallUsrErrFn(void* errobj, const Char8* msg, void* obj) 
{
    if (cvfs_errfn != NULL) 
    {
        cvfs_errfn(cvfs_errobj, msg, obj);
    }
}

// cvFsChangeDir
// cvFsClose
// cvFsDelDev
// cvFsDeleteFile

// 100% matching!
void cvFsEntryErrFunc(CVFS_ERRFN func, void* obj) 
{
    if (func == NULL)
    {
        cvfs_errfn = NULL;
        cvfs_errobj = NULL;
    }
    else 
    {
        cvfs_errfn = func;
        cvfs_errobj = obj;
    }
}

// 100% matching!
void cvFsError(const Char8* msg) 
{
    cvFsCallUsrErrFn(&cvfs_errobj, msg, NULL);
}

void cvFsExecServer(void)
{
    scePrintf("cvFsExecServer - UNIMPLEMENTED!\n");
}

// cvFsFinish
// cvFsGetDefDev
// cvFsGetDevName
// cvFsGetFileSize
// cvFsGetFileSizeEx
// cvFsGetFreeSize
// cvFsGetMaxByteRate
// cvFsGetNumFiles
// cvFsGetNumTr

// 100% matching!
Sint32 cvFsGetSctLen(CVFS cvfs)
{
    Sint32 sctlen;

    sctlen = 0;
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsGetSctLen #1:handle error");
        
        return 0;
    }
    
    if (cvfs->vtbl->GetSctLen != NULL) 
    {
        sctlen = cvfs->vtbl->GetSctLen(cvfs->dev); 
    }
    else 
    {
        cvFsError("cvFsGetSctLen #2:vtbl error");
    }
    
    return sctlen;
}

// 100% matching!
Sint8 cvFsGetStat(CVFS cvfs)
{
    Sint8 stat;

    stat = 3;
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsGetStat #1:handle error");
        
        return 3;
    }
    
    if (cvfs->vtbl->GetStat != NULL) 
    {
        stat = cvfs->vtbl->GetStat(cvfs->dev); 
    }
    else 
    {
        cvFsError("cvFsGetStat #2:vtbl error");
    }
    
    return stat;
}

// cvFsInit
// cvFsIsExistFile
// cvFsLoadDirInfo
// cvFsMakeDir
// cvFsOpen
// cvFsOptFn1
// cvFsOptFn2
// cvFsRemoveDir
// cvFsReqRd
// cvFsReqWr
// cvFsSeek

void cvFsSetDefDev(void* arg0)
{
    scePrintf("cvFsSetDefDev - UNIMPLEMENTED!\n");
}

// cvFsSetSctLen
// cvFsStopTr
// cvFsTell
// getDefDev
// getDevice
// getDevName
// getNumFiles
// getNumFilesAll
// isExistDev
// releaseCvFsHn
// toUpperStr
