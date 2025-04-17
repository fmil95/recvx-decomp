/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _adx_talk;
typedef struct _adxt_sprm;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _UUID;
typedef struct _sj_vtbl;
typedef struct _anon5;
typedef struct _adx_fs;
typedef struct _anon6;

typedef void(*type_0)(_anon1*, int, _anon2*);
typedef void(*type_1)(_anon1*, int, _anon2*);
typedef int(*type_4)(_anon1*, int);
typedef int(*type_6)(_anon1*, int, int, int*);
typedef void(*type_8)(_anon1*, void(*)(void*, int), void*);
typedef void(*type_9)(void*, int);
typedef void(*type_21)();
typedef void(*type_22)();
typedef void(*type_23)();
typedef void(*type_25)(_anon1*);
typedef _UUID*(*type_27)(_anon1*);
typedef void(*type_28)(_anon1*);
typedef void(*type_30)(_anon1*, int, int, _anon2*);

typedef _anon6 type_2[8];
typedef _anon0 type_3[4];
typedef char type_5[256];
typedef short type_7[128];
typedef char type_10[256];
typedef _anon1* type_11[2];
typedef char* type_12[0];
typedef char type_13[471040];
typedef char type_14[5628];
typedef int type_15[2];
typedef char type_16[256];
typedef unsigned char type_17[8];
typedef unsigned char type_18[880];
typedef short type_19[2];
typedef char type_20[256];
typedef _anon1* type_24[2];
typedef _anon1* type_26[2];
typedef char type_29[256];
typedef _anon5 type_31[16];

struct _anon0
{
	_adx_talk* Handle;
	unsigned char* pAdxTWork;
	int WorkSize;
	unsigned int Flag;
	int FadeFunc;
	int FadeCntMax;
	float Volume;
	float VolSpeed;
	float VolLast;
	float VolSave;
	float LimitMaxVol;
	int PanFunc;
	int PanCntMax;
	float Pan;
	float PanSpeed;
	float PanLast;
};

struct _anon1
{
	_sj_vtbl* vtbl;
};

struct _anon2
{
	char* data;
	int len;
};

struct _adx_talk
{
	char used;
	char stat;
	char pmode;
	char maxnch;
	void* sjd;
	void* stm;
	void* rna;
	_anon1* sjf;
	_anon1* sji;
	_anon1* sjo[2];
	char* ibuf;
	int ibuflen;
	int ibufxlen;
	short* obuf;
	int obufsize;
	int obufdist;
	int svrfreq;
	short maxsct;
	short minsct;
	short outvol;
	short outpan[2];
	int maxdecsmpl;
	int lpcnt;
	int lp_skiplen;
	int trp;
	int wpos;
	int mofst;
	short ercode;
	int edecpos;
	short edeccnt;
	short eshrtcnt;
	char lpflg;
	char autorcvr;
	char fltmode;
	char execflag;
	char pstwait_flag;
	char pstready_flag;
	char pause_flag;
	void* amp;
	_anon1* ampsji[2];
	_anon1* ampsjo[2];
	int time_ofst;
	int lesct;
	int trpnsmpl;
	void* lsc;
	char lnkflg;
	char rsv;
	short rsv2;
	unsigned int tvofst;
	unsigned int svcnt;
};

struct _adxt_sprm
{
	char* fname;
	char* fpc;
	int size;
	int nrtry;
	int speed;
	int dtype;
	int opmode;
};

struct _anon3
{
	unsigned int MaxChannel;
	unsigned int MaxSampleRate;
	int RecoverType;
	int ReloadSector;
};

struct _anon4
{
	char* AfsFileName;
	int PartitionId;
	int MaxInsideFileNum;
	unsigned char* pInfoWork;
};

struct _UUID
{
	unsigned int Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char Data4[8];
};

struct _sj_vtbl
{
	void(*QueryInterface)();
	void(*AddRef)();
	void(*Release)();
	void(*Destroy)(_anon1*);
	_UUID*(*GetUuid)(_anon1*);
	void(*Reset)(_anon1*);
	void(*GetChunk)(_anon1*, int, int, _anon2*);
	void(*UngetChunk)(_anon1*, int, _anon2*);
	void(*PutChunk)(_anon1*, int, _anon2*);
	int(*GetNumData)(_anon1*, int);
	int(*IsGetChunk)(_anon1*, int, int, int*);
	void(*EntryErrFunc)(_anon1*, void(*)(void*, int), void*);
};

