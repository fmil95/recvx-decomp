#include "adv.h"

/*unsigned char SaveLoadMessage[10956];
_anon53 OptionDef[7];*/
int AdvFirstInitFlag;
int PatId[4];
ADV_WORK AdvWork;
SYS_WORK* sys;
NJS_TEXMEMLIST tbuf[256];
ROM_WORK* rom;
unsigned int palbuf[4096];
PAD_WRK Pad[4];
NJS_TEXMEMLIST* Ps2_current_texmemlist;
QUAD Qtex[16];
NJS_TEXINFO AdvTexInfo[2][8];
NJS_TEXNAME AdvTexName[2][8];
NJS_TEXLIST AdvTexList[2] = { {&AdvTexName[0][0], 8}, {&AdvTexName[1][0], 8} };
char AdvTexPalBank[2][8];
int CurrentPortId;
unsigned char FontSz[126];
float FontScaleCR;
float FontScaleX;
ADV_VM_MSG AdvVmMsgDef[21] = {{-1.0f, 32.0f, 23, 21, 1}, {-1.0f, 176.0f, 25, -1, 0}, {-1.0f, 32.0f, 33, 21, 1}, {-1.0f, 208.0f, 30, 22, 1}, {-1.0f, 224.0f, 27, 22, 1}, {-1.0f, 32.0f, 24, 22, 1}, {-1.0f, 416.0f, 28, -1, 0}, {-1.0f, 32.0f, 24, 21, 1}, {-1.0f, 224.0f, 31, 22, 1}, {-1.0f, 224.0f, 32, 22, 1}, {-1.0f, 32.0f, 23, 22, 1}, {-1.0f, 32.0f, 33, 20, 1}, {-1.0f, 32.0f, 33, 22, 1}, {-1.0f, 32.0f, 34, 20, 1}, {-1.0f, 32.0f, 35, 20, 1}, {-1.0f, 32.0f, 36, 20, 1}, {-1.0f, 32.0f, 37, 20, 1}, {-1.0f, 32.0f, 38, 20, 1}, {-1.0f, 32.0f, 39, 20, 1}, {-1.0f, 32.0f, 40, 20, 1}, {-1.0f, 32.0f, 41, 20, 1}};
SYSLOAD_SCREEN* pSysLoad;
SYSLOAD_SCREEN SysLoad;
/*float ColorBarSizeY;
float RedLinePosY;
unsigned int ColorBarBright;
tagSYSSAVE_SCREEN* pSysSave;
unsigned char* vwbmemp;
tagSYSSAVE_SCREEN SysSave;

void CallPlayerDeadVoice(int PlayerNo);
void CallSystemVoice(int VoiceNo);
float GetSamurai(int Time);
void InitAdvSystem();
void ResetAdvSystem();*/
void MountAdvAfs();
/*unsigned char* AdvGetResourcePtr(unsigned char* bp, unsigned int ResId);
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
void ExecuteAdvFade();*/
void StopAdvScreenSaver(int Flag);
/*void ExecuteAdvScreenSaver();
void CheckAdvScreenSaverStopKey(int PortId);
unsigned int AdvGetOkButton();
unsigned int AdvGetCancelButton();
void SetPvrInfo(_anon20* np, _anon16* ip, unsigned char* pp);
int TransPvpData(unsigned char* pp, int Mode);
void AdvTransShadowPalette();
void AdvEasyDrawWindow(_anon32* tlp, _anon32* brp, unsigned int WindowColor, unsigned int BackColor);
void AdvEasyDrawTexture(int TexNo, unsigned int BaseColor, _anon0* qp, float PosZ, int TransFlag);
void AdvEasyDrawTextureS(int TexNo, unsigned int BaseColor, _anon0* qp, float PosZ, int TransFlag, unsigned int ShadowAlpha);
void SetQuadPos(float StartX, float StartY, float SizeX, float SizeY, _anon0* qp);
void SetQuadUv2Ex(float u, float v, float SizeX, float SizeY, unsigned int ListNo, unsigned int TexNo, _anon0* qp);
void SetQuadUv2(float u, float v, float SizeX, float SizeY, unsigned int TexNo, _anon0* qp);
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
int CheckConnectVmDrive(int SlotNo);
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
int Adv_SoundMuseum();*/

// 100% matching! 
void CallPlayerDeadVoice(int PlayerNo)
{ 
    PlayBgmEx2(PatId[3], PlayerNo + 8, 1, -45);
}

// 100% matching! 
void CallSystemVoice(int VoiceNo) 
{ 
    PlayVoiceEx2(PatId[3], VoiceNo + 16, NULL, 1, 0, 0);
}

// 100% matching! 
float GetSamurai(int Time)
{ 
    return 1.0f / (((Time / 100) * 30) + (((Time % 100) * 6) / 10));
} 

// 100% matching! 
void InitAdvSystem()
{ 
    ADV_WORK* ap;

    ap = &AdvWork;

    if (AdvFirstInitFlag == 0) 
    { 
        memset(&AdvWork, 0, sizeof(ADV_WORK)); 
        
        ap->PatId = -1; 
        
        ap->Active = 0; 
        
        AdvFirstInitFlag = 1; 
    } 
    
    MountAdvAfs(); 
} 

// 100% matching!
void ResetAdvSystem()
{ 
	ADV_WORK* ap; 
    int i;

    ap = (ADV_WORK*)&AdvWork; 

    if (ap->Active != 0) 
    {
        ExitApplication();
    }
    
    ap->Active = 1; 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
    
    njFogDisable(); 
    
    for (i = 0; i < 8; i++) 
    { 
        ap->ptr[i] = NULL; 
    } 
    
    for (i = 0; i < 2; i++) 
    { 
        ap->SetTexture[i] = 0; 
    } 
    
    for (i = 0; i < 7; i++) 
    { 
        ap->KeyCommandCount[i] = 0; 
    } 
  
    ap->NextReturnCode = 0; 
    
    ap->Count = 0; 
    
    ap->OptIndex = 0; 
    
    ap->ErrorId = 0; 
    ap->ErrorMsgFlushCount = 0; 
    
    ap->ExtraFlag = 0; 
    
    ap->Mode2 = 0; 
    ap->NextMode = 0; 
    
    ap->DepthLevel = 0; 
    
    ap->GenFlag = 0; 
    
    ap->OptFadeType = 0; 
    
    ap->PalNo = 0; 
    ap->PalFlag = 1; 
    
    ap->TexFlag = 0; 
    
    ap->SrFlag = 0; 
    
    ap->SoundMode = -1; 
    
    ap->OptSaveFlag = 0; 
    
    ap->vMode = 0; 
    
    ap->DriveNo = 0;  
    
    ap->VmOpMode = ap->OldVmOpMode = 0; 

    StopAdvScreenSaver(1); 
} 

// 100% matching! 
void MountAdvAfs() 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
    
    temp->PatId = PatId[3]; 
}

// 100% matching!
unsigned char* AdvGetResourcePtr(unsigned char* bp, unsigned int ResId) 
{ 
    return &bp[((int*)bp)[ResId]]; 
}

// 100% matching!
void AdvSetSoundMode() 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    if (ap->SoundMode >= 0) 
    { 
        syCfgSetSoundMode(ap->SoundMode); 
        
        ap->SoundMode = -1; 
    }
} 

// 100% matching!
void AdvCheckSoftReset(int Flag)
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    if ((ap->SrFlag == 0) && (!(sys->ss_flg & 0x20000)) && (CheckSoftResetKeyFlag(-1) != 0)) 
    {
        if (Flag == 0) 
        { 
            ap->Mode = -1;
        }
        else 
        { 
            ap->Mode2 = -1; 
        } 
        
        AdvSetSoundMode(); 
    } 
} 

// 100% matching!
void AdvPushRoomTexture() 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    ap->TexFlag = 0; 
    
    if (rom->mdl.texP != NULL)
    { 
        ap->SysMemPtr = sys->memp; 
        
        sys->memp = (unsigned char*)bhCopyTexmem2MainmemSub(rom->mdl.texP, (char*)sys->memp); 
        
        njReleaseTexture(rom->mdl.texP); 
        
        bhGarbageTexture(tbuf, 256); 
        
        ap->TexFlag = 1; 
    }
} 

// 100% matching!
void AdvPopRoomTexture()
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    if ((ap->TexFlag != 0) && (rom->mdl.texP != NULL)) 
    { 
        bhCopyMainmem2Texmem(rom->mdl.texP); 
        
        sys->memp = ap->SysMemPtr; 
    }
    
    ap->TexFlag = 0; 
} 

// 100% matching!
void AdvPushPaletteData() 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
    
    njMemCopy4(&palbuf[3072], palbuf, 1024); 
    
    temp->PalMode = njGetPaletteMode(); 
}

// 100% matching!
void AdvPopPaletteData() 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
    
    njSetPaletteMode(temp->PalMode); 
    
    njMemCopy4(palbuf, &palbuf[3072], 1024); 
    
    sys->gm_flg |= 0x4; 
    
    if ((sys->st_flg & 0x2)) 
    { 
        njFogEnable(); 
    } 
    
    sys->gm_flg |= 0x8000; 
} 

// 100% matching!
void RequestAdvInsideFileEx(int InsideFileId, int MemoryBlockNo)
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    ap->ptr[MemoryBlockNo] = bhGetFreeMemory(GetInsideFileSize(ap->PatId, InsideFileId), 32); 
    
    RequestReadInsideFile(ap->PatId, InsideFileId, ap->ptr[MemoryBlockNo]); 
} 

// 100% matching! 
void RequestAdvInsideFile(int InsideFileId) 
{ 
    RequestAdvInsideFileEx(InsideFileId, 0);
}

// 100% matching!
void FreeAdvMemoryEx(int MemoryBlockNo)
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork; 

    if (temp->ptr[MemoryBlockNo] != NULL) 
    { 
        bhReleaseFreeMemory(temp->ptr[MemoryBlockNo]); 
        
        temp->ptr[MemoryBlockNo] = NULL; 
    } 
} 

// 100% matching!
void AllFreeAdvMemory()
{ 
    int i;

    for (i = 7; i >= 0; i--) 
    { 
        FreeAdvMemoryEx(i); 
    } 
} 

// 100% matching!
int CheckReadEndAdvInsideFile()
{ 
    int ReturnCode;

    ReturnCode = GetReadFileStatus(); 
    
    if (ReturnCode == -1) 
    { 
        AllFreeAdvMemory(); 
    }
    
    return ReturnCode; 
} 

// 100% matching!
void CheckReadEndAdvInsideFile2Ex(int NextMode, int Flag) 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    switch (CheckReadEndAdvInsideFile()) 
    {               
    case -1:
        if (Flag == 0) 
        { 
            ap->Mode = -1;
        }
        else
        { 
            ap->Mode2 = -1;
        }
        
        break; 
    case 0:
        if (Flag == 0) 
        { 
            ap->Mode = NextMode;
        } 
        else
        { 
            ap->Mode2 = NextMode; 
        }
        
        break;
    case 1:
        break;
    } 
}

// 100% matching!
void CheckReadEndAdvInsideFile2(int NextMode)
{ 
    CheckReadEndAdvInsideFile2Ex(NextMode, 0);
}

// 100% matching!
void RequestAdvFade(int FadeType, float FadeSpeed) 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    ap->FadeType = FadeType; 
    
    ap->FadeSpeed = FadeSpeed; 
    
    switch (FadeType) 
    {              
    case 1:
        ap->FadeType = 0; 
        break; 
    case 2:
        ap->FadeRate = 1.0f;
        break;
    case 3:
        ap->FadeRate = 0; 
        break;
    }
}

// 100% matching!
int CheckAdvFade() 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork; 
    
    return temp->FadeType;
}

// 98.60% matching
void AdvDrawFadePolygon(int Type, float Rate, unsigned int BaseColor)
{ 
	NJS_POLYGON_VTX poly[4];
    float PosZ[4] = { 
        0.98f,
        0.90f,
        1.99f,
        1.98f
    };
    
    BaseColor |= ((unsigned int)(255.0f * Rate) & 0xFF) << 24;
    
    poly[0].x = -2.0f; 
    poly[0].y = -2.0f; 
    
    poly[1].x = -2.0f; 
    poly[1].y = 482.0f; 
    
    poly[2].x = 642.0f; 
    poly[2].y = -2.0f; 
    
    poly[3].x = 642.0f; 
    poly[3].y = 482.0f; 
    
    poly[0].z = poly[1].z = poly[2].z = poly[3].z = PosZ[Type]; 
    
    poly[0].col = poly[1].col = poly[2].col = poly[3].col = BaseColor; 
    
    njDrawPolygon(poly, 4, 1); 
} 

// 100% matching!
void ExecuteAdvFadeEx(int Type)
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    switch (ap->FadeType) 
    { 
    case 2:
        ap->FadeRate -= ap->FadeSpeed; 
        
        if (ap->FadeRate <= 0) 
        { 
            ap->FadeRate = 0; 
            
            ap->FadeType = 0; 
        } 
        
        AdvDrawFadePolygon(Type, ap->FadeRate, 0); 
        break; 
    case 3:
        ap->FadeRate += ap->FadeSpeed; 
        
        if (ap->FadeRate >= 1.0f)
        { 
            ap->FadeRate = 1.0f; 
            
            ap->FadeType = 0; 
        }
        
        AdvDrawFadePolygon(Type, ap->FadeRate, 0); 
        break;
    }
} 

// 100% matching!
void ExecuteAdvFade() 
{
    ExecuteAdvFadeEx(0);
}

// 100% matching!
void StopAdvScreenSaver(int Flag)
{
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    ap->SaverTimer = 9000.0f;
    
    ap->SaverCommand = 0; 
    
    if (Flag != 0) 
    { 
        ap->SaverRate = 0;
    } 
}

// 100% matching!
void ExecuteAdvScreenSaver()
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    if (ap->SaverCommand == 0) 
    { 
        ap->SaverTimer -= 1.0f; 
        
        if (ap->SaverTimer < 0) 
        { 
            ap->SaverCommand = 1; 
            
            ap->SaverRate = 0;
        }
    }
    
    if (ap->SaverCommand == 1) 
    { 
        ap->SaverRate += 0.01f;
        
        if (ap->SaverRate >= 0.5f)
        { 
            ap->SaverRate = 0.5f;
        }
    } 
    else 
    { 
        ap->SaverRate -= 0.05f; 
        
        if (ap->SaverRate <= 0) 
        { 
            ap->SaverRate = 0; 
        }
    }
    
    AdvDrawFadePolygon(2, ap->SaverRate, 0xF);
} 

// 100% matching!
void CheckAdvScreenSaverStopKey(int PortId)
{ 
    if ((Pad[PortId].on != 0) || ((Pad[PortId].x1 != 0) || (Pad[PortId].y1 != 0))) 
    { 
        StopAdvScreenSaver(0); 
    }
} 

// 100% matching!
unsigned int AdvGetOkButton()
{ 
    unsigned int ButtonDef[3] = {192, 96, 160}; 
    
    return ButtonDef[sys->keytype]; 
}

// 100% matching!
unsigned int AdvGetCancelButton() 
{ 
    unsigned int ButtonDef[3] = {32, 128, 64}; 
    
    return ButtonDef[sys->keytype]; 
} 

// 100% matching!
void SetPvrInfo(NJS_TEXNAME* np, NJS_TEXINFO* ip, unsigned char* pp, int param1, unsigned int param2) // fourth and fifth parameters are not present on the debugging symbols
{ 
    TIM2_PICTUREHEADER_SMALL* pPichd;
    unsigned int GlobalIndex;
    
    ((TIM2_PICTUREHEADER*)pp)->PictFormat = 0; 
    
    GlobalIndex = ((TIM2_PICTUREHEADER*)pp)->Gindex; 
    
    pPichd = (TIM2_PICTUREHEADER_SMALL*)&((TIM2_PICTUREHEADER*)pp)->TotalSize; 
    
    Ps2CheckTextureAlpha(pp); 
    
    njSetTextureInfo(ip, (unsigned short*)pp, pPichd->PictFormat, pPichd->ImageWidth, pPichd->ImageHeight); 
    njSetTextureName(np, ip, GlobalIndex, 0x40800000); 
} 

// 100% matching!
int TransPvpData(unsigned char* pp, int Mode) 
{ 
    PVP_INFO* pPvp;
    unsigned short temp; // not from the debugging symbols
    short temp2; // not from the debugging symbols

    pPvp = (PVP_INFO*)pp;

    if (strncmp(&pPvp->ppStrPvpl, "PVPL", 4) != 0)
    { 
        return -1; 
    }
    
    temp = pPvp->ppCategoryCode; 
    
    temp2 = pPvp->ppBankId;
    
    if (Mode != 0) 
    { 
        njSetPaletteMode(temp); 
    } 
    
    return temp2; 
} 

// 100% matching!
void AdvTransShadowPalette() 
{ 
    unsigned int* lp;
    unsigned int* p;
    int i;

    lp = p = (unsigned int*)bhGetFreeMemory(64, 32);       
    
    *lp++ = 0xFFFFFF; 
    
    for (i = 0; i < 15; i++) 
    { 
        *lp++ = 0xFF000000; 
    } 
    
    njSetPaletteData(16, 16, p);
    
    bhReleaseFreeMemory(p); 
} 

// 100% matching!
void AdvEasyDrawWindow(NJS_POINT3* tlp, NJS_POINT3* brp, unsigned int WindowColor, unsigned int BackColor)
{ 
    NJS_POLYGON_VTX poly[4];

    poly[0].z = poly[2].z = tlp->z;
    poly[1].z = poly[3].z = brp->z; 
    
    poly[0].col = poly[1].col = poly[2].col = poly[3].col = WindowColor; 
    
    poly[0].x = poly[1].x = tlp->x; 
    poly[2].x = poly[3].x = brp->x; 
    
    poly[0].y = poly[2].y = tlp->y; 
    poly[1].y = poly[3].y = 4.0f + tlp->y; 
    
    njDrawPolygon(poly, 4, 0); 
    
    poly[0].y = poly[2].y = brp->y - 4.0f; 
    poly[1].y = poly[3].y = brp->y; 
    
    njDrawPolygon(poly, 4, 0); 
    
    poly[0].x = poly[1].x = tlp->x; 
    poly[2].x = poly[3].x = 3.0f + tlp->x; 
    
    poly[0].y = poly[2].y = tlp->y; 
    poly[1].y = poly[3].y = brp->y; 
    
    njDrawPolygon(poly, 4, 0);
    
    poly[0].x = poly[1].x = brp->x - 4.0f; 
    poly[2].x = poly[3].x = 3.0f + (brp->x - 4.0f); 
    
    njDrawPolygon(poly, 4, 0); 
    
    poly[0].x = poly[1].x = tlp->x; 
    poly[2].x = poly[3].x = brp->x; 
    
    poly[0].y = poly[2].y = tlp->y; 
    poly[1].y = poly[3].y = brp->y; 
    
    poly[0].z = poly[2].z = tlp->z - 0.001f; 
    poly[1].z = poly[3].z = brp->z - 0.001f; 
    
    poly[0].col = poly[1].col = poly[2].col = poly[3].col = BackColor; 
    
    njDrawPolygon(poly, 4, 1);
} 

