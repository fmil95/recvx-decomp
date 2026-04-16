#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"

/*int njIsParalellL2L(_anon1* pLine1, _anon1* pLine2);
int njIsParalellL2PL(_anon1* pLine, _anon1* pPlane);
float njDistanceP2P(_anon0* pPoint1, _anon0* pPoint2);
float njDistanceP2L(_anon0* pPoint, _anon1* pLine, _anon0* pCross);
float njDistanceP2PL(_anon0* pPoint, _anon1* pPlane, _anon0* pCross);
float njDistanceL2L(_anon1* pLine1, _anon1* pLine2, _anon0* pCross1, _anon0* pCross2);
float njDistanceL2PL(_anon1* pLine, _anon1* pPlane, _anon0* pCross);
void njGetPlaneNormal(_anon0* pPoint, _anon0* pVector);
void njGetPlaneNormal2(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pVector);
int njCollisionCheckSS(_anon4* pSphere1, _anon4* pSphere2);
int njCollisionCheckCC(_anon2* pCap1, _anon2* pCap2);
int njCollisionCheckSC(_anon4* pSphere, _anon2* pCapsule);
int njCollisionCheckBS(_anon3* pBox, _anon4* pSphere);
int njCollisionCheckBC(_anon3* pBox, _anon2* pCapsule);
int njCheckPlane4AndLine(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPN, _anon1* pLine);
int njCollisionCheckBC2(_anon3* pBox, _anon2* pCapsule);
int njCheckPlane4IncludePoint(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPC);*/

// 100% matching!
Bool	njIsParalellL2L(NJS_LINE *l1, NJS_LINE *l2)
{
    float fX1, fY1, fZ1;
    float fX2, fY2, fZ2;
    float fLength;
    
    fX1 = l1->vx;
    fY1 = l1->vy;  
    fZ1 = l1->vz;
    
    fLength = njInvertSqrt((fX1 * fX1) + (fY1 * fY1) + (fZ1 * fZ1));
    
    fX1 *= fLength;
    fY1 *= fLength;
    fZ1 *= fLength;
    
    fX2 = l2->vx;
    fY2 = l2->vy;
    fZ2 = l2->vz;
    
    fLength = njInvertSqrt((fX2 * fX2) + (fY2 * fY2) + (fZ2 * fZ2));
    
    fX2 *= fLength;
    fY2 *= fLength;
    fZ2 *= fLength;
    
    return (0.995f <= fabsf((fX1 * fX2) + (fY1 * fY2) + (fZ1 * fZ2))) ? 1 : 0;
}

// 100% matching!
Bool	njIsParalellL2PL(NJS_LINE *l, NJS_PLANE *pl)
{
    float fLength;
    float fPx, fPy, fPz;
    float fLx, fLy, fLz;
    
    fPx = pl->vx;
    fPy = pl->vy;  
    fPz = pl->vz;
    
    fLength = njInvertSqrt((fPx * fPx) + (fPy * fPy) + (fPz * fPz));
    
    fPx *= fLength;
    fPy *= fLength;
    fPz *= fLength;

    fLx = l->vx;
    fLy = l->vy;  
    fLz = l->vz;

    fLength = njInvertSqrt((fLx * fLx) + (fLy * fLy) + (fLz * fLz));
    
    fLx *= fLength;
    fLy *= fLength;
    fLz *= fLength;

    return (fabsf((fPx * fLx) + (fPy * fLy) + (fPz * fLz)) <= 0.025f) ? 1 : 0;
}

// 100% matching!
Float	njDistanceP2P(NJS_POINT3 *p1, NJS_POINT3 *p2)
{
    float fDeltaX, fDeltaY, fDeltaZ;

    fDeltaX = p2->x - p1->x;
    fDeltaY = p2->y - p1->y;
    fDeltaZ = p2->z - p1->z;

    return njSqrt((fDeltaX * fDeltaX) + (fDeltaY * fDeltaY) + (fDeltaZ * fDeltaZ));
}

// 100% matching! 
Float	njDistanceP2L(NJS_POINT3 *p, NJS_LINE *l, NJS_POINT3 *cp) 
{
    float fLx, fLy, fLz;   
    float fLl;  
    float fDx, fDy, fDz;    
    float fDl;  

    fDx = l->vx;
    fDy = l->vy;
    fDz = l->vz;

    fDl = njInvertSqrt((fDx * fDx) + (fDy * fDy) + (fDz * fDz));
    
    fDx *= fDl;
    fDy *= fDl;
    fDz *= fDl;

    fLx = p->x - l->px;
    fLy = p->y - l->py;
    fLz = p->z - l->pz;

    fLl = (fLx * fLx) + (fLy * fLy) + (fLz * fLz); 

    if (fLl == 0) 
    {
        if (cp != NULL) 
        {
            cp->x = l->px;
            cp->y = l->py;
            cp->z = l->pz;
        }
        
        return 0;
    }

    fDl = (fDx * fLx) + (fDy * fLy) + (fDz * fLz);
    
    if (cp != NULL) 
    {
        cp->x = l->px + (fDx * fDl);
        cp->y = l->py + (fDy * fDl);
        cp->z = l->pz + (fDz * fDl);
    }

    return njSqrt(fLl - (fDl * fDl));
}

// 100% matching!
Float	njDistanceP2PL(NJS_POINT3 *p, NJS_PLANE *pl, NJS_POINT3 *cp) 
{
    float fLength; 
    float fVx, fVy, fVz;     

    fVx = pl->vx;
    fVy = pl->vy;
    fVz = pl->vz;
    
    fLength = njInvertSqrt((fVx * fVx) + (fVy * fVy) + (fVz * fVz));
    
    fVx *= fLength;
    fVy *= fLength; 
    fVz *= fLength;
    
    fLength = (fVx * (p->x - pl->px)) + (fVy * (p->y - pl->py)) + (fVz * (p->z - pl->pz));
    
    if (cp != NULL) 
    {
        cp->x = p->x - (fVx * fLength);
        cp->y = p->y - (fVy * fLength);
        cp->z = p->z - (fVz * fLength);
    }
    
    return fabsf(fLength);
}

// 100% matching!
Float	njDistanceL2L(NJS_LINE *l1, NJS_LINE *l2, NJS_POINT3 *cp1, NJS_POINT3 *cp2)
{
    float fT;   
    float fIV; 
    float fV1x, fV1y, fV1z; 
    float fV2x, fV2y, fV2z; 
    float fNx, fNy, fNz; 
    float fDx, fDy, fDz;
  
    fV1x = l1->vx;
    fV1y = l1->vy;
    fV1z = l1->vz;
    
    fT = njInvertSqrt((fV1x * fV1x) + (fV1y * fV1y) + (fV1z * fV1z));
    
    fV2x = l2->vx;
    fV2y = l2->vy;
    fV2z = l2->vz;
    
    fV1x *= fT;
    fV1y *= fT;
    fV1z *= fT;
    
    fT = njInvertSqrt((fV2x * fV2x) + (fV2y * fV2y) + (fV2z * fV2z)); 
    
    fV2x *= fT;
    fV2y *= fT;
    fV2z *= fT;
    
    fIV = (fV1x * fV2x) + (fV1y * fV2y) + (fV1z * fV2z);
    
    if (0.975f < fabsf(fIV)) 
    {
        if (cp1 != NULL) 
        {
            cp1->x = l1->px;
            cp1->y = l1->py;
            cp1->z = l1->pz;
        }
        
        return njDistanceP2L((NJS_POINT3*)l1, l2, cp2);
    }
    else 
    {
        fDx = l2->px - l1->px;
        fDy = l2->py - l1->py;
        fDz = l2->pz - l1->pz;
        
        if ((cp1 != NULL) || (cp2 != NULL)) 
        {
            fNx = (fDx * fV1x) + (fDy * fV1y) + (fDz * fV1z);
            fNy = (fDx * fV2x) + (fDy * fV2y) + (fDz * fV2z);
            fNz = 1.0f - (fIV * fIV);
            
            if (cp1 != NULL) 
            {
                fT = (fNx - (fIV * fNy)) / fNz;
                
                cp1->x = l1->px + (fV1x * fT);
                cp1->y = l1->py + (fV1y * fT);
                cp1->z = l1->pz + (fV1z * fT);
            }
            
            if (cp2 != NULL) 
            {
                fT = ((fNx * fIV) - fNy) / fNz;
                
                cp2->x = l2->px + (fV2x * fT);
                cp2->y = l2->py + (fV2y * fT);
                cp2->z = l2->pz + (fV2z * fT);
            }
        }
        
        fNx = (fV1y * fV2z) - (fV1z * fV2y);
        fNy = (fV1z * fV2x) - (fV1x * fV2z);
        fNz = (fV1x * fV2y) - (fV1y * fV2x);
        
        fT = fabsf((fNx * fDx) + (fNy * fDy) + (fNz * fDz));
        
        fV1x = njInvertSqrt((fNx * fNx) + (fNy * fNy) + (fNz * fNz));
        
        fIV = fT * fV1x;
        
        if (fIV < 0.158f) 
        {
            fIV = 0;
        }
    }
    
    return fIV;
}

