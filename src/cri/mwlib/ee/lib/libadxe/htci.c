
typedef void (*HTCI_ERRFN)(void* htci_errobj, const Char8* msg, void* obj);

typedef struct _htci_obj 
{
    Sint8   used;
    Sint8   unk1;
    Sint8   stat;
    Sint8   unk3;
    Sint32  unk4;
    Sint32  isend;
    Sint32  fd;
    Sint32  unk10;
    Sint32  unk14;
    Sint32  tell;
    void*   buf;
    Sint32  nbyte;
} HTCI_OBJ;

typedef HTCI_OBJ *HTCI;

static Char8* volatile htci_build = "\nhtCi Ver.2.16 Build:Jan 26 2001 09:56:20\n";
static HTCI_OBJ htg_ci_obj[13];
static HTCI_ERRFN htg_ci_err_func;
static void* htg_ci_err_obj;
void* htci_vtbl;

void htci_wait_io(void);
void htCiStopTr(HTCI htci);

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

// 100% matching!
void htci_conv_fname(const Char8* fname, Char8* path)  
{
    Uint32 flen;
    Uint32 dirlen;
    Sint32 i;
    Sint32 j;

    memset(path, 0, 297);
    
    memcpy(path, "host:", sizeof("host:"));
    
    flen = strlen(fname);
    dirlen = strlen(path);
    
    for (i = 0, j = 0; i <= flen; i++) 
    { 
        if (((Uint8)fname[i] == '\\') || ((Uint8)fname[i] == '\0'))
        {
            memcpy(&path[dirlen], &fname[j], (Uint16)(i - j));
            
            dirlen += i - j;
            j += i - j;
            
            if (flen != j) 
            {
                path[dirlen] = '/';  
                
                dirlen++;
                j++;
            }
        }
    } 
}

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
    
    for (i = 0; i < 13; i++) 
    {
        if ((htg_ci_obj[i].used == TRUE) && (htci_is_one_excute(&htg_ci_obj[i]) == 0))
        {
            return 0; 
        }
    }
  
    return 1;
}

// 100% matching!
Sint32 htci_is_one_excute(HTCI htci)
{
    if (sceIoctl(htci->fd, 1, &htci->isend) < 0) 
    {
        return 0;
    }
    else 
    {
        return htci->isend != TRUE;
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
    Sint32 isend;

    isend = TRUE;
    
    while (isend == TRUE) 
    {
        sceIoctl(fd, 1, &isend);
    } 
    
    htci_wait_io();
    
    return 0;
}

// 100% matching!
void htci_wait_io(void) 
{
    while (htci_is_all_excute() == 0);
}

// 100% matching!
void htCiClose(HTCI htci)
{
    if (htci != NULL)
    {
        if ((unsigned char)htci->stat >= 2)
        {
            htCiStopTr(htci);
        }
        
        if (htci->unk1 == 0) 
        {
            htci_wait_io();
            
            if (sceClose(htci->fd) < 0)
            {
                printf("HTCI: Failed sceClose!\n");
            }
        }
        
        htci->used = FALSE;
        
        htci_free(htci);
    }
}

// 100% matching!
void htCiEntryErrFunc(HTCI_ERRFN func, void* obj) 
{
    htg_ci_err_func = func;
    htg_ci_err_obj = obj;
}

// 100% matching!
void htCiExecHndl(HTCI htci)
{
    Sint8 stat;

    stat = htci->stat;
    
    if ((stat == 2) && (htci_is_all_excute() != 0) && (htci->isend == FALSE))
    {
        if (htci->unk3 == 0) 
        {
            htci->unk3 = 1;
        }
        else if (htci->unk3 == 1) 
        {
            htci->unk3 = stat;
        }
        else if (htci->unk3 == stat) 
        {
            htci->stat = 1;
            
            htci->unk3 = 0;
            
            htci->tell += htci->nbyte;
        }

        if (htci->unk3 == 1)  
        {        
            sceLseek(htci->fd, htci->tell * 2048, 0);
        }
        else if (htci->unk3 == 2) 
        {
            sceRead(htci->fd, htci->buf, htci->nbyte * 2048);
        }
    }
}

// 100% matching!
void htCiExecServer(void) 
{
    HTCI htci;
    Sint32 i;

    for (i = 0; i < 13; i++) 
    {
        htci = &htg_ci_obj[i];

        if (htci->used == TRUE)
        {
            htCiExecHndl(htci);
        }
    }
}

// htCiGetFileSize

// 100% matching!
void* htCiGetInterface(void)
{
    return &htci_vtbl;
}

// 100% matching!
Sint32 htCiGetNumTr(HTCI htci) 
{
    if (htci == NULL) 
    {
        htci_call_errfn(NULL, "E0092712:handl is null.");
        
        return 0;
    }
    
    return htci->tell * 2048;
}

// 100% matching!
Sint32 htCiGetSctLen(void) 
{
    return 2048;
}

// 100% matching!
Sint8 htCiGetStat(HTCI htci) 
{
    if (htci == NULL)
    {
        htci_call_errfn(NULL, "E0092712:handl is null.");
        
        return 0;
    }
    
    return htci->stat;
}

// htCiOpen
// htCiReqRd
// htCiSeek

// 100% matching!
void htCiStopTr(HTCI htci)
{
    Sint32 i;

    if (htci == NULL) 
    {
        htci_call_errfn(NULL, "E0092712:handl is null.");
        return;
    }
    
    if (htci->stat != 0) 
    {
        if ((htci->stat == 2) && (htci->isend == TRUE)) 
        {
            for (i = 0; i < 20; i++) 
            {
                sceIoctl(htci->fd, 1, &htci->isend);
                
                if (htci->isend == FALSE) 
                {
                    break;
                }
                
                htci_wait();
            }
        }
        
        htci->stat = 0;
    }
}

// 100% matching!
Sint32 htCiTell(HTCI htci) 
{
    if (htci == NULL) 
    {
        htci_call_errfn(NULL, "E0092712:handl is null.");
        
        return 0;
    }
    
    return htci->tell;
}
