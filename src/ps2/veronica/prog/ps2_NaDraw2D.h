#ifndef _PS2_NADRAW2D_H_
#define _PS2_NADRAW2D_H_

#include "types.h"

void CalcPs2ZbuffAB();
void sceVu0ITOF12Vector(sceVu0FVECTOR v0, sceVu0IVECTOR v1);
void	njDrawLine2D(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr);
void	njDrawPolygon2D(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr);
void njDrawPolygon2DM(NJS_POINT2COL* p, int n, float pri, unsigned int attr);

#endif
