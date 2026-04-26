#include "../../../ps2/veronica/prog/effsub6.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/effsub2.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"

static NJS_POINT3 eye_ofs[2] =
{
    {  0.28f, 0.82f, -0.90f },
    { -0.28f, 0.82f, -0.90f }
};

// 
// Start address: 0x2e80b0
void bhEff085(O_WRK* op)
{
	//_anon6* effp;
	//_anon1* tnp2;
	//_anon1* tnp;
	// Line 86, Address: 0x2e80b0, Func Offset: 0
	// Line 88, Address: 0x2e80d0, Func Offset: 0x20
	// Line 89, Address: 0x2e80dc, Func Offset: 0x2c
	// Line 90, Address: 0x2e80e0, Func Offset: 0x30
	// Line 91, Address: 0x2e80e4, Func Offset: 0x34
	// Line 92, Address: 0x2e80e8, Func Offset: 0x38
	// Line 94, Address: 0x2e80ec, Func Offset: 0x3c
	// Line 97, Address: 0x2e80f4, Func Offset: 0x44
	// Line 99, Address: 0x2e8100, Func Offset: 0x50
	// Line 101, Address: 0x2e810c, Func Offset: 0x5c
	// Line 103, Address: 0x2e8110, Func Offset: 0x60
	// Line 101, Address: 0x2e8114, Func Offset: 0x64
	// Line 99, Address: 0x2e811c, Func Offset: 0x6c
	// Line 101, Address: 0x2e812c, Func Offset: 0x7c
	// Line 99, Address: 0x2e8130, Func Offset: 0x80
	// Line 101, Address: 0x2e813c, Func Offset: 0x8c
	// Line 99, Address: 0x2e8144, Func Offset: 0x94
	// Line 101, Address: 0x2e8148, Func Offset: 0x98
	// Line 99, Address: 0x2e8150, Func Offset: 0xa0
	// Line 103, Address: 0x2e8158, Func Offset: 0xa8
	// Line 99, Address: 0x2e815c, Func Offset: 0xac
	// Line 103, Address: 0x2e8160, Func Offset: 0xb0
	// Line 105, Address: 0x2e8168, Func Offset: 0xb8
	// Line 107, Address: 0x2e8198, Func Offset: 0xe8
	// Line 108, Address: 0x2e81a0, Func Offset: 0xf0
	// Line 111, Address: 0x2e81a8, Func Offset: 0xf8
	// Line 114, Address: 0x2e81b8, Func Offset: 0x108
	// Line 116, Address: 0x2e81d4, Func Offset: 0x124
	// Line 119, Address: 0x2e81e0, Func Offset: 0x130
	// Line 121, Address: 0x2e8218, Func Offset: 0x168
	// Line 128, Address: 0x2e821c, Func Offset: 0x16c
	// Func End, Address: 0x2e8224, Func Offset: 0x174
	scePrintf("bhEff085 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff145(O_WRK* op)
{
    switch (op->mode0) 
    {                       
    case 0:
        op->stflg = 0;
        
        op->flg |= 0x8000;
        
        op->mode0 = 1;
        op->mode1 = 0;
        op->mode2 = 0;
        op->mode3 = 0;
        
        op->tv->col = 0xFFFF0000;
        break;
    case 1:
        if (op->mode1 == 2) 
        {
            if ((op->tv->col & 0xFF000000) < 0x10000000)
            {
                op->tv->col = 0;
            } 
            else
            {
                op->tv->col += 0xF0000000;
            }
        } 
        else 
        {
            op->tv->col = 0xFFFF0000;
        }
        
        bhEff146_Init(op);
        break;
    }
}

// 100% matching!
void bhEff146_Init(O_WRK* op)
{
    int i;
    int eno;
    
    sys->ef.id = 146;
    
    sys->ef.type = op->type;
    
    sys->ef.flg = 1;
    
    sys->ef.sx = 0.05f;
    sys->ef.sy = 0.05f;
    sys->ef.sz = 0.05f;
    
    sys->ef.mdlver = 0;
    
    if (op->lkwkp != NULL)
    {
        njSetMatrix(op->mtx, &((BH_PWORK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
    }
    
    for (i = 0; i < 2; i++) 
    {
        njCalcPoint(op->mtx, &eye_ofs[i], (NJS_POINT3*)&sys->ef.px);
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if ((eno != -1) || (eno < 512)) 
        {
            eff[eno].ax = (int)(10430.381f * atan2f(op->mtx[0][6], op->mtx[0][10]));
            eff[eno].ay = (int)(10430.381f * asinf(-op->mtx[0][2]));
            eff[eno].az = (int)(10430.381f * atan2f(op->mtx[0][1], op->mtx[0][0]));
            
            eff[eno].ct3 = 0;
            
            eff[eno].exp0 = (unsigned char*)op;
            
            eff[eno].mode1 = op->mode1;
            
            eff[eno].tv->col = op->tv->col;
        }
    } 
}

// 100% matching! 
void bhEff_Sub146(O_WRK* op)
{
    switch (op->mode0) 
    {
    case 0:
        if (op->mode1 != 2)
        {
            op->tv[0].col = 0xFF0000;
            op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        }
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->flg |= 0x40A0000;
        
        op->ani_ct = 2;
        
        op->tex_id = 4;
        
        if (op->type == 0) 
        {
            op->ct2 = 0x10000000;
        } 
        else if (op->type == 1) 
        {
            op->ct2 = 0x20000000;
        }
        else
        {
            op->ct2 = 0x40000000; 
        }
        
        op->sx = op->sxb;
        op->sy = op->syb;
        
        op->tv[0].u = 0;
        op->tv[0].v = 0;
        
        op->tv[3].u = 1.0f;
        op->tv[3].v = 1.0f;
        
        op->tv[1].u = op->tv[3].u;
        op->tv[1].v = op->tv[0].v;
        
        op->tv[2].u = op->tv[0].u;
        op->tv[2].v = op->tv[3].v;
        
        op->mode0++;
    case 1:
        op->ct3--;

        if (op->ct3 < 0) 
        {
            op->mode2 = 1;
            op->mode0++;
        }
        else 
        {
            break;
        }
    case 2:
        if (op->mode1 != 2)
        {
            op->tv[0].col -= op->ct2;
        }
        
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        if ((op->tv[0].col & 0xFF000000) < 0x10000000) 
        {
            op->flg = 0;
        }
        
        break;
    }
    
    if (op->mode2 != 0) 
    {
        if (op->mode1 != 0) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            
            sys->ef_trsn++;
            
            op->flg = 0;
        }
        else if (op->flg != 0) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            
            sys->ef_trsn++;
        }
    }
}

// 100% matching!
void bhEff147(O_WRK* op)
{
    if (!(op->stflg & 0x1000000)) 
    {
        op->flg |= 0x1;
        
        op->tex_id = 80;
        
        op->tv[0].x = -1.0f;
        op->tv[0].y = 0;
        op->tv[0].z = -1.0f;
        
        op->tv[1].x = -1.0f;
        op->tv[1].y = 0;
        op->tv[1].z = 1.0f;
        
        op->tv[2].x = 1.0f;
        op->tv[2].y = 0;
        op->tv[2].z = -1.0f;
        
        op->tv[3].x = 1.0f;
        op->tv[3].y = 0;
        op->tv[3].z = 1.0f;
        
        if (op->type != 0) 
        {
            bhEff_SetBaseColor(op, 0xFF5F0000);
        } 
        else 
        {
            bhEff_SetBaseColor(op, 0xFF400000);
        }
        
        op->flg |= 0x4000000;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        if (sys->ef_trsn < 512) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            
            sys->ef_trsn++;
        }
    }
}

// 100% matching!
void bhEff148(O_WRK* op)
{
    NJS_POINT3 pos;

    if (op->mode0 == 0) 
    {
        op->stflg = 0;
        
        op->flg |= 0x8000;
        
        op->mode0 = 1;
        op->mode1 = 0;
        op->mode2 = 0;
        op->mode3 = 0;
        
        op->tv[0].col = 0xFF400000;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->flg |= 0x4120000;
        
        op->ani_ct = 2;
        
        op->tex_id = 4;
        
        op->ct1 = 0;
        op->ct2 = 0;
        
        op->sx = 0.1f * op->sxb;
        op->sy = 0.1f * op->syb;
        op->sz = 0.1f * op->szb;
        
        pos.x = op->px;
        pos.y = op->py;
        pos.z = op->pz;
        
        op->gpy = bhGetGroundPosition(&pos);
        
        op->tv[0].u = 0;
        op->tv[0].v = 0;
        
        op->tv[3].u = 1.0f;
        op->tv[3].v = 1.0f;
        
        op->tv[1].u = op->tv[3].u;
        op->tv[1].v = op->tv[0].v;
        
        op->tv[2].u = op->tv[0].u;
        op->tv[2].v = op->tv[3].v;
    }
    
    switch (op->mode1)
    {                            
    case 0:
        op->flg &= ~0x80;
        
        if (op->lkwkp != NULL) 
        {
            njSetMatrix(op->mtx, &((BH_PWORK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
            
            njCalcPoint(op->mtx, (NJS_POINT3*)&op->lox, (NJS_POINT3*)&op->px);
        }
        
        op->ofy = op->py;
        break;
    case 1:
        if (op->yn > -2.0f) 
        {
            op->yn -= 0.1f;
        }
        
        op->py += op->yn;
        
        if (op->py < op->gpy) 
        {
            op->py = op->gpy;
            
            op->mode1 = 2;
        }
        
        break;
    case 2:
        op->mode1 = 0;
        
        op->py = op->ofy;
        
        op->yn = 0;
        break;
    }
    
    if (op->mode1 != 0) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff149(O_WRK* op)
{
    UV_WORK* uvp;          
    static UV_WORK uvtble[10] = 
    {
        { 0,         0,         0.15625f, 0.1875f },
        { 0.1875f,   0,         0.15625f, 0.1875f },
        { 0.375f,    0,         0.15625f, 0.1875f },
        { 0.5625f,   0,         0.15625f, 0.1875f },
        { 0.75f,     0,         0.15625f, 0.1875f },
        { 0,         0.1875f,   0.15625f, 0.1875f },
        { 0.1875f,   0.1875f,   0.15625f, 0.1875f },
        { 0.375f,    0.1875f,   0.15625f, 0.1875f },
        { 0.5625f,   0.1875f,   0.15625f, 0.1875f },
        { -1.0f,     0,         0,        0       }
    }; 
    
    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 80;
        
        op->ani_ct = 1;
        
        bhEff_SetBaseColor(op, 0x80FFFFFF);
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->flg |= 0x4180000;
        
        bhEff_SetAlign(op, 2);
        
        op->mtn_no = 0;
        op->frm_no = (int)(8.0f * (-rand() / -2.1474836E9f));
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->ct1 = 0;
        op->ct3 = (int)(300.0f * (-rand() / -2.1474836E9f));
        
        op->ah = 0.2f;
        op->aw = 1.0f;
        op->az = (int)(182.04445f * (op->type * 90));
        
        op->func = (void*)bhEff_Draw3DSprite;
        
        op->mode0 = 6;
        op->mode1 = 0;
        return;
    case 1:
        op->ah += 0.2f;
        
        if (op->ah > 1.0f) 
        {
            op->ah = 1.0f;
            
            op->mode0++;
        }
        
        break;
    case 2:
        if (op->mode1 == 2)
        {
            op->mode0++;
        }
        
        if (op->ct3-- == 0)
        {
            sys->ef.id = 264;
            
            sys->ef.type = 0;
            
            sys->ef.flg = 1;
            
            sys->ef.px = op->px;
            sys->ef.py = 5.0f + op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.ax = 0;
            sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            op->ct3 = (int)(200.0f * (-rand() / -2.1474836E9f)) + 200;
        }
        
        break;
    case 3:
        op->ah -= 0.02f;
        op->aw -= 0.01f;
        
        if (op->ah < 0.8f) 
        {
            op->ah = 0.8f;
            op->aw = 0.9f;
            
            op->ct3 = 128;
            
            op->mode0++;
        }
        
        break;
    case 4:
        op->ct3 -= 8;
        
        op->ah -= 0.002f;
        op->aw -= 0.001f;
        
        if (op->ct3 < 0)
        {
            op->mode0++;
            return;
        }
        else 
        {
            bhEff_SetBaseColor(op, (op->ct3 << 24) | 0xFFFFFF);
        }
        
        break;
    case 5:
        op->sx = op->sxb;
        op->sy = op->syb;
        
        op->mode0 = 0;
        return;
    case 6:
        if (op->mode1 == 1) 
        {
            op->mode0 = 1;
        }
        
        return;
    }

    uvp = &uvtble[op->frm_no];
    
    op->frm_no++;
    
    if (uvtble[op->frm_no].u < 0) 
    {
        op->frm_no = 0;
    }
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = op->tv[0].v;
    
    op->tv[2].u = op->tv[0].u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = op->tv[1].u;
    op->tv[3].v = op->tv[2].v;
    
    op->sx = (op->sxb * uvp->xs) / 0.09375f;
    op->sy = (op->syb * uvp->ys) / 0.09375f;
    
    op->sx *= op->aw;
    op->sy *= op->ah;
    
    if (sys->ef_fncn < 128) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhEff144(O_WRK* op)
{
    switch (op->mode0) 
    {
    case 0:
        op->ct0 = 0;
        op->ct1 = 0;
        
        op->ani_ct = op->mdlver;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct1++;
        
        if (op->ct1 < 6) 
        {
            sys->ef_trs[sys->ef_trsn++] = op;
            return;
        }
        
        break;
    }
    
    op->ct1 = 0;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff143_sub(O_WRK* op)
{
    P_WORK* pp; 

    pp = (P_WORK*)op->exp0;
    
    if (!(op->stflg & 0x20)) 
    {
        njSetTexture(&sys->ef_tlist);
    }
    else 
    {
        njSetTexture(op->txp[0]);
    }
    
    if ((op->flg & 0x20000000)) 
    {
        njTextureFilterMode(0);
    } 
    else 
    {
        njTextureFilterMode(1);
    }
    
    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);
    
    njSetMatrix(NULL, cam.mtx);
    
    njPtclSpriteStart(op->tex_id, pp->col, 1);
    njPtclDrawSprite(pp->pos, pp->num, pp->sx, pp->sy);
    njPtclSpriteEnd();
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
}

// 99.97% matching
void bhEff143(O_WRK* op)
{
    NJS_POINT3* p, *v;              
    int i;                  
    P_WORK* pp; // different order in regards to DWARF                 
    unsigned int col[3] = 
    { 
        0xE233200,
        0xA1E1E00,
        0x1C415000 
    };
    O_WRK* owp; // not from DWARF

    switch (op->mode0) 
    {                              
    case 0:                                         
        op->flg |= 0x1;
        
        op->stflg = 0;
        
        op->mode0 = 1;
        op->mode1 = 0;
        op->mode2 = 0;
        op->mode3 = 0;
        
        owp = bhSetExtraEffectWork();
        
        if (owp == NULL) 
        {
            op->flg = 0;
            return;
        }
        
        op->exp0 = (unsigned char*)owp;
        
        owp->px = 2.2e-44f;
        
        op->flg |= 0x20000000;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->func = (void*)bhEff143_sub;
        break;
    case 1:                                         
        pp = (P_WORK*)op->exp0;
        
        p = pp->pos;
        v = pp->vec;
        
        for (i = 0; i < pp->num; i++, p++, v++) 
        {
            p->x = (op->px - (2.0f * (-rand() / -2.1474836E9f))) - 1.0f;
            p->y = op->py + (5.0f * (-rand() / -2.1474836E9f));
            p->z = (op->pz - (2.0f * (-rand() / -2.1474836E9f))) - 1.0f;
            
            op->xn = 0.1f + (0.1f * (-rand() / -2.1474836E9f));
            op->ay = (int)(65536.0f * (-rand() / -2.1474836E9f));
            
            v->x = op->xn * -njSin(op->ay);
            v->y = 0.5f + (0.5f * (-rand() / -2.1474836E9f));
            v->z = op->xn * -njCos(op->ay);
        }
        
        pp->sx = 0.1f;
        pp->sy = 0.15f;
        
        op->ct0 = (int)(30.0f + (20.0f * (-rand() / -2.1474836E9f)));
        op->ct2 = 0xFF;
        
        op->mode0++;
        break;
    }
    
    switch (op->mode1) 
    {   
    case 0:                                     
        return;
    case 1:                                     
        pp = (P_WORK*)op->exp0;
        
        p = pp->pos;
        v = pp->vec;
        
        for (i = 0; i < pp->num; i++, p++, v++) 
        {
            v->x += (0.06f * (-rand() / -2.1474836E9f)) - 0.03f;
            v->y += (0.1f * (-rand() / -2.1474836E9f)) - 0.05f;
            v->z += (0.06f * (-rand() / -2.1474836E9f)) - 0.03f;
            
            p->x += v->x;
            p->y += v->y;
            p->z += v->z;
            
            v->x *= 0.95f;
            v->y *= 0.95f;
            v->z *= 0.95f;
        }
        
        pp->col = col[(int)(3.0f * (-rand() / -2.1474836E9f))];
        
        pp->col |= op->ct2 << 24;
        
        op->tex_id = sys->ef_tn[4] + (int)(4.0f * (-rand() / -2.1474836E9f));
        
        if (op->ct0 < 30)
        {
            op->ct2 -= 8;
        }
        
        if (op->ct0-- == 0) 
        {
            op->mode0 = 1;
            op->mode1 = 0;
            break;
        }
        
        if (sys->ef_fncn < 128) 
        {
            sys->ef_fnc[sys->ef_fncn] = op;
            
            sys->ef_fncn++;
        }
    
        break;
    }
}
