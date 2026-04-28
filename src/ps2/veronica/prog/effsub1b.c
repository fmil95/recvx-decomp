#include "../../../ps2/veronica/prog/effsub1b.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/screen.h"
#include "../../../ps2/veronica/prog/sdfunc.h"

/*_anon4* sys;
void(*bhDraw134)(O_WRK*);
O_WRK eff[0];
O_WRK* ef_Zanzo[6];
_anon41 cam;
void(*bhDraw136)(O_WRK*);
void(*bhDraw137)(O_WRK*);
_anon7* rom;
void(*bhDraw138)(O_WRK*);*/

// 100% matching!
void bhEff133(O_WRK* op)
{
	static char lmt[3][2] = 
    {
        { 1, 5 },
        { 0, 9 },
        { 0, 9 }
    };

    op->flg |= 0x1000000;
    
    if ((op->mode1 != 0) || ((sys->st_flg & 0x40000000))) 
    {
        sys->st_flg |= 0x40000000;
        
        switch (op->mode0)
        {
        case 0:
            op->ct3 = sys->sp_flg;
            
            sys->sp_flg &= ~0x3;
            
            sys->ond_tnm = sys->ef_tn[42];
            
            op->mode0 = 1;
        case 1:
            sys->ond_ud = 0;
            
            if (sys->ond_cx < 3)
            {
                if (((sys->pad_ps & 0x1)) && (sys->ond_n[sys->ond_cx] < lmt[sys->ond_cx][1])) 
                {
                    sys->ond_n[sys->ond_cx]++;
                    sys->ond_ud = 1;
                    
                    CallSystemSe(0, 2);
                }
                
                if (((sys->pad_ps & 0x2)) && (sys->ond_n[sys->ond_cx] > lmt[sys->ond_cx][0]))
                {
                    sys->ond_n[sys->ond_cx]--;
                    sys->ond_ud = -1;
                    
                    CallSystemSe(0, 2);
                }
            }
            
            if (((sys->pad_ps & 0x4)) && (sys->ond_cx > 0))
            {
                sys->ond_cx--;
                
                CallSystemSe(0, 2);
            }
            
            if (((sys->pad_ps & 0x8)) && (sys->ond_cx < 3))
            {
                sys->ond_cx++;
            
                CallSystemSe(0, 2);
            }
            
            if (((sys->pad_ps & 0x800)) && (sys->ond_cx == 3)) 
            {
                op->mode0 = 2;
                
                CallSystemSe(0, 3);
            }
            
            break;
        case 2:
            if ((sys->ond_n[0] == 1) && (sys->ond_n[1] == 2) && (sys->ond_n[2] == 8))
            {
                bhStFlg(sys->ev_flg, 58);
            }
            
            sys->sp_flg = op->ct3;
            sys->st_flg &= ~0x40000000; 
            
            *(int*)&op->mode0 = 0;
        }
    }
}

// 100% matching!
void bhDraw134(O_WRK* op)
{
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4]; 
    NJS_COLOR col[4];
    unsigned int argb; 
    int i; 
    int tmp; // not from DWARF
    static NJS_PRIM ef134tb[8]; // DATA

    njPushMatrixEx();
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njTextureFilterMode(0);
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[44]);
    
    p2c.p = p;
    p2c.col = col;
    p2c.num = 1;
    
    col[3].color = col[2].color = col[1].color = col[0].color = -1;
    
    bhDrawPARAM2D(ef134tb, &p2c, -1.5f);
    
    p2c.tex = NULL;
    
    tmp = (int)op->aoy;
    
    argb = (((int)tmp << 24) | 0xFF0000) | ((int)tmp << 8);
    
    col[2].color = col[1].color = col[0].color = argb;
    
    p[0].x = 320.0f;
    p[0].y = 336.0f;
        
    p[1].x = 304.0f;
    p[1].y = 360.0f;
    
    p[2].x = 336.0f;
    p[2].y = 360.0f;
    
    njDrawPolygon2D(&p2c, 3, -1.4f, 96);
    
    tmp = (int)op->aox;
    
    argb = ((tmp << 24) | 0xFF0000) | (tmp << 8);
    
    col[2].color = col[1].color = col[0].color = argb;
    
    p[0].x = 216.0f;
    p[0].y = 412.0f;
    
    p[1].x = 240.0f;
    p[1].y = 396.0f;
    
    p[2].x = 240.0f;
    p[2].y = 428.0f;
    
    njDrawPolygon2D(&p2c, 3, -1.4f, 96);
    
    if ((sys->sp_flg & 0x8)) 
    {
        if ((op->ct2 & 0x2)) 
        {
            if (op->aspd < 12) 
            {
                op->aspd++;
            }
        }
        
        if ((op->ct2 & 0x8)) 
        {
            if (op->aspd < 24)
            {
                op->aspd++;
            }
        }
    }
    
    for (i = 0; i < 7; i++)
    {
        if ((op->jno[i] > 0) && ((sys->sp_flg & 0x8))) 
        {
            op->jno[i]--;
        }
        
        if ((op->aspd >> 2) == i) 
        {
            op->jno[i] = 17;
        }
        
        argb = (op->jno[i] * 0xF000000) | 0xFFFFFF;
        
        col[3].color = col[2].color = col[1].color = col[0].color = argb;
        
        bhDrawPARAM2D(&ef134tb[i + 1], &p2c, -1.4f);
    }
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();
}

