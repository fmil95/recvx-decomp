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

// 
// Start address: 0x2c8b80
void CountDisplay(int disppoint, NJS_POINT2* pos, unsigned int col, int param) // fourth parameter is not present on the debugging symbols      
{
	//_anon26 uv[4];
	//_anon26 col_[4];
	//_anon5 p[4];
	//_anon43 p2c;
	// Line 2757, Address: 0x2c8b80, Func Offset: 0
	// Line 2764, Address: 0x2c8b94, Func Offset: 0x14
	// Line 2765, Address: 0x2c8bb8, Func Offset: 0x38
	// Line 2767, Address: 0x2c8bc0, Func Offset: 0x40
	// Line 2768, Address: 0x2c8bc8, Func Offset: 0x48
	// Line 2769, Address: 0x2c8bd0, Func Offset: 0x50
	// Line 2770, Address: 0x2c8bd8, Func Offset: 0x58
	// Line 2771, Address: 0x2c8be0, Func Offset: 0x60
	// Line 2773, Address: 0x2c8be4, Func Offset: 0x64
	// Line 2790, Address: 0x2c8bec, Func Offset: 0x6c
	// Line 2789, Address: 0x2c8bf0, Func Offset: 0x70
	// Line 2771, Address: 0x2c8bf4, Func Offset: 0x74
	// Line 2772, Address: 0x2c8bf8, Func Offset: 0x78
	// Line 2789, Address: 0x2c8bfc, Func Offset: 0x7c
	// Line 2800, Address: 0x2c8c04, Func Offset: 0x84
	// Line 2772, Address: 0x2c8c10, Func Offset: 0x90
	// Line 2773, Address: 0x2c8c14, Func Offset: 0x94
	// Line 2800, Address: 0x2c8c18, Func Offset: 0x98
	// Line 2773, Address: 0x2c8c24, Func Offset: 0xa4
	// Line 2774, Address: 0x2c8c2c, Func Offset: 0xac
	// Line 2775, Address: 0x2c8c34, Func Offset: 0xb4
	// Line 2776, Address: 0x2c8c40, Func Offset: 0xc0
	// Line 2777, Address: 0x2c8c4c, Func Offset: 0xcc
	// Line 2778, Address: 0x2c8c54, Func Offset: 0xd4
	// Line 2780, Address: 0x2c8c5c, Func Offset: 0xdc
	// Line 2781, Address: 0x2c8c60, Func Offset: 0xe0
	// Line 2782, Address: 0x2c8c64, Func Offset: 0xe4
	// Line 2789, Address: 0x2c8c68, Func Offset: 0xe8
	// Line 2778, Address: 0x2c8c6c, Func Offset: 0xec
	// Line 2783, Address: 0x2c8c70, Func Offset: 0xf0
	// Line 2790, Address: 0x2c8c74, Func Offset: 0xf4
	// Line 2792, Address: 0x2c8c78, Func Offset: 0xf8
	// Line 2793, Address: 0x2c8c84, Func Offset: 0x104
	// Line 2794, Address: 0x2c8c8c, Func Offset: 0x10c
	// Line 2795, Address: 0x2c8c98, Func Offset: 0x118
	// Line 2796, Address: 0x2c8ca4, Func Offset: 0x124
	// Line 2797, Address: 0x2c8cac, Func Offset: 0x12c
	// Line 2800, Address: 0x2c8cb4, Func Offset: 0x134
	// Line 2803, Address: 0x2c8cbc, Func Offset: 0x13c
	// Func End, Address: 0x2c8cd4, Func Offset: 0x154
	scePrintf("CountDisplay - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x2c8e50
void TypeWriterTextureInit()
{
	unsigned int dt;
	unsigned char* datp;
	int sz;
	//_anon2* tw;
	// Line 3232, Address: 0x2c8e50, Func Offset: 0
	// Line 3233, Address: 0x2c8e60, Func Offset: 0x10
	// Line 3237, Address: 0x2c8e6c, Func Offset: 0x1c
	// Line 3239, Address: 0x2c8e98, Func Offset: 0x48
	// Line 3240, Address: 0x2c8eb0, Func Offset: 0x60
	// Line 3241, Address: 0x2c8ec8, Func Offset: 0x78
	// Line 3243, Address: 0x2c8ecc, Func Offset: 0x7c
	// Line 3241, Address: 0x2c8ed4, Func Offset: 0x84
	// Line 3243, Address: 0x2c8edc, Func Offset: 0x8c
	// Line 3244, Address: 0x2c8ee8, Func Offset: 0x98
	// Line 3249, Address: 0x2c8ef0, Func Offset: 0xa0
	// Line 3252, Address: 0x2c8ef8, Func Offset: 0xa8
	// Line 3249, Address: 0x2c8f00, Func Offset: 0xb0
	// Line 3252, Address: 0x2c8f14, Func Offset: 0xc4
	// Line 3249, Address: 0x2c8f18, Func Offset: 0xc8
	// Line 3252, Address: 0x2c8f24, Func Offset: 0xd4
	// Line 3253, Address: 0x2c8f38, Func Offset: 0xe8
	// Line 3255, Address: 0x2c8f40, Func Offset: 0xf0
	// Line 3253, Address: 0x2c8f4c, Func Offset: 0xfc
	// Line 3254, Address: 0x2c8f64, Func Offset: 0x114
	// Line 3255, Address: 0x2c8f84, Func Offset: 0x134
	// Line 3256, Address: 0x2c8f94, Func Offset: 0x144
	// Line 3255, Address: 0x2c8f98, Func Offset: 0x148
	// Line 3268, Address: 0x2c8fa4, Func Offset: 0x154
	// Line 3269, Address: 0x2c8fac, Func Offset: 0x15c
	// Line 3271, Address: 0x2c8fb0, Func Offset: 0x160
	// Line 3273, Address: 0x2c8fb8, Func Offset: 0x168
	// Line 3274, Address: 0x2c8fc8, Func Offset: 0x178
	// Line 3282, Address: 0x2c8fd0, Func Offset: 0x180
	// Line 3274, Address: 0x2c8fd4, Func Offset: 0x184
	// Line 3281, Address: 0x2c8fe4, Func Offset: 0x194
	// Line 3275, Address: 0x2c8fe8, Func Offset: 0x198
	// Line 3276, Address: 0x2c8fec, Func Offset: 0x19c
	// Line 3277, Address: 0x2c8ff0, Func Offset: 0x1a0
	// Line 3278, Address: 0x2c8ff4, Func Offset: 0x1a4
	// Line 3281, Address: 0x2c8ff8, Func Offset: 0x1a8
	// Line 3283, Address: 0x2c900c, Func Offset: 0x1bc
	// Line 3285, Address: 0x2c9014, Func Offset: 0x1c4
	// Line 3286, Address: 0x2c9024, Func Offset: 0x1d4
	// Line 3287, Address: 0x2c9038, Func Offset: 0x1e8
	// Line 3292, Address: 0x2c9040, Func Offset: 0x1f0
	// Line 3295, Address: 0x2c905c, Func Offset: 0x20c
	// Line 3292, Address: 0x2c9060, Func Offset: 0x210
	// Line 3295, Address: 0x2c906c, Func Offset: 0x21c
	// Line 3296, Address: 0x2c9088, Func Offset: 0x238
	// Line 3298, Address: 0x2c908c, Func Offset: 0x23c
	// Line 3300, Address: 0x2c9094, Func Offset: 0x244
	// Line 3301, Address: 0x2c90a4, Func Offset: 0x254
	// Line 3302, Address: 0x2c90bc, Func Offset: 0x26c
	// Line 3303, Address: 0x2c90c0, Func Offset: 0x270
	// Line 3305, Address: 0x2c90c8, Func Offset: 0x278
	// Line 3306, Address: 0x2c90d8, Func Offset: 0x288
	// Line 3311, Address: 0x2c90ec, Func Offset: 0x29c
	// Line 3314, Address: 0x2c9108, Func Offset: 0x2b8
	// Line 3311, Address: 0x2c910c, Func Offset: 0x2bc
	// Line 3314, Address: 0x2c9118, Func Offset: 0x2c8
	// Line 3315, Address: 0x2c9154, Func Offset: 0x304
	// Line 3316, Address: 0x2c9158, Func Offset: 0x308
	// Line 3317, Address: 0x2c9160, Func Offset: 0x310
	// Line 3319, Address: 0x2c9164, Func Offset: 0x314
	// Line 3321, Address: 0x2c916c, Func Offset: 0x31c
	// Line 3322, Address: 0x2c917c, Func Offset: 0x32c
	// Line 3323, Address: 0x2c9190, Func Offset: 0x340
	// Line 3328, Address: 0x2c9198, Func Offset: 0x348
	// Line 3331, Address: 0x2c91b4, Func Offset: 0x364
	// Line 3328, Address: 0x2c91b8, Func Offset: 0x368
	// Line 3331, Address: 0x2c91c4, Func Offset: 0x374
	// Line 3332, Address: 0x2c91e0, Func Offset: 0x390
	// Line 3333, Address: 0x2c91e8, Func Offset: 0x398
	// Line 3332, Address: 0x2c91ec, Func Offset: 0x39c
	// Line 3335, Address: 0x2c9204, Func Offset: 0x3b4
	// Line 3337, Address: 0x2c920c, Func Offset: 0x3bc
	// Line 3338, Address: 0x2c922c, Func Offset: 0x3dc
	// Line 3339, Address: 0x2c9230, Func Offset: 0x3e0
	// Line 3338, Address: 0x2c923c, Func Offset: 0x3ec
	// Line 3339, Address: 0x2c9240, Func Offset: 0x3f0
	// Line 3342, Address: 0x2c9248, Func Offset: 0x3f8
	// Line 3346, Address: 0x2c9270, Func Offset: 0x420
	// Line 3347, Address: 0x2c9280, Func Offset: 0x430
	// Line 3349, Address: 0x2c9294, Func Offset: 0x444
	// Line 3351, Address: 0x2c929c, Func Offset: 0x44c
	// Line 3355, Address: 0x2c92a8, Func Offset: 0x458
	// Line 3356, Address: 0x2c92c0, Func Offset: 0x470
	// Line 3357, Address: 0x2c92c4, Func Offset: 0x474
	// Line 3359, Address: 0x2c92cc, Func Offset: 0x47c
	// Line 3361, Address: 0x2c92d4, Func Offset: 0x484
	// Line 3360, Address: 0x2c92d8, Func Offset: 0x488
	// Line 3361, Address: 0x2c92dc, Func Offset: 0x48c
	// Line 3362, Address: 0x2c92e0, Func Offset: 0x490
	// Line 3366, Address: 0x2c9300, Func Offset: 0x4b0
	// Line 3367, Address: 0x2c9304, Func Offset: 0x4b4
	// Line 3369, Address: 0x2c930c, Func Offset: 0x4bc
	// Line 3370, Address: 0x2c9314, Func Offset: 0x4c4
	// Line 3371, Address: 0x2c9324, Func Offset: 0x4d4
	// Line 3372, Address: 0x2c9330, Func Offset: 0x4e0
	// Line 3375, Address: 0x2c9348, Func Offset: 0x4f8
	// Func End, Address: 0x2c935c, Func Offset: 0x50c
	scePrintf("TypeWriterTextureInit - UNIMPLEMENTED!\n");
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
