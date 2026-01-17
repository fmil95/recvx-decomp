#include "cri_cvfs.h"

//#include <string.h>

char* volatile cvfs_build = "\ncvFs Ver.2.11 Build:Jan 26 2001 09:55:14\n";
static CVF_FS_ERRFN cvfs_errfn = NULL;
static void *cvfs_errobj = NULL; 
Sint32 cvfs_init_cnt = 0;
static Sint8 cvfs_defdev[9];
static CVS_FS_OBJ cvfs_obj[40];
static CVF_FS_TBL cvfs_tbl[32];

// 100% matching!
static CVFS_IF addDevice(Sint8 *devname, CVF_FS_VTBLFN func)
{
    Sint32 lp;
	CVFS_IF fsif;

    lp = 0;

    toUpperStr(devname);
    
    fsif = func();

    if (getDevice(devname) != NULL)
    {
        return fsif;
    }

    for ( ; lp < 32; lp++) 
    {
        if (cvfs_tbl[lp].dname[0] == '\0')
        {
            break;
        }
    }

    if (lp == 32)
    {
        return fsif; 
    }

    cvfs_tbl[lp].vtbl = fsif;
    
    memcpy(cvfs_tbl[lp].dname, devname, strlen((const char*)devname) + 1);

    return fsif;
}

// 100% matching!
static void* allocCvFsHn()
{
    Sint32 lp;

    for (lp = 0; lp < 40; lp++) 
    {
        if (cvfs_obj[lp].obj == NULL) 
        {
            break;
        }
    }

    if (lp == 40) 
    {
        return NULL;
    }
    
    return &cvfs_obj[lp];
}

// 100% matching!
void cvFsAddDev(Sint8 *devname, CVF_FS_VTBLFN vtblfn, void *init_prm)
{
    CVFS_IF fsif;

    if (devname == NULL) 
    {
        cvFsError((const Sint8*)"cvFsAddDev #1:illegal device name");
    }
    else if (vtblfn == NULL) 
    {
        cvFsError((const Sint8*)"cvFsAddDev #2:illegal I/F func name");
    }
    else 
    {
        fsif = addDevice(devname, vtblfn);
    
        if (fsif->EntryErrFunc != NULL) 
        {
            fsif->EntryErrFunc(cvFsCallUsrErrFn, NULL);
        }
    }
}

// 100% matching!
void cvFsCallUsrErrFn(void *obj, const Sint8 *msg, void *hndl)
{
    if (cvfs_errfn != NULL) 
    {
        cvfs_errfn(cvfs_errobj, msg, hndl);
    }
}

// 100% matching!
Sint32 cvFsChangeDir(const Sint8 *dirname)
{
    Sint32 ret;
	CVFS_IF cvfsif;
	Sint8 dev[297];
	Sint8 dir[297];

    ret = -1;
    
    if (dirname == NULL) 
    {
        cvFsError((const Sint8*)"cvFsChangeDir #1:illegal directory name");
        
        return ret;
    }
    
    getDevName(dev, dir, dirname);
    
    if (dir[0] == '\0') 
    {
        cvFsError((const Sint8*)"cvFsChangeDir #1:illegal directory name");
        
        return ret;
    }
    
    if (dev[0] == '\0') 
    {
        getDefDev(dev);
        
        if (dev[0] == '\0') 
        {
            cvFsError((const Sint8*)"cvFsChangeDir #2:illegal device name");
            
            return ret;
        }
    }
    
    cvfsif = getDevice(dev); 
    
    if (cvfsif == NULL) 
    {
        cvFsError((const Sint8*)"cvFsChangeDir #3:device not found");
        
        return ret;
    }
    
    if (cvfsif->ChangeDir == NULL) 
    {
        cvFsError((const Sint8*)"cvFsChangeDir #4:vtbl error");
        
        return ret;
    }

    ret = cvfsif->ChangeDir(dir);

    return ret; 
}

// 100% matching!
void cvFsClose(CVFS cvfs)
{
    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsClose #1:handle error");
        return;
    }
    
    if (cvfs->vtbl->Close != NULL) 
    {
        cvfs->vtbl->Close(cvfs->obj);
        
        releaseCvFsHn(cvfs);
        return;
    }
    else 
    {
        cvFsError((const Sint8*)"cvFsClose #2:vtbl error");
    }
}