// 100% matching!
void bhEff134(O_WRK* op)
{
	float mm, nn;
    int i;

    op->flg |= 0x1000000;
    
    if (op->mode1 != 0) 
    {
        sys->st_flg |= 0x4;
        
        switch (op->mode0)
        {
        case 0:
            op->ct3 = sys->sp_flg;
            
            sys->sp_flg &= ~0x1;
            
            sys->ufo_md = 0;
            sys->ufo_flg = 0;
            sys->ufo_oidx = op->lkono;
            
            if (bhCkFlg(sys->ev_flg, 59) != 0)
            {
                sys->ufo_pos.x = 13.0f;
                op->px = 13.0f;
                
                sys->ufo_pos.y = -15.0f;
                op->py = -15.0f;
                
                sys->ufo_pos.z = 11.6f;
                op->pz = 11.6f;
            }
            else 
            {
                sys->ufo_pos.x = 47.0f;
                op->px = 47.0f;
                
                sys->ufo_pos.y = -15.0f;
                op->py = -15.0f;
                
                sys->ufo_pos.z = 60.0f;
                op->pz = 60.0f;
            }
            
            sys->gm_flg |= 0x1000;
            sys->gm_flg &= ~0x10000;
            
            sys->fixcno = op->type;
            
            op->func = (void*)bhDraw134;
            
            op->ct0 = 0;
            op->aspd = 0;
            
            for (i = 0; i < 7; i++)
            {
                op->jno[i] = 0;
            }
            
            op->mode0 = 1;
        case 1:
            op->aoy = 64.0f + (190.0f * njSin(op->ct0));
            op->aox = 64.0f;
            
            op->ct0 = (op->ct0 + 2048) & 0x7FFF;
            
            if ((sys->pad_ps & 0x1)) 
            {
                CallSystemSe(0, 0x8000020A);
                
                op->aspd = 4;
                
                op->aoy = 255.0f;
                op->zn = 0.5f;
                
                op->mode0 = 2;
                
                op->ct2 |= 0x2;
            }
            
            break;
        case 2:
            if ((sys->pad_on & 0x1)) 
            {
                op->pz -= 0.2f;
                
                if (op->pz <= 10.0f) 
                {
                    op->pz = 10.0f;
                    
                    op->ct0 = 0;
                    
                    op->zn = 0.5f;
                    
                    op->mode0 = 3;
                    
                    op->ct2 &= ~0x2;
                    
                    CallSystemSe(0, 0x8000020B);
                }
                else 
                {
                    op->ct2 |= 0x2;
                }
            }
            else 
            {
                op->ct0 = 0;
                
                op->zn = 0.5f;
                
                op->mode0 = 3;
                
                op->ct2 &= ~0x2;
                
                CallSystemSe(0, 0x8000020B);
            }
            
            break;
        case 3:
            if ((op->zn != 0) || (op->aspd != 0)) 
            {
                if (op->aspd > 0)
                {
                    op->aspd--;
                }
                
                op->aoy = 64.0f;
                op->aox = 64.0f;
            }
            else 
            {
                op->aox = 64.0f + (190.0f * njSin(op->ct0));
                op->aoy = 64.0f;
                
                op->ct0 = (op->ct0 + 2048) & 0x7FFF;
                
                if ((sys->pad_ps & 0x4)) 
                {
                    op->aspd = 16;
                    
                    op->aox = 255.0f;
                    op->xn = 0.5f;
                    
                    op->mode0 = 4;
                    
                    op->ct2 |= 0x8;
                    
                    CallSystemSe(0, 0x8000020A);
                }
            }
            
            break;
        case 4:
            if ((sys->pad_on & 0x4)) 
            {
                op->px -= 0.2f;
                
                if (op->px <= 13.0f)
                {
                    op->px = 13.0f;
                    
                    op->ct0 = 0;
                    
                    op->xn = 0.5f;
                    
                    op->mode0 = 12;
                    
                    sys->ufo_md = 1;
                    
                    op->ct2 &= ~0x8;
                    
                    CallSystemSe(0, 0x8000020D);
                }
                else 
                {
                    op->ct2 |= 0x8;
                }
            }
            else
            {
                op->ct0 = 0;
                
                op->xn = 0.5f;
                
                op->mode0 = 12;
                
                sys->ufo_md = 1;
                
                op->ct2 &= ~0x8;
                
                CallSystemSe(0, 0x8000020D);
            }
            
            break;
        case 12:
            if (op->aspd > 16)
            {
                op->aspd--;
            }
            else 
            {
                op->aspd = 0;
            }
            
            op->aox = 0;
            op->aoy = 0;
            
            op->ct0++;
            
            if (op->ct0 > 60) 
            {
                sys->ufo_md = 2;
                
                op->yn = 1.0f;
                
                op->mode0 = 13;
                
                CallSystemSe(0, 0x8000020C);
            }
            
            break;
        case 13:
            if (op->py > -44.0f) 
            {
                op->py -= 0.5f;
            }
            
            if ((op->py <= -44.0f) || (sys->ufo_md == 3))
            {
                CallSystemSe(0, 0x8000020B);
                
                mm = fabsf(sys->obwp[op->lkono].px - op->px);
                nn = fabsf(sys->obwp[op->lkono].pz - op->pz);
                
                if ((op->py <= -40.0f) && ((mm <= 3.0f) && (nn <= 8.0f))) 
                {
                    if (nn < 4.0f)
                    {
                        bhStFlg(sys->ev_flg, 59);
                        
                        sys->ufo_flg = 2;
                    }
                    else 
                    {
                        sys->ufo_flg = 1;
                    }  
                } 
                else 
                {
                    sys->ufo_flg = 0;
                }
                
                op->ct0 = 0;
                
                op->yn = 1.0f;
                
                op->mode0 = 14;
            }
            
            break;
        case 14:
            op->ct0++;
            
            if (op->ct0 == 20) 
            {
                if (sys->ufo_flg == 0) 
                {
                    CallSystemSe(0, 0x8000020F);
                }
                else 
                {
                    CallSystemSe(0, 0x8000020E);
                }
                
                sys->ufo_md = 4;
            }
            
            if (op->ct0 > 60) 
            {
                op->ct0 = 0;
                
                sys->ufo_md = 5;
                
                op->mode0 = 15;
                
                CallSystemSe(0, 0x80000210);
            }
            
            break;
        case 15:
            op->ct0++;
            
            if (op->ct0 == 50) 
            {
                bhSetScreenFade(0xFF000000, 30.0f);
            }
            
            if (op->py < 0) 
            {
                op->py += 0.5f;
            }
            
            if (op->ct0 > 80) 
            {
                op->mode0 = 20;
                
                StopSystemSe();
            }
            
            break;
        case 20:
            sys->ufo_md = 0;
            
            if (bhCkFlg(sys->ev_flg, 59) != 0) 
            {
                sys->ufo_pos.x = 13.0f;
                op->px = 13.0f;
                
                sys->ufo_pos.y = -15.0f;
                op->py = -15.0f;
                
                sys->ufo_pos.z = 11.6f;
                op->pz = 11.6f;
            }
            else 
            {
                sys->ufo_pos.x = 47.0f;
                op->px = 47.0f;
                
                sys->ufo_pos.y = -15.0f;
                op->py = -15.0f;
                
                sys->ufo_pos.z = 60.0f;
                op->pz = 60.0f;
                
                sys->obwp[op->lkono].px = sys->obwp[op->lkono].gpx;
                sys->obwp[op->lkono].py = sys->obwp[op->lkono].gpy;
                sys->obwp[op->lkono].pz = sys->obwp[op->lkono].gpz;
            }
            
            bhStandPlayerMotion();
            
            sys->gm_flg |= 0x800;
            
            sys->st_flg &= ~0x1;
            sys->cb_flg &= ~0x44;
            
            sys->sp_flg = op->ct3;
            
            *(int*)&op->mode0 = 0;
            
            sys->st_flg &= ~0x4;
            
            bhSetScreenFade(sys->fade_pbk, 3.0f);
            break;
        }
        
        sys->ufo_pos.x = op->px + (op->xn * (-rand() / (float)(2 << 30)) - (op->xn * 0.5f));
        sys->ufo_pos.y = op->py + (op->yn * (-rand() / (float)(2 << 30)) - (op->yn * 0.5f));
        sys->ufo_pos.z = op->pz + (op->zn * (-rand() / (float)(2 << 30)) - (op->zn * 0.5f));
        
        if (op->xn) 
        {
            op->xn *= 0.8f;
            
            if (op->xn < 0.1f)
            {
                op->xn = 0;
            }
        }
        
        if (op->yn) 
        {
            op->yn *= 0.8f;
            
            if (op->yn < 0.1f)
            {
                op->yn = 0;
            }
        }
        
        if (op->zn) 
        {
            op->zn *= 0.8f;
            
            if (op->zn < 0.1f)
            {
                op->zn = 0;
            }
        }
        
        if ((op->mode0 > 0) && (op->mode0 < 20)) 
        {
            sys->ef_fnc[sys->ef_fncn++] = op;
        }
    }
}

