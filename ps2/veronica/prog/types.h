#define	CheckCmdReq(vol, pan, pitch)	(0x00|0|((vol)&1)|(((pan)&1)<<1)|(((pitch)&1)<<2))

typedef float	sceVu0FMATRIX[4][4];

typedef enum SDE_DATA_TYPE
{
	SDE_DATA_TYPE_SND_DRV = 0x56524453,
	SDE_DATA_TYPE_MULTI_UNIT = 0x544c4d53,
	SDE_DATA_TYPE_MIDI_DRM_BANK = 0x42444d53,
	SDE_DATA_TYPE_MIDI_SEQ_BANK = 0x42534d53,
	SDE_DATA_TYPE_MIDI_PRG_BANK = 0x42504d53,
	SDE_DATA_TYPE_SHOT_BANK = 0x42534f53,
	SDE_DATA_TYPE_PSTM_RING_BUF = 0x52535053,
	SDE_DATA_TYPE_FX_OUT_BANK = 0x424f4653,
	SDE_DATA_TYPE_FX_PRG_BANK = 0x42504653,
	SDE_DATA_TYPE_FX_PRG_WRK = 0x57504653
} SDE_DATA_TYPE;

typedef struct Unknown31
{
	float x;
	float y;
	float z;
	float w;
} Unknown31;

typedef struct sceCdCLOCK
{
	unsigned char stat;
	unsigned char second;
	unsigned char minute;
	unsigned char hour;
	unsigned char pad;
	unsigned char day;
	unsigned char month;
	unsigned char year;
} sceCdCLOCK;

typedef struct _SYS_RTC_DATE
{
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned char dayofweek;
	unsigned char ageofmoon;
} _SYS_RTC_DATE;

typedef struct _SYS_BT_SYSTEMID
{
	int nNo;
	int nAll;
	char szProduct[16];
} _SYS_BT_SYSTEMID;

typedef enum SYE_CBL_TAG
{
	SYE_CBL_NTSC,
	SYE_CBL_VGA,
	SYE_CBL_PAL,
	SYE_CBL_MAX
} SYE_CBL_TAG;

typedef struct SNDQUE
{
	int cmd;
	char vol;
	char pan;
	short pitch;
} SNDQUE;

typedef struct Unknown29
{
	char ppStrPvpl[4];
	unsigned int ppNextTag;
	unsigned short ppCategoryCode;
	unsigned short ppBankId;
	unsigned short ppEntryOffset;
	unsigned short ppEntryCount;
} Unknown29;

// SCE_GS_TEX0
typedef struct Unknown26
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
} Unknown26;


typedef struct Unknown27
{
	unsigned int gindex;
	unsigned int size;
	unsigned int count;
	void* addr;
	void* before;
	void* after;
} Unknown27;

// SCE_GS_TEX1
typedef struct Unknown28
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
} Unknown28;

typedef struct Unknown25
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
	Unknown26 GsTex0;
	Unknown28 GsTex1;
	unsigned int GsRegs;
	unsigned int GsTexClut;
	Unknown27 admin;
	unsigned int TpFlag;
	unsigned int ClampFlag;
} Unknown25;

typedef struct Unknown24
{
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
	unsigned long GsTex0;
	unsigned long GsTex1;
	unsigned int GsRegs;
	unsigned int GsTexClut;
} Unknown24;

typedef struct MEMORYCARDPORT
{
	int lCrntType;
	int lPrevType;
	int lFreeSize;
	int lFormatType;
} MEMORYCARDPORT;


typedef struct MEMORYCARDSTATE
{
	unsigned int ulState;
	unsigned int ulError;
	unsigned int ulMcSubState;
	unsigned int ulFileSize;
	int lCurrentPort;
	int lOpenFileNumber;
	int lSelectFileNumber;
	int lOpenMode;
	unsigned short usMcSysState;
	void* vpAddr;
	char cCurrentDir[50];
	char cOpenFileName[32];
	char cRetryCount;
	char cMcCheckFlag;
	char cCheckMcFlag;
	MEMORYCARDPORT Port[2];
} MEMORYCARDSTATE;


typedef struct Unknown22
{
	int PerType;
	int OldPerType;
	int PerTypeEx;
	unsigned int Flag;
	int SoftReset;
	unsigned int on;
	unsigned int press;
	unsigned int Rept;
	unsigned int on2;
	unsigned int on2old;
	unsigned int press2;
	unsigned short l;
	unsigned short r;
	short x1;
	short y1;
	short x2;
	short y2;
	short Calibrate;
} Unknown22;


typedef struct Vector3 {
    float x;
    float y;
    float z;
}
Vector3;


typedef struct Vector3Col {
    /*  0 */ float x;
    /*  4 */ float y;
    /*  8 */ float z;
    /* 12 */ unsigned int col;
}
Vector3Col;


typedef struct Vector5Col {
    /*  0 */ float x;
    /*  4 */ float y;
    /*  8 */ float z;
    /* 12 */ float u;
    /* 16 */ float v;
    /* 20 */ unsigned int col;
}
Vector5Col;


typedef struct Point {
    float x;
    float y;
}
Point;


typedef struct PositionVelocity {
    /*  0 */ float px;
    /*  4 */ float py;
    /*  8 */ float pz;
    /* 12 */ float vx;
    /* 16 */ float vy;
    /* 20 */ float vz;
}
PositionVelocity;


