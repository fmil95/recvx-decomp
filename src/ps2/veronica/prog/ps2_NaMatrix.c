#include "ps2_NaMatrix.h"
#include "ps2_NaFog.h"
#include "ps2_NaView.h"
#include "main.h"

/*_anon5 TempMatrix0;
_anon5 TempMatrix1;*/
int lNaMatIsUnitMatrix;
int lNaMatMatrixStuckMax;
int lNaMatMatrixStuckCnt;
NJS_MATRIX* pNaMatMatrixStuckPtr;
NJS_MATRIX* pNaMatMatrixStuckTop;
/*_anon4 _nj_screen_;
float NaViewScreenMatrix[16];

void njInitMatrix(float pMatrix[16], int lSize, int lFlag);
void njCalcPoints(float pMatrix[16], _anon0* pSrcPoints, _anon0* pDstPoints, int lNum);
void njGetTranslation(float pMatrix[16], _anon0* pPoint);
void njUnitTransPortion(float pMatrix[16]);
void njUnitRotPortion(float pMatrix[16]);
void njClearMatrix();
int njPushMatrix(float pMatrix[16]);
int njPopMatrix(unsigned int ulNumber);
void njUnitMatrix(float pMatrix[16]);
void njSetMatrix(float pDst[16], float pSrc[16]);
void njSetMatrixCN(float pMat[16]);
void njGetMatrix(float pMatrix[16]);
void njMultiMatrix(float pDstMat[16], float pSrcMat[16]);
void njTranslate(float pMatrix[16], float fX, float fY, float fZ);
void njTranslateV(float pMatrix[16], _anon0* pVector);
void njRotateX(float pMatrix[16], int lAngle);
void njRotateY(float pMatrix[16], int lAngle);
void njRotateZ(float pMatrix[16], int lAngle);
void njRotateXYZ(float pMatrix[16], int lAngleX, int lAngleY, int lAngleZ);
void njRotXYZ(float pMatrix[16], int lAngleX, int lAngleY, int lAngleZ);
void njRotate(float pMatrix[16], _anon0* pAxis, int lAngle);
void njScale(float pMatrix[16], float fScaleX, float fScaleY, float fScaleZ);
void njScaleV(float pMatrix[16], _anon0* pScale);
int njInvertMatrix(float pMatrix[16]);
void njTransposeMatrix(float pMatrix[16]);
static float njAtan2b(float a, float b);
void njMirror(float pMatrix[16], _anon3* pPlane);
void njCalcPoint(float pMatrix[16], _anon0* pSrcPoint, _anon0* pDstPoint);
void njCalcPoint4(float pMatrix[16], _anon1* pSrcPoint, _anon1* pDstPoint);*/
void njCalcPointCN(NJS_POINT3* pSrcPoint, NJS_POINT3* pDstPoint);
/*void njAddVector(_anon0* pDstVec, _anon0* pSrcVec);
void njSubVector(_anon0* pDstVec, _anon0* pSrcVec);
void njCalcVector(float pMatrix[16], _anon0* pSrcVec, _anon0* pDstVec);
float njUnitVector(_anon0* pVector);
float njScalor(_anon0* pVector);
float njScalor2(_anon0* pVector);
void njProjectScreen(float pMatrix[16], _anon0* pPoint, _anon2* pScreen);
float njOuterProduct(_anon0* pSrcVec1, _anon0* pSrcVec2, _anon0* pDstVec);
float njInnerProduct(_anon0* pVec1, _anon0* pVec2);
void njTranslateEx(_anon0* pVector);
void njRotateEx(int* lpAngle, int lV);
void njScaleEx(_anon0* pScale);
int njPushMatrixEx();
int njPopMatrixEx();
void njRotTransPers(_anon0* pPoint, tagNJS_SCRVECTOR* pScreen);
void njRotTrans(_anon0* pPoint, _anon0* pOut);
void njPers(tagNJS_SCRVECTOR* pScreen);
void njCopyMatrix(float pDstMat[16], float pSrcMat[16]);*/
void njMulMatrixCN(NJS_MATRIX* pSrcMat1, NJS_MATRIX* pSrcMat2);

extern void VU0_INIT_CALC_PROCESS() __attribute__((section(".vutext")));

// 98.85% matching
void	njInitMatrix(NJS_MATRIX *m, Sint32 n, Int flag)
{
    register float pi;

    pNaMatMatrixStuckTop = m;
    pNaMatMatrixStuckPtr = m; 
    
    lNaMatMatrixStuckCnt = 0; 
    lNaMatMatrixStuckMax = n; 
    
    lNaMatIsUnitMatrix = flag; 
    
    pi = 3.141592f;
    
    asm volatile 
    {
    .set noreorder
    
        vaddw.xyz  vf1, vf0, vf0w   
        
        vmul.w     vf1, vf0, vf0                     

        sub        t5, t5, t5     
        
        addi       t0, t5, 0x80                       
        addi       t1, t5, 0x100          
        
        mult       zero, t1, t1        
        
        mflo       t2               
        
        mfc1       t3, pi           
        
        qmtc2      t0, vf3                          
        qmtc2      t1, vf9                               
        qmtc2      t2, vf10                             
        qmtc2      t3, vf11                              

        vitof0.xyzw vf3, vf3                        
        vitof0.xyzw vf9, vf9                 
        vitof0.xyzw vf10, vf10         
        
        vaddx.y    vf3, vf0, vf9x                     
        vaddx.z    vf3, vf0, vf10x       
        
        vmulx.w    vf3, vf0, vf11x        
        
        vaddw.xyzw vf2, vf0, vf0w        
        
        vdiv       Q, vf0w, vf2w        
        
        vaddw.xyzw vf2, vf2, vf0w                    
        vaddw.xyzw vf2, vf2, vf0w                     
        vaddw.yzw  vf2, vf2, vf0w                     
        vaddw.zw   vf2, vf2, vf0w   
        
        vwaitq                     
        
        vmulq.w    vf2, vf0, Q                        
        
        addi       t0, zero, 0xFFF      
        
        qmtc2      t0, vf4                               
        
        vitof0.xyz vf4, vf4      
        
        vaddx.z    vf16, vf0, vf4x          
        
        vcallms    VU0_INIT_CALC_PROCESS                          
        
        nop       
    
    .set reorder
    }
}

