#include "../../../ps2/veronica/prog/effsub0.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
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

// 100% matching!
void bhEff151(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK uvinfo_koisi[11];  // DATA
    static UV_WORK uvinfo_mokuhen[11]; // DATA

    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 50;
        
        effinit(op);
        
        op->yn = -0.1f;
        
        op->spd = 0.02f * op->sz;

        switch (op->type)
        {
        case 1:
            op->exp0 = (unsigned char*)&uvinfo_mokuhen;
            
            op->ani_ct = op->type = 1;
            break;
        default:
            op->exp0 = (unsigned char*)&uvinfo_koisi;
            
            op->ani_ct = op->type = 0;
            break;
        }
        
        op->mode0 = 1;
    }
    
    if (op->ani_ct != op->type) 
    {
        op->ct0 = 0;

        switch (op->type) 
        { 
        case 1:
            op->exp0 = (unsigned char*)&uvinfo_mokuhen;
            
            op->ani_ct = 1;
            break;
        default: 
            op->exp0 = (unsigned char*)&uvinfo_koisi;
            
            op->ani_ct = op->type = 0;
            break;
        }
    }
    
    if (op->yn > -3.0f) 
    {
        op->yn -= op->spd;
    }
    
    op->py += op->yn;
    
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
void bhEff152(O_WRK* op)
{
    NJS_POINT3 vs, vd;  
    unsigned short i, j;
    float px, py, pz; // not from DWARF

    op->flg |= 0x1000000;
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type != 0) 
    {
        vs.y = 0;
        vs.x = 0;
        vs.z = op->sz;
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        njCalcVector(NULL, &vs, &vd);
        
        px = op->px;
        py = op->py;
        pz = op->pz;
        
        j = ++op->ct1;
        
        if (j >= 12) 
        {
            op->ct1 = 0;
            
            j = 0;
        }
        
        for (i = 0; i < op->type; i++)
        {
            op->px = (px + (vd.x * i)) + (2.0f * ((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)));
            op->py = (py + (vd.y * i)) + (2.0f * ((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)));
            op->pz = (pz + (vd.z * i)) + (2.0f * ((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)));
            
            sys->ef.flg = 0x4100001;
            
            sys->ef.id = 153;
            sys->ef.type = j;
            
            sys->ef.flr_no = op->lkono;
            
            sys->ef.mdlver = 0;
            
            sys->ef.px = op->px;
            sys->ef.py = op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.sx = op->sx;
            sys->ef.sy = op->sy;
            sys->ef.sz = op->sz;
            
            sys->ef.ax = op->ax;
            sys->ef.ay = op->ay;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);

            j = !j ? 11 : --j; 
        }
        
        op->px = px;
        op->py = py;
        op->pz = pz;
        
        op->mode1 = 0;
    }
}

// 100% matching!
void bhEff153(O_WRK* op)
{
    unsigned int argb; // not from DWARF
    static UV_WORK uvinfo_geki[12]; // DATA
    
    switch (op->mode0)
    { 
    case 0:
        op->tex_id = 51;
        
        effinit(op);
        
        op->exp0 = (unsigned char*)&uvinfo_geki[op->type];
        
        op->mode0 = 1;
        break;
    case 1:
        op->mode0 = 2;
        break;
    case 2:
        op->flg = 0;
        return;
    }
    
    effset(op, (UV_WORK*)op->exp0, 0);
    
    if (op->flr_no >= 20) 
    {
        argb = 0;
    }
    else 
    {
        argb = 255 - (unsigned int)((char)op->flr_no * 255) / 20;
    }
    
    op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = (argb << 24) + 0xFFFFFF;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff154(O_WRK* op)
{
    int ct0; // not from DWARF
    
    op->flg |= 0x1000000;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type != 0) 
    {
        if ((op->ct1 < 1) || (op->ct1 > 7)) 
        {
            switch (op->ct0) 
            {
            case 1:
                if ((-rand() / -2.1474836E9f) >= 0.5f) 
                { 
                    ct0 = 2;
                }
                else 
                { 
                    ct0 = 0;
                }
                
                op->ct0 = ct0;
                break;
            case 2:
                if ((-rand() / -2.1474836E9f) >= 0.5f) 
                { 
                    ct0 = 1;
                }
                else 
                { 
                    ct0 = 0;
                }
                
                op->ct0 = ct0;
                break;
            default:
                if ((-rand() / -2.1474836E9f) >= 0.5f) 
                { 
                    ct0 = 2;
                }
                else 
                { 
                    ct0 = 1; 
                }
                
                op->ct0 = ct0;
                break;
            }
            
            setentry(155, op->ct0, op);
            
            op->mode1 = 0;
            
            op->ct1 = 7;
        }
        
        op->ct1--;
    }
}

