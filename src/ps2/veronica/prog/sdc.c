#include "sdc.h"
#include "ps2_sg_sycfg.h"
#include "main.h"

NO_NAME_20 MidiInfo[8];
SDMIDI MidiHandle[8] __attribute__((aligned(64)));
NO_NAME_20 SeInfo[20] __attribute__((aligned(64)));
SDSHOT SeHandle[20];
char SdcMasterVolume;
char SdcGdDaVolume;
char SdcMidiDefaultVolume;
char SdcSeDefaultVolume;
unsigned int TransCompleteFlag;
SDS_MEMBLK* SdMemBlk __attribute__((aligned(64)));
unsigned int ExecFxFlag;
unsigned int SddFirstFlag;
int SdcSoundMode = -1;
void(*TransCallBackFunc)(void*) = (void*)-1;

// 100% matching!
void TransWaitCallBackFunction() 
{ 
    sdMemBlkDestroy(SdMemBlk); 
    
    TransCompleteFlag = 0; 
}

// 100% matching!
unsigned int CheckTransComplete() 
{ 
    return TransCompleteFlag; 
}

// 100% matching!
void SetupSoundDriver(void* pSndDrv, unsigned int SndDrvSize)
{
    void* temp; // not from the debugging symbols

    temp = TransWaitCallBackFunction;
    
    sdLibInit(NULL, 0, 0); 
    
    sdMemBlkCreate(&SdMemBlk);
    
    TransCompleteFlag = 1;
    
    sdMemBlkSetPrm(SdMemBlk, pSndDrv, SndDrvSize, TransCallBackFunc, NULL);
    
    sdDrvInit(SdMemBlk);
    
    sdMemBlkDestroy(SdMemBlk);
    
    sdMemBlkSetTransferMode(SDE_MEMBLK_TRANSFER_MODE_DMA);
    
    TransCallBackFunc = temp;
    
    sdSysSetSlotMax(36, 20, 8); 
}

// 100% matching! 
void ExitSoundDriver()
{
    StopFxProgram();
    
    sdSndStopAll();
    
    sdSysFinish();
}

// 100% matching!
void SetMultiUnit(void* pMulUni, unsigned int MulUniSize)
{
    sdMemBlkCreate(&SdMemBlk);
    
    TransCompleteFlag = 1;
    
    sdMemBlkSetPrm(SdMemBlk, pMulUni, MulUniSize, (SD_MEMBLK_CALLBACK_FUNC)-1, NULL);
    
    sdMultiUnitDownload(SdMemBlk);
    
    sdMemBlkDestroy(SdMemBlk);
}

// 100% matching!
void SetSoundData(SDE_DATA_TYPE DataType, int BankNo, void* pSndDat, unsigned int SndDatSize)
{
    sdMemBlkCreate(&SdMemBlk);
    
    TransCompleteFlag = 1;
    
    sdMemBlkSetPrm(SdMemBlk, pSndDat, SndDatSize, TransCallBackFunc, NULL);
    
    sdBankDownload(SdMemBlk, DataType, BankNo);
}

// 100% matching!
void SetSoundModeEx(int Mode, int Flag)
{
    if (Mode == 0)
    {
        sdSndSetPanMode(SDE_PAN_MODE_STEREO);
        
        sdGddaSetPan(127, -127);
    } 
    else
    {
        sdSndSetPanMode(SDE_PAN_MODE_MONO);
        
        sdGddaSetPan(0, 0);
    }
    
    SdcSoundMode = Mode;
    
    if (Flag != 0) 
    {
        syCfgSetSoundMode(Mode);
    }
}

// 100% matching!
void SetSoundMode(int Mode)
{
    SetSoundModeEx(Mode, 1);
}

// 100% matching!
int GetSoundMode()
{
    int Mode;

    if (SdcSoundMode == -1) 
    {
        syCfgGetSoundMode(&Mode);
        
        SdcSoundMode = Mode;
    }
    
    return SdcSoundMode;
}