/*// 
// Start address: 0x2d6780
void njCalcPoints(float pMatrix[16], _anon0* pSrcPoints, _anon0* pDstPoints, int lNum)
{
	// Line 206, Address: 0x2d6780, Func Offset: 0
	// Line 243, Address: 0x2d6784, Func Offset: 0x4
	// Line 305, Address: 0x2d6798, Func Offset: 0x18
	// Line 307, Address: 0x2d679c, Func Offset: 0x1c
	// Line 308, Address: 0x2d67a0, Func Offset: 0x20
	// Line 309, Address: 0x2d67a4, Func Offset: 0x24
	// Line 310, Address: 0x2d67a8, Func Offset: 0x28
	// Line 311, Address: 0x2d67ac, Func Offset: 0x2c
	// Line 312, Address: 0x2d67b0, Func Offset: 0x30
	// Line 314, Address: 0x2d67b4, Func Offset: 0x34
	// Line 315, Address: 0x2d67b8, Func Offset: 0x38
	// Line 316, Address: 0x2d67bc, Func Offset: 0x3c
	// Line 317, Address: 0x2d67c0, Func Offset: 0x40
	// Line 319, Address: 0x2d67c4, Func Offset: 0x44
	// Line 321, Address: 0x2d67c8, Func Offset: 0x48
	// Line 322, Address: 0x2d67cc, Func Offset: 0x4c
	// Line 323, Address: 0x2d67d0, Func Offset: 0x50
	// Line 324, Address: 0x2d67d4, Func Offset: 0x54
	// Line 325, Address: 0x2d67d8, Func Offset: 0x58
	// Line 326, Address: 0x2d67dc, Func Offset: 0x5c
	// Line 327, Address: 0x2d67e0, Func Offset: 0x60
	// Line 328, Address: 0x2d67e4, Func Offset: 0x64
	// Line 329, Address: 0x2d67e8, Func Offset: 0x68
	// Line 330, Address: 0x2d67ec, Func Offset: 0x6c
	// Line 332, Address: 0x2d67f0, Func Offset: 0x70
	// Line 333, Address: 0x2d67f4, Func Offset: 0x74
	// Line 334, Address: 0x2d67f8, Func Offset: 0x78
	// Line 335, Address: 0x2d67fc, Func Offset: 0x7c
	// Line 336, Address: 0x2d6800, Func Offset: 0x80
	// Line 338, Address: 0x2d6804, Func Offset: 0x84
	// Line 339, Address: 0x2d6808, Func Offset: 0x88
	// Line 346, Address: 0x2d6810, Func Offset: 0x90
	// Func End, Address: 0x2d6818, Func Offset: 0x98
}*/

// 100% matching! 
void    njGetTranslation(NJS_MATRIX *m, NJS_POINT3 *p)
{
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile 
    ("
    .set noreorder
        lw t0, 0x30(%0)
        lw t1, 0x34(%0)
        lw t2, 0x38(%0)
        
        sw t0, NJS_POINT3.x(%1)
        sw t1, NJS_POINT3.y(%1)
        sw t2, NJS_POINT3.z(%1)
    .set reorder
    " : : "r"(m), "r"(p) : 
    );
}

// 100% matching!
void    njUnitTransPortion(NJS_MATRIX *m)
{
	if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile 
    ("
    .set noreorder
        sqc2 vf0, 0x30(%0)
    .set reorder
    " : : "r"(m) : 
    );
}

// 100% matching! 
void    njUnitRotPortion(NJS_MATRIX *m)
{
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile 
    ("
    .set noreorder
        vmulw.xyzw vf4, vf0, vf0w
        
        vmr32.xyzw vf5, vf4
        vmr32.xyzw vf6, vf5
        vmr32.xyzw vf7, vf6
        
        sqc2       vf5, 0x20(%0)
        sqc2       vf6, 0x10(%0)
        sqc2       vf7,  0x0(%0)
    .set reorder
    " : : "r"(m) : 
    );
}

// 100% matching!
void    njClearMatrix()
{
    lNaMatMatrixStuckCnt = 0;

    pNaMatMatrixStuckPtr = pNaMatMatrixStuckTop;
    
    njSetMatrix(NULL, &NaViwViewMatrix);
}

// 100% matching!
Bool	njPushMatrix(NJS_MATRIX *m)
{
	NJS_MATRIX* fpSrc;
    NJS_MATRIX* fpDst;

    if (lNaMatMatrixStuckMax <= lNaMatMatrixStuckCnt) 
    {
        return FALSE;
    }
    
    lNaMatMatrixStuckCnt++;

    if (m == NULL) 
    {
        fpSrc = pNaMatMatrixStuckPtr;
    }
    else 
    {
        fpSrc = m;
    }

    pNaMatMatrixStuckPtr++;
    
    fpDst = pNaMatMatrixStuckPtr;
    
    asm volatile
    ("
    .set noreorder
        lqc2 vf4, 0(%0) 
        lqc2 vf5, 0x10(%0) 
        lqc2 vf6, 0x20(%0) 
        lqc2 vf7, 0x30(%0) 
    
        sqc2 vf4, 0(%1) 
        sqc2 vf5, 0x10(%1) 
        sqc2 vf6, 0x20(%1) 
        sqc2 vf7, 0x30(%1) 
    .set reorder
    " : : "r"(fpSrc), "r"(fpDst) : 
    );

    return TRUE;
}

// 100% matching!
Bool	njPopMatrix(Uint32 n)
{
    int lNumber;

    lNumber = lNaMatMatrixStuckCnt - n;
    
    if (lNumber < 0) 
    {
        return FALSE;
    }
    
    lNaMatMatrixStuckCnt = lNumber;
    
    pNaMatMatrixStuckPtr -= n;
    
    return TRUE;
}

// 100% matching!
void	njUnitMatrix(register NJS_MATRIX *m)
{
    if (m == NULL) 
    {
        m = pNaMatMatrixStuckPtr;
    }
    
    asm volatile 
    {
    .set noreorder

        vmulw.xyzw $vf4xyzw, $vf0xyzw, $vf0w

        vmr32.xyzw $vf5xyzw, $vf4xyzw
        vmr32.xyzw $vf6xyzw, $vf5xyzw
        vmr32.xyzw $vf7xyzw, $vf6xyzw
    
        sqc2       $vf4, 0x30(m)
        sqc2       $vf5, 0x20(m)
        sqc2       $vf6, 0x10(m) 
        sqc2       $vf7,  0x0(m)
        
    .set reorder
    }
}

// 100% matching!
void	njSetMatrix(NJS_MATRIX *md, NJS_MATRIX *ms)
{
    register NJS_MATRIX* fpSrc; 
    register NJS_MATRIX* fpDst; 

    fpSrc = ms;
    fpDst = md ? md : pNaMatMatrixStuckPtr;

    asm volatile 
    {
    .set noreorder
        
        lqc2       $vf4, 0x0(fpSrc) 
        lqc2       $vf5, 0x10(fpSrc) 
        lqc2       $vf6, 0x20(fpSrc) 
        lqc2       $vf7, 0x30(fpSrc) 
    
        sqc2       $vf4, 0x0(fpDst) 
        sqc2       $vf5, 0x10(fpDst) 
        sqc2       $vf6, 0x20(fpDst) 
        sqc2       $vf7, 0x30(fpDst) 
        
    .set reorder
    }
}

// 100% matching!
void njSetMatrixCN(NJS_MATRIX* pMat)
{
    asm volatile
    ("
    .set noreorder
        lqc2 vf28,  0x0(%0) 
        lqc2 vf29, 0x10(%0) 
        lqc2 vf30, 0x20(%0) 
        lqc2 vf31, 0x30(%0) 
    .set reorder 
    " : : "r"(pMat) : 
    );
}

// 100% matching!
void	njGetMatrix(NJS_MATRIX *m)
{
    register NJS_MATRIX* fpSrc; 
    register NJS_MATRIX* fpDst; 

    fpSrc = pNaMatMatrixStuckPtr;
    fpDst = m; 
    
    asm volatile 
    {
    .set noreorder
        
        lqc2       $vf4, 0x0(fpSrc)
        lqc2       $vf5, 0x10(fpSrc)
        lqc2       $vf6, 0x20(fpSrc)
        lqc2       $vf7, 0x30(fpSrc)
    
        sqc2       $vf4, 0x0(fpDst)
        sqc2       $vf5, 0x10(fpDst)
        sqc2       $vf6, 0x20(fpDst)
        sqc2       $vf7, 0x30(fpDst)
        
    .set reorder
    }
}

