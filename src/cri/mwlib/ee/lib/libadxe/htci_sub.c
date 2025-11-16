#include "htci_sub.h"
#include "htci.h"

#include <stdio.h>
#include <string.h>

Sint32 htg_found = FALSE;
static HTCI_FLIST_TBL htg_flist_tbl = { 0 };
Sint32 htg_ci_open_mode = 0x8001;
static Sint8 htg_rbuf[4096];

// 100% matching!
static Sint32 analysis_flist(void *inf, Sint8 *buf, Sint32 num)
{
    Uint32 pos;
	Uint32 begin;
	Uint32 len;
    HTS_CI_FCACHE *finf;
    
    for (pos = 0, begin = 0, len = 0; buf[pos] != '\0'; pos++)
    {
        if (buf[pos] == '\\')
        {
            buf[pos] = '/';
        }
        
        if ((buf[pos] == '\n') || (buf[pos] == '\0'))
        {
            finf = inf;
            
            memcpy(finf[len].fname, &buf[begin], (pos - begin) - 1);
            
            len++;
            
            begin = pos + 1;
            
            if (len == num) 
            {
                break;
            }
        }
    }
    
    if (htg_flist_tbl.finf == NULL) 
    {
        if (htg_found != FALSE)
        {
            htci_call_errfn(NULL, "E0111601:can't found filelist.(htCiLoadfinfoInfo)");
        }
        else 
        {
            htg_found = TRUE;
            
            htg_flist_tbl.finf = inf;
            
            htg_flist_tbl.num = len;
        }
    }
    
    return len;
}

// 100% matching!
static Sint32 close_file_all(void)
{
    HTS_CI_FCACHE *inf;
	Uint32 lp;
	Uint32 found;
	Sint32 num;
	char fname[256];
	char *fnameptr;
    
    inf = htg_flist_tbl.finf;
    
    found = 0;
    
    if (inf == NULL)
    {
        if (htg_found != FALSE)
        {
            htci_call_errfn(NULL, "E0111602:can't found filelist.(htCiLoadDirInfo)");
        }
        
        return 0;
    }
    
    num = htg_flist_tbl.num;
    
    for (lp = 0; lp < num; lp++) 
    {
        fnameptr = inf[lp].fname;
            
        conv_to_tpath(fname, fnameptr);
        
        if (fnameptr[0] != '\0') 
        {
            if (sceClose(inf[lp].fd) < 0)
            {
                printf("HTCI: \"%s\" can't Close.(sceClose)\n", fname);
            } 
            else 
            {
                found++;
                
                printf("HTCI: \"%s\" Closed.(sceClose)\n", fname);
            }
        }
    } 
    
    printf("HTCI: Total %d files\n", found);
    
    htg_found = FALSE;
    
    htci_init_flist();
    
    return 1;
}

// 100% matching!
void conv_to_tpath(Char8 *spath, Char8 *tpath)
{
    Sint32 i;
	Sint32 flen;
    
    memcpy(spath, "host:", 6); 
    
    strcat(spath, tpath);

    flen = strlen(spath);
    
    if ((spath[flen - 1] == '/') || (spath[flen - 1] == '\\')) 
    {
        spath[flen - 1] = '\0';
    }
    
    flen = strlen(spath);
    
    for (i = 0; (Uint32)i < flen; i++) 
    {
        if (spath[i] == '\\') 
        {
            spath[i] = '/';
        }
    } 
}

// 100% matching!
static void get_fstate(HTS_CI_FCACHE *finf, const Uint8 *fname, HTS_CI_FCACHE *inf, Sint32 num)
{
    Sint32 lp;

    for (lp = 0; lp < num; lp++)
    {
        if (strcasecmp(fname, (Char8*)&inf[lp].fname) == 0)
        {
            finf->fd = inf[lp].fd;
            
            finf->size = inf[lp].size;
            return;
        }
    }

    finf->fd = 0;
    
    finf->size = 0;
}

