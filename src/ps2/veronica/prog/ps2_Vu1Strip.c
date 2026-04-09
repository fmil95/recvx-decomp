#include "../../../ps2/veronica/prog/ps2_Vu1Strip.h"
#include "../../../ps2/veronica/prog/ps2_NaFog.h"
#include "../../../ps2/veronica/prog/ps2_NaView.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/main.h"

static SCISSOR_PLANE planeset;
static SCISSOR scissorflip;
static NODE node;
float fVu1Projection;
float fVu1NearClip;
float fVu1InvNearClip;
float fVu1FarClip;
float fVu1OffsetX;
float fVu1OffsetY;
float fVu1AspectW;
float fVu1AspectH;
VU1_PRIM_BUF vu1ScessorBuf[16];
void (*pColorCalcFuncTbl[11])(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim) = 
{
	vu1GetVertexColor,
	vu1GetVertexColorCM,
	vu1GetVertexColorIgnore,
	vu1GetVertexColorDif,
	vu1GetVertexColorDifAmb,
	vu1GetVertexColorDifSpe1,
	vu1GetVertexColorDifSpe2,
	vu1GetVertexColorDifSpe3,
	vu1GetVertexColorDifSpe1Amb,
	vu1GetVertexColorDifSpe2Amb,
	vu1GetVertexColorDifSpe3Amb
};
VU1_COLOR vu1Diffuse = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR vu1Specula = { 1.0f, 1.0f, 1.0f, 1.0f };
VU1_COLOR vu1Ambient = { 1.0f, 1.0f, 1.0f, 1.0f };
float fVu1AlphaRatio = 128.0f;

extern void VU0_CLIP_VIEW_VOLUME_ALL() __attribute__((section(".vutext")));
extern void VU0_CALC_COLOR() __attribute__((section(".vutext")));
extern void VU0_INIT_CALC_COLOR() __attribute__((section(".vutext")));

// 100% matching!
void vu1SetScreenProjection(float fProjection)
{
    fVu1Projection = fProjection;
    
    asm volatile 
    {

        mfc1     t0, $f12
        nop
        
        qmtc2    t0, $vf4

        vaddx.z  $vf23, $vf0, $vf4x
        
    }
    
    _Make_ClipMatrix(ClipMatrix2, fVu1Projection, _fNaViwClipNear, _fNaViwClipFar);
}

// 100% matching!
void vu1SetNearFarClip(float fNear, float fFar)
{
    fVu1NearClip = fNear;
    fVu1FarClip = fFar;
    
    fVu1InvNearClip = 1.0f / fVu1NearClip;

    asm volatile 
    {
        
        mfc1     t0, $f12
        mfc1     t1, $f13

        qmtc2    t0, $vf4
        qmtc2    t1, $vf5

        vaddx.x  $vf23x, $vf0x, $vf4x
        vaddx.y  $vf23y, $vf0y, $vf5x
        
    }
    
    _Make_ClipMatrix(ClipMatrix2, fVu1Projection, _fNaViwClipNear, _fNaViwClipFar);
}

// 100% matching!
void vu1SetScreenOffset(float fOffsetX, float fOffsetY)
{
    fVu1OffsetX = fOffsetX;
    fVu1OffsetY = fOffsetY;
    
    asm volatile 
    {
        
        mfc1     t0, $f12
        mfc1     t1, $f13

        qmtc2    t0, $vf4
        qmtc2    t1, $vf5

        vaddx.x  $vf16, $vf0, $vf4x
        vaddx.y  $vf16, $vf0, $vf5x
        
    }
}

// 100% matching!
void vu1SetScreenAspect(float fAspectW, float fAspectH)
{
    fVu1AspectW = fAspectW;
    fVu1AspectH = fAspectH;

    asm volatile 
    {
        
        mfc1     t0, $f12
        mfc1     t1, $f13

        qmtc2    t0, $vf4
        qmtc2    t1, $vf5

        vaddx.x  $vf17x, $vf0x, $vf4x
        vaddx.y  $vf17y, $vf0y, $vf5x
        
    }
}

// 100% matching!
void vu1SetDiffuseMaterial(VU1_COLOR* pDiffuse)
{
    vu1Diffuse.fR = 128.0f * pDiffuse->fR;
    vu1Diffuse.fG = 128.0f * pDiffuse->fG;
    vu1Diffuse.fB = 128.0f * pDiffuse->fB;
    
    asm volatile 
    ("
        lq         t3, VU1_COLOR.fR(%0)
    
        mfc1       t0, %1
        mfc1       t1, %1
        mfc1       t2, %1
        
        pextlw     t0, t1, t0 
        pcpyld     t0, t2, t0 
    
        qmtc2      t3, $vf4 
        qmtc2      t0, $vf5 
    
        vmul.xyz   $vf4,  $vf4, $vf5 
        vaddx.xyzw $vf20, $vf4, $vf0x 
    " : : "r"(pDiffuse), "f"(128.0f) : "t0"
    );
}

// 100% matching!
void vu1SetSpeculaMaterial(VU1_COLOR* pSpecula)
{
    vu1Specula.fR = 31.0f * pSpecula->fR;
    vu1Specula.fG = 31.0f * pSpecula->fG;
    vu1Specula.fB = 31.0f * pSpecula->fB;
    
    asm volatile 
    ("
        mfc1       t0, %0
        mfc1       t1, %0
        mfc1       t2, %0
        
        pextlw     t0, t1, t0 
        pcpyld     t0, t2, t0 
    
        qmtc2      t3, $vf4 
        qmtc2      t0, $vf5 
    
        vmul.xyz   $vf4,  $vf4, $vf5 
        vaddx.xyzw $vf21, $vf4, $vf0x 
    " : : "f"(31.0f) : "t0", "t1", "t2"
    );
}

// 100% matching!
void vu1SetAmbient(VU1_COLOR* pAmbient)
{
    vu1Ambient.fR = pAmbient->fR;
    vu1Ambient.fG = pAmbient->fG;
    vu1Ambient.fB = pAmbient->fB;
    
    asm volatile
    ("
        lqc2 vf22, VU1_COLOR.fR(%0)
    " : : "r"(pAmbient) : 
    );
}

// 100% matching!
void vu1SetAlphaRatio(float fAlpha)
{
    fVu1AlphaRatio = 128.0f * fAlpha;

    asm volatile 
    ("

        mfc1    t0, %0       
        qmtc2   t0, $vf4 

        vmulx.w $vf23, $vf0, $vf4x

    " : : "f"(fVu1AlphaRatio) : "t0"
    );
}

#include "ps2_Vu1Scissor2.c"

// 100% matching!
void InitNodeArraySet(SCISSOR* scissor)
{
    scissor->rotflag = 0;
    scissor->flipflag = 0;

    asm volatile 
    ("
        add  t0, zero, %0
        
        addi t2, zero, 3
        
        addi t0, t0, SCISSOR.narray
        addi t1, t0, sizeof(SCISSOR_NODE)
        
        sw   t0, SCISSOR.in(%0)
        sw   t1, SCISSOR.out(%0)
        
        sw   zero, SCISSOR_NODE.nodeNum(t0)
        sw   zero, SCISSOR_NODE.nodeNum(t1)
        
        sw   t2, SCISSOR_NODE.nodeNum(%0)
    " : : "r"(scissor) : 
    );
}

// 100% matching!
static void InitScissorPlane(SCISSOR_PLANE* sp)
{
    sp->planeNum = 5;
    
    sp->plane[0].clipmask = 0x820;
    sp->plane[0].xyzflag = 0x12;
    
    sp->plane[1].clipmask = 0x208;
    sp->plane[1].xyzflag = 0x11;
    
    sp->plane[2].clipmask = 0x104;
    sp->plane[2].xyzflag = 0x1;
    
    sp->plane[3].clipmask = 0x82;
    sp->plane[3].xyzflag = 0x10;
    
    sp->plane[4].clipmask = 0x41;
    sp->plane[4].xyzflag = 0;
}

// 100% matching!
void _Init_ScissorSystem()
{
    InitScissorPlane(&planeset);
    InitNodeArraySet(&scissorflip);
}

