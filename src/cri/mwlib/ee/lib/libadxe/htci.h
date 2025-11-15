#ifndef _HTCI_H_
#define _HTCI_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <libcdvd.h>
#include <sifdev.h>
#include "macros.h"

typedef struct _htci_dir_obj
{
    Sint32  fd;
    Sint32  fsize;
    Char8   fname[256]; 
    Uint8   pad[4];
} HTCI_DIR_OBJ;
typedef HTCI_DIR_OBJ *HTCI_DIR;

typedef void (*HTCI_ERRFN)(void* htci_errobj, const Char8* msg, void* obj);

typedef struct _htci_obj 
{
    Sint8   used;
    Sint8   unk1;
    Sint8   stat;
    Sint8   unk3;
    Sint32  unk4;  /* unused */
    Sint32  isend;
    Sint32  fd;
    Sint32  fsize;
    Sint32  ofs;
    Sint32  tell;
    void*   buf;
    Sint32  nbyte;
} HTCI_OBJ;
typedef HTCI_OBJ *HTCI;

typedef struct _htci_vtbl
{
    void    (*ExecServer)();
    void    (*EntryErrFunc)(HTCI_ERRFN func, void* obj);
    Sint32  (*GetFileSize)(const Char8* fname);
    void    (*unkC)();
    HTCI    (*Open)(Char8* fname, void* unused, Sint32 rw);
    void    (*Close)(HTCI htci);
    Sint32  (*Seek)(HTCI htci, Sint32 ofst, Sint32 whence);
    Sint32  (*Tell)(HTCI htci);
    Sint32  (*ReqRd)(HTCI htci, Sint32 nsct, Sint8* buf);
    void    (*unk24)();
    void    (*StopTr)(HTCI htci);
    Sint8   (*GetStat)(HTCI htci);
    Sint32  (*GetSctLen)();
    void    (*unk34)();
    Sint32  (*GetNumTr)(HTCI htci);
    void    (*unk3C)();
    void    (*unk40)();
    void    (*unk44)();
    void    (*unk48)();
    void    (*unk4C)();
    void    (*unk50)();
    void    (*unk54)();
    void    (*unk58)();
    void    (*unk5C)();
    void    (*unk60)();
    void    (*unk64)();
} HTCI_VTBL;

HTCI htci_alloc(void);
void htci_call_errfn(void* obj, const Char8* msg);
void htci_conv_fname(const Char8* fname, Char8* path);
void htci_free(HTCI htci);
Sint32 htci_get_fsize_opened(Sint32 fd);
Sint32 htci_is_all_excute(void);
Sint32 htci_is_one_excute(HTCI htci);
void htci_wait(void);
Sint32 htci_wait_by_fd(Sint32 fd);
void htci_wait_io(void);
void htCiClose(HTCI htci);
void htCiEntryErrFunc(HTCI_ERRFN func, void* obj);
void htCiExecHndl(HTCI htci);
void htCiExecServer(void);
Sint32 htCiGetFileSize(const Char8* fname);
void* htCiGetInterface(void);
Sint32 htCiGetNumTr(HTCI htci);
Sint32 htCiGetSctLen(void);
Sint8 htCiGetStat(HTCI htci);
HTCI htCiOpen(Char8* fname, void* unused, Sint32 rw);
Sint32 htCiReqRd(HTCI htci, Sint32 nsct, Sint8* buf);
Sint32 htCiSeek(HTCI htci, Sint32 ofst, Sint32 whence);
void htCiStopTr(HTCI htci);
Sint32 htCiTell(HTCI htci);

#endif
