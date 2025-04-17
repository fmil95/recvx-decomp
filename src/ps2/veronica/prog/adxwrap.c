char last_rdx_files[256];
char last_adx_files[256];
char last_file_id;
char adx_status;
int RDX_SIZE;
unsigned int RDX_CHECK_SAM;
int RDX_TOP;
unsigned int READ_RDX_NO;
char cf_area[5628];
ADXT_SPRM cf_prm = { "\\cf_rom.txt", cf_area, 5092, 0, 0, 0, 0 };
short AdxVolTbl[128] = { 0, -2, -4, -6, -8, -10, -12, -14, -16, -18, -20, -22, -24, -26, -28, -30, -32, -34, -36, -38, -40, -42, -44, -46, -48, -50, -52, -54, -56, -58, -60, -62, -64, -70, -76, -82, -88, -94, -100, -106, -112, -118, -124, -130, -136, -142, -148, -154, -160, -166, -172, -178, -184, -190, -196, -202, -208, -214, -220, -226, -232, -238, -244, -250, -256, -264, -272, -280, -288, -296, -304, -312, -320, -328, -336, -344, -352, -360, -368, -376, -384, -392, -400, -408, -416, -424, -432, -440, -448, -456, -464, -472, -480, -488, -496, -504, -512, -528, -544, -560, -576, -592, -608, -624, -640, -656, -672, -688, -704, -720, -736, -752, -768, -784, -800, -816, -832, -848, -864, -880, -896, -912, -928, -944, -960, -976, -992, -999 };
int AdxStreamSleepFlag;
int MaxAdxStreamCnt;
ADXT_INFO AdxTInfo[4];
ADXF_INFO AdxFInfo[8];
AFS_INFO AfsInfo[16];
unsigned char RDX_FILE_PARTISION[880];
int rdx_image_data_max = 205;
char* rdx_files[205];
int ADX_STREAM_BUFF_OFFSET[2] = { 0, 307456 }; 
char ADX_STREAM_BUFFER[471040];

void InitAdx();
void ExitAdx();
void DeletePartition(unsigned int PartitionId);
int CreatePartitionEx(AFS_PATINFO* ap);
void DeletePartitionEx(AFS_PATINFO* ap);
int SearchAdxFSlot();
int OpenAfsInsideFile(unsigned int PartitionId, unsigned int FileId);
int OpenAfsIsoFile(char* FileName);
int GetAfsInsideFileSize(int SlotNo);
void RequestReadAfsInsideFile(int SlotNo, unsigned char* Address);
int CheckReadEndAfsInsideFile(int SlotNo);
void CloseAfsInsideFile(int SlotNo);
void StopAfsInsideFile(int SlotNo);
void RegistAdxStreamEx(int MaxStream, int DummyStream, ADX_WORK* pAdx);
void FreeAdxStream();
void SleepAdxStream();
void WakeupAdxStream(ADX_WORK* pAdx);
void PlayAdxEx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId, int Flag);
void PlayAdx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId);
void StopAdx(unsigned int SlotNo);
void PauseAdx(unsigned int SlotNo);
void ContinueAdx(unsigned int SlotNo);
int GetAdxStatus(unsigned int SlotNo);
void SetVolumeAdx(unsigned int SlotNo, int Volume);
void SetVolumeAdxEx(unsigned int SlotNo, float Volume, float MaxVolume);
void SetVolumeAdx2(unsigned int SlotNo, float Volume);
void SetPanAdx2(unsigned int SlotNo, int Channel, float Pan); // second parameter is not present on the debugging symbols
void SetPanAdx(unsigned int SlotNo, int Channel, int Pan);
int GetAdxPlayTime(unsigned int SlotNo);
void RequestAdxFadeFunction2(int SlotNo, int Func, int Timer, int FirstVolume);
void RequestAdxFadeFunction(int SlotNo, int Func, int Timer);
void RequestAdxFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame);
int ExecAdxFadeManager();

