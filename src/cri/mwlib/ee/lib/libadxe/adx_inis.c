Sint32 adxt_vsync_svr_flag;

// 100% matching!
void adxini_rnaerr_cbfn(void* arg0, Char8* err_msg) 
{
    ADXERR_CallErrFunc1(err_msg);
}

// 100% matching!
void ADXT_ConfigVsyncSvr(Sint32 flg) 
{
    adxt_vsync_svr_flag = flg;
}

void ADXT_Finish(void) 
{
    scePrintf("ADXT_Finish - UNIMPLEMENTED!\n");
}

void ADXT_Init(void) 
{
    scePrintf("ADXT_Init - UNIMPLEMENTED!\n");
}

// ADXT_ResetLibrary
// ADXT_VsyncProc
