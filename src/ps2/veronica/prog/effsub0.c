#include "../../../ps2/veronica/prog/effsub0.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NinjaPtcl.h"

// 100% matching!
int setentry(unsigned short id, unsigned short type, O_WRK* op) 
{
    sys->ef.flg = 0x04100001;
    sys->ef.id = id;
    sys->ef.type = type;
    sys->ef.flr_no = 0;
    sys->ef.mdlver = 0;
    sys->ef.px = op->px;
    sys->ef.py = op->py;
    sys->ef.pz = op->pz;
    sys->ef.sx = op->sx;
    sys->ef.sy = op->sy;
    sys->ef.sz = op->sz;
    sys->ef.ax = op->ax;
    sys->ef.ay = op->ay;
    return bhSetEffectTb(&sys->ef, NULL, NULL, 0);
}

// 100% matching!
void effinit(O_WRK* op) 
{
    op->flg |= 0x04100000;
    op->tv[0].x = -1.0f;
    op->tv[0].y = -1.0f;
    op->tv[0].z = 0.0f;
    op->tv[1].x = 1.0f;
    op->tv[1].y = -1.0f;
    op->tv[1].z = 0.0f;
    op->tv[2].x = -1.0f;
    op->tv[2].y = 1.0f;
    op->tv[2].z = 0.0f;
    op->tv[3].x = 1.0f;
    op->tv[3].y = 1.0f;
    op->tv[3].z = 0.0f;
    op->tv[0].col = -1U;
    op->tv[1].col = -1U;
    op->tv[2].col = -1U;
    op->tv[3].col = -1U;
    op->bl_src = 8;
    op->bl_dst = 6;
    op->bank = sys->ef_pbkb[op->tex_id];
    op->ani_ct = 0;
    op->ct1 = 0;
    op->ct0 = 0;
    op->sxb = op->sx;
    op->syb = op->sy;
    op->spd = 0.0f;
    op->zn = 0.0f;
    op->yn = 0.0f;
    op->xn = 0.0f;
}

// 100% matching!
void effset(O_WRK* op, UV_WORK* uvp, unsigned short num)
{
    static unsigned int kcol[10][4]; // DATA
    
    op->sx = 4.0f * (op->sxb * uvp->xs);
    op->sy = 4.0f * (op->syb * uvp->ys);
    
    op->tv[0].col = kcol[num][0];
    op->tv[1].col = kcol[num][1];
    op->tv[2].col = kcol[num][2];
    op->tv[3].col = kcol[num][3];
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
}

// 100% matching!
void getuv(unsigned char type, O_WRK* op)
{
	float tab_type[2][4][3] = { 0 }; // DATA
    NJS_POINT3 vs, vd; 
    unsigned char i;

    for (i = 0; i < 4; i++)
    {
        vs.x = tab_type[type][i][0];
        vs.y = tab_type[type][i][1];
        vs.z = tab_type[type][i][2];
        
        njCalcVector(NULL, &vs, &vd);
    
        op->tv[i].x = vd.x;
        op->tv[i].y = vd.y;
        op->tv[i].z = vd.z;
    }
}

// 100% matching!
void bhEff150(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
        }
    }
    
    if (op->type != 0) 
    {
        setentry(0x97U, (unsigned short)op->type - 1, op);
        op->mode1 = 0;
        op->type = 0;
    }
}