// 100% matching! 
int _Clip_ViewVolume(float* clip, float local_clip[4], float* vertex)
{
    asm volatile
    ("
        lqc2         vf4, 0(%1)
            
        vmulax.xyzw  ACC, vf24, vf4x
            
        vmadday.xyzw ACC, vf25, vf4y
        vmaddaz.xyzw ACC, vf26, vf4z
            
        vmaddw.xyzw  vf5, vf27, vf0w
            
        vclipw.xyz   vf5xyz, vf5w
        vnop
        vnop
        vnop
        vnop
        
        sqc2         vf5, 0(%0)
        
        cfc2         v0, vi18
    " : : "r"(clip), "r"(vertex) : 
    );
}

// 100% matching!
void PushTriangleNodeArray(SCISSOR* scissor, NODE* nod)
{
    asm volatile 
    ("
        move   v1, %1
        
        lw     t0, SCISSOR.rotflag(%0)
        
        daddiu at, zero, sizeof(NODE)
    
        mult   t0, at
        nop
        nop
    
        mflo   t1
    
        addi   t0, t0, 1
        add    t1, t1, %0
        
        andi   t0, t0, 0x3
    
        lqc2   vf4, NODE.vertex(v1)
        lqc2   vf5, NODE.color(v1)
        lqc2   vf6, NODE.texUV(v1)
        lqc2   vf7, NODE.clipV(v1)
        
        sqc2   vf4, SCISSOR.triangle.node[0].vertex(t1)
        sqc2   vf5, SCISSOR.triangle.node[0].color(t1)
        sqc2   vf6, SCISSOR.triangle.node[0].texUV(t1)
        sqc2   vf7, SCISSOR.triangle.node[0].clipV(t1)
        
        addi   t2, t0, -3
        
        bltz   t2, l_002D4150
        nop
    
        neg    t0, zero
        
        l_002D4150:
        sw     t0, SCISSOR.rotflag(%0)
    " : : "r"(scissor), "r"(&node) : "v1"
    );
}

// 100% matching!
void ResetNodeArraySet(SCISSOR* scissor)
{
    scissor->flipflag = 0;

    asm volatile 
    ("
        add  t0, zero, %0
        
        addi t2, zero, 3
        
        addi t0, t0, SCISSOR.narray
        addi t1, t0, sizeof(SCISSOR_NODE)
        
        sw   t0, SCISSOR.in(%0)
        sw   t1, SCISSOR.out(%0)
        
        sw   zero, SCISSOR_NODE.nodeNum(t0)
        sw   zero, SCISSOR_NODE.nodeNum(t1)
    " : : "r"(scissor) : 
    );
}

