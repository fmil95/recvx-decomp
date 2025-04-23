Sint32 htg_ci_open_mode;

// analysis_flist
// close_file_all
// conv_to_tpath
// get_fstate
// htci_get_finf
// htci_init_flist

void htCiLoadFpCache(Char8* arg0, Char8* arg1, Sint32 arg2)
{
    scePrintf("htCiLoadFpCache - UNIMPLEMENTED!\n");
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

// load_flist
// open_file_all
