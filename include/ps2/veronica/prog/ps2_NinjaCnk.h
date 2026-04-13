#ifndef _PS2_NINJACNK_H_
#define _PS2_NINJACNK_H_

#include "types.h"

void	njInit3D( NJS_VERTEX_BUF *vbuf, Int vn );
void	njDrawModel( NJS_MODEL *model );
void	njControl3D( Uint32 flag );
void	njSetConstantAttr( Uint32 and_attr, Uint32 or_attr );
void	njSetConstantMaterial( NJS_ARGB *mat );
void njSetCnkBlendMode(Uint32 attr);
void    njCnkModDrawModel( NJS_CNK_MODEL *model );
void    njCnkSetEasyLight( Float x,Float y,Float z );
void    njCnkSetEasyLightIntensity( Float inten, Float ambient );
void    njCnkSetEasyLightColor( Float r, Float g, Float b );
void    njCnkSetEasyMultiLight(Int num);
void    njCnkSetEasyMultiLightSwitch(Int light, Int flag);
void    njCnkSetEasyMultiAmbient(Float ar, Float ag, Float ab);
void    njCnkSetEasyMultiLightColor(Int light, Float lr, Float lg, Float lb);
void    njCnkSetEasyMultiLightVector(Float vx, Float vy, Float vz);
void    njCnkSetEasyMultiLightPoint(Int light, Float px, Float py, Float pz);
void    njCnkSetEasyMultiLightRange(Int light, Float nrange, Float frange);
void    njCnkSetEasyMultiLightMatrices(void);
void    njCnkSetSimpleLight( Float x,Float y,Float z );
void    njCnkSetSimpleLightIntensity( Float inten, Float ambient );
void    njCnkSetSimpleLightColor( Float r, Float g, Float b );
void    njCnkSetSimpleMultiLight(Int num);
void    njCnkSetSimpleMultiLightSwitch(Int light, Int flag);
void    njCnkSetSimpleMultiAmbient(Float ar, Float ag, Float ab);
void    njCnkSetSimpleMultiLightColor(Int light, Float lr, Float lg, Float lb);
void    njCnkSetSimpleMultiLightVector(Float vx, Float vy, Float vz);
void    njCnkSetSimpleMultiLightPoint(Int light, Float px, Float py, Float pz);
void    njCnkSetSimpleMultiLightRange(Int light, Float nrange, Float frange);
void    njCnkSetSimpleMultiLightMatrices(void);
void    njCnkEasyDrawModel( NJS_CNK_MODEL *model );
void    njCnkEasyDrawObject( NJS_CNK_OBJECT *model );
void    njCnkEasyMultiDrawModel( NJS_CNK_MODEL *model );
void    njCnkEasyMultiDrawObject( NJS_CNK_OBJECT *model );
void    njCnkSimpleDrawModel( NJS_CNK_MODEL *model );
void    njCnkSimpleMultiDrawModel( NJS_CNK_MODEL *model );
void njCnkSetCurrentDrawMode(unsigned int ulMode);
int njCnkDrawModelLocal(NJS_CNK_MODEL* pModel);
int njCnkDrawModelLocalMod(NJS_CNK_MODEL* pModel);
CHUNK_HEAD* njCnkCn(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCbBa(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCbDa(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCbExp(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCtTid(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCmD(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCmA(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCmDa(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCmS(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCmDs(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCmAs(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCmDas(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCoP4(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCoSt(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCvVn(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCvVnPs2(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCvVMod(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCoP3(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCs(CHUNK_HEAD* pCnk);
int _CVV(float* v0);
CHUNK_HEAD* njCnkCsUvh(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkCsUvn(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkDefaultLong(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkDefaultShort(CHUNK_HEAD* pCnk);
void njCnkEasyMultiDrawObjectI(NJS_CNK_OBJECT* pObject);

extern int lCnkModClipFace;
extern float fNaCnkConstantA;
extern float fNaCnkConstantR;
extern float fNaCnkConstantG;
extern float fNaCnkConstantB;

#endif
