#include "dvci_sub.h"
#include "dvci.h"

#include <stdio.h>
//#include <string.h>

static DVG_FLIST_TBL dvg_flist_tbl = { 0 };
static Sint8 dvg_rbuf[4096];
sceCdRMode dvg_ci_cdrmode = { 0 };

// 100% matching!
Sint32 analysis_flist_dup(Char8* fpc, Sint8* rbuf, Uint32 size)
{
    DVCI_DIR dir;
    Sint32 i;
    Sint32 j;
    Sint32 k;

    for (i = 0, j = 0, k = 0; rbuf[i] != '\0'; i++)
    {
        if ((rbuf[i] == '\n') || (rbuf[i] == '\0'))
        {
            dir = (DVCI_DIR)fpc;
            
            memcpy(dir[k].fname, &rbuf[j], (i - j) - 1);
            
            dvci_to_large_to_yen(dir[k].fname);
            
            k++;
            
            j = i + 1;
            
            if (k == size) 
            {
                break;
            }
        }
    }
    
    if (dvg_flist_tbl.fp == NULL) 
    {
        dvg_flist_tbl.fp = fpc;
        
        dvg_flist_tbl.fsize = k;
    }
    
    return k;
}

// 100% matching!
void conv_to_tpath_dup(Char8* fname, Char8* path)
{
    strcpy(fname, path);
    
    if (strcmp(fname + (strlen(fname) - 2), ";1") != 0)
    {
        strcat(fname, ";1");
    }
    
    dvci_to_large_to_yen(fname);
}

// 100% matching!
void dvci_get_fstate(const Char8* fname, sceCdlFILE* fp)
{
    fp->lsn = 0;
    
    fp->size = 0;
    
    if (dvg_flist_tbl.fp != NULL) 
    {
        get_fp_from_fname(fp, fname, (DVCI_DIR)dvg_flist_tbl.fp, dvg_flist_tbl.fsize);
    }
}

// 100% matching!
void dvci_init_flist(void) 
{
    *(Sint64*)&dvg_flist_tbl = 0;
}

// 100% matching!
Sint32 dvCiLoadFpCache(Char8* fname, Char8* fpc, Uint32 size) 
{
    Char8 flist[128] = { 0 };
    
    memset(dvg_rbuf, 0, sizeof(dvg_rbuf));
    
    if (dvg_flist_tbl.fp == NULL)
    {
        dvci_init_flist();
    }
    
    if ((fname == NULL) || (fpc == NULL) || (size == 0))
    {
        dvci_init_flist();
        
        return 0;
    }
    
    conv_to_tpath_dup(flist, fname);
    
    if (load_flist_dup(flist, dvg_rbuf) == 0)
    {
        dvci_call_errfn(NULL, "E0111501:can't read filelist.(dvCiLoadDirInfo)");
        
        return 0;
    }
    
    return search_fstate(fpc, analysis_flist_dup(fpc, dvg_rbuf, size / 140)) * 140;
}

// 100% matching!
void dvCiSetRdMode(Sint32 nrtry, Sint32 speed, Sint32 dtype)
{
    dvg_ci_cdrmode.trycount = nrtry;
    
    dvg_ci_cdrmode.spindlctrl = speed;
    
    dvg_ci_cdrmode.datapattern = dtype;
}

// 100% matching!
void get_fp_from_fname(sceCdlFILE* fp, const Char8* fname, DVCI_DIR dir, Sint32 size)
{
    Sint32 i;

    for (i = 0; i < size; i++)
    {
        if (strcasecmp(fname, (Char8*)&dir[i].fname) == 0)
        {
            fp->lsn = dir[i].fd;
            
            fp->size = dir[i].fsize;
            return;
        }
    }

    fp->lsn = 0;
    
    fp->size = 0;
}

// 100% matching!
Sint32 load_flist_dup(Char8* flist, Sint8* rbuf)  
{
    sceCdlFILE fp;
    sceCdRMode mode;

    if ((sceCdSearchFile(&fp, flist) == 0) || (mode.spindlctrl = 1, mode.trycount = 0, mode.datapattern = 0, mode.pad = 0, (sceCdRead(fp.lsn, 2, rbuf, &mode) == 0))) 
    {
        return 0;
    }
    
    sceCdSync(0);
    
    return 1;
}

// 100% matching!
Sint32 search_fstate(Char8* fpc, Sint32 fsize)
{
    Char8 flist[128] = { 0 };
    DVCI_DIR dir;
    Sint32 numf;
    Sint32 fd;
    Sint32 i;
    sceCdlFILE fp;

    numf = 0;
    
    for (i = 0; i < fsize; i++) 
    {
        dir = (DVCI_DIR)fpc;
        
        strcpy(flist, dir[i].fname);
        
        if (dir[i].fname[0] != '\0')
        {
            if (strcmp(flist + (strlen(flist) - 2), ";1") != 0) 
            {
                strcat(flist, ";1");
            }
            
            if (sceCdSearchFile(&fp, flist) == 1)
            {
                dir[i].fd = fp.lsn;
                
                numf++;
                
                dir[i].fsize = fp.size;
                
                printf("DVCI: \"%s\" found.\n", flist);
            }
            else 
            {
                printf("DVCI: \"%s\" Not found.\n", flist);
            }
        }
    } 
    
    printf("DVCI: Total %d files\n", numf);
    
    return numf;
}
