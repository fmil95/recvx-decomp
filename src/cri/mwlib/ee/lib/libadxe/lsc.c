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

// 100% matching!
Sint32 LSC_GetNumStm(LSC lsc) 
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -1;
    }
    
    return lsc->nstm;
}

// 100% matching!
Sint32 LSC_GetStat(LSC lsc) 
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -1;
    }
    
    return lsc->stat;
}

// 100% matching!
char *LSC_GetStmFname(LSC lsc, Sint32 sid)
{
    Sint32 i;

    if (lsc == NULL)
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return NULL;
    }

    for (i = 0; i < LSC_STM_MAX; i++) 
    {
        if (lsc->sinfo[i].sid == sid) 
        {
            break;
        }
    }

    if (i == LSC_STM_MAX) 
    {
        LSC_CallErrFunc("E0012: Can not find stream ID =%d", sid);
        
        return NULL;
    }

    return lsc->sinfo[i].fname;
}

// 100% matching!
Sint32 LSC_GetStmId(LSC lsc, Sint32 no)
{
    Sint32 i;
    
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -1;
    }

    if ((no < 0) || (no >= lsc->nstm)) 
    {
        LSC_CallErrFunc("E0012: Can not find stream ID =%d", no);
        
        return -1;
    }
    
    i = (lsc->rpos + no) % LSC_STM_MAX;
    
    return lsc->sinfo[i].sid;
}

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
