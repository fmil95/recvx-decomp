#include "sdfunc.h"
#include "adv.h"
#include "adxwrap.h"
#include "gdlib.h"
#include "mwwrap.h"
#include "ps2_sg_maloc.h"
#include "ps2_sg_sybt.h"
#include "ps2_sg_sycfg.h"
#include "padman.h"
#include "pwksub.h"
#include "screen.h"
#include "sdc.h"
#include "sdcwrap.h"
#include "vibman.h"
#include "main.h"

#include <string.h>

#include <mathf.h>

AFS_PATINFO SoundAfsPatDef[8] = {
    { "BGM?.AFS"    , 0, 128, NULL },
    { "VOICE?.AFS"  , 1, 768, NULL },
    { "MULTSPQ?.AFS", 2, 512, NULL },
    { "ADV.AFS"     , 3, 128, NULL },
    { "ITEM?.AFS"   , 4, 512, NULL },
    { "MRY.AFS"     , 5, 160, NULL },
    { "SYSTEM.AFS"  , 6, 256, NULL },
    { NULL          , 0, 0  , NULL }
};
ADX_WORK AdxDef[2] = { { 2, 48000, 2, -1 }, { 1, 48000, 2, -1 } };
SDE_DATA_TYPE SdTypeDef[5] = { SDE_DATA_TYPE_MIDI_SEQ_BANK, SDE_DATA_TYPE_MIDI_PRG_BANK, SDE_DATA_TYPE_SHOT_BANK, SDE_DATA_TYPE_FX_PRG_BANK, SDE_DATA_TYPE_FX_OUT_BANK }; 
/*int PlayerFootStepSwitch[3];
int SystemSeSlotSwitch;
int WeaponSeSlotSwitch;
int EnemyBackGroundSeFlag;*/
char MoviePlayTrayOpenFlag;
int CurrentBgmNo = -1;
int CurrentBgSeNo[2];
int RoomSoundCaseNo;
/*short DefBg[3];
short DefObj[5];
short DefEvt[5];*/
short DefEne[6];
int SoundInitLevel;
int SdReadMode;
int SpqFileReadRequestFlag;
int TransSoundPackDataFlag;
int ReadFileRequestFlag;
int FileReadStatus;
int KeyReadSwitch;
SND_CMD SoundCommand;
MOV_INFO MovieInfo;
unsigned char* pConfigWork;
unsigned short* pSpqList;
unsigned char* pSoundAfs;
char SpqFileName[32];
int EventVibrationMode;
NO_NAME_30 BgSePrmBuf[2];
int ReqFadeBgSe[2];
int ReqFadeBgmNo;
int NextBgmVolume;
int CurrentBgmVolume;
unsigned char* pSdReadBuf;
SPQ_HEADER* pSpqHeader;
/*int AddFxLevel;
int CurrentFxLevel;
int RoomFxLevel;*/
RM_SNDENV Room_SoundEnv;
/*char FxLevelTimer;*/
unsigned short SpqKeyCode;
char CurrentDoorNo;
int MaxSlotEventSe;
int MaxSlotObjectSe;
/*char ThreeDVolTbl[510];
char PanTbl360[68];
char PanTbl360Vol[68];*/
char CurrentRoomFxLevel;
/*int AngBak;*/
SND_REQ RequestInfo;
NJS_POINT3 CameraPos;
/*_anon44 GsSlotInfoAx[2];*/
Object ObjectInfo[16];
/*_anon44 GsSlotInfoMi[8];
*/
NO_NAME_31 GsSlotInfoSe[20];
NJS_POINT3 PlayerPos;
/*int xAng;
int xVol;
int xPan;
SDS_PORT_REF** MidiHandle[0];
*/
int StartInitScriptFlag;
/*_anon19 MidiInfo[0];*/
Enemy EnemyInfo[128];
EnemySlot EnemySlotInfo[6];
int MaxObjectReqList;
unsigned char ObjectReqList[16];
unsigned int AdxPlayFlag[2];
char CurrentRoomFxProgNo;
int MaxRequestList;
unsigned char RequestList[128];
ObjectSlot ObjectSlotInfo[3];
/*_anon65 SdComFuncTbl[10];*/
unsigned char* DestReadPtr;
int GenAdxfSlot;
unsigned char MovieTypeDef[22] = { 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x80, 0x42, 0x82, 0x00, 0x80, 0x00, 0x82 };
short MovieVolDef[22] = { 0 }; 
MOV_DEF MovieDef[4] = { { 320, 240, 0, 0, 640, 448, 1 }, { 320, 176, 0, 64, 640, 320, 1 }, { 320, 352, 0, 64, 640, 320, 1 }, { 0, 0, 0, 0, 0, 0, 1 } };
RMI_WORK rmi;
PDS_VIBPARAM_EX VibP[32];
char VibFlag[5] = { 0x01, 0x08, 0x80, 0x09, 0x81 };
int SystemAdjustFlag;
/*float xDist;
_anon6 NextSoundInfo;*/

// 100% matching!
void bhReleaseFreeMemory(void* mp)
{ 
    sys->memp = mp; 
}

// 100% matching!
void ExitApplication()
{ 
    njUserExit();
}

// 100% matching!
void QuickGetDiscTrayStatus() 
{ 
    StatusUpdateCounter = 1; 
    
    njWaitVSync(); 
    
    if (DiscOpenTrayFlag == -1)
    { 
        ExitApplication(DiscOpenTrayFlag); 
    }
} 

// 100% matching!
void InitFirstSofdec()
{
    mwPlyPreInitSofdec();
}

// 100% matching! 
int GetBootDiscId()
{
    unsigned char* p; 
    int ReturnCode; 

    syBtGetBootSystemID(&BootDiscSystemId);
    
    p = syMalloc(16384);
    
    QuickGetDiscTrayStatus();
    
    if (ReadFileEx("DISCID.BIN", p) != 0) 
    {
        ExitApplication();
    }
    
    ReturnCode = *p;
    
    syFree(p);
    
    return ReturnCode;
}

// 100% matching! 
void InitSofdecSystem(int Mode)
{
    MWS_PLY_INIT_SFD iprm;
    int temp; // not from the debugging symbols

    memset(&iprm, 0, sizeof(MWS_PLY_INIT_SFD));
    
    iprm.mode = hws->mode;
    
    iprm.frame = hws->frame; 
    
    iprm.count = hws->count; 
    
    if (hws->vtx_opq_a < 0) 
    {
        temp = 2;
    }
    else if (hws->vtx_opq_b < 0) 
    {
        temp = 2;
    }
    else if (hws->vtx_trs_a < 0) 
    {
        temp = 2;
    } 
    else if (hws->vtx_trs_b < 0)
    {
        temp = 2;
    }
    else if (hws->vtx_punch < 0) 
    {
        temp = 2;
    }
    else 
    {
        temp = 3;
    }

    iprm.latency = temp; 
    
    if (Mode == 0) 
    {
        InitMwSystem(0, &iprm);
    }
    else 
    {
        ReinitMwSystem(&iprm);
    }
}

// 100% matching! 
void ExitSofdecSystem()
{
    if (MoviePlayTrayOpenFlag == 0) 
    {
        ExitMwSystem();
    }
}

// 97.61% matching
void InitSoundProgram()
{
    int i;

    switch (GetBootDiscId()) 
    {                         
    case 0:
        sys->ss_flg &= ~0x1;
        break;
    case 1:
        sys->ss_flg |= 0x1;
        break;
    }
    
    pConfigWork = syMalloc(16384);
    
    syCfgInit(pConfigWork);
    
    SoundInitLevel = 1;
    
    InitSoundDriver("MANATEE.DRV", "COMMON.MLT");
    
    SoundInitLevel = 2;
    
    for (i = 0; i < 8; i++) 
    {
        RegistMidiSlot(i);
    } 
    
    for (i = 0; i < 20; i++)
    {
        RegistSeSlot(i);
    } 
    
    SetFxProgram(0, 0);
    
    InitSofdecSystem(0);
    
    MovieInfo.ExecMovieSystemFlag = 0;
    
    SoundInitLevel = 3;
    
    InitAdx();
    
    RegistAdxStreamEx(2, 4, &AdxDef[0]);
    
    if (MountSoundAfs() != 0) 
    {
        ExitApplication();
    }
    
    SoundInitLevel = 4;
    
    InitReadKeyEx(1);
    
    SetRepeatKeyTimer(5, 2);
    
    InitVibrationUnit();
    InitPlayLogSystem();
    
    RequestAdjustDisplay(0, 0);
    
    ResetRoomSoundEnvParam();
    ResetSoundComInfo();
    
    memset(&SoundCommand, 0, sizeof(SND_CMD));
    
    InitAdvSystem();
    
    SoundInitLevel = -1;
}

// 100% matching!
void ExitSoundProgram() 
{ 
    switch (SoundInitLevel)
    {       
    case -1:
        ExitPlayLogSystem(); 
        ExitVibrationUnit(); 
    case 4:
        UnmountSoundAfs(); 
        
        FreeAdxStream(); 
        
        ExitAdx(); 
    case 3:
        ExitSofdecSystem(); 
    case 2:
        ExitSoundDriver(); 
    case 1:
        syCfgExit(); 
        syFree(pConfigWork); 
    }
} 

// 100% matching! 
int MountSoundAfs()
{
    int i; 
    int WorkSize; 
    unsigned char* p; 
    
    if (!(sys->ss_flg & 0x1))
    {
        SoundAfsPatDef[0].AfsFileName[3] = '1';
        SoundAfsPatDef[1].AfsFileName[5] = '1';
        SoundAfsPatDef[2].AfsFileName[7] = '1';
        SoundAfsPatDef[4].AfsFileName[4] = '1';
    }
    else
    {
        SoundAfsPatDef[0].AfsFileName[3] = '2';
        SoundAfsPatDef[1].AfsFileName[5] = '2';
        SoundAfsPatDef[2].AfsFileName[7] = '2';
        SoundAfsPatDef[4].AfsFileName[4] = '2';
    }
    
    i = 0;

    WorkSize = 0;
    
    while (SoundAfsPatDef[i].AfsFileName != NULL) 
    {
        WorkSize += ADXF_CALC_PTINFO_SIZE(SoundAfsPatDef[i].MaxInsideFileNum); 
        
        i++;
    }
    
    pSoundAfs = syMalloc(WorkSize + ADXF_DEF_SCT_SIZE);
    
    p = pSoundAfs;
    
    pSpqList = (unsigned short*)p;
    
    p += ADXF_DEF_SCT_SIZE;
    
    QuickGetDiscTrayStatus();
    
    if (!(sys->ss_flg & 0x1)) 
    {
        if (ReadFileEx("MULTSPQ1.IDX", pSpqList) != 0) 
        {
            ExitApplication();
        }
    }
    else if (ReadFileEx("MULTSPQ2.IDX", pSpqList) != 0)
    {
        ExitApplication();
    }
    
    i = 0; 
    
    while (SoundAfsPatDef[i].AfsFileName != NULL)
    {
        SoundAfsPatDef[i].pInfoWork = p;
        
        p += ADXF_CALC_PTINFO_SIZE(SoundAfsPatDef[i].MaxInsideFileNum); 
        
        i++; 
    }
    
    QuickGetDiscTrayStatus();
    
    if (CreatePartitionEx(SoundAfsPatDef) != 0) 
    {
        ExitApplication();
    }
    
    PatId[0] = SoundAfsPatDef[0].PartitionId;
    PatId[1] = SoundAfsPatDef[1].PartitionId;
    PatId[2] = SoundAfsPatDef[2].PartitionId;
    PatId[3] = SoundAfsPatDef[3].PartitionId;
    
    sys->itm_partid = SoundAfsPatDef[4].PartitionId;
    sys->dor_partid = SoundAfsPatDef[5].PartitionId;
    sys->sys_partid = SoundAfsPatDef[6].PartitionId;
    
    return 0;
}

// 100% matching!
void UnmountSoundAfs()
{ 
    if (PatId[0] != -1) 
    { 
        DeletePartitionEx(SoundAfsPatDef); 
        
        syFree(pSoundAfs); 
        
        PatId[0] = PatId[1] = PatId[2] = PatId[3] = -1; 
    }
} 

// 100% matching! 
void ExecSoundSynchProgram()
{
    if (SoundInitLevel < 0) 
    {
        sdSysServer();
        
        if ((SpqFileReadRequestFlag != 0) && (LoadSoundPackFile(SpqFileName) <= 0)) 
        {
            SpqFileReadRequestFlag = 0;
        }
        
        ExecTransSoundData();
        
        ExecSoundFadeManager();
        ExecSoundPanManager();
        
        if (!(sys->ss_flg & 0x4000000)) 
        {
            ExecAdxFadeManager();
        }
        
        KeyReadSwitch = (KeyReadSwitch != 0) ^ 1;
        
        ExecFileManager();
        
        ExecAdjustDisplay();
    }
}

// 100% matching!
void InitGameSoundSystem() {
    int i;

    SetVolumeMidi2(0, -127, 0);
    SetVolumeMidi2(1, -127, 0);
    ReqFadeBgmNo = 0;
    CurrentBgmNo = -1;
    CurrentBgmVolume = -0x7F;
    NextBgmVolume = -0x7F;

    for(i = 0; i < 2; i++) {
        CurrentBgSeNo[i] = -1;
        ReqFadeBgSe[i] = 0;
    }

    memset(&BgSePrmBuf, 0, 0x10);
    ResetEnemySeInfo();
    ResetObjectSeInfo();
    memset(&SoundCommand, 0, 8);
    CustomMidiSlotDef(1, 4);
    ResetRoomSoundEnvParam();
    ResetSoundComInfo();
    EventVibrationMode = 0;
}

/*// 
// Start address: 0x292d10
int SearchAfsInsideFileId(unsigned short KeyCode)
{
	unsigned short* lp;
	int i;
	// Line 728, Address: 0x292d10, Func Offset: 0
	// Line 729, Address: 0x292d20, Func Offset: 0x10
	// Line 730, Address: 0x292d30, Func Offset: 0x20
	// Line 732, Address: 0x292d38, Func Offset: 0x28
	// Line 733, Address: 0x292d40, Func Offset: 0x30
	// Line 735, Address: 0x292d48, Func Offset: 0x38
	// Line 737, Address: 0x292d58, Func Offset: 0x48
	// Line 738, Address: 0x292d5c, Func Offset: 0x4c
	// Func End, Address: 0x292d64, Func Offset: 0x54
}*/

// 100% matching!
void StopThePsgSound(void) {
    if (CheckPlayMidi(0) != 0) {
        StopBackGroundSeEx(0, 0);
    }
    if (CheckPlayMidi(1) != 0) {
        StopBackGroundSeEx(1, 0);
    }
}

// 
// 100% matching!
int CheckSpecialBank(int Type, int BankNo)
{
    while(TRUE)
    {
        if ((Type != 0) || (BankNo != 3)) 
        {
            if ((Type != 1 || BankNo != 3)) 
            {
                break;
            }
        }
        
        if ((ReqFadeBgSe[0] & 2) || ((ReqFadeBgSe[1]) & 2)) 
        {
            StopThePsgSound();
            return 0;
        }
    
        if (CurrentBgSeNo[0] == -1) 
        {
            if (CurrentBgSeNo[1] == -1) 
            {
                StopThePsgSound();
                return 0;
            }
        }     
        
        return 1;
    }
    
    return 0;
}