typedef struct Unknown21
{
	int PatId;
	int Mode;
	int Mode2;
	int NextMode;
	int NextReturnCode;
	int PortId;
	int OptIndex;
	int OptLevel;
	int NextOptLevel;
	int OptScrX;
	int OptScrY;
	unsigned int PalNo;
	unsigned int PalMode;
	unsigned int FontBaseColor;
	unsigned char* SysMemPtr;
	unsigned char* MsgPtr;
	unsigned char* ptr[8];
	float Timer;
	float FadeRate;
	float FadeSpeed;
	float SaverTimer;
	float SaverRate;
	float FlushCount;
	float FlushSpeed;
	float FlushCount2;
	float FlushSpeed2;
	float ScrollPlatePosX[2][2];
	char Active;
	char AppMode;
	char ExtraFlag;
	char FadeType;
	char SaverCommand;
	char Count;
	char LastLevel;
	char FromTitle;
	char CurrentDiscId;
	char NextDiscId;
	char ErrorId;
	unsigned char ErrorMsgFlushCount;
	char AnimId;
	unsigned char AnimTime;
	char GenFlag;
	char PalFlag;
	char SrFlag;
	char OptFadeType;
	char TexFlag;
	char SoundMode;
	char vibration;
	char keytype;
	char adjust_x;
	char adjust_y;
	char OptSaveFlag;
	char vMode;
	char DriveNo;
	char MsgNo;
	char DepthLevel;
	char OldVmOpMode;
	char VmOpMode;
	char SetTexture[2];
	char KeyCommandCount[7];
	char Cursor[3];
	char CursorMax[3];
	char CursorFlag[4][4];
	char ModeCommandId[4];
} Unknown21;


typedef union Unknown20 {
    unsigned int work;
    unsigned int clip;
}
Unknown20;


typedef struct VertexBuffer {
    /*  0 */ Unknown20 a;
    /*  4 */ float sx;
    /*  8 */ float sy;
    /* 12 */ float oow;
    /* 16 */ Vector3 point;
    /* 28 */ unsigned int reserve;
    /* 32 */ float u;
    /* 36 */ float v;
    /* 40 */ float inten[2];
    /* 48 */ Vector3 vector;
    /* 60 */ unsigned int flag;
}
VertexBuffer;


typedef struct Camera {
    /*   0 */ unsigned int flg;
    /*   4 */ int camver;
    /*   8 */ unsigned char mode0;
    /*   9 */ unsigned char mode1;
    /*  10 */ unsigned char mode2;
    /*  11 */ unsigned char mode3;
    /*  12 */ float px;
    /*  16 */ float py;
    /*  20 */ float pz;
    /*  24 */ float vx;
    /*  28 */ float vy;
    /*  32 */ float vz;
    /*  36 */ float wpx;
    /*  40 */ float wpy;
    /*  44 */ float wpz;
    /*  48 */ float plx;
    /*  52 */ float ply;
    /*  56 */ float plz;
    /*  60 */ float pxp;
    /*  64 */ float pyp;
    /*  68 */ float pzp;
    /*  72 */ float ofx;
    /*  76 */ float ofy;
    /*  80 */ float ofz;
    /*  84 */ int ax;
    /*  88 */ int ay;
    /*  92 */ int az;
    /*  96 */ int axp;
    /* 100 */ int ayp;
    /* 104 */ int azp;
    /* 108 */ float ln;
    /* 112 */ float pln;
    /* 116 */ float xr;
    /* 120 */ float xn;
    /* 124 */ float yr;
    /* 128 */ float yn;
    /* 132 */ int pers;
    /* 136 */ int ppers;
    /* 140 */ int ncut;
    /* 144 */ int ocut;
    /* 148 */ unsigned int ocflg;
    /* 152 */ unsigned int attr;
    /* 156 */ float* mtx;
    /* 160 */ float* mtxb;
    /* 164 */ int evc_no;
    /* 168 */ int hct;
    /* 172 */ int ct0;
    /* 176 */ int ct1;
    /* 180 */ int keyf_no;
    /* 184 */ float frm;
    /* 188 */ float spd;
    /* 192 */ float pxn;
    /* 196 */ float pyn;
    /* 200 */ float pzn;
    /* 204 */ int axn;
    /* 208 */ int ayn;
    /* 212 */ int azn;
    /* 216 */ int pe_ax;
    /* 220 */ int pe_pers;
    /* 224 */ unsigned int fog_col;
    /* 228 */ float fog_nr;
    /* 232 */ float fog_fr;
    /* 236 */ float ips[20][3];
    /* 476 */ float ian[20][3];
    /* 716 */ float ipf[20][3];
    /* 956 */ float icr[20][3];
}
Camera;


typedef struct Timestamp {
    /* 0 */ unsigned short year;
    /* 2 */ unsigned char month;
    /* 3 */ unsigned char day;
    /* 4 */ unsigned char hour;
    /* 5 */ unsigned char minute;
    /* 6 */ unsigned char second;
    /* 7 */ unsigned char dayofweek;
}
Timestamp;


typedef struct Disk {
    /*  0 */ unsigned char volume[32];
    /* 32 */ unsigned short total_blocks;
    /* 34 */ unsigned short total_user_blocks;
    /* 36 */ unsigned short free_blocks;
    /* 38 */ unsigned short free_user_blocks;
    /* 40 */ unsigned short total_exe_blocks;
    /* 42 */ unsigned short free_exe_blocks;
    /* 44 */ unsigned short block_size;
    /* 46 */ unsigned short icon_no;
    /* 48 */ Timestamp time;
}
Disk;


