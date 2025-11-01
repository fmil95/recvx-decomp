#include "adx_fs.h"
#include "adx_fini.h"
#include "adx_stmc.h"

#define REG_RCNT0_COUNT     (volatile int *)0x10000000

#define getRcnt0CountShort() *REG_RCNT0_COUNT & 0xFFFF

void* buf;
Sint32* D_01E272F0;
Sint32* wrk32;
Sint32 adxf_tcnt[10] = { 0 };
Sint32 adxf_chkp_tcnt[10] = { 0 };

void adxf_SetCmdHstry(Sint32 ncall, Sint32 fg, Sint32 ptid, Sint32 flid, Sint32 type);
void adxf_wait_1ms(void);

// ADXF_AddPartition

// 100% matching!
ADXF adxf_AllocAdxFs(void) 
{
    Sint32 i;
    ADXF adxf;

    adxf = NULL;
    
    for (i = 0; i < ADXF_OBJ_MAX; i++)
    {
        if (adxf_obj[i].used == FALSE) 
        {
            adxf = &adxf_obj[i];
            break;
        }
    }

    return adxf;
}

// 100% matching!
Sint32 adxf_ChkPrmGfr(Uint32 ptid, Sint32 flid)
{
    ADXF_PTINFO* ptinfo;

    if (ptid >= ADXF_PART_MAX) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040828:'ptid' is range outside.");
        
        return ADXF_ERR_PRM;
    }
    
    ptinfo = adxf_ptinfo[ptid];
    
    if (ptinfo == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040828:'ptid' is range outside.");
        
        return ADXF_ERR_PRM;
    }
    
    if ((flid < 0) || (flid >= ptinfo->nfile))
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040828:'flid' is range outside.");
        
        return ADXF_ERR_PRM;
    } 
    
    return ADXF_ERR_OK;
}

// 100% matching!
Sint32 adxf_ChkPrmPt(Uint32 ptid, ADXF_PTINFO* ptinfo) 
{
    if (ptid >= ADXF_PART_MAX) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040801:'ptid' is range outside.(adxf_ChkPrmPt)");
        
        return ADXF_ERR_PRM;
    }
    
    if (ptinfo == NULL)
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)");
        
        return ADXF_ERR_PRM;
    }
    
    return ADXF_ERR_OK;
}

// 100% matching!
void ADXF_Close(ADXF adxf)
{
    adxf_SetCmdHstry(3, 0, (Sint32)adxf, -1, -1);
    
    if (adxf != NULL) 
    {
        ADXCRS_Lock();
        
        if (adxf->stat == ADXF_STAT_READING) 
        {
            ADXF_Stop(adxf);
        }
        
        if (adxf->stm != NULL) 
        {
            ADXSTM_Close(adxf->stm);
        }
        
        *adxf = (ADX_FS){0};
        
        ADXCRS_Unlock();
        
        adxf_SetCmdHstry(3, 1, (Sint32)adxf, -1, -1);
    }
}

// 100% matching!
void ADXF_CloseAll(void)
{
    Sint32 i;

    for (i = 0; i < ADXF_OBJ_MAX; i++)
    {
        if (adxf_obj[i].used == TRUE) 
        {
            ADXF_Close(&adxf_obj[i]);
        }
    }
}

// 100% matching!
void adxf_CloseLdptnwHn(void) 
{
    ADXF_Close(adxf_ldptnw_hn);
    
    adxf_ldptnw_hn = NULL;
    
    adxf_ldptnw_ptid = -1;
    
    adxf_flno = 0;
}

// 100% matching!
void adxf_CloseSjStm(ADXF adxf)
{
    if ((adxf->sj != NULL) && (adxf->sjflag == 0)) 
    {
        if (adxf_ocbi_fg == 1) 
        {
            ADXF_Ocbi(adxf->buf, adxf->bsize);
        }
        
        adxf->sj->vtbl->Destroy(adxf->sj);
        
        adxf->sj = NULL;
    }
}

// 100% matching!
ADXF adxf_CreateAdxFs(void) 
{
    ADXF adxf;

    adxf = adxf_AllocAdxFs();
    
    if (adxf == NULL)
    {
        return adxf;
    }
    
    adxf->rqrdsct = ADXF_DEF_REQ_RD_SCT;
    
    adxf->stat = ADXF_STAT_STOP;
    
    adxf->used = TRUE;
    
    adxf->stm = NULL;
    
    adxf->rdstpos = 0;
    
    adxf->rqsct = 0;
    adxf->rdsct = 0;
    
    adxf->sjflag = 0;
    
    adxf->sj = NULL;
    
    return adxf;
}

