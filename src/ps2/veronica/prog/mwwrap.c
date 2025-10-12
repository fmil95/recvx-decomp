#include "mwwrap.h"

int MwMode = -1;
int MwPlayFlag;
MWPLY MwPly;
MWS_PLY_CPRM_SFD MwsCprmSfd;
int MwMemoryMode;
int MwPlayMode;

/*void InitMwSystem(unsigned int Mode, void* pPrm);
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
int PlayMwMain();*/
void PauseMw();
/*void RestartMw();
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
void CreateWaveHandle(void* unused) // parameter not present on the debugging symbols 
{

}

// 100% matching!
void CreateTmHandle()
{

}

// 100% matching!
void PlayMwOpenMain(char* FileName, int Mode, void* mp, void* pp, int PauseFlag)
{ 
    if (MwPlayFlag != 0) 
    {
        return; 
    } 
    
    MwMemoryMode = 0;	
    
    switch (MwMode) 
    { 
    case 0:
        CreateSfdHandle(mp, pp, FileName); 

        MwPlayMode = 0; 
        break; 
    case 1:
        CreateWaveHandle(NULL); 
        
        MwPlayMode = 1; 
        break; 
    case 2:
        switch (Mode) 
        { 
        case 0: 
            CreateSfdHandle(mp, pp, FileName); 
            break; 
        case 1: 
            CreateWaveHandle(NULL); 
            break; 
        case 4: 
            CreateTmHandle(); 
            break;
        }
        
        MwPlayMode = Mode; 
        break; 
    }
    
    SetMwSoundMode(GetSoundMode()); 
    
    if (PauseFlag != 0)
    { 
        PauseMw(); 
    }
    
    MwPly->vtbl->StartFname(MwPly, (signed char*)FileName); 
    
    MwPlayFlag = 1; 
} 

// 100% matching!
void PlayMw2(char* FileName, int Mode, void* mp, void* pp, int PauseFlag)
{
    PlayMwOpenMain(FileName, Mode, mp, pp, PauseFlag);
}

// 100% matching!
void StopMw()
{
    if (MwPlayFlag != 0)
    { 
        MwPly->vtbl->Stop(MwPly);
        
        MwPly->vtbl->Destroy(MwPly);
        
        if (MwMemoryMode == 0)
        {
            switch (MwPlayMode) 
            {
            case 0: 
                syFree(MwsCprmSfd.work);
            } 
        }
        
        MwPlayFlag = 0;
    }
}

// 100% matching!
MWE_PLY_STAT GetMwStatus()
{
    return MwPly->vtbl->GetStat(MwPly);
}

// 100% matching!
int PlayMwMain2(void(*Func)())
{
    MWE_PLY_STAT MweStat;
    
    if (MwPlayFlag != 0)
    {
        MweStat = GetMwStatus();
        
        if (MweStat == 3)
        {
            if (Func != NULL) 
            {
                Func();
            }
            
            StopMw();
            
            return 0;
        }
        
        mwPlyExecServer();
    }
    
    return 1;
}

// 100% matching!
int PlayMwMain()
{
    PlayMwMain2(NULL);
}

// 
// Start address: 0x290f60
void PauseMw()
{
	// Line 288, Address: 0x290f60, Func Offset: 0
	// Func End, Address: 0x290f7c, Func Offset: 0x1c
	scePrintf("PauseMw - UNIMPLEMENTED!\n");
}

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
