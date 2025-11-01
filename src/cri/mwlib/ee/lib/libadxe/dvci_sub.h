#ifndef _DVCI_SUB_H_
#define _DVCI_SUB_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <libcdvd.h>

typedef struct _dvg_flist_tbl 
{
    Char8*  fp;
    Sint32  fsize;
} DVG_FLIST_TBL;

typedef struct _dvci_dir_obj
{
    Sint32  fd;
    Sint32  fsize;
    Char8   fname[128]; 
    Uint8   pad[4];
} DVCI_DIR_OBJ;
typedef DVCI_DIR_OBJ *DVCI_DIR;

extern sceCdRMode dvg_ci_cdrmode;

Sint32 analysis_flist_dup(Char8* fpc, Sint8* rbuf, Uint32 size);
void conv_to_tpath_dup(Char8* fname, Char8* path);
void dvci_get_fstate(const Char8* fname, sceCdlFILE *fp);
void dvci_init_flist(void);
Sint32 dvCiLoadFpCache(Char8* fname, Char8* fpc, Uint32 size);
void dvCiSetRdMode(Sint32 nrtry, Sint32 speed, Sint32 dtype);
void get_fp_from_fname(sceCdlFILE* fp, const Char8* fname, DVCI_DIR dir, Sint32 size);
Sint32 load_flist_dup(Char8* flist, Sint8* rbuf);
Sint32 search_fstate(Char8* fpc, Sint32 fsize);

#endif