// 100% matching!
void adxf_ExecOne(ADXF adxf) 
{
    Sint32 nsct;
    
    if (adxf->stat == ADXF_STAT_READING)
    {
        adxf->stat = ADXSTM_GetStat(adxf->stm);
        
        ADXSTM_GetCurOfst(adxf->stm, &nsct);
        
        adxf->rdsct = nsct;
        
        if ((adxf->stat == ADXF_STAT_READEND) || (adxf->stat == ADXF_STAT_ERROR)) 
        {
            adxf->skpos += nsct;
        
            adxf_CloseSjStm(adxf);
        }
    }
}

// 100% matching!
void ADXF_ExecServer(void)
{
    Sint32 i;
    
    ADXCRS_Lock();

    for (i = 0; i < ADXF_OBJ_MAX; i++)
    {
        if (adxf_obj[i].used == TRUE)
        {
            adxf_ExecOne(&adxf_obj[i]);
        }
    }

    ADXCRS_Unlock();
}

// 100% matching!
Sint32 ADXF_GetFnameRange(Sint32 ptid, Sint32 flid, Char8 *fname, Sint32 *ofst, Sint32 *fnsct)
{
    Sint32 ret;
    ADXF_PTINFO *ptinfo;
    Sint32 i;
    Sint32 ofst2;
    Uint16 *fnsct2;
    ADXF_FINFO *finfo;
    ADXF_FINFO *finfo2;
    
    ret = adxf_ChkPrmGfr(ptid, flid);
    
    if (ret < 0)
    {
        *ofst = -1;
        *fnsct = -1;
        
        return ret;
    }

    for (ptinfo = adxf_ptinfo[ptid]; ptinfo->next != NULL; ptinfo = ptinfo->next) 
    {
        finfo = ptinfo->finfo;

        for (i = 0; i < ptinfo->nentry; i++) 
        {
            finfo2 = &finfo[i];
            
            if (finfo2->flid == flid) 
            {
                strncpy(fname, ptinfo->fname, ADXF_FNAME_MAX);
                
                *ofst = finfo2->ofst;
                *fnsct = finfo2->fnsct;
                
                return ret;
            }
        }
    }

    ofst2 = ptinfo->finfo->flid;
    fnsct2 = &ptinfo->finfo->fnsct;

    for (i = 0; i < flid; i++) 
    {
        ofst2 += fnsct2[i];
    }

    strncpy(fname, ptinfo->fname, ADXF_FNAME_MAX);
    
    *ofst = ofst2;
    *fnsct = fnsct2[flid];
    
    return ret;
}

// 100% matching!
Sint32 ADXF_GetFnameRangeEx(Sint32 ptid, Sint32 flid, Char8 *fname, void **dir, Sint32 *ofst, Sint32 *fnsct)
{
    Sint32 ret;
    ADXF_PTINFO *ptinfo;
    Sint32 i;
    Sint32 ofst2;
    Uint16 *fnsct2;
    ADXF_FINFO *finfo;
    ADXF_FINFO *finfo2;
    
    ret = adxf_ChkPrmGfr(ptid, flid);
    
    if (ret < 0)
    {
        *dir = 0;
        
        *ofst = -1;
        *fnsct = -1;
        
        return ret;
    }

    for (ptinfo = adxf_ptinfo[ptid]; ptinfo->next != NULL; ptinfo = ptinfo->next) 
    {
        finfo = ptinfo->finfo;

        for (i = 0; i < ptinfo->nentry; i++) 
        {
            finfo2 = &finfo[i];
            
            if (finfo2->flid == flid) 
            {
                strncpy(fname, ptinfo->fname, ADXF_FNAME_MAX);
                
                *dir = ptinfo->curdir;
                
                *ofst = finfo2->ofst;
                *fnsct = finfo2->fnsct;
                
                return ret;
            }
        }
    }

    ofst2 = ptinfo->finfo->flid;
    fnsct2 = &ptinfo->finfo->fnsct;

    for (i = 0; i < flid; i++) 
    {
        ofst2 += fnsct2[i];
    }

    strncpy(fname, ptinfo->fname, ADXF_FNAME_MAX);
    
    *dir = ptinfo->curdir; 
    
    *ofst = ofst2;
    *fnsct = fnsct2[flid];
    
    return ret;
}