typedef struct Drive {
    /*  0 */ unsigned short Ready;
    /*  2 */ unsigned short IsFormat;
    /*  4 */ unsigned int LastError;
    /*  8 */ unsigned int ProgressCount;
    /* 12 */ unsigned int ProgressMax;
    /* 16 */ unsigned int Operation;
    /* 20 */ Disk DiskInfo;
    /* 76 */ unsigned int Connect;
    /* 80 */ void* Work;
    /* 84 */ unsigned int WorkSize;
    /* 88 */ unsigned int Capacity;
    /* 92 */ int MemMode;
}
Drive;


typedef struct Controller {
    /*  0 */ int PerType;
    /*  4 */ int OldPerType;
    /*  8 */ int PerTypeEx;
    /* 12 */ unsigned int Flag;
    /* 16 */ int SoftReset;
    /* 20 */ unsigned int on;
    /* 24 */ unsigned int press;
    /* 28 */ unsigned int Rept;
    /* 32 */ unsigned int on2;
    /* 36 */ unsigned int on2old;
    /* 40 */ unsigned int press2;
    /* 44 */ unsigned short l;
    /* 46 */ unsigned short r;
    /* 48 */ short x1;
    /* 50 */ short y1;
    /* 52 */ short x2;
    /* 54 */ short y2;
    /* 56 */ short Calibrate;
}
Controller;


typedef struct ControllerButton {
    int Type;
    unsigned int Button;
}
ControllerButton;


typedef struct KeyRepeatInfo {
    unsigned int WaitFlag;
    unsigned int WaitCnt;
    unsigned int Key;
}
KeyRepeatInfo;


typedef struct VibrationInfo {
    /* 0 */ unsigned char unit;
    /* 1 */ unsigned char flag;
    /* 2 */ char power;
    /* 3 */ unsigned char freq;
    /* 4 */ unsigned char inc;
    /* 5 */ unsigned char reserved[3];
}
VibrationInfo;


typedef struct GDS_DCF GDS_DCF;
typedef struct GDS_FS_LIF GDS_FS_LIF;


typedef struct GDS_FS_DIRREC_ENT {
    /*  0 */ int fad;
    /*  4 */ int fsize;
    /*  8 */ unsigned char flag;
    /*  9 */ unsigned char sid;
    /* 10 */ char fname[32];
    /* 42 */ char pad[2];
}
GDS_FS_DIRREC_ENT;


typedef struct GDS_FS_DIRINFO {
    /*  0 */ int fad;
    /*  4 */ int fsize;
    /*  8 */ unsigned char flag;
    /*  9 */ unsigned char pad[3];
}
GDS_FS_DIRINFO;


typedef struct GDS_FS_WORK GDS_FS_WORK;
typedef struct GDS_FS_HANDLE {
    /*  0 */ GDS_FS_WORK* wk;
    /*  4 */ int fid;
    /*  8 */ int fad;
    /* 12 */ int fsize;
    /* 16 */ int fsctsize;
    /* 20 */ int ofs;
    /* 24 */ int trnsed;
    /* 28 */ int rsize;
    /* 32 */ int trsize;
    /* 36 */ void(*rdendcb)(void*);
    /* 40 */ void* rdcb_1st;
    /* 44 */ void(*trendcb)(void*);
    /* 48 */ void* trcb_1st;
    /* 52 */ void(*errcb)(void*, int);
    /* 56 */ void* errcb_1st;
    /* 60 */ int gdchn;
    /* 64 */ int gdchn_wait;
    /* 68 */ int ex_errcode;
    /* 72 */ short act;
    /* 74 */ short trflag;
    /* 76 */ short used;
    /* 78 */ short tmode;
    /* 80 */ short stat;
    /* 82 */ short err;
}
GDS_FS_HANDLE;


typedef struct GDS_FS_DIRREC_TBL {
    /*  0 */ int dir_num;
    /*  4 */ int max_ent;
    /*  8 */ int dir_fad;
    /* 12 */ int pad;
    /* 16 */ GDS_FS_DIRREC_ENT dirrec_tbl[1];
}
GDS_FS_DIRREC_TBL;


typedef struct GDS_FS_WORK {
    /*    0 */ int max_open;
    /*    4 */ int pathtbl_fad;
    /*    8 */ int pathtbl_size;
    /*   12 */ GDS_DCF* dcf;
    /*   16 */ GDS_FS_DIRREC_TBL* curdir;
    /*   20 */ GDS_FS_HANDLE* syshdl;
    /*   24 */ GDS_FS_HANDLE* hndtbl;
    /*   28 */ GDS_FS_HANDLE* now_work;
    /*   32 */ int f_svr;
    /*   36 */ void(*g_errcb)(void*, int);
    /*   40 */ void* g_errcb_1st;
    /*   44 */ int gdc_ver;
    /*   48 */ int errstat;
    /*   52 */ int istray;
    /*   56 */ short f_init;
    /*   58 */ short daplayed;
    /*   60 */ GDS_FS_LIF* liftbl;
    /*   64 */ unsigned int sctbuf[1040];
    /* 4224 */ GDS_FS_HANDLE hndlist[1];
}
GDS_FS_WORK;


typedef struct LfOpen {
    unsigned int Flag;
    GDS_FS_HANDLE* GdFs;
}
LfOpen;


typedef struct TextureFileLocation {
    void* filename;
    unsigned int attr;
    unsigned int texaddr;
}
TextureFileLocation;


