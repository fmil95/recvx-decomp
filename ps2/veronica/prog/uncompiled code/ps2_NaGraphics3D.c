typedef union _anon0;
typedef struct _anon1;
typedef struct tagVU1_STRIP_BUF;
typedef struct _anon2;
typedef struct _anon3;
typedef struct tagNJS_SCRVECTOR;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;


typedef float type_0[4][96];
typedef float type_1[4];
typedef float type_2[4][32];
typedef float type_3[4][4];
typedef _anon1 type_4[5];
typedef float type_5[4][32];
typedef float type_6[4][2];
typedef float type_7[4][64];
typedef tagVU1_STRIP_BUF type_8[256];

union _anon0
{
	unsigned int color;
	_anon5 tex;
	_anon6 argb;
};

struct _anon1
{
	float norm[4];
	float pos[4];
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

struct _anon2
{
	_anon3* p;
	_anon0* col;
	_anon0* tex;
	unsigned int num;
};

struct _anon3
{
	float x;
	float y;
	float z;
};

struct tagNJS_SCRVECTOR
{
	float x;
	float y;
	float z;
	float iz;
	float fog;
};

struct _anon4
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};

struct _anon5
{
	short u;
	short v;
};

struct _anon6
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

_anon1 sc_plane;
_anon1 c_plane[5];
_anon4 _nj_screen_;

void Ps2SetPlane(_anon1* p, float* v0, float* v1, float* v2);
void Ps2CalcScreenCone();
float Calc_Intersection2(float* v0, float* v1, _anon1* plane);
int CalcIntersectionCone(float* ans, float* v0, float* v1);
float Head_or_Tail(float* v);
float Across_Plane(float* v0, float* v1);
void njDrawLine3D(_anon2* p, int n, unsigned int attr);
void njDrawLine3DEx(_anon2* p, int n, unsigned int attr);
void njDrawTriangle3D(_anon2* p, int n, unsigned int attr);
void njDrawPolygon3D(_anon2* p, int n, unsigned int attr);

// 
// Start address: 0x2dfa00
void Ps2SetPlane(_anon1* p, float* v0, float* v1, float* v2)
{
	float tmp1[4];
	float tmp0[4];
	// Line 64, Address: 0x2dfa00, Func Offset: 0
	// Line 67, Address: 0x2dfa14, Func Offset: 0x14
	// Line 68, Address: 0x2dfa2c, Func Offset: 0x2c
	// Line 69, Address: 0x2dfa3c, Func Offset: 0x3c
	// Line 70, Address: 0x2dfa4c, Func Offset: 0x4c
	// Line 71, Address: 0x2dfa58, Func Offset: 0x58
	// Line 72, Address: 0x2dfa64, Func Offset: 0x64
	// Func End, Address: 0x2dfa78, Func Offset: 0x78
}

// 
// Start address: 0x2dfa80
void Ps2CalcScreenCone()
{
	float cp[4];
	float pos[4][4];
	// Line 76, Address: 0x2dfa80, Func Offset: 0
	// Line 83, Address: 0x2dfa84, Func Offset: 0x4
	// Line 76, Address: 0x2dfa8c, Func Offset: 0xc
	// Line 83, Address: 0x2dfa90, Func Offset: 0x10
	// Line 85, Address: 0x2dfa9c, Func Offset: 0x1c
	// Line 83, Address: 0x2dfaa0, Func Offset: 0x20
	// Line 85, Address: 0x2dfaa4, Func Offset: 0x24
	// Line 83, Address: 0x2dfaa8, Func Offset: 0x28
	// Line 85, Address: 0x2dfaac, Func Offset: 0x2c
	// Line 83, Address: 0x2dfabc, Func Offset: 0x3c
	// Line 85, Address: 0x2dfac0, Func Offset: 0x40
	// Line 86, Address: 0x2dfac8, Func Offset: 0x48
	// Line 87, Address: 0x2dfae8, Func Offset: 0x68
	// Line 88, Address: 0x2dfb08, Func Offset: 0x88
	// Line 89, Address: 0x2dfb28, Func Offset: 0xa8
	// Func End, Address: 0x2dfb34, Func Offset: 0xb4
}