// 100% matching!
Sint32 ADXF_GetFsizeByte(ADXF adxf)
{
    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040829:'adxf' is NULL.(ADXF_GetFsizeByte)");
        
        return ADXF_ERR_PRM;
    }
    
    return adxf->fsize;
}

// 100% matching!
Sint32 ADXF_GetFsizeSct(ADXF adxf)
{
    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040828:'adxf' is NULL.(ADXF_GetFsizeSct)");
        
        return ADXF_ERR_PRM;
    }
    
    return adxf->fnsct;
}

// 100% matching!
Sint32 ADXF_GetNumReadSct(ADXF adxf)
{
    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040831:'adxf' is NULL.(ADXF_GetNumReadSct)");
        
        return ADXF_ERR_PRM;
    }
    
    return adxf->rdsct;
}

// 100% matching!
Sint32 ADXF_GetNumReqSct(ADXF adxf, Sint32 *seekpos)
{
    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040830:'adxf' is NULL.(ADXF_GetNumReqSct)");
        
        *seekpos = 0;
        
        return ADXF_ERR_PRM;
    }
    
    *seekpos = adxf->rdstpos;
    
    return adxf->rqsct;
}

// 100% matching!
Sint32 ADXF_GetPtinfoSize(Sint32 ptid)
{
    return adxf_ptinfo[ptid]->size;
}

// 100% matching!
Sint32 ADXF_GetPtStat(Sint32 ptid) 
{
    Sint32 stat;
    Uint16* fnsct;
    Sint32 rdsct;
    ADXF_PTINFO* ptinfo;

    if (ptid != adxf_ldptnw_ptid) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E0041303:illigal parameter 'ptid'.(ADXF_GetPtStat)");
        
        return ADXF_ERR_PRM;
    }
    
    stat = ADXF_GetStat(adxf_ldptnw_hn);
    
    if (stat == ADXF_STAT_READEND)
    {
        ptinfo = adxf_ptinfo[ptid];
        
        fnsct = &ptinfo->finfo->fnsct;
        
        if (ptinfo->nfile == 0) 
        {
            if (memcmp(buf, "AFS", 3) != 0)
            {
                ADXERR_CallErrFunc1((const Sint8*)"E0040701:Illigal format(not AFS).(ADXF_GetPtStat)");
                
                adxf_CloseLdptnwHn();
                
                return ADXF_STAT_ERROR;
            }
            
            if (((Sint32*)buf)[1] > ADXF_FILE_MAX)
            {
                ADXERR_CallErrFunc1((const Sint8*)"E0040702:Illigal number of file.(ADXF_GetPtStat)");
                
                adxf_CloseLdptnwHn();
                
                return ADXF_STAT_ERROR;
            }
            
            ptinfo->nfile = ptinfo->nentry = ((Uint32*)buf)[1];
            
            ptinfo->size = (((Uint32)ptinfo->nfile + 140) >> 1) * 4;
            
            ptinfo->finfo->flid = ((Sint32*)buf)[2] / ADXF_DEF_SCT_SIZE;
            
            rdsct = 3;
        }
        else 
        {
            rdsct = 1;
        }
        
        for ( ; rdsct < ADXF_DEF_REQ_RD_SCT; rdsct += 2)
        {
            fnsct[adxf_flno++] = (((Sint32*)buf)[rdsct] + (ADXF_DEF_SCT_SIZE - 1)) / ADXF_DEF_SCT_SIZE;
            
            if (adxf_flno >= ptinfo->nfile) 
            {
                stat = ADXF_STAT_READEND;
                
                adxf_CloseLdptnwHn();
                break;
            }
        }
        
        if (rdsct < ADXF_DEF_REQ_RD_SCT)
        {
            return stat;
        }
        
        if (ADXF_ReadNw32(adxf_ldptnw_hn, 1, buf) < 0) 
        {
            stat = ADXF_STAT_ERROR;
            
            adxf_CloseLdptnwHn();
        } 
        else 
        {
            stat = adxf_ldptnw_hn->stat;
        }
    }
    
    return stat;
}