// 100% matching! 
void ScissorTriangle(SCISSOR* scissor, SCISSOR_PLANE* plane_set)
{
    int i;                 
    int j;                  
    int clip;               
    int mask;               
    int xyz;                
    float sgn;              
    SCISSOR_NODE* inarray;  
    SCISSOR_NODE* outarray; 
    NODE* currN;            
    NODE* nextN;            
    NODE interN;            
    int n;                 

    nextN = NULL;
    currN = NULL;

    sgn = 0;

    clip = 0;
    
    inarray = &scissor->triangle;
    outarray = scissor->out;
    
    for (i = 0; i < plane_set->planeNum; i++) 
    {
        asm volatile
        ("
            lw          t0, 0(%4)
            
            muli        t0, t0, sizeof(PLANE)
        
            add         t0, t0, %1
        
            lw          t1, PLANE.xyzflag(t0)
            
            andi        t4, t1, 16
        
            li          t2, -1 
            li          t3,  1 
            
            movz        t2, t3, t4
            
            qmtc2       t2, vf4
        
            vitof0.xyzw vf4, vf4
            
            lw          t2, PLANE.clipmask(t0)
        
            sw          t2, 0(%2)
            
            andi        t1, t1, 0xF
        
            sw          t1, 0(%3)
            
            qmfc2       v0, vf4
        
            mtc1        v0, %0
        " : "=r"(sgn) : "r"(plane_set), "r"(&mask), "r"(&xyz), "r"(&i) :
        ); 
        
        for (j = 0; j < inarray->nodeNum; j++) 
        {
            asm volatile
            ("
                lw   t0, 0(%3)
                lw   t1, SCISSOR_NODE.nodeNum(%2)
                
                muli t2, t0, sizeof(NODE)
            
                addi t3, t0, 1 
            
                sub  t4, t3, t1 
                
                bltz t4, l_002D4244
                vnop
            
                neg  t3, zero
                
            l_002D4244:
                muli t3, t3, sizeof(NODE)
                                    
                add  %0, t2, %2
                add  %1, t3, %2 
            " : "=r"(currN), "=r"(nextN) : "r"(inarray), "r"(&j)
            );
                
            asm volatile
            ("
                lqc2       vf4, NODE.clipV(%1)
                lqc2       vf5, NODE.clipV(%2) 
            
                vclipw.xyz vf4, vf4                    
                vclipw.xyz vf5, vf5                   
                vnop
                vnop
                vnop
                vnop
                vnop
            
                cfc2       %0, vi18
            " : "=r"(clip) : "r"(currN), "r"(nextN)
            );
            
            clip &= mask;
            
            if (clip == 0) 
            {
                asm volatile
                ("  
                    lw   t0, SCISSOR_NODE.nodeNum(%2)
                    
                    muli t1, t0, sizeof(NODE)
                
                    add  t1, t1, %2 
                
                    lqc2 vf4, NODE.vertex(%4)
                    lqc2 vf5, NODE.color(%4)
                    lqc2 vf6, NODE.texUV(%4)
                    lqc2 vf7, NODE.clipV(%4)
                    
                    sqc2 vf4, NODE.vertex(t1)
                    sqc2 vf5, NODE.color(t1)
                    sqc2 vf6, NODE.texUV(t1)
                    sqc2 vf7, NODE.clipV(t1)
                    
                    addi t0, t0, 1 
                
                    sw   t0, SCISSOR_NODE.nodeNum(%2)
                " : : "r"(inarray), "r"(&j), "r"(outarray), "r"(mask), "r"(currN)
                );
            } 
            else if (((clip & 0x3F)) && ((clip & 0xFC0)))
            {
                
            } 
            else if (((clip & 0x3F)) && (!(clip & 0xFC0)))
            {
                asm volatile
                ("
                    lqc2       vf8, NODE.clipV(%3)
                    lqc2       vf9, NODE.clipV(%4)
                    
                    mfc1       t0, %0
                
                    qmtc2      t0, vf10
                    
                    vmulx.w    vf11, vf8, vf10
                    vmulx.w    vf12, vf9, vf10
                    
                    vsubw.xyzw vf11, vf8, vf11
                    vsubw.xyzw vf12, vf9, vf12
                    
                    vabs.xyzw  vf11, vf11
                    vabs.xyzw  vf12, vf12
                    
                    qmfc2      t1, vf11
                    qmfc2      t2, vf12
                    nop
                
                l_002D4350:   
                    beqz       %2, l_002D4368
                        
                    prot3w     t1, t1
                    prot3w     t2, t2
                
                    addi       %2, -1
                    j l_002D4350  
                    
                l_002D4368:    
                    qmtc2      t1, vf11
                    qmtc2      t2, vf12
                
                    vsub.xyzw  vf13, vf9, vf8
                    
                    vadd.xyz   vf12, vf12, vf11
                    
                    lqc2       vf6, NODE.vertex(%4)
                    lqc2       vf5, NODE.color(%4)
                    lqc2       vf4, NODE.texUV(%4)
                    
                    vdiv       Q, vf11, vf12
                
                    lqc2       vf9,  NODE.vertex(%3)
                    lqc2       vf10, NODE.color(%3)
                    lqc2       vf11, NODE.texUV(%3)
                    
                    vsub.xyzw  vf6, vf6, vf9
                    vsub.xyzw  vf5, vf5, vf10
                    vsub.xyzw  vf4, vf4, vf11
                    
                    vwaitq
                    
                    vaddq.xyzw vf12, vf0, Q
                    
                    vabs.x     vf12, vf12
                    
                    vmulx.xyzw vf7, vf13, vf12
                    vmulx.xyzw vf6, vf6,  vf12
                    vmulx.xyzw vf5, vf5,  vf12
                    vmulx.xyzw vf4, vf4,  vf12
                    
                    vadd.xyzw  vf7, vf8, vf7
                    vadd.xyzw  vf6, vf6, vf9
                    vadd.xyzw  vf5, vf5, vf10
                    vadd.xyzw  vf4, vf4, vf11
                    
                    vmaxw.z    vf6, vf6, vf0
                    
                    sqc2       vf5, NODE.color(%1)
                    sqc2       vf4, NODE.texUV(%1)
                    sqc2       vf7, NODE.clipV(%1)
                    sqc2       vf6, NODE.vertex(%1)
                " : : "r"(sgn), "r"(&interN), "r"(xyz), "r"(currN), "r"(nextN)
                );
                    
                asm volatile
                ("
                    lw   t0, SCISSOR_NODE.nodeNum(%2)
                
                    muli t1, t0, sizeof(NODE)
                    
                    add  t1, t1, %2 
                
                    lqc2 vf4, NODE.vertex(%3)
                    lqc2 vf5, NODE.color(%3)
                    lqc2 vf6, NODE.texUV(%3)
                    lqc2 vf7, NODE.clipV(%3)
                    
                    sqc2 vf4, NODE.vertex(t1)
                    sqc2 vf5, NODE.color(t1)
                    sqc2 vf6, NODE.texUV(t1)
                    sqc2 vf7, NODE.clipV(t1)
                    
                    addi t0, t0, 1 
                
                    sw   t0, SCISSOR_NODE.nodeNum(%2)
                " : : "r"(&interN), "r"(xyz), "r"(outarray), "r"(currN)
                );
                    
                asm volatile
                ("
                    lw   t0, SCISSOR_NODE.nodeNum(%2)
                    
                    muli t1, t0, sizeof(NODE)
                    
                    add  t1, t1, %2 
                
                    lqc2 vf4, NODE.vertex(%0)
                    lqc2 vf5, NODE.color(%0)
                    lqc2 vf6, NODE.texUV(%0)
                    lqc2 vf7, NODE.clipV(%0)
                    
                    sqc2 vf4, NODE.vertex(t1)
                    sqc2 vf5, NODE.color(t1)
                    sqc2 vf6, NODE.texUV(t1)
                    sqc2 vf7, NODE.clipV(t1)
                    
                    addi t0, t0, 1 
                
                    sw   t0, SCISSOR_NODE.nodeNum(%2)
                " : : "r"(&interN), "r"(xyz), "r"(outarray)
                );
            } 
            else if ((!(clip & 0x3F)) && ((clip & 0xFC0))) 
            {
                asm volatile
                ("
                    lqc2       vf8, NODE.clipV(%3)
                    lqc2       vf9, NODE.clipV(%4)
                    
                    mfc1       t0, %0
                
                    qmtc2      t0, vf10
                    
                    vmulx.w    vf11, vf8, vf10
                    vmulx.w    vf12, vf9, vf10
                    
                    vsubw.xyzw vf11, vf8, vf11
                    vsubw.xyzw vf12, vf9, vf12
                    
                    vabs.xyzw  vf11, vf11
                    vabs.xyzw  vf12, vf12
                    
                    qmfc2      t1, vf11
                    qmfc2      t2, vf12
                    nop
                
                l_002D44C8:
                    beqz       %2, l_002D44E0
                        
                    prot3w     t1, t1
                    prot3w     t2, t2
                
                    addi       %2, %2, -1 
                    j          l_002D44C8
                    
                l_002D44E0:
                    qmtc2      t1, vf11
                    qmtc2      t2, vf12
                
                    vsub.xyzw  vf13, vf9, vf8
                    
                    vadd.xyz   vf12, vf12, vf11
                    
                    lqc2       vf6, NODE.vertex(%4)
                    lqc2       vf5, NODE.color(%4)
                    lqc2       vf4, NODE.texUV(%4)
                    
                    vdiv       Q, vf11, vf12
                
                    lqc2       vf9,  NODE.vertex(%3)
                    lqc2       vf10, NODE.color(%3)
                    lqc2       vf11, NODE.texUV(%3)
                    
                    vsub.xyzw  vf6, vf6, vf9
                    vsub.xyzw  vf5, vf5, vf10
                    vsub.xyzw  vf4, vf4, vf11
                    
                    vwaitq
                    
                    vaddq.xyzw vf12, vf0, Q
                    
                    vabs.x     vf12, vf12
                    
                    vmulx.xyzw vf7, vf13, vf12
                    vmulx.xyzw vf6, vf6, vf12
                    vmulx.xyzw vf5, vf5, vf12
                    vmulx.xyzw vf4, vf4, vf12
                    
                    vadd.xyzw  vf7, vf8, vf7
                    vadd.xyzw  vf6, vf6, vf9
                    vadd.xyzw  vf5, vf5, vf10
                    vadd.xyzw  vf4, vf4, vf11
                    
                    vmaxw.z    vf6, vf6, vf0
                    
                    sqc2       vf5, NODE.color(%1)
                    sqc2       vf4, NODE.texUV(%1)
                    sqc2       vf7, NODE.clipV(%1)
                    sqc2       vf6, NODE.vertex(%1)
                " : : "r"(sgn), "r"(&interN), "r"(xyz), "r"(nextN), "r"(currN)
                );
                
                asm volatile
                ("
                    lw   t0, SCISSOR_NODE.nodeNum(%2)
                    
                    muli t1, t0, sizeof(NODE)
                    
                    add  t1, t1, %2 
                    
                    lqc2 vf4, NODE.vertex(%1)
                    lqc2 vf5, NODE.color(%1)
                    lqc2 vf6, NODE.texUV(%1)
                    lqc2 vf7, NODE.clipV(%1)
                    
                    sqc2 vf4, NODE.vertex(t1)
                    sqc2 vf5, NODE.color(t1)
                    sqc2 vf6, NODE.texUV(t1)
                    sqc2 vf7, NODE.clipV(t1)
                    
                    addi t0, t0, 1 
                    
                    sw   t0, SCISSOR_NODE.nodeNum(%2)
                " : : "r"(xyz), "r"(&interN), "r"(outarray)
                );
            }
        }

        asm volatile
        ("
            lw   t0, SCISSOR.flipflag(%0)
            
            addi t1, t0, 1 
        
            andi t1, t1, 1
            
            sw   t1, SCISSOR.flipflag(%0)
            
            muli t0, t0, sizeof(SCISSOR_NODE)
            muli t1, t1, sizeof(SCISSOR_NODE)
        
            add  t0, t0, %0 
            add  t1, t1, %0 
            
            addi t0, t0, sizeof(SCISSOR_NODE) 
            addi t1, t1, sizeof(SCISSOR_NODE) 
            
            sw   t0,   SCISSOR.out(%0)
            sw   t1,   SCISSOR.in(%0)
            sw   zero, SCISSOR.triangle.nodeNum(t0)
        " : : "r"(scissor)
        );
                
        inarray = scissor->in;   
        outarray = scissor->out;
    }
}

// 100% matching!
int _Check_DisplayAreaPoint(NJS_VECTOR* vec)
{
    if (((vec->x >= 1.0f) && (vec->x < 4095.0f)) && ((vec->y >= 1.0f) && (vec->y < 4095.0f)) && ((vec->z >= 1.0f) && (vec->z < 65535.0f))) 
    {
        return 0;
    }
    
    return 1;
}

// 100% matching!
void DrawScissorPolygonOpaque(SCISSOR* scissor, unsigned long ulType)
{
    SCISSOR_NODE* in; 
    VU1_PRIM_BUF* pP; // not from the debugging symbols

    in = scissor->in;
    
    asm volatile
    ("
        addi     t6, %0, SCISSOR.in
    
        lw       t6, SCISSOR.triangle.node[0](t6)
        
        add      t7, zero, %1
    
        lw       t0, SCISSOR_NODE.nodeNum(t6)
        nop
        
        l_002D4720:
        lqc2     vf4, SCISSOR.triangle.node[0].vertex(t6)
        
        vdiv     Q, vf0w, vf4z
    
        lqc2     vf7, SCISSOR.triangle.node[0].color(t6)
        
        sqc2     vf7, VU1_PRIM_BUF.fR(t7)
    
        vaddz.x  vf5, vf0, vf23z
        
        lqc2     vf6, SCISSOR.triangle.node[0].texUV(t6)
    
        addi     t0, t0, -1
        
        vwaitq
        
        vmulq.x  vf5, vf5, Q
        vmulq.xy vf6, vf6, Q
        
        vaddq.z  vf6, vf0, Q
        
        vsub.w   vf6, vf6, vf6
        
        vmulx.xy vf4, vf4, vf5x
        
        sqc2     vf6, VU1_PRIM_BUF.fS(t7)
    
        vmul.xy  vf4, vf4, vf17
        
        vadd.xy  vf4, vf4, vf16
        
        addi     t6, t6, sizeof(NODE)
    
        sqc2     vf4, VU1_PRIM_BUF.fX(t7)
    
        addi     t7, t7, sizeof(VU1_PRIM_BUF)
    
        bnez     t0, l_002D4720
        vnop
    " : : "r"(scissor), "r"(vu1ScessorBuf) : "t7"
    );

    ulType = (ulType & 0xFFFDFFFFFFFFFFFF) | 0x6800000000000;
    
    pP = vu1ScessorBuf;
    
    Ps2AddPrim3DEx(ulType, pP, in->nodeNum);
}

