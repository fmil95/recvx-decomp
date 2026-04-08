#ifndef _ADV_H_
#define _ADV_H_

#include "types.h"

typedef struct ADV_WORK
{
	// total size: 0xD8
    int PatId;                        // offset 0x0, size 0x4
    int Mode;                         // offset 0x4, size 0x4
    int Mode2;                        // offset 0x8, size 0x4
    int NextMode;                     // offset 0xC, size 0x4
    int NextReturnCode;               // offset 0x10, size 0x4
    int PortId;                       // offset 0x14, size 0x4
    int OptIndex;                     // offset 0x18, size 0x4
    int OptLevel;                     // offset 0x1C, size 0x4
    int NextOptLevel;                 // offset 0x20, size 0x4
    int OptScrX;                      // offset 0x24, size 0x4
    int OptScrY;                      // offset 0x28, size 0x4
    unsigned int PalNo;               // offset 0x2C, size 0x4
    unsigned int PalMode;             // offset 0x30, size 0x4
    unsigned int FontBaseColor;       // offset 0x34, size 0x4
    unsigned char* SysMemPtr;         // offset 0x38, size 0x4
    unsigned char* MsgPtr;            // offset 0x3C, size 0x4
    unsigned char* ptr[8];            // offset 0x40, size 0x20
    float Timer;                      // offset 0x60, size 0x4
    float FadeRate;                   // offset 0x64, size 0x4
    float FadeSpeed;                  // offset 0x68, size 0x4
    float SaverTimer;                 // offset 0x6C, size 0x4
    float SaverRate;                  // offset 0x70, size 0x4
    float FlushCount;                 // offset 0x74, size 0x4
    float FlushSpeed;                 // offset 0x78, size 0x4
    float FlushCount2;                // offset 0x7C, size 0x4
    float FlushSpeed2;                // offset 0x80, size 0x4
    float ScrollPlatePosX[2][2];      // offset 0x84, size 0x10
    char Active;                      // offset 0x94, size 0x1
    char AppMode;                     // offset 0x95, size 0x1
    char ExtraFlag;                   // offset 0x96, size 0x1
    char FadeType;                    // offset 0x97, size 0x1
    char SaverCommand;                // offset 0x98, size 0x1
    char Count;                       // offset 0x99, size 0x1
    char LastLevel;                   // offset 0x9A, size 0x1
    char FromTitle;                   // offset 0x9B, size 0x1
    char CurrentDiscId;               // offset 0x9C, size 0x1
    char NextDiscId;                  // offset 0x9D, size 0x1
    char ErrorId;                     // offset 0x9E, size 0x1
    unsigned char ErrorMsgFlushCount; // offset 0x9F, size 0x1
    char AnimId;                      // offset 0xA0, size 0x1
    unsigned char AnimTime;           // offset 0xA1, size 0x1
    char GenFlag;                     // offset 0xA2, size 0x1
    char PalFlag;                     // offset 0xA3, size 0x1
    char SrFlag;                      // offset 0xA4, size 0x1
    char OptFadeType;                 // offset 0xA5, size 0x1
    char TexFlag;                     // offset 0xA6, size 0x1
    char SoundMode;                   // offset 0xA7, size 0x1
    char vibration;                   // offset 0xA8, size 0x1
    char keytype;                     // offset 0xA9, size 0x1
    char adjust_x;                    // offset 0xAA, size 0x1
    char adjust_y;                    // offset 0xAB, size 0x1
    char OptSaveFlag;                 // offset 0xAC, size 0x1
    char vMode;                       // offset 0xAD, size 0x1
    char DriveNo;                     // offset 0xAE, size 0x1
    char MsgNo;                       // offset 0xAF, size 0x1
    char DepthLevel;                  // offset 0xB0, size 0x1
    char OldVmOpMode;                 // offset 0xB1, size 0x1
    char VmOpMode;                    // offset 0xB2, size 0x1
    char SetTexture[2];               // offset 0xB3, size 0x2
    char KeyCommandCount[7];          // offset 0xB5, size 0x7
    char Cursor[3];                   // offset 0xBC, size 0x3
    char CursorMax[3];                // offset 0xBF, size 0x3
    char CursorFlag[4][4];            // offset 0xC2, size 0x10
    char ModeCommandId[4];            // offset 0xD2, size 0x4
} ADV_WORK;

typedef struct PVP_INFO 
{
    // total size: 0x10
    char ppStrPvpl[4];             // offset 0x0, size 0x4
    unsigned int ppNextTag;        // offset 0x4, size 0x4
    unsigned short ppCategoryCode; // offset 0x8, size 0x2
    unsigned short ppBankId;       // offset 0xA, size 0x2
    unsigned short ppEntryOffset;  // offset 0xC, size 0x2
    unsigned short ppEntryCount;   // offset 0xE, size 0x2
} PVP_INFO;