// 100% matching!
Sint32 ADXF_GetStat(ADXF adxf)
{
    if (adxf == NULL)
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040832:'adxf' is NULL.(ADXF_GetStat)");
        
        return ADXF_ERR_PRM;
    }
    
    return adxf->stat;
}

// 100% matching!
void adxf_LoadData(ADXF adxf, Sint32 nsct, void *buf) 
{
    while (ADXF_ReadNw32(adxf, nsct, buf) <= 0) 
    {
        cvFsExecServer();
        ADXSTM_ExecServer();
        ADXF_ExecServer();
        
        adxf_wait_1ms();
    }
    
    while (TRUE)
    {
        cvFsExecServer();
        ADXSTM_ExecServer();
        ADXF_ExecServer();
        
        if (ADXF_GetStat(adxf) == ADXF_STAT_READEND) 
        {
            ADXF_GetNumReadSct(adxf);
            break;
        }
        
        adxf_wait_1ms();
    }
}

// ADXF_LoadPartition
// ADXF_LoadPartitionEx

// 100% matching!
Sint32 ADXF_LoadPartitionNw(Sint32 ptid, Char8 *fname, void *dir, void *ptinfo) 
{
    Sint32 rdsct;
    Sint32 errmsg;

    errmsg = adxf_ChkPrmPt(ptid, ptinfo);
    
    if (errmsg >= ADXF_ERR_OK) 
    {
        if (adxf_ldptnw_ptid >= 0) 
        {
            ADXERR_CallErrFunc1((const Sint8*)"E0042401:multi-load partition.(ADXF_LoadPartitionNw)");
            
            return ADXF_ERR_FATAL;
        }
        
        adxf_ldptnw_hn = ADXF_Open(fname, dir);
        
        if (adxf_ldptnw_hn == NULL) 
        {
            ADXERR_CallErrFunc1((const Sint8*)"E9040804:can't open file.(ADXF_LoaddPartitionNw)");
            
            return ADXF_ERR_FATAL;
        }
        
        adxf_ldptnw_ptid = ptid;
        
        adxf_flno = 0;
        
        memset(ptinfo, 0, sizeof(ADXF_PTINFO));
        
        ((ADXF_PTINFO*)ptinfo)->next = 0;
        
        adxf_ptinfo[ptid] = ptinfo;
        
        strncpy(&((ADXF_PTINFO*)ptinfo)->fname, fname, ADXF_FNAME_MAX);
        
        ((ADXF_PTINFO*)ptinfo)->type = 0;
        
        ((ADXF_PTINFO*)ptinfo)->curdir = dir;
        
        wrk32 = buf = (Sint32*)((Sint32)&D_01E272F0 & ADXF_DEF_ALIGN_CALC);
        
        rdsct = ADXF_ReadNw32(adxf_ldptnw_hn, 1, buf);
        
        if (rdsct >= 0) 
        {
            ((ADXF_PTINFO*)ptinfo)->nfile = 0;
            
            errmsg = ADXF_ERR_OK;
        }
        else 
        {
            ADXF_Close(adxf_ldptnw_hn);
            
            return rdsct;
        }
    }
    
    return errmsg;
}

// 100% matching!
ADXF ADXF_Open(Char8 *fname, void *atr)
{
    ADXF adxf;

    adxf_SetCmdHstry(1, 0, (Sint32)fname, (Sint32)atr, -1);
    
    ADXCRS_Lock();
    
    adxf = adxf_CreateAdxFs();
    
    if ((adxf != NULL) && (adxf_SetFileInfoEx((ADXF_ROFS)adxf, fname, atr) < 0)) 
    {
        ADXF_Close(adxf);
        
        adxf = NULL;
    }
    
    ADXCRS_Unlock();
    
    adxf_SetCmdHstry(1, 1, (Sint32)fname, (Sint32)atr, -1);
    
    return adxf;
}

// 100% matching!
ADXF ADXF_OpenAfs(Sint32 ptid, Sint32 flid)
{
    ADXF adxf;

    adxf_SetCmdHstry(2, 0, ptid, flid, -1);
    
    ADXCRS_Lock();
    
    adxf = adxf_CreateAdxFs();
    
    if ((adxf != NULL) && (adxf_SetAfsFileInfo(adxf, ptid, flid) < 0)) 
    {
        ADXF_Close(adxf);
        
        adxf = NULL;
    }
    
    ADXCRS_Unlock();
    
    adxf_SetCmdHstry(2, 1, ptid, flid, -1);
    
    return adxf;
}

