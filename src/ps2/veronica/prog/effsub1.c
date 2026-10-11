#include "../../../ps2/veronica/prog/effsub1.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaGraphics3D.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NaView.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/weapon.h"
#include "../../../ps2/veronica/prog/main.h"

#pragma divbyzerocheck on 

STRIPPED_DOUBLE_CODE(); // check the "mwcc_hacks" header for more info

// 100% matching!
void bhEffDmy(O_WRK* op)
{
	op->flg = 0;
}

// 100% matching!
void bhEffFil(O_WRK* op) 
{
    switch (op->mode0) 
    {                    
    case 0:                               
        op->flg |= 0x1000000;
        
        op->tex_id = op->id;
        
        op->gidx = bhGetGidx(op);
        
        op->tv[0].x = 0;
        op->tv[0].y = 0;
        op->tv[0].z = 1.0869f;
        
        op->tv[1].x = 640.0f;
        op->tv[1].y = 0;
        op->tv[1].z = 1.0869f;
        
        op->tv[2].x = 0;
        op->tv[2].y = 480.0f;
        op->tv[2].z = 1.0869f;
        
        op->tv[3].x = 640.0f;
        op->tv[3].y = 480.0f;
        op->tv[3].z = 1.0869f;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->mode0 = 1;
        break;
    case 1:                                     
        if (((cam.flg & 0x8)) && (sys->fil_no == (op->id - 90))) 
        {
            switch (sys->fil_rt & 0x3) 
            {              
            case 0:                                 
                op->tv[0].u = 0;
                op->tv[0].v = 0;
                
                op->tv[1].u = 1.0f;
                op->tv[1].v = 0;
                
                op->tv[2].u = 0;
                op->tv[2].v = 1.0f;
                
                op->tv[3].u = 1.0f;
                op->tv[3].v = 1.0f;
                break;
            case 1:                               
                op->tv[0].u = 0;
                op->tv[0].v = 1.0f;
                
                op->tv[1].u = 0;
                op->tv[1].v = 0;
                
                op->tv[2].u = 1.0f;
                op->tv[2].v = 1.0f;
                
                op->tv[3].u = 1.0f;
                op->tv[3].v = 0;
                break;
            case 2:                              
                op->tv[0].u = 1.0f;
                op->tv[0].v = 1.0f;
                
                op->tv[1].u = 0;
                op->tv[1].v = 1.0f;
                
                op->tv[2].u = 1.0f;
                op->tv[2].v = 0;
                
                op->tv[3].u = 0;
                op->tv[3].v = 0;
                break;
            case 3:                              
                op->tv[0].u = 1.0f;
                op->tv[0].v = 0;
                
                op->tv[1].u = 1.0f;
                op->tv[1].v = 1.0f;
                
                op->tv[2].u = 0;
                op->tv[2].v = 0;
                
                op->tv[3].u = 0;
                op->tv[3].v = 1.0f;
                break;
            }
            
            op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col = (((((unsigned char)sys->fil_rt & 0xF0) | 0xF) & 0xFF) << 24) | 0xFFFFFF;
            
            op->mode0 = 2;
        }
        else 
        {
            op->flg |= 0x1000000;
            break;
        }
    case 2:          
        if ((!(cam.flg & 0x8)) || (sys->fil_no != (op->id - 90))) 
        {
            op->flg |= 0x1000000;
            
            op->mode0 = 1;
            break;
        }
        
        op->flg &= ~0x1000000;
        
        sys->ef_trs2d[sys->ef_trs2dn++] = op;
        break;
    }
}