// 
// Start address: 0x2dfb40
float Calc_Intersection2(float* v0, float* v1, _anon1* plane)
{
	float tmpf;
	float tmp1[4];
	float tmp0[4];
	// Line 112, Address: 0x2dfb40, Func Offset: 0
	// Line 116, Address: 0x2dfb60, Func Offset: 0x20
	// Line 117, Address: 0x2dfb74, Func Offset: 0x34
	// Line 118, Address: 0x2dfb84, Func Offset: 0x44
	// Line 119, Address: 0x2dfb94, Func Offset: 0x54
	// Line 121, Address: 0x2dfbd8, Func Offset: 0x98
	// Func End, Address: 0x2dfbf4, Func Offset: 0xb4
}

// 
// Start address: 0x2dfc00
int CalcIntersectionCone(float* ans, float* v0, float* v1)
{
	float f;
	float tmpf;
	float tmp1[4];
	int i;
	// Line 125, Address: 0x2dfc00, Func Offset: 0
	// Line 128, Address: 0x2dfc1c, Func Offset: 0x1c
	// Line 125, Address: 0x2dfc24, Func Offset: 0x24
	// Line 128, Address: 0x2dfc28, Func Offset: 0x28
	// Line 130, Address: 0x2dfc38, Func Offset: 0x38
	// Line 131, Address: 0x2dfc50, Func Offset: 0x50
	// Line 132, Address: 0x2dfc54, Func Offset: 0x54
	// Line 133, Address: 0x2dfc64, Func Offset: 0x64
	// Line 134, Address: 0x2dfc90, Func Offset: 0x90
	// Line 135, Address: 0x2dfca0, Func Offset: 0xa0
	// Line 136, Address: 0x2dfcb0, Func Offset: 0xb0
	// Line 137, Address: 0x2dfcc0, Func Offset: 0xc0
	// Func End, Address: 0x2dfce4, Func Offset: 0xe4
}

// 
// Start address: 0x2dfcf0
float Head_or_Tail(float* v)
{
	float tmp[4];
	_anon1 p;
	// Line 141, Address: 0x2dfcf0, Func Offset: 0
	// Line 144, Address: 0x2dfd04, Func Offset: 0x14
	// Line 141, Address: 0x2dfd08, Func Offset: 0x18
	// Line 144, Address: 0x2dfd0c, Func Offset: 0x1c
	// Line 145, Address: 0x2dfd18, Func Offset: 0x28
	// Line 146, Address: 0x2dfd24, Func Offset: 0x34
	// Func End, Address: 0x2dfd30, Func Offset: 0x40
}

// 
// Start address: 0x2dfd30
float Across_Plane(float* v0, float* v1)
{
	float tmp1[4];
	float tmp0[4];
	_anon1 p;
	// Line 150, Address: 0x2dfd30, Func Offset: 0
	// Line 153, Address: 0x2dfd50, Func Offset: 0x20
	// Line 150, Address: 0x2dfd58, Func Offset: 0x28
	// Line 153, Address: 0x2dfd5c, Func Offset: 0x2c
	// Line 154, Address: 0x2dfd6c, Func Offset: 0x3c
	// Line 155, Address: 0x2dfd7c, Func Offset: 0x4c
	// Line 156, Address: 0x2dfd9c, Func Offset: 0x6c
	// Func End, Address: 0x2dfdb4, Func Offset: 0x84
}

