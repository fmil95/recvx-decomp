#define HTCI_OBJ_MAX 13

typedef struct _htg_ci 
{
    Sint8 used;
    Sint8 unk1;
    Sint8 unk2;
    Sint8 unk3;
    Sint32 unk4;
    Sint32 unk8;
    Sint32 unkC;
    Sint32 unk10;
    Sint32 unk14;
    Sint32 unk18;
    Sint32 unk1C;
    Sint32 unk20;
} HTG_CI;
typedef HTG_CI  *HTCI;

typedef HTG_CI HTCI_OBJ;

HTCI_OBJ htg_ci_obj[HTCI_OBJ_MAX];
Char8* htci_build = "\nhtCi Ver.2.16 Build:Jan 26 2001 09:56:20\n";
void (*htg_ci_err_func)(void* err_obj, Char8* err_msg, Sint32 arg2);
void* htg_ci_err_obj;
void* htci_vtbl;

void htci_wait_io(void);

// 100% matching!
HTCI_OBJ* htci_alloc(void) 
{
    HTCI_OBJ* htci_obj;
    Sint32 i;
    
    htci_obj = NULL;
    
    for (i = 0; i < HTCI_OBJ_MAX; i++) 
    {
        if (htg_ci_obj[i].used == 0) 
        {
            htci_obj = &htg_ci_obj[i];
        }
    }
  
    return htci_obj;
}

// 100% matching!
void htci_call_errfn(Sint32 arg0, Char8* htg_ci_err_msg)
{
    if (htg_ci_err_func != NULL) 
    { 
        htg_ci_err_func(htg_ci_err_obj, htg_ci_err_msg, arg0);
    }
}

// htci_conv_fname
// htci_free
// htci_get_fsize_opened

Sint32 htci_is_all_excute(void)
{
    scePrintf("htci_is_all_excute - UNIMPLEMENTED!\n");
}

// htci_is_one_excute

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
