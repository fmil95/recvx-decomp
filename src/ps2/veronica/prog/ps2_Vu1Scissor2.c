#include "ps2_Vu1Scissor2.h"
#include "ps2_Vu1Strip.h"

extern void VU0_CLIP_VIEW_VOLUME() __attribute__((section(".vutext")));
extern void VU0_CLIP_VIEW_VOLUME_ALL() __attribute__((section(".vutext")));
extern void VU0_SET_NODE_ARRAY() __attribute__((section(".vutext")));
extern void VU0_LOAD_SCISSOR_WORK() __attribute__((section(".vutext")));
extern void VU0_LOAD_SCISSOR_WORKi() __attribute__((section(".vutext")));
extern void VU0_LOAD_SCISSOR_WORKb() __attribute__((section(".vutext")));

// 98.80% matching
void DrawScissorPolygonOpaque2(int count, unsigned long ulType)
{
    VU1_PRIM_BUF* pPrim; 

    asm volatile
    ("
        lw        t0, 0(%1)
        
        addi      t1, zero, 80
    
        ctc2      t1, vi3
        
        l_002D3B2C:
        vcallms   VU0_LOAD_SCISSOR_WORKi
    
        vdiv      Q, vf0w, vf9z
        
        vmulx.w   vf10, vf0, vf0x
        vmul.xy   vf9,  vf9, vf17
        
        vaddw.z   vf10, vf0, vf0w
    
        addi      t0, t0, -1
        addi      %0, %0, sizeof(VU1_PRIM_BUF)
        
        vwaitq
        
        vmulq.z   vf4,  vf23, Q
        vmulq.xyz vf10, vf10, Q
        vmulz.xy  vf9,  vf9,  vf4z
        
        vadd.xy   vf9, vf9, vf16
        
        sqc2      vf10, -0x30(%0)
        sqc2      vf11, -0x20(%0)
        sqc2      vf9,  -0x10(%0)

        bnez      t0, l_002D3B2C
        nop
    " : : "r"(vu1ScessorBuf), "r"(&count) : "$t0", "memory"
    );

    ulType = (ulType & ~0x2000000000000) | 0x6800000000000;
    
    pPrim = vu1ScessorBuf;
    
    Ps2AddPrim3DEx(ulType, pPrim, count);
}

// 100% matching!
void InitNodeArraySet2()
{
    asm volatile 
    {
        vmove.xyzw vf15, vf0
        vmove.xyzw vf18, vf0
        vmove.xyzw vf19, vf0
    }
}

// 92.50% matching
unsigned int _Clip_ViewVolume2(NJS_POINT4* vec) 
{
    unsigned int ret;
    
    ret = 0;
    
    asm volatile
    ("
    .set noreorder
        lqc2    vf14, NJS_POINT4.x(%0)
        
        vcallms VU0_CLIP_VIEW_VOLUME
    .set reorder
    " : : "r"(vec) : 
    );
    
    return ret;
}

// 100% matching! 
unsigned int _Get_ClipViewVolume2()
{
    unsigned int ret;

    ret = 0;

    asm volatile 
    ("
        cfc2.i %0, vi18
        
        addi   %0, %0, 0 
    " : "=r"(ret) : : 
    );

    return ret;
}

// 100% matching! 
int _Get_ClipVolumePlane() 
{
    int ret;

    ret = 0;

    asm volatile 
    ("
    .set noreorder
        cfc2.i %0, vi2
        
        addi   %0, %0, 0 
    .set reorder
    " : "=r"(ret) : : 
    );

    return ret;
}

// 91.43% matching
void _Check_ClipViewAll(NJS_POINT4* vec) 
{
    asm volatile
    ("
    .set noreorder
        lqc2    vf14, NJS_POINT4.x(%0)
        
        vcallms VU0_CLIP_VIEW_VOLUME_ALL
    .set reorder
    " : : "r"(vec) : 
    );
}

