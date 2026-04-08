#ifndef _DVCI_H_
#define _DVCI_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <libcdvd.h>
#include "cri_cvfs.h"
#include "macros.h"

typedef struct 
{
	Sint8 used;
	Sint8 cache;
	Sint8 stat;
	Sint8 instat;
    Sint32 fnsct;
	Uint32 fsize;
	Sint32 skpos;
	Sint32 req_nsct;
    Sint8 *buf;
	Sint32 tr_nsct;
	sceCdlFILE fp;
	sceCdRMode mode;
} DVS_CI_OBJ;
typedef DVS_CI_OBJ *DVCI;

static DVCI dvci_alloc(void);
void dvci_call_errfn(DVCI dvci, const char *msg);
void dvci_conv_fname(const Sint8 *spath, Sint8 *tpath);
static void dvci_free(DVCI dvci);
void dvci_to_large_to_yen(Sint8 *fname);
void dvci_wait(void);
void dvCiClose(void *obj);
void dvCiEntryErrFunc(CVF_FS_ERRFN errfn, void *obj);
void dvCiExecHndl(DVCI dvci);
void dvCiExecServer(void);
Sint32 dvCiGetFileSize(const Sint8 *fname);
CVFS_IF dvCiGetInterface(void);
Sint32 dvCiGetNumTr(void *obj);
Sint32 dvCiGetSctLen(void *obj);
CVE_FS_ST dvCiGetStat(void *obj);
void* dvCiOpen(Sint8 *fname, void *prm, CVE_FS_OP rw);
Sint32 dvCiReqRd(void *obj, Sint32 nsct, void *buf);
Sint32 dvCiSeek(void *obj, Sint32 nsct, CVE_FS_SK mode);
void dvCiStopTr(void *obj);
Sint32 dvCiTell(void *obj);

#endif
