#include "ps2_NinjaCnk.h"
#include "ps2_dummy.h"
#include "ps2_NaMatrix.h"
#include "ps2_Vu1Strip.h"

static VU1_STRIP_BUF* pNaCnkVerBufTop;
static int iNaCnkVerBufMax;
/*tagVU1_STRIP_BUF NaCnkStrBufTop[200];
unsigned int Vu0ClipFlag;
int lCnkModClipFace;
tagCHUNK_HEAD*(*pCnkFuncTbl)(tagCHUNK_HEAD*)[76];
void(*pCnkCsVu1FuncTbl)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short)[32];
unsigned short usCnkCsPolColorCalcFunc[8];
unsigned short usCnkCsTexColorCalcFunc[8][4];*/
unsigned int ulNaCnkFlagConstMaterial;
unsigned int ulNaCnkFlagConstAttr;
unsigned int ulNaCnkFlagModelClip;
int lNaCnkSrcAlphaMode[8] = { 11, 10, 3, 5, 8, 6, 2, 4 };
int lNaCnkDstAlphaMode[8] = { 11, 10, 9, 7, 8, 6, 2, 4 };
int lNaCnkSrcBlendMode = 8;
int lNaCnkDstBlendMode = 6;
unsigned char ucNaCnkAttr;
VU1_COLOR NaCnkDefaultOne;
float fNaCnkConstantA = 1.0f;
float fNaCnkConstantR = 1.0f;
float fNaCnkConstantG = 1.0f;
float fNaCnkConstantB = 1.0f;
VU1_COLOR NaCnkConstantMaterial = { 1.0f, 1.0f, 1.0f, 1.0f };
/*float fNaCnkAlphaMaterial;*/
VU1_COLOR NaCnkDiffuseMaterial __attribute__((aligned(64)));
/*float fNaCnkMaterialSpeE;*/
VU1_COLOR NaCnkSpeculaMaterial __attribute__((aligned(64)));
/*tagVU1_COLOR NaCnkAmbientFunctionSm;*/
VU1_COLOR NaCnkAmbientEs __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientEm __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientFunctionEm __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientMaterial __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientSs __attribute__((aligned(64))) = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR NaCnkAmbientSm;
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
void* vpDummy;
/*tagCNK_LIGHTING* pNaCnkCrntLighting;
unsigned short* uspCnkCrntTexColCalcTbl;
unsigned int ulCnkCurrentDrawMode;
float fNaViwHalfH;
float fNaViwHalfW;
float fNaViwAspectH;
float fNaViwAspectW;
_anon21 _nj_screen_;
float _fNaViwClipFar;
float _fNaViwClipNear;
float pNaMatMatrixStuckPtr[16];
int Ps2_shadow_z;
float Ps2_shadow_fog;
float Ps2_shadow_vec[4];
float fNaViwOffsetY;
float fNaViwOffsetX;
_anon7 planeset;
_anon26 scissorflip;
_anon22 node;
unsigned int Ps2_chunk_buff_flip;
float Ps2_zbuff_a;
float Ps2_zbuff_b;
float ClipScreenMatrix[4][4];
float fVu1AspectH;
float fVu1AspectW;
float fVu1OffsetY;
float fVu1OffsetX;
float ClipMatrix2[4][4];
float fVu1AlphaRatio;
float fVu1Projection;
float fVu1FarClip;
float fVu1NearClip;
tagVU1_COLOR vu1Specula;
tagVU1_COLOR vu1Ambient;
tagVU1_COLOR vu1Diffuse;
unsigned int Ps2_tex_load_tp_cancel;
_anon8* Ps2_now_tex;
void(*vu1DrawTriangleStripOpaqueSingle)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
void(*vu1DrawTriangleStripTransSingle)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
void(*vu1DrawTriangleStripTransDoubleI)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
void(*vu1DrawTriangleStripTransDouble)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
unsigned int ulDrawGeneralPurposeWater;
unsigned int njCnkConvTest;*/

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

/*// 
// Start address: 0x2cf570
void njCnkSetEasyMultiLight(int iLightMax)
{
	// Line 807, Address: 0x2cf570, Func Offset: 0
	// Line 808, Address: 0x2cf578, Func Offset: 0x8
	// Func End, Address: 0x2cf584, Func Offset: 0x14
}*/

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

