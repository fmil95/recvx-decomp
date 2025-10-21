#include "cri_cvfs.h"

/* cvFsOpen() looks a bit strange with all the casts, it seems that there is one struct missing for the handle component and cvFsInit() 
   further cements that idea. Additionally, functions like cvFsAddDev() parse the device to its interface instead of manually accessing 
   it from the CVFS_OBJ struct, this could be due to polymorphism but maybe there is some cleaner way to do it? */

static Char8* volatile cvfs_build = "\ncvFs Ver.2.11 Build:Jan 26 2001 09:55:14\n";
static CVFS_ERRFN cvfs_errfn = NULL;
static void* cvfs_errobj = NULL; 
static Sint32 cvfs_init_cnt = 0;
static Char8 cvfs_defdev[9];
static CVFS_OBJ cvfs_obj[40];
static CVFS_NAME_OBJ cvfs_tbl[32];
static CVFS_NAME_OBJ D_01E2A604[32];

// 100% matching!
CVFS addDevice(Char8* devname, void* (*getdevif()))
{
    CVFS cvfs;
    Sint32 i;

    i = 0;

    toUpperStr(devname);
    
    cvfs = (CVFS)getdevif();

    if (getDevice(devname) != NULL)
    {
        return cvfs;
    }

    for ( ; i < 32; i++) 
    {
        if (cvfs_tbl[i].name[0] == '\0')
        {
            break;
        }
    }

    if (i == 32)
    {
        return cvfs; 
    }

    cvfs_tbl[i].dev = cvfs;
    
    memcpy(cvfs_tbl[i].name, devname, strlen(devname) + 1);

    return cvfs;
}

// 100% matching!
CVFS allocCvFsHn(void) 
{
    Sint32 i;

    for (i = 0; i < 40; i++) 
    {
        if (cvfs_obj[i].dev == NULL) 
        {
            break;
        }
    }

    if (i == 40) 
    {
        return NULL;
    }
    
    return &cvfs_obj[i];
}

// 100% matching!
void cvFsAddDev(Char8* devname, void* (*getdevif()), void* unused) 
{
    CVFS cvfs;

    if (devname == NULL) 
    {
        cvFsError("cvFsAddDev #1:illegal device name");
    }
    else if (getdevif == NULL) 
    {
        cvFsError("cvFsAddDev #2:illegal I/F func name");
    }
    else 
    {
        cvfs = addDevice(devname, getdevif);
    
        if (((CVFS_VTBL*)cvfs)->EntryErrFunc != NULL) 
        {
            ((CVFS_VTBL*)cvfs)->EntryErrFunc(cvFsCallUsrErrFn, NULL);
        }
    }
}

// 100% matching!
void cvFsCallUsrErrFn(void* errobj, const Char8* msg, void* obj) 
{
    if (cvfs_errfn != NULL) 
    {
        cvfs_errfn(cvfs_errobj, msg, obj);
    }
}

// 100% matching!
Sint32 cvFsChangeDir(const Char8* dirname) 
{
    CVFS cvfs;
    Char8 devname[297];
    Char8 fname[297];

    if (dirname == NULL) 
    {
        cvFsError("cvFsChangeDir #1:illegal directory name");
        
        return -1;
    }
    
    getDevName(devname, fname, dirname);
    
    if (fname[0] == '\0') 
    {
        cvFsError("cvFsChangeDir #1:illegal directory name");
        
        return -1;
    }
    
    if (devname[0] == '\0') 
    {
        getDefDev(devname);
        
        if (devname[0] == '\0') 
        {
            cvFsError("cvFsChangeDir #2:illegal device name");
            
            return -1;
        }
    }
    
    cvfs = getDevice(devname); 
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsChangeDir #3:device not found");
        
        return -1;
    }
    
    if (((CVFS_VTBL*)cvfs)->ChangeDir == NULL) 
    {
        cvFsError("cvFsChangeDir #4:vtbl error");
        
        return -1;
    }

    // might not really return here, but a VTBL callback signature is usually the same as that of the function which invokes it  
    return ((CVFS_VTBL*)cvfs)->ChangeDir(fname); 
}

// 100% matching!
void cvFsClose(CVFS cvfs)
{
    if (cvfs == NULL) 
    {
        cvFsError("cvFsClose #1:handle error");
        return;
    }
    
    if (cvfs->vtbl->Close != NULL) 
    {
        cvfs->vtbl->Close(cvfs->dev);
        
        releaseCvFsHn(cvfs);
        return;
    }
    else 
    {
        cvFsError("cvFsClose #2:vtbl error");
    }
}