struct _anon5
{
	unsigned char* pInfoPart;
	unsigned int PartAreaSize;
	unsigned int Flag;
};

struct _adx_fs
{
	char used;
	char stat;
	char sjflag;
	char rev;
	void* stm;
	_anon1* sj;
	int fnsct;
	int fsize;
	int skpos;
	int rdstpos;
	int rqsct;
	int rdsct;
	char* buf;
	int bsize;
	int rqrdsct;
	int ofst;
	char fname[256];
	void* dir;
};

struct _anon6
{
	_adx_fs* Handle;
	unsigned char* pAdxFWork;
	unsigned int Flag;
	int Mode;
};

char last_rdx_files[256];
char last_adx_files[256];
char last_file_id;
char adx_status;
int RDX_SIZE;
unsigned int RDX_CHECK_SAM;
int RDX_TOP;
unsigned int READ_RDX_NO;*/
char cf_area[5628];
ADXT_SPRM cf_prm = {
    "\\cf_rom.txt", cf_area, 5092, 0, 0, 0, 0
};
short AdxVolTbl[128]; // TODO: define the .data for this
int AdxStreamSleepFlag;
int MaxAdxStreamCnt;
ADXT_INFO AdxTInfo[4];
ADXF_INFO AdxFInfo[8];
AFS_INFO AfsInfo[16];
/*unsigned char RDX_FILE_PARTISION[880];*/
int rdx_image_data_max = 205;
char* rdx_files[205];
int ADX_STREAM_BUFF_OFFSET[2] = {
    0,
    307456
}; 
char ADX_STREAM_BUFFER[471040];

/*void InitAdx();
void ExitAdx();
void DeletePartition(unsigned int PartitionId);
int CreatePartitionEx(_anon4* ap);
void DeletePartitionEx(_anon4* ap);
int SearchAdxFSlot();
int OpenAfsInsideFile(unsigned int PartitionId, unsigned int FileId);
int OpenAfsIsoFile(char* FileName);
int GetAfsInsideFileSize(int SlotNo);
void RequestReadAfsInsideFile(int SlotNo, unsigned char* Address);
int CheckReadEndAfsInsideFile(int SlotNo);*/
void CloseAfsInsideFile(int SlotNo);
/*void StopAfsInsideFile(int SlotNo);
void RegistAdxStreamEx(int MaxStream, int DummyStream, _anon3* pAdx);
void FreeAdxStream();
void SleepAdxStream();
void WakeupAdxStream(_anon3* pAdx);
void PlayAdxEx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId, int Flag);
void PlayAdx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId);
void StopAdx(unsigned int SlotNo);*/
void PauseAdx(unsigned int SlotNo);
/*void ContinueAdx(unsigned int SlotNo);
int GetAdxStatus(unsigned int SlotNo);
void SetVolumeAdx(unsigned int SlotNo, int Volume);
void SetVolumeAdxEx(unsigned int SlotNo, float Volume, float MaxVolume);*/
void SetVolumeAdx2(unsigned int SlotNo, float Volume);
/*void SetPanAdx2(unsigned int SlotNo, float Pan);
void SetPanAdx(unsigned int SlotNo, int Channel, int Pan);
int GetAdxPlayTime(unsigned int SlotNo);
void RequestAdxFadeFunction2(int SlotNo, int Func, int Timer, int FirstVolume);
void RequestAdxFadeFunction(int SlotNo, int Func, int Timer);
void RequestAdxFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame);
int ExecAdxFadeManager();*/

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

