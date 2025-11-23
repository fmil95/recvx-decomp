#include "htci.h"
#include "htci_sub.h"

#include <stdio.h>
#include <string.h>

char* volatile htci_build = "\nhtCi Ver.2.16 Build:Jan 26 2001 09:56:20\n";
CVF_FS_ERRFN htg_ci_err_func = NULL;
void *htg_ci_err_obj = NULL;
CVS_FS_IF htci_vtbl = { htCiExecServer, htCiEntryErrFunc, htCiGetFileSize, NULL, htCiOpen, htCiClose, htCiSeek, htCiTell, htCiReqRd, NULL, htCiStopTr, htCiGetStat, htCiGetSctLen, NULL, htCiGetNumTr, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
HTS_CI_OBJ htg_ci_obj[13] = { 0 };
Uint8 htg_ci_fname[297] = { 0 };

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
void htci_call_errfn(HTCI htci, const char *msg)
{
    if (htg_ci_err_func != NULL) 
    { 
        htg_ci_err_func(htg_ci_err_obj, msg, htci);
    }
}

// 100% matching!
void htci_conv_fname(const Char8 *spath, Char8 *tpath)  
{
    Sint32 i;
    Sint32 j;
	Sint32 flen;
    Sint32 dirlen;

    memset(tpath, 0, 297);
    
    memcpy(tpath, "host:", 6);
    
    flen = strlen(spath);
    dirlen = strlen(tpath);
    
    for (i = 0, j = 0; (Uint32)i <= flen; i++) 
    { 
        if (((Uint8)spath[i] == '\\') || ((Uint8)spath[i] == '\0'))
        {
            memcpy(&tpath[dirlen], &spath[j], (Uint16)(i - j));
            
            dirlen += i - j;
            j += i - j;
            
            if (flen != j) 
            {
                tpath[dirlen] = '/';  
                
                dirlen++;
                j++;
            }
        }
    } 
}

// 100% matching!
void htci_free(HTCI htci)
{
    memset(htci, 0, sizeof(HTS_CI_OBJ));
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
    if (sceIoctl(htci->fd, SCE_FS_EXECUTING, &htci->end_fg) < 0) 
    {
        return 0;
    }
    else 
    {
        return htci->end_fg != TRUE;
    }
}

// 100% matching!
void htci_wait(void) 
{
    Sint32 i;

    for (i = 0; i < 32768; i++);
}

// 100% matching!
Sint32 htci_wait_by_fd(int fd)
{
    Sint32 end_fg;

    end_fg = TRUE;
    
    while (end_fg == TRUE) 
    {
        sceIoctl(fd, SCE_FS_EXECUTING, &end_fg);
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
void htCiClose(void *obj)
{
    HTCI htci;

    htci = obj;
    
    if (htci != NULL)
    {
        if ((htci->stat < 0) || (htci->stat >= 2))
        {
            htCiStopTr(htci);
        }
        
        if (htci->cache == 0) 
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
void htCiEntryErrFunc(CVF_FS_ERRFN errfn, void *obj)
{
    htg_ci_err_func = errfn;
    htg_ci_err_obj = obj;
}

// 100% matching!
void htCiExecHndl(HTCI htci)
{
    Sint32 sync_stat;

    sync_stat = htci->stat;
    
    if ((sync_stat == 2) && (htci_is_all_excute() != 0) && (htci->end_fg == FALSE))
    {
        if (htci->rsv == 0) 
        {
            htci->rsv = 1;
        }
        else if (htci->rsv == 1) 
        {
            htci->rsv = sync_stat;
        }
        else if (htci->rsv == sync_stat) 
        {
            htci->stat = 1;
            
            htci->rsv = 0;
            
            htci->req_nsct += htci->tr_nsct;
        }

        if (htci->rsv == 1)  
        {        
            sceLseek(htci->fd, htci->req_nsct * 2048, SCE_SEEK_SET);
        }
        else if (htci->rsv == 2) 
        {
            sceRead(htci->fd, htci->buf, htci->tr_nsct * 2048);
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
Sint32 htCiGetFileSize(const Sint8 *fname)
{
    Sint32 fsize;
	Sint32 fd;
	HTS_CI_FCACHE finf;

    if (fname == NULL) 
    {
        htci_call_errfn(NULL, "E0092704:fname is null.(htCiGetFileSize)");
        
        return 0;
    }
    
    htci_conv_fname((Char8*)fname, (Char8*)htg_ci_fname);
    
    htci_get_finf(&htg_ci_fname[5], &finf);
    
    if (finf.size == 0) 
    {
        htci_wait_io();
        
        fd = sceOpen((char*)htg_ci_fname, SCE_RDONLY);
        
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
        fsize = finf.size;
    }
    
    return fsize;
}

// 100% matching!
CVFS_IF htCiGetInterface(void)
{
    return &htci_vtbl;
}

// 100% matching!
Sint32 htCiGetNumTr(void *obj)
{
    HTCI htci;

    htci = obj;

    if (htci == NULL) 
    {
        htci_call_errfn(NULL, "E0092712:handl is null.");
        
        return 0;
    }
    
    return htci->req_nsct * 2048;
}

// 100% matching!
Sint32 htCiGetSctLen(void *obj)
{
    return 2048;
}

// 100% matching!
CVE_FS_ST htCiGetStat(void *obj)
{
    HTCI htci;

    htci = obj;
    
    if (htci == NULL)
    {
        htci_call_errfn(NULL, "E0092712:handl is null.");
        
        return CVE_FS_ST_IDLE;
    }
    
    return (CVE_FS_ST)htci->stat;
}

// 100% matching!
void* htCiOpen(Sint8 *fname, void *prm, CVE_FS_OP rw)
{
    HTCI htci;
    HTS_CI_FCACHE finf = { 0 };

    if (fname == NULL) 
    {
        htci_call_errfn((HTCI)fname, "E0092708:fname is null.(htCiOpen)");
        
        return NULL; 
    }

    if (rw != CVE_FS_OP_READ)
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

    htci_conv_fname((Char8*)fname, (Char8*)htg_ci_fname);
    
    htci_get_finf(&htg_ci_fname[5], &finf);
    
    if (finf.size == 0) 
    {
        htci->fnsct = htCiGetFileSize(fname);

        if (htci->fnsct == 0) 
        {
            htci_call_errfn(NULL, "E0111501:sceLseek fail.(htCiOpen)");
        }
    
        htci_wait_io();

        printf("opmode = %d\n", htg_ci_open_mode);
        
        htci->fd = sceOpen((char*)htg_ci_fname, htg_ci_open_mode);

        if (htci->fd < 0) 
        {
            htci_call_errfn(NULL, "E0092711:sceOpen fail.(htCiOpen)");
            
            htci_free(htci);
            
            return NULL;
        }

        htci_wait_by_fd(htci->fd);
        
        htci->cache = 0;
    } 
    else 
    {
        htci->cache = 1;
        
        htci->fd = finf.fd;
        
        htci->fnsct = finf.size;
    }
    
    htci->req_nsct = 0;

    htci->used = TRUE;
    
    htci->buf = NULL;

    htci->tr_nsct = 0; 

    htci->skpos = ((Sint32)htci->fnsct + 2047) / 2048;

    htci->rsv = 0;

    htci->end_fg = FALSE;
    
    htci->stat = 0;

    return htci;
}

// 100% matching!
Sint32 htCiReqRd(void *obj, Sint32 nsct, void *buf)
{
    HTCI htci;

    htci = obj;
    
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
    
    htci->rsv = 0;
    
    htci->end_fg = FALSE;
    
    htci->tr_nsct = MIN(nsct, htci->skpos - htci->req_nsct);
    
    return htci->tr_nsct;
}

// 100% matching!
Sint32 htCiSeek(void *obj, Sint32 nsct, CVE_FS_SK mode)
{
    HTCI htci;

    htci = obj;
    
    if (htci == NULL) 
    {
        htci_call_errfn(htci, "E0092712:handl is null.");
        
        return 0;
    }

    if (mode == CVE_FS_ST_IDLE) 
    {
        htci->req_nsct = nsct;
    } 
    else if (mode == CVE_FS_ST_TRANS) 
    {
        htci->req_nsct = htci->skpos + nsct;
    } 
    else if (mode == CVE_FS_ST_COMPLETE)
    {
        htci->req_nsct += nsct;
    }

    htci->req_nsct = CLAMP(htci->req_nsct, 0, htci->skpos);
    
    return htci->req_nsct;
}

// 100% matching!
void htCiStopTr(void *obj)
{
    HTCI htci;
	Sint32 cnt;

    htci = obj;

    if (htci == NULL) 
    {
        htci_call_errfn(NULL, "E0092712:handl is null.");
        return;
    }
    
    if (htci->stat != 0) 
    {
        if ((htci->stat == 2) && (htci->end_fg == TRUE)) 
        {
            for (cnt = 0; cnt < 20; cnt++) 
            {
                sceIoctl(htci->fd, SCE_FS_EXECUTING, &htci->end_fg);
                
                if (htci->end_fg == FALSE) 
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
Sint32 htCiTell(void *obj)
{
    HTCI htci;
    
    htci = obj;
    
    if (htci == NULL) 
    {
        htci_call_errfn(NULL, "E0092712:handl is null.");
        
        return 0;
    }
    
    return htci->req_nsct;
}