// 100% matching! 
void vu1DrawTriangleStripOpaqueSingle(unsigned long ulType, VU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode)
{
    VU1_PRIM_BUF* pP;                            
    VU1_STRIP_BUF* pS0, *pS1, *pS2;                         
    float fIz;                                   
    unsigned short usStripCnt;                  
    void (*pFunc)(VU1_STRIP_BUF*, VU1_PRIM_BUF*); 
    unsigned int clipflag;                     
    int flg;                                    
    int count;                                

    pS0 = pStripTop; 
    pS1 = &pS0[1];
    pS2 = &pS1[1];
    
    InitNodeArraySet2();
    
    pP = (VU1_PRIM_BUF*)Ps2_DRAW_TMP;
    
    pFunc = pColorCalcFuncTbl[(usMode & 0xFFFF) & 0xF];
    
    pFunc(pS0, pP);
    
    _Clip_ViewVolume2((NJS_POINT4*)&pS0->fVx);
    
    fIz = pS0->fIz;
   
    pP->fS = pS0->fU * fIz;
    pP->fT = pS0->fV * fIz;
    pP->fQ = fIz;
    
    pP->ulKick = 0;
    
    pP->fX = fVu1OffsetX + pS0->fSx;
    pP->fY = fVu1OffsetY + pS0->fSy;
    pP->fZ = pS0->fVz;
    
    pP->fF = pS0->fFog;
    
    flg = _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX);
    
    flg <<= 1;
    
    pP++;
    
    pFunc(pS1, pP);
    
    _Clip_ViewVolume2((NJS_POINT4*)&pS1->fVx);
    
    fIz = pS1->fIz;
    
    pP->fS = pS1->fU * fIz;
    pP->fT = pS1->fV * fIz;
    pP->fQ = fIz;
    
    pP->ulKick = 0;
    
    pP->fX = fVu1OffsetX + pS1->fSx;
    pP->fY = fVu1OffsetY + pS1->fSy;
    pP->fZ = pS1->fVz;
    
    pP->fF = pS1->fFog;
    
    flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX);
    
    flg <<= 1;
    
    pP++; 
    
    for (usStripCnt = 2; usStripCnt < usStripMax; usStripCnt++, pS0++, pS1++, pS2++, pP++) 
    {
        pFunc(pS2, pP);
        
        _Check_ClipViewAll((NJS_POINT4*)&pS2->fVx);
        
        fIz = pS2->fIz;
        
        pP->fS = pS2->fU * fIz;
        pP->fT = pS2->fV * fIz;
        pP->fQ = fIz;
        
        pP->ulKick = 0;
        
        pP->fX = fVu1OffsetX + pS2->fSx;
        pP->fY = fVu1OffsetY + pS2->fSy;
        pP->fZ = pS2->fVz;
        
        pP->fF = pS2->fFog;
        
        flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX);
        
        clipflag = _Get_ClipViewVolume2();
        
        if ((0 < pS0->fNz) && (0 < pS1->fNz) && (0 < pS2->fNz))  
        {
            pP->ulKick = 32768;
        }
        else if (((flg & 0x7)) && ((clipflag & 0x3FFFF)))
        {
            pP->ulKick = 32768;
            
            if (_Get_ClipVolumePlane() != 0) 
            {
                _Set_NodeArray(pS2, pP);
                
                count = _Check_ScissorPlane();
                
                if (count != 0)
                {
                    DrawScissorPolygonOpaque2(count, ulType);
                }
            }
        }
        
        flg <<= 1;
    }
    
    Ps2AddPrim3DEx(ulType, Ps2_DRAW_TMP, usStripMax);
}

// 100% matching! 
void vu1DrawTriangleStripOpaqueDouble(unsigned long ulType, VU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{
    VU1_PRIM_BUF* pP;                            
    float fIz;                                   
    unsigned short usStripCnt;                  
    void (*pFunc)(VU1_STRIP_BUF*, VU1_PRIM_BUF*); 
    unsigned int clipflag;                     
    unsigned int flg;                                    
    int count;   

    InitNodeArraySet2();
    
    pP = (VU1_PRIM_BUF*)Ps2_DRAW_TMP;
    
    pFunc = pColorCalcFuncTbl[(usMode & 0xFFFF) & 0xF];
    
    pFunc(pS, pP);
    
    fIz = pS->fIz;
   
    pP->fS = pS->fU * fIz;
    pP->fT = pS->fV * fIz;
    pP->fQ = fIz;
    
    pP->ulKick = 0;

    _Clip_ViewVolume2((NJS_POINT4*)&pS->fVx);
    
    pP->fX = fVu1OffsetX + pS->fSx;
    pP->fY = fVu1OffsetY + pS->fSy;
    pP->fZ = pS->fVz;
    
    pP->fF = pS->fFog;
    
    flg = _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX);
    
    flg <<= 1;
    
    pP++;
    pS++;
    
    pFunc(pS, pP);
    
    fIz = pS->fIz;
    
    pP->fS = pS->fU * fIz;
    pP->fT = pS->fV * fIz;
    pP->fQ = fIz;
    
    pP->ulKick = 0;

    _Clip_ViewVolume2((NJS_POINT4*)&pS->fVx);
    
    pP->fX = fVu1OffsetX + pS->fSx;
    pP->fY = fVu1OffsetY + pS->fSy;
    pP->fZ = pS->fVz;
    
    pP->fF = pS->fFog;
    
    flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX);
    
    flg <<= 1;
    
    pP++; 
    pS++;
    
    for (usStripCnt = 2; usStripCnt < usStripMax; usStripCnt++, pS++, pP++) 
    {
        pFunc(pS, pP);
        
        fIz = pS->fIz;
        
        pP->fS = pS->fU * fIz;
        pP->fT = pS->fV * fIz;
        pP->fQ = fIz;
        
        pP->ulKick = 0;

        _Check_ClipViewAll((NJS_POINT4*)&pS->fVx);
        
        pP->fX = fVu1OffsetX + pS->fSx;
        pP->fY = fVu1OffsetY + pS->fSy;
        pP->fZ = pS->fVz;
        
        pP->fF = pS->fFog;
        
        flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX);
        
        clipflag = _Get_ClipViewVolume2();
        
        if (((flg & 0x7)) && ((clipflag & 0x3FFFF)))
        {
            pP->ulKick = 32768;
            
            if (_Get_ClipVolumePlane() != 0) 
            {
                _Set_NodeArray(pS, pP);
                
                count = _Check_ScissorPlane();
                
                if (count != 0)
                {
                    DrawScissorPolygonOpaque2(count, ulType);
                }
            }
        }
        
        flg <<= 1;
    }
    
    Ps2AddPrim3DEx(ulType, Ps2_DRAW_TMP, usStripMax);
}

