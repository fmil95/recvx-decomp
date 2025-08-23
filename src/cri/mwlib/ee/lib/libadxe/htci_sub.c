
typedef struct _htg_flist_tbl 
{
    Char8*  fp;
    Sint32  fsize;
} HTG_FLIST_TBL;

typedef struct _htci_dir_obj
{
    Sint32  fd;
    Sint32  fsize;
    Char8   fname[256]; 
    Uint8   pad[4];
} HTCI_DIR_OBJ;

typedef HTCI_DIR_OBJ *HTCI_DIR;

static HTG_FLIST_TBL htg_flist_tbl;
Sint32 htg_found;
Sint32 htg_rbuf[4096];
Sint32 htg_ci_open_mode;

void conv_to_tpath(Char8* flist, Char8* fname);
void htci_init_flist(void);

Sint32 analysis_flist(Char8* fpc, Sint32* rbuf, Uint32 size)
{
    scePrintf("analysis_flist - UNIMPLEMENTED!\n");
}

void htci_call_errfn(void* obj, const Char8* msg); // remove this declaration
// 100% matching!
Sint32 close_file_all(void)
{
    Char8 flist[256];
    HTCI_DIR dir;
    Sint32 numf;
    Uint32 size;
    Uint32 i;

    dir = (HTCI_DIR)htg_flist_tbl.fp;
    
    numf = 0;
    
    if (dir == NULL)
    {
        if (htg_found != 0)
        {
            htci_call_errfn(0, "E0111602:can't found filelist.(htCiLoadDirInfo)");
        }
        
        return 0;
    }
    
    size = htg_flist_tbl.fsize;
    
    for (i = 0; i < size; i++) // the loop limit here might not be a size  
    {
        conv_to_tpath(flist, dir[i].fname);
        
        if (dir[i].fname[0] != 0) 
        {
            if (sceClose(dir[i].fd) < 0)
            {
                printf("HTCI: \"%s\" can't Close.(sceClose)\n", flist);
            } 
            else 
            {
                numf++;
                
                printf("HTCI: \"%s\" Closed.(sceClose)\n", flist);
            }
        }
    } 
    
    printf("HTCI: Total %d files\n", numf);
    
    htg_found = 0;
    
    htci_init_flist();
    
    return 1;
}

// 100% matching!
void conv_to_tpath(Char8* fname, Char8* path)
{
    Uint32 i;
    Sint32 len;

    memcpy(fname, "host:", sizeof("host:")); 
    
    strcat(fname, path);

    len = strlen(fname);
    
    if ((fname[len - 1] == '/') || (fname[len - 1] == '\\')) 
    {
        fname[len - 1] = '\0';
    }
    
    len = strlen(fname);
    
    for (i = 0; i < len; i++) 
    {
        if (fname[i] == '\\') 
        {
            fname[i] = '/';
        }
    } 
}

void get_fstate(sceCdlFILE* fp, const Char8* fname, HTCI_DIR dir, Sint32 size)
{
    scePrintf("get_fstate - UNIMPLEMENTED!\n");
}

// 100% matching!
void htci_get_finf(Char8* fname, sceCdlFILE* fp) 
{
    HTCI_DIR dir;

    dir = (HTCI_DIR)htg_flist_tbl.fp; 
    
    fp->lsn = 0;
    
    fp->size = 0; 

    if (dir != NULL) 
    {
        get_fstate(fp, fname, dir, htg_flist_tbl.fsize);
    } 
}

// 100% matching!
void htci_init_flist(void) 
{
    *(Sint64*)&htg_flist_tbl = 0; // cast doesn't seem valid, furthermore htg_flist_tbl might be a different data type altogether
    
    htg_found = 0;
}

void htci_wait_io(void); // remove this declaration
// 100% matching!
Sint32 htCiLoadFpCache(Char8* fname, Char8* fpc, Uint32 size)
{
    Char8 flist[256] = { 0 };

    memset(htg_rbuf, 0, 4096);
    
    if (htg_found == 0) 
    {
        htci_init_flist();
    }
    
    htci_wait_io();
    
    close_file_all();
    
    if ((fname == NULL) || (fpc == NULL) || (size == 0)) 
    {
        return 0;
    }
    
    conv_to_tpath(flist, fname);
    
    if (load_flist(flist, htg_rbuf) == 0) 
    {
        htci_call_errfn(0, "E0111501:can't read filelist.(htCiLoadDirInfo)");
        
        return 0;
    }
    else 
    {
        return open_file_all(fpc, analysis_flist(fpc, htg_rbuf, size / 268)) * 268;
    }
    
    return 0;
}

// 100% matching!
void htCiSetOpenMode(Sint32 opmode) 
{
    if (opmode != 0) 
    {
        if (opmode == 1) 
        {
            htg_ci_open_mode = opmode;
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
Sint32 load_flist(Char8* flist, Sint32* rbuf) 
{
    Sint32 fd;
    Sint32 fsize;

    fd = sceOpen(flist, SCE_RDONLY);
    
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
Sint32 open_file_all(Char8* fpc, Sint32 arg1)
{
    Char8 flist[256] = { 0 };
    HTCI_DIR dir;
    Sint32 numf;
    Sint32 fd;
    Sint32 i;
    
    numf = 0;
    
    if (arg1 > 13) 
    {
        arg1 = 13;
    }
    
    for (i = 0; i < arg1; i++)
    {
        dir = (HTCI_DIR)fpc;
        
        conv_to_tpath(flist, dir[i].fname);
        
        if (dir[i].fname[0] != 0) 
        {
            fd = sceOpen(flist, SCE_RDONLY);
            
            if (fd < 0) 
            {
                printf("HTCI: \"%s\" can't Open.(sceOpen)\n", flist);
            } 
            else 
            {
                dir[i].fd = fd;
                
                numf++;
                
                dir[i].fsize = htci_get_fsize_opened(fd);
                
                printf("HTCI: \"%s\" Opened.(sceOpen)\n", flist);
                
                sceClose(fd);
                
                htci_wait_by_fd(sceOpen(flist, htg_ci_open_mode));
            }
        }
    } 
    
    printf("HTCI: Total %d files\n", numf);
    
    return numf;
}
