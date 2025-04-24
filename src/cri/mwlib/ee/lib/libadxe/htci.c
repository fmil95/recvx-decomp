Sint32 htci_vtbl[1];

// htci_alloc
// htci_build

void htci_call_errfn(Sint32 arg0, Char8* err_msg)
{
    scePrintf("htci_call_errfn - UNIMPLEMENTED!\n");
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