// 100% matching! 
void vu1DrawTriangleStripTransSingle(unsigned long ulType, VU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode)
{
    VU1_PRIM_BUF* pP;                            
    VU1_STRIP_BUF* pS0, *pS1, *pS2;                         
    float fIz;                                   
    unsigned short usStripCnt;                  
    void (*pFunc)(VU1_STRIP_BUF*, VU1_PRIM_BUF*); 
    unsigned int clipflag;                     
    int flg;                                    
    int count;                                

    pS0 = pStripTop; 
    pS1 = &pS0[1];
    pS2 = &pS1[1];
    
    InitNodeArraySet2();
    
    pP = (VU1_PRIM_BUF*)Ps2_DRAW_TMP;
    
    pFunc = pColorCalcFuncTbl[(usMode & 0xFFFF) & 0xF];
    
    pFunc(pS0, pP);
    
    _Clip_ViewVolume2((NJS_POINT4*)&pS0->fVx);
    
    fIz = pS0->fIz;
   
    pP->fS = pS0->fU * fIz;
    pP->fT = pS0->fV * fIz;
    pP->fQ = fIz;
    
    pP->ulKick = 0;
    
    pP->fX = fVu1OffsetX + pS0->fSx;
    pP->fY = fVu1OffsetY + pS0->fSy;
    pP->fZ = pS0->fVz;
    
    pP->fF = pS0->fFog;
    
    flg = _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX);
    
    flg <<= 1;
    
    pP++;
    
    pFunc(pS1, pP);
    
    _Clip_ViewVolume2((NJS_POINT4*)&pS1->fVx);
    
    fIz = pS1->fIz;
    
    pP->fS = pS1->fU * fIz;
    pP->fT = pS1->fV * fIz;
    pP->fQ = fIz;
    
    pP->ulKick = 0;
    
    pP->fX = fVu1OffsetX + pS1->fSx;
    pP->fY = fVu1OffsetY + pS1->fSy;
    pP->fZ = pS1->fVz;
    
    pP->fF = pS1->fFog;
    
    flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX);
    
    flg <<= 1;
    
    pP++; 
    
    for (usStripCnt = 2; usStripCnt < usStripMax; usStripCnt++, pS0++, pS1++, pS2++, pP++) 
    {
        pFunc(pS2, pP);
        
        _Check_ClipViewAll((NJS_POINT4*)&pS2->fVx);
        
        fIz = pS2->fIz;
        
        pP->fS = pS2->fU * fIz;
        pP->fT = pS2->fV * fIz;
        pP->fQ = fIz;
        
        pP->ulKick = 0;
        
        pP->fX = fVu1OffsetX + pS2->fSx;
        pP->fY = fVu1OffsetY + pS2->fSy;
        pP->fZ = pS2->fVz;
        
        pP->fF = pS2->fFog;
        
        flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX);
        
        clipflag = _Get_ClipViewVolume2();
        
        if ((0 < pS0->fNz) && (0 < pS1->fNz) && (0 < pS2->fNz))  
        {
            pP->ulKick = 32768;
        }
        else if (((flg & 0x7)) && ((clipflag & 0x3FFFF)))
        {
            pP->ulKick = 32768;
            
            if (_Get_ClipVolumePlane() != 0) 
            {
                _Set_NodeArray(pS2, pP);
                
                count = _Check_ScissorPlane();
                
                if (count != 0)
                {
                    DrawScissorPolygonOpaque2(count, ulType);
                }
            }
        }
        
        flg <<= 1;
    }
    
    Ps2AddPrim3DEx(ulType, Ps2_DRAW_TMP, usStripMax);
}

// 99.38% matching
int _Clip_Screen(float* clip)
{
    int ret;         
    static float para[2][4] = { 2048.0f, 2048.0f, 0, 240.0f, 0.75f, 1.0f, 0, 0 }; 

    ret = 0;

    asm volatile
    ("
        lqc2       vf4, 0(%1)
        lqc2       vf5, 0(%2)
        lqc2       vf6, 16(%2)
    
        vsub.xy    vf4, vf4, vf5
        
        vmul.xyzw  vf4, vf4, vf6
        
        vclipw.xyz vf4, vf5
        vnop
        vnop
        vnop
        vnop
        vnop
    
        cfc2       %0, vi18
    " : "=r"(ret) : "f"(clip), "r"(&para) :
    );

    return ret;
}

