#include "adv.h"
#include "adxwrap.h"
#include "effect.h"
#include "message.h"
#include "ps2_dummy.h"
#include "ps2_MemoryCard.h"
#include "ps2_NaDraw.h"
#include "ps2_sg_maloc.h"
#include "ps2_sg_sycfg.h"
#include "ps2_SystemLoadScreen.h"
#include "ps2_SystemSaveScreen.h"
#include "ps2_texture.h"
#include "pwksub.h"
#include "sdc.h"
#include "sdfunc.h"
#include "padman.h"
#include "vibman.h"
#include "main.h"

#include <string.h>

/*unsigned char SaveLoadMessage[10956];*/
OPTION OptionDef[7] = { { 0, 1, 0, 0, 0,  0,  0, 0, 0 },
                        { 0, 2, 0, 0, 0,  1,  0, 0, 1 },
			            { 0, 0, 0, 2, 0,  2,  0, 0, 0 },
		                { 0, 0, 0, 0, 0,  3,  0, 0, 0 },
                        { 0, 1, 0, 0, 0,  0,  0, 0, 0 },
                        { 0, 0, 0, 0, 0,  0,  0, 0, 0 },
			            { 0, 0, 0, 0, 0, -1, -1, 0, 0 } };
int AdvFirstInitFlag;
ADV_WORK AdvWork;
QUAD Qtex[16];
NJS_TEXINFO AdvTexInfo[2][8];
NJS_TEXNAME AdvTexName[2][8];
NJS_TEXLIST AdvTexList[2] = { {AdvTexName[0], 8}, {AdvTexName[1], 8} };
char AdvTexPalBank[2][8];
ADV_VM_MSG AdvVmMsgDef[21] = {{-1.0f, 32.0f, 23, 21, 1}, {-1.0f, 176.0f, 25, -1, 0}, {-1.0f, 32.0f, 33, 21, 1}, {-1.0f, 208.0f, 30, 22, 1}, {-1.0f, 224.0f, 27, 22, 1}, {-1.0f, 32.0f, 24, 22, 1}, {-1.0f, 416.0f, 28, -1, 0}, {-1.0f, 32.0f, 24, 21, 1}, {-1.0f, 224.0f, 31, 22, 1}, {-1.0f, 224.0f, 32, 22, 1}, {-1.0f, 32.0f, 23, 22, 1}, {-1.0f, 32.0f, 33, 20, 1}, {-1.0f, 32.0f, 33, 22, 1}, {-1.0f, 32.0f, 34, 20, 1}, {-1.0f, 32.0f, 35, 20, 1}, {-1.0f, 32.0f, 36, 20, 1}, {-1.0f, 32.0f, 37, 20, 1}, {-1.0f, 32.0f, 38, 20, 1}, {-1.0f, 32.0f, 39, 20, 1}, {-1.0f, 32.0f, 40, 20, 1}, {-1.0f, 32.0f, 41, 20, 1}};
SYSLOAD_SCREEN* pSysLoad;
SYSLOAD_SCREEN SysLoad;
/*float ColorBarSizeY;
float RedLinePosY;
unsigned int ColorBarBright;*/
SYSSAVE_SCREEN* pSysSave;
SYSSAVE_SCREEN SysSave;

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
void AdvPushRoomTexture(int param) // parameter is not present on the debugging symbols
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
    TIM2_PICTUREHEADER* pPichd;
    unsigned int GlobalIndex;
    
    ((TIM2_PICTUREHEADER_EX*)pp)->PictFormat = 0; 
    
    GlobalIndex = ((TIM2_PICTUREHEADER_EX*)pp)->Gindex; 
    
    pPichd = (TIM2_PICTUREHEADER*)&((unsigned char*)pp)[128];
    
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

    if (strncmp((char*)&pPvp->ppStrPvpl, "PVPL", 4) != 0)
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
        ((TIM2_PICTUREHEADER_EX*)Ps2_current_texmemlist->texinfo.texsurface.pSurface)->ClutChange |= 0x8000; 
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

// 89.93% matching
void DisplayGameModePlate(int Cursor, int CursorMax, float FadeRate, int Flag)
{
    ADV_WORK* ap = (ADV_WORK*)&AdvWork; 
    QUAD* qp; 
    int i; 
    unsigned int Alpha; 
    int DivTbl[4] = { 2, 2, 2, 2 }; 
    float PosYDef[2][4] = { { 288.0f, 320.0f, 352.0f, 384.0f }, { 272.0f, 304.0f, 336.0f, 368.0f } }; 
    float VDef[2][4] = { { 64.0f, 96.0f, 128.0f, 224.0f }, { 64.0f, 96.0f, 224.0f, 128.0f } }; 

    DivTbl[Cursor] = (ap->ExtraFlag == 0) ? 1 : 0;
    
    qp = &Qtex[1]; 
    
    SetQuadPos(64.0f, PosYDef[0][Cursor], 513.0f, 33.0f, qp);
    SetQuadUv2(0, VDef[0][Cursor], 513.0f, 33.0f, 1, qp);
    
    SetQuadPos(64.0f, PosYDef[0][Cursor + 1], 513.0f, 33.0f, &qp[1]);
    SetQuadUv2(0, VDef[0][Cursor + 1], 513.0f, 33.0f, 1, &qp[1]);
    
    SetQuadPos(64.0f, PosYDef[0][Cursor + 2], 513.0f, 33.0f, &qp[2]);
    SetQuadUv2(0, VDef[0][Cursor + 2], 513.0f, 33.0f, 1, &qp[2]);
    
    SetQuadPos(64.0f, PosYDef[0][Cursor + 3], 513.0f, 33.0f, &qp[3]);
    SetQuadUv2(0, VDef[0][Cursor + 3], 513.0f, 33.0f, 1, &qp[3]);

    for (i = 0; i < CursorMax; i++) 
    {
        Alpha = FadeRate;
        
        if (DivTbl[i] == 1) 
        {
            Alpha += (unsigned int)ap->FlushCount2;
            
            Alpha <<= 24;
            
            if (Flag == 0) 
            {
                Alpha = 0xFF000000;
            }
            
            AdvEasyDrawTextureS(1, Alpha | ap->FontBaseColor, &Qtex[i + 1], 0.5f, 1, FadeRate);
        } 
        else 
        {
            Alpha <<= 24;
            
            if (Flag == 0)
            {
                Alpha = 0xFF000000;
            }
            
            AdvEasyDrawTextureS(1, Alpha | 0x7F7F7F, &Qtex[i + 1], 0.5f, 1, FadeRate);
        }
    } 

    FlushPlate();
    
    DisplayTitleBg();
}

