#ifndef _PS2_NAVIEW_H_
#define _PS2_NAVIEW_H_

#include "types.h"

void    njSetScreen(NJS_SCREEN *s);
void	njSetPerspective(Angle ang);
void njSetScreenProjection(float dist);
void    njSetAspect(Float ax, Float ay);
void    njInitView(NJS_VIEW *v);
void    njSetView(NJS_VIEW *v);
void    njClipZ(Float n, Float f);
int     njCalcScreen(NJS_POINT3 *p, Float *sx, Float *sy);
void njViewScreenMatrix(NJS_MATRIX* vs);
void _Make_ClipMatrix(sceVu0FMATRIX sc, float scr, float near, float far);
void _Make_ClipVolume(float x, float y);

#endif
