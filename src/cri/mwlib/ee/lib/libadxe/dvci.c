#include "dvci.h"
#include "dvci_sub.h"

#include <PREFIX_PS2_DEBUG.h>
#include <eetypes.h>
#include <eekernel.h>
#include <stdio.h>
//#include <string.h> /* ERROR: causes linker to fail */

static Char8* volatile dvg_ci_build = "\ndvCi Ver.2.14 Build:Mar 14 2001 14:12:35\n";
static DVCI_OBJ dvg_ci_obj[40] = { 0 };
static DVCI_ERRFN dvg_ci_err_func = NULL;
static void* dvg_ci_err_obj = NULL;
static Char8 dvg_ci_fname[297] = { 0 };
static DVCI_VTBL dvg_ci_vtbl = { dvCiExecServer, dvCiEntryErrFunc, dvCiGetFileSize, NULL, dvCiOpen, dvCiClose, dvCiSeek, dvCiTell, dvCiReqRd, NULL, dvCiStopTr, dvCiGetStat, dvCiGetSctLen, NULL, dvCiGetNumTr, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

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

// 100% matching!
void dvci_conv_fname(const Char8* fname, Char8* path) 
{
    memset(path, 0, 297);
    
    strcpy(path, fname);

    if (strcmp(fname + (strlen(fname) - 2), ";1") != 0) 
    {
        strcat(path, ";1");
    }

    dvci_to_large_to_yen(path);
}

// 100% matching!
void dvci_free(DVCI dvci)
{
    memset(dvci, 0, sizeof(DVCI_OBJ));
}

// 100% matching!
void dvci_to_large_to_yen(Char8* path) 
{
    Sint32 i;
    Uint32 l;

    l = strlen(path);
    
    for (i = 0; i < l; i++) 
    {
        if (path[i] == '/') 
        {
            path[i] = '\\';
        }
        
        if ((Uint8)(path[i] - 'a') < 26) // probably a compiler optimization
        {
            path[i] -= ' ';
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
void dvCiClose(DVCI dvci) 
{
    if (dvci != NULL) 
    {
        if ((unsigned char)dvci->stat >= 2) 
        {
            dvCiStopTr(dvci);
        }
        
        dvci->used = FALSE;
        
        dvci_free(dvci);
    }
}

// 100% matching!
void dvCiEntryErrFunc(DVCI_ERRFN func, void* obj) 
{
    dvg_ci_err_func = func;
    dvg_ci_err_obj = obj;
}

// 100% matching!
void dvCiExecHndl(DVCI dvci)
{
    Sint32 rsflg;
    Sint32 errcode;

    if (dvci->stat == 2) 
    {
        rsflg = sceCdSync(1);
        
        errcode = sceCdGetError();
        
        if (((errcode >= SCECdErREAD) && (errcode <= SCECdErEOM)) || ((errcode == SCECdErCUD) || (errcode == SCECdErCMD) || (errcode == SCECdErOPENS) || (errcode == SCECdErNODISC)))
        {
            dvci->stat = 3; 
            
            printf("Drive Error (0x%x)\n", errcode);
        }
        else if (rsflg == 0) 
        {
            InvalidDCache(dvci->buf, (dvci->buf + (dvci->rdsct * 2048)) - 1);
            
            dvci->stat = 1;
            
            dvci->tell += dvci->rdsct;
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

    return dvci->tell * 2048;
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

// 100% matching!
DVCI dvCiOpen(Char8* fname, void* unused, Sint32 rw)
{
    DVCI dvci;

    if (fname == NULL) 
    {
        dvci_call_errfn(fname, "E0092908:fname is null.(dvCiOpen)");
        
        return NULL;
    }

    if (rw != 0)
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

        if (sceCdSearchFile(&dvci->fp, dvg_ci_fname) == 0) 
        {
            dvci_call_errfn(NULL, "E0092911:sceCdSearchFile fail.(dvCiOpen)");
            
            dvci_free(dvci);
            
            return NULL;
        }

        dvci->unk1 = 0;
    } 
    else 
    {
        dvci->unk1 = 1;
    }

    dvci->fsize = dvci->fp.size;
    
    dvci->used = TRUE;
    
    dvci->tell = 0;
    
    dvci->buf = NULL;
    
    dvci->ofs = ((Sint32)dvci->fp.size + 2047) / 2048;
    
    dvci->rdsct = 0;
    
    dvci->stat = 0;

    return dvci;
}

// 100% matching!
Sint32 dvCiReqRd(DVCI dvci, Sint32 nsct, Sint8* buf) 
{
    Sint32 lsn;

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
    
    dvci->rdsct = MIN(nsct, dvci->ofs - dvci->tell);
    
    dvci->cdrmode.trycount = dvg_ci_cdrmode.trycount;
    
    dvci->cdrmode.spindlctrl = dvg_ci_cdrmode.spindlctrl;
    
    dvci->cdrmode.datapattern = dvg_ci_cdrmode.datapattern;
    
    if (sceCdSync(1) == 1)
    {
        return 0; 
    }
    
    dvCiExecServer();
    
    lsn = dvci->fp.lsn + dvci->tell;
    
    InvalidDCache(dvci->buf, (dvci->buf + (dvci->rdsct * 2048)) - 1);
    
    if (sceCdRead(lsn, dvci->rdsct, dvci->buf, &dvci->cdrmode) == 0) 
    {
        return 0;
    }
    else 
    { 
        dvci->stat = 2;
    }
    
    return dvci->rdsct;
}

// 100% matching!
Sint32 dvCiSeek(DVCI dvci, Sint32 ofst, Sint32 whence)
{
    if (dvci == NULL) 
    {
        dvci_call_errfn(dvci, "E0092912:handl is null.");
        
        return 0;
    }

    if (whence == 0) 
    {
        dvci->tell = ofst;
    } 
    else if (whence == 2) 
    {
        dvci->tell = dvci->ofs + ofst;
    } 
    else if (whence == 1)
    {
        dvci->tell += ofst;
    }

    dvci->tell = CLAMP(dvci->tell, 0, dvci->ofs);
    
    return dvci->tell;
}

// 100% matching!
void dvCiStopTr(DVCI dvci) 
{
    Sint32 i;

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
            for (i = 0; i < 20; i++) 
            {
                if (sceCdBreak() == 1) 
                {
                    break;
                }
                
                dvci_wait();
            } 
            
            if (i >= 20) 
            {
                sceCdSync(0);
            }
        }
        
        InvalidDCache(dvci->buf, (dvci->buf + (dvci->rdsct * 2048)) - 1);
        
        dvci->stat = 0;
    }
}

// 100% matching!
Sint32 dvCiTell(DVCI dvci)
{
    if (dvci == NULL) 
    {
        dvci_call_errfn(dvci, "E0092912:handl is null.");
        
        return 0;
    }

    return dvci->tell;
}
