#ifndef _PS2_SG_GD_H_
#define _PS2_SG_GD_H_

#include "types.h"
#include "ps2_dvd_image.h"

void  gdFsClose(GDFS gdfs);
GDFS_DIRREC  gdFsCreateDirhn(void *dirbuf, Sint32 max_dirent);
void  gdFsFinish(void);
Sint32  gdFsGetDirInfo(const char *name, GDFS_DIRINFO *dirinfo);
Sint32  gdFsGetDrvStat(void);
Bool  gdFsGetFileSize(GDFS gdfs, Sint32 *fsize);
Sint32  gdFsInit(Sint32 max_open, void *gdfs_work, Sint32 max_dirent, void *dirbuf);
GDFS  gdFsOpen(const char *fname, GDFS_DIRREC gf_dirrec);
Sint32  gdFsReqDrvStat(void);
Sint32  gdFsSetDir(GDFS_DIRREC gf_dirrec);
void  gdFsEntryErrFuncAll(GDFS_ERRFUNC erfunc, void *obj);
Sint32  gdFsLoadDir(const char *dirname, GDFS_DIRREC gf_dirrec);
Sint32  gdFsRead(GDFS gdfs, Sint32 nsct, void *buf);

#endif
