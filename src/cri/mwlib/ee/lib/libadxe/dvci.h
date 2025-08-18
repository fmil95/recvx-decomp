#ifndef _DVCI_H_
#define _DVCI_H_

typedef void (*DVCI_ERRFN)(void* dvci_errobj, const Char8* msg, void* obj);

typedef struct _dvci_obj 
{
    Sint8       used;
    Sint8       unk1;
    Sint8       stat;
    Sint8       unk3;    /* unused */
    Sint32      unk4;    /* unused */
    Sint32      fsize;
    Sint32      ofs;
    Sint32      tell;
    Sint8*      buf;
    Sint32      rdsct;
    sceCdlFILE  fp;
    sceCdRMode  cdrmode;
} DVCI_OBJ;

typedef DVCI_OBJ *DVCI;

typedef struct _dvci_vtbl
{
    void    (*ExecServer)();
    void    (*EntryErrFunc)(DVCI_ERRFN func, void* obj);
    Sint32  (*GetFileSize)(const Char8* fname);
    void    (*unkC)();
    DVCI    (*Open)(Char8* fname, void* unused, Sint32 rw);
    void    (*Close)(DVCI dvci);
    Sint32  (*Seek)(DVCI dvci, Sint32 ofst, Sint32 whence);
    Sint32  (*Tell)(DVCI dvci);
    Sint32  (*ReqRd)(DVCI dvci, Sint32 nsct, Sint8* buf);
    void    (*unk24)();
    void    (*StopTr)(DVCI dvci);
    Sint8   (*GetStat)(DVCI dvci);
    Sint32  (*GetSctLen)();
    void    (*unk34)();
    Sint32  (*GetNumTr)(DVCI dvci);
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
} DVCI_VTBL;

DVCI dvci_alloc(void);
void dvci_call_errfn(void* obj, const Char8* msg);
void dvci_conv_fname(const Char8* fname, Char8* path);
void dvci_free(DVCI dvci);
void dvci_to_large_to_yen(Char8* path);
void dvci_wait(void);
void dvCiClose(DVCI dvci);
void dvCiEntryErrFunc(DVCI_ERRFN func, void* obj);
void dvCiExecHndl(DVCI dvci);
void dvCiExecServer(void);
Sint32 dvCiGetFileSize(const Char8* fname);
void* dvCiGetInterface(void);
Sint32 dvCiGetNumTr(DVCI dvci);
Sint32 dvCiGetSctLen(void);
Sint8 dvCiGetStat(DVCI dvci);
DVCI dvCiOpen(Char8* fname, void* unused, Sint32 rw);
Sint32 dvCiReqRd(DVCI dvci, Sint32 nsct, Sint8* buf);
Sint32 dvCiSeek(DVCI dvci, Sint32 ofst, Sint32 whence);
void dvCiStopTr(DVCI dvci);
Sint32 dvCiTell(DVCI dvci);

#endif