// 100% matching!
void AdvEasyDrawTexture(int TexNo, unsigned int BaseColor, QUAD* qp, float PosZ, int TransFlag)
{ 
    if (TransFlag != 0) 
    { 
        ((TIM2_PICTUREHEADER*)Ps2_current_texmemlist->texinfo.texsurface.pSurface)->ClutChange |= 0x8000; 
    }
    
    njQuadTextureStart(TransFlag); 
    
    njSetQuadTexture(TexNo, BaseColor); 
    
    njDrawQuadTexture(qp, PosZ); 
    
    njQuadTextureEnd(); 
} 

// 100% matching!
void AdvEasyDrawTextureS(int TexNo, unsigned int BaseColor, QUAD* qp, float PosZ, int TransFlag, unsigned int ShadowAlpha) 
{ 
    QUAD* sqp; 

    sqp = &Qtex[15]; 

    AdvEasyDrawTexture(TexNo, BaseColor, qp, PosZ, TransFlag); 
    
    memcpy(sqp, qp, 32); 
    
    sqp->x1 = 3.0f + qp->x1; 
    sqp->y1 = 3.0f + qp->y1; 
    
    sqp->x2 = 3.0f + qp->x2; 
    sqp->y2 = 3.0f + qp->y2; 
    
    AdvEasyDrawTexture(TexNo, ShadowAlpha << 24, sqp, PosZ - 0.001f, 1); 
} 

// 100% matching!
void SetQuadPos(float StartX, float StartY, float SizeX, float SizeY, QUAD* qp)
{ 
    qp->x1 = StartX; 
    qp->y1 = StartY; 
    
    qp->x2 = StartX + (SizeX - 1.0f); 
    qp->y2 = StartY + (SizeY - 1.0f);
}

// 100% matching!
void SetQuadUv2Ex(float u, float v, float SizeX, float SizeY, unsigned int ListNo, unsigned int TexNo, QUAD* qp)
{ 
    float TexX;
    float TexY;
    NJS_TEXMEMLIST* temp; // not from the debugging symbols

    temp = (NJS_TEXMEMLIST*)AdvTexList[ListNo].textures[TexNo].texaddr; 
    
    TexX = (temp->texinfo.texsurface.nWidth >= 0) ? temp->texinfo.texsurface.nWidth : temp->texinfo.texsurface.nWidth / 3; 
    TexY = (temp->texinfo.texsurface.nHeight >= 0) ? temp->texinfo.texsurface.nHeight : temp->texinfo.texsurface.nHeight / 3; 
   
    qp->u1 = u / TexX; 
    qp->v1 = v / TexY; 
    
    qp->u2 = (u + (SizeX - 1.0f)) / TexX; 
    qp->v2 = (v + (SizeY - 1.0f)) / TexY;
}

// 100% matching!
void SetQuadUv2(float u, float v, float SizeX, float SizeY, unsigned int TexNo, QUAD* qp)
{
    SetQuadUv2Ex(u, v, SizeX, SizeY, 0, TexNo, qp);
}

// 98.75% matching
void AdvDwawOnePictureEx(int TexNo, unsigned int BaseColor)
{ 
    QUAD* qp; 

    qp = (QUAD*)Qtex; 
    
    njTextureFilterMode(1); 
    
    SetQuadPos(0, 0, 1024.0f, 512.0f, qp);
    SetQuadUv2(0, 0, 1024.0f, 512.0f, TexNo, qp);
    
    AdvEasyDrawTexture(TexNo, BaseColor, qp, 0.01f, 0);
    
    njTextureFilterMode(0);
} 

// 100% matching!
void AdvDwawOnePicture(int TexNo)
{ 
    AdvDwawOnePictureEx(TexNo, -1);
}

// 100% matching!
void AdvEasySetupTextureBasic(unsigned char* xp, int ListNo, int TexNo) 
{ 
    ADV_WORK* ap; 
    unsigned int* lp;

    ap = (ADV_WORK*)&AdvWork; 
    
    lp = (unsigned int*)xp; 
    
    AdvTexPalBank[ListNo][TexNo] = -1; 
    
    if (lp[0] != 0)
    { 
        ap->PalNo = TransPvpData(xp + lp[0], ap->PalFlag); 
        
        if (ap->PalFlag != 0)
        { 
            ap->PalFlag = 0;
        } 
        
        AdvTexPalBank[ListNo][TexNo] = ap->PalNo;
    }
    
    SetPvrInfo(&AdvTexName[ListNo][TexNo], &AdvTexInfo[ListNo][TexNo], xp + lp[1], -1, ap->PalNo); 
} 

// 100% matching!
void AdvEasySetupTextureEx(int ListNo) 
{ 
    ADV_WORK* ap;

    ap = (ADV_WORK*)&AdvWork;
    
    AdvEasySetupTextureBasic(ap->ptr[ap->Count], ListNo, ap->Count); 
    
    ap->Count++; 
} 

// 100% matching!
void AdvEasySetupTexture()
{ 
    AdvEasySetupTextureEx(0);
}

// 100% matching!
void AdvEasySetTextureList(int ListNo)
{ 
    njSetTexture(&AdvTexList[ListNo]); 
    
    njSetTextureNum(0); 
} 

// 100% matching!
void AdvEasyTransTextureBasic(int ListNo, int TexNum, int Flag) 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    AdvTexList[ListNo].nbTexture = TexNum; 
    
    njLoadTexture(&AdvTexList[ListNo]); 
    
    AdvEasySetTextureList(ListNo); 
    
    if (Flag == 0) 
    { 
        AllFreeAdvMemory(); 
    }
    
    ap->Count = 0; 
    
    ap->SetTexture[ListNo] = 1; 
} 

// 100% matching!
void AdvEasyTransTextureEx(int ListNo)
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
    
    AdvEasyTransTextureBasic(ListNo, temp->Count, 0);
}

// 100% matching!
void AdvEasyTransTexture() 
{ 
    AdvEasyTransTextureEx(0);
}

// 100% matching!
void AdvEasyReleaseTextureEx(int ListNo) 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;

    if (temp->SetTexture[ListNo] != 0) 
    { 
        njReleaseTexture(&AdvTexList[ListNo]); 
        
        temp->SetTexture[ListNo] = 0;
    }
    
    bhGarbageTexture(NULL, 0); 
} 

// 100% matching!
void AdvEasyReleaseTexture()
{ 
    AdvEasyReleaseTextureEx(0);
}

// 100% matching!
void AdvEasyReleaseAllTexture() 
{ 
    ADV_WORK* ap; 
    int i;

    ap = (ADV_WORK*)&AdvWork; 

    for (i = 0; i < 2; i++) 
    { 
        ap->SetTexture[i] = 0; 
    } 
    
    njReleaseTextureAll(); 
    
    sys->ss_flg &= ~0x40; 
}

// 100% matching!
int AdvGetCurrentPort()
{ 
    return CurrentPortId;
} 

// 100% matching!
int CheckConnectVmDrive(int param, int SlotNo) // first parameter is not present on the debugging symbols
{ 
    MEMORYCARDSTATE McDrive;
    MEMORYCARDSTATE* pMcDrive;
    
    pMcDrive = CreateMemoryCard(&McDrive); 
    
    if (GetMcSelectPortType(pMcDrive, SlotNo - 1) == 2)
    {
        return ((SlotNo % 6) - 1) + ((SlotNo / 6) * 2); 
    }

    return -1;
} 

// 100% matching!
int FindFirstVmDrive() 
{ 
    int j;
    int DriveNo;

    for (j = 1; ; ) 
    { 
        DriveNo = CheckConnectVmDrive(0, j); 
        
        if (DriveNo >= 0) 
        { 
            return DriveNo;
        } 
        
        j++;
        
        if (j >= 3) 
        {
            break;
        }
    }
        
    return -1; 
}

// 100% matching! 
float AdvEasyDispMessage(float PosX, float PosY, unsigned int MessageNo)
{ 
    unsigned char* dmp;
    unsigned char* smp;
    unsigned short* mp;
    unsigned short* nmp;
    unsigned int* temp; // not from the debugging symbols
    int x;
    int y;
    int LoopFlag = 1;
    int SearchFlag;
    float sx;
    float SizeX;
    float sy;
    ADV_WORK* temp2; // not from the debugging symbols

    sy = PosY;

    temp2 = (ADV_WORK*)&AdvWork; 

    smp = (unsigned char*)((int)temp2->MsgPtr + ((int*)temp2->MsgPtr)[MessageNo + 1]); 
    
    dmp = syMalloc(1024); 
    
    memcpy(dmp, smp, 1024); 

    nmp = (unsigned short*)dmp; 

    y = 0; 

    sx = PosX;
    
    for ( ; LoopFlag != 0; y++)
    { 
        SizeX = 0; 
        
        SearchFlag = 1;
        
        for (x = 0; SearchFlag != 0; x++) 
        { 
            switch (nmp[x]) 
            { 
            case 65535:
                LoopFlag = 0; 
                SearchFlag = 0;
                break; 
            case 65280:
                nmp[x] = 65535; 
                
                temp = (unsigned int*)(&nmp[x] + 1); 
                
                SearchFlag = 0; 
                break; 
            case 65281:
                SizeX += 14.0f; 
                break; 
            default: 
                SizeX += FontSz[nmp[x]]; 
                break; 
            } 
        } 

        if (PosX < 0) 
        { 
            sx = 320.0f - (SizeX / 2.0f); 
        } 
        
        sys->mes_tp = nmp; 
        
        bhDispMessage(sx, sy, -1.0f, 2, 0, 0, 0);    
        
        sy += 30.0f;
        
        nmp = (unsigned short*)temp; 
    } 
    
    syFree(dmp); 

    if (PosX < 0) 
    {
        return y * 30; 
    } 
    else 
    {
        return SizeX;
    }
} 

// 100% matching! 
float AutoSaveLoadEasyDispMessage(float PosX, float PosY, unsigned char* ucpMsbTop, unsigned int MessageNo)
{ 
    unsigned char* dmp;
    unsigned char* smp;
    unsigned short* mp;
    unsigned short* nmp;
    unsigned int* temp; // not from the debugging symbols
    int x;
    int y;
    int LoopFlag = 1;
    int SearchFlag;
    float sx;
    float SizeX;
    float sy;

    sy = PosY;
    
    smp = (unsigned char*)((int)ucpMsbTop + ((int*)ucpMsbTop)[MessageNo + 1]); 
    
    dmp = syMalloc(1024); 
    
    memcpy(dmp, smp, 1024); 

    nmp = (unsigned short*)dmp; 

    y = 0; 

    sx = PosX;
    
    for ( ; LoopFlag != 0; y++)
    { 
        SizeX = 0; 
        
        SearchFlag = 1;
        
        for (x = 0; SearchFlag != 0; x++) 
        { 
            switch (nmp[x]) 
            { 
            case 65535:
                LoopFlag = 0; 
                SearchFlag = 0;
                break; 
            case 65280:
                nmp[x] = 65535; 
                
                temp = (unsigned int*)(&nmp[x] + 1); 
                
                SearchFlag = 0; 
                break; 
            case 65281:
                SizeX += 14.0f * FontScaleX; 
                break; 
            default: 
                SizeX += FontScaleX * FontSz[nmp[x]]; 
                break; 
            } 
        } 

        if (PosX < 0) 
        { 
            sx = 320.0f - (SizeX / 2.0f); 
        } 
        
        sys->mes_tp = nmp; 
        
        bhDispMessage(sx, sy, -1.0f, 2, 0, 0, 0);    
        
        sy += 30.0f * FontScaleCR;
        
        nmp = (unsigned short*)temp; 
    } 
    
    syFree(dmp); 

    if (PosX < 0) 
    {
        return y * 30 * FontScaleCR; 
    } 
    else 
    {
        return SizeX;
    }
} 

// 100% matching! 
int DispVmWarningMessage(int MsgId)
{ 
    ADV_WORK* ap; 
    ADV_VM_MSG* mp; 

    ap = (ADV_WORK*)&AdvWork;

    mp = &AdvVmMsgDef[MsgId]; 
    
    if ((mp->MsgType != 0) && ((Pad[ap->PortId].press & 0x800))) 
    { 
        ap->Mode = ap->Mode2 = ap->NextMode; 
        
        return 1;
    } 
    
    AdvEasyDispMessage(mp->Sx, mp->Sy, mp->StartMsgNo); 
    
    if (mp->NaviMsgNo >= 0) 
    { 
        AdvEasyDispMessage(-1.0f, 400.0f, mp->NaviMsgNo); 
    }

    return 0; 
} 

// 100% matching!
void DefaultSetOption()
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
    
    sys->keytype = 0; 
    
    RequestAdjustDisplay(0, 0); 
    
    sys->vibration = (CheckVibrationUnit((temp->PortId * 6) + 2) == 0) ? 0 : 1; 
    
    SetUseVibrationUnit(sys->vibration); 
}

// 99.72% matching
int Adv_FirstWarningMessage()
{ 
	ADV_WORK* ap = (ADV_WORK*)&AdvWork; 
    int ReturnCode;
	int TexNoDef[3] = {0, 1, -1}; 
	static int lState;
	static int LoadCheck;
    
    ReturnCode = 0; 
    
    ap->PortId = AdvGetCurrentPort(); 
    
    ExecuteAdvFade(); 
    ExecuteAdvScreenSaver(); 
    
    CheckAdvScreenSaverStopKey(ap->PortId); 
    
    AdvCheckSoftReset(0); 

    switch (ap->Mode) 
    { 
    case 0:
        ResetAdvSystem(); 
        
        ap->Mode = 1; 
        break; 
    case 1:
        ap->ptr[0] = bhGetFreeMemory(GetInsideFileSize(sys->sys_partid, 1), 32);
        
        RequestReadInsideFile(sys->sys_partid, 1, ap->ptr[0]); 
        
        ap->Mode = 2; 
        break; 
    case 2:
        CheckReadEndAdvInsideFile2(3); 
        break; 
    case 3:
        bhSetFontTexture(ap->ptr[0]); 
        
        AllFreeAdvMemory(); 
        
        ap->Mode = 4; 
    case 4:
        RequestAdvInsideFileEx(0, 0); 
        
        ap->Mode = 5; 
        break; 
    case 5:
        CheckReadEndAdvInsideFile2(6); 
        break; 
    case 6:
        ap->MsgPtr = AdvGetResourcePtr(ap->ptr[0], 0); 
        
        AdvEasySetupTextureBasic(AdvGetResourcePtr(ap->ptr[0], 2), 0, 0); 
        AdvEasySetupTextureBasic(AdvGetResourcePtr(ap->ptr[0], 3), 0, 1); 
        
        ap->PalNo = TransPvpData(AdvGetResourcePtr(ap->ptr[0], 1), ap->PalFlag); 
        
        AdvEasyTransTextureBasic(0, 2, 1); 
        
        ap->Mode = 8; 
        break; 
    case 8:
    case 9:
        ap->Mode = 11; 
        break; 
    case 10:
        ap->Mode = 11; 
        break; 
    case 11:
        switch (lState)
        { 
        case 0:
            pSysLoad = CreateSysLoadScreen(&SysLoad, NULL); 
            
            lState = 1; 
            
            LoadCheck = 0; 
            break;
        case 1:
            LoadCheck = ExecuteSysLoadScreen(pSysLoad); 
            
            if (LoadCheck == 1) 
            { 
                ap->Mode = 15;
                
                lState = 0; 
                
                LoadCheck = 0; 
                
                DefaultSetOption(1); 
            }
            else if (LoadCheck == 2) 
            { 
                ap->Mode = 15; 
                
                lState = 0; 
                
                LoadCheck = 0;
                
                ap->GenFlag = 1; 
                
                switch (sys->ssd_reserve) 
                { 
                case 0:
                    SetSoundMode(0); 
                    break; 
                case 1:
                    SetSoundMode(1); 
                    break;
                }
            } 
        }
        
        break; 
    case 12:
        ap->Mode = 15; 
        break; 
    case 13:
        ap->Mode = 15; 
        break; 
    case 14:
        CheckAdvScreenSaverStopKey(ap->PortId); 
        
        DispVmWarningMessage(ap->MsgNo); 
        break; 
    case 15:
        ap->Mode = 16; 
        break; 
    case 16:
        if (ap->GenFlag != 0) 
        {
            SetAdjustDisplay(); 
        }

        RequestAdvFade(2, GetSamurai(50)); 
        
        ap->Count = 0; 
        
        ap->Mode = 17; 
        break; 
    case 17:
        if (CheckAdvFade() == 0) 
        { 
            ap->Timer = 150.0f; 
            
            ap->Mode = 18; 
        }
        
        AdvEasySetTextureList(0); 
        
        AdvDwawOnePicture(TexNoDef[ap->Count]); 
        break; 
    case 18:
        ap->Timer--; 
        
        if (ap->Timer < 0) 
        { 
            RequestAdvFade(3, GetSamurai(50));
            
            ap->Mode = 19; 
        }
        
        AdvEasySetTextureList(0); 
        
        AdvDwawOnePicture(TexNoDef[ap->Count]); 
        break; 
    case 19:
        if (CheckAdvFade() == 0) 
        { 
            ap->Count++; 
            
            if (TexNoDef[ap->Count] < 0)
            { 
                ap->Mode = -1; 
            } 
            else 
            { 
                RequestAdvFade(2, GetSamurai(50)); 
                
                ap->Mode = 17; 
            }
        }
        else 
        { 
            AdvEasySetTextureList(0); 
            
            AdvDwawOnePicture(TexNoDef[ap->Count]); 
        }
        
        break;
    }
    
    if (ap->Mode == -1) 
    { 
        AdvEasyReleaseAllTexture(); 
        
        AllFreeAdvMemory(); 
        
        ap->Mode = 0; 
        
        ap->Active = 0; 
        
        ReturnCode = 1;
    }
    
    return ReturnCode; 
} 

