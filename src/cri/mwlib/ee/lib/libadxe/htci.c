void (*htg_ci_err_func)(void* err_obj, Char8* err_msg, Sint32 arg2);
void* htg_ci_err_obj;
Sint32 htci_vtbl[1];

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
// htci_is_all_excute
// htci_is_one_excute
// htci_wait
// htci_wait_by_fd

void htci_wait_io()
{
    scePrintf("htci_wait_io - UNIMPLEMENTED!\n");
}

// htCiClose
// htCiEntryErrFunc
// htCiExecHndl
// htCiExecServer
// htCiGetFileSize

// 100% matching!
Sint32* htCiGetInterface(void)
{
    return htci_vtbl;
}

// htCiGetNumTr
// htCiGetSctLen
// htCiGetStat
// htCiOpen
// htCiReqRd
// htCiSeek
// htCiStopTr
// htCiTell
