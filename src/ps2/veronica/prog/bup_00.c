#include "bup_00.h"
#include "ps2_LoadScreen.h"
#include "ps2_NaFog.h"
#include "ps2_NaMem.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_SaveScreen.h"
#include "pwksub.h"
#include "main.h"

/*char vmssyscmttbl[16];
int old_data_flg;*/
unsigned int InitFlag;
/*char bootcommenttbl[32][32];
_anon20* bip;
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
int space_pos[8][18];
unsigned short mesdeftbl[10];*/
typedef void (*TypewriterMode_proc)();
TypewriterMode_proc TypewriterMode[3] = { TypewriterInit, TypewriterMain, TypewriterExit };
/*unsigned char* img1p;
_anon44 hdr00;
_anon20* binfo_;
unsigned char* img2p;
unsigned char* img3p;
unsigned char* img4p;
unsigned int palbuf[0];
_anon11* rom;*/
LOAD_SCREEN* pLoad;
LOAD_SCREEN Load;
SAVE_SCREEN* pSave;
SAVE_SCREEN Save;
/*int ErrorCode;
_anon44 hdr01;
_anon54 Info;
char bootcommentbuf[32][15];*/

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

// 
// Start address: 0x2c8ce0
unsigned int RoomNameSwitch(unsigned int name)
{
	unsigned int roomnum;
	// Line 2810, Address: 0x2c8ce0, Func Offset: 0
	// Line 2813, Address: 0x2c8dc8, Func Offset: 0xe8
	// Line 2819, Address: 0x2c8dd0, Func Offset: 0xf0
	// Line 2822, Address: 0x2c8dd8, Func Offset: 0xf8
	// Line 2828, Address: 0x2c8de0, Func Offset: 0x100
	// Line 2831, Address: 0x2c8de8, Func Offset: 0x108
	// Line 2834, Address: 0x2c8df0, Func Offset: 0x110
	// Line 2837, Address: 0x2c8df8, Func Offset: 0x118
	// Line 2840, Address: 0x2c8e00, Func Offset: 0x120
	// Line 2843, Address: 0x2c8e08, Func Offset: 0x128
	// Line 2846, Address: 0x2c8e10, Func Offset: 0x130
	// Line 2849, Address: 0x2c8e18, Func Offset: 0x138
	// Line 2852, Address: 0x2c8e20, Func Offset: 0x140
	// Line 2855, Address: 0x2c8e28, Func Offset: 0x148
	// Line 2858, Address: 0x2c8e30, Func Offset: 0x150
	// Line 2861, Address: 0x2c8e38, Func Offset: 0x158
	// Line 2864, Address: 0x2c8e40, Func Offset: 0x160
	// Line 2873, Address: 0x2c8e48, Func Offset: 0x168
	// Func End, Address: 0x2c8e50, Func Offset: 0x170
	scePrintf("RoomNameSwitch - UNIMPLEMENTED!\n");
}

// 100% matching! 
void TypeWriterTextureInit()
{
    TYPEWRITER_WORK* tw; 
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
    TYPEWRITER_WORK* tw;

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
