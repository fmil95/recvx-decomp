#include "bup_00.h"
#include "effect.h"
#include "ps2_LoadScreen.h"
#include "ps2_NaDraw2D.h"
#include "ps2_NaFog.h"
#include "ps2_NaMem.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_SaveScreen.h"
#include "ps2_texture.h"
#include "pwksub.h"
#include "screen.h"
#include "sdfunc.h"
#include "main.h"

SAVE_SCREEN Save;
SAVE_SCREEN* pSave;
LOAD_SCREEN Load;
LOAD_SCREEN* pLoad;
static unsigned int InitFlag; 
unsigned short mesdeftbl[10] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 }; 
typedef void (*TypewriterMode_proc)();
TypewriterMode_proc TypewriterMode[3] = { TypewriterInit, TypewriterMain, TypewriterExit };
/* unused below */
/* char vmssyscmttbl[16]; 
int old_data_flg; 
char bootcommenttbl[32][32]; 
BACKUPINFO* bip; 
char StrBuf[128]; 
char ErrBuf[128]; 
char TwBuf[128]; 
char name_99[16]; 
unsigned char sys_icon_palette[32]; 
unsigned char sys_icon_data[512]; 
unsigned char cla_icon_palette[32]; 
unsigned char cla_icon_data[1536]; 
unsigned char chs_icon_palette[32]; 
unsigned char chs_icon_data[1536]; 
int space_pos[18][8]; 
unsigned char* img1p; 
BUS_BACKUPFILEHEADER hdr00; 
BACKUPINFO* binfo_; 
unsigned char* img2p; 
unsigned char* img3p; 
unsigned char* img4p; 
int ErrorCode; 
BUS_BACKUPFILEHEADER hdr01; 
BUS_FILEINFO Info; 
char bootcommentbuf[15][32]; */

// 100% matching!
void ControlTypewriter()
{
    TypewriterMode[sys->typ_md0](); 
}

// 100% matching! 
void TypewriterKeepMemory()
{
    sys->typ_exp = bhGetFreeMemory(800, 32);
}

// 100% matching! 
void CountDisplay(int disppoint, NJS_POINT2* pos, unsigned int col, int param) // fourth parameter is not present on the debugging symbols   
{
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];   
    NJS_COLOR col_[4]; 
    NJS_COLOR uv[4];   
	
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(0);
    
    p2c.p = p;
    
    p2c.col = col_;
    
    p2c.tex = uv;
    
    p2c.num = 1;
    
    p[0].x = pos->x;
    p[0].y = pos->y;
    
    p[1].x = 28.0f + pos->x;
    p[1].y = pos->y;
    
    p[2].x = 28.0f + pos->x;
    p[2].y = 28.0f + pos->y;
    
    p[3].x = pos->x;
    p[3].y = 28.0f + pos->y;
    
    col_[3].color = col_[2].color = col_[1].color = col_[0].color = col;
    
    uv[0].tex.u = disppoint * 14;
    uv[0].tex.v = 0; 
    
    uv[1].tex.u = uv[0].tex.u + 14; 
    uv[1].tex.v = uv[0].tex.v;
    
    uv[2].tex.u = uv[0].tex.u + 14;
    uv[2].tex.v = uv[0].tex.v + 14;
    
    uv[3].tex.u = uv[0].tex.u;
    uv[3].tex.v = uv[0].tex.v + 14; 
    
    njDrawPolygon2DM(&p2c, 4, -3.0f, 0x80000060);
}

// 100% matching!
unsigned int RoomNameSwitch(unsigned int name)
{
    unsigned int roomnum;

    switch (name)
    {
    case 0:
        roomnum = 0;
        break;
    case 1:
        roomnum = 1;
        break;
    case 108:
        roomnum = 2;
        break;
    case 311:
        roomnum = 3;
        break;
    case 500:
        roomnum = 4;
        break;
    case 604:
        roomnum = 5;
        break;
    case 709:
        roomnum = 6;
        break;
    case 722:
        roomnum = 7;
        break;
    case 904:
        roomnum = 8;
        break;
    case 914:
        roomnum = 9;
        break;
    case 4:
        roomnum = 10;
        break;
    case 921:
        roomnum = 11;
        break;
    case 600:
        roomnum = 12;
        break;
    case 724:
        roomnum = 13;
        break;
    case 404:
        roomnum = 14;
        break;
    case 804:
        roomnum = 15;
        break;
    case 304:
        roomnum = 16;
        break;
    case 702:
        roomnum = 17;
        break;
    case 207:
        roomnum = 18;
        break;
    default:
        roomnum = 0;
        break;
    }

    return roomnum;
}

