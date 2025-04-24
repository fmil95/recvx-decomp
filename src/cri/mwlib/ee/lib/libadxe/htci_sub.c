Sint32 htg_found;
Sint32 htg_rbuf[4096];
Sint32 htg_ci_open_mode;

Sint32 analysis_flist(Char8* fpc, Sint32* rbuf, Uint32 size)
{
    scePrintf("analysis_flist - UNIMPLEMENTED!\n");
}

void close_file_all()
{
    scePrintf("close_file_all - UNIMPLEMENTED!\n");
}

void conv_to_tpath(Char8* flist, Char8* fname)
{
    scePrintf("conv_to_tpath - UNIMPLEMENTED!\n");
}

// get_fstate
// htci_get_finf

void htci_init_flist()
{
    scePrintf("htci_init_flist - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 htCiLoadFpCache(Char8* fname, Char8* fpc, Uint32 size)
{
    Char8 flist[ADXF_FNAME_MAX] = {0};

    memset(htg_rbuf, 0, 4096);
    
    if (htg_found == 0) 
    {
        htci_init_flist();
    }
    
    htci_wait_io();
    
    close_file_all();
    
    if ((fname == NULL) || ((fpc == NULL) || (size == 0))) 
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
    Sint32 ofst;

    fd = sceOpen(flist, 1);
    
    if (fd < 0)
    {
        return 0;
    }
    
    ofst = sceLseek(fd, 0, 2);
    
    if ((ofst < 0) || (sceLseek(fd, 0, 0) < 0)) 
    {
        return 0;
    }
    
    if (sceRead(fd, rbuf, (ofst < 4097) ? ofst : 4096) < 0) 
    {
        sceClose(fd);
        
        return 0;
    }
    
    sceClose(fd);
    
    return 1;
}

Sint32 open_file_all(Char8* fpc, Sint32 arg1)
{
    scePrintf("open_file_all - UNIMPLEMENTED!\n");
}
