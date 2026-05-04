#ifndef _PS2_NACOLI_H_
#define _PS2_NACOLI_H_

#include "types.h"

/*int njIsParalellL2L(_anon1* pLine1, _anon1* pLine2);
int njIsParalellL2PL(_anon1* pLine, _anon1* pPlane);*/
Float	njDistanceP2P(NJS_POINT3 *p1, NJS_POINT3 *p2);
/*float njDistanceP2L(_anon0* pPoint, _anon1* pLine, _anon0* pCross);
float njDistanceP2PL(_anon0* pPoint, _anon1* pPlane, _anon0* pCross);
float njDistanceL2L(_anon1* pLine1, _anon1* pLine2, _anon0* pCross1, _anon0* pCross2);
float njDistanceL2PL(_anon1* pLine, _anon1* pPlane, _anon0* pCross);
void njGetPlaneNormal(_anon0* pPoint, _anon0* pVector);*/
void	njGetPlaneNormal2(NJS_POINT3 *p0, NJS_POINT3 *p1, NJS_POINT3 *p2, NJS_VECTOR *v);
/*int njCollisionCheckSS(_anon4* pSphere1, _anon4* pSphere2);
int njCollisionCheckCC(_anon2* pCap1, _anon2* pCap2);
int njCollisionCheckSC(_anon4* pSphere, _anon2* pCapsule);
int njCollisionCheckBS(_anon3* pBox, _anon4* pSphere);
int njCollisionCheckBC(_anon3* pBox, _anon2* pCapsule);
int njCheckPlane4AndLine(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPN, _anon1* pLine);
int njCollisionCheckBC2(_anon3* pBox, _anon2* pCapsule);
int njCheckPlane4IncludePoint(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPC);*/

#endif