// 
// Start address: 0x21f290
void bhEff151(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK uvinfo_koisi[11];
	UV_WORK uvinfo_mokuhen[11];
	// Line 312, Address: 0x21f290, Func Offset: 0
	// Line 344, Address: 0x21f29c, Func Offset: 0xc
	// Line 346, Address: 0x21f2b0, Func Offset: 0x20
	// Line 347, Address: 0x21f2b4, Func Offset: 0x24
	// Line 349, Address: 0x21f2bc, Func Offset: 0x2c
	// Line 351, Address: 0x21f2c8, Func Offset: 0x38
	// Line 354, Address: 0x21f2d8, Func Offset: 0x48
	// Line 351, Address: 0x21f2dc, Func Offset: 0x4c
	// Line 354, Address: 0x21f2e4, Func Offset: 0x54
	// Line 356, Address: 0x21f2f8, Func Offset: 0x68
	// Line 357, Address: 0x21f304, Func Offset: 0x74
	// Line 358, Address: 0x21f30c, Func Offset: 0x7c
	// Line 360, Address: 0x21f314, Func Offset: 0x84
	// Line 361, Address: 0x21f320, Func Offset: 0x90
	// Line 364, Address: 0x21f32c, Func Offset: 0x9c
	// Line 370, Address: 0x21f334, Func Offset: 0xa4
	// Line 371, Address: 0x21f344, Func Offset: 0xb4
	// Line 372, Address: 0x21f348, Func Offset: 0xb8
	// Line 374, Address: 0x21f360, Func Offset: 0xd0
	// Line 376, Address: 0x21f36c, Func Offset: 0xdc
	// Line 378, Address: 0x21f374, Func Offset: 0xe4
	// Line 379, Address: 0x21f380, Func Offset: 0xf0
	// Line 386, Address: 0x21f38c, Func Offset: 0xfc
	// Line 387, Address: 0x21f3b8, Func Offset: 0x128
	// Line 392, Address: 0x21f3c0, Func Offset: 0x130
	// Line 387, Address: 0x21f3cc, Func Offset: 0x13c
	// Line 391, Address: 0x21f3d4, Func Offset: 0x144
	// Line 392, Address: 0x21f3e4, Func Offset: 0x154
	// Line 394, Address: 0x21f3f8, Func Offset: 0x168
	// Line 397, Address: 0x21f400, Func Offset: 0x170
	// Line 398, Address: 0x21f40c, Func Offset: 0x17c
	// Line 399, Address: 0x21f410, Func Offset: 0x180
	// Line 398, Address: 0x21f414, Func Offset: 0x184
	// Line 399, Address: 0x21f41c, Func Offset: 0x18c
	// Line 400, Address: 0x21f450, Func Offset: 0x1c0
	// Func End, Address: 0x21f460, Func Offset: 0x1d0
	scePrintf("bhEff151 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x21f460
void bhEff152(O_WRK* op)
{
	unsigned short j;
	unsigned short i;
	//_anon24 vd;
	//_anon24 vs;
	// Line 409, Address: 0x21f460, Func Offset: 0
	// Line 413, Address: 0x21f484, Func Offset: 0x24
	// Line 415, Address: 0x21f494, Func Offset: 0x34
	// Line 417, Address: 0x21f4b4, Func Offset: 0x54
	// Line 418, Address: 0x21f4c0, Func Offset: 0x60
	// Line 419, Address: 0x21f4c8, Func Offset: 0x68
	// Line 420, Address: 0x21f4cc, Func Offset: 0x6c
	// Line 421, Address: 0x21f4d8, Func Offset: 0x78
	// Line 422, Address: 0x21f4ec, Func Offset: 0x8c
	// Line 427, Address: 0x21f4fc, Func Offset: 0x9c
	// Line 424, Address: 0x21f500, Func Offset: 0xa0
	// Line 425, Address: 0x21f504, Func Offset: 0xa4
	// Line 426, Address: 0x21f508, Func Offset: 0xa8
	// Line 427, Address: 0x21f50c, Func Offset: 0xac
	// Line 428, Address: 0x21f518, Func Offset: 0xb8
	// Line 430, Address: 0x21f524, Func Offset: 0xc4
	// Line 429, Address: 0x21f528, Func Offset: 0xc8
	// Line 432, Address: 0x21f52c, Func Offset: 0xcc
	// Line 433, Address: 0x21f538, Func Offset: 0xd8
	// Line 434, Address: 0x21f5dc, Func Offset: 0x17c
	// Line 435, Address: 0x21f680, Func Offset: 0x220
	// Line 441, Address: 0x21f718, Func Offset: 0x2b8
	// Line 442, Address: 0x21f724, Func Offset: 0x2c4
	// Line 435, Address: 0x21f728, Func Offset: 0x2c8
	// Line 454, Address: 0x21f72c, Func Offset: 0x2cc
	// Line 435, Address: 0x21f738, Func Offset: 0x2d8
	// Line 441, Address: 0x21f744, Func Offset: 0x2e4
	// Line 442, Address: 0x21f754, Func Offset: 0x2f4
	// Line 443, Address: 0x21f768, Func Offset: 0x308
	// Line 444, Address: 0x21f77c, Func Offset: 0x31c
	// Line 445, Address: 0x21f794, Func Offset: 0x334
	// Line 446, Address: 0x21f7a8, Func Offset: 0x348
	// Line 447, Address: 0x21f7c0, Func Offset: 0x360
	// Line 448, Address: 0x21f7d8, Func Offset: 0x378
	// Line 449, Address: 0x21f7f0, Func Offset: 0x390
	// Line 450, Address: 0x21f808, Func Offset: 0x3a8
	// Line 451, Address: 0x21f820, Func Offset: 0x3c0
	// Line 452, Address: 0x21f838, Func Offset: 0x3d8
	// Line 453, Address: 0x21f850, Func Offset: 0x3f0
	// Line 454, Address: 0x21f868, Func Offset: 0x408
	// Line 456, Address: 0x21f880, Func Offset: 0x420
	// Line 457, Address: 0x21f8a4, Func Offset: 0x444
	// Line 459, Address: 0x21f8c4, Func Offset: 0x464
	// Line 460, Address: 0x21f8c8, Func Offset: 0x468
	// Line 461, Address: 0x21f8cc, Func Offset: 0x46c
	// Line 462, Address: 0x21f8d0, Func Offset: 0x470
	// Line 466, Address: 0x21f8d4, Func Offset: 0x474
	// Func End, Address: 0x21f8fc, Func Offset: 0x49c
	scePrintf("bhEff152 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x21f900
void bhEff153(O_WRK* op)
{
	UV_WORK uvinfo_geki[12];
	// Line 475, Address: 0x21f900, Func Offset: 0
	// Line 494, Address: 0x21f90c, Func Offset: 0xc
	// Line 496, Address: 0x21f938, Func Offset: 0x38
	// Line 497, Address: 0x21f93c, Func Offset: 0x3c
	// Line 499, Address: 0x21f944, Func Offset: 0x44
	// Line 501, Address: 0x21f950, Func Offset: 0x50
	// Line 499, Address: 0x21f954, Func Offset: 0x54
	// Line 502, Address: 0x21f960, Func Offset: 0x60
	// Line 505, Address: 0x21f968, Func Offset: 0x68
	// Line 508, Address: 0x21f970, Func Offset: 0x70
	// Line 513, Address: 0x21f978, Func Offset: 0x78
	// Line 522, Address: 0x21f988, Func Offset: 0x88
	// Line 529, Address: 0x21f9f4, Func Offset: 0xf4
	// Line 530, Address: 0x21fa2c, Func Offset: 0x12c
	// Func End, Address: 0x21fa3c, Func Offset: 0x13c
	scePrintf("bhEff153 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x21fa40
void bhEff154(O_WRK* op)
{
	// Line 539, Address: 0x21fa40, Func Offset: 0
	// Line 540, Address: 0x21fa4c, Func Offset: 0xc
	// Line 542, Address: 0x21fa5c, Func Offset: 0x1c
	// Line 543, Address: 0x21fa7c, Func Offset: 0x3c
	// Line 545, Address: 0x21fa88, Func Offset: 0x48
	// Line 546, Address: 0x21faa0, Func Offset: 0x60
	// Line 548, Address: 0x21fac4, Func Offset: 0x84
	// Line 549, Address: 0x21fb14, Func Offset: 0xd4
	// Line 551, Address: 0x21fb1c, Func Offset: 0xdc
	// Line 552, Address: 0x21fb6c, Func Offset: 0x12c
	// Line 554, Address: 0x21fb74, Func Offset: 0x134
	// Line 556, Address: 0x21fbc8, Func Offset: 0x188
	// Line 559, Address: 0x21fbd8, Func Offset: 0x198
	// Line 557, Address: 0x21fbdc, Func Offset: 0x19c
	// Line 559, Address: 0x21fbe0, Func Offset: 0x1a0
	// Line 561, Address: 0x21fbe4, Func Offset: 0x1a4
	// Line 564, Address: 0x21fbf0, Func Offset: 0x1b0
	// Func End, Address: 0x21fc00, Func Offset: 0x1c0
	scePrintf("bhEff154 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x21fc00
void bhEff155(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK uvinfo_hibana_0[8];
	UV_WORK uvinfo_hibana_2[8];
	UV_WORK uvinfo_hibana_1[8];
	// Line 573, Address: 0x21fc00, Func Offset: 0
	// Line 609, Address: 0x21fc0c, Func Offset: 0xc
	// Line 611, Address: 0x21fc20, Func Offset: 0x20
	// Line 612, Address: 0x21fc24, Func Offset: 0x24
	// Line 615, Address: 0x21fc2c, Func Offset: 0x2c
	// Line 617, Address: 0x21fc50, Func Offset: 0x50
	// Line 618, Address: 0x21fc58, Func Offset: 0x58
	// Line 620, Address: 0x21fc60, Func Offset: 0x60
	// Line 621, Address: 0x21fc68, Func Offset: 0x68
	// Line 623, Address: 0x21fc70, Func Offset: 0x70
	// Line 625, Address: 0x21fc7c, Func Offset: 0x7c
	// Line 631, Address: 0x21fc84, Func Offset: 0x84
	// Line 632, Address: 0x21fc8c, Func Offset: 0x8c
	// Line 631, Address: 0x21fc94, Func Offset: 0x94
	// Line 632, Address: 0x21fc9c, Func Offset: 0x9c
	// Line 666, Address: 0x21fcb0, Func Offset: 0xb0
	// Line 669, Address: 0x21fcb8, Func Offset: 0xb8
	// Line 670, Address: 0x21fcc4, Func Offset: 0xc4
	// Line 671, Address: 0x21fcc8, Func Offset: 0xc8
	// Line 670, Address: 0x21fccc, Func Offset: 0xcc
	// Line 671, Address: 0x21fcd4, Func Offset: 0xd4
	// Line 672, Address: 0x21fd08, Func Offset: 0x108
	// Func End, Address: 0x21fd18, Func Offset: 0x118
	scePrintf("bhEff155 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff156(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
        }
    }
    
    if (op->type != 0) 
    {
        setentry(0x9DU, op->type, op);
        op->mode1 = 0;
        op->type = 0;
    }
}

// 100% matching!
void bhEff157(O_WRK* op)
{
    UV_WORK* uvp;
    NJS_POINT3 vs, vd;
    static UV_WORK uvinfo_mos[13]; // DATA

    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 53;
        
        effinit(op);
        
        vs.y = 0;
        vs.x = 0;
        vs.z = op->sz;
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        
        njCalcVector(NULL, &vs, &vd);
        
        op->xn = vd.x;
        op->yn = vd.y;
        op->zn = vd.z;
        
        op->exp0 = (unsigned char*)&uvinfo_mos;
        
        op->mode0 = 1;
        break;
    }
    
    op->px += op->xn;
    op->py += op->yn;
    op->pz += op->zn;
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
    }
    else
    {
        effset(op, uvp, 0);
        
        op->ct0++;
        
        sys->ef_trs[sys->ef_trsn++] = op;
    }
}

// 100% matching!
void bhEff158(O_WRK* op)
{
    int type; // not from DWARF
    
    op->flg |= 0x1000000;
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type != 0) 
    {
        if ((unsigned int)op->type == 2) 
        {
            type = 1;
        }
        else 
        {
            type = 0;
        }
        
        setentry(159, type, op);
        
        op->mode1 = 0;
        op->type = 0;
    }
}

// 100% matching!
void bhEff159(O_WRK* op)
{
    int exp_bank0[24] = { 0 }; // DATA
    int exp_bank1[26] = { 0 }; // DATA
    UV_WORK* uvp;
    static UV_WORK uvinfo_exp_0[25]; // DATA
    static UV_WORK uvinfo_exp_1[27]; // DATA

    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 54;
        
        effinit(op);
        
        switch (op->type) 
        {
        case 1:
            op->exp0 = (unsigned char*)uvinfo_exp_1;
            break;
        case 2:
            op->exp0 = (unsigned char*)uvinfo_exp_0;
            
            op->type -= 2;
            
            op->xn = (op->sz * ((-rand() / -2.1474836E9f) - 0.5f)) / 8.0f;
            op->yn = (op->sz * ((-rand() / -2.1474836E9f) - 0.5f)) / 8.0f;
            op->zn = (op->sz * ((-rand() / -2.1474836E9f) - 0.5f)) / 8.0f;
            break;
        default:
            op->exp0 = (unsigned char*)uvinfo_exp_0;
            
            op->type = 0;
            break;
        }
        
        op->mode0 = 1;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
        
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
    }
    else 
    {
        switch (op->type)
        {
        case 1:
            op->ani_ct = exp_bank1[op->ct0];
            break;
        default:
            op->ani_ct = exp_bank0[op->ct0];
            break;
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        effset(op, uvp, 0);
        
        op->ct0++;
        
        sys->ef_trs[sys->ef_trsn++] = op;
    }
}

// 100% matching!
void bhEff160(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
        }
    }

    if (op->type != 0) 
    {
        setentry(0xA1U, (unsigned short) op->type - 1, op);
        op->mode1 = 0;
        op->type = 0;
    }
}

// 
// Start address: 0x220300
void bhEff161(O_WRK* op)
{
	UV_WORK* uvp;
	//_anon24 vd;
	//_anon24 vs;
	UV_WORK uvinfo_sw_0[11];
	UV_WORK uvinfo_sw_2[11];
	UV_WORK uvinfo_sw_1[16];
	// Line 961, Address: 0x220300, Func Offset: 0
	// Line 1012, Address: 0x22030c, Func Offset: 0xc
	// Line 1014, Address: 0x220320, Func Offset: 0x20
	// Line 1015, Address: 0x220324, Func Offset: 0x24
	// Line 1017, Address: 0x22032c, Func Offset: 0x2c
	// Line 1018, Address: 0x220334, Func Offset: 0x34
	// Line 1019, Address: 0x220338, Func Offset: 0x38
	// Line 1020, Address: 0x220344, Func Offset: 0x44
	// Line 1021, Address: 0x220358, Func Offset: 0x58
	// Line 1022, Address: 0x220368, Func Offset: 0x68
	// Line 1028, Address: 0x22036c, Func Offset: 0x6c
	// Line 1022, Address: 0x220374, Func Offset: 0x74
	// Line 1023, Address: 0x220378, Func Offset: 0x78
	// Line 1024, Address: 0x220380, Func Offset: 0x80
	// Line 1028, Address: 0x220388, Func Offset: 0x88
	// Line 1030, Address: 0x2203b8, Func Offset: 0xb8
	// Line 1032, Address: 0x2203c4, Func Offset: 0xc4
	// Line 1034, Address: 0x2203cc, Func Offset: 0xcc
	// Line 1035, Address: 0x2203d8, Func Offset: 0xd8
	// Line 1036, Address: 0x2203dc, Func Offset: 0xdc
	// Line 1038, Address: 0x2203e4, Func Offset: 0xe4
	// Line 1043, Address: 0x2203f0, Func Offset: 0xf0
	// Line 1046, Address: 0x220434, Func Offset: 0x134
	// Line 1043, Address: 0x220438, Func Offset: 0x138
	// Line 1044, Address: 0x22043c, Func Offset: 0x13c
	// Line 1046, Address: 0x220440, Func Offset: 0x140
	// Line 1052, Address: 0x220444, Func Offset: 0x144
	// Line 1053, Address: 0x22044c, Func Offset: 0x14c
	// Line 1052, Address: 0x220454, Func Offset: 0x154
	// Line 1053, Address: 0x22045c, Func Offset: 0x15c
	// Line 1055, Address: 0x220470, Func Offset: 0x170
	// Line 1058, Address: 0x220478, Func Offset: 0x178
	// Line 1067, Address: 0x220480, Func Offset: 0x180
	// Line 1058, Address: 0x220488, Func Offset: 0x188
	// Line 1059, Address: 0x220490, Func Offset: 0x190
	// Line 1060, Address: 0x2204a0, Func Offset: 0x1a0
	// Line 1062, Address: 0x2204b0, Func Offset: 0x1b0
	// Line 1063, Address: 0x2204cc, Func Offset: 0x1cc
	// Line 1067, Address: 0x2204d4, Func Offset: 0x1d4
	// Line 1068, Address: 0x2204dc, Func Offset: 0x1dc
	// Line 1069, Address: 0x2204e0, Func Offset: 0x1e0
	// Line 1068, Address: 0x2204e4, Func Offset: 0x1e4
	// Line 1069, Address: 0x2204ec, Func Offset: 0x1ec
	// Line 1070, Address: 0x220520, Func Offset: 0x220
	// Func End, Address: 0x220530, Func Offset: 0x230
	scePrintf("bhEff161 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff162(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
        }
    }

    if (op->type != 0) 
    {
        setentry(0xA3U, (unsigned short) op->type - 1, op);
        op->mode1 = 0;
        op->type = 0;
    }
}

// 
// Start address: 0x2205b0
void bhEff163(O_WRK* op)
{
	//_anon24 vd;
	//_anon24 vs;
	UV_WORK* uvp;
	UV_WORK uvinfo_bub_0[18];
	UV_WORK uvinfo_bub_1[14];
	// Line 1098, Address: 0x2205b0, Func Offset: 0
	// Line 1141, Address: 0x2205bc, Func Offset: 0xc
	// Line 1143, Address: 0x2205d0, Func Offset: 0x20
	// Line 1144, Address: 0x2205d4, Func Offset: 0x24
	// Line 1146, Address: 0x2205dc, Func Offset: 0x2c
	// Line 1148, Address: 0x2205f4, Func Offset: 0x44
	// Line 1150, Address: 0x220600, Func Offset: 0x50
	// Line 1151, Address: 0x220608, Func Offset: 0x58
	// Line 1152, Address: 0x220620, Func Offset: 0x70
	// Line 1154, Address: 0x22062c, Func Offset: 0x7c
	// Line 1156, Address: 0x220634, Func Offset: 0x84
	// Line 1157, Address: 0x220640, Func Offset: 0x90
	// Line 1159, Address: 0x220644, Func Offset: 0x94
	// Line 1160, Address: 0x22064c, Func Offset: 0x9c
	// Line 1161, Address: 0x220654, Func Offset: 0xa4
	// Line 1162, Address: 0x22065c, Func Offset: 0xac
	// Line 1163, Address: 0x220670, Func Offset: 0xc0
	// Line 1164, Address: 0x220680, Func Offset: 0xd0
	// Line 1165, Address: 0x220688, Func Offset: 0xd8
	// Line 1166, Address: 0x220690, Func Offset: 0xe0
	// Line 1171, Address: 0x220698, Func Offset: 0xe8
	// Line 1172, Address: 0x2206a4, Func Offset: 0xf4
	// Line 1171, Address: 0x2206a8, Func Offset: 0xf8
	// Line 1172, Address: 0x2206ac, Func Offset: 0xfc
	// Line 1178, Address: 0x2206b0, Func Offset: 0x100
	// Line 1179, Address: 0x2206bc, Func Offset: 0x10c
	// Line 1180, Address: 0x2206cc, Func Offset: 0x11c
	// Line 1181, Address: 0x2206dc, Func Offset: 0x12c
	// Line 1182, Address: 0x2206ec, Func Offset: 0x13c
	// Line 1186, Address: 0x2206fc, Func Offset: 0x14c
	// Line 1187, Address: 0x220704, Func Offset: 0x154
	// Line 1186, Address: 0x22070c, Func Offset: 0x15c
	// Line 1187, Address: 0x220714, Func Offset: 0x164
	// Line 1189, Address: 0x220728, Func Offset: 0x178
	// Line 1190, Address: 0x220730, Func Offset: 0x180
	// Line 1193, Address: 0x22074c, Func Offset: 0x19c
	// Line 1194, Address: 0x220770, Func Offset: 0x1c0
	// Line 1195, Address: 0x220780, Func Offset: 0x1d0
	// Line 1196, Address: 0x220788, Func Offset: 0x1d8
	// Line 1197, Address: 0x220790, Func Offset: 0x1e0
	// Line 1199, Address: 0x220798, Func Offset: 0x1e8
	// Line 1200, Address: 0x2207bc, Func Offset: 0x20c
	// Line 1201, Address: 0x2207c0, Func Offset: 0x210
	// Line 1205, Address: 0x2207c8, Func Offset: 0x218
	// Line 1206, Address: 0x2207e4, Func Offset: 0x234
	// Line 1207, Address: 0x2207e8, Func Offset: 0x238
	// Line 1206, Address: 0x2207ec, Func Offset: 0x23c
	// Line 1207, Address: 0x2207f4, Func Offset: 0x244
	// Line 1208, Address: 0x220828, Func Offset: 0x278
	// Func End, Address: 0x220838, Func Offset: 0x288
	scePrintf("bhEff163 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff164(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
            op->mode1 = 0;
        }
    }

    if ((op->type != 0) && (op->ct0 == 0)) 
    {
        op->ct0 = op->type & 0xFFFF;
    }

    if (op->ct0 != 0) 
    {
        setentry(0x9FU, 2U, op);
        op->ct0 -= 1;
        if (op->ct0 == 0) 
        {
            op->type = 0;
        }
    }
}

