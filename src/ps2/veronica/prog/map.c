#include "../../../ps2/veronica/prog/map.h"
#include "../../../ps2/veronica/prog/binfunc.h"
#include "../../../ps2/veronica/prog/event.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMem.h"
#include "../../../ps2/veronica/prog/ps2_NaSprite.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NaView.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_texture.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/screen.h"
#include "../../../ps2/veronica/prog/sdfunc.h"

#pragma divbyzerocheck on 

static map_wrk MapWrk;

static map_wrk* mwP = &MapWrk;

const static NJS_ARGB MapPal[32] = 
{
    { 1.0f, 0.7f, 0.7f, 0.7f }, { 1.0f, 0.1f, 0.2f, 0.4f }, { 1.0f, 0.4f, 0.1f, 0.2f }, { 0.5f, 1.0f, 0.5f, 0.0f },
    { 1.0f, 0.6f, 0.1f, 0.5f }, { 0.3f, 0.2f, 0.2f, 0.8f }, { 1.0f, 1.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.4f, 0.8f },
    { 1.0f, 0.8f, 0.0f, 0.4f }, { 0.8f, 1.0f, 0.5f, 0.0f }, { 1.0f, 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 0.0f, 1.0f },
    { 1.0f, 0.8f, 0.8f, 0.0f }, { 1.0f, 0.8f, 0.0f, 0.8f }, { 1.0f, 0.0f, 0.8f, 0.8f }, { 1.0f, 0.8f, 0.8f, 0.0f },
    { 1.0f, 0.0f, 0.8f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.8f, 0.6f, 0.4f, 0.0f },
    { 1.0f, 0.8f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.8f, 0.0f }, { 1.0f, 0.0f, 0.0f, 0.8f }, { 1.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 0.5f, 0.1f, 0.1f }, { 1.0f, 0.5f, 0.3f, 0.3f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 0.8f, 0.8f, 0.0f }, { 1.0f, 0.8f, 0.0f, 0.8f }, { 1.0f, 0.0f, 0.8f, 0.8f }, { 1.0f, 0.8f, 0.8f, 0.0f }
};
const static NJS_COLOR MapCol[3] = 
{
    { 0xFF000800 }, { 0xFF003000 }, { 0xC0A0A0A0 }
};
const static ID_WORK ItmDat[22] = 
{
    { 59, 96 },  { 86, 96 },  { 84, 97 },  { 56, 98 },  { 51, 99 },  { 67, 100 }, { 68, 101 }, { 33, 102 },  { 73, 103 }, { 62, 104 }, 
	{ 93, 105 }, { 76, 106 }, { 75, 107 }, { 89, 108 }, { 90, 109 }, { 81, 110 }, { 92, 111 }, { 105, 112 }, { 66, 113 }, { 44, 114 },
    { 46, 115 }, { 108, 116 }
};
const static unsigned short CncDatA[81] = 
{
    65284, 1, 65285, 256, 416, 65325, 40960, 40961, 41121, 65347, 41376, 41232, 41233, 41234, 65287, 4113, 65288, 4368, 4370, 4513, 4400, 
	4401, 4402, 65289, 4625, 65294, 12337, 65295, 12592, 12594, 12560, 12561, 12562, 12706, 65296, 12849, 65345, 41520, 41521, 41522, 
	41504, 41505, 41506, 41507, 65290, 8225, 8354, 8256, 8257, 65291, 8480, 8482, 65292, 8737, 8739, 65293, 8994, 65297, 16449, 16416,
    16417, 16418, 16419, 16464, 65298, 16704, 65299, 20544, 20545, 20576, 20577, 20578, 65300, 24673, 65301, 24928, 24930, 24912, 65302, 
	25185, 65535
};
const static unsigned short CncDatB[49] = 
{
    65303, 28785, 65304, 29040, 29042, 65294, 29297, 29299, 65295, 29554, 29556, 29568, 29569, 65296, 29811, 65297, 32897, 32880, 32881, 
	32882, 32883, 32884, 32912, 32913, 32914, 32915, 32916, 32917, 65298, 33152, 65305, 37009, 65306, 37264, 37266, 65307, 37521, 37523, 
	65308, 37778, 37780, 65300, 38035, 38037, 65301, 38292, 38272, 38273, 65535
};

// 98.45% matching
void bhInitMap(enum_2 set_mod)
{
    NJS_TEXLIST* texP;

    njClipZ(-2.0f, -20000.0f);
    
    njSetAspect(1.174f, 1.0f);
    njSetBackColor(0, 0, 0);
    
    npSetMemory((unsigned char*)mwP, sizeof(map_wrk), 0);
    
    mwP->status |= (1 << set_mod) & 7;
    
    mwP->mem_bakP = sys->memp;
    
    mwP->vew_mtxP = (NJS_MATRIX*)mwP->Vew_Mtx;
    mwP->rom_mtxP = (NJS_MATRIX*)mwP->Rom_Mtx;
    
    mwP->cur_mtxP = &mwP->rom_mtxP[1];
    mwP->tmp_mtxP = &mwP->rom_mtxP[2];
    
    mwP->ply_stg = sys->stg_no;
    mwP->ply_rom = sys->rom_no + (sys->stg_no * 100);
    
    mwP->vew_max.y = 600.0f;
    mwP->vew_min.y = 600.0f;
    
    mwP->dst_zom = 600.0f;
    mwP->vew_zom = 600.0f;
    
    mwP->vew_ang[0] = -16384;
    
    mwP->bck_depth = -1600.0f;
    
    mwP->bck_p0.x = 0;
    mwP->bck_p0.y = 0;
    
    mwP->bck_p1.x = 640.0f;
    mwP->bck_p1.y = 480.0f;
    
    mwP->ar = mwP->ag = mwP->ab = 0;
    mwP->pr = mwP->pg = mwP->pb = 0.6f;
    
    mwP->pitch = -16384;
    
    mwP->yaw = 0;
    
    mwP->map_scale = 0.001f;
    
    if ((mwP->status & 0x2)) 
    {
        mwP->bnk_mde = sys->mp_prm[0];
        mwP->bnk_stg = sys->mp_prm[1];
        mwP->bnk_flr = sys->mp_prm[2];
        mwP->bnk_rom = sys->mp_prm[3] + (mwP->bnk_stg * 100);
    }
    
    if (!(mwP->status & 0x4)) 
    {
        mwP->rom_texP = rom->mdl.texP;
        
        if (mwP->rom_texP != NULL) 
        {
            sys->memp = (unsigned char*)(((int)sys->memp + 31) & ~0x1F);
            
            mwP->rom_bakP = sys->memp;
            
            sys->memp = (unsigned char*)bhCopyTexmem2Mainmem(mwP->rom_texP, (char*)sys->memp);
            
            bhGarbageTexture(NULL, 0);
            
            Ps2ClearOT();
            
            if (sys->fade_an > 0) 
            {
                bhDrawScreenFade();
            }
        }
    }
    
    texP = (NJS_TEXLIST*)bhGetFreeMemory(8, 4);
    
    texP->textures  = (NJS_TEXNAME*)bhGetFreeMemory(12, 4);
    texP->nbTexture = 1;
    
    mwP->map_texP = texP;
    
    texP = (NJS_TEXLIST*)bhGetFreeMemory(8, 4);
    
    texP->textures  = (NJS_TEXNAME*)bhGetFreeMemory(12, 4);
    texP->nbTexture = 1;
    
    mwP->stg_texP = texP;
    
    MapFuncInit(24);
    
    njCnkSetEasyMultiLight(1);
    
    MapCnvStatus2Flag();
    
    mwP->prti_no = sys->dor_partid;
    
    if (!(mwP->status & 0x4)) 
    {
        CallSystemSe(0, 3);
    }
}

// 100% matching! 
void bhSetMap()
{

}

// 100% matching!
void bhExitMap()
{
    njClipZ(GameNear, GameFar);
    
    njSetAspect(BHD_ASPECT_X, BHD_ASPECT_Y);
    
    if ((mwP->status & 0x8)) 
    {
        njReleaseTexture(mwP->map_texP);
    }
    
    if ((mwP->status & 0x10)) 
    {
        njReleaseTexture(mwP->stg_texP);
    }
    
    bhGarbageTexture(NULL, 0);
    
    if (mwP->rom_texP != NULL) 
    {
        bhCopyMainmem2Texmem(mwP->rom_texP);
    }
    
    bhReleaseFreeMemory(mwP->mem_bakP);
    
    sys->gm_flg &= ~0x80000;
}

// 100% matching!
static int bhReadMapData(char* namP)
{
    int code;
	int status;

    code = 0;
    
    switch (mwP->fil_mode)
    {
    case 0:
        if (mwP->map_bufP != NULL) 
        {
            bhReleaseFreeMemory(mwP->map_bufP);
        }
        
        mwP->map_bufP = bhGetFreeMemory(GetInsideFileSize(mwP->prti_no, (unsigned int)namP), 32);
        
        if (RequestReadInsideFile(mwP->prti_no, (unsigned int)namP, mwP->map_bufP) == 0) 
        {
            mwP->fil_mode = 2;
            break;
        }
        else 
        {
            mwP->fil_mode = 1;
        }
    case 1:
        code = -1;
        break;
    case 2:
        status = GetReadFileStatus(mwP);
        
        if (status == -1) 
        {
            code = -1;
        }
        else if (status == 0) 
        {
            code = 1;
        }
        
        break;
    }
    
    return code;
}

// 99.41% matching
static void MapCnvStatus2Flag()
{
	int id;
    unsigned int* itm_basP;
    ID_WORK* datP;
    int chk;
    int itm;
    unsigned int* itmP;

    id = sys->ply_id;
    
    if (id > 2)
    {
        if (id == 3) 
        {
            id = 2;
        }
        else if (id == 4) 
        {
            id = 0;
        }
        else 
        {
            id = 0;
        }
    }
    
    bhFlagSet(8, 1,      1);
    bhFlagSet(8, 2,      1);
    bhFlagSet(8, 3,      1);
    bhFlagSet(8, id + 1, 0);
   
    itm_basP = &sys->itm[sys->ply_id * 16];
    
    chk = 22; 
    
    datP = ItmDat;
    
    for (; chk > 0; chk--, datP++)
    {
        bhFlagSet(9, datP->flg_no, 1);
    }

    chk = 22;
    
    datP = ItmDat;

    for (; chk > 0; chk--, datP++)
    {
        for (itmP = itm_basP, id = 0; id < 16; id++, itmP++)
        {
            itm = (*itmP >> 16) & 0xFF;
            
            if ((unsigned int)itm == datP->itm_no)
            {
                bhFlagSet(9, datP->flg_no, 0);
                break;
            }
        }
    }
}