// 100% matching!
void bhEff155(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK uvinfo_hibana_0[8]; // DATA
	static UV_WORK uvinfo_hibana_1[8]; // DATA
    static UV_WORK uvinfo_hibana_2[8]; // DATA

    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 52;
        
        effinit(op);
        
        switch (op->type)
        { 
        case 1:
            op->exp0 = (unsigned char*)uvinfo_hibana_1;
            break;
        case 2:
            op->exp0 = (unsigned char*)uvinfo_hibana_2;
            break;
        default:
            op->exp0 = (unsigned char*)uvinfo_hibana_0;
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

// 100% matching!
void bhEff161(O_WRK* op)
{
    NJS_POINT3 vs, vd;
    UV_WORK* uvp;
    static UV_WORK uvinfo_sw_0[11]; // DATA
	static UV_WORK uvinfo_sw_1[16]; // DATA
    static UV_WORK uvinfo_sw_2[11]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 55;
        
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
        
        switch (op->type % 10)
        {
        case 1:
            op->exp0 = (unsigned char*)&uvinfo_sw_1;
            
            op->ani_ct = 1;
            break;
        case 2:
            op->exp0 = (unsigned char*)&uvinfo_sw_2;
            
            op->ani_ct = 1;
            break;
        default:
            op->exp0 = (unsigned char*)&uvinfo_sw_0;
            break;
        }
        
        op->spd = op->type / 500.0f;
        
        op->ct1 = 0;
        
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
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->py -= op->spd * op->ct1;
        
        op->ct1++;
        
        effset(op, uvp, 0);
        
        op->ct0++;
        
        sys->ef_trs[sys->ef_trsn++] = op;
    }
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

// 100% matching!
void bhEff170(O_WRK* op)
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
        
        op->lox = 0;
        op->loy = 0;
        op->loz = 0;
    }
    
    if (op->ct0 != 0) 
    {
        if (!(op->ct0 & 0x1)) 
        {
            setentry(171, 1, op);
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->py += op->spd;
        
        op->lox += op->xn;
        op->loy += op->yn;
        op->loz += op->zn;
        
        op->loy += op->spd;
        
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
        
        op->spd -= 0.1f;
        
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
void bhEff171(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK uvinfo_sw_0[11]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 55;
        
        effinit(op);
        
        op->exp0 = (unsigned char*)&uvinfo_sw_0;
        
        op->ct1 = op->type;
        
        op->mode0 = 1;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        op->ct1--;

        if (op->ct1 != 0)
        {
            op->ct0 = 0;
            
            uvp = (UV_WORK*)op->exp0 + op->ct0;
        }
        else
        {
            op->flg = 0;
            return;
        }
    }
    
    effset(op, uvp, 0);
        
    op->ct0++;
        
    sys->ef_trs[sys->ef_trsn++] = op;
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

// 100% matching!
void bhEff173(O_WRK* op)
{
    UV_WORK* uvp;
    static int bltbl[10]; // DATA
    static UV_WORK uvinfo_e23_0[2]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 70;
        
        effinit(op);
        
        op->exp0 = (unsigned char*)&uvinfo_e23_0;
        
        op->mode0 = 1;
        break;
    }
    
    op->bl_src = bltbl[(op->type / 10) + (op->type >> 31)];
    op->bl_dst = bltbl[op->type % 10];
    
    op->sxb = 1.0f;
    op->syb = 1.0f;
    
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

// 100% matching!
void bhEff176(O_WRK* op)
{
	static UV_WORK uvinfo_moon[1]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 68;
        
        effinit(op);
        
        op->exp0 = (unsigned char*)&uvinfo_moon;
        
        op->mode0 = 1;
        break;
    }
    
    effset(op, (UV_WORK*)op->exp0 + op->ct0, 0);
        
    sys->ef_trs[sys->ef_trsn++] = op;
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

// 100% matching!
void bhEff180(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK uvinfo_hiba2_0[11]; // DATA
	static UV_WORK uvinfo_hiba2_1[11]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 408;
        
        effinit(op);

        switch (op->type)
        {
        case 1:
            op->exp0 = (unsigned char*)&uvinfo_hiba2_1;
            
            op->ani_ct = 1;
            break;
        default:
            op->exp0 = (unsigned char*)&uvinfo_hiba2_0;
            break;
        }
        
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
void bhEff181(O_WRK* op)
{
	unsigned short typ;

    op->flg |= 0x1000000;
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type != 0) 
    {
        typ = op->type - 1;
        
        if (!floorf(op->sz)) 
        {
            setentry(182, typ, op);
            
            op->mode1 = 0;
            
            op->type = 0;
            return;
        }
        
        if (op->ct1 < 1) 
        {
            setentry(182, typ, op);
            
            op->ct1 = floorf(op->sz);
        }
        
        op->ct1--;
    }
}

// 100% matching!
void bhEff182(O_WRK* op)
{
    unsigned short ktype, kcolor;
    NJS_POINT3 vs, vd;   
	UV_WORK* uvp;
    static int texid_kemu[10];       // DATA
    static UV_WORK* uvinfo_kemu[10]; // DATA

    kcolor = op->type % 10;
    ktype = op->type / 10;
    
    switch (op->mode0)
    {
    case 0:
        op->tex_id = texid_kemu[kcolor];
        
        effinit(op);
        
        op->exp0 = (unsigned char*)uvinfo_kemu[kcolor];
        
        op->mode0 = 1;
        break;
    }
    
    vs.y = 0;
    vs.x = 0;
    vs.z = njFraction(op->sz);
    
    njUnitMatrix(NULL);
    
    njRotateXYZ(NULL, op->ax, op->ay, 0);
    njCalcVector(NULL, &vs, &vd);
    
    op->px += vd.x;
    op->py += vd.y;
    op->pz += vd.z;
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
        
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
        return;
    }
    
    effset(op, uvp, ktype);
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
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

// 100% matching! 
void bhEff185(O_WRK* op)
{
    UV_WORK* uvp;
    int ct0; // not from DWARF
    static UV_WORK uvinfo_button0[5]; // DATA
    static UV_WORK uvinfo_button1[5]; // DATA
    static UV_WORK uvinfo_button2[5]; // DATA
    static UV_WORK uvinfo_button3[5]; // DATA
    static UV_WORK uvinfo_button4[5]; // DATA
    static UV_WORK uvinfo_button5[5]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 410;
        
        op->flg |= 0x4000000;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        
        op->mode0 = 1;
        break;
    }
    
    switch (op->type)
    {
    case 1:
        op->exp0 = (unsigned char*)uvinfo_button0;
        break;
    case 2:
        op->exp0 = (unsigned char*)uvinfo_button1;
        break;
    case 3:
        op->exp0 = (unsigned char*)uvinfo_button2;
        break;
    case 4:
        op->exp0 = (unsigned char*)uvinfo_button3;
        break;
    case 5:
        op->exp0 = (unsigned char*)uvinfo_button4;
        break;
    case 6:
        op->exp0 = (unsigned char*)uvinfo_button5;
        break;
    default:
        return;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;

    op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col = 0xFFFFFFFF;
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;

    sys->ef_trs[sys->ef_trsn++] = op;
    
    if (op->ct0 == 3)
    {
        ct0 = 0;
    }
    else
    {
        ct0 = op->ct0 + 1;
        
        op->ct0 = ct0;
    }

    op->ct0 = ct0;
}

// 100% matching!
void bhEff186(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK* uvinfo_button[6]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 410;
        
        effinit(op);
        
        if (op->type >= 6) 
        {
            op->type = 0;
        }
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, 0, op->ay, -op->ax);
        
        op->exp0 = (unsigned char*)uvinfo_button[op->type];
        
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
        njSetMatrix(NULL, cam.mtx);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        
        getuv(0, op);
        
        effset(op, uvp, 0);
        
        op->ct0++;
        
        sys->ef_trs[sys->ef_trsn++] = op;
    }
}

// 100% matching!
void bhEff187(O_WRK* op)
{
    unsigned char dt_interval0[10] = { 0 } /* DATA */, dt_interval1[10] = { 0 }; // DATA
    
    op->flg |= 0x1000000;
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type != 0) 
    {
        switch ((unsigned short)op->type)
        {
        case 2:
            setentry(188, 1, op);
            
            op->mode1 = 0;
            op->type = 0;
            break;
        case 3:
            if (op->ct1 <= 0) 
            {
                setentry(188, 0, op);
                
                op->ct1 = dt_interval0[(unsigned char)(10.0f * (-rand() / -2.1474836E9f))];
            }
            
            op->ct1--;
            break;
        case 4:
            if (op->ct1 <= 0) 
            {
                setentry(188, 1, op);
                
                op->ct1 = dt_interval1[(unsigned char)(10.0f * (-rand() / -2.1474836E9f))];
            }
            
            op->ct1--;
            break;
        default:
            setentry(188, 0, op);
            
            op->mode1 = 0;
            op->type = 0;
            break;
        }
    }
}

