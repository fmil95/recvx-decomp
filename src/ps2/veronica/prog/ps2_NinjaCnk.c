#include "ps2_NinjaCnk.h"
#include "ps2_dummy.h"
#include "ps2_NaFog.h"
#include "ps2_NaMath.h"
#include "ps2_NaMatrix.h"
#include "ps2_NaSystem.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_NaView.h"
#include "ps2_Vu1Strip.h"

static VU1_STRIP_BUF* pNaCnkVerBufTop;
static int iNaCnkVerBufMax;
static VU1_STRIP_BUF NaCnkStrBufTop[200];
static unsigned int Vu0ClipFlag;
static unsigned int Ps2_chunk_buff_flip;
unsigned int ulCnkCurrentDrawMode;
unsigned short* uspCnkCrntTexColCalcTbl;
CNK_LIGHTING* pNaCnkCrntLighting;
void* vpDummy;
unsigned char ucNaCnkAttr;
unsigned int ulNaCnkFlagModelClip;
unsigned int ulNaCnkFlagConstAttr;
unsigned int ulNaCnkFlagConstMaterial;
int lCnkModClipFace;
CHUNK_HEAD* (*pCnkFuncTbl[76])(CHUNK_HEAD*) = 
{
	njCnkCn,
	njCnkCbBa,
	njCnkCbDa,
	njCnkCbExp,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkCtTid,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkCmD,
	njCnkCmA,
	njCnkCmDa,
	njCnkCmS,
	njCnkCmDs,
	njCnkCmAs,
	njCnkCmDas,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkCvVn,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkCvVnPs2,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkDefaultLong,
	njCnkCoP3,
	njCnkCoP4,
	njCnkCoSt,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkCs,
	njCnkCsUvn,
	njCnkCsUvh,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort,
	njCnkDefaultShort
};
void (*pCnkCsVu1FuncTbl[32])(unsigned long, VU1_STRIP_BUF*, unsigned short, unsigned short) = 
{
	vu1DrawTriangleStripOpaqueDouble,
	vu1DrawTriangleStripOpaqueDouble,
	vu1DrawTriangleStripOpaqueSingle,
	vu1DrawTriangleStripOpaqueSingle,
	NULL,
	NULL,
	NULL,
	NULL,
	vu1DrawTriangleStripTransDouble,
	vu1DrawTriangleStripTransDouble,
	vu1DrawTriangleStripTransSingle,
	vu1DrawTriangleStripTransSingle,
	NULL,
	NULL,
	NULL,
	NULL,
	vu1DrawTriangleStripOpaqueDouble,
	vu1DrawTriangleStripOpaqueDouble,
	vu1DrawTriangleStripOpaqueDouble,
	vu1DrawTriangleStripOpaqueDouble,
	NULL,
	NULL,
	NULL,
	NULL,
	vu1DrawTriangleStripTransDouble,
	vu1DrawTriangleStripTransDouble,
	vu1DrawTriangleStripTransDouble,
	vu1DrawTriangleStripTransDouble,
	vu1DrawTriangleStripTransDoubleI,
	vu1DrawTriangleStripTransDoubleI,
	vu1DrawTriangleStripTransDoubleI,
	vu1DrawTriangleStripTransDoubleI
};
unsigned short usCnkCsPolColorCalcFunc[8] = { 4, 2, 4, 2, 4, 2, 4, 2 };
unsigned short usCnkCsTexColorCalcFunc[4][8] = { { 9, 2, 4, 2, 6, 2, 3, 2 }, { 9, 2, 4, 2, 6, 2, 3, 2 }, 
												 { 10, 2, 4, 2, 7, 2, 3, 2 }, { 8, 2, 4, 2, 5, 2, 3, 2 } };
int lNaCnkSrcAlphaMode[8] = { 11, 10, 3, 5, 8, 6, 2, 4 };
int lNaCnkDstAlphaMode[8] = { 11, 10, 9, 7, 8, 6, 2, 4 };
int lNaCnkSrcBlendMode = 8;
int lNaCnkDstBlendMode = 6;
VU1_COLOR NaCnkDefaultOne = { 1.0f, 1.0f, 1.0f, 1.0f };
float fNaCnkConstantA = 1.0f;
float fNaCnkConstantR = 1.0f;
float fNaCnkConstantG = 1.0f;
float fNaCnkConstantB = 1.0f;
VU1_COLOR NaCnkConstantMaterial = { 1.0f, 1.0f, 1.0f, 1.0f };
float fNaCnkAlphaMaterial = { 1.0f }; 
VU1_COLOR NaCnkDiffuseMaterial __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
float fNaCnkMaterialSpeE = 17.0f;
VU1_COLOR NaCnkSpeculaMaterial __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientMaterial __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientFunctionEm __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientFunctionSm = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientEs __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientEm __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientSs __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientSm = { 1.0f, 1.0f, 1.0f, 1.0f };
CNK_LIGHT NaCnkLightEs __attribute__((aligned(64))) = { 1.401298464f, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 };
CNK_LIGHT NaCnkLightEm[6] __attribute__((aligned(64))) = { { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 } };
CNK_LIGHT NaCnkLightSs = { 1.401298464f, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 };
CNK_LIGHT NaCnkLightSm[6] __attribute__((aligned(64))) = { { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 },
														   { 0, 0, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0 } };