// 99.81% matching
Sint32 adxf_read_sj32(ADXF adxf, Sint32 nsct, SJ sj) 
{
    Sint32 rdsct;

    if (ADXSTM_GetStat(adxf->stm) != ADXF_STAT_STOP) 
    {
        ADXSTM_Stop(adxf->stm);
    }
    
    ADXCRS_Lock();
    
    adxf->rdsct = 0;
    
    adxf->rdstpos = adxf->ofst + adxf->skpos;
    
    adxf->rqsct = (nsct < (adxf->fnsct - adxf->skpos)) ? nsct : adxf->fnsct - adxf->skpos;
    
    if (adxf->rqsct == 0)
    {
        rdsct = 0;
        
        adxf->stat = ADXF_STAT_READEND;
    } 
    else 
    {
        ADXSTM_SetRdSct(adxf->stm, adxf->rqsct);
        ADXSTM_SetSj(adxf->stm, sj);
        ADXSTM_SetReqRdSize(adxf->stm, adxf->rqrdsct);
        
        adxf->stat = ADXF_STAT_READING;
        
        ADXSTM_Start(adxf->stm);
        
        rdsct = adxf->rqsct;
    }
    
    ADXCRS_Unlock();
    
    return rdsct;
}

// 100% matching!
Sint32 ADXF_ReadNw(ADXF adxf, Sint32 nsct, void *buf)
{
    if (((Sint32)buf & 0x3F)) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E0120401:'buf' isn't 64byte alignment.(ADXF_ReadNw)");
        
        return ADXF_ERR_PRM;
    }
    
    return ADXF_ReadNw32(adxf, nsct, buf);
}

// 100% matching!
Sint32 ADXF_ReadNw32(ADXF adxf, Sint32 nsct, void *buf)
{
    SJ sj;
    Sint32 rdsct;

    adxf_tcnt[0] = getRcnt0CountShort();
    
    adxf_SetCmdHstry(4, 0, (Sint32)adxf, nsct, (Sint32)buf);
    
    adxf_tcnt[1] = getRcnt0CountShort();
    
    adxf_chkp_tcnt[0] = getRcnt0CountShort();
    
    if (adxf == NULL)
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040816:'adxf' is NULL.(ADXF_ReadNw32)");
        
        return ADXF_ERR_PRM;
    }
    
    adxf_chkp_tcnt[1] = getRcnt0CountShort();
    
    if (nsct < 0)  
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040817:'nsct' is negative.(ADXF_ReadNw32)"); 
        
        return ADXF_ERR_PRM;
    }
    
    adxf_chkp_tcnt[2] = getRcnt0CountShort();
    
    if (buf == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040818:'buf' is NULL.(ADXF_ReadNw32)");
        
        return ADXF_ERR_PRM;
    }
    
    adxf_chkp_tcnt[3] = getRcnt0CountShort();
    adxf_chkp_tcnt[4] = getRcnt0CountShort();
    
    if (adxf->stat != ADXF_STAT_READING) 
    {
        adxf_chkp_tcnt[5] = getRcnt0CountShort(); 
        
        if (adxf->sj != NULL) 
        {
            ADXERR_CallErrFunc1((const Sint8*)"E9040821:'sj' is NULL.(ADXF_ReadNw32)"); 
            
            return ADXF_ERR_FATAL;
        }
        
        adxf_chkp_tcnt[6] = getRcnt0CountShort();
        
        adxf_tcnt[2] = getRcnt0CountShort();
        
        sj = SJRBF_Create(buf, nsct * ADXF_DEF_SCT_SIZE, 0);
        
        if (sj == NULL) 
        {
            return ADXF_ERR_INTERNAL;
        } 
        else 
        {
            adxf->bsize = nsct * ADXF_DEF_SCT_SIZE;
            
            adxf->buf = buf; 
            
            adxf_tcnt[3] = getRcnt0CountShort();
            
            ADXCRS_Lock();
            
            adxf_tcnt[4] = getRcnt0CountShort();
            
            if (adxf_ocbi_fg == 1) 
            {
                ADXF_Ocbi(adxf->buf, adxf->bsize);
            }
            
            adxf_tcnt[5] = getRcnt0CountShort();
            
            rdsct = adxf_read_sj32(adxf, nsct, sj);
            
            if (rdsct <= 0) 
            {
                sj->vtbl->Destroy(sj);
            } 
            else 
            {
                adxf->sj = sj;
            }
            
            adxf_tcnt[6] = getRcnt0CountShort();  
            
            adxf->sjflag = 0;
            
            ADXCRS_Unlock(); 
            
            adxf_SetCmdHstry(4, 1, (Sint32)adxf, nsct, (Sint32)buf); 
            
            adxf_tcnt[7] = getRcnt0CountShort();
            
            return rdsct;
        }
    }
    
    return ADXF_ERR_OK;
}