// 100% matching!
void bhEff165(O_WRK* op)
{
	float py;
    NJS_POINT3 vs, vd;

    op->flg |= 0x1000000;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = (unsigned char)op->mode1;
        
        op->mode1 = 0;
    }
    
    if ((op->type != 0) && (op->ct0 == 0)) 
    {
        op->ct0 = (unsigned short)op->type * 2;
        
        vs.y = 0;
        vs.x = 0;
        vs.z = op->sz;
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        
        njCalcVector(NULL, &vs, &vd);
        
        op->xn = vd.x;
        op->yn = vd.y;
        op->zn = vd.z;
        
        op->spd = 0;
        
        op->aox = op->px;
        op->aoy = op->py;
        op->aoz = op->pz;
        
        op->axp = op->ax;
        op->ayp = op->ay;
        op->azp = op->az;
    }
    
    if (op->ct0 != 0) 
    {
        if (!(op->ct0 & 0x1)) 
        {
            setentry(159, 1, op);
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->py += op->spd;
        
        op->spd -= 0.05f;
        
        bhCheckWallRefAngle((NJS_POINT3*)&op->px, op->flg, 0.1f, 0.1f, &op->ay);
        
        vs.y = 0;
        vs.x = 0;
        vs.z = op->sz;
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        
        njCalcVector(NULL, &vs, &vd);
        
        op->xn = vd.x;
        op->yn = vd.y;
        op->zn = vd.z;

        py = bhGetGroundPosition((NJS_POINT3*)&op->px);
        
        if (py >= op->py) 
        {
            if (op->yn < 0) 
            {
                op->spd = 2.0f * -op->yn;
                
                op->yn = 0;
            }
            else 
            {
                op->yn = -(op->yn + op->spd);
                
                op->spd = 0;
            }
        }
        
        op->ct0--;
        
        if (op->ct0 == 0) 
        {
            op->type = 0;
            
            op->px = op->aox;
            op->py = op->aoy;
            op->pz = op->aoz;
            
            op->ax = op->axp;
            op->ay = op->ayp;
            op->az = op->azp;
        }
    }
}

// 100% matching!
void bhEff166(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1 & 0xFF;
        }
    }

    if (op->type != 0) 
    {
        if ((op->ct1 <= 0) || (op->ct1 > 0xD))  
        {
            setentry(0xA7U, 1U, op);
            op->mode1 = 0;
            op->ct1 = 0xD;
        } 
        
        op->ct1 -= 1;
    }
}

// 100% matching!
void bhEff167(O_WRK* op)
{
	UV_WORK* uvp;
    static UV_WORK uvinfo_e29[14]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 57;
        
        effinit(op);
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, 0, op->ay, -op->ax);
        
        getuv(0, op);
        
        op->exp0 = (unsigned char*)&uvinfo_e29;
        
        op->mode0 = 1;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
    }
    else
    {
        effset(op, uvp, 0);
        
        op->ct0++;
        
        sys->ef_trs[sys->ef_trsn++] = op;
    }
}

// 100% matching!
void bhEff168(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1 & 0xFF;
        }
    }
    
    if (op->type != 0) 
    {
        setentry(0xA9U, (unsigned short) op->type - 1, op);
        op->mode1 = 0;
        op->type = 0;
    }
}

// 100% matching!
void bhEff169(O_WRK* op)
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_e23_0[11]; // DATA
	static UV_WORK uvinfo_e23_1[15]; // DATA
    
    switch (op->mode0)
    {
    case 0:
        op->tex_id = 64;
        
        effinit(op);
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, 0, op->ay, -op->ax);
        
        switch (op->type) 
        {
        case 1:
            op->exp0 = (unsigned char*)&uvinfo_e23_1;
            
            getuv(0, op);
            break;
        case 2:
            op->exp0 = (unsigned char*)&uvinfo_e23_1;
            
            getuv(1, op);
            break;
        default:
            op->exp0 = (unsigned char*)&uvinfo_e23_0;
            
            op->type = 0;
            
            getuv(0, op);
            break;
        }
        
        op->mode0 = 1;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
    }
    else
    {
        effset(op, uvp, 0);
        
        op->ct0++;
        
        sys->ef_trs[sys->ef_trsn++] = op;
    }
}