// 100% matching!
void	njMultiMatrix(NJS_MATRIX *md, NJS_MATRIX *ms)
{
    if (md == NULL)
    {
        md = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        lqc2        vf4,  0(%0)
        lqc2        vf5,  0x10(%0)
        lqc2        vf6,  0x20(%0)
        lqc2        vf7,  0x30(%0)
        lqc2        vf8,  0(%1)
        lqc2        vf9,  0x10(%1)
        lqc2        vf10, 0x20(%1)
        lqc2        vf11, 0x30(%1)

        vmulax.xyz  ACC,  vf4, vf8
        
        vmadday.xyz ACC,  vf5, vf8
        vmaddz.xyz  vf8,  vf6, vf8
        
        vmulax.xyz  ACC,  vf4, vf9

        vmadday.xyz ACC,  vf5, vf9
        vmaddz.xyz  vf9,  vf6, vf9
        
        vmulax.xyz  ACC,  vf4, vf10

        vmadday.xyz ACC,  vf5, vf10
        vmaddz.xyz  vf10, vf6, vf10
        
        vmulax.xyz  ACC,  vf4, vf11

        vmadday.xyz ACC,  vf5, vf11
        vmaddaz.xyz ACC,  vf6, vf11
        vmaddw.xyz  vf11, vf7, vf0

        sqc2        vf8,  0x0(%0)
        sqc2        vf9,  0x10(%0)
        sqc2        vf10, 0x20(%0)
        sqc2        vf11, 0x30(%0)
    .set reorder
    " : : "r"(md), "r"(ms) : 
    );
}

// 100% matching!
void	njTranslate(NJS_MATRIX *m, Float x, Float y, Float z)
{
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        mfc1        t0, %1 
        mfc1        t1, %2
        mfc1        t2, %3
        
        qmtc2       t0, vf4
        qmtc2       t1, vf5
        qmtc2       t2, vf6
    
        lqc2        vf7,  0(%0)
        lqc2        vf8,  0x10(%0)
        lqc2        vf9,  0x20(%0)
        lqc2        vf10, 0x30(%0)

        vmulax.xyz  ACC,  vf7,  vf4
        
        vmaddax.xyz ACC,  vf8,  vf5
        vmaddax.xyz ACC,  vf9,  vf6
        vmaddw.xyz  vf11, vf10, vf0
    
        sqc2        vf11, 0x30(%0)
    .set reorder
    " : : "r"(m), "f"(x), "f"(y), "f"(z) : 
    );
}

// 100% matching!
void	njTranslateV(NJS_MATRIX *m, NJS_VECTOR *v)
{
	if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        ldl         a4, 0x7(%1)
        ldr         a4,   0(%1)

        lw          a5, NJS_VECTOR.z(%1) 

        pcpyld      a4, a5, a4

        qmtc2.ni    a4, vf4

        lqc2        vf5, 0(%0)
        lqc2        vf6, 0x10(%0)
        lqc2        vf7, 0x20(%0)
        lqc2        vf8, 0x30(%0)

        vmulax.xyz  ACC,  vf5, vf4x
        
        vmadday.xyz ACC,  vf6, vf4y
        vmaddaz.xyz ACC,  vf7, vf4z
        vmaddw.xyz  vf9,  vf8, vf0w
    
        sqc2        vf9,  0x30(%0)
    .set reorder
    " : : "r"(m), "r"(v) : 
    );
}

// 100% matching!
void	njRotateX(NJS_MATRIX *m, Angle ang)
{
    float fSin;
    float fCos;

    ang &= 0xFFFF;
    
    njSinCos(ang, &fSin, &fCos);
    
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        mfc1      t6, %1 
        mfc1      t7, %2
        
        qmtc2     t6, vf11
        qmtc2     t7, vf12
    
        lqc2      vf4, 0x10(%0)
        lqc2      vf5, 0x20(%0)

        vsub.x    vf10, vf0, vf11
        
        vmulx.xyz vf6, vf4, vf12
        vmulx.xyz vf7, vf5, vf11
        vmulx.xyz vf4, vf4, vf10
        vmulx.xyz vf5, vf5, vf12

        vadd.xyz  vf8, vf6, vf7
        vadd.xyz  vf9, vf4, vf5

        sqc2      vf8, 0x10(%0)
        sqc2      vf9, 0x20(%0)
    .set reorder
    " : : "r"(m), "f"(fSin), "f"(fCos) : 
    );
}

// 100% matching!
void	njRotateY(NJS_MATRIX *m, Angle ang)
{
    float fSin;
    float fCos;

    ang &= 0xFFFF;
    
    njSinCos(ang, &fSin, &fCos);
    
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        mfc1      t6, %1 
        mfc1      t7, %2
        
        qmtc2     t6, vf11
        qmtc2     t7, vf12
    
        lqc2      vf4, 0x0(%0)
        lqc2      vf5, 0x20(%0)

        vsub.x    vf10, vf0, vf11
        
        vmulx.xyz vf6, vf4, vf12
        vmulx.xyz vf7, vf5, vf10
        vmulx.xyz vf4, vf4, vf11
        vmulx.xyz vf5, vf5, vf12

        vadd.xyz  vf8, vf6, vf7
        vadd.xyz  vf9, vf4, vf5

        sqc2      vf8, 0x0(%0)
        sqc2      vf9, 0x20(%0)
    .set reorder
    " : : "r"(m), "f"(fSin), "f"(fCos) : 
    );
}

// 100% matching!
void	njRotateZ(NJS_MATRIX *m, Angle ang)
{
    float fSin;
    float fCos;

    ang &= 0xFFFF;
    
    njSinCos(ang, &fSin, &fCos);
    
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        mfc1      t6, %1 
        mfc1      t7, %2
        
        qmtc2     t6, vf11
        qmtc2     t7, vf12
    
        lqc2      vf4, 0x0(%0)
        lqc2      vf5, 0x10(%0)

        vsub.x    vf10, vf0, vf11
        
        vmulx.xyz vf6, vf4, vf12
        vmulx.xyz vf7, vf5, vf11
        vmulx.xyz vf4, vf4, vf10
        vmulx.xyz vf5, vf5, vf12

        vadd.xyz  vf8, vf6, vf7
        vadd.xyz  vf9, vf4, vf5

        sqc2      vf8, 0x0(%0)
        sqc2      vf9, 0x10(%0)
    .set reorder
    " : : "r"(m), "f"(fSin), "f"(fCos) : 
    );
}

// 100% matching!
void	njRotateXYZ(NJS_MATRIX *m, Angle angx, Angle angy, Angle angz)
{
    if (m == NULL) 
    {
        m = pNaMatMatrixStuckPtr;
    }
    
    njRotateZ(m, angz);
    njRotateY(m, angy);
    njRotateX(m, angx);
}