// 100% matching!
void htci_get_finf(const Uint8 *fname, HTS_CI_FCACHE *inf)
{
    inf->fd = 0;
    
    inf->size = 0; 

    if (htg_flist_tbl.finf != NULL) 
    {
        get_fstate(inf, fname, htg_flist_tbl.finf, htg_flist_tbl.num);
    } 
}

// 100% matching!
void htci_init_flist(void) 
{
    *(Sint64*)&htg_flist_tbl = 0; 
    
    htg_found = FALSE;
}

// 100% matching!
Sint32 htCiLoadFpCache(Sint8 *fls_fname, Sint8 *fpc_ptr, Sint32 fpc_size)
{
    char fname[256] = { 0 };

    memset(htg_rbuf, 0, sizeof(htg_rbuf));
    
    if (htg_found == FALSE) 
    {
        htci_init_flist();
    }
    
    htci_wait_io();
    
    close_file_all();
    
    if ((fls_fname == NULL) || ((fpc_ptr == NULL) || (fpc_size == 0))) 
    {
        return 0;
    }
    
    conv_to_tpath((Char8*)fname, (Char8*)fls_fname);
    
    if (load_flist((Sint8*)fname, htg_rbuf) == 0) 
    {
        htci_call_errfn(NULL, "E0111501:can't read filelist.(htCiLoadDirInfo)");
        
        return 0;
    }
    else 
    {
        return open_file_all(fpc_ptr, analysis_flist(fpc_ptr, htg_rbuf, (Uint32)fpc_size / 268)) * 268;
    }
    
    return 0;
}

// 100% matching!
void htCiSetOpenMode(Sint32 mode)
{
    if (mode != 0) 
    {
        if (mode == 1) 
        {
            htg_ci_open_mode = mode;
        }
        else 
        {
            htg_ci_open_mode = 0x8001;
        }
    }
    else 
    {
        htg_ci_open_mode = 0x8001;
    }
}

// 100% matching!
Sint32 load_flist(Sint8 *fname, Sint8 *rbuf)
{
    int fd;
	Sint32 fsize;

    fd = sceOpen((char*)fname, SCE_RDONLY);
    
    if (fd < 0)
    {
        return 0;
    }
    
    fsize = sceLseek(fd, 0, SCE_SEEK_END);
    
    if ((fsize < 0) || (sceLseek(fd, 0, SCE_SEEK_SET) < 0)) 
    {
        return 0;
    }
    
    if (sceRead(fd, rbuf, (fsize < 4097) ? fsize : 4096) < 0) 
    {
        sceClose(fd);
        
        return 0;
    }
    
    sceClose(fd);
    
    return 1;
}

// 100% matching!
static Sint32 open_file_all(void *inf, Sint32 num)
{
    char fname[256] = { 0 };
	int fd;
	Sint32 lp;
	Sint32 found;
	char *fnameptr; 
    HTS_CI_FCACHE *finf;
    
    found = 0;
    
    if (num > 13) 
    {
        num = 13;
    }
    
    for (lp = 0; lp < num; lp++)
    {
        finf = inf;

        fnameptr = finf[lp].fname;
        
        conv_to_tpath(fname, fnameptr);
        
        if (fnameptr[0] != '\0') 
        {
            fd = sceOpen(fname, SCE_RDONLY);
            
            if (fd < 0) 
            {
                printf("HTCI: \"%s\" can't Open.(sceOpen)\n", fname);
            } 
            else 
            {
                finf[lp].fd = fd;
                
                found++;
                
                finf[lp].size = htci_get_fsize_opened(fd);
                
                printf("HTCI: \"%s\" Opened.(sceOpen)\n", fname);
                
                sceClose(fd);
                
                htci_wait_by_fd(sceOpen(fname, htg_ci_open_mode));
            }
        }
    } 
    
    printf("HTCI: Total %d files\n", found);
    
    return found;
}