// 94.78% matching
void DisplayNewGamePlate(int Cursor, float FadeRate, int Flag)
{
    ADV_WORK* ap = &AdvWork; 
    QUAD* qp; 
    int i; 
    unsigned int Alpha; 
    int DivTbl[3] = { 2, 2, 2 }; 

    DivTbl[Cursor] = 1;
    
    qp = &Qtex[1];
    
    SetQuadPos(224.0f, 304.0f, 193.0f, 33.0f, qp);
    SetQuadUv2(0, 320.0f, 193.0f, 33.0f, 1, qp);
    
    SetQuadPos(224.0f, 336.0f, 193.0f, 33.0f, &qp[1]);
    SetQuadUv2(0, 288.0f, 193.0f, 33.0f, 1, &qp[1]);
    
    SetQuadPos(224.0f, 368.0f, 193.0f, 33.0f, &qp[2]);
    SetQuadUv2(0, 256.0f, 193.0f, 33.0f, 1, &qp[2]);
    
    SetQuadPos(64.0f, 272.0f, 513.0f, 33.0f, &qp[3]);
    SetQuadUv2(0, 160.0f, 513.0f, 33.0f, 1, &qp[3]);
    
    for (i = 0; i < 3; i++)
    {
        Alpha = FadeRate;
        
        if (DivTbl[i] == 1) 
        {
            Alpha += (unsigned int)ap->FlushCount2;
                       
            Alpha <<= 24;
            
            if (Flag == 0) 
            {
                Alpha = 0xFF000000;
            }
            
            AdvEasyDrawTextureS(1, Alpha | ap->FontBaseColor, &Qtex[i + 1], 0.5f, 1, FadeRate);
        } 
        else 
        {
            Alpha <<= 24;
            
            if (Flag == 0) 
            {
                Alpha = 0xFF000000;
            }
            
            AdvEasyDrawTextureS(1, Alpha | 0x7F7F7F, &Qtex[i + 1], 0.5f, 1, FadeRate);
        }
    } 
   
    AdvEasyDrawTextureS(1, ((unsigned int)FadeRate << 24) | 0xFFFFFF, &Qtex[4], 0.5f, 1, FadeRate);
    
    FlushPlate();
    
    DisplayTitleBg();
}

// 94.18% matching
void DisplayExtraGamePlate(int Cursor, float FadeRate, int Flag)
{
    ADV_WORK* ap = &AdvWork; 
    QUAD* qp; 
    int i; 
    unsigned int Alpha; 
    int DivTbl[2] = { 2, 2 }; 

    DivTbl[Cursor] = 1;
    
    qp = &Qtex[1];
    
    SetQuadPos(64.0f, 352.0f, 256.0f, 33.0f, qp);
    SetQuadUv2(0, 352.0f, 256.0f, 33.0f, 1, qp);
    
    SetQuadPos(320.0f, 352.0f, 256.0f, 33.0f, &qp[1]);
    SetQuadUv2(0, 384.0f, 256.0f, 33.0f, 1, &qp[1]);
    
    SetQuadPos(64.0f, 288.0f, 512.0f, 33.0f, &qp[2]);
    SetQuadUv2(0, 160.0f, 512.0f, 33.0f, 1, &qp[2]);
    
    for (i = 0; i < 2; i++)
    {
        Alpha = FadeRate;
        
        if (DivTbl[i] == 1) 
        {
            Alpha += (unsigned int)ap->FlushCount2;
                       
            Alpha <<= 24;
            
            if (Flag == 0) 
            {
                Alpha = 0xFF000000;
            }
            
            AdvEasyDrawTextureS(1, Alpha | ap->FontBaseColor, &Qtex[i + 1], 0.5f, 1, FadeRate);
        } 
        else 
        {
            Alpha <<= 24;
            
            if (Flag == 0) 
            {
                Alpha = 0xFF000000;
            }
            
            AdvEasyDrawTextureS(1, Alpha | 0x7F7F7F, &Qtex[i + 1], 0.5f, 1, FadeRate);
        }
    } 
   
    AdvEasyDrawTextureS(1, ((unsigned int)FadeRate << 24) | 0xFFFFFF, &Qtex[3], 0.5f, 1, FadeRate);
    
    FlushPlate();
    
    DisplayTitleBg();
}

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

