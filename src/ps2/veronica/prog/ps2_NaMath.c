#include "ps2_NaMath.h"
#include "main.h"

static float SinTable[16384];

/*void _Make_SinTable();
float njSin(int lAngle);
float njCos(int lAngle);
void njSinCos(int lAngle, float* sin, float* cos);
float njFraction(float fN);
float njSqrt(float x);
float njInvertSqrt(float x);
void njLinear(float* fpIdata, float* fpOdata, float fFrame);
void njOverhauserSpline(float* fpIdata, float* fpOdata, _anon0* pAttr, float fT);
void njBezierSpline(float* fpIdata, float* fpOdata, _anon0* pAttr, float fFrame);
unsigned int njFactorial(unsigned int ulN);*/

// 100% matching! 
void _Make_SinTable()
{ 
    int i;

    for (i = 0; i < 16384; i++) 
    { 
        SinTable[i] = sinf(0.0000958738f * i); 
    } 
}  

// 100% matching!
Float	njSin(Angle n)
{
    float ret;
    
    asm volatile 
    ("
    .set noreorder
        move  v0, %0
        
        lw    t0, 0(%1)
        
        addi  t2, zero, 16383
    
        andi  t3, t0, 0x4000
        
        beqz  t3, l_002D7D08
        
        and   t1, t0, t2
    
        sub   t2, t2, t1
    
        muli  t2, t2, 4
    
        add   t2, t2, %2
        
        lwc1  f4, 0(t2)
        
        neg.s f6, f4
        
        mfc1  %2, f6
        
        andi  t0, t0, 0x8000
    
        mfc1  t6, f4
        
        b     l_002D7D30
    
        movz  %2, t6, t0

        l_002D7D08:
        muli  t1, t1, 4
        
        add   t1, t1, %2
        
        lwc1  f4, 0(t1)
        
        neg.s f6, f4
        
        mfc1  %2, f4
        mfc1  t6, f6
    
        andi  t0, t0, 0x8000
        
        movn  %2, t6, t0

        l_002D7D30:
        mtc1  %2, f0
    .set reorder
    " : "=r"(ret) : "r"(&n), "r"(SinTable) : 
    );
}

// 
// Start address: 0x2d7d40
Float	njCos(Angle n)
{
	float ret;
	// Line 172, Address: 0x2d7d40, Func Offset: 0
	// Line 208, Address: 0x2d7d44, Func Offset: 0x4
	// Line 172, Address: 0x2d7d50, Func Offset: 0x10
	// Line 210, Address: 0x2d7d54, Func Offset: 0x14
	// Line 211, Address: 0x2d7d58, Func Offset: 0x18
	// Line 212, Address: 0x2d7d5c, Func Offset: 0x1c
	// Line 213, Address: 0x2d7d60, Func Offset: 0x20
	// Line 215, Address: 0x2d7d68, Func Offset: 0x28
	// Line 216, Address: 0x2d7d74, Func Offset: 0x34
	// Line 217, Address: 0x2d7d78, Func Offset: 0x38
	// Line 218, Address: 0x2d7d7c, Func Offset: 0x3c
	// Line 219, Address: 0x2d7d80, Func Offset: 0x40
	// Line 220, Address: 0x2d7d84, Func Offset: 0x44
	// Line 221, Address: 0x2d7d88, Func Offset: 0x48
	// Line 222, Address: 0x2d7d8c, Func Offset: 0x4c
	// Line 225, Address: 0x2d7d94, Func Offset: 0x54
	// Line 226, Address: 0x2d7d98, Func Offset: 0x58
	// Line 227, Address: 0x2d7da4, Func Offset: 0x64
	// Line 228, Address: 0x2d7da8, Func Offset: 0x68
	// Line 229, Address: 0x2d7dac, Func Offset: 0x6c
	// Line 230, Address: 0x2d7db0, Func Offset: 0x70
	// Line 231, Address: 0x2d7db4, Func Offset: 0x74
	// Line 232, Address: 0x2d7db8, Func Offset: 0x78
	// Line 233, Address: 0x2d7dbc, Func Offset: 0x7c
	// Line 235, Address: 0x2d7dc0, Func Offset: 0x80
	// Line 245, Address: 0x2d7dc4, Func Offset: 0x84
	// Func End, Address: 0x2d7dcc, Func Offset: 0x8c
	scePrintf("njCos - UNIMPLEMENTED!\n");
}

