/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _UUID;
typedef struct _sj_vtbl;
typedef enum _mwe_ply_stat;
typedef struct _mwply_if;

typedef void(*type_0)(_anon1*, int, int, _anon0*);
typedef void(*type_1)();
typedef void(*type_2)(_anon1*, int, _anon0*);
typedef void(*type_3)();
typedef void(*type_4)();
typedef void(*type_5)(_anon2*);
typedef void(*type_6)(_anon1*, int, _anon0*);
typedef void(*type_7)(_anon2*);
typedef int(*type_9)(_anon1*, int);
typedef void(*type_10)(_anon2*);
typedef void(*type_11)(_anon2*, char*);
typedef int(*type_12)(_anon1*, int, int, int*);
typedef void(*type_13)(_anon2*);
typedef void(*type_14)(_anon1*, void(*)(void*, int), void*);
typedef _mwe_ply_stat(*type_15)(_anon2*);
typedef void(*type_16)(void*, int);
typedef void(*type_17)(_anon2*, int*, int*);
typedef void(*type_18)(_anon2*, int);
typedef void(*type_19)(_anon2*, int);
typedef int(*type_20)(_anon2*);
typedef void(*type_21)(_anon2*, int, int);
typedef int(*type_22)(_anon2*, int);
typedef void(*type_23)(_anon2*, _anon1*);
typedef void(*type_25)(_anon2*, void*, int);
typedef void(*type_26)();
typedef void(*type_27)();
typedef void(*type_28)();
typedef void(*type_29)(_anon1*);
typedef _UUID*(*type_30)(_anon1*);
typedef void(*type_31)(_anon1*);
typedef void(*type_32)();

typedef int type_8[4];
typedef unsigned char type_24[8];

struct _anon0
{
	char* data;
	int len;
};

struct _anon1
{
	_sj_vtbl* vtbl;
};

struct _anon2
{
	_mwply_if* vtbl;
};

struct _anon3
{
	int mode;
	int frame;
	int count;
	int latency;
	int rsv[4];
};

struct _anon4
{
	int ftype;
	int max_bps;
	int max_width;
	int max_height;
	int nfrm_pool_wk;
	char* work;
	int wksize;
	int dtype;
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
	void(*GetChunk)(_anon1*, int, int, _anon0*);
	void(*UngetChunk)(_anon1*, int, _anon0*);
	void(*PutChunk)(_anon1*, int, _anon0*);
	int(*GetNumData)(_anon1*, int);
	int(*IsGetChunk)(_anon1*, int, int, int*);
	void(*EntryErrFunc)(_anon1*, void(*)(void*, int), void*);
};

enum _mwe_ply_stat
{
	MWE_PLY_STAT_STOP,
	MWE_PLY_STAT_PREP,
	MWE_PLY_STAT_PLAYING,
	MWE_PLY_STAT_PLAYEND,
	MWE_PLY_STAT_ERROR
};

struct _mwply_if
{
	void(*QueryInterface)();
	void(*AddRef)();
	void(*Release)();
	void(*VsyncHndl)(_anon2*);
	void(*ExecSvrHndl)(_anon2*);
	void(*Destroy)(_anon2*);
	void(*StartFname)(_anon2*, char*);
	void(*Stop)(_anon2*);
	_mwe_ply_stat(*GetStat)(_anon2*);
	void(*GetTime)(_anon2*, int*, int*);
	void(*Pause)(_anon2*, int);
	void(*SetOutVol)(_anon2*, int);
	int(*GetOutVol)(_anon2*);
	void(*SetOutPan)(_anon2*, int, int);
	int(*GetOutPan)(_anon2*, int);
	void(*StartSj)(_anon2*, _anon1*);
	void(*StartMem)(_anon2*, void*, int);
};*/

int MwMode = -1;
int MwPlayFlag;
MWPLY MwPly;
MWS_PLY_CPRM_SFD MwsCprmSfd;
int MwMemoryMode;
/*int MwPlayMode;

void InitMwSystem(unsigned int Mode, void* pPrm);
void ReinitMwSystem(_anon3* pPrm);
void ExitMwSystem();
void SetMwSoundMode();
void GetMwPlayTime(int* ncount, int* tscale);
int GetMwPlayTimeEx();
void CreateSfdHandle(void* mp, void* pp, char* fname);
void CreateWaveHandle();
void CreateTmHandle();
void PlayMwOpenMain(char* FileName, int Mode, void* mp, void* pp, int PauseFlag);
void PlayMw2(char* FileName, int Mode, void* mp, void* pp, int PauseFlag);
void StopMw();
_mwe_ply_stat GetMwStatus();
int PlayMwMain2(void(*Func)());
int PlayMwMain();
void PauseMw();
void RestartMw();
void SetMwVolume(int Volume);
int GetSfdFadeRate();
void SetSfdDislpaySize(float PosX, float PosY, float SizeX, float SizeY);*/