// 
// Start address: 0x2dfdc0
void njDrawLine3D(_anon2* p, int n, unsigned int attr)
{
	tagNJS_SCRVECTOR scr;
	unsigned long prim;
	unsigned int i;
	float bp[4];
	float buff[4][32];
	float invz;
	// Line 173, Address: 0x2dfdc0, Func Offset: 0
	// Line 180, Address: 0x2dfdec, Func Offset: 0x2c
	// Line 173, Address: 0x2dfdf0, Func Offset: 0x30
	// Line 180, Address: 0x2dfdfc, Func Offset: 0x3c
	// Line 181, Address: 0x2dfe04, Func Offset: 0x44
	// Line 182, Address: 0x2dfe08, Func Offset: 0x48
	// Line 189, Address: 0x2dfe0c, Func Offset: 0x4c
	// Line 182, Address: 0x2dfe14, Func Offset: 0x54
	// Line 189, Address: 0x2dfe18, Func Offset: 0x58
	// Line 191, Address: 0x2dfe30, Func Offset: 0x70
	// Line 196, Address: 0x2dfe34, Func Offset: 0x74
	// Line 191, Address: 0x2dfe38, Func Offset: 0x78
	// Line 192, Address: 0x2dfe44, Func Offset: 0x84
	// Line 193, Address: 0x2dfe54, Func Offset: 0x94
	// Line 194, Address: 0x2dfe64, Func Offset: 0xa4
	// Line 196, Address: 0x2dfe74, Func Offset: 0xb4
	// Line 197, Address: 0x2dfe80, Func Offset: 0xc0
	// Line 198, Address: 0x2dfe88, Func Offset: 0xc8
	// Line 199, Address: 0x2dfe90, Func Offset: 0xd0
	// Line 200, Address: 0x2dfe98, Func Offset: 0xd8
	// Line 203, Address: 0x2dfea0, Func Offset: 0xe0
	// Line 204, Address: 0x2dfea8, Func Offset: 0xe8
	// Line 208, Address: 0x2dfeac, Func Offset: 0xec
	// Line 204, Address: 0x2dfeb4, Func Offset: 0xf4
	// Line 205, Address: 0x2dfec4, Func Offset: 0x104
	// Line 206, Address: 0x2dfed8, Func Offset: 0x118
	// Line 208, Address: 0x2dfedc, Func Offset: 0x11c
	// Line 209, Address: 0x2dfee4, Func Offset: 0x124
	// Line 210, Address: 0x2dfef0, Func Offset: 0x130
	// Line 212, Address: 0x2dfefc, Func Offset: 0x13c
	// Line 213, Address: 0x2dff04, Func Offset: 0x144
	// Line 214, Address: 0x2dff08, Func Offset: 0x148
	// Line 215, Address: 0x2dff0c, Func Offset: 0x14c
	// Line 216, Address: 0x2dff10, Func Offset: 0x150
	// Line 217, Address: 0x2dff14, Func Offset: 0x154
	// Line 218, Address: 0x2dff18, Func Offset: 0x158
	// Line 216, Address: 0x2dff1c, Func Offset: 0x15c
	// Line 218, Address: 0x2dff24, Func Offset: 0x164
	// Line 219, Address: 0x2dff30, Func Offset: 0x170
	// Line 220, Address: 0x2dff38, Func Offset: 0x178
	// Line 221, Address: 0x2dff3c, Func Offset: 0x17c
	// Line 228, Address: 0x2dff44, Func Offset: 0x184
	// Line 221, Address: 0x2dff4c, Func Offset: 0x18c
	// Line 228, Address: 0x2dff50, Func Offset: 0x190
	// Line 230, Address: 0x2dff68, Func Offset: 0x1a8
	// Line 235, Address: 0x2dff6c, Func Offset: 0x1ac
	// Line 230, Address: 0x2dff70, Func Offset: 0x1b0
	// Line 231, Address: 0x2dff7c, Func Offset: 0x1bc
	// Line 232, Address: 0x2dff8c, Func Offset: 0x1cc
	// Line 233, Address: 0x2dff9c, Func Offset: 0x1dc
	// Line 235, Address: 0x2dffac, Func Offset: 0x1ec
	// Line 236, Address: 0x2dffb8, Func Offset: 0x1f8
	// Line 237, Address: 0x2dffc0, Func Offset: 0x200
	// Line 238, Address: 0x2dffc8, Func Offset: 0x208
	// Line 239, Address: 0x2dffd0, Func Offset: 0x210
	// Line 242, Address: 0x2dffd8, Func Offset: 0x218
	// Line 243, Address: 0x2dffe0, Func Offset: 0x220
	// Line 247, Address: 0x2dffe4, Func Offset: 0x224
	// Line 243, Address: 0x2dffec, Func Offset: 0x22c
	// Line 244, Address: 0x2dfffc, Func Offset: 0x23c
	// Line 245, Address: 0x2e0010, Func Offset: 0x250
	// Line 247, Address: 0x2e0014, Func Offset: 0x254
	// Line 248, Address: 0x2e001c, Func Offset: 0x25c
	// Line 249, Address: 0x2e0028, Func Offset: 0x268
	// Line 251, Address: 0x2e0034, Func Offset: 0x274
	// Line 252, Address: 0x2e003c, Func Offset: 0x27c
	// Line 253, Address: 0x2e0040, Func Offset: 0x280
	// Line 254, Address: 0x2e0044, Func Offset: 0x284
	// Line 255, Address: 0x2e0048, Func Offset: 0x288
	// Line 256, Address: 0x2e004c, Func Offset: 0x28c
	// Line 257, Address: 0x2e0050, Func Offset: 0x290
	// Line 255, Address: 0x2e0054, Func Offset: 0x294
	// Line 257, Address: 0x2e005c, Func Offset: 0x29c
	// Line 259, Address: 0x2e0068, Func Offset: 0x2a8
	// Line 260, Address: 0x2e0080, Func Offset: 0x2c0
	// Line 262, Address: 0x2e009c, Func Offset: 0x2dc
	// Line 263, Address: 0x2e00ac, Func Offset: 0x2ec
	// Func End, Address: 0x2e00e0, Func Offset: 0x320
}