typedef struct TextureList {
    TextureFileLocation* textures;
    unsigned int nbTexture;
}
TextureList;


typedef struct PeripheralInfo {
    /*   0 */ unsigned int type;
    /*   4 */ unsigned int reserved[3];
    /*  16 */ unsigned char is_root;
    /*  17 */ unsigned char area_code;
    /*  18 */ unsigned char connector_dir[2];
    /*  20 */ char product_name[32];
    /*  52 */ char license[64];
    /* 116 */ unsigned short stdby_pow;
    /* 118 */ unsigned short max_pow;
}
PeripheralInfo;


typedef struct Peripheral {
    /*  0 */ unsigned int id;
    /*  4 */ unsigned int support;
    /*  8 */ unsigned int on;
    /* 12 */ unsigned int off;
    /* 16 */ unsigned int press;
    /* 20 */ unsigned int release;
    /* 24 */ unsigned short r;
    /* 26 */ unsigned short l;
    /* 28 */ short x1;
    /* 30 */ short y1;
    /* 32 */ short x2;
    /* 34 */ short y2;
    /* 36 */ char* name;
    /* 40 */ void* extend;
    /* 44 */ unsigned int old;
    /* 48 */ PeripheralInfo* info;
}
Peripheral;


typedef struct Model {
    /*  0 */ int* vlist;
    /*  4 */ short* plist;
    /*  8 */ Vector3 center;
    /* 20 */ float r;
}
Model;


typedef struct npobj npobj;
typedef struct npobj {
    /*  0 */ unsigned int evalflags;
    /*  4 */ Model* model;
    /*  8 */ float pos[3];
    /* 20 */ int ang[3];
    /* 32 */ float scl[3];
    /* 44 */ npobj* child;
    /* 48 */ npobj* sibling;
}
npobj;


typedef struct Surface {
    /*  0 */ unsigned int Type;
    /*  4 */ unsigned int BitDepth;
    /*  8 */ unsigned int PixelFormat;
    /* 12 */ unsigned int nWidth;
    /* 16 */ unsigned int nHeight;
    /* 20 */ unsigned int TextureSize;
    /* 24 */ unsigned int fSurfaceFlags;
    /* 28 */ unsigned int* pSurface;
    /* 32 */ unsigned int* pVirtual;
    /* 36 */ unsigned int* pPhysical;
}
Surface;


typedef struct TextureInfo {
    void* texaddr;
    Surface texsurface;
}
TextureInfo;


typedef struct Unknown30
{
	unsigned int globalIndex;
	unsigned int bank;
	unsigned int tspparambuffer;
	unsigned int texparambuffer;
	unsigned int texaddr;
	TextureInfo texinfo;
	unsigned short count;
	unsigned short dummy;
} Unknown30;


typedef struct Color {
    /*  0 */ float a;
    /*  4 */ float r;
    /*  8 */ float g;
    /* 12 */ float b;
}
Color;


typedef struct Door {
    /*  0 */ unsigned int flg;
    /*  4 */ char stg_no;
    /*  5 */ char rom_no;
    /*  6 */ unsigned char pos_no;
    /*  7 */ unsigned char dor_tp;
    /*  8 */ unsigned char mode0;
    /*  9 */ unsigned char mode1;
    /* 10 */ unsigned char mode2;
    /* 11 */ unsigned char mode3;
    /* 12 */ int ct0;
    /* 16 */ int ct1;
    /* 20 */ int ct2;
    /* 24 */ int ct3;
}
Door;


typedef struct Unknown19 {
    /*  0 */ int mode;
    /*  4 */ int frame;
    /*  8 */ int count;
    /* 12 */ int vtx_opq_a;
    /* 16 */ int vtx_opq_b;
    /* 20 */ int vtx_trs_a;
    /* 24 */ int vtx_trs_b;
    /* 28 */ int vtx_punch;
    /* 32 */ int vtx_total;
}
Unknown19;


typedef struct Unknown18 {
    short jnt_a;
    short jnt_b;
    int cap_r;
}
Unknown18;


typedef struct Unknown17 {
    Vector3 c1;
    Vector3 c2;
    float r;
}
Unknown17;


typedef struct Unknown16 {
    /*  0 */ Vector3 c1;
    /* 12 */ Vector3 c2;
    /* 24 */ float r1;
    /* 28 */ float r2;
}
Unknown16;


typedef struct Unknown15 {
    unsigned char flg;
    unsigned char type;
    unsigned char id;
    char flr_no;
    unsigned int attr;
    float px;
    float py;
    float pz;
    float w;
    float h;
    float d;
    unsigned char prm0;
    unsigned char prm1;
    unsigned char prm2;
    unsigned char prm3;
}
Unknown15;


typedef struct Unknown14 {
    Vector3 ps;
    float nr;
    float fr;
    float cr;
    float cg;
    float cb;
}
Unknown14;


typedef struct Unknown13 {
    int lsrc;
    float iamb;
    float idif;
    float ispc;
    float nrang;
    float frang;
    void* func;
    int iang;
    int oang;
    Color argb;
}
Unknown13;


typedef struct Unknown12 {
    float ratten;
    float ipd;
    float nrr;
    float frr;
    float cosi;
    float cose;
    float idev;
    float odev;
    float rate;
    float intns;
    int exp;
    int reserve;
    Vector3 lpnt;
    Vector3 lvctr;
    Vector3 lmvctr;
    Color atten;
    Color amb;
    Color dif;
    Color spc;
    Color mamb;
    Color mdif;
    Color mspc;
}
Unknown12;


