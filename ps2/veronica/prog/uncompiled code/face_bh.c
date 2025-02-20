typedef struct _anon0;
typedef struct cnkobj;
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
typedef struct npobj;
typedef struct _anon13;


typedef float type_0[3];
typedef int type_1[3];
typedef float type_2[3];
typedef unsigned char type_3[64];
typedef float type_4[16];
typedef char type_5[4];
typedef unsigned short type_6[2];
typedef unsigned int type_7[3];
typedef cnkobj type_8[9];
typedef cnkobj* type_9[9];
typedef float type_10[3];
typedef float type_11[3][9];
typedef int type_12[3];
typedef int type_13[3][9];
typedef unsigned int type_14[4];
typedef unsigned int type_15[3];
typedef float type_16[16][9];
typedef unsigned char type_17[64];
typedef unsigned char type_18[64];
typedef char type_19[9];
typedef unsigned int type_20[2];
typedef float type_21[3];
typedef int type_22[3];
typedef float type_23[3];
typedef int type_24[3];
typedef float type_25[3];
typedef float type_26[3];
typedef float type_27[32];
typedef int type_28[3];
typedef float type_29[4];
typedef npobj* type_30[256];
typedef cnkobj* type_31[256];
typedef cnkobj* type_32[256];
typedef _anon0* type_33[32];
typedef float type_34[32];

struct _anon0
{
	float x;
	float y;
	float z;
};

struct cnkobj
{
	unsigned int evalflags;
	_anon1* model;
	float pos[3];
	int ang[3];
	float scl[3];
	cnkobj* child;
	cnkobj* sibling;
};

struct _anon1
{
	int* vlist;
	short* plist;
	_anon0 center;
	float r;
};

struct _anon2
{
	_anon1* src;
	_anon1* dst;
	_anon7* list;
	_anon6* vlist;
	_anon0** nvpt;
	int lnum;
	cnkobj* obj;
	_anon3* jaw;
	int jnum;
	unsigned int Dummy[3];
	float jmat1[16];
	float jmat2[16];
	_anon4 param;
	cnkobj eye[9];
	cnkobj* eyesrc[9];
	float eyepos[3][9];
	int eyeang[3][9];
	unsigned int Dummy2[3];
	float eyemat[16][9];
	_anon3* tang;
	int tnum;
	_anon1* tangsrc;
	_anon1* tangdst;
	cnkobj tangobj;
	cnkobj* tangorg;
	float tangpos[3];
	int tangang[3];
	cnkobj tooth;
	cnkobj* toothsrc;
	float toothpos[3];
	int toothang[3];
	unsigned int mode;
	_anon4* face;
	int fnum;
	int vtype;
	int vtop;
	int ntop;
	int vofs;
	_anon8* head;
};

struct _anon3
{
	int id;
	float rate;
};

struct _anon4
{
	float muscle[32];
	float jawang;
	float jawtrans;
	_anon0 eye;
	float tangx;
	float tangy;
	float tangz;
	short frame;
	short flag;
};

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon11* texP;
	_anon12* owP;
};

struct _anon6
{
	short id;
	char mnum;
	char nvnum;
};

struct _anon7
{
	int id;
	_anon0 vec;
	float scal;
};

struct _anon8
{
	char id[4];
	unsigned short version;
	unsigned short flag;
	unsigned short jawId[2];
	unsigned int nAttr;
	unsigned int nList;
	unsigned int nConnect;
	unsigned int nJaw;
	unsigned int nTang;
	unsigned int nFace;
	unsigned int reserve[4];
	char faceId;
	char tangId;
	char toothId;
	char eyeId[9];
};

struct _anon9
{
	unsigned char* top;
	unsigned char* ptr;
	short cnt;
	short time;
	unsigned char cur;
	unsigned char next;
	unsigned short flag;
};

struct _anon10
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon11
{
	_anon10* textures;
	unsigned int nbTexture;
};

