#ifndef _PS2_VU1STRIP_H_
#define _PS2_VU1STRIP_H_

#include "types.h"

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
void PushTriangleNodeArray(SCISSOR* scissor);
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

#endif
