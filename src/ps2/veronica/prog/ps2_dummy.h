#ifndef _PS2_DUMMY_H_
#define _PS2_DUMMY_H_

#include "types.h"

void _builtin_set_imask(int mask);
void Ps2Init();
void Ps2LoadModule(char* p);
void Snd_init();
void Cd_init();
void Card_init();
void PS2_jikken();
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
unsigned int Ps2BitCount(unsigned int value);
void Ps2InitTexCache();
int Ps2GlobalIndexTexLoad(unsigned int index);
int Ps2TexLoad(NJS_TEXMEMLIST* addr);
void Ps2SetFogColor();
void Ps2SetFogColorSys(unsigned int r, unsigned int g, unsigned int b);
void Ps2AlphaIs000(unsigned int* cp, unsigned int num);
unsigned int Ps2AlphaIsHalf(unsigned int* cp, unsigned int num);
unsigned int Ps2Alpha4to8(unsigned int* cp, unsigned int num);
int Ps2CheckTextureAlpha(void* pp);
void Ps2InitPS2_GS_SAVE();
void Ps2ScreenClear();
void Ps2DispScreenClear();
void Ps2ZbuffOff();
void Ps2ZbuffOff2();
void Ps2ZbuffOn();
void Ps2ShadowStart();
void Ps2ShadowDraw();
void Ps2ShadowMain0();
void Ps2ShadowMain1();
void Ps2ShadowEnd();
void Ps2Vu0ProgSend(unsigned int prog_no);
void Ps2Vu1ProgSend(unsigned int prog_no);
void Ps2AddPrim3DExI(unsigned long prim, void* dp, unsigned int num);
void PS2_Render_Tex_Sub();

extern unsigned char Ps2_PBUFF[1835008];
extern unsigned int Ps2_use_pt_flag;
extern sceGsDBuffDc Db;
extern PS2_GS_SAVE Ps2_gs_save;
extern unsigned int Ps2_albinoid_flag;
extern unsigned int Ps2_sys_cnt;
extern unsigned char* Ps2_MOVIE;
extern unsigned int Ps2_ice_flag;
extern float cmmat[16];
extern NJS_MATRIX lcmat[12] __attribute__((aligned(64)));
extern Uint8* _BSG_END;
extern NJS_VERTEX_BUF* _nj_vertex_buf_;
extern unsigned int _nj_control_3d_flag_;
extern NJS_SCREEN _nj_screen_;
extern unsigned char Ps2_DRAW_TMP[16384];
extern unsigned int Ps2_njControl3D_flag;
extern void (* VsyncFunc)();
extern void (* EorFunc)();
extern unsigned int Ps2_vcount;
extern unsigned int Ps2_dbuff;

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
};*/

#endif