// 100% matching!
void InitAdx()
{
    unsigned int i;
    
    printf("Setup host file system.\n");
    
    ADXT_SetupHostFs(&cf_prm);
    ADXT_SetupDvdFs(&cf_prm);
    
    ADXPS2_SetupThrd(NULL);
    
    ADXT_Init();
    
    ADXT_SetNumRetry(-1);
    
    for (i = 0; i < 16; i++)
    {
        AfsInfo[i].Flag = 0;
    }
    
    for (i = 0; i < 8; i++)
    {
        AdxFInfo[i].Flag = 0;
    }
    
    for (i = 0; i < 4; i++) 
    {
        AdxTInfo[i].Volume = 0;
        
        AdxTInfo[i].LimitMaxVol = 0;
        
        AdxTInfo[i].FadeFunc = 0;
        AdxTInfo[i].PanFunc = 0;
        
        AdxTInfo[i].Flag = 0;
    }
    
    MaxAdxStreamCnt = 0;
    
    AdxStreamSleepFlag = 0;
}

// 100% matching! 
void ExitAdx()
{ 
    ADXT_Finish();
}

// 100% matching!
void DeletePartition(unsigned int PartitionId)
{
    if (AfsInfo[PartitionId].Flag != 0)
    {
        syFree(AfsInfo[PartitionId].pInfoPart);
        
        AfsInfo[PartitionId].Flag = 0;
    }
}

// 100% matching!
int CreatePartitionEx(AFS_PATINFO* ap)
{ 
	char chg_AfsFile[256];
    int ret;
    
    while (TRUE) 
    {
        if (ap->AfsFileName != NULL) 
        { 
            sprintf(chg_AfsFile, "%s%s", "\\", ap->AfsFileName); 
           
            if (AfsInfo[ap->PartitionId].Flag == 0) 
            { 
                ADXPS2_Lock();
                
                ADXF_LoadPartitionNw(ap->PartitionId, chg_AfsFile, NULL, ap->pInfoWork); 
                
                ADXPS2_Unlock(); 
                
                while (TRUE) 
                { 
                    ADXPS2_Lock(); 
                    
                    ret = ADXF_GetPtStat(ap->PartitionId); 
                    
                    ADXPS2_Unlock(); 

                    if (ret == ADXF_STAT_READEND)
                    {
                        break; 
                    }

                    if (ret != ADXF_STAT_READING)
                    {
                        printf("adx load partition error! %s\n", chg_AfsFile);
                        break; 
                    }
                    
                    sceGsSyncV(0); 
                } 
                
                AfsInfo[ap->PartitionId].Flag = 1; 
            }

            ap++; 
        } 
        else 
        { 
            break;
        }
    }
    
    ADXPS2_Lock(); 
    
    ADXF_LoadPartitionNw(17, "\\RDX_LNK.AFS", NULL, RDX_FILE_PARTISION); 
    
    ADXPS2_Unlock(); 

    while (TRUE) 
    {
        ADXPS2_Lock(); 
        
        ret = ADXF_GetPtStat(17); 
        
        ADXPS2_Unlock(); 

        if (ret == ADXF_STAT_READEND) 
        { 
            break;
        }

        if (ret != ADXF_STAT_READING) 
        { 
            printf("adx load partition error! %s\n", chg_AfsFile); 
            break; 
        }

        sceGsSyncV(0); 
    } 
    
    return 0; 
} 

// 100% matching!
void DeletePartitionEx(AFS_PATINFO* ap)
{
    for ( ; ; ap++) 
    {
        if (ap->AfsFileName == NULL)
        {
            break;
        }
        
        AfsInfo[ap->PartitionId].Flag = 0; 
    } 
} 

// 100% matching!
int SearchAdxFSlot() 
{
    unsigned int i;
    
    for (i = 0; i < 8; i++) 
    { 
        if (AdxFInfo[i].Flag == 0)
        { 
            return i; 
        }
    } 
    
    return -1; 
} 

