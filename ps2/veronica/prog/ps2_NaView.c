/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;


typedef float type_0[16];
typedef float type_1[4];
typedef float type_2[4][4];

struct _anon0
{
	float x;
	float y;
	float z;
};

struct _anon1
{
	float x;
	float y;
	float z;
	float w;
};

struct _anon2
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};

struct _anon3
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
};

float fNaViwOffsetX;
float fNaViwOffsetY;
float fNaViwAspectW;
float fNaViwAspectH;
float fNaViwClipNear;
float fNaViwClipFar;
float _fNaViwClipNear;
float _fNaViwClipFar;*/
float ClipDispW;
float ClipDispH;
/*_anon2 _nj_screen_;
float NaViewScreenMatrix[16];
float fNaViwHalfH;
float fNaViwHalfW;
float NaViwViewMatrix[16];
_anon1 ClipVolume;
float ClipScreenMatrix[4][4];
float ClipMatrix2[4][4];
float fVu1Projection;

void njSetScreen(_anon2* pScreen);
void njSetPerspective(int lAngle);
void njSetScreenProjection(float dist);
void njSetAspect(float fW, float fH);
void njInitView(_anon3* pView);
void njSetView();
void njClipZ(float fNear, float fFar);
int njCalcScreen(_anon0* pPoint, float* fpScreenX, float* fpScreenY);
void njViewScreenMatrix(float vs[16]);
void _Make_ClipMatrix(float sc[4], float scr, float near, float far);
void _Make_ClipVolume(float x, float y);

// 
// Start address: 0x2e2970
void njSetScreen(_anon2* pScreen)
{
	// Line 122, Address: 0x2e2970, Func Offset: 0
	// Line 123, Address: 0x2e297c, Func Offset: 0xc
	// Line 125, Address: 0x2e2988, Func Offset: 0x18
	// Line 127, Address: 0x2e2990, Func Offset: 0x20
	// Line 131, Address: 0x2e2998, Func Offset: 0x28
	// Line 132, Address: 0x2e29a0, Func Offset: 0x30
	// Line 127, Address: 0x2e29a4, Func Offset: 0x34
	// Line 128, Address: 0x2e29a8, Func Offset: 0x38
	// Line 132, Address: 0x2e29b0, Func Offset: 0x40
	// Line 134, Address: 0x2e29b4, Func Offset: 0x44
	// Line 128, Address: 0x2e29bc, Func Offset: 0x4c
	// Line 129, Address: 0x2e29c0, Func Offset: 0x50
	// Line 141, Address: 0x2e29c8, Func Offset: 0x58
	// Line 145, Address: 0x2e29d0, Func Offset: 0x60
	// Line 129, Address: 0x2e29d8, Func Offset: 0x68
	// Line 130, Address: 0x2e29dc, Func Offset: 0x6c
	// Line 134, Address: 0x2e29e8, Func Offset: 0x78
	// Line 131, Address: 0x2e29f0, Func Offset: 0x80
	// Line 135, Address: 0x2e29f4, Func Offset: 0x84
	// Line 134, Address: 0x2e29fc, Func Offset: 0x8c
	// Line 131, Address: 0x2e2a00, Func Offset: 0x90
	// Line 132, Address: 0x2e2a0c, Func Offset: 0x9c
	// Line 141, Address: 0x2e2a10, Func Offset: 0xa0
	// Line 135, Address: 0x2e2a14, Func Offset: 0xa4
	// Line 141, Address: 0x2e2a18, Func Offset: 0xa8
	// Line 142, Address: 0x2e2a1c, Func Offset: 0xac
	// Line 134, Address: 0x2e2a24, Func Offset: 0xb4
	// Line 132, Address: 0x2e2a2c, Func Offset: 0xbc
	// Line 135, Address: 0x2e2a38, Func Offset: 0xc8
	// Line 145, Address: 0x2e2a40, Func Offset: 0xd0
	// Line 147, Address: 0x2e2a48, Func Offset: 0xd8
	// Line 148, Address: 0x2e2a54, Func Offset: 0xe4
	// Line 150, Address: 0x2e2a68, Func Offset: 0xf8
	// Func End, Address: 0x2e2a78, Func Offset: 0x108
}

// 
// Start address: 0x2e2a80
void njSetPerspective(int lAngle)
{
	// Line 167, Address: 0x2e2a80, Func Offset: 0
	// Line 168, Address: 0x2e2a84, Func Offset: 0x4
	// Line 166, Address: 0x2e2a94, Func Offset: 0x14
	// Line 168, Address: 0x2e2a9c, Func Offset: 0x1c
	// Line 170, Address: 0x2e2acc, Func Offset: 0x4c
	// Line 175, Address: 0x2e2ad4, Func Offset: 0x54
	// Line 177, Address: 0x2e2ae0, Func Offset: 0x60
	// Line 178, Address: 0x2e2aec, Func Offset: 0x6c
	// Func End, Address: 0x2e2af8, Func Offset: 0x78
}

// 
// Start address: 0x2e2b00
void njSetScreenProjection(float dist)
{
	// Line 191, Address: 0x2e2b00, Func Offset: 0
	// Line 192, Address: 0x2e2b08, Func Offset: 0x8
	// Line 194, Address: 0x2e2b0c, Func Offset: 0xc
	// Line 199, Address: 0x2e2b14, Func Offset: 0x14
	// Line 201, Address: 0x2e2b20, Func Offset: 0x20
	// Line 203, Address: 0x2e2b2c, Func Offset: 0x2c
	// Func End, Address: 0x2e2b38, Func Offset: 0x38
}*/