// 100% matching!
void cvFsDelDev(Sint8 *devname)
{
    Uint32 len;
	Uint32 lp;
    
    if (devname == NULL)
    {
        cvFsError((const Sint8*)"cvFsDelDev #1:illegal device name");
        return;
    }
    
    len = strlen((const char*)devname);

    for (lp = 0; lp < 32; lp++) 
    {
        if (strncmp((const char*)devname, (const char*)cvfs_tbl[lp].dname, len) == 0) 
        {
            cvfs_tbl[lp].dname[0] = '\0';
            return;
        }
    }
}

// 100% matching!
Sint32 cvFsDeleteFile(const Sint8 *fname)
{
    Sint32 ret;
	CVFS_IF cvfsif;
	Sint8 dev[297];
	Sint8 dir[297];

    ret = -1;
    
    if (fname == NULL) 
    {
        cvFsError((const Sint8*)"cvFsDeleteFile #1:illegal file name");
        
        return ret;
    }
    
    getDevName(dev, dir, fname);
    
    if (dir[0] == '\0') 
    {
        cvFsError((const Sint8*)"cvFsDeleteFile #1:illegal file name");
        
        return ret;
    }
    
    if (dev[0] == '\0') 
    {
        getDefDev(dev);
        
        if (dev[0] == '\0') 
        {
            cvFsError((const Sint8*)"cvFsDeleteFile #2:illegal device name");
            
            return ret;
        }
    }
    
    cvfsif = getDevice(dev); 
    
    if (cvfsif == NULL) 
    {
        cvFsError((const Sint8*)"cvFsDeleteFile #3:device not found");
        
        return ret;
    }
    
    if (cvfsif->DeleteFile == NULL) 
    {
        cvFsError((const Sint8*)"cvFsDeleteFile #4:vtbl error");
        
        return ret;
    }

    ret = cvfsif->DeleteFile(dir);

    return ret; 
}

// 100% matching!
void cvFsEntryErrFunc(CVF_FS_ERRFN errfn, void *obj)
{
    if (errfn == NULL)
    {
        cvfs_errfn = NULL;
        cvfs_errobj = NULL;
    }
    else 
    {
        cvfs_errfn = errfn;
        cvfs_errobj = obj;
    }
}

// 100% matching!
void cvFsError(const Sint8 *msg)
{
    cvFsCallUsrErrFn(&cvfs_errobj, msg, NULL);
}

// 100% matching!
void cvFsExecServer(void) 
{
    CVFS_IF cvfsif;
	Sint32 lp;
    
    for (lp = 0; lp < 32; lp++) 
    {
        cvfsif = cvfs_tbl[lp].vtbl;
        
        if ((cvfsif != NULL) && (cvfsif->ExecServer != NULL)) 
        {
            cvfsif->ExecServer();
        }
    }
} 

// 100% matching!
void cvFsFinish(void) 
{
    CVFS cvfs;
    CVFS cvfs2; 
    Sint32 lp;

    if (--cvfs_init_cnt == 0)
    {
        for (lp = 0; lp < 40; lp++) 
        {
            cvfs = &cvfs_obj[lp];
            
            if (cvfs->vtbl != NULL)
            {
                cvfs2 = (CVFS)&cvfs_obj[lp].obj; 
                
                cvfs->vtbl->Close(cvfs->obj);
            }
            
            cvfs2 = (CVFS)&cvfs_obj[lp].obj; 
    
            cvfs->vtbl = NULL;
            cvfs2->vtbl = NULL;
        } 
    
        for (lp = 0; lp < 32; lp++) 
        {
            cvfs_tbl[lp].dname[0] = '\0'; 
        } 
        
        memset(cvfs_defdev, 0, sizeof(cvfs_defdev));
        
        cvfs_defdev[0] = '\0';
    }
}

// 100% matching!
Sint8* cvFsGetDefDev(void)
{
    return cvfs_defdev;
}

// 100% matching!
Sint8* cvFsGetDevName(CVFS cvfs)
{
    Sint32 lp;

    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetDevName #1:vtbl error");
        
        return NULL;
    }
    
    for (lp = 0; lp < 32; lp++) 
    {
        if (cvfs_tbl[lp].vtbl == cvfs->vtbl) 
        {
            break;
        } 
    } 
    
    return cvfs_tbl[lp].dname;
}

