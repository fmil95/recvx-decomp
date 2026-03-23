#include "zonzon1.h"
#include "effect.h"
#include "effsub3.h"
#include "njplus.h"
#include "ps2_NaMath.h"
#include "sdfunc.h"
#include "main.h"

static BT_WK BloodType[31] = 
{
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 1, 0, 5 }, 
    { 1, 1, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 1 }, 
    { 1, 1, 0 }, 
    { 0, 0, 1 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 3, 2, 1 }, 
    { 2, 3, 0 }, 
    { 3, 0, 1 }, 
    { 3, 0, 8 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 2, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 1, 6 }, 
    { 0, 1, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 0, 1, 0 }, 
    { 0, 0, 0 }, 
    { 0, 0, 0 }, 
    { 2, 0, 2 } 
};
unsigned int BloodCol[4][2] = 
{
    { 0xFF5F0000, 0xFF4F0000 },
    { 0xFF4F3520, 0xFF20102F },
    { 0xFF3F3F16, 0xFF102F18 },
    { 0xFF3F0000, 0xFF2F0000 }
};

// 99.94% matching (matches on GC)
void bhEne_SetMinceEffect(BH_PWORK* epw, int type, int num)
{
    int eno; 
    int i; 
    int dam_ang; 
    float size; 

    sys->ef.id = 250;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type;
    
    sys->ef.px = epw->dpx;
    sys->ef.py = epw->dpy;
    sys->ef.pz = epw->dpz;
    
    sys->ef.sz = sys->ef.sy = sys->ef.sx = 0.2f + (0.1f * (-rand() / -2.1474836E9f));
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    dam_ang = bhArcTan2(plp->px - epw->px, plp->pz - epw->pz);
    
    for (i = 0; i < num; i++)
    {
        sys->ef.ay = dam_ang + (int)((21845.33f * (-rand() / -2.1474836E9f)) - 10922.66f);
    
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if (eno != -1) 
        {   
            eff[eno].stflg |= 0x20;
            
            eff[eno].txp[0] = epw->mdl[BloodType[epw->id].mdlno].texP;
            eff[eno].tex_id = BloodType[epw->id].tex_id;
        }
    }
}

// 99.94% matching (matches on GC)
void bhEne_SetMinceEffect2(BH_PWORK* epw, int type, float size, int num)
{
    int eno; 
    int i; 
    int dam_ang; 

    sys->ef.id = 250;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type;
    
    sys->ef.px = epw->dpx;
    sys->ef.py = epw->dpy;
    sys->ef.pz = epw->dpz;
    
    sys->ef.sx = size;
    sys->ef.sy = size;
    sys->ef.sz = size;
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    dam_ang = bhArcTan2(plp->px - epw->px, plp->pz - epw->pz);
    
    for (i = 0; i < num; i++)
    {
        sys->ef.ay = dam_ang + (int)((21845.33f * (-rand() / -2.1474836E9f)) - 10922.66f);
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if (eno != -1)
        {
            eff[eno].stflg |= 0x20;
            
            eff[eno].txp[0] = epw->mdl[BloodType[epw->id].mdlno].texP;
            eff[eno].tex_id = BloodType[epw->id].tex_id;
        }
    }
}

// 100% matching!
void bhEne_SetBloodEffect(BH_PWORK* epw, int type)
{
    bhEne_SetBloodEffect5(epw, 0, type);
}

// 100% matching!
void bhEne_SetBloodEffect2(BH_PWORK* epw, int type, int jno, NJS_POINT3* ofp)
{
    NJS_POINT3 org = { 0 }; 
    NJS_POINT3 vec; 
    
    if (ofp == NULL) 
    {
        ofp = &org;
    }
    
    vec.x = -epw->dvx;
    vec.y = -epw->dvy;
    vec.z = -epw->dvz;
    
    bhSetEffParticleMk2(epw, jno, ofp, &vec, BloodCol[BloodType[epw->id].color][0], BloodCol[BloodType[epw->id].color][1], type >> 16);
    
    sys->ef.id = 5;
    
    sys->ef.flg = 1;
    
    sys->ef.type = (char)(type & 0xFF);
    
    sys->ef.px = sys->ef.py = sys->ef.pz = 0;
    
    sys->ef.sx = 2.0f;
    sys->ef.sy = 2.0f;
    sys->ef.sz = 2.0f;
    
    sys->ef.ay = 0;
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, jno);
}