// 
// Start address: 0x2e2b40 
void    njSetAspect(Float ax, Float ay) 
{ 
    // Line 221, Address: 0x2e2b40, Func Offset: 0
	// Line 222, Address: 0x2e2b50, Func Offset: 0x10
	// Line 226, Address: 0x2e2b58, Func Offset: 0x18
	// Line 223, Address: 0x2e2b5c, Func Offset: 0x1c
	// Line 226, Address: 0x2e2b60, Func Offset: 0x20
	// Line 223, Address: 0x2e2b68, Func Offset: 0x28
	// Line 226, Address: 0x2e2b6c, Func Offset: 0x2c
	// Line 228, Address: 0x2e2b74, Func Offset: 0x34
	// Line 230, Address: 0x2e2b80, Func Offset: 0x40
	// Func End, Address: 0x2e2b94, Func Offset: 0x54
	scePrintf("njSetAspect - UNIMPLEMENTED!\n");
} 

// 100% matching!
void    njInitView(NJS_VIEW *v)
{
    v->px = 0; 
    v->py = 0; 
    v->pz = 0; 
    
    v->vx = 0; 
    v->vy = 0; 
    v->vz = -1.0f; 
    
    v->roll = 0; 
    
    v->apx = 0; 
    v->apy = 0; 
    v->apz = 0; 
    
    v->avx = 0; 
    v->avy = 0; 
    v->avz = -1.0f; 
    
    v->aroll = 0; 
    
    ClipDispW = 2047.0f; 
    ClipDispH = 2047.0f; 
} 

// 
// Start address: 0x2e2c00
void    njSetView(NJS_VIEW *v)
{ 
	// Line 302, Address: 0x2e2c00, Func Offset: 0
	// Line 353, Address: 0x2e2c08, Func Offset: 0x8
	// Line 354, Address: 0x2e2c14, Func Offset: 0x14
	// Line 355, Address: 0x2e2c1c, Func Offset: 0x1c
	// Line 356, Address: 0x2e2c24, Func Offset: 0x24
	// Line 357, Address: 0x2e2c2c, Func Offset: 0x2c
	// Line 358, Address: 0x2e2c38, Func Offset: 0x38
	// Line 359, Address: 0x2e2c40, Func Offset: 0x40
	// Line 360, Address: 0x2e2c48, Func Offset: 0x48
	// Line 361, Address: 0x2e2c50, Func Offset: 0x50
	// Line 362, Address: 0x2e2c58, Func Offset: 0x58
	// Line 363, Address: 0x2e2c60, Func Offset: 0x60
	// Line 368, Address: 0x2e2c64, Func Offset: 0x64
	// Line 363, Address: 0x2e2c68, Func Offset: 0x68
	// Line 364, Address: 0x2e2c6c, Func Offset: 0x6c
	// Line 368, Address: 0x2e2c70, Func Offset: 0x70
	// Line 371, Address: 0x2e2c7c, Func Offset: 0x7c
	// Line 374, Address: 0x2e2c84, Func Offset: 0x84
	// Func End, Address: 0x2e2c90, Func Offset: 0x90
    scePrintf("njSetView - UNIMPLEMENTED!\n");
} 

