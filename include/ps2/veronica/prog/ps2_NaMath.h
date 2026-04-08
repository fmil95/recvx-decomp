#ifndef _PS2_NAMATH_H_
#define _PS2_NAMATH_H_

#include "types.h"

void _Make_SinTable();
Float	njSin(Angle n);
Float	njCos(Angle n);
void njSinCos(int lAngle, float* sin, float* cos);
Float	njFraction  (Float n);
Float	njSqrt(Float n);
Float	njInvertSqrt(Float n);
void	njLinear(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame);
void	njOverhauserSpline(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame);
void	njBezierSpline(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame);
unsigned int njFactorial(unsigned int ulN);

#endif
