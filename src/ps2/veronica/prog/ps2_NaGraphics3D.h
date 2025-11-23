#ifndef _PS2_NAGRAPHICS3D_H_
#define _PS2_NAGRAPHICS3D_H_

#include "types.h"

/*void Ps2SetPlane(_anon1* p, float* v0, float* v1, float* v2);*/
void Ps2CalcScreenCone();
/*float Calc_Intersection2(float* v0, float* v1, _anon1* plane);*/
int CalcIntersectionCone(float* ans, float* v0, float* v1);
float Head_or_Tail(float* v);
float Across_Plane(float* v0, float* v1);
/*void njDrawLine3D(_anon2* p, int n, unsigned int attr);
void njDrawLine3DEx(_anon2* p, int n, unsigned int attr);
void njDrawTriangle3D(_anon2* p, int n, unsigned int attr);
void njDrawPolygon3D(_anon2* p, int n, unsigned int attr);*/

/*typedef union _anon0;
typedef struct _anon1;
typedef struct tagVU1_STRIP_BUF;
typedef struct _anon2;
typedef struct _anon3;
typedef struct tagNJS_SCRVECTOR;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;


typedef float type_0[4][96];
typedef float type_1[4];
typedef float type_2[4][32];
typedef float type_3[4][4];
typedef _anon1 type_4[5];
typedef float type_5[4][32];
typedef float type_6[4][2];
typedef float type_7[4][64];
typedef tagVU1_STRIP_BUF type_8[256];

union _anon0
{
	unsigned int color;
	_anon5 tex;
	_anon6 argb;
};

struct _anon1
{
	float norm[4];
	float pos[4];
};

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

struct _anon2
{
	_anon3* p;
	_anon0* col;
	_anon0* tex;
	unsigned int num;
};

struct _anon3
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

struct _anon4
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};

struct _anon5
{
	short u;
	short v;
};

struct _anon6
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};*/

#endif