typedef struct Unknown11 {
    float mtrx[16];
    Vector3 pnt;
    Vector3 vctr;
    int stat;
    int reserve;
    Unknown12 ltcal;
    Unknown13 attr;
}
Unknown11;


typedef struct Unknown10 {
    unsigned int flg;
    unsigned int type;
    int aspd;
    int lkflg;
    int lkno;
    int lkono;
    int lsrc;
    float px;
    float py;
    float pz;
    float lx;
    float ly;
    float lz;
    float vx;
    float vy;
    float vz;
    float spc;
    float dif;
    float amb;
    float r;
    float g;
    float b;
    float nr;
    float fr;
    int iang;
    int oang;
    int ax;
    int ay;
    int az;
    unsigned int mode;
    int ct0;
    int ct1;
    int ct2;
    int ct3;
    float wpx;
    float wpy;
    float wpz;
    float wvx;
    float wvy;
    float wvz;
    float wspc;
    float wdif;
    float wamb;
    float wr;
    float wg;
    float wb;
    float wnr;
    float wfr;
    int wiang;
    int woang;
    int wax;
    int way;
    int waz;
    unsigned char* lkwkp;
    unsigned char* exp;
    Unknown11* light;
}
Unknown10;


typedef struct Unknown9 {
    float x;
    float y;
    float z;
    float u;
    float v;
    unsigned int bcol;
    unsigned int ocol;
}
Unknown9;


typedef struct Unknown8 {
    unsigned int flg;
    unsigned short id;
    unsigned short type;
    short flr_no;
    unsigned short mdlver;
    float px;
    float py;
    float pz;
    float sx;
    float sy;
    float sz;
    short ay;
    short ax;
}
Unknown8;


typedef struct Unknown7 {
    unsigned char* adr;
    unsigned int gidx;
    unsigned int attr;
    unsigned int w;
    unsigned int h;
}
Unknown7;


typedef struct Unknown6 {
    Vector3 c;
    float r;
}
Unknown6;


typedef struct Unknown5 {
    unsigned int flg;
    int dmy;
    unsigned int dummy[2];
    float mtx[16];
}
Unknown5;

typedef struct Unknown4 {
    unsigned int flg;
    unsigned int obj_num;
    void* datP;
    npobj* objP;
    TextureList* texP;
    Unknown5* owP;
}
Unknown4;


typedef struct Unknown3 {
    void* p[2];
}
Unknown3;


typedef struct Unknown2 {
    unsigned int flg;
    unsigned int obj_num;
    unsigned int frm_num;
    void* datP;
    Unknown3* md2P;
    unsigned short* atrP;
}
Unknown2;


typedef struct Unknown1 {
    unsigned int flg;
    unsigned short id;
    unsigned short type;
    char flr_no;
    char flr_nob;
    unsigned char mdlver;
    unsigned char param;
    unsigned char mode0;
    unsigned char mode1;
    unsigned char mode2;
    unsigned char mode3;
    float px;
    float py;
    float pz;
    int ax;
    int ay;
    int az;
    float ar;
    float aw;
    float ah;
    float ad;
    float car;
    float cah;
    float pxb;
    float pyb;
    float pzb;
    int axb;
    int ayb;
    int azb;
    float gpx;
    float gpy;
    float gpz;
    float lox;
    float loy;
    float loz;
    float aox;
    float aoy;
    float aoz;
    float spd;
    unsigned int flg2;
    unsigned int mdflg;
    unsigned int stflg;
    unsigned int Dummy3;
    int draw_tp;
    int mdl_n;
    void* mskp;
    unsigned int Dummy[1];
    int* skp[16];
    npobj* mbp[16];
    TextureList* txp[16];
    Unknown4 mdl[16];
    Unknown4* mlwP;
    unsigned int mdl_no;
    int lkono;
    unsigned char* lkwkp;
    unsigned char* exp0;
    unsigned char* exp1;
    unsigned char* exp2;
    unsigned char* exp3;
    unsigned char mtxbuf[64];
    float mtx[16];
    npobj* obj_a;
    npobj* obj_b;
    float shp_ct;
    char clp_jno[8];
    int lok_jno;
    Unknown2* mnwP;
    Unknown2* mnwPb;
    unsigned int mtn_attr;
    unsigned int mtn_no;
    int frm_no;
    unsigned int frm_mode;
    int hokan_rate;
    unsigned int hokan_count;
    unsigned int hokan_ctbak;
    int mtn_add;
    unsigned int mtn_md;
    unsigned char* mtn_tp;
    int axp;
    int ayp;
    int azp;
    short psh_ct;
    short psh_idx;
    int idx_ct;
    int mtn_chk;
    float ofx;
    float ofy;
    float ofz;
    float sx;
    float sy;
    float sz;
    float sxb;
    float syb;
    float szb;
    float xn;
    float yn;
    float zn;
    int ct0;
    int ct1;
    int ct2;
    int ct3;
    unsigned char* objbak;
    Unknown6 cspr;
    int pn;
    Vector3Col* pvp;
    Vector5Col* tvp;
    Vector3Col pv[4];
    Vector5Col tv[4];
    int bl_src;
    int bl_dst;
    int ani_ct;
    int tex_id;
    int aspd;
    unsigned int gidx;
    int bank;
    char jno[16];
    char hide[4];
    void(*func)(void*);
    int idx;
    int Dummy2;
}
Unknown1;