// 100% matching!
Float	njDistanceL2PL(NJS_LINE *l, NJS_PLANE *pl, NJS_POINT3 *cp)
{
    float fA, fB, fC;      
    float fL, fM, fN;    
    float fX, fY, fZ;      
    float fT;      
  
    fA = pl->vx;
    fB = pl->vy;
    fC = pl->vz;

    fT = njInvertSqrt((fA * fA) + (fB * fB) + (fC * fC));

    fA *= fT;
    fB *= fT;
    fC *= fT;

    fL = l->vx;
    fM = l->vy;
    fN = l->vz;

    fT = njInvertSqrt((fL * fL) + (fM * fM) + (fN * fN));

    fL *= fT;
    fM *= fT;
    fN *= fT;

    fT = (fA * fL) + (fB * fM) + (fC * fN);
    
    if (cp != NULL) 
    {
        if (0.025f < fabsf(fT)) 
        {
            fX = l->px;
            fY = l->py;
            fZ = l->pz;
            
            fT = -((fA * (fX - pl->px)) + (fB * (fY - pl->py)) + (fC * (fZ - pl->pz))) / fT;
            
            cp->x = fX + (fL * fT);
            cp->y = fY + (fM * fT);
            cp->z = fZ + (fN * fT);

            return 0;
        }
        else 
        {
            return njDistanceP2PL((NJS_POINT3*)&l->px, pl, cp);
        }
    }
    
    return fT;
}

// 100% matching!
void	njGetPlaneNormal(NJS_POINT3 *p, NJS_VECTOR *v)
{
	NJS_POINT3* pP2, *pP3;

	pP2 = &p[1];
	pP3 = &p[2];

	v->x = ((pP2->y - p->y) * (pP3->z - pP2->z)) - ((pP2->z - p->z) * (pP3->y - pP2->y));
    v->y = ((pP2->z - p->z) * (pP3->x - pP2->x)) - ((pP2->x - p->x) * (pP3->z - pP2->z));
    v->z = ((pP2->x - p->x) * (pP3->y - pP2->y)) - ((pP2->y - p->y) * (pP3->x - pP2->x));
}

// 100% matching!
void	njGetPlaneNormal2(NJS_POINT3 *p0, NJS_POINT3 *p1, NJS_POINT3 *p2, NJS_VECTOR *v)
{
	v->x = ((p1->y - p0->y) * (p2->z - p1->z)) - ((p1->z - p0->z) * (p2->y - p1->y));
    v->y = ((p1->z - p0->z) * (p2->x - p1->x)) - ((p1->x - p0->x) * (p2->z - p1->z));
    v->z = ((p1->x - p0->x) * (p2->y - p1->y)) - ((p1->y - p0->y) * (p2->x - p1->x));
}

// 100% matching!
Int     njCollisionCheckSS(NJS_SPHERE *sphere1, NJS_SPHERE *sphere2)
{
	NJS_POINT3* pCenter1, *pCenter2;
    float fDx, fDy, fDz;
	float fR;

	pCenter1 = &sphere1->c;
	pCenter2 = &sphere2->c;

	fDx = pCenter2->x - pCenter1->x;
	fDy = pCenter2->y - pCenter1->y;
	fDz = pCenter2->z - pCenter1->z;

	fR = sphere1->r + sphere2->r;
	
	if (((fDx * fDx) + (fDy * fDy) + (fDz * fDz)) <= (fR * fR)) 
	{
		return 1;
	}

	return 0;
}

