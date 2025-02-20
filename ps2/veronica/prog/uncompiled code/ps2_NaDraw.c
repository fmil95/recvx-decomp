typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct tagVU1_STRIP_BUF;
typedef struct tagNJS_SCRVECTOR;


typedef _anon0 type_0[32];
typedef float type_1[4][128];
typedef float type_2[4];
typedef float type_3[4][6];
typedef float type_4[4][64];
typedef float type_5[4][64];
typedef tagVU1_STRIP_BUF type_6[256];
typedef float type_7[4][64];
typedef _anon0 type_8[4];
typedef float type_9[4][128];
typedef float type_10[4][64];

struct _anon0
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon1
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon2
{
	_anon1* textures;
	unsigned int nbTexture;
};

struct _anon3
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon4
{
	float x1;
	float y1;
	float x2;
	float y2;
	float u1;
	float v1;
	float u2;
	float v2;
};

struct _anon5
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct tagVU1_STRIP_BUF
{
	float fU;
	float fV;
	float fPad0;
	float fPad1;
	float fIr;
	float fIg;
	float fIb;
	float fA;
	float fVx;
	float fVy;
	float fVz;
	float fFog;
	float fSx;
	float fSy;
	float fIz;
	float fNz;
};

struct tagNJS_SCRVECTOR
{
	float x;
	float y;
	float z;
	float iz;
	float fog;
};

int Ps2_3DEx_trans;
int Ps2_3DEx_count;
_anon5* Ps2_3DEx_p;
int Ps2_tex3DEx_trans;
int Ps2_tex3DEx_count;
_anon3* Ps2_tex3DEx_p;
unsigned int Ps2_current_texno_bk;
unsigned int Ps2_current_texno;
_anon2* Ps2_current_texlist_bk;
_anon2* Ps2_current_texlist;
int Ps2_quad_trans;
unsigned int Ps2_quad_color;

void njDrawPolygon(_anon5* polygon, int count, int trans);
void njDrawTextureSub(_anon3* polygon, int count, int flag);
void njDrawTexture(_anon3* polygon, int count, int tex, int flag);
void njDrawTextureSubH(_anon0* polygon, int count, int flag);
void njDrawTextureH(_anon0* polygon, int count, int tex, int flag);
void njDrawPolygon3DEx(_anon5* p, int count, int trans);
void njDrawPolygon3DExStart(int trans);
void njDrawPolygonSub3D(_anon5* polygon, int count, int flag);
void njDrawPolygon3DExSetData(_anon5* p, int count);
void njDrawPolygon3DExEnd();
void njDrawTexture3DEx(_anon3* p, int count, int trans);
void njDrawTexture3DEx1P(_anon3* p, int count, int trans);
void njDrawTexture3DExStart(int trans);
void njDrawTextureSub3D(_anon3* polygon, int count, int flag);
void njDrawTextureSub3D1P(_anon3* polygon, int count, int flag);
void njDrawTexture3DExSetData(_anon3* p, int count);
void njDrawTexture3DExSetData1P(_anon3* p, int count);
void njDrawTexture3DExEnd();
void njDrawTextureSub3DH(_anon0* polygon, int count, int flag);
void njDrawTexture3DHEx(_anon0* p, int count, int trans);
void njQuadTextureStart(int trans);
void njQuadTextureEnd();
void njSetQuadTexture(int texid, unsigned int col);
void njDrawQuadTexture(_anon4* q, float z);

