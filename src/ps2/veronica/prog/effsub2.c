#include "../../../ps2/veronica/prog/effsub2.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/effsub6.h"
#include "../../../ps2/veronica/prog/en12.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaFog.h"
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
    	while (TRUE) 
        {
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

			if (p->wait != 0) 
			{
				break;
			}

			op->frm_no++;
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

// 100% matching!
void bhEff_E02_SandDust(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK BH_UVTAB0[12] = 
    {
        {  0.3125f,   0.09375f, 0.03125f,  0.03125f },
        { 0.34375f, 0.0859375f, 0.03125f,  0.03125f },
        {  0.3125f,     0.125f,  0.0625f,   0.0625f },
        {     0.0f,       0.0f, 0.09375f,  0.09375f },
        { 0.09375f,       0.0f, 0.09375f,  0.09375f },
        {  0.1875f,       0.0f, 0.09375f, 0.078125f },
        { 0.28125f,       0.0f, 0.09375f, 0.078125f },
        {   0.375f,       0.0f,   0.125f,    0.125f },
        {     0.5f,  0.015625f, 0.15625f,    0.125f },
        { 0.65625f,  0.015625f, 0.15625f,    0.125f },
        {  0.8125f,  0.015625f, 0.15625f,    0.125f },
        {    -1.0f,       0.0f,     0.0f,      0.0f }
	};
    static UV_WORK BH_UVTAB1[15] = 
    {
        { 0.33984375f,   0.359375f,  0.03125f,  0.03125f },
        {      0.375f,  0.3515625f,  0.03125f,  0.03125f },
        {    0.34375f, 0.38671875f,   0.0625f,   0.0625f },
        { 0.42578125f, 0.37109375f,   0.0625f,   0.0625f },
        {  0.5078125f,   0.359375f, 0.078125f, 0.078125f },
        { 0.58984375f, 0.31640625f,  0.09375f,  0.09375f },
        {   0.703125f,   0.328125f,  0.09375f,  0.09375f },
        {     0.8125f,  0.3203125f, 0.109375f, 0.109375f },
        { 0.01171875f,  0.2109375f,    0.125f,    0.125f },
        {    0.15625f,   0.203125f,  0.15625f,  0.15625f },
        {     0.3125f, 0.19921875f,  0.15625f,  0.15625f },
        {    0.46875f,  0.1484375f,  0.15625f,  0.15625f },
        {      0.625f,  0.1484375f,  0.15625f,  0.15625f },
        {    0.78125f,  0.1484375f,  0.15625f,  0.15625f },
        {       -1.0f,        0.0f,      0.0f,      0.0f }
    };
    static UV_WORK BH_UVTAB2[16] = 
    {
        {    0.0f,  0.4453125f, 0.1875f,     0.1875f },
        { 0.1875f,  0.4453125f, 0.1875f,     0.1875f },
        {  0.375f,     0.4375f, 0.1875f,     0.1875f },
        { 0.5625f,     0.4375f, 0.1875f,     0.1875f },
        {   0.75f,     0.4375f, 0.1875f,     0.1875f },
        {    0.0f,      0.625f, 0.1875f,     0.1875f },
        { 0.1875f, 0.62109375f, 0.1875f,     0.1875f },
        {  0.375f, 0.62109375f, 0.1875f,     0.1875f },
        { 0.5625f,      0.625f, 0.1875f, 0.18359375f },
        {   0.75f,      0.625f, 0.1875f, 0.18359375f },
        {    0.0f,     0.8125f, 0.1875f,     0.1875f },
        { 0.1875f, 0.80859375f, 0.1875f,     0.1875f },
        {  0.375f, 0.80859375f, 0.1875f,     0.1875f },
        { 0.5625f, 0.80859375f, 0.1875f,     0.1875f },
        {   0.75f, 0.80859375f, 0.1875f,     0.1875f },
        {   -1.0f,        0.0f,    0.0f,        0.0f }
    };
    static UV_WORK BH_UVTAB3[15] = 
    {
        {  0.3125f, 0.09375f, 0.03125f, 0.03125f },
        { 0.34375f, 0.09375f, 0.03125f, 0.03125f },
        {  0.3125f,   0.125f,  0.0625f,  0.0625f },
        {     0.0f,     0.0f, 0.09375f, 0.09375f },
        { 0.09375f,     0.0f, 0.09375f, 0.09375f },
        {  0.1875f,     0.0f, 0.09375f, 0.09375f },
        { 0.28125f,     0.0f, 0.09375f, 0.09375f },
        {     0.0f, 0.09375f, 0.09375f, 0.09375f },
        { 0.09375f, 0.09375f, 0.09375f, 0.09375f },
        {  0.1875f, 0.09375f,   0.125f,   0.125f },
        {   0.375f,     0.0f,   0.125f,   0.125f },
        {     0.5f,     0.0f, 0.15625f, 0.15625f },
        { 0.65625f,     0.0f, 0.15625f, 0.15625f },
        {  0.8125f,     0.0f, 0.15625f, 0.15625f },
        {    -1.0f,     0.0f,     0.0f,     0.0f }
    };
    static UV_WORK BH_UVTAB4[15] = 
    {
        {     0.0f,   0.375f, 0.03125f, 0.03125f },
        { 0.03125f,   0.375f, 0.03125f, 0.03125f },
        {     0.0f, 0.40625f,  0.0625f,  0.0625f },
        {  0.0625f,   0.375f, 0.09375f, 0.09375f },
        { 0.15625f,   0.375f, 0.09375f, 0.09375f },
        {    0.25f,   0.375f, 0.09375f, 0.09375f },
        { 0.34375f,   0.375f,   0.125f,   0.125f },
        { 0.46875f,   0.375f,   0.125f,   0.125f },
        {     0.0f, 0.21875f, 0.15625f, 0.15625f },
        { 0.15625f, 0.21875f, 0.15625f, 0.15625f },
        {  0.3125f, 0.21875f, 0.15625f, 0.15625f },
        { 0.46875f, 0.21875f, 0.15625f, 0.15625f },
        {   0.625f, 0.21875f, 0.15625f, 0.15625f },
        { 0.78125f, 0.21875f, 0.15625f, 0.15625f },
        {    -1.0f,     0.0f,     0.0f,     0.0f }
    };
    static UV_WORK BH_UVTAB5[11] =
    {
        {    0.0f, 0.5625f, 0.1875f, 0.1875f },
        { 0.1875f, 0.5625f, 0.1875f, 0.1875f },
        {  0.375f, 0.5625f, 0.1875f, 0.1875f },
        { 0.5625f, 0.5625f, 0.1875f, 0.1875f },
        {   0.75f, 0.5625f, 0.1875f, 0.1875f },
        {    0.0f,   0.75f, 0.1875f, 0.1875f },
        { 0.1875f,   0.75f, 0.1875f, 0.1875f },
        {  0.375f,   0.75f, 0.1875f, 0.1875f },
        { 0.5625f,   0.75f, 0.1875f, 0.1875f },
        {   0.75f,   0.75f, 0.1875f, 0.1875f },
        {   -1.0f,    0.0f,    0.0f,    0.0f }
    };
    static UV_WORK* uvtble[6] = 
    {
        BH_UVTAB0,
        BH_UVTAB1,
        BH_UVTAB2,
        BH_UVTAB3,
        BH_UVTAB4,
        BH_UVTAB5
    };

    switch (op->mode0) 
    {                              
    case 0:
        bhEff_SetAlign(op, 2);
        bhEff_SetBaseColor(op, 0xFF404040);
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->tex_id = op->mdlver + 82;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        op->ct1 = 0;
        
        op->flg |= 0x180000;
        op->flg |= 0x4000000;
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->mode0 = 1;
    case 1:
        uvp = &uvtble[op->type + (op->mdlver * 3)][op->ct1];
        
        if (uvp->u < 0) 
        {
            op->flg = 0;
            return;
        }
        
        op->ct1++;
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        if (op->type != 2) 
        {
            op->xn *= 0.9f;
            op->yn *= 0.9f;
            op->zn *= 0.9f;
        }
        
        op->yn -= 0.1f;
        
        bhEff_SetUVInfo(op, uvp, 0.0625f);
        
        if (sys->ef_trsn < 512) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            
            sys->ef_trsn++;
        }
        
        break;
    }
}