// 100% matching!
Sint32 cvFsGetFileSize(const Sint8 *fname)
{
    Sint32 val;
	CVFS_IF cvfsif;
	Sint8 dev[297];
	Sint8 file[297];

    val = 0;
    
    if (fname == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetFileSize #1:illegal file name");
        
        return val;
    }
    
    getDevName(dev, file, fname);
    
    if (file[0] == '\0') 
    {
        cvFsError((const Sint8*)"cvFsGetFileSize #1:illegal file name");
        
        return val;
    }
    
    if (dev[0] == '\0') 
    {
        getDefDev(dev);
        
        if (dev[0] == '\0') 
        {
            cvFsError((const Sint8*)"cvFsGetFileSize #2:illegal device name");
            
            return val;
        }
    }
    
    cvfsif = getDevice(dev); 
    
    if (cvfsif == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetFileSize #3:device not found");
        
        return val;
    }
    
    if (cvfsif->GetFileSize == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetFileSize #4:vtbl error");
        
        return val;
    }

    val = cvfsif->GetFileSize(file);

    return val; 
}

// 100% matching!
Sint32 cvFsGetFileSizeEx(const Sint8 *fname, void *prm)
{
    Sint32 val;
	CVFS_IF cvfsif;
	Sint8 dev[297];
	Sint8 file[297];

    val = 0;
    
    if (fname == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetFileSize #1:illegal file name");
        
        return val;
    }
    
    getDevName(dev, file, fname);
    
    if (file[0] == '\0') 
    {
        cvFsError((const Sint8*)"cvFsGetFileSize #1:illegal file name");
        
        return val;
    }
    
    if (dev[0] == '\0') 
    {
        getDefDev(dev);
        
        if (dev[0] == '\0') 
        {
            cvFsError((const Sint8*)"cvFsGetFileSize #2:illegal device name");
            
            return val;
        }
    }
    
    cvfsif = getDevice(dev); 
    
    if (cvfsif == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetFileSize #3:device not found");
        
        return val;
    }
    
    if (cvfsif->GetFileSizeEx == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetFileSize #4:vtbl error");
        
        return val;
    }

    val = cvfsif->GetFileSizeEx(file, prm);

    return val; 
}

// 100% matching!
Sint32 cvFsGetFreeSize(Sint8 *devname)
{
    Sint32 val;
	Sint32 len;
	Sint32 lp;
	CVFS_IF cvfsif;
	Sint8 dev[297];
    
    val = 0;
    
    if ((devname == NULL) || (devname[0] == '\0'))
    {
        getDefDev(dev);
        
        if (dev[0] == '\0')
        {
            cvFsError((const Sint8*)"cvFsGetFreeSize #5:device not found");
            
            return val;
        }
    } 
    else
    {
        memcpy(dev, devname, strlen((const char*)devname) + 1);
    }
    
    len = strlen((const char*)dev);
    
    if (len <= 0) 
    {
        cvFsError((const Sint8*)"cvFsGetFreeSize #5:device not found");
        
        return val;
    }
    
    for (lp = 0; lp < 32; lp++)
    {
        if (strncmp((char*)dev, (char*)&cvfs_tbl[lp].dname, len) == 0) 
        {
            cvfsif = cvfs_tbl[lp].vtbl;
            
            if (cvfsif == NULL) 
            {
                cvFsError((const Sint8*)"cvFsGetFreeSize #6:vtbl error");
                
                return 0;
            } 

            if (cvfsif->GetFreeSize != NULL) 
            {
                val = cvfsif->GetFreeSize();
            }
        }
    }
    
    return val;
}

// 100% matching!
Sint32 cvFsGetMaxByteRate(CVFS cvfs)
{
    Sint32 val;

    val = 0;
    
    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetMaxByteRate #1:handle error");
    }
    else if (cvfs->vtbl->GetMaxByteRate == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetMaxByteRate #2:vtbl error");
    }
    else
    {
        val = cvfs->vtbl->GetMaxByteRate(cvfs->obj);
        
        return val;
    }
    
    return val;
}

// 100% matching!
Sint32 cvFsGetNumFiles(const Sint8 *devname)
{
    Sint32 val;

    if (devname == NULL)
    {
        val = getNumFilesAll();
    } 
    else
    {
        val = getNumFiles(devname);
    }
    
    if (val == 0)
    {
        cvFsError((const Sint8*)"cvFsGetNumFiles #1:file info error");
    }
    
    return val;
}

