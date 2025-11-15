#ifndef _HTCI_SUB_H_
#define _HTCI_SUB_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <libcdvd.h>
#include <sifdev.h>

typedef struct
{ 
	Sint32 fd;
	Sint32 size;
    Char8 fname[256]; 
    Sint8 pad[4];
} HTS_CI_FCACHE;

typedef struct 
{ 
	HTS_CI_FCACHE *finf;
	Sint32 num;
	Sint32 num_max;
	Sint32 fname_max;
} HTCI_FLIST_TBL;

extern Sint32 htg_ci_open_mode;

static Sint32 analysis_flist(void *inf, Sint8 *buf, Sint32 num);
static Sint32 close_file_all(void);
void conv_to_tpath(Char8 *spath, Char8 *tpath);
static void get_fstate(HTS_CI_FCACHE *finf, Uint8 *fname, HTS_CI_FCACHE *inf, Sint32 num);
void htci_get_finf(Uint8 *fname, HTS_CI_FCACHE *inf);
void htci_init_flist(void);
Sint32 htCiLoadFpCache(Sint8 *fls_fname, Sint8 *fpc_ptr, Sint32 fpc_size);
void htCiSetOpenMode(Sint32 mode);
Sint32 load_flist(Sint8 *fname, Sint8 *rbuf);
static Sint32 open_file_all(void *inf, Sint32 num);

#endif