// 
// Start address: 0x2de160
void njDrawPolygon(_anon5* polygon, int count, int trans)
{
	unsigned int i;
	float bp[4];
	float buff[4][64];
	float sz;
	// Line 73, Address: 0x2de160, Func Offset: 0
	// Line 83, Address: 0x2de164, Func Offset: 0x4
	// Line 73, Address: 0x2de16c, Func Offset: 0xc
	// Line 83, Address: 0x2de170, Func Offset: 0x10
	// Line 102, Address: 0x2de178, Func Offset: 0x18
	// Line 101, Address: 0x2de180, Func Offset: 0x20
	// Line 103, Address: 0x2de184, Func Offset: 0x24
	// Line 95, Address: 0x2de18c, Func Offset: 0x2c
	// Line 103, Address: 0x2de194, Func Offset: 0x34
	// Line 96, Address: 0x2de198, Func Offset: 0x38
	// Line 85, Address: 0x2de1a0, Func Offset: 0x40
	// Line 86, Address: 0x2de1a4, Func Offset: 0x44
	// Line 87, Address: 0x2de1a8, Func Offset: 0x48
	// Line 88, Address: 0x2de1ac, Func Offset: 0x4c
	// Line 90, Address: 0x2de1b0, Func Offset: 0x50
	// Line 91, Address: 0x2de1bc, Func Offset: 0x5c
	// Line 92, Address: 0x2de1c8, Func Offset: 0x68
	// Line 93, Address: 0x2de1d0, Func Offset: 0x70
	// Line 95, Address: 0x2de1dc, Func Offset: 0x7c
	// Line 96, Address: 0x2de1e8, Func Offset: 0x88
	// Line 101, Address: 0x2de1f4, Func Offset: 0x94
	// Line 102, Address: 0x2de208, Func Offset: 0xa8
	// Line 103, Address: 0x2de21c, Func Offset: 0xbc
	// Line 104, Address: 0x2de22c, Func Offset: 0xcc
	// Line 105, Address: 0x2de234, Func Offset: 0xd4
	// Line 107, Address: 0x2de238, Func Offset: 0xd8
	// Line 109, Address: 0x2de23c, Func Offset: 0xdc
	// Line 108, Address: 0x2de240, Func Offset: 0xe0
	// Line 109, Address: 0x2de248, Func Offset: 0xe8
	// Line 111, Address: 0x2de258, Func Offset: 0xf8
	// Line 112, Address: 0x2de264, Func Offset: 0x104
	// Line 114, Address: 0x2de278, Func Offset: 0x118
	// Line 115, Address: 0x2de280, Func Offset: 0x120
	// Line 118, Address: 0x2de294, Func Offset: 0x134
	// Func End, Address: 0x2de2a0, Func Offset: 0x140
}

// 
// Start address: 0x2de2a0
void njDrawTextureSub(_anon3* polygon, int count, int flag)
{
	unsigned int i;
	float bp[4];
	float buff[4][128];
	float sz;
	// Line 121, Address: 0x2de2a0, Func Offset: 0
	// Line 131, Address: 0x2de2a4, Func Offset: 0x4
	// Line 121, Address: 0x2de2ac, Func Offset: 0xc
	// Line 131, Address: 0x2de2b0, Func Offset: 0x10
	// Line 157, Address: 0x2de2b8, Func Offset: 0x18
	// Line 150, Address: 0x2de2c0, Func Offset: 0x20
	// Line 158, Address: 0x2de2c4, Func Offset: 0x24
	// Line 150, Address: 0x2de2cc, Func Offset: 0x2c
	// Line 135, Address: 0x2de2d0, Func Offset: 0x30
	// Line 151, Address: 0x2de2d4, Func Offset: 0x34
	// Line 156, Address: 0x2de2d8, Func Offset: 0x38
	// Line 158, Address: 0x2de2dc, Func Offset: 0x3c
	// Line 151, Address: 0x2de2e0, Func Offset: 0x40
	// Line 153, Address: 0x2de2e4, Func Offset: 0x44
	// Line 133, Address: 0x2de2e8, Func Offset: 0x48
	// Line 134, Address: 0x2de2f0, Func Offset: 0x50
	// Line 135, Address: 0x2de2f8, Func Offset: 0x58
	// Line 136, Address: 0x2de2fc, Func Offset: 0x5c
	// Line 144, Address: 0x2de300, Func Offset: 0x60
	// Line 145, Address: 0x2de318, Func Offset: 0x78
	// Line 146, Address: 0x2de330, Func Offset: 0x90
	// Line 147, Address: 0x2de340, Func Offset: 0xa0
	// Line 150, Address: 0x2de358, Func Offset: 0xb8
	// Line 151, Address: 0x2de364, Func Offset: 0xc4
	// Line 153, Address: 0x2de370, Func Offset: 0xd0
	// Line 154, Address: 0x2de384, Func Offset: 0xe4
	// Line 156, Address: 0x2de388, Func Offset: 0xe8
	// Line 157, Address: 0x2de39c, Func Offset: 0xfc
	// Line 158, Address: 0x2de3b0, Func Offset: 0x110
	// Line 159, Address: 0x2de3c0, Func Offset: 0x120
	// Line 160, Address: 0x2de3c8, Func Offset: 0x128
	// Line 161, Address: 0x2de3cc, Func Offset: 0x12c
	// Line 162, Address: 0x2de3d0, Func Offset: 0x130
	// Line 164, Address: 0x2de3d4, Func Offset: 0x134
	// Line 163, Address: 0x2de3d8, Func Offset: 0x138
	// Line 164, Address: 0x2de3e0, Func Offset: 0x140
	// Line 166, Address: 0x2de3f0, Func Offset: 0x150
	// Line 167, Address: 0x2de3fc, Func Offset: 0x15c
	// Line 169, Address: 0x2de410, Func Offset: 0x170
	// Line 170, Address: 0x2de418, Func Offset: 0x178
	// Line 173, Address: 0x2de42c, Func Offset: 0x18c
	// Func End, Address: 0x2de438, Func Offset: 0x198
}