// 99.82% matching
int bhControlMap()
{
    int bol;         
    NJS_SCREEN scrn; 
    int next;        
    int* pacP;        
    ML_WORK* mlwP;    
    int i;            
    unsigned int tmp; 

    bol = 1;
    
    switch (mwP->map_mode) 
    {
    case MP_MOD_FIRST:
        bhSetScreenFade(sys->fade_pbk, 8.0f);
        
        MapFuncAlloc(FsubBackDraw, 0);
        MapFuncAlloc((void*)FsubZoomScreen, 0);
        
        MapEntryTask(FtskMapWait, MP_MOD_IDX_READ, 0);
        
        mwP->map_mode = MP_MOD_WAIT;
        
        MapCncInit(11, 6);
        
        if (GetGameMode() == 1) 
        {
            MapCncConnect(CncDatA);
        } 
        else 
        {
            MapCncConnect(CncDatB);
        }
        
        break;
    case MP_MOD_IDX_READ:
        njClipZ(-2.0f, -20000.0f);
        
        njSetAspect(1.174f, 1.0f);
        njSetBackColor(0x00000000, 0x00000000, 0x00000000); 
        
        scrn.dist = 500.0f;
        
        scrn.w = 640.0f;
        scrn.h = 480.0f;
        
        scrn.cx = 320.0f;
        scrn.cy = 240.0f;
        
        njSetScreen(&scrn);
        
        MapEntryTask(FtskMapRead, MP_MOD_IDX_ANALYZE, sys->ply_id);
        
        mwP->map_mode = MP_MOD_WAIT;
        break;
    case MP_MOD_IDX_ANALYZE:
        pacP = mwP->map_bufP;
        
        if (*pacP++ == 0x4341504D)
        {
            mlwP = mwP->MrkMdl;
            
            pacP = (int*)((int)pacP + *pacP);
            
            next = *pacP++;
            
            while ((*pacP & 0xFFFFFF) == 0x4C444D) 
            {
                bhMlbBinRealize(pacP, mlwP);
                
                pacP = (int*)((int)pacP + next);
                
                next = *pacP++;
                
                mlwP++; 
            }
            
            mwP->status |= 0x8;
            
            bhSetMemPvpTexture(mwP->map_texP, (unsigned char*)pacP, 0);
            
            if (next != -1) 
            {
                pacP = (int*)((int)pacP + next); 
                
                next = *pacP++;
            }
            
            for (i = 0; i < 10; i++) 
            {
                mwP->mes_bufPP[i] = (unsigned int*)pacP;
                
                if (next != -1) 
                {
                    pacP = (int*)((int)pacP + next); 
                    
                    next = *pacP++;
                }
            }
            
            mwP->map_bufP = pacP;
            
            tmp = MapGetFloorNo(mwP->map_bufP, mwP->ply_rom, plp->py);
            
            mwP->map_no  = tmp / 65536;
            mwP->ply_flr = tmp & 0xFFFF;
            
            MapEntrySprite(MP_SET_SILHOUETTE, 0);
            
            MapFuncAlloc((void*)FsubCompass, 0);
            MapFuncAlloc((void*)FsubModeMessage, 0);
        }
        
        if ((mwP->status & 0x2)) 
        {
            mwP->stg_no = mwP->bnk_stg;
            mwP->rom_no = mwP->bnk_rom;
            mwP->flr_no = mwP->bnk_flr;
        } 
        else 
        {
            mwP->stg_no = mwP->map_no;
            mwP->rom_no = mwP->ply_rom;
            mwP->flr_no = mwP->ply_flr;
        }
    case MP_MOD_MAP_READ:
        mwP->status &= ~0x40;
        mwP->status &= ~0x100;
        
        mwP->map_flr = mwP->flr_no;
        
        if ((mwP->status & 0x10)) 
        {
            mwP->status &= ~0x10;
            
            njReleaseTexture(mwP->stg_texP);
            
            bhGarbageTexture(NULL, 0);
        }
        
        MapEntryTask(FtskMapRead, MP_MOD_DAT_SET, (mwP->map_flr + (mwP->stg_no * 6)) + 5);
        
        mwP->map_mode = MP_MOD_WAIT;
        break;
    case MP_MOD_DAT_SET:
    {
        int next;  
        int* pacP; 
        
        pacP = mwP->map_bufP; 
        
        if (*pacP++ == 0x4341504D)
        {
            pacP = (int*)((int)pacP + *pacP);
            
            next = *pacP++;
            
            mwP->map_cdeP = (short*)pacP;
            
            if (next != -1) 
            {
                pacP = (int*)((int)pacP + next);
                
                next = *pacP++;
                
                bhMlbBinRealize(pacP, &mwP->map_mdl);
                
                MapPurgeTree(&mwP->map_mdl);
                
                mwP->map_objP = mwP->map_mdl.objP;
                
                if (next != -1) 
                {
                    mwP->status |= 0x10;
                    
                    bhSetMemPvpTexture(mwP->stg_texP, (unsigned char*)(((int)pacP + next) + 4), 0); 
                }
            }
            
            MapFuncAlloc(FsubMapDraw, 0);
            
            MapTagInit(64);
            
            mwP->map_mode = MP_MOD_VEW_NORMAL;
        } 
        else 
        {
            mwP->map_mode = MP_MOD_WAIT_NOMAP;
        }
        
        break;
    }
    case MP_MOD_VEW_NORMAL:
        MapEntryTask(FtskMapNormal, MP_MOD_VEW_ZOOM, 0);
        
        mwP->map_mode = MP_MOD_WAIT_NORMAL;
        break;
    case MP_MOD_VEW_ZOOM:
        MapEntryTask(FtskMapZoom, MP_MOD_VEW_NORMAL, 0);
        
        mwP->map_mode = MP_MOD_WAIT_ZOOM;
        break;
    case MP_MOD_WAIT_NOMAP:
        MapDrawMessage(mwP->ply_rom, 160.0f, 220.0f);
    case MP_MOD_WAIT_NORMAL:
    case MP_MOD_WAIT_ZOOM:
    {
        NJS_POINT3* dstP, *srcP; 

        srcP = &mwP->vew_pos;
        dstP = &mwP->dst_pos;
            
        srcP->x      += 0.5f * (dstP->x      - srcP->x);
        mwP->vew_zom += 0.5f * (mwP->dst_zom - mwP->vew_zom);
        srcP->z      += 0.5f * (dstP->z      - srcP->z);
        
        if ((mwP->pad_ps & 0x3000)) 
        {
            CallSystemSe(0, 0);
            
            bhSetScreenFade(0xFF000000, 8.0f);
            
            mwP->map_mode = MP_MOD_WAIT;
            
            MapEntryTask(FtskMapExit, MP_MOD_EXIT, 0);
            
            mwP->status |= 0x400;
        }
        
        break;
    }
    case MP_MOD_EXIT:
        bol = 0;
        break;
    }
    
    mwP->time++;
    
    MapPadMain();
    MapViewMain();
    MapLightMain();
    MapPaletteMain();
    
    MapFuncExec();
    
    return bol;
}

// 100% matching!
static void MapPadMain()
{
    if ((mwP->status & 0x400)) 
    {
        mwP->pad_ps = 0;
        
        mwP->pad_ax = mwP->pad_ay = 0;
        mwP->pad_al = mwP->pad_ar = 0;
        return;
    }
    
    mwP->pad_ps = sys->pad_ps;
    
    mwP->pad_al = sys->pad_al;
    mwP->pad_ar = sys->pad_ar;
    
    if ((sys->pad_ax > 40.0f) || (sys->pad_ax < -40.0f))
    {
        mwP->pad_ax = sys->pad_ax;
    }
    else 
    {
        mwP->pad_ax = 0;
    }
    
    if ((sys->pad_ay > 40.0f) || (sys->pad_ay < -40.0f))
    {
        mwP->pad_ay = sys->pad_ay;
    }
    else
    {
        mwP->pad_ay = 0;
    }
}

// 100% matching!
static void MapViewMain()
{
    NJS_MATRIX* mtxP;

    mtxP = mwP->vew_mtxP;
    
    njUnitMatrix(mtxP);
    
    njRotateX(mtxP, 32768);
    
    njTranslate(mtxP, 0, 0, -mwP->vew_zom);
    
    njRotateZ(mtxP, -mwP->vew_ang[2]);
    njRotateX(mtxP, -mwP->vew_ang[0]);
    njRotateY(mtxP, -mwP->vew_ang[1]);
    
    njTranslate(mtxP, -mwP->vew_pos.x, -mwP->vew_pos.y, -mwP->vew_pos.z);
}

// 99.61% matching
static void MapLightMain()
{
	int pitch, yaw;
    float scl;

    njCnkSetEasyMultiLightSwitch(1, 1);
    njCnkSetEasyMultiAmbient(mwP->ar, mwP->ag, mwP->ab);
    
    mwP->lgt_scale = mwP->map_scale;
    
    yaw   = mwP->yaw;
    pitch = mwP->pitch;
    
    scl = 1.0f / mwP->map_scale;
    
    njCnkSetEasyMultiLightVector(-njSin(yaw) * njCos(pitch), njSin(pitch), -njCos(yaw) * njCos(pitch));
    njCnkSetEasyMultiLightColor(1, mwP->pr * scl, mwP->pg * scl, mwP->pb * scl);
    
    njPushMatrix(mwP->vew_mtxP);
    
    njCnkSetEasyMultiLightMatrices();
    
    njPopMatrixEx();
}

// 100% matching!
static void MapPaletteMain()
{
    NJS_ARGB* srcP, *dstP;
    int i;

    njMemCopy4(mwP->MapPal, MapPal, 64);
    njMemCopy4(mwP->MapCol, MapCol, 3);
    
    srcP = &MapPal[16];
    dstP = &mwP->MapPal[16];
    
    for (i = 4; i > 0; i--, srcP++, dstP++) 
    {
        float rate;
        
        rate = 2.0f + njSin((mwP->time + (i * 4)) * 1024);
        rate = 0.3333f * rate;
        
        dstP->a = srcP->a;
        dstP->r = srcP->r * rate;
        dstP->g = srcP->g * rate;
        dstP->b = srcP->b * rate;
    } 
    
    for (i = 4; i > 0; i--, srcP++, dstP++)
    {
        float rate;
        
        rate = 2.0f + njSin((mwP->time + (i * 4)) * 2048);
        rate = 0.3333f * rate;
        
        dstP->a = srcP->a;
        dstP->r = srcP->r * rate;
        dstP->g = srcP->g * rate;
        dstP->b = srcP->b * rate;
    } 
    
    for (i = 4; i > 0; i--, srcP++, dstP++)
    {
        float rate;
        
        rate = 2.0f + njSin((mwP->time + (i * 4)) * 4096);
        rate = 0.3333f * rate;
        
        dstP->a = srcP->a;
        dstP->r = srcP->r * rate;
        dstP->g = srcP->g * rate;
        dstP->b = srcP->b * rate;
    }
    
    for (i = 4; i > 0; i--, srcP++, dstP++) 
    {
        float rate;

        rate = 2.0f + njSin(mwP->time * 4096);
        rate = 0.3333f * rate;
        
        dstP->a = srcP->a * rate;
        dstP->r = srcP->r * rate;
        dstP->g = srcP->g * rate;
        dstP->b = srcP->b * rate;
    } 
}