// 100% matching!
void SetMasterVolume(char Volume)
{
    sdSndSetMasterVol(Volume);
    
    SdcMasterVolume = Volume;
}

// 100% matching!
void SetGdDaVolume(char Volume)
{
    SdcGdDaVolume = Volume;
}

// 100% matching!
void InitMidiInfo()
{
    unsigned int i;
    
    for (i = 0; i < 8; i++)
    {
        if (SddFirstFlag == 0) 
        {
            MidiInfo[i].Flag = 0;
        } 
        else 
        {
            FreeMidiSlot(i);
        }
        
        MidiInfo[i].Volume = 0;
        
        MidiInfo[i].LimitMaxVol = 0;
        
        MidiInfo[i].FadeFunc = 0;
        MidiInfo[i].PanFunc = 0;
    } 
}

// 100% matching! 
unsigned int RegistMidiSlot(unsigned int SlotNo) 
{
    if (MidiInfo[SlotNo].Flag != 0) 
    {
        return 1;
    }
    
    sdMidiOpenPort(&MidiHandle[SlotNo]);

    MidiInfo[SlotNo].Flag = 1;
    
    return 0;
}

// 100% matching! 
void FreeMidiSlot(unsigned int SlotNo)
{
    if (MidiInfo[SlotNo].Flag != 0)
    {
        sdMidiClosePort(MidiHandle[SlotNo]);
    }
    
    MidiInfo[SlotNo].Flag = 0;
}

// 100% matching! 
unsigned int CheckPlayMidi(unsigned int SlotNo)
{
    SDS_MIDI_STAT Status;
    
    sdMidiGetStat(MidiHandle[SlotNo], &Status);

    return Status.m_Flg & 0x1;
}

// 100% matching! 
void PlayMidi(unsigned int SlotNo, char BankNo, char ListNo, char Priority)
{
    if ((MidiInfo[SlotNo].Flag != 0) && (ListNo != -1)) 
    {
        sdMidiPlay(MidiHandle[SlotNo], BankNo, ListNo, Priority);
    }
}

// 100% matching! 
void ExPlayMidi(SND_REQ* pRequestInfo)
{
    if (MidiInfo[pRequestInfo->SlotNo].Flag != 0)
    {
        switch (pRequestInfo->PanDelayTime)
        {               
        case -2:
            SetPanMidi(pRequestInfo->SlotNo, 0, 0);
            break;
        case -1:
            break;
        default:
            SetPanMidi(pRequestInfo->SlotNo, pRequestInfo->Pan, pRequestInfo->PanDelayTime);
            break;
        }
        
        switch (pRequestInfo->VolumeDelayTime) 
        {                       
        case -2:                                   
            SetVolumeMidi(pRequestInfo->SlotNo, SdcSeDefaultVolume, 0);
            break;
        case -1:                                    
            break;
        default:                                    
            SetVolumeMidi(pRequestInfo->SlotNo, pRequestInfo->Volume, pRequestInfo->VolumeDelayTime);
            break;
        }
        
        switch (pRequestInfo->PitchDelayTime)
        {                        
        case -2:                                 
            SetPitchMidi(pRequestInfo->SlotNo, 0, 0);
            break;
        case -1:                                  
            break;
        default:                                   
            SetPitchMidi(pRequestInfo->SlotNo, pRequestInfo->Pitch, pRequestInfo->PitchDelayTime);
            break;
        }
        
        switch (pRequestInfo->SpeedDelayTime)
        {                        
        case -2:                                    
            SetSpeedMidi(pRequestInfo->SlotNo, 0, 0);
            break;
        case -1:                                   
            break;
        default:                                    
            SetSpeedMidi(pRequestInfo->SlotNo, pRequestInfo->Speed, pRequestInfo->SpeedDelayTime);
            break;
        }
        
        if (pRequestInfo->FxInput != -1) 
        {
            sdMidiSetFxLev(MidiHandle[pRequestInfo->SlotNo], pRequestInfo->FxLevel);
        }
        
        PlayMidi(pRequestInfo->SlotNo, pRequestInfo->BankNo, pRequestInfo->ListNo, pRequestInfo->Priority);
    }
}

