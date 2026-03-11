#ifndef _SDFUNC_H_
#define _SDFUNC_H_

#include "types.h"

typedef struct RM_SNDENV
{
	// total size: 0x10
	char VolPlayerVoice;   // offset 0x0, size 0x1
    char VolPlayerAction;  // offset 0x1, size 0x1
    char VolWeaponSe;      // offset 0x2, size 0x1
    char VolCartridgeSe;   // offset 0x3, size 0x1
    char VolEnemySe;       // offset 0x4, size 0x1
    char VolBgSe0;         // offset 0x5, size 0x1
    char VolBgSe1;         // offset 0x6, size 0x1
    char VolObjectSe;      // offset 0x7, size 0x1
    char VolEventSe;       // offset 0x8, size 0x1
    char RoomFxLevel;      // offset 0x9, size 0x1
    char RoomFxProg;       // offset 0xA, size 0x1
    char MaxEventSeSlots;  // offset 0xB, size 0x1
    char MaxObjectSeSlots; // offset 0xC, size 0x1
    char Dummy1;           // offset 0xD, size 0x1
    char Dummy2;           // offset 0xE, size 0x1
    char Dummy3;           // offset 0xF, size 0x1
} RM_SNDENV;

typedef struct SND_CMD
{
	// total size: 0x8
	int MaxCommand;          // offset 0x0, size 0x4
    unsigned char ComTbl[2]; // offset 0x4, size 0x2
} SND_CMD;

typedef struct MOV_DEF
{
	// total size: 0xE
    unsigned short sSizeX;  // offset 0x0, size 0x2
    unsigned short sSizeY;  // offset 0x2, size 0x2
    unsigned short dPosX;   // offset 0x4, size 0x2
    unsigned short dPosY;   // offset 0x6, size 0x2
    unsigned short dSizeX;  // offset 0x8, size 0x2
    unsigned short dSizeY;  // offset 0xA, size 0x2
    unsigned char DispType; // offset 0xC, size 0x1
} MOV_DEF; 

typedef struct PDS_VIBPARAM_EX
{
	// total size: 0x4
    unsigned char flag; // offset 0x0, size 0x1
    char power;         // offset 0x1, size 0x1
    unsigned char freq; // offset 0x2, size 0x1
    unsigned char inc;  // offset 0x3, size 0x1
} PDS_VIBPARAM_EX;

typedef struct SPQ_HEADER
{
	// total size: 0x10
    int Offset; // offset 0x0, size 0x4
    int Size;   // offset 0x4, size 0x4
    int Type;   // offset 0x8, size 0x4
    int BankNo; // offset 0xC, size 0x4
} SPQ_HEADER;

typedef struct GAME_WORK
{
    // total size: 0x20
    int Type;     // offset 0x0, size 0x4
    int SlotNo;   // offset 0x4, size 0x4
    int SeNo;     // offset 0x8, size 0x4
    int StartVol; // offset 0xC, size 0x4
    int LastVol;  // offset 0x10, size 0x4
    int StartPan; // offset 0x14, size 0x4
    int LastPan;  // offset 0x18, size 0x4
    int Frame;    // offset 0x1C, size 0x4
} GAME_WORK;

typedef struct NEXTSOUND_INFO
 {
    // total size: 0x28
    int OfsPointBgSe[2];          // offset 0x0, size 0x8
    int FadeNextBgSe[2];          // offset 0x8, size 0x8
    int OfsPointBgm;              // offset 0x10, size 0x4
    int FadeNextBgm;              // offset 0x14, size 0x4
    short NextBgmType;            // offset 0x18, size 0x2
    unsigned short NextBgSeNo[2]; // offset 0x1A, size 0x4
    char ComNextBgm;              // offset 0x1E, size 0x1
    char PointNextBgm;            // offset 0x1F, size 0x1
    unsigned char NextBgmNo;      // offset 0x20, size 0x1
    char ComNextBgSe[2];          // offset 0x21, size 0x2
    char PointNextBgSe[2];        // offset 0x23, size 0x2
    char SetNextBgmFlag;          // offset 0x25, size 0x1
    char SetNextBgSeFlag[2];      // offset 0x26, size 0x2
} NEXTSOUND_INFO;

