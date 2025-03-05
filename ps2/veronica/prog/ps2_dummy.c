/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct PS2_OT_LIST;
typedef union _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;
typedef struct _anon33;
typedef struct _anon34;
typedef struct _anon35;
typedef struct _anon36;
typedef struct _anon37;
typedef struct _anon38;
typedef struct _anon39;

typedef void(*type_29)();
typedef void(*type_30)();

typedef _anon17 type_0[8192];
typedef int type_1[3];
typedef unsigned long type_2[8];
typedef _anon16 type_3[64];
typedef unsigned long type_4[2];
typedef _anon31 type_5[64];
typedef unsigned long type_6[2];
typedef float type_7[16];
typedef float type_8[16][2];
typedef float type_9[16][12];
typedef void* type_10[4];
typedef float type_11[16][128];
typedef unsigned int type_12[4];
typedef unsigned char type_13[2];
typedef float type_14[4];
typedef unsigned int type_15[4096];
typedef void* type_16[3];
typedef char type_17[16];
typedef unsigned char type_18[2];
typedef char type_19[16];
typedef unsigned char type_20[10485760];
typedef char type_21[4];
typedef void* type_22[2];
typedef unsigned long type_23[2];
typedef unsigned long type_24[6];
typedef _anon17* type_25[2];
typedef _anon17* type_26[2][4096];
typedef unsigned int type_27[27];
typedef unsigned char type_28[1835008];
typedef _anon35 type_31[2];
typedef float type_32[4][3];
typedef int type_33[4];
typedef unsigned char type_34[2];
typedef unsigned char type_35[16384];
typedef float type_36[2];
typedef float type_37[4][128];

struct _anon0
{
	char FileId[4];
	unsigned char FormatVersion;
	unsigned char FormatId;
	unsigned short Pictures;
	unsigned int Gindex;
	unsigned char OrgColorType;
	unsigned char OrgTexType;
	unsigned short ClutChange;
	unsigned int PalNum;
	unsigned int PalData[27];
	unsigned int TotalSize;
	unsigned int ClutSize;
	unsigned int ImageSize;
	unsigned short HeaderSize;
	unsigned short ClutColors;
	unsigned char PictFormat;
	unsigned char MipMapTextures;
	unsigned char ClutType;
	unsigned char ImageType;
	unsigned short ImageWidth;
	unsigned short ImageHeight;
	_anon24 GsTex0;
	_anon32 GsTex1;
	unsigned int GsRegs;
	unsigned int GsTexClut;
	_anon12 admin;
	unsigned int TpFlag;
	unsigned int ClampFlag;
};

struct _anon1
{
	unsigned long SC_TAG[2];
	unsigned long GIF_TAG[2];
	unsigned long TEX0;
	unsigned long TEX0_TAG;
	unsigned long TEX0_NEXT;
	unsigned long TEX0_NEXT_TAG;
	unsigned long TEX1;
	unsigned long TEX1_TAG;
	unsigned long CLAMP;
	unsigned long CLAMP_TAG;
	unsigned long TEST;
	unsigned long TEST_TAG;
	unsigned long FOGCOL;
	unsigned long FOGCOL_TAG;
	unsigned long ALPHA;
	unsigned long ALPHA_TAG;
	unsigned long FBA;
	unsigned long FBA_TAG;
	unsigned long SCISSOR;
	unsigned long SCISSOR_TAG;
	unsigned char mode_bk[2];
	unsigned char set_last;
	unsigned char dc_alpha;
	unsigned int pad32;
	unsigned long pad64;
};

struct _anon2
{
	struct
	{
		unsigned int DX : 12;
		unsigned int DY : 11;
		unsigned int MAGH : 4;
		unsigned int MAGV : 2;
		unsigned int p0 : 3;
	};
	struct
	{
		unsigned int DW : 12;
		unsigned int DH : 11;
		unsigned int p1 : 9;
	};
};

struct _anon3
{
	_anon27 a;
	float sx;
	float sy;
	float oow;
	_anon6 point;
	unsigned int reserve;
	float u;
	float v;
	float inten[2];
	_anon6 vector;
	unsigned int flag;
};

struct _anon4
{
	unsigned int globalIndex;
	unsigned int bank;
	unsigned int tspparambuffer;
	unsigned int texparambuffer;
	unsigned int texaddr;
	_anon39 texinfo;
	unsigned short count;
	unsigned short dummy;
};

struct _anon5
{
	struct
	{
		unsigned long AC : 1;
		unsigned long pad01 : 63;
	};
};

struct _anon6
{
	float x;
	float y;
	float z;
};

struct _anon7
{
	struct
	{
		unsigned int R : 8;
		unsigned int G : 8;
		unsigned int B : 8;
		unsigned int p0 : 8;
	};
	unsigned int p1;
};

struct _anon8
{
	_anon15 frame2;
	unsigned long frame2addr;
	_anon30 zbuf2;
	long zbuf2addr;
	_anon22 xyoffset2;
	long xyoffset2addr;
	_anon13 scissor2;
	long scissor2addr;
	_anon5 prmodecont;
	long prmodecontaddr;
	_anon21 colclamp;
	long colclampaddr;
	_anon10 dthe;
	long dtheaddr;
	_anon18 test2;
	long test2addr;
};

struct _anon9
{
	struct
	{
		unsigned int R : 8;
		unsigned int G : 8;
		unsigned int B : 8;
		unsigned int A : 8;
	};
	float Q;
};

struct _anon10
{
	struct
	{
		unsigned long DTHE : 1;
		unsigned long pad01 : 63;
	};
};

struct _anon11
{
	unsigned short on;
	unsigned short old;
	unsigned short push;
	unsigned short release;
	short send;
	unsigned short ad_flag;
	unsigned char buff[2];
	unsigned short onon;
	unsigned short repeat;
	char time1[16];
	char time2[16];
	unsigned char rh;
	unsigned char rv;
	unsigned char lh;
	unsigned char lv;
	unsigned char au;
	unsigned char ad;
	unsigned char al;
	unsigned char ar;
	unsigned char abu;
	unsigned char abd;
	unsigned char abl;
	unsigned char abr;
	unsigned char al1;
	unsigned char al2;
	unsigned char ar1;
	unsigned char ar2;
};

struct _anon12
{
	unsigned int gindex;
	unsigned int size;
	unsigned int count;
	void* addr;
	void* before;
	void* after;
};

struct _anon13
{
	struct
	{
		unsigned long SCAX0 : 11;
		unsigned long pad11 : 5;
		unsigned long SCAX1 : 11;
		unsigned long pad27 : 5;
		unsigned long SCAY0 : 11;
		unsigned long pad43 : 5;
		unsigned long SCAY1 : 11;
		unsigned long pad59 : 5;
	};
};

struct _anon14
{
	_anon18 testa;
	long testaaddr;
	_anon34 prim;
	long primaddr;
	_anon9 rgbaq;
	long rgbaqaddr;
	_anon25 xyz2a;
	long xyz2aaddr;
	_anon25 xyz2b;
	long xyz2baddr;
	_anon18 testb;
	long testbaddr;
};

struct _anon15
{
	struct
	{
		unsigned long FBP : 9;
		unsigned long pad09 : 7;
		unsigned long FBW : 6;
		unsigned long pad22 : 2;
		unsigned long PSM : 6;
		unsigned long pad30 : 2;
		unsigned long FBMSK : 32;
	};
};

struct _anon16
{
	unsigned long GIF_TAG[2];
	unsigned long TEX0;
	unsigned long TEX0_TAG;
	unsigned long TEX0_NEXT;
	unsigned long TEX0_NEXT_TAG;
	unsigned long CLAMP;
	unsigned long CLAMP_TAG;
};

struct _anon17
{
	_anon4* tp;
	unsigned char mode_bk[2];
	unsigned char set_last;
	unsigned char dc_alpha;
	PS2_OT_LIST* op;
	void* p;
	unsigned long ALPHA;
	unsigned long TEX0;
	unsigned long TEX0_NEXT;
	unsigned int bank;
	unsigned int pad;
};

struct _anon18
{
	struct
	{
		unsigned long ATE : 1;
		unsigned long ATST : 3;
		unsigned long AREF : 8;
		unsigned long AFAIL : 2;
		unsigned long DATE : 1;
		unsigned long DATM : 1;
		unsigned long ZTE : 1;
		unsigned long ZTST : 2;
		unsigned long pad19 : 45;
	};
};

struct _anon19
{
	_anon11 pad1;
	_anon11 pad2;
};

struct _anon20
{
	_anon35 disp[2];
	_anon23 giftag0;
	_anon38 draw01;
	_anon8 draw02;
	_anon14 clear0;
	_anon23 giftag1;
	_anon38 draw11;
	_anon8 draw12;
	_anon14 clear1;
};

struct _anon21
{
	struct
	{
		unsigned long CLAMP : 1;
		unsigned long pad01 : 63;
	};
};

struct _anon22
{
	struct
	{
		unsigned long OFX : 16;
		unsigned long pad16 : 16;
		unsigned long OFY : 16;
		unsigned long pad48 : 16;
	};
};

