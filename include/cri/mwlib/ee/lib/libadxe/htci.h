#ifndef _HTCI_H_
#define _HTCI_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <libcdvd.h>
#include <sifdev.h>
#include "cri_cvfs.h"
#include "macros.h"

typedef struct
{
	Sint8 used;
	Sint8 cache;
	Sint8 stat;
	Sint8 rsv;
	Uint32 fsize;
    Sint32 end_fg;
	Sint32 fd;
    Sint32 fnsct;
	Sint32 skpos;
	Sint32 req_nsct;
    Sint8 *buf;
	Sint32 tr_nsct;
} HTS_CI_OBJ;
typedef HTS_CI_OBJ *HTCI;

HTCI htci_alloc(void);
void htci_call_errfn(HTCI htci, const char *msg);
void htci_conv_fname(const Char8 *spath, Char8 *tpath);
void htci_free(HTCI htci);
Sint32 htci_get_fsize_opened(Sint32 fd);
Sint32 htci_is_all_excute(void);
Sint32 htci_is_one_excute(HTCI htci);
void htci_wait(void);
Sint32 htci_wait_by_fd(int fd);
void htci_wait_io(void);
void htCiClose(void *obj);
void htCiEntryErrFunc(CVF_FS_ERRFN errfn, void *obj);
void htCiExecHndl(HTCI htci);
void htCiExecServer(void);
Sint32 htCiGetFileSize(const Sint8 *fname);
CVFS_IF htCiGetInterface(void);
Sint32 htCiGetNumTr(void *obj);
Sint32 htCiGetSctLen(void *obj);
CVE_FS_ST htCiGetStat(void *obj);
void* htCiOpen(Sint8 *fname, void *prm, CVE_FS_OP rw);
Sint32 htCiReqRd(void *obj, Sint32 nsct, void *buf);
Sint32 htCiSeek(void *obj, Sint32 nsct, CVE_FS_SK mode);
void htCiStopTr(void *obj);
Sint32 htCiTell(void *obj);

#endif