// 100% matching!
void StopMidi(unsigned int SlotNo) 
{
    if (MidiInfo[SlotNo].Flag != 0) 
    {
        sdMidiStop(MidiHandle[SlotNo]);
    }
}

// 99.43% matching
void SetPanMidi2(unsigned int SlotNo, float Pan, short DelayTime)
{
    if ((MidiInfo[SlotNo].Flag != 0) && ((MidiInfo[SlotNo].PanFunc != 0) || (MidiInfo[SlotNo].FadeFunc != 2)))
    {
        sdMidiSetPan(MidiHandle[SlotNo], Pan, DelayTime);
        
        MidiInfo[SlotNo].Pan = Pan;
    }
}

// 100% matching!
void SetPanMidi(unsigned int SlotNo, char Pan, short DelayTime)
{
    SetPanMidi2(SlotNo, Pan, DelayTime);
}

// 99.56% matching
void SetVolumeMidiEx(unsigned int SlotNo, float Volume, short DelayTime, int Flag)
{
    if (MidiInfo[SlotNo].Flag != 0)
    {
        switch (MidiInfo[SlotNo].FadeFunc) 
        {
        case 0:
            sdMidiSetVol(MidiHandle[SlotNo], Volume, DelayTime);
            
            MidiInfo[SlotNo].Volume = Volume;
            break;
        case 1:
            if ((Flag == 0) && (Volume < MidiInfo[SlotNo].VolLast)) 
            {
                RequestMidiFadeFunctionEx(SlotNo, -1, Volume, MidiInfo[SlotNo].FadeCntMax);
            }
            
            MidiInfo[SlotNo].Volume = Volume;
        case 2:
            sdMidiSetVol(MidiHandle[SlotNo], MidiInfo[SlotNo].Volume, 0);
            break;
        }
    }
}

// 100% matching!
void SetVolumeMidi(unsigned int SlotNo, char Volume, short DelayTime)
{
    SetVolumeMidiEx(SlotNo, Volume, DelayTime, 0);
}

// 100% matching!
void SetVolumeMidi2(unsigned int SlotNo, float Volume, short DelayTime)
{
    SetVolumeMidiEx(SlotNo, Volume, DelayTime, 0);
}

// 100% matching! 
void SetPitchMidi(unsigned int SlotNo, short Pitch, short DelayTime)
{
    if (MidiInfo[SlotNo].Flag != 0)
    {
        sdMidiSetPitch(MidiHandle[SlotNo], Pitch, DelayTime);
    }
}

// 100% matching! 
void SetSpeedMidi(unsigned int SlotNo, short Speed, short DelayTime)
{
    if (MidiInfo[SlotNo].Flag != 0) 
    {
        sdMidiSetSpeed(MidiHandle[SlotNo], Speed, DelayTime);
    }
}

// 100% matching!
void SetFxLevelMidi(unsigned int SlotNo, char FxLevel)
{
    if (MidiInfo[SlotNo].Flag != 0) 
    {
        sdMidiSetFxLev(MidiHandle[SlotNo], FxLevel);
    }
}

// 100% matching! 
void SetMidiDefaultVolume(char Volume)
{
    SdcMidiDefaultVolume = Volume;
}

// 100% matching!
void InitSeInfo()
{
    unsigned int i;
    
    for (i = 0; i < 20; i++)
    {
        if (SddFirstFlag == 0) 
        {
            SeInfo[i].Flag = 0;
        } 
        else 
        {
            FreeSeSlot(i);
        }
        
        SeInfo[i].Volume = 0;
        
        SeInfo[i].LimitMaxVol = 0;
        
        SeInfo[i].FadeFunc = 0;
        SeInfo[i].PanFunc = 0;
    } 
}

