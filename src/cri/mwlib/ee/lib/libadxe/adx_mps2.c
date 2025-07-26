Sint32 adxps2_cur_prio;
Sint32 adxps2_cur_tid;
Sint32 volatile adxps2_id_safe;
Sint32 volatile adxps2_lock_count;
Sint32 adxps2_save_tprm[4] = { 0 };

// adxps2_adx_thrd_func
// ADXPS2_ExecServer

// 100% matching!
void ADXPS2_Lock(void)
{
    ThreadParam tprm; 
    Sint32 tid;

    if (adxps2_lock_count == 0)
    {
        tid = GetThreadId();
        
        ReferThreadStatus(tid, &tprm);
        
        ChangeThreadPriority(tid, adxps2_save_tprm[0]);
        
        adxps2_cur_prio = tprm.currentPriority;
        
        adxps2_cur_tid = tid;
        
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

// ADXPS2_RestoreVsyncCallback
// adxps2_safe_thrd_func

void ADXPS2_SetupThrd(ADXPS2_TPRM *tprm) 
{
    scePrintf("ADXPS2_SetupThrd - UNIMPLEMENTED!\n");
}

// ADXPS2_SetupUsvr
// ADXPS2_Shutdown
// ADXPS2_ShutdownThrd

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

// ADXPS2_VsyncCallback
