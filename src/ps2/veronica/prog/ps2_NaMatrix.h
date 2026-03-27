#ifndef _PS2_NAMATRIX_H_
#define _PS2_NAMATRIX_H_

#include "types.h"

void    njInitMatrix(NJS_MATRIX *m, Sint32 n, Int flag);
void    njCalcPoints(NJS_MATRIX *m, NJS_POINT3 *ps, NJS_POINT3 *pd, Int num);
void    njGetTranslation(NJS_MATRIX *m, NJS_POINT3 *p);
void    njUnitTransPortion(NJS_MATRIX *m);
void    njUnitRotPortion(NJS_MATRIX *m);
void    njClearMatrix();
Bool    njPushMatrix(NJS_MATRIX *m);
Bool    njPopMatrix(Uint32 n);
void    njUnitMatrix(register NJS_MATRIX *m);
void    njSetMatrix(NJS_MATRIX *md, NJS_MATRIX *ms);
void    njSetMatrixCN(NJS_MATRIX* pMat);
void    njGetMatrix(NJS_MATRIX *m);
void    njMultiMatrix(NJS_MATRIX *md, NJS_MATRIX *ms);
void    njTranslate(NJS_MATRIX *m, Float x, Float y, Float z);
void    njTranslateV(NJS_MATRIX *m, NJS_VECTOR *v);
void    njRotateX(NJS_MATRIX *m, Angle ang);
void    njRotateY(NJS_MATRIX *m, Angle ang);
void    njRotateZ(NJS_MATRIX *m, Angle ang);
void    njRotateXYZ(NJS_MATRIX *m, Angle angx, Angle angy, Angle angz);
void    njRotXYZ(NJS_MATRIX* pMatrix, int lAngleX, int lAngleY, int lAngleZ);
void    njRotate(NJS_MATRIX *m, NJS_VECTOR *v, Angle ang);
void    njScale(NJS_MATRIX *m, Float sx, Float sy, Float sz);
void    njScaleV(NJS_MATRIX *m, NJS_VECTOR *v);
Bool    njInvertMatrix(NJS_MATRIX *m);
void    njTransposeMatrix(NJS_MATRIX *m);
static float njAtan2b(float a, float b);
void    njMirror(NJS_MATRIX *m, NJS_PLANE *pl);
void    njCalcPoint(NJS_MATRIX *m, NJS_POINT3 *ps, NJS_POINT3 *pd);
void    njCalcPoint4(NJS_MATRIX* pMatrix, NJS_POINT4* pSrcPoint, NJS_POINT4* pDstPoint);
void    njCalcPointCN(NJS_POINT3* pSrcPoint, NJS_POINT3* pDstPoint);
void    njAddVector(NJS_VECTOR *vd, NJS_VECTOR *vs);
void    njSubVector(NJS_VECTOR *vd, NJS_VECTOR *vs);
void    njCalcVector(NJS_MATRIX *m, NJS_VECTOR *vs, NJS_VECTOR *vd);
Float   njUnitVector(NJS_VECTOR *v);
Float   njScalor(NJS_VECTOR *v);
Float   njScalor2(NJS_VECTOR *v);
void    njProjectScreen(NJS_MATRIX *m, NJS_POINT3 *p3, NJS_POINT2 *p2);
Float   njOuterProduct(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *ov);
Float   njInnerProduct(NJS_VECTOR *v1, NJS_VECTOR *v2);
void    njTranslateEx(NJS_VECTOR *v);
void    njRotateEx(Angle *ang, Sint32 lv);
void    njScaleEx(NJS_VECTOR *v);
Bool    njPushMatrixEx(void);
Bool    njPopMatrixEx(void);
void    njRotTransPers(NJS_POINT3* pPoint, NJS_SCRVECTOR* pScreen);
void    njRotTrans(NJS_POINT3* pPoint, NJS_POINT3* pOut);
void    njPers(NJS_SCRVECTOR* pScreen);
void    njCopyMatrix(NJS_MATRIX* pDstMat, NJS_MATRIX* pSrcMat);
void    njMulMatrixCN(NJS_MATRIX* pSrcMat1, NJS_MATRIX* pSrcMat2);

extern NJS_MATRIX* pNaMatMatrixStuckPtr;

#endif