// 
// Start address: 0x23a3a0
void bhEff135(O_WRK* op)
{
	int i;
	BH_PWORK* pp;
	// Line 500, Address: 0x23a3a0, Func Offset: 0
	// Line 503, Address: 0x23a3ac, Func Offset: 0xc
	// Line 505, Address: 0x23a3b4, Func Offset: 0x14
	// Line 503, Address: 0x23a3b8, Func Offset: 0x18
	// Line 505, Address: 0x23a3c0, Func Offset: 0x20
	// Line 506, Address: 0x23a3d8, Func Offset: 0x38
	// Line 511, Address: 0x23a3dc, Func Offset: 0x3c
	// Line 506, Address: 0x23a3e4, Func Offset: 0x44
	// Line 511, Address: 0x23a3e8, Func Offset: 0x48
	// Line 513, Address: 0x23a404, Func Offset: 0x64
	// Line 515, Address: 0x23a424, Func Offset: 0x84
	// Line 517, Address: 0x23a444, Func Offset: 0xa4
	// Line 520, Address: 0x23a460, Func Offset: 0xc0
	// Line 536, Address: 0x23a4ac, Func Offset: 0x10c
	// Line 537, Address: 0x23a4c0, Func Offset: 0x120
	// Line 542, Address: 0x23a4d4, Func Offset: 0x134
	// Line 537, Address: 0x23a4dc, Func Offset: 0x13c
	// Line 542, Address: 0x23a4e8, Func Offset: 0x148
	// Line 543, Address: 0x23a4f4, Func Offset: 0x154
	// Line 542, Address: 0x23a4f8, Func Offset: 0x158
	// Line 543, Address: 0x23a4fc, Func Offset: 0x15c
	// Line 547, Address: 0x23a53c, Func Offset: 0x19c
	// Line 554, Address: 0x23a54c, Func Offset: 0x1ac
	// Line 558, Address: 0x23a57c, Func Offset: 0x1dc
	// Line 557, Address: 0x23a580, Func Offset: 0x1e0
	// Line 560, Address: 0x23a584, Func Offset: 0x1e4
	// Line 562, Address: 0x23a58c, Func Offset: 0x1ec
	// Line 564, Address: 0x23a598, Func Offset: 0x1f8
	// Line 563, Address: 0x23a5a0, Func Offset: 0x200
	// Line 564, Address: 0x23a5a4, Func Offset: 0x204
	// Line 572, Address: 0x23a5a8, Func Offset: 0x208
	// Line 564, Address: 0x23a5ac, Func Offset: 0x20c
	// Line 565, Address: 0x23a5b8, Func Offset: 0x218
	// Line 566, Address: 0x23a5cc, Func Offset: 0x22c
	// Line 567, Address: 0x23a5e4, Func Offset: 0x244
	// Line 568, Address: 0x23a5fc, Func Offset: 0x25c
	// Line 569, Address: 0x23a614, Func Offset: 0x274
	// Line 570, Address: 0x23a62c, Func Offset: 0x28c
	// Line 571, Address: 0x23a644, Func Offset: 0x2a4
	// Line 572, Address: 0x23a65c, Func Offset: 0x2bc
	// Line 574, Address: 0x23a688, Func Offset: 0x2e8
	// Line 576, Address: 0x23a6b8, Func Offset: 0x318
	// Line 577, Address: 0x23a6c4, Func Offset: 0x324
	// Line 581, Address: 0x23a6d8, Func Offset: 0x338
	// Func End, Address: 0x23a6e8, Func Offset: 0x348
	scePrintf("bhEff135 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhDraw136(O_WRK* op)
{
    int* vp;
    BH_PWORK* pwp;

    if (op->flg != 0) 
    {
        njPushMatrixEx();
        
        njControl3D(0x800);
        
        njSetConstantAttr(0, 0xA00);
        
        pwp = (BH_PWORK*)op->lkwkp;
        vp = pwp->mdl[op->mdlver].objP[op->lkono].model->vlist; 
        
        pwp->mdl[op->mdlver].objP[op->lkono].model->vlist = (int*)op->exp0;
        
        njCnkSetSimpleLightColor(1.0f, 1.0f, 1.0f);
        njCnkSetSimpleLightIntensity(1.0f, 0.8f);
        njCnkSetSimpleLight(0, 0.3f, 0.7f);
        
        npSetAllMatAlphaColor(&pwp->mdl[op->mdlver].objP[op->lkono], 1, (op->ct0 + 1) * 40);
        
        njSetMatrix(NULL, cam.mtx);
        
        if (!(pwp->mdl[op->mdlver].objP[op->lkono].evalflags & 0x80000000)) 
        {
            njMultiMatrix(NULL, op->mtx);
        }
        else 
        {
            njTranslate(NULL, op->px, op->py, op->pz);
        }
        
        njSetTexture(pwp->mdl[op->mdlver].texP);
        
        njCnkSimpleDrawModel(pwp->mdl[op->mdlver].objP[op->lkono].model);
        
        pwp->mdl[op->mdlver].objP[op->lkono].model->vlist = vp;
        
        njPopMatrixEx();
    }
}

// 
// Start address: 0x23a950
void bhEff136(O_WRK* op)
{
	int i;
	//_anon12* mlwPb;
	//_anon12* mlwP;
	BH_PWORK* pwp;
	// Line 630, Address: 0x23a950, Func Offset: 0
	// Line 634, Address: 0x23a968, Func Offset: 0x18
	// Line 637, Address: 0x23a97c, Func Offset: 0x2c
	// Line 636, Address: 0x23a980, Func Offset: 0x30
	// Line 638, Address: 0x23a984, Func Offset: 0x34
	// Line 637, Address: 0x23a98c, Func Offset: 0x3c
	// Line 638, Address: 0x23a9a0, Func Offset: 0x50
	// Line 646, Address: 0x23a9bc, Func Offset: 0x6c
	// Line 648, Address: 0x23a9f4, Func Offset: 0xa4
	// Line 651, Address: 0x23aa0c, Func Offset: 0xbc
	// Line 648, Address: 0x23aa10, Func Offset: 0xc0
	// Line 651, Address: 0x23aa18, Func Offset: 0xc8
	// Line 652, Address: 0x23aa4c, Func Offset: 0xfc
	// Line 655, Address: 0x23aa64, Func Offset: 0x114
	// Line 657, Address: 0x23aa70, Func Offset: 0x120
	// Line 656, Address: 0x23aa74, Func Offset: 0x124
	// Line 657, Address: 0x23aa78, Func Offset: 0x128
	// Line 658, Address: 0x23aa90, Func Offset: 0x140
	// Line 659, Address: 0x23aaa0, Func Offset: 0x150
	// Line 660, Address: 0x23aabc, Func Offset: 0x16c
	// Line 661, Address: 0x23aac4, Func Offset: 0x174
	// Line 663, Address: 0x23aae0, Func Offset: 0x190
	// Line 665, Address: 0x23aae4, Func Offset: 0x194
	// Line 666, Address: 0x23ab14, Func Offset: 0x1c4
	// Line 667, Address: 0x23ab20, Func Offset: 0x1d0
	// Line 670, Address: 0x23ab28, Func Offset: 0x1d8
	// Line 672, Address: 0x23ab58, Func Offset: 0x208
	// Line 673, Address: 0x23ab64, Func Offset: 0x214
	// Line 674, Address: 0x23ab6c, Func Offset: 0x21c
	// Line 675, Address: 0x23ab70, Func Offset: 0x220
	// Line 678, Address: 0x23ab78, Func Offset: 0x228
	// Line 684, Address: 0x23ab84, Func Offset: 0x234
	// Line 687, Address: 0x23ab8c, Func Offset: 0x23c
	// Line 694, Address: 0x23ac08, Func Offset: 0x2b8
	// Line 695, Address: 0x23ac3c, Func Offset: 0x2ec
	// Line 698, Address: 0x23ac44, Func Offset: 0x2f4
	// Line 703, Address: 0x23ac58, Func Offset: 0x308
	// Line 704, Address: 0x23ac64, Func Offset: 0x314
	// Func End, Address: 0x23ac80, Func Offset: 0x330
	scePrintf("bhEff136 - UNIMPLEMENTED!\n");
}

// 91.50% matching (matches on GC)
void bhDraw137(O_WRK* op) 
{
    NJS_POINT2COL p2c;        
    NJS_POINT2 p[4];         
    NJS_COLOR col[4], uv[4];         
    float px;                  
    float zom;                
    float xr, yr;                  
    unsigned int argb;        
    int i;                     
    static EF_WORK ef137tb[9]; // DATA

    njPushMatrixEx();
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njTextureFilterMode(0);
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[440]);
    
    p2c.p = p;
    p2c.col = col;
    p2c.tex = uv;
    p2c.num = 1;
    
    col[3].color = col[2].color = col[1].color = col[0].color = 0x90FFFFFF;
    
    uv[0].tex.u = 0;
    uv[0].tex.v = 64;
    
    uv[1].tex.u = uv[0].tex.u + 4;
    uv[1].tex.v = uv[0].tex.v;
    
    uv[2].tex.u = uv[0].tex.u + 4;
    uv[2].tex.v = uv[0].tex.v + 191;
    
    uv[3].tex.u = uv[0].tex.u;
    uv[3].tex.v = uv[0].tex.v + 191;
    
    p[0].x = 0;
    p[0].y = 0;
    
    p[1].x = 640.0f;
    p[1].y = 0;
    
    p[2].x = 640.0f;
    p[2].y = 95.0f;
    
    p[3].x = 0;
    p[3].y = 95.0f;
    
    for (i = 0; i < 5; i++) 
    {
        njDrawPolygon2DM(&p2c, 4, -1.6f, 0x80000060);
        
        p[0].y += 96.0f;
        p[1].y += 96.0f;
        p[2].y += 96.0f;
        p[3].y += 96.0f;
    } 
    
    col[3].color = col[2].color = col[1].color = col[0].color = 0xC0FFFFFF;
    
    bhDrawPARAM2D((NJS_PRIM*)&ef137tb[4], &p2c, -1.5f);
    
    for (i = 5; i < 9; i++) 
    {
        bhDrawPARAM2D((NJS_PRIM*)&ef137tb[i], &p2c, -1.5f);
    } 
    
    for (i = 0; i < 4; i++) 
    {
        if (op->ct3 == i) 
        {
            argb = 0xC0FF0000 | 0x1010;
        }
        else 
        {
            argb = 0x80100000 | 0x1010;
        }
        
        col[3].color = col[2].color = col[1].color = col[0].color = argb;
        
        bhDrawPARAM2D((NJS_PRIM*)&ef137tb[i], &p2c, -1.5f);
    } 
    
    zom = 100.0f - (1.4285715f * ((0.005493164f * cam.pers) - 10.0f));
    
    px = 144.0f;
    
    bhDrawScopeNumber(px, 352.0f, 10);
    px += 16.0f;
    
    bhDrawScopeNumber(px, 352.0f, 11);
    px += 16.0f;
    
    bhDrawScopeNumber(px, 352.0f, 17);
    px += 32.0f;
    
    bhDrawScopeNumber(px, 352.0f, (int)(zom / 100.0f));
    px += 16.0f;
    
    bhDrawScopeNumber(px, 352.0f, (int)(zom / 10.0f) % 10);
    px += 16.0f;
    
    bhDrawScopeNumber(px, 352.0f, (int)zom % 10);
    
    xr = op->xn - 22.0f;
    
    px = 384.0f; 
    
    bhDrawScopeNumber(px, 352.0f, 12);
    px += 16.0f;
    
    bhDrawScopeNumber(px, 352.0f, 13);
    px += 16.0f;
    
    bhDrawScopeNumber(px, 352.0f, 17);
    px += 16.0f;
    
    if (xr < 0)
    {
        bhDrawScopeNumber(px, 352.0f, 15);
        
        xr = -xr;
    }
    
    px += 16.0f;
    
    bhDrawScopeNumber(px, 352.0f, (int)(xr / 100.0f));
    px += 16.0f;
    
    bhDrawScopeNumber(px, 352.0f, (int)(xr / 10.0f) % 10);
    px += 16.0f;
    
    bhDrawScopeNumber(px, 352.0f, (int)xr % 10);
    
    yr = op->yn - 226.0f;
    
    px = 384.0f; 
    
    bhDrawScopeNumber(px, 384.0f, 14);
    px += 16.0f;
    
    bhDrawScopeNumber(px, 384.0f, 13);
    px += 16.0f;
    
    bhDrawScopeNumber(px, 384.0f, 17);
    px += 16.0f;
    
    if (yr < 0) 
    {
        bhDrawScopeNumber(px, 384.0f, 15);
        
        yr = -yr;
    }
    
    px += 16.0f;
    
    bhDrawScopeNumber(px, 384.0f, (int)(yr / 100.0f));
    px += 16.0f;
    
    bhDrawScopeNumber(px, 384.0f, (int)(yr / 10.0f) % 10);
    px += 16.0f;
    
    bhDrawScopeNumber(px, 384.0f, (int)yr % 10);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();
}

// 99.80% matching (matches on GC)
void bhEff137(O_WRK* op) 
{
    op->flg |= 0x1000000;
    
    if (op->mode1 == 0) 
    {
        op->mode0 = 0;
        return;
    }
    
    sys->st_flg |= 0x4;
    
    switch (op->mode0)
    {                              
    case 0:                                         
        cam.flg = 0x40;
        
        bhSetCut(op->type, 1);
        
        sys->cb_flg |= 0x44;
        sys->st_flg |= 0x1;
        
        cam.flg = 0x40;
        
        cam.pers = 14563;
        
        cam.ln = -2.0f;
        
        op->xn = 22.0f;
        op->yn = 226.0f;
        
        cam.ax = cam.axp = (int)(182.04445f * op->xn) & 0xFFFF;
        cam.ay = cam.ayp = (int)(182.04445f * op->yn) & 0xFFFF;
        cam.az = cam.azp = 0;
        
        op->px = cam.px = cam.pxp = 67.5f;
        op->py = cam.py = cam.pyp = 29.3f;
        op->pz = cam.pz = cam.pzp = 6.5f;
        
        op->func = (void*)bhDraw137;
        
        op->ct0 = 0;
        op->ct1 = 0;
        op->ct2 = 0;
        op->ct3 = -1;
        
        op->mode0 = 10;
        break;
    case 1:                                         
        if (op->ct0 != 0) 
        {
            op->ct0--;
            
            if (op->ct0 == 0) 
            {
                op->ct3 = -1;
            }
        }
        
        if ((sys->pad_on & 0xC))
        {
            if (((sys->pad_on & 0x8)) && ((op->ct0 == 0) && (op->yn < 266.0f))) 
            {
                if (op->ct2 == 0) 
                {
                    CallSystemSe(0, 0x80000208);
                }
                
                op->ct0 = 8;
                op->ct2 = 1;
                op->ct3 = 2;
            }
            
            if (((sys->pad_on & 0x4)) && ((op->ct0 == 0) && (op->yn > 186.0f))) 
            {
                if (op->ct2 == 0)
                {
                    CallSystemSe(0, 0x80000208);
                }
                
                op->ct0 = 8;
                op->ct2 = 1;
                op->ct3 = 3;
            }
        } 
        else 
        {
            if (((sys->pad_on & 0x2)) && ((op->ct0 == 0) && (op->xn < 43.0f)))
            {
                if (op->ct2 == 0) 
                {
                    CallSystemSe(0, 0x80000208);
                }
                
                op->ct0 = 6;
                op->ct2 = 1;
                op->ct3 = 1;
            }
            
            if (((sys->pad_on & 0x1)) && ((op->ct0 == 0) && (op->xn > 1.0f))) 
            {
                if (op->ct2 == 0)
                {
                    CallSystemSe(0, 0x80000208);
                }
                
                op->ct0 = 6;
                op->ct2 = 1;
                op->ct3 = 0;
            }
        }
        
        if ((op->ct0 == 0) && (op->ct2 != 0)) 
        {
            op->ct2 = 0;
            
            CallSystemSe(0, 0x80000209);
        }
        
        if (((sys->pad_ps & 0x800)) && (op->ct0 == 0))
        {
            CallSystemSe(0, 0x80000204);
            
            op->mode0 = 2;
        }
        
        switch (op->ct3) 
        {                       
        case 0:                                     
            op->xn -= 0.5f;
            break;
        case 1:                                     
            op->xn += 0.5f;
            break;
        case 2:                                     
            op->yn += 0.5f;
            break;
        case 3:                                     
            op->yn -= 0.5f;
            break;
        }
        
        cam.ax = (int)(182.04445f * op->xn) & 0xFFFF;
        cam.ay = (int)(182.04445f * op->yn) & 0xFFFF;
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 2:                                         
        cam.pers -= 182;
        
        if (cam.pers < 1821) 
        {
            cam.pers = 1820;
            
            op->mode0 = 3;
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 3:                                         
        if (((op->xn >= 13.0f) && (op->xn <= 16.0f)) && ((op->yn >= 262.0f) && (op->yn <= 266.0f))) 
        {
            bhStFlg(sys->ev_flg, 65);
        } 
        else if (((op->xn >= 31.0f) && (op->xn <= 34.0f)) && ((op->yn >= 246.0f) && (op->yn <= 254.0f))) 
        {
            bhStFlg(sys->ev_flg, 72);
        } 
        else 
        {
            bhStFlg(sys->ev_flg, 66);
        }
        
        op->mode0 = 4;
    case 4:                                         
        if (op->mode1 == 2) 
        {
            CallSystemSe(0, 0x80000204);
            
            op->mode0 = 5;
            op->mode1 = 1;
        }
        
        if (op->mode1 == 3) 
        {
            CallSystemSe(0, 0x80000204);
            
            op->mode0 = 6;
            op->mode1 = 1;
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 5:                                         
    case 6:                                         
        cam.pers += 182;
        
        if (cam.pers >= 14563) 
        {
            if (op->mode0 == 6) 
            {
                cam.pers = 14563;
                
                op->mode0 = 7;
            } 
            else 
            {
                cam.pers = 14563;
                
                bhCrFlg(sys->ev_flg, 65);
                bhCrFlg(sys->ev_flg, 66);
                bhCrFlg(sys->ev_flg, 72);
                
                op->ct0 = 0;
                op->ct3 = -1;
                
                op->mode0 = 1;
            }
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 7:                                         
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 10:                                        
        if (!(sys->ef_flg & 0x1))
        {
            op->ct0 = (op->ct0 + 1) & 0x3F;
            
            if (op->ct0 == 0)
            {
                op->mode0 = 1;
            }
            
            sys->ef_fnc[sys->ef_fncn++] = op;
        }
        
        break;
    }
}

// 100% matching!
void bhDraw138(O_WRK* op) 
{
    NJS_POINT2COL p2c;           
    NJS_POINT2 p[4];     
    NJS_COLOR col[4], uv[4];         
    unsigned int argb;         
    int i;                      
    static NJS_PRIM ef138cur[1];  // DATA
    static NJS_PRIM ef138ledl[4]; // DATA
    static NJS_PRIM ef138leds[4]; // DATA
    static NJS_PRIM ef138tb[12];  // DATA
    static NJS_PRIM ef138oil[9];  // DATA
    
    njPushMatrixEx();
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njTextureFilterMode(1);
    
    njSetTexture(&sys->ef_tlist);
    
    p2c.p = p;
    p2c.col = col;
    p2c.tex = uv;
    p2c.num = 1;
    
    njSetTextureNum(sys->ef_tn[441] + 3);
    
    col[3].color = col[2].color = col[1].color = col[0].color = -1;
    
    uv[0].tex.u = 0;
    uv[0].tex.v = 0;
    
    uv[1].tex.u = uv[0].tex.u + 160;
    uv[1].tex.v = uv[0].tex.v;
    
    uv[2].tex.u = uv[0].tex.u + 160;
    uv[2].tex.v = uv[0].tex.v + 120;
    
    uv[3].tex.u = uv[0].tex.u;
    uv[3].tex.v = uv[0].tex.v + 120;
    
    p[0].x = 0;
    p[0].y = 0;
    
    p[1].x = 640.0f;
    p[1].y = 0;
    
    p[2].x = 640.0f;
    p[2].y = 480.0f;
    
    p[3].x = 0;
    p[3].y = 480.0f;
    
    njDrawPolygon2D(&p2c, 4, -3.0f, 0x80000060);
    
    njTextureFilterMode(0);
    
    njSetTextureNum(sys->ef_tn[441]);
    
    for (i = 0; i <= 4; i++) 
    {
        bhDrawPARAM2D(&ef138tb[i], &p2c, -1.968f);
    } 
    
    col[3].color = col[2].color = col[1].color = col[0].color = -1;
    
    p2c.tex = uv;
    
    uv[0].tex.u = 8;
    uv[0].tex.v = 181;
    
    uv[1].tex.u = uv[0].tex.u;
    uv[1].tex.v = uv[0].tex.v;
    
    uv[2].tex.u = uv[0].tex.u;
    uv[2].tex.v = uv[0].tex.v;
    
    uv[3].tex.u = uv[0].tex.u;
    uv[3].tex.v = uv[0].tex.v;
    
    p[0].x = 266.0f;
    p[0].y = 150.0f;
    
    p[1].x = 112.0f + p[0].x;
    p[1].y = p[0].y;
    
    p[2].x = 112.0f + p[0].x;
    p[2].y = 147.0f - (18.0f * op->gpx);
    
    p[3].x = p[0].x;
    p[3].y = 147.0f - (18.0f * op->gpx);
    
    njDrawPolygon2D(&p2c, 4, -4.0f, 0x80000060);
    
    p[0].x = 430.0f;
    p[0].y = 150.0f;
    
    p[1].x = 112.0f + p[0].x;
    p[1].y = p[0].y;
    
    p[2].x = 112.0f + p[0].x;
    p[2].y = 147.0f - (18.0f * op->gpy);
    
    p[3].x = p[0].x;
    p[3].y = 147.0f - (18.0f * op->gpy);
    
    njDrawPolygon2D(&p2c, 4, -4.0f, 0x80000060);
    
    if (op->gpz > 0)
    {
        if (op->gpz > 1.0f) 
        {
            p[0].x = 264.0f;
            p[0].y = 440.0f;
            
            p[1].x = 112.0f + p[0].x;
            p[1].y = p[0].y;
            
            p[2].x = 112.0f + p[0].x;
            p[2].y = 410.0f - (10.0f * op->gpz);
            
            p[3].x = p[0].x;
            p[3].y = 410.0f - (10.0f * op->gpz);
            
            njDrawPolygon2D(&p2c, 4, -4.0f, 0x80000060);
        } 
        else
        {
            p[0].x = 264.0f;
            p[0].y = 440.0f;
            
            p[1].x = 112.0f + p[0].x;
            p[1].y = p[0].y;
            
            p[2].x = 112.0f + p[0].x;
            p[2].y = 440.0f - (44.0f * op->gpz);
            
            p[3].x = p[0].x;
            p[3].y = 440.0f - (44.0f * op->gpz);
            
            njDrawPolygon2D(&p2c, 4, -4.0f, 0x80000060);
        }
    }
    
    col[3].color = col[2].color = col[1].color = col[0].color = -1;
    
    if (op->gpx > 0)
    {
        i = op->jno[0];
        
        ef138oil[i].px = 266.0f;
        ef138oil[i].py = 147.0f - (18.0f * op->gpx);
        
        bhDrawPARAM2D(&ef138oil[i], &p2c, -3.9f);
    }
    
    if (op->gpy > 0) 
    {
        i = op->jno[1];
        
        ef138oil[i].px = 430.0f;
        ef138oil[i].py = 147.0f - (18.0f * op->gpy);
        
        bhDrawPARAM2D(&ef138oil[i], &p2c, -3.9f);
    }
    
    if (op->gpz > 0) 
    {
        i = op->jno[2];
        
        ef138oil[i].px = 266.0f;
        
        if (op->gpz > 1.0f) 
        {
            ef138oil[i].py = 410.0f - (10.0f * op->gpz);
        } 
        else 
        {
            ef138oil[i].py = 440.0f - (44.0f * op->gpz);
        }
        
        bhDrawPARAM2D(&ef138oil[i], &p2c, -3.9f);
    }
    
    njSetTextureNum(sys->ef_tn[441] + 1);
    
    for (i = 5; i <= 11; i++) 
    {
        bhDrawPARAM2D(&ef138tb[i], &p2c, -1.967f);
    }
    
    njSetTextureNum(sys->ef_tn[441] + 2);
    
    i = op->hide[0];
    
    argb = ((4 - i) * 63) | ((((4 - i) * 0x3F0000) | 0xFF000000) | ((4 - i) * 0x3F00));
    
    col[3].color = col[2].color = col[1].color = col[0].color = argb;
    
    ef138leds[i].px = 139.0f;
    ef138leds[i].py = 164.0f;
    
    bhDrawPARAM2D(&ef138leds[i], &p2c, -1.967f);
    
    i = op->hide[1];
    
    argb = ((4 - i) * 63) | ((((4 - i) * 0x3F0000) | 0xFF000000) | ((4 - i) * 0x3F00));
    
    col[3].color = col[2].color = col[1].color = col[0].color = argb;
    
    ef138leds[i].px = 304.0f;
    ef138leds[i].py = 164.0f;
    
    bhDrawPARAM2D(&ef138leds[i], &p2c, -1.967f);
    
    i = op->hide[2];
    
    argb = ((4 - i) * 63) | ((((4 - i) * 0x3F0000) | 0xFF000000) | ((4 - i) * 0x3F00));
    
    col[3].color = col[2].color = col[1].color = col[0].color = argb;
    
    ef138leds[i].px = 472.0f;
    ef138leds[i].py = 164.0f;
    
    bhDrawPARAM2D(&ef138leds[i], &p2c, -1.967f);
    
    i = op->hide[3];
    
    argb = ((4 - i) * 63) | ((((4 - i) * 0x3F0000) | 0xFF000000) | ((4 - i) * 0x3F00));
    
    col[3].color = col[2].color = col[1].color = col[0].color = argb;
    
    ef138ledl[i].px = 454.0f;
    ef138ledl[i].py = 353.0f;
    
    bhDrawPARAM2D(&ef138ledl[i], &p2c, -1.967f);
    
    if (op->mode0 == 1)
    {
        i = (int)(128.0f + (127.0f * njSin(op->aspd)));
        
        argb = i | (((i << 16) | 0xFF000000) | (i << 8));
        
        col[3].color = col[2].color = col[1].color = col[0].color = argb;
        
        ef138cur->px = op->px;
        ef138cur->py = op->py;
        
        bhDrawPARAM2D(ef138cur, &p2c, -1.966f);
    }
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();
}

// 
// Start address: 0x23c790
void bhEff138(O_WRK* op)
{
	int flg;
	float CurTab[2][3];
	// Line 1350, Address: 0x23c790, Func Offset: 0
	// Line 1357, Address: 0x23c7a0, Func Offset: 0x10
	// Line 1358, Address: 0x23c7b0, Func Offset: 0x20
	// Line 1360, Address: 0x23c7bc, Func Offset: 0x2c
	// Line 1362, Address: 0x23c7c4, Func Offset: 0x34
	// Line 1363, Address: 0x23c7cc, Func Offset: 0x3c
	// Line 1362, Address: 0x23c7d0, Func Offset: 0x40
	// Line 1363, Address: 0x23c7dc, Func Offset: 0x4c
	// Line 1365, Address: 0x23c834, Func Offset: 0xa4
	// Line 1375, Address: 0x23c83c, Func Offset: 0xac
	// Line 1382, Address: 0x23c844, Func Offset: 0xb4
	// Line 1365, Address: 0x23c848, Func Offset: 0xb8
	// Line 1366, Address: 0x23c84c, Func Offset: 0xbc
	// Line 1385, Address: 0x23c850, Func Offset: 0xc0
	// Line 1389, Address: 0x23c854, Func Offset: 0xc4
	// Line 1365, Address: 0x23c858, Func Offset: 0xc8
	// Line 1366, Address: 0x23c85c, Func Offset: 0xcc
	// Line 1386, Address: 0x23c860, Func Offset: 0xd0
	// Line 1366, Address: 0x23c864, Func Offset: 0xd4
	// Line 1367, Address: 0x23c868, Func Offset: 0xd8
	// Line 1366, Address: 0x23c86c, Func Offset: 0xdc
	// Line 1367, Address: 0x23c870, Func Offset: 0xe0
	// Line 1368, Address: 0x23c878, Func Offset: 0xe8
	// Line 1369, Address: 0x23c884, Func Offset: 0xf4
	// Line 1368, Address: 0x23c888, Func Offset: 0xf8
	// Line 1369, Address: 0x23c890, Func Offset: 0x100
	// Line 1370, Address: 0x23c898, Func Offset: 0x108
	// Line 1371, Address: 0x23c8a4, Func Offset: 0x114
	// Line 1370, Address: 0x23c8a8, Func Offset: 0x118
	// Line 1371, Address: 0x23c8b0, Func Offset: 0x120
	// Line 1372, Address: 0x23c8b8, Func Offset: 0x128
	// Line 1371, Address: 0x23c8bc, Func Offset: 0x12c
	// Line 1372, Address: 0x23c8c0, Func Offset: 0x130
	// Line 1373, Address: 0x23c8c8, Func Offset: 0x138
	// Line 1374, Address: 0x23c8dc, Func Offset: 0x14c
	// Line 1375, Address: 0x23c8f0, Func Offset: 0x160
	// Line 1376, Address: 0x23c8f4, Func Offset: 0x164
	// Line 1377, Address: 0x23c8f8, Func Offset: 0x168
	// Line 1378, Address: 0x23c8fc, Func Offset: 0x16c
	// Line 1379, Address: 0x23c900, Func Offset: 0x170
	// Line 1380, Address: 0x23c904, Func Offset: 0x174
	// Line 1381, Address: 0x23c908, Func Offset: 0x178
	// Line 1382, Address: 0x23c90c, Func Offset: 0x17c
	// Line 1383, Address: 0x23c910, Func Offset: 0x180
	// Line 1384, Address: 0x23c914, Func Offset: 0x184
	// Line 1385, Address: 0x23c918, Func Offset: 0x188
	// Line 1386, Address: 0x23c91c, Func Offset: 0x18c
	// Line 1387, Address: 0x23c920, Func Offset: 0x190
	// Line 1388, Address: 0x23c924, Func Offset: 0x194
	// Line 1389, Address: 0x23c928, Func Offset: 0x198
	// Line 1390, Address: 0x23c92c, Func Offset: 0x19c
	// Line 1391, Address: 0x23c930, Func Offset: 0x1a0
	// Line 1393, Address: 0x23c934, Func Offset: 0x1a4
	// Line 1394, Address: 0x23c944, Func Offset: 0x1b4
	// Line 1395, Address: 0x23c96c, Func Offset: 0x1dc
	// Line 1396, Address: 0x23c978, Func Offset: 0x1e8
	// Line 1398, Address: 0x23c984, Func Offset: 0x1f4
	// Line 1399, Address: 0x23c9b0, Func Offset: 0x220
	// Line 1400, Address: 0x23c9bc, Func Offset: 0x22c
	// Line 1403, Address: 0x23c9c8, Func Offset: 0x238
	// Line 1404, Address: 0x23c9d8, Func Offset: 0x248
	// Line 1405, Address: 0x23c9f8, Func Offset: 0x268
	// Line 1406, Address: 0x23ca00, Func Offset: 0x270
	// Line 1408, Address: 0x23ca04, Func Offset: 0x274
	// Line 1409, Address: 0x23ca0c, Func Offset: 0x27c
	// Line 1410, Address: 0x23ca2c, Func Offset: 0x29c
	// Line 1411, Address: 0x23ca34, Func Offset: 0x2a4
	// Line 1414, Address: 0x23ca3c, Func Offset: 0x2ac
	// Line 1416, Address: 0x23ca70, Func Offset: 0x2e0
	// Line 1418, Address: 0x23ca8c, Func Offset: 0x2fc
	// Line 1419, Address: 0x23caa8, Func Offset: 0x318
	// Line 1421, Address: 0x23cab0, Func Offset: 0x320
	// Line 1422, Address: 0x23cab8, Func Offset: 0x328
	// Line 1425, Address: 0x23cac0, Func Offset: 0x330
	// Line 1427, Address: 0x23cac8, Func Offset: 0x338
	// Line 1428, Address: 0x23cae4, Func Offset: 0x354
	// Line 1430, Address: 0x23caec, Func Offset: 0x35c
	// Line 1431, Address: 0x23caf4, Func Offset: 0x364
	// Line 1434, Address: 0x23cafc, Func Offset: 0x36c
	// Line 1436, Address: 0x23cb04, Func Offset: 0x374
	// Line 1439, Address: 0x23cb08, Func Offset: 0x378
	// Line 1440, Address: 0x23cb14, Func Offset: 0x384
	// Line 1442, Address: 0x23cb24, Func Offset: 0x394
	// Line 1441, Address: 0x23cb28, Func Offset: 0x398
	// Line 1443, Address: 0x23cb2c, Func Offset: 0x39c
	// Line 1444, Address: 0x23cb34, Func Offset: 0x3a4
	// Line 1446, Address: 0x23cb40, Func Offset: 0x3b0
	// Line 1447, Address: 0x23cb4c, Func Offset: 0x3bc
	// Line 1448, Address: 0x23cb5c, Func Offset: 0x3cc
	// Line 1451, Address: 0x23cb64, Func Offset: 0x3d4
	// Line 1452, Address: 0x23cb70, Func Offset: 0x3e0
	// Line 1451, Address: 0x23cb78, Func Offset: 0x3e8
	// Line 1452, Address: 0x23cb88, Func Offset: 0x3f8
	// Line 1453, Address: 0x23cb9c, Func Offset: 0x40c
	// Line 1454, Address: 0x23cbac, Func Offset: 0x41c
	// Line 1455, Address: 0x23cbc4, Func Offset: 0x434
	// Line 1456, Address: 0x23cbdc, Func Offset: 0x44c
	// Line 1457, Address: 0x23cbf4, Func Offset: 0x464
	// Line 1458, Address: 0x23cc28, Func Offset: 0x498
	// Line 1461, Address: 0x23cc30, Func Offset: 0x4a0
	// Line 1463, Address: 0x23cc34, Func Offset: 0x4a4
	// Line 1461, Address: 0x23cc38, Func Offset: 0x4a8
	// Line 1462, Address: 0x23cc40, Func Offset: 0x4b0
	// Line 1463, Address: 0x23cc54, Func Offset: 0x4c4
	// Line 1465, Address: 0x23cc70, Func Offset: 0x4e0
	// Line 1466, Address: 0x23cc7c, Func Offset: 0x4ec
	// Line 1467, Address: 0x23cc8c, Func Offset: 0x4fc
	// Line 1468, Address: 0x23cc98, Func Offset: 0x508
	// Line 1469, Address: 0x23ccac, Func Offset: 0x51c
	// Line 1470, Address: 0x23ccc8, Func Offset: 0x538
	// Line 1471, Address: 0x23ccd4, Func Offset: 0x544
	// Line 1472, Address: 0x23ccf8, Func Offset: 0x568
	// Line 1473, Address: 0x23ccfc, Func Offset: 0x56c
	// Line 1475, Address: 0x23cd00, Func Offset: 0x570
	// Line 1476, Address: 0x23cd24, Func Offset: 0x594
	// Line 1477, Address: 0x23cd28, Func Offset: 0x598
	// Line 1480, Address: 0x23cd2c, Func Offset: 0x59c
	// Line 1482, Address: 0x23cd34, Func Offset: 0x5a4
	// Line 1483, Address: 0x23cd40, Func Offset: 0x5b0
	// Line 1484, Address: 0x23cd50, Func Offset: 0x5c0
	// Line 1485, Address: 0x23cd5c, Func Offset: 0x5cc
	// Line 1486, Address: 0x23cd70, Func Offset: 0x5e0
	// Line 1487, Address: 0x23cd8c, Func Offset: 0x5fc
	// Line 1488, Address: 0x23cd98, Func Offset: 0x608
	// Line 1489, Address: 0x23cdbc, Func Offset: 0x62c
	// Line 1490, Address: 0x23cdc0, Func Offset: 0x630
	// Line 1492, Address: 0x23cdc4, Func Offset: 0x634
	// Line 1493, Address: 0x23cde8, Func Offset: 0x658
	// Line 1494, Address: 0x23cdec, Func Offset: 0x65c
	// Line 1497, Address: 0x23cdf0, Func Offset: 0x660
	// Line 1499, Address: 0x23cdf8, Func Offset: 0x668
	// Line 1500, Address: 0x23ce04, Func Offset: 0x674
	// Line 1501, Address: 0x23ce14, Func Offset: 0x684
	// Line 1502, Address: 0x23ce24, Func Offset: 0x694
	// Line 1501, Address: 0x23ce2c, Func Offset: 0x69c
	// Line 1502, Address: 0x23ce30, Func Offset: 0x6a0
	// Line 1503, Address: 0x23ce40, Func Offset: 0x6b0
	// Line 1504, Address: 0x23ce44, Func Offset: 0x6b4
	// Line 1505, Address: 0x23ce48, Func Offset: 0x6b8
	// Line 1507, Address: 0x23ce4c, Func Offset: 0x6bc
	// Line 1506, Address: 0x23ce50, Func Offset: 0x6c0
	// Line 1507, Address: 0x23ce54, Func Offset: 0x6c4
	// Line 1508, Address: 0x23ce58, Func Offset: 0x6c8
	// Line 1509, Address: 0x23ce60, Func Offset: 0x6d0
	// Line 1510, Address: 0x23ce94, Func Offset: 0x704
	// Line 1511, Address: 0x23ce9c, Func Offset: 0x70c
	// Line 1515, Address: 0x23cea4, Func Offset: 0x714
	// Line 1516, Address: 0x23ceb0, Func Offset: 0x720
	// Line 1517, Address: 0x23ceb8, Func Offset: 0x728
	// Line 1518, Address: 0x23cec8, Func Offset: 0x738
	// Line 1521, Address: 0x23cecc, Func Offset: 0x73c
	// Line 1518, Address: 0x23ced4, Func Offset: 0x744
	// Line 1519, Address: 0x23cee4, Func Offset: 0x754
	// Line 1520, Address: 0x23cef8, Func Offset: 0x768
	// Line 1521, Address: 0x23cf08, Func Offset: 0x778
	// Line 1525, Address: 0x23cf18, Func Offset: 0x788
	// Line 1526, Address: 0x23cf20, Func Offset: 0x790
	// Line 1527, Address: 0x23cf24, Func Offset: 0x794
	// Line 1528, Address: 0x23cf28, Func Offset: 0x798
	// Line 1532, Address: 0x23cf60, Func Offset: 0x7d0
	// Line 1531, Address: 0x23cf64, Func Offset: 0x7d4
	// Line 1533, Address: 0x23cf68, Func Offset: 0x7d8
	// Line 1534, Address: 0x23cf70, Func Offset: 0x7e0
	// Line 1536, Address: 0x23cf74, Func Offset: 0x7e4
	// Line 1537, Address: 0x23cf7c, Func Offset: 0x7ec
	// Line 1539, Address: 0x23cf90, Func Offset: 0x800
	// Line 1538, Address: 0x23cf94, Func Offset: 0x804
	// Line 1540, Address: 0x23cf98, Func Offset: 0x808
	// Line 1542, Address: 0x23cfa0, Func Offset: 0x810
	// Line 1541, Address: 0x23cfa4, Func Offset: 0x814
	// Line 1545, Address: 0x23cfa8, Func Offset: 0x818
	// Line 1546, Address: 0x23cfb0, Func Offset: 0x820
	// Line 1547, Address: 0x23cfb8, Func Offset: 0x828
	// Line 1550, Address: 0x23cfc0, Func Offset: 0x830
	// Line 1551, Address: 0x23cff4, Func Offset: 0x864
	// Line 1553, Address: 0x23cffc, Func Offset: 0x86c
	// Line 1555, Address: 0x23d000, Func Offset: 0x870
	// Line 1553, Address: 0x23d004, Func Offset: 0x874
	// Line 1554, Address: 0x23d00c, Func Offset: 0x87c
	// Line 1555, Address: 0x23d020, Func Offset: 0x890
	// Line 1556, Address: 0x23d03c, Func Offset: 0x8ac
	// Line 1557, Address: 0x23d04c, Func Offset: 0x8bc
	// Line 1559, Address: 0x23d06c, Func Offset: 0x8dc
	// Line 1560, Address: 0x23d078, Func Offset: 0x8e8
	// Line 1561, Address: 0x23d08c, Func Offset: 0x8fc
	// Line 1562, Address: 0x23d09c, Func Offset: 0x90c
	// Line 1561, Address: 0x23d0a0, Func Offset: 0x910
	// Line 1562, Address: 0x23d0a4, Func Offset: 0x914
	// Line 1563, Address: 0x23d0bc, Func Offset: 0x92c
	// Line 1564, Address: 0x23d0c0, Func Offset: 0x930
	// Line 1565, Address: 0x23d0c8, Func Offset: 0x938
	// Line 1566, Address: 0x23d0f0, Func Offset: 0x960
	// Line 1567, Address: 0x23d0f4, Func Offset: 0x964
	// Line 1568, Address: 0x23d0f8, Func Offset: 0x968
	// Line 1570, Address: 0x23d100, Func Offset: 0x970
	// Line 1572, Address: 0x23d108, Func Offset: 0x978
	// Line 1573, Address: 0x23d114, Func Offset: 0x984
	// Line 1574, Address: 0x23d128, Func Offset: 0x998
	// Line 1575, Address: 0x23d138, Func Offset: 0x9a8
	// Line 1574, Address: 0x23d13c, Func Offset: 0x9ac
	// Line 1575, Address: 0x23d140, Func Offset: 0x9b0
	// Line 1577, Address: 0x23d158, Func Offset: 0x9c8
	// Line 1576, Address: 0x23d15c, Func Offset: 0x9cc
	// Line 1577, Address: 0x23d160, Func Offset: 0x9d0
	// Line 1578, Address: 0x23d164, Func Offset: 0x9d4
	// Line 1579, Address: 0x23d190, Func Offset: 0xa00
	// Line 1580, Address: 0x23d194, Func Offset: 0xa04
	// Line 1581, Address: 0x23d198, Func Offset: 0xa08
	// Line 1586, Address: 0x23d1a0, Func Offset: 0xa10
	// Line 1587, Address: 0x23d1b8, Func Offset: 0xa28
	// Line 1588, Address: 0x23d1ec, Func Offset: 0xa5c
	// Line 1590, Address: 0x23d1f4, Func Offset: 0xa64
	// Line 1594, Address: 0x23d1f8, Func Offset: 0xa68
	// Line 1590, Address: 0x23d1fc, Func Offset: 0xa6c
	// Line 1591, Address: 0x23d204, Func Offset: 0xa74
	// Line 1592, Address: 0x23d210, Func Offset: 0xa80
	// Line 1593, Address: 0x23d21c, Func Offset: 0xa8c
	// Line 1594, Address: 0x23d228, Func Offset: 0xa98
	// Line 1595, Address: 0x23d244, Func Offset: 0xab4
	// Line 1596, Address: 0x23d254, Func Offset: 0xac4
	// Line 1597, Address: 0x23d25c, Func Offset: 0xacc
	// Line 1598, Address: 0x23d26c, Func Offset: 0xadc
	// Line 1600, Address: 0x23d274, Func Offset: 0xae4
	// Line 1601, Address: 0x23d28c, Func Offset: 0xafc
	// Line 1602, Address: 0x23d2a4, Func Offset: 0xb14
	// Line 1603, Address: 0x23d2bc, Func Offset: 0xb2c
	// Line 1604, Address: 0x23d2f0, Func Offset: 0xb60
	// Line 1606, Address: 0x23d2f8, Func Offset: 0xb68
	// Line 1607, Address: 0x23d314, Func Offset: 0xb84
	// Line 1608, Address: 0x23d32c, Func Offset: 0xb9c
	// Line 1609, Address: 0x23d344, Func Offset: 0xbb4
	// Line 1610, Address: 0x23d35c, Func Offset: 0xbcc
	// Line 1611, Address: 0x23d390, Func Offset: 0xc00
	// Line 1613, Address: 0x23d398, Func Offset: 0xc08
	// Line 1614, Address: 0x23d3b8, Func Offset: 0xc28
	// Line 1615, Address: 0x23d3d8, Func Offset: 0xc48
	// Line 1616, Address: 0x23d3e0, Func Offset: 0xc50
	// Line 1617, Address: 0x23d3e8, Func Offset: 0xc58
	// Line 1618, Address: 0x23d3ec, Func Offset: 0xc5c
	// Line 1625, Address: 0x23d3f0, Func Offset: 0xc60
	// Line 1616, Address: 0x23d3f4, Func Offset: 0xc64
	// Line 1617, Address: 0x23d3f8, Func Offset: 0xc68
	// Line 1616, Address: 0x23d3fc, Func Offset: 0xc6c
	// Line 1617, Address: 0x23d404, Func Offset: 0xc74
	// Line 1618, Address: 0x23d40c, Func Offset: 0xc7c
	// Line 1617, Address: 0x23d410, Func Offset: 0xc80
	// Line 1618, Address: 0x23d418, Func Offset: 0xc88
	// Line 1619, Address: 0x23d420, Func Offset: 0xc90
	// Line 1618, Address: 0x23d424, Func Offset: 0xc94
	// Line 1619, Address: 0x23d42c, Func Offset: 0xc9c
	// Line 1620, Address: 0x23d434, Func Offset: 0xca4
	// Line 1619, Address: 0x23d438, Func Offset: 0xca8
	// Line 1620, Address: 0x23d43c, Func Offset: 0xcac
	// Line 1621, Address: 0x23d444, Func Offset: 0xcb4
	// Line 1620, Address: 0x23d448, Func Offset: 0xcb8
	// Line 1621, Address: 0x23d44c, Func Offset: 0xcbc
	// Line 1622, Address: 0x23d454, Func Offset: 0xcc4
	// Line 1621, Address: 0x23d458, Func Offset: 0xcc8
	// Line 1622, Address: 0x23d45c, Func Offset: 0xccc
	// Line 1623, Address: 0x23d46c, Func Offset: 0xcdc
	// Line 1625, Address: 0x23d478, Func Offset: 0xce8
	// Line 1623, Address: 0x23d47c, Func Offset: 0xcec
	// Line 1624, Address: 0x23d484, Func Offset: 0xcf4
	// Line 1625, Address: 0x23d488, Func Offset: 0xcf8
	// Line 1629, Address: 0x23d498, Func Offset: 0xd08
	// Func End, Address: 0x23d4ac, Func Offset: 0xd1c
	scePrintf("bhEff138 - UNIMPLEMENTED!\n");
}
