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

// 99.63% matching (matches on GC)
void bhEff163(O_WRK* op)
{
    UV_WORK* uvp;
    NJS_POINT3 vs, vd;
    static UV_WORK uvinfo_bub_0[18]; // DATA
	static UV_WORK uvinfo_bub_1[14]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 56;
        
        effinit(op);
        
        switch (op->type)
        {
        case 1:
            op->exp0 = (unsigned char*)&uvinfo_bub_1;
            
            njUnitMatrix(NULL);
            
            njRotateXYZ(NULL, 0, op->ay, -op->ax);
            
            getuv(0, op);
            break;
        default:
            op->exp0 = (unsigned char*)&uvinfo_bub_0;
            
            op->type = 0;
            
            vs.z = 0;
            vs.x = 0;
            vs.y = 0.5f;
            
            njUnitMatrix(NULL);
            
            njRotateXYZ(NULL, op->ax, op->ay, 0);
            njCalcVector(NULL, &vs, &vd);
            
            op->xn = vd.x;
            op->yn = vd.y;
            op->zn = vd.z;
            break;
        }
        
        op->ct1 = op->sz;
        
        op->mode0 = 1;
    }
    
    if ((op->type == 0) && (op->ct0 < 13)) 
    {
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
    }

    uvp = (UV_WORK*)op->exp0 + op->ct0;

    if (uvp->u == -1.0f)
    {
        op->flg = 0;
        return;
    }
    else if (uvp->u == -2.0f) 
    {
        op->ct0 = 0;
    }
    else if (uvp->u == -3.0f)
    {       
        if (--op->ct1 > 0) 
        {
            op->ct0 = uvp->v;
        }
        else 
        {
            op->ct0++;
        }
    }
    else if (uvp->u == -4.0f) 
    {
        op->ct0++;
        return;
    }

    effset(op, (UV_WORK*)op->exp0 + op->ct0, 0);
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
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

// 99.30% matching (matches on GC)
void bhEff184(O_WRK* op)
{
    UV_WORK* uvp;
    NJS_POINT3 vs, vd;
    static UV_WORK uvinfo_mizu_0[16]; // DATA

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 33;
        
        effinit(op);
        
        op->exp0 = (unsigned char*)uvinfo_mizu_0;
            
        vs.y = 0;
        vs.x = 0;
        vs.z = op->sz / 10.0f;
            
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        njCalcVector(NULL, &vs, &vd);
            
        op->xn = vd.x;
        op->yn = vd.y;
        op->zn = vd.z;
            
        op->spd = 0.01f;
        
        op->ct1 = 99;
        
        op->mode0 = 1;
        break;
    }
    
    if (op->ct0 <= 10) 
    {
        op->px += op->xn + (((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)) / 16.0f);
        op->py += op->yn + (((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)) / 16.0f);
        op->pz += op->zn + (((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)) / 16.0f);
        
        op->py -= op->spd;
        
        op->spd += 0.01f;
    }
    
    if ((op->ct0 <= 9) && (op->type >= op->py)) 
    {
        op->py = op->type; // bug? 
        
        op->ct0 = 11;
        
        op->sxb *= 4.0f;
        op->syb *= 4.0f;
    }

    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1)
    {
        op->flg = 0;
        return;
    }
    else if (uvp->u == -2) 
    {
        op->ct0 = 0;
    }
    else if (uvp->u == -3)
    {
        if (--op->ct1 >= 0) 
        {
            op->ct0 = uvp->v;
        }
        else 
        {
            op->ct0++;
        }
    }
    else if (uvp->u == -4)
    {
        op->ct0++;
        return;
    }

    effset(op, (UV_WORK*)op->exp0 + op->ct0, 0);
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
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

#pragma divbyzerocheck on 

// 99.31% matching (matches on GC)
void bhEff193(O_WRK* op)
{
	EFF0UV* pInfo;
    float sz;
    static EFF0UV Eff193UvInfo[15]; // DATA

    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 430;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->aox = op->sx - floorf(op->sx);
        op->sx = floorf(op->sx);
        
        op->aoy = op->sy - floorf(op->sy);
        op->spd = floorf(op->sy);
        
        op->aoz = op->sz - floorf(op->sz);
        op->sz = floorf(op->sz);
        
        op->yn = 0;
        op->xn = 0;
        
        op->zn = sz = op->sz / 10.0f;
        op->zn = sz - (op->aoz * (sz * (-rand() / -2.1474836E9f)));
        
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, op->ay);
        njRotateX(NULL, op->ax);

        njRotateZ(NULL, (int)(65536.0f * (-rand() / -2.1474836E9f)));
        njRotateX(NULL, (int)(op->aox * (16384.0f * (-rand() / -2.1474836E9f))));
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->xn);
        
        njPopMatrixEx();
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->sx = op->sy = 0.1875f * op->sx;
        
        op->ct0 = op->aoy * (op->spd * (-rand() / -2.1474836E9f));
        
        op->mode0 = 1;
        break;
    case 1:
        if (op->spd < 1.0f) 
        {
            op->spd = 1.0f;
        }
        
        op->ct0++;
        
        op->ct1 = (op->ct0 * 15) / (int)op->spd;
        
        if (op->ct1 >= 15) 
        {
            op->flg = 0;
            return;
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->yn -= 0.0326f;
        op->yn *= 0.97f;
        break;
    }

    pInfo = &Eff193UvInfo[op->ct1];
    
    op->tv[0].u = op->tv[2].u = pInfo->u / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 47) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 47) / 256.0f;
    
    if (sys->ef_trsn < 512)
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

#pragma divbyzerocheck off 

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