typedef struct BH_PWORK {
    unsigned int flg;
    unsigned short id;
    unsigned short type;
    char flr_no;
    char flr_nob;
    unsigned char mdlver;
    unsigned char param;
    unsigned char mode0;
    unsigned char mode1;
    unsigned char mode2;
    unsigned char mode3;
    float px;
    float py;
    float pz;
    int ax;
    int ay;
    int az;
    float ar;
    float aw;
    float ah;
    float ad;
    float car;
    float cah;
    float pxb;
    float pyb;
    float pzb;
    int axb;
    int ayb;
    int azb;
    float gpx;
    float gpy;
    float gpz;
    float lox;
    float loy;
    float loz;
    float aox;
    float aoy;
    float aoz;
    float spd;
    unsigned int flg2;
    unsigned int mdflg;
    unsigned int stflg;
    unsigned int Dummy3;
    int draw_tp;
    int mdl_n;
    void* mskp;
    unsigned int Dummy[1];
    int* skp[16];
    npobj* mbp[16];
    TextureList* txp[16];
    Unknown4 mdl[16];
    Unknown4* mlwP;
    unsigned int mdl_no;
    int lkono;
    unsigned char* lkwkp;
    unsigned char* exp0;
    unsigned char* exp1;
    unsigned char* exp2;
    unsigned char* exp3;
    unsigned char mtxbuf[64];
    float mtx[16];
    npobj* obj_a;
    npobj* obj_b;
    float shp_ct;
    char clp_jno[8];
    int lok_jno;
    Unknown2* mnwP;
    Unknown2* mnwPb;
    unsigned int mtn_attr;
    unsigned int mtn_no;
    int frm_no;
    unsigned int frm_mode;
    int hokan_rate;
    unsigned int hokan_count;
    unsigned int hokan_ctbak;
    int mtn_add;
    unsigned int mtn_md;
    unsigned char* mtn_tp;
    int axp;
    int ayp;
    int azp;
    short psh_ct;
    short psh_idx;
    int idx_ct;
    int mtn_chk;
    float ofx;
    float ofy;
    float ofz;
    float sx;
    float sy;
    float sz;
    float sxb;
    float syb;
    float szb;
    float xn;
    float yn;
    float zn;
    int ct0;
    int ct1;
    int ct2;
    int ct3;
    int wpnr_no;
    int wpnl_no;
    unsigned int at_flg;
    Unknown17 watr;
    Unknown18* cpcl;
    short wax;
    short way;
    short waz;
    short waxp;
    short wayp;
    short wazp;
    int hp;
    int dam[64];
    int djnt_no;
    int cpcl_no;
    int dax;
    int day;
    float dpx;
    float dpy;
    float dpz;
    float dvx;
    float dvy;
    float dvz;
    int flr_snd;
    int ko_num;
    int footeff;
    int src_no;
    unsigned char* kdnp;
    int kdnidx;
    void* dan_ap;
    unsigned int comb_flg;
    unsigned int comb_wep;
    int comb_pnt;
    int comb_timeout;
    int total_dam;
    unsigned int Dummy2[2];
}
BH_PWORK;