void CallPlayerDeadVoice(int PlayerNo);
void CallSystemVoice(int VoiceNo);
float GetSamurai(int Time);
void InitAdvSystem();
void ResetAdvSystem();
void MountAdvAfs();
unsigned char* AdvGetResourcePtr(unsigned char* bp, unsigned int ResId);
void AdvSetSoundMode();
void AdvCheckSoftReset(int Flag);
void AdvPushRoomTexture();
void AdvPopRoomTexture();
void AdvPushPaletteData();
void AdvPopPaletteData();
void RequestAdvInsideFileEx(int InsideFileId, int MemoryBlockNo);
void RequestAdvInsideFile(int InsideFileId);
void FreeAdvMemoryEx(int MemoryBlockNo);
void AllFreeAdvMemory();
int CheckReadEndAdvInsideFile();
void CheckReadEndAdvInsideFile2Ex(int NextMode, int Flag);
void CheckReadEndAdvInsideFile2(int NextMode);
void RequestAdvFade(int FadeType, float FadeSpeed);
int CheckAdvFade();
void AdvDrawFadePolygon(int Type, float Rate, unsigned int BaseColor);
void ExecuteAdvFadeEx(int Type);
void ExecuteAdvFade();
void StopAdvScreenSaver(int Flag);
void ExecuteAdvScreenSaver();
void CheckAdvScreenSaverStopKey(int PortId);
unsigned int AdvGetOkButton();
unsigned int AdvGetCancelButton();
void SetPvrInfo(NJS_TEXNAME* np, NJS_TEXINFO* ip, unsigned char* pp, int param1, unsigned int param2);
int TransPvpData(unsigned char* pp, int Mode);
void AdvTransShadowPalette();
void AdvEasyDrawWindow(NJS_POINT3* tlp, NJS_POINT3* brp, unsigned int WindowColor, unsigned int BackColor);
void AdvEasyDrawTexture(int TexNo, unsigned int BaseColor, QUAD* qp, float PosZ, int TransFlag);
void AdvEasyDrawTextureS(int TexNo, unsigned int BaseColor, QUAD* qp, float PosZ, int TransFlag, unsigned int ShadowAlpha);
void SetQuadPos(float StartX, float StartY, float SizeX, float SizeY, QUAD* qp);
void SetQuadUv2Ex(float u, float v, float SizeX, float SizeY, unsigned int ListNo, unsigned int TexNo, QUAD* qp);
void SetQuadUv2(float u, float v, float SizeX, float SizeY, unsigned int TexNo, QUAD* qp);
void AdvDwawOnePictureEx(int TexNo, unsigned int BaseColor);
void AdvDwawOnePicture(int TexNo);
void AdvEasySetupTextureBasic(unsigned char* xp, int ListNo, int TexNo);
void AdvEasySetupTextureEx(int ListNo);
void AdvEasySetupTexture();
void AdvEasySetTextureList(int ListNo);
void AdvEasyTransTextureBasic(int ListNo, int TexNum, int Flag);
void AdvEasyTransTextureEx(int ListNo);
void AdvEasyTransTexture();
void AdvEasyReleaseTextureEx(int ListNo);
void AdvEasyReleaseTexture();
void AdvEasyReleaseAllTexture();
int AdvGetCurrentPort();
int CheckConnectVmDrive(int param, int SlotNo);
int FindFirstVmDrive();
float AdvEasyDispMessage(float PosX, float PosY, unsigned int MessageNo);
float AutoSaveLoadEasyDispMessage(float PosX, float PosY, unsigned char* ucpMsbTop, unsigned int MessageNo);
int DispVmWarningMessage(int MsgId);
void DefaultSetOption();
int Adv_FirstWarningMessage();
int Adv_CapcomLogo();
void ResetFlushPlate();
void FlushPlate();
void DisplayTitleBg();
void DisplayPressStartPlate(float FadeRate);
void DisplayGameModePlate(int Cursor, int CursorMax, float FadeRate, int Flag);
void DisplayNewGamePlate(int Cursor, float FadeRate, int Flag);
void DisplayExtraGamePlate(int Cursor, float FadeRate, int Flag);
void FadeInPlate(int NextMode);
void FadeOutPlate();
void TitleCall(int PortId, int ReturnCode);
int CheckButton(int Level, int Flag, int MaxFlag);
int CheckStartButton();
int Adv_BioCvTitle();
void ResetOptionMenuParam(int Mode);
void DisplayOptionScrollPlate(float PosX, float PosY);
void DisplayOptionBg(int Level, int Flag);
int DisplayOptionPlateLevel0(int PortId, int Flag);
int DisplayOptionPlateLevel1(int PortId, int Flag);
int DisplayOptionPlateLevel2(int PortId, int Flag);
int DisplayOptionPlateLevel3(int PortId, int Flag);
int DisplayOptionPlate(int PortId, int Level, int Flag);
int Adv_GameOptionScreen();
int Adv_ChangeDiscScreen();
int Adv_SoundMuseum();

extern unsigned char SaveLoadMessage[10956];

#endif