// 100% matching!
int Adv_CapcomLogo()
{ 
	ADV_WORK* ap; 
    int ReturnCode;

    ap = (ADV_WORK*)&AdvWork; 

    ReturnCode = 0;
    
    ap->PortId = AdvGetCurrentPort(); 
    
    ExecuteAdvFade();
    
    AdvCheckSoftReset(0); 

    switch (ap->Mode) 
    { 
    case 0:
        ResetAdvSystem();
        
        ap->Mode = 1; 
        break; 
    case 1:
        RequestAdvInsideFile(1); 
        
        ap->Mode = 2; 
        break; 
    case 2:
        CheckReadEndAdvInsideFile2(3); 
        break; 
    case 3:
        AdvEasySetupTexture(); 
        AdvEasyTransTexture(); 
        
        RequestAdvFade(2, GetSamurai(50)); 
        
        ap->Mode = 4; 
        break; 
    case 4:
        if (CheckAdvFade() == 0) 
        { 
            ap->Timer = 150.0f; 
            
            ap->Mode = 5; 
        }
        
        AdvDwawOnePicture(0); 
        break; 
    case 5:
        if (--ap->Timer < 0) 
        { 
            RequestAdvFade(3, GetSamurai(50)); 
            
            ap->NextMode = 7; 
            ap->Mode = 6; 
        }
        
        AdvDwawOnePicture(0); 
        break; 
    case 6:
        if (CheckAdvFade() == 0) 
        { 
            ap->Mode = ap->NextMode; 
        }
        else
        {
            if ((Pad[ap->PortId].press & 0x800)) 
            { 
                ap->NextMode = -1;
            }
            
            AdvDwawOnePicture(0); 
        }
        
        break; 
    case 7:
        PlayStartMovieEx(16, 0, 1); 
        
        ap->Mode = 8; 
        break; 
    case 8:
        switch (WaitPrePlayMovie(0)) 
        { 
        case 0:
            ap->Mode = 9; 
            break; 
        case 2:
        case 3:
            ap->Mode = -1; 
            break;
        case 1: 
            break;
        }
        
        break; 
    case 9:
        switch (PlayMovieMain(0)) 
        { 
        case 1:
        case 2:
        case 3:
            ap->Mode = -1; 
            break;
        case 0:
            break;
        }
        
        break;
    }

    if (ap->Mode == -1)
    { 
        AdvEasyReleaseTexture();
        
        ap->Mode = 0;
        
        ap->Active = 0; 
        
        ReturnCode = 1; 
    }
    
    return ReturnCode; 
} 

// 100% matching!
void ResetFlushPlate() 
{
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork;
    
    ap->FlushSpeed2 = 0; 
    ap->FlushCount2 = 0; 
}

// 100% matching! 
void FlushPlate() 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork;

    ap->FlushCount2 += ap->FlushSpeed2; 
    
    if (ap->FlushSpeed2 < 0) 
    { 
        if (ap->FlushCount2 <= -64.0f)
        { 
            ap->FlushCount2 = -64.0f; 
            ap->FlushSpeed2 = 2.0f;
        }
    } 
    else if (ap->FlushCount2 >= 0) 
    { 
        ap->FlushCount2 = 0;
        ap->FlushSpeed2 = -2.0f; 
    }

    ap->FontBaseColor = (unsigned int)ap->FlushCount2 + 255; 
    
    ap->FontBaseColor |= ((unsigned int)ap->FlushCount2 + 255) << 16;
    ap->FontBaseColor |= ((unsigned int)ap->FlushCount2 + 255) << 8;
} 

// 98.31% matching
void DisplayTitleBg()
{ 
    QUAD* qp; 

    qp = &Qtex[1];
    
    AdvDwawOnePictureEx(0, 0xFFFFFFFF); 

    SetQuadPos(20.0f, 396.0f, 352.0f, 54.0f, qp); 
    SetQuadUv2(0.0f, 460.0f, 352.0f, 54.0f, 1, qp); 
    
    AdvEasyDrawTextureS(1, 0xFFFFFFFF, qp, 0.15f, 1, 192); 
    
    SetQuadPos(348.0f, 418.0f, 240.0f, 32.0f, qp); 
    SetQuadUv2(272.0f, 432.0f, 240.0f, 32.0f, 1, qp); 
    
    AdvEasyDrawTextureS(1, 0xFFFFFFFF, qp, 0.15f, 1, 192); 
} 

// 97.50% matching
void DisplayPressStartPlate(float FadeRate)
{ 
    QUAD* qp; 
    float temp; // not from the debugging symbols

    qp = &Qtex[1]; 

    DisplayTitleBg();
    
    SetQuadPos(64.0f, 512.0f, 304.0f, 32.0f, qp); 
    SetQuadUv2(0, 512.0f, 32.0f, 32.0f, 1, qp); 

    temp = 0.5f;
    
    AdvEasyDrawTextureS(1, ((unsigned int)FadeRate << 24) | 0xFFFFFF, qp, FadeRate, 1, temp);
}

/*// 
// Start address: 0x2c3460
void DisplayGameModePlate(int Cursor, int CursorMax, float FadeRate, int Flag)
{
	float VDef[4][2];
	float PosYDef[4][2];
	int DivTbl[4];
	unsigned int Alpha;
	int i;
	_anon0* qp;
	_anon8* ap;
	// Line 2898, Address: 0x2c3460, Func Offset: 0
	// Line 2899, Address: 0x2c3478, Func Offset: 0x18
	// Line 2898, Address: 0x2c3480, Func Offset: 0x20
	// Line 2908, Address: 0x2c3488, Func Offset: 0x28
	// Line 2898, Address: 0x2c348c, Func Offset: 0x2c
	// Line 2908, Address: 0x2c3490, Func Offset: 0x30
	// Line 2919, Address: 0x2c34a8, Func Offset: 0x48
	// Line 2908, Address: 0x2c34b0, Func Offset: 0x50
	// Line 2919, Address: 0x2c34b4, Func Offset: 0x54
	// Line 2939, Address: 0x2c34c0, Func Offset: 0x60
	// Line 2953, Address: 0x2c34c4, Func Offset: 0x64
	// Line 2939, Address: 0x2c34c8, Func Offset: 0x68
	// Line 2919, Address: 0x2c34cc, Func Offset: 0x6c
	// Line 2939, Address: 0x2c34d0, Func Offset: 0x70
	// Line 2919, Address: 0x2c34d4, Func Offset: 0x74
	// Line 2939, Address: 0x2c34d8, Func Offset: 0x78
	// Line 2953, Address: 0x2c34e0, Func Offset: 0x80
	// Line 2939, Address: 0x2c34e8, Func Offset: 0x88
	// Line 2957, Address: 0x2c34ec, Func Offset: 0x8c
	// Line 2939, Address: 0x2c34f0, Func Offset: 0x90
	// Line 2953, Address: 0x2c34f4, Func Offset: 0x94
	// Line 2957, Address: 0x2c34f8, Func Offset: 0x98
	// Line 2955, Address: 0x2c34fc, Func Offset: 0x9c
	// Line 2969, Address: 0x2c3500, Func Offset: 0xa0
	// Line 2955, Address: 0x2c350c, Func Offset: 0xac
	// Line 2969, Address: 0x2c3510, Func Offset: 0xb0
	// Line 2955, Address: 0x2c3514, Func Offset: 0xb4
	// Line 2969, Address: 0x2c3518, Func Offset: 0xb8
	// Line 2970, Address: 0x2c3538, Func Offset: 0xd8
	// Line 2975, Address: 0x2c3564, Func Offset: 0x104
	// Line 2976, Address: 0x2c3590, Func Offset: 0x130
	// Line 2980, Address: 0x2c35bc, Func Offset: 0x15c
	// Line 2981, Address: 0x2c35e8, Func Offset: 0x188
	// Line 2985, Address: 0x2c3614, Func Offset: 0x1b4
	// Line 2986, Address: 0x2c3640, Func Offset: 0x1e0
	// Line 2996, Address: 0x2c366c, Func Offset: 0x20c
	// Line 2997, Address: 0x2c367c, Func Offset: 0x21c
	// Line 2998, Address: 0x2c3684, Func Offset: 0x224
	// Line 2997, Address: 0x2c3688, Func Offset: 0x228
	// Line 2998, Address: 0x2c368c, Func Offset: 0x22c
	// Line 2999, Address: 0x2c3698, Func Offset: 0x238
	// Line 3001, Address: 0x2c36a4, Func Offset: 0x244
	// Line 3002, Address: 0x2c36ac, Func Offset: 0x24c
	// Line 3004, Address: 0x2c36b0, Func Offset: 0x250
	// Line 3005, Address: 0x2c36ec, Func Offset: 0x28c
	// Line 3007, Address: 0x2c36f4, Func Offset: 0x294
	// Line 3008, Address: 0x2c36f8, Func Offset: 0x298
	// Line 3009, Address: 0x2c3700, Func Offset: 0x2a0
	// Line 3010, Address: 0x2c3704, Func Offset: 0x2a4
	// Line 3011, Address: 0x2c3708, Func Offset: 0x2a8
	// Line 3012, Address: 0x2c374c, Func Offset: 0x2ec
	// Line 3014, Address: 0x2c3750, Func Offset: 0x2f0
	// Line 3016, Address: 0x2c3760, Func Offset: 0x300
	// Line 3018, Address: 0x2c3768, Func Offset: 0x308
	// Line 3019, Address: 0x2c3770, Func Offset: 0x310
	// Func End, Address: 0x2c3798, Func Offset: 0x338
}

// 
// Start address: 0x2c37a0
void DisplayNewGamePlate(int Cursor, float FadeRate, int Flag)
{
	int DivTbl[3];
	unsigned int Alpha;
	int i;
	_anon0* qp;
	_anon8* ap;
	// Line 3031, Address: 0x2c37a0, Func Offset: 0
	// Line 3032, Address: 0x2c37bc, Func Offset: 0x1c
	// Line 3031, Address: 0x2c37c4, Func Offset: 0x24
	// Line 3036, Address: 0x2c37c8, Func Offset: 0x28
	// Line 3031, Address: 0x2c37d4, Func Offset: 0x34
	// Line 3036, Address: 0x2c37dc, Func Offset: 0x3c
	// Line 3038, Address: 0x2c37e8, Func Offset: 0x48
	// Line 3036, Address: 0x2c37f0, Func Offset: 0x50
	// Line 3038, Address: 0x2c37f4, Func Offset: 0x54
	// Line 3036, Address: 0x2c37f8, Func Offset: 0x58
	// Line 3038, Address: 0x2c37fc, Func Offset: 0x5c
	// Line 3040, Address: 0x2c3800, Func Offset: 0x60
	// Line 3044, Address: 0x2c3808, Func Offset: 0x68
	// Line 3045, Address: 0x2c3830, Func Offset: 0x90
	// Line 3049, Address: 0x2c3858, Func Offset: 0xb8
	// Line 3050, Address: 0x2c3880, Func Offset: 0xe0
	// Line 3054, Address: 0x2c38a8, Func Offset: 0x108
	// Line 3055, Address: 0x2c38d0, Func Offset: 0x130
	// Line 3059, Address: 0x2c38f8, Func Offset: 0x158
	// Line 3060, Address: 0x2c3924, Func Offset: 0x184
	// Line 3106, Address: 0x2c3950, Func Offset: 0x1b0
	// Line 3117, Address: 0x2c3958, Func Offset: 0x1b8
	// Line 3118, Address: 0x2c3960, Func Offset: 0x1c0
	// Line 3117, Address: 0x2c3964, Func Offset: 0x1c4
	// Line 3118, Address: 0x2c3968, Func Offset: 0x1c8
	// Line 3119, Address: 0x2c3974, Func Offset: 0x1d4
	// Line 3121, Address: 0x2c3980, Func Offset: 0x1e0
	// Line 3122, Address: 0x2c3988, Func Offset: 0x1e8
	// Line 3123, Address: 0x2c398c, Func Offset: 0x1ec
	// Line 3124, Address: 0x2c3990, Func Offset: 0x1f0
	// Line 3125, Address: 0x2c39d0, Func Offset: 0x230
	// Line 3127, Address: 0x2c39d8, Func Offset: 0x238
	// Line 3128, Address: 0x2c39dc, Func Offset: 0x23c
	// Line 3129, Address: 0x2c39e4, Func Offset: 0x244
	// Line 3131, Address: 0x2c39e8, Func Offset: 0x248
	// Line 3132, Address: 0x2c3a2c, Func Offset: 0x28c
	// Line 3135, Address: 0x2c3a30, Func Offset: 0x290
	// Line 3136, Address: 0x2c3a40, Func Offset: 0x2a0
	// Line 3138, Address: 0x2c3a84, Func Offset: 0x2e4
	// Line 3140, Address: 0x2c3a8c, Func Offset: 0x2ec
	// Line 3141, Address: 0x2c3a94, Func Offset: 0x2f4
	// Func End, Address: 0x2c3abc, Func Offset: 0x31c
}

// 
// Start address: 0x2c3ac0
void DisplayExtraGamePlate(int Cursor, float FadeRate, int Flag)
{
	int DivTbl[2];
	unsigned int Alpha;
	int i;
	_anon0* qp;
	_anon8* ap;
	// Line 3152, Address: 0x2c3ac0, Func Offset: 0
	// Line 3153, Address: 0x2c3adc, Func Offset: 0x1c
	// Line 3152, Address: 0x2c3ae4, Func Offset: 0x24
	// Line 3157, Address: 0x2c3ae8, Func Offset: 0x28
	// Line 3152, Address: 0x2c3af4, Func Offset: 0x34
	// Line 3157, Address: 0x2c3afc, Func Offset: 0x3c
	// Line 3159, Address: 0x2c3b04, Func Offset: 0x44
	// Line 3157, Address: 0x2c3b10, Func Offset: 0x50
	// Line 3159, Address: 0x2c3b14, Func Offset: 0x54
	// Line 3161, Address: 0x2c3b18, Func Offset: 0x58
	// Line 3164, Address: 0x2c3b20, Func Offset: 0x60
	// Line 3165, Address: 0x2c3b48, Func Offset: 0x88
	// Line 3169, Address: 0x2c3b70, Func Offset: 0xb0
	// Line 3170, Address: 0x2c3b98, Func Offset: 0xd8
	// Line 3174, Address: 0x2c3bc0, Func Offset: 0x100
	// Line 3175, Address: 0x2c3be8, Func Offset: 0x128
	// Line 3178, Address: 0x2c3c10, Func Offset: 0x150
	// Line 3189, Address: 0x2c3c18, Func Offset: 0x158
	// Line 3190, Address: 0x2c3c20, Func Offset: 0x160
	// Line 3189, Address: 0x2c3c24, Func Offset: 0x164
	// Line 3190, Address: 0x2c3c28, Func Offset: 0x168
	// Line 3191, Address: 0x2c3c34, Func Offset: 0x174
	// Line 3193, Address: 0x2c3c40, Func Offset: 0x180
	// Line 3194, Address: 0x2c3c48, Func Offset: 0x188
	// Line 3195, Address: 0x2c3c4c, Func Offset: 0x18c
	// Line 3196, Address: 0x2c3c50, Func Offset: 0x190
	// Line 3197, Address: 0x2c3c90, Func Offset: 0x1d0
	// Line 3199, Address: 0x2c3c98, Func Offset: 0x1d8
	// Line 3200, Address: 0x2c3c9c, Func Offset: 0x1dc
	// Line 3201, Address: 0x2c3ca4, Func Offset: 0x1e4
	// Line 3203, Address: 0x2c3ca8, Func Offset: 0x1e8
	// Line 3204, Address: 0x2c3cec, Func Offset: 0x22c
	// Line 3207, Address: 0x2c3cf0, Func Offset: 0x230
	// Line 3208, Address: 0x2c3d00, Func Offset: 0x240
	// Line 3210, Address: 0x2c3d44, Func Offset: 0x284
	// Line 3212, Address: 0x2c3d4c, Func Offset: 0x28c
	// Line 3213, Address: 0x2c3d54, Func Offset: 0x294
	// Func End, Address: 0x2c3d7c, Func Offset: 0x2bc
}*/

// 100% matching! 
void FadeInPlate(int NextMode)
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    ResetFlushPlate(); 
    
    ap->FlushCount += ap->FlushSpeed; 
    
    if (ap->FlushCount > 255.0f) 
    { 
        ap->FlushCount = 255.0f; 
        ap->FlushSpeed = 32.0f; 
        
        ap->Mode = NextMode; 
    }
}

// 100% matching! 
void FadeOutPlate()
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    ResetFlushPlate(); 
    
    ap->FlushCount -= ap->FlushSpeed; 
    
    if (ap->FlushCount < 0) 
    { 
        ap->FlushCount = 0; 
        ap->FlushSpeed = 32.0f; 
        
        ap->Mode = ap->NextMode; 
    }
} 

// 100% matching! 
void TitleCall(int PortId, int ReturnCode) 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    StartVibrationEx(PortId, 16); 
    
    SetVolumeAdx2(0, 0); 
    
    PlayAdx(0, ap->PatId, 3); 
    
    RequestAdvFade(3, GetSamurai(430)); 
    
    ap->FlushCount = 180.0f; 
    
    ap->NextReturnCode = ReturnCode; 
    
    ap->Mode = 17; 
    
    ap->GenFlag = 1; 
} 

