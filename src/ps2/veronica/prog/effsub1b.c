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
#include "../../../ps2/veronica/prog/pwksub.h"
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
    static NJS_PRIM ef134tb[8] = 
    {
        { 320.0f, 412.0f, -64.0f, -36.0f, 64.0f, 36.0f, { 0x00000000, 0x00000100, 0x00900100, 0x00900000 } },
        { 320.0f, 412.0f, -8.0f,  -24.0f, 8.0f,  8.0f,  { 0x00900000, 0x00900020, 0x00D00020, 0x00D00000 } },
        { 320.0f, 412.0f, -8.0f,  -32.0f, 8.0f,  0.0f,  { 0x00900020, 0x00900040, 0x00D00040, 0x00D00020 } },
        { 320.0f, 412.0f, -8.0f,  -32.0f, 8.0f,  0.0f,  { 0x00900040, 0x00900060, 0x00D00060, 0x00D00040 } },
        { 320.0f, 412.0f, -8.0f,  -32.0f, 8.0f,  0.0f,  { 0x00900060, 0x00900080, 0x00D00080, 0x00D00060 } },
        { 320.0f, 412.0f, -32.0f, -8.0f,  0.0f,  8.0f,  { 0x009000C0, 0x00900100, 0x00B00100, 0x00B000C0 } },
        { 320.0f, 412.0f, -32.0f, -8.0f,  0.0f,  8.0f,  { 0x00B00080, 0x00B000C0, 0x00D000C0, 0x00D00080 } },
        { 320.0f, 412.0f, -32.0f, -8.0f,  0.0f,  8.0f,  { 0x00B000C0, 0x00B00100, 0x00D00100, 0x00D000C0 } }
    };

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

