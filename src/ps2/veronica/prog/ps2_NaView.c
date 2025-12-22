#include "ps2_NaView.h"
#include "ps2_NaDraw2D.h"
#include "ps2_NaGraphics3D.h"
#include "ps2_Vu1Strip.h"
#include "main.h"

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
NJS_MATRIX NaViwViewMatrix __attribute__((aligned(64)));
NO_NAME_16 ClipVolume = { 320.0f, 240.0f, 1.0f, 512.0f };
sceVu0FMATRIX ClipScreenMatrix;
sceVu0FMATRIX ClipMatrix2;
float fVu1Projection;

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

// 100% matching!
int     njCalcScreen(NJS_POINT3 *p, Float *sx, Float *sy) 
{ 
    NJS_POINT3 Point;
    float fSX;
    float fSY;
    float fZ;

    njCalcPoint(&NaViwViewMatrix, p, &Point); 

    fZ = _nj_screen_.dist / Point.z; 
    
    fSX = Point.x * fZ; 
    fSY = Point.y * fZ; 
    
    *sx = fNaViwOffsetX + fSX; 
    *sy = fNaViwOffsetY + fSY; 
    
    if (Point.z < _fNaViwClipNear) 
    { 
        return -1; 
    } 
    
    if (_fNaViwClipFar < Point.z)
    { 
        return -1; 
    } 
    
    if (fSX < -fNaViwHalfW) 
    {
        return -1; 
    }
    
    if (fNaViwHalfW < fSX) 
    {
        return -1;
    }
    
    if (fSY < -fNaViwHalfH) 
    {
        return -1;
    }
    
    if (fNaViwHalfH < fSY) 
    {
        return -1;
    }
    
    return 0;
}

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

// 100% matching!
void _Make_ClipVolume(float x, float y) 
{ 
    if ((x < 0) && (y < 0)) 
    { 
        ClipDispW = -x * 0.5f;
        ClipDispH = -y * 0.5f; 
        
        ClipVolume.x = 320.0f; 
        ClipVolume.y = 240.0f; 
        
        _Make_ClipMatrix(ClipMatrix2, fVu1Projection, _fNaViwClipNear, _fNaViwClipFar); 
    } 
    else 
    {
        ClipDispW = 2047.0f; 
        ClipDispH = 2047.0f; 

        ClipVolume.x = x; 
        ClipVolume.y = y; 
        
        _Make_ClipMatrix(ClipMatrix2, fVu1Projection, _fNaViwClipNear, _fNaViwClipFar); 
    }
} 
