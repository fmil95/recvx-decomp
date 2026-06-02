#ifndef _PS2_NACOLI_H_
#define _PS2_NACOLI_H_

#include "types.h"

Bool	njIsParalellL2L(NJS_LINE *l1, NJS_LINE *l2);
Bool	njIsParalellL2PL(NJS_LINE *l, NJS_PLANE *pl);
Float	njDistanceP2P(NJS_POINT3 *p1, NJS_POINT3 *p2);
Float	njDistanceP2L(NJS_POINT3 *p, NJS_LINE *l, NJS_POINT3 *cp);
Float	njDistanceP2PL(NJS_POINT3 *p, NJS_PLANE *pl, NJS_POINT3 *cp);
Float	njDistanceL2L(NJS_LINE *l1, NJS_LINE *l2, NJS_POINT3 *cp1, NJS_POINT3 *cp2);
Float	njDistanceL2PL(NJS_LINE *l, NJS_PLANE *pl, NJS_POINT3 *cp);
void	njGetPlaneNormal(NJS_POINT3 *p, NJS_VECTOR *v);
void	njGetPlaneNormal2(NJS_POINT3 *p0, NJS_POINT3 *p1, NJS_POINT3 *p2, NJS_VECTOR *v);
Int     njCollisionCheckSS(NJS_SPHERE *sphere1, NJS_SPHERE *sphere2);
Int     njCollisionCheckCC(NJS_CAPSULE *h1, NJS_CAPSULE *h2);
Int     njCollisionCheckSC(NJS_SPHERE *sphere, NJS_CAPSULE *capsule);
Int     njCollisionCheckBS(NJS_BOX *box, NJS_SPHERE *sphere);
Int     njCollisionCheckBC(NJS_BOX *box, NJS_CAPSULE *capsule);
int njCheckPlane4AndLine(NJS_POINT3* pP1, NJS_POINT3* pP2, NJS_POINT3* pP3, NJS_POINT3* pP4, NJS_POINT3* pPN, NJS_LINE* pLine);
int njCollisionCheckBC2(NJS_BOX* pBox, NJS_CAPSULE* pCapsule);
int njCheckPlane4IncludePoint(NJS_POINT3* pP1, NJS_POINT3* pP2, NJS_POINT3* pP3, NJS_POINT3* pP4, NJS_POINT3* pPC);

#endif