// 
// Start address: 0x2e00e0
void njDrawLine3DEx(_anon2* p, int n, unsigned int attr)
{
	tagNJS_SCRVECTOR scr;
	unsigned long prim;
	unsigned int i;
	float ans[4];
	float pos[4][2];
	float bp[4];
	float buff[4][32];
	float invz;
	// Line 280, Address: 0x2e00e0, Func Offset: 0
	// Line 287, Address: 0x2e010c, Func Offset: 0x2c
	// Line 280, Address: 0x2e0110, Func Offset: 0x30
	// Line 287, Address: 0x2e011c, Func Offset: 0x3c
	// Line 288, Address: 0x2e0124, Func Offset: 0x44
	// Line 289, Address: 0x2e0128, Func Offset: 0x48
	// Line 296, Address: 0x2e0130, Func Offset: 0x50
	// Line 289, Address: 0x2e0138, Func Offset: 0x58
	// Line 296, Address: 0x2e013c, Func Offset: 0x5c
	// Line 298, Address: 0x2e0158, Func Offset: 0x78
	// Line 303, Address: 0x2e015c, Func Offset: 0x7c
	// Line 298, Address: 0x2e0160, Func Offset: 0x80
	// Line 299, Address: 0x2e016c, Func Offset: 0x8c
	// Line 300, Address: 0x2e017c, Func Offset: 0x9c
	// Line 301, Address: 0x2e018c, Func Offset: 0xac
	// Line 303, Address: 0x2e019c, Func Offset: 0xbc
	// Line 304, Address: 0x2e01a8, Func Offset: 0xc8
	// Line 305, Address: 0x2e01b0, Func Offset: 0xd0
	// Line 306, Address: 0x2e01b8, Func Offset: 0xd8
	// Line 307, Address: 0x2e01c0, Func Offset: 0xe0
	// Line 310, Address: 0x2e01c8, Func Offset: 0xe8
	// Line 311, Address: 0x2e01d0, Func Offset: 0xf0
	// Line 315, Address: 0x2e01d4, Func Offset: 0xf4
	// Line 311, Address: 0x2e01dc, Func Offset: 0xfc
	// Line 312, Address: 0x2e01ec, Func Offset: 0x10c
	// Line 313, Address: 0x2e0200, Func Offset: 0x120
	// Line 315, Address: 0x2e0204, Func Offset: 0x124
	// Line 316, Address: 0x2e020c, Func Offset: 0x12c
	// Line 317, Address: 0x2e0218, Func Offset: 0x138
	// Line 319, Address: 0x2e0224, Func Offset: 0x144
	// Line 320, Address: 0x2e022c, Func Offset: 0x14c
	// Line 321, Address: 0x2e0230, Func Offset: 0x150
	// Line 322, Address: 0x2e0234, Func Offset: 0x154
	// Line 323, Address: 0x2e0238, Func Offset: 0x158
	// Line 324, Address: 0x2e023c, Func Offset: 0x15c
	// Line 325, Address: 0x2e0240, Func Offset: 0x160
	// Line 323, Address: 0x2e0244, Func Offset: 0x164
	// Line 325, Address: 0x2e024c, Func Offset: 0x16c
	// Line 326, Address: 0x2e0258, Func Offset: 0x178
	// Line 328, Address: 0x2e0260, Func Offset: 0x180
	// Line 327, Address: 0x2e0264, Func Offset: 0x184
	// Line 328, Address: 0x2e0268, Func Offset: 0x188
	// Line 335, Address: 0x2e0270, Func Offset: 0x190
	// Line 328, Address: 0x2e0278, Func Offset: 0x198
	// Line 335, Address: 0x2e027c, Func Offset: 0x19c
	// Line 336, Address: 0x2e029c, Func Offset: 0x1bc
	// Line 337, Address: 0x2e02a8, Func Offset: 0x1c8
	// Line 338, Address: 0x2e02b8, Func Offset: 0x1d8
	// Line 339, Address: 0x2e02cc, Func Offset: 0x1ec
	// Line 341, Address: 0x2e02d0, Func Offset: 0x1f0
	// Line 347, Address: 0x2e02d4, Func Offset: 0x1f4
	// Line 341, Address: 0x2e02e0, Func Offset: 0x200
	// Line 347, Address: 0x2e02e8, Func Offset: 0x208
	// Line 341, Address: 0x2e02ec, Func Offset: 0x20c
	// Line 342, Address: 0x2e02f0, Func Offset: 0x210
	// Line 343, Address: 0x2e0300, Func Offset: 0x220
	// Line 344, Address: 0x2e0310, Func Offset: 0x230
	// Line 347, Address: 0x2e031c, Func Offset: 0x23c
	// Line 348, Address: 0x2e033c, Func Offset: 0x25c
	// Line 349, Address: 0x2e0344, Func Offset: 0x264
	// Line 351, Address: 0x2e036c, Func Offset: 0x28c
	// Line 352, Address: 0x2e037c, Func Offset: 0x29c
	// Line 353, Address: 0x2e0380, Func Offset: 0x2a0
	// Line 354, Address: 0x2e0384, Func Offset: 0x2a4
	// Line 355, Address: 0x2e0388, Func Offset: 0x2a8
	// Line 352, Address: 0x2e038c, Func Offset: 0x2ac
	// Line 353, Address: 0x2e0390, Func Offset: 0x2b0
	// Line 355, Address: 0x2e0394, Func Offset: 0x2b4
	// Line 356, Address: 0x2e039c, Func Offset: 0x2bc
	// Line 358, Address: 0x2e03a4, Func Offset: 0x2c4
	// Line 360, Address: 0x2e03cc, Func Offset: 0x2ec
	// Line 361, Address: 0x2e03dc, Func Offset: 0x2fc
	// Line 362, Address: 0x2e03e0, Func Offset: 0x300
	// Line 363, Address: 0x2e03e4, Func Offset: 0x304
	// Line 364, Address: 0x2e03e8, Func Offset: 0x308
	// Line 361, Address: 0x2e03ec, Func Offset: 0x30c
	// Line 362, Address: 0x2e03f0, Func Offset: 0x310
	// Line 364, Address: 0x2e03f4, Func Offset: 0x314
	// Line 365, Address: 0x2e03fc, Func Offset: 0x31c
	// Line 369, Address: 0x2e0404, Func Offset: 0x324
	// Line 370, Address: 0x2e0414, Func Offset: 0x334
	// Line 374, Address: 0x2e0418, Func Offset: 0x338
	// Line 375, Address: 0x2e0420, Func Offset: 0x340
	// Line 376, Address: 0x2e0428, Func Offset: 0x348
	// Line 377, Address: 0x2e0430, Func Offset: 0x350
	// Line 380, Address: 0x2e0438, Func Offset: 0x358
	// Line 381, Address: 0x2e0440, Func Offset: 0x360
	// Line 385, Address: 0x2e0444, Func Offset: 0x364
	// Line 381, Address: 0x2e044c, Func Offset: 0x36c
	// Line 382, Address: 0x2e045c, Func Offset: 0x37c
	// Line 383, Address: 0x2e0470, Func Offset: 0x390
	// Line 385, Address: 0x2e0474, Func Offset: 0x394
	// Line 386, Address: 0x2e047c, Func Offset: 0x39c
	// Line 387, Address: 0x2e0488, Func Offset: 0x3a8
	// Line 389, Address: 0x2e0494, Func Offset: 0x3b4
	// Line 390, Address: 0x2e049c, Func Offset: 0x3bc
	// Line 391, Address: 0x2e04a0, Func Offset: 0x3c0
	// Line 392, Address: 0x2e04a4, Func Offset: 0x3c4
	// Line 393, Address: 0x2e04a8, Func Offset: 0x3c8
	// Line 394, Address: 0x2e04ac, Func Offset: 0x3cc
	// Line 395, Address: 0x2e04b0, Func Offset: 0x3d0
	// Line 393, Address: 0x2e04b4, Func Offset: 0x3d4
	// Line 395, Address: 0x2e04bc, Func Offset: 0x3dc
	// Line 397, Address: 0x2e04c8, Func Offset: 0x3e8
	// Line 398, Address: 0x2e04ec, Func Offset: 0x40c
	// Line 400, Address: 0x2e0514, Func Offset: 0x434
	// Line 401, Address: 0x2e0524, Func Offset: 0x444
	// Func End, Address: 0x2e0558, Func Offset: 0x478
}