// 100% matching!
void njRotXYZ(NJS_MATRIX* pMatrix, int lAngleX, int lAngleY, int lAngleZ)
{
    float fSin;
    float fCos;

    lAngleX &= 0xFFFF;
    
    njSinCos(lAngleX, &fSin, &fCos);
    
    asm volatile
    ("
    .set noreorder
        lqc2      vf4,  0x0(%0)
        lqc2      vf5, 0x10(%0)
        lqc2      vf6, 0x20(%0)

        vsub.x    vf10, vf0, vf11
        
        vmulx.xyz vf7, vf5, vf12
        vmulx.xyz vf8, vf6, vf11
        vmulx.xyz vf5, vf5, vf10
        vmulx.xyz vf6, vf6, vf12

        vadd.xyz  vf6, vf5, vf6
        vadd.xyz  vf5, vf7, vf8
    .set reorder
    " : : "r"(pMatrix) :  
    );

    lAngleY &= 0xFFFF;
    
    njSinCos(lAngleY, &fSin, &fCos);
    
    asm volatile
    ("
    .set noreorder
        vsub.x    vf10, vf0, vf11
        
        vmulx.xyz vf7, vf4, vf12
        vmulx.xyz vf8, vf6, vf10
        vmulx.xyz vf4, vf4, vf11
        vmulx.xyz vf6, vf6, vf12

        vadd.xyz  vf6, vf4, vf6
        vadd.xyz  vf4, vf7, vf8
    .set reorder
    " : : "r"(pMatrix) :  
    );

    lAngleZ &= 0xFFFF;
    
    njSinCos(lAngleZ, &fSin, &fCos);
    
    asm volatile
    ("
    .set noreorder
        vsub.x    vf10, vf0, vf11
        
        vmulx.xyz vf7, vf4, vf12
        vmulx.xyz vf8, vf5, vf11
        vmulx.xyz vf4, vf4, vf10
        vmulx.xyz vf5, vf5, vf12

        vadd.xyz  vf8, vf7, vf8
        vadd.xyz  vf9, vf4, vf5

        sqc2      vf8,  0x0(%0)
        sqc2      vf9, 0x10(%0)
        sqc2      vf6, 0x20(%0)
    .set reorder
    " : : "r"(pMatrix) : 
    );
}

/*// 
// Start address: 0x2d6f00
void njRotate(float pMatrix[16], _anon0* pAxis, int lAngle)
{
	float fCos;
	float fSin;
	// Line 2356, Address: 0x2d6f00, Func Offset: 0
	// Line 2370, Address: 0x2d6f14, Func Offset: 0x14
	// Line 2372, Address: 0x2d6f28, Func Offset: 0x28
	// Line 2373, Address: 0x2d6f2c, Func Offset: 0x2c
	// Line 2376, Address: 0x2d6f30, Func Offset: 0x30
	// Line 2575, Address: 0x2d6f40, Func Offset: 0x40
	// Line 2579, Address: 0x2d6f4c, Func Offset: 0x4c
	// Line 2580, Address: 0x2d6f50, Func Offset: 0x50
	// Line 2581, Address: 0x2d6f54, Func Offset: 0x54
	// Line 2582, Address: 0x2d6f58, Func Offset: 0x58
	// Line 2583, Address: 0x2d6f5c, Func Offset: 0x5c
	// Line 2585, Address: 0x2d6f60, Func Offset: 0x60
	// Line 2586, Address: 0x2d6f64, Func Offset: 0x64
	// Line 2587, Address: 0x2d6f68, Func Offset: 0x68
	// Line 2588, Address: 0x2d6f6c, Func Offset: 0x6c
	// Line 2589, Address: 0x2d6f70, Func Offset: 0x70
	// Line 2590, Address: 0x2d6f74, Func Offset: 0x74
	// Line 2591, Address: 0x2d6f78, Func Offset: 0x78
	// Line 2592, Address: 0x2d6f7c, Func Offset: 0x7c
	// Line 2593, Address: 0x2d6f80, Func Offset: 0x80
	// Line 2594, Address: 0x2d6f84, Func Offset: 0x84
	// Line 2599, Address: 0x2d6f88, Func Offset: 0x88
	// Line 2600, Address: 0x2d6f8c, Func Offset: 0x8c
	// Line 2601, Address: 0x2d6f90, Func Offset: 0x90
	// Line 2602, Address: 0x2d6f94, Func Offset: 0x94
	// Line 2603, Address: 0x2d6f98, Func Offset: 0x98
	// Line 2604, Address: 0x2d6f9c, Func Offset: 0x9c
	// Line 2605, Address: 0x2d6fa0, Func Offset: 0xa0
	// Line 2608, Address: 0x2d6fa4, Func Offset: 0xa4
	// Line 2609, Address: 0x2d6fa8, Func Offset: 0xa8
	// Line 2610, Address: 0x2d6fac, Func Offset: 0xac
	// Line 2612, Address: 0x2d6fb0, Func Offset: 0xb0
	// Line 2613, Address: 0x2d6fb4, Func Offset: 0xb4
	// Line 2615, Address: 0x2d6fb8, Func Offset: 0xb8
	// Line 2616, Address: 0x2d6fbc, Func Offset: 0xbc
	// Line 2619, Address: 0x2d6fc0, Func Offset: 0xc0
	// Line 2620, Address: 0x2d6fc4, Func Offset: 0xc4
	// Line 2622, Address: 0x2d6fc8, Func Offset: 0xc8
	// Line 2623, Address: 0x2d6fcc, Func Offset: 0xcc
	// Line 2624, Address: 0x2d6fd0, Func Offset: 0xd0
	// Line 2626, Address: 0x2d6fd4, Func Offset: 0xd4
	// Line 2627, Address: 0x2d6fd8, Func Offset: 0xd8
	// Line 2630, Address: 0x2d6fdc, Func Offset: 0xdc
	// Line 2631, Address: 0x2d6fe0, Func Offset: 0xe0
	// Line 2633, Address: 0x2d6fe4, Func Offset: 0xe4
	// Line 2634, Address: 0x2d6fe8, Func Offset: 0xe8
	// Line 2636, Address: 0x2d6fec, Func Offset: 0xec
	// Line 2637, Address: 0x2d6ff0, Func Offset: 0xf0
	// Line 2638, Address: 0x2d6ff4, Func Offset: 0xf4
	// Line 2640, Address: 0x2d6ff8, Func Offset: 0xf8
	// Line 2641, Address: 0x2d6ffc, Func Offset: 0xfc
	// Line 2642, Address: 0x2d7000, Func Offset: 0x100
	// Line 2649, Address: 0x2d7004, Func Offset: 0x104
	// Line 2650, Address: 0x2d7008, Func Offset: 0x108
	// Line 2651, Address: 0x2d700c, Func Offset: 0x10c
	// Line 2652, Address: 0x2d7010, Func Offset: 0x110
	// Line 2653, Address: 0x2d7014, Func Offset: 0x114
	// Line 2657, Address: 0x2d7018, Func Offset: 0x118
	// Line 2658, Address: 0x2d701c, Func Offset: 0x11c
	// Line 2659, Address: 0x2d7020, Func Offset: 0x120
	// Line 2660, Address: 0x2d7024, Func Offset: 0x124
	// Line 2661, Address: 0x2d7028, Func Offset: 0x128
	// Line 2665, Address: 0x2d702c, Func Offset: 0x12c
	// Line 2666, Address: 0x2d7030, Func Offset: 0x130
	// Line 2667, Address: 0x2d7034, Func Offset: 0x134
	// Line 2668, Address: 0x2d7038, Func Offset: 0x138
	// Line 2669, Address: 0x2d703c, Func Offset: 0x13c
	// Line 2671, Address: 0x2d7040, Func Offset: 0x140
	// Line 2672, Address: 0x2d7044, Func Offset: 0x144
	// Line 2673, Address: 0x2d7048, Func Offset: 0x148
	// Line 2680, Address: 0x2d704c, Func Offset: 0x14c
	// Func End, Address: 0x2d7060, Func Offset: 0x160
}*/

// 100% matching!
void	njScale(NJS_MATRIX *m, Float sx, Float sy, Float sz)
{
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        mfc1      t2, %1 
        mfc1      t3, %2
        mfc1      t4, %3
        
        qmtc2     t2, vf4
        qmtc2     t3, vf5
        qmtc2     t4, vf6
    
        lqc2      vf7,  0x0(%0)
        lqc2      vf8, 0x10(%0)
        lqc2      vf9, 0x20(%0)

        vmulx.xyz vf7, vf7, vf4
        vmulx.xyz vf8, vf8, vf5
        vmulx.xyz vf9, vf9, vf6
    
        sqc2      vf7,  0x0(%0)
        sqc2      vf8, 0x10(%0)
        sqc2      vf9, 0x20(%0)
    .set reorder
    " : : "r"(m), "f"(sx), "f"(sy), "f"(sz) : 
    );
}

