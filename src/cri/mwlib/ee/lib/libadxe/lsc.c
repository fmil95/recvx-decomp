#include "lsc.h"
#include "adx_stmc.h"
#include "lsc_crs.h"
#include "lsc_err.h"
#include "lsc_ini.h"
#include "lsc_svr.h"

#include <string.h>

/* The KATANA SDK has a header for this file, cri_lsc.h, while the PS2 CRIware headers don't. */

static LSC_STATFN lsc_stat_func;
static void *lsc_stat_obj1;
static void *lsc_stat_obj2;

// 100% matching!
LSC lsc_Alloc(void) 
{
    LSC lsc;
    Sint32 i;

    lsc = NULL;

    for (i = 0; i < LSC_OBJ_MAX; i++) 
    {
        if (lsc_obj[i].used == FALSE) 
        {
            lsc = &lsc_obj[i];
            break;
        }
    }

    return lsc;
}

// 100% matching!
void LSC_CallStatFunc(void) 
{
    if (lsc_stat_func != NULL) 
    {
        lsc_stat_func(lsc_stat_obj1, lsc_stat_obj2);
    }
}

// 100% matching!
LSC LSC_Create(SJ sj)
{
    LSC lsc;
    LSC_CRS crs;
    Sint32 i;

    if (sj == NULL)
    {
        LSC_CallErrFunc("E0001: Illigal parameter=sj (LSC_Create)");
        
        return NULL;
    }
    
    LSC_LockCrs(&crs);
    
    lsc = lsc_Alloc();

    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0002: Not enough instance (LSC_Create)");
    } 
    else 
    {
        lsc->stat = LSC_STAT_STOP;
        
        lsc->sj = sj;

        lsc->bsize = SJ_GetNumData(sj, 0) + SJ_GetNumData(sj, 1);
        
        lsc->bufmin = (lsc->bsize * 8) / 10;

        for (i = 0; i < LSC_STM_MAX; i++) 
        {
            lsc->sinfo[i].stat = LSC_STM_STAT_WAIT;
        }

        lsc->used = TRUE;
    }

    LSC_UnlockCrs(&crs);
    
    return lsc;
}

// 100% matching!
void LSC_Destroy(LSC lsc) 
{
    LSC_CRS crs;
    
    if (lsc != NULL) 
    {
        LSC_LockCrs(&crs);
        
        LSC_Stop(lsc);
        
        lsc->used = FALSE;
        
        memset(lsc, 0, sizeof(LSC_OBJ));

        LSC_UnlockCrs(&crs);
    }
}

// 100% matching!
void LSC_EntryChgStatFunc(LSC_STATFN statfn, void *obj1, void *obj2)
{
    if (statfn == NULL) 
    {
        lsc_stat_func = NULL;
        
        lsc_stat_obj1 = NULL;
        lsc_stat_obj2 = NULL;
    }
    else 
    {
        lsc_stat_func = statfn;
        
        lsc_stat_obj1 = obj1;
        lsc_stat_obj2 = obj2;
    }
}

// 100% matching!
Sint32 LSC_EntryFileRange(LSC lsc, Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct) 
{
    LSC_SINFO *sinfo;
	Sint32 sid;
	Sint32 pre_sid; /* unused */
	Sint32 pos;

    sid = 0;

    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -1;
    }

    if (lsc->nstm >= LSC_STM_MAX)
    {
        return -1;
    }

    if (fname == NULL) 
    {
        LSC_CallErrFunc("E0011: Illigal parameter fname=%s", fname);
        
        return -1;
    }

    sinfo = &lsc->sinfo[lsc->wpos];
    
    pos = (lsc->wpos + 15) % LSC_STM_MAX;
    
    sid = ((lsc->sinfo[pos].sid) == 0x7FFFFFFF) ? 0 : lsc->sinfo[pos].sid + 1;
    
    sinfo->sid = sid;

    strncpy((char*)sinfo->fname, (char*)fname, sizeof(sinfo->fname));
    
    sinfo->ofst = ofst;
    
    sinfo->fsct = nsct;
    
    sinfo->dir = dir;
    
    sinfo->stat = LSC_STM_STAT_WAIT;
    
    sinfo->rdsct = 0;
    
    lsc->nstm++;
    
    lsc->wpos++;
    
    lsc->wpos %= LSC_STM_MAX;

    if (lsc->stat == LSC_STAT_WAIT)
    {
        lsc->stat = LSC_STAT_EXEC;
    }

    return sid;
}

// 100% matching!
Sint32 LSC_EntryFname(LSC lsc, Sint8 *fname) 
{
    void *fp;
	Sint32 fsize;
	Sint32 fsct;

    fp = ADXSTM_OpenFname(fname, lsc->sj);
    
    if (fp == NULL) 
    {
        LSC_CallErrFunc("E0004: Can not open '%s'", fname);
    }

    fsct = (ADXSTM_GetFileLen(fp) + 2047) / 2048;
        
    ADXSTM_Close(fp);
    
    fsize = LSC_EntryFileRange(lsc, fname, NULL, 0, fsct);

    return fsize;
}

// 100% matching!
void LSC_ExecServer(void)
{
    LSC lsc;
    LSC_CRS crs;
    Sint32 i;
    
    LSC_LockCrs(&crs);
    
    for (i = 0; i < LSC_OBJ_MAX; i++) 
    {
        lsc = &lsc_obj[i];

        if (lsc->used == TRUE) 
        {
            lsc_ExecHndl(lsc);
        }
    }
    
    LSC_UnlockCrs(&crs);
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
Sint8* LSC_GetStmFname(LSC lsc, Sint32 sid)
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
    Sint32 pos;
    
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
    
    pos = (lsc->rpos + no) % LSC_STM_MAX;
    
    return lsc->sinfo[pos].sid;
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
    LSC_CRS crs;
    
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }

    LSC_LockCrs(&crs);

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

    LSC_UnlockCrs(&crs);
}

// 100% matching!
void LSC_Stop(LSC lsc) 
{
    LSC_CRS crs;

    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }
    
    LSC_LockCrs(&crs);
    
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
    
    LSC_UnlockCrs(&crs); 
}
