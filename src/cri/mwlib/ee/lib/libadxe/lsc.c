#include "cri_lsc.h"

/* The KATANA SDK has a header for this file, cri_lsc.h, while the PS2 CRIware headers don't. */

static void (*lsc_stat_func)(void* obj1, void* obj2);
static void* lsc_stat_obj1;
static void* lsc_stat_obj2;

// lsc_Alloc

// 100% matching!
void LSC_CallStatFunc(void) 
{
    if (lsc_stat_func != NULL) 
    {
        lsc_stat_func(lsc_stat_obj1, lsc_stat_obj2);
    }
}

LSC LSC_Create(SJ sj)
{
    scePrintf("LSC_Create - UNIMPLEMENTED!\n");
}

// 100% matching!
void LSC_Destroy(LSC lsc) 
{
    Sint32 unused;
    
    if (lsc != NULL) 
    {
        LSC_LockCrs(&unused);
        
        LSC_Stop(lsc);
        
        lsc->used = FALSE;
        
        memset(lsc, 0, sizeof(LSC_OBJ));

        LSC_UnlockCrs(&unused);
    }
}

// 100% matching!
void LSC_EntryChgStatFunc(void* func, void* obj1, void* obj2)
{
    if (func == NULL) 
    {
        lsc_stat_func = NULL;
        
        lsc_stat_obj1 = NULL;
        lsc_stat_obj2 = NULL;
    }
    else 
    {
        lsc_stat_func = func;
        
        lsc_stat_obj1 = obj1;
        lsc_stat_obj2 = obj2;
    }
}

void LSC_EntryFileRange(LSC lsc, char *fname, Sint32 arg2, Sint32 arg3, Sint32 flen) 
{
    scePrintf("LSC_EntryFileRange - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 LSC_EntryFname(LSC lsc, char *fname) 
{
    ADXSTM adxstm;
    Sint32 flen;

    adxstm = ADXSTM_OpenFname(fname, lsc->sj);
    
    if (adxstm == NULL) 
    {
        LSC_CallErrFunc("E0004: Can not open '%s'", fname);
    }
    
    flen = (ADXSTM_GetFileLen((Sint32)adxstm) + 2047) / 2048;
    
    ADXSTM_Close(adxstm);
    
    LSC_EntryFileRange(lsc, fname, 0, 0, flen);

    // this code blocks the compiler from doing the tail call optimization
    if (0 != 0)
    {
        while (TRUE);
    }
}

// 100% matching!
void LSC_ExecServer(void)
{
    LSC lsc;
    Sint32 i;
    Sint32 unused;

    LSC_LockCrs(&unused);
    
    for (i = 0; i < LSC_OBJ_MAX; i++) 
    {
        lsc = &lsc_obj[i];

        if (lsc->used == TRUE) 
        {
            lsc_ExecHndl(lsc);
        }
    }
    
    LSC_UnlockCrs(&unused);
}

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

    return (Char8*)lsc->sinfo[i].fname;
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

// 100% matching!
Sint32 LSC_GetStmRdSct(LSC lsc, Sint32 sid)
{
    Sint32 i;

    if (lsc == NULL)
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return 0;
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
        
        return 0;
    }

    return lsc->sinfo[i].rdsct;
}

// 100% matching!
Sint32 LSC_GetStmStat(LSC lsc, Sint32 sid) 
{
    Sint32 i;

    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -1;
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
        
        return -1;
    }

    return lsc->sinfo[i].stat;
}

// 100% matching!
void LSC_Pause(LSC lsc, Sint32 sw)
{
    if (lsc == NULL)
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }

    if (sw == 1) 
    {
        lsc->pause = TRUE;
    } 
    else
    {
        lsc->pause = FALSE;
    }
}

// 100% matching!
void LSC_SetFlowLimit(LSC lsc, Sint32 min)
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }

    if ((min < 0) || (min > lsc->bsize)) 
    {
        LSC_CallErrFunc("E0012: Can not find stream ID =%d", min);
        return;
    }
    
    lsc->bufmin = min;
}

// 100% matching!
void LSC_SetLpFlg(LSC lsc, Sint32 flg)
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }
    
    lsc->lpflg = flg;
}

// 100% matching!
void LSC_Start(LSC lsc)
{
    Sint32 unused;
    
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }

    LSC_LockCrs(&unused);

    if (lsc->stat != LSC_STAT_STOP) 
    {
        LSC_Stop(lsc);
    }

    if (lsc->nstm > 0)
    {
        lsc->stat = LSC_STAT_EXEC;
    } 
    else 
    {
        lsc->stat = LSC_STAT_WAIT;
    }

    LSC_UnlockCrs(&unused);
}

// 100% matching!
void LSC_Stop(LSC lsc) 
{
    Sint32 unused;

    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }
    
    LSC_LockCrs(&unused);
    
    if (lsc->fp != NULL) 
    {
        if (lsc->rdflg == 1) 
        {
            ADXSTM_Stop(lsc->fp);
            
            lsc->rdflg = 0;
        }
        
        ADXSTM_Close(lsc->fp);
        
        lsc->fp = NULL;
    }
    
    lsc->fsct = 0;
    
    lsc->wpos = 0;
    lsc->rpos = 0;
    
    lsc->nstm = 0;
    
    lsc->errcnt = 0;
    
    lsc->stat = LSC_STAT_STOP;
    
    LSC_UnlockCrs(&unused); 
}
