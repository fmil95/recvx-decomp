#include "ps2_NaMatrix.h"
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

// 
// Start address: 0x2d6860
void    njUnitTransPortion(NJS_MATRIX *m)
{
	// Line 556, Address: 0x2d6860, Func Offset: 0
	// Line 582, Address: 0x2d6874, Func Offset: 0x14
	// Line 589, Address: 0x2d6878, Func Offset: 0x18
	// Func End, Address: 0x2d6880, Func Offset: 0x20
	scePrintf("njUnitTransPortion - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d6880
void    njUnitRotPortion(NJS_MATRIX *m)
{
	// Line 618, Address: 0x2d6880, Func Offset: 0
	// Line 664, Address: 0x2d6894, Func Offset: 0x14
	// Line 665, Address: 0x2d6898, Func Offset: 0x18
	// Line 666, Address: 0x2d689c, Func Offset: 0x1c
	// Line 667, Address: 0x2d68a0, Func Offset: 0x20
	// Line 668, Address: 0x2d68a4, Func Offset: 0x24
	// Line 669, Address: 0x2d68a8, Func Offset: 0x28
	// Line 670, Address: 0x2d68ac, Func Offset: 0x2c
	// Line 677, Address: 0x2d68b0, Func Offset: 0x30
	// Func End, Address: 0x2d68b8, Func Offset: 0x38
	scePrintf("njUnitRotPortion - UNIMPLEMENTED!\n");
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

/*// 
// Start address: 0x2d6a60
void njSetMatrixCN(float pMat[16])
{
	// Line 1030, Address: 0x2d6a60, Func Offset: 0
	// Line 1031, Address: 0x2d6a64, Func Offset: 0x4
	// Line 1032, Address: 0x2d6a68, Func Offset: 0x8
	// Line 1033, Address: 0x2d6a6c, Func Offset: 0xc
	// Line 1038, Address: 0x2d6a70, Func Offset: 0x10
	// Func End, Address: 0x2d6a78, Func Offset: 0x18
}*/

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

/*// 
// Start address: 0x2d6ac0
void njMultiMatrix(float pDstMat[16], float pSrcMat[16])
{
	// Line 1220, Address: 0x2d6ac0, Func Offset: 0
	// Line 1324, Address: 0x2d6ad4, Func Offset: 0x14
	// Line 1325, Address: 0x2d6ad8, Func Offset: 0x18
	// Line 1326, Address: 0x2d6adc, Func Offset: 0x1c
	// Line 1327, Address: 0x2d6ae0, Func Offset: 0x20
	// Line 1328, Address: 0x2d6ae4, Func Offset: 0x24
	// Line 1329, Address: 0x2d6ae8, Func Offset: 0x28
	// Line 1330, Address: 0x2d6aec, Func Offset: 0x2c
	// Line 1331, Address: 0x2d6af0, Func Offset: 0x30
	// Line 1333, Address: 0x2d6af4, Func Offset: 0x34
	// Line 1334, Address: 0x2d6af8, Func Offset: 0x38
	// Line 1335, Address: 0x2d6afc, Func Offset: 0x3c
	// Line 1337, Address: 0x2d6b00, Func Offset: 0x40
	// Line 1338, Address: 0x2d6b04, Func Offset: 0x44
	// Line 1339, Address: 0x2d6b08, Func Offset: 0x48
	// Line 1341, Address: 0x2d6b0c, Func Offset: 0x4c
	// Line 1342, Address: 0x2d6b10, Func Offset: 0x50
	// Line 1343, Address: 0x2d6b14, Func Offset: 0x54
	// Line 1345, Address: 0x2d6b18, Func Offset: 0x58
	// Line 1346, Address: 0x2d6b1c, Func Offset: 0x5c
	// Line 1347, Address: 0x2d6b20, Func Offset: 0x60
	// Line 1348, Address: 0x2d6b24, Func Offset: 0x64
	// Line 1350, Address: 0x2d6b28, Func Offset: 0x68
	// Line 1351, Address: 0x2d6b2c, Func Offset: 0x6c
	// Line 1352, Address: 0x2d6b30, Func Offset: 0x70
	// Line 1353, Address: 0x2d6b34, Func Offset: 0x74
	// Line 1360, Address: 0x2d6b38, Func Offset: 0x78
	// Func End, Address: 0x2d6b40, Func Offset: 0x80
}*/

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

/*// 
// Start address: 0x2d6ba0
void njTranslateV(float pMatrix[16], _anon0* pVector)
{
	// Line 1611, Address: 0x2d6ba0, Func Offset: 0
	// Line 1667, Address: 0x2d6bb4, Func Offset: 0x14
	// Line 1668, Address: 0x2d6bb8, Func Offset: 0x18
	// Line 1669, Address: 0x2d6bbc, Func Offset: 0x1c
	// Line 1670, Address: 0x2d6bc0, Func Offset: 0x20
	// Line 1671, Address: 0x2d6bc4, Func Offset: 0x24
	// Line 1674, Address: 0x2d6bc8, Func Offset: 0x28
	// Line 1675, Address: 0x2d6bcc, Func Offset: 0x2c
	// Line 1676, Address: 0x2d6bd0, Func Offset: 0x30
	// Line 1677, Address: 0x2d6bd4, Func Offset: 0x34
	// Line 1678, Address: 0x2d6bd8, Func Offset: 0x38
	// Line 1679, Address: 0x2d6bdc, Func Offset: 0x3c
	// Line 1680, Address: 0x2d6be0, Func Offset: 0x40
	// Line 1681, Address: 0x2d6be4, Func Offset: 0x44
	// Line 1682, Address: 0x2d6be8, Func Offset: 0x48
	// Line 1689, Address: 0x2d6bec, Func Offset: 0x4c
	// Func End, Address: 0x2d6bf4, Func Offset: 0x54
}*/

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

// 
// Start address: 0x2d6db0
void	njRotateXYZ(NJS_MATRIX *m, Angle angx, Angle angy, Angle angz)
{
	// Line 2246, Address: 0x2d6db0, Func Offset: 0
	// Line 2247, Address: 0x2d6dcc, Func Offset: 0x1c
	// Line 2250, Address: 0x2d6de0, Func Offset: 0x30
	// Line 2251, Address: 0x2d6dec, Func Offset: 0x3c
	// Line 2252, Address: 0x2d6df8, Func Offset: 0x48
	// Line 2253, Address: 0x2d6e04, Func Offset: 0x54
	// Func End, Address: 0x2d6e1c, Func Offset: 0x6c
	scePrintf("njRotateXYZ - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d6e20
void njRotXYZ(NJS_MATRIX* pMatrix, int lAngleX, int lAngleY, int lAngleZ)
{
	float fCos;
	float fSin;
	// Line 2272, Address: 0x2d6e20, Func Offset: 0
	// Line 2279, Address: 0x2d6e3c, Func Offset: 0x1c
	// Line 2280, Address: 0x2d6e40, Func Offset: 0x20
	// Line 2288, Address: 0x2d6e54, Func Offset: 0x34
	// Line 2289, Address: 0x2d6e58, Func Offset: 0x38
	// Line 2290, Address: 0x2d6e5c, Func Offset: 0x3c
	// Line 2292, Address: 0x2d6e60, Func Offset: 0x40
	// Line 2294, Address: 0x2d6e64, Func Offset: 0x44
	// Line 2295, Address: 0x2d6e68, Func Offset: 0x48
	// Line 2296, Address: 0x2d6e6c, Func Offset: 0x4c
	// Line 2297, Address: 0x2d6e70, Func Offset: 0x50
	// Line 2299, Address: 0x2d6e74, Func Offset: 0x54
	// Line 2300, Address: 0x2d6e78, Func Offset: 0x58
	// Line 2305, Address: 0x2d6e7c, Func Offset: 0x5c
	// Line 2306, Address: 0x2d6e80, Func Offset: 0x60
	// Line 2309, Address: 0x2d6e90, Func Offset: 0x70
	// Line 2310, Address: 0x2d6e94, Func Offset: 0x74
	// Line 2311, Address: 0x2d6e98, Func Offset: 0x78
	// Line 2312, Address: 0x2d6e9c, Func Offset: 0x7c
	// Line 2313, Address: 0x2d6ea0, Func Offset: 0x80
	// Line 2314, Address: 0x2d6ea4, Func Offset: 0x84
	// Line 2315, Address: 0x2d6ea8, Func Offset: 0x88
	// Line 2319, Address: 0x2d6eac, Func Offset: 0x8c
	// Line 2320, Address: 0x2d6eb0, Func Offset: 0x90
	// Line 2323, Address: 0x2d6ec0, Func Offset: 0xa0
	// Line 2324, Address: 0x2d6ec4, Func Offset: 0xa4
	// Line 2325, Address: 0x2d6ec8, Func Offset: 0xa8
	// Line 2326, Address: 0x2d6ecc, Func Offset: 0xac
	// Line 2327, Address: 0x2d6ed0, Func Offset: 0xb0
	// Line 2328, Address: 0x2d6ed4, Func Offset: 0xb4
	// Line 2329, Address: 0x2d6ed8, Func Offset: 0xb8
	// Line 2330, Address: 0x2d6edc, Func Offset: 0xbc
	// Line 2331, Address: 0x2d6ee0, Func Offset: 0xc0
	// Line 2332, Address: 0x2d6ee4, Func Offset: 0xc4
	// Line 2335, Address: 0x2d6ee8, Func Offset: 0xc8
	// Func End, Address: 0x2d6f00, Func Offset: 0xe0
	scePrintf("njRotXYZ - UNIMPLEMENTED!\n");
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
}

// 
// Start address: 0x2d7060
void njScale(float pMatrix[16], float fScaleX, float fScaleY, float fScaleZ)
{
	// Line 2923, Address: 0x2d7060, Func Offset: 0
	// Line 2996, Address: 0x2d7074, Func Offset: 0x14
	// Line 2997, Address: 0x2d7078, Func Offset: 0x18
	// Line 2998, Address: 0x2d707c, Func Offset: 0x1c
	// Line 2999, Address: 0x2d7080, Func Offset: 0x20
	// Line 3000, Address: 0x2d7084, Func Offset: 0x24
	// Line 3001, Address: 0x2d7088, Func Offset: 0x28
	// Line 3002, Address: 0x2d708c, Func Offset: 0x2c
	// Line 3003, Address: 0x2d7090, Func Offset: 0x30
	// Line 3004, Address: 0x2d7094, Func Offset: 0x34
	// Line 3005, Address: 0x2d7098, Func Offset: 0x38
	// Line 3006, Address: 0x2d709c, Func Offset: 0x3c
	// Line 3007, Address: 0x2d70a0, Func Offset: 0x40
	// Line 3008, Address: 0x2d70a4, Func Offset: 0x44
	// Line 3009, Address: 0x2d70a8, Func Offset: 0x48
	// Line 3010, Address: 0x2d70ac, Func Offset: 0x4c
	// Line 3017, Address: 0x2d70b0, Func Offset: 0x50
	// Func End, Address: 0x2d70b8, Func Offset: 0x58
}

// 
// Start address: 0x2d70c0
void njScaleV(float pMatrix[16], _anon0* pScale)
{
	// Line 3059, Address: 0x2d70c0, Func Offset: 0
	// Line 3132, Address: 0x2d70d4, Func Offset: 0x14
	// Line 3133, Address: 0x2d70d8, Func Offset: 0x18
	// Line 3134, Address: 0x2d70dc, Func Offset: 0x1c
	// Line 3135, Address: 0x2d70e0, Func Offset: 0x20
	// Line 3136, Address: 0x2d70e4, Func Offset: 0x24
	// Line 3138, Address: 0x2d70e8, Func Offset: 0x28
	// Line 3139, Address: 0x2d70ec, Func Offset: 0x2c
	// Line 3140, Address: 0x2d70f0, Func Offset: 0x30
	// Line 3141, Address: 0x2d70f4, Func Offset: 0x34
	// Line 3142, Address: 0x2d70f8, Func Offset: 0x38
	// Line 3143, Address: 0x2d70fc, Func Offset: 0x3c
	// Line 3144, Address: 0x2d7100, Func Offset: 0x40
	// Line 3145, Address: 0x2d7104, Func Offset: 0x44
	// Line 3146, Address: 0x2d7108, Func Offset: 0x48
	// Line 3153, Address: 0x2d710c, Func Offset: 0x4c
	// Func End, Address: 0x2d7114, Func Offset: 0x54
}

// 
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
}

// 
// Start address: 0x2d7210
static float njAtan2b(float a, float b)
{
	// Line 3657, Address: 0x2d7210, Func Offset: 0
	// Func End, Address: 0x2d725c, Func Offset: 0x4c
}*/

// 
// Start address: 0x2d7260
void	njMirror(NJS_MATRIX *m,NJS_PLANE *pl)
{
	int lAngleZ;
	int lAngleX;
	//float mat[16];
	// Line 3662, Address: 0x2d7260, Func Offset: 0
	// Line 3698, Address: 0x2d7278, Func Offset: 0x18
	// Line 4005, Address: 0x2d728c, Func Offset: 0x2c
	// Line 4008, Address: 0x2d7298, Func Offset: 0x38
	// Line 4009, Address: 0x2d729c, Func Offset: 0x3c
	// Line 4010, Address: 0x2d72a0, Func Offset: 0x40
	// Line 4011, Address: 0x2d72a4, Func Offset: 0x44
	// Line 4012, Address: 0x2d72a8, Func Offset: 0x48
	// Line 4013, Address: 0x2d72ac, Func Offset: 0x4c
	// Line 4014, Address: 0x2d72b0, Func Offset: 0x50
	// Line 4015, Address: 0x2d72b4, Func Offset: 0x54
	// Line 4016, Address: 0x2d72b8, Func Offset: 0x58
	// Line 4017, Address: 0x2d72bc, Func Offset: 0x5c
	// Line 4018, Address: 0x2d72c0, Func Offset: 0x60
	// Line 4019, Address: 0x2d72c4, Func Offset: 0x64
	// Line 4020, Address: 0x2d72c8, Func Offset: 0x68
	// Line 4021, Address: 0x2d72cc, Func Offset: 0x6c
	// Line 4022, Address: 0x2d72d0, Func Offset: 0x70
	// Line 4023, Address: 0x2d72d4, Func Offset: 0x74
	// Line 4024, Address: 0x2d72d8, Func Offset: 0x78
	// Line 4025, Address: 0x2d72dc, Func Offset: 0x7c
	// Line 4026, Address: 0x2d72e0, Func Offset: 0x80
	// Line 4027, Address: 0x2d72e4, Func Offset: 0x84
	// Line 4028, Address: 0x2d72e8, Func Offset: 0x88
	// Line 4029, Address: 0x2d72ec, Func Offset: 0x8c
	// Line 4030, Address: 0x2d72f0, Func Offset: 0x90
	// Line 4031, Address: 0x2d72f4, Func Offset: 0x94
	// Line 4032, Address: 0x2d72f8, Func Offset: 0x98
	// Line 4033, Address: 0x2d72fc, Func Offset: 0x9c
	// Line 4034, Address: 0x2d7300, Func Offset: 0xa0
	// Line 4036, Address: 0x2d7308, Func Offset: 0xa8
	// Line 4037, Address: 0x2d730c, Func Offset: 0xac
	// Line 4038, Address: 0x2d7310, Func Offset: 0xb0
	// Line 4039, Address: 0x2d7314, Func Offset: 0xb4
	// Line 4040, Address: 0x2d7318, Func Offset: 0xb8
	// Line 4041, Address: 0x2d731c, Func Offset: 0xbc
	// Line 4042, Address: 0x2d7320, Func Offset: 0xc0
	// Line 4043, Address: 0x2d7324, Func Offset: 0xc4
	// Line 4046, Address: 0x2d732c, Func Offset: 0xcc
	// Line 4047, Address: 0x2d7330, Func Offset: 0xd0
	// Line 4048, Address: 0x2d7334, Func Offset: 0xd4
	// Line 4049, Address: 0x2d7338, Func Offset: 0xd8
	// Line 4050, Address: 0x2d733c, Func Offset: 0xdc
	// Line 4051, Address: 0x2d7340, Func Offset: 0xe0
	// Line 4053, Address: 0x2d7348, Func Offset: 0xe8
	// Line 4054, Address: 0x2d7350, Func Offset: 0xf0
	// Line 4055, Address: 0x2d7354, Func Offset: 0xf4
	// Line 4056, Address: 0x2d7358, Func Offset: 0xf8
	// Line 4057, Address: 0x2d735c, Func Offset: 0xfc
	// Line 4059, Address: 0x2d7364, Func Offset: 0x104
	// Line 4061, Address: 0x2d736c, Func Offset: 0x10c
	// Line 4064, Address: 0x2d7374, Func Offset: 0x114
	// Line 4065, Address: 0x2d7378, Func Offset: 0x118
	// Line 4066, Address: 0x2d737c, Func Offset: 0x11c
	// Line 4067, Address: 0x2d7380, Func Offset: 0x120
	// Line 4068, Address: 0x2d7384, Func Offset: 0x124
	// Line 4069, Address: 0x2d7388, Func Offset: 0x128
	// Line 4070, Address: 0x2d738c, Func Offset: 0x12c
	// Line 4071, Address: 0x2d7390, Func Offset: 0x130
	// Line 4072, Address: 0x2d7394, Func Offset: 0x134
	// Line 4073, Address: 0x2d7398, Func Offset: 0x138
	// Line 4074, Address: 0x2d739c, Func Offset: 0x13c
	// Line 4076, Address: 0x2d73a4, Func Offset: 0x144
	// Line 4077, Address: 0x2d73a8, Func Offset: 0x148
	// Line 4078, Address: 0x2d73ac, Func Offset: 0x14c
	// Line 4079, Address: 0x2d73b0, Func Offset: 0x150
	// Line 4080, Address: 0x2d73b4, Func Offset: 0x154
	// Line 4081, Address: 0x2d73b8, Func Offset: 0x158
	// Line 4082, Address: 0x2d73bc, Func Offset: 0x15c
	// Line 4083, Address: 0x2d73c0, Func Offset: 0x160
	// Line 4084, Address: 0x2d73c4, Func Offset: 0x164
	// Line 4085, Address: 0x2d73c8, Func Offset: 0x168
	// Line 4086, Address: 0x2d73cc, Func Offset: 0x16c
	// Line 4087, Address: 0x2d73d0, Func Offset: 0x170
	// Line 4088, Address: 0x2d73d4, Func Offset: 0x174
	// Line 4089, Address: 0x2d73d8, Func Offset: 0x178
	// Line 4090, Address: 0x2d73dc, Func Offset: 0x17c
	// Line 4091, Address: 0x2d73e0, Func Offset: 0x180
	// Line 4092, Address: 0x2d73e4, Func Offset: 0x184
	// Line 4093, Address: 0x2d73e8, Func Offset: 0x188
	// Line 4094, Address: 0x2d73ec, Func Offset: 0x18c
	// Line 4095, Address: 0x2d73f0, Func Offset: 0x190
	// Line 4096, Address: 0x2d73f4, Func Offset: 0x194
	// Line 4097, Address: 0x2d73f8, Func Offset: 0x198
	// Line 4098, Address: 0x2d73fc, Func Offset: 0x19c
	// Line 4099, Address: 0x2d7400, Func Offset: 0x1a0
	// Line 4100, Address: 0x2d7404, Func Offset: 0x1a4
	// Line 4101, Address: 0x2d7408, Func Offset: 0x1a8
	// Line 4102, Address: 0x2d740c, Func Offset: 0x1ac
	// Line 4103, Address: 0x2d7410, Func Offset: 0x1b0
	// Line 4105, Address: 0x2d7418, Func Offset: 0x1b8
	// Line 4106, Address: 0x2d741c, Func Offset: 0x1bc
	// Line 4107, Address: 0x2d7420, Func Offset: 0x1c0
	// Line 4108, Address: 0x2d7424, Func Offset: 0x1c4
	// Line 4109, Address: 0x2d7428, Func Offset: 0x1c8
	// Line 4110, Address: 0x2d742c, Func Offset: 0x1cc
	// Line 4111, Address: 0x2d7430, Func Offset: 0x1d0
	// Line 4112, Address: 0x2d7434, Func Offset: 0x1d4
	// Line 4113, Address: 0x2d7438, Func Offset: 0x1d8
	// Line 4114, Address: 0x2d743c, Func Offset: 0x1dc
	// Line 4115, Address: 0x2d7440, Func Offset: 0x1e0
	// Line 4116, Address: 0x2d7444, Func Offset: 0x1e4
	// Line 4117, Address: 0x2d7448, Func Offset: 0x1e8
	// Line 4118, Address: 0x2d744c, Func Offset: 0x1ec
	// Line 4129, Address: 0x2d7450, Func Offset: 0x1f0
	// Line 4130, Address: 0x2d7458, Func Offset: 0x1f8
	// Line 4131, Address: 0x2d7464, Func Offset: 0x204
	// Line 4132, Address: 0x2d7470, Func Offset: 0x210
	// Line 4133, Address: 0x2d748c, Func Offset: 0x22c
	// Line 4134, Address: 0x2d749c, Func Offset: 0x23c
	// Line 4135, Address: 0x2d74ac, Func Offset: 0x24c
	// Line 4136, Address: 0x2d74b8, Func Offset: 0x258
	// Func End, Address: 0x2d74d0, Func Offset: 0x270
	scePrintf("njMirror - UNIMPLEMENTED!\n");
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

/*// 
// Start address: 0x2d75d0
void njAddVector(_anon0* pDstVec, _anon0* pSrcVec)
{
	// Line 4354, Address: 0x2d75d0, Func Offset: 0
	// Line 4355, Address: 0x2d75d4, Func Offset: 0x4
	// Line 4356, Address: 0x2d75d8, Func Offset: 0x8
	// Line 4357, Address: 0x2d75dc, Func Offset: 0xc
	// Line 4358, Address: 0x2d75e0, Func Offset: 0x10
	// Line 4359, Address: 0x2d75e4, Func Offset: 0x14
	// Line 4360, Address: 0x2d75e8, Func Offset: 0x18
	// Line 4361, Address: 0x2d75ec, Func Offset: 0x1c
	// Line 4362, Address: 0x2d75f0, Func Offset: 0x20
	// Line 4363, Address: 0x2d75f4, Func Offset: 0x24
	// Line 4364, Address: 0x2d75f8, Func Offset: 0x28
	// Line 4365, Address: 0x2d75fc, Func Offset: 0x2c
	// Line 4370, Address: 0x2d7600, Func Offset: 0x30
	// Func End, Address: 0x2d7608, Func Offset: 0x38
}

// 
// Start address: 0x2d7610
void njSubVector(_anon0* pDstVec, _anon0* pSrcVec)
{
	// Line 4414, Address: 0x2d7610, Func Offset: 0
	// Line 4415, Address: 0x2d7614, Func Offset: 0x4
	// Line 4416, Address: 0x2d7618, Func Offset: 0x8
	// Line 4417, Address: 0x2d761c, Func Offset: 0xc
	// Line 4418, Address: 0x2d7620, Func Offset: 0x10
	// Line 4419, Address: 0x2d7624, Func Offset: 0x14
	// Line 4420, Address: 0x2d7628, Func Offset: 0x18
	// Line 4421, Address: 0x2d762c, Func Offset: 0x1c
	// Line 4422, Address: 0x2d7630, Func Offset: 0x20
	// Line 4423, Address: 0x2d7634, Func Offset: 0x24
	// Line 4424, Address: 0x2d7638, Func Offset: 0x28
	// Line 4425, Address: 0x2d763c, Func Offset: 0x2c
	// Line 4430, Address: 0x2d7640, Func Offset: 0x30
	// Func End, Address: 0x2d7648, Func Offset: 0x38
}*/

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

/*// 
// Start address: 0x2d76b0
float njUnitVector(_anon0* pVector)
{
	float ret;
	// Line 4662, Address: 0x2d76b0, Func Offset: 0
	// Line 4663, Address: 0x2d76b4, Func Offset: 0x4
	// Line 4664, Address: 0x2d76b8, Func Offset: 0x8
	// Line 4665, Address: 0x2d76bc, Func Offset: 0xc
	// Line 4666, Address: 0x2d76c0, Func Offset: 0x10
	// Line 4668, Address: 0x2d76c4, Func Offset: 0x14
	// Line 4669, Address: 0x2d76c8, Func Offset: 0x18
	// Line 4670, Address: 0x2d76cc, Func Offset: 0x1c
	// Line 4672, Address: 0x2d76d0, Func Offset: 0x20
	// Line 4673, Address: 0x2d76d4, Func Offset: 0x24
	// Line 4674, Address: 0x2d76d8, Func Offset: 0x28
	// Line 4675, Address: 0x2d76dc, Func Offset: 0x2c
	// Line 4677, Address: 0x2d76e0, Func Offset: 0x30
	// Line 4678, Address: 0x2d76e4, Func Offset: 0x34
	// Line 4679, Address: 0x2d76e8, Func Offset: 0x38
	// Line 4680, Address: 0x2d76ec, Func Offset: 0x3c
	// Line 4681, Address: 0x2d76f0, Func Offset: 0x40
	// Line 4682, Address: 0x2d76f4, Func Offset: 0x44
	// Line 4683, Address: 0x2d76f8, Func Offset: 0x48
	// Line 4689, Address: 0x2d76fc, Func Offset: 0x4c
	// Func End, Address: 0x2d7704, Func Offset: 0x54
}

// 
// Start address: 0x2d7710
float njScalor(_anon0* pVector)
{
	float ret;
	// Line 4740, Address: 0x2d7710, Func Offset: 0
	// Line 4741, Address: 0x2d7714, Func Offset: 0x4
	// Line 4742, Address: 0x2d7718, Func Offset: 0x8
	// Line 4743, Address: 0x2d771c, Func Offset: 0xc
	// Line 4744, Address: 0x2d7720, Func Offset: 0x10
	// Line 4745, Address: 0x2d7724, Func Offset: 0x14
	// Line 4746, Address: 0x2d7728, Func Offset: 0x18
	// Line 4747, Address: 0x2d772c, Func Offset: 0x1c
	// Line 4748, Address: 0x2d7730, Func Offset: 0x20
	// Line 4749, Address: 0x2d7734, Func Offset: 0x24
	// Line 4750, Address: 0x2d7738, Func Offset: 0x28
	// Line 4751, Address: 0x2d773c, Func Offset: 0x2c
	// Line 4752, Address: 0x2d7740, Func Offset: 0x30
	// Line 4758, Address: 0x2d7744, Func Offset: 0x34
	// Func End, Address: 0x2d774c, Func Offset: 0x3c
}

// 
// Start address: 0x2d7750
float njScalor2(_anon0* pVector)
{
	float ret;
	// Line 4807, Address: 0x2d7750, Func Offset: 0
	// Line 4808, Address: 0x2d7754, Func Offset: 0x4
	// Line 4809, Address: 0x2d7758, Func Offset: 0x8
	// Line 4810, Address: 0x2d775c, Func Offset: 0xc
	// Line 4811, Address: 0x2d7760, Func Offset: 0x10
	// Line 4812, Address: 0x2d7764, Func Offset: 0x14
	// Line 4813, Address: 0x2d7768, Func Offset: 0x18
	// Line 4814, Address: 0x2d776c, Func Offset: 0x1c
	// Line 4815, Address: 0x2d7770, Func Offset: 0x20
	// Line 4816, Address: 0x2d7774, Func Offset: 0x24
	// Line 4822, Address: 0x2d7778, Func Offset: 0x28
	// Func End, Address: 0x2d7780, Func Offset: 0x30
}*/

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

/*// 
// Start address: 0x2d7830
float njOuterProduct(_anon0* pSrcVec1, _anon0* pSrcVec2, _anon0* pDstVec)
{
	float ret;
	// Line 4937, Address: 0x2d7830, Func Offset: 0
	// Line 4938, Address: 0x2d7834, Func Offset: 0x4
	// Line 4939, Address: 0x2d7838, Func Offset: 0x8
	// Line 4940, Address: 0x2d783c, Func Offset: 0xc
	// Line 4941, Address: 0x2d7840, Func Offset: 0x10
	// Line 4942, Address: 0x2d7844, Func Offset: 0x14
	// Line 4943, Address: 0x2d7848, Func Offset: 0x18
	// Line 4944, Address: 0x2d784c, Func Offset: 0x1c
	// Line 4945, Address: 0x2d7850, Func Offset: 0x20
	// Line 4946, Address: 0x2d7854, Func Offset: 0x24
	// Line 4948, Address: 0x2d7858, Func Offset: 0x28
	// Line 4949, Address: 0x2d785c, Func Offset: 0x2c
	// Line 4951, Address: 0x2d7860, Func Offset: 0x30
	// Line 4952, Address: 0x2d7864, Func Offset: 0x34
	// Line 4953, Address: 0x2d7868, Func Offset: 0x38
	// Line 4954, Address: 0x2d786c, Func Offset: 0x3c
	// Line 4956, Address: 0x2d7870, Func Offset: 0x40
	// Line 4957, Address: 0x2d7874, Func Offset: 0x44
	// Line 4958, Address: 0x2d7878, Func Offset: 0x48
	// Line 4959, Address: 0x2d787c, Func Offset: 0x4c
	// Line 4960, Address: 0x2d7880, Func Offset: 0x50
	// Line 4962, Address: 0x2d7884, Func Offset: 0x54
	// Line 4963, Address: 0x2d7888, Func Offset: 0x58
	// Line 4964, Address: 0x2d788c, Func Offset: 0x5c
	// Line 4965, Address: 0x2d7890, Func Offset: 0x60
	// Line 4971, Address: 0x2d7894, Func Offset: 0x64
	// Func End, Address: 0x2d789c, Func Offset: 0x6c
}

// 
// Start address: 0x2d78a0
float njInnerProduct(_anon0* pVec1, _anon0* pVec2)
{
	float ret;
	// Line 5031, Address: 0x2d78a0, Func Offset: 0
	// Line 5032, Address: 0x2d78a4, Func Offset: 0x4
	// Line 5033, Address: 0x2d78a8, Func Offset: 0x8
	// Line 5034, Address: 0x2d78ac, Func Offset: 0xc
	// Line 5035, Address: 0x2d78b0, Func Offset: 0x10
	// Line 5036, Address: 0x2d78b4, Func Offset: 0x14
	// Line 5037, Address: 0x2d78b8, Func Offset: 0x18
	// Line 5038, Address: 0x2d78bc, Func Offset: 0x1c
	// Line 5039, Address: 0x2d78c0, Func Offset: 0x20
	// Line 5040, Address: 0x2d78c4, Func Offset: 0x24
	// Line 5042, Address: 0x2d78c8, Func Offset: 0x28
	// Line 5043, Address: 0x2d78cc, Func Offset: 0x2c
	// Line 5044, Address: 0x2d78d0, Func Offset: 0x30
	// Line 5045, Address: 0x2d78d4, Func Offset: 0x34
	// Line 5046, Address: 0x2d78d8, Func Offset: 0x38
	// Line 5052, Address: 0x2d78dc, Func Offset: 0x3c
	// Func End, Address: 0x2d78e4, Func Offset: 0x44
}*/

// 
// Start address: 0x2d78f0
void njTranslateEx(NJS_VECTOR *v)
{
	// Line 5152, Address: 0x2d78f0, Func Offset: 0
	// Line 5155, Address: 0x2d78fc, Func Offset: 0xc
	// Line 5156, Address: 0x2d7900, Func Offset: 0x10
	// Line 5157, Address: 0x2d7904, Func Offset: 0x14
	// Line 5158, Address: 0x2d7908, Func Offset: 0x18
	// Line 5159, Address: 0x2d790c, Func Offset: 0x1c
	// Line 5161, Address: 0x2d7910, Func Offset: 0x20
	// Line 5162, Address: 0x2d7914, Func Offset: 0x24
	// Line 5163, Address: 0x2d7918, Func Offset: 0x28
	// Line 5164, Address: 0x2d791c, Func Offset: 0x2c
	// Line 5166, Address: 0x2d7920, Func Offset: 0x30
	// Line 5167, Address: 0x2d7924, Func Offset: 0x34
	// Line 5168, Address: 0x2d7928, Func Offset: 0x38
	// Line 5169, Address: 0x2d792c, Func Offset: 0x3c
	// Line 5171, Address: 0x2d7930, Func Offset: 0x40
	// Line 5178, Address: 0x2d7934, Func Offset: 0x44
	// Func End, Address: 0x2d793c, Func Offset: 0x4c
	scePrintf("njTranslateEx - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d7940
void njRotateEx( Angle *ang, Sint32 lv )
{
	// Line 5240, Address: 0x2d7940, Func Offset: 0
	// Line 5241, Address: 0x2d794c, Func Offset: 0xc
	// Line 5242, Address: 0x2d7954, Func Offset: 0x14
	// Line 5243, Address: 0x2d7960, Func Offset: 0x20
	// Line 5244, Address: 0x2d796c, Func Offset: 0x2c
	// Line 5245, Address: 0x2d7978, Func Offset: 0x38
	// Line 5246, Address: 0x2d7980, Func Offset: 0x40
	// Line 5247, Address: 0x2d798c, Func Offset: 0x4c
	// Line 5248, Address: 0x2d7998, Func Offset: 0x58
	// Line 5250, Address: 0x2d79a4, Func Offset: 0x64
	// Func End, Address: 0x2d79b4, Func Offset: 0x74
	scePrintf("njRotateEx - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d79c0
void njScaleEx(NJS_VECTOR *v)
{
	// Line 5351, Address: 0x2d79c0, Func Offset: 0
	// Line 5354, Address: 0x2d79cc, Func Offset: 0xc
	// Line 5355, Address: 0x2d79d0, Func Offset: 0x10
	// Line 5356, Address: 0x2d79d4, Func Offset: 0x14
	// Line 5358, Address: 0x2d79d8, Func Offset: 0x18
	// Line 5359, Address: 0x2d79dc, Func Offset: 0x1c
	// Line 5360, Address: 0x2d79e0, Func Offset: 0x20
	// Line 5361, Address: 0x2d79e4, Func Offset: 0x24
	// Line 5362, Address: 0x2d79e8, Func Offset: 0x28
	// Line 5364, Address: 0x2d79ec, Func Offset: 0x2c
	// Line 5365, Address: 0x2d79f0, Func Offset: 0x30
	// Line 5366, Address: 0x2d79f4, Func Offset: 0x34
	// Line 5368, Address: 0x2d79f8, Func Offset: 0x38
	// Line 5369, Address: 0x2d79fc, Func Offset: 0x3c
	// Line 5370, Address: 0x2d7a00, Func Offset: 0x40
	// Line 5377, Address: 0x2d7a04, Func Offset: 0x44
	// Func End, Address: 0x2d7a0c, Func Offset: 0x4c
	scePrintf("njScaleEx - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d7a10
Bool njPushMatrixEx( void )
{
	// Line 5439, Address: 0x2d7a10, Func Offset: 0
	// Func End, Address: 0x2d7a18, Func Offset: 0x8
	scePrintf("njPushMatrixEx - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d7a20
Bool njPopMatrixEx( void )
{
	// Line 5459, Address: 0x2d7a20, Func Offset: 0
	// Func End, Address: 0x2d7a28, Func Offset: 0x8
	scePrintf("njPopMatrixEx - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d7a30
void njRotTransPers(NJS_POINT3* pPoint, NJS_SCRVECTOR* pScreen)
{
	// Line 5788, Address: 0x2d7a30, Func Offset: 0
	// Line 5794, Address: 0x2d7a48, Func Offset: 0x18
	// Line 5795, Address: 0x2d7a58, Func Offset: 0x28
	// Line 5805, Address: 0x2d7a64, Func Offset: 0x34
	// Line 5808, Address: 0x2d7a70, Func Offset: 0x40
	// Line 5809, Address: 0x2d7a74, Func Offset: 0x44
	// Line 5810, Address: 0x2d7a78, Func Offset: 0x48
	// Line 5811, Address: 0x2d7a80, Func Offset: 0x50
	// Line 5812, Address: 0x2d7a88, Func Offset: 0x58
	// Line 5813, Address: 0x2d7a8c, Func Offset: 0x5c
	// Line 5814, Address: 0x2d7a90, Func Offset: 0x60
	// Line 5815, Address: 0x2d7a94, Func Offset: 0x64
	// Line 5816, Address: 0x2d7a98, Func Offset: 0x68
	// Line 5817, Address: 0x2d7a9c, Func Offset: 0x6c
	// Line 5818, Address: 0x2d7aa0, Func Offset: 0x70
	// Line 5819, Address: 0x2d7aa4, Func Offset: 0x74
	// Line 5820, Address: 0x2d7aa8, Func Offset: 0x78
	// Line 5821, Address: 0x2d7aac, Func Offset: 0x7c
	// Line 5822, Address: 0x2d7ab0, Func Offset: 0x80
	// Line 5823, Address: 0x2d7ab4, Func Offset: 0x84
	// Line 5824, Address: 0x2d7ab8, Func Offset: 0x88
	// Line 5825, Address: 0x2d7abc, Func Offset: 0x8c
	// Line 5830, Address: 0x2d7ac0, Func Offset: 0x90
	// Line 5832, Address: 0x2d7acc, Func Offset: 0x9c
	// Func End, Address: 0x2d7ae0, Func Offset: 0xb0
	scePrintf("njRotTransPers - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2d7ae0
void njRotTrans(_anon0* pPoint, _anon0* pOut)
{
	// Line 5840, Address: 0x2d7ae0, Func Offset: 0
	// Line 5842, Address: 0x2d7af8, Func Offset: 0x18
	// Line 5843, Address: 0x2d7b08, Func Offset: 0x28
	// Line 5844, Address: 0x2d7b14, Func Offset: 0x34
	// Func End, Address: 0x2d7b28, Func Offset: 0x48
}

// 
// Start address: 0x2d7b30
void njPers(tagNJS_SCRVECTOR* pScreen)
{
	// Line 5859, Address: 0x2d7b30, Func Offset: 0
	// Line 5862, Address: 0x2d7b3c, Func Offset: 0xc
	// Line 5863, Address: 0x2d7b40, Func Offset: 0x10
	// Line 5864, Address: 0x2d7b44, Func Offset: 0x14
	// Line 5865, Address: 0x2d7b48, Func Offset: 0x18
	// Line 5866, Address: 0x2d7b4c, Func Offset: 0x1c
	// Line 5868, Address: 0x2d7b50, Func Offset: 0x20
	// Line 5869, Address: 0x2d7b54, Func Offset: 0x24
	// Line 5870, Address: 0x2d7b58, Func Offset: 0x28
	// Line 5871, Address: 0x2d7b60, Func Offset: 0x30
	// Line 5872, Address: 0x2d7b68, Func Offset: 0x38
	// Line 5873, Address: 0x2d7b6c, Func Offset: 0x3c
	// Line 5874, Address: 0x2d7b70, Func Offset: 0x40
	// Line 5875, Address: 0x2d7b74, Func Offset: 0x44
	// Line 5876, Address: 0x2d7b78, Func Offset: 0x48
	// Line 5877, Address: 0x2d7b7c, Func Offset: 0x4c
	// Line 5878, Address: 0x2d7b80, Func Offset: 0x50
	// Line 5879, Address: 0x2d7b84, Func Offset: 0x54
	// Line 5880, Address: 0x2d7b88, Func Offset: 0x58
	// Line 5881, Address: 0x2d7b8c, Func Offset: 0x5c
	// Line 5882, Address: 0x2d7b90, Func Offset: 0x60
	// Line 5883, Address: 0x2d7b94, Func Offset: 0x64
	// Line 5884, Address: 0x2d7b98, Func Offset: 0x68
	// Line 5885, Address: 0x2d7b9c, Func Offset: 0x6c
	// Line 5890, Address: 0x2d7ba0, Func Offset: 0x70
	// Func End, Address: 0x2d7ba8, Func Offset: 0x78
}

// 
// Start address: 0x2d7bb0
void njCopyMatrix(float pDstMat[16], float pSrcMat[16])
{
	// Line 5984, Address: 0x2d7bb0, Func Offset: 0
	// Line 5985, Address: 0x2d7bb4, Func Offset: 0x4
	// Line 5986, Address: 0x2d7bb8, Func Offset: 0x8
	// Line 5987, Address: 0x2d7bbc, Func Offset: 0xc
	// Line 5988, Address: 0x2d7bc0, Func Offset: 0x10
	// Line 5989, Address: 0x2d7bc4, Func Offset: 0x14
	// Line 5990, Address: 0x2d7bc8, Func Offset: 0x18
	// Line 5991, Address: 0x2d7bcc, Func Offset: 0x1c
	// Line 5996, Address: 0x2d7bd0, Func Offset: 0x20
	// Func End, Address: 0x2d7bd8, Func Offset: 0x28
}*/

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