// 100% matching!
void cvFsDelDev(Char8* devname)
{
    Sint32 nameln;
    Uint32 i;

    if (devname == NULL)
    {
        cvFsError("cvFsDelDev #1:illegal device name");
        return;
    }
    
    nameln = strlen(devname);

    for (i = 0; i < 32; i++) 
    {
        if (strncmp(devname, D_01E2A604[i].name, nameln) == 0) 
        {
            D_01E2A604[i].name[0] = '\0';
            return;
        }
    }
}

// 100% matching!
Sint32 cvFsDeleteFile(const Char8* dirname) 
{
    CVFS cvfs;
    Char8 devname[297];
    Char8 fname[297];

    if (dirname == NULL) 
    {
        cvFsError("cvFsDeleteFile #1:illegal file name");
        
        return -1;
    }
    
    getDevName(devname, fname, dirname);
    
    if (fname[0] == '\0') 
    {
        cvFsError("cvFsDeleteFile #1:illegal file name");
        
        return -1;
    }
    
    if (devname[0] == '\0') 
    {
        getDefDev(devname);
        
        if (devname[0] == '\0') 
        {
            cvFsError("cvFsDeleteFile #2:illegal device name");
            
            return -1;
        }
    }
    
    cvfs = getDevice(devname); 
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsDeleteFile #3:device not found");
        
        return -1;
    }
    
    if (((CVFS_VTBL*)cvfs)->DeleteFile == NULL) 
    {
        cvFsError("cvFsDeleteFile #4:vtbl error");
        
        return -1;
    }

    // same situation as cvFsChangeDir()
    return ((CVFS_VTBL*)cvfs)->DeleteFile(fname); 
}

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
    CVFS cvfs;
    Sint32 i;

    for (i = 0; i < 32; i++) 
    {
        cvfs = (CVFS)&cvfs_tbl[i];
        
        if ((cvfs->vtbl != NULL) && (cvfs->vtbl->ExecServer != NULL)) 
        {
            cvfs->vtbl->ExecServer();
        }
    }
} 

// 100% matching!
void cvFsFinish(void) 
{
    CVFS cvfs1;
    CVFS cvfs2; 
    Sint32 i;

    if (--cvfs_init_cnt == 0)
    {
        for (i = 0; i < 40; i++) 
        {
            cvfs1 = &cvfs_obj[i];
            
            if (cvfs1->vtbl != NULL)
            {
                cvfs2 = (CVFS)&cvfs_obj[i].dev; 
                
                cvfs1->vtbl->Close(cvfs1->dev);
            }
            
            cvfs2 = (CVFS)&cvfs_obj[i].dev; 
    
            cvfs1->vtbl = NULL;
            cvfs2->vtbl = NULL;
        } 
    
        for (i = 0; i < 32; i++) 
        {
            cvfs_tbl[i].name[0] = '\0'; 
        } 
        
        memset(cvfs_defdev, 0, sizeof(cvfs_defdev));
        
        cvfs_defdev[0] = '\0';
    }
}

// 100% matching!
Char8* cvFsGetDefDev(void) 
{
    return cvfs_defdev;
}

// 100% matching!
CVFS_NAME cvFsGetDevName(CVFS cvfs)
{
    Sint32 i;

    if (cvfs == NULL) 
    {
        cvFsError("cvFsGetDevName #1:vtbl error");
        
        return NULL;
    }
    
    for (i = 0; i < 32; i++) 
    {
        if (((CVFS)&cvfs_tbl[i])->vtbl == cvfs->vtbl) 
        {
            break;
        } 
    } 
    
    return &D_01E2A604[i];
}

// 100% matching!
Sint32 cvFsGetFileSize(const Sint8* dirname) 
{
    CVFS cvfs;
    Char8 devname[297];
    Char8 fname[297];

    if (dirname == NULL) 
    {
        cvFsError("cvFsGetFileSize #1:illegal file name");
        
        return 0;
    }
    
    getDevName(devname, fname, (const Char8*)dirname);
    
    if (fname[0] == '\0') 
    {
        cvFsError("cvFsGetFileSize #1:illegal file name");
        
        return 0;
    }
    
    if (devname[0] == '\0') 
    {
        getDefDev(devname);
        
        if (devname[0] == '\0') 
        {
            cvFsError("cvFsGetFileSize #2:illegal device name");
            
            return 0;
        }
    }
    
    cvfs = getDevice(devname); 
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsGetFileSize #3:device not found");
        
        return 0;
    }
    
    if (((CVFS_VTBL*)cvfs)->GetFileSize == NULL) 
    {
        cvFsError("cvFsGetFileSize #4:vtbl error");
        
        return 0;
    }

    // same situation as cvFsChangeDir()
    return ((CVFS_VTBL*)cvfs)->GetFileSize(fname); 
}