// 97.44% matching
void vu1DrawTriangleStripTransDouble(unsigned long ulType, VU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{ 
    VU1_PRIM_BUF* pP;                            
    float fIz;                                   
    unsigned short usStripCnt;                  
    unsigned int clipflag;                     
    int flg;                                    
    int count;   
    int clipswitch;

    clipswitch = 0; 
    
    clipflag = 0;
    
    asm volatile 
    ("
    .set noreorder
        andi    v0, %0, 0xF    

        add     t0, zero, v0 
        
        ctc2    t0, vi1      
    
        vcallms VU0_INIT_CALC_COLOR 
        nop
    .set reorder
    " : "r"(usMode) : 
    );
   
    pP = (VU1_PRIM_BUF*)Ps2_DRAW_TMP; 
    
    if (clipswitch == 0) 
    { 
        asm volatile
        ("
        .set noreorder
            lqc2    vf4, VU1_STRIP_BUF.fIr(%2) 
            lqc2    vf14, VU1_STRIP_BUF.fVx(%2)
            
            vcallms VU0_CALC_COLOR  
        
            lwc1    f1, VU1_STRIP_BUF.fU(%2)
            lwc1    f2, VU1_STRIP_BUF.fV(%2) 
            lwc1    f3, VU1_STRIP_BUF.fIz(%2) 
            
            lq      t0, VU1_STRIP_BUF.fVx(%2) 
            
            lwc1    f4, VU1_STRIP_BUF.fSx(%2) 
            lwc1    f5, VU1_STRIP_BUF.fSy(%2) 
            
            mul.s   f1, f1, f3 
            mul.s   f2, f2, f3 
            
            add.s   f4, f4, %0 
            add.s   f5, f5, %1 
            
            sq      t0, VU1_PRIM_BUF.fX(%3) 
            
            swc1    f1, VU1_PRIM_BUF.fS(%3) 
            swc1    f2, VU1_PRIM_BUF.fT(%3) 
            swc1    f3, VU1_PRIM_BUF.fQ(%3) 
            
            sw      zero, VU1_PRIM_BUF.ulKick(%3) 
            
            swc1    f4, VU1_PRIM_BUF.fX(%3) 
            swc1    f5, VU1_PRIM_BUF.fY(%3) 
        .set reorder
        " : : "f"(fVu1OffsetX), "f"(fVu1OffsetY), "r"(pS), "r"(pP) : "$f1", "$f2", "$f3", "$f4", "$f5", "$t0", "memory"
        );  
            
        flg = _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX) << 2;
        
        asm volatile 
        ("
            qmfc2.i t0, vf4    
            
            sq      t0, VU1_PRIM_BUF.fR(%0) 
        " : : "r"(pP) : "$t0", "memory" 
        );
        
        pP++; 
        pS++; 
        
        asm volatile 
        (" 
        .set noreorder
            lqc2    vf4, VU1_STRIP_BUF.fIr(%2) 
            lqc2    vf14, VU1_STRIP_BUF.fVx(%2)
            
            vcallms VU0_CALC_COLOR  
        
            lwc1    f1, VU1_STRIP_BUF.fU(%2)
            lwc1    f2, VU1_STRIP_BUF.fV(%2) 
            lwc1    f3, VU1_STRIP_BUF.fIz(%2) 
            
            lq      t0, VU1_STRIP_BUF.fVx(%2) 
            
            lwc1    f4, VU1_STRIP_BUF.fSx(%2) 
            lwc1    f5, VU1_STRIP_BUF.fSy(%2) 
            
            mul.s   f1, f1, f3 
            mul.s   f2, f2, f3 
            
            add.s   f4, f4, %0 
            add.s   f5, f5, %1 
            
            sq      t0, VU1_PRIM_BUF.fX(%3) 
            
            swc1    f1, VU1_PRIM_BUF.fS(%3) 
            swc1    f2, VU1_PRIM_BUF.fT(%3) 
            swc1    f3, VU1_PRIM_BUF.fQ(%3) 
            
            sw      zero, VU1_PRIM_BUF.ulKick(%3) 
            
            swc1    f4, VU1_PRIM_BUF.fX(%3) 
            swc1    f5, VU1_PRIM_BUF.fY(%3) 
        .set reorder
        " : : "f"(fVu1OffsetX), "f"(fVu1OffsetY), "r"(pS), "r"(pP) : "$f1", "$f2", "$f3", "$f4", "$f5", "$t0", "memory"
        );
        
        flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX) << 1; 
        
        asm volatile 
        ("
            qmfc2.i t0, vf4    
            
            sq      t0, VU1_PRIM_BUF.fR(%0) 
        " : : "r"(pP) : "$t0", "memory" 
        );
        
        pP++; 
        pS++;
        
        for (usStripCnt = 2; usStripCnt < usStripMax; usStripCnt++, pS++, pP++) 
        {
            asm volatile 
            (" 
            .set noreorder
                lqc2    vf4, VU1_STRIP_BUF.fIr(%2) 
                lqc2    vf14, VU1_STRIP_BUF.fVx(%2)
                
                vcallms VU0_CLIP_VIEW_VOLUME_ALL  
            
                lwc1    f1, VU1_STRIP_BUF.fU(%2)
                lwc1    f2, VU1_STRIP_BUF.fV(%2) 
                lwc1    f3, VU1_STRIP_BUF.fIz(%2) 
                
                lq      t0, VU1_STRIP_BUF.fVx(%2) 
                
                lwc1    f4, VU1_STRIP_BUF.fSx(%2) 
                lwc1    f5, VU1_STRIP_BUF.fSy(%2) 
                
                mul.s   f1, f1, f3 
                mul.s   f2, f2, f3 
                
                add.s   f4, f4, %0 
                add.s   f5, f5, %1 
                
                sq      t0, VU1_PRIM_BUF.fX(%3) 
                
                swc1    f1, VU1_PRIM_BUF.fS(%3) 
                swc1    f2, VU1_PRIM_BUF.fT(%3) 
                swc1    f3, VU1_PRIM_BUF.fQ(%3) 
                
                sw      zero, VU1_PRIM_BUF.ulKick(%3) 
                
                swc1    f4, VU1_PRIM_BUF.fX(%3) 
                swc1    f5, VU1_PRIM_BUF.fY(%3) 
            .set reorder
            " : : "f"(fVu1OffsetX), "f"(fVu1OffsetY), "r"(pS), "r"(pP) : "$f1", "$f2", "$f3", "$f4", "$f5", "$t0", "memory"
            );
                
            flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX); 
            
            asm volatile 
            ("
                qmfc2.i t0, vf4     
                
                sq      t0, VU1_PRIM_BUF.fR(%1) 
                
                cfc2    %0, vi18    
                
                addi    %0, %0, 0
            " : "=r"(clipflag) : "r"(pP) : "$t0" 
            );

            if ((flg != 0) && ((clipflag & 0x3FFFF)))
            { 
                pP->ulKick = 32768; 
                
                if (_Get_ClipVolumePlane() != 0) 
                { 
                    _Set_NodeArray(pS, pP); 
                    
                    count = _Check_ScissorPlane(); 
                    
                    if (count != 0)
                    { 
                        DrawScissorPolygonOpaque2(count, ulType); 
                    }
                }
            }
            
            flg = (flg << 1) & 0x7; 
        } 
    }
    else
    {
        asm volatile 
        ("
        .set noreorder
            lqc2    vf4, VU1_STRIP_BUF.fIr(%0) 
            
            vcallms VU0_CALC_COLOR  
            nop
        .set reorder
        " : : "r"(pS) : 
        );   
        
        fIz = pS->fIz; 
        
        pP->fS = pS->fU * fIz; 
        pP->fT = pS->fV * fIz; 
        pP->fQ = fIz; 
        
        pP->ulKick = 0; 
        
        pP->fX = fVu1OffsetX + pS->fSx; 
        pP->fY = fVu1OffsetY + pS->fSy; 
        pP->fZ = pS->fVz; 
        
        pP->fF = pS->fFog; 
        
        asm volatile 
        ("
            sqc2 vf4, VU1_PRIM_BUF.fR(%0) 
            nop                         
        " : : "r"(pP) : 
        );

        _Clip_ViewVolume2((NJS_POINT4*)&pS->fVx); 
        
        pP++; 
        pS++; 

        asm volatile 
        ("
        .set noreorder
            lqc2    vf4, VU1_STRIP_BUF.fIr(%0) 
            
            vcallms VU0_CALC_COLOR  
            nop
        .set reorder
        " : : "r"(pS) : 
        );
        
        fIz = pS->fIz; 
        
        pP->fS = pS->fU * fIz;  
        pP->fT = pS->fV * fIz;
        pP->fQ = fIz; 
        
        pP->ulKick = 0; 
        
        pP->fX = fVu1OffsetX + pS->fSx; 
        pP->fY = fVu1OffsetY + pS->fSy; 
        pP->fZ = pS->fVz; 
        
        pP->fF = pS->fFog; 
        
        asm volatile 
        ("
            sqc2 vf4, VU1_PRIM_BUF.fR(%0) 
            nop                         
        " : : "r"(pP) : 
        );
    
        _Clip_ViewVolume2((NJS_POINT4*)&pS->fVx); 
        
        pP++; 
        pS++; 
        
        for (usStripCnt = 2; usStripCnt < usStripMax; usStripCnt++, pS++, pP++) 
        {
            asm volatile 
            ("
            .set noreorder
                lqc2    vf4, VU1_STRIP_BUF.fIr(%0) 
                
                vcallms VU0_CALC_COLOR  
                nop
            .set reorder
            " : : "r"(pS) : 
            );
            
            fIz = pS->fIz; 
            
            pP->fS = pS->fU * fIz;
            pP->fT = pS->fV * fIz; 
            pP->fQ = fIz; 
            
            pP->ulKick = 0; 
            
            pP->fX = fVu1OffsetX + pS->fSx; 
            pP->fY = fVu1OffsetY + pS->fSy; 
            pP->fZ = pS->fVz; 
            
            pP->fF = pS->fFog; 
            
            asm volatile 
            ("
                sqc2 vf4, VU1_PRIM_BUF.fR(%0) 
                nop                         
            " : : "r"(pP) : 
            );
            
            _Clip_ViewVolume2((NJS_POINT4*)&pS->fVx); 
            
            clipflag = _Get_ClipViewVolume2(); 
            
            if ((clipflag & 0x3FFFF))
            { 
                pP->ulKick = 32768; 
            } 
        } 
    } 
    
    Ps2AddPrim3DEx(ulType, Ps2_DRAW_TMP, usStripMax); 
} 

// 100% matching!
void vu1GetVertexColor(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2      vf4, VU1_STRIP_BUF.fIr(%0)
        
        mfc1      t0, %2
        mfc1      t1, %2
        mfc1      t2, %2
        mfc1      t3, %3
        
        pextlw    t0, t1, t0
        pextlw    t2, t3, t2
        pcpyld    t0, t2, t0
    
        qmtc2     t0, vf5
    
        vmul.xyzw vf4, vf4, vf5 
        
        sqc2      vf4, VU1_PRIM_BUF.fR(%1)
    " : : "r"(pStrip), "r"(pPrim), "f"(128.0f), "f"(256.0f) : "$t0", "$t1", "$t2", "$t3"
    );
}

// 100% matching!
void vu1GetVertexColorCM(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim) // first parameter is not present on the debugging symbols
{
    asm volatile 
    ("
        lqc2    vf4, VU1_COLOR.fR(%1)

        lw      t0, fVu1AlphaRatio

        qmtc2   t0, vf5 
    
        vmulx.w vf4, vf0, vf5x 

        sqc2    vf4, VU1_PRIM_BUF.fR(%0)
    " : : "r"(pPrim), "r"(&vu1Diffuse), "f"(fVu1AlphaRatio) : "$v1", "$t0"
    );
}

// 100% matching!
void vu1GetVertexColorIgnore(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim) // first parameter is not present on the debugging symbols
{
    asm volatile 
    ("
        addi        t0, zero, 128
        
        qmtc2       t0, vf5
        
        vitof0.xyzw vf5, vf5
        
        lw          t1, fVu1AlphaRatio
    
        qmtc2       t1, vf6
    
        vaddx.xyz   vf4, vf0, vf5x
        vmulx.w     vf4, vf0, vf6x 

        sqc2        vf4, VU1_PRIM_BUF.fR(%0)
    " : : "r"(pPrim), "f"(fVu1AlphaRatio) : "$t1"
    );
}

