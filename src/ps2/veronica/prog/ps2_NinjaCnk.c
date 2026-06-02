#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/objitm.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaFog.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NaView.h"
#include "../../../ps2/veronica/prog/ps2_Vu1Strip.h"

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
extern void VU0_CALCPOINT() __attribute__((section(".vutext")));
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
        vcallms  VU0_CALCPOINT_INIT 
    
        lqc2     vf4,    0(%2)
        lqc2     vf5, 0x10(%2)
        
        vcallms  VU0_CALCPOINT 
    
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
            
            vcallms VU0_CALCPOINT
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
        vcallms VU0_CALCPOINT_END 
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

// 99.22% matching
CHUNK_HEAD* njCnkCsUvh(CHUNK_HEAD* pCnk)
{
    unsigned char ucFlag;                                                           
    unsigned long ulType, ulType2;                                     
    unsigned short* uspCnk;                                                       
    VU1_STRIP_BUF* pV, *pS, *pSorg; // pSorg needs use                                                          
    unsigned short usNext; // needs use                                                    
    unsigned short usStrip;                                                   
    unsigned short usCnt;                                                         
    unsigned short usMax;                                                       
    unsigned short usNum;                                                 
    unsigned short usClip;                                                          
    unsigned short usColorCalc;                                                     
    void (*pVu1Func)(unsigned long, VU1_STRIP_BUF*, unsigned short, unsigned short); 
    int sExit;                                                                    
    unsigned long* ulpP;                                                          
    unsigned long ulVuflag; // needs use                                                  
    unsigned long vu1func_tag;                                                                                                                 
    unsigned long* p; // not from DWARF 

    ulType  = SCE_GIF_PRIM(SCE_GS_PRIM_TRISTRIP, 0, /* textured */ SCE_GS_TRUE, /* fog */ SCE_GS_TRUE, 0, 0, 0, 0, 0);
    ulType2 = SCE_GIF_PRIM(SCE_GS_PRIM_TRIFAN,   0, /* textured */ SCE_GS_TRUE, /* fog */ SCE_GS_TRUE, 0, 0, 0, 0, 0);
    
    if (ulNaCnkFlagConstAttr != 0) 
    { 
        ucFlag = ucNaCnkAttr;
    }
    else 
    { 
        ucFlag = pCnk->ucHeadBits;
    }
    
    if ((ucFlag & 0x8)) 
    {
        ulType  |= SCE_GIF_PRIM(0, 0, 0, 0, /* Alpha blend */ SCE_GS_TRUE, 0, 0, 0, 0);
        ulType2 |= SCE_GIF_PRIM(0, 0, 0, 0, /* Alpha blend */ SCE_GS_TRUE, 0, 0, 0, 0); 
    }
   
    if (!(ucFlag & 0x20)) 
    {
        ulType  |= SCE_GIF_PRIM(0, /* Gourand */ SCE_GS_TRUE, 0, 0, 0, 0, 0, 0, 0);
        ulType2 |= SCE_GIF_PRIM(0, /* Gourand */ SCE_GS_TRUE, 0, 0, 0, 0, 0, 0, 0);
    }
    
    if (ulNaCnkFlagConstMaterial != 0)
    {
        vu1SetDiffuseMaterial(&NaCnkConstantMaterial);
        vu1SetAlphaRatio(fNaCnkConstantA);    
        
        usColorCalc = 1;
    } 
    else
    {
        vu1SetDiffuseMaterial(pNaCnkCrntLighting->pDiffuse);
        vu1SetSpeculaMaterial(pNaCnkCrntLighting->pSpecula);
        vu1SetAmbient(pNaCnkCrntLighting->pAmbient);
        vu1SetAlphaRatio(fNaCnkAlphaMaterial);
        
        usColorCalc = uspCnkCrntTexColCalcTbl[ucFlag & 0x7];
    }
    
    pVu1Func = pCnkCsVu1FuncTbl[(ucFlag & 0x18) | ulCnkCurrentDrawMode];

    uspCnk = (unsigned short*)&pCnk[1];
    
    usStrip = *uspCnk++ & 0x3FFF;
    
    if ((ulDrawGeneralPurposeWater != 0) || ((pVu1Func != vu1DrawTriangleStripTransDouble) && (pVu1Func != vu1DrawTriangleStripTransDoubleI))) 
    {
        TIM2_PICTUREHEADER_EX* timp;                                                 
        unsigned int coflag;  

        coflag = 0;  
        
        if ((pVu1Func == vu1DrawTriangleStripTransSingle) || (pVu1Func == vu1DrawTriangleStripOpaqueSingle))
        {
            vu1func_tag = SCE_VIF1_SET_MSCAL(700, 0);
        }
        else
        {
            vu1func_tag = SCE_VIF1_SET_MSCAL(0,   0);
        }

        timp = (TIM2_PICTUREHEADER_EX*)Ps2_now_tex->texinfo.texsurface.pSurface;
        
        if (timp->TpFlag != 0) 
        {
            Ps2_tex_load_tp_cancel = 1;
            
            Ps2TexLoad(Ps2_now_tex);
            
            Ps2_tex_load_tp_cancel = 0;
        }
        
        ulpP = (u_long*)SPR_ADDR(0x3E80);
        
        ulpP[0] = DMAend | 0x10;
        ulpP[1] = 0;
        
        ulpP[2] = JOIN_TAGS(SCE_VIF1_SET_BASE(0, 0), SCE_VIF1_SET_OFFSET(422, 0));
        ulpP[3] = JOIN_TAGS(SCE_VIF1_SET_NOP(0),     SCE_VIF1_SET_UNPACK(884, 15, SCE_UPF_V4_32, 0));
        
        SET_VEC4_AT(ulpP, 32, &vu1Diffuse);
        SET_VEC4_AT(ulpP, 48, &vu1Ambient);
        SET_VEC4_AT(ulpP, 64, &vu1Specula);
        
        SET_DATA_AT(ulpP, 80, float, fVu1NearClip);
        SET_DATA_AT(ulpP, 84, float, fVu1FarClip);
        SET_DATA_AT(ulpP, 88, float, fVu1Projection);
        SET_DATA_AT(ulpP, 92, float, fVu1AlphaRatio);
        
        SET_VEC4_AT(ulpP, 96, &ClipMatrix2[0]);
        SET_VEC4_AT(ulpP, 112, &ClipMatrix2[1]);
        SET_VEC4_AT(ulpP, 128, &ClipMatrix2[2]);
        SET_VEC4_AT(ulpP, 144, &ClipMatrix2[3]);
        
        SET_DATA_AT(ulpP, 160, float, fVu1OffsetX);
        SET_DATA_AT(ulpP, 164, float, fVu1OffsetY);
        
        SET_DATA_AT(ulpP, 168, float, 0);
        SET_DATA_AT(ulpP, 172, float, 4095.0f);
        
        SET_DATA_AT(ulpP, 176, float, fVu1AspectW);
        SET_DATA_AT(ulpP, 180, float, fVu1AspectH);
        
        SET_DATA_AT(ulpP, 184, float, 0);
        SET_DATA_AT(ulpP, 188, float, 65535.0f);
        
        SET_VEC4_AT(ulpP, 192, &ClipScreenMatrix[0]);
        SET_VEC4_AT(ulpP, 208, &ClipScreenMatrix[1]);
        SET_VEC4_AT(ulpP, 224, &ClipScreenMatrix[2]);
        SET_VEC4_AT(ulpP, 240, &ClipScreenMatrix[3]);
        
        ulpP[32] = SCE_GIF_SET_TAG(0, 1, SCE_GIF_REGLIST, NULL, 0, 3) | ulType2;
        ulpP[33] = GIF_REGLIST(SCE_GS_ST, SCE_GS_RGBAQ, SCE_GS_XYZF2);
        
        sceDmaSend((sceDmaChan*)D1_CHCR, (void*)0xF0003E80);
        sceDmaSync((sceDmaChan*)D1_CHCR, 0, 0);
        
        for (; usStrip; usStrip--)  
        {
            usClip = *uspCnk & 0x8000;
            
            usNum = usMax = (usClip != 0) ? ~*uspCnk + 1 : *uspCnk; 
            
            uspCnk++;
            
            sExit = 0;
            
            while (TRUE) 
            {
                ulpP = (Ps2_chunk_buff_flip != 0) ? (void*)0x70002000 : (void*)0x70002F40;
                
                p = (void*)&ulpP[6];
                
                pS = (void*)p;
                
                if ((usMax = usNum) > 60)
                {
                    usNum -= 58;
                    
                    usMax = 60;
                } 
                else 
                {
                    sExit = 1;
                }
                
                ulpP[0] = DMAend | ((usMax * 4) + 3);
                ulpP[1] = 0;
                
                ulpP[2] = 0;
                ulpP[3] = JOIN_TAGS(SCE_VIF1_SET_NOP(0), SCE_VIF1_SET_UNPACK(32768, (usMax * 4) + 1, SCE_UPF_V4_32, 0));
                
                ulpP[4] = (SCE_GIF_SET_TAG(0, SCE_GS_TRUE, SCE_GS_TRUE, 0, SCE_GIF_PACKED, 3) | ulType) | usMax;
                ulpP[5] = GIF_REGLIST(SCE_GS_ST, SCE_GS_RGBAQ, SCE_GS_XYZF2);

                asm volatile
                ("
                .set noreorder
                    addiu        %0, zero, 0x3F
                    
                    lhu          t0, 0(%1)
                    
                    addiu        a0, %1, 6
                    
                    sll          t0, t0, 6
                    
                    addi         %2, %2, -1
                    add          t0, %3, t0
                    
                    lqc2         vf4, 0x20(t0)

                    vmulax.xyzw  ACC, vf24, vf4x
                    
                    vmadday.xyzw ACC, vf25, vf4y
                    vmaddaz.xyzw ACC, vf26, vf4z
                    vmaddw.xyzw  vf5, vf27, vf0w
                    
                l_002D2AB8:
                    lhu          t0, 0(a0)
                    
                    addiu        a0, a0,  6
                    addi         %2, %2, -1 
                    
                    sll          t0, t0,  6
                    
                    beqz         %0, label
                    
                    add          t0, %3, t0 
                    
                    lqc2         vf4, 0x20(t0) 
                    
                    vclipw.xyz   vf5, vf5w                  
                    
                    vmulax.xyzw  ACC, vf24, vf4x
                    
                    vmadday.xyzw ACC, vf25, vf4y
                    vmaddaz.xyzw ACC, vf26, vf4z
                    vmaddw.xyzw  vf5, vf27, vf0w
                    vnop

                    cfc2         t1, vi18
                    
                    bnez         %2, l_002D2AB8
                    
                    and          %0, %0, t1
                    
                    vclipw.xyz   vf5, vf5w
                    vnop
                    vnop
                    vnop
                    vnop
                    vnop

                    cfc2         t1, vi18
                    
                    and          %0, %0, t1
                .set reorder
                " : "r"(coflag) : "r"(uspCnk), "r"(usMax), "m"(pNaCnkVerBufTop) : "memory"
                );
                    
                if (coflag != 0)
                {
                    uspCnk += usMax * 3;
                }
                else
                {
                label:
                {
                    float zbuff[4] = { -Ps2_zbuff_b, 0.0009775171f, -Ps2_zbuff_a, 65534.0f }; 
                    
                    asm volatile
                    ("
                    .set noreorder
                        lqc2 vf8, 0(%0)
                    .set reorder
                    " : : "r"(zbuff) : "v1", "memory"
                    );  
   
                    asm volatile
                    ("
                    .set noreorder
                        andi      %3, %3, 0xFFFF
                        
                        move      t3, %0
                        move      t4, %1
                    
                        ldl       t0, 0x7(t4)
                        ldr       t0,   0(t4)
                        
                        addiu     t4, t4, 6
                    
                        andi      t1, t0, 0xFFFF
                        
                        dsrl      t0, t0, 16
                        sll       t1, t1, 6
                        
                        add       t2, %2, t1
                        
                    l_002D2B38: 
                        lqc2      vf4,    0(t2)
                        lqc2      vf5, 0x10(t2)
                        lqc2      vf6, 0x20(t2)
                        lqc2      vf7, 0x30(t2)

                        pextlh    t0, zero, t0
                    
                        qmtc2     t0, vf4
                    
                        vitof0.xy vf4, vf4
                        
                        vmove.z   vf4, vf7
                        
                        vmuly.xy  vf4, vf4, vf8y
                        
                        vmove.w   vf5, vf7
                        
                        vmulax.z  ACC, vf7, vf8x
                        
                        vmaddw.z  vf7, vf8, vf0w
                        
                        ldl       t0, 0x7(t4)
                        ldr       t0,   0(t4)
                        
                        addiu     t4, t4, 6
                        
                        vmax.z    vf7, vf7, vf0
                        
                        andi      t1, t0, 0xFFFF
                    
                        dsrl      t0, t0, 16
                        sll       t1, t1, 6
                        
                        add       t2, %2, t1
                        
                        vminiw.z  vf7, vf7, vf8w
                        
                        vmove.w   vf7, vf6
                        
                        addi      %3, %3, -1
                        
                        sqc2      vf4,    0(t3)
                        sqc2      vf5, 0x10(t3)
                        sqc2      vf6, 0x20(t3)
                        sqc2      vf7, 0x30(t3)
                        
                        sw        %4, VU1_STRIP_BUF.fPad1(%0)
                        
                        bnez      %3, l_002D2B38 
                        
                        addiu     t3, t3, 64
                    .set reorder
                    " : : "r"(pS), "r"(uspCnk), "m"(pNaCnkVerBufTop), "r"(usMax), "r"(usColorCalc) : "t0", "t1", "t2", "memory"
                    );
                
                    uspCnk += usMax * 3;
                    
                    p = (void*)&pS[usMax];
                    
                    p[0] = 0;
                    p[1] = vu1func_tag;
                    
                    sceDmaSend((sceDmaChan*)D1_CHCR, (void*)((unsigned int)ulpP | 0x80000000));
                    
                    Ps2_chunk_buff_flip ^= 1;
                }
                }
                
                if (sExit == 0) 
                {
                    uspCnk -= 6;
                } 
                else
                {
                    usStrip--; // FAKE - this line isn't actually on the code, but for some reason it matches the function from 93% to 99%
                    usStrip++; // only purpose of this line is to cancel the effect of the subtraction above
                    break;
                }
            }
        }
        
        SyncPath();
    }
    else
    {
        for (; usStrip; usStrip--)
        {
            pS = NaCnkStrBufTop;
        
            usClip = *uspCnk & 0x8000; 
            
            usNum = (usClip != 0) ? ~*uspCnk + 1 : *uspCnk; 
            
            uspCnk++;
            
            sExit = 0;
            
            while (TRUE) 
            {
                unsigned int cflag;

                cflag = 0x3F;
                
                ulpP = (unsigned long*)pS;
                
                if ((usMax = usNum) > 60) 
                {
                    usNum -= 58;
                    
                    usMax = 60;
                }
                else 
                {
                    sExit = 1;
                }
                
                for (usCnt = usMax; usCnt; usCnt--, pS++) 
                {
                    pV = &pNaCnkVerBufTop[*uspCnk++];
                    
                    *(u_long128*)&pS->fVx = *(u_long128*)&pV->fVx;
                    *(u_long128*)&pS->fSx = *(u_long128*)&pV->fSx;
                    *(u_long128*)&pS->fIr = *(u_long128*)&pV->fIr;
                    
                    pS->fU = 0.0009775171f * *uspCnk++;
                    pS->fV = 0.0009775171f * *uspCnk++;
                    
                    cflag &= _CVV(&pV->fVx);
                }
             
                if (cflag == 0) 
                {
                    pVu1Func(ulType, (VU1_STRIP_BUF*)ulpP, usMax, usClip | usColorCalc);
                }
               
                if (sExit == 0) 
                {
                    uspCnk -= 6; 
                } 
                else 
                {
                    break;
                }
            }
        }
    }
    
    return (CHUNK_HEAD*)uspCnk;
}

