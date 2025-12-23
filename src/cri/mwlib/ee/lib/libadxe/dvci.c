#include "dvci.h"
#include "dvci_sub.h"

#include <eetypes.h>
#include <eekernel.h>
#include <stdio.h>
//#include <string.h> /* ERROR: causes linker to fail */

char* volatile dvg_ci_build = "\ndvCi Ver.2.14 Build:Mar 14 2001 14:12:35\n";
DVS_CI_OBJ dvg_ci_obj[40] = { 0 };
CVF_FS_ERRFN dvg_ci_err_func = NULL;
void *dvg_ci_err_obj = NULL;
Sint8 dvg_ci_fname[297] __attribute__((aligned(64))) = { 0 };
CVS_FS_IF dvg_ci_vtbl = { dvCiExecServer, dvCiEntryErrFunc, dvCiGetFileSize, NULL, dvCiOpen, dvCiClose, dvCiSeek, dvCiTell, dvCiReqRd, NULL, dvCiStopTr, dvCiGetStat, dvCiGetSctLen, NULL, dvCiGetNumTr, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

// 100% matching!
static DVCI dvci_alloc(void)
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
void dvci_call_errfn(DVCI dvci, const char *msg)
{
    if (dvg_ci_err_func != NULL) 
    {
        dvg_ci_err_func(dvg_ci_err_obj, (const Sint8*)msg, dvci);
    }
}

// 100% matching!
void dvci_conv_fname(const Sint8 *spath, Sint8 *tpath)
{
    memset(tpath, 0, 297);
    
    strcpy(tpath, spath);

    if (strcmp(spath + (strlen(spath) - 2), ";1") != 0) 
    {
        strcat(tpath, ";1");
    }

    dvci_to_large_to_yen(tpath);
}

// 100% matching!
static void dvci_free(DVCI dvci)
{
    memset(dvci, 0, sizeof(DVS_CI_OBJ));
}

// 100% matching!
void dvci_to_large_to_yen(Sint8 *fname)
{
    Uint32 len;
    Uint32 lp;

    len = strlen(fname);
    
    for (lp = 0; lp < len; lp++) 
    {
        if (fname[lp] == '/') 
        {
            fname[lp] = '\\';
        }
        
        if ((fname[lp] >= 'a') && (fname[lp] <= 'z')) 
        {
            fname[lp] -= ' ';
        }
    } 
}

// 100% matching!
void dvci_wait(void)
{
    Sint32 i;

    for (i = 0; i < 32768; i++);
}

// 100% matching!
void dvCiClose(void *obj)
{
    DVCI dvci;

    dvci = obj;
    
    if (dvci != NULL) 
    {
        if ((dvci->stat != 0) && (dvci->stat != 1)) 
        {
            dvCiStopTr(dvci);
        }
        
        dvci->used = FALSE;
        
        dvci_free(dvci);
    }
}

// 100% matching!
void dvCiEntryErrFunc(CVF_FS_ERRFN errfn, void *obj)
{
    dvg_ci_err_func = errfn;
    dvg_ci_err_obj = obj;
}

// 100% matching!
void dvCiExecHndl(DVCI dvci)
{
    Sint32 sync_stat;
    Sint32 errcode;

    if (dvci->stat == 2) 
    {
        sync_stat = sceCdSync(1);
        
        errcode = sceCdGetError();
        
        if (((errcode >= SCECdErREAD) && (errcode <= SCECdErEOM)) || ((errcode == SCECdErCUD) || (errcode == SCECdErCMD) || (errcode == SCECdErOPENS) || (errcode == SCECdErNODISC)))
        {
            dvci->stat = 3; 
            
            printf("Drive Error (0x%x)\n", errcode);
        }
        else if (sync_stat == 0) 
        {
            InvalidDCache(dvci->buf, (dvci->buf + (dvci->tr_nsct * 2048)) - 1);
            
            dvci->stat = 1;
            
            dvci->req_nsct += dvci->tr_nsct;
        }
    }
}

// 100% matching!
void dvCiExecServer(void) 
{
    DVCI dvci;
    Sint32 i;

    for (i = 0; i < 40; i++) 
    {
        dvci = &dvg_ci_obj[i];

        if (dvci->used == TRUE)
        {
            dvCiExecHndl(dvci);
        }
    }
}

// 100% matching!
Sint32 dvCiGetFileSize(const Sint8 *fname) 
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

        if (sceCdSearchFile(&fp, (char*)dvg_ci_fname) == 0) 
        {
            dvci_call_errfn(NULL, "E0092902:can't find file.(dvCiGetFileSize)");
            
            return 0;
        }
    }

    return fp.size;
}

// 100% matching!
CVFS_IF dvCiGetInterface()
{
    return &dvg_ci_vtbl;
}

// 100% matching!
Sint32 dvCiGetNumTr(void *obj)
{
    DVCI dvci;

    dvci = obj;
    
    if (dvci == NULL)
    {
        dvci_call_errfn(dvci, "E0092912:handl is null.");
        
        return 0;
    }

    return dvci->req_nsct * 2048;
}

// 100% matching!
Sint32 dvCiGetSctLen(void *obj)
{
    return 2048;
}

// 100% matching!
CVE_FS_ST dvCiGetStat(void *obj)
{
    DVCI dvci;

    dvci = obj;
    
    if (dvci == NULL) 
    {
        dvci_call_errfn(dvci, "E0092912:handl is null.");
        
        return CVE_FS_ST_IDLE;
    }

    return (CVE_FS_ST)dvci->stat;
}