struct _anon23
{
	struct
	{
		unsigned long NLOOP : 15;
		unsigned long EOP : 1;
		unsigned long pad16 : 16;
		unsigned long id : 14;
		unsigned long PRE : 1;
		unsigned long PRIM : 11;
		unsigned long FLG : 2;
		unsigned long NREG : 4;
	};
	struct
	{
		unsigned long REGS0 : 4;
		unsigned long REGS1 : 4;
		unsigned long REGS2 : 4;
		unsigned long REGS3 : 4;
		unsigned long REGS4 : 4;
		unsigned long REGS5 : 4;
		unsigned long REGS6 : 4;
		unsigned long REGS7 : 4;
		unsigned long REGS8 : 4;
		unsigned long REGS9 : 4;
		unsigned long REGS10 : 4;
		unsigned long REGS11 : 4;
		unsigned long REGS12 : 4;
		unsigned long REGS13 : 4;
		unsigned long REGS14 : 4;
		unsigned long REGS15 : 4;
	};
};

struct _anon24
{
	struct
	{
		unsigned long TBP0 : 14;
		unsigned long TBW : 6;
		unsigned long PSM : 6;
		unsigned long TW : 4;
		unsigned long TH : 4;
		unsigned long TCC : 1;
		unsigned long TFX : 2;
		unsigned long CBP : 14;
		unsigned long CPSM : 4;
		unsigned long CSM : 1;
		unsigned long CSA : 5;
		unsigned long CLD : 3;
	};
};

struct _anon25
{
	struct
	{
		unsigned long X : 16;
		unsigned long Y : 16;
		unsigned long Z : 32;
	};
};

struct _anon26
{
	struct
	{
		unsigned int EN1 : 1;
		unsigned int EN2 : 1;
		unsigned int CRTMD : 3;
		unsigned int MMOD : 1;
		unsigned int AMOD : 1;
		unsigned int SLBG : 1;
		unsigned int ALP : 8;
		unsigned int p0 : 16;
	};
	unsigned int p1;
};

struct PS2_OT_LIST
{
};

union _anon27
{
	unsigned int work;
	unsigned int clip;
};

struct _anon28
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};

struct _anon29
{
	struct
	{
		unsigned int FBP : 9;
		unsigned int FBW : 6;
		unsigned int PSM : 5;
		unsigned int p0 : 12;
	};
	struct
	{
		unsigned int DBX : 11;
		unsigned int DBY : 11;
		unsigned int p1 : 10;
	};
};

struct _anon30
{
	struct
	{
		unsigned long ZBP : 9;
		unsigned long pad09 : 15;
		unsigned long PSM : 4;
		unsigned long pad28 : 4;
		unsigned long ZMSK : 1;
		unsigned long pad33 : 31;
	};
};

struct _anon31
{
	void* tp;
	unsigned int bank;
	unsigned int tex_addr;
	unsigned int clt_addr;
};

struct _anon32
{
	struct
	{
		unsigned long LCM : 1;
		unsigned long pad01 : 1;
		unsigned long MXL : 3;
		unsigned long MMAG : 1;
		unsigned long MMIN : 3;
		unsigned long MTBA : 1;
		unsigned long pad10 : 9;
		unsigned long L : 2;
		unsigned long pad21 : 11;
		unsigned long K : 12;
		unsigned long pad44 : 20;
	};
};

struct _anon33
{
	unsigned int Type;
	unsigned int BitDepth;
	unsigned int PixelFormat;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int TextureSize;
	unsigned int fSurfaceFlags;
	unsigned int* pSurface;
	unsigned int* pVirtual;
	unsigned int* pPhysical;
};

struct _anon34
{
	struct
	{
		unsigned long PRIM : 3;
		unsigned long IIP : 1;
		unsigned long TME : 1;
		unsigned long FGE : 1;
		unsigned long ABE : 1;
		unsigned long AA1 : 1;
		unsigned long FST : 1;
		unsigned long CTXT : 1;
		unsigned long FIX : 1;
		unsigned long pad11 : 53;
	};
};

struct _anon35
{
	_anon26 pmode;
	_anon37 smode2;
	_anon29 dispfb;
	_anon2 display;
	_anon7 bgcolor;
};

struct _anon36
{
	unsigned char* mmp;
	float Vol;
	float VolSpeed;
	float Fade;
	float FadeSpeed;
	short FrameCnt;
	char ExecMovieSystemFlag;
	char MovieCancelFlag;
	char MovieFadeFlag;
	char MovieFadeMode;
	char MovieSystemLastError;
};

struct _anon37
{
	struct
	{
		unsigned int INT : 1;
		unsigned int FFMD : 1;
		unsigned int DPMS : 2;
		unsigned int p0 : 28;
	};
	unsigned int p1;
};

struct _anon38
{
	_anon15 frame1;
	unsigned long frame1addr;
	_anon30 zbuf1;
	long zbuf1addr;
	_anon22 xyoffset1;
	long xyoffset1addr;
	_anon13 scissor1;
	long scissor1addr;
	_anon5 prmodecont;
	long prmodecontaddr;
	_anon21 colclamp;
	long colclampaddr;
	_anon10 dthe;
	long dtheaddr;
	_anon18 test1;
	long test1addr;
};

struct _anon39
{
	void* texaddr;
	_anon33 texsurface;
};

unsigned char* Ps2_MOVIE;
unsigned int Ps2_tex_load_tp_cancel;
unsigned int Ps2_highlight;
float Ps2_rand_seed[4];
unsigned int PS2_Render_tex_sub_flag;
unsigned int Ps2_ice_flag;
unsigned int Ps2_albinoid_flag;*/
sceGsDBuffDc Db;
void* Ps2_tex_buff;
unsigned char Ps2_tex_mem[10485760];
/*_anon36 MovieInfo;
float Ps2_zbuff_a;
float Ps2_zbuff_b;
_anon1 Ps2_gs_save;
unsigned int Ps2_use_pt_flag;
_anon4* Ps2_now_tex;
unsigned int Ps2_ot_list_no;
void* Ps2_PP;
_anon17 Ps2_ot_list[8192];
unsigned int Ps2_now_bank;
_anon17* Ps2_OT[2][4096];
float Ps2AddPrimPrio;
unsigned char Ps2_PBUFF[1835008];
unsigned int Ps2_current_texbreak;
_anon16 Ps2_tp_tag[64];
_anon31 ps2_tp_cache[64];
unsigned int Ps2_tex_cache_num;
unsigned int Ps2_tex_cache_beflag[4];
void* Ps2_tex_cache_buff[4];
_anon4* Ps2_tex_info;
unsigned long ulNaFogB;
unsigned long ulNaFogG;
unsigned long ulNaFogR;
unsigned int Ps2_divide_flag;
_anon19 Ps2_pad;
float Ps2_shadow_fog;
float Ps2_shadow_vec[4];
int Ps2_shadow_z;
int ViewType;
unsigned int palbuf[4096];
float mbuf[16][128];
float lcmat[16][12];
float cmmat[16][2];
float crmat[16];
unsigned char* _BSG_END;
int _nj_tex_count;
_anon3* _nj_vertex_buf_;
unsigned int _nj_control_3d_flag_;
_anon28 _nj_screen_;
unsigned char Ps2_DRAW_TMP[16384];
unsigned int Ps2_sys_cnt;
unsigned int Ps2_njControl3D_flag;
unsigned int Ps2_dbuff;
unsigned int Ps2_vcount;
void(*VsyncFunc)();
void(*EorFunc)();

int _builtin_set_imask();
void Ps2Init();*/
void Ps2LoadModule(char* p);
void Snd_init();
void Cd_init();
void Card_init();
/*void PS2_jikken();
void PS2_swap();
void Ps2AddPrim(unsigned long prim, void* dp, unsigned int num, unsigned int clip_3d_on);
void Ps2AddPrim2D(unsigned long prim, void* dp, unsigned int num);
void Ps2AddPrim3D(unsigned long prim, void* dp, unsigned int num);
void Ps2AddPrim3DEx(unsigned long prim, void* dp, unsigned int num);
void Ps2AddPrim3DEx1P(unsigned long prim, void* dp, unsigned int num);
void Ps2AddPrim3DMod(unsigned long prim, void* dp, unsigned int num);
void Ps2ClearOT();
void Ps2AddOT(void* p, unsigned int num, float z, unsigned long prim);
void Ps2DrawOTag();
int Ps2DrawOTagSub(int start_no);
unsigned int Ps2BitCount(unsigned int value);*/
void Ps2InitTexCache();
/*int Ps2GlobalIndexTexLoad(unsigned int index);
int Ps2TexLoad(_anon4* addr);
void Ps2SetFogColor();
void Ps2SetFogColorSys(unsigned int r, unsigned int g, unsigned int b);
void Ps2AlphaIs000(unsigned int* cp, unsigned int num);
unsigned int Ps2AlphaIsHalf(unsigned int* cp, unsigned int num);
unsigned int Ps2Alpha4to8(unsigned int* cp, unsigned int num);
int Ps2CheckTextureAlpha(void* pp);*/
void Ps2InitPS2_GS_SAVE();
void Ps2ScreenClear();
void Ps2DispScreenClear();
/*void Ps2ZbuffOff();
void Ps2ZbuffOff2();
void Ps2ZbuffOn();
void Ps2ShadowStart();
void Ps2ShadowDraw();
void Ps2ShadowMain0();
void Ps2ShadowMain1();
void Ps2ShadowEnd();*/
void Ps2Vu0ProgSend(unsigned int prog_no);
void Ps2Vu1ProgSend(unsigned int prog_no);
/*void Ps2AddPrim3DExI(unsigned long prim, void* dp, unsigned int num);
void PS2_Render_Tex_Sub();*/