// 100% matching!
Sint32 cvFsGetFileSizeEx(const Char8* dirname, Sint32 arg1) 
{
    CVFS cvfs;
    Char8 devname[297];
    Char8 fname[297];

    if (dirname == NULL) 
    {
        cvFsError("cvFsGetFileSize #1:illegal file name");
        
        return 0;
    }
    
    getDevName(devname, fname, dirname);
    
    if (fname[0] == '\0') 
    {
        cvFsError("cvFsGetFileSize #1:illegal file name");
        
        return 0;
    }
    
    if (devname[0] == '\0') 
    {
        getDefDev(devname);
        
        if (devname[0] == '\0') 
        {
            cvFsError("cvFsGetFileSize #2:illegal device name");
            
            return 0;
        }
    }
    
    cvfs = getDevice(devname); 
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsGetFileSize #3:device not found");
        
        return 0;
    }
    
    if (((CVFS_VTBL*)cvfs)->GetFileSizeEx == NULL) 
    {
        cvFsError("cvFsGetFileSize #4:vtbl error");
        
        return 0;
    }

    // same situation as cvFsChangeDir()
    return ((CVFS_VTBL*)cvfs)->GetFileSizeEx(fname, arg1); 
}

// 100% matching!
Sint32 cvFsGetFreeSize(Char8* fname) 
{
    CVFS cvfs;
    Char8 devname[297];
    Sint32 size;
    Sint32 nameln;
    Sint32 i;
    
    size = 0;
    
    if ((fname == NULL) || (fname[0] == '\0'))
    {
        getDefDev(devname);
        
        if (devname[0] == '\0')
        {
            cvFsError("cvFsGetFreeSize #5:device not found");
            
            return 0;
        }
    } 
    else
    {
        memcpy(devname, fname, strlen(fname) + 1);
    }
    
    nameln = strlen(devname);
    
    if (nameln <= 0) 
    {
        cvFsError("cvFsGetFreeSize #5:device not found");
        
        return 0;
    }
    
    for (i = 0; i < 32; i++)
    {
        if (strncmp(devname, &D_01E2A604[i].name, nameln) == 0) 
        {
            cvfs = (CVFS)&D_01E2A604[i].dev;
            
            if (cvfs->vtbl == NULL) 
            {
                cvFsError("cvFsGetFreeSize #6:vtbl error");
                
                return 0;
            } 

            if (cvfs->vtbl->GetFreeSize != NULL) 
            {
                size = cvfs->vtbl->GetFreeSize();
            }
        }
    }
    
    return size;
}

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

// 100% matching!
void cvFsInit(void) 
{
    CVFS cvfs1;
    CVFS cvfs2; 
    Sint32 i;

    if (cvfs_init_cnt == 0)
    {
        for (i = 0; i < 40; i++) 
        {
            cvfs1 = &cvfs_obj[i];
            cvfs2 = (CVFS)&cvfs_obj[i].dev; 
    
            cvfs1->vtbl = NULL;
            cvfs2->vtbl = NULL;
        } 
    
        for (i = 0; i < 32; i++) 
        {
            cvfs_tbl[i].name[0] = '\0'; 
        } 
        
        memset(cvfs_defdev, 0, sizeof(cvfs_defdev));
        
        cvfs_defdev[0] = '\0';
    }

    cvfs_init_cnt++;
}

// 100% matching!
Sint32 cvFsIsExistFile(const Char8* dirname) 
{
    CVFS cvfs;
    Char8 devname[297];
    Char8 fname[297];

    getDevName(devname, fname, dirname);
    
    if (fname[0] == '\0') 
    {
        cvFsError("cvFsIsExistFile #1:illegal file name");
        
        return 0;
    }
    
    if (devname[0] == '\0') 
    {
        getDefDev(devname);
        
        if (devname[0] == '\0') 
        {
            cvFsError("cvFsIsExistFile #2:illegal device name");
            
            return 0;
        }
    }
    
    cvfs = getDevice(devname); 
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsIsExistFile #3:device not found");
        
        return 0;
    }
    
    if (((CVFS_VTBL*)cvfs)->IsExistFile == NULL) 
    {
        cvFsError("cvFsIsExistFile #4:vtbl error");
        
        return 0;
    }

    // same situation as cvFsChangeDir()
    return ((CVFS_VTBL*)cvfs)->IsExistFile(fname); 
}