// 100% matching!
Sint32 cvFsGetNumTr(CVFS cvfs)
{
    Sint32 val;

    val = 0;
    
    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetNumTr #1:handle error");
        
        return val;
    }
    
    if (cvfs->vtbl->GetNumTr != NULL) 
    {
        val = cvfs->vtbl->GetNumTr(cvfs->obj); 
    }
    else 
    {
        cvFsError((const Sint8*)"cvFsGetNumTr #2:vtbl error");
    }
    
    return val;
}

// 100% matching!
Sint32 cvFsGetSctLen(CVFS cvfs)
{
    Sint32 val;

    val = 0;
    
    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetSctLen #1:handle error");
        
        return val;
    }
    
    if (cvfs->vtbl->GetSctLen != NULL) 
    {
        val = cvfs->vtbl->GetSctLen(cvfs->obj); 
    }
    else 
    {
        cvFsError((const Sint8*)"cvFsGetSctLen #2:vtbl error");
    }
    
    return val;
}

// 100% matching!
CVE_FS_ST cvFsGetStat(CVFS cvfs)
{
    CVE_FS_ST val;

    val = CVE_FS_ST_ERR;
    
    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsGetStat #1:handle error");
        
        return val;
    }
    
    if (cvfs->vtbl->GetStat != NULL) 
    {
        val = cvfs->vtbl->GetStat(cvfs->obj); 
    }
    else 
    {
        cvFsError((const Sint8*)"cvFsGetStat #2:vtbl error");
    }
    
    return val;
}

// 100% matching!
void cvFsInit(void) 
{
    CVFS cvfs;
    CVFS cvfs2; 
    Sint32 lp;

    if (cvfs_init_cnt == 0)
    {
        for (lp = 0; lp < 40; lp++) 
        {
            cvfs = &cvfs_obj[lp];
            cvfs2 = (CVFS)&cvfs_obj[lp].obj; 
    
            cvfs->vtbl = NULL;
            cvfs2->vtbl = NULL;
        } 
    
        for (lp = 0; lp < 32; lp++) 
        {
            cvfs_tbl[lp].dname[0] = '\0'; 
        } 
        
        memset(cvfs_defdev, 0, sizeof(cvfs_defdev));
        
        cvfs_defdev[0] = '\0';
    }

    cvfs_init_cnt++;
}

// 100% matching!
Sint32 cvFsIsExistFile(const Sint8 *fname)
{
    Sint32 ret;
	CVFS_IF cvfsif;
	Sint8 dev[297];
	Sint8 file[297];
    
    getDevName(dev, file, fname);

    ret = 0;
    
    if (file[0] == '\0') 
    {
        cvFsError((const Sint8*)"cvFsIsExistFile #1:illegal file name");
        
        return ret;
    }
    
    if (dev[0] == '\0') 
    {
        getDefDev(dev);
        
        if (dev[0] == '\0') 
        {
            cvFsError((const Sint8*)"cvFsIsExistFile #2:illegal device name");
            
            return ret;
        }
    }
    
    cvfsif = getDevice(dev); 
    
    if (cvfsif == NULL) 
    {
        cvFsError((const Sint8*)"cvFsIsExistFile #3:device not found");
        
        return ret;
    }
    
    if (cvfsif->IsExistFile == NULL) 
    {
        cvFsError((const Sint8*)"cvFsIsExistFile #4:vtbl error");
        
        return ret;
    }

    ret = cvfsif->IsExistFile(file);

    return ret; 
}

// 100% matching!
Sint32 cvFsLoadDirInfo(const Sint8 *name, void *inf, Sint32 num) 
{
    Sint32 ret;
	Sint8 dev[297];
	Sint8 file[297];
	CVFS_IF cvfsif;
    
    getDevName(dev, file, name);

    ret = 0;
    
    if (dev[0] == '\0') 
    {
        getDefDev(dev);
        
        if (dev[0] == '\0') 
        {
            cvFsError((const Sint8*)"cvFsIsExistFile #2:illegal device name");
            
            return ret;
        }
    }
    
    cvfsif = getDevice(dev); 
    
    if ((cvfsif != NULL) && (cvfsif->LoadDirInfo != NULL)) 
    {
        ret = cvfsif->LoadDirInfo(name, inf, num); 
    }

    return ret; 
}