// 100% matching!
void	njScaleV(NJS_MATRIX *m, NJS_VECTOR *v)
{
	if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        ldl         a4, 0x7(%1)
        ldr         a4,   0(%1)

        lw          a5, NJS_VECTOR.z(%1) 

        pcpyld      a4, a5, a4

        qmtc2.ni    a4, vf4

        lqc2        vf5,    0(%0)
        lqc2        vf6, 0x10(%0)
        lqc2        vf7, 0x20(%0)

        vmulx       vf5, vf5, vf4
        vmuly       vf6, vf6, vf4
        vmulz       vf7, vf7, vf4
    
        sqc2        vf5,     0(%0)
        sqc2        vf6,  0x10(%0)
        sqc2        vf7,  0x20(%0)
    .set reorder
    " : : "r"(m), "r"(v) : 
    );
}

/*// 
// Start address: 0x2d7120
int njInvertMatrix(float pMatrix[16])
{
	// Line 3277, Address: 0x2d7120, Func Offset: 0
	// Line 3355, Address: 0x2d7134, Func Offset: 0x14
	// Line 3356, Address: 0x2d7138, Func Offset: 0x18
	// Line 3357, Address: 0x2d713c, Func Offset: 0x1c
	// Line 3358, Address: 0x2d7140, Func Offset: 0x20
	// Line 3360, Address: 0x2d7144, Func Offset: 0x24
	// Line 3361, Address: 0x2d7148, Func Offset: 0x28
	// Line 3362, Address: 0x2d714c, Func Offset: 0x2c
	// Line 3363, Address: 0x2d7150, Func Offset: 0x30
	// Line 3365, Address: 0x2d7154, Func Offset: 0x34
	// Line 3366, Address: 0x2d7158, Func Offset: 0x38
	// Line 3367, Address: 0x2d715c, Func Offset: 0x3c
	// Line 3368, Address: 0x2d7160, Func Offset: 0x40
	// Line 3369, Address: 0x2d7164, Func Offset: 0x44
	// Line 3370, Address: 0x2d7168, Func Offset: 0x48
	// Line 3371, Address: 0x2d716c, Func Offset: 0x4c
	// Line 3373, Address: 0x2d7170, Func Offset: 0x50
	// Line 3374, Address: 0x2d7174, Func Offset: 0x54
	// Line 3375, Address: 0x2d7178, Func Offset: 0x58
	// Line 3377, Address: 0x2d717c, Func Offset: 0x5c
	// Line 3378, Address: 0x2d7180, Func Offset: 0x60
	// Line 3379, Address: 0x2d7184, Func Offset: 0x64
	// Line 3380, Address: 0x2d7188, Func Offset: 0x68
	// Line 3382, Address: 0x2d718c, Func Offset: 0x6c
	// Line 3383, Address: 0x2d7190, Func Offset: 0x70
	// Line 3384, Address: 0x2d7194, Func Offset: 0x74
	// Line 3385, Address: 0x2d7198, Func Offset: 0x78
	// Line 3393, Address: 0x2d719c, Func Offset: 0x7c
	// Func End, Address: 0x2d71a4, Func Offset: 0x84
}

// 
// Start address: 0x2d71b0
void njTransposeMatrix(float pMatrix[16])
{
	// Line 3473, Address: 0x2d71b0, Func Offset: 0
	// Line 3533, Address: 0x2d71c4, Func Offset: 0x14
	// Line 3534, Address: 0x2d71c8, Func Offset: 0x18
	// Line 3535, Address: 0x2d71cc, Func Offset: 0x1c
	// Line 3536, Address: 0x2d71d0, Func Offset: 0x20
	// Line 3537, Address: 0x2d71d4, Func Offset: 0x24
	// Line 3538, Address: 0x2d71d8, Func Offset: 0x28
	// Line 3539, Address: 0x2d71dc, Func Offset: 0x2c
	// Line 3540, Address: 0x2d71e0, Func Offset: 0x30
	// Line 3541, Address: 0x2d71e4, Func Offset: 0x34
	// Line 3542, Address: 0x2d71e8, Func Offset: 0x38
	// Line 3543, Address: 0x2d71ec, Func Offset: 0x3c
	// Line 3544, Address: 0x2d71f0, Func Offset: 0x40
	// Line 3545, Address: 0x2d71f4, Func Offset: 0x44
	// Line 3546, Address: 0x2d71f8, Func Offset: 0x48
	// Line 3547, Address: 0x2d71fc, Func Offset: 0x4c
	// Line 3554, Address: 0x2d7200, Func Offset: 0x50
	// Func End, Address: 0x2d7208, Func Offset: 0x58
}*/

// 100% matching!
static float njAtan2b(float a, float b)
{
    return atan2(a, b);
}