// 100% matching!
int CheckButton(int Level, int Flag, int MaxFlag) 
{
    ADV_WORK* ap = (ADV_WORK*)&AdvWork; 
    unsigned int DownKey[3] = { 0x1000, 0x1000, 0x8000 }; 
    unsigned int UpKey[3] = { 0x4000, 0x4000, 0x2000 }; 
    unsigned char NewGameDef[3] = { 0, 1, 2 }; 
    unsigned char ExGameDef[2] = { 3, 3 }; 
    int CancelNextMode[3] = { 5, 8, 8 }; 
    int CancelMode[3] = { 10, 13, 10 }; 
    int ConnectFlag; 

    ConnectFlag = 1;
    
    CheckAdvScreenSaverStopKey(ap->PortId); 
    
    if ((Level == 0) && (ap->Cursor[Level] == 0) && (Flag == 0)) 
    {
        ap->Cursor[Level] = 1;
        
        ConnectFlag = 0; 
    }
    
    if (ConnectFlag != 0) 
    {
        if ((Pad[ap->PortId].Rept & DownKey[Level])) 
        {
            while (TRUE) 
            {
                ap->Cursor[Level]--;
                
                if ((ap->CursorFlag[Level][ap->Cursor[Level]] != 0) && ((Level == 0) && (ap->Cursor[Level] == 0) && (Flag == 0))) 
                {
                    ap->Cursor[Level] = 1;
                }
                
                if (ap->Cursor[Level] < 0)
                {
                    if (MaxFlag != 0)
                    {
                        ap->Cursor[Level] = ap->CursorMax[Level] - 1;
                    } 
                    else 
                    {
                        ap->Cursor[Level] = 0;
                    }
                }
                
                if ((ap->CursorFlag[Level][ap->Cursor[Level]] != 0) && ((Level != 0) || (ap->Cursor[Level] != 0) || (Flag != 0))) 
                {
                    break;
                }
            }
            
            CallSystemSe(0, 2);
        }
        else if ((Pad[ap->PortId].Rept & UpKey[Level]))
        {
            while (TRUE) 
            {
                ap->Cursor[Level]++;
                
                if ((ap->CursorFlag[Level][ap->Cursor[Level]] != 0) && ((Level == 0) && (ap->Cursor[Level] == 0) && (Flag == 0))) 
                {
                    ap->Cursor[Level] = 1;
                }
                
                if (ap->Cursor[Level] > (ap->CursorMax[Level] - 1)) 
                {
                    if (MaxFlag != 0)
                    {
                        ap->Cursor[Level] = 0;
                    } 
                    else
                    {
                        ap->Cursor[Level] = ap->CursorMax[Level] - 1;
                    }
                }
                
                if ((ap->CursorFlag[Level][ap->Cursor[Level]] != 0) && ((Level != 0) || (ap->Cursor[Level] != 0) || (Flag != 0))) 
                {
                    break;
                }
            }
            
            CallSystemSe(0, 2);
        }
    }
    
    if (((Pad[ap->PortId].press & 0x800)) || ((Pad[ap->PortId].press & AdvGetOkButton()))) 
    {
        switch (Level) 
        {                            
        case 0:
            switch (ap->ModeCommandId[ap->Cursor[Level]]) 
            {                 
            case 0:                            
                if (FindFirstVmDrive() < 0) 
                { 
                    CallSystemSe(0, 1);
                } 
                else 
                {
                    ap->AppMode = 1;
                
                    ap->FromTitle = 1;
                   
                    ap->LastLevel = Level;
                    
                    TitleCall(ap->PortId, 3);
                }
                
                break;
            case 1:                             
                ap->AppMode = 1;
                
                ap->FromTitle = 0;
                
                ap->LastLevel = Level;
                
                sys->gm_mode = 0;
                
                TitleCall(ap->PortId, 2);
                break;
            case 2:                                
                ap->AppMode = 0;
                
                ap->FromTitle = 2;
                
                ap->LastLevel = Level;
                
                ap->NextReturnCode = 4;
                
                ap->Mode = 17;
                
                CallSystemSe(0, 3);
                
                RequestAdvFade(3, GetSamurai(50));
                break;
            case 3:                           
                ap->AppMode = 1;
                
                ap->FromTitle = 3;
                
                ap->LastLevel = Level;
                
                sys->gm_mode = 3;
                
                TitleCall(ap->PortId, 6);
                break;
            }
            
            break;
        case 1:
            sys->gm_mode = NewGameDef[ap->Cursor[Level]];
            
            TitleCall(ap->PortId, 2);
            
            ap->LastLevel = Level;
            break;
        case 2:
            sys->gm_mode = ExGameDef[ap->Cursor[Level]];
            
            TitleCall(ap->PortId, 2);
            
            ap->LastLevel = Level;
            break;
        }
    }
    else if ((Pad[ap->PortId].press & AdvGetCancelButton())) 
    {
        ap->NextMode = CancelNextMode[Level];
        ap->Mode = CancelMode[Level];
        
        CallSystemSe(0, 0); 
    }
        
    return -1;
}

// 100% matching! 
int CheckStartButton() 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
        
    if ((Pad[temp->PortId].press & 0x800))
    { 
        CallSystemSeBasic(3, 0, 0); 
        
        StopAdvScreenSaver(0); 
        
        return 1;
    }
    
    return 0; 
} 

