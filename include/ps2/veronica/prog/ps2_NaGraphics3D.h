#ifndef _PS2_NAGRAPHICS3D_H_
#define _PS2_NAGRAPHICS3D_H_

#include "types.h"

void Ps2SetPlane(PS2_PLANE* p, sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
void Ps2CalcScreenCone();
float Calc_Intersection2(sceVu0FVECTOR v0, sceVu0FVECTOR v1, PS2_PLANE* plane);
int CalcIntersectionCone(float* ans, float* v0, float* v1);
float Head_or_Tail(PS2_PLANE* plane, float* v);
float Across_Plane(PS2_PLANE* plane, float* v0, float* v1);
void    njDrawLine3D(NJS_POINT3COL *p, Int n, Uint32 attr);
void njDrawLine3DEx(NJS_POINT3COL* p, int n, unsigned int attr);
void    njDrawTriangle3D(NJS_POINT3COL *p, Int n, Uint32 attr);
void    njDrawPolygon3D(NJS_POINT3COL *p, Int n, Uint32 attr);

#endif