// 96% matching
void _Set_NodeArray(VU1_STRIP_BUF* pS, VU1_PRIM_BUF* pP)
{
    asm volatile 
    ("
    .set noreorder
        lqc2    vf4, -0x60(%0)
        lqc2    vf5, -0x20(%0)
        lqc2    vf6, 0x20(%0)
        lqc2    vf7, -0x80(%0)
        lqc2    vf8, -0x40(%0)
        lqc2    vf9, 0(%0)
        lqc2    vf10, -0x50(%1)
        lqc2    vf11, -0x20(%1)
        lqc2    vf12, 0x10(%1)
        
        vcallms VU0_SET_NODE_ARRAY
    .set reorder
    " : : "r"(pS), "r"(pP) : 
    );
}

// TODO: Verify that this function hasn't got more parts written in C, for example addiu and paddub tend to be compiler-emitted instructions
// 96.57% matching 
int _ClipInter(int mask1, int mask2, int xyzflg, float sin, int work0, int work1, int count)
{
    int ret;
    int pad[4]; // not from the debugging symbols

    ret = 0;

    asm volatile 
    ("
    .set noreorder
        addiu      s0, sp, 0x50
        addiu      s1, sp, 0x54
        addiu      s2, sp, 0x58
        addiu      s3, sp, 0x5C
        
        sw         t1, 0x5C(sp)
        sw         a0, 0x50(sp)
        sw         a1, 0x54(sp)
        sw         a2, 0x58(sp)
        
        paddub     %0, t0, zero
        
        add        t0, zero, a3 
        add        t1, zero, %0 
        
        ctc2.ni    t0, vi3
        ctc2.ni    t1, vi4
        
        viadd      vi5, vi0, vi4
    
        vcallms    VU0_LOAD_SCISSOR_WORK
    
        mfc1       t2, f12
    
        lw         t3, 0(s3)
        
        neg        t5, zero 
    
        qmtc2.ni   t2, vf12
        
        l_002D3CE4:
        lw         t1, 0(s2)
        
        vmove.xyzw vf4, vf8
        vmove.xyzw vf5, vf9
        vmove.xyzw vf6, vf10
        vmove.xyzw vf7, vf11
        
        vcallms    VU0_LOAD_SCISSOR_WORK
    
        vclipw.xyz vf4, vf4w                   
        vclipw.xyz vf8, vf8w                 
        vnop
        vnop
        vnop
        vnop
        vnop
    
        lw         t0, 0(s0)
        lw         t7, 0(s1)
        
        cfc2.ni    %0, vi18
        
        and        t0, %0, t0
        nop
    
        beqz       t0, l_002D3DCC
        nop
        
        and        %0, %0, t7
        nop
    
        bnez       %0, l_002D3E74
        nop
    
        vmulx.w    vf13, vf4, vf12x
        vmulx.w    vf14, vf8, vf12x
        
        vsubw.xyzw vf13, vf4, vf13w
        vsubw.xyzw vf14, vf8, vf14w
        
        l_002D3D54:
        beqz       t1, l_002D3D70
        nop
        
        vmr32.xyzw vf13, vf13
        vmr32.xyzw vf14, vf14
        
        addi       t1, t1, -1 
        
        b          l_002D3D54
        nop
    
        l_002D3D70:
        vsub.xyz   vf14, vf14, vf13
        
        vdiv       Q, vf13x, vf14x
    
        vwaitq
    
        vaddq.x    vf13, vf0, Q
        
        vabs.x     vf13, vf13
        
        vsub.xyzw  vf14, vf8, vf4
        
        vmulx.xyzw vf14, vf14, vf13x
        
        vadd.xyzw  vf4, vf4, vf14
        vsub.xyzw  vf14, vf9, vf5
        
        vmulx.xyzw vf14, vf14, vf13x
        
        vadd.xyzw  vf5, vf5, vf14
        
        vmaxw.z    vf5, vf5, vf0w
        
        vsub.xyzw  vf14, vf10, vf6
        
        vmulx.xyzw vf14, vf14, vf13x
        
        vadd.xyzw  vf6, vf6, vf14
        vsub.xyzw  vf14, vf11, vf7
        
        vmulx.xyzw vf14, vf14, vf13x
        
        vadd.xyzw  vf7, vf7, vf14
        
        vcallms    VU0_LOAD_SCISSOR_WORKb
    
        addi       t5, t5, 1 
        nop
    
        b          l_002D3E74
        nop
    
        l_002D3DCC:
        and        %0, %0, t7
        nop
    
        beqz       %0, l_002D3E6C
        nop
    
        vcallms    VU0_LOAD_SCISSOR_WORKb
    
        vmulx.w    vf13, vf4, vf12x
        vmulx.w    vf14, vf8, vf12x
        
        vsubw.xyzw vf13, vf4, vf13w
        vsubw.xyzw vf14, vf8, vf14w
        
        l_002D3DF0:
        beqz       t1, l_002D3E10
        nop
        
        vmr32.xyzw vf13, vf13
        vmr32.xyzw vf14, vf14
        
        addi       t1, t1, -1 
        nop
        
        b          l_002D3DF0
        nop
    
        l_002D3E10:
        vsub.xyz   vf14, vf14, vf13
        
        vdiv       Q, vf13x, vf14x
    
        vwaitq
    
        vaddq.x    vf13, vf0, Q
        
        vabs.x     vf13, vf13
        
        vsub.xyzw  vf14, vf8, vf4
        
        vmulx.xyzw vf14, vf14, vf13x
        
        vadd.xyzw  vf4, vf4, vf14
        vsub.xyzw  vf14, vf9, vf5
        
        vmulx.xyzw vf14, vf14, vf13x
        
        vadd.xyzw  vf5, vf5, vf14
        
        vmaxw.z    vf5, vf5, vf0w
        
        vsub.xyzw  vf14, vf10, vf6
        
        vmulx.xyzw vf14, vf14, vf13x
        
        vadd.xyzw  vf6, vf6, vf14
        vsub.xyzw  vf14, vf11, vf7
        
        vmulx.xyzw vf14, vf14, vf13x
        
        vadd.xyzw  vf7, vf7, vf14
        
        vcallms    VU0_LOAD_SCISSOR_WORKb
    
        addi       t5, t5, 2 
        nop
    
        b          l_002D3E74
        nop
    
        l_002D3E6C:
        vcallms    VU0_LOAD_SCISSOR_WORKb
    
        addi       t5, t5, 1 
    
        l_002D3E74:
        addi       t3, t3, -1 
        nop
        
        bnez       t3, l_002D3CE4
        nop
    
        vcallms    VU0_LOAD_SCISSOR_WORKi
        vcallms    VU0_LOAD_SCISSOR_WORKb
    
        addu       %0, t5, zero
        addi       %0, %0, 0 
    .set reorder
    " : "=r"(ret) : "r"(pad) : 
    );

    return ret;
}

// 100% matching!
int _Check_ScissorPlane()
{
    int count;

    count = _ClipInter(2048, 32, 2, -1.0f, 80, 128, 3);
    
    if (count == 0) 
    {
        return count;
    }

    count = _ClipInter(1024, 16, 2, 1.0f, 128, 80, count);

    if (count == 0) 
    {
        return count;
    }

    count = _ClipInter(128, 2, 0, -1.0f, 80, 128, count);
    
    if (count == 0) 
    {
        return count;
    }

    count = _ClipInter(64, 1, 0, 1.0f, 128, 80, count);
    
    if (count == 0) 
    {
        return count;
    }

    count = _ClipInter(512, 8, 1, -1.0f, 80, 128, count);
    
    if (count == 0) 
    {
        return count;
    }
    
    count = _ClipInter(256, 4, 1, 1.0f, 128, 80, count);

    return count;
}
