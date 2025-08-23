#ifndef _HTCI_SUB_H_
#define _HTCI_SUB_H_

typedef struct _htg_flist_tbl 
{
    Char8*  fp;
    Sint32  fsize;
} HTG_FLIST_TBL;

typedef struct _htci_dir_obj
{
    Sint32  fd;
    Sint32  fsize;
    Char8   fname[256]; 
    Uint8   pad[4];
} HTCI_DIR_OBJ;

typedef HTCI_DIR_OBJ *HTCI_DIR;

Sint32 analysis_flist(Char8* fpc, Sint8* rbuf, Uint32 size);
Sint32 close_file_all(void);
void conv_to_tpath(Char8* fname, Char8* path);
void get_fstate(sceCdlFILE* fp, const Char8* fname, HTCI_DIR dir, Sint32 size);
void htci_get_finf(const Char8* fname, sceCdlFILE* fp);
void htci_init_flist(void);
Sint32 htCiLoadFpCache(Char8* fname, Char8* fpc, Uint32 size);
void htCiSetOpenMode(Sint32 opmode);
Sint32 load_flist(Char8* flist, Sint8* rbuf);
Sint32 open_file_all(Char8* fpc, Sint32 fno);

#endif
