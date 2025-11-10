#include "adx_mps2.h"
#include "adx_fsvr.h"

#include <libgraph.h>

char* volatile adxps2_build = "\nADXPS2 Ver.1.01 Build:Mar 14 2001 14:23:33\n";
static ADXPS2_TPRM adxps2_save_tprm = { 0 };
int volatile adxps2_id_safe = 0;
int volatile adxps2_id_adx = 0;
int volatile adxps2_id_main = 0;
Sint32 volatile adxps2_exec_svr = 0;
Sint32 volatile adxps2_lock_count = 0;
long unsigned int volatile adxps2_scnt = 0;
long unsigned int volatile adxps2_vcnt = 0;
int (*adxps2_old_cbf)(int arg) = NULL;
int adxps2_cur_prio = 0;
int adxps2_cur_tid = 0;
int adxps2_main_prio_def = 0;
static char adxps2_stk_adx[DEF_STACK_SIZE] bss_align(64);
static char adxps2_stk_safe[DEF_STACK_SIZE] bss_align(64); // TODO: double-check whether DEF_STACK_SIZE should be 2048, or 4096 instead

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

// 99.89% matching
void ADXPS2_SetupThrd(ADXPS2_TPRM *tprm)
{
    ThreadParam th0;
    ThreadParam th1;
    ThreadParam th2;

    if (tprm == NULL) 
    {
        adxps2_save_tprm.prio_main = 24;
        
        adxps2_save_tprm.prio_lock = 1;
        
        adxps2_save_tprm.prio_safe = 8;
        
        adxps2_save_tprm.prio_adx = 16;
    } 
    else
    {
        adxps2_save_tprm = *tprm;
    }

    th1.stackSize = DEF_STACK_SIZE;
    
    th1.gpReg = &_gp;
    
    th1.entry = &adxps2_safe_thrd_func;
    
    th1.stack = &adxps2_stk_safe;
    
    th1.initPriority = adxps2_save_tprm.prio_safe;
    
    adxps2_id_safe = CreateThread(&th1);
    
    adxps2_id_safe;
    
    StartThread(adxps2_id_safe, NULL);
    
    if (adxps2_id_safe != 0) 
    {
        SuspendThread(adxps2_id_safe);
        
        adxps2_id_safe;
    }

    th0.stackSize = DEF_STACK_SIZE;
    
    th0.gpReg = &_gp;
    
    th0.entry = &adxps2_adx_thrd_func;
    
    th0.stack = &adxps2_stk_adx;
    
    th0.initPriority = adxps2_save_tprm.prio_adx;
    
    adxps2_id_adx = CreateThread(&th0);
    
    adxps2_id_adx;
    
    StartThread(adxps2_id_adx, NULL);
    
    adxps2_id_main = GetThreadId();
    
    ReferThreadStatus(adxps2_id_main, &th2);
    
    adxps2_main_prio_def = th2.currentPriority;
    
    ChangeThreadPriority(adxps2_id_main, adxps2_save_tprm.prio_main);
    
    ADXPS2_RestoreVsyncCallback();
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