struct _anon12
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct npobj
{
	unsigned int evalflags;
	_anon1* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon13
{
	float x;
	float y;
	float z;
	float w;
};


void fmSetLipSyncParam(_anon2* fm, _anon4* base, _anon9* lip, unsigned int mask);
void _fmSetObjP(_anon5* mlwP);
cnkobj* _fmCnkSearchObject(_anon2* fm, cnkobj* root, char id);
void _fmGetVChunkType(_anon2* fm);
void _fmCnkSetFaceObject(_anon2* fm, cnkobj* face);
void _fmCnkSetEyeballObject(_anon2* fm, unsigned int id, cnkobj* eye, cnkobj* root);
void _fmCnkSetTangObject(_anon2* fm, cnkobj* tang);
void _fmCnkSetToothObject(_anon2* fm, cnkobj* tooth);
void _fmCnkSetJaw(_anon2* fm, unsigned int v0, unsigned int v1);
void fmCnkInitContext(_anon2* fm, void* data, cnkobj* root, _anon5* mlwP);
void fmCnkSetParam(_anon2* fm, _anon4* param);
void fmCnkSetParamLip(_anon2* fm, _anon4* param, unsigned int flag);
void fmCnkSetInterParam(_anon2* fm, _anon4* p1, _anon4* p2, float t, float lv, unsigned int mask);
void fmCnkSetInterParamLip(_anon2* fm, _anon4* p1, _anon4* p2, float t, float lv, unsigned int mask);
void fmCnkSetCurrentFrame(_anon2* fm, float frame);
unsigned int fmCnkGetLastFrame(_anon2* fm);
void _fmCnkCalcMuscle(_anon2* fm);
void _fmCnkCalcJaw(_anon2* fm);
void _fmCnkCalcEye(_anon2* fm);
void _fmCnkCalcTang(_anon2* fm);
void _fmCnkCalcNormal(_anon2* fm);
void fmCnkCalcFace(_anon2* fm);
void fmCnkSetMode(_anon2* fm, unsigned int mode);

// 
// Start address: 0x298820
void fmSetLipSyncParam(_anon2* fm, _anon4* base, _anon9* lip, unsigned int mask)
{
	float level;
	float rate;
	// Line 57, Address: 0x298820, Func Offset: 0
	// Line 60, Address: 0x29882c, Func Offset: 0xc
	// Line 61, Address: 0x298840, Func Offset: 0x20
	// Line 62, Address: 0x298848, Func Offset: 0x28
	// Line 63, Address: 0x29885c, Func Offset: 0x3c
	// Line 65, Address: 0x298860, Func Offset: 0x40
	// Line 67, Address: 0x298868, Func Offset: 0x48
	// Line 68, Address: 0x298878, Func Offset: 0x58
	// Line 69, Address: 0x29888c, Func Offset: 0x6c
	// Line 71, Address: 0x29889c, Func Offset: 0x7c
	// Line 73, Address: 0x2988a4, Func Offset: 0x84
	// Line 77, Address: 0x2988a8, Func Offset: 0x88
	// Line 78, Address: 0x2988cc, Func Offset: 0xac
	// Line 79, Address: 0x2988d8, Func Offset: 0xb8
	// Line 80, Address: 0x2988e8, Func Offset: 0xc8
	// Line 79, Address: 0x2988ec, Func Offset: 0xcc
	// Line 80, Address: 0x2988f8, Func Offset: 0xd8
	// Line 81, Address: 0x29890c, Func Offset: 0xec
	// Line 83, Address: 0x298914, Func Offset: 0xf4
	// Line 84, Address: 0x298928, Func Offset: 0x108
	// Line 83, Address: 0x29892c, Func Offset: 0x10c
	// Line 84, Address: 0x298930, Func Offset: 0x110
	// Line 83, Address: 0x298934, Func Offset: 0x114
	// Line 86, Address: 0x298938, Func Offset: 0x118
	// Line 87, Address: 0x298978, Func Offset: 0x158
	// Line 89, Address: 0x298980, Func Offset: 0x160
	// Line 93, Address: 0x2989a4, Func Offset: 0x184
	// Line 94, Address: 0x2989b0, Func Offset: 0x190
	// Line 96, Address: 0x2989bc, Func Offset: 0x19c
	// Func End, Address: 0x2989cc, Func Offset: 0x1ac
}

// 
// Start address: 0x2989d0
void _fmSetObjP(_anon5* mlwP)
{
	int sp;
	npobj* stack[256];
	npobj* obj2;
	npobj* obj;
	// Line 133, Address: 0x2989d0, Func Offset: 0
	// Line 139, Address: 0x2989e4, Func Offset: 0x14
	// Line 138, Address: 0x2989e8, Func Offset: 0x18
	// Line 139, Address: 0x2989f0, Func Offset: 0x20
	// Line 140, Address: 0x298a10, Func Offset: 0x40
	// Line 139, Address: 0x298a14, Func Offset: 0x44
	// Line 140, Address: 0x298a18, Func Offset: 0x48
	// Line 143, Address: 0x298a30, Func Offset: 0x60
	// Line 144, Address: 0x298a38, Func Offset: 0x68
	// Line 146, Address: 0x298a48, Func Offset: 0x78
	// Line 147, Address: 0x298a54, Func Offset: 0x84
	// Line 148, Address: 0x298a64, Func Offset: 0x94
	// Line 149, Address: 0x298a68, Func Offset: 0x98
	// Line 151, Address: 0x298a74, Func Offset: 0xa4
	// Line 152, Address: 0x298a7c, Func Offset: 0xac
	// Line 153, Address: 0x298a84, Func Offset: 0xb4
	// Line 154, Address: 0x298a90, Func Offset: 0xc0
	// Line 156, Address: 0x298a98, Func Offset: 0xc8
	// Line 157, Address: 0x298a9c, Func Offset: 0xcc
	// Line 158, Address: 0x298aa0, Func Offset: 0xd0
	// Line 159, Address: 0x298aa8, Func Offset: 0xd8
	// Func End, Address: 0x298ac0, Func Offset: 0xf0
}

// 
// Start address: 0x298ac0
cnkobj* _fmCnkSearchObject(_anon2* fm, cnkobj* root, char id)
{
	int dummy;
	int i;
	int n;
	int sp;
	cnkobj* stack[256];
	cnkobj* obj;
	// Line 218, Address: 0x298ac0, Func Offset: 0
	// Line 221, Address: 0x298adc, Func Offset: 0x1c
	// Line 223, Address: 0x298ae0, Func Offset: 0x20
	// Line 224, Address: 0x298ae8, Func Offset: 0x28
	// Line 225, Address: 0x298af4, Func Offset: 0x34
	// Line 227, Address: 0x298b00, Func Offset: 0x40
	// Line 228, Address: 0x298b0c, Func Offset: 0x4c
	// Line 229, Address: 0x298b1c, Func Offset: 0x5c
	// Line 231, Address: 0x298b20, Func Offset: 0x60
	// Line 232, Address: 0x298b2c, Func Offset: 0x6c
	// Line 234, Address: 0x298b30, Func Offset: 0x70
	// Line 235, Address: 0x298b3c, Func Offset: 0x7c
	// Line 237, Address: 0x298b40, Func Offset: 0x80
	// Line 238, Address: 0x298b48, Func Offset: 0x88
	// Line 239, Address: 0x298b54, Func Offset: 0x94
	// Line 241, Address: 0x298b58, Func Offset: 0x98
	// Line 242, Address: 0x298b68, Func Offset: 0xa8
	// Line 244, Address: 0x298b7c, Func Offset: 0xbc
	// Line 245, Address: 0x298b84, Func Offset: 0xc4
	// Line 246, Address: 0x298b8c, Func Offset: 0xcc
	// Line 247, Address: 0x298b98, Func Offset: 0xd8
	// Line 249, Address: 0x298ba0, Func Offset: 0xe0
	// Line 250, Address: 0x298ba4, Func Offset: 0xe4
	// Line 251, Address: 0x298ba8, Func Offset: 0xe8
	// Line 252, Address: 0x298bb0, Func Offset: 0xf0
	// Line 253, Address: 0x298bb4, Func Offset: 0xf4
	// Func End, Address: 0x298bbc, Func Offset: 0xfc
}

// 
// Start address: 0x298bc0
void _fmGetVChunkType(_anon2* fm)
{
	// Line 339, Address: 0x298bc0, Func Offset: 0
	// Line 344, Address: 0x298bd0, Func Offset: 0x10
	// Line 346, Address: 0x298c00, Func Offset: 0x40
	// Line 347, Address: 0x298c08, Func Offset: 0x48
	// Line 348, Address: 0x298c10, Func Offset: 0x50
	// Line 349, Address: 0x298c14, Func Offset: 0x54
	// Line 351, Address: 0x298c1c, Func Offset: 0x5c
	// Line 352, Address: 0x298c24, Func Offset: 0x64
	// Line 353, Address: 0x298c28, Func Offset: 0x68
	// Line 354, Address: 0x298c30, Func Offset: 0x70
	// Line 355, Address: 0x298c38, Func Offset: 0x78
	// Line 363, Address: 0x298c40, Func Offset: 0x80
	// Line 364, Address: 0x298c48, Func Offset: 0x88
	// Line 365, Address: 0x298c4c, Func Offset: 0x8c
	// Line 366, Address: 0x298c54, Func Offset: 0x94
	// Line 367, Address: 0x298c5c, Func Offset: 0x9c
	// Line 369, Address: 0x298c64, Func Offset: 0xa4
	// Line 370, Address: 0x298c6c, Func Offset: 0xac
	// Line 371, Address: 0x298c74, Func Offset: 0xb4
	// Line 372, Address: 0x298c78, Func Offset: 0xb8
	// Line 379, Address: 0x298c80, Func Offset: 0xc0
	// Line 380, Address: 0x298c88, Func Offset: 0xc8
	// Line 381, Address: 0x298c90, Func Offset: 0xd0
	// Line 382, Address: 0x298c94, Func Offset: 0xd4
	// Line 384, Address: 0x298c9c, Func Offset: 0xdc
	// Line 385, Address: 0x298ca4, Func Offset: 0xe4
	// Line 386, Address: 0x298cac, Func Offset: 0xec
	// Line 387, Address: 0x298cb4, Func Offset: 0xf4
	// Line 388, Address: 0x298cbc, Func Offset: 0xfc
	// Line 391, Address: 0x298cc4, Func Offset: 0x104
	// Line 392, Address: 0x298ccc, Func Offset: 0x10c
	// Line 393, Address: 0x298cd4, Func Offset: 0x114
	// Line 394, Address: 0x298cd8, Func Offset: 0x118
	// Line 395, Address: 0x298ce0, Func Offset: 0x120
	// Line 397, Address: 0x298ce8, Func Offset: 0x128
	// Line 398, Address: 0x298cf0, Func Offset: 0x130
	// Line 399, Address: 0x298cf8, Func Offset: 0x138
	// Line 400, Address: 0x298d00, Func Offset: 0x140
	// Line 401, Address: 0x298d08, Func Offset: 0x148
	// Line 403, Address: 0x298d10, Func Offset: 0x150
	// Line 404, Address: 0x298d18, Func Offset: 0x158
	// Line 405, Address: 0x298d1c, Func Offset: 0x15c
	// Line 406, Address: 0x298d20, Func Offset: 0x160
	// Line 409, Address: 0x298d2c, Func Offset: 0x16c
	// Func End, Address: 0x298d34, Func Offset: 0x174
}

// 
// Start address: 0x298d40
void _fmCnkSetFaceObject(_anon2* fm, cnkobj* face)
{
	// Line 441, Address: 0x298d40, Func Offset: 0
	// Line 442, Address: 0x298d54, Func Offset: 0x14
	// Line 445, Address: 0x298d5c, Func Offset: 0x1c
	// Line 446, Address: 0x298d60, Func Offset: 0x20
	// Line 447, Address: 0x298d64, Func Offset: 0x24
	// Line 448, Address: 0x298d78, Func Offset: 0x38
	// Line 449, Address: 0x298d88, Func Offset: 0x48
	// Line 452, Address: 0x298d8c, Func Offset: 0x4c
	// Line 453, Address: 0x298d98, Func Offset: 0x58
	// Line 454, Address: 0x298dc8, Func Offset: 0x88
	// Line 455, Address: 0x298df4, Func Offset: 0xb4
	// Func End, Address: 0x298e08, Func Offset: 0xc8
}

// 
// Start address: 0x298e10
void _fmCnkSetEyeballObject(_anon2* fm, unsigned int id, cnkobj* eye, cnkobj* root)
{
	int sp;
	cnkobj* stack[256];
	cnkobj* obj;
	int i;
	// Line 529, Address: 0x298e10, Func Offset: 0
	// Line 535, Address: 0x298e38, Func Offset: 0x28
	// Line 538, Address: 0x298e5c, Func Offset: 0x4c
	// Line 539, Address: 0x298e84, Func Offset: 0x74
	// Line 540, Address: 0x298e8c, Func Offset: 0x7c
	// Line 542, Address: 0x298e90, Func Offset: 0x80
	// Line 545, Address: 0x298e9c, Func Offset: 0x8c
	// Line 540, Address: 0x298ea0, Func Offset: 0x90
	// Line 541, Address: 0x298ea4, Func Offset: 0x94
	// Line 542, Address: 0x298ea8, Func Offset: 0x98
	// Line 543, Address: 0x298eb0, Func Offset: 0xa0
	// Line 544, Address: 0x298eb4, Func Offset: 0xa4
	// Line 542, Address: 0x298eb8, Func Offset: 0xa8
	// Line 545, Address: 0x298ec0, Func Offset: 0xb0
	// Line 543, Address: 0x298ec4, Func Offset: 0xb4
	// Line 545, Address: 0x298ec8, Func Offset: 0xb8
	// Line 543, Address: 0x298ed0, Func Offset: 0xc0
	// Line 544, Address: 0x298ed8, Func Offset: 0xc8
	// Line 549, Address: 0x298ee4, Func Offset: 0xd4
	// Line 546, Address: 0x298ee8, Func Offset: 0xd8
	// Line 551, Address: 0x298eec, Func Offset: 0xdc
	// Line 546, Address: 0x298ef4, Func Offset: 0xe4
	// Line 547, Address: 0x298ef8, Func Offset: 0xe8
	// Line 548, Address: 0x298f00, Func Offset: 0xf0
	// Line 549, Address: 0x298f04, Func Offset: 0xf4
	// Line 550, Address: 0x298f08, Func Offset: 0xf8
	// Line 551, Address: 0x298f14, Func Offset: 0x104
	// Line 552, Address: 0x298f1c, Func Offset: 0x10c
	// Line 555, Address: 0x298f28, Func Offset: 0x118
	// Line 556, Address: 0x298f30, Func Offset: 0x120
	// Line 558, Address: 0x298f38, Func Offset: 0x128
	// Line 560, Address: 0x298f40, Func Offset: 0x130
	// Line 561, Address: 0x298f4c, Func Offset: 0x13c
	// Line 562, Address: 0x298f54, Func Offset: 0x144
	// Line 564, Address: 0x298f68, Func Offset: 0x158
	// Line 565, Address: 0x298f7c, Func Offset: 0x16c
	// Line 566, Address: 0x298f90, Func Offset: 0x180
	// Line 567, Address: 0x298fa4, Func Offset: 0x194
	// Line 568, Address: 0x298fb0, Func Offset: 0x1a0
	// Line 569, Address: 0x298fbc, Func Offset: 0x1ac
	// Line 571, Address: 0x298fc4, Func Offset: 0x1b4
	// Line 573, Address: 0x298fd0, Func Offset: 0x1c0
	// Line 574, Address: 0x298fd8, Func Offset: 0x1c8
	// Line 575, Address: 0x298fe0, Func Offset: 0x1d0
	// Line 576, Address: 0x298fe8, Func Offset: 0x1d8
	// Line 577, Address: 0x298ff4, Func Offset: 0x1e4
	// Line 582, Address: 0x298ffc, Func Offset: 0x1ec
	// Line 583, Address: 0x299008, Func Offset: 0x1f8
	// Func End, Address: 0x299030, Func Offset: 0x220
}

// 
// Start address: 0x299030
void _fmCnkSetTangObject(_anon2* fm, cnkobj* tang)
{
	<unknown fundamental type (0xa510)>* dst_128;
	<unknown fundamental type (0xa510)>* src_128;
	int i;
	// Line 631, Address: 0x299030, Func Offset: 0
	// Line 635, Address: 0x299044, Func Offset: 0x14
	// Line 638, Address: 0x29904c, Func Offset: 0x1c
	// Line 639, Address: 0x299050, Func Offset: 0x20
	// Line 640, Address: 0x299064, Func Offset: 0x34
	// Line 641, Address: 0x299074, Func Offset: 0x44
	// Line 644, Address: 0x299078, Func Offset: 0x48
	// Line 641, Address: 0x29907c, Func Offset: 0x4c
	// Line 644, Address: 0x299080, Func Offset: 0x50
	// Line 646, Address: 0x2990ac, Func Offset: 0x7c
	// Line 647, Address: 0x2990b0, Func Offset: 0x80
	// Line 648, Address: 0x2990b4, Func Offset: 0x84
	// Line 646, Address: 0x2990b8, Func Offset: 0x88
	// Line 647, Address: 0x2990bc, Func Offset: 0x8c
	// Line 648, Address: 0x2990c0, Func Offset: 0x90
	// Line 649, Address: 0x2990e0, Func Offset: 0xb0
	// Line 650, Address: 0x2990e4, Func Offset: 0xb4
	// Line 649, Address: 0x2990e8, Func Offset: 0xb8
	// Line 650, Address: 0x2990f4, Func Offset: 0xc4
	// Line 653, Address: 0x299100, Func Offset: 0xd0
	// Line 654, Address: 0x299110, Func Offset: 0xe0
	// Line 655, Address: 0x299114, Func Offset: 0xe4
	// Line 657, Address: 0x299118, Func Offset: 0xe8
	// Line 656, Address: 0x299120, Func Offset: 0xf0
	// Line 658, Address: 0x299124, Func Offset: 0xf4
	// Line 655, Address: 0x299128, Func Offset: 0xf8
	// Line 656, Address: 0x29912c, Func Offset: 0xfc
	// Line 657, Address: 0x299130, Func Offset: 0x100
	// Line 659, Address: 0x299134, Func Offset: 0x104
	// Line 660, Address: 0x299138, Func Offset: 0x108
	// Line 657, Address: 0x299144, Func Offset: 0x114
	// Line 658, Address: 0x29914c, Func Offset: 0x11c
	// Line 659, Address: 0x299158, Func Offset: 0x128
	// Line 664, Address: 0x299164, Func Offset: 0x134
	// Line 661, Address: 0x299168, Func Offset: 0x138
	// Line 666, Address: 0x29916c, Func Offset: 0x13c
	// Line 661, Address: 0x299174, Func Offset: 0x144
	// Line 662, Address: 0x299178, Func Offset: 0x148
	// Line 663, Address: 0x299180, Func Offset: 0x150
	// Line 664, Address: 0x299184, Func Offset: 0x154
	// Line 665, Address: 0x299188, Func Offset: 0x158
	// Line 666, Address: 0x299190, Func Offset: 0x160
	// Line 667, Address: 0x299198, Func Offset: 0x168
	// Line 668, Address: 0x29919c, Func Offset: 0x16c
	// Func End, Address: 0x2991b0, Func Offset: 0x180
}

// 
// Start address: 0x2991b0
void _fmCnkSetToothObject(_anon2* fm, cnkobj* tooth)
{
	int i;
	// Line 707, Address: 0x2991b0, Func Offset: 0
	// Line 710, Address: 0x2991c4, Func Offset: 0x14
	// Line 713, Address: 0x2991cc, Func Offset: 0x1c
	// Line 714, Address: 0x2991d8, Func Offset: 0x28
	// Line 715, Address: 0x2991dc, Func Offset: 0x2c
	// Line 717, Address: 0x2991e0, Func Offset: 0x30
	// Line 716, Address: 0x2991e8, Func Offset: 0x38
	// Line 718, Address: 0x2991ec, Func Offset: 0x3c
	// Line 715, Address: 0x2991f0, Func Offset: 0x40
	// Line 716, Address: 0x2991f4, Func Offset: 0x44
	// Line 717, Address: 0x2991f8, Func Offset: 0x48
	// Line 719, Address: 0x2991fc, Func Offset: 0x4c
	// Line 720, Address: 0x299200, Func Offset: 0x50
	// Line 717, Address: 0x29920c, Func Offset: 0x5c
	// Line 718, Address: 0x299214, Func Offset: 0x64
	// Line 719, Address: 0x299220, Func Offset: 0x70
	// Line 724, Address: 0x29922c, Func Offset: 0x7c
	// Line 721, Address: 0x299230, Func Offset: 0x80
	// Line 726, Address: 0x299234, Func Offset: 0x84
	// Line 721, Address: 0x29923c, Func Offset: 0x8c
	// Line 722, Address: 0x299240, Func Offset: 0x90
	// Line 723, Address: 0x299248, Func Offset: 0x98
	// Line 724, Address: 0x29924c, Func Offset: 0x9c
	// Line 725, Address: 0x299250, Func Offset: 0xa0
	// Line 726, Address: 0x299258, Func Offset: 0xa8
	// Line 727, Address: 0x299260, Func Offset: 0xb0
	// Line 728, Address: 0x299264, Func Offset: 0xb4
	// Func End, Address: 0x299278, Func Offset: 0xc8
}

// 
// Start address: 0x299280
void _fmCnkSetJaw(_anon2* fm, unsigned int v0, unsigned int v1)
{
	float svp0[4];
	unsigned int vofs;
	int rz;
	int ry;
	float z;
	float y;
	float x;
	float* svp;
	// Line 797, Address: 0x299280, Func Offset: 0
	// Line 804, Address: 0x2992a8, Func Offset: 0x28
	// Line 806, Address: 0x2992ac, Func Offset: 0x2c
	// Line 807, Address: 0x2992b4, Func Offset: 0x34
	// Line 812, Address: 0x2992b8, Func Offset: 0x38
	// Line 811, Address: 0x2992bc, Func Offset: 0x3c
	// Line 806, Address: 0x2992c0, Func Offset: 0x40
	// Line 813, Address: 0x2992c8, Func Offset: 0x48
	// Line 806, Address: 0x2992cc, Func Offset: 0x4c
	// Line 807, Address: 0x2992d0, Func Offset: 0x50
	// Line 811, Address: 0x2992d4, Func Offset: 0x54
	// Line 806, Address: 0x2992d8, Func Offset: 0x58
	// Line 807, Address: 0x2992dc, Func Offset: 0x5c
	// Line 811, Address: 0x2992e8, Func Offset: 0x68
	// Line 807, Address: 0x2992ec, Func Offset: 0x6c
	// Line 811, Address: 0x2992f0, Func Offset: 0x70
	// Line 812, Address: 0x2992f8, Func Offset: 0x78
	// Line 813, Address: 0x299300, Func Offset: 0x80
	// Line 811, Address: 0x299308, Func Offset: 0x88
	// Line 812, Address: 0x29930c, Func Offset: 0x8c
	// Line 814, Address: 0x299310, Func Offset: 0x90
	// Line 813, Address: 0x299314, Func Offset: 0x94
	// Line 814, Address: 0x299318, Func Offset: 0x98
	// Line 816, Address: 0x29933c, Func Offset: 0xbc
	// Line 821, Address: 0x299368, Func Offset: 0xe8
	// Line 823, Address: 0x299370, Func Offset: 0xf0
	// Line 824, Address: 0x299378, Func Offset: 0xf8
	// Line 825, Address: 0x299384, Func Offset: 0x104
	// Line 826, Address: 0x299390, Func Offset: 0x110
	// Line 829, Address: 0x2993b0, Func Offset: 0x130
	// Line 830, Address: 0x2993b8, Func Offset: 0x138
	// Line 831, Address: 0x2993cc, Func Offset: 0x14c
	// Line 832, Address: 0x2993d8, Func Offset: 0x158
	// Line 834, Address: 0x2993e4, Func Offset: 0x164
	// Line 837, Address: 0x2993ec, Func Offset: 0x16c
	// Line 844, Address: 0x2993f8, Func Offset: 0x178
	// Line 845, Address: 0x2993fc, Func Offset: 0x17c
	// Line 849, Address: 0x299404, Func Offset: 0x184
	// Line 856, Address: 0x299410, Func Offset: 0x190
	// Line 857, Address: 0x299414, Func Offset: 0x194
	// Line 859, Address: 0x29941c, Func Offset: 0x19c
	// Func End, Address: 0x299448, Func Offset: 0x1c8
}

// 
// Start address: 0x299450
void fmCnkInitContext(_anon2* fm, void* data, cnkobj* root, _anon5* mlwP)
{
	unsigned int vofs;
	cnkobj* obj;
	int j;
	int i;
	int* dvp;
	unsigned int* nlist;
	_anon6* vlist;
	// Line 937, Address: 0x299450, Func Offset: 0
	// Line 945, Address: 0x299470, Func Offset: 0x20
	// Line 947, Address: 0x299484, Func Offset: 0x34
	// Line 949, Address: 0x299488, Func Offset: 0x38
	// Line 950, Address: 0x2994a8, Func Offset: 0x58
	// Line 951, Address: 0x2994bc, Func Offset: 0x6c
	// Line 952, Address: 0x2994c4, Func Offset: 0x74
	// Line 953, Address: 0x2994d0, Func Offset: 0x80
	// Line 955, Address: 0x2994dc, Func Offset: 0x8c
	// Line 956, Address: 0x2994f0, Func Offset: 0xa0
	// Line 957, Address: 0x2994f8, Func Offset: 0xa8
	// Line 958, Address: 0x299504, Func Offset: 0xb4
	// Line 961, Address: 0x299510, Func Offset: 0xc0
	// Line 962, Address: 0x299514, Func Offset: 0xc4
	// Line 963, Address: 0x29952c, Func Offset: 0xdc
	// Line 964, Address: 0x299534, Func Offset: 0xe4
	// Line 965, Address: 0x299548, Func Offset: 0xf8
	// Line 966, Address: 0x299554, Func Offset: 0x104
	// Line 967, Address: 0x299558, Func Offset: 0x108
	// Line 970, Address: 0x299568, Func Offset: 0x118
	// Line 975, Address: 0x29956c, Func Offset: 0x11c
	// Line 970, Address: 0x299570, Func Offset: 0x120
	// Line 971, Address: 0x299578, Func Offset: 0x128
	// Line 974, Address: 0x299590, Func Offset: 0x140
	// Line 972, Address: 0x299598, Func Offset: 0x148
	// Line 973, Address: 0x29959c, Func Offset: 0x14c
	// Line 976, Address: 0x2995a0, Func Offset: 0x150
	// Line 974, Address: 0x2995a4, Func Offset: 0x154
	// Line 977, Address: 0x2995ac, Func Offset: 0x15c
	// Line 979, Address: 0x2995b4, Func Offset: 0x164
	// Line 980, Address: 0x2995bc, Func Offset: 0x16c
	// Line 981, Address: 0x2995d0, Func Offset: 0x180
	// Line 982, Address: 0x2995d4, Func Offset: 0x184
	// Line 986, Address: 0x2995ec, Func Offset: 0x19c
	// Line 987, Address: 0x2995f0, Func Offset: 0x1a0
	// Line 988, Address: 0x299608, Func Offset: 0x1b8
	// Line 989, Address: 0x29960c, Func Offset: 0x1bc
	// Line 990, Address: 0x29962c, Func Offset: 0x1dc
	// Line 992, Address: 0x299644, Func Offset: 0x1f4
	// Line 993, Address: 0x29965c, Func Offset: 0x20c
	// Line 994, Address: 0x299668, Func Offset: 0x218
	// Line 995, Address: 0x299674, Func Offset: 0x224
	// Line 996, Address: 0x299680, Func Offset: 0x230
	// Line 997, Address: 0x29968c, Func Offset: 0x23c
	// Line 999, Address: 0x2996a0, Func Offset: 0x250
	// Line 1000, Address: 0x2996a8, Func Offset: 0x258
	// Func End, Address: 0x2996c4, Func Offset: 0x274
}

// 
// Start address: 0x2996d0
void fmCnkSetParam(_anon2* fm, _anon4* param)
{
	// Line 1127, Address: 0x2996d0, Func Offset: 0
	// Func End, Address: 0x2996dc, Func Offset: 0xc
}

// 
// Start address: 0x2996e0
void fmCnkSetParamLip(_anon2* fm, _anon4* param, unsigned int flag)
{
	int i;
	// Line 1158, Address: 0x2996e0, Func Offset: 0
	// Line 1159, Address: 0x2996ec, Func Offset: 0xc
	// Line 1160, Address: 0x299700, Func Offset: 0x20
	// Line 1162, Address: 0x299708, Func Offset: 0x28
	// Line 1160, Address: 0x299710, Func Offset: 0x30
	// Line 1162, Address: 0x299714, Func Offset: 0x34
	// Line 1163, Address: 0x29971c, Func Offset: 0x3c
	// Line 1164, Address: 0x299738, Func Offset: 0x58
	// Line 1165, Address: 0x299740, Func Offset: 0x60
	// Line 1166, Address: 0x299750, Func Offset: 0x70
	// Line 1167, Address: 0x299760, Func Offset: 0x80
	// Line 1168, Address: 0x299764, Func Offset: 0x84
	// Func End, Address: 0x29976c, Func Offset: 0x8c
}

// 
// Start address: 0x299770
void fmCnkSetInterParam(_anon2* fm, _anon4* p1, _anon4* p2, float t, float lv, unsigned int mask)
{
	float rate;
	int i;
	// Line 1250, Address: 0x299770, Func Offset: 0
	// Line 1255, Address: 0x299790, Func Offset: 0x20
	// Line 1261, Address: 0x2997dc, Func Offset: 0x6c
	// Line 1263, Address: 0x2997e4, Func Offset: 0x74
	// Line 1264, Address: 0x2997ec, Func Offset: 0x7c
	// Line 1267, Address: 0x2997f4, Func Offset: 0x84
	// Line 1268, Address: 0x299818, Func Offset: 0xa8
	// Line 1270, Address: 0x299820, Func Offset: 0xb0
	// Line 1277, Address: 0x299824, Func Offset: 0xb4
	// Line 1278, Address: 0x299834, Func Offset: 0xc4
	// Line 1280, Address: 0x299848, Func Offset: 0xd8
	// Line 1281, Address: 0x299864, Func Offset: 0xf4
	// Line 1282, Address: 0x299868, Func Offset: 0xf8
	// Line 1280, Address: 0x299870, Func Offset: 0x100
	// Line 1282, Address: 0x299878, Func Offset: 0x108
	// Line 1285, Address: 0x299880, Func Offset: 0x110
	// Line 1286, Address: 0x29989c, Func Offset: 0x12c
	// Line 1288, Address: 0x2998b8, Func Offset: 0x148
	// Line 1289, Address: 0x2998d0, Func Offset: 0x160
	// Line 1290, Address: 0x2998e8, Func Offset: 0x178
	// Line 1294, Address: 0x299900, Func Offset: 0x190
	// Line 1295, Address: 0x29991c, Func Offset: 0x1ac
	// Line 1296, Address: 0x299938, Func Offset: 0x1c8
	// Line 1297, Address: 0x299954, Func Offset: 0x1e4
	// Func End, Address: 0x299974, Func Offset: 0x204
}

// 
// Start address: 0x299980
void fmCnkSetInterParamLip(_anon2* fm, _anon4* p1, _anon4* p2, float t, float lv, unsigned int mask)
{
	float* fm_muscle;
	float rate;
	int i;
	// Line 1313, Address: 0x299980, Func Offset: 0
	// Line 1321, Address: 0x2999a0, Func Offset: 0x20
	// Line 1327, Address: 0x2999ec, Func Offset: 0x6c
	// Line 1329, Address: 0x2999f4, Func Offset: 0x74
	// Line 1330, Address: 0x2999fc, Func Offset: 0x7c
	// Line 1333, Address: 0x299a04, Func Offset: 0x84
	// Line 1334, Address: 0x299a28, Func Offset: 0xa8
	// Line 1336, Address: 0x299a30, Func Offset: 0xb0
	// Line 1345, Address: 0x299a34, Func Offset: 0xb4
	// Line 1346, Address: 0x299a38, Func Offset: 0xb8
	// Line 1347, Address: 0x299a44, Func Offset: 0xc4
	// Line 1349, Address: 0x299a58, Func Offset: 0xd8
	// Line 1350, Address: 0x299a74, Func Offset: 0xf4
	// Line 1351, Address: 0x299a78, Func Offset: 0xf8
	// Line 1349, Address: 0x299a80, Func Offset: 0x100
	// Line 1351, Address: 0x299a88, Func Offset: 0x108
	// Line 1360, Address: 0x299a90, Func Offset: 0x110
	// Line 1361, Address: 0x299acc, Func Offset: 0x14c
	// Line 1362, Address: 0x299ae8, Func Offset: 0x168
	// Line 1363, Address: 0x299b1c, Func Offset: 0x19c
	// Line 1364, Address: 0x299b50, Func Offset: 0x1d0
	// Line 1365, Address: 0x299b6c, Func Offset: 0x1ec
	// Func End, Address: 0x299b8c, Func Offset: 0x20c
}

// 
// Start address: 0x299b90
void fmCnkSetCurrentFrame(_anon2* fm, float frame)
{
	unsigned int key;
	int i;
	// Line 1376, Address: 0x299b90, Func Offset: 0
	// Line 1381, Address: 0x299bb0, Func Offset: 0x20
	// Line 1382, Address: 0x299bc8, Func Offset: 0x38
	// Line 1385, Address: 0x299bec, Func Offset: 0x5c
	// Line 1390, Address: 0x299c00, Func Offset: 0x70
	// Line 1391, Address: 0x299c08, Func Offset: 0x78
	// Line 1392, Address: 0x299c14, Func Offset: 0x84
	// Line 1393, Address: 0x299c1c, Func Offset: 0x8c
	// Line 1394, Address: 0x299c24, Func Offset: 0x94
	// Line 1395, Address: 0x299c4c, Func Offset: 0xbc
	// Line 1397, Address: 0x299c54, Func Offset: 0xc4
	// Line 1400, Address: 0x299c58, Func Offset: 0xc8
	// Line 1402, Address: 0x299cd8, Func Offset: 0x148
	// Func End, Address: 0x299cfc, Func Offset: 0x16c
}

// 
// Start address: 0x299d00
unsigned int fmCnkGetLastFrame(_anon2* fm)
{
	// Line 1409, Address: 0x299d00, Func Offset: 0
	// Line 1410, Address: 0x299d20, Func Offset: 0x20
	// Func End, Address: 0x299d28, Func Offset: 0x28
}

// 
// Start address: 0x299d30
void _fmCnkCalcMuscle(_anon2* fm)
{
	float rsum;
	unsigned int vofs;
	float para;
	_anon3* jaw;
	float rate;
	float sum;
	float* mrp;
	_anon0** mvp;
	float mrate[32];
	_anon0* mvec[32];
	float* param;
	_anon6* list;
	_anon7* con;
	float* dvp;
	float* svp;
	int m;
	int n;
	int i;
	// Line 1513, Address: 0x299d30, Func Offset: 0
	// Line 1514, Address: 0x299d34, Func Offset: 0x4
	// Line 1513, Address: 0x299d38, Func Offset: 0x8
	// Line 1517, Address: 0x299d3c, Func Offset: 0xc
	// Line 1492, Address: 0x299d40, Func Offset: 0x10
	// Line 1513, Address: 0x299d44, Func Offset: 0x14
	// Line 1514, Address: 0x299d48, Func Offset: 0x18
	// Line 1513, Address: 0x299d4c, Func Offset: 0x1c
	// Line 1536, Address: 0x299d50, Func Offset: 0x20
	// Line 1514, Address: 0x299d54, Func Offset: 0x24
	// Line 1513, Address: 0x299d58, Func Offset: 0x28
	// Line 1536, Address: 0x299d5c, Func Offset: 0x2c
	// Line 1537, Address: 0x299d6c, Func Offset: 0x3c
	// Line 1539, Address: 0x299d78, Func Offset: 0x48
	// Line 1541, Address: 0x299d80, Func Offset: 0x50
	// Line 1544, Address: 0x299d8c, Func Offset: 0x5c
	// Line 1545, Address: 0x299d98, Func Offset: 0x68
	// Line 1546, Address: 0x299d9c, Func Offset: 0x6c
	// Line 1547, Address: 0x299da0, Func Offset: 0x70
	// Line 1548, Address: 0x299da4, Func Offset: 0x74
	// Line 1549, Address: 0x299da8, Func Offset: 0x78
	// Line 1550, Address: 0x299dac, Func Offset: 0x7c
	// Line 1551, Address: 0x299db0, Func Offset: 0x80
	// Line 1561, Address: 0x299dbc, Func Offset: 0x8c
	// Line 1562, Address: 0x299dc0, Func Offset: 0x90
	// Line 1564, Address: 0x299dc4, Func Offset: 0x94
	// Line 1566, Address: 0x299dc8, Func Offset: 0x98
	// Line 1571, Address: 0x299ddc, Func Offset: 0xac
	// Line 1567, Address: 0x299de4, Func Offset: 0xb4
	// Line 1568, Address: 0x299de8, Func Offset: 0xb8
	// Line 1569, Address: 0x299dec, Func Offset: 0xbc
	// Line 1571, Address: 0x299df0, Func Offset: 0xc0
	// Line 1570, Address: 0x299df8, Func Offset: 0xc8
	// Line 1571, Address: 0x299dfc, Func Offset: 0xcc
	// Line 1572, Address: 0x299e08, Func Offset: 0xd8
	// Line 1573, Address: 0x299e0c, Func Offset: 0xdc
	// Line 1574, Address: 0x299e14, Func Offset: 0xe4
	// Line 1575, Address: 0x299e24, Func Offset: 0xf4
	// Line 1576, Address: 0x299e34, Func Offset: 0x104
	// Line 1577, Address: 0x299e38, Func Offset: 0x108
	// Line 1576, Address: 0x299e3c, Func Offset: 0x10c
	// Line 1577, Address: 0x299e40, Func Offset: 0x110
	// Line 1580, Address: 0x299e5c, Func Offset: 0x12c
	// Line 1577, Address: 0x299e60, Func Offset: 0x130
	// Line 1579, Address: 0x299e64, Func Offset: 0x134
	// Line 1578, Address: 0x299e6c, Func Offset: 0x13c
	// Line 1579, Address: 0x299e70, Func Offset: 0x140
	// Line 1581, Address: 0x299e74, Func Offset: 0x144
	// Line 1582, Address: 0x299e78, Func Offset: 0x148
	// Line 1583, Address: 0x299e7c, Func Offset: 0x14c
	// Line 1584, Address: 0x299e80, Func Offset: 0x150
	// Line 1586, Address: 0x299e90, Func Offset: 0x160
	// Line 1587, Address: 0x299e9c, Func Offset: 0x16c
	// Line 1607, Address: 0x299ea4, Func Offset: 0x174
	// Line 1587, Address: 0x299eac, Func Offset: 0x17c
	// Line 1588, Address: 0x299ebc, Func Offset: 0x18c
	// Line 1587, Address: 0x299ec8, Func Offset: 0x198
	// Line 1588, Address: 0x299ecc, Func Offset: 0x19c
	// Line 1609, Address: 0x299ed0, Func Offset: 0x1a0
	// Line 1611, Address: 0x299edc, Func Offset: 0x1ac
	// Line 1612, Address: 0x299ee0, Func Offset: 0x1b0
	// Line 1613, Address: 0x299ee4, Func Offset: 0x1b4
	// Line 1614, Address: 0x299ee8, Func Offset: 0x1b8
	// Line 1615, Address: 0x299eec, Func Offset: 0x1bc
	// Line 1616, Address: 0x299ef0, Func Offset: 0x1c0
	// Line 1617, Address: 0x299ef4, Func Offset: 0x1c4
	// Line 1618, Address: 0x299ef8, Func Offset: 0x1c8
	// Line 1619, Address: 0x299efc, Func Offset: 0x1cc
	// Line 1621, Address: 0x299f00, Func Offset: 0x1d0
	// Line 1622, Address: 0x299f04, Func Offset: 0x1d4
	// Line 1623, Address: 0x299f08, Func Offset: 0x1d8
	// Line 1624, Address: 0x299f0c, Func Offset: 0x1dc
	// Line 1625, Address: 0x299f10, Func Offset: 0x1e0
	// Line 1626, Address: 0x299f14, Func Offset: 0x1e4
	// Line 1627, Address: 0x299f18, Func Offset: 0x1e8
	// Line 1628, Address: 0x299f1c, Func Offset: 0x1ec
	// Line 1629, Address: 0x299f20, Func Offset: 0x1f0
	// Line 1630, Address: 0x299f24, Func Offset: 0x1f4
	// Line 1631, Address: 0x299f28, Func Offset: 0x1f8
	// Line 1632, Address: 0x299f2c, Func Offset: 0x1fc
	// Line 1633, Address: 0x299f30, Func Offset: 0x200
	// Line 1634, Address: 0x299f34, Func Offset: 0x204
	// Line 1635, Address: 0x299f38, Func Offset: 0x208
	// Line 1637, Address: 0x299f44, Func Offset: 0x214
	// Line 1638, Address: 0x299f48, Func Offset: 0x218
	// Line 1639, Address: 0x299f4c, Func Offset: 0x21c
	// Line 1644, Address: 0x299f50, Func Offset: 0x220
	// Line 1645, Address: 0x299f54, Func Offset: 0x224
	// Line 1646, Address: 0x299f58, Func Offset: 0x228
	// Line 1652, Address: 0x299f60, Func Offset: 0x230
	// Func End, Address: 0x299f68, Func Offset: 0x238
}

// 
// Start address: 0x299f70
void _fmCnkCalcJaw(_anon2* fm)
{
	float jawtrans;
	float jawang;
	float jmat2[16];
	float jmat1[16];
	unsigned int vofs;
	_anon13 vec;
	_anon13* dvp1;
	float* dvp;
	float mat2[16];
	float mat[16];
	unsigned char mt2[64];
	unsigned char mt1[64];
	_anon3* jaw;
	int i;
	// Line 2051, Address: 0x299f70, Func Offset: 0
	// Line 2076, Address: 0x299fa4, Func Offset: 0x34
	// Line 2058, Address: 0x299fa8, Func Offset: 0x38
	// Line 2059, Address: 0x299fac, Func Offset: 0x3c
	// Line 2076, Address: 0x299fb0, Func Offset: 0x40
	// Line 2082, Address: 0x299fb8, Func Offset: 0x48
	// Line 2085, Address: 0x299fbc, Func Offset: 0x4c
	// Line 2083, Address: 0x299fc0, Func Offset: 0x50
	// Line 2084, Address: 0x299fc4, Func Offset: 0x54
	// Line 2087, Address: 0x299fc8, Func Offset: 0x58
	// Line 2082, Address: 0x299fcc, Func Offset: 0x5c
	// Line 2087, Address: 0x299fd0, Func Offset: 0x60
	// Line 2088, Address: 0x299fd8, Func Offset: 0x68
	// Line 2089, Address: 0x299ff8, Func Offset: 0x88
	// Line 2090, Address: 0x29a00c, Func Offset: 0x9c
	// Line 2093, Address: 0x29a018, Func Offset: 0xa8
	// Line 2094, Address: 0x29a020, Func Offset: 0xb0
	// Line 2095, Address: 0x29a024, Func Offset: 0xb4
	// Line 2096, Address: 0x29a028, Func Offset: 0xb8
	// Line 2093, Address: 0x29a02c, Func Offset: 0xbc
	// Line 2096, Address: 0x29a038, Func Offset: 0xc8
	// Line 2097, Address: 0x29a040, Func Offset: 0xd0
	// Line 2098, Address: 0x29a044, Func Offset: 0xd4
	// Line 2097, Address: 0x29a050, Func Offset: 0xe0
	// Line 2098, Address: 0x29a054, Func Offset: 0xe4
	// Line 2097, Address: 0x29a058, Func Offset: 0xe8
	// Line 2098, Address: 0x29a060, Func Offset: 0xf0
	// Line 2102, Address: 0x29a068, Func Offset: 0xf8
	// Line 2104, Address: 0x29a06c, Func Offset: 0xfc
	// Line 2105, Address: 0x29a070, Func Offset: 0x100
	// Line 2106, Address: 0x29a074, Func Offset: 0x104
	// Line 2107, Address: 0x29a078, Func Offset: 0x108
	// Line 2108, Address: 0x29a07c, Func Offset: 0x10c
	// Line 2109, Address: 0x29a080, Func Offset: 0x110
	// Line 2110, Address: 0x29a084, Func Offset: 0x114
	// Line 2111, Address: 0x29a088, Func Offset: 0x118
	// Line 2112, Address: 0x29a08c, Func Offset: 0x11c
	// Line 2113, Address: 0x29a090, Func Offset: 0x120
	// Line 2114, Address: 0x29a094, Func Offset: 0x124
	// Line 2115, Address: 0x29a098, Func Offset: 0x128
	// Line 2116, Address: 0x29a09c, Func Offset: 0x12c
	// Line 2117, Address: 0x29a0a0, Func Offset: 0x130
	// Line 2118, Address: 0x29a0a4, Func Offset: 0x134
	// Line 2119, Address: 0x29a0a8, Func Offset: 0x138
	// Line 2120, Address: 0x29a0ac, Func Offset: 0x13c
	// Line 2121, Address: 0x29a0b0, Func Offset: 0x140
	// Line 2125, Address: 0x29a0b4, Func Offset: 0x144
	// Line 2131, Address: 0x29a0bc, Func Offset: 0x14c
	// Line 2139, Address: 0x29a0c8, Func Offset: 0x158
	// Line 2140, Address: 0x29a0f4, Func Offset: 0x184
	// Line 2142, Address: 0x29a0f8, Func Offset: 0x188
	// Line 2143, Address: 0x29a0fc, Func Offset: 0x18c
	// Line 2144, Address: 0x29a100, Func Offset: 0x190
	// Line 2145, Address: 0x29a104, Func Offset: 0x194
	// Line 2146, Address: 0x29a108, Func Offset: 0x198
	// Line 2147, Address: 0x29a10c, Func Offset: 0x19c
	// Line 2148, Address: 0x29a110, Func Offset: 0x1a0
	// Line 2149, Address: 0x29a114, Func Offset: 0x1a4
	// Line 2150, Address: 0x29a118, Func Offset: 0x1a8
	// Line 2151, Address: 0x29a11c, Func Offset: 0x1ac
	// Line 2152, Address: 0x29a120, Func Offset: 0x1b0
	// Line 2153, Address: 0x29a124, Func Offset: 0x1b4
	// Line 2154, Address: 0x29a128, Func Offset: 0x1b8
	// Line 2155, Address: 0x29a12c, Func Offset: 0x1bc
	// Line 2156, Address: 0x29a130, Func Offset: 0x1c0
	// Line 2157, Address: 0x29a134, Func Offset: 0x1c4
	// Line 2158, Address: 0x29a138, Func Offset: 0x1c8
	// Line 2159, Address: 0x29a13c, Func Offset: 0x1cc
	// Line 2160, Address: 0x29a140, Func Offset: 0x1d0
	// Line 2161, Address: 0x29a144, Func Offset: 0x1d4
	// Line 2162, Address: 0x29a148, Func Offset: 0x1d8
	// Line 2163, Address: 0x29a14c, Func Offset: 0x1dc
	// Line 2164, Address: 0x29a150, Func Offset: 0x1e0
	// Line 2165, Address: 0x29a154, Func Offset: 0x1e4
	// Line 2166, Address: 0x29a158, Func Offset: 0x1e8
	// Line 2167, Address: 0x29a15c, Func Offset: 0x1ec
	// Line 2168, Address: 0x29a160, Func Offset: 0x1f0
	// Line 2169, Address: 0x29a164, Func Offset: 0x1f4
	// Line 2170, Address: 0x29a168, Func Offset: 0x1f8
	// Line 2171, Address: 0x29a16c, Func Offset: 0x1fc
	// Line 2172, Address: 0x29a170, Func Offset: 0x200
	// Line 2173, Address: 0x29a174, Func Offset: 0x204
	// Line 2174, Address: 0x29a178, Func Offset: 0x208
	// Line 2175, Address: 0x29a17c, Func Offset: 0x20c
	// Line 2176, Address: 0x29a180, Func Offset: 0x210
	// Line 2177, Address: 0x29a184, Func Offset: 0x214
	// Line 2178, Address: 0x29a188, Func Offset: 0x218
	// Line 2179, Address: 0x29a18c, Func Offset: 0x21c
	// Line 2180, Address: 0x29a190, Func Offset: 0x220
	// Line 2181, Address: 0x29a194, Func Offset: 0x224
	// Line 2182, Address: 0x29a198, Func Offset: 0x228
	// Line 2186, Address: 0x29a19c, Func Offset: 0x22c
	// Line 2187, Address: 0x29a1a0, Func Offset: 0x230
	// Line 2191, Address: 0x29a1a8, Func Offset: 0x238
	// Line 2192, Address: 0x29a1ac, Func Offset: 0x23c
	// Line 2187, Address: 0x29a1b0, Func Offset: 0x240
	// Line 2192, Address: 0x29a1b4, Func Offset: 0x244
	// Line 2195, Address: 0x29a1c0, Func Offset: 0x250
	// Line 2196, Address: 0x29a1cc, Func Offset: 0x25c
	// Line 2200, Address: 0x29a1ec, Func Offset: 0x27c
	// Line 2201, Address: 0x29a1f8, Func Offset: 0x288
	// Line 2206, Address: 0x29a218, Func Offset: 0x2a8
	// Func End, Address: 0x29a250, Func Offset: 0x2e0
}

// 
// Start address: 0x29a250
void _fmCnkCalcEye(_anon2* fm)
{
	int i;
	_anon0 r3;
	_anon0 q3;
	_anon0 t3;
	cnkobj* obj;
	float dz;
	float dy;
	float dx;
	// Line 2294, Address: 0x29a250, Func Offset: 0
	// Line 2304, Address: 0x29a270, Func Offset: 0x20
	// Line 2305, Address: 0x29a274, Func Offset: 0x24
	// Line 2306, Address: 0x29a278, Func Offset: 0x28
	// Line 2307, Address: 0x29a284, Func Offset: 0x34
	// Line 2308, Address: 0x29a28c, Func Offset: 0x3c
	// Line 2309, Address: 0x29a298, Func Offset: 0x48
	// Line 2310, Address: 0x29a2a0, Func Offset: 0x50
	// Line 2325, Address: 0x29a2a8, Func Offset: 0x58
	// Line 2327, Address: 0x29a2c8, Func Offset: 0x78
	// Line 2328, Address: 0x29a2cc, Func Offset: 0x7c
	// Line 2329, Address: 0x29a2d0, Func Offset: 0x80
	// Line 2330, Address: 0x29a2d4, Func Offset: 0x84
	// Line 2331, Address: 0x29a2d8, Func Offset: 0x88
	// Line 2332, Address: 0x29a2dc, Func Offset: 0x8c
	// Line 2333, Address: 0x29a2e0, Func Offset: 0x90
	// Line 2334, Address: 0x29a2e4, Func Offset: 0x94
	// Line 2335, Address: 0x29a2e8, Func Offset: 0x98
	// Line 2336, Address: 0x29a2ec, Func Offset: 0x9c
	// Line 2337, Address: 0x29a2f0, Func Offset: 0xa0
	// Line 2338, Address: 0x29a2f4, Func Offset: 0xa4
	// Line 2339, Address: 0x29a2f8, Func Offset: 0xa8
	// Line 2340, Address: 0x29a2fc, Func Offset: 0xac
	// Line 2341, Address: 0x29a300, Func Offset: 0xb0
	// Line 2342, Address: 0x29a304, Func Offset: 0xb4
	// Line 2343, Address: 0x29a308, Func Offset: 0xb8
	// Line 2344, Address: 0x29a30c, Func Offset: 0xbc
	// Line 2345, Address: 0x29a310, Func Offset: 0xc0
	// Line 2346, Address: 0x29a314, Func Offset: 0xc4
	// Line 2347, Address: 0x29a318, Func Offset: 0xc8
	// Line 2348, Address: 0x29a31c, Func Offset: 0xcc
	// Line 2349, Address: 0x29a320, Func Offset: 0xd0
	// Line 2350, Address: 0x29a324, Func Offset: 0xd4
	// Line 2351, Address: 0x29a328, Func Offset: 0xd8
	// Line 2352, Address: 0x29a32c, Func Offset: 0xdc
	// Line 2353, Address: 0x29a330, Func Offset: 0xe0
	// Line 2354, Address: 0x29a334, Func Offset: 0xe4
	// Line 2355, Address: 0x29a338, Func Offset: 0xe8
	// Line 2356, Address: 0x29a33c, Func Offset: 0xec
	// Line 2357, Address: 0x29a340, Func Offset: 0xf0
	// Line 2358, Address: 0x29a344, Func Offset: 0xf4
	// Line 2359, Address: 0x29a348, Func Offset: 0xf8
	// Line 2360, Address: 0x29a34c, Func Offset: 0xfc
	// Line 2361, Address: 0x29a350, Func Offset: 0x100
	// Line 2362, Address: 0x29a354, Func Offset: 0x104
	// Line 2363, Address: 0x29a358, Func Offset: 0x108
	// Line 2364, Address: 0x29a35c, Func Offset: 0x10c
	// Line 2365, Address: 0x29a360, Func Offset: 0x110
	// Line 2375, Address: 0x29a364, Func Offset: 0x114
	// Line 2369, Address: 0x29a36c, Func Offset: 0x11c
	// Line 2370, Address: 0x29a370, Func Offset: 0x120
	// Line 2375, Address: 0x29a374, Func Offset: 0x124
	// Line 2377, Address: 0x29a384, Func Offset: 0x134
	// Line 2381, Address: 0x29a3ac, Func Offset: 0x15c
	// Line 2384, Address: 0x29a3b4, Func Offset: 0x164
	// Line 2388, Address: 0x29a3e4, Func Offset: 0x194
	// Line 2389, Address: 0x29a3e8, Func Offset: 0x198
	// Line 2390, Address: 0x29a400, Func Offset: 0x1b0
	// Line 2391, Address: 0x29a430, Func Offset: 0x1e0
	// Line 2393, Address: 0x29a438, Func Offset: 0x1e8
	// Line 2394, Address: 0x29a474, Func Offset: 0x224
	// Line 2396, Address: 0x29a478, Func Offset: 0x228
	// Line 2397, Address: 0x29a484, Func Offset: 0x234
	// Line 2398, Address: 0x29a488, Func Offset: 0x238
	// Line 2402, Address: 0x29a49c, Func Offset: 0x24c
	// Func End, Address: 0x29a4c0, Func Offset: 0x270
}

// 
// Start address: 0x29a4c0
void _fmCnkCalcTang(_anon2* fm)
{
	unsigned int calc_ofs;
	float tangz;
	float tangy;
	float tangx;
	unsigned int vofs;
	float* dvp;
	float* svp;
	float mat[16];
	unsigned char mt1[64];
	_anon3* tang;
	int i;
	// Line 2446, Address: 0x29a4c0, Func Offset: 0
	// Line 2464, Address: 0x29a4ec, Func Offset: 0x2c
	// Line 2474, Address: 0x29a4f8, Func Offset: 0x38
	// Line 2475, Address: 0x29a4fc, Func Offset: 0x3c
	// Line 2474, Address: 0x29a500, Func Offset: 0x40
	// Line 2470, Address: 0x29a504, Func Offset: 0x44
	// Line 2471, Address: 0x29a508, Func Offset: 0x48
	// Line 2472, Address: 0x29a50c, Func Offset: 0x4c
	// Line 2474, Address: 0x29a510, Func Offset: 0x50
	// Line 2475, Address: 0x29a514, Func Offset: 0x54
	// Line 2473, Address: 0x29a518, Func Offset: 0x58
	// Line 2476, Address: 0x29a51c, Func Offset: 0x5c
	// Line 2474, Address: 0x29a520, Func Offset: 0x60
	// Line 2499, Address: 0x29a528, Func Offset: 0x68
	// Line 2517, Address: 0x29a530, Func Offset: 0x70
	// Line 2518, Address: 0x29a534, Func Offset: 0x74
	// Line 2519, Address: 0x29a538, Func Offset: 0x78
	// Line 2520, Address: 0x29a53c, Func Offset: 0x7c
	// Line 2521, Address: 0x29a540, Func Offset: 0x80
	// Line 2522, Address: 0x29a544, Func Offset: 0x84
	// Line 2523, Address: 0x29a548, Func Offset: 0x88
	// Line 2524, Address: 0x29a54c, Func Offset: 0x8c
	// Line 2527, Address: 0x29a550, Func Offset: 0x90
	// Line 2528, Address: 0x29a57c, Func Offset: 0xbc
	// Line 2529, Address: 0x29a5a8, Func Offset: 0xe8
	// Line 2531, Address: 0x29a5b0, Func Offset: 0xf0
	// Line 2533, Address: 0x29a5bc, Func Offset: 0xfc
	// Line 2534, Address: 0x29a5c0, Func Offset: 0x100
	// Line 2535, Address: 0x29a5c4, Func Offset: 0x104
	// Line 2536, Address: 0x29a5c8, Func Offset: 0x108
	// Line 2537, Address: 0x29a5cc, Func Offset: 0x10c
	// Line 2538, Address: 0x29a5d0, Func Offset: 0x110
	// Line 2539, Address: 0x29a5d4, Func Offset: 0x114
	// Line 2540, Address: 0x29a5d8, Func Offset: 0x118
	// Line 2541, Address: 0x29a5dc, Func Offset: 0x11c
	// Line 2542, Address: 0x29a5e0, Func Offset: 0x120
	// Line 2543, Address: 0x29a5e4, Func Offset: 0x124
	// Line 2544, Address: 0x29a5e8, Func Offset: 0x128
	// Line 2546, Address: 0x29a5ec, Func Offset: 0x12c
	// Line 2547, Address: 0x29a5f0, Func Offset: 0x130
	// Line 2548, Address: 0x29a5f4, Func Offset: 0x134
	// Line 2549, Address: 0x29a5f8, Func Offset: 0x138
	// Line 2551, Address: 0x29a5fc, Func Offset: 0x13c
	// Line 2552, Address: 0x29a600, Func Offset: 0x140
	// Line 2553, Address: 0x29a604, Func Offset: 0x144
	// Line 2554, Address: 0x29a608, Func Offset: 0x148
	// Line 2555, Address: 0x29a60c, Func Offset: 0x14c
	// Line 2559, Address: 0x29a610, Func Offset: 0x150
	// Line 2560, Address: 0x29a614, Func Offset: 0x154
	// Line 2564, Address: 0x29a620, Func Offset: 0x160
	// Func End, Address: 0x29a650, Func Offset: 0x190
}

// 
// Start address: 0x29a650
void _fmCnkCalcNormal(_anon2* fm)
{
	unsigned int vofs;
	_anon0** nvp;
	_anon6* list;
	_anon0 norm;
	_anon0* dnp1;
	_anon0* dvp1;
	float* dnp;
	float* dvp;
	int n;
	int i;
	// Line 2683, Address: 0x29a650, Func Offset: 0
	// Line 2693, Address: 0x29a67c, Func Offset: 0x2c
	// Line 2694, Address: 0x29a684, Func Offset: 0x34
	// Line 2695, Address: 0x29a688, Func Offset: 0x38
	// Line 2696, Address: 0x29a68c, Func Offset: 0x3c
	// Line 2698, Address: 0x29a690, Func Offset: 0x40
	// Line 2693, Address: 0x29a694, Func Offset: 0x44
	// Line 2697, Address: 0x29a6a0, Func Offset: 0x50
	// Line 2694, Address: 0x29a6a4, Func Offset: 0x54
	// Line 2693, Address: 0x29a6a8, Func Offset: 0x58
	// Line 2694, Address: 0x29a6ac, Func Offset: 0x5c
	// Line 2699, Address: 0x29a6b0, Func Offset: 0x60
	// Line 2700, Address: 0x29a6b8, Func Offset: 0x68
	// Line 2703, Address: 0x29a6bc, Func Offset: 0x6c
	// Line 2700, Address: 0x29a6c0, Func Offset: 0x70
	// Line 2701, Address: 0x29a6cc, Func Offset: 0x7c
	// Line 2702, Address: 0x29a6d0, Func Offset: 0x80
	// Line 2704, Address: 0x29a6dc, Func Offset: 0x8c
	// Line 2705, Address: 0x29a6e4, Func Offset: 0x94
	// Line 2706, Address: 0x29a6f8, Func Offset: 0xa8
	// Line 2707, Address: 0x29a700, Func Offset: 0xb0
	// Line 2710, Address: 0x29a708, Func Offset: 0xb8
	// Line 2707, Address: 0x29a70c, Func Offset: 0xbc
	// Line 2708, Address: 0x29a714, Func Offset: 0xc4
	// Line 2709, Address: 0x29a724, Func Offset: 0xd4
	// Line 2711, Address: 0x29a734, Func Offset: 0xe4
	// Line 2712, Address: 0x29a74c, Func Offset: 0xfc
	// Line 2713, Address: 0x29a754, Func Offset: 0x104
	// Line 2714, Address: 0x29a758, Func Offset: 0x108
	// Line 2715, Address: 0x29a76c, Func Offset: 0x11c
	// Func End, Address: 0x29a79c, Func Offset: 0x14c
}

// 
// Start address: 0x29a7a0
void fmCnkCalcFace(_anon2* fm)
{
	// Line 2813, Address: 0x29a7a0, Func Offset: 0
	// Line 2814, Address: 0x29a7ac, Func Offset: 0xc
	// Line 2846, Address: 0x29a7b8, Func Offset: 0x18
	// Line 2847, Address: 0x29a7c0, Func Offset: 0x20
	// Line 2848, Address: 0x29a7c8, Func Offset: 0x28
	// Line 2850, Address: 0x29a7d0, Func Offset: 0x30
	// Line 2852, Address: 0x29a7d8, Func Offset: 0x38
	// Line 2853, Address: 0x29a7e8, Func Offset: 0x48
	// Line 2856, Address: 0x29a7f0, Func Offset: 0x50
	// Func End, Address: 0x29a800, Func Offset: 0x60
}

// 
// Start address: 0x29a800
void fmCnkSetMode(_anon2* fm, unsigned int mode)
{
	float* dnp;
	float* snp;
	int i;
	// Line 2895, Address: 0x29a800, Func Offset: 0
	// Line 2896, Address: 0x29a81c, Func Offset: 0x1c
	// Line 2897, Address: 0x29a824, Func Offset: 0x24
	// Line 2896, Address: 0x29a828, Func Offset: 0x28
	// Line 2897, Address: 0x29a830, Func Offset: 0x30
	// Line 2896, Address: 0x29a834, Func Offset: 0x34
	// Line 2898, Address: 0x29a838, Func Offset: 0x38
	// Line 2897, Address: 0x29a83c, Func Offset: 0x3c
	// Line 2898, Address: 0x29a840, Func Offset: 0x40
	// Line 2899, Address: 0x29a84c, Func Offset: 0x4c
	// Line 2908, Address: 0x29a850, Func Offset: 0x50
	// Line 2899, Address: 0x29a854, Func Offset: 0x54
	// Line 2904, Address: 0x29a858, Func Offset: 0x58
	// Line 2905, Address: 0x29a85c, Func Offset: 0x5c
	// Line 2908, Address: 0x29a860, Func Offset: 0x60
	// Line 2912, Address: 0x29a868, Func Offset: 0x68
	// Func End, Address: 0x29a870, Func Offset: 0x70
}