// 100% matching!
Sint32 cvFsMakeDir(const Sint8 *dirname)
{
    Sint32 ret;
	CVFS_IF cvfsif;
	Sint8 dev[33];
	Sint8 dir[33];

    ret = -1;

    if (dirname == NULL) 
    {
        cvFsError((const Sint8*)"cvFsMakeDir #1:illegal directory name");
        
        return ret;
    }

    getDevName(dev, dir, dirname);
    
    if (dir[0] == '\0') 
    {
        cvFsError((const Sint8*)"cvFsMakeDir #1:illegal directory name");
        
        return ret;
    }
    
    if (dev[0] == '\0') 
    {
        getDefDev(dev);
        
        if (dev[0] == '\0') 
        {
            cvFsError((const Sint8*)"cvFsMakeDir #2:illegal device name");
            
            return ret;
        }
    }
    
    cvfsif = getDevice(dev); 
    
    if (cvfsif == NULL) 
    {
        cvFsError((const Sint8*)"cvFsMakeDir #3:device not found");
        
        return ret;
    }
    
    if (cvfsif->MakeDir == NULL) 
    {
        cvFsError((const Sint8*)"cvFsMakeDir #4:vtbl error");
        
        return ret;
    }

    ret = cvfsif->MakeDir(dir);

    return ret; 
}

// 100% matching!
CVFS cvFsOpen(const Sint8 *fname, void *prm, CVE_FS_OP op_mode)
{
    CVFS cvfs;
    CVFS_IF cvfsif;
	Sint8 dev[297];
	Sint8 file[297];

    if (fname == NULL) 
    {
        cvFsError((const Sint8*)"cvFsOpen #1:illegal file name");
        
        return NULL;
    }

    getDevName(dev, file, fname);
    
    if (file[0] == '\0') 
    {
        cvFsError((const Sint8*)"cvFsOpen #1:illegal file name");
        
        return NULL;
    }
    
    if (dev[0] == '\0') 
    {
        getDefDev(dev);
        
        if (dev[0] == '\0') 
        {
            cvFsError((const Sint8*)"cvFsOpen #2:illegal device name");
            
            return NULL;
        }
    }

    cvfs = allocCvFsHn(); 
    
    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsOpen #3:failed handle alloced");
        
        return NULL;
    }
    
    cvfsif = getDevice(dev); 

    cvfs->vtbl = cvfsif; 
    
    if (cvfsif == NULL) 
    {
        releaseCvFsHn(cvfs);
        
        cvFsError((const Sint8*)"cvFsOpen #4:device not found");
        
        return NULL;
    }
    
    if (cvfsif->Open != NULL) 
    {
        cvfs->obj = cvfsif->Open(file, prm, op_mode);
    }
    else 
    {
        cvFsError((const Sint8*)"cvFsOpen #5:vtbl error");
            
        return NULL;
    }
    
    if (cvfs->obj == NULL) 
    {
        releaseCvFsHn(cvfs);
        
        cvFsError((const Sint8*)"cvFsOpen #6:open failed");
        
        return NULL;
    }

    return cvfs;
}

// 100% matching!
Sint32 cvFsOptFn1(CVFS cvfs, Sint32 p0, Sint32 p1, Sint32 p2)
{
    Sint32 val;

    val = 0;
    
    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsOptFn1 #1:handle error");
        
        return val;
    }
    
    if (cvfs->vtbl->OptFn1 != NULL) 
    {
        val = cvfs->vtbl->OptFn1(cvfs->obj);
    } 
    else 
    {
        cvFsError((const Sint8*)"cvFsOptFn1 #2:vtbl error");
    }
    
    return val;
}

// 100% matching!
Sint32 cvFsOptFn2(CVFS cvfs, Sint32 p0, Sint32 p1, Sint32 p2)
{
    Sint32 val;

    val = 0;
    
    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsOptFn2 #1:handle error");
        
        return val;
    }
    
    if (cvfs->vtbl->OptFn2 != NULL) 
    {
        val = cvfs->vtbl->OptFn2(cvfs->obj);
    } 
    else 
    {
        cvFsError((const Sint8*)"cvFsOptFn2 #2:vtbl error");
    }
    
    return val;
}