// 100% matching! 
unsigned int RegistSeSlot(unsigned int SlotNo)
{
    if (SeInfo[SlotNo].Flag != 0) 
    {
        return 1;
    }
    
    sdShotOpenPort(&SeHandle[SlotNo]);

    SeInfo[SlotNo].Flag = 1;
    
    return 0;
}

// 100% matching! 
void FreeSeSlot(unsigned int SlotNo)
{
    if (SeInfo[SlotNo].Flag != 0) 
    {
        sdShotClosePort(SeHandle[SlotNo]);
    }

    SeInfo[SlotNo].Flag = 0;
}

// 100% matching! 
unsigned int CheckPlaySe(unsigned int SlotNo) 
{
    SDS_SHOT_STAT status;
    
    sdShotGetStat(SeHandle[SlotNo], &status);
    
    return status.m_Flg & 0x1;
}

// 100% matching!
void PlaySe(unsigned int SlotNo, char BankNo, char ListNo, char Priority)
{
    if ((SeInfo[SlotNo].Flag != 0) && (ListNo != -1)) 
    {
        sdShotPlay(SeHandle[SlotNo], BankNo, ListNo, Priority);
    }
}

// 100% matching! 
void ExPlaySe(SND_REQ* pRequestInfo)
{
    if (SeInfo[pRequestInfo->SlotNo].Flag != 0) 
    {
        switch (pRequestInfo->PanDelayTime) 
        {                         
        case -2:
            SetPanSe(pRequestInfo->SlotNo, 0, 0);
            break;
        case -1:
            break;
        default:
            SetPanSe(pRequestInfo->SlotNo, pRequestInfo->Pan, pRequestInfo->PanDelayTime);
            break;
        }
        
        switch (pRequestInfo->VolumeDelayTime) 
        {                        
        case -2:                                  
            SetVolumeSe(pRequestInfo->SlotNo, SdcSeDefaultVolume, 0);
            break;
        case -1:                                  
            break;
        default:                                  
            SetVolumeSe(pRequestInfo->SlotNo, pRequestInfo->Volume, pRequestInfo->VolumeDelayTime);
            break;
        }
        
        switch (pRequestInfo->PitchDelayTime) 
        {                        
        case -2:                                   
            SetPitchSe(pRequestInfo->SlotNo, 0, 0);
            break;
        case -1:                                   
            break;
        default:                                    
            SetPitchSe(pRequestInfo->SlotNo, pRequestInfo->Pitch, pRequestInfo->PitchDelayTime);
            break;
        }
        
        switch (pRequestInfo->FxInput) 
        {                         
        case -2:                                    
            sdShotSetFxLev(SeHandle[pRequestInfo->SlotNo], 0);
            break;
        case -1:                                    
            break;
        default:                                  
            sdShotSetFxLev(SeHandle[pRequestInfo->SlotNo], pRequestInfo->FxLevel);
            break;
        }
        
        PlaySe(pRequestInfo->SlotNo, pRequestInfo->BankNo, pRequestInfo->ListNo, pRequestInfo->Priority);
    }
}

// 100% matching!
void StopSe(unsigned int SlotNo)
{
    if (SeInfo[SlotNo].Flag != 0) 
    {
        sdShotStop(SeHandle[SlotNo]);
    }
}

// 99.49% matching
void SetPanSe2(unsigned int SlotNo, float Pan, short DelayTime)
{ 
    if (SeInfo[SlotNo].Flag != 0) 
    {
        sdShotSetPan(SeHandle[SlotNo], Pan, DelayTime);
        
        SeInfo[SlotNo].Pan = Pan;
    }
}

// 100% matching!
void SetPanSe(unsigned int SlotNo, char Pan, short DelayTime)
{
    SetPanSe2(SlotNo, Pan, DelayTime);
}