int ps2_vu0sub0; 
int ps2_vu1sub0;
int ps2_vu1sub1;

// 100% matching!
void _builtin_set_imask(int mask) 
{

}

#define	DISP_WIDTH          640
#define	DISP_HEIGHT         480

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
    
    //while (sceSifRebootIop("cdrom0:\\PS2_DATA\\MODULES\\IOPRP213.IMG;1") == 0); // TODO: gotta find an effective way to repack the compiled binary with the ISO first
    
    //while (sceSifSyncIop() == 0);  
    
    sceSifInitRpc(0); 
    
    while (sceCdInit(SCECdINIT) == 0); 
    
    sceCdMmode(SCECdDVD); 
    
    sceFsReset(); 
    
    if (sceSifInitIopHeap() != 0)
    { 
        printf("Error:sceSifInitIopHeap Error\n");
        
        //exit(-1);
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
    //Pad_init(); // TODO: for some reason, this function causes the next lines of code to not be triggered
    
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
        
        //exit(0); // TODO: need to find a way to get the IRX modules to load at all
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

/*// 
// Start address: 0x2cb5f0
void PS2_swap()
{
	unsigned long* p;
	// Line 660, Address: 0x2cb5f0, Func Offset: 0
	// Line 684, Address: 0x2cb5fc, Func Offset: 0xc
	// Line 686, Address: 0x2cb604, Func Offset: 0x14
	// Line 689, Address: 0x2cb614, Func Offset: 0x24
	// Line 687, Address: 0x2cb618, Func Offset: 0x28
	// Line 689, Address: 0x2cb61c, Func Offset: 0x2c
	// Line 687, Address: 0x2cb620, Func Offset: 0x30
	// Line 689, Address: 0x2cb624, Func Offset: 0x34
	// Line 690, Address: 0x2cb634, Func Offset: 0x44
	// Line 692, Address: 0x2cb640, Func Offset: 0x50
	// Line 693, Address: 0x2cb650, Func Offset: 0x60
	// Line 695, Address: 0x2cb65c, Func Offset: 0x6c
	// Line 696, Address: 0x2cb664, Func Offset: 0x74
	// Line 697, Address: 0x2cb670, Func Offset: 0x80
	// Line 698, Address: 0x2cb678, Func Offset: 0x88
	// Line 700, Address: 0x2cb684, Func Offset: 0x94
	// Line 701, Address: 0x2cb68c, Func Offset: 0x9c
	// Line 711, Address: 0x2cb698, Func Offset: 0xa8
	// Line 712, Address: 0x2cb6a8, Func Offset: 0xb8
	// Line 713, Address: 0x2cb6c0, Func Offset: 0xd0
	// Line 714, Address: 0x2cb6c8, Func Offset: 0xd8
	// Line 717, Address: 0x2cb6e4, Func Offset: 0xf4
	// Line 723, Address: 0x2cb6ec, Func Offset: 0xfc
	// Line 719, Address: 0x2cb6f0, Func Offset: 0x100
	// Line 723, Address: 0x2cb6f8, Func Offset: 0x108
	// Line 720, Address: 0x2cb6fc, Func Offset: 0x10c
	// Line 723, Address: 0x2cb700, Func Offset: 0x110
	// Line 720, Address: 0x2cb70c, Func Offset: 0x11c
	// Line 723, Address: 0x2cb710, Func Offset: 0x120
	// Line 724, Address: 0x2cb714, Func Offset: 0x124
	// Line 726, Address: 0x2cb71c, Func Offset: 0x12c
	// Line 736, Address: 0x2cb724, Func Offset: 0x134
	// Line 727, Address: 0x2cb72c, Func Offset: 0x13c
	// Line 736, Address: 0x2cb730, Func Offset: 0x140
	// Line 738, Address: 0x2cb738, Func Offset: 0x148
	// Line 740, Address: 0x2cb740, Func Offset: 0x150
	// Line 742, Address: 0x2cb74c, Func Offset: 0x15c
	// Line 741, Address: 0x2cb754, Func Offset: 0x164
	// Line 742, Address: 0x2cb758, Func Offset: 0x168
	// Line 741, Address: 0x2cb760, Func Offset: 0x170
	// Line 742, Address: 0x2cb764, Func Offset: 0x174
	// Line 743, Address: 0x2cb76c, Func Offset: 0x17c
	// Line 745, Address: 0x2cb770, Func Offset: 0x180
	// Line 743, Address: 0x2cb774, Func Offset: 0x184
	// Line 745, Address: 0x2cb778, Func Offset: 0x188
	// Line 747, Address: 0x2cb780, Func Offset: 0x190
	// Line 746, Address: 0x2cb78c, Func Offset: 0x19c
	// Line 747, Address: 0x2cb790, Func Offset: 0x1a0
	// Line 748, Address: 0x2cb798, Func Offset: 0x1a8
	// Line 750, Address: 0x2cb79c, Func Offset: 0x1ac
	// Line 751, Address: 0x2cb7a4, Func Offset: 0x1b4
	// Line 753, Address: 0x2cb7a8, Func Offset: 0x1b8
	// Line 754, Address: 0x2cb7b0, Func Offset: 0x1c0
	// Line 755, Address: 0x2cb7b8, Func Offset: 0x1c8
	// Line 756, Address: 0x2cb7c0, Func Offset: 0x1d0
	// Func End, Address: 0x2cb7d0, Func Offset: 0x1e0
}

// 
// Start address: 0x2cb7d0
void Ps2AddPrim(unsigned long prim, void* dp, unsigned int num, unsigned int clip_3d_on)
{
	float y;
	float x;
	float sz;
	float invz;
	float z;
	unsigned int nf_flag;
	unsigned int st_clip_flag;
	unsigned int out_clip_flag;
	unsigned int sc_flag;
	unsigned int clip_flag;
	unsigned int i;
	unsigned long* p;
	// Line 890, Address: 0x2cb7d0, Func Offset: 0
	// Line 904, Address: 0x2cb800, Func Offset: 0x30
	// Line 890, Address: 0x2cb80c, Func Offset: 0x3c
	// Line 895, Address: 0x2cb81c, Func Offset: 0x4c
	// Line 904, Address: 0x2cb820, Func Offset: 0x50
	// Line 895, Address: 0x2cb824, Func Offset: 0x54
	// Line 904, Address: 0x2cb82c, Func Offset: 0x5c
	// Line 906, Address: 0x2cb834, Func Offset: 0x64
	// Line 915, Address: 0x2cb844, Func Offset: 0x74
	// Line 919, Address: 0x2cb85c, Func Offset: 0x8c
	// Line 921, Address: 0x2cb86c, Func Offset: 0x9c
	// Line 929, Address: 0x2cb894, Func Offset: 0xc4
	// Line 931, Address: 0x2cb8ac, Func Offset: 0xdc
	// Line 932, Address: 0x2cb8bc, Func Offset: 0xec
	// Line 933, Address: 0x2cb8c4, Func Offset: 0xf4
	// Line 934, Address: 0x2cb8cc, Func Offset: 0xfc
	// Line 956, Address: 0x2cb8d4, Func Offset: 0x104
	// Line 957, Address: 0x2cb8d8, Func Offset: 0x108
	// Line 960, Address: 0x2cb8e0, Func Offset: 0x110
	// Line 963, Address: 0x2cb904, Func Offset: 0x134
	// Line 961, Address: 0x2cb90c, Func Offset: 0x13c
	// Line 963, Address: 0x2cb910, Func Offset: 0x140
	// Line 961, Address: 0x2cb914, Func Offset: 0x144
	// Line 963, Address: 0x2cb918, Func Offset: 0x148
	// Line 964, Address: 0x2cb924, Func Offset: 0x154
	// Line 967, Address: 0x2cb930, Func Offset: 0x160
	// Line 969, Address: 0x2cb948, Func Offset: 0x178
	// Line 970, Address: 0x2cb960, Func Offset: 0x190
	// Line 971, Address: 0x2cb968, Func Offset: 0x198
	// Line 973, Address: 0x2cb984, Func Offset: 0x1b4
	// Line 984, Address: 0x2cb98c, Func Offset: 0x1bc
	// Line 985, Address: 0x2cb9b8, Func Offset: 0x1e8
	// Line 986, Address: 0x2cb9d0, Func Offset: 0x200
	// Line 987, Address: 0x2cb9d8, Func Offset: 0x208
	// Line 988, Address: 0x2cb9e0, Func Offset: 0x210
	// Line 991, Address: 0x2cb9ec, Func Offset: 0x21c
	// Line 997, Address: 0x2cb9f8, Func Offset: 0x228
	// Line 1010, Address: 0x2cb9fc, Func Offset: 0x22c
	// Line 992, Address: 0x2cba00, Func Offset: 0x230
	// Line 993, Address: 0x2cba04, Func Offset: 0x234
	// Line 997, Address: 0x2cba08, Func Offset: 0x238
	// Line 998, Address: 0x2cba0c, Func Offset: 0x23c
	// Line 999, Address: 0x2cba10, Func Offset: 0x240
	// Line 998, Address: 0x2cba14, Func Offset: 0x244
	// Line 1002, Address: 0x2cba18, Func Offset: 0x248
	// Line 1005, Address: 0x2cba20, Func Offset: 0x250
	// Line 1007, Address: 0x2cba28, Func Offset: 0x258
	// Line 1008, Address: 0x2cba2c, Func Offset: 0x25c
	// Line 1010, Address: 0x2cba30, Func Offset: 0x260
	// Line 1011, Address: 0x2cba88, Func Offset: 0x2b8
	// Line 1015, Address: 0x2cba94, Func Offset: 0x2c4
	// Line 1016, Address: 0x2cbad0, Func Offset: 0x300
	// Line 1017, Address: 0x2cbad4, Func Offset: 0x304
	// Line 1019, Address: 0x2cbad8, Func Offset: 0x308
	// Line 1023, Address: 0x2cbae0, Func Offset: 0x310
	// Line 1025, Address: 0x2cbae8, Func Offset: 0x318
	// Line 1023, Address: 0x2cbaec, Func Offset: 0x31c
	// Line 1025, Address: 0x2cbb00, Func Offset: 0x330
	// Line 1027, Address: 0x2cbb18, Func Offset: 0x348
	// Line 1029, Address: 0x2cbb40, Func Offset: 0x370
	// Line 1031, Address: 0x2cbb48, Func Offset: 0x378
	// Line 1032, Address: 0x2cbb50, Func Offset: 0x380
	// Line 1031, Address: 0x2cbb54, Func Offset: 0x384
	// Line 1032, Address: 0x2cbb68, Func Offset: 0x398
	// Line 1034, Address: 0x2cbb80, Func Offset: 0x3b0
	// Line 1035, Address: 0x2cbba8, Func Offset: 0x3d8
	// Line 1041, Address: 0x2cbbac, Func Offset: 0x3dc
	// Line 1042, Address: 0x2cbbb0, Func Offset: 0x3e0
	// Line 1044, Address: 0x2cbbbc, Func Offset: 0x3ec
	// Line 1045, Address: 0x2cbbd0, Func Offset: 0x400
	// Line 1046, Address: 0x2cbbe8, Func Offset: 0x418
	// Line 1047, Address: 0x2cbbec, Func Offset: 0x41c
	// Line 1086, Address: 0x2cbc08, Func Offset: 0x438
	// Line 1053, Address: 0x2cbc0c, Func Offset: 0x43c
	// Line 1086, Address: 0x2cbc10, Func Offset: 0x440
	// Line 1102, Address: 0x2cbc20, Func Offset: 0x450
	// Line 1110, Address: 0x2cbc2c, Func Offset: 0x45c
	// Line 1112, Address: 0x2cbc40, Func Offset: 0x470
	// Line 1120, Address: 0x2cbc48, Func Offset: 0x478
	// Line 1121, Address: 0x2cbc50, Func Offset: 0x480
	// Line 1128, Address: 0x2cbc58, Func Offset: 0x488
	// Func End, Address: 0x2cbc8c, Func Offset: 0x4bc
}

// 
// Start address: 0x2cbc90
void Ps2AddPrim2D(unsigned long prim, void* dp, unsigned int num)
{
	// Line 1198, Address: 0x2cbc90, Func Offset: 0
	// Func End, Address: 0x2cbc98, Func Offset: 0x8
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
	_anon0* timp;
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
	_anon0* timp;
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
	_anon0* timp;
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
}

// 
// Start address: 0x2cc850
void Ps2ClearOT()
{
	int i;
	// Line 2165, Address: 0x2cc850, Func Offset: 0
	// Line 2164, Address: 0x2cc854, Func Offset: 0x4
	// Line 2165, Address: 0x2cc858, Func Offset: 0x8
	// Line 2164, Address: 0x2cc85c, Func Offset: 0xc
	// Line 2166, Address: 0x2cc860, Func Offset: 0x10
	// Line 2164, Address: 0x2cc868, Func Offset: 0x18
	// Line 2168, Address: 0x2cc880, Func Offset: 0x30
	// Line 2171, Address: 0x2cc884, Func Offset: 0x34
	// Line 2170, Address: 0x2cc888, Func Offset: 0x38
	// Line 2171, Address: 0x2cc88c, Func Offset: 0x3c
	// Line 2170, Address: 0x2cc890, Func Offset: 0x40
	// Line 2171, Address: 0x2cc894, Func Offset: 0x44
	// Line 2172, Address: 0x2cc8a0, Func Offset: 0x50
	// Func End, Address: 0x2cc8a8, Func Offset: 0x58
}

// 
// Start address: 0x2cc8b0
void Ps2AddOT(void* p, unsigned int num, float z, unsigned long prim)
{
	unsigned int id;
	unsigned int otz;
	unsigned int size;
	unsigned int i;
	// Line 2193, Address: 0x2cc8b0, Func Offset: 0
	// Line 2194, Address: 0x2cc8c0, Func Offset: 0x10
	// Line 2195, Address: 0x2cc8d4, Func Offset: 0x24
	// Line 2197, Address: 0x2cc8fc, Func Offset: 0x4c
	// Line 2198, Address: 0x2cc900, Func Offset: 0x50
	// Line 2202, Address: 0x2cc904, Func Offset: 0x54
	// Line 2204, Address: 0x2cc90c, Func Offset: 0x5c
	// Line 2205, Address: 0x2cc910, Func Offset: 0x60
	// Line 2210, Address: 0x2cc914, Func Offset: 0x64
	// Line 2213, Address: 0x2cc91c, Func Offset: 0x6c
	// Line 2214, Address: 0x2cc920, Func Offset: 0x70
	// Line 2215, Address: 0x2cc928, Func Offset: 0x78
	// Line 2222, Address: 0x2cc92c, Func Offset: 0x7c
	// Line 2225, Address: 0x2cc93c, Func Offset: 0x8c
	// Line 2226, Address: 0x2cc958, Func Offset: 0xa8
	// Line 2227, Address: 0x2cc988, Func Offset: 0xd8
	// Line 2226, Address: 0x2cc98c, Func Offset: 0xdc
	// Line 2227, Address: 0x2cc990, Func Offset: 0xe0
	// Line 2228, Address: 0x2cc9bc, Func Offset: 0x10c
	// Line 2229, Address: 0x2cc9cc, Func Offset: 0x11c
	// Line 2230, Address: 0x2cc9d4, Func Offset: 0x124
	// Line 2231, Address: 0x2cca14, Func Offset: 0x164
	// Line 2233, Address: 0x2cca28, Func Offset: 0x178
	// Line 2234, Address: 0x2cca3c, Func Offset: 0x18c
	// Line 2235, Address: 0x2cca4c, Func Offset: 0x19c
	// Line 2234, Address: 0x2cca54, Func Offset: 0x1a4
	// Line 2235, Address: 0x2cca70, Func Offset: 0x1c0
	// Line 2236, Address: 0x2cca90, Func Offset: 0x1e0
	// Line 2237, Address: 0x2cca98, Func Offset: 0x1e8
	// Line 2240, Address: 0x2ccac0, Func Offset: 0x210
	// Line 2241, Address: 0x2ccad0, Func Offset: 0x220
	// Line 2240, Address: 0x2ccad8, Func Offset: 0x228
	// Line 2241, Address: 0x2ccae0, Func Offset: 0x230
	// Line 2240, Address: 0x2ccae4, Func Offset: 0x234
	// Line 2241, Address: 0x2ccaf8, Func Offset: 0x248
	// Line 2242, Address: 0x2ccb24, Func Offset: 0x274
	// Line 2241, Address: 0x2ccb2c, Func Offset: 0x27c
	// Line 2242, Address: 0x2ccb40, Func Offset: 0x290
	// Line 2243, Address: 0x2ccb48, Func Offset: 0x298
	// Line 2253, Address: 0x2ccb50, Func Offset: 0x2a0
	// Line 2242, Address: 0x2ccb58, Func Offset: 0x2a8
	// Line 2253, Address: 0x2ccb60, Func Offset: 0x2b0
	// Line 2242, Address: 0x2ccb64, Func Offset: 0x2b4
	// Line 2255, Address: 0x2ccb68, Func Offset: 0x2b8
	// Line 2242, Address: 0x2ccb6c, Func Offset: 0x2bc
	// Line 2243, Address: 0x2ccb80, Func Offset: 0x2d0
	// Line 2257, Address: 0x2ccb88, Func Offset: 0x2d8
	// Line 2243, Address: 0x2ccb98, Func Offset: 0x2e8
	// Line 2254, Address: 0x2ccbb4, Func Offset: 0x304
	// Line 2258, Address: 0x2ccbbc, Func Offset: 0x30c
	// Line 2260, Address: 0x2ccbc0, Func Offset: 0x310
	// Line 2262, Address: 0x2ccbc4, Func Offset: 0x314
	// Line 2254, Address: 0x2ccbc8, Func Offset: 0x318
	// Line 2255, Address: 0x2ccbd4, Func Offset: 0x324
	// Line 2261, Address: 0x2ccbf8, Func Offset: 0x348
	// Line 2255, Address: 0x2ccbfc, Func Offset: 0x34c
	// Line 2256, Address: 0x2ccc08, Func Offset: 0x358
	// Line 2257, Address: 0x2ccc28, Func Offset: 0x378
	// Line 2258, Address: 0x2ccc48, Func Offset: 0x398
	// Line 2259, Address: 0x2ccc5c, Func Offset: 0x3ac
	// Line 2258, Address: 0x2ccc64, Func Offset: 0x3b4
	// Line 2259, Address: 0x2ccc70, Func Offset: 0x3c0
	// Line 2260, Address: 0x2ccc90, Func Offset: 0x3e0
	// Line 2262, Address: 0x2cccac, Func Offset: 0x3fc
	// Line 2263, Address: 0x2cccb4, Func Offset: 0x404
	// Line 2264, Address: 0x2cccc0, Func Offset: 0x410
	// Line 2263, Address: 0x2cccc4, Func Offset: 0x414
	// Line 2264, Address: 0x2ccce0, Func Offset: 0x430
	// Line 2265, Address: 0x2cccec, Func Offset: 0x43c
	// Line 2267, Address: 0x2cccfc, Func Offset: 0x44c
	// Func End, Address: 0x2ccd04, Func Offset: 0x454
}

// 
// Start address: 0x2ccd10
void Ps2DrawOTag()
{
	int i;
	// Line 2352, Address: 0x2ccd10, Func Offset: 0
	// Line 2355, Address: 0x2ccd18, Func Offset: 0x8
	// Line 2356, Address: 0x2ccd20, Func Offset: 0x10
	// Line 2357, Address: 0x2ccd24, Func Offset: 0x14
	// Line 2358, Address: 0x2ccd30, Func Offset: 0x20
	// Line 2359, Address: 0x2ccd44, Func Offset: 0x34
	// Line 2360, Address: 0x2ccd4c, Func Offset: 0x3c
	// Line 2361, Address: 0x2ccd58, Func Offset: 0x48
	// Func End, Address: 0x2ccd64, Func Offset: 0x54
}

// 
// Start address: 0x2ccd70
int Ps2DrawOTagSub(int start_no)
{
	void* start_addr;
	unsigned int exit_no;
	unsigned int clt_addr;
	unsigned int tex_addr;
	unsigned int np_no;
	unsigned int t_no;
	unsigned int p_flag;
	unsigned int t_flag;
	unsigned int tex_cache_num;
	_anon0* timp;
	int save_alpha[3];
	_anon17* old_p;
	_anon17* p;
	int j;
	int i;
	// Line 2365, Address: 0x2ccd70, Func Offset: 0
	// Line 2371, Address: 0x2ccd74, Func Offset: 0x4
	// Line 2365, Address: 0x2ccd78, Func Offset: 0x8
	// Line 2371, Address: 0x2ccd80, Func Offset: 0x10
	// Line 2365, Address: 0x2ccd88, Func Offset: 0x18
	// Line 2371, Address: 0x2ccd90, Func Offset: 0x20
	// Line 2365, Address: 0x2ccd94, Func Offset: 0x24
	// Line 2372, Address: 0x2ccd98, Func Offset: 0x28
	// Line 2365, Address: 0x2ccd9c, Func Offset: 0x2c
	// Line 2372, Address: 0x2ccda4, Func Offset: 0x34
	// Line 2365, Address: 0x2ccda8, Func Offset: 0x38
	// Line 2367, Address: 0x2ccdbc, Func Offset: 0x4c
	// Line 2370, Address: 0x2ccdc0, Func Offset: 0x50
	// Line 2377, Address: 0x2ccdc8, Func Offset: 0x58
	// Line 2378, Address: 0x2ccdcc, Func Offset: 0x5c
	// Line 2380, Address: 0x2ccdd0, Func Offset: 0x60
	// Line 2379, Address: 0x2ccdd4, Func Offset: 0x64
	// Line 2380, Address: 0x2ccdd8, Func Offset: 0x68
	// Line 2379, Address: 0x2ccddc, Func Offset: 0x6c
	// Line 2380, Address: 0x2ccde0, Func Offset: 0x70
	// Line 2381, Address: 0x2ccdec, Func Offset: 0x7c
	// Line 2382, Address: 0x2cce24, Func Offset: 0xb4
	// Line 2385, Address: 0x2cce40, Func Offset: 0xd0
	// Line 2386, Address: 0x2cce4c, Func Offset: 0xdc
	// Line 2387, Address: 0x2cce68, Func Offset: 0xf8
	// Line 2388, Address: 0x2cce70, Func Offset: 0x100
	// Line 2391, Address: 0x2cce78, Func Offset: 0x108
	// Line 2390, Address: 0x2cce7c, Func Offset: 0x10c
	// Line 2391, Address: 0x2cce80, Func Offset: 0x110
	// Line 2392, Address: 0x2cce90, Func Offset: 0x120
	// Line 2394, Address: 0x2cce9c, Func Offset: 0x12c
	// Line 2395, Address: 0x2ccea8, Func Offset: 0x138
	// Line 2396, Address: 0x2ccebc, Func Offset: 0x14c
	// Line 2398, Address: 0x2ccec0, Func Offset: 0x150
	// Line 2401, Address: 0x2ccec8, Func Offset: 0x158
	// Line 2403, Address: 0x2cced0, Func Offset: 0x160
	// Line 2404, Address: 0x2ccee8, Func Offset: 0x178
	// Line 2407, Address: 0x2ccef4, Func Offset: 0x184
	// Line 2405, Address: 0x2ccefc, Func Offset: 0x18c
	// Line 2407, Address: 0x2ccf00, Func Offset: 0x190
	// Line 2408, Address: 0x2ccf08, Func Offset: 0x198
	// Line 2409, Address: 0x2ccf0c, Func Offset: 0x19c
	// Line 2412, Address: 0x2ccf10, Func Offset: 0x1a0
	// Line 2413, Address: 0x2ccf20, Func Offset: 0x1b0
	// Line 2414, Address: 0x2ccf28, Func Offset: 0x1b8
	// Line 2415, Address: 0x2ccf30, Func Offset: 0x1c0
	// Line 2416, Address: 0x2ccf48, Func Offset: 0x1d8
	// Line 2417, Address: 0x2ccf4c, Func Offset: 0x1dc
	// Line 2419, Address: 0x2ccf54, Func Offset: 0x1e4
	// Line 2420, Address: 0x2ccf84, Func Offset: 0x214
	// Line 2422, Address: 0x2ccf88, Func Offset: 0x218
	// Line 2423, Address: 0x2ccf90, Func Offset: 0x220
	// Line 2425, Address: 0x2ccfac, Func Offset: 0x23c
	// Line 2426, Address: 0x2ccfb4, Func Offset: 0x244
	// Line 2427, Address: 0x2ccfc4, Func Offset: 0x254
	// Line 2430, Address: 0x2ccfcc, Func Offset: 0x25c
	// Line 2435, Address: 0x2ccfdc, Func Offset: 0x26c
	// Line 2437, Address: 0x2ccfe4, Func Offset: 0x274
	// Line 2438, Address: 0x2ccfec, Func Offset: 0x27c
	// Line 2440, Address: 0x2ccff4, Func Offset: 0x284
	// Line 2439, Address: 0x2ccff8, Func Offset: 0x288
	// Line 2440, Address: 0x2ccffc, Func Offset: 0x28c
	// Line 2439, Address: 0x2cd000, Func Offset: 0x290
	// Line 2442, Address: 0x2cd010, Func Offset: 0x2a0
	// Line 2443, Address: 0x2cd014, Func Offset: 0x2a4
	// Line 2445, Address: 0x2cd018, Func Offset: 0x2a8
	// Line 2443, Address: 0x2cd028, Func Offset: 0x2b8
	// Line 2445, Address: 0x2cd02c, Func Offset: 0x2bc
	// Line 2446, Address: 0x2cd030, Func Offset: 0x2c0
	// Line 2448, Address: 0x2cd038, Func Offset: 0x2c8
	// Line 2449, Address: 0x2cd054, Func Offset: 0x2e4
	// Line 2451, Address: 0x2cd068, Func Offset: 0x2f8
	// Line 2449, Address: 0x2cd06c, Func Offset: 0x2fc
	// Line 2451, Address: 0x2cd094, Func Offset: 0x324
	// Line 2452, Address: 0x2cd098, Func Offset: 0x328
	// Line 2455, Address: 0x2cd0d4, Func Offset: 0x364
	// Line 2456, Address: 0x2cd0dc, Func Offset: 0x36c
	// Line 2458, Address: 0x2cd0fc, Func Offset: 0x38c
	// Line 2456, Address: 0x2cd100, Func Offset: 0x390
	// Line 2458, Address: 0x2cd114, Func Offset: 0x3a4
	// Line 2459, Address: 0x2cd118, Func Offset: 0x3a8
	// Line 2461, Address: 0x2cd13c, Func Offset: 0x3cc
	// Line 2464, Address: 0x2cd140, Func Offset: 0x3d0
	// Line 2465, Address: 0x2cd150, Func Offset: 0x3e0
	// Line 2467, Address: 0x2cd158, Func Offset: 0x3e8
	// Line 2468, Address: 0x2cd170, Func Offset: 0x400
	// Line 2467, Address: 0x2cd174, Func Offset: 0x404
	// Line 2468, Address: 0x2cd178, Func Offset: 0x408
	// Line 2467, Address: 0x2cd18c, Func Offset: 0x41c
	// Line 2468, Address: 0x2cd190, Func Offset: 0x420
	// Line 2470, Address: 0x2cd194, Func Offset: 0x424
	// Line 2468, Address: 0x2cd198, Func Offset: 0x428
	// Line 2472, Address: 0x2cd1a0, Func Offset: 0x430
	// Line 2473, Address: 0x2cd1a8, Func Offset: 0x438
	// Line 2474, Address: 0x2cd1d8, Func Offset: 0x468
	// Line 2477, Address: 0x2cd1e0, Func Offset: 0x470
	// Line 2478, Address: 0x2cd1e4, Func Offset: 0x474
	// Line 2479, Address: 0x2cd1e8, Func Offset: 0x478
	// Line 2480, Address: 0x2cd1fc, Func Offset: 0x48c
	// Line 2482, Address: 0x2cd218, Func Offset: 0x4a8
	// Line 2484, Address: 0x2cd224, Func Offset: 0x4b4
	// Line 2488, Address: 0x2cd228, Func Offset: 0x4b8
	// Line 2484, Address: 0x2cd22c, Func Offset: 0x4bc
	// Line 2488, Address: 0x2cd234, Func Offset: 0x4c4
	// Line 2484, Address: 0x2cd238, Func Offset: 0x4c8
	// Line 2488, Address: 0x2cd23c, Func Offset: 0x4cc
	// Line 2484, Address: 0x2cd254, Func Offset: 0x4e4
	// Line 2485, Address: 0x2cd264, Func Offset: 0x4f4
	// Line 2488, Address: 0x2cd274, Func Offset: 0x504
	// Line 2491, Address: 0x2cd27c, Func Offset: 0x50c
	// Line 2493, Address: 0x2cd284, Func Offset: 0x514
	// Line 2495, Address: 0x2cd288, Func Offset: 0x518
	// Line 2492, Address: 0x2cd28c, Func Offset: 0x51c
	// Line 2491, Address: 0x2cd294, Func Offset: 0x524
	// Line 2493, Address: 0x2cd298, Func Offset: 0x528
	// Line 2492, Address: 0x2cd2a0, Func Offset: 0x530
	// Line 2495, Address: 0x2cd2a4, Func Offset: 0x534
	// Line 2497, Address: 0x2cd2ac, Func Offset: 0x53c
	// Line 2498, Address: 0x2cd2b4, Func Offset: 0x544
	// Line 2499, Address: 0x2cd2c4, Func Offset: 0x554
	// Line 2500, Address: 0x2cd2cc, Func Offset: 0x55c
	// Line 2501, Address: 0x2cd2e4, Func Offset: 0x574
	// Line 2503, Address: 0x2cd2f8, Func Offset: 0x588
	// Line 2505, Address: 0x2cd300, Func Offset: 0x590
	// Line 2506, Address: 0x2cd304, Func Offset: 0x594
	// Func End, Address: 0x2cd334, Func Offset: 0x5c4
}

// 
// Start address: 0x2cd340
unsigned int Ps2BitCount(unsigned int value)
{
	// Line 2513, Address: 0x2cd340, Func Offset: 0
	// Line 2514, Address: 0x2cd344, Func Offset: 0x4
	// Line 2515, Address: 0x2cd348, Func Offset: 0x8
	// Line 2516, Address: 0x2cd34c, Func Offset: 0xc
	// Line 2520, Address: 0x2cd350, Func Offset: 0x10
	// Func End, Address: 0x2cd358, Func Offset: 0x18
}*/

// 
// Start address: 0x2cd360
void Ps2InitTexCache()
{
	unsigned int i;
	// Line 2526, Address: 0x2cd370, Func Offset: 0x10
	// Line 2527, Address: 0x2cd374, Func Offset: 0x14
	// Line 2529, Address: 0x2cd378, Func Offset: 0x18
	// Line 2528, Address: 0x2cd37c, Func Offset: 0x1c
	// Line 2529, Address: 0x2cd384, Func Offset: 0x24
	// Line 2530, Address: 0x2cd390, Func Offset: 0x30
	// Line 2531, Address: 0x2cd398, Func Offset: 0x38
	// Func End, Address: 0x2cd3a0, Func Offset: 0x40
	scePrintf("Ps2InitTexCache - UNIMPLEMENTED!\n");
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
}

// 
// Start address: 0x2cd410
int Ps2TexLoad(_anon4* addr)
{
	unsigned int cache_flag;
	_anon0* timp;
	unsigned long* p;
	unsigned int i;
	unsigned int th;
	unsigned int tw;
	unsigned int psm;
	unsigned int tbw;
	// Line 2561, Address: 0x2cd410, Func Offset: 0
	// Line 2567, Address: 0x2cd430, Func Offset: 0x20
	// Line 2572, Address: 0x2cd434, Func Offset: 0x24
	// Line 2573, Address: 0x2cd448, Func Offset: 0x38
	// Line 2574, Address: 0x2cd454, Func Offset: 0x44
	// Line 2582, Address: 0x2cd45c, Func Offset: 0x4c
	// Line 2585, Address: 0x2cd460, Func Offset: 0x50
	// Line 2586, Address: 0x2cd480, Func Offset: 0x70
	// Line 2587, Address: 0x2cd484, Func Offset: 0x74
	// Line 2589, Address: 0x2cd488, Func Offset: 0x78
	// Line 2588, Address: 0x2cd48c, Func Offset: 0x7c
	// Line 2589, Address: 0x2cd494, Func Offset: 0x84
	// Line 2590, Address: 0x2cd4a0, Func Offset: 0x90
	// Line 2591, Address: 0x2cd4a4, Func Offset: 0x94
	// Line 2593, Address: 0x2cd4ac, Func Offset: 0x9c
	// Line 2595, Address: 0x2cd4bc, Func Offset: 0xac
	// Line 2597, Address: 0x2cd4c4, Func Offset: 0xb4
	// Line 2601, Address: 0x2cd4d0, Func Offset: 0xc0
	// Line 2603, Address: 0x2cd4dc, Func Offset: 0xcc
	// Line 2623, Address: 0x2cd4e4, Func Offset: 0xd4
	// Line 2607, Address: 0x2cd4ec, Func Offset: 0xdc
	// Line 2623, Address: 0x2cd4f4, Func Offset: 0xe4
	// Line 2624, Address: 0x2cd4fc, Func Offset: 0xec
	// Line 2626, Address: 0x2cd514, Func Offset: 0x104
	// Line 2633, Address: 0x2cd530, Func Offset: 0x120
	// Line 2639, Address: 0x2cd544, Func Offset: 0x134
	// Line 2640, Address: 0x2cd548, Func Offset: 0x138
	// Line 2642, Address: 0x2cd550, Func Offset: 0x140
	// Line 2645, Address: 0x2cd560, Func Offset: 0x150
	// Line 2643, Address: 0x2cd564, Func Offset: 0x154
	// Line 2645, Address: 0x2cd568, Func Offset: 0x158
	// Line 2643, Address: 0x2cd56c, Func Offset: 0x15c
	// Line 2645, Address: 0x2cd570, Func Offset: 0x160
	// Line 2646, Address: 0x2cd580, Func Offset: 0x170
	// Line 2648, Address: 0x2cd590, Func Offset: 0x180
	// Line 2649, Address: 0x2cd598, Func Offset: 0x188
	// Line 2651, Address: 0x2cd5a4, Func Offset: 0x194
	// Line 2652, Address: 0x2cd5a8, Func Offset: 0x198
	// Line 2651, Address: 0x2cd5ac, Func Offset: 0x19c
	// Line 2652, Address: 0x2cd5b8, Func Offset: 0x1a8
	// Line 2653, Address: 0x2cd5c0, Func Offset: 0x1b0
	// Line 2655, Address: 0x2cd5cc, Func Offset: 0x1bc
	// Line 2658, Address: 0x2cd5e8, Func Offset: 0x1d8
	// Line 2666, Address: 0x2cd5f0, Func Offset: 0x1e0
	// Line 2673, Address: 0x2cd608, Func Offset: 0x1f8
	// Line 2678, Address: 0x2cd624, Func Offset: 0x214
	// Line 2667, Address: 0x2cd628, Func Offset: 0x218
	// Line 2673, Address: 0x2cd630, Func Offset: 0x220
	// Line 2678, Address: 0x2cd634, Func Offset: 0x224
	// Line 2673, Address: 0x2cd63c, Func Offset: 0x22c
	// Line 2667, Address: 0x2cd640, Func Offset: 0x230
	// Line 2673, Address: 0x2cd644, Func Offset: 0x234
	// Line 2678, Address: 0x2cd658, Func Offset: 0x248
	// Line 2673, Address: 0x2cd660, Func Offset: 0x250
	// Line 2678, Address: 0x2cd66c, Func Offset: 0x25c
	// Line 2673, Address: 0x2cd670, Func Offset: 0x260
	// Line 2678, Address: 0x2cd678, Func Offset: 0x268
	// Line 2673, Address: 0x2cd67c, Func Offset: 0x26c
	// Line 2678, Address: 0x2cd688, Func Offset: 0x278
	// Line 2673, Address: 0x2cd68c, Func Offset: 0x27c
	// Line 2677, Address: 0x2cd6b0, Func Offset: 0x2a0
	// Line 2678, Address: 0x2cd6bc, Func Offset: 0x2ac
	// Line 2683, Address: 0x2cd6c4, Func Offset: 0x2b4
	// Line 2678, Address: 0x2cd6c8, Func Offset: 0x2b8
	// Line 2683, Address: 0x2cd6fc, Func Offset: 0x2ec
	// Line 2684, Address: 0x2cd700, Func Offset: 0x2f0
	// Line 2685, Address: 0x2cd708, Func Offset: 0x2f8
	// Line 2686, Address: 0x2cd710, Func Offset: 0x300
	// Line 2689, Address: 0x2cd770, Func Offset: 0x360
	// Line 2690, Address: 0x2cd77c, Func Offset: 0x36c
	// Line 2694, Address: 0x2cd78c, Func Offset: 0x37c
	// Line 2695, Address: 0x2cd794, Func Offset: 0x384
	// Line 2696, Address: 0x2cd79c, Func Offset: 0x38c
	// Line 2697, Address: 0x2cd7a8, Func Offset: 0x398
	// Line 2700, Address: 0x2cd808, Func Offset: 0x3f8
	// Line 2701, Address: 0x2cd814, Func Offset: 0x404
	// Line 2704, Address: 0x2cd824, Func Offset: 0x414
	// Line 2705, Address: 0x2cd82c, Func Offset: 0x41c
	// Line 2706, Address: 0x2cd834, Func Offset: 0x424
	// Line 2709, Address: 0x2cd854, Func Offset: 0x444
	// Line 2710, Address: 0x2cd860, Func Offset: 0x450
	// Line 2713, Address: 0x2cd870, Func Offset: 0x460
	// Line 2714, Address: 0x2cd878, Func Offset: 0x468
	// Line 2713, Address: 0x2cd87c, Func Offset: 0x46c
	// Line 2714, Address: 0x2cd880, Func Offset: 0x470
	// Line 2719, Address: 0x2cd884, Func Offset: 0x474
	// Line 2720, Address: 0x2cd894, Func Offset: 0x484
	// Line 2723, Address: 0x2cd89c, Func Offset: 0x48c
	// Line 2725, Address: 0x2cd8b0, Func Offset: 0x4a0
	// Line 2723, Address: 0x2cd8b4, Func Offset: 0x4a4
	// Line 2725, Address: 0x2cd8c0, Func Offset: 0x4b0
	// Line 2729, Address: 0x2cd8c4, Func Offset: 0x4b4
	// Line 2730, Address: 0x2cd8d8, Func Offset: 0x4c8
	// Line 2732, Address: 0x2cd8e0, Func Offset: 0x4d0
	// Line 2733, Address: 0x2cd8e8, Func Offset: 0x4d8
	// Line 2734, Address: 0x2cd8ec, Func Offset: 0x4dc
	// Func End, Address: 0x2cd910, Func Offset: 0x500
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
}

// 
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
}