// 
// Start address: 0x2de440
void njDrawTexture(_anon3* polygon, int count, int tex, int flag)
{
	// Line 191, Address: 0x2de440, Func Offset: 0
	// Line 201, Address: 0x2de460, Func Offset: 0x20
	// Line 202, Address: 0x2de468, Func Offset: 0x28
	// Line 203, Address: 0x2de478, Func Offset: 0x38
	// Func End, Address: 0x2de490, Func Offset: 0x50
}

// 
// Start address: 0x2de490
void njDrawTextureSubH(_anon0* polygon, int count, int flag)
{
	unsigned int i;
	float bp[4];
	float buff[4][128];
	float sz;
	// Line 206, Address: 0x2de490, Func Offset: 0
	// Line 216, Address: 0x2de494, Func Offset: 0x4
	// Line 206, Address: 0x2de49c, Func Offset: 0xc
	// Line 216, Address: 0x2de4a0, Func Offset: 0x10
	// Line 231, Address: 0x2de4a8, Func Offset: 0x18
	// Line 230, Address: 0x2de4b0, Func Offset: 0x20
	// Line 232, Address: 0x2de4b4, Func Offset: 0x24
	// Line 228, Address: 0x2de4bc, Func Offset: 0x2c
	// Line 232, Address: 0x2de4c4, Func Offset: 0x34
	// Line 229, Address: 0x2de4c8, Func Offset: 0x38
	// Line 220, Address: 0x2de4d0, Func Offset: 0x40
	// Line 218, Address: 0x2de4d4, Func Offset: 0x44
	// Line 219, Address: 0x2de4dc, Func Offset: 0x4c
	// Line 220, Address: 0x2de4e4, Func Offset: 0x54
	// Line 221, Address: 0x2de4e8, Func Offset: 0x58
	// Line 223, Address: 0x2de4ec, Func Offset: 0x5c
	// Line 224, Address: 0x2de4f8, Func Offset: 0x68
	// Line 225, Address: 0x2de504, Func Offset: 0x74
	// Line 226, Address: 0x2de50c, Func Offset: 0x7c
	// Line 228, Address: 0x2de518, Func Offset: 0x88
	// Line 229, Address: 0x2de524, Func Offset: 0x94
	// Line 230, Address: 0x2de530, Func Offset: 0xa0
	// Line 231, Address: 0x2de544, Func Offset: 0xb4
	// Line 232, Address: 0x2de558, Func Offset: 0xc8
	// Line 233, Address: 0x2de568, Func Offset: 0xd8
	// Line 234, Address: 0x2de570, Func Offset: 0xe0
	// Line 235, Address: 0x2de574, Func Offset: 0xe4
	// Line 236, Address: 0x2de578, Func Offset: 0xe8
	// Line 238, Address: 0x2de57c, Func Offset: 0xec
	// Line 239, Address: 0x2de5b0, Func Offset: 0x120
	// Line 238, Address: 0x2de5b4, Func Offset: 0x124
	// Line 239, Address: 0x2de5bc, Func Offset: 0x12c
	// Line 241, Address: 0x2de5c8, Func Offset: 0x138
	// Line 242, Address: 0x2de5d4, Func Offset: 0x144
	// Line 244, Address: 0x2de5e8, Func Offset: 0x158
	// Line 245, Address: 0x2de5f0, Func Offset: 0x160
	// Line 248, Address: 0x2de604, Func Offset: 0x174
	// Func End, Address: 0x2de610, Func Offset: 0x180
}

