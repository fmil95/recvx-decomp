typedef union _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;


typedef float type_0[4][32];
typedef float type_1[4][32];
typedef float type_2[4];
typedef float type_3[4][32];

union _anon0
{
	unsigned int color;
	_anon3 tex;
	_anon4 argb;
};

struct _anon1
{
	float x;
	float y;
};

struct _anon2
{
	_anon1* p;
	_anon0* col;
	_anon0* tex;
	unsigned int num;
};

struct _anon3
{
	short u;
	short v;
};

struct _anon4
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

float Ps2_zbuff_b;
float Ps2_zbuff_a;
float fNaViwClipFar;
float fNaViwClipNear;

void CalcPs2ZbuffAB();
void sceVu0ITOF12Vector(float* v0, float* v1);
void njDrawLine2D(_anon2* p, int n, float pri, unsigned int attr);
void njDrawPolygon2D(_anon2* p, int n, float pri, unsigned int attr);
void njDrawPolygon2DM(_anon2* p, int n, float pri, unsigned int attr);

// 
// Start address: 0x2df1f0
void CalcPs2ZbuffAB()
{
	// Line 35, Address: 0x2df1f0, Func Offset: 0
	// Line 36, Address: 0x2df200, Func Offset: 0x10
	// Line 35, Address: 0x2df208, Func Offset: 0x18
	// Line 36, Address: 0x2df210, Func Offset: 0x20
	// Line 35, Address: 0x2df214, Func Offset: 0x24
	// Line 36, Address: 0x2df220, Func Offset: 0x30
	// Line 35, Address: 0x2df224, Func Offset: 0x34
	// Line 36, Address: 0x2df228, Func Offset: 0x38
	// Line 35, Address: 0x2df22c, Func Offset: 0x3c
	// Line 36, Address: 0x2df230, Func Offset: 0x40
	// Line 37, Address: 0x2df238, Func Offset: 0x48
	// Func End, Address: 0x2df240, Func Offset: 0x50
}

// 
// Start address: 0x2df240
void sceVu0ITOF12Vector(float* v0, float* v1)
{
	// Line 66, Address: 0x2df240, Func Offset: 0
	// Line 67, Address: 0x2df244, Func Offset: 0x4
	// Line 70, Address: 0x2df248, Func Offset: 0x8
	// Func End, Address: 0x2df250, Func Offset: 0x10
}

// 
// Start address: 0x2df250
void njDrawLine2D(_anon2* p, int n, float pri, unsigned int attr)
{
	unsigned long prim;
	unsigned int i;
	float bp[4];
	float buff[4][32];
	// Line 73, Address: 0x2df250, Func Offset: 0
	// Line 78, Address: 0x2df280, Func Offset: 0x30
	// Line 80, Address: 0x2df298, Func Offset: 0x48
	// Line 79, Address: 0x2df29c, Func Offset: 0x4c
	// Line 81, Address: 0x2df2a0, Func Offset: 0x50
	// Line 83, Address: 0x2df2a8, Func Offset: 0x58
	// Line 82, Address: 0x2df2b0, Func Offset: 0x60
	// Line 83, Address: 0x2df2b4, Func Offset: 0x64
	// Line 92, Address: 0x2df2b8, Func Offset: 0x68
	// Line 94, Address: 0x2df2d8, Func Offset: 0x88
	// Line 95, Address: 0x2df2e0, Func Offset: 0x90
	// Line 97, Address: 0x2df2e4, Func Offset: 0x94
	// Line 99, Address: 0x2df2e8, Func Offset: 0x98
	// Line 95, Address: 0x2df2f0, Func Offset: 0xa0
	// Line 96, Address: 0x2df300, Func Offset: 0xb0
	// Line 97, Address: 0x2df314, Func Offset: 0xc4
	// Line 99, Address: 0x2df318, Func Offset: 0xc8
	// Line 100, Address: 0x2df320, Func Offset: 0xd0
	// Line 101, Address: 0x2df328, Func Offset: 0xd8
	// Line 102, Address: 0x2df32c, Func Offset: 0xdc
	// Line 103, Address: 0x2df330, Func Offset: 0xe0
	// Line 104, Address: 0x2df334, Func Offset: 0xe4
	// Line 112, Address: 0x2df338, Func Offset: 0xe8
	// Line 107, Address: 0x2df340, Func Offset: 0xf0
	// Line 113, Address: 0x2df344, Func Offset: 0xf4
	// Line 116, Address: 0x2df34c, Func Offset: 0xfc
	// Line 107, Address: 0x2df350, Func Offset: 0x100
	// Line 108, Address: 0x2df35c, Func Offset: 0x10c
	// Line 116, Address: 0x2df360, Func Offset: 0x110
	// Line 108, Address: 0x2df364, Func Offset: 0x114
	// Line 109, Address: 0x2df370, Func Offset: 0x120
	// Line 110, Address: 0x2df380, Func Offset: 0x130
	// Line 115, Address: 0x2df38c, Func Offset: 0x13c
	// Line 110, Address: 0x2df390, Func Offset: 0x140
	// Line 112, Address: 0x2df39c, Func Offset: 0x14c
	// Line 113, Address: 0x2df3b0, Func Offset: 0x160
	// Line 115, Address: 0x2df3bc, Func Offset: 0x16c
	// Line 113, Address: 0x2df3c0, Func Offset: 0x170
	// Line 114, Address: 0x2df3c8, Func Offset: 0x178
	// Line 115, Address: 0x2df3cc, Func Offset: 0x17c
	// Line 116, Address: 0x2df3d0, Func Offset: 0x180
	// Line 118, Address: 0x2df3d8, Func Offset: 0x188
	// Line 120, Address: 0x2df3f0, Func Offset: 0x1a0
	// Line 121, Address: 0x2df40c, Func Offset: 0x1bc
	// Line 122, Address: 0x2df41c, Func Offset: 0x1cc
	// Func End, Address: 0x2df450, Func Offset: 0x200
}