// 99.79% matching
int Adv_BioCvTitle() 
{ 
    ADV_WORK* ap;
    int ReturnCode;
	int i;
	int j;
	int TitleSoftResetFlag;
    unsigned int McCrntResult;
    NJS_POLYGON_VTX poly[4];
    unsigned int a;
	static unsigned int ulFrame;
	static unsigned int McPrevResult;

    ap = (ADV_WORK*)&AdvWork;

    ReturnCode = 0; 
    
    TitleSoftResetFlag = 0; 
    
    ap->PortId = AdvGetCurrentPort();
    
    ExecuteAdvFade(); 
    ExecuteAdvScreenSaver(); 
    
    AdvCheckSoftReset(0); 
    
    if ((ap->DepthLevel != 0) && (CheckSoftResetKeyFlag(-1) != 0)) 
    { 
        TitleSoftResetFlag = 1; 
        
        ap->Mode = -1; 
    }
    
    switch (ap->Mode) 
    { 
    case 0:
        RequestAllStopSoundEx(1, 0, 0); 
        
        SetEventVibrationMode(0); 
        
        ResetAdvSystem(); 
        
        ap->AppMode = 0; 
         
        for (i = 0; i < 4; i++) 
        { 
            for (j = 0; j < 4; j++) 
            { 
                ap->CursorFlag[i][j] = 1; 
            } 
        } 
        
        ap->Cursor[1] = 0; 
        ap->Cursor[2] = 0; 
        
        ap->CursorMax[1] = 3; 
        ap->CursorMax[2] = 2; 
    
        if (((sys->ss_flg & 0x100000)) || ((sys->ss_flg & 0x1000))) 
        {
            ap->FromTitle = 0; 
        }
        
        sys->ss_flg &= ~0x100000; 
        sys->ss_flg &= ~0x1000; 

        if ((sys->ssd_flg & 0x1)) 
        { 
            ap->ExtraFlag = 1; 
        }
        
        if (ap->ExtraFlag != 0)
        { 
            ap->CursorMax[0] = 4; 
            
            ap->ModeCommandId[0] = 0; 
            ap->ModeCommandId[1] = 1; 
            ap->ModeCommandId[2] = 3; 
            ap->ModeCommandId[3] = 2; 

            switch (ap->FromTitle) 
            { 
            case 0:
            case 1:
                ap->Cursor[0] = 0; 
                break;
            case 3:
                ap->Cursor[0] = 2; 
                break;
            case 2:
                ap->Cursor[0] = 3; 
                break;
            }
        } 
        else 
        {
            ap->CursorMax[0] = 3; 
            
            ap->ModeCommandId[0] = 0; 
            ap->ModeCommandId[1] = 1; 
            ap->ModeCommandId[2] = 2; 
            ap->ModeCommandId[3] = 3; 

            switch (ap->FromTitle)
            { 
            case 0:
            case 1:
            case 3:
                ap->Cursor[0] = 0; 
                break;
            case 2:
                ap->Cursor[0] = 2; 
                break;
            }
        }
 
        ap->Mode = 1; 
        break; 
    case 1:
        sys->ss_flg |= 0x20000; 
        
        ClearSoftResetKeyFlag(ap->PortId); 
        
        Pad[ap->PortId].Flag = 1; 
        
        RequestAdvInsideFileEx(2, 0); 
        
        ap->Mode = 2; 
        break; 
    case 2:
        CheckReadEndAdvInsideFile2(3); 
        break; 
    case 3:
        RequestAllStopSoundEx(0, 1, 0); 

        AdvEasySetupTextureBasic(AdvGetResourcePtr(ap->ptr[0], 0), 0, 0); 
        AdvEasySetupTextureBasic(AdvGetResourcePtr(ap->ptr[0], 2), 0, 1); 
        
        AdvEasyTransTextureBasic(0, 2, 0); 
        
        AdvTransShadowPalette(); 
        
        RequestAdvFade(2, GetSamurai(50));
        
        ap->Mode = 4; 
        break; 
    case 4:
        if (CheckAdvFade() == 0)
        { 
            switch (ap->FromTitle) 
            { 
            case 0:
                ap->Mode = 5; 
                break; 
            case 1:
            case 3:
            case 2:
                ap->FlushCount = 0; 
                ap->FlushSpeed = 32.0f; 
                
                ap->Mode = 8; 
                break;
            }
        }
        
        DisplayTitleBg(); 
        break; 
    case 5:
        ap->DepthLevel = 0;
        
        sys->ss_flg &= ~0x20000; 
        
        Pad[ap->PortId].Flag = 0; 
        
        ap->Timer = 900.0f; 
        
        ap->FlushCount = 0;
        ap->FlushSpeed = 32.0f; 
        
        DisplayPressStartPlate(ap->FlushCount); 
        
        ap->Mode = 6; 
        break; 
    case 6:
        ap->FlushCount += ap->FlushSpeed; 
        
        if (ap->FlushSpeed < 0) 
        {
            if (ap->FlushCount <= 128.0f)
            { 
                ap->FlushCount = 128.0f; 
                ap->FlushSpeed = 4.0f; 
            }
        } 
        else if (ap->FlushCount >= 255.0f) 
        { 
            ap->FlushCount = 255.0f; 
            ap->FlushSpeed = -4.0f; 
        } 

        ap->Timer--; 
        
        if (ap->Timer < 0) 
        { 
            RequestAdvFade(3, GetSamurai(50)); 
            
            ap->FromTitle = 0; 
            
            ap->NextReturnCode = 1; 
            
            ap->Mode = 17; 
        } 
        else if (CheckStartButton() != 0) 
        { 
            ap->FlushCount = 255.0f; 
            ap->FlushSpeed = 32.0f; 
            
            ap->NextMode = 8; 
            ap->Mode = 7; 
        } 

        DisplayPressStartPlate(ap->FlushCount); 
        break; 
    case 7:
        DisplayPressStartPlate(ap->FlushCount); 
        
        FadeOutPlate(); 
        break; 
    case 8:
        ap->DepthLevel = 1; 
        
        sys->ss_flg |= 0x20000; 
        
        Pad[ap->PortId].Flag = 0; 

        ulFrame = 2; 
        
        McPrevResult = 0; 

        if ((ap->Cursor[0] == 0) && (FindFirstVmDrive() < 0))
        { 
            ap->Cursor[0] = 1;
        } 
        
        FadeInPlate(9); 
        
        DisplayGameModePlate(ap->Cursor[0], ap->CursorMax[0], ap->FlushCount, 1); 
        break; 
    case 9:
        if (ulFrame == 0) 
        { 
            McCrntResult = CheckMcSelectPortInfoState(0); 
            
            if ((McCrntResult | McPrevResult) == 1) 
            {
                CheckButton(0, 1, 0);
            } 
            else
            { 
                CheckButton(0, 0, 0);
            }
            
            McPrevResult = McCrntResult; 
            
            ulFrame = 1;
        } 
        else if (ulFrame == 1)
        { 
            McCrntResult = CheckMcSelectPortInfoState(1); 
            
            if ((McCrntResult | McPrevResult) == 1) 
            {
                CheckButton(0, 1, 0);
            }
            else
            {
                CheckButton(0, 0, 0); 
            } 
            
            McPrevResult = McCrntResult; 
            
            ulFrame = 0; 
        } 
        else
        { 
            McCrntResult = CheckMcSelectPortInfoState(0);
            McPrevResult = CheckMcSelectPortInfoState(1);
            
            if ((McCrntResult | McPrevResult) == 1) 
            { 
                CheckButton(0, 1, 0);
                
                McPrevResult = 1;
            } 
            else
            { 
                CheckButton(0, 0, 0); 
                
                McPrevResult = 0; 
            }
            
            ulFrame = 0;
        }
        
        DisplayGameModePlate(ap->Cursor[0], ap->CursorMax[0], ap->FlushCount, 0);
        break; 
    case 10:
        DisplayGameModePlate(ap->Cursor[0], ap->CursorMax[0], ap->FlushCount, 1); 
        
        FadeOutPlate(); 
        break; 
    case 11:
        FadeInPlate(12); 
        
        DisplayNewGamePlate(ap->Cursor[1], ap->FlushCount, 1);
        break; 
    case 12:
        CheckButton(1, 1, 1); 
        
        DisplayNewGamePlate(ap->Cursor[1], ap->FlushCount, 0); 
        break; 
    case 13:
        DisplayNewGamePlate(ap->Cursor[1], ap->FlushCount, 1); 
        
        FadeOutPlate(); 
        break;
    case 14:
        FadeInPlate(15); 
        
        DisplayExtraGamePlate(ap->Cursor[2], ap->FlushCount, 1); 
        break; 
    case 15:
        CheckButton(2, 1, 1); 
        
        DisplayExtraGamePlate(ap->Cursor[2], ap->FlushCount, 0); 
        break; 
    case 16:
        DisplayExtraGamePlate(ap->Cursor[2], ap->FlushCount, 1); 
        
        FadeOutPlate(); 
        break; 
    case 17:
        if (CheckAdvFade() == 0) 
        { 
            ap->Mode = -1; 
        } 
        else
        { 
            DisplayTitleBg(); 
            
            if ((ap->GenFlag != 0) && (ap->FlushCount != 0)) 
            { 
                a = (((unsigned int)ap->FlushCount & 0xFF) << 24) | 0xFFFFFF; 
                
                poly[0].x = -2.0f; 
                poly[0].y = -2.0f; 
                poly[0].z = 0.9f; 
                poly[0].col = a; 
                
                poly[1].x = -2.0f; 
                poly[1].y = 482.0f; 
                poly[1].z = 0.9f; 
                poly[1].col = a; 
                
                poly[2].x = 642.0f; 
                poly[2].y = -2.0f; 
                poly[2].z = 0.9f; 
                poly[2].col = a; 
                
                poly[3].x = 642.0f; 
                poly[3].y = 482.0f; 
                poly[3].z = 0.9f; 
                poly[3].col = a; 
                
                njDrawPolygon(poly, 4, 1); 
                
                ap->FlushCount -= 3.0f; 
                
                if (ap->FlushCount < 0)
                { 
                    ap->FlushCount = 0;
                } 
            } 
        } 
        
        break; 
    } 
    
    if (ap->Mode == -1)
    {
        StopVibrationEx();
        
        AdvEasyReleaseTexture();
        
        if ((ap->NextReturnCode == 3) || (ap->NextReturnCode == 2) || (ap->NextReturnCode == 6)) 
        {
            StopAdx(0);
        }
        
        if (ap->DepthLevel != 0) 
        {
            if (TitleSoftResetFlag != 0) 
            {
                ap->FromTitle = 0;
                
                ap->NextReturnCode = 7;
            } 
            else
            {
                sys->ss_flg &= ~0x20000;
            }
        }
        
        ap->DepthLevel = 0;
        
        ap->Mode = 0;
        
        ap->Active = 0;
        
        ReturnCode = ap->NextReturnCode;
    }
    
    return ReturnCode;
}