// 100% matching!
void njSinCos(int lAngle, float* sin, float* cos)
{
    asm volatile 
    ("
    .set noreorder
        move  v1, %3 
        
        lw    t0, 0(%0) 
        
        addi  t2, zero, 16383 
    
        andi  t3, t0, 0x4000 
        
        beqz  t3, l_002D7E4C 
        
        and   t1, t0, t2
    
        sub   t2, t2, t1 
    
        muli  t1, t1, 4 
        muli  t2, t2, 4 
        
        add   t1, t1, v1 
        add   t2, t2, v1 
    
        lwc1  f4, 0(t2) 
        lwc1  f5, 0(t1) 
        
        neg.s f6, f4 
        neg.s f7, f5
        
        mfc1  t4, f6
        mfc1  t5, f5
        mfc1  t6, f4
        mfc1  t7, f7
    
        andi  t0, t0, 0x8000
    
        movz  t4, t6, t0
        
        b     l_002D7E9C
    
        movz  t5, t7, t0
    
        l_002D7E4C:
        sub   t2, t2, t1 
        
        muli  t1, t1, 4
        muli  t2, t2, 4
        
        add   t1, t1, v1 
        add   t2, t2, v1 
    
        lwc1  f4, 0(t1)
        lwc1  f5, 0(t2)
        
        neg.s f6, f4
        neg.s f7, f5
        
        mfc1  t4, f4
        mfc1  t5, f5
        mfc1  t6, f6
        mfc1  t7, f7
    
        andi  t0, t0, 0x8000
    
        movn  t4, t6, t0
        movn  t5, t7, t0
    
        l_002D7E9C:
        sw    t4, 0(%1)
        sw    t5, 0(%2)
        
        qmtc2 t4, vf11
        qmtc2 t5, vf12
    .set reorder
    " : : "r"(&lAngle), "r"(sin), "r"(cos), "r"(SinTable) : 
    );
}

// 79.50% matching 
Float	njFraction  (Float n) 
{ 
    return n - floorf(n); 
} 

// 
// Start address: 0x2d7ef0
Float	njSqrt(Float n)
{
	float ret;
	// Line 438, Address: 0x2d7ef0, Func Offset: 0
	// Line 439, Address: 0x2d7ef8, Func Offset: 0x8
	// Line 440, Address: 0x2d7efc, Func Offset: 0xc
	// Line 441, Address: 0x2d7f00, Func Offset: 0x10
	// Line 442, Address: 0x2d7f04, Func Offset: 0x14
	// Line 443, Address: 0x2d7f08, Func Offset: 0x18
	// Line 444, Address: 0x2d7f0c, Func Offset: 0x1c
	// Line 448, Address: 0x2d7f10, Func Offset: 0x20
	// Func End, Address: 0x2d7f18, Func Offset: 0x28
	scePrintf("njSqrt - UNIMPLEMENTED!\n");
}

// 100% matching! 
Float	njInvertSqrt(Float n)
{
    float ret;

    ret = 0;
    
    asm volatile
    ("
        mfc1    t0, f12

        qmtc2   t0, vf8
    
        vrsqrt  Q, vf0w, vf8x

        vwaitq 

        vaddq.x vf8, vf0, Q
        
        qmfc2   v0, vf8
    
        mtc1    v0, %0
    " : "=f"(ret) : : 
    );

    return ret;
}