// 100% matching!
void vu1GetVertexColorDif(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(%0)
        lqc2       vf5, VU1_COLOR.fR(%2)

        lw         t0, fVu1AlphaRatio

        vminiw.xyz vf4, vf4, vf0w
        vmaxx.xyz  vf4, vf4, vf0x 
        
        qmtc2      t0, vf6 

        vmul.xyz   vf4, vf4, vf5
        vmulx.w    vf4, vf0, vf6x 

        sqc2       vf4, VU1_PRIM_BUF.fR(%1)
    " : : "r"(pStrip), "r"(pPrim), "r"(&vu1Diffuse), "f"(fVu1AlphaRatio) : "$v1", "$t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifAmb(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim) 
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(%0)

        lw         t0, fVu1AlphaRatio
        
        qmtc2      t0, vf8

        vadd.xyz   vf7, vf4, vf22
        
        vmaxx.xyz  vf7, vf7, vf0x
        vminiw.xyz vf7, vf7, vf0w
        
        vmul.xyz   vf4, vf7, vf20
        vmulx.w    vf4, vf0, vf8x 

        sqc2       vf4, VU1_PRIM_BUF.fR(%1)
    " : : "r"(pStrip), "r"(pPrim), "f"(fVu1AlphaRatio) : "$t0"
    );
}

// 96.47% matching
void vu1GetVertexColorDifSpe1(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(%0)

        lw         t0, fVu1AlphaRatio
    
        vmove.xyzw vf5, vf4
        vmove.xyzw vf6, vf4
        
        qmtc2      t0, vf8
    
        vsubw.xyz  vf7, vf4, vf0w

        vmaxx.xyz  vf4, vf4, vf0x
        vminiw.xyz vf4, vf4, vf0w
        
        vmaxx.xyz  vf7, vf7, vf0x
        vminiw.xyz vf7, vf7, vf0w
        
        vmul.xyz   vf4, vf4, vf5
        vmul.xyz   vf7, vf7, vf6
        
        vadd.xyz   vf4, vf4, vf7
        
        vmulx.w    vf4, vf0, vf8x 

        sqc2       vf4, VU1_PRIM_BUF.fR(%1)
    " : : "r"(pStrip), "r"(pPrim), "f"(fVu1AlphaRatio) : "$t0", "memory"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe2(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(%0)
        lqc2       vf5, VU1_COLOR.fR(%2)
        lqc2       vf6, VU1_COLOR.fR(%3)
        lqc2       vf7, VU1_COLOR.fR(%4)

        lw         t0, fVu1AlphaRatio
        
        qmtc2      t0, vf8
    
        vadd.xyz   vf5, vf4, vf5
        vsubw.xyz  vf5, vf5, vf0w

        vmaxx.xyz  vf4, vf4, vf0x
        vminiw.xyz vf4, vf4, vf0w
        
        vmaxx.xyz  vf5, vf5, vf0x
        vminiw.xyz vf5, vf5, vf0w
        
        vmul.xyz   vf4, vf4, vf6
        vmul.xyz   vf5, vf5, vf7
        
        vadd.xyz   vf4, vf4, vf5
        
        vmulx.w    vf4, vf0, vf8x 

        sqc2       vf4, VU1_PRIM_BUF.fR(%1)
    " : : "r"(pStrip), "r"(pPrim), "r"(&vu1Ambient), "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "$v1", "$a2", "$a3", "$t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe3(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(%0)
        lqc2       vf5, VU1_COLOR.fR(%2)
        lqc2       vf6, VU1_COLOR.fR(%3)

        lw         t0, fVu1AlphaRatio
        
        qmtc2      t0, vf8

        addi       t1, zero, 17

        vaddw.xyz  vf7, vf0, vf0w

        l_002D5770:
        vmul.xyz   vf7, vf7, vf4

        addi       t1, t1, -1
        nop
        nop
        nop

        bnez       t1, l_002D5770
        nop

        vmaxx.xyz  vf4, vf4, vf0x
        vminiw.xyz vf4, vf4, vf0w
        
        vmaxx.xyz  vf7, vf7, vf0x
        vminiw.xyz vf7, vf7, vf0w
        
        vmul.xyz   vf4, vf4, vf5
        vmul.xyz   vf7, vf7, vf6
        
        vadd.xyz   vf4, vf4, vf7
        
        vmulx.w    vf4, vf0, vf8x 

        sqc2       vf4, VU1_PRIM_BUF.fR(%1)
    " : : "r"(pStrip), "r"(pPrim), "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "$v1", "$a2", "$t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe1Amb(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(%0)
        lqc2       vf5, VU1_COLOR.fR(%2)
        lqc2       vf6, VU1_COLOR.fR(%3)
        lqc2       vf7, VU1_COLOR.fR(%4)

        lw         t0, fVu1AlphaRatio
        
        qmtc2      t0, vf8
    
        vsubw.xyz  vf9, vf4, vf0w

        vmaxx.xyz  vf9, vf9, vf0x
        vminiw.xyz vf9, vf9, vf0w

        vadd.xyz   vf4, vf4, vf5
        
        vmaxx.xyz  vf4, vf4, vf0x
        vminiw.xyz vf4, vf4, vf0w
        
        vmul.xyz   vf9, vf9, vf7
        vmul.xyz   vf4, vf4, vf6
        
        vadd.xyz   vf4, vf4, vf9
        
        vmulx.w    vf4, vf0, vf8x 

        sqc2       vf4, VU1_PRIM_BUF.fR(%1)
    " : : "r"(pStrip), "r"(pPrim), "r"(&vu1Ambient), "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "$v1", "$a2", "$a3", "$t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe2Amb(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(%0)
        lqc2       vf5, VU1_COLOR.fR(%2)
        lqc2       vf6, VU1_COLOR.fR(%3)
        lqc2       vf7, VU1_COLOR.fR(%4)

        lw         t0, fVu1AlphaRatio
        
        qmtc2      t0, vf8

        vadd.xyz   vf4, vf4, vf5
        vsubw.xyz  vf9, vf4, vf0w

        vmaxx.xyz  vf9, vf9, vf0x
        vminiw.xyz vf9, vf9, vf0w
        
        vmaxx.xyz  vf4, vf4, vf0x
        vminiw.xyz vf4, vf4, vf0w
        
        vmul.xyz   vf9, vf9, vf7
        vmul.xyz   vf4, vf4, vf6
        
        vadd.xyz   vf4, vf4, vf9
        
        vmulx.w    vf4, vf0, vf8x 

        sqc2       vf4, VU1_PRIM_BUF.fR(%1)
    " : : "r"(pStrip), "r"(pPrim), "r"(&vu1Ambient), "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "$v1", "$a2", "$a3", "$t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe3Amb(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(%0)
        lqc2       vf5, VU1_COLOR.fR(%2)
        lqc2       vf6, VU1_COLOR.fR(%3)
        lqc2       vf7, VU1_COLOR.fR(%4)

        lw         t0, fVu1AlphaRatio
        
        qmtc2      t0, vf8

        vadd.xyz   vf4, vf4, vf5

        addi       t1, zero, 17

        vaddw.xyz  vf9, vf0, vf0w

        l_002D58E0:
        vmul.xyz   vf9, vf9, vf4

        addi       t1, t1, -1
        nop
        nop
        nop

        bnez       t1, l_002D58E0
        nop

        vmaxx.xyz  vf4, vf4, vf0x
        vminiw.xyz vf4, vf4, vf0w
        
        vmaxx.xyz  vf9, vf9, vf0x
        vminiw.xyz vf9, vf9, vf0w
        
        vmul.xyz   vf4, vf4, vf6
        vmul.xyz   vf9, vf9, vf7
        
        vadd.xyz   vf4, vf4, vf9
        
        vmulx.w    vf4, vf0, vf8x 

        sqc2       vf4, VU1_PRIM_BUF.fR(%1)
    " : : "r"(pStrip), "r"(pPrim), "r"(&vu1Ambient), "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "$v1", "$a2", "$a3", "$t0"
    );
}

// 100% matching! 
void vu1RotTransStripBuf(NJS_MATRIX* pMatrix, NJS_VECTOR* pVector, VU1_STRIP_BUF* pBuf)
{
    float fZ;
    float fIz;
    
    njCalcPoint(pMatrix, pVector, (NJS_POINT3*)&pBuf->fVx);
    
    fIz = 1.0f / pBuf->fVz;
    
    fZ = fVu1Projection * fIz;
    
    pBuf->fSx = fVu1AspectW * (pBuf->fVx * fZ);
    pBuf->fSy = fVu1AspectH * (pBuf->fVy * fZ);
    
    pBuf->fIz = fIz;
    
    pBuf->fFog = njCalcFogPowerEx(fIz);
}

