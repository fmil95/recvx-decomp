#include "ps2_Vu1Strip.c"

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
};*/

float fNaViwOffsetX = 2048.0f;
float fNaViwOffsetY = 2048.0f;
float fNaViwAspectW = 1.174000025f;
float fNaViwAspectH = 1.0f;
float fNaViwClipNear = -1.0f;
float fNaViwClipFar = -65535.0f;
float _fNaViwClipNear = 1.0f;
float _fNaViwClipFar = 65535.0f;
float ClipDispW = 2047.0f;
float ClipDispH = 2047.0f;
NJS_SCREEN	_nj_screen_;
NJS_MATRIX NaViewScreenMatrix;
float fNaViwHalfH;
float fNaViwHalfW;
NJS_MATRIX NaViwViewMatrix;
NO_NAME_16 ClipVolume = { 320.0f, 240.0f, 1.0f, 512.0f };
sceVu0FMATRIX ClipScreenMatrix;
sceVu0FMATRIX ClipMatrix2;
/*float fVu1Projection;

void njSetScreen(_anon2* pScreen);
void njSetPerspective(int lAngle);
void njSetScreenProjection(float dist);
void njSetAspect(float fW, float fH);
void njInitView(_anon3* pView);
void njSetView();
void njClipZ(float fNear, float fFar);
int njCalcScreen(_anon0* pPoint, float* fpScreenX, float* fpScreenY);*/
void njViewScreenMatrix(NJS_MATRIX* vs);
void _Make_ClipMatrix(sceVu0FMATRIX sc, float scr, float near, float far);
/*void _Make_ClipVolume(float x, float y);*/

// 100% matching!
void    njSetScreen(NJS_SCREEN *s)
{ 
    _nj_screen_.dist = s->dist; 
    
    Ps2CalcScreenCone();
    
    _nj_screen_.w = s->w; 
    _nj_screen_.h = s->h;
    
    _nj_screen_.cx = s->cx; 
    _nj_screen_.cy = s->cy; 
    
    fNaViwOffsetX = s->cx + 1728.0f; 
    fNaViwOffsetY = s->cy + 1808.0f; 
    
    fNaViwHalfW = _nj_screen_.w / 2.0f; 
    fNaViwHalfH = _nj_screen_.h / 2.0f;

    ClipDispW = 2047.0f; 
    ClipDispH = 2047.0f;

    njViewScreenMatrix(&NaViewScreenMatrix); 
    
    vu1SetScreenProjection(_nj_screen_.dist); 
    vu1SetScreenOffset(fNaViwOffsetX, fNaViwOffsetY);
} 

// 93.17% matching
void	njSetPerspective(Angle ang)
{ 
    ang /= 2; 
    
    _nj_screen_.dist = (_nj_screen_.w / 2.0f) / tanf(0.0000958738f * ang);
    
    Ps2CalcScreenCone();
    
    njViewScreenMatrix(&NaViewScreenMatrix); 
    
    vu1SetScreenProjection(_nj_screen_.dist);
} 

// 100% matching!
void njSetScreenProjection(float dist)
{ 
    _nj_screen_.dist = dist; 
    
    Ps2CalcScreenCone(); 
    
    njViewScreenMatrix(&NaViewScreenMatrix); 
    
    vu1SetScreenProjection(_nj_screen_.dist); 
} 

// 100% matching!
void    njSetAspect(Float ax, Float ay)
{ 
    fNaViwAspectW = ax; 
    fNaViwAspectH = ay; 
    
    njViewScreenMatrix(&NaViewScreenMatrix); 
    
    vu1SetScreenAspect(ax, ay); 
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

// 100% matching!
void    njSetView(NJS_VIEW *v)
{ 
    NaViwViewMatrix[0] = 1.0f; 
    NaViwViewMatrix[1] = 0; 
    NaViwViewMatrix[2] = 0; 
    NaViwViewMatrix[4] = 0; 
    
    NaViwViewMatrix[5] = -1.0f; 
    NaViwViewMatrix[6] = 0; 
    NaViwViewMatrix[8] = 0; 
    NaViwViewMatrix[9] = 0; 
    
    NaViwViewMatrix[10] = -1.0f; 
    NaViwViewMatrix[12] = 0; 
    NaViwViewMatrix[13] = 0; 
    NaViwViewMatrix[14] = 0; 

    njViewScreenMatrix(&NaViewScreenMatrix); 

    njClearMatrix(); 
}

// 100% matching!
void    njClipZ(Float n, Float f) 
{ 
    if (-1.0f < n) 
    { 
        n = -1.0f; 
    }
    
    if (f < -65535.0f)
    { 
        f = -65535.0f; 
    } 
    
    fNaViwClipNear = n; 
    fNaViwClipFar = f; 
    
    _fNaViwClipNear = -n; 
    _fNaViwClipFar = -f; 
    
    vu1SetNearFarClip(_fNaViwClipNear, _fNaViwClipFar);
    
    CalcPs2ZbuffAB();
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
}*/

// 100% matching!
void njViewScreenMatrix(NJS_MATRIX* vs) // this function is not on this KATANA release
{ 
    njUnitMatrix(vs); 
    
    (*vs)[0] = fNaViwAspectW; 
    (*vs)[5] = fNaViwAspectH; 
    
    (*vs)[10] = 1.0f; 
    (*vs)[12] = 0; 
    (*vs)[13] = 0; 
    (*vs)[14] = 0; 
    
    (*vs)[15] = _nj_screen_.dist; 
}

// 100% matching!
void _Make_ClipMatrix(sceVu0FMATRIX sc, float scr, float near, float far)
{ 
	float gsx;
	float gsy;
    NO_NAME_16* cv;
    float (*mp)[4]; // not from the debugging symbols
    register float (*mp2)[4], *fM, *fw, *fh; // not from the debugging symbols

    mp = sc;
    
    if (mp == NULL) 
    {
        mp = &ClipMatrix2[0];
    }
    
    cv = &ClipVolume; 
    
    gsx = (near * cv->x) / scr; 
    gsy = (near * cv->y) / scr; 
    
    sceVu0UnitMatrix(mp); 

    mp[0][0] = (2.0f * near) / (gsx + gsx); 
    mp[1][1] = (2.0f * near) / (gsy + gsy); 
    
    mp[2][2] = (far + near) / (far - near); 
    mp[3][2] = (-2.0f * far * near) / (far - near);
    
    mp[2][3] = 1.0f; 
    mp[3][3] = 0; 

    mp2 = &ClipMatrix2[0]; 
    
    asm volatile 
    { 
    .set noreorder
        
        lqc2 $vf24, 0x0(mp2) 
        lqc2 $vf25, 0x10(mp2) 
        lqc2 $vf26, 0x20(mp2) 
        lqc2 $vf27, 0x30(mp2)

    .set reorder
    }

    fM = ClipScreenMatrix[0];
    
    fw = &ClipDispW; 
    fh = &ClipDispH; 

    asm volatile 
    { 
    .set noreorder
        
        lwc1 $f8, 0x0(fw) 
        lwc1 $f9, 0x0(fh) 
        
        swc1 $f8, 0x2C(fM) 
        swc1 $f9, 0x28(fM)

    .set reorder
    }
} 

/*// 
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
