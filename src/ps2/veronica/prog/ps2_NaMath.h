#ifndef _PS2_NAMATH_H_
#define _PS2_NAMATH_H_

#include "types.h"

void _Make_SinTable();
Float	njSin(Angle n);
void njSinCos(int lAngle, float* sin, float* cos);
Float	njFraction  (Float n);
unsigned int njFactorial(unsigned int ulN);

/*typedef struct _anon0;


typedef float type[16384];

struct _anon0
{
	int keys;
	int* iparam;
	float* fparam;
};*/

#endif