// 100% matching!
void bhEne_SetBloodEffect4(NJS_POINT3* pos, NJS_POINT3* vec, int col, int type1, int type2)
{
    bhSetEffParticleMk2(NULL, 0, pos, vec, BloodCol[col][0], BloodCol[col][1], type1);
    
    sys->ef.id = 5;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type2 & 0xFF;
    
    sys->ef.mdlver = col;
    
    sys->ef.px = pos->x;
    sys->ef.py = pos->y;
    sys->ef.pz = pos->z;
    
    sys->ef.sx = 2.0f;
    sys->ef.sy = 2.0f;
    sys->ef.sz = 2.0f;
    
    sys->ef.ay = 0;
    
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
}

// 100% matching!
void bhEne_SetBloodEffect5(BH_PWORK* epw, int type1, int type2)
{
    NJS_POINT3 ofp; 
    NJS_POINT3 vec; 

    ofp.x = epw->dpx - epw->mlwP->owP[epw->djnt_no].mtx[12];
    ofp.y = epw->dpy - epw->mlwP->owP[epw->djnt_no].mtx[13];
    ofp.z = epw->dpz - epw->mlwP->owP[epw->djnt_no].mtx[14];
    
    njSetMatrix(NULL, (NJS_MATRIX*)epw->mlwP->owP[epw->djnt_no].mtx);
    njInvertMatrix(NULL);
    
    njCalcVector(NULL, &ofp, &ofp);
    
    vec.x = -epw->dvx;
    vec.y = -epw->dvy;
    vec.z = -epw->dvz;
    
    bhSetEffParticleMk2(epw, epw->djnt_no, &ofp, &vec, BloodCol[BloodType[epw->id].color][0], BloodCol[BloodType[epw->id].color][1], type1);
    
    sys->ef.id = 5;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type2;
    
    sys->ef.pz = 0;
    sys->ef.py = 0;
    sys->ef.px = 0;
    
    sys->ef.sx = 2.0f;
    sys->ef.sy = 2.0f;
    sys->ef.sz = 2.0f;
    
    sys->ef.ay = 0;
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    bhSetEffectTb(&sys->ef, &ofp, (unsigned char*)epw, epw->djnt_no);
}

// 100% matching!
void bhEne_SetBloodEffectBurst(BH_PWORK* epw, int type, int jno, NJS_POINT3* pos, int flg)
{   
    int eno;
    O_WRK* op; 
    NJS_POINT3 ofp; 

    if (pos == NULL) 
    {
        ofp.z = 0;
        ofp.y = 0;
        ofp.x = 0;
    }
    else 
    {
        ofp = *pos; 
    }
    
    if (flg != 0) 
    {   
        njSubVector(&ofp, (NJS_VECTOR*)&epw->mlwP->owP[jno].mtx[12]);
        
        njSetMatrix(NULL, (NJS_MATRIX*)epw->mlwP->owP[jno].mtx);
        njInvertMatrix(NULL);
        
        njCalcVector(NULL, &ofp, &ofp);
    }
    
    sys->ef.id = 297;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type;
    
    sys->ef.pz = 0;
    sys->ef.py = 0;
    sys->ef.px = 0;
    
    sys->ef.sx = 1.0f;
    sys->ef.sy = 1.0f;
    sys->ef.sz = 1.0f;
    
    sys->ef.ay = 0;
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    eno = bhSetEffectTb(&sys->ef, &ofp, (unsigned char*)epw, jno);
    
    if (eno != -1) 
    {
        op = &eff[eno];
        
        op->xn = -epw->dvx;
        op->yn = -epw->dvy;
        op->zn = -epw->dvz;
    }
}