typedef struct System {
    unsigned int ssd_ver;
    unsigned int ssd_flg;
    unsigned int ssd_reserve;
    char keytype;
    char adjust_x;
    char adjust_y;
    char vibration;
    int best_tm[8];
    unsigned int sys_partid;
    unsigned int itm_partid;
    unsigned int fil_partid;
    unsigned int dor_partid;
    unsigned int ss_flg;
    int pdm_no;
    unsigned int typ_flg;
    unsigned short typ_md0;
    unsigned short typ_md1;
    void* typ_exp;
    unsigned int tk_flg;
    unsigned int ts_flg;
    unsigned int gm_flg;
    unsigned int st_flg;
    unsigned int cb_flg;
    unsigned int rm_flg;
    unsigned int pt_flg;
    unsigned int sp_flg;
    unsigned int ef_flg;
    unsigned int error;
    unsigned int version;
    int save_ct;
    char ply_id;
    char stg_no;
    char rom_no;
    char rcase;
    char pos_no;
    char cut_no;
    char flr_no;
    char reserve0;
    int gm_mode;
    unsigned int ev_flg[32];
    unsigned int it_flg[16];
    unsigned int ic_flg[16];
    unsigned int ed_flg[32];
    unsigned int ky_flg[16];
    unsigned int mp_flg[8];
    unsigned int itm[384];
    unsigned int ply_stflg[4];
    Vector3 ply_pos;
    int ply_ang;
    char ply_wno[4];
    short ply_hp[4];
    unsigned char evt_posno[4];
    int time;
    int stv_tm;
    short spray_ct;
    short retry_ct;
    short clear_ct;
    short reserve1;
    unsigned int save_end;
    char stg_nob;
    char rom_nob;
    char pos_nob;
    char rcase_b;
    unsigned int en_flg[4];
    TextureList* et_lp[100][16][16];
    TextureList* ot_lp[1300];
    TextureList* it_lp[200];
    int eft_n;
    TextureList* eft_lp[8];
    int loop_ct;
    int loop_now;
    int cng_pid;
    Peripheral* p1per;
    Peripheral* p2per;
    Peripheral* kbper;
    Peripheral* msper;
    Peripheral ms_per;
    int pad_port;
    unsigned int pad_on;
    unsigned int pad_oncpy;
    unsigned int pad_ps;
    unsigned int pad_rs;
    unsigned int pad_old;
    unsigned int pad_onb;
    unsigned int pad_psb;
    unsigned int pad_oldb;
    short pad_ax;
    short pad_ay;
    short pad_dx;
    short pad_dy;
    unsigned short pad_ar;
    unsigned short pad_al;
    int fixcno;
    int fixkno;
    unsigned int exm_attr;
    short evc_no;
    short evc_kn;
    short evc_ono;
    short evc_okn;
    int evc_sc;
    unsigned char mn_mode0;
    unsigned char mn_mode1;
    unsigned char mn_mode2;
    unsigned char mn_mode3;
    unsigned char mn_md0;
    unsigned char mn_md1;
    unsigned char mn_md2;
    unsigned char mn_md3;
    int mn_setct;
    unsigned int mn_stack[8];
    unsigned int sdm_flg;
    unsigned int sdm_mode;
    unsigned char* ltc_bp;
    unsigned int ltc_tsbak;
    int ewk_n;
    unsigned int enow;
    unsigned int onow;
    unsigned int efnow;
    int vsyc_ct;
    int vsyc_flg;
    int fog_ct;
    int bcl_ct;
    int gfrm_ct;
    int gframe;
    int eor_ct;
    unsigned int pfm_cts;
    int evt_tmd;
    int evt_tim;
    int evt_tdg;
    int evt_fcd;
    unsigned int evt_fcdct;
    unsigned int fsize;
    unsigned int rdtsz;
    unsigned char* memp;
    unsigned char* mempb;
    unsigned char* endp;
    unsigned char* rdtp;
    unsigned char* plmdlp;
    unsigned char* lmmdlp;
    unsigned char* wrmdlp;
    unsigned char* wlmdlp;
    unsigned char* plmthp;
    unsigned char* plbmtp;
    unsigned char* plwmtp;
    unsigned char* plzmtp;
    unsigned char* plemtp;
    unsigned char* plexwp;
    unsigned char* plhdwp;
    unsigned char* pletcp;
    unsigned char* subtxp;
    unsigned char* doordp;
    unsigned char* sbs_sp;
    Unknown1* obwp;
    Unknown1* itwp;
    Unknown2* emtp[128];
    Unknown2* rmthp;
    unsigned char* mspp;
    unsigned char* lspp;
    unsigned int* mes_ip;
    unsigned int* mes_sp;
    void* mes_tp;
    short txr_n;
    short txr_ct;
    TextureList* txlp[256];
    unsigned char* txdp[256];
    short txloff[256];
    short txb_ct;
    short txb_n;
    short txb[256];
    TextureList* txblp[256];
    Unknown7 txbp[256];
    unsigned char* ef_psp;
    TextureFileLocation ef_tex[450];
    TextureList ef_tlist;
    Unknown8 ef;
    short efid[256];
    Unknown4 efm[450];
    int ef_ct;
    int ef_ctb;
    int ef_extn;
    int ef_tn[450];
    unsigned char ef_pbkb[450];
    int ef_pbnk;
    int ef_slow;
    int ef_ctrn;
    int yk_ct;
    int mg_ct;
    int bl_ct;
    int windr;
    float winds;
    int windrb;
    float windsb;
    unsigned int thunder;
    float gas_py;
    int en_objn;
    BH_PWORK* en_obj[16];
    int ef_poln;
    int ef_mdfn;
    int ef_linn;
    int ef_ntxn;
    int ef_trsn;
    int ef_pncn;
    int ef_opqn;
    int ef_thln;
    int ef_ntx2dn;
    int ef_trs2dn;
    int ef_pnc2dn;
    int ef_fncn;
    Unknown1* ef_pol[512];
    Unknown1* ef_mdf[128];
    Unknown1* ef_lin[512];
    Unknown1* ef_ntx[512];
    Unknown1* ef_trs[512];
    Unknown1* ef_pnc[512];
    Unknown1* ef_opq[512];
    Unknown1* ef_thl[512];
    Unknown1* ef_ntx2d[128];
    Unknown1* ef_trs2d[128];
    Unknown1* ef_pnc2d[128];
    Unknown1* ef_fnc[512];
    int ob_nlgn;
    int ob_hlgn;
    int ob_spcn;
    Unknown1* ob_nlg[32];
    Unknown1* ob_hlg[32];
    Unknown1* ob_spc[32];
    unsigned int ren_gid;
    TextureInfo ren_info;
    TextureFileLocation ren_tex[1];
    TextureList ren_tlist;
    Unknown9 rpb[256];
    int ren_n;
    int ren_idx[4];
    int wt_nbpt;
    float wt_px;
    float wt_pz;
    int wt_xp;
    int wt_zp;
    int wt_minx;
    int wt_minz;
    int wt_maxx;
    int wt_maxz;
    unsigned char* wt_wvp;
    PositionVelocity mr_pl;
    unsigned char* zan_memp;
    unsigned char* zanp;
    Unknown10* lgtp;
    float lg_vx;
    float lg_vy;
    float lg_vz;
    float lg_r;
    float lg_g;
    float lg_b;
    int lg_pnt;
    Unknown14 lg_ptb[4];
    int mes_idx;
    unsigned int* mes_dp;
    int mes_ct;
    int mes_tim;
    int mes_fls;
    int mes_sel;
    int mes_seln;
    Point mes_sps[16];
    int rt_sp;
    unsigned char* rt_wp;
    unsigned char* rt_dp;
    unsigned char* rt_nw;
    unsigned char* rt_nx;
    float* rt_ln;
    BH_PWORK* plp;
    Unknown15* pl_htp;
    int costume;
    Vector3 hd_pos;
    Vector3 apos;
    Unknown15* ahtp;
    int mwal_n;
    int metc_n;
    int mflr_n;
    Unknown15 mwalp[64];
    Unknown15 metcp[64];
    Unknown15 mflrp[64];
    int dla_n;
    Unknown15* htp;
    int psh_snd;
    int fog_cngct;
    unsigned int fog_col;
    float fog_nr;
    float fog_fr;
    float fade_ct;
    float fade_hkn;
    float fade_ao;
    float fade_an;
    float fade_ap;
    float fade_ro;
    float fade_rn;
    float fade_rp;
    float fade_go;
    float fade_gn;
    float fade_gp;
    float fade_bo;
    float fade_bn;
    float fade_bp;
    unsigned int fade_pbk;
    unsigned short ssv_md0;
    unsigned short ssv_md1;
    int ssv_tim;
    float ssv_ct;
    float ssv_hkn;
    float ssv_ao;
    float ssv_an;
    float ssv_ap;
    short fil_no;
    short fil_rt;
    float rvf_sc;
    float rvf_sn;
    unsigned int rvfc[4];
    float cine_an;
    float cine_ap;
    unsigned int sco_flg;
    float amb_r[4];
    float amb_g[4];
    float amb_b[4];
    int sb_id;
    int sb_cmd;
    int sb_rdid;
    int sb_rdsz;
    void* sb_rdp;
    void* sb_mlb;
    void* sb_ppp;
    TextureList* sb_tlist;
    int ddmd;
    Door door;
    int mpmd;
    int mp_prm[4];
    unsigned short gov_md0;
    unsigned short gov_md1;
    int gov_ct;
    void* gov_exp;
    unsigned int com_flg;
    unsigned short com_md0;
    unsigned short com_md1;
    unsigned int com_num;
    void* com_exp;
    short ond_tnm;
    short ond_ud;
    char ond_cx;
    char ond_n[3];
    unsigned char ufo_md;
    unsigned char ufo_flg;
    short ufo_oidx;
    Vector3 ufo_pos;
    unsigned int opt_flg;
    unsigned short opt_md0;
    unsigned short opt_md1;
    void* opt_exp;
    unsigned int etc_idx;
    unsigned int flr_idx;
    int mvi_no;
    int mvi_tp;
    unsigned short mvi_md;
    unsigned short mvi_flg;
    unsigned int mvi_tsb;
    unsigned int mvi_spb;
    unsigned char* mvi_memp;
    unsigned int dcg_tkbak;
    unsigned int dcg_tsbak;
    unsigned int pau_spbak;
    unsigned int pau_pad_on;
    unsigned int pau_pad_ps;
    unsigned int pau_pad_old;
    unsigned char* pdm_dp;
    unsigned char* pdm_pd;
    int pdm_keytpb;
    int gat_ct;
    Unknown16 gatc[16];
    int ght_ct;
    unsigned int ghtc[32];
    Vector3 ghtp[32];
    unsigned short db_md0;
    unsigned short db_md1;
    char db_stgno;
    char db_romno;
    char db_rcase;
    char db_muteki;
    short db_px;
    short db_py;
    int db_mes;
    int calc_v;
    unsigned int brkfg;
    char brkfg_typ[32];
    short brkfg_bit[32];
    unsigned int brkfg_tkb;
    unsigned int brkfg_tsb;
    int brkfg_ct;
    unsigned int bmt_size;
    unsigned int lmt_size;
    unsigned int emt_size;
    unsigned int wmt_size;
    char mes[256];
    float sfx;
    float sfy;
    float sfxn;
    float sfyn;
    float sfct;
}
System;