// 100% matching!
Sint32 cvFsLoadDirInfo(const Char8* dirname, Sint32 arg1, Sint32 rw) 
{
    CVFS cvfs;
    Char8 devname[297];
    Char8 fname[297];
    Sint32 ret;

    getDevName(devname, fname, dirname);

    ret = 0;
    
    if (devname[0] == '\0') 
    {
        getDefDev(devname);
        
        if (devname[0] == '\0') 
        {
            cvFsError("cvFsIsExistFile #2:illegal device name");
            
            return ret;
        }
    }
    
    cvfs = getDevice(devname); 
    
    if ((cvfs != NULL) && (((CVFS_VTBL*)cvfs)->LoadDirInfo != NULL)) 
    {
        ret = ((CVFS_VTBL*)cvfs)->LoadDirInfo(dirname, arg1, rw); 
    }

    return ret; 
}

// 100% matching!
Sint32 cvFsMakeDir(const Char8* dirname) 
{
    CVFS cvfs;
    Char8 devname[48];
    Char8 fname[48];

    if (dirname == NULL) 
    {
        cvFsError("cvFsMakeDir #1:illegal directory name");
        
        return -1;
    }

    getDevName(devname, fname, dirname);
    
    if (fname[0] == '\0') 
    {
        cvFsError("cvFsMakeDir #1:illegal directory name");
        
        return -1;
    }
    
    if (devname[0] == '\0') 
    {
        getDefDev(devname);
        
        if (devname[0] == '\0') 
        {
            cvFsError("cvFsMakeDir #2:illegal device name");
            
            return -1;
        }
    }
    
    cvfs = getDevice(devname); 
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsMakeDir #3:device not found");
        
        return -1;
    }
    
    if (((CVFS_VTBL*)cvfs)->MakeDir == NULL) 
    {
        cvFsError("cvFsMakeDir #4:vtbl error");
        
        return -1;
    }

    // same situation as cvFsChangeDir()
    return ((CVFS_VTBL*)cvfs)->MakeDir(fname); 
}

// 100% matching!
CVFS cvFsOpen(const Sint8* dirname, void* arg1, CVE_FS_OP rw)
{
    CVFS cvfs1;
    CVFS_NAME cvfs2;
    Char8 devname[297];
    Char8 fname[297];

    if (dirname == NULL) 
    {
        cvFsError("cvFsOpen #1:illegal file name");
        
        return NULL;
    }

    getDevName(devname, fname, (Char8*)dirname);
    
    if (fname[0] == '\0') 
    {
        cvFsError("cvFsOpen #1:illegal file name");
        
        return NULL;
    }
    
    if (devname[0] == '\0') 
    {
        getDefDev((Char8*)devname);
        
        if (devname[0] == '\0') 
        {
            cvFsError("cvFsOpen #2:illegal device name");
            
            return NULL;
        }
    }

    cvfs2 = (CVFS_NAME)allocCvFsHn(); 
    
    if (cvfs2 == NULL) 
    {
        cvFsError("cvFsOpen #3:failed handle alloced");
        
        return NULL;
    }
    
    cvfs1 = getDevice((Char8*)devname); 

    cvfs2->dev = cvfs1; 
    
    if (cvfs1 == NULL) 
    {
        releaseCvFsHn((CVFS)cvfs2);
        
        cvFsError("cvFsOpen #4:device not found");
        
        return NULL;
    }
    
    if (((CVFS_VTBL*)cvfs1)->Open != NULL) 
    {
        ((CVFS)cvfs2)->dev = (void*)((CVFS_VTBL*)cvfs1)->Open((Sint8*)fname, arg1, rw);
    }
    else 
    {
        cvFsError("cvFsOpen #5:vtbl error");
            
        return NULL;
    }
    
    if (((CVFS)cvfs2)->dev == NULL) 
    {
        releaseCvFsHn((CVFS)cvfs2);
        
        cvFsError("cvFsOpen #6:open failed");
        
        return NULL;
    }

    return (CVFS)cvfs2;
}

// 100% matching!
Sint32 cvFsOptFn1(CVFS cvfs) 
{
    Sint32 ret;

    ret = 0;
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsOptFn1 #1:handle error");
        
        return ret;
    }
    
    if (cvfs->vtbl->OptFn1 != NULL) 
    {
        ret = cvfs->vtbl->OptFn1(cvfs->dev);
    } 
    else 
    {
        cvFsError("cvFsOptFn1 #2:vtbl error");
    }
    
    return ret;
}

// 100% matching!
Sint32 cvFsOptFn2(CVFS cvfs) 
{
    Sint32 ret;

    ret = 0;
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsOptFn2 #1:handle error");
        
        return ret;
    }
    
    if (cvfs->vtbl->OptFn2 != NULL) 
    {
        ret = cvfs->vtbl->OptFn2(cvfs->dev);
    } 
    else 
    {
        cvFsError("cvFsOptFn2 #2:vtbl error");
    }
    
    return ret;
}

