#include "ps2_dummy.h"
#include "ps2_loadtim2.h"
#include "ps2_NaDraw2D.h"
#include "ps2_NaMath.h"
#include "ps2_NaSystem.h"
#include "ps2_sg_pad.h"
#include "ps2_texture.h"
#include "main.h"

unsigned char* Ps2_MOVIE = &Ps2_PBUFF[1179648]; 
unsigned int Ps2_tex_load_tp_cancel;
/*unsigned int Ps2_highlight;
float Ps2_rand_seed[4];*/
unsigned int PS2_Render_tex_sub_flag;
unsigned int Ps2_ice_flag;
/*unsigned int Ps2_albinoid_flag;*/
unsigned char Ps2_tex_mem[10485760] __attribute__((aligned(64)));
/*float Ps2_zbuff_a;
float Ps2_zbuff_b;*/
unsigned int Ps2_use_pt_flag;
NJS_TEXMEMLIST* Ps2_now_tex;
unsigned int Ps2_ot_list_no;
void* Ps2_PP;
PS2_OT Ps2_ot_list[8192];
unsigned int Ps2_now_bank;
PS2_OT* Ps2_OT[4096][2] __attribute__((aligned(64)));
float Ps2AddPrimPrio;
PS2_TP_TAG Ps2_tp_tag[64];
PS2_TP_CACHE ps2_tp_cache[64];
unsigned int Ps2_tex_cache_num;
unsigned int Ps2_tex_cache_beflag[4];
void* Ps2_tex_cache_buff[4];
unsigned char Ps2_PBUFF[1835008] __attribute__((aligned(64)));
sceGsDBuffDc Db;
PS2_GS_SAVE Ps2_gs_save __attribute__((aligned(64)));
unsigned int Ps2_albinoid_flag;
unsigned int Ps2_sys_cnt;
/*_anon4* Ps2_tex_info;
unsigned long ulNaFogB;
unsigned long ulNaFogG;
unsigned long ulNaFogR;
unsigned int Ps2_divide_flag;
_anon19 Ps2_pad;*/
float Ps2_shadow_fog;
float Ps2_shadow_vec[4];
int Ps2_shadow_z;
/*int ViewType;
unsigned int palbuf[4096];
float mbuf[16][128];*/
NJS_MATRIX lcmat[12] __attribute__((aligned(64)));
//float cmmat[2][16] __attribute__((aligned(64))); // TODO: use this definition
float cmmat[16];
/*float cmmat[16][2];
float crmat[16];*/
Uint8* _BSG_END;
/*int _nj_tex_count;*/
NJS_VERTEX_BUF* _nj_vertex_buf_;
NJS_SCREEN _nj_screen_;
void (* VsyncFunc)();
void (* EorFunc)();
unsigned int Ps2_vcount;
unsigned int Ps2_dbuff;
unsigned int _nj_control_3d_flag_;
/*_anon28 _nj_screen_;*/
unsigned char Ps2_DRAW_TMP[16384];
/*unsigned int Ps2_sys_cnt;*/
unsigned int Ps2_njControl3D_flag;
/*unsigned int Ps2_dbuff;
unsigned int Ps2_vcount;
void(*VsyncFunc)();
void(*EorFunc)();*/

extern int ps2_vu0sub0 __attribute__((section(".vudata")));
extern int ps2_vu1sub0 __attribute__((section(".vudata")));
extern int ps2_vu1sub1 __attribute__((section(".vudata")));

// 100% matching!
void _builtin_set_imask(int mask) 
{

}

// 100% matching! 
void Ps2Init() 
{ 
    Ps2_tex_buff = &Ps2_tex_mem; 
    
    sceDmaReset(1); 
    sceVpu0Reset(); 
    
    sceGsResetPath(); 
    sceGsResetGraph(0, SCE_GS_INTERLACE, SCE_GS_NTSC, SCE_GS_FIELD); 
    
    sceGsSyncV(0); 
    
    sceGsSetDefDBuffDc(&Db, SCE_GS_PSMCT32, DISP_WIDTH, DISP_HEIGHT, SCE_GS_ZGEQUAL, SCE_GS_PSMZ16S, 1); 
    
    Db.disp[0].dispfb.FBP = 150; 
    Db.disp[0].dispfb.PSM = SCE_GS_PSMCT32;
    
    Db.draw01.frame1.FBP = 0; 
    Db.draw01.frame1.PSM = SCE_GS_PSMCT32;
    
    Db.draw01.zbuf1.ZBP = 300;
    
    Db.draw02.frame2.FBP = 0; 
    Db.draw02.frame2.PSM = SCE_GS_PSMCT32;
    
    Db.draw02.zbuf2.ZBP = 300; 
    
    Db.disp[1].dispfb.FBP = 150; 
    Db.disp[1].dispfb.PSM = SCE_GS_PSMCT32;
    
    Db.draw11.frame1.FBP = 0; 
    Db.draw11.frame1.PSM = SCE_GS_PSMCT32; 
    
    Db.draw11.zbuf1.ZBP = 300; 
    
    Db.draw12.frame2.FBP = 0; 
    Db.draw12.frame2.PSM = SCE_GS_PSMCT32; 
    
    Db.draw12.zbuf2.ZBP = 300; 
    
    Db.disp[0].display.DY = 636; 
    Db.disp[1].display.DY = 32; 
    
    ClearVram(); 
    
    *T0_MODE = 139; 
    
    FlushCache(0); 
    
    sceSifInitRpc(0); 
    
    while (sceCdInit(SCECdINIT) == 0); 
    
    sceCdMmode(SCECdDVD); 
    
    while (sceSifRebootIop("cdrom0:\\PS2_DATA\\MODULES\\IOPRP213.IMG;1") == 0);
    
    while (sceSifSyncIop() == 0);  
    
    sceSifInitRpc(0); 
    
    while (sceCdInit(SCECdINIT) == 0); 
    
    sceCdMmode(SCECdDVD); 
    
    sceFsReset(); 
    
    if (sceSifInitIopHeap() != 0)
    { 
        printf("Error:sceSifInitIopHeap Error\n");
        
        exit(-1);
    }
    
    Ps2LoadModule("cdrom0:\\PS2_DATA\\MODULES\\SIO2MAN.IRX;1"); 
    Ps2LoadModule("cdrom0:\\PS2_DATA\\MODULES\\PADMAN.IRX;1"); 
    Ps2LoadModule("cdrom0:\\PS2_DATA\\MODULES\\MCMAN.IRX;1"); 
    Ps2LoadModule("cdrom0:\\PS2_DATA\\MODULES\\MCSERV.IRX;1"); 
    Ps2LoadModule("cdrom0:\\PS2_DATA\\MODULES\\LIBSD.IRX;1"); 
    Ps2LoadModule("cdrom0:\\PS2_DATA\\MODULES\\MODHSYN.IRX;1"); 
    Ps2LoadModule("cdrom0:\\PS2_DATA\\MODULES\\MODMIDI.IRX;1"); 
    Ps2LoadModule("cdrom0:\\PS2_DATA\\MODULES\\MODMSIN.IRX;1"); 
    Ps2LoadModule("cdrom0:\\PS2_DATA\\MODULES\\TSNDDRV.IRX;1"); 
    
    Snd_init(); 
    Cd_init(); 
    Card_init(); 
    Pad_init(); 
    
    Ps2SetVSyncCounter(); 
    
    Ps2InitFunc(); 
    
    Ps2DispScreenClear(); 
    Ps2ScreenClear(); 
    
    Db.disp[0].pmode.EN2 = 0; 
    Db.disp[1].pmode.EN2 = 0;
    
    FlushCache(0); 
    
    Ps2SwapDBuff(); 
    
    Db.disp[0].pmode.EN2 = 1; 
    Db.disp[1].pmode.EN2 = 1; 
    
    FlushCache(0); 
    
    Ps2InitTexCache(); 
    Ps2InitPS2_GS_SAVE(); 
    
    njColorBlendingMode(0, 8); 
    njColorBlendingMode(1, 6); 

    njUserClipping(0, NULL); 
    
    _Make_SinTable(); 
    
    Ps2Vu0ProgSend(0); 
    Ps2Vu1ProgSend(0); 
    Ps2Vu1ProgSend(1); 
}

// 100% matching!
void Ps2LoadModule(char* p)
{
    if (sceSifLoadModule(p, 0, NULL) < 0) 
    {
        printf("LOAD ERROR!!! %s\n", p); 
        
        exit(0); 
    }
}

// 100% matching! 
void Snd_init()
{

}

// 100% matching! 
void Cd_init()
{

}

// 100% matching! 
void Card_init()
{

}

// 100% matching!
void PS2_jikken()
{ 
    pdGetPeripheral(PDD_PORT_A0); 
    
    Ps2SwapDBuff(); 
} 

// 99.92% matching 
void PS2_swap()
{
    unsigned long *p;

    p = (unsigned long*)WORKBASE;

    D2_SyncTag();

    *p++ = DMAend | 0xF;
    *p++ = 0;

    *p++ = SCE_GIF_SET_TAG(14, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    *p++ = SCE_GIF_PACKED_AD;

    *p++ = SCE_GS_SET_FRAME_2(150, 10, SCE_GS_PSMCT32, 0);
    *p++ = SCE_GS_FRAME_2;

    *p++ = 0;
    *p++ = SCE_GS_TEXFLUSH;

    *p++ = SCE_GS_SET_TEX1_2(0, 0, SCE_GS_NEAREST, SCE_GS_NEAREST, 0, 0, 0);
    *p++ = SCE_GS_TEX1_2;

    *p++ = SCE_GS_SET_PABE(0);
    *p++ = SCE_GS_PABE;

    if (MovieInfo.ExecMovieSystemFlag != 0)
    {
        *p++ = SCE_GS_SET_ALPHA_2(SCE_GS_ALPHA_CS, SCE_GS_ALPHA_CD, SCE_GS_ALPHA_FIX, SCE_GS_ALPHA_CD, 128);
    }
    else
    {
        *p++ = SCE_GS_SET_ALPHA_2(SCE_GS_ALPHA_CS, SCE_GS_ALPHA_CD, SCE_GS_ALPHA_FIX, SCE_GS_ALPHA_CD, 96);
    }

    *p++ = SCE_GS_ALPHA_2;

    *p++ = SCE_GS_SET_TEST_2(0, SCE_GS_ALPHA_NEVER, 0, SCE_GS_AFAIL_KEEP, 0, 0, 1, SCE_GS_DEPTH_ALWAYS);
    *p++ = SCE_GS_TEST_2;

    *p++ = SCE_GS_SET_TEX0_2(0, 10, SCE_GS_PSMCT32, 10, 9, 1, SCE_GS_MODULATE, 0, SCE_GS_PSMCT32, 0, 0, 0);
    *p++ = SCE_GS_TEX0_2;

    *p++ = SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 0, 1, 1, 0);
    *p++ = SCE_GS_PRIM;

    *p++ = SCE_GS_SET_RGBAQ(128, 128, 128, 128, 0);
    *p++ = SCE_GS_RGBAQ;

    *p++ = SCE_GS_SET_UV(8, 8);
    *p++ = SCE_GS_UV;

    *p++ = SCE_GS_SET_XYZF2(GS_X_COORD(0), GS_Y_COORD(-128), 256, 0);
    *p++ = SCE_GS_XYZF2;

    *p++ = SCE_GS_SET_UV(8 + (DISP_WIDTH * 16), 8 + (DISP_HEIGHT * 16));
    *p++ = SCE_GS_UV;

    *p++ = SCE_GS_SET_XYZF2(GS_X_COORD(SCR_WIDTH), GS_Y_COORD(352), 256, 0);
    *p++ = SCE_GS_XYZF2;

    *p++ = SCE_GS_SET_TEST_2(0, SCE_GS_ALPHA_NEVER, 0, SCE_GS_AFAIL_KEEP, 0, 0, 1, SCE_GS_DEPTH_GEQUAL);
    *p++ = SCE_GS_TEST_2;
    
    loadImage((void*)0xF0000000);
    
    D2_SyncTag();
    SyncPath();
}