// 
// Start address: 0x2df450
void njDrawPolygon2D(_anon2* p, int n, float pri, unsigned int attr)
{
	unsigned long prim;
	unsigned int i;
	float bp[4];
	float buff[4][32];
	// Line 141, Address: 0x2df450, Func Offset: 0
	// Line 153, Address: 0x2df478, Func Offset: 0x28
	// Line 141, Address: 0x2df47c, Func Offset: 0x2c
	// Line 153, Address: 0x2df480, Func Offset: 0x30
	// Line 154, Address: 0x2df49c, Func Offset: 0x4c
	// Line 156, Address: 0x2df4a0, Func Offset: 0x50
	// Line 158, Address: 0x2df4c0, Func Offset: 0x70
	// Line 161, Address: 0x2df4c8, Func Offset: 0x78
	// Line 164, Address: 0x2df4cc, Func Offset: 0x7c
	// Line 166, Address: 0x2df4d0, Func Offset: 0x80
	// Line 161, Address: 0x2df4d8, Func Offset: 0x88
	// Line 162, Address: 0x2df4ec, Func Offset: 0x9c
	// Line 164, Address: 0x2df504, Func Offset: 0xb4
	// Line 166, Address: 0x2df508, Func Offset: 0xb8
	// Line 167, Address: 0x2df510, Func Offset: 0xc0
	// Line 168, Address: 0x2df518, Func Offset: 0xc8
	// Line 169, Address: 0x2df51c, Func Offset: 0xcc
	// Line 170, Address: 0x2df520, Func Offset: 0xd0
	// Line 171, Address: 0x2df524, Func Offset: 0xd4
	// Line 174, Address: 0x2df528, Func Offset: 0xd8
	// Line 175, Address: 0x2df530, Func Offset: 0xe0
	// Line 176, Address: 0x2df544, Func Offset: 0xf4
	// Line 177, Address: 0x2df558, Func Offset: 0x108
	// Line 178, Address: 0x2df56c, Func Offset: 0x11c
	// Line 179, Address: 0x2df580, Func Offset: 0x130
	// Line 180, Address: 0x2df588, Func Offset: 0x138
	// Line 181, Address: 0x2df598, Func Offset: 0x148
	// Line 182, Address: 0x2df5a8, Func Offset: 0x158
	// Line 183, Address: 0x2df5b8, Func Offset: 0x168
	// Line 186, Address: 0x2df5d0, Func Offset: 0x180
	// Line 187, Address: 0x2df5dc, Func Offset: 0x18c
	// Line 190, Address: 0x2df5e4, Func Offset: 0x194
	// Line 189, Address: 0x2df5e8, Func Offset: 0x198
	// Line 186, Address: 0x2df5ec, Func Offset: 0x19c
	// Line 190, Address: 0x2df5f8, Func Offset: 0x1a8
	// Line 186, Address: 0x2df5fc, Func Offset: 0x1ac
	// Line 187, Address: 0x2df600, Func Offset: 0x1b0
	// Line 189, Address: 0x2df60c, Func Offset: 0x1bc
	// Line 187, Address: 0x2df610, Func Offset: 0x1c0
	// Line 188, Address: 0x2df618, Func Offset: 0x1c8
	// Line 189, Address: 0x2df61c, Func Offset: 0x1cc
	// Line 190, Address: 0x2df620, Func Offset: 0x1d0
	// Line 191, Address: 0x2df628, Func Offset: 0x1d8
	// Line 192, Address: 0x2df634, Func Offset: 0x1e4
	// Line 193, Address: 0x2df640, Func Offset: 0x1f0
	// Line 197, Address: 0x2df648, Func Offset: 0x1f8
	// Line 199, Address: 0x2df660, Func Offset: 0x210
	// Line 200, Address: 0x2df67c, Func Offset: 0x22c
	// Line 201, Address: 0x2df688, Func Offset: 0x238
	// Func End, Address: 0x2df6b8, Func Offset: 0x268
}