// 100% matching!
void bhEne_SetBloodstain(BH_PWORK* epw, int type, int jno, NJS_POINT3* ofp)
{
    NJS_POINT3 pos; 
    float d; 

    if (jno < 0)
    {
        if (ofp != NULL) 
        {
            pos = *ofp;
        } 
        else 
        {
            *(NJS_POINT3*)&pos = *(NJS_POINT3*)&epw->px;
        }
    }
    else if (ofp != NULL)
    {
        njSetMatrix(NULL, (NJS_MATRIX*)epw->mlwP->owP[jno].mtx);

        njCalcPoint(NULL, ofp, &pos);
    } 
    else 
    {
        *(NJS_POINT3*)&pos = *(NJS_POINT3*)&epw->mlwP->owP[jno].mtx[12];
    }
    
    sys->ef.id = 301;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type;
    
    sys->ef.px = pos.x;
    sys->ef.py = pos.y;
    sys->ef.pz = pos.z;
    
    sys->ef.sx = 1.0f;
    sys->ef.sy = 1.0f;
    sys->ef.sz = 1.0f;
    
    sys->ef.mdlver = BloodType[epw->id].color;
    
    sys->ef.ax = bhArcTan2(epw->dvy, njSqrt((epw->dvx * epw->dvx) + (epw->dvz * epw->dvz)));
    sys->ef.ay = bhArcTan2(-epw->dvx, -epw->dvz);
    
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
}

// 100% matching!
void bhEne_SetFireEffect(BH_PWORK* epw, int jno, NJS_POINT3* ofp, float size, int len)
{
    NJS_POINT3 org = { 0 }; 
    int eno; 
    
    if (ofp == NULL) 
    {
        ofp = &org;
    }
    
    sys->ef.id = 252;
    
    sys->ef.flg = 1;
    
    sys->ef.type = 0;
    
    sys->ef.pz = 0;
    sys->ef.py = 0;
    sys->ef.px = 0;
    
    sys->ef.sx = size;
    sys->ef.sy = size;
    sys->ef.sz = 1.0f;
    
    sys->ef.ay = 0;
    
    sys->ef.mdlver = 0;
    
    eno = bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, jno);
    
    if (eno != -1) 
    {
        eff[eno].ct0 = len;
    }
}

// 100% matching!
void bhEne_BloodPool(BH_PWORK* epw, NJS_POINT3* pos, int ang, BP_WORK* param)
{
    bhSetBloodPoolLnk(epw, pos, ang, param, BloodType[epw->id].color);
}

// 100% matching!
void bhEne_SetAcidEffect(BH_PWORK* epw, int jno, NJS_POINT3* ofp, float size)
{
    NJS_POINT3 org = { 0 };
    
    if (ofp == NULL) 
    {
        ofp = &org;
    }
    
    sys->ef.id = 298;
    
    if (jno >= 0) 
    {
        sys->ef.flg = 0x81;
    }
    else 
    {
        sys->ef.flg = 1;
    }
    
    sys->ef.type = 20;
    
    sys->ef.pz = 0;
    sys->ef.py = 0;
    sys->ef.px = 0;
    
    sys->ef.sx = size;
    sys->ef.sy = size;
    sys->ef.sz = size;
    
    sys->ef.ay = 0;
    
    bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, jno);
}

// 100% matching!
int bhEne_DirTarget(BH_PWORK* epw, float x, float z, int w)
{
    int ang;

    ang = bhArcTan2(epw->px - x, epw->pz - z);
    ang = (short)(ang - epw->ay);
    
    if (w < abs(ang))
    {
        ang = (ang > 0) ? w : -w;
    }
    
    return ang;
}

// 100% matching!
int bhEne_CheckDirTarget(BH_PWORK* epw, float x, float z, int w)
{
    int ang;

    ang = bhArcTan2(epw->px - x, epw->pz - z);
    ang = (short)(ang - epw->ay);

    if ((ang > w) || (ang < -w))
    {
        return 0;
    }

    return 1;
}

// 100% matching!
void bhEne_GetPartsPos(BH_PWORK* epw, char* parts, NJS_POINT3* p)
{
    ML_WORK* mlwP;
    NJS_CNK_OBJECT* objP; 

    mlwP = epw->mlwP;
    
    njPushMatrixEx();
    
    njUnitMatrix(NULL);
    
    njTranslateEx((NJS_VECTOR*)&epw->px);
    njRotateEx(&epw->ax, 0);
    
    while (*parts != -1) 
    {
        objP = &mlwP->objP[*parts++];
        
        njTranslateEx((NJS_VECTOR*)objP->pos);
        njRotateEx(objP->ang, 0);
    }
    
    njGetTranslation(NULL, p);
    
    njPopMatrixEx();
}