// 100% matching!
int OpenAfsInsideFile(unsigned int PartitionId, unsigned int FileId)
{
    unsigned int SlotNo; 
    
    SlotNo = SearchAdxFSlot();
    
    ADXPS2_Lock();
    
    AdxFInfo[SlotNo].Handle = ADXF_OpenAfs(PartitionId, FileId);
    
    ADXPS2_Unlock();
    
    if (AdxFInfo[SlotNo].Handle == NULL) 
    {
        return -1;
    }
    
    AdxFInfo[SlotNo].Mode = -1;
    
    AdxFInfo[SlotNo].Flag = 1;
    
    return SlotNo;
}

// 100% matching!
int OpenAfsIsoFile(char* FileName)
{
    unsigned int SlotNo;  
    char chg_FileName[256]; 
    int i;                
    
    SlotNo = SearchAdxFSlot();
    
    if ((FileName[strlen(FileName) - 4] == '.') && (FileName[strlen(FileName) - 3] == 'r') && (FileName[strlen(FileName) - 2] == 'd') && (FileName[strlen(FileName) - 1] == 'x')) 
    {
        for (i = 0; (unsigned int)i < strlen(FileName); i++) 
        {
            if ((FileName[i] >= 'a') && (FileName[i] <= 'z')) 
            {
                chg_FileName[i] = FileName[i] - ' ';
            } 
            else 
            {
                chg_FileName[i] = FileName[i];
            }
        } 
        
        chg_FileName[i] = 0;
        
        for (i = 0; i < rdx_image_data_max; i++) 
        {
            if (strcmp(chg_FileName, rdx_files[i]) == 0) 
            {
                break;
            }
        }
        
        if (i == rdx_image_data_max) 
        {
            printf("error!\n");
            printf("not found %s file\n", chg_FileName);
            
            while (TRUE);
        }
        
        printf("read file = %s\n", chg_FileName);
        
        ADXPS2_Lock();
        
        AdxFInfo[SlotNo].Handle = ADXF_OpenAfs(17, i);
        
        ADXPS2_Unlock();
        
        if (AdxFInfo[SlotNo].Handle == NULL) 
        {
            return -1;
        }
        
        AdxFInfo[SlotNo].Mode = -1;
        
        AdxFInfo[SlotNo].Flag = 1;
        
        return SlotNo;
    }
    
    sprintf(chg_FileName, "%s%s", "\\", FileName);
    
    ADXPS2_Lock();
    
    AdxFInfo[SlotNo].Handle = ADXF_Open(chg_FileName, NULL);
    
    ADXPS2_Unlock();
    
    if (AdxFInfo[SlotNo].Handle == NULL) 
    {
        return -1;
    }
    
    AdxFInfo[SlotNo].Mode = -1;
    
    AdxFInfo[SlotNo].Flag = 1;
    
    return SlotNo;
}

// 100% matching!
int GetAfsInsideFileSize(int SlotNo)
{
    if (AdxFInfo[SlotNo].Flag != 0) 
    {
        return ADXF_GetFsizeByte(AdxFInfo[SlotNo].Handle);
    }
    
    return 0;
}

// 100% matching!
void RequestReadAfsInsideFile(int SlotNo, unsigned char* Address)
{
    if (AdxFInfo[SlotNo].Flag != 0) 
    {
        FlushCache(0);
        
        ADXPS2_Lock();
        
        ADXF_ReadNw32(AdxFInfo[SlotNo].Handle, ADXF_GetFsizeSct(AdxFInfo[SlotNo].Handle), Address);
        
        ADXPS2_Unlock();
        
        AdxFInfo[SlotNo].Mode = 0;
    }
}

