Sint32 adxf_ocbi_fg;
ADXF adxf_ldptnw_hn;
Sint32 adxf_ldptnw_ptid;

void adxf_SetCmdHstry(Sint32 arg0, Sint32 arg1, Sint32 ptid, Sint32 flid, Sint32 arg4);

// ADXF_AddPartition
// adxf_AllocAdxFs
// adxf_ChkPrmGfr
// adxf_ChkPrmPt

void ADXF_Close(ADXF adxf)
{
    scePrintf("ADXF_Close - UNIMPLEMENTED!\n");
}

// ADXF_CloseAll

void adxf_CloseLdptnwHn()
{
    scePrintf("adxf_CloseLdptnwHn - UNIMPLEMENTED!\n");
}

void adxf_CloseSjStm(ADXF adxf)
{
    scePrintf("adxf_CloseSjStm - UNIMPLEMENTED!\n");
}

ADXF adxf_CreateAdxFs()
{
    scePrintf("adxf_CreateAdxFs - UNIMPLEMENTED!\n");
}

// adxf_ExecOne
// ADXF_ExecServer
// ADXF_GetFnameRange
// ADXF_GetFnameRangeEx

Sint32 ADXF_GetFsizeByte(ADXF adxf)
{
    scePrintf("ADXF_GetFsizeByte - UNIMPLEMENTED!\n");
}

Sint32 ADXF_GetFsizeSct(ADXF adxf)
{
    scePrintf("ADXF_GetFsizeSct - UNIMPLEMENTED!\n");
}

// ADXF_GetNumReadSct
// ADXF_GetNumReqSct
// ADXF_GetPtinfoSize

Sint32 ADXF_GetPtStat(Sint32 ptid)
{
    scePrintf("ADXF_GetPtStat - UNIMPLEMENTED!\n");
}

Sint32 ADXF_GetStat(ADXF adxf)
{
    scePrintf("ADXF_GetStat - UNIMPLEMENTED!\n");
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

// adxf_read_sj32
// ADXF_ReadNw

Sint32 ADXF_ReadNw32(ADXF adxf, Sint32 nsct, void *buf)
{
    scePrintf("ADXF_ReadNw32 - UNIMPLEMENTED!\n");
}

// ADXF_ReadSj32
// ADXF_Seek

Sint32 adxf_SetAfsFileInfo(ADXF adxf, Sint32 ptid, Sint32 flid)
{
    scePrintf("adxf_SetAfsFileInfo - UNIMPLEMENTED!\n");
}

void adxf_SetCmdHstry(Sint32 arg0, Sint32 arg1, Sint32 ptid, Sint32 flid, Sint32 arg4)
{
    scePrintf("adxf_SetCmdHstry - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 adxf_SetFileInfoEx(ADXF_ROFS rofs, Sint32 arg1, Sint32 arg2) 
{
    Sint32 file_id;
    Sint32 file_size;
    Char8 sp[24]; 

    if (arg1 == 0)
    {
        ADXERR_CallErrFunc1("E9081901:illigal parameter fname=null.(ADXF_Open)");
        
        return ADXF_ERR_FATAL;
    }
    
    sp[0] = 0;
    
    file_id = ADXSTM_OpenFnameEx(arg1, arg2, 0);
    
    if (file_id == 0)
    {
        ADXERR_CallErrFunc1("E0110901:can't open file.(ADXF_Open)");
        
        return ADXF_ERR_FATAL;
    }
    
    rofs->fid = file_id;
    
    file_size = ADXSTM_GetFileLen(file_id);

    rofs->ofs = (file_size + (ADXF_DEF_SCT_SIZE - 1)) / ADXF_DEF_SCT_SIZE; 

    rofs->fsize = file_size;
    
    return ADXF_ERR_OK;
}

// 100% matching!
void ADXF_SetOcbiSw(Sint32 arg0) 
{
    adxf_ocbi_fg = arg0;
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
    Sint32 sp;
    
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
            
            ADXSTM_GetCurOfst(adxf->stm, &sp);
            
            adxf->rdsct = sp;
            
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