// 100% matching!
static void MapCodeProcess()
{
    short* ocP;         
    int* stsP;          
    NJS_CNK_OBJECT* objP;
    int mode;             
    unsigned char typ;   // needs use  
    //unsigned char typ; // needs use
    float scl;     
    float x, y, z;    // not from DWARF
    float xx, yy, zz; // not from DWARF
	static const int SndTbl[1] = { 0x80000247 };
    
    ocP  = mwP->map_cdeP;
    stsP = &mwP->status;
    
    njControl3D(0x810);
    
    njSetConstantAttr(-1, 0x800);
    
    njPushMatrixEx();
    
    njUnitMatrix(NULL);
    
    njScale(NULL, 1.0f, mwP->lgt_scale, 1.0f);
    
    while ((mode = *ocP) != 2) 
    {
        ocP++;
        
        switch (mode & 0xFFF) 
        {
        case 3:
            objP = mwP->map_objP + *ocP++;
            
            mwP->cur_objP = objP;
            
            njPushMatrixEx();
            
            njTranslate(NULL, objP->pos[0], objP->pos[1], objP->pos[2]);
            njRotateXYZ(NULL, objP->ang[0], objP->ang[1], objP->ang[2]);
            
            njGetMatrix(mwP->cur_mtxP);
            
            njPopMatrixEx();
            break;
        case 4:
            mode = *ocP++;
            
            njPushMatrix(mwP->vew_mtxP);
            njMultiMatrix(NULL, mwP->cur_mtxP);
            
            if (mwP->cur_objP->model != NULL) 
            {
                if (((mwP->status & 0x200)) && (mwP->chk_rom == mwP->bnk_tag_rom))
                {
                    if ((mode == 1) || (mode == 2) || (mode == 24)) 
                    {
                        mode = mwP->bnk_tag_pal;
                    }
                    else if ((mode == 7) || (mode == 8) || (mode == 25)) 
                    {
                        mode = mwP->bnk_tag_pal_wal;
                    } 
                }
                
                njSetConstantMaterial(&mwP->MapPal[mode]);
                
                njCnkEasyMultiDrawModel(mwP->cur_objP->model);
            }
            
            njPopMatrixEx();
            break;
        case 5:
        {
            int mrk_no;       
            NJS_POINT3 pos;    
                
            mrk_no = ocP[0];
            
            pos.x = ocP[1] / 32.0f;
            pos.y = ocP[2] / 32.0f;
            
            scl = ocP[3];
            
            ocP += 4;
            
            pos.z = scl / 32.0f;
            
            MapDrawMarker(mrk_no, &pos, -1);
            break;
        }
        case 7:
        {
            int ax, ay, az;           
            
            ax = ocP[0];
            ay = ocP[1];
            az = ocP[2];
            
            ocP += 3;
            
            njRotateXYZ(mwP->cur_mtxP, ax, ay, az);
            break;
        }
        case 6:
        {
            float tx, ty, tz;            
            
            tx = ocP[0] / 32.0f;
            ty = ocP[1] / 32.0f;
            tz = ocP[2] / 32.0f;
            
            ocP += 3;
            
            njTranslate(mwP->cur_mtxP, tx, ty, tz);
            break;
        }
        case 11:
        {
            int ck_rom;         
            
            ck_rom = *ocP++;
            
            if ((mwP->ply_flr == mwP->map_flr) && (mwP->rom_no == ck_rom))
            {
                MapBoolSet(1, mode & 0xF000);
            }  
            else 
            {
                MapBoolSet(0, mode & 0xF000);
            }
            
            mwP->chk_rom = ck_rom;
            break;
        }
        case 12:
            MapBoolSet(bhFlagCk(*ocP++, *ocP++, 0), mode & 0xF000);
            break;
        case 13:
            x = ocP[0] / 32.0f;
            y = ocP[1] / 32.0f;
            z = ocP[2] / 32.0f;
            
            xx = ocP[3] / 32.0f;
            yy = ocP[4] / 32.0f;
            zz = ocP[5] / 32.0f;
            
            ocP += 6;
            
            if (((x <= plp->px) && (plp->px <= xx)) && ((y <= plp->py) && (plp->py <= yy)) && ((z <= plp->pz) && (plp->pz <= zz))) 
            {
                MapBoolSet(1, mode & 0xF000);
            }
            else
            {
                MapBoolSet(0, mode & 0xF000);
            }
            
            break;
        case 8:
            if (mwP->cde_bol == 0)
            {
                ocP++;
            } 
            else 
            {
                ocP = &mwP->map_cdeP[*ocP];
            }
            
            break;
        case 9:
            if (mwP->cde_bol != 0)
            {
                ocP++;
            } 
            else
            {
                ocP = &mwP->map_cdeP[*ocP];
            }
            
            break;
        case 10:
            ocP = &mwP->map_cdeP[*ocP];
            break;
        case 14:
            MapBoolSet(bhFlagSet(*ocP++, *ocP++, 0), mode & 0xF000);
            break;
        case 15:
            if (!(*stsP & 0x40))
            {
                *stsP |= 0x40;
                
                mwP->vew_pos.x = 10.0f * (ocP[0] / 32.0f);
                mwP->vew_pos.y = 10.0f * (ocP[1] / 32.0f);
                mwP->vew_pos.z = 10.0f * (ocP[2] / 32.0f);
                mwP->vew_zom   = 10.0f * (ocP[3] / 32.0f);
                
                ocP += 4;
                
                mwP->vew_min.y = 0.3333f * mwP->vew_zom;
                mwP->vew_max.y = 1.5f    * mwP->vew_zom;
                
                MapViewMain();
                
                scl = 1.0f;
                scl = (scl * mwP->vew_mtxP[0][14]) / _nj_screen_.dist;
                
                mwP->vew_min.x = mwP->vew_pos.x - (320.0f * scl);
                mwP->vew_max.x = mwP->vew_pos.x + (320.0f * scl);
                
                mwP->vew_min.z = mwP->vew_pos.z - (240.0f * scl);
                mwP->vew_max.z = mwP->vew_pos.z + (240.0f * scl);
                
                mwP->vew_pos_bak = mwP->vew_pos;
                mwP->vew_zom_bak = mwP->vew_zom;
            } 
            else
            {
                ocP += 4;
            }
            
            break;
        case 16:
        {
            int rom_no;         
            NJS_POINT3 pos;     
                
            if (!(*stsP & 0x100))
            {
                rom_no = ocP[0];
                
                pos.x = ocP[1] / 32.0f;
                pos.y = ocP[2] / 32.0f;
                
                scl = ocP[3];
                
                ocP += 4;
                
                pos.z = scl / 32.0f;
                
                MapTagEntry(mwP->cur_mtxP, rom_no, &pos);
            } 
            else 
            {
                ocP += 4;
            }
            
            break;
        }
        case 17:
        {
            int mrk_no, pal_no;        
            NJS_POINT3 pos;     
                
            mrk_no = ocP[0];
            pal_no = ocP[1];
            
            pos.x = ocP[2] / 32.0f;
            pos.y = ocP[3] / 32.0f;
            
            scl = ocP[4];
            
            ocP += 5;
            
            pos.z = scl / 32.0f;
            
            MapDrawMarker(mrk_no, &pos, pal_no);
            break;
        }
        case 18:
        {
            int snd_no; 
            int bnk_tim, off_tim; 
            
            snd_no = ocP[0];
            
            bnk_tim = ocP[1];
            off_tim = ocP[2];
            
            ocP += 3;
            
            if (((off_tim + mwP->time) % bnk_tim) == 0)
            {
                CallSystemSe(0, SndTbl[snd_no]);
            }
            
            break;
        }
        case 0:
        case 1:
        case 2:
            break;
        } 
    }
                    
    njPopMatrixEx();
    
    njControl3D(0);
}

// 100% matching!
static void MapBoolSet(int bol, int mod) 
{
    switch (mod) 
    {                                 
    case 0:
        mwP->cde_bol = bol;
        break;
    case 0x4000:
        mwP->cde_bol &= bol;
        break;
    case 0x8000:
        mwP->cde_bol |= bol;
        break;
    }
}

// 100% matching!
static void MapDrawMarker(int mrk_no, NJS_POINT3* posP, int pal_no)
{
	MA_WORK* maP;
	static MA_WORK MrkAtr[6] = 
    {
        { 0, 3.0f, 24.0f, 16 }, { 1, 3.0f, 20.0f, 28 }, { 1, 3.0f, 16.0f, 13 },
        { 1, 3.0f, 12.0f, 14 }, { 3, 1.0f, 12.0f, 30 }, { 2, 2.0f,  8.0f, 31 }
    };

    switch (mrk_no)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        maP = &MrkAtr[mrk_no];
        
        if (pal_no == -1) 
        {
            pal_no = maP->pal_no;
        }
        
        njSetConstantMaterial(&mwP->MapPal[pal_no]);
        
        njPushMatrix(mwP->vew_mtxP);
        
        njMultiMatrix(NULL, mwP->cur_mtxP);
        
        if (mrk_no == 0) 
        {
            if (mwP->ply_flr == mwP->map_flr)
            {
                njTranslate(NULL, plp->px, plp->py + maP->offset, plp->pz);
                njRotateXYZ(NULL, plp->ax, plp->ay, plp->az);
                
                njScale(NULL, maP->scale, 1.0f, maP->scale);
                
                njCnkEasyMultiDrawObject(mwP->MrkMdl[maP->mrk_no].objP);
            }
        } 
        else 
        {
            njTranslate(NULL, posP->x, posP->y + maP->offset, posP->z);
            
            njScale(NULL, maP->scale, 1.0f, maP->scale);
            
            njCnkEasyMultiDrawObject(mwP->MrkMdl[maP->mrk_no].objP);
        }
        
        njPopMatrixEx();
        break;
    case 6:
        posP->z -= 1.0f;
        
        MapDrawSprite(posP, -1, MP_SPR_TITLE);
        break;
    }
}

// 100% matching!
static void MapDrawBackground(float depth, NJS_POINT2* p0P, NJS_POINT2* p1P)
{
    NJS_POINT2 p0, p1;
    float dst;     
    
    MapDrawFill(p0P, p1P, depth, mwP->MapCol[0].color);
    
    p0.x = ceilf(-16.0f + p0P->x);
    p0.y = ceilf(p0P->y);
    
    p1.x = floorf(p1P->x);
    p1.y = p0.y;
    
    dst = floorf(p1P->y);
    
    while (p0.y <= dst) 
    {
        MapDrawLine(&p0, &p1, 20.0f + depth, mwP->MapCol[1].color);
        
        p0.y += 32.0f;
        p1.y += 32.0f;
    }
    
    p0.x = ceilf(-16.0f + p0P->x);
    p0.y = ceilf(p0P->y);
    
    p1.x = p0.x;
    p1.y = floorf(p1P->y);
    
    dst = floorf(p1P->x);
    
    while (p0.x <= dst)
    {
        MapDrawLine(&p0, &p1, 20.0f + depth, mwP->MapCol[1].color);
        
        p0.x += 32.0f;
        p1.x += 32.0f;
    }
}