// 
// Start address: 0x2cda90
void Ps2AlphaIs000(unsigned int* cp, unsigned int num)
{
	unsigned int i;
	// Line 2788, Address: 0x2cda90, Func Offset: 0
	// Line 2789, Address: 0x2cda9c, Func Offset: 0xc
	// Line 2790, Address: 0x2cdaa8, Func Offset: 0x18
	// Line 2791, Address: 0x2cdacc, Func Offset: 0x3c
	// Line 2794, Address: 0x2cdad0, Func Offset: 0x40
	// Line 2795, Address: 0x2cdae0, Func Offset: 0x50
	// Func End, Address: 0x2cdae8, Func Offset: 0x58
}

// 
// Start address: 0x2cdaf0
unsigned int Ps2AlphaIsHalf(unsigned int* cp, unsigned int num)
{
	unsigned int i;
	// Line 2802, Address: 0x2cdaf0, Func Offset: 0
	// Line 2806, Address: 0x2cdafc, Func Offset: 0xc
	// Line 2807, Address: 0x2cdb00, Func Offset: 0x10
	// Line 2806, Address: 0x2cdb08, Func Offset: 0x18
	// Line 2807, Address: 0x2cdb14, Func Offset: 0x24
	// Line 2808, Address: 0x2cdb20, Func Offset: 0x30
	// Func End, Address: 0x2cdb28, Func Offset: 0x38
}