// 100% matching!
void bhEff188(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK uvinfo_houden_0[13]; // DATA
	static UV_WORK uvinfo_houden_1[6];  // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 412;
        
        effinit(op);

        switch (op->type)
        {
        case 1:
            op->exp0 = (unsigned char*)&uvinfo_houden_1;
            break;
        default:
            op->exp0 = (unsigned char*)&uvinfo_houden_0;
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

// 99.50% matching (matches on GC)
void bhEff195(O_WRK* op)
{
    EFF0UVWHUC* pInfo;
    static EFF0UVWHUC* pEff195UvInfoTop[3]; // DATA
    static int lEff195UvInfoMax[3];         // DATA

    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 431;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->ct1 = 0;
        op->ct0 = 0;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        break;
    }
    
    op->ani_ct = op->type;
    
    if (op->sz < 1.0f) 
    {
        op->sz = 1.0f;
    }
    
    if (op->sz <= op->ct0) 
    {
        op->flg = 0;
        return;
    }
    
    op->ct1 = (op->ct0 * lEff195UvInfoMax[op->type]) / op->sz;
    
    pInfo = &pEff195UvInfoTop[op->type][op->ct1];
    
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
void bhEff196(O_WRK* op)
{
    EFF0UV* pInfo;
    int lType, lColor; 
    static EFF0UV* pEff196UvInfoTop[4];       // DATA
	static unsigned int ulEff196UvInfoMax[4]; // DATA

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

    lColor = (op->type - 1) % 6;
    lType = ((op->type - 1) / 6) % 4;
    
    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 414;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ct0 = 0;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (ulEff196UvInfoMax[lType] <= op->ct0) 
        {
            op->ct0 = 0;
        }
        
        break;
    }
    
    op->ani_ct = lColor;
    
    pInfo = &pEff196UvInfoTop[lType][op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 31) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 31) / 256.0f;
    
    if (sys->ef_trsn < 512)
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
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