// 
// Start address: 0x292e80
int LoadSoundPackFile(char* SpqFile)
{
	int InsideId;
	int FileSize;
	// Line 812, Address: 0x292e80, Func Offset: 0
	// Line 816, Address: 0x292e90, Func Offset: 0x10
	// Line 819, Address: 0x292ecc, Func Offset: 0x4c
	// Line 820, Address: 0x292ee0, Func Offset: 0x60
	// Line 821, Address: 0x292ef0, Func Offset: 0x70
	// Line 824, Address: 0x292ef8, Func Offset: 0x78
	// Line 825, Address: 0x292f08, Func Offset: 0x88
	// Line 827, Address: 0x292f10, Func Offset: 0x90
	// Line 828, Address: 0x292f28, Func Offset: 0xa8
	// Line 834, Address: 0x292f30, Func Offset: 0xb0
	// Line 836, Address: 0x292f44, Func Offset: 0xc4
	// Line 837, Address: 0x292f58, Func Offset: 0xd8
	// Line 838, Address: 0x292f68, Func Offset: 0xe8
	// Line 839, Address: 0x292f70, Func Offset: 0xf0
	// Line 852, Address: 0x292f88, Func Offset: 0x108
	// Line 854, Address: 0x292f9c, Func Offset: 0x11c
	// Line 856, Address: 0x292fcc, Func Offset: 0x14c
	// Line 857, Address: 0x292fd4, Func Offset: 0x154
	// Line 856, Address: 0x292fdc, Func Offset: 0x15c
	// Line 857, Address: 0x292fe4, Func Offset: 0x164
	// Line 859, Address: 0x292fec, Func Offset: 0x16c
	// Line 864, Address: 0x292ff4, Func Offset: 0x174
	// Line 866, Address: 0x293000, Func Offset: 0x180
	// Line 867, Address: 0x293004, Func Offset: 0x184
	// Line 871, Address: 0x293010, Func Offset: 0x190
	// Line 872, Address: 0x293028, Func Offset: 0x1a8
	// Line 873, Address: 0x293038, Func Offset: 0x1b8
	// Line 878, Address: 0x293074, Func Offset: 0x1f4
	// Line 879, Address: 0x29307c, Func Offset: 0x1fc
	// Line 891, Address: 0x29309c, Func Offset: 0x21c
	// Line 890, Address: 0x2930a4, Func Offset: 0x224
	// Line 892, Address: 0x2930b0, Func Offset: 0x230
	// Line 891, Address: 0x2930b8, Func Offset: 0x238
	// Line 892, Address: 0x2930c4, Func Offset: 0x244
	// Line 898, Address: 0x2930dc, Func Offset: 0x25c
	// Line 899, Address: 0x2930ec, Func Offset: 0x26c
	// Line 901, Address: 0x2930f4, Func Offset: 0x274
	// Line 902, Address: 0x29310c, Func Offset: 0x28c
	// Line 903, Address: 0x29311c, Func Offset: 0x29c
	// Line 907, Address: 0x29312c, Func Offset: 0x2ac
	// Line 908, Address: 0x293140, Func Offset: 0x2c0
	// Line 912, Address: 0x293154, Func Offset: 0x2d4
	// Line 915, Address: 0x293160, Func Offset: 0x2e0
	// Line 917, Address: 0x293168, Func Offset: 0x2e8
	// Line 918, Address: 0x293170, Func Offset: 0x2f0
	// Line 920, Address: 0x293178, Func Offset: 0x2f8
	// Line 921, Address: 0x293180, Func Offset: 0x300
	// Line 922, Address: 0x293188, Func Offset: 0x308
	// Line 923, Address: 0x293194, Func Offset: 0x314
	// Line 927, Address: 0x2931a8, Func Offset: 0x328
	// Line 930, Address: 0x2931b4, Func Offset: 0x334
	// Line 932, Address: 0x2931bc, Func Offset: 0x33c
	// Line 933, Address: 0x2931c4, Func Offset: 0x344
	// Line 935, Address: 0x2931cc, Func Offset: 0x34c
	// Line 940, Address: 0x2931d8, Func Offset: 0x358
	// Line 941, Address: 0x2931dc, Func Offset: 0x35c
	// Func End, Address: 0x2931f0, Func Offset: 0x370
	scePrintf("LoadSoundPackFile - UNIMPLEMENTED!\n");
}

// 100% matching! 
void ExecTransSoundData()
{
    if (TransSoundPackDataFlag != 0)
    {
        switch (SdReadMode) 
        {                    
        case 0:
            SetSoundData(SdTypeDef[pSpqHeader->Type], pSpqHeader->BankNo, &pSdReadBuf[pSpqHeader->Offset], pSpqHeader->Size);
            
            SdReadMode++;
            return;
        case 1:
            if (CheckTransComplete(SdReadMode) == 0)
            {
                SdReadMode = 0;
                
                pSpqHeader++;
                
                if (pSpqHeader->Offset == 0) 
                {
                    TransSoundPackDataFlag = 0;
                }
            }
            
            return;
        }
    }
}

// 100% matching 
void RequestRoomSoundBank(int StageNo, int RoomNo, int CaseNo) {
    ResetRoomSoundEnvParam();
    sprintf(SpqFileName, "RM_%01u%02u%01u.SPQ", StageNo, RoomNo, CaseNo);
    SpqKeyCode = CaseNo + ((StageNo * 0x3E8) + (RoomNo * 0xA));
    SpqFileReadRequestFlag = 1;
}

// 100% matching
void RequestArmsSoundBank(int ArmsNo) {
    sprintf(SpqFileName, "ARMS_%03u.SPQ", ArmsNo);
    SpqKeyCode = ArmsNo | 0x4000;
    SpqFileReadRequestFlag = 2;
}

// 100% matching
void RequestDoorSoundBank(int DoorNo) {
    sprintf(SpqFileName, "DOOR_%03u.SPQ", DoorNo);
    CurrentDoorNo = DoorNo;
    SpqKeyCode = DoorNo | 0x8000;
    SpqFileReadRequestFlag = 3;
}

// 100% matching
void RequestPlayerVoiceSoundBank(int PlayerNo) {
    sprintf(SpqFileName, "CORE_%03u.SPQ", PlayerNo);
    SpqKeyCode = PlayerNo | 0xFFF0;
    SpqFileReadRequestFlag = 4;
}

//  100% matching
int CheckTransEndSoundBank() {
    return SpqFileReadRequestFlag;
}

// 100% matching
void SetRoomSoundCaseNo(int CaseNo) {
    RoomSoundCaseNo = CaseNo;
}

// 100% matching
int GetRoomSoundCaseNo() {
    int ReturnCode;
    
    ReturnCode = RoomSoundCaseNo;
    RoomSoundCaseNo = 0;
    
    return ReturnCode;
}

// 100% matching
int CustomMidiSlotDef(int ObjectSlot, int EventSlot) {
    if ((ObjectSlot + EventSlot) > 5) {
        MaxSlotObjectSe = 1;
        MaxSlotEventSe = 4;
        return 1;
    }
    
    if (ObjectSlot > 3) {
        MaxSlotObjectSe = 1;
        MaxSlotEventSe = 4;
        return 1;
    }
    
    MaxSlotObjectSe = ObjectSlot;
    MaxSlotEventSe = EventSlot;
    return 0;
}

// 100% matching! 
void ResetRoomSoundEnvParam()
{
    memset(&Room_SoundEnv, 0, sizeof(RM_SNDENV));
}

// 99.13% matching
int wadGetAngle(NJS_POINT3* pPos1, int Ang, NJS_POINT3* pPos2) {
    return (short)(Ang + (int)(10430.381f * atan2f(pPos1->x - pPos2->x,  pPos1->z - pPos2->z)));
}

// 100% matching
int CheckCollision4Sound(NJS_POINT3* pP2) {
    NJS_CAPSULE Capsule;
    int ReturnCode;

    ReturnCode = 0;
    if (rom->flg & 2) {
        Capsule.c1.x = cam.wpx;
        Capsule.c1.y = cam.wpy;
        Capsule.c1.z = cam.wpz;
        Capsule.c2.x = pP2->x;
        Capsule.c2.y = pP2->y;
        Capsule.c2.z = pP2->z;
        Capsule.r =  0.1;

        if (bhCheckC2Wall(&Capsule) != 0) {
            ReturnCode = -0x1C;
        }
    } 

    return ReturnCode;
}

/*// 
// Start address: 0x293640
int Get3DSoundParameter(_anon16* pP1, _anon16* pP2, char* pPan, char* pVol, float* pDist, int Mode)
{
	_anon16 pd;
	_anon28 ScreenPos;
	int Ang;
	int Val;
	int ReturnCode;
	// Line 1415, Address: 0x293640, Func Offset: 0
	// Line 1429, Address: 0x29367c, Func Offset: 0x3c
	// Line 1430, Address: 0x293688, Func Offset: 0x48
	// Line 1431, Address: 0x29369c, Func Offset: 0x5c
	// Line 1433, Address: 0x2936ac, Func Offset: 0x6c
	// Line 1434, Address: 0x2936bc, Func Offset: 0x7c
	// Line 1436, Address: 0x2936c8, Func Offset: 0x88
	// Line 1437, Address: 0x2936d0, Func Offset: 0x90
	// Line 1438, Address: 0x2936d8, Func Offset: 0x98
	// Line 1442, Address: 0x2936dc, Func Offset: 0x9c
	// Line 1443, Address: 0x2936f4, Func Offset: 0xb4
	// Line 1444, Address: 0x293720, Func Offset: 0xe0
	// Line 1445, Address: 0x293740, Func Offset: 0x100
	// Line 1446, Address: 0x293750, Func Offset: 0x110
	// Line 1445, Address: 0x29375c, Func Offset: 0x11c
	// Line 1446, Address: 0x293760, Func Offset: 0x120
	// Line 1448, Address: 0x293778, Func Offset: 0x138
	// Line 1450, Address: 0x293780, Func Offset: 0x140
	// Line 1456, Address: 0x2937c0, Func Offset: 0x180
	// Line 1457, Address: 0x2937c4, Func Offset: 0x184
	// Func End, Address: 0x2937f0, Func Offset: 0x1b0
}*/