// 
// Start address: 0x2de610
void njDrawTextureH(_anon0* polygon, int count, int tex, int flag)
{
	int i;
	_anon0 poly[32];
	// Line 304, Address: 0x2de610, Func Offset: 0
	// Line 317, Address: 0x2de628, Func Offset: 0x18
	// Line 318, Address: 0x2de654, Func Offset: 0x44
	// Line 319, Address: 0x2de65c, Func Offset: 0x4c
	// Line 338, Address: 0x2de66c, Func Offset: 0x5c
	// Line 320, Address: 0x2de670, Func Offset: 0x60
	// Line 339, Address: 0x2de674, Func Offset: 0x64
	// Line 320, Address: 0x2de67c, Func Offset: 0x6c
	// Line 321, Address: 0x2de680, Func Offset: 0x70
	// Line 322, Address: 0x2de688, Func Offset: 0x78
	// Line 323, Address: 0x2de690, Func Offset: 0x80
	// Line 324, Address: 0x2de698, Func Offset: 0x88
	// Line 336, Address: 0x2de6a0, Func Offset: 0x90
	// Line 338, Address: 0x2de6f4, Func Offset: 0xe4
	// Line 339, Address: 0x2de6fc, Func Offset: 0xec
	// Line 341, Address: 0x2de708, Func Offset: 0xf8
	// Line 342, Address: 0x2de718, Func Offset: 0x108
	// Line 344, Address: 0x2de720, Func Offset: 0x110
	// Func End, Address: 0x2de73c, Func Offset: 0x12c
}

// 
// Start address: 0x2de740
void njDrawPolygon3DEx(_anon5* p, int count, int trans)
{
	// Line 360, Address: 0x2de740, Func Offset: 0
	// Line 361, Address: 0x2de758, Func Offset: 0x18
	// Line 362, Address: 0x2de760, Func Offset: 0x20
	// Line 364, Address: 0x2de76c, Func Offset: 0x2c
	// Func End, Address: 0x2de780, Func Offset: 0x40
}

// 
// Start address: 0x2de780
void njDrawPolygon3DExStart(int trans)
{
	// Line 378, Address: 0x2de780, Func Offset: 0
	// Line 379, Address: 0x2de784, Func Offset: 0x4
	// Func End, Address: 0x2de78c, Func Offset: 0xc
}

// 
// Start address: 0x2de790
void njDrawPolygonSub3D(_anon5* polygon, int count, int flag)
{
	tagNJS_SCRVECTOR scr;
	unsigned int i;
	float bp[4];
	float buff[4][64];
	float invz;
	// Line 382, Address: 0x2de790, Func Offset: 0
	// Line 393, Address: 0x2de7b0, Func Offset: 0x20
	// Line 395, Address: 0x2de7c8, Func Offset: 0x38
	// Line 400, Address: 0x2de7cc, Func Offset: 0x3c
	// Line 395, Address: 0x2de7d4, Func Offset: 0x44
	// Line 396, Address: 0x2de7dc, Func Offset: 0x4c
	// Line 397, Address: 0x2de7e8, Func Offset: 0x58
	// Line 398, Address: 0x2de7f0, Func Offset: 0x60
	// Line 400, Address: 0x2de7f8, Func Offset: 0x68
	// Line 402, Address: 0x2de800, Func Offset: 0x70
	// Line 412, Address: 0x2de804, Func Offset: 0x74
	// Line 411, Address: 0x2de808, Func Offset: 0x78
	// Line 412, Address: 0x2de80c, Func Offset: 0x7c
	// Line 402, Address: 0x2de810, Func Offset: 0x80
	// Line 403, Address: 0x2de814, Func Offset: 0x84
	// Line 404, Address: 0x2de81c, Func Offset: 0x8c
	// Line 405, Address: 0x2de824, Func Offset: 0x94
	// Line 407, Address: 0x2de82c, Func Offset: 0x9c
	// Line 408, Address: 0x2de830, Func Offset: 0xa0
	// Line 409, Address: 0x2de834, Func Offset: 0xa4
	// Line 410, Address: 0x2de838, Func Offset: 0xa8
	// Line 411, Address: 0x2de83c, Func Offset: 0xac
	// Line 412, Address: 0x2de840, Func Offset: 0xb0
	// Line 415, Address: 0x2de848, Func Offset: 0xb8
	// Line 416, Address: 0x2de854, Func Offset: 0xc4
	// Line 418, Address: 0x2de868, Func Offset: 0xd8
	// Line 419, Address: 0x2de870, Func Offset: 0xe0
	// Line 423, Address: 0x2de884, Func Offset: 0xf4
	// Func End, Address: 0x2de8a4, Func Offset: 0x114
}

