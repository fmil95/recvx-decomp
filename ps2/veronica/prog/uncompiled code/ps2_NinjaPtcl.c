typedef struct _anon0;
typedef struct tagNJS_SCRVECTOR;
typedef struct _anon1;


typedef float type_0[4][256];
typedef float type_1[4];
typedef float type_2[4][256];

struct _anon0
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

struct _anon1
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};

unsigned int Ps2_ptcl_poly_col;
int Ps2_ptcl_spr_flag;
unsigned int Ps2_ptcl_spr_col;
_anon1 _nj_screen_;

void njPtclPolygonStart(unsigned int col);
void njPtclPolygonEnd();
void njPtclDrawPolygon(_anon0* p, int n, float h);
void njPtclSpriteStart(int texid, unsigned int col, int flag);
void njPtclSpriteEnd();
void njPtclDrawSprite(_anon0* p, int n, float w, float h);

// 
// Start address: 0x2d82e0
void njPtclPolygonStart(unsigned int col)
{
	// Line 46, Address: 0x2d82e0, Func Offset: 0
	// Line 47, Address: 0x2d82e4, Func Offset: 0x4
	// Func End, Address: 0x2d82ec, Func Offset: 0xc
}

// 
// Start address: 0x2d82f0
void njPtclPolygonEnd()
{
	// Line 56, Address: 0x2d82f0, Func Offset: 0
	// Func End, Address: 0x2d82f8, Func Offset: 0x8
}

// 
// Start address: 0x2d8300
void njPtclDrawPolygon(_anon0* p, int n, float h)
{
	tagNJS_SCRVECTOR scr;
	unsigned int col;
	unsigned int i;
	float bp[4];
	float buff[4][256];
	float invz;
	// Line 67, Address: 0x2d8300, Func Offset: 0
	// Line 78, Address: 0x2d832c, Func Offset: 0x2c
	// Line 79, Address: 0x2d8338, Func Offset: 0x38
	// Line 81, Address: 0x2d8380, Func Offset: 0x80
	// Line 82, Address: 0x2d8384, Func Offset: 0x84
	// Line 83, Address: 0x2d8388, Func Offset: 0x88
	// Line 84, Address: 0x2d838c, Func Offset: 0x8c
	// Line 85, Address: 0x2d8390, Func Offset: 0x90
	// Line 86, Address: 0x2d8394, Func Offset: 0x94
	// Line 87, Address: 0x2d8398, Func Offset: 0x98
	// Line 90, Address: 0x2d839c, Func Offset: 0x9c
	// Line 102, Address: 0x2d83ac, Func Offset: 0xac
	// Line 121, Address: 0x2d83b0, Func Offset: 0xb0
	// Line 91, Address: 0x2d83b4, Func Offset: 0xb4
	// Line 103, Address: 0x2d83b8, Func Offset: 0xb8
	// Line 104, Address: 0x2d83bc, Func Offset: 0xbc
	// Line 102, Address: 0x2d83c0, Func Offset: 0xc0
	// Line 105, Address: 0x2d83c4, Func Offset: 0xc4
	// Line 120, Address: 0x2d83c8, Func Offset: 0xc8
	// Line 102, Address: 0x2d83cc, Func Offset: 0xcc
	// Line 103, Address: 0x2d83d0, Func Offset: 0xd0
	// Line 121, Address: 0x2d83d4, Func Offset: 0xd4
	// Line 103, Address: 0x2d83d8, Func Offset: 0xd8
	// Line 104, Address: 0x2d83e0, Func Offset: 0xe0
	// Line 105, Address: 0x2d83e8, Func Offset: 0xe8
	// Line 106, Address: 0x2d83f0, Func Offset: 0xf0
	// Line 107, Address: 0x2d83fc, Func Offset: 0xfc
	// Line 108, Address: 0x2d8408, Func Offset: 0x108
	// Line 109, Address: 0x2d8410, Func Offset: 0x110
	// Line 112, Address: 0x2d8418, Func Offset: 0x118
	// Line 113, Address: 0x2d841c, Func Offset: 0x11c
	// Line 114, Address: 0x2d8420, Func Offset: 0x120
	// Line 115, Address: 0x2d8424, Func Offset: 0x124
	// Line 117, Address: 0x2d8428, Func Offset: 0x128
	// Line 118, Address: 0x2d842c, Func Offset: 0x12c
	// Line 119, Address: 0x2d8430, Func Offset: 0x130
	// Line 120, Address: 0x2d8434, Func Offset: 0x134
	// Line 121, Address: 0x2d8438, Func Offset: 0x138
	// Line 123, Address: 0x2d8440, Func Offset: 0x140
	// Line 124, Address: 0x2d8454, Func Offset: 0x154
	// Line 126, Address: 0x2d8468, Func Offset: 0x168
	// Line 127, Address: 0x2d8470, Func Offset: 0x170
	// Line 130, Address: 0x2d8484, Func Offset: 0x184
	// Func End, Address: 0x2d84b4, Func Offset: 0x1b4
}

