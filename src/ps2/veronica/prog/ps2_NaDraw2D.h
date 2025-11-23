#ifndef _PS2_NADRAW2D_H_
#define _PS2_NADRAW2D_H_

#include "types.h"

void CalcPs2ZbuffAB();
void sceVu0ITOF12Vector(sceVu0FVECTOR v0, sceVu0IVECTOR v1);
/*void njDrawLine2D(_anon2* p, int n, float pri, unsigned int attr);
void njDrawPolygon2D(_anon2* p, int n, float pri, unsigned int attr);*/
void njDrawPolygon2DM(NJS_POINT2COL* p, int n, float pri, unsigned int attr);

/*typedef union _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;


typedef float type_0[4][32];
typedef float type_1[4][32];
typedef float type_2[4];
typedef float type_3[4][32];

union _anon0
{
	unsigned int color;
	_anon3 tex;
	_anon4 argb;
};

struct _anon1
{
	float x;
	float y;
};

struct _anon2
{
	_anon1* p;
	_anon0* col;
	_anon0* tex;
	unsigned int num;
};

struct _anon3
{
	short u;
	short v;
};

struct _anon4
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};*/

#endif