// 
// Start address: 0x2de8b0
void njDrawPolygon3DExSetData(_anon5* p, int count)
{
	// Line 440, Address: 0x2de8b0, Func Offset: 0
	// Line 441, Address: 0x2de8b8, Func Offset: 0x8
	// Line 443, Address: 0x2de8c0, Func Offset: 0x10
	// Func End, Address: 0x2de8cc, Func Offset: 0x1c
}

// 
// Start address: 0x2de8d0
void njDrawPolygon3DExEnd()
{
	// Line 454, Address: 0x2de8d0, Func Offset: 0
	// Func End, Address: 0x2de8d8, Func Offset: 0x8
}

// 
// Start address: 0x2de8e0
void njDrawTexture3DEx(_anon3* p, int count, int trans)
{
	// Line 469, Address: 0x2de8e0, Func Offset: 0
	// Line 470, Address: 0x2de8f8, Func Offset: 0x18
	// Line 471, Address: 0x2de900, Func Offset: 0x20
	// Line 473, Address: 0x2de90c, Func Offset: 0x2c
	// Func End, Address: 0x2de920, Func Offset: 0x40
}

// 
// Start address: 0x2de920
void njDrawTexture3DEx1P(_anon3* p, int count, int trans)
{
	// Line 476, Address: 0x2de920, Func Offset: 0
	// Line 477, Address: 0x2de938, Func Offset: 0x18
	// Line 478, Address: 0x2de940, Func Offset: 0x20
	// Line 480, Address: 0x2de94c, Func Offset: 0x2c
	// Func End, Address: 0x2de960, Func Offset: 0x40
}

// 
// Start address: 0x2de960
void njDrawTexture3DExStart(int trans)
{
	// Line 496, Address: 0x2de960, Func Offset: 0
	// Line 497, Address: 0x2de964, Func Offset: 0x4
	// Func End, Address: 0x2de96c, Func Offset: 0xc
}

// 
// Start address: 0x2de970
void njDrawTextureSub3D(_anon3* polygon, int count, int flag)
{
	unsigned int cflag;
	tagNJS_SCRVECTOR scr;
	unsigned int col;
	unsigned int i;
	float bp[4];
	float buff[4][64];
	float invz;
	// Line 507, Address: 0x2de970, Func Offset: 0
	// Line 512, Address: 0x2de994, Func Offset: 0x24
	// Line 520, Address: 0x2de998, Func Offset: 0x28
	// Line 524, Address: 0x2de9b0, Func Offset: 0x40
	// Line 546, Address: 0x2de9b4, Func Offset: 0x44
	// Line 525, Address: 0x2de9bc, Func Offset: 0x4c
	// Line 526, Address: 0x2de9d0, Func Offset: 0x60
	// Line 527, Address: 0x2de9e4, Func Offset: 0x74
	// Line 528, Address: 0x2de9f4, Func Offset: 0x84
	// Line 546, Address: 0x2dea04, Func Offset: 0x94
	// Line 548, Address: 0x2dea0c, Func Offset: 0x9c
	// Line 555, Address: 0x2dea28, Func Offset: 0xb8
	// Line 560, Address: 0x2dea2c, Func Offset: 0xbc
	// Line 555, Address: 0x2dea30, Func Offset: 0xc0
	// Line 556, Address: 0x2dea34, Func Offset: 0xc4
	// Line 557, Address: 0x2dea3c, Func Offset: 0xcc
	// Line 558, Address: 0x2dea44, Func Offset: 0xd4
	// Line 560, Address: 0x2dea48, Func Offset: 0xd8
	// Line 563, Address: 0x2dea50, Func Offset: 0xe0
	// Line 564, Address: 0x2dea54, Func Offset: 0xe4
	// Line 568, Address: 0x2dea58, Func Offset: 0xe8
	// Line 560, Address: 0x2dea60, Func Offset: 0xf0
	// Line 564, Address: 0x2dea64, Func Offset: 0xf4
	// Line 565, Address: 0x2dea6c, Func Offset: 0xfc
	// Line 567, Address: 0x2dea74, Func Offset: 0x104
	// Line 565, Address: 0x2dea78, Func Offset: 0x108
	// Line 566, Address: 0x2dea7c, Func Offset: 0x10c
	// Line 567, Address: 0x2dea80, Func Offset: 0x110
	// Line 568, Address: 0x2dea84, Func Offset: 0x114
	// Line 570, Address: 0x2dea90, Func Offset: 0x120
	// Line 573, Address: 0x2dea98, Func Offset: 0x128
	// Line 574, Address: 0x2deaa4, Func Offset: 0x134
	// Line 576, Address: 0x2deab8, Func Offset: 0x148
	// Line 577, Address: 0x2deac0, Func Offset: 0x150
	// Line 583, Address: 0x2dead4, Func Offset: 0x164
	// Func End, Address: 0x2deaf8, Func Offset: 0x188
}