// 
// Start address: 0x2e0560
void njDrawTriangle3D(_anon2* p, int n, unsigned int attr)
{
	tagNJS_SCRVECTOR scr;
	unsigned long prim;
	unsigned int i;
	float bp[4];
	float buff[4][96];
	float invz;
	// Line 417, Address: 0x2e0560, Func Offset: 0
	// Line 424, Address: 0x2e058c, Func Offset: 0x2c
	// Line 417, Address: 0x2e0590, Func Offset: 0x30
	// Line 424, Address: 0x2e059c, Func Offset: 0x3c
	// Line 426, Address: 0x2e05a4, Func Offset: 0x44
	// Line 425, Address: 0x2e05a8, Func Offset: 0x48
	// Line 427, Address: 0x2e05ac, Func Offset: 0x4c
	// Line 428, Address: 0x2e05b4, Func Offset: 0x54
	// Line 429, Address: 0x2e05bc, Func Offset: 0x5c
	// Line 438, Address: 0x2e05c8, Func Offset: 0x68
	// Line 446, Address: 0x2e05e8, Func Offset: 0x88
	// Line 452, Address: 0x2e05ec, Func Offset: 0x8c
	// Line 446, Address: 0x2e05f0, Func Offset: 0x90
	// Line 447, Address: 0x2e0600, Func Offset: 0xa0
	// Line 448, Address: 0x2e0614, Func Offset: 0xb4
	// Line 449, Address: 0x2e0628, Func Offset: 0xc8
	// Line 452, Address: 0x2e063c, Func Offset: 0xdc
	// Line 453, Address: 0x2e0648, Func Offset: 0xe8
	// Line 454, Address: 0x2e0650, Func Offset: 0xf0
	// Line 455, Address: 0x2e0658, Func Offset: 0xf8
	// Line 456, Address: 0x2e0660, Func Offset: 0x100
	// Line 459, Address: 0x2e0668, Func Offset: 0x108
	// Line 460, Address: 0x2e0670, Func Offset: 0x110
	// Line 464, Address: 0x2e0674, Func Offset: 0x114
	// Line 460, Address: 0x2e067c, Func Offset: 0x11c
	// Line 461, Address: 0x2e068c, Func Offset: 0x12c
	// Line 462, Address: 0x2e06a0, Func Offset: 0x140
	// Line 464, Address: 0x2e06a4, Func Offset: 0x144
	// Line 465, Address: 0x2e06ac, Func Offset: 0x14c
	// Line 466, Address: 0x2e06b8, Func Offset: 0x158
	// Line 468, Address: 0x2e06c4, Func Offset: 0x164
	// Line 469, Address: 0x2e06cc, Func Offset: 0x16c
	// Line 470, Address: 0x2e06d0, Func Offset: 0x170
	// Line 471, Address: 0x2e06d4, Func Offset: 0x174
	// Line 472, Address: 0x2e06d8, Func Offset: 0x178
	// Line 473, Address: 0x2e06dc, Func Offset: 0x17c
	// Line 474, Address: 0x2e06e0, Func Offset: 0x180
	// Line 472, Address: 0x2e06e4, Func Offset: 0x184
	// Line 474, Address: 0x2e06ec, Func Offset: 0x18c
	// Line 475, Address: 0x2e06f8, Func Offset: 0x198
	// Line 476, Address: 0x2e0710, Func Offset: 0x1b0
	// Line 478, Address: 0x2e072c, Func Offset: 0x1cc
	// Line 479, Address: 0x2e073c, Func Offset: 0x1dc
	// Func End, Address: 0x2e0770, Func Offset: 0x210
}

