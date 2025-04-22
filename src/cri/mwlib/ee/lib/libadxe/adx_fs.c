typedef	ADX_FS ADXF_OBJ;

ADXF_OBJ adxf_obj[ADXF_OBJ_MAX];
ADXF_PTINFO *adxf_ptinfo[ADXF_PART_MAX];
ADXF_CMD_HSTRY adxf_cmd_hstry[1];
Sint16 adxf_cmd_ncall[1];
Sint32 adxf_hstry_no;
Sint32 adxf_ocbi_fg;
Sint32 adxf_flno;
ADXF adxf_ldptnw_hn;
Sint32 adxf_ldptnw_ptid;

void adxf_SetCmdHstry(Sint32 ncall, Sint32 fg, Sint32 ptid, Sint32 flid, Sint32 type);

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
        ADXERR_CallErrFunc1("E9040828:'ptid' is range outside.");
        
        return ADXF_ERR_PRM;
    }
    
    ptinfo = adxf_ptinfo[ptid];
    
    if (ptinfo == NULL) 
    {
        ADXERR_CallErrFunc1("E9040828:'ptid' is range outside.");
        
        return ADXF_ERR_PRM;
    }
    
    if ((flid < 0) || (flid >= ptinfo->nfile))
    {
        ADXERR_CallErrFunc1("E9040828:'flid' is range outside.");
        
        return ADXF_ERR_PRM;
    } 
    
    return ADXF_ERR_OK;
}