/* Dreamcast SDK types */

#define PDD_PLOGIC_ACTIVE 0

#define PDD_PLOGIC_NEGATIVE 1

typedef struct PDS_PERIPHERALINFO
{
	unsigned int type;
	unsigned int reserved[3];
	unsigned char is_root;
	unsigned char area_code;
	unsigned char connector_dir[2];
	char product_name[32];
	char license[64];
	unsigned short stdby_pow;
	unsigned short max_pow;
} PDS_PERIPHERALINFO;

typedef struct PDS_PERIPHERAL
{
	unsigned int id;
	unsigned int support;
	unsigned int on;
	unsigned int off;
	unsigned int press;
	unsigned int release;
	unsigned short r;
	unsigned short l;
	short x1;
	short y1;
	short x2;
	short y2;
	char* name;
	void* extend;
	unsigned int old;
	PDS_PERIPHERALINFO* info;
} PDS_PERIPHERAL; 

typedef struct NJS_POINT3
{
	float x;
	float y;
	float z;
} NJS_POINT3;

typedef struct NJS_SCRVECTOR
{
	float x;
	float y;
	float z;
	float iz;
	float fog;
} NJS_SCRVECTOR;

typedef struct NJS_SCREEN
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
} NJS_SCREEN;

typedef struct NJS_POLYGON_VTX
{
	float x;
	float y;
	float z;
	unsigned int col;
} NJS_POLYGON_VTX;

typedef struct NJS_QUAD_TEXTURE
{
	float x1;
	float y1;
	float x2;
	float y2;
	float u1;
	float v1;
	float u2;
	float v2;
} NJS_QUAD_TEXTURE;

typedef struct NJS_VIEW
{
	float m[16];
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
	int roll;
	float apx;
	float apy;
	float apz;
	float avx;
	float avy;
	float avz;
	int aroll;
} NJS_VIEW;