// 99.22% matching
CHUNK_HEAD* njCnkCsUvn(CHUNK_HEAD* pCnk)
{
    unsigned char ucFlag;                                                           
    unsigned long ulType, ulType2;                                     
    unsigned short* uspCnk;                                                       
    VU1_STRIP_BUF* pV, *pS, *pSorg; // pSorg needs use                                                             
    unsigned short usNext; // needs use                                                    
    unsigned short usStrip;                                                   
    unsigned short usCnt;                                                         
    unsigned short usMax;                                                       
    unsigned short usNum;                                                 
    unsigned short usClip;                                                          
    unsigned short usColorCalc;                                                     
    void (*pVu1Func)(unsigned long, VU1_STRIP_BUF*, unsigned short, unsigned short); 
    int sExit;                                                                    
    unsigned long* ulpP;                                                          
    unsigned long ulVuflag; // needs use                                                        
    unsigned long vu1func_tag;                                                                                                                 
    unsigned long* p; // not from DWARF 

    ulType  = SCE_GIF_PRIM(SCE_GS_PRIM_TRISTRIP, 0, /* textured */ SCE_GS_TRUE, /* fog */ SCE_GS_TRUE, 0, 0, 0, 0, 0);
    ulType2 = SCE_GIF_PRIM(SCE_GS_PRIM_TRIFAN,   0, /* textured */ SCE_GS_TRUE, /* fog */ SCE_GS_TRUE, 0, 0, 0, 0, 0);
    
    if (ulNaCnkFlagConstAttr != 0) 
    { 
        ucFlag = ucNaCnkAttr;
    }
    else 
    { 
        ucFlag = pCnk->ucHeadBits;
    }
    
    if ((ucFlag & 0x8)) 
    {
        ulType  |= SCE_GIF_PRIM(0, 0, 0, 0, /* Alpha blend */ SCE_GS_TRUE, 0, 0, 0, 0);
        ulType2 |= SCE_GIF_PRIM(0, 0, 0, 0, /* Alpha blend */ SCE_GS_TRUE, 0, 0, 0, 0); 
    }
   
    if (!(ucFlag & 0x20)) 
    {
        ulType  |= SCE_GIF_PRIM(0, /* Gourand */ SCE_GS_TRUE, 0, 0, 0, 0, 0, 0, 0);
        ulType2 |= SCE_GIF_PRIM(0, /* Gourand */ SCE_GS_TRUE, 0, 0, 0, 0, 0, 0, 0);
    }
    
    if (ulNaCnkFlagConstMaterial != 0)
    {
        vu1SetDiffuseMaterial(&NaCnkConstantMaterial);
        vu1SetAlphaRatio(fNaCnkConstantA);    
        
        usColorCalc = 1;
    } 
    else
    {
        vu1SetDiffuseMaterial(pNaCnkCrntLighting->pDiffuse);
        vu1SetSpeculaMaterial(pNaCnkCrntLighting->pSpecula);
        vu1SetAmbient(pNaCnkCrntLighting->pAmbient);
        vu1SetAlphaRatio(fNaCnkAlphaMaterial);
        
        usColorCalc = uspCnkCrntTexColCalcTbl[ucFlag & 0x7];
    }
    
    pVu1Func = pCnkCsVu1FuncTbl[(ucFlag & 0x18) | ulCnkCurrentDrawMode];

    uspCnk = (unsigned short*)&pCnk[1];
    
    usStrip = *uspCnk++ & 0x3FFF;
    
    if ((ulDrawGeneralPurposeWater != 0) || ((pVu1Func != vu1DrawTriangleStripTransDouble) && (pVu1Func != vu1DrawTriangleStripTransDoubleI))) 
    {
        TIM2_PICTUREHEADER_EX* timp;                                                 
        unsigned int coflag;  

        coflag = 0;  
        
        if ((pVu1Func == vu1DrawTriangleStripTransSingle) || (pVu1Func == vu1DrawTriangleStripOpaqueSingle))
        {
            vu1func_tag = SCE_VIF1_SET_MSCAL(700, 0);
        }
        else
        {
            vu1func_tag = SCE_VIF1_SET_MSCAL(0,   0);
        }

        timp = (TIM2_PICTUREHEADER_EX*)Ps2_now_tex->texinfo.texsurface.pSurface;
        
        if (timp->TpFlag != 0) 
        {
            Ps2_tex_load_tp_cancel = 1;
            
            Ps2TexLoad(Ps2_now_tex);
            
            Ps2_tex_load_tp_cancel = 0;
        }
        
        ulpP = (u_long*)SPR_ADDR(0x3E80);
        
        ulpP[0] = DMAend | 0x10;
        ulpP[1] = 0;
        
        ulpP[2] = JOIN_TAGS(SCE_VIF1_SET_BASE(0, 0), SCE_VIF1_SET_OFFSET(422, 0));
        ulpP[3] = JOIN_TAGS(SCE_VIF1_SET_NOP(0),     SCE_VIF1_SET_UNPACK(884, 15, SCE_UPF_V4_32, 0));
        
        SET_VEC4_AT(ulpP, 32, &vu1Diffuse);
        SET_VEC4_AT(ulpP, 48, &vu1Ambient);
        SET_VEC4_AT(ulpP, 64, &vu1Specula);
        
        SET_DATA_AT(ulpP, 80, float, fVu1NearClip);
        SET_DATA_AT(ulpP, 84, float, fVu1FarClip);
        SET_DATA_AT(ulpP, 88, float, fVu1Projection);
        SET_DATA_AT(ulpP, 92, float, fVu1AlphaRatio);
        
        SET_VEC4_AT(ulpP, 96, &ClipMatrix2[0]);
        SET_VEC4_AT(ulpP, 112, &ClipMatrix2[1]);
        SET_VEC4_AT(ulpP, 128, &ClipMatrix2[2]);
        SET_VEC4_AT(ulpP, 144, &ClipMatrix2[3]);
        
        SET_DATA_AT(ulpP, 160, float, fVu1OffsetX);
        SET_DATA_AT(ulpP, 164, float, fVu1OffsetY);
        
        SET_DATA_AT(ulpP, 168, float, 0);
        SET_DATA_AT(ulpP, 172, float, 4095.0f);
        
        SET_DATA_AT(ulpP, 176, float, fVu1AspectW);
        SET_DATA_AT(ulpP, 180, float, fVu1AspectH);
        
        SET_DATA_AT(ulpP, 184, float, 0);
        SET_DATA_AT(ulpP, 188, float, 65535.0f);
        
        SET_VEC4_AT(ulpP, 192, &ClipScreenMatrix[0]);
        SET_VEC4_AT(ulpP, 208, &ClipScreenMatrix[1]);
        SET_VEC4_AT(ulpP, 224, &ClipScreenMatrix[2]);
        SET_VEC4_AT(ulpP, 240, &ClipScreenMatrix[3]);
        
        ulpP[32] = SCE_GIF_SET_TAG(0, 1, SCE_GIF_REGLIST, NULL, 0, 3) | ulType2;
        ulpP[33] = GIF_REGLIST(SCE_GS_ST, SCE_GS_RGBAQ, SCE_GS_XYZF2);
        
        sceDmaSend((sceDmaChan*)D1_CHCR, (void*)0xF0003E80);
        sceDmaSync((sceDmaChan*)D1_CHCR, 0, 0);
        
        for (; usStrip; usStrip--)  
        {
            usClip = *uspCnk & 0x8000;
            
            usNum = usMax = (usClip != 0) ? ~*uspCnk + 1 : *uspCnk; 
            
            uspCnk++;
            
            sExit = 0;
            
            while (TRUE) 
            {
                ulpP = (Ps2_chunk_buff_flip != 0) ? (void*)0x70002000 : (void*)0x70002F40;
                
                p = (void*)&ulpP[6];
                
                pS = (void*)p;
                
                if ((usMax = usNum) > 60)
                {
                    usNum -= 58;
                    
                    usMax = 60;
                } 
                else 
                {
                    sExit = 1;
                }
                
                ulpP[0] = DMAend | ((usMax * 4) + 3);
                ulpP[1] = 0;
                
                ulpP[2] = 0;
                ulpP[3] = JOIN_TAGS(SCE_VIF1_SET_NOP(0), SCE_VIF1_SET_UNPACK(32768, (usMax * 4) + 1, SCE_UPF_V4_32, 0));
                
                ulpP[4] = (SCE_GIF_SET_TAG(0, SCE_GS_TRUE, SCE_GS_TRUE, 0, SCE_GIF_PACKED, 3) | ulType) | usMax;
                ulpP[5] = GIF_REGLIST(SCE_GS_ST, SCE_GS_RGBAQ, SCE_GS_XYZF2);

                asm volatile
                ("
                .set noreorder
                    addiu        %0, zero, 0x3F
                    
                    lhu          t0, 0(%1)
                    
                    addiu        a0, %1, 6
                    
                    sll          t0, t0, 6
                    
                    addi         %2, %2, -1
                    add          t0, %3, t0
                    
                    lqc2         vf4, 0x20(t0)

                    vmulax.xyzw  ACC, vf24, vf4x
                    
                    vmadday.xyzw ACC, vf25, vf4y
                    vmaddaz.xyzw ACC, vf26, vf4z
                    vmaddw.xyzw  vf5, vf27, vf0w
                    
                l_002D2AB8:
                    lhu          t0, 0(a0)
                    
                    addiu        a0, a0,  6
                    addi         %2, %2, -1 
                    
                    sll          t0, t0,  6
                    
                    beqz         %0, label
                    
                    add          t0, %3, t0 
                    
                    lqc2         vf4, 0x20(t0) 
                    
                    vclipw.xyz   vf5, vf5w                  
                    
                    vmulax.xyzw  ACC, vf24, vf4x
                    
                    vmadday.xyzw ACC, vf25, vf4y
                    vmaddaz.xyzw ACC, vf26, vf4z
                    vmaddw.xyzw  vf5, vf27, vf0w
                    vnop

                    cfc2         t1, vi18
                    
                    bnez         %2, l_002D2AB8
                    
                    and          %0, %0, t1
                    
                    vclipw.xyz   vf5, vf5w
                    vnop
                    vnop
                    vnop
                    vnop
                    vnop

                    cfc2         t1, vi18
                    
                    and          %0, %0, t1
                .set reorder
                " : "r"(coflag) : "r"(uspCnk), "r"(usMax), "m"(pNaCnkVerBufTop) : "memory"
                );
                    
                if (coflag != 0)
                {
                    uspCnk += usMax * 3;
                }
                else
                {
                label:
                {
                    float zbuff[4] = { -Ps2_zbuff_b, 0.0009775171f, -Ps2_zbuff_a, 65534.0f }; 
                    
                    asm volatile
                    ("
                    .set noreorder
                        lqc2 vf8, 0(%0)
                    .set reorder
                    " : : "r"(zbuff) : "v1", "memory"
                    );  
   
                    asm volatile
                    ("
                    .set noreorder
                        andi      %3, %3, 0xFFFF
                        
                        move      t3, %0
                        move      t4, %1
                    
                        ldl       t0, 0x7(t4)
                        ldr       t0,   0(t4)
                        
                        addiu     t4, t4, 6
                    
                        andi      t1, t0, 0xFFFF
                        
                        dsrl      t0, t0, 16
                        sll       t1, t1, 6
                        
                        add       t2, %2, t1
                        
                    l_002D2B38: 
                        lqc2      vf4,    0(t2)
                        lqc2      vf5, 0x10(t2)
                        lqc2      vf6, 0x20(t2)
                        lqc2      vf7, 0x30(t2)

                        pextlh    t0, zero, t0
                    
                        qmtc2     t0, vf4
                    
                        vitof0.xy vf4, vf4
                        
                        vmove.z   vf4, vf7
                        
                        vmuly.xy  vf4, vf4, vf8y
                        
                        vmove.w   vf5, vf7
                        
                        vmulax.z  ACC, vf7, vf8x
                        
                        vmaddw.z  vf7, vf8, vf0w
                        
                        ldl       t0, 0x7(t4)
                        ldr       t0,   0(t4)
                        
                        addiu     t4, t4, 6
                        
                        vmax.z    vf7, vf7, vf0
                        
                        andi      t1, t0, 0xFFFF
                    
                        dsrl      t0, t0, 16
                        sll       t1, t1, 6
                        
                        add       t2, %2, t1
                        
                        vminiw.z  vf7, vf7, vf8w
                        
                        vmove.w   vf7, vf6
                        
                        addi      %3, %3, -1
                        
                        sqc2      vf4,    0(t3)
                        sqc2      vf5, 0x10(t3)
                        sqc2      vf6, 0x20(t3)
                        sqc2      vf7, 0x30(t3)
                        
                        sw        %4, VU1_STRIP_BUF.fPad1(%0)
                        
                        bnez      %3, l_002D2B38 
                        
                        addiu     t3, t3, 64
                    .set reorder
                    " : : "r"(pS), "r"(uspCnk), "m"(pNaCnkVerBufTop), "r"(usMax), "r"(usColorCalc) : "t0", "t1", "t2", "memory"
                    );
                
                    uspCnk += usMax * 3;
                    
                    p = (void*)&pS[usMax];
                    
                    p[0] = 0;
                    p[1] = vu1func_tag;
                    
                    sceDmaSend((sceDmaChan*)D1_CHCR, (void*)((unsigned int)ulpP | 0x80000000));
                    
                    Ps2_chunk_buff_flip ^= 1;
                }
                }
                
                if (sExit == 0) 
                {
                    uspCnk -= 6;
                } 
                else
                {
                    usStrip--; // FAKE - this line isn't actually on the code, but for some reason it matches the function from 93% to 99%
                    usStrip++; // only purpose of this line is to cancel the effect of the subtraction above
                    break;
                }
            }
        }
        
        SyncPath();
    }
    else
    {
        for (; usStrip; usStrip--)
        {
            pS = NaCnkStrBufTop;
        
            usClip = *uspCnk & 0x8000; 
            
            usNum = (usClip != 0) ? ~*uspCnk + 1 : *uspCnk; 
            
            uspCnk++;
            
            sExit = 0;
            
            while (TRUE) 
            {
                unsigned int cflag;

                cflag = 0x3F;
                
                ulpP = (unsigned long*)pS;
                
                if ((usMax = usNum) > 60) 
                {
                    usNum -= 58;
                    
                    usMax = 60;
                }
                else 
                {
                    sExit = 1;
                }
                
                for (usCnt = usMax; usCnt; usCnt--, pS++) 
                {
                    pV = &pNaCnkVerBufTop[*uspCnk++];
                    
                    *(u_long128*)&pS->fVx = *(u_long128*)&pV->fVx;
                    *(u_long128*)&pS->fSx = *(u_long128*)&pV->fSx;
                    *(u_long128*)&pS->fIr = *(u_long128*)&pV->fIr;
                    
                    pS->fU = 0.003921569f * *uspCnk++;
                    pS->fV = 0.003921569f * *uspCnk++;
                    
                    cflag &= _CVV(&pV->fVx);
                }
             
                if (cflag == 0) 
                {
                    pVu1Func(ulType, (VU1_STRIP_BUF*)ulpP, usMax, usClip | usColorCalc);
                }
               
                if (sExit == 0) 
                {
                    uspCnk -= 6; 
                } 
                else 
                {
                    break;
                }
            }
        }
    }
    
    return (CHUNK_HEAD*)uspCnk;
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