// 100% matching!
Sint32 cvFsRemoveDir(const Sint8 *dirname)
{
    Sint32 ret;
	CVFS_IF cvfsif;
	Sint8 dev[297];
	Sint8 dir[297];

    ret = -1;

    if (dirname == NULL) 
    {
        cvFsError((const Sint8*)"cvFsRemoveDir #1:illegal directory name");
        
        return ret;
    }

    getDevName(dev, dir, dirname);
    
    if (dir[0] == '\0') 
    {
        cvFsError((const Sint8*)"cvFsRemoveDir #1:illegal directory name");
        
        return ret;
    }
    
    if (dev[0] == '\0') 
    {
        getDefDev(dev);
        
        if (dev[0] == '\0') 
        {
            cvFsError((const Sint8*)"cvFsRemoveDir #2:illegal device name");
            
            return ret;
        }
    }
    
    cvfsif = getDevice(dev); 
    
    if (cvfsif == NULL) 
    {
        cvFsError((const Sint8*)"cvFsRemoveDir #3:device not found");
        
        return ret;
    }
    
    if (cvfsif->RemoveDir == NULL) 
    {
        cvFsError((const Sint8*)"cvFsRemoveDir #4:vtbl error");
        
        return ret;
    }

    ret = cvfsif->RemoveDir(dir);

    return ret; 
}

// 100% matching!
Sint32 cvFsReqRd(CVFS cvfs, Sint32 nsct, void *buf)
{
    Sint32 val;

    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsReqRd #1:handle error");
        
        return 0;
    }
    
    if (cvfs->vtbl->ReqRd != NULL) 
    {
        val = cvfs->vtbl->ReqRd(cvfs->obj, nsct, buf);
    } 
    else 
    {
        val = 0;
        
        cvFsError((const Sint8*)"cvFsReqRd #2:vtbl error");
    }
    
    return val;
}

// 100% matching!
Sint32 cvFsReqWr(CVFS cvfs, Sint32 nsct, void *buf)
{
    Sint32 val;

    val = 0;

    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsReqWr #1:handle error");
        
        return val;
    }
    
    if (cvfs->vtbl->ReqWr != NULL) 
    {
        val = cvfs->vtbl->ReqWr(cvfs->obj, nsct, buf);
    } 
    else 
    {
        cvFsError((const Sint8*)"cvFsReqWr #2:vtbl error");
    }
    
    return val;
}

// 100% matching!
Sint32 cvFsSeek(CVFS cvfs, Sint32 nsct, CVE_FS_SK sk_mode)
{
    Sint32 val;

    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsSeek #1:handle error");
        
        return CVE_FS_SK_SET;
    }
    
    if (cvfs->vtbl->Seek != NULL) 
    {
        val = cvfs->vtbl->Seek(cvfs->obj, nsct, sk_mode);
    } 
    else 
    {
        val = CVE_FS_SK_SET;
        
        cvFsError((const Sint8*)"cvFsSeek #2:vtbl error");
    }
    
    return val;
}

// 100% matching!
void cvFsSetDefDev(Sint8 *devname)
{
    Uint32 len;

    if (devname == NULL) 
    {
        cvFsError((const Sint8*)"cvFsSetDefDev #1:illegal device name");
        return;
    }

    len = strlen((const char*)devname);

    if (len == 0) 
    {
        cvfs_defdev[0] = '\0';
        return;
    }
    
    toUpperStr(devname);

    if (isExistDev(devname, len) == 1)
    {
        memcpy(cvfs_defdev, devname, len + 1);
        return;
    }
    
    cvFsError((const Sint8*)"cvFsSetDefDev #2:unknown device name");
}

// 100% matching!
void cvFsSetSctLen(CVFS cvfs, Sint32 sctlen)
{
    if (cvfs == NULL)
    {
        cvFsError((const Sint8*)"cvFsSetSctLen #3:handle error");
    }
    else if (cvfs->vtbl->SetSctLen == NULL)
    {
        cvFsError((const Sint8*)"cvFsSetSctLen #4:vtbl error");
    }
    else 
    {
        cvfs->vtbl->SetSctLen(cvfs->obj);
    }
}

// 100% matching!
void cvFsStopTr(CVFS cvfs) 
{
    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsStopTr #1:handle error");
    }
    else if (cvfs->vtbl->StopTr == NULL) 
    {
        cvFsError((const Sint8*)"cvFsStopTr #2:vtbl error");
    }
    else 
    {
        cvfs->vtbl->StopTr(cvfs->obj);
    }
}

