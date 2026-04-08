#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/main.h"

static float SinTable[16384];

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

// 100% matching!
Float	njCos(Angle n)
{
	float ret;

	asm volatile 
    ("
    .set noreorder
        move  v0, %0
        
        lw    t0, 0(%1)
        
        addi  t2, zero, 16383
    
        andi  t3, t0, 0x4000
        
        beqz  t3, l_002D7D94
        
        and   t1, t0, t2
    
        muli  t1, t1, 4
    
        add   t1, t1, %2
        
        lwc1  f5, 0(t1)
        
        neg.s f7, f5
        
        mfc1  %2, f5
		mfc1  t7, f7
        
        andi  t0, t0, 0x8000

        b     l_002D7DC0

        movz  %2, t7, t0

        l_002D7D94:
		sub   t2, t2, t1

        muli  t2, t2, 4
        
        add   t2, t2, %2
        
        lwc1  f5, 0(t2)
        
        neg.s f7, f5
        
        mfc1  %2, f5
        mfc1  t7, f7
    
        andi  t0, t0, 0x8000
        
        movn  %2, t7, t0

        l_002D7DC0:
        mtc1  %2, f0
    .set reorder
    " : "=r"(ret) : "r"(&n), "r"(SinTable) : 
    );
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

// 100% matching! 
Float	njFraction  (Float n) 
{ 
    return n - floorf(n); 
} 

// 100% matching! 
Float	njSqrt(Float n)
{
	float ret;

	ret = 0;
    
    asm volatile
    ("
        mfc1    t0, f12

        qmtc2   t0, vf8
    
        vsqrt   Q,  vf8

        vwaitq 

        vaddq   vf8, vf0, Q
        
        qmfc2   v0,  vf8
    
        mtc1    v0, %0
    " : "=f"(ret) : : 
    );

    return ret;
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
    
        vrsqrt  Q,  vf0w, vf8

        vwaitq 

        vaddq   vf8, vf0, Q
        
        qmfc2   v0,  vf8
    
        mtc1    v0, %0
    " : "=f"(ret) : : 
    );

    return ret;
}

// 100% matching! 
void	njLinear(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame)
{
	asm volatile
    ("
	    addi     a4, %0, 12

		mfc1     a5, %3

        ldl      a6, 0x7(%0)
        ldr      a6,   0(%0)
     
        lw       a7,   8(%0) 

        ldl      t4, 0x7(a4)
        ldr      t4,   0(a4)
     
        lw       t5,   8(a4) 
     
        pcpyld   a6, a7, a6
        pcpyld   t4, t5, t4
     
        qmtc2.ni a6, vf10
        qmtc2.ni t4, vf11
		qmtc2.ni a5, vf9
		
		vsub     vf12, vf11, vf10

		vmulx    vf12, vf12, vf9

		vadd     vf4,  vf12, vf10

		qmfc2.ni a6, vf4

		pcpyud   a7, a6, a6

		sdl      a6, 0x7(%1)
        sdr      a6,   0(%1)
     
        sw       a7,   8(%1) 
    " : : "r"(idata), "r"(odata), "r"(attr), "f"(frame) : 
    );
}

// 100% matching! 
void	njOverhauserSpline(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame)
{
	float ftmp; 

	ftmp = 0.5f;

	asm volatile
    ("
		mfc1     a4, %3

		vaddw    vf12,  vf0, vf0
		vaddw    vf12, vf12, vf0

		qmtc2.ni a4, vf4

		vmul     vf5,  vf4, vf4
		vmul     vf6,  vf5, vf4

		vadd     vf8,  vf5, vf5

		vsub     vf8,  vf8, vf6
		vsub     vf8,  vf8, vf4

		vmulz    vf10, vf5, vf2
		vmul     vf9,  vf6, vf2

		vsub     vf9,  vf9, vf10

		vadd     vf9,  vf9, vf12

		vsub     vf7,  vf0, vf2

		vmulx    vf7,  vf6, vf7
		vmuly    vf10, vf5, vf2

		vadd     vf10, vf10, vf4
		vadd     vf10, vf10, vf7

		vsub     vf11, vf6, vf5

		mfc1     a5, %4
		nop

		qmtc2.ni a5, vf12

        ldl      a4,  0x7(%0)
        ldr      a4,    0(%0)
     
        lw       a5,    8(%0) 

        ldl      a6, 0x13(%0)
        ldr      a6,  0xC(%0)
     
        lw       a7,   20(%0) 

		ldl      t4, 0x1F(%0)
        ldr      t4, 0x18(%0)
     
        lw       t5,   32(%0) 

        ldl      t6, 0x2B(%0)
        ldr      t6, 0x24(%0)
     
        lw       t7,   44(%0) 
     
		pcpyld   a4, a5, a4
		pcpyld   a6, a7, a6
        pcpyld   t4, t5, t4
        pcpyld   t6, t7, t6
     
		qmtc2.ni a4, vf4
		qmtc2.ni a6, vf5
		qmtc2.ni t4, vf6
		qmtc2.ni t6, vf7
		
		vmulx    vf4, vf4, vf8
		vmulx    vf5, vf5, vf9
		vmulx    vf6, vf6, vf10
		vmulx    vf7, vf7, vf11

		vadd     vf4, vf4, vf5
		vadd     vf4, vf4, vf6
		vadd     vf4, vf4, vf7

		vmulx    vf4, vf4, vf12

		qmfc2.ni a6, vf4

		pcpyud   a7, a6, a6

		sdl      a6, 0x7(%1)
        sdr      a6,   0(%1)
     
        sw       a7,   8(%1) 
    " : : "r"(idata), "r"(odata), "r"(attr), "f"(frame), "f"(ftmp) : 
    );
}

// 100% matching! 
void	njBezierSpline(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame) 
{
    unsigned int ulCnt; 
    unsigned int ulMax; 
    float fFactMax;     
    float fResult;      
    
    odata[0] = 0;
    odata[1] = 0;
    odata[2] = 0;
    
    ulMax = *attr->iparam - 1;
    
    fResult = njFactorial(ulMax);

    for (ulCnt = 0; ulCnt <= ulMax; ulCnt++)  
    {            
        fFactMax = (powf(frame, ulCnt) * (fResult / (njFactorial(ulCnt) * njFactorial(ulMax - ulCnt)))) * powf(1.0f - frame, ulMax - ulCnt);
        
        odata[0] += fFactMax * *idata++;
        odata[1] += fFactMax * *idata++;
        odata[2] += fFactMax * *idata++; 
    }
}

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