// 100% matching!
int bhEne_DirCheck(int ay, NJS_VECTOR* vec)
{
    NJS_VECTOR v;    
    int ang; // not from DWARF

    njUnitMatrix(NULL);
    
    njRotateY(NULL, -ay);
    
    njCalcVector(NULL, vec, &v);
    
    ang = 1;
    
    if (v.z >= 0) 
    {
        ang = 0;
    }
    
    return ang;
}

// 100% matching!
int bhEne_DGDirCheck(BH_PWORK* epw)
{
    return bhEne_DirCheck(epw->ay, (NJS_VECTOR*)&epw->dvx);
}

// 100% matching!
void bhEne_CallPlayerVoice(int no)
{
    no |= 0x400;
    
    CallPlayerVoice(no);
}

// 100% matching!
void bhEne_CheckEnemiesBall(BH_PWORK* epw)
{
    BH_PWORK* epp;
    float px, py, pz; 
    float ln; 
    float ex0, ey0, ez0; 
    float ex1, ey1, ez1; 
    float ex2, ey2, ez2; // not from DWARF
    float r; 
    int i; 

    if (!(epw->flg2 & 0x1)) 
    {
        px = epw->px + epw->aox;
        py = epw->py + epw->aoy;
        pz = epw->pz + epw->aoz;

        epp = ene;
        
        for (i = 0; i < sys->ewk_n; i++, epp++)
        {
            if ((((epp->flg & 0x1)) && ((epp->flg & 0x8))) && (epw != epp) && ((epw != plp) || ((epp->flg & 0x40))))
            {
                ex0 = epp->px + epp->aox;
                ey0 = epp->py + epp->aoy;
                ez0 = epp->pz + epp->aoz;

                ex1 = px - ex0;
                ey1 = py - ey0;
                ez1 = pz - ez0;
                
                ln = njSqrt((ex1 * ex1) + (ey1 * ey1) + (ez1 * ez1));
                
                r = epw->car + epp->car;
                
                if (ln < r) 
                {
                    r = (1.0f / ln) * r;
                    
                    ex2 = ex0 - px; 
                    ey2 = ey0 - py; 
                    ez2 = ez0 - pz; 
                    
                    epw->px = (ex0 - (ex2 * r)) - epw->aox;
                    epw->py = (ey0 - (ey2 * r)) - epw->aoy;
                    epw->pz = (ez0 - (ez2 * r)) - epw->aoz;
                    
                    if (epw == plp)
                    {
                        epp->stflg |= 0x4;
                    } 
                    else 
                    {
                        epp->stflg |= 0x2;
                    }
                }
            }
        }
    }
}

// 100% matching!
void bhEne_SetWeponAtr(BH_PWORK* epw, char j1, char j2, float r)
{
    O_WORK* owk;

    owk = &epw->mlwP->owP[j1];
    
    epw->watr.c1.x = owk->mtx[12];
    epw->watr.c1.y = owk->mtx[13];
    epw->watr.c1.z = owk->mtx[14];
    
    owk = &epw->mlwP->owP[j2];
    
    epw->watr.c2.x = owk->mtx[12];
    epw->watr.c2.y = owk->mtx[13];
    epw->watr.c2.z = owk->mtx[14];
    
    epw->watr.r = r;
}

// 100% matching!
unsigned char bhEne_AttackHitCheck(BH_PWORK* pl, NJS_POINT3* pos, float ar)
{
    NJS_POINT3 vec; 
    float ll; 
    float knr; 
    int i; 
    int kno; 
    NJS_SPHERE sphere; 

    kno = -1;
    
    sphere.c.x = pos->x;
    sphere.c.y = pos->y;
    sphere.c.z = pos->z;
    
    sphere.r = ar;
    
    if (npCollisionCheckSC(&sphere, &pl->watr) != 0)
    {
        ll = ar * ar;
        
        for (i = 0; i < (int)pl->mlwP->obj_num; i++)
        {
            vec.x = pos->x - pl->mlwP->owP[i].mtx[12];
            vec.y = pos->y - pl->mlwP->owP[i].mtx[13];
            vec.z = pos->z - pl->mlwP->owP[i].mtx[14];
            
            knr = njScalor2(&vec);
            
            if (ll > knr) 
            {
                ll = knr;
                
                kno = i;
                
                pl->dvx = -vec.x;
                pl->dvy = -vec.y;
                pl->dvz = -vec.z;
            }
        }
    }
    
    if (kno >= 0)
    {
        pl->djnt_no = kno;
        
        pl->dpx = pos->x;
        pl->dpy = pos->y;
        pl->dpz = pos->z;

        return 1;
    }
    
    return 0;
}