// 100% matching! 
void TypeWriterTextureInit()
{
    TYP_WORK* tw; 
    int sz;              
    unsigned char* datp; 
    unsigned int dt;     
    
    tw = sys->typ_exp;
    
    switch (tw->mode_00)
    {
    case 0:
        sys->sbs_sp = sys->memp;
        
        if ((sys->ss_flg & 0x200))
        {
            sys->tk_flg |= 0x400000;
            
            sz = GetIsoFileSize("sysmes.ald");
            
            if (sz != 0)
            {
                sys->memp = (unsigned char*)((unsigned int)(sys->memp + 63) & ~0x3F);
                
                RequestReadIsoFile("sysmes.ald", sys->memp);
                
                sys->mes_ip = (unsigned int*)sys->memp;
                
                sys->memp += sz;
                
                sys->doordp = bhGetFreeMemory(172032, 32);
                
                tw->mode_00 = 1;
            }
        }
        else 
        {
            tw->mode_00 = 4;
        }
      
        break;
    case 1:
        if (GetReadFileStatus() == 0)
        {
            datp = (unsigned char*)sys->mes_ip;
            
            dt = *sys->mes_ip; 
            
            datp += 4; 
            
            sys->mes_ip = (unsigned int*)datp; 
            
            datp += dt; 
            
            sys->mes_sp = (unsigned int*)(datp + 4);
            
            tw->mode_00 = 2;
        }
        
        break;
    case 2:
        if ((GetReadFileStatus() == 0) && (GetInsideFileSize(sys->sys_partid, 1) != 0))
        {
            sys->memp = (unsigned char*)((unsigned int)(sys->memp + 63) & ~0x3F);
            
            RequestReadInsideFile(sys->sys_partid, 1, sys->memp);
            
            tw->mode_00 = 3;
        }
        
        break;
    case 3:
        if (GetReadFileStatus() == 0)
        {
            bhSetFontTexture(sys->memp);
            
            tw->mode_00 = 4;
        }
        
        break;
    case 4:
        if (!(sys->ss_flg & 0x200))
        {
            if (GetReadFileStatus() != 1)
            {
                sys->memp = (unsigned char*)((unsigned int)(sys->memp + 63) & ~0x3F);
                
                if (rom->mdl.texP != NULL)
                {
                    sys->memp = (unsigned char*)bhCopyTexmem2MainmemSub(rom->mdl.texP, (char*)sys->memp);
                }
                
                tw->mode_00 = 5;
            }
        }
        else
        {
            tw->mode_00 = 5;
        }
        
        break;
    case 5:
        if ((GetReadFileStatus() == 0) && (GetInsideFileSize(sys->itm_partid, 144) != 0))
        {
            sys->memp = (unsigned char*)((unsigned int)(sys->memp + 63) & ~0x3F);
            
            RequestReadInsideFile(sys->itm_partid, 144, sys->memp);
            
            sys->subtxp = sys->memp;
            
            tw->mode_00 = 6;
        }
        
        break;
    case 6:
        if ((!(sys->cb_flg & 0x2)) && (!(sys->ts_flg & 0x80)))
        {
            sys->ts_flg |= 0x80;
            
            njSetBackColor(0x00000000, 0x00000000, 0x00000000);
        }
        
        if ((GetReadFileStatus() == 0) && (!(sys->cb_flg & 0x2)))
        {
            if ((!(sys->ss_flg & 0x200)) && (rom->mdl.texP != NULL))
            {
                njReleaseTexture(rom->mdl.texP);
                
                bhGarbageTexture(NULL, 0);
            }
            
            njMemCopy4(&palbuf[3072], palbuf, 1024);
            
            tw->mode_00 = 7;
        }
        
        break;
    case 7:
        njSetPaletteMode(6);
        
        tw->twtx_list.textures = (void*)tw;
        
        tw->twtx_list.nbTexture = 3;
        
        bhSetMemPvpTexture(&tw->twtx_list, sys->subtxp, 0);
        
        tw->mode_00 = 8;
        break;
    case 8:
        tw->mode_00 = 9;
        
        sys->typ_md0 = 1;
        sys->typ_md1 = 0;
        
        njSetTexture(&sys->ef_tlist);
    }
}