// 
// Start address: 0x2deb00
void njDrawTextureSub3D1P(_anon3* polygon, int count, int flag)
{
	tagVU1_STRIP_BUF* vp;
	unsigned long prim;
	unsigned int i;
	tagVU1_STRIP_BUF vb[256];
	// Line 643, Address: 0x2deb00, Func Offset: 0
	// Line 660, Address: 0x2deb1c, Func Offset: 0x1c
	// Line 643, Address: 0x2deb20, Func Offset: 0x20
	// Line 660, Address: 0x2deb24, Func Offset: 0x24
	// Line 677, Address: 0x2deb3c, Func Offset: 0x3c
	// Line 678, Address: 0x2deb94, Func Offset: 0x94
	// Line 679, Address: 0x2debec, Func Offset: 0xec
	// Line 680, Address: 0x2dec3c, Func Offset: 0x13c
	// Line 682, Address: 0x2dec88, Func Offset: 0x188
	// Line 680, Address: 0x2dec8c, Func Offset: 0x18c
	// Line 682, Address: 0x2dec90, Func Offset: 0x190
	// Line 684, Address: 0x2deca0, Func Offset: 0x1a0
	// Line 687, Address: 0x2deca4, Func Offset: 0x1a4
	// Line 684, Address: 0x2decac, Func Offset: 0x1ac
	// Line 685, Address: 0x2decb0, Func Offset: 0x1b0
	// Line 687, Address: 0x2decbc, Func Offset: 0x1bc
	// Line 689, Address: 0x2decc8, Func Offset: 0x1c8
	// Line 690, Address: 0x2decd0, Func Offset: 0x1d0
	// Line 691, Address: 0x2dece8, Func Offset: 0x1e8
	// Line 695, Address: 0x2decfc, Func Offset: 0x1fc
	// Func End, Address: 0x2ded1c, Func Offset: 0x21c
}

// 
// Start address: 0x2ded20
void njDrawTexture3DExSetData(_anon3* p, int count)
{
	// Line 773, Address: 0x2ded20, Func Offset: 0
	// Line 774, Address: 0x2ded28, Func Offset: 0x8
	// Line 776, Address: 0x2ded30, Func Offset: 0x10
	// Func End, Address: 0x2ded3c, Func Offset: 0x1c
}

// 
// Start address: 0x2ded40
void njDrawTexture3DExSetData1P(_anon3* p, int count)
{
	// Line 781, Address: 0x2ded40, Func Offset: 0
	// Line 782, Address: 0x2ded48, Func Offset: 0x8
	// Line 784, Address: 0x2ded50, Func Offset: 0x10
	// Func End, Address: 0x2ded5c, Func Offset: 0x1c
}

// 
// Start address: 0x2ded60
void njDrawTexture3DExEnd()
{
	// Line 795, Address: 0x2ded60, Func Offset: 0
	// Func End, Address: 0x2ded68, Func Offset: 0x8
}