void bhReleaseFreeMemory(void* mp);
void ExitApplication();
void QuickGetDiscTrayStatus();
void InitFirstSofdec();
int GetBootDiscId();
void InitSofdecSystem(int Mode);
void ExitSofdecSystem();
void InitSoundProgram();
void ExitSoundProgram();
int MountSoundAfs();
void UnmountSoundAfs();
void ExecSoundSynchProgram();
void InitGameSoundSystem();
int SearchAfsInsideFileId(unsigned short KeyCode);
void StopThePsgSound();
int CheckSpecialBank(int Type, int BankNo);
int LoadSoundPackFile(char* SpqFile);
void ExecTransSoundData();
void RequestRoomSoundBank(int StageNo, int RoomNo, int CaseNo);
void RequestArmsSoundBank(int ArmsNo);
void RequestDoorSoundBank(int DoorNo);
void RequestPlayerVoiceSoundBank(int PlayerNo);
int CheckTransEndSoundBank();
void SetRoomSoundCaseNo(int CaseNo);
int GetRoomSoundCaseNo();
int CustomMidiSlotDef(int ObjectSlot, int EventSlot);
void ResetRoomSoundEnvParam();
int wadGetAngle(NJS_POINT3* pPos1, int Ang, NJS_POINT3* pPos2);
int CheckCollision4Sound(NJS_POINT3* pP2);
int Get3DSoundParameter(NJS_POINT3* pP1, NJS_POINT3* pP2, char* pPan, char* pVol, float* pDist, int Mode);
int SetupSeGenericParm(int SlotNo, int SeNo, NJS_POINT3* pPos, int Flag, unsigned int Flag2);
void Set3dSoundFlag(int Type, int SlotNo, unsigned int Flag);
void Reset3dSoundFlag();
void SetUserSoundVolume(int Type, int SlotNo, int StartVol, int LastVol, int Frame);
void SetUserSoundPan(int Type, int SlotNo, int StartPan, int LastPan, int Frame);
void PlayGameSe4Event(GAME_WORK* gp, NJS_POINT3* pPos, int FloorType, int SeType);
void CallSystemSeBasic(int SeNo, int Volume, int FxLevel);
void CallSystemSeEx(int SeNo, int Volume);
void CallSystemSe(int param, int SeNo);
void StopSystemSe();
void SetSyukanModeSoundParam();
void CallPlayerVoice(int SeNo);
int GetPlayerActionSeSlotNo(int Type, int Id);
void CallPlayerFootStepSeEx(int FloorType, int Type, int Flag, int Id, NJS_POINT3* pPos);
void CallPlayerFootStepSe(int FloorType, int Type, int Flag);
void CallPlayerActionSe(int SeNo, int Flag);
void CallPlayerWeaponSeEx(NJS_POINT3* pPos, int SeNo, int SlotNo);
void CallYakkyouSe(NJS_POINT3* pPos, int SeNo);
void CallBackGroundSeEx(unsigned int SlotNo, int SeNo, short Timer);
void CallBackGroundSe(unsigned int SlotNo, int SeNo);
void CallBackGroundSe2(unsigned int SlotNo, int SeNo);
void StopBackGroundSeEx(unsigned int SlotNo, short Timer);
void StopBackGroundSe2(unsigned int SlotNo);
void CallDoorSe(unsigned int No);
void RequestEnemySeBasic(int EnemyNo, NJS_POINT3* pPos, int SeNo, int Flag, int FadeRate);
void RequestEnemySe(int EnemyNo, NJS_POINT3* pPos, int SeNo);
void RequestEnemySeEx(int EnemyNo, NJS_POINT3* pPos, int SeNo, int FadeRate);
int ChechPlayEnemySe(int EnemyNo, int SeNo);
void AllStopEnemySe();
void CallEnemySe(int SlotNo, NJS_POINT3* pPos, int SeNo);
void StopEnemySe(int SlotNo);
int CallNativeEventSe(int SlotNo, NJS_POINT3* pPos, int SeNo, int Mode);
int StopNativeEventSe(int SlotNo);
void RequestObjectSeEx(int ObjectNo, NJS_POINT3* pPos, int SeNo, int Prio, int Type);
void RegistObjectSe(int ObjectNo, NJS_POINT3* pPos, int SeNo, int Prio);
void FreeObjectSe(int ObjectNo);
void PlayBgmEx2(unsigned int PatId, int BgmNo, int FadeInRate, int Volume);
void PlayBgmEx(int BgmNo, int FadeInRate, int Volume);
void PlayBgm(int BgmNo, int FadeInRate);
void PlayBgm2(int BgmNo, int Volume);
void StopBgm(int FadeOutRate);
void StopBgm2();
void PlayVoiceEx2(int PatId, int VoiceNo, NJS_POINT3* pPos, int Mode, int FadeInRate, int PauseFlag);
void PlayVoiceEx(int VoiceNo, NJS_POINT3* pPos, int Mode, int FadeInRate, int PauseFlag);
void PlayVoice(int VoiceNo, NJS_POINT3* pPos, int Mode, int FadeInRate);
void ContinuePlayVoice();
void StopVoice(int FadeOutRate);
int CheckPlayEndAdx(int SlotNo);
int GetTimeAdx(int SlotNo);
void SetRoomSoundFxLevel(char FxProgNo, char FxLevel);
void SetRoomSoundFxLevelEx();
int SearchPlayingEnemySe(int EnemyNo, int Attrib);
int SearchFreeEnemySeSlot();
int CheckPlaySameSe(int EnemyNo, int SeNo, int Flag);
void CallEnemySeMain(unsigned int SlotNo, int SeNo, char Pan, char Vol, int Flag, int FadeRate);
void RegistEnemySlot(int SlotNo, int EnemyNo, int SeNo);
void ResetEnemySeInfo();
void ExecEnemySeManager();
int SearchPlayingObjectSeEx(int ObjectNo, int Mode);
int SearchPlayingObjectSe(int ObjectNo);
int SearchFreeObjectSeSlot();
void CallObjectSe2(unsigned int SlotNo, Object* oip, int Flag);
void RegistObjectSlot(int SlotNo, int ObjectNo, int SeNo);
void ResetObjectSeInfo();
void ExecObjectSeManager();
void RequestSoundFade(int Func, int Attr, short Timer);
void RequestAllStopSoundEx(int AdxFlag, int InSoundFlag, int FadeCount);
void ResetSoundComInfo();
void Com_ExecRoomFadeIn();
void Com_ExecRoomFadeOut();
void Com_ExecCallBgm_And_BgSe();
void Com_StartInitScript();
void Com_FinishInitScript();
void ExecuteSoundCommand();
void SendSoundCommand(unsigned int CommandNo);
void ExecSoundSystemMonitor();
int RequestReadIsoFile(char* FileName, void* DestPtr);
int RequestReadInsideFile(unsigned int PartitionId, unsigned int FileId, void* DestPtr);
int GetIsoFileSize(char* FileName);
int GetInsideFileSize(unsigned int PartitionId, unsigned int FileId);
int GetReadFileStatus();
void ExecFileManager();
int PlayStartMovieEx(int MovieNo, int MovieType, int PauseFlag);
void PlayStopMovieEx(int Mode);
void PlayStopMovie();
int CheckPlayEndMovie();
int GetTimeMoive();
int WaitPrePlayMovie();
int PlayMovieMain();
void SetEventVibrationMode(int Mode);
void StartVibrationBasic(int PortNo, int AtrbId, int VibNo);
void StartVibrationEx(int AtrbId, int VibNo);
void StopVibrationBasic(int PortNo);
void StopVibrationEx();
void SetAdjustDisplay();
void RequestAdjustDisplay(int AdjustX, int AdjustY);
void ExecAdjustDisplay();
void InitPlayLogSystem();
void ExitPlayLogSystem();
void ReadPlayLog();
void WritePlayLog(int param1, int param2);

extern int OpenDriveTrayFlag;
extern int RoomFxLevel;
extern char FxLevelTimer;
extern int CurrentFxLevel;
extern int AddFxLevel;
extern int PatId[4];

#endif