// 100% matching!
void InitMwSystem(unsigned int Mode, void* pPrm)
{
    switch (Mode)
    {
    case 0:
        mwPlyInitSofdec(pPrm);
        break;
    case 2:
        mwPlyInitSofdec(pPrm);
        break;
    }
    
    MwMode = Mode;
    
    MwPlayFlag = 0;
}

// 100% matching!
void ReinitMwSystem(MWS_PLY_INIT_SFD* pPrm)
{
    switch (MwMode)
    {
    case 0:
    case 2:
        mwPlySetDispMode(pPrm->mode, pPrm->frame, pPrm->count, pPrm->latency);
        break;
    }
}

// 100% matching!
void ExitMwSystem()
{
    switch (MwMode) 
    {                              
    case 0:
        mwPlyFinishSofdec();
        break;
    case 2:
        mwPlyFinishSofdec();
        break;
    }
    
    MwMode = -1;
}

// 100% matching!
void SetMwSoundMode()
{

}

// 100% matching!
void GetMwPlayTime(int* ncount, int* tscale)
{ 
    MwPly->vtbl->GetTime(MwPly, ncount, tscale); 
}

// 100% matching!
int GetMwPlayTimeEx()
{
    int SampleCount;
    int SamplingRate;

    GetMwPlayTime(&SampleCount, &SamplingRate);
    
    return ((double)SampleCount / (double)SamplingRate) * 100; 
} 

// 100% matching!
void CreateSfdHandle(void* mp, void* pp, char* fname)
{ 
    memset(MwsCprmSfd, 0, sizeof(MWS_PLY_CPRM_SFD));
    
    if (pp == NULL) 
    {
        MwsCprmSfd.ftype = 1;
        MwsCprmSfd.dtype = 0;
        
        MwsCprmSfd.max_bps = 3686400;
        
        MwsCprmSfd.max_width = 320;
        MwsCprmSfd.max_height = 240;
        
        MwsCprmSfd.nfrm_pool_wk = 3;
        
        MwsCprmSfd.wksize = mwPlyCalcWorkSofdec(MwsCprmSfd.ftype, MwsCprmSfd.max_bps, MwsCprmSfd.max_width, MwsCprmSfd.max_height, MwsCprmSfd.nfrm_pool_wk);
    }
    else 
    {
        MwsCprmSfd.ftype = ((MWS_PLY_CPRM_SFD*)pp)->ftype;
        MwsCprmSfd.dtype = ((MWS_PLY_CPRM_SFD*)pp)->dtype;
        
        MwsCprmSfd.max_bps = ((MWS_PLY_CPRM_SFD*)pp)->max_bps;
        
        MwsCprmSfd.max_width = ((MWS_PLY_CPRM_SFD*)pp)->max_width;
        MwsCprmSfd.max_height = ((MWS_PLY_CPRM_SFD*)pp)->max_height;
        
        MwsCprmSfd.nfrm_pool_wk = ((MWS_PLY_CPRM_SFD*)pp)->nfrm_pool_wk;
        
        MwsCprmSfd.wksize = ((MWS_PLY_CPRM_SFD*)pp)->wksize;
    }
    
    if (mp == NULL) 
    {
        MwsCprmSfd.work = syMalloc(MwsCprmSfd.wksize);
    }
    else
    {
        MwsCprmSfd.work = mp;
        
        MwMemoryMode = 1;
    }
    
    MwPly = ps2mwPlyCreateSofdec(&MwsCprmSfd, fname);
    
    mwPlySetFastHalfpel(MwPly, 0);
}

// 100% matching!
void CreateWaveHandle()
{

}

// 100% matching!
void CreateTmHandle()
{

}

/*// 
// Start address: 0x290cc0
void PlayMwOpenMain(char* FileName, int Mode, void* mp, void* pp, int PauseFlag)
{
	// Line 182, Address: 0x290cc0, Func Offset: 0
	// Line 183, Address: 0x290cd4, Func Offset: 0x14
	// Line 184, Address: 0x290cec, Func Offset: 0x2c
	// Line 185, Address: 0x290cf4, Func Offset: 0x34
	// Line 189, Address: 0x290d24, Func Offset: 0x64
	// Line 191, Address: 0x290d34, Func Offset: 0x74
	// Line 192, Address: 0x290d38, Func Offset: 0x78
	// Line 194, Address: 0x290d40, Func Offset: 0x80
	// Line 195, Address: 0x290d4c, Func Offset: 0x8c
	// Line 196, Address: 0x290d54, Func Offset: 0x94
	// Line 198, Address: 0x290d5c, Func Offset: 0x9c
	// Line 202, Address: 0x290d84, Func Offset: 0xc4
	// Line 204, Address: 0x290d94, Func Offset: 0xd4
	// Line 206, Address: 0x290d9c, Func Offset: 0xdc
	// Line 207, Address: 0x290da8, Func Offset: 0xe8
	// Line 209, Address: 0x290db0, Func Offset: 0xf0
	// Line 212, Address: 0x290db8, Func Offset: 0xf8
	// Line 215, Address: 0x290dc0, Func Offset: 0x100
	// Line 216, Address: 0x290dd0, Func Offset: 0x110
	// Line 217, Address: 0x290dd8, Func Offset: 0x118
	// Line 219, Address: 0x290de0, Func Offset: 0x120
	// Line 220, Address: 0x290df8, Func Offset: 0x138
	// Line 222, Address: 0x290e04, Func Offset: 0x144
	// Func End, Address: 0x290e1c, Func Offset: 0x15c
}*/