// 100% matching!
void bhEne_AddNullTrans(BH_PWORK* epw, NJS_VECTOR* mtn)
{
    NJS_VECTOR v; 

    njUnitMatrix(NULL);
    
    njRotateY(NULL, epw->ay);
    
    njCalcVector(NULL, &mtn[epw->frm_no / 65536], &v);
    
    epw->px += v.x;
    epw->pz += v.z;
}

// 100% matching!
void bhEne_AddNullTransDir(BH_PWORK* epw, int ay, NJS_POINT3* mtn)
{
    NJS_VECTOR v; 

    njUnitMatrix(NULL);
    
    njRotateY(NULL, ay);
    
    njCalcVector(NULL, &mtn[epw->frm_no / 65536], &v);
    
    epw->px += v.x;
    epw->pz += v.z;
}

// 100% matching!
float bhEne_GetShapeCnt(P_WORK* p, int key)
{   
    P_WORK* pp;
  
    while (TRUE)
    {
        pp = p;
        
        if (key <= pp->key) 
        {
            break;
        }
        
        p++;
    }
    
    if (pp->key == key)
    {
        return p->cnt;
    }
    else
    {
        return p[-1].cnt + (((p->cnt - p[-1].cnt) * (key - p[-1].key)) / (pp->key - p[-1].key));
    }
}

// 100% matching!
void bhEne_CalcDamage(BH_PWORK* epw, COMBWEP_WORK* CombWepTbl, COMBJOINT_WORK* CombJointTbl)
{
    int dam; 
    unsigned int i; 
    COMBJOINT_WORK* cjp; 
    COMBWEP_WORK* cwp; 

    cjp = CombJointTbl;
    
    cwp = &CombWepTbl[epw->wpnr_no];

    epw->comb_flg &= ~0xD;
    
    epw->total_dam = 0;
    
    for (i = 0; i < epw->mlwP->obj_num; i++, cjp++)
    {
        if ((i != 0) && (epw->dam[i] != 0))
        {
            if (!(cjp->flg & 0x1)) 
            {
                if ((epw->comb_wep == epw->wpnr_no) && (epw->comb_timeout != 0)) 
                {
                    epw->comb_timeout = cwp->timeout;
                } 
                else 
                {
                    epw->comb_wep = epw->wpnr_no;
                    
                    epw->comb_pnt = 0;
                    
                    epw->comb_timeout = cwp->timeout;
                }
                
                if ((epw->comb_flg & 0x10)) 
                {
                    epw->comb_pnt += cwp->pt[0];
                }
                
                if ((epw->comb_flg & 0x20)) 
                {
                    epw->comb_pnt += cwp->pt[1];
                }
                
                if ((epw->comb_flg & 0x40)) 
                {
                    epw->comb_pnt += cwp->pt[2];
                }
            }
            
            if ((cwp->crit != 0) && (epw->comb_pnt >= cwp->crit))
            {
                epw->comb_flg |= 0x1;
                
                if (!(epw->comb_flg & 0x2)) 
                {
                    epw->comb_pnt = 0;
                }
                
                dam = epw->dam[i] + ((epw->dam[i] * (cwp->bonus + cjp->correct)) / 100);
            } 
            else 
            {
                dam = epw->dam[i] + ((epw->dam[i] * cjp->correct) / 100);
            }
            
            epw->total_dam += dam;
        }
    }
    
    if (bhEne_DGDirCheck(epw) != 0) 
    {
        epw->comb_flg |= 0x8;
    }
    else 
    {
        epw->comb_flg |= 0x4;
    }
}

// 100% matching!
void bhEne_InitDamage(BH_PWORK* epw)
{
    int i;

    if (epw->mlwP != NULL) 
    {
        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            epw->dam[i] = 0;
        }
    }
    
    if (epw->comb_timeout != 0)
    {
        epw->comb_timeout--;
    }
    
    epw->comb_flg &= ~0x70;
    epw->flg2 &= ~0x4;
}

