void* dvg_flist_tbl;
Sint32 dvg_rbuf[4096];
sceCdRMode dvg_ci_cdrmode;

Sint32 load_flist_dup(Char8* flist, Sint32* rbuf);

Sint32 analysis_flist_dup(Char8* fpc, Sint32* rbuf, Uint32 size)
{
    scePrintf("analysis_flist_dup - UNIMPLEMENTED!\n");
}

void conv_to_tpath_dup(Char8* flist, Char8* fname)
{
    scePrintf("conv_to_tpath_dup - UNIMPLEMENTED!\n");
}

// dvci_get_fstate

// 100% matching!
void dvci_init_flist(void) 
{
    *(Sint64*)&dvg_flist_tbl = 0;
}

// 100% matching!
Sint32 dvCiLoadFpCache(Char8* fname, Char8* fpc, Uint32 size) 
{
    Char8 flist[ADXPS2_DEF_MAXFLEN_DVD] = {0};
    
    memset(dvg_rbuf, 0, 4096);
    
    if (dvg_flist_tbl == NULL)
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
        dvci_call_errfn(0, "E0111501:can't read filelist.(dvCiLoadDirInfo)");
        
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

// get_fp_from_fname

// 100% matching!
Sint32 load_flist_dup(Char8* flist, Sint32* rbuf)  
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

Sint32 search_fstate(Char8* fpc, Sint32 arg1)
{
    scePrintf("search_fstate - UNIMPLEMENTED!\n");
}