// 100% matching!
void TypewriterInit()
{
    sys->typ_flg &= 0x1;
    
    TypeWriterTextureInit();
    
    if (sys->typ_md0 == 1) 
    {
        sys->typ_md1 = 0;
    }
    
    if (InitFlag == 0) 
    {
        if (!(sys->ss_flg & 0x200)) 
        {
            pSave = CreateSaveScreen(&Save, vwbmemp);
            
            sys->version = 10;
            
            sys->flr_no = plp->flr_no;
            
            sys->ply_stflg[sys->ply_id] = plp->stflg;
            
            sys->ply_pos.x = plp->px;
            sys->ply_pos.y = plp->py;
            sys->ply_pos.z = plp->pz;
            
            sys->ply_ang = plp->ay;
            
            sys->ply_wno[sys->ply_id] = plp->wpnr_no;
            
            sys->ply_hp[sys->ply_id] = plp->hp;
            
            InitFlag = 1;
        }
        else 
        {
            pLoad = CreateLoadScreen(&Load, NULL);
            
            InitFlag = 1;
        }
    }
}

// 100% matching!
void TypewriterMain()
{
     if (!(sys->ss_flg & 0x200))
     {
        ExecuteSaveScreen(pSave);
         
        if (pSave->usExitFlag == 1) 
        {
            sys->typ_md0 = 2;
            sys->typ_md1 = 0;
            
            sys->typ_flg |= 0x8;
            
            InitFlag = 0;
        }
    }
    else
     {
        ExecuteLoadScreen(pLoad);
         
        if (pLoad->usExitFlag == 1) 
        {
            sys->typ_md0 = 2;
            sys->typ_md1 = 0;
            
            InitFlag = 0;
        }
    }
}

// 100% matching! 
void TypewriterExit()
{
    TYP_WORK* tw;

    tw = sys->typ_exp;
    
    if ((sys->ss_flg & 0x200)) 
    {
        njReleaseTextureAll();
        
        sys->ss_flg &= ~0x40;
        
        switch (sys->typ_flg & 0x10) 
        {
        case 0x10:
            sys->tk_flg = 0x300010;
            break;
        default:
            sys->tk_flg = 0x300008;
            break;
        }
        
        sys->typ_flg = 0;
        
        sys->typ_md1 = sys->typ_md0 = 0;
        
        sys->ss_flg &= ~0x20000;
        sys->ss_flg &= ~0x10000;
        
        sys->memp = sys->sbs_sp;
        
        tw->mode_00 = 0;
    }
    else 
    {
        switch (sys->typ_md1)
        {                           
        case 0:
            tw->mode_00 = 0;
            
            sys->ss_flg &= ~0x20000;
            sys->ss_flg &= ~0x10000;
            
            njReleaseTexture(&tw->twtx_list);
            
            bhGarbageTexture(NULL, 0);
            
            bhSetScreenFade(sys->fade_pbk, 3.0f);
            
            switch (sys->typ_flg & 0x18) 
            {                         
            case 0x10:                                   
                sys->typ_md1 = 2;
                break;
            case 0x8:                                    
                sys->typ_md1 = 1;
                break;
            default:                                  
                sys->typ_md1 = 1;
                break;
            }
            
            break;
        case 1:
            if (rom->mdl.texP != NULL) 
            {
                bhCopyMainmem2Texmem(rom->mdl.texP);
            }
            
            njSetPaletteMode(2);
            
            njMemCopy4(palbuf, &palbuf[3072], 1024);
            
            sys->gm_flg |= 0x4;
            
            sys->memp = sys->sbs_sp;
            
            sys->sp_flg = -1;
            
            sys->bcl_ct = 0;
            
            sys->gm_flg |= 0x8000;
            
            sys->st_flg &= ~0x8000000;
            
            sys->cb_flg &= ~0x200000;
            
            sys->ts_flg |= 0x8000;
            sys->ts_flg &= ~0x80;
            
            sys->typ_flg = 0;
            
            sys->typ_md1 = sys->typ_md0 = 0;
            
            bhDrawScreenFade();
            
            sys->bcl_ct = 1;
            
            sys->gm_flg |= 0x8000;
            
            if ((sys->st_flg & 0x2)) 
            {
                njFogEnable();
            }
            
            break;
        case 2:
            njSetPaletteMode(2);
            
            njSetPaletteData(0, 1024, &palbuf[3072]);
            
            sys->sp_flg = -1;
            
            sys->bcl_ct = 0;
            
            sys->gm_flg |= 0x8000;
            
            sys->st_flg &= ~0x8000000;
            
            sys->cb_flg &= ~0x200000;
            
            sys->ts_flg |= 0x8000;
            sys->ts_flg &= ~0x80;
            
            sys->typ_flg = 0;
            
            sys->typ_md0 = 0;
            break;
        }
    }
}