// 100% matching!
void	njMirror(NJS_MATRIX *m,NJS_PLANE *pl)
{
    NJS_MATRIX mat; 
    int lAngleX;   
    int lAngleZ;   
    
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        move        a1, %0
        move        a0, %1
        move        s1, %2
        move        s2, %3
        
        addiu       a0, sp, 0x40
        
        vaddz.x     vf4, vf0, vf3z
        
        ld          t0, NJS_PLANE.vx(a1)
        ld          t2, NJS_PLANE.vz(a1)
        
        qmtc2       t0, vf5
    
        vmulw.x     vf4, vf4, vf2w
        
        qmtc2       t2, vf6
    
        vaddx.z     vf5, vf0, vf6x
        
        vmul.xyz    vf7, vf5, vf5
        
        vaddy.x     vf7, vf7, vf7y
        vaddz.x     vf7, vf7, vf7z
        
        vrsqrt      Q, vf0w, vf7x
    
        ldl         t0, 0x7(a1)
        ldr         t0, 0x0(a1)
        
        lw          t1, 0x8(a1)
        
        pcpyld      t0, t1, t0
    
        qmtc2       t0, vf12
    
        vwaitq
    
        vmulq.xyz   vf9, vf5, Q
    
        vaddq.x     vf6, vf0, Q
        
        vmul.xyz    vf8, vf9, vf12
        
        vsubx.x     vf10, vf0, vf8x
        vsuby.x     vf10, vf10, vf8y
        vsubz.x     vf10, vf10, vf8z
        
        vmulx.xyz   vf11, vf9, vf10x
        
        vsub.xyz    vf11, vf0, vf11
        
        qmfc2       t0, vf10
    
        bnez        t0, l_002D732C
    
        vadd.x      vf10, vf10, vf10
        
        vmulw.xyzw  vf4, vf0, vf0w
        
        vmr32.xyzw  vf5, vf4
        vmr32.xyzw  vf6, vf5
        vmr32.xyzw  vf7, vf6
        
        sqc2        vf4, 0x30(s1)
        sqc2        vf5, 0x20(s1)
        sqc2        vf6, 0x10(s1)

        jr          ra
		
        sqc2        vf7, 0x0(s1)
    
        l_002D732C:
        vmulx.xyz   vf14, vf5, vf10x
        
        vsub.xyz    vf12, vf0, vf14
        
        vaddy.x     vf11, vf0, vf5y
        vaddz.x     vf11, vf11, vf5z
        
        qmfc2       t0, vf11
    
        bnez        t0, l_002D7374
    
        sqc2        vf12, 0x30(a0)
        
        addiu       t6, zero, 0x4008
        addiu       t6, t6, 0x7FF8
        addiu       t7, zero, 0x4000
        
        mfc1        s1, f0
        
        qmfc2       t2, vf5
    
        bgtz        t2, l_002D7450
    
        mfc1        s2, f14
    
        bgtz        t2, l_002D7450
    
        mfc1        s2, f15
    
        j           l_002D7450
    
        mfc1        s2, f0
    
        l_002D7374:
        vaddz.x     vf6, vf0, vf5z
        vaddy.x     vf7, vf0, vf5y
        
        qmfc2       a0, vf6
        qmfc2       a1, vf7
    
        addi        sp, sp, -0x10 
        
        sw          v0, 0x0(sp)
        sw          v1, 0x4(sp)
        sw          a0, 0x8(sp)
        sw          a1, 0xC(sp)
        
        lwc1        f12, 0x8(sp)
        
        jal         njAtan2b
    
        lwc1        f13, 0xC(sp)
        
        swc1        f0, 0xC(sp)
        
        lw          v0, 0x0(sp)
        lw          v1, 0x4(sp)
        lw          t2, 0xC(sp)
        
        addi        sp, sp, 0x10 
    
        qmtc2       t2, vf12
        
        vmulx.x     vf12, vf12, vf4x
        
        vdiv        Q, vf12x, vf3w
    
        vmul.xyz    vf6, vf5, vf5
        
        vaddy.x     vf7, vf0, vf5y
        vaddz.x     vf7, vf7, vf5z
        
        vwaitq
        
        vaddq.x     vf12, vf0, Q
        
        vftoi0.xyzw vf12, vf12
        
        qmfc2       t3, vf12
    
        sw          t3, 0x0(s1)
        
        vsqrt       Q, vf7x          
    
        addi        sp, sp, -0x10 
        
        sw          v0, 0x0(sp)
        sw          v1, 0x4(sp)
        
        vwaitq
        
        vaddq.x     vf6, vf0, Q
        
        qmfc2       a0, vf5
        qmfc2       a1, vf6
    
        sw          a0, 0x8(sp)
        sw          a1, 0xC(sp)
        
        lwc1        f12, 0x8(sp)
        
        jal         njAtan2b
    
        lwc1        f13, 0xC(sp)
        
        swc1        f0, 0xC(sp)
        
        lw          v0, 0x0(sp)
        lw          v1, 0x4(sp)
        lw          t2, 0xC(sp)
        
        addi        sp, sp, 0x10 
    
        qmtc2       t2, vf12
        
        vmulx.x     vf12, vf12, vf4x
        
        vdiv        Q, vf12x, vf3w
    
        vwaitq
    
        vaddq.x     vf12, vf0, Q
        
        vsubx.x     vf12, vf0, vf12x
        
        vftoi0.xyzw vf12, vf12
        
        qmfc2       t3, vf12
    
        sw          t3, 0x0(s2)
    .set reorder
    " : : "r"(pl), "f"(&mat), "r"(&lAngleX), "r"(&lAngleZ) : 
    );

    l_002D7450:
    njUnitRotPortion(&mat);
    
    njRotateX(&mat, lAngleX);
    njRotateZ(&mat, lAngleZ);
    
    njScale(&mat, 1.0f, -1.0f, 1.0f);
    
    njRotateZ(&mat, -lAngleZ);
    njRotateX(&mat, -lAngleX);
    
    njMultiMatrix(m, &mat);
}

// 100% matching!
void	njCalcPoint(NJS_MATRIX *m, NJS_POINT3 *ps, NJS_POINT3 *pd)
{
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        ldl         t0, 7(%1)
        ldr         t0, 0(%1)
        
        lw          t1, 8(%1)
        
        pcpyld      t0, t1, t0
    
        qmtc2       t0, vf4
    
        lqc2        vf5, 0(%0)
        lqc2        vf6, 0x10(%0)
        lqc2        vf7, 0x20(%0)
        lqc2        vf8, 0x30(%0)

        vmulax.xyz  ACC,  vf5, vf4
        
        vmadday.xyz ACC,  vf6, vf4
        vmaddaz.xyz ACC,  vf7, vf4
        vmaddw.xyz  vf18, vf8, vf0

        qmfc2       t0, vf18
    
        pcpyud      t1, t0, t0
    
        sdl         t0, 7(%2)
        sdr         t0, 0(%2)
        
        sw          t1, 8(%2)
    .set reorder
    " : : "r"(m), "r"(ps), "r"(pd) : 
    );
}

// 100% matching!
void njCalcPoint4(NJS_MATRIX* pMatrix, NJS_POINT4* pSrcPoint, NJS_POINT4* pDstPoint)
{
    if (pMatrix == NULL)
    {
        pMatrix = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        lqc2        vf4, 0(%1)
        lqc2        vf5, 0(%0)
        lqc2        vf6, 0x10(%0)
        lqc2        vf7, 0x20(%0)
        lqc2        vf8, 0x30(%0)

        vmulax.xyz  ACC,  vf5, vf4x
        
        vmadday.xyz ACC,  vf6, vf4y
        vmaddaz.xyz ACC,  vf7, vf4z
        vmaddw.xyz  vf18, vf8, vf0w
    
        sqc2        vf18, 0(%2)
    .set reorder
    " : : "r"(pMatrix), "r"(pSrcPoint), "r"(pDstPoint) : 
    );
}

// 100% matching!
void njCalcPointCN(NJS_POINT3* pSrcPoint, NJS_POINT3* pDstPoint)
{
    asm volatile
    ("
    .set noreorder
        ldl         t2, 7(%0)
        ldr         t2, 0(%0)
        
        lw          t3, 8(%0)
        
        pcpyld      t2, t3, t2
    
        qmtc2       t2, vf4
    
        vmulax.xyz  ACC, vf28, vf4
        
        vmadday.xyz ACC, vf29, vf4
        vmaddaz.xyz ACC, vf30, vf4

        vmaddw.xyz  vf18, vf31, vf0

        qmfc2       t0, vf18
    
        pcpyud      t1, t0, t0
    
        sdl         t0, 7(%1)
        sdr         t0, 0(%1)
        
        sw          t1, 8(%1)
    .set reorder
    " : : "r"(pSrcPoint), "r"(pDstPoint) : 
    );
}

// 100% matching!
void	njAddVector(NJS_VECTOR *vd, NJS_VECTOR *vs)
{
	asm volatile
    ("
    .set noreorder
        lwc1   f8, NJS_VECTOR.x(%0)
        lwc1   f9, NJS_VECTOR.y(%0)
        lwc1  f10, NJS_VECTOR.z(%0)

        lwc1  f11, NJS_VECTOR.x(%1)
        lwc1  f12, NJS_VECTOR.y(%1)
        lwc1  f13, NJS_VECTOR.z(%1)

        add.s  f8,  f8, f11
        add.s  f9,  f9, f12
        add.s f10, f10, f13

        swc1   f8, NJS_VECTOR.x(%0)
        swc1   f9, NJS_VECTOR.y(%0)
        swc1  f10, NJS_VECTOR.z(%0)
    .set reorder
    " : : "r"(vd), "r"(vs) : 
    );
}