/*// 
// Start address: 0x21aba0
void bhEne_CallSE(BH_PWORK* epw, _anon6* pos, int se)
{
	// Line 1005, Address: 0x21aba0, Func Offset: 0
	// Line 1006, Address: 0x21aba8, Func Offset: 0x8
	// Line 1007, Address: 0x21abbc, Func Offset: 0x1c
	// Line 1009, Address: 0x21abd4, Func Offset: 0x34
	// Func End, Address: 0x21abe0, Func Offset: 0x40
}

// 
// Start address: 0x21abe0
void bhEne_CallSE_EX(BH_PWORK* epw, _anon6* pos, int se, int fade)
{
	// Line 1021, Address: 0x21abe0, Func Offset: 0
	// Line 1022, Address: 0x21abe8, Func Offset: 0x8
	// Line 1023, Address: 0x21abfc, Func Offset: 0x1c
	// Line 1025, Address: 0x21ac14, Func Offset: 0x34
	// Func End, Address: 0x21ac20, Func Offset: 0x40
}

// 
// Start address: 0x21ac20
void bhEne_CallEffectSE(_anon6* pos, int se)
{
	// Line 1037, Address: 0x21ac24, Func Offset: 0x4
	// Func End, Address: 0x21ac30, Func Offset: 0x10
}

// 
// Start address: 0x21ac30
void bhEne_SetSEPan(_anon6* pos, int se)
{
	// Line 1051, Address: 0x21ac30, Func Offset: 0
	// Func End, Address: 0x21ac50, Func Offset: 0x20
}

// 
// Start address: 0x21ac50
int bhEne_CheckPlayEffectSE(int se)
{
	// Line 1063, Address: 0x21ac54, Func Offset: 0x4
	// Func End, Address: 0x21ac5c, Func Offset: 0xc
}*/

// 
// Start address: 0x21ac60
int bhArcTan2(float y, float x)
{
	int ang;
	float len;
	// Line 1075, Address: 0x21ac60, Func Offset: 0
	// Line 1079, Address: 0x21ac74, Func Offset: 0x14
	// Line 1080, Address: 0x21ac84, Func Offset: 0x24
	// Line 1082, Address: 0x21aca4, Func Offset: 0x44
	// Line 1084, Address: 0x21acd4, Func Offset: 0x74
	// Line 1085, Address: 0x21acec, Func Offset: 0x8c
	// Line 1094, Address: 0x21acfc, Func Offset: 0x9c
	// Func End, Address: 0x21ad10, Func Offset: 0xb0
	scePrintf("bhArcTan2 - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x21ad10
_anon21* bhEne_CheckEventAtr(int flr_no, float px, float pz, int id, int min, int max)
{
	int flr_n;
	int i;
	_anon21* fp;
	// Line 1113, Address: 0x21ad10, Func Offset: 0
	// Line 1114, Address: 0x21ad34, Func Offset: 0x24
	// Line 1117, Address: 0x21ad44, Func Offset: 0x34
	// Line 1116, Address: 0x21ad48, Func Offset: 0x38
	// Line 1117, Address: 0x21ad84, Func Offset: 0x74
	// Line 1122, Address: 0x21adc8, Func Offset: 0xb8
	// Line 1125, Address: 0x21ae2c, Func Offset: 0x11c
	// Line 1128, Address: 0x21ae34, Func Offset: 0x124
	// Line 1129, Address: 0x21ae48, Func Offset: 0x138
	// Line 1130, Address: 0x21ae4c, Func Offset: 0x13c
	// Func End, Address: 0x21ae54, Func Offset: 0x144
}

// 
// Start address: 0x21ae60
void bhEne_EraseArrow(BH_PWORK* epw, int obj_no)
{
	_anon0* op;
	int i;
	// Line 1145, Address: 0x21ae60, Func Offset: 0
	// Line 1146, Address: 0x21ae68, Func Offset: 0x8
	// Line 1148, Address: 0x21ae6c, Func Offset: 0xc
	// Line 1147, Address: 0x21ae70, Func Offset: 0x10
	// Line 1148, Address: 0x21ae8c, Func Offset: 0x2c
	// Line 1151, Address: 0x21aeb0, Func Offset: 0x50
	// Line 1153, Address: 0x21aeb4, Func Offset: 0x54
	// Line 1154, Address: 0x21aeb8, Func Offset: 0x58
	// Line 1155, Address: 0x21aec8, Func Offset: 0x68
	// Func End, Address: 0x21aed0, Func Offset: 0x70
}*/
