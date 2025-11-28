#ifndef _CRI_CVFS_H_
#define _CRI_CVFS_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>

typedef enum 
{
	CVE_FS_ST_IDLE = 0,
	CVE_FS_ST_COMPLETE = 1,
	CVE_FS_ST_TRANS = 2,
	CVE_FS_ST_ERR = 3,
	CVE_FS_ST_NUM = 4
} CVE_FS_ST;

typedef enum 
{
	CVE_FS_OP_READ = 0,
	CVE_FS_OP_WRITE = 1,
	CVE_FS_OP_NUM = 2
} CVE_FS_OP;

typedef enum 
{
	CVE_FS_SK_SET = 0,
	CVE_FS_SK_CUR = 1,
	CVE_FS_SK_END = 2,
	CVE_FS_SK_NUM = 3
} CVE_FS_SK;

typedef struct _cvfs_vtbl
{
    void    (*ExecServer)();
    void    (*EntryErrFunc)(void* func, void* obj);
    Sint32  (*GetFileSize)(const Char8* dirname);
    Sint32  (*GetFreeSize)();
    void*   (*Open)(const Sint8* dirname, void* arg1, CVE_FS_OP rw); 
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

typedef void (*CVF_FS_ERRFN)(void *err_obj, const Sint8 *msg, void *obj);

typedef struct _vfs_vtbl 
{
	void (*ExecServer)();
	void (*EntryErrFunc)();
	Sint32 (*GetFileSize)();
	Sint32 (*GetFreeSize)();
	void* (*Open)();
	void (*Close)();
	Sint32 (*Seek)();
	Sint32 (*Tell)();
	Sint32 (*ReqRd)();
	Sint32 (*ReqWr)();
	void (*StopTr)();
	CVE_FS_ST (*GetStat)();
	Sint32 (*GetSctLen)();
	void (*SetSctLen)();
	Sint32 (*GetNumTr)();
	Sint32 (*ChangeDir)();
	Sint32 (*IsExistFile)();
	Sint32 (*GetNumFiles)();
	Sint32 (*LoadDirInfo)();
	Sint32 (*GetMaxByteRate)();
	Sint32 (*MakeDir)();
	Sint32 (*RemoveDir)();
	Sint32 (*DeleteFile)();
	Sint32 (*GetFileSizeEx)();
	Sint32 (*OptFn1)();
	Sint32 (*OptFn2)();
} CVS_FS_IF;
typedef CVS_FS_IF *CVFS_IF;
typedef CVFS_IF (*CVF_FS_VTBLFN)();

typedef struct 
{ 
	CVFS_IF vtbl;
	Sint8 dname[9];
} CVF_FS_TBL;

typedef struct 
{ 
	CVFS_IF vtbl;
	void *obj;
} CVS_FS_OBJ;
typedef CVS_FS_OBJ *CVFS;

static CVFS_IF addDevice(Sint8 *devname, CVF_FS_VTBLFN func);
static void* allocCvFsHn();
void cvFsAddDev(Sint8 *devname, CVF_FS_VTBLFN vtblfn, void *init_prm);
void cvFsCallUsrErrFn(void *obj, const Sint8 *msg, void *hndl);
Sint32 cvFsChangeDir(const Sint8 *dirname);
void cvFsClose(CVFS cvfs);
void cvFsDelDev(Sint8 *devname);
Sint32 cvFsDeleteFile(const Sint8 *fname);
void cvFsEntryErrFunc(CVF_FS_ERRFN errfn, void *obj);
void cvFsError(const Sint8 *msg);
void cvFsExecServer(void);
void cvFsFinish(void);
Sint8* cvFsGetDefDev(void);
Sint8* cvFsGetDevName(CVFS cvfs);
Sint32 cvFsGetFileSize(const Sint8 *fname);
Sint32 cvFsGetFileSizeEx(const Sint8 *fname, void *prm);
Sint32 cvFsGetFreeSize(Sint8 *devname);
Sint32 cvFsGetMaxByteRate(CVFS cvfs);
Sint32 cvFsGetNumFiles(const Sint8 *devname);
Sint32 cvFsGetNumTr(CVFS cvfs);
Sint32 cvFsGetSctLen(CVFS cvfs);
CVE_FS_ST cvFsGetStat(CVFS cvfs);
void cvFsInit(void);
Sint32 cvFsIsExistFile(const Sint8 *fname);
Sint32 cvFsLoadDirInfo(const Sint8 *name, void *inf, Sint32 num);
Sint32 cvFsMakeDir(const Sint8 *dirname);
CVFS cvFsOpen(const Sint8 *fname, void *prm, CVE_FS_OP op_mode);
Sint32 cvFsOptFn1(CVFS cvfs, Sint32 p0, Sint32 p1, Sint32 p2);
Sint32 cvFsOptFn2(CVFS cvfs, Sint32 p0, Sint32 p1, Sint32 p2);
Sint32 cvFsRemoveDir(const Sint8 *dirname);
Sint32 cvFsReqRd(CVFS cvfs, Sint32 nsct, void *buf);
Sint32 cvFsReqWr(CVFS cvfs, Sint32 nsct, void *buf);
Sint32 cvFsSeek(CVFS cvfs, Sint32 nsct, CVE_FS_SK sk_mode);
void cvFsSetDefDev(Sint8 *devname);
void cvFsSetSctLen(CVFS cvfs, Sint32 sctlen);
void cvFsStopTr(CVFS cvfs);
Sint32 cvFsTell(CVFS cvfs);
static void getDefDev(Sint8 *dev);
static CVFS_IF getDevice(const Sint8 *devname);
void getDevName(Sint8 *dname, Sint8 *fname, const Sint8 *fn);
Sint32 getNumFiles(const Sint8 *devname);
Sint32 getNumFilesAll(void);
static void releaseCvFsHn(CVFS cvfs);
static void toUpperStr(Sint8 *src);

#endif