// 100% matching!
Sint32 ADXF_ReadSj32(ADXF adxf, Sint32 nsct, SJ sj)
{
    Sint32 rdsct;

    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040811:'adxf' is NULL.(ADXF_ReadSj32)");
        
        return ADXF_ERR_PRM;
    }
    
    if (nsct < 0) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040812:'nsct'is negative.(ADXF_ReadSj32)");
        
        return ADXF_ERR_PRM;
    }
    
    if (sj == NULL)
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040813:'sj'is NULL.(ADXF_ReadSj32)");
        
        return ADXF_ERR_PRM;
    }
    
    if (adxf->stat == ADXF_STAT_READING)
    {
        return ADXF_ERR_OK;
    }

    ADXCRS_Lock();
    
    rdsct = adxf_read_sj32(adxf, nsct, sj);
    
    adxf->sjflag = 1;
    
    ADXCRS_Unlock();
    
    return rdsct;
}

// 100% matching!
Sint32 ADXF_Seek(ADXF adxf, Sint32 pos, Sint32 type)
{
    adxf_SetCmdHstry(6, 0, (Sint32)adxf, pos, type);

    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040825:'adxf' is NULL.(ADXF_Seek)");
        
        return ADXF_ERR_PRM;
    }

    if (adxf->stat == ADXF_STAT_READING)
    {
        ADXF_Stop(adxf);
    }

    if (type == 0) 
    {
        adxf->skpos = pos;
    } 
    else if (type == 1) 
    {
        adxf->skpos += pos;
    } 
    else if (type == 2) 
    {
        adxf->skpos = adxf->fnsct + pos;
    } 
    else
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040826:'type' is illigal.(ADXF_Seek)");
        
        return ADXF_ERR_PRM;
    }

    if (adxf->skpos < 0)
    {
        adxf->skpos = 0;
    }
    else if (adxf->fnsct < adxf->skpos)
    {
        adxf->skpos = adxf->fnsct;
    }

    ADXSTM_SetOfst(adxf->stm, adxf->ofst + adxf->skpos);
    
    adxf_SetCmdHstry(6, 1, (Sint32)adxf, pos, type);
    
    return adxf->skpos;
}

// 100% matching!
Sint32 adxf_SetAfsFileInfo(ADXF adxf, Sint32 ptid, Sint32 flid)
{
    Char8 fname[ADXF_FNAME_MAX];
    void *dir;
    Sint32 ofst;
    Sint32 fnsct;

    if (ADXF_GetFnameRangeEx(ptid, flid, fname, (void**)&dir, &ofst, &fnsct) < 0) 
    {
        return ADXF_ERR_PRM;
    }
    
    adxf->ofst = ofst;
    
    adxf->stm = ADXSTM_OpenFileRangeEx((Sint8*)fname, dir, ofst, fnsct, 0);
    
    if (adxf->stm == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E0110902:can't open file.(ADXF_OpenAfs)");
        
        return ADXF_ERR_FATAL;
    }
    
    adxf->fnsct = fnsct;
    
    adxf->fsize = fnsct * ADXF_DEF_SCT_SIZE;
    
    return ADXF_ERR_OK;
}

