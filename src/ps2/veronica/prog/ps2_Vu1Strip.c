#include "ps2_Vu1Strip.h"
#include "ps2_NaFog.h"
#include "ps2_NaView.h"
#include "ps2_dummy.h"
#include "main.h"

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
        lq         t3, 0(a0)
    
        mfc1       t0, %0
        mfc1       t1, %0
        mfc1       t2, %0
        
        pextlw     t0, t1, t0 
        pcpyld     t0, t2, t0 
    
        qmtc2      t3, $vf4 
        qmtc2      t0, $vf5 
    
        vmul.xyz   $vf4,  $vf4, $vf5 
        vaddx.xyzw $vf20, $vf4, $vf0x 
    " : : "f"(128.0f) : "t0", "t1", "t2"
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
    
    asm volatile(lqc2 vf22, 0(a0));
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

// 100% matching!
void InitNodeArraySet(register SCISSOR* scissor)
{
    scissor->rotflag = 0;
    scissor->flipflag = 0;

    asm volatile {
        
        add  t0, zero, scissor
        
        addi t2, zero, 3
        
        addi t0, t0, SCISSOR.narray
        addi t1, t0, sizeof(SCISSOR_NODE)
        
        sw   t0, SCISSOR.in(scissor)
        sw   t1, SCISSOR.out(scissor)
        
        sw   zero, SCISSOR_NODE.nodeNum(t0)
        sw   zero, SCISSOR_NODE.nodeNum(t1)
        
        sw   t2, SCISSOR_NODE.nodeNum(scissor)
            
    }
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
int _Clip_ViewVolume(register float* clip, register float local_clip[4], register float* vertex)
{
    asm volatile
    {
        
        lqc2         $vf4, 0(vertex)
            
        vmulax.xyzw  ACC,  $vf24, $vf4x
            
        vmadday.xyzw ACC,  $vf25, $vf4y
        vmaddaz.xyzw ACC,  $vf26, $vf4z
            
        vmaddw.xyzw  $vf5, $vf27, $vf0w
            
        vclipw.xyz   $vf5xyz, $vf5w
        vnop
        vnop
        vnop
        vnop
        
        sqc2         $vf5, 0(clip)
        
        cfc2         v0, $vi18
        
    }
}

// 100% matching!
void PushTriangleNodeArray(register SCISSOR* scissor)
{
    asm volatile 
    ("
        move   v1, %0
        
        lw     t0, SCISSOR.rotflag(scissor)
        
        daddiu at, zero, sizeof(NODE)
    
        mult   t0, at
        nop
        nop
    
        mflo   t1
    
        addi   t0, t0, 1
        add    t1, t1, scissor
        
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
        sw     t0, SCISSOR.rotflag(scissor)
    " : : "r"(&node) : "v1"
    );
}

// 100% matching!
void ResetNodeArraySet(register SCISSOR* scissor)
{
    scissor->flipflag = 0;

    asm volatile 
    {
        
        add  t0, zero, scissor
        
        addi t2, zero, 3
        
        addi t0, t0, SCISSOR.narray
        addi t1, t0, sizeof(SCISSOR_NODE)
        
        sw   t0, SCISSOR.in(scissor)
        sw   t1, SCISSOR.out(scissor)
        
        sw   zero, SCISSOR_NODE.nodeNum(t0)
        sw   zero, SCISSOR_NODE.nodeNum(t1)
        
    }
}

// 
// Start address: 0x2d4190
void ScissorTriangle(SCISSOR* scissor, SCISSOR_PLANE* plane_set)
{
	int n;
	//_anon4 interN;
	//_anon4* nextN;
	//_anon4* currN;
	//_anon0* outarray;
	//_anon0* inarray;
	float sgn;
	int xyz;
	int mask;
	int clip;
	int j;
	int i;
	// Line 943, Address: 0x2d4190, Func Offset: 0
	// Line 894, Address: 0x2d4194, Func Offset: 0x4
	// Line 942, Address: 0x2d4198, Func Offset: 0x8
	// Line 949, Address: 0x2d419c, Func Offset: 0xc
	// Line 954, Address: 0x2d41a4, Func Offset: 0x14
	// Line 955, Address: 0x2d41b0, Func Offset: 0x20
	// Line 956, Address: 0x2d41b4, Func Offset: 0x24
	// Line 957, Address: 0x2d41c8, Func Offset: 0x38
	// Line 958, Address: 0x2d41cc, Func Offset: 0x3c
	// Line 959, Address: 0x2d41d0, Func Offset: 0x40
	// Line 960, Address: 0x2d41d4, Func Offset: 0x44
	// Line 961, Address: 0x2d41d8, Func Offset: 0x48
	// Line 962, Address: 0x2d41dc, Func Offset: 0x4c
	// Line 963, Address: 0x2d41e0, Func Offset: 0x50
	// Line 964, Address: 0x2d41e4, Func Offset: 0x54
	// Line 965, Address: 0x2d41e8, Func Offset: 0x58
	// Line 966, Address: 0x2d41ec, Func Offset: 0x5c
	// Line 967, Address: 0x2d41f0, Func Offset: 0x60
	// Line 968, Address: 0x2d41f4, Func Offset: 0x64
	// Line 969, Address: 0x2d41f8, Func Offset: 0x68
	// Line 970, Address: 0x2d41fc, Func Offset: 0x6c
	// Line 972, Address: 0x2d4200, Func Offset: 0x70
	// Line 975, Address: 0x2d4208, Func Offset: 0x78
	// Line 976, Address: 0x2d420c, Func Offset: 0x7c
	// Line 977, Address: 0x2d4210, Func Offset: 0x80
	// Line 978, Address: 0x2d4214, Func Offset: 0x84
	// Line 979, Address: 0x2d4228, Func Offset: 0x98
	// Line 980, Address: 0x2d422c, Func Offset: 0x9c
	// Line 981, Address: 0x2d4230, Func Offset: 0xa0
	// Line 982, Address: 0x2d4238, Func Offset: 0xa8
	// Line 983, Address: 0x2d423c, Func Offset: 0xac
	// Line 985, Address: 0x2d4240, Func Offset: 0xb0
	// Line 986, Address: 0x2d4254, Func Offset: 0xc4
	// Line 987, Address: 0x2d4258, Func Offset: 0xc8
	// Line 991, Address: 0x2d425c, Func Offset: 0xcc
	// Line 992, Address: 0x2d4260, Func Offset: 0xd0
	// Line 993, Address: 0x2d4264, Func Offset: 0xd4
	// Line 994, Address: 0x2d4268, Func Offset: 0xd8
	// Line 995, Address: 0x2d426c, Func Offset: 0xdc
	// Line 996, Address: 0x2d4270, Func Offset: 0xe0
	// Line 997, Address: 0x2d4274, Func Offset: 0xe4
	// Line 998, Address: 0x2d4278, Func Offset: 0xe8
	// Line 999, Address: 0x2d427c, Func Offset: 0xec
	// Line 1000, Address: 0x2d4280, Func Offset: 0xf0
	// Line 1002, Address: 0x2d4284, Func Offset: 0xf4
	// Line 1003, Address: 0x2d428c, Func Offset: 0xfc
	// Line 1006, Address: 0x2d4294, Func Offset: 0x104
	// Line 1007, Address: 0x2d4298, Func Offset: 0x108
	// Line 1008, Address: 0x2d42ac, Func Offset: 0x11c
	// Line 1009, Address: 0x2d42b0, Func Offset: 0x120
	// Line 1010, Address: 0x2d42b4, Func Offset: 0x124
	// Line 1011, Address: 0x2d42b8, Func Offset: 0x128
	// Line 1012, Address: 0x2d42bc, Func Offset: 0x12c
	// Line 1013, Address: 0x2d42c0, Func Offset: 0x130
	// Line 1014, Address: 0x2d42c4, Func Offset: 0x134
	// Line 1015, Address: 0x2d42c8, Func Offset: 0x138
	// Line 1016, Address: 0x2d42cc, Func Offset: 0x13c
	// Line 1017, Address: 0x2d42d0, Func Offset: 0x140
	// Line 1020, Address: 0x2d42d4, Func Offset: 0x144
	// Line 1021, Address: 0x2d42f4, Func Offset: 0x164
	// Line 1023, Address: 0x2d4310, Func Offset: 0x180
	// Line 1024, Address: 0x2d4318, Func Offset: 0x188
	// Line 1025, Address: 0x2d431c, Func Offset: 0x18c
	// Line 1026, Address: 0x2d4320, Func Offset: 0x190
	// Line 1027, Address: 0x2d4328, Func Offset: 0x198
	// Line 1028, Address: 0x2d432c, Func Offset: 0x19c
	// Line 1029, Address: 0x2d4330, Func Offset: 0x1a0
	// Line 1030, Address: 0x2d4334, Func Offset: 0x1a4
	// Line 1031, Address: 0x2d4338, Func Offset: 0x1a8
	// Line 1032, Address: 0x2d433c, Func Offset: 0x1ac
	// Line 1033, Address: 0x2d4340, Func Offset: 0x1b0
	// Line 1034, Address: 0x2d4344, Func Offset: 0x1b4
	// Line 1035, Address: 0x2d4348, Func Offset: 0x1b8
	// Line 1036, Address: 0x2d434c, Func Offset: 0x1bc
	// Line 1037, Address: 0x2d4350, Func Offset: 0x1c0
	// Line 1038, Address: 0x2d4358, Func Offset: 0x1c8
	// Line 1039, Address: 0x2d435c, Func Offset: 0x1cc
	// Line 1041, Address: 0x2d4360, Func Offset: 0x1d0
	// Line 1044, Address: 0x2d4368, Func Offset: 0x1d8
	// Line 1045, Address: 0x2d436c, Func Offset: 0x1dc
	// Line 1046, Address: 0x2d4370, Func Offset: 0x1e0
	// Line 1047, Address: 0x2d4374, Func Offset: 0x1e4
	// Line 1048, Address: 0x2d4378, Func Offset: 0x1e8
	// Line 1049, Address: 0x2d437c, Func Offset: 0x1ec
	// Line 1050, Address: 0x2d4380, Func Offset: 0x1f0
	// Line 1051, Address: 0x2d4384, Func Offset: 0x1f4
	// Line 1052, Address: 0x2d4388, Func Offset: 0x1f8
	// Line 1053, Address: 0x2d438c, Func Offset: 0x1fc
	// Line 1054, Address: 0x2d4390, Func Offset: 0x200
	// Line 1055, Address: 0x2d4394, Func Offset: 0x204
	// Line 1056, Address: 0x2d4398, Func Offset: 0x208
	// Line 1057, Address: 0x2d439c, Func Offset: 0x20c
	// Line 1058, Address: 0x2d43a0, Func Offset: 0x210
	// Line 1059, Address: 0x2d43a4, Func Offset: 0x214
	// Line 1060, Address: 0x2d43a8, Func Offset: 0x218
	// Line 1061, Address: 0x2d43ac, Func Offset: 0x21c
	// Line 1062, Address: 0x2d43b0, Func Offset: 0x220
	// Line 1063, Address: 0x2d43b4, Func Offset: 0x224
	// Line 1064, Address: 0x2d43b8, Func Offset: 0x228
	// Line 1065, Address: 0x2d43bc, Func Offset: 0x22c
	// Line 1066, Address: 0x2d43c0, Func Offset: 0x230
	// Line 1067, Address: 0x2d43c4, Func Offset: 0x234
	// Line 1068, Address: 0x2d43c8, Func Offset: 0x238
	// Line 1069, Address: 0x2d43cc, Func Offset: 0x23c
	// Line 1070, Address: 0x2d43d0, Func Offset: 0x240
	// Line 1071, Address: 0x2d43d4, Func Offset: 0x244
	// Line 1072, Address: 0x2d43d8, Func Offset: 0x248
	// Line 1073, Address: 0x2d43dc, Func Offset: 0x24c
	// Line 1077, Address: 0x2d43e0, Func Offset: 0x250
	// Line 1078, Address: 0x2d43e4, Func Offset: 0x254
	// Line 1079, Address: 0x2d43f8, Func Offset: 0x268
	// Line 1080, Address: 0x2d43fc, Func Offset: 0x26c
	// Line 1081, Address: 0x2d4400, Func Offset: 0x270
	// Line 1082, Address: 0x2d4404, Func Offset: 0x274
	// Line 1083, Address: 0x2d4408, Func Offset: 0x278
	// Line 1084, Address: 0x2d440c, Func Offset: 0x27c
	// Line 1085, Address: 0x2d4410, Func Offset: 0x280
	// Line 1086, Address: 0x2d4414, Func Offset: 0x284
	// Line 1087, Address: 0x2d4418, Func Offset: 0x288
	// Line 1088, Address: 0x2d441c, Func Offset: 0x28c
	// Line 1089, Address: 0x2d4420, Func Offset: 0x290
	// Line 1092, Address: 0x2d4424, Func Offset: 0x294
	// Line 1093, Address: 0x2d4428, Func Offset: 0x298
	// Line 1094, Address: 0x2d442c, Func Offset: 0x29c
	// Line 1095, Address: 0x2d4440, Func Offset: 0x2b0
	// Line 1096, Address: 0x2d4444, Func Offset: 0x2b4
	// Line 1097, Address: 0x2d4448, Func Offset: 0x2b8
	// Line 1098, Address: 0x2d444c, Func Offset: 0x2bc
	// Line 1099, Address: 0x2d4450, Func Offset: 0x2c0
	// Line 1100, Address: 0x2d4454, Func Offset: 0x2c4
	// Line 1101, Address: 0x2d4458, Func Offset: 0x2c8
	// Line 1102, Address: 0x2d445c, Func Offset: 0x2cc
	// Line 1103, Address: 0x2d4460, Func Offset: 0x2d0
	// Line 1104, Address: 0x2d4464, Func Offset: 0x2d4
	// Line 1107, Address: 0x2d4468, Func Offset: 0x2d8
	// Line 1109, Address: 0x2d4488, Func Offset: 0x2f8
	// Line 1110, Address: 0x2d4490, Func Offset: 0x300
	// Line 1111, Address: 0x2d4494, Func Offset: 0x304
	// Line 1112, Address: 0x2d4498, Func Offset: 0x308
	// Line 1113, Address: 0x2d44a0, Func Offset: 0x310
	// Line 1114, Address: 0x2d44a4, Func Offset: 0x314
	// Line 1115, Address: 0x2d44a8, Func Offset: 0x318
	// Line 1116, Address: 0x2d44ac, Func Offset: 0x31c
	// Line 1117, Address: 0x2d44b0, Func Offset: 0x320
	// Line 1118, Address: 0x2d44b4, Func Offset: 0x324
	// Line 1119, Address: 0x2d44b8, Func Offset: 0x328
	// Line 1120, Address: 0x2d44bc, Func Offset: 0x32c
	// Line 1121, Address: 0x2d44c0, Func Offset: 0x330
	// Line 1122, Address: 0x2d44c4, Func Offset: 0x334
	// Line 1123, Address: 0x2d44c8, Func Offset: 0x338
	// Line 1124, Address: 0x2d44d0, Func Offset: 0x340
	// Line 1125, Address: 0x2d44d4, Func Offset: 0x344
	// Line 1127, Address: 0x2d44d8, Func Offset: 0x348
	// Line 1130, Address: 0x2d44e0, Func Offset: 0x350
	// Line 1131, Address: 0x2d44e4, Func Offset: 0x354
	// Line 1132, Address: 0x2d44e8, Func Offset: 0x358
	// Line 1133, Address: 0x2d44ec, Func Offset: 0x35c
	// Line 1134, Address: 0x2d44f0, Func Offset: 0x360
	// Line 1135, Address: 0x2d44f4, Func Offset: 0x364
	// Line 1136, Address: 0x2d44f8, Func Offset: 0x368
	// Line 1137, Address: 0x2d44fc, Func Offset: 0x36c
	// Line 1138, Address: 0x2d4500, Func Offset: 0x370
	// Line 1139, Address: 0x2d4504, Func Offset: 0x374
	// Line 1140, Address: 0x2d4508, Func Offset: 0x378
	// Line 1141, Address: 0x2d450c, Func Offset: 0x37c
	// Line 1142, Address: 0x2d4510, Func Offset: 0x380
	// Line 1143, Address: 0x2d4514, Func Offset: 0x384
	// Line 1144, Address: 0x2d4518, Func Offset: 0x388
	// Line 1145, Address: 0x2d451c, Func Offset: 0x38c
	// Line 1146, Address: 0x2d4520, Func Offset: 0x390
	// Line 1147, Address: 0x2d4524, Func Offset: 0x394
	// Line 1148, Address: 0x2d4528, Func Offset: 0x398
	// Line 1149, Address: 0x2d452c, Func Offset: 0x39c
	// Line 1150, Address: 0x2d4530, Func Offset: 0x3a0
	// Line 1151, Address: 0x2d4534, Func Offset: 0x3a4
	// Line 1152, Address: 0x2d4538, Func Offset: 0x3a8
	// Line 1153, Address: 0x2d453c, Func Offset: 0x3ac
	// Line 1154, Address: 0x2d4540, Func Offset: 0x3b0
	// Line 1155, Address: 0x2d4544, Func Offset: 0x3b4
	// Line 1156, Address: 0x2d4548, Func Offset: 0x3b8
	// Line 1157, Address: 0x2d454c, Func Offset: 0x3bc
	// Line 1158, Address: 0x2d4550, Func Offset: 0x3c0
	// Line 1159, Address: 0x2d4554, Func Offset: 0x3c4
	// Line 1162, Address: 0x2d4558, Func Offset: 0x3c8
	// Line 1163, Address: 0x2d455c, Func Offset: 0x3cc
	// Line 1164, Address: 0x2d4560, Func Offset: 0x3d0
	// Line 1165, Address: 0x2d4574, Func Offset: 0x3e4
	// Line 1166, Address: 0x2d4578, Func Offset: 0x3e8
	// Line 1167, Address: 0x2d457c, Func Offset: 0x3ec
	// Line 1168, Address: 0x2d4580, Func Offset: 0x3f0
	// Line 1169, Address: 0x2d4584, Func Offset: 0x3f4
	// Line 1170, Address: 0x2d4588, Func Offset: 0x3f8
	// Line 1171, Address: 0x2d458c, Func Offset: 0x3fc
	// Line 1172, Address: 0x2d4590, Func Offset: 0x400
	// Line 1173, Address: 0x2d4594, Func Offset: 0x404
	// Line 1174, Address: 0x2d4598, Func Offset: 0x408
	// Line 1175, Address: 0x2d459c, Func Offset: 0x40c
	// Line 1178, Address: 0x2d45a0, Func Offset: 0x410
	// Line 1181, Address: 0x2d45c4, Func Offset: 0x434
	// Line 1182, Address: 0x2d45c8, Func Offset: 0x438
	// Line 1183, Address: 0x2d45cc, Func Offset: 0x43c
	// Line 1184, Address: 0x2d45d0, Func Offset: 0x440
	// Line 1185, Address: 0x2d45d4, Func Offset: 0x444
	// Line 1186, Address: 0x2d45e8, Func Offset: 0x458
	// Line 1187, Address: 0x2d45fc, Func Offset: 0x46c
	// Line 1188, Address: 0x2d4600, Func Offset: 0x470
	// Line 1189, Address: 0x2d4604, Func Offset: 0x474
	// Line 1190, Address: 0x2d4608, Func Offset: 0x478
	// Line 1191, Address: 0x2d460c, Func Offset: 0x47c
	// Line 1192, Address: 0x2d4610, Func Offset: 0x480
	// Line 1193, Address: 0x2d4614, Func Offset: 0x484
	// Line 1197, Address: 0x2d4618, Func Offset: 0x488
	// Line 1195, Address: 0x2d461c, Func Offset: 0x48c
	// Line 1196, Address: 0x2d4620, Func Offset: 0x490
	// Line 1197, Address: 0x2d4624, Func Offset: 0x494
	// Line 1199, Address: 0x2d4644, Func Offset: 0x4b4
	// Func End, Address: 0x2d464c, Func Offset: 0x4bc
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
        addi     t6, a0, SCISSOR.in
    
        lw       t6, SCISSOR.triangle.node[0](t6)
        
        add      t7, zero, %0
    
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
    " : : "r"(vu1ScessorBuf) : "t7"
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
int _Clip_Screen(register float* clip)
{
    int ret;         
    static float para[2][4] = { 2048.0f, 2048.0f, 0, 240.0f, 0.75f, 1.0f, 0, 0 }; 

    asm volatile
    ("
        move       v0, %0
    
        lqc2       vf4, 0(clip)
        lqc2       vf5, 0(v0)
        lqc2       vf6, 16(v0)
    
        vsub.xy    vf4, vf4, vf5
        
        vmul.xyzw  vf4, vf4, vf6
        
        vclipw.xyz vf4, vf5
        vnop
        vnop
        vnop
        vnop
        vnop
    
        cfc2       v0, vi18
    " : : "f"(para) : "v0"
    );
}

/*// 
// Start address: 0x2d50f0
void vu1DrawTriangleStripTransDouble(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{
	int clipswitch;
	int count;
	int flg;
	unsigned int clipflag;
	unsigned short usStripCnt;
	float fIz;
	tagVU1_PRIM_BUF* pP;
	// Line 3071, Address: 0x2d50f0, Func Offset: 0
	// Line 3080, Address: 0x2d5128, Func Offset: 0x38
	// Line 3087, Address: 0x2d512c, Func Offset: 0x3c
	// Line 3090, Address: 0x2d5130, Func Offset: 0x40
	// Line 3091, Address: 0x2d5134, Func Offset: 0x44
	// Line 3092, Address: 0x2d5138, Func Offset: 0x48
	// Line 3097, Address: 0x2d5140, Func Offset: 0x50
	// Line 3103, Address: 0x2d5144, Func Offset: 0x54
	// Line 3135, Address: 0x2d514c, Func Offset: 0x5c
	// Line 3137, Address: 0x2d5160, Func Offset: 0x70
	// Line 3138, Address: 0x2d5164, Func Offset: 0x74
	// Line 3139, Address: 0x2d5168, Func Offset: 0x78
	// Line 3141, Address: 0x2d5170, Func Offset: 0x80
	// Line 3142, Address: 0x2d5174, Func Offset: 0x84
	// Line 3143, Address: 0x2d5178, Func Offset: 0x88
	// Line 3144, Address: 0x2d517c, Func Offset: 0x8c
	// Line 3145, Address: 0x2d5180, Func Offset: 0x90
	// Line 3146, Address: 0x2d5184, Func Offset: 0x94
	// Line 3147, Address: 0x2d5188, Func Offset: 0x98
	// Line 3148, Address: 0x2d518c, Func Offset: 0x9c
	// Line 3149, Address: 0x2d5190, Func Offset: 0xa0
	// Line 3150, Address: 0x2d5194, Func Offset: 0xa4
	// Line 3151, Address: 0x2d5198, Func Offset: 0xa8
	// Line 3152, Address: 0x2d519c, Func Offset: 0xac
	// Line 3153, Address: 0x2d51a0, Func Offset: 0xb0
	// Line 3154, Address: 0x2d51a4, Func Offset: 0xb4
	// Line 3155, Address: 0x2d51a8, Func Offset: 0xb8
	// Line 3156, Address: 0x2d51ac, Func Offset: 0xbc
	// Line 3162, Address: 0x2d51b0, Func Offset: 0xc0
	// Line 3166, Address: 0x2d51bc, Func Offset: 0xcc
	// Line 3167, Address: 0x2d51c0, Func Offset: 0xd0
	// Line 3175, Address: 0x2d51c4, Func Offset: 0xd4
	// Line 3171, Address: 0x2d51cc, Func Offset: 0xdc
	// Line 3172, Address: 0x2d51d0, Func Offset: 0xe0
	// Line 3175, Address: 0x2d51d4, Func Offset: 0xe4
	// Line 3177, Address: 0x2d51e0, Func Offset: 0xf0
	// Line 3178, Address: 0x2d51e4, Func Offset: 0xf4
	// Line 3179, Address: 0x2d51e8, Func Offset: 0xf8
	// Line 3181, Address: 0x2d51f0, Func Offset: 0x100
	// Line 3182, Address: 0x2d51f4, Func Offset: 0x104
	// Line 3183, Address: 0x2d51f8, Func Offset: 0x108
	// Line 3184, Address: 0x2d51fc, Func Offset: 0x10c
	// Line 3185, Address: 0x2d5200, Func Offset: 0x110
	// Line 3186, Address: 0x2d5204, Func Offset: 0x114
	// Line 3187, Address: 0x2d5208, Func Offset: 0x118
	// Line 3188, Address: 0x2d520c, Func Offset: 0x11c
	// Line 3189, Address: 0x2d5210, Func Offset: 0x120
	// Line 3190, Address: 0x2d5214, Func Offset: 0x124
	// Line 3191, Address: 0x2d5218, Func Offset: 0x128
	// Line 3192, Address: 0x2d521c, Func Offset: 0x12c
	// Line 3193, Address: 0x2d5220, Func Offset: 0x130
	// Line 3194, Address: 0x2d5224, Func Offset: 0x134
	// Line 3195, Address: 0x2d5228, Func Offset: 0x138
	// Line 3196, Address: 0x2d522c, Func Offset: 0x13c
	// Line 3202, Address: 0x2d5230, Func Offset: 0x140
	// Line 3206, Address: 0x2d5240, Func Offset: 0x150
	// Line 3207, Address: 0x2d5244, Func Offset: 0x154
	// Line 3211, Address: 0x2d5248, Func Offset: 0x158
	// Line 3212, Address: 0x2d524c, Func Offset: 0x15c
	// Line 3214, Address: 0x2d5250, Func Offset: 0x160
	// Line 3217, Address: 0x2d5258, Func Offset: 0x168
	// Line 3219, Address: 0x2d526c, Func Offset: 0x17c
	// Line 3220, Address: 0x2d5270, Func Offset: 0x180
	// Line 3221, Address: 0x2d5274, Func Offset: 0x184
	// Line 3223, Address: 0x2d527c, Func Offset: 0x18c
	// Line 3224, Address: 0x2d5280, Func Offset: 0x190
	// Line 3225, Address: 0x2d5284, Func Offset: 0x194
	// Line 3226, Address: 0x2d5288, Func Offset: 0x198
	// Line 3227, Address: 0x2d528c, Func Offset: 0x19c
	// Line 3228, Address: 0x2d5290, Func Offset: 0x1a0
	// Line 3229, Address: 0x2d5294, Func Offset: 0x1a4
	// Line 3230, Address: 0x2d5298, Func Offset: 0x1a8
	// Line 3231, Address: 0x2d529c, Func Offset: 0x1ac
	// Line 3232, Address: 0x2d52a0, Func Offset: 0x1b0
	// Line 3233, Address: 0x2d52a4, Func Offset: 0x1b4
	// Line 3234, Address: 0x2d52a8, Func Offset: 0x1b8
	// Line 3235, Address: 0x2d52ac, Func Offset: 0x1bc
	// Line 3236, Address: 0x2d52b0, Func Offset: 0x1c0
	// Line 3237, Address: 0x2d52b4, Func Offset: 0x1c4
	// Line 3238, Address: 0x2d52b8, Func Offset: 0x1c8
	// Line 3244, Address: 0x2d52bc, Func Offset: 0x1cc
	// Line 3247, Address: 0x2d52c8, Func Offset: 0x1d8
	// Line 3248, Address: 0x2d52cc, Func Offset: 0x1dc
	// Line 3249, Address: 0x2d52d0, Func Offset: 0x1e0
	// Line 3254, Address: 0x2d52d4, Func Offset: 0x1e4
	// Line 3255, Address: 0x2d52ec, Func Offset: 0x1fc
	// Line 3256, Address: 0x2d52f0, Func Offset: 0x200
	// Line 3257, Address: 0x2d5300, Func Offset: 0x210
	// Line 3258, Address: 0x2d530c, Func Offset: 0x21c
	// Line 3259, Address: 0x2d5314, Func Offset: 0x224
	// Line 3260, Address: 0x2d531c, Func Offset: 0x22c
	// Line 3264, Address: 0x2d5328, Func Offset: 0x238
	// Line 3265, Address: 0x2d5330, Func Offset: 0x240
	// Line 3266, Address: 0x2d5354, Func Offset: 0x264
	// Line 3271, Address: 0x2d535c, Func Offset: 0x26c
	// Line 3272, Address: 0x2d5360, Func Offset: 0x270
	// Line 3276, Address: 0x2d5368, Func Offset: 0x278
	// Line 3277, Address: 0x2d536c, Func Offset: 0x27c
	// Line 3281, Address: 0x2d5370, Func Offset: 0x280
	// Line 3277, Address: 0x2d5374, Func Offset: 0x284
	// Line 3278, Address: 0x2d537c, Func Offset: 0x28c
	// Line 3279, Address: 0x2d5388, Func Offset: 0x298
	// Line 3280, Address: 0x2d538c, Func Offset: 0x29c
	// Line 3281, Address: 0x2d5390, Func Offset: 0x2a0
	// Line 3282, Address: 0x2d5398, Func Offset: 0x2a8
	// Line 3281, Address: 0x2d539c, Func Offset: 0x2ac
	// Line 3282, Address: 0x2d53a4, Func Offset: 0x2b4
	// Line 3283, Address: 0x2d53b4, Func Offset: 0x2c4
	// Line 3284, Address: 0x2d53bc, Func Offset: 0x2cc
	// Line 3287, Address: 0x2d53c4, Func Offset: 0x2d4
	// Line 3288, Address: 0x2d53c8, Func Offset: 0x2d8
	// Line 3291, Address: 0x2d53cc, Func Offset: 0x2dc
	// Line 3292, Address: 0x2d53d4, Func Offset: 0x2e4
	// Line 3293, Address: 0x2d53d8, Func Offset: 0x2e8
	// Line 3298, Address: 0x2d53dc, Func Offset: 0x2ec
	// Line 3299, Address: 0x2d53e0, Func Offset: 0x2f0
	// Line 3303, Address: 0x2d53e8, Func Offset: 0x2f8
	// Line 3304, Address: 0x2d53ec, Func Offset: 0x2fc
	// Line 3308, Address: 0x2d53f0, Func Offset: 0x300
	// Line 3304, Address: 0x2d53f4, Func Offset: 0x304
	// Line 3305, Address: 0x2d53fc, Func Offset: 0x30c
	// Line 3306, Address: 0x2d5408, Func Offset: 0x318
	// Line 3307, Address: 0x2d540c, Func Offset: 0x31c
	// Line 3308, Address: 0x2d5410, Func Offset: 0x320
	// Line 3309, Address: 0x2d5418, Func Offset: 0x328
	// Line 3308, Address: 0x2d541c, Func Offset: 0x32c
	// Line 3309, Address: 0x2d5424, Func Offset: 0x334
	// Line 3310, Address: 0x2d5434, Func Offset: 0x344
	// Line 3311, Address: 0x2d543c, Func Offset: 0x34c
	// Line 3314, Address: 0x2d5444, Func Offset: 0x354
	// Line 3315, Address: 0x2d5448, Func Offset: 0x358
	// Line 3318, Address: 0x2d544c, Func Offset: 0x35c
	// Line 3319, Address: 0x2d5454, Func Offset: 0x364
	// Line 3320, Address: 0x2d5458, Func Offset: 0x368
	// Line 3321, Address: 0x2d545c, Func Offset: 0x36c
	// Line 3326, Address: 0x2d5464, Func Offset: 0x374
	// Line 3327, Address: 0x2d5468, Func Offset: 0x378
	// Line 3331, Address: 0x2d5470, Func Offset: 0x380
	// Line 3332, Address: 0x2d5474, Func Offset: 0x384
	// Line 3336, Address: 0x2d5478, Func Offset: 0x388
	// Line 3332, Address: 0x2d547c, Func Offset: 0x38c
	// Line 3333, Address: 0x2d5484, Func Offset: 0x394
	// Line 3334, Address: 0x2d5490, Func Offset: 0x3a0
	// Line 3335, Address: 0x2d5494, Func Offset: 0x3a4
	// Line 3336, Address: 0x2d5498, Func Offset: 0x3a8
	// Line 3337, Address: 0x2d54a0, Func Offset: 0x3b0
	// Line 3336, Address: 0x2d54a4, Func Offset: 0x3b4
	// Line 3337, Address: 0x2d54ac, Func Offset: 0x3bc
	// Line 3338, Address: 0x2d54bc, Func Offset: 0x3cc
	// Line 3339, Address: 0x2d54c4, Func Offset: 0x3d4
	// Line 3342, Address: 0x2d54cc, Func Offset: 0x3dc
	// Line 3343, Address: 0x2d54d0, Func Offset: 0x3e0
	// Line 3346, Address: 0x2d54d4, Func Offset: 0x3e4
	// Line 3347, Address: 0x2d54dc, Func Offset: 0x3ec
	// Line 3349, Address: 0x2d54e4, Func Offset: 0x3f4
	// Line 3350, Address: 0x2d54f4, Func Offset: 0x404
	// Line 3351, Address: 0x2d54fc, Func Offset: 0x40c
	// Line 3352, Address: 0x2d5500, Func Offset: 0x410
	// Line 3353, Address: 0x2d5524, Func Offset: 0x434
	// Line 3355, Address: 0x2d5528, Func Offset: 0x438
	// Line 3360, Address: 0x2d553c, Func Offset: 0x44c
	// Func End, Address: 0x2d556c, Func Offset: 0x47c
}*/

// 100% matching!
void vu1GetVertexColor(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2      vf4, VU1_STRIP_BUF.fIr(pStrip)
        
        mfc1      t0, %0
        mfc1      t1, %0
        mfc1      t2, %0
        mfc1      t3, %1
        
        pextlw    t0, t1, t0
        pextlw    t2, t3, t2
        pcpyld    t0, t2, t0
    
        qmtc2     t0, vf5
    
        vmul.xyzw vf4, vf4, vf5 
        
        sqc2      vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "f"(128.0f), "f"(256.0f) : "t0", "t1", "t2", "t3"
    );
}

// 100% matching!
void vu1GetVertexColorCM(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim) // first parameter is not present on the debugging symbols
{
    asm volatile 
    ("
        lqc2    vf4, VU1_COLOR.fR(%0)

        lw      t0, fVu1AlphaRatio

        qmtc2   t0, vf5 
    
        vmulx.w vf4, vf0, vf5x 

        sqc2    vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "r"(&vu1Diffuse), "f"(fVu1AlphaRatio) : "v1", "t0"
    );
}

// 100% matching!
void vu1GetVertexColorIgnore(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim) // first parameter is not present on the debugging symbols
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

        sqc2        vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "f"(fVu1AlphaRatio) : "t1"
    );
}