// 97.04% matching
static void MapDrawSprite(NJS_POINT3* posP, int col, mp_spr spr_no)
{
    NJS_SPRITE* sprP;
	NJS_ARGB* mtrP;
	static const NJS_TEXANIM TexAnm[18] = 
    {
        {  40,  56, 20, 26,   0,   0,  80, 112, 0, 0 },
        {  32,  16, 16,  8, 192,   0, 256,  32, 0, 0 },
        {  32,  16, 15,  8, 256,  32, 192,   0, 0, 0 },
        {  16,  32,  8, 15, 160,   0, 192,  64, 0, 0 },
        {  16,  32,  8, 16, 192,  64, 160,   0, 0, 0 },
        {  24,  24, 12, 12, 208,  80, 256, 128, 0, 0 },
        {  24,  24, 12, 12, 208, 128, 256, 176, 0, 0 },
        {  24,  24, 12, 12, 208,  32, 256,  80, 0, 0 },
        {  88,  32, 41, 16,   0, 128, 176, 192, 0, 0 },
        {  88,  16,  0,  8,   0, 192, 176, 224, 0, 0 },
        {  40,  16,  0,  8,  96,  64, 176,  96, 0, 0 },
        {  40,  16,  0,  8,  96,  96, 176, 128, 0, 0 },
        { 104,  16,  0,  8,   0, 224, 208, 256, 0, 0 },
        {  16,  16,  7,  7, 224, 224, 256, 256, 0, 0 },
        {  24,  16,  0, 16,  96,   0, 144,  32, 0, 0 },
        {  24,  16,  0, 16,  96,   0, 144,  32, 0, 0 },
        {  24,  16, 24,  0,  96,  32, 144,  64, 0, 0 },
        { 128, 128,  0,  0,   0,   0, 256, 256, 0, 0 }
    };

    sprP = &mwP->map_spr;
    mtrP = &mwP->map_mtr;
    
    sprP->ang = 0;
    
    sprP->sx = 1.0f;
    sprP->sy = 1.0f;
    
    sprP->p.x = posP->x;
    sprP->p.y = posP->y;
    
    sprP->tanim = (NJS_TEXANIM*)&TexAnm[spr_no];
    
    if (spr_no < 17) 
    {
        sprP->tlist = mwP->map_texP;
    } 
    else 
    {
        sprP->tlist = mwP->stg_texP;
    }
    
    mtrP->b = (float)(col & 0xFF) * (1.0 / 255.0);
    col >>= 8;
    
    mtrP->g = (float)(col & 0xFF) * (1.0 / 255.0);
    col >>= 8;
    
    mtrP->r = (float)(col & 0xFF) * (1.0 / 255.0);
    col >>= 8;
    
    mtrP->a = (float)(col & 0xFF) * (1.0 / 255.0);
    
    njSetConstantMaterial(mtrP);
    
    njDrawSprite2D(sprP, 0, posP->z, 0x22);
}

// 100% matching!
static int MapGetFloorNo(void* datP, int rom_no, float pos_y)
{
    int high;  
    float key;  
    int low;    
    FT_WRK* ftP; 
    int middle;  

    low  = 0;
    high = ((short*)datP)[3] - 1;
    
    key = 100.0f * rom_no;
    
    ftP = (FT_WRK*)((int)datP + ((short*)datP)[2]);
    
    do 
    {
        middle = (low + high) / 2;
        
        if ((key + pos_y) <= ftP[middle].label) 
        {
            high = middle;
        }
        else
        {
            low = middle;
        }
    } while ((high - low) != 1);
    
    if (ftP[high].label < (100.0f * rom_no)) 
    {
        return -1;
    }
    
    return (ftP[high].map_no << 16) | ftP[high].flr_no;
}

// 100% matching!
static void MapPurgeTree(ML_WORK* mlwP)
{
    NJS_CNK_OBJECT* objP; 
    NJS_MATRIX* mtxP;    
    int obj_num;         
    
    objP = mlwP->objP;
    mtxP = lcmat;
    
    njPushMatrixEx();
    
    njUnitMatrix(NULL);
    
    for (obj_num = mlwP->obj_num; obj_num > 0; obj_num--, objP++) 
    {
        if (objP->sibling != NULL)
        {
            njPushMatrixEx();
        }
        
        njTranslate(NULL, objP->pos[0], objP->pos[1], objP->pos[2]);
        njRotateXYZ(NULL, objP->ang[0], objP->ang[1], objP->ang[2]);
        
        njGetMatrix(mtxP);
        
        objP->ang[0] = 10430.381f * atan2f(mtxP[0][6], mtxP[0][10]);
        objP->ang[1] = 10430.381f * asinf(-mtxP[0][2]);
        objP->ang[2] = 10430.381f * atan2f(mtxP[0][1], mtxP[0][0]);
        
        objP->pos[0] = mtxP[0][12];
        objP->pos[1] = mtxP[0][13];
        objP->pos[2] = mtxP[0][14];
        
        if (objP->child == NULL) 
        {
            njPopMatrixEx();
        }
        
        objP->child   = NULL;
        objP->sibling = NULL;
    } 
    
    njPopMatrixEx();
}

// 100% matching! 
static void MapFuncInit(int func_num) 
{
    func_wrk_typ* fwP; 

    fwP = mwP->busy_funcP = (func_wrk_typ*)bhGetFreeMemory((func_num + 2) * 64, 4);
    
    fwP->nextP = fwP->prevP = fwP;
    
    mwP->free_funcP = ++fwP;
    
    fwP->nextP = fwP->prevP = fwP;
    
    fwP++; 
    
    for ( ; func_num > 0; func_num--, fwP++) 
    {
        MapFuncIns(mwP->free_funcP, fwP);
    }
}

// 100% matching!
static func_wrk_typ* MapFuncAlloc(int(*funcP)(func_wrk_typ*), int param0) 
{
    func_wrk_typ* fwP;
    
    fwP = mwP->free_funcP->nextP;
    
    MapFuncDel(fwP);
    MapFuncIns(mwP->busy_funcP, fwP);
    
    fwP->funcP = funcP;
    
    fwP->mode = 0;
    
    fwP->param0 = param0;
    fwP->param1 = 0;
    fwP->param2 = 0;
    
    fwP->FreeWrk[0] = fwP->FreeWrk[1] = fwP->FreeWrk[2] = fwP->FreeWrk[3] = 0;
    fwP->FreeWrk[4] = fwP->FreeWrk[5] = fwP->FreeWrk[6] = fwP->FreeWrk[7] = 0;
    
    fwP->FreeWrk[8] = 0;
    
    return fwP;
}

// 100% matching!
static void MapFuncFree(func_wrk_typ* fwP) 
{
    MapFuncDel(fwP);
    MapFuncIns(mwP->free_funcP, fwP);
}

// 100% matching!
static void MapFuncDel(func_wrk_typ* fwP)
{
    fwP->prevP->nextP = fwP->nextP;
	fwP->nextP->prevP = fwP->prevP;
}

// 100% matching!
static func_wrk_typ* MapFuncIns(func_wrk_typ* bsP, func_wrk_typ* fwP)
{
    fwP->nextP = bsP->nextP;
    fwP->prevP = bsP;
    
    bsP->nextP->prevP = fwP;
    bsP->nextP        = fwP;

    // no return 
}

// 100% matching!
static void MapFuncExec() 
{
    func_wrk_typ* fwP, *nxP;

    for (nxP = mwP->busy_funcP->nextP; nxP != mwP->busy_funcP; nxP = fwP) 
    {
        fwP = nxP->nextP;
        
        if (nxP->funcP != NULL) 
        {
            nxP->funcP(nxP);
        }
    }
}

// 100% matching!
static int FsubMapDraw(func_wrk_typ* fwP)
{
    tag_wrk_typ* curP; // not from DWARF

    if (mwP->map_mode == MP_MOD_MAP_READ) 
    {
        mwP->map_objP = NULL;
        mwP->map_cdeP = NULL;
        
        MapFuncFree(fwP);
    } 
    else if ((mwP->map_objP != NULL) && (mwP->map_cdeP != NULL)) 
    {
        MapCodeProcess();
        
        if (!(mwP->status & 0x100)) 
        {
            mwP->status |= 0x100;
            
            curP = MapTagConnect(mwP->rom_no);
            
            mwP->cur_tagP = curP;
            
            if (curP == NULL) 
            {
                mwP->cur_tagP = MapTagCenter();
            }
        }
    }
    
    return 1;
}

// 100% matching!
static int FsubBackDraw() 
{
    MapDrawBackground(mwP->bck_depth, &mwP->bck_p0, &mwP->bck_p1);
    
    return 1;
}

// 100% matching!
static void MapEntrySprite(mp_set set_no, int mode)
{
    func_wrk_typ* fwP;
    SS_WORK* ssP;
    FSD_WORK* fsdP;
	static const SS_WORK SprSet[11] = 
    {
        { MP_SPR_SILHOUETTE,  (void*)FsprSilhouetteDraw, 1535, 0xFF004000, { 585.0f,  66.0f, -8.0f } },
        { MP_SPR_ARROW_UP,    (void*)FsprArrowDraw,      128,  0xFF008000, { 320.0f,  40.0f, -6.0f } },
        { MP_SPR_ARROW_DOWN,  (void*)FsprArrowDraw,      128,  0xFF008000, { 320.0f, 443.0f, -6.0f } },
        { MP_SPR_ARROW_LEFT,  (void*)FsprArrowDraw,      128,  0xFF008000, {  32.0f, 240.0f, -6.0f } },
        { MP_SPR_ARROW_RIGHT, (void*)FsprArrowDraw,      128,  0xFF008000, { 610.0f, 240.0f, -6.0f } },
        { MP_SPR_ARROW_UP,    (void*)FsprArrowDraw2,     256,  0xFF4050A0, { 320.0f,  40.0f, -6.0f } },
        { MP_SPR_ARROW_DOWN,  (void*)FsprArrowDraw2,     256,  0xFF4050A0, { 320.0f, 443.0f, -6.0f } },
        { MP_SPR_ARROW_LEFT,  (void*)FsprArrowDraw2,     256,  0xFF4050A0, {  32.0f, 240.0f, -6.0f } },
        { MP_SPR_ARROW_RIGHT, (void*)FsprArrowDraw2,     256,  0xFF4050A0, { 610.0f, 240.0f, -6.0f } },
        { MP_SPR_LR_ZOOM,     (void*)FsprSpriteDraw,     256,  0xFFFFFFFF, { 320.0f,  80.0f, -8.0f } },
        { MP_SPR_TITLE,       (void*)FsprSpriteDraw,     1120, 0xFFFFFFFF, {  64.0f,  32.0f, -8.0f } }
    };
    
    ssP = &SprSet[set_no];
    fwP = MapFuncAlloc(ssP->funcP, 0);
    
    if (fwP != NULL) 
    {
        fwP->param0 = (int)&mwP->map_mode;
        fwP->param1 = ssP->act_bit;
        fwP->param2 = ssP->spr_no;
        
        fwP->FreeWrk[0]                = ssP->spr_col;
        *(NJS_POINT3*)&fwP->FreeWrk[1] = *(NJS_POINT3*)&ssP->spr_pos;
        fwP->FreeWrk[4]                = mode;
    }
}