// 
// Start address: 0x220f30
void bhEff170(O_WRK* op)
{
	//_anon24 vd;
	//_anon24 vs;
	float py;
	// Line 1534, Address: 0x220f30, Func Offset: 0
	// Line 1539, Address: 0x220f3c, Func Offset: 0xc
	// Line 1542, Address: 0x220f4c, Func Offset: 0x1c
	// Line 1543, Address: 0x220f64, Func Offset: 0x34
	// Line 1544, Address: 0x220f6c, Func Offset: 0x3c
	// Line 1546, Address: 0x220f70, Func Offset: 0x40
	// Line 1547, Address: 0x220f88, Func Offset: 0x58
	// Line 1549, Address: 0x220f94, Func Offset: 0x64
	// Line 1550, Address: 0x220f9c, Func Offset: 0x6c
	// Line 1551, Address: 0x220fa0, Func Offset: 0x70
	// Line 1552, Address: 0x220fac, Func Offset: 0x7c
	// Line 1553, Address: 0x220fc0, Func Offset: 0x90
	// Line 1554, Address: 0x220fd0, Func Offset: 0xa0
	// Line 1555, Address: 0x220fd8, Func Offset: 0xa8
	// Line 1556, Address: 0x220fe0, Func Offset: 0xb0
	// Line 1557, Address: 0x220fe8, Func Offset: 0xb8
	// Line 1559, Address: 0x220fec, Func Offset: 0xbc
	// Line 1560, Address: 0x220ff4, Func Offset: 0xc4
	// Line 1561, Address: 0x220ffc, Func Offset: 0xcc
	// Line 1562, Address: 0x221004, Func Offset: 0xd4
	// Line 1563, Address: 0x22100c, Func Offset: 0xdc
	// Line 1564, Address: 0x221014, Func Offset: 0xe4
	// Line 1565, Address: 0x22101c, Func Offset: 0xec
	// Line 1566, Address: 0x221020, Func Offset: 0xf0
	// Line 1567, Address: 0x221024, Func Offset: 0xf4
	// Line 1570, Address: 0x221028, Func Offset: 0xf8
	// Line 1571, Address: 0x221034, Func Offset: 0x104
	// Line 1572, Address: 0x221040, Func Offset: 0x110
	// Line 1575, Address: 0x221050, Func Offset: 0x120
	// Line 1589, Address: 0x221058, Func Offset: 0x128
	// Line 1575, Address: 0x22106c, Func Offset: 0x13c
	// Line 1576, Address: 0x221074, Func Offset: 0x144
	// Line 1577, Address: 0x221084, Func Offset: 0x154
	// Line 1578, Address: 0x221094, Func Offset: 0x164
	// Line 1580, Address: 0x2210a4, Func Offset: 0x174
	// Line 1581, Address: 0x2210b4, Func Offset: 0x184
	// Line 1582, Address: 0x2210c4, Func Offset: 0x194
	// Line 1583, Address: 0x2210d4, Func Offset: 0x1a4
	// Line 1589, Address: 0x2210e4, Func Offset: 0x1b4
	// Line 1590, Address: 0x2210f0, Func Offset: 0x1c0
	// Line 1591, Address: 0x2210f8, Func Offset: 0x1c8
	// Line 1592, Address: 0x2210fc, Func Offset: 0x1cc
	// Line 1593, Address: 0x221108, Func Offset: 0x1d8
	// Line 1594, Address: 0x22111c, Func Offset: 0x1ec
	// Line 1595, Address: 0x22112c, Func Offset: 0x1fc
	// Line 1605, Address: 0x221130, Func Offset: 0x200
	// Line 1595, Address: 0x221134, Func Offset: 0x204
	// Line 1596, Address: 0x221138, Func Offset: 0x208
	// Line 1597, Address: 0x221140, Func Offset: 0x210
	// Line 1605, Address: 0x221144, Func Offset: 0x214
	// Line 1606, Address: 0x22114c, Func Offset: 0x21c
	// Line 1607, Address: 0x221160, Func Offset: 0x230
	// Line 1608, Address: 0x22117c, Func Offset: 0x24c
	// Line 1610, Address: 0x221194, Func Offset: 0x264
	// Line 1611, Address: 0x22119c, Func Offset: 0x26c
	// Line 1612, Address: 0x2211ac, Func Offset: 0x27c
	// Line 1620, Address: 0x2211b0, Func Offset: 0x280
	// Line 1622, Address: 0x2211cc, Func Offset: 0x29c
	// Line 1623, Address: 0x2211d8, Func Offset: 0x2a8
	// Line 1624, Address: 0x2211e4, Func Offset: 0x2b4
	// Line 1626, Address: 0x2211e8, Func Offset: 0x2b8
	// Line 1627, Address: 0x2211f0, Func Offset: 0x2c0
	// Line 1628, Address: 0x2211f8, Func Offset: 0x2c8
	// Line 1629, Address: 0x221200, Func Offset: 0x2d0
	// Line 1630, Address: 0x221208, Func Offset: 0x2d8
	// Line 1631, Address: 0x221210, Func Offset: 0x2e0
	// Line 1641, Address: 0x221218, Func Offset: 0x2e8
	// Func End, Address: 0x221228, Func Offset: 0x2f8
	scePrintf("bhEff170 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x221230
void bhEff171(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK uvinfo_sw_0[11];
	// Line 1650, Address: 0x221230, Func Offset: 0
	// Line 1667, Address: 0x22123c, Func Offset: 0xc
	// Line 1669, Address: 0x221250, Func Offset: 0x20
	// Line 1670, Address: 0x221254, Func Offset: 0x24
	// Line 1672, Address: 0x22125c, Func Offset: 0x2c
	// Line 1673, Address: 0x221268, Func Offset: 0x38
	// Line 1675, Address: 0x22126c, Func Offset: 0x3c
	// Line 1673, Address: 0x221270, Func Offset: 0x40
	// Line 1675, Address: 0x221274, Func Offset: 0x44
	// Line 1681, Address: 0x221278, Func Offset: 0x48
	// Line 1682, Address: 0x221280, Func Offset: 0x50
	// Line 1681, Address: 0x221288, Func Offset: 0x58
	// Line 1682, Address: 0x221290, Func Offset: 0x60
	// Line 1683, Address: 0x2212a4, Func Offset: 0x74
	// Line 1684, Address: 0x2212b0, Func Offset: 0x80
	// Line 1685, Address: 0x2212bc, Func Offset: 0x8c
	// Line 1686, Address: 0x2212c0, Func Offset: 0x90
	// Line 1687, Address: 0x2212cc, Func Offset: 0x9c
	// Line 1689, Address: 0x2212d4, Func Offset: 0xa4
	// Line 1693, Address: 0x2212dc, Func Offset: 0xac
	// Line 1694, Address: 0x2212e8, Func Offset: 0xb8
	// Line 1695, Address: 0x2212ec, Func Offset: 0xbc
	// Line 1694, Address: 0x2212f0, Func Offset: 0xc0
	// Line 1695, Address: 0x2212f8, Func Offset: 0xc8
	// Line 1696, Address: 0x22132c, Func Offset: 0xfc
	// Func End, Address: 0x22133c, Func Offset: 0x10c
	scePrintf("bhEff171 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff172(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
        }
    }

    if (op->type != 0) 
    {
        setentry(0xAD, (unsigned short)op->type - 1, op);
        op->mode1 = 0;
        op->type = 0;
    }
}

// 
// Start address: 0x2213c0
void bhEff173(O_WRK* op)
{
	UV_WORK* uvp;
	int bltbl[10];
	UV_WORK uvinfo_e23_0[2];
	// Line 1724, Address: 0x2213c0, Func Offset: 0
	// Line 1746, Address: 0x2213cc, Func Offset: 0xc
	// Line 1748, Address: 0x2213e0, Func Offset: 0x20
	// Line 1749, Address: 0x2213e4, Func Offset: 0x24
	// Line 1751, Address: 0x2213ec, Func Offset: 0x2c
	// Line 1752, Address: 0x2213f8, Func Offset: 0x38
	// Line 1756, Address: 0x221400, Func Offset: 0x40
	// Line 1757, Address: 0x221418, Func Offset: 0x58
	// Line 1756, Address: 0x22141c, Func Offset: 0x5c
	// Line 1757, Address: 0x221424, Func Offset: 0x64
	// Line 1756, Address: 0x221428, Func Offset: 0x68
	// Line 1757, Address: 0x22143c, Func Offset: 0x7c
	// Line 1758, Address: 0x221440, Func Offset: 0x80
	// Line 1764, Address: 0x221444, Func Offset: 0x84
	// Line 1756, Address: 0x22144c, Func Offset: 0x8c
	// Line 1757, Address: 0x221450, Func Offset: 0x90
	// Line 1758, Address: 0x221474, Func Offset: 0xb4
	// Line 1759, Address: 0x221478, Func Offset: 0xb8
	// Line 1763, Address: 0x22147c, Func Offset: 0xbc
	// Line 1764, Address: 0x22148c, Func Offset: 0xcc
	// Line 1765, Address: 0x2214a0, Func Offset: 0xe0
	// Line 1766, Address: 0x2214a4, Func Offset: 0xe4
	// Line 1769, Address: 0x2214b4, Func Offset: 0xf4
	// Line 1770, Address: 0x2214c0, Func Offset: 0x100
	// Line 1771, Address: 0x2214c4, Func Offset: 0x104
	// Line 1770, Address: 0x2214c8, Func Offset: 0x108
	// Line 1771, Address: 0x2214d0, Func Offset: 0x110
	// Line 1772, Address: 0x221504, Func Offset: 0x144
	// Func End, Address: 0x221514, Func Offset: 0x154
	scePrintf("bhEff173 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff174()
{

}

// 100% matching!
void bhEff175(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
        }
    }
    
    if (op->type != 0) 
    {
        setentry(0xB0, 0, op);
        op->mode1 = 0;
        op->type = 0;
    }
}

// 
// Start address: 0x2215a0
void bhEff176(O_WRK* op)
{
	UV_WORK uvinfo_moon[1];
	// Line 1811, Address: 0x2215a0, Func Offset: 0
	// Line 1819, Address: 0x2215ac, Func Offset: 0xc
	// Line 1821, Address: 0x2215c0, Func Offset: 0x20
	// Line 1822, Address: 0x2215c4, Func Offset: 0x24
	// Line 1824, Address: 0x2215cc, Func Offset: 0x2c
	// Line 1825, Address: 0x2215d8, Func Offset: 0x38
	// Line 1833, Address: 0x2215e0, Func Offset: 0x40
	// Line 1834, Address: 0x2215fc, Func Offset: 0x5c
	// Line 1835, Address: 0x221634, Func Offset: 0x94
	// Func End, Address: 0x221644, Func Offset: 0xa4
	scePrintf("bhEff176 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff177(O_WRK* op) 
{
    int lNumber;

    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
        }
    }
    
    if (op->type != 0) 
    {
        lNumber = setentry(0xB2, (unsigned short)op->type - 1, op);
        
        if (lNumber != -1) 
        {
            eff[lNumber].lkono = op->lkono;
        }
        
        op->mode1 = 0;
        op->type = 0;
    }
}

// 100% matching!
void bhEff178(O_WRK* op)
{
    NJS_POINT3 vs, vd;
    UV_WORK* uvp;
    int type; // not from DWARF
    static UV_WORK uvinfo_hiko[7]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 69;
        
        effinit(op);
        
        op->spd = op->sz;

        type = op->type;
        
        if (op->type >= 6) 
        {
            type = 0;
        }
        
        op->ct0 = type;
        op->ct1 = 0;
        
        op->exp0 = (unsigned char*)&uvinfo_hiko;
        
        op->mode0 = 1;
    }
    
    op->ct1++;
    
    if (op->lkono <= op->ct1) 
    {
        op->flg = 0;
    }
    else 
    {
        vs.y = 0;
        vs.x = 0;
        vs.z = op->spd;
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        
        njCalcVector(NULL, &vs, &vd);
        
        op->px += vd.x;
        op->py += vd.y;
        op->pz += vd.z;
        
        uvp = (UV_WORK*)op->exp0 + op->ct0;
        
        if (uvp->u == -1.0f) 
        {
            op->ct0 = 0;
            
            uvp = (UV_WORK*)op->exp0 + op->ct0;
        }
        
        effset(op, uvp, 0);
        
        op->ct0++;
        
        sys->ef_trs[sys->ef_trsn++] = op;
    }
}