// 
// Start address: 0x2d7f50
void	njLinear(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame)
{
	// Line 526, Address: 0x2d7f50, Func Offset: 0
	// Line 527, Address: 0x2d7f54, Func Offset: 0x4
	// Line 528, Address: 0x2d7f58, Func Offset: 0x8
	// Line 529, Address: 0x2d7f5c, Func Offset: 0xc
	// Line 530, Address: 0x2d7f60, Func Offset: 0x10
	// Line 531, Address: 0x2d7f64, Func Offset: 0x14
	// Line 532, Address: 0x2d7f68, Func Offset: 0x18
	// Line 533, Address: 0x2d7f6c, Func Offset: 0x1c
	// Line 534, Address: 0x2d7f70, Func Offset: 0x20
	// Line 535, Address: 0x2d7f74, Func Offset: 0x24
	// Line 536, Address: 0x2d7f78, Func Offset: 0x28
	// Line 537, Address: 0x2d7f7c, Func Offset: 0x2c
	// Line 538, Address: 0x2d7f80, Func Offset: 0x30
	// Line 539, Address: 0x2d7f84, Func Offset: 0x34
	// Line 540, Address: 0x2d7f88, Func Offset: 0x38
	// Line 541, Address: 0x2d7f8c, Func Offset: 0x3c
	// Line 542, Address: 0x2d7f90, Func Offset: 0x40
	// Line 543, Address: 0x2d7f94, Func Offset: 0x44
	// Line 544, Address: 0x2d7f98, Func Offset: 0x48
	// Line 545, Address: 0x2d7f9c, Func Offset: 0x4c
	// Line 549, Address: 0x2d7fa0, Func Offset: 0x50
	// Func End, Address: 0x2d7fa8, Func Offset: 0x58
	scePrintf("njLinear - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d7fb0
void	njOverhauserSpline(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame)
{
	float ftmp;
	// Line 594, Address: 0x2d7fb0, Func Offset: 0
	// Line 599, Address: 0x2d7fb8, Func Offset: 0x8
	// Line 600, Address: 0x2d7fbc, Func Offset: 0xc
	// Line 601, Address: 0x2d7fc0, Func Offset: 0x10
	// Line 602, Address: 0x2d7fc4, Func Offset: 0x14
	// Line 606, Address: 0x2d7fc8, Func Offset: 0x18
	// Line 607, Address: 0x2d7fcc, Func Offset: 0x1c
	// Line 609, Address: 0x2d7fd0, Func Offset: 0x20
	// Line 610, Address: 0x2d7fd4, Func Offset: 0x24
	// Line 611, Address: 0x2d7fd8, Func Offset: 0x28
	// Line 613, Address: 0x2d7fdc, Func Offset: 0x2c
	// Line 614, Address: 0x2d7fe0, Func Offset: 0x30
	// Line 615, Address: 0x2d7fe4, Func Offset: 0x34
	// Line 616, Address: 0x2d7fe8, Func Offset: 0x38
	// Line 618, Address: 0x2d7fec, Func Offset: 0x3c
	// Line 619, Address: 0x2d7ff0, Func Offset: 0x40
	// Line 620, Address: 0x2d7ff4, Func Offset: 0x44
	// Line 621, Address: 0x2d7ff8, Func Offset: 0x48
	// Line 622, Address: 0x2d7ffc, Func Offset: 0x4c
	// Line 624, Address: 0x2d8000, Func Offset: 0x50
	// Line 625, Address: 0x2d8004, Func Offset: 0x54
	// Line 626, Address: 0x2d800c, Func Offset: 0x5c
	// Line 627, Address: 0x2d8010, Func Offset: 0x60
	// Line 628, Address: 0x2d8014, Func Offset: 0x64
	// Line 629, Address: 0x2d8018, Func Offset: 0x68
	// Line 630, Address: 0x2d801c, Func Offset: 0x6c
	// Line 631, Address: 0x2d8020, Func Offset: 0x70
	// Line 632, Address: 0x2d8024, Func Offset: 0x74
	// Line 633, Address: 0x2d8028, Func Offset: 0x78
	// Line 634, Address: 0x2d802c, Func Offset: 0x7c
	// Line 635, Address: 0x2d8030, Func Offset: 0x80
	// Line 636, Address: 0x2d8034, Func Offset: 0x84
	// Line 637, Address: 0x2d8038, Func Offset: 0x88
	// Line 638, Address: 0x2d803c, Func Offset: 0x8c
	// Line 639, Address: 0x2d8040, Func Offset: 0x90
	// Line 640, Address: 0x2d8044, Func Offset: 0x94
	// Line 641, Address: 0x2d8048, Func Offset: 0x98
	// Line 642, Address: 0x2d804c, Func Offset: 0x9c
	// Line 643, Address: 0x2d8050, Func Offset: 0xa0
	// Line 644, Address: 0x2d8054, Func Offset: 0xa4
	// Line 645, Address: 0x2d8058, Func Offset: 0xa8
	// Line 646, Address: 0x2d805c, Func Offset: 0xac
	// Line 650, Address: 0x2d8060, Func Offset: 0xb0
	// Line 651, Address: 0x2d8064, Func Offset: 0xb4
	// Line 652, Address: 0x2d8068, Func Offset: 0xb8
	// Line 653, Address: 0x2d806c, Func Offset: 0xbc
	// Line 655, Address: 0x2d8070, Func Offset: 0xc0
	// Line 656, Address: 0x2d8074, Func Offset: 0xc4
	// Line 657, Address: 0x2d8078, Func Offset: 0xc8
	// Line 658, Address: 0x2d807c, Func Offset: 0xcc
	// Line 659, Address: 0x2d8080, Func Offset: 0xd0
	// Line 660, Address: 0x2d8084, Func Offset: 0xd4
	// Line 661, Address: 0x2d8088, Func Offset: 0xd8
	// Line 662, Address: 0x2d808c, Func Offset: 0xdc
	// Line 667, Address: 0x2d8090, Func Offset: 0xe0
	// Func End, Address: 0x2d8098, Func Offset: 0xe8
	scePrintf("njOverhauserSpline - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2d80a0
void njBezierSpline(float* fpIdata, float* fpOdata, _anon0* pAttr, float fFrame)
{
	float fResult;
	float fFactMax;
	unsigned int ulMax;
	unsigned int ulCnt;
	// Line 692, Address: 0x2d80a0, Func Offset: 0
	// Line 728, Address: 0x2d80d0, Func Offset: 0x30
	// Line 729, Address: 0x2d80d4, Func Offset: 0x34
	// Line 730, Address: 0x2d80d8, Func Offset: 0x38
	// Line 733, Address: 0x2d80dc, Func Offset: 0x3c
	// Line 734, Address: 0x2d80f4, Func Offset: 0x54
	// Line 736, Address: 0x2d812c, Func Offset: 0x8c
	// Line 739, Address: 0x2d8148, Func Offset: 0xa8
	// Line 741, Address: 0x2d821c, Func Offset: 0x17c
	// Line 744, Address: 0x2d8220, Func Offset: 0x180
	// Line 741, Address: 0x2d8228, Func Offset: 0x188
	// Line 742, Address: 0x2d8238, Func Offset: 0x198
	// Line 743, Address: 0x2d824c, Func Offset: 0x1ac
	// Line 744, Address: 0x2d8260, Func Offset: 0x1c0
	// Line 746, Address: 0x2d8268, Func Offset: 0x1c8
	// Func End, Address: 0x2d829c, Func Offset: 0x1fc
}*/

// 100% matching! 
unsigned int njFactorial(unsigned int ulN) 
{ 
    unsigned int ulResult;

    ulResult = 1;
    
    for ( ; ulN != 0; ulN--)
    { 
        ulResult *= ulN; 
    }
    
    return ulResult; 
}
