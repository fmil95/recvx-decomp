#ifndef _PS2_VU1SCISSOR2_H_
#define _PS2_VU1SCISSOR2_H_

#include "types.h"

void DrawScissorPolygonOpaque2(int count, unsigned long ulType);
void InitNodeArraySet2();
unsigned int _Clip_ViewVolume2(NJS_POINT4* vec);
unsigned int _Get_ClipViewVolume2();
int _Get_ClipVolumePlane();
void _Check_ClipViewAll(NJS_POINT4* vec);
void _Set_NodeArray(VU1_STRIP_BUF* pS, VU1_PRIM_BUF* pP);
int _ClipInter(int mask1, int mask2, int xyzflg, float sin, int work0, int work1, int count);
int _Check_ScissorPlane();

#endif
