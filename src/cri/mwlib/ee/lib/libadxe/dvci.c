
typedef void (*DVCI_ERRFN)(void* dvci_errobj, const Char8* msg, void* obj);

typedef struct _dvci_obj 
{
    Sint8   used;
    Sint8   unk1;
    Sint8   stat;
    Sint8   unk3;
    Sint32  unk4;
    Sint32  unk8;
    Sint32  unkC;
    Sint32  numtr;
    Sint32  unk14;
    Sint32  unk18;
    Sint32  unk1C;
    Sint32  unk20;
    Sint32  unk24;
    Sint32  unk28;
    Sint32  unk2C;
    Sint32  unk30;
    Sint32  unk34;
    Sint32  unk38;
    Sint32  unk3C;
} DVCI_OBJ;

typedef DVCI_OBJ *DVCI;

static DVCI_OBJ dvg_ci_obj[40];
static DVCI_ERRFN dvg_ci_err_func;
static void* dvg_ci_err_obj;
static Char8 dvg_ci_fname[297];
void* dvg_ci_vtbl;

// 100% matching!
DVCI dvci_alloc(void) 
{
    DVCI dvci;
    Sint32 i;
    
    dvci = NULL;
    
    for (i = 0; i < 40; i++) 
    {
        if (dvg_ci_obj[i].used == FALSE) 
        {
            dvci = &dvg_ci_obj[i];
        }
    }
  
    return dvci;
}

// 100% matching!
void dvci_call_errfn(void* obj, const Char8* msg)
{
    if (dvg_ci_err_func != NULL) 
    {
        dvg_ci_err_func(dvg_ci_err_obj, msg, obj);
    }
}

void dvci_conv_fname(const Char8* fname, Char8* path)
{
    scePrintf("dvci_conv_fname - UNIMPLEMENTED!\n");
}

// 100% matching!
void dvci_free(DVCI dvci)
{
    memset(dvci, 0, sizeof(DVCI_OBJ));
}

// 100% matching!
void dvci_to_large_to_yen(Char8* fname) 
{
    Uint32 i;
    Uint32 l;

    l = strlen(fname);
    
    for (i = 0; i < l; i++) 
    {
        if (fname[i] == '/') 
        {
            fname[i] = '\\';
        }
        
        if ((Uint8)(fname[i] - 'a') < 26) // probably a compiler optimization
        {
            fname[i] -= ' ';
        }
    } 
}

// 100% matching!
void dvci_wait(void)
{
    Sint32 i;

    for (i = 0; i < 32768; i++);
}

// dvCiClose
// dvCiEntryErrFunc
// dvCiExecHndl
// dvCiExecServer

void dvci_get_fstate(const Char8* fname, sceCdlFILE* fp); // this declaration needs removing
// 100% matching!
Sint32 dvCiGetFileSize(const Char8* fname) 
{
    sceCdlFILE fp;

    if (fname == NULL) 
    {
        dvci_call_errfn(NULL, "E0092901:fname is null.(dvCiGetFileSize)");
        
        return 0;
    }

    dvci_get_fstate(fname, &fp);

    if (fp.lsn == 0) 
    {
        sceCdSync(0);
        
        dvci_conv_fname(fname, dvg_ci_fname);

        if (sceCdSearchFile(&fp, dvg_ci_fname) == 0) 
        {
            dvci_call_errfn(NULL, "E0092902:can't find file.(dvCiGetFileSize)");
            
            return 0;
        }
    }

    return fp.size;
}

// 100% matching!
void* dvCiGetInterface(void) 
{
    return &dvg_ci_vtbl;
}

// 100% matching!
Sint32 dvCiGetNumTr(DVCI dvci)
{
    if (dvci == NULL)
    {
        dvci_call_errfn(dvci, "E0092912:handl is null.");
        
        return 0;
    }

    return dvci->numtr * 2048;
}

// 100% matching!
Sint32 dvCiGetSctLen(void)
{
    return 2048;
}

// 100% matching!
Sint8 dvCiGetStat(DVCI dvci)
{
    if (dvci == NULL) 
    {
        dvci_call_errfn(dvci, "E0092912:handl is null.");
        
        return 0;
    }

    return dvci->stat;
}

// dvCiOpen
// dvCiReqRd
// dvCiSeek
// dvCiStopTr
// dvCiTell
// dvg_ci_build
