
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
    void    (*SetSctLen)(void* dev);
    Sint32  (*GetNumTr)(void* dev);
    void    (*unk3C)();
    void    (*unk40)();
    Sint32  (*GetNumFilesAll)();
    void    (*unk48)();
    Sint32  (*GetMaxByteRate)(void* dev);
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
    Sint32     unk8;
    Sint32     unkC;
} CVFS_OBJ;

typedef CVFS_OBJ *CVFS;

typedef struct 
{
    CVFS_OBJ*  dev;
    Char8      name[12];
} CVFS_NAME_OBJ;

static CVFS_ERRFN cvfs_errfn;
static void* cvfs_errobj; 
static Char8 cvfs_defdev[16];
static CVFS_OBJ cvfs_tbl[32];
static CVFS_NAME_OBJ D_01E2A604[32];

void toUpperStr(Char8* str);

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

// 100% matching!
void cvFsExecServer(void) 
{
    Sint32 i;

    for (i = 0; i < 32; i++) 
    {
        if ((cvfs_tbl[i].vtbl != NULL) && (cvfs_tbl[i].vtbl->ExecServer != NULL)) 
        {
            cvfs_tbl[i].vtbl->ExecServer();
        }
    }
} 

// cvFsFinish

// 100% matching!
Char8* cvFsGetDefDev(void) 
{
    return cvfs_defdev;
}

// cvFsGetDevName
// cvFsGetFileSize
// cvFsGetFileSizeEx
// cvFsGetFreeSize

// 100% matching!
Sint32 cvFsGetMaxByteRate(CVFS cvfs)
{
    if (cvfs == NULL) 
    {
        cvFsError("cvFsGetMaxByteRate #1:handle error");
    }
    else if (cvfs->vtbl->GetMaxByteRate == NULL) 
    {
        cvFsError("cvFsGetMaxByteRate #2:vtbl error");
    }
    else
    {
        return cvfs->vtbl->GetMaxByteRate(cvfs->dev);
    }
    
    return 0;
}

// 100% matching!
Sint32 cvFsGetNumFiles(const char* devname) 
{
    Sint32 numf;

    if (devname == NULL)
    {
        numf = getNumFilesAll();
    } 
    else
    {
        numf = getNumFiles(devname);
    }
    
    if (numf == 0)
    {
        cvFsError("cvFsGetNumFiles #1:file info error");
    }
    
    return numf;
}

// 100% matching!
Sint32 cvFsGetNumTr(CVFS cvfs)
{
    Sint32 numtr;

    numtr = 0;
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsGetNumTr #1:handle error");
        
        return 0;
    }
    
    if (cvfs->vtbl->GetNumTr != NULL) 
    {
        numtr = cvfs->vtbl->GetNumTr(cvfs->dev); 
    }
    else 
    {
        cvFsError("cvFsGetNumTr #2:vtbl error");
    }
    
    return numtr;
}

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

// 100% matching!
void cvFsSetDefDev(Char8* devname) 
{
    Sint32 nameln;

    if (devname == NULL) 
    {
        cvFsError("cvFsSetDefDev #1:illegal device name");
        return;
    }

    nameln = strlen(devname);

    if (nameln == 0) 
    {
        cvfs_defdev[0] = '\0';
        return;
    }
    
    toUpperStr(devname);

    if (isExistDev(devname, nameln) == 1)
    {
        memcpy(cvfs_defdev, devname, nameln + 1);
        return;
    }
    
    cvFsError("cvFsSetDefDev #2:unknown device name");
}

// 100% matching!
void cvFsSetSctLen(CVFS cvfs)
{
    if (cvfs == NULL)
    {
        cvFsError("cvFsSetSctLen #3:handle error");
    }
    else if (cvfs->vtbl->SetSctLen == NULL)
    {
        cvFsError("cvFsSetSctLen #4:vtbl error");
    }
    else 
    {
        cvfs->vtbl->SetSctLen(cvfs->dev);
    }
}

// 100% matching!
void cvFsStopTr(CVFS cvfs) 
{
    if (cvfs == NULL) 
    {
        cvFsError("cvFsStopTr #1:handle error");
    }
    else if (cvfs->vtbl->StopTr == NULL) 
    {
        cvFsError("cvFsStopTr #2:vtbl error");
    }
    else 
    {
        cvfs->vtbl->StopTr(cvfs->dev);
    }
}

// 100% matching!
Sint32 cvFsTell(CVFS cvfs) 
{
    Sint32 ofst;

    if (cvfs == NULL) 
    {
        cvFsError("cvFsTell #1:handle error");
        
        return 0;
    }

    if (cvfs->vtbl->Tell != NULL) 
    {
        ofst = cvfs->vtbl->Tell(cvfs->dev);
    }
    else 
    {
        ofst = 0;
        
        cvFsError("cvFsTell #2:vtbl error");
    }

    return ofst;
}

// 100% matching!
void getDefDev(Char8* devname) 
{
    Sint32 len;

    len = strlen(cvfs_defdev);

    if (cvfs_defdev[0] == '\0') 
    {
        devname[0] = '\0';
    }
    else
    {
        memcpy(devname, cvfs_defdev, len + 1);
    }
}

// 100% matching!
CVFS getDevice(const Char8 *devname) 
{
    Sint32 nameln;
    Uint32 i;

    nameln = strlen(devname);

    for (i = 0; i < 32; i++)
    {
        if (strncmp(devname, &D_01E2A604[i].name, nameln) == 0)
        {
            return D_01E2A604[i].dev;
        }
    }

    return NULL;
}

// getDevName

// 100% matching!
Sint32 getNumFiles(const char* devname)
{
    CVFS cvfs;
    Sint32 numf;
    Sint32 nameln;
    Sint32 i;

    numf = 0;
    
    nameln = strlen(devname);
    
    for (i = 0; i < 32; i++)
    {
        if (strncmp(devname, &cvfs_tbl[i].dev, nameln) == 0)
        { 
            cvfs = &cvfs_tbl[i];
            
            if ((cvfs->vtbl != NULL) && (cvfs->vtbl->GetNumFilesAll != NULL)) 
            {
                numf = cvfs->vtbl->GetNumFilesAll();
                break; 
            }
        }
    }
    
    return numf;
}

// 100% matching!
Sint32 getNumFilesAll(void)
{
    Sint32 numf;
    Sint32 i;

    numf = 0;
    
    for (i = 0; i < 32; i++) 
    {
        if ((cvfs_tbl[i].vtbl != NULL) && (cvfs_tbl[i].vtbl->GetNumFilesAll != NULL))
        {
            numf += cvfs_tbl[i].vtbl->GetNumFilesAll();
        }
    }
    
    return numf;
}

// 100% matching!
Sint32 isExistDev(const Char8* devname, Sint32 nameln) 
{
    Sint32 i;

    for (i = 0; i < 32; i++) 
    {
        if (strncmp(devname, D_01E2A604[i].name, nameln) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// 100% matching!
void releaseCvFsHn(CVFS cvfs) 
{
    cvfs->dev = NULL;
    
    cvfs->vtbl = NULL;
}

// 100% matching!
void toUpperStr(Char8* str) 
{
    Uint32 len;
    Sint32 i;

    len = strlen(str);

    for (i = 0; i < (len + 1); i++)
    {
        if ((str[i] >= 'a') && (str[i] <= 'z')) 
        {
            str[i] -= 'a' - 'A';
        }
    }
}
