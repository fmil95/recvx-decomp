#ifndef _DVCI_SUB_H_
#define _DVCI_SUB_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <libcdvd.h>

typedef struct 
{ 
	Uint32 lsn;
	Uint32 size;
    Char8   fname[128]; 
    Sint8   pad[4];
} DVS_CI_FCACHE;

typedef struct 
{ 
	DVS_CI_FCACHE *finf;
	Sint32 num;
	Sint32 num_max;
	Sint32 fname_max;
} DVCI_FLIST_TBL;

extern sceCdRMode dvg_ci_cdrmode;

static Sint32 analysis_flist_dup(void *inf, Sint8 *buf, Sint32 num);
void conv_to_tpath_dup(Sint8 *spath, Sint8 *tpath);
void dvci_get_fstate(const Sint8 *fname, sceCdlFILE *fp);
void dvci_init_flist(void);
Sint32 dvCiLoadFpCache(Sint8 *fls_fname, Sint8 *fpc_ptr, Sint32 fpc_size);
void dvCiSetRdMode(Sint32 nrtry, Sint32 speed, Sint32 dtype);
static void get_fp_from_fname(sceCdlFILE *fp, const Sint8 *fname, void *inf, Sint32 num);
static Sint32 load_flist_dup(Sint8 *fname, Sint8 *rbuf);
static Sint32 search_fstate(void *inf, Sint32 num);

#endif
