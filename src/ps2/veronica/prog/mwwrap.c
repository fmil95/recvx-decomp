#include "mwwrap.h"
#include "ps2_sfd_mw.h"
#include "ps2_sg_maloc.h"
#include "sdc.h"

#include <string.h>

int MwMode = -1;
int MwPlayFlag;
MWPLY MwPly;
MWS_PLY_CPRM_SFD MwsCprmSfd __attribute__((aligned(64)));
int MwMemoryMode;
int MwPlayMode;

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
    memset(&MwsCprmSfd, 0, sizeof(MWS_PLY_CPRM_SFD));
    
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
    return PlayMwMain2(NULL);
}

// 100% matching!
void PauseMw()
{
    MwPly->vtbl->Pause(MwPly, 1); 
}

// 100% matching!
void RestartMw()
{
    MwPly->vtbl->Pause(MwPly, 0); 
}

// 100% matching!
void SetMwVolume(int Volume)
{
    MwPly->vtbl->SetOutVol(MwPly, Volume);
}

// 100% matching!
int GetSfdFadeRate()
{
    return mwPlyGetBright(MwPly);
}

// 100% matching!
void SetSfdDislpaySize(float PosX, float PosY, float SizeX, float SizeY)
{
    mwPlySetDispPos(MwPly, PosX, PosY);
    mwPlySetDispSize(MwPly, SizeX, SizeY);
}
