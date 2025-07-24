void (*cvfs_errfn)(Sint32 arg0);
Sint32 cvfs_errobj;

// addDevice
// allocCvFsHn

void cvFsAddDev(void* arg0, void* arg1, Sint32 arg2)
{
    scePrintf("cvFsAddDev - UNIMPLEMENTED!\n");
}

// 100% matching!
void cvFsCallUsrErrFn(Sint32* errobj, Sint32 arg1, Sint32 arg2) 
{
    if (cvfs_errfn != NULL) 
    {
        cvfs_errfn(cvfs_errobj);
    }
}

// cvFsChangeDir
// cvFsClose
// cvFsDelDev
// cvFsDeleteFile

// 100% matching!
void cvFsEntryErrFunc(void* arg0, Sint32 arg1) 
{
    if (arg0 == 0)
    {
        cvfs_errfn = NULL;
        
        cvfs_errobj = 0;
    }
    else 
    {
        cvfs_errfn = arg0;
        
        cvfs_errobj = arg1;
    }
}

// 100% matching!
void cvFsError(Sint32 arg0) 
{
    cvFsCallUsrErrFn(&cvfs_errobj, arg0, 0);
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
// cvFsGetSctLen
// cvFsGetStat
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