// 100% matching! 
void vu1DrawTriangleStripTransDoubleI(unsigned long ulType, VU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{ 
    VU1_PRIM_BUF* pP;                              
    unsigned short usStripCnt;                      
    void (*pFunc)(VU1_STRIP_BUF*, VU1_PRIM_BUF*); 
    unsigned int clipflag;                                     
    int flg;                                              

    clipflag = 0; 
    flg = 0;

    InitNodeArraySet(&scissorflip); 
    
    pP = (VU1_PRIM_BUF*)Ps2_DRAW_TMP; 
    
    pFunc = pColorCalcFuncTbl[usMode & 0xF]; 
    
    for (usStripCnt = 0; usStripCnt < usStripMax; usStripCnt++, pS++, pP++) 
    {
        pFunc(pS, pP);
        
        asm volatile
        ("
            lqc2       vf4, VU1_STRIP_BUF.fSx(%2)   
            lqc2       vf5, VU1_STRIP_BUF.fU(%2)    
            lqc2       vf6, VU1_STRIP_BUF.fVx(%2)    
            
            vmulz.xy   vf5, vf5, vf4z  
            
            vadd.z     vf5, vf0, vf4   
            vsub.w     vf5, vf5, vf5   
            
            sqc2       vf5, VU1_PRIM_BUF.fS(%3)      
        
            lqc2       vf8, VU1_STRIP_BUF.fVx(%2)    
            lqc2       vf10, VU1_STRIP_BUF.fU(%2)   
            lqc2       vf9, VU1_PRIM_BUF.fR(%3)    
        
            vmulax     ACC, vf24, vf8x
            
            vmadday    ACC, vf25, vf8y 
            vmaddaz    ACC, vf26, vf8z 
            vmaddw     vf11, vf27, vf0w 
            
            vclipw.xyz vf11, vf11w       
            
            vmove      vf7, vf6         
            
            vadd.xy    vf7, vf4, vf16  
            
            sqc2       vf7, VU1_PRIM_BUF.fX(%3)   
            
            lw         t1, 0(%1)     
            
            cfc2.ni    t0, vi18        
            
            andi       t0, t0, 0x3F   
            or         t1, t0, t1     
            
            sw         t1, 0(%1)     
            
            lw         t2, SCISSOR.rotflag(%0)   
            
            muli       t3, t2, 64    
        
            addi       t2, t2, 1     
            add        t4, t3, %0      
            
            andi       t2, t2, 0x3   
            
            sqc2       vf8, SCISSOR.triangle.node[0].vertex(t4)    
            sqc2       vf9, SCISSOR.triangle.node[0].color(t4)    
            sqc2       vf10, SCISSOR.triangle.node[0].texUV(t4)   
            sqc2       vf11, SCISSOR.triangle.node[0].clipV(t4) 
            
            addi       t5, t2, -3    
            
            bltz       t5, l_002D5AE0        
            vnop                    
        
            neg        t2, zero   
            
            l_002D5AE0:
            sw         t2, SCISSOR.rotflag(%0)    
        " : : "r"(&scissorflip), "r"(&clipflag), "r"(pS), "r"(pP) : "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "memory");
    
        flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX); 
        
        if ((((flg & 0x7)) && ((clipflag & 0x3FFFF))) && (usStripCnt >= 2)) 
        { 
            pP->ulKick = 32768;
            
            ScissorTriangle(&scissorflip, &planeset); 
            
            if (scissorflip.in->nodeNum != 0) 
            { 
                DrawScissorPolygonOpaque(&scissorflip, ulType); 
       
                ResetNodeArraySet(&scissorflip); 
            } 
        }
        
        clipflag <<= 6; 
        flg <<= 1; 
    } 
    
    Ps2AddPrim3DExI(ulType, Ps2_DRAW_TMP, usStripMax); 
} 

// 100% matching!
void DrawScissorPolygonTrans1P(SCISSOR* scissor, unsigned long ulType)
{
    SCISSOR_NODE* in; 
    VU1_PRIM_BUF* pP; // not from the debugging symbols

    in = scissor->in;
    
    asm volatile
    ("
        addi     t6, %0, SCISSOR.in
    
        lw       t6, SCISSOR.triangle.node[0](t6)
        
        add      t7, zero, %1
    
        lw       t0, SCISSOR_NODE.nodeNum(t6)
        nop
        
        l_002D4720:
        lqc2     vf4, SCISSOR.triangle.node[0].vertex(t6)
        
        vdiv     Q, vf0w, vf4z
    
        lqc2     vf7, SCISSOR.triangle.node[0].color(t6)
        
        sqc2     vf7, VU1_PRIM_BUF.fR(t7)
    
        vaddz.x  vf5, vf0, vf23z
        
        lqc2     vf6, SCISSOR.triangle.node[0].texUV(t6)
    
        addi     t0, t0, -1
        
        vwaitq
        
        vmulq.x  vf5, vf5, Q
        vmulq.xy vf6, vf6, Q
        
        vaddq.z  vf6, vf0, Q
        
        vsub.w   vf6, vf6, vf6
        
        vmulx.xy vf4, vf4, vf5x
        
        sqc2     vf6, VU1_PRIM_BUF.fS(t7)
    
        vmul.xy  vf4, vf4, vf17
        
        vadd.xy  vf4, vf4, vf16
        
        addi     t6, t6, sizeof(NODE)
    
        sqc2     vf4, VU1_PRIM_BUF.fX(t7)
    
        addi     t7, t7, sizeof(VU1_PRIM_BUF)
    
        bnez     t0, l_002D4720
        vnop
    " : : "r"(scissor), "r"(vu1ScessorBuf) : "t7"
    );

    ulType = (ulType & 0xFFFDFFFFFFFFFFFF) | 0x6800000000000;
    
    pP = vu1ScessorBuf;
    
    Ps2AddPrim3DEx1P(ulType, pP, in->nodeNum);
}

// 100% matching!
void vu1DrawTriangleStripTransDouble1P(unsigned long ulType, VU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{ 
    VU1_PRIM_BUF* pP;                                      
    float fIz;                                    
    float sam;                                    
    unsigned short usStripCnt;                                   
    void (*pFunc)(VU1_STRIP_BUF*, VU1_PRIM_BUF*); 
    unsigned int clipflag;                                                           
    int flg;                                                             

    clipflag = 0; 
    flg = 0;

    InitNodeArraySet(&scissorflip); 
    
    pP = (VU1_PRIM_BUF*)Ps2_DRAW_TMP; 

    sam = 0;
    
    pFunc = pColorCalcFuncTbl[usMode & 0xF]; 
    
    for (usStripCnt = 0; usStripCnt < usStripMax; usStripCnt++)
    {
        sam += pS[usStripCnt].fVz;
    }
    
    Ps2AddPrimPrio = sam / usStripMax;
    
    for (usStripCnt = 0; usStripCnt < usStripMax; usStripCnt++, pS++, pP++) 
    {
        pFunc(pS, pP);

        fIz = pS->fIz;
       
        pP->fS = pS->fU * fIz;
        pP->fT = pS->fV * fIz;
        pP->fQ = fIz;
        
        pP->fX = fVu1OffsetX + pS->fSx;
        pP->fY = fVu1OffsetY + pS->fSy;
        pP->fZ = pS->fVz;
        
        pP->fF = pS->fFog;

        pP->ulKick = 0;

        clipflag |= _Clip_ViewVolume(node.clipV, ClipMatrix2[0], &pS->fVx) & 0x3F;
    
        flg |= _Check_DisplayAreaPoint((NJS_VECTOR*)&pP->fX); 

        *(u_long128*)&node.texUV = *(u_long128*)&pS->fU;
        *(u_long128*)&node.vertex = *(u_long128*)&pS->fVx;
        *(u_long128*)&node.color = *(u_long128*)&pP->fR;
        
        PushTriangleNodeArray(&scissorflip, &node);

        if ((((flg & 0x7)) && ((clipflag & 0x3FFFF))) && (usStripCnt >= 2)) 
        { 
            pP->ulKick = 32768;
            
            ScissorTriangle(&scissorflip, &planeset); 
            
            if (scissorflip.in->nodeNum != 0) 
            { 
                DrawScissorPolygonTrans1P(&scissorflip, ulType); 
       
                ResetNodeArraySet(&scissorflip); 
            } 
        }
        
        clipflag <<= 6; 
        flg <<= 1; 
    } 
    
    Ps2AddPrim3DEx1P(ulType, Ps2_DRAW_TMP, usStripMax); 
} 