// 99.93% matching
void Ps2AddPrim(unsigned long prim, void* dp, unsigned int num, unsigned int clip_3d_on)
{
    unsigned long* p;           
    unsigned int i;             
    unsigned int clip_flag;     
    unsigned int sc_flag;       
    unsigned int out_clip_flag; 
    unsigned int st_clip_flag;  
    unsigned int nf_flag;       
    float z;                    
    float invz;                 
    float sz;                   
    float x;                   
    float y;                    

    clip_flag = 0; 
    sc_flag = 0;
    st_clip_flag = 0x8000;
    nf_flag = 0; 
    
    if ((prim & 0x8000000000000))
    { 
        if (Ps2_now_tex == NULL) 
        { 
            return;
        }
        
        if (((prim & 0x20000000000000)) && (Ps2_use_pt_flag != 0)) 
        { 
            prim &= ~0x20000000000000; 
        }
        
        if ((!(prim & 0x20000000000000)) && (((TIM2_PICTUREHEADER_EX*)(Ps2_now_tex->texinfo.texsurface.pSurface))->TpFlag != 0)) 
        { 
            Ps2_tex_load_tp_cancel = 1; 
            
            Ps2TexLoad(Ps2_now_tex);
            
            Ps2_tex_load_tp_cancel = 0; 
        }
    } 
    
    p = (unsigned long*)WORKBASE; 
    
    D2_SyncTag(); 
    
    *p++ = DMAend | ((num * 3) + 3); 
    *p++ = 0; 
    
    *p++ = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 1); 
    *p++ = SCE_GIF_PACKED_AD; 
    
    if ((prim & 0x20000000000000)) 
    { 
        *p++ = Ps2_gs_save.TEST = SCE_GS_SET_TEST(1, 6, 0, 0, 0, 0, 1, 2); 
    }
    else
    { 
        *p++ = Ps2_gs_save.TEST = SCE_GS_SET_TEST(1, 6, 0, 0, 0, 0, 1, 2); 
    }
    
    *p++ = SCE_GS_TEST_1; 
    *p++ = SCE_GIF_SET_TAG(prim, 1, 1, 0, 0, 3) | num; // should be SCE_GIF_SET_TAG(num, ...) - maybe it's a custom macro and not the official one?
    
    if ((prim & 0x80000000000000)) 
    {
        *p++ = SCE_GS_UV << (0 * 4) | SCE_GS_RGBAQ << (1 * 4) | SCE_GS_XYZF2 << (2 * 4); 
    } 
    else 
    { 
        *p++ = SCE_GS_ST << (0 * 4) | SCE_GS_RGBAQ << (1 * 4) | SCE_GS_XYZF2 << (2 * 4); 
    }
    
    for (i = 0; i < num; i++) 
    { 
        clip_flag >>= 1; 
        nf_flag >>= 1; 
        
        ((u_long128*)p)[0] = ((u_long128*)dp)[0]; 
        
        out_clip_flag = ((UNKNOWN*)p)->unkC; 
        
        invz = ((float*)p)[2]; 
        
        ((u_long128*)p)[1] = ((u_long128*)dp)[1]; 
        ((u_long128*)p)[2] = ((u_long128*)dp)[2]; 
        
        x = ((float*)p)[8]; 
        y = ((float*)p)[9]; 
            
        sc_flag >>= 4;

        if (((x < 0) || (x > 4095.0f)) || ((y < 0) || (y > 4095.0f))) 
        { 
            clip_flag |= 0x4;
        }

        z = ((float*)p)[3] = ((UNKNOWN*)(p + 4))->unk8;
        
        if ((z < 1.0f) || (z > 65535.0f)) 
        { 
            clip_flag |= 0x4;
            nf_flag |= 0x4; 
        }
        
        if (clip_3d_on != 0)
        { 
            sz = (-Ps2_zbuff_b * invz) - Ps2_zbuff_a; 
            
            if (sz < 0) 
            {
                sz = 0;
            }
            
            if (sz > 65534.0f) 
            {
                sz = 65534.0f; 
            }
            
            ((UNKNOWN*)(p + 4))->unk8 = sz; 
        } 
        else 
        { 
            sz = Ps2_zbuff_a + (Ps2_zbuff_b / z); 
            
            if (sz < 0) 
            {
                sz = 0; 
            }
            
            if (sz > 65534.0f) 
            {
                sz = 65534.0f; 
            }
               
            ((UNKNOWN*)(p + 4))->unk8 = sz; 
        } 
        
        sceVu0FTOI4Vector((void*)(p + 4), (void*)(p + 4)); 
        
        if (clip_flag != 0) 
        { 
            ((UNKNOWN*)(p + 4))->unkC |= 0x8000;
        }
        
        ((UNKNOWN*)(p + 4))->unkC |= out_clip_flag; 
        
        st_clip_flag &= ((UNKNOWN*)(p + 4))->unkC; 
        
        if (clip_3d_on == 0) 
        { 
            ((UNKNOWN*)(p + 4))->unkC &= ~0x8000;
        }
        
        p = (unsigned long*)((int)p + 48); 
        dp = (unsigned long*)((int)dp + 48);
    } 
    
    if ((prim & 0x20000000000000)) 
    { 
        Ps2AddOT((void*)WORKBASE, num, sz, prim); 
    } 
    else
    { 
        SyncPath(); 
        
        loadImage((void*)0xF0000000); 
    }
} 

// 100% matching!
void Ps2AddPrim2D(unsigned long prim, void* dp, unsigned int num)
{
    Ps2AddPrim(prim, dp, num, 0);
}