// 100% matching!
Sint32 cvFsTell(CVFS cvfs) 
{
    Sint32 val;

    if (cvfs == NULL) 
    {
        cvFsError((const Sint8*)"cvFsTell #1:handle error");
        
        return 0;
    }

    if (cvfs->vtbl->Tell != NULL) 
    {
        val = cvfs->vtbl->Tell(cvfs->obj);
    }
    else 
    {
        val = 0;
        
        cvFsError((const Sint8*)"cvFsTell #2:vtbl error");
    }

    return val;
}

// 100% matching!
static void getDefDev(Sint8 *dev)
{
    Sint32 len;

    len = strlen((const char*)cvfs_defdev);

    if (cvfs_defdev[0] == '\0') 
    {
        dev[0] = '\0';
    }
    else
    {
        memcpy(dev, cvfs_defdev, len + 1);
    }
}

// 100% matching!
static CVFS_IF getDevice(const Sint8 *devname) 
{
    Uint32 len;
	Uint32 lp;
    
    len = strlen((const char*)devname);

    for (lp = 0; lp < 32; lp++)
    {
        if (strncmp((char*)devname, (char*)&cvfs_tbl[lp].dname, len) == 0)
        {
            return cvfs_tbl[lp].vtbl;
        }
    }

    return NULL;
}

// 100% matching!
static void getDevName(Sint8 *dname, Sint8 *fname, const Sint8 *fn)
{
    Sint32 dlp;
    Sint32 flp;

    if (fn == NULL) 
    {
        return;
    }

    for (dlp = 0; (dlp < 297) && ((fn[dlp] != ':') && (fn[dlp] != '\0')); dlp++) 
    {
        dname[dlp] = fn[dlp];
    }
    
    if (fn[dlp] == '\0') 
    {
        dname[dlp] = '\0';
        
        memcpy(fname, dname, strlen((const char*)dname) + 1);
        
        dname[0] = '\0';
        return;
    }

    dname[dlp] = '\0';
    
    dlp++;

    for (flp = dlp; (flp < 297) && ((fn[flp] != ':') && (fn[flp] != '\0')); flp++) 
    {
        fname[flp - dlp] = fn[flp];
    }

    fname[flp - dlp] = '\0';
    
    toUpperStr(dname);
}

// 100% matching!
static Sint32 getNumFiles(const Sint8 *devname)
{
    CVFS_IF cvfsif;
    Sint32 val;
    Uint32 len;
    Sint32 lp;

    val = 0;
    
    len = strlen((const char*)devname);
    
    for (lp = 0; lp < 32; lp++)
    {
        if (strncmp((char*)devname, (char*)&cvfs_tbl[lp].dname, len) == 0)
        { 
            cvfsif = cvfs_tbl[lp].vtbl;
            
            if ((cvfsif != NULL) && (cvfsif->GetNumFiles != NULL)) 
            {
                val = cvfsif->GetNumFiles();
                break; 
            }
        }
    }
    
    return val;
}

// 100% matching!
static Sint32 getNumFilesAll(void)
{
    CVFS_IF cvfsif;
    Sint32 val;
    Sint32 lp;

    val = 0;
    
    for (lp = 0; lp < 32; lp++) 
    {
        cvfsif = cvfs_tbl[lp].vtbl;
        
        if ((cvfsif != NULL) && (cvfsif->GetNumFiles != NULL))
        {
            val += cvfsif->GetNumFiles();
        }
    }
    
    return val;
}

// 100% matching!
static Sint32 isExistDev(const Sint8 *devname, Sint32 len)
{
    Sint32 lp;

    for (lp = 0; lp < 32; lp++) 
    {
        if (strncmp((const char*)devname, (const char*)cvfs_tbl[lp].dname, len) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// 100% matching!
static void releaseCvFsHn(CVFS cvfs)
{
    cvfs->obj = NULL;
    
    cvfs->vtbl = NULL;
}

// 100% matching!
static void toUpperStr(Sint8 *src)
{
    Uint32 len;
    Uint32 lp;

    len = strlen((const char*)src);

    for (lp = 0; lp < (len + 1); lp++)
    {
        if ((src[lp] >= 'a') && (src[lp] <= 'z')) 
        {
            src[lp] -= 'a' - 'A';
        }
    }
}
