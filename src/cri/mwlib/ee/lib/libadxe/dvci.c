typedef struct _dvd_ci 
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
    Sint32 unk24;
    Sint32 unk28;
    Sint32 unk2C;
    Sint32 unk30;
    Sint32 unk34;
    Sint32 unk38;
    Sint32 unk3C;
} DVD_CI;
typedef DVD_CI  *DVCI;

typedef DVD_CI DVCI_OBJ;

DVCI_OBJ dvg_ci_obj[ADXPS2_DEF_NUM_FILE_DVD];
void (*dvg_ci_err_func)(void* err_obj, Char8* err_msg, Sint32 arg2);
void* dvg_ci_err_obj;

// 100% matching!
DVCI dvci_alloc(void) 
{
    DVCI dvci;
    Sint32 i;
    
    dvci = NULL;
    
    for (i = 0; i < ADXPS2_DEF_NUM_FILE_DVD; i++) 
    {
        if (dvg_ci_obj[i].used == 0) 
        {
            dvci = &dvg_ci_obj[i];
        }
    }
  
    return dvci;
}

// 100% matching!
void dvci_call_errfn(Sint32 arg0, Char8* err_msg)
{
    if (dvg_ci_err_func != NULL) 
    {
        dvg_ci_err_func(dvg_ci_err_obj, err_msg, arg0);
    }
}

// dvci_conv_fname

// 100% matching!
void dvci_free(DVCI dvci)
{
    *dvci = (DVD_CI){0};
}

// 100% matching!
void dvci_to_large_to_yen(Char8* flist) 
{
    Uint32 i;
    Uint32 l;

    l = strlen(flist);
    
    for (i = 0; i < l; i++) 
    {
        if (flist[i] == '/') 
        {
            flist[i] = '\\';
        }
        
        if ((Uint8)(flist[i] - 'a') < 26) 
        {
            flist[i] -= ' ';
        }
    } 
}

// dvci_wait
// dvCiClose
// dvCiEntryErrFunc
// dvCiExecHndl
// dvCiExecServer
// dvCiGetFileSize

void dvCiGetInterface(void)
{
    scePrintf("dvCiGetInterface - UNIMPLEMENTED!\n");
}

// dvCiGetNumTr
// dvCiGetSctLen
// dvCiGetStat
// dvCiOpen
// dvCiReqRd
// dvCiSeek
// dvCiStopTr
// dvCiTell
// dvg_ci_build