// 
// Start address: 0x2cbca0
void Ps2AddPrim3D(unsigned long prim, void* dp, unsigned int num)
{
	float zbuff_ab_vec[4];
	float zsum;
	unsigned int st_clip_flag;
	unsigned int clut_flag;
	unsigned int clip_flag;
	//_anon0* timp;
	unsigned long* p;
	float zclip_ab_vec[4];
	float near_far_vec[4];
	float clip_vec[4];
	// Line 1207, Address: 0x2cbca0, Func Offset: 0
	// Line 1221, Address: 0x2cbcb0, Func Offset: 0x10
	// Line 1207, Address: 0x2cbcb4, Func Offset: 0x14
	// Line 1221, Address: 0x2cbcbc, Func Offset: 0x1c
	// Line 1225, Address: 0x2cbce0, Func Offset: 0x40
	// Line 1221, Address: 0x2cbcec, Func Offset: 0x4c
	// Line 1225, Address: 0x2cbd08, Func Offset: 0x68
	// Line 1226, Address: 0x2cbd10, Func Offset: 0x70
	// Line 1228, Address: 0x2cbd20, Func Offset: 0x80
	// Line 1229, Address: 0x2cbd34, Func Offset: 0x94
	// Line 1230, Address: 0x2cbd44, Func Offset: 0xa4
	// Line 1233, Address: 0x2cbd64, Func Offset: 0xc4
	// Line 1234, Address: 0x2cbd78, Func Offset: 0xd8
	// Line 1235, Address: 0x2cbd84, Func Offset: 0xe4
	// Line 1236, Address: 0x2cbd90, Func Offset: 0xf0
	// Line 1237, Address: 0x2cbd98, Func Offset: 0xf8
	// Line 1238, Address: 0x2cbda0, Func Offset: 0x100
	// Line 1249, Address: 0x2cbda8, Func Offset: 0x108
	// Line 1250, Address: 0x2cbdac, Func Offset: 0x10c
	// Line 1253, Address: 0x2cbdb4, Func Offset: 0x114
	// Line 1256, Address: 0x2cbdb8, Func Offset: 0x118
	// Line 1253, Address: 0x2cbdc8, Func Offset: 0x128
	// Line 1254, Address: 0x2cbdec, Func Offset: 0x14c
	// Line 1256, Address: 0x2cbdf4, Func Offset: 0x154
	// Line 1257, Address: 0x2cbdfc, Func Offset: 0x15c
	// Line 1260, Address: 0x2cbe04, Func Offset: 0x164
	// Line 1257, Address: 0x2cbe08, Func Offset: 0x168
	// Line 1260, Address: 0x2cbe0c, Func Offset: 0x16c
	// Line 1268, Address: 0x2cbe1c, Func Offset: 0x17c
	// Line 1260, Address: 0x2cbe30, Func Offset: 0x190
	// Line 1261, Address: 0x2cbe34, Func Offset: 0x194
	// Line 1268, Address: 0x2cbe3c, Func Offset: 0x19c
	// Line 1261, Address: 0x2cbe44, Func Offset: 0x1a4
	// Line 1272, Address: 0x2cbe48, Func Offset: 0x1a8
	// Line 1268, Address: 0x2cbe4c, Func Offset: 0x1ac
	// Line 1269, Address: 0x2cbe58, Func Offset: 0x1b8
	// Line 1272, Address: 0x2cbe60, Func Offset: 0x1c0
	// Line 1269, Address: 0x2cbe74, Func Offset: 0x1d4
	// Line 1272, Address: 0x2cbe78, Func Offset: 0x1d8
	// Line 1275, Address: 0x2cbe84, Func Offset: 0x1e4
	// Line 1276, Address: 0x2cbe88, Func Offset: 0x1e8
	// Line 1277, Address: 0x2cbe8c, Func Offset: 0x1ec
	// Line 1278, Address: 0x2cbe90, Func Offset: 0x1f0
	// Line 1279, Address: 0x2cbe94, Func Offset: 0x1f4
	// Line 1280, Address: 0x2cbe98, Func Offset: 0x1f8
	// Line 1282, Address: 0x2cbe9c, Func Offset: 0x1fc
	// Line 1281, Address: 0x2cbea0, Func Offset: 0x200
	// Line 1282, Address: 0x2cbea4, Func Offset: 0x204
	// Line 1283, Address: 0x2cbea8, Func Offset: 0x208
	// Line 1284, Address: 0x2cbeac, Func Offset: 0x20c
	// Line 1285, Address: 0x2cbeb0, Func Offset: 0x210
	// Line 1286, Address: 0x2cbeb4, Func Offset: 0x214
	// Line 1287, Address: 0x2cbeb8, Func Offset: 0x218
	// Line 1289, Address: 0x2cbebc, Func Offset: 0x21c
	// Line 1290, Address: 0x2cbec0, Func Offset: 0x220
	// Line 1291, Address: 0x2cbec4, Func Offset: 0x224
	// Line 1293, Address: 0x2cbec8, Func Offset: 0x228
	// Line 1294, Address: 0x2cbecc, Func Offset: 0x22c
	// Line 1295, Address: 0x2cbed0, Func Offset: 0x230
	// Line 1296, Address: 0x2cbed4, Func Offset: 0x234
	// Line 1297, Address: 0x2cbed8, Func Offset: 0x238
	// Line 1299, Address: 0x2cbedc, Func Offset: 0x23c
	// Line 1300, Address: 0x2cbee0, Func Offset: 0x240
	// Line 1301, Address: 0x2cbee4, Func Offset: 0x244
	// Line 1303, Address: 0x2cbee8, Func Offset: 0x248
	// Line 1304, Address: 0x2cbeec, Func Offset: 0x24c
	// Line 1305, Address: 0x2cbef0, Func Offset: 0x250
	// Line 1306, Address: 0x2cbef4, Func Offset: 0x254
	// Line 1307, Address: 0x2cbef8, Func Offset: 0x258
	// Line 1308, Address: 0x2cbefc, Func Offset: 0x25c
	// Line 1309, Address: 0x2cbf00, Func Offset: 0x260
	// Line 1311, Address: 0x2cbf08, Func Offset: 0x268
	// Line 1313, Address: 0x2cbf0c, Func Offset: 0x26c
	// Line 1314, Address: 0x2cbf10, Func Offset: 0x270
	// Line 1315, Address: 0x2cbf14, Func Offset: 0x274
	// Line 1316, Address: 0x2cbf18, Func Offset: 0x278
	// Line 1317, Address: 0x2cbf1c, Func Offset: 0x27c
	// Line 1318, Address: 0x2cbf20, Func Offset: 0x280
	// Line 1319, Address: 0x2cbf24, Func Offset: 0x284
	// Line 1320, Address: 0x2cbf28, Func Offset: 0x288
	// Line 1321, Address: 0x2cbf2c, Func Offset: 0x28c
	// Line 1323, Address: 0x2cbf34, Func Offset: 0x294
	// Line 1324, Address: 0x2cbf38, Func Offset: 0x298
	// Line 1326, Address: 0x2cbf40, Func Offset: 0x2a0
	// Line 1327, Address: 0x2cbf44, Func Offset: 0x2a4
	// Line 1379, Address: 0x2cbf48, Func Offset: 0x2a8
	// Line 1436, Address: 0x2cbf5c, Func Offset: 0x2bc
	// Line 1439, Address: 0x2cbf80, Func Offset: 0x2e0
	// Line 1442, Address: 0x2cbf88, Func Offset: 0x2e8
	// Line 1443, Address: 0x2cbf90, Func Offset: 0x2f0
	// Line 1447, Address: 0x2cbf98, Func Offset: 0x2f8
	// Func End, Address: 0x2cbfb0, Func Offset: 0x310
	scePrintf("Ps2AddPrim3D - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2cbfb0
void Ps2AddPrim3DEx(unsigned long prim, void* dp, unsigned int num)
{
	float zbuff_ab_vec[4];
	float zsum;
	unsigned int st_clip_flag;
	unsigned int clut_flag;
	unsigned int clip_flag;
	//_anon0* timp;
	unsigned long* p;
	float zclip_ab_vec[4];
	float near_far_vec[4];
	float clip_vec[4];
	// Line 1450, Address: 0x2cbfb0, Func Offset: 0
	// Line 1464, Address: 0x2cbfc0, Func Offset: 0x10
	// Line 1450, Address: 0x2cbfc4, Func Offset: 0x14
	// Line 1464, Address: 0x2cbfcc, Func Offset: 0x1c
	// Line 1481, Address: 0x2cbff0, Func Offset: 0x40
	// Line 1464, Address: 0x2cbffc, Func Offset: 0x4c
	// Line 1481, Address: 0x2cc018, Func Offset: 0x68
	// Line 1482, Address: 0x2cc020, Func Offset: 0x70
	// Line 1484, Address: 0x2cc030, Func Offset: 0x80
	// Line 1485, Address: 0x2cc044, Func Offset: 0x94
	// Line 1487, Address: 0x2cc054, Func Offset: 0xa4
	// Line 1490, Address: 0x2cc074, Func Offset: 0xc4
	// Line 1491, Address: 0x2cc088, Func Offset: 0xd8
	// Line 1492, Address: 0x2cc094, Func Offset: 0xe4
	// Line 1493, Address: 0x2cc0a0, Func Offset: 0xf0
	// Line 1494, Address: 0x2cc0a8, Func Offset: 0xf8
	// Line 1495, Address: 0x2cc0b0, Func Offset: 0x100
	// Line 1505, Address: 0x2cc0b8, Func Offset: 0x108
	// Line 1506, Address: 0x2cc0bc, Func Offset: 0x10c
	// Line 1509, Address: 0x2cc0c4, Func Offset: 0x114
	// Line 1512, Address: 0x2cc0c8, Func Offset: 0x118
	// Line 1509, Address: 0x2cc0d8, Func Offset: 0x128
	// Line 1510, Address: 0x2cc0fc, Func Offset: 0x14c
	// Line 1512, Address: 0x2cc104, Func Offset: 0x154
	// Line 1513, Address: 0x2cc10c, Func Offset: 0x15c
	// Line 1516, Address: 0x2cc114, Func Offset: 0x164
	// Line 1513, Address: 0x2cc118, Func Offset: 0x168
	// Line 1516, Address: 0x2cc11c, Func Offset: 0x16c
	// Line 1529, Address: 0x2cc12c, Func Offset: 0x17c
	// Line 1516, Address: 0x2cc140, Func Offset: 0x190
	// Line 1517, Address: 0x2cc144, Func Offset: 0x194
	// Line 1529, Address: 0x2cc14c, Func Offset: 0x19c
	// Line 1517, Address: 0x2cc154, Func Offset: 0x1a4
	// Line 1533, Address: 0x2cc158, Func Offset: 0x1a8
	// Line 1529, Address: 0x2cc15c, Func Offset: 0x1ac
	// Line 1530, Address: 0x2cc168, Func Offset: 0x1b8
	// Line 1533, Address: 0x2cc170, Func Offset: 0x1c0
	// Line 1530, Address: 0x2cc184, Func Offset: 0x1d4
	// Line 1533, Address: 0x2cc188, Func Offset: 0x1d8
	// Line 1536, Address: 0x2cc194, Func Offset: 0x1e4
	// Line 1537, Address: 0x2cc198, Func Offset: 0x1e8
	// Line 1538, Address: 0x2cc19c, Func Offset: 0x1ec
	// Line 1539, Address: 0x2cc1a0, Func Offset: 0x1f0
	// Line 1540, Address: 0x2cc1a4, Func Offset: 0x1f4
	// Line 1541, Address: 0x2cc1a8, Func Offset: 0x1f8
	// Line 1543, Address: 0x2cc1ac, Func Offset: 0x1fc
	// Line 1542, Address: 0x2cc1b0, Func Offset: 0x200
	// Line 1543, Address: 0x2cc1b4, Func Offset: 0x204
	// Line 1544, Address: 0x2cc1b8, Func Offset: 0x208
	// Line 1545, Address: 0x2cc1bc, Func Offset: 0x20c
	// Line 1546, Address: 0x2cc1c0, Func Offset: 0x210
	// Line 1547, Address: 0x2cc1c4, Func Offset: 0x214
	// Line 1548, Address: 0x2cc1c8, Func Offset: 0x218
	// Line 1550, Address: 0x2cc1cc, Func Offset: 0x21c
	// Line 1551, Address: 0x2cc1d0, Func Offset: 0x220
	// Line 1552, Address: 0x2cc1d4, Func Offset: 0x224
	// Line 1554, Address: 0x2cc1d8, Func Offset: 0x228
	// Line 1555, Address: 0x2cc1dc, Func Offset: 0x22c
	// Line 1556, Address: 0x2cc1e0, Func Offset: 0x230
	// Line 1557, Address: 0x2cc1e4, Func Offset: 0x234
	// Line 1558, Address: 0x2cc1e8, Func Offset: 0x238
	// Line 1560, Address: 0x2cc1ec, Func Offset: 0x23c
	// Line 1561, Address: 0x2cc1f0, Func Offset: 0x240
	// Line 1562, Address: 0x2cc1f4, Func Offset: 0x244
	// Line 1563, Address: 0x2cc1f8, Func Offset: 0x248
	// Line 1564, Address: 0x2cc1fc, Func Offset: 0x24c
	// Line 1565, Address: 0x2cc200, Func Offset: 0x250
	// Line 1566, Address: 0x2cc204, Func Offset: 0x254
	// Line 1567, Address: 0x2cc208, Func Offset: 0x258
	// Line 1568, Address: 0x2cc20c, Func Offset: 0x25c
	// Line 1569, Address: 0x2cc210, Func Offset: 0x260
	// Line 1570, Address: 0x2cc214, Func Offset: 0x264
	// Line 1572, Address: 0x2cc21c, Func Offset: 0x26c
	// Line 1574, Address: 0x2cc220, Func Offset: 0x270
	// Line 1575, Address: 0x2cc224, Func Offset: 0x274
	// Line 1576, Address: 0x2cc228, Func Offset: 0x278
	// Line 1577, Address: 0x2cc22c, Func Offset: 0x27c
	// Line 1578, Address: 0x2cc230, Func Offset: 0x280
	// Line 1579, Address: 0x2cc234, Func Offset: 0x284
	// Line 1580, Address: 0x2cc238, Func Offset: 0x288
	// Line 1581, Address: 0x2cc23c, Func Offset: 0x28c
	// Line 1582, Address: 0x2cc240, Func Offset: 0x290
	// Line 1584, Address: 0x2cc248, Func Offset: 0x298
	// Line 1585, Address: 0x2cc24c, Func Offset: 0x29c
	// Line 1587, Address: 0x2cc254, Func Offset: 0x2a4
	// Line 1588, Address: 0x2cc258, Func Offset: 0x2a8
	// Line 1641, Address: 0x2cc25c, Func Offset: 0x2ac
	// Line 1705, Address: 0x2cc270, Func Offset: 0x2c0
	// Line 1708, Address: 0x2cc294, Func Offset: 0x2e4
	// Line 1711, Address: 0x2cc29c, Func Offset: 0x2ec
	// Line 1712, Address: 0x2cc2a4, Func Offset: 0x2f4
	// Line 1716, Address: 0x2cc2ac, Func Offset: 0x2fc
	// Func End, Address: 0x2cc2c4, Func Offset: 0x314
	scePrintf("Ps2AddPrim3DEx - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2cc2d0
void Ps2AddPrim3DEx1P(unsigned long prim, void* dp, unsigned int num)
{
	float zbuff_ab_vec[4];
	float zsum;
	unsigned int st_clip_flag;
	unsigned int clut_flag;
	unsigned int clip_flag;
	//_anon0* timp;
	unsigned long* p;
	float zclip_ab_vec[4];
	float near_far_vec[4];
	float clip_vec[4];
	// Line 1896, Address: 0x2cc2d0, Func Offset: 0
	// Line 1907, Address: 0x2cc2e0, Func Offset: 0x10
	// Line 1896, Address: 0x2cc2e4, Func Offset: 0x14
	// Line 1907, Address: 0x2cc2ec, Func Offset: 0x1c
	// Line 1911, Address: 0x2cc310, Func Offset: 0x40
	// Line 1907, Address: 0x2cc31c, Func Offset: 0x4c
	// Line 1911, Address: 0x2cc338, Func Offset: 0x68
	// Line 1912, Address: 0x2cc340, Func Offset: 0x70
	// Line 1914, Address: 0x2cc350, Func Offset: 0x80
	// Line 1915, Address: 0x2cc364, Func Offset: 0x94
	// Line 1916, Address: 0x2cc374, Func Offset: 0xa4
	// Line 1919, Address: 0x2cc394, Func Offset: 0xc4
	// Line 1920, Address: 0x2cc3a8, Func Offset: 0xd8
	// Line 1921, Address: 0x2cc3b4, Func Offset: 0xe4
	// Line 1922, Address: 0x2cc3c0, Func Offset: 0xf0
	// Line 1923, Address: 0x2cc3c8, Func Offset: 0xf8
	// Line 1924, Address: 0x2cc3d0, Func Offset: 0x100
	// Line 1926, Address: 0x2cc3d4, Func Offset: 0x104
	// Line 1928, Address: 0x2cc3dc, Func Offset: 0x10c
	// Line 1930, Address: 0x2cc3ec, Func Offset: 0x11c
	// Line 1929, Address: 0x2cc3f4, Func Offset: 0x124
	// Line 1930, Address: 0x2cc3fc, Func Offset: 0x12c
	// Line 1931, Address: 0x2cc404, Func Offset: 0x134
	// Line 1943, Address: 0x2cc40c, Func Offset: 0x13c
	// Line 1944, Address: 0x2cc410, Func Offset: 0x140
	// Line 1946, Address: 0x2cc418, Func Offset: 0x148
	// Line 1949, Address: 0x2cc41c, Func Offset: 0x14c
	// Line 1946, Address: 0x2cc42c, Func Offset: 0x15c
	// Line 1947, Address: 0x2cc450, Func Offset: 0x180
	// Line 1949, Address: 0x2cc458, Func Offset: 0x188
	// Line 1950, Address: 0x2cc460, Func Offset: 0x190
	// Line 1953, Address: 0x2cc468, Func Offset: 0x198
	// Line 1950, Address: 0x2cc46c, Func Offset: 0x19c
	// Line 1953, Address: 0x2cc470, Func Offset: 0x1a0
	// Line 1956, Address: 0x2cc480, Func Offset: 0x1b0
	// Line 1953, Address: 0x2cc494, Func Offset: 0x1c4
	// Line 1954, Address: 0x2cc498, Func Offset: 0x1c8
	// Line 1956, Address: 0x2cc4a0, Func Offset: 0x1d0
	// Line 1954, Address: 0x2cc4a8, Func Offset: 0x1d8
	// Line 1959, Address: 0x2cc4ac, Func Offset: 0x1dc
	// Line 1956, Address: 0x2cc4b0, Func Offset: 0x1e0
	// Line 1957, Address: 0x2cc4bc, Func Offset: 0x1ec
	// Line 1959, Address: 0x2cc4c4, Func Offset: 0x1f4
	// Line 1957, Address: 0x2cc4dc, Func Offset: 0x20c
	// Line 1959, Address: 0x2cc4e0, Func Offset: 0x210
	// Line 1962, Address: 0x2cc4e4, Func Offset: 0x214
	// Line 1963, Address: 0x2cc4e8, Func Offset: 0x218
	// Line 1964, Address: 0x2cc4ec, Func Offset: 0x21c
	// Line 1965, Address: 0x2cc4f0, Func Offset: 0x220
	// Line 1966, Address: 0x2cc4f4, Func Offset: 0x224
	// Line 1967, Address: 0x2cc4f8, Func Offset: 0x228
	// Line 1969, Address: 0x2cc4fc, Func Offset: 0x22c
	// Line 1968, Address: 0x2cc500, Func Offset: 0x230
	// Line 1969, Address: 0x2cc504, Func Offset: 0x234
	// Line 1970, Address: 0x2cc508, Func Offset: 0x238
	// Line 1971, Address: 0x2cc50c, Func Offset: 0x23c
	// Line 1972, Address: 0x2cc510, Func Offset: 0x240
	// Line 1973, Address: 0x2cc514, Func Offset: 0x244
	// Line 1974, Address: 0x2cc518, Func Offset: 0x248
	// Line 1976, Address: 0x2cc51c, Func Offset: 0x24c
	// Line 1977, Address: 0x2cc520, Func Offset: 0x250
	// Line 1978, Address: 0x2cc524, Func Offset: 0x254
	// Line 1980, Address: 0x2cc528, Func Offset: 0x258
	// Line 1981, Address: 0x2cc52c, Func Offset: 0x25c
	// Line 1982, Address: 0x2cc530, Func Offset: 0x260
	// Line 1983, Address: 0x2cc534, Func Offset: 0x264
	// Line 1984, Address: 0x2cc538, Func Offset: 0x268
	// Line 1986, Address: 0x2cc53c, Func Offset: 0x26c
	// Line 1987, Address: 0x2cc540, Func Offset: 0x270
	// Line 1988, Address: 0x2cc544, Func Offset: 0x274
	// Line 1989, Address: 0x2cc548, Func Offset: 0x278
	// Line 1990, Address: 0x2cc54c, Func Offset: 0x27c
	// Line 1991, Address: 0x2cc550, Func Offset: 0x280
	// Line 1992, Address: 0x2cc554, Func Offset: 0x284
	// Line 1993, Address: 0x2cc558, Func Offset: 0x288
	// Line 1994, Address: 0x2cc55c, Func Offset: 0x28c
	// Line 1995, Address: 0x2cc560, Func Offset: 0x290
	// Line 1996, Address: 0x2cc564, Func Offset: 0x294
	// Line 1998, Address: 0x2cc56c, Func Offset: 0x29c
	// Line 2000, Address: 0x2cc570, Func Offset: 0x2a0
	// Line 2001, Address: 0x2cc574, Func Offset: 0x2a4
	// Line 2002, Address: 0x2cc578, Func Offset: 0x2a8
	// Line 2003, Address: 0x2cc57c, Func Offset: 0x2ac
	// Line 2004, Address: 0x2cc580, Func Offset: 0x2b0
	// Line 2005, Address: 0x2cc584, Func Offset: 0x2b4
	// Line 2006, Address: 0x2cc588, Func Offset: 0x2b8
	// Line 2007, Address: 0x2cc58c, Func Offset: 0x2bc
	// Line 2008, Address: 0x2cc590, Func Offset: 0x2c0
	// Line 2010, Address: 0x2cc598, Func Offset: 0x2c8
	// Line 2011, Address: 0x2cc59c, Func Offset: 0x2cc
	// Line 2013, Address: 0x2cc5a4, Func Offset: 0x2d4
	// Line 2014, Address: 0x2cc5a8, Func Offset: 0x2d8
	// Line 2028, Address: 0x2cc5ac, Func Offset: 0x2dc
	// Line 2029, Address: 0x2cc5bc, Func Offset: 0x2ec
	// Line 2030, Address: 0x2cc5d0, Func Offset: 0x300
	// Line 2031, Address: 0x2cc5e8, Func Offset: 0x318
	// Line 2034, Address: 0x2cc5f0, Func Offset: 0x320
	// Line 2035, Address: 0x2cc5f8, Func Offset: 0x328
	// Line 2038, Address: 0x2cc600, Func Offset: 0x330
	// Func End, Address: 0x2cc618, Func Offset: 0x348
	scePrintf("Ps2AddPrim3DEx1P - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2cc620
void Ps2AddPrim3DMod(unsigned long prim, void* dp, unsigned int num)
{
	float zbuff_ab_vec[4];
	float zsum;
	unsigned int st_clip_flag;
	unsigned int clip_flag;
	unsigned long* p;
	float zclip_ab_vec[4];
	float near_far_vec[4];
	float clip_vec[4];
	// Line 2041, Address: 0x2cc620, Func Offset: 0
	// Line 2052, Address: 0x2cc634, Func Offset: 0x14
	// Line 2041, Address: 0x2cc63c, Func Offset: 0x1c
	// Line 2052, Address: 0x2cc640, Func Offset: 0x20
	// Line 2055, Address: 0x2cc660, Func Offset: 0x40
	// Line 2052, Address: 0x2cc664, Func Offset: 0x44
	// Line 2056, Address: 0x2cc680, Func Offset: 0x60
	// Line 2059, Address: 0x2cc688, Func Offset: 0x68
	// Line 2062, Address: 0x2cc68c, Func Offset: 0x6c
	// Line 2059, Address: 0x2cc69c, Func Offset: 0x7c
	// Line 2060, Address: 0x2cc6c0, Func Offset: 0xa0
	// Line 2062, Address: 0x2cc6c8, Func Offset: 0xa8
	// Line 2063, Address: 0x2cc6d0, Func Offset: 0xb0
	// Line 2076, Address: 0x2cc6d8, Func Offset: 0xb8
	// Line 2077, Address: 0x2cc6e4, Func Offset: 0xc4
	// Line 2063, Address: 0x2cc6f8, Func Offset: 0xd8
	// Line 2067, Address: 0x2cc6fc, Func Offset: 0xdc
	// Line 2068, Address: 0x2cc708, Func Offset: 0xe8
	// Line 2077, Address: 0x2cc710, Func Offset: 0xf0
	// Line 2068, Address: 0x2cc718, Func Offset: 0xf8
	// Line 2081, Address: 0x2cc71c, Func Offset: 0xfc
	// Line 2077, Address: 0x2cc720, Func Offset: 0x100
	// Line 2078, Address: 0x2cc72c, Func Offset: 0x10c
	// Line 2081, Address: 0x2cc734, Func Offset: 0x114
	// Line 2078, Address: 0x2cc74c, Func Offset: 0x12c
	// Line 2081, Address: 0x2cc750, Func Offset: 0x130
	// Line 2084, Address: 0x2cc754, Func Offset: 0x134
	// Line 2085, Address: 0x2cc758, Func Offset: 0x138
	// Line 2086, Address: 0x2cc75c, Func Offset: 0x13c
	// Line 2087, Address: 0x2cc760, Func Offset: 0x140
	// Line 2088, Address: 0x2cc764, Func Offset: 0x144
	// Line 2089, Address: 0x2cc768, Func Offset: 0x148
	// Line 2091, Address: 0x2cc76c, Func Offset: 0x14c
	// Line 2090, Address: 0x2cc770, Func Offset: 0x150
	// Line 2091, Address: 0x2cc774, Func Offset: 0x154
	// Line 2092, Address: 0x2cc778, Func Offset: 0x158
	// Line 2093, Address: 0x2cc77c, Func Offset: 0x15c
	// Line 2094, Address: 0x2cc780, Func Offset: 0x160
	// Line 2095, Address: 0x2cc784, Func Offset: 0x164
	// Line 2096, Address: 0x2cc788, Func Offset: 0x168
	// Line 2098, Address: 0x2cc78c, Func Offset: 0x16c
	// Line 2099, Address: 0x2cc790, Func Offset: 0x170
	// Line 2100, Address: 0x2cc794, Func Offset: 0x174
	// Line 2102, Address: 0x2cc798, Func Offset: 0x178
	// Line 2103, Address: 0x2cc79c, Func Offset: 0x17c
	// Line 2104, Address: 0x2cc7a0, Func Offset: 0x180
	// Line 2105, Address: 0x2cc7a4, Func Offset: 0x184
	// Line 2106, Address: 0x2cc7a8, Func Offset: 0x188
	// Line 2108, Address: 0x2cc7ac, Func Offset: 0x18c
	// Line 2109, Address: 0x2cc7b0, Func Offset: 0x190
	// Line 2110, Address: 0x2cc7b4, Func Offset: 0x194
	// Line 2111, Address: 0x2cc7b8, Func Offset: 0x198
	// Line 2112, Address: 0x2cc7bc, Func Offset: 0x19c
	// Line 2113, Address: 0x2cc7c0, Func Offset: 0x1a0
	// Line 2114, Address: 0x2cc7c4, Func Offset: 0x1a4
	// Line 2115, Address: 0x2cc7c8, Func Offset: 0x1a8
	// Line 2116, Address: 0x2cc7cc, Func Offset: 0x1ac
	// Line 2117, Address: 0x2cc7d0, Func Offset: 0x1b0
	// Line 2118, Address: 0x2cc7d4, Func Offset: 0x1b4
	// Line 2120, Address: 0x2cc7dc, Func Offset: 0x1bc
	// Line 2122, Address: 0x2cc7e0, Func Offset: 0x1c0
	// Line 2123, Address: 0x2cc7e4, Func Offset: 0x1c4
	// Line 2124, Address: 0x2cc7e8, Func Offset: 0x1c8
	// Line 2125, Address: 0x2cc7ec, Func Offset: 0x1cc
	// Line 2126, Address: 0x2cc7f0, Func Offset: 0x1d0
	// Line 2127, Address: 0x2cc7f4, Func Offset: 0x1d4
	// Line 2128, Address: 0x2cc7f8, Func Offset: 0x1d8
	// Line 2129, Address: 0x2cc7fc, Func Offset: 0x1dc
	// Line 2130, Address: 0x2cc800, Func Offset: 0x1e0
	// Line 2132, Address: 0x2cc808, Func Offset: 0x1e8
	// Line 2133, Address: 0x2cc80c, Func Offset: 0x1ec
	// Line 2135, Address: 0x2cc814, Func Offset: 0x1f4
	// Line 2136, Address: 0x2cc818, Func Offset: 0x1f8
	// Line 2150, Address: 0x2cc81c, Func Offset: 0x1fc
	// Line 2151, Address: 0x2cc824, Func Offset: 0x204
	// Line 2154, Address: 0x2cc82c, Func Offset: 0x20c
	// Func End, Address: 0x2cc844, Func Offset: 0x224
	scePrintf("Ps2AddPrim3DMod - UNIMPLEMENTED!\n");
}

// 100% matching! 
void Ps2ClearOT()
{
    int i;

    Ps2_ot_list->tp = NULL;
    
    Ps2_ot_list_no = 0;
    
    Ps2_PP = (void*)((int)&Ps2_PBUFF | 0x30000000); 
    
    for (i = 0; i < 4096; i++) 
    {
        *(unsigned long*)&Ps2_OT[i][0] = 0;
    } 
}

// 100% matching!
void Ps2AddOT(void* p, unsigned int num, float z, unsigned long prim)
{
    unsigned int i; 
    unsigned int size; 
    register unsigned int otz = 0; 
    unsigned int id; 

    if (Ps2_ice_flag != 0)
    { 
        id = Ps2_now_tex->globalIndex & 0xFFFFF; 
        
        if (((id >= 26510) && (id <= 26614)) || (id == 107170)) 
        { 
            asm volatile (cvt.w.s f12, f12); 
            asm volatile (mfc1      otz, f12); 
            
            otz >>= 12;
        } 
        else 
        { 
            asm volatile (cvt.w.s f12, f12); 
            asm volatile (mfc1      otz, f12); 
            
            otz >>= 4;
        }
    } 
    else 
    { 
        asm volatile (cvt.w.s f12, f12); 
        asm volatile (mfc1      otz, f12); 
        
        otz >>= 4; 
    }
        
    if (otz > 4095) 
    {
        otz = 4095; 
    }
        
    if (Ps2_OT[otz][0] != NULL) 
    { 
        Ps2_OT[otz][1]->op = (void*)&Ps2_ot_list[Ps2_ot_list_no]; 
        
        Ps2_OT[otz][1] = &Ps2_ot_list[Ps2_ot_list_no]; 
        
        Ps2_OT[otz][1]->op = NULL; 
    } 
    else 
    { 
        Ps2_OT[otz][0] = Ps2_OT[otz][1] = &Ps2_ot_list[Ps2_ot_list_no]; 
        
        Ps2_OT[otz][1]->op = NULL; 
    }
        
    if ((prim & 0x8000000000000)) 
    { 
        Ps2_ot_list[Ps2_ot_list_no].tp = Ps2_now_tex; 
        Ps2_ot_list[Ps2_ot_list_no].bank = Ps2_now_bank; 
    }
    else 
    { 
        Ps2_ot_list[Ps2_ot_list_no].tp = (void*)-1; 
    }
        
    Ps2_ot_list[Ps2_ot_list_no].p = Ps2_PP; 
    
    Ps2_ot_list[Ps2_ot_list_no].TEX0 = Ps2_gs_save.TEX0 & 0xE0F8001FFFFFC000; 
    Ps2_ot_list[Ps2_ot_list_no].TEX0_NEXT = Ps2_gs_save.TEX0_NEXT & 0xE0F8001FFFFFC000; 
    
    Ps2_ot_list[Ps2_ot_list_no].ALPHA = Ps2_gs_save.ALPHA; 
    
    num = (num * 3) + 1; 
    
    (char*)Ps2_PP += 16; 
        
    *((long*)Ps2_PP)++ = DMAnext | ((*(long*)p) & 0xFFFFFFF); 
    *((long*)Ps2_PP)++ = 0; 
    
    *((long*)Ps2_PP)++ = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 1); 
    *((long*)Ps2_PP)++ = SCE_GIF_PACKED_AD; 
    
    *((long*)Ps2_PP)++ = Ps2_gs_save.ALPHA; 
    *((long*)Ps2_PP)++ = SCE_GS_ALPHA_1; 
    
    (char*)p += 48; 
    
    for (i = 0; i < num; i++) 
    { 
        *((u_long128*)Ps2_PP)++ = *((u_long128*)p)++; 
    } 
    
    Ps2_ot_list_no++; 
} 

// 100% matching! 
void Ps2DrawOTag()
{
    int i;

    Ps2ZbuffOff();
    
    for (i = 0; i < 4096; )
    {
        i = Ps2DrawOTagSub(i);
    } 
    
    Ps2ZbuffOn();
    
    Ps2_current_texbreak = 1;
}

// 98.96% matching
int Ps2DrawOTagSub(int start_no)
{ 
    int i; 
    int j; 
    PS2_OT* p; 
    PS2_OT* old_p; 
    int save_alpha[3]; 
    TIM2_PICTUREHEADER_EX* timp; 
    unsigned int tex_cache_num; 
    PS2_OT *temp; // not from the debugging symbols 
    unsigned int t_flag;
    unsigned int p_flag; 
    unsigned int t_no; 
    unsigned int np_no; 
    unsigned int tex_addr;
    unsigned int clt_addr;
    unsigned int exit_no; 
    void* start_addr;
    
    old_p = NULL;
    
    t_no = 0; 
    np_no = 0;
    
    tex_cache_num = 0; 
    
    tex_addr = 0x2F80; 
    clt_addr = 0x2E44;
    
    exit_no = 4096; 
    
    for (i = 0; i < 64; i++) 
    { 
        *(u_long128*)&ps2_tp_cache[i] = 0; 
    } 
    
    for (i = start_no; i < 4096; i++) 
    { 
        for (p = Ps2_OT[i][0]; p != NULL; ) 
        { 
            if (old_p != NULL) 
            { 
                ((long*)old_p->p)[2] |= ((unsigned long)p->p & 0xFFFFFFF) << 32; 
            }
            else
            { 
                start_addr = p->p; 
            }
            
            p_flag = 0; 
            t_flag = 0; 
            
            if (p->tp == NULL)
            {
                return 4096;
            }
            
            if ((int)p->tp != -1) 
            { 
                if (tex_cache_num >= 64) 
                { 
                    printf("Ps2DrawOTag ERROR!\n");
                    
                    exit(0); 
                }

                timp = (TIM2_PICTUREHEADER_EX*)p->tp->texinfo.texsurface.pSurface; 
                
                if (timp != NULL) 
                { 
                    for (j = 0; j < tex_cache_num; j++) 
                    { 
                        if (ps2_tp_cache[j].tp == p->tp->texinfo.texsurface.pSurface) 
                        { 
                            t_flag = 1; 
                            
                            np_no = j;
                            
                            if (ps2_tp_cache[j].bank == p->bank) 
                            { 
                                p_flag = 1;
                                
                                t_no = j; 
                            }
                        }
                    } 
                    
                    if (t_flag != 0)
                    { 
                        if (p_flag == 0) 
                        { 
                            ps2_tp_cache[tex_cache_num].tex_addr = ps2_tp_cache[np_no].tex_addr; 
                            ps2_tp_cache[tex_cache_num].clt_addr = ps2_tp_cache[np_no].clt_addr; 
                        } 
                        else 
                        { 
                            ((long*)p->p)[0] = DMAref | 0x4 | ((long)&Ps2_tp_tag[t_no] << 32); 
                            ((long*)p->p)[1] = 0; 
                            
                            goto loop_end; 
                        }
                    } 
                    else if ((tex_addr + (timp->ImageSize >> 8)) >= 0x3F80) 
                    { 
                        exit_no = i; 
                        
                        Ps2_OT[i][0] = p; 
                        
                        goto block; 
                    } 
                    else 
                    {
                        Send_Tim2_dataEx(timp, (int)tex_addr, (int)clt_addr); 
                        
                        timp->TpFlag = 1; 
                        
                        ps2_tp_cache[tex_cache_num].tex_addr = tex_addr; 
                        ps2_tp_cache[tex_cache_num].clt_addr = clt_addr; 
                        
                        tex_addr += timp->ImageSize >> 8; 
                        clt_addr += 8; 
                    }
                    
                    ps2_tp_cache[tex_cache_num].tp = timp; 
                    ps2_tp_cache[tex_cache_num].bank = p->bank; 
                    
                    Ps2_tp_tag[tex_cache_num].GIF_TAG[0] = SCE_GIF_SET_TAG(3, SCE_GS_FALSE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1); 
                    Ps2_tp_tag[tex_cache_num].GIF_TAG[1] = SCE_GIF_PACKED_AD; 
                    
                    if ((timp->PictFormat >= 5) && (timp->PictFormat < 9)) 
                    { 
                        Ps2_tp_tag[tex_cache_num].TEX0 = p->TEX0 | SCE_GS_SET_TEX0_1(ps2_tp_cache[tex_cache_num].tex_addr, 0, SCE_GS_PSMCT32, 0, 0, 0, SCE_GS_MODULATE, ((p->bank & 0x30) >> 2) + 0x3FF0, SCE_GS_PSMCT32, 0, 0, 2); 
                        Ps2_tp_tag[tex_cache_num].TEX0_TAG = SCE_GS_TEX0_1; 
                        Ps2_tp_tag[tex_cache_num].TEX0_NEXT = p->TEX0_NEXT | SCE_GS_SET_TEX0_1(ps2_tp_cache[tex_cache_num].tex_addr, 0, SCE_GS_PSMCT32, 0, 0, 0, SCE_GS_MODULATE, ((p->bank & 0x30) >> 2) + 0x3FF0, SCE_GS_PSMCT32, 0, p->bank & 0xF, 0);
                        Ps2_tp_tag[tex_cache_num].TEX0_NEXT_TAG = SCE_GS_TEX0_1;
                    } 
                    else 
                    { 
                        Ps2_tp_tag[tex_cache_num].TEX0 = p->TEX0 | SCE_GS_SET_TEX0_1(ps2_tp_cache[tex_cache_num].tex_addr, 0, SCE_GS_PSMCT32, 0, 0, 1, SCE_GS_MODULATE, ps2_tp_cache[tex_cache_num].clt_addr, SCE_GS_PSMCT32, 0, 0, 2); 
                        Ps2_tp_tag[tex_cache_num].TEX0_TAG = SCE_GS_TEX0_1; 
                        Ps2_tp_tag[tex_cache_num].TEX0_NEXT = p->TEX0_NEXT | SCE_GS_SET_TEX0_1(ps2_tp_cache[tex_cache_num].tex_addr, 0, SCE_GS_PSMCT32, 0, 0, 1, SCE_GS_MODULATE, ps2_tp_cache[tex_cache_num].clt_addr, SCE_GS_PSMCT32, 0, 0, 2); 
                        Ps2_tp_tag[tex_cache_num].TEX0_NEXT_TAG = SCE_GS_TEX0_1; 
                    }

                    Ps2_tp_tag[tex_cache_num].CLAMP = SCE_GS_SET_CLAMP_1(SCE_GS_CLAMP, SCE_GS_CLAMP, 255, 0, 255, 0); 
                    Ps2_tp_tag[tex_cache_num].CLAMP_TAG = SCE_GS_CLAMP_1; 
                    
                    ((long*)p->p)[0] = DMAref | 0x4 | ((long)&Ps2_tp_tag[tex_cache_num] << 32); 
                    ((long*)p->p)[1] = 0; 
                    
                    tex_cache_num++; 
                }
            } 
            else 
            { 
                ((long*)p->p)[0] = DMAref | 0x4 | ((long)&Ps2_tp_tag[t_no] << 32); 
                ((long*)p->p)[1] = 0; 
            }
            
        loop_end:
            old_p = p; 
            p = (PS2_OT*)p->op; 
        } 
    } 

    if (old_p != NULL) 
    { 
    block:
        ((long*)old_p->p)[2] = (((long*)(temp = old_p)->p)[2] & 0xFFFFFFF) | 0x70000000; 
        ((long*)old_p->p)[8] = ((long*)old_p->p)[8] | 0x8000; 
        
        printf("TEX %05d:%05d]", 0x3F80 - tex_addr, 0x3FCC - clt_addr); 
        
        save_alpha[0] = Ps2_gs_save.mode_bk[0]; 
        save_alpha[1] = Ps2_gs_save.mode_bk[1]; 
        save_alpha[2] = Ps2_gs_save.set_last; 
        
        FlushCache(0); 
        
        SyncPath();
        
        loadImage((void*)((int)start_addr & 0xFFFFFF));
        
        SyncPath(); 
        
        njColorBlendingMode(save_alpha[2] ^ 1, save_alpha[save_alpha[2] ^ 1]); 
        njColorBlendingMode(save_alpha[2], save_alpha[save_alpha[2]]); 
        
        return exit_no; 
    }
    
    return 4096; 
} 

// 100% matching!
unsigned int Ps2BitCount(register unsigned int value)
{
    asm volatile
    {
        
        addi  v0, value, -1
        addi  v1, zero, 0x1F
            
        plzcw v0, v0
            
        subu  v0, v1, v0
        
        nop
            
    }
}

// 100% matching!
void Ps2InitTexCache()
{
    unsigned int i;

    for (i = 0; i < 4; i++) 
    {
        Ps2_tex_cache_buff[i] = NULL;
        
        Ps2_tex_cache_beflag[i] = 0;
    } 
    
    Ps2_tex_cache_num = 4;
}

/*// 
// Start address: 0x2cd3a0
int Ps2GlobalIndexTexLoad(unsigned int index)
{
	int no;
	// Line 2534, Address: 0x2cd3a0, Func Offset: 0
	// Line 2537, Address: 0x2cd3ac, Func Offset: 0xc
	// Line 2538, Address: 0x2cd3b8, Func Offset: 0x18
	// Line 2539, Address: 0x2cd3c0, Func Offset: 0x20
	// Line 2540, Address: 0x2cd3dc, Func Offset: 0x3c
	// Line 2541, Address: 0x2cd3e4, Func Offset: 0x44
	// Line 2544, Address: 0x2cd3f4, Func Offset: 0x54
	// Func End, Address: 0x2cd404, Func Offset: 0x64
}*/

// 97.17% matching
int Ps2TexLoad(NJS_TEXMEMLIST* addr)
{
    unsigned int tbw;       
    unsigned int psm;     
    unsigned int tw;       
    unsigned int th;        
    unsigned int i;          
    unsigned long* p;        
    TIM2_PICTUREHEADER_EX* timp; 
    unsigned int cache_flag;  
    unsigned int temp; // not from the debugging symbols

    cache_flag = 1;

    if ((addr == NULL) || (addr->texinfo.texsurface.pSurface == NULL)) 
    {
        return printf("Ps2CurrentTexLoad ERROR!!!!\n"); 
    }

    Ps2_now_tex = addr;

    timp = (TIM2_PICTUREHEADER_EX*)addr->texinfo.texsurface.pSurface;

    if (Ps2_current_texbreak != 0) 
    {
        for (i = 0; i < 4; i++) 
        {
            Ps2_tex_cache_buff[i] = NULL;
            
            Ps2_tex_cache_beflag[i] = 0;
        }

        Ps2_current_texbreak = 0;

        goto label;
    }
    
    if (timp == Ps2_tex_cache_buff[0]) 
    {
        cache_flag = 0;
    } 
    else if ((Ps2_tex_load_tp_cancel == 0) && (timp->TpFlag != 0)) 
    {
        cache_flag = 0;
    } 
    else 
    {
label:
        Ps2_tex_cache_buff[0] = addr->texinfo.texsurface.pSurface;
        
        if ((PS2_Render_tex_sub_flag == 0) || ((timp->PictFormat >= 5) && (timp->PictFormat <= 8)) || ((timp->ImageType == 4) || (timp->ImageType == 5)))
        {
            Send_Tim2_dataEx(Ps2_tex_cache_buff[0], 190 * 64, 254 * 64);
        }
    }

    p = (unsigned long*)WORKBASE;

    D2_SyncTag();

    *p++ = DMAend | 0x7;
    *p++ = 0;

    *p++ = SCE_GS_SET_TEX0_1(6, 2, SCE_GS_PSMCT32, 0, 0, 0, SCE_GS_MODULATE, 0, SCE_GS_PSMCT32, 0, 16, 0);
    *p++ = 0xEEEEEE;

    *p++ = 0;
    *p++ = SCE_GS_TEXFLUSH;

    tbw = timp->GsTex0.TBW;
    
    tw = Ps2BitCount(timp->ImageWidth);
    th = Ps2BitCount(timp->ImageHeight);

    switch (timp->ImageType) 
    {
    default:
        psm = SCE_GS_PSMCT32;
        break;
    case 4:
        psm = SCE_GS_PSMT4;
        break;
    case 5:
        psm = SCE_GS_PSMT8;
        break;
    }

    temp = 190;

    if ((timp->PictFormat >= 5) && (timp->PictFormat <= 8)) 
    {
        Ps2_now_bank = addr->bank;
     
        *p++ = Ps2_gs_save.TEX0 = SCE_GS_SET_TEX0_1(temp * 64, tbw, SCE_GS_PSMT8, tw, th, 1, SCE_GS_MODULATE, ((addr->bank & 0x30) / 4) + 16368, SCE_GS_PSMCT32, 0, 0, 2);
        *p++ = SCE_GS_TEX0_1;

        *p++ = Ps2_gs_save.TEX0_NEXT = SCE_GS_SET_TEX0_1(temp * 64, tbw, psm, tw, th, 1, SCE_GS_MODULATE, ((addr->bank & 0x30) / 4) + 16368, SCE_GS_PSMCT32, 0, addr->bank & 0xF, 0);
        *p++ = SCE_GS_TEX0_1;
    } 
    else if (psm != 0) 
    {
        *p++ = Ps2_gs_save.TEX0 = SCE_GS_SET_TEX0_1(temp * 64, tbw, psm, tw, th, 1, SCE_GS_MODULATE, 254 * 64, SCE_GS_PSMCT32, 0, 0, 2);
        *p++ = SCE_GS_TEX0_1;

        *p++ = Ps2_gs_save.TEX0_NEXT = SCE_GS_SET_TEX0_1(temp * 64, tbw, psm, tw, th, 1, SCE_GS_MODULATE, 254 * 64, SCE_GS_PSMCT32, 0, 0, 2);
        *p++ = SCE_GS_TEX0_1;
    } 
    else if (PS2_Render_tex_sub_flag == 0)
    {
        *p++ = Ps2_gs_save.TEX0 = SCE_GS_SET_TEX0_1(temp * 64, tbw, psm, tw, th, 0, SCE_GS_MODULATE, 254 * 64, SCE_GS_PSMCT32, 0, 0, 2);
        *p++ = SCE_GS_TEX0_1;

        *p++ = Ps2_gs_save.TEX0_NEXT = SCE_GS_SET_TEX0_1(temp * 64, tbw, psm, tw, th, 0, SCE_GS_MODULATE, 254 * 64, SCE_GS_PSMCT32, 0, 0, 2);
        *p++ = SCE_GS_TEX0_1;
    } 
    else 
    {
        *p++ = Ps2_gs_save.TEX0 = SCE_GS_SET_TEX0_1((temp * 64) + (48 * 64), 4, SCE_GS_PSMCT32, 8, 8, 0, SCE_GS_MODULATE, 0, SCE_GS_PSMCT32, 0, 0, 0);
        *p++ = SCE_GS_TEX0_1;

        *p++ = Ps2_gs_save.TEX0_NEXT = SCE_GS_SET_TEX0_1((temp * 64) + (48 * 64), 4, SCE_GS_PSMCT32, 8, 8, 0, SCE_GS_MODULATE, 0, SCE_GS_PSMCT32, 0, 0, 0);
        *p++ = SCE_GS_TEX0_1;

        PS2_Render_tex_sub_flag = 0;
    }

    *p++ = Ps2_gs_save.TEX1 = SCE_GS_SET_TEX1_1(0, 0, SCE_GS_LINEAR, SCE_GS_LINEAR, 0, 0, 0);
    *p++ = SCE_GS_TEX1_1;

    *p++ = Ps2_gs_save.CLAMP = SCE_GS_SET_CLAMP_1(timp->ClampFlag, SCE_GS_REPEAT, 255, 0, 255, 0);
    *p++ = SCE_GS_CLAMP_1;

    *p++ = Ps2_gs_save.TEST = SCE_GS_SET_TEST_1(1, SCE_GS_ALPHA_GREATER, 0, SCE_GS_AFAIL_KEEP, 0, 0, 1, SCE_GS_DEPTH_GEQUAL);
    *p++ = SCE_GS_TEST_1;

    loadImage((void*)0xF0000000);

    return cache_flag;
}

// 
// Start address: 0x2cd910
void Ps2SetFogColor()
{
	// Line 2742, Address: 0x2cd910, Func Offset: 0
	// Line 2747, Address: 0x2cd918, Func Offset: 0x8
	// Line 2749, Address: 0x2cd920, Func Offset: 0x10
	// Line 2752, Address: 0x2cd930, Func Offset: 0x20
	// Line 2750, Address: 0x2cd934, Func Offset: 0x24
	// Line 2752, Address: 0x2cd938, Func Offset: 0x28
	// Line 2750, Address: 0x2cd93c, Func Offset: 0x2c
	// Line 2752, Address: 0x2cd940, Func Offset: 0x30
	// Line 2753, Address: 0x2cd950, Func Offset: 0x40
	// Line 2755, Address: 0x2cd95c, Func Offset: 0x4c
	// Line 2756, Address: 0x2cd964, Func Offset: 0x54
	// Line 2758, Address: 0x2cd968, Func Offset: 0x58
	// Line 2755, Address: 0x2cd96c, Func Offset: 0x5c
	// Line 2756, Address: 0x2cd99c, Func Offset: 0x8c
	// Line 2758, Address: 0x2cd9a0, Func Offset: 0x90
	// Line 2759, Address: 0x2cd9a8, Func Offset: 0x98
	// Line 2760, Address: 0x2cd9b0, Func Offset: 0xa0
	// Func End, Address: 0x2cd9bc, Func Offset: 0xac
	scePrintf("Ps2SetFogColor - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2cd9c0
void Ps2SetFogColorSys(unsigned int r, unsigned int g, unsigned int b)
{
	// Line 2763, Address: 0x2cd9c0, Func Offset: 0
	// Line 2768, Address: 0x2cd9dc, Func Offset: 0x1c
	// Line 2776, Address: 0x2cd9e4, Func Offset: 0x24
	// Line 2770, Address: 0x2cda0c, Func Offset: 0x4c
	// Line 2773, Address: 0x2cda1c, Func Offset: 0x5c
	// Line 2771, Address: 0x2cda20, Func Offset: 0x60
	// Line 2773, Address: 0x2cda24, Func Offset: 0x64
	// Line 2771, Address: 0x2cda28, Func Offset: 0x68
	// Line 2773, Address: 0x2cda2c, Func Offset: 0x6c
	// Line 2774, Address: 0x2cda3c, Func Offset: 0x7c
	// Line 2776, Address: 0x2cda48, Func Offset: 0x88
	// Line 2777, Address: 0x2cda58, Func Offset: 0x98
	// Line 2779, Address: 0x2cda64, Func Offset: 0xa4
	// Line 2780, Address: 0x2cda6c, Func Offset: 0xac
	// Line 2781, Address: 0x2cda74, Func Offset: 0xb4
	// Func End, Address: 0x2cda8c, Func Offset: 0xcc
}*/

// 100% matching!
void Ps2AlphaIs000(unsigned int* cp, unsigned int num)
{
    unsigned int i;
    
    for (i = 0; i < num; i++, cp++)
    {
        if ((((unsigned char*)cp)[3] != 0) && (((unsigned char*)cp)[0] == 0) && (((unsigned char*)cp)[1] == 0) && (((unsigned char*)cp)[2] == 0)) 
        {
            ((unsigned char*)cp)[3] = 0;
        }
    }
}

// 100% matching!
unsigned int Ps2AlphaIsHalf(unsigned int* cp, unsigned int num)
{
    unsigned int i;
    
    for (i = 0; i < num; i++, cp++)
    {
        ((unsigned char*)cp)[3] = (((unsigned char*)cp)[3] + 1) >> 1;
    }
}

// 100% matching!
unsigned int Ps2Alpha4to8(unsigned int* cp, unsigned int num)
{
    unsigned int i;
    unsigned int val;
    
    for (i = 0; i < num; i++, cp++)
    {
        val = ((unsigned char*)cp)[3];
        
        ((unsigned char*)cp)[3] = val | (val >> 4);
    }
}

// 100% matching!
int Ps2CheckTextureAlpha(void* pp)
{
    unsigned int *cp;  
    unsigned int num;  
    unsigned int flag; 
    unsigned int temp; // not from the debugging symbols
    TIM2_PICTUREHEADER_EX* temp2; // not from the debugging symbols

    temp2 = pp;
    
    if (temp2->ClutChange != 0)
    {
        return (unsigned short)temp2->ClutChange;
    }
    
    cp = (unsigned int*)((int)pp + temp2->ImageSize + 256);
    
    num = temp2->ClutSize >> 2;
    
    if (isVQ(temp2->PictFormat) != 0) 
    {
        switch (temp2->OrgColorType) 
        {                       
        case 0:                                     
            flag = 0x8000;
            
            printf("ARGB1555\n", temp2->OrgColorType);
            break;
        case 1:                                    
            flag = 0x8000;
            
            printf("RGB565\n", temp2->OrgColorType);
            break;
        case 2:                                    
            flag = 0x8000;
            
            Ps2Alpha4to8(cp, num);
            Ps2AlphaIsHalf(cp, num);
            
            printf("ARGB4444\n");
            break;
        case 6:                                  
            flag = 0x8000;
            
            Ps2AlphaIsHalf(cp, num);
            
            printf("ARGB8888\n");
            break;
        default:                                   
            printf("ERROR ERROR ERROR ERROR ERROR %04x\n", temp2->OrgColorType);
            break;
        }
    } 
    else 
    {
        switch (temp2->OrgColorType)
        {                       
        case 0:
            flag = 0x8000;
            
            Ps2AlphaIs000(cp, num);
            
            printf("ARGB1555\n");
            break;
        case 1:
            flag = 0x8000;
            
            Ps2AlphaIs000(cp, num);
            
            printf("RGB565\n");
            break;
        case 2:
            flag = 0x8000;
            
            Ps2AlphaIs000(cp, num);
            Ps2Alpha4to8(cp, num);
            Ps2AlphaIsHalf(cp, num);
            
            printf("ARGB4444\n");
            break;
        case 6:
            flag = 0x8000;
            
            Ps2AlphaIs000(cp, num);
            Ps2AlphaIsHalf(cp, num);
            
            printf("ARGB8888\n");
            break;
        default:
            printf("ERROR ERROR ERROR ERROR ERROR %04x\n", temp2->OrgColorType);
            break;
        }
    }
    
    temp2->ClutChange = flag;
    
    temp = temp2->Gindex & 0xFFFFF;
    
    if ((temp == 20500) || (temp == 15205) || (temp == 15206) || (temp == 15207) || (temp == 15208) || (temp == 15209))
    {
        temp2->ClampFlag = 0xFF000FF0;
    }
    else 
    {
        temp2->ClampFlag = 0xFF000FF5;
    }
 
    Ps2PxlconvCheck(pp);
    
    return flag;
}

// 96.92% matching 
void Ps2InitPS2_GS_SAVE()
{
    Ps2_gs_save.SC_TAG[0] = DMAend | 0xA;
    Ps2_gs_save.SC_TAG[1] = 0;
    
    Ps2_gs_save.GIF_TAG[0] = SCE_GIF_SET_TAG(9, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    Ps2_gs_save.GIF_TAG[1] = SCE_GIF_PACKED_AD;
    
    Ps2_gs_save.TEX0 = 0;
    Ps2_gs_save.TEX0_TAG = SCE_GS_TEX0_1;
    
    Ps2_gs_save.TEX0_NEXT = 0;
    Ps2_gs_save.TEX0_NEXT_TAG = SCE_GS_TEX0_1;
    
    Ps2_gs_save.TEX1 = 0;
    Ps2_gs_save.TEX1_TAG = SCE_GS_TEX1_1;
    
    Ps2_gs_save.CLAMP = 0;
    Ps2_gs_save.CLAMP_TAG = SCE_GS_CLAMP_1;
    
    Ps2_gs_save.TEST = 0;
    Ps2_gs_save.TEST_TAG = SCE_GS_TEST_1;
    
    Ps2_gs_save.FOGCOL = 0;
    Ps2_gs_save.FOGCOL_TAG = SCE_GS_FOGCOL;
    
    Ps2_gs_save.ALPHA = 0;
    Ps2_gs_save.ALPHA_TAG = SCE_GS_ALPHA_1;
    
    Ps2_gs_save.FBA = 0;
    Ps2_gs_save.FBA_TAG = SCE_GS_FBA_1;
    
    Ps2_gs_save.SCISSOR = 0;
    Ps2_gs_save.SCISSOR_TAG = SCE_GS_SCISSOR_1;

    Ps2_gs_save.mode_bk[0] = 0;
    Ps2_gs_save.pad64 = 0;
    
    FlushCache(0);
}

// 100% matching! 
void Ps2ScreenClear()
{
    SyncPath();

    ((u_long*)WORKBASE)[0] = DMAend | 0x8; 
    ((u_long*)WORKBASE)[1] = 0;

    ((u_long*)WORKBASE)[2] = SCE_GIF_SET_TAG(7, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    ((u_long*)WORKBASE)[3] = SCE_GIF_PACKED_AD;
    
    ((u_long*)WORKBASE)[4] = SCE_GS_SET_FRAME_2(0, 10, SCE_GS_PSMCT32, 0);
    ((u_long*)WORKBASE)[5] = SCE_GS_FRAME_2;
    
    ((u_long*)WORKBASE)[6] = SCE_GS_SET_TEST_2(0, SCE_GS_ALPHA_NEVER, 0, SCE_GS_AFAIL_KEEP, 0, 0, 1, SCE_GS_DEPTH_ALWAYS);
    ((u_long*)WORKBASE)[7] = SCE_GS_TEST_2;
    
    ((u_long*)WORKBASE)[8] = SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 0, 0, 0, 0, 0, 1, 0);
    ((u_long*)WORKBASE)[9] = SCE_GS_PRIM;
    
    ((u_long*)WORKBASE)[10] = SCE_GS_SET_RGBAQ(0, 0, 0, 0, 0);
    ((u_long*)WORKBASE)[11] = SCE_GS_RGBAQ;
    
    ((u_long*)WORKBASE)[12] = SCE_GS_SET_XYZF(GS_X_COORD(0), GS_Y_COORD(-128), 0, 0);
    ((u_long*)WORKBASE)[13] = SCE_GS_XYZF2;
    
    ((u_long*)WORKBASE)[14] = SCE_GS_SET_XYZF(GS_X_COORD(640), GS_Y_COORD(352), 0, 0);
    ((u_long*)WORKBASE)[15] = SCE_GS_XYZF2;
    
    ((u_long*)WORKBASE)[16] = SCE_GS_SET_TEST_2(0, SCE_GS_ALPHA_NEVER, 0, SCE_GS_AFAIL_KEEP, 0, 0, 1, SCE_GS_DEPTH_GEQUAL);
    ((u_long*)WORKBASE)[17] = SCE_GS_TEST_2;
    
    loadImage((void*)0xF0000000);
 
    D2_SyncTag();
    SyncPath();
}

// 100% matching! 
void Ps2DispScreenClear()
{
    SyncPath();

    ((u_long*)WORKBASE)[0] = DMAend | 0x8; 
    ((u_long*)WORKBASE)[1] = 0;

    ((u_long*)WORKBASE)[2] = SCE_GIF_SET_TAG(7, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    ((u_long*)WORKBASE)[3] = SCE_GIF_PACKED_AD;
    
    ((u_long*)WORKBASE)[4] = SCE_GS_SET_FRAME_2(0, 10, SCE_GS_PSMCT32, 0) | 0x96;
    ((u_long*)WORKBASE)[5] = SCE_GS_FRAME_2;
    
    ((u_long*)WORKBASE)[6] = SCE_GS_SET_TEST_2(0, SCE_GS_ALPHA_NEVER, 0, SCE_GS_AFAIL_KEEP, 0, 0, 1, SCE_GS_DEPTH_ALWAYS);
    ((u_long*)WORKBASE)[7] = SCE_GS_TEST_2;
    
    ((u_long*)WORKBASE)[8] = SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 0, 0, 0, 0, 0, 1, 0);
    ((u_long*)WORKBASE)[9] = SCE_GS_PRIM;
    
    ((u_long*)WORKBASE)[10] = SCE_GS_SET_RGBAQ(0, 0, 0, 0, 0);
    ((u_long*)WORKBASE)[11] = SCE_GS_RGBAQ;
    
    ((u_long*)WORKBASE)[12] = SCE_GS_SET_XYZF(GS_X_COORD(0), GS_Y_COORD(-128), 0, 0);
    ((u_long*)WORKBASE)[13] = SCE_GS_XYZF2;
    
    ((u_long*)WORKBASE)[14] = SCE_GS_SET_XYZF(GS_X_COORD(640), GS_Y_COORD(352), 0, 0);
    ((u_long*)WORKBASE)[15] = SCE_GS_XYZF2;
    
    ((u_long*)WORKBASE)[16] = SCE_GS_SET_TEST_2(0, SCE_GS_ALPHA_NEVER, 0, SCE_GS_AFAIL_KEEP, 0, 0, 1, SCE_GS_DEPTH_GEQUAL);
    ((u_long*)WORKBASE)[17] = SCE_GS_TEST_2;
    
    loadImage((void*)0xF0000000);
 
    D2_SyncTag();
    SyncPath();
}

// 100% matching! 
void Ps2ZbuffOff()
{
    D2_SyncTag();
    
    ((u_long*)WORKBASE)[0] = DMAend | 0x2;
    ((u_long*)WORKBASE)[1] = 0;
    
    ((u_long*)WORKBASE)[2] = SCE_GIF_SET_TAG(1, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    ((u_long*)WORKBASE)[3] = SCE_GIF_PACKED_AD;
    
    ((u_long*)WORKBASE)[4] = SCE_GS_SET_TEST_1(1, SCE_GS_ALPHA_GEQUAL, 128, SCE_GS_AFAIL_FB_ONLY, 0, 0, 1, SCE_GS_DEPTH_GEQUAL);
    ((u_long*)WORKBASE)[5] = SCE_GS_TEST_1;
    
    loadImage((void*)0xF0000000);
    
    D2_SyncTag();
}

/*// 
// Start address: 0x2ce1e0
void Ps2ZbuffOff2()
{
	// Line 3641, Address: 0x2ce1e0, Func Offset: 0
	// Line 3645, Address: 0x2ce1e8, Func Offset: 0x8
	// Line 3647, Address: 0x2ce1f0, Func Offset: 0x10
	// Line 3650, Address: 0x2ce200, Func Offset: 0x20
	// Line 3648, Address: 0x2ce204, Func Offset: 0x24
	// Line 3650, Address: 0x2ce208, Func Offset: 0x28
	// Line 3648, Address: 0x2ce20c, Func Offset: 0x2c
	// Line 3650, Address: 0x2ce210, Func Offset: 0x30
	// Line 3651, Address: 0x2ce220, Func Offset: 0x40
	// Line 3653, Address: 0x2ce22c, Func Offset: 0x4c
	// Line 3654, Address: 0x2ce248, Func Offset: 0x68
	// Line 3656, Address: 0x2ce254, Func Offset: 0x74
	// Line 3657, Address: 0x2ce264, Func Offset: 0x84
	// Line 3659, Address: 0x2ce270, Func Offset: 0x90
	// Line 3660, Address: 0x2ce278, Func Offset: 0x98
	// Line 3661, Address: 0x2ce280, Func Offset: 0xa0
	// Func End, Address: 0x2ce28c, Func Offset: 0xac
}*/

// 100% matching! 
void Ps2ZbuffOn()
{
    D2_SyncTag();
    
    ((u_long*)WORKBASE)[0] = DMAend | 0x3;
    ((u_long*)WORKBASE)[1] = 0;
    
    ((u_long*)WORKBASE)[2] = SCE_GIF_SET_TAG(2, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    ((u_long*)WORKBASE)[3] = SCE_GIF_PACKED_AD;
    
    ((u_long*)WORKBASE)[4] = SCE_GS_SET_ZBUF_1(300, SCE_GS_PSMCT16S, 0);
    ((u_long*)WORKBASE)[5] = SCE_GS_ZBUF_1;
    
    ((u_long*)WORKBASE)[6] = SCE_GS_SET_TEST_1(1, SCE_GS_ALPHA_GREATER, 0, SCE_GS_AFAIL_KEEP, 0, 0, 1, SCE_GS_DEPTH_GEQUAL);
    ((u_long*)WORKBASE)[7] = SCE_GS_TEST_1;
    
    loadImage((void*)0xF0000000);
    
    D2_SyncTag();
}

/*// 
// Start address: 0x2ce330
void Ps2ShadowStart()
{
	// Line 3688, Address: 0x2ce330, Func Offset: 0
	// Line 3691, Address: 0x2ce334, Func Offset: 0x4
	// Line 3688, Address: 0x2ce338, Func Offset: 0x8
	// Line 3691, Address: 0x2ce33c, Func Offset: 0xc
	// Line 3694, Address: 0x2ce340, Func Offset: 0x10
	// Line 3696, Address: 0x2ce348, Func Offset: 0x18
	// Line 3699, Address: 0x2ce358, Func Offset: 0x28
	// Line 3697, Address: 0x2ce35c, Func Offset: 0x2c
	// Line 3699, Address: 0x2ce360, Func Offset: 0x30
	// Line 3697, Address: 0x2ce364, Func Offset: 0x34
	// Line 3699, Address: 0x2ce368, Func Offset: 0x38
	// Line 3700, Address: 0x2ce378, Func Offset: 0x48
	// Line 3703, Address: 0x2ce384, Func Offset: 0x54
	// Line 3710, Address: 0x2ce394, Func Offset: 0x64
	// Line 3705, Address: 0x2ce398, Func Offset: 0x68
	// Line 3707, Address: 0x2ce3a4, Func Offset: 0x74
	// Line 3710, Address: 0x2ce3b0, Func Offset: 0x80
	// Line 3708, Address: 0x2ce3b4, Func Offset: 0x84
	// Line 3710, Address: 0x2ce3c0, Func Offset: 0x90
	// Line 3711, Address: 0x2ce3d4, Func Offset: 0xa4
	// Line 3713, Address: 0x2ce3e0, Func Offset: 0xb0
	// Line 3714, Address: 0x2ce3ec, Func Offset: 0xbc
	// Line 3716, Address: 0x2ce3f4, Func Offset: 0xc4
	// Line 3717, Address: 0x2ce3fc, Func Offset: 0xcc
	// Line 3719, Address: 0x2ce404, Func Offset: 0xd4
	// Line 3722, Address: 0x2ce414, Func Offset: 0xe4
	// Line 3720, Address: 0x2ce41c, Func Offset: 0xec
	// Line 3722, Address: 0x2ce428, Func Offset: 0xf8
	// Line 3723, Address: 0x2ce434, Func Offset: 0x104
	// Line 3725, Address: 0x2ce43c, Func Offset: 0x10c
	// Line 3728, Address: 0x2ce448, Func Offset: 0x118
	// Line 3726, Address: 0x2ce44c, Func Offset: 0x11c
	// Line 3728, Address: 0x2ce450, Func Offset: 0x120
	// Line 3726, Address: 0x2ce454, Func Offset: 0x124
	// Line 3728, Address: 0x2ce458, Func Offset: 0x128
	// Line 3729, Address: 0x2ce468, Func Offset: 0x138
	// Line 3731, Address: 0x2ce474, Func Offset: 0x144
	// Line 3732, Address: 0x2ce47c, Func Offset: 0x14c
	// Func End, Address: 0x2ce488, Func Offset: 0x158
}

// 
// Start address: 0x2ce490
void Ps2ShadowDraw()
{
	int iv0[4];
	int iv4[4];
	unsigned long xy1;
	unsigned long xy0;
	unsigned long uv1;
	unsigned long uv0;
	// Line 3735, Address: 0x2ce490, Func Offset: 0
	// Line 3747, Address: 0x2ce4a8, Func Offset: 0x18
	// Line 3748, Address: 0x2ce4ec, Func Offset: 0x5c
	// Line 3749, Address: 0x2ce518, Func Offset: 0x88
	// Line 3750, Address: 0x2ce544, Func Offset: 0xb4
	// Line 3753, Address: 0x2ce570, Func Offset: 0xe0
	// Line 3754, Address: 0x2ce590, Func Offset: 0x100
	// Line 3755, Address: 0x2ce5bc, Func Offset: 0x12c
	// Line 3756, Address: 0x2ce5e8, Func Offset: 0x158
	// Line 3757, Address: 0x2ce614, Func Offset: 0x184
	// Line 3758, Address: 0x2ce640, Func Offset: 0x1b0
	// Line 3759, Address: 0x2ce66c, Func Offset: 0x1dc
	// Line 3760, Address: 0x2ce698, Func Offset: 0x208
	// Line 3762, Address: 0x2ce6c4, Func Offset: 0x234
	// Line 3763, Address: 0x2ce6d4, Func Offset: 0x244
	// Line 3764, Address: 0x2ce6dc, Func Offset: 0x24c
	// Line 3765, Address: 0x2ce6e4, Func Offset: 0x254
	// Line 3766, Address: 0x2ce6ec, Func Offset: 0x25c
	// Line 3768, Address: 0x2ce6f4, Func Offset: 0x264
	// Line 3769, Address: 0x2ce700, Func Offset: 0x270
	// Line 3771, Address: 0x2ce710, Func Offset: 0x280
	// Line 3773, Address: 0x2ce714, Func Offset: 0x284
	// Line 3771, Address: 0x2ce718, Func Offset: 0x288
	// Line 3773, Address: 0x2ce71c, Func Offset: 0x28c
	// Line 3774, Address: 0x2ce720, Func Offset: 0x290
	// Line 3773, Address: 0x2ce724, Func Offset: 0x294
	// Line 3772, Address: 0x2ce728, Func Offset: 0x298
	// Line 3773, Address: 0x2ce730, Func Offset: 0x2a0
	// Line 3774, Address: 0x2ce734, Func Offset: 0x2a4
	// Line 3773, Address: 0x2ce738, Func Offset: 0x2a8
	// Line 3774, Address: 0x2ce73c, Func Offset: 0x2ac
	// Line 3773, Address: 0x2ce740, Func Offset: 0x2b0
	// Line 3774, Address: 0x2ce748, Func Offset: 0x2b8
	// Line 3773, Address: 0x2ce74c, Func Offset: 0x2bc
	// Line 3774, Address: 0x2ce750, Func Offset: 0x2c0
	// Line 3773, Address: 0x2ce760, Func Offset: 0x2d0
	// Line 3774, Address: 0x2ce764, Func Offset: 0x2d4
	// Line 3773, Address: 0x2ce768, Func Offset: 0x2d8
	// Line 3774, Address: 0x2ce770, Func Offset: 0x2e0
	// Line 3773, Address: 0x2ce778, Func Offset: 0x2e8
	// Line 3774, Address: 0x2ce780, Func Offset: 0x2f0
	// Line 3773, Address: 0x2ce788, Func Offset: 0x2f8
	// Line 3784, Address: 0x2ce78c, Func Offset: 0x2fc
	// Line 3786, Address: 0x2ce794, Func Offset: 0x304
	// Line 3789, Address: 0x2ce7a4, Func Offset: 0x314
	// Line 3787, Address: 0x2ce7ac, Func Offset: 0x31c
	// Line 3789, Address: 0x2ce7b0, Func Offset: 0x320
	// Line 3787, Address: 0x2ce7b4, Func Offset: 0x324
	// Line 3789, Address: 0x2ce7b8, Func Offset: 0x328
	// Line 3790, Address: 0x2ce7c8, Func Offset: 0x338
	// Line 3792, Address: 0x2ce7e8, Func Offset: 0x358
	// Line 3793, Address: 0x2ce7f4, Func Offset: 0x364
	// Line 3795, Address: 0x2ce800, Func Offset: 0x370
	// Line 3796, Address: 0x2ce810, Func Offset: 0x380
	// Line 3799, Address: 0x2ce81c, Func Offset: 0x38c
	// Line 3800, Address: 0x2ce838, Func Offset: 0x3a8
	// Line 3815, Address: 0x2ce844, Func Offset: 0x3b4
	// Line 3816, Address: 0x2ce888, Func Offset: 0x3f8
	// Line 3818, Address: 0x2ce894, Func Offset: 0x404
	// Line 3819, Address: 0x2ce89c, Func Offset: 0x40c
	// Line 3822, Address: 0x2ce8a8, Func Offset: 0x418
	// Line 3824, Address: 0x2ce8b0, Func Offset: 0x420
	// Line 3826, Address: 0x2ce8b8, Func Offset: 0x428
	// Line 3827, Address: 0x2ce8c0, Func Offset: 0x430
	// Line 3830, Address: 0x2ce8c8, Func Offset: 0x438
	// Line 3832, Address: 0x2ce8d0, Func Offset: 0x440
	// Line 3835, Address: 0x2ce8d8, Func Offset: 0x448
	// Line 3836, Address: 0x2ce8e0, Func Offset: 0x450
	// Line 3839, Address: 0x2ce8ec, Func Offset: 0x45c
	// Line 3840, Address: 0x2ce8fc, Func Offset: 0x46c
	// Line 3842, Address: 0x2ce908, Func Offset: 0x478
	// Line 3843, Address: 0x2ce914, Func Offset: 0x484
	// Line 3845, Address: 0x2ce920, Func Offset: 0x490
	// Line 3846, Address: 0x2ce92c, Func Offset: 0x49c
	// Line 3848, Address: 0x2ce934, Func Offset: 0x4a4
	// Line 3849, Address: 0x2ce93c, Func Offset: 0x4ac
	// Line 3851, Address: 0x2ce944, Func Offset: 0x4b4
	// Line 3853, Address: 0x2ce94c, Func Offset: 0x4bc
	// Line 3855, Address: 0x2ce954, Func Offset: 0x4c4
	// Line 3857, Address: 0x2ce95c, Func Offset: 0x4cc
	// Line 3859, Address: 0x2ce964, Func Offset: 0x4d4
	// Line 3860, Address: 0x2ce970, Func Offset: 0x4e0
	// Line 3862, Address: 0x2ce978, Func Offset: 0x4e8
	// Line 3864, Address: 0x2ce980, Func Offset: 0x4f0
	// Func End, Address: 0x2ce99c, Func Offset: 0x50c
}

// 
// Start address: 0x2ce9a0
void Ps2ShadowMain0()
{
	unsigned long shadow_head[8];
	// Line 3899, Address: 0x2ce9a0, Func Offset: 0
	// Line 3900, Address: 0x2ce9ac, Func Offset: 0xc
	// Line 3901, Address: 0x2ce9b4, Func Offset: 0x14
	// Line 3902, Address: 0x2ce9c0, Func Offset: 0x20
	// Line 3903, Address: 0x2ce9c8, Func Offset: 0x28
	// Func End, Address: 0x2ce9d4, Func Offset: 0x34
}

// 
// Start address: 0x2ce9e0
void Ps2ShadowMain1()
{
	unsigned long shadow_tail[6];
	// Line 3915, Address: 0x2ce9e0, Func Offset: 0
	// Func End, Address: 0x2ce9ec, Func Offset: 0xc
}*/

// 100% matching! 
void Ps2ShadowEnd()
{
    D2_SyncTag();
    
    ((u_long*)WORKBASE)[0] = DMAend | 0x5;
    ((u_long*)WORKBASE)[1] = 0;
    
    ((u_long*)WORKBASE)[2] = SCE_GIF_SET_TAG(4, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    ((u_long*)WORKBASE)[3] = SCE_GIF_PACKED_AD;
    
    ((u_long*)WORKBASE)[4] = SCE_GS_SET_FRAME_2(0, 10, SCE_GS_PSMCT32, 0); 
    ((u_long*)WORKBASE)[5] = SCE_GS_FRAME_2;
    
    ((u_long*)WORKBASE)[6] = SCE_GS_SET_TEST_2(0, SCE_GS_ALPHA_NEVER, 0, SCE_GS_AFAIL_KEEP, 0, 0, 1, SCE_GS_DEPTH_GEQUAL);
    ((u_long*)WORKBASE)[7] = SCE_GS_TEST_2;
    
    ((u_long*)WORKBASE)[8] = SCE_GS_SET_ZBUF_2(300, SCE_GS_PSMZ16S, 0);
    ((u_long*)WORKBASE)[9] = SCE_GS_ZBUF_2;
    
    ((u_long*)WORKBASE)[10] = SCE_GS_SET_ALPHA_2(SCE_GS_ALPHA_CS, SCE_GS_ALPHA_CS, SCE_GS_ALPHA_AS, SCE_GS_ALPHA_CS, 0);
    ((u_long*)WORKBASE)[11] = SCE_GS_ALPHA_2;
    
    loadImage((void*)0xF0000000);
}

// 99.44% matching
void Ps2Vu0ProgSend(unsigned int prog_no)
{
    static void* prog_table[3] = {
        &ps2_vu0sub0,
        &ps2_vu0sub0, 
        &ps2_vu0sub0
    };
    
    sceDmaSend((sceDmaChan*)0x10008000, prog_table[prog_no]);
    sceDmaSync((sceDmaChan*)0x10008000, 0, 0);
}

// 99.44% matching
void Ps2Vu1ProgSend(unsigned int prog_no)
{
    static void* prog_table[2] = {
        &ps2_vu1sub0,
        &ps2_vu1sub1
    };
    
    sceDmaSend((sceDmaChan*)0x10009000, prog_table[prog_no]);
    sceDmaSync((sceDmaChan*)0x10009000, 0, 0);
}

// 
// Start address: 0x2ceb50
void Ps2AddPrim3DExI(unsigned long prim, void* dp, unsigned int num)
{
	float max;
	//float max;
	//float max;
	float fz[4][3];
	int j;
	//<unknown fundamental type (0xa510)>* p128;
	unsigned long* pp;
	float zbuff_ab_vec[4];
	float zsum;
	unsigned int st_clip_flag;
	unsigned int clut_flag;
	unsigned int clip_flag;
	//_anon0* timp;
	unsigned long* p;
	float zclip_ab_vec[4];
	float near_far_vec[4];
	float clip_vec[4];
	// Line 4073, Address: 0x2ceb50, Func Offset: 0
	// Line 4085, Address: 0x2ceb60, Func Offset: 0x10
	// Line 4073, Address: 0x2ceb64, Func Offset: 0x14
	// Line 4085, Address: 0x2ceb6c, Func Offset: 0x1c
	// Line 4089, Address: 0x2ceb90, Func Offset: 0x40
	// Line 4085, Address: 0x2ceb9c, Func Offset: 0x4c
	// Line 4089, Address: 0x2cebb8, Func Offset: 0x68
	// Line 4090, Address: 0x2cebc0, Func Offset: 0x70
	// Line 4092, Address: 0x2cebd0, Func Offset: 0x80
	// Line 4093, Address: 0x2cebe4, Func Offset: 0x94
	// Line 4094, Address: 0x2cebf4, Func Offset: 0xa4
	// Line 4097, Address: 0x2cec14, Func Offset: 0xc4
	// Line 4098, Address: 0x2cec28, Func Offset: 0xd8
	// Line 4099, Address: 0x2cec34, Func Offset: 0xe4
	// Line 4100, Address: 0x2cec40, Func Offset: 0xf0
	// Line 4101, Address: 0x2cec48, Func Offset: 0xf8
	// Line 4102, Address: 0x2cec50, Func Offset: 0x100
	// Line 4113, Address: 0x2cec58, Func Offset: 0x108
	// Line 4114, Address: 0x2cec5c, Func Offset: 0x10c
	// Line 4116, Address: 0x2cec64, Func Offset: 0x114
	// Line 4119, Address: 0x2cec68, Func Offset: 0x118
	// Line 4116, Address: 0x2cec78, Func Offset: 0x128
	// Line 4117, Address: 0x2cec9c, Func Offset: 0x14c
	// Line 4119, Address: 0x2ceca4, Func Offset: 0x154
	// Line 4120, Address: 0x2cecac, Func Offset: 0x15c
	// Line 4123, Address: 0x2cecb4, Func Offset: 0x164
	// Line 4120, Address: 0x2cecb8, Func Offset: 0x168
	// Line 4123, Address: 0x2cecbc, Func Offset: 0x16c
	// Line 4126, Address: 0x2ceccc, Func Offset: 0x17c
	// Line 4123, Address: 0x2cece0, Func Offset: 0x190
	// Line 4124, Address: 0x2cece4, Func Offset: 0x194
	// Line 4126, Address: 0x2cecec, Func Offset: 0x19c
	// Line 4124, Address: 0x2cecf4, Func Offset: 0x1a4
	// Line 4129, Address: 0x2cecf8, Func Offset: 0x1a8
	// Line 4126, Address: 0x2cecfc, Func Offset: 0x1ac
	// Line 4127, Address: 0x2ced08, Func Offset: 0x1b8
	// Line 4129, Address: 0x2ced10, Func Offset: 0x1c0
	// Line 4127, Address: 0x2ced24, Func Offset: 0x1d4
	// Line 4129, Address: 0x2ced28, Func Offset: 0x1d8
	// Line 4132, Address: 0x2ced34, Func Offset: 0x1e4
	// Line 4133, Address: 0x2ced38, Func Offset: 0x1e8
	// Line 4134, Address: 0x2ced3c, Func Offset: 0x1ec
	// Line 4135, Address: 0x2ced40, Func Offset: 0x1f0
	// Line 4136, Address: 0x2ced44, Func Offset: 0x1f4
	// Line 4137, Address: 0x2ced48, Func Offset: 0x1f8
	// Line 4139, Address: 0x2ced4c, Func Offset: 0x1fc
	// Line 4138, Address: 0x2ced50, Func Offset: 0x200
	// Line 4139, Address: 0x2ced54, Func Offset: 0x204
	// Line 4140, Address: 0x2ced58, Func Offset: 0x208
	// Line 4141, Address: 0x2ced5c, Func Offset: 0x20c
	// Line 4142, Address: 0x2ced60, Func Offset: 0x210
	// Line 4143, Address: 0x2ced64, Func Offset: 0x214
	// Line 4144, Address: 0x2ced68, Func Offset: 0x218
	// Line 4146, Address: 0x2ced6c, Func Offset: 0x21c
	// Line 4147, Address: 0x2ced70, Func Offset: 0x220
	// Line 4148, Address: 0x2ced74, Func Offset: 0x224
	// Line 4150, Address: 0x2ced78, Func Offset: 0x228
	// Line 4151, Address: 0x2ced7c, Func Offset: 0x22c
	// Line 4152, Address: 0x2ced80, Func Offset: 0x230
	// Line 4153, Address: 0x2ced84, Func Offset: 0x234
	// Line 4154, Address: 0x2ced88, Func Offset: 0x238
	// Line 4156, Address: 0x2ced8c, Func Offset: 0x23c
	// Line 4157, Address: 0x2ced90, Func Offset: 0x240
	// Line 4158, Address: 0x2ced94, Func Offset: 0x244
	// Line 4159, Address: 0x2ced98, Func Offset: 0x248
	// Line 4160, Address: 0x2ced9c, Func Offset: 0x24c
	// Line 4161, Address: 0x2ceda0, Func Offset: 0x250
	// Line 4162, Address: 0x2ceda4, Func Offset: 0x254
	// Line 4163, Address: 0x2ceda8, Func Offset: 0x258
	// Line 4164, Address: 0x2cedac, Func Offset: 0x25c
	// Line 4165, Address: 0x2cedb0, Func Offset: 0x260
	// Line 4166, Address: 0x2cedb4, Func Offset: 0x264
	// Line 4168, Address: 0x2cedbc, Func Offset: 0x26c
	// Line 4170, Address: 0x2cedc0, Func Offset: 0x270
	// Line 4171, Address: 0x2cedc4, Func Offset: 0x274
	// Line 4172, Address: 0x2cedc8, Func Offset: 0x278
	// Line 4173, Address: 0x2cedcc, Func Offset: 0x27c
	// Line 4174, Address: 0x2cedd0, Func Offset: 0x280
	// Line 4175, Address: 0x2cedd4, Func Offset: 0x284
	// Line 4176, Address: 0x2cedd8, Func Offset: 0x288
	// Line 4177, Address: 0x2ceddc, Func Offset: 0x28c
	// Line 4178, Address: 0x2cede0, Func Offset: 0x290
	// Line 4180, Address: 0x2cede8, Func Offset: 0x298
	// Line 4181, Address: 0x2cedec, Func Offset: 0x29c
	// Line 4183, Address: 0x2cedf4, Func Offset: 0x2a4
	// Line 4184, Address: 0x2cedf8, Func Offset: 0x2a8
	// Line 4198, Address: 0x2cedfc, Func Offset: 0x2ac
	// Line 4199, Address: 0x2cee10, Func Offset: 0x2c0
	// Line 4200, Address: 0x2cee24, Func Offset: 0x2d4
	// Line 4201, Address: 0x2cee34, Func Offset: 0x2e4
	// Line 4206, Address: 0x2cee54, Func Offset: 0x304
	// Line 4208, Address: 0x2cee6c, Func Offset: 0x31c
	// Line 4210, Address: 0x2cee70, Func Offset: 0x320
	// Line 4225, Address: 0x2cee78, Func Offset: 0x328
	// Line 4210, Address: 0x2cee7c, Func Offset: 0x32c
	// Line 4213, Address: 0x2cee80, Func Offset: 0x330
	// Line 4211, Address: 0x2cee88, Func Offset: 0x338
	// Line 4213, Address: 0x2cee8c, Func Offset: 0x33c
	// Line 4211, Address: 0x2cee90, Func Offset: 0x340
	// Line 4213, Address: 0x2cee94, Func Offset: 0x344
	// Line 4214, Address: 0x2ceea0, Func Offset: 0x350
	// Line 4217, Address: 0x2ceea8, Func Offset: 0x358
	// Line 4214, Address: 0x2ceeac, Func Offset: 0x35c
	// Line 4217, Address: 0x2ceeb0, Func Offset: 0x360
	// Line 4218, Address: 0x2ceec4, Func Offset: 0x374
	// Line 4220, Address: 0x2ceecc, Func Offset: 0x37c
	// Line 4221, Address: 0x2ceeec, Func Offset: 0x39c
	// Line 4218, Address: 0x2cef00, Func Offset: 0x3b0
	// Line 4221, Address: 0x2cef04, Func Offset: 0x3b4
	// Line 4223, Address: 0x2cef10, Func Offset: 0x3c0
	// Line 4226, Address: 0x2cef18, Func Offset: 0x3c8
	// Line 4227, Address: 0x2cef24, Func Offset: 0x3d4
	// Line 4230, Address: 0x2cef38, Func Offset: 0x3e8
	// Line 4227, Address: 0x2cef3c, Func Offset: 0x3ec
	// Line 4228, Address: 0x2cef40, Func Offset: 0x3f0
	// Line 4229, Address: 0x2cef48, Func Offset: 0x3f8
	// Line 4230, Address: 0x2cef50, Func Offset: 0x400
	// Line 4231, Address: 0x2cef58, Func Offset: 0x408
	// Line 4233, Address: 0x2cef60, Func Offset: 0x410
	// Line 4236, Address: 0x2cef78, Func Offset: 0x428
	// Line 4233, Address: 0x2cef84, Func Offset: 0x434
	// Line 4234, Address: 0x2cef88, Func Offset: 0x438
	// Line 4236, Address: 0x2cef8c, Func Offset: 0x43c
	// Line 4239, Address: 0x2cef94, Func Offset: 0x444
	// Line 4234, Address: 0x2cef98, Func Offset: 0x448
	// Line 4235, Address: 0x2cef9c, Func Offset: 0x44c
	// Line 4239, Address: 0x2cefa0, Func Offset: 0x450
	// Line 4235, Address: 0x2cefb0, Func Offset: 0x460
	// Line 4236, Address: 0x2cefb4, Func Offset: 0x464
	// Line 4242, Address: 0x2cefb8, Func Offset: 0x468
	// Line 4236, Address: 0x2cefc0, Func Offset: 0x470
	// Line 4237, Address: 0x2cefc4, Func Offset: 0x474
	// Line 4238, Address: 0x2cefcc, Func Offset: 0x47c
	// Line 4239, Address: 0x2cefd4, Func Offset: 0x484
	// Line 4240, Address: 0x2cefdc, Func Offset: 0x48c
	// Line 4241, Address: 0x2cefe4, Func Offset: 0x494
	// Line 4242, Address: 0x2cefe8, Func Offset: 0x498
	// Line 4243, Address: 0x2ceff0, Func Offset: 0x4a0
	// Line 4244, Address: 0x2ceffc, Func Offset: 0x4ac
	// Line 4248, Address: 0x2cf008, Func Offset: 0x4b8
	// Line 4252, Address: 0x2cf038, Func Offset: 0x4e8
	// Line 4253, Address: 0x2cf060, Func Offset: 0x510
	// Line 4255, Address: 0x2cf078, Func Offset: 0x528
	// Line 4257, Address: 0x2cf088, Func Offset: 0x538
	// Line 4261, Address: 0x2cf090, Func Offset: 0x540
	// Line 4263, Address: 0x2cf0a8, Func Offset: 0x558
	// Line 4261, Address: 0x2cf0ac, Func Offset: 0x55c
	// Line 4263, Address: 0x2cf0b0, Func Offset: 0x560
	// Line 4261, Address: 0x2cf0b8, Func Offset: 0x568
	// Line 4263, Address: 0x2cf0bc, Func Offset: 0x56c
	// Line 4265, Address: 0x2cf0c4, Func Offset: 0x574
	// Line 4269, Address: 0x2cf0cc, Func Offset: 0x57c
	// Line 4270, Address: 0x2cf0f0, Func Offset: 0x5a0
	// Line 4272, Address: 0x2cf108, Func Offset: 0x5b8
	// Line 4277, Address: 0x2cf118, Func Offset: 0x5c8
	// Line 4278, Address: 0x2cf134, Func Offset: 0x5e4
	// Line 4284, Address: 0x2cf13c, Func Offset: 0x5ec
	// Line 4287, Address: 0x2cf160, Func Offset: 0x610
	// Line 4289, Address: 0x2cf168, Func Offset: 0x618
	// Line 4290, Address: 0x2cf170, Func Offset: 0x620
	// Line 4293, Address: 0x2cf178, Func Offset: 0x628
	// Func End, Address: 0x2cf190, Func Offset: 0x640
	scePrintf("Ps2AddPrim3DExI - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2cf190
void PS2_Render_Tex_Sub()
{
	// Line 4302, Address: 0x2cf190, Func Offset: 0
	// Line 4305, Address: 0x2cf194, Func Offset: 0x4
	// Line 4302, Address: 0x2cf198, Func Offset: 0x8
	// Line 4305, Address: 0x2cf19c, Func Offset: 0xc
	// Line 4309, Address: 0x2cf1a0, Func Offset: 0x10
	// Line 4311, Address: 0x2cf1a8, Func Offset: 0x18
	// Line 4343, Address: 0x2cf1b8, Func Offset: 0x28
	// Line 4314, Address: 0x2cf1bc, Func Offset: 0x2c
	// Line 4312, Address: 0x2cf1c0, Func Offset: 0x30
	// Line 4314, Address: 0x2cf1c4, Func Offset: 0x34
	// Line 4312, Address: 0x2cf1c8, Func Offset: 0x38
	// Line 4314, Address: 0x2cf1cc, Func Offset: 0x3c
	// Line 4315, Address: 0x2cf1dc, Func Offset: 0x4c
	// Line 4317, Address: 0x2cf1e8, Func Offset: 0x58
	// Line 4318, Address: 0x2cf1f8, Func Offset: 0x68
	// Line 4320, Address: 0x2cf204, Func Offset: 0x74
	// Line 4321, Address: 0x2cf20c, Func Offset: 0x7c
	// Line 4322, Address: 0x2cf218, Func Offset: 0x88
	// Line 4331, Address: 0x2cf224, Func Offset: 0x94
	// Line 4323, Address: 0x2cf234, Func Offset: 0xa4
	// Line 4325, Address: 0x2cf240, Func Offset: 0xb0
	// Line 4326, Address: 0x2cf248, Func Offset: 0xb8
	// Line 4327, Address: 0x2cf254, Func Offset: 0xc4
	// Line 4328, Address: 0x2cf260, Func Offset: 0xd0
	// Line 4331, Address: 0x2cf26c, Func Offset: 0xdc
	// Line 4332, Address: 0x2cf278, Func Offset: 0xe8
	// Line 4334, Address: 0x2cf284, Func Offset: 0xf4
	// Line 4335, Address: 0x2cf290, Func Offset: 0x100
	// Line 4337, Address: 0x2cf294, Func Offset: 0x104
	// Line 4335, Address: 0x2cf298, Func Offset: 0x108
	// Line 4337, Address: 0x2cf29c, Func Offset: 0x10c
	// Line 4338, Address: 0x2cf2ac, Func Offset: 0x11c
	// Line 4340, Address: 0x2cf2b8, Func Offset: 0x128
	// Line 4343, Address: 0x2cf2c8, Func Offset: 0x138
	// Line 4341, Address: 0x2cf2d0, Func Offset: 0x140
	// Line 4343, Address: 0x2cf2dc, Func Offset: 0x14c
	// Line 4347, Address: 0x2cf2e8, Func Offset: 0x158
	// Line 4345, Address: 0x2cf2ec, Func Offset: 0x15c
	// Line 4347, Address: 0x2cf2f8, Func Offset: 0x168
	// Line 4350, Address: 0x2cf304, Func Offset: 0x174
	// Line 4348, Address: 0x2cf308, Func Offset: 0x178
	// Line 4350, Address: 0x2cf30c, Func Offset: 0x17c
	// Line 4348, Address: 0x2cf310, Func Offset: 0x180
	// Line 4350, Address: 0x2cf314, Func Offset: 0x184
	// Line 4352, Address: 0x2cf324, Func Offset: 0x194
	// Line 4354, Address: 0x2cf32c, Func Offset: 0x19c
	// Line 4355, Address: 0x2cf338, Func Offset: 0x1a8
	// Line 4357, Address: 0x2cf340, Func Offset: 0x1b0
	// Line 4360, Address: 0x2cf348, Func Offset: 0x1b8
	// Line 4361, Address: 0x2cf350, Func Offset: 0x1c0
	// Func End, Address: 0x2cf35c, Func Offset: 0x1cc
}*/