// 
// Start address: 0x2ded70
void njDrawTextureSub3DH(_anon0* polygon, int count, int flag)
{
	tagNJS_SCRVECTOR scr;
	unsigned int i;
	float bp[4];
	float buff[4][64];
	float invz;
	// Line 798, Address: 0x2ded70, Func Offset: 0
	// Line 809, Address: 0x2ded90, Func Offset: 0x20
	// Line 811, Address: 0x2deda8, Func Offset: 0x38
	// Line 816, Address: 0x2dedac, Func Offset: 0x3c
	// Line 811, Address: 0x2dedb4, Func Offset: 0x44
	// Line 812, Address: 0x2dedc8, Func Offset: 0x58
	// Line 813, Address: 0x2dede0, Func Offset: 0x70
	// Line 814, Address: 0x2dedf0, Func Offset: 0x80
	// Line 816, Address: 0x2dee04, Func Offset: 0x94
	// Line 817, Address: 0x2dee0c, Func Offset: 0x9c
	// Line 828, Address: 0x2dee10, Func Offset: 0xa0
	// Line 821, Address: 0x2dee14, Func Offset: 0xa4
	// Line 828, Address: 0x2dee18, Func Offset: 0xa8
	// Line 817, Address: 0x2dee1c, Func Offset: 0xac
	// Line 818, Address: 0x2dee20, Func Offset: 0xb0
	// Line 819, Address: 0x2dee28, Func Offset: 0xb8
	// Line 821, Address: 0x2dee30, Func Offset: 0xc0
	// Line 823, Address: 0x2dee34, Func Offset: 0xc4
	// Line 824, Address: 0x2dee38, Func Offset: 0xc8
	// Line 825, Address: 0x2dee44, Func Offset: 0xd4
	// Line 827, Address: 0x2dee4c, Func Offset: 0xdc
	// Line 825, Address: 0x2dee50, Func Offset: 0xe0
	// Line 826, Address: 0x2dee54, Func Offset: 0xe4
	// Line 827, Address: 0x2dee58, Func Offset: 0xe8
	// Line 828, Address: 0x2dee5c, Func Offset: 0xec
	// Line 831, Address: 0x2dee68, Func Offset: 0xf8
	// Line 832, Address: 0x2dee74, Func Offset: 0x104
	// Line 834, Address: 0x2dee88, Func Offset: 0x118
	// Line 835, Address: 0x2dee90, Func Offset: 0x120
	// Line 839, Address: 0x2deea4, Func Offset: 0x134
	// Func End, Address: 0x2deec4, Func Offset: 0x154
}

// 
// Start address: 0x2deed0
void njDrawTexture3DHEx(_anon0* p, int count, int trans)
{
	int i;
	_anon0 poly[4];
	// Line 854, Address: 0x2deed0, Func Offset: 0
	// Line 865, Address: 0x2deee4, Func Offset: 0x14
	// Line 866, Address: 0x2def0c, Func Offset: 0x3c
	// Line 878, Address: 0x2def1c, Func Offset: 0x4c
	// Line 867, Address: 0x2def20, Func Offset: 0x50
	// Line 879, Address: 0x2def24, Func Offset: 0x54
	// Line 867, Address: 0x2def2c, Func Offset: 0x5c
	// Line 868, Address: 0x2def30, Func Offset: 0x60
	// Line 869, Address: 0x2def38, Func Offset: 0x68
	// Line 870, Address: 0x2def40, Func Offset: 0x70
	// Line 871, Address: 0x2def48, Func Offset: 0x78
	// Line 877, Address: 0x2def50, Func Offset: 0x80
	// Line 878, Address: 0x2defa4, Func Offset: 0xd4
	// Line 879, Address: 0x2defac, Func Offset: 0xdc
	// Line 881, Address: 0x2defb8, Func Offset: 0xe8
	// Line 882, Address: 0x2defc8, Func Offset: 0xf8
	// Line 883, Address: 0x2defd0, Func Offset: 0x100
	// Func End, Address: 0x2defe8, Func Offset: 0x118
}

// 
// Start address: 0x2deff0
void njQuadTextureStart(int trans)
{
	// Line 894, Address: 0x2deff0, Func Offset: 0
	// Line 896, Address: 0x2deff8, Func Offset: 0x8
	// Line 897, Address: 0x2df000, Func Offset: 0x10
	// Line 896, Address: 0x2df008, Func Offset: 0x18
	// Line 897, Address: 0x2df010, Func Offset: 0x20
	// Line 898, Address: 0x2df014, Func Offset: 0x24
	// Func End, Address: 0x2df01c, Func Offset: 0x2c
}

// 
// Start address: 0x2df020
void njQuadTextureEnd()
{
	// Line 906, Address: 0x2df020, Func Offset: 0
	// Line 907, Address: 0x2df028, Func Offset: 0x8
	// Line 906, Address: 0x2df030, Func Offset: 0x10
	// Line 907, Address: 0x2df038, Func Offset: 0x18
	// Line 908, Address: 0x2df03c, Func Offset: 0x1c
	// Func End, Address: 0x2df044, Func Offset: 0x24
}