// 100% matching!
void ResetOptionMenuParam(int Mode) 
{ 
    ADV_WORK* ap; 
    int i;

    ap = &AdvWork; 

    switch (Mode) 
    { 
    case 0:
        sys->vibration = GetUseVibrationUnit(); 

        OptionDef[0].Item = GetSoundMode(); 
        OptionDef[1].Item = sys->keytype; 
        OptionDef[2].Item = 0; 
        OptionDef[3].Item = 0; 
        OptionDef[4].Item = !(sys->vibration != 0); 
        OptionDef[5].Item = 0; 
        OptionDef[6].Item = 0; 
        
        ap->OptScrX = sys->adjust_x; 
        ap->OptScrY = sys->adjust_y; 
        
        ap->OptLevel = 0; 

        ap->vibration = sys->vibration; 
        
        ap->keytype = sys->keytype; 
        
        ap->adjust_x = sys->adjust_x; 
        ap->adjust_y = sys->adjust_y; 
        
        ap->SoundMode = GetSoundMode(); 

        for (i = 0; i < 2; i++)
        { 
            ap->ScrollPlatePosX[i][0] = 0; 
            ap->ScrollPlatePosX[i][1] = 672.0f; 
        } 
        
        break; 
    case 2:
        sys->keytype = 0; 
        
        RequestAdjustDisplay(0, 0); 
        
        SetSoundModeEx(0, 0); 
        
        ap->SoundMode = 0; 
        
        if (CheckVibrationUnit((ap->PortId * 6) + 2) == 0) 
        { 
            SetUseVibrationUnit(0); 
            
            sys->vibration = 0; 
        } 
        else 
        { 
            SetUseVibrationUnit(1); 
            
            sys->vibration = 1; 
        }
        
        OptionDef[0].Item = GetSoundMode(); 
        OptionDef[1].Item = sys->keytype; 
        OptionDef[2].Item = 0; 
        OptionDef[3].Item = 0; 
        OptionDef[4].Item = !(sys->vibration != 0); 
        OptionDef[5].Item = 0; 
        OptionDef[6].Item = 0; 
        
        ap->OptScrX = sys->adjust_x; 
        ap->OptScrY = sys->adjust_y; 
        break;
    }

    for (i = 0; i < 7; i++) 
    { 
        OptionDef[i].Item2 = 0; 
        
        OptionDef[i].SelectFlag = 0; 
        
        OptionDef[i].Switch = 0; 
    } 
} 

// 99.70% matching
void DisplayOptionScrollPlate(float PosX, float PosY) 
{ 
    int i;
    QUAD* qp;

    qp = &Qtex[1];

    njTextureFilterMode(1); 
    
    for (i = 0; i < 6; i++)
    { 
        SetQuadPos(PosX + (i * 112.0f), PosY, 114.0f, 80.0f, qp); 
        SetQuadUv2(400.0f, 80.0f * i, 114.0f, 80.0f, 2, qp); 
        
        AdvEasyDrawTexture(2, -1, qp, (0.01f * i) + 0.92f, 0); 
    } 
    
    njTextureFilterMode(0); 
} 

// 100% matching!
void DisplayOptionBg(int Level, int Flag)
{
    ADV_WORK* ap = &AdvWork;     
    int i;                        
    int j;                       
    float y[2] = { 16.0f, 384.0f }; 
    float s[2] = { 2.0f, -2.0f };   
    QUAD* qp;                   

    qp = &Qtex[2];

    switch (Level) 
    {
    case 0:
    case 1:
        break;
    case -1:
    case 2:
    case 3:
        return;
    }
    
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++) 
        {
            DisplayOptionScrollPlate(ap->ScrollPlatePosX[i][j], y[i]);
            
            ap->ScrollPlatePosX[i][j] += s[i];
        }
        
        for (j = 0; j < 2; j++)
        {
            if (i == 0)
            {
                if (!(ap->ScrollPlatePosX[i][j] < 672.0f)) 
                {
                    ap->ScrollPlatePosX[i][j] = ap->ScrollPlatePosX[i][(j != 0) ^ 1] - 672.0f;
                }
            } 
            else if (ap->ScrollPlatePosX[i][j] <= -672.0f) 
            {
                ap->ScrollPlatePosX[i][j] = 672.0f + ap->ScrollPlatePosX[i][(j != 0) ^ 1];
            }
        }
    }  
    
    if (Flag != 0) 
    {
        njTextureFilterMode(1);
        
        SetQuadPos(0, 96.0f, 322.0f, 288.0f, qp);
        SetQuadUv2(24.0f, 0, 298.0f, 256.0f, 2, qp);
        
        AdvEasyDrawTexture(2, 0xFF7F7F7F, qp, 0.01f, 0);
        
        SetQuadPos(320.0f, 96.0f, 322.0f, 288.0f, qp);
        SetQuadUv2(0, 256.0f, 298.0f, 256.0f, 2, qp);
        
        AdvEasyDrawTexture(2, 0xFF7F7F7F, qp, 0.01f, 0);
        
        njTextureFilterMode(0);
    }
}

