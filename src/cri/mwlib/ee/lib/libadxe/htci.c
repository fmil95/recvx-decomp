#include "htci.h"
#include "htci_sub.h"

static Char8* volatile htci_build = "\nhtCi Ver.2.16 Build:Jan 26 2001 09:56:20\n";
static HTCI_OBJ htg_ci_obj[13] = { 0 };
static HTCI_ERRFN htg_ci_err_func = NULL;
static void* htg_ci_err_obj = NULL;
static Char8 htg_ci_fname[297] = { 0 };
static HTCI_VTBL htci_vtbl = { htCiExecServer, htCiEntryErrFunc, htCiGetFileSize, NULL, htCiOpen, htCiClose, htCiSeek, htCiTell, htCiReqRd, NULL, htCiStopTr, htCiGetStat, htCiGetSctLen, NULL, htCiGetNumTr, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

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
    memset(htci, 0, sizeof(HTCI_OBJ));
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
    if (sceIoctl(htci->fd, SCE_FS_EXECUTING, &htci->isend) < 0) 
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
        sceIoctl(fd, SCE_FS_EXECUTING, &isend);
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
            sceLseek(htci->fd, htci->tell * 2048, SCE_SEEK_SET);
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

// 100% matching!
Sint32 htCiGetFileSize(const Char8* fname)
{
    HTCI_DIR_OBJ dir;
    Sint32 fd;
    Sint32 fsize;

    if (fname == NULL) 
    {
        htci_call_errfn(NULL, "E0092704:fname is null.(htCiGetFileSize)");
        
        return 0;
    }
    
    htci_conv_fname(fname, htg_ci_fname);
    
    htci_get_finf(&htg_ci_fname[5], (sceCdlFILE*)&dir);
    
    if (dir.fsize == 0) 
    {
        htci_wait_io();
        
        fd = sceOpen(htg_ci_fname, SCE_RDONLY);
        
        if (fd < 0) 
        {
            htci_call_errfn(NULL, "E0092705:sceOpen fail.(htCiGetFileSize)");
            
            return 0;
        }
        
        htci_wait_by_fd(fd);
        
        fsize = sceLseek(fd, 0, SCE_SEEK_END);
        
        if (fsize < 0)
        {
            htci_call_errfn(NULL, "E0092706:sceLseek fail.(htCiGetFileSize)");
            
            sceClose(fd);
            
            return 0;
        }
        
        htci_wait_by_fd(fd);
        
        if (sceClose(fd) < 0)
        {
            htci_call_errfn(NULL, "E0092707:sceClose fail.(htCiGetFileSize)");
            
            return 0;
        }
    } 
    else
    {
        fsize = dir.fsize;
    }
    
    return fsize;
}

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

// 100% matching!
HTCI htCiOpen(Char8* fname, void* unused, Sint32 rw)
{
    HTCI htci;
    HTCI_DIR_OBJ dir = { 0 };

    if (fname == NULL) 
    {
        htci_call_errfn(fname, "E0092708:fname is null.(htCiOpen)");
        
        return NULL;
    }

    if (rw != 0)
    {
        htci_call_errfn(NULL, "E0092709:rw is illigal.(htCiOpen)");
        
        return NULL;
    }

    htci = htci_alloc();

    if (htci == NULL) 
    {
        htci_call_errfn(NULL, "E0092710:not enough handle resource.(htCiOpen)");
        
        return NULL;
    }

    htci_conv_fname(fname, htg_ci_fname);
    
    htci_get_finf(&htg_ci_fname[5], (sceCdlFILE*)&dir);
    
    if (dir.fsize == 0) 
    {
        htci->fsize = htCiGetFileSize(fname);

        if (htci->fsize == 0) 
        {
            htci_call_errfn(NULL, "E0111501:sceLseek fail.(htCiOpen)");
        }
    
        htci_wait_io();

        printf("opmode = %d\n", htg_ci_open_mode);
        
        htci->fd = sceOpen(htg_ci_fname, htg_ci_open_mode);

        if (htci->fd < 0) 
        {
            htci_call_errfn(NULL, "E0092711:sceOpen fail.(htCiOpen)");
            
            htci_free(htci);
            
            return NULL;
        }

        htci_wait_by_fd(htci->fd);
        
        htci->unk1 = 0;
    } 
    else 
    {
        htci->unk1 = 1;
        
        htci->fd = dir.fd;
        
        htci->fsize = dir.fsize;
    }
    
    htci->tell = 0;

    htci->used = TRUE;
    
    htci->buf = NULL;

    htci->nbyte = 0; 

    htci->ofs = ((Sint32)htci->fsize + 2047) / 2048;

    htci->unk3 = 0;

    htci->isend = FALSE;
    
    htci->stat = 0;

    return htci;
}

// 100% matching!
Sint32 htCiReqRd(HTCI htci, Sint32 nsct, Sint8* buf) 
{
    if (htci == NULL) 
    {
        htci_call_errfn(NULL, "E0092712:handl is null.");
        
        return 0;
    }

    if (nsct < 0) 
    {
        htci_call_errfn(htci, "E0092713:nsct < 0.(htCiReqRd)");
        
        return 0;
    }

    if (buf == NULL)
    {
        htci_call_errfn(htci, "E0092714:buf is null.(htCiReqRd)");
        
        return 0;
    }

    if ((htci->stat != 0) && (htci->stat != 1)) 
    {
        return 0;
    }

    if (nsct == 0) 
    {
        htci->stat = 1;
        
        return 0;
    }
    
    htci->stat = 2;
    
    htci->buf = buf;
    
    htci->unk3 = 0;
    
    htci->isend = FALSE;
    
    htci->nbyte = MIN(nsct, htci->ofs - htci->tell);
    
    return htci->nbyte;
}

// 100% matching!
Sint32 htCiSeek(HTCI htci, Sint32 ofst, Sint32 whence)
{
    if (htci == NULL) 
    {
        htci_call_errfn(htci, "E0092712:handl is null.");
        
        return 0;
    }

    if (whence == 0) 
    {
        htci->tell = ofst;
    } 
    else if (whence == 2) 
    {
        htci->tell = htci->ofs + ofst;
    } 
    else if (whence == 1)
    {
        htci->tell += ofst;
    }

    htci->tell = CLAMP(htci->tell, 0, htci->ofs);
    
    return htci->tell;
}

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
                sceIoctl(htci->fd, SCE_FS_EXECUTING, &htci->isend);
                
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
