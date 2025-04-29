sceCdRMode dvg_ci_cdrmode;
void* dvg_flist_tbl;

// analysis_flist
// conv_to_tpath
// dvci_get_fstate

// 100% matching!
void dvci_init_flist(void) 
{
    *(Sint64*)&dvg_flist_tbl = 0;
}

void dvCiLoadFpCache(Char8* fname, Char8* fpc, Sint32 size)
{
    scePrintf("dvCiLoadFpCache - UNIMPLEMENTED!\n");
}

// 100% matching!
void dvCiSetRdMode(Sint32 nrtry, Sint32 speed, Sint32 dtype)
{
    dvg_ci_cdrmode.trycount = nrtry;
    
    dvg_ci_cdrmode.spindlctrl = speed;
    
    dvg_ci_cdrmode.datapattern = dtype;
}

// get_fp_from_fname
// load_flist
// search_fstate