// 
// Start address: 0x2cdb30
unsigned int Ps2Alpha4to8(unsigned int* cp, unsigned int num)
{
	unsigned int val;
	unsigned int i;
	// Line 2815, Address: 0x2cdb30, Func Offset: 0
	// Line 2817, Address: 0x2cdb3c, Func Offset: 0xc
	// Line 2819, Address: 0x2cdb40, Func Offset: 0x10
	// Line 2818, Address: 0x2cdb48, Func Offset: 0x18
	// Line 2819, Address: 0x2cdb54, Func Offset: 0x24
	// Line 2820, Address: 0x2cdb60, Func Offset: 0x30
	// Func End, Address: 0x2cdb68, Func Offset: 0x38
}

// 
// Start address: 0x2cdb70
int Ps2CheckTextureAlpha(void* pp)
{
	unsigned int flag;
	unsigned int num;
	unsigned int* cp;
	// Line 2859, Address: 0x2cdb70, Func Offset: 0
	// Line 2871, Address: 0x2cdb88, Func Offset: 0x18
	// Line 2872, Address: 0x2cdb9c, Func Offset: 0x2c
	// Line 2873, Address: 0x2cdba0, Func Offset: 0x30
	// Line 2874, Address: 0x2cdba4, Func Offset: 0x34
	// Line 2872, Address: 0x2cdba8, Func Offset: 0x38
	// Line 2874, Address: 0x2cdbb0, Func Offset: 0x40
	// Line 2876, Address: 0x2cdbc0, Func Offset: 0x50
	// Line 2879, Address: 0x2cdbf8, Func Offset: 0x88
	// Line 2880, Address: 0x2cdc08, Func Offset: 0x98
	// Line 2883, Address: 0x2cdc10, Func Offset: 0xa0
	// Line 2884, Address: 0x2cdc20, Func Offset: 0xb0
	// Line 2887, Address: 0x2cdc28, Func Offset: 0xb8
	// Line 2888, Address: 0x2cdc38, Func Offset: 0xc8
	// Line 2889, Address: 0x2cdc44, Func Offset: 0xd4
	// Line 2890, Address: 0x2cdc50, Func Offset: 0xe0
	// Line 2893, Address: 0x2cdc58, Func Offset: 0xe8
	// Line 2894, Address: 0x2cdc68, Func Offset: 0xf8
	// Line 2895, Address: 0x2cdc74, Func Offset: 0x104
	// Line 2897, Address: 0x2cdc7c, Func Offset: 0x10c
	// Line 2899, Address: 0x2cdc88, Func Offset: 0x118
	// Line 2901, Address: 0x2cdc90, Func Offset: 0x120
	// Line 2904, Address: 0x2cdcc8, Func Offset: 0x158
	// Line 2905, Address: 0x2cdcd8, Func Offset: 0x168
	// Line 2906, Address: 0x2cdce4, Func Offset: 0x174
	// Line 2909, Address: 0x2cdcec, Func Offset: 0x17c
	// Line 2910, Address: 0x2cdcfc, Func Offset: 0x18c
	// Line 2911, Address: 0x2cdd08, Func Offset: 0x198
	// Line 2914, Address: 0x2cdd10, Func Offset: 0x1a0
	// Line 2915, Address: 0x2cdd20, Func Offset: 0x1b0
	// Line 2916, Address: 0x2cdd2c, Func Offset: 0x1bc
	// Line 2917, Address: 0x2cdd38, Func Offset: 0x1c8
	// Line 2918, Address: 0x2cdd44, Func Offset: 0x1d4
	// Line 2921, Address: 0x2cdd4c, Func Offset: 0x1dc
	// Line 2922, Address: 0x2cdd5c, Func Offset: 0x1ec
	// Line 2923, Address: 0x2cdd68, Func Offset: 0x1f8
	// Line 2924, Address: 0x2cdd74, Func Offset: 0x204
	// Line 2926, Address: 0x2cdd7c, Func Offset: 0x20c
	// Line 2929, Address: 0x2cdd88, Func Offset: 0x218
	// Line 2933, Address: 0x2cdd8c, Func Offset: 0x21c
	// Line 2948, Address: 0x2cddb4, Func Offset: 0x244
	// Line 2949, Address: 0x2cddbc, Func Offset: 0x24c
	// Line 2950, Address: 0x2cddc4, Func Offset: 0x254
	// Line 2954, Address: 0x2cddd0, Func Offset: 0x260
	// Line 2956, Address: 0x2cddd8, Func Offset: 0x268
	// Line 3026, Address: 0x2cdddc, Func Offset: 0x26c
	// Func End, Address: 0x2cddf8, Func Offset: 0x288
}*/