// 100% matching!
void	njSubVector(NJS_VECTOR *vd, NJS_VECTOR *vs)
{
	asm volatile
    ("
    .set noreorder
        lwc1   f8, NJS_VECTOR.x(%0)
        lwc1   f9, NJS_VECTOR.y(%0)
        lwc1  f10, NJS_VECTOR.z(%0)

        lwc1  f11, NJS_VECTOR.x(%1)
        lwc1  f12, NJS_VECTOR.y(%1)
        lwc1  f13, NJS_VECTOR.z(%1)

        sub.s  f8,  f8, f11
        sub.s  f9,  f9, f12
        sub.s f10, f10, f13

        swc1   f8, NJS_VECTOR.x(%0)
        swc1   f9, NJS_VECTOR.y(%0)
        swc1  f10, NJS_VECTOR.z(%0)
    .set reorder
    " : : "r"(vd), "r"(vs) : 
    );
}

// 100% matching!
void	njCalcVector(NJS_MATRIX *m, NJS_VECTOR *vs, NJS_VECTOR *vd)
{
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        ldl         t0, 7(%1)
        ldr         t0, 0(%1)
        
        lw          t1, 8(%1)
        
        pcpyld      t0, t1, t0
    
        qmtc2       t0, vf4
    
        lqc2        vf7, 0(%0)
        lqc2        vf8, 0x10(%0)
        lqc2        vf9, 0x20(%0)

        vmulax.xyz  ACC,  vf7, vf4
        
        vmadday.xyz ACC,  vf8, vf4
        vmaddz.xyz  vf18, vf9, vf4

        qmfc2       t0, vf18
    
        pcpyud      t1, t0, t0
    
        sdl         t0, 7(%2)
        sdr         t0, 0(%2)
        
        sw          t1, 8(%2)
    .set reorder
    " : : "r"(m), "r"(vs), "r"(vd) : 
    );
}

// 100% matching!
Float	njUnitVector(NJS_VECTOR *v)
{
	float ret;

    asm volatile
    ("
    .set noreorder
        ldl      a4, 0x7(%1)
        ldr      a4,   0(%1)
     
        lw       a5, NJS_VECTOR.z(%1) 
     
        pcpyld   a4, a5, a4
     
        qmtc2.ni a4, vf4
     
        vmul     vf5, vf4, vf4
     
        vaddy    vf5, vf5, vf5
        vaddz    vf5, vf5, vf5
     
        vrsqrt   Q, vf0w, vf5
     
        vwaitq   

        vmulq    vf6, vf4, Q
        vmulq    vf7, vf5, Q

        qmfc2.ni a6, vf6

        pcpyud   a7, a6, a6

        sdl      a6, 0x7(%1)
        sdr      a6,   0(%1)
     
        sw       a7, NJS_VECTOR.z(%1) 
     
        qmfc2.ni v0, vf7

        mtc1     v0, %0
    .set reorder
    " : "=r"(ret) : "r"(v) : 
    );

    return ret;
}

// 100% matching!
Float	njScalor(NJS_VECTOR *v)
{
	float ret;

    asm volatile
    ("
    .set noreorder
        ldl      a4, 0x7(%1)
        ldr      a4,   0(%1)
     
        lw       a5, NJS_VECTOR.z(%1) 
     
        pcpyld   a4, a5, a4
     
        qmtc2.ni a4, vf4
     
        vmul     vf5, vf4, vf4
     
        vaddy    vf5, vf5, vf5
        vaddz    vf5, vf5, vf5
     
        vsqrt    Q, vf5
     
        vwaitq   
     
        vaddq    vf6, vf0, Q
     
        qmfc2.ni v0, vf6

        mtc1     v0, %0
    .set reorder
    " : "=r"(ret) : "r"(v) : 
    );

    return ret;
}

// 100% matching!
Float	njScalor2(NJS_VECTOR *v)
{
	float ret;

    asm volatile
    ("
    .set noreorder
        ldl      a4, 0x7(%1)
        ldr      a4,   0(%1)
     
        lw       a5, NJS_VECTOR.z(%1) 
     
        pcpyld   a4, a5, a4
     
        qmtc2.ni a4, vf4
     
        vmul     vf5, vf4, vf4
     
        vaddy    vf5, vf5, vf5
        vaddz    vf6, vf5, vf5
     
        qmfc2.ni v0, vf6
        
        mtc1     v0, %0
    .set reorder
    " : "=r"(ret) : "r"(v) : 
    );

    return ret;
}

// 100% matching!
void	njProjectScreen(NJS_MATRIX *m, NJS_POINT3 *p3, NJS_POINT2 *p2)
{
    NJS_POINT3 Point;
    
    if (m == NULL)
    {
        m = pNaMatMatrixStuckPtr;
    }
    
    njMulMatrixCN(&NaViewScreenMatrix, m);
    
    njCalcPointCN(p3, &Point);
    
    asm volatile
    ("
    .set noreorder
        mfc1     t0, %2
        
        qmtc2    t0, vf4

        vdiv     Q, vf4x, vf18z

        lw       t1, fNaViwOffsetX
        lw       t2, fNaViwOffsetY
        
        qmtc2    t1, vf5
        qmtc2    t2, vf6

        vwaitq

        vaddq.z  vf8, vf0, Q

        vmulq.xy vf7, vf18, Q
        
        vaddx.x  vf8, vf7, vf5
        vaddx.y  vf8, vf7, vf6

        qmfc2    t0, vf8
    
        pcpyud   t1, t0, t0
    
        sdl      t0, 7(%0)
        sdr      t0, 0(%0)
        
        sw       t1, 8(%1)
    .set reorder
    " : : "r"(p2), "r"(&Point), "f"(_nj_screen_.dist) : 
    );
}

// 100% matching! 
Float	njOuterProduct(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *ov)
{
	float ret;

	asm volatile
    ("
    .set noreorder
        ldl      a4, 0x7(%1)
        ldr      a4,   0(%1)
     
        lw       a5, NJS_VECTOR.z(%1) 

        ldl      a6, 0x7(%2)
        ldr      a6,   0(%2)
     
        lw       a7, NJS_VECTOR.z(%2) 
     
        pcpyld   a4, a5, a4
        pcpyld   a6, a7, a6
     
        qmtc2.ni a4, vf4
        qmtc2.ni a6, vf5

        vopmula  ACC, vf4, vf5
        vopmsub  vf6, vf5, vf4
     
        vmul     vf7, vf6, vf6
     
        vaddy    vf7, vf7, vf7
        vaddz    vf7, vf7, vf7

        vsqrt    Q, vf7

        qmfc2.ni a4, vf6

        pcpyud   a5, a4, a4

        sdl      a4, 0x7(%3)
        sdr      a4,   0(%3)

        sw       a5, NJS_VECTOR.z(%3)

        vwaitq

        vaddq    vf8, vf0, Q
     
        qmfc2.ni v0, vf8
        
        mtc1     v0, %0
    .set reorder
    " : "=r"(ret) : "r"(v1), "r"(v2), "r"(ov) : 
    );

    return ret;
}

// 100% matching! 
Float	njInnerProduct(NJS_VECTOR *v1, NJS_VECTOR *v2)
{
	float ret;

	asm volatile
    ("
    .set noreorder
        ldl      a4, 0x7(%1)
        ldr      a4,   0(%1)
     
        lw       a5, NJS_VECTOR.z(%1) 

        ldl      a6, 0x7(%2)
        ldr      a6,   0(%2)
     
        lw       a7, NJS_VECTOR.z(%2) 
     
        pcpyld   a4, a5, a4
        pcpyld   a6, a7, a6
     
        qmtc2.ni a4, vf4
        qmtc2.ni a6, vf5
     
        vmul     vf6,  vf4, vf5
     
        vaddy    vf6,  vf6, vf6
        vaddz    vf14, vf6, vf6
     
        qmfc2.ni v0, vf14
        
        mtc1     v0, %0
    .set reorder
    " : "=r"(ret) : "r"(v1), "r"(v2) : 
    );

    return ret;
}