// 100% matching!
Sint32 adxf_ChkPrmPt(Uint32 ptid, ADXF_PTINFO* ptinfo) 
{
    if (ptid >= ADXF_PART_MAX) 
    {
        ADXERR_CallErrFunc1("E9040801:'ptid' is range outside.(adxf_ChkPrmPt)");
        
        return ADXF_ERR_PRM;
    }
    
    if (ptinfo == NULL)
    {
        ADXERR_CallErrFunc1("E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)");
        
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

// ADXF_CloseAll

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

// ADXF_ExecServer
// ADXF_GetFnameRange

Sint32 ADXF_GetFnameRangeEx(Sint32 ptid, Sint32 flid, Char8 *fname, void **dir, Sint32 *ofst, Sint32 *fnsct)
{
    scePrintf("ADXF_GetFnameRangeEx - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 ADXF_GetFsizeByte(ADXF adxf)
{
    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1("E9040829:'adxf' is NULL.(ADXF_GetFsizeByte)");
        
        return ADXF_ERR_PRM;
    }
    
    return adxf->fsize;
}

// 100% matching!
Sint32 ADXF_GetFsizeSct(ADXF adxf)
{
    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1("E9040828:'adxf' is NULL.(ADXF_GetFsizeSct)");
        
        return ADXF_ERR_PRM;
    }
    
    return adxf->fnsct;
}

// ADXF_GetNumReadSct
// ADXF_GetNumReqSct

// 100% matching!
Sint32 ADXF_GetPtinfoSize(Sint32 ptid)
{
    return adxf_ptinfo[ptid]->size;
}

Sint32 ADXF_GetPtStat(Sint32 ptid)
{
    scePrintf("ADXF_GetPtStat - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 ADXF_GetStat(ADXF adxf)
{
    if (adxf == NULL)
    {
        ADXERR_CallErrFunc1("E9040832:'adxf' is NULL.(ADXF_GetStat)");
        
        return ADXF_ERR_PRM;
    }
    
    return adxf->stat;
}

// adxf_LoadData
// ADXF_LoadPartition
// ADXF_LoadPartitionEx

Sint32 ADXF_LoadPartitionNw(Sint32 ptid, Char8 *fname, void *dir, void *ptinfo)
{
    scePrintf("ADXF_LoadPartitionNw - UNIMPLEMENTED!\n");
}

ADXF ADXF_Open(Char8 *fname, void *atr)
{
    scePrintf("ADXF_Open - UNIMPLEMENTED!\n");
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

Sint32 adxf_read_sj32(ADXF adxf, Sint32 nsct, SJ sj)
{
    scePrintf("adxf_read_sj32 - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 ADXF_ReadNw(ADXF adxf, Sint32 nsct, void *buf)
{
    if (((Sint32)buf & 0x3F)) 
    {
        ADXERR_CallErrFunc1("E0120401:'buf' isn't 64byte alignment.(ADXF_ReadNw)");
        
        return ADXF_ERR_PRM;
    }
    
    return ADXF_ReadNw32(adxf, nsct, buf);
}

Sint32 ADXF_ReadNw32(ADXF adxf, Sint32 nsct, void *buf)
{
    scePrintf("ADXF_ReadNw32 - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 ADXF_ReadSj32(ADXF adxf, Sint32 nsct, SJ sj)
{
    Sint32 rdsct;

    if (adxf == NULL) 
    {
        ADXERR_CallErrFunc1("E9040811:'adxf' is NULL.(ADXF_ReadSj32)");
        
        return ADXF_ERR_PRM;
    }
    
    if (nsct < 0) 
    {
        ADXERR_CallErrFunc1("E9040812:'nsct'is negative.(ADXF_ReadSj32)");
        
        return ADXF_ERR_PRM;
    }
    
    if (sj == NULL)
    {
        ADXERR_CallErrFunc1("E9040813:'sj'is NULL.(ADXF_ReadSj32)");
        
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
        ADXERR_CallErrFunc1("E9040825:'adxf' is NULL.(ADXF_Seek)");
        
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
        ADXERR_CallErrFunc1("E9040826:'type' is illigal.(ADXF_Seek)");
        
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
    Char8 fname[256];
    void *dir;
    Sint32 ofst;
    Sint32 fnsct;

    if (ADXF_GetFnameRangeEx(ptid, flid, fname, (void**)&dir, &ofst, &fnsct) < 0) 
    {
        return ADXF_ERR_PRM;
    }
    
    adxf->ofst = ofst;
    
    adxf->stm = ADXSTM_OpenFileRangeEx(fname, dir, ofst, fnsct, 0);
    
    if (adxf->stm == NULL) 
    {
        ADXERR_CallErrFunc1("E0110902:can't open file.(ADXF_OpenAfs)");
        
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

    adxf_hstry_no %= 256;
    
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
Sint32 adxf_SetFileInfoEx(ADXF_ROFS rofs, Char8* fname, Sint32 arg2) 
{
    Sint32 fid;
    Sint32 fsize;
    Char8 dirname[24]; 

    if (fname == NULL)
    {
        ADXERR_CallErrFunc1("E9081901:illigal parameter fname=null.(ADXF_Open)");
        
        return ADXF_ERR_FATAL;
    }
    
    dirname[0] = '\0';
    
    fid = ADXSTM_OpenFnameEx(fname, arg2, 0);
    
    if (fid == 0)
    {
        ADXERR_CallErrFunc1("E0110901:can't open file.(ADXF_Open)");
        
        return ADXF_ERR_FATAL;
    }
    
    rofs->fid = fid;
    
    fsize = ADXSTM_GetFileLen(fid);

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
        ADXERR_CallErrFunc1("E0041201:state is reading(ADXF_SetReqRdSct)");
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
        ADXERR_CallErrFunc1("E9040822:'adxf' is NULL.(ADXF_Stop)");
        
        return ADXF_ERR_PRM;
    } 
    else 
    {
        switch (adxf->stat) 
        {                         
        case 3:
            adxf->stat = ADXF_STAT_STOP;
        case 1:
            return adxf->skpos;
        default:
            if (adxf->stm == NULL) 
            {
                ADXERR_CallErrFunc1("E9040823:'adxf->stm' is NULL.(ADXF_Stop)");
                
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
        ADXERR_CallErrFunc1("E9040827:'adxf' is NULL.(ADXF_Tell)");
        
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
