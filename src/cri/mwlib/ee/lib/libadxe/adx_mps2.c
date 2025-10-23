typedef struct 
{ // 0x1c
	/* 0x00 */ int prio_lock;
	/* 0x04 */ int prio_safe;
	/* 0x08 */ int prio_usrvsync;
	/* 0x0c */ int prio_vsync;
	/* 0x10 */ int prio_main;
	/* 0x14 */ int prio_mwidle;
	/* 0x18 */ int prio_usridle;
} ADXPS2_TPRM_EX;

static int adxps2_cur_tid;
static ADXPS2_TPRM_EX adxps2_save_tprm = { 0 };
static int adxps2_cur_prio;
static Sint32 volatile adxps2_lock_count;
static Sint32 volatile adxps2_exec_svr;
static int volatile adxps2_id_adx;
static int volatile adxps2_id_main;
static int volatile adxps2_id_safe;
static int adxps2_main_prio_def;
static int (*adxps2_old_cbf)(int arg);
static long unsigned int volatile adxps2_scnt;
static long unsigned int volatile adxps2_vcnt;

// 100% matching!
void adxps2_adx_thrd_func(void)
{
    while (TRUE) 
    {
        adxps2_exec_svr = 1;
        
        ADXPS2_Lock();
        
        ADXT_ExecServer();
        ADXT_ExecFsSvr();
        
        ADXPS2_Unlock();
        
        adxps2_exec_svr = 0;
        
        SleepThread(); 
    }
}

// 100% matching!
void ADXPS2_ExecServer(void) 
{
    ADXT_ExecServer();
    ADXT_ExecFsSvr();
}

// 100% matching!
void ADXPS2_Lock(void)
{
    ThreadParam info; 
    Sint32 th_id;

    if (adxps2_lock_count == 0)
    {
        th_id = GetThreadId();
        
        ReferThreadStatus(th_id, &info);
        
        ChangeThreadPriority(th_id, adxps2_save_tprm.prio_lock);
        
        adxps2_cur_prio = info.currentPriority;
        
        adxps2_cur_tid = th_id;
        
        if (adxps2_id_safe != 0)
        {
            ResumeThread(adxps2_id_safe);
            
            if (adxps2_id_safe != 0)
            {
                
            }
        }
    }
    
    adxps2_lock_count++;
}

// 100% matching!
void ADXPS2_RestoreVsyncCallback(void) 
{
    adxps2_old_cbf = (void*)sceGsSyncVCallback(ADXPS2_VsyncCallback);
}

// 99.29% matching
void adxps2_safe_thrd_func(void) 
{
    while (TRUE) 
    {
        adxps2_scnt++;
        
        adxps2_scnt;
    }
}

void ADXPS2_SetupThrd(ADXPS2_TPRM *tprm) 
{
    scePrintf("ADXPS2_SetupThrd - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADXPS2_SetupUsvr(void) 
{

}

// 100% matching!
void ADXPS2_Shutdown(void) 
{

}

// 100% matching!
void ADXPS2_ShutdownThrd(void)
{
    SuspendThread(adxps2_id_adx);
    
    adxps2_id_adx;
    
    DeleteThread(adxps2_id_adx);
    
    adxps2_id_adx;
    
    SuspendThread(adxps2_id_safe);
    
    adxps2_id_safe;
    
    DeleteThread(adxps2_id_safe);
    
    adxps2_id_safe;
    
    adxps2_id_main = GetThreadId();
    
    ChangeThreadPriority(adxps2_id_main, adxps2_main_prio_def);
}

// 100% matching!
void ADXPS2_Unlock(void)
{
    adxps2_lock_count--;
    
    if (adxps2_lock_count == 0) 
    {
        if (adxps2_id_safe != 0) 
        {
            SuspendThread(adxps2_id_safe);
            
            if (adxps2_id_safe != 0)
            {
                
            }
        }
        
        ChangeThreadPriority(GetThreadId(), adxps2_cur_prio);
    }
    
    if (adxps2_lock_count < 0) 
    {
        adxps2_lock_count = 0;
    }
}

// 100% matching!
int ADXPS2_VsyncCallback(int arg)
{
    if ((adxps2_exec_svr == 0) && (adxps2_id_adx != 0)) 
    {
        iWakeupThread(adxps2_id_adx);
    }
    
    adxps2_vcnt++;
    
    if (adxps2_old_cbf != NULL) 
    {
        return adxps2_old_cbf(arg);
    }
    
    return 0;
}
