#include "lsc.h"

/* The KATANA SDK has a header for this file, cri_lsc.h, while the PS2 CRIware headers don't. */

// lsc_Alloc
// LSC_CallStatFunc

LSC LSC_Create(SJ sj)
{
    scePrintf("LSC_Create - UNIMPLEMENTED!\n");
}

void LSC_Destroy(LSC lsc)
{
    scePrintf("LSC_Destroy - UNIMPLEMENTED!\n");
}

// LSC_EntryChgStatFunc
// LSC_EntryFileRange
// LSC_EntryFname
// LSC_ExecServer

// 100% matching!
Sint32 LSC_GetFlowLimit(LSC lsc) 
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -1;
    }
    
    return lsc->bufmin;
}

// LSC_GetNumStm
// LSC_GetStat
// LSC_GetStmFname
// LSC_GetStmId
// LSC_GetStmRdSct
// LSC_GetStmStat
// LSC_Pause
// LSC_SetFlowLimit
// LSC_SetLpFlg
// LSC_Start

void LSC_Stop(LSC lsc)
{
    scePrintf("LSC_Stop - UNIMPLEMENTED!\n");
}