// 99.56% matching
void SetVolumeSeEx(unsigned int SlotNo, float Volume, short DelayTime, int Flag)
{
    if (SeInfo[SlotNo].Flag != 0) 
    {
        switch (SeInfo[SlotNo].FadeFunc) 
        {
        case 0:
            sdShotSetVol(SeHandle[SlotNo], Volume, DelayTime);
            
            SeInfo[SlotNo].Volume = Volume;
            break;
        case 1:
            if ((Flag == 0) && (Volume < SeInfo[SlotNo].VolLast))
            {
                RequestSeFadeFunctionEx(SlotNo, -1, Volume, SeInfo[SlotNo].FadeCntMax);
            }
            
            SeInfo[SlotNo].Volume = Volume;
        case 2:
            sdShotSetVol(SeHandle[SlotNo], SeInfo[SlotNo].Volume, 0);
            break;
        }
    }
}

// 100% matching!
void SetVolumeSe(unsigned int SlotNo, char Volume, short DelayTime)
{
    SetVolumeSeEx(SlotNo, Volume, DelayTime, 0);
}

// 100% matching!
void SetVolumeSe2(unsigned int SlotNo, float Volume, short DelayTime)
{
    SetVolumeSeEx(SlotNo, Volume, DelayTime, 0);
}

// 100% matching! 
void SetPitchSe(unsigned int SlotNo, short Pitch, short DelayTime)
{
    if (SeInfo[SlotNo].Flag != 0) 
    {
        sdShotSetPitch(SeHandle[SlotNo], Pitch, DelayTime);
    }
}

// 100% matching!
void SetFxLevelSe(unsigned int SlotNo, char FxLevel)
{
    if (SeInfo[SlotNo].Flag != 0) 
    {
        sdShotSetFxLev(SeHandle[SlotNo], FxLevel);
    }
}

// 100% matching! 
void SetSeDefaultVolume(char Volume) 
{
    SdcSeDefaultVolume = Volume;
}

// 100% matching! 
void SetFxProgram(char FxProgramNo, char FxOutputNo)
{
    sdSndSetFxPrg(FxProgramNo, FxOutputNo);
    
    ExecFxFlag = 1;
}

// 100% matching!
void StopFxProgram()
{
    if (ExecFxFlag != 0) 
    {
        sdSndClearFxPrg();
    }
    
    ExecFxFlag = 0;
}