/*// 
// Start address: 0x2c3ee0
int CheckButton(int Level, int Flag, int MaxFlag)
{
	int ConnectFlag;
	int CancelMode[3];
	int CancelNextMode[3];
	unsigned char ExGameDef[2];
	unsigned char NewGameDef[3];
	unsigned int UpKey[3];
	unsigned int DownKey[3];
	_anon8* ap;
	// Line 3273, Address: 0x2c3ee0, Func Offset: 0
	// Line 3274, Address: 0x2c3efc, Func Offset: 0x1c
	// Line 3276, Address: 0x2c3f04, Func Offset: 0x24
	// Line 3277, Address: 0x2c3f24, Func Offset: 0x44
	// Line 3276, Address: 0x2c3f30, Func Offset: 0x50
	// Line 3278, Address: 0x2c3f38, Func Offset: 0x58
	// Line 3277, Address: 0x2c3f40, Func Offset: 0x60
	// Line 3284, Address: 0x2c3f48, Func Offset: 0x68
	// Line 3278, Address: 0x2c3f4c, Func Offset: 0x6c
	// Line 3284, Address: 0x2c3f50, Func Offset: 0x70
	// Line 3277, Address: 0x2c3f54, Func Offset: 0x74
	// Line 3278, Address: 0x2c3f5c, Func Offset: 0x7c
	// Line 3284, Address: 0x2c3f60, Func Offset: 0x80
	// Line 3285, Address: 0x2c3f64, Func Offset: 0x84
	// Line 3278, Address: 0x2c3f6c, Func Offset: 0x8c
	// Line 3290, Address: 0x2c3f70, Func Offset: 0x90
	// Line 3285, Address: 0x2c3f74, Func Offset: 0x94
	// Line 3278, Address: 0x2c3f78, Func Offset: 0x98
	// Line 3284, Address: 0x2c3f80, Func Offset: 0xa0
	// Line 3290, Address: 0x2c3f84, Func Offset: 0xa4
	// Line 3284, Address: 0x2c3f88, Func Offset: 0xa8
	// Line 3285, Address: 0x2c3f8c, Func Offset: 0xac
	// Line 3290, Address: 0x2c3f94, Func Offset: 0xb4
	// Line 3285, Address: 0x2c3f98, Func Offset: 0xb8
	// Line 3290, Address: 0x2c3fa0, Func Offset: 0xc0
	// Line 3297, Address: 0x2c3fb0, Func Offset: 0xd0
	// Line 3299, Address: 0x2c3fbc, Func Offset: 0xdc
	// Line 3300, Address: 0x2c3fe0, Func Offset: 0x100
	// Line 3301, Address: 0x2c3fe8, Func Offset: 0x108
	// Line 3304, Address: 0x2c3fec, Func Offset: 0x10c
	// Line 3305, Address: 0x2c3ff4, Func Offset: 0x114
	// Line 3312, Address: 0x2c4034, Func Offset: 0x154
	// Line 3307, Address: 0x2c4038, Func Offset: 0x158
	// Line 3310, Address: 0x2c4044, Func Offset: 0x164
	// Line 3311, Address: 0x2c4058, Func Offset: 0x178
	// Line 3312, Address: 0x2c4070, Func Offset: 0x190
	// Line 3314, Address: 0x2c4074, Func Offset: 0x194
	// Line 3316, Address: 0x2c4078, Func Offset: 0x198
	// Line 3317, Address: 0x2c4084, Func Offset: 0x1a4
	// Line 3318, Address: 0x2c408c, Func Offset: 0x1ac
	// Line 3319, Address: 0x2c4094, Func Offset: 0x1b4
	// Line 3320, Address: 0x2c409c, Func Offset: 0x1bc
	// Line 3323, Address: 0x2c40a0, Func Offset: 0x1c0
	// Line 3324, Address: 0x2c40b4, Func Offset: 0x1d4
	// Line 3328, Address: 0x2c40cc, Func Offset: 0x1ec
	// Line 3329, Address: 0x2c40d0, Func Offset: 0x1f0
	// Line 3330, Address: 0x2c40dc, Func Offset: 0x1fc
	// Line 3331, Address: 0x2c40e4, Func Offset: 0x204
	// Line 3338, Address: 0x2c40fc, Func Offset: 0x21c
	// Line 3333, Address: 0x2c4100, Func Offset: 0x220
	// Line 3336, Address: 0x2c410c, Func Offset: 0x22c
	// Line 3337, Address: 0x2c4120, Func Offset: 0x240
	// Line 3338, Address: 0x2c4138, Func Offset: 0x258
	// Line 3340, Address: 0x2c413c, Func Offset: 0x25c
	// Line 3342, Address: 0x2c4140, Func Offset: 0x260
	// Line 3343, Address: 0x2c4158, Func Offset: 0x278
	// Line 3345, Address: 0x2c4160, Func Offset: 0x280
	// Line 3346, Address: 0x2c4168, Func Offset: 0x288
	// Line 3348, Address: 0x2c416c, Func Offset: 0x28c
	// Line 3349, Address: 0x2c4170, Func Offset: 0x290
	// Line 3350, Address: 0x2c4184, Func Offset: 0x2a4
	// Line 3354, Address: 0x2c419c, Func Offset: 0x2bc
	// Line 3355, Address: 0x2c41a0, Func Offset: 0x2c0
	// Line 3360, Address: 0x2c41ac, Func Offset: 0x2cc
	// Line 3361, Address: 0x2c41f8, Func Offset: 0x318
	// Line 3363, Address: 0x2c4220, Func Offset: 0x340
	// Line 3381, Address: 0x2c425c, Func Offset: 0x37c
	// Line 3382, Address: 0x2c426c, Func Offset: 0x38c
	// Line 3383, Address: 0x2c4278, Func Offset: 0x398
	// Line 3384, Address: 0x2c4280, Func Offset: 0x3a0
	// Line 3385, Address: 0x2c4288, Func Offset: 0x3a8
	// Line 3386, Address: 0x2c428c, Func Offset: 0x3ac
	// Line 3387, Address: 0x2c4290, Func Offset: 0x3b0
	// Line 3390, Address: 0x2c429c, Func Offset: 0x3bc
	// Line 3399, Address: 0x2c42a4, Func Offset: 0x3c4
	// Line 3400, Address: 0x2c42a8, Func Offset: 0x3c8
	// Line 3401, Address: 0x2c42ac, Func Offset: 0x3cc
	// Line 3402, Address: 0x2c42b0, Func Offset: 0x3d0
	// Line 3403, Address: 0x2c42bc, Func Offset: 0x3dc
	// Line 3405, Address: 0x2c42c4, Func Offset: 0x3e4
	// Line 3407, Address: 0x2c42cc, Func Offset: 0x3ec
	// Line 3408, Address: 0x2c42d0, Func Offset: 0x3f0
	// Line 3410, Address: 0x2c42d4, Func Offset: 0x3f4
	// Line 3409, Address: 0x2c42d8, Func Offset: 0x3f8
	// Line 3410, Address: 0x2c42dc, Func Offset: 0x3fc
	// Line 3411, Address: 0x2c42e0, Func Offset: 0x400
	// Line 3412, Address: 0x2c42e4, Func Offset: 0x404
	// Line 3411, Address: 0x2c42e8, Func Offset: 0x408
	// Line 3412, Address: 0x2c42ec, Func Offset: 0x40c
	// Line 3413, Address: 0x2c42f4, Func Offset: 0x414
	// Line 3414, Address: 0x2c4308, Func Offset: 0x428
	// Line 3417, Address: 0x2c4310, Func Offset: 0x430
	// Line 3418, Address: 0x2c4314, Func Offset: 0x434
	// Line 3419, Address: 0x2c4318, Func Offset: 0x438
	// Line 3420, Address: 0x2c431c, Func Offset: 0x43c
	// Line 3421, Address: 0x2c4328, Func Offset: 0x448
	// Line 3452, Address: 0x2c4334, Func Offset: 0x454
	// Line 3454, Address: 0x2c433c, Func Offset: 0x45c
	// Line 3455, Address: 0x2c4358, Func Offset: 0x478
	// Line 3457, Address: 0x2c4360, Func Offset: 0x480
	// Line 3459, Address: 0x2c4368, Func Offset: 0x488
	// Line 3460, Address: 0x2c4384, Func Offset: 0x4a4
	// Line 3464, Address: 0x2c438c, Func Offset: 0x4ac
	// Line 3465, Address: 0x2c4394, Func Offset: 0x4b4
	// Line 3466, Address: 0x2c43c4, Func Offset: 0x4e4
	// Line 3468, Address: 0x2c43d0, Func Offset: 0x4f0
	// Line 3466, Address: 0x2c43d8, Func Offset: 0x4f8
	// Line 3467, Address: 0x2c43dc, Func Offset: 0x4fc
	// Line 3468, Address: 0x2c43e0, Func Offset: 0x500
	// Line 3473, Address: 0x2c43e8, Func Offset: 0x508
	// Line 3472, Address: 0x2c4400, Func Offset: 0x520
	// Line 3473, Address: 0x2c4404, Func Offset: 0x524
	// Func End, Address: 0x2c440c, Func Offset: 0x52c
}

// 
// Start address: 0x2c4410
int CheckStartButton()
{
	// Line 3511, Address: 0x2c4410, Func Offset: 0
	// Line 3564, Address: 0x2c4414, Func Offset: 0x4
	// Line 3511, Address: 0x2c441c, Func Offset: 0xc
	// Line 3564, Address: 0x2c4420, Func Offset: 0x10
	// Line 3578, Address: 0x2c444c, Func Offset: 0x3c
	// Line 3580, Address: 0x2c445c, Func Offset: 0x4c
	// Line 3584, Address: 0x2c4464, Func Offset: 0x54
	// Line 3587, Address: 0x2c446c, Func Offset: 0x5c
	// Line 3588, Address: 0x2c4470, Func Offset: 0x60
	// Func End, Address: 0x2c447c, Func Offset: 0x6c
}*/