// 
// Start address: 0x291170
int CreatePartitionEx(AFS_PATINFO* ap)
{
	int ret;
	char chg_AfsFile[256];
	// Line 317, Address: 0x291170, Func Offset: 0
	// Line 322, Address: 0x291184, Func Offset: 0x14
	// Line 328, Address: 0x291190, Func Offset: 0x20
	// Line 329, Address: 0x2911a8, Func Offset: 0x38
	// Line 331, Address: 0x2911d0, Func Offset: 0x60
	// Line 333, Address: 0x2911d8, Func Offset: 0x68
	// Line 335, Address: 0x2911ec, Func Offset: 0x7c
	// Line 337, Address: 0x2911f4, Func Offset: 0x84
	// Line 339, Address: 0x2911f8, Func Offset: 0x88
	// Line 341, Address: 0x291200, Func Offset: 0x90
	// Line 343, Address: 0x291208, Func Offset: 0x98
	// Line 345, Address: 0x291210, Func Offset: 0xa0
	// Line 348, Address: 0x29121c, Func Offset: 0xac
	// Line 349, Address: 0x291228, Func Offset: 0xb8
	// Line 350, Address: 0x291238, Func Offset: 0xc8
	// Line 360, Address: 0x291240, Func Offset: 0xd0
	// Line 361, Address: 0x29124c, Func Offset: 0xdc
	// Line 362, Address: 0x291254, Func Offset: 0xe4
	// Line 382, Address: 0x291278, Func Offset: 0x108
	// Line 383, Address: 0x29127c, Func Offset: 0x10c
	// Line 394, Address: 0x291284, Func Offset: 0x114
	// Line 404, Address: 0x29128c, Func Offset: 0x11c
	// Line 407, Address: 0x2912a8, Func Offset: 0x138
	// Line 412, Address: 0x2912b0, Func Offset: 0x140
	// Line 414, Address: 0x2912b8, Func Offset: 0x148
	// Line 416, Address: 0x2912c0, Func Offset: 0x150
	// Line 418, Address: 0x2912c8, Func Offset: 0x158
	// Line 421, Address: 0x2912d4, Func Offset: 0x164
	// Line 422, Address: 0x2912e0, Func Offset: 0x170
	// Line 423, Address: 0x2912f0, Func Offset: 0x180
	// Line 432, Address: 0x2912f8, Func Offset: 0x188
	// Line 433, Address: 0x291304, Func Offset: 0x194
	// Line 459, Address: 0x29130c, Func Offset: 0x19c
	// Line 458, Address: 0x291318, Func Offset: 0x1a8
	// Line 459, Address: 0x29131c, Func Offset: 0x1ac
	// Func End, Address: 0x291324, Func Offset: 0x1b4
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

// 85.37% matching
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

// 98.24% matching
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

// 84.75% matching
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

// 92.03% matching
void RegistAdxStreamEx(int MaxStream, int DummyStream, ADX_WORK* pAdx)
{
    int i;
    ADXT_INFO* tp;

    if (DummyStream < 0)
    {
        DummyStream = MaxStream;
    }

    memset(ADX_STREAM_BUFFER, 0, sizeof(ADX_STREAM_BUFFER));

    for (i = 0; i < MaxStream; i++)
    {
        AdxTInfo[i].WorkSize = ADXT_CALC_WORK(pAdx[i].MaxChannel, 1, DummyStream, pAdx[i].MaxSampleRate);
        
        AdxTInfo[i].pAdxTWork = (unsigned char*)&ADX_STREAM_BUFFER[ADX_STREAM_BUFF_OFFSET[i]];

        ADXPS2_Lock();

        AdxTInfo[i].Handle = ADXT_Create(pAdx[i].MaxChannel, AdxTInfo[i].pAdxTWork, AdxTInfo[i].WorkSize);

        ADXPS2_Unlock();

        if (pAdx[i].RecoverType != -1)
        {
            ADXT_SetAutoRcvr(AdxTInfo[i].Handle, pAdx[i].RecoverType);
        }

        if (pAdx[i].ReloadSector >= 0)
        {
            ADXT_SetReloadSct(AdxTInfo[i].Handle, pAdx[i].ReloadSector);
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

// 81.42% matching
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

// 84.62% matching
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
void SetPanAdx2(unsigned int SlotNo, int param, float Pan) // second parameter is not present on the debugging symbols
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
    
    ADXT_GetTime(AdxTInfo[SlotNo].Handle, (long*)&SampleCount, (long*)&SamplingRate);
    
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