// 
// Start address: 0x28ff80
void RequestMidiFadeFunction(int SlotNo, int Func, short Timer)
{
	//_anon0* mp;
	// Line 652, Address: 0x28ff80, Func Offset: 0
	// Line 653, Address: 0x28ff98, Func Offset: 0x18
	// Line 655, Address: 0x28ffb8, Func Offset: 0x38
	// Line 656, Address: 0x28ffc0, Func Offset: 0x40
	// Line 657, Address: 0x28ffc4, Func Offset: 0x44
	// Line 659, Address: 0x28ffcc, Func Offset: 0x4c
	// Line 663, Address: 0x28ffd4, Func Offset: 0x54
	// Line 666, Address: 0x290044, Func Offset: 0xc4
	// Line 667, Address: 0x290050, Func Offset: 0xd0
	// Line 668, Address: 0x29005c, Func Offset: 0xdc
	// Line 674, Address: 0x290064, Func Offset: 0xe4
	// Line 677, Address: 0x290084, Func Offset: 0x104
	// Func End, Address: 0x29008c, Func Offset: 0x10c
	scePrintf("RequestMidiFadeFunction - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x290090
void RequestMidiFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame)
{
	//_anon0* mp;
	// Line 680, Address: 0x290090, Func Offset: 0
	// Line 683, Address: 0x2900a0, Func Offset: 0x10
	// Line 680, Address: 0x2900bc, Func Offset: 0x2c
	// Line 685, Address: 0x2900c0, Func Offset: 0x30
	// Line 686, Address: 0x2900cc, Func Offset: 0x3c
	// Line 688, Address: 0x2900d8, Func Offset: 0x48
	// Line 689, Address: 0x2900dc, Func Offset: 0x4c
	// Line 688, Address: 0x2900e4, Func Offset: 0x54
	// Line 689, Address: 0x2900e8, Func Offset: 0x58
	// Line 688, Address: 0x2900ec, Func Offset: 0x5c
	// Line 689, Address: 0x2900f0, Func Offset: 0x60
	// Line 691, Address: 0x2900f4, Func Offset: 0x64
	// Line 692, Address: 0x2900fc, Func Offset: 0x6c
	// Line 695, Address: 0x29011c, Func Offset: 0x8c
	// Line 696, Address: 0x290148, Func Offset: 0xb8
	// Func End, Address: 0x290160, Func Offset: 0xd0
	scePrintf("RequestMidiFadeFunctionEx - UNIMPLEMENTED!\n");
}
 
// 100% matching! 
void StopFadeMidi(int SlotNo)
{
    MidiInfo[SlotNo].FadeFunc = 0;
}

// 100% matching! 
void RequestSeFadeFunction(int SlotNo, int Func, short Timer)
{
    NO_NAME_20* sp;
    
    sp = &SeInfo[SlotNo];
    
    switch (Func) 
    {                                
    case 1:
        sp->Volume = -127.0f;
        
        sp->VolLast = sp->LimitMaxVol;
        break;
    case 2:
        sp->VolLast = -127.0f;
        break;
    }
    
    sp->FadeCntMax = ((Timer / 100) * 30) + (((Timer % 100) * 6) / 10);
    
    sp->FadeCntMax /= 2;
    
    if (sp->FadeCntMax == 0) 
    {
        sp->FadeCntMax = 1;
    }
    
    sp->VolSpeed = (sp->Volume - sp->VolLast) / sp->FadeCntMax;
    
    sp->FadeFunc = Func;
}

// 87.69% matching
void RequestSeFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame)
{
    NO_NAME_20* sp;
    int Func; // not from the debugging symbols
    
    sp = &SeInfo[SlotNo];
    
    if (StartVol == -1) 
    {
        StartVol = sp->Volume;  
    }

    sp->Volume = StartVol;      
    sp->VolLast = LastVol;     
    
    sp->FadeCntMax = Frame;

    if (Frame != 0) 
    {
        sp->VolSpeed = -((sp->VolLast - sp->Volume) / sp->FadeCntMax);
    }

    if (sp->VolSpeed < 0) 
    {
        Func = 1;
    } 
    else 
    {
        Func = 2;
    }

    sp->FadeFunc = Func;
}

// 100% matching! 
void StopFadeSe(int SlotNo)
{
    SeInfo[SlotNo].FadeFunc = 0;
}

// 100% matching! 
int CheckFadeEndSe(int SlotNo)
{
    if (SeInfo[SlotNo].FadeFunc == 0) 
    {
        return 0;
    }
    
    return 1;
}

// 100% matching!
int ExecSoundFadeManager() {
    int i;
    int ReturnCode;
    NO_NAME_20* mp;
    NO_NAME_20* sp;
    
    ReturnCode = 0;
    for(i = 0;i < 8; i++) {
        mp = &MidiInfo[i];
        switch(mp->FadeFunc) {
            case 1:
            case 2:
                mp->Volume -= mp->VolSpeed;
                mp->FadeCntMax--;

                if (mp->FadeCntMax < 0) {
                    mp->Volume = mp->VolLast;
                    
                    if ((int)mp->Volume == -0x7F) {
                        StopMidi(i);
                    }
                    
                    mp->FadeFunc = 0;
                } else {
                    ReturnCode = 1;
                }
                
                SetVolumeMidiEx(i, mp->Volume, 0, 1);  
            break;

            case 0:
            break;
        }
    }

    for(i = 0; i < 20; i++) {
        sp = &SeInfo[i];
        switch(sp->FadeFunc) {
            case 1: 
            case 2:
                sp->Volume -= sp->VolSpeed;
                sp->FadeCntMax -= 1;
    
                if (sp->FadeCntMax < 0) {
                    sp->Volume = sp->VolLast;
                    
                    if ((int)sp->Volume == -0x7F) {
                        StopSe(i);
                    }
                    
                    sp->FadeFunc = 0;
                } else {
                    ReturnCode = 1;
                }
                
                SetVolumeSeEx(i, sp->Volume, 0, 1);
            break;
            
            case 0:
            break;
        }
    }

    return ReturnCode;
}