// 100% matching!
int CheckReadEndAfsInsideFile(int SlotNo)
{
    if ((AdxFInfo[SlotNo].Flag != 0) && (ADXF_GetStat(AdxFInfo[SlotNo].Handle) == 3)) 
    {
        if (AdxFInfo[SlotNo].Mode == 0) 
        {
            CloseAfsInsideFile(SlotNo);
        }
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
void CloseAfsInsideFile(int SlotNo)
{
    if (AdxFInfo[SlotNo].Flag != 0)
    {
        ADXPS2_Lock();
        
        ADXF_Close(AdxFInfo[SlotNo].Handle);
        
        ADXPS2_Unlock();
        
        AdxFInfo[SlotNo].Flag = 0;
    }
}

// 100% matching! 
void StopAfsInsideFile(int SlotNo) 
{
    if (AdxFInfo[SlotNo].Flag != 0) 
    {
        ADXPS2_Lock();
        
        ADXF_Stop(AdxFInfo[SlotNo].Handle);
        
        ADXPS2_Unlock();
        
        CloseAfsInsideFile(SlotNo);
    }
}

// 100% matching! 
void RegistAdxStreamEx(int MaxStream, int DummyStream, ADX_WORK* pAdx)
{
    int i;
    ADXT_INFO* tp;

    if (DummyStream < 0)
    {
        DummyStream = MaxStream;
    }

    memset(ADX_STREAM_BUFFER, 0, sizeof(ADX_STREAM_BUFFER));

    for (i = 0; i < MaxStream; i++, pAdx++)
    {
        AdxTInfo[i].WorkSize = ADXT_CALC_WORK(pAdx->MaxChannel, 1, DummyStream, pAdx->MaxSampleRate);
        
        AdxTInfo[i].pAdxTWork = (unsigned char*)&ADX_STREAM_BUFFER[ADX_STREAM_BUFF_OFFSET[i]];

        ADXPS2_Lock();

        AdxTInfo[i].Handle = ADXT_Create(pAdx->MaxChannel, AdxTInfo[i].pAdxTWork, AdxTInfo[i].WorkSize);

        ADXPS2_Unlock();

        if (pAdx->RecoverType != -1)
        {
            ADXT_SetAutoRcvr(AdxTInfo[i].Handle, pAdx->RecoverType);
        }

        if (pAdx->ReloadSector >= 0)
        {
            ADXT_SetReloadSct(AdxTInfo[i].Handle, pAdx->ReloadSector);
        }

        AdxTInfo[i].FadeFunc = 0;
        
        AdxTInfo[i].Flag = 0;
    }

    MaxAdxStreamCnt = MaxStream;
    
    AdxStreamSleepFlag = 0;
}

// 100% matching!
void FreeAdxStream()
{
    int i;
    
    for (i = MaxAdxStreamCnt - 1; i >= 0; i--) 
    {
        if (AdxStreamSleepFlag == 0) 
        {
            ADXT_SetOutVol(AdxTInfo[i].Handle, -999);
            
            ADXPS2_Lock();
            
            ADXT_Stop(AdxTInfo[i].Handle);
            
            ADXPS2_Unlock();
            
            ADXPS2_Lock();
            
            ADXT_Destroy(AdxTInfo[i].Handle);
            
            ADXPS2_Unlock();
        }
        
        syFree(AdxTInfo[i].pAdxTWork);
    } 
    
    MaxAdxStreamCnt = 0;
}

// 100% matching!
void SleepAdxStream()
{
    int i;
    
    if (AdxStreamSleepFlag == 0) 
    {
        for (i = 0; i < MaxAdxStreamCnt; i++) 
        {
            ADXPS2_Lock();
            
            ADXT_SetOutVol(AdxTInfo[i].Handle, -999);
            
            ADXPS2_Unlock();
            
            ADXPS2_Lock();
            
            ADXT_Stop(AdxTInfo[i].Handle);
            
            ADXPS2_Unlock();
            
            ADXPS2_Lock();
            
            ADXT_Destroy(AdxTInfo[i].Handle);
            
            ADXPS2_Unlock();
        }
        
        AdxStreamSleepFlag = 1;
    }
}

// 100% matching! 
void WakeupAdxStream(ADX_WORK* pAdx)
{
    int i;
    ADXT_INFO* tp;

    if (AdxStreamSleepFlag != 0) 
    {
        for (i = 0; i < MaxAdxStreamCnt; i++, pAdx++) 
        {
            ADXPS2_Lock();
            
            AdxTInfo[i].Handle = ADXT_Create(pAdx->MaxChannel, AdxTInfo[i].pAdxTWork, AdxTInfo[i].WorkSize);
            
            ADXPS2_Unlock();
            
            if (pAdx->RecoverType != -1) 
            {
                ADXT_SetAutoRcvr(AdxTInfo[i].Handle, pAdx->RecoverType);
            }
            
            if (pAdx->ReloadSector >= 0) 
            {
                ADXT_SetReloadSct(AdxTInfo[i].Handle, pAdx->ReloadSector);
            }
            
            AdxTInfo[i].FadeFunc = 0;
            
            AdxTInfo[i].Flag = 0;
        }
        
        AdxStreamSleepFlag = 0;
    }
}

// 100% matching! 
void PlayAdxEx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId, int Flag)
{
    if (Flag != 0)
    {
        PauseAdx(SlotNo);
    }
    
    ADXPS2_Lock();
    
    ADXT_SetSvrFreq(AdxTInfo[SlotNo].Handle, 12);
    
    ADXT_StartAfs(AdxTInfo[SlotNo].Handle, PartitionId, FileId);
    
    ADXPS2_Unlock();
    
    AdxTInfo[SlotNo].Flag = 1;
}

// 100% matching!
void PlayAdx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId)
{ 
    PlayAdxEx(SlotNo, PartitionId, FileId, 0);
}