// 
// Start address: 0x2d84c0
void njPtclSpriteStart(int texid, unsigned int col, int flag)
{
	// Line 140, Address: 0x2d84c0, Func Offset: 0
	// Line 141, Address: 0x2d84c8, Func Offset: 0x8
	// Line 143, Address: 0x2d84cc, Func Offset: 0xc
	// Func End, Address: 0x2d84d4, Func Offset: 0x14
}

// 
// Start address: 0x2d84e0
void njPtclSpriteEnd()
{
	// Line 153, Address: 0x2d84e0, Func Offset: 0
	// Func End, Address: 0x2d84e8, Func Offset: 0x8
}

// 
// Start address: 0x2d84f0
void njPtclDrawSprite(_anon0* p, int n, float w, float h)
{
	tagNJS_SCRVECTOR scr;
	unsigned int col;
	unsigned int i;
	float bp[4];
	float buff[4][256];
	float invz;
	// Line 164, Address: 0x2d84f0, Func Offset: 0
	// Line 175, Address: 0x2d8520, Func Offset: 0x30
	// Line 176, Address: 0x2d852c, Func Offset: 0x3c
	// Line 178, Address: 0x2d8584, Func Offset: 0x94
	// Line 179, Address: 0x2d8588, Func Offset: 0x98
	// Line 180, Address: 0x2d858c, Func Offset: 0x9c
	// Line 181, Address: 0x2d8590, Func Offset: 0xa0
	// Line 182, Address: 0x2d8594, Func Offset: 0xa4
	// Line 183, Address: 0x2d8598, Func Offset: 0xa8
	// Line 184, Address: 0x2d859c, Func Offset: 0xac
	// Line 187, Address: 0x2d85a0, Func Offset: 0xb0
	// Line 189, Address: 0x2d85b0, Func Offset: 0xc0
	// Line 207, Address: 0x2d85b8, Func Offset: 0xc8
	// Line 188, Address: 0x2d85bc, Func Offset: 0xcc
	// Line 189, Address: 0x2d85c0, Func Offset: 0xd0
	// Line 190, Address: 0x2d85c4, Func Offset: 0xd4
	// Line 189, Address: 0x2d85c8, Func Offset: 0xd8
	// Line 190, Address: 0x2d85cc, Func Offset: 0xdc
	// Line 191, Address: 0x2d85d0, Func Offset: 0xe0
	// Line 192, Address: 0x2d85d4, Func Offset: 0xe4
	// Line 189, Address: 0x2d85d8, Func Offset: 0xe8
	// Line 206, Address: 0x2d85dc, Func Offset: 0xec
	// Line 207, Address: 0x2d85e0, Func Offset: 0xf0
	// Line 189, Address: 0x2d85e4, Func Offset: 0xf4
	// Line 190, Address: 0x2d85ec, Func Offset: 0xfc
	// Line 193, Address: 0x2d85f8, Func Offset: 0x108
	// Line 190, Address: 0x2d85fc, Func Offset: 0x10c
	// Line 191, Address: 0x2d8608, Func Offset: 0x118
	// Line 192, Address: 0x2d8610, Func Offset: 0x120
	// Line 193, Address: 0x2d8618, Func Offset: 0x128
	// Line 194, Address: 0x2d8624, Func Offset: 0x134
	// Line 193, Address: 0x2d8628, Func Offset: 0x138
	// Line 194, Address: 0x2d8634, Func Offset: 0x144
	// Line 195, Address: 0x2d864c, Func Offset: 0x15c
	// Line 196, Address: 0x2d8654, Func Offset: 0x164
	// Line 198, Address: 0x2d865c, Func Offset: 0x16c
	// Line 199, Address: 0x2d8660, Func Offset: 0x170
	// Line 200, Address: 0x2d8664, Func Offset: 0x174
	// Line 201, Address: 0x2d8668, Func Offset: 0x178
	// Line 203, Address: 0x2d866c, Func Offset: 0x17c
	// Line 204, Address: 0x2d8670, Func Offset: 0x180
	// Line 205, Address: 0x2d8674, Func Offset: 0x184
	// Line 206, Address: 0x2d8678, Func Offset: 0x188
	// Line 207, Address: 0x2d867c, Func Offset: 0x18c
	// Line 209, Address: 0x2d8688, Func Offset: 0x198
	// Line 210, Address: 0x2d869c, Func Offset: 0x1ac
	// Line 212, Address: 0x2d86b0, Func Offset: 0x1c0
	// Line 213, Address: 0x2d86b8, Func Offset: 0x1c8
	// Line 216, Address: 0x2d86cc, Func Offset: 0x1dc
	// Func End, Address: 0x2d8700, Func Offset: 0x210
}

