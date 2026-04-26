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
/*BH_PWORK ene[0];
_anon9* rom;
_anon5* sys;
O_WRK eff[0];
void(*bhEff_Draw3DSprite)(O_WRK*);
_anon38 cam;
void(*bhEff143_sub)(O_WRK*);*/

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

// 
// Start address: 0x2e8b30
void bhEff149(O_WRK* op)
{
	//_anon39* uvp;
	//_anon39 uvtble[10];
	// Line 560, Address: 0x2e8b30, Func Offset: 0
	// Line 585, Address: 0x2e8b3c, Func Offset: 0xc
	// Line 587, Address: 0x2e8b68, Func Offset: 0x38
	// Line 588, Address: 0x2e8b70, Func Offset: 0x40
	// Line 589, Address: 0x2e8b78, Func Offset: 0x48
	// Line 590, Address: 0x2e8b88, Func Offset: 0x58
	// Line 591, Address: 0x2e8b90, Func Offset: 0x60
	// Line 593, Address: 0x2e8b98, Func Offset: 0x68
	// Line 594, Address: 0x2e8ba0, Func Offset: 0x70
	// Line 593, Address: 0x2e8ba8, Func Offset: 0x78
	// Line 594, Address: 0x2e8bac, Func Offset: 0x7c
	// Line 596, Address: 0x2e8bb4, Func Offset: 0x84
	// Line 597, Address: 0x2e8bf4, Func Offset: 0xc4
	// Line 598, Address: 0x2e8bfc, Func Offset: 0xcc
	// Line 601, Address: 0x2e8c04, Func Offset: 0xd4
	// Line 603, Address: 0x2e8c44, Func Offset: 0x114
	// Line 604, Address: 0x2e8c50, Func Offset: 0x120
	// Line 607, Address: 0x2e8c58, Func Offset: 0x128
	// Line 610, Address: 0x2e8c90, Func Offset: 0x160
	// Line 607, Address: 0x2e8c98, Func Offset: 0x168
	// Line 610, Address: 0x2e8c9c, Func Offset: 0x16c
	// Line 613, Address: 0x2e8ca0, Func Offset: 0x170
	// Line 615, Address: 0x2e8ca8, Func Offset: 0x178
	// Line 618, Address: 0x2e8cb0, Func Offset: 0x180
	// Line 619, Address: 0x2e8cc0, Func Offset: 0x190
	// Line 618, Address: 0x2e8cc4, Func Offset: 0x194
	// Line 619, Address: 0x2e8cc8, Func Offset: 0x198
	// Line 620, Address: 0x2e8ce0, Func Offset: 0x1b0
	// Line 621, Address: 0x2e8ce4, Func Offset: 0x1b4
	// Line 623, Address: 0x2e8cec, Func Offset: 0x1bc
	// Line 626, Address: 0x2e8cf4, Func Offset: 0x1c4
	// Line 627, Address: 0x2e8d04, Func Offset: 0x1d4
	// Line 630, Address: 0x2e8d08, Func Offset: 0x1d8
	// Line 632, Address: 0x2e8d18, Func Offset: 0x1e8
	// Line 636, Address: 0x2e8d20, Func Offset: 0x1f0
	// Line 632, Address: 0x2e8d24, Func Offset: 0x1f4
	// Line 636, Address: 0x2e8d28, Func Offset: 0x1f8
	// Line 634, Address: 0x2e8d2c, Func Offset: 0x1fc
	// Line 632, Address: 0x2e8d30, Func Offset: 0x200
	// Line 633, Address: 0x2e8d3c, Func Offset: 0x20c
	// Line 640, Address: 0x2e8d44, Func Offset: 0x214
	// Line 633, Address: 0x2e8d50, Func Offset: 0x220
	// Line 634, Address: 0x2e8d5c, Func Offset: 0x22c
	// Line 635, Address: 0x2e8d70, Func Offset: 0x240
	// Line 636, Address: 0x2e8d88, Func Offset: 0x258
	// Line 637, Address: 0x2e8da4, Func Offset: 0x274
	// Line 638, Address: 0x2e8dbc, Func Offset: 0x28c
	// Line 639, Address: 0x2e8dd0, Func Offset: 0x2a0
	// Line 640, Address: 0x2e8de4, Func Offset: 0x2b4
	// Line 643, Address: 0x2e8dfc, Func Offset: 0x2cc
	// Line 645, Address: 0x2e8e3c, Func Offset: 0x30c
	// Line 647, Address: 0x2e8e44, Func Offset: 0x314
	// Line 648, Address: 0x2e8e54, Func Offset: 0x324
	// Line 647, Address: 0x2e8e58, Func Offset: 0x328
	// Line 648, Address: 0x2e8e5c, Func Offset: 0x32c
	// Line 649, Address: 0x2e8e60, Func Offset: 0x330
	// Line 647, Address: 0x2e8e68, Func Offset: 0x338
	// Line 648, Address: 0x2e8e6c, Func Offset: 0x33c
	// Line 649, Address: 0x2e8e74, Func Offset: 0x344
	// Line 648, Address: 0x2e8e7c, Func Offset: 0x34c
	// Line 649, Address: 0x2e8e84, Func Offset: 0x354
	// Line 650, Address: 0x2e8e98, Func Offset: 0x368
	// Line 651, Address: 0x2e8e9c, Func Offset: 0x36c
	// Line 652, Address: 0x2e8ea8, Func Offset: 0x378
	// Line 653, Address: 0x2e8eb0, Func Offset: 0x380
	// Line 655, Address: 0x2e8eb8, Func Offset: 0x388
	// Line 657, Address: 0x2e8ec0, Func Offset: 0x390
	// Line 658, Address: 0x2e8ec4, Func Offset: 0x394
	// Line 659, Address: 0x2e8ed0, Func Offset: 0x3a0
	// Line 657, Address: 0x2e8ed4, Func Offset: 0x3a4
	// Line 658, Address: 0x2e8edc, Func Offset: 0x3ac
	// Line 659, Address: 0x2e8ee0, Func Offset: 0x3b0
	// Line 658, Address: 0x2e8eec, Func Offset: 0x3bc
	// Line 659, Address: 0x2e8ef4, Func Offset: 0x3c4
	// Line 660, Address: 0x2e8f00, Func Offset: 0x3d0
	// Line 661, Address: 0x2e8f0c, Func Offset: 0x3dc
	// Line 662, Address: 0x2e8f14, Func Offset: 0x3e4
	// Line 664, Address: 0x2e8f1c, Func Offset: 0x3ec
	// Line 665, Address: 0x2e8f2c, Func Offset: 0x3fc
	// Line 667, Address: 0x2e8f34, Func Offset: 0x404
	// Line 668, Address: 0x2e8f3c, Func Offset: 0x40c
	// Line 677, Address: 0x2e8f44, Func Offset: 0x414
	// Line 680, Address: 0x2e8f4c, Func Offset: 0x41c
	// Line 683, Address: 0x2e8f5c, Func Offset: 0x42c
	// Line 687, Address: 0x2e8f64, Func Offset: 0x434
	// Line 689, Address: 0x2e8f70, Func Offset: 0x440
	// Line 687, Address: 0x2e8f7c, Func Offset: 0x44c
	// Line 688, Address: 0x2e8f84, Func Offset: 0x454
	// Line 689, Address: 0x2e8f8c, Func Offset: 0x45c
	// Line 690, Address: 0x2e8fac, Func Offset: 0x47c
	// Line 694, Address: 0x2e8fb0, Func Offset: 0x480
	// Line 703, Address: 0x2e8fb4, Func Offset: 0x484
	// Line 724, Address: 0x2e8fbc, Func Offset: 0x48c
	// Line 694, Address: 0x2e8fc0, Func Offset: 0x490
	// Line 695, Address: 0x2e8fc4, Func Offset: 0x494
	// Line 696, Address: 0x2e8fcc, Func Offset: 0x49c
	// Line 697, Address: 0x2e8fdc, Func Offset: 0x4ac
	// Line 698, Address: 0x2e8fe4, Func Offset: 0x4b4
	// Line 699, Address: 0x2e8fec, Func Offset: 0x4bc
	// Line 700, Address: 0x2e8ffc, Func Offset: 0x4cc
	// Line 701, Address: 0x2e9004, Func Offset: 0x4d4
	// Line 703, Address: 0x2e900c, Func Offset: 0x4dc
	// Line 704, Address: 0x2e9020, Func Offset: 0x4f0
	// Line 705, Address: 0x2e9034, Func Offset: 0x504
	// Line 706, Address: 0x2e9044, Func Offset: 0x514
	// Line 724, Address: 0x2e9054, Func Offset: 0x524
	// Line 725, Address: 0x2e9070, Func Offset: 0x540
	// Line 726, Address: 0x2e9084, Func Offset: 0x554
	// Line 743, Address: 0x2e90a8, Func Offset: 0x578
	// Func End, Address: 0x2e90b8, Func Offset: 0x588
	scePrintf("bhEff149 - UNIMPLEMENTED!\n");
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
