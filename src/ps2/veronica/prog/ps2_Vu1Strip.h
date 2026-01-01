#ifndef _PS2_VU1STRIP_H_
#define _PS2_VU1STRIP_H_

#include "types.h"

void vu1SetScreenProjection(float fProjection);
void vu1SetNearFarClip(float fNear, float fFar);
void vu1SetScreenOffset(float fOffsetX, float fOffsetY);
void vu1SetScreenAspect(float fAspectW, float fAspectH);
/*void vu1SetDiffuseMaterial(tagVU1_COLOR* pDiffuse);
void vu1SetSpeculaMaterial(tagVU1_COLOR* pSpecula);
void vu1SetAmbient(tagVU1_COLOR* pAmbient);*/
void vu1SetAlphaRatio(float fAlpha);
void InitNodeArraySet(register SCISSOR* scissor);
void InitScissorPlane(SCISSOR_PLANE* sp);
void _Init_ScissorSystem();
int _Clip_ViewVolume(float* clip, float local_clip[4], float* vertex);
/*void PushTriangleNodeArray(_anon2* scissor);
void ResetNodeArraySet(_anon2* scissor);
void ScissorTriangle(_anon2* scissor, _anon5* plane_set);
int _Check_DisplayAreaPoint(_anon3* vec);
void DrawScissorPolygonOpaque(_anon2* scissor, unsigned long ulType);
void vu1DrawTriangleStripOpaqueSingle(unsigned long ulType, tagVU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode);
void vu1DrawTriangleStripOpaqueDouble(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);
void vu1DrawTriangleStripTransSingle(unsigned long ulType, tagVU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode);*/
int _Clip_Screen(float* clip);
/*void vu1DrawTriangleStripTransDouble(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);*/
void vu1GetVertexColor(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorCM(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorIgnore(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDif(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifAmb(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe1(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe2(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe3(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe1Amb(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe2Amb(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe3Amb(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim);
/*void vu1RotTransStripBuf(float pMatrix[16], _anon3* pVector, tagVU1_STRIP_BUF* pBuf);
void vu1DrawTriangleStripTransDoubleI(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);
void DrawScissorPolygonTrans1P(_anon2* scissor, unsigned long ulType);
void vu1DrawTriangleStripTransDouble1P(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);*/

extern float fVu1Projection;

/*typedef struct tagVU1_STRIP_BUF;
typedef struct tagVU1_PRIM_BUF;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct tagVU1_COLOR;

typedef void(*type_0)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_2)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_12)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_14)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_17)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_18)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);

typedef float type_1[4][2];
typedef void(*type_3)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*)[11];
typedef float type_4[16];
typedef _anon4 type_5[12];
typedef float type_6[3];
typedef _anon0 type_7[2];
typedef unsigned char type_8[16384];
typedef float type_9[4][1];
typedef float type_10[4];
typedef _anon6 type_11[5];
typedef float type_13[4];
typedef float type_15[4][4];
typedef tagVU1_PRIM_BUF type_16[16];

struct tagVU1_STRIP_BUF
{
	float fU;
	float fV;
	float fPad0;
	float fPad1;
	float fIr;
	float fIg;
	float fIb;
	float fA;
	float fVx;
	float fVy;
	float fVz;
	float fFog;
	float fSx;
	float fSy;
	float fIz;
	float fNz;
};

struct tagVU1_PRIM_BUF
{
	float fS;
	float fT;
	float fQ;
	unsigned int ulKick;
	float fR;
	float fG;
	float fB;
	float fA;
	float fX;
	float fY;
	float fZ;
	float fF;
};

struct _anon0
{
	_anon4 node[12];
	unsigned int nodeNum;
	float pad[3];
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
	_anon0 triangle;
	_anon0 narray[2];
	_anon0* in;
	_anon0* out;
	unsigned int rotflag;
	unsigned int flipflag;
};

struct _anon3
{
	float x;
	float y;
	float z;
};

struct _anon4
{
	float vertex[4];
	float color[4];
	float texUV[4];
	float clipV[4];
};

struct _anon5
{
	_anon6 plane[5];
	unsigned int planeNum;
};

struct _anon6
{
	unsigned int xyzflag;
	unsigned int clipmask;
};

struct tagVU1_COLOR
{
	float fR;
	float fG;
	float fB;
	float fA;
};*/

#endif