// 100% matching!
static int FsprSpriteDraw(FS_WORK* fsP) 
{
    FSD_WORK* fsdP;
    
    fsdP = (FSD_WORK*)&fsP->spr_dsp;

    if (!(fsP->spr_dsp.act_bit & (1 << *(fsP->spr_dsp.act_mdeP)))) 
    {
        MapFuncFree((func_wrk_typ*)fsP);
    } 
    else if (fsP->mode == 0) 
    {
        MapDrawSprite(&fsdP->spr_pos, fsdP->spr_col, fsdP->spr_no);
    }
    
    return 1;
}

// 100% matching!
static int FsprSilhouetteDraw(FS_WORK* fsP)
{
    FSD_WORK* fsdP; 
    FSC_WORK* fscP; 
    int bol;       
    int col_bak;    
 
    fsdP = &fsP->spr_dsp;
    fscP = &fsP->spr_cnt;
    
    bol = 1; 
    
    switch (fscP->spr_mde) 
    {                          
    case 0:
        col_bak = fsdP->spr_col;
        
        fscP->count++;
        
        if (++fscP->count >= 0xFF) 
        {
            fscP->count   = 0xFF;
            fscP->spr_mde = 1;
        }
        
        fsdP->spr_col = (fsdP->spr_col & 0xFFFFFF) | (fscP->count << 24);
        
        bol = FsprSpriteDraw(fsP);
        
        fsdP->spr_col = col_bak;
        break;
    case 1:
        bol = FsprSpriteDraw(fsP);
        break;
    }

    return bol; 
}

// 100% matching!
static int FsprArrowDraw(FS_WORK* fsP) 
{
    FSD_WORK* fsdP;   
    FSC_WORK* fscP;   
    int count;       
    NJS_POINT3 bak;    
    map_nxt* mnP;      
    int p_prs;        
    int* prmP;        
    mp_no cn_s, cn_d;        
    cnc_wrk_typ* dstP, *srcP; 
    int flr_top;       

    count = fsP->spr_cnt.count;
    
    bak = fsP->spr_dsp.spr_pos;
    
    fsdP = &fsP->spr_dsp; 
    fscP = &fsP->spr_cnt; 
    
    switch (fsP->spr_cnt.spr_mde) 
    {                              
    case 0:                                         
        fsdP->spr_pos.y -= 1.9f * njSin(count);
        break;
    case 1:                                         
        fsdP->spr_pos.y += 1.9f * njSin(count);
        break;
    case 2:                                         
        fsdP->spr_pos.x -= 1.9f * njSin(count);
        break;
    case 3:                                         
        fsdP->spr_pos.x += 1.9f * njSin(count);
        break;
    }
    
    fsdP->spr_pos.x = floorf(fsdP->spr_pos.x);
    fsdP->spr_pos.y = floorf(fsdP->spr_pos.y);
    
    FsprSpriteDraw(fsP);
    
    fsdP->spr_pos = bak;
    
    fscP->count = count + 910;
    
    if (fscP->count >= 32768) 
    {
        fscP->count -= 32768;
    }
    
    if (mwP->map_mode == MP_MOD_WAIT_NORMAL) 
    {
        mnP = &mwP->map_nxt;
        
        p_prs = mwP->pad_ps;
        
        prmP = NULL;
        
        switch (fscP->spr_mde)
        {                       
        case 0:                                     
            if ((p_prs & 0x1)) 
            {
                prmP = (int*)mnP;
            }
            
            break;
        case 1:                                     
            if ((p_prs & 0x2)) 
            {
                prmP = &mnP->map_down;
            }
            
            break;
        case 2:                                     
            if ((p_prs & 0x4))
            {
                prmP = &mnP->map_left;
            }
            
            break;
        case 3:                                     
            if ((p_prs & 0x8)) 
            {
                prmP = &mnP->map_right;
            }
            
            break;
        }
        
        if (prmP != NULL) 
        {
            CallSystemSe(0, 2);
            
            if (prmP[0] != 10) 
            {
                flr_top = 0;
            } 
            else 
            {
                flr_top = prmP[1];
            }
            
            dstP = MapCncGet(mwP->stg_no, mwP->flr_no);
            srcP = MapCncGet(prmP[0], flr_top);
            
            cn_d = mwP->stg_no * 16;
            cn_d = cn_d | mwP->flr_no;
            
            cn_s = prmP[0] * 16;
            cn_s = cn_s | flr_top;
            
            if ((fscP->spr_mde == 2) || (fscP->spr_mde == 3)) 
            {
                while (srcP != NULL) 
                {
                    MapCnc(cn_d, cn_s, dstP->status);
                    
                    srcP = srcP->flr_nextP;
                    
                    cn_s++;
                } 
            }
            
            mwP->stg_no = prmP[0];
            mwP->flr_no = prmP[1];
            
            mwP->map_mode = MP_MOD_MAP_READ;
        }
    }
    
    return 1;
}

// 100% matching!
static int FsprArrowDraw2(FS_WORK* fsP)
{
    FSD_WORK* fsdP;   
    FSC_WORK* fscP;   
    tag_wrk_typ* twP; 
    int count;        
    int tab;         
    NJS_POINT3 bak;   

    fsdP = &fsP->spr_dsp;
    fscP = &fsP->spr_cnt; 
    
    twP = mwP->fcs_tagP;
    
    count = fsP->spr_cnt.count;
    
    bak = fsdP->spr_pos; 
    
    switch (fsP->spr_cnt.spr_mde) 
    {                             
    case 0:
        fsdP->spr_pos.y -= 1.9f * njSin(count);
        
        tab = 3;
        break;
    case 1:
        fsdP->spr_pos.y += 1.9f * njSin(count);
        
        tab = 1;
        break;
    case 2:
        fsdP->spr_pos.x -= 1.9f * njSin(count);
        
        tab = 2;
        break;
    case 3:
        fsdP->spr_pos.x += 1.9f * njSin(count);
        
        tab = 0;
        break;
    }
    
    fsdP->spr_pos.x = floorf(fsdP->spr_pos.x);
    fsdP->spr_pos.y = floorf(fsdP->spr_pos.y);
    
    if (twP->tagPP[tab] != NULL) 
    {
        fsP->mode = 0;
    } 
    else 
    {
        fsP->mode = -1;
    }
    
    FsprSpriteDraw(fsP);
    
    fsdP->spr_pos = bak; 
    
    fscP->count = count + 910;
    
    if (fscP->count >= 32768) 
    {
        fscP->count -= 32768;
    }
    
    return 1;
}

// 100% matching!
static FT_WORK* MapEntryTask(int(*tskP)(FTS_WORK*), mp_mod chg_mde, int param0) 
{
    func_wrk_typ* fwP;
    FT_WORK* ftP;

    fwP = MapFuncAlloc((void*)FsubTaskMain, 0);
    ftP = NULL;
    
    if (fwP != NULL) 
    {
        fwP->param0 = (int)&mwP->map_mode;
        fwP->param1 = chg_mde; 
        fwP->param2 = (int)tskP;
        
        fwP->FreeWrk[0] = param0;

        ftP = (FT_WORK*)fwP;
        
        return ftP;
    }
    
    return ftP;
}

// 100% matching!
static int FsubTaskMain(FT_WORK* ftP) 
{
    if (ftP->tskP(&ftP->tsk_sub) == 0) 
    {
        *ftP->map_mdeP = ftP->chg_mde;
        
        MapFuncFree((func_wrk_typ*)ftP);
    }
    
    return 1;
}

// 100% matching!
static int FtskMapWait()
{
    int bol;

    bol = 1;
    
    if (!(sys->st_flg & 0x8)) 
    {
        bol = 0;
    }
    
    return bol;
}

// 100% matching!
static int FtskMapExit() 
{
    int bol;

    bol = 1;
    
    if (!(sys->cb_flg & 0x2)) 
    {
        bol = 0;
    }
    
    return bol;
}

// 100% matching!
static int FtskMapRead(FTS_WORK* ftsP) 
{
    int bol;

    bol = 1;
    
    switch (ftsP->param3) 
    {                          
    case 0:
        mwP->fil_mode = 0;
        
        ftsP->param3++;
    case 1:
        if (bhReadMapData((char*)ftsP->param0) != 0) 
        {
            bol = 0;
        }
        
        break;
    }
    
    return bol;
}

// 100% matching!
static int FtskMapNormal(FTS_WORK* ftsP)
{
    int bol;   
    map_nxt* mnP; 
    
    bol = 1;
    
    switch (ftsP->param3) 
    {                              
    case 0:
        CallSystemSe(0, 5);
        
        mwP->dst_pos = mwP->vew_pos_bak;
        mwP->dst_zom = mwP->vew_zom_bak;
        
        mnP = MapCheckNextMap(&mwP->map_nxt);
        
        if (mnP->map_up != -1) 
        {
            MapEntrySprite(MP_SET_ARROW_UP, 0);
        }
        
        if (mnP->map_down != -1) 
        {
            MapEntrySprite(MP_SET_ARROW_DOWN, 1);
        }
        
        if (mnP->map_left != -1) 
        {
            MapEntrySprite(MP_SET_ARROW_LEFT, 2);
        }
        
        if (mnP->map_right != -1) 
        {
            MapEntrySprite(MP_SET_ARROW_RIGHT, 3);
        }
        
        ftsP->param3++;
        break;
    case 1:
        if (mwP->map_mode == MP_MOD_MAP_READ) 
        {
            MapFuncFree((func_wrk_typ*)&ftsP[-1]);
        } 
        else if (((mwP->pad_ps & 0x100)) && (mwP->cur_tagP != NULL)) 
        {
            bol = 0;
        }
        
        break;
    }
    
    return bol;
}