// 
// Start address: 0x2937f0
int SetupSeGenericParm(int SlotNo, int SeNo, NJS_POINT3* pPos, int Flag, unsigned int Flag2)
{
	float Distance;
	int ReturnCode;
	// Line 1480, Address: 0x2937f0, Func Offset: 0
	// Line 1484, Address: 0x293804, Func Offset: 0x14
	// Line 1480, Address: 0x29380c, Func Offset: 0x1c
	// Line 1484, Address: 0x29381c, Func Offset: 0x2c
	// Line 1486, Address: 0x293840, Func Offset: 0x50
	// Line 1487, Address: 0x293844, Func Offset: 0x54
	// Line 1488, Address: 0x29384c, Func Offset: 0x5c
	// Line 1489, Address: 0x293850, Func Offset: 0x60
	// Line 1490, Address: 0x293858, Func Offset: 0x68
	// Line 1492, Address: 0x293864, Func Offset: 0x74
	// Line 1493, Address: 0x293874, Func Offset: 0x84
	// Line 1494, Address: 0x293878, Func Offset: 0x88
	// Line 1496, Address: 0x293884, Func Offset: 0x94
	// Line 1497, Address: 0x29388c, Func Offset: 0x9c
	// Line 1498, Address: 0x293894, Func Offset: 0xa4
	// Line 1500, Address: 0x29389c, Func Offset: 0xac
	// Line 1502, Address: 0x2938a8, Func Offset: 0xb8
	// Line 1503, Address: 0x2938b0, Func Offset: 0xc0
	// Line 1504, Address: 0x2938b8, Func Offset: 0xc8
	// Line 1506, Address: 0x2938c0, Func Offset: 0xd0
	// Line 1507, Address: 0x2938c8, Func Offset: 0xd8
	// Line 1508, Address: 0x2938d4, Func Offset: 0xe4
	// Line 1509, Address: 0x2938dc, Func Offset: 0xec
	// Line 1512, Address: 0x2938e4, Func Offset: 0xf4
	// Func End, Address: 0x293900, Func Offset: 0x110
    scePrintf("SetupSeGenericParm - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x293900
void Set3dSoundFlag(int Type, int SlotNo, unsigned int Flag)
{
	int No;
	// Line 1552, Address: 0x293900, Func Offset: 0
	// Line 1553, Address: 0x29390c, Func Offset: 0xc
	// Line 1552, Address: 0x293910, Func Offset: 0x10
	// Line 1553, Address: 0x293914, Func Offset: 0x14
	// Line 1555, Address: 0x293938, Func Offset: 0x38
	// Line 1556, Address: 0x29393c, Func Offset: 0x3c
	// Line 1557, Address: 0x293948, Func Offset: 0x48
	// Line 1559, Address: 0x293958, Func Offset: 0x58
	// Line 1560, Address: 0x293964, Func Offset: 0x64
	// Line 1562, Address: 0x293974, Func Offset: 0x74
	// Line 1564, Address: 0x29397c, Func Offset: 0x7c
	// Line 1565, Address: 0x293990, Func Offset: 0x90
	// Line 1566, Address: 0x2939a0, Func Offset: 0xa0
	// Line 1567, Address: 0x2939ac, Func Offset: 0xac
	// Line 1568, Address: 0x2939bc, Func Offset: 0xbc
	// Line 1570, Address: 0x2939cc, Func Offset: 0xcc
	// Line 1571, Address: 0x2939d8, Func Offset: 0xd8
	// Line 1572, Address: 0x2939e8, Func Offset: 0xe8
	// Line 1574, Address: 0x2939f8, Func Offset: 0xf8
	// Line 1576, Address: 0x293a00, Func Offset: 0x100
	// Line 1577, Address: 0x293a04, Func Offset: 0x104
	// Line 1578, Address: 0x293a10, Func Offset: 0x110
	// Line 1580, Address: 0x293a20, Func Offset: 0x120
	// Line 1581, Address: 0x293a2c, Func Offset: 0x12c
	// Line 1583, Address: 0x293a3c, Func Offset: 0x13c
	// Line 1585, Address: 0x293a44, Func Offset: 0x144
	// Line 1586, Address: 0x293a4c, Func Offset: 0x14c
	// Line 1587, Address: 0x293a54, Func Offset: 0x154
	// Line 1588, Address: 0x293a58, Func Offset: 0x158
	// Line 1589, Address: 0x293a64, Func Offset: 0x164
	// Line 1590, Address: 0x293a74, Func Offset: 0x174
	// Line 1591, Address: 0x293a84, Func Offset: 0x184
	// Line 1593, Address: 0x293a94, Func Offset: 0x194
	// Line 1594, Address: 0x293aa0, Func Offset: 0x1a0
	// Line 1595, Address: 0x293ab0, Func Offset: 0x1b0
	// Line 1596, Address: 0x293ac0, Func Offset: 0x1c0
	// Line 1598, Address: 0x293ad0, Func Offset: 0x1d0
	// Line 1600, Address: 0x293ad8, Func Offset: 0x1d8
	// Line 1601, Address: 0x293adc, Func Offset: 0x1dc
	// Line 1602, Address: 0x293ae8, Func Offset: 0x1e8
	// Line 1604, Address: 0x293af8, Func Offset: 0x1f8
	// Line 1605, Address: 0x293b04, Func Offset: 0x204
	// Line 1607, Address: 0x293b14, Func Offset: 0x214
	// Line 1609, Address: 0x293b1c, Func Offset: 0x21c
	// Line 1610, Address: 0x293b38, Func Offset: 0x238
	// Line 1609, Address: 0x293b3c, Func Offset: 0x23c
	// Line 1610, Address: 0x293b40, Func Offset: 0x240
	// Line 1611, Address: 0x293b48, Func Offset: 0x248
	// Line 1613, Address: 0x293b5c, Func Offset: 0x25c
	// Line 1614, Address: 0x293b68, Func Offset: 0x268
	// Line 1616, Address: 0x293b78, Func Offset: 0x278
	// Line 1618, Address: 0x293b80, Func Offset: 0x280
	// Line 1619, Address: 0x293ba0, Func Offset: 0x2a0
	// Line 1620, Address: 0x293bac, Func Offset: 0x2ac
	// Line 1625, Address: 0x293bc0, Func Offset: 0x2c0
	// Line 1627, Address: 0x293bc8, Func Offset: 0x2c8
	// Line 1628, Address: 0x293be4, Func Offset: 0x2e4
	// Line 1627, Address: 0x293be8, Func Offset: 0x2e8
	// Line 1628, Address: 0x293bec, Func Offset: 0x2ec
	// Line 1629, Address: 0x293bf4, Func Offset: 0x2f4
	// Line 1631, Address: 0x293c08, Func Offset: 0x308
	// Line 1632, Address: 0x293c14, Func Offset: 0x314
	// Line 1634, Address: 0x293c24, Func Offset: 0x324
	// Line 1639, Address: 0x293c2c, Func Offset: 0x32c
	// Line 1641, Address: 0x293c44, Func Offset: 0x344
	// Line 1639, Address: 0x293c48, Func Offset: 0x348
	// Line 1641, Address: 0x293c4c, Func Offset: 0x34c
	// Line 1642, Address: 0x293c5c, Func Offset: 0x35c
	// Line 1643, Address: 0x293c68, Func Offset: 0x368
	// Line 1645, Address: 0x293c88, Func Offset: 0x388
	// Line 1646, Address: 0x293c94, Func Offset: 0x394
	// Line 1650, Address: 0x293cb4, Func Offset: 0x3b4
	// Line 1661, Address: 0x293cbc, Func Offset: 0x3bc
	// Line 1662, Address: 0x293cc4, Func Offset: 0x3c4
	// Line 1672, Address: 0x293cd4, Func Offset: 0x3d4
	// Func End, Address: 0x293ce8, Func Offset: 0x3e8
}
*/

// 100% matching
void Reset3dSoundFlag(void) {
    int i;
    
    Set3dSoundFlag(0, 0, 0);

    for(i = 0; i < 3; i++) {
        Set3dSoundFlag(1, i, 0);
    }
    
    Set3dSoundFlag(2, 0, 0);
    Set3dSoundFlag(3, 0, 0);
    Set3dSoundFlag(4, 0, 0);

    for(i = 0; i < 6; i++) {
        Set3dSoundFlag(5, i, 0);
    }
    
    Set3dSoundFlag(6, 0, 0);
    Set3dSoundFlag(6, 1, 0);
    Set3dSoundFlag(6, 2, 0);

    for(i = 0; i < MaxSlotObjectSe; i++) {
        Set3dSoundFlag(7, i, 0);
    }

    for(i = 0; i < MaxSlotEventSe; i++) {
        Set3dSoundFlag(8, i, 0);
    }
    
    Set3dSoundFlag(9, 0, 0);
    Set3dSoundFlag(0xA, 0, 0);
    Set3dSoundFlag(0xB, 0, 0);
}

/*// 
// Start address: 0x293e60
void SetUserSoundVolume(int Type, int SlotNo, int StartVol, int LastVol, int Frame)
{
	// Line 1740, Address: 0x293e60, Func Offset: 0
	// Line 1741, Address: 0x293e74, Func Offset: 0x14
	// Line 1740, Address: 0x293e78, Func Offset: 0x18
	// Line 1741, Address: 0x293e84, Func Offset: 0x24
	// Line 1743, Address: 0x293ea8, Func Offset: 0x48
	// Line 1744, Address: 0x293ebc, Func Offset: 0x5c
	// Line 1746, Address: 0x293ed0, Func Offset: 0x70
	// Line 1748, Address: 0x293ed8, Func Offset: 0x78
	// Line 1749, Address: 0x293ef8, Func Offset: 0x98
	// Line 1750, Address: 0x293f0c, Func Offset: 0xac
	// Line 1752, Address: 0x293f20, Func Offset: 0xc0
	// Line 1754, Address: 0x293f28, Func Offset: 0xc8
	// Line 1755, Address: 0x293f3c, Func Offset: 0xdc
	// Line 1757, Address: 0x293f50, Func Offset: 0xf0
	// Line 1759, Address: 0x293f58, Func Offset: 0xf8
	// Line 1760, Address: 0x293f6c, Func Offset: 0x10c
	// Line 1761, Address: 0x293f80, Func Offset: 0x120
	// Line 1762, Address: 0x293f94, Func Offset: 0x134
	// Line 1764, Address: 0x293fa8, Func Offset: 0x148
	// Line 1766, Address: 0x293fb0, Func Offset: 0x150
	// Line 1767, Address: 0x293fc4, Func Offset: 0x164
	// Line 1769, Address: 0x293fd8, Func Offset: 0x178
	// Line 1771, Address: 0x293fe0, Func Offset: 0x180
	// Line 1772, Address: 0x294010, Func Offset: 0x1b0
	// Line 1774, Address: 0x294020, Func Offset: 0x1c0
	// Line 1776, Address: 0x294028, Func Offset: 0x1c8
	// Line 1777, Address: 0x294058, Func Offset: 0x1f8
	// Line 1779, Address: 0x294068, Func Offset: 0x208
	// Line 1781, Address: 0x294070, Func Offset: 0x210
	// Line 1782, Address: 0x2940a0, Func Offset: 0x240
	// Line 1784, Address: 0x2940b0, Func Offset: 0x250
	// Line 1786, Address: 0x2940b8, Func Offset: 0x258
	// Line 1787, Address: 0x2940e0, Func Offset: 0x280
	// Line 1788, Address: 0x2940f0, Func Offset: 0x290
	// Line 1789, Address: 0x294100, Func Offset: 0x2a0
	// Line 1790, Address: 0x294110, Func Offset: 0x2b0
	// Line 1792, Address: 0x294118, Func Offset: 0x2b8
	// Line 1799, Address: 0x294120, Func Offset: 0x2c0
	// Line 1800, Address: 0x294134, Func Offset: 0x2d4
	// Line 1809, Address: 0x294148, Func Offset: 0x2e8
	// Func End, Address: 0x294164, Func Offset: 0x304
}

// 
// Start address: 0x294170
void SetUserSoundPan(int Type, int SlotNo, int StartPan, int LastPan, int Frame)
{
	// Line 1841, Address: 0x294170, Func Offset: 0
	// Line 1842, Address: 0x294184, Func Offset: 0x14
	// Line 1841, Address: 0x294188, Func Offset: 0x18
	// Line 1842, Address: 0x294194, Func Offset: 0x24
	// Line 1844, Address: 0x2941b8, Func Offset: 0x48
	// Line 1845, Address: 0x2941cc, Func Offset: 0x5c
	// Line 1847, Address: 0x2941e0, Func Offset: 0x70
	// Line 1849, Address: 0x2941e8, Func Offset: 0x78
	// Line 1850, Address: 0x294208, Func Offset: 0x98
	// Line 1851, Address: 0x29421c, Func Offset: 0xac
	// Line 1853, Address: 0x294230, Func Offset: 0xc0
	// Line 1855, Address: 0x294238, Func Offset: 0xc8
	// Line 1856, Address: 0x29424c, Func Offset: 0xdc
	// Line 1858, Address: 0x294260, Func Offset: 0xf0
	// Line 1860, Address: 0x294268, Func Offset: 0xf8
	// Line 1861, Address: 0x29427c, Func Offset: 0x10c
	// Line 1862, Address: 0x294290, Func Offset: 0x120
	// Line 1863, Address: 0x2942a4, Func Offset: 0x134
	// Line 1865, Address: 0x2942b8, Func Offset: 0x148
	// Line 1867, Address: 0x2942c0, Func Offset: 0x150
	// Line 1868, Address: 0x2942d4, Func Offset: 0x164
	// Line 1870, Address: 0x2942e8, Func Offset: 0x178
	// Line 1872, Address: 0x2942f0, Func Offset: 0x180
	// Line 1873, Address: 0x294320, Func Offset: 0x1b0
	// Line 1875, Address: 0x294330, Func Offset: 0x1c0
	// Line 1877, Address: 0x294338, Func Offset: 0x1c8
	// Line 1878, Address: 0x294368, Func Offset: 0x1f8
	// Line 1880, Address: 0x294378, Func Offset: 0x208
	// Line 1882, Address: 0x294380, Func Offset: 0x210
	// Line 1883, Address: 0x2943a8, Func Offset: 0x238
	// Line 1884, Address: 0x2943b8, Func Offset: 0x248
	// Line 1885, Address: 0x2943c8, Func Offset: 0x258
	// Line 1886, Address: 0x2943d8, Func Offset: 0x268
	// Line 1897, Address: 0x2943e4, Func Offset: 0x274
	// Func End, Address: 0x294400, Func Offset: 0x290
}

// 
// Start address: 0x294400
void PlayGameSe4Event(_anon25* gp, _anon16* pPos, int FloorType, int SeType)
{
	int Flag;
	// Line 1947, Address: 0x294400, Func Offset: 0
	// Line 1950, Address: 0x294418, Func Offset: 0x18
	// Line 1951, Address: 0x294438, Func Offset: 0x38
	// Line 1953, Address: 0x29443c, Func Offset: 0x3c
	// Line 1954, Address: 0x29444c, Func Offset: 0x4c
	// Line 1956, Address: 0x294450, Func Offset: 0x50
	// Line 1958, Address: 0x29445c, Func Offset: 0x5c
	// Line 1959, Address: 0x29446c, Func Offset: 0x6c
	// Line 1961, Address: 0x294480, Func Offset: 0x80
	// Line 1962, Address: 0x294490, Func Offset: 0x90
	// Line 1965, Address: 0x2944a4, Func Offset: 0xa4
	// Line 1967, Address: 0x2944d0, Func Offset: 0xd0
	// Line 1968, Address: 0x2944d8, Func Offset: 0xd8
	// Line 1970, Address: 0x2944e0, Func Offset: 0xe0
	// Line 1971, Address: 0x2944f8, Func Offset: 0xf8
	// Line 1973, Address: 0x294500, Func Offset: 0x100
	// Line 1974, Address: 0x29450c, Func Offset: 0x10c
	// Line 1976, Address: 0x294514, Func Offset: 0x114
	// Line 1977, Address: 0x294524, Func Offset: 0x124
	// Line 1979, Address: 0x29452c, Func Offset: 0x12c
	// Line 1980, Address: 0x294538, Func Offset: 0x138
	// Line 1982, Address: 0x294540, Func Offset: 0x140
	// Line 1983, Address: 0x294550, Func Offset: 0x150
	// Line 1985, Address: 0x294558, Func Offset: 0x158
	// Line 1986, Address: 0x294564, Func Offset: 0x164
	// Line 1988, Address: 0x29456c, Func Offset: 0x16c
	// Line 1999, Address: 0x294580, Func Offset: 0x180
	// Func End, Address: 0x29459c, Func Offset: 0x19c
}*/

// 
// Start address: 0x2945a0
void CallSystemSeBasic(int SeNo, int Volume, int FxLevel)
{
	int SlotDef[2];
	// Line 2012, Address: 0x2945a0, Func Offset: 0
	// Line 2013, Address: 0x2945a4, Func Offset: 0x4
	// Line 2012, Address: 0x2945ac, Func Offset: 0xc
	// Line 2013, Address: 0x2945b0, Func Offset: 0x10
	// Line 2015, Address: 0x2945b8, Func Offset: 0x18
	// Line 2018, Address: 0x2945bc, Func Offset: 0x1c
	// Line 2015, Address: 0x2945c0, Func Offset: 0x20
	// Line 2013, Address: 0x2945c8, Func Offset: 0x28
	// Line 2015, Address: 0x2945cc, Func Offset: 0x2c
	// Line 2016, Address: 0x2945d0, Func Offset: 0x30
	// Line 2017, Address: 0x2945d8, Func Offset: 0x38
	// Line 2018, Address: 0x2945e0, Func Offset: 0x40
	// Line 2019, Address: 0x2945e8, Func Offset: 0x48
	// Line 2020, Address: 0x2945f0, Func Offset: 0x50
	// Line 2021, Address: 0x2945f8, Func Offset: 0x58
	// Line 2022, Address: 0x294600, Func Offset: 0x60
	// Line 2023, Address: 0x294608, Func Offset: 0x68
	// Line 2024, Address: 0x294610, Func Offset: 0x70
	// Line 2025, Address: 0x294618, Func Offset: 0x78
	// Line 2026, Address: 0x29461c, Func Offset: 0x7c
	// Line 2027, Address: 0x294624, Func Offset: 0x84
	// Line 2028, Address: 0x29462c, Func Offset: 0x8c
	// Line 2031, Address: 0x294634, Func Offset: 0x94
	// Line 2032, Address: 0x294644, Func Offset: 0xa4
	// Line 2033, Address: 0x29464c, Func Offset: 0xac
	// Line 2034, Address: 0x294658, Func Offset: 0xb8
	// Line 2035, Address: 0x294664, Func Offset: 0xc4
	// Line 2036, Address: 0x29466c, Func Offset: 0xcc
	// Line 2038, Address: 0x294674, Func Offset: 0xd4
	// Line 2036, Address: 0x29467c, Func Offset: 0xdc
	// Line 2037, Address: 0x294688, Func Offset: 0xe8
	// Line 2036, Address: 0x294698, Func Offset: 0xf8
	// Line 2038, Address: 0x29469c, Func Offset: 0xfc
	// Line 2040, Address: 0x2946a4, Func Offset: 0x104
	// Func End, Address: 0x2946b0, Func Offset: 0x110
	scePrintf("CallSystemSeBasic - UNIMPLEMENTED!\n");
}

// 100% matching 
void CallSystemSeEx(int SeNo, int Volume) {
    CallSystemSeBasic(SeNo, Volume, 0);
}

// 100% matching 
void CallSystemSe(int param, int SeNo) // first parameter is not present on the debugging symbols
{
    CallSystemSeEx(SeNo, 0);
}

// 100% matching
void StopSystemSe() {
    StopMidi(2);
}

// 100% matching
void SetSyukanModeSoundParam() {
    if (sys->gm_flg & 0x01000000) {
        RequestInfo.Volume = 0;
        RequestInfo.VolumeDelayTime = 0;
        RequestInfo.Pan = 0;
        RequestInfo.PanDelayTime = 0;
    }
}

// 100% matching
void CallPlayerVoice(int SeNo) {
    SetupSeGenericParm(7, SeNo, &PlayerPos, 1, GsSlotInfoSe[7].Flag);
    RequestInfo.PitchDelayTime = -2;
    if (!(GsSlotInfoSe[7].Flag & 2)) {
        RequestInfo.Volume += Room_SoundEnv.VolPlayerVoice;
    }
    ExPlaySe(&RequestInfo);
}


/*// 
// Start address: 0x2947b0
int GetPlayerActionSeSlotNo(int Type, int Id)
{
	int SlotDef[6];
	// Line 2135, Address: 0x2947b0, Func Offset: 0
	// Line 2134, Address: 0x2947bc, Func Offset: 0xc
	// Line 2135, Address: 0x2947c0, Func Offset: 0x10
	// Line 2140, Address: 0x2947c4, Func Offset: 0x14
	// Line 2135, Address: 0x2947c8, Func Offset: 0x18
	// Line 2140, Address: 0x2947d0, Func Offset: 0x20
	// Line 2145, Address: 0x2947f4, Func Offset: 0x44
	// Line 2155, Address: 0x294808, Func Offset: 0x58
	// Line 2145, Address: 0x29480c, Func Offset: 0x5c
	// Line 2155, Address: 0x294818, Func Offset: 0x68
	// Line 2160, Address: 0x294830, Func Offset: 0x80
	// Line 2162, Address: 0x294834, Func Offset: 0x84
	// Func End, Address: 0x29483c, Func Offset: 0x8c
}

// 
// Start address: 0x294840
void CallPlayerFootStepSeEx(int FloorType, int Type, int Flag, int Id, _anon16* pPos)
{
	float Distance;
	char FootDef[5];
	short RunPitchTbl[4];
	short WalkPitchTbl[4];
	// Line 2184, Address: 0x294840, Func Offset: 0
	// Line 2185, Address: 0x294854, Func Offset: 0x14
	// Line 2184, Address: 0x294858, Func Offset: 0x18
	// Line 2185, Address: 0x29485c, Func Offset: 0x1c
	// Line 2186, Address: 0x294874, Func Offset: 0x34
	// Line 2185, Address: 0x29487c, Func Offset: 0x3c
	// Line 2186, Address: 0x294880, Func Offset: 0x40
	// Line 2187, Address: 0x29488c, Func Offset: 0x4c
	// Line 2186, Address: 0x294898, Func Offset: 0x58
	// Line 2187, Address: 0x29489c, Func Offset: 0x5c
	// Line 2191, Address: 0x2948a0, Func Offset: 0x60
	// Line 2187, Address: 0x2948b0, Func Offset: 0x70
	// Line 2191, Address: 0x2948b4, Func Offset: 0x74
	// Line 2187, Address: 0x2948c4, Func Offset: 0x84
	// Line 2191, Address: 0x2948cc, Func Offset: 0x8c
	// Line 2192, Address: 0x2948d4, Func Offset: 0x94
	// Line 2198, Address: 0x2948dc, Func Offset: 0x9c
	// Line 2202, Address: 0x2948e4, Func Offset: 0xa4
	// Line 2199, Address: 0x2948ec, Func Offset: 0xac
	// Line 2200, Address: 0x2948f4, Func Offset: 0xb4
	// Line 2198, Address: 0x2948fc, Func Offset: 0xbc
	// Line 2199, Address: 0x294904, Func Offset: 0xc4
	// Line 2200, Address: 0x29490c, Func Offset: 0xcc
	// Line 2202, Address: 0x294910, Func Offset: 0xd0
	// Line 2203, Address: 0x294920, Func Offset: 0xe0
	// Line 2204, Address: 0x294928, Func Offset: 0xe8
	// Line 2206, Address: 0x294930, Func Offset: 0xf0
	// Line 2207, Address: 0x294938, Func Offset: 0xf8
	// Line 2210, Address: 0x29496c, Func Offset: 0x12c
	// Line 2209, Address: 0x294974, Func Offset: 0x134
	// Line 2210, Address: 0x29497c, Func Offset: 0x13c
	// Line 2211, Address: 0x294980, Func Offset: 0x140
	// Line 2212, Address: 0x2949d4, Func Offset: 0x194
	// Line 2213, Address: 0x2949d8, Func Offset: 0x198
	// Line 2222, Address: 0x2949e0, Func Offset: 0x1a0
	// Line 2221, Address: 0x2949e8, Func Offset: 0x1a8
	// Line 2222, Address: 0x2949f0, Func Offset: 0x1b0
	// Line 2223, Address: 0x2949f4, Func Offset: 0x1b4
	// Line 2224, Address: 0x294a48, Func Offset: 0x208
	// Line 2225, Address: 0x294a4c, Func Offset: 0x20c
	// Line 2233, Address: 0x294a54, Func Offset: 0x214
	// Line 2235, Address: 0x294a5c, Func Offset: 0x21c
	// Line 2236, Address: 0x294a68, Func Offset: 0x228
	// Line 2237, Address: 0x294a70, Func Offset: 0x230
	// Line 2245, Address: 0x294a78, Func Offset: 0x238
	// Line 2246, Address: 0x294a84, Func Offset: 0x244
	// Line 2247, Address: 0x294a8c, Func Offset: 0x24c
	// Line 2251, Address: 0x294a98, Func Offset: 0x258
	// Line 2252, Address: 0x294abc, Func Offset: 0x27c
	// Line 2253, Address: 0x294ac4, Func Offset: 0x284
	// Line 2254, Address: 0x294acc, Func Offset: 0x28c
	// Line 2256, Address: 0x294ad4, Func Offset: 0x294
	// Line 2257, Address: 0x294af8, Func Offset: 0x2b8
	// Line 2258, Address: 0x294b00, Func Offset: 0x2c0
	// Line 2259, Address: 0x294b08, Func Offset: 0x2c8
	// Line 2261, Address: 0x294b0c, Func Offset: 0x2cc
	// Line 2262, Address: 0x294b14, Func Offset: 0x2d4
	// Line 2263, Address: 0x294b1c, Func Offset: 0x2dc
	// Line 2264, Address: 0x294b24, Func Offset: 0x2e4
	// Line 2265, Address: 0x294b2c, Func Offset: 0x2ec
	// Line 2268, Address: 0x294b34, Func Offset: 0x2f4
	// Line 2269, Address: 0x294b58, Func Offset: 0x318
	// Line 2272, Address: 0x294b74, Func Offset: 0x334
	// Line 2273, Address: 0x294b80, Func Offset: 0x340
	// Func End, Address: 0x294b9c, Func Offset: 0x35c
}*/

// 100% matching 
void CallPlayerFootStepSe(int FloorType, int Type, int Flag) {
    CallPlayerFootStepSeEx(FloorType, Type, Flag, 0, &PlayerPos);
}

// 100% matching
void CallPlayerActionSe(int SeNo, int Flag) {
    CallPlayerFootStepSeEx(SeNo, 3, Flag, 0, &PlayerPos);
}


/*// 
// Start address: 0x294bd0
void CallPlayerWeaponSeEx(_anon16* pPos, int SeNo, int SlotNo)
{
	int NeoSlotNo;
	int SlotDef[2];
	// Line 2315, Address: 0x294bd0, Func Offset: 0
	// Line 2316, Address: 0x294bd4, Func Offset: 0x4
	// Line 2315, Address: 0x294bd8, Func Offset: 0x8
	// Line 2316, Address: 0x294bdc, Func Offset: 0xc
	// Line 2315, Address: 0x294be0, Func Offset: 0x10
	// Line 2316, Address: 0x294be8, Func Offset: 0x18
	// Line 2319, Address: 0x294bf0, Func Offset: 0x20
	// Line 2316, Address: 0x294bf4, Func Offset: 0x24
	// Line 2319, Address: 0x294bf8, Func Offset: 0x28
	// Line 2323, Address: 0x294c08, Func Offset: 0x38
	// Line 2325, Address: 0x294c14, Func Offset: 0x44
	// Line 2326, Address: 0x294c1c, Func Offset: 0x4c
	// Line 2327, Address: 0x294c30, Func Offset: 0x60
	// Line 2328, Address: 0x294c3c, Func Offset: 0x6c
	// Line 2329, Address: 0x294c44, Func Offset: 0x74
	// Line 2331, Address: 0x294c48, Func Offset: 0x78
	// Line 2332, Address: 0x294c64, Func Offset: 0x94
	// Line 2334, Address: 0x294c6c, Func Offset: 0x9c
	// Line 2336, Address: 0x294c78, Func Offset: 0xa8
	// Line 2337, Address: 0x294c88, Func Offset: 0xb8
	// Line 2340, Address: 0x294ca4, Func Offset: 0xd4
	// Line 2341, Address: 0x294cb0, Func Offset: 0xe0
	// Func End, Address: 0x294cc0, Func Offset: 0xf0
}

// 
// Start address: 0x294cc0
void CallYakkyouSe(_anon16* pPos, int SeNo)
{
	// Line 2361, Address: 0x294cc0, Func Offset: 0
	// Line 2362, Address: 0x294ccc, Func Offset: 0xc
	// Line 2368, Address: 0x294ce0, Func Offset: 0x20
	// Line 2366, Address: 0x294ce8, Func Offset: 0x28
	// Line 2368, Address: 0x294cf4, Func Offset: 0x34
	// Line 2369, Address: 0x294d04, Func Offset: 0x44
	// Line 2371, Address: 0x294d2c, Func Offset: 0x6c
	// Line 2369, Address: 0x294d34, Func Offset: 0x74
	// Line 2371, Address: 0x294d48, Func Offset: 0x88
	// Line 2369, Address: 0x294d4c, Func Offset: 0x8c
	// Line 2371, Address: 0x294d54, Func Offset: 0x94
	// Line 2372, Address: 0x294d5c, Func Offset: 0x9c
	// Line 2375, Address: 0x294d78, Func Offset: 0xb8
	// Line 2376, Address: 0x294d84, Func Offset: 0xc4
	// Func End, Address: 0x294d90, Func Offset: 0xd0
}

// 
// Start address: 0x294d90
void CallBackGroundSeEx(unsigned int SlotNo, int SeNo, short Timer)
{
	int SlotDef[3];
	// Line 2386, Address: 0x294d90, Func Offset: 0
	// Line 2387, Address: 0x294da0, Func Offset: 0x10
	// Line 2386, Address: 0x294da4, Func Offset: 0x14
	// Line 2387, Address: 0x294da8, Func Offset: 0x18
	// Line 2391, Address: 0x294dc0, Func Offset: 0x30
	// Line 2389, Address: 0x294dc4, Func Offset: 0x34
	// Line 2387, Address: 0x294dd0, Func Offset: 0x40
	// Line 2389, Address: 0x294dd4, Func Offset: 0x44
	// Line 2387, Address: 0x294dd8, Func Offset: 0x48
	// Line 2391, Address: 0x294ddc, Func Offset: 0x4c
	// Line 2392, Address: 0x294de8, Func Offset: 0x58
	// Line 2393, Address: 0x294dfc, Func Offset: 0x6c
	// Line 2394, Address: 0x294e0c, Func Offset: 0x7c
	// Line 2396, Address: 0x294e1c, Func Offset: 0x8c
	// Line 2399, Address: 0x294e24, Func Offset: 0x94
	// Line 2400, Address: 0x294e34, Func Offset: 0xa4
	// Line 2404, Address: 0x294e48, Func Offset: 0xb8
	// Line 2405, Address: 0x294e54, Func Offset: 0xc4
	// Line 2410, Address: 0x294e70, Func Offset: 0xe0
	// Line 2411, Address: 0x294e78, Func Offset: 0xe8
	// Line 2414, Address: 0x294e84, Func Offset: 0xf4
	// Line 2418, Address: 0x294e94, Func Offset: 0x104
	// Line 2415, Address: 0x294e98, Func Offset: 0x108
	// Line 2414, Address: 0x294e9c, Func Offset: 0x10c
	// Line 2415, Address: 0x294ea0, Func Offset: 0x110
	// Line 2416, Address: 0x294eac, Func Offset: 0x11c
	// Line 2417, Address: 0x294eb4, Func Offset: 0x124
	// Line 2418, Address: 0x294ebc, Func Offset: 0x12c
	// Line 2419, Address: 0x294ec4, Func Offset: 0x134
	// Line 2420, Address: 0x294ecc, Func Offset: 0x13c
	// Line 2421, Address: 0x294ed8, Func Offset: 0x148
	// Line 2422, Address: 0x294ee0, Func Offset: 0x150
	// Line 2424, Address: 0x294eec, Func Offset: 0x15c
	// Line 2425, Address: 0x294efc, Func Offset: 0x16c
	// Func End, Address: 0x294f14, Func Offset: 0x184
}*/

// 100% matching
void CallBackGroundSe(unsigned int SlotNo, int SeNo) {
    CallBackGroundSeEx(SlotNo, SeNo, 0);
}

// 100% matching
void CallBackGroundSe2(unsigned int SlotNo, int SeNo) {
    if( SeNo != CurrentBgSeNo[SlotNo]) {
        ReqFadeBgSe[SlotNo] |= 2;
        CurrentBgSeNo[SlotNo] = SeNo;
    }
}

/*// 
// Start address: 0x294f70
void StopBackGroundSeEx(unsigned int SlotNo, short Timer)
{
	int SlotDef[3];
	// Line 2460, Address: 0x294f70, Func Offset: 0
	// Line 2463, Address: 0x294f74, Func Offset: 0x4
	// Line 2460, Address: 0x294f78, Func Offset: 0x8
	// Line 2461, Address: 0x294f84, Func Offset: 0x14
	// Line 2463, Address: 0x294f9c, Func Offset: 0x2c
	// Line 2461, Address: 0x294fa0, Func Offset: 0x30
	// Line 2463, Address: 0x294fa4, Func Offset: 0x34
	// Line 2464, Address: 0x294fac, Func Offset: 0x3c
	// Line 2465, Address: 0x294fc0, Func Offset: 0x50
	// Line 2466, Address: 0x294fc8, Func Offset: 0x58
	// Line 2468, Address: 0x294fd8, Func Offset: 0x68
	// Line 2469, Address: 0x294ff0, Func Offset: 0x80
	// Func End, Address: 0x295000, Func Offset: 0x90
}*/

// 100% matching
void StopBackGroundSe2(unsigned int SlotNo) {
    ReqFadeBgSe[SlotNo] = 1;
    CurrentBgSeNo[SlotNo] = -1;
}

/*// 
// Start address: 0x295030
void CallDoorSe(unsigned int No)
{
	unsigned char DoorFxDef[40];
	// Line 2502, Address: 0x295030, Func Offset: 0
	// Line 2503, Address: 0x295034, Func Offset: 0x4
	// Line 2502, Address: 0x29503c, Func Offset: 0xc
	// Line 2503, Address: 0x295040, Func Offset: 0x10
	// Line 2511, Address: 0x295050, Func Offset: 0x20
	// Line 2503, Address: 0x295058, Func Offset: 0x28
	// Line 2511, Address: 0x295064, Func Offset: 0x34
	// Line 2512, Address: 0x295068, Func Offset: 0x38
	// Line 2513, Address: 0x295074, Func Offset: 0x44
	// Line 2514, Address: 0x29507c, Func Offset: 0x4c
	// Line 2515, Address: 0x295084, Func Offset: 0x54
	// Line 2516, Address: 0x295090, Func Offset: 0x60
	// Line 2517, Address: 0x295098, Func Offset: 0x68
	// Line 2522, Address: 0x2950a0, Func Offset: 0x70
	// Line 2518, Address: 0x2950a8, Func Offset: 0x78
	// Line 2526, Address: 0x2950b4, Func Offset: 0x84
	// Line 2522, Address: 0x2950bc, Func Offset: 0x8c
	// Line 2521, Address: 0x2950c4, Func Offset: 0x94
	// Line 2522, Address: 0x2950cc, Func Offset: 0x9c
	// Line 2526, Address: 0x2950d4, Func Offset: 0xa4
	// Line 2531, Address: 0x2950d8, Func Offset: 0xa8
	// Line 2526, Address: 0x2950dc, Func Offset: 0xac
	// Line 2531, Address: 0x2950e0, Func Offset: 0xb0
	// Line 2526, Address: 0x2950e4, Func Offset: 0xb4
	// Line 2531, Address: 0x2950f4, Func Offset: 0xc4
	// Line 2532, Address: 0x2950fc, Func Offset: 0xcc
	// Func End, Address: 0x295108, Func Offset: 0xd8
}

// 
// Start address: 0x295110
void RequestEnemySeBasic(int EnemyNo, _anon16* pPos, int SeNo, int Flag, int FadeRate)
{
	char VolDownTbl[8];
	_anon2* eip;
	// Line 2550, Address: 0x295110, Func Offset: 0
	// Line 2552, Address: 0x295124, Func Offset: 0x14
	// Line 2550, Address: 0x29512c, Func Offset: 0x1c
	// Line 2552, Address: 0x295130, Func Offset: 0x20
	// Line 2554, Address: 0x295148, Func Offset: 0x38
	// Line 2557, Address: 0x295150, Func Offset: 0x40
	// Line 2555, Address: 0x295154, Func Offset: 0x44
	// Line 2557, Address: 0x29515c, Func Offset: 0x4c
	// Line 2555, Address: 0x295160, Func Offset: 0x50
	// Line 2557, Address: 0x295168, Func Offset: 0x58
	// Line 2558, Address: 0x29516c, Func Offset: 0x5c
	// Line 2557, Address: 0x295178, Func Offset: 0x68
	// Line 2558, Address: 0x295180, Func Offset: 0x70
	// Line 2557, Address: 0x295188, Func Offset: 0x78
	// Line 2558, Address: 0x29518c, Func Offset: 0x7c
	// Line 2560, Address: 0x295194, Func Offset: 0x84
	// Line 2561, Address: 0x2951a0, Func Offset: 0x90
	// Line 2560, Address: 0x2951b0, Func Offset: 0xa0
	// Line 2561, Address: 0x2951b8, Func Offset: 0xa8
	// Line 2564, Address: 0x2951c0, Func Offset: 0xb0
	// Line 2561, Address: 0x2951cc, Func Offset: 0xbc
	// Line 2562, Address: 0x2951d4, Func Offset: 0xc4
	// Line 2564, Address: 0x2951d8, Func Offset: 0xc8
	// Line 2565, Address: 0x2951e8, Func Offset: 0xd8
	// Line 2568, Address: 0x2951ec, Func Offset: 0xdc
	// Line 2570, Address: 0x2951fc, Func Offset: 0xec
	// Line 2569, Address: 0x295200, Func Offset: 0xf0
	// Line 2570, Address: 0x295204, Func Offset: 0xf4
	// Line 2572, Address: 0x295208, Func Offset: 0xf8
	// Line 2574, Address: 0x295210, Func Offset: 0x100
	// Line 2573, Address: 0x295214, Func Offset: 0x104
	// Line 2574, Address: 0x295218, Func Offset: 0x108
	// Line 2575, Address: 0x29521c, Func Offset: 0x10c
	// Line 2577, Address: 0x295220, Func Offset: 0x110
	// Func End, Address: 0x29523c, Func Offset: 0x12c
}

// 
// Start address: 0x295240
void RequestEnemySe(int EnemyNo, _anon16* pPos, int SeNo)
{
	// Line 2588, Address: 0x295240, Func Offset: 0
	// Func End, Address: 0x29524c, Func Offset: 0xc
}

// 
// Start address: 0x295250
void RequestEnemySeEx(int EnemyNo, _anon16* pPos, int SeNo, int FadeRate)
{
	// Line 2618, Address: 0x295254, Func Offset: 0x4
	// Func End, Address: 0x29525c, Func Offset: 0xc
}

// 
// Start address: 0x295260
int ChechPlayEnemySe(int EnemyNo, int SeNo)
{
	EnemySlot* esp;
	int i;
	// Line 2634, Address: 0x295260, Func Offset: 0
	// Line 2635, Address: 0x29526c, Func Offset: 0xc
	// Line 2636, Address: 0x295278, Func Offset: 0x18
	// Line 2637, Address: 0x295284, Func Offset: 0x24
	// Line 2638, Address: 0x29528c, Func Offset: 0x2c
	// Line 2640, Address: 0x295294, Func Offset: 0x34
	// Line 2641, Address: 0x2952a0, Func Offset: 0x40
	// Line 2646, Address: 0x2952a8, Func Offset: 0x48
	// Line 2648, Address: 0x2952b8, Func Offset: 0x58
	// Line 2649, Address: 0x2952bc, Func Offset: 0x5c
	// Func End, Address: 0x2952c4, Func Offset: 0x64
}*/

// 100% matching
void AllStopEnemySe(void) {
    int i;
    EnemySlot* esp;

    esp = &EnemySlotInfo[0];
    for(i = 0; i < 6; i++, esp++) {
        if (esp->Flag != 0) {
            RequestSeFadeFunction(DefEne[i], 2, 0xC8);
        } else {
            StopEnemySe(i);
        }
        
        esp->EnemyNo = 0;
        esp->SeNo = 0;
        esp->Flag = 0;
    }

    StopVibrationEx();
}

/*// 
// Start address: 0x295370
void CallEnemySe(int SlotNo, _anon16* pPos, int SeNo)
{
	int SlotDef[6];
	// Line 2686, Address: 0x295370, Func Offset: 0
	// Line 2687, Address: 0x295374, Func Offset: 0x4
	// Line 2686, Address: 0x295378, Func Offset: 0x8
	// Line 2687, Address: 0x29537c, Func Offset: 0xc
	// Line 2686, Address: 0x295380, Func Offset: 0x10
	// Line 2687, Address: 0x295388, Func Offset: 0x18
	// Line 2689, Address: 0x295394, Func Offset: 0x24
	// Line 2687, Address: 0x2953a4, Func Offset: 0x34
	// Line 2691, Address: 0x2953a8, Func Offset: 0x38
	// Line 2687, Address: 0x2953ac, Func Offset: 0x3c
	// Line 2691, Address: 0x2953b0, Func Offset: 0x40
	// Line 2693, Address: 0x2953d8, Func Offset: 0x68
	// Line 2694, Address: 0x2953e8, Func Offset: 0x78
	// Line 2697, Address: 0x295404, Func Offset: 0x94
	// Line 2698, Address: 0x295410, Func Offset: 0xa0
	// Func End, Address: 0x295420, Func Offset: 0xb0
}
*/

// 
// Start address: 0x295420
void StopEnemySe(int SlotNo)
{
	// Line 2709, Address: 0x295420, Func Offset: 0
	// Func End, Address: 0x295438, Func Offset: 0x18
	scePrintf("StopEnemySe - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x295440
int CallNativeEventSe(int SlotNo, _anon16* pPos, int SeNo, int Mode)
{
	int SlotDef[5];
	float Distance;
	// Line 2781, Address: 0x295440, Func Offset: 0
	// Line 2783, Address: 0x295444, Func Offset: 0x4
	// Line 2781, Address: 0x29544c, Func Offset: 0xc
	// Line 2783, Address: 0x295450, Func Offset: 0x10
	// Line 2785, Address: 0x295458, Func Offset: 0x18
	// Line 2783, Address: 0x29545c, Func Offset: 0x1c
	// Line 2785, Address: 0x295468, Func Offset: 0x28
	// Line 2786, Address: 0x295478, Func Offset: 0x38
	// Line 2791, Address: 0x295480, Func Offset: 0x40
	// Line 2789, Address: 0x295490, Func Offset: 0x50
	// Line 2791, Address: 0x2954a0, Func Offset: 0x60
	// Line 2792, Address: 0x2954a4, Func Offset: 0x64
	// Line 2791, Address: 0x2954a8, Func Offset: 0x68
	// Line 2792, Address: 0x2954ac, Func Offset: 0x6c
	// Line 2793, Address: 0x2954b8, Func Offset: 0x78
	// Line 2794, Address: 0x2954c0, Func Offset: 0x80
	// Line 2795, Address: 0x2954c8, Func Offset: 0x88
	// Line 2796, Address: 0x2954d4, Func Offset: 0x94
	// Line 2797, Address: 0x2954e0, Func Offset: 0xa0
	// Line 2799, Address: 0x2954e4, Func Offset: 0xa4
	// Line 2801, Address: 0x295500, Func Offset: 0xc0
	// Line 2802, Address: 0x295524, Func Offset: 0xe4
	// Line 2803, Address: 0x29552c, Func Offset: 0xec
	// Line 2804, Address: 0x295530, Func Offset: 0xf0
	// Line 2806, Address: 0x295538, Func Offset: 0xf8
	// Line 2807, Address: 0x295540, Func Offset: 0x100
	// Line 2808, Address: 0x295560, Func Offset: 0x120
	// Line 2809, Address: 0x295564, Func Offset: 0x124
	// Line 2810, Address: 0x29556c, Func Offset: 0x12c
	// Line 2815, Address: 0x295574, Func Offset: 0x134
	// Line 2817, Address: 0x295580, Func Offset: 0x140
	// Line 2818, Address: 0x295584, Func Offset: 0x144
	// Func End, Address: 0x295590, Func Offset: 0x150
}

// 
// Start address: 0x295590
int StopNativeEventSe(int SlotNo)
{
	int SlotDef[5];
	// Line 2827, Address: 0x295590, Func Offset: 0
	// Line 2828, Address: 0x295594, Func Offset: 0x4
	// Line 2827, Address: 0x29559c, Func Offset: 0xc
	// Line 2828, Address: 0x2955a0, Func Offset: 0x10
	// Line 2830, Address: 0x2955a8, Func Offset: 0x18
	// Line 2828, Address: 0x2955ac, Func Offset: 0x1c
	// Line 2830, Address: 0x2955b8, Func Offset: 0x28
	// Line 2831, Address: 0x2955c8, Func Offset: 0x38
	// Line 2834, Address: 0x2955d0, Func Offset: 0x40
	// Line 2836, Address: 0x2955e0, Func Offset: 0x50
	// Line 2837, Address: 0x2955e4, Func Offset: 0x54
	// Func End, Address: 0x2955f0, Func Offset: 0x60
}
*/

// 
// Start address: 0x2955f0
void RequestObjectSeEx(int ObjectNo, NJS_POINT3* pPos, int SeNo, int Prio, int Type)
{
	_anon35* oip;
	// Line 2851, Address: 0x2955f0, Func Offset: 0
	// Line 2854, Address: 0x295600, Func Offset: 0x10
	// Line 2855, Address: 0x295608, Func Offset: 0x18
	// Line 2859, Address: 0x295618, Func Offset: 0x28
	// Line 2860, Address: 0x295620, Func Offset: 0x30
	// Line 2861, Address: 0x29563c, Func Offset: 0x4c
	// Line 2862, Address: 0x295644, Func Offset: 0x54
	// Line 2865, Address: 0x295660, Func Offset: 0x70
	// Line 2866, Address: 0x295668, Func Offset: 0x78
	// Line 2871, Address: 0x29567c, Func Offset: 0x8c
	// Line 2873, Address: 0x295684, Func Offset: 0x94
	// Line 2874, Address: 0x29568c, Func Offset: 0x9c
	// Func End, Address: 0x2956a0, Func Offset: 0xb0
	scePrintf("RequestObjectSeEx - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2956a0
void RegistObjectSe(int ObjectNo, _anon16* pPos, int SeNo, int Prio)
{
	_anon35* oip;
	int i;
	// Line 2904, Address: 0x2956a0, Func Offset: 0
	// Line 2909, Address: 0x2956a8, Func Offset: 0x8
	// Line 2905, Address: 0x2956ac, Func Offset: 0xc
	// Line 2909, Address: 0x2956bc, Func Offset: 0x1c
	// Line 2910, Address: 0x2956c0, Func Offset: 0x20
	// Line 2907, Address: 0x2956c4, Func Offset: 0x24
	// Line 2914, Address: 0x2956d4, Func Offset: 0x34
	// Line 2910, Address: 0x2956d8, Func Offset: 0x38
	// Line 2911, Address: 0x2956dc, Func Offset: 0x3c
	// Line 2916, Address: 0x2956e4, Func Offset: 0x44
	// Line 2919, Address: 0x2956e8, Func Offset: 0x48
	// Line 2911, Address: 0x2956f0, Func Offset: 0x50
	// Line 2912, Address: 0x2956f4, Func Offset: 0x54
	// Line 2913, Address: 0x2956f8, Func Offset: 0x58
	// Line 2914, Address: 0x2956fc, Func Offset: 0x5c
	// Line 2915, Address: 0x295700, Func Offset: 0x60
	// Line 2916, Address: 0x295704, Func Offset: 0x64
	// Line 2919, Address: 0x295708, Func Offset: 0x68
	// Line 2920, Address: 0x295714, Func Offset: 0x74
	// Line 2923, Address: 0x295724, Func Offset: 0x84
	// Line 2926, Address: 0x295734, Func Offset: 0x94
	// Line 2927, Address: 0x295744, Func Offset: 0xa4
	// Line 2928, Address: 0x295758, Func Offset: 0xb8
	// Func End, Address: 0x295760, Func Offset: 0xc0
	scePrintf("RegistObjectSe - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x295760
void FreeObjectSe(int ObjectNo)
{
	_anon35* oip;
	int Flag;
	int i;
	// Line 2941, Address: 0x295760, Func Offset: 0
	// Line 2942, Address: 0x295768, Func Offset: 0x8
	// Line 2936, Address: 0x295778, Func Offset: 0x18
	// Line 2944, Address: 0x29577c, Func Offset: 0x1c
	// Line 2936, Address: 0x295780, Func Offset: 0x20
	// Line 2944, Address: 0x295784, Func Offset: 0x24
	// Line 2945, Address: 0x295788, Func Offset: 0x28
	// Line 2948, Address: 0x29578c, Func Offset: 0x2c
	// Line 2938, Address: 0x29579c, Func Offset: 0x3c
	// Line 2948, Address: 0x2957a0, Func Offset: 0x40
	// Line 2949, Address: 0x2957a8, Func Offset: 0x48
	// Line 2950, Address: 0x2957b4, Func Offset: 0x54
	// Line 2952, Address: 0x2957b8, Func Offset: 0x58
	// Line 2953, Address: 0x2957c0, Func Offset: 0x60
	// Line 2955, Address: 0x2957cc, Func Offset: 0x6c
	// Line 2956, Address: 0x2957dc, Func Offset: 0x7c
	// Line 2957, Address: 0x2957e4, Func Offset: 0x84
	// Line 2960, Address: 0x2957f8, Func Offset: 0x98
	// Line 2961, Address: 0x29580c, Func Offset: 0xac
	// Line 2963, Address: 0x295824, Func Offset: 0xc4
	// Func End, Address: 0x295830, Func Offset: 0xd0
	scePrintf("FreeObjectSe - UNIMPLEMENTED!\n");
}

// 100% matching!
void PlayBgmEx2(unsigned int PatId, int BgmNo, int FadeInRate, int Volume)
{
    if (!(sys->ss_flg & 0x4000000)) 
    {
        if (GetAdxStatus(0) == 3) 
        {
            StopAdx(0);
            
            AdxPlayFlag[0] = 0;
        }
        
        if ((FadeInRate + 1) != 0) 
        {
            SetVolumeAdxEx(0, -127.0f, Volume);
            
            RequestAdxFadeFunction(0, 1, FadeInRate + 1);
        }
        
        PlayAdx(0, PatId, BgmNo);
        
        CurrentBgmNo = BgmNo;
        CurrentBgmVolume = Volume;
        
        AdxPlayFlag[0] = 1;
    }
}

/*// 
// Start address: 0x295910
void PlayBgmEx(int BgmNo, int FadeInRate, int Volume)
{
	// Line 3008, Address: 0x295914, Func Offset: 0x4
	// Func End, Address: 0x29592c, Func Offset: 0x1c
}

// 
// Start address: 0x295930
void PlayBgm(int BgmNo, int FadeInRate)
{
	// Line 3021, Address: 0x295930, Func Offset: 0
	// Func End, Address: 0x295938, Func Offset: 0x8
}

// 
// 100% matching!
*/
void PlayBgm2(int BgmNo, int Volume)
{
    if (CurrentBgmNo != BgmNo) 
    {
        CurrentBgmNo = BgmNo;
        ReqFadeBgmNo = 8;
    }
    else if (CurrentBgmVolume != Volume) 
    {
        ReqFadeBgmNo = 2;
    }
    CurrentBgmVolume = Volume;
}

// 
// 100% matching!
void StopBgm(int FadeOutRate) 
{
    if (FadeOutRate != 0) 
    {
        RequestAdxFadeFunction(0, 2, FadeOutRate);
    } 
    else 
    {
        StopAdx(0);
        AdxPlayFlag[0] = 0;
    }
    CurrentBgmNo = -1;
    CurrentBgmVolume = -127;
    NextBgmVolume = -127;
}

// 100% matching!
void StopBgm2()
{
    ReqFadeBgmNo = 1;
    
    CurrentBgmNo = -1;
    CurrentBgmVolume = -127;
    
    NextBgmVolume = -127;
}

// 
// Start address: 0x295a20
void PlayVoiceEx2(int PatId, int VoiceNo, NJS_POINT3* pPos, int Mode, int FadeInRate, int PauseFlag)
{
	float Dist;
	char Vol;
	char Pan;
	// Line 3093, Address: 0x295a20, Func Offset: 0
	// Line 3098, Address: 0x295a44, Func Offset: 0x24
	// Line 3094, Address: 0x295a5c, Func Offset: 0x3c
	// Line 3098, Address: 0x295a60, Func Offset: 0x40
	// Line 3099, Address: 0x295a74, Func Offset: 0x54
	// Line 3100, Address: 0x295a7c, Func Offset: 0x5c
	// Line 3103, Address: 0x295a84, Func Offset: 0x64
	// Line 3105, Address: 0x295aac, Func Offset: 0x8c
	// Line 3106, Address: 0x295ac8, Func Offset: 0xa8
	// Line 3107, Address: 0x295ad8, Func Offset: 0xb8
	// Line 3108, Address: 0x295ae4, Func Offset: 0xc4
	// Line 3109, Address: 0x295af8, Func Offset: 0xd8
	// Line 3111, Address: 0x295b00, Func Offset: 0xe0
	// Line 3112, Address: 0x295b08, Func Offset: 0xe8
	// Line 3113, Address: 0x295b18, Func Offset: 0xf8
	// Line 3114, Address: 0x295b20, Func Offset: 0x100
	// Line 3116, Address: 0x295b2c, Func Offset: 0x10c
	// Line 3117, Address: 0x295b3c, Func Offset: 0x11c
	// Line 3118, Address: 0x295b50, Func Offset: 0x130
	// Line 3120, Address: 0x295b58, Func Offset: 0x138
	// Line 3121, Address: 0x295b78, Func Offset: 0x158
	// Line 3122, Address: 0x295b88, Func Offset: 0x168
	// Line 3125, Address: 0x295b94, Func Offset: 0x174
	// Line 3126, Address: 0x295ba0, Func Offset: 0x180
	// Func End, Address: 0x295bc4, Func Offset: 0x1a4
	scePrintf("PlayVoiceEx2 - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x295bd0
void PlayVoiceEx(int VoiceNo, _anon16* pPos, int Mode, int FadeInRate, int PauseFlag)
{
	// Line 3144, Address: 0x295bd4, Func Offset: 0x4
	// Func End, Address: 0x295bfc, Func Offset: 0x2c
}

// 
// Start address: 0x295c00
void PlayVoice(int VoiceNo, _anon16* pPos, int Mode, int FadeInRate)
{
	// Line 3160, Address: 0x295c00, Func Offset: 0
	// Func End, Address: 0x295c08, Func Offset: 0x8
}

// 
// Start address: 0x295c10
void ContinuePlayVoice()
{
	// Line 3170, Address: 0x295c10, Func Offset: 0
	// Func End, Address: 0x295c18, Func Offset: 0x8
}

*/ 
// 100% matching!
void StopVoice(int FadeOutRate)
{
    if (FadeOutRate != 0) 
    {
        RequestAdxFadeFunction(1, 2, FadeOutRate);
        return;
    }
    StopAdx(1);
    AdxPlayFlag[1] = 0;
}

// 100% matching!
int CheckPlayEndAdx(int SlotNo)
{
    return AdxPlayFlag[SlotNo];
}

// 100% matching!
int GetTimeAdx(int SlotNo)
{
    return GetAdxPlayTime(SlotNo);
}


// 100% matching!
void SetRoomSoundFxLevel(char FxProgNo, char FxLevel)
{
    SetFxLevelSe(0, FxLevel);
    SetFxLevelSe(1, FxLevel);
    SetFxLevelSe(2, FxLevel);
    SetFxLevelSe(3, FxLevel);
    SetFxLevelSe(4, FxLevel);
    SetFxLevelSe(5, FxLevel);
    SetFxLevelSe(0xB, FxLevel);
    SetFxLevelSe(0xC, FxLevel);
    SetFxLevelSe(7, FxLevel);
    SetFxLevelSe(6, FxLevel);
    SetFxLevelSe(8, FxLevel);
    SetFxLevelSe(9, FxLevel);
    SetFxLevelSe(0xA, FxLevel);
    SetFxLevelSe(0xD, FxLevel);
    SetFxLevelSe(0xE, FxLevel);
    SetFxLevelSe(0xF, FxLevel);
    SetFxLevelSe(0x10, FxLevel);
    SetFxLevelMidi(3, FxLevel);
    SetFxLevelMidi(4, FxLevel);
    SetFxLevelMidi(5, FxLevel);
    SetFxLevelMidi(7, FxLevel);
    SetFxLevelMidi(6, FxLevel);
    CurrentRoomFxProgNo = FxProgNo;
    CurrentRoomFxLevel = FxLevel;
}

// 
// 100% matching!

void SetRoomSoundFxLevelEx() 
{
    SetRoomSoundFxLevel(0, Room_SoundEnv.RoomFxLevel);
}

/*
// 100% matching!
*/
int SearchPlayingEnemySe(int EnemyNo, int Attrib) 
{
    EnemySlot* EnemySlotPtr;
    int i = 0;
    EnemySlotPtr = &EnemySlotInfo[0];
    
    while (TRUE)
    {
        if ((EnemySlotPtr->Flag != 0) && (EnemyNo == EnemySlotPtr->EnemyNo) && (Attrib == EnemySlotPtr->Attrib)) 
        {
            return i;
        }
        
        i += 1;
        EnemySlotPtr += 1;
        
        if (i >= 6) 
        {
            return -1;
        }
    }
}

// 100% matching!
int SearchFreeEnemySeSlot() 
{
    EnemySlot* EnemySlotPtr;
    int i = 0;
    EnemySlotPtr = &EnemySlotInfo[0];
    
    while (TRUE)
    {
        if (EnemySlotPtr->Flag == 0) 
        {
            return i;
        }
        
        i += 1;
        EnemySlotPtr += 1;
        
        if (i >= 6) 
        {
            return -1;
        }
    }
}


// 100% matching!
int CheckPlaySameSe(int EnemyNo, int SeNo, int Flag) 
{
    int i = 0;
    EnemySlot* EnemySlotPtr;
    int SameSeCount = 0;
    int MaxSeCount = 0;
    EnemySlotPtr = &EnemySlotInfo[0];
    
    while (i < 6)
    {
        if ((EnemySlotPtr->Flag != 0) && (EnemySlotPtr->SeNo == SeNo) && (EnemyNo != EnemySlotPtr->EnemyNo) && (Flag != 0)) 
        {
            SameSeCount += 1;
        }
        
        i += 1;
        EnemySlotPtr += 1;
    }
    
    MaxSeCount = (SeNo >> 12) & 0xF;
    
    if (SameSeCount == 0)
    {
        return 0;
    }
    
    return (SameSeCount < MaxSeCount) ? 0 : 1;

}


// 100% matching!
void CallEnemySeMain(unsigned int SlotNo, int SeNo, char Pan, char Vol, int Flag, int FadeRate)
{
    short* var_at;
    RequestInfo.SlotNo = SlotNo;
    RequestInfo.Priority = 0;
    
    if (Flag == 0) 
    {
        RequestInfo.ListNo = -1;
        if (CheckFadeEndSe(SlotNo) == 0) 
        {
            RequestInfo.Volume = Vol;
            RequestInfo.VolumeDelayTime = 0;
        } 
        else 
        {
            RequestInfo.VolumeDelayTime = -1;
        }
        
    }
    else 
    {
        StopSe(SlotNo);
        RequestInfo.BankNo = ((SeNo >> 0x8) & 0xF);
        RequestInfo.ListNo = SeNo;
        if (FadeRate == 0) 
        {
            StopFadeSe(SlotNo);
             RequestInfo.Volume = Vol;
             RequestInfo.VolumeDelayTime = 0;
        } 
        else 
        {
        block_8:
            RequestInfo.VolumeDelayTime = -1;
        }
    }
    RequestInfo.Pan = Pan;
    RequestInfo.PanDelayTime = 0;
    RequestInfo.PitchDelayTime = -1;
    RequestInfo.FxInput = -1;
    ExPlaySe(&RequestInfo);
    if ((Flag != 0) && (FadeRate != 0)) 
    {
        RequestSeFadeFunctionEx(SlotNo, -0x7F, Vol, FadeRate);
    }
}


// 100% matching!
void RegistEnemySlot(int SlotNo, int EnemyNo, int SeNo)
{
    EnemySlot* EnemySlotPtr;
    
    EnemySlotPtr = EnemySlotInfo;
    EnemySlotPtr += (SlotNo * 0x1);
    EnemySlotPtr->EnemyNo = EnemyNo;
    EnemySlotPtr->SeNo = SeNo;
    EnemySlotPtr->Attrib = (SeNo & 0xF000000) >> 0x18;
    EnemySlotPtr->Prio = (SeNo & 0xF0000) >> 0x10;
    EnemySlotPtr->Flag = 1;
}

// 
// Start address: 0x2960a0
void ResetEnemySeInfo()
{
	// Line 3373, Address: 0x2960a0, Func Offset: 0
	// Func End, Address: 0x2960a8, Func Offset: 0x8
    scePrintf("ResetEnemySeInfo - UNIMPLEMENTED\n");
}

// 99.85% matching
void ExecEnemySeManager()
{
    int i;
    int j;
    EnemySlot* esp;
    Enemy* eip;
    Enemy* eip2;
    unsigned char* rlp1;
    unsigned char* rlp2;
    unsigned char a;
    unsigned char b;
    int SlotNo;
    int FreeEnemySlotCnt;

    FreeEnemySlotCnt = 0;
    
    if (StartInitScriptFlag != 0) 
    {
        return;
    }
    
    for (i = 0, esp = EnemySlotInfo; i < 6; i++, esp++) 
    {
        if (CheckPlaySe(i) == 0) 
        {
            esp->Flag = 0;
            
            esp->EnemyNo = 0;
            esp->SeNo = 0;
            
            esp->Attrib = 0;
            
            esp->Prio = 0;
            
            FreeEnemySlotCnt++;
        }
    }
    
    MaxRequestList = 0;
    
    for (i = 0, eip = EnemyInfo; i < 128; i++, eip++) 
    {
        if ((eip->ReqFlag != 0) || (eip->ReqFlagV != 0)) 
        {
            RequestList[MaxRequestList] = i;
            
            MaxRequestList++;
        }
    }
    
    if (MaxRequestList >= 2) 
    {
        for (i = 0; i < (MaxRequestList - 1); i++) 
        {
            for (j = i + 1; j < MaxRequestList; j++) 
            {
                rlp1 = rlp1 = RequestList;
                
                rlp1 += i;
                
                a = *rlp1;

                rlp2 = RequestList;
                
                rlp2 += j;
                
                b = *rlp2;

                eip = EnemyInfo;
                
                eip += a;

                eip2 = EnemyInfo;
                
                eip2 += b;

                if (eip->Prio > eip2->Prio) 
                {
                    *rlp1 = b;
                    *rlp2 = a;
                }
                else if (eip->Dist > eip2->Dist) 
                {
                    *rlp1 = b;
                    *rlp2 = a;
                }
            }
        }
    }
    
    for (i = 0; i < MaxRequestList; i++) 
    {
        eip = EnemyInfo;
        
        j = RequestList[i];
        
        eip += j;
        
        eip->Vol += CheckCollision4Sound(&eip->Pos);
        
        if (eip->ReqFlag != 0) 
        {
            if (CheckPlaySameSe(j, eip->SeNo, eip->CallFlag) == 0) 
            {
                if ((SlotNo = SearchPlayingEnemySe(j, 0)) < 0)
                {
                    if ((SlotNo = SearchFreeEnemySeSlot()) >= 0) 
                    {
                        RegistEnemySlot(SlotNo, j, eip->SeNo);
                        
                        CallEnemySeMain(SlotNo, eip->SeNo, eip->Pan, eip->Vol, eip->CallFlag, eip->FadeRate);
                    }
                } 
                else 
                {
                    RegistEnemySlot(SlotNo, j, eip->SeNo);
                    
                    CallEnemySeMain(SlotNo, eip->SeNo, eip->Pan, eip->Vol, eip->CallFlag, eip->FadeRate);
                }
            }
            
            eip->ReqFlag = 0;
        }

        if (eip->ReqFlagV != 0) 
        {
            if (CheckPlaySameSe(j, eip->SeNoV, eip->CallFlagV) == 0) 
            {
                if ((SlotNo = SearchPlayingEnemySe(j, 1)) < 0)
                {
                    if ((SlotNo = SearchFreeEnemySeSlot()) >= 0) 
                    {
                        RegistEnemySlot(SlotNo, j, eip->SeNoV);
                        
                        CallEnemySeMain(SlotNo, eip->SeNoV, eip->Pan, eip->Vol, eip->CallFlagV, eip->FadeRate);
                    }
                } 
                else 
                {
                    RegistEnemySlot(SlotNo, j, eip->SeNoV);
                    
                    CallEnemySeMain(SlotNo, eip->SeNoV, eip->Pan, eip->Vol, eip->CallFlagV, eip->FadeRate);
                }
            }
            
            eip->ReqFlagV = 0;
        }
        
        eip->Prio = 3;
    }
}

// 100% matching
int SearchPlayingObjectSeEx(int ObjectNo, int Mode) {
    int i;
    ObjectSlot* osp;
    
    i = 0;
    osp = &ObjectSlotInfo[i];

    while(i < MaxSlotObjectSe) {

        if ((osp->Flag != 0) && (ObjectNo == osp->ObjectNo)) {
            if (Mode != 0) {
                osp->FindFlag = 1;
            }
            
            return i;
        }
        
        i += 1;
        osp++;
    }
    
    return -1;
}

// 
// 100% matching
int SearchPlayingObjectSe(int ObjectNo) {
    return SearchPlayingObjectSeEx(ObjectNo, 1);
}

// 
// Start address: 0x2964e0
int SearchFreeObjectSeSlot()
{
	//_anon11* osp;
	int i;
	// Line 3550, Address: 0x2964e0, Func Offset: 0
	// Line 3551, Address: 0x2964f8, Func Offset: 0x18
	// Line 3552, Address: 0x296504, Func Offset: 0x24
	// Line 3554, Address: 0x29650c, Func Offset: 0x2c
	// Line 3556, Address: 0x296524, Func Offset: 0x44
	// Line 3557, Address: 0x296528, Func Offset: 0x48
	// Func End, Address: 0x296530, Func Offset: 0x50
	scePrintf("SearchFreeObjectSeSlot - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x296530
void CallObjectSe2(unsigned int SlotNo, Object* oip, int Flag)
{
	// Line 3560, Address: 0x296530, Func Offset: 0
	// Line 3561, Address: 0x296544, Func Offset: 0x14
	// Line 3562, Address: 0x296554, Func Offset: 0x24
	// Line 3563, Address: 0x29656c, Func Offset: 0x3c
	// Line 3564, Address: 0x296574, Func Offset: 0x44
	// Line 3565, Address: 0x29657c, Func Offset: 0x4c
	// Line 3566, Address: 0x296584, Func Offset: 0x54
	// Line 3567, Address: 0x296598, Func Offset: 0x68
	// Line 3569, Address: 0x2965a4, Func Offset: 0x74
	// Line 3570, Address: 0x2965ac, Func Offset: 0x7c
	// Line 3571, Address: 0x2965bc, Func Offset: 0x8c
	// Line 3572, Address: 0x2965c8, Func Offset: 0x98
	// Line 3573, Address: 0x2965d8, Func Offset: 0xa8
	// Line 3574, Address: 0x2965f0, Func Offset: 0xc0
	// Line 3576, Address: 0x2965fc, Func Offset: 0xcc
	// Line 3577, Address: 0x296604, Func Offset: 0xd4
	// Line 3578, Address: 0x29660c, Func Offset: 0xdc
	// Line 3579, Address: 0x296634, Func Offset: 0x104
	// Line 3581, Address: 0x29663c, Func Offset: 0x10c
	// Line 3582, Address: 0x29664c, Func Offset: 0x11c
	// Line 3583, Address: 0x296658, Func Offset: 0x128
	// Line 3584, Address: 0x296668, Func Offset: 0x138
	// Line 3585, Address: 0x29667c, Func Offset: 0x14c
	// Line 3587, Address: 0x296688, Func Offset: 0x158
	// Line 3588, Address: 0x296690, Func Offset: 0x160
	// Line 3589, Address: 0x29669c, Func Offset: 0x16c
	// Line 3591, Address: 0x2966a4, Func Offset: 0x174
	// Line 3592, Address: 0x2966b0, Func Offset: 0x180
	// Line 3593, Address: 0x2966b8, Func Offset: 0x188
	// Line 3594, Address: 0x2966c0, Func Offset: 0x190
	// Line 3595, Address: 0x2966cc, Func Offset: 0x19c
	// Line 3596, Address: 0x2966d4, Func Offset: 0x1a4
	// Line 3597, Address: 0x2966e4, Func Offset: 0x1b4
	// Line 3598, Address: 0x2966f0, Func Offset: 0x1c0
	// Line 3599, Address: 0x2966f8, Func Offset: 0x1c8
	// Line 3602, Address: 0x29670c, Func Offset: 0x1dc
	// Func End, Address: 0x296724, Func Offset: 0x1f4
	scePrintf("CallObjectSe2 - UNIMPLEMENTED!\n");
}

// 100% matching!
void RegistObjectSlot(int SlotNo, int ObjectNo, int SeNo)
{
    ObjectSlot* ObjectSlotPtr;
    
    ObjectSlotPtr = ObjectSlotInfo;
    ObjectSlotPtr = ObjectSlotPtr + (SlotNo);
    ObjectSlotPtr->ObjectNo = ObjectNo;
    ObjectSlotPtr->SeNo = SeNo;
    ObjectSlotPtr->Prio = 0;
    ObjectSlotPtr->Flag = 1;
}

// 100% matching!
void ResetObjectSeInfo()
{
    memset(&ObjectSlotInfo, 0, 0x24);
    memset(&ObjectInfo, 0, 0x380);
    MaxObjectReqList = 0;
}

// 100% matching!
void ExecObjectSeManager() {
    int i;
    int j;
    Object *oip;
    ObjectSlot *osp;
    int SlotNo;
    
    if (StartInitScriptFlag != 0) {
        return;
    }
    
    for (i = 0; i < MaxObjectReqList; i++) {
        oip = ObjectInfo;
        j = ObjectReqList[i];
        oip += j;

        RequestObjectSeEx(
            j,
            &oip->pos,
            oip->SeNo,     
            oip->Prio,     
            oip->Type      
        );

    }
    
    for (i = 0; i < MaxSlotObjectSe; i++) {
        oip = ObjectInfo;
        j = ObjectReqList[i];
        oip += j;
        
        if (oip->ReqFlag != 0) {
            SlotNo = SearchPlayingObjectSe(j);
            if (SlotNo >= 0) {
                oip->SlotNo = SlotNo;
            }
        }
    }
   
    for (i = 0; i < MaxSlotObjectSe; i++) {
        oip = ObjectInfo;
        j = ObjectReqList[i];
        oip += j;

        if (oip->ReqFlag != 0) {
            if (oip->SlotNo < 0) {
                if ((SlotNo = SearchFreeObjectSeSlot() )>= 0) {
                    CallObjectSe2(SlotNo, oip, 1);
                    RegistObjectSlot(SlotNo, j, oip->SeNo);
                }
            } else {
                CallObjectSe2(oip->SlotNo, oip, 0);
                RegistObjectSlot(oip->SlotNo, j, oip->SeNo);
            }
            
            oip->ReqFlag = 0;
        }
    }

    for (i = 0, osp = ObjectSlotInfo; i < MaxSlotObjectSe; i++, osp++) {
        osp->FindFlag = 0;  
    }
}

/*// 
// Start address: 0x2969c0
void RequestSoundFade(int Func, int Attr, short Timer)
{
	int i;
	// Line 3763, Address: 0x2969c0, Func Offset: 0
	// Line 3766, Address: 0x2969dc, Func Offset: 0x1c
	// Line 3763, Address: 0x2969e0, Func Offset: 0x20
	// Line 3766, Address: 0x2969ec, Func Offset: 0x2c
	// Line 3767, Address: 0x2969f4, Func Offset: 0x34
	// Line 3768, Address: 0x296a00, Func Offset: 0x40
	// Line 3770, Address: 0x296a10, Func Offset: 0x50
	// Line 3771, Address: 0x296a1c, Func Offset: 0x5c
	// Line 3772, Address: 0x296a2c, Func Offset: 0x6c
	// Line 3773, Address: 0x296a3c, Func Offset: 0x7c
	// Line 3774, Address: 0x296a4c, Func Offset: 0x8c
	// Line 3775, Address: 0x296a5c, Func Offset: 0x9c
	// Line 3776, Address: 0x296a6c, Func Offset: 0xac
	// Line 3782, Address: 0x296a7c, Func Offset: 0xbc
	// Line 3783, Address: 0x296a88, Func Offset: 0xc8
	// Line 3785, Address: 0x296a98, Func Offset: 0xd8
	// Line 3786, Address: 0x296aa4, Func Offset: 0xe4
	// Line 3791, Address: 0x296ab4, Func Offset: 0xf4
	// Line 3792, Address: 0x296adc, Func Offset: 0x11c
	// Line 3793, Address: 0x296b38, Func Offset: 0x178
	// Line 3794, Address: 0x296b44, Func Offset: 0x184
	// Line 3795, Address: 0x296b58, Func Offset: 0x198
	// Line 3796, Address: 0x296b60, Func Offset: 0x1a0
	// Line 3798, Address: 0x296b74, Func Offset: 0x1b4
	// Line 3799, Address: 0x296b94, Func Offset: 0x1d4
	// Line 3800, Address: 0x296b9c, Func Offset: 0x1dc
	// Line 3801, Address: 0x296bb0, Func Offset: 0x1f0
	// Line 3807, Address: 0x296bcc, Func Offset: 0x20c
	// Line 3808, Address: 0x296bd0, Func Offset: 0x210
	// Line 3809, Address: 0x296bdc, Func Offset: 0x21c
	// Line 3811, Address: 0x296bf0, Func Offset: 0x230
	// Line 3812, Address: 0x296bfc, Func Offset: 0x23c
	// Line 3814, Address: 0x296c10, Func Offset: 0x250
	// Func End, Address: 0x296c34, Func Offset: 0x274
}*/

// 
// Start address: 0x296c40
void RequestAllStopSoundEx(int AdxFlag, int InSoundFlag, int FadeCount)
{
	int i;
	// Line 3830, Address: 0x296c40, Func Offset: 0
	// Line 3833, Address: 0x296c58, Func Offset: 0x18
	// Line 3834, Address: 0x296c6c, Func Offset: 0x2c
	// Line 3835, Address: 0x296c7c, Func Offset: 0x3c
	// Line 3836, Address: 0x296c80, Func Offset: 0x40
	// Line 3837, Address: 0x296c88, Func Offset: 0x48
	// Line 3838, Address: 0x296c90, Func Offset: 0x50
	// Line 3839, Address: 0x296c98, Func Offset: 0x58
	// Line 3840, Address: 0x296cac, Func Offset: 0x6c
	// Line 3842, Address: 0x296cb0, Func Offset: 0x70
	// Line 3841, Address: 0x296cb4, Func Offset: 0x74
	// Line 3842, Address: 0x296cb8, Func Offset: 0x78
	// Line 3847, Address: 0x296cc4, Func Offset: 0x84
	// Line 3844, Address: 0x296ccc, Func Offset: 0x8c
	// Line 3845, Address: 0x296cd8, Func Offset: 0x98
	// Line 3846, Address: 0x296ce4, Func Offset: 0xa4
	// Line 3851, Address: 0x296cec, Func Offset: 0xac
	// Line 3852, Address: 0x296cf4, Func Offset: 0xb4
	// Line 3854, Address: 0x296cfc, Func Offset: 0xbc
	// Line 3855, Address: 0x296d00, Func Offset: 0xc0
	// Line 3856, Address: 0x296d08, Func Offset: 0xc8
	// Line 3857, Address: 0x296d10, Func Offset: 0xd0
	// Line 3858, Address: 0x296d18, Func Offset: 0xd8
	// Line 3859, Address: 0x296d20, Func Offset: 0xe0
	// Line 3860, Address: 0x296d34, Func Offset: 0xf4
	// Line 3861, Address: 0x296d38, Func Offset: 0xf8
	// Line 3862, Address: 0x296d48, Func Offset: 0x108
	// Line 3863, Address: 0x296d4c, Func Offset: 0x10c
	// Line 3864, Address: 0x296d54, Func Offset: 0x114
	// Line 3865, Address: 0x296d5c, Func Offset: 0x11c
	// Line 3866, Address: 0x296d64, Func Offset: 0x124
	// Line 3867, Address: 0x296d6c, Func Offset: 0x12c
	// Line 3869, Address: 0x296d80, Func Offset: 0x140
	// Line 3872, Address: 0x296da0, Func Offset: 0x160
	// Line 3873, Address: 0x296da4, Func Offset: 0x164
	// Line 3875, Address: 0x296da8, Func Offset: 0x168
	// Line 3873, Address: 0x296dac, Func Offset: 0x16c
	// Line 3874, Address: 0x296db0, Func Offset: 0x170
	// Line 3875, Address: 0x296db4, Func Offset: 0x174
	// Line 3874, Address: 0x296db8, Func Offset: 0x178
	// Line 3875, Address: 0x296dbc, Func Offset: 0x17c
	// Line 3876, Address: 0x296dc4, Func Offset: 0x184
	// Line 3877, Address: 0x296dc8, Func Offset: 0x188
	// Func End, Address: 0x296de4, Func Offset: 0x1a4
	scePrintf("RequestAllStopSoundEx - UNIMPLEMENTED!\n");
}

// 100% matching! 
void ResetSoundComInfo()
{

}

/*// 
// Start address: 0x296e00
void Com_ExecRoomFadeIn()
{
	int i;
	// Line 3948, Address: 0x296e00, Func Offset: 0
	// Line 3953, Address: 0x296e18, Func Offset: 0x18
	// Line 3981, Address: 0x296e20, Func Offset: 0x20
	// Line 3982, Address: 0x296e34, Func Offset: 0x34
	// Line 3983, Address: 0x296e4c, Func Offset: 0x4c
	// Line 3984, Address: 0x296e54, Func Offset: 0x54
	// Line 3985, Address: 0x296e60, Func Offset: 0x60
	// Line 3988, Address: 0x296e8c, Func Offset: 0x8c
	// Line 3990, Address: 0x296e98, Func Offset: 0x98
	// Line 3991, Address: 0x296e9c, Func Offset: 0x9c
	// Line 3992, Address: 0x296eac, Func Offset: 0xac
	// Line 3993, Address: 0x296ebc, Func Offset: 0xbc
	// Line 3994, Address: 0x296ec4, Func Offset: 0xc4
	// Line 3995, Address: 0x296ed0, Func Offset: 0xd0
	// Line 4000, Address: 0x296ee0, Func Offset: 0xe0
	// Line 3998, Address: 0x296ee4, Func Offset: 0xe4
	// Line 3999, Address: 0x296ee8, Func Offset: 0xe8
	// Line 4000, Address: 0x296eec, Func Offset: 0xec
	// Line 3999, Address: 0x296ef0, Func Offset: 0xf0
	// Line 4000, Address: 0x296ef8, Func Offset: 0xf8
	// Line 4002, Address: 0x296f00, Func Offset: 0x100
	// Line 4004, Address: 0x296f10, Func Offset: 0x110
	// Line 4007, Address: 0x296f18, Func Offset: 0x118
	// Line 4008, Address: 0x296f28, Func Offset: 0x128
	// Func End, Address: 0x296f44, Func Offset: 0x144
}

// 
// Start address: 0x296f50
void Com_ExecRoomFadeOut()
{
	int AttrTbl[2];
	int FadeAttr;
	int i;
	// Line 4017, Address: 0x296f50, Func Offset: 0
	// Line 4020, Address: 0x296f54, Func Offset: 0x4
	// Line 4017, Address: 0x296f5c, Func Offset: 0xc
	// Line 4020, Address: 0x296f60, Func Offset: 0x10
	// Line 4036, Address: 0x296f68, Func Offset: 0x18
	// Line 4020, Address: 0x296f6c, Func Offset: 0x1c
	// Line 4036, Address: 0x296f70, Func Offset: 0x20
	// Line 4037, Address: 0x296f7c, Func Offset: 0x2c
	// Line 4039, Address: 0x296f84, Func Offset: 0x34
	// Line 4040, Address: 0x296f8c, Func Offset: 0x3c
	// Line 4039, Address: 0x296f90, Func Offset: 0x40
	// Line 4040, Address: 0x296f94, Func Offset: 0x44
	// Line 4041, Address: 0x296f98, Func Offset: 0x48
	// Line 4042, Address: 0x296fa8, Func Offset: 0x58
	// Line 4044, Address: 0x296fb0, Func Offset: 0x60
	// Line 4042, Address: 0x296fb8, Func Offset: 0x68
	// Line 4044, Address: 0x296fbc, Func Offset: 0x6c
	// Line 4046, Address: 0x296fc4, Func Offset: 0x74
	// Line 4048, Address: 0x296fd0, Func Offset: 0x80
	// Line 4049, Address: 0x296fd8, Func Offset: 0x88
	// Func End, Address: 0x296fe4, Func Offset: 0x94
}*/

// 100% matching!
void Com_ExecCallBgm_And_BgSe()
{

}

/*// 
// Start address: 0x297000
void Com_StartInitScript()
{
	// Line 4108, Address: 0x297000, Func Offset: 0
	// Line 4109, Address: 0x297004, Func Offset: 0x4
	// Line 4108, Address: 0x297008, Func Offset: 0x8
	// Line 4109, Address: 0x29700c, Func Offset: 0xc
	// Line 4111, Address: 0x297010, Func Offset: 0x10
	// Line 4114, Address: 0x297018, Func Offset: 0x18
	// Line 4115, Address: 0x297020, Func Offset: 0x20
	// Line 4116, Address: 0x297028, Func Offset: 0x28
	// Line 4117, Address: 0x297030, Func Offset: 0x30
	// Line 4118, Address: 0x297038, Func Offset: 0x38
	// Line 4119, Address: 0x297040, Func Offset: 0x40
	// Line 4121, Address: 0x297048, Func Offset: 0x48
	// Line 4122, Address: 0x29705c, Func Offset: 0x5c
	// Line 4123, Address: 0x297070, Func Offset: 0x70
	// Line 4125, Address: 0x297084, Func Offset: 0x84
	// Line 4126, Address: 0x297090, Func Offset: 0x90
	// Func End, Address: 0x29709c, Func Offset: 0x9c
}*/

// 100% matching!
void Com_FinishInitScript() 
{

}

// 
// Start address: 0x2970b0
void ExecuteSoundCommand()
{
	int i;
	// Line 4163, Address: 0x2970b0, Func Offset: 0
	// Line 4166, Address: 0x2970c8, Func Offset: 0x18
	// Line 4167, Address: 0x2970d0, Func Offset: 0x20
	// Line 4168, Address: 0x2970f0, Func Offset: 0x40
	// Line 4170, Address: 0x2970f8, Func Offset: 0x48
	// Line 4171, Address: 0x297100, Func Offset: 0x50
	// Line 4173, Address: 0x29711c, Func Offset: 0x6c
	// Line 4174, Address: 0x297124, Func Offset: 0x74
	// Func End, Address: 0x297138, Func Offset: 0x88
	scePrintf("ExecuteSoundCommand - UNIMPLEMENTED!\n");
}

// 100% matching!
void SendSoundCommand(unsigned int CommandNo)
{
    if (SoundCommand.MaxCommand != 2) 
    {
        SoundCommand.ComTbl[SoundCommand.MaxCommand] = CommandNo;
        
        SoundCommand.MaxCommand++;
        
        ExecuteSoundCommand();
    }
}

// 100% matching!
void ExecSoundSystemMonitor()
{
    int i;
    
    CameraPos.x = cam.wpx;
    CameraPos.y = cam.wpy;
    CameraPos.z = cam.wpz;
    
    PlayerPos.x = plp->px;
    PlayerPos.y = plp->py;
    PlayerPos.z = plp->pz;
    
    for (i = 0; i < 2; i++)
    {
        if ((AdxPlayFlag[i] != 0) && ((GetAdxStatus(i) == 5) || (GetAdxStatus(i) == 0)))
        {
            StopAdx(i);
                
            AdxPlayFlag[i] = 0;
        }
    } 
    
    ExecEnemySeManager();
    ExecObjectSeManager();
}

// 100% matching!
int RequestReadIsoFile(char* FileName, void* DestPtr)
{
    if (ReadFileRequestFlag != 0) 
    {
        return -1;
    }
    
    if ((GenAdxfSlot = OpenAfsIsoFile(FileName)) < 0) 
    {
        return -1;
    }
    
    RequestReadAfsInsideFile(GenAdxfSlot, DestPtr);
    
    DestReadPtr = DestPtr;

    ReadFileRequestFlag = 1;

    FileReadStatus = 1;

    return 0;
}

// 100% matching!
int RequestReadInsideFile(unsigned int PartitionId, unsigned int FileId, void* DestPtr)
{
    if (ReadFileRequestFlag != 0) 
    {
        return -1;
    }
    
    if ((GenAdxfSlot = OpenAfsInsideFile(PartitionId, FileId)) < 0) 
    {
        return -1;
    }
    
    RequestReadAfsInsideFile(GenAdxfSlot, DestPtr);
    
    DestReadPtr = DestPtr;
    
    ReadFileRequestFlag = 1;
    
    FileReadStatus = 1;
    
    return 0;
}

// 100% matching!
int GetIsoFileSize(char* FileName)
{
    GetFileSize(FileName);
}

// 100% matching!
int GetInsideFileSize(unsigned int PartitionId, unsigned int FileId)
{
    unsigned int temp; // not from the debugging symbols
    int SlotNo;
    int FileSize;
    
    SlotNo = OpenAfsInsideFile(PartitionId, FileId);
    
    temp = SlotNo;
    
    if (SlotNo < 0)
    {
        return 0;
    }
    
    FileSize = GetAfsInsideFileSize(temp);

    CloseAfsInsideFile(temp);
    
    return FileSize;
}

// 100% matching!
int GetReadFileStatus() 
{ 
    return FileReadStatus; 
}

// 100% matching! 
void ExecFileManager()
{
    OpenDriveTrayFlag = CheckOpenTray();
    
    if (ReadFileRequestFlag != 0)
    {
        if ((OpenDriveTrayFlag != 0) || (CheckSoftResetKeyFlag(-1) != 0))
        {
            StopAfsInsideFile(GenAdxfSlot);
            
            ReadFileRequestFlag = 0;
            
            FileReadStatus = -1;
        }
        else if ((FileReadStatus == 1) && (CheckReadEndAfsInsideFile(GenAdxfSlot) != 0)) 
        {
            ReadFileRequestFlag = 0;
            
            FileReadStatus = 0;
        }
    }
}

// 100% matching! 
int PlayStartMovieEx(int MovieNo, int MovieType, int PauseFlag)
{
    MWS_PLY_CPRM_SFD CprmSfd;
    char FileName[16];        
    unsigned int Type;     

    if (MovieInfo.ExecMovieSystemFlag != 0)
    {
        MovieInfo.MovieSystemLastError = 2;
        
        return 2;
    }

    Type = MovieTypeDef[MovieNo] & 0x1F;

    CprmSfd.ftype = 1;
    CprmSfd.dtype = MovieDef[Type].DispType;
    
    CprmSfd.max_bps = 0x384000;
    
    CprmSfd.max_width = MovieDef[Type].sSizeX;
    CprmSfd.max_height = MovieDef[Type].sSizeY;
    
    CprmSfd.nfrm_pool_wk = 3;
    
    CprmSfd.wksize = mwPlyCalcWorkSofdec(CprmSfd.ftype, CprmSfd.max_bps, CprmSfd.max_width, CprmSfd.max_height, CprmSfd.nfrm_pool_wk);

    if ((MovieInfo.mmp = bhGetFreeMemory(CprmSfd.wksize, sizeof(MWS_PLY_CPRM_SFD))) == NULL)
    {
        MovieInfo.MovieSystemLastError = 1;
        
        return 1;
    }

    StopBgm(0);
    StopVoice(0);
    
    SleepAdxStream();
    
    sprintf(FileName, "MV_%03u.PSS", MovieNo);
    
    PlayMw2(FileName, 0, MovieInfo.mmp, &CprmSfd, PauseFlag);

    if (MovieDef[Type].dSizeX != 0)
    {
        SetSfdDislpaySize(MovieDef[Type].dPosX, MovieDef[Type].dPosY, MovieDef[Type].dSizeX, MovieDef[Type].dSizeY);
    }

    MovieInfo.MovieCancelFlag = ((MovieTypeDef[MovieNo] & 0x80) == 0) ? 1 : 0;
    
    if ((MovieType & 0x1))
    {
        MovieInfo.MovieCancelFlag = 1;
    }
    
    MovieInfo.MovieFadeFlag = ((MovieTypeDef[MovieNo] & 0x40) == 0) ? 0 : 1;
    
    if ((MovieType & 0x2))
    {
        MovieInfo.MovieFadeFlag = 1;
    }
    
    MovieInfo.MovieFadeMode = 0;
    
    MovieInfo.FrameCnt = 30;
    
    MovieInfo.Vol = MovieVolDef[MovieNo];
    MovieInfo.VolSpeed = (MovieVolDef[MovieNo] - -999.0f) / MovieInfo.FrameCnt;
    
    MovieInfo.Fade = GetSfdFadeRate();
    MovieInfo.FadeSpeed = MovieInfo.Fade / MovieInfo.FrameCnt;
    
    MovieInfo.MovieSystemLastError = 0;
    
    MovieInfo.ExecMovieSystemFlag = 1;

    return 0;
}

// 100% matching!
void PlayStopMovieEx(int Mode)
{
    if (MovieInfo.ExecMovieSystemFlag != 0) 
    {
        if (Mode == 0) 
        {
            StopMw();
            
            bhReleaseFreeMemory(MovieInfo.mmp);
            
            WakeupAdxStream(AdxDef);
        }
        
        MovieInfo.ExecMovieSystemFlag = 0;
        
        if ((sys->cb_flg & 0x2)) 
        {
            sys->cb_flg &= ~0x2;
        }
    }
}

// 100% matching!
void PlayStopMovie()
{
    PlayStopMovieEx(0);
}

// 100% matching!
int CheckPlayEndMovie()
{
    return MovieInfo.ExecMovieSystemFlag;
}

// 100% matching!
int GetTimeMoive()
{
    if (MovieInfo.ExecMovieSystemFlag != 0)
    {
        return GetMwPlayTimeEx();
    }
    
    return 0;
}

// 100% matching!
int WaitPrePlayMovie()
{
    if (MovieInfo.ExecMovieSystemFlag != 0)
    {
        if (OpenDriveTrayFlag != 0) 
        {
            PlayStopMovieEx(1);
            
            return 3;
        }
        
        if (CheckSoftResetKeyFlag(-1) != 0)
        {
            PlayStopMovie();
            
            return 3;
        }
        
        if ((MovieInfo.MovieCancelFlag != 0) && ((rmi.MVCancelButton & Pad[CurrentPortId].press))) 
        {
            PlayStopMovie();
            
            return 2;
        }
        
        PlayMwMain();
        
        if (GetMwStatus() == MWE_PLY_STAT_PLAYING) 
        {
            RestartMw();
            
            return 0;
        }
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
int PlayMovieMain()
{
    if (MovieInfo.ExecMovieSystemFlag != 0) 
    {
        if (OpenDriveTrayFlag != 0) 
        {
            PlayStopMovieEx(1);
            
            return 3;
        }
        
        if (CheckSoftResetKeyFlag(-1) != 0)
        {
            PlayStopMovie();
            
            return 3;
        }
        
        mwPlyStartFrame();
        
        if (MovieInfo.MovieCancelFlag != 0)
        {
            if ((rmi.MVCancelButton & Pad[CurrentPortId].press)) 
            {
                if (MovieInfo.MovieFadeFlag == 0) 
                {
                    PlayStopMovie();
                    
                    return 2;
                }
                
                if (MovieInfo.MovieFadeMode != 1) 
                {
                    MovieInfo.MovieFadeMode = 1;
                    
                    bhSetScreenFade(0xFF000000, MovieInfo.FrameCnt);
                }
            }
        }
        
        if (MovieInfo.MovieFadeMode != 0) 
        {
            if (!(sys->cb_flg & 0x2)) 
            {
                PlayStopMovie();
                
                return 2;
            }
            
            bhControlScreenFade();
            
            if (sys->fade_an > 0) 
            {
                bhDrawScreenFade();
            }
            
            MovieInfo.Vol -= MovieInfo.VolSpeed;
            
            SetMwVolume(MovieInfo.Vol);
        }
        
        if (PlayMwMain() == 0) 
        {
            PlayStopMovie();
            
            return 1;
        }
    }
    
    return 0;
}

// 100% matching!
void SetEventVibrationMode(int Mode) 
{ 
    EventVibrationMode = Mode; 
}

// 100% matching!
void StartVibrationBasic(int PortNo, int AtrbId, int VibNo)
{
    PDS_VIBPARAM VibPrm;
    
    if ((!(sys->ss_flg & 0x400000)) && ((EventVibrationMode == 0) || (AtrbId == 2))) 
    {
        VibPrm.flag = VibFlag[VibP[VibNo].flag];
        
        VibPrm.power = VibP[VibNo].power;
        
        VibPrm.freq = VibP[VibNo].freq;
        
        VibPrm.inc = VibP[VibNo].inc;
        
        StartVibration((PortNo * 6) + 2, &VibPrm);
    }
}

// 100% matching!
void StartVibrationEx(int AtrbId, int VibNo) 
{ 
    StartVibrationBasic(CurrentPortId, AtrbId, VibNo);
}

// 100% matching!
void StopVibrationBasic(int PortNo) 
{ 
    StopVibration((PortNo * 6) + 2);
}

// 100% matching!
void StopVibrationEx() 
{ 
    StopVibrationBasic(CurrentPortId);
}

// 100% matching!
void SetAdjustDisplay() 
{ 
    SystemAdjustFlag = 1; 
}

// 100% matching! 
void RequestAdjustDisplay(int AdjustX, int AdjustY)
{ 
    sys->adjust_x = AdjustX;
    sys->adjust_y = AdjustY; 
    
    SetAdjustDisplay(); 
}

// 100% matching! 
void ExecAdjustDisplay()
{ 
    if (SystemAdjustFlag != 0) 
    { 
        njAdjustDisplay(sys->adjust_x, sys->adjust_y + 1); 
        
        SystemAdjustFlag = 0; 
    }
} 

// 100% matching! 
void InitPlayLogSystem()
{

}

// 100% matching! 
void ExitPlayLogSystem()
{

}

// 100% matching! 
void ReadPlayLog()
{

}

// 100% matching! 
void WritePlayLog()
{

}
