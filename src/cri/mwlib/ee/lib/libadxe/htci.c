
typedef void (*HTCI_ERRFN)(void* htci_errobj, const Char8* msg, void* obj);

typedef struct _htci_obj 
{
    Sint8   used;
    Sint8   unk1;
    Sint8   unk2;
    Sint8   unk3;
    Sint32  unk4;
    Sint32  is_end;
    Sint32  fd;
    Sint32  unk10;
    Sint32  unk14;
    Sint32  unk18;
    Sint32  unk1C;
    Sint32  unk20;
} HTCI_OBJ;

typedef HTCI_OBJ *HTCI;

static Char8* volatile htci_build = "\nhtCi Ver.2.16 Build:Jan 26 2001 09:56:20\n";
static HTCI_OBJ htg_ci_obj[13];
static HTCI_ERRFN htg_ci_err_func;
static void* htg_ci_err_obj;
void* htci_vtbl;

void htci_wait_io(void);

// 100% matching!
HTCI htci_alloc(void) 
{
    HTCI htci;
    Sint32 i;
    
    htci = NULL;
    
    for (i = 0; i < 13; i++) 
    {
        if (htg_ci_obj[i].used == FALSE) 
        {
            htci = &htg_ci_obj[i];
        }
    }
  
    return htci;
}

// 100% matching!
void htci_call_errfn(void* obj, const Char8* msg)
{
    if (htg_ci_err_func != NULL) 
    { 
        htg_ci_err_func(htg_ci_err_obj, msg, obj);
    }
}

// htci_conv_fname

// 100% matching!
void htci_free(HTCI htci)
{
    *htci = (HTCI_OBJ){0};
}

// 100% matching!
Sint32 htci_get_fsize_opened(Sint32 fd) 
{
    Sint32 fsize;

    htci_wait_by_fd(fd);
    
    if (sceLseek(fd, 0, SCE_SEEK_SET) < 0)
    {
        return 0;
    }
    
    htci_wait_by_fd(fd);
        
    fsize = sceLseek(fd, 0, SCE_SEEK_END);
    
    return (fsize <= -1) ? 0 : fsize;
}

// 100% matching!
Sint32 htci_is_all_excute(void)
{
    Sint32 i;
    
    for (i = 0; i < ADXPS2_DEF_NUM_FILE_HOST; i++) 
    {
        if ((htg_ci_obj[i].used == 1) && (htci_is_one_excute(&htg_ci_obj[i]) == 0))
        {
            return 0; 
        }
    }
  
    return 1;
}

// 100% matching!
Sint32 htci_is_one_excute(HTCI htci)
{
    if (sceIoctl(htci->fd, 1, &htci->is_end) < 0) 
    {
        return 0;
    }
    else 
    {
        return htci->is_end != TRUE;
    }
}

// 100% matching!
void htci_wait(void) 
{
    Sint32 i;

    for (i = 0; i < 32768; i++);
}

// 100% matching!
Sint32 htci_wait_by_fd(Sint32 fd) 
{
    Sint32 is_end;

    is_end = TRUE;
    
    while (is_end == TRUE) 
    {
        sceIoctl(fd, 1, &is_end);
    } 
    
    htci_wait_io();
    
    return 0;
}

// 100% matching!
void htci_wait_io(void) 
{
    while (htci_is_all_excute() == 0);
}

// htCiClose
// htCiEntryErrFunc
// htCiExecHndl
// htCiExecServer
// htCiGetFileSize

// 100% matching!
void* htCiGetInterface(void)
{
    return &htci_vtbl;
}

// htCiGetNumTr
// htCiGetSctLen
// htCiGetStat
// htCiOpen
// htCiReqRd
// htCiSeek
// htCiStopTr
// htCiTell