// 100% matching!
Sint32 cvFsRemoveDir(const Char8* dirname) 
{
    CVFS cvfs;
    Char8 devname[297];
    Char8 fname[297];

    if (dirname == NULL) 
    {
        cvFsError("cvFsRemoveDir #1:illegal directory name");
        
        return -1;
    }

    getDevName(devname, fname, dirname);
    
    if (fname[0] == '\0') 
    {
        cvFsError("cvFsRemoveDir #1:illegal directory name");
        
        return -1;
    }
    
    if (devname[0] == '\0') 
    {
        getDefDev(devname);
        
        if (devname[0] == '\0') 
        {
            cvFsError("cvFsRemoveDir #2:illegal device name");
            
            return -1;
        }
    }
    
    cvfs = getDevice(devname); 
    
    if (cvfs == NULL) 
    {
        cvFsError("cvFsRemoveDir #3:device not found");
        
        return -1;
    }
    
    if (((CVFS_VTBL*)cvfs)->RemoveDir == NULL) 
    {
        cvFsError("cvFsRemoveDir #4:vtbl error");
        
        return -1;
    }

    // same situation as cvFsChangeDir()
    return ((CVFS_VTBL*)cvfs)->RemoveDir(fname); 
}

// 100% matching!
Sint32 cvFsReqRd(CVFS cvfs, Sint32 nsct, Sint8* buf)
{
    Sint32 ret;

    if (cvfs == NULL) 
    {
        cvFsError("cvFsReqRd #1:handle error");
        
        return 0;
    }
    
    if (cvfs->vtbl->ReqRd != NULL) 
    {
        ret = cvfs->vtbl->ReqRd(cvfs->dev, nsct, buf);
    } 
    else 
    {
        ret = 0;
        
        cvFsError("cvFsReqRd #2:vtbl error");
    }
    
    return ret;
}

// 100% matching!
Sint32 cvFsReqWr(CVFS cvfs, Sint32 nsct, Sint8* buf)
{
    Sint32 ret;

    ret = 0;

    if (cvfs == NULL) 
    {
        cvFsError("cvFsReqWr #1:handle error");
        
        return ret;
    }
    
    if (cvfs->vtbl->ReqRw != NULL) 
    {
        ret = cvfs->vtbl->ReqRw(cvfs->dev, nsct, buf);
    } 
    else 
    {
        cvFsError("cvFsReqWr #2:vtbl error");
    }
    
    return ret;
}

// 100% matching!
Sint32 cvFsSeek(CVFS cvfs, Sint32 ofst, Sint32 whence)
{
    Sint32 ret;

    if (cvfs == NULL) 
    {
        cvFsError("cvFsSeek #1:handle error");
        
        return 0;
    }
    
    if (cvfs->vtbl->Seek != NULL) 
    {
        ret = cvfs->vtbl->Seek(cvfs->dev, ofst, whence);
    } 
    else 
    {
        ret = 0;
        
        cvFsError("cvFsSeek #2:vtbl error");
    }
    
    return ret;
}

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

// 100% matching!
void getDevName(Char8* devname, Char8* fname, const Char8* dirname) 
{
    Sint32 i;
    Sint32 j;

    if (dirname == NULL) 
    {
        return;
    }

    for (i = 0; (i < 297) && ((dirname[i] != ':') && (dirname[i] != '\0')); i++) 
    {
        devname[i] = dirname[i];
    }
    
    if (dirname[i] == '\0') 
    {
        devname[i] = '\0';
        
        memcpy(fname, devname, strlen(devname) + 1);
        
        devname[0] = '\0';
        return;
    }

    devname[i] = '\0';
    
    i++;

    for (j = i; (j < 297) && ((dirname[j] != ':') && (dirname[j] != '\0')); j++) 
    {
        fname[j - i] = dirname[j];
    }

    fname[j - i] = '\0';
    
    toUpperStr(devname);
}

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
        if (strncmp(devname, &cvfs_tbl[i].name, nameln) == 0)
        { 
            cvfs = (CVFS)&cvfs_tbl[i];
            
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
    CVFS cvfs;
    Sint32 numf;
    Sint32 i;

    numf = 0;
    
    for (i = 0; i < 32; i++) 
    {
        cvfs = (CVFS)&cvfs_tbl[i];
        
        if ((cvfs->vtbl != NULL) && (cvfs->vtbl->GetNumFilesAll != NULL))
        {
            numf += cvfs->vtbl->GetNumFilesAll();
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