// 
// Start address: 0x2cde00
void Ps2InitPS2_GS_SAVE()
{
	// Line 3450, Address: 0x2cde00, Func Offset: 0
	// Line 3453, Address: 0x2cde10, Func Offset: 0x10
	// Line 3451, Address: 0x2cde14, Func Offset: 0x14
	// Line 3453, Address: 0x2cde18, Func Offset: 0x18
	// Line 3451, Address: 0x2cde1c, Func Offset: 0x1c
	// Line 3453, Address: 0x2cde20, Func Offset: 0x20
	// Line 3454, Address: 0x2cde30, Func Offset: 0x30
	// Line 3456, Address: 0x2cde3c, Func Offset: 0x3c
	// Line 3457, Address: 0x2cde44, Func Offset: 0x44
	// Line 3459, Address: 0x2cde50, Func Offset: 0x50
	// Line 3460, Address: 0x2cde58, Func Offset: 0x58
	// Line 3462, Address: 0x2cde60, Func Offset: 0x60
	// Line 3463, Address: 0x2cde68, Func Offset: 0x68
	// Line 3465, Address: 0x2cde74, Func Offset: 0x74
	// Line 3466, Address: 0x2cde7c, Func Offset: 0x7c
	// Line 3468, Address: 0x2cde88, Func Offset: 0x88
	// Line 3469, Address: 0x2cde90, Func Offset: 0x90
	// Line 3471, Address: 0x2cde9c, Func Offset: 0x9c
	// Line 3472, Address: 0x2cdea4, Func Offset: 0xa4
	// Line 3474, Address: 0x2cdeb0, Func Offset: 0xb0
	// Line 3475, Address: 0x2cdeb8, Func Offset: 0xb8
	// Line 3477, Address: 0x2cdec4, Func Offset: 0xc4
	// Line 3478, Address: 0x2cdecc, Func Offset: 0xcc
	// Line 3480, Address: 0x2cded8, Func Offset: 0xd8
	// Line 3481, Address: 0x2cdee0, Func Offset: 0xe0
	// Line 3483, Address: 0x2cdeec, Func Offset: 0xec
	// Line 3484, Address: 0x2cdef4, Func Offset: 0xf4
	// Line 3486, Address: 0x2cdef8, Func Offset: 0xf8
	// Func End, Address: 0x2cdf04, Func Offset: 0x104
	scePrintf("Ps2InitPS2_GS_SAVE - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2cdf10
void Ps2ScreenClear()
{
	// Line 3493, Address: 0x2cdf10, Func Offset: 0
	// Line 3498, Address: 0x2cdf18, Func Offset: 0x8
	// Line 3501, Address: 0x2cdf20, Func Offset: 0x10
	// Line 3504, Address: 0x2cdf30, Func Offset: 0x20
	// Line 3502, Address: 0x2cdf34, Func Offset: 0x24
	// Line 3504, Address: 0x2cdf38, Func Offset: 0x28
	// Line 3502, Address: 0x2cdf3c, Func Offset: 0x2c
	// Line 3504, Address: 0x2cdf40, Func Offset: 0x30
	// Line 3505, Address: 0x2cdf50, Func Offset: 0x40
	// Line 3507, Address: 0x2cdf5c, Func Offset: 0x4c
	// Line 3508, Address: 0x2cdf68, Func Offset: 0x58
	// Line 3510, Address: 0x2cdf74, Func Offset: 0x64
	// Line 3511, Address: 0x2cdf80, Func Offset: 0x70
	// Line 3513, Address: 0x2cdf8c, Func Offset: 0x7c
	// Line 3514, Address: 0x2cdf98, Func Offset: 0x88
	// Line 3516, Address: 0x2cdfa0, Func Offset: 0x90
	// Line 3517, Address: 0x2cdfa8, Func Offset: 0x98
	// Line 3519, Address: 0x2cdfb4, Func Offset: 0xa4
	// Line 3522, Address: 0x2cdfc4, Func Offset: 0xb4
	// Line 3520, Address: 0x2cdfcc, Func Offset: 0xbc
	// Line 3522, Address: 0x2cdfd8, Func Offset: 0xc8
	// Line 3523, Address: 0x2cdfe4, Func Offset: 0xd4
	// Line 3525, Address: 0x2cdfec, Func Offset: 0xdc
	// Line 3526, Address: 0x2cdff8, Func Offset: 0xe8
	// Line 3528, Address: 0x2ce000, Func Offset: 0xf0
	// Line 3529, Address: 0x2ce008, Func Offset: 0xf8
	// Line 3530, Address: 0x2ce010, Func Offset: 0x100
	// Line 3531, Address: 0x2ce018, Func Offset: 0x108
	// Func End, Address: 0x2ce024, Func Offset: 0x114
	scePrintf("Ps2ScreenClear - UNIMPLEMENTED!\n");
}

#define SCR_WIDTH 640
#define SCR_HEIGHT 224

#define GS_X_COORD(x) ((2048 - (SCR_WIDTH / 2) + x) * 16)
#define GS_Y_COORD(y) ((2048 - (SCR_HEIGHT / 2) + y) * 16)

#define WORKBASE (0x70000000)

#define DMAend  (7<<28)

#define    SCE_GS_FALSE         (0)
#define    SCE_GS_TRUE          (1)

#define SCE_GS_ALPHA_NEVER      (0)

#define    SCE_GS_AFAIL_KEEP    (0)

#define SCE_GS_DEPTH_ALWAYS     (1)
#define SCE_GS_DEPTH_GEQUAL     (2)

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

/*// 
// Start address: 0x2ce150
void Ps2ZbuffOff()
{
	// Line 3613, Address: 0x2ce150, Func Offset: 0
	// Line 3618, Address: 0x2ce158, Func Offset: 0x8
	// Line 3620, Address: 0x2ce160, Func Offset: 0x10
	// Line 3623, Address: 0x2ce170, Func Offset: 0x20
	// Line 3621, Address: 0x2ce174, Func Offset: 0x24
	// Line 3623, Address: 0x2ce178, Func Offset: 0x28
	// Line 3621, Address: 0x2ce17c, Func Offset: 0x2c
	// Line 3623, Address: 0x2ce180, Func Offset: 0x30
	// Line 3624, Address: 0x2ce190, Func Offset: 0x40
	// Line 3631, Address: 0x2ce19c, Func Offset: 0x4c
	// Line 3632, Address: 0x2ce1ac, Func Offset: 0x5c
	// Line 3635, Address: 0x2ce1b8, Func Offset: 0x68
	// Line 3636, Address: 0x2ce1c0, Func Offset: 0x70
	// Line 3637, Address: 0x2ce1c8, Func Offset: 0x78
	// Func End, Address: 0x2ce1d4, Func Offset: 0x84
}

// 
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
}

// 
// Start address: 0x2ce290
void Ps2ZbuffOn()
{
	// Line 3664, Address: 0x2ce290, Func Offset: 0
	// Line 3669, Address: 0x2ce298, Func Offset: 0x8
	// Line 3671, Address: 0x2ce2a0, Func Offset: 0x10
	// Line 3674, Address: 0x2ce2b0, Func Offset: 0x20
	// Line 3672, Address: 0x2ce2b4, Func Offset: 0x24
	// Line 3674, Address: 0x2ce2b8, Func Offset: 0x28
	// Line 3672, Address: 0x2ce2bc, Func Offset: 0x2c
	// Line 3674, Address: 0x2ce2c0, Func Offset: 0x30
	// Line 3675, Address: 0x2ce2d0, Func Offset: 0x40
	// Line 3677, Address: 0x2ce2dc, Func Offset: 0x4c
	// Line 3678, Address: 0x2ce2ec, Func Offset: 0x5c
	// Line 3679, Address: 0x2ce2f8, Func Offset: 0x68
	// Line 3680, Address: 0x2ce308, Func Offset: 0x78
	// Line 3682, Address: 0x2ce314, Func Offset: 0x84
	// Line 3683, Address: 0x2ce31c, Func Offset: 0x8c
	// Line 3684, Address: 0x2ce324, Func Offset: 0x94
	// Func End, Address: 0x2ce330, Func Offset: 0xa0
}

// 
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
}

// 
// Start address: 0x2ce9f0
void Ps2ShadowEnd()
{
	// Line 3920, Address: 0x2ce9f0, Func Offset: 0
	// Line 3925, Address: 0x2ce9f8, Func Offset: 0x8
	// Line 3927, Address: 0x2cea00, Func Offset: 0x10
	// Line 3930, Address: 0x2cea10, Func Offset: 0x20
	// Line 3928, Address: 0x2cea14, Func Offset: 0x24
	// Line 3930, Address: 0x2cea18, Func Offset: 0x28
	// Line 3928, Address: 0x2cea1c, Func Offset: 0x2c
	// Line 3930, Address: 0x2cea20, Func Offset: 0x30
	// Line 3931, Address: 0x2cea30, Func Offset: 0x40
	// Line 3933, Address: 0x2cea3c, Func Offset: 0x4c
	// Line 3934, Address: 0x2cea48, Func Offset: 0x58
	// Line 3936, Address: 0x2cea54, Func Offset: 0x64
	// Line 3937, Address: 0x2cea60, Func Offset: 0x70
	// Line 3939, Address: 0x2cea6c, Func Offset: 0x7c
	// Line 3940, Address: 0x2cea7c, Func Offset: 0x8c
	// Line 3942, Address: 0x2cea88, Func Offset: 0x98
	// Line 3943, Address: 0x2cea90, Func Offset: 0xa0
	// Line 3945, Address: 0x2cea9c, Func Offset: 0xac
	// Line 3946, Address: 0x2ceaa4, Func Offset: 0xb4
	// Func End, Address: 0x2ceab0, Func Offset: 0xc0
}*/

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

/*// 
// Start address: 0x2ceb50
void Ps2AddPrim3DExI(unsigned long prim, void* dp, unsigned int num)
{
	float max;
	float max;
	float max;
	float fz[4][3];
	int j;
	<unknown fundamental type (0xa510)>* p128;
	unsigned long* pp;
	float zbuff_ab_vec[4];
	float zsum;
	unsigned int st_clip_flag;
	unsigned int clut_flag;
	unsigned int clip_flag;
	_anon0* timp;
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
}

// 
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