// 
// Start address: 0x290560
void RequestMidiPanFunctionEx(int SlotNo, int StartPan, int LastPan, int Frame)
{
	//_anon0* mp;
	// Line 817, Address: 0x290560, Func Offset: 0
	// Line 820, Address: 0x290570, Func Offset: 0x10
	// Line 817, Address: 0x29058c, Func Offset: 0x2c
	// Line 822, Address: 0x290590, Func Offset: 0x30
	// Line 823, Address: 0x29059c, Func Offset: 0x3c
	// Line 825, Address: 0x2905a8, Func Offset: 0x48
	// Line 826, Address: 0x2905ac, Func Offset: 0x4c
	// Line 825, Address: 0x2905b4, Func Offset: 0x54
	// Line 826, Address: 0x2905b8, Func Offset: 0x58
	// Line 825, Address: 0x2905bc, Func Offset: 0x5c
	// Line 826, Address: 0x2905c0, Func Offset: 0x60
	// Line 828, Address: 0x2905c4, Func Offset: 0x64
	// Line 829, Address: 0x2905cc, Func Offset: 0x6c
	// Line 832, Address: 0x290600, Func Offset: 0xa0
	// Line 833, Address: 0x290608, Func Offset: 0xa8
	// Func End, Address: 0x290620, Func Offset: 0xc0
	scePrintf("RequestMidiPanFunctionEx - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x290620
void RequestSePanFunctionEx(int SlotNo, int StartPan, int LastPan, int Frame)
{
	_anon0* sp;
	// Line 836, Address: 0x290620, Func Offset: 0
	// Line 839, Address: 0x290630, Func Offset: 0x10
	// Line 836, Address: 0x29064c, Func Offset: 0x2c
	// Line 841, Address: 0x290650, Func Offset: 0x30
	// Line 842, Address: 0x29065c, Func Offset: 0x3c
	// Line 844, Address: 0x290668, Func Offset: 0x48
	// Line 845, Address: 0x29066c, Func Offset: 0x4c
	// Line 844, Address: 0x290674, Func Offset: 0x54
	// Line 845, Address: 0x290678, Func Offset: 0x58
	// Line 844, Address: 0x29067c, Func Offset: 0x5c
	// Line 845, Address: 0x290680, Func Offset: 0x60
	// Line 847, Address: 0x290684, Func Offset: 0x64
	// Line 848, Address: 0x29068c, Func Offset: 0x6c
	// Line 851, Address: 0x2906c0, Func Offset: 0xa0
	// Line 852, Address: 0x2906c8, Func Offset: 0xa8
	// Func End, Address: 0x2906e0, Func Offset: 0xc0
}*/

// 100% matching!
int ExecSoundPanManager() {
    NO_NAME_20* sp;
    int ReturnCode;
    int i;

    ReturnCode = 0;
    
    for(i = 0; i < 8; i++) {
        sp = &MidiInfo[i];
        if (sp->PanFunc != 0) {
            sp->Pan -= sp->PanSpeed;
            sp->PanCntMax -= 1;

            if (sp->PanCntMax < 0) {
                sp->Pan = sp->PanLast;
                sp->PanFunc = 0;
            } else {
               ReturnCode = 1; 
            }

            SetPanMidi2(i, sp->Pan, 0);
        }
    }

    for(i = 0; i < 20; i++) {
        sp = &SeInfo[i];
        if (sp->PanFunc != 0) {
            sp->Pan -= sp->PanSpeed;
            sp->PanCntMax  -= 1;

            if (sp->PanCntMax < 0)  {
                sp->Pan = sp->PanLast;
                sp->PanFunc = 0;
            } else {
                ReturnCode = 1;
            }

            SetPanSe2(i, sp->Pan, 0);
        }
        
    }

    return ReturnCode;
}