// 100% matching!
static int FtskMapZoom(FTS_WORK* ftsP)
{
    int bol;           
    tag_wrk_typ* twP;  
    FG_WORK* fgP;       
    unsigned int p_prs; 
    
    bol = TRUE;
    
    switch (ftsP->param3)
    {                           
    case 0:
        CallSystemSe(0, 5);
        
        twP = mwP->cur_tagP;
        
        mwP->fcs_tagP = twP;
        
        mwP->status |= 0x200;
        
        mwP->bnk_tag_rom     = twP->rom_no;
        mwP->bnk_tag_pal     = 3;
        mwP->bnk_tag_pal_wal = 9;
        
        mwP->dst_zom = 0.5f * mwP->vew_zom_bak;
        
        mwP->dst_pos.x = twP->pos.x;
        mwP->dst_pos.y = twP->pos.y;
        mwP->dst_pos.z = twP->pos.z;
        
        MapFuncAlloc((void*)FsubZoomCursor,     0);
        MapFuncAlloc((void*)FsubZoomInfomation, 0);
        
        MapEntrySprite(MP_SET_LR_ZOOM,      0);
        MapEntrySprite(MP_SET_ARROW2_UP,    0);
        MapEntrySprite(MP_SET_ARROW2_DOWN,  1);
        MapEntrySprite(MP_SET_ARROW2_LEFT,  2);
        MapEntrySprite(MP_SET_ARROW2_RIGHT, 3);
        
        fgP = (FG_WORK*)MapFuncAlloc((void*)FsubGaugeDraw, 0);
        
        fgP->gge_pos.x = 57.0f;
        fgP->gge_pos.y = 416.0f;
        fgP->gge_pos.z = -6.0f;
        
        ftsP->param3 = 1; 
        break;
    case 1:
        p_prs = mwP->pad_ps;
        
        if (mwP->map_mode == MP_MOD_MAP_READ) 
        {
            MapFuncFree((func_wrk_typ*)&ftsP[-1]);
        } 
        else if ((p_prs & 0x100)) 
        {
            bol = FALSE;
            
            mwP->status &= ~0x200;
        } 
        else 
        {
            tag_wrk_typ* twP; 
            int tag;         

            twP = mwP->fcs_tagP;
            
            tag = -1;
            
            if ((p_prs & 0x8)) 
            {
                tag = 0;
            } 
            else if ((p_prs & 0x2)) 
            {
                tag = 1;
            } 
            else if ((p_prs & 0x4)) 
            {
                tag = 2;
            } 
            else if ((p_prs & 0x1)) 
            {
                tag = 3;
            }
            
            if (tag != -1) 
            {
                twP = twP->tagPP[tag];
                
                if (twP != NULL) 
                {
                    mwP->fcs_tagP = twP;
                    
                    mwP->bnk_tag_rom = twP->rom_no;
                    
                    mwP->dst_pos.x = twP->pos.x;
                    mwP->dst_pos.y = twP->pos.y;
                    mwP->dst_pos.z = twP->pos.z;
                    
                    CallSystemSe(0, 2);
                }
            }
            
            mwP->dst_zom += 0.05f * mwP->pad_al;
            mwP->dst_zom -= 0.05f * mwP->pad_ar;
         
            if (mwP->dst_zom < mwP->vew_min.y) 
            {
                mwP->dst_zom = mwP->vew_min.y;
            }
            
            if (mwP->dst_zom > mwP->vew_max.y)
            {
                mwP->dst_zom = mwP->vew_max.y;
            }
        }
        
        break;
    }
    
    return bol;
}

// 100% matching!
static int FsubGaugeDrawZ(FG_WORK* fgP)
{
    float scl;        
    NJS_COLOR col[2]; 
    NJS_POINT2 pnt[2]; 
    int cnt;         
    float pos, dsp;         
    float tmp;       
    float size;     
    float dist; // not from DWARF
    float yy;   // not from DWARF
	static NJS_POINT2COL p2c;

    dist = (_nj_screen_.dist * (5.0f / mwP->vew_mtxP[0][14])) / 5.0f;
    
    p2c.tex = NULL;
    p2c.p   = pnt;
    p2c.col = col;
    p2c.num = 1;
    
    yy = fgP->gge_pos.y - (100.0f * dist);
    
    col[0].color = col[1].color = mwP->MapCol[2].color;
    
    pnt[0].y = pnt[1].y = 0.5f + floorf(yy);
    
    pnt[0].x = floorf(fgP->gge_pos.x - 1.0f);
    pnt[1].x = 0.5f + floorf(fgP->gge_pos.x - 8.0f);
    
    njDrawLine2D(&p2c, p2c.num, fgP->gge_pos.z, 0);
    
    pnt[1].y = 0.5f + floorf(yy + (100.0f * dist));
    pnt[1].x = pnt[0].x;
    
    njDrawLine2D(&p2c, p2c.num, fgP->gge_pos.z, 0);
    
    pnt[0].y = pnt[1].y;
    pnt[0].x = 0.5f + floorf(fgP->gge_pos.x - 8.0f);
    
    njDrawLine2D(&p2c, p2c.num, fgP->gge_pos.z, 0);
    
    tmp = 1000.0f + ((mwP->vew_pos.z - 50.0f) / 5.0f);
    
    if (!njFraction(tmp)) 
    {
        cnt = tmp;
        
        pos = 0; 
    } 
    else 
    {
        cnt = ceilf(tmp);
        
        pos = 5.0f * (1.0f - njFraction(tmp));
    }
    
    for ( ; pos <= 100.0f; pos += 5.0f, cnt++)
    {
        if ((cnt % 10) == 0)
        {
            size = 9.0f;
        }
        else if ((cnt % 2) == 0) 
        {
            size = 5.0f;
        } 
        else 
        {
            size = 3.0f;
        }
        
        pnt[0].y = pnt[1].y = 0.5f + floorf(yy + (pos * dist));
        
        pnt[0].x = fgP->gge_pos.x;
        pnt[1].x = fgP->gge_pos.x + size;
        
        njDrawLine2D(&p2c, p2c.num, fgP->gge_pos.z, 0);
    }
    
    return 1;
}

// 100% matching!
static int FsubGaugeDrawX(FG_WORK* fgP)
{
    float scl;         
    NJS_COLOR col[2];  
    NJS_POINT2 pnt[2]; 
    int cnt;           
    float pos, dsp;         
    float tmp;        
    float size;        
    float dist; // not from DWARF
	static NJS_POINT2COL p2c;

    dist = 1.174f * ((_nj_screen_.dist * (5.0f / mwP->vew_mtxP[0][14])) / 5.0f);
    
    p2c.tex = NULL;
    p2c.p   = pnt;
    p2c.col = col;
    p2c.num = 1;
    
    dsp = fgP->gge_pos.x;
    
    col[0].color = col[1].color = mwP->MapCol[2].color;
    
    pnt[0].x = pnt[1].x = floorf(dsp) - 0.5f;
    
    pnt[0].y = floorf(1.0f + fgP->gge_pos.y);
    pnt[1].y = floorf(8.0f + fgP->gge_pos.y) - 0.5f;
    
    njDrawLine2D(&p2c, p2c.num, fgP->gge_pos.z, 0);
    
    pnt[1].x = 0.5f + floorf(dsp + (100.0f * dist));
    pnt[1].y = pnt[0].y;
    
    njDrawLine2D(&p2c, p2c.num, fgP->gge_pos.z, 0);
    
    pnt[0].x = pnt[1].x;
    pnt[1].y = floorf(8.0f + fgP->gge_pos.y) - 0.5f;
    
    njDrawLine2D(&p2c, p2c.num, fgP->gge_pos.z, 0);
    
    tmp = 1000.0f + ((mwP->vew_pos.x - 50.0f) / 5.0f);
    
    if (!njFraction(tmp))
    {
        cnt = tmp;
        
        pos = 0; 
    } 
    else
    {
        cnt = ceilf(tmp);
        
        pos = 5.0f * (1.0f - njFraction(tmp));
    }
    
    for ( ; pos <= 100.0f; pos += 5.0f, cnt++) 
    {
        if ((cnt % 10) == 0)
        {
            size = 9.0f;
        }
        else if ((cnt % 2) == 0) 
        {
            size = 5.0f;
        } 
        else 
        {
            size = 3.0f;
        }
        
        pnt[0].x = pnt[1].x = 0.5f + floorf(dsp + (pos * dist));
        
        pnt[0].y = fgP->gge_pos.y - size;
        pnt[1].y = fgP->gge_pos.y;
        
        njDrawLine2D(&p2c, p2c.num, fgP->gge_pos.z, 0);
    } 
    
    return 1;
}

// 86.86% matching
static int FsubGaugeDraw(FG_WORK* fgP)
{
    float scl_y;   
    NJS_POINT3 p0; 
    
    FsubGaugeDrawZ(fgP);
    FsubGaugeDrawX(fgP);
    
    scl_y = (_nj_screen_.dist * (5.0f / mwP->vew_mtxP[0][14])) / 5.0f;
    
    p0.x = 2.0f + fgP->gge_pos.x;
    p0.y = 8.0f + (fgP->gge_pos.y - (100.0f * scl_y));
    p0.z = fgP->gge_pos.z;
    
    MapDrawSprite(&p0, -1, MP_SPR_10M_L);
    
    p0.x = fgP->gge_pos.x - 2.0f;
    p0.y = 1.0f + fgP->gge_pos.y;
    p0.z = fgP->gge_pos.z;
    
    MapDrawSprite(&p0, -1, MP_SPR_0M);
    
    p0.x = (fgP->gge_pos.x + (100.0f * (1.174f * scl_y))) - 8.0f;
    p0.y = fgP->gge_pos.y - 2.0f;
    p0.z = fgP->gge_pos.z;
    
    MapDrawSprite(&p0, -1, MP_SPR_10M_D);
    
    if (mwP->map_mode != MP_MOD_WAIT_ZOOM)
    {
        MapFuncFree((func_wrk_typ*)fgP);
    }
    
    return 1;
}

// 100% matching!
static void MapTagInit(int tag_num)
{
    mwP->tag_num = 0;
    mwP->tag_wrkP = (tag_wrk_typ*)bhGetFreeMemory(tag_num * 32, 4);
}

// 100% matching!
static void MapTagEntry(NJS_MATRIX* basP, int rom_no, NJS_POINT3* posP)
{
    tag_wrk_typ* twP;

    twP = &mwP->tag_wrkP[mwP->tag_num++];
    
    twP->rom_no = rom_no;   
    
    if (basP != NULL) 
    {
        njCalcPoint(basP, posP, &twP->pos);
    }
    else 
    {
        twP->pos = *posP;
    } 
}

// 100% matching!
static tag_wrk_typ* MapTagConnect(int rom_no)
{
    int dir;          
    float d;           
	float dst[4];      
    int i;             
	tag_wrk_typ* rtnP, *basP, *twP; 
	int num;           
    
    num = mwP->tag_num;
    
    basP = mwP->tag_wrkP;
    rtnP = NULL;
    
    for (i = num; i > 0; i--, basP++) 
    {
        twP = mwP->tag_wrkP;
        
        dst[0] = dst[1] = dst[2] = dst[3] = 999999.0f;
        
        basP->tagPP[0] = basP->tagPP[1] = basP->tagPP[2] = basP->tagPP[3] = NULL;
        
        for (num = mwP->tag_num; num > 0; num--, twP++)
        {
            if (basP != twP) 
            {
                d = ((twP->pos.x - basP->pos.x) * (twP->pos.x - basP->pos.x)) + ((twP->pos.z - basP->pos.z) * (twP->pos.z - basP->pos.z));
                
                dir = (((int)(10430.381f * atan2f(twP->pos.z - basP->pos.z, twP->pos.x - basP->pos.x)) + 8192) / 16384) & 3;
                
                if (d < dst[dir]) 
                {
                    dst[dir] = d;
                    
                    basP->tagPP[dir] = twP;
                }
            }
        }
        
        if (basP->rom_no == rom_no) 
        {
            rtnP = basP;
        }
    } 
    
    return rtnP;
}