// 100% matching!
void bhEff_E02_SandParticle(O_WRK* op) 
{
	P_WRK* pp;
	NJS_POINT3* p, *v;
	int i;
    unsigned int col[3] = 
    {
        0xFF332417,
        0xFF322320,
        0xFF211816
    };
    float px, py, pz; // not from DWARF

    switch (op->mode0) 
    {                             
    case 0:
        pp = (P_WRK*)bhSetExtraEffectWork();
        
        if (pp == NULL) 
        {
            op->flg = 0;
            return;
        }
        
        op->exp0 = (unsigned char*)pp;
        
        p = pp->pos;
        v = pp->vec;
        
        pp->num = 16;
        
        for (i = 0; i < pp->num; i++, p++, v++)  
        {
            px   = op->px + (op->sx * (-rand() / -2.1474836E9f));
            p->x = px - (op->sx * (-rand() / -2.1474836E9f));
            
            py   = op->py + (op->sy * (-rand() / -2.1474836E9f));
            p->y = py - (op->sy * (-rand() / -2.1474836E9f));
            
            pz   = op->pz + (op->sz * (-rand() / -2.1474836E9f));
            p->z = pz - (op->sz * (-rand() / -2.1474836E9f));
            
            px   = op->xn + (op->sxb * (-rand() / -2.1474836E9f));
            v->x = px - (op->sxb * (-rand() / -2.1474836E9f));
            
            py   = op->yn + (op->syb * (-rand() / -2.1474836E9f));
            v->y = py - (op->syb * (-rand() / -2.1474836E9f));
           
            pz   = op->zn + (op->szb * (-rand() / -2.1474836E9f));
            v->z = pz - (op->szb * (-rand() / -2.1474836E9f));
         }
        
        pp->sx = 1.0f;
        pp->sy = 1.0f;
        
        pp->col = col[op->type];
        
        op->ct0 = 10.0f + (10.0f * (-rand() / -2.1474836E9f));
        
        op->flg |= 0x20000000;
        
        op->func = (void*)bhEff_E00_DrawParticlePly;
        
        op->mode0++;
        break;
    case 1:
        pp = (P_WRK*)op->exp0;
        
        p = pp->pos;
        v = pp->vec;
        
        for (i = 0; i < pp->num; i++, p++, v++) 
        {
            p->x += v->x;
            p->y += v->y;
            p->z += v->z;
            
            v->y -= 0.4f;
            v->x *= 0.8f;
            v->z *= 0.8f;
        }
        
        if (op->ct0-- == 0) 
        {
            op->flg = 0;
            pp->flg = 0;
            return;
        }
        
        if (sys->ef_fncn < 128) 
        {
            sys->ef_fnc[sys->ef_fncn] = op;
            
            sys->ef_fncn++;
        }
    }
}

// 99.93% matching
void bhEff_E02_SandParticle2(O_WRK* op) 
{
    O_WRK* opw;
    int eno;
    
    switch (op->mode0) 
    {                              
    case 0:
        op->ct0 = 120.0f + (30.0f * ( -rand() / -2.1474836E9f));
        
        op->mode0++;
        break;
    case 1:
        if (op->ct0-- == 0) 
        {
            op->mode0 = 0;
            
            if ((-rand() / -2.1474836E9f) < 0.3f) 
            {
                sys->ef.id = 254;
                
                sys->ef.flg = 1;
                sys->ef.type = 0;
                
                sys->ef.px = op->px;
                sys->ef.py = op->py;
                sys->ef.pz = op->pz;
                
                sys->ef.ax = 0;
                sys->ef.ay = 0;
                
                eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
                
                if (eno >= 0) 
                {
                    opw = &eff[eno];
                    
                    opw->sx = 3.0f;
                    opw->sy = 3.0f;
                    opw->sz = 3.0f;
                    
                    opw->sxb = 0.2f;
                    opw->syb = 0.3f;
                    opw->szb = 0.2f;
                }
            }
        }
        
        break;
    }
}

