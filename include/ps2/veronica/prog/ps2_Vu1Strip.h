#ifndef _PS2_VU1STRIP_H_
#define _PS2_VU1STRIP_H_

#include "types.h"

typedef struct PLANE
{
	// total size: 0x8
    unsigned int xyzflag;  // offset 0x0, size 0x4
    unsigned int clipmask; // offset 0x4, size 0x4
} PLANE;

typedef struct SCISSOR_PLANE
{
    // total size: 0x2C
	PLANE plane[5];        // offset 0x0, size 0x28
	unsigned int planeNum; // offset 0x28, size 0x4
} SCISSOR_PLANE;

void vu1SetScreenProjection(float fProjection);
void vu1SetNearFarClip(float fNear, float fFar);
void vu1SetScreenOffset(float fOffsetX, float fOffsetY);
void vu1SetScreenAspect(float fAspectW, float fAspectH);
void vu1SetDiffuseMaterial(VU1_COLOR* pDiffuse);
void vu1SetSpeculaMaterial(VU1_COLOR* pSpecula);
void vu1SetAmbient(VU1_COLOR* pAmbient);
void vu1SetAlphaRatio(float fAlpha);
void InitNodeArraySet(SCISSOR* scissor);
static void InitScissorPlane(SCISSOR_PLANE* sp);
void _Init_ScissorSystem();
int _Clip_ViewVolume(float* clip, float local_clip[4], float* vertex);
void PushTriangleNodeArray(SCISSOR* scissor, NODE* nod);
void ResetNodeArraySet(SCISSOR* scissor);
void ScissorTriangle(SCISSOR* scissor, SCISSOR_PLANE* plane_set);
int _Check_DisplayAreaPoint(NJS_VECTOR* vec);
void DrawScissorPolygonOpaque(SCISSOR* scissor, unsigned long ulType);
void vu1DrawTriangleStripOpaqueSingle(unsigned long ulType, VU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode);
void vu1DrawTriangleStripOpaqueDouble(unsigned long ulType, VU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);
void vu1DrawTriangleStripTransSingle(unsigned long ulType, VU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode);
int _Clip_Screen(float* clip);
void vu1DrawTriangleStripTransDouble(unsigned long ulType, VU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);
void vu1GetVertexColor(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorCM(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorIgnore(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDif(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifAmb(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe1(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe2(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe3(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe1Amb(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe2Amb(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe3Amb(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1RotTransStripBuf(NJS_MATRIX* pMatrix, NJS_VECTOR* pVector, VU1_STRIP_BUF* pBuf);
void vu1DrawTriangleStripTransDoubleI(unsigned long ulType, VU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);
void DrawScissorPolygonTrans1P(SCISSOR* scissor, unsigned long ulType);
void vu1DrawTriangleStripTransDouble1P(unsigned long ulType, VU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);

extern float fVu1Projection;
extern VU1_PRIM_BUF vu1ScessorBuf[16];
extern VU1_COLOR vu1Diffuse;
extern VU1_COLOR vu1Specula;
extern VU1_COLOR vu1Ambient;
extern float fVu1NearClip;
extern float fVu1FarClip;
extern float fVu1OffsetX;
extern float fVu1OffsetY;
extern float fVu1AspectW;
extern float fVu1AspectH;
extern float fVu1AlphaRatio;

#endif
