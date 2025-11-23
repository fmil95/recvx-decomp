#include "dvci_sub.h"
#include "dvci.h"

#include <stdio.h>
//#include <string.h>

static DVCI_FLIST_TBL dvg_flist_tbl = { 0 };
static Sint8 dvg_rbuf[4096];
sceCdRMode dvg_ci_cdrmode = { 0 };

// 100% matching!
static Sint32 analysis_flist_dup(void *inf, Sint8 *buf, Sint32 num)
{
    Sint32 pos;
	Sint32 begin;
	Sint32 len;
    DVS_CI_FCACHE *finf;

    for (pos = 0, begin = 0, len = 0; buf[pos] != '\0'; pos++)
    {
        if ((buf[pos] == '\n') || (buf[pos] == '\0'))
        {
            finf = (DVS_CI_FCACHE*)inf;
            
            memcpy(finf[len].fname, &buf[begin], (pos - begin) - 1);
            
            dvci_to_large_to_yen((Sint8*)finf[len].fname);
            
            len++;
            
            begin = pos + 1;
            
            if (len == num) 
            {
                break;
            }
        }
    }
    
    if (dvg_flist_tbl.finf == NULL) 
    {
        dvg_flist_tbl.finf = inf;
        
        dvg_flist_tbl.num = len;
    }
    
    return len;
}

// 100% matching!
void conv_to_tpath_dup(Sint8 *spath, Sint8 *tpath)
{
    strcpy(spath, tpath);
    
    if (strcmp(spath + (strlen(spath) - 2), ";1") != 0)
    {
        strcat(spath, ";1");
    }
    
    dvci_to_large_to_yen(spath);
}

// 100% matching!
Sint32 dvci_get_fstate(const Sint8 *fname, sceCdlFILE *fp)
{
    fp->lsn = 0;
    
    fp->size = 0;
    
    if (dvg_flist_tbl.finf != NULL) 
    {
        get_fp_from_fname(fp, fname, dvg_flist_tbl.finf, dvg_flist_tbl.num);
    }
}

// 100% matching!
void dvci_init_flist(void) 
{
    *(Sint64*)&dvg_flist_tbl = 0;
}

// 100% matching!
Sint32 dvCiLoadFpCache(Sint8 *fls_fname, Sint8 *fpc_ptr, Sint32 fpc_size)
{
    Char8 fname[128] = { 0 };
    
    memset(dvg_rbuf, 0, sizeof(dvg_rbuf));
    
    if (dvg_flist_tbl.finf == NULL)
    {
        dvci_init_flist();
    }
    
    if ((fls_fname == NULL) || (fpc_ptr == NULL) || (fpc_size == 0))
    {
        dvci_init_flist();
        
        return 0;
    }
    
    conv_to_tpath_dup((Sint8*)fname, fls_fname);
    
    if (load_flist_dup((Sint8*)fname, dvg_rbuf) == 0)
    {
        dvci_call_errfn(NULL, "E0111501:can't read filelist.(dvCiLoadDirInfo)");
        
        return 0;
    }
    
    return search_fstate(fpc_ptr, analysis_flist_dup(fpc_ptr, dvg_rbuf, (Uint32)fpc_size / 140)) * 140;
}

// 100% matching!
void dvCiSetRdMode(Sint32 nrtry, Sint32 speed, Sint32 dtype)
{
    dvg_ci_cdrmode.trycount = nrtry;
    
    dvg_ci_cdrmode.spindlctrl = speed;
    
    dvg_ci_cdrmode.datapattern = dtype;
}

// 100% matching!
static void get_fp_from_fname(sceCdlFILE *fp, const Sint8 *fname, void *inf, Sint32 num)
{
    Sint32 lp;
    DVS_CI_FCACHE *finf;

    finf = inf;

    for (lp = 0; lp < num; lp++)
    {
        if (strcasecmp(fname, (Char8*)&finf[lp].fname) == 0)
        {
            fp->lsn = finf[lp].lsn;
            
            fp->size = finf[lp].size;
            return;
        }
    }

    fp->lsn = 0;
    
    fp->size = 0;
}

// 100% matching!
static Sint32 load_flist_dup(Sint8 *fname, Sint8 *rbuf)
{
    sceCdlFILE fp;
    sceCdRMode mode;

    if ((sceCdSearchFile(&fp, (char*)fname) == 0) || (mode.spindlctrl = 1, mode.trycount = 0, mode.datapattern = 0, mode.pad = 0, (sceCdRead(fp.lsn, 2, rbuf, &mode) == 0))) 
    {
        return 0;
    }
    
    sceCdSync(0);
    
    return 1;
}

// 100% matching!
static Sint32 search_fstate(void *inf, Sint32 num)
{
    Char8 fname[128] = { 0 };
    sceCdlFILE fp;
	Sint32 lp;
	Sint32 found;
	char *fnameptr;
    DVS_CI_FCACHE *finf;

    found = 0;
    
    for (lp = 0; lp < num; lp++) 
    {
        finf = inf;

        fnameptr = finf[lp].fname;
        
        strcpy(fname, fnameptr);
        
        if (fnameptr[0] != '\0')
        {
            if (strcmp(fname + (strlen(fname) - 2), ";1") != 0) 
            {
                strcat(fname, ";1");
            }
            
            if (sceCdSearchFile(&fp, fname) == 1)
            {
                finf[lp].lsn = fp.lsn;
                
                found++;
                
                finf[lp].size = fp.size;
                
                printf("DVCI: \"%s\" found.\n", fname);
            }
            else 
            {
                printf("DVCI: \"%s\" Not found.\n", fname);
            }
        }
    } 
    
    printf("DVCI: Total %d files\n", found);
    
    return found;
}
