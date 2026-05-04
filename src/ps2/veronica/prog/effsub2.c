#include "../../../ps2/veronica/prog/effsub2.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/effsub6.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NinjaPtcl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// 99.93% matching
void bhEff_E00_Mince(O_WRK* op) 
{
    NJS_POINT3 n;
    float spd;
    float size;
    NJS_POINT3 p1, p2;
    static UV_WORK BH_UVTAB0[9] = 
    {
        {  0.875f,  0.0f,    0.125f, 0.125f },
        {  0.75f,   0.0f,    0.125f, 0.125f },
        {  0.625f,  0.0f,    0.125f, 0.125f },
        {  0.0f,    0.0f,    0.125f, 0.125f },
        {  0.125f,  0.0f,    0.125f, 0.125f },
        {  0.25f,   0.0f,    0.125f, 0.125f },
        {  0.375f,  0.0f,    0.125f, 0.125f },
        {  0.5f,    0.0f,    0.125f, 0.125f },
        { -1.0f,    0.0f,    0.0f,   0.0f   }
    };
    static UV_WORK BH_UVTAB1[9] = 
    {
        {  0.875f,  0.125f,  0.125f, 0.125f },
        {  0.75f,   0.125f,  0.125f, 0.125f },
        {  0.625f,  0.125f,  0.125f, 0.125f },
        {  0.0f,    0.125f,  0.125f, 0.125f },
        {  0.125f,  0.125f,  0.125f, 0.125f },
        {  0.25f,   0.125f,  0.125f, 0.125f },
        {  0.375f,  0.125f,  0.125f, 0.125f },
        {  0.5f,    0.125f,  0.125f, 0.125f },
        { -1.0f,    0.0f,    0.0f,   0.0f   }
    };
    static UV_WORK BH_UVTAB2[9] = 
    {
        {  0.875f,  0.25f,   0.125f, 0.125f },
        {  0.75f,   0.25f,   0.125f, 0.125f },
        {  0.625f,  0.25f,   0.125f, 0.125f },
        {  0.0f,    0.25f,   0.125f, 0.125f },
        {  0.125f,  0.25f,   0.125f, 0.125f },
        {  0.25f,   0.25f,   0.125f, 0.125f },
        {  0.375f,  0.25f,   0.125f, 0.125f },
        {  0.5f,    0.25f,   0.125f, 0.125f },
        { -1.0f,    0.0f,    0.0f,   0.0f   }
    };
    static UV_WORK BH_UVTAB3[9] = 
    {
        {  0.875f,  0.375f,  0.125f, 0.125f },
        {  0.75f,   0.375f,  0.125f, 0.125f },
        {  0.625f,  0.375f,  0.125f, 0.125f },
        {  0.0f,    0.375f,  0.125f, 0.125f },
        {  0.125f,  0.375f,  0.125f, 0.125f },
        {  0.25f,   0.375f,  0.125f, 0.125f },
        {  0.375f,  0.375f,  0.125f, 0.125f },
        {  0.5f,    0.375f,  0.125f, 0.125f },
        { -1.0f,    0.0f,    0.0f,   0.0f   }
    };
    static UV_WORK* uvtble[4] = 
    {
        BH_UVTAB0,
        BH_UVTAB1,
        BH_UVTAB2,
        BH_UVTAB3
    };

    switch (op->mode0) 
    {
    case 0:
        op->flg    |= 0x4180000;
        op->stflg  |= 0x20;
        
        bhEff_SetBaseColor(op, -1);
        
        op->bl_src  = 8;
        op->bl_dst  = 3;
        
        op->mtn_no  = op->type & 0x3;
        op->frm_no  = 4.0f * (-rand() / -2.147483648E9f);
        
        op->sxb     = op->sx;
        op->syb     = op->sy;
        
        spd         = 0.5f + (0.6f * (-rand() / -2.147483648E9f));
        
        op->xn      = spd * -njSin(op->ay);
        op->zn      = spd * -njCos(op->ay);
        op->yn      = (1.4f * (-rand() / -2.147483648E9f)) - 0.6f;
        
        op->ct0     = 0;
        op->ct1     = 4.0f * (-rand() / -2.147483648E9f);
        op->ct2     = 1;

        if ((op->type == 0 )|| (op->type == 2)) 
        {
            op->ct3 = 30.0f + (20.0f * (-rand() / -2.147483648E9f));
        } 
        else 
        {
            op->ct3 = 10.0f + (5.0f * (-rand() / -2.147483648E9f));
        }        

        op->mode0 = 1;
    case 1:
        if ((op->ct0 == op->ct3) || (op->ct2 == 0)) 
        {
            op->mode0 = 2;
            
            op->ct0   = 0;
        } 
        else 
        {
            op->frm_no++;
            
            if (op->frm_no > 7) 
            {
                op->frm_no = 3;
            }
            
            op->ct0++;
        }

        if ((!(op->type & 0x100)) && (op->ct0 < 10)) 
        {
            sys->ef.id     = 296;
            
            sys->ef.flg    = 1;
            sys->ef.type   = 1;
            
            sys->ef.px  = op->px;
            sys->ef.py  = op->py;
            sys->ef.pz  = op->pz;
            
            size = 0.1f + (0.3f * (-rand() / -2.147483648E9f));
            
            sys->ef.sx = size;
            sys->ef.sy = size;
            sys->ef.sz = size;
            
            sys->ef.ax     = 0;
            sys->ef.ay     = 0;
            
            sys->ef.mdlver = op->mdlver;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            op->ct1 = 4.0f * (-rand() / -2.147483648E9f);
        }
        
        break;
    case 2:
        op->ct0++;
        
        if (op->ct0 >= 8) 
        {
            op->flg = 0;
            return;
        }
        
        bhEff_SetBaseColor(op, ((0xFF - (op->ct0 << 5)) << 24) | 0xFFFFFF);
        
        op->sx *= 0.9f;
        op->sy *= 0.9f;
        break;
    }

    if (op->ct2 != 0) 
    {
        op->px += op->xn;
        op->pz += op->zn;
        op->py += op->yn;
        
        op->yn -= 0.06f;

        p1.x = op->pxb;
        p1.y = op->pyb - 0.5f;
        p1.z = op->pzb;
        
        p2.x = op->px;
        p2.y = op->py - 0.5f;
        p2.z = op->pz;

        op->xn *= 0.97f;
        op->zn *= 0.97f;

        if (bhCollisionCheckLine2(&p1, &p2, 0x4400, -1) != NULL) 
        {
            bhGetHitCollisionNormal(&n);
            
            njUnitVector(&n);
            
            if (n.y > 0.9f) 
            {
                op->ct2 = 0;
            } 
            else 
            {
                op->xn = 0;
                op->zn = 0;
                op->yn = 0;
            }
            
            op->px = p2.x;
            op->py = 0.5f + p2.y;
            op->pz = p2.z;
        }
    }

    bhEff_SetUVInfo(op, &uvtble[op->mtn_no][op->frm_no], 0.0625f);

    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff_E00_DrawParticleSpr(O_WRK* op) 
{
   	P_WRK* pp;

    pp = (P_WRK*)op->exp0;
    
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

// 100% matching!
void bhEff_E00_DrawParticlePly(O_WRK* op)
{
    P_WRK* pp;

    pp = (P_WRK*)op->exp0;
    
    njSetMatrix(NULL, cam.mtx);
    
    njPtclPolygonStart(pp->col);
    njPtclDrawPolygon(pp->pos, pp->num, pp->sx);
    njPtclPolygonEnd();
}

// 100% matching!
void bhEff_E00_DropBlood(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK BH_UVTAB0[6] = 
    {
        { 0.84375f,  0.15625f, 0.0625f, 0.0625f },
        { 0.90625f,  0.15625f, 0.0625f, 0.0625f },
        { 0.53125f,  0.21875f, 0.0625f, 0.0625f },
        { 0.59375f,  0.21875f, 0.0625f, 0.0625f },
        { 0.65625f,  0.21875f, 0.0625f, 0.0625f },
        { -1.0f,     0.0f,     0.0f,    0.0f    },
    };
    static UV_WORK BH_UVTAB1[6] = 
    {
        { 0.71875f,  0.21875f, 0.0625f,  0.0625f  },
        { 0.78125f,  0.21875f, 0.09375f, 0.09375f },
        { 0.875f,    0.21875f, 0.09375f, 0.09375f },
        { 0.9375f,   0.3125f,  0.0625f,  0.0625f  },
        { 0.9375f,   0.375f,   0.0625f,  0.0625f  },
        { -1.0f,     0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK* uvtble[2] = 
    {
        BH_UVTAB0,
        BH_UVTAB1
    };

    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 5;
        
        bhEff_SetBaseColor(op, -1);
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0    = 0;
        op->ct1    = 0;
        
        op->flg   |= 0x180000;
        
        op->sxb    = op->sx;
        op->syb    = op->sy;
        
        op->yn     = bhGetGroundPosition((NJS_POINT3*)&op->px) + 0.2f;
        
        op->ofy    = -0.71f;
        
        op->mode0++;
    case 1:
        uvp = &uvtble[0][op->ct1];
        
        if (uvp->u == -1.0f) 
        {
            op->ct1 = 1;
            
            uvp = &uvtble[0][1];
        }
        
        op->ct1++;

        op->py += op->ofy;
        
        if (op->ofy > -2.0f)
        {
            op->ofy -= 0.15f;
        }
        
        if (op->py < op->yn) 
        {
            op->py = op->yn;
            
            op->mode0++;
        }
        
        break;
    case 2:
        uvp = &uvtble[1][op->ct1];
        
        if (uvp->u == -1.0f) 
        {
            op->flg = 0;
            return;
        }
        
        op->ct1++;
        break;
    }

    bhEff_SetUVInfo(op, uvp, 0.0625f);

    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff_E00_Fire(O_WRK* op) 
{
    UV_WORK* uvp;
    BH_PWORK* pp;
    static UV_WORK BH_UVTAB0[11] = 
    {
        {  0.0f,    0.375f,  0.1875f, 0.1875f },
        {  0.1875f, 0.375f,  0.1875f, 0.1875f },
        {  0.375f,  0.375f,  0.1875f, 0.1875f },
        {  0.5625f, 0.375f,  0.1875f, 0.1875f },
        {  0.75f,   0.375f,  0.1875f, 0.1875f },
        {  0.0f,    0.5625f, 0.1875f, 0.1875f },
        {  0.1875f, 0.5625f, 0.1875f, 0.1875f },
        {  0.375f,  0.5625f, 0.1875f, 0.1875f },
        {  0.5625f, 0.5625f, 0.1875f, 0.1875f },
        {  0.75f,   0.5625f, 0.1875f, 0.1875f },
        { -1.0f,    0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK BH_UVTAB1[11] = 
    {
        {  0.0f,    0.0f,    0.1875f, 0.1875f },
        {  0.1875f, 0.0f,    0.1875f, 0.1875f },
        {  0.375f,  0.0f,    0.1875f, 0.1875f },
        {  0.5625f, 0.0f,    0.1875f, 0.1875f },
        {  0.75f,   0.0f,    0.1875f, 0.1875f },
        {  0.0f,    0.1875f, 0.1875f, 0.1875f },
        {  0.1875f, 0.1875f, 0.1875f, 0.1875f },
        {  0.375f,  0.1875f, 0.1875f, 0.1875f },
        {  0.5625f, 0.1875f, 0.1875f, 0.1875f },
        {  0.75f,   0.1875f, 0.1875f, 0.1875f },
        { -1.0f,    0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK BH_UVTAB2[11] = 
    {
        {  0.75f,   0.5625f, 0.1875f, 0.1875f },
        {  0.5625f, 0.5625f, 0.1875f, 0.1875f },
        {  0.375f,  0.5625f, 0.1875f, 0.1875f },
        {  0.1875f, 0.5625f, 0.1875f, 0.1875f },
        {  0.0f,    0.5625f, 0.1875f, 0.1875f },
        {  0.75f,   0.375f,  0.1875f, 0.1875f },
        {  0.5625f, 0.375f,  0.1875f, 0.1875f },
        {  0.375f,  0.375f,  0.1875f, 0.1875f },
        {  0.1875f, 0.375f,  0.1875f, 0.1875f },
        {  0.0f,    0.375f,  0.1875f, 0.1875f },
        { -1.0f,    0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK* uvtble[3] = 
    {
        BH_UVTAB0,
        BH_UVTAB1,
        BH_UVTAB2
    };

    pp = (BH_PWORK*)op->lkwkp;
    
    if ((pp != NULL) && ((pp->stflg & 0x1000000))) 
    {
        return;
    }

    switch (op->mode0) 
    {
    case 0:
        op->flg    |= 0x4180000;
        
        op->tex_id  = 8;
        
        bhEff_SetBaseColor(op, 0x80FFFFFF);
        
        op->bl_src  = 8;
        op->bl_dst  = 10;
        
        op->sxb     = op->sx;
        op->syb     = op->sy;
        
        op->sx      = 0.1f;
        op->sy      = 0.1f;
        
        op->mtn_no  = 0;
        op->frm_no  = 0;
        
        op->mode0++;
        break;
    case 1:
        if (op->frm_no == 0) 
        {
            op->mtn_no++;
            
            op->frm_no = 10.0f * (-rand() / -2.1474836E9f);
            
            op->mode0++;
            
            op->sx      = op->sxb;
            op->sy      = op->syb;
        }

        op->sx += (op->sxb - op->sx) / 32.0f;
        op->sy += (op->syb - op->sy) / 32.0f;
        break;
    case 2:
        if (op->ct0-- == 0) 
        {
            op->mtn_no++;
            
            op->frm_no  = 0;
            
            op->mode0++;
        }
        
        break;
    case 3:
        if (op->frm_no == 0)
        {
            op->flg = 0;
            return;
        }
        
        op->sx += (0.01f - op->sx) / 32.0f;
        op->sy += (0.01f - op->sy) / 32.0f;
        break;
    }

    uvp = &uvtble[op->mtn_no][op->frm_no];
    
    op->frm_no++;
    
    if (uvtble[op->mtn_no][op->frm_no].u < 0) 
    {
        op->frm_no = 0;
    }

    bhEff_SetUVInfo(op, uvp, 0.125f);

    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff_E00_Acid(O_WRK* op) 
{
    UV_WORK* uvp;
    static UV_WORK BH_UVTAB0[8] = 
    {
        {  0.25f,   0.0f,    0.125f,  0.125f  },
        {  0.5f,    0.0f,    0.125f,  0.125f  },
        {  0.75f,   0.0f,    0.125f,  0.125f  },
        {  0.0f,    0.125f,  0.1875f, 0.1875f },
        {  0.1875f, 0.125f,  0.1875f, 0.1875f },
        {  0.375f,  0.125f,  0.1875f, 0.1875f },
        {  0.0f,    0.3125f, 0.1875f, 0.1875f },
        { -1.0f,    0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK* uvtble[1] = 
    {
        BH_UVTAB0
    };

    switch (op->mode0) 
    {
    case 0:
        op->tex_id  = 2;
        
        op->bl_src  = 8;
        op->bl_dst  = 6;
        
        op->flg    |= 0x180000;
        op->stflg  &= ~0x20;
        
        op->sxb     = op->sx;
        op->syb     = op->sy;
        
        op->yn      = 0.2f + (0.4f * (-rand() / -2.147483648E9f));
        
        op->ct0     = (int)(10.0f * (-rand() / -2.147483648E9f)) + 10;
        op->ct2     = 64;
        
        op->mode0   = 1;
    case 1:
        if (op->ct0-- == 0) 
        {
            op->flg = 0;
            return;
        }

        uvp = &uvtble[0][op->ct1];
        
        if (uvp->u < 0)
        {
            op->ct1--;
            
            uvp      = &uvtble[0][op->ct1];
            
            op->ct2 -= 8;
            
            if (op->ct2 < 5)
            {
                op->ct2 = 0;
            }
        }
        
        op->ct1++;
        
        bhEff_SetBaseColor(op, (op->ct2 << 24) | 0xD2CDC8);
        bhEff_SetUVInfo(op, uvp, 0.09375f);

        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->xn *= 0.9f;
        op->yn *= 0.9f;
        op->zn *= 0.9f;
        
        op->xn += (0.2f * (-rand() / -2.147483648E9f)) - 0.1f;
        op->zn += (0.2f * (-rand() / -2.147483648E9f)) - 0.1f;

        if (sys->ef_trsn < 512) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            
            sys->ef_trsn++;
        }

        break;
    }
}

// 100% matching!
void bhEff_E00_AcidGenerator(O_WRK* op) 
{
    UV_WORK* uvp;
    O_WRK* owp; // not from DWARF
    
    owp = (O_WRK*)op->lkwkp;
    
    if ((owp == NULL) || (!(owp->stflg & 0x1000000)))
    {
        switch (op->mode0)
        {                          
        case 0:
            op->ct0 = 5;
            
            op->mode0++;
        case 1:
            if (op->ct0-- == 0)
            {
                op->mode0++;
                return;
            }
            
            break;
        case 2:
            sys->ef.id = 257;
            
            sys->ef.flg = 1;
            sys->ef.type = 0;
            
            sys->ef.px = op->px;
            sys->ef.py = op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.sx = op->sx;
            sys->ef.sy = op->sy;
            sys->ef.sz = op->sz;
            
            sys->ef.ax = 0;
            sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            sys->ef.px = op->px + (0.5f * (op->sx * ((-rand() / -2.1474836E9f) - 0.5f)));
            sys->ef.py = op->py + (0.5f * (op->sy * ((-rand() / -2.1474836E9f) - 0.5f)));
            sys->ef.pz = op->pz + (0.5f * (op->sz * ((-rand() / -2.1474836E9f) - 0.5f)));
            
            sys->ef.sx = 0.4f * op->sx;
            sys->ef.sy = 0.4f * op->sy;
            sys->ef.sz = 0.4f * op->sz;
            
            sys->ef.ax = 0;
            sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            if (op->type > 0)
            {
                op->type--;
            }
            
            if (op->type == 0) 
            {
                op->flg = 0;
            }
            
            break;
        }
    }
}

// 100% matching!
void bhEff_E00_BloodBurst(O_WRK* op)
{
    P_WK* p;
    BH_PWORK* pp;
    NJS_POINT3 v;
    int eno;
    O_WRK* owp; // not from DWARF
    static P_WK type0[2] = 
    {
        { 17,     1, 1.5f, 0.3f, 4      },
        { 0xFFFF, 2, 0.7f, 0.5f, 0xFFFF }
    };
    static P_WK type1[4] = 
    {
        { 17,     1, 1.5f, -0.8f, 0      },
        { 9,      1, 1.5f,  0.3f, 4      },
        { 17,     2, 1.5f,  0.3f, 2      },
        { 0xFFFF, 2, 1.0f,  0.5f, 0xFFFF } 
    };
    static P_WK type2[5] = 
    {
        { 17, 1, 1.5f,  0.1f, 0      },
        { 17, 1, 1.5f, -0.8f, 0      },
        { 9,  1, 1.8f,  0.3f, 4      },
        { 17, 2, 2.3f,  0.3f, 2      },
        { 9,  1, 1.7f,  0.5f, 0xFFFF }
    };
    static P_WK type3[2] = 
    {
        { 9,  2, 1.8f, 0.3f, 3      },
        { 10, 1, 1.7f, 0.5f, 0xFFFF }
    };
    static P_WK type4[5] = 
    {
        { 17,     1, 1.5f, 0.1f, 0      },
        { 0xFFFF, 2, 1.5f, 0.8f, 0      },
        { 10,     2, 1.3f, 0.6f, 6      },
        { 17,     2, 1.5f, 0.4f, 0      },
        { 9,      1, 1.0f, 0.7f, 0xFFFF }
    };
    static P_WK type5[2] = 
    {
        { 17, 1, 1.5f, 0.8f, 0      },
        { 10, 2, 1.3f, 0.6f, 0xFFFF }
    };
    static P_WK type6[1] = 
    {
        { 17, 2, 1.5f, 0.8f, 0xFFFF }
    };
    static P_WK* TypeList[7] = 
    {
        type0,
        type1,
        type2,
        type3,
        type4,
        type5,
        type6
    };

    pp = (BH_PWORK*)op->lkwkp;
    
    if ((pp != NULL) && ((pp->stflg & 0x1000000))) 
    {
        return;
    }

    switch (op->mode0) 
    {
    case 0:
        njUnitVector((NJS_VECTOR*)&op->xn);
        
        op->frm_no = 0;
        
        op->mode0++; 
    case 1:
    label:
        p = &TypeList[op->type][op->frm_no];

        if (p->type1 >= 0) 
        {
            if (p->spd > 0)
            {
                bhSetEffParticleMk2((BH_PWORK*)op->lkwkp, op->lkono, (NJS_POINT3*)&op->lox, (NJS_POINT3*)&op->xn, BloodCol[op->mdlver][0], BloodCol[op->mdlver][1], p->type1);
            } 
            else
            {
                v.x = -op->xn;
                v.y = -op->yn;
                v.z = -op->zn;
                
                bhSetEffParticleMk2((BH_PWORK*)op->lkwkp, op->lkono, (NJS_POINT3*)&op->lox, &v, BloodCol[op->mdlver][0], BloodCol[op->mdlver][1], p->type1);
            }
        }

        if (p->type2 >= 0) 
        {
            sys->ef.id     = 296;
            
            sys->ef.flg    = 1;
            sys->ef.type   = p->type2;
            
            sys->ef.sx     = op->sx * p->size;
            sys->ef.sy     = op->sy * p->size;
            sys->ef.sz     = 1.0f;
            
            sys->ef.ax     = 0;
            sys->ef.ay     = 0;
            
            sys->ef.mdlver = op->mdlver;

            owp = (O_WRK*)op->lkwkp;
            
            njCalcPoint(&owp->mlwP->owP[op->lkono].mtx, (NJS_POINT3*)&op->lox, (NJS_POINT3*)&sys->ef.px);

            eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            if (eno != -1) 
            {
                eff[eno].xn = op->xn * p->spd;
                eff[eno].yn = op->yn * p->spd;
                eff[eno].zn = op->zn * p->spd;
            }
        }

        op->ct0 = p->wait;

        if (p->wait == -1)
        {
            op->flg = 0;
            return;
        }

        if (p->wait == 0) 
        {
            op->frm_no++;
            goto label;
        }

        op->frm_no++;
        
        op->mode0++;
    case 2:
        if (op->ct0 != 0) 
        {
            op->ct0--;
            return;
        }
        
        op->mode0--;
    }
}

// 100% matching!
void bhEff_E00_Blood(O_WRK* op) 
{
    UV_WORK* uvp;
    static UV_WORK BH_UVTAB0[13] =
    {
        {  0.3125f,  0.5f,     0.0625f,  0.0625f  },
        {  0.375f,   0.4375f,  0.125f,   0.125f   },
        {  0.5f,     0.4375f,  0.15625f, 0.15625f },
        {  0.65625f, 0.4375f,  0.15625f, 0.15625f },
        {  0.8125f,  0.4375f,  0.15625f, 0.15625f },
        {  0.0f,     0.5625f,  0.1875f,  0.1875f  },
        {  0.1875f,  0.5625f,  0.1875f,  0.1875f  },
        {  0.375f,   0.59375f, 0.1875f,  0.1875f  },
        {  0.5625f,  0.59375f, 0.1875f,  0.1875f  },
        {  0.0f,     0.78125f, 0.21875f, 0.21875f },
        {  0.21875f, 0.78125f, 0.21875f, 0.21875f },
        {  0.4375f,  0.78125f, 0.21875f, 0.21875f },
        { -1.0f,     0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK BH_UVTAB1[12] = 
    {
        {  0.0f,     0.25f,    0.0625f,  0.0625f  },
        {  0.0f,     0.15625f, 0.09375f, 0.09375f },
        {  0.09375f, 0.15625f, 0.125f,   0.125f   },
        {  0.21875f, 0.15625f, 0.15625f, 0.15625f },
        {  0.375f,   0.15625f, 0.15625f, 0.15625f },
        {  0.0f,     0.0f,     0.15625f, 0.15625f },
        {  0.15625f, 0.0f,     0.15625f, 0.15625f },
        {  0.3125f,  0.0f,     0.15625f, 0.15625f },
        {  0.46875f, 0.0f,     0.15625f, 0.15625f },
        {  0.625f,   0.0f,     0.15625f, 0.15625f },
        {  0.78125f, 0.125f,   0.15625f, 0.15625f },
        { -1.0f,     0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK BH_UVTAB2[14] =
    {
        {  0.0f,    0.3125f, 0.0625f, 0.0625f },
        {  0.0f,    0.5f,    0.0625f, 0.0625f },
        {  0.0f,    0.375f,  0.0625f, 0.0625f },
        {  0.0f,    0.4375f, 0.0625f, 0.0625f },
        {  0.0625f, 0.3125f, 0.125f,  0.125f  },
        {  0.1875f, 0.3125f, 0.125f,  0.125f  },
        {  0.3125f, 0.3125f, 0.125f,  0.125f  },
        {  0.4375f, 0.3125f, 0.125f,  0.125f  },
        {  0.5625f, 0.3125f, 0.125f,  0.125f  },
        {  0.6875f, 0.3125f, 0.125f,  0.125f  },
        {  0.8125f, 0.3125f, 0.125f,  0.125f  },
        {  0.0625f, 0.4375f, 0.125f,  0.125f  },
        {  0.1875f, 0.4375f, 0.125f,  0.125f  },
        { -1.0f,    0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK* uvtble[3] = 
    {
        BH_UVTAB0,
        BH_UVTAB1,
        BH_UVTAB2
    };

    switch (op->mode0) 
    {
    case 0:
        op->tex_id  = 5;
        
        op->flg    |= 0x4180000;
        
        bhEff_SetBaseColor(op, -1);
        
        op->bl_src  = 8;
        op->bl_dst  = 6;
        
        op->ani_ct  = op->mdlver;
        
        op->sxb     = op->sx;
        op->syb     = op->sy;
        
        op->mtn_no  = op->type;
        op->frm_no  = 0;
        
        op->mode0++;
        break;
    case 1:
        if (op->frm_no == 0) 
        {
            op->flg = 0;
            return;
        }
        
        break;
    }

    op->px += op->xn;
    op->py += op->yn;
    op->pz += op->zn;
    
    op->xn *= 0.97f;
    op->yn *= 0.97f;
    op->zn *= 0.97f;
    
    op->yn -= 0.1f;

    uvp = &uvtble[op->mtn_no][op->frm_no];
    
    op->frm_no++;
    
    if (uvtble[op->mtn_no][op->frm_no].u < 0) 
    {
        op->frm_no = 0;
    }

    bhEff_SetUVInfo(op, uvp, 0.125f);

    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff_E00_Dust(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK BH_UVTAB0[23] = 
    {
        {  0.25f,   0.0f,    0.125f,  0.125f  },
        {  0.5f,    0.0f,    0.125f,  0.125f  },
        {  0.75f,   0.0f,    0.125f,  0.125f  },
        {  0.0f,    0.125f,  0.1875f, 0.1875f },
        {  0.0f,    0.125f,  0.1875f, 0.1875f },
        {  0.375f,  0.125f,  0.1875f, 0.1875f },
        {  0.375f,  0.125f,  0.1875f, 0.1875f },
        {  0.1875f, 0.3125f, 0.1875f, 0.1875f },
        {  0.1875f, 0.3125f, 0.1875f, 0.1875f },
        {  0.1875f, 0.3125f, 0.1875f, 0.1875f },
        {  0.0f,    0.5f,    0.1875f, 0.1875f },
        {  0.0f,    0.5f,    0.1875f, 0.1875f },
        {  0.0f,    0.5f,    0.1875f, 0.1875f },
        {  0.375f,  0.5f,    0.1875f, 0.1875f },
        {  0.375f,  0.5f,    0.1875f, 0.1875f },
        {  0.375f,  0.5f,    0.1875f, 0.1875f },
        {  0.375f,  0.5f,    0.1875f, 0.1875f },
        {  0.375f,  0.5f,    0.1875f, 0.1875f },
        {  0.375f,  0.5f,    0.1875f, 0.1875f },
        {  0.375f,  0.5f,    0.1875f, 0.1875f },
        {  0.375f,  0.5f,    0.1875f, 0.1875f },
        {  0.375f,  0.5f,    0.1875f, 0.1875f },
        { -1.0f,    0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK* uvtble[1] = 
    {
        BH_UVTAB0
    };

    switch (op->mode0)
    {                             
    case 0:
        op->tex_id = 2;
        
        bhEff_SetAlign(op, 2);
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->flg |= 0x180000;
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->ct0 = 50;
        op->ct1 = 0;
        
        op->mode0 = 1;
    case 1:
        bhEff_SetBaseColor(op, (op->ct0 << 24) | 0x373737);
        
        op->ct0 -= 2;
        
        uvp = &uvtble[0][op->ct1];
        
        if (uvp->u < 0) 
        {
            op->flg = 0;
            return;
        }
        
        op->ct1++;
        
        bhEff_SetUVInfo(op, uvp, 0.09375f);
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->xn *= 0.8f;
        op->yn *= 0.8f;
        op->zn *= 0.8f;
        
        if (sys->ef_trsn < 512) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            
            sys->ef_trsn++;
        }
        
        break;
    }
}

// 
// Start address: 0x23f050
void bhEff_E02_SandDust(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK* uvtble[6];
	// Line 1063, Address: 0x23f050, Func Offset: 0
	// Line 1176, Address: 0x23f05c, Func Offset: 0xc
	// Line 1178, Address: 0x23f07c, Func Offset: 0x2c
	// Line 1179, Address: 0x23f088, Func Offset: 0x38
	// Line 1180, Address: 0x23f098, Func Offset: 0x48
	// Line 1181, Address: 0x23f0a0, Func Offset: 0x50
	// Line 1182, Address: 0x23f0a8, Func Offset: 0x58
	// Line 1186, Address: 0x23f0ac, Func Offset: 0x5c
	// Line 1187, Address: 0x23f0b0, Func Offset: 0x60
	// Line 1190, Address: 0x23f0b4, Func Offset: 0x64
	// Line 1182, Address: 0x23f0b8, Func Offset: 0x68
	// Line 1183, Address: 0x23f0c0, Func Offset: 0x70
	// Line 1184, Address: 0x23f0c4, Func Offset: 0x74
	// Line 1185, Address: 0x23f0c8, Func Offset: 0x78
	// Line 1186, Address: 0x23f0cc, Func Offset: 0x7c
	// Line 1187, Address: 0x23f0d8, Func Offset: 0x88
	// Line 1188, Address: 0x23f0e4, Func Offset: 0x94
	// Line 1189, Address: 0x23f0ec, Func Offset: 0x9c
	// Line 1190, Address: 0x23f0f4, Func Offset: 0xa4
	// Line 1192, Address: 0x23f0f8, Func Offset: 0xa8
	// Line 1193, Address: 0x23f10c, Func Offset: 0xbc
	// Line 1192, Address: 0x23f110, Func Offset: 0xc0
	// Line 1193, Address: 0x23f130, Func Offset: 0xe0
	// Line 1195, Address: 0x23f144, Func Offset: 0xf4
	// Line 1197, Address: 0x23f14c, Func Offset: 0xfc
	// Line 1200, Address: 0x23f154, Func Offset: 0x104
	// Line 1205, Address: 0x23f15c, Func Offset: 0x10c
	// Line 1200, Address: 0x23f160, Func Offset: 0x110
	// Line 1201, Address: 0x23f168, Func Offset: 0x118
	// Line 1202, Address: 0x23f178, Func Offset: 0x128
	// Line 1205, Address: 0x23f188, Func Offset: 0x138
	// Line 1206, Address: 0x23f194, Func Offset: 0x144
	// Line 1207, Address: 0x23f1b0, Func Offset: 0x160
	// Line 1208, Address: 0x23f1bc, Func Offset: 0x16c
	// Line 1212, Address: 0x23f1c8, Func Offset: 0x178
	// Line 1215, Address: 0x23f1d8, Func Offset: 0x188
	// Line 1212, Address: 0x23f1e0, Func Offset: 0x190
	// Line 1215, Address: 0x23f1e4, Func Offset: 0x194
	// Line 1217, Address: 0x23f1f0, Func Offset: 0x1a0
	// Line 1218, Address: 0x23f210, Func Offset: 0x1c0
	// Line 1219, Address: 0x23f224, Func Offset: 0x1d4
	// Line 1222, Address: 0x23f248, Func Offset: 0x1f8
	// Func End, Address: 0x23f258, Func Offset: 0x208
	scePrintf("bhEff_E02_SandDust - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x23f260
void bhEff_E02_SandParticle(O_WRK* op)
{
	unsigned int col[3];
	int i;
	NJS_POINT3* v;
	NJS_POINT3* p;
	//_anon6* pp;
	// Line 1232, Address: 0x23f260, Func Offset: 0
	// Line 1237, Address: 0x23f278, Func Offset: 0x18
	// Line 1232, Address: 0x23f27c, Func Offset: 0x1c
	// Line 1237, Address: 0x23f280, Func Offset: 0x20
	// Line 1232, Address: 0x23f284, Func Offset: 0x24
	// Line 1237, Address: 0x23f288, Func Offset: 0x28
	// Line 1243, Address: 0x23f2a0, Func Offset: 0x40
	// Line 1246, Address: 0x23f2c0, Func Offset: 0x60
	// Line 1247, Address: 0x23f2cc, Func Offset: 0x6c
	// Line 1249, Address: 0x23f2d4, Func Offset: 0x74
	// Line 1253, Address: 0x23f2dc, Func Offset: 0x7c
	// Line 1252, Address: 0x23f2e0, Func Offset: 0x80
	// Line 1254, Address: 0x23f2e4, Func Offset: 0x84
	// Line 1255, Address: 0x23f2e8, Func Offset: 0x88
	// Line 1253, Address: 0x23f2ec, Func Offset: 0x8c
	// Line 1256, Address: 0x23f2f0, Func Offset: 0x90
	// Line 1257, Address: 0x23f2f8, Func Offset: 0x98
	// Line 1258, Address: 0x23f358, Func Offset: 0xf8
	// Line 1259, Address: 0x23f3b8, Func Offset: 0x158
	// Line 1260, Address: 0x23f418, Func Offset: 0x1b8
	// Line 1261, Address: 0x23f478, Func Offset: 0x218
	// Line 1262, Address: 0x23f4d8, Func Offset: 0x278
	// Line 1263, Address: 0x23f518, Func Offset: 0x2b8
	// Line 1262, Address: 0x23f51c, Func Offset: 0x2bc
	// Line 1263, Address: 0x23f524, Func Offset: 0x2c4
	// Line 1262, Address: 0x23f528, Func Offset: 0x2c8
	// Line 1263, Address: 0x23f540, Func Offset: 0x2e0
	// Line 1265, Address: 0x23f558, Func Offset: 0x2f8
	// Line 1266, Address: 0x23f560, Func Offset: 0x300
	// Line 1268, Address: 0x23f564, Func Offset: 0x304
	// Line 1270, Address: 0x23f574, Func Offset: 0x314
	// Line 1272, Address: 0x23f5b4, Func Offset: 0x354
	// Line 1275, Address: 0x23f5bc, Func Offset: 0x35c
	// Line 1272, Address: 0x23f5c4, Func Offset: 0x364
	// Line 1275, Address: 0x23f5cc, Func Offset: 0x36c
	// Line 1276, Address: 0x23f5d0, Func Offset: 0x370
	// Line 1277, Address: 0x23f5d8, Func Offset: 0x378
	// Line 1279, Address: 0x23f5e0, Func Offset: 0x380
	// Line 1282, Address: 0x23f5e4, Func Offset: 0x384
	// Line 1280, Address: 0x23f600, Func Offset: 0x3a0
	// Line 1282, Address: 0x23f604, Func Offset: 0x3a4
	// Line 1283, Address: 0x23f60c, Func Offset: 0x3ac
	// Line 1291, Address: 0x23f614, Func Offset: 0x3b4
	// Line 1283, Address: 0x23f618, Func Offset: 0x3b8
	// Line 1284, Address: 0x23f620, Func Offset: 0x3c0
	// Line 1285, Address: 0x23f630, Func Offset: 0x3d0
	// Line 1288, Address: 0x23f640, Func Offset: 0x3e0
	// Line 1291, Address: 0x23f644, Func Offset: 0x3e4
	// Line 1288, Address: 0x23f648, Func Offset: 0x3e8
	// Line 1289, Address: 0x23f650, Func Offset: 0x3f0
	// Line 1290, Address: 0x23f65c, Func Offset: 0x3fc
	// Line 1291, Address: 0x23f668, Func Offset: 0x408
	// Line 1293, Address: 0x23f680, Func Offset: 0x420
	// Line 1294, Address: 0x23f690, Func Offset: 0x430
	// Line 1296, Address: 0x23f694, Func Offset: 0x434
	// Line 1299, Address: 0x23f69c, Func Offset: 0x43c
	// Line 1300, Address: 0x23f6bc, Func Offset: 0x45c
	// Line 1301, Address: 0x23f6d0, Func Offset: 0x470
	// Line 1304, Address: 0x23f6f4, Func Offset: 0x494
	// Func End, Address: 0x23f718, Func Offset: 0x4b8
	scePrintf("bhEff_E02_SandParticle - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x23f720
void bhEff_E02_SandParticle2(O_WRK* op)
{
	int eno;
	O_WRK* opw;
	// Line 1314, Address: 0x23f720, Func Offset: 0
	// Line 1318, Address: 0x23f730, Func Offset: 0x10
	// Line 1320, Address: 0x23f750, Func Offset: 0x30
	// Line 1321, Address: 0x23f794, Func Offset: 0x74
	// Line 1322, Address: 0x23f79c, Func Offset: 0x7c
	// Line 1324, Address: 0x23f7a4, Func Offset: 0x84
	// Line 1327, Address: 0x23f7b4, Func Offset: 0x94
	// Line 1328, Address: 0x23f7fc, Func Offset: 0xdc
	// Line 1329, Address: 0x23f808, Func Offset: 0xe8
	// Line 1338, Address: 0x23f80c, Func Offset: 0xec
	// Line 1328, Address: 0x23f810, Func Offset: 0xf0
	// Line 1329, Address: 0x23f81c, Func Offset: 0xfc
	// Line 1338, Address: 0x23f824, Func Offset: 0x104
	// Line 1329, Address: 0x23f82c, Func Offset: 0x10c
	// Line 1330, Address: 0x23f838, Func Offset: 0x118
	// Line 1331, Address: 0x23f84c, Func Offset: 0x12c
	// Line 1332, Address: 0x23f864, Func Offset: 0x144
	// Line 1333, Address: 0x23f87c, Func Offset: 0x15c
	// Line 1334, Address: 0x23f894, Func Offset: 0x174
	// Line 1335, Address: 0x23f8a8, Func Offset: 0x188
	// Line 1338, Address: 0x23f8bc, Func Offset: 0x19c
	// Line 1339, Address: 0x23f8d4, Func Offset: 0x1b4
	// Line 1340, Address: 0x23f8dc, Func Offset: 0x1bc
	// Line 1343, Address: 0x23f8fc, Func Offset: 0x1dc
	// Line 1344, Address: 0x23f904, Func Offset: 0x1e4
	// Line 1345, Address: 0x23f908, Func Offset: 0x1e8
	// Line 1347, Address: 0x23f90c, Func Offset: 0x1ec
	// Line 1348, Address: 0x23f914, Func Offset: 0x1f4
	// Line 1347, Address: 0x23f918, Func Offset: 0x1f8
	// Line 1348, Address: 0x23f91c, Func Offset: 0x1fc
	// Line 1349, Address: 0x23f924, Func Offset: 0x204
	// Line 1354, Address: 0x23f928, Func Offset: 0x208
	// Func End, Address: 0x23f938, Func Offset: 0x218
	scePrintf("bhEff_E02_SandParticle2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x23f940
void bhEff_E03_Acid(O_WRK* op)
{
	NJS_POINT3 n;
	UV_WORK* uvp;
	//_anon48 param[7];
	//_anon51 c;
	//_anon24* hp;
	UV_WORK* uvtble[3];
	// Line 1364, Address: 0x23f940, Func Offset: 0
	// Line 1367, Address: 0x23f94c, Func Offset: 0xc
	// Line 1364, Address: 0x23f954, Func Offset: 0x14
	// Line 1367, Address: 0x23f958, Func Offset: 0x18
	// Line 1420, Address: 0x23f96c, Func Offset: 0x2c
	// Line 1367, Address: 0x23f970, Func Offset: 0x30
	// Line 1420, Address: 0x23f990, Func Offset: 0x50
	// Line 1422, Address: 0x23f9c4, Func Offset: 0x84
	// Line 1423, Address: 0x23f9cc, Func Offset: 0x8c
	// Line 1425, Address: 0x23f9dc, Func Offset: 0x9c
	// Line 1426, Address: 0x23f9ec, Func Offset: 0xac
	// Line 1427, Address: 0x23f9f4, Func Offset: 0xb4
	// Line 1428, Address: 0x23f9f8, Func Offset: 0xb8
	// Line 1430, Address: 0x23fa00, Func Offset: 0xc0
	// Line 1431, Address: 0x23fa10, Func Offset: 0xd0
	// Line 1432, Address: 0x23fa18, Func Offset: 0xd8
	// Line 1434, Address: 0x23fa20, Func Offset: 0xe0
	// Line 1435, Address: 0x23fa28, Func Offset: 0xe8
	// Line 1441, Address: 0x23fa2c, Func Offset: 0xec
	// Line 1434, Address: 0x23fa30, Func Offset: 0xf0
	// Line 1435, Address: 0x23fa38, Func Offset: 0xf8
	// Line 1436, Address: 0x23fa3c, Func Offset: 0xfc
	// Line 1437, Address: 0x23fa40, Func Offset: 0x100
	// Line 1438, Address: 0x23fa4c, Func Offset: 0x10c
	// Line 1439, Address: 0x23fa54, Func Offset: 0x114
	// Line 1441, Address: 0x23fa5c, Func Offset: 0x11c
	// Line 1442, Address: 0x23fa68, Func Offset: 0x128
	// Line 1443, Address: 0x23fa70, Func Offset: 0x130
	// Line 1444, Address: 0x23fa78, Func Offset: 0x138
	// Line 1447, Address: 0x23fa88, Func Offset: 0x148
	// Line 1448, Address: 0x23fa8c, Func Offset: 0x14c
	// Line 1449, Address: 0x23fa90, Func Offset: 0x150
	// Line 1451, Address: 0x23fa9c, Func Offset: 0x15c
	// Line 1452, Address: 0x23faa8, Func Offset: 0x168
	// Line 1453, Address: 0x23fab0, Func Offset: 0x170
	// Line 1454, Address: 0x23faf0, Func Offset: 0x1b0
	// Line 1456, Address: 0x23faf8, Func Offset: 0x1b8
	// Line 1458, Address: 0x23fb00, Func Offset: 0x1c0
	// Line 1460, Address: 0x23fb10, Func Offset: 0x1d0
	// Line 1464, Address: 0x23fb18, Func Offset: 0x1d8
	// Line 1466, Address: 0x23fb24, Func Offset: 0x1e4
	// Line 1470, Address: 0x23fb2c, Func Offset: 0x1ec
	// Line 1472, Address: 0x23fb3c, Func Offset: 0x1fc
	// Line 1476, Address: 0x23fb44, Func Offset: 0x204
	// Line 1480, Address: 0x23fb50, Func Offset: 0x210
	// Line 1472, Address: 0x23fb54, Func Offset: 0x214
	// Line 1480, Address: 0x23fb58, Func Offset: 0x218
	// Line 1472, Address: 0x23fb5c, Func Offset: 0x21c
	// Line 1473, Address: 0x23fb60, Func Offset: 0x220
	// Line 1480, Address: 0x23fb68, Func Offset: 0x228
	// Line 1473, Address: 0x23fb70, Func Offset: 0x230
	// Line 1474, Address: 0x23fb78, Func Offset: 0x238
	// Line 1476, Address: 0x23fb88, Func Offset: 0x248
	// Line 1477, Address: 0x23fb94, Func Offset: 0x254
	// Line 1478, Address: 0x23fba0, Func Offset: 0x260
	// Line 1480, Address: 0x23fbac, Func Offset: 0x26c
	// Line 1483, Address: 0x23fbb8, Func Offset: 0x278
	// Line 1484, Address: 0x23fbd0, Func Offset: 0x290
	// Line 1491, Address: 0x23fbd4, Func Offset: 0x294
	// Line 1490, Address: 0x23fbdc, Func Offset: 0x29c
	// Line 1491, Address: 0x23fbe0, Func Offset: 0x2a0
	// Line 1484, Address: 0x23fbe4, Func Offset: 0x2a4
	// Line 1485, Address: 0x23fbe8, Func Offset: 0x2a8
	// Line 1491, Address: 0x23fbec, Func Offset: 0x2ac
	// Line 1485, Address: 0x23fbf0, Func Offset: 0x2b0
	// Line 1486, Address: 0x23fbf4, Func Offset: 0x2b4
	// Line 1487, Address: 0x23fbfc, Func Offset: 0x2bc
	// Line 1488, Address: 0x23fc04, Func Offset: 0x2c4
	// Line 1489, Address: 0x23fc0c, Func Offset: 0x2cc
	// Line 1491, Address: 0x23fc14, Func Offset: 0x2d4
	// Line 1493, Address: 0x23fc24, Func Offset: 0x2e4
	// Line 1495, Address: 0x23fc50, Func Offset: 0x310
	// Line 1496, Address: 0x23fc78, Func Offset: 0x338
	// Line 1500, Address: 0x23fc98, Func Offset: 0x358
	// Line 1506, Address: 0x23fca8, Func Offset: 0x368
	// Line 1500, Address: 0x23fcac, Func Offset: 0x36c
	// Line 1501, Address: 0x23fcb0, Func Offset: 0x370
	// Line 1500, Address: 0x23fcb4, Func Offset: 0x374
	// Line 1501, Address: 0x23fcbc, Func Offset: 0x37c
	// Line 1503, Address: 0x23fcc4, Func Offset: 0x384
	// Line 1501, Address: 0x23fcc8, Func Offset: 0x388
	// Line 1503, Address: 0x23fcd0, Func Offset: 0x390
	// Line 1504, Address: 0x23fcd8, Func Offset: 0x398
	// Line 1503, Address: 0x23fcdc, Func Offset: 0x39c
	// Line 1504, Address: 0x23fce0, Func Offset: 0x3a0
	// Line 1505, Address: 0x23fce8, Func Offset: 0x3a8
	// Line 1504, Address: 0x23fcec, Func Offset: 0x3ac
	// Line 1505, Address: 0x23fcf0, Func Offset: 0x3b0
	// Line 1506, Address: 0x23fcf8, Func Offset: 0x3b8
	// Line 1505, Address: 0x23fcfc, Func Offset: 0x3bc
	// Line 1506, Address: 0x23fd00, Func Offset: 0x3c0
	// Line 1508, Address: 0x23fd08, Func Offset: 0x3c8
	// Line 1510, Address: 0x23fd30, Func Offset: 0x3f0
	// Line 1511, Address: 0x23fd7c, Func Offset: 0x43c
	// Line 1516, Address: 0x23fd94, Func Offset: 0x454
	// Line 1517, Address: 0x23fda0, Func Offset: 0x460
	// Line 1527, Address: 0x23fda4, Func Offset: 0x464
	// Line 1516, Address: 0x23fda8, Func Offset: 0x468
	// Line 1517, Address: 0x23fdb4, Func Offset: 0x474
	// Line 1527, Address: 0x23fdbc, Func Offset: 0x47c
	// Line 1517, Address: 0x23fdc4, Func Offset: 0x484
	// Line 1518, Address: 0x23fdd0, Func Offset: 0x490
	// Line 1519, Address: 0x23fde4, Func Offset: 0x4a4
	// Line 1520, Address: 0x23fdfc, Func Offset: 0x4bc
	// Line 1521, Address: 0x23fe14, Func Offset: 0x4d4
	// Line 1522, Address: 0x23fe2c, Func Offset: 0x4ec
	// Line 1523, Address: 0x23fe44, Func Offset: 0x504
	// Line 1524, Address: 0x23fe5c, Func Offset: 0x51c
	// Line 1525, Address: 0x23fe74, Func Offset: 0x534
	// Line 1526, Address: 0x23fe88, Func Offset: 0x548
	// Line 1527, Address: 0x23fe9c, Func Offset: 0x55c
	// Line 1530, Address: 0x23feb4, Func Offset: 0x574
	// Line 1534, Address: 0x23febc, Func Offset: 0x57c
	// Line 1536, Address: 0x23fecc, Func Offset: 0x58c
	// Line 1537, Address: 0x23fee0, Func Offset: 0x5a0
	// Line 1540, Address: 0x23fee8, Func Offset: 0x5a8
	// Line 1541, Address: 0x23fef0, Func Offset: 0x5b0
	// Line 1543, Address: 0x23fef8, Func Offset: 0x5b8
	// Line 1545, Address: 0x23ff30, Func Offset: 0x5f0
	// Line 1546, Address: 0x23ff38, Func Offset: 0x5f8
	// Line 1548, Address: 0x23ff40, Func Offset: 0x600
	// Line 1549, Address: 0x23ff50, Func Offset: 0x610
	// Line 1550, Address: 0x23ff60, Func Offset: 0x620
	// Line 1553, Address: 0x23ff70, Func Offset: 0x630
	// Line 1552, Address: 0x23ff74, Func Offset: 0x634
	// Line 1553, Address: 0x23ff78, Func Offset: 0x638
	// Line 1555, Address: 0x23ff7c, Func Offset: 0x63c
	// Line 1557, Address: 0x23ff8c, Func Offset: 0x64c
	// Line 1558, Address: 0x23ff98, Func Offset: 0x658
	// Line 1563, Address: 0x23ff9c, Func Offset: 0x65c
	// Line 1557, Address: 0x23ffa0, Func Offset: 0x660
	// Line 1558, Address: 0x23ffac, Func Offset: 0x66c
	// Line 1564, Address: 0x23ffb4, Func Offset: 0x674
	// Line 1565, Address: 0x23ffb8, Func Offset: 0x678
	// Line 1558, Address: 0x23ffbc, Func Offset: 0x67c
	// Line 1559, Address: 0x23ffc8, Func Offset: 0x688
	// Line 1560, Address: 0x23ffdc, Func Offset: 0x69c
	// Line 1561, Address: 0x23fff4, Func Offset: 0x6b4
	// Line 1562, Address: 0x24000c, Func Offset: 0x6cc
	// Line 1563, Address: 0x240024, Func Offset: 0x6e4
	// Line 1564, Address: 0x240038, Func Offset: 0x6f8
	// Line 1565, Address: 0x24004c, Func Offset: 0x70c
	// Line 1566, Address: 0x240060, Func Offset: 0x720
	// Line 1567, Address: 0x240074, Func Offset: 0x734
	// Line 1570, Address: 0x240088, Func Offset: 0x748
	// Line 1571, Address: 0x240094, Func Offset: 0x754
	// Line 1573, Address: 0x2400b4, Func Offset: 0x774
	// Line 1575, Address: 0x2400bc, Func Offset: 0x77c
	// Line 1576, Address: 0x2400c8, Func Offset: 0x788
	// Line 1588, Address: 0x2400cc, Func Offset: 0x78c
	// Line 1575, Address: 0x2400d0, Func Offset: 0x790
	// Line 1576, Address: 0x2400dc, Func Offset: 0x79c
	// Line 1577, Address: 0x2400f0, Func Offset: 0x7b0
	// Line 1578, Address: 0x240104, Func Offset: 0x7c4
	// Line 1579, Address: 0x24011c, Func Offset: 0x7dc
	// Line 1580, Address: 0x240134, Func Offset: 0x7f4
	// Line 1581, Address: 0x24014c, Func Offset: 0x80c
	// Line 1582, Address: 0x240164, Func Offset: 0x824
	// Line 1583, Address: 0x24017c, Func Offset: 0x83c
	// Line 1584, Address: 0x240194, Func Offset: 0x854
	// Line 1585, Address: 0x2401a8, Func Offset: 0x868
	// Line 1588, Address: 0x2401bc, Func Offset: 0x87c
	// Line 1589, Address: 0x2401e0, Func Offset: 0x8a0
	// Line 1592, Address: 0x240200, Func Offset: 0x8c0
	// Line 1594, Address: 0x240224, Func Offset: 0x8e4
	// Line 1596, Address: 0x24022c, Func Offset: 0x8ec
	// Line 1598, Address: 0x240248, Func Offset: 0x908
	// Line 1600, Address: 0x24024c, Func Offset: 0x90c
	// Line 1603, Address: 0x240250, Func Offset: 0x910
	// Line 1598, Address: 0x240258, Func Offset: 0x918
	// Line 1599, Address: 0x240260, Func Offset: 0x920
	// Line 1600, Address: 0x240264, Func Offset: 0x924
	// Line 1603, Address: 0x240268, Func Offset: 0x928
	// Line 1604, Address: 0x24026c, Func Offset: 0x92c
	// Line 1614, Address: 0x240270, Func Offset: 0x930
	// Line 1603, Address: 0x24027c, Func Offset: 0x93c
	// Line 1604, Address: 0x240288, Func Offset: 0x948
	// Line 1605, Address: 0x24029c, Func Offset: 0x95c
	// Line 1606, Address: 0x2402b0, Func Offset: 0x970
	// Line 1607, Address: 0x2402c8, Func Offset: 0x988
	// Line 1608, Address: 0x2402e0, Func Offset: 0x9a0
	// Line 1609, Address: 0x2402f8, Func Offset: 0x9b8
	// Line 1610, Address: 0x240310, Func Offset: 0x9d0
	// Line 1611, Address: 0x240328, Func Offset: 0x9e8
	// Line 1612, Address: 0x240340, Func Offset: 0xa00
	// Line 1613, Address: 0x240354, Func Offset: 0xa14
	// Line 1614, Address: 0x240368, Func Offset: 0xa28
	// Line 1617, Address: 0x240380, Func Offset: 0xa40
	// Line 1618, Address: 0x2403a8, Func Offset: 0xa68
	// Line 1625, Address: 0x2403c8, Func Offset: 0xa88
	// Line 1627, Address: 0x2403d4, Func Offset: 0xa94
	// Line 1625, Address: 0x2403dc, Func Offset: 0xa9c
	// Line 1627, Address: 0x2403e0, Func Offset: 0xaa0
	// Line 1625, Address: 0x2403e4, Func Offset: 0xaa4
	// Line 1626, Address: 0x2403f4, Func Offset: 0xab4
	// Line 1625, Address: 0x2403fc, Func Offset: 0xabc
	// Line 1627, Address: 0x240400, Func Offset: 0xac0
	// Line 1628, Address: 0x240430, Func Offset: 0xaf0
	// Line 1632, Address: 0x240434, Func Offset: 0xaf4
	// Line 1634, Address: 0x240444, Func Offset: 0xb04
	// Line 1635, Address: 0x240464, Func Offset: 0xb24
	// Line 1636, Address: 0x240478, Func Offset: 0xb38
	// Line 1638, Address: 0x24049c, Func Offset: 0xb5c
	// Func End, Address: 0x2404b0, Func Offset: 0xb70
	scePrintf("bhEff_E03_Acid - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2404b0
void bhEff_E03_Shadow(O_WRK* op)
{
	BH_PWORK* pp;
	// Line 1651, Address: 0x2404b0, Func Offset: 0
	// Line 1653, Address: 0x2404d0, Func Offset: 0x20
	// Line 1654, Address: 0x2404dc, Func Offset: 0x2c
	// Line 1653, Address: 0x2404e4, Func Offset: 0x34
	// Line 1654, Address: 0x2404ec, Func Offset: 0x3c
	// Line 1655, Address: 0x2404f8, Func Offset: 0x48
	// Line 1657, Address: 0x2404fc, Func Offset: 0x4c
	// Line 1659, Address: 0x240504, Func Offset: 0x54
	// Line 1661, Address: 0x240514, Func Offset: 0x64
	// Line 1663, Address: 0x24051c, Func Offset: 0x6c
	// Line 1666, Address: 0x24054c, Func Offset: 0x9c
	// Line 1667, Address: 0x240558, Func Offset: 0xa8
	// Line 1668, Address: 0x240560, Func Offset: 0xb0
	// Line 1669, Address: 0x24056c, Func Offset: 0xbc
	// Line 1668, Address: 0x240570, Func Offset: 0xc0
	// Line 1669, Address: 0x240578, Func Offset: 0xc8
	// Line 1673, Address: 0x2405ac, Func Offset: 0xfc
	// Func End, Address: 0x2405b4, Func Offset: 0x104
	scePrintf("bhEff_E03_Shadow - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2405c0
void bhEff_E05_Blood(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK* uvtble[2];
	// Line 1683, Address: 0x2405c0, Func Offset: 0
	// Line 1720, Address: 0x2405cc, Func Offset: 0xc
	// Line 1722, Address: 0x2405ec, Func Offset: 0x2c
	// Line 1723, Address: 0x2405f8, Func Offset: 0x38
	// Line 1724, Address: 0x240600, Func Offset: 0x40
	// Line 1725, Address: 0x240608, Func Offset: 0x48
	// Line 1726, Address: 0x24060c, Func Offset: 0x4c
	// Line 1727, Address: 0x240610, Func Offset: 0x50
	// Line 1732, Address: 0x240618, Func Offset: 0x58
	// Line 1727, Address: 0x24061c, Func Offset: 0x5c
	// Line 1728, Address: 0x240624, Func Offset: 0x64
	// Line 1729, Address: 0x240630, Func Offset: 0x70
	// Line 1730, Address: 0x240638, Func Offset: 0x78
	// Line 1731, Address: 0x240640, Func Offset: 0x80
	// Line 1732, Address: 0x240648, Func Offset: 0x88
	// Line 1734, Address: 0x24064c, Func Offset: 0x8c
	// Line 1735, Address: 0x24065c, Func Offset: 0x9c
	// Line 1734, Address: 0x240660, Func Offset: 0xa0
	// Line 1735, Address: 0x240674, Func Offset: 0xb4
	// Line 1737, Address: 0x240688, Func Offset: 0xc8
	// Line 1739, Address: 0x240690, Func Offset: 0xd0
	// Line 1742, Address: 0x240698, Func Offset: 0xd8
	// Line 1743, Address: 0x2406a8, Func Offset: 0xe8
	// Line 1745, Address: 0x2406b0, Func Offset: 0xf0
	// Line 1743, Address: 0x2406b4, Func Offset: 0xf4
	// Line 1745, Address: 0x2406bc, Func Offset: 0xfc
	// Line 1746, Address: 0x2406d8, Func Offset: 0x118
	// Line 1747, Address: 0x2406ec, Func Offset: 0x12c
	// Line 1750, Address: 0x240710, Func Offset: 0x150
	// Func End, Address: 0x240720, Func Offset: 0x160
	scePrintf("bhEff_E05_Blood - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x240720
void bhEff_E06_Rinpun(O_WRK* op)
{
	O_WRK* pp;
	int i;
	unsigned int col[3];
	//int i;
	NJS_POINT3* v;
	NJS_POINT3* p;
	//_anon6* pp;
	// Line 1760, Address: 0x240720, Func Offset: 0
	// Line 1765, Address: 0x240740, Func Offset: 0x20
	// Line 1760, Address: 0x240744, Func Offset: 0x24
	// Line 1765, Address: 0x240748, Func Offset: 0x28
	// Line 1760, Address: 0x24074c, Func Offset: 0x2c
	// Line 1765, Address: 0x240750, Func Offset: 0x30
	// Line 1771, Address: 0x240768, Func Offset: 0x48
	// Line 1774, Address: 0x240788, Func Offset: 0x68
	// Line 1775, Address: 0x240794, Func Offset: 0x74
	// Line 1777, Address: 0x24079c, Func Offset: 0x7c
	// Line 1781, Address: 0x2407a4, Func Offset: 0x84
	// Line 1780, Address: 0x2407a8, Func Offset: 0x88
	// Line 1782, Address: 0x2407ac, Func Offset: 0x8c
	// Line 1783, Address: 0x2407b0, Func Offset: 0x90
	// Line 1781, Address: 0x2407b4, Func Offset: 0x94
	// Line 1784, Address: 0x2407b8, Func Offset: 0x98
	// Line 1785, Address: 0x2407c0, Func Offset: 0xa0
	// Line 1786, Address: 0x240804, Func Offset: 0xe4
	// Line 1787, Address: 0x240848, Func Offset: 0x128
	// Line 1789, Address: 0x24088c, Func Offset: 0x16c
	// Line 1790, Address: 0x2408d8, Func Offset: 0x1b8
	// Line 1791, Address: 0x2408f0, Func Offset: 0x1d0
	// Line 1792, Address: 0x240908, Func Offset: 0x1e8
	// Line 1793, Address: 0x240914, Func Offset: 0x1f4
	// Line 1794, Address: 0x24095c, Func Offset: 0x23c
	// Line 1795, Address: 0x240964, Func Offset: 0x244
	// Line 1797, Address: 0x2409b0, Func Offset: 0x290
	// Line 1799, Address: 0x2409d0, Func Offset: 0x2b0
	// Line 1800, Address: 0x2409d8, Func Offset: 0x2b8
	// Line 1802, Address: 0x2409dc, Func Offset: 0x2bc
	// Line 1804, Address: 0x240a1c, Func Offset: 0x2fc
	// Line 1807, Address: 0x240a2c, Func Offset: 0x30c
	// Line 1804, Address: 0x240a30, Func Offset: 0x310
	// Line 1809, Address: 0x240a40, Func Offset: 0x320
	// Line 1811, Address: 0x240a84, Func Offset: 0x364
	// Line 1813, Address: 0x240a8c, Func Offset: 0x36c
	// Line 1814, Address: 0x240a90, Func Offset: 0x370
	// Line 1811, Address: 0x240a94, Func Offset: 0x374
	// Line 1812, Address: 0x240a9c, Func Offset: 0x37c
	// Line 1817, Address: 0x240aa0, Func Offset: 0x380
	// Line 1812, Address: 0x240aa8, Func Offset: 0x388
	// Line 1813, Address: 0x240ab0, Func Offset: 0x390
	// Line 1814, Address: 0x240ab4, Func Offset: 0x394
	// Line 1817, Address: 0x240ab8, Func Offset: 0x398
	// Line 1818, Address: 0x240abc, Func Offset: 0x39c
	// Line 1819, Address: 0x240ac4, Func Offset: 0x3a4
	// Line 1821, Address: 0x240acc, Func Offset: 0x3ac
	// Line 1824, Address: 0x240ad0, Func Offset: 0x3b0
	// Line 1822, Address: 0x240ad4, Func Offset: 0x3b4
	// Line 1824, Address: 0x240ad8, Func Offset: 0x3b8
	// Line 1825, Address: 0x240ae0, Func Offset: 0x3c0
	// Line 1826, Address: 0x240b38, Func Offset: 0x418
	// Line 1827, Address: 0x240b90, Func Offset: 0x470
	// Line 1829, Address: 0x240bc0, Func Offset: 0x4a0
	// Line 1827, Address: 0x240bc4, Func Offset: 0x4a4
	// Line 1829, Address: 0x240bc8, Func Offset: 0x4a8
	// Line 1831, Address: 0x240bcc, Func Offset: 0x4ac
	// Line 1827, Address: 0x240bd0, Func Offset: 0x4b0
	// Line 1831, Address: 0x240bdc, Func Offset: 0x4bc
	// Line 1832, Address: 0x240be0, Func Offset: 0x4c0
	// Line 1827, Address: 0x240be8, Func Offset: 0x4c8
	// Line 1829, Address: 0x240bec, Func Offset: 0x4cc
	// Line 1827, Address: 0x240bf4, Func Offset: 0x4d4
	// Line 1829, Address: 0x240c04, Func Offset: 0x4e4
	// Line 1831, Address: 0x240c08, Func Offset: 0x4e8
	// Line 1832, Address: 0x240c0c, Func Offset: 0x4ec
	// Line 1829, Address: 0x240c10, Func Offset: 0x4f0
	// Line 1830, Address: 0x240c18, Func Offset: 0x4f8
	// Line 1831, Address: 0x240c24, Func Offset: 0x504
	// Line 1832, Address: 0x240c2c, Func Offset: 0x50c
	// Line 1834, Address: 0x240c40, Func Offset: 0x520
	// Line 1835, Address: 0x240c44, Func Offset: 0x524
	// Line 1836, Address: 0x240c48, Func Offset: 0x528
	// Line 1837, Address: 0x240c4c, Func Offset: 0x52c
	// Line 1834, Address: 0x240c54, Func Offset: 0x534
	// Line 1837, Address: 0x240c58, Func Offset: 0x538
	// Line 1835, Address: 0x240c5c, Func Offset: 0x53c
	// Line 1836, Address: 0x240c60, Func Offset: 0x540
	// Line 1837, Address: 0x240c64, Func Offset: 0x544
	// Line 1839, Address: 0x240c78, Func Offset: 0x558
	// Line 1847, Address: 0x240c7c, Func Offset: 0x55c
	// Line 1839, Address: 0x240c80, Func Offset: 0x560
	// Line 1848, Address: 0x240c84, Func Offset: 0x564
	// Line 1839, Address: 0x240c8c, Func Offset: 0x56c
	// Line 1840, Address: 0x240c90, Func Offset: 0x570
	// Line 1844, Address: 0x240c94, Func Offset: 0x574
	// Line 1841, Address: 0x240c98, Func Offset: 0x578
	// Line 1845, Address: 0x240c9c, Func Offset: 0x57c
	// Line 1846, Address: 0x240ca0, Func Offset: 0x580
	// Line 1847, Address: 0x240ca4, Func Offset: 0x584
	// Line 1848, Address: 0x240ca8, Func Offset: 0x588
	// Line 1849, Address: 0x240cbc, Func Offset: 0x59c
	// Line 1851, Address: 0x240cf4, Func Offset: 0x5d4
	// Line 1853, Address: 0x240cfc, Func Offset: 0x5dc
	// Line 1854, Address: 0x240d08, Func Offset: 0x5e8
	// Line 1853, Address: 0x240d0c, Func Offset: 0x5ec
	// Line 1854, Address: 0x240d14, Func Offset: 0x5f4
	// Line 1855, Address: 0x240d2c, Func Offset: 0x60c
	// Line 1856, Address: 0x240d74, Func Offset: 0x654
	// Line 1862, Address: 0x240d8c, Func Offset: 0x66c
	// Line 1863, Address: 0x240d94, Func Offset: 0x674
	// Line 1864, Address: 0x240d98, Func Offset: 0x678
	// Line 1865, Address: 0x240db8, Func Offset: 0x698
	// Line 1866, Address: 0x240dbc, Func Offset: 0x69c
	// Line 1867, Address: 0x240dc0, Func Offset: 0x6a0
	// Line 1873, Address: 0x240dd0, Func Offset: 0x6b0
	// Line 1874, Address: 0x240e1c, Func Offset: 0x6fc
	// Line 1876, Address: 0x240e2c, Func Offset: 0x70c
	// Line 1877, Address: 0x240e74, Func Offset: 0x754
	// Line 1878, Address: 0x240e84, Func Offset: 0x764
	// Line 1881, Address: 0x240e8c, Func Offset: 0x76c
	// Line 1883, Address: 0x240e9c, Func Offset: 0x77c
	// Line 1884, Address: 0x240ea8, Func Offset: 0x788
	// Line 1889, Address: 0x240ec0, Func Offset: 0x7a0
	// Line 1890, Address: 0x240ed0, Func Offset: 0x7b0
	// Line 1892, Address: 0x240ed4, Func Offset: 0x7b4
	// Line 1895, Address: 0x240edc, Func Offset: 0x7bc
	// Line 1896, Address: 0x240efc, Func Offset: 0x7dc
	// Line 1897, Address: 0x240f10, Func Offset: 0x7f0
	// Line 1900, Address: 0x240f34, Func Offset: 0x814
	// Func End, Address: 0x240f60, Func Offset: 0x840
	scePrintf("bhEff_E06_Rinpun - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x240f60
void bhEff_E11_SearchLight(O_WRK* op)
{
	// Line 1910, Address: 0x240f60, Func Offset: 0
	// Line 1919, Address: 0x240f6c, Func Offset: 0xc
	// Line 1921, Address: 0x240fac, Func Offset: 0x4c
	// Line 1922, Address: 0x240fb0, Func Offset: 0x50
	// Line 1925, Address: 0x240fb4, Func Offset: 0x54
	// Line 1923, Address: 0x240fb8, Func Offset: 0x58
	// Line 1925, Address: 0x240fbc, Func Offset: 0x5c
	// Line 1924, Address: 0x240fc0, Func Offset: 0x60
	// Line 1925, Address: 0x240fc4, Func Offset: 0x64
	// Line 1926, Address: 0x240fc8, Func Offset: 0x68
	// Line 1929, Address: 0x240fcc, Func Offset: 0x6c
	// Line 1930, Address: 0x240fd8, Func Offset: 0x78
	// Line 1932, Address: 0x240fe0, Func Offset: 0x80
	// Line 1935, Address: 0x240fe8, Func Offset: 0x88
	// Line 1936, Address: 0x241000, Func Offset: 0xa0
	// Line 1938, Address: 0x24100c, Func Offset: 0xac
	// Line 1939, Address: 0x24102c, Func Offset: 0xcc
	// Line 1940, Address: 0x241034, Func Offset: 0xd4
	// Line 1942, Address: 0x24103c, Func Offset: 0xdc
	// Line 1943, Address: 0x241040, Func Offset: 0xe0
	// Line 1945, Address: 0x241048, Func Offset: 0xe8
	// Line 1946, Address: 0x241054, Func Offset: 0xf4
	// Line 1947, Address: 0x24105c, Func Offset: 0xfc
	// Line 1948, Address: 0x241064, Func Offset: 0x104
	// Line 1950, Address: 0x24106c, Func Offset: 0x10c
	// Line 1952, Address: 0x241074, Func Offset: 0x114
	// Line 1953, Address: 0x241080, Func Offset: 0x120
	// Line 1954, Address: 0x24108c, Func Offset: 0x12c
	// Line 1955, Address: 0x241090, Func Offset: 0x130
	// Line 1957, Address: 0x241094, Func Offset: 0x134
	// Line 1958, Address: 0x2410a4, Func Offset: 0x144
	// Line 1965, Address: 0x2410b0, Func Offset: 0x150
	// Line 1966, Address: 0x2410e0, Func Offset: 0x180
	// Line 1967, Address: 0x241110, Func Offset: 0x1b0
	// Line 1969, Address: 0x241120, Func Offset: 0x1c0
	// Line 1967, Address: 0x241124, Func Offset: 0x1c4
	// Line 1969, Address: 0x24113c, Func Offset: 0x1dc
	// Line 1970, Address: 0x241158, Func Offset: 0x1f8
	// Line 1971, Address: 0x24116c, Func Offset: 0x20c
	// Line 1973, Address: 0x241190, Func Offset: 0x230
	// Func End, Address: 0x2411a0, Func Offset: 0x240
	scePrintf("bhEff_E11_SearchLight - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2411a0
void bhEff_E11_SearchLightDraw(O_WRK* op)
{
	float rate;
	int id2;
	int id1;
	//_anon27 c[2];
	NJS_POINT3 p[2];
	//_anon44 p3c;
	//_anon44 p3c;
	NJS_POINT3 area[3];
	//_anon27 c[3];
	//NJS_POINT3* p;
	int i;
	float mtx[16];
	char atr[192];
	//float rate[16];
	NJS_POINT3 n;
	NJS_POINT3 pos;
	NJS_POINT3* pt;
	NJS_POINT3 p1;
	// Line 1985, Address: 0x2411a0, Func Offset: 0
	// Line 1996, Address: 0x2411d4, Func Offset: 0x34
	// Line 2008, Address: 0x2411d8, Func Offset: 0x38
	// Line 1996, Address: 0x2411e8, Func Offset: 0x48
	// Line 1997, Address: 0x2411f4, Func Offset: 0x54
	// Line 1998, Address: 0x2411f8, Func Offset: 0x58
	// Line 1996, Address: 0x2411fc, Func Offset: 0x5c
	// Line 1997, Address: 0x241200, Func Offset: 0x60
	// Line 1998, Address: 0x241204, Func Offset: 0x64
	// Line 1999, Address: 0x24120c, Func Offset: 0x6c
	// Line 2003, Address: 0x241218, Func Offset: 0x78
	// Line 2007, Address: 0x241220, Func Offset: 0x80
	// Line 2009, Address: 0x241224, Func Offset: 0x84
	// Line 2010, Address: 0x241284, Func Offset: 0xe4
	// Line 2009, Address: 0x24128c, Func Offset: 0xec
	// Line 2010, Address: 0x241290, Func Offset: 0xf0
	// Line 2011, Address: 0x2412cc, Func Offset: 0x12c
	// Line 2016, Address: 0x2412d0, Func Offset: 0x130
	// Line 2017, Address: 0x2412d4, Func Offset: 0x134
	// Line 2010, Address: 0x2412d8, Func Offset: 0x138
	// Line 2011, Address: 0x2412e0, Func Offset: 0x140
	// Line 2014, Address: 0x2412e4, Func Offset: 0x144
	// Line 2015, Address: 0x2412ec, Func Offset: 0x14c
	// Line 2017, Address: 0x2412f4, Func Offset: 0x154
	// Line 2018, Address: 0x2412fc, Func Offset: 0x15c
	// Line 2019, Address: 0x24130c, Func Offset: 0x16c
	// Line 2021, Address: 0x241320, Func Offset: 0x180
	// Line 2024, Address: 0x24133c, Func Offset: 0x19c
	// Line 2025, Address: 0x241350, Func Offset: 0x1b0
	// Line 2026, Address: 0x241368, Func Offset: 0x1c8
	// Line 2027, Address: 0x241390, Func Offset: 0x1f0
	// Line 2028, Address: 0x241394, Func Offset: 0x1f4
	// Line 2030, Address: 0x24139c, Func Offset: 0x1fc
	// Line 2031, Address: 0x2413b4, Func Offset: 0x214
	// Line 2030, Address: 0x2413bc, Func Offset: 0x21c
	// Line 2031, Address: 0x2413c0, Func Offset: 0x220
	// Line 2032, Address: 0x2413d0, Func Offset: 0x230
	// Line 2033, Address: 0x2413e8, Func Offset: 0x248
	// Line 2034, Address: 0x241410, Func Offset: 0x270
	// Line 2037, Address: 0x241418, Func Offset: 0x278
	// Line 2039, Address: 0x241430, Func Offset: 0x290
	// Line 2040, Address: 0x241440, Func Offset: 0x2a0
	// Line 2041, Address: 0x241454, Func Offset: 0x2b4
	// Line 2042, Address: 0x24146c, Func Offset: 0x2cc
	// Line 2043, Address: 0x24147c, Func Offset: 0x2dc
	// Line 2046, Address: 0x241484, Func Offset: 0x2e4
	// Line 2047, Address: 0x241488, Func Offset: 0x2e8
	// Line 2043, Address: 0x241490, Func Offset: 0x2f0
	// Line 2047, Address: 0x241498, Func Offset: 0x2f8
	// Line 2051, Address: 0x2414a0, Func Offset: 0x300
	// Line 2052, Address: 0x2414a8, Func Offset: 0x308
	// Line 2053, Address: 0x2414b4, Func Offset: 0x314
	// Line 2054, Address: 0x2414c0, Func Offset: 0x320
	// Line 2056, Address: 0x2414c8, Func Offset: 0x328
	// Line 2064, Address: 0x2414d8, Func Offset: 0x338
	// Line 2065, Address: 0x2414e0, Func Offset: 0x340
	// Line 2067, Address: 0x2414e8, Func Offset: 0x348
	// Line 2066, Address: 0x2414ec, Func Offset: 0x34c
	// Line 2067, Address: 0x2414f0, Func Offset: 0x350
	// Line 2069, Address: 0x2414f4, Func Offset: 0x354
	// Line 2070, Address: 0x241500, Func Offset: 0x360
	// Line 2071, Address: 0x241528, Func Offset: 0x388
	// Line 2072, Address: 0x241538, Func Offset: 0x398
	// Line 2073, Address: 0x24153c, Func Offset: 0x39c
	// Line 2074, Address: 0x241540, Func Offset: 0x3a0
	// Line 2075, Address: 0x24154c, Func Offset: 0x3ac
	// Line 2077, Address: 0x241550, Func Offset: 0x3b0
	// Line 2078, Address: 0x241558, Func Offset: 0x3b8
	// Line 2079, Address: 0x241580, Func Offset: 0x3e0
	// Line 2080, Address: 0x2415a4, Func Offset: 0x404
	// Line 2081, Address: 0x2415c8, Func Offset: 0x428
	// Line 2082, Address: 0x2415cc, Func Offset: 0x42c
	// Line 2081, Address: 0x2415d8, Func Offset: 0x438
	// Line 2082, Address: 0x2415dc, Func Offset: 0x43c
	// Line 2083, Address: 0x2415f0, Func Offset: 0x450
	// Line 2084, Address: 0x241614, Func Offset: 0x474
	// Line 2086, Address: 0x24161c, Func Offset: 0x47c
	// Line 2091, Address: 0x241624, Func Offset: 0x484
	// Line 2086, Address: 0x24162c, Func Offset: 0x48c
	// Line 2088, Address: 0x241634, Func Offset: 0x494
	// Line 2089, Address: 0x241638, Func Offset: 0x498
	// Line 2088, Address: 0x24163c, Func Offset: 0x49c
	// Line 2089, Address: 0x241640, Func Offset: 0x4a0
	// Line 2090, Address: 0x241644, Func Offset: 0x4a4
	// Line 2089, Address: 0x241648, Func Offset: 0x4a8
	// Line 2090, Address: 0x24164c, Func Offset: 0x4ac
	// Line 2092, Address: 0x241654, Func Offset: 0x4b4
	// Line 2094, Address: 0x241664, Func Offset: 0x4c4
	// Line 2093, Address: 0x24166c, Func Offset: 0x4cc
	// Line 2092, Address: 0x241670, Func Offset: 0x4d0
	// Line 2093, Address: 0x24167c, Func Offset: 0x4dc
	// Line 2094, Address: 0x241688, Func Offset: 0x4e8
	// Line 2093, Address: 0x241690, Func Offset: 0x4f0
	// Line 2094, Address: 0x24169c, Func Offset: 0x4fc
	// Line 2095, Address: 0x2416bc, Func Offset: 0x51c
	// Line 2096, Address: 0x2416e8, Func Offset: 0x548
	// Line 2097, Address: 0x2416fc, Func Offset: 0x55c
	// Line 2096, Address: 0x241704, Func Offset: 0x564
	// Line 2097, Address: 0x241708, Func Offset: 0x568
	// Line 2098, Address: 0x241710, Func Offset: 0x570
	// Line 2100, Address: 0x24172c, Func Offset: 0x58c
	// Line 2098, Address: 0x241734, Func Offset: 0x594
	// Line 2099, Address: 0x241740, Func Offset: 0x5a0
	// Line 2100, Address: 0x24174c, Func Offset: 0x5ac
	// Line 2099, Address: 0x24175c, Func Offset: 0x5bc
	// Line 2100, Address: 0x241768, Func Offset: 0x5c8
	// Line 2101, Address: 0x241784, Func Offset: 0x5e4
	// Line 2102, Address: 0x2417ac, Func Offset: 0x60c
	// Line 2113, Address: 0x2417c0, Func Offset: 0x620
	// Line 2121, Address: 0x2417c4, Func Offset: 0x624
	// Line 2113, Address: 0x2417c8, Func Offset: 0x628
	// Line 2114, Address: 0x2417cc, Func Offset: 0x62c
	// Line 2116, Address: 0x2417d4, Func Offset: 0x634
	// Line 2115, Address: 0x2417d8, Func Offset: 0x638
	// Line 2116, Address: 0x2417dc, Func Offset: 0x63c
	// Line 2120, Address: 0x2417e0, Func Offset: 0x640
	// Line 2118, Address: 0x2417e4, Func Offset: 0x644
	// Line 2120, Address: 0x2417e8, Func Offset: 0x648
	// Line 2124, Address: 0x2417ec, Func Offset: 0x64c
	// Line 2121, Address: 0x2417f8, Func Offset: 0x658
	// Line 2122, Address: 0x2417fc, Func Offset: 0x65c
	// Line 2125, Address: 0x241804, Func Offset: 0x664
	// Line 2126, Address: 0x241808, Func Offset: 0x668
	// Line 2118, Address: 0x24180c, Func Offset: 0x66c
	// Line 2120, Address: 0x241814, Func Offset: 0x674
	// Line 2122, Address: 0x24181c, Func Offset: 0x67c
	// Line 2120, Address: 0x241820, Func Offset: 0x680
	// Line 2119, Address: 0x241824, Func Offset: 0x684
	// Line 2123, Address: 0x24182c, Func Offset: 0x68c
	// Line 2120, Address: 0x241830, Func Offset: 0x690
	// Line 2123, Address: 0x241834, Func Offset: 0x694
	// Line 2124, Address: 0x241838, Func Offset: 0x698
	// Line 2123, Address: 0x241854, Func Offset: 0x6b4
	// Line 2124, Address: 0x241858, Func Offset: 0x6b8
	// Line 2128, Address: 0x241860, Func Offset: 0x6c0
	// Line 2124, Address: 0x241864, Func Offset: 0x6c4
	// Line 2125, Address: 0x241878, Func Offset: 0x6d8
	// Line 2128, Address: 0x241880, Func Offset: 0x6e0
	// Line 2125, Address: 0x241884, Func Offset: 0x6e4
	// Line 2126, Address: 0x241890, Func Offset: 0x6f0
	// Line 2128, Address: 0x2418a4, Func Offset: 0x704
	// Line 2129, Address: 0x2418b4, Func Offset: 0x714
	// Line 2132, Address: 0x2418b8, Func Offset: 0x718
	// Line 2130, Address: 0x2418c0, Func Offset: 0x720
	// Line 2129, Address: 0x2418c4, Func Offset: 0x724
	// Line 2130, Address: 0x2418cc, Func Offset: 0x72c
	// Line 2131, Address: 0x2418dc, Func Offset: 0x73c
	// Line 2132, Address: 0x2418e0, Func Offset: 0x740
	// Line 2133, Address: 0x2418f0, Func Offset: 0x750
	// Line 2134, Address: 0x2418f4, Func Offset: 0x754
	// Line 2140, Address: 0x2418f8, Func Offset: 0x758
	// Line 2133, Address: 0x241900, Func Offset: 0x760
	// Line 2134, Address: 0x241908, Func Offset: 0x768
	// Line 2140, Address: 0x241918, Func Offset: 0x778
	// Line 2144, Address: 0x241920, Func Offset: 0x780
	// Line 2153, Address: 0x241924, Func Offset: 0x784
	// Line 2144, Address: 0x241930, Func Offset: 0x790
	// Line 2146, Address: 0x24193c, Func Offset: 0x79c
	// Line 2147, Address: 0x241978, Func Offset: 0x7d8
	// Line 2148, Address: 0x24198c, Func Offset: 0x7ec
	// Line 2153, Address: 0x24199c, Func Offset: 0x7fc
	// Line 2158, Address: 0x2419a4, Func Offset: 0x804
	// Line 2159, Address: 0x2419ac, Func Offset: 0x80c
	// Line 2160, Address: 0x2419c4, Func Offset: 0x824
	// Line 2161, Address: 0x2419cc, Func Offset: 0x82c
	// Func End, Address: 0x241a04, Func Offset: 0x864
	scePrintf("bhEff_E11_SearchLightDraw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x241a10
int bhEff_E11_CheckCollisionPlayer(NJS_POINT3* p1, NJS_POINT3* p2)
{
	BH_PWORK* ep;
	//npobj* pObj;
	int ret;
	int j;
	int i;
	int num;
	//_anon12* mtn;
	// Line 2353, Address: 0x241a10, Func Offset: 0
	// Line 2360, Address: 0x241a3c, Func Offset: 0x2c
	// Line 2355, Address: 0x241a44, Func Offset: 0x34
	// Line 2360, Address: 0x241a4c, Func Offset: 0x3c
	// Line 2362, Address: 0x241a50, Func Offset: 0x40
	// Line 2360, Address: 0x241a54, Func Offset: 0x44
	// Line 2361, Address: 0x241a58, Func Offset: 0x48
	// Line 2363, Address: 0x241a5c, Func Offset: 0x4c
	// Line 2364, Address: 0x241a64, Func Offset: 0x54
	// Line 2365, Address: 0x241a70, Func Offset: 0x60
	// Line 2366, Address: 0x241a7c, Func Offset: 0x6c
	// Line 2367, Address: 0x241a94, Func Offset: 0x84
	// Line 2371, Address: 0x241a98, Func Offset: 0x88
	// Line 2369, Address: 0x241a9c, Func Offset: 0x8c
	// Line 2371, Address: 0x241aa0, Func Offset: 0x90
	// Line 2372, Address: 0x241aac, Func Offset: 0x9c
	// Line 2375, Address: 0x241ab0, Func Offset: 0xa0
	// Line 2376, Address: 0x241ab8, Func Offset: 0xa8
	// Line 2377, Address: 0x241ac0, Func Offset: 0xb0
	// Line 2378, Address: 0x241ad0, Func Offset: 0xc0
	// Line 2380, Address: 0x241b08, Func Offset: 0xf8
	// Line 2382, Address: 0x241b0c, Func Offset: 0xfc
	// Line 2381, Address: 0x241b10, Func Offset: 0x100
	// Line 2383, Address: 0x241b14, Func Offset: 0x104
	// Line 2384, Address: 0x241b1c, Func Offset: 0x10c
	// Line 2385, Address: 0x241b28, Func Offset: 0x118
	// Line 2386, Address: 0x241b34, Func Offset: 0x124
	// Line 2387, Address: 0x241b4c, Func Offset: 0x13c
	// Line 2391, Address: 0x241b50, Func Offset: 0x140
	// Line 2389, Address: 0x241b54, Func Offset: 0x144
	// Line 2391, Address: 0x241b58, Func Offset: 0x148
	// Line 2394, Address: 0x241b64, Func Offset: 0x154
	// Line 2395, Address: 0x241b68, Func Offset: 0x158
	// Line 2397, Address: 0x241b90, Func Offset: 0x180
	// Line 2398, Address: 0x241b94, Func Offset: 0x184
	// Func End, Address: 0x241bc4, Func Offset: 0x1b4
	scePrintf("bhEff_E11_CheckCollisionPlayer - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x241bd0
void bhEff_E16_LaserSight(O_WRK* op)
{
	// Line 2409, Address: 0x241bd0, Func Offset: 0
	// Line 2411, Address: 0x241be8, Func Offset: 0x18
	// Line 2414, Address: 0x241bf0, Func Offset: 0x20
	// Line 2416, Address: 0x241c10, Func Offset: 0x40
	// Line 2417, Address: 0x241c18, Func Offset: 0x48
	// Line 2419, Address: 0x241c20, Func Offset: 0x50
	// Line 2423, Address: 0x241c28, Func Offset: 0x58
	// Line 2427, Address: 0x241c38, Func Offset: 0x68
	// Line 2428, Address: 0x241c54, Func Offset: 0x84
	// Line 2429, Address: 0x241c68, Func Offset: 0x98
	// Line 2431, Address: 0x241c8c, Func Offset: 0xbc
	// Func End, Address: 0x241c94, Func Offset: 0xc4
	scePrintf("bhEff_E16_LaserSight - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x241ca0
void bhEff_E16_LaserSightDraw(O_WRK* op)
{
	//_anon45 p3c;
	NJS_POINT3 area[3];
	//_anon27 c[3];
	//_anon27 c[2];
	NJS_POINT3 p[2];
	//_anon45 p3c;
	//_anon39* p;
	BH_PWORK* ep;
	NJS_POINT3* effp;
	int num;
	float mtx[16];
	int i;
	char atr[192];
	float len;
	float rate[16];
	//_anon39 n[16];
	//_anon39 pos;
	//_anon39 pw;
	//_anon39 pt[16];
	//_anon39 p1;
	// Line 2443, Address: 0x241ca0, Func Offset: 0
	// Line 2456, Address: 0x241cd4, Func Offset: 0x34
	// Line 2464, Address: 0x241cdc, Func Offset: 0x3c
	// Line 2456, Address: 0x241ce0, Func Offset: 0x40
	// Line 2464, Address: 0x241ce8, Func Offset: 0x48
	// Line 2456, Address: 0x241cec, Func Offset: 0x4c
	// Line 2457, Address: 0x241d00, Func Offset: 0x60
	// Line 2465, Address: 0x241d04, Func Offset: 0x64
	// Line 2456, Address: 0x241d08, Func Offset: 0x68
	// Line 2458, Address: 0x241d0c, Func Offset: 0x6c
	// Line 2457, Address: 0x241d10, Func Offset: 0x70
	// Line 2458, Address: 0x241d14, Func Offset: 0x74
	// Line 2465, Address: 0x241d18, Func Offset: 0x78
	// Line 2458, Address: 0x241d20, Func Offset: 0x80
	// Line 2459, Address: 0x241d24, Func Offset: 0x84
	// Line 2463, Address: 0x241d30, Func Offset: 0x90
	// Line 2462, Address: 0x241d34, Func Offset: 0x94
	// Line 2463, Address: 0x241d38, Func Offset: 0x98
	// Line 2464, Address: 0x241d3c, Func Offset: 0x9c
	// Line 2465, Address: 0x241d40, Func Offset: 0xa0
	// Line 2467, Address: 0x241d48, Func Offset: 0xa8
	// Line 2469, Address: 0x241d60, Func Offset: 0xc0
	// Line 2471, Address: 0x241d78, Func Offset: 0xd8
	// Line 2472, Address: 0x241d7c, Func Offset: 0xdc
	// Line 2476, Address: 0x241d80, Func Offset: 0xe0
	// Line 2471, Address: 0x241d88, Func Offset: 0xe8
	// Line 2472, Address: 0x241d8c, Func Offset: 0xec
	// Line 2473, Address: 0x241d90, Func Offset: 0xf0
	// Line 2472, Address: 0x241d94, Func Offset: 0xf4
	// Line 2473, Address: 0x241d98, Func Offset: 0xf8
	// Line 2476, Address: 0x241d9c, Func Offset: 0xfc
	// Line 2479, Address: 0x241da8, Func Offset: 0x108
	// Line 2480, Address: 0x241dac, Func Offset: 0x10c
	// Line 2479, Address: 0x241db0, Func Offset: 0x110
	// Line 2480, Address: 0x241db4, Func Offset: 0x114
	// Line 2481, Address: 0x241db8, Func Offset: 0x118
	// Line 2480, Address: 0x241dbc, Func Offset: 0x11c
	// Line 2481, Address: 0x241dc0, Func Offset: 0x120
	// Line 2483, Address: 0x241dc8, Func Offset: 0x128
	// Line 2484, Address: 0x241dd4, Func Offset: 0x134
	// Line 2486, Address: 0x241ddc, Func Offset: 0x13c
	// Line 2487, Address: 0x241de0, Func Offset: 0x140
	// Line 2486, Address: 0x241de4, Func Offset: 0x144
	// Line 2487, Address: 0x241de8, Func Offset: 0x148
	// Line 2488, Address: 0x241df0, Func Offset: 0x150
	// Line 2515, Address: 0x241dfc, Func Offset: 0x15c
	// Line 2519, Address: 0x241e08, Func Offset: 0x168
	// Line 2518, Address: 0x241e10, Func Offset: 0x170
	// Line 2519, Address: 0x241e14, Func Offset: 0x174
	// Line 2520, Address: 0x241e24, Func Offset: 0x184
	// Line 2521, Address: 0x241e64, Func Offset: 0x1c4
	// Line 2520, Address: 0x241e68, Func Offset: 0x1c8
	// Line 2521, Address: 0x241e6c, Func Offset: 0x1cc
	// Line 2523, Address: 0x241e90, Func Offset: 0x1f0
	// Line 2521, Address: 0x241e9c, Func Offset: 0x1fc
	// Line 2523, Address: 0x241ea0, Func Offset: 0x200
	// Line 2526, Address: 0x241ea8, Func Offset: 0x208
	// Line 2529, Address: 0x241eac, Func Offset: 0x20c
	// Line 2526, Address: 0x241eb0, Func Offset: 0x210
	// Line 2527, Address: 0x241eb4, Func Offset: 0x214
	// Line 2529, Address: 0x241ebc, Func Offset: 0x21c
	// Line 2530, Address: 0x241ec4, Func Offset: 0x224
	// Line 2531, Address: 0x241ed4, Func Offset: 0x234
	// Line 2533, Address: 0x241ee8, Func Offset: 0x248
	// Line 2535, Address: 0x241f04, Func Offset: 0x264
	// Line 2537, Address: 0x241f0c, Func Offset: 0x26c
	// Line 2538, Address: 0x241f24, Func Offset: 0x284
	// Line 2537, Address: 0x241f2c, Func Offset: 0x28c
	// Line 2538, Address: 0x241f30, Func Offset: 0x290
	// Line 2539, Address: 0x241f40, Func Offset: 0x2a0
	// Line 2540, Address: 0x241f58, Func Offset: 0x2b8
	// Line 2542, Address: 0x241f80, Func Offset: 0x2e0
	// Line 2544, Address: 0x241f88, Func Offset: 0x2e8
	// Line 2542, Address: 0x241f90, Func Offset: 0x2f0
	// Line 2544, Address: 0x241f9c, Func Offset: 0x2fc
	// Line 2548, Address: 0x241fa4, Func Offset: 0x304
	// Line 2549, Address: 0x241fac, Func Offset: 0x30c
	// Line 2550, Address: 0x241fb8, Func Offset: 0x318
	// Line 2551, Address: 0x241fc4, Func Offset: 0x324
	// Line 2553, Address: 0x241fcc, Func Offset: 0x32c
	// Line 2561, Address: 0x241fdc, Func Offset: 0x33c
	// Line 2566, Address: 0x241fe0, Func Offset: 0x340
	// Line 2561, Address: 0x241fe4, Func Offset: 0x344
	// Line 2562, Address: 0x241fe8, Func Offset: 0x348
	// Line 2569, Address: 0x241fec, Func Offset: 0x34c
	// Line 2562, Address: 0x241ff0, Func Offset: 0x350
	// Line 2564, Address: 0x241ff4, Func Offset: 0x354
	// Line 2563, Address: 0x241ff8, Func Offset: 0x358
	// Line 2564, Address: 0x241ffc, Func Offset: 0x35c
	// Line 2567, Address: 0x242000, Func Offset: 0x360
	// Line 2566, Address: 0x242004, Func Offset: 0x364
	// Line 2567, Address: 0x242008, Func Offset: 0x368
	// Line 2569, Address: 0x24200c, Func Offset: 0x36c
	// Line 2570, Address: 0x242010, Func Offset: 0x370
	// Line 2571, Address: 0x242014, Func Offset: 0x374
	// Line 2568, Address: 0x242018, Func Offset: 0x378
	// Line 2567, Address: 0x24201c, Func Offset: 0x37c
	// Line 2568, Address: 0x242020, Func Offset: 0x380
	// Line 2573, Address: 0x242024, Func Offset: 0x384
	// Line 2577, Address: 0x242028, Func Offset: 0x388
	// Line 2585, Address: 0x24202c, Func Offset: 0x38c
	// Line 2568, Address: 0x242030, Func Offset: 0x390
	// Line 2570, Address: 0x242034, Func Offset: 0x394
	// Line 2569, Address: 0x242038, Func Offset: 0x398
	// Line 2570, Address: 0x24203c, Func Offset: 0x39c
	// Line 2585, Address: 0x242040, Func Offset: 0x3a0
	// Line 2571, Address: 0x242044, Func Offset: 0x3a4
	// Line 2570, Address: 0x242048, Func Offset: 0x3a8
	// Line 2571, Address: 0x24204c, Func Offset: 0x3ac
	// Line 2573, Address: 0x242050, Func Offset: 0x3b0
	// Line 2571, Address: 0x242054, Func Offset: 0x3b4
	// Line 2573, Address: 0x242058, Func Offset: 0x3b8
	// Line 2574, Address: 0x24205c, Func Offset: 0x3bc
	// Line 2575, Address: 0x242060, Func Offset: 0x3c0
	// Line 2577, Address: 0x242064, Func Offset: 0x3c4
	// Line 2576, Address: 0x242068, Func Offset: 0x3c8
	// Line 2577, Address: 0x24206c, Func Offset: 0x3cc
	// Line 2578, Address: 0x242070, Func Offset: 0x3d0
	// Line 2579, Address: 0x242074, Func Offset: 0x3d4
	// Line 2585, Address: 0x242078, Func Offset: 0x3d8
	// Line 2588, Address: 0x242080, Func Offset: 0x3e0
	// Line 2589, Address: 0x242084, Func Offset: 0x3e4
	// Line 2590, Address: 0x242090, Func Offset: 0x3f0
	// Line 2591, Address: 0x242098, Func Offset: 0x3f8
	// Line 2592, Address: 0x2420a4, Func Offset: 0x404
	// Line 2591, Address: 0x2420a8, Func Offset: 0x408
	// Line 2592, Address: 0x2420ac, Func Offset: 0x40c
	// Line 2593, Address: 0x2420bc, Func Offset: 0x41c
	// Line 2595, Address: 0x2420d4, Func Offset: 0x434
	// Line 2601, Address: 0x2420d8, Func Offset: 0x438
	// Line 2595, Address: 0x2420e4, Func Offset: 0x444
	// Line 2596, Address: 0x2420e8, Func Offset: 0x448
	// Line 2597, Address: 0x2420f0, Func Offset: 0x450
	// Line 2601, Address: 0x2420f4, Func Offset: 0x454
	// Line 2603, Address: 0x242100, Func Offset: 0x460
	// Line 2604, Address: 0x242114, Func Offset: 0x474
	// Line 2613, Address: 0x242118, Func Offset: 0x478
	// Line 2623, Address: 0x24211c, Func Offset: 0x47c
	// Line 2613, Address: 0x242120, Func Offset: 0x480
	// Line 2614, Address: 0x242124, Func Offset: 0x484
	// Line 2616, Address: 0x24212c, Func Offset: 0x48c
	// Line 2618, Address: 0x242130, Func Offset: 0x490
	// Line 2615, Address: 0x242134, Func Offset: 0x494
	// Line 2619, Address: 0x242138, Func Offset: 0x498
	// Line 2616, Address: 0x24213c, Func Offset: 0x49c
	// Line 2620, Address: 0x242140, Func Offset: 0x4a0
	// Line 2624, Address: 0x242144, Func Offset: 0x4a4
	// Line 2621, Address: 0x242148, Func Offset: 0x4a8
	// Line 2623, Address: 0x24214c, Func Offset: 0x4ac
	// Line 2624, Address: 0x242150, Func Offset: 0x4b0
	// Line 2627, Address: 0x242154, Func Offset: 0x4b4
	// Line 2629, Address: 0x242158, Func Offset: 0x4b8
	// Line 2630, Address: 0x24215c, Func Offset: 0x4bc
	// Line 2625, Address: 0x242160, Func Offset: 0x4c0
	// Line 2624, Address: 0x242164, Func Offset: 0x4c4
	// Line 2625, Address: 0x242168, Func Offset: 0x4c8
	// Line 2632, Address: 0x24216c, Func Offset: 0x4cc
	// Line 2627, Address: 0x242174, Func Offset: 0x4d4
	// Line 2625, Address: 0x242178, Func Offset: 0x4d8
	// Line 2628, Address: 0x24217c, Func Offset: 0x4dc
	// Line 2629, Address: 0x242180, Func Offset: 0x4e0
	// Line 2630, Address: 0x242184, Func Offset: 0x4e4
	// Line 2633, Address: 0x24218c, Func Offset: 0x4ec
	// Line 2634, Address: 0x242194, Func Offset: 0x4f4
	// Line 2633, Address: 0x242198, Func Offset: 0x4f8
	// Line 2634, Address: 0x2421a0, Func Offset: 0x500
	// Line 2633, Address: 0x2421a8, Func Offset: 0x508
	// Line 2634, Address: 0x2421b0, Func Offset: 0x510
	// Line 2633, Address: 0x2421b4, Func Offset: 0x514
	// Line 2634, Address: 0x2421b8, Func Offset: 0x518
	// Line 2635, Address: 0x2421d4, Func Offset: 0x534
	// Line 2636, Address: 0x2421f0, Func Offset: 0x550
	// Line 2637, Address: 0x242208, Func Offset: 0x568
	// Line 2638, Address: 0x24221c, Func Offset: 0x57c
	// Line 2637, Address: 0x242224, Func Offset: 0x584
	// Line 2638, Address: 0x242228, Func Offset: 0x588
	// Line 2639, Address: 0x242230, Func Offset: 0x590
	// Line 2641, Address: 0x242248, Func Offset: 0x5a8
	// Line 2639, Address: 0x242258, Func Offset: 0x5b8
	// Line 2640, Address: 0x242260, Func Offset: 0x5c0
	// Line 2639, Address: 0x242264, Func Offset: 0x5c4
	// Line 2640, Address: 0x242268, Func Offset: 0x5c8
	// Line 2641, Address: 0x242280, Func Offset: 0x5e0
	// Line 2642, Address: 0x242290, Func Offset: 0x5f0
	// Line 2643, Address: 0x2422a4, Func Offset: 0x604
	// Line 2647, Address: 0x2422b8, Func Offset: 0x618
	// Line 2648, Address: 0x2422c0, Func Offset: 0x620
	// Line 2649, Address: 0x2422d8, Func Offset: 0x638
	// Line 2650, Address: 0x2422e0, Func Offset: 0x640
	// Func End, Address: 0x242318, Func Offset: 0x678
	scePrintf("bhEff_E16_LaserSightDraw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x242320
void bhEff_E12_Fire(O_WRK* op)
{
	O_WRK** ent;
	O_WRK* fireman;
	NJS_POINT3 v;
	float ln;
	float dz;
	float dx;
	//_anon19* lp;
	UV_WORK* uvp;
	UV_WORK* uvtble[2];
	// Line 2872, Address: 0x242320, Func Offset: 0
	// Line 2913, Address: 0x242334, Func Offset: 0x14
	// Line 2915, Address: 0x242360, Func Offset: 0x40
	// Line 2916, Address: 0x242368, Func Offset: 0x48
	// Line 2917, Address: 0x242370, Func Offset: 0x50
	// Line 2920, Address: 0x242380, Func Offset: 0x60
	// Line 2921, Address: 0x242384, Func Offset: 0x64
	// Line 2920, Address: 0x242388, Func Offset: 0x68
	// Line 2921, Address: 0x24238c, Func Offset: 0x6c
	// Line 2922, Address: 0x242390, Func Offset: 0x70
	// Line 2924, Address: 0x24239c, Func Offset: 0x7c
	// Line 2925, Address: 0x2423a4, Func Offset: 0x84
	// Line 2924, Address: 0x2423ac, Func Offset: 0x8c
	// Line 2925, Address: 0x2423b0, Func Offset: 0x90
	// Line 2928, Address: 0x2423b8, Func Offset: 0x98
	// Line 2929, Address: 0x2423f4, Func Offset: 0xd4
	// Line 2930, Address: 0x2423fc, Func Offset: 0xdc
	// Line 2931, Address: 0x242404, Func Offset: 0xe4
	// Line 2930, Address: 0x242408, Func Offset: 0xe8
	// Line 2931, Address: 0x24240c, Func Offset: 0xec
	// Line 2932, Address: 0x242414, Func Offset: 0xf4
	// Line 2933, Address: 0x242450, Func Offset: 0x130
	// Line 2935, Address: 0x242490, Func Offset: 0x170
	// Line 2939, Address: 0x242494, Func Offset: 0x174
	// Line 2935, Address: 0x242498, Func Offset: 0x178
	// Line 2936, Address: 0x24249c, Func Offset: 0x17c
	// Line 2939, Address: 0x2424a4, Func Offset: 0x184
	// Line 2940, Address: 0x2424b0, Func Offset: 0x190
	// Line 2941, Address: 0x2424f0, Func Offset: 0x1d0
	// Line 2942, Address: 0x242500, Func Offset: 0x1e0
	// Line 2945, Address: 0x242504, Func Offset: 0x1e4
	// Line 2947, Address: 0x242540, Func Offset: 0x220
	// Line 2945, Address: 0x242544, Func Offset: 0x224
	// Line 2947, Address: 0x242548, Func Offset: 0x228
	// Line 2948, Address: 0x242550, Func Offset: 0x230
	// Line 2951, Address: 0x242558, Func Offset: 0x238
	// Line 2953, Address: 0x242568, Func Offset: 0x248
	// Line 2954, Address: 0x242574, Func Offset: 0x254
	// Line 2956, Address: 0x242584, Func Offset: 0x264
	// Line 2957, Address: 0x242588, Func Offset: 0x268
	// Line 2958, Address: 0x24258c, Func Offset: 0x26c
	// Line 2959, Address: 0x242590, Func Offset: 0x270
	// Line 2960, Address: 0x242594, Func Offset: 0x274
	// Line 2962, Address: 0x242598, Func Offset: 0x278
	// Line 2964, Address: 0x24259c, Func Offset: 0x27c
	// Line 2965, Address: 0x2425a0, Func Offset: 0x280
	// Line 2967, Address: 0x2425a4, Func Offset: 0x284
	// Line 2962, Address: 0x2425a8, Func Offset: 0x288
	// Line 2969, Address: 0x2425b0, Func Offset: 0x290
	// Line 2963, Address: 0x2425b8, Func Offset: 0x298
	// Line 2969, Address: 0x2425bc, Func Offset: 0x29c
	// Line 2968, Address: 0x2425c4, Func Offset: 0x2a4
	// Line 2963, Address: 0x2425c8, Func Offset: 0x2a8
	// Line 2964, Address: 0x2425d0, Func Offset: 0x2b0
	// Line 2965, Address: 0x2425d4, Func Offset: 0x2b4
	// Line 2966, Address: 0x2425d8, Func Offset: 0x2b8
	// Line 2967, Address: 0x2425dc, Func Offset: 0x2bc
	// Line 2968, Address: 0x2425e0, Func Offset: 0x2c0
	// Line 2969, Address: 0x2425e4, Func Offset: 0x2c4
	// Line 2971, Address: 0x2425e8, Func Offset: 0x2c8
	// Line 2976, Address: 0x2425f0, Func Offset: 0x2d0
	// Line 2977, Address: 0x2425f4, Func Offset: 0x2d4
	// Line 2969, Address: 0x2425fc, Func Offset: 0x2dc
	// Line 2978, Address: 0x242600, Func Offset: 0x2e0
	// Line 2969, Address: 0x242608, Func Offset: 0x2e8
	// Line 2970, Address: 0x242614, Func Offset: 0x2f4
	// Line 2971, Address: 0x242624, Func Offset: 0x304
	// Line 2972, Address: 0x242638, Func Offset: 0x318
	// Line 2973, Address: 0x242648, Func Offset: 0x328
	// Line 2974, Address: 0x24265c, Func Offset: 0x33c
	// Line 2975, Address: 0x242670, Func Offset: 0x350
	// Line 2976, Address: 0x242684, Func Offset: 0x364
	// Line 2977, Address: 0x242688, Func Offset: 0x368
	// Line 2978, Address: 0x24268c, Func Offset: 0x36c
	// Line 2981, Address: 0x242690, Func Offset: 0x370
	// Line 2985, Address: 0x242694, Func Offset: 0x374
	// Line 2981, Address: 0x24269c, Func Offset: 0x37c
	// Line 2982, Address: 0x2426a4, Func Offset: 0x384
	// Line 2985, Address: 0x2426a8, Func Offset: 0x388
	// Line 2987, Address: 0x2426ac, Func Offset: 0x38c
	// Line 2989, Address: 0x2426b8, Func Offset: 0x398
	// Line 2990, Address: 0x2426bc, Func Offset: 0x39c
	// Line 2994, Address: 0x2426c4, Func Offset: 0x3a4
	// Line 2995, Address: 0x2426dc, Func Offset: 0x3bc
	// Line 2999, Address: 0x2426e8, Func Offset: 0x3c8
	// Line 3000, Address: 0x2426f8, Func Offset: 0x3d8
	// Line 2999, Address: 0x2426fc, Func Offset: 0x3dc
	// Line 3000, Address: 0x242700, Func Offset: 0x3e0
	// Line 3001, Address: 0x242718, Func Offset: 0x3f8
	// Line 3002, Address: 0x24271c, Func Offset: 0x3fc
	// Line 3004, Address: 0x242724, Func Offset: 0x404
	// Line 3007, Address: 0x24272c, Func Offset: 0x40c
	// Line 3009, Address: 0x242738, Func Offset: 0x418
	// Line 3010, Address: 0x242748, Func Offset: 0x428
	// Line 3012, Address: 0x242750, Func Offset: 0x430
	// Line 3014, Address: 0x242758, Func Offset: 0x438
	// Line 3015, Address: 0x242768, Func Offset: 0x448
	// Line 3020, Address: 0x24276c, Func Offset: 0x44c
	// Line 3023, Address: 0x242784, Func Offset: 0x464
	// Line 3024, Address: 0x24278c, Func Offset: 0x46c
	// Line 3023, Address: 0x242790, Func Offset: 0x470
	// Line 3024, Address: 0x242794, Func Offset: 0x474
	// Line 3023, Address: 0x242798, Func Offset: 0x478
	// Line 3024, Address: 0x24279c, Func Offset: 0x47c
	// Line 3025, Address: 0x2427a0, Func Offset: 0x480
	// Line 3026, Address: 0x2427ac, Func Offset: 0x48c
	// Line 3027, Address: 0x2427d4, Func Offset: 0x4b4
	// Line 3028, Address: 0x2427dc, Func Offset: 0x4bc
	// Line 3027, Address: 0x2427e0, Func Offset: 0x4c0
	// Line 3028, Address: 0x2427ec, Func Offset: 0x4cc
	// Line 3029, Address: 0x2427f8, Func Offset: 0x4d8
	// Line 3028, Address: 0x2427fc, Func Offset: 0x4dc
	// Line 3029, Address: 0x242810, Func Offset: 0x4f0
	// Line 3030, Address: 0x242818, Func Offset: 0x4f8
	// Line 3029, Address: 0x24281c, Func Offset: 0x4fc
	// Line 3030, Address: 0x242824, Func Offset: 0x504
	// Line 3032, Address: 0x242834, Func Offset: 0x514
	// Line 3034, Address: 0x242840, Func Offset: 0x520
	// Line 3038, Address: 0x24287c, Func Offset: 0x55c
	// Line 3039, Address: 0x242888, Func Offset: 0x568
	// Line 3043, Address: 0x242890, Func Offset: 0x570
	// Line 3039, Address: 0x242894, Func Offset: 0x574
	// Line 3040, Address: 0x242898, Func Offset: 0x578
	// Line 3039, Address: 0x24289c, Func Offset: 0x57c
	// Line 3040, Address: 0x2428a4, Func Offset: 0x584
	// Line 3041, Address: 0x2428ac, Func Offset: 0x58c
	// Line 3042, Address: 0x2428b8, Func Offset: 0x598
	// Line 3043, Address: 0x2428c4, Func Offset: 0x5a4
	// Line 3044, Address: 0x2428d0, Func Offset: 0x5b0
	// Line 3048, Address: 0x2428e4, Func Offset: 0x5c4
	// Line 3044, Address: 0x2428e8, Func Offset: 0x5c8
	// Line 3045, Address: 0x2428ec, Func Offset: 0x5cc
	// Line 3046, Address: 0x2428f8, Func Offset: 0x5d8
	// Line 3048, Address: 0x242904, Func Offset: 0x5e4
	// Line 3053, Address: 0x242908, Func Offset: 0x5e8
	// Line 3056, Address: 0x24291c, Func Offset: 0x5fc
	// Line 3058, Address: 0x24292c, Func Offset: 0x60c
	// Line 3062, Address: 0x242934, Func Offset: 0x614
	// Line 3058, Address: 0x242938, Func Offset: 0x618
	// Line 3062, Address: 0x24293c, Func Offset: 0x61c
	// Line 3060, Address: 0x242940, Func Offset: 0x620
	// Line 3058, Address: 0x242944, Func Offset: 0x624
	// Line 3059, Address: 0x242950, Func Offset: 0x630
	// Line 3066, Address: 0x242958, Func Offset: 0x638
	// Line 3059, Address: 0x242964, Func Offset: 0x644
	// Line 3060, Address: 0x242970, Func Offset: 0x650
	// Line 3061, Address: 0x242984, Func Offset: 0x664
	// Line 3062, Address: 0x24299c, Func Offset: 0x67c
	// Line 3063, Address: 0x2429b8, Func Offset: 0x698
	// Line 3064, Address: 0x2429d0, Func Offset: 0x6b0
	// Line 3065, Address: 0x2429e4, Func Offset: 0x6c4
	// Line 3066, Address: 0x2429f8, Func Offset: 0x6d8
	// Line 3069, Address: 0x242a10, Func Offset: 0x6f0
	// Line 3071, Address: 0x242a50, Func Offset: 0x730
	// Line 3073, Address: 0x242a58, Func Offset: 0x738
	// Line 3074, Address: 0x242a68, Func Offset: 0x748
	// Line 3073, Address: 0x242a6c, Func Offset: 0x74c
	// Line 3074, Address: 0x242a70, Func Offset: 0x750
	// Line 3075, Address: 0x242a74, Func Offset: 0x754
	// Line 3073, Address: 0x242a7c, Func Offset: 0x75c
	// Line 3074, Address: 0x242a80, Func Offset: 0x760
	// Line 3075, Address: 0x242a88, Func Offset: 0x768
	// Line 3074, Address: 0x242a90, Func Offset: 0x770
	// Line 3075, Address: 0x242a98, Func Offset: 0x778
	// Line 3076, Address: 0x242aac, Func Offset: 0x78c
	// Line 3077, Address: 0x242ab0, Func Offset: 0x790
	// Line 3078, Address: 0x242abc, Func Offset: 0x79c
	// Line 3079, Address: 0x242ac4, Func Offset: 0x7a4
	// Line 3081, Address: 0x242acc, Func Offset: 0x7ac
	// Line 3083, Address: 0x242ad4, Func Offset: 0x7b4
	// Line 3084, Address: 0x242ad8, Func Offset: 0x7b8
	// Line 3085, Address: 0x242ae4, Func Offset: 0x7c4
	// Line 3083, Address: 0x242ae8, Func Offset: 0x7c8
	// Line 3084, Address: 0x242af0, Func Offset: 0x7d0
	// Line 3085, Address: 0x242af4, Func Offset: 0x7d4
	// Line 3084, Address: 0x242b00, Func Offset: 0x7e0
	// Line 3085, Address: 0x242b08, Func Offset: 0x7e8
	// Line 3086, Address: 0x242b14, Func Offset: 0x7f4
	// Line 3087, Address: 0x242b20, Func Offset: 0x800
	// Line 3089, Address: 0x242b2c, Func Offset: 0x80c
	// Line 3091, Address: 0x242b34, Func Offset: 0x814
	// Line 3092, Address: 0x242b3c, Func Offset: 0x81c
	// Line 3095, Address: 0x242b44, Func Offset: 0x824
	// Line 3096, Address: 0x242b54, Func Offset: 0x834
	// Line 3105, Address: 0x242b5c, Func Offset: 0x83c
	// Line 3108, Address: 0x242b64, Func Offset: 0x844
	// Line 3111, Address: 0x242b74, Func Offset: 0x854
	// Line 3115, Address: 0x242b7c, Func Offset: 0x85c
	// Line 3117, Address: 0x242b88, Func Offset: 0x868
	// Line 3115, Address: 0x242b90, Func Offset: 0x870
	// Line 3117, Address: 0x242b94, Func Offset: 0x874
	// Line 3115, Address: 0x242b98, Func Offset: 0x878
	// Line 3116, Address: 0x242ba8, Func Offset: 0x888
	// Line 3115, Address: 0x242bb0, Func Offset: 0x890
	// Line 3117, Address: 0x242bb4, Func Offset: 0x894
	// Line 3118, Address: 0x242be4, Func Offset: 0x8c4
	// Line 3122, Address: 0x242be8, Func Offset: 0x8c8
	// Line 3123, Address: 0x242bf4, Func Offset: 0x8d4
	// Line 3127, Address: 0x242bfc, Func Offset: 0x8dc
	// Line 3123, Address: 0x242c04, Func Offset: 0x8e4
	// Line 3124, Address: 0x242c0c, Func Offset: 0x8ec
	// Line 3127, Address: 0x242c1c, Func Offset: 0x8fc
	// Line 3130, Address: 0x242c30, Func Offset: 0x910
	// Line 3131, Address: 0x242c40, Func Offset: 0x920
	// Line 3135, Address: 0x242c6c, Func Offset: 0x94c
	// Line 3138, Address: 0x242c78, Func Offset: 0x958
	// Line 3145, Address: 0x242c8c, Func Offset: 0x96c
	// Line 3147, Address: 0x242c98, Func Offset: 0x978
	// Line 3148, Address: 0x242cb4, Func Offset: 0x994
	// Line 3149, Address: 0x242cc8, Func Offset: 0x9a8
	// Line 3156, Address: 0x242ce8, Func Offset: 0x9c8
	// Line 3158, Address: 0x242cf0, Func Offset: 0x9d0
	// Line 3160, Address: 0x242cf4, Func Offset: 0x9d4
	// Line 3159, Address: 0x242cf8, Func Offset: 0x9d8
	// Line 3160, Address: 0x242cfc, Func Offset: 0x9dc
	// Line 3161, Address: 0x242d08, Func Offset: 0x9e8
	// Line 3162, Address: 0x242d14, Func Offset: 0x9f4
	// Line 3174, Address: 0x242d20, Func Offset: 0xa00
	// Func End, Address: 0x242d38, Func Offset: 0xa18
	scePrintf("bhEff_E12_Fire - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x242d40
void bhEff_E12_FrameLiquid(O_WRK* op)
{
	NJS_POINT3 ofp;
	int hit;
	int i;
	int eno;
	int DGDir;
	// Line 3185, Address: 0x242d40, Func Offset: 0
	// Line 3198, Address: 0x242d5c, Func Offset: 0x1c
	// Line 3200, Address: 0x242d98, Func Offset: 0x58
	// Line 3201, Address: 0x242d9c, Func Offset: 0x5c
	// Line 3202, Address: 0x242da4, Func Offset: 0x64
	// Line 3203, Address: 0x242da8, Func Offset: 0x68
	// Line 3204, Address: 0x242dac, Func Offset: 0x6c
	// Line 3205, Address: 0x242db0, Func Offset: 0x70
	// Line 3206, Address: 0x242db4, Func Offset: 0x74
	// Line 3207, Address: 0x242dbc, Func Offset: 0x7c
	// Line 3208, Address: 0x242dc0, Func Offset: 0x80
	// Line 3209, Address: 0x242dc4, Func Offset: 0x84
	// Line 3210, Address: 0x242dc8, Func Offset: 0x88
	// Line 3211, Address: 0x242dcc, Func Offset: 0x8c
	// Line 3212, Address: 0x242dd0, Func Offset: 0x90
	// Line 3213, Address: 0x242dd4, Func Offset: 0x94
	// Line 3214, Address: 0x242ddc, Func Offset: 0x9c
	// Line 3215, Address: 0x242de4, Func Offset: 0xa4
	// Line 3216, Address: 0x242de8, Func Offset: 0xa8
	// Line 3214, Address: 0x242dec, Func Offset: 0xac
	// Line 3215, Address: 0x242df4, Func Offset: 0xb4
	// Line 3216, Address: 0x242df8, Func Offset: 0xb8
	// Line 3221, Address: 0x242dfc, Func Offset: 0xbc
	// Line 3222, Address: 0x242e04, Func Offset: 0xc4
	// Line 3225, Address: 0x242e08, Func Offset: 0xc8
	// Line 3226, Address: 0x242e14, Func Offset: 0xd4
	// Line 3227, Address: 0x242e24, Func Offset: 0xe4
	// Line 3228, Address: 0x242e88, Func Offset: 0x148
	// Line 3230, Address: 0x242eb4, Func Offset: 0x174
	// Line 3231, Address: 0x242ec4, Func Offset: 0x184
	// Line 3233, Address: 0x242ed0, Func Offset: 0x190
	// Line 3231, Address: 0x242ed4, Func Offset: 0x194
	// Line 3233, Address: 0x242edc, Func Offset: 0x19c
	// Line 3234, Address: 0x242ee4, Func Offset: 0x1a4
	// Line 3233, Address: 0x242ee8, Func Offset: 0x1a8
	// Line 3234, Address: 0x242eec, Func Offset: 0x1ac
	// Line 3235, Address: 0x242ef4, Func Offset: 0x1b4
	// Line 3234, Address: 0x242ef8, Func Offset: 0x1b8
	// Line 3235, Address: 0x242efc, Func Offset: 0x1bc
	// Line 3237, Address: 0x242f04, Func Offset: 0x1c4
	// Line 3235, Address: 0x242f08, Func Offset: 0x1c8
	// Line 3237, Address: 0x242f0c, Func Offset: 0x1cc
	// Line 3239, Address: 0x242f14, Func Offset: 0x1d4
	// Line 3237, Address: 0x242f20, Func Offset: 0x1e0
	// Line 3245, Address: 0x242f24, Func Offset: 0x1e4
	// Line 3239, Address: 0x242f28, Func Offset: 0x1e8
	// Line 3240, Address: 0x242f2c, Func Offset: 0x1ec
	// Line 3241, Address: 0x242f38, Func Offset: 0x1f8
	// Line 3242, Address: 0x242f44, Func Offset: 0x204
	// Line 3246, Address: 0x242f58, Func Offset: 0x218
	// Line 3247, Address: 0x242f98, Func Offset: 0x258
	// Line 3248, Address: 0x242fd8, Func Offset: 0x298
	// Line 3249, Address: 0x243000, Func Offset: 0x2c0
	// Line 3250, Address: 0x24308c, Func Offset: 0x34c
	// Line 3251, Address: 0x24309c, Func Offset: 0x35c
	// Line 3254, Address: 0x2430a0, Func Offset: 0x360
	// Line 3257, Address: 0x2430ac, Func Offset: 0x36c
	// Line 3255, Address: 0x2430b0, Func Offset: 0x370
	// Line 3256, Address: 0x2430b4, Func Offset: 0x374
	// Line 3254, Address: 0x2430b8, Func Offset: 0x378
	// Line 3255, Address: 0x2430c4, Func Offset: 0x384
	// Line 3256, Address: 0x2430d8, Func Offset: 0x398
	// Line 3257, Address: 0x2430ec, Func Offset: 0x3ac
	// Line 3258, Address: 0x243100, Func Offset: 0x3c0
	// Line 3259, Address: 0x243114, Func Offset: 0x3d4
	// Line 3260, Address: 0x24312c, Func Offset: 0x3ec
	// Line 3261, Address: 0x243140, Func Offset: 0x400
	// Line 3263, Address: 0x243148, Func Offset: 0x408
	// Line 3264, Address: 0x243174, Func Offset: 0x434
	// Line 3265, Address: 0x243198, Func Offset: 0x458
	// Line 3267, Address: 0x2431bc, Func Offset: 0x47c
	// Line 3268, Address: 0x2431d0, Func Offset: 0x490
	// Line 3269, Address: 0x2431f4, Func Offset: 0x4b4
	// Line 3273, Address: 0x2431f8, Func Offset: 0x4b8
	// Line 3268, Address: 0x2431fc, Func Offset: 0x4bc
	// Line 3273, Address: 0x243214, Func Offset: 0x4d4
	// Line 3268, Address: 0x24321c, Func Offset: 0x4dc
	// Line 3269, Address: 0x243224, Func Offset: 0x4e4
	// Line 3270, Address: 0x243238, Func Offset: 0x4f8
	// Line 3271, Address: 0x24324c, Func Offset: 0x50c
	// Line 3273, Address: 0x243260, Func Offset: 0x520
	// Line 3274, Address: 0x243278, Func Offset: 0x538
	// Line 3275, Address: 0x243284, Func Offset: 0x544
	// Line 3276, Address: 0x2432a8, Func Offset: 0x568
	// Line 3277, Address: 0x2432bc, Func Offset: 0x57c
	// Line 3278, Address: 0x2432d0, Func Offset: 0x590
	// Line 3281, Address: 0x2432e4, Func Offset: 0x5a4
	// Line 3282, Address: 0x2432e8, Func Offset: 0x5a8
	// Line 3281, Address: 0x2432ec, Func Offset: 0x5ac
	// Line 3284, Address: 0x2432f4, Func Offset: 0x5b4
	// Line 3286, Address: 0x2432fc, Func Offset: 0x5bc
	// Line 3287, Address: 0x243308, Func Offset: 0x5c8
	// Line 3288, Address: 0x24330c, Func Offset: 0x5cc
	// Line 3287, Address: 0x243310, Func Offset: 0x5d0
	// Line 3291, Address: 0x243318, Func Offset: 0x5d8
	// Line 3294, Address: 0x243320, Func Offset: 0x5e0
	// Line 3295, Address: 0x243334, Func Offset: 0x5f4
	// Line 3296, Address: 0x243344, Func Offset: 0x604
	// Line 3297, Address: 0x24334c, Func Offset: 0x60c
	// Line 3301, Address: 0x243358, Func Offset: 0x618
	// Line 3302, Address: 0x243364, Func Offset: 0x624
	// Line 3303, Address: 0x243370, Func Offset: 0x630
	// Line 3306, Address: 0x24337c, Func Offset: 0x63c
	// Line 3310, Address: 0x243384, Func Offset: 0x644
	// Line 3313, Address: 0x24338c, Func Offset: 0x64c
	// Line 3326, Address: 0x243394, Func Offset: 0x654
	// Line 3327, Address: 0x2433b4, Func Offset: 0x674
	// Line 3328, Address: 0x2433c8, Func Offset: 0x688
	// Line 3330, Address: 0x2433ec, Func Offset: 0x6ac
	// Func End, Address: 0x24340c, Func Offset: 0x6cc
	scePrintf("bhEff_E12_FrameLiquid - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x243410
void bhEff_E12_FloorBlood2(O_WRK* op)
{
	UV_WORK* uvp;
	NJS_POINT3 ofp;
	int i;
	UV_WORK* uvtble[1];
	// Line 3340, Address: 0x243410, Func Offset: 0
	// Line 3359, Address: 0x243424, Func Offset: 0x14
	// Line 3361, Address: 0x24345c, Func Offset: 0x4c
	// Line 3362, Address: 0x2434a0, Func Offset: 0x90
	// Line 3364, Address: 0x2434ac, Func Offset: 0x9c
	// Line 3365, Address: 0x2434bc, Func Offset: 0xac
	// Line 3367, Address: 0x2434e8, Func Offset: 0xd8
	// Line 3368, Address: 0x2434f4, Func Offset: 0xe4
	// Line 3370, Address: 0x2434fc, Func Offset: 0xec
	// Line 3376, Address: 0x243500, Func Offset: 0xf0
	// Line 3368, Address: 0x243504, Func Offset: 0xf4
	// Line 3370, Address: 0x243508, Func Offset: 0xf8
	// Line 3368, Address: 0x24350c, Func Offset: 0xfc
	// Line 3370, Address: 0x243514, Func Offset: 0x104
	// Line 3371, Address: 0x24351c, Func Offset: 0x10c
	// Line 3372, Address: 0x243528, Func Offset: 0x118
	// Line 3371, Address: 0x24352c, Func Offset: 0x11c
	// Line 3372, Address: 0x243530, Func Offset: 0x120
	// Line 3373, Address: 0x243538, Func Offset: 0x128
	// Line 3377, Address: 0x24354c, Func Offset: 0x13c
	// Line 3378, Address: 0x24358c, Func Offset: 0x17c
	// Line 3379, Address: 0x2435d0, Func Offset: 0x1c0
	// Line 3380, Address: 0x2435f8, Func Offset: 0x1e8
	// Line 3381, Address: 0x243684, Func Offset: 0x274
	// Line 3382, Address: 0x243694, Func Offset: 0x284
	// Line 3383, Address: 0x243698, Func Offset: 0x288
	// Line 3385, Address: 0x2436a0, Func Offset: 0x290
	// Line 3387, Address: 0x2436a8, Func Offset: 0x298
	// Line 3388, Address: 0x2436ac, Func Offset: 0x29c
	// Line 3389, Address: 0x2436b4, Func Offset: 0x2a4
	// Line 3390, Address: 0x2436bc, Func Offset: 0x2ac
	// Line 3388, Address: 0x2436c0, Func Offset: 0x2b0
	// Line 3389, Address: 0x2436c8, Func Offset: 0x2b8
	// Line 3391, Address: 0x2436cc, Func Offset: 0x2bc
	// Line 3389, Address: 0x2436d0, Func Offset: 0x2c0
	// Line 3390, Address: 0x2436d8, Func Offset: 0x2c8
	// Line 3391, Address: 0x2436e0, Func Offset: 0x2d0
	// Line 3392, Address: 0x2436e8, Func Offset: 0x2d8
	// Line 3393, Address: 0x2436f0, Func Offset: 0x2e0
	// Line 3395, Address: 0x2436f4, Func Offset: 0x2e4
	// Line 3396, Address: 0x243734, Func Offset: 0x324
	// Line 3397, Address: 0x243778, Func Offset: 0x368
	// Line 3398, Address: 0x2437a0, Func Offset: 0x390
	// Line 3399, Address: 0x2437a8, Func Offset: 0x398
	// Line 3401, Address: 0x2437ac, Func Offset: 0x39c
	// Line 3398, Address: 0x2437b0, Func Offset: 0x3a0
	// Line 3399, Address: 0x2437b4, Func Offset: 0x3a4
	// Line 3401, Address: 0x2437b8, Func Offset: 0x3a8
	// Line 3402, Address: 0x2437bc, Func Offset: 0x3ac
	// Line 3403, Address: 0x2437c0, Func Offset: 0x3b0
	// Line 3404, Address: 0x2437c4, Func Offset: 0x3b4
	// Line 3405, Address: 0x2437c8, Func Offset: 0x3b8
	// Line 3406, Address: 0x2437d0, Func Offset: 0x3c0
	// Line 3408, Address: 0x2437d8, Func Offset: 0x3c8
	// Line 3410, Address: 0x2437e4, Func Offset: 0x3d4
	// Line 3415, Address: 0x2437ec, Func Offset: 0x3dc
	// Line 3417, Address: 0x2437f8, Func Offset: 0x3e8
	// Line 3415, Address: 0x243800, Func Offset: 0x3f0
	// Line 3417, Address: 0x243804, Func Offset: 0x3f4
	// Line 3415, Address: 0x243808, Func Offset: 0x3f8
	// Line 3416, Address: 0x243818, Func Offset: 0x408
	// Line 3415, Address: 0x243820, Func Offset: 0x410
	// Line 3417, Address: 0x243824, Func Offset: 0x414
	// Line 3418, Address: 0x243854, Func Offset: 0x444
	// Line 3422, Address: 0x243858, Func Offset: 0x448
	// Line 3424, Address: 0x243864, Func Offset: 0x454
	// Line 3425, Address: 0x243884, Func Offset: 0x474
	// Line 3426, Address: 0x243898, Func Offset: 0x488
	// Line 3428, Address: 0x2438bc, Func Offset: 0x4ac
	// Func End, Address: 0x2438d4, Func Offset: 0x4c4
	scePrintf("bhEff_E12_FloorBlood2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2438e0
void bhEff_E12_FireSpark(O_WRK* op)
{
	unsigned int col[3];
	int i;
	NJS_POINT3* v;
	NJS_POINT3* p;
	//_anon6* pp;
	// Line 3438, Address: 0x2438e0, Func Offset: 0
	// Line 3443, Address: 0x2438f4, Func Offset: 0x14
	// Line 3438, Address: 0x2438f8, Func Offset: 0x18
	// Line 3443, Address: 0x243900, Func Offset: 0x20
	// Line 3449, Address: 0x24391c, Func Offset: 0x3c
	// Line 3452, Address: 0x24393c, Func Offset: 0x5c
	// Line 3453, Address: 0x243948, Func Offset: 0x68
	// Line 3455, Address: 0x243950, Func Offset: 0x70
	// Line 3459, Address: 0x243958, Func Offset: 0x78
	// Line 3458, Address: 0x24395c, Func Offset: 0x7c
	// Line 3460, Address: 0x243960, Func Offset: 0x80
	// Line 3461, Address: 0x243964, Func Offset: 0x84
	// Line 3459, Address: 0x243968, Func Offset: 0x88
	// Line 3462, Address: 0x24396c, Func Offset: 0x8c
	// Line 3463, Address: 0x243974, Func Offset: 0x94
	// Line 3464, Address: 0x2439b8, Func Offset: 0xd8
	// Line 3465, Address: 0x2439ec, Func Offset: 0x10c
	// Line 3467, Address: 0x243a30, Func Offset: 0x150
	// Line 3468, Address: 0x243a68, Func Offset: 0x188
	// Line 3469, Address: 0x243aa8, Func Offset: 0x1c8
	// Line 3470, Address: 0x243abc, Func Offset: 0x1dc
	// Line 3471, Address: 0x243af4, Func Offset: 0x214
	// Line 3472, Address: 0x243b04, Func Offset: 0x224
	// Line 3471, Address: 0x243b0c, Func Offset: 0x22c
	// Line 3472, Address: 0x243b14, Func Offset: 0x234
	// Line 3474, Address: 0x243b28, Func Offset: 0x248
	// Line 3475, Address: 0x243b34, Func Offset: 0x254
	// Line 3477, Address: 0x243b3c, Func Offset: 0x25c
	// Line 3480, Address: 0x243b7c, Func Offset: 0x29c
	// Line 3477, Address: 0x243b80, Func Offset: 0x2a0
	// Line 3480, Address: 0x243b84, Func Offset: 0x2a4
	// Line 3482, Address: 0x243b88, Func Offset: 0x2a8
	// Line 3483, Address: 0x243b90, Func Offset: 0x2b0
	// Line 3484, Address: 0x243b94, Func Offset: 0x2b4
	// Line 3482, Address: 0x243b98, Func Offset: 0x2b8
	// Line 3483, Address: 0x243ba0, Func Offset: 0x2c0
	// Line 3484, Address: 0x243ba4, Func Offset: 0x2c4
	// Line 3487, Address: 0x243ba8, Func Offset: 0x2c8
	// Line 3488, Address: 0x243bb4, Func Offset: 0x2d4
	// Line 3489, Address: 0x243bbc, Func Offset: 0x2dc
	// Line 3492, Address: 0x243bc4, Func Offset: 0x2e4
	// Line 3495, Address: 0x243bc8, Func Offset: 0x2e8
	// Line 3493, Address: 0x243bcc, Func Offset: 0x2ec
	// Line 3495, Address: 0x243bd0, Func Offset: 0x2f0
	// Line 3496, Address: 0x243bd8, Func Offset: 0x2f8
	// Line 3497, Address: 0x243c24, Func Offset: 0x344
	// Line 3498, Address: 0x243c70, Func Offset: 0x390
	// Line 3504, Address: 0x243c98, Func Offset: 0x3b8
	// Line 3498, Address: 0x243c9c, Func Offset: 0x3bc
	// Line 3504, Address: 0x243cac, Func Offset: 0x3cc
	// Line 3507, Address: 0x243cb0, Func Offset: 0x3d0
	// Line 3498, Address: 0x243cb4, Func Offset: 0x3d4
	// Line 3504, Address: 0x243cbc, Func Offset: 0x3dc
	// Line 3498, Address: 0x243cc0, Func Offset: 0x3e0
	// Line 3500, Address: 0x243ccc, Func Offset: 0x3ec
	// Line 3501, Address: 0x243cdc, Func Offset: 0x3fc
	// Line 3502, Address: 0x243cec, Func Offset: 0x40c
	// Line 3504, Address: 0x243cfc, Func Offset: 0x41c
	// Line 3507, Address: 0x243d00, Func Offset: 0x420
	// Line 3504, Address: 0x243d04, Func Offset: 0x424
	// Line 3505, Address: 0x243d0c, Func Offset: 0x42c
	// Line 3506, Address: 0x243d18, Func Offset: 0x438
	// Line 3507, Address: 0x243d24, Func Offset: 0x444
	// Line 3510, Address: 0x243d38, Func Offset: 0x458
	// Line 3511, Address: 0x243d84, Func Offset: 0x4a4
	// Line 3512, Address: 0x243d94, Func Offset: 0x4b4
	// Line 3513, Address: 0x243dec, Func Offset: 0x50c
	// Line 3514, Address: 0x243dfc, Func Offset: 0x51c
	// Line 3517, Address: 0x243e08, Func Offset: 0x528
	// Line 3518, Address: 0x243e18, Func Offset: 0x538
	// Line 3520, Address: 0x243e1c, Func Offset: 0x53c
	// Line 3523, Address: 0x243e24, Func Offset: 0x544
	// Line 3524, Address: 0x243e44, Func Offset: 0x564
	// Line 3525, Address: 0x243e58, Func Offset: 0x578
	// Line 3528, Address: 0x243e7c, Func Offset: 0x59c
	// Func End, Address: 0x243e9c, Func Offset: 0x5bc
	scePrintf("bhEff_E12_FireSpark - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x243ea0
void bhEff_E12_FireManager(O_WRK* op)
{
	// Line 3538, Address: 0x243ea0, Func Offset: 0
	// Line 3548, Address: 0x243eb0, Func Offset: 0x10
	// Line 3551, Address: 0x243ed0, Func Offset: 0x30
	// Line 3552, Address: 0x243edc, Func Offset: 0x3c
	// Line 3555, Address: 0x243ee8, Func Offset: 0x48
	// Line 3556, Address: 0x243ef0, Func Offset: 0x50
	// Line 3557, Address: 0x243ef8, Func Offset: 0x58
	// Line 3558, Address: 0x243f00, Func Offset: 0x60
	// Line 3563, Address: 0x243f08, Func Offset: 0x68
	// Line 3565, Address: 0x243f14, Func Offset: 0x74
	// Line 3566, Address: 0x243f1c, Func Offset: 0x7c
	// Line 3569, Address: 0x243f24, Func Offset: 0x84
	// Line 3572, Address: 0x243f28, Func Offset: 0x88
	// Line 3573, Address: 0x243f48, Func Offset: 0xa8
	// Line 3574, Address: 0x243f5c, Func Offset: 0xbc
	// Line 3577, Address: 0x243f80, Func Offset: 0xe0
	// Func End, Address: 0x243f90, Func Offset: 0xf0
	scePrintf("bhEff_E12_FireManager - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x243f90
void bhEff_E12_FireBurstDraw(O_WRK* owp)
{
	char atr[192];
	O_WRK** opp;
	O_WRK* op;
	int num;
	// Line 3587, Address: 0x243f90, Func Offset: 0
	// Line 3593, Address: 0x243fa4, Func Offset: 0x14
	// Line 3596, Address: 0x243fb8, Func Offset: 0x28
	// Line 3598, Address: 0x243fc0, Func Offset: 0x30
	// Line 3599, Address: 0x243fd8, Func Offset: 0x48
	// Line 3601, Address: 0x244004, Func Offset: 0x74
	// Line 3602, Address: 0x24400c, Func Offset: 0x7c
	// Line 3603, Address: 0x244018, Func Offset: 0x88
	// Line 3605, Address: 0x244024, Func Offset: 0x94
	// Line 3607, Address: 0x24402c, Func Offset: 0x9c
	// Line 3608, Address: 0x244030, Func Offset: 0xa0
	// Line 3609, Address: 0x244034, Func Offset: 0xa4
	// Line 3610, Address: 0x24403c, Func Offset: 0xac
	// Line 3611, Address: 0x244040, Func Offset: 0xb0
	// Line 3613, Address: 0x244044, Func Offset: 0xb4
	// Line 3616, Address: 0x24404c, Func Offset: 0xbc
	// Line 3617, Address: 0x244054, Func Offset: 0xc4
	// Line 3618, Address: 0x24405c, Func Offset: 0xcc
	// Line 3619, Address: 0x244064, Func Offset: 0xd4
	// Line 3620, Address: 0x244070, Func Offset: 0xe0
	// Line 3621, Address: 0x244078, Func Offset: 0xe8
	// Line 3623, Address: 0x244080, Func Offset: 0xf0
	// Line 3626, Address: 0x24408c, Func Offset: 0xfc
	// Line 3627, Address: 0x2440a0, Func Offset: 0x110
	// Line 3629, Address: 0x2440a8, Func Offset: 0x118
	// Line 3632, Address: 0x2440b4, Func Offset: 0x124
	// Line 3634, Address: 0x2440c4, Func Offset: 0x134
	// Line 3635, Address: 0x2440cc, Func Offset: 0x13c
	// Line 3638, Address: 0x2440d8, Func Offset: 0x148
	// Line 3639, Address: 0x2440e0, Func Offset: 0x150
	// Line 3640, Address: 0x244100, Func Offset: 0x170
	// Func End, Address: 0x244118, Func Offset: 0x188
	scePrintf("bhEff_E12_FireBurstDraw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x244120
void bhEff_E12_Fire2(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK* uvtble[1];
	// Line 3650, Address: 0x244120, Func Offset: 0
	// Line 3676, Address: 0x24412c, Func Offset: 0xc
	// Line 3678, Address: 0x244164, Func Offset: 0x44
	// Line 3680, Address: 0x24416c, Func Offset: 0x4c
	// Line 3681, Address: 0x24417c, Func Offset: 0x5c
	// Line 3682, Address: 0x244184, Func Offset: 0x64
	// Line 3683, Address: 0x24418c, Func Offset: 0x6c
	// Line 3684, Address: 0x244194, Func Offset: 0x74
	// Line 3683, Address: 0x24419c, Func Offset: 0x7c
	// Line 3684, Address: 0x2441a0, Func Offset: 0x80
	// Line 3686, Address: 0x2441a8, Func Offset: 0x88
	// Line 3687, Address: 0x2441e8, Func Offset: 0xc8
	// Line 3694, Address: 0x2441ec, Func Offset: 0xcc
	// Line 3689, Address: 0x2441f0, Func Offset: 0xd0
	// Line 3691, Address: 0x2441f4, Func Offset: 0xd4
	// Line 3694, Address: 0x2441f8, Func Offset: 0xd8
	// Line 3687, Address: 0x2441fc, Func Offset: 0xdc
	// Line 3688, Address: 0x244200, Func Offset: 0xe0
	// Line 3689, Address: 0x244208, Func Offset: 0xe8
	// Line 3690, Address: 0x24420c, Func Offset: 0xec
	// Line 3691, Address: 0x244210, Func Offset: 0xf0
	// Line 3694, Address: 0x244214, Func Offset: 0xf4
	// Line 3696, Address: 0x244218, Func Offset: 0xf8
	// Line 3698, Address: 0x244224, Func Offset: 0x104
	// Line 3699, Address: 0x244230, Func Offset: 0x110
	// Line 3700, Address: 0x244234, Func Offset: 0x114
	// Line 3702, Address: 0x24423c, Func Offset: 0x11c
	// Line 3704, Address: 0x244244, Func Offset: 0x124
	// Line 3706, Address: 0x24424c, Func Offset: 0x12c
	// Line 3707, Address: 0x244258, Func Offset: 0x138
	// Line 3708, Address: 0x24425c, Func Offset: 0x13c
	// Line 3709, Address: 0x244264, Func Offset: 0x144
	// Line 3711, Address: 0x244268, Func Offset: 0x148
	// Line 3713, Address: 0x244270, Func Offset: 0x150
	// Line 3714, Address: 0x24427c, Func Offset: 0x15c
	// Line 3716, Address: 0x244288, Func Offset: 0x168
	// Line 3718, Address: 0x244290, Func Offset: 0x170
	// Line 3723, Address: 0x2442a4, Func Offset: 0x184
	// Line 3725, Address: 0x2442b0, Func Offset: 0x190
	// Line 3723, Address: 0x2442b8, Func Offset: 0x198
	// Line 3725, Address: 0x2442bc, Func Offset: 0x19c
	// Line 3723, Address: 0x2442c0, Func Offset: 0x1a0
	// Line 3724, Address: 0x2442d0, Func Offset: 0x1b0
	// Line 3723, Address: 0x2442d8, Func Offset: 0x1b8
	// Line 3725, Address: 0x2442dc, Func Offset: 0x1bc
	// Line 3726, Address: 0x24430c, Func Offset: 0x1ec
	// Line 3730, Address: 0x244310, Func Offset: 0x1f0
	// Line 3731, Address: 0x244320, Func Offset: 0x200
	// Line 3734, Address: 0x244328, Func Offset: 0x208
	// Line 3731, Address: 0x24432c, Func Offset: 0x20c
	// Line 3732, Address: 0x244334, Func Offset: 0x214
	// Line 3734, Address: 0x244344, Func Offset: 0x224
	// Line 3735, Address: 0x244360, Func Offset: 0x240
	// Line 3736, Address: 0x244374, Func Offset: 0x254
	// Line 3738, Address: 0x244398, Func Offset: 0x278
	// Func End, Address: 0x2443a8, Func Offset: 0x288
	scePrintf("bhEff_E12_Fire2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2443b0
void bhEff_E12_Fire3(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK* uvtble[1];
	// Line 3748, Address: 0x2443b0, Func Offset: 0
	// Line 3784, Address: 0x2443bc, Func Offset: 0xc
	// Line 3786, Address: 0x2443dc, Func Offset: 0x2c
	// Line 3788, Address: 0x2443e4, Func Offset: 0x34
	// Line 3789, Address: 0x2443f0, Func Offset: 0x40
	// Line 3790, Address: 0x2443f8, Func Offset: 0x48
	// Line 3791, Address: 0x244400, Func Offset: 0x50
	// Line 3792, Address: 0x244408, Func Offset: 0x58
	// Line 3791, Address: 0x244410, Func Offset: 0x60
	// Line 3792, Address: 0x244414, Func Offset: 0x64
	// Line 3794, Address: 0x24441c, Func Offset: 0x6c
	// Line 3795, Address: 0x24445c, Func Offset: 0xac
	// Line 3800, Address: 0x244460, Func Offset: 0xb0
	// Line 3797, Address: 0x244464, Func Offset: 0xb4
	// Line 3800, Address: 0x244468, Func Offset: 0xb8
	// Line 3795, Address: 0x24446c, Func Offset: 0xbc
	// Line 3796, Address: 0x244470, Func Offset: 0xc0
	// Line 3797, Address: 0x244478, Func Offset: 0xc8
	// Line 3800, Address: 0x24447c, Func Offset: 0xcc
	// Line 3802, Address: 0x244480, Func Offset: 0xd0
	// Line 3803, Address: 0x244488, Func Offset: 0xd8
	// Line 3805, Address: 0x244490, Func Offset: 0xe0
	// Line 3807, Address: 0x24449c, Func Offset: 0xec
	// Line 3811, Address: 0x2444a4, Func Offset: 0xf4
	// Line 3812, Address: 0x2444b0, Func Offset: 0x100
	// Line 3813, Address: 0x2444bc, Func Offset: 0x10c
	// Line 3814, Address: 0x2444d4, Func Offset: 0x124
	// Line 3820, Address: 0x2444f0, Func Offset: 0x140
	// Line 3822, Address: 0x2444fc, Func Offset: 0x14c
	// Line 3820, Address: 0x244504, Func Offset: 0x154
	// Line 3822, Address: 0x244508, Func Offset: 0x158
	// Line 3820, Address: 0x24450c, Func Offset: 0x15c
	// Line 3821, Address: 0x24451c, Func Offset: 0x16c
	// Line 3820, Address: 0x244524, Func Offset: 0x174
	// Line 3822, Address: 0x244528, Func Offset: 0x178
	// Line 3823, Address: 0x244558, Func Offset: 0x1a8
	// Line 3827, Address: 0x24455c, Func Offset: 0x1ac
	// Line 3830, Address: 0x24456c, Func Offset: 0x1bc
	// Line 3835, Address: 0x244574, Func Offset: 0x1c4
	// Line 3830, Address: 0x244584, Func Offset: 0x1d4
	// Line 3831, Address: 0x24458c, Func Offset: 0x1dc
	// Line 3832, Address: 0x24459c, Func Offset: 0x1ec
	// Line 3835, Address: 0x2445ac, Func Offset: 0x1fc
	// Line 3836, Address: 0x2445b8, Func Offset: 0x208
	// Line 3837, Address: 0x2445c4, Func Offset: 0x214
	// Line 3840, Address: 0x2445cc, Func Offset: 0x21c
	// Line 3841, Address: 0x244618, Func Offset: 0x268
	// Line 3844, Address: 0x244664, Func Offset: 0x2b4
	// Line 3846, Address: 0x244684, Func Offset: 0x2d4
	// Line 3844, Address: 0x244688, Func Offset: 0x2d8
	// Line 3846, Address: 0x2446a4, Func Offset: 0x2f4
	// Line 3847, Address: 0x2446c0, Func Offset: 0x310
	// Line 3848, Address: 0x2446d4, Func Offset: 0x324
	// Line 3850, Address: 0x2446f8, Func Offset: 0x348
	// Func End, Address: 0x244708, Func Offset: 0x358
	scePrintf("bhEff_E12_Fire3 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x244710
void bhEff_E12_BintaEffControl(O_WRK* op)
{
	BH_PWORK* ep;
	// Line 3860, Address: 0x244710, Func Offset: 0
	// Line 3863, Address: 0x244720, Func Offset: 0x10
	// Line 3865, Address: 0x244740, Func Offset: 0x30
	// Line 3866, Address: 0x244750, Func Offset: 0x40
	// Line 3868, Address: 0x24475c, Func Offset: 0x4c
	// Line 3869, Address: 0x244764, Func Offset: 0x54
	// Line 3873, Address: 0x24479c, Func Offset: 0x8c
	// Line 3875, Address: 0x2447a8, Func Offset: 0x98
	// Line 3877, Address: 0x2447b0, Func Offset: 0xa0
	// Line 3879, Address: 0x2447bc, Func Offset: 0xac
	// Line 3881, Address: 0x2447c4, Func Offset: 0xb4
	// Line 3886, Address: 0x2447d0, Func Offset: 0xc0
	// Func End, Address: 0x2447e0, Func Offset: 0xd0
	scePrintf("bhEff_E12_BintaEffControl - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2447e0
void bhEff_E13_Fluid(O_WRK* op)
{
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	NJS_POINT3 n;
	UV_WORK* uvtble[4];
	// Line 3896, Address: 0x2447e0, Func Offset: 0
	// Line 3954, Address: 0x2447f4, Func Offset: 0x14
	// Line 3956, Address: 0x244820, Func Offset: 0x40
	// Line 3957, Address: 0x244828, Func Offset: 0x48
	// Line 3960, Address: 0x24482c, Func Offset: 0x4c
	// Line 3956, Address: 0x244830, Func Offset: 0x50
	// Line 3957, Address: 0x244838, Func Offset: 0x58
	// Line 3960, Address: 0x24483c, Func Offset: 0x5c
	// Line 3962, Address: 0x244844, Func Offset: 0x64
	// Line 3963, Address: 0x24484c, Func Offset: 0x6c
	// Line 3965, Address: 0x244854, Func Offset: 0x74
	// Line 3966, Address: 0x244858, Func Offset: 0x78
	// Line 3969, Address: 0x244898, Func Offset: 0xb8
	// Line 3973, Address: 0x24489c, Func Offset: 0xbc
	// Line 3969, Address: 0x2448a0, Func Offset: 0xc0
	// Line 3970, Address: 0x2448a4, Func Offset: 0xc4
	// Line 3972, Address: 0x2448ac, Func Offset: 0xcc
	// Line 3973, Address: 0x2448b0, Func Offset: 0xd0
	// Line 3974, Address: 0x2448b4, Func Offset: 0xd4
	// Line 3975, Address: 0x2448cc, Func Offset: 0xec
	// Line 3976, Address: 0x24490c, Func Offset: 0x12c
	// Line 3977, Address: 0x244914, Func Offset: 0x134
	// Line 3979, Address: 0x244958, Func Offset: 0x178
	// Line 3981, Address: 0x244960, Func Offset: 0x180
	// Line 3983, Address: 0x24497c, Func Offset: 0x19c
	// Line 3985, Address: 0x244984, Func Offset: 0x1a4
	// Line 3987, Address: 0x24498c, Func Offset: 0x1ac
	// Line 3988, Address: 0x244998, Func Offset: 0x1b8
	// Line 3989, Address: 0x2449a8, Func Offset: 0x1c8
	// Line 3990, Address: 0x2449b0, Func Offset: 0x1d0
	// Line 3992, Address: 0x2449b8, Func Offset: 0x1d8
	// Line 3995, Address: 0x2449c0, Func Offset: 0x1e0
	// Line 3996, Address: 0x2449cc, Func Offset: 0x1ec
	// Line 3998, Address: 0x2449dc, Func Offset: 0x1fc
	// Line 4000, Address: 0x2449e4, Func Offset: 0x204
	// Line 4002, Address: 0x244a04, Func Offset: 0x224
	// Line 4003, Address: 0x244a20, Func Offset: 0x240
	// Line 4008, Address: 0x244a2c, Func Offset: 0x24c
	// Line 4011, Address: 0x244a38, Func Offset: 0x258
	// Line 4014, Address: 0x244a40, Func Offset: 0x260
	// Line 4021, Address: 0x244a4c, Func Offset: 0x26c
	// Line 4011, Address: 0x244a50, Func Offset: 0x270
	// Line 4017, Address: 0x244a54, Func Offset: 0x274
	// Line 4022, Address: 0x244a58, Func Offset: 0x278
	// Line 4011, Address: 0x244a5c, Func Offset: 0x27c
	// Line 4012, Address: 0x244a60, Func Offset: 0x280
	// Line 4017, Address: 0x244a68, Func Offset: 0x288
	// Line 4027, Address: 0x244a6c, Func Offset: 0x28c
	// Line 4024, Address: 0x244a70, Func Offset: 0x290
	// Line 4012, Address: 0x244a78, Func Offset: 0x298
	// Line 4027, Address: 0x244a7c, Func Offset: 0x29c
	// Line 4024, Address: 0x244a84, Func Offset: 0x2a4
	// Line 4012, Address: 0x244a88, Func Offset: 0x2a8
	// Line 4013, Address: 0x244a8c, Func Offset: 0x2ac
	// Line 4027, Address: 0x244a94, Func Offset: 0x2b4
	// Line 4013, Address: 0x244a98, Func Offset: 0x2b8
	// Line 4014, Address: 0x244aa0, Func Offset: 0x2c0
	// Line 4016, Address: 0x244aac, Func Offset: 0x2cc
	// Line 4017, Address: 0x244ab4, Func Offset: 0x2d4
	// Line 4018, Address: 0x244ac0, Func Offset: 0x2e0
	// Line 4020, Address: 0x244ac8, Func Offset: 0x2e8
	// Line 4021, Address: 0x244ad0, Func Offset: 0x2f0
	// Line 4022, Address: 0x244adc, Func Offset: 0x2fc
	// Line 4024, Address: 0x244ae4, Func Offset: 0x304
	// Line 4025, Address: 0x244af0, Func Offset: 0x310
	// Line 4027, Address: 0x244af8, Func Offset: 0x318
	// Line 4028, Address: 0x244b08, Func Offset: 0x328
	// Line 4029, Address: 0x244b10, Func Offset: 0x330
	// Line 4030, Address: 0x244b18, Func Offset: 0x338
	// Line 4032, Address: 0x244b3c, Func Offset: 0x35c
	// Line 4033, Address: 0x244b44, Func Offset: 0x364
	// Line 4034, Address: 0x244b48, Func Offset: 0x368
	// Line 4035, Address: 0x244b4c, Func Offset: 0x36c
	// Line 4038, Address: 0x244b50, Func Offset: 0x370
	// Line 4039, Address: 0x244b54, Func Offset: 0x374
	// Line 4038, Address: 0x244b60, Func Offset: 0x380
	// Line 4039, Address: 0x244b64, Func Offset: 0x384
	// Line 4040, Address: 0x244b70, Func Offset: 0x390
	// Line 4046, Address: 0x244b78, Func Offset: 0x398
	// Line 4049, Address: 0x244bac, Func Offset: 0x3cc
	// Line 4050, Address: 0x244bcc, Func Offset: 0x3ec
	// Line 4051, Address: 0x244be0, Func Offset: 0x400
	// Line 4053, Address: 0x244c04, Func Offset: 0x424
	// Func End, Address: 0x244c1c, Func Offset: 0x43c
	scePrintf("bhEff_E13_Fluid - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x244c20
void bhEff_E14_Explosion(O_WRK* op)
{
	// Line 4063, Address: 0x244c20, Func Offset: 0
	// Line 4064, Address: 0x244c2c, Func Offset: 0xc
	// Line 4066, Address: 0x244c4c, Func Offset: 0x2c
	// Line 4067, Address: 0x244c54, Func Offset: 0x34
	// Line 4066, Address: 0x244c58, Func Offset: 0x38
	// Line 4067, Address: 0x244c5c, Func Offset: 0x3c
	// Line 4070, Address: 0x244c60, Func Offset: 0x40
	// Line 4066, Address: 0x244c64, Func Offset: 0x44
	// Line 4067, Address: 0x244c70, Func Offset: 0x50
	// Line 4078, Address: 0x244c78, Func Offset: 0x58
	// Line 4067, Address: 0x244c84, Func Offset: 0x64
	// Line 4068, Address: 0x244c90, Func Offset: 0x70
	// Line 4069, Address: 0x244ca4, Func Offset: 0x84
	// Line 4070, Address: 0x244cb8, Func Offset: 0x98
	// Line 4071, Address: 0x244ccc, Func Offset: 0xac
	// Line 4072, Address: 0x244ce0, Func Offset: 0xc0
	// Line 4073, Address: 0x244cf4, Func Offset: 0xd4
	// Line 4074, Address: 0x244d0c, Func Offset: 0xec
	// Line 4075, Address: 0x244d24, Func Offset: 0x104
	// Line 4076, Address: 0x244d3c, Func Offset: 0x11c
	// Line 4077, Address: 0x244d50, Func Offset: 0x130
	// Line 4078, Address: 0x244d64, Func Offset: 0x144
	// Line 4080, Address: 0x244d7c, Func Offset: 0x15c
	// Line 4081, Address: 0x244d84, Func Offset: 0x164
	// Line 4080, Address: 0x244d88, Func Offset: 0x168
	// Line 4081, Address: 0x244d8c, Func Offset: 0x16c
	// Line 4082, Address: 0x244d90, Func Offset: 0x170
	// Line 4080, Address: 0x244d94, Func Offset: 0x174
	// Line 4081, Address: 0x244da0, Func Offset: 0x180
	// Line 4084, Address: 0x244da8, Func Offset: 0x188
	// Line 4092, Address: 0x244dac, Func Offset: 0x18c
	// Line 4081, Address: 0x244db8, Func Offset: 0x198
	// Line 4082, Address: 0x244dc4, Func Offset: 0x1a4
	// Line 4083, Address: 0x244dd8, Func Offset: 0x1b8
	// Line 4084, Address: 0x244dec, Func Offset: 0x1cc
	// Line 4085, Address: 0x244e00, Func Offset: 0x1e0
	// Line 4086, Address: 0x244e14, Func Offset: 0x1f4
	// Line 4087, Address: 0x244e28, Func Offset: 0x208
	// Line 4088, Address: 0x244e40, Func Offset: 0x220
	// Line 4089, Address: 0x244e58, Func Offset: 0x238
	// Line 4090, Address: 0x244e70, Func Offset: 0x250
	// Line 4091, Address: 0x244e84, Func Offset: 0x264
	// Line 4092, Address: 0x244e98, Func Offset: 0x278
	// Line 4094, Address: 0x244eb0, Func Offset: 0x290
	// Line 4095, Address: 0x244eb4, Func Offset: 0x294
	// Line 4096, Address: 0x244ebc, Func Offset: 0x29c
	// Line 4098, Address: 0x244ec4, Func Offset: 0x2a4
	// Line 4099, Address: 0x244ed0, Func Offset: 0x2b0
	// Line 4100, Address: 0x244ee0, Func Offset: 0x2c0
	// Line 4101, Address: 0x244ee8, Func Offset: 0x2c8
	// Line 4104, Address: 0x244ef0, Func Offset: 0x2d0
	// Line 4100, Address: 0x244ef4, Func Offset: 0x2d4
	// Line 4104, Address: 0x244f04, Func Offset: 0x2e4
	// Line 4101, Address: 0x244f08, Func Offset: 0x2e8
	// Line 4112, Address: 0x244f10, Func Offset: 0x2f0
	// Line 4101, Address: 0x244f1c, Func Offset: 0x2fc
	// Line 4102, Address: 0x244f28, Func Offset: 0x308
	// Line 4103, Address: 0x244f3c, Func Offset: 0x31c
	// Line 4104, Address: 0x244f50, Func Offset: 0x330
	// Line 4105, Address: 0x244f64, Func Offset: 0x344
	// Line 4106, Address: 0x244f78, Func Offset: 0x358
	// Line 4107, Address: 0x244f8c, Func Offset: 0x36c
	// Line 4108, Address: 0x244fb0, Func Offset: 0x390
	// Line 4109, Address: 0x244fd4, Func Offset: 0x3b4
	// Line 4110, Address: 0x244ff8, Func Offset: 0x3d8
	// Line 4111, Address: 0x24500c, Func Offset: 0x3ec
	// Line 4112, Address: 0x245020, Func Offset: 0x400
	// Line 4114, Address: 0x245038, Func Offset: 0x418
	// Line 4118, Address: 0x24503c, Func Offset: 0x41c
	// Func End, Address: 0x24504c, Func Offset: 0x42c
	scePrintf("bhEff_E14_Explosion - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x245050
void bhEff_E14_Fire(O_WRK* op)
{
	NJS_POINT3 ofp;
	int i;
	float ln;
	//_anon19* lp;
	UV_WORK* uvp;
	UV_WORK* uvtble[2];
	// Line 4128, Address: 0x245050, Func Offset: 0
	// Line 4160, Address: 0x245064, Func Offset: 0x14
	// Line 4162, Address: 0x2450a8, Func Offset: 0x58
	// Line 4164, Address: 0x2450b0, Func Offset: 0x60
	// Line 4163, Address: 0x2450b4, Func Offset: 0x64
	// Line 4164, Address: 0x2450b8, Func Offset: 0x68
	// Line 4167, Address: 0x2450c0, Func Offset: 0x70
	// Line 4168, Address: 0x2450c8, Func Offset: 0x78
	// Line 4169, Address: 0x2450d0, Func Offset: 0x80
	// Line 4170, Address: 0x2450d8, Func Offset: 0x88
	// Line 4169, Address: 0x2450dc, Func Offset: 0x8c
	// Line 4170, Address: 0x2450e0, Func Offset: 0x90
	// Line 4172, Address: 0x2450e8, Func Offset: 0x98
	// Line 4173, Address: 0x245124, Func Offset: 0xd4
	// Line 4175, Address: 0x245164, Func Offset: 0x114
	// Line 4178, Address: 0x245168, Func Offset: 0x118
	// Line 4175, Address: 0x24516c, Func Offset: 0x11c
	// Line 4176, Address: 0x245170, Func Offset: 0x120
	// Line 4178, Address: 0x245178, Func Offset: 0x128
	// Line 4180, Address: 0x24517c, Func Offset: 0x12c
	// Line 4182, Address: 0x2451bc, Func Offset: 0x16c
	// Line 4183, Address: 0x2451c8, Func Offset: 0x178
	// Line 4186, Address: 0x2451d0, Func Offset: 0x180
	// Line 4188, Address: 0x2451e0, Func Offset: 0x190
	// Line 4189, Address: 0x2451f0, Func Offset: 0x1a0
	// Line 4191, Address: 0x245200, Func Offset: 0x1b0
	// Line 4192, Address: 0x245204, Func Offset: 0x1b4
	// Line 4193, Address: 0x245208, Func Offset: 0x1b8
	// Line 4194, Address: 0x24520c, Func Offset: 0x1bc
	// Line 4195, Address: 0x245210, Func Offset: 0x1c0
	// Line 4197, Address: 0x245214, Func Offset: 0x1c4
	// Line 4199, Address: 0x245218, Func Offset: 0x1c8
	// Line 4200, Address: 0x24521c, Func Offset: 0x1cc
	// Line 4202, Address: 0x245220, Func Offset: 0x1d0
	// Line 4197, Address: 0x245224, Func Offset: 0x1d4
	// Line 4198, Address: 0x24522c, Func Offset: 0x1dc
	// Line 4212, Address: 0x245230, Func Offset: 0x1e0
	// Line 4203, Address: 0x245238, Func Offset: 0x1e8
	// Line 4204, Address: 0x24523c, Func Offset: 0x1ec
	// Line 4211, Address: 0x245240, Func Offset: 0x1f0
	// Line 4198, Address: 0x245244, Func Offset: 0x1f4
	// Line 4199, Address: 0x24524c, Func Offset: 0x1fc
	// Line 4200, Address: 0x245250, Func Offset: 0x200
	// Line 4201, Address: 0x245254, Func Offset: 0x204
	// Line 4202, Address: 0x245258, Func Offset: 0x208
	// Line 4203, Address: 0x24525c, Func Offset: 0x20c
	// Line 4204, Address: 0x245260, Func Offset: 0x210
	// Line 4205, Address: 0x245264, Func Offset: 0x214
	// Line 4213, Address: 0x24526c, Func Offset: 0x21c
	// Line 4205, Address: 0x245274, Func Offset: 0x224
	// Line 4206, Address: 0x24527c, Func Offset: 0x22c
	// Line 4207, Address: 0x24528c, Func Offset: 0x23c
	// Line 4208, Address: 0x24529c, Func Offset: 0x24c
	// Line 4209, Address: 0x2452b0, Func Offset: 0x260
	// Line 4210, Address: 0x2452c4, Func Offset: 0x274
	// Line 4211, Address: 0x2452d8, Func Offset: 0x288
	// Line 4212, Address: 0x2452dc, Func Offset: 0x28c
	// Line 4213, Address: 0x2452e0, Func Offset: 0x290
	// Line 4216, Address: 0x2452e4, Func Offset: 0x294
	// Line 4220, Address: 0x2452e8, Func Offset: 0x298
	// Line 4226, Address: 0x2452f0, Func Offset: 0x2a0
	// Line 4216, Address: 0x2452f4, Func Offset: 0x2a4
	// Line 4217, Address: 0x2452fc, Func Offset: 0x2ac
	// Line 4220, Address: 0x245300, Func Offset: 0x2b0
	// Line 4226, Address: 0x245304, Func Offset: 0x2b4
	// Line 4227, Address: 0x24532c, Func Offset: 0x2dc
	// Line 4228, Address: 0x245354, Func Offset: 0x304
	// Line 4233, Address: 0x245378, Func Offset: 0x328
	// Line 4234, Address: 0x245388, Func Offset: 0x338
	// Line 4236, Address: 0x245390, Func Offset: 0x340
	// Line 4242, Address: 0x245394, Func Offset: 0x344
	// Line 4234, Address: 0x245398, Func Offset: 0x348
	// Line 4236, Address: 0x24539c, Func Offset: 0x34c
	// Line 4234, Address: 0x2453a0, Func Offset: 0x350
	// Line 4236, Address: 0x2453a8, Func Offset: 0x358
	// Line 4237, Address: 0x2453b0, Func Offset: 0x360
	// Line 4238, Address: 0x2453bc, Func Offset: 0x36c
	// Line 4237, Address: 0x2453c0, Func Offset: 0x370
	// Line 4238, Address: 0x2453c4, Func Offset: 0x374
	// Line 4239, Address: 0x2453cc, Func Offset: 0x37c
	// Line 4243, Address: 0x2453e0, Func Offset: 0x390
	// Line 4244, Address: 0x245420, Func Offset: 0x3d0
	// Line 4245, Address: 0x245464, Func Offset: 0x414
	// Line 4246, Address: 0x245490, Func Offset: 0x440
	// Line 4247, Address: 0x245524, Func Offset: 0x4d4
	// Line 4252, Address: 0x245534, Func Offset: 0x4e4
	// Line 4253, Address: 0x245538, Func Offset: 0x4e8
	// Line 4254, Address: 0x245548, Func Offset: 0x4f8
	// Line 4253, Address: 0x24554c, Func Offset: 0x4fc
	// Line 4254, Address: 0x245550, Func Offset: 0x500
	// Line 4255, Address: 0x245568, Func Offset: 0x518
	// Line 4256, Address: 0x24556c, Func Offset: 0x51c
	// Line 4258, Address: 0x245574, Func Offset: 0x524
	// Line 4261, Address: 0x24557c, Func Offset: 0x52c
	// Line 4262, Address: 0x24558c, Func Offset: 0x53c
	// Line 4265, Address: 0x245598, Func Offset: 0x548
	// Line 4267, Address: 0x2455a8, Func Offset: 0x558
	// Line 4271, Address: 0x2455b0, Func Offset: 0x560
	// Line 4267, Address: 0x2455b4, Func Offset: 0x564
	// Line 4271, Address: 0x2455b8, Func Offset: 0x568
	// Line 4269, Address: 0x2455bc, Func Offset: 0x56c
	// Line 4267, Address: 0x2455c0, Func Offset: 0x570
	// Line 4268, Address: 0x2455cc, Func Offset: 0x57c
	// Line 4275, Address: 0x2455d4, Func Offset: 0x584
	// Line 4268, Address: 0x2455e0, Func Offset: 0x590
	// Line 4269, Address: 0x2455ec, Func Offset: 0x59c
	// Line 4270, Address: 0x245600, Func Offset: 0x5b0
	// Line 4271, Address: 0x245618, Func Offset: 0x5c8
	// Line 4272, Address: 0x245634, Func Offset: 0x5e4
	// Line 4273, Address: 0x24564c, Func Offset: 0x5fc
	// Line 4274, Address: 0x245660, Func Offset: 0x610
	// Line 4275, Address: 0x245674, Func Offset: 0x624
	// Line 4278, Address: 0x24568c, Func Offset: 0x63c
	// Line 4280, Address: 0x2456cc, Func Offset: 0x67c
	// Line 4282, Address: 0x2456d4, Func Offset: 0x684
	// Line 4283, Address: 0x2456e4, Func Offset: 0x694
	// Line 4282, Address: 0x2456e8, Func Offset: 0x698
	// Line 4283, Address: 0x2456ec, Func Offset: 0x69c
	// Line 4284, Address: 0x2456f0, Func Offset: 0x6a0
	// Line 4282, Address: 0x2456f8, Func Offset: 0x6a8
	// Line 4283, Address: 0x2456fc, Func Offset: 0x6ac
	// Line 4284, Address: 0x245704, Func Offset: 0x6b4
	// Line 4283, Address: 0x24570c, Func Offset: 0x6bc
	// Line 4284, Address: 0x245714, Func Offset: 0x6c4
	// Line 4285, Address: 0x245728, Func Offset: 0x6d8
	// Line 4286, Address: 0x24572c, Func Offset: 0x6dc
	// Line 4287, Address: 0x245738, Func Offset: 0x6e8
	// Line 4288, Address: 0x245740, Func Offset: 0x6f0
	// Line 4290, Address: 0x245748, Func Offset: 0x6f8
	// Line 4292, Address: 0x245750, Func Offset: 0x700
	// Line 4293, Address: 0x245754, Func Offset: 0x704
	// Line 4294, Address: 0x245760, Func Offset: 0x710
	// Line 4292, Address: 0x245764, Func Offset: 0x714
	// Line 4293, Address: 0x24576c, Func Offset: 0x71c
	// Line 4294, Address: 0x245770, Func Offset: 0x720
	// Line 4293, Address: 0x24577c, Func Offset: 0x72c
	// Line 4294, Address: 0x245784, Func Offset: 0x734
	// Line 4295, Address: 0x245790, Func Offset: 0x740
	// Line 4296, Address: 0x24579c, Func Offset: 0x74c
	// Line 4298, Address: 0x2457a8, Func Offset: 0x758
	// Line 4300, Address: 0x2457b0, Func Offset: 0x760
	// Line 4301, Address: 0x2457b8, Func Offset: 0x768
	// Line 4304, Address: 0x2457c0, Func Offset: 0x770
	// Line 4309, Address: 0x2457d4, Func Offset: 0x784
	// Line 4311, Address: 0x2457e0, Func Offset: 0x790
	// Line 4309, Address: 0x2457e8, Func Offset: 0x798
	// Line 4311, Address: 0x2457ec, Func Offset: 0x79c
	// Line 4309, Address: 0x2457f0, Func Offset: 0x7a0
	// Line 4310, Address: 0x245800, Func Offset: 0x7b0
	// Line 4309, Address: 0x245808, Func Offset: 0x7b8
	// Line 4311, Address: 0x24580c, Func Offset: 0x7bc
	// Line 4312, Address: 0x24583c, Func Offset: 0x7ec
	// Line 4316, Address: 0x245840, Func Offset: 0x7f0
	// Line 4317, Address: 0x245850, Func Offset: 0x800
	// Line 4321, Address: 0x245858, Func Offset: 0x808
	// Line 4317, Address: 0x24585c, Func Offset: 0x80c
	// Line 4318, Address: 0x245864, Func Offset: 0x814
	// Line 4321, Address: 0x245874, Func Offset: 0x824
	// Line 4323, Address: 0x245888, Func Offset: 0x838
	// Line 4324, Address: 0x2458a8, Func Offset: 0x858
	// Line 4325, Address: 0x2458bc, Func Offset: 0x86c
	// Line 4327, Address: 0x2458e0, Func Offset: 0x890
	// Func End, Address: 0x2458f8, Func Offset: 0x8a8
	scePrintf("bhEff_E14_Fire - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x245900
void bhEff_E14_Fire2(O_WRK* op)
{
	UV_WORK* uvp;
	UV_WORK* uvtble[1];
	// Line 4337, Address: 0x245900, Func Offset: 0
	// Line 4357, Address: 0x24590c, Func Offset: 0xc
	// Line 4359, Address: 0x24592c, Func Offset: 0x2c
	// Line 4360, Address: 0x245938, Func Offset: 0x38
	// Line 4361, Address: 0x24593c, Func Offset: 0x3c
	// Line 4359, Address: 0x245940, Func Offset: 0x40
	// Line 4360, Address: 0x245948, Func Offset: 0x48
	// Line 4361, Address: 0x24594c, Func Offset: 0x4c
	// Line 4362, Address: 0x245950, Func Offset: 0x50
	// Line 4363, Address: 0x245958, Func Offset: 0x58
	// Line 4365, Address: 0x24595c, Func Offset: 0x5c
	// Line 4362, Address: 0x245960, Func Offset: 0x60
	// Line 4365, Address: 0x245968, Func Offset: 0x68
	// Line 4368, Address: 0x245970, Func Offset: 0x70
	// Line 4369, Address: 0x2459b0, Func Offset: 0xb0
	// Line 4370, Address: 0x2459f4, Func Offset: 0xf4
	// Line 4371, Address: 0x245a20, Func Offset: 0x120
	// Line 4372, Address: 0x245a28, Func Offset: 0x128
	// Line 4374, Address: 0x245a2c, Func Offset: 0x12c
	// Line 4376, Address: 0x245a30, Func Offset: 0x130
	// Line 4371, Address: 0x245a34, Func Offset: 0x134
	// Line 4372, Address: 0x245a38, Func Offset: 0x138
	// Line 4374, Address: 0x245a3c, Func Offset: 0x13c
	// Line 4375, Address: 0x245a40, Func Offset: 0x140
	// Line 4376, Address: 0x245a44, Func Offset: 0x144
	// Line 4377, Address: 0x245a48, Func Offset: 0x148
	// Line 4378, Address: 0x245a4c, Func Offset: 0x14c
	// Line 4380, Address: 0x245a50, Func Offset: 0x150
	// Line 4381, Address: 0x245a58, Func Offset: 0x158
	// Line 4383, Address: 0x245a60, Func Offset: 0x160
	// Line 4385, Address: 0x245a6c, Func Offset: 0x16c
	// Line 4389, Address: 0x245a74, Func Offset: 0x174
	// Line 4390, Address: 0x245aa4, Func Offset: 0x1a4
	// Line 4394, Address: 0x245ab8, Func Offset: 0x1b8
	// Line 4396, Address: 0x245ac4, Func Offset: 0x1c4
	// Line 4394, Address: 0x245acc, Func Offset: 0x1cc
	// Line 4396, Address: 0x245ad0, Func Offset: 0x1d0
	// Line 4394, Address: 0x245ad4, Func Offset: 0x1d4
	// Line 4395, Address: 0x245ae4, Func Offset: 0x1e4
	// Line 4394, Address: 0x245aec, Func Offset: 0x1ec
	// Line 4396, Address: 0x245af0, Func Offset: 0x1f0
	// Line 4397, Address: 0x245b20, Func Offset: 0x220
	// Line 4401, Address: 0x245b24, Func Offset: 0x224
	// Line 4403, Address: 0x245b34, Func Offset: 0x234
	// Line 4404, Address: 0x245b54, Func Offset: 0x254
	// Line 4405, Address: 0x245b68, Func Offset: 0x268
	// Line 4407, Address: 0x245b8c, Func Offset: 0x28c
	// Func End, Address: 0x245b9c, Func Offset: 0x29c
	scePrintf("bhEff_E14_Fire2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x245ba0
void bhEff_E14_Mucus(O_WRK* op)
{
	NJS_POINT3 v;
	//NJS_POINT3 v;
	int i;
	BH_PWORK* ep;
	UV_WORK* uvp;
	UV_WORK* uvtble[3];
	// Line 4417, Address: 0x245ba0, Func Offset: 0
	// Line 4486, Address: 0x245bb8, Func Offset: 0x18
	// Line 4489, Address: 0x245bec, Func Offset: 0x4c
	// Line 4491, Address: 0x245bf0, Func Offset: 0x50
	// Line 4492, Address: 0x245bfc, Func Offset: 0x5c
	// Line 4493, Address: 0x245c04, Func Offset: 0x64
	// Line 4494, Address: 0x245c0c, Func Offset: 0x6c
	// Line 4505, Address: 0x245c10, Func Offset: 0x70
	// Line 4494, Address: 0x245c18, Func Offset: 0x78
	// Line 4506, Address: 0x245c1c, Func Offset: 0x7c
	// Line 4494, Address: 0x245c20, Func Offset: 0x80
	// Line 4497, Address: 0x245c28, Func Offset: 0x88
	// Line 4498, Address: 0x245c2c, Func Offset: 0x8c
	// Line 4506, Address: 0x245c30, Func Offset: 0x90
	// Line 4507, Address: 0x245c4c, Func Offset: 0xac
	// Line 4509, Address: 0x245c68, Func Offset: 0xc8
	// Line 4511, Address: 0x245c70, Func Offset: 0xd0
	// Line 4515, Address: 0x245c88, Func Offset: 0xe8
	// Line 4517, Address: 0x245c94, Func Offset: 0xf4
	// Line 4520, Address: 0x245ca0, Func Offset: 0x100
	// Line 4521, Address: 0x245cac, Func Offset: 0x10c
	// Line 4520, Address: 0x245cb0, Func Offset: 0x110
	// Line 4521, Address: 0x245cb4, Func Offset: 0x114
	// Line 4522, Address: 0x245cbc, Func Offset: 0x11c
	// Line 4524, Address: 0x245cc4, Func Offset: 0x124
	// Line 4528, Address: 0x245ccc, Func Offset: 0x12c
	// Line 4530, Address: 0x245cd8, Func Offset: 0x138
	// Line 4528, Address: 0x245cdc, Func Offset: 0x13c
	// Line 4529, Address: 0x245cf4, Func Offset: 0x154
	// Line 4528, Address: 0x245cf8, Func Offset: 0x158
	// Line 4529, Address: 0x245cfc, Func Offset: 0x15c
	// Line 4530, Address: 0x245d00, Func Offset: 0x160
	// Line 4531, Address: 0x245d24, Func Offset: 0x184
	// Line 4539, Address: 0x245d30, Func Offset: 0x190
	// Line 4545, Address: 0x245d3c, Func Offset: 0x19c
	// Line 4546, Address: 0x245d44, Func Offset: 0x1a4
	// Line 4547, Address: 0x245d50, Func Offset: 0x1b0
	// Line 4550, Address: 0x245d54, Func Offset: 0x1b4
	// Line 4548, Address: 0x245d58, Func Offset: 0x1b8
	// Line 4549, Address: 0x245d5c, Func Offset: 0x1bc
	// Line 4547, Address: 0x245d60, Func Offset: 0x1c0
	// Line 4548, Address: 0x245d64, Func Offset: 0x1c4
	// Line 4550, Address: 0x245d68, Func Offset: 0x1c8
	// Line 4551, Address: 0x245d78, Func Offset: 0x1d8
	// Line 4567, Address: 0x245d80, Func Offset: 0x1e0
	// Line 4551, Address: 0x245d84, Func Offset: 0x1e4
	// Line 4552, Address: 0x245d8c, Func Offset: 0x1ec
	// Line 4553, Address: 0x245d9c, Func Offset: 0x1fc
	// Line 4554, Address: 0x245dac, Func Offset: 0x20c
	// Line 4555, Address: 0x245dbc, Func Offset: 0x21c
	// Line 4556, Address: 0x245dcc, Func Offset: 0x22c
	// Line 4567, Address: 0x245ddc, Func Offset: 0x23c
	// Line 4568, Address: 0x245e04, Func Offset: 0x264
	// Line 4569, Address: 0x245e18, Func Offset: 0x278
	// Line 4571, Address: 0x245e24, Func Offset: 0x284
	// Line 4572, Address: 0x245e28, Func Offset: 0x288
	// Line 4573, Address: 0x245e2c, Func Offset: 0x28c
	// Line 4574, Address: 0x245e30, Func Offset: 0x290
	// Line 4571, Address: 0x245e34, Func Offset: 0x294
	// Line 4572, Address: 0x245e38, Func Offset: 0x298
	// Line 4574, Address: 0x245e3c, Func Offset: 0x29c
	// Line 4575, Address: 0x245e4c, Func Offset: 0x2ac
	// Line 4578, Address: 0x245e50, Func Offset: 0x2b0
	// Line 4575, Address: 0x245e5c, Func Offset: 0x2bc
	// Line 4576, Address: 0x245e64, Func Offset: 0x2c4
	// Line 4578, Address: 0x245e68, Func Offset: 0x2c8
	// Line 4582, Address: 0x245e70, Func Offset: 0x2d0
	// Line 4585, Address: 0x245e84, Func Offset: 0x2e4
	// Line 4586, Address: 0x245ea4, Func Offset: 0x304
	// Line 4587, Address: 0x245eb8, Func Offset: 0x318
	// Line 4589, Address: 0x245edc, Func Offset: 0x33c
	// Func End, Address: 0x245ef8, Func Offset: 0x358
	scePrintf("bhEff_E14_Mucus - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x245f00
void bhEff_E14_MucusDraw(O_WRK* op)
{
	// Line 4599, Address: 0x245f00, Func Offset: 0
	// Line 4602, Address: 0x245f0c, Func Offset: 0xc
	// Line 4604, Address: 0x245f34, Func Offset: 0x34
	// Line 4608, Address: 0x245f3c, Func Offset: 0x3c
	// Line 4611, Address: 0x245f48, Func Offset: 0x48
	// Line 4614, Address: 0x245f50, Func Offset: 0x50
	// Line 4616, Address: 0x245f68, Func Offset: 0x68
	// Line 4619, Address: 0x245f94, Func Offset: 0x94
	// Line 4620, Address: 0x245fa0, Func Offset: 0xa0
	// Line 4623, Address: 0x245fac, Func Offset: 0xac
	// Line 4626, Address: 0x245fbc, Func Offset: 0xbc
	// Line 4628, Address: 0x245fc8, Func Offset: 0xc8
	// Line 4631, Address: 0x245fd4, Func Offset: 0xd4
	// Func End, Address: 0x245fe4, Func Offset: 0xe4
	scePrintf("bhEff_E14_MucusDraw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x245ff0
void bhEff_DamagePoint(O_WRK* op)
{
	// Line 4641, Address: 0x245ff0, Func Offset: 0
	// Line 4642, Address: 0x246000, Func Offset: 0x10
	// Line 4644, Address: 0x24602c, Func Offset: 0x3c
	// Line 4645, Address: 0x246038, Func Offset: 0x48
	// Line 4646, Address: 0x246040, Func Offset: 0x50
	// Line 4647, Address: 0x246048, Func Offset: 0x58
	// Line 4648, Address: 0x24606c, Func Offset: 0x7c
	// Line 4649, Address: 0x246074, Func Offset: 0x84
	// Line 4651, Address: 0x24607c, Func Offset: 0x8c
	// Line 4652, Address: 0x246084, Func Offset: 0x94
	// Line 4651, Address: 0x246094, Func Offset: 0xa4
	// Line 4652, Address: 0x24609c, Func Offset: 0xac
	// Line 4653, Address: 0x2460a8, Func Offset: 0xb8
	// Line 4654, Address: 0x2460c0, Func Offset: 0xd0
	// Line 4655, Address: 0x2460d0, Func Offset: 0xe0
	// Line 4656, Address: 0x2460d4, Func Offset: 0xe4
	// Line 4655, Address: 0x2460d8, Func Offset: 0xe8
	// Line 4656, Address: 0x2460e0, Func Offset: 0xf0
	// Line 4658, Address: 0x2460e4, Func Offset: 0xf4
	// Line 4659, Address: 0x2460f4, Func Offset: 0x104
	// Line 4658, Address: 0x2460f8, Func Offset: 0x108
	// Line 4659, Address: 0x2460fc, Func Offset: 0x10c
	// Line 4658, Address: 0x246100, Func Offset: 0x110
	// Line 4659, Address: 0x246104, Func Offset: 0x114
	// Line 4661, Address: 0x246120, Func Offset: 0x130
	// Line 4663, Address: 0x246128, Func Offset: 0x138
	// Line 4665, Address: 0x246138, Func Offset: 0x148
	// Line 4669, Address: 0x246140, Func Offset: 0x150
	// Line 4670, Address: 0x246160, Func Offset: 0x170
	// Line 4671, Address: 0x246174, Func Offset: 0x184
	// Line 4673, Address: 0x246198, Func Offset: 0x1a8
	// Func End, Address: 0x2461a8, Func Offset: 0x1b8
	scePrintf("bhEff_DamagePoint - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff_DamagePointDraw(O_WRK* op)
{
    NJS_POINT2 pos;

    njProjectScreen(cam.mtx, (NJS_POINT3*)&op->px, &pos);
}

// 
// Start address: 0x2461e0
void bhEff_Draw3DSprite(O_WRK* op)
{
	NJS_POINT3 vec;
	NJS_POINT3 pc;
	NJS_POINT3 pb;
	NJS_POINT3 pa;
	// Line 4702, Address: 0x2461e0, Func Offset: 0
	// Line 4706, Address: 0x2461ec, Func Offset: 0xc
	// Line 4707, Address: 0x2461f4, Func Offset: 0x14
	// Line 4710, Address: 0x246204, Func Offset: 0x24
	// Line 4713, Address: 0x24620c, Func Offset: 0x2c
	// Line 4714, Address: 0x246220, Func Offset: 0x40
	// Line 4716, Address: 0x246230, Func Offset: 0x50
	// Line 4719, Address: 0x24623c, Func Offset: 0x5c
	// Line 4720, Address: 0x24624c, Func Offset: 0x6c
	// Line 4721, Address: 0x246264, Func Offset: 0x84
	// Line 4722, Address: 0x246290, Func Offset: 0xb0
	// Line 4723, Address: 0x246298, Func Offset: 0xb8
	// Line 4724, Address: 0x2462a0, Func Offset: 0xc0
	// Line 4728, Address: 0x2462b0, Func Offset: 0xd0
	// Line 4729, Address: 0x2462b8, Func Offset: 0xd8
	// Line 4731, Address: 0x2462d8, Func Offset: 0xf8
	// Line 4732, Address: 0x2462e4, Func Offset: 0x104
	// Line 4733, Address: 0x2462ec, Func Offset: 0x10c
	// Line 4734, Address: 0x2462f8, Func Offset: 0x118
	// Line 4735, Address: 0x246300, Func Offset: 0x120
	// Line 4739, Address: 0x246308, Func Offset: 0x128
	// Line 4740, Address: 0x246334, Func Offset: 0x154
	// Line 4741, Address: 0x246348, Func Offset: 0x168
	// Line 4743, Address: 0x24635c, Func Offset: 0x17c
	// Line 4744, Address: 0x246364, Func Offset: 0x184
	// Line 4745, Address: 0x246370, Func Offset: 0x190
	// Line 4746, Address: 0x246384, Func Offset: 0x1a4
	// Line 4747, Address: 0x24638c, Func Offset: 0x1ac
	// Line 4748, Address: 0x246398, Func Offset: 0x1b8
	// Line 4749, Address: 0x2463b0, Func Offset: 0x1d0
	// Line 4750, Address: 0x2463dc, Func Offset: 0x1fc
	// Line 4753, Address: 0x246410, Func Offset: 0x230
	// Line 4756, Address: 0x24641c, Func Offset: 0x23c
	// Line 4759, Address: 0x246430, Func Offset: 0x250
	// Line 4760, Address: 0x246440, Func Offset: 0x260
	// Line 4761, Address: 0x246454, Func Offset: 0x274
	// Line 4762, Address: 0x246468, Func Offset: 0x288
	// Line 4763, Address: 0x246478, Func Offset: 0x298
	// Line 4764, Address: 0x24648c, Func Offset: 0x2ac
	// Line 4765, Address: 0x2464a0, Func Offset: 0x2c0
	// Line 4766, Address: 0x2464b4, Func Offset: 0x2d4
	// Line 4767, Address: 0x2464bc, Func Offset: 0x2dc
	// Line 4768, Address: 0x2464d8, Func Offset: 0x2f8
	// Line 4769, Address: 0x2464e0, Func Offset: 0x300
	// Line 4770, Address: 0x2464e8, Func Offset: 0x308
	// Line 4772, Address: 0x2464f0, Func Offset: 0x310
	// Line 4788, Address: 0x246500, Func Offset: 0x320
	// Line 4789, Address: 0x24650c, Func Offset: 0x32c
	// Line 4792, Address: 0x246518, Func Offset: 0x338
	// Line 4794, Address: 0x246528, Func Offset: 0x348
	// Line 4796, Address: 0x246534, Func Offset: 0x354
	// Line 4798, Address: 0x246540, Func Offset: 0x360
	// Line 4800, Address: 0x246548, Func Offset: 0x368
	// Line 4801, Address: 0x246568, Func Offset: 0x388
	// Func End, Address: 0x246578, Func Offset: 0x398
	scePrintf("bhEff_Draw3DSprite - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x246580
void bhEff_SetUVInfo(O_WRK* op, UV_WORK* uvp, float BaseSize)
{
	// Line 4814, Address: 0x246580, Func Offset: 0
	// Line 4815, Address: 0x246588, Func Offset: 0x8
	// Line 4816, Address: 0x246590, Func Offset: 0x10
	// Line 4817, Address: 0x2465a0, Func Offset: 0x20
	// Line 4818, Address: 0x2465a8, Func Offset: 0x28
	// Line 4819, Address: 0x2465b0, Func Offset: 0x30
	// Line 4820, Address: 0x2465c0, Func Offset: 0x40
	// Line 4821, Address: 0x2465c8, Func Offset: 0x48
	// Line 4822, Address: 0x2465d0, Func Offset: 0x50
	// Line 4823, Address: 0x2465e4, Func Offset: 0x64
	// Line 4824, Address: 0x2465fc, Func Offset: 0x7c
	// Func End, Address: 0x246604, Func Offset: 0x84
	scePrintf("bhEff_SetUVInfo - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x246610
void bhEff_SetAlign(O_WRK* op, unsigned int flg)
{
	// Line 4837, Address: 0x246610, Func Offset: 0
	// Line 4838, Address: 0x24661c, Func Offset: 0xc
	// Line 4839, Address: 0x246628, Func Offset: 0x18
	// Line 4840, Address: 0x246630, Func Offset: 0x20
	// Line 4841, Address: 0x246634, Func Offset: 0x24
	// Line 4843, Address: 0x246638, Func Offset: 0x28
	// Line 4844, Address: 0x24664c, Func Offset: 0x3c
	// Line 4845, Address: 0x246650, Func Offset: 0x40
	// Line 4846, Address: 0x246654, Func Offset: 0x44
	// Line 4848, Address: 0x24665c, Func Offset: 0x4c
	// Line 4849, Address: 0x246664, Func Offset: 0x54
	// Line 4850, Address: 0x24666c, Func Offset: 0x5c
	// Line 4851, Address: 0x246670, Func Offset: 0x60
	// Line 4854, Address: 0x246678, Func Offset: 0x68
	// Line 4855, Address: 0x246680, Func Offset: 0x70
	// Line 4856, Address: 0x24668c, Func Offset: 0x7c
	// Line 4857, Address: 0x246690, Func Offset: 0x80
	// Line 4858, Address: 0x246694, Func Offset: 0x84
	// Line 4860, Address: 0x24669c, Func Offset: 0x8c
	// Line 4861, Address: 0x2466b0, Func Offset: 0xa0
	// Line 4862, Address: 0x2466b8, Func Offset: 0xa8
	// Line 4863, Address: 0x2466bc, Func Offset: 0xac
	// Line 4865, Address: 0x2466c0, Func Offset: 0xb0
	// Line 4866, Address: 0x2466c8, Func Offset: 0xb8
	// Line 4867, Address: 0x2466d0, Func Offset: 0xc0
	// Line 4868, Address: 0x2466d4, Func Offset: 0xc4
	// Line 4869, Address: 0x2466dc, Func Offset: 0xcc
	// Line 4874, Address: 0x2466e0, Func Offset: 0xd0
	// Line 4875, Address: 0x2466e8, Func Offset: 0xd8
	// Line 4876, Address: 0x2466f0, Func Offset: 0xe0
	// Line 4877, Address: 0x2466f4, Func Offset: 0xe4
	// Line 4880, Address: 0x2466f8, Func Offset: 0xe8
	// Line 4881, Address: 0x2466fc, Func Offset: 0xec
	// Line 4882, Address: 0x246700, Func Offset: 0xf0
	// Line 4884, Address: 0x246704, Func Offset: 0xf4
	// Func End, Address: 0x24670c, Func Offset: 0xfc
	scePrintf("bhEff_SetAlign - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff_SetBaseColor(O_WRK* op, unsigned int col)
{
    op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col = col;
}

// 100% matching!
void bhClrEff_YG()
{
    O_WRK* opp;
    int i;
	
    opp = eff;
    
    for (i = 0; i < 512; i++, opp++) 
    {
        if ((opp->flg & 0x1))
        {
            switch (opp->id) 
            {                      
            case 250:
            case 253:
            case 256:
            case 257:
            case 272:
            case 296:
            case 297:
            case 298:
                opp->flg = 0;
                break;
            case 254:
            case 260:
                *(int*)opp->exp0 = 0;
                
                opp->flg = 0;
                break;
            }
        }
    }
}