// 99.65% matching
int DisplayOptionPlateLevel0(int PortId, int Flag)
{
    ADV_WORK* ap;            
    QUAD* qp;                
    int i;                  
    int ReturnCode;         
    unsigned int Alpha;      
    int PuruFindFlag;        
    int ForceCursorMoveFlag; 
    
    ap = &AdvWork;

    PuruFindFlag = 1;
    
    ReturnCode = 0;
    
    ForceCursorMoveFlag = 0;
    
    if (CheckVibrationUnit((PortId * 6) + 2) == 0) 
    {
        OptionDef[4].Item = 1;
        
        PuruFindFlag = 0;
        
        SetUseVibrationUnit(0);
        
        sys->vibration = 0;
        
        if (ap->OptIndex == 4)
        {
            ForceCursorMoveFlag = 1;
            
            ap->OptIndex = 5;
        }
    }
    
    if (Flag != 0) 
    {
        if (((Pad[PortId].press & 0x100)) || ((Pad[PortId].press & AdvGetCancelButton()))) 
        {
            ap->OptIndex = 6;
            ap->OptFadeType = 0;
            
            CallSystemSe(0, 0);
            
            ReturnCode = -1; 
        }
        else if ((Pad[PortId].press & AdvGetOkButton())) 
        {
            if (OptionDef[ap->OptIndex].NextLevel > 0) 
            {
                ap->OptFadeType = OptionDef[ap->OptIndex].NextFadeType;
                
                CallSystemSe(0, 3);
                
                ReturnCode = OptionDef[ap->OptIndex].NextLevel;
            } 
            else if (OptionDef[ap->OptIndex].NextLevel < 0) 
            {
                ap->OptFadeType = 0;
                
                CallSystemSe(0, 0);
                
                ReturnCode = OptionDef[ap->OptIndex].NextLevel;
            } 
            else if (ap->OptIndex == 5) 
            {
                ResetOptionMenuParam(2);
                
                CallSystemSe(0, 3);
            }
        } 
        else
        {
            if (ForceCursorMoveFlag == 0) 
            {
                if ((Pad[PortId].Rept & 0x1000)) 
                {
                    if (ap->OptIndex == 0) 
                    {
                        ap->OptIndex = 6;
                        goto label;
                    }
                    
                    ap->OptIndex--;
                    
                    if ((ap->OptIndex == 4) && (PuruFindFlag == 0)) 
                    {
                        ap->OptIndex--;
                    }
                    
                label:
                    CallSystemSe(0, 2);
                } 
                else if ((Pad[PortId].Rept & 0x4000)) 
                {
                    if (ap->OptIndex == 6) 
                    {
                        ap->OptIndex = 0;
                    } 
                    else 
                    {
                        ap->OptIndex++;
                        
                        if ((ap->OptIndex == 4) && (PuruFindFlag == 0))
                        {
                            ap->OptIndex++;
                        }
                    }
                    
                    CallSystemSe(0, 2);
                }
            }
            
            if ((Pad[PortId].press & 0x8000)) 
            {
                if (((ap->OptIndex != 4) || (PuruFindFlag != 0)) && ((ap->OptIndex != 1) && (OptionDef[ap->OptIndex].Item != 0))) 
                {
                    OptionDef[ap->OptIndex].Item--;

                    switch (ap->OptIndex)
                    { 
                    case 0:        
                        SetSoundModeEx(0, 0);
                        
                        ap->SoundMode = 0;
                        break;
                    case 4:            
                        SetUseVibrationUnit(1);
                        
                        StartVibrationEx(PortId, 0);
                        
                        sys->vibration = 1;
                        break;
                    }
                    
                    CallSystemSe(0, 2);
                } 
            } 
            else if ((Pad[PortId].press & 0x2000)) 
            {
                if (((ap->OptIndex != 4) || (PuruFindFlag != 0)) && ((ap->OptIndex != 1) && (OptionDef[ap->OptIndex].Item != OptionDef[ap->OptIndex].MaxItem)))  
                {
                    OptionDef[ap->OptIndex].Item++;
                    
                    switch (ap->OptIndex) 
                    { 
                    case 0:
                        SetSoundModeEx(1, 0);
                        
                        ap->SoundMode = 1;
                        break;
                    case 4:
                        SetUseVibrationUnit(0);
                        
                        sys->vibration = 0;
                        break;
                    }
                    
                    CallSystemSe(0, 2); 
                }
            }
        }
    }
    
    for (i = 0; i < 7; i++) 
    {
        OptionDef[i].SelectFlag = 0;
    } 
    
    OptionDef[ap->OptIndex].SelectFlag = 1;
    
    qp = &Qtex[1];
    
    SetQuadPos(32.0f, 160.0f, 288.0f, 32.0f, qp);
    SetQuadUv2(0, 0, 288.0f, 32.0f, 0, qp);
    
    SetQuadPos(32.0f, 192.0f, 288.0f, 32.0f, &qp[1]);
    SetQuadUv2(0, 32.0f, 288.0f, 32.0f, 0, &qp[1]);
    
    SetQuadPos(32.0f, 224.0f, 288.0f, 32.0f, &qp[2]);
    SetQuadUv2(0, 64.0f, 288.0f, 32.0f, 0, &qp[2]);
    
    SetQuadPos(32.0f, 256.0f, 288.0f, 32.0f, &qp[3]);
    SetQuadUv2(0, 96.0f, 288.0f, 32.0f, 0, &qp[3]);
    
    SetQuadPos(32.0f, 288.0f, 288.0f, 32.0f, &qp[4]);
    SetQuadUv2(0, 128.0f, 288.0f, 32.0f, 0, &qp[4]);
    
    SetQuadPos(32.0f, 320.0f, 288.0f, 32.0f, &qp[5]);
    SetQuadUv2(0, 160.0f, 288.0f, 32.0f, 0, &qp[5]);
    
    SetQuadPos(32.0f, 352.0f, 288.0f, 32.0f, &qp[6]);
    SetQuadUv2(0, 192.0f, 288.0f, 32.0f, 0, &qp[6]);
    
    SetQuadPos(336.0f, 160.0f, 128.0f, 32.0f, &qp[7]);
    SetQuadUv2(0, 256.0f, 128.0f, 32.0f, 0, &qp[7]);
    
    SetQuadPos(480.0f, 160.0f, 128.0f, 32.0f, &qp[8]);
    SetQuadUv2(128.0f, 256.0f, 128.0f, 32.0f, 0, &qp[8]);
    
    SetQuadPos(336.0f, 192.0f, 128.0f, 32.0f, &qp[9]);
    SetQuadUv2(0, 288.0f, 128.0f, 32.0f, 0, &qp[9]);
    
    SetQuadPos(432.0f, 192.0f, 32.0f, 32.0f, &qp[10]);
    SetQuadUv2(128.0f + (OptionDef[1].Item * 32), 288.0f, 32.0f, 32.0f, 0, &qp[10]); 
    
    SetQuadPos(336.0f, 288.0f, 128.0f, 32.0f, &qp[11]);
    SetQuadUv2(0, 320.0f, 128.0f, 32.0f, 0, &qp[11]);
    
    SetQuadPos(480.0f, 288.0f, 128.0f, 32.0f, &qp[12]);
    SetQuadUv2(128.0f, 320.0f, 128.0f, 32.0f, 0, &qp[12]);
    
    SetQuadPos(96.0f, 96.0f, 448.0f, 48.0f, &qp[13]);
    SetQuadUv2(0, 320.0f, 448.0f, 48.0f, 2, &qp[13]);
    
    for (i = 0; i < 7; i++) 
    {
        Alpha = 255;
        
        if (OptionDef[i].SelectFlag != 0) 
        {
            Alpha += (unsigned int)ap->FlushCount2;
            
            Alpha <<= 24;
            
            Alpha |= 0xFFFFFF;
        } 
        else 
        {
            Alpha = 0x7FAFAFAF;
        }
        
        AdvEasyDrawTexture(0, Alpha, &Qtex[i + 1], 0.05f, 1);
    } 
            
    if (OptionDef[0].Item == 0) 
    {
        if (ap->OptIndex == 0) 
        {
            AdvEasyDrawTexture(0, 0xDFFFFFFF, &Qtex[8], 0.05f, 1);
        } 
        else 
        {
            AdvEasyDrawTexture(0, 0xDFCFCFCF, &Qtex[8], 0.05f, 1);
        }
        
        AdvEasyDrawTexture(0, 0x7FAFAFAF, &Qtex[9], 0.05f, 1);
    } 
    else
    {
        AdvEasyDrawTexture(0, 0x7FAFAFAF, &Qtex[8], 0.05f, 1);
        
        if (ap->OptIndex == 0)
        {
            AdvEasyDrawTexture(0, 0xDFFFFFFF, &Qtex[9], 0.05f, 1);
        } 
        else 
        {
            AdvEasyDrawTexture(0, 0xDFCFCFCF, &Qtex[9], 0.05f, 1);
        }
    }
    
    if (ap->OptIndex == 1) 
    {
        AdvEasyDrawTexture(0, 0xDFFFFFFF, &Qtex[10], 0.05f, 1);
        AdvEasyDrawTexture(0, 0xDFFFFFFF, &Qtex[11], 0.05f, 1);
    } 
    else 
    {
        AdvEasyDrawTexture(0, 0xDFCFCFCF, &Qtex[10], 0.05f, 1);
        AdvEasyDrawTexture(0, 0xDFCFCFCF, &Qtex[11], 0.05f, 1);
    }
    
    if (OptionDef[4].Item == 0) 
    {
        if (ap->OptIndex == 4) 
        {
            AdvEasyDrawTexture(0, 0xDFFFFFFF, &Qtex[12], 0.05f, 1);
        } 
        else
        {
            AdvEasyDrawTexture(0, 0xDFCFCFCF, &Qtex[12], 0.05f, 1);
        }
        
        AdvEasyDrawTexture(0, 0x7FFFFFFF, &Qtex[13], 0.05f, 1);
    } 
    else 
    {
        AdvEasyDrawTexture(0, 0x7FFFFFFF, &Qtex[12], 0.05f, 1);
        
        if (ap->OptIndex == 4)
        {
            AdvEasyDrawTexture(0, 0xDFFFFFFF, &Qtex[13], 0.05f, 1);
        } 
        else 
        {
            AdvEasyDrawTexture(0, 0xDFCFCFCF, &Qtex[13], 0.05f, 1);
        }
    }
    
    AdvEasyDrawTexture(1, -1, &Qtex[14], 0.05f, 1);
    
    FlushPlate();
    
    return ReturnCode;
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
	//_anon0* qp;
	//_anon8* ap;
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
	scePrintf("DisplayOptionPlateLevel1 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2c6d50
int DisplayOptionPlateLevel2(int PortId, int Flag)
{
	unsigned int CursorCol[4];
	char Str[4];
	//_anon32 BotRigt;
	//_anon32 TopLeft;
	int ReturnCode;
	//_anon0* qp;
	//_anon8* ap;
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
	scePrintf("DisplayOptionPlateLevel2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2c7870
int DisplayOptionPlateLevel3(int PortId, int Flag)
{
	unsigned int PolyCol;
	//_anon28 ColorBarDef[8];
	//_anon13 poly[4];
	//_anon32 BotRigt;
	//_anon32 TopLeft;
	int ReturnCode;
	int i;
	//_anon0* qp;
	//_anon8* ap;
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
	scePrintf("DisplayOptionPlateLevel3 - UNIMPLEMENTED!\n");
}

// 100% matching! 
int DisplayOptionPlate(int PortId, int Level, int Flag)
{ 
    switch (Level) 
    {                  
    case 0:
        return DisplayOptionPlateLevel0(PortId, Flag); 
    case 1:
        return DisplayOptionPlateLevel1(PortId, Flag); 
    case 2:
        return DisplayOptionPlateLevel2(PortId, Flag); 
    case 3: 
        return DisplayOptionPlateLevel3(PortId, Flag); 
    }

    return -1;
} 

// 99.79% matching
int Adv_GameOptionScreen()
{
	ADV_WORK* ap;
    int ReturnCode;
	static int ulState;
	static int SaveCheck;

    ap = (ADV_WORK*)&AdvWork;

    ReturnCode = 0;

    ap->PortId = AdvGetCurrentPort();
    
    ExecuteAdvFadeEx(ap->OptFadeType);
    
    if (ap->AppMode == 0) 
    {
        ExecuteAdvScreenSaver();
    }
    
    AdvCheckSoftReset(1);
    
    switch (ap->Mode2) 
    {
    case 0:
        ResetAdvSystem();
        ResetOptionMenuParam(0);
        
        ap->Mode2 = (ap->AppMode == 0) ? 3 : 6;
        break;
    case 3:
        ap->ptr[0] = bhGetFreeMemory(GetInsideFileSize(sys->sys_partid, 1), 32);
        
        RequestReadInsideFile(sys->sys_partid, 1, ap->ptr[0]);
        
        ap->Mode2 = 4;
        break;
    case 4:
        CheckReadEndAdvInsideFile2Ex(5, 1);
        break;
    case 5:
        bhSetFontTexture(ap->ptr[0]);
        
        AllFreeAdvMemory();
        
        ap->Mode2 = 6;
        break;
    case 6:
        RequestAdvInsideFileEx(4, 0);
        
        ap->Mode2 = 7;
        break;
    case 7:
        CheckReadEndAdvInsideFile2Ex((ap->AppMode == 0) ? 8 : 1, 1);
        break;
    case 1:
        AdvPushPaletteData();
        
        ap->Mode2 = 2;
        break;
    case 2:
        AdvPushRoomTexture(0xC0000);
        
        ap->Mode2 = 8;
        break;
    case 8:
        AdvEasySetupTextureBasic(AdvGetResourcePtr(ap->ptr[0], 2), 0, 0);
        AdvEasySetupTextureBasic(AdvGetResourcePtr(ap->ptr[0], 3), 0, 1);
        AdvEasySetupTextureBasic(AdvGetResourcePtr(ap->ptr[0], 4), 0, 2);
        
        ap->PalNo = TransPvpData(AdvGetResourcePtr(ap->ptr[0], 1), ap->PalFlag);
        
        ap->MsgPtr = (unsigned char*)AdvGetResourcePtr(ap->ptr[0], 0);
        
        AdvEasyTransTextureBasic(0, 3, 1);
        
        RequestAdvFade(2, 0.25f);
        
        if (ap->AppMode != 0)
        {
            CallSystemSe(0, 3);
        }
        
        ap->Mode2 = 9;
        break;
    case 9:
        DisplayOptionPlate(ap->PortId, ap->OptLevel, 0);
        DisplayOptionBg(ap->OptLevel, 1);
        
        if (CheckAdvFade() == 0)
        {
            ap->Mode2 = 10;
        }
        
        break;
    case 10:
        CheckAdvScreenSaverStopKey(ap->PortId);
        
        ap->NextOptLevel = DisplayOptionPlate(ap->PortId, ap->OptLevel, 1);
        
        DisplayOptionBg(ap->OptLevel, 1);
        
        if (ap->OptLevel != ap->NextOptLevel) 
        {
            RequestAdvFade(3, 0.25f);
            
            ap->NextReturnCode = 0;
            
            ap->Mode2 = 11;
            break;
        }
        
        if (ap->NextOptLevel < 0) 
        {
            if ((ap->vibration != sys->vibration) || (ap->keytype != sys->keytype) || ((ap->adjust_x != sys->adjust_x) || (ap->adjust_y != sys->adjust_y)) || (ap->SoundMode != sys->ssd_reserve)) 
            {
                ap->OptSaveFlag = 1;
            }
            
            RequestAdvFade(3, 0.25f);
            
            ap->NextReturnCode = 1;
            
            ap->Mode2 = 11;
        }
        
        break;
    case 11:
        if (CheckAdvFade() == 0) 
        {
            if (ap->NextReturnCode == 0) 
            {
                switch (ap->OptLevel)
                {
                case 0:
                    switch (ap->NextOptLevel) 
                    {
                    case 1:
                        DisplayOptionBg(ap->OptLevel, 0);
                        break;
                    case -1:
                    case 2:
                    case 3:
                        break;
                    }
                    
                    break;
                case 1:
                    DisplayOptionBg(ap->OptLevel, 0);
                    break;
                }
                
                ResetOptionMenuParam(1);
                
                RequestAdvFade(2, 0.25f);
                
                ap->OptLevel = ap->NextOptLevel;
                
                ap->Mode2 = 9;
            } 
            else
            {
                ap->MsgNo = 0;
                
                ap->GenFlag = 0;
                
                ap->Mode2 = 15;
            }
            
            break;
        }
        
        DisplayOptionPlate(ap->PortId, ap->OptLevel, 0);
        DisplayOptionBg(ap->OptLevel, 1);
        break;
    case 15:
        StopAdvScreenSaver(0);
        
        ap->Mode2 = 16;
        break;
    case 16:
        if (ap->OptSaveFlag != 0) 
        {
            switch (ulState) 
            {
            case 0:
                sys->ssd_reserve = GetSoundMode();
                
                pSysSave = CreateSysSaveScreen(&SysSave, vwbmemp, 0, 1);
                
                SaveCheck = 0;
                
                ulState = 1;
                break;
            case 1:
                SaveCheck = ExecuteSysSaveScreen(pSysSave);
                
                if (SaveCheck == 1)
                {
                    ulState = 0;
                    
                    SaveCheck = 0;
                    
                    ap->Mode2 = 12;
                }
                else if (SaveCheck == 2) 
                {
                    ulState = 0;
                    
                    SaveCheck = 0;
                    
                    ap->Mode2 = 12;
                }
            }
            
            break;
        }
        
        ap->Mode2 = 12;
        break;
    case 17:
        CheckAdvScreenSaverStopKey(ap->PortId);
        
        ap->NextMode = 12;
        
        DispVmWarningMessage(ap->MsgNo);
        break;
    case 12:
        if (ap->AppMode == 0)
        {
            AdvEasyReleaseAllTexture();
            
            ap->Mode2 = 18;
        } 
        else 
        {
            AdvEasyReleaseTexture();
            
            ap->Mode2 = 13;
        }
        
        break;
    case 13:
        AdvPopRoomTexture();
        
        ap->Mode2 = 14;
        break;
    case 14:
        AdvPopPaletteData();
        
        ap->Mode2 = 18;
        break;
    case 18:
        ap->Mode2 = -1;
        break;
    }
    
    if (ap->Mode2 == -1)
    {
        if (ap->AppMode == 0) 
        {
            AdvEasyReleaseAllTexture();
        } 
        else 
        {
            AdvEasyReleaseTexture();
        }
        
        AllFreeAdvMemory();
        
        AdvSetSoundMode();
        
        ap->OptFadeType = 0;
        
        ap->Mode2 = 0;
        ap->Mode = 0;
        
        ap->Active = 0;
        
        ReturnCode = 1;
    }
    
    return ReturnCode;
}

// 100% matching! 
int Adv_ChangeDiscScreen()
{ 
    ADV_WORK* ap;

    ap = &AdvWork;

    UnmountSoundAfs(); 

    sys->ss_flg &= ~0x40000; 
    sys->ss_flg &= ~0x10000; 
    
    if (!(sys->ss_flg & 0x1))
    {
        sys->ss_flg |= 0x1;
    } 
    else 
    { 
        sys->ss_flg &= ~0x1; 
    }
    
    ap->NextReturnCode = 1; 

    MountSoundAfs(); 

    sys->ss_flg &= ~0x20000; 
    sys->ss_flg &= ~0x10000; 
    
    ap->Mode = 0; 
    
    ap->Active = 0; 

    return ap->NextReturnCode; 
} 

// 100% matching! 
int Adv_SoundMuseum()
{ 
    return 1;
} 