// 
// Start address: 0x2cf930
void    njCnkSetSimpleMultiAmbient(Float ar, Float ag, Float ab)
{
	// Line 1166, Address: 0x2cf930, Func Offset: 0
	// Line 1167, Address: 0x2cf938, Func Offset: 0x8
	// Line 1168, Address: 0x2cf940, Func Offset: 0x10
	// Line 1171, Address: 0x2cf948, Func Offset: 0x18
	// Line 1172, Address: 0x2cf950, Func Offset: 0x20
	// Line 1171, Address: 0x2cf958, Func Offset: 0x28
	// Line 1173, Address: 0x2cf95c, Func Offset: 0x2c
	// Line 1172, Address: 0x2cf964, Func Offset: 0x34
	// Line 1171, Address: 0x2cf968, Func Offset: 0x38
	// Line 1172, Address: 0x2cf970, Func Offset: 0x40
	// Line 1173, Address: 0x2cf978, Func Offset: 0x48
	// Line 1174, Address: 0x2cf980, Func Offset: 0x50
	// Func End, Address: 0x2cf988, Func Offset: 0x58
	scePrintf("njCnkSetSimpleMultiAmbient - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2cf990
void    njCnkSetSimpleMultiLightColor(Int light, Float lr, Float lg, Float lb)
{
	// Line 1199, Address: 0x2cf990, Func Offset: 0
	// Line 1200, Address: 0x2cf9a8, Func Offset: 0x18
	// Line 1201, Address: 0x2cf9b8, Func Offset: 0x28
	// Line 1202, Address: 0x2cf9c4, Func Offset: 0x34
	// Func End, Address: 0x2cf9cc, Func Offset: 0x3c
	scePrintf("njCnkSetSimpleMultiLightColor - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2cf9d0
void    njCnkSetSimpleMultiLightVector(Float vx, Float vy, Float vz)
{
	// Line 1224, Address: 0x2cf9d0, Func Offset: 0
	// Line 1225, Address: 0x2cf9dc, Func Offset: 0xc
	// Line 1226, Address: 0x2cf9e8, Func Offset: 0x18
	// Line 1227, Address: 0x2cf9f4, Func Offset: 0x24
	// Line 1228, Address: 0x2cf9f8, Func Offset: 0x28
	// Func End, Address: 0x2cfa00, Func Offset: 0x30
	scePrintf("njCnkSetSimpleMultiLightVector - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2cfa00
void njCnkSetSimpleMultiLightPoint(int iLightNum, float fX, float fY, float fZ)
{
	// Line 1253, Address: 0x2cfa00, Func Offset: 0
	// Line 1254, Address: 0x2cfa18, Func Offset: 0x18
	// Line 1255, Address: 0x2cfa28, Func Offset: 0x28
	// Line 1256, Address: 0x2cfa38, Func Offset: 0x38
	// Line 1257, Address: 0x2cfa48, Func Offset: 0x48
	// Func End, Address: 0x2cfa50, Func Offset: 0x50
}

// 
// Start address: 0x2cfa50
void njCnkSetSimpleMultiLightRange(int iLightNum, float fNear, float fFar)
{
	// Line 1280, Address: 0x2cfa50, Func Offset: 0
	// Line 1281, Address: 0x2cfa68, Func Offset: 0x18
	// Line 1280, Address: 0x2cfa6c, Func Offset: 0x1c
	// Line 1281, Address: 0x2cfa70, Func Offset: 0x20
	// Line 1282, Address: 0x2cfa80, Func Offset: 0x30
	// Line 1283, Address: 0x2cfa90, Func Offset: 0x40
	// Func End, Address: 0x2cfa98, Func Offset: 0x48
}*/

// 
// Start address: 0x2cfaa0
void    njCnkSetSimpleMultiLightMatrices(void)
{
	int lCnt;
	// Line 1296, Address: 0x2cfaa0, Func Offset: 0
	// Line 1300, Address: 0x2cfab8, Func Offset: 0x18
	// Line 1302, Address: 0x2cfac0, Func Offset: 0x20
	// Line 1305, Address: 0x2cfacc, Func Offset: 0x2c
	// Line 1307, Address: 0x2cfad8, Func Offset: 0x38
	// Line 1308, Address: 0x2cfae0, Func Offset: 0x40
	// Line 1309, Address: 0x2cfae8, Func Offset: 0x48
	// Line 1310, Address: 0x2cfaf8, Func Offset: 0x58
	// Line 1311, Address: 0x2cfb00, Func Offset: 0x60
	// Line 1315, Address: 0x2cfb08, Func Offset: 0x68
	// Line 1317, Address: 0x2cfb1c, Func Offset: 0x7c
	// Line 1318, Address: 0x2cfb34, Func Offset: 0x94
	// Func End, Address: 0x2cfb48, Func Offset: 0xa8
	scePrintf("njCnkSetSimpleMultiLightMatrices - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2cfb50
void njCnkEasyDrawModel(_anon5* pModel)
{
	// Line 1336, Address: 0x2cfb50, Func Offset: 0
	// Line 1339, Address: 0x2cfb60, Func Offset: 0x10
	// Line 1341, Address: 0x2cfb68, Func Offset: 0x18
	// Line 1342, Address: 0x2cfb70, Func Offset: 0x20
	// Func End, Address: 0x2cfb80, Func Offset: 0x30
}*/

// 
// Start address: 0x2cfb80
void    njCnkEasyDrawObject( NJS_CNK_OBJECT *model )
{
	int lDrawResult;
	unsigned int ulFlags;
	// Line 1361, Address: 0x2cfb80, Func Offset: 0
	// Line 1367, Address: 0x2cfb90, Func Offset: 0x10
	// Line 1369, Address: 0x2cfb9c, Func Offset: 0x1c
	// Line 1373, Address: 0x2cfba4, Func Offset: 0x24
	// Line 1376, Address: 0x2cfbac, Func Offset: 0x2c
	// Line 1377, Address: 0x2cfbc0, Func Offset: 0x40
	// Line 1378, Address: 0x2cfbd8, Func Offset: 0x58
	// Line 1382, Address: 0x2cfbf0, Func Offset: 0x70
	// Line 1385, Address: 0x2cfc0c, Func Offset: 0x8c
	// Line 1387, Address: 0x2cfc30, Func Offset: 0xb0
	// Line 1390, Address: 0x2cfc38, Func Offset: 0xb8
	// Line 1391, Address: 0x2cfc40, Func Offset: 0xc0
	// Line 1392, Address: 0x2cfc50, Func Offset: 0xd0
	// Func End, Address: 0x2cfc64, Func Offset: 0xe4
	scePrintf("njCnkEasyDrawObject - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2cfc70
void njCnkEasyMultiDrawModel(_anon5* pModel)
{
	// Line 1409, Address: 0x2cfc70, Func Offset: 0
	// Line 1412, Address: 0x2cfc80, Func Offset: 0x10
	// Line 1414, Address: 0x2cfc88, Func Offset: 0x18
	// Line 1415, Address: 0x2cfc90, Func Offset: 0x20
	// Func End, Address: 0x2cfca0, Func Offset: 0x30
}*/

// 
// Start address: 0x2cfca0
void    njCnkEasyMultiDrawObject( NJS_CNK_OBJECT *model )
{
	int lDrawResult;
	unsigned int ulFlags;
	// Line 1432, Address: 0x2cfca0, Func Offset: 0
	// Line 1438, Address: 0x2cfcb0, Func Offset: 0x10
	// Line 1440, Address: 0x2cfcbc, Func Offset: 0x1c
	// Line 1444, Address: 0x2cfcc4, Func Offset: 0x24
	// Line 1447, Address: 0x2cfccc, Func Offset: 0x2c
	// Line 1448, Address: 0x2cfce0, Func Offset: 0x40
	// Line 1449, Address: 0x2cfcf8, Func Offset: 0x58
	// Line 1453, Address: 0x2cfd10, Func Offset: 0x70
	// Line 1456, Address: 0x2cfd2c, Func Offset: 0x8c
	// Line 1458, Address: 0x2cfd50, Func Offset: 0xb0
	// Line 1461, Address: 0x2cfd58, Func Offset: 0xb8
	// Line 1462, Address: 0x2cfd60, Func Offset: 0xc0
	// Line 1463, Address: 0x2cfd70, Func Offset: 0xd0
	// Func End, Address: 0x2cfd84, Func Offset: 0xe4
	scePrintf("njCnkEasyMultiDrawObject - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2cfd90
void njCnkSimpleDrawModel(_anon5* pModel)
{
	// Line 1480, Address: 0x2cfd90, Func Offset: 0
	// Line 1483, Address: 0x2cfda0, Func Offset: 0x10
	// Line 1485, Address: 0x2cfda8, Func Offset: 0x18
	// Line 1486, Address: 0x2cfdb0, Func Offset: 0x20
	// Func End, Address: 0x2cfdc0, Func Offset: 0x30
}

// 
// Start address: 0x2cfdc0
void njCnkSimpleMultiDrawModel(_anon5* pModel)
{
	// Line 1551, Address: 0x2cfdc0, Func Offset: 0
	// Line 1554, Address: 0x2cfdd0, Func Offset: 0x10
	// Line 1556, Address: 0x2cfdd8, Func Offset: 0x18
	// Line 1557, Address: 0x2cfde0, Func Offset: 0x20
	// Func End, Address: 0x2cfdf0, Func Offset: 0x30
}

// 
// Start address: 0x2cfdf0
void njCnkSetCurrentDrawMode(unsigned int ulMode)
{
	// Line 1627, Address: 0x2cfdf0, Func Offset: 0
	// Line 1626, Address: 0x2cfdf8, Func Offset: 0x8
	// Line 1627, Address: 0x2cfdfc, Func Offset: 0xc
	// Line 1626, Address: 0x2cfe00, Func Offset: 0x10
	// Line 1627, Address: 0x2cfe04, Func Offset: 0x14
	// Line 1628, Address: 0x2cfe10, Func Offset: 0x20
	// Line 1629, Address: 0x2cfe24, Func Offset: 0x34
	// Func End, Address: 0x2cfe2c, Func Offset: 0x3c
}

// 
// Start address: 0x2cfe30
int njCnkDrawModelLocal(_anon5* pModel)
{
	unsigned int modelclipflag;
	tagCHUNK_HEAD* pCnk;
	float fZ;
	float fSY;
	float fSX;
	float fRH;
	float fRW;
	_anon9 Center;
	// Line 1651, Address: 0x2cfe30, Func Offset: 0
	// Line 1659, Address: 0x2cfe44, Func Offset: 0x14
	// Line 1662, Address: 0x2cfe58, Func Offset: 0x28
	// Line 1663, Address: 0x2cfe5c, Func Offset: 0x2c
	// Line 1666, Address: 0x2cfe74, Func Offset: 0x44
	// Line 1668, Address: 0x2cfe84, Func Offset: 0x54
	// Line 1672, Address: 0x2cfe88, Func Offset: 0x58
	// Line 1673, Address: 0x2cfeac, Func Offset: 0x7c
	// Line 1675, Address: 0x2cfed0, Func Offset: 0xa0
	// Line 1678, Address: 0x2cfeec, Func Offset: 0xbc
	// Line 1677, Address: 0x2cfef4, Func Offset: 0xc4
	// Line 1683, Address: 0x2cfef8, Func Offset: 0xc8
	// Line 1679, Address: 0x2cfefc, Func Offset: 0xcc
	// Line 1678, Address: 0x2cff04, Func Offset: 0xd4
	// Line 1679, Address: 0x2cff08, Func Offset: 0xd8
	// Line 1684, Address: 0x2cff0c, Func Offset: 0xdc
	// Line 1683, Address: 0x2cff14, Func Offset: 0xe4
	// Line 1684, Address: 0x2cff18, Func Offset: 0xe8
	// Line 1685, Address: 0x2cff38, Func Offset: 0x108
	// Line 1689, Address: 0x2cff54, Func Offset: 0x124
	// Line 1690, Address: 0x2cff58, Func Offset: 0x128
	// Line 1689, Address: 0x2cff60, Func Offset: 0x130
	// Line 1690, Address: 0x2cff64, Func Offset: 0x134
	// Line 1691, Address: 0x2cff84, Func Offset: 0x154
	// Line 1732, Address: 0x2cffa0, Func Offset: 0x170
	// Line 1733, Address: 0x2cffa8, Func Offset: 0x178
	// Line 1734, Address: 0x2cffac, Func Offset: 0x17c
	// Line 1738, Address: 0x2cffb4, Func Offset: 0x184
	// Line 1740, Address: 0x2cffc8, Func Offset: 0x198
	// Line 1742, Address: 0x2cffe8, Func Offset: 0x1b8
	// Line 1745, Address: 0x2cfff0, Func Offset: 0x1c0
	// Line 1750, Address: 0x2d0008, Func Offset: 0x1d8
	// Line 1755, Address: 0x2d0010, Func Offset: 0x1e0
	// Line 1757, Address: 0x2d0024, Func Offset: 0x1f4
	// Line 1762, Address: 0x2d0038, Func Offset: 0x208
	// Line 1763, Address: 0x2d003c, Func Offset: 0x20c
	// Line 1765, Address: 0x2d0044, Func Offset: 0x214
	// Line 1767, Address: 0x2d004c, Func Offset: 0x21c
	// Line 1768, Address: 0x2d0070, Func Offset: 0x240
	// Line 1770, Address: 0x2d0080, Func Offset: 0x250
	// Line 1771, Address: 0x2d0084, Func Offset: 0x254
	// Func End, Address: 0x2d009c, Func Offset: 0x26c
}*/

// 
// Start address: 0x2d00a0
int njCnkDrawModelLocalMod(NJS_CNK_MODEL* pModel)
{
	CHUNK_HEAD* pCnk;
	float fZ;
	float fSY;
	float fSX;
	float fRH;
	float fRW;
	//_anon9 Center;
	// Line 1786, Address: 0x2d00a0, Func Offset: 0
	// Line 1793, Address: 0x2d00b4, Func Offset: 0x14
	// Line 1796, Address: 0x2d00c4, Func Offset: 0x24
	// Line 1797, Address: 0x2d00c8, Func Offset: 0x28
	// Line 1800, Address: 0x2d00e0, Func Offset: 0x40
	// Line 1802, Address: 0x2d00f0, Func Offset: 0x50
	// Line 1804, Address: 0x2d00f4, Func Offset: 0x54
	// Line 1807, Address: 0x2d010c, Func Offset: 0x6c
	// Line 1808, Address: 0x2d0130, Func Offset: 0x90
	// Line 1810, Address: 0x2d0154, Func Offset: 0xb4
	// Line 1812, Address: 0x2d0170, Func Offset: 0xd0
	// Line 1811, Address: 0x2d0178, Func Offset: 0xd8
	// Line 1816, Address: 0x2d017c, Func Offset: 0xdc
	// Line 1813, Address: 0x2d0180, Func Offset: 0xe0
	// Line 1812, Address: 0x2d0188, Func Offset: 0xe8
	// Line 1813, Address: 0x2d018c, Func Offset: 0xec
	// Line 1817, Address: 0x2d0190, Func Offset: 0xf0
	// Line 1816, Address: 0x2d0198, Func Offset: 0xf8
	// Line 1817, Address: 0x2d019c, Func Offset: 0xfc
	// Line 1818, Address: 0x2d01bc, Func Offset: 0x11c
	// Line 1821, Address: 0x2d01d8, Func Offset: 0x138
	// Line 1822, Address: 0x2d01dc, Func Offset: 0x13c
	// Line 1821, Address: 0x2d01e4, Func Offset: 0x144
	// Line 1822, Address: 0x2d01e8, Func Offset: 0x148
	// Line 1823, Address: 0x2d0208, Func Offset: 0x168
	// Line 1829, Address: 0x2d0224, Func Offset: 0x184
	// Line 1830, Address: 0x2d022c, Func Offset: 0x18c
	// Line 1831, Address: 0x2d0230, Func Offset: 0x190
	// Line 1833, Address: 0x2d0238, Func Offset: 0x198
	// Line 1835, Address: 0x2d0240, Func Offset: 0x1a0
	// Line 1839, Address: 0x2d0248, Func Offset: 0x1a8
	// Line 1840, Address: 0x2d024c, Func Offset: 0x1ac
	// Line 1842, Address: 0x2d0254, Func Offset: 0x1b4
	// Line 1844, Address: 0x2d025c, Func Offset: 0x1bc
	// Line 1845, Address: 0x2d0260, Func Offset: 0x1c0
	// Func End, Address: 0x2d0278, Func Offset: 0x1d8
	scePrintf("njCnkDrawModelLocalMod - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2d0280
tagCHUNK_HEAD* njCnkCn(tagCHUNK_HEAD* pCnk)
{
	// Line 1864, Address: 0x2d0280, Func Offset: 0
	// Func End, Address: 0x2d0288, Func Offset: 0x8
}

// 
// Start address: 0x2d0290
tagCHUNK_HEAD* njCnkCbBa(tagCHUNK_HEAD* pCnk)
{
	// Line 1902, Address: 0x2d0290, Func Offset: 0
	// Line 1904, Address: 0x2d029c, Func Offset: 0xc
	// Line 1906, Address: 0x2d02b0, Func Offset: 0x20
	// Line 1909, Address: 0x2d02ec, Func Offset: 0x5c
	// Line 1910, Address: 0x2d02f0, Func Offset: 0x60
	// Func End, Address: 0x2d0300, Func Offset: 0x70
}*/

// 100% matching!
CHUNK_HEAD* njCnkCbDa(CHUNK_HEAD* pCnk) 
{
    return &pCnk[1];
}

/*// 
// Start address: 0x2d0310
tagCHUNK_HEAD* njCnkCbExp(tagCHUNK_HEAD* pCnk)
{
	// Line 1949, Address: 0x2d0310, Func Offset: 0
	// Line 1951, Address: 0x2d0348, Func Offset: 0x38
	// Line 1952, Address: 0x2d034c, Func Offset: 0x3c
	// Func End, Address: 0x2d0354, Func Offset: 0x44
}

// 
// Start address: 0x2d0360
tagCHUNK_HEAD* njCnkCtTid(tagCHUNK_HEAD* pCnk)
{
	// Line 1970, Address: 0x2d0360, Func Offset: 0
	// Line 1972, Address: 0x2d036c, Func Offset: 0xc
	// Line 1974, Address: 0x2d0380, Func Offset: 0x20
	// Line 1977, Address: 0x2d038c, Func Offset: 0x2c
	// Line 1979, Address: 0x2d0398, Func Offset: 0x38
	// Line 1986, Address: 0x2d03a8, Func Offset: 0x48
	// Line 1988, Address: 0x2d03b4, Func Offset: 0x54
	// Line 1989, Address: 0x2d03b8, Func Offset: 0x58
	// Func End, Address: 0x2d03c8, Func Offset: 0x68
}

// 
// Start address: 0x2d03d0
tagCHUNK_HEAD* njCnkCmD(tagCHUNK_HEAD* pCnk)
{
	unsigned char* ucpPtr;
	// Line 2007, Address: 0x2d03d0, Func Offset: 0
	// Line 2011, Address: 0x2d03dc, Func Offset: 0xc
	// Line 2014, Address: 0x2d03f0, Func Offset: 0x20
	// Line 2020, Address: 0x2d042c, Func Offset: 0x5c
	// Line 2021, Address: 0x2d0474, Func Offset: 0xa4
	// Line 2022, Address: 0x2d04bc, Func Offset: 0xec
	// Line 2023, Address: 0x2d0504, Func Offset: 0x134
	// Line 2026, Address: 0x2d0548, Func Offset: 0x178
	// Line 2023, Address: 0x2d054c, Func Offset: 0x17c
	// Line 2027, Address: 0x2d0550, Func Offset: 0x180
	// Func End, Address: 0x2d0560, Func Offset: 0x190
}

// 
// Start address: 0x2d0560
tagCHUNK_HEAD* njCnkCmA(tagCHUNK_HEAD* pCnk)
{
	unsigned char* ucpPtr;
	// Line 2045, Address: 0x2d0560, Func Offset: 0
	// Line 2049, Address: 0x2d056c, Func Offset: 0xc
	// Line 2052, Address: 0x2d0580, Func Offset: 0x20
	// Line 2058, Address: 0x2d05bc, Func Offset: 0x5c
	// Line 2059, Address: 0x2d0604, Func Offset: 0xa4
	// Line 2060, Address: 0x2d064c, Func Offset: 0xec
	// Line 2064, Address: 0x2d0688, Func Offset: 0x128
	// Line 2060, Address: 0x2d068c, Func Offset: 0x12c
	// Line 2064, Address: 0x2d0690, Func Offset: 0x130
	// Line 2073, Address: 0x2d0694, Func Offset: 0x134
	// Line 2065, Address: 0x2d0698, Func Offset: 0x138
	// Line 2066, Address: 0x2d06a0, Func Offset: 0x140
	// Line 2069, Address: 0x2d06a8, Func Offset: 0x148
	// Line 2070, Address: 0x2d06b0, Func Offset: 0x150
	// Line 2064, Address: 0x2d06b8, Func Offset: 0x158
	// Line 2071, Address: 0x2d06bc, Func Offset: 0x15c
	// Line 2069, Address: 0x2d06c4, Func Offset: 0x164
	// Line 2060, Address: 0x2d06c8, Func Offset: 0x168
	// Line 2065, Address: 0x2d06d0, Func Offset: 0x170
	// Line 2066, Address: 0x2d06d8, Func Offset: 0x178
	// Line 2070, Address: 0x2d06e0, Func Offset: 0x180
	// Line 2064, Address: 0x2d06e4, Func Offset: 0x184
	// Line 2069, Address: 0x2d06ec, Func Offset: 0x18c
	// Line 2065, Address: 0x2d06f4, Func Offset: 0x194
	// Line 2070, Address: 0x2d0700, Func Offset: 0x1a0
	// Line 2066, Address: 0x2d0708, Func Offset: 0x1a8
	// Line 2071, Address: 0x2d0714, Func Offset: 0x1b4
	// Line 2074, Address: 0x2d0720, Func Offset: 0x1c0
	// Func End, Address: 0x2d0730, Func Offset: 0x1d0
}

// 
// Start address: 0x2d0730
tagCHUNK_HEAD* njCnkCmDa(tagCHUNK_HEAD* pCnk)
{
	unsigned char* ucpPtr;
	// Line 2092, Address: 0x2d0730, Func Offset: 0
	// Line 2096, Address: 0x2d073c, Func Offset: 0xc
	// Line 2099, Address: 0x2d0750, Func Offset: 0x20
	// Line 2105, Address: 0x2d078c, Func Offset: 0x5c
	// Line 2106, Address: 0x2d07d4, Func Offset: 0xa4
	// Line 2107, Address: 0x2d081c, Func Offset: 0xec
	// Line 2108, Address: 0x2d0864, Func Offset: 0x134
	// Line 2112, Address: 0x2d08ac, Func Offset: 0x17c
	// Line 2113, Address: 0x2d08f4, Func Offset: 0x1c4
	// Line 2114, Address: 0x2d093c, Func Offset: 0x20c
	// Line 2118, Address: 0x2d0978, Func Offset: 0x248
	// Line 2114, Address: 0x2d097c, Func Offset: 0x24c
	// Line 2118, Address: 0x2d0980, Func Offset: 0x250
	// Line 2127, Address: 0x2d0984, Func Offset: 0x254
	// Line 2119, Address: 0x2d0988, Func Offset: 0x258
	// Line 2120, Address: 0x2d0990, Func Offset: 0x260
	// Line 2123, Address: 0x2d0998, Func Offset: 0x268
	// Line 2124, Address: 0x2d09a0, Func Offset: 0x270
	// Line 2118, Address: 0x2d09a8, Func Offset: 0x278
	// Line 2125, Address: 0x2d09ac, Func Offset: 0x27c
	// Line 2123, Address: 0x2d09b4, Func Offset: 0x284
	// Line 2114, Address: 0x2d09b8, Func Offset: 0x288
	// Line 2119, Address: 0x2d09c0, Func Offset: 0x290
	// Line 2120, Address: 0x2d09c8, Func Offset: 0x298
	// Line 2124, Address: 0x2d09d0, Func Offset: 0x2a0
	// Line 2118, Address: 0x2d09d4, Func Offset: 0x2a4
	// Line 2123, Address: 0x2d09dc, Func Offset: 0x2ac
	// Line 2119, Address: 0x2d09e4, Func Offset: 0x2b4
	// Line 2124, Address: 0x2d09f0, Func Offset: 0x2c0
	// Line 2120, Address: 0x2d09f8, Func Offset: 0x2c8
	// Line 2125, Address: 0x2d0a04, Func Offset: 0x2d4
	// Line 2128, Address: 0x2d0a10, Func Offset: 0x2e0
	// Func End, Address: 0x2d0a20, Func Offset: 0x2f0
}

// 
// Start address: 0x2d0a20
tagCHUNK_HEAD* njCnkCmS(tagCHUNK_HEAD* pCnk)
{
	unsigned char* ucpPtr;
	// Line 2146, Address: 0x2d0a20, Func Offset: 0
	// Line 2150, Address: 0x2d0a2c, Func Offset: 0xc
	// Line 2153, Address: 0x2d0a40, Func Offset: 0x20
	// Line 2159, Address: 0x2d0a7c, Func Offset: 0x5c
	// Line 2160, Address: 0x2d0ac4, Func Offset: 0xa4
	// Line 2161, Address: 0x2d0b0c, Func Offset: 0xec
	// Line 2162, Address: 0x2d0b54, Func Offset: 0x134
	// Line 2166, Address: 0x2d0b90, Func Offset: 0x170
	// Line 2165, Address: 0x2d0b98, Func Offset: 0x178
	// Line 2166, Address: 0x2d0b9c, Func Offset: 0x17c
	// Func End, Address: 0x2d0ba4, Func Offset: 0x184
}

// 
// Start address: 0x2d0bb0
tagCHUNK_HEAD* njCnkCmDs(tagCHUNK_HEAD* pCnk)
{
	unsigned char* ucpPtr;
	// Line 2184, Address: 0x2d0bb0, Func Offset: 0
	// Line 2188, Address: 0x2d0bbc, Func Offset: 0xc
	// Line 2191, Address: 0x2d0bd0, Func Offset: 0x20
	// Line 2197, Address: 0x2d0c0c, Func Offset: 0x5c
	// Line 2198, Address: 0x2d0c54, Func Offset: 0xa4
	// Line 2199, Address: 0x2d0c9c, Func Offset: 0xec
	// Line 2200, Address: 0x2d0ce4, Func Offset: 0x134
	// Line 2204, Address: 0x2d0d2c, Func Offset: 0x17c
	// Line 2205, Address: 0x2d0d74, Func Offset: 0x1c4
	// Line 2206, Address: 0x2d0dbc, Func Offset: 0x20c
	// Line 2207, Address: 0x2d0e04, Func Offset: 0x254
	// Line 2211, Address: 0x2d0e40, Func Offset: 0x290
	// Line 2210, Address: 0x2d0e48, Func Offset: 0x298
	// Line 2211, Address: 0x2d0e4c, Func Offset: 0x29c
	// Func End, Address: 0x2d0e54, Func Offset: 0x2a4
}

// 
// Start address: 0x2d0e60
tagCHUNK_HEAD* njCnkCmAs(tagCHUNK_HEAD* pCnk)
{
	unsigned char* ucpPtr;
	// Line 2229, Address: 0x2d0e60, Func Offset: 0
	// Line 2233, Address: 0x2d0e6c, Func Offset: 0xc
	// Line 2236, Address: 0x2d0e80, Func Offset: 0x20
	// Line 2242, Address: 0x2d0ebc, Func Offset: 0x5c
	// Line 2243, Address: 0x2d0f04, Func Offset: 0xa4
	// Line 2244, Address: 0x2d0f4c, Func Offset: 0xec
	// Line 2248, Address: 0x2d0f88, Func Offset: 0x128
	// Line 2244, Address: 0x2d0f8c, Func Offset: 0x12c
	// Line 2248, Address: 0x2d0f90, Func Offset: 0x130
	// Line 2249, Address: 0x2d0f94, Func Offset: 0x134
	// Line 2250, Address: 0x2d0f9c, Func Offset: 0x13c
	// Line 2253, Address: 0x2d0fa4, Func Offset: 0x144
	// Line 2254, Address: 0x2d0fac, Func Offset: 0x14c
	// Line 2248, Address: 0x2d0fb4, Func Offset: 0x154
	// Line 2255, Address: 0x2d0fb8, Func Offset: 0x158
	// Line 2253, Address: 0x2d0fc0, Func Offset: 0x160
	// Line 2244, Address: 0x2d0fc4, Func Offset: 0x164
	// Line 2249, Address: 0x2d0fcc, Func Offset: 0x16c
	// Line 2250, Address: 0x2d0fd4, Func Offset: 0x174
	// Line 2254, Address: 0x2d0fdc, Func Offset: 0x17c
	// Line 2248, Address: 0x2d0fe0, Func Offset: 0x180
	// Line 2253, Address: 0x2d0fe8, Func Offset: 0x188
	// Line 2249, Address: 0x2d0ff0, Func Offset: 0x190
	// Line 2254, Address: 0x2d0ffc, Func Offset: 0x19c
	// Line 2250, Address: 0x2d1004, Func Offset: 0x1a4
	// Line 2255, Address: 0x2d1010, Func Offset: 0x1b0
	// Line 2259, Address: 0x2d101c, Func Offset: 0x1bc
	// Line 2260, Address: 0x2d1064, Func Offset: 0x204
	// Line 2261, Address: 0x2d10ac, Func Offset: 0x24c
	// Line 2262, Address: 0x2d10f4, Func Offset: 0x294
	// Line 2266, Address: 0x2d1130, Func Offset: 0x2d0
	// Line 2265, Address: 0x2d1138, Func Offset: 0x2d8
	// Line 2266, Address: 0x2d113c, Func Offset: 0x2dc
	// Func End, Address: 0x2d1144, Func Offset: 0x2e4
}

// 
// Start address: 0x2d1150
tagCHUNK_HEAD* njCnkCmDas(tagCHUNK_HEAD* pCnk)
{
	unsigned char* ucpPtr;
	// Line 2284, Address: 0x2d1150, Func Offset: 0
	// Line 2288, Address: 0x2d115c, Func Offset: 0xc
	// Line 2291, Address: 0x2d1170, Func Offset: 0x20
	// Line 2297, Address: 0x2d11ac, Func Offset: 0x5c
	// Line 2298, Address: 0x2d11f4, Func Offset: 0xa4
	// Line 2299, Address: 0x2d123c, Func Offset: 0xec
	// Line 2300, Address: 0x2d1284, Func Offset: 0x134
	// Line 2304, Address: 0x2d12cc, Func Offset: 0x17c
	// Line 2305, Address: 0x2d1314, Func Offset: 0x1c4
	// Line 2306, Address: 0x2d135c, Func Offset: 0x20c
	// Line 2310, Address: 0x2d1398, Func Offset: 0x248
	// Line 2306, Address: 0x2d139c, Func Offset: 0x24c
	// Line 2310, Address: 0x2d13a0, Func Offset: 0x250
	// Line 2311, Address: 0x2d13a4, Func Offset: 0x254
	// Line 2312, Address: 0x2d13ac, Func Offset: 0x25c
	// Line 2315, Address: 0x2d13b4, Func Offset: 0x264
	// Line 2316, Address: 0x2d13bc, Func Offset: 0x26c
	// Line 2310, Address: 0x2d13c4, Func Offset: 0x274
	// Line 2317, Address: 0x2d13c8, Func Offset: 0x278
	// Line 2315, Address: 0x2d13d0, Func Offset: 0x280
	// Line 2306, Address: 0x2d13d4, Func Offset: 0x284
	// Line 2311, Address: 0x2d13dc, Func Offset: 0x28c
	// Line 2312, Address: 0x2d13e4, Func Offset: 0x294
	// Line 2316, Address: 0x2d13ec, Func Offset: 0x29c
	// Line 2310, Address: 0x2d13f0, Func Offset: 0x2a0
	// Line 2315, Address: 0x2d13f8, Func Offset: 0x2a8
	// Line 2311, Address: 0x2d1400, Func Offset: 0x2b0
	// Line 2316, Address: 0x2d140c, Func Offset: 0x2bc
	// Line 2312, Address: 0x2d1414, Func Offset: 0x2c4
	// Line 2317, Address: 0x2d1420, Func Offset: 0x2d0
	// Line 2320, Address: 0x2d142c, Func Offset: 0x2dc
	// Line 2321, Address: 0x2d1474, Func Offset: 0x324
	// Line 2322, Address: 0x2d14bc, Func Offset: 0x36c
	// Line 2323, Address: 0x2d1504, Func Offset: 0x3b4
	// Line 2327, Address: 0x2d1540, Func Offset: 0x3f0
	// Line 2326, Address: 0x2d1548, Func Offset: 0x3f8
	// Line 2327, Address: 0x2d154c, Func Offset: 0x3fc
	// Func End, Address: 0x2d1554, Func Offset: 0x404
}*/

// 100% matching!
CHUNK_HEAD* njCnkCoP4(CHUNK_HEAD* pCnk)
{
    return (CHUNK_HEAD*)((char*)&pCnk[1] + (pCnk->usSize * 2));
}

/*// 
// Start address: 0x2d1580
tagCHUNK_HEAD* njCnkCoSt(tagCHUNK_HEAD* pCnk)
{
	// Line 2367, Address: 0x2d1580, Func Offset: 0
	// Line 2368, Address: 0x2d158c, Func Offset: 0xc
	// Func End, Address: 0x2d1594, Func Offset: 0x14
}

// 
// Start address: 0x2d15a0
tagCHUNK_HEAD* njCnkCvVn(tagCHUNK_HEAD* pCnk)
{
	float fTRZ;
	float fTRY;
	float fTRX;
	float fR22;
	float fR21;
	float fR20;
	float fR12;
	float fR11;
	float fR10;
	float fR02;
	float fR01;
	float fR00;
	float fNSZ;
	float fNSY;
	float fNSX;
	float fZ;
	float fY;
	float fX;
	float fL;
	float fVSY;
	float fVSX;
	float fVSZ;
	float fB;
	float fG;
	float fR;
	float fI;
	int lLightCnt;
	tagCNK_LIGHT* pLightPtr;
	float* fpCnk;
	unsigned int ulIndex;
	tagVU1_STRIP_BUF* pBuffer;
	// Line 2641, Address: 0x2d15a0, Func Offset: 0
	// Line 2681, Address: 0x2d15ec, Func Offset: 0x4c
	// Line 2682, Address: 0x2d15f8, Func Offset: 0x58
	// Line 2683, Address: 0x2d15fc, Func Offset: 0x5c
	// Line 2685, Address: 0x2d1604, Func Offset: 0x64
	// Line 2681, Address: 0x2d160c, Func Offset: 0x6c
	// Line 2685, Address: 0x2d1614, Func Offset: 0x74
	// Line 2686, Address: 0x2d161c, Func Offset: 0x7c
	// Line 2687, Address: 0x2d1624, Func Offset: 0x84
	// Line 2688, Address: 0x2d162c, Func Offset: 0x8c
	// Line 2689, Address: 0x2d1634, Func Offset: 0x94
	// Line 2690, Address: 0x2d163c, Func Offset: 0x9c
	// Line 2691, Address: 0x2d1644, Func Offset: 0xa4
	// Line 2692, Address: 0x2d164c, Func Offset: 0xac
	// Line 2693, Address: 0x2d1654, Func Offset: 0xb4
	// Line 2694, Address: 0x2d165c, Func Offset: 0xbc
	// Line 2695, Address: 0x2d1664, Func Offset: 0xc4
	// Line 2696, Address: 0x2d166c, Func Offset: 0xcc
	// Line 2698, Address: 0x2d1670, Func Offset: 0xd0
	// Line 2701, Address: 0x2d1678, Func Offset: 0xd8
	// Line 2704, Address: 0x2d167c, Func Offset: 0xdc
	// Line 2702, Address: 0x2d1680, Func Offset: 0xe0
	// Line 2703, Address: 0x2d1684, Func Offset: 0xe4
	// Line 2704, Address: 0x2d1688, Func Offset: 0xe8
	// Line 2709, Address: 0x2d16ac, Func Offset: 0x10c
	// Line 2705, Address: 0x2d16b4, Func Offset: 0x114
	// Line 2706, Address: 0x2d16c4, Func Offset: 0x124
	// Line 2705, Address: 0x2d16d4, Func Offset: 0x134
	// Line 2706, Address: 0x2d16e0, Func Offset: 0x140
	// Line 2705, Address: 0x2d16e8, Func Offset: 0x148
	// Line 2706, Address: 0x2d16f0, Func Offset: 0x150
	// Line 2710, Address: 0x2d16f8, Func Offset: 0x158
	// Line 2706, Address: 0x2d16fc, Func Offset: 0x15c
	// Line 2714, Address: 0x2d1700, Func Offset: 0x160
	// Line 2717, Address: 0x2d170c, Func Offset: 0x16c
	// Line 2733, Address: 0x2d1714, Func Offset: 0x174
	// Line 2717, Address: 0x2d171c, Func Offset: 0x17c
	// Line 2714, Address: 0x2d1720, Func Offset: 0x180
	// Line 2718, Address: 0x2d1724, Func Offset: 0x184
	// Line 2719, Address: 0x2d172c, Func Offset: 0x18c
	// Line 2718, Address: 0x2d1730, Func Offset: 0x190
	// Line 2719, Address: 0x2d1734, Func Offset: 0x194
	// Line 2733, Address: 0x2d173c, Func Offset: 0x19c
	// Line 2720, Address: 0x2d1740, Func Offset: 0x1a0
	// Line 2733, Address: 0x2d1744, Func Offset: 0x1a4
	// Line 2719, Address: 0x2d1748, Func Offset: 0x1a8
	// Line 2720, Address: 0x2d1754, Func Offset: 0x1b4
	// Line 2734, Address: 0x2d1760, Func Offset: 0x1c0
	// Line 2720, Address: 0x2d1764, Func Offset: 0x1c4
	// Line 2721, Address: 0x2d1768, Func Offset: 0x1c8
	// Line 2724, Address: 0x2d176c, Func Offset: 0x1cc
	// Line 2727, Address: 0x2d1770, Func Offset: 0x1d0
	// Line 2725, Address: 0x2d1774, Func Offset: 0x1d4
	// Line 2726, Address: 0x2d1778, Func Offset: 0x1d8
	// Line 2727, Address: 0x2d177c, Func Offset: 0x1dc
	// Line 2728, Address: 0x2d1794, Func Offset: 0x1f4
	// Line 2729, Address: 0x2d179c, Func Offset: 0x1fc
	// Line 2728, Address: 0x2d17a4, Func Offset: 0x204
	// Line 2729, Address: 0x2d17b0, Func Offset: 0x210
	// Line 2728, Address: 0x2d17b8, Func Offset: 0x218
	// Line 2729, Address: 0x2d17c0, Func Offset: 0x220
	// Line 2730, Address: 0x2d17cc, Func Offset: 0x22c
	// Line 2734, Address: 0x2d17d0, Func Offset: 0x230
	// Line 2735, Address: 0x2d17d4, Func Offset: 0x234
	// Line 2734, Address: 0x2d17d8, Func Offset: 0x238
	// Line 2735, Address: 0x2d17dc, Func Offset: 0x23c
	// Line 2737, Address: 0x2d17e8, Func Offset: 0x248
	// Line 2740, Address: 0x2d17f4, Func Offset: 0x254
	// Line 2743, Address: 0x2d1800, Func Offset: 0x260
	// Line 2744, Address: 0x2d180c, Func Offset: 0x26c
	// Line 2743, Address: 0x2d1810, Func Offset: 0x270
	// Line 2744, Address: 0x2d1820, Func Offset: 0x280
	// Line 2745, Address: 0x2d1830, Func Offset: 0x290
	// Line 2746, Address: 0x2d1834, Func Offset: 0x294
	// Line 2751, Address: 0x2d183c, Func Offset: 0x29c
	// Line 2752, Address: 0x2d1840, Func Offset: 0x2a0
	// Line 2750, Address: 0x2d1844, Func Offset: 0x2a4
	// Line 2754, Address: 0x2d184c, Func Offset: 0x2ac
	// Line 2751, Address: 0x2d1850, Func Offset: 0x2b0
	// Line 2750, Address: 0x2d1854, Func Offset: 0x2b4
	// Line 2752, Address: 0x2d1858, Func Offset: 0x2b8
	// Line 2753, Address: 0x2d185c, Func Offset: 0x2bc
	// Line 2754, Address: 0x2d186c, Func Offset: 0x2cc
	// Line 2755, Address: 0x2d187c, Func Offset: 0x2dc
	// Line 2756, Address: 0x2d1884, Func Offset: 0x2e4
	// Line 2757, Address: 0x2d1888, Func Offset: 0x2e8
	// Line 2758, Address: 0x2d188c, Func Offset: 0x2ec
	// Line 2759, Address: 0x2d1890, Func Offset: 0x2f0
	// Line 2760, Address: 0x2d189c, Func Offset: 0x2fc
	// Line 2759, Address: 0x2d18a0, Func Offset: 0x300
	// Line 2760, Address: 0x2d18a4, Func Offset: 0x304
	// Line 2762, Address: 0x2d18b4, Func Offset: 0x314
	// Line 2763, Address: 0x2d18c8, Func Offset: 0x328
	// Line 2767, Address: 0x2d18d8, Func Offset: 0x338
	// Line 2768, Address: 0x2d18dc, Func Offset: 0x33c
	// Line 2769, Address: 0x2d18e0, Func Offset: 0x340
	// Line 2767, Address: 0x2d18e4, Func Offset: 0x344
	// Line 2768, Address: 0x2d18e8, Func Offset: 0x348
	// Line 2769, Address: 0x2d18ec, Func Offset: 0x34c
	// Line 2767, Address: 0x2d18f0, Func Offset: 0x350
	// Line 2768, Address: 0x2d18f4, Func Offset: 0x354
	// Line 2769, Address: 0x2d18f8, Func Offset: 0x358
	// Line 2770, Address: 0x2d18fc, Func Offset: 0x35c
	// Line 2771, Address: 0x2d1910, Func Offset: 0x370
	// Line 2772, Address: 0x2d1914, Func Offset: 0x374
	// Line 2773, Address: 0x2d1918, Func Offset: 0x378
	// Line 2774, Address: 0x2d191c, Func Offset: 0x37c
	// Line 2776, Address: 0x2d1928, Func Offset: 0x388
	// Line 2777, Address: 0x2d192c, Func Offset: 0x38c
	// Func End, Address: 0x2d197c, Func Offset: 0x3dc
}

// 
// Start address: 0x2d1980
tagCHUNK_HEAD* njCnkCvVnPs2(tagCHUNK_HEAD* pCnk)
{
	unsigned int tmp;
	tagCNK_LIGHT* lp;
	float v[4][11];
	float fog;
	float* fpCnk;
	unsigned int ulIndex;
	tagVU1_STRIP_BUF* pBuffer;
	unsigned int mask[5];
	// Line 2857, Address: 0x2d1980, Func Offset: 0
	// Line 2872, Address: 0x2d1998, Func Offset: 0x18
	// Line 2897, Address: 0x2d19a0, Func Offset: 0x20
	// Line 2898, Address: 0x2d19a8, Func Offset: 0x28
	// Line 2872, Address: 0x2d19ac, Func Offset: 0x2c
	// Line 2934, Address: 0x2d19b0, Func Offset: 0x30
	// Line 2874, Address: 0x2d19b4, Func Offset: 0x34
	// Line 2875, Address: 0x2d19bc, Func Offset: 0x3c
	// Line 2876, Address: 0x2d19c4, Func Offset: 0x44
	// Line 2877, Address: 0x2d19cc, Func Offset: 0x4c
	// Line 2879, Address: 0x2d19d4, Func Offset: 0x54
	// Line 2880, Address: 0x2d19dc, Func Offset: 0x5c
	// Line 2881, Address: 0x2d19e4, Func Offset: 0x64
	// Line 2882, Address: 0x2d19ec, Func Offset: 0x6c
	// Line 2884, Address: 0x2d19f4, Func Offset: 0x74
	// Line 2885, Address: 0x2d19fc, Func Offset: 0x7c
	// Line 2886, Address: 0x2d1a04, Func Offset: 0x84
	// Line 2887, Address: 0x2d1a0c, Func Offset: 0x8c
	// Line 2897, Address: 0x2d1a14, Func Offset: 0x94
	// Line 2889, Address: 0x2d1a18, Func Offset: 0x98
	// Line 2897, Address: 0x2d1a2c, Func Offset: 0xac
	// Line 2889, Address: 0x2d1a34, Func Offset: 0xb4
	// Line 2897, Address: 0x2d1a6c, Func Offset: 0xec
	// Line 2889, Address: 0x2d1a70, Func Offset: 0xf0
	// Line 2897, Address: 0x2d1a7c, Func Offset: 0xfc
	// Line 2898, Address: 0x2d1a80, Func Offset: 0x100
	// Line 2900, Address: 0x2d1a84, Func Offset: 0x104
	// Line 2901, Address: 0x2d1a8c, Func Offset: 0x10c
	// Line 2902, Address: 0x2d1a94, Func Offset: 0x114
	// Line 2903, Address: 0x2d1a9c, Func Offset: 0x11c
	// Line 2905, Address: 0x2d1aa4, Func Offset: 0x124
	// Line 2906, Address: 0x2d1aac, Func Offset: 0x12c
	// Line 2907, Address: 0x2d1ab4, Func Offset: 0x134
	// Line 2908, Address: 0x2d1abc, Func Offset: 0x13c
	// Line 2910, Address: 0x2d1ac4, Func Offset: 0x144
	// Line 2911, Address: 0x2d1acc, Func Offset: 0x14c
	// Line 2912, Address: 0x2d1ad4, Func Offset: 0x154
	// Line 2913, Address: 0x2d1adc, Func Offset: 0x15c
	// Line 2915, Address: 0x2d1ae4, Func Offset: 0x164
	// Line 2916, Address: 0x2d1aec, Func Offset: 0x16c
	// Line 2917, Address: 0x2d1af4, Func Offset: 0x174
	// Line 2918, Address: 0x2d1afc, Func Offset: 0x17c
	// Line 2920, Address: 0x2d1b04, Func Offset: 0x184
	// Line 2921, Address: 0x2d1b0c, Func Offset: 0x18c
	// Line 2922, Address: 0x2d1b14, Func Offset: 0x194
	// Line 2923, Address: 0x2d1b1c, Func Offset: 0x19c
	// Line 2925, Address: 0x2d1b24, Func Offset: 0x1a4
	// Line 2926, Address: 0x2d1b2c, Func Offset: 0x1ac
	// Line 2927, Address: 0x2d1b34, Func Offset: 0x1b4
	// Line 2928, Address: 0x2d1b3c, Func Offset: 0x1bc
	// Line 2930, Address: 0x2d1b44, Func Offset: 0x1c4
	// Line 2931, Address: 0x2d1b4c, Func Offset: 0x1cc
	// Line 2932, Address: 0x2d1b54, Func Offset: 0x1d4
	// Line 2933, Address: 0x2d1b5c, Func Offset: 0x1dc
	// Line 2936, Address: 0x2d1b64, Func Offset: 0x1e4
	// Line 2937, Address: 0x2d1b68, Func Offset: 0x1e8
	// Line 2938, Address: 0x2d1b6c, Func Offset: 0x1ec
	// Line 2939, Address: 0x2d1b70, Func Offset: 0x1f0
	// Line 2940, Address: 0x2d1b74, Func Offset: 0x1f4
	// Line 2941, Address: 0x2d1b78, Func Offset: 0x1f8
	// Line 2942, Address: 0x2d1b7c, Func Offset: 0x1fc
	// Line 2943, Address: 0x2d1b80, Func Offset: 0x200
	// Line 2944, Address: 0x2d1b84, Func Offset: 0x204
	// Line 2945, Address: 0x2d1b88, Func Offset: 0x208
	// Line 2946, Address: 0x2d1b8c, Func Offset: 0x20c
	// Line 2955, Address: 0x2d1b90, Func Offset: 0x210
	// Line 2957, Address: 0x2d1b98, Func Offset: 0x218
	// Line 2958, Address: 0x2d1b9c, Func Offset: 0x21c
	// Line 2959, Address: 0x2d1ba8, Func Offset: 0x228
	// Line 2960, Address: 0x2d1bac, Func Offset: 0x22c
	// Line 2961, Address: 0x2d1bb0, Func Offset: 0x230
	// Line 2967, Address: 0x2d1bb4, Func Offset: 0x234
	// Line 2958, Address: 0x2d1bb8, Func Offset: 0x238
	// Line 2967, Address: 0x2d1bbc, Func Offset: 0x23c
	// Line 2972, Address: 0x2d1bc8, Func Offset: 0x248
	// Line 2984, Address: 0x2d1bd0, Func Offset: 0x250
	// Line 2986, Address: 0x2d1bd4, Func Offset: 0x254
	// Line 2996, Address: 0x2d1bdc, Func Offset: 0x25c
	// Line 2997, Address: 0x2d1be0, Func Offset: 0x260
	// Line 2998, Address: 0x2d1be4, Func Offset: 0x264
	// Line 2999, Address: 0x2d1be8, Func Offset: 0x268
	// Line 3000, Address: 0x2d1bec, Func Offset: 0x26c
	// Line 3003, Address: 0x2d1bf0, Func Offset: 0x270
	// Line 3004, Address: 0x2d1bf4, Func Offset: 0x274
	// Line 3012, Address: 0x2d1bf8, Func Offset: 0x278
	// Line 3013, Address: 0x2d1bfc, Func Offset: 0x27c
	// Line 3016, Address: 0x2d1c00, Func Offset: 0x280
	// Line 3029, Address: 0x2d1c08, Func Offset: 0x288
	// Line 3030, Address: 0x2d1c0c, Func Offset: 0x28c
	// Line 3032, Address: 0x2d1c10, Func Offset: 0x290
	// Line 3040, Address: 0x2d1c18, Func Offset: 0x298
	// Line 3042, Address: 0x2d1c20, Func Offset: 0x2a0
	// Line 3040, Address: 0x2d1c28, Func Offset: 0x2a8
	// Line 3044, Address: 0x2d1c2c, Func Offset: 0x2ac
	// Line 3045, Address: 0x2d1c30, Func Offset: 0x2b0
	// Line 3046, Address: 0x2d1c34, Func Offset: 0x2b4
	// Line 3047, Address: 0x2d1c38, Func Offset: 0x2b8
	// Line 3048, Address: 0x2d1c3c, Func Offset: 0x2bc
	// Line 3049, Address: 0x2d1c40, Func Offset: 0x2c0
	// Line 3052, Address: 0x2d1c44, Func Offset: 0x2c4
	// Line 3053, Address: 0x2d1c48, Func Offset: 0x2c8
	// Line 3055, Address: 0x2d1c4c, Func Offset: 0x2cc
	// Line 3056, Address: 0x2d1c50, Func Offset: 0x2d0
	// Line 3063, Address: 0x2d1c54, Func Offset: 0x2d4
	// Line 3065, Address: 0x2d1c68, Func Offset: 0x2e8
	// Line 3069, Address: 0x2d1c74, Func Offset: 0x2f4
	// Line 3077, Address: 0x2d1c78, Func Offset: 0x2f8
	// Line 3078, Address: 0x2d1c7c, Func Offset: 0x2fc
	// Func End, Address: 0x2d1c98, Func Offset: 0x318
}

// 
// Start address: 0x2d1ca0
tagCHUNK_HEAD* njCnkCvVMod(tagCHUNK_HEAD* pCnk)
{
	float fTRZ;
	float fTRY;
	float fTRX;
	float fR22;
	float fR21;
	float fR20;
	float fR12;
	float fR11;
	float fR10;
	float fR02;
	float fR01;
	float fR00;
	float fZ;
	float fY;
	float fX;
	float fVSY;
	float fVSX;
	float fVSZ;
	float fI;
	float* fpCnk;
	unsigned int ulIndex;
	tagVU1_STRIP_BUF* pBuffer;
	// Line 3392, Address: 0x2d1ca0, Func Offset: 0
	// Line 3410, Address: 0x2d1ce4, Func Offset: 0x44
	// Line 3411, Address: 0x2d1cf0, Func Offset: 0x50
	// Line 3412, Address: 0x2d1cf4, Func Offset: 0x54
	// Line 3414, Address: 0x2d1cfc, Func Offset: 0x5c
	// Line 3410, Address: 0x2d1d04, Func Offset: 0x64
	// Line 3414, Address: 0x2d1d0c, Func Offset: 0x6c
	// Line 3417, Address: 0x2d1d10, Func Offset: 0x70
	// Line 3418, Address: 0x2d1d14, Func Offset: 0x74
	// Line 3419, Address: 0x2d1d18, Func Offset: 0x78
	// Line 3420, Address: 0x2d1d1c, Func Offset: 0x7c
	// Line 3421, Address: 0x2d1d20, Func Offset: 0x80
	// Line 3414, Address: 0x2d1d24, Func Offset: 0x84
	// Line 3415, Address: 0x2d1d28, Func Offset: 0x88
	// Line 3422, Address: 0x2d1d2c, Func Offset: 0x8c
	// Line 3423, Address: 0x2d1d30, Func Offset: 0x90
	// Line 3424, Address: 0x2d1d34, Func Offset: 0x94
	// Line 3425, Address: 0x2d1d38, Func Offset: 0x98
	// Line 3427, Address: 0x2d1d3c, Func Offset: 0x9c
	// Line 3415, Address: 0x2d1d40, Func Offset: 0xa0
	// Line 3416, Address: 0x2d1d44, Func Offset: 0xa4
	// Line 3428, Address: 0x2d1d4c, Func Offset: 0xac
	// Line 3431, Address: 0x2d1d54, Func Offset: 0xb4
	// Line 3434, Address: 0x2d1d58, Func Offset: 0xb8
	// Line 3442, Address: 0x2d1d5c, Func Offset: 0xbc
	// Line 3432, Address: 0x2d1d60, Func Offset: 0xc0
	// Line 3433, Address: 0x2d1d64, Func Offset: 0xc4
	// Line 3442, Address: 0x2d1d68, Func Offset: 0xc8
	// Line 3434, Address: 0x2d1d70, Func Offset: 0xd0
	// Line 3433, Address: 0x2d1d74, Func Offset: 0xd4
	// Line 3434, Address: 0x2d1d78, Func Offset: 0xd8
	// Line 3435, Address: 0x2d1d84, Func Offset: 0xe4
	// Line 3434, Address: 0x2d1d88, Func Offset: 0xe8
	// Line 3439, Address: 0x2d1d8c, Func Offset: 0xec
	// Line 3435, Address: 0x2d1d90, Func Offset: 0xf0
	// Line 3436, Address: 0x2d1d98, Func Offset: 0xf8
	// Line 3435, Address: 0x2d1da4, Func Offset: 0x104
	// Line 3436, Address: 0x2d1dac, Func Offset: 0x10c
	// Line 3435, Address: 0x2d1db0, Func Offset: 0x110
	// Line 3436, Address: 0x2d1db4, Func Offset: 0x114
	// Line 3440, Address: 0x2d1dbc, Func Offset: 0x11c
	// Line 3442, Address: 0x2d1dc0, Func Offset: 0x120
	// Line 3445, Address: 0x2d1de0, Func Offset: 0x140
	// Line 3448, Address: 0x2d1dec, Func Offset: 0x14c
	// Line 3449, Address: 0x2d1df4, Func Offset: 0x154
	// Line 3448, Address: 0x2d1df8, Func Offset: 0x158
	// Line 3449, Address: 0x2d1dfc, Func Offset: 0x15c
	// Line 3453, Address: 0x2d1e00, Func Offset: 0x160
	// Line 3450, Address: 0x2d1e04, Func Offset: 0x164
	// Line 3449, Address: 0x2d1e08, Func Offset: 0x168
	// Line 3450, Address: 0x2d1e0c, Func Offset: 0x16c
	// Line 3451, Address: 0x2d1e14, Func Offset: 0x174
	// Line 3450, Address: 0x2d1e18, Func Offset: 0x178
	// Line 3451, Address: 0x2d1e20, Func Offset: 0x180
	// Line 3452, Address: 0x2d1e30, Func Offset: 0x190
	// Line 3453, Address: 0x2d1e34, Func Offset: 0x194
	// Line 3455, Address: 0x2d1e40, Func Offset: 0x1a0
	// Line 3456, Address: 0x2d1e44, Func Offset: 0x1a4
	// Func End, Address: 0x2d1e8c, Func Offset: 0x1ec
}

// 
// Start address: 0x2d1e90
tagCHUNK_HEAD* njCnkCoP3(tagCHUNK_HEAD* pCnk)
{
	float fNormal;
	unsigned short usPoly;
	unsigned short usNext;
	tagCNK_PRIM_BUF* pP;
	tagVU1_STRIP_BUF* pV2;
	tagVU1_STRIP_BUF* pV1;
	tagVU1_STRIP_BUF* pV0;
	unsigned short* uspCnk;
	// Line 3476, Address: 0x2d1e90, Func Offset: 0
	// Line 3491, Address: 0x2d1ea8, Func Offset: 0x18
	// Line 3490, Address: 0x2d1eac, Func Offset: 0x1c
	// Line 3493, Address: 0x2d1eb0, Func Offset: 0x20
	// Line 3491, Address: 0x2d1eb4, Func Offset: 0x24
	// Line 3492, Address: 0x2d1eb8, Func Offset: 0x28
	// Line 3495, Address: 0x2d1ebc, Func Offset: 0x2c
	// Line 3499, Address: 0x2d1ecc, Func Offset: 0x3c
	// Line 3497, Address: 0x2d1ed8, Func Offset: 0x48
	// Line 3499, Address: 0x2d1ee0, Func Offset: 0x50
	// Line 3501, Address: 0x2d1ee4, Func Offset: 0x54
	// Line 3499, Address: 0x2d1ee8, Func Offset: 0x58
	// Line 3500, Address: 0x2d1eec, Func Offset: 0x5c
	// Line 3504, Address: 0x2d1ef0, Func Offset: 0x60
	// Line 3505, Address: 0x2d1ef4, Func Offset: 0x64
	// Line 3500, Address: 0x2d1ef8, Func Offset: 0x68
	// Line 3501, Address: 0x2d1efc, Func Offset: 0x6c
	// Line 3502, Address: 0x2d1f00, Func Offset: 0x70
	// Line 3503, Address: 0x2d1f04, Func Offset: 0x74
	// Line 3504, Address: 0x2d1f08, Func Offset: 0x78
	// Line 3505, Address: 0x2d1f0c, Func Offset: 0x7c
	// Line 3506, Address: 0x2d1f14, Func Offset: 0x84
	// Line 3505, Address: 0x2d1f18, Func Offset: 0x88
	// Line 3506, Address: 0x2d1f20, Func Offset: 0x90
	// Line 3510, Address: 0x2d1f28, Func Offset: 0x98
	// Line 3506, Address: 0x2d1f2c, Func Offset: 0x9c
	// Line 3507, Address: 0x2d1f34, Func Offset: 0xa4
	// Line 3508, Address: 0x2d1f3c, Func Offset: 0xac
	// Line 3510, Address: 0x2d1f44, Func Offset: 0xb4
	// Line 3511, Address: 0x2d1f68, Func Offset: 0xd8
	// Line 3512, Address: 0x2d1f90, Func Offset: 0x100
	// Line 3513, Address: 0x2d1fb8, Func Offset: 0x128
	// Line 3517, Address: 0x2d1fe0, Func Offset: 0x150
	// Line 3519, Address: 0x2d1fec, Func Offset: 0x15c
	// Line 3522, Address: 0x2d1ff0, Func Offset: 0x160
	// Line 3517, Address: 0x2d1ff4, Func Offset: 0x164
	// Line 3518, Address: 0x2d1ffc, Func Offset: 0x16c
	// Line 3523, Address: 0x2d2000, Func Offset: 0x170
	// Line 3518, Address: 0x2d2004, Func Offset: 0x174
	// Line 3519, Address: 0x2d2008, Func Offset: 0x178
	// Line 3520, Address: 0x2d200c, Func Offset: 0x17c
	// Line 3521, Address: 0x2d2010, Func Offset: 0x180
	// Line 3522, Address: 0x2d2014, Func Offset: 0x184
	// Line 3523, Address: 0x2d2018, Func Offset: 0x188
	// Line 3524, Address: 0x2d2020, Func Offset: 0x190
	// Line 3523, Address: 0x2d2024, Func Offset: 0x194
	// Line 3524, Address: 0x2d202c, Func Offset: 0x19c
	// Line 3528, Address: 0x2d2034, Func Offset: 0x1a4
	// Line 3524, Address: 0x2d2038, Func Offset: 0x1a8
	// Line 3525, Address: 0x2d2040, Func Offset: 0x1b0
	// Line 3526, Address: 0x2d2048, Func Offset: 0x1b8
	// Line 3528, Address: 0x2d2050, Func Offset: 0x1c0
	// Line 3529, Address: 0x2d2070, Func Offset: 0x1e0
	// Line 3530, Address: 0x2d2098, Func Offset: 0x208
	// Line 3531, Address: 0x2d20c0, Func Offset: 0x230
	// Line 3535, Address: 0x2d20e8, Func Offset: 0x258
	// Line 3537, Address: 0x2d20f4, Func Offset: 0x264
	// Line 3540, Address: 0x2d20f8, Func Offset: 0x268
	// Line 3535, Address: 0x2d20fc, Func Offset: 0x26c
	// Line 3536, Address: 0x2d2104, Func Offset: 0x274
	// Line 3541, Address: 0x2d2108, Func Offset: 0x278
	// Line 3536, Address: 0x2d210c, Func Offset: 0x27c
	// Line 3537, Address: 0x2d2110, Func Offset: 0x280
	// Line 3538, Address: 0x2d2114, Func Offset: 0x284
	// Line 3539, Address: 0x2d2118, Func Offset: 0x288
	// Line 3540, Address: 0x2d211c, Func Offset: 0x28c
	// Line 3541, Address: 0x2d2120, Func Offset: 0x290
	// Line 3542, Address: 0x2d2128, Func Offset: 0x298
	// Line 3541, Address: 0x2d212c, Func Offset: 0x29c
	// Line 3542, Address: 0x2d2134, Func Offset: 0x2a4
	// Line 3546, Address: 0x2d213c, Func Offset: 0x2ac
	// Line 3542, Address: 0x2d2140, Func Offset: 0x2b0
	// Line 3543, Address: 0x2d2148, Func Offset: 0x2b8
	// Line 3544, Address: 0x2d2150, Func Offset: 0x2c0
	// Line 3546, Address: 0x2d2158, Func Offset: 0x2c8
	// Line 3547, Address: 0x2d2178, Func Offset: 0x2e8
	// Line 3548, Address: 0x2d21a0, Func Offset: 0x310
	// Line 3549, Address: 0x2d21c8, Func Offset: 0x338
	// Line 3552, Address: 0x2d21f0, Func Offset: 0x360
	// Line 3553, Address: 0x2d2208, Func Offset: 0x378
	// Line 3552, Address: 0x2d2210, Func Offset: 0x380
	// Line 3553, Address: 0x2d2224, Func Offset: 0x394
	// Line 3555, Address: 0x2d222c, Func Offset: 0x39c
	// Line 3556, Address: 0x2d224c, Func Offset: 0x3bc
	// Line 3557, Address: 0x2d2250, Func Offset: 0x3c0
	// Line 3560, Address: 0x2d2258, Func Offset: 0x3c8
	// Line 3561, Address: 0x2d227c, Func Offset: 0x3ec
	// Line 3567, Address: 0x2d2280, Func Offset: 0x3f0
	// Line 3564, Address: 0x2d2294, Func Offset: 0x404
	// Line 3567, Address: 0x2d2298, Func Offset: 0x408
	// Line 3568, Address: 0x2d22a0, Func Offset: 0x410
	// Line 3569, Address: 0x2d22b0, Func Offset: 0x420
	// Line 3571, Address: 0x2d22b8, Func Offset: 0x428
	// Line 3569, Address: 0x2d22bc, Func Offset: 0x42c
	// Line 3572, Address: 0x2d22c0, Func Offset: 0x430
	// Func End, Address: 0x2d22dc, Func Offset: 0x44c
}

// 
// Start address: 0x2d22e0
tagCHUNK_HEAD* njCnkCs(tagCHUNK_HEAD* pCnk)
{
	void(*pVu1Func)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
	unsigned short usColorCalc;
	unsigned short usClip;
	unsigned short usMax;
	unsigned short usCnt;
	unsigned short usStrip;
	unsigned short usNext;
	tagVU1_STRIP_BUF* pS;
	tagVU1_STRIP_BUF* pV;
	unsigned short* uspCnk;
	unsigned long ulType;
	// Line 3589, Address: 0x2d22e0, Func Offset: 0
	// Line 3591, Address: 0x2d2300, Func Offset: 0x20
	// Line 3605, Address: 0x2d2308, Func Offset: 0x28
	// Line 3608, Address: 0x2d2348, Func Offset: 0x68
	// Line 3611, Address: 0x2d2360, Func Offset: 0x80
	// Line 3613, Address: 0x2d2370, Func Offset: 0x90
	// Line 3614, Address: 0x2d237c, Func Offset: 0x9c
	// Line 3616, Address: 0x2d2388, Func Offset: 0xa8
	// Line 3619, Address: 0x2d2390, Func Offset: 0xb0
	// Line 3620, Address: 0x2d239c, Func Offset: 0xbc
	// Line 3621, Address: 0x2d23ac, Func Offset: 0xcc
	// Line 3622, Address: 0x2d23b8, Func Offset: 0xd8
	// Line 3627, Address: 0x2d23d4, Func Offset: 0xf4
	// Line 3631, Address: 0x2d23e4, Func Offset: 0x104
	// Line 3632, Address: 0x2d23e8, Func Offset: 0x108
	// Line 3627, Address: 0x2d23ec, Func Offset: 0x10c
	// Line 3633, Address: 0x2d2400, Func Offset: 0x120
	// Line 3634, Address: 0x2d2404, Func Offset: 0x124
	// Line 3632, Address: 0x2d2408, Func Offset: 0x128
	// Line 3636, Address: 0x2d240c, Func Offset: 0x12c
	// Line 3641, Address: 0x2d2420, Func Offset: 0x140
	// Line 3638, Address: 0x2d2424, Func Offset: 0x144
	// Line 3641, Address: 0x2d2428, Func Offset: 0x148
	// Line 3642, Address: 0x2d2430, Func Offset: 0x150
	// Line 3645, Address: 0x2d2450, Func Offset: 0x170
	// Line 3642, Address: 0x2d245c, Func Offset: 0x17c
	// Line 3659, Address: 0x2d2460, Func Offset: 0x180
	// Line 3645, Address: 0x2d2464, Func Offset: 0x184
	// Line 3659, Address: 0x2d2468, Func Offset: 0x188
	// Line 3645, Address: 0x2d246c, Func Offset: 0x18c
	// Line 3646, Address: 0x2d2470, Func Offset: 0x190
	// Line 3652, Address: 0x2d2474, Func Offset: 0x194
	// Line 3646, Address: 0x2d2478, Func Offset: 0x198
	// Line 3647, Address: 0x2d247c, Func Offset: 0x19c
	// Line 3648, Address: 0x2d2484, Func Offset: 0x1a4
	// Line 3652, Address: 0x2d248c, Func Offset: 0x1ac
	// Line 3653, Address: 0x2d249c, Func Offset: 0x1bc
	// Line 3652, Address: 0x2d24a0, Func Offset: 0x1c0
	// Line 3653, Address: 0x2d24a4, Func Offset: 0x1c4
	// Line 3654, Address: 0x2d24a8, Func Offset: 0x1c8
	// Line 3655, Address: 0x2d24b0, Func Offset: 0x1d0
	// Line 3659, Address: 0x2d24b8, Func Offset: 0x1d8
	// Line 3661, Address: 0x2d24c0, Func Offset: 0x1e0
	// Line 3667, Address: 0x2d24cc, Func Offset: 0x1ec
	// Line 3661, Address: 0x2d24d4, Func Offset: 0x1f4
	// Line 3662, Address: 0x2d24e0, Func Offset: 0x200
	// Line 3666, Address: 0x2d24e4, Func Offset: 0x204
	// Line 3662, Address: 0x2d24e8, Func Offset: 0x208
	// Line 3663, Address: 0x2d24ec, Func Offset: 0x20c
	// Line 3664, Address: 0x2d24f4, Func Offset: 0x214
	// Line 3667, Address: 0x2d24fc, Func Offset: 0x21c
	// Line 3670, Address: 0x2d2508, Func Offset: 0x228
	// Line 3671, Address: 0x2d2524, Func Offset: 0x244
	// Line 3673, Address: 0x2d2538, Func Offset: 0x258
	// Line 3674, Address: 0x2d253c, Func Offset: 0x25c
	// Func End, Address: 0x2d2560, Func Offset: 0x280
}

// 
// Start address: 0x2d2560
int _CVV(float* v0)
{
	int ret;
	// Line 3806, Address: 0x2d2560, Func Offset: 0
	// Line 3807, Address: 0x2d2564, Func Offset: 0x4
	// Line 3808, Address: 0x2d2568, Func Offset: 0x8
	// Line 3809, Address: 0x2d256c, Func Offset: 0xc
	// Line 3810, Address: 0x2d2570, Func Offset: 0x10
	// Line 3811, Address: 0x2d2574, Func Offset: 0x14
	// Line 3812, Address: 0x2d2578, Func Offset: 0x18
	// Line 3813, Address: 0x2d257c, Func Offset: 0x1c
	// Line 3814, Address: 0x2d2580, Func Offset: 0x20
	// Line 3815, Address: 0x2d2584, Func Offset: 0x24
	// Line 3816, Address: 0x2d2588, Func Offset: 0x28
	// Line 3817, Address: 0x2d258c, Func Offset: 0x2c
	// Line 3820, Address: 0x2d2590, Func Offset: 0x30
	// Func End, Address: 0x2d2598, Func Offset: 0x38
}*/

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

/*// 
// Start address: 0x2d37c0
void njCnkEasyMultiDrawObjectI(cnkobj* pObject)
{
	int lDrawResult;
	unsigned int ulFlags;
	// Line 4180, Address: 0x2d37c0, Func Offset: 0
	// Line 4186, Address: 0x2d37d4, Func Offset: 0x14
	// Line 4187, Address: 0x2d37dc, Func Offset: 0x1c
	// Line 4189, Address: 0x2d37ec, Func Offset: 0x2c
	// Line 4193, Address: 0x2d37f4, Func Offset: 0x34
	// Line 4196, Address: 0x2d37fc, Func Offset: 0x3c
	// Line 4197, Address: 0x2d3810, Func Offset: 0x50
	// Line 4198, Address: 0x2d3828, Func Offset: 0x68
	// Line 4202, Address: 0x2d3840, Func Offset: 0x80
	// Line 4205, Address: 0x2d385c, Func Offset: 0x9c
	// Line 4207, Address: 0x2d3880, Func Offset: 0xc0
	// Line 4210, Address: 0x2d3888, Func Offset: 0xc8
	// Line 4211, Address: 0x2d3890, Func Offset: 0xd0
	// Line 4212, Address: 0x2d38a0, Func Offset: 0xe0
	// Func End, Address: 0x2d38b4, Func Offset: 0xf4
}*/
