#ifndef _CRI_CVFS_H_
#define _CRI_CVFS_H_

typedef void (*CVFS_ERRFN)(void* cvfs_errobj, const Char8* msg, void* obj);

typedef struct _cvfs_vtbl
{
    void    (*ExecServer)();
    void    (*EntryErrFunc)(void* func, void* obj);
    Sint32  (*GetFileSize)(const Char8* dirname);
    Sint32  (*GetFreeSize)();
    void*   (*Open)(const Char8* dirname, Sint32 arg1, Sint32 rw); 
    void    (*Close)(void* dev);
    Sint32  (*Seek)(void* dev, Sint32 ofst, Sint32 whence);
    Sint32  (*Tell)(void* dev);
    Sint32  (*ReqRd)(void* dev, Sint32 nsct, Sint8* buf);
    Sint32  (*ReqRw)(void* dev, Sint32 nsct, Sint8* buf);
    void    (*StopTr)(void* dev);
    Sint8   (*GetStat)(void* dev);
    Sint32  (*GetSctLen)();
    void    (*SetSctLen)(void* dev);
    Sint32  (*GetNumTr)(void* dev);
    Sint32  (*ChangeDir)(const Char8* dirname);
    Sint32  (*IsExistFile)(const Char8* dirname);
    Sint32  (*GetNumFilesAll)();
    Sint32  (*LoadDirInfo)(const Char8* dirname, Sint32 arg1, Sint32 rw);
    Sint32  (*GetMaxByteRate)(void* dev);
    Sint32  (*MakeDir)(const Char8* dirname);
    Sint32  (*RemoveDir)(const Char8* dirname);
    Sint32  (*DeleteFile)(const Char8* dirname);
    Sint32  (*GetFileSizeEx)(const Char8* dirname, Sint32 arg1);
    Sint32  (*OptFn1)(void* dev);
    Sint32  (*OptFn2)(void* dev);
} CVFS_VTBL;

typedef struct _cvfs_obj 
{
    CVFS_VTBL* vtbl;
    void*      dev;
} CVFS_OBJ;

typedef CVFS_OBJ *CVFS;

typedef struct _cvfs_name_obj
{
    CVFS_OBJ*  dev;
    Char8      name[12];
} CVFS_NAME_OBJ;

typedef CVFS_NAME_OBJ *CVFS_NAME;

CVFS addDevice(Char8* devname, void* (*getdevif()));
CVFS allocCvFsHn(void);
void cvFsAddDev(Char8* devname, void* (*getdevif()), void* unused);
void cvFsCallUsrErrFn(void* errobj, const Char8* msg, void* obj);
Sint32 cvFsChangeDir(const Char8* dirname);
void cvFsClose(CVFS cvfs);
void cvFsDelDev(Char8* devname);
Sint32 cvFsDeleteFile(const Char8* dirname);
void cvFsEntryErrFunc(CVFS_ERRFN func, void* obj);
void cvFsError(const Char8* msg);
void cvFsExecServer(void);
void cvFsFinish(void);
Char8* cvFsGetDefDev(void);
CVFS_NAME cvFsGetDevName(CVFS cvfs);
Sint32 cvFsGetFileSize(const Sint8* dirname);
Sint32 cvFsGetFileSizeEx(const Char8* dirname, Sint32 arg1);
Sint32 cvFsGetFreeSize(Char8* fname);
Sint32 cvFsGetMaxByteRate(CVFS cvfs);
Sint32 cvFsGetNumFiles(const char* devname);
Sint32 cvFsGetNumTr(CVFS cvfs);
Sint32 cvFsGetSctLen(CVFS cvfs);
Sint8 cvFsGetStat(CVFS cvfs);
void cvFsInit(void);
Sint32 cvFsIsExistFile(const Char8* dirname);
Sint32 cvFsLoadDirInfo(const Char8* dirname, Sint32 arg1, Sint32 rw);
Sint32 cvFsMakeDir(const Char8* dirname);
CVFS cvFsOpen(const Char8* dirname, Sint32 arg1, Sint32 rw);
Sint32 cvFsOptFn1(CVFS cvfs);
Sint32 cvFsOptFn2(CVFS cvfs);
Sint32 cvFsRemoveDir(const Char8* dirname);
Sint32 cvFsReqRd(CVFS cvfs, Sint32 nsct, Sint8* buf);
Sint32 cvFsReqWr(CVFS cvfs, Sint32 nsct, Sint8* buf);
Sint32 cvFsSeek(CVFS cvfs, Sint32 ofst, Sint32 whence);
void cvFsSetDefDev(Char8* devname);
void cvFsSetSctLen(CVFS cvfs);
void cvFsStopTr(CVFS cvfs);
Sint32 cvFsTell(CVFS cvfs);
void getDefDev(Char8* devname);
CVFS getDevice(const Char8* devname);
void getDevName(Char8* devname, Char8* fname, const Char8* dirname);
Sint32 getNumFiles(const char* devname);
Sint32 getNumFilesAll(void);
Sint32 isExistDev(const Char8* devname, Sint32 nameln);
void releaseCvFsHn(CVFS cvfs);
void toUpperStr(Char8* str);

#endif
