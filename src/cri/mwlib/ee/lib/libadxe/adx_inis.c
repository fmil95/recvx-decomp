Sint32 adxt_vsync_svr_flag;
Sint32 adxt_init_cnt;
Sint32 adxt_vsync_cnt;

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

// 100% matching!
void ADXT_ResetLibrary(void)
{
    adxt_init_cnt = 0;
    
    ADXT_Init();
}

// 100% matching!
void ADXT_VsyncProc(void) 
{
    adxt_vsync_cnt++; 
    
    ADXT_ExecServer();
}