// 100% matching!
void StopAdx(unsigned int SlotNo)
{
    if (AdxTInfo[SlotNo].Flag != 0) 
    {
        ADXPS2_Lock();
        
        ADXT_Stop(AdxTInfo[SlotNo].Handle);
        
        ADXPS2_Unlock();
    }
    
    AdxTInfo[SlotNo].Flag = 0;
}

// 100% matching!
void PauseAdx(unsigned int SlotNo)
{
    ADXPS2_Lock();
    
    ADXT_Pause(AdxTInfo[SlotNo].Handle, 1);
    
    ADXPS2_Unlock();
}

// 100% matching!
void ContinueAdx(unsigned int SlotNo)
{
    ADXPS2_Lock();
    
    ADXT_Pause(AdxTInfo[SlotNo].Handle, 0);
    
    ADXPS2_Unlock();
}

// 100% matching!
int GetAdxStatus(unsigned int SlotNo)
{
    ADXT_GetStat(AdxTInfo[SlotNo].Handle);
}

// 100% matching!
void SetVolumeAdx(unsigned int SlotNo, int Volume)
{
    SetVolumeAdx2(SlotNo, Volume);
}

// 100% matching!
void SetVolumeAdxEx(unsigned int SlotNo, float Volume, float MaxVolume)
{
    if (MaxVolume < -20.0f) 
    {
        MaxVolume += 20.0f;
    }
    else 
    {
        MaxVolume = 0;
    }

    AdxTInfo[SlotNo].LimitMaxVol = MaxVolume;
    
    SetVolumeAdx2(SlotNo, Volume);
}

// 100% matching!
void SetVolumeAdx2(unsigned int SlotNo, float Volume)
{
    if (AdxTInfo[SlotNo].Handle->used != 0) 
    {
        ADXPS2_Lock();
        
        ADXT_SetOutVol(AdxTInfo[SlotNo].Handle, AdxVolTbl[(int)-Volume]);
        
        ADXPS2_Unlock();
    }
    
    AdxTInfo[SlotNo].Volume = Volume;
}

// 100% matching!
void SetPanAdx2(unsigned int SlotNo, int Channel, float Pan) 
{
    AdxTInfo[SlotNo].Pan = Pan;
}