// 
// Start address: 0x2e0770
void njDrawPolygon3D(_anon2* p, int n, unsigned int attr)
{
	tagVU1_STRIP_BUF* vp;
	tagNJS_SCRVECTOR scr;
	unsigned long prim;
	unsigned int i;
	float bp[4];
	float buff[4][64];
	float invz;
	tagVU1_STRIP_BUF vb[256];
	// Line 496, Address: 0x2e0770, Func Offset: 0
	// Line 507, Address: 0x2e079c, Func Offset: 0x2c
	// Line 496, Address: 0x2e07a0, Func Offset: 0x30
	// Line 507, Address: 0x2e07ac, Func Offset: 0x3c
	// Line 508, Address: 0x2e07b4, Func Offset: 0x44
	// Line 509, Address: 0x2e07c0, Func Offset: 0x50
	// Line 519, Address: 0x2e07c8, Func Offset: 0x58
	// Line 520, Address: 0x2e07d4, Func Offset: 0x64
	// Line 521, Address: 0x2e07dc, Func Offset: 0x6c
	// Line 528, Address: 0x2e0800, Func Offset: 0x90
	// Line 529, Address: 0x2e0850, Func Offset: 0xe0
	// Line 530, Address: 0x2e08a0, Func Offset: 0x130
	// Line 532, Address: 0x2e08f0, Func Offset: 0x180
	// Line 535, Address: 0x2e0934, Func Offset: 0x1c4
	// Line 532, Address: 0x2e0938, Func Offset: 0x1c8
	// Line 535, Address: 0x2e093c, Func Offset: 0x1cc
	// Line 532, Address: 0x2e0940, Func Offset: 0x1d0
	// Line 535, Address: 0x2e0944, Func Offset: 0x1d4
	// Line 549, Address: 0x2e0950, Func Offset: 0x1e0
	// Line 550, Address: 0x2e0958, Func Offset: 0x1e8
	// Line 551, Address: 0x2e0980, Func Offset: 0x210
	// Line 553, Address: 0x2e09a0, Func Offset: 0x230
	// Line 551, Address: 0x2e09a4, Func Offset: 0x234
	// Line 553, Address: 0x2e09ac, Func Offset: 0x23c
	// Line 554, Address: 0x2e09b8, Func Offset: 0x248
	// Line 555, Address: 0x2e09d0, Func Offset: 0x260
	// Line 557, Address: 0x2e09ec, Func Offset: 0x27c
	// Line 558, Address: 0x2e0a04, Func Offset: 0x294
	// Line 559, Address: 0x2e0a0c, Func Offset: 0x29c
	// Line 560, Address: 0x2e0a14, Func Offset: 0x2a4
	// Line 559, Address: 0x2e0a1c, Func Offset: 0x2ac
	// Line 560, Address: 0x2e0a20, Func Offset: 0x2b0
	// Line 562, Address: 0x2e0a38, Func Offset: 0x2c8
	// Line 567, Address: 0x2e0a3c, Func Offset: 0x2cc
	// Line 562, Address: 0x2e0a40, Func Offset: 0x2d0
	// Line 563, Address: 0x2e0a4c, Func Offset: 0x2dc
	// Line 564, Address: 0x2e0a5c, Func Offset: 0x2ec
	// Line 565, Address: 0x2e0a6c, Func Offset: 0x2fc
	// Line 567, Address: 0x2e0a7c, Func Offset: 0x30c
	// Line 568, Address: 0x2e0a88, Func Offset: 0x318
	// Line 569, Address: 0x2e0a90, Func Offset: 0x320
	// Line 570, Address: 0x2e0a98, Func Offset: 0x328
	// Line 571, Address: 0x2e0aa0, Func Offset: 0x330
	// Line 574, Address: 0x2e0aa8, Func Offset: 0x338
	// Line 575, Address: 0x2e0ab0, Func Offset: 0x340
	// Line 579, Address: 0x2e0ab4, Func Offset: 0x344
	// Line 575, Address: 0x2e0abc, Func Offset: 0x34c
	// Line 576, Address: 0x2e0acc, Func Offset: 0x35c
	// Line 577, Address: 0x2e0ae0, Func Offset: 0x370
	// Line 579, Address: 0x2e0ae4, Func Offset: 0x374
	// Line 580, Address: 0x2e0aec, Func Offset: 0x37c
	// Line 581, Address: 0x2e0af8, Func Offset: 0x388
	// Line 583, Address: 0x2e0b04, Func Offset: 0x394
	// Line 584, Address: 0x2e0b0c, Func Offset: 0x39c
	// Line 585, Address: 0x2e0b10, Func Offset: 0x3a0
	// Line 586, Address: 0x2e0b14, Func Offset: 0x3a4
	// Line 587, Address: 0x2e0b18, Func Offset: 0x3a8
	// Line 588, Address: 0x2e0b1c, Func Offset: 0x3ac
	// Line 589, Address: 0x2e0b20, Func Offset: 0x3b0
	// Line 587, Address: 0x2e0b24, Func Offset: 0x3b4
	// Line 589, Address: 0x2e0b2c, Func Offset: 0x3bc
	// Line 590, Address: 0x2e0b38, Func Offset: 0x3c8
	// Line 591, Address: 0x2e0b50, Func Offset: 0x3e0
	// Line 592, Address: 0x2e0b6c, Func Offset: 0x3fc
	// Line 594, Address: 0x2e0b7c, Func Offset: 0x40c
	// Func End, Address: 0x2e0bb0, Func Offset: 0x440
}

