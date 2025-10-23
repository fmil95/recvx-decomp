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

void LSC_CallStatFunc(void); // TODO: remove this function declaration
// 100% matching!
void lsc_StatEnd(LSC lsc) 
{
    static Sint8 fname[LSC_FNAME_MAX];
	void *dir;
	Sint32 ofst;
	Sint32 nsct;
	LSC_SINFO *sinfo;

    dir = NULL; 
    
    ofst = 0;
    
    nsct = 0; 
    
    if (lsc->fp != NULL) 
    {
        ADXSTM_Close(lsc->fp); 
        
        lsc->fp = NULL;
        
        if (lsc->lpflg == 1) 
        {
            sinfo = &lsc->sinfo[lsc->rpos];
            
            memcpy(fname, sinfo->fname, sizeof(fname) - 1);
            
            dir = sinfo->dir;
            
            ofst = sinfo->ofst;
            
            nsct = sinfo->fsct;
        }
        
        lsc->nstm--;
        
        lsc->rpos++; 
        
        lsc->rpos -= (lsc->rpos / LSC_STM_MAX) * LSC_STM_MAX;
        
        if (lsc->nstm <= 0) 
        {
            LSC_CallStatFunc();
            
            lsc->stat = LSC_STAT_WAIT;
        }
        
        if (lsc->lpflg == 1) 
        {
            LSC_EntryFileRange(lsc, &fname, dir, ofst, nsct);
        }
    }
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

// 100% matching!
void lsc_StatWait(LSC lsc)
{
    LSC_SINFO *sinfo;
	Sint32 fsct;

    sinfo = &lsc->sinfo[lsc->rpos];
    
    if (lsc->nstm > 0)
    {
        if (lsc->fp == NULL)
        {
            lsc->fp = ADXSTM_OpenFileRangeExRt(sinfo->fname, sinfo->dir, sinfo->ofst, sinfo->fsct, lsc->sj);
            
            if (lsc->fp == NULL) 
            {
                LSC_CallErrFunc("E0004: Can not open '%s'", sinfo->fname);
            }
            
            fsct = (ADXSTM_GetFileLen(lsc->fp) + 2047) / 2048;
            
            lsc->rdflg = 0;
            
            lsc->fsct = fsct;
            
            sinfo->rdsct = 0;
        }
        
        if (lsc->rdflg == 0) 
        {
            ADXSTM_SetBufSize(lsc->fp, lsc->bufmin, lsc->bsize);
            
            ADXSTM_Seek(lsc->fp, 0);
            
            ADXSTM_Start(lsc->fp);
            
            lsc->rdflg = 1;
        }
        
        sinfo->stat = LSC_STAT_WAIT;
    } 
    else if (lsc->fp != NULL)
    {
        LSC_CallErrFunc("E0006: Illigal member nstm='%d' fp='%08x'h", lsc->nstm, lsc->fp);
    }
}
