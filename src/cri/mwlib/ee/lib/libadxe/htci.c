void (*htg_ci_err_func)(void* err_obj, Char8* err_msg, Sint32 arg2);
void* htg_ci_err_obj;
void* htci_vtbl;

// htci_alloc
// htci_build

// 100% matching!
void htci_call_errfn(Sint32 arg0, Char8* htg_ci_err_msg)
{
    if (htg_ci_err_func != NULL) 
    { 
        htg_ci_err_func(htg_ci_err_obj, htg_ci_err_msg, arg0);
    }
}

// htci_conv_fname
// htci_free
// htci_get_fsize_opened

Sint32 htci_is_all_excute(void)
{
    scePrintf("htci_is_all_excute - UNIMPLEMENTED!\n");
}

// htci_is_one_excute

// 100% matching!
void htci_wait(void) 
{
    Sint32 i;

    for (i = 0; i < 32768; i++);
}

// htci_wait_by_fd

// 100% matching!
void htci_wait_io(void) 
{
    while (htci_is_all_excute() == 0);
}

// htCiClose
// htCiEntryErrFunc
// htCiExecHndl
// htCiExecServer
// htCiGetFileSize

// 100% matching!
void* htCiGetInterface(void)
{
    return &htci_vtbl;
}

// htCiGetNumTr
// htCiGetSctLen
// htCiGetStat
// htCiOpen
// htCiReqRd
// htCiSeek
// htCiStopTr
// htCiTell