// 
// Start address: 0x2df6c0
void njDrawPolygon2DM(_anon2* p, int n, float pri, unsigned int attr)
{
	unsigned long prim;
	unsigned int i;
	float bp[4];
	float buff[4][32];
	// Line 207, Address: 0x2df6c0, Func Offset: 0
	// Line 219, Address: 0x2df6e8, Func Offset: 0x28
	// Line 207, Address: 0x2df6ec, Func Offset: 0x2c
	// Line 219, Address: 0x2df6f0, Func Offset: 0x30
	// Line 220, Address: 0x2df70c, Func Offset: 0x4c
	// Line 222, Address: 0x2df710, Func Offset: 0x50
	// Line 224, Address: 0x2df730, Func Offset: 0x70
	// Line 225, Address: 0x2df738, Func Offset: 0x78
	// Line 227, Address: 0x2df76c, Func Offset: 0xac
	// Line 228, Address: 0x2df784, Func Offset: 0xc4
	// Line 229, Address: 0x2df798, Func Offset: 0xd8
	// Line 231, Address: 0x2df7a0, Func Offset: 0xe0
	// Line 232, Address: 0x2df7b8, Func Offset: 0xf8
	// Line 233, Address: 0x2df7cc, Func Offset: 0x10c
	// Line 235, Address: 0x2df7d4, Func Offset: 0x114
	// Line 236, Address: 0x2df7ec, Func Offset: 0x12c
	// Line 237, Address: 0x2df800, Func Offset: 0x140
	// Line 239, Address: 0x2df808, Func Offset: 0x148
	// Line 240, Address: 0x2df820, Func Offset: 0x160
	// Line 243, Address: 0x2df838, Func Offset: 0x178
	// Line 245, Address: 0x2df840, Func Offset: 0x180
	// Line 246, Address: 0x2df850, Func Offset: 0x190
	// Line 247, Address: 0x2df858, Func Offset: 0x198
	// Line 248, Address: 0x2df85c, Func Offset: 0x19c
	// Line 249, Address: 0x2df860, Func Offset: 0x1a0
	// Line 250, Address: 0x2df864, Func Offset: 0x1a4
	// Line 253, Address: 0x2df868, Func Offset: 0x1a8
	// Line 254, Address: 0x2df870, Func Offset: 0x1b0
	// Line 255, Address: 0x2df884, Func Offset: 0x1c4
	// Line 256, Address: 0x2df898, Func Offset: 0x1d8
	// Line 257, Address: 0x2df8ac, Func Offset: 0x1ec
	// Line 258, Address: 0x2df8c0, Func Offset: 0x200
	// Line 259, Address: 0x2df8c8, Func Offset: 0x208
	// Line 260, Address: 0x2df8d8, Func Offset: 0x218
	// Line 261, Address: 0x2df8e8, Func Offset: 0x228
	// Line 262, Address: 0x2df8f8, Func Offset: 0x238
	// Line 265, Address: 0x2df910, Func Offset: 0x250
	// Line 266, Address: 0x2df91c, Func Offset: 0x25c
	// Line 269, Address: 0x2df924, Func Offset: 0x264
	// Line 268, Address: 0x2df928, Func Offset: 0x268
	// Line 265, Address: 0x2df92c, Func Offset: 0x26c
	// Line 269, Address: 0x2df938, Func Offset: 0x278
	// Line 265, Address: 0x2df93c, Func Offset: 0x27c
	// Line 266, Address: 0x2df940, Func Offset: 0x280
	// Line 268, Address: 0x2df94c, Func Offset: 0x28c
	// Line 266, Address: 0x2df950, Func Offset: 0x290
	// Line 267, Address: 0x2df958, Func Offset: 0x298
	// Line 268, Address: 0x2df95c, Func Offset: 0x29c
	// Line 269, Address: 0x2df960, Func Offset: 0x2a0
	// Line 270, Address: 0x2df968, Func Offset: 0x2a8
	// Line 271, Address: 0x2df974, Func Offset: 0x2b4
	// Line 272, Address: 0x2df980, Func Offset: 0x2c0
	// Line 276, Address: 0x2df988, Func Offset: 0x2c8
	// Line 278, Address: 0x2df9a0, Func Offset: 0x2e0
	// Line 279, Address: 0x2df9bc, Func Offset: 0x2fc
	// Line 280, Address: 0x2df9c8, Func Offset: 0x308
	// Func End, Address: 0x2df9f8, Func Offset: 0x338
}