// 100% matching!
void bhEffBG(O_WRK* op)
{
    switch (op->mode0)
    {
    case 0:
        op->flg = 0x4100001;
        
        op->tex_id = op->id;
        
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col = -1;
        
        op->tv[0].u = 0;
        op->tv[0].v = 0;
        
        op->tv[1].u = 0.625f;
        op->tv[1].v = 0;
        
        op->tv[2].u = 0;
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
void bhEff2D(O_WRK* op)
{
	float u;
    float v;
    
    switch (op->mode0) 
    {                           
    case 0:
        op->flg |= 0x1000000;
        
        op->tex_id = op->type;
        
        op->ani_ct = op->lkono;
        
        op->px = 0;
        op->py = 0;
        op->pz = 0;
        
        op->gidx = bhGetGidx(op);
        
        op->tv[0].u = 0;
        op->tv[0].v = 0;
        
        op->tv[1].u = 1.0f;
        op->tv[1].v = 0;
        
        op->tv[2].u = 0;
        op->tv[2].v = 1.0f;
        
        op->tv[3].u = 1.0f;
        op->tv[3].v = 1.0f;
        
        op->tv[0].col = 0xFFE0E0E0;
        op->tv[1].col = 0xFFE0E0E0;
        op->tv[2].col = 0xFFE0E0E0;
        op->tv[3].col = 0xFFE0E0E0;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->mode0 = 1;
        break;
    case 1:
        if (op->mode1 == 0) 
        {
            op->flg |= 0x1000000;
            break;
        }

        u = (op->sx / 4.0f) * (512.0f * (op->tv[1].u - op->tv[0].u));
        v = (op->sy / 4.0f) * (512.0f * (op->tv[2].v - op->tv[0].v));

        op->flg &= ~0x1000000;
        
        op->tv[0].x = op->px;
        op->tv[0].y = op->py;
        op->tv[0].z = 1.0f / op->sz;
        
        op->tv[1].x = op->px + u;
        op->tv[1].y = op->py;
        op->tv[1].z = 1.0f / op->sz;
        
        op->tv[2].x = op->px;
        op->tv[2].y = op->py + v;
        op->tv[2].z = 1.0f / op->sz;
        
        op->tv[3].x = op->px + u;
        op->tv[3].y = op->py + v;
        op->tv[3].z = 1.0f / op->sz;
        
        sys->ef_trs2d[sys->ef_trs2dn++] = op;
        break;
    }
}

// 100% matching!
void bhEff000(O_WRK* op) 
{
    NJS_POINT3 pos; 
    ATR_WORK* hp;  
    float py;      
    ATR_WORK* whp;  

    if ((sys->yk_ct == op->flr_no) || (op->py < -100.0f)) 
    {
        op->flg = 0;
        return;
    }
    
    sys->ef_pol[sys->ef_poln++] = op;
    
    switch (op->mode0) 
    {                              
    case 0:                                         
        op->tex_id = 5;
        
        op->ani_ct = 0;
        
        njCalcPoint(&((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx, (NJS_POINT3*)&op->lox, (NJS_POINT3*)&op->px);
        
        op->flg &= ~0x80; 
        
        if (op->mdlver == 0) 
        { 
            switch (op->type) 
            {                    
            case 0:                                 
                op->yn = 0.2f * (-rand() / -2.1474836E9f);
                op->zn = 0.65f + (0.1f * (-rand() / -2.1474836E9f));
                
                op->ayp = op->ay - ((int)(182.04445f * (110.0f + ((16.0f * (-rand() / -2.1474836E9f)) - 8.0f))) & 0xFFFF);
                break;
            case 1:                                 
                op->yn = 0;
                op->zn = 0.3f + (0.1f * (-rand() / -2.1474836E9f));
                
                op->ayp = op->ay - ((int)(182.04445f * (110.0f + ((16.0f * (-rand() / -2.1474836E9f)) - 8.0f))) & 0xFFFF);
                break;
            case 2:                                 
                op->yn = 0.1f * (-rand() / -2.1474836E9f);
                op->zn = 0.7f + (0.1f * (-rand() / -2.1474836E9f));
                
                op->ayp = op->ay - ((int)(182.04445f * (100.0f + ((16.0f * (-rand() / -2.1474836E9f)) - 8.0f))) & 0xFFFF);
                break;
            case 3:                                 
                op->yn = 0.2f + (0.1f * (-rand() / -2.1474836E9f));
                op->zn = 1.0f + (0.1f * (-rand() / -2.1474836E9f));
                
                op->ayp = op->ay - ((int)(182.04445f * (90.0f + ((16.0f * (-rand() / -2.1474836E9f)) - 8.0f))) & 0xFFFF);
                break;
            case 10:                                
                op->px += (0.2f * (-rand() / -2.1474836E9f)) - 0.1f;
                op->py -= 0.2f * (-rand() / -2.1474836E9f);
                op->pz += (0.2f * (-rand() / -2.1474836E9f)) - 0.1f;
                
                op->yn = -(0.1f + (0.2f * (-rand() / -2.1474836E9f)));
                op->zn = 0;
                
                op->ax = 16384;
                
                op->ayp = op->ay;
                break;
            }
        } 
        else 
        {
            op->yn = 0.1f * (-rand() / -2.1474836E9f);
            op->zn = 0.3f + (0.1f * (-rand() / -2.1474836E9f));
            
            op->ayp = op->ay - ((int)(182.04445f * (105.0f + ((12.0f * (-rand() / -2.1474836E9f)) - 6.0f))) & 0xFFFF);
        }
        
        op->ct1 = 0;
        op->ct0 = 0;
        
        op->mode0 = 1;
    case 1:                                         
        op->px -= op->zn * njSin(op->ayp);
        op->pz -= op->zn * njCos(op->ayp);
        op->py += op->yn;
        
        op->ay -= (int)(182.04445f * (40.0f * op->zn)) & 0xFFFF;
        op->ax -= (int)(182.04445f * (20.0f * op->zn)) & 0xFFFF;
        
        if ((op->stflg & 0x100000)) 
        {
            op->zn -= 0.005f;
            
            if (op->zn < 0) 
            {
                op->zn = 0;
            }
            
            if (op->yn > -0.25f) 
            {
                op->yn -= 0.01f;
            }
        } 
        else if (op->yn > -1.0f) 
        {
            op->yn -= 0.04f;
        }
        
        break;
    case 2:                                         
        if (op->zn > 0) 
        {
            op->ay -= (int)(182.04445f * (10.0f * op->zn)) & 0xFFFF;
            
            op->px -= op->zn * njSin(op->ayp);
            op->pz -= op->zn * njCos(op->ayp);
            
            op->zn -= 0.01f;
            break;
        }
        
        sys->ef_poln--;
        
        op->flg = 0;
        return;
    case 3:                                         
        pos.x = op->px;
        pos.y = 1.0f + op->py;
        pos.z = op->pz;
        
        py = 0.1f + bhGetGroundPosition((NJS_POINT3*)&op->px);
        
        hp = sys->htp; 
        
        if (hp != NULL) 
        {
            if (hp->type == 6) 
            {
                switch (hp->id) 
                {        
                case 0:                     
                    op->ayp = 0;
                    break;
                case 1:                     
                    op->ayp = 16384;
                    break;
                case 2:
                    op->ayp = 49152;
                    break;
                case 3:
                    op->ayp = 32768;
                    break;
                }
              
                op->ay += (op->ayp - op->ay) >> 1;
                
                op->px -= op->zn * njSin(op->ay + 16384);
                op->pz -= op->zn * njCos(op->ay + 16384);
                
                if (op->zn < 0.5f) 
                {
                    op->zn += 0.01f;
                }
                
                op->py += op->yn;
                
                if (op->yn > -1.0f) 
                {
                    op->yn -= 0.04f;
                }
                
                if (py > op->py) 
                {
                    op->py = py;
                }
                
                return;
            }
        }
        
        op->mode0 = 4;
    case 4:                                     
        op->px -= op->zn * njSin(op->ay + 16384);
        op->pz -= op->zn * njCos(op->ay + 16384);
        
        pos.x = op->px;
        pos.y = op->py - 0.1f;
        pos.z = op->pz;
        
        if (bhCheckWallType(&pos, 0x400, 0.1f, 0.1f) == NULL) 
        {
            op->py += op->yn;
            
            if ((op->stflg & 0x100000)) 
            {
                op->zn -= 0.005f;
                
                if (op->zn < 0)
                {
                    op->zn = 0;
                }
                
                if (op->yn > -0.25f) 
                {
                    op->yn -= 0.01f;
                }
            } 
            else if (op->yn > -1.0f) 
            {
                op->yn -= 0.04f;
            }
        } 
        else 
        {
            op->zn -= 0.01f;
            
            if (op->zn < 0) 
            {
                op->zn = 0;
                
                op->mode0 = 5;
            }
        }
        
        break;
    case 5:                                         
        sys->ef_poln--;
        
        op->flg = 0;
        return;
    }

    if (((sys->st_flg & 0x40)) && (!(op->stflg & 0x100000))) 
    {
        whp = bhCheckWater((NJS_POINT3*)&op->px);
        
        if (whp != NULL) 
        {
            op->stflg |= 0x100000;
            
            op->zn *= 0.25f;
            op->yn *= 0.25f;
            
            sys->ef.id = 15;
            
            sys->ef.flg = 1;
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = 2;
            
            sys->ef.sx = 0.25f;
            sys->ef.sy = 0.25f;
            sys->ef.sz = 0.25f;
            
            sys->ef.px = op->px;
            sys->ef.py = whp->py + whp->h;
            sys->ef.pz = op->pz;
            
            sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
    }
    
    if ((whp = bhCheckWallType((NJS_POINT3*)&op->px, op->flg, 0.1f, 0.1f)) != NULL) 
    {
        py = op->py;
        
        bhSetWallRefAngle(whp, (NJS_POINT3*)&op->px, 0.1f, 0.1f, &op->ayp);
        
        if ((op->py != py) && (op->yn < 0))
        {
            if ((op->stflg & 0x100000)) 
            {
                op->zn = 0;
                
                op->mode0 = 2;
                return;
            }
            else
            {
                op->py += 0.1f;
                
                if (whp->type == 6)
                {
                    op->yn = 0.5f * op->zn;
                    op->zn = 0.1f * op->zn;
                } 
                else 
                {
                    op->yn = 0.35f * -op->yn;
                    op->zn = 0.5f * op->zn;
                }
                
                if (fabsf(op->yn) < 0.1f) 
                {
                    op->ax = 0;
                    
                    op->yn = 0;
                    
                    if (whp->type == 6) 
                    {
                        op->mode0 = 3;
                        
                        op->zn = 0;
                    } 
                    else 
                    {
                        op->mode0 = 2;
                    }
                }
            }
        }
        
        if (op->ct0 == 0)
        {
            if (op->type == 10) 
            {
                op->zn = 0.1f + (0.1f * (-rand() / -2.1474836E9f));
                
                op->ayp = (int)(182.04445f * (360.0f * (-rand() / -2.1474836E9f))) & 0xFFFF;
            }
        }
        
        if (op->ct0 < 2) 
        {
            op->ct0++;
            
            CallYakkyouSe((NJS_POINT3*)&op->px, 262);
        }
        else if (op->type == 1)
        {
            sys->ef_poln--;
            
            op->flg = 0;
        }
    } 
    else if ((op->mode0 == 2) && (op->zn > 0)) 
    {
        op->mode0 = 1;
    }
}

// 100% matching!
void bhEff001(O_WRK* op) 
{
    BH_PWORK* pp;   
    NJS_POINT3 ps0; 
    NJS_POINT3 ps1; 
    int i;         
    int jno;        
    ML_WORK* mp;    
    float minx;    
    float minz;     
    float maxx;     
    float maxz;     
    float scx;      
    float scz;      

    switch (op->mode0) 
    {                             
    case 0:
        op->flg |= 0x8000000;
        
        op->mode0 = 1;
        break;
    case 1:
        pp = (BH_PWORK*)op->lkwkp;
        
        mp = pp->mlwP;
        
        op->ay = pp->ay; 
        
        if (op->mdlver == 0) 
        {
            if (!(pp->stflg & 0x2000)) 
            {
                op->py = bhGetGroundPosition((NJS_POINT3*)&op->px);
            } 
            else 
            {
                op->py = ((O_WRK*)pp->mlwP->owP)->pyb;
            }
        }
        
        if (op->type == 0) 
        {
            minx = minz = 100.0f; 
            maxx = maxz = -100.0f;
            
            ps0.y = 0;
            
            for (i = 0; i < 15; i++) 
            {
                jno = op->jno[i];
                
                if (jno == -1)
                {
                    break;
                }
                
                ps0.x = mp->owP[jno].mtx[12] - op->px;
                ps0.z = mp->owP[jno].mtx[14] - op->pz;  
                
                njUnitMatrix(NULL);
                njRotateY(NULL, -op->ay);
                
                njCalcPoint(NULL, &ps0, &ps1);
                
                if (minx > ps1.x) 
                {
                    minx = ps1.x;
                }
                
                if (minz > ps1.z)
                {
                    minz = ps1.z;
                }
                
                if (maxx < ps1.x)
                {
                    maxx = ps1.x;
                }
                
                if (maxz < ps1.z) 
                {
                    maxz = ps1.z;
                }
            }
            
            scx = 0.8f * (maxx - minx);
            scz = 0.8f * (maxz - minz);
            
            if (scx < op->sxb)
            {
                scx = op->sxb;
            }
            
            if (scz < op->szb)
            {
                scz = op->szb;
            }
            
            if (scx > (2.0f * op->sxb))
            {
                scx = 2.0f * op->sxb;
            }
            
            if (scz > (2.0f * op->szb)) 
            {
                scz = 2.0f * op->szb;
            }
            
            op->sx = scx;
            op->sz = scz;
        }
        
        if (!(pp->flg & 0x1))
        {
            op->flg = 0;
            break;
        }
        
        if ((((pp->stflg & 0x8)) || ((pp->stflg & 0x1000000)) || ((pp->mdflg & 0x1)) || ((pp->stflg & 0x40000000)) && (!(sys->pt_flg & 0x1))) || ((!(pp->stflg & 0x40000000)) && (!(sys->pt_flg & 0x2))))
        {
            op->flg |= 0x1000000;
            break;
        }
        
        op->flg &= ~0x1000000;
        
        sys->ef_mdf[sys->ef_mdfn++] = op;
    }
}

// 100% matching!
void bhEff002(O_WRK* op) 
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_v0[14] = 
    {
        { 0.0625f,  0.0f,     0.0625f,  0.0625f  },
        { 0.0625f,  0.0625f,  0.0625f,  0.0625f  },
        { 0.25f,    0.0f,     0.125f,   0.125f   },
        { 0.5f,     0.0f,     0.125f,   0.125f   },
        { 0.75f,    0.0f,     0.125f,   0.125f   },
        { 0.0f,     0.125f,   0.1875f,  0.1875f  },
        { 0.375f,   0.125f,   0.1875f,  0.1875f  },
        { 0.1875f,  0.3125f,  0.1875f,  0.1875f  },
        { 0.0f,     0.5f,     0.1875f,  0.1875f  },
        { 0.375f,   0.5f,     0.1875f,  0.1875f  },
        { 0.5625f,  0.125f,   0.21875f, 0.21875f },
        { 0.78125f, 0.125f,   0.21875f, 0.21875f },
        { 0.5625f,  0.34375f, 0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_v1[7] = 
    {
        { 0.0f,     0.5f,     0.1875f,  0.1875f  },
        { 0.1875f,  0.5f,     0.1875f,  0.1875f  },
        { 0.375f,   0.5f,     0.1875f,  0.1875f  },
        { 0.5625f,  0.125f,   0.21875f, 0.21875f },
        { 0.78125f, 0.125f,   0.21875f, 0.21875f },
        { 0.5625f,  0.34375f, 0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_v2[25] = 
    {
        { 0.0f,     0.0f,     0.0625f,  0.0625f  },
        { 0.0625f,  0.0f,     0.0625f,  0.0625f  },
        { 0.0f,     0.0625f,  0.0625f,  0.0625f  },
        { 0.0625f,  0.0625f,  0.0625f,  0.0625f  },
        { 0.125f,   0.0f,     0.125f,   0.125f   },
        { 0.25f,    0.0f,     0.125f,   0.125f   },
        { 0.375f,   0.0f,     0.125f,   0.125f   },
        { 0.5f,     0.0f,     0.125f,   0.125f   },
        { 0.625f,   0.0f,     0.125f,   0.125f   },
        { 0.75f,    0.0f,     0.125f,   0.125f   },
        { 0.875f,   0.0f,     0.125f,   0.125f   },
        { 0.0f,     0.125f,   0.1875f,  0.1875f  },
        { 0.1875f,  0.125f,   0.1875f,  0.1875f  },
        { 0.375f,   0.125f,   0.1875f,  0.1875f  },
        { 0.0f,     0.3125f,  0.1875f,  0.1875f  },
        { 0.1875f,  0.3125f,  0.1875f,  0.1875f  },
        { 0.0f,     0.5f,     0.1875f,  0.1875f  },
        { 0.1875f,  0.5f,     0.1875f,  0.1875f  },
        { 0.375f,   0.5f,     0.1875f,  0.1875f  },
        { 0.0f,     0.6875f,  0.1875f,  0.1875f  },
        { 0.5625f,  0.125f,   0.21875f, 0.21875f },
        { 0.78125f, 0.125f,   0.21875f, 0.21875f },
        { 0.5625f,  0.34375f, 0.21875f, 0.21875f },
        { 0.78125f, 0.34375f, 0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_v3[14] = 
    {
        { 0.0f,     0.0f,     0.0625f,  0.0625f  },
        { 0.0f,     0.0625f,  0.0625f,  0.0625f  },
        { 0.125f,   0.0f,     0.125f,   0.125f   },
        { 0.375f,   0.0f,     0.125f,   0.125f   },
        { 0.625f,   0.0f,     0.125f,   0.125f   },
        { 0.875f,   0.0f,     0.125f,   0.125f   },
        { 0.1875f,  0.125f,   0.1875f,  0.1875f  },
        { 0.0f,     0.3125f,  0.1875f,  0.1875f  },
        { 0.375f,   0.3125f,  0.1875f,  0.1875f  },
        { 0.1875f,  0.5f,     0.1875f,  0.1875f  },
        { 0.5625f,  0.125f,   0.21875f, 0.21875f },
        { 0.78125f, 0.125f,   0.21875f, 0.21875f },
        { 0.5625f,  0.34375f, 0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_v4[8] = 
    {
        { 0.875f,   0.0f,     0.125f,   0.125f   },
        { 0.75f,    0.0f,     0.125f,   0.125f   },
        { 0.625f,   0.0f,     0.125f,   0.125f   },
        { 0.5f,     0.0f,     0.125f,   0.125f   },
        { 0.375f,   0.0f,     0.125f,   0.125f   },
        { 0.25f,    0.0f,     0.125f,   0.125f   },
        { 0.125f,   0.0f,     0.125f,   0.125f   },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_v8[5] = 
    {
        { 0.375f,   0.3125f,  0.1875f,  0.1875f  },
        { 0.1875f,  0.5f,     0.1875f,  0.1875f  },
        { 0.5625f,  0.125f,   0.21875f, 0.21875f },
        { 0.5625f,  0.34375f, 0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_v9[7] = 
    {
        { 0.0f,     0.3125f,  0.1875f,  0.1875f  },
        { 0.1875f,  0.3125f,  0.1875f,  0.1875f  },
        { 0.375f,   0.3125f,  0.1875f,  0.1875f  },
        { 0.0f,     0.5f,     0.1875f,  0.1875f  },
        { 0.1875f,  0.5f,     0.1875f,  0.1875f  },
        { 0.5625f,  0.125f,   0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_vz[6] = 
    {
        { 0.0f,     0.0f,     0.0625f,  0.0625f  },
        { 0.0f,     0.0f,     0.0625f,  0.0625f  },
        { 0.0625f,  0.0f,     0.0625f,  0.0625f  },
        { 0.0625f,  0.0f,     0.0625f,  0.0625f  },
        { 0.0f,     0.0625f,  0.0625f,  0.0625f  },
        { 0.0625f,  0.0625f,  0.0625f,  0.0625f  }
    };
        
    switch (op->mode0) 
    {                              
    case 0:                                         
        op->tex_id = 2;
        
        op->tv[0].col = 0x80FFFFFF;
        op->tv[1].col = 0x80FFFFFF;
        op->tv[2].col = 0x80FFFFFF;
        op->tv[3].col = 0x80FFFFFF;
        
        switch (op->type) 
        {                        
        case 2:                                     
            op->tv[0].col = 0x60C0C0C0;
            op->tv[1].col = 0x60C0C0C0;
            op->tv[2].col = 0x60C0C0C0;
            op->tv[3].col = 0x60C0C0C0;
        case 0:                                     
        case 6:                                     
            op->bl_src = 8;
            op->bl_dst = 6;
            
            op->yn = 0;
            break;
        case 3:                                     
            op->xn = (-rand()        / -2147483648.0f) * 0.1 - 0.05f;
            op->yn = 0.1f + (-rand() / -2147483648.0f) * 0.1;
            op->zn = (-rand()        / -2147483648.0f) * 0.1 - 0.05f;
        case 5:                                     
            if (op->mdlver == 11) 
            {
                op->tv[0].col = 0x40FFFFFF;
                op->tv[1].col = 0x40FFFFFF;
                op->tv[2].col = 0x40FFFFFF;
                op->tv[3].col = 0x40FFFFFF;
            } 
            else 
            {
                op->tv[0].col = 0x40C0C0C0;
                op->tv[1].col = 0x40C0C0C0;
                op->tv[2].col = 0x40C0C0C0;
                op->tv[3].col = 0x40C0C0C0;
            }
            
            op->ani_ct = 1;
            
            op->bl_src = 8;
            op->bl_dst = 6;
            break;
        case 4:                                     
            op->bl_src = 8;
            op->bl_dst = 6;
            
            op->yn = 0;
            
            op->ani_ct = 1;
            break;
        case 7:                                     
            op->tv[0].col = 0x40FFFFFF;
            op->tv[1].col = 0x40FFFFFF;
            op->tv[2].col = 0x40FFFFFF;
            op->tv[3].col = 0x40FFFFFF;
            
            op->bl_src = 8;
            op->bl_dst = 10;
            
            op->spd = 64.0f;
            
            op->ani_ct = 1;
            break;
        case 8:                                     
            op->xn = op->lox;
            op->yn = op->loy;
            op->zn = op->loz;
            
            op->tv[0].col = 0x40FFFFFF;
            op->tv[1].col = 0x40FFFFFF;
            op->tv[2].col = 0x40FFFFFF;
            op->tv[3].col = 0x40FFFFFF;
            
            op->ani_ct = 1;
            
            op->bl_src = 8;
            op->bl_dst = 10;
            break;
        case 1:
            op->flg = 0x4100001;
            
            op->bl_src = 11;
            op->bl_dst = 3;
            
            op->xn = (-rand()        / -2147483648.0f) * 0.2 - 0.1f;
            op->yn = 0.4f + (-rand() / -2147483648.0f) * 0.3;
            op->zn = (-rand()        / -2147483648.0f) * 0.2 - 0.1f;
            
            op->ani_ct = 1;
            break;
        case 9:
            op->xn = ((-rand() / -2147483648.0f) * 0.1) - 0.05f;
            op->yn = op->sz;
            op->zn = ((-rand() / -2147483648.0f) * 0.1) - 0.05f;
            
            op->tv[0].col = 0xC0202020;
            op->tv[1].col = 0xC0202020;
            op->tv[2].col = 0xC0202020;
            op->tv[3].col = 0xC0202020;
            
            op->ani_ct = 1;
            
            op->bl_src = 8;
            op->bl_dst = 6;
            break;
        case 10:                                    
            op->bl_src = 8;
            op->bl_dst = 6;
            
            op->ct0 = op->lkono;
            op->ct3 = 128;
            break;
        }
        
        switch (op->mdlver) 
        {                        
        case 1:                                     
            uvp = uvinfo_v1;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 2:                                     
            uvp = uvinfo_v2;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 3:                                     
            uvp = uvinfo_v3;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 4:                                     
            uvp = uvinfo_v4;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 8:                                     
            uvp = uvinfo_v8;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 9:                                     
            uvp = uvinfo_v9;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 10:                                    
            uvp = uvinfo_vz;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 11:                                    
            uvp = uvinfo_v2;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        default:                                    
            uvp = uvinfo_v0;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        }
        
        op->mode0 = 1;
        
        if (op->type < 9)
        {
            return;
        }
        
        break;
    case 1:
        switch (op->type) 
        {
        case 0:
            if (op->ct0 < 4) 
            {
                sys->ef.id = 2;
                
                sys->ef.flg = 0x4100001;
                
                sys->ef.type = 10;
                
                sys->ef.flr_no = 0;
                
                sys->ef.mdlver = 10;
                
                sys->ef.px = op->px;
                sys->ef.py = op->py;
                sys->ef.pz = op->pz;
                
                sys->ef.sx = op->sxb;
                sys->ef.sy = op->syb;
                sys->ef.sz = op->szb;
                
                sys->ef.ay = sys->ef.ax = 0;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, op->ct0);
            }
        case 6:
            op->px += op->lox;
            op->py += op->loy;
            op->pz += op->loz;
            
            op->lox *= 0.9f;
            op->loy *= 0.9f;
            op->loz *= 0.9f;
            
            op->py += op->yn;
            
            if (op->yn < 0.1f) 
            {
                op->yn += 0.01f;
            }
            
            break;
        case 3:
        case 8:
            if ((op->flg & 0x80))
            {
                sys->ef.id = 2;
                
                sys->ef.flg = 0x4100001;
                
                if (op->type == 9) 
                {
                    sys->ef.type   = 9;
                    sys->ef.mdlver = 3;
                } 
                else
                {
                    sys->ef.type   = 3;
                    sys->ef.mdlver = 11;
                }
                
                sys->ef.flr_no = 0;
                
                sys->ef.px = op->px;
                sys->ef.py = op->py;
                sys->ef.pz = op->pz;
                
                sys->ef.sx = op->sxb;
                sys->ef.sy = op->syb;
                sys->ef.sz = op->szb;
                
                sys->ef.ay = sys->ef.ax = 0;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, op->ct0);
                
                op->flr_no--;
                
                if (op->flr_no <= 0) 
                {
                    op->flg = 0;
                }
                
                return; 
            } 
            else 
            {
                op->px += op->xn;
                op->py += op->yn;
                op->pz += op->zn;
                
                op->yn = op->yn * 0.9f;
            }

            break; 
        case 4:
            if (op->ct0 < 6) 
            {
                sys->ef.id = 2;
                
                sys->ef.flg = 0x4100001;
                
                sys->ef.type = 10;
                
                sys->ef.flr_no = 0;
                
                sys->ef.mdlver = 3;
                
                sys->ef.px = op->px;
                sys->ef.py = op->py;
                sys->ef.pz = op->pz;
                
                sys->ef.sx = op->sxb;
                sys->ef.sy = op->syb;
                sys->ef.sz = op->szb;
                
                sys->ef.ay = sys->ef.ax = 0;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, op->ct0);
            }
            
            op->px += op->lox;
            op->py += op->loy;
            op->pz += op->loz;
            
            op->lox *= 0.9f;
            op->loy *= 0.9f;
            op->loz *= 0.9f;
            break;
        case 1:
        case 9:
            op->px += op->xn;
            op->py += op->yn;
            op->pz += op->zn;
            
            op->yn = op->yn * 0.9f;
            break;
        case 7:
            op->tv[0].col = ((unsigned int)op->spd << 24) | 0xFFFFFF;
            op->tv[1].col = ((unsigned int)op->spd << 24) | 0xFFFFFF;
            op->tv[2].col = ((unsigned int)op->spd << 24) | 0xFFFFFF;
            op->tv[3].col = ((unsigned int)op->spd << 24) | 0xFFFFFF;
            
            op->spd *= 0.9f;
            break;
        case 10:
            op->tv[0].col = (op->ct3 << 24) | 0xFFFFFF;
            op->tv[1].col = (op->ct3 << 24) | 0xFFFFFF;
            op->tv[2].col = (op->ct3 << 24) | 0xFFFFFF;
            op->tv[3].col = (op->ct3 << 24) | 0xFFFFFF;
            
            op->ct3 -= 32;
            
            if (op->ct3 <= 0)
            {
                op->flg = 0;
                return;
            }
            
            break;
        }
    }

    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
        return;
    }
    
    op->sx = 4.0f * (op->sxb * uvp->xs);
    op->sy = 4.0f * (op->syb * uvp->ys);
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    if (op->type < 10)
    {
        op->ct0++;
    }
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhDrawWeaponEffect(O_WRK* op)
{
    UV_WORK* uvp;                 
    int i;                         
    int ani;                    
    NJS_TEXTURE_VTX tv[4], tvb[4];           
    float scl;                       
    float off;                       
    float* wkp;                  
    NJS_POINT3 fps;                 
    NJS_POINT3 pos;            
    NJS_LINE lp;                    
    float len;                     
    static UV_WORK uvinfo_t00[2][4] = 
    {
        {
            { 0.265625f, 0.0f,      0.09375f, 0.09375f },
            { 0.359375f, 0.0f,      0.1875f,  0.09375f },
            { 0.0f,      0.0f,      0.09375f, 0.09375f },
            { 0.09375f,  0.0f,      0.125f,   0.09375f }
        },
        {
            { 0.265625f, 0.109375f, 0.0625f,  0.0625f  },
            { 0.34375f,  0.109375f, 0.0625f,  0.0625f  },
            { 0.0f,      0.09375f,  0.09375f, 0.09375f },
            { 0.09375f,  0.09375f,  0.09375f, 0.09375f }
        }
    };
    static UV_WORK uvinfo_t01[2][9] = 
    {
        {
            { 0.625f,    0.0f,     0.0625f,  0.0625f  },
            { 0.796875f, 0.0625f,  0.09375f, 0.0625f  },
            { 0.96875f,  0.125f,   0.03125f, 0.09375f },
            { 0.640625f, 0.0625f,  0.0625f,  0.0625f  },
            { 0.6875f,   0.0f,     0.15625f, 0.0625f  },
            { 0.78125f,  0.34375f, 0.0625f,  0.125f   },
            { 0.21875f,  0.1875f,  0.0625f,  0.0625f  },
            { 0.0f,      0.1875f,  0.09375f, 0.0625f  },
            { 0.65625f,  0.34375f, 0.0625f,  0.125f   }
        },
        {
            { 0.546875f, 0.0f,     0.0625f,  0.0625f  },
            { 0.90625f,  0.0625f,  0.09375f, 0.0625f  },
            { 0.921875f, 0.125f,   0.03125f, 0.09375f },
            { 0.71875f,  0.0625f,  0.0625f,  0.0625f  },
            { 0.84375f,  0.0f,     0.15625f, 0.0625f  },
            { 0.859375f, 0.34375f, 0.0625f,  0.125f   },
            { 0.296875f, 0.1875f,  0.0625f,  0.0625f  },
            { 0.109375f, 0.1875f,  0.09375f, 0.0625f  },
            { 0.71875f,  0.34375f, 0.0625f,  0.125f   }
        }
    };
    static UV_WORK uvinfo_t03[2][4] = 
    {
        {
            { 0.0f,      0.3125f, 0.03125f, 0.03125f },
            { 0.046875f, 0.3125f, 0.03125f, 0.03125f },
            { 0.09375f,  0.3125f, 0.03125f, 0.03125f },
            { 0.140625f, 0.3125f, 0.03125f, 0.03125f }
        },
        {
            { 0.0f,      0.3125f, 0.03125f, 0.03125f },
            { 0.046875f, 0.3125f, 0.03125f, 0.03125f },
            { 0.0625f,   0.25f,   0.0625f,  0.0625f  },
            { 0.0f,      0.25f,   0.0625f,  0.0625f  }
        }
    };
    static short akpal[2][3] = 
    { 
        { 0, 0, 1 }, 
        { 0, 1, 1 } 
    };        
    
    njUnitMatrix(NULL);
    
    if ((((op->flg & 0x1000000)) || ((op->stflg & 0x1000000))) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40)))) 
    { 
        return;  
    }
    
    if ((op->flg & 0x20000000))
    {
        njTextureFilterMode(0);
    } 
    else 
    {
        njTextureFilterMode(1);
    }
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[op->tex_id] + op->ani_ct);
    
    if (!(op->flg & 0x1000)) 
    {
        if ((!(op->flg & 0x80)) || ((op->flg & 0x200000))) 
        {
            njTranslate(NULL, op->px, op->py, op->pz);
            njRotateXYZ(NULL, op->ax, op->ay, op->az);
            
            njGetMatrix(op->mtx);
        } 
        else 
        {
            njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
            
            njTranslate(op->mtx, op->lox, op->loy, op->loz); 
            njRotateXYZ(op->mtx, op->ax, op->ay, op->az);
        }
    }
    
    njSetMatrix(NULL, cam.mtx);
    
    njMultiMatrix(NULL, op->mtx);
    
    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);
    
    for (i = 0; i < op->pn; i++) 
    {
        tv[i].col = tvb[i].col = op->tvp->col;
    }
    
    ani = op->ct0 - 1;
    
    switch (op->type) 
    {
    case 0:
    case 5:
        njSetTextureNum(sys->ef_tn[op->tex_id] + ani);
        
        if (op->type == 0) 
        {
            if (op->mdlver == 0) 
            {
                scl = op->sx;
                
                if (ani == 0) 
                {
                    off = 0;
                } 
                else 
                {
                    off = 0.6f;
                }
            } 
            else 
            {
                off = 0.9f;
                
                if (ani == 0) 
                {
                    scl = 0.8f * op->sx;
                } 
                else
                {
                    scl = 0.6f * op->sx; 
                }
            }
            
            njScale(NULL, scl, scl, scl);
        } 
        else
        {
            off = 0;
            
            njScale(NULL, op->sx, op->sy, op->sz);
        }
        
        uvp = &uvinfo_t00[op->mdlver][ani * 2];
        
        tv[0].x = 0.5f;
        tv[0].y = -0.45f;
        tv[0].z = -0.45f;
        
        tv[1].x = 0.5f;
        tv[1].y = 0.45f;
        tv[1].z = -0.45f;
        
        tv[2].x = 0.5f;
        tv[2].y = -0.45f;
        tv[2].z = 0.45f;
        
        tv[3].x = 0.5f;
        tv[3].y = 0.45f;
        tv[3].z = 0.45f;
        
        tv[0].u = uvp->u;
        tv[0].v = uvp->v;
        
        tv[1].u = uvp->u + uvp->xs;
        tv[1].v = uvp->v;
        
        tv[2].u = uvp->u;
        tv[2].v = uvp->v + uvp->ys;
        
        tv[3].u = uvp->u + uvp->xs;
        tv[3].v = uvp->v + uvp->ys;
        
        njDrawTexture3DEx(tv, op->pn, 1);
        
        uvp = &uvinfo_t00[op->mdlver][(ani * 2) + 1];
        
        tv[0].x = 0;
        tv[0].y = 0;
        tv[0].z = -0.45f;
        
        tv[1].x = 1.8f - off;
        tv[1].y = 0;
        tv[1].z = -0.45f;
        
        tv[2].x = 0;
        tv[2].y = 0;
        tv[2].z = 0.45f;
        
        tv[3].x = 1.8f - off;
        tv[3].y = 0;
        tv[3].z = 0.45f;
        
        tv[1].u = uvp->u;
        tv[1].v = uvp->v;
        
        tv[0].u = uvp->u + uvp->xs;
        tv[0].v = uvp->v;
        
        tv[3].u = uvp->u;
        tv[3].v = uvp->v + uvp->ys;
        
        tv[2].u = uvp->u + uvp->xs;
        tv[2].v = uvp->v + uvp->ys;
        
        njDrawTexture3DEx(tv, op->pn, 1);
        
        tv[0].x = 0;
        tv[0].y = -0.45f;
        tv[0].z = 0;
        
        tv[1].x = 1.8f - off;
        tv[1].y = -0.45f;
        tv[1].z = 0;
        
        tv[2].x = 0;
        tv[2].y = 0.45f;
        tv[2].z = 0;
        
        tv[3].x = 1.8f - off;
        tv[3].y = 0.45f;
        tv[3].z = 0;
        
        njDrawTexture3DEx(tv, op->pn, 1);
        break;
    case 1:
    case 2:
        njSetTextureNum(sys->ef_tn[op->tex_id] + akpal[0][ani]);
        
        scl = op->sx * op->spd;
        
        njScale(NULL, scl, scl, scl); 
        
        if (op->mdlver == 0) 
        {
            off = 0;
        } 
        else
        {
            off = 0.2f;
        }
        
        uvp = &uvinfo_t01[op->mdlver][ani * 3];
        
        tv[0].x = 0.3f;
        tv[0].y = -0.25f - off;
        tv[0].z = -0.25f - off;

        tv[1].x = 0.3f;
        tv[1].y = 0.25f + off;
        tv[1].z = -0.25f - off;
        
        tv[2].x = 0.3f;
        tv[2].y = -0.25f - off;
        tv[2].z = 0.25f + off;
        
        tv[3].x = 0.3f;
        tv[3].y = 0.25f + off;
        tv[3].z = 0.25f + off;
        
        tv[0].u = uvp->u;
        tv[0].v = uvp->v;
        
        tv[1].u = uvp->u + uvp->xs;
        tv[1].v = uvp->v;
        
        tv[2].u = uvp->u;
        tv[2].v = uvp->v + uvp->ys;
        
        tv[3].u = uvp->u + uvp->xs;
        tv[3].v = uvp->v + uvp->ys;
        
        njDrawTexture3DEx(tv, op->pn, 1);
        
        uvp = &uvinfo_t01[op->mdlver][(ani * 3) + 1];
        
        tv[0].x = 0;
        tv[0].y = 0;
        tv[0].z = -0.45f - off;
        
        tv[1].x = 1.5f;
        tv[1].y = 0;
        tv[1].z = -0.45f - off;
        
        tv[2].x = 0;
        tv[2].y = 0;
        tv[2].z = 0.45f + off;
        
        tv[3].x = 1.5f;
        tv[3].y = 0;
        tv[3].z = 0.45f + off;
        
        tv[1].u = uvp->u;
        tv[1].v = uvp->v;
        
        tv[0].u = uvp->u + uvp->xs;
        tv[0].v = uvp->v;
        
        tv[3].u = uvp->u;
        tv[3].v = uvp->v + uvp->ys;
        
        tv[2].u = uvp->u + uvp->xs;
        tv[2].v = uvp->v + uvp->ys;
        
        njDrawTexture3DEx(tv, op->pn, 1);
        
        tv[0].x = 0;
        tv[0].y = -0.45f - off;
        tv[0].z = 0;
        
        tv[1].x = 1.5f;
        tv[1].y = -0.45f - off;
        tv[1].z = 0;
        
        tv[2].x = 0;
        tv[2].y = 0.45f + off;
        tv[2].z = 0;
        
        tv[3].x = 1.5f;
        tv[3].y = 0.45f + off;
        tv[3].z = 0;
        
        njDrawTexture3DEx(tv, op->pn, 1);
        
        njSetTextureNum(sys->ef_tn[op->tex_id] + akpal[1][ani]);
        
        njColorBlendingMode(0, 8);
        njColorBlendingMode(1, 10);
        
        uvp = &uvinfo_t01[op->mdlver][(ani * 3) + 2];
        
        tv[0].x = 0.3f;
        tv[0].y = -0.2f - off;
        tv[0].z = -1.0f - off;
        
        tv[1].x = 0.3f;
        tv[1].y = 0.2f + off;
        tv[1].z = -1.0f - off;
        
        tv[2].x = 0;
        tv[2].y = -0.2f - off;
        tv[2].z = 0;
        
        tv[3].x = 0;
        tv[3].y = 0.2f + off;
        tv[3].z = 0;

        tvb[0].x = 0.1f - off;
        tvb[0].y = 0; 
        tvb[0].z = -1.0f - off;
        
        tvb[1].x = 0.5f + off;
        tvb[1].y = 0;
        tvb[1].z = -1.0f - off;
        
        tvb[2].x = -0.2f - off;
        tvb[2].y = 0; 
        tvb[2].z = 0;
        
        tvb[3].x = 0.2f + off;
        tvb[3].y = 0; 
        tvb[3].z = 0;
        
        tv[0].u = uvp->u;
        tv[0].v = uvp->v;
        
        tv[1].u = uvp->u + uvp->xs;
        tv[1].v = uvp->v;
        
        tv[2].u = uvp->u;
        tv[2].v = uvp->v + uvp->ys;
        
        tv[3].u = uvp->u + uvp->xs;
        tv[3].v = uvp->v + uvp->ys;
        
        tvb[0].u = uvp->u;
        tvb[0].v = uvp->v;
        
        tvb[1].u = uvp->u + uvp->xs;
        tvb[1].v = uvp->v;
        
        tvb[2].u = uvp->u;
        tvb[2].v = uvp->v + uvp->ys;
        
        tvb[3].u = uvp->u + uvp->xs;
        tvb[3].v = uvp->v + uvp->ys;
        
        if ((op->type == 2) || (op->mdlver != 0))
        {
            for (i = 0; i < 4; i++) 
            {
                njDrawTexture3DEx(tv,  op->pn, 1);
                njDrawTexture3DEx(tvb, op->pn, 1);
                
                njRotateX(NULL, 16384);
            } 
        } 
        else
        {
            for (i = 0; i < 6; i++) 
            {
                njDrawTexture3DEx(tv,  op->pn, 1);
                njDrawTexture3DEx(tvb, op->pn, 1);
                
                njRotateX(NULL, 10922);
            } 
        }
        
        break;
    case 3:
        wkp = &op->pv->x; 
        
        njSetTextureNum(sys->ef_tn[op->tex_id] + 1);
        
        njScale(NULL, op->sx, op->sy, op->sz);
        
        for (i = 0; i < 8; i++) 
        {
            uvp = &uvinfo_t03[op->jno[i]][ani];
            
            tv[0].u = uvp->u;
            tv[0].v = uvp->v;
            
            tv[1].u = uvp->u + uvp->xs; 
            tv[1].v = uvp->v;
            
            tv[2].u = uvp->u;
            tv[2].v = uvp->v + uvp->ys;
            
            tv[3].u = uvp->u + uvp->xs;
            tv[3].v = uvp->v + uvp->ys;
            
            tvb[0].u = tv[0].u;
            tvb[0].v = tv[0].v;
            
            tvb[1].u = tv[1].u;
            tvb[1].v = tv[1].v;
            
            tvb[2].u = tv[2].u;
            tvb[2].v = tv[2].v;
            
            tvb[3].u = tv[3].u;
            tvb[3].v = tv[3].v;
            
            op->spd = 1.0f + ((1.4f * op->ct0) + (i % 3));
            
            njPushMatrixEx();
            
            njSetMatrix(NULL, op->mtx);
            
            njRotateX(NULL, wkp[0]);
            njRotateY(NULL, wkp[1]);
            
            fps.x = 0;
            fps.y = 0;
            fps.z = -1.0f - op->spd; 
            
            njCalcPoint(NULL, &fps, &pos);
            
            njPopMatrixEx();
            
            lp.px = op->px;
            lp.py = op->py;
            lp.pz = op->pz;
            
            lp.vx = pos.x - op->px;
            lp.vy = pos.y - op->py;
            lp.vz = pos.z - op->pz;
            
            if (bhCheckL2Wall(&lp, 0x400, &len) != 0) 
            {
                tv[0].x = 0;
                tv[0].y = -0.05f;
                tv[0].z = -len;
                
                tv[1].x = 0;
                tv[1].y = 0.05f;
                tv[1].z = -len;
                
                tv[2].x = 0;
                tv[2].y = -0.05f;
                tv[2].z = -0.5f;
                
                tv[3].x = 0;
                tv[3].y = 0.05f;
                tv[3].z = -0.5f;

                tvb[0].x = -0.05f;
                tvb[0].y = 0;
                tvb[0].z = -len;
                
                tvb[1].x = 0.05f;
                tvb[1].y = 0;
                tvb[1].z = -len;
                
                tvb[2].x = -0.05f;
                tvb[2].y = 0;
                tvb[2].z = -0.5f;
                
                tvb[3].x = 0.05f;
                tvb[3].y = 0;
                tvb[3].z = -0.5f;
            } 
            else
            {
                tv[0].x = 0;
                tv[0].y = -0.05f;
                tv[0].z = -1.0f - op->spd;
                
                tv[1].x = 0;
                tv[1].y = 0.05f;
                tv[1].z = -1.0f - op->spd;
                
                tv[2].x = 0;
                tv[2].y = -0.05f;
                tv[2].z = -0.5f;
                
                tv[3].x = 0;
                tv[3].y = 0.05f;
                tv[3].z = -0.5f;

                tvb[0].x = -0.05f;
                tvb[0].y = 0;
                tvb[0].z = -1.0f - op->spd;
                
                tvb[1].x = 0.05f;
                tvb[1].y = 0;
                tvb[1].z = -1.0f - op->spd;
                
                tvb[2].x = -0.05f;
                tvb[2].y = 0;
                tvb[2].z = -0.5f;
                
                tvb[3].x = 0.05f;
                tvb[3].y = 0;
                tvb[3].z = -0.5f;
            }
            
            njPushMatrixEx();
            
            njRotateX(NULL, *wkp++);
            njRotateY(NULL, *wkp++);
            
            njDrawTexture3DEx(tv,  op->pn, 1);
            njDrawTexture3DEx(tvb, op->pn, 1);
            
            njPopMatrixEx();
        }  
        
        break;
    case 4:
        njSetTextureNum(sys->ef_tn[op->tex_id] + akpal[0][ani]);
        
        scl = op->sx * op->spd; 
        
        njScale(NULL, scl, scl, scl);
        
        if (op->mdlver == 0) 
        {
            off = 0;
        } 
        else 
        {
            off = 0.2f;
        }
        
        uvp = &uvinfo_t01[op->mdlver][ani * 3]; 
        
        tv[0].z = -0.3f;
        tv[0].y = -0.25f - off;
        tv[0].x = -0.25f - off; 
        
        tv[1].z = -0.3f;
        tv[1].y = 0.25f + off;
        tv[1].x = -0.25f - off;
        
        tv[2].z = -0.3f;
        tv[2].y = -0.25f - off;
        tv[2].x = 0.25f + off;
        
        tv[3].z = -0.3f;
        tv[3].y = 0.25f + off;
        tv[3].x = 0.25f + off;
        
        tv[0].u = uvp->u;
        tv[0].v = uvp->v;
        
        tv[1].u = uvp->u + uvp->xs;
        tv[1].v = uvp->v;
        
        tv[2].u = uvp->u;
        tv[2].v = uvp->v + uvp->ys;
        
        tv[3].u = uvp->u + uvp->xs;
        tv[3].v = uvp->v + uvp->ys;
        
        njDrawTexture3DEx(tv, op->pn, 1);
        
        uvp = &uvinfo_t01[op->mdlver][(ani * 3) + 1];
        
        tv[0].z = -0.0f;
        tv[0].y = 0; 
        tv[0].x = -0.45f - off;
        
        tv[1].z = -1.5f;
        tv[1].y = 0;
        tv[1].x = -0.45f - off;
        
        tv[2].z = -0.0f;
        tv[2].y = 0;
        tv[2].x = 0.45f + off;
        
        tv[3].z = -1.5f;
        tv[3].y = 0;
        tv[3].x = 0.45f + off;
        
        tv[1].u = uvp->u;
        tv[1].v = uvp->v;
        
        tv[0].u = uvp->u + uvp->xs;
        tv[0].v = uvp->v;
        
        tv[3].u = uvp->u;
        tv[3].v = uvp->v + uvp->ys;
        
        tv[2].u = uvp->u + uvp->xs;
        tv[2].v = uvp->v + uvp->ys;
        
        njDrawTexture3DEx(tv, op->pn, 1);
        
        tv[0].z = -0.0f;
        tv[0].y = -0.45f - off;
        tv[0].x = 0;
        
        tv[1].z = -1.5f;
        tv[1].y = -0.45f - off;
        tv[1].x = 0;
        
        tv[2].z = -0.0f;
        tv[2].y = 0.45f + off;
        tv[2].x = 0;
        
        tv[3].z = -1.5f;
        tv[3].y = 0.45f + off;
        tv[3].x = 0;
        
        njDrawTexture3DEx(tv, op->pn, 1);
        
        njSetTextureNum(sys->ef_tn[op->tex_id] + akpal[1][ani]);
        
        njColorBlendingMode(0, 8);
        njColorBlendingMode(1, 10);

        uvp = &uvinfo_t01[op->mdlver][(ani * 3) + 2];
        
        tv[0].z = -0.3f;
        tv[0].y = -0.2f - off;
        tv[0].x = -1.0f - off;
        
        tv[1].z = -0.3f;
        tv[1].y = 0.2f + off;
        tv[1].x = -1.0f - off;
        
        tv[2].z = -0.0f;
        tv[2].y = -0.2f - off;
        tv[2].x = 0;
        
        tv[3].z = -0.0f;
        tv[3].y = 0.2f + off;
        tv[3].x = 0;
        
        tvb[0].z = -0.1f - off;
        tvb[0].y = 0;
        tvb[0].x = -1.0f - off;
        
        tvb[1].z = -0.5f + off;
        tvb[1].y = 0;
        tvb[1].x = -1.0f - off;
        
        tvb[2].z = -0.2f - off;
        tvb[2].y = 0;
        tvb[2].x = 0;
        
        tvb[3].z = -0.2f + off;
        tvb[3].y = 0;
        tvb[3].x = 0;
        
        tv[0].u = uvp->u;
        tv[0].v = uvp->v;
        
        tv[1].u = uvp->u + uvp->xs;
        tv[1].v = uvp->v;
        
        tv[2].u = uvp->u;
        tv[2].v = uvp->v + uvp->ys;
        
        tv[3].u = uvp->u + uvp->xs;
        tv[3].v = uvp->v + uvp->ys;
        
        tvb[0].u = uvp->u;
        tvb[0].v = uvp->v;
        
        tvb[1].u = uvp->u + uvp->xs;
        tvb[1].v = uvp->v;
        
        tvb[2].u = uvp->u;
        tvb[2].v = uvp->v + uvp->ys;
        
        tvb[3].u = uvp->u + uvp->xs;
        tvb[3].v = uvp->v + uvp->ys;
        
        if (op->mdlver != 0) 
        {
            for (i = 0; i < 4; i++) 
            {
                njDrawTexture3DEx(tv,  op->pn, 1);
                njDrawTexture3DEx(tvb, op->pn, 1);
                
                njRotateZ(NULL, 16384);
            } 
        } 
        else 
        {
            for (i = 0; i < 6; i++)
            {
                njDrawTexture3DEx(tv,  op->pn, 1);
                njDrawTexture3DEx(tvb, op->pn, 1);
                
                njRotateZ(NULL, 10922);
            } 
        }
        
        break;
    }
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
}

// 98.78% matching (matches on NGC)
void bhEff003(O_WRK* op)
{
    float* wkp;   
	int i;

    switch (op->mode0)
    {
    case 0:
        op->tex_id = 3;
        
        op->func = (void*)bhDrawWeaponEffect;
        
        switch (op->type)
        {
        case 0:
        case 1:
        case 2:
        case 4:
            op->tvp->col = -1;
            
            op->bl_src = 8;
            op->bl_dst = 10;
            break;
        case 3:
            op->tvp->col = -1;
            
            op->bl_src = 8;
            op->bl_dst = 6;
            
            wkp = (float*)op->pv;

            i = 8;
            
            while (i-- != 0)
            {
                *wkp++ = (int)(182.04445f * (45.0f * i)) & 0xFFFF;
                *wkp++ = -((int)(182.04445f * (70.0f + (15.0f * (-rand() / -2.1474836E9f)))) & 0xFFFF);
                
                if ((i % 3) == 0) 
                {
                    op->jno[i] = 1;
                }
                else 
                {
                    op->jno[i] = 0;
                }
            }
            
            break;
        case 5:
            op->tvp->col = -0x5FA0;
            
            op->bl_src = 9;
            op->bl_dst = 10;
            break;
        }
        
        op->ani_ct = 0;
        
        op->ct0 = op->ct1 = 0;
        
        op->mode0 = 1;
    case 1:
        switch (op->type)
        {
        case 0:
            if ((op->mdlver != 0) && (op->ct1 == 0))
            {
                op->ct1++;
                return;
            }

            break;
        case 1:
        case 2:
        case 4:
            if (op->ct0 != 1) 
            {
                op->spd = 0.8f;
            }
            else
            {
                op->spd = 1.0f;
            }
            
            break;
        case 3:
            break;
        }

        sys->ef_fnc[sys->ef_fncn++] = op;
        
        op->ct0++;
        
        if (op->ct0 >= op->flr_no) 
        {
            op->mode0 = 2;
        }
        
        break;
    case 2:
        op->flg = 0;
        break;
    }
}

// 100% matching!
void bhEff004()
{

}

// 100% matching!
void bhEff005(O_WRK* op)
{
    UV_WORK* uvp; 
	static UV_WORK uvinfo_l[13] = 
    {
        { 0.3125f,  0.5f,     0.0625f,  0.0625f  },
        { 0.375f,   0.4375f,  0.125f,   0.125f   },
        { 0.5f,     0.4375f,  0.15625f, 0.15625f },
        { 0.65625f, 0.4375f,  0.15625f, 0.15625f },
        { 0.8125f,  0.4375f,  0.15625f, 0.15625f },
        { 0.0f,     0.5625f,  0.1875f,  0.1875f  },
        { 0.1875f,  0.5625f,  0.1875f,  0.1875f  },
        { 0.375f,   0.59375f, 0.1875f,  0.1875f  },
        { 0.5625f,  0.59375f, 0.1875f,  0.1875f  },
        { 0.0f,     0.78125f, 0.21875f, 0.21875f },
        { 0.21875f, 0.78125f, 0.21875f, 0.21875f },
        { 0.4375f,  0.78125f, 0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_m[12] = 
    {
        { 0.0f,     0.25f,    0.0625f,  0.0625f  },
        { 0.0f,     0.15625f, 0.09375f, 0.09375f },
        { 0.09375f, 0.15625f, 0.125f,   0.125f   },
        { 0.21875f, 0.15625f, 0.15625f, 0.15625f },
        { 0.375f,   0.15625f, 0.15625f, 0.15625f },
        { 0.0f,     0.0f,     0.15625f, 0.15625f },
        { 0.15625f, 0.0f,     0.15625f, 0.15625f },
        { 0.3125f,  0.0f,     0.15625f, 0.15625f },
        { 0.46875f, 0.0f,     0.15625f, 0.15625f },
        { 0.625f,   0.0f,     0.15625f, 0.15625f },
        { 0.78125f, 0.125f,   0.15625f, 0.15625f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_s[14] = 
    {
        { 0.0f,    0.3125f, 0.0625f, 0.0625f  },
        { 0.0f,    0.5f,    0.0625f, 0.0625f  },
        { 0.0f,    0.375f,  0.0625f, 0.0625f  },
        { 0.0f,    0.4375f, 0.0625f, 0.0625f  },
        { 0.0625f, 0.3125f, 0.125f,  0.125f   },
        { 0.1875f, 0.3125f, 0.125f,  0.125f   },
        { 0.3125f, 0.3125f, 0.125f,  0.125f   },
        { 0.4375f, 0.3125f, 0.125f,  0.125f   },
        { 0.5625f, 0.3125f, 0.125f,  0.125f   },
        { 0.6875f, 0.3125f, 0.125f,  0.125f   },
        { 0.8125f, 0.3125f, 0.125f,  0.125f   },
        { 0.0625f, 0.4375f, 0.125f,  0.125f   },
        { 0.1875f, 0.4375f, 0.125f,  0.125f   },
        { -1.0f,   0.0f,    0.0f,    0.0f     }
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 5;
        
        op->flg |= 0x4100000;
        
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ct0 = 0;
        
        op->ani_ct = op->mdlver;
        
        op->mode0 = 1;
        break;
    }
    
    switch (op->type) 
    {                            
    case 0:
        uvp = &uvinfo_s[op->ct0];
        break;
    case 1:
        uvp = &uvinfo_m[op->ct0];
        break;
    case 2:
        uvp = &uvinfo_l[op->ct0];
        break;
    }
    
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
        return;
    }
    
    op->sx = 8.0f * (op->sxb * uvp->xs);
    op->sy = 8.0f * (op->syb * uvp->ys);
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff006(O_WRK* op) 
{
    UV_WORK* uvp;
	static UV_WORK uvinfo[8] = 
    {
        { 0.5f,     0.4375f,  0.15625f, 0.15625f },
        { 0.65625f, 0.4375f,  0.15625f, 0.15625f },
        { 0.8125f,  0.4375f,  0.15625f, 0.15625f },
        { 0.0f,     0.5625f,  0.1875f,  0.1875f  },
        { 0.1875f,  0.5625f,  0.1875f,  0.1875f  },
        { 0.375f,   0.59375f, 0.1875f,  0.1875f  },
        { 0.5625f,  0.59375f, 0.1875f,  0.1875f  },
        { 0.0f,     0.78125f, 0.21875f, 0.21875f }
    };
    
    switch (op->mode0) 
    {                            
    case 0:
        if (op->type == 0) 
        {
            op->tex_id = 6;
            
            op->tv[0].u = 0.5f;
            op->tv[0].v = 1.0f;
            
            op->tv[1].u = 0;
            op->tv[1].v = 0;
            
            op->tv[2].u = 1.0f;
            op->tv[2].v = 0;
            
            if (op->mdlver == 0) 
            {
                op->tv[0].col = 0xFFC0C0C0;
                op->tv[1].col = 0xFFC0C0C0;
                op->tv[2].col = 0xFFC0C0C0;
                op->tv[3].col = 0xFFC0C0C0;
            } 
            else 
            {
                op->tv[0].col = 0xFFC0C0C0;
                op->tv[1].col = 0xFFC0C0C0;
                op->tv[2].col = 0xFFC0C0C0;
                op->tv[3].col = 0xFFC0C0C0;
            }
            
            op->pn = 3;
            
            op->ani_ct = op->mdlver;
        } 
        else
        {
            op->tex_id = 5;
            
            uvp = &uvinfo[op->flr_no];
            
            op->tv[0].u = uvp->u;
            op->tv[0].v = uvp->v;
            
            op->tv[1].u = uvp->u + uvp->xs;
            op->tv[1].v = uvp->v;
            
            op->tv[2].u = uvp->u;
            op->tv[2].v = uvp->v + uvp->ys;
            
            op->tv[3].u = uvp->u + uvp->xs;
            op->tv[3].v = uvp->v + uvp->ys;
            
            op->pn = 4;
            
            op->ani_ct = 0;
            
            op->ct0 = 0xFF;
        }
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ax = op->ay = op->az = 0;
        
        op->mode0 = 1;
    case 1:
        if (op->type != 0) 
        {
            op->tv[0].col = (op->ct0 << 24) | 0xC0C0C0;
            op->tv[1].col = (op->ct0 << 24) | 0xC0C0C0;
            op->tv[2].col = (op->ct0 << 24) | 0xC0C0C0;
            op->tv[3].col = (op->ct0 << 24) | 0xC0C0C0;
            
            op->ct0--;
            
            if (op->ct0 <= 0)
            {
                op->flg = 0;
                break;
            }
        }
    default:
        if (op->mtx[0][13] < -100.0f) 
        {
            op->flg = 0;
            break;
        }
        
        if (op->mode0 != 0)
        {
            if (op->mdlver == 0) 
            {
                sys->ef_opq[sys->ef_opqn++] = op;
            }
            else 
            {
                sys->ef_trs[sys->ef_trsn++] = op;
            }
        } 
        
        break;
    }
}

// 100% matching!
void bhEff007(O_WRK* op) 
{
    switch (op->mode0) 
    {                            
    case 0:
        op->tex_id = 7;
        
        op->ani_ct = 0;
        
        njCalcPoint(&((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx, (NJS_POINT3*)&op->lox, (NJS_POINT3*)&op->px);
        
        op->gpy = 0.6f + bhGetGroundPosition((NJS_POINT3*)&op->px);
        
        op->flg &= ~0x80;
        
        op->yn = -0.3f;
        
        op->ct0 = 0;
        
        if (op->mdlver != 0) 
        {
            sys->obwp->mlwP->objP[2].evalflags |= 0x8;
        }
        
        op->mode0 = 1;
    case 1:
        if ((((sys->st_flg & 0x40)) && (!(op->stflg & 0x100000))) && (bhCheckWater((NJS_POINT3*)&op->px) != NULL)) 
        {
            op->stflg |= 0x100000;
            
            op->yn *= 0.25f;
            
            sys->ef.id = 15;
            
            sys->ef.flg = 1;
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = 1;
            
            sys->ef.sx = 0.8f;
            sys->ef.sy = 1.5f;
            sys->ef.sz = 0.8f;
            
            sys->ef.px = op->px;
            sys->ef.py = 1.0f + op->py;
            sys->ef.pz = op->pz; 
            
            sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
        
        op->py += op->yn;
        
        if ((op->stflg & 0x100000)) 
        {
            if (op->yn > -0.3f) 
            {
                op->yn -= 0.01f;
            }
        } 
        else
        {
            if (op->yn > -1.0f)
            {
                op->yn -= 0.05f;
            }
        }
        
        if (op->py < op->gpy) 
        {
            if ((op->stflg & 0x100000)) 
            {
                op->yn = 0;
            }
            else 
            {
                op->yn = 0.3f * -op->yn;
                
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 259, 0);
            }
            
            op->mode0 = 2;
            
            op->py = op->gpy;
            
            op->gpy -= 0.5f;
        }
        
        break;
    case 2:
        op->py += op->yn;
        
        if (op->yn > -1.0f) 
        {
            op->yn -= 0.05f;
        }
        
        if (op->ax < 16384)
        {
            op->ax += 1024;
        }
        
        if (op->py < op->gpy) 
        {
            op->yn = 0;
            op->py = op->gpy;
            
            op->flg = 0;
            return;
        }
        
        break;
    }
    
    sys->ef_pol[sys->ef_poln++] = op;
}

// 100% matching!
void bhEff008(O_WRK* op) 
{
    UV_WORK* uvp;
    static UV_WORK uvinfo_f0[11] = 
    {
        { 0.0f,    0.0f,    0.1875f, 0.1875f },
        { 0.1875f, 0.0f,    0.1875f, 0.1875f },
        { 0.375f,  0.0f,    0.1875f, 0.1875f },
        { 0.5625f, 0.0f,    0.1875f, 0.1875f },
        { 0.75f,   0.0f,    0.1875f, 0.1875f },
        { 0.0f,    0.1875f, 0.1875f, 0.1875f },
        { 0.1875f, 0.1875f, 0.1875f, 0.1875f },
        { 0.375f,  0.1875f, 0.1875f, 0.1875f },
        { 0.5625f, 0.1875f, 0.1875f, 0.1875f },
        { 0.75f,   0.1875f, 0.1875f, 0.1875f },
        { -1.0f,   0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK uvinfo_fst[11] = 
    {
        { 0.0f,    0.375f,  0.1875f, 0.1875f },
        { 0.1875f, 0.375f,  0.1875f, 0.1875f },
        { 0.375f,  0.375f,  0.1875f, 0.1875f },
        { 0.5625f, 0.375f,  0.1875f, 0.1875f },
        { 0.75f,   0.375f,  0.1875f, 0.1875f },
        { 0.0f,    0.5625f, 0.1875f, 0.1875f },
        { 0.1875f, 0.5625f, 0.1875f, 0.1875f },
        { 0.375f,  0.5625f, 0.1875f, 0.1875f },
        { 0.5625f, 0.5625f, 0.1875f, 0.1875f },
        { 0.75f,   0.5625f, 0.1875f, 0.1875f },
        { -1.0f,   0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK uvinfo_f1[9] = 
    {
        { 0.0f,   0.875f, 0.125f, 0.125f },
        { 0.125f, 0.875f, 0.125f, 0.125f },
        { 0.25f,  0.875f, 0.125f, 0.125f },
        { 0.375f, 0.875f, 0.125f, 0.125f },
        { 0.5f,   0.875f, 0.125f, 0.125f },
        { 0.625f, 0.875f, 0.125f, 0.125f },
        { 0.75f,  0.875f, 0.125f, 0.125f },
        { 0.875f, 0.875f, 0.125f, 0.125f },
        { -1.0f,  0.0f,   0.0f,   0.0f   }
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 8;
        
        op->flg |= 0x4100000;
        
        op->tv[0].x = -1.0f;
        op->tv[0].y = -2.0f;
        op->tv[0].z = 0;
        
        op->tv[1].x = 1.0f;
        op->tv[1].y = -2.0f;
        op->tv[1].z = 0;
        
        op->tv[2].x = -1.0f;
        op->tv[2].y = 0;
        op->tv[2].z = 0;
        
        op->tv[3].x = 1.0f;
        op->tv[3].y = 0;
        op->tv[3].z = 0;
        
        op->tv[0].col = 0xFFE0E0E0;
        op->tv[1].col = 0xFFE0E0E0;
        op->tv[2].col = 0xFFE0E0E0;
        op->tv[3].col = 0xFFE0E0E0;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        
        switch (op->type) 
        {                          
        case 1:
            uvp = uvinfo_f1;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 2:
            uvp = uvinfo_fst;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        default:
            uvp = uvinfo_f0;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        }
        
        op->mode0 = 1;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        if (op->type == 2) 
        {
            op->exp0 = (unsigned char*)uvinfo_f1;
            
            op->type = 0;
        }
        
        op->ct0 = 0;
        
        uvp = (UV_WORK*)op->exp0 + op->ct0;
    }
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff009(O_WRK* op) 
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_f0[9] = 
    {
        { 0.0f,   0.0f,   0.25f, 0.25f },
        { 0.25f,  0.0f,   0.25f, 0.25f },
        { 0.5f,   0.0f,   0.25f, 0.25f },
        { 0.75f,  0.0f,   0.25f, 0.25f },
        { 0.0f,   0.25f,  0.25f, 0.25f },
        { 0.25f,  0.25f,  0.25f, 0.25f },
        { 0.5f,   0.25f,  0.25f, 0.25f },
        { 0.75f,  0.25f,  0.25f, 0.25f },
        { -1.0f,  0.0f,   0.0f,  0.0f  }
    };
    static UV_WORK uvinfo_f1[9] = 
    {
        { 0.0f,     0.8125f, 0.0625f, 0.0625f },
        { 0.0625f,  0.8125f, 0.0625f, 0.0625f },
        { 0.125f,   0.8125f, 0.0625f, 0.0625f },
        { 0.1875f,  0.8125f, 0.0625f, 0.0625f },
        { 0.25f,    0.8125f, 0.0625f, 0.0625f },
        { 0.3125f,  0.8125f, 0.0625f, 0.0625f },
        { 0.375f,   0.8125f, 0.0625f, 0.0625f },
        { 0.4375f,  0.8125f, 0.0625f, 0.0625f },
        { -1.0f,    0.0f,    0.0f,    0.0f    }
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4100000;
        
        op->tv[0].x = -1.0f;
        op->tv[0].y = -2.0f;
        op->tv[0].z = 0;
        
        op->tv[1].x = 1.0f;
        op->tv[1].y = -2.0f;
        op->tv[1].z = 0;
        
        op->tv[2].x = -1.0f;
        op->tv[2].y = 0;
        op->tv[2].z = 0;
        
        op->tv[3].x = 1.0f;
        op->tv[3].y = 0;
        op->tv[3].z = 0;
        
        op->tv[0].col = 0xFFE0E0E0;
        op->tv[1].col = 0xFFE0E0E0;
        op->tv[2].col = 0xFFE0E0E0;
        op->tv[3].col = 0xFFE0E0E0;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ani_ct = 0;
        op->ct0 = 0;
        
        switch (op->type) 
        {                          
        case 1:
        case 2:
        case 3:
            op->tex_id = 8;
            
            uvp = uvinfo_f1;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        default:
            op->tex_id = 9;
            
            uvp = uvinfo_f0;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        }
        
        op->mode0 = 1;
    }
    
    if (op->type == 3) 
    {
        if ((sys->st_flg & 0x20000000)) 
        {
            goto label;
        } 
        else 
        {
            op->flg = 0;
        }
    } 
    else
    {
    label:
        if (op->type == 2) 
        {
            if (!(plp->flg & 0x1000000)) 
            {
                op->flg = 0;
                return;
            }
            
            if (!(((sys->pt_flg & 0x1)) && (!(plp->stflg & 0x1000000)) && (!(plp->mdflg & 0x1)))) 
            {
                return;
            }
            
            op->flg &= ~0x1000000;
        }
    
        uvp = (UV_WORK*)op->exp0 + op->ct0;
        
        if (uvp->u == -1.0f) 
        {
            op->ct0 = 0;
            
            uvp = (UV_WORK*)op->exp0 + op->ct0;
        }
        
        op->tv[0].u = uvp->u;
        op->tv[0].v = uvp->v;
        
        op->tv[1].u = uvp->u + uvp->xs;
        op->tv[1].v = uvp->v;
        
        op->tv[2].u = uvp->u;
        op->tv[2].v = uvp->v + uvp->ys;
        
        op->tv[3].u = uvp->u + uvp->xs;
        op->tv[3].v = uvp->v + uvp->ys;
        
        op->ct0++;
        
        sys->ef_trs[sys->ef_trsn++] = op;
    }
}

// 100% matching!
void bhEff010(O_WRK* op) 
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_f0[5] = 
    {
        { 0.0f,     0.640625f, 0.21875f, 0.21875f },
        { 0.21875f, 0.640625f, 0.21875f, 0.21875f },
        { 0.4375f,  0.640625f, 0.1875f,  0.15625f },
        { 0.625f,   0.65625f,  0.1875f,  0.15625f },
        { -1.0f,    0.0f,      0.0f,     0.0f     }
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 19;
        
        op->flg |= 0x4100000;
        
        op->tv[0].x = -1.0f;
        op->tv[0].y = -2.0f;
        op->tv[0].z = 0;
        
        op->tv[1].x = 1.0f;
        op->tv[1].y = -2.0f;
        op->tv[1].z = 0;
        
        op->tv[2].x = -1.0f;
        op->tv[2].y = 0;
        op->tv[2].z = 0;
        
        op->tv[3].x = 1.0f;
        op->tv[3].y = 0;
        op->tv[3].z = 0;
        
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        if (op->type < 2) 
        {
            op->bl_src = 11;
            op->bl_dst = 3;
        } 
        else 
        {
            op->bl_src = 8;
            op->bl_dst = 6;
        }
        
        op->yn = op->py;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
            
        op->exp0 = (unsigned char*)uvinfo_f0;
        
        op->mode0 = 1;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        if (op->type != 0) 
        {
            op->flg = 0;
            return;
        }
        
        op->py = op->yn;
        
        op->ct0 = 0;
        
        uvp = (UV_WORK*)op->exp0 + op->ct0;
    }
    
    if (op->type < 2) 
    {
        op->py += 0.8f;
    }
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff011(O_WRK* op)
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_t0[18] = 
    {
        { 0.28125f,   0.0f,       0.03125f,    0.03125f    },
        { 0.3125f,    0.0f,       0.0625f,     0.0625f     },
        { 0.375f,     0.0f,       0.0703125f,  0.0703125f  },
        { 0.4453125f, 0.0f,       0.08984375f, 0.08984375f },
        { 0.5390625f, 0.0f,       0.08984375f, 0.08984375f },
        { 0.15625f,   0.0f,       0.125f,      0.125f      },
        { 0.75f,      0.0f,       0.125f,      0.125f      },
        { 0.0f,       0.0f,       0.15625f,    0.15625f    },
        { 0.0f,       0.15625f,   0.171875f,   0.171875f   },
        { 0.171875f,  0.125f,     0.171875f,   0.171875f   },
        { 0.34375f,   0.125f,     0.1953125f,  0.1953125f  },
        { 0.5390625f, 0.1015625f, 0.2109375f,  0.2109375f  },
        { 0.09375f,   0.3203125f, 0.21875f,    0.203125f   },
        { 0.3125f,    0.3203125f, 0.21875f,    0.203125f   },
        { 0.53125f,   0.3203125f, 0.21875f,    0.203125f   },
        { 0.75f,      0.125f,     0.21875f,    0.203125f   },
        { 0.75f,      0.328125f,  0.21875f,    0.203125f   },
        { -1.0f,      0.0f, 0.0f, 0.0f                     }
    };
    static UV_WORK uvinfo_tb[17] = 
    {
        { 0.0f,     0.0f,     0.21875f, 0.21875f },
        { 0.21875f, 0.0f,     0.21875f, 0.21875f },
        { 0.4375f,  0.0f,     0.21875f, 0.21875f },
        { 0.65625f, 0.0f,     0.21875f, 0.21875f },
        { 0.0f,     0.21875f, 0.21875f, 0.21875f },
        { 0.21875f, 0.21875f, 0.21875f, 0.21875f },
        { 0.4375f,  0.21875f, 0.21875f, 0.21875f },
        { 0.65625f, 0.21875f, 0.21875f, 0.21875f },
        { 0.0f,     0.4375f,  0.21875f, 0.21875f },
        { 0.21875f, 0.4375f,  0.21875f, 0.21875f },
        { 0.4375f,  0.4375f,  0.21875f, 0.21875f },
        { 0.65625f, 0.4375f,  0.21875f, 0.21875f },
        { 0.0f,     0.65625f, 0.21875f, 0.21875f },
        { 0.21875f, 0.65625f, 0.21875f, 0.21875f },
        { 0.4375f,  0.65625f, 0.21875f, 0.21875f },
        { 0.65625f, 0.65625f, 0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_c0[10] = 
    {
        { 0.0f,     0.4375f, 0.125f,   0.125f   },
        { 0.125f,   0.4375f, 0.125f,   0.125f   },
        { 0.25f,    0.4375f, 0.125f,   0.125f   },
        { 0.15625f, 0.5625f, 0.15625f, 0.15625f },
        { 0.3125f,  0.5625f, 0.15625f, 0.15625f },
        { 0.46875f, 0.5625f, 0.15625f, 0.15625f },
        { 0.625f,   0.625f,  0.1875f,  0.1875f  },
        { 0.625f,   0.4375f, 0.1875f,  0.1875f  },
        { 0.8125f,  0.4375f, 0.1875f,  0.1875f  },
        { -1.0f,    0.0f,    0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_c1[11] = 
    {
        { 0.09375f, 0.0f,     0.09375f, 0.09375f },
        { 0.1875f,  0.0f,     0.09375f, 0.09375f },
        { 0.28125f, 0.0f,     0.09375f, 0.09375f },
        { 0.0f,     0.09375f, 0.09375f, 0.09375f },
        { 0.09375f, 0.09375f, 0.09375f, 0.09375f },
        { 0.1875f,  0.09375f, 0.125f,   0.125f   },
        { 0.375f,   0.0f,     0.125f,   0.125f   },
        { 0.5f,     0.0f,     0.15625f, 0.15625f },
        { 0.65625f, 0.0f,     0.15625f, 0.15625f },
        { 0.8125f,  0.0f,     0.15625f, 0.15625f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_c2[11] = 
    {
        { 0.09375f, 0.21875f, 0.09375f, 0.09375f },
        { 0.1875f,  0.21875f, 0.09375f, 0.09375f },
        { 0.28125f, 0.21875f, 0.09375f, 0.09375f },
        { 0.0f,     0.3125f,  0.09375f, 0.09375f },
        { 0.09375f, 0.3125f,  0.09375f, 0.09375f },
        { 0.1875f,  0.3125f,  0.125f,   0.125f   },
        { 0.375f,   0.21875f, 0.125f,   0.125f   },
        { 0.5f,     0.15625f, 0.15625f, 0.15625f },
        { 0.65625f, 0.15625f, 0.15625f, 0.15625f },
        { 0.8125f,  0.15625f, 0.15625f, 0.15625f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_c3[6] = 
    {
        { 0.5f,   0.3125f, 0.125f, 0.125f },
        { 0.625f, 0.3125f, 0.125f, 0.125f },
        { 0.75f,  0.3125f, 0.125f, 0.125f },
        { 0.875f, 0.3125f, 0.125f, 0.125f },
        { 0.5f,   0.4375f, 0.125f, 0.125f },
        { -1.0f,  0.0f,    0.0f,   0.0f   }
    };
    static UV_WORK uvinfo_c4[11] = 
    {
        { 0.0f,     0.71875f, 0.125f,   0.125f   },
        { 0.125f,   0.71875f, 0.125f,   0.125f   },
        { 0.25f,    0.71875f, 0.125f,   0.125f   },
        { 0.0f,     0.84375f, 0.15625f, 0.15625f },
        { 0.15625f, 0.84375f, 0.15625f, 0.15625f },
        { 0.3125f,  0.84375f, 0.15625f, 0.15625f },
        { 0.46875f, 0.84375f, 0.15625f, 0.15625f },
        { 0.625f,   0.8125f,  0.1875f,  0.1875f  },
        { 0.8125f,  0.8125f,  0.1875f,  0.1875f  },
        { 0.8125f,  0.625f,   0.1875f,  0.1875f  },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_smk[9] = 
    {
        { 0.0f,     0.5f,     0.1875f,  0.1875f  },
        { 0.1875f,  0.5f,     0.1875f,  0.1875f  },
        { 0.375f,   0.5f,     0.1875f,  0.1875f  },
        { 0.0f,     0.6875f,  0.1875f,  0.1875f  },
        { 0.5625f,  0.125f,   0.21875f, 0.21875f },
        { 0.78125f, 0.125f,   0.21875f, 0.21875f },
        { 0.5625f,  0.34375f, 0.21875f, 0.21875f },
        { 0.78125f, 0.34375f, 0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_oil[13] = 
    {
        { 0.0f,     0.0f,    0.0625f,  0.0625f  },
        { 0.0625f,  0.0f,    0.09375f, 0.09375f },
        { 0.15625f, 0.0f,    0.125f,   0.125f   },
        { 0.28125f, 0.0f,    0.125f,   0.125f   },
        { 0.40625f, 0.0f,    0.15625f, 0.15625f },
        { 0.5625f,  0.0f,    0.1875f,  0.1875f  },
        { 0.75f,    0.0f,    0.1875f,  0.1875f  },
        { 0.0f,     0.1875f, 0.1875f,  0.1875f  },
        { 0.1875f,  0.1875f, 0.1875f,  0.1875f  },
        { 0.375f,   0.1875f, 0.1875f,  0.1875f  },
        { 0.5625f,  0.1875f, 0.1875f,  0.1875f  },
        { 0.75f,    0.1875f, 0.1875f,  0.1875f  },
        { -1.0f,    0.0f,    0.0f,     0.0f     }
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->flg = 0x4100001;
        
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        if (op->lkono == 1) 
        {
            op->tv[0].x = 1.0f;
            op->tv[0].y = -1.0f;
            op->tv[0].z = 0;
            
            op->tv[1].x = -1.0f;
            op->tv[1].y = -1.0f;
            op->tv[1].z = 0;
            
            op->tv[2].x = 1.0f;
            op->tv[2].y = 1.0f;
            op->tv[2].z = 0;
            
            op->tv[3].x = -1.0f;
            op->tv[3].y = 1.0f;
            op->tv[3].z = 0;
        }
        
        switch (op->mdlver) 
        {                          
        case 0:                                     
            op->tex_id = 34;
            
            op->bl_src = 8;
            op->bl_dst = 10;
            
            op->px -= 0.5f * njSin(op->ay);
            op->pz -= 0.5f * njCos(op->ay);
            
            op->ani_ct = 0;
            op->ct0    = 0;
            
            switch (op->type) 
            {                    
            case 0:                                 
                op->xn = 0;
                
                if (op->lkono < 2)
                {
                    op->yn = 0.4f;
                }
                else 
                {
                    op->yn = 0.5f;
                }
                
                op->exp0 = (unsigned char*)uvinfo_tb;
                
                op->ani_ct = 1;
                break;
            case 1:                                 
                op->xn = 0;
                
                if (op->lkono < 2) 
                {
                    op->yn = 0.8f;
                }
                else 
                {
                    op->yn = 1.0f;
                }
                
                op->exp0 = (unsigned char*)uvinfo_tb;
                
                op->ani_ct = 1;
                break;
            case 2:                                 
                op->tex_id = 36;
                
                op->xn = 0;
                
                if (op->lkono < 2) 
                {
                    op->yn = 0.4f;
                } 
                else 
                {
                    op->yn = 0.5f;
                }
                
                op->exp0 = (unsigned char*)uvinfo_oil;
                break;
            case 10:                                
                op->xn = 0;
                
                if (op->lkono < 2) 
                {
                    op->yn = 0.2f;
                }
                else 
                {
                    op->yn = 0.25f;
                }
                
                op->exp0 = (unsigned char*)uvinfo_t0;
                break;
            case 11:                                
                op->xn = 0;
                
                if (op->lkono < 2) 
                {
                    op->yn = 0.4f;
                } 
                else 
                {
                    op->yn = 0.5f;
                }
                
                op->exp0 = (unsigned char*)uvinfo_t0;
                break;
            }
            
            break;
        case 1:                                     
            op->tex_id = 11;
            
            if (op->type != 3) 
            {
                op->bl_src = 8;
                op->bl_dst = 6;
            } 
            else 
            {
                op->bl_src = 8;
                op->bl_dst = 10;
            }
            
            op->ct0 = 0;
            
            switch (op->flr_no) 
            {
            case 1:
                op->px -= 0.5f * njSin(op->ay);
                op->pz -= 0.5f * njCos(op->ay);
                
                op->xn = 0.02f  * op->sx;
                op->yn = 0.333f * op->sy;
                break;
            default:
                op->xn = 0;
                op->yn = 0;
                break;
            }
            
            op->ani_ct = op->type;
            
            switch (op->type) 
            {                      
            case 0:                                 
                op->exp0 = (unsigned char*)uvinfo_c0;
                break;
            case 1:                                 
                op->exp0 = (unsigned char*)uvinfo_c1;
                break;
            case 2:                                 
                op->exp0 = (unsigned char*)uvinfo_c2;
                break;
            case 3:                                 
                op->exp0 = (unsigned char*)uvinfo_c3;
                break;
            case 4:                                 
                op->exp0 = (unsigned char*)uvinfo_c4;
                break;
            default:                                
                op->bl_src = 8;
                op->bl_dst = 10;
                
                op->exp0 = (unsigned char*)uvinfo_smk;
                
                op->tex_id = 2;
                
                op->tv[0].col = 0xC0FFDCC0;
                op->tv[1].col = 0xC0FFDCC0;
                op->tv[2].col = 0xC0FFDCC0;
                op->tv[3].col = 0xC0FFDCC0;
                
                op->ani_ct = 1;
                break;
            }
            
            break;
        }
        
        op->mode0 = 1;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
        return;
    }
    
    op->sx = 8.0f * (op->sxb * uvp->xs);
    op->sy = 8.0f * (op->syb * uvp->ys);
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    switch (op->mdlver) 
    {                            
    case 0:                                         
        op->px -= op->xn * njSin(op->ay);
        op->pz -= op->xn * njCos(op->ay);
        
        switch (op->type) 
        {                        
        case 0:      
        case 2:   
            op->py += op->yn;
            
            op->xn += 0.02f;
            op->yn -= 0.06f;
            break;
        case 1:                                     
            op->py += op->yn;
            
            op->xn += 0.03f;
            op->yn -= 0.15f;
            break;
        case 10:                                    
            op->py += op->yn;
            
            op->xn += 0.02f;
            op->yn -= 0.02f;
            break;
        case 11:                                    
            op->py += op->yn;
            
            op->xn += 0.03f;
            op->yn -= 0.035f;
            break;
        }
        
        break;
    case 1:                                         
        if (op->flr_no != 0) 
        {
            op->px -= op->xn * njSin(op->ay);
            op->pz -= op->xn * njCos(op->ay);
            op->py += op->yn;
            
            op->yn -= 0.03f;
        } 
        else
        {
            op->px += op->lox;
            op->py += op->loy;
            op->pz += op->loz;
            
            op->lox *= 0.7f;
            op->loy *= 0.7f;
            op->loz *= 0.7f;
        }
        
        break;
    }
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff012(O_WRK* op) 
{
    switch (op->mode0) 
    {
    case 0:
        op->flg = 0x4100001;
        
        op->tex_id = 5;
        
        op->pn = 3;
        
        op->pv[0].x = -1.0f;
        op->pv[0].y = -1.0f;
        op->pv[0].z = 0;
        
        op->pv[1].x = 1.0f;
        op->pv[1].y = -1.0f;
        op->pv[1].z = 0;
        
        op->pv[2].x = -1.0f;
        op->pv[2].y = 1.0f;
        op->pv[2].z = 0;
        
        op->pv[3].x = 1.0f;
        op->pv[3].y = 1.0f;
        op->pv[3].z = 0;
        
        op->pv[0].col = 0xFF800000;
        op->pv[1].col = 0xFF600000;
        op->pv[2].col = 0xFF200000;
        op->pv[3].col = 0xFF800000;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ani_ct = 0;
        
        switch (op->type) 
        {                          
        case 0:                                    
            op->xn = 0.5f * (0.2f + (-rand() / -2.1474836E9f));
            op->yn = 0.5f *         (-rand() / -2.1474836E9f);
            break;
        case 1:                                    
            op->xn = 0.2f * (0.2f + (-rand() / -2.1474836E9f));
            op->yn = 0.2f *         (-rand() / -2.1474836E9f);
            break;
        }
        
        op->az = 65536.0f * (-rand() / -2.1474836E9f);
        
        op->ct0   = 0;
        op->mode0 = 1;
        break;
    }
    
    op->px -= op->xn * njSin(op->ay);
    op->pz -= op->xn * njCos(op->ay);
    op->py += op->yn;
    
    switch (op->type)
    {                              
    case 0:                                         
        op->sx -= 0.003f;
        op->sy -= 0.003f;
        
        op->ct0++;
        
        if (op->ct0 >= 22) 
        {
            op->flg = 0;
            return;
        }
        
        op->xn -= 0.05f * op->xn;
        op->yn -= 0.04f;
        break;
    case 1:                                         
        op->ct0++;
        
        if (op->ct0 >= 14)
        {
            op->flg = 0;
            return;
        }
        
        op->xn -= 0.02f * op->xn;
        op->yn -= 0.025f;
    }

    sys->ef_ntx[sys->ef_ntxn++] = op;
}

// 100% matching!
void bhEff013(O_WRK* op)
{
    POINT lp;       
    NJS_POINT3 ps;  
    float len;     
    GA_WORK gat;    
    BH_PWORK* ep;   
    int aa;         
    float hh;       
    int id;         
    NJS_VECTOR vec, vc0, vc1; 
    
    switch (op->mode0) 
    {                              
    case 0:                                         
        op->gpx = op->px;
        op->gpy = op->py;
        op->gpz = op->pz;
        
        op->tex_id = 8;
        
        op->ani_ct = 0;
        
        op->ct3 = 100;
        
        op->xn = op->lox;
        op->yn = op->loy;
        op->zn = op->loz;
        
        njUnitVector((NJS_VECTOR*)&op->xn);
        
        aa = 2730;
        
        hh = 0;
        
        if (bhSearchNearEnemy((BH_PWORK*)op, &aa, &hh, &id) != 0) 
        {
            op->ct1 = id;
        }
        else 
        {
            op->ct1 = -1;
        }
        
        op->mode0 = 1;
    case 1:                                         
        bhSetEffect(140, (POINT*)&op->px, NULL, 0);
        
        op->px += op->lox;
        op->py += op->loy;
        op->pz += op->loz;
        
        lp.px = op->px;
        lp.py = op->py;
        lp.pz = op->pz;
        
        lp.ox = op->lox;
        lp.oy = op->loy;
        lp.oz = op->loz;
        
        njUnitVector((NJS_VECTOR*)&lp.ox);
        
        if (op->ct1 >= 0) 
        {
            ep = &ene[op->ct1];
            
            if ((((ep->flg & 0x1)) && ((ep->flg & 0x20)) && (!(ep->flg & 0x2))) && (!(ep->stflg & 0x41000000))) 
            {
                ps.x = 0.5f * (ep->watr.c1.x + ep->watr.c2.x);
                ps.y = 0.5f * (ep->watr.c1.y + ep->watr.c2.y);
                ps.z = 0.5f * (ep->watr.c1.z + ep->watr.c2.z);
                
                vec.x = ps.x - op->px;
                vec.y = ps.y - op->py;
                vec.z = ps.z - op->pz;
                
                njUnitVector(&vec);
                
                op->xn += 0.2f  * (vec.x - op->xn);
                op->yn += 0.05f * (vec.y - op->yn);
                op->zn += 0.2f  * (vec.z - op->zn);
                
                vc0.x = vec.x;
                vc0.y = 0;
                vc0.z = vec.z;
                
                vc1.x = lp.ox;
                vc1.y = 0;
                vc1.z = lp.oz;
                
                hh = njInnerProduct(&vc0, &vc1);
                
                if (hh > 0.5f) 
                {
                    op->ay = 10430.381f * atan2f(-op->xn, -op->zn);
                    op->ax = 10430.381f * asinf(op->yn);
                    
                    op->lox = 3.0f * op->xn;
                    op->loy = 3.0f * op->yn;
                    op->loz = 3.0f * op->zn;
                } 
                else 
                {
                    op->ct1 = -1;
                }
            } 
            else 
            {
                op->ct1 = -1;
            }
        }
        
        lp.ox *= 3.0f;
        lp.oy *= 3.0f;
        lp.oz *= 3.0f;
        
        if ((bhCheckWallType((NJS_POINT3*)&lp.px, 0x400, 2.0f, 1.0f) != NULL) && (bhCheckL2Wall((NJS_LINE*)&lp.px, 0x400, &len) != 0)) 
        {
            op->exp0 = &sys->ahtp->flg;
            
            if (op->mdlver != 0) 
            {
                op->mode0 = 3;
                
                op->px = sys->apos.x - lp.ox;
                op->py = sys->apos.y - lp.oy;
                op->pz = sys->apos.z - lp.oz;
                
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 281, 1);
                return;
            }
            
            if (bhCheckWallAttrB89(sys->ahtp) == 0) 
            {
                op->flg = 0;
                return;
            }
            
            op->px = sys->apos.x;
            op->py = sys->apos.y;
            op->pz = sys->apos.z;
            
            CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 270, 1);
            
            op->mode0 = 2;
            break;
        }
        
        op->ct3--;
        
        if ((op->ct3 <= 0) || ((sys->cb_flg & 0x4))) 
        {
            op->flg = 0;
            return;
        }
        
        gat.px = gat.gx = op->px - lp.ox;
        gat.py = gat.gy = op->py - lp.oy;
        gat.pz = gat.gz = op->pz - lp.oz;
        
        gat.vx = 2.0f * lp.ox;
        gat.vy = 2.0f * lp.oy;
        gat.vz = 2.0f * lp.oz;
        
        gat.at_flg = 0;
        
        if (op->mdlver == 0)
        {
            gat.wpn_no = 10;
        }
        else 
        {
            gat.wpn_no = 19;
        }
        
        gat.r = WpnTab[gat.wpn_no].r;
        gat.l = WpnTab[gat.wpn_no].l;
        
        gat.rmax = gat.rn = 0;
        
        gat.ax = op->ax;
        gat.ay = op->ay;
        
        if (bhCheckGunAtari(&gat) != 0) 
        {
            op->lox = gat.px;
            op->loy = gat.py;
            op->loz = gat.pz;
            
            op->lkono = gat.at_flg;
            op->lkwkp = (unsigned char*)&ene[gat.wpn_no];
            
            op->ax = gat.ax;
            op->ay = gat.ay;
            
            op->ct2 = gat.wpn_no;
            
            if (op->mdlver != 0) 
            {
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 281, 1);
                
                ene[gat.wpn_no].flg2 |= 0x4;
                
                op->mode0 = 3;
            } 
            else 
            {
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 269, 1);
                
                op->flg |= 0x80;
                
                op->mode0 = 2;
            }
        }
        else if (((sys->st_flg & 0x40)) && (op->mdlver != 0) && (bhCheckL2Water((NJS_LINE*)&lp.px, &ps) != NULL)) 
        {
            CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 281, 1);
            
            bhSetEffect(108, (POINT*)&ps, NULL, 12);
            
            sys->ef.id = 15;
            
            sys->ef.flg = 1;
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = 2;
            
            sys->ef.flr_no = 0;
            
            sys->ef.px = (ps.x + ((-rand() / -2.1474836E9f) - 0.5f)) - cam.vx;
            sys->ef.pz = (ps.z + ((-rand() / -2.1474836E9f) - 0.5f)) - cam.vz;
            sys->ef.py = ps.y - 1.0f;
            
            sys->ef.ay = 0;
            
            sys->ef.sx = 4.0f;
            sys->ef.sy = 1.2f + (0.25f * (-rand() / -2.1474836E9f));
            sys->ef.sz = 4.0f;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            bhSetWaterSplash4((NJS_POINT3*)&sys->ef.px, op->ay, 1, 1.6f, 1.6f, 1.6f);
            
            op->mode0 = 3;
        }
        
        break;
    case 2:                                                 
        if (!(op->flg & 0x80)) 
        {
            if (bhCheckWallAttrB89((ATR_WORK*)op->exp0) == 0) 
            {
                op->flg = 0;
                return;
            }
        } 
        else if (((O_WRK*)op->lkwkp)->id == 0) 
        {
            op->flg = 0;
            return;
        }
        
        op->ct0++;
        
        if ((op->ct0 >= 121) || ((sys->cb_flg & 0x4))) 
        {
            op->flg = 0;
            return;
        }
        
        break;
    case 3:                                         
        plp->stflg |= 0x100;
        
        switch (op->mode1) 
        {                        
        case 0:                                     
            gat.px = op->px;
            gat.py = op->py;
            gat.pz = op->pz;
            
            gat.gx = op->gpx;
            gat.gy = op->gpy;
            gat.gz = op->gpz;
            
            gat.vx = op->lox;
            gat.vy = op->loy;
            gat.vz = op->loz;
            
            gat.at_flg = 0;
            
            gat.wpn_no = 19;
            
            gat.r = 4.0f;
            gat.l = 1.0f;
            
            gat.rmax = gat.rn = 0;
            
            gat.ax = op->ax;
            gat.ay = op->ay;
            
            bhCheckFlyAtari(&gat, op->ct2);
            
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
            
            sys->ef.ax = sys->ef.ay = 0;
            
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
            
            sys->ef.ax = sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            op->ct0 = 0;
            
            op->mode1++;
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
                
                sys->ef.ax = sys->ef.ay = 0;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
                
                op->mode1++;
            }
            
            break;
        case 2:                                     
            op->flg = 0;
            return;
        }
    }
    
    if (op->mode0 < 3) 
    {
        sys->ef_pol[sys->ef_poln++] = op;
    }
}

// 100% matching!
void bhEff014(O_WRK* op) 
{
    UV_WORK* uvp;
    static UV_WORK uvinfo_f0[8] = 
    {
        { 0.0f,      0.484375f, 0.09375f, 0.09375f },
        { 0.109375f, 0.484375f, 0.09375f, 0.09375f },
        { 0.21875f,  0.484375f, 0.125f,   0.125f   },
        { 0.359375f, 0.484375f, 0.15625f, 0.15625f },
        { 0.53125f,  0.484375f, 0.15625f, 0.15625f },
        { 0.6875f,   0.484375f, 0.15625f, 0.15625f },
        { 0.84375f,  0.484375f, 0.15625f, 0.15625f },
        { -1.0f,     0.0f,      0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_f1[4] = 
    {
        { 0.15625f,  0.578125f, 0.0625f, 0.0625f },
        { 0.078125f, 0.578125f, 0.0625f, 0.0625f },
        { 0.0f,      0.578125f, 0.0625f, 0.0625f },
        { -1.0f,     0.0f,      0.0f,    0.0f    }
    };
    static UV_WORK uvinfo_f2[6] = 
    {
        { 0.40625f,  0.15625f, 0.0625f,  0.0625f  },
        { 0.484375f, 0.125f,   0.09375f, 0.09375f },
        { 0.59375f,  0.125f,   0.09375f, 0.09375f },
        { 0.703125f, 0.125f,   0.09375f, 0.09375f },
        { 0.8125f,   0.125f,   0.09375f, 0.09375f },
        { -1.0f,     0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_f3[1] = 
    {
        { 0.5625f, 0.0625f, 0.0625f, 0.0625f }
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 3;
        
        op->tv[0].col = 0xA0FFFFFF;
        op->tv[1].col = 0xA0FFFFFF;
        op->tv[2].col = 0xA0FFFFFF;
        op->tv[3].col = 0xA0FFFFFF;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->ani_ct = 0;
        op->ct0    = 0;
        
        switch (op->type) 
        {                         
        case 0:
            uvp = uvinfo_f0;
            
            op->ani_ct = 2;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 1:
            uvp = uvinfo_f1;
            
            op->ani_ct = 2;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 2:
            uvp = uvinfo_f2;
            
            op->ani_ct = 0;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 3:
            op->tv[0].x = 0;
            op->tv[0].y = -1.0f;
            op->tv[0].z = -1.0f;
            
            op->tv[1].x = 0;
            op->tv[1].y = 1.0f;
            op->tv[1].z = -1.0f;
            
            op->tv[2].x = 0;
            op->tv[2].y = -1.0f;
            op->tv[2].z = 1.0f;
            
            op->tv[3].x = 0;
            op->tv[3].y = 1.0f;
            op->tv[3].z = 1.0f;
            
            op->ct1 = 200;
            
            uvp = uvinfo_f3;
            
            op->ani_ct = 0;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        }
        
        op->mode0 = 1;
        break;
    }
    
    if (op->type == 2)
    {
        op->px += op->lox;
        op->py += op->loy;
        op->pz += op->loz;
        
        op->lox *= 0.8f;
        op->loy *= 0.8f;
        op->loz *= 0.8f;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (((op->type != 3) && (uvp->u == -1.0f)) || ((op->type == 3) && (op->ct1 <= 0))) 
    {
        op->flg = 0;
        return;
    }
    
    if (op->type != 3) 
    {
        op->sx = 8.0f * (op->sxb * uvp->xs);
        op->sy = 8.0f * (op->syb * uvp->ys);
        
        op->ct0++;
    } 
    else 
    {
        op->tv[0].col = (op->ct1 << 24) | 0xFFFFFF;
        op->tv[1].col = (op->ct1 << 24) | 0xFFFFFF;
        op->tv[2].col = (op->ct1 << 24) | 0xFFFFFF;
        op->tv[3].col = (op->ct1 << 24) | 0xFFFFFF;
        
        op->ct1 -= 4;
    }
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff015(O_WRK* op)
{
    UV_WORK* uvp; 
    float xn;     
	static UV_WORK uvinfo_t0[11] = 
    {
        { 0.0f,  0.0f,  0.25f, 0.25f },
        { 0.25f, 0.0f,  0.25f, 0.25f },
        { 0.5f,  0.0f,  0.25f, 0.25f },
        { 0.75f, 0.0f,  0.25f, 0.25f },
        { 0.0f,  0.25f, 0.25f, 0.25f },
        { 0.25f, 0.25f, 0.25f, 0.25f },
        { 0.5f,  0.25f, 0.25f, 0.25f },
        { 0.75f, 0.25f, 0.25f, 0.25f },
        { 0.0f,  0.5f,  0.25f, 0.25f },
        { 0.25f, 0.5f,  0.25f, 0.25f },
        { -1.0f, 0.0f,  0.0f,  0.0f  }
    };
    static UV_WORK uvinfo_t1[5] = 
    {
        { 0.5f,  0.5f,   0.25f, 0.125f },
        { 0.75f, 0.5f,   0.25f, 0.125f },
        { 0.5f,  0.625f, 0.25f, 0.125f },
        { 0.75f, 0.625f, 0.25f, 0.125f },
        { -1.0f, 0.0f,   0.0f,  0.0f   }
    };
    static UV_WORK uvinfo_t2[12] = 
    {
        { 0.09375f, 0.90625f, 0.125f,   0.09375f },
        { 0.21875f, 0.84375f, 0.125f,   0.15625f },
        { 0.34375f, 0.8125f,  0.125f,   0.1875f  },
        { 0.46875f, 0.6875f,  0.125f,   0.3125f  },
        { 0.59375f, 0.625f,   0.1875f,  0.375f   },
        { 0.78125f, 0.5625f,  0.21875f, 0.4375f  },
        { 0.0f,     0.53125f, 0.1875f,  0.375f   },
        { 0.1875f,  0.53125f, 0.15625f, 0.28125f },
        { 0.34375f, 0.53125f, 0.125f,   0.25f    },
        { 0.46875f, 0.53125f, 0.125f,   0.15625f },
        { 0.59375f, 0.53125f, 0.125f,   0.09375f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_oil[9] = 
    {
        { 0.375f,  0.375f,  0.1875f, 0.1875f },
        { 0.5625f, 0.375f,  0.1875f, 0.1875f },
        { 0.0f,    0.5625f, 0.1875f, 0.1875f },
        { 0.1875f, 0.5625f, 0.1875f, 0.1875f },
        { 0.375f,  0.5625f, 0.1875f, 0.1875f },
        { 0.5625f, 0.5625f, 0.1875f, 0.1875f },
        { 0.0f,    0.75f,   0.1875f, 0.1875f },
        { 0.1875f, 0.75f,   0.1875f, 0.1875f },
        { -1.0f,   0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK uvinfo_oilh[5] = 
    {
        { 0.375f,  0.75f,    0.1875f, 0.09375f },
        { 0.5625f, 0.75f,    0.1875f, 0.09375f },
        { 0.375f,  0.84375f, 0.1875f, 0.09375f },
        { 0.5625f, 0.84375f, 0.1875f, 0.09375f },
        { -1.0f,   0.0f,     0.0f,    0.0f     }
    };

    switch (op->mode0) 
    {
    case 0:
        op->flg = 0x4100001;
        
        op->tex_id = 33;
        
        op->tv[0].col = 0xA0FFFFFF;
        op->tv[1].col = 0xA0FFFFFF;
        op->tv[2].col = 0xA0FFFFFF;
        op->tv[3].col = 0xA0FFFFFF;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ani_ct = 0;
        
        switch (op->type) 
        {                          
        case 0:                                     
            op->xn = 0.7f;
            op->yn = 0.2f;
            
            uvp = uvinfo_t0;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 1:                                     
            uvp = uvinfo_t1;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 2:                                     
            op->tex_id = 34;
            
            op->bl_src = 8;
            op->bl_dst = 10;
            
            op->tv[0].x = -1.0f;
            op->tv[0].y = -2.0f;
            op->tv[0].z = 0;
            
            op->tv[1].x = 1.0f;
            op->tv[1].y = -2.0f;
            op->tv[1].z = 0;
            
            op->tv[2].x = -1.0f;
            op->tv[2].y = 0;
            op->tv[2].z = 0;
            
            op->tv[3].x = 1.0f;
            op->tv[3].y = 0;
            op->tv[3].z = 0;
            
            uvp = uvinfo_t2;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 3:                                     
            op->tex_id = 31;
            
            op->xn = 0.4f;
            op->yn = 0.3f;
            
            uvp = uvinfo_t0;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 4:                                     
            op->tex_id = 31;
            
            uvp = uvinfo_t1;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 5:                                     
            op->tex_id = 36;
            
            uvp = uvinfo_oil;
            
            op->gpx = op->px;
            op->gpy = op->py;
            op->gpz = op->pz;
            
            op->xn = op->sz;
            op->yn = op->sy;
            
            op->sx = op->sxb = op->sx;
            op->sy = op->syb = op->sx;
            op->sz = op->szb = op->sx;
            
            op->ct1 = op->mdlver;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 6:                                     
            op->tex_id = 36;
            
            uvp = uvinfo_oilh;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        }
        
        op->ct0   = 0;
        op->mode0 = 1;
        break;
    }
    
    if (op->type == 2) 
    {
        if (op->flr_no > 0) 
        {
            op->flg |= 0x1000000;
            
            op->flr_no--;
            return;
        }
        
        op->flg &= ~0x1000000; 
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        if (op->type == 5) 
        {
            op->ct0 = 0;
            
            uvp = (UV_WORK*)op->exp0 + op->ct0;
        }
        else 
        {
            op->flg = 0;
            
            if ((op->type == 0) || (op->type == 3)) 
            {
                sys->ef.id = 15;
                
                sys->ef.flg = 0x4100001;
                
                sys->ef.mdlver = 0;
                
                sys->ef.type = op->type + 1;
                
                sys->ef.sx = 2.0f;
                sys->ef.sy = 2.0f;
                sys->ef.sz = 2.0f;
                
                sys->ef.px = op->px + ((2.0f * (-rand() / -2.1474836E9f)) - 1.0f);
                sys->ef.py = op->py;
                sys->ef.pz = op->pz + ((2.0f * (-rand() / -2.1474836E9f)) - 1.0f);
                
                sys->ef.ay = 0;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            }
            
            return;
        }
    }
    
    if (op->type == 2) 
    {
        op->sx = 8.0f * (op->sxb * uvp->xs);
        op->sy = 8.0f * (op->syb * uvp->ys);
    }
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    switch (op->type) 
    {                        
    case 0:  
    case 3:
        op->sx += 0.1f;
        op->sy += 0.1f;
        
        op->px -= op->xn * njSin(op->ay);
        op->pz -= op->xn * njCos(op->ay);
        op->py += op->yn;
        
        op->xn -= 0.07f * op->xn;
        op->yn -= 0.15f; 
        break; 
    case 5:   
        xn = op->xn * -njSin(op->ct1);
        
        op->px = op->gpx + (xn     * njSin(op->ay));
        op->pz = op->gpz + (xn     * njCos(op->ay));
        op->py = op->gpy + (op->yn * njCos(op->ct1));
        
        op->sx += 0.001f;
        
        op->ct1 += 512;
        
        if (op->ct1 >= 16384) 
        {
            op->flg = 0;
            
            sys->ef.id = 15;
            
            sys->ef.flg = 0x4100001;
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = op->type + 1;
            
            sys->ef.sx = 1.2f * op->sx;
            sys->ef.sy = 1.2f * op->sy;
            sys->ef.sz = 1.2f * op->sz;
            
            sys->ef.px = op->px + ((-rand() / -2.1474836E9f) - 0.5f);
            sys->ef.py = op->py;
            sys->ef.pz = op->pz + ((-rand() / -2.1474836E9f) - 0.5f);
            
            sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            return;
        }
        
        break;
    case 2:
        break;
    }
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff016(O_WRK* op)
{
    float ar; // not from DWARF

    ar = 20.0f;
    
    op->ct0++;

    if (op->ct0 >= op->lkono)
    {
        bhCheckBombAtari((NJS_POINT3*)&op->px, (float)ar, 150, 100);

        op->flg = 0;
    }
}

// 100% matching!
void bhEff017(O_WRK* op)
{
    ATR_WORK* hp; // not from DWARF
    
    if ((((O_WRK*)op->lkwkp)->stflg & 0x1000000))
    {
        hp = &sys->mwalp[((O_WRK*)op->lkwkp)->ct0];
        
        hp->flg &= ~0x1;  
    }
}

// 100% matching!
void bhEff018(O_WRK* op)
{
    NJS_POINT3 pos;
	UV_WORK* uvp;
	static UV_WORK uvinfo_fst[8] = 
    {
        { 0.0f,    0.6875f, 0.125f,  0.125f  },
        { 0.125f,  0.6875f, 0.125f,  0.125f  },
        { 0.0f,    0.8125f, 0.1875f, 0.1875f },
        { 0.1875f, 0.8125f, 0.1875f, 0.1875f },
        { 0.375f,  0.8125f, 0.1875f, 0.1875f },
        { 0.5625f, 0.75f,   0.1875f, 0.25f   },
        { 0.75f,   0.75f,   0.1875f, 0.25f   },
        { -1.0f,   0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK uvinfo_fl[11] = 
    {
        { 0.0f,    0.0f,     0.1875f, 0.25f    },
        { 0.1875f, 0.0f,     0.1875f, 0.25f    },
        { 0.375f,  0.0f,     0.1875f, 0.25f    },
        { 0.5625f, 0.0f,     0.1875f, 0.25f    },
        { 0.75f,   0.0f,     0.1875f, 0.25f    },
        { 0.0f,    0.25f,    0.1875f, 0.21875f },
        { 0.1875f, 0.25f,    0.1875f, 0.21875f },
        { 0.375f,  0.25f,    0.1875f, 0.21875f },
        { 0.5625f, 0.25f,    0.1875f, 0.21875f },
        { 0.0f,    0.46875f, 0.1875f, 0.21875f },
        { -1.0f,   0.0f,     0.0f,    0.0f     }
    };
    static UV_WORK uvinfo_fs[9] = 
    {
        { 0.75f,   0.53125f, 0.1875f, 0.15625f },
        { 0.0f,    0.6875f,  0.1875f, 0.15625f },
        { 0.1875f, 0.6875f,  0.1875f, 0.15625f },
        { 0.375f,  0.6875f,  0.1875f, 0.15625f },
        { 0.5625f, 0.6875f,  0.1875f, 0.15625f },
        { 0.75f,   0.6875f,  0.1875f, 0.15625f },
        { 0.0f,    0.6875f,  0.1875f, 0.15625f },
        { 0.1875f, 0.6875f,  0.1875f, 0.15625f },
        { -1.0f,   0.0f,     0.0f,    0.0f     }
    };
    static UV_WORK uvinfo_fl2s[4] = 
    {
        { 0.1875f, 0.46875f, 0.1875f, 0.21875f },
        { 0.375f,  0.46875f, 0.1875f, 0.21875f },
        { 0.5625f, 0.46875f, 0.1875f, 0.21875f },
        { -1.0f,   0.0f,     0.0f,    0.0f     }
    };
    static UV_WORK uvinfo_fed[4] = 
    {
        { 0.375f,  0.6875f, 0.1875f, 0.15625f },
        { 0.5625f, 0.6875f, 0.1875f, 0.15625f },
        { 0.75f,   0.6875f, 0.1875f, 0.15625f },
        { -1.0f,   0.0f,    0.0f,    0.0f     }
    };

    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 18;
        
        op->flg |= 0x4100000;
        
        op->tv[0].x = -1.0f;
        op->tv[0].y = -2.0f;
        op->tv[0].z = 0;
        
        op->tv[1].x = 1.0f;
        op->tv[1].y = -2.0f;
        op->tv[1].z = 0;
        
        op->tv[2].x = -1.0f;
        op->tv[2].y = 0;
        op->tv[2].z = 0;
        
        op->tv[3].x = 1.0f;
        op->tv[3].y = 0;
        op->tv[3].z = 0;
        
        op->tv[0].col = 0xFFE0E0E0;
        op->tv[1].col = 0xFFE0E0E0;
        op->tv[2].col = 0xFFE0E0E0;
        op->tv[3].col = 0xFFE0E0E0;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ani_ct = 0;
        op->ct0    = 0;
        
        switch (op->type) 
        {                         
        case 0:                                     
            op->exp0 = (unsigned char*)uvinfo_fl;
            break;
        case 1:                                     
            op->tex_id = 3;
            
            op->ani_ct = 3;
            
            op->exp0 = (unsigned char*)uvinfo_fst;
            break;
        case 2:                                     
            op->exp0 = (unsigned char*)uvinfo_fl2s;
            break;
        case 3:                                     
            op->exp0 = (unsigned char*)uvinfo_fs;
            break;
        case 4:                                     
            op->exp0 = (unsigned char*)uvinfo_fed;
            break;
        case 10:                                    
        case 11:                                    
            op->ani_ct = 0;
            
            if (op->mdlver != 0) 
            {
                op->exp0 = (unsigned char*)uvinfo_fl;
            }
            else 
            { 
                op->exp0 = (unsigned char*)uvinfo_fs;
            }
            
            op->ct0 = op->flr_no;
            
            if (op->type == 10) 
            {
                op->ct1 = (int)(30.0f * (-rand() / -2.1474836E9f)) + 10;
            } 
            else 
            {
                op->ct1 = 0;
            }
            
            pos.x = op->px;
            pos.y = 2.0f + op->py;
            pos.z = op->pz;
            
            op->gpy = bhGetGroundPosition(&pos);
            op->yn  = 0;
            
            op->loy = 0.01f + (0.1f * (-rand() / -2.1474836E9f));
            break;
        }
        
        op->mode0 = 1;
        break;
    }
    
    if (op->mode1 != 0) 
    {
        switch ((unsigned short)op->mode1) 
        {                  
        case 1:                                    
            op->type = 2;
            
            op->exp0 = (unsigned char*)uvinfo_fl2s;
            op->ct0  = 0;
            break;
        case 2:                                    
            op->type = 4;
            
            op->exp0 = (unsigned char*)uvinfo_fed;
            op->ct0  = 0;
            break;
        }
        
        op->mode1 = 0;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f)
    {
        switch (op->type) 
        {                       
        case 1:                                     
            op->tex_id = 18;
            
            op->ani_ct = 0;
            
            op->exp0 = (unsigned char*)uvinfo_fl;
            
            op->type = 1;
            break;
        case 2:                                     
            op->exp0 = (unsigned char*)uvinfo_fs;
            
            op->type = 3;
            break;
        case 4:                                     
            op->flg = 0;
            return;
        }
        
        op->ct0 = 0;
        
        uvp = (UV_WORK*)op->exp0 + op->ct0;
    } 
    
    if (op->type >= 10) 
    {
        if (op->ct1 <= 0) 
        {
            if ((op->ct0 == 0) && (op->sxb > 0.5f))
            {
                sys->ef.id = 19;
                
                sys->ef.flg = 0x4100001;
                
                sys->ef.type = 3;
                
                sys->ef.mdlver = 0;
                
                sys->ef.sx = op->sxb;
                sys->ef.sy = op->syb;
                sys->ef.sz = op->szb;
                
                sys->ef.px = op->px;
                sys->ef.py = op->py;
                sys->ef.pz = op->pz;
                
                sys->ef.ax = sys->ef.ay = 0;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            }
            
            if (op->type == 11)
            {
                op->sxb *= 0.5f;
                op->syb *= 0.5f;
            }
            else if (op->py > op->gpy) 
            {
                op->sxb *= 0.9f;
                op->syb *= 0.9f;
            }
            else 
            {
                op->sxb *= 0.95f;
                op->syb *= 0.95f;
            }
            
            if (op->sxb < 0.2f)
            {
                op->flg = 0;
                return;
            }
        }
        else 
        {
            op->ct1--;
        }
        
        op->px += op->lox;
        op->pz += op->loz;
        
        if (op->py > op->gpy) 
        {
            op->py += op->yn;
            
            if (op->yn > -1.0f) 
            {
                op->yn -= op->loy;
            }
            
            op->lox *= 0.95f;
            op->loz *= 0.95f;
            
            op->ct1 = 0;
        } 
        else 
        {
            op->py = op->gpy;
            
            op->lox *= 0.9f;
            op->loz *= 0.9f;
        }
    }
    
    op->sx = 4.0f * (op->sxb * uvp->xs);
    op->sy = 4.0f * (op->syb * uvp->ys);
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff019(O_WRK* op) 
{
    UV_WORK* uvp;
    LGT_WORK* lp;
	static UV_WORK uvinfo_t0[15] = 
    {
        { 0.015625f, 0.0f,      0.15625f, 0.125f    },
        { 0.015625f, 0.125f,    0.15625f, 0.15625f  },
        { 0.015625f, 0.3125f,   0.15625f, 0.15625f  },
        { 0.0f,      0.484375f, 0.1875f,  0.15625f  },
        { 0.625f,    0.484375f, 0.1875f,  0.15625f  },
        { 0.375f,    0.0f,      0.21875f, 0.1875f   },
        { 0.375f,    0.1875f,   0.21875f, 0.1875f   },
        { 0.375f,    0.40625f,  0.21875f, 0.1875f   },
        { 0.625f,    0.265625f, 0.21875f, 0.1875f   },
        { 0.640625f, 0.015625f, 0.1875f,  0.1875f   },
        { 0.1875f,   0.0f,      0.1875f,  0.1875f   },
        { 0.1875f,   0.1875f,   0.1875f,  0.15625f  },
        { 0.1875f,   0.34375f,  0.1875f,  0.1875f   },
        { 0.1875f,   0.5f,      0.1875f,  0.140625f },
        { -1.0f,     0.0f,      0.0f,     0.0f      }
    };
    static UV_WORK uvinfo_t1[15] = 
    {
        { 0.015625f, 0.0f,      0.15625f, 0.125f   },
        { 0.015625f, 0.125f,    0.15625f, 0.15625f },
        { 0.015625f, 0.3125f,   0.15625f, 0.15625f },
        { 0.0f,      0.484375f, 0.1875f,  0.15625f },
        { 0.625f,    0.484375f, 0.1875f,  0.15625f },
        { 0.375f,    0.0f,      0.21875f, 0.1875f  },
        { 0.375f,    0.1875f,   0.21875f, 0.1875f  },
        { 0.375f,    0.40625f,  0.21875f, 0.1875f  },
        { 0.625f,    0.265625f, 0.21875f, 0.1875f  },
        { 0.0f,      0.640625f, 0.21875f, 0.21875f },
        { 0.21875f,  0.640625f, 0.21875f, 0.21875f },
        { 0.4375f,   0.640625f, 0.1875f,  0.15625f },
        { 0.625f,    0.65625f,  0.1875f,  0.15625f },
        { 0.8125f,   0.65625f,  0.1875f,  0.15625f },
        { -1.0f,     0.0f,      0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_t2[8] = 
    {
        { 0.3125f,  0.875f, 0.09375f, 0.09375f },
        { 0.40625f, 0.875f, 0.09375f, 0.09375f },
        { 0.5f,     0.875f, 0.09375f, 0.09375f },
        { 0.59375f, 0.875f, 0.09375f, 0.09375f },
        { 0.6875f,  0.875f, 0.09375f, 0.09375f },
        { 0.78125f, 0.875f, 0.09375f, 0.09375f },
        { 0.875f,   0.875f, 0.09375f, 0.09375f },
        { -1.0f,    0.0f,   0.0f,     0.0f     }
    };

    switch (op->mode0) 
    {
    case 0:
        op->flg = 0x4100001;
        
        op->tex_id = 19;
        
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        op->ani_ct = 0;
        
        switch (op->type) 
        {                          
        case 0:                                     
            op->bl_src = 8;
            op->bl_dst = 10;
            
            op->exp0 = (unsigned char*)uvinfo_t0;
            
            op->yn = 1.0f;
            
            lp = rom->lgtp;
            
            if (!(lp->flg & 0x2)) 
            {
                lp->flg = 3; 
                
                lp->type = 101;
                
                lp->aspd = 8;
                
                lp->lkflg = 0;
                lp->lkno  = 0;
                lp->lkono = 0;
                
                lp->mode = 0;
                
                lp->lsrc = 4;
                
                lp->r = 3.0f;
                lp->g = 2.0f;
                lp->b = 1.0f;
                
                lp->nr = 20.0f;
                lp->fr = 60.0f;
                
                lp->px = op->px;
                lp->py = op->py;
                lp->pz = op->pz;
                
                lp->lx = 0;
                lp->ly = 0;
                lp->lz = 0;
                
                lp->ct0 = 0;
                
                lp->light = NULL;
            }
            
            break;
        case 1:                                     
            op->tv[0].col = 0x30FFFFFF;
            op->tv[1].col = 0x30FFFFFF;
            op->tv[2].col = 0x30FFFFFF;
            op->tv[3].col = 0x30FFFFFF;
            
            op->bl_src = 11;
            op->bl_dst = 3;
            
            op->exp0 = (unsigned char*)uvinfo_t1;
            
            op->yn = 1.4f;
            
            op->ct1 = 48;
            break;
        case 2:                                     
            op->tv[0].col = 0x40FFFFFF;
            op->tv[1].col = 0x40FFFFFF;
            op->tv[2].col = 0x40FFFFFF;
            op->tv[3].col = 0x40FFFFFF;
            
            op->bl_src = 8;
            op->bl_dst = 6;
            
            uvp = uvinfo_t2;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        case 3:                                     
            op->tv[0].col = 0x60FFFFFF;
            op->tv[1].col = 0x60FFFFFF;
            op->tv[2].col = 0x60FFFFFF;
            op->tv[3].col = 0x60FFFFFF;
            
            op->bl_src = 11;
            
            uvp = uvinfo_t1;
            
            op->bl_dst = 3;
            
            op->exp0 = (unsigned char*)uvp;
            break;
        }
        
        op->ct0   = 0;
        op->mode0 = 1;
        break;
    }
    
    switch (op->type)
    {                            
    case 0:                                         
        op->py += op->yn;
        op->yn *= 0.9f;
        break;
    case 1:                                         
        op->ct1 += 24;
        
        if (op->ct1 > 0xFF) 
        {
            op->ct1 = 0xFF;
        }
        
        op->tv[0].col = (op->ct1 << 24) | 0xFFFFFF;
        op->tv[1].col = (op->ct1 << 24) | 0xFFFFFF;
        op->tv[2].col = (op->ct1 << 24) | 0xFFFFFF;
        op->tv[3].col = (op->ct1 << 24) | 0xFFFFFF;
        
        op->py += op->yn;
        op->yn *= 0.9f;
        break;
    case 2:                                         
        op->sxb += 0.5f;
        op->syb += 0.5f;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f)
    {
        op->flg = 0;
        return;
    }
    
    op->sx = 8.0f * (op->sxb * uvp->xs);
    op->sy = 8.0f * (op->syb * uvp->ys);
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhDraw021()
{
	NJS_POINT2COL p2c;     
    NJS_POINT2 p[4];    
    NJS_COLOR col[4];  

    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    p2c.p = p;
    p2c.col = col;
    p2c.tex = NULL;
    p2c.num = 1;
    
    p2c.col[0].color = 0xFF000000;
    p2c.col[1].color = 0xFF000000;
    p2c.col[2].color = 0xFF000000;
    p2c.col[3].color = 0xFF000000;
    
    p[0].x = 0;
    p[0].y = -40.0f;
    
    p[1].x = 640.0f;
    p[1].y = -40.0f;
    
    p[2].x = 640.0f;
    p[2].y = 40.0f;
    
    p[3].x = 0;
    p[3].y = 40.0f;
    
    njDrawPolygon2D(&p2c, 4, -0.9f, 96);
    
    p2c.col[0].color = 0xFF000000;
    p2c.col[1].color = 0xFF000000;
    p2c.col[2].color = 0;
    p2c.col[3].color = 0;
    
    p[0].y = 40.0f;
    p[1].y = 40.0f;
    p[2].y = 104.0f;
    p[3].y = 104.0f;
    
    njDrawPolygon2D(&p2c, 4, -0.9f, 96);
    
    p2c.col[0].color = 0xFF000000;
    p2c.col[1].color = 0xFF000000;
    p2c.col[2].color = 0xFF000000;
    p2c.col[3].color = 0xFF000000;
    
    p[0].y = 440.0f;
    p[1].y = 440.0f;
    p[2].y = 520.0f;
    p[3].y = 520.0f;
    
    njDrawPolygon2D(&p2c, 4, -0.9f, 96);
    
    p2c.col[0].color = 0;
    p2c.col[1].color = 0;
    p2c.col[2].color = 0xFF000000;
    p2c.col[3].color = 0xFF000000;
    
    p[0].y = 376.0f;
    p[1].y = 376.0f;
    p[2].y = 440.0f;
    p[3].y = 440.0f;
    
    njDrawPolygon2D(&p2c, 4, -0.9f, 96);
}

// 100% matching!
void bhEff021(O_WRK* op)
{
    if (op->mode1 != 0) 
    {
        sys->cb_flg |= 0x40;
        
        op->func = bhDraw021;
        
        sys->ef_fnc[sys->ef_fncn++] = op;
    }
    else 
    {
        sys->cb_flg &= ~0x40;
        
        op->flg |= 0x1000000;
    }
}

// 99.18% matching (matches on NGC)
void bhDraw022(O_WRK* op)
{
    UV_WORK* uvp;
    EXP_DRAW022_WORK* exp;
    NJS_VECTOR scl;
    int i;
	static UV_WORK uvinfo[15] = 
    {
        { 0.0625f,  0.875f,   0.03125f, 0.03125f },
        { 0.09375f, 0.875f,   0.03125f, 0.03125f },
        { 0.0625f,  0.90625f, 0.0625f,  0.0625f  },
        { 0.0f,     0.875f,   0.0625f,  0.0625f  },
        { 0.0f,     0.9375f,  0.0625f,  0.0625f  },
        { 0.125f,   0.875f,   0.09375f, 0.09375f },
        { 0.21875f, 0.875f,   0.09375f, 0.09375f },
        { 0.3125f,  0.875f,   0.09375f, 0.09375f },
        { 0.40625f, 0.875f,   0.09375f, 0.09375f },
        { 0.5f,     0.875f,   0.09375f, 0.09375f },
        { 0.59375f, 0.875f,   0.09375f, 0.09375f },
        { 0.6875f,  0.875f,   0.09375f, 0.09375f },
        { 0.78125f, 0.875f,   0.09375f, 0.09375f },
        { 0.875f,   0.875f,   0.09375f, 0.09375f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static NJS_TEXTURE_VTX tv[4] = 
    {
        { -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0xC0FFFFFF },
        {  1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0xC0FFFFFF },
        { -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0xC0FFFFFF },
        {  1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0xC0FFFFFF }
    };
    
    njPushMatrixEx();
    
    if ((sys->sp_flg & 0x8)) 
    {
        if ((op->ct0 - 1) < 16)
        {
            exp = (EXP_DRAW022_WORK*)&op->exp0[4];
            exp += op->ct0 - 1;
            
            exp->flg = 1;
            
            exp->ct = 0;
            
            exp->px = op->px;
            exp->py = op->py;
            exp->pz = op->pz;
        }
    }
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[9] + op->flr_no);
    
    njControl3D(0);
    
    njTextureFilterMode(1);
    
    njColorBlendingMode(0,  8);
    njColorBlendingMode(1, 10);
    
    exp = (EXP_DRAW022_WORK*)&op->exp0[4];
    
    scl.z = 0;
    
    for (i = 0; i < 77; i++, exp++) 
    {
        if (exp->flg != 0) 
        {
            uvp = &uvinfo[exp->ct];
            
            scl.x = 8.0f * (op->sxb * uvp->xs);
            scl.y = 8.0f * (op->syb * uvp->ys);
            
            tv[0].u = uvp->u;
            tv[0].v = uvp->v;
            
            tv[1].u = uvp->u + uvp->xs;
            tv[1].v = uvp->v;
            
            tv[2].u = uvp->u;
            tv[2].v = uvp->v + uvp->ys;
            
            tv[3].u = uvp->u + uvp->xs;
            tv[3].v = uvp->v + uvp->ys;
            
            njSetMatrix(NULL, cam.mtx);
            
            njTranslateEx((NJS_VECTOR*)&exp->px);
            njUnitRotPortion(NULL);
            njScaleEx(&scl);
            
            njDrawTexture3DEx(tv, 4, 1);
            
            if ((sys->sp_flg & 0x8))
            {
                exp->ct++;
                
                if (exp->ct > 13) 
                {
                    exp->flg = 0;
                }
            }
        }
    } 
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();
}

// 99.95% matching
void bhEff022(O_WRK* op)
{
    NJS_VECTOR vc;
    NJS_POINT3 ps;
    int i;
    
    op->flg |= 0x1000000;
    
    if (op->mode0 == 0) 
    {
        if ((op->exp0 = (unsigned char*)bhSetExtraEffectWork()) == NULL) 
        {
            op->flg = 0;
            return;
        }
        
        op->func = (void*)bhDraw022;
        
        op->mode0 = 1;
        return;
    }
    
    op->px += op->lox;
    op->py += op->loy;
    op->pz += op->loz;
    
    op->loy += op->yn;
    
    op->yn -= 0.01f;
    
    op->ct0++;
    
    if (op->ct0 > 30)
    {
        op->flg = 0;
        
        *(int*)op->exp0 = 0;
        return;
    }
    
    if (op->ct0 < 16) 
    {
        sys->ef.id = 132;
        
        sys->ef.flg  = 0x4100001;
        sys->ef.type = 1;
        
        sys->ef.mdlver = 0;
        
        sys->ef.px = op->px;
        sys->ef.py = op->py;
        sys->ef.pz = op->pz;
        
        sys->ef.sx = 1.0f;
        sys->ef.sy = 1.0f;
        sys->ef.sz = 0.0f;
        
        vc.x = 0;
        vc.y = vc.z = 0.5f;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, op->ay);
        njRotateX(NULL, op->ax);
        
        for (i = 0; i <= 0; i++) // non-sensical loop - dev mistake 
        {
            njPushMatrixEx();
            
            njRotateZ(NULL, (int)(182.04445f * (360.0f * (-rand() / -2.1474836E9f))) & 0xFFFF);
            
            njCalcPoint(NULL, &vc, &ps);
            
            bhSetEffectTb(&sys->ef, &ps, NULL, 0);
            
            njPopMatrixEx();
        }
    }
    
    sys->ef_fnc[sys->ef_fncn++] = op;
}

// 99.93% matching
void bhEff023(O_WRK* op) 
{
    UV_WORK* uvp;   
    NJS_VECTOR vc0, vc1; 
    float scl, sch;     
	static UV_WORK uvinfo_t0[16] = 
    {
        { 0,        0,        0.21875f, 0.21875f },
        { 0.21875f, 0,        0.21875f, 0.21875f },
        { 0.4375f,  0,        0.21875f, 0.21875f },
        { 0.65625f, 0,        0.21875f, 0.21875f },
        { 0,        0.21875f, 0.21875f, 0.21875f },
        { 0.21875f, 0.21875f, 0.21875f, 0.21875f },
        { 0.4375f,  0.21875f, 0.21875f, 0.21875f },
        { 0.65625f, 0.21875f, 0.21875f, 0.21875f },
        { 0,        0.4375f,  0.21875f, 0.21875f },
        { 0.21875f, 0.4375f,  0.21875f, 0.21875f },
        { 0.4375f,  0.4375f,  0.21875f, 0.21875f },
        { 0.65625f, 0.4375f,  0.21875f, 0.21875f },
        { 0,        0.65625f, 0.21875f, 0.21875f },
        { 0.21875f, 0.65625f, 0.21875f, 0.21875f },
        { 0.4375f,  0.65625f, 0.21875f, 0.21875f },
        { -1.0f,    0,        0,        0        }
    };
    
    switch (op->mode0)
    {
    case 0:
        op->flg = 0x100001;
        
        op->ani_ct = op->flr_no;
        
        if (op->mdlver == 0) 
        {
            op->tex_id = 9;
            
            op->tv[0].col = -1;
            op->tv[1].col = -1;
            op->tv[2].col = -1;
            op->tv[3].col = -1;
            
            op->bl_src = 8;
            op->bl_dst = 6;
        } 
        else
        {
            if (op->ani_ct == 0) 
            {
                op->tex_id = 10;
            }
            else 
            {
                op->tex_id = 9;
            }
            
            op->tv[0].col = -1;
            op->tv[1].col = -1;
            op->tv[2].col = -1;
            op->tv[3].col = -1;
            
            op->bl_src = 8;
            op->bl_dst = 10;
        }
        
        op->exp0 = (unsigned char*)uvinfo_t0;
        
        op->ct0 = 0;
        
        op->spd = 1.2f;
        
        op->mode0 = 1;
    }
    
    if ((op->type != 0) && ((((unsigned int)op->type == 1) && ((op->ct0 > 0) && (!(op->ct0 & 3)))) || (((unsigned int)op->type == 2) && ((op->ct0 > 0) && (!(op->ct0 % 6))))))
    {
        scl = op->sxb;
        sch = 0.5f * scl;
        
        sys->ef.id = 23;
        
        sys->ef.flg = 1;
        
        sys->ef.type = 0;
        
        sys->ef.mdlver = op->mdlver;
        
        sys->ef.flr_no = op->flr_no;
        
        sys->ef.sx = op->sxb * op->spd;
        sys->ef.sy = op->syb * op->spd;
        sys->ef.sz = op->szb * op->spd;
        
        sys->ef.px = op->px + ((scl * (-rand() / -2.1474836E9f)) - sch);
        sys->ef.py = op->py + ((scl * (-rand() / -2.1474836E9f)) - sch);
        sys->ef.pz = op->pz + ((scl * (-rand() / -2.1474836E9f)) - sch);
        
        sys->ef.ax = sys->ef.ay = 0;
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        vc0.x = vc0.y = 0;
        vc0.z = -(scl / 3.0f);
        
        sys->ef.id = 24;
        
        sys->ef.flg = 1;
        
        sys->ef.type = 0;
        
        sys->ef.mdlver = 1;
        
        sys->ef.flr_no = 0;
        
        sys->ef.sx = 1.0f + (-rand() / -2.1474836E9f);
        sys->ef.sy = sys->ef.sx;
        sys->ef.sz = 0;
        
        sys->ef.ay = 182.04445f * (360.0f * (-rand() / -2.1474836E9f));
        sys->ef.ax = 182.04445f * (80.0f  * (-rand() / -2.1474836E9f));
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, sys->ef.ax, sys->ef.ay, 0);
        njCalcVector(NULL, &vc0, &vc1);
        
        bhSetEffectTb(&sys->ef, &vc1, NULL, 0);
        
        op->spd += 0.2f;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
        
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
        return;
    }
    
    op->sx = 8.0f * (op->sxb * uvp->xs);
    op->sy = 8.0f * (op->syb * uvp->ys);
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    if (op->mdlver == 0) 
    {
        sys->ef_pnc[sys->ef_pncn++] = op;
    }
    else 
    {
        sys->ef_trs[sys->ef_trsn++] = op;
    }
}

// 100% matching!
void bhDraw024(O_WRK* op) 
{
    NJS_TEXTURE_VTX* tv;   
    UV_WORK* uvp;          
    EXP_DRAW022_WORK* exp; 
    NJS_POINT3 scl;        
    int i;                 
	static UV_WORK uvinfo0[8] = 
    {
        { 0.0625f,  0.875f,   0.03125f, 0.03125f },
        { 0.0625f,  0.90625f, 0.0625f,  0.0625f  },
        { 0.0f,     0.9375f,  0.0625f,  0.0625f  },
        { 0.21875f, 0.875f,   0.09375f, 0.09375f },
        { 0.40625f, 0.875f,   0.09375f, 0.09375f },
        { 0.59375f, 0.875f,   0.09375f, 0.09375f },
        { 0.78125f, 0.875f,   0.09375f, 0.09375f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo1[11] = 
    {
        { 0.015625f, 0.0f,      0.15625f, 0.125f   },
        { 0.015625f, 0.125f,    0.15625f, 0.15625f },
        { 0.015625f, 0.3125f,   0.15625f, 0.15625f },
        { 0.0f,      0.484375f, 0.1875f,  0.15625f },
        { 0.625f,    0.484375f, 0.1875f,  0.15625f },
        { 0.375f,    0.0f,      0.21875f, 0.1875f  },
        { 0.375f,    0.40625f,  0.21875f, 0.1875f  },
        { 0.0f,      0.640625f, 0.21875f, 0.21875f },
        { 0.4375f,   0.640625f, 0.1875f,  0.15625f },
        { 0.8125f,   0.65625f,  0.1875f,  0.15625f },
        { -1.0f,     0.0f,      0.0f,     0.0f     }
    };
    static NJS_TEXTURE_VTX tv0[4] = 
    {
        { -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF },
        {  1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF },
        { -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF },
        {  1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF }
    };
    static NJS_TEXTURE_VTX tv1[4] = 
    {
        { -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0x40FFFFFF },
        {  1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0x40FFFFFF },
        { -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0x40FFFFFF },
        {  1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0x40FFFFFF }
    };
    static int ef24ct[2] = 
    {
        6, 14
    };
    
    njPushMatrixEx();
    
    if ((op->ct0 - 1) < 32) 
    {
        exp = (EXP_DRAW022_WORK*)&op->exp0[4];
        exp += op->ct0 - 1;
        
        exp->flg = 1;
        
        exp->ct = 0;
        
        exp->px = op->px;
        exp->py = op->py;
        exp->pz = op->pz;
        
        exp = (EXP_DRAW022_WORK*)&op->exp0[4];
        exp += op->ct0 + 31;
        
        exp->flg = 2;
        
        exp->ct = 0;
        
        exp->px = op->px + cam.vx;
        exp->py = op->py + cam.vy;
        exp->pz = op->pz + cam.vz;
    }
    
    njSetTexture(&sys->ef_tlist);
    
    njControl3D(0);
    
    njTextureFilterMode(1);
    njSetTextureNum(sys->ef_tn[19]);
    
    exp = (EXP_DRAW022_WORK*)&op->exp0[4];
    
    scl.z = 0;
    
    for (i = 0; i < 64; i++, exp++) 
    {
        if (exp->flg != 0) 
        {
            if ((unsigned short)exp->flg == 1)
            {
                njColorBlendingMode(0, 8);
                njColorBlendingMode(1, 10);
                
                tv = tv0;
                
                uvp = &uvinfo0[exp->ct];
            } 
            else if (exp->ct < 5) 
            {
                if ((sys->sp_flg & 0x8)) 
                {
                    exp->ct++;
                }
                
                continue;
            } 
            else 
            {
                njColorBlendingMode(0, 11);
                njColorBlendingMode(1, 3);
                
                tv = tv1;
                
                uvp = &uvinfo1[exp->ct - 5];
            }

            scl.x = 8.0f * (op->sxb * uvp->xs);
            scl.y = 8.0f * (op->syb * uvp->ys);
            
            tv[0].u = uvp->u;
            tv[0].v = uvp->v;
            
            tv[1].u = uvp->u + uvp->xs;
            tv[1].v = uvp->v;
            
            tv[2].u = uvp->u;
            tv[2].v = uvp->v + uvp->ys;
            
            tv[3].u = uvp->u + uvp->xs;
            tv[3].v = uvp->v + uvp->ys;
            
            njSetMatrix(NULL, cam.mtx);
            
            njTranslateEx((NJS_VECTOR*)&exp->px);
            njUnitRotPortion(NULL);
            njScaleEx(&scl);
            
            njDrawTexture3DEx(tv, 4, 1);
            
            if ((sys->sp_flg & 0x8)) 
            {
                exp->ct++;
                
                if (exp->ct > ef24ct[exp->flg - 1]) 
                {
                    exp->flg = 0;
                }
            }
            
            njColorBlendingMode(0, 8);
            njColorBlendingMode(1, 6);
        }
    }
        
    njPopMatrixEx();
}

// 99.94% matching
void bhEff024(O_WRK* op) 
{
    ATR_WORK* hp;
    NJS_VECTOR vec;
    float py;
    
    op->flg |= 0x1000000;
    
    if (op->mode0 == 0) 
    {
        if ((op->exp0 = (unsigned char*)bhSetExtraEffectWork()) == NULL) 
        {
            op->flg = 0;
            return;
        }
        
        op->func = (void*)bhDraw024;
        
        op->mode0 = 1;
        return;
    }
    
    op->px += op->lox;
    op->py += op->loy;
    op->pz += op->loz;
    
    op->loy += op->yn;
    
    op->yn -= 0.01f;
    
    op->ct0++;
    
    if ((!(sys->cb_flg & 0x40000000)) && ((hp = bhCheckWallType((NJS_POINT3*)&op->px, 0x400, 0.1f, 0.1f)) != NULL)) 
    {
        py = op->py;
        
        bhSetWallRefAngle(hp, (NJS_POINT3*)&op->px, 0.1f, 0.1f, &op->ayp);
        
        if ((op->py != py) && (op->yn < 0))
        {
            op->yn = -op->yn;
        } 
        else 
        {
            vec.x = op->lox;
            vec.y = 0;
            
            vec.z = op->loz;
            vec.z = -njScalor(&vec);

            vec.x = vec.y = 0;
            
            op->ay = op->ayp;
            
            njUnitMatrix(NULL);
            
            njRotateXYZ(NULL, 0, op->ay, 0);
            njCalcVector(NULL, &vec, &vec);
            
            op->lox = vec.x;
            op->loz = vec.z;
        }
        
        op->lox *= 0.9f;
        op->loz *= 0.9f;
    }
    
    if (op->ct0 > 47)
    {
        op->flg = 0;
        
        *(int*)op->exp0 = 0;
        return;
    }
    
    if (op->ct0 < 16) 
    {
        sys->ef.id = 25;
        
        sys->ef.flg  = 1;
        sys->ef.type = 0;
        
        sys->ef.mdlver = 0;
        
        sys->ef.flr_no = 0;
        
        sys->ef.px = op->px;
        sys->ef.py = op->py;
        sys->ef.pz = op->pz;
        
        sys->ef.sx = 1.0f;
        sys->ef.sy = 1.0f;
        sys->ef.sz = 0;
        
        sys->ef.ax = sys->ef.ay = 0;
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
    
    sys->ef_fnc[sys->ef_fncn++] = op;
}

// 100% matching!
void bhDraw025(O_WRK* op) 
{
    UV_WORK* uvp;
    EXP_EFF025_WORK* exp;
    NJS_POINT3 scl;
    int i;
	static UV_WORK uvinfo[11] = 
    {
        { 0.0f,    0.0f,     0.1875f, 0.25f    },
        { 0.1875f, 0.0f,     0.1875f, 0.25f    },
        { 0.375f,  0.0f,     0.1875f, 0.25f    },
        { 0.5625f, 0.0f,     0.1875f, 0.25f    },
        { 0.75f,   0.0f,     0.1875f, 0.25f    },
        { 0.0f,    0.25f,    0.1875f, 0.21875f },
        { 0.1875f, 0.25f,    0.1875f, 0.21875f },
        { 0.375f,  0.25f,    0.1875f, 0.21875f },
        { 0.5625f, 0.25f,    0.1875f, 0.21875f },
        { 0.0f,    0.46875f, 0.1875f, 0.21875f },
        { -1.0f,   0.0f,     0.0f,    0.0f     }
    };
    static NJS_TEXTURE_VTX tv[4] = 
    {
        { -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF },
        {  1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF },
        { -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF },
        {  1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF }
    };

    njPushMatrixEx();
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[18]);
    
    njControl3D(0);
    
    njTextureFilterMode(0);
    
    njColorBlendingMode(0,  8);
    njColorBlendingMode(1, 10);
    
    exp = (EXP_EFF025_WORK*)&op->exp0[4];
    
    for (i = 0; i < 8; i++, exp++) 
    {
        if (exp->flg != 0) 
        {
            uvp = &uvinfo[exp->ct];
            
            scl.x = scl.y = scl.z = exp->scl;
            
            tv[0].u = uvp->u;
            tv[0].v = uvp->v;
            
            tv[1].u = uvp->u + uvp->xs;
            tv[1].v = uvp->v;
            
            tv[2].u = uvp->u;
            tv[2].v = uvp->v + uvp->ys;
            
            tv[3].u = uvp->u + uvp->xs;
            tv[3].v = uvp->v + uvp->ys;
            
            njSetMatrix(NULL, cam.mtx);
            
            njTranslateEx((NJS_VECTOR*)&exp->px);
            njUnitRotPortion(NULL);
            njScaleEx((NJS_VECTOR*)&scl);
            
            njDrawTexture3DEx(tv, 4, 1);
            
            if ((sys->sp_flg & 0x8)) 
            {
                exp->scl *= 0.8f;
                
                exp->px += exp->xn;
                exp->py += exp->yn;
                exp->pz += exp->zn;
                
                exp->xn *= 0.8f;
                exp->zn *= 0.8f;
                exp->yn *= 0.8f;
                
                exp->ct++;
                
                if (exp->ct > 9) 
                {
                    exp->ct = 0;
                }
            }
        }
    } 
        
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();
}

// 100% matching!
void bhEff025(O_WRK* op) 
{
    EXP_EFF025_WORK* exp;
    int i;
    
    op->flg |= 0x1000000;
    
    if (op->mode0 == 0) 
    {
        if ((op->exp0 = (unsigned char*)bhSetExtraEffectWork()) == NULL) 
        {
            op->flg = 0;
            return;
        }
        
        exp = (EXP_EFF025_WORK*)&op->exp0[4];
        
        for (i = 0; i < 8; i++, exp++)
        {
            exp->flg = 1;
            
            exp->ct = 0;
            
            exp->scl = 1.0f;
            
            exp->px = op->px + ((2.0f * (-rand() / -2.1474836E9f)) - 1.0f);
            exp->py = op->py + ((2.0f * (-rand() / -2.1474836E9f)) - 1.0f);
            exp->pz = op->pz + ((2.0f * (-rand() / -2.1474836E9f)) - 1.0f);
            
            exp->xn = (-rand() / -2.1474836E9f) - 0.5f;
            exp->yn = (-rand() / -2.1474836E9f) - 0.5f;
            exp->zn = (-rand() / -2.1474836E9f) - 0.5f;
            
            njUnitVector((NJS_VECTOR*)&exp->xn);
        } 
        
        op->func = (void*)bhDraw025;
        
        op->mode0 = 1;
        return;
    }
    
    op->ct0++;
    
    if (op->ct0 >= 6) 
    {
        if (op->ct0 > 14) 
        {
            op->flg = 0;
            
            *(int*)op->exp0 = 0;
            return;
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
    }
}

// 99.92% matching
void bhEff026(O_WRK* op)
{
    unsigned int argb;
    POINT pnt;
    
    if (op->mode0 == 0) 
    {
        op->tex_id = 2;
        
        op->ani_ct = 0;
        
        op->gidx = bhGetGidx(op);
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->tv[0].u = 0.75f;
        op->tv[0].v = 0;
        
        op->tv[1].u = 0.875f;
        op->tv[1].v = 0;
        
        op->tv[2].u = 0.75f;
        op->tv[2].v = 0.125f;
        
        op->tv[3].u = 0.875f;
        op->tv[3].v = 0.125f;
        
        op->px = 160.0f + (320.0f * (-rand() / -2.1474836E9f));
        op->py = 120.0f + (240.0f * (-rand() / -2.1474836E9f));
        
        op->sx = 1024.0f;
        op->sy = 1.0f;
        op->sz = 1.0f + (0.1f * (-rand() / -2.1474836E9f));
        
        op->spd = (2.0f * (-rand() / -2.1474836E9f)) - 1.0f;
        
        op->mode0 = 1;
    }
    
    op->ct1++;
    
    if (op->ct1 == 16)
    {
        bhSetEffect(26, &pnt, NULL, 0);
    }
    
    op->az += (int)(182.04445f * op->spd) & 0xFFFF;
    
    op->ct0 = (op->ct0 + 1024) & 0x7FFF;
    
    if (op->ct0 == 0) 
    {
        op->flg = 0;
        return;
    }
    
    argb = ((int)(128.0f * njSin(op->ct0)) << 24) | 0xC8B440;
    
    op->tv[0].col = argb;
    op->tv[1].col = argb;
    op->tv[2].col = argb;
    op->tv[3].col = argb;
    
    op->tv[0].x = op->px + (op->sx * njSin(op->az - 8192));
    op->tv[0].y = op->py + (op->sx * njCos(op->az - 8192));
    op->tv[0].z = 1.0f / op->sz;
    
    op->tv[1].x = op->px + (op->sx * njSin(op->az + 8192));
    op->tv[1].y = op->py + (op->sx * njCos((8192.0f + op->sz)));
    op->tv[1].z = 1.0f / op->sz;
    
    op->tv[2].x = op->px + (op->sx * njSin(op->az - 24576));
    op->tv[2].y = op->py + (op->sx * njCos(op->az - 24576));
    op->tv[2].z = 1.0f / op->sz;
    
    op->tv[3].x = op->px + (op->sx * njSin(op->az + 24576));
    op->tv[3].y = op->py + (op->sx * njCos((24576.0f + op->sz)));
    op->tv[3].z = 1.0f / op->sz;
    
    sys->ef_trs2d[sys->ef_trs2dn++] = op;
}

// 100% matching!
void bhDraw027(O_WRK* op)
{
    UV_WORK* uvp;
    EXP_EFF025_WORK* exp;
    NJS_POINT3 scl;
    int i;
	static UV_WORK uvinfo[11] = 
    {
        { 0.0f,    0.0f,     0.1875f, 0.25f    },
        { 0.1875f, 0.0f,     0.1875f, 0.25f    },
        { 0.375f,  0.0f,     0.1875f, 0.25f    },
        { 0.5625f, 0.0f,     0.1875f, 0.25f    },
        { 0.75f,   0.0f,     0.1875f, 0.25f    },
        { 0.0f,    0.25f,    0.1875f, 0.21875f },
        { 0.1875f, 0.25f,    0.1875f, 0.21875f },
        { 0.375f,  0.25f,    0.1875f, 0.21875f },
        { 0.5625f, 0.25f,    0.1875f, 0.21875f },
        { 0.0f,    0.46875f, 0.1875f, 0.21875f },
        { -1.0f,   0.0f,     0.0f,    0.0f     }
    };
    static NJS_TEXTURE_VTX tv[4] = 
    {
        { -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF },
        {  1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF },
        { -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF },
        {  1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0xE0FFFFFF }
    };

    njPushMatrixEx();
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[18]);
    
    njControl3D(0);
    
    njTextureFilterMode(0);
    
    njColorBlendingMode(0,  8);
    njColorBlendingMode(1, 10);
    
    exp = (EXP_EFF025_WORK*)&op->exp0[4];
    
    for (i = 0; i < 16; i++, exp++) 
    {
        if (exp->flg != 0) 
        {
            uvp = &uvinfo[exp->ct];
            
            scl.x = scl.y = scl.z = exp->scl;
            
            tv[0].u = uvp->u;
            tv[0].v = uvp->v;
            
            tv[1].u = uvp->u + uvp->xs;
            tv[1].v = uvp->v;
            
            tv[2].u = uvp->u;
            tv[2].v = uvp->v + uvp->ys;
            
            tv[3].u = uvp->u + uvp->xs;
            tv[3].v = uvp->v + uvp->ys;
            
            njSetMatrix(NULL, cam.mtx);
            
            njTranslateEx((NJS_VECTOR*)&exp->px);
            njUnitRotPortion(NULL);
            njScaleEx((NJS_VECTOR*)&scl);
            
            njDrawTexture3DEx(tv, 4, 1);
            
            if ((sys->sp_flg & 0x8)) 
            {
                exp->scl *= 0.8f;
                
                exp->px += exp->xn;
                exp->py += exp->yn;
                exp->pz += exp->zn;
                
                exp->xn *= 0.8f;
                exp->zn *= 0.8f;
                exp->yn *= 0.8f;

                exp->yn -= 0.1f;
                
                exp->ct++;
                
                if (exp->ct > 9) 
                {
                    exp->ct = 0;
                }
            }
        }
    } 
        
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();
}

// 100% matching!
void bhEff027(O_WRK* op) 
{
    NJS_POINT3 ps;
    EXP_EFF025_WORK* exp;
    int i;
    
    op->flg |= 0x1000000;
    
    if (op->mode0 == 0) 
    {
        if ((op->exp0 = (unsigned char*)bhSetExtraEffectWork()) == NULL) 
        {
            op->flg = 0;
            return;
        }
        
        njCalcPoint(&plp->mlwP->owP[9].mtx, (NJS_POINT3*)&WpnTab[20].wp_fps2, (NJS_POINT3*)&op->px);
        
        exp = (EXP_EFF025_WORK*)&op->exp0[4];
        
        for (i = 0; i < 16; i++, exp++)
        {
            exp->flg = 1;
            
            exp->ct = 0;
            
            exp->scl = 1.0f;
            
            exp->px = op->px + ((-rand() / -2.1474836E9f) - 0.5f);
            exp->py = op->py + ((-rand() / -2.1474836E9f) - 0.5f);
            exp->pz = op->pz + ((-rand() / -2.1474836E9f) - 0.5f);
            
            njSetMatrix(NULL, &plp->mlwP->owP[9].mtx);
            
            ps.x = -(1.0f + (-rand() / -2.1474836E9f));
            ps.y = (-rand() / -2.1474836E9f) - 0.5f;
            ps.z = (-rand() / -2.1474836E9f) - 0.5f;
            
            njCalcVector(NULL, &ps, (NJS_VECTOR*)&exp->xn);
        } 
        
        op->func = (void*)bhDraw027;
        
        op->mode0 = 1;
    }
    
    op->ct0++;
    
    if (op->ct0 > 6) 
    {
        sys->ef.id = 2;
        
        sys->ef.flg = 0x4100001;

        sys->ef.type = 9;
        
        sys->ef.flr_no = 3;
        
        sys->ef.mdlver = 1;
        
        sys->ef.sx = 0.5f  * op->ct0;
        sys->ef.sy = 0.5f  * op->ct0;
        sys->ef.sz = 0.25f * (op->ct0 - 6);
        
        sys->ef.ax = 0;
        sys->ef.ay = 0;
        
        njCalcPoint(&plp->mlwP->owP[9].mtx, (NJS_POINT3*)&WpnTab[20].wp_fps2, (NJS_POINT3*)&sys->ef.px);
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
    
    if (op->ct0 > 8)
    {
        op->flg = 0;
        
        *(int*)op->exp0 = 0;
    }
    else 
    {
        sys->ef_fnc[sys->ef_fncn++] = op;
    }
}

// 100% matching!
void bhEff028()
{

}

// 100% matching!
void bhEff029(O_WRK* op)
{
	op->ct0 = (op->ct0 + 1) & 0x1F;

    if (op->ct0 == 0)
	{
        ((int*)op->lkwkp)[1] |= 0x40; // TODO: find the actual struct getting parsed to here

    	op->flg = 0;
    }
}

// 100% matching!
void bhEff100(O_WRK* op) 
{
    ER_WORK* erp;
    int i;
    
    op->flg |= 0x1000000;
    
    if ((op->stflg & 0x1000000)) 
    {
        op->flg = 0;
        return;
    }
    
    if (op->mode0 == 0) 
    {
        if ((op->exp0 = (unsigned char*)bhSetExtraEffectWork()) == NULL) 
        {
            op->flg = 0;
            return;
        }
        
        op->func = (void*)bhEff106;
        
        erp = (ER_WORK*)&op->exp0[4]; 
        
        i = 77;
        
        while (i--) 
        {
            erp->px = (cam.wpx + (30.0f * cam.vx)) + ((80.0f * (-rand() / -2.1474836E9f)) - 40.0f);
            erp->py = 80.0f * (-rand() / -2.1474836E9f);
            erp->pz = (cam.wpz + (30.0f * cam.vz)) + ((80.0f * (-rand() / -2.1474836E9f)) - 40.0f);
            
            erp->ax = 0;
            erp->ay = 0;
            
            erp++;
        } 
        
        op->mode0 = 1;
        return;
    }
    
    sys->ef_fnc[sys->ef_fncn++] = op;
}

// 100% matching!
void bhEff101(O_WRK* op)
{
    op->flg |= 0x1000000;
    
    if ((op->stflg & 0x1000000)) 
    {
        op->flg = 0;
        return;
    }
    
    sys->ef.id = 107;
    
    sys->ef.flg  = 1;
    sys->ef.type = 0;
    
    sys->ef.px = 0;
    sys->ef.py = 0;
    sys->ef.pz = 0;
    
    sys->ef.sx = op->sx;
    sys->ef.sy = op->sy;
    sys->ef.sz = op->sz;
    
    sys->ef.ay = 0;
    
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
}

// 99.90% matching
void bhEff102(O_WRK* op) 
{
    op->flg |= 0x1000000;
    
    sys->windrb = sys->windr;
    sys->windsb = sys->winds;
    
    if (op->lkono != 0)
    {
        sys->windr += (int)(182.04445f * ((op->sz * (-rand() / -2.1474836E9f)) - (0.5f * op->sz))) & 0xFFFF;
    } 
    else 
    {
        sys->windr = op->ay + ((int)(182.04445f * (20.0f * njSin(op->ct0))) & 0xFFFF);
    }
    
    sys->winds = op->sx + (op->sy * njSin(op->ct0));
    
    op->ct0 = (unsigned short)(op->ct0 + (op->type * 256));
}

// 100% matching!
void bhEff103(O_WRK* op)
{
    op->flg |= 0x1000000;
    
    switch (op->type) 
    {                            
    case 0:
        if ((-rand() / -2.1474836E9f) < 0.3f) 
        {
            sys->ef.id = 10;
            
            sys->ef.flg = 0x100001;
            
            sys->ef.type = 1;

            sys->ef.px = op->px + ((3.0f * (-rand() / -2.1474836E9f)) - 1.5f);
            sys->ef.py = op->py + ((3.0f * (-rand() / -2.1474836E9f)) - 1.5f);
            sys->ef.pz = op->pz + ((3.0f * (-rand() / -2.1474836E9f)) - 1.5f);
            
            sys->ef.sx = op->sx;
            sys->ef.sy = op->sy;
            sys->ef.sz = op->sz;
            
            sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
        
        break;
    case 1:
        op->ct0 = (op->ct0 + 1) & 3;
        
        if (op->ct0 == 0) 
        {
            sys->ef.id = 119;
            
            sys->ef.flg = 0x4100001;
            
            sys->ef.type = 0;
            
            sys->ef.px = op->px;
            sys->ef.py = op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.sx = op->sx;
            sys->ef.sy = op->sy;
            sys->ef.sz = op->sz;
            
            sys->ef.ay = op->ay + (int)(2048.0f * njSin(op->ct1));
            
            op->ct1 += 2048;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
        
        break;
    case 2:
        op->ct0 = (op->ct0 + 1) & 1;
        
        if (op->ct0 == 0) 
        {
            sys->ef.id = 119;
            
            sys->ef.flg = 0x4100001;
            
            sys->ef.type = 1;
            
            sys->ef.px = op->px;
            sys->ef.py = op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.sx = op->sx;
            sys->ef.sy = op->sy;
            sys->ef.sz = op->sz;
            
            sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
        
        break;
    }
}

// 99.89% matching
void bhEff104(O_WRK* op)
{
    int i, j;
    
    op->flg |= 0x1000000;
    
    for (i = 0, j = op->type; i < j; i++) 
    {
        sys->ef.id = 12;
        
        sys->ef.flg = 0x100001;
        
        sys->ef.mdlver = 0;
        
        if (op->flr_no == -1) 
        {
            sys->ef.type = 1;
        }
        else 
        {
            sys->ef.type = 0;
        }
        
        sys->ef.px = op->px + ((2.0f * (-rand() / -2.1474836E9f)) - 1.0f);
        sys->ef.py = op->py + ((2.0f * (-rand() / -2.1474836E9f)) - 1.0f);
        sys->ef.pz = op->pz + ((2.0f * (-rand() / -2.1474836E9f)) - 1.0f);
        
        sys->ef.sx = 0.1f;
        sys->ef.sy = 0.1f;
        sys->ef.sz = 0.1f;
        
        sys->ef.ay = op->ay + ((int)(182.04445f * ((90.0f * (-rand() / -2.1474836E9f)) - 45.0f)) & 0xFFFF);
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    } 
    
    op->ct0++;
    
    if (op->ct0 > op->mdlver) 
    {
        op->flg = 0;
    }
}

// 100% matching!
void bhEff105(O_WRK* op) 
{
    op->flg |= 0x1000000;
    
    switch (op->mode0) 
    {                             
    case 0:
        if (op->mode1 != 0) 
        {
            op->mode1 = 0;
            
            CallBackGroundSe(1, 770);
            
            op->ct0 = 16384;
            
            op->mode2 = 0;
            op->mode0 = 1;
        }
        
        break;
    case 1:
        if (op->ct0 > 0) 
        {
            if (((op->ct0 < 14336) && (op->ct0 > 10240)) && (op->mode2 == 0) && ((-rand() / -2.1474836E9f) > 0.7f))
            {
                op->mode2 = 1;
                
                op->ct0 = 16384;
                
                CallBackGroundSe(1, 770);
            }
        } 
        else
        {
            op->ct0 = 0;
            op->ct1 = 0;
            op->ct2 = 0;
            
            sys->thunder = 0;
            
            op->mode0 = 2;
        }
        
        break;
    case 2:
        op->ct1++;
        
        if (((op->ct1 < 120) && (op->ct2 < 3)) && ((-rand() / -2.1474836E9f) > 0.97f)) 
        {
            op->ct0 = (int)(1024.0f * (-rand() / -2.1474836E9f)) + 2048;
            op->ct2++;
        }
        
        if (op->ct1 == 30) 
        {
            CallBackGroundSe(1, 771);
        }
        
        if (op->ct1 > 180) 
        {
            op->mode0 = 0;
        }
        
        break;
    }
    
    if (op->mode0 != 0) 
    {
        op->ct0 -= 1536;
        
        if (op->ct0 < 0) 
        {
            op->ct0 = 0;
        }
        
        sys->thunder = fabsf(255.0f * njSin(op->ct0));
    }
}

// 100% matching!
void bhEff106(O_WRK* op) 
{
    NJS_POINT3COL p3c;
    ER_WORK* erp;
    int i;
    int ang[3];
    static NJS_POINT3 pos[2] = 
    {
        { 0.0f,  7.0f, 0.0f },
        { 0.0f, -7.0f, 0.0f }
    };
    static NJS_COLOR col[2] = 
    {
        0x10101010,
        0x40303030
    };
    
    njPushMatrixEx();
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 10);
    
    p3c.p   = pos;
    p3c.col = col;
    p3c.tex = NULL;
    p3c.num = 1;
    
    erp = (ER_WORK*)&op->exp0[4];
    
    i = 77;
    
    while (i-- != 0) 
    {
        if ((sys->sp_flg & 0x8)) 
        {
            erp->ax = 182.04445f * (25.0f * sys->winds);
            
            erp->px -= sys->winds * njSin(erp->ay);
            erp->pz -= sys->winds * njCos(erp->ay);
            erp->py -= 5.0f;
            
            if (erp->py < 0) 
            {
                erp->ay = sys->windr;
                
                erp->px = (cam.wpx + (30.0f * cam.vx)) + ((80.0f * (-rand() / -2.1474836E9f)) - 40.0f);
                erp->py = 80.0f;
                erp->pz = (cam.wpz + (30.0f * cam.vz)) + ((80.0f * (-rand() / -2.1474836E9f)) - 40.0f);
            }
        }
        
        njSetMatrix(NULL, cam.mtx);
        
        njTranslateEx((NJS_VECTOR*)&erp->px);
        
        ang[0] = erp->ax;
        ang[1] = erp->ay;
        ang[2] = 0;
        
        njRotateEx(ang, 0);
        
        njDrawLine3D(&p3c, 1, 0x40);
        
        erp++; 
    } 
    
    njPopMatrixEx();
}

// 100% matching!
void bhDraw107(O_WRK* op)
{
    ER_WORK* erp;
    UV_WORK* uvp;
    int i;
    static UV_WORK uvinfo[6] = 
    {
        { 0.0f,      0.0f, 0.109375f, 0.09375f },
        { 0.109375f, 0.0f, 0.109375f, 0.09375f },
        { 0.21875f,  0.0f, 0.109375f, 0.09375f },
        { 0.328125f, 0.0f, 0.109375f, 0.09375f },
        { 0.4375f,   0.0f, 0.109375f, 0.09375f },
        { -1.0f,     0.0f, 0.0f,      0.0f     }
    };
    static NJS_TEXTURE_VTX tv[4] = 
    {
        { -0.7f, -1.4f, 0.0f, 0.0f, 0.0f, 0x80808080 },
        {  0.7f, -1.4f, 0.0f, 0.0f, 0.0f, 0x80808080 },
        { -0.7f,  0.0f, 0.0f, 0.0f, 0.0f, 0x80808080 },
        {  0.7f,  0.0f, 0.0f, 0.0f, 0.0f, 0x80808080 }
    };
    
    njPushMatrixEx();
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[32]);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 10);
    
    njTextureFilterMode(0);
    
    erp = (ER_WORK*)&op->exp0[4];
    
    i = 8;
    
    while (i-- != 0)
    {
        uvp = &uvinfo[erp->ay];
        
        tv[0].u = uvp->u;
        tv[0].v = uvp->v;
        
        tv[1].u = uvp->u + uvp->xs;
        tv[1].v = uvp->v;
        
        tv[2].u = uvp->u;
        tv[2].v = uvp->v + uvp->ys;
        
        tv[3].u = uvp->u + uvp->xs;
        tv[3].v = uvp->v + uvp->ys;
        
        if ((sys->sp_flg & 0x8))
        {
            erp->ay++;
        }
        
        if ((erp->ay < 5) && (erp->ax != 0)) 
        {
            njSetMatrix(NULL, cam.mtx);
            
            njTranslateEx((NJS_VECTOR*)&erp->px);
            njUnitRotPortion(NULL);
            
            njDrawTexture3DEx(tv, 4, 1);
        }
        
        erp++;
    } 
    
    njPopMatrixEx();
}

// 100% matching!
void bhEff107(O_WRK* op) 
{
    ER_WORK* erp;
    ATR_WORK* hp;
    int i;
    
    if (op->mode0 == 0) 
    {
        if ((op->exp0 = (unsigned char*)bhSetExtraEffectWork()) == NULL) 
        {
            op->flg = 0;
            return;
        }
        
        op->func = (void*)bhDraw107;
        
        erp = (ER_WORK*)&op->exp0[4];

        i = 8;
        
        while (i-- != 0) 
        {
            erp->px = (cam.wpx + (40.0f * cam.vx)) + ((80.0f * (-rand() / -2.1474836E9f)) - 40.0f);
            erp->pz = (cam.wpz + (40.0f * cam.vz)) + ((80.0f * (-rand() / -2.1474836E9f)) - 40.0f);
            
            hp = bhCheckFloorEffect(0, erp->px, erp->pz);
            
            if ((hp != NULL) && ((hp->type == 3) && (hp->prm0 == 0))) 
            {
                erp->ax = 0;
            }
            else 
            {
                erp->ax = 1;
            }
            
            erp->py = 0.1f;
            erp->ay = 0;
            
            erp++;
        } 
        
        op->mode0 = 1;
        op->ct0   = 0;
        return;
    }
    
    op->ct0++;
    
    if (op->ct0 > 4) 
    {
        *(int*)op->exp0 = 0;
        
        op->flg = 0;
    }
    else 
    {
        sys->ef_fnc[sys->ef_fncn++] = op;
    }
}

// 100% matching!
void bhEff108(O_WRK* op) 
{
    int ox, oy;    
    int x, y;   
    int e;      
    int r;    
    int ax, ay;   
    float* wty; 

    if ((!(sys->st_flg & 0x40)) || ((sys->gm_flg & 0x1))) 
    {
        op->flg = 0;
        return;
    }
    
    op->flg |= 0x1000000;

    switch (op->mode0)
    {
    case 0:
        op->px -= sys->wt_px;
        op->pz -= sys->wt_pz;
        
        op->sy = 0.1f * op->lkono;
        
        op->car = 1.0f;
        
        op->spd = 0.5f * op->sy;
        
        op->mode0 = 1;
    case 1:
        ox = op->px;
        oy = op->pz;
        
        r = op->car;
        
        x = 0;

        e = 3 - (r * 2);

        for (; x <= r; x++) 
        {
            ax = ox + x;
            ay = oy + r;
            
            if (((unsigned short)ax < sys->wt_maxx) && ((unsigned short)ay < sys->wt_maxz)) 
            {
                wty = (float*)sys->wt_wvp;
                wty += ay + (ax * sys->wt_zp);
                
                if (op->sy > *wty)
                {
                    *wty = op->sy;
                }
            }
            
            ax = ox + x;
            ay = oy - r;
            
            if (((unsigned short)ax < sys->wt_maxx) && ((unsigned short)ay < sys->wt_maxz)) 
            {
                wty = (float*)sys->wt_wvp;
                wty += ay + (ax * sys->wt_zp);
                
                if (op->sy > *wty)
                {
                    *wty = op->sy;
                }
            }
            
            ax = ox - x;
            ay = oy + r;
            
            if (((unsigned short)ax < sys->wt_maxx) && ((unsigned short)ay < sys->wt_maxz)) 
            {
                wty = (float*)sys->wt_wvp;
                wty += ay + (ax * sys->wt_zp);
                
                if (op->sy > *wty) 
                {
                    *wty = op->sy;
                }
            }
            
            ax = ox - x;
            ay = oy - r;
            
            if (((unsigned short)ax < sys->wt_maxx) && ((unsigned short)ay < sys->wt_maxz)) 
            {
                wty = (float*)sys->wt_wvp;
                wty += ay + (ax * sys->wt_zp);
                
                if (op->sy > *wty) 
                {
                    *wty = op->sy;
                }
            }
            
            ax = ox + r;
            ay = oy + x;
            
            if (((unsigned short)ax < sys->wt_maxx) && ((unsigned short)ay < sys->wt_maxz)) 
            {
                wty = (float*)sys->wt_wvp;
                wty += ay + (ax * sys->wt_zp);
                
                if (op->sy > *wty)
                {
                    *wty = op->sy;
                }
            }
            
            ax = ox + r;
            ay = oy - x;
            
            if (((unsigned short)ax < sys->wt_maxx) && ((unsigned short)ay < sys->wt_maxz)) 
            {
                wty = (float*)sys->wt_wvp;
                wty += ay + (ax * sys->wt_zp);
                
                if (op->sy > *wty)
                {
                    *wty = op->sy;
                }
            }
            
            ax = ox - r;
            ay = oy + x;
            
            if (((unsigned short)ax < sys->wt_maxx) && ((unsigned short)ay < sys->wt_maxz)) 
            {
                wty = (float*)sys->wt_wvp;
                wty += ay + (ax * sys->wt_zp);
                
                if (op->sy > *wty) 
                {
                    *wty = op->sy;
                }
            }
            
            ax = ox - r;
            ay = oy - x;
            
            if (((unsigned short)ax < sys->wt_maxx) && ((unsigned short)ay < sys->wt_maxz)) 
            {
                wty = (float*)sys->wt_wvp;
                wty += ay + (ax * sys->wt_zp);
                
                if (op->sy > *wty) 
                {
                    *wty = op->sy;
                }
            }

            if (e < 0) 
            {
                e += x * 4;
                e += 6;
            } 
            else 
            {
                e += (x - r) * 4;
                e += 10;
                
                r--;
            }
        }
        
        op->car += op->spd;
        
        if (op->spd > 0.1f) 
        {
            op->spd -= 0.008f;
        }

        op->sy -= 0.01f;
        
        if (op->sy < 0)
        {
            op->flg = 0;
        }
    }
}

// 100% matching!
void bhEff109(O_WRK* op)
{
    POINT pos;
    
    op->flg |= 0x1000000;
    
    if (!(sys->gm_flg & 0x1)) 
    {
        if (op->type == 0) 
        {
            op->ct0 = (op->ct0 + 1) & 0xF;
            
            if (op->ct0 == 0) 
            {
                pos.px = op->px;
                pos.py = op->py;
                pos.pz = op->pz;
                
                bhSetEffect(108, &pos, NULL, 13);
            }
        } 
        else 
        {
            op->ct0++;
            
            if (op->ct0 > op->lkono) 
            {
                op->ct0 = 0;
                
                pos.px = op->px;
                pos.py = op->py;
                pos.pz = op->pz;
                
                bhSetEffect(108, &pos, NULL, op->type);
            }
        }
    }
}

// 100% matching!
void bhEff110(O_WRK* op)
{
    int i;   
    int x, y;   
    float px, py;
    float xn, yn; 

    op->flg |= 0x1000000;
    
    if (!(sys->ef_flg & 0x1))
    {
        switch (op->mode1) 
        {                       
        case 1:                                     
            op->mode1 = 0;
            op->mode0 = 10;
            break;
        case 2:                                     
            op->mode1 = 0;
            op->mode0 = 12;
            break;
        case 3:                                     
            op->mode1 = 0;
            
            sys->gm_flg &= ~0x100;
            
            BHD_ASPECT_Y = 1.0f;
            
            njSetAspect(BHD_ASPECT_X, 1.0f);
            
            op->mode0 = 1;
            break;
        case 4:                                     
            op->mode1 = 0;
            
            sys->gm_flg &= ~0x100;
            
            BHD_ASPECT_Y = 1.0f;
            
            njSetAspect(BHD_ASPECT_X, 1.0f);
            
            op->flg = 0;
            break;
        }
        
        if ((op->type > 0) && (op->mode0 != 0)) 
        {
            if ((cam.flg & 0x20))
            {
                if (!(sys->gm_flg & 0x100))
                {
                    op->mode0 = 10;
                }
            } 
            else if ((sys->gm_flg & 0x100))
            {
                sys->gm_flg &= ~0x100100;
                
                BHD_ASPECT_Y = 1.0f;
                
                njSetAspect(BHD_ASPECT_X, 1.0f);
                
                op->mode0 = 1;
            }
        }
        
        switch (op->mode0) 
        {                          
        case 0:     
            if (!(sys->gm_flg & 0x1)) 
            {
                sys->memp = (unsigned char*)(((int)sys->memp + 31) & ~0x1F);
                
                njSetTextureInfo(&sys->ren_info, (unsigned short*)sys->memp, 2817, 512, 512);
                njSetTextureName(sys->ren_tex, &sys->ren_info, 1, 0x40800000);
                
                sys->ren_tlist.textures  = sys->ren_tex;
                sys->ren_tlist.nbTexture = 1;
                
                njLoadTexture(&sys->ren_tlist);
                
                for (i = 0; i < 256; i++)
                {
                    sys->rpb[i].z = 0.83f; 
                    
                    switch (op->type) 
                    { 
                    case 0:
                        sys->rpb[i].bcol = -1;
                        sys->rpb[i].ocol = 0;
                        break;
                    default:
                        sys->rpb[i].bcol = -1;
                        sys->rpb[i].ocol = 0;
                        break;
                    } 
                }
                
                for (y = 0; y < 16; y++)
                {
                    for (x = 0; x < 16; x++)  
                    {
                        sys->rpb[x + (y * 16)].x = 42.66666f * x;
                        sys->rpb[x + (y * 16)].y = 32.0f     * y;
                        
                        if (x != 0) 
                        {
                            sys->rpb[x + (y * 16)].u = x / 15.0f;
                        }
                        else
                        {
                            sys->rpb[x + (y * 16)].u = 0;
                        }
                        
                        if (y != 0) 
                        {
                            sys->rpb[x + (y * 16)].v = 0.9375f * (y / 15.0f);
                        } 
                        else 
                        {
                            sys->rpb[x + (y * 16)].v = 0; 
                        }
                    }
                } 
                
                op->aspd = 0;
                
                op->mode0 = 1;
            }
            
            break;
        case 1:
            break; 
        case 10:                                    
            if ((sys->gm_flg & 0x1)) 
            {
                BHD_ASPECT_Y = 1.0f;
                
                njSetAspect(BHD_ASPECT_X, 1.0f);
                break;
            }
            
            switch (op->type) 
            {                      
            case 0:                                 
                op->spd = 0;
                
                op->mode0 = 11;
                break;
            case 1:                                 
                op->mode0 = 14;
                break;
            }
            
            BHD_ASPECT_Y = 1.25f;
            
            njSetAspect(BHD_ASPECT_X, 1.25f);
            
            sys->gm_flg |= 0x100;
            break;
        case 11:                                    
        case 12:                                    
        case 13:                                    
            sys->gm_flg |= 0x100;
            
            op->ct1 = op->ct0;
            
            for (y = 0; y < 16; y++) 
            {
                op->ct2 = op->ct1;
                
                xn = fabsf(op->spd * njSin(op->ct1));
                px = -xn;
                
                xn = 640.0f + (2.0f * xn);
                
                for (x = 0; x < 16; x++) 
                {
                    yn = fabsf(op->spd * njCos(op->ct2));
                    py = -yn;
                    
                    yn = 480.0f + (2.0f * yn);
                    
                    sys->rpb[(y * 16) + x].x = px + (x * (xn / 15.0f));
                    sys->rpb[(y * 16) + x].y = py + (y * (yn / 15.0f));
                    
                    op->ct2 = (unsigned short)(op->ct2 + 4096); 
                }
                
                op->ct1 = (unsigned short)(op->ct1 + 4096);
            }
            
            op->ct0 = (unsigned short)(op->ct0 + 256);
            
            switch (op->mode0)
            {                    
            case 11:                                
                if (op->spd < 20.0f) 
                {
                    op->spd += 0.25f;
                    
                    for (i = 0; i < 256; i++) 
                    {
                        sys->rpb[i].ocol = (unsigned short)op->spd << 17;
                    } 
                    
                    break;
                }
                
                op->mode0 = 13;
                break;
            case 12:                                
                op->spd -= 0.2f;
                
                if (op->spd < 0) 
                {
                    op->mode0 = 13;
                    
                    op->spd = 0;
                    
                    op->ct3 = 4;
                }
                
                for (i = 0; i < 256; i++) 
                {
                    sys->rpb[i].ocol = (unsigned short)op->spd << 17;
                } 
                
                break;
            }
            
            break;
        case 14:                                    
            sys->gm_flg |= 0x100100;
            
            op->ct1 = op->ct0;
            
            for (y = 0; y < 16; y++) 
            {
                op->ct2 = op->ct1;
                
                xn = fabsf(op->sx * njSin(op->ct1));
                px = -xn;
                
                xn = 640.0f + (2.0f * xn);
                
                for (x = 0; x < 16; x++) 
                { 
                    yn = fabsf(op->sy * njCos(op->ct2));
                    py = -yn;
                    
                    yn = 480.0f + (2.0f * yn);
                    
                    sys->rpb[(y * 16) + x].x = px + (x * (xn / 15.0f));
                    sys->rpb[(y * 16) + x].y = py + (y * (yn / 15.0f));
                    
                    op->ct2 = (unsigned short)(op->ct2 + 4096);
                }
                
                op->ct1 = (unsigned short)(op->ct1 + 4096);
            } 
            
            op->ct0 = (unsigned short)(op->ct0 + 256);
            break;
        }
    }
}

// 100% matching!
void bhEff111(O_WRK* op) 
{
    NJS_TEXTUREH_VTX* tvp; 
    float wsin, wcos;          
    
    if ((sys->ef_flg & 0x1)) 
    {
        return;
    }
    
    switch (op->mode0) 
    {                          
    case 0:                                     
        op->flg |= 0x1000000;
        
        if (sys->ren_n != 0)
        {
            op->mode0 = 1;
            break;
        } 
        else if (!(sys->gm_flg & 0x1)) 
        {
            bhGarbageTexture(tbuf, 256);
            
            sys->memp = (unsigned char*)(((int)sys->memp + 31) & ~0x1F);
            
            njSetTextureInfo(&sys->ren_info, (unsigned short*)sys->memp, 2817, 512, 512);
            njSetTextureName(&sys->ef_tex[sys->ef_ct], &sys->ren_info, sys->ren_gid, 0x40800000);
            
            sys->ef_tlist.textures  = &sys->ef_tex[sys->ef_ct];
            sys->ef_tlist.nbTexture = 1;
            
            njLoadTexture(&sys->ef_tlist);
            
            sys->ef_tn[op->id] = sys->ef_ct;
            
            op->tex_id = op->id;
            
            sys->ren_gid++;
            
            sys->ren_idx[sys->ren_n] = op->idx;
            
            sys->ren_n++;
            
            sys->ef_ct++;
            sys->ef_extn++;
            
            sys->ef_tlist.textures  = sys->ef_tex;
            sys->ef_tlist.nbTexture = sys->ef_ct;
            
            op->bl_src = 0;
            op->bl_dst = 0;
            
            op->tvp = (NJS_TEXTURE_VTX*)op->pv;
            tvp     = (NJS_TEXTUREH_VTX*)op->pvp;
            
            tvp[0].x = -1.0f;
            tvp[0].y = -1.0f;
            tvp[0].z = 0;
            
            tvp[1].x = 1.0f;
            tvp[1].y = -1.0f;
            tvp[1].z = 0;
            
            tvp[2].x = -1.0f;
            tvp[2].y = 1.0f;
            tvp[2].z = 0;
            
            tvp[3].x = 1.0f;
            tvp[3].y = 1.0f;
            tvp[3].z = 0;
            
            tvp[0].bcol = -1;
            tvp[1].bcol = -1;
            tvp[2].bcol = -1;
            tvp[3].bcol = -1;
            
            tvp[0].u = 1.0f;
            tvp[0].v = 0.9335f;
            
            tvp[1].u = 0;
            tvp[1].v = 0.9335f;
            
            tvp[2].u = 1.0f;
            tvp[2].v = 0;
            
            tvp[3].u = 0;
            tvp[3].v = 0;
            
            op->flg &= ~0x1000000;
            op->flg |= 0x4020000;
            
            op->mode0 = 1;
        }
        
        break;
    case 1:                                     
        tvp = (NJS_TEXTUREH_VTX*)op->pvp;
        
        switch (op->lkono) 
        {                      
        case 0:                                 
            tvp[0].ocol = 0;
            tvp[1].ocol = 0;
            tvp[2].ocol = 0;
            tvp[3].ocol = 0;
            
            op->ct0 = 0;
            op->ct1 = 0;
            op->ct2 = 0;
            break;
        case 1:                                 
            tvp[0].ocol = 0x400000;
            tvp[1].ocol = 0x400000;
            tvp[2].ocol = 0x400000;
            tvp[3].ocol = 0x400000;
            
            op->ct0 = 64;
            op->ct1 = 0;
            op->ct2 = 0;
            break;
        }
        
        op->mode0 = 2;
    case 2:                                     
        if ((sys->gm_flg & 0x1))
        {
            sys->gm_flg &= ~0x200;
            
            sys->ef_thl[sys->ef_thln++] = op;
            return;
        }
        
        if (op->lkono != 0) 
        {
            tvp = (NJS_TEXTUREH_VTX*)op->pvp;
            
            wsin = 0.02f * njSin(op->aspd);
            wcos = 0.02f * njCos(op->aspd);
            
            tvp[0].u = 0.98f   + wsin;
            tvp[0].v = 0.9135f - wsin;
            
            tvp[1].u = 0.02f   - wsin;
            tvp[1].v = 0.9135f - wcos;
            
            tvp[2].u = 0.98f + wcos;
            tvp[2].v = 0.02f + wsin;
            
            tvp[3].u = 0.02f - wcos;
            tvp[3].v = 0.02f + wcos;
            
            op->aspd = (unsigned short)(op->aspd + 512);
        }
        
        if (op->mode1 != 0) 
        {
            tvp = (NJS_TEXTUREH_VTX*)op->pvp;
            
            if ((unsigned short)op->mode1 == 2) 
            {
                tvp[0].ocol = 0;
                tvp[1].ocol = 0;
                tvp[2].ocol = 0;
                tvp[3].ocol = 0;
                
                op->mode0 = 3;
                
                sys->gm_flg |= 0x200;
                
                sys->ef_thl[sys->ef_thln++] = op;
                break;
            } 
            else
            {
                if (op->ct0 > 0) 
                {
                    op->ct0--;
                }
                
                if (op->ct1 > 0) 
                {
                    op->ct1--;
                }
                
                if (op->ct2 > 0) 
                {
                    op->ct2--;
                }
                
                tvp[0].ocol = (op->ct2 << 0) | ((op->ct0 << 16) | (op->ct1 << 8));
                tvp[1].ocol = (op->ct2 << 0) | ((op->ct0 << 16) | (op->ct1 << 8));
                tvp[2].ocol = (op->ct2 << 0) | ((op->ct0 << 16) | (op->ct1 << 8));
                tvp[3].ocol = (op->ct2 << 0) | ((op->ct0 << 16) | (op->ct1 << 8));
                
                if ((op->ct0 <= 0) && (op->ct1 <= 0) && (op->ct2 <= 0)) 
                {
                    op->mode0 = 3;
                }
            }
        } 
        
        if ((sys->cb_flg & 0x1)) 
        {
            sys->gm_flg &= ~0x200;
        }
        else 
        {
            sys->gm_flg |= 0x200;
        }
        
        sys->ef_thl[sys->ef_thln++] = op;
        break;
    case 3:                                     
        if (op->mode1 == 0) 
        {
            op->mode0 = 1;
        }
        
        sys->gm_flg &= ~0x200;
        
        sys->ef_thl[sys->ef_thln++] = op;
        break;
    }

    tvp = (NJS_TEXTUREH_VTX*)op->pvp;
    
    op->ct3 = (op->ct3 + 1) & 1;
    
    if (op->ct3 != 0)
    {
        tvp[0].bcol = -1;
        tvp[1].bcol = -1;
        tvp[2].bcol = -1;
        tvp[3].bcol = -1;
    } 
    else 
    {
        tvp[0].bcol = 0xFFC0C0C0;
        tvp[1].bcol = 0xFFC0C0C0;
        tvp[2].bcol = 0xFFC0C0C0;
        tvp[3].bcol = 0xFFC0C0C0;
    }
}

// 100% matching!
void bhEff112(O_WRK* op)
{
    NJS_VECTOR vec = { 0, 0, -1.0f };

    op->flg |= 0x1000000;
    
    if ((!(op->mdflg & 0x1)) && (sys->stg_no == 2))
    {
        sys->mr_pl.px = op->px;
        sys->mr_pl.py = op->py;
        sys->mr_pl.pz = op->pz;
        
        njSetMatrix(NULL, cmat);
        
        njRotateXYZ(NULL, op->ax, op->ay, op->az);
        njCalcVector(NULL, &vec, (NJS_VECTOR*)&sys->mr_pl.vx);
        
        sys->st_flg |= 0x100;
    }
    else 
    {
        sys->st_flg &= ~0x100;
    }
}

// 99.87% matching
void bhEff113(O_WRK* op)
{
    NJS_VECTOR vc0, vc1; 
    int i, j;         
    int ct;        
    float r;     
    float spd;    
    float xn, yn;    
    float spq;      
    float ax, ay; // not from DWARF
    
    switch (op->type) 
    {                           
    case 0:
        ct = 64;
        
        r = 1.0f;
        
        spd = 0.5f;
        
        sys->ef.sx = 0.4f;
        sys->ef.sy = 0.4f;
        sys->ef.sz = 0.4f;
        break;
    case 1:
        if ((sys->stg_no == 1) && (sys->rom_no == 9))
        {
            ct = 196;
        }
        else 
        {
            ct = 225;
        }
        
        r = 5.0f;
        
        spd = 1.0f;
        
        sys->ef.sx = 1.5f;
        sys->ef.sy = 1.5f;
        sys->ef.sz = 1.5f;
        break;
    case 2:
        ct = 128;
        
        r = 3.0f;
        
        spd = 0.8f;
        
        sys->ef.sx = 1.0f;
        sys->ef.sy = 1.0f;
        sys->ef.sz = 1.0f;
        break;
    }
    
    vc0.x = vc0.y = 0;
    vc0.z = -1.0f;
    
    sys->ef.id = 114;
    
    sys->ef.flg = 1;
    
    sys->ef.type = 0;
    
    sys->ef.flr_no = 0;
    
    spq = fabsf(njSqrt(ct));
    
    ax = 120.0f / spq;
    ay = 140.0f / spq;
    
    j = spq;
    
    for (i = 0; i < ct; i++)  
    {
        xn = ((30.0f * (-rand() / -2.1474836E9f)) - 15.0f) + ((ax * ((i + 1) / j)) - 60.0f);
        sys->ef.ax = op->ax + ((int)(182.04445f * xn) & 0xFFFF);
        
        yn = ((30.0f * (-rand() / -2.1474836E9f)) - 15.0f) + ((ay * ((i + 1) % j)) - 70.0f);
        sys->ef.ay = op->ay + ((int)(182.04445f * yn) & 0xFFFF);
        
        sys->ef.mdlver = (unsigned char)((i * 4) % 55);
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, sys->ef.ax, sys->ef.ay, 0);
        njCalcVector(NULL, &vc0, &vc1);
        
        sys->ef.px = op->px + (vc1.x * r);
        sys->ef.py = op->py + (vc1.y * r);
        sys->ef.pz = op->pz + (vc1.z * r);
        
        vc1.x *= spd;
        vc1.y *= spd;
        vc1.z *= spd;
        
        bhSetEffectTb(&sys->ef, &vc1, NULL, 0);
    } 
    
    op->flg = 0;
}

// 100% matching!
void bhDraw114(O_WRK* op) 
{
    NJS_TEXTUREH_VTX* tvp; 
    NJS_VECTOR vc0, vc1;        
    float it;              
    int pt;               
    
    njPushMatrixEx();
    
    vc0.x = vc0.y = 0;
    vc0.z = -1.0f;
    
    njUnitMatrix(NULL);
    
    njRotateXYZ(NULL, op->ax, op->ay, 0);
    njCalcVector(NULL, &vc0, &vc1);
    
    it = fabsf(njInnerProduct((NJS_VECTOR*)&vc1, (NJS_VECTOR*)&cam.vx));
    
    pt = (int)(128.0f * njCos((int)(182.04445f * (360.0f * it)) & 0xFFFF)) + 32;
    
    njTextureFilterMode(1);
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[op->tex_id]);
    
    njSetMatrix(NULL, cam.mtx);
    
    njTranslateEx((NJS_VECTOR*)&op->px);
    njRotateEx(&op->ax, 0);
    njScaleEx((NJS_VECTOR*)&op->sx);
    
    tvp = (NJS_TEXTUREH_VTX*)op->tvp;
    
    tvp[0].ocol = tvp[1].ocol = tvp[2].ocol = tvp[3].ocol = (pt << 0) | ((pt << 8) | ((pt << 24) | (pt << 16)));
    
    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);
    
    njDrawTexture3DHEx(tvp, 4, 1);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();
}

// 100% matching!
void bhEff114(O_WRK* op) 
{
    NJS_VECTOR vc0;        
    NJS_TEXTUREH_VTX* tvp; 
    int pt;                
    float u, v;             
    int is;               
    float fs;              
  
    switch (op->mode0) 
    {                             
    case 0:
        op->tex_id = 31;
        
        op->flg |= 0x6000000;
        
        op->tvp = (NJS_TEXTURE_VTX*)op->pv;
        tvp     = (NJS_TEXTUREH_VTX*)op->pvp;
        
        tvp[0].x = -1.0f;
        tvp[0].y = -1.0f;
        tvp[0].z = 0;
        
        tvp[1].x = 1.0f;
        tvp[1].y = -1.0f;
        tvp[1].z = 0;
        
        tvp[2].x = -1.0f;
        tvp[2].y = 1.0f;
        tvp[2].z = 0;
        
        tvp[3].x = 1.0f;
        tvp[3].y = 1.0f;
        tvp[3].z = 0;
        
        if ((sys->stg_no == 9) && (sys->rom_no == 11)) 
        {
            tvp[0].bcol = 0x60FFFFFF;
            tvp[1].bcol = 0x60FFFFFF;
            tvp[2].bcol = 0x60FFFFFF;
            tvp[3].bcol = 0x60FFFFFF;
        } 
        else 
        {
            tvp[0].bcol = 0xC0FFFFFF;
            tvp[1].bcol = 0xC0FFFFFF;
            tvp[2].bcol = 0xC0FFFFFF;
            tvp[3].bcol = 0xC0FFFFFF;
        }
        
        is = op->mdlver;
        
        if (is > 28)
        {
            v = ((is - 29) * 16) / 256.0f;
            
            tvp[0].u = v;
            tvp[0].v = 0.9375f;
            
            u = 0.0625f + v;
            
            tvp[1].u = u; 
            tvp[1].v = 0.9375f;
            
            tvp[2].u = v;
            tvp[2].v = 1.0f;
            
            tvp[3].u = u;
            tvp[3].v = 1.0f;
            
            op->sx = 6.0f * (0.0625f * op->sxb);
            op->sy = 6.0f * (0.0625f * op->syb);
            op->sz = 6.0f * (0.0625f * op->szb);
        } 
        else if (is > 14) 
        {
            u = (((is  - 15) % 8) * 32)        / 256.0f;
            v = ((((is - 15) / 8) * 32) + 144) / 256.0f;
            
            tvp[0].u = u;
            tvp[0].v = v;
            
            tvp[1].u = 0.125f + u;
            tvp[1].v = v;
            
            tvp[2].u = u;
            tvp[2].v = 0.125f + v;
            
            tvp[3].u = 0.125f + u;
            tvp[3].v = 0.125f + v;
            
            op->sx = 7.0f * (0.125f * op->sxb);
            op->sy = 7.0f * (0.125f * op->syb);
            op->sz = 7.0f * (0.125f * op->szb);
        }
        else 
        {
            u = (((is  - 15) % 5)  * 48) / 256.0f;
            v = ((((is - 15) / 5)) * 48) / 256.0f;
            
            tvp[0].u = u;
            tvp[0].v = v;
            
            tvp[1].u = 0.1875f + u;
            tvp[1].v = v;
            
            tvp[2].u = u;
            tvp[2].v = 0.1875f + v;
            
            tvp[3].u = 0.1875f + u;
            tvp[3].v = 0.1875f + v;
            
            op->sx = 8.0f * (0.1875f * op->sxb);
            op->sy = 8.0f * (0.1875f * op->syb);
            op->sz = 8.0f * (0.1875f * op->szb);
        }
        
        vc0.x = op->lox;
        vc0.y = op->loy;
        vc0.z = op->loz;
        
        njUnitVector(&vc0);
        
        op->axp = (int)(182.04445f * (10.0f + (10.0f * (-rand() / -2.1474836E9f)))) & 0xFFFF;
        op->ayp = (int)(182.04445f * (10.0f + (10.0f * (-rand() / -2.1474836E9f)))) & 0xFFFF;

        op->yn = op->loy;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->ani_ct = 0;
        op->ct0    = 0;
        
        op->func = (void*)bhDraw114;
        
        op->mode0 = 1;
    case 1:
        if ((sys->st_flg & 0x2000000)) 
        {
            pt = sys->ef_slow;
            
            fs = pt;
            
            op->ax += op->axp / pt;
            op->ay += op->ayp / pt;
            
            op->px += op->lox / fs;
            op->pz += op->loz / fs;
            
            op->lox -= (0.06f * op->lox) / fs;
            op->loz -= (0.06f * op->loz) / fs;
            
            op->py += op->yn / fs;
            
            if (op->yn > -1.0f) 
            {
                op->yn -= 0.05f / fs; 
            }
        } 
        else 
        {
            op->ax += op->axp;
            op->ay += op->ayp;
            
            op->px += op->lox;
            op->pz += op->loz;
            
            op->lox -= 0.06f * op->lox;
            op->loz -= 0.06f * op->loz;
            
            op->py += op->yn;
            
            if (op->yn > -1.0f) 
            {
                op->yn -= 0.05f;
            }
        }
        
        if (op->py < -10.0f)
        {
            op->flg = 0;
            return;
        }

        break;
    }

    sys->ef_fnc[sys->ef_fncn++] = op;
}

// 99.30% matching (matches on GC)
void bhEff115(O_WRK* op) 
{
    int i;
    
    op->flg |= 0x1000000;
    
    if (!(sys->gm_flg & 0x1)) 
    {
        switch (op->type) 
        {                 
        case 0:
            if (op->mode1 != 0)
            {
                op->spd -= 0.01f;
                
                if (op->spd <= 0) 
                {
                    op->mode1 = 0;
                    
                    op->stflg |= 0x1000000;
                    break;
                }
                
                op->ct0 = (int)(4.0f * op->spd) + 1;
                op->ct1 = (op->ct1 + 1) & 0x1;
                
                if ((op->ct0 == 1) && (op->ct1 != 0))
                {
                    return;
                }
            } 
            else 
            {
                op->spd = 1.0f;
                
                op->ct0 = 4;
            }
            
            sys->ef.id = 15;
            
            sys->ef.flg = 0x4100001;
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = 0;
            
            sys->ef.sx = 0.5f * op->spd;
            sys->ef.sy = 0.5f * op->spd;
            sys->ef.sz = 0.5f * op->spd;
            
            for (i = 0; i < op->ct0; i++) 
            {
                sys->ef.px = op->px + (op->spd * ((-rand() / -2.1474836e9f) - 0.5f));
                sys->ef.py = op->py + (op->spd * ((-rand() / -2.1474836e9f) - 0.5f));
                sys->ef.pz = op->pz + (op->spd * ((-rand() / -2.1474836e9f) - 0.5f));
                
                sys->ef.ay = op->ay + ((int)(182.04445f * (op->spd * ((6.0f * (-rand() / -2.1474836e9f)) - 3.0f))) & 0xFFFF);
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            }
            
            break;
        case 1:
            sys->ef.id = 15;
            
            sys->ef.flg = 0x4100001;
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = 3;
            
            sys->ef.sx = op->sx;
            sys->ef.sy = op->sy;
            sys->ef.sz = op->sz;
            
            sys->ef.px = op->px;
            sys->ef.py = op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.ay = op->ay;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            break;
        case 2:
            if (op->mode1 != 0) 
            {
                op->mode1 = 0;
                
                sys->ef.id = 124;
                
                sys->ef.flg = 0x4100001;
                
                sys->ef.mdlver = 0;
                
                sys->ef.type = 0;
                
                sys->ef.sx = 0.1f * op->sx;
                sys->ef.sy = 0.1f * op->sy;
                sys->ef.sz = 0.1f * op->sz;
                
                sys->ef.px = op->px;
                sys->ef.py = op->py;
                sys->ef.pz = op->pz;
                
                sys->ef.ay = op->ay;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            }
            
            break;
        }
    }
}

// 100% matching!
void bhEff116(O_WRK* op) 
{
    op->flg |= 0x1000000;
    
    op->ct3 = (op->ct3 + 1) & 0x3;
    
    if (op->ct3 != 0) 
    {
        return;
    }
    
    switch (op->type) 
    {
    case 0:
        sys->ef.id = 15;
        
        sys->ef.flg = 0x4100001;
        
        sys->ef.mdlver = op->ct3 & 0x7;
        
        sys->ef.type = 5;
        
        sys->ef.sx = op->sx;
        sys->ef.sy = op->sy;
        sys->ef.sz = op->sz;
        
        sys->ef.ay = op->ay;
        
        sys->ef.px = op->px;
        sys->ef.py = op->py;
        sys->ef.pz = op->pz;
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
		break;
    }
}

// 100% matching!
void bhEff117(O_WRK* op)
{
    UV_WORK* uvp;
    static UV_WORK uvinfo_p0[4] =
    {
        { 0.0f,    0.0f, 0.1875f, 0.1875f },
        { 0.1875f, 0.0f, 0.1875f, 0.1875f },
        { 0.375f,  0.0f, 0.1875f, 0.1875f },
        { -1.0f,   0.0f, 0.0f,    0.0f    }
    };
    static UV_WORK uvinfo_p1[4] = 
    {
        { 0.5625f, 0.0f,    0.1875f, 0.1875f },
        { 0.75f,   0.0f,    0.1875f, 0.1875f },
        { 0.0f,    0.1875f, 0.1875f, 0.1875f },
        { -1.0f,   0.0f,    0.0f,    0.0f    }
    };
    
    switch (op->mode0)
    {                            
    case 0:
        op->tex_id = 38;
        
        op->flg |= 0x4100000;
        
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        op->ct1 = (int)(4.0f * (-rand() / -2.1474836E9f)) + 1;
        
        if (op->type == 0) 
        {
            uvp = uvinfo_p0;
            
            op->exp0 = (unsigned char*)uvp;
        } 
        else 
        {
            uvp = uvinfo_p1;
            
            op->exp0 = (unsigned char*)uvp;
        }
        
        op->mode0 = 1;
        break;
    case 2:
        op->flg = 0;
        return;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        op->ct0 = 0;
        
        uvp = (UV_WORK*)op->exp0 + op->ct0;
    }
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 99.96% matching
void bhEff118(O_WRK* op) 
{
    O_WRK* opp;    
    NJS_POINT3 pos; 
    int i;          
    float ang;      
    short* wp;      
	
    op->flg |= 0x1000000;
    
    if (((op->mode1 != 0) && (op->mode0 != 0)) && (op->ct3 <= 0))
    {
        op->stflg |= 0x1000000;
        
        *(int*)&op->mode0 = 0;
        return;
    }
    
    if (op->mode0 == 0) 
    {
        wp = (short*)op->pv;
        
        for (i = 0; i < 8; i++) 
        {
            sys->ef.id = 117;
            
            sys->ef.flg = 0x4100001;
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = (int)(2.0f * (-rand() / -2.1474836E9f));
            
            sys->ef.sx = op->sx;
            sys->ef.sy = op->sx;
            sys->ef.sz = op->sx;
            
            sys->ef.ax = 0;
            sys->ef.ay = 0;
            
            ang = 182.04445f * (360.0f * (-rand() / -2.1474836E9f));
            
            pos.x = njSin((int)ang & 0xFFFF);
            pos.y = 0;
            pos.z = njCos((int)ang & 0xFFFF);
            
            sys->ef.px = op->px + pos.x;
            sys->ef.py = op->py;
            sys->ef.pz = op->pz + pos.z;
            
            *wp++ = op->ct3 = bhSetEffectTb(&sys->ef, &pos, NULL, 0);
        } 
        
        op->ct3 = 8;
        
        op->mode0 = 1;
    }
    else 
    {
        wp = (short*)op->pv;
        
        for (i = 0; i < 8; i++) 
        {
            opp = &eff[*wp++];
            
            if (((opp->flg & 0x3)) && (opp->id == 117))
            {
                if (((op->mode1 != 0) && (opp->mode1 == 0)) && ((op->ct2 & 0x1F) == (i * 4))) 
                {
                    opp->mode1 = 1;
                }
                
                opp->px = op->px + (opp->lox * op->sy);
                opp->py = op->py;
                opp->pz = op->pz + (opp->loz * op->sy);
                
                if (opp->mode1 == 0) 
                {
                    opp->sx = op->sx;
                    opp->sy = op->sx;
                } 
                else
                {
                    opp->sx -= 0.2f;
                    opp->sy -= 0.2f;
                    
                    if (opp->sx <= 0.2f) 
                    {
                        opp->mode0 = 2;
                        
                        op->ct3--;
                    }
                }
            }
        }
    }
    
    op->ct2++;
}

// 100% matching!
void bhEff119(O_WRK* op) 
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_p0[16] =
    {
        { 0.0f,     0.0f,     0.0625f,  0.0625f  },
        { 0.0f,     0.0625f,  0.0625f,  0.0625f  },
        { 0.0625f,  0.0f,     0.09375f, 0.09375f },
        { 0.15625f, 0.0f,     0.125f,   0.125f   },
        { 0.28125f, 0.0f,     0.125f,   0.125f   },
        { 0.40625f, 0.0f,     0.1875f,  0.1875f  },
        { 0.59375f, 0.0f,     0.1875f,  0.1875f  },
        { 0.78125f, 0.0f,     0.1875f,  0.1875f  },
        { 0.0f,     0.125f,   0.21875f, 0.21875f },
        { 0.0f,     0.34375f, 0.25f,    0.25f    },
        { 0.25f,    0.34375f, 0.25f,    0.25f    },
        { 0.5f,     0.34375f, 0.25f,    0.25f    },
        { 0.75f,    0.34375f, 0.25f,    0.25f    },
        { 0.0f,     0.59375f, 0.25f,    0.25f    },
        { 0.25f,    0.59375f, 0.25f,    0.25f    },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    
    switch (op->mode0)
    {
    case 0:
        op->tex_id = 39;
        
        op->flg |= 0x4100000;
        
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        op->bl_src = 11;
        op->bl_dst = 3;
        
        op->gpy = op->py;
        
        op->ani_ct = 0;
        op->ct0    = 0;
        
        op->xn = (0.4f * (-rand() / -2.1474836E9f)) - 0.2f;
        op->zn = (0.4f * (-rand() / -2.1474836E9f)) - 0.2f;
        
        switch (op->type)
        {                        
        case 0:                                     
            op->tv[0].col = 0xC0FFFFFF;
            op->tv[1].col = 0xC0FFFFFF;
            op->tv[2].col = 0xC0FFFFFF;
            op->tv[3].col = 0xC0FFFFFF;
            
            op->ct2 = 192;
            
            op->exp0 = (unsigned char*)uvinfo_p0;
            
            op->spd = 0.1f * op->sz;
            break;
        case 1:                                     
            op->exp0 = (unsigned char*)&uvinfo_p0[5];
            break;
        }
        
        op->mode0 = 1;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f) 
    {
        op->flg = 0;
        return;
    }
    
    switch (op->type) 
    {                            
    case 0:                                         
        op->tv[0].col = (op->ct2 << 24) | 0xFFFFFF;
        op->tv[1].col = (op->ct2 << 24) | 0xFFFFFF;
        op->tv[2].col = (op->ct2 << 24) | 0xFFFFFF;
        op->tv[3].col = (op->ct2 << 24) | 0xFFFFFF;
        
        op->spd *= 0.9f;
        
        op->px -= op->spd * njSin(op->ay);
        op->pz -= op->spd * njCos(op->ay);
        op->py += 0.5f;
        
        op->ct2 -= 8;
        break;
    case 1:                                         
        op->px += op->xn;
        op->pz += op->zn;
        op->py = op->gpy + (op->sz * njSin(op->ct0 * 1024));
        
        op->sx = 8.0f * (op->sxb * uvp->xs);
        op->sy = 8.0f * (op->syb * uvp->ys);
        break;
    }
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff120(O_WRK* op)
{
    BH_PWORK* ep;
    short az;
	
    op->flg |= 0x1000000;
    
    switch (op->mode0)
    {                             
    case 0:
        if (!(sys->gm_flg & 0x1)) 
        {
            op->ct0 = 0;
            
            ep = (BH_PWORK*)op->lkwkp;
            
            op->ct1 = 1024;
            
            npSetOffsetUV(ep->mlwP->objP[4].model, 0, op->ct1);
            npSetOffsetUV(ep->mlwP->objP[2].model, 0, op->ct1);
            
            op->ct3 = 0;
            
            op->mode0 = 1;
        }
        
        break;
    case 1:
        ep = (BH_PWORK*)op->lkwkp;
        
        if ((sys->gm_flg & 0x1)) 
        {
            npSetOffsetUV(ep->mlwP->objP[4].model, 0, -op->ct1);
            npSetOffsetUV(ep->mlwP->objP[2].model, 0, -op->ct1);
            
            op->mode0 = 0;
            break;
        }
        
        az = ep->mlwP->objP[11].ang[2] - op->azp;
        
        op->azp = ep->mlwP->objP[11].ang[2];
        
        op->ct0 = -(az / 32);
        
        npSetOffsetUV(ep->mlwP->objP[4].model, 0, op->ct0);
        npSetOffsetUV(ep->mlwP->objP[2].model, 0, op->ct0);
        
        op->ct1 += op->ct0;
        
        if (op->ct1 <= 0) 
        {
            op->ct1 += 1024;
            
            npSetOffsetUV(ep->mlwP->objP[4].model, 0, 1024);
            npSetOffsetUV(ep->mlwP->objP[2].model, 0, 1024);
        }

        break;
    }
}

// 100% matching!
void bhEff121(O_WRK* op) 
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_p0[9] =
    {
        { 0.0f,  0.0f, 0.25f, 0.5f },
        { 0.0f,  0.5f, 0.25f, 0.5f },
        { 0.25f, 0.0f, 0.25f, 0.5f },
        { 0.25f, 0.5f, 0.25f, 0.5f },
        { 0.5f,  0.0f, 0.25f, 0.5f },
        { 0.5f,  0.5f, 0.25f, 0.5f },
        { 0.75f, 0.0f, 0.25f, 0.5f },
        { 0.75f, 0.5f, 0.25f, 0.5f },
        { -1.0f, 0.0f, 0.0f,  0.0f }
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 40;
        
        op->flg |= 0x4000000;
        
        op->tv[0].x = -1.0f;
        op->tv[0].y = 0;
        op->tv[0].z = 0;
        
        op->tv[1].x = 1.0f;
        op->tv[1].y = 0;
        op->tv[1].z = 0;
        
        op->tv[2].x = -1.0f;
        op->tv[2].y = -2.0f;
        op->tv[2].z = 0;
        
        op->tv[3].x = 1.0f;
        op->tv[3].y = -2.0f;
        op->tv[3].z = 0;
        
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        
        op->exp0 = (unsigned char*)uvinfo_p0;
        
        op->mode0 = 1;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f)
    {
        op->ct0 = 0;
        
        uvp = (UV_WORK*)op->exp0 + op->ct0;
    }
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff122(O_WRK* op)
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_p0[3] = 
    {
        { 0.0f,   0.0f, 0.125f, 0.125f },
        { 0.125f, 0.0f, 0.125f, 0.125f },
        { 0.25f,  0.0f, 0.125f, 0.125f }
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 41;
        
        op->flg |= 0x4000000;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->ct0 = 0;
        
        op->exp0 = (unsigned char*)uvinfo_p0;
        
        op->mode0 = 1;
        break;
    }
    
    op->ani_ct = op->type;
    
    uvp = (UV_WORK*)op->exp0 + op->mode1;
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 99.88% matching
void bhEff123(O_WRK* op) 
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_p0[4] = 
    {
        { 0.0f,    0.875f, 0.0625f, 0.0625f },
        { 0.0625f, 0.875f, 0.0625f, 0.0625f },
        { 0.125f,  0.875f, 0.0625f, 0.0625f },
        { 0.1875f, 0.875f, 0.0625f, 0.0625f }
    };
        
    switch (op->mode0) 
    {                             
    case 0:                                         
        op->tex_id = 2;
        
        op->flg |= 0x4100000;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        
        op->exp0 = (unsigned char*)uvinfo_p0;
        
        op->ct2 = 0;
        
        op->mode0 = 1;
        break;
    case 1:                                         
        op->ct1++;
        
        if ((op->ct1 > op->ct2) || (op->mode1 != 0)) 
        {
            op->ct1 = 0;
            op->ct2 = 20.0f + (10.0f * (-rand() / -2.1474836E9f));
            
            op->mode1 = 0;
            op->mode0 = 2;
        }
        
        return;
    }
    
    switch (op->type) 
    {                          
    case 1:
        op->tv[0].col = 0xFFFF0000;
        op->tv[1].col = 0xFFFF0000;
        op->tv[2].col = 0xFFFF0000;
        op->tv[3].col = 0xFFFF0000;
        break;
    case 2:                                     
        op->tv[0].col = 0xFF00FF00;
        op->tv[1].col = 0xFF00FF00;
        op->tv[2].col = 0xFF00FF00;
        op->tv[3].col = 0xFF00FF00;
        break;
    case 3:                                     
        op->tv[0].col = 0xFF0000FF;
        op->tv[1].col = 0xFF0000FF;
        op->tv[2].col = 0xFF0000FF;
        op->tv[3].col = 0xFF0000FF;
        break;
    case 4:                                     
        op->tv[0].col = 0xFF00FFFF;
        op->tv[1].col = 0xFF00FFFF;
        op->tv[2].col = 0xFF00FFFF;
        op->tv[3].col = 0xFF00FFFF;
        break;
    case 5:                                     
        op->tv[0].col = ~0xFF;
        op->tv[1].col = ~0xFF;
        op->tv[2].col = ~0xFF;
        op->tv[3].col = ~0xFF;
        break;
    default: 
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    op->az = op->ct0 * 4096;
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0 = (op->ct0 + 1) & 3;
    
    if (op->ct0 == 0) 
    {
        op->mode0 = 1;
    }
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff124(O_WRK* op) 
{
    UV_WORK* uvp;           
    NJS_POINT3 pos;     
    static UV_WORK uvinfo[15] = 
    {
        { 0,       0.9375f, 0.0625f, 0.0625f },
        { 0.0625f, 0.9375f, 0.0625f, 0.0625f },
        { 0.125f,  0.9375f, 0.0625f, 0.0625f },
        { 0.1875f, 0.9375f, 0.0625f, 0.0625f },
        { 0.25f,   0.9375f, 0.0625f, 0.0625f },
        { 0.3125f, 0.9375f, 0.0625f, 0.0625f },
        { 0.375f,  0.9375f, 0.0625f, 0.0625f },
        { 0.4375f, 0.9375f, 0.0625f, 0.0625f },
        { 0.5f,    0.9375f, 0.0625f, 0.0625f },
        { 0.5625f, 0.9375f, 0.0625f, 0.0625f },
        { 0.625f,  0.9375f, 0.0625f, 0.0625f },
        { 0.6875f, 0.9375f, 0.0625f, 0.0625f },
        { 0.75f,   0.9375f, 0.0625f, 0.0625f },
        { 0.8125f, 0.9375f, 0.0625f, 0.0625f },
        { 0.875f,  0.9375f, 0.0625f, 0.0625f }
    }; 
    
    switch (op->mode0) 
    {                              
    case 0:
        op->tex_id = 33;
        
        op->flg |= 0x4100000;
        
        op->tv[0].x = -1.0f;
        op->tv[0].y = -2.0f;
        op->tv[0].z = 0;
        
        op->tv[1].x = 1.0f;
        op->tv[1].y = -2.0f;
        op->tv[1].z = 0;
        
        op->tv[2].x = -1.0f;
        op->tv[2].y = 0;
        op->tv[2].z = 0;
        
        op->tv[3].x = 1.0f;
        op->tv[3].y = 0;
        op->tv[3].z = 0;
        
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        pos.x = op->px;
        pos.y = op->py - 3.0f;
        pos.z = op->pz;
        
        op->gpy = bhGetGroundPosition(&pos);
        op->ofy = op->py;
        
        op->ani_ct = 0;
        
        uvp = uvinfo;
        
        op->exp0 = (unsigned char*)uvp;
        
        op->mode0 = 1;
        return;
    case 1:
        uvp = (UV_WORK*)op->exp0 + op->ct0;
        
        op->ct0++;
        
        if (op->ct0 > 4)
        {
            op->mode0 = 2;
        }
        
        break;
    case 2:
        uvp = (UV_WORK*)op->exp0 + op->ct0;
        
        op->ct0++;
        
        if (op->ct0 > 8) 
        {
            op->ct0 = 5;
        }
        
        if (op->yn > -2.0f) 
        {
            op->yn -= 0.1f;
        }
        
        op->py += op->yn;
        
        if (op->py < op->gpy) 
        {
            op->py = op->gpy;
            
            op->ct0 = 9;
            
            op->mode0 = 3;
        }
        
        break;
    case 3:
        uvp = (UV_WORK*)op->exp0 + op->ct0;
        
        op->ct0++; 
        
        if (op->ct0 > 14) 
        {
            op->flg = 0;
            return;
        }
        
        break;
    }

    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff125(O_WRK* op)
{
    op->flg |= 0x1000000;
    
    if ((!(sys->gm_flg & 0x1)) && (op->mode1 != 0)) 
    {
        sys->ef.id = 126;
        
        sys->ef.flg = 0x4100001;
        
        sys->ef.mdlver = op->type % 4;
        
        sys->ef.type = op->mode1 - 1;
        
        sys->ef.sx = 0.25f * op->sx;
        sys->ef.sy = 0.25f * op->sy;
        sys->ef.sz = op->sz;
        
        sys->ef.px = op->px + ((-rand() / -2.1474836E9f) - 0.5f);
        sys->ef.py = op->py;
        sys->ef.pz = op->pz + ((-rand() / -2.1474836E9f) - 0.5f);
        
        sys->ef.ay = op->ay;
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        op->mode1 = 0;
    }
}

// 100% matching!
void bhEff126(O_WRK* op) 
{
    UV_WORK* uvp;
    NJS_POINT3 pos;
    int alpha;
    static UV_WORK uvinfo_p0[19] = 
    {
        { 0.0f,     0.0f,     0.15625f, 0.15625f },
        { 0.15625f, 0.0f,     0.15625f, 0.15625f },
        { 0.3125f,  0.0f,     0.15625f, 0.15625f },
        { 0.46875f, 0.0f,     0.15625f, 0.15625f },
        { 0.625f,   0.0f,     0.15625f, 0.15625f },
        { 0.78125f, 0.0f,     0.15625f, 0.15625f },
        { 0.625f,   0.0f,     0.15625f, 0.15625f },
        { 0.78125f, 0.0f,     0.15625f, 0.15625f },
        { 0.625f,   0.0f,     0.15625f, 0.15625f },
        { 0.78125f, 0.0f,     0.15625f, 0.15625f },
        { 0.625f,   0.0f,     0.15625f, 0.15625f },
        { 0.78125f, 0.0f,     0.15625f, 0.15625f },
        { 0.625f,   0.0f,     0.15625f, 0.15625f },
        { 0.78125f, 0.0f,     0.15625f, 0.15625f },
        { 0.0f,     0.15625f, 0.15625f, 0.15625f },
        { 0.15625f, 0.15625f, 0.15625f, 0.15625f },
        { 0.3125f,  0.15625f, 0.15625f, 0.15625f },
        { 0.46875f, 0.15625f, 0.15625f, 0.15625f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_p1[19] = 
    {
        { 0.0f,     0.3125f,  0.15625f, 0.15625f },
        { 0.15625f, 0.3125f,  0.15625f, 0.15625f },
        { 0.3125f,  0.3125f,  0.15625f, 0.15625f },
        { 0.46875f, 0.3125f,  0.15625f, 0.15625f },
        { 0.625f,   0.3125f,  0.15625f, 0.15625f },
        { 0.78125f, 0.3125f,  0.15625f, 0.15625f },
        { 0.625f,   0.3125f,  0.15625f, 0.15625f },
        { 0.78125f, 0.3125f,  0.15625f, 0.15625f },
        { 0.625f,   0.3125f,  0.15625f, 0.15625f },
        { 0.78125f, 0.3125f,  0.15625f, 0.15625f },
        { 0.625f,   0.3125f,  0.15625f, 0.15625f },
        { 0.78125f, 0.3125f,  0.15625f, 0.15625f },
        { 0.625f,   0.3125f,  0.15625f, 0.15625f },
        { 0.78125f, 0.3125f,  0.15625f, 0.15625f },
        { 0.0f,     0.46875f, 0.15625f, 0.15625f },
        { 0.15625f, 0.46875f, 0.15625f, 0.15625f },
        { 0.3125f,  0.46875f, 0.15625f, 0.15625f },
        { 0.46875f, 0.46875f, 0.15625f, 0.15625f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_p2[20] = 
    {
        { 0.0f,     0.0f,  0.0625f,  0.0625f  },
        { 0.0625f,  0.0f,  0.09375f, 0.09375f },
        { 0.15625f, 0.0f,  0.09375f, 0.09375f },
        { 0.25f,    0.0f,  0.125f,   0.125f   },
        { 0.375f,   0.0f,  0.1875f,  0.1875f  },
        { 0.5625f,  0.0f,  0.1875f,  0.1875f  },
        { 0.75f,    0.0f,  0.25f,    0.25f    },
        { 0.5625f,  0.0f,  0.1875f,  0.1875f  },
        { 0.75f,    0.0f,  0.25f,    0.25f    },
        { 0.5625f,  0.0f,  0.1875f,  0.1875f  },
        { 0.75f,    0.0f,  0.25f,    0.25f    },
        { 0.0f,     0.25f, 0.25f,    0.25f    },
        { 0.25f,    0.25f, 0.25f,    0.25f    },
        { 0.5f,     0.25f, 0.25f,    0.25f    },
        { 0.75f,    0.25f, 0.25f,    0.25f    },
        { 0.0f,     0.5f,  0.25f,    0.25f    },
        { 0.25f,    0.5f,  0.25f,    0.25f    },
        { 0.5f,     0.5f,  0.25f,    0.25f    },
        { 0.75f,    0.5f,  0.25f,    0.25f    },
        { -1.0f,    0.0f,  0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_p3[16] = 
    {
        { 0.0f,     0.0f,  0.0625f,  0.0625f  },
        { 0.0625f,  0.0f,  0.09375f, 0.09375f },
        { 0.15625f, 0.0f,  0.09375f, 0.09375f },
        { 0.25f,    0.0f,  0.125f,   0.125f   },
        { 0.375f,   0.0f,  0.1875f,  0.1875f  },
        { 0.5625f,  0.0f,  0.1875f,  0.1875f  },
        { 0.75f,    0.0f,  0.25f,    0.25f    },
        { 0.0f,     0.25f, 0.25f,    0.25f    },
        { 0.25f,    0.25f, 0.25f,    0.25f    },
        { 0.5f,     0.25f, 0.25f,    0.25f    },
        { 0.75f,    0.25f, 0.25f,    0.25f    },
        { 0.0f,     0.5f,  0.25f,    0.25f    },
        { 0.25f,    0.5f,  0.25f,    0.25f    },
        { 0.5f,     0.5f,  0.25f,    0.25f    },
        { 0.75f,    0.5f,  0.25f,    0.25f    },
        { -1.0f,    0.0f,  0.0f,     0.0f     }
    };

    switch (op->mode0) 
    {
    case 0:
        op->tex_id = 35;
        
        op->flg |= 0x4100000;
        
        if (op->type < 5) 
        {
            op->tv[0].x = -1.0f;
            op->tv[0].y = 1.0f;
            op->tv[0].z = 0;
            
            op->tv[1].x = 1.0f;
            op->tv[1].y = 1.0f;
            op->tv[1].z = 0;
            
            op->tv[2].x = -1.0f;
            op->tv[2].y = -1.0f;
            op->tv[2].z = 0;
            
            op->tv[3].x = 1.0f;
            op->tv[3].y = -1.0f;
            op->tv[3].z = 0;
            
            op->tv[0].col = -1;
            op->tv[1].col = -1;
            op->tv[2].col = -1;
            op->tv[3].col = -1;
        }
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        pos.x = op->px;
        pos.y = op->py - 3.0f;
        pos.z = op->pz;
        
        op->gpy = bhGetGroundPosition(&pos);
        op->yn  = -0.1f;
        
        switch (op->type) 
        {                          
        case 0:                                     
        case 1:                                     
            op->exp0 = (unsigned char*)uvinfo_p0;
            
            op->spd = 0.015f * op->sz;
            
            op->ani_ct = 0;
            break;
        case 2:                                     
        case 3:                                     
            op->exp0 = (unsigned char*)uvinfo_p1;
            
            op->sx *= 0.8f;
            op->sy *= 0.8f;
            
            op->spd = 0.02f * op->sz;
            
            op->ani_ct = 1;
            break;
        case 4:                                     
            alpha = ((64 - (op->mdlver * 16)) << 24) | 0xFFFFFF;
            
            op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = alpha;
            
            op->exp0 = (unsigned char*)uvinfo_p2;
            
            op->sx *= 1.2f;
            op->sy *= 1.2f;
            
            op->spd = 0.005f * op->sz;
            
            op->ani_ct = 2;
            break;
        case 6:                                     
            op->yn = 0.25f * op->sz;
        case 5:                                     
            alpha = ((128 - (op->mdlver * 32)) << 24) | 0xFFFFFF;
            
            op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = alpha;
            
            op->exp0 = (unsigned char*)uvinfo_p3;
            
            op->ani_ct = 2;
            break;
        }
        
        op->mode0 = 1;
        break;
    }
    
    switch (op->type)
    {                            
    case 0:                                         
    case 1:                                         
    case 2:                                         
    case 3:                                         
    case 4:                                         
        if (op->yn > -3.0f) 
        {
            op->yn -= op->spd;
        }
        
        op->py += op->yn;
        break;
    case 6:                                         
        op->py += op->yn;
        op->yn *= 0.8f;
        break;
    }
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if ((uvp->u == -1.0f) || (op->py < op->gpy)) 
    {
        op->flg = 0;
        return;
    }
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 99.84% matching (matches on NGC)
void bhEff127(O_WRK* op) 
{
    if (((op->mode1 == 0) && (op->type < 2)) || ((bhCkFlg(sys->ev_flg, 2) != 0) && (op->type < 2))) 
    {
        op->mode0 = 0;
        return;
    }
    
    if (op->mode0 == 0)
    {
        op->sx = 2.0f;
        
        op->ct0 = (op->idx & 3) * 4;
        
        sys->gas_py = 0;
        op->gpy = bhGetGroundPosition((NJS_POINT3*)&op->px);
        
        op->mode0 = 1;
        return;
    }
    
    op->ct0++;
    
    switch (op->type)
    {                             
    case 0:
        if (!(op->ct0 & 0xF)) 
        {
            sys->ef.id = 128;
            
            sys->ef.flg = 0x4000001;
            
            sys->ef.type = 0;
            
            sys->ef.flr_no = 0;
            
            sys->ef.mdlver = op->lkono;
            
            sys->ef.sx = op->sx;
            sys->ef.sy = 0;
            sys->ef.sz = op->sx;
            
            sys->ef.px = op->px;
            sys->ef.py = op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.ax = sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            if (op->sx < 4.0f) 
            {
                op->sx += 0.5f;
            }
        }
        
        break;
    case 1:
        if ((sys->gas_py > 0.5f) && (!(op->ct0 & 0x7)))
        {
            if (!(op->ct0 & 0x1F)) 
            {
                op->ct1 = (op->ct1 + 1) & 1;
                
                sys->ef.py = sys->gas_py - (0.1f * op->ct1);
                
                sys->ef.type = 1;
                
                sys->ef.flr_no = op->ct1;
            } 
            else 
            {
                sys->ef.py = 0.1f + (sys->gas_py * (-rand() / -2.1474836E9f));
                
                sys->ef.type = 2;
                
                sys->ef.flr_no = (int)(2.0f * (-rand() / -2.1474836E9f)) + 2;
            }
            
            sys->ef.px = op->px + ((30.0f * (-rand() / -2.1474836E9f)) - 15.0f);
            sys->ef.pz = op->pz + ((30.0f * (-rand() / -2.1474836E9f)) - 15.0f);
            
            sys->ef.sx = 50.0f;
            sys->ef.sz = 50.0f;
            
            sys->ef.id = 128;
            
            sys->ef.flg = 0x4000001;
            
            sys->ef.mdlver = op->lkono;
            
            sys->ef.sy = (2.0f * (-rand() / -2.1474836E9f)) - 1.0f;
            
            sys->ef.ax = sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
        
        if (sys->gas_py < 17.0f) 
        {
            sys->gas_py += 0.018f;
        }
        
        if (((1.0f + plp->mlwP->owP[5].mtx[13]) < sys->gas_py) && (!(plp->stflg & 0x40000))) 
        {
            plp->hp = -1;
        }
        
        break;
    case 2:
        if (!(op->ct0 & 0xF)) 
        {
            if (!(op->ct0 & 0x1F))
            {
                op->ct1 = (op->ct1 + 1) & 1;
                
                sys->ef.py = op->py - (0.1f * op->ct1);
                
                sys->ef.type = 1;
                
                sys->ef.flr_no = op->ct1;
            } 
            else 
            {
                sys->ef.py = 0.1f + (((op->py - op->gpy) - 0.1f) * (-rand() / -2.1474836E9f));
                
                sys->ef.type = 2;
                
                sys->ef.flr_no = (int)(2.0f * (-rand() / -2.1474836E9f)) + 2;
            }
            
            sys->ef.px = op->px + ((30.0f * (-rand() / -2.1474836E9f)) - 15.0f);
            sys->ef.pz = op->pz + ((30.0f * (-rand() / -2.1474836E9f)) - 15.0f);
            
            sys->ef.sx = 50.0f;
            sys->ef.sz = 50.0f;
            
            sys->ef.id = 128;
            
            sys->ef.flg = 0x4000001;
            
            sys->ef.mdlver = op->lkono;
            
            sys->ef.sy = (2.0f * (-rand() / -2.1474836E9f)) - 1.0f;
            
            sys->ef.ax = sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
        
        break;
    }
}

// 100% matching!
void bhEff128(O_WRK* op) 
{
	unsigned int argb;
    float x, y;
    
    switch (op->mode0) 
    {
    case 0:
        switch (op->type) 
        {
        case 0:
            op->tex_id = 2;
            
            op->ani_ct = 1;
            
            op->tv[0].u = 0.1875f;
            op->tv[0].v = 0.3125f;
            
            op->tv[1].u = 0.375f;
            op->tv[1].v = 0.3125f;
            
            op->tv[2].u = 0.1875f;
            op->tv[2].v = 0.5f;
            
            op->tv[3].u = 0.375f;
            op->tv[3].v = 0.5f; 
            break;
        default:
            op->tex_id = 43;
            
            x = 0.5f * (op->flr_no % 2);
            y = 0.5f * (op->flr_no / 2);
            
            op->tv[0].u = x;
            op->tv[0].v = y;
            
            op->tv[1].u = 0.5f + x;
            op->tv[1].v = y;
            
            op->tv[2].u = x;
            op->tv[2].v = 0.5f + y;
            
            op->tv[3].u = 0.5f + x;
            op->tv[3].v = 0.5f + y;
            break;
        }
        
        op->tv[0].x = -1.0f;
        op->tv[0].y = 0;
        op->tv[0].z = -1.0f;
        
        op->tv[1].x = 1.0f;
        op->tv[1].y = 0;
        op->tv[1].z = -1.0f;
        
        op->tv[2].x = -1.0f;
        op->tv[2].y = 0;
        op->tv[2].z = 1.0f;
        
        op->tv[3].x = 1.0f;
        op->tv[3].y = 0;
        op->tv[3].z = 1.0f;
        
        op->xn = 0.1f * op->sx;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ct1 = 192;
        
        op->mode0 = 1;
		break;
    }
    
    if (op->type == 0) 
    {
        op->ct1 -= 4;
        
        if (op->ct1 <= 0)
        {
            op->flg = 0;
            return;
        }
        
        op->sx += op->xn;
        op->sz += op->xn;
    }
    else
    {
        op->ay += (int)(182.04445f * op->sy) & 0xFFFF;
        
        op->ct1 = 160.0f * njSin(op->ct0);
        op->ct0 = (op->ct0 + 512) & 0x7FFF;
        
        if (op->ct0 == 0)
        {
            op->flg = 0;
            return;
        }
    }
    
    switch (op->mdlver) 
    {                             
    case 0:
        argb = (op->ct1 << 24) | 0xC8B440;
        break;
    case 1:
        argb = (op->ct1 << 24) | 0xFFFFFF;
        break;
    }
    
    op->tv[0].col = argb;
    op->tv[1].col = argb;
    op->tv[2].col = argb;
    op->tv[3].col = argb;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff129()
{

}

// 99.70% matching
void bhEff130(O_WRK* op) 
{
    LGT_WORK* lgp;    
    NJS_LINE lp;     
    NJS_POINT3 ps;  
    NJS_VECTOR vc;    
    GA_WORK gat;     
    float len;       
    int i;          
    NJS_VECTOR vc0, vc1;  

    switch (op->mode0)
    {                      
    case 0:                                         
        op->tex_id = 3;
        
        op->tv[0].col = -1;
        op->tv[1].col = -1;
        op->tv[2].col = -1;
        op->tv[3].col = -1;
        
        op->tv[0].u = 0.171875f;
        op->tv[0].v = 0.25f;
        
        op->tv[1].u = 0.265625f;
        op->tv[1].v = 0.25f;
        
        op->tv[2].u = 0.171875f;
        op->tv[2].v = 0.34375f;
        
        op->tv[3].u = 0.265625f;
        op->tv[3].v = 0.34375f;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->gpx = op->px;
        op->gpy = op->py;
        op->gpz = op->pz;
        
        op->ani_ct = 0;
        
        switch (op->type) 
        {                          
        case 0:                                     
            op->ct3 = 15;
            break;
        case 1:                                     
        case 2:                                     
        case 3:                                     
            op->ct3 = 20;
            break;
        case 4:                                     
            op->tex_id = 10;
            
            op->ani_ct = 2;
            
            op->ct3 = 100;
            break;
        case 6:                                     
            op->tex_id = 10;
            
            op->ani_ct = 0;
            
            op->ct3 = 100;
            break;
        }
        
        op->ct1 = op->ct2 = -1;
        
        op->mode0 = 1;
    case 1:                                         
        op->px += op->lox;
        op->py += op->loy;
        op->pz += op->loz;
        
        if (op->type < 4) 
        {
            op->loy -= 0.02f;
        }
        
        lp.px = op->pxb;
        lp.py = op->pyb;
        lp.pz = op->pzb;
        
        lp.vx = op->px - lp.px;
        lp.vy = op->py - lp.py;
        lp.vz = op->pz - lp.pz;
        
        if (bhCheckL2Wall(&lp, 0x400, &len) != 0) 
        {
            if (op->type == 4) 
            {
                sys->ef_flg &= ~0x2;
            }
            
            njUnitVector((NJS_VECTOR*)&lp.vx);
            
            op->px = sys->apos.x - (3.0f * lp.vx);
            op->py = sys->apos.y - (3.0f * lp.vy);
            op->pz = sys->apos.z - (3.0f * lp.vz);
            
            op->ct1 = sys->ahtp->type;
            
            op->mode0 = 2;
            break;
        }
        
        op->ct3--;
        
        if ((sys->cb_flg & 0x4))
        {
            sys->ef_flg &= ~0x2;
            op->flg      = 0;
            break;
        }
        
        if (op->ct3 <= 0)
        {
            if (op->type == 4) 
            {
                sys->ef_flg &= ~0x2;
                op->flg      = 0;
                break; 
            }
            
            op->mode0 = 2;
            break;
        }
        
        switch (op->type) 
        {                        
        case 0:                                     
        case 1:                                     
        case 2:                                     
        case 3:                                     
            sys->ef.id = 2;
            
            sys->ef.flg  = 0x4100001;
            sys->ef.type = 7;
            
            sys->ef.mdlver = 4;
            
            sys->ef.sx = 2.0f + (-rand() / -2.1474836E9f);
            sys->ef.sy = 2.0f + (-rand() / -2.1474836E9f);
            sys->ef.sz = 0;
            
            sys->ef.px = op->px;
            sys->ef.py = op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.ay = 0;
            sys->ef.ax = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            break;
        case 4:                                     
            if ((op->ct3 & 0x1))
            {
                op->tv[0].u = 0.875f;
                op->tv[0].v = 0;
                
                op->tv[1].u = 1.0f;
                op->tv[1].v = 0;
                
                op->tv[2].u = 0.875f;
                op->tv[2].v = 0.125f;
                
                op->tv[3].u = 1.0f;
                op->tv[3].v = 0.125f;
            }
            else 
            {
                op->tv[0].u = 0.875f;
                op->tv[0].v = 0.125f;
                
                op->tv[1].u = 1.0f;
                op->tv[1].v = 0.125f;
                
                op->tv[2].u = 0.875f;
                op->tv[2].v = 0.25f;
                
                op->tv[3].u = 1.0f;
                op->tv[3].v = 0.25f;
            }
            
            sys->ef.id = 132;
            
            sys->ef.flg  = 0x4100001;
            sys->ef.type = 0;
            
            sys->ef.mdlver = 0;
            
            sys->ef.sx = 4.0f;
            sys->ef.sy = 4.0f;
            sys->ef.sz = 0;
            
            sys->ef.px = op->px;
            sys->ef.py = op->py;
            sys->ef.pz = op->pz;
            
            sys->ef.ay = 0;
            sys->ef.ax = 0;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            
            sys->ef.type = 1;
            
            sys->ef.sx = 1.0f;
            sys->ef.sy = 1.0f;
            
            vc.x = 0;
            vc.y = vc.z = 0.5f;
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, op->ay);
            njRotateX(NULL, op->ax);
            
            for (i = 0; i < 2; i++) 
            {
                njPushMatrixEx();
                
                njRotateZ(NULL, (int)(182.04445f * (360.0f * (-rand() / -2.1474836E9f))) & 0xFFFF);
                
                njCalcPoint(NULL, &vc, &ps);
                
                bhSetEffectTb(&sys->ef, &ps, NULL, 0);
                
                njPopMatrixEx();
            }
            
            break;
        case 6:                                     
            if ((op->ct3 & 0x1)) 
            {
                op->tv[0].u = 0.875f;
                op->tv[0].v = 0;
                
                op->tv[1].u = 1.0f;
                op->tv[1].v = 0;
                
                op->tv[2].u = 0.875f;
                op->tv[2].v = 0.125f;
                
                op->tv[3].u = 1.0f;
                op->tv[3].v = 0.125f;
            } 
            else 
            {
                op->tv[0].u = 0.875f;
                op->tv[0].v = 0.125f;
                
                op->tv[1].u = 1.0f;
                op->tv[1].v = 0.125f;
                
                op->tv[2].u = 0.875f;
                op->tv[2].v = 0.25f;
                
                op->tv[3].u = 1.0f;
                op->tv[3].v = 0.25f;
            }
            
            if ((op->ct3 % 3) != 0)
            {
                sys->ef.id = 132;
                
                sys->ef.flg  = 0x4100001;
                sys->ef.type = 2;
                
                sys->ef.mdlver = 0;
                
                sys->ef.sx = 4.0f + (2.0f * (-rand() / -2.1474836E9f));
                sys->ef.sy = 4.0f + (2.0f * (-rand() / -2.1474836E9f));
                sys->ef.sz = 0;
                
                sys->ef.px = op->px;
                sys->ef.py = op->py;
                sys->ef.pz = op->pz;
                
                sys->ef.ay = 0;
                sys->ef.ax = 0;
                
                vc.x = 0.2f * -op->lox;
                vc.y = 0.2f * -(op->loy + ((0.5f * (-rand() / -2.1474836E9f)) - 0.25f));
                vc.z = 0.2f * -op->loz;
                
                bhSetEffectTb(&sys->ef, &vc, NULL, 0);
            }
            
            break;
        }
        
        gat.px = op->px;
        gat.py = op->py;
        gat.pz = op->pz;
        
        gat.gx = op->gpx;
        gat.gy = op->gpy;
        gat.gz = op->gpz;
        
        gat.vx = 2.0f * lp.vx;
        gat.vy = 2.0f * lp.vy;
        gat.vz = 2.0f * lp.vz;
        
        gat.at_flg = 0;
        
        gat.wpn_no = op->type + 14;
        
        gat.r = WpnTab[gat.wpn_no].r;
        gat.l = WpnTab[gat.wpn_no].l;
        
        gat.rmax = gat.rn = 0;
        
        gat.ax = op->ax;
        gat.ay = op->ay;
        
        if ((op->ct2 = bhCheckFlyAtari(&gat, -1)) != -1) 
        {
            if (op->type == 4) 
            {
                sys->ef_flg &= ~0x2;
            }
            
            ene[op->ct2].flg2 |= 0x4;
            
            op->lox = lp.vx;
            op->loy = lp.vy;
            op->loz = lp.vz;
            
            op->mode0 = 2;
            break;
        }
        
        if (((sys->st_flg & 0x40)) && (bhCheckL2Water(&lp, &ps) != NULL)) 
        {
            if (op->type == 4) 
            {
                sys->ef_flg &= ~0x2;
            }
            
            bhSetEffect(108, (POINT*)&ps, NULL, 12);
            
            sys->ef.id = 15;
            
            sys->ef.flg = 1;
            
            sys->ef.mdlver = 0;
            
            sys->ef.type = 2;
            
            sys->ef.flr_no = 0;
            
            sys->ef.px = (ps.x + ((-rand() / -2.1474836E9f) - 0.5f)) - cam.vx;
            sys->ef.pz = (ps.z + ((-rand() / -2.1474836E9f) - 0.5f)) - cam.vz;
            sys->ef.py = ps.y - 1.0f;
            
            sys->ef.ay = 0;
            
            sys->ef.sx = 4.0f;
            sys->ef.sy = 1.6f + (0.25f * (-rand() / -2.1474836E9f));
            sys->ef.sz = 4.0f;
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            bhSetWaterSplash4((NJS_POINT3*)&sys->ef.px, op->ay, 1, 1.6f, 1.6f, 1.6f);
            
            op->lox = lp.vx;
            op->loy = lp.vy;
            op->loz = lp.vz;
            
            op->stflg |= 0x100000;
            
            op->mode0 = 2;
            break;
        }
        
        sys->ef_trs[sys->ef_trsn++] = op;
        break;
    case 2:                                         
        plp->stflg |= 0x100;
        
        switch (op->type) 
        {                        
        case 0:                                     
            switch (op->mode1) 
            {                    
            case 0:                                 
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 266, 1);
                
                gat.px = op->px;
                gat.py = 2.0f + op->py;
                gat.pz = op->pz;
                
                gat.gx = op->gpx;
                gat.gy = op->gpy;
                gat.gz = op->gpz;
                
                gat.vx = op->lox;
                gat.vy = op->loy;
                gat.vz = op->loz;
                
                gat.at_flg = 0;
                
                gat.wpn_no = op->type + 14;
                
                gat.r = 4.0f * WpnTab[gat.wpn_no].r;
                gat.l = WpnTab[gat.wpn_no].l;
                
                gat.rmax = gat.rn = 0;
                
                gat.ax = op->ax;
                gat.ay = op->ay;
                
                bhCheckFlyAtari(&gat, op->ct2);
                
                sys->ef.id = 19;
                
                sys->ef.flg  = 0x4100001;
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
                
                sys->ef.flg  = 0x4100001;
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
                
                op->mode1++;
                break;
            case 1:                                 
                op->ct0++;
                
                if (op->ct0 > 2)
                {
                    sys->ef.id = 19;
                    
                    sys->ef.flg  = 0x4100001;
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
                    
                    op->mode1++;
                }
                
                break;
            case 2:                                 
                op->flg = 0;
                break;
            }
            
            break;
        case 1:                                     
            switch (op->mode1)
            {                    
            case 0:                                 
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 268, 1);
                
                gat.px = op->px;
                gat.py = 3.0f + op->py;
                gat.pz = op->pz;
                
                gat.gx = op->gpx;
                gat.gy = op->gpy;
                gat.gz = op->gpz;
                
                gat.vx = op->lox;
                gat.vy = op->loy;
                gat.vz = op->loz;
                
                gat.at_flg = 0;
                
                gat.wpn_no = op->type + 14;
                
                gat.r = 6.0f * WpnTab[gat.wpn_no].r;
                gat.l = WpnTab[gat.wpn_no].l;
                
                gat.rmax = gat.rn = 0;
                
                gat.ax = op->ax;
                gat.ay = op->ay;
                
                bhCheckFlyAtari(&gat, op->ct2);
                
                sys->ef.id = 19;
                
                sys->ef.flg  = 0x4100001;
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
                
                sys->ef.id = 2;
                
                sys->ef.flg  = 0x4100001;
                sys->ef.type = 8;
                
                sys->ef.flr_no = 0;
                
                sys->ef.mdlver = 3;
                
                sys->ef.sx = 8.0f;
                sys->ef.sy = 8.0f;
                sys->ef.sz = 8.0f;
                
                sys->ef.ay = 0;
                sys->ef.ax = 0;
                
                sys->ef.px = op->px;
                sys->ef.py = op->py;
                sys->ef.pz = op->pz;
                
                vc.x = op->lox;
                vc.y = 0.5f;
                vc.z = op->loz;
                
                njUnitVector(&vc);
                njUnitMatrix(NULL);
                
                for (i = 0; i < 4; i++) 
                {
                    njRotateY(NULL, (int)(182.04445f * (i * 90)) & 0xFFFF);
                    
                    njCalcVector(NULL, &vc, &ps); 
                    
                    ps.x *= 0.25f;
                    ps.z *= 0.25f;
                    
                    bhSetEffectTb(&sys->ef, &ps, NULL, 0);
                } 
                
                op->ct0 = 0;
                
                op->mode1++;
                break;
            case 1:                                 
                op->ct0++;
                
                if (op->ct0 > 2)
                {
                    sys->ef.id = 19;
                    
                    sys->ef.flg  = 0x4100001;
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
                    
                    op->mode1++;
                }
                
                break;
            case 2:                                 
                op->flg = 0;
                break;
            }
            
            break;
        case 2:                                     
            switch (op->mode1)
            {                    
            case 0:                                 
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 267, 1);
                
                gat.px = op->px;
                gat.py = 2.0f + op->py;
                gat.pz = op->pz;
                
                gat.gx = op->gpx;
                gat.gy = op->gpy;
                gat.gz = op->gpz;
                
                gat.vx = op->lox;
                gat.vy = op->loy;
                gat.vz = op->loz;
                
                gat.at_flg = 0;
                
                gat.wpn_no = op->type + 14;
                
                gat.r = 4.0f * WpnTab[gat.wpn_no].r;
                gat.l = WpnTab[gat.wpn_no].l;
                
                gat.rmax = gat.rn = 0;
                
                gat.ax = op->ax;
                gat.ay = op->ay;
                
                bhCheckFlyAtari(&gat, op->ct2);
                
                op->ct0 = 0;
                
                op->mode1++;
            case 1:                                 
                sys->ef.id = 18;
                
                sys->ef.flg = 0x4100001;
                
                if (!(op->stflg & 0x100000)) 
                {
                    sys->ef.type = 10;
                }
                else 
                {
                    sys->ef.type = 11;
                }
                
                sys->ef.px = op->px;
                sys->ef.py = op->py - 2.5f;
                sys->ef.pz = op->pz;
                
                sys->ef.ay = 0;
                sys->ef.ax = 0;
                
                sys->ef.sz = 0;
                
                vc.x = op->lox;
                vc.y = 0;
                vc.z = op->loz;
                
                njUnitVector(&vc);
                
                op->lox = 0.5f * vc.x;
                op->loy = 0;
                op->loz = 0.5f * vc.z;
                
                for (i = 0; i < 20; i++) 
                {
                    njUnitMatrix(NULL);
                    
                    njRotateY(NULL, (int)(182.04445f * ((i - 12) * 3)) & 0xFFFF);
                    
                    njCalcVector(NULL, &vc, &ps);
                    
                    sys->ef.sx = 2.0f + (3.0f * (-rand() / -2.1474836E9f));
                    sys->ef.sy = 2.0f + (3.0f * (-rand() / -2.1474836E9f));
                    
                    switch (op->ct1) 
                    {              
                    case -1:                        
                        ps.x = (-rand() / -2.1474836E9f) - 0.5f;
                        ps.z = (-rand() / -2.1474836E9f) - 0.5f;
                        break;
                    case 7:                         
                        len = 0.3f + (0.7f * (-rand() / -2.1474836E9f));
                        
                        ps.x *= len;
                        ps.z *= len;
                        break;
                    default:                        
                        len = -(0.1f + (0.5f * (-rand() / -2.1474836E9f)));
                        
                        ps.x *= len;
                        ps.z *= len; 
                        break;
                    }
                    
                    sys->ef.flr_no = i & 7;
					
                    sys->ef.mdlver = i & 3;
                    
                    bhSetEffectTb(&sys->ef, (NJS_POINT3*)&ps, NULL, 0);
                } 
                
                op->ct0 = 0;
                
                op->spd = 1.0f;
                
                op->mode1++;
                break;
            case 2:                                 
                if ((op->ct0 < 50) && (op->ct1 == 7))
                {
                    op->px += op->lox;
                    op->pz += op->loz;
                    
                    op->lox *= 0.9f;
                    op->loz *= 0.9f;
                    
                    gat.px = op->px;
                    gat.py = 2.0f + op->py;
                    gat.pz = op->pz;
                    
                    if (bhCheckWallType((NJS_POINT3*)&gat.px, 0x400, 1.0f, 1.0f) != NULL) 
                    {
                        op->flg = 0;
                        break;
                    }
                    
                    gat.gx = op->gpx;
                    gat.gy = op->gpy;
                    gat.gz = op->gpz;
                    
                    gat.vx = op->lox;
                    gat.vy = op->loy;
                    gat.vz = op->loz;
                    
                    gat.at_flg = 0x80;
                    
                    gat.wpn_no = op->type + 14;
                    
                    gat.r = op->spd;
                    gat.l = 0;
                    
                    gat.rmax = gat.rn = 0;
                    
                    gat.ax = op->ax;
                    gat.ay = op->ay;
                    
                    bhCheckFlyAtari(&gat, -1);
                    
                    if (op->spd < 4.0f) 
                    {
                        op->spd += 0.5f;
                    }
                }
                else 
                {
                    op->flg = 0;
                }
                
                op->ct0++;
            }
            
            break;
        case 3:                                     
            switch (op->mode1) 
            {                    
            case 0:                                 
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 280, 1);
                
                sys->ef.id = 19;
                
                sys->ef.flg  = 0x4100001;
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
                
                op->ct0 = 0;
                
                op->pv[0].x = 0;
                op->pv[0].y = 0;
                op->pv[0].z = 1.2195f;
                
                op->pv[1].x = 640.0f;
                op->pv[1].y = 0;
                op->pv[1].z = 1.2195f;
                
                op->pv[2].x = 0;
                op->pv[2].y = 480.0f;
                op->pv[2].z = 1.2195f;
                
                op->pv[3].x = 640.0f;
                op->pv[3].y = 480.0f;
                op->pv[3].z = 1.2195f;
                
                op->bl_src = 8;
                op->bl_dst = 6;
                
                op->mode1++;
                break;
            case 1:                                 
                if (op->ct0 == 2) 
                {
                    sys->ef.id = 19;
                    
                    sys->ef.flg  = 0x4100001;
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
                }
                
                if (op->ct0 < 8) 
                {
                    vc0.x = vc0.y = 0;
                    vc0.z = -1.0f;
                    
                    sys->ef.id = 131;
                    
                    sys->ef.flg  = 0x4100001;
                    sys->ef.type = 0;
                    
                    sys->ef.mdlver = 0;
                    
                    sys->ef.px = op->px;
                    sys->ef.py = op->py;
                    sys->ef.pz = op->pz;
                    
                    for (i = 0; i < 4; i++)  
                    {
                        sys->ef.sx = 3.0f + (-rand() / -2.1474836E9f);
                        sys->ef.sy = 3.0f + (-rand() / -2.1474836E9f);
                        sys->ef.sz = 3.0f;
                        
                        sys->ef.ay = 182.04445f * (360.0f * (-rand() / -2.1474836E9f));
                        sys->ef.ax = 182.04445f * (90.0f  * (-rand() / -2.1474836E9f));
                        
                        njUnitMatrix(NULL);
                        
                        njRotateXYZ(NULL, sys->ef.ax, sys->ef.ay, 0);
                        
                        njCalcVector(NULL, &vc0, &vc1);
                        
                        vc1.x *= 0.5f + (-rand() / -2.1474836E9f);
                        vc1.y *= 0.5f + (-rand() / -2.1474836E9f);
                        vc1.z *= 0.5f + (-rand() / -2.1474836E9f);
                        
                        bhSetEffectTb(&sys->ef, &vc1, NULL, 0);
                    } 
                }
                
                if (op->ct0 > 7) 
                {
                    op->pv[3].col = op->pv[2].col = op->pv[1].col = op->pv[0].col = ((int)(64.0f * njSin((op->ct0 - 8) << 10)) << 24) | 0x10C040;
                    
                    sys->ef_ntx2d[sys->ef_ntx2dn++] = op;
                }
                
                op->ct0++;
                
                if (op->ct0 > 24) 
                {
                    bhSetBowDamage();
                    
                    op->ct0 = 32;
                    
                    op->mode1++;
                }
                
                break;
            case 2:                                 
                op->ct0--;
                
                if (op->ct0 > 0)
                {
                    op->pv[3].col = op->pv[2].col = op->pv[1].col = op->pv[0].col = ((int)(64.0f * njSin(op->ct0 << 9)) << 24) | 0x10C040;
                    
                    sys->ef_ntx2d[sys->ef_ntx2dn++] = op;
                    break;
                }
                
                op->flg = 0;
            }
            
            break;
        case 4:                                     
            switch (op->mode1) 
            {                    
            case 0:                   
            {
                NJS_VECTOR vc0, vc1; 
                
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 282, 1);
                
                gat.px = op->px;
                gat.py = 2.0f + op->py;
                gat.pz = op->pz;
                
                gat.gx = op->gpx;
                gat.gy = op->gpy;
                gat.gz = op->gpz;
                
                gat.vx = op->lox;
                gat.vy = op->loy;
                gat.vz = op->loz;
                
                gat.at_flg = 0;
                
                gat.wpn_no = op->type + 14;
                
                gat.r = 10.0f;
                gat.l = 0;
                
                gat.rmax = gat.rn = 0;
                
                gat.ax = op->ax;
                gat.ay = op->ay;
                
                bhCheckFlyAtari(&gat, op->ct2);
                
                sys->ef.id = 23;
                
                sys->ef.flg  = 1;
                sys->ef.type = 0;
                
                sys->ef.mdlver = 1;
                
                sys->ef.flr_no = 1;
                
                sys->ef.sx = 4.0f;
                sys->ef.sy = 4.0f;
                sys->ef.sz = 4.0f;
                
                sys->ef.px = op->px - cam.vx;
                sys->ef.py = op->py - cam.vy;
                sys->ef.pz = op->pz - cam.vz;
                
                sys->ef.ay = 0;
                sys->ef.ax = 0;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
                
                op->ct0 = 0;
                
                for (i = 0; i < 5; i++) 
                {
                    vc0.x = vc0.y = 0;
                    vc0.z = 1.0f;
                    
                    sys->ef.id = 22;
                    
                    sys->ef.flg  = 1;
                    sys->ef.type = 0;
                    
                    sys->ef.mdlver = 1;
                    
                    sys->ef.flr_no = 1;
                    
                    sys->ef.sx = 2.0f + (-rand() / -2.1474836E9f);
                    sys->ef.sy = sys->ef.sx;
                    sys->ef.sz = 0;
                    
                    sys->ef.ay = op->ay + ((int)(182.04445f * ((160.0f * (-rand() / -2.1474836E9f)) - 80.0f)) & 0xFFFF);
                    sys->ef.ax = op->ax + ((int)(182.04445f * ((120.0f * (-rand() / -2.1474836E9f)) - 60.0f)) & 0xFFFF);
                    
                    njUnitMatrix(NULL);
                    
                    njRotateXYZ(NULL, sys->ef.ax, sys->ef.ay, 0);
                    
                    njCalcVector(NULL, &vc0, &vc1);
                    
                    bhSetEffectTb(&sys->ef, &vc1, NULL, 0); 
                }  
                
                op->mode1++;
                break;
            }
            case 1:                                 
                op->flg = 0;
                break;
            }
            
            break;
        case 6:                                     
            switch (op->mode1) 
            {                
            case 0:                                 
                CallPlayerWeaponSeEx((NJS_POINT3*)&op->px, 279, 1);
                
                gat.px = op->px;
                gat.py = op->py;
                gat.pz = op->pz;
                
                gat.gx = op->gpx;
                gat.gy = op->gpy;
                gat.gz = op->gpz;
                
                gat.vx = op->lox;
                gat.vy = op->loy;
                gat.vz = op->loz;
                
                gat.at_flg = 0;
                
                gat.wpn_no = 20;
                
                gat.r = 10.0f;
                gat.l = 0;
                
                gat.rmax = gat.rn = 0;
                
                gat.ax = op->ax;
                gat.ay = op->ay;
                
                bhCheckFlyAtari(&gat, op->ct2);
                
                ps.x = op->px - op->lox;
                ps.y = op->py - op->loy;
                ps.z = op->pz - op->loz;
                
                bhSetExplosionEffectEx(&ps, 4.0f);
                
                op->mode1++;
                
                lgp = rom->lgtp;
                
                lgp->flg  = 3;
                lgp->type = 101;
                
                lgp->aspd = 8;
                
                lgp->lkflg = 0;
                lgp->lkno  = 0;
                lgp->lkono = 0;
                
                lgp->mode = 0;
                
                lgp->lsrc = 4;
                
                lgp->r = 4.5f;
                lgp->g = 3.0f;
                lgp->b = 1.5f;
                
                lgp->nr = 20.0f;
                lgp->fr = 100.0f;
                
                lgp->px = ps.x;
                lgp->py = ps.y;
                lgp->pz = ps.z;
                
                lgp->lx = 0;
                lgp->ly = 0;
                lgp->lz = 0;
                
                lgp->ct0 = 0;
                
                lgp->light = NULL;
                break;
            case 1:
                op->flg = 0;
                break;
            }
        }
        
        break;
    }
}

// 100% matching!
void bhEff131(O_WRK* op) 
{
    UV_WORK* uvp;
	static UV_WORK uvinfo_p0[14] = 
    {
        { 0.0625f,  0.0f,     0.0625f,  0.0625f  },
        { 0.0625f,  0.0625f,  0.0625f,  0.0625f  },
        { 0.25f,    0.0f,     0.125f,   0.125f   },
        { 0.5f,     0.0f,     0.125f,   0.125f   },
        { 0.75f,    0.0f,     0.125f,   0.125f   },
        { 0.0f,     0.125f,   0.1875f,  0.1875f  },
        { 0.375f,   0.125f,   0.1875f,  0.1875f  },
        { 0.1875f,  0.3125f,  0.1875f,  0.1875f  },
        { 0.0f,     0.5f,     0.1875f,  0.1875f  },
        { 0.375f,   0.5f,     0.1875f,  0.1875f  },
        { 0.5625f,  0.125f,   0.21875f, 0.21875f },
        { 0.78125f, 0.125f,   0.21875f, 0.21875f },
        { 0.5625f,  0.34375f, 0.21875f, 0.21875f },
        { -1.0f,    0.0f,     0.0f,     0.0f     }
    };

    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4100000;
        
        op->tex_id = 2;
        
        op->tv[0].col = 0x8010C040;
        op->tv[1].col = 0x8010C040;
        op->tv[2].col = 0x8010C040;
        op->tv[3].col = 0x8010C040;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->exp0 = (unsigned char*)uvinfo_p0;
        
        op->mode0 = 1;
        break;
    }
    
    op->px += op->lox;
    op->py += op->loy;
    op->pz += op->loz;
    
    op->lox *= 0.9f;
    op->loy *= 0.9f;
    op->loz *= 0.9f;
    
    uvp = (UV_WORK*)op->exp0 + op->ct0;
    
    if (uvp->u == -1.0f)
    {
        op->flg = 0;
        return;
    }
    
    op->sx = 4.0f * (op->sxb * uvp->xs);
    op->sy = 4.0f * (op->syb * uvp->ys);
    
    op->tv[0].u = uvp->u;
    op->tv[0].v = uvp->v;
    
    op->tv[1].u = uvp->u + uvp->xs;
    op->tv[1].v = uvp->v;
    
    op->tv[2].u = uvp->u;
    op->tv[2].v = uvp->v + uvp->ys;
    
    op->tv[3].u = uvp->u + uvp->xs;
    op->tv[3].v = uvp->v + uvp->ys;
    
    op->ct0++;
    
    sys->ef_trs[sys->ef_trsn++] = op;
}

// 100% matching!
void bhEff132(O_WRK* op)
{
    int i;
	UV_WORK* uvp;
	static UV_WORK uvinfo_p0[8] = 
    {
        { 0.1875f, 0.125f,  0.1875f, 0.1875f },
        { 0.875f,  0.0f,    0.125f,  0.125f  },
        { 0.625f,  0.0f,    0.125f,  0.125f  },
        { 0.375f,  0.0f,    0.125f,  0.125f  },
        { 0.125f,  0.0f,    0.125f,  0.125f  },
        { 0.0625f, 0.0625f, 0.0625f, 0.0625f },
        { 0.0f,    0.0625f, 0.0625f, 0.0625f },
        { -1.0f,   0.0f,    0.0f,    0.0f    }
    };
    static UV_WORK uvinfo_p1[9] = 
    {
        { 0.0f,   0.875f, 0.125f, 0.125f },
        { 0.125f, 0.875f, 0.125f, 0.125f },
        { 0.25f,  0.875f, 0.125f, 0.125f },
        { 0.375f, 0.875f, 0.125f, 0.125f },
        { 0.5f,   0.875f, 0.125f, 0.125f },
        { 0.625f, 0.875f, 0.125f, 0.125f },
        { 0.75f,  0.875f, 0.125f, 0.125f },
        { 0.875f, 0.875f, 0.125f, 0.125f },
        { -1.0f,  0.0f,   0.0f,   0.0f   }
    };
    static UV_WORK uvinfo_p2[12] = 
    {
        { 0.0625f,  0.0625f, 0.0625f,  0.0625f  },
        { 0.25f,    0.0f,    0.125f,   0.125f   },
        { 0.5f,     0.0f,    0.125f,   0.125f   },
        { 0.75f,    0.0f,    0.125f,   0.125f   },
        { 0.0f,     0.125f,  0.1875f,  0.1875f  },
        { 0.375f,   0.125f,  0.1875f,  0.1875f  },
        { 0.1875f,  0.3125f, 0.1875f,  0.1875f  },
        { 0.0f,     0.5f,    0.1875f,  0.1875f  },
        { 0.375f,   0.5f,    0.1875f,  0.1875f  },
        { 0.5625f,  0.125f,  0.21875f, 0.21875f },
        { 0.78125f, 0.125f,  0.21875f, 0.21875f },
        { -1.0f,    0.0f,    0.0f,     0.0f     }
    };
    static UV_WORK uvinfo_p3[9] = 
    {
        { 0.59375f, 0.875f, 0.09375f, 0.09375f },
        { 0.59375f, 0.875f, 0.09375f, 0.09375f },
        { 0.59375f, 0.875f, 0.09375f, 0.09375f },
        { 0.5f,     0.875f, 0.09375f, 0.09375f },
        { 0.40625f, 0.875f, 0.09375f, 0.09375f },
        { 0.3125f,  0.875f, 0.09375f, 0.09375f },
        { 0.21875f, 0.875f, 0.09375f, 0.09375f },
        { 0.125f,   0.875f, 0.09375f, 0.09375f },
        { -1.0f,    0.0f,   0.0f,     0.0f     }
    };
    static short apat_p3[9] = 
    {
        208, 208, 208, 208, 192, 176, 160, 144, 0
    };
    
    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4100000;
        
        switch (op->type) 
        {                          
        case 0:                                     
            op->tex_id = 2;
            
            op->ani_ct = 0;
            
            op->bl_src = 8;
            op->bl_dst = 10;
            
            op->exp0 = (unsigned char*)uvinfo_p0;
            
            op->tv[0].col = 0xFF20E0FF;
            op->tv[1].col = 0xFF20E0FF;
            op->tv[2].col = 0xFF20E0FF;
            op->tv[3].col = 0xFF20E0FF;
            break;
        case 1:                                     
            op->tex_id = 10;
            
            op->ani_ct = 2;
            
            op->bl_src = 8;
            op->bl_dst = 10;
            
            op->exp0 = (unsigned char*)uvinfo_p1;
            
            op->tv[0].u = 0.875f;
            op->tv[0].v = 0.25f;
            
            op->tv[1].u = 1.0f;
            op->tv[1].v = 0.25f;
            
            op->tv[2].u = 0.875f;
            op->tv[2].v = 0.375f;
            
            op->tv[3].u = 1.0f;
            op->tv[3].v = 0.375f;
            
            op->tv[0].col = -1;
            op->tv[1].col = -1;
            op->tv[2].col = -1;
            op->tv[3].col = -1;
            break;
        case 2:                                     
            op->tex_id = 2;
            
            op->ani_ct = 1;
            
            op->bl_src = 9;
            op->bl_dst = 10;
            
            op->exp0 = (unsigned char*)uvinfo_p2;
            
            op->ct3 = 192;
            break;
        case 3:                                     
            op->tex_id = 19;
            
            op->ani_ct = 0;
            
            op->bl_src = 9;
            op->bl_dst = 10;
            
            op->gpx = op->px;
            op->gpy = op->py;
            op->gpz = op->pz;
            
            op->xn = op->lox;
            op->yn = op->loy;
            op->zn = op->loz;
            
            op->spd = 0.9f;
            
            op->exp0 = (unsigned char*)uvinfo_p3;
            break;
        }
        
        op->mode0 = 1;
        break;
    }
    
    switch (op->type) 
    {                            
    case 0:                                        
        uvp = (UV_WORK*)op->exp0 + op->ct0;
        
        if (uvp->u == -1.0f)
        {
            op->flg = 0;
            return;
        }
        
        op->sx = 4.0f * (op->sxb * uvp->xs);
        op->sy = 4.0f * (op->syb * uvp->ys);
        
        op->tv[0].u = uvp->u;
        op->tv[0].v = uvp->v;
        
        op->tv[1].u = uvp->u + uvp->xs;
        op->tv[1].v = uvp->v;
        
        op->tv[2].u = uvp->u;
        op->tv[2].v = uvp->v + uvp->ys;
        
        op->tv[3].u = uvp->u + uvp->xs;
        op->tv[3].v = uvp->v + uvp->ys;
        
        op->ct0++;
        break;
    case 1:                                        
        op->px += op->lox;
        op->py += op->loy;
        op->pz += op->loz;
        
        op->lox *= 0.8f;
        op->loy *= 0.8f;
        op->loz *= 0.8f;
        
        op->sx *= 0.8f;
        op->sy *= 0.8f;
        
        if (op->sx < 0.1f) 
        {
            op->flg = 0;
            return;
        }
        
        break;
    case 2:                                        
        i = (op->ct3 << 24) | 0xFFFFFF;
        
        op->tv[0].col = i;
        op->tv[1].col = i;
        op->tv[2].col = i;
        op->tv[3].col = i;
        
        op->ct3 -= 14;
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->xn += op->lox;
        op->yn += op->loy;
        op->zn += op->loz;
        
        uvp = (UV_WORK*)op->exp0 + op->ct0;
        
        if (uvp->u == -1.0f) 
        {
            op->flg = 0;
            return;
        }
        
        op->sx = 4.0f * (op->sxb * uvp->xs);
        op->sy = 4.0f * (op->syb * uvp->ys);
        
        op->tv[0].u = uvp->u;
        op->tv[0].v = uvp->v;
        
        op->tv[1].u = uvp->u + uvp->xs;
        op->tv[1].v = uvp->v;
        
        op->tv[2].u = uvp->u;
        op->tv[2].v = uvp->v + uvp->ys;
        
        op->tv[3].u = uvp->u + uvp->xs;
        op->tv[3].v = uvp->v + uvp->ys;
        
        op->ct0++;
        break;
    case 3:                                        
        if (((op->ct0 > 0) && (op->ct0 < 3)) && (op->mdlver == 0)) 
        {
            sys->ef.id   = 132;
            sys->ef.type = 3;
            
            sys->ef.flr_no = 0;
            
            sys->ef.mdlver = 1;
            
            sys->ef.ax = 0;
            sys->ef.ay = 0;
            
            sys->ef.flg = 0x4100001;
            
            sys->ef.sx = op->sxb * op->spd;
            sys->ef.sy = op->syb * op->spd;
            sys->ef.sz = 1.0f;
            
            sys->ef.px = op->gpx;
            sys->ef.py = op->gpy;
            sys->ef.pz = op->gpz;
            
            bhSetEffectTb(&sys->ef, (NJS_POINT3*)&op->xn, NULL, 0);
            
            op->spd -= 0.1f;
        }
        
        i = (apat_p3[op->ct0] << 24) | 0xFFFFFF;
        
        op->tv[0].col = i;
        op->tv[1].col = i;
        op->tv[2].col = i;
        op->tv[3].col = i;
        
        op->px += op->lox;
        op->py += op->loy;
        op->pz += op->loz;
        
        op->lox *= 0.6f;
        op->loy *= 0.6f;
        op->loz *= 0.6f;
        
        uvp = (UV_WORK*)op->exp0 + op->ct0;
        
        if (uvp->u == -1.0f)
        {
            op->flg = 0;
            return;
        }
        
        op->sx = 4.0f * (op->sxb * uvp->xs);
        op->sy = 4.0f * (op->syb * uvp->ys);
        
        op->sxb *= 1.1f;
        op->syb *= 1.1f;
        
        op->tv[0].u = uvp->u;
        op->tv[0].v = uvp->v;
        
        op->tv[1].u = uvp->u + uvp->xs;
        op->tv[1].v = uvp->v;
        
        op->tv[2].u = uvp->u;
        op->tv[2].v = uvp->v + uvp->ys;
        
        op->tv[3].u = uvp->u + uvp->xs;
        op->tv[3].v = uvp->v + uvp->ys;
        
        op->ct0++;
        break;
    }

    sys->ef_trs[sys->ef_trsn++] = op;
}