// 
// Start address: 0x2c4480
int Adv_BioCvTitle()
{
	unsigned int a;
	//_anon13 poly[4];
	unsigned int McCrntResult;
	int TitleSoftResetFlag;
	int j;
	int i;
	int ReturnCode;
	//_anon8* ap;
	unsigned int ulFrame;
	unsigned int McPrevResult;
	// Line 3635, Address: 0x2c4480, Func Offset: 0
	// Line 3636, Address: 0x2c4498, Func Offset: 0x18
	// Line 3637, Address: 0x2c44a0, Func Offset: 0x20
	// Line 3646, Address: 0x2c44a4, Func Offset: 0x24
	// Line 3647, Address: 0x2c44ac, Func Offset: 0x2c
	// Line 3648, Address: 0x2c44b4, Func Offset: 0x34
	// Line 3649, Address: 0x2c44bc, Func Offset: 0x3c
	// Line 3650, Address: 0x2c44c4, Func Offset: 0x44
	// Line 3651, Address: 0x2c44d0, Func Offset: 0x50
	// Line 3653, Address: 0x2c44e0, Func Offset: 0x60
	// Line 3652, Address: 0x2c44e4, Func Offset: 0x64
	// Line 3653, Address: 0x2c44e8, Func Offset: 0x68
	// Line 3657, Address: 0x2c44ec, Func Offset: 0x6c
	// Line 3659, Address: 0x2c4518, Func Offset: 0x98
	// Line 3660, Address: 0x2c4528, Func Offset: 0xa8
	// Line 3661, Address: 0x2c4530, Func Offset: 0xb0
	// Line 3662, Address: 0x2c4538, Func Offset: 0xb8
	// Line 3664, Address: 0x2c453c, Func Offset: 0xbc
	// Line 3666, Address: 0x2c4544, Func Offset: 0xc4
	// Line 3665, Address: 0x2c4548, Func Offset: 0xc8
	// Line 3667, Address: 0x2c4550, Func Offset: 0xd0
	// Line 3666, Address: 0x2c4554, Func Offset: 0xd4
	// Line 3667, Address: 0x2c4558, Func Offset: 0xd8
	// Line 3666, Address: 0x2c455c, Func Offset: 0xdc
	// Line 3667, Address: 0x2c4560, Func Offset: 0xe0
	// Line 3668, Address: 0x2c456c, Func Offset: 0xec
	// Line 3669, Address: 0x2c457c, Func Offset: 0xfc
	// Line 3671, Address: 0x2c4580, Func Offset: 0x100
	// Line 3670, Address: 0x2c4584, Func Offset: 0x104
	// Line 3671, Address: 0x2c4588, Func Offset: 0x108
	// Line 3672, Address: 0x2c458c, Func Offset: 0x10c
	// Line 3690, Address: 0x2c4594, Func Offset: 0x114
	// Line 3691, Address: 0x2c45bc, Func Offset: 0x13c
	// Line 3693, Address: 0x2c45c0, Func Offset: 0x140
	// Line 3694, Address: 0x2c45d0, Func Offset: 0x150
	// Line 3693, Address: 0x2c45d4, Func Offset: 0x154
	// Line 3694, Address: 0x2c45d8, Func Offset: 0x158
	// Line 3693, Address: 0x2c45dc, Func Offset: 0x15c
	// Line 3694, Address: 0x2c45e4, Func Offset: 0x164
	// Line 3700, Address: 0x2c45ec, Func Offset: 0x16c
	// Line 3694, Address: 0x2c45f0, Func Offset: 0x170
	// Line 3700, Address: 0x2c45f8, Func Offset: 0x178
	// Line 3701, Address: 0x2c460c, Func Offset: 0x18c
	// Line 3704, Address: 0x2c4614, Func Offset: 0x194
	// Line 3723, Address: 0x2c4620, Func Offset: 0x1a0
	// Line 3725, Address: 0x2c4628, Func Offset: 0x1a8
	// Line 3724, Address: 0x2c462c, Func Offset: 0x1ac
	// Line 3726, Address: 0x2c4630, Func Offset: 0x1b0
	// Line 3725, Address: 0x2c4634, Func Offset: 0x1b4
	// Line 3727, Address: 0x2c4638, Func Offset: 0x1b8
	// Line 3726, Address: 0x2c463c, Func Offset: 0x1bc
	// Line 3727, Address: 0x2c4640, Func Offset: 0x1c0
	// Line 3731, Address: 0x2c4644, Func Offset: 0x1c4
	// Line 3735, Address: 0x2c4670, Func Offset: 0x1f0
	// Line 3738, Address: 0x2c4678, Func Offset: 0x1f8
	// Line 3761, Address: 0x2c4680, Func Offset: 0x200
	// Line 3777, Address: 0x2c4688, Func Offset: 0x208
	// Line 3779, Address: 0x2c4690, Func Offset: 0x210
	// Line 3778, Address: 0x2c4694, Func Offset: 0x214
	// Line 3780, Address: 0x2c4698, Func Offset: 0x218
	// Line 3779, Address: 0x2c469c, Func Offset: 0x21c
	// Line 3780, Address: 0x2c46a0, Func Offset: 0x220
	// Line 3781, Address: 0x2c46a4, Func Offset: 0x224
	// Line 3785, Address: 0x2c46a8, Func Offset: 0x228
	// Line 3790, Address: 0x2c46d4, Func Offset: 0x254
	// Line 3798, Address: 0x2c46dc, Func Offset: 0x25c
	// Line 3814, Address: 0x2c46e0, Func Offset: 0x260
	// Line 3815, Address: 0x2c46e4, Func Offset: 0x264
	// Line 3817, Address: 0x2c46ec, Func Offset: 0x26c
	// Line 3818, Address: 0x2c4704, Func Offset: 0x284
	// Line 3819, Address: 0x2c470c, Func Offset: 0x28c
	// Line 3821, Address: 0x2c472c, Func Offset: 0x2ac
	// Line 3819, Address: 0x2c4730, Func Offset: 0x2b0
	// Line 3821, Address: 0x2c4734, Func Offset: 0x2b4
	// Line 3822, Address: 0x2c473c, Func Offset: 0x2bc
	// Line 3823, Address: 0x2c4740, Func Offset: 0x2c0
	// Line 3825, Address: 0x2c4748, Func Offset: 0x2c8
	// Line 3826, Address: 0x2c4750, Func Offset: 0x2d0
	// Line 3828, Address: 0x2c4758, Func Offset: 0x2d8
	// Line 3836, Address: 0x2c4768, Func Offset: 0x2e8
	// Line 3838, Address: 0x2c4784, Func Offset: 0x304
	// Line 3839, Address: 0x2c47a0, Func Offset: 0x320
	// Line 3840, Address: 0x2c47b0, Func Offset: 0x330
	// Line 3842, Address: 0x2c47b8, Func Offset: 0x338
	// Line 3843, Address: 0x2c47cc, Func Offset: 0x34c
	// Line 3844, Address: 0x2c47d0, Func Offset: 0x350
	// Line 3846, Address: 0x2c47d8, Func Offset: 0x358
	// Line 3847, Address: 0x2c47e8, Func Offset: 0x368
	// Line 3853, Address: 0x2c4820, Func Offset: 0x3a0
	// Line 3854, Address: 0x2c4824, Func Offset: 0x3a4
	// Line 3861, Address: 0x2c482c, Func Offset: 0x3ac
	// Line 3862, Address: 0x2c4830, Func Offset: 0x3b0
	// Line 3863, Address: 0x2c4838, Func Offset: 0x3b8
	// Line 3867, Address: 0x2c4840, Func Offset: 0x3c0
	// Line 3869, Address: 0x2c4848, Func Offset: 0x3c8
	// Line 3871, Address: 0x2c4850, Func Offset: 0x3d0
	// Line 3872, Address: 0x2c4854, Func Offset: 0x3d4
	// Line 3873, Address: 0x2c4864, Func Offset: 0x3e4
	// Line 3872, Address: 0x2c486c, Func Offset: 0x3ec
	// Line 3875, Address: 0x2c4870, Func Offset: 0x3f0
	// Line 3877, Address: 0x2c4874, Func Offset: 0x3f4
	// Line 3872, Address: 0x2c4878, Func Offset: 0x3f8
	// Line 3873, Address: 0x2c4880, Func Offset: 0x400
	// Line 3875, Address: 0x2c4898, Func Offset: 0x418
	// Line 3876, Address: 0x2c489c, Func Offset: 0x41c
	// Line 3877, Address: 0x2c48a0, Func Offset: 0x420
	// Line 3878, Address: 0x2c48a4, Func Offset: 0x424
	// Line 3879, Address: 0x2c48ac, Func Offset: 0x42c
	// Line 3880, Address: 0x2c48b0, Func Offset: 0x430
	// Line 3882, Address: 0x2c48b8, Func Offset: 0x438
	// Line 3883, Address: 0x2c48c0, Func Offset: 0x440
	// Line 3882, Address: 0x2c48c8, Func Offset: 0x448
	// Line 3883, Address: 0x2c48d0, Func Offset: 0x450
	// Line 3885, Address: 0x2c48e4, Func Offset: 0x464
	// Line 3886, Address: 0x2c4904, Func Offset: 0x484
	// Line 3887, Address: 0x2c4908, Func Offset: 0x488
	// Line 3889, Address: 0x2c490c, Func Offset: 0x48c
	// Line 3891, Address: 0x2c4914, Func Offset: 0x494
	// Line 3892, Address: 0x2c4934, Func Offset: 0x4b4
	// Line 3893, Address: 0x2c4938, Func Offset: 0x4b8
	// Line 3897, Address: 0x2c4940, Func Offset: 0x4c0
	// Line 3898, Address: 0x2c494c, Func Offset: 0x4cc
	// Line 3897, Address: 0x2c4954, Func Offset: 0x4d4
	// Line 3898, Address: 0x2c4958, Func Offset: 0x4d8
	// Line 3899, Address: 0x2c4968, Func Offset: 0x4e8
	// Line 3901, Address: 0x2c497c, Func Offset: 0x4fc
	// Line 3900, Address: 0x2c4980, Func Offset: 0x500
	// Line 3901, Address: 0x2c4984, Func Offset: 0x504
	// Line 3902, Address: 0x2c4988, Func Offset: 0x508
	// Line 3903, Address: 0x2c498c, Func Offset: 0x50c
	// Line 3917, Address: 0x2c4994, Func Offset: 0x514
	// Line 3982, Address: 0x2c49a4, Func Offset: 0x524
	// Line 3983, Address: 0x2c49ac, Func Offset: 0x52c
	// Line 3984, Address: 0x2c49b4, Func Offset: 0x534
	// Line 3985, Address: 0x2c49bc, Func Offset: 0x53c
	// Line 3993, Address: 0x2c49c4, Func Offset: 0x544
	// Line 3994, Address: 0x2c49cc, Func Offset: 0x54c
	// Line 3996, Address: 0x2c49d4, Func Offset: 0x554
	// Line 3997, Address: 0x2c49dc, Func Offset: 0x55c
	// Line 3998, Address: 0x2c49e4, Func Offset: 0x564
	// Line 4000, Address: 0x2c49ec, Func Offset: 0x56c
	// Line 4001, Address: 0x2c49f4, Func Offset: 0x574
	// Line 4002, Address: 0x2c49fc, Func Offset: 0x57c
	// Line 4001, Address: 0x2c4a04, Func Offset: 0x584
	// Line 4006, Address: 0x2c4a08, Func Offset: 0x588
	// Line 4001, Address: 0x2c4a0c, Func Offset: 0x58c
	// Line 4006, Address: 0x2c4a10, Func Offset: 0x590
	// Line 4001, Address: 0x2c4a14, Func Offset: 0x594
	// Line 4002, Address: 0x2c4a1c, Func Offset: 0x59c
	// Line 4006, Address: 0x2c4a34, Func Offset: 0x5b4
	// Line 4007, Address: 0x2c4a38, Func Offset: 0x5b8
	// Line 4017, Address: 0x2c4a40, Func Offset: 0x5c0
	// Line 4018, Address: 0x2c4a5c, Func Offset: 0x5dc
	// Line 4021, Address: 0x2c4a64, Func Offset: 0x5e4
	// Line 4022, Address: 0x2c4a70, Func Offset: 0x5f0
	// Line 4023, Address: 0x2c4a84, Func Offset: 0x604
	// Line 4031, Address: 0x2c4a8c, Func Offset: 0x60c
	// Line 4033, Address: 0x2c4a9c, Func Offset: 0x61c
	// Line 4034, Address: 0x2c4aa8, Func Offset: 0x628
	// Line 4036, Address: 0x2c4ac0, Func Offset: 0x640
	// Line 4037, Address: 0x2c4acc, Func Offset: 0x64c
	// Line 4040, Address: 0x2c4ad4, Func Offset: 0x654
	// Line 4042, Address: 0x2c4ae4, Func Offset: 0x664
	// Line 4043, Address: 0x2c4aec, Func Offset: 0x66c
	// Line 4044, Address: 0x2c4af4, Func Offset: 0x674
	// Line 4046, Address: 0x2c4afc, Func Offset: 0x67c
	// Line 4048, Address: 0x2c4b08, Func Offset: 0x688
	// Line 4049, Address: 0x2c4b14, Func Offset: 0x694
	// Line 4051, Address: 0x2c4b2c, Func Offset: 0x6ac
	// Line 4052, Address: 0x2c4b38, Func Offset: 0x6b8
	// Line 4055, Address: 0x2c4b40, Func Offset: 0x6c0
	// Line 4058, Address: 0x2c4b50, Func Offset: 0x6d0
	// Line 4059, Address: 0x2c4b58, Func Offset: 0x6d8
	// Line 4060, Address: 0x2c4b5c, Func Offset: 0x6dc
	// Line 4064, Address: 0x2c4b64, Func Offset: 0x6e4
	// Line 4065, Address: 0x2c4b70, Func Offset: 0x6f0
	// Line 4066, Address: 0x2c4b84, Func Offset: 0x704
	// Line 4068, Address: 0x2c4b9c, Func Offset: 0x71c
	// Line 4069, Address: 0x2c4ba8, Func Offset: 0x728
	// Line 4070, Address: 0x2c4bb0, Func Offset: 0x730
	// Line 4073, Address: 0x2c4bb8, Func Offset: 0x738
	// Line 4074, Address: 0x2c4bc8, Func Offset: 0x748
	// Line 4076, Address: 0x2c4bd0, Func Offset: 0x750
	// Line 4084, Address: 0x2c4bd8, Func Offset: 0x758
	// Line 4085, Address: 0x2c4bec, Func Offset: 0x76c
	// Line 4087, Address: 0x2c4bf4, Func Offset: 0x774
	// Line 4088, Address: 0x2c4c08, Func Offset: 0x788
	// Line 4089, Address: 0x2c4c10, Func Offset: 0x790
	// Line 4091, Address: 0x2c4c18, Func Offset: 0x798
	// Line 4092, Address: 0x2c4c20, Func Offset: 0x7a0
	// Line 4093, Address: 0x2c4c30, Func Offset: 0x7b0
	// Line 4095, Address: 0x2c4c38, Func Offset: 0x7b8
	// Line 4096, Address: 0x2c4c48, Func Offset: 0x7c8
	// Line 4097, Address: 0x2c4c58, Func Offset: 0x7d8
	// Line 4099, Address: 0x2c4c60, Func Offset: 0x7e0
	// Line 4100, Address: 0x2c4c70, Func Offset: 0x7f0
	// Line 4101, Address: 0x2c4c78, Func Offset: 0x7f8
	// Line 4103, Address: 0x2c4c80, Func Offset: 0x800
	// Line 4104, Address: 0x2c4c88, Func Offset: 0x808
	// Line 4105, Address: 0x2c4c98, Func Offset: 0x818
	// Line 4107, Address: 0x2c4ca0, Func Offset: 0x820
	// Line 4108, Address: 0x2c4cb0, Func Offset: 0x830
	// Line 4109, Address: 0x2c4cc0, Func Offset: 0x840
	// Line 4111, Address: 0x2c4cc8, Func Offset: 0x848
	// Line 4112, Address: 0x2c4cd8, Func Offset: 0x858
	// Line 4113, Address: 0x2c4ce0, Func Offset: 0x860
	// Line 4156, Address: 0x2c4ce8, Func Offset: 0x868
	// Line 4157, Address: 0x2c4cf8, Func Offset: 0x878
	// Line 4158, Address: 0x2c4cfc, Func Offset: 0x87c
	// Line 4159, Address: 0x2c4d04, Func Offset: 0x884
	// Line 4160, Address: 0x2c4d0c, Func Offset: 0x88c
	// Line 4161, Address: 0x2c4d18, Func Offset: 0x898
	// Line 4167, Address: 0x2c4d34, Func Offset: 0x8b4
	// Line 4169, Address: 0x2c4d50, Func Offset: 0x8d0
	// Line 4171, Address: 0x2c4d58, Func Offset: 0x8d8
	// Line 4170, Address: 0x2c4d60, Func Offset: 0x8e0
	// Line 4171, Address: 0x2c4d64, Func Offset: 0x8e4
	// Line 4172, Address: 0x2c4d68, Func Offset: 0x8e8
	// Line 4177, Address: 0x2c4d6c, Func Offset: 0x8ec
	// Line 4173, Address: 0x2c4d70, Func Offset: 0x8f0
	// Line 4174, Address: 0x2c4d74, Func Offset: 0x8f4
	// Line 4175, Address: 0x2c4d7c, Func Offset: 0x8fc
	// Line 4176, Address: 0x2c4d80, Func Offset: 0x900
	// Line 4177, Address: 0x2c4d84, Func Offset: 0x904
	// Line 4178, Address: 0x2c4d8c, Func Offset: 0x90c
	// Line 4179, Address: 0x2c4d90, Func Offset: 0x910
	// Line 4180, Address: 0x2c4d94, Func Offset: 0x914
	// Line 4181, Address: 0x2c4d98, Func Offset: 0x918
	// Line 4182, Address: 0x2c4d9c, Func Offset: 0x91c
	// Line 4183, Address: 0x2c4da0, Func Offset: 0x920
	// Line 4184, Address: 0x2c4da4, Func Offset: 0x924
	// Line 4185, Address: 0x2c4da8, Func Offset: 0x928
	// Line 4188, Address: 0x2c4db8, Func Offset: 0x938
	// Line 4189, Address: 0x2c4dc4, Func Offset: 0x944
	// Line 4188, Address: 0x2c4dcc, Func Offset: 0x94c
	// Line 4189, Address: 0x2c4dd0, Func Offset: 0x950
	// Line 4190, Address: 0x2c4de0, Func Offset: 0x960
	// Line 4198, Address: 0x2c4de4, Func Offset: 0x964
	// Line 4199, Address: 0x2c4df4, Func Offset: 0x974
	// Line 4200, Address: 0x2c4dfc, Func Offset: 0x97c
	// Line 4201, Address: 0x2c4e04, Func Offset: 0x984
	// Line 4208, Address: 0x2c4e2c, Func Offset: 0x9ac
	// Line 4210, Address: 0x2c4e38, Func Offset: 0x9b8
	// Line 4211, Address: 0x2c4e44, Func Offset: 0x9c4
	// Line 4216, Address: 0x2c4e4c, Func Offset: 0x9cc
	// Line 4212, Address: 0x2c4e50, Func Offset: 0x9d0
	// Line 4218, Address: 0x2c4e54, Func Offset: 0x9d4
	// Line 4219, Address: 0x2c4e5c, Func Offset: 0x9dc
	// Line 4222, Address: 0x2c4e78, Func Offset: 0x9f8
	// Line 4223, Address: 0x2c4e7c, Func Offset: 0x9fc
	// Line 4224, Address: 0x2c4e80, Func Offset: 0xa00
	// Line 4225, Address: 0x2c4e84, Func Offset: 0xa04
	// Line 4228, Address: 0x2c4e8c, Func Offset: 0xa0c
	// Line 4229, Address: 0x2c4e90, Func Offset: 0xa10
	// Func End, Address: 0x2c4eac, Func Offset: 0xa2c
	scePrintf("Adv_BioCvTitle - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2c4eb0
void ResetOptionMenuParam(int Mode)
{
	int i;
	_anon8* ap;
	// Line 4243, Address: 0x2c4eb0, Func Offset: 0
	// Line 4244, Address: 0x2c4ebc, Func Offset: 0xc
	// Line 4247, Address: 0x2c4ec4, Func Offset: 0x14
	// Line 4249, Address: 0x2c4ee0, Func Offset: 0x30
	// Line 4259, Address: 0x2c4ef0, Func Offset: 0x40
	// Line 4261, Address: 0x2c4f00, Func Offset: 0x50
	// Line 4262, Address: 0x2c4f14, Func Offset: 0x64
	// Line 4263, Address: 0x2c4f1c, Func Offset: 0x6c
	// Line 4264, Address: 0x2c4f24, Func Offset: 0x74
	// Line 4265, Address: 0x2c4f38, Func Offset: 0x88
	// Line 4266, Address: 0x2c4f40, Func Offset: 0x90
	// Line 4267, Address: 0x2c4f48, Func Offset: 0x98
	// Line 4268, Address: 0x2c4f4c, Func Offset: 0x9c
	// Line 4267, Address: 0x2c4f50, Func Offset: 0xa0
	// Line 4268, Address: 0x2c4f54, Func Offset: 0xa4
	// Line 4271, Address: 0x2c4f5c, Func Offset: 0xac
	// Line 4268, Address: 0x2c4f60, Func Offset: 0xb0
	// Line 4269, Address: 0x2c4f64, Func Offset: 0xb4
	// Line 4271, Address: 0x2c4f68, Func Offset: 0xb8
	// Line 4272, Address: 0x2c4f70, Func Offset: 0xc0
	// Line 4271, Address: 0x2c4f74, Func Offset: 0xc4
	// Line 4272, Address: 0x2c4f78, Func Offset: 0xc8
	// Line 4273, Address: 0x2c4f80, Func Offset: 0xd0
	// Line 4272, Address: 0x2c4f84, Func Offset: 0xd4
	// Line 4273, Address: 0x2c4f88, Func Offset: 0xd8
	// Line 4274, Address: 0x2c4f90, Func Offset: 0xe0
	// Line 4273, Address: 0x2c4f94, Func Offset: 0xe4
	// Line 4274, Address: 0x2c4f98, Func Offset: 0xe8
	// Line 4275, Address: 0x2c4fa0, Func Offset: 0xf0
	// Line 4277, Address: 0x2c4fac, Func Offset: 0xfc
	// Line 4279, Address: 0x2c4fb0, Func Offset: 0x100
	// Line 4280, Address: 0x2c4fb4, Func Offset: 0x104
	// Line 4278, Address: 0x2c4fb8, Func Offset: 0x108
	// Line 4279, Address: 0x2c4fbc, Func Offset: 0x10c
	// Line 4280, Address: 0x2c4fc0, Func Offset: 0x110
	// Line 4279, Address: 0x2c4fc4, Func Offset: 0x114
	// Line 4280, Address: 0x2c4fc8, Func Offset: 0x118
	// Line 4281, Address: 0x2c4fd0, Func Offset: 0x120
	// Line 4283, Address: 0x2c4fd8, Func Offset: 0x128
	// Line 4284, Address: 0x2c4fe0, Func Offset: 0x130
	// Line 4285, Address: 0x2c4ff0, Func Offset: 0x140
	// Line 4286, Address: 0x2c4ffc, Func Offset: 0x14c
	// Line 4287, Address: 0x2c5000, Func Offset: 0x150
	// Line 4288, Address: 0x2c5020, Func Offset: 0x170
	// Line 4289, Address: 0x2c5028, Func Offset: 0x178
	// Line 4290, Address: 0x2c5030, Func Offset: 0x180
	// Line 4291, Address: 0x2c5038, Func Offset: 0x188
	// Line 4292, Address: 0x2c5044, Func Offset: 0x194
	// Line 4294, Address: 0x2c5054, Func Offset: 0x1a4
	// Line 4295, Address: 0x2c5064, Func Offset: 0x1b4
	// Line 4296, Address: 0x2c5078, Func Offset: 0x1c8
	// Line 4297, Address: 0x2c5080, Func Offset: 0x1d0
	// Line 4298, Address: 0x2c5088, Func Offset: 0x1d8
	// Line 4299, Address: 0x2c509c, Func Offset: 0x1ec
	// Line 4300, Address: 0x2c50a4, Func Offset: 0x1f4
	// Line 4301, Address: 0x2c50ac, Func Offset: 0x1fc
	// Line 4302, Address: 0x2c50b0, Func Offset: 0x200
	// Line 4301, Address: 0x2c50b4, Func Offset: 0x204
	// Line 4302, Address: 0x2c50b8, Func Offset: 0x208
	// Line 4306, Address: 0x2c50cc, Func Offset: 0x21c
	// Line 4307, Address: 0x2c50d0, Func Offset: 0x220
	// Line 4310, Address: 0x2c50d4, Func Offset: 0x224
	// Line 4308, Address: 0x2c50d8, Func Offset: 0x228
	// Line 4309, Address: 0x2c50dc, Func Offset: 0x22c
	// Line 4310, Address: 0x2c50e0, Func Offset: 0x230
	// Line 4311, Address: 0x2c50ec, Func Offset: 0x23c
	// Func End, Address: 0x2c50fc, Func Offset: 0x24c
}

// 
// Start address: 0x2c5100
void DisplayOptionScrollPlate(float PosX, float PosY)
{
	_anon0* qp;
	int i;
	// Line 4321, Address: 0x2c5100, Func Offset: 0
	// Line 4324, Address: 0x2c5114, Func Offset: 0x14
	// Line 4321, Address: 0x2c5118, Func Offset: 0x18
	// Line 4324, Address: 0x2c511c, Func Offset: 0x1c
	// Line 4326, Address: 0x2c5124, Func Offset: 0x24
	// Line 4327, Address: 0x2c5130, Func Offset: 0x30
	// Line 4328, Address: 0x2c5134, Func Offset: 0x34
	// Line 4329, Address: 0x2c5168, Func Offset: 0x68
	// Line 4330, Address: 0x2c5198, Func Offset: 0x98
	// Line 4331, Address: 0x2c51d4, Func Offset: 0xd4
	// Line 4332, Address: 0x2c51e4, Func Offset: 0xe4
	// Line 4333, Address: 0x2c51ec, Func Offset: 0xec
	// Func End, Address: 0x2c5208, Func Offset: 0x108
}

// 
// Start address: 0x2c5210
void DisplayOptionBg(int Level, int Flag)
{
	_anon0* qp;
	float s[2];
	float y[2];
	int j;
	int i;
	_anon8* ap;
	// Line 4342, Address: 0x2c5210, Func Offset: 0
	// Line 4343, Address: 0x2c522c, Func Offset: 0x1c
	// Line 4342, Address: 0x2c5230, Func Offset: 0x20
	// Line 4343, Address: 0x2c5234, Func Offset: 0x24
	// Line 4342, Address: 0x2c5238, Func Offset: 0x28
	// Line 4345, Address: 0x2c5240, Func Offset: 0x30
	// Line 4342, Address: 0x2c5244, Func Offset: 0x34
	// Line 4345, Address: 0x2c5248, Func Offset: 0x38
	// Line 4342, Address: 0x2c524c, Func Offset: 0x3c
	// Line 4345, Address: 0x2c5254, Func Offset: 0x44
	// Line 4346, Address: 0x2c525c, Func Offset: 0x4c
	// Line 4345, Address: 0x2c5268, Func Offset: 0x58
	// Line 4346, Address: 0x2c526c, Func Offset: 0x5c
	// Line 4347, Address: 0x2c5270, Func Offset: 0x60
	// Line 4349, Address: 0x2c5278, Func Offset: 0x68
	// Line 4359, Address: 0x2c52a4, Func Offset: 0x94
	// Line 4360, Address: 0x2c52b0, Func Offset: 0xa0
	// Line 4361, Address: 0x2c52c0, Func Offset: 0xb0
	// Line 4362, Address: 0x2c52cc, Func Offset: 0xbc
	// Line 4363, Address: 0x2c52d0, Func Offset: 0xc0
	// Line 4362, Address: 0x2c52d8, Func Offset: 0xc8
	// Line 4363, Address: 0x2c52e0, Func Offset: 0xd0
	// Line 4364, Address: 0x2c52e8, Func Offset: 0xd8
	// Line 4366, Address: 0x2c52f0, Func Offset: 0xe0
	// Line 4370, Address: 0x2c52f8, Func Offset: 0xe8
	// Line 4365, Address: 0x2c5300, Func Offset: 0xf0
	// Line 4366, Address: 0x2c5308, Func Offset: 0xf8
	// Line 4367, Address: 0x2c531c, Func Offset: 0x10c
	// Line 4369, Address: 0x2c5334, Func Offset: 0x124
	// Line 4370, Address: 0x2c533c, Func Offset: 0x12c
	// Line 4371, Address: 0x2c5350, Func Offset: 0x140
	// Line 4374, Address: 0x2c5368, Func Offset: 0x158
	// Line 4375, Address: 0x2c5378, Func Offset: 0x168
	// Line 4374, Address: 0x2c5380, Func Offset: 0x170
	// Line 4375, Address: 0x2c5388, Func Offset: 0x178
	// Line 4377, Address: 0x2c5390, Func Offset: 0x180
	// Line 4386, Address: 0x2c5398, Func Offset: 0x188
	// Line 4388, Address: 0x2c53a0, Func Offset: 0x190
	// Line 4389, Address: 0x2c53c4, Func Offset: 0x1b4
	// Line 4390, Address: 0x2c53ec, Func Offset: 0x1dc
	// Line 4391, Address: 0x2c5410, Func Offset: 0x200
	// Line 4392, Address: 0x2c5438, Func Offset: 0x228
	// Line 4393, Address: 0x2c545c, Func Offset: 0x24c
	// Line 4395, Address: 0x2c5480, Func Offset: 0x270
	// Line 4398, Address: 0x2c5488, Func Offset: 0x278
	// Func End, Address: 0x2c54bc, Func Offset: 0x2ac
}

// 
// Start address: 0x2c54c0
int DisplayOptionPlateLevel0(int PortId, int Flag)
{
	int ForceCursorMoveFlag;
	int PuruFindFlag;
	unsigned int Alpha;
	int ReturnCode;
	int i;
	_anon0* qp;
	_anon8* ap;
	// Line 4410, Address: 0x2c54c0, Func Offset: 0
	// Line 4411, Address: 0x2c54e4, Func Offset: 0x24
	// Line 4419, Address: 0x2c54ec, Func Offset: 0x2c
	// Line 4416, Address: 0x2c5504, Func Offset: 0x44
	// Line 4414, Address: 0x2c5508, Func Offset: 0x48
	// Line 4419, Address: 0x2c550c, Func Offset: 0x4c
	// Line 4420, Address: 0x2c551c, Func Offset: 0x5c
	// Line 4422, Address: 0x2c5528, Func Offset: 0x68
	// Line 4423, Address: 0x2c5534, Func Offset: 0x74
	// Line 4424, Address: 0x2c553c, Func Offset: 0x7c
	// Line 4423, Address: 0x2c5540, Func Offset: 0x80
	// Line 4424, Address: 0x2c5544, Func Offset: 0x84
	// Line 4425, Address: 0x2c5550, Func Offset: 0x90
	// Line 4426, Address: 0x2c5554, Func Offset: 0x94
	// Line 4425, Address: 0x2c5558, Func Offset: 0x98
	// Line 4430, Address: 0x2c555c, Func Offset: 0x9c
	// Line 4434, Address: 0x2c5564, Func Offset: 0xa4
	// Line 4436, Address: 0x2c55a4, Func Offset: 0xe4
	// Line 4438, Address: 0x2c55ac, Func Offset: 0xec
	// Line 4440, Address: 0x2c55bc, Func Offset: 0xfc
	// Line 4441, Address: 0x2c55c4, Func Offset: 0x104
	// Line 4442, Address: 0x2c55dc, Func Offset: 0x11c
	// Line 4443, Address: 0x2c5600, Func Offset: 0x140
	// Line 4444, Address: 0x2c5610, Func Offset: 0x150
	// Line 4445, Address: 0x2c5620, Func Offset: 0x160
	// Line 4446, Address: 0x2c5638, Func Offset: 0x178
	// Line 4447, Address: 0x2c5640, Func Offset: 0x180
	// Line 4449, Address: 0x2c5648, Func Offset: 0x188
	// Line 4450, Address: 0x2c5658, Func Offset: 0x198
	// Line 4451, Address: 0x2c5670, Func Offset: 0x1b0
	// Line 4452, Address: 0x2c5678, Func Offset: 0x1b8
	// Line 4453, Address: 0x2c5684, Func Offset: 0x1c4
	// Line 4454, Address: 0x2c568c, Func Offset: 0x1cc
	// Line 4458, Address: 0x2c5698, Func Offset: 0x1d8
	// Line 4459, Address: 0x2c56a0, Func Offset: 0x1e0
	// Line 4460, Address: 0x2c56a8, Func Offset: 0x1e8
	// Line 4461, Address: 0x2c56c4, Func Offset: 0x204
	// Line 4462, Address: 0x2c56d0, Func Offset: 0x210
	// Line 4463, Address: 0x2c56d4, Func Offset: 0x214
	// Line 4464, Address: 0x2c56dc, Func Offset: 0x21c
	// Line 4465, Address: 0x2c56e4, Func Offset: 0x224
	// Line 4466, Address: 0x2c56fc, Func Offset: 0x23c
	// Line 4469, Address: 0x2c5704, Func Offset: 0x244
	// Line 4470, Address: 0x2c5710, Func Offset: 0x250
	// Line 4471, Address: 0x2c5718, Func Offset: 0x258
	// Line 4472, Address: 0x2c5724, Func Offset: 0x264
	// Line 4474, Address: 0x2c5734, Func Offset: 0x274
	// Line 4475, Address: 0x2c573c, Func Offset: 0x27c
	// Line 4476, Address: 0x2c5744, Func Offset: 0x284
	// Line 4477, Address: 0x2c575c, Func Offset: 0x29c
	// Line 4480, Address: 0x2c5764, Func Offset: 0x2a4
	// Line 4484, Address: 0x2c5770, Func Offset: 0x2b0
	// Line 4485, Address: 0x2c5780, Func Offset: 0x2c0
	// Line 4486, Address: 0x2c57a4, Func Offset: 0x2e4
	// Line 4487, Address: 0x2c57c4, Func Offset: 0x304
	// Line 4488, Address: 0x2c57cc, Func Offset: 0x30c
	// Line 4490, Address: 0x2c57ec, Func Offset: 0x32c
	// Line 4492, Address: 0x2c57f8, Func Offset: 0x338
	// Line 4494, Address: 0x2c5800, Func Offset: 0x340
	// Line 4495, Address: 0x2c5808, Func Offset: 0x348
	// Line 4496, Address: 0x2c5814, Func Offset: 0x354
	// Line 4501, Address: 0x2c5824, Func Offset: 0x364
	// Line 4504, Address: 0x2c5830, Func Offset: 0x370
	// Line 4505, Address: 0x2c5838, Func Offset: 0x378
	// Line 4506, Address: 0x2c5844, Func Offset: 0x384
	// Line 4507, Address: 0x2c5868, Func Offset: 0x3a8
	// Line 4508, Address: 0x2c58a0, Func Offset: 0x3e0
	// Line 4509, Address: 0x2c58a8, Func Offset: 0x3e8
	// Line 4511, Address: 0x2c58c8, Func Offset: 0x408
	// Line 4512, Address: 0x2c58d4, Func Offset: 0x414
	// Line 4513, Address: 0x2c58d8, Func Offset: 0x418
	// Line 4515, Address: 0x2c58e0, Func Offset: 0x420
	// Line 4516, Address: 0x2c58ec, Func Offset: 0x42c
	// Line 4521, Address: 0x2c58f8, Func Offset: 0x438
	// Line 4530, Address: 0x2c590c, Func Offset: 0x44c
	// Line 4532, Address: 0x2c5910, Func Offset: 0x450
	// Line 4531, Address: 0x2c5914, Func Offset: 0x454
	// Line 4532, Address: 0x2c5918, Func Offset: 0x458
	// Line 4531, Address: 0x2c591c, Func Offset: 0x45c
	// Line 4532, Address: 0x2c5920, Func Offset: 0x460
	// Line 4533, Address: 0x2c592c, Func Offset: 0x46c
	// Line 4535, Address: 0x2c5938, Func Offset: 0x478
	// Line 4533, Address: 0x2c5940, Func Offset: 0x480
	// Line 4538, Address: 0x2c5954, Func Offset: 0x494
	// Line 4539, Address: 0x2c5978, Func Offset: 0x4b8
	// Line 4543, Address: 0x2c599c, Func Offset: 0x4dc
	// Line 4544, Address: 0x2c59c0, Func Offset: 0x500
	// Line 4548, Address: 0x2c59e4, Func Offset: 0x524
	// Line 4549, Address: 0x2c5a08, Func Offset: 0x548
	// Line 4553, Address: 0x2c5a30, Func Offset: 0x570
	// Line 4554, Address: 0x2c5a54, Func Offset: 0x594
	// Line 4558, Address: 0x2c5a7c, Func Offset: 0x5bc
	// Line 4559, Address: 0x2c5a9c, Func Offset: 0x5dc
	// Line 4563, Address: 0x2c5ac4, Func Offset: 0x604
	// Line 4564, Address: 0x2c5ae8, Func Offset: 0x628
	// Line 4568, Address: 0x2c5b10, Func Offset: 0x650
	// Line 4569, Address: 0x2c5b34, Func Offset: 0x674
	// Line 4573, Address: 0x2c5b5c, Func Offset: 0x69c
	// Line 4574, Address: 0x2c5b84, Func Offset: 0x6c4
	// Line 4578, Address: 0x2c5bac, Func Offset: 0x6ec
	// Line 4579, Address: 0x2c5bd4, Func Offset: 0x714
	// Line 4583, Address: 0x2c5bfc, Func Offset: 0x73c
	// Line 4584, Address: 0x2c5c24, Func Offset: 0x764
	// Line 4588, Address: 0x2c5c4c, Func Offset: 0x78c
	// Line 4589, Address: 0x2c5c70, Func Offset: 0x7b0
	// Line 4593, Address: 0x2c5cb0, Func Offset: 0x7f0
	// Line 4594, Address: 0x2c5cd8, Func Offset: 0x818
	// Line 4598, Address: 0x2c5d00, Func Offset: 0x840
	// Line 4599, Address: 0x2c5d28, Func Offset: 0x868
	// Line 4603, Address: 0x2c5d50, Func Offset: 0x890
	// Line 4604, Address: 0x2c5d74, Func Offset: 0x8b4
	// Line 4607, Address: 0x2c5da4, Func Offset: 0x8e4
	// Line 4609, Address: 0x2c5da8, Func Offset: 0x8e8
	// Line 4610, Address: 0x2c5db4, Func Offset: 0x8f4
	// Line 4612, Address: 0x2c5dc0, Func Offset: 0x900
	// Line 4611, Address: 0x2c5dc4, Func Offset: 0x904
	// Line 4612, Address: 0x2c5dc8, Func Offset: 0x908
	// Line 4613, Address: 0x2c5dcc, Func Offset: 0x90c
	// Line 4614, Address: 0x2c5dd4, Func Offset: 0x914
	// Line 4615, Address: 0x2c5ddc, Func Offset: 0x91c
	// Line 4616, Address: 0x2c5de0, Func Offset: 0x920
	// Line 4617, Address: 0x2c5e10, Func Offset: 0x950
	// Line 4619, Address: 0x2c5e20, Func Offset: 0x960
	// Line 4620, Address: 0x2c5e30, Func Offset: 0x970
	// Line 4621, Address: 0x2c5e3c, Func Offset: 0x97c
	// Line 4622, Address: 0x2c5e64, Func Offset: 0x9a4
	// Line 4623, Address: 0x2c5e6c, Func Offset: 0x9ac
	// Line 4625, Address: 0x2c5e94, Func Offset: 0x9d4
	// Line 4626, Address: 0x2c5ebc, Func Offset: 0x9fc
	// Line 4627, Address: 0x2c5ec4, Func Offset: 0xa04
	// Line 4628, Address: 0x2c5eec, Func Offset: 0xa2c
	// Line 4629, Address: 0x2c5ef8, Func Offset: 0xa38
	// Line 4630, Address: 0x2c5f20, Func Offset: 0xa60
	// Line 4631, Address: 0x2c5f28, Func Offset: 0xa68
	// Line 4635, Address: 0x2c5f50, Func Offset: 0xa90
	// Line 4636, Address: 0x2c5f60, Func Offset: 0xaa0
	// Line 4637, Address: 0x2c5f84, Func Offset: 0xac4
	// Line 4638, Address: 0x2c5fac, Func Offset: 0xaec
	// Line 4639, Address: 0x2c5fb4, Func Offset: 0xaf4
	// Line 4640, Address: 0x2c5fd8, Func Offset: 0xb18
	// Line 4643, Address: 0x2c6000, Func Offset: 0xb40
	// Line 4644, Address: 0x2c6010, Func Offset: 0xb50
	// Line 4645, Address: 0x2c6020, Func Offset: 0xb60
	// Line 4646, Address: 0x2c6048, Func Offset: 0xb88
	// Line 4647, Address: 0x2c6050, Func Offset: 0xb90
	// Line 4649, Address: 0x2c6078, Func Offset: 0xbb8
	// Line 4650, Address: 0x2c60a0, Func Offset: 0xbe0
	// Line 4651, Address: 0x2c60a8, Func Offset: 0xbe8
	// Line 4652, Address: 0x2c60d0, Func Offset: 0xc10
	// Line 4653, Address: 0x2c60e0, Func Offset: 0xc20
	// Line 4654, Address: 0x2c6108, Func Offset: 0xc48
	// Line 4655, Address: 0x2c6110, Func Offset: 0xc50
	// Line 4659, Address: 0x2c6138, Func Offset: 0xc78
	// Line 4661, Address: 0x2c615c, Func Offset: 0xc9c
	// Line 4663, Address: 0x2c6164, Func Offset: 0xca4
	// Line 4664, Address: 0x2c6168, Func Offset: 0xca8
	// Func End, Address: 0x2c6190, Func Offset: 0xcd0
}

// 
// Start address: 0x2c6190
int DisplayOptionPlateLevel1(int PortId, int Flag)
{
	float KeyNameV[12];
	float KeyNameU[12];
	float KeyNameSizY[12];
	float KeyNameSizX[12];
	float KeyNamePosY[12];
	float KeyNamePosX[12];
	int ButtonSet[3][3];
	int i;
	int ReturnCode;
	_anon0* qp;
	_anon8* ap;
	// Line 4676, Address: 0x2c6190, Func Offset: 0
	// Line 4677, Address: 0x2c61bc, Func Offset: 0x2c
	// Line 4679, Address: 0x2c61c4, Func Offset: 0x34
	// Line 4684, Address: 0x2c61cc, Func Offset: 0x3c
	// Line 4706, Address: 0x2c61e4, Func Offset: 0x54
	// Line 4707, Address: 0x2c61e8, Func Offset: 0x58
	// Line 4706, Address: 0x2c61ec, Func Offset: 0x5c
	// Line 4684, Address: 0x2c61f0, Func Offset: 0x60
	// Line 4706, Address: 0x2c61f4, Func Offset: 0x64
	// Line 4684, Address: 0x2c61f8, Func Offset: 0x68
	// Line 4706, Address: 0x2c6200, Func Offset: 0x70
	// Line 4707, Address: 0x2c6208, Func Offset: 0x78
	// Line 4708, Address: 0x2c6210, Func Offset: 0x80
	// Line 4706, Address: 0x2c6218, Func Offset: 0x88
	// Line 4708, Address: 0x2c621c, Func Offset: 0x8c
	// Line 4709, Address: 0x2c6220, Func Offset: 0x90
	// Line 4706, Address: 0x2c6224, Func Offset: 0x94
	// Line 4707, Address: 0x2c6230, Func Offset: 0xa0
	// Line 4709, Address: 0x2c6238, Func Offset: 0xa8
	// Line 4710, Address: 0x2c6240, Func Offset: 0xb0
	// Line 4707, Address: 0x2c6244, Func Offset: 0xb4
	// Line 4708, Address: 0x2c6254, Func Offset: 0xc4
	// Line 4710, Address: 0x2c6260, Func Offset: 0xd0
	// Line 4711, Address: 0x2c6264, Func Offset: 0xd4
	// Line 4710, Address: 0x2c6268, Func Offset: 0xd8
	// Line 4708, Address: 0x2c626c, Func Offset: 0xdc
	// Line 4709, Address: 0x2c6278, Func Offset: 0xe8
	// Line 4711, Address: 0x2c6280, Func Offset: 0xf0
	// Line 4709, Address: 0x2c6288, Func Offset: 0xf8
	// Line 4710, Address: 0x2c6298, Func Offset: 0x108
	// Line 4711, Address: 0x2c62b0, Func Offset: 0x120
	// Line 4720, Address: 0x2c62c4, Func Offset: 0x134
	// Line 4721, Address: 0x2c62cc, Func Offset: 0x13c
	// Line 4722, Address: 0x2c62f4, Func Offset: 0x164
	// Line 4723, Address: 0x2c6300, Func Offset: 0x170
	// Line 4744, Address: 0x2c6304, Func Offset: 0x174
	// Line 4745, Address: 0x2c6314, Func Offset: 0x184
	// Line 4746, Address: 0x2c6320, Func Offset: 0x190
	// Line 4745, Address: 0x2c6328, Func Offset: 0x198
	// Line 4746, Address: 0x2c6340, Func Offset: 0x1b0
	// Line 4747, Address: 0x2c635c, Func Offset: 0x1cc
	// Line 4749, Address: 0x2c6370, Func Offset: 0x1e0
	// Line 4750, Address: 0x2c6394, Func Offset: 0x204
	// Line 4751, Address: 0x2c63a4, Func Offset: 0x214
	// Line 4752, Address: 0x2c63ac, Func Offset: 0x21c
	// Line 4753, Address: 0x2c63b8, Func Offset: 0x228
	// Line 4754, Address: 0x2c63c4, Func Offset: 0x234
	// Line 4753, Address: 0x2c63cc, Func Offset: 0x23c
	// Line 4754, Address: 0x2c63dc, Func Offset: 0x24c
	// Line 4753, Address: 0x2c63e4, Func Offset: 0x254
	// Line 4754, Address: 0x2c63ec, Func Offset: 0x25c
	// Line 4755, Address: 0x2c6414, Func Offset: 0x284
	// Line 4757, Address: 0x2c6418, Func Offset: 0x288
	// Line 4758, Address: 0x2c643c, Func Offset: 0x2ac
	// Line 4764, Address: 0x2c644c, Func Offset: 0x2bc
	// Line 4767, Address: 0x2c6454, Func Offset: 0x2c4
	// Line 4768, Address: 0x2c6478, Func Offset: 0x2e8
	// Line 4769, Address: 0x2c64a0, Func Offset: 0x310
	// Line 4840, Address: 0x2c64c0, Func Offset: 0x330
	// Line 4841, Address: 0x2c64e8, Func Offset: 0x358
	// Line 4842, Address: 0x2c650c, Func Offset: 0x37c
	// Line 4845, Address: 0x2c652c, Func Offset: 0x39c
	// Line 4846, Address: 0x2c6554, Func Offset: 0x3c4
	// Line 4847, Address: 0x2c657c, Func Offset: 0x3ec
	// Line 4850, Address: 0x2c659c, Func Offset: 0x40c
	// Line 4851, Address: 0x2c65c0, Func Offset: 0x430
	// Line 4852, Address: 0x2c6618, Func Offset: 0x488
	// Line 4855, Address: 0x2c6638, Func Offset: 0x4a8
	// Line 4856, Address: 0x2c665c, Func Offset: 0x4cc
	// Line 4857, Address: 0x2c6684, Func Offset: 0x4f4
	// Line 4860, Address: 0x2c66bc, Func Offset: 0x52c
	// Line 4861, Address: 0x2c66e0, Func Offset: 0x550
	// Line 4862, Address: 0x2c6708, Func Offset: 0x578
	// Line 4864, Address: 0x2c6740, Func Offset: 0x5b0
	// Line 4865, Address: 0x2c675c, Func Offset: 0x5cc
	// Line 4866, Address: 0x2c6788, Func Offset: 0x5f8
	// Line 4867, Address: 0x2c67ec, Func Offset: 0x65c
	// Line 4868, Address: 0x2c680c, Func Offset: 0x67c
	// Line 4869, Address: 0x2c6848, Func Offset: 0x6b8
	// Line 4870, Address: 0x2c6898, Func Offset: 0x708
	// Line 4871, Address: 0x2c68b8, Func Offset: 0x728
	// Line 4870, Address: 0x2c68c0, Func Offset: 0x730
	// Line 4871, Address: 0x2c68d4, Func Offset: 0x744
	// Line 4872, Address: 0x2c68dc, Func Offset: 0x74c
	// Line 4873, Address: 0x2c6910, Func Offset: 0x780
	// Line 4874, Address: 0x2c693c, Func Offset: 0x7ac
	// Line 4875, Address: 0x2c6948, Func Offset: 0x7b8
	// Line 4876, Address: 0x2c6978, Func Offset: 0x7e8
	// Line 4877, Address: 0x2c6980, Func Offset: 0x7f0
	// Line 4879, Address: 0x2c69a8, Func Offset: 0x818
	// Line 4880, Address: 0x2c69c8, Func Offset: 0x838
	// Line 4881, Address: 0x2c69d8, Func Offset: 0x848
	// Line 4882, Address: 0x2c6a24, Func Offset: 0x894
	// Line 4883, Address: 0x2c6a94, Func Offset: 0x904
	// Line 4884, Address: 0x2c6aac, Func Offset: 0x91c
	// Line 4885, Address: 0x2c6ad4, Func Offset: 0x944
	// Line 4886, Address: 0x2c6b20, Func Offset: 0x990
	// Line 4887, Address: 0x2c6b88, Func Offset: 0x9f8
	// Line 4888, Address: 0x2c6b90, Func Offset: 0xa00
	// Line 4889, Address: 0x2c6bd8, Func Offset: 0xa48
	// Line 4891, Address: 0x2c6c20, Func Offset: 0xa90
	// Line 4892, Address: 0x2c6c28, Func Offset: 0xa98
	// Line 4893, Address: 0x2c6c64, Func Offset: 0xad4
	// Line 4894, Address: 0x2c6cbc, Func Offset: 0xb2c
	// Line 4895, Address: 0x2c6cc0, Func Offset: 0xb30
	// Line 4896, Address: 0x2c6ce4, Func Offset: 0xb54
	// Line 4895, Address: 0x2c6ce8, Func Offset: 0xb58
	// Line 4896, Address: 0x2c6cf8, Func Offset: 0xb68
	// Line 4895, Address: 0x2c6cfc, Func Offset: 0xb6c
	// Line 4896, Address: 0x2c6d08, Func Offset: 0xb78
	// Line 4899, Address: 0x2c6d10, Func Offset: 0xb80
	// Line 4901, Address: 0x2c6d18, Func Offset: 0xb88
	// Line 4902, Address: 0x2c6d1c, Func Offset: 0xb8c
	// Func End, Address: 0x2c6d4c, Func Offset: 0xbbc
}

// 
// Start address: 0x2c6d50
int DisplayOptionPlateLevel2(int PortId, int Flag)
{
	unsigned int CursorCol[4];
	char Str[4];
	_anon32 BotRigt;
	_anon32 TopLeft;
	int ReturnCode;
	_anon0* qp;
	_anon8* ap;
	// Line 4914, Address: 0x2c6d50, Func Offset: 0
	// Line 4915, Address: 0x2c6d6c, Func Offset: 0x1c
	// Line 4916, Address: 0x2c6d74, Func Offset: 0x24
	// Line 4922, Address: 0x2c6d7c, Func Offset: 0x2c
	// Line 4918, Address: 0x2c6d8c, Func Offset: 0x3c
	// Line 4925, Address: 0x2c6d90, Func Offset: 0x40
	// Line 4926, Address: 0x2c6d98, Func Offset: 0x48
	// Line 4927, Address: 0x2c6dc0, Func Offset: 0x70
	// Line 4929, Address: 0x2c6dcc, Func Offset: 0x7c
	// Line 4930, Address: 0x2c6dd4, Func Offset: 0x84
	// Line 4931, Address: 0x2c6de0, Func Offset: 0x90
	// Line 4932, Address: 0x2c6de8, Func Offset: 0x98
	// Line 4933, Address: 0x2c6df4, Func Offset: 0xa4
	// Line 4934, Address: 0x2c6e00, Func Offset: 0xb0
	// Line 4935, Address: 0x2c6e08, Func Offset: 0xb8
	// Line 4936, Address: 0x2c6e14, Func Offset: 0xc4
	// Line 4937, Address: 0x2c6e24, Func Offset: 0xd4
	// Line 4938, Address: 0x2c6e2c, Func Offset: 0xdc
	// Line 4939, Address: 0x2c6e38, Func Offset: 0xe8
	// Line 4940, Address: 0x2c6e44, Func Offset: 0xf4
	// Line 4942, Address: 0x2c6e48, Func Offset: 0xf8
	// Line 4943, Address: 0x2c6e50, Func Offset: 0x100
	// Line 4944, Address: 0x2c6e5c, Func Offset: 0x10c
	// Line 4945, Address: 0x2c6e6c, Func Offset: 0x11c
	// Line 4946, Address: 0x2c6e74, Func Offset: 0x124
	// Line 4947, Address: 0x2c6e80, Func Offset: 0x130
	// Line 4948, Address: 0x2c6e8c, Func Offset: 0x13c
	// Line 4950, Address: 0x2c6e90, Func Offset: 0x140
	// Line 4951, Address: 0x2c6e98, Func Offset: 0x148
	// Line 4952, Address: 0x2c6ea4, Func Offset: 0x154
	// Line 4953, Address: 0x2c6eb4, Func Offset: 0x164
	// Line 4954, Address: 0x2c6ebc, Func Offset: 0x16c
	// Line 4955, Address: 0x2c6ec8, Func Offset: 0x178
	// Line 4956, Address: 0x2c6ed4, Func Offset: 0x184
	// Line 4958, Address: 0x2c6ed8, Func Offset: 0x188
	// Line 4959, Address: 0x2c6ee0, Func Offset: 0x190
	// Line 4960, Address: 0x2c6eec, Func Offset: 0x19c
	// Line 4961, Address: 0x2c6efc, Func Offset: 0x1ac
	// Line 4962, Address: 0x2c6f04, Func Offset: 0x1b4
	// Line 4963, Address: 0x2c6f10, Func Offset: 0x1c0
	// Line 4964, Address: 0x2c6f1c, Func Offset: 0x1cc
	// Line 4977, Address: 0x2c6f24, Func Offset: 0x1d4
	// Line 4979, Address: 0x2c6f4c, Func Offset: 0x1fc
	// Line 4980, Address: 0x2c6f74, Func Offset: 0x224
	// Line 4986, Address: 0x2c6f94, Func Offset: 0x244
	// Line 4987, Address: 0x2c6fb8, Func Offset: 0x268
	// Line 4989, Address: 0x2c6fe4, Func Offset: 0x294
	// Line 4993, Address: 0x2c7008, Func Offset: 0x2b8
	// Line 4994, Address: 0x2c7030, Func Offset: 0x2e0
	// Line 4995, Address: 0x2c7058, Func Offset: 0x308
	// Line 5003, Address: 0x2c7078, Func Offset: 0x328
	// Line 5004, Address: 0x2c709c, Func Offset: 0x34c
	// Line 5005, Address: 0x2c70c4, Func Offset: 0x374
	// Line 5008, Address: 0x2c70e4, Func Offset: 0x394
	// Line 5009, Address: 0x2c7108, Func Offset: 0x3b8
	// Line 5010, Address: 0x2c7130, Func Offset: 0x3e0
	// Line 5013, Address: 0x2c7150, Func Offset: 0x400
	// Line 5014, Address: 0x2c7174, Func Offset: 0x424
	// Line 5015, Address: 0x2c719c, Func Offset: 0x44c
	// Line 5018, Address: 0x2c71bc, Func Offset: 0x46c
	// Line 5019, Address: 0x2c71e0, Func Offset: 0x490
	// Line 5020, Address: 0x2c7208, Func Offset: 0x4b8
	// Line 5023, Address: 0x2c7228, Func Offset: 0x4d8
	// Line 5024, Address: 0x2c724c, Func Offset: 0x4fc
	// Line 5025, Address: 0x2c7274, Func Offset: 0x524
	// Line 5028, Address: 0x2c7298, Func Offset: 0x548
	// Line 5029, Address: 0x2c72c0, Func Offset: 0x570
	// Line 5030, Address: 0x2c72ec, Func Offset: 0x59c
	// Line 5033, Address: 0x2c7310, Func Offset: 0x5c0
	// Line 5034, Address: 0x2c731c, Func Offset: 0x5cc
	// Line 5035, Address: 0x2c7344, Func Offset: 0x5f4
	// Line 5036, Address: 0x2c7370, Func Offset: 0x620
	// Line 5038, Address: 0x2c7394, Func Offset: 0x644
	// Line 5039, Address: 0x2c73bc, Func Offset: 0x66c
	// Line 5040, Address: 0x2c73e4, Func Offset: 0x694
	// Line 5041, Address: 0x2c7428, Func Offset: 0x6d8
	// Line 5042, Address: 0x2c744c, Func Offset: 0x6fc
	// Line 5043, Address: 0x2c7474, Func Offset: 0x724
	// Line 5044, Address: 0x2c74bc, Func Offset: 0x76c
	// Line 5047, Address: 0x2c74e0, Func Offset: 0x790
	// Line 5048, Address: 0x2c7508, Func Offset: 0x7b8
	// Line 5049, Address: 0x2c7530, Func Offset: 0x7e0
	// Line 5052, Address: 0x2c7554, Func Offset: 0x804
	// Line 5053, Address: 0x2c757c, Func Offset: 0x82c
	// Line 5054, Address: 0x2c75a8, Func Offset: 0x858
	// Line 5056, Address: 0x2c75cc, Func Offset: 0x87c
	// Line 5057, Address: 0x2c75d8, Func Offset: 0x888
	// Line 5058, Address: 0x2c7600, Func Offset: 0x8b0
	// Line 5059, Address: 0x2c762c, Func Offset: 0x8dc
	// Line 5061, Address: 0x2c7650, Func Offset: 0x900
	// Line 5062, Address: 0x2c7678, Func Offset: 0x928
	// Line 5063, Address: 0x2c76a0, Func Offset: 0x950
	// Line 5064, Address: 0x2c76e4, Func Offset: 0x994
	// Line 5065, Address: 0x2c7708, Func Offset: 0x9b8
	// Line 5066, Address: 0x2c7730, Func Offset: 0x9e0
	// Line 5067, Address: 0x2c7774, Func Offset: 0xa24
	// Line 5070, Address: 0x2c7798, Func Offset: 0xa48
	// Line 5071, Address: 0x2c77a0, Func Offset: 0xa50
	// Line 5072, Address: 0x2c77ac, Func Offset: 0xa5c
	// Line 5073, Address: 0x2c77bc, Func Offset: 0xa6c
	// Line 5074, Address: 0x2c77c4, Func Offset: 0xa74
	// Line 5076, Address: 0x2c77d0, Func Offset: 0xa80
	// Line 5075, Address: 0x2c77d4, Func Offset: 0xa84
	// Line 5076, Address: 0x2c77d8, Func Offset: 0xa88
	// Line 5075, Address: 0x2c77e8, Func Offset: 0xa98
	// Line 5076, Address: 0x2c77ec, Func Offset: 0xa9c
	// Line 5079, Address: 0x2c77f4, Func Offset: 0xaa4
	// Line 5082, Address: 0x2c77fc, Func Offset: 0xaac
	// Line 5084, Address: 0x2c7804, Func Offset: 0xab4
	// Line 5085, Address: 0x2c7810, Func Offset: 0xac0
	// Line 5086, Address: 0x2c7818, Func Offset: 0xac8
	// Line 5088, Address: 0x2c7820, Func Offset: 0xad0
	// Line 5087, Address: 0x2c7834, Func Offset: 0xae4
	// Line 5088, Address: 0x2c7838, Func Offset: 0xae8
	// Line 5282, Address: 0x2c7840, Func Offset: 0xaf0
	// Line 5284, Address: 0x2c7848, Func Offset: 0xaf8
	// Line 5285, Address: 0x2c784c, Func Offset: 0xafc
	// Func End, Address: 0x2c786c, Func Offset: 0xb1c
}

// 
// Start address: 0x2c7870
int DisplayOptionPlateLevel3(int PortId, int Flag)
{
	unsigned int PolyCol;
	_anon28 ColorBarDef[8];
	_anon13 poly[4];
	_anon32 BotRigt;
	_anon32 TopLeft;
	int ReturnCode;
	int i;
	_anon0* qp;
	_anon8* ap;
	// Line 5302, Address: 0x2c7870, Func Offset: 0
	// Line 5303, Address: 0x2c789c, Func Offset: 0x2c
	// Line 5309, Address: 0x2c78a4, Func Offset: 0x34
	// Line 5306, Address: 0x2c78bc, Func Offset: 0x4c
	// Line 5309, Address: 0x2c78c0, Func Offset: 0x50
	// Line 5317, Address: 0x2c78d0, Func Offset: 0x60
	// Line 5318, Address: 0x2c78d8, Func Offset: 0x68
	// Line 5319, Address: 0x2c7900, Func Offset: 0x90
	// Line 5320, Address: 0x2c790c, Func Offset: 0x9c
	// Line 5352, Address: 0x2c7910, Func Offset: 0xa0
	// Line 5355, Address: 0x2c7918, Func Offset: 0xa8
	// Line 5356, Address: 0x2c793c, Func Offset: 0xcc
	// Line 5357, Address: 0x2c7964, Func Offset: 0xf4
	// Line 5360, Address: 0x2c7984, Func Offset: 0x114
	// Line 5361, Address: 0x2c79a8, Func Offset: 0x138
	// Line 5362, Address: 0x2c79d4, Func Offset: 0x164
	// Line 5365, Address: 0x2c7a0c, Func Offset: 0x19c
	// Line 5366, Address: 0x2c7a34, Func Offset: 0x1c4
	// Line 5367, Address: 0x2c7a5c, Func Offset: 0x1ec
	// Line 5370, Address: 0x2c7a80, Func Offset: 0x210
	// Line 5371, Address: 0x2c7a94, Func Offset: 0x224
	// Line 5372, Address: 0x2c7a98, Func Offset: 0x228
	// Line 5371, Address: 0x2c7aa0, Func Offset: 0x230
	// Line 5375, Address: 0x2c7aac, Func Offset: 0x23c
	// Line 5371, Address: 0x2c7ab0, Func Offset: 0x240
	// Line 5372, Address: 0x2c7abc, Func Offset: 0x24c
	// Line 5375, Address: 0x2c7adc, Func Offset: 0x26c
	// Line 5376, Address: 0x2c7ae4, Func Offset: 0x274
	// Line 5379, Address: 0x2c7af0, Func Offset: 0x280
	// Line 5376, Address: 0x2c7af4, Func Offset: 0x284
	// Line 5377, Address: 0x2c7afc, Func Offset: 0x28c
	// Line 5379, Address: 0x2c7b14, Func Offset: 0x2a4
	// Line 5380, Address: 0x2c7b24, Func Offset: 0x2b4
	// Line 5381, Address: 0x2c7b34, Func Offset: 0x2c4
	// Line 5382, Address: 0x2c7b38, Func Offset: 0x2c8
	// Line 5383, Address: 0x2c7b44, Func Offset: 0x2d4
	// Line 5384, Address: 0x2c7b54, Func Offset: 0x2e4
	// Line 5385, Address: 0x2c7b58, Func Offset: 0x2e8
	// Line 5386, Address: 0x2c7b64, Func Offset: 0x2f4
	// Line 5388, Address: 0x2c7b70, Func Offset: 0x300
	// Line 5389, Address: 0x2c7b80, Func Offset: 0x310
	// Line 5390, Address: 0x2c7b8c, Func Offset: 0x31c
	// Line 5389, Address: 0x2c7b90, Func Offset: 0x320
	// Line 5390, Address: 0x2c7b94, Func Offset: 0x324
	// Line 5389, Address: 0x2c7b98, Func Offset: 0x328
	// Line 5390, Address: 0x2c7b9c, Func Offset: 0x32c
	// Line 5391, Address: 0x2c7ba4, Func Offset: 0x334
	// Line 5390, Address: 0x2c7bac, Func Offset: 0x33c
	// Line 5391, Address: 0x2c7bb4, Func Offset: 0x344
	// Line 5394, Address: 0x2c7bbc, Func Offset: 0x34c
	// Line 5397, Address: 0x2c7be4, Func Offset: 0x374
	// Line 5398, Address: 0x2c7bec, Func Offset: 0x37c
	// Line 5397, Address: 0x2c7bf8, Func Offset: 0x388
	// Line 5398, Address: 0x2c7bfc, Func Offset: 0x38c
	// Line 5399, Address: 0x2c7c08, Func Offset: 0x398
	// Line 5400, Address: 0x2c7c0c, Func Offset: 0x39c
	// Line 5399, Address: 0x2c7c14, Func Offset: 0x3a4
	// Line 5401, Address: 0x2c7c1c, Func Offset: 0x3ac
	// Line 5402, Address: 0x2c7c20, Func Offset: 0x3b0
	// Line 5399, Address: 0x2c7c24, Func Offset: 0x3b4
	// Line 5400, Address: 0x2c7c2c, Func Offset: 0x3bc
	// Line 5402, Address: 0x2c7c38, Func Offset: 0x3c8
	// Line 5400, Address: 0x2c7c3c, Func Offset: 0x3cc
	// Line 5401, Address: 0x2c7c48, Func Offset: 0x3d8
	// Line 5402, Address: 0x2c7c58, Func Offset: 0x3e8
	// Line 5405, Address: 0x2c7c64, Func Offset: 0x3f4
	// Line 5406, Address: 0x2c7c6c, Func Offset: 0x3fc
	// Line 5407, Address: 0x2c7c74, Func Offset: 0x404
	// Line 5408, Address: 0x2c7c7c, Func Offset: 0x40c
	// Line 5409, Address: 0x2c7c88, Func Offset: 0x418
	// Line 5411, Address: 0x2c7c90, Func Offset: 0x420
	// Line 5407, Address: 0x2c7ca4, Func Offset: 0x434
	// Line 5410, Address: 0x2c7ca8, Func Offset: 0x438
	// Line 5411, Address: 0x2c7cac, Func Offset: 0x43c
	// Line 5413, Address: 0x2c7cb4, Func Offset: 0x444
	// Line 5415, Address: 0x2c7cbc, Func Offset: 0x44c
	// Line 5416, Address: 0x2c7cc0, Func Offset: 0x450
	// Func End, Address: 0x2c7cf0, Func Offset: 0x480
}

// 
// Start address: 0x2c7cf0
int DisplayOptionPlate(int PortId, int Level, int Flag)
{
	// Line 5429, Address: 0x2c7cf0, Func Offset: 0
	// Line 5430, Address: 0x2c7cf4, Func Offset: 0x4
	// Line 5432, Address: 0x2c7d28, Func Offset: 0x38
	// Line 5435, Address: 0x2c7d3c, Func Offset: 0x4c
	// Line 5438, Address: 0x2c7d50, Func Offset: 0x60
	// Line 5441, Address: 0x2c7d64, Func Offset: 0x74
	// Line 5444, Address: 0x2c7d74, Func Offset: 0x84
	// Line 5446, Address: 0x2c7d78, Func Offset: 0x88
	// Func End, Address: 0x2c7d84, Func Offset: 0x94
}*/

// 
// Start address: 0x2c7d90
int Adv_GameOptionScreen()
{
	int ReturnCode;
	//_anon8* ap;
	int SaveCheck;
	int ulState;
	// Line 5465, Address: 0x2c7d90, Func Offset: 0
	// Line 5466, Address: 0x2c7da0, Func Offset: 0x10
	// Line 5476, Address: 0x2c7da8, Func Offset: 0x18
	// Line 5477, Address: 0x2c7db4, Func Offset: 0x24
	// Line 5478, Address: 0x2c7dbc, Func Offset: 0x2c
	// Line 5479, Address: 0x2c7dc8, Func Offset: 0x38
	// Line 5481, Address: 0x2c7dd0, Func Offset: 0x40
	// Line 5483, Address: 0x2c7ddc, Func Offset: 0x4c
	// Line 5485, Address: 0x2c7e08, Func Offset: 0x78
	// Line 5486, Address: 0x2c7e10, Func Offset: 0x80
	// Line 5492, Address: 0x2c7e18, Func Offset: 0x88
	// Line 5493, Address: 0x2c7e28, Func Offset: 0x98
	// Line 5495, Address: 0x2c7e30, Func Offset: 0xa0
	// Line 5496, Address: 0x2c7e54, Func Offset: 0xc4
	// Line 5497, Address: 0x2c7e6c, Func Offset: 0xdc
	// Line 5498, Address: 0x2c7e70, Func Offset: 0xe0
	// Line 5500, Address: 0x2c7e78, Func Offset: 0xe8
	// Line 5501, Address: 0x2c7e84, Func Offset: 0xf4
	// Line 5503, Address: 0x2c7e8c, Func Offset: 0xfc
	// Line 5504, Address: 0x2c7e94, Func Offset: 0x104
	// Line 5505, Address: 0x2c7e9c, Func Offset: 0x10c
	// Line 5506, Address: 0x2c7ea0, Func Offset: 0x110
	// Line 5508, Address: 0x2c7ea8, Func Offset: 0x118
	// Line 5509, Address: 0x2c7eb4, Func Offset: 0x124
	// Line 5510, Address: 0x2c7eb8, Func Offset: 0x128
	// Line 5512, Address: 0x2c7ec0, Func Offset: 0x130
	// Line 5513, Address: 0x2c7ed4, Func Offset: 0x144
	// Line 5515, Address: 0x2c7edc, Func Offset: 0x14c
	// Line 5516, Address: 0x2c7ee4, Func Offset: 0x154
	// Line 5517, Address: 0x2c7ee8, Func Offset: 0x158
	// Line 5519, Address: 0x2c7ef0, Func Offset: 0x160
	// Line 5520, Address: 0x2c7ef8, Func Offset: 0x168
	// Line 5521, Address: 0x2c7efc, Func Offset: 0x16c
	// Line 5523, Address: 0x2c7f04, Func Offset: 0x174
	// Line 5524, Address: 0x2c7f20, Func Offset: 0x190
	// Line 5525, Address: 0x2c7f3c, Func Offset: 0x1ac
	// Line 5526, Address: 0x2c7f58, Func Offset: 0x1c8
	// Line 5527, Address: 0x2c7f74, Func Offset: 0x1e4
	// Line 5528, Address: 0x2c7f80, Func Offset: 0x1f0
	// Line 5527, Address: 0x2c7f88, Func Offset: 0x1f8
	// Line 5528, Address: 0x2c7f8c, Func Offset: 0x1fc
	// Line 5530, Address: 0x2c7f94, Func Offset: 0x204
	// Line 5531, Address: 0x2c7fa4, Func Offset: 0x214
	// Line 5532, Address: 0x2c7fb0, Func Offset: 0x220
	// Line 5534, Address: 0x2c7fbc, Func Offset: 0x22c
	// Line 5535, Address: 0x2c7fc0, Func Offset: 0x230
	// Line 5537, Address: 0x2c7fc8, Func Offset: 0x238
	// Line 5538, Address: 0x2c7fd8, Func Offset: 0x248
	// Line 5539, Address: 0x2c7fe4, Func Offset: 0x254
	// Line 5540, Address: 0x2c7ff4, Func Offset: 0x264
	// Line 5542, Address: 0x2c7ff8, Func Offset: 0x268
	// Line 5544, Address: 0x2c8000, Func Offset: 0x270
	// Line 5545, Address: 0x2c8008, Func Offset: 0x278
	// Line 5546, Address: 0x2c801c, Func Offset: 0x28c
	// Line 5547, Address: 0x2c8028, Func Offset: 0x298
	// Line 5548, Address: 0x2c8038, Func Offset: 0x2a8
	// Line 5550, Address: 0x2c8048, Func Offset: 0x2b8
	// Line 5549, Address: 0x2c804c, Func Offset: 0x2bc
	// Line 5551, Address: 0x2c8050, Func Offset: 0x2c0
	// Line 5552, Address: 0x2c8058, Func Offset: 0x2c8
	// Line 5554, Address: 0x2c8060, Func Offset: 0x2d0
	// Line 5557, Address: 0x2c80b8, Func Offset: 0x328
	// Line 5564, Address: 0x2c80c0, Func Offset: 0x330
	// Line 5565, Address: 0x2c80d0, Func Offset: 0x340
	// Line 5566, Address: 0x2c80d8, Func Offset: 0x348
	// Line 5569, Address: 0x2c80dc, Func Offset: 0x34c
	// Line 5571, Address: 0x2c80e4, Func Offset: 0x354
	// Line 5572, Address: 0x2c80f4, Func Offset: 0x364
	// Line 5573, Address: 0x2c8100, Func Offset: 0x370
	// Line 5575, Address: 0x2c8120, Func Offset: 0x390
	// Line 5577, Address: 0x2c8158, Func Offset: 0x3c8
	// Line 5583, Address: 0x2c8164, Func Offset: 0x3d4
	// Line 5585, Address: 0x2c816c, Func Offset: 0x3dc
	// Line 5588, Address: 0x2c8178, Func Offset: 0x3e8
	// Line 5589, Address: 0x2c8184, Func Offset: 0x3f4
	// Line 5590, Address: 0x2c8194, Func Offset: 0x404
	// Line 5591, Address: 0x2c8198, Func Offset: 0x408
	// Line 5590, Address: 0x2c819c, Func Offset: 0x40c
	// Line 5592, Address: 0x2c81a0, Func Offset: 0x410
	// Line 5593, Address: 0x2c81a8, Func Offset: 0x418
	// Line 5598, Address: 0x2c81ac, Func Offset: 0x41c
	// Line 5594, Address: 0x2c81b0, Func Offset: 0x420
	// Line 5601, Address: 0x2c81b4, Func Offset: 0x424
	// Line 5602, Address: 0x2c81bc, Func Offset: 0x42c
	// Line 5603, Address: 0x2c81cc, Func Offset: 0x43c
	// Line 5605, Address: 0x2c81d8, Func Offset: 0x448
	// Line 5607, Address: 0x2c81e0, Func Offset: 0x450
	// Line 5608, Address: 0x2c81e8, Func Offset: 0x458
	// Line 5609, Address: 0x2c81ec, Func Offset: 0x45c
	// Line 5645, Address: 0x2c81f4, Func Offset: 0x464
	// Line 5647, Address: 0x2c8200, Func Offset: 0x470
	// Line 5651, Address: 0x2c8224, Func Offset: 0x494
	// Line 5652, Address: 0x2c8234, Func Offset: 0x4a4
	// Line 5651, Address: 0x2c8240, Func Offset: 0x4b0
	// Line 5652, Address: 0x2c8244, Func Offset: 0x4b4
	// Line 5654, Address: 0x2c825c, Func Offset: 0x4cc
	// Line 5653, Address: 0x2c8264, Func Offset: 0x4d4
	// Line 5655, Address: 0x2c826c, Func Offset: 0x4dc
	// Line 5657, Address: 0x2c8274, Func Offset: 0x4e4
	// Line 5658, Address: 0x2c8288, Func Offset: 0x4f8
	// Line 5660, Address: 0x2c829c, Func Offset: 0x50c
	// Line 5661, Address: 0x2c82a4, Func Offset: 0x514
	// Line 5662, Address: 0x2c82a8, Func Offset: 0x518
	// Line 5661, Address: 0x2c82ac, Func Offset: 0x51c
	// Line 5663, Address: 0x2c82b0, Func Offset: 0x520
	// Line 5664, Address: 0x2c82b8, Func Offset: 0x528
	// Line 5666, Address: 0x2c82c4, Func Offset: 0x534
	// Line 5667, Address: 0x2c82cc, Func Offset: 0x53c
	// Line 5668, Address: 0x2c82d0, Func Offset: 0x540
	// Line 5667, Address: 0x2c82d4, Func Offset: 0x544
	// Line 5672, Address: 0x2c82d8, Func Offset: 0x548
	// Line 5675, Address: 0x2c82e0, Func Offset: 0x550
	// Line 5677, Address: 0x2c82e4, Func Offset: 0x554
	// Line 5730, Address: 0x2c82ec, Func Offset: 0x55c
	// Line 5731, Address: 0x2c82f4, Func Offset: 0x564
	// Line 5732, Address: 0x2c82fc, Func Offset: 0x56c
	// Line 5733, Address: 0x2c8304, Func Offset: 0x574
	// Line 5735, Address: 0x2c830c, Func Offset: 0x57c
	// Line 5736, Address: 0x2c8318, Func Offset: 0x588
	// Line 5737, Address: 0x2c8320, Func Offset: 0x590
	// Line 5738, Address: 0x2c8324, Func Offset: 0x594
	// Line 5739, Address: 0x2c832c, Func Offset: 0x59c
	// Line 5740, Address: 0x2c8334, Func Offset: 0x5a4
	// Line 5742, Address: 0x2c8338, Func Offset: 0x5a8
	// Line 5744, Address: 0x2c8340, Func Offset: 0x5b0
	// Line 5745, Address: 0x2c8348, Func Offset: 0x5b8
	// Line 5746, Address: 0x2c834c, Func Offset: 0x5bc
	// Line 5748, Address: 0x2c8354, Func Offset: 0x5c4
	// Line 5749, Address: 0x2c835c, Func Offset: 0x5cc
	// Line 5750, Address: 0x2c8360, Func Offset: 0x5d0
	// Line 5752, Address: 0x2c8368, Func Offset: 0x5d8
	// Line 5756, Address: 0x2c8370, Func Offset: 0x5e0
	// Line 5757, Address: 0x2c8380, Func Offset: 0x5f0
	// Line 5758, Address: 0x2c838c, Func Offset: 0x5fc
	// Line 5759, Address: 0x2c8394, Func Offset: 0x604
	// Line 5760, Address: 0x2c839c, Func Offset: 0x60c
	// Line 5762, Address: 0x2c83a4, Func Offset: 0x614
	// Line 5763, Address: 0x2c83ac, Func Offset: 0x61c
	// Line 5764, Address: 0x2c83b4, Func Offset: 0x624
	// Line 5765, Address: 0x2c83b8, Func Offset: 0x628
	// Line 5767, Address: 0x2c83c0, Func Offset: 0x630
	// Line 5766, Address: 0x2c83c4, Func Offset: 0x634
	// Line 5770, Address: 0x2c83c8, Func Offset: 0x638
	// Line 5771, Address: 0x2c83cc, Func Offset: 0x63c
	// Func End, Address: 0x2c83e0, Func Offset: 0x650
	scePrintf("Adv_GameOptionScreen - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2c83e0
int Adv_ChangeDiscScreen()
{
	//_anon8* ap;
	// Line 5818, Address: 0x2c83e0, Func Offset: 0
	// Line 5819, Address: 0x2c83ec, Func Offset: 0xc
	// Line 5896, Address: 0x2c83f0, Func Offset: 0x10
	// Line 5898, Address: 0x2c83f8, Func Offset: 0x18
	// Line 5899, Address: 0x2c8408, Func Offset: 0x28
	// Line 5898, Address: 0x2c8410, Func Offset: 0x30
	// Line 5899, Address: 0x2c8414, Func Offset: 0x34
	// Line 5898, Address: 0x2c8418, Func Offset: 0x38
	// Line 5899, Address: 0x2c8420, Func Offset: 0x40
	// Line 5900, Address: 0x2c8428, Func Offset: 0x48
	// Line 5899, Address: 0x2c842c, Func Offset: 0x4c
	// Line 5900, Address: 0x2c8434, Func Offset: 0x54
	// Line 5901, Address: 0x2c844c, Func Offset: 0x6c
	// Line 5902, Address: 0x2c8454, Func Offset: 0x74
	// Line 5903, Address: 0x2c845c, Func Offset: 0x7c
	// Line 5905, Address: 0x2c846c, Func Offset: 0x8c
	// Line 5907, Address: 0x2c8470, Func Offset: 0x90
	// Line 5971, Address: 0x2c8478, Func Offset: 0x98
	// Line 5972, Address: 0x2c8488, Func Offset: 0xa8
	// Line 5971, Address: 0x2c8490, Func Offset: 0xb0
	// Line 5972, Address: 0x2c8494, Func Offset: 0xb4
	// Line 5971, Address: 0x2c8498, Func Offset: 0xb8
	// Line 5972, Address: 0x2c84a0, Func Offset: 0xc0
	// Line 5973, Address: 0x2c84b0, Func Offset: 0xd0
	// Line 5974, Address: 0x2c84b4, Func Offset: 0xd4
	// Line 5979, Address: 0x2c84b8, Func Offset: 0xd8
	// Line 5980, Address: 0x2c84bc, Func Offset: 0xdc
	// Func End, Address: 0x2c84cc, Func Offset: 0xec
	scePrintf("Adv_ChangeDiscScreen - UNIMPLEMENTED!\n");
}

// 100% matching! 
int Adv_SoundMuseum()
{ 
    return 1;
} 