// 100% matching!
void bhEff135(O_WRK* op)
{
    BH_PWORK* pp; 
    int i;        
    int eno; // not from DWARF
    
    op->flg |= 0x1000000;
    
    if (!(sys->ef_flg & 0x4)) 
    {
        sys->ef_flg |= 0x4;
        
        sys->zan_memp = bhGetFreeMemory(0x200000, 64);
        sys->zanp = sys->zan_memp;
    }
    
    switch (op->mode0)
    {                            
    case 0:
        if (((op->flg & 0x80)) && (op->mode1 != 0)) 
        {
            pp = (BH_PWORK*)op->lkwkp;
            
            if ((pp->mdl[op->type].objP != NULL) && (pp->mdl[op->type].objP[op->lkono].model != NULL)) 
            {
                i = ((pp->mdl[op->type].objP[op->lkono].model->vlist[1] >> 16) << 5) + 72;
                
                i += 64 - (i % 64);
                
                op->exp0 = sys->zanp;
                
                if (!(&sys->zanp[8 * i] >= (sys->zan_memp + 0x200000))) 
                {
                    sys->zanp = (unsigned char*)(((int)&sys->zanp[8 * i] + 63) & ~0x3F);
                    
                    ef_Zanzo[0] = ef_Zanzo[1] = ef_Zanzo[2] = ef_Zanzo[3] = ef_Zanzo[4] = ef_Zanzo[5] = NULL;
                    
                    op->ct0 = 0;
                    
                    op->mode0 = 1;
                }
            }
        }
        
        break;
    case 1:
        if (op->mode1 != 0)
        {
            pp = (BH_PWORK*)op->lkwkp;
            
            sys->ef.id = 136;
            
            sys->ef.flg = 1;
            
            sys->ef.type = op->idx;
            
            sys->ef.flr_no = op->ct0;
            
            sys->ef.mdlver = op->type;
            
            sys->ef.px = pp->px;
            sys->ef.py = pp->py;
            sys->ef.pz = pp->pz;
            
            eno = bhSetEffectTb(&sys->ef, NULL, op->lkwkp, op->lkono);
            
            if (eno != -1) 
            {
                eff[eno].flg &= ~0x80;
            }
            
            op->ct0++;
            
            if (op->ct0 > 5)
            {
                op->ct0 = 0;
            }
        }
        
        break;
    }
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

// 91.70% matching (matches on GC)
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
    static NJS_PRIM ef137tb[9] = 
    {
        { 320.0f, 44.0f,  -16.0f, -12.0f, 16.0f,  12.0f, { 0x00400040, 0x00400080, 0x00700080, 0x00700040 } },
        { 320.0f, 436.0f, -16.0f, -12.0f, 16.0f,  12.0f, { 0x00700040, 0x00700080, 0x00400080, 0x00400040 } },
        { 596.0f, 240.0f, -12.0f, -16.0f, 12.0f,  16.0f, { 0x00700040, 0x00400040, 0x00400080, 0x00700080 } },
        { 44.0f,  240.0f, -12.0f, -16.0f, 12.0f,  16.0f, { 0x00400080, 0x00700080, 0x00700040, 0x00400040 } },
        { 320.0f, 240.0f, -28.0f, -24.0f, 28.0f,  24.0f, { 0x00900020, 0x00900090, 0x00F00090, 0x00F00020 } },
        { 64.0f,  64.0f,   0.0f,   0.0f,  48.0f,  48.0f, { 0x004000A0, 0x00400100, 0x00A00100, 0x00A000A0 } },
        { 576.0f, 64.0f,   0.0f,   0.0f, -48.0f,  48.0f, { 0x004000A0, 0x00400100, 0x00A00100, 0x00A000A0 } },
        { 64.0f,  418.0f,  0.0f,   0.0f,  48.0f, -48.0f, { 0x004000A0, 0x00400100, 0x00A00100, 0x00A000A0 } },
        { 576.0f, 418.0f,  0.0f,   0.0f, -48.0f, -48.0f, { 0x004000A0, 0x00400100, 0x00A00100, 0x00A000A0 } }
    };

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
    
    bhDrawPARAM2D(&ef137tb[4], &p2c, -1.5f);
    
    for (i = 5; i < 9; i++) 
    {
        bhDrawPARAM2D(&ef137tb[i], &p2c, -1.5f);
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
        
        bhDrawPARAM2D(&ef137tb[i], &p2c, -1.5f);
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
    static NJS_PRIM ef138tb[12]; // DATA 
    static NJS_PRIM ef138ledl[4] =
    {
        { 0.0f, 0.0f, 0.0f, 0.0f, 44.0f, 28.0f, { 0x00000000, 0x00000058, 0x00380058, 0x00380000 } },
        { 0.0f, 0.0f, 0.0f, 0.0f, 44.0f, 28.0f, { 0x00380000, 0x00380058, 0x00700058, 0x00700000 } },
        { 0.0f, 0.0f, 0.0f, 0.0f, 44.0f, 28.0f, { 0x00700000, 0x00700058, 0x00A80058, 0x00A80000 } },
        { 0.0f, 0.0f, 0.0f, 0.0f, 44.0f, 28.0f, { 0x00A80000, 0x00A80058, 0x00E00058, 0x00E00000 } }
    };
    static NJS_PRIM ef138leds[4] =
    {
        { 0.0f, 0.0f, 0.0f, 0.0f, 32.0f, 24.0f, { 0x00000058, 0x00000098, 0x00300098, 0x00300058 } },
        { 0.0f, 0.0f, 0.0f, 0.0f, 32.0f, 24.0f, { 0x00300058, 0x00300098, 0x00600098, 0x00600058 } },
        { 0.0f, 0.0f, 0.0f, 0.0f, 32.0f, 24.0f, { 0x00600058, 0x00600098, 0x00900098, 0x00900058 } },
        { 0.0f, 0.0f, 0.0f, 0.0f, 32.0f, 24.0f, { 0x00900058, 0x00900098, 0x00C00098, 0x00C00058 } }
    };
    static NJS_PRIM ef138cur[1] =
    {
        { 0.0f, 0.0f, -32.0f, -24.0f, 32.0f, 24.0f, { 0x00B80098, 0x00B800F0, 0x010000F0, 0x01000098 } }
    };
    static NJS_PRIM ef138oil[9] = 
    {
        { 0.0f, 0.0f, 0.0f, -12.0f, 112.0f, 12.0f, { 0x004D0000, 0x004D0038, 0x00570038, 0x00570000 } },
        { 0.0f, 0.0f, 0.0f, -12.0f, 112.0f, 12.0f, { 0x00590000, 0x00590038, 0x00630038, 0x00630000 } },
        { 0.0f, 0.0f, 0.0f, -12.0f, 112.0f, 12.0f, { 0x00650000, 0x00650038, 0x006F0038, 0x006F0000 } },
        { 0.0f, 0.0f, 0.0f, -12.0f, 112.0f, 12.0f, { 0x00710000, 0x00710038, 0x007B0038, 0x007B0000 } },
        { 0.0f, 0.0f, 0.0f, -12.0f, 112.0f, 12.0f, { 0x007D0000, 0x007D0038, 0x00870038, 0x00870000 } },
        { 0.0f, 0.0f, 0.0f, -12.0f, 112.0f, 12.0f, { 0x00890000, 0x00890038, 0x00930038, 0x00930000 } },
        { 0.0f, 0.0f, 0.0f, -12.0f, 112.0f, 12.0f, { 0x00950000, 0x00950038, 0x009F0038, 0x009F0000 } },
        { 0.0f, 0.0f, 0.0f, -12.0f, 112.0f, 12.0f, { 0x00A10000, 0x00A10038, 0x00AB0038, 0x00AB0000 } },
        { 0.0f, 0.0f, 0.0f, -12.0f, 112.0f, 12.0f, { 0x00AD0000, 0x00AD0038, 0x00B70038, 0x00B70000 } }
    };
    
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

// 100% matching!
void bhEff138(O_WRK* op)
{
    int flg;                   
    static float CurTab[3][2] = 
    {
        { 320.0f, 176.0f },
        { 488.0f, 176.0f },
        { 474.0f, 370.0f }
    };

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
        op->ct2 = sys->pt_flg;
        op->ct3 = sys->sp_flg;
        
        sys->pt_flg = 0;
        sys->pt_flg |= 0x10;
        
        sys->sp_flg = 0;
        sys->sp_flg |= 0x28;
        
        op->mtn_no = rom->bak_col;
        
        rom->bak_col = 0;
        
        sys->bcl_ct = 0;
        
        sys->gm_flg |= 0x8000;
        
        op->func = (void*)bhDraw138;
        
        op->frm_no = 0;
        
        op->ct0 = 2;
        
        op->hide[0] = 3;
        op->hide[1] = 0;
        op->hide[2] = 0;
        op->hide[3] = 3;
        
        op->jno[0] = 8;
        op->jno[1] = 8;
        op->jno[2] = 8;
        
        op->gpx = 3.0f;
        op->gpy = 5.0f;
        op->gpz = 0;
        
        op->clp_jno[0] = 3;
        op->clp_jno[1] = 5;
        op->clp_jno[2] = 0;
        
        op->mode0 = 1;
    case 1:                                         
        if (op->ct0 < 2) 
        {
            if (((sys->pad_ps & 0x8)) && (op->ct0 <= 0)) 
            {
                CallSystemSe(0, 2);
                
                op->ct0++;
            }
            
            if (((sys->pad_ps & 0x4)) && (op->ct0 > 0))
            {
                CallSystemSe(0, 2);
                
                op->ct0--;
            }
        }
        
        if (op->ct0 == 2)
        {
            if ((sys->pad_ps & 0x1))
            {
                CallSystemSe(0, 2);
                
                op->ct0 = 1;
            }
        } 
        else if ((sys->pad_ps & 0x2))
        {
            CallSystemSe(0, 2);
            
            op->ct0 = 2;
        }
        
        if (((sys->pad_ps & 0x800)) && (op->hide[op->ct0 + 1] == 0)) 
        {
            switch (op->ct0) 
            {                
            case 0:                             
                if ((10 - op->clp_jno[2]) >= op->clp_jno[0]) 
                {
                    op->clp_jno[2] += op->clp_jno[0];
                    op->clp_jno[0] = 0;
                }
                else 
                {
                    op->clp_jno[0] -= 10 - op->clp_jno[2];
                    op->clp_jno[2] = 10;
                }
                
                break;
            case 1:                             
                if ((10 - op->clp_jno[2]) >= op->clp_jno[1])
                {
                    op->clp_jno[2] += op->clp_jno[1];
                    op->clp_jno[1] = 0;
                } 
                else 
                {
                    op->clp_jno[1] -= 10 - op->clp_jno[2];
                    op->clp_jno[2] = 10;
                }
                
                break;
            default:                            
                op->clp_jno[2] = 0;
                break;
            }
            
            CallSystemSe(0, 3);
            CallSystemSe(0, 0x80000203);
            
            op->ct1 = 0;
            
            op->mode0 = 2;
        }
        else if ((sys->pad_ps & 0x1000)) 
        {
            CallSystemSe(0, 0);
            
            bhSetScreenFade(0xFF000000, 10.0f);
            
            op->mode0 = 10;
        }
        
        op->px = CurTab[op->ct0][0];
        op->py = CurTab[op->ct0][1]; 
        
        op->aspd = (op->aspd + 2048) & 0x7FFF;
        
        if (op->jno[0] < 8)
        {
            op->jno[0]++;
        }
        
        if (op->jno[1] < 8)
        {
            op->jno[1]++;
        }
        
        if (op->jno[2] < 8)
        {
            op->jno[2]++;
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 2:                                         
        op->ct1++;
        
        op->hide[op->ct0 + 1] = op->ct1 & 0x3;
        
        flg = 0;
        
        switch (op->ct0) 
        {                        
        case 0:                                     
            op->jno[0]--;
            
            if (op->jno[0] < 0) 
            {
                op->jno[0] = 4;
            }
            
            op->jno[2]--;
            
            if (op->jno[2] < 0) 
            {
                op->jno[2] = 4;
            }
            
            op->gpx -= 0.05f;
            op->gpz += 0.05f;
            
            if (op->gpx <= op->clp_jno[0]) 
            {
                op->gpx = op->clp_jno[0];
                
                flg |= 0x1;
            }
            
            if (op->gpz >= op->clp_jno[2]) 
            {
                op->gpz = op->clp_jno[2];
                
                flg |= 0x2;
            }
            
            op->hide[3] = 0;
            break;
        case 1:                                     
            op->jno[1]--;
            
            if (op->jno[1] < 0) 
            {
                op->jno[1] = 4;
            }
            
            op->jno[2]--;
            
            if (op->jno[2] < 0) 
            {
                op->jno[2] = 4;
            }
            
            op->gpy -= 0.05f;
            op->gpz += 0.05f;
            
            if (op->gpy <= op->clp_jno[1]) 
            {
                op->gpy = op->clp_jno[1];
                
                flg |= 0x1;
            }
            
            if (op->gpz >= op->clp_jno[2])
            {
                op->gpz = op->clp_jno[2];
                
                flg |= 0x2;
            }
            
            op->hide[3] = 0;
            break;
        default:                                    
            op->jno[2]--;
            
            if (op->jno[2] < 0) 
            {
                op->jno[2] = 4;
            }
            
            op->gpz -= 0.1f;
            
            if (op->gpz <= 0) 
            {
                op->gpz = 0;
                
                op->clp_jno[2] = 0;
                
                op->hide[1] = 0;
                op->hide[2] = 0;
                op->hide[3] = 3;
                
                op->mode0 = 1;
                
                sys->ef_fnc[sys->ef_fncn++] = op;
                
                StopSystemSe();
                return;
            }
        }
        
        if (flg == 3) 
        {
            StopSystemSe();
            
            if (op->ct0 < 2)
            {
                op->gpx = op->clp_jno[0];
                op->gpy = op->clp_jno[1];
                op->gpz = op->clp_jno[2];
                
                if (op->gpz >= 10.0f) 
                {
                    op->hide[1] = 3;
                    op->hide[2] = 3;
                    op->hide[3] = 0;
                    
                    if (((op->ct0 == 0) && ((int)op->gpx <= 0)) || ((op->ct0 == 1) && ((int)op->gpy <= 0)))
                    {
                        op->ct1 = 0;
                        
                        op->mode0 = 3; 
                    }
                    else 
                    {
                        op->mode0 = 1; 
                    }
                } 
                else if ((int)op->gpz == 7) 
                {
                    op->ct1 = 0;
                    
                    op->mode0 = 4;
                }
                else 
                {
                    op->ct1 = 0;
                    
                    op->mode0 = 3;
                }
            } 
            else
            {
                op->hide[3] = 3;
                
                op->mode0 = 1;
            }
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 3:                                         
        op->ct1++; 
        
        op->hide[op->ct0 + 1] = op->ct1 & 0x3;
        
        if (op->ct1 == 30)
        {
            CallSystemSe(0, 0x80000202);
        }
        
        if (op->ct1 > 30) 
        {
            switch (op->ct0) 
            {                    
            case 0:                                 
                op->jno[0]--;
                
                if (op->jno[0] < 0) 
                {
                    op->jno[0] = 4;
                }
                
                op->gpx += 0.1f;
                
                if (op->gpx >= 3.0f)
                {
                    op->gpx = 3.0f;
                    
                    op->clp_jno[0] = 3;
                    
                    if (op->gpz >= 10.0f) 
                    {
                        op->hide[1] = 3;
                    } 
                    else 
                    {
                        op->hide[1] = 0;
                    }
                    
                    op->mode0 = 1;
                    
                    StopSystemSe();
                }
                
                break;
            case 1:                                 
                op->jno[1]--;
                
                if (op->jno[1] < 0)
                {
                    op->jno[1] = 4;
                }
                
                op->gpy += 0.1f;
                
                if (op->gpy >= 5.0f) 
                {
                    op->gpy = 5.0f;
                    
                    op->clp_jno[1] = 5;
                    
                    if (op->gpz >= 10.0f) 
                    {
                        op->hide[2] = 3;
                    }
                    else
                    {
                        op->hide[2] = 0;
                    }
                    
                    op->mode0 = 1;
                    
                    StopSystemSe();
                }
                
                break;
            }
        }
        
        if (op->jno[2] < 8)
        {
            op->jno[2]++;
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 4:                                         
        op->ct1++;
        
        op->hide[1] = op->ct1 & 0x3;
        op->hide[2] = op->ct1 & 0x3;
        op->hide[3] = op->ct1 & 0x3;
        
        if (op->ct1 == 8) 
        {
            CallSystemSe(0, 0x80000205);
        }
        
        if (op->ct1 > 120)
        {
            op->frm_no = 1;
            
            bhSetScreenFade(0xFF000000, 10.0f);
            
            op->mode0 = 10;
        }
        
        if (op->jno[0] < 8)
        {
            op->jno[0]++;
        }
        
        if (op->jno[1] < 8) 
        {
            op->jno[1]++;
        }
        
        if (op->jno[2] < 8) 
        {
            op->jno[2]++;
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 10:                                        
        if (!(sys->cb_flg & 0x2)) 
        {
            op->mode0 = 11;
        }
        
        if (op->jno[0] < 8) 
        {
            op->jno[0]++;
        }
        
        if (op->jno[1] < 8)
        {
            op->jno[1]++;
        }
        
        if (op->jno[2] < 8) 
        {
            op->jno[2]++;
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        break;
    case 11:                                        
        if (op->frm_no != 0) 
        {
            bhStFlg(sys->ev_flg, 64);
        }
        
        bhSetScreenFade(sys->fade_pbk, 3.0f);
        
        bhStandPlayerMotion();
        
        sys->gm_flg |= 0x800;
        
        sys->st_flg &= ~0x1;
        sys->cb_flg &= ~0x44;
        
        sys->pt_flg = op->ct2;
        sys->sp_flg = op->ct3;
        
        rom->bak_col = op->mtn_no;
        
        sys->bcl_ct = 0;
        
        sys->gm_flg |= 0x8000;
        
        *(int*)&op->mode0 = 0;
        
        sys->st_flg &= ~0x4;
        break;
    }
}