// 
// Start address: 0x2e2c90
void    njClipZ(Float n, Float f) 
{ 
	// Line 397, Address: 0x2e2c90, Func Offset: 0
	// Line 396, Address: 0x2e2c98, Func Offset: 0x8
	// Line 397, Address: 0x2e2c9c, Func Offset: 0xc
	// Line 398, Address: 0x2e2cb0, Func Offset: 0x20
	// Line 400, Address: 0x2e2cd4, Func Offset: 0x44
	// Line 401, Address: 0x2e2cdc, Func Offset: 0x4c
	// Line 402, Address: 0x2e2ce4, Func Offset: 0x54
	// Line 403, Address: 0x2e2cf0, Func Offset: 0x60
	// Line 405, Address: 0x2e2cfc, Func Offset: 0x6c
	// Line 407, Address: 0x2e2d10, Func Offset: 0x80
	// Line 411, Address: 0x2e2d18, Func Offset: 0x88
	// Func End, Address: 0x2e2d24, Func Offset: 0x94
	scePrintf("njClipZ - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2e2d30
int njCalcScreen(_anon0* pPoint, float* fpScreenX, float* fpScreenY)
{
	float fZ;
	float fSY;
	float fSX;
	_anon0 Point;
	// Line 435, Address: 0x2e2d30, Func Offset: 0
	// Line 441, Address: 0x2e2d48, Func Offset: 0x18
	// Line 444, Address: 0x2e2d5c, Func Offset: 0x2c
	// Line 445, Address: 0x2e2d60, Func Offset: 0x30
	// Line 444, Address: 0x2e2d64, Func Offset: 0x34
	// Line 446, Address: 0x2e2d70, Func Offset: 0x40
	// Line 447, Address: 0x2e2d74, Func Offset: 0x44
	// Line 444, Address: 0x2e2d78, Func Offset: 0x48
	// Line 447, Address: 0x2e2d7c, Func Offset: 0x4c
	// Line 448, Address: 0x2e2d80, Func Offset: 0x50
	// Line 445, Address: 0x2e2d84, Func Offset: 0x54
	// Line 447, Address: 0x2e2d88, Func Offset: 0x58
	// Line 448, Address: 0x2e2d90, Func Offset: 0x60
	// Line 446, Address: 0x2e2d94, Func Offset: 0x64
	// Line 448, Address: 0x2e2d98, Func Offset: 0x68
	// Line 451, Address: 0x2e2d9c, Func Offset: 0x6c
	// Line 448, Address: 0x2e2da0, Func Offset: 0x70
	// Line 451, Address: 0x2e2da4, Func Offset: 0x74
	// Line 452, Address: 0x2e2dc4, Func Offset: 0x94
	// Line 453, Address: 0x2e2de4, Func Offset: 0xb4
	// Line 454, Address: 0x2e2e08, Func Offset: 0xd8
	// Line 455, Address: 0x2e2e20, Func Offset: 0xf0
	// Line 456, Address: 0x2e2e44, Func Offset: 0x114
	// Line 458, Address: 0x2e2e60, Func Offset: 0x130
	// Func End, Address: 0x2e2e74, Func Offset: 0x144
}

// 
// Start address: 0x2e2e80
void njViewScreenMatrix(float vs[16])
{
	// Line 521, Address: 0x2e2e80, Func Offset: 0
	// Line 548, Address: 0x2e2e8c, Func Offset: 0xc
	// Line 549, Address: 0x2e2e94, Func Offset: 0x14
	// Line 551, Address: 0x2e2e9c, Func Offset: 0x1c
	// Line 549, Address: 0x2e2ea0, Func Offset: 0x20
	// Line 550, Address: 0x2e2ea4, Func Offset: 0x24
	// Line 551, Address: 0x2e2eb0, Func Offset: 0x30
	// Line 552, Address: 0x2e2eb4, Func Offset: 0x34
	// Line 553, Address: 0x2e2eb8, Func Offset: 0x38
	// Line 554, Address: 0x2e2ebc, Func Offset: 0x3c
	// Line 555, Address: 0x2e2ec0, Func Offset: 0x40
	// Line 557, Address: 0x2e2ecc, Func Offset: 0x4c
	// Func End, Address: 0x2e2edc, Func Offset: 0x5c
}

// 
// Start address: 0x2e2ee0
void _Make_ClipMatrix(float sc[4], float scr, float near, float far)
{
	_anon1* cv;
	float gsy;
	float gsx;
	// Line 581, Address: 0x2e2ee0, Func Offset: 0
	// Line 589, Address: 0x2e2f04, Func Offset: 0x24
	// Line 590, Address: 0x2e2f14, Func Offset: 0x34
	// Line 607, Address: 0x2e2f1c, Func Offset: 0x3c
	// Line 608, Address: 0x2e2f20, Func Offset: 0x40
	// Line 615, Address: 0x2e2f24, Func Offset: 0x44
	// Line 607, Address: 0x2e2f28, Func Offset: 0x48
	// Line 608, Address: 0x2e2f34, Func Offset: 0x54
	// Line 615, Address: 0x2e2f44, Func Offset: 0x64
	// Line 617, Address: 0x2e2f4c, Func Offset: 0x6c
	// Line 624, Address: 0x2e2f54, Func Offset: 0x74
	// Line 617, Address: 0x2e2f58, Func Offset: 0x78
	// Line 628, Address: 0x2e2f5c, Func Offset: 0x7c
	// Line 625, Address: 0x2e2f60, Func Offset: 0x80
	// Line 628, Address: 0x2e2f64, Func Offset: 0x84
	// Line 617, Address: 0x2e2f68, Func Offset: 0x88
	// Line 618, Address: 0x2e2f6c, Func Offset: 0x8c
	// Line 617, Address: 0x2e2f70, Func Offset: 0x90
	// Line 624, Address: 0x2e2f74, Func Offset: 0x94
	// Line 617, Address: 0x2e2f78, Func Offset: 0x98
	// Line 618, Address: 0x2e2f7c, Func Offset: 0x9c
	// Line 624, Address: 0x2e2f80, Func Offset: 0xa0
	// Line 618, Address: 0x2e2f84, Func Offset: 0xa4
	// Line 624, Address: 0x2e2f88, Func Offset: 0xa8
	// Line 623, Address: 0x2e2f8c, Func Offset: 0xac
	// Line 624, Address: 0x2e2f98, Func Offset: 0xb8
	// Line 623, Address: 0x2e2f9c, Func Offset: 0xbc
	// Line 624, Address: 0x2e2fa0, Func Offset: 0xc0
	// Line 625, Address: 0x2e2fa4, Func Offset: 0xc4
	// Line 626, Address: 0x2e2fa8, Func Offset: 0xc8
	// Line 629, Address: 0x2e2fac, Func Offset: 0xcc
	// Line 630, Address: 0x2e2fb0, Func Offset: 0xd0
	// Line 631, Address: 0x2e2fb4, Func Offset: 0xd4
	// Line 632, Address: 0x2e2fb8, Func Offset: 0xd8
	// Line 669, Address: 0x2e2fbc, Func Offset: 0xdc
	// Line 670, Address: 0x2e2fd4, Func Offset: 0xf4
	// Line 671, Address: 0x2e2fd8, Func Offset: 0xf8
	// Line 672, Address: 0x2e2fdc, Func Offset: 0xfc
	// Line 673, Address: 0x2e2fe0, Func Offset: 0x100
	// Line 681, Address: 0x2e2fe4, Func Offset: 0x104
	// Func End, Address: 0x2e3004, Func Offset: 0x124
}

// 
// Start address: 0x2e3010
void _Make_ClipVolume(float x, float y)
{
	// Line 742, Address: 0x2e3010, Func Offset: 0
	// Line 741, Address: 0x2e3014, Func Offset: 0x4
	// Line 742, Address: 0x2e3018, Func Offset: 0x8
	// Line 744, Address: 0x2e3038, Func Offset: 0x28
	// Line 747, Address: 0x2e3048, Func Offset: 0x38
	// Line 748, Address: 0x2e3054, Func Offset: 0x44
	// Line 744, Address: 0x2e3060, Func Offset: 0x50
	// Line 750, Address: 0x2e3068, Func Offset: 0x58
	// Line 745, Address: 0x2e3070, Func Offset: 0x60
	// Line 750, Address: 0x2e3074, Func Offset: 0x64
	// Line 745, Address: 0x2e3078, Func Offset: 0x68
	// Line 750, Address: 0x2e307c, Func Offset: 0x6c
	// Line 745, Address: 0x2e3084, Func Offset: 0x74
	// Line 750, Address: 0x2e308c, Func Offset: 0x7c
	// Line 751, Address: 0x2e309c, Func Offset: 0x8c
	// Line 756, Address: 0x2e30a4, Func Offset: 0x94
	// Line 757, Address: 0x2e30ac, Func Offset: 0x9c
	// Line 753, Address: 0x2e30b4, Func Offset: 0xa4
	// Line 754, Address: 0x2e30c4, Func Offset: 0xb4
	// Line 759, Address: 0x2e30cc, Func Offset: 0xbc
	// Line 761, Address: 0x2e30f0, Func Offset: 0xe0
	// Func End, Address: 0x2e30fc, Func Offset: 0xec
}*/