CNK_LIGHTING NaCnkLighting[4] __attribute__((aligned(64))) = { { &NaCnkLightEs, 1, &NaCnkDefaultOne, &NaCnkSpeculaMaterial, &NaCnkAmbientEs, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
														       { NaCnkLightEm, 6, &NaCnkDefaultOne, &NaCnkDefaultOne, &NaCnkAmbientEm, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
														       { &NaCnkLightSs, 1, &NaCnkDiffuseMaterial, &NaCnkSpeculaMaterial, &NaCnkAmbientSs, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
														       { NaCnkLightSm, 6, &NaCnkDiffuseMaterial, &NaCnkDefaultOne, &NaCnkAmbientSm, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
/*unsigned int njCnkConvTest; - unused*/
extern void VU0_MINMAX() __attribute__((section(".vutext")));
extern void VU0_CALCPOINT_END() __attribute__((section(".vutext")));
extern void VU0_CALCPOINT_INIT() __attribute__((section(".vutext")));

// 100% matching!
void	njInit3D( NJS_VERTEX_BUF *vbuf, Int vn )
{
    pNaCnkVerBufTop = (VU1_STRIP_BUF*)vbuf; 
    
    iNaCnkVerBufMax = vn; 
    
    _Init_ScissorSystem(); 
}

// 100% matching!
void	njDrawModel( NJS_MODEL *model )
{
    vpDummy = model;
}

// 100% matching!
void	njControl3D( Uint32 flag )
{
    _nj_control_3d_flag_ = Ps2_njControl3D_flag = flag;
    
    Ps2_use_pt_flag = flag & 0x4000;
    
    ulNaCnkFlagConstMaterial = flag & 0x10;
    ulNaCnkFlagConstAttr = flag & 0x800;
    
    ulNaCnkFlagModelClip = flag & 0x100;
}

// 100% matching!
void	njSetConstantAttr( Uint32 and_attr, Uint32 or_attr )
{
    ucNaCnkAttr &= and_attr >> 8;
    ucNaCnkAttr |= or_attr >> 8;
}

// 100% matching!
void	njSetConstantMaterial( NJS_ARGB *mat )
{
    fNaCnkConstantA = mat->a; 
    fNaCnkConstantR = mat->r; 
    fNaCnkConstantG = mat->g; 
    fNaCnkConstantB = mat->b; 

    NaCnkConstantMaterial.fA = mat->a;
    NaCnkConstantMaterial.fR = mat->r;
    NaCnkConstantMaterial.fG = mat->g;
    NaCnkConstantMaterial.fB = mat->b;
}

// 100% matching!
void njSetCnkBlendMode(Uint32 attr)
{
    lNaCnkSrcBlendMode = lNaCnkSrcAlphaMode[(attr >> 3) & 0x7]; 
    lNaCnkDstBlendMode = lNaCnkDstAlphaMode[attr & 0x7];
}

// 100% matching!
void    njCnkModDrawModel( NJS_CNK_MODEL *model ) 
{
    njCnkDrawModelLocalMod(model);
}

// 100% matching!
void    njCnkSetEasyLight( Float x,Float y,Float z ) 
{
    NaCnkLightEs.fCx = -x;
    NaCnkLightEs.fCy = -y;
    NaCnkLightEs.fCz = -z;
}

// 100% matching!
void    njCnkSetEasyLightIntensity( Float inten, Float ambient ) 
{
    NaCnkLightEs.fI = inten;
    
    NaCnkAmbientEs.fB = ambient;
    NaCnkAmbientEs.fG = ambient;
    NaCnkAmbientEs.fR = ambient;
}

// 100% matching!
void    njCnkSetEasyLightColor( Float r, Float g, Float b ) 
{    
    NaCnkLightEs.fR = r;    
    NaCnkLightEs.fG = g;    
    NaCnkLightEs.fB = b;
}

// 100% matching! 
void    njCnkSetEasyMultiLight(Int num)
{
    NaCnkLighting[1].lLightMax = num;
    
    njCnkSetEasyMultiLightSwitch(0, 1);
}

// 100% matching!
void    njCnkSetEasyMultiLightSwitch(Int light, Int flag) 
{
    int lCnt; // not from the debugging symbols

    if (light == 0) 
    {
        for (lCnt = 0; lCnt < NaCnkLighting[1].lLightMax; lCnt++) 
        {
            NaCnkLightEm[lCnt].ulState = flag;
        }
    } 
    else 
    {
        NaCnkLightEm[light - 1].ulState = flag;
    }    
}

// 100% matching!
void    njCnkSetEasyMultiAmbient(Float ar, Float ag, Float ab)
{
    NaCnkAmbientFunctionEm.fR = ar;
    NaCnkAmbientFunctionEm.fG = ag;
    NaCnkAmbientFunctionEm.fB = ab;
    
    NaCnkAmbientEm.fR = ar * NaCnkAmbientMaterial.fR;
    NaCnkAmbientEm.fG = ag * NaCnkAmbientMaterial.fG;
    NaCnkAmbientEm.fB = ab * NaCnkAmbientMaterial.fB;
}

// 100% matching!
void    njCnkSetEasyMultiLightColor(Int light, Float lr, Float lg, Float lb)
{
    int lCnt; // not from the debugging symbols

    lCnt = light - 1;
    
    NaCnkLightEm[lCnt].fR = lr;
    NaCnkLightEm[lCnt].fG = lg;
    NaCnkLightEm[lCnt].fB = lb;
}

// 100% matching!
void    njCnkSetEasyMultiLightVector(Float vx, Float vy, Float vz)
{
    NaCnkLightEm->fWx = -vx;
    NaCnkLightEm->fWy = -vy;
    NaCnkLightEm->fWz = -vz;
    
    NaCnkLightEm->ulMode = 0;
}

// 100% matching!
void    njCnkSetEasyMultiLightPoint(Int light, Float px, Float py, Float pz)
{
    int lCnt; // not from the debugging symbols

    lCnt = light - 1;
    
    NaCnkLightEm[lCnt].fWx = px;
    NaCnkLightEm[lCnt].fWy = py;
    NaCnkLightEm[lCnt].fWz = pz;
    
    NaCnkLightEm[lCnt].ulMode = 1;
}

// 100% matching!
void    njCnkSetEasyMultiLightRange(Int light, Float nrange, Float frange)
{
    int lCnt; // not from the debugging symbols

    lCnt = light - 1;

    NaCnkLightEm[lCnt].fNearRR = nrange * nrange;
    NaCnkLightEm[lCnt].fFarRR = frange * frange;
    
    NaCnkLightEm[lCnt].ulMode = 1;
}

// 100% matching!
void    njCnkSetEasyMultiLightMatrices(void)
{
    int lCnt;  
    
    for (lCnt = 0; lCnt < NaCnkLighting[1].lLightMax; lCnt++) 
    {
        if (NaCnkLightEm[lCnt].ulState != 0) 
        {
            if (NaCnkLightEm[lCnt].ulMode == 0) 
            {
                njPushMatrixEx();
                
                njUnitTransPortion(NULL);
                
                njCalcPoint(NULL, (NJS_POINT3*)&NaCnkLightEm[lCnt].fWx, (NJS_POINT3*)&NaCnkLightEm[lCnt].fCx);
                
                njPopMatrixEx();
            } 
            else 
            {
                njCalcPoint(NULL, (NJS_POINT3*)&NaCnkLightEm[lCnt].fWx, (NJS_POINT3*)&NaCnkLightEm[lCnt].fCx);
            }
        }
    }
}

// 100% matching!
void    njCnkSetSimpleLight( Float x,Float y,Float z )
{
    NaCnkLightSs.fCx = -x;
    NaCnkLightSs.fCy = -y;
    NaCnkLightSs.fCz = -z;
}

// 100% matching!
void    njCnkSetSimpleLightIntensity( Float inten, Float ambient ) 
{
    NaCnkLightSs.fI = inten;
    
    NaCnkAmbientSs.fB = ambient;
    NaCnkAmbientSs.fG = ambient;
    NaCnkAmbientSs.fR = ambient;
}

// 100% matching!
void    njCnkSetSimpleLightColor( Float r, Float g, Float b )
{
    NaCnkLightSs.fR = r;
    NaCnkLightSs.fG = g;
    NaCnkLightSs.fB = b;
}

// 100% matching!
void    njCnkSetSimpleMultiLight(Int num)
{
    NaCnkLighting[3].lLightMax = num;
    
    njCnkSetSimpleMultiLightSwitch(0, 1);
}

// 100% matching!
void    njCnkSetSimpleMultiLightSwitch(Int light, Int flag)
{
    int lCnt; // not from the debugging symbols

    if (light == 0) 
    {
        for (lCnt = 0; lCnt < NaCnkLighting[3].lLightMax; lCnt++) 
        {
            NaCnkLightSm[lCnt].ulState = flag;
        }
    } 
    else 
    {
        NaCnkLightSm[light - 1].ulState = flag;
    }
}

// 100% matching!
void    njCnkSetSimpleMultiAmbient(Float ar, Float ag, Float ab)
{
    NaCnkAmbientFunctionSm.fR = ar;
    NaCnkAmbientFunctionSm.fG = ag;
    NaCnkAmbientFunctionSm.fB = ab;
    
    NaCnkAmbientSm.fR = ar * NaCnkAmbientMaterial.fR;
    NaCnkAmbientSm.fG = ag * NaCnkAmbientMaterial.fG;
    NaCnkAmbientSm.fB = ab * NaCnkAmbientMaterial.fB;
}

// 100% matching!
void    njCnkSetSimpleMultiLightColor(Int light, Float lr, Float lg, Float lb)
{
    int lCnt; // not from the debugging symbols

    lCnt = light - 1;
    
    NaCnkLightSm[lCnt].fR = lr;
    NaCnkLightSm[lCnt].fG = lg;
    NaCnkLightSm[lCnt].fB = lb;
}

// 100% matching!
void    njCnkSetSimpleMultiLightVector(Float vx, Float vy, Float vz)
{
    NaCnkLightSm->fWx = -vx;
    NaCnkLightSm->fWy = -vy;
    NaCnkLightSm->fWz = -vz;
    
    NaCnkLightSm->ulMode = 0;
}

// 100% matching!
void    njCnkSetSimpleMultiLightPoint(Int light, Float px, Float py, Float pz)
{
    int lCnt; // not from the debugging symbols

    lCnt = light - 1;
    
    NaCnkLightSm[lCnt].fWx = px;
    NaCnkLightSm[lCnt].fWy = py;
    NaCnkLightSm[lCnt].fWz = pz;
    
    NaCnkLightSm[lCnt].ulMode = 1;
}

// 100% matching!
void    njCnkSetSimpleMultiLightRange(Int light, Float nrange, Float frange)
{
    int lCnt; // not from the debugging symbols

    lCnt = light - 1;
    
    NaCnkLightSm[lCnt].fNearRR = nrange * nrange;
    NaCnkLightSm[lCnt].fFarRR = frange * frange;
    
    NaCnkLightSm[lCnt].ulMode = 1;
}

// 100% matching!
void    njCnkSetSimpleMultiLightMatrices(void)
{
    int lCnt;

    for (lCnt = 0; lCnt < NaCnkLighting[3].lLightMax; lCnt++) 
    {
        if (NaCnkLightSm[lCnt].ulState != 0) 
        {
            if (NaCnkLightSm[lCnt].ulMode == 0)
            {
                njPushMatrixEx();
                
                njUnitTransPortion(NULL);
                
                njCalcPoint(NULL, (NJS_POINT3*)&NaCnkLightSm[lCnt].fWx, (NJS_POINT3*)&NaCnkLightSm[lCnt].fCx);
                
                njPopMatrixEx();
            } 
            else 
            {
                njCalcPoint(NULL, (NJS_POINT3*)&NaCnkLightSm[lCnt].fWx, (NJS_POINT3*)&NaCnkLightSm[lCnt].fCx);
            }
        }
    }
}

// 100% matching!
void    njCnkEasyDrawModel( NJS_CNK_MODEL *model )
{
    njCnkSetCurrentDrawMode(0);
    
    njCnkDrawModelLocal(model);
}

// 100% matching!
void    njCnkEasyDrawObject( NJS_CNK_OBJECT *model )
{
    unsigned int ulFlags; 
    int lDrawResult;  

    njCnkSetCurrentDrawMode(0);
    
    for ( ; model != NULL; model = model->sibling) 
    {
        ulFlags = model->evalflags;
    
        njPushMatrixEx();
    
        if (!(ulFlags & 0x1)) 
        {
            njTranslateEx((NJS_VECTOR*)&model->pos[0]);
        }
    
        if (!(ulFlags & 0x2)) 
        {
            njRotateEx(model->ang, ulFlags & 0x20);
        }
    
        if (!(ulFlags & 0x4))
        {
            njScaleEx((NJS_VECTOR*)&model->scl[0]);
        }
    
        if ((ulFlags & 0x8)) 
        {
            lDrawResult = 0;
        } 
        else
        {
            lDrawResult = njCnkDrawModelLocal(model->model);
        }
    
        if (!(ulFlags & 0x10)) 
        {
            if ((!(ulFlags & 0x100)) || (lDrawResult != 0)) 
            {
                njCnkEasyDrawObject(model->child);
            }
        }
    
        njPopMatrixEx();
    }
}

// 100% matching!
void    njCnkEasyMultiDrawModel( NJS_CNK_MODEL *model ) 
{
    njCnkSetCurrentDrawMode(1);
    
    njCnkDrawModelLocal(model);
}

// 100% matching!
void    njCnkEasyMultiDrawObject( NJS_CNK_OBJECT *model )
{
    unsigned int ulFlags; 
    int lDrawResult;    

    njCnkSetCurrentDrawMode(1);
    
    for ( ; model != NULL; model = model->sibling) 
    {
        ulFlags = model->evalflags;
    
        njPushMatrixEx();
    
        if (!(ulFlags & 0x1)) 
        {
            njTranslateEx((NJS_VECTOR*)&model->pos[0]);
        }
    
        if (!(ulFlags & 0x2)) 
        {
            njRotateEx(model->ang, ulFlags & 0x20);
        }
    
        if (!(ulFlags & 0x4))
        {
            njScaleEx((NJS_VECTOR*)&model->scl[0]);
        }
    
        if ((ulFlags & 0x8)) 
        {
            lDrawResult = 0;
        } 
        else
        {
            lDrawResult = njCnkDrawModelLocal(model->model);
        }
    
        if (!(ulFlags & 0x10)) 
        {
            if ((!(ulFlags & 0x100)) || (lDrawResult != 0)) 
            {
                njCnkEasyMultiDrawObject(model->child);
            }
        }
    
        njPopMatrixEx();
    }
}

// 100% matching!
void    njCnkSimpleDrawModel( NJS_CNK_MODEL *model ) 
{
    njCnkSetCurrentDrawMode(2);
    
    njCnkDrawModelLocal(model);
}

// 100% matching!
void    njCnkSimpleMultiDrawModel( NJS_CNK_MODEL *model )
{
    njCnkSetCurrentDrawMode(3);
    
    njCnkDrawModelLocal(model);
}

// 100% matching!
void njCnkSetCurrentDrawMode(unsigned int ulMode) 
{
    ulCnkCurrentDrawMode = ulMode;
    
    uspCnkCrntTexColCalcTbl = usCnkCsTexColorCalcFunc[ulMode];
    
    pNaCnkCrntLighting = &NaCnkLighting[ulMode];
}

// 99.55% matching
int njCnkDrawModelLocal(NJS_CNK_MODEL* pModel) 
{
    NJS_POINT3 Center;      
    float fRW, fRH;              
    float fSX, fSY;              
    float fZ;                 
    CHUNK_HEAD* pCnk;           
    unsigned int modelclipflag; 
    float temp, temp2; // not from the debugging symbols

    modelclipflag = 0;
    
    if (ulNaCnkFlagModelClip != 0) 
    {
        temp = pModel->r;
        
        if (0 < temp) 
        {
            njCalcPoint(NULL, &pModel->center, &Center);
            
            if ((Center.z + temp) < _fNaViwClipNear) 
            {
                return 0;
            }
            
            if (_fNaViwClipFar < (Center.z - temp))
            {
                return 0;
            }
            
            fZ = fabsf(_nj_screen_.dist / Center.z);
            
            temp2 = temp * fZ;
            
            fRW = temp2 * fNaViwAspectW;
            fRH = temp2 * fNaViwAspectH;
            
            fSX = Center.x * fZ;
            
            if ((fSX + fRW) < -fNaViwHalfW) 
            {
                return 0;
            }
            
            if (fNaViwHalfW < (fSX - fRW)) 
            {
                return 0;
            }
            
            fSY = Center.y * fZ;
            
            if ((fSY + fRH) < -fNaViwHalfH) 
            {
                return 0;
            }
            
            if (fNaViwHalfH < (fSY - fRH)) 
            {
                return 0;
            }
        }
    }
    
    njPushMatrixEx();
    
    pCnk = (CHUNK_HEAD*)pModel->vlist;
    
    if (pCnk != NULL)
    {
        if (pCnk->ucType == 51)
        {
            modelclipflag = 1;
        }
        
        pCnkFuncTbl[pCnk->ucType](pCnk);
    }
    
    njPopMatrixEx();
    
    if ((modelclipflag != 0) && (Vu0ClipFlag != 0)) 
    {
        return 1;  
    } 
    
    if ((Ps2_njControl3D_flag & 0x8000)) 
    {
        njColorBlendingModeSys(lNaCnkSrcBlendMode, lNaCnkDstBlendMode);
    }
    
    pCnk = (CHUNK_HEAD*)pModel->plist;
    
    if (pCnk != NULL) 
    {
        while (pCnk->ucType != 0xFF) 
        {
            pCnk = pCnkFuncTbl[pCnk->ucType](pCnk);
        }
    }
    
    return 1;
}

// 99.41% matching
int njCnkDrawModelLocalMod(NJS_CNK_MODEL* pModel)
{
    NJS_POINT3 Center;      
    float fRW, fRH;              
    float fSX, fSY;              
    float fZ;                 
    CHUNK_HEAD* pCnk;           
    float temp, temp2, temp3; // not from the debugging symbols

    if (ulNaCnkFlagModelClip != 0) 
    {
        temp = pModel->r;
        
        if (0 < temp) 
        {
            njCalcPoint(NULL, &pModel->center, &Center);

            temp3 = Center.z;
            
            printf("POS = %f\n", temp3);
            
            if ((temp3 + temp) < _fNaViwClipNear) 
            {
                return 0;
            }
            
            if (_fNaViwClipFar < (temp3 - temp))
            {
                return 0;
            }
            
            fZ = fabsf(_nj_screen_.dist / temp3);
            
            temp2 = temp * fZ;
            
            fRW = temp2 * fNaViwAspectW;
            fRH = temp2 * fNaViwAspectH;
            
            fSX = Center.x * fZ;
            
            if ((fSX + fRW) < -fNaViwHalfW) 
            {
                return 0;
            }
            
            if (fNaViwHalfW < (fSX - fRW)) 
            {
                return 0;
            }
            
            fSY = Center.y * fZ;
            
            if ((fSY + fRH) < -fNaViwHalfH) 
            {
                return 0;
            }
            
            if (fNaViwHalfH < (fSY - fRH)) 
            {
                return 0;
            }
        }
    }
    
    njPushMatrixEx();
    
    pCnk = (CHUNK_HEAD*)pModel->vlist;
    
    if (pModel->vlist != NULL)
    {
        njCnkCvVMod((CHUNK_HEAD*)pModel->vlist);
    }

    njPopMatrixEx();
    
    if (pModel->plist != NULL) 
    {
        njCnkCoP3((CHUNK_HEAD*)pModel->plist);
    }
    
    return 1;
}

// 100% matching!
CHUNK_HEAD* njCnkCn(CHUNK_HEAD* pCnk)
{
    return (CHUNK_HEAD*)&pCnk->usSize;
}

// 100% matching!
CHUNK_HEAD* njCnkCbBa(CHUNK_HEAD* pCnk) 
{
    if (!(Ps2_njControl3D_flag & 0x8000)) 
    {
        njColorBlendingModeSys((int)lNaCnkSrcAlphaMode[(pCnk->ucHeadBits >> 3) & 0x7], lNaCnkDstAlphaMode[pCnk->ucHeadBits & 0x7]);
    }
    
    return &pCnk[1];
}

// 100% matching!
CHUNK_HEAD* njCnkCbDa(CHUNK_HEAD* pCnk) 
{
    return &pCnk[1];
}

// 100% matching!
CHUNK_HEAD* njCnkCbExp(CHUNK_HEAD* pCnk)
{
    fNaCnkMaterialSpeE = pCnk->ucHeadBits;

    return &pCnk[1];
}

// 100% matching!
CHUNK_HEAD* njCnkCtTid(CHUNK_HEAD* pCnk) 
{
    if (((pCnk->ucHeadBits >> 6) & 0x3)) 
    {
        printf("'Texture Flip' Exist in 'CNK-DATA' !!\n");
    }

    njSetTextureNumSys(pCnk->usSize & 0xFFF);

    if (!(pCnk->usSize & 0x2000)) 
    {
        njTextureFilterMode((pCnk->usSize / 16384) & 0x3);
    }
    
    return &pCnk[1];
}

// 100% matching!
CHUNK_HEAD* njCnkCmD(CHUNK_HEAD* pCnk) 
{
    unsigned char* ucpPtr;
    
    if (!(Ps2_njControl3D_flag & 0x8000)) 
    {
        njColorBlendingModeSys((int)lNaCnkSrcAlphaMode[(pCnk->ucHeadBits >> 3) & 0x7], lNaCnkDstAlphaMode[pCnk->ucHeadBits & 0x7]);
    }

    ucpPtr = (unsigned char*)&pCnk[1];
    
    NaCnkDiffuseMaterial.fB = ucpPtr[0] / 255.0f;
    NaCnkDiffuseMaterial.fG = ucpPtr[1] / 255.0f;
    NaCnkDiffuseMaterial.fR = ucpPtr[2] / 255.0f;
    
    fNaCnkAlphaMaterial = ucpPtr[3] / 255.0f;
    
    return (CHUNK_HEAD*)&ucpPtr[4];
}

// 100% matching!
CHUNK_HEAD* njCnkCmA(CHUNK_HEAD* pCnk)
{
    unsigned char* ucpPtr;
    
    if (!(Ps2_njControl3D_flag & 0x8000)) 
    {
        njColorBlendingModeSys((int)lNaCnkSrcAlphaMode[(pCnk->ucHeadBits >> 3) & 0x7], lNaCnkDstAlphaMode[pCnk->ucHeadBits & 0x7]);
    }
    
    ucpPtr = (unsigned char*)&pCnk[1];
    
    NaCnkAmbientMaterial.fB = ucpPtr[0] / 255.0f;
    NaCnkAmbientMaterial.fG = ucpPtr[1] / 255.0f;
    NaCnkAmbientMaterial.fR = ucpPtr[2] / 255.0f;
    
    NaCnkAmbientEm.fR = NaCnkAmbientFunctionEm.fR * NaCnkAmbientMaterial.fR;
    NaCnkAmbientEm.fG = NaCnkAmbientFunctionEm.fG * NaCnkAmbientMaterial.fG;
    NaCnkAmbientEm.fB = NaCnkAmbientFunctionEm.fB * NaCnkAmbientMaterial.fB;
    
    NaCnkAmbientSm.fR = NaCnkAmbientFunctionSm.fR * NaCnkAmbientMaterial.fR;
    NaCnkAmbientSm.fG = NaCnkAmbientFunctionSm.fG * NaCnkAmbientMaterial.fG;
    NaCnkAmbientSm.fB = NaCnkAmbientFunctionSm.fB * NaCnkAmbientMaterial.fB;
    
    return (CHUNK_HEAD*)&ucpPtr[4];
}

// 100% matching!
CHUNK_HEAD* njCnkCmDa(CHUNK_HEAD* pCnk)
{
    unsigned char* ucpPtr;

    if (!(Ps2_njControl3D_flag & 0x8000)) 
    {
        njColorBlendingModeSys((int)lNaCnkSrcAlphaMode[(pCnk->ucHeadBits >> 3) & 0x7], lNaCnkDstAlphaMode[pCnk->ucHeadBits & 0x7]);
    }
    
    ucpPtr = (unsigned char*)&pCnk[1];
    
    NaCnkDiffuseMaterial.fB = ucpPtr[0] / 255.0f;
    NaCnkDiffuseMaterial.fG = ucpPtr[1] / 255.0f;
    NaCnkDiffuseMaterial.fR = ucpPtr[2] / 255.0f;
    
    fNaCnkAlphaMaterial = ucpPtr[3] / 255.0f;
    
    NaCnkAmbientMaterial.fB = ucpPtr[4] / 255.0f;
    NaCnkAmbientMaterial.fG = ucpPtr[5] / 255.0f;
    NaCnkAmbientMaterial.fR = ucpPtr[6] / 255.0f;
    
    NaCnkAmbientEm.fR = NaCnkAmbientFunctionEm.fR * NaCnkAmbientMaterial.fR;
    NaCnkAmbientEm.fG = NaCnkAmbientFunctionEm.fG * NaCnkAmbientMaterial.fG;
    NaCnkAmbientEm.fB = NaCnkAmbientFunctionEm.fB * NaCnkAmbientMaterial.fB;
    
    NaCnkAmbientSm.fR = NaCnkAmbientFunctionSm.fR * NaCnkAmbientMaterial.fR;
    NaCnkAmbientSm.fG = NaCnkAmbientFunctionSm.fG * NaCnkAmbientMaterial.fG;
    NaCnkAmbientSm.fB = NaCnkAmbientFunctionSm.fB * NaCnkAmbientMaterial.fB;
    
    return (CHUNK_HEAD*)&ucpPtr[8];
}

// 100% matching!
CHUNK_HEAD* njCnkCmS(CHUNK_HEAD* pCnk)
{
    unsigned char* ucpPtr;

    if (!(Ps2_njControl3D_flag & 0x8000)) 
    {
        njColorBlendingModeSys((int)lNaCnkSrcAlphaMode[(pCnk->ucHeadBits >> 3) & 0x7], lNaCnkDstAlphaMode[pCnk->ucHeadBits & 0x7]);
    }
    
    ucpPtr = (unsigned char*)&pCnk[1];
    
    NaCnkSpeculaMaterial.fB = ucpPtr[0] / 255.0f;
    NaCnkSpeculaMaterial.fG = ucpPtr[1] / 255.0f;
    NaCnkSpeculaMaterial.fR = ucpPtr[2] / 255.0f;
    
    fNaCnkMaterialSpeE = ucpPtr[3];
    
    return (CHUNK_HEAD*)&ucpPtr[4];
}

// 100% matching!
CHUNK_HEAD* njCnkCmDs(CHUNK_HEAD* pCnk)
{
    unsigned char* ucpPtr;

    if (!(Ps2_njControl3D_flag & 0x8000)) 
    {
        njColorBlendingModeSys((int)lNaCnkSrcAlphaMode[(pCnk->ucHeadBits >> 3) & 0x7], lNaCnkDstAlphaMode[pCnk->ucHeadBits & 0x7]);
    }
    
    ucpPtr = (unsigned char*)&pCnk[1];
    
    NaCnkDiffuseMaterial.fB = ucpPtr[0] / 255.0f;
    NaCnkDiffuseMaterial.fG = ucpPtr[1] / 255.0f;
    NaCnkDiffuseMaterial.fR = ucpPtr[2] / 255.0f;
    
    fNaCnkAlphaMaterial = ucpPtr[3] / 255.0f;
    
    NaCnkSpeculaMaterial.fB = ucpPtr[4] / 255.0f;
    NaCnkSpeculaMaterial.fG = ucpPtr[5] / 255.0f;
    NaCnkSpeculaMaterial.fR = ucpPtr[6] / 255.0f;
    
    fNaCnkMaterialSpeE = ucpPtr[7];
    
    return (CHUNK_HEAD*)&ucpPtr[8];
}

// 100% matching!
CHUNK_HEAD* njCnkCmAs(CHUNK_HEAD* pCnk)
{
    unsigned char* ucpPtr;

    if (!(Ps2_njControl3D_flag & 0x8000)) 
    {
        njColorBlendingModeSys((int)lNaCnkSrcAlphaMode[(pCnk->ucHeadBits >> 3) & 0x7], lNaCnkDstAlphaMode[pCnk->ucHeadBits & 0x7]);
    }
    
    ucpPtr = (unsigned char*)&pCnk[1];
    
    NaCnkAmbientMaterial.fB = ucpPtr[0] / 255.0f;
    NaCnkAmbientMaterial.fG = ucpPtr[1] / 255.0f;
    NaCnkAmbientMaterial.fR = ucpPtr[2] / 255.0f;
    
    NaCnkAmbientEm.fR = NaCnkAmbientFunctionEm.fR * NaCnkAmbientMaterial.fR;
    NaCnkAmbientEm.fG = NaCnkAmbientFunctionEm.fG * NaCnkAmbientMaterial.fG;
    NaCnkAmbientEm.fB = NaCnkAmbientFunctionEm.fB * NaCnkAmbientMaterial.fB;
    
    NaCnkAmbientSm.fR = NaCnkAmbientFunctionSm.fR * NaCnkAmbientMaterial.fR;
    NaCnkAmbientSm.fG = NaCnkAmbientFunctionSm.fG * NaCnkAmbientMaterial.fG;
    NaCnkAmbientSm.fB = NaCnkAmbientFunctionSm.fB * NaCnkAmbientMaterial.fB;
    
    NaCnkSpeculaMaterial.fB = ucpPtr[4] / 255.0f;
    NaCnkSpeculaMaterial.fG = ucpPtr[5] / 255.0f;
    NaCnkSpeculaMaterial.fR = ucpPtr[6] / 255.0f;
    
    fNaCnkMaterialSpeE = ucpPtr[7];
    
    return (CHUNK_HEAD*)&ucpPtr[8];
}

// 100% matching!
CHUNK_HEAD* njCnkCmDas(CHUNK_HEAD* pCnk)
{
    unsigned char* ucpPtr;

    if (!(Ps2_njControl3D_flag & 0x8000)) 
    {
        njColorBlendingModeSys((int)lNaCnkSrcAlphaMode[(pCnk->ucHeadBits >> 3) & 0x7], lNaCnkDstAlphaMode[pCnk->ucHeadBits & 0x7]);
    }
    
    ucpPtr = (unsigned char*)&pCnk[1];
    
    NaCnkDiffuseMaterial.fB = ucpPtr[0] / 255.0f;
    NaCnkDiffuseMaterial.fG = ucpPtr[1] / 255.0f;
    NaCnkDiffuseMaterial.fR = ucpPtr[2] / 255.0f;
    
    fNaCnkAlphaMaterial = ucpPtr[3] / 255.0f;
    
    NaCnkAmbientMaterial.fB = ucpPtr[4] / 255.0f;
    NaCnkAmbientMaterial.fG = ucpPtr[5] / 255.0f;
    NaCnkAmbientMaterial.fR = ucpPtr[6] / 255.0f;

    NaCnkAmbientEm.fR = NaCnkAmbientFunctionEm.fR * NaCnkAmbientMaterial.fR;
    NaCnkAmbientEm.fG = NaCnkAmbientFunctionEm.fG * NaCnkAmbientMaterial.fG;
    NaCnkAmbientEm.fB = NaCnkAmbientFunctionEm.fB * NaCnkAmbientMaterial.fB;
    
    NaCnkAmbientSm.fR = NaCnkAmbientFunctionSm.fR * NaCnkAmbientMaterial.fR;
    NaCnkAmbientSm.fG = NaCnkAmbientFunctionSm.fG * NaCnkAmbientMaterial.fG;
    NaCnkAmbientSm.fB = NaCnkAmbientFunctionSm.fB * NaCnkAmbientMaterial.fB;
    
    NaCnkSpeculaMaterial.fB = ucpPtr[8] / 255.0f;
    NaCnkSpeculaMaterial.fG = ucpPtr[9] / 255.0f;
    NaCnkSpeculaMaterial.fR = ucpPtr[10] / 255.0f;
    
    fNaCnkMaterialSpeE = ucpPtr[11];
    
    return (CHUNK_HEAD*)&ucpPtr[12];
}

// 100% matching!
CHUNK_HEAD* njCnkCoP4(CHUNK_HEAD* pCnk)
{
    return (CHUNK_HEAD*)((char*)&pCnk[1] + (pCnk->usSize * 2));
}

// 100% matching!
CHUNK_HEAD* njCnkCoSt(CHUNK_HEAD* pCnk)
{
    return (CHUNK_HEAD*)((char*)&pCnk[1] + (pCnk->usSize * 2));
}

// 100% matching! 
CHUNK_HEAD* njCnkCvVn(CHUNK_HEAD* pCnk)
{
    // these variables are arranged in an order different from the debugging symbols
    VU1_STRIP_BUF* pBuffer;
    float* fpCnk;         
    unsigned int ulIndex;  
    CNK_LIGHT* pLightPtr;  
    int lLightCnt;          
    float fI;             
    float fR;              
    float fG;             
    float fB;             
    float fVSZ;         
    float fVSX;            
    float fVSY;          
    float fL;               
    float fX;             
    float fY;              
    float fZ;              
    float fNSX;           
    float fNSY;            
    float fNSZ;            
    float fR00;            
    float fR01;          
    float fR02;          
    float fR10;            
    float fR11;             
    float fR12;            
    float fR20;           
    float fR21;            
    float fR22;             
    float fTRX;             
    float fTRY;             
    float fTRZ;             
    float f3;            // not from the debugging symbols
    float f25;           // not from the debugging symbols
    float f26, f27, f28; // not from the debugging symbols
    float f29, f30, f31; // not from the debugging symbols

    pBuffer = &pNaCnkVerBufTop[*(unsigned short*)&pCnk[1]];
    
    fpCnk = &((float*)&pCnk[1])[1];
    
    fR00 = pNaMatMatrixStuckPtr[0][0];
    fR01 = pNaMatMatrixStuckPtr[0][1];
    fR02 = pNaMatMatrixStuckPtr[0][2];
    
    fR10 = pNaMatMatrixStuckPtr[0][4];
    fR11 = pNaMatMatrixStuckPtr[0][5];
    fR12 = pNaMatMatrixStuckPtr[0][6];
    
    fR20 = pNaMatMatrixStuckPtr[0][8];
    fR21 = pNaMatMatrixStuckPtr[0][9];
    fR22 = pNaMatMatrixStuckPtr[0][10];
    
    fTRX = pNaMatMatrixStuckPtr[0][12];
    fTRY = pNaMatMatrixStuckPtr[0][13];
    fTRZ = pNaMatMatrixStuckPtr[0][14];
    
    for (ulIndex = ((unsigned short*)&pCnk[1])[1]; ulIndex != 0; ulIndex--, pBuffer++)
    {
        fX = *fpCnk++;
        fY = *fpCnk++;
        fZ = *fpCnk++;
        
        fVSX = fTRX + (fR00 * fX) + (fR10 * fY) + (fR20 * fZ);
        fVSY = fTRY + (fR01 * fX) + (fR11 * fY) + (fR21 * fZ);
        fVSZ = fTRZ + (fR02 * fX) + (fR12 * fY) + (fR22 * fZ);

        pBuffer->fVx = fVSX;
        pBuffer->fVy = fVSY;
        pBuffer->fVz = fVSZ;

        pBuffer->fFog = njCalcFogPower(fVSZ);

        fI = 1.0f / fVSZ;
        
        f3 = _nj_screen_.dist * fI;
        
        pBuffer->fSx = fNaViwAspectW * (fVSX * f3);
        pBuffer->fSy = fNaViwAspectH * (fVSY * f3);
        pBuffer->fIz = fI;

        fB = 0;
        fG = 0;
        fR = 0;

        fNSX = *fpCnk++;
        fNSY = *fpCnk++;
        fNSZ = *fpCnk++;

        f26 = (fR00 * fNSX) + (fR10 * fNSY) + (fR20 * fNSZ); 
        f27 = (fR01 * fNSX) + (fR11 * fNSY) + (fR21 * fNSZ);
        f28 = (fR02 * fNSX) + (fR12 * fNSY) + (fR22 * fNSZ);

        pBuffer->fNz = f28;

        pLightPtr = pNaCnkCrntLighting->pLightTop;
        
        for (lLightCnt = pNaCnkCrntLighting->lLightMax; lLightCnt != 0; lLightCnt--, pLightPtr++) 
        {
            if (pLightPtr->ulState != 0)
            {
                if (pLightPtr->ulMode == 0) 
                {
                    f3 = (f26 * pLightPtr->fCx) + (f27 * pLightPtr->fCy) + (f28 * pLightPtr->fCz);
                    
                    if (f3 > 0) 
                    {
                        f3 *= pLightPtr->fI;
                        goto label;
                    }
                }
                else 
                {
                    f29 = pLightPtr->fCx - fVSX;
                    f30 = pLightPtr->fCy - fVSY;
                    f31 = pLightPtr->fCz - fVSZ;
                    
                    f25 = (f29 * f29) + (f30 * f30) + (f31 * f31);
                    
                    if (pLightPtr->fFarRR > f25) 
                    {
                        fL = njInvertSqrt(f25);
                        
                        f29 *= fL;
                        f30 *= fL;
                        f31 *= fL; 
                        
                        f3 = (f26 * f29) + (f27 * f30) + (f28 * f31);
                        
                        if (f3 > 0) 
                        {
                            if (pLightPtr->fNearRR < f25) 
                            {
                                f3 *= pLightPtr->fNearRR / f25;
                            }

                            label:
                            fR += f3 * pLightPtr->fR;
                            fG += f3 * pLightPtr->fG;
                            fB += f3 * pLightPtr->fB;
                        }
                    }
                }
            }
        }
        
        pBuffer->fIr = fR;
        pBuffer->fIg = fG;
        pBuffer->fIb = fB;
    } 
    
    return (CHUNK_HEAD*)fpCnk;
}

// 98.11% matching
CHUNK_HEAD* njCnkCvVnPs2(CHUNK_HEAD* pCnk)
{
    VU1_STRIP_BUF* pBuffer;                                    
    unsigned int ulIndex;                                      
    float* fpCnk;                                               
    float fog;                                                  
    float v[11][4];                                              
    CNK_LIGHT* lp;                                               
    unsigned int tmp;                                            
    static unsigned int mask[5] = { 0, 0x88, 0xCC, 0xEE, 0xFF }; 

    fog = 0;

    lp = pNaCnkCrntLighting->pLightTop;
    
    v[0][0] = lp->fCx;
    v[0][1] = lp[1].fCx;
    v[0][2] = lp[2].fCx;
    v[0][3] = lp[3].fCx;
    
    v[1][0] = lp->fCy;
    v[1][1] = lp[1].fCy;
    v[1][2] = lp[2].fCy;
    v[1][3] = lp[3].fCy;
    
    v[2][0] = lp->fCz;
    v[2][1] = lp[1].fCz;
    v[2][2] = lp[2].fCz;
    v[2][3] = lp[3].fCz;

    tmp = lp[3].ulMode | ((lp[2].ulMode * 2) | ((lp[1].ulMode * 4) | ((lp->ulMode * 8) | ((lp[3].ulState * 16) | ((lp[2].ulState * 32) | ((lp->ulState * 128) | (lp[1].ulState * 64)))))));
    
    tmp &= mask[pNaCnkCrntLighting->lLightMax];
    
    *(int*)&v[3][0] = tmp;
    
    v[4][0] = lp->fNearRR;
    v[4][1] = lp[1].fNearRR;
    v[4][2] = lp[2].fNearRR;
    v[4][3] = lp[3].fNearRR;
    
    v[5][0] = lp->fFarRR;
    v[5][1] = lp[1].fFarRR;
    v[5][2] = lp[2].fFarRR;
    v[5][3] = lp[3].fFarRR;
    
    v[6][0] = lp->fI;
    v[6][1] = lp[1].fI;
    v[6][2] = lp[2].fI;
    v[6][3] = lp[3].fI;
    
    v[7][0] = lp->fR;
    v[7][1] = lp->fG;
    v[7][2] = lp->fB;
    v[7][3] = lp->fI;
    
    v[8][0] = lp[1].fR;
    v[8][1] = lp[1].fG;
    v[8][2] = lp[1].fB;
    v[8][3] = lp[1].fI;
    
    v[9][0] = lp[2].fR;
    v[9][1] = lp[2].fG;
    v[9][2] = lp[2].fB;
    v[9][3] = lp[2].fI;
    
    v[10][0] = lp[3].fR;
    v[10][1] = lp[3].fG;
    v[10][2] = lp[3].fB;
    v[10][3] = lp[3].fI;
    
    asm volatile 
    ("
    .set noreorder
        move v1, %0
        
        lqc2 vf4,     0(v1) 
        lqc2 vf5,  0x10(v1) 
        lqc2 vf6,  0x20(v1) 
        lqc2 vf7,  0x30(v1) 
        lqc2 vf8,  0x40(v1) 
        lqc2 vf9,  0x50(v1) 
        lqc2 vf10, 0x60(v1) 
        lqc2 vf11, 0x70(v1) 
        lqc2 vf12, 0x80(v1) 
        lqc2 vf13, 0x90(v1) 
        lqc2 vf14, 0xA0(v1) 
    .set reorder
    " : : "r"(v) : "$v1", "memory" 
    ); 
        
    pCnk = (CHUNK_HEAD*)((int)pCnk | 0x30000000);
    
    pCnk++;
    
    ulIndex = pCnk->usSize;
    
    fpCnk = (float*)&pCnk[1];
    
    fpCnk += 14;
    
    pBuffer = &pNaCnkVerBufTop[*(unsigned short*)&pCnk[0]];
    
    njSetMatrixCN(pNaMatMatrixStuckPtr);
    
    asm volatile 
    ("
    .set noreorder
        vcallms  VU0_MINMAX 
    
        lqc2     vf4,    0(%2)
        lqc2     vf5, 0x10(%2)
        
        vcallms  VU0_CALCPOINT_END 
    
        qmfc2.i  t0, vf7 
        qmfc2.i  t1, vf18 
        qmfc2.i  t2, vf6 
        
        sq       t0, 0x10(%1)
        sq       t1, 0x20(%1)
        sq       t2, 0x30(%1)
        
        qmfc2.ni t3, vf11 
        
        mtc1     t3, %0  
    .set reorder
    " : "=f"(fog) : "r"(pBuffer), "r"(fpCnk) : "$f20", "$s1", "$s2", "memory" 
    ); 
        
    ulIndex--;
    
    pBuffer++;
    
    fpCnk += 8;
    
    while (ulIndex != 0)
    {
        asm volatile 
        ("
        .set noreorder
            lqc2    vf4,    0(%0)
            lqc2    vf5, 0x10(%0)
            
            vcallms VU0_CALCPOINT_END
            nop
        .set reorder
        " : : "r"(fpCnk) : "$s2", "memory" 
        ); 
            
        pBuffer[-1].fFog = njCalcFogPowerEx(fog);
        
        asm volatile 
        ("
        .set noreorder
            qmfc2.i  t0, vf7 
            qmfc2.i  t1, vf18 
            qmfc2.i  t2, vf6
         
            sq       t0, 0x10(%2)
            sq       t1, 0x20(%2)
            sq       t2, 0x30(%2)
        
            qmfc2.ni t3, vf11 
        
            mtc1     t3, %0
        
            cfc2.ni  t0, vi11 
        
            sw       t0, 0(%1)
        .set reorder
        " : "=f"(fog) : "r"(&Vu0ClipFlag), "r"(pBuffer) : "$f20", "$v0", "$s1", "memory" 
        ); 

        ulIndex--;
        
        pBuffer++;
        
        fpCnk += 8; 
    }
    
    pBuffer[-1].fFog = njCalcFogPowerEx(fog);
    
    asm volatile 
    ("
    .set noreorder 
        vcallms VU0_CALCPOINT_INIT 
    .set reorder 
    ");
    
    return (CHUNK_HEAD*)fpCnk;
}

// 100% matching! 
CHUNK_HEAD* njCnkCvVMod(CHUNK_HEAD* pCnk)
{
    VU1_STRIP_BUF* pBuffer;
    unsigned int ulIndex;
    float* fpCnk;
    float fI;
    float fVSZ, fVSX, fVSY;
    float fX, fY, fZ;
    float fR00, fR01, fR02;
    float fR10, fR11, fR12;
    float fR20, fR21, fR22;
    float fTRX, fTRY, fTRZ;
    float temp; // not from the debugging symbols

    pBuffer = &pNaCnkVerBufTop[((unsigned short*)&pCnk[1])[0]];
    
    ulIndex = ((unsigned short*)&pCnk[1])[1];
    
    fpCnk = &((float*)&pCnk[1])[1];

    fR00 = pNaMatMatrixStuckPtr[0][0];
    fR01 = pNaMatMatrixStuckPtr[0][1];
    fR02 = pNaMatMatrixStuckPtr[0][2];
    
    fR10 = pNaMatMatrixStuckPtr[0][4];
    fR11 = pNaMatMatrixStuckPtr[0][5];
    fR12 = pNaMatMatrixStuckPtr[0][6];
    
    fR20 = pNaMatMatrixStuckPtr[0][8];
    fR21 = pNaMatMatrixStuckPtr[0][9];
    fR22 = pNaMatMatrixStuckPtr[0][10];
    
    fTRX = pNaMatMatrixStuckPtr[0][12];
    fTRY = pNaMatMatrixStuckPtr[0][13];
    fTRZ = pNaMatMatrixStuckPtr[0][14];
    
    Ps2_shadow_z = 0;
    
    for ( ; ulIndex != 0; ulIndex--)
    {
        fX = fpCnk[0];
        fY = fpCnk[1];
        fZ = fpCnk[2];

        fVSX = ((fTRX + (fR00 * fX)) + (fR10 * fY)) + (fR20 * fZ);
        fVSY = ((fTRY + (fR01 * fX)) + (fR11 * fY)) + (fR21 * fZ);
        fVSZ = ((fTRZ + (fR02 * fX)) + (fR12 * fY)) + (fR22 * fZ);

        fpCnk += 3;

        pBuffer->fVx = fVSX;
        pBuffer->fVy = fVSY;
        pBuffer->fVz = fVSZ;
        
        if (fVSZ < 1.0f)
        {
            Ps2_shadow_z = 1;
        }
        
        pBuffer->fFog = njCalcFogPower(fVSZ);
        
        fI = 1.0f / fVSZ;
        
        temp = _nj_screen_.dist * fI;
        
        pBuffer->fSx = fNaViwAspectW * (fVSX * temp);
        pBuffer->fSy = fNaViwAspectH * (fVSY * temp);
        pBuffer->fIz = fI;
        
        pBuffer++;
    } 
    
    return (CHUNK_HEAD*)fpCnk;
}

// 100% matching! 
CHUNK_HEAD* njCnkCoP3(CHUNK_HEAD* pCnk)
{
    unsigned short* uspCnk;
    VU1_STRIP_BUF* pV0;    
    VU1_STRIP_BUF* pV1;     
    VU1_STRIP_BUF* pV2;     
    CNK_PRIM_BUF* pP;       
    unsigned short usNext;  
    unsigned short usPoly;  
    float fNormal;          
    void *dp; // not from the debugging symbols

    uspCnk = (unsigned short*)&pCnk[1];
    
    usNext = (*uspCnk >> 14) & 0x3;
    usPoly = *uspCnk & 0x3FFF;

    uspCnk++;

    if (usPoly != 0) 
    {
        do 
        {
            pP = (CNK_PRIM_BUF*)NaCnkStrBufTop;

            pV0 = &pNaCnkVerBufTop[*uspCnk++];
            
            pP->fQ = pV0->fIz;
            
            pP->fR = 32.0f;
            pP->fG = 32.0f;
            pP->fB = 32.0f;
            pP->fA = 128.0f;
            
            pP->fX = fNaViwOffsetX + pV0->fSx;
            pP->fY = fNaViwOffsetY + pV0->fSy;
            pP->fZ = pV0->fVz;
            
            pP->fF = pV0->fFog;

            if (pP->fX < Ps2_shadow_vec[0]) 
            {
                Ps2_shadow_vec[0] = pP->fX;
            }

            if (pP->fY < Ps2_shadow_vec[1]) 
            {
                Ps2_shadow_vec[1] = pP->fY;
            }

            if (pP->fX > Ps2_shadow_vec[2])
            {
                Ps2_shadow_vec[2] = pP->fX;
            }

            if (pP->fY > Ps2_shadow_vec[3])
            {
                Ps2_shadow_vec[3] = pP->fY;
            }

            pV1 = &pNaCnkVerBufTop[*uspCnk++];

            pP++;
            
            pP->fQ = pV1->fIz;
            
            pP->fR = 32.0f;
            pP->fG = 32.0f;
            pP->fB = 32.0f;
            pP->fA = 128.0f;
            
            pP->fX = fNaViwOffsetX + pV1->fSx;
            pP->fY = fNaViwOffsetY + pV1->fSy;
            pP->fZ = pV1->fVz;
            
            pP->fF = pV1->fFog;

            if (pP->fX < Ps2_shadow_vec[0])
            {
                Ps2_shadow_vec[0] = pP->fX;
            }

            if (pP->fY < Ps2_shadow_vec[1]) 
            {
                Ps2_shadow_vec[1] = pP->fY;
            }

            if (pP->fX > Ps2_shadow_vec[2]) 
            {
                Ps2_shadow_vec[2] = pP->fX;
            }

            if (pP->fY > Ps2_shadow_vec[3])
            {
                Ps2_shadow_vec[3] = pP->fY;
            }

            pV2 = &pNaCnkVerBufTop[*uspCnk++];
            
            pP++;
            
            pP->fQ = pV2->fIz;
            
            pP->fR = 32.0f;
            pP->fG = 32.0f;
            pP->fB = 32.0f;
            pP->fA = 128.0f;
            
            pP->fX = fNaViwOffsetX + pV2->fSx;
            pP->fY = fNaViwOffsetY + pV2->fSy;
            pP->fZ = pV2->fVz;
            
            pP->fF = pV2->fFog;

            if (pP->fX < Ps2_shadow_vec[0])
            {
                Ps2_shadow_vec[0] = pP->fX;
            }

            if (pP->fY < Ps2_shadow_vec[1])
            {
                Ps2_shadow_vec[1] = pP->fY;
            }

            if (pP->fX > Ps2_shadow_vec[2])
            {
                Ps2_shadow_vec[2] = pP->fX;
            }

            if (pP->fY > Ps2_shadow_vec[3])
            {
                Ps2_shadow_vec[3] = pP->fY;
            }
            
            fNormal = ((pV1->fSx - pV2->fSx) * (pV0->fSy - pV2->fSy)) - ((pV0->fSx - pV2->fSx) * (pV1->fSy - pV2->fSy));

            if (lCnkModClipFace != 0)
            {
                if (fNormal < 0)
                {
                    pP->ulKick = 0;
                }
                else 
                {
                    pP->ulKick = 32768;
                }
            } 
            else if (fNormal <= 0) 
            {
                pP->ulKick = 32768;
            } 
            else 
            {
                pP->ulKick = 0;
            }

            uspCnk += usNext;

            Ps2AddPrim3DMod(SCE_GIF_SET_TAG(0, SCE_GS_FALSE, SCE_GS_FALSE, SCE_GS_SET_PRIM(SCE_GS_PRIM_TRI, 0, 0, 0, 1, 0, 0, 1, 0), SCE_GIF_PACKED, 0), dp = NaCnkStrBufTop, 3);

            usPoly--;
        } while (usPoly != 0);
    }

    Ps2_shadow_fog = pV2->fFog;

    return (CHUNK_HEAD*)uspCnk;
}

// 100% matching! 
CHUNK_HEAD* njCnkCs(CHUNK_HEAD* pCnk)
{ 
    VU1_STRIP_BUF* pS;
    VU1_STRIP_BUF* pV;
    unsigned short usNext;
    unsigned short usMax;
    unsigned short usClip;
    unsigned short usColorCalc;
    int ulMode; // not from the debugging symbols
    unsigned long ulType;           
    unsigned short usCnt;
    unsigned short* uspCnk;                                                        
    unsigned short usStrip;                                                      
    unsigned short usColorCalc2; // not from the debugging symbols
    void (*pVu1Func)(unsigned long, VU1_STRIP_BUF*, unsigned short, unsigned short); 

    ulType = 0x12000000000000;

    if (((ulMode = ulNaCnkFlagConstAttr ? ucNaCnkAttr : pCnk->ucHeadBits) & 0x8)) 
    { 
        ulType |= 0x20000000000000;
    }

    if (!(ulMode & 0x20)) 
    {
        ulType |= 0x4000000000000;
    }
    
    if (ulNaCnkFlagConstMaterial != 0) 
    {
        vu1SetDiffuseMaterial(&NaCnkConstantMaterial); 
        vu1SetAlphaRatio(fNaCnkConstantA); 
        
        usColorCalc = 1;
    } 
    else
    {
        vu1SetDiffuseMaterial(&NaCnkDiffuseMaterial);
        vu1SetAmbient(pNaCnkCrntLighting->pAmbient);
        vu1SetAlphaRatio(fNaCnkAlphaMaterial);
        
        usColorCalc = usCnkCsPolColorCalcFunc[ulMode & 0x7];
    }
    
    pVu1Func = pCnkCsVu1FuncTbl[(ulMode & 0x18) | ulCnkCurrentDrawMode]; 
    
    usColorCalc2 = usColorCalc;
    
    uspCnk = (unsigned short*)&pCnk[1];
    
    usNext = (*uspCnk >> 14) & 0x3;
    
    usStrip = *uspCnk & 0x3FFF;
    
    uspCnk++; 
    
    for ( ; usStrip; usStrip--)
    {
        pS = NaCnkStrBufTop;
        
        usClip = *uspCnk & 0x8000; 
        
        usCnt = usMax = usClip ? ~*uspCnk + 1 : *uspCnk; 
        
        uspCnk++;
        
        pV = &pNaCnkVerBufTop[*uspCnk];

        uspCnk++;
        
        *(u_long128*)&pS->fVx = *(u_long128*)&pV->fVx; 
        *(u_long128*)&pS->fSx = *(u_long128*)&pV->fSx; 
        *(u_long128*)&pS->fIr = *(u_long128*)&pV->fIr; 
        
        pS++;
        
        pV = &pNaCnkVerBufTop[*uspCnk];

        uspCnk++;
        
        *(u_long128*)&pS->fVx = *(u_long128*)&pV->fVx; 
        *(u_long128*)&pS->fSx = *(u_long128*)&pV->fSx; 
        *(u_long128*)&pS->fIr = *(u_long128*)&pV->fIr; 

        pS++;
        
        for (usCnt = usMax - 2; usCnt; usCnt--) 
        {
            pV = &pNaCnkVerBufTop[*uspCnk];

            uspCnk++;
            
            *(u_long128*)&pS->fVx = *(u_long128*)&pV->fVx; 
            *(u_long128*)&pS->fSx = *(u_long128*)&pV->fSx; 
            *(u_long128*)&pS->fIr = *(u_long128*)&pV->fIr; 
            
            pS++; 
            
            uspCnk += usNext;
        }
        
        pVu1Func(ulType, NaCnkStrBufTop, usMax, usClip | usColorCalc2);
    }
    
    return (CHUNK_HEAD*)uspCnk;
}

// 100% matching!
int _CVV(float* v0)
{
    register int ret;
    
    asm volatile 
    {
                      
        lqc2         vf4, 0(a0)
        
        vmulax.xyzw  ACC, vf24, vf4x
            
        vmadday.xyzw ACC, vf25, vf4y
        vmaddaz.xyzw ACC, vf26, vf4z
            
        vmaddw.xyzw  vf5, vf27, vf0w
        
        vclipw.xyz   vf5, vf5w  
        vnop
        vnop
        vnop
        vnop
        vnop
    
        cfc2.ni      ret, vi18
        
        jr           ra
        nop
            
    } 
}

// 
// Start address: 0x2d25a0
CHUNK_HEAD* njCnkCsUvh(CHUNK_HEAD* pCnk)
{
	unsigned int cflag;
	float zbuff[4];
	unsigned int coflag;
	//_anon17* timp;
	unsigned long vu1func_tag;
	unsigned long ulVuflag;
	unsigned long* ulpP;
	int sExit;
	void(*pVu1Func)(unsigned long, VU1_STRIP_BUF*, unsigned short, unsigned short);
	unsigned short usColorCalc;
	unsigned short usClip;
	unsigned short usNum;
	unsigned short usMax;
	unsigned short usCnt;
	unsigned short usStrip;
	unsigned short usNext;
	VU1_STRIP_BUF* pSorg;
	VU1_STRIP_BUF* pS;
	VU1_STRIP_BUF* pV;
	unsigned short* uspCnk;
	unsigned long ulType2;
	unsigned long ulType;
	unsigned char ucFlag;
	// Line 19, Address: 0x2d25a0, Func Offset: 0
	// Line 21, Address: 0x2d25bc, Func Offset: 0x1c
	// Line 19, Address: 0x2d25c0, Func Offset: 0x20
	// Line 21, Address: 0x2d25c8, Func Offset: 0x28
	// Line 19, Address: 0x2d25d0, Func Offset: 0x30
	// Line 22, Address: 0x2d25d4, Func Offset: 0x34
	// Line 19, Address: 0x2d25d8, Func Offset: 0x38
	// Line 22, Address: 0x2d25dc, Func Offset: 0x3c
	// Line 35, Address: 0x2d25e0, Func Offset: 0x40
	// Line 36, Address: 0x2d25fc, Func Offset: 0x5c
	// Line 40, Address: 0x2d2604, Func Offset: 0x64
	// Line 41, Address: 0x2d2614, Func Offset: 0x74
	// Line 42, Address: 0x2d2620, Func Offset: 0x80
	// Line 41, Address: 0x2d2624, Func Offset: 0x84
	// Line 48, Address: 0x2d262c, Func Offset: 0x8c
	// Line 49, Address: 0x2d263c, Func Offset: 0x9c
	// Line 50, Address: 0x2d2648, Func Offset: 0xa8
	// Line 49, Address: 0x2d264c, Func Offset: 0xac
	// Line 55, Address: 0x2d2654, Func Offset: 0xb4
	// Line 57, Address: 0x2d2664, Func Offset: 0xc4
	// Line 58, Address: 0x2d2670, Func Offset: 0xd0
	// Line 59, Address: 0x2d267c, Func Offset: 0xdc
	// Line 60, Address: 0x2d2680, Func Offset: 0xe0
	// Line 63, Address: 0x2d2688, Func Offset: 0xe8
	// Line 64, Address: 0x2d2698, Func Offset: 0xf8
	// Line 65, Address: 0x2d26a8, Func Offset: 0x108
	// Line 66, Address: 0x2d26b8, Func Offset: 0x118
	// Line 67, Address: 0x2d26c4, Func Offset: 0x124
	// Line 72, Address: 0x2d26e4, Func Offset: 0x144
	// Line 78, Address: 0x2d26f8, Func Offset: 0x158
	// Line 76, Address: 0x2d26fc, Func Offset: 0x15c
	// Line 72, Address: 0x2d2700, Func Offset: 0x160
	// Line 86, Address: 0x2d2710, Func Offset: 0x170
	// Line 72, Address: 0x2d2714, Func Offset: 0x174
	// Line 86, Address: 0x2d2718, Func Offset: 0x178
	// Line 79, Address: 0x2d271c, Func Offset: 0x17c
	// Line 78, Address: 0x2d2720, Func Offset: 0x180
	// Line 86, Address: 0x2d2724, Func Offset: 0x184
	// Line 87, Address: 0x2d272c, Func Offset: 0x18c
	// Line 97, Address: 0x2d2754, Func Offset: 0x1b4
	// Line 99, Address: 0x2d277c, Func Offset: 0x1dc
	// Line 100, Address: 0x2d2780, Func Offset: 0x1e0
	// Line 101, Address: 0x2d2788, Func Offset: 0x1e8
	// Line 104, Address: 0x2d278c, Func Offset: 0x1ec
	// Line 105, Address: 0x2d2798, Func Offset: 0x1f8
	// Line 106, Address: 0x2d27a4, Func Offset: 0x204
	// Line 107, Address: 0x2d27ac, Func Offset: 0x20c
	// Line 108, Address: 0x2d27b4, Func Offset: 0x214
	// Line 112, Address: 0x2d27bc, Func Offset: 0x21c
	// Line 113, Address: 0x2d27c4, Func Offset: 0x224
	// Line 115, Address: 0x2d27cc, Func Offset: 0x22c
	// Line 114, Address: 0x2d27dc, Func Offset: 0x23c
	// Line 115, Address: 0x2d27e0, Func Offset: 0x240
	// Line 116, Address: 0x2d27e8, Func Offset: 0x248
	// Line 117, Address: 0x2d27f8, Func Offset: 0x258
	// Line 120, Address: 0x2d2804, Func Offset: 0x264
	// Line 118, Address: 0x2d2808, Func Offset: 0x268
	// Line 117, Address: 0x2d2810, Func Offset: 0x270
	// Line 118, Address: 0x2d2814, Func Offset: 0x274
	// Line 119, Address: 0x2d2818, Func Offset: 0x278
	// Line 124, Address: 0x2d2820, Func Offset: 0x280
	// Line 118, Address: 0x2d2824, Func Offset: 0x284
	// Line 119, Address: 0x2d2828, Func Offset: 0x288
	// Line 124, Address: 0x2d282c, Func Offset: 0x28c
	// Line 125, Address: 0x2d2830, Func Offset: 0x290
	// Line 119, Address: 0x2d2838, Func Offset: 0x298
	// Line 120, Address: 0x2d283c, Func Offset: 0x29c
	// Line 126, Address: 0x2d2840, Func Offset: 0x2a0
	// Line 127, Address: 0x2d2848, Func Offset: 0x2a8
	// Line 120, Address: 0x2d2850, Func Offset: 0x2b0
	// Line 121, Address: 0x2d2854, Func Offset: 0x2b4
	// Line 131, Address: 0x2d285c, Func Offset: 0x2bc
	// Line 135, Address: 0x2d2864, Func Offset: 0x2c4
	// Line 136, Address: 0x2d286c, Func Offset: 0x2cc
	// Line 121, Address: 0x2d2870, Func Offset: 0x2d0
	// Line 122, Address: 0x2d2874, Func Offset: 0x2d4
	// Line 136, Address: 0x2d287c, Func Offset: 0x2dc
	// Line 137, Address: 0x2d2880, Func Offset: 0x2e0
	// Line 122, Address: 0x2d2888, Func Offset: 0x2e8
	// Line 123, Address: 0x2d288c, Func Offset: 0x2ec
	// Line 138, Address: 0x2d2894, Func Offset: 0x2f4
	// Line 139, Address: 0x2d289c, Func Offset: 0x2fc
	// Line 141, Address: 0x2d28a0, Func Offset: 0x300
	// Line 123, Address: 0x2d28a4, Func Offset: 0x304
	// Line 124, Address: 0x2d28a8, Func Offset: 0x308
	// Line 141, Address: 0x2d28ac, Func Offset: 0x30c
	// Line 124, Address: 0x2d28c0, Func Offset: 0x320
	// Line 125, Address: 0x2d28c4, Func Offset: 0x324
	// Line 144, Address: 0x2d28c8, Func Offset: 0x328
	// Line 128, Address: 0x2d28d0, Func Offset: 0x330
	// Line 139, Address: 0x2d28d4, Func Offset: 0x334
	// Line 125, Address: 0x2d28d8, Func Offset: 0x338
	// Line 126, Address: 0x2d28dc, Func Offset: 0x33c
	// Line 142, Address: 0x2d28e0, Func Offset: 0x340
	// Line 144, Address: 0x2d28e4, Func Offset: 0x344
	// Line 126, Address: 0x2d28ec, Func Offset: 0x34c
	// Line 127, Address: 0x2d28f0, Func Offset: 0x350
	// Line 128, Address: 0x2d28f8, Func Offset: 0x358
	// Line 129, Address: 0x2d2900, Func Offset: 0x360
	// Line 130, Address: 0x2d290c, Func Offset: 0x36c
	// Line 131, Address: 0x2d2910, Func Offset: 0x370
	// Line 132, Address: 0x2d2914, Func Offset: 0x374
	// Line 133, Address: 0x2d2920, Func Offset: 0x380
	// Line 134, Address: 0x2d292c, Func Offset: 0x38c
	// Line 135, Address: 0x2d2930, Func Offset: 0x390
	// Line 136, Address: 0x2d2934, Func Offset: 0x394
	// Line 137, Address: 0x2d293c, Func Offset: 0x39c
	// Line 138, Address: 0x2d2944, Func Offset: 0x3a4
	// Line 139, Address: 0x2d294c, Func Offset: 0x3ac
	// Line 141, Address: 0x2d2954, Func Offset: 0x3b4
	// Line 144, Address: 0x2d2958, Func Offset: 0x3b8
	// Line 145, Address: 0x2d2960, Func Offset: 0x3c0
	// Line 148, Address: 0x2d2974, Func Offset: 0x3d4
	// Line 151, Address: 0x2d297c, Func Offset: 0x3dc
	// Line 152, Address: 0x2d2988, Func Offset: 0x3e8
	// Line 153, Address: 0x2d29a0, Func Offset: 0x400
	// Line 152, Address: 0x2d29a4, Func Offset: 0x404
	// Line 155, Address: 0x2d29a8, Func Offset: 0x408
	// Line 156, Address: 0x2d29ac, Func Offset: 0x40c
	// Line 161, Address: 0x2d29b0, Func Offset: 0x410
	// Line 167, Address: 0x2d29d8, Func Offset: 0x438
	// Line 168, Address: 0x2d29e8, Func Offset: 0x448
	// Line 170, Address: 0x2d29f0, Func Offset: 0x450
	// Line 171, Address: 0x2d29f8, Func Offset: 0x458
	// Line 173, Address: 0x2d29fc, Func Offset: 0x45c
	// Line 175, Address: 0x2d2a00, Func Offset: 0x460
	// Line 178, Address: 0x2d2a0c, Func Offset: 0x46c
	// Line 175, Address: 0x2d2a14, Func Offset: 0x474
	// Line 178, Address: 0x2d2a28, Func Offset: 0x488
	// Line 176, Address: 0x2d2a38, Func Offset: 0x498
	// Line 178, Address: 0x2d2a3c, Func Offset: 0x49c
	// Line 177, Address: 0x2d2a40, Func Offset: 0x4a0
	// Line 178, Address: 0x2d2a44, Func Offset: 0x4a4
	// Line 179, Address: 0x2d2a4c, Func Offset: 0x4ac
	// Line 183, Address: 0x2d2a64, Func Offset: 0x4c4
	// Line 179, Address: 0x2d2a68, Func Offset: 0x4c8
	// Line 180, Address: 0x2d2a7c, Func Offset: 0x4dc
	// Line 183, Address: 0x2d2a84, Func Offset: 0x4e4
	// Line 185, Address: 0x2d2a8c, Func Offset: 0x4ec
	// Line 186, Address: 0x2d2a90, Func Offset: 0x4f0
	// Line 187, Address: 0x2d2a94, Func Offset: 0x4f4
	// Line 188, Address: 0x2d2a98, Func Offset: 0x4f8
	// Line 189, Address: 0x2d2a9c, Func Offset: 0x4fc
	// Line 190, Address: 0x2d2aa0, Func Offset: 0x500
	// Line 191, Address: 0x2d2aa4, Func Offset: 0x504
	// Line 193, Address: 0x2d2aa8, Func Offset: 0x508
	// Line 194, Address: 0x2d2aac, Func Offset: 0x50c
	// Line 195, Address: 0x2d2ab0, Func Offset: 0x510
	// Line 196, Address: 0x2d2ab4, Func Offset: 0x514
	// Line 198, Address: 0x2d2ab8, Func Offset: 0x518
	// Line 199, Address: 0x2d2abc, Func Offset: 0x51c
	// Line 200, Address: 0x2d2ac0, Func Offset: 0x520
	// Line 201, Address: 0x2d2ac4, Func Offset: 0x524
	// Line 202, Address: 0x2d2ac8, Func Offset: 0x528
	// Line 204, Address: 0x2d2ad0, Func Offset: 0x530
	// Line 206, Address: 0x2d2ad4, Func Offset: 0x534
	// Line 207, Address: 0x2d2ad8, Func Offset: 0x538
	// Line 208, Address: 0x2d2adc, Func Offset: 0x53c
	// Line 209, Address: 0x2d2ae0, Func Offset: 0x540
	// Line 210, Address: 0x2d2ae4, Func Offset: 0x544
	// Line 211, Address: 0x2d2ae8, Func Offset: 0x548
	// Line 212, Address: 0x2d2aec, Func Offset: 0x54c
	// Line 214, Address: 0x2d2af0, Func Offset: 0x550
	// Line 217, Address: 0x2d2af8, Func Offset: 0x558
	// Line 218, Address: 0x2d2afc, Func Offset: 0x55c
	// Line 219, Address: 0x2d2b00, Func Offset: 0x560
	// Line 220, Address: 0x2d2b04, Func Offset: 0x564
	// Line 221, Address: 0x2d2b08, Func Offset: 0x568
	// Line 222, Address: 0x2d2b0c, Func Offset: 0x56c
	// Line 223, Address: 0x2d2b10, Func Offset: 0x570
	// Line 224, Address: 0x2d2b14, Func Offset: 0x574
	// Line 227, Address: 0x2d2b18, Func Offset: 0x578
	// Line 231, Address: 0x2d2b20, Func Offset: 0x580
	// Line 233, Address: 0x2d2b30, Func Offset: 0x590
	// Line 239, Address: 0x2d2b38, Func Offset: 0x598
	// Line 242, Address: 0x2d2b6c, Func Offset: 0x5cc
	// Line 249, Address: 0x2d2b70, Func Offset: 0x5d0
	// Line 251, Address: 0x2d2b84, Func Offset: 0x5e4
	// Line 252, Address: 0x2d2b88, Func Offset: 0x5e8
	// Line 253, Address: 0x2d2b8c, Func Offset: 0x5ec
	// Line 257, Address: 0x2d2b90, Func Offset: 0x5f0
	// Line 258, Address: 0x2d2b94, Func Offset: 0x5f4
	// Line 259, Address: 0x2d2b98, Func Offset: 0x5f8
	// Line 260, Address: 0x2d2b9c, Func Offset: 0x5fc
	// Line 261, Address: 0x2d2ba0, Func Offset: 0x600
	// Line 262, Address: 0x2d2ba4, Func Offset: 0x604
	// Line 263, Address: 0x2d2ba8, Func Offset: 0x608
	// Line 264, Address: 0x2d2bac, Func Offset: 0x60c
	// Line 265, Address: 0x2d2bb0, Func Offset: 0x610
	// Line 266, Address: 0x2d2bb4, Func Offset: 0x614
	// Line 267, Address: 0x2d2bb8, Func Offset: 0x618
	// Line 268, Address: 0x2d2bbc, Func Offset: 0x61c
	// Line 270, Address: 0x2d2bc0, Func Offset: 0x620
	// Line 271, Address: 0x2d2bc4, Func Offset: 0x624
	// Line 272, Address: 0x2d2bc8, Func Offset: 0x628
	// Line 273, Address: 0x2d2bcc, Func Offset: 0x62c
	// Line 274, Address: 0x2d2bd0, Func Offset: 0x630
	// Line 276, Address: 0x2d2bd4, Func Offset: 0x634
	// Line 278, Address: 0x2d2bd8, Func Offset: 0x638
	// Line 279, Address: 0x2d2bdc, Func Offset: 0x63c
	// Line 281, Address: 0x2d2be0, Func Offset: 0x640
	// Line 282, Address: 0x2d2be4, Func Offset: 0x644
	// Line 283, Address: 0x2d2be8, Func Offset: 0x648
	// Line 285, Address: 0x2d2bec, Func Offset: 0x64c
	// Line 287, Address: 0x2d2bf0, Func Offset: 0x650
	// Line 288, Address: 0x2d2bf4, Func Offset: 0x654
	// Line 289, Address: 0x2d2bf8, Func Offset: 0x658
	// Line 290, Address: 0x2d2bfc, Func Offset: 0x65c
	// Line 292, Address: 0x2d2c00, Func Offset: 0x660
	// Line 294, Address: 0x2d2c04, Func Offset: 0x664
	// Line 296, Address: 0x2d2c08, Func Offset: 0x668
	// Line 297, Address: 0x2d2c0c, Func Offset: 0x66c
	// Line 298, Address: 0x2d2c10, Func Offset: 0x670
	// Line 299, Address: 0x2d2c14, Func Offset: 0x674
	// Line 300, Address: 0x2d2c18, Func Offset: 0x678
	// Line 301, Address: 0x2d2c1c, Func Offset: 0x67c
	// Line 303, Address: 0x2d2c20, Func Offset: 0x680
	// Line 309, Address: 0x2d2c28, Func Offset: 0x688
	// Line 310, Address: 0x2d2c3c, Func Offset: 0x69c
	// Line 325, Address: 0x2d2c44, Func Offset: 0x6a4
	// Line 314, Address: 0x2d2c50, Func Offset: 0x6b0
	// Line 325, Address: 0x2d2c54, Func Offset: 0x6b4
	// Line 326, Address: 0x2d2c60, Func Offset: 0x6c0
	// Line 327, Address: 0x2d2c74, Func Offset: 0x6d4
	// Line 328, Address: 0x2d2c78, Func Offset: 0x6d8
	// Line 330, Address: 0x2d2c80, Func Offset: 0x6e0
	// Line 336, Address: 0x2d2c88, Func Offset: 0x6e8
	// Line 338, Address: 0x2d2c98, Func Offset: 0x6f8
	// Line 344, Address: 0x2d2ca0, Func Offset: 0x700
	// Line 356, Address: 0x2d2ca8, Func Offset: 0x708
	// Line 354, Address: 0x2d2cac, Func Offset: 0x70c
	// Line 356, Address: 0x2d2cb4, Func Offset: 0x714
	// Line 357, Address: 0x2d2cbc, Func Offset: 0x71c
	// Line 358, Address: 0x2d2cd8, Func Offset: 0x738
	// Line 357, Address: 0x2d2cdc, Func Offset: 0x73c
	// Line 360, Address: 0x2d2ce0, Func Offset: 0x740
	// Line 361, Address: 0x2d2ce4, Func Offset: 0x744
	// Line 367, Address: 0x2d2ce8, Func Offset: 0x748
	// Line 364, Address: 0x2d2cf0, Func Offset: 0x750
	// Line 367, Address: 0x2d2cf4, Func Offset: 0x754
	// Line 368, Address: 0x2d2cfc, Func Offset: 0x75c
	// Line 370, Address: 0x2d2d04, Func Offset: 0x764
	// Line 371, Address: 0x2d2d0c, Func Offset: 0x76c
	// Line 374, Address: 0x2d2d10, Func Offset: 0x770
	// Line 376, Address: 0x2d2d18, Func Offset: 0x778
	// Line 377, Address: 0x2d2d30, Func Offset: 0x790
	// Line 378, Address: 0x2d2d38, Func Offset: 0x798
	// Line 379, Address: 0x2d2d40, Func Offset: 0x7a0
	// Line 380, Address: 0x2d2d48, Func Offset: 0x7a8
	// Line 381, Address: 0x2d2d94, Func Offset: 0x7f4
	// Line 384, Address: 0x2d2dd4, Func Offset: 0x834
	// Line 381, Address: 0x2d2dd8, Func Offset: 0x838
	// Line 384, Address: 0x2d2de0, Func Offset: 0x840
	// Line 387, Address: 0x2d2dec, Func Offset: 0x84c
	// Line 386, Address: 0x2d2df0, Func Offset: 0x850
	// Line 387, Address: 0x2d2df4, Func Offset: 0x854
	// Line 391, Address: 0x2d2e00, Func Offset: 0x860
	// Line 395, Address: 0x2d2e38, Func Offset: 0x898
	// Line 397, Address: 0x2d2e40, Func Offset: 0x8a0
	// Line 400, Address: 0x2d2e48, Func Offset: 0x8a8
	// Line 405, Address: 0x2d2e58, Func Offset: 0x8b8
	// Line 406, Address: 0x2d2e5c, Func Offset: 0x8bc
	// Func End, Address: 0x2d2e8c, Func Offset: 0x8ec
	scePrintf("njCnkCsUvh - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d2e90
CHUNK_HEAD* njCnkCsUvn(CHUNK_HEAD* pCnk)
{
	unsigned int cflag;
	float zbuff[4];
	unsigned int coflag;
	//_anon17* timp;
	unsigned long vu1func_tag;
	unsigned long ulVuflag;
	unsigned long* ulpP;
	int sExit;
	void(*pVu1Func)(unsigned long, VU1_STRIP_BUF*, unsigned short, unsigned short);
	unsigned short usColorCalc;
	unsigned short usClip;
	unsigned short usNum;
	unsigned short usMax;
	unsigned short usCnt;
	unsigned short usStrip;
	unsigned short usNext;
	VU1_STRIP_BUF* pSorg;
	VU1_STRIP_BUF* pS;
	VU1_STRIP_BUF* pV;
	unsigned short* uspCnk;
	unsigned long ulType2;
	unsigned long ulType;
	unsigned char ucFlag;
	// Line 19, Address: 0x2d2e90, Func Offset: 0
	// Line 21, Address: 0x2d2eac, Func Offset: 0x1c
	// Line 19, Address: 0x2d2eb0, Func Offset: 0x20
	// Line 21, Address: 0x2d2eb8, Func Offset: 0x28
	// Line 19, Address: 0x2d2ec0, Func Offset: 0x30
	// Line 22, Address: 0x2d2ec4, Func Offset: 0x34
	// Line 19, Address: 0x2d2ec8, Func Offset: 0x38
	// Line 22, Address: 0x2d2ecc, Func Offset: 0x3c
	// Line 35, Address: 0x2d2ed0, Func Offset: 0x40
	// Line 36, Address: 0x2d2eec, Func Offset: 0x5c
	// Line 40, Address: 0x2d2ef4, Func Offset: 0x64
	// Line 41, Address: 0x2d2f04, Func Offset: 0x74
	// Line 42, Address: 0x2d2f10, Func Offset: 0x80
	// Line 41, Address: 0x2d2f14, Func Offset: 0x84
	// Line 48, Address: 0x2d2f1c, Func Offset: 0x8c
	// Line 49, Address: 0x2d2f2c, Func Offset: 0x9c
	// Line 50, Address: 0x2d2f38, Func Offset: 0xa8
	// Line 49, Address: 0x2d2f3c, Func Offset: 0xac
	// Line 55, Address: 0x2d2f44, Func Offset: 0xb4
	// Line 57, Address: 0x2d2f54, Func Offset: 0xc4
	// Line 58, Address: 0x2d2f60, Func Offset: 0xd0
	// Line 59, Address: 0x2d2f6c, Func Offset: 0xdc
	// Line 60, Address: 0x2d2f70, Func Offset: 0xe0
	// Line 63, Address: 0x2d2f78, Func Offset: 0xe8
	// Line 64, Address: 0x2d2f88, Func Offset: 0xf8
	// Line 65, Address: 0x2d2f98, Func Offset: 0x108
	// Line 66, Address: 0x2d2fa8, Func Offset: 0x118
	// Line 67, Address: 0x2d2fb4, Func Offset: 0x124
	// Line 72, Address: 0x2d2fd4, Func Offset: 0x144
	// Line 78, Address: 0x2d2fe8, Func Offset: 0x158
	// Line 76, Address: 0x2d2fec, Func Offset: 0x15c
	// Line 72, Address: 0x2d2ff0, Func Offset: 0x160
	// Line 86, Address: 0x2d3000, Func Offset: 0x170
	// Line 72, Address: 0x2d3004, Func Offset: 0x174
	// Line 86, Address: 0x2d3008, Func Offset: 0x178
	// Line 79, Address: 0x2d300c, Func Offset: 0x17c
	// Line 78, Address: 0x2d3010, Func Offset: 0x180
	// Line 86, Address: 0x2d3014, Func Offset: 0x184
	// Line 87, Address: 0x2d301c, Func Offset: 0x18c
	// Line 97, Address: 0x2d3044, Func Offset: 0x1b4
	// Line 99, Address: 0x2d306c, Func Offset: 0x1dc
	// Line 100, Address: 0x2d3070, Func Offset: 0x1e0
	// Line 101, Address: 0x2d3078, Func Offset: 0x1e8
	// Line 104, Address: 0x2d307c, Func Offset: 0x1ec
	// Line 105, Address: 0x2d3088, Func Offset: 0x1f8
	// Line 106, Address: 0x2d3094, Func Offset: 0x204
	// Line 107, Address: 0x2d309c, Func Offset: 0x20c
	// Line 108, Address: 0x2d30a4, Func Offset: 0x214
	// Line 112, Address: 0x2d30ac, Func Offset: 0x21c
	// Line 113, Address: 0x2d30b4, Func Offset: 0x224
	// Line 115, Address: 0x2d30bc, Func Offset: 0x22c
	// Line 114, Address: 0x2d30cc, Func Offset: 0x23c
	// Line 115, Address: 0x2d30d0, Func Offset: 0x240
	// Line 116, Address: 0x2d30d8, Func Offset: 0x248
	// Line 117, Address: 0x2d30e8, Func Offset: 0x258
	// Line 120, Address: 0x2d30f4, Func Offset: 0x264
	// Line 118, Address: 0x2d30f8, Func Offset: 0x268
	// Line 117, Address: 0x2d3100, Func Offset: 0x270
	// Line 118, Address: 0x2d3104, Func Offset: 0x274
	// Line 119, Address: 0x2d3108, Func Offset: 0x278
	// Line 124, Address: 0x2d3110, Func Offset: 0x280
	// Line 118, Address: 0x2d3114, Func Offset: 0x284
	// Line 119, Address: 0x2d3118, Func Offset: 0x288
	// Line 124, Address: 0x2d311c, Func Offset: 0x28c
	// Line 125, Address: 0x2d3120, Func Offset: 0x290
	// Line 119, Address: 0x2d3128, Func Offset: 0x298
	// Line 120, Address: 0x2d312c, Func Offset: 0x29c
	// Line 126, Address: 0x2d3130, Func Offset: 0x2a0
	// Line 127, Address: 0x2d3138, Func Offset: 0x2a8
	// Line 120, Address: 0x2d3140, Func Offset: 0x2b0
	// Line 121, Address: 0x2d3144, Func Offset: 0x2b4
	// Line 131, Address: 0x2d314c, Func Offset: 0x2bc
	// Line 135, Address: 0x2d3154, Func Offset: 0x2c4
	// Line 136, Address: 0x2d315c, Func Offset: 0x2cc
	// Line 121, Address: 0x2d3160, Func Offset: 0x2d0
	// Line 122, Address: 0x2d3164, Func Offset: 0x2d4
	// Line 136, Address: 0x2d316c, Func Offset: 0x2dc
	// Line 137, Address: 0x2d3170, Func Offset: 0x2e0
	// Line 122, Address: 0x2d3178, Func Offset: 0x2e8
	// Line 123, Address: 0x2d317c, Func Offset: 0x2ec
	// Line 138, Address: 0x2d3184, Func Offset: 0x2f4
	// Line 139, Address: 0x2d318c, Func Offset: 0x2fc
	// Line 141, Address: 0x2d3190, Func Offset: 0x300
	// Line 123, Address: 0x2d3194, Func Offset: 0x304
	// Line 124, Address: 0x2d3198, Func Offset: 0x308
	// Line 141, Address: 0x2d319c, Func Offset: 0x30c
	// Line 124, Address: 0x2d31b0, Func Offset: 0x320
	// Line 125, Address: 0x2d31b4, Func Offset: 0x324
	// Line 144, Address: 0x2d31b8, Func Offset: 0x328
	// Line 128, Address: 0x2d31c0, Func Offset: 0x330
	// Line 139, Address: 0x2d31c4, Func Offset: 0x334
	// Line 125, Address: 0x2d31c8, Func Offset: 0x338
	// Line 126, Address: 0x2d31cc, Func Offset: 0x33c
	// Line 142, Address: 0x2d31d0, Func Offset: 0x340
	// Line 144, Address: 0x2d31d4, Func Offset: 0x344
	// Line 126, Address: 0x2d31dc, Func Offset: 0x34c
	// Line 127, Address: 0x2d31e0, Func Offset: 0x350
	// Line 128, Address: 0x2d31e8, Func Offset: 0x358
	// Line 129, Address: 0x2d31f0, Func Offset: 0x360
	// Line 130, Address: 0x2d31fc, Func Offset: 0x36c
	// Line 131, Address: 0x2d3200, Func Offset: 0x370
	// Line 132, Address: 0x2d3204, Func Offset: 0x374
	// Line 133, Address: 0x2d3210, Func Offset: 0x380
	// Line 134, Address: 0x2d321c, Func Offset: 0x38c
	// Line 135, Address: 0x2d3220, Func Offset: 0x390
	// Line 136, Address: 0x2d3224, Func Offset: 0x394
	// Line 137, Address: 0x2d322c, Func Offset: 0x39c
	// Line 138, Address: 0x2d3234, Func Offset: 0x3a4
	// Line 139, Address: 0x2d323c, Func Offset: 0x3ac
	// Line 141, Address: 0x2d3244, Func Offset: 0x3b4
	// Line 144, Address: 0x2d3248, Func Offset: 0x3b8
	// Line 145, Address: 0x2d3250, Func Offset: 0x3c0
	// Line 148, Address: 0x2d3264, Func Offset: 0x3d4
	// Line 151, Address: 0x2d326c, Func Offset: 0x3dc
	// Line 152, Address: 0x2d3278, Func Offset: 0x3e8
	// Line 153, Address: 0x2d3290, Func Offset: 0x400
	// Line 152, Address: 0x2d3294, Func Offset: 0x404
	// Line 155, Address: 0x2d3298, Func Offset: 0x408
	// Line 156, Address: 0x2d329c, Func Offset: 0x40c
	// Line 161, Address: 0x2d32a0, Func Offset: 0x410
	// Line 167, Address: 0x2d32c8, Func Offset: 0x438
	// Line 168, Address: 0x2d32d8, Func Offset: 0x448
	// Line 170, Address: 0x2d32e0, Func Offset: 0x450
	// Line 171, Address: 0x2d32e8, Func Offset: 0x458
	// Line 173, Address: 0x2d32ec, Func Offset: 0x45c
	// Line 175, Address: 0x2d32f0, Func Offset: 0x460
	// Line 178, Address: 0x2d32fc, Func Offset: 0x46c
	// Line 175, Address: 0x2d3304, Func Offset: 0x474
	// Line 178, Address: 0x2d3318, Func Offset: 0x488
	// Line 176, Address: 0x2d3328, Func Offset: 0x498
	// Line 178, Address: 0x2d332c, Func Offset: 0x49c
	// Line 177, Address: 0x2d3330, Func Offset: 0x4a0
	// Line 178, Address: 0x2d3334, Func Offset: 0x4a4
	// Line 179, Address: 0x2d333c, Func Offset: 0x4ac
	// Line 183, Address: 0x2d3354, Func Offset: 0x4c4
	// Line 179, Address: 0x2d3358, Func Offset: 0x4c8
	// Line 180, Address: 0x2d336c, Func Offset: 0x4dc
	// Line 183, Address: 0x2d3374, Func Offset: 0x4e4
	// Line 185, Address: 0x2d337c, Func Offset: 0x4ec
	// Line 186, Address: 0x2d3380, Func Offset: 0x4f0
	// Line 187, Address: 0x2d3384, Func Offset: 0x4f4
	// Line 188, Address: 0x2d3388, Func Offset: 0x4f8
	// Line 189, Address: 0x2d338c, Func Offset: 0x4fc
	// Line 190, Address: 0x2d3390, Func Offset: 0x500
	// Line 191, Address: 0x2d3394, Func Offset: 0x504
	// Line 193, Address: 0x2d3398, Func Offset: 0x508
	// Line 194, Address: 0x2d339c, Func Offset: 0x50c
	// Line 195, Address: 0x2d33a0, Func Offset: 0x510
	// Line 196, Address: 0x2d33a4, Func Offset: 0x514
	// Line 198, Address: 0x2d33a8, Func Offset: 0x518
	// Line 199, Address: 0x2d33ac, Func Offset: 0x51c
	// Line 200, Address: 0x2d33b0, Func Offset: 0x520
	// Line 201, Address: 0x2d33b4, Func Offset: 0x524
	// Line 202, Address: 0x2d33b8, Func Offset: 0x528
	// Line 204, Address: 0x2d33c0, Func Offset: 0x530
	// Line 206, Address: 0x2d33c4, Func Offset: 0x534
	// Line 207, Address: 0x2d33c8, Func Offset: 0x538
	// Line 208, Address: 0x2d33cc, Func Offset: 0x53c
	// Line 209, Address: 0x2d33d0, Func Offset: 0x540
	// Line 210, Address: 0x2d33d4, Func Offset: 0x544
	// Line 211, Address: 0x2d33d8, Func Offset: 0x548
	// Line 212, Address: 0x2d33dc, Func Offset: 0x54c
	// Line 214, Address: 0x2d33e0, Func Offset: 0x550
	// Line 217, Address: 0x2d33e8, Func Offset: 0x558
	// Line 218, Address: 0x2d33ec, Func Offset: 0x55c
	// Line 219, Address: 0x2d33f0, Func Offset: 0x560
	// Line 220, Address: 0x2d33f4, Func Offset: 0x564
	// Line 221, Address: 0x2d33f8, Func Offset: 0x568
	// Line 222, Address: 0x2d33fc, Func Offset: 0x56c
	// Line 223, Address: 0x2d3400, Func Offset: 0x570
	// Line 224, Address: 0x2d3404, Func Offset: 0x574
	// Line 227, Address: 0x2d3408, Func Offset: 0x578
	// Line 231, Address: 0x2d3410, Func Offset: 0x580
	// Line 233, Address: 0x2d3420, Func Offset: 0x590
	// Line 239, Address: 0x2d3428, Func Offset: 0x598
	// Line 242, Address: 0x2d345c, Func Offset: 0x5cc
	// Line 249, Address: 0x2d3460, Func Offset: 0x5d0
	// Line 251, Address: 0x2d3474, Func Offset: 0x5e4
	// Line 252, Address: 0x2d3478, Func Offset: 0x5e8
	// Line 253, Address: 0x2d347c, Func Offset: 0x5ec
	// Line 257, Address: 0x2d3480, Func Offset: 0x5f0
	// Line 258, Address: 0x2d3484, Func Offset: 0x5f4
	// Line 259, Address: 0x2d3488, Func Offset: 0x5f8
	// Line 260, Address: 0x2d348c, Func Offset: 0x5fc
	// Line 261, Address: 0x2d3490, Func Offset: 0x600
	// Line 262, Address: 0x2d3494, Func Offset: 0x604
	// Line 263, Address: 0x2d3498, Func Offset: 0x608
	// Line 264, Address: 0x2d349c, Func Offset: 0x60c
	// Line 265, Address: 0x2d34a0, Func Offset: 0x610
	// Line 266, Address: 0x2d34a4, Func Offset: 0x614
	// Line 267, Address: 0x2d34a8, Func Offset: 0x618
	// Line 268, Address: 0x2d34ac, Func Offset: 0x61c
	// Line 270, Address: 0x2d34b0, Func Offset: 0x620
	// Line 271, Address: 0x2d34b4, Func Offset: 0x624
	// Line 272, Address: 0x2d34b8, Func Offset: 0x628
	// Line 273, Address: 0x2d34bc, Func Offset: 0x62c
	// Line 274, Address: 0x2d34c0, Func Offset: 0x630
	// Line 276, Address: 0x2d34c4, Func Offset: 0x634
	// Line 278, Address: 0x2d34c8, Func Offset: 0x638
	// Line 279, Address: 0x2d34cc, Func Offset: 0x63c
	// Line 281, Address: 0x2d34d0, Func Offset: 0x640
	// Line 282, Address: 0x2d34d4, Func Offset: 0x644
	// Line 283, Address: 0x2d34d8, Func Offset: 0x648
	// Line 285, Address: 0x2d34dc, Func Offset: 0x64c
	// Line 287, Address: 0x2d34e0, Func Offset: 0x650
	// Line 288, Address: 0x2d34e4, Func Offset: 0x654
	// Line 289, Address: 0x2d34e8, Func Offset: 0x658
	// Line 290, Address: 0x2d34ec, Func Offset: 0x65c
	// Line 292, Address: 0x2d34f0, Func Offset: 0x660
	// Line 294, Address: 0x2d34f4, Func Offset: 0x664
	// Line 296, Address: 0x2d34f8, Func Offset: 0x668
	// Line 297, Address: 0x2d34fc, Func Offset: 0x66c
	// Line 298, Address: 0x2d3500, Func Offset: 0x670
	// Line 299, Address: 0x2d3504, Func Offset: 0x674
	// Line 300, Address: 0x2d3508, Func Offset: 0x678
	// Line 301, Address: 0x2d350c, Func Offset: 0x67c
	// Line 303, Address: 0x2d3510, Func Offset: 0x680
	// Line 309, Address: 0x2d3518, Func Offset: 0x688
	// Line 310, Address: 0x2d352c, Func Offset: 0x69c
	// Line 325, Address: 0x2d3534, Func Offset: 0x6a4
	// Line 314, Address: 0x2d3540, Func Offset: 0x6b0
	// Line 325, Address: 0x2d3544, Func Offset: 0x6b4
	// Line 326, Address: 0x2d3550, Func Offset: 0x6c0
	// Line 327, Address: 0x2d3564, Func Offset: 0x6d4
	// Line 328, Address: 0x2d3568, Func Offset: 0x6d8
	// Line 330, Address: 0x2d3570, Func Offset: 0x6e0
	// Line 336, Address: 0x2d3578, Func Offset: 0x6e8
	// Line 338, Address: 0x2d3588, Func Offset: 0x6f8
	// Line 344, Address: 0x2d3590, Func Offset: 0x700
	// Line 356, Address: 0x2d3598, Func Offset: 0x708
	// Line 354, Address: 0x2d359c, Func Offset: 0x70c
	// Line 356, Address: 0x2d35a4, Func Offset: 0x714
	// Line 357, Address: 0x2d35ac, Func Offset: 0x71c
	// Line 358, Address: 0x2d35c8, Func Offset: 0x738
	// Line 357, Address: 0x2d35cc, Func Offset: 0x73c
	// Line 360, Address: 0x2d35d0, Func Offset: 0x740
	// Line 361, Address: 0x2d35d4, Func Offset: 0x744
	// Line 367, Address: 0x2d35d8, Func Offset: 0x748
	// Line 364, Address: 0x2d35e0, Func Offset: 0x750
	// Line 367, Address: 0x2d35e4, Func Offset: 0x754
	// Line 368, Address: 0x2d35ec, Func Offset: 0x75c
	// Line 370, Address: 0x2d35f4, Func Offset: 0x764
	// Line 371, Address: 0x2d35fc, Func Offset: 0x76c
	// Line 374, Address: 0x2d3600, Func Offset: 0x770
	// Line 376, Address: 0x2d3608, Func Offset: 0x778
	// Line 377, Address: 0x2d3620, Func Offset: 0x790
	// Line 378, Address: 0x2d3628, Func Offset: 0x798
	// Line 379, Address: 0x2d3630, Func Offset: 0x7a0
	// Line 380, Address: 0x2d3638, Func Offset: 0x7a8
	// Line 381, Address: 0x2d3684, Func Offset: 0x7f4
	// Line 384, Address: 0x2d36c4, Func Offset: 0x834
	// Line 381, Address: 0x2d36c8, Func Offset: 0x838
	// Line 384, Address: 0x2d36d0, Func Offset: 0x840
	// Line 387, Address: 0x2d36dc, Func Offset: 0x84c
	// Line 386, Address: 0x2d36e0, Func Offset: 0x850
	// Line 387, Address: 0x2d36e4, Func Offset: 0x854
	// Line 391, Address: 0x2d36f0, Func Offset: 0x860
	// Line 395, Address: 0x2d3728, Func Offset: 0x898
	// Line 397, Address: 0x2d3730, Func Offset: 0x8a0
	// Line 400, Address: 0x2d3738, Func Offset: 0x8a8
	// Line 405, Address: 0x2d3748, Func Offset: 0x8b8
	// Line 406, Address: 0x2d374c, Func Offset: 0x8bc
	// Func End, Address: 0x2d377c, Func Offset: 0x8ec
	scePrintf("njCnkCsUvn - UNIMPLEMENTED!\n");
}

// 100% matching!
CHUNK_HEAD* njCnkDefaultLong(CHUNK_HEAD* pCnk)
{ 
    return (CHUNK_HEAD*)&((unsigned int*)(pCnk + 1))[pCnk->usSize]; 
}

// 100% matching!
CHUNK_HEAD* njCnkDefaultShort(CHUNK_HEAD* pCnk) 
{ 
    return (CHUNK_HEAD*)&((unsigned short*)(pCnk + 1))[pCnk->usSize]; 
}

// 100% matching!
void njCnkEasyMultiDrawObjectI(NJS_CNK_OBJECT* pObject)
{
    unsigned int ulFlags; 
    int lDrawResult;    

    njCnkSetCurrentDrawMode(1);
    
    ulCnkCurrentDrawMode |= 0x4;
    
    for ( ; pObject != NULL; pObject = pObject->sibling) 
    {
        ulFlags = pObject->evalflags;
    
        njPushMatrixEx();
    
        if (!(ulFlags & 0x1)) 
        {
            njTranslateEx((NJS_VECTOR*)&pObject->pos[0]);
        }
    
        if (!(ulFlags & 0x2)) 
        {
            njRotateEx(pObject->ang, ulFlags & 0x20);
        }
    
        if (!(ulFlags & 0x4))
        {
            njScaleEx((NJS_VECTOR*)&pObject->scl[0]);
        }
    
        if ((ulFlags & 0x8)) 
        {
            lDrawResult = 0;
        } 
        else
        {
            lDrawResult = njCnkDrawModelLocal(pObject->model);
        }
    
        if (!(ulFlags & 0x10)) 
        {
            if ((!(ulFlags & 0x100)) || (lDrawResult != 0)) 
            {
                njCnkEasyMultiDrawObjectI(pObject->child);
            }
        }
    
        njPopMatrixEx();
    }
}