// 100% matching!
void adxf_SetCmdHstry(Sint32 ncall, Sint32 fg, Sint32 ptid, Sint32 flid, Sint32 type)
{
    ADXF_CMD_HSTRY* cmd_hstry;

    adxf_hstry_no %= ADXF_CMD_HSTRY_MAX;
    
    cmd_hstry = &adxf_cmd_hstry[adxf_hstry_no];
   
    if (fg == 0) 
    {
        adxf_cmd_ncall[ncall]++;
    }
    
    adxf_hstry_no++;
    
    cmd_hstry->cmdid = ncall;
    
    cmd_hstry->fg = fg;
    
    cmd_hstry->ncall = adxf_cmd_ncall[ncall];
    
    cmd_hstry->prm[0] = ptid;
    cmd_hstry->prm[1] = flid;
    cmd_hstry->prm[2] = type;
}

// 100% matching!
Sint32 adxf_SetFileInfoEx(ADXF_ROFS rofs, Char8* fname, void* atr) 
{
    Sint32 fid;
    Sint32 fsize;
    Char8 dirname[24]; 

    if (fname == NULL)
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9081901:illigal parameter fname=null.(ADXF_Open)");
        
        return ADXF_ERR_FATAL;
    }
    
    dirname[0] = '\0';
    
    fid = (Sint32)ADXSTM_OpenFnameEx((Sint8*)fname, atr, 0);
    
    if (fid == 0)
    {
        ADXERR_CallErrFunc1((const Sint8*)"E0110901:can't open file.(ADXF_Open)");
        
        return ADXF_ERR_FATAL;
    }
    
    rofs->fid = fid;
    
    fsize = ADXSTM_GetFileLen((void*)fid);

    rofs->ofs = (fsize + (ADXF_DEF_SCT_SIZE - 1)) / ADXF_DEF_SCT_SIZE; 

    rofs->fsize = fsize;
    
    return ADXF_ERR_OK;
}

// 100% matching!
void ADXF_SetOcbiSw(Sint32 fg) 
{
    adxf_ocbi_fg = fg;
}

// 100% matching!
void ADXF_SetReqRdSct(ADXF adxf, Sint32 nsct)
{
    if (adxf->stat == ADXF_STAT_READING) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E0041201:state is reading(ADXF_SetReqRdSct)");
    }
    else 
    {
        adxf->rqrdsct = nsct;
    }
}

// 100% matching!
Sint32 ADXF_Stop(ADXF adxf)
{
    Sint32 nsct;
    
    adxf_SetCmdHstry(5, 0, (Sint32)adxf, -1, -1);
    
    if (adxf == NULL)
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040822:'adxf' is NULL.(ADXF_Stop)");
        
        return ADXF_ERR_PRM;
    } 
    else 
    {
        switch (adxf->stat) 
        {                         
        case ADXF_STAT_READEND:
            adxf->stat = ADXF_STAT_STOP;
        case ADXF_STAT_STOP:
            return adxf->skpos;
        default:
            if (adxf->stm == NULL) 
            {
                ADXERR_CallErrFunc1((const Sint8*)"E9040823:'adxf->stm' is NULL.(ADXF_Stop)");
                
                return ADXF_ERR_FATAL;
            }
            
            ADXCRS_Lock();
            
            ADXSTM_Stop(adxf->stm);
            
            ADXSTM_GetCurOfst(adxf->stm, &nsct);
            
            adxf->rdsct = nsct;
            
            adxf_CloseSjStm(adxf);
            
            adxf->stat = ADXF_STAT_STOP;
            
            ADXCRS_Unlock();
            
            adxf_SetCmdHstry(5, 1, (Sint32)adxf, -1, -1);
            
            return adxf->skpos;
        }
    }
}

// 100% matching!
void ADXF_StopPtLd(void)
{
    if ((adxf_ldptnw_hn != NULL) && (adxf_ldptnw_ptid >= 0)) 
    {
        if (ADXF_GetStat(adxf_ldptnw_hn) != ADXF_STAT_STOP) 
        {
            ADXF_Stop(adxf_ldptnw_hn);
        }
        
        adxf_CloseLdptnwHn();
    }
}

// 100% matching!
Sint32 ADXF_Tell(ADXF adxf)
{
    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"E9040827:'adxf' is NULL.(ADXF_Tell)");
        
        return ADXF_ERR_PRM;
    }
    
    return adxf->skpos;
}

// 100% matching!
void adxf_wait_1ms(void) 
{
    Sint32 i;

    for (i = 0; i < 50000; i++);
}