// 99.40% matching
static tag_wrk_typ* MapTagCenter()
{
    int num;            
    float f_num;       
    tag_wrk_typ* twP;   
    float dst;          
    int i; // not from DWARF
    tag_wrk_typ* rtnP;  
    float d;            
    float dz, dx; // not from DWARF

    dx = dz = 0;

    num = mwP->tag_num;
    twP = mwP->tag_wrkP;
    
    f_num = 1.0f / num;

    rtnP = twP;
    
    for (i = num; i > 0; i--, rtnP++)
    {
        dx += rtnP->pos.x;
        dz += rtnP->pos.z;
    }
    
    dx *= f_num;
    dz *= f_num;

    dst = 999999.0f;
    
    rtnP = NULL;
    
    for ( ; num > 0; num--, twP++)
    {
        d = ((twP->pos.x - dx) * (twP->pos.x - dx)) + ((twP->pos.z - dz) * (twP->pos.z - dz));
        
        if (d < dst)
        {
            dst = d;
            
            rtnP = twP;
        }
    }
    
    return rtnP;
}

// 100% matching!
static void MapDrawLine2(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal) 
{
    static NJS_COLOR col[2];
    static NJS_POINT2 pnt[2];
    static NJS_POINT2COL p2c = { pnt, col, NULL, 1 };

    pnt[0].x = srcP->x;
    pnt[0].y = srcP->y;

    pnt[1].x = dstP->x;
    pnt[1].y = dstP->y;

    col[0].color = col[1].color = pal;

    njDrawLine2D(&p2c, p2c.num, pri, 0x40);
}

// 100% matching!
static void MapDrawLine(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal)
{ 
    static NJS_COLOR col[2];
    static NJS_POINT2 pnt[2];
    static NJS_POINT2COL p2c = { pnt, col, NULL, 1 };

    pnt[0].x = 0.5f + floorf(srcP->x);
    pnt[0].y = 0.5f + floorf(srcP->y);
    
    pnt[1].x = 0.5f + floorf(dstP->x);
    pnt[1].y = 0.5f + floorf(dstP->y);
    
    col[0].color = col[1].color = pal;

    njDrawLine2D(&p2c, p2c.num, pri, 0);
}

// 100% matching!
static void MapDrawFill(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal) 
{
    static NJS_POINT2 pnt[4];
    
    pnt[0].x = srcP->x;
    pnt[0].y = srcP->y;

    pnt[1].x = dstP->x;
    pnt[1].y = srcP->y;
    
    pnt[2].x = dstP->x;
    pnt[2].y = dstP->y;
    
    pnt[3].x = srcP->x;
    pnt[3].y = dstP->y;
    
    MapDrawPolyFill(pnt, pri, pal);
}

// 100% matching!
static void MapDrawPolyFill(NJS_POINT2* pnt, float pri, int pal) 
{
    static NJS_COLOR col[4];
    static NJS_POINT2COL p2c = { NULL, col, NULL, 4 };

    p2c.p = pnt;
    
    col[0].color = col[1].color = col[2].color = col[3].color = pal;
    
    njDrawPolygon2D(&p2c, p2c.num, pri, 0x60);
}

// 100% matching!
static void MapDrawMessage(int rom, float x, float y) // parameters not present on DWARF
{

}

// 91.09% matching
static int FsubZoomCursor(FZ_WORK* fzP)
{
    static const NJS_POINT2 dst_pos0[4] = 
    {
        {  56.0f,  64.0f },
        { 585.0f,  64.0f },
        {  56.0f,  64.0f },
        {  56.0f, 417.0f }
    };
    static const NJS_POINT2 dst_pos1[4] = 
    {
        {  56.0f, 240.0f },
        { 585.0f, 240.0f },
        { 320.0f,  64.0f },
        { 320.0f, 417.0f }
    };
    static const NJS_POINT2 dst_pos2[4] =
    {
        {  56.0f, 417.0f },
        { 585.0f, 417.0f },
        { 585.0f,  64.0f },
        { 585.0f, 417.0f }
    };
    NJS_COLOR col1, col2; // not from DWARF

    switch (fzP->mode) 
    {                           
    case 0:
        fzP->time = 0;
        
        fzP->pos_a0 = dst_pos0[0];
        fzP->pos_a1 = dst_pos0[1];
        
        fzP->pos_b0 = dst_pos0[2];
        fzP->pos_b1 = dst_pos0[3];
        
        fzP->dstP = dst_pos1;
        
        fzP->mode++;
    case 1:
        if (fzP->time <= 0) 
        {
            MapDrawMessage(mwP->fcs_tagP->rom_no, 48.0f, 425.0f);
        } 
        else
        {
            fzP->time--;
        }
        
        if (mwP->map_mode != MP_MOD_WAIT_ZOOM) 
        {
            fzP->dstP = dst_pos2;
            
            fzP->time = 5;
            
            fzP->mode = 2;
        }
        
        break;
    case 2:
        if (fzP->time < 0) 
        {
            MapFuncFree((func_wrk_typ*)fzP);
        } 
        else 
        {
            fzP->time--;
        }
        
        break;
    }
    
    col1 = MapCnvArgb2Color(&mwP->MapPal[19]);
    MapDrawLine(&fzP->pos_a0, &fzP->pos_a1, -7.0f, col1.color);
    
    col2 = MapCnvArgb2Color(&mwP->MapPal[19]);
    MapDrawLine(&fzP->pos_b0, &fzP->pos_b1, -7.0f, col2.color);
    
    fzP->pos_a0.x += ceilf(0.5f * (fzP->dstP->x - fzP->pos_a0.x));
    fzP->pos_a0.y += ceilf(0.5f * (fzP->dstP->y - fzP->pos_a0.y));
    
    fzP->pos_a1.x += ceilf(0.5f * (fzP->dstP[1].x - fzP->pos_a1.x));
    fzP->pos_a1.y += ceilf(0.5f * (fzP->dstP[1].y - fzP->pos_a1.y));
    
    fzP->pos_b0.x += ceilf(0.5f * (fzP->dstP[2].x - fzP->pos_b0.x));
    fzP->pos_b0.y += ceilf(0.5f * (fzP->dstP[2].y - fzP->pos_b0.y));
    
    fzP->pos_b1.x += ceilf(0.5f * (fzP->dstP[3].x - fzP->pos_b1.x));
    fzP->pos_b1.y += ceilf(0.5f * (fzP->dstP[3].y - fzP->pos_b1.y));
    
    return 1;
}

// 100% matching!
static int FsubZoomInfomation(FI_WORK* fiP) 
{
    NJS_POINT3 pos;
	static const NJS_POINT3 set_pos = 
    {
        441.0f, 353.0f, -8.0f
    };
    NJS_COLOR col1, col2, col3; // not from DWARF
    
    switch (fiP->mode) 
    {                              
    case 0:
        fiP->pos0 = set_pos;
        
        fiP->pos1.x = 585.0f;
        fiP->pos1.y = 417.0f;
        
        fiP->time = 0;
        
        fiP->mode++;
    case 1:
        if (fiP->time <= 0) 
        {
            MapDrawFill((NJS_POINT2*)&fiP->pos0, &fiP->pos1, fiP->pos0.z, 0x80000000);
            
            pos.x = 16.0f + fiP->pos0.x;
            pos.y = 16.0f + fiP->pos0.y;
            pos.z = 1.0f  + fiP->pos0.z;
            
            col1 = MapCnvArgb2Color(&mwP->MapPal[28]);
            MapDrawSprite(&pos, col1.color, MP_SPR_DIAMOND);
            
            pos.x += 16.0f;
            
            MapDrawSprite(&pos, -1, MP_SPR_ITEM);
            
            pos.y += 16.0f;
            pos.x -= 16.0f;
            
            col2 = MapCnvArgb2Color(&mwP->MapPal[13]);
            MapDrawSprite(&pos, col2.color, MP_SPR_DIAMOND);
            
            pos.x += 16.0f;
            
            MapDrawSprite(&pos, -1, MP_SPR_SAVEPOINT);
            
            pos.y += 16.0f;
            pos.x -= 16.0f;
                
            col3 = MapCnvArgb2Color(&mwP->MapPal[14]);
            MapDrawSprite(&pos, col3.color, MP_SPR_DIAMOND);
            
            pos.x += 16.0f;
            MapDrawSprite(&pos, -1, MP_SPR_ITEM);
            
            pos.x += 48.0f;
            MapDrawSprite(&pos, -1, MP_SPR_BOX);
        } 
        else 
        {
            fiP->time--;
        }
        
        if (mwP->map_mode != MP_MOD_WAIT_ZOOM) 
        {
            MapFuncFree((func_wrk_typ*)fiP);
        }
        
        break;
    }
    
    return 1;
}

// 100% matching!
static NJS_COLOR MapCnvArgb2Color(NJS_ARGB* argbP)
{
    NJS_COLOR col;
    
    col.argb.a = 255.0f * argbP->a;
    col.argb.r = 255.0f * argbP->r;
    col.argb.g = 255.0f * argbP->g;
    col.argb.b = 255.0f * argbP->b;

    return col;
}