// 100% matching!
void bhEff179(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
        }
    }
    
    if (op->type != 0) 
    {
        if (!op->sz) 
        {
            setentry(0xB4, (unsigned short)op->type - 1, op);
            op->mode1 = 0;
            op->type = 0;
            return;
        }

        if (op->ct1 <= 0) 
        {
            setentry(0xB4, (unsigned short)op->type - 1, op);
            op->ct1 = (int) (op->sz);
        }
        op->ct1 -= 1;
    }
}

// 
// Start address: 0x221980
void bhEff180(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK uvinfo_hiba2_0[11];
	UV_WORK uvinfo_hiba2_1[11];
	// Line 1972, Address: 0x221980, Func Offset: 0
	// Line 2004, Address: 0x22198c, Func Offset: 0xc
	// Line 2006, Address: 0x2219a0, Func Offset: 0x20
	// Line 2007, Address: 0x2219a4, Func Offset: 0x24
	// Line 2010, Address: 0x2219ac, Func Offset: 0x2c
	// Line 2012, Address: 0x2219c4, Func Offset: 0x44
	// Line 2015, Address: 0x2219d0, Func Offset: 0x50
	// Line 2017, Address: 0x2219d8, Func Offset: 0x58
	// Line 2020, Address: 0x2219e4, Func Offset: 0x64
	// Line 2028, Address: 0x2219ec, Func Offset: 0x6c
	// Line 2029, Address: 0x2219f4, Func Offset: 0x74
	// Line 2028, Address: 0x2219fc, Func Offset: 0x7c
	// Line 2029, Address: 0x221a04, Func Offset: 0x84
	// Line 2031, Address: 0x221a18, Func Offset: 0x98
	// Line 2034, Address: 0x221a20, Func Offset: 0xa0
	// Line 2035, Address: 0x221a2c, Func Offset: 0xac
	// Line 2036, Address: 0x221a30, Func Offset: 0xb0
	// Line 2035, Address: 0x221a34, Func Offset: 0xb4
	// Line 2036, Address: 0x221a3c, Func Offset: 0xbc
	// Line 2037, Address: 0x221a70, Func Offset: 0xf0
	// Func End, Address: 0x221a80, Func Offset: 0x100
	scePrintf("bhEff180 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x221a80
void bhEff181(O_WRK* op)
{
	unsigned short typ;
	// Line 2046, Address: 0x221a80, Func Offset: 0
	// Line 2048, Address: 0x221a90, Func Offset: 0x10
	// Line 2050, Address: 0x221aa0, Func Offset: 0x20
	// Line 2052, Address: 0x221ac0, Func Offset: 0x40
	// Line 2054, Address: 0x221acc, Func Offset: 0x4c
	// Line 2053, Address: 0x221ad0, Func Offset: 0x50
	// Line 2054, Address: 0x221ad4, Func Offset: 0x54
	// Line 2055, Address: 0x221af4, Func Offset: 0x74
	// Line 2056, Address: 0x221b04, Func Offset: 0x84
	// Line 2058, Address: 0x221b08, Func Offset: 0x88
	// Line 2059, Address: 0x221b10, Func Offset: 0x90
	// Line 2060, Address: 0x221b1c, Func Offset: 0x9c
	// Line 2061, Address: 0x221b2c, Func Offset: 0xac
	// Line 2063, Address: 0x221b40, Func Offset: 0xc0
	// Line 2067, Address: 0x221b4c, Func Offset: 0xcc
	// Func End, Address: 0x221b60, Func Offset: 0xe0
	scePrintf("bhEff181 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x221b60
void bhEff182(O_WRK* op)
{
	UV_WORK* uvp;
	//_anon24 vd;
	//_anon24 vs;
	unsigned short kcolor;
	unsigned short ktype;
	UV_WORK* uvinfo_kemu[10];
	int texid_kemu[10];
	// Line 2076, Address: 0x221b60, Func Offset: 0
	// Line 2320, Address: 0x221b74, Func Offset: 0x14
	// Line 2322, Address: 0x221b7c, Func Offset: 0x1c
	// Line 2321, Address: 0x221b80, Func Offset: 0x20
	// Line 2320, Address: 0x221b8c, Func Offset: 0x2c
	// Line 2321, Address: 0x221b9c, Func Offset: 0x3c
	// Line 2320, Address: 0x221ba4, Func Offset: 0x44
	// Line 2321, Address: 0x221bac, Func Offset: 0x4c
	// Line 2322, Address: 0x221bb8, Func Offset: 0x58
	// Line 2324, Address: 0x221bc8, Func Offset: 0x68
	// Line 2325, Address: 0x221be0, Func Offset: 0x80
	// Line 2326, Address: 0x221be8, Func Offset: 0x88
	// Line 2327, Address: 0x221bf8, Func Offset: 0x98
	// Line 2326, Address: 0x221bfc, Func Offset: 0x9c
	// Line 2327, Address: 0x221c00, Func Offset: 0xa0
	// Line 2332, Address: 0x221c04, Func Offset: 0xa4
	// Line 2333, Address: 0x221c0c, Func Offset: 0xac
	// Line 2334, Address: 0x221c18, Func Offset: 0xb8
	// Line 2335, Address: 0x221c20, Func Offset: 0xc0
	// Line 2336, Address: 0x221c34, Func Offset: 0xd4
	// Line 2337, Address: 0x221c44, Func Offset: 0xe4
	// Line 2343, Address: 0x221c4c, Func Offset: 0xec
	// Line 2337, Address: 0x221c58, Func Offset: 0xf8
	// Line 2338, Address: 0x221c60, Func Offset: 0x100
	// Line 2339, Address: 0x221c70, Func Offset: 0x110
	// Line 2342, Address: 0x221c80, Func Offset: 0x120
	// Line 2343, Address: 0x221c90, Func Offset: 0x130
	// Line 2345, Address: 0x221ca4, Func Offset: 0x144
	// Line 2348, Address: 0x221cac, Func Offset: 0x14c
	// Line 2349, Address: 0x221cb8, Func Offset: 0x158
	// Line 2350, Address: 0x221cbc, Func Offset: 0x15c
	// Line 2349, Address: 0x221cc0, Func Offset: 0x160
	// Line 2350, Address: 0x221cc8, Func Offset: 0x168
	// Line 2351, Address: 0x221cfc, Func Offset: 0x19c
	// Func End, Address: 0x221d14, Func Offset: 0x1b4
	scePrintf("bhEff182 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff183(O_WRK* op) 
{
    op->flg |= 0x01000000;
    if (op->type == 0) 
    {
        if (op->mode1 != 0) 
        {
            op->type = op->mode1;
        }
    }

    if (op->type != 0) 
    {
        setentry(0xB8, (unsigned short)op->type - 1, op);
    }
}

// 
// Start address: 0x221d90
void bhEff184(O_WRK* op)
{
	//_anon24 vd;
	//_anon24 vs;
	UV_WORK* uvp;
	UV_WORK uvinfo_mizu_0[16];
	// Line 2379, Address: 0x221d90, Func Offset: 0
	// Line 2402, Address: 0x221da0, Func Offset: 0x10
	// Line 2404, Address: 0x221db4, Func Offset: 0x24
	// Line 2405, Address: 0x221db8, Func Offset: 0x28
	// Line 2407, Address: 0x221dc0, Func Offset: 0x30
	// Line 2409, Address: 0x221dcc, Func Offset: 0x3c
	// Line 2410, Address: 0x221dd4, Func Offset: 0x44
	// Line 2412, Address: 0x221de0, Func Offset: 0x50
	// Line 2410, Address: 0x221de4, Func Offset: 0x54
	// Line 2412, Address: 0x221df0, Func Offset: 0x60
	// Line 2413, Address: 0x221df8, Func Offset: 0x68
	// Line 2414, Address: 0x221e0c, Func Offset: 0x7c
	// Line 2415, Address: 0x221e1c, Func Offset: 0x8c
	// Line 2419, Address: 0x221e20, Func Offset: 0x90
	// Line 2421, Address: 0x221e28, Func Offset: 0x98
	// Line 2422, Address: 0x221e2c, Func Offset: 0x9c
	// Line 2415, Address: 0x221e30, Func Offset: 0xa0
	// Line 2416, Address: 0x221e34, Func Offset: 0xa4
	// Line 2417, Address: 0x221e3c, Func Offset: 0xac
	// Line 2419, Address: 0x221e44, Func Offset: 0xb4
	// Line 2421, Address: 0x221e48, Func Offset: 0xb8
	// Line 2422, Address: 0x221e4c, Func Offset: 0xbc
	// Line 2428, Address: 0x221e50, Func Offset: 0xc0
	// Line 2429, Address: 0x221e60, Func Offset: 0xd0
	// Line 2430, Address: 0x221ed4, Func Offset: 0x144
	// Line 2431, Address: 0x221f48, Func Offset: 0x1b8
	// Line 2434, Address: 0x221f94, Func Offset: 0x204
	// Line 2431, Address: 0x221f98, Func Offset: 0x208
	// Line 2434, Address: 0x221f9c, Func Offset: 0x20c
	// Line 2431, Address: 0x221fa0, Func Offset: 0x210
	// Line 2433, Address: 0x221fc8, Func Offset: 0x238
	// Line 2434, Address: 0x221fd0, Func Offset: 0x240
	// Line 2433, Address: 0x221fd8, Func Offset: 0x248
	// Line 2434, Address: 0x221fe0, Func Offset: 0x250
	// Line 2436, Address: 0x221fec, Func Offset: 0x25c
	// Line 2437, Address: 0x222044, Func Offset: 0x2b4
	// Line 2438, Address: 0x222074, Func Offset: 0x2e4
	// Line 2437, Address: 0x222078, Func Offset: 0x2e8
	// Line 2438, Address: 0x22207c, Func Offset: 0x2ec
	// Line 2439, Address: 0x222080, Func Offset: 0x2f0
	// Line 2440, Address: 0x222098, Func Offset: 0x308
	// Line 2444, Address: 0x2220a4, Func Offset: 0x314
	// Line 2445, Address: 0x2220ac, Func Offset: 0x31c
	// Line 2444, Address: 0x2220b4, Func Offset: 0x324
	// Line 2445, Address: 0x2220bc, Func Offset: 0x32c
	// Line 2447, Address: 0x2220d0, Func Offset: 0x340
	// Line 2448, Address: 0x2220d8, Func Offset: 0x348
	// Line 2450, Address: 0x2220f4, Func Offset: 0x364
	// Line 2451, Address: 0x222118, Func Offset: 0x388
	// Line 2452, Address: 0x222128, Func Offset: 0x398
	// Line 2453, Address: 0x222130, Func Offset: 0x3a0
	// Line 2454, Address: 0x222138, Func Offset: 0x3a8
	// Line 2456, Address: 0x222140, Func Offset: 0x3b0
	// Line 2457, Address: 0x222164, Func Offset: 0x3d4
	// Line 2458, Address: 0x222168, Func Offset: 0x3d8
	// Line 2463, Address: 0x222170, Func Offset: 0x3e0
	// Line 2464, Address: 0x22218c, Func Offset: 0x3fc
	// Line 2465, Address: 0x222190, Func Offset: 0x400
	// Line 2464, Address: 0x222194, Func Offset: 0x404
	// Line 2465, Address: 0x22219c, Func Offset: 0x40c
	// Line 2466, Address: 0x2221d0, Func Offset: 0x440
	// Func End, Address: 0x2221e4, Func Offset: 0x454
	scePrintf("bhEff184 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2221f0
void bhEff185(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK uvinfo_button5[5];
	UV_WORK uvinfo_button4[5];
	UV_WORK uvinfo_button3[5];
	UV_WORK uvinfo_button2[5];
	UV_WORK uvinfo_button1[5];
	UV_WORK uvinfo_button0[5];
	// Line 2542, Address: 0x2221f0, Func Offset: 0
	// Line 2544, Address: 0x222204, Func Offset: 0x14
	// Line 2545, Address: 0x222208, Func Offset: 0x18
	// Line 2546, Address: 0x222210, Func Offset: 0x20
	// Line 2547, Address: 0x222214, Func Offset: 0x24
	// Line 2545, Address: 0x222218, Func Offset: 0x28
	// Line 2546, Address: 0x222220, Func Offset: 0x30
	// Line 2547, Address: 0x222224, Func Offset: 0x34
	// Line 2548, Address: 0x222228, Func Offset: 0x38
	// Line 2551, Address: 0x22222c, Func Offset: 0x3c
	// Line 2549, Address: 0x222230, Func Offset: 0x40
	// Line 2551, Address: 0x222234, Func Offset: 0x44
	// Line 2554, Address: 0x222238, Func Offset: 0x48
	// Line 2556, Address: 0x222260, Func Offset: 0x70
	// Line 2557, Address: 0x222268, Func Offset: 0x78
	// Line 2559, Address: 0x222270, Func Offset: 0x80
	// Line 2560, Address: 0x222278, Func Offset: 0x88
	// Line 2562, Address: 0x222280, Func Offset: 0x90
	// Line 2563, Address: 0x222288, Func Offset: 0x98
	// Line 2565, Address: 0x222290, Func Offset: 0xa0
	// Line 2566, Address: 0x222298, Func Offset: 0xa8
	// Line 2568, Address: 0x2222a0, Func Offset: 0xb0
	// Line 2569, Address: 0x2222a8, Func Offset: 0xb8
	// Line 2571, Address: 0x2222b0, Func Offset: 0xc0
	// Line 2572, Address: 0x2222b8, Func Offset: 0xc8
	// Line 2574, Address: 0x2222c0, Func Offset: 0xd0
	// Line 2576, Address: 0x2222c8, Func Offset: 0xd8
	// Line 2577, Address: 0x2222d0, Func Offset: 0xe0
	// Line 2589, Address: 0x2222d4, Func Offset: 0xe4
	// Line 2591, Address: 0x2222d8, Func Offset: 0xe8
	// Line 2577, Address: 0x2222dc, Func Offset: 0xec
	// Line 2576, Address: 0x2222e0, Func Offset: 0xf0
	// Line 2578, Address: 0x2222e4, Func Offset: 0xf4
	// Line 2579, Address: 0x2222e8, Func Offset: 0xf8
	// Line 2576, Address: 0x2222ec, Func Offset: 0xfc
	// Line 2580, Address: 0x2222f0, Func Offset: 0x100
	// Line 2581, Address: 0x2222f4, Func Offset: 0x104
	// Line 2582, Address: 0x2222fc, Func Offset: 0x10c
	// Line 2583, Address: 0x222304, Func Offset: 0x114
	// Line 2584, Address: 0x222314, Func Offset: 0x124
	// Line 2585, Address: 0x22231c, Func Offset: 0x12c
	// Line 2586, Address: 0x222324, Func Offset: 0x134
	// Line 2587, Address: 0x222334, Func Offset: 0x144
	// Line 2588, Address: 0x222344, Func Offset: 0x154
	// Line 2589, Address: 0x222354, Func Offset: 0x164
	// Line 2591, Address: 0x222388, Func Offset: 0x198
	// Line 2592, Address: 0x2223a4, Func Offset: 0x1b4
	// Func End, Address: 0x2223ac, Func Offset: 0x1bc
	scePrintf("bhEff185 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2223b0
void bhEff186(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK* uvinfo_button[6];
	// Line 2601, Address: 0x2223b0, Func Offset: 0
	// Line 2656, Address: 0x2223c0, Func Offset: 0x10
	// Line 2658, Address: 0x2223d4, Func Offset: 0x24
	// Line 2659, Address: 0x2223d8, Func Offset: 0x28
	// Line 2661, Address: 0x2223e0, Func Offset: 0x30
	// Line 2662, Address: 0x2223f0, Func Offset: 0x40
	// Line 2664, Address: 0x2223f4, Func Offset: 0x44
	// Line 2665, Address: 0x222400, Func Offset: 0x50
	// Line 2666, Address: 0x222418, Func Offset: 0x68
	// Line 2668, Address: 0x222424, Func Offset: 0x74
	// Line 2666, Address: 0x222428, Func Offset: 0x78
	// Line 2668, Address: 0x222438, Func Offset: 0x88
	// Line 2673, Address: 0x22243c, Func Offset: 0x8c
	// Line 2674, Address: 0x222444, Func Offset: 0x94
	// Line 2673, Address: 0x22244c, Func Offset: 0x9c
	// Line 2674, Address: 0x222454, Func Offset: 0xa4
	// Line 2678, Address: 0x222468, Func Offset: 0xb8
	// Line 2681, Address: 0x222470, Func Offset: 0xc0
	// Line 2682, Address: 0x222480, Func Offset: 0xd0
	// Line 2683, Address: 0x222494, Func Offset: 0xe4
	// Line 2685, Address: 0x2224a0, Func Offset: 0xf0
	// Line 2687, Address: 0x2224b0, Func Offset: 0x100
	// Line 2688, Address: 0x2224b4, Func Offset: 0x104
	// Line 2687, Address: 0x2224b8, Func Offset: 0x108
	// Line 2688, Address: 0x2224c0, Func Offset: 0x110
	// Line 2689, Address: 0x2224f4, Func Offset: 0x144
	// Func End, Address: 0x222508, Func Offset: 0x158
	scePrintf("bhEff186 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x222510
void bhEff187(O_WRK* op)
{
	unsigned char dt_interval1[10];
	unsigned char dt_interval0[10];
	// Line 2698, Address: 0x222510, Func Offset: 0
	// Line 2700, Address: 0x222514, Func Offset: 0x4
	// Line 2698, Address: 0x222518, Func Offset: 0x8
	// Line 2700, Address: 0x222520, Func Offset: 0x10
	// Line 2705, Address: 0x222530, Func Offset: 0x20
	// Line 2700, Address: 0x22253c, Func Offset: 0x2c
	// Line 2705, Address: 0x222544, Func Offset: 0x34
	// Line 2711, Address: 0x222548, Func Offset: 0x38
	// Line 2705, Address: 0x22254c, Func Offset: 0x3c
	// Line 2711, Address: 0x222558, Func Offset: 0x48
	// Line 2713, Address: 0x222564, Func Offset: 0x54
	// Line 2715, Address: 0x222584, Func Offset: 0x74
	// Line 2716, Address: 0x222590, Func Offset: 0x80
	// Line 2718, Address: 0x2225c0, Func Offset: 0xb0
	// Line 2719, Address: 0x2225d0, Func Offset: 0xc0
	// Line 2721, Address: 0x2225d4, Func Offset: 0xc4
	// Line 2723, Address: 0x2225dc, Func Offset: 0xcc
	// Line 2724, Address: 0x2225e8, Func Offset: 0xd8
	// Line 2725, Address: 0x2225f8, Func Offset: 0xe8
	// Line 2727, Address: 0x222644, Func Offset: 0x134
	// Line 2728, Address: 0x22264c, Func Offset: 0x13c
	// Line 2730, Address: 0x222654, Func Offset: 0x144
	// Line 2731, Address: 0x222660, Func Offset: 0x150
	// Line 2732, Address: 0x222670, Func Offset: 0x160
	// Line 2734, Address: 0x2226bc, Func Offset: 0x1ac
	// Line 2735, Address: 0x2226c4, Func Offset: 0x1b4
	// Line 2737, Address: 0x2226cc, Func Offset: 0x1bc
	// Line 2738, Address: 0x2226dc, Func Offset: 0x1cc
	// Line 2739, Address: 0x2226e0, Func Offset: 0x1d0
	// Line 2744, Address: 0x2226e4, Func Offset: 0x1d4
	// Func End, Address: 0x2226f4, Func Offset: 0x1e4
	scePrintf("bhEff187 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x222700
void bhEff188(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK uvinfo_houden_0[13];
	UV_WORK uvinfo_houden_1[6];
	// Line 2753, Address: 0x222700, Func Offset: 0
	// Line 2782, Address: 0x22270c, Func Offset: 0xc
	// Line 2784, Address: 0x222720, Func Offset: 0x20
	// Line 2785, Address: 0x222724, Func Offset: 0x24
	// Line 2787, Address: 0x22272c, Func Offset: 0x2c
	// Line 2789, Address: 0x222744, Func Offset: 0x44
	// Line 2790, Address: 0x22274c, Func Offset: 0x4c
	// Line 2792, Address: 0x222754, Func Offset: 0x54
	// Line 2795, Address: 0x222760, Func Offset: 0x60
	// Line 2801, Address: 0x222768, Func Offset: 0x68
	// Line 2802, Address: 0x222770, Func Offset: 0x70
	// Line 2801, Address: 0x222778, Func Offset: 0x78
	// Line 2802, Address: 0x222780, Func Offset: 0x80
	// Line 2804, Address: 0x222794, Func Offset: 0x94
	// Line 2807, Address: 0x22279c, Func Offset: 0x9c
	// Line 2808, Address: 0x2227a8, Func Offset: 0xa8
	// Line 2809, Address: 0x2227ac, Func Offset: 0xac
	// Line 2808, Address: 0x2227b0, Func Offset: 0xb0
	// Line 2809, Address: 0x2227b8, Func Offset: 0xb8
	// Line 2810, Address: 0x2227ec, Func Offset: 0xec
	// Func End, Address: 0x2227fc, Func Offset: 0xfc
	scePrintf("bhEff188 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff189(O_WRK* op)
{
	EFF0UV* pInfo;
    static EFF0UV Eff189UvInfo[10]; // DATA

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4180000;
        
        op->ani_ct = (op->type - 1) % 2;
        
        op->tex_id = 50;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->gpx = op->px;
        op->gpy = op->py;
        op->gpz = op->pz;
        
        op->sxb = op->sx;
        op->syb = op->sy;
        op->szb = op->sz;
        
        op->tv[0].col = op->tv[1].col =op->tv[2].col =op->tv[3].col = -1;
        
        op->ct0 = 0;
        
        if ((op->type == 0) || (op->type == 1)) 
        {
            op->yn = 0;
            op->xn = 0;
            op->zn = 0.1f * op->sz;
        } 
        else 
        {
            op->yn = 0;
            op->zn = 0;
            op->xn = 0;
        }
        
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        njCalcVector(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->xn);
        
        njPopMatrixEx();
        
        op->mode0 = 1;
        break;
    case 1:
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        if (op->py <= op->lkono) 
        {
            op->px = op->gpx;
            op->py = op->gpy;
            op->pz = op->gpz;
            
            op->sx = op->sxb;
            op->sy = op->syb;
            op->sz = op->szb;
            
            op->type = op->mode0 = op->mode1 = 0;
            return;
        }
        
        if ((op->type == 0) || (op->type == 1)) 
        {
            op->yn -= 0.06f;
        }
        else 
        {
            op->yn -= 0.01f * op->sz;
        }
        
        op->ct0++;
        
        if (op->ct0 >= 10) 
        {
            op->ct0 = 0;
        }
    }

    pInfo = &Eff189UvInfo[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 63) / 256.0f;

    op->tv[0].v = op->tv[1].v = pInfo->v / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 63) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff190(O_WRK* op)
{
	EF_WORK* pEffect;

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0) 
    {
    case 0:
        op->ct0 = 6;
        
        op->mode0 = 1;
        break;
    }
    
    op->ct0++;
    
    if (op->ct0 >= 6) 
    {
        pEffect = &sys->ef;
        
        pEffect->flg = 1;
        
        pEffect->id = 191;
        pEffect->type = 0;
        
        pEffect->flr_no = 0;
        
        pEffect->mdlver = 0;
        
        pEffect->px = op->px;
        pEffect->py = op->py;
        pEffect->pz = op->pz;
        
        pEffect->sx = op->sx;
        pEffect->sy = op->sy;
        pEffect->sz = op->sz;
        
        pEffect->ay = op->ay;
        pEffect->ax = op->ax;
        
        bhSetEffectTb(pEffect, NULL, NULL, 0xFF);
        
        op->ct0 = 0;
    }
}

// 100% matching!
void bhEff191(O_WRK* op)
{	
    EFF0UVWHUC* pInfo;
    static EFF0UVWHUC Eff191UvInfo[20]; // DATA
    
    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 429;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        
        op->yn = 0;
        op->xn = 0;
        op->zn = op->sz / 10.0f;
        
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, op->ay + (((short)(3072.0f * (-rand() / -2.1474836E9f))) - 1536));
        njRotateX(NULL, op->ax + (((short)(3072.0f * (-rand() / -2.1474836E9f))) - 1536));
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->xn);
        
        njPopMatrixEx();
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 20)
        {
            op->flg = 0;
            return;
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->yn -= 0.0326f;
        op->yn *= 0.95f;
    }
    
    pInfo = &Eff191UvInfo[op->ct0];
    
    op->sx = 4.0f * (op->sxb * (pInfo->w / 256.0f));
    op->sy = 4.0f * (op->syb * (pInfo->h / 256.0f));
    
    op->tv[0].u = op->tv[2].u = pInfo->u / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + (pInfo->w - 1)) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + (pInfo->h - 1)) / 256.0f;
    
    if (sys->ef_trsn < 512)
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff192(O_WRK* op)
{
    EF_WORK* pEffect;
	int lLoop;

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    pEffect = &sys->ef;
    
    pEffect->flg = 1;
    
    pEffect->id = 193;
    pEffect->type = 0;
    
    pEffect->flr_no = 0;
    
    pEffect->mdlver = 0;
    
    pEffect->px = op->px;
    pEffect->py = op->py;
    pEffect->pz = op->pz;
    
    pEffect->sx = op->sx;
    pEffect->sy = op->sy;
    pEffect->sz = op->sz;
    
    pEffect->ay = op->ay;
    pEffect->ax = op->ax;
    
    for (lLoop = 0; lLoop < op->lkono; lLoop++)
    {
        bhSetEffectTb(pEffect, NULL, NULL, 0xFF);
    }
    
    op->type = op->mode0 = op->mode1 = 0;
}

// 
// Start address: 0x223250
void bhEff193(O_WRK* op)
{
	//tagEFF0UV* pInfo;
	//tagEFF0UV Eff193UvInfo[15];
	// Line 3151, Address: 0x223250, Func Offset: 0
	// Line 3161, Address: 0x223264, Func Offset: 0x14
	// Line 3164, Address: 0x223284, Func Offset: 0x34
	// Line 3165, Address: 0x22328c, Func Offset: 0x3c
	// Line 3167, Address: 0x223290, Func Offset: 0x40
	// Line 3164, Address: 0x223294, Func Offset: 0x44
	// Line 3165, Address: 0x22329c, Func Offset: 0x4c
	// Line 3166, Address: 0x2232a0, Func Offset: 0x50
	// Line 3167, Address: 0x2232a4, Func Offset: 0x54
	// Line 3169, Address: 0x2232a8, Func Offset: 0x58
	// Line 3171, Address: 0x2232b0, Func Offset: 0x60
	// Line 3172, Address: 0x2232c4, Func Offset: 0x74
	// Line 3173, Address: 0x2232d0, Func Offset: 0x80
	// Line 3174, Address: 0x2232e4, Func Offset: 0x94
	// Line 3175, Address: 0x2232f0, Func Offset: 0xa0
	// Line 3176, Address: 0x223304, Func Offset: 0xb4
	// Line 3179, Address: 0x223310, Func Offset: 0xc0
	// Line 3180, Address: 0x223318, Func Offset: 0xc8
	// Line 3181, Address: 0x223334, Func Offset: 0xe4
	// Line 3182, Address: 0x223368, Func Offset: 0x118
	// Line 3184, Address: 0x223370, Func Offset: 0x120
	// Line 3185, Address: 0x223378, Func Offset: 0x128
	// Line 3186, Address: 0x223384, Func Offset: 0x134
	// Line 3187, Address: 0x223390, Func Offset: 0x140
	// Line 3188, Address: 0x2233d8, Func Offset: 0x188
	// Line 3189, Address: 0x223420, Func Offset: 0x1d0
	// Line 3191, Address: 0x223430, Func Offset: 0x1e0
	// Line 3194, Address: 0x223438, Func Offset: 0x1e8
	// Line 3200, Address: 0x22344c, Func Offset: 0x1fc
	// Line 3202, Address: 0x223464, Func Offset: 0x214
	// Line 3204, Address: 0x22349c, Func Offset: 0x24c
	// Line 3202, Address: 0x2234a0, Func Offset: 0x250
	// Line 3205, Address: 0x2234a4, Func Offset: 0x254
	// Line 3209, Address: 0x2234ac, Func Offset: 0x25c
	// Line 3210, Address: 0x2234d0, Func Offset: 0x280
	// Line 3211, Address: 0x2234dc, Func Offset: 0x28c
	// Line 3214, Address: 0x223504, Func Offset: 0x2b4
	// Line 3217, Address: 0x223514, Func Offset: 0x2c4
	// Line 3221, Address: 0x22351c, Func Offset: 0x2cc
	// Line 3226, Address: 0x223524, Func Offset: 0x2d4
	// Line 3229, Address: 0x223530, Func Offset: 0x2e0
	// Line 3221, Address: 0x223534, Func Offset: 0x2e4
	// Line 3229, Address: 0x223538, Func Offset: 0x2e8
	// Line 3221, Address: 0x22353c, Func Offset: 0x2ec
	// Line 3222, Address: 0x223540, Func Offset: 0x2f0
	// Line 3229, Address: 0x223548, Func Offset: 0x2f8
	// Line 3222, Address: 0x22354c, Func Offset: 0x2fc
	// Line 3223, Address: 0x223554, Func Offset: 0x304
	// Line 3226, Address: 0x223564, Func Offset: 0x314
	// Line 3229, Address: 0x223570, Func Offset: 0x320
	// Line 3234, Address: 0x22357c, Func Offset: 0x32c
	// Line 3238, Address: 0x223588, Func Offset: 0x338
	// Line 3245, Address: 0x223590, Func Offset: 0x340
	// Line 3234, Address: 0x223594, Func Offset: 0x344
	// Line 3238, Address: 0x22359c, Func Offset: 0x34c
	// Line 3239, Address: 0x2235b8, Func Offset: 0x368
	// Line 3240, Address: 0x2235d8, Func Offset: 0x388
	// Line 3241, Address: 0x2235f4, Func Offset: 0x3a4
	// Line 3245, Address: 0x223614, Func Offset: 0x3c4
	// Line 3247, Address: 0x223630, Func Offset: 0x3e0
	// Line 3248, Address: 0x223644, Func Offset: 0x3f4
	// Line 3250, Address: 0x223668, Func Offset: 0x418
	// Func End, Address: 0x223680, Func Offset: 0x430
	scePrintf("bhEff193 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff194(O_WRK* op)
{
	EF_WORK* pEffect;

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;

    pEffect = &sys->ef;
    
    pEffect->flg = 1;
    
    pEffect->id = 195;
    pEffect->type = (op->type - 1) % 3;
    
    pEffect->mdlver = 0;
    
    pEffect->flr_no = 0;
    
    pEffect->px = op->px;
    pEffect->py = op->py;
    pEffect->pz = op->pz;
    
    pEffect->sx = op->sx;
    pEffect->sy = op->sy;
    pEffect->sz = op->sz;
    
    pEffect->ay = op->ay;
    pEffect->ax = op->ax;
    
    bhSetEffectTb(pEffect, NULL, NULL, 0);
    
    op->type = op->mode1 = 0;
}

// 
// Start address: 0x2237a0
void bhEff195(O_WRK* op)
{
	//tagEFF0UVWHUC* pInfo;
	//tagEFF0UVWHUC* pEff195UvInfoTop[3];
	int lEff195UvInfoMax[3];
	// Line 3302, Address: 0x2237a0, Func Offset: 0
	// Line 3326, Address: 0x2237ac, Func Offset: 0xc
	// Line 3329, Address: 0x2237cc, Func Offset: 0x2c
	// Line 3330, Address: 0x2237d4, Func Offset: 0x34
	// Line 3331, Address: 0x2237d8, Func Offset: 0x38
	// Line 3329, Address: 0x2237dc, Func Offset: 0x3c
	// Line 3330, Address: 0x2237e4, Func Offset: 0x44
	// Line 3331, Address: 0x2237e8, Func Offset: 0x48
	// Line 3332, Address: 0x2237ec, Func Offset: 0x4c
	// Line 3335, Address: 0x2237f4, Func Offset: 0x54
	// Line 3340, Address: 0x223808, Func Offset: 0x68
	// Line 3341, Address: 0x223810, Func Offset: 0x70
	// Line 3343, Address: 0x223818, Func Offset: 0x78
	// Line 3345, Address: 0x223820, Func Offset: 0x80
	// Line 3348, Address: 0x223828, Func Offset: 0x88
	// Line 3353, Address: 0x223834, Func Offset: 0x94
	// Line 3356, Address: 0x223838, Func Offset: 0x98
	// Line 3353, Address: 0x223840, Func Offset: 0xa0
	// Line 3356, Address: 0x223844, Func Offset: 0xa4
	// Line 3357, Address: 0x22385c, Func Offset: 0xbc
	// Line 3360, Address: 0x223880, Func Offset: 0xe0
	// Line 3362, Address: 0x223888, Func Offset: 0xe8
	// Line 3365, Address: 0x2238c8, Func Offset: 0x128
	// Line 3369, Address: 0x2238ec, Func Offset: 0x14c
	// Line 3370, Address: 0x223948, Func Offset: 0x1a8
	// Line 3374, Address: 0x2239a4, Func Offset: 0x204
	// Line 3375, Address: 0x2239f0, Func Offset: 0x250
	// Line 3376, Address: 0x223a18, Func Offset: 0x278
	// Line 3381, Address: 0x223a54, Func Offset: 0x2b4
	// Line 3376, Address: 0x223a58, Func Offset: 0x2b8
	// Line 3377, Address: 0x223a64, Func Offset: 0x2c4
	// Line 3381, Address: 0x223a8c, Func Offset: 0x2ec
	// Line 3383, Address: 0x223aa8, Func Offset: 0x308
	// Line 3384, Address: 0x223abc, Func Offset: 0x31c
	// Line 3386, Address: 0x223ae0, Func Offset: 0x340
	// Func End, Address: 0x223af0, Func Offset: 0x350
	scePrintf("bhEff195 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x223af0
void bhEff196(O_WRK* op)
{
	int lColor;
	int lType;
	//tagEFF0UV* pInfo;
	//tagEFF0UV* pEff196UvInfoTop[4];
	unsigned int ulEff196UvInfoMax[4];
	// Line 3422, Address: 0x223af0, Func Offset: 0
	// Line 3423, Address: 0x223b10, Func Offset: 0x20
	// Line 3425, Address: 0x223b1c, Func Offset: 0x2c
	// Line 3426, Address: 0x223b28, Func Offset: 0x38
	// Line 3428, Address: 0x223b30, Func Offset: 0x40
	// Line 3432, Address: 0x223b3c, Func Offset: 0x4c
	// Line 3431, Address: 0x223b40, Func Offset: 0x50
	// Line 3428, Address: 0x223b44, Func Offset: 0x54
	// Line 3431, Address: 0x223b4c, Func Offset: 0x5c
	// Line 3432, Address: 0x223b50, Func Offset: 0x60
	// Line 3431, Address: 0x223b54, Func Offset: 0x64
	// Line 3432, Address: 0x223b68, Func Offset: 0x78
	// Line 3433, Address: 0x223b94, Func Offset: 0xa4
	// Line 3436, Address: 0x223bb4, Func Offset: 0xc4
	// Line 3437, Address: 0x223bbc, Func Offset: 0xcc
	// Line 3438, Address: 0x223bc0, Func Offset: 0xd0
	// Line 3436, Address: 0x223bc4, Func Offset: 0xd4
	// Line 3437, Address: 0x223bcc, Func Offset: 0xdc
	// Line 3438, Address: 0x223bd0, Func Offset: 0xe0
	// Line 3439, Address: 0x223bd4, Func Offset: 0xe4
	// Line 3444, Address: 0x223bdc, Func Offset: 0xec
	// Line 3441, Address: 0x223be0, Func Offset: 0xf0
	// Line 3444, Address: 0x223be4, Func Offset: 0xf4
	// Line 3450, Address: 0x223bf4, Func Offset: 0x104
	// Line 3453, Address: 0x223bfc, Func Offset: 0x10c
	// Line 3456, Address: 0x223c00, Func Offset: 0x110
	// Line 3453, Address: 0x223c10, Func Offset: 0x120
	// Line 3456, Address: 0x223c18, Func Offset: 0x128
	// Line 3458, Address: 0x223c2c, Func Offset: 0x13c
	// Line 3469, Address: 0x223c30, Func Offset: 0x140
	// Line 3465, Address: 0x223c3c, Func Offset: 0x14c
	// Line 3469, Address: 0x223c40, Func Offset: 0x150
	// Line 3477, Address: 0x223c4c, Func Offset: 0x15c
	// Line 3470, Address: 0x223c50, Func Offset: 0x160
	// Line 3469, Address: 0x223c58, Func Offset: 0x168
	// Line 3470, Address: 0x223c60, Func Offset: 0x170
	// Line 3471, Address: 0x223c7c, Func Offset: 0x18c
	// Line 3472, Address: 0x223c9c, Func Offset: 0x1ac
	// Line 3473, Address: 0x223cb8, Func Offset: 0x1c8
	// Line 3477, Address: 0x223cd8, Func Offset: 0x1e8
	// Line 3479, Address: 0x223cf4, Func Offset: 0x204
	// Line 3480, Address: 0x223d08, Func Offset: 0x218
	// Line 3482, Address: 0x223d2c, Func Offset: 0x23c
	// Func End, Address: 0x223d34, Func Offset: 0x244
	scePrintf("bhEff196 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff197()
{

}

// 100% matching!
void bhEff198(O_WRK* op)
{
    switch (op->mode0) 
    {
    case 0:
        op->flg = 0x4100001;
        
        op->tex_id = 94;
        
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col = -1;
        
        op->tv[0].v = op->tv[0].u = 0;
        op->tv[1].u = 0.625f;
        
        op->tv[2].u = op->tv[1].v = 0;
        op->tv[2].v = 0.46875f;
        
        op->tv[3].u = 0.625f;
        op->tv[3].v = 0.46875f;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->mode0 = 1;
    case 1:
        sys->ef_opq[sys->ef_opqn++] = op;
        break;
    }
}

// 100% matching!
void bhEff199()
{
	NJS_POINT3 ptcl[11] = { 0 }; // DATA
    
    njSetMatrix(NULL, cam.mtx);
    
    njPtclPolygonStart(0xFFAFAFFF);
    
    njPtclDrawPolygon(ptcl, 11, 1.0f);
    njRotateXYZ(NULL, -256, 256, 0);
    
    njPtclDrawPolygon(ptcl, 11, 1.0f);
    njRotateXYZ(NULL, -256, 256, 0);
    
    njPtclDrawPolygon(ptcl, 11, 1.0f);
    njRotateXYZ(NULL, -256, 256, 0);
    
    njPtclDrawPolygon(ptcl, 11, 1.0f);
    njRotateXYZ(NULL, -256, 256, 0);
    
    njPtclDrawPolygon(ptcl, 11, 1.0f);
    njRotateXYZ(NULL, -256, 256, 0);
    
    njPtclDrawPolygon(ptcl, 11, 1.0f);
    
    njPtclPolygonEnd();
}
