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

// 
// Start address: 0x23b3b0
void bhEff137(O_WRK* op)
{
	// Line 878, Address: 0x23b3b0, Func Offset: 0
	// Line 879, Address: 0x23b3bc, Func Offset: 0xc
	// Line 880, Address: 0x23b3cc, Func Offset: 0x1c
	// Line 882, Address: 0x23b3d8, Func Offset: 0x28
	// Line 884, Address: 0x23b3e0, Func Offset: 0x30
	// Line 885, Address: 0x23b3f4, Func Offset: 0x44
	// Line 888, Address: 0x23b420, Func Offset: 0x70
	// Line 890, Address: 0x23b42c, Func Offset: 0x7c
	// Line 891, Address: 0x23b438, Func Offset: 0x88
	// Line 898, Address: 0x23b440, Func Offset: 0x90
	// Line 893, Address: 0x23b44c, Func Offset: 0x9c
	// Line 891, Address: 0x23b450, Func Offset: 0xa0
	// Line 892, Address: 0x23b454, Func Offset: 0xa4
	// Line 894, Address: 0x23b458, Func Offset: 0xa8
	// Line 895, Address: 0x23b45c, Func Offset: 0xac
	// Line 896, Address: 0x23b460, Func Offset: 0xb0
	// Line 891, Address: 0x23b464, Func Offset: 0xb4
	// Line 892, Address: 0x23b46c, Func Offset: 0xbc
	// Line 897, Address: 0x23b470, Func Offset: 0xc0
	// Line 892, Address: 0x23b474, Func Offset: 0xc4
	// Line 893, Address: 0x23b478, Func Offset: 0xc8
	// Line 892, Address: 0x23b47c, Func Offset: 0xcc
	// Line 893, Address: 0x23b484, Func Offset: 0xd4
	// Line 894, Address: 0x23b488, Func Offset: 0xd8
	// Line 895, Address: 0x23b490, Func Offset: 0xe0
	// Line 896, Address: 0x23b498, Func Offset: 0xe8
	// Line 897, Address: 0x23b49c, Func Offset: 0xec
	// Line 898, Address: 0x23b4a0, Func Offset: 0xf0
	// Line 899, Address: 0x23b4c0, Func Offset: 0x110
	// Line 900, Address: 0x23b4ec, Func Offset: 0x13c
	// Line 901, Address: 0x23b4fc, Func Offset: 0x14c
	// Line 902, Address: 0x23b514, Func Offset: 0x164
	// Line 903, Address: 0x23b530, Func Offset: 0x180
	// Line 904, Address: 0x23b548, Func Offset: 0x198
	// Line 905, Address: 0x23b554, Func Offset: 0x1a4
	// Line 906, Address: 0x23b558, Func Offset: 0x1a8
	// Line 908, Address: 0x23b55c, Func Offset: 0x1ac
	// Line 907, Address: 0x23b560, Func Offset: 0x1b0
	// Line 908, Address: 0x23b564, Func Offset: 0x1b4
	// Line 909, Address: 0x23b568, Func Offset: 0x1b8
	// Line 910, Address: 0x23b56c, Func Offset: 0x1bc
	// Line 912, Address: 0x23b574, Func Offset: 0x1c4
	// Line 913, Address: 0x23b580, Func Offset: 0x1d0
	// Line 914, Address: 0x23b588, Func Offset: 0x1d8
	// Line 915, Address: 0x23b594, Func Offset: 0x1e4
	// Line 918, Address: 0x23b59c, Func Offset: 0x1ec
	// Line 919, Address: 0x23b5bc, Func Offset: 0x20c
	// Line 920, Address: 0x23b5f4, Func Offset: 0x244
	// Line 921, Address: 0x23b610, Func Offset: 0x260
	// Line 922, Address: 0x23b618, Func Offset: 0x268
	// Line 923, Address: 0x23b620, Func Offset: 0x270
	// Line 925, Address: 0x23b628, Func Offset: 0x278
	// Line 926, Address: 0x23b674, Func Offset: 0x2c4
	// Line 927, Address: 0x23b690, Func Offset: 0x2e0
	// Line 928, Address: 0x23b698, Func Offset: 0x2e8
	// Line 929, Address: 0x23b6a0, Func Offset: 0x2f0
	// Line 931, Address: 0x23b6a4, Func Offset: 0x2f4
	// Line 932, Address: 0x23b6ac, Func Offset: 0x2fc
	// Line 933, Address: 0x23b6e4, Func Offset: 0x334
	// Line 934, Address: 0x23b700, Func Offset: 0x350
	// Line 935, Address: 0x23b708, Func Offset: 0x358
	// Line 936, Address: 0x23b710, Func Offset: 0x360
	// Line 938, Address: 0x23b714, Func Offset: 0x364
	// Line 939, Address: 0x23b760, Func Offset: 0x3b0
	// Line 940, Address: 0x23b77c, Func Offset: 0x3cc
	// Line 941, Address: 0x23b784, Func Offset: 0x3d4
	// Line 942, Address: 0x23b78c, Func Offset: 0x3dc
	// Line 945, Address: 0x23b790, Func Offset: 0x3e0
	// Line 947, Address: 0x23b7a8, Func Offset: 0x3f8
	// Line 949, Address: 0x23b7bc, Func Offset: 0x40c
	// Line 950, Address: 0x23b7e8, Func Offset: 0x438
	// Line 951, Address: 0x23b7f8, Func Offset: 0x448
	// Line 953, Address: 0x23b800, Func Offset: 0x450
	// Line 955, Address: 0x23b838, Func Offset: 0x488
	// Line 956, Address: 0x23b84c, Func Offset: 0x49c
	// Line 958, Address: 0x23b854, Func Offset: 0x4a4
	// Line 959, Address: 0x23b868, Func Offset: 0x4b8
	// Line 961, Address: 0x23b870, Func Offset: 0x4c0
	// Line 962, Address: 0x23b884, Func Offset: 0x4d4
	// Line 964, Address: 0x23b88c, Func Offset: 0x4dc
	// Line 967, Address: 0x23b8a4, Func Offset: 0x4f4
	// Line 968, Address: 0x23b8c8, Func Offset: 0x518
	// Line 969, Address: 0x23b8ec, Func Offset: 0x53c
	// Line 970, Address: 0x23b920, Func Offset: 0x570
	// Line 972, Address: 0x23b928, Func Offset: 0x578
	// Line 973, Address: 0x23b93c, Func Offset: 0x58c
	// Line 974, Address: 0x23b950, Func Offset: 0x5a0
	// Line 975, Address: 0x23b95c, Func Offset: 0x5ac
	// Line 977, Address: 0x23b964, Func Offset: 0x5b4
	// Line 978, Address: 0x23b998, Func Offset: 0x5e8
	// Line 980, Address: 0x23b9a0, Func Offset: 0x5f0
	// Line 984, Address: 0x23ba18, Func Offset: 0x668
	// Line 986, Address: 0x23ba2c, Func Offset: 0x67c
	// Line 988, Address: 0x23ba34, Func Offset: 0x684
	// Line 990, Address: 0x23baa8, Func Offset: 0x6f8
	// Line 991, Address: 0x23babc, Func Offset: 0x70c
	// Line 992, Address: 0x23bac4, Func Offset: 0x714
	// Line 996, Address: 0x23bad8, Func Offset: 0x728
	// Line 998, Address: 0x23bae0, Func Offset: 0x730
	// Line 999, Address: 0x23baf0, Func Offset: 0x740
	// Line 1000, Address: 0x23bb00, Func Offset: 0x750
	// Line 1001, Address: 0x23bb08, Func Offset: 0x758
	// Line 1003, Address: 0x23bb10, Func Offset: 0x760
	// Line 1004, Address: 0x23bb20, Func Offset: 0x770
	// Line 1005, Address: 0x23bb30, Func Offset: 0x780
	// Line 1006, Address: 0x23bb38, Func Offset: 0x788
	// Line 1008, Address: 0x23bb40, Func Offset: 0x790
	// Line 1009, Address: 0x23bb74, Func Offset: 0x7c4
	// Line 1012, Address: 0x23bb7c, Func Offset: 0x7cc
	// Line 1013, Address: 0x23bb90, Func Offset: 0x7e0
	// Line 1015, Address: 0x23bba4, Func Offset: 0x7f4
	// Line 1016, Address: 0x23bbb4, Func Offset: 0x804
	// Line 1017, Address: 0x23bbc0, Func Offset: 0x810
	// Line 1018, Address: 0x23bbc4, Func Offset: 0x814
	// Line 1020, Address: 0x23bbcc, Func Offset: 0x81c
	// Line 1019, Address: 0x23bbd4, Func Offset: 0x824
	// Line 1020, Address: 0x23bbd8, Func Offset: 0x828
	// Line 1019, Address: 0x23bbdc, Func Offset: 0x82c
	// Line 1020, Address: 0x23bbe0, Func Offset: 0x830
	// Line 1021, Address: 0x23bbec, Func Offset: 0x83c
	// Line 1022, Address: 0x23bc00, Func Offset: 0x850
	// Line 1024, Address: 0x23bc14, Func Offset: 0x864
	// Line 1023, Address: 0x23bc18, Func Offset: 0x868
	// Line 1024, Address: 0x23bc1c, Func Offset: 0x86c
	// Line 1025, Address: 0x23bc20, Func Offset: 0x870
	// Line 1028, Address: 0x23bc28, Func Offset: 0x878
	// Line 1029, Address: 0x23bc5c, Func Offset: 0x8ac
	// Line 1031, Address: 0x23bc64, Func Offset: 0x8b4
	// Line 1032, Address: 0x23bc98, Func Offset: 0x8e8
	// Line 1034, Address: 0x23bca0, Func Offset: 0x8f0
	// Line 1035, Address: 0x23bcb8, Func Offset: 0x908
	// Line 1036, Address: 0x23bcc8, Func Offset: 0x918
	// Line 1037, Address: 0x23bcdc, Func Offset: 0x92c
	// Line 1043, Address: 0x23bd14, Func Offset: 0x964
	// Func End, Address: 0x23bd24, Func Offset: 0x974
	scePrintf("bhEff137 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x23bd30
void bhDraw138(O_WRK* op)
{
	int i;
	unsigned int argb;
	//_anon23 uv[4];
	//_anon23 col[4];
	//_anon34 p[4];
	//_anon39 p2c;
	//_anon48 ef138cur[1];
	//_anon48 ef138ledl[4];
	//_anon48 ef138leds[4];
	//_anon48 ef138tb[12];
	//_anon48 ef138oil[9];
	// Line 1050, Address: 0x23bd30, Func Offset: 0
	// Line 1115, Address: 0x23bd5c, Func Offset: 0x2c
	// Line 1116, Address: 0x23bd64, Func Offset: 0x34
	// Line 1117, Address: 0x23bd70, Func Offset: 0x40
	// Line 1118, Address: 0x23bd7c, Func Offset: 0x4c
	// Line 1119, Address: 0x23bd84, Func Offset: 0x54
	// Line 1120, Address: 0x23bd9c, Func Offset: 0x6c
	// Line 1121, Address: 0x23bda4, Func Offset: 0x74
	// Line 1122, Address: 0x23bdac, Func Offset: 0x7c
	// Line 1125, Address: 0x23bdb8, Func Offset: 0x88
	// Line 1123, Address: 0x23bdc0, Func Offset: 0x90
	// Line 1125, Address: 0x23bdc8, Func Offset: 0x98
	// Line 1127, Address: 0x23bddc, Func Offset: 0xac
	// Line 1128, Address: 0x23bde0, Func Offset: 0xb0
	// Line 1127, Address: 0x23bde4, Func Offset: 0xb4
	// Line 1129, Address: 0x23bde8, Func Offset: 0xb8
	// Line 1128, Address: 0x23bdec, Func Offset: 0xbc
	// Line 1130, Address: 0x23bdf0, Func Offset: 0xc0
	// Line 1129, Address: 0x23bdf4, Func Offset: 0xc4
	// Line 1130, Address: 0x23bdf8, Func Offset: 0xc8
	// Line 1132, Address: 0x23bdfc, Func Offset: 0xcc
	// Line 1131, Address: 0x23be00, Func Offset: 0xd0
	// Line 1132, Address: 0x23be04, Func Offset: 0xd4
	// Line 1133, Address: 0x23be08, Func Offset: 0xd8
	// Line 1140, Address: 0x23be0c, Func Offset: 0xdc
	// Line 1141, Address: 0x23be10, Func Offset: 0xe0
	// Line 1146, Address: 0x23be14, Func Offset: 0xe4
	// Line 1133, Address: 0x23be18, Func Offset: 0xe8
	// Line 1134, Address: 0x23be24, Func Offset: 0xf4
	// Line 1150, Address: 0x23be2c, Func Offset: 0xfc
	// Line 1134, Address: 0x23be30, Func Offset: 0x100
	// Line 1135, Address: 0x23be34, Func Offset: 0x104
	// Line 1144, Address: 0x23be38, Func Offset: 0x108
	// Line 1135, Address: 0x23be3c, Func Offset: 0x10c
	// Line 1136, Address: 0x23be48, Func Offset: 0x118
	// Line 1150, Address: 0x23be4c, Func Offset: 0x11c
	// Line 1136, Address: 0x23be58, Func Offset: 0x128
	// Line 1150, Address: 0x23be64, Func Offset: 0x134
	// Line 1137, Address: 0x23be6c, Func Offset: 0x13c
	// Line 1138, Address: 0x23be78, Func Offset: 0x148
	// Line 1139, Address: 0x23be88, Func Offset: 0x158
	// Line 1141, Address: 0x23be8c, Func Offset: 0x15c
	// Line 1140, Address: 0x23be90, Func Offset: 0x160
	// Line 1141, Address: 0x23be94, Func Offset: 0x164
	// Line 1142, Address: 0x23be98, Func Offset: 0x168
	// Line 1143, Address: 0x23bea0, Func Offset: 0x170
	// Line 1144, Address: 0x23bea8, Func Offset: 0x178
	// Line 1145, Address: 0x23beb0, Func Offset: 0x180
	// Line 1150, Address: 0x23beb8, Func Offset: 0x188
	// Line 1154, Address: 0x23bec0, Func Offset: 0x190
	// Line 1155, Address: 0x23bec8, Func Offset: 0x198
	// Line 1156, Address: 0x23bee8, Func Offset: 0x1b8
	// Line 1157, Address: 0x23beec, Func Offset: 0x1bc
	// Line 1158, Address: 0x23bf04, Func Offset: 0x1d4
	// Line 1162, Address: 0x23bf14, Func Offset: 0x1e4
	// Line 1163, Address: 0x23bf1c, Func Offset: 0x1ec
	// Line 1164, Address: 0x23bf20, Func Offset: 0x1f0
	// Line 1165, Address: 0x23bf24, Func Offset: 0x1f4
	// Line 1167, Address: 0x23bf28, Func Offset: 0x1f8
	// Line 1168, Address: 0x23bf34, Func Offset: 0x204
	// Line 1169, Address: 0x23bf3c, Func Offset: 0x20c
	// Line 1179, Address: 0x23bf44, Func Offset: 0x214
	// Line 1170, Address: 0x23bf4c, Func Offset: 0x21c
	// Line 1182, Address: 0x23bf54, Func Offset: 0x224
	// Line 1177, Address: 0x23bf5c, Func Offset: 0x22c
	// Line 1170, Address: 0x23bf60, Func Offset: 0x230
	// Line 1182, Address: 0x23bf64, Func Offset: 0x234
	// Line 1171, Address: 0x23bf6c, Func Offset: 0x23c
	// Line 1189, Address: 0x23bf70, Func Offset: 0x240
	// Line 1178, Address: 0x23bf78, Func Offset: 0x248
	// Line 1171, Address: 0x23bf7c, Func Offset: 0x24c
	// Line 1189, Address: 0x23bf84, Func Offset: 0x254
	// Line 1172, Address: 0x23bf8c, Func Offset: 0x25c
	// Line 1189, Address: 0x23bf94, Func Offset: 0x264
	// Line 1172, Address: 0x23bf9c, Func Offset: 0x26c
	// Line 1173, Address: 0x23bfa0, Func Offset: 0x270
	// Line 1174, Address: 0x23bfac, Func Offset: 0x27c
	// Line 1175, Address: 0x23bfb8, Func Offset: 0x288
	// Line 1177, Address: 0x23bfc4, Func Offset: 0x294
	// Line 1178, Address: 0x23bfc8, Func Offset: 0x298
	// Line 1179, Address: 0x23bfcc, Func Offset: 0x29c
	// Line 1180, Address: 0x23bfdc, Func Offset: 0x2ac
	// Line 1181, Address: 0x23bfe8, Func Offset: 0x2b8
	// Line 1182, Address: 0x23bff8, Func Offset: 0x2c8
	// Line 1183, Address: 0x23c00c, Func Offset: 0x2dc
	// Line 1184, Address: 0x23c018, Func Offset: 0x2e8
	// Line 1189, Address: 0x23c024, Func Offset: 0x2f4
	// Line 1193, Address: 0x23c02c, Func Offset: 0x2fc
	// Line 1194, Address: 0x23c034, Func Offset: 0x304
	// Line 1195, Address: 0x23c03c, Func Offset: 0x30c
	// Line 1198, Address: 0x23c048, Func Offset: 0x318
	// Line 1205, Address: 0x23c050, Func Offset: 0x320
	// Line 1198, Address: 0x23c054, Func Offset: 0x324
	// Line 1195, Address: 0x23c060, Func Offset: 0x330
	// Line 1205, Address: 0x23c068, Func Offset: 0x338
	// Line 1195, Address: 0x23c070, Func Offset: 0x340
	// Line 1205, Address: 0x23c074, Func Offset: 0x344
	// Line 1196, Address: 0x23c07c, Func Offset: 0x34c
	// Line 1205, Address: 0x23c084, Func Offset: 0x354
	// Line 1196, Address: 0x23c088, Func Offset: 0x358
	// Line 1197, Address: 0x23c08c, Func Offset: 0x35c
	// Line 1198, Address: 0x23c09c, Func Offset: 0x36c
	// Line 1199, Address: 0x23c0b0, Func Offset: 0x380
	// Line 1200, Address: 0x23c0bc, Func Offset: 0x38c
	// Line 1205, Address: 0x23c0c8, Func Offset: 0x398
	// Line 1209, Address: 0x23c0d0, Func Offset: 0x3a0
	// Line 1210, Address: 0x23c0ec, Func Offset: 0x3bc
	// Line 1211, Address: 0x23c108, Func Offset: 0x3d8
	// Line 1212, Address: 0x23c110, Func Offset: 0x3e0
	// Line 1213, Address: 0x23c118, Func Offset: 0x3e8
	// Line 1216, Address: 0x23c124, Func Offset: 0x3f4
	// Line 1223, Address: 0x23c12c, Func Offset: 0x3fc
	// Line 1216, Address: 0x23c130, Func Offset: 0x400
	// Line 1213, Address: 0x23c13c, Func Offset: 0x40c
	// Line 1223, Address: 0x23c144, Func Offset: 0x414
	// Line 1213, Address: 0x23c14c, Func Offset: 0x41c
	// Line 1223, Address: 0x23c150, Func Offset: 0x420
	// Line 1214, Address: 0x23c158, Func Offset: 0x428
	// Line 1223, Address: 0x23c160, Func Offset: 0x430
	// Line 1214, Address: 0x23c164, Func Offset: 0x434
	// Line 1215, Address: 0x23c168, Func Offset: 0x438
	// Line 1216, Address: 0x23c178, Func Offset: 0x448
	// Line 1217, Address: 0x23c18c, Func Offset: 0x45c
	// Line 1218, Address: 0x23c198, Func Offset: 0x468
	// Line 1223, Address: 0x23c1a4, Func Offset: 0x474
	// Line 1226, Address: 0x23c1ac, Func Offset: 0x47c
	// Line 1227, Address: 0x23c1b4, Func Offset: 0x484
	// Line 1228, Address: 0x23c1bc, Func Offset: 0x48c
	// Line 1232, Address: 0x23c1c0, Func Offset: 0x490
	// Line 1228, Address: 0x23c1c4, Func Offset: 0x494
	// Line 1229, Address: 0x23c1c8, Func Offset: 0x498
	// Line 1232, Address: 0x23c1d4, Func Offset: 0x4a4
	// Line 1239, Address: 0x23c1dc, Func Offset: 0x4ac
	// Line 1229, Address: 0x23c1e8, Func Offset: 0x4b8
	// Line 1239, Address: 0x23c1f0, Func Offset: 0x4c0
	// Line 1229, Address: 0x23c1f4, Func Offset: 0x4c4
	// Line 1230, Address: 0x23c1f8, Func Offset: 0x4c8
	// Line 1239, Address: 0x23c200, Func Offset: 0x4d0
	// Line 1230, Address: 0x23c208, Func Offset: 0x4d8
	// Line 1231, Address: 0x23c20c, Func Offset: 0x4dc
	// Line 1232, Address: 0x23c21c, Func Offset: 0x4ec
	// Line 1233, Address: 0x23c230, Func Offset: 0x500
	// Line 1234, Address: 0x23c23c, Func Offset: 0x50c
	// Line 1239, Address: 0x23c248, Func Offset: 0x518
	// Line 1245, Address: 0x23c250, Func Offset: 0x520
	// Line 1250, Address: 0x23c254, Func Offset: 0x524
	// Line 1245, Address: 0x23c258, Func Offset: 0x528
	// Line 1246, Address: 0x23c25c, Func Offset: 0x52c
	// Line 1247, Address: 0x23c260, Func Offset: 0x530
	// Line 1248, Address: 0x23c264, Func Offset: 0x534
	// Line 1250, Address: 0x23c268, Func Offset: 0x538
	// Line 1252, Address: 0x23c27c, Func Offset: 0x54c
	// Line 1253, Address: 0x23c288, Func Offset: 0x558
	// Line 1252, Address: 0x23c290, Func Offset: 0x560
	// Line 1253, Address: 0x23c2a8, Func Offset: 0x578
	// Line 1257, Address: 0x23c2b4, Func Offset: 0x584
	// Line 1253, Address: 0x23c2b8, Func Offset: 0x588
	// Line 1257, Address: 0x23c2cc, Func Offset: 0x59c
	// Line 1260, Address: 0x23c2e0, Func Offset: 0x5b0
	// Line 1262, Address: 0x23c2fc, Func Offset: 0x5cc
	// Line 1263, Address: 0x23c308, Func Offset: 0x5d8
	// Line 1262, Address: 0x23c310, Func Offset: 0x5e0
	// Line 1263, Address: 0x23c328, Func Offset: 0x5f8
	// Line 1267, Address: 0x23c334, Func Offset: 0x604
	// Line 1263, Address: 0x23c338, Func Offset: 0x608
	// Line 1267, Address: 0x23c34c, Func Offset: 0x61c
	// Line 1270, Address: 0x23c360, Func Offset: 0x630
	// Line 1272, Address: 0x23c37c, Func Offset: 0x64c
	// Line 1273, Address: 0x23c388, Func Offset: 0x658
	// Line 1272, Address: 0x23c390, Func Offset: 0x660
	// Line 1273, Address: 0x23c3a8, Func Offset: 0x678
	// Line 1274, Address: 0x23c3bc, Func Offset: 0x68c
	// Line 1275, Address: 0x23c3e4, Func Offset: 0x6b4
	// Line 1276, Address: 0x23c3ec, Func Offset: 0x6bc
	// Line 1281, Address: 0x23c418, Func Offset: 0x6e8
	// Line 1285, Address: 0x23c42c, Func Offset: 0x6fc
	// Line 1286, Address: 0x23c44c, Func Offset: 0x71c
	// Line 1287, Address: 0x23c454, Func Offset: 0x724
	// Line 1288, Address: 0x23c46c, Func Offset: 0x73c
	// Line 1290, Address: 0x23c47c, Func Offset: 0x74c
	// Line 1292, Address: 0x23c498, Func Offset: 0x768
	// Line 1293, Address: 0x23c49c, Func Offset: 0x76c
	// Line 1298, Address: 0x23c4a0, Func Offset: 0x770
	// Line 1293, Address: 0x23c4a4, Func Offset: 0x774
	// Line 1298, Address: 0x23c4a8, Func Offset: 0x778
	// Line 1293, Address: 0x23c4ac, Func Offset: 0x77c
	// Line 1294, Address: 0x23c4cc, Func Offset: 0x79c
	// Line 1295, Address: 0x23c4d0, Func Offset: 0x7a0
	// Line 1296, Address: 0x23c4d4, Func Offset: 0x7a4
	// Line 1297, Address: 0x23c4d8, Func Offset: 0x7a8
	// Line 1298, Address: 0x23c4dc, Func Offset: 0x7ac
	// Line 1299, Address: 0x23c4ec, Func Offset: 0x7bc
	// Line 1298, Address: 0x23c4f4, Func Offset: 0x7c4
	// Line 1299, Address: 0x23c4fc, Func Offset: 0x7cc
	// Line 1300, Address: 0x23c508, Func Offset: 0x7d8
	// Line 1302, Address: 0x23c51c, Func Offset: 0x7ec
	// Line 1303, Address: 0x23c520, Func Offset: 0x7f0
	// Line 1308, Address: 0x23c524, Func Offset: 0x7f4
	// Line 1303, Address: 0x23c528, Func Offset: 0x7f8
	// Line 1308, Address: 0x23c52c, Func Offset: 0x7fc
	// Line 1303, Address: 0x23c530, Func Offset: 0x800
	// Line 1304, Address: 0x23c550, Func Offset: 0x820
	// Line 1305, Address: 0x23c554, Func Offset: 0x824
	// Line 1306, Address: 0x23c558, Func Offset: 0x828
	// Line 1307, Address: 0x23c55c, Func Offset: 0x82c
	// Line 1308, Address: 0x23c560, Func Offset: 0x830
	// Line 1309, Address: 0x23c570, Func Offset: 0x840
	// Line 1308, Address: 0x23c578, Func Offset: 0x848
	// Line 1309, Address: 0x23c580, Func Offset: 0x850
	// Line 1310, Address: 0x23c58c, Func Offset: 0x85c
	// Line 1312, Address: 0x23c5a0, Func Offset: 0x870
	// Line 1313, Address: 0x23c5a4, Func Offset: 0x874
	// Line 1318, Address: 0x23c5a8, Func Offset: 0x878
	// Line 1313, Address: 0x23c5ac, Func Offset: 0x87c
	// Line 1318, Address: 0x23c5b0, Func Offset: 0x880
	// Line 1313, Address: 0x23c5b4, Func Offset: 0x884
	// Line 1314, Address: 0x23c5d4, Func Offset: 0x8a4
	// Line 1315, Address: 0x23c5d8, Func Offset: 0x8a8
	// Line 1316, Address: 0x23c5dc, Func Offset: 0x8ac
	// Line 1317, Address: 0x23c5e0, Func Offset: 0x8b0
	// Line 1318, Address: 0x23c5e4, Func Offset: 0x8b4
	// Line 1319, Address: 0x23c5f4, Func Offset: 0x8c4
	// Line 1318, Address: 0x23c5fc, Func Offset: 0x8cc
	// Line 1319, Address: 0x23c604, Func Offset: 0x8d4
	// Line 1320, Address: 0x23c610, Func Offset: 0x8e0
	// Line 1322, Address: 0x23c624, Func Offset: 0x8f4
	// Line 1323, Address: 0x23c628, Func Offset: 0x8f8
	// Line 1328, Address: 0x23c62c, Func Offset: 0x8fc
	// Line 1323, Address: 0x23c630, Func Offset: 0x900
	// Line 1328, Address: 0x23c634, Func Offset: 0x904
	// Line 1323, Address: 0x23c638, Func Offset: 0x908
	// Line 1324, Address: 0x23c658, Func Offset: 0x928
	// Line 1325, Address: 0x23c65c, Func Offset: 0x92c
	// Line 1326, Address: 0x23c660, Func Offset: 0x930
	// Line 1327, Address: 0x23c664, Func Offset: 0x934
	// Line 1328, Address: 0x23c668, Func Offset: 0x938
	// Line 1329, Address: 0x23c678, Func Offset: 0x948
	// Line 1328, Address: 0x23c688, Func Offset: 0x958
	// Line 1329, Address: 0x23c690, Func Offset: 0x960
	// Line 1330, Address: 0x23c698, Func Offset: 0x968
	// Line 1332, Address: 0x23c6ac, Func Offset: 0x97c
	// Line 1333, Address: 0x23c6bc, Func Offset: 0x98c
	// Line 1334, Address: 0x23c6e4, Func Offset: 0x9b4
	// Line 1335, Address: 0x23c6fc, Func Offset: 0x9cc
	// Line 1336, Address: 0x23c700, Func Offset: 0x9d0
	// Line 1337, Address: 0x23c704, Func Offset: 0x9d4
	// Line 1338, Address: 0x23c708, Func Offset: 0x9d8
	// Line 1339, Address: 0x23c70c, Func Offset: 0x9dc
	// Line 1341, Address: 0x23c714, Func Offset: 0x9e4
	// Line 1339, Address: 0x23c724, Func Offset: 0x9f4
	// Line 1340, Address: 0x23c728, Func Offset: 0x9f8
	// Line 1341, Address: 0x23c72c, Func Offset: 0x9fc
	// Line 1340, Address: 0x23c730, Func Offset: 0xa00
	// Line 1341, Address: 0x23c734, Func Offset: 0xa04
	// Line 1344, Address: 0x23c740, Func Offset: 0xa10
	// Line 1345, Address: 0x23c74c, Func Offset: 0xa1c
	// Line 1346, Address: 0x23c758, Func Offset: 0xa28
	// Line 1347, Address: 0x23c760, Func Offset: 0xa30
	// Func End, Address: 0x23c790, Func Offset: 0xa60
	scePrintf("bhDraw138 - UNIMPLEMENTED!\n");
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