// 100% matching!
Int     njCollisionCheckCC(NJS_CAPSULE *h1, NJS_CAPSULE *h2)
{
    NJS_POINT3* pP12, *pP22;  
    NJS_LINE Line1, Line2;    
    float fLength;   
    NJS_POINT3 Point1, Point2; 
    NJS_SPHERE Sphere; 

    pP12 = &h1->c2;
    pP22 = &h2->c2;
    
    Line1.vx = h1->c2.x - h1->c1.x;
    Line1.vy = h1->c2.y - h1->c1.y;
    Line1.vz = h1->c2.z - h1->c1.z;
    
    Line1.px = h1->c1.x;
    Line1.py = h1->c1.y;
    Line1.pz = h1->c1.z;
    
    Line2.vx = h2->c2.x - h2->c1.x;
    Line2.vy = h2->c2.y - h2->c1.y;
    Line2.vz = h2->c2.z - h2->c1.z;
    
    Line2.px = h2->c1.x;
    Line2.py = h2->c1.y;
    Line2.pz = h2->c1.z;
    
    if (njIsParalellL2L(&Line1, &Line2) != 0) 
    {
        Sphere.r = h1->r;
        
        Sphere.c.x = h1->c1.x;
        Sphere.c.y = h1->c1.y;
        Sphere.c.z = h1->c1.z;
        
        if (njCollisionCheckSC(&Sphere, h2) != 0) 
        {
            return 1;
        }
        
        Sphere.c.x = pP12->x;
        Sphere.c.y = pP12->y;
        Sphere.c.z = pP12->z;
        
        if (njCollisionCheckSC(&Sphere, h2) != 0)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    fLength = h1->r + h2->r;
    
    if (fLength <= njDistanceL2L(&Line1, &Line2, &Point1, &Point2)) 
    {
        return 0;
    }
    
    fLength = njDistanceP2P(&h1->c1, pP12);
    
    if (fLength < njDistanceP2P(&Point1, &h1->c1)) 
    {
        Point1.x = pP12->x;
        Point1.y = pP12->y;
        Point1.z = pP12->z;
    }
    else if (fLength < njDistanceP2P(&Point1, pP12)) 
    {
        Point1.x = h1->c1.x;
        Point1.y = h1->c1.y;
        Point1.z = h1->c1.z;
    }
    
    fLength = njDistanceP2P(&h2->c1, pP22);
    
    if (fLength < njDistanceP2P(&Point2, &h2->c1)) 
    {
        Point2.x = pP22->x;
        Point2.y = pP22->y;
        Point2.z = pP22->z;
    }
    else if (fLength < njDistanceP2P(&Point2, pP22)) 
    {
        Point2.x = h2->c1.x;
        Point2.y = h2->c1.y;
        Point2.z = h2->c1.z;
    }
    
    if (njDistanceP2P(&Point1, &Point2) < (h1->r + h2->r)) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
Int     njCollisionCheckBS(NJS_BOX *box, NJS_SPHERE *sphere)
{
    float fCx, fCy, fCz;          
    float fR;            
    NJS_CAPSULE Capsule; 

    fR = sphere->r;
    
    fCx = sphere->c.x;
    fCy = sphere->c.y;
    fCz = sphere->c.z;
    
    if (((fCx <= (box->v[0].x - fR)) || ((box->v[6].x + fR) <= fCx)) || ((fCy <= (box->v[6].y - fR)) || ((box->v[0].y + fR) <= fCy)) || ((fCz <= (box->v[6].z - fR)) || ((box->v[0].z + fR) <= fCz))) 
    {
        return 0;
    }
    
    if (((box->v[0].x <= fCx) && (fCx <= box->v[6].x)) && ((box->v[6].z <= fCz) && (fCz <= box->v[0].z)))
    {
        return 1;
    }
    
    if (((box->v[6].y <= fCy) && (fCy <= box->v[0].y)) && ((box->v[6].z <= fCz) && (fCz <= box->v[0].z))) 
    {
        return 1;
    }
    
    if (((box->v[0].x <= fCx) && (fCx <= box->v[6].x)) && ((box->v[6].y <= fCy) && (fCy <= box->v[0].y))) 
    {
        return 1;
    }
    
    Capsule.r = 0;
    
    Capsule.c1.x = box->v[0].x;
    Capsule.c1.y = box->v[0].y;
    Capsule.c1.z = box->v[0].z;
    
    Capsule.c2.x = box->v[3].x;
    Capsule.c2.y = box->v[3].y;
    Capsule.c2.z = box->v[3].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[4].x;
    Capsule.c2.y = box->v[4].y;
    Capsule.c2.z = box->v[4].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[1].x;
    Capsule.c2.y = box->v[1].y;
    Capsule.c2.z = box->v[1].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c1.x = box->v[5].x;
    Capsule.c1.y = box->v[5].y;
    Capsule.c1.z = box->v[5].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[4].x;
    Capsule.c2.y = box->v[4].y;
    Capsule.c2.z = box->v[4].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[6].x;
    Capsule.c2.y = box->v[6].y;
    Capsule.c2.z = box->v[6].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c1.x = box->v[2].x;
    Capsule.c1.y = box->v[2].y;
    Capsule.c1.z = box->v[2].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[1].x;
    Capsule.c2.y = box->v[1].y;
    Capsule.c2.z = box->v[1].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0)
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[3].x;
    Capsule.c2.y = box->v[3].y;
    Capsule.c2.z = box->v[3].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c1.x = box->v[7].x;
    Capsule.c1.y = box->v[7].y;
    Capsule.c1.z = box->v[7].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[4].x;
    Capsule.c2.y = box->v[4].y;
    Capsule.c2.z = box->v[4].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[6].x;
    Capsule.c2.y = box->v[6].y;
    Capsule.c2.z = box->v[6].z;
    
    if (njCollisionCheckSC(sphere, &Capsule) != 0) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

// 100% matching!
Int     njCollisionCheckSC(NJS_SPHERE *sphere, NJS_CAPSULE *capsule) 
{
    NJS_POINT3* pP2;  
    NJS_LINE Line;    
    float fLength;    
    NJS_POINT3 Point; 

    pP2 = &capsule->c2;
    
    Line.vx = capsule->c2.x - capsule->c1.x;
    Line.vy = capsule->c2.y - capsule->c1.y;
    Line.vz = capsule->c2.z - capsule->c1.z;
    
    Line.px = capsule->c1.x;
    Line.py = capsule->c1.y;
    Line.pz = capsule->c1.z;
    
    fLength = capsule->r + sphere->r;
    
    if (fLength <= njDistanceP2L(&sphere->c, &Line, &Point)) 
    {
        return 0;
    }
    
    fLength = njDistanceP2P(&capsule->c1, pP2);
    
    if (fLength < njDistanceP2P(&Point, &capsule->c1)) 
    {
        Point.x = pP2->x;
        Point.y = pP2->y;
        Point.z = pP2->z;
    }
    else if (fLength < njDistanceP2P(&Point, pP2))
    {
        Point.x = capsule->c1.x;
        Point.y = capsule->c1.y;
        Point.z = capsule->c1.z;
    }
    
    if (njDistanceP2P(&sphere->c, &Point) < (capsule->r + sphere->r)) 
    {
        return 1;
    }
    
    return 0;
}

/*// 
// Start address: 0x2e3fe0
int njCollisionCheckBS(_anon3* pBox, _anon4* pSphere)
{
	_anon2 Capsule;
	float fR;
	float fCz;
	float fCy;
	float fCx;
	// Line 750, Address: 0x2e3fe0, Func Offset: 0
	// Line 763, Address: 0x2e4004, Func Offset: 0x24
	// Line 760, Address: 0x2e4008, Func Offset: 0x28
	// Line 757, Address: 0x2e400c, Func Offset: 0x2c
	// Line 758, Address: 0x2e4010, Func Offset: 0x30
	// Line 759, Address: 0x2e4014, Func Offset: 0x34
	// Line 763, Address: 0x2e401c, Func Offset: 0x3c
	// Line 770, Address: 0x2e40a8, Func Offset: 0xc8
	// Line 774, Address: 0x2e40b4, Func Offset: 0xd4
	// Line 775, Address: 0x2e40fc, Func Offset: 0x11c
	// Line 776, Address: 0x2e4144, Func Offset: 0x164
	// Line 779, Address: 0x2e418c, Func Offset: 0x1ac
	// Line 781, Address: 0x2e4190, Func Offset: 0x1b0
	// Line 782, Address: 0x2e4194, Func Offset: 0x1b4
	// Line 783, Address: 0x2e4198, Func Offset: 0x1b8
	// Line 784, Address: 0x2e419c, Func Offset: 0x1bc
	// Line 781, Address: 0x2e41a0, Func Offset: 0x1c0
	// Line 782, Address: 0x2e41a4, Func Offset: 0x1c4
	// Line 785, Address: 0x2e41a8, Func Offset: 0x1c8
	// Line 786, Address: 0x2e41ac, Func Offset: 0x1cc
	// Line 787, Address: 0x2e41b0, Func Offset: 0x1d0
	// Line 782, Address: 0x2e41b4, Func Offset: 0x1d4
	// Line 783, Address: 0x2e41b8, Func Offset: 0x1d8
	// Line 787, Address: 0x2e41bc, Func Offset: 0x1dc
	// Line 783, Address: 0x2e41c0, Func Offset: 0x1e0
	// Line 784, Address: 0x2e41c4, Func Offset: 0x1e4
	// Line 785, Address: 0x2e41cc, Func Offset: 0x1ec
	// Line 786, Address: 0x2e41d4, Func Offset: 0x1f4
	// Line 787, Address: 0x2e41d8, Func Offset: 0x1f8
	// Line 788, Address: 0x2e41f0, Func Offset: 0x210
	// Line 791, Address: 0x2e41f4, Func Offset: 0x214
	// Line 788, Address: 0x2e41fc, Func Offset: 0x21c
	// Line 789, Address: 0x2e4200, Func Offset: 0x220
	// Line 790, Address: 0x2e4208, Func Offset: 0x228
	// Line 791, Address: 0x2e420c, Func Offset: 0x22c
	// Line 792, Address: 0x2e4224, Func Offset: 0x244
	// Line 795, Address: 0x2e4228, Func Offset: 0x248
	// Line 792, Address: 0x2e4230, Func Offset: 0x250
	// Line 793, Address: 0x2e4234, Func Offset: 0x254
	// Line 794, Address: 0x2e423c, Func Offset: 0x25c
	// Line 795, Address: 0x2e4240, Func Offset: 0x260
	// Line 796, Address: 0x2e4258, Func Offset: 0x278
	// Line 799, Address: 0x2e425c, Func Offset: 0x27c
	// Line 796, Address: 0x2e4264, Func Offset: 0x284
	// Line 797, Address: 0x2e4268, Func Offset: 0x288
	// Line 798, Address: 0x2e4270, Func Offset: 0x290
	// Line 799, Address: 0x2e4274, Func Offset: 0x294
	// Line 800, Address: 0x2e428c, Func Offset: 0x2ac
	// Line 803, Address: 0x2e4290, Func Offset: 0x2b0
	// Line 800, Address: 0x2e4298, Func Offset: 0x2b8
	// Line 801, Address: 0x2e429c, Func Offset: 0x2bc
	// Line 802, Address: 0x2e42a4, Func Offset: 0x2c4
	// Line 803, Address: 0x2e42a8, Func Offset: 0x2c8
	// Line 804, Address: 0x2e42c0, Func Offset: 0x2e0
	// Line 807, Address: 0x2e42c4, Func Offset: 0x2e4
	// Line 804, Address: 0x2e42cc, Func Offset: 0x2ec
	// Line 805, Address: 0x2e42d0, Func Offset: 0x2f0
	// Line 806, Address: 0x2e42d8, Func Offset: 0x2f8
	// Line 807, Address: 0x2e42dc, Func Offset: 0x2fc
	// Line 808, Address: 0x2e42f4, Func Offset: 0x314
	// Line 811, Address: 0x2e42f8, Func Offset: 0x318
	// Line 808, Address: 0x2e4300, Func Offset: 0x320
	// Line 809, Address: 0x2e4304, Func Offset: 0x324
	// Line 810, Address: 0x2e430c, Func Offset: 0x32c
	// Line 811, Address: 0x2e4310, Func Offset: 0x330
	// Line 812, Address: 0x2e4328, Func Offset: 0x348
	// Line 815, Address: 0x2e432c, Func Offset: 0x34c
	// Line 812, Address: 0x2e4334, Func Offset: 0x354
	// Line 813, Address: 0x2e4338, Func Offset: 0x358
	// Line 814, Address: 0x2e4340, Func Offset: 0x360
	// Line 815, Address: 0x2e4344, Func Offset: 0x364
	// Line 816, Address: 0x2e435c, Func Offset: 0x37c
	// Line 819, Address: 0x2e4360, Func Offset: 0x380
	// Line 816, Address: 0x2e4368, Func Offset: 0x388
	// Line 817, Address: 0x2e436c, Func Offset: 0x38c
	// Line 818, Address: 0x2e4374, Func Offset: 0x394
	// Line 819, Address: 0x2e4378, Func Offset: 0x398
	// Line 820, Address: 0x2e4390, Func Offset: 0x3b0
	// Line 823, Address: 0x2e4394, Func Offset: 0x3b4
	// Line 820, Address: 0x2e439c, Func Offset: 0x3bc
	// Line 821, Address: 0x2e43a0, Func Offset: 0x3c0
	// Line 822, Address: 0x2e43a8, Func Offset: 0x3c8
	// Line 823, Address: 0x2e43ac, Func Offset: 0x3cc
	// Line 824, Address: 0x2e43c4, Func Offset: 0x3e4
	// Line 827, Address: 0x2e43c8, Func Offset: 0x3e8
	// Line 824, Address: 0x2e43d0, Func Offset: 0x3f0
	// Line 825, Address: 0x2e43d4, Func Offset: 0x3f4
	// Line 826, Address: 0x2e43dc, Func Offset: 0x3fc
	// Line 827, Address: 0x2e43e0, Func Offset: 0x400
	// Line 828, Address: 0x2e43f8, Func Offset: 0x418
	// Line 831, Address: 0x2e43fc, Func Offset: 0x41c
	// Line 828, Address: 0x2e4404, Func Offset: 0x424
	// Line 829, Address: 0x2e4408, Func Offset: 0x428
	// Line 830, Address: 0x2e4410, Func Offset: 0x430
	// Line 831, Address: 0x2e4414, Func Offset: 0x434
	// Line 834, Address: 0x2e4428, Func Offset: 0x448
	// Func End, Address: 0x2e4450, Func Offset: 0x470
}*/

// 100% matching!
Int     njCollisionCheckBC(NJS_BOX *box, NJS_CAPSULE *capsule)
{
    NJS_CAPSULE Capsule;            
    NJS_LINE Line;             
    float fX1, fY1, fZ1;                    
    float fX2, fY2, fZ2;                          
    float fR;                       
    float fMinX, fMaxX;                      
    float fMinY, fMaxY;                   
    float fMinZ, fMaxZ;                       
    unsigned int ulCnt;                 
    static unsigned int ulVertex[6][4] = 
    {
        { 0, 1, 2, 3 },
        { 4, 7, 6, 5 },
        { 0, 3, 7, 4 },
        { 2, 1, 5, 6 },
        { 1, 0, 4, 5 },
        { 3, 2, 6, 7 }
    };
    static NJS_POINT3 Normal[6] = 
    {
        {  0,     1.0f,     0 },
        {  0,    -1.0f,     0 },
        {  0,        0,  1.0f },
        {  0,        0, -1.0f },
        { -1.0f,     0,     0 },
        {  1.0f,        0,  0 }
    };    

    fX1 = capsule->c1.x;
    fX2 = capsule->c2.x;
    fY1 = capsule->c1.y;
    fZ1 = capsule->c1.z;
    fY2 = capsule->c2.y;
    fZ2 = capsule->c2.z;
    
    fR = capsule->r; 
    
    if (fX1 < fX2) 
    {
        fMinX = fX1 - fR;
        fMaxX = fX2 + fR;
    }
    else
    {
        fMinX = fX2 - fR;
        fMaxX = fX1 + fR;
    }
    
    if (fY1 < fY2) 
    {
        fMinY = fY1 - fR;
        fMaxY = fY2 + fR;
    }
    else 
    {
        fMinY = fY2 - fR;
        fMaxY = fY1 + fR;
    }
    
    if (fZ1 < fZ2) 
    {
        fMinZ = fZ1 - fR;
        fMaxZ = fZ2 + fR;
    }
    else
    {
        fMinZ = fZ2 - fR;
        fMaxZ = fZ1 + fR;
    }
    
    if (((fMaxX <= box->v[0].x) || (box->v[6].x <= fMinX)) || ((fMaxY <= box->v[6].y) || (box->v[0].y <= fMinY)) || ((fMaxZ <= box->v[6].z) || (box->v[0].z <= fMinZ))) 
    {
        return 0;
    }
    
    if (((((box->v[0].x - fR) < fX1) && (fX1 < (box->v[6].x + fR))) && ((box->v[6].y <= fY1) && (fY1 <= box->v[0].y)) && ((box->v[6].z <= fZ1) && (fZ1 <= box->v[0].z))) || (((box->v[0].x <= fX1) && (fX1 <= box->v[6].x)) && (((box->v[6].y - fR) < fY1) && (fY1 < (box->v[0].y + fR))) && ((box->v[6].z <= fZ1) && (fZ1 <= box->v[0].z))) || (((box->v[0].x <= fX1) && (fX1 <= box->v[6].x)) && ((box->v[6].y <= fY1) && (fY1 <= box->v[0].y)) && (((box->v[6].z - fR) < fZ1) && (fZ1 < (box->v[0].z + fR))))) 
    {
        return 1;
    }
    
    if (((((box->v[0].x - fR) < fX2) && (fX2 < (box->v[6].x + fR))) && ((box->v[6].y <= fY2) && (fY2 <= box->v[0].y)) && ((box->v[6].z <= fZ2) && (fZ2 <= box->v[0].z))) || (((box->v[0].x <= fX2) && (fX2 <= box->v[6].x)) && (((box->v[6].y - fR) < fY2) && (fY2 < (box->v[0].y + fR))) && ((box->v[6].z <= fZ2) && (fZ2 <= box->v[0].z))) || (((box->v[0].x <= fX2) && (fX2 <= box->v[6].x)) && ((box->v[6].y <= fY2) && (fY2 <= box->v[0].y)) && (((box->v[6].z - fR) < fZ2) && (fZ2 < (box->v[0].z + fR))))) 
    {
        return 1;
    }
    
    Capsule.r = 0;
    
    Capsule.c1.x = box->v[0].x;
    Capsule.c1.y = box->v[0].y;
    Capsule.c1.z = box->v[0].z;
    
    Capsule.c2.x = box->v[3].x;
    Capsule.c2.y = box->v[3].y;
    Capsule.c2.z = box->v[3].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[4].x;
    Capsule.c2.y = box->v[4].y;
    Capsule.c2.z = box->v[4].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[1].x;
    Capsule.c2.y = box->v[1].y;
    Capsule.c2.z = box->v[1].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c1.x = box->v[5].x;
    Capsule.c1.y = box->v[5].y;
    Capsule.c1.z = box->v[5].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[4].x;
    Capsule.c2.y = box->v[4].y;
    Capsule.c2.z = box->v[4].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[6].x;
    Capsule.c2.y = box->v[6].y;
    Capsule.c2.z = box->v[6].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c1.x = box->v[2].x;
    Capsule.c1.y = box->v[2].y;
    Capsule.c1.z = box->v[2].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0)
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[1].x;
    Capsule.c2.y = box->v[1].y;
    Capsule.c2.z = box->v[1].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[3].x;
    Capsule.c2.y = box->v[3].y;
    Capsule.c2.z = box->v[3].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c1.x = box->v[7].x;
    Capsule.c1.y = box->v[7].y;
    Capsule.c1.z = box->v[7].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[4].x;
    Capsule.c2.y = box->v[4].y;
    Capsule.c2.z = box->v[4].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Capsule.c2.x = box->v[6].x;
    Capsule.c2.y = box->v[6].y;
    Capsule.c2.z = box->v[6].z;
    
    if (njCollisionCheckCC(capsule, &Capsule) != 0) 
    {
        return 1;
    }
    
    Line.px = fX1;
    Line.py = fY1;
    Line.pz = fZ1;
    
    Line.vx = fX2 - fX1;
    Line.vy = fY2 - fY1;
    Line.vz = fZ2 - fZ1;
    
    for (ulCnt = 0; ulCnt < 6; ulCnt++) 
    { 
        if (njCheckPlane4AndLine(&box->v[ulVertex[ulCnt][0]], &box->v[ulVertex[ulCnt][1]], &box->v[ulVertex[ulCnt][2]], &box->v[ulVertex[ulCnt][3]], &Normal[ulCnt], &Line) != 0) 
        {
            return 1;
        }
    }
    
    return 0;
}

/*// 
// Start address: 0x2e4bc0
int njCheckPlane4AndLine(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPN, _anon1* pLine)
{
	float fT4;
	float fT3;
	float fT2;
	float fT1;
	float fVZ4;
	float fVY4;
	float fVX4;
	float fVZ3;
	float fVY3;
	float fVX3;
	float fVZ2;
	float fVY2;
	float fVX2;
	float fVZ1;
	float fVY1;
	float fVX1;
	// Line 1051, Address: 0x2e4bc0, Func Offset: 0
	// Line 1065, Address: 0x2e4c0c, Func Offset: 0x4c
	// Line 1066, Address: 0x2e4c10, Func Offset: 0x50
	// Line 1067, Address: 0x2e4c14, Func Offset: 0x54
	// Line 1059, Address: 0x2e4c18, Func Offset: 0x58
	// Line 1060, Address: 0x2e4c1c, Func Offset: 0x5c
	// Line 1061, Address: 0x2e4c20, Func Offset: 0x60
	// Line 1068, Address: 0x2e4c24, Func Offset: 0x64
	// Line 1062, Address: 0x2e4c28, Func Offset: 0x68
	// Line 1063, Address: 0x2e4c2c, Func Offset: 0x6c
	// Line 1064, Address: 0x2e4c30, Func Offset: 0x70
	// Line 1068, Address: 0x2e4c38, Func Offset: 0x78
	// Line 1069, Address: 0x2e4c54, Func Offset: 0x94
	// Line 1071, Address: 0x2e4c68, Func Offset: 0xa8
	// Line 1074, Address: 0x2e4c78, Func Offset: 0xb8
	// Line 1076, Address: 0x2e4ca0, Func Offset: 0xe0
	// Line 1080, Address: 0x2e4ca8, Func Offset: 0xe8
	// Line 1083, Address: 0x2e4cd8, Func Offset: 0x118
	// Line 1084, Address: 0x2e4ce0, Func Offset: 0x120
	// Line 1085, Address: 0x2e4ce4, Func Offset: 0x124
	// Line 1084, Address: 0x2e4ce8, Func Offset: 0x128
	// Line 1085, Address: 0x2e4cec, Func Offset: 0x12c
	// Line 1088, Address: 0x2e4cf0, Func Offset: 0x130
	// Line 1089, Address: 0x2e4cf4, Func Offset: 0x134
	// Line 1092, Address: 0x2e4cf8, Func Offset: 0x138
	// Line 1090, Address: 0x2e4d00, Func Offset: 0x140
	// Line 1092, Address: 0x2e4d04, Func Offset: 0x144
	// Line 1093, Address: 0x2e4d24, Func Offset: 0x164
	// Line 1094, Address: 0x2e4d28, Func Offset: 0x168
	// Line 1095, Address: 0x2e4d2c, Func Offset: 0x16c
	// Line 1093, Address: 0x2e4d30, Func Offset: 0x170
	// Line 1094, Address: 0x2e4d34, Func Offset: 0x174
	// Line 1097, Address: 0x2e4d38, Func Offset: 0x178
	// Line 1095, Address: 0x2e4d40, Func Offset: 0x180
	// Line 1097, Address: 0x2e4d44, Func Offset: 0x184
	// Line 1101, Address: 0x2e4d64, Func Offset: 0x1a4
	// Line 1104, Address: 0x2e4d68, Func Offset: 0x1a8
	// Line 1100, Address: 0x2e4d70, Func Offset: 0x1b0
	// Line 1102, Address: 0x2e4d74, Func Offset: 0x1b4
	// Line 1103, Address: 0x2e4d78, Func Offset: 0x1b8
	// Line 1104, Address: 0x2e4d84, Func Offset: 0x1c4
	// Line 1103, Address: 0x2e4d88, Func Offset: 0x1c8
	// Line 1104, Address: 0x2e4d8c, Func Offset: 0x1cc
	// Line 1105, Address: 0x2e4da4, Func Offset: 0x1e4
	// Line 1108, Address: 0x2e4dac, Func Offset: 0x1ec
	// Line 1109, Address: 0x2e4db0, Func Offset: 0x1f0
	// Line 1110, Address: 0x2e4db4, Func Offset: 0x1f4
	// Line 1112, Address: 0x2e4db8, Func Offset: 0x1f8
	// Line 1105, Address: 0x2e4dc0, Func Offset: 0x200
	// Line 1109, Address: 0x2e4dcc, Func Offset: 0x20c
	// Line 1108, Address: 0x2e4dd0, Func Offset: 0x210
	// Line 1110, Address: 0x2e4dd4, Func Offset: 0x214
	// Line 1111, Address: 0x2e4dd8, Func Offset: 0x218
	// Line 1112, Address: 0x2e4de4, Func Offset: 0x224
	// Line 1111, Address: 0x2e4de8, Func Offset: 0x228
	// Line 1112, Address: 0x2e4dec, Func Offset: 0x22c
	// Line 1113, Address: 0x2e4e04, Func Offset: 0x244
	// Line 1116, Address: 0x2e4e0c, Func Offset: 0x24c
	// Line 1117, Address: 0x2e4e10, Func Offset: 0x250
	// Line 1118, Address: 0x2e4e14, Func Offset: 0x254
	// Line 1120, Address: 0x2e4e18, Func Offset: 0x258
	// Line 1113, Address: 0x2e4e20, Func Offset: 0x260
	// Line 1117, Address: 0x2e4e2c, Func Offset: 0x26c
	// Line 1116, Address: 0x2e4e30, Func Offset: 0x270
	// Line 1118, Address: 0x2e4e34, Func Offset: 0x274
	// Line 1119, Address: 0x2e4e38, Func Offset: 0x278
	// Line 1120, Address: 0x2e4e44, Func Offset: 0x284
	// Line 1119, Address: 0x2e4e48, Func Offset: 0x288
	// Line 1120, Address: 0x2e4e4c, Func Offset: 0x28c
	// Line 1121, Address: 0x2e4e64, Func Offset: 0x2a4
	// Line 1124, Address: 0x2e4e6c, Func Offset: 0x2ac
	// Line 1125, Address: 0x2e4e70, Func Offset: 0x2b0
	// Line 1126, Address: 0x2e4e74, Func Offset: 0x2b4
	// Line 1128, Address: 0x2e4e78, Func Offset: 0x2b8
	// Line 1121, Address: 0x2e4e80, Func Offset: 0x2c0
	// Line 1125, Address: 0x2e4e8c, Func Offset: 0x2cc
	// Line 1124, Address: 0x2e4e90, Func Offset: 0x2d0
	// Line 1126, Address: 0x2e4e94, Func Offset: 0x2d4
	// Line 1127, Address: 0x2e4e98, Func Offset: 0x2d8
	// Line 1128, Address: 0x2e4ea4, Func Offset: 0x2e4
	// Line 1127, Address: 0x2e4ea8, Func Offset: 0x2e8
	// Line 1128, Address: 0x2e4eac, Func Offset: 0x2ec
	// Line 1129, Address: 0x2e4ec4, Func Offset: 0x304
	// Line 1133, Address: 0x2e4ed0, Func Offset: 0x310
	// Line 1129, Address: 0x2e4ed4, Func Offset: 0x314
	// Line 1132, Address: 0x2e4edc, Func Offset: 0x31c
	// Line 1133, Address: 0x2e4ee8, Func Offset: 0x328
	// Line 1132, Address: 0x2e4eec, Func Offset: 0x32c
	// Line 1133, Address: 0x2e4ef0, Func Offset: 0x330
	// Line 1134, Address: 0x2e4f28, Func Offset: 0x368
	// Line 1135, Address: 0x2e4f38, Func Offset: 0x378
	// Line 1136, Address: 0x2e4f64, Func Offset: 0x3a4
	// Line 1137, Address: 0x2e4f74, Func Offset: 0x3b4
	// Line 1138, Address: 0x2e4fa0, Func Offset: 0x3e0
	// Line 1139, Address: 0x2e4fb0, Func Offset: 0x3f0
	// Line 1144, Address: 0x2e4fdc, Func Offset: 0x41c
	// Line 1151, Address: 0x2e5034, Func Offset: 0x474
	// Func End, Address: 0x2e5084, Func Offset: 0x4c4
}

// 
// Start address: 0x2e5090
int njCollisionCheckBC2(_anon3* pBox, _anon2* pCapsule)
{
	unsigned int ulCnt;
	float fR;
	float fZ2;
	float fY2;
	float fX2;
	float fZ1;
	float fY1;
	float fX1;
	_anon0 Cross;
	_anon1 Plane;
	_anon1 Line;
	_anon2 Capsule;
	unsigned int ulVertex[4][6];
	_anon0 Normal[6];
	// Line 1172, Address: 0x2e5090, Func Offset: 0
	// Line 1199, Address: 0x2e50d0, Func Offset: 0x40
	// Line 1200, Address: 0x2e50d4, Func Offset: 0x44
	// Line 1201, Address: 0x2e50d8, Func Offset: 0x48
	// Line 1202, Address: 0x2e50dc, Func Offset: 0x4c
	// Line 1203, Address: 0x2e50e0, Func Offset: 0x50
	// Line 1204, Address: 0x2e50e4, Func Offset: 0x54
	// Line 1205, Address: 0x2e50e8, Func Offset: 0x58
	// Line 1213, Address: 0x2e50f0, Func Offset: 0x60
	// Line 1214, Address: 0x2e50f4, Func Offset: 0x64
	// Line 1211, Address: 0x2e50f8, Func Offset: 0x68
	// Line 1212, Address: 0x2e50fc, Func Offset: 0x6c
	// Line 1215, Address: 0x2e5100, Func Offset: 0x70
	// Line 1216, Address: 0x2e5104, Func Offset: 0x74
	// Line 1217, Address: 0x2e5108, Func Offset: 0x78
	// Line 1212, Address: 0x2e510c, Func Offset: 0x7c
	// Line 1213, Address: 0x2e5110, Func Offset: 0x80
	// Line 1218, Address: 0x2e5118, Func Offset: 0x88
	// Line 1213, Address: 0x2e511c, Func Offset: 0x8c
	// Line 1214, Address: 0x2e5120, Func Offset: 0x90
	// Line 1215, Address: 0x2e5128, Func Offset: 0x98
	// Line 1216, Address: 0x2e5130, Func Offset: 0xa0
	// Line 1217, Address: 0x2e5138, Func Offset: 0xa8
	// Line 1218, Address: 0x2e5140, Func Offset: 0xb0
	// Line 1219, Address: 0x2e5158, Func Offset: 0xc8
	// Line 1222, Address: 0x2e515c, Func Offset: 0xcc
	// Line 1219, Address: 0x2e5164, Func Offset: 0xd4
	// Line 1220, Address: 0x2e5168, Func Offset: 0xd8
	// Line 1221, Address: 0x2e5170, Func Offset: 0xe0
	// Line 1222, Address: 0x2e5174, Func Offset: 0xe4
	// Line 1223, Address: 0x2e518c, Func Offset: 0xfc
	// Line 1226, Address: 0x2e5190, Func Offset: 0x100
	// Line 1223, Address: 0x2e5198, Func Offset: 0x108
	// Line 1224, Address: 0x2e519c, Func Offset: 0x10c
	// Line 1225, Address: 0x2e51a4, Func Offset: 0x114
	// Line 1226, Address: 0x2e51a8, Func Offset: 0x118
	// Line 1227, Address: 0x2e51c0, Func Offset: 0x130
	// Line 1230, Address: 0x2e51c4, Func Offset: 0x134
	// Line 1227, Address: 0x2e51cc, Func Offset: 0x13c
	// Line 1228, Address: 0x2e51d0, Func Offset: 0x140
	// Line 1229, Address: 0x2e51d8, Func Offset: 0x148
	// Line 1230, Address: 0x2e51dc, Func Offset: 0x14c
	// Line 1231, Address: 0x2e51f4, Func Offset: 0x164
	// Line 1234, Address: 0x2e51f8, Func Offset: 0x168
	// Line 1231, Address: 0x2e5200, Func Offset: 0x170
	// Line 1232, Address: 0x2e5204, Func Offset: 0x174
	// Line 1233, Address: 0x2e520c, Func Offset: 0x17c
	// Line 1234, Address: 0x2e5210, Func Offset: 0x180
	// Line 1235, Address: 0x2e5228, Func Offset: 0x198
	// Line 1238, Address: 0x2e522c, Func Offset: 0x19c
	// Line 1235, Address: 0x2e5234, Func Offset: 0x1a4
	// Line 1236, Address: 0x2e5238, Func Offset: 0x1a8
	// Line 1237, Address: 0x2e5240, Func Offset: 0x1b0
	// Line 1238, Address: 0x2e5244, Func Offset: 0x1b4
	// Line 1239, Address: 0x2e525c, Func Offset: 0x1cc
	// Line 1242, Address: 0x2e5260, Func Offset: 0x1d0
	// Line 1239, Address: 0x2e5268, Func Offset: 0x1d8
	// Line 1240, Address: 0x2e526c, Func Offset: 0x1dc
	// Line 1241, Address: 0x2e5274, Func Offset: 0x1e4
	// Line 1242, Address: 0x2e5278, Func Offset: 0x1e8
	// Line 1243, Address: 0x2e5290, Func Offset: 0x200
	// Line 1246, Address: 0x2e5294, Func Offset: 0x204
	// Line 1243, Address: 0x2e529c, Func Offset: 0x20c
	// Line 1244, Address: 0x2e52a0, Func Offset: 0x210
	// Line 1245, Address: 0x2e52a8, Func Offset: 0x218
	// Line 1246, Address: 0x2e52ac, Func Offset: 0x21c
	// Line 1247, Address: 0x2e52c4, Func Offset: 0x234
	// Line 1250, Address: 0x2e52c8, Func Offset: 0x238
	// Line 1247, Address: 0x2e52d0, Func Offset: 0x240
	// Line 1248, Address: 0x2e52d4, Func Offset: 0x244
	// Line 1249, Address: 0x2e52dc, Func Offset: 0x24c
	// Line 1250, Address: 0x2e52e0, Func Offset: 0x250
	// Line 1251, Address: 0x2e52f8, Func Offset: 0x268
	// Line 1254, Address: 0x2e52fc, Func Offset: 0x26c
	// Line 1251, Address: 0x2e5304, Func Offset: 0x274
	// Line 1252, Address: 0x2e5308, Func Offset: 0x278
	// Line 1253, Address: 0x2e5310, Func Offset: 0x280
	// Line 1254, Address: 0x2e5314, Func Offset: 0x284
	// Line 1255, Address: 0x2e532c, Func Offset: 0x29c
	// Line 1258, Address: 0x2e5330, Func Offset: 0x2a0
	// Line 1255, Address: 0x2e5338, Func Offset: 0x2a8
	// Line 1256, Address: 0x2e533c, Func Offset: 0x2ac
	// Line 1257, Address: 0x2e5344, Func Offset: 0x2b4
	// Line 1258, Address: 0x2e5348, Func Offset: 0x2b8
	// Line 1259, Address: 0x2e5360, Func Offset: 0x2d0
	// Line 1262, Address: 0x2e5364, Func Offset: 0x2d4
	// Line 1259, Address: 0x2e536c, Func Offset: 0x2dc
	// Line 1260, Address: 0x2e5370, Func Offset: 0x2e0
	// Line 1261, Address: 0x2e5378, Func Offset: 0x2e8
	// Line 1262, Address: 0x2e537c, Func Offset: 0x2ec
	// Line 1266, Address: 0x2e5394, Func Offset: 0x304
	// Line 1267, Address: 0x2e53a0, Func Offset: 0x310
	// Line 1266, Address: 0x2e53a4, Func Offset: 0x314
	// Line 1267, Address: 0x2e53ac, Func Offset: 0x31c
	// Line 1266, Address: 0x2e53b8, Func Offset: 0x328
	// Line 1268, Address: 0x2e53c0, Func Offset: 0x330
	// Line 1266, Address: 0x2e53cc, Func Offset: 0x33c
	// Line 1267, Address: 0x2e53d0, Func Offset: 0x340
	// Line 1268, Address: 0x2e53ec, Func Offset: 0x35c
	// Line 1270, Address: 0x2e5404, Func Offset: 0x374
	// Line 1272, Address: 0x2e542c, Func Offset: 0x39c
	// Line 1273, Address: 0x2e5430, Func Offset: 0x3a0
	// Line 1274, Address: 0x2e5434, Func Offset: 0x3a4
	// Line 1272, Address: 0x2e543c, Func Offset: 0x3ac
	// Line 1274, Address: 0x2e5444, Func Offset: 0x3b4
	// Line 1272, Address: 0x2e5448, Func Offset: 0x3b8
	// Line 1273, Address: 0x2e5454, Func Offset: 0x3c4
	// Line 1274, Address: 0x2e5470, Func Offset: 0x3e0
	// Line 1276, Address: 0x2e5488, Func Offset: 0x3f8
	// Line 1278, Address: 0x2e54b0, Func Offset: 0x420
	// Line 1279, Address: 0x2e54b4, Func Offset: 0x424
	// Line 1280, Address: 0x2e54b8, Func Offset: 0x428
	// Line 1278, Address: 0x2e54c0, Func Offset: 0x430
	// Line 1280, Address: 0x2e54c8, Func Offset: 0x438
	// Line 1278, Address: 0x2e54cc, Func Offset: 0x43c
	// Line 1279, Address: 0x2e54d8, Func Offset: 0x448
	// Line 1280, Address: 0x2e54f4, Func Offset: 0x464
	// Line 1282, Address: 0x2e550c, Func Offset: 0x47c
	// Line 1284, Address: 0x2e5534, Func Offset: 0x4a4
	// Line 1285, Address: 0x2e5538, Func Offset: 0x4a8
	// Line 1286, Address: 0x2e553c, Func Offset: 0x4ac
	// Line 1284, Address: 0x2e5544, Func Offset: 0x4b4
	// Line 1286, Address: 0x2e554c, Func Offset: 0x4bc
	// Line 1284, Address: 0x2e5550, Func Offset: 0x4c0
	// Line 1285, Address: 0x2e555c, Func Offset: 0x4cc
	// Line 1286, Address: 0x2e5578, Func Offset: 0x4e8
	// Line 1288, Address: 0x2e5590, Func Offset: 0x500
	// Line 1290, Address: 0x2e55b8, Func Offset: 0x528
	// Line 1291, Address: 0x2e55bc, Func Offset: 0x52c
	// Line 1292, Address: 0x2e55c0, Func Offset: 0x530
	// Line 1290, Address: 0x2e55c8, Func Offset: 0x538
	// Line 1292, Address: 0x2e55d0, Func Offset: 0x540
	// Line 1290, Address: 0x2e55d4, Func Offset: 0x544
	// Line 1291, Address: 0x2e55e0, Func Offset: 0x550
	// Line 1292, Address: 0x2e55fc, Func Offset: 0x56c
	// Line 1294, Address: 0x2e5614, Func Offset: 0x584
	// Line 1296, Address: 0x2e563c, Func Offset: 0x5ac
	// Line 1297, Address: 0x2e5640, Func Offset: 0x5b0
	// Line 1298, Address: 0x2e5644, Func Offset: 0x5b4
	// Line 1296, Address: 0x2e564c, Func Offset: 0x5bc
	// Line 1298, Address: 0x2e5654, Func Offset: 0x5c4
	// Line 1296, Address: 0x2e5658, Func Offset: 0x5c8
	// Line 1297, Address: 0x2e5664, Func Offset: 0x5d4
	// Line 1298, Address: 0x2e5680, Func Offset: 0x5f0
	// Line 1300, Address: 0x2e5698, Func Offset: 0x608
	// Line 1304, Address: 0x2e56c0, Func Offset: 0x630
	// Line 1305, Address: 0x2e56c4, Func Offset: 0x634
	// Line 1306, Address: 0x2e56c8, Func Offset: 0x638
	// Line 1304, Address: 0x2e56d0, Func Offset: 0x640
	// Line 1306, Address: 0x2e56d8, Func Offset: 0x648
	// Line 1304, Address: 0x2e56dc, Func Offset: 0x64c
	// Line 1305, Address: 0x2e56e8, Func Offset: 0x658
	// Line 1306, Address: 0x2e5704, Func Offset: 0x674
	// Line 1308, Address: 0x2e571c, Func Offset: 0x68c
	// Line 1310, Address: 0x2e5744, Func Offset: 0x6b4
	// Line 1311, Address: 0x2e5748, Func Offset: 0x6b8
	// Line 1312, Address: 0x2e574c, Func Offset: 0x6bc
	// Line 1310, Address: 0x2e5754, Func Offset: 0x6c4
	// Line 1312, Address: 0x2e575c, Func Offset: 0x6cc
	// Line 1310, Address: 0x2e5760, Func Offset: 0x6d0
	// Line 1311, Address: 0x2e576c, Func Offset: 0x6dc
	// Line 1312, Address: 0x2e5788, Func Offset: 0x6f8
	// Line 1314, Address: 0x2e57a0, Func Offset: 0x710
	// Line 1316, Address: 0x2e57c8, Func Offset: 0x738
	// Line 1317, Address: 0x2e57cc, Func Offset: 0x73c
	// Line 1318, Address: 0x2e57d0, Func Offset: 0x740
	// Line 1316, Address: 0x2e57d8, Func Offset: 0x748
	// Line 1318, Address: 0x2e57e0, Func Offset: 0x750
	// Line 1316, Address: 0x2e57e4, Func Offset: 0x754
	// Line 1317, Address: 0x2e57f0, Func Offset: 0x760
	// Line 1318, Address: 0x2e580c, Func Offset: 0x77c
	// Line 1320, Address: 0x2e5824, Func Offset: 0x794
	// Line 1322, Address: 0x2e584c, Func Offset: 0x7bc
	// Line 1323, Address: 0x2e5850, Func Offset: 0x7c0
	// Line 1324, Address: 0x2e5854, Func Offset: 0x7c4
	// Line 1322, Address: 0x2e585c, Func Offset: 0x7cc
	// Line 1324, Address: 0x2e5864, Func Offset: 0x7d4
	// Line 1322, Address: 0x2e5868, Func Offset: 0x7d8
	// Line 1323, Address: 0x2e5874, Func Offset: 0x7e4
	// Line 1324, Address: 0x2e5890, Func Offset: 0x800
	// Line 1326, Address: 0x2e58a8, Func Offset: 0x818
	// Line 1328, Address: 0x2e58d0, Func Offset: 0x840
	// Line 1329, Address: 0x2e58d4, Func Offset: 0x844
	// Line 1330, Address: 0x2e58d8, Func Offset: 0x848
	// Line 1328, Address: 0x2e58e0, Func Offset: 0x850
	// Line 1330, Address: 0x2e58e8, Func Offset: 0x858
	// Line 1328, Address: 0x2e58ec, Func Offset: 0x85c
	// Line 1329, Address: 0x2e58f8, Func Offset: 0x868
	// Line 1330, Address: 0x2e5914, Func Offset: 0x884
	// Line 1332, Address: 0x2e592c, Func Offset: 0x89c
	// Line 1334, Address: 0x2e5954, Func Offset: 0x8c4
	// Line 1335, Address: 0x2e5958, Func Offset: 0x8c8
	// Line 1336, Address: 0x2e595c, Func Offset: 0x8cc
	// Line 1334, Address: 0x2e5964, Func Offset: 0x8d4
	// Line 1336, Address: 0x2e596c, Func Offset: 0x8dc
	// Line 1334, Address: 0x2e5970, Func Offset: 0x8e0
	// Line 1335, Address: 0x2e597c, Func Offset: 0x8ec
	// Line 1336, Address: 0x2e5998, Func Offset: 0x908
	// Line 1338, Address: 0x2e59b0, Func Offset: 0x920
	// Line 1347, Address: 0x2e59d8, Func Offset: 0x948
	// Line 1344, Address: 0x2e59dc, Func Offset: 0x94c
	// Line 1345, Address: 0x2e59e0, Func Offset: 0x950
	// Line 1346, Address: 0x2e59e4, Func Offset: 0x954
	// Line 1347, Address: 0x2e59e8, Func Offset: 0x958
	// Line 1348, Address: 0x2e59ec, Func Offset: 0x95c
	// Line 1349, Address: 0x2e59fc, Func Offset: 0x96c
	// Line 1350, Address: 0x2e5a08, Func Offset: 0x978
	// Line 1349, Address: 0x2e5a0c, Func Offset: 0x97c
	// Line 1353, Address: 0x2e5a10, Func Offset: 0x980
	// Line 1355, Address: 0x2e5a74, Func Offset: 0x9e4
	// Line 1357, Address: 0x2e5a7c, Func Offset: 0x9ec
	// Line 1355, Address: 0x2e5a80, Func Offset: 0x9f0
	// Line 1357, Address: 0x2e5a84, Func Offset: 0x9f4
	// Line 1360, Address: 0x2e5a90, Func Offset: 0xa00
	// Line 1361, Address: 0x2e5a94, Func Offset: 0xa04
	// Func End, Address: 0x2e5ad8, Func Offset: 0xa48
}

// 
// Start address: 0x2e5ae0
int njCheckPlane4IncludePoint(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPC)
{
	float fT4;
	float fT3;
	float fT2;
	float fT1;
	float fVZ4;
	float fVY4;
	float fVX4;
	float fVZ3;
	float fVY3;
	float fVX3;
	float fVZ2;
	float fVY2;
	float fVX2;
	float fVZ1;
	float fVY1;
	float fVX1;
	// Line 1388, Address: 0x2e5ae0, Func Offset: 0
	// Line 1397, Address: 0x2e5b24, Func Offset: 0x44
	// Line 1403, Address: 0x2e5b28, Func Offset: 0x48
	// Line 1398, Address: 0x2e5b2c, Func Offset: 0x4c
	// Line 1404, Address: 0x2e5b30, Func Offset: 0x50
	// Line 1399, Address: 0x2e5b34, Func Offset: 0x54
	// Line 1405, Address: 0x2e5b38, Func Offset: 0x58
	// Line 1407, Address: 0x2e5b3c, Func Offset: 0x5c
	// Line 1403, Address: 0x2e5b40, Func Offset: 0x60
	// Line 1407, Address: 0x2e5b44, Func Offset: 0x64
	// Line 1404, Address: 0x2e5b50, Func Offset: 0x70
	// Line 1405, Address: 0x2e5b54, Func Offset: 0x74
	// Line 1406, Address: 0x2e5b58, Func Offset: 0x78
	// Line 1407, Address: 0x2e5b64, Func Offset: 0x84
	// Line 1406, Address: 0x2e5b68, Func Offset: 0x88
	// Line 1407, Address: 0x2e5b6c, Func Offset: 0x8c
	// Line 1408, Address: 0x2e5b84, Func Offset: 0xa4
	// Line 1411, Address: 0x2e5b8c, Func Offset: 0xac
	// Line 1412, Address: 0x2e5b90, Func Offset: 0xb0
	// Line 1413, Address: 0x2e5b94, Func Offset: 0xb4
	// Line 1415, Address: 0x2e5b98, Func Offset: 0xb8
	// Line 1408, Address: 0x2e5ba0, Func Offset: 0xc0
	// Line 1412, Address: 0x2e5bac, Func Offset: 0xcc
	// Line 1411, Address: 0x2e5bb0, Func Offset: 0xd0
	// Line 1413, Address: 0x2e5bb4, Func Offset: 0xd4
	// Line 1414, Address: 0x2e5bb8, Func Offset: 0xd8
	// Line 1415, Address: 0x2e5bc4, Func Offset: 0xe4
	// Line 1414, Address: 0x2e5bc8, Func Offset: 0xe8
	// Line 1415, Address: 0x2e5bcc, Func Offset: 0xec
	// Line 1416, Address: 0x2e5be4, Func Offset: 0x104
	// Line 1419, Address: 0x2e5bec, Func Offset: 0x10c
	// Line 1420, Address: 0x2e5bf0, Func Offset: 0x110
	// Line 1421, Address: 0x2e5bf4, Func Offset: 0x114
	// Line 1423, Address: 0x2e5bf8, Func Offset: 0x118
	// Line 1416, Address: 0x2e5c00, Func Offset: 0x120
	// Line 1420, Address: 0x2e5c0c, Func Offset: 0x12c
	// Line 1419, Address: 0x2e5c10, Func Offset: 0x130
	// Line 1421, Address: 0x2e5c14, Func Offset: 0x134
	// Line 1422, Address: 0x2e5c18, Func Offset: 0x138
	// Line 1423, Address: 0x2e5c24, Func Offset: 0x144
	// Line 1422, Address: 0x2e5c28, Func Offset: 0x148
	// Line 1423, Address: 0x2e5c2c, Func Offset: 0x14c
	// Line 1424, Address: 0x2e5c44, Func Offset: 0x164
	// Line 1427, Address: 0x2e5c4c, Func Offset: 0x16c
	// Line 1428, Address: 0x2e5c50, Func Offset: 0x170
	// Line 1429, Address: 0x2e5c54, Func Offset: 0x174
	// Line 1431, Address: 0x2e5c58, Func Offset: 0x178
	// Line 1424, Address: 0x2e5c60, Func Offset: 0x180
	// Line 1428, Address: 0x2e5c6c, Func Offset: 0x18c
	// Line 1427, Address: 0x2e5c70, Func Offset: 0x190
	// Line 1429, Address: 0x2e5c74, Func Offset: 0x194
	// Line 1430, Address: 0x2e5c78, Func Offset: 0x198
	// Line 1431, Address: 0x2e5c84, Func Offset: 0x1a4
	// Line 1430, Address: 0x2e5c88, Func Offset: 0x1a8
	// Line 1431, Address: 0x2e5c8c, Func Offset: 0x1ac
	// Line 1432, Address: 0x2e5ca4, Func Offset: 0x1c4
	// Line 1436, Address: 0x2e5cb0, Func Offset: 0x1d0
	// Line 1432, Address: 0x2e5cb4, Func Offset: 0x1d4
	// Line 1435, Address: 0x2e5cbc, Func Offset: 0x1dc
	// Line 1436, Address: 0x2e5cc8, Func Offset: 0x1e8
	// Line 1435, Address: 0x2e5ccc, Func Offset: 0x1ec
	// Line 1436, Address: 0x2e5cd0, Func Offset: 0x1f0
	// Line 1437, Address: 0x2e5d08, Func Offset: 0x228
	// Line 1438, Address: 0x2e5d18, Func Offset: 0x238
	// Line 1439, Address: 0x2e5d44, Func Offset: 0x264
	// Line 1440, Address: 0x2e5d54, Func Offset: 0x274
	// Line 1441, Address: 0x2e5d80, Func Offset: 0x2a0
	// Line 1442, Address: 0x2e5d90, Func Offset: 0x2b0
	// Line 1447, Address: 0x2e5dbc, Func Offset: 0x2dc
	// Line 1454, Address: 0x2e5e14, Func Offset: 0x334
	// Func End, Address: 0x2e5e5c, Func Offset: 0x37c
}*/