// 100% matching! 
void njTranslateEx(NJS_VECTOR *v)
{
    asm volatile
    ("
    .set noreorder
        ldl         a4, 0x7(%0)
        ldr         a4,   0(%0)

        lw          a5, NJS_VECTOR.z(%0) 

        pcpyld      a4, a5, a4

        qmtc2.ni    a4, vf4

        lqc2        vf28,    0(%1)
        lqc2        vf29, 0x10(%1)
        lqc2        vf30, 0x20(%1)
        lqc2        vf31, 0x30(%1)

        vmulax.xyz  ACC,  vf28, vf4
        
        vmadday.xyz ACC,  vf29, vf4
        vmaddaz.xyz ACC,  vf30, vf4
        vmaddw.xyz  vf31, vf31, vf0
    
        sqc2        vf31, 0x30(%1)
    .set reorder
    " : : "r"(v), "r"(pNaMatMatrixStuckPtr) : 
    );
}

// 100% matching! 
void njRotateEx( Angle *ang, Sint32 lv )
{
	if (lv != 0) 
    {
        njRotateY(NULL, ang[1]);
        njRotateX(NULL, ang[0]);
        njRotateZ(NULL, ang[2]);
    }
    else
    {
        njRotateZ(NULL, ang[2]);
        njRotateY(NULL, ang[1]);
        njRotateX(NULL, ang[0]);
    }
}

// 100% matching! 
void njScaleEx(NJS_VECTOR *v)
{
    asm volatile
    ("
    .set noreorder
        lqc2     vf28,    0(%1)
        lqc2     vf29, 0x10(%1)
        lqc2     vf30, 0x20(%1)
        
        ldl      a4, 0x7(%0)
        ldr      a4,   0(%0)
        
        lw       a5, NJS_VECTOR.z(%0) 
        
        pcpyld   a4, a5, a4
        
        qmtc2.ni a4, vf4
        
        vmulx    vf28, vf28, vf4
        vmuly    vf29, vf29, vf4
        vmulz    vf30, vf30, vf4
        
        sqc2     vf28,    0(%1)
        sqc2     vf29, 0x10(%1)
        sqc2     vf30, 0x20(%1)
    .set reorder
    " : : "r"(v), "r"(pNaMatMatrixStuckPtr) : 
    );
}

// 100% matching!
Bool njPushMatrixEx( void )
{
    njPushMatrix(NULL);
}

// 100% matching!
Bool njPopMatrixEx( void )
{
    njPopMatrix(1);
}

// 100% matching! 
void njRotTransPers(NJS_POINT3* pPoint, NJS_SCRVECTOR* pScreen)
{
	njMulMatrixCN(&NaViewScreenMatrix, NULL);

    njCalcPointCN(pPoint, (NJS_POINT3*)&pScreen->x);

    asm volatile
    ("
    .set noreorder
        vdiv     Q, vf0w, vf18z

        mfc1     t0, %2

        lw       t1, fNaViwOffsetX
        lw       t2, fNaViwOffsetY

        qmtc2    t0, vf4
        qmtc2    t1, vf5
        qmtc2    t2, vf6

        vwaitq

        vmulq.xy vf8,  vf4,  Q

        vaddq.z  vf14, vf0,  Q

        vmulx    vf8,  vf18, vf8
        
        vaddx.x  vf14, vf8,  vf5
        vaddx.y  vf14, vf8,  vf6

        qmfc2    a6, vf14
    
        pcpyud   a7, a6, a6
    
        sdl      a6, 7(%1)
        sdr      a6, 0(%1)
        
        sw       a7, NJS_SCRVECTOR.iz(%1)
    .set reorder
    " : : "r"(pPoint), "r"(pScreen), "f"(_nj_screen_.dist) : 
    );

    pScreen->fog = njCalcFogPower(pScreen->z);
}

// 100% matching!
void njRotTrans(NJS_POINT3* pPoint, NJS_POINT3* pOut)
{
	njMulMatrixCN(&NaViewScreenMatrix, NULL);
    
    njCalcPointCN(pPoint, pOut);
}

// 100% matching!
void njPers(NJS_SCRVECTOR* pScreen)
{
    asm volatile
    ("
    .set noreorder
        ldl      t0, 7(%0)
        ldr      t0, 0(%0)
        
        lw       t1, 8(%0)
        
        pcpyld   t0, t1, t0

        qmtc2    t0, vf18

        vdiv     Q, vf0w, vf18z

        mfc1     t0, %1

        lw       t1, fNaViwOffsetX
        lw       t2, fNaViwOffsetY

        qmtc2    t0, vf4
        qmtc2    t1, vf5
        qmtc2    t2, vf6

        vwaitq

        vmulq.x  vf8, vf4, Q

        vaddq.z  vf14, vf0, Q

        vmulx.xy vf8, vf18, vf8
        
        vaddx.x  vf14, vf8, vf5
        vaddx.y  vf14, vf8, vf6

        qmfc2    t2, vf14
    
        pcpyud   t3, t2, t2
    
        sdl      t2, 7(%0)
        sdr      t2, 0(%0)
        
        sw       t3, 12(%0)
    .set reorder
    " : : "r"(pScreen), "f"(_nj_screen_.dist) : 
    );
}

// 100% matching!
void njCopyMatrix(NJS_MATRIX* pDstMat, NJS_MATRIX* pSrcMat) 
{
    asm volatile
    ("
    .set noreorder
        lqc2 vf4, 0(%1) 
        lqc2 vf5, 0x10(%1) 
        lqc2 vf6, 0x20(%1) 
        lqc2 vf7, 0x30(%1) 
    
        sqc2 vf4, 0(%0) 
        sqc2 vf5, 0x10(%0) 
        sqc2 vf6, 0x20(%0) 
        sqc2 vf7, 0x30(%0) 
    .set reorder
    " : : "r"(pDstMat), "r"(pSrcMat) : 
    );
}

// 100% matching!
void njMulMatrixCN(NJS_MATRIX* pSrcMat1, NJS_MATRIX* pSrcMat2)
{
    if (pSrcMat2 == NULL)
    {
        pSrcMat2 = pNaMatMatrixStuckPtr;
    }

    asm volatile
    ("
    .set noreorder
        lqc2         vf4,  0(%0)
        lqc2         vf5,  0x10(%0)
        lqc2         vf6,  0x20(%0)
        lqc2         vf7,  0x30(%0)
        lqc2         vf8,  0(%1)
        lqc2         vf9,  0x10(%1)
        lqc2         vf10, 0x20(%1)
        lqc2         vf11, 0x30(%1)

        vmulax.xyzw  ACC,  vf4, vf8
        
        vmadday.xyzw ACC,  vf5, vf8
        vmaddz.xyzw  vf28, vf6, vf8
        
        vmulax.xyzw  ACC,  vf4, vf9

        vmadday.xyzw ACC,  vf5, vf9
        vmaddz.xyzw  vf29, vf6, vf9
        
        vmulax.xyzw  ACC,  vf4, vf10

        vmadday.xyzw ACC,  vf5, vf10
        vmaddz.xyzw  vf30, vf6, vf10
        
        vmulax.xyzw  ACC,  vf4, vf11

        vmadday.xyzw ACC,  vf5, vf11
        vmaddaz.xyzw ACC,  vf6, vf11
        vmaddw.xyzw  vf31, vf7, vf0
    .set reorder
    " : : "r"(pSrcMat1), "r"(pSrcMat2) : 
    );
}