// 100% matching!
void* dvCiOpen(Sint8 *fname, void *prm, CVE_FS_OP rw)
{
    DVCI dvci;

    if (fname == NULL) 
    {
        dvci_call_errfn((DVCI)fname, "E0092908:fname is null.(dvCiOpen)");
        
        return NULL;
    }

    if (rw != CVE_FS_OP_READ)
    {
        dvci_call_errfn(NULL, "E0092909:rw is illigal.(dvCis)");
        
        return NULL;
    }

    dvci = dvci_alloc();

    if (dvci == NULL) 
    {
        dvci_call_errfn(NULL, "E0092910:not enough handle resource.(dvCiOpen)");
        
        return NULL;
    }

    dvci_get_fstate(fname, &dvci->fp);

    if (dvci->fp.lsn == 0) 
    {
        dvci_conv_fname(fname, dvg_ci_fname);

        sceCdSync(0);

        if (sceCdSearchFile(&dvci->fp, (char*)dvg_ci_fname) == 0) 
        {
            dvci_call_errfn(NULL, "E0092911:sceCdSearchFile fail.(dvCiOpen)");
            
            dvci_free(dvci);
            
            return NULL;
        }

        dvci->cache = 0;
    } 
    else 
    {
        dvci->cache = 1;
    }

    dvci->fsize = dvci->fp.size;
    
    dvci->used = TRUE;
    
    dvci->req_nsct = 0;
    
    dvci->buf = NULL;
    
    dvci->skpos = ((Sint32)dvci->fp.size + 2047) / 2048;
    
    dvci->tr_nsct = 0;
    
    dvci->stat = 0;

    return dvci;
}

// 100% matching!
Sint32 dvCiReqRd(void *obj, Sint32 nsct, void *buf)
{
    DVCI dvci;
    Sint32 lsn;

    dvci = obj;

    if (dvci == NULL) 
    {
        dvci_call_errfn(NULL, "E0092912:handl is null.");
        
        return 0;
    }

    if (nsct < 0) 
    {
        dvci_call_errfn(dvci, "E0092913:nsct < 0.(dvCiReqRd)");
        
        return 0;
    }

    if (buf == NULL)
    {
        dvci_call_errfn(dvci, "E0092914:buf is null.(dvCiReqRd)");
        
        return 0;
    }

    if (dvci->stat == 2) 
    {
        return 0;
    }

    if (nsct == 0) 
    {
        dvci->stat = 1;
        
        return 0;
    }
    
    dvci->buf = buf;
    
    dvci->tr_nsct = MIN(nsct, dvci->skpos - dvci->req_nsct);
    
    dvci->mode.trycount = dvg_ci_cdrmode.trycount;
    
    dvci->mode.spindlctrl = dvg_ci_cdrmode.spindlctrl;
    
    dvci->mode.datapattern = dvg_ci_cdrmode.datapattern;
    
    if (sceCdSync(1) == 1)
    {
        return 0; 
    }
    
    dvCiExecServer();
    
    lsn = dvci->fp.lsn + dvci->req_nsct;
    
    InvalidDCache(dvci->buf, (dvci->buf + (dvci->tr_nsct * 2048)) - 1);
    
    if (sceCdRead(lsn, dvci->tr_nsct, dvci->buf, &dvci->mode) == 0) 
    {
        return 0;
    }
    else 
    { 
        dvci->stat = 2;
    }
    
    return dvci->tr_nsct;
}

// 100% matching!
Sint32 dvCiSeek(void *obj, Sint32 nsct, CVE_FS_SK mode)
{
    DVCI dvci;

    dvci = obj;

    if (dvci == NULL) 
    {
        dvci_call_errfn(dvci, "E0092912:handl is null.");
        
        return 0;
    }

    if (mode == CVE_FS_SK_SET) 
    {
        dvci->req_nsct = nsct;
    } 
    else if (mode == CVE_FS_SK_END) 
    {
        dvci->req_nsct = dvci->skpos + nsct;
    } 
    else if (mode == CVE_FS_SK_CUR)
    {
        dvci->req_nsct += nsct;
    }

    dvci->req_nsct = CLAMP(dvci->req_nsct, 0, dvci->skpos);
    
    return dvci->req_nsct;
}

// 100% matching!
void dvCiStopTr(void *obj)
{
    DVCI dvci;
	Sint32 cnt;

    dvci = obj;

    if (dvci == NULL) 
    {
        dvci_call_errfn(NULL, "E0092912:handl is null.");
        
        return;
    }
    
    if (dvci->stat != 0)
    {
        dvCiExecHndl(dvci);
        
        if (dvci->stat == 2) 
        {
            for (cnt = 0; cnt < 20; cnt++) 
            {
                if (sceCdBreak() == 1) 
                {
                    break;
                }
                
                dvci_wait();
            } 
            
            if (cnt >= 20) 
            {
                sceCdSync(0);
            }
        }
        
        InvalidDCache(dvci->buf, (dvci->buf + (dvci->tr_nsct * 2048)) - 1);
        
        dvci->stat = 0;
    }
}

// 100% matching!
Sint32 dvCiTell(void *obj)
{
    DVCI dvci;

    dvci = obj;
    
    if (dvci == NULL) 
    {
        dvci_call_errfn(dvci, "E0092912:handl is null.");
        
        return 0;
    }

    return dvci->req_nsct;
}