// 100% matching!
static int FsubZoomScreen(FS_WRK* fsP) 
{
    int ang; 
    int tmp; 
    static const NJS_POINT2 ScrOut[2] = 
    {
        { 0.0f,   0.0f   },
        { 640.0f, 480.0f }
    };
    static const NJS_POINT2 ScrIn[2] = 
    {
        {  56.0f,  64.0f },
        { 585.0f, 417.0f }
    };
	static NJS_POINT2 pnt[4];

    switch (fsP->mode) 
    {                             
    case 0:
        fsP->pos0 = ScrIn[0];
        fsP->pos1 = ScrIn[1];
        
        fsP->rad = 32.0f;
        
        fsP->ang = 8192;
        
        fsP->mode++;
    case 1:
        pnt[0] = ScrOut[0];
        pnt[1] = ScrOut[0];
        
        pnt[1].x = fsP->pos1.x - fsP->rad;
        
        pnt[2] = pnt[1];
        
        pnt[2].y = fsP->pos0.y;
        
        pnt[3] = pnt[0];

        pnt[3].y = fsP->pos0.y;
        
        MapDrawPolyFill(pnt, -8.0f, 0x80000000);
        MapDrawLine2(&fsP->pos0, &pnt[2], -7.0f, -0xFFA000);
        
        ang = 16384;
        
        do 
        {
            pnt[0].x = pnt[3].x = fsP->pos1.x + (fsP->rad * njCos(ang));
            pnt[0].y = pnt[3].y = fsP->pos0.y + (fsP->rad * njSin(ang));
            
            tmp = ang + fsP->ang;
            
            pnt[1].x = pnt[2].x = fsP->pos1.x + (fsP->rad * njCos(tmp));
            pnt[1].y = pnt[2].y = fsP->pos0.y + (fsP->rad * njSin(tmp));
            
            MapDrawLine2(pnt, &pnt[1], -7.0f, -0xFFA000);
            
            if (ang >= 32768) 
            {
                if ((unsigned short)ang < 32768) 
                {
                    pnt[2].y = pnt[3].y = ScrOut[1].y;
                } 
                else 
                {
                    pnt[0].y = pnt[1].y = ScrOut[0].y;
                }
                
                MapDrawPolyFill(pnt, -8.0f, 0x80000000);
            }
            
            ang = tmp;
        } while (tmp < 81920);
        
        MapDrawLine2(&pnt[1], &fsP->pos1, -7.0f, -0xFFA000);
        
        pnt[3].x = pnt[0].x = fsP->pos1.x + fsP->rad;
        pnt[0].y = pnt[1].y = ScrOut[0].y;
        
        pnt[1].x = pnt[2].x = ScrOut[1].x;
        pnt[2].y = pnt[3].y = ScrOut[1].y;
        
        MapDrawPolyFill(&pnt[0], -8.0f, 0x80000000);
        
        pnt[3].x = pnt[0].x = fsP->pos0.x;
        pnt[0].y = pnt[1].y = fsP->pos1.y;
        
        pnt[1].x = pnt[2].x = fsP->pos1.x;
        pnt[2].y = pnt[3].y = ScrOut[1].y;
        
        MapDrawPolyFill(&pnt[0], -8.0f, 0x80000000);
        MapDrawLine2(&pnt[1], &pnt[0], -7.0f, -0xFFA000);
        
        pnt[3].x = pnt[0].x = ScrOut[0].x;
        pnt[0].y = pnt[1].y = fsP->pos0.y;
        
        pnt[1].x = pnt[2].x = fsP->pos0.x;
        pnt[2].y = pnt[3].y = ScrOut[1].y;
        
        MapDrawPolyFill(&pnt[0], -8.0f, 0x80000000);
        
        pnt[2].y = fsP->pos1.y;
        
        MapDrawLine2(&pnt[1], &pnt[2], -7.0f, -0xFFA000);
        
        pnt[0].x = ScrOut[0].x;
        pnt[1].x = fsP->pos0.x;
        
        pnt[0].y = pnt[1].y = 240.0f;
        
        MapDrawLine(&pnt[0], &pnt[1], -7.0f, -0xFFA000);
        
        pnt[0].x = fsP->pos1.x;
        pnt[1].x = ScrOut[1].x;
        
        MapDrawLine(&pnt[0], &pnt[1], -7.0f, -0xFFA000);
        
        pnt[0].x = pnt[1].x = 320.0f;
        
        pnt[0].y = ScrOut[0].y;
        pnt[1].y = fsP->pos0.y;
        
        MapDrawLine(&pnt[0], &pnt[1], -7.0f, -0xFFA000);
        
        pnt[0].y = fsP->pos1.y;
        pnt[1].y = ScrOut[1].y;
        
        MapDrawLine(&pnt[0], &pnt[1], -7.0f, -0xFFA000);
        break;
    }
    
    return 1;
}

// 100% matching!
static int FsubCompass(FC_WORK* fcP)
{
    static const NJS_POLYGON_VTX CmpArw[4] = 
    {
        {   0.0f, -30.0f, 0.0f, 0x6000C000 }, { -12.0f, -22.0f, 0.0f, 0x6000C000 },
        {  12.0f, -22.0f, 0.0f, 0x6000C000 }, {   0.0f,  30.0f, 0.0f, 0x6000C000 }
    }; 
    
    switch (fcP->mode) 
    {               
    case 0:
        fcP->pos.x = 585.0f;
        fcP->pos.y = 62.0f;
        fcP->pos.z = -4.0f;
        
        fcP->scl_y = fabsf(-4.0f) / _nj_screen_.dist;
        fcP->scl_x = fcP->scl_y / 1.174f;
        
        fcP->pos.x = (fcP->pos.x - 320.0f) * fcP->scl_x;
        fcP->pos.y = (240.0f - fcP->pos.y) * fcP->scl_y;
        
        fcP->ang = 0;
        
        fcP->mode++;
    case 1:
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateX(NULL, 32768);
        
        njTranslateEx(&fcP->pos);
        
        njScale(NULL, fcP->scl_y, fcP->scl_y, fcP->scl_y);
        
        njRotateY(NULL, fcP->ang += 1456); // the second parameter here is written in an unusual form
        
        njDrawPolygon3DEx(CmpArw, 4, 1);
        
        njPopMatrixEx();
        break;
    }
    
    return 1;
}

// 100% matching!
static int FsubModeMessage(FM_WORK* fmP)
{
    int typ;
    MD_WORK* mdP;
	static const MD_WORK NmlMes[2] = 
    {
        { { 464.0f, 441.0f, -7.0f }, 5 },
        { { 480.0f, 441.0f, -7.0f }, 9 }
    };
    
    typ = sys->keytype;
    
    if (typ > 2)
    {
        typ = 0;
    }
    
    switch (fmP->mode) 
    {
    case 0:
        fmP->mdP = NmlMes;
        mdP      = fmP->mdP;
        
        if (mdP != NULL)
        {
            MapDrawSprite(&mdP[0].pos, -1, mdP[0].spr + typ);
            MapDrawSprite(&mdP[1].pos, -1, mdP[1].spr);
        }
        
        break;
    }
    
    return 1;
}

// 100% matching!
static void MapCncInit(int map_num, int flr_num)
{
    int map_no, flr_no;
	cnc_wrk_typ* cwP;
	
    mwP->cnc_map = map_num;
    mwP->cnc_flr = flr_num;
    
    map_num *= flr_num;
    
    mwP->cnc_wrkP = (cnc_wrk_typ*)bhGetFreeMemory(map_num * 28, 4);
    
    for (map_no = 0; map_no < map_num; map_no++)
    {
        for (flr_no = 0; flr_no < flr_num; flr_no++) 
        {
            cwP = MapCncGet(map_no, flr_no);
            
            cwP->map_no = map_no;
            cwP->flr_no = flr_no;
            
            cwP->status = 0;
        } 
    } 
}

// 100% matching!
static cnc_wrk_typ* MapCncGet(int map_no, int flr_no)
{
    map_no *= mwP->cnc_flr;
    map_no += flr_no;
    
    return &mwP->cnc_wrkP[map_no];
}

// 68.79% matching
static void MapCnc(mp_no dst, mp_no src, int status)
{
	// modified order of local variables in regards to DWARF
    cnc_wrk_typ* srcP, *dstP; 
    int dst_map;       
	int src_flr, src_map;     
	int dst_flr;     
	static const int AdjMapA[3] = { 64, 128, 832 };
    
    dst_flr = dst / 16;
    dst_map = dst & 0xF;

    src_flr = src / 16;
    src_map = src & 0xF;
    
    dstP = MapCncGet(dst_flr, dst_map);
    srcP = MapCncGet(src_flr, src_map);
    
    dst_flr *= 256;
    src_flr *= 256;
    
    if (src_flr == 2560) 
	{
        src_flr = AdjMapA[src_map];
    }

    if (dst_flr == 2560) 
	{
        dst_flr = AdjMapA[dst_map];
    }

    if (src_flr == 512) 
	{
        src_flr = 896;
    }

    if (dst_flr == 512) 
	{
        dst_flr = 896;
    }

    if (dst_flr == src_flr) 
	{
        if (dst_map < src_map) 
		{
            srcP->flr_prevP = dstP;
        } 
		else if (dst_map > src_map) 
		{
            srcP->flr_nextP = dstP;
        }
    } 
	else if (dst_flr < src_flr) 
	{
        srcP->map_prevP = dstP;
    }
	else 
	{
        srcP->map_nextP = dstP;
    }

    dstP->status = status;
}

// 81.59% matching (matches on NGC)
static void MapCncConnect(const unsigned short* datP) 
{
    int sts;          
    int dat_u;  
    int dat_l;        
    unsigned short dat; 

    sts = 0;

    while (TRUE)
    {
        dat = *datP++;
        
        dat_l = dat >> 8;
        dat_u = (unsigned char)dat;
        
        if (dat_l == 255) 
        {
            if (dat_u == 255)
            { 
                break;
            }

            if (bhFlagCk(8, dat_u, 0) != 0)
            {
                sts = 1;
            } 
            else
            {
                sts = 0;
            }
        } 
        else 
        {
            MapCnc(dat_l, dat_u, sts);
        }
    }
}

// 92.80% matching (matches on NGC)
static map_nxt* MapCheckNextMap(map_nxt* mnP)
{
    cnc_wrk_typ* curP, *cwP;

    curP = MapCncGet(mwP->stg_no, mwP->flr_no);
    
    for (cwP = curP->flr_nextP; cwP != NULL; cwP = cwP->flr_nextP)
    {
        if (cwP->status != 0)
        {
            break;
        }
    }
    
    if (cwP == NULL) 
    {
        mnP->map_up = -1;
    }
    else 
    {
        mnP->map_up = cwP->map_no;
        mnP->flr_up = cwP->flr_no;
    }

    for (cwP = curP->flr_prevP; cwP != NULL; cwP = cwP->flr_prevP)
    {
        if (cwP->status != 0) 
        {
            break;
        }
    }
    
    if (cwP == NULL) 
    {
        mnP->map_down = -1;
    } 
    else 
    {
        mnP->map_down = cwP->map_no;
        mnP->flr_down = cwP->flr_no;
    }

    for (cwP = curP->map_prevP; cwP != NULL; cwP = cwP->map_prevP)
    {
        if (cwP->status != 0) 
        {
            break;
        }
    }
    
    if (cwP == NULL) 
    {
        mnP->map_left = -1;
    } 
    else
    {
        mnP->map_left = cwP->map_no;
        mnP->flr_left = cwP->flr_no;
    }
    
    for (cwP = curP->map_nextP; cwP != NULL; cwP = cwP->map_nextP)
    {
        if (cwP->status != 0) 
        {
            break;
        }
    }
    
    if (cwP == NULL)
    {
        mnP->map_right = -1;
    } 
    else 
    {
        mnP->map_right = cwP->map_no;
        mnP->flr_right = cwP->flr_no;
    }

    return mnP;
}

// 100% matching!
static int GetGameMode()
{
    if (sys->stg_no >= 7) 
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