// 
// Start address: 0x2df050
void njSetQuadTexture(int texid, unsigned int col)
{
	// Line 922, Address: 0x2df050, Func Offset: 0
	// Line 923, Address: 0x2df054, Func Offset: 0x4
	// Func End, Address: 0x2df05c, Func Offset: 0xc
}

// 
// Start address: 0x2df060
void njDrawQuadTexture(_anon4* q, float z)
{
	unsigned int rgba;
	float buff[4][6];
	float sz;
	// Line 943, Address: 0x2df060, Func Offset: 0
	// Line 938, Address: 0x2df064, Func Offset: 0x4
	// Line 943, Address: 0x2df068, Func Offset: 0x8
	// Line 944, Address: 0x2df078, Func Offset: 0x18
	// Line 945, Address: 0x2df088, Func Offset: 0x28
	// Line 946, Address: 0x2df0a8, Func Offset: 0x48
	// Line 947, Address: 0x2df0b0, Func Offset: 0x50
	// Line 956, Address: 0x2df0bc, Func Offset: 0x5c
	// Line 954, Address: 0x2df0c0, Func Offset: 0x60
	// Line 958, Address: 0x2df0c8, Func Offset: 0x68
	// Line 977, Address: 0x2df0cc, Func Offset: 0x6c
	// Line 956, Address: 0x2df0d0, Func Offset: 0x70
	// Line 957, Address: 0x2df0d4, Func Offset: 0x74
	// Line 977, Address: 0x2df0d8, Func Offset: 0x78
	// Line 957, Address: 0x2df0e8, Func Offset: 0x88
	// Line 958, Address: 0x2df0ec, Func Offset: 0x8c
	// Line 959, Address: 0x2df0f0, Func Offset: 0x90
	// Line 960, Address: 0x2df0f4, Func Offset: 0x94
	// Line 978, Address: 0x2df0f8, Func Offset: 0x98
	// Line 960, Address: 0x2df108, Func Offset: 0xa8
	// Line 961, Address: 0x2df10c, Func Offset: 0xac
	// Line 979, Address: 0x2df110, Func Offset: 0xb0
	// Line 980, Address: 0x2df11c, Func Offset: 0xbc
	// Line 961, Address: 0x2df120, Func Offset: 0xc0
	// Line 962, Address: 0x2df124, Func Offset: 0xc4
	// Line 980, Address: 0x2df128, Func Offset: 0xc8
	// Line 963, Address: 0x2df12c, Func Offset: 0xcc
	// Line 980, Address: 0x2df130, Func Offset: 0xd0
	// Line 978, Address: 0x2df138, Func Offset: 0xd8
	// Line 977, Address: 0x2df13c, Func Offset: 0xdc
	// Line 983, Address: 0x2df140, Func Offset: 0xe0
	// Line 979, Address: 0x2df148, Func Offset: 0xe8
	// Line 978, Address: 0x2df14c, Func Offset: 0xec
	// Line 980, Address: 0x2df150, Func Offset: 0xf0
	// Line 979, Address: 0x2df154, Func Offset: 0xf4
	// Line 980, Address: 0x2df158, Func Offset: 0xf8
	// Line 983, Address: 0x2df15c, Func Offset: 0xfc
	// Line 984, Address: 0x2df160, Func Offset: 0x100
	// Line 992, Address: 0x2df168, Func Offset: 0x108
	// Line 983, Address: 0x2df174, Func Offset: 0x114
	// Line 984, Address: 0x2df17c, Func Offset: 0x11c
	// Line 985, Address: 0x2df188, Func Offset: 0x128
	// Line 986, Address: 0x2df18c, Func Offset: 0x12c
	// Line 987, Address: 0x2df190, Func Offset: 0x130
	// Line 988, Address: 0x2df19c, Func Offset: 0x13c
	// Line 989, Address: 0x2df1a8, Func Offset: 0x148
	// Line 992, Address: 0x2df1ac, Func Offset: 0x14c
	// Line 993, Address: 0x2df1b4, Func Offset: 0x154
	// Line 995, Address: 0x2df1c8, Func Offset: 0x168
	// Line 996, Address: 0x2df1d0, Func Offset: 0x170
	// Line 999, Address: 0x2df1e4, Func Offset: 0x184
	// Func End, Address: 0x2df1f0, Func Offset: 0x190
}