// 100% matching!
void bhEff_E03_Acid(O_WRK* op)
{
	ATR_WORK* hp; // needs use
	NJS_CAPSULE c;
    ACID_WORK param[7] = 
    {
        {  0, 0.0f,  0       },
        { 10, 0.25f, 0x12308 },
        { 20, 0.4f,  0x12308 },
        { 20, 0.0f,  0x12305 },
        { 20, 0.15f, 0x12304 },
        { 10, 0.25f, 0x12308 },
        { 20, 0.0f,  0x12305 }
    };
	UV_WORK* uvp;
    NJS_POINT3 n;
    static UV_WORK BH_UVTAB0[7] = 
    {
        {  0.0f,   0.4375f, 0.0625f,  0.0625f  },
        {  0.0f,   0.375f,  0.0625f,  0.0625f  },
        {  0.0f,   0.0f,    0.09375f, 0.09375f },
        {  0.0f,   0.09375f,0.09375f, 0.09375f },
        {  0.0f,   0.1875f, 0.125f,   0.125f   },
        {  0.625f, 0.1875f, 0.125f,   0.125f   },
        { -1.0f,   0.0f,    0.0f,     0.0f     }
    };
    static UV_WORK BH_UVTAB1[7] = 
    {
        {  0.15625f, 0.0f,     0.15625f, 0.15625f },
        {  0.3125f,  0.0f,     0.15625f, 0.15625f },
        {  0.46875f, 0.0f,     0.15625f, 0.15625f },
        {  0.15625f, 0.15625f, 0.15625f, 0.15625f },
        {  0.3125f,  0.15625f, 0.15625f, 0.15625f },
        {  0.46875f, 0.15625f, 0.15625f, 0.15625f },
        { -1.0f,     0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK BH_UVTAB2[9] = 
    {
        {  0.625f,  0.0f,    0.1875f, 0.1875f },
        {  0.8125f, 0.0f,    0.1875f, 0.1875f },
        {  0.8125f, 0.1875f, 0.1875f, 0.1875f },
        {  0.0625f, 0.3125f, 0.1875f, 0.1875f },
        {  0.25f,   0.3125f, 0.1875f, 0.1875f },
        {  0.4375f, 0.3125f, 0.1875f, 0.1875f },
        {  0.625f,  0.3125f, 0.1875f, 0.1875f },
        {  0.8125f, 0.375f,  0.1875f, 0.125f  },
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
        bhEff_SetAlign(op, 2);
        
        if (op->type == 6) 
        {
            bhEff_SetBaseColor(op, 0xFFFF3E00);
            
            op->bl_src = 8;
            op->bl_dst = 10;
        } 
        else 
        {
            bhEff_SetBaseColor(op, 0xFF80A880);
            
            op->bl_src = 8;
            op->bl_dst = 6;
        }
        
        op->flg   |= 0x4180000;
        
        op->ct0    = 100;
        op->ct1    = 0; 
        
        op->stflg |= 0x20;
        
        op->sxb    = op->sx;
        op->syb    = op->sy;
        
        if (op->type != 5) 
        {
            op->flg |= 0x10;
        }
        else 
        {
            op->flg &= ~0x10;
        }
        
        op->mtn_no = 0;
        op->frm_no = 0;
        
        op->mode0++;
    case 1:
        if (op->frm_no == 0) 
        {
            op->mtn_no++;
            
            op->frm_no = 6.0f * (-rand() / -2.147483648E9f);
            
            op->mode0++;
        }
        
        break;
    case 2:
        if (op->ct0-- == 0) 
        {
            op->flg = 0;
            return;
        }
        
        break;
    case 3:
        if (op->frm_no == 0) 
        {
            op->flg = 0;
            return;
        }
        
        break;
    default:
        break;
    }

    if (op->mode0 < 3) 
    {
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->xn *= 0.97f;
        op->yn *= 0.97f;
        op->zn *= 0.97f;
        
        op->yn -= 0.3f;

        if ((op->type != 0) && (op->type != 6)) 
        {
            c.c1.x = op->pxb;
            c.c1.y = op->pyb;
            c.c1.z = op->pzb;
            
            c.c2.x = op->px;
            c.c2.y = op->py;
            c.c2.z = op->pz;
            
            c.r    = 2.0f;

            if (npCollisionCheckCC(&c, &plp->watr) != 0) 
            {
                if ((!(plp->flg & 0x4)) && (!(plp->stflg & 0x80000000))) 
                {
                    if (bhEne_CheckPlayEffectSE(param[op->type].se) == 0) 
                    {
                        bhEne_CallEffectSE((NJS_POINT3*)&op->px, param[op->type].se);
                    }
                    
                    plp->flg            |= 0x10004;
                    plp->stflg          |= 0x10000;
                    
                    plp->dvx             = op->xn;
                    plp->dvy             = op->yn;
                    plp->dvz             = op->zn;
                    
                    *(int*)&plp->mode0   = 2;
                    
                    plp->hp             -= param[op->type].dam;
                    
                    if ((-rand() / -2.147483648E9f) < param[op->type].poison) 
                    {
                        plp->stflg |= 0x80000;
                    }
                }
                
                sys->ef.id     = 257;
                
                sys->ef.flg    = 1;
                sys->ef.type   = 0;
                
                sys->ef.px     = op->px;
                sys->ef.py     = op->py;
                sys->ef.pz     = op->pz;
                
                sys->ef.sx     = op->sx;
                sys->ef.sy     = op->sy;
                sys->ef.sz     = op->sz;
                
                sys->ef.ax     = 0;
                sys->ef.ay     = 0;
                
                bhSetEffectTb((EF_WORK*)&sys->ef, NULL, NULL, 0);
                
                op->flg = 0;
                return;
            }
        }

        if ((op->flg & 0x10)) 
        {
            if (bhCollisionCheckLine2((NJS_POINT3*)&op->pxb, (NJS_POINT3*)&op->px, 0x4400, -1) != 0) 
            {
                bhGetHitCollisionNormal(&n);
                
                njUnitVector(&n);

                if (n.y > 0.9) // probably mistyped as double
                {
                    op->mtn_no++;
                } 
                else 
                {
                    op->px += n.x;
                    op->py += n.y;
                    op->pz += n.z;
                }

                op->frm_no = 0;
                
                op->mode0  = 3;

                if (op->type == 6)
                {
                    sys->ef.id    = 269;
                    
                    sys->ef.flg   = 1;
                    sys->ef.type  = 1;
                    
                    sys->ef.px    = op->px;
                    sys->ef.py    = op->py;
                    sys->ef.pz    = op->pz;
                    
                    sys->ef.sx    = 1.5f;
                    sys->ef.sy    = 2.0f;
                    sys->ef.sz    = 1.0f;
                    
                    sys->ef.ax    = 0;
                    sys->ef.ay    = 0;
                    
                    if (op->mdlver == 0) 
                    {
                        bhEne_CallEffectSE((NJS_POINT3*)&op->px, param[op->type].se);
                    }
                } 
                else 
                {
                    sys->ef.id    = 257;
                    
                    sys->ef.flg   = 1;
                    sys->ef.type  = 0;
                    
                    sys->ef.px    = op->px;
                    sys->ef.py    = op->py;
                    sys->ef.pz    = op->pz;
                    
                    sys->ef.sx    = op->sx;
                    sys->ef.sy    = op->sy;
                    sys->ef.sz    = op->sz;
                    
                    sys->ef.ax    = 0;
                    sys->ef.ay    = 0;
                    
                    if (bhEne_CheckPlayEffectSE(param[op->type].se) == 0) 
                    {
                        bhEne_CallEffectSE((NJS_POINT3*)&op->px, param[op->type].se);
                    }
                }
                
                bhSetEffectTb((EF_WORK*)&sys->ef, NULL, NULL, 0);
            }
        }
        else if (op->yn < 0) 
        {
            op->mtn_no++;
            
            op->frm_no    = 0;
            
            op->mode0     = 3;
            
            sys->ef.id    = 257;
            
            sys->ef.flg   = 1;
            sys->ef.type  = 0;
            
            sys->ef.px    = op->px;
            sys->ef.py    = op->py;
            sys->ef.pz    = op->pz;
            
            sys->ef.sx    = op->sx;
            sys->ef.sy    = op->sy;
            sys->ef.sz    = op->sz;
            
            sys->ef.ax    = 0;
            sys->ef.ay    = 0;
            
            bhSetEffectTb((EF_WORK*)&sys->ef, NULL, NULL, 0);
            
            if (bhEne_CheckPlayEffectSE(param[op->type].se) == 0) 
            {
                bhEne_CallEffectSE((NJS_POINT3*)&op->px, param[op->type].se);
            }
        }
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
void bhEff_E03_Shadow(O_WRK* op) 
{
    BH_PWORK* pp;
    O_WRK* owp; // not from DWARF
    
    owp = (O_WRK*)op->lkwkp;
    
    switch (op->mode0) 
    {                             
    case 0:
        op->flg |= 0x8000080;
        op->flg &= ~0x200000;
        
        op->lkono = 0;
        
        op->mode0 = 1;
        break;
    case 1:
        if (!(owp->flg & 0x1)) 
        {
            op->flg = 0;
            return;
        }
        
        if (((owp->stflg & 0x8)) || ((owp->mdflg & 0x1)) || ((owp->stflg & 0x1000000))) 
        {
            op->flg |= 0x1000000;
            return;
        }
        
        op->flg &= ~0x1000000;
        
        sys->ef_mdf[sys->ef_mdfn++] = op;
        break;
    }
}

// 100% matching!
void bhEff_E05_Blood(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK BH_UVTAB0[18] = 
    {
        {     0.0f,     0.0f, 0.03125f, 0.03125f },
        {     0.0f, 0.03125f,  0.0625f,  0.0625f },
        {     0.0f, 0.09375f,  0.0625f,  0.0625f },
        {  0.0625f, 0.09375f, 0.09375f, 0.09375f },
        {  0.0625f,     0.0f, 0.09375f, 0.09375f },
        { 0.15625f,     0.0f,   0.125f,   0.125f },
        { 0.28125f,     0.0f,   0.125f,   0.125f },
        { 0.40625f,     0.0f, 0.15625f, 0.15625f },
        {  0.5625f,     0.0f, 0.15625f, 0.15625f },
        { 0.71875f,     0.0f,  0.1875f,  0.1875f },
        {     0.0f,  0.1875f,  0.1875f,  0.1875f },
        {  0.1875f,  0.1875f, 0.21875f, 0.21875f },
        { 0.40625f,  0.1875f, 0.21875f, 0.21875f },
        {   0.625f,  0.1875f, 0.21875f, 0.21875f },
        {     0.0f, 0.40625f, 0.21875f, 0.21875f },
        { 0.21875f, 0.40625f, 0.21875f, 0.21875f },
        {  0.4375f, 0.40625f, 0.21875f, 0.21875f },
        {    -1.0f,     0.0f,     0.0f,     0.0f }
    };
    static UV_WORK BH_UVTAB1[6] = 
    {
        { 0.15625f,   0.125f, 0.03125f, 0.03125f },
        { 0.15625f, 0.15625f, 0.03125f, 0.03125f },
        {  0.1875f,   0.125f,  0.0625f,  0.0625f },
        {    0.25f,   0.125f,  0.0625f,  0.0625f },
        {  0.3125f,   0.125f,  0.0625f,  0.0625f },
        {    -1.0f,     0.0f,     0.0f,     0.0f }
    };
    static UV_WORK* uvtble[2] = 
    {
        BH_UVTAB0,
        BH_UVTAB1
    };

    switch (op->mode0) 
    {                            
    case 0:
        bhEff_SetBaseColor(op, -1);
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        op->ct1 = 0;
        
        op->flg |= 0x4180000;
        op->stflg |= 0x20;
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->yn = op->py;
        
        op->mode0 = 1;
    case 1:
        uvp = &uvtble[op->type][op->ct1];
        
        if (uvp->u < 0) 
        {
            op->flg = 0;
            return;
        }

        op->ct1++;
        
        bhEff_SetUVInfo(op, uvp, 0.0625f);
        
        op->py = op->yn + op->sy;
        
        if (sys->ef_trsn < 512) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            
            sys->ef_trsn++;
        }
    }
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

// 100% matching!
void bhEff_E11_SearchLight(O_WRK* op)
{
    switch (op->mode0) 
    {
    case 0:
        op->ct0  = 0;
        op->ct1  = 0;
        op->ct2  = 0;
        
        op->ax   = 0;
        
        op->func = (void*)bhEff_E11_SearchLightDraw;
        
        op->mode0 = 0xFF;
        
        if (op->exp0 != NULL) 
        {
            return;
        }
        
        op->exp0 = (unsigned char*)bhSetExtraEffectWork();
        return;
    case 1:
        if (++op->ct0 >= 32) 
        {
            op->mode0++;
        }
        
        op->ax += (short)(op->axp - op->ax) / 16;
        
        op->ct1 += 10;
        break;
    case 2:
        op->ct0 = 32;
        
        op->ax  = op->axp;
        
        if (op->ct2 != 0) 
        {
            op->ct1 += 14;
        } 
        else 
        {
            op->ct1 += 6;
        }
        
        break;
    case 3:
        op->ct0 -= 3;
        
        if (op->ct0 <= 0) 
        {
            op->ct0   = 0;
            
            op->mode0 = 0;
        }
        
        op->ax   = op->ax - (op->ax / 8);
        
        op->ct1 += 2;
        break;
    case 0xFF:
        return;
    }

    op->sx = -rand() / -2.147483648E9f;
    op->sy = -rand() / -2.147483648E9f;
    op->sz = -rand() / -2.147483648E9f;

    if (sys->ef_fncn < 128)
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
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

// 100% matching!
void bhEff_E16_LaserSight(O_WRK* op) 
{
    O_WRK* opp; // not from DWARF

    opp = (O_WRK*)op->lkwkp;
    
    if ((opp->flg != 0) ^ 1) 
    {
        op->flg = 0;
        return;
    }
    
    switch (op->mode0) 
    {                             
    case 0:
        op->func = (void*)bhEff_E16_LaserSightDraw;

        op->mode0++;
        break;
    default:
        if (!(opp->stflg & 0x1000000)) 
        {
            if (sys->ef_fncn < 128)
            {
                sys->ef_fnc[sys->ef_fncn] = op;
                
                sys->ef_fncn++;
            }
        }
        
        break;
    case 1:
        return;
    }
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

// 100% matching!
void bhEff_E12_FloorBlood2(O_WRK* op) 
{
    int i;
    NJS_POINT3 ofp;
    UV_WORK* uvp;
    float tmp; // not from DWARF
    static UV_WORK BH_UVTAB0[9] = 
    {
        {  0.0f,   0.0f,   0.25f, 0.25f },
        {  0.25f,  0.0f,   0.25f, 0.25f },
        {  0.5f,   0.0f,   0.25f, 0.25f },
        {  0.75f,  0.0f,   0.25f, 0.25f },
        {  0.0f,   0.25f,  0.25f, 0.25f },
        {  0.25f,  0.25f,  0.25f, 0.25f },
        {  0.5f,   0.25f,  0.25f, 0.25f },
        {  0.75f,  0.25f,  0.25f, 0.25f },
        { -1.0f,   0.0f,   0.0f,  0.0f  }
    };
    static UV_WORK* uvtble[1] = 
    {
        BH_UVTAB0
    };
    
    switch (op->mode0) 
    {                             
    case 0:
        op->ct0 = (int)(10.0f * (-rand() / -2.1474836E9f)) + 40;
        
        op->mode0++;
    case 1:
        if (op->ct0-- == 0) 
        {
            if ((!(plp->flg & 0x4)) && (!(plp->stflg & 0x80000000))) 
            {
                plp->flg |= 0x10004;
                plp->stflg |= 0x10000;
                
                plp->mode0 = 4;
                plp->mode2 = op->mode1;
                plp->mode3 = 0;
                
                plp->hp -= 20;
                
                for (i = 0; i < 4; i++) 
                {
                    ofp.x = 1.0f - (2.0f * (-rand() / -2.1474836E9f));
                    ofp.y = -0.5f + (2.0f * (-rand() / -2.1474836E9f));
                        
                    if (op->mode1 != 0) 
                    {
                        tmp = 1.3f;
                    } 
                    else 
                    {
                        tmp = -1.5f;
                    }
                    
                    ofp.z = tmp;
                    
                    tmp = 0.5f + (-rand() / -2.147483648E9f);
                    
                    bhEne_SetFireEffect(plp, 3, &ofp, tmp, (int)(10.0f * (-rand() / -2.147483648E9f)) + 20);
                }
            }
            
            op->mode0++;
        }
        
        return;
    case 2:
        op->tex_id = 9;
        
        op->stflg &= ~0x20;
        
        op->flg |= 0x4000080;
        op->flg |= 0x180000;
        
        bhEff_SetBaseColor(op, -1);
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->lox = 1.0f - (2.0f * (-rand() / -2.1474836E9f));
        op->loy = -0.5f + (2.0f * (-rand() / -2.1474836E9f));

        if (op->mode1 != 0) 
        {
            tmp = 1.3f;
        } 
        else 
        {
            tmp = -1.5f;
        }
        
        op->loz = tmp;
        
        op->lkwkp = (unsigned char*)plp;
        op->lkono = 3;
        
        op->sxb = 2.5f;
        op->syb = 2.5f;
        
        op->mtn_no = 0;
        op->frm_no = 0;
        
        op->mode0++;
        break;
    case 3:
        if (op->frm_no == 0) 
        {
            op->flg = 0;
            return;
        }
        
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

// 99.97% matching
void bhEff_E12_FireSpark(O_WRK* op)
{
    P_WRK* pp;
    NJS_POINT3* p, *v;
    int i;
    unsigned int col[3] = 
    {
        0x32230E,
        0x1E1E0A,
        0x50411C
    };
    
    switch (op->mode0) 
    {                            
    case 0:
        pp = (P_WRK*)bhSetExtraEffectWork();
        
        if (pp == NULL) 
        {
            op->flg = 0;
            return;
        }
        
        op->exp0 = (unsigned char*)pp;
        
        p = pp->pos;
        v = pp->vec;
        
        pp->num = 16;
        
        for (i = 0; i < pp->num; i++, p++, v++) 
        {
            p->x = (op->px - (2.0f * (-rand() / -2.1474836E9f))) - 1.0f;
            p->y = op->py + (5.0f * (-rand() / -2.1474836E9f));
            p->z = (op->pz - (2.0f * (-rand() / -2.1474836E9f))) - 1.0f;
            
            op->xn = 0.1f + (0.1f * (-rand() / -2.1474836E9f));
            
            op->ay = 65536.0f * (-rand() / -2.1474836E9f);
            
            v->x = op->xn * -njSin(op->ay);
            v->y = 0.5f + (0.5f * (-rand() / -2.1474836E9f));
            v->z = op->xn * -njCos(op->ay);
        }
        
        pp->sx = 0.1f;
        pp->sy = 0.15f;
        
        op->ct0 = 30.0f + (20.0f * (-rand() / -2.1474836E9f));
        op->ct2 = 0xFF;
        
        op->flg |= 0x20000000;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->func = (void*)bhEff_E00_DrawParticleSpr;

        op->mode0++;
        break;
    case 1:
        pp = (P_WRK*)op->exp0;
        
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
            op->flg = 0;
            pp->flg = 0;
            return;
        }
        
        if (sys->ef_fncn < 128) 
        {
            sys->ef_fnc[sys->ef_fncn] = op;
            
            sys->ef_fncn++;
        }
    }
}

// 100% matching!
void bhEff_E12_FireManager(O_WRK* op) 
{
    switch (op->mode0) 
    {                           
    case 0:
        if (op->exp0 == NULL) 
        {
            op->exp0 = (unsigned char*)bhSetExtraEffectWork();
        }
        
        op->tex_id = 80;
        
        op->ani_ct = 1;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->func = (void*)bhEff_E12_FireBurstDraw;
        
        op->mode0++;
        break;
    case 1:
        op->ct0 = 0;
        break;
    }
    
    if (sys->ef_fncn < 128) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhEff_E12_FireBurstDraw(O_WRK* owp)
{
    O_WRK* op;
    O_WRK** opp;
    int num; // modified original position from DWARF
    char atr[192];

    njSetMatrix(NULL, cam.mtx);
    
    njTextureFilterMode(0);
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[owp->tex_id] + owp->ani_ct);
    
    njGetSystemAttr((NJS_SYS_ATTR*)&atr);
    
    njColorBlendingMode(0, owp->bl_src);
    njColorBlendingMode(1, owp->bl_dst);
    
    njFogDisable();

    opp = (O_WRK**)&owp->exp0[4];
    
    for (num = owp->ct0; num != 0; )
    {
        op = *opp++;
        
        num--;
        
        njPushMatrixEx();
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njTranslateEx((NJS_VECTOR*)&op->px);
        njRotateEx((Angle*)&op->ax, 0);
        
        njGetMatrix(op->mtx);
        
        njPopMatrixEx();
        
        njMultiMatrix(NULL, op->mtx);

        if ((op->flg & 0x100000)) 
        {
            njUnitRotPortion(NULL);
        }

        njScaleEx((NJS_VECTOR*)&op->sx);
        
        njDrawTexture3DEx(op->tvp, op->pn, 1);
        
        njPopMatrixEx();
    } 
    
    njSetSystemAttr((NJS_SYS_ATTR*)&atr);
     
    if ((sys->st_flg & 0x2)) 
    {
        njFogEnable();
    }
}

// 100% matching!
void bhEff_E12_Fire2(O_WRK* op) 
{
    UV_WORK* uvp;
    static UV_WORK BH_UVTAB0[11] = 
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
    static UV_WORK* uvtble[1] = 
    {
        BH_UVTAB0
    };

    switch (op->mode0) 
    {                          
    case 0:
        op->tex_id = 8;
        
        op->ani_ct = 0;
        
        bhEff_SetBaseColor(op, 0xFF808080);
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->flg |= 0x4180000;
        
        bhEff_SetAlign(op, 2);
        
        op->mtn_no = 0;
        op->frm_no = 8.0f * (-rand() / -2.1474836E9f);
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->aw = 1.0f;
        op->ah = 1.0f;
        
        op->ct3 = 0xFF;
        
        op->func = (void*)bhEff_Draw3DSprite;
        
        op->mode0++;
    case 1:
        if (op->ct1 != 0) 
        {
            op->ct1--;
            return;
        }
        
        op->mode0++;
        break;
    case 2:
        if (op->ct0 != 0) 
        {
            op->ct0--;
        }
        else 
        {
            op->mode0++;
        }
        
        break;
    case 3:
        op->ct3 -= 8;
        
        if (op->ct3 < 0) 
        {
            op->flg = 0;
            return;
        }
        
        bhEff_SetBaseColor(op, (op->ct3 << 24) | 0xFFFFFF);
        break;
    }
    
    uvp = &uvtble[op->mtn_no][op->frm_no];
    
    op->frm_no++;
    
    if (uvtble[op->mtn_no][op->frm_no].u < 0) 
    {
        op->frm_no = 0;
    }
    
    bhEff_SetUVInfo(op, uvp, 0.09375f);
    
    op->sx *= op->aw;
    op->sy *= op->ah;
    
    if (sys->ef_fncn < 128) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhEff_E12_Fire3(O_WRK* op) 
{
    UV_WORK* uvp;
    static UV_WORK BH_UVTAB0[22] = 
    {
        {     0.0f,     0.0f, 0.21875f, 0.21875f },
        { 0.21875f,     0.0f, 0.21875f, 0.21875f },
        {  0.4375f,     0.0f, 0.21875f, 0.21875f },
        { 0.65625f,     0.0f, 0.21875f, 0.21875f },
        {     0.0f, 0.21875f, 0.21875f, 0.21875f },
        { 0.21875f, 0.21875f, 0.21875f, 0.21875f },
        {  0.4375f, 0.21875f, 0.21875f, 0.21875f },
        { 0.65625f, 0.21875f, 0.21875f, 0.21875f },
        {     0.0f,  0.4375f, 0.21875f, 0.21875f },
        { 0.21875f,  0.4375f, 0.21875f, 0.21875f },
        {  0.4375f,  0.4375f, 0.21875f, 0.21875f },
        { 0.65625f,  0.4375f, 0.21875f, 0.21875f },
        {     0.0f, 0.65625f, 0.21875f, 0.21875f },
        { 0.21875f, 0.65625f, 0.21875f, 0.21875f },
        {  0.4375f, 0.65625f, 0.21875f, 0.21875f },
        {  0.4375f, 0.65625f, 0.21875f, 0.21875f },
        {  0.4375f, 0.65625f, 0.21875f, 0.21875f },
        {  0.4375f, 0.65625f, 0.21875f, 0.21875f },
        {  0.4375f, 0.65625f, 0.21875f, 0.21875f },
        {  0.4375f, 0.65625f, 0.21875f, 0.21875f },
        {  0.4375f, 0.65625f, 0.21875f, 0.21875f },
        {    -1.0f,     0.0f,     0.0f,     0.0f }
    };
    static UV_WORK* uvtble[1] = 
    {
        BH_UVTAB0
    };

    switch (op->mode0) 
    {                          
    case 0:
        op->tex_id = 9;
        
        op->ani_ct = 0;
        
        bhEff_SetBaseColor(op, -1);
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->flg |= 0x4180000;
        
        bhEff_SetAlign(op, 2);
        
        op->mtn_no = 0;
        op->frm_no = 9.0f * (-rand() / -2.1474836E9f);
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->ct3 = 0xFF;
        
        op->func = (void*)bhEff_Draw3DSprite;
        
        op->mode0++;
        break;
    case 1:
        if (op->frm_no == 0) 
        {
            op->flg = 0;
            return;
        }
        
        if (op->frm_no > 7) 
        {
            op->ct3 -= 16;
            
            if (op->ct3 < 16)
            {
                op->ct3 = 16;
            }
            
            bhEff_SetBaseColor(op, (op->ct3 << 24) | 0xFFFFFF);
        }
        
        break;
    }
    
    uvp = &uvtble[op->mtn_no][op->frm_no]; 
    
    op->frm_no++;
    
    if (uvtble[op->mtn_no][op->frm_no].u < 0) 
    {
        op->frm_no = 0;
    }
    
    bhEff_SetUVInfo(op, uvp, 0.1875f);
    
    op->px += op->xn;
    op->py += op->yn;
    op->pz += op->zn;
    
    op->xn *= 0.9f;
    op->yn *= 0.9f;
    op->zn *= 0.9f;
    
    op->xn += (0.04f * (-rand() / -2.1474836E9f)) - 0.02f;
    op->zn += (0.04f * (-rand() / -2.1474836E9f)) - 0.02f;
    op->yn += 0.03f * (-rand() / -2.1474836E9f);
    
    if (sys->ef_fncn < 128) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhEff_E12_BintaEffControl(O_WRK* op) 
{
    BH_PWORK* ep;

    ep = (BH_PWORK*)op->lkwkp;
    
    switch (op->mode0) 
    {                             
    case 0:                                         
        op->flg |= 0x1000000;
        
        op->mode0++;
    case 1:                                         
        if (ep != NULL) 
        {
            switch (op->mode1) 
            { 
            case 0:
                break;
            case 1:                                 
                bhEne12_SetFireBintaEffect(ep, 0);

                op->mode1 = 0;
                break;
            case 2:                                 
                bhEne12_SetFireBintaEffect(ep, 1);

                op->mode1 = 0;
                break;
            case 3:                                 
                bhEne12_SetFireBintaEffect(ep, 2);
                break;
            }
        } 
        
        break;
    }
}

// 99.89% matching
void bhEff_E13_Fluid(O_WRK* op) 
{
    NJS_POINT3 n;
    NJS_POINT3 p1, p2;
    float sz; // not from DWARF
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
        BH_UVTAB2,
        BH_UVTAB3,
        BH_UVTAB0,
        BH_UVTAB1
    };

    switch (op->mode0) 
    {
    case 0:
        op->flg    |= 0x180000;
        
        op->tex_id  = 81;
        
        op->ani_ct  = 0;
        
        bhEff_SetBaseColor(op, -1);
        
        op->bl_src  = 8;
        op->bl_dst  = 3;
        
        op->mtn_no  = op->type;
        op->frm_no  = 4.0f * (-rand() / -2.147483648E9f);
        
        op->sxb     = op->sx;
        op->syb     = op->sy;
        
        op->ct0     = 0;
        op->ct2     = 1;

        if ((op->type == 0) || (op->type == 2)) 
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
            break;
        }

        op->frm_no++;
        
        if (op->frm_no > 7) 
        {
            op->frm_no = 3;
        }
        
        op->ct0++;
        break;
    case 2:
        op->ct0++;
        
        if (op->ct0 >= 8)
        {
            op->flg = 0;
            return;
        }
        
        bhEff_SetBaseColor(op, ((unsigned int)(0xFF - (op->ct0 * 32)) << 24) | 0xFFFFFF);
        
        op->sx *= 0.9f;
        op->sy *= 0.9f;
        break;
    }

    if (op->ct2 != 0)
    {
        op->px += op->xn;
        op->pz += op->zn;
        op->py += op->yn;
        
        op->yn -= 0.15f;

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

    sz = 0.0625f;
    
    bhEff_SetUVInfo(op, &uvtble[op->mtn_no][op->frm_no], (float)sz);

    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff_E14_Explosion(O_WRK* op) 
{ 
    switch (op->mode0) 
    {                         
    case 0:
        sys->ef.id = 19;
        
        sys->ef.flg = 0x4100001;
        sys->ef.type = 0;
        
        sys->ef.mdlver = 0;
        
        sys->ef.sx = 2.5f;
        sys->ef.sy = 2.5f;
        sys->ef.sz = 2.5f;
        
        sys->ef.px = op->px;
        sys->ef.py = op->py;
        sys->ef.pz = op->pz;
        
        sys->ef.ay = 0;
        sys->ef.ax = 0;
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        sys->ef.id = 19;
        
        sys->ef.flg = 0x4100001;
        sys->ef.type = 2;
        
        sys->ef.mdlver = 0;
        
        sys->ef.sx = 5.0f;
        sys->ef.sy = 5.0f;
        sys->ef.sz = 5.0f;
        
        sys->ef.px = op->px;
        sys->ef.py = op->py;
        sys->ef.pz = op->pz;
        
        sys->ef.ay = 0;
        sys->ef.ax = 0;
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        op->ct0 = 0;
        
        op->mode0++;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 > 2) 
        {
            sys->ef.id = 19;
            
            sys->ef.flg = 0x4100001;
            sys->ef.type = 1;
            
            sys->ef.mdlver = 0;
            
            sys->ef.sx = 2.8f;
            sys->ef.sy = 2.8f;
            sys->ef.sz = 2.8f;
            
            sys->ef.px = op->px + cam.vx;
            sys->ef.py = op->py + cam.vy;
            sys->ef.pz = op->pz + cam.vz;
            
            sys->ef.ay = 0;
            sys->ef.ax = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            op->flg = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEff_E14_Fire(O_WRK* op) 
{
    UV_WORK* uvp;
    LGT_WORK* lp;
    float ln;
    int i;
    NJS_POINT3 ofp;
    float px, pz; // not from DWARF
    float z;      // not from DWARF
    static UV_WORK BH_UVTAB0[10] = 
    {
        {     0.0f,     0.0f, 0.15625f, 0.1875f },
        {  0.1875f,     0.0f, 0.15625f, 0.1875f },
        {   0.375f,     0.0f, 0.15625f, 0.1875f },
        {  0.5625f,     0.0f, 0.15625f, 0.1875f },
        {    0.75f,     0.0f, 0.15625f, 0.1875f },
        {     0.0f,  0.1875f, 0.15625f, 0.1875f },
        {  0.1875f,  0.1875f, 0.15625f, 0.1875f },
        {   0.375f,  0.1875f, 0.15625f, 0.1875f },
        {  0.5625f,  0.1875f, 0.15625f, 0.1875f },
        {    -1.0f,     0.0f,     0.0f,    0.0f }
    };
    static UV_WORK BH_UVTAB1[9] = 
    {
        { 0.03125f, 0.46875f, 0.15625f, 0.21875f },
        {    0.25f, 0.46875f, 0.15625f, 0.21875f },
        { 0.46875f, 0.46875f, 0.15625f, 0.21875f },
        {  0.6875f, 0.46875f, 0.15625f, 0.21875f },
        { 0.03125f,  0.6875f, 0.15625f, 0.21875f },
        {    0.25f,  0.6875f, 0.15625f, 0.21875f },
        { 0.46875f,  0.6875f, 0.15625f, 0.21875f },
        {  0.6875f,  0.6875f, 0.15625f, 0.21875f },
        {    -1.0f,     0.0f,     0.0f,     0.0f }
    };
    static UV_WORK* uvtble[2] = 
    {
        BH_UVTAB0,
        BH_UVTAB1
    };

    switch (op->mode0) 
    {
    case 0:
        op->tex_id  = 80;
        
        op->ani_ct  = 1;
        
        bhEff_SetBaseColor(op, 0x80FFFFFF);
        
        op->bl_src  = 8;
        op->bl_dst  = 3;
        
        op->flg    |= 0x24080000;
        
        bhEff_SetAlign(op, 3);
        
        op->mtn_no  = (int)(2.0f * (-rand() / -2.147483648E9f));
        op->frm_no  = 8.0f * (-rand() / -2.147483648E9f);
        
        op->sxb     = op->sx;
        op->syb     = op->sy;
        
        op->ct0     = 20;
        op->ct1     = 0;
        op->ct3     = 300.0f * (-rand() / -2.147483648E9f);
        
        op->ah      = 0.2f;
        op->aw      = 1.0f;

        if (op->type == 1) 
        {
            lp = &rom->lgtp[1];

            if (!(lp->flg & 0x1)) 
            {
                lp->ct0    = 0;
                
                lp->lkono  = 0;
                
                lp->vx     = 0;
                lp->vy     = 0;
                lp->vz     = 0;
            }

            lp->lkono++;
            
            lp->flg   |= 0x3;
            lp->type   = 13;
            
            lp->aspd   = 2;
            
            lp->lkflg  = 0;
            lp->lsrc   = 4;
            
            lp->nr     = 15.0f;
            lp->fr     = 20.0f;
            
            lp->vx    += op->px;
            lp->vy    += op->py;
            lp->vz    += op->pz;
            
            lp->px     = lp->vx / lp->lkono;
            lp->py     = lp->vy / lp->lkono;
            lp->pz     = lp->vz / lp->lkono;
            
            lp->r      = 3.0f;
            lp->g      = 1.8f;
            lp->b      = 0.7f;
        }

        op->mode0++;
        
        op->mode1  = 0;
        
        op->func   = (void*)bhEff_Draw3DSprite;

        px = plp->px - op->px;
        pz = plp->pz - op->pz;

        if ((njSqrt((px * px) + (pz * pz)) < (1.5f + plp->ar)) && ((!(plp->flg & 0x4)) && (!(plp->stflg & 0x80000000)))) 
        {
            plp->flg   |= 0x10004;
            plp->stflg |= 0x10000;
            
            plp->mode0  = 4;
            plp->mode2  = op->mode1;
            plp->mode3  = 0;
            
            plp->hp    -= 20;

            for (i = 0; i < 4; i++) 
            {
                ofp.x = 1.0f - (2.0f * (-rand() / -2.147483648E9f));
                ofp.y = -0.5f + (2.0f * (-rand() / -2.147483648E9f));

                if (op->mode1 != 0) 
                {
                    z = 1.3f;
                } 
                else
                {
                    z = -1.5f;
                }

                ofp.z = z;
            
                ln = 0.5f + (0.3f * (-rand() / -2.147483648E9f));
                
                bhEne_SetFireEffect(plp, 3, &ofp, ln, (int)(10.0f * (-rand() / -2.147483648E9f)) + 20);
            }
        }
    case 1:
        op->ah += 0.2f;
        
        if (op->ah <= 1.0f) 
        {
            break;
        }
        
        op->ah = 1.0f;
        
        op->mode0++;
        break;
    case 2:
        if (op->ct0-- == 0) 
        {
            op->mode0++;
        }
        
        if (op->ct3-- == 0) 
        {
            sys->ef.id    = 264;
            
            sys->ef.type  = 0;
            sys->ef.flg   = 1;
            
            sys->ef.px = op->px;
            sys->ef.py = 5.0f + op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.ax    = 0;
            sys->ef.ay    = 0;
            
            bhSetEffectTb((EF_WORK*)&sys->ef, NULL, NULL, 0);
            
            op->ct3 = (int)(200.0f * (-rand() / -2.147483648E9f)) + 200;
        }
        
        break;
    case 3:
        op->ah -= 0.02f;
        op->aw -= 0.01f;
        
        if (op->ah < 0.6f) 
        {
            op->ah   = 0.6f;
            op->aw   = 0.8f;
            
            op->ct3  = 128;
            
            op->mode0++;
        }
        
        break;
    case 4:
        op->ct3 -= 8;
        
        op->ah  -= 0.002f;
        op->aw  -= 0.001f;
        
        if (op->ct3 < 0)
        {
            if (op->type != 0) 
            {
                op->flg = 0;
                return;
            }
            
            op->mode0++;
            return;
        }
        
        bhEff_SetBaseColor(op, (op->ct3 << 24) | 0xFFFFFF);
        break;
    }

    uvp = &uvtble[op->mtn_no][op->frm_no];
    
    op->frm_no++;
    
    if (uvtble[op->mtn_no][op->frm_no].u < 0) 
    {
        op->frm_no = 0;
    }
    
    bhEff_SetUVInfo(op, uvp, 0.09375f);

    op->sx *= op->aw;
    op->sy *= op->ah;
    
    op->ay = bhArcTan2(cam.mtx[0][8], cam.mtx[0][10]);

    if (sys->ef_fncn < 128)
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhEff_E14_Fire2(O_WRK* op) 
{
    UV_WORK* uvp;
    float loz; // not from DWARF
    static UV_WORK BH_UVTAB0[12] = 
    {
        {  0.5f,  0.5f, 0.25f, 0.25f },
        { 0.25f,  0.5f, 0.25f, 0.25f },
        {  0.0f,  0.5f, 0.25f, 0.25f },
        { 0.75f, 0.25f, 0.25f, 0.25f },
        {  0.5f, 0.25f, 0.25f, 0.25f },
        { 0.25f, 0.25f, 0.25f, 0.25f },
        {  0.0f, 0.25f, 0.25f, 0.25f },
        { 0.75f,  0.0f, 0.25f, 0.25f },
        {  0.5f,  0.0f, 0.25f, 0.25f },
        { 0.25f,  0.0f, 0.25f, 0.25f },
        {  0.0f,  0.0f, 0.25f, 0.25f },
        { -1.0f,  0.0f,  0.0f,  0.0f }
    };
    static UV_WORK* uvtble[1] = 
    {
        BH_UVTAB0
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->flg    |= 0x4180080;
        
        op->bl_src  = 8;
        op->bl_dst  = 10;
        
        op->stflg  &= ~0x20;
        
        op->tex_id  = 9;
        
        bhEff_SetBaseColor(op, -1);
        
        op->lox = 1.0f - (2.0f * (-rand() / -2.147483648E9f));
        op->loy = -0.5f + (2.0f * (-rand() / -2.147483648E9f));

        if (op->mode1 != 0) 
        {
            loz = 1.3f;
        }
        else 
        {
            loz = -1.5f;
        }
        
        op->loz    = loz;
        
        op->lkwkp  = (unsigned char*)plp;
        op->lkono  = 3;
        
        op->sxb    = 2.0f;
        op->syb    = 2.0f;
        
        op->ct0    = 0xFF;
        
        op->mtn_no = 0;
        op->frm_no = 0;
        
        op->mode0++;
        break;
    case 1:
        if (op->frm_no == 0)
        {
            op->flg = 0;
            return;
        }
        
        op->sxb += 0.1f * (0.3f - op->sxb);
        op->syb += 0.1f * (0.3f - op->syb);
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
void bhEff_E14_Mucus(O_WRK* op) 
{
    UV_WORK* uvp;
    BH_PWORK* ep;
    int i;
    O_WRK* opp; // not from DWARF
    static UV_WORK BH_UVTAB0[9] = 
    {
        {   0.0f,    0.0f, 0.125f, 0.1875f },
        { 0.125f,    0.0f, 0.125f, 0.1875f },
        {  0.25f,    0.0f, 0.125f, 0.1875f },
        { 0.375f,    0.0f, 0.125f, 0.1875f },
        {   0.5f,    0.0f, 0.125f, 0.1875f },
        { 0.625f,    0.0f, 0.125f, 0.1875f },
        {  0.75f,    0.0f, 0.125f, 0.1875f },
        { 0.875f,    0.0f, 0.125f, 0.1875f },
        {  -1.0f,    0.0f,   0.0f,    0.0f }
    };
    static UV_WORK BH_UVTAB1[13] =
    {
        {   0.0f, 0.1875f, 0.125f, 0.1875f },
        { 0.125f, 0.1875f, 0.125f, 0.1875f },
        {  0.25f, 0.1875f, 0.125f, 0.1875f },
        { 0.375f, 0.1875f, 0.125f, 0.1875f },
        {   0.5f, 0.1875f, 0.125f, 0.1875f },
        { 0.625f, 0.1875f, 0.125f, 0.1875f },
        {  0.75f, 0.1875f, 0.125f, 0.1875f },
        { 0.875f, 0.1875f, 0.125f, 0.1875f },
        {   0.0f,  0.375f, 0.125f, 0.1875f },
        { 0.125f,  0.375f, 0.125f, 0.1875f },
        {  0.25f,  0.375f, 0.125f, 0.1875f },
        { 0.375f,  0.375f, 0.125f, 0.1875f },
        {  -1.0f,    0.0f,   0.0f,    0.0f }
    };
    static UV_WORK BH_UVTAB2[21] = 
    {
        {   0.5f,  0.375f, 0.125f, 0.1875f },
        { 0.625f,  0.375f, 0.125f, 0.1875f },
        {  0.75f,  0.375f, 0.125f, 0.1875f },
        { 0.875f,  0.375f, 0.125f, 0.1875f },
        {   0.0f, 0.5625f, 0.125f, 0.1875f },
        { 0.125f, 0.5625f, 0.125f, 0.1875f },
        {  0.25f, 0.5625f, 0.125f, 0.1875f },
        { 0.375f, 0.5625f, 0.125f, 0.1875f },
        {   0.5f, 0.5625f, 0.125f, 0.1875f },
        { 0.625f, 0.5625f, 0.125f, 0.1875f },
        {  0.75f, 0.5625f, 0.125f, 0.1875f },
        { 0.875f, 0.5625f, 0.125f, 0.1875f },
        {   0.0f,   0.75f, 0.125f, 0.1875f },
        { 0.125f,   0.75f, 0.125f, 0.1875f },
        {  0.25f,   0.75f, 0.125f, 0.1875f },
        { 0.375f,   0.75f, 0.125f, 0.1875f },
        {   0.5f,   0.75f, 0.125f, 0.1875f },
        { 0.625f,   0.75f, 0.125f, 0.1875f },
        {  0.75f,   0.75f, 0.125f, 0.1875f },
        { 0.875f,   0.75f, 0.125f, 0.1875f },
        {  -1.0f,    0.0f,   0.0f,    0.0f }
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
        op->tex_id  = 81;
        
        op->ani_ct  = 1;
        
        bhEff_SetBaseColor(op, -1);
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->flg   |= 0x24080000;
        
        op->mtn_no = 0;
        op->frm_no = 0;

        ep = ene;
        
        for (i = 0; i < sys->ewk_n; i++, ep++) 
        {
            if (((ep->flg & 0x1)) && (ep->id == 14))
            {
                op->lkwkp = (unsigned char*)ep;
                break;
            }
        }

        op->func   = (void*)bhEff_E14_MucusDraw;
        
        op->mode0++;
    case 1:
        uvp = &uvtble[0][op->frm_no];
        
        if (op->mode1 != 0) 
        {
            op->mode0++;
        }
        
        break;
    case 2:
        i = op->mode1 - 1;
        
        uvp = &uvtble[i][op->frm_no];
        
        op->frm_no++;
        
        if (uvtble[i][op->frm_no].u < 0) 
        {
            op->mode0++;
        }
        
        break;
    case 3:
        return;
    }

    if (op->lkwkp == NULL) 
    {
        return;
    }

    njUnitMatrix(NULL);
    
    njRotateY(NULL, op->ay);

    {
    NJS_POINT3 v;
    
    v.x = op->sz;
    v.y = 0;
    v.z = 0;
        
    njCalcVector(NULL, &v, &v);

    op->tv[2].x = op->px + v.x;
    op->tv[2].y = op->py + v.y;
    op->tv[2].z = op->pz + v.z;
        
    op->tv[3].x = op->px - v.x;
    op->tv[3].y = op->py - v.y;
    op->tv[3].z = op->pz - v.z;
    }

    opp = (O_WRK*)op->lkwkp;
    
    njSetMatrix(NULL, &opp->mlwP->owP[op->lkono].mtx);

    njTranslate(NULL, op->sx, op->sy, 0);
    njRotateZ(NULL, op->ax);

    {
    NJS_POINT3 v;
        
    v.x = op->sz;
    v.y = 0;
    v.z = 0;
        
    njCalcPoint(NULL, &v, (NJS_POINT3*)&op->tv[0].x);

    v.x = -op->sz;
    v.y = 0;
    v.z = 0;
        
    njCalcPoint(NULL, &v, (NJS_POINT3*)&op->tv[1].x);
    }

    bhEff_SetUVInfo(op, uvp, 0.125f);

    if (sys->ef_fncn < 128) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhEff_E14_MucusDraw(O_WRK* op)
{
    if (((op->flg & 0x1000000)) || ((op->stflg & 0x1000000))) 
    {
        return;
    } 
    else
    {
        njSetMatrix(NULL, cam.mtx);
        
        njTextureFilterMode(1);
        
        njSetTexture(&sys->ef_tlist);
        njSetTextureNum(sys->ef_tn[op->tex_id] + op->ani_ct);
        
        njColorBlendingMode(0, op->bl_src);
        njColorBlendingMode(1, op->bl_dst);
        
        njDrawTexture3DEx(op->tvp, op->pn, 1);
        
        njColorBlendingMode(0, 8);
        njColorBlendingMode(1, 6);
    }
}

// 100% matching!
void bhEff_DamagePoint(O_WRK* op) 
{
    switch (op->mode0) 
    {                            
    case 0:
        op->func = (void*)bhEff_DamagePointDraw;
        
        op->ct0 = 5;
        
        op->ofy = 0.6f;
        
        op->yn = 0.2f + bhGetGroundPosition((NJS_POINT3*)&op->px);
        
        op->mode0++;
        break;
    case 1:
        op->py += op->ofy;
        
        op->ofy -= 0.2f;
        
        if (op->py < op->yn) 
        {
            if (op->ct0-- == 0) 
            {
                op->mode0++;
                
                op->ct0 = 5;
            }
            
            op->ofy *= -0.4f;
            
            op->py = op->yn + (0.6f * (op->yn - op->py));
        }
        
        break;
    case 2:
        if (op->ct0-- == 0) 
        {
            op->flg = 0;
            return;
        }
        
        break;
    }
    
    if (sys->ef_fncn < 128) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhEff_DamagePointDraw(O_WRK* op)
{
    NJS_POINT2 pos;

    njProjectScreen(cam.mtx, (NJS_POINT3*)&op->px, &pos);
}

// 100% matching!
void bhEff_Draw3DSprite(O_WRK* op) 
{
    NJS_POINT3 pa, pb, pc;
    NJS_POINT3 vec;
    O_WRK* opp; // not from DWARF

    njPushMatrixEx();
    
    njSetMatrix(NULL, cam.mtx);
    
    njFogDisable();

    if ((op->flg & 0x20000000)) 
    {
        njTextureFilterMode(0);
    } 
    else
    {
        njTextureFilterMode(1);
    }

    if (!(op->stflg & 0x20)) 
    {
        njSetTexture(&sys->ef_tlist);
        njSetTextureNum(sys->ef_tn[op->tex_id] + op->ani_ct);
    }
    else 
    {
        njSetTexture(op->txp[0]);
        njSetTextureNum(op->tex_id + op->ani_ct);
    }

    njPushMatrixEx();

    if ((!(op->flg & 0x80)) || ((op->flg & 0x200000)))
    {
        njUnitMatrix(NULL);
        
        njTranslateEx((NJS_POINT3*)&op->px);
        njRotateEx((Angle*)&op->ax, 0);
        
        njGetMatrix(op->mtx);
    }
    else
    {
        opp = (O_WRK*)op->lkwkp;
        
        njSetMatrix(op->mtx, &opp->mlwP->owP[op->lkono].mtx);
        
        njTranslate(op->mtx, op->lox, op->loy, op->loz);
        njRotateXYZ(op->mtx, op->ax, op->ay, op->az);
    }

    njPopMatrixEx();
    
    njMultiMatrix(NULL, op->mtx);

    if ((op->flg & 0x100000))
    {
        njUnitRotPortion(NULL);
        njRotateZ(NULL, op->az);
        
        if ((sys->gm_flg & 0x4000)) 
        {
            if (sys->mr_pl.vx)
            {
                njRotateY(NULL, 32768);
            }
            
            if (sys->mr_pl.vy) 
            {
                njRotateX(NULL, 32768);
            }
        }
    }

    njScaleEx((NJS_VECTOR*)&op->sx);

    if ((op->flg & 0x20000)) 
    {
        njCalcPoint(NULL, (NJS_POINT3*)&op->tvp[0].x, &pa);
        njCalcPoint(NULL, (NJS_POINT3*)&op->tvp[1].x, &pb);
        njCalcPoint(NULL, (NJS_POINT3*)&op->tvp[2].x, &pc);
        
        njProjectScreen(NULL, (NJS_POINT3*)&op->tvp[0].x, (NJS_POINT2*)&pa);
        njProjectScreen(NULL, (NJS_POINT3*)&op->tvp[1].x, (NJS_POINT2*)&pb);
        njProjectScreen(NULL, (NJS_POINT3*)&op->tvp[2].x, (NJS_POINT2*)&pc);
        
        njGetPlaneNormal2(&pa, &pb, &pc, &vec);
        
        njUnitVector(&vec);

        if (vec.z < 0) 
        {
            op->stflg |= 0x10;
            
            njPopMatrixEx();
            return;
        }
        
        op->stflg &= ~0x10;
    }

    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);
    
    njDrawTexture3DEx(op->tvp, op->pn, 1);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();

    if ((sys->st_flg & 0x2)) 
    {
        njFogEnable();
    }
}

// 100% matching!
void bhEff_SetUVInfo(O_WRK* op, UV_WORK* uvp, float BaseSize)
{
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = op->tv[0].v;
    
    op->tv[2].u = op->tv[0].u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = op->tv[1].u;
    op->tv[3].v = op->tv[2].v;
    
    op->sx = (op->sxb * uvp->xs) / BaseSize;
    op->sy = (op->syb * uvp->ys) / BaseSize;
}

// 100% matching!
void bhEff_SetAlign(O_WRK* op, unsigned int flg) 
{
    if ((flg & 0x1))
    {
        if ((flg & 0x2)) 
        {
            op->tv[0].y = 2;
            op->tv[1].y = 2;
            op->tv[2].y = 0;
            op->tv[3].y = 0;
        } 
        else 
        {
            if ((flg & 0x4)) 
            {
                op->tv[0].y = 0;
                op->tv[1].y = 0;
                op->tv[2].y = -2;
                op->tv[3].y = -2;
            } 
            else 
            {
                op->tv[0].y = -1;
                op->tv[1].y = -1;
                op->tv[2].y = 1;
                op->tv[3].y = 1;
            }
        }
    } 
    else 
    {
        if ((flg & 0x4)) 
        {
            op->tv[0].y = 0;
            op->tv[1].y = 0;
            op->tv[2].y = 2;
            op->tv[3].y = 2;
        }
        else if ((flg & 0x2))
        {
            op->tv[0].y = -2;
            op->tv[1].y = -2;
            op->tv[2].y = 0;
            op->tv[3].y = 0;
        } 
        else 
        {
            op->tv[0].y = -1;
            op->tv[1].y = -1;
            op->tv[2].y = 1;
            op->tv[3].y = 1;
        }
    }
    
    op->tv[0].x = -1;
    op->tv[1].x = 1;
    op->tv[2].x = -1;
    op->tv[3].x = 1;
    
    op->tv[0].z = 0;
    op->tv[1].z = 0;
    op->tv[2].z = 0;
    op->tv[3].z = 0;
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