// 100% matching!
void vu1GetVertexColorDif(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(pStrip)
        lqc2       vf5, VU1_COLOR.fR(%0)

        lw         t0, fVu1AlphaRatio

        vminiw.xyz vf4, vf4, vf0w
        vmaxx.xyz  vf4, vf4, vf0x 
        
        qmtc2      t0, vf6 

        vmul.xyz   vf4, vf4, vf5
        vmulx.w    vf4, vf0, vf6x 

        sqc2       vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "r"(&vu1Diffuse), "f"(fVu1AlphaRatio) : "v1", "t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifAmb(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim) 
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(pStrip)

        lw         t0, fVu1AlphaRatio
        
        qmtc2      t0, vf8

        vadd.xyz   vf7, vf4, vf22
        
        vmaxx.xyz  vf7, vf7, vf0x
        vminiw.xyz vf7, vf7, vf0w
        
        vmul.xyz   vf4, vf7, vf20
        vmulx.w    vf4, vf0, vf8x 

        sqc2       vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "f"(fVu1AlphaRatio) : "t0"
    );
}

// 96.47% matching
void vu1GetVertexColorDifSpe1(VU1_STRIP_BUF* pStrip, VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(%1)

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

        sqc2       vf4, VU1_PRIM_BUF.fR(%2)
    " : : "f"(fVu1AlphaRatio), "r"(pStrip), "r"(pPrim) : "$t0", "memory"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe2(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(pStrip)
        lqc2       vf5, VU1_COLOR.fR(%0)
        lqc2       vf6, VU1_COLOR.fR(%1)
        lqc2       vf7, VU1_COLOR.fR(%2)

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

        sqc2       vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "r"(&vu1Ambient), "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "v1", "a2", "a3", "t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe3(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(pStrip)
        lqc2       vf5, VU1_COLOR.fR(%0)
        lqc2       vf6, VU1_COLOR.fR(%1)

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

        sqc2       vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "v1", "a2", "t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe1Amb(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(pStrip)
        lqc2       vf5, VU1_COLOR.fR(%0)
        lqc2       vf6, VU1_COLOR.fR(%1)
        lqc2       vf7, VU1_COLOR.fR(%2)

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

        sqc2       vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "r"(&vu1Ambient), "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "v1", "a2", "a3", "t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe2Amb(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(pStrip)
        lqc2       vf5, VU1_COLOR.fR(%0)
        lqc2       vf6, VU1_COLOR.fR(%1)
        lqc2       vf7, VU1_COLOR.fR(%2)

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

        sqc2       vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "r"(&vu1Ambient), "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "v1", "a2", "a3", "t0"
    );
}

// 100% matching!
void vu1GetVertexColorDifSpe3Amb(register VU1_STRIP_BUF* pStrip, register VU1_PRIM_BUF* pPrim)
{
    asm volatile 
    ("
        lqc2       vf4, VU1_STRIP_BUF.fIr(pStrip)
        lqc2       vf5, VU1_COLOR.fR(%0)
        lqc2       vf6, VU1_COLOR.fR(%1)
        lqc2       vf7, VU1_COLOR.fR(%2)

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

        sqc2       vf4, VU1_PRIM_BUF.fR(pPrim)
    " : : "r"(&vu1Ambient), "r"(&vu1Diffuse), "r"(&vu1Specula), "f"(fVu1AlphaRatio) : "v1", "a2", "a3", "t0"
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
        addi     t6, a0, SCISSOR.in
    
        lw       t6, SCISSOR.triangle.node[0](t6)
        
        add      t7, zero, %0
    
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
    " : : "r"(vu1ScessorBuf) : "t7"
    );

    ulType = (ulType & 0xFFFDFFFFFFFFFFFF) | 0x6800000000000;
    
    pP = vu1ScessorBuf;
    
    Ps2AddPrim3DEx1P(ulType, pP, in->nodeNum);
}

/*// 
// Start address: 0x2d5ca0
void vu1DrawTriangleStripTransDouble1P(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{
	int flg;
	unsigned int clipflag;
	void(*pFunc)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
	unsigned short usStripCnt;
	float sam;
	float fIz;
	tagVU1_PRIM_BUF* pP;
	// Line 4792, Address: 0x2d5ca0, Func Offset: 0
	// Line 4802, Address: 0x2d5cd0, Func Offset: 0x30
	// Line 4797, Address: 0x2d5ce4, Func Offset: 0x44
	// Line 4802, Address: 0x2d5ce8, Func Offset: 0x48
	// Line 4807, Address: 0x2d5cf0, Func Offset: 0x50
	// Line 4806, Address: 0x2d5cfc, Func Offset: 0x5c
	// Line 4811, Address: 0x2d5d04, Func Offset: 0x64
	// Line 4807, Address: 0x2d5d08, Func Offset: 0x68
	// Line 4811, Address: 0x2d5d18, Func Offset: 0x78
	// Line 4812, Address: 0x2d5d2c, Func Offset: 0x8c
	// Line 4813, Address: 0x2d5d30, Func Offset: 0x90
	// Line 4812, Address: 0x2d5d38, Func Offset: 0x98
	// Line 4813, Address: 0x2d5d40, Func Offset: 0xa0
	// Line 4814, Address: 0x2d5d50, Func Offset: 0xb0
	// Line 4823, Address: 0x2d5d94, Func Offset: 0xf4
	// Line 4825, Address: 0x2d5da0, Func Offset: 0x100
	// Line 4826, Address: 0x2d5dac, Func Offset: 0x10c
	// Line 4827, Address: 0x2d5db0, Func Offset: 0x110
	// Line 4836, Address: 0x2d5db4, Func Offset: 0x114
	// Line 4831, Address: 0x2d5dc0, Func Offset: 0x120
	// Line 4827, Address: 0x2d5dc4, Func Offset: 0x124
	// Line 4836, Address: 0x2d5dc8, Func Offset: 0x128
	// Line 4827, Address: 0x2d5dd0, Func Offset: 0x130
	// Line 4828, Address: 0x2d5dd4, Func Offset: 0x134
	// Line 4829, Address: 0x2d5de0, Func Offset: 0x140
	// Line 4831, Address: 0x2d5de4, Func Offset: 0x144
	// Line 4832, Address: 0x2d5dec, Func Offset: 0x14c
	// Line 4831, Address: 0x2d5df0, Func Offset: 0x150
	// Line 4832, Address: 0x2d5df8, Func Offset: 0x158
	// Line 4833, Address: 0x2d5e08, Func Offset: 0x168
	// Line 4834, Address: 0x2d5e10, Func Offset: 0x170
	// Line 4836, Address: 0x2d5e18, Func Offset: 0x178
	// Line 4837, Address: 0x2d5e24, Func Offset: 0x184
	// Line 4838, Address: 0x2d5e30, Func Offset: 0x190
	// Line 4837, Address: 0x2d5e34, Func Offset: 0x194
	// Line 4838, Address: 0x2d5e38, Func Offset: 0x198
	// Line 4839, Address: 0x2d5e40, Func Offset: 0x1a0
	// Line 4838, Address: 0x2d5e44, Func Offset: 0x1a4
	// Line 4839, Address: 0x2d5e48, Func Offset: 0x1a8
	// Line 4840, Address: 0x2d5e50, Func Offset: 0x1b0
	// Line 4839, Address: 0x2d5e58, Func Offset: 0x1b8
	// Line 4840, Address: 0x2d5e5c, Func Offset: 0x1bc
	// Line 4841, Address: 0x2d5e60, Func Offset: 0x1c0
	// Line 4843, Address: 0x2d5e78, Func Offset: 0x1d8
	// Line 4844, Address: 0x2d5ea0, Func Offset: 0x200
	// Line 4845, Address: 0x2d5ea8, Func Offset: 0x208
	// Line 4846, Address: 0x2d5ebc, Func Offset: 0x21c
	// Line 4847, Address: 0x2d5ed0, Func Offset: 0x230
	// Line 4848, Address: 0x2d5ee0, Func Offset: 0x240
	// Line 4850, Address: 0x2d5eec, Func Offset: 0x24c
	// Line 4854, Address: 0x2d5ef0, Func Offset: 0x250
	// Line 4852, Address: 0x2d5efc, Func Offset: 0x25c
	// Line 4853, Address: 0x2d5f00, Func Offset: 0x260
	// Line 4854, Address: 0x2d5f04, Func Offset: 0x264
	// Line 4856, Address: 0x2d5f18, Func Offset: 0x278
	// Line 4857, Address: 0x2d5f30, Func Offset: 0x290
	// Func End, Address: 0x2d5f60, Func Offset: 0x2c0
}*/
