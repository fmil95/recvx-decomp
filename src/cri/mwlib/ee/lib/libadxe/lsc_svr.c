#include "cri_lsc.h"

void lsc_ExecHndl(LSC lsc);
void lsc_StatEnd(LSC lsc);
void lsc_StatRead(LSC lsc);
void lsc_StatWait(LSC lsc);

// 100% matching! 
void lsc_ExecHndl(LSC lsc) 
{
    if ((lsc->pause == TRUE) || (lsc->stat != LSC_STAT_EXEC) || (lsc->nstm <= 0)) 
    {
        return;
    }

    if (lsc->sinfo[lsc->rpos].stat == LSC_STM_STAT_READ)
    {
        lsc_StatRead(lsc);
    }

    if (lsc->sinfo[lsc->rpos].stat == LSC_STM_STAT_END) 
    {
        lsc_StatEnd(lsc);
    }

    if (lsc->sinfo[lsc->rpos].stat != LSC_STM_STAT_WAIT) 
    {
        return;
    }
    
    lsc_StatWait(lsc); 
}

void lsc_StatEnd(LSC lsc) 
{
    scePrintf("lsc_StatEnd - UNIMPLEMENTED!\n");
}

// 100% matching! 
void lsc_StatRead(LSC lsc) 
{
    LSC_SINFO *sinfo;
	Sint32 stat;

    if (lsc->fp == NULL)
    {
        LSC_CallErrFunc("E0007: lsc->fp=NULL");
        return;
    }
    
    sinfo = &lsc->sinfo[lsc->rpos];
    
    stat = ADXSTM_GetStat(lsc->fp);
    
    if (stat == 4) 
    {
        lsc->stat = LSC_STAT_ERR;
    }
    else if (stat == 2)
    {
        sinfo->rdsct = ADXSTM_Tell(lsc->fp);
    }
    else if (stat == 3) 
    {
        sinfo->rdsct = lsc->fsct;
        
        sinfo->stat = LSC_STM_STAT_END;
    }
}

void lsc_StatWait(LSC lsc) 
{
    scePrintf("lsc_StatWait - UNIMPLEMENTED!\n");
}