// 
// Start address: 0x290e20
void PlayMw2(char* FileName, int Mode, void* mp, void* pp, int PauseFlag)
{
	// Line 231, Address: 0x290e20, Func Offset: 0
	// Func End, Address: 0x290e28, Func Offset: 0x8
	scePrintf("PlayMw2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x290e30
void StopMw()
{
	// Line 235, Address: 0x290e30, Func Offset: 0
	// Line 236, Address: 0x290e38, Func Offset: 0x8
	// Line 237, Address: 0x290e48, Func Offset: 0x18
	// Line 238, Address: 0x290e60, Func Offset: 0x30
	// Line 239, Address: 0x290e78, Func Offset: 0x48
	// Line 240, Address: 0x290e88, Func Offset: 0x58
	// Line 242, Address: 0x290ea0, Func Offset: 0x70
	// Line 251, Address: 0x290eac, Func Offset: 0x7c
	// Line 253, Address: 0x290eb4, Func Offset: 0x84
	// Func End, Address: 0x290ec0, Func Offset: 0x90
	scePrintf("StopMw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x290ec0
MWE_PLY_STAT GetMwStatus()
{
	// Line 257, Address: 0x290ec0, Func Offset: 0
	// Func End, Address: 0x290ed8, Func Offset: 0x18
	scePrintf("GetMwStatus - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x290ee0
int PlayMwMain2(void(*Func)())
{
	_mwe_ply_stat MweStat;
	// Line 261, Address: 0x290ee0, Func Offset: 0
	// Line 264, Address: 0x290eec, Func Offset: 0xc
	// Line 265, Address: 0x290efc, Func Offset: 0x1c
	// Line 266, Address: 0x290f04, Func Offset: 0x24
	// Line 267, Address: 0x290f10, Func Offset: 0x30
	// Line 268, Address: 0x290f18, Func Offset: 0x38
	// Line 270, Address: 0x290f20, Func Offset: 0x40
	// Line 271, Address: 0x290f28, Func Offset: 0x48
	// Line 274, Address: 0x290f30, Func Offset: 0x50
	// Line 277, Address: 0x290f38, Func Offset: 0x58
	// Line 278, Address: 0x290f3c, Func Offset: 0x5c
	// Func End, Address: 0x290f4c, Func Offset: 0x6c
}*/

// 
// Start address: 0x290f50
int PlayMwMain()
{
	// Line 282, Address: 0x290f50, Func Offset: 0
	// Func End, Address: 0x290f58, Func Offset: 0x8
	scePrintf("PlayMwMain - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x290f60
void PauseMw()
{
	// Line 288, Address: 0x290f60, Func Offset: 0
	// Func End, Address: 0x290f7c, Func Offset: 0x1c
}*/

// 
// Start address: 0x290f80
void RestartMw()
{
	// Line 306, Address: 0x290f80, Func Offset: 0
	// Func End, Address: 0x290f9c, Func Offset: 0x1c
	scePrintf("RestartMw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x290fa0
void SetMwVolume(int Volume)
{
	// Line 322, Address: 0x290fa4, Func Offset: 0x4
	// Func End, Address: 0x290fbc, Func Offset: 0x1c
	scePrintf("SetMwVolume - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x290fc0
int GetSfdFadeRate()
{
	// Line 327, Address: 0x290fc0, Func Offset: 0
	// Func End, Address: 0x290fcc, Func Offset: 0xc
	scePrintf("GetSfdFadeRate - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x290fd0
void SetSfdDislpaySize(float PosX, float PosY, float SizeX, float SizeY)
{
	// Line 338, Address: 0x290fd0, Func Offset: 0
	// Line 339, Address: 0x290fe0, Func Offset: 0x10
	// Line 340, Address: 0x290ff4, Func Offset: 0x24
	// Line 341, Address: 0x291008, Func Offset: 0x38
	// Func End, Address: 0x29101c, Func Offset: 0x4c
	scePrintf("SetSfdDislpaySize - UNIMPLEMENTED!\n");
}