// 100% matching!
void SetPanAdx(unsigned int SlotNo, int Channel, int Pan) 
{ 
    SetPanAdx2(SlotNo, Channel, Pan);
}

// 100% matching!
int GetAdxPlayTime(unsigned int SlotNo)
{
    int SampleCount;
    int SamplingRate;
    
    ADXPS2_Lock();
    
    ADXT_GetTime(AdxTInfo[SlotNo].Handle, &SampleCount, &SamplingRate);
    
    ADXPS2_Unlock();
    
    return ((double)SampleCount / SamplingRate) * 100.0f;
}

// 100% matching!
void RequestAdxFadeFunction2(int SlotNo, int Func, int Timer, int FirstVolume)
{
    float Cnt; 
    ADXT_INFO* tp; 
    
    tp = &AdxTInfo[SlotNo];
    
    tp->FadeCntMax = ((Timer / 100) * 30) + (((Timer % 100) * 6) / 10);
    
    tp->FadeCntMax /= 2;
    
    if (tp->FadeCntMax == 0) 
    {
        tp->FadeCntMax = 1;
    }
    
    if (FirstVolume != 1) 
    {
        tp->Volume = FirstVolume;
    }
    
    switch (Func) 
    {                               
    case 1:
        tp->VolLast = tp->LimitMaxVol;
        break;
    case 2:
        tp->VolLast = -127.0f;
        break;
    }
    
    Cnt = tp->Volume - tp->VolLast;
    
    if (tp->FadeCntMax != 0) 
    {
        tp->VolSpeed = Cnt / tp->FadeCntMax;
    }
    else
    {
        tp->VolSpeed = 0;
    }
    
    tp->VolSave = tp->Volume;
    
    tp->FadeFunc = Func;
}

// 100% matching!
void RequestAdxFadeFunction(int SlotNo, int Func, int Timer)
{ 
    RequestAdxFadeFunction2(SlotNo, Func, Timer, 1);
}

// 98.29% matching
void RequestAdxFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame)
{
    ADXT_INFO* tp; 
    
    tp = &AdxTInfo[SlotNo];
    
    if (StartVol == -1)
    {
        StartVol = tp->Volume;
    }
    
    tp->Volume = StartVol;
    tp->VolLast = LastVol;
    
    tp->FadeCntMax = Frame;
    
    if (Frame != 0) 
    {
        tp->VolSpeed = -((tp->VolLast - tp->Volume) / tp->FadeCntMax);
    }
    
    tp->FadeFunc = 1;
}

// 100% matching!
int ExecAdxFadeManager()
{
    int i;         
    int ReturnCode; 
    ADXT_INFO* tp;  
    
    tp = AdxTInfo;
    
    ReturnCode = 0;
    
    for (i = 0; i < 4; i++)
    {
        if (tp[i].FadeFunc != 0) 
        {
            tp[i].Volume -= tp[i].VolSpeed;
            
            tp[i].FadeCntMax--;
            
            if (tp[i].FadeCntMax < 0) 
            {
                tp[i].Volume = tp[i].VolLast;
                
                if ((int)tp[i].Volume == -127) 
                {
                    StopAdx(i);
                }
                
                tp[i].FadeFunc = 0;
            } 
            else
            {
                ReturnCode = 1;
            }
            
            SetVolumeAdx2(i, tp[i].Volume);
        }
        
        if (tp[i].PanFunc != 0)
        {
            tp[i].Pan -= tp[i].PanSpeed;
            
            tp[i].PanCntMax--;
            
            if (tp[i].PanCntMax < 0) 
            {
                tp[i].Pan = tp[i].PanLast;
                
                tp[i].PanFunc = 0;
            }
            else 
            {
                ReturnCode = 1;
            }
            
            SetPanAdx2(i, 0, tp[i].Pan);
        }
    } 
    
    return ReturnCode;
}
