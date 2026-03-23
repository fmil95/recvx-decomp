#include "zonzon.h"
#include "effect.h"
#include "effsub3.h"
#include "hitchk.h"
#include "ps2_NaMath.h"
#include "ps2_NinjaCnk.h"
#include "main.h"

// 100% matching! 
void ikou(BH_PWORK* epw, NJS_POINT3* pos, int add_dir)
{
	int ang;
	int rot;

    if ((epw->flg & 0x80) != 0)
    {
        return;
    }
    
    ang = NitenDir_ck(epw->px, epw->pz, pos->x, pos->z);
    if ((add_dir & 0x80000000) != 0) 
    {
        add_dir = -add_dir;
        ang = ang + 0x8000 & 0xffff;
    }

    rot = add_dir + (ang - epw->ay) & 0xffff;

    if (rot < (add_dir + add_dir))
    {
        epw->ay = ang;
    }
    else 
    {
        epw->ay -= add_dir;
        
        if (rot <= 0x8000)
        {
            epw->ay += (add_dir + add_dir);
        }
    }
}

// 100% matching!
int ikou3(BH_PWORK* epw, NJS_POINT3* pos, int add_dir)
{
    int rot;

    if((epw->flg & 0x80) != 0) 
    {
        return 0;
    }

    rot = NitenDir_ck(epw->px, epw->pz, pos->x, pos->z);
    rot = add_dir + (rot - epw->ay) & 0xffff;
    if ((int)rot < add_dir + add_dir) 
    {
        return 0;
    }
    
    if (rot < 0x8001) 
    {
        return add_dir;
    }
    
    return -add_dir;
}

// 100% matching!
int NitenDir_ck(float hontai_x, float hontai_z, float target_x, float target_z) 
{
    return atan2f(hontai_x - target_x, hontai_z - target_z) * 10430.381f;
}

// 100% matching!
int bhCdirCheck(int my_ang, int trg_ang) 
{    
   return (((my_ang - trg_ang) + 0x4000) & 0xffff) < 0x8000 ? 1 : 0;
}

// 100% matching!
int bhEne_LeverCheck() 
{
    int dec_cnt;
    
    dec_cnt = 0;

    if ((sys->pad_ps & 0xf) != 0)
    {
        dec_cnt = 4;
    }
    
    if ((sys->pad_ps & 0x2d00) != 0) 
    {
        dec_cnt += 3;
    }
    return dec_cnt;
}

// 100% matching!
int bhDGCdirCheck(NJS_VECTOR* dv, int rot) 
{
    NJS_VECTOR v1;
    NJS_VECTOR v0;
    
    v1.x = -njSin(rot);
    v1.z = -njCos(rot);
    v1.y = 0;

    v0.x = dv->x;
    v0.y = dv->y;
    v0.z = dv->z;
    
    njUnitVector(&v0);

    if (njInnerProduct(&v1, &v0) < 0.0f) 
    {
        return 0;
    }

    return 1;
}

// 100% matching!
int bhDGCdirCheck2(NJS_VECTOR* dv, O_WORK* owk)
{
    NJS_VECTOR v0;
    NJS_VECTOR v1;

    v1.x = 0;
    v1.y = 0;
    v1.z = -1.0f;

    njCalcVector((NJS_MATRIX*)owk->mtx, &v1, &v0);
    
    v1.x = dv->x;
    v1.y = dv->y;
    v1.z = dv->z;
    
    njUnitVector(&v1);
    
    if (njInnerProduct(&v0, &v1) < 0.0f) 
    {
        return 0;
    }
    return 1;
}

// 100% matching!
int bhDGCdirCheck3(NJS_VECTOR* dv, int rot) 
{
    int ang; // r2

    ang = ((int) (atan2f(dv->x, dv->z) * 10430.381f) - rot) & 0xffff;

    if ((ang < 0x2000) || (ang >= 0xE000))
    {
        return 0;
    }
    
    if ((ang >= 0x2000) && (ang < 0x6000))
    {
        return 1;
    }

    if (((ang >= 0x6000)) && (ang < 0xa000))
    {
        return 2;
    }
    
    if ((ang >= 0xA000) && (ang < 0xE000))
    {
        return 3;
    }

    return 3;
}

// 100% matching!
int bhEne_AngleCheck(NJS_VECTOR* vec, int rot, int chk_ang) {
    float n2;
    float n1; // Unused
    NJS_VECTOR v3;
    NJS_VECTOR v2;
    NJS_VECTOR v1;

    v3.x = 0;
    v3.y = 0;
    v3.z = -1.0f;
    
    njUnitMatrix(0);
    njRotateY(0, chk_ang);
    njCalcVector(0, &v3, &v2);
    njUnitMatrix(0);
    njRotateY(0, rot + 0x7FFF + 1);
    njCalcVector(0, &v3, &v1);
    njUnitVector(vec);
    n2 = njInnerProduct(&v3, &v2);

    if (njInnerProduct(vec, &v1) > n2) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
void bhEne_GetTranslateMtn(BH_PWORK* epw, int frm, int mode)
{
    NJS_MKEY* mkfP;    
    MN_WORK* mtnp; // not from DWARF
    NJS_POINT3 key; 

    mtnp = &epw->mnwP[epw->mtn_no];
    
    mkfP = (void*)&((NJS_POINT3*)mtnp->md2P->p[0])[frm];
    
    if ((epw->mtn_add != 0) || ((epw->frm_no / 65536) != frm)) 
    {
        if (frm == 0) 
        {
            key.x = mkfP->key[0];
            key.y = mkfP->key[1];
            key.z = mkfP->key[2];
        }
        else 
        {
            key.x = mkfP->key[0] - mkfP->key[-3];
            key.y = mkfP->key[1] - mkfP->key[-2];
            key.z = mkfP->key[2] - mkfP->key[-1];
        }
        
        if (mode == 0) 
        {
            key.y = 0;
        }
        
        njUnitMatrix(NULL);
        
        njTranslate(NULL, epw->px, epw->py, epw->pz);
        njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
        
        njCalcPoint(NULL, (NJS_POINT3*)&key, (NJS_POINT3*)&epw->px);
        
        epw->py = (int)(100.0f * (0.001f + epw->py)) / 100.0f;
    }
}

// 100% matching!
void bhEne_GetTranslateMtn2(BH_PWORK* epw, int frm, int mode)
{
    NJS_MKEY* mkfP;    
    MN_WORK* mtnp; // not from DWARF
    NJS_POINT3 key; 

    mtnp = &epw->mnwP[epw->mtn_no];
    
    mkfP = (void*)&((NJS_POINT3*)mtnp->md2P->p[0])[frm];
    
    if ((epw->mtn_add != 0) || ((epw->frm_no / 65536) != frm)) 
    {
        if (frm == 0) 
        {
            key.x = mkfP->key[0];
            key.y = mkfP->key[1];
            key.z = mkfP->key[2];
        }
        else 
        {
            key.x = mkfP->key[0] - mkfP->key[-3];
            key.y = mkfP->key[1] - mkfP->key[-2];
            key.z = mkfP->key[2] - mkfP->key[-1];
        }
        
        if (mode == 0) 
        {
            key.y = 0;
        }
        
        epw->spd = njScalor(&key);
    }
}

// 100% matching!
void bhEne_CalcPartsPos(BH_PWORK* epw, NJS_MATRIX* mtx, NJS_POINT3* pos, char* tree, int parts_num, int clr_flg)
{   
    NJS_CNK_OBJECT* obj;
    int i; 
        
    if (clr_flg != 0)
    {
        njUnitMatrix(mtx);
        
        njTranslate(mtx, epw->px, epw->py, epw->pz);
        njRotateXYZ(mtx, epw->ax, epw->ay, epw->az);
    }

    for (i = 0; i < parts_num; i++, tree++) 
    {
        obj = &epw->mlwP->objP[*tree];
        
        njTranslate(mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
        njRotateXYZ(mtx, obj->ang[0], obj->ang[1], obj->ang[2]);
    }

    njGetTranslation(mtx, pos);
}

ATR_WORK* bhKaidanAtrCheck(BH_PWORK* epw, float len, int* idx)
{
    ATR_WORK* exp;
    float px, px2; 
    float pz, pz2; 
    int i; 
    int etc_n; 

    px = epw->px - (len * njSin(epw->ay));
    pz = epw->pz - (len * njCos(epw->ay));
    
    etc_n = rom->etc_n + sys->metc_n;
    
    for (i = 0; i < etc_n; i++)
    {
        if (i < rom->etc_n) 
        { 
            exp = &rom->etcp[i]; 
        }
        else 
        { 
            exp = &sys->metcp[i - rom->etc_n]; 
        }

        if ((exp->flg & 0x1))
        {
            switch (exp->type)
            {
            case 1:
                if (((exp->px <= px) && ((exp->px + exp->w) >= px)) && ((exp->pz <= pz) && ((exp->pz + exp->d) >= pz)) && (!(exp->attr & 0x400000)) && (exp->flr_no == epw->flr_no))
                {   
                    px = 0.5f + exp->px;
                    pz = 0.5f + exp->pz;
                    
                    px2 = (exp->px + exp->w) - 0.5f;
                    pz2 = (exp->pz + exp->d) - 0.5f;
                    
                    if ((exp->prm1 == 0) || (exp->prm1 == 2))
                    {
                        if ((px <= epw->px) && (px2 >= epw->px))
                        {
                            *idx = i;
                            
                            return exp;
                        }
                    }
                    else if ((pz <= epw->pz) && (pz2 >= epw->pz))
                    {
                        *idx = i;
                        
                        return exp;
                    }
                }
                
                break;
            }
        }
    }
    
    return NULL;
}

// 100% matching!
ATR_WORK* bhEne_EnemyAtariCheck(NJS_POINT3* pos, int flr_no, unsigned char id, unsigned char type) 
{
    ATR_WORK* fp;
    int i; 
    int flr_n; 

    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++) 
    {
        if (rom->flr_n > i)
        {
            fp = rom->flrp + i;
        }
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if (((fp->flg & 0x1)) && (fp->type == 2) && (bhEne_PosCheck(pos->x, pos->z, fp->px, fp->pz, fp->w, fp->d) != 0) && (fp->flr_no == flr_no) && ((fp->prm0 == id) && (fp->prm1 == type))) 
        {
            return fp;
        }
    }

    return NULL;
}

// 100% matching!
int bhEne_PosCheck(float px, float pz, float x, float z, float w, float h)
{
    if (x <= px) 
	{
        if (!((x + w) < px) && (z <= pz) && !((z + h) < pz)) 
		{
            return 1;
        }
    }
    return 0;
}

// 100% matching!
void bhEne_SetBlood(BH_PWORK* epw, unsigned char type, BT_WORK* bt)
{
    O_WORK* owk; 
    NJS_POINT3 ofp; 
    NJS_POINT3 ps; 
    int fhit;
    BT_WORK* btp; // not from DWARF

    fhit = 0;
    
    owk = &epw->mlwP->owP[epw->djnt_no];
    
    if ((bt == NULL) || ((epw->wpnr_no == 13) || (epw->wpnr_no == 10)))
    {
        ps.x = epw->dpx - owk->mtx[12];
        ps.y = epw->dpy - owk->mtx[13];
        ps.z = epw->dpz - owk->mtx[14];
        
        njSetMatrix(NULL, &owk->mtx);
        njInvertMatrix(NULL);
        
        njCalcVector(NULL, &ps, &ofp);
    } 
    else 
    {
        if (bhDGCdirCheck2((NJS_VECTOR*)&epw->dvx, owk) == 0)
        {
            fhit = 1;
        }
        
        btp = &bt[epw->djnt_no];
        
        ofp.x = btp->x + (btp->xlen - ((2.0f * btp->xlen) * (-rand() / -2.1474836E9f)));
        ofp.y = btp->y + (btp->ylen - ((2.0f * btp->ylen) * (-rand() / -2.1474836E9f)));
        
        if (fhit != 0) 
        {
            ofp.z = -btp->z;
        }
        else 
        {
            ofp.z = btp->z;
        }
        
        epw->djnt_no = btp->lnk_obj;
    }
    
    bhEne_SetBlood2(epw, type, &ofp, plp->way);
}

// 100% matching!
void bhEne_SetBlood2(BH_PWORK* epw, unsigned char type, NJS_POINT3* ofp, short ry)
{
    unsigned int bl_color;
    O_WRK* op; 
    
    sys->ef.flg = 1;
    
    sys->ef.px = 0;
    sys->ef.py = 0;
    sys->ef.pz = 0;
    
    sys->ef.sx = 1.5f;
    sys->ef.sy = 1.5f;
    sys->ef.sz = 0;
    
    sys->ef.ay = 0;
    
    if (epw->id == 17)
    {
        bl_color = 0xFFFFFFFFFF400000;
        
        sys->ef.mdlver = 3;
    }
    else 
    {
        bl_color = 0xFFFFFFFFFF5F0000;
        
        sys->ef.mdlver = 0;
    }
    
    switch (type)
    {
    case 0:
    case 1:
    case 2:
        sys->ef.id = 5;
        
        sys->ef.type = type;
        
        if (type == 2) 
        {
            sys->ef.sx = 3.0f;
            sys->ef.sy = 3.0f;
            sys->ef.sz = 0;
        }
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
        break;
    case 3: 
    {
        NJS_POINT3 ps;
        
        sys->ef.id = 5;
        
        sys->ef.flg = 1;
        
        sys->ef.type = 0;
        
        sys->ef.sx = 1.5f;
        sys->ef.sy = 1.5f;
        sys->ef.sz = 0;
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
        
        ps.x = -epw->dvx;
        ps.y = -epw->dvy;
        ps.z = -epw->dvz;
        
        ofp->z = 0;
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, &ps, bl_color, 0);
        break;
    }
    case 4:
        epw->dvx = -njSin(ry);
        epw->dvy = njSin(10922);
        epw->dvz = -njCos(ry);
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, (NJS_POINT3*)&epw->dvx, bl_color, 1);
        break;
    case 5:
        sys->ef.id = 5;
        
        sys->ef.type = 2;
        
        sys->ef.sx = 3.0f;
        sys->ef.sy = 3.0f;
        sys->ef.sz = 0;
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
        break;
    case 6:
        sys->ef.sx = 1.5f;
        sys->ef.sy = 1.5f;
        sys->ef.sz = 0;
        
        sys->ef.id = 5;
        
        sys->ef.type = 1;
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
        
        epw->dvx = -njSin(ry);
        epw->dvy = njSin(10922);
        epw->dvz = -njCos(ry);
        
        ofp->z = 0;
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, (NJS_POINT3*)&epw->dvx, bl_color, 3);
        break;
    case 7: 
    {
        NJS_POINT3 ps;
        
        sys->ef.id = 5;
        
        sys->ef.flg = 1;
        
        sys->ef.type = 0;
        
        sys->ef.sx = 1.5f;
        sys->ef.sy = 1.5f;
        sys->ef.sz = 0;
        
        bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
            
        ps.x = -epw->dvx;
        ps.y = -epw->dvy;
        ps.z = -epw->dvz;
        
        ofp->z = 0;
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, &ps, bl_color, 8);
        break;
    }
    case 8: 
    {
        NJS_POINT3 ps;
        
        ps.x = -epw->dvx;
        ps.y = -epw->dvy;
        ps.z = -epw->dvz;
        
        ofp->z = 0;
        
        bhSetEffParticle(epw, epw->djnt_no, ofp, &ps, bl_color, 13);
        break;
    }
    case 10:
        ofp->z = 0;
        
        bhEne_SetBlood4(epw, epw->djnt_no, ofp, 0, 2);
        break;
    case 11:
        epw->dvx = -njSin(ry);
        epw->dvy = njSin(10922);
        epw->dvz = -njCos(ry);
        
        ofp->z = 0;
        
        op = bhSetEffParticle(epw, epw->djnt_no, ofp, (NJS_POINT3*)&epw->dvx, 0xFFFFFFFFFF9F0000, 18);
        
        op->mode1 = 1;
        break;
    }
}

// 100% matching!
void bhEne_SetBlood3(BH_PWORK* epw, int lnk_obj, NJS_POINT3* ofs, NJS_POINT3* dv, int n, int tex_id, int type, int wcnt) 
{   
    int eno;

    sys->ef.id = 370;
    
    sys->ef.flg = 1;
    
    sys->ef.type = type;
    
    sys->ef.sx = 3.5f;
    sys->ef.sy = 3.5f;
    sys->ef.sz = 0;
    
    if (lnk_obj != -1) 
    {
        sys->ef.px = 0;
        sys->ef.py = 0;
        sys->ef.pz = 0;
        
        eno = bhSetEffectTb(&sys->ef, ofs, (unsigned char*)epw, lnk_obj);
    } 
    else 
    {
        sys->ef.px = ofs->x;
        sys->ef.py = ofs->y;
        sys->ef.pz = ofs->z;
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
    
    if (eno != -1) 
    {
        eff[eno].stflg |= 0x20;
        
        eff[eno].txp[0] = epw->mlwP->texP;
        
        eff[eno].tex_id = tex_id;
        
        eff[eno].xn = dv->x;
        eff[eno].yn = dv->y;
        eff[eno].zn = dv->z;
        
        eff[eno].ct0 = wcnt;
        eff[eno].ct1 = n;
    }
}

// 100% matching!
void bhEne_SetBlood4(BH_PWORK* epw, int lnk_obj, NJS_POINT3* ofs, int tex_id, int type)
{
    BT_WRK* tbl; 
    NJS_POINT3 ps; 
    NJS_POINT3 v; 
    int ang; // DWARF has this variable placed below angY 
    int angY;  
    int i; 
    static BT_WRK bld_tbl[20] = // TODO: match this to 100%, the signed zeroes are causing trouble
    {
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00002000, 4, 2 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0xFFFFE000, 4, 2 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00000004, 0, 0 },
        { { -0.0f,  0.0f, 0.0f }, 0xFFFFF000, 4         , 0, 0 },
        { {  0.2f,  0.0f, 0.0f }, 0x00002000, 0x00000000, 4, 3 },
        { {  0.0f, -0.2f, 0.0f }, 0x00000000, 4         , 3, 0 },
        { {  0.2f,  0.0f, 0.0f }, 0x00002000, 0x00009000, 4, 6 },
        { {  0.0f, -0.2f, 0.0f }, 0xFFFFF000, 0x00008000, 4, 7 },
        { {  0.0f,  0.2f, 0.0f }, 0x00002000, 0x00007000, 4, 8 },
        { {  0.0f,  0.0f, 0.0f }, 0x00000000, 0xFFFFFFFF, 0, 0 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00000800, 8, 1 },
        { {  0.0f, -0.0f, 0.0f }, 0x00001000, 0xFFFFF800, 8, 1 },
        { {  0.0f,  0.0f, 0.0f }, 0x00002000, 0x00000000, 8, 0 },
        { {  0.0f,  0.0f, 0.0f }, 0x00000000, 0xFFFFFFFF, 0, 0 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00000800, 4, 1 },
        { {  0.0f, -0.0f, 0.0f }, 0x00001000, 0xFFFFF800, 4, 1 },
        { {  0.0f,  0.0f, 0.0f }, 0x00002000, 0x00000000, 4, 0 },
        { {  0.0f,  0.0f, 0.0f }, 0x00001000, 0x00009000, 4, 2 },
        { {  0.0f, -0.0f, 0.0f }, 0x00001000, 0x00007000, 4, 2 },
        { {  0.0f,  0.0f, 0.0f }, 0x00000000, 0xFFFFFFFF, 0, 0 }
    };
    static int blood_n[4] = { 5, 10, 2, 3 };

    tbl = bld_tbl;
    
    angY = 0;
    
    if (type == 2)
    {
        if (bhDGCdirCheck2((NJS_VECTOR*)&epw->dvx, &epw->mlwP->owP[lnk_obj]) != 0)
        {
            angY = 32768;
        }
        
        ps.z = 0;
        ps.y = 0;
        ps.x = 0;
        
        tbl = &tbl[10];
        
        v.x = -epw->dvx;
        v.y = -epw->dvy;
        v.z = -epw->dvz;
        
        njUnitVector(&v);
        
        bhEne_SetBlood3(epw, lnk_obj, &ps, &v, 1, 0, 9, 3);
    } 
    else if (type == 3)
    {
        tbl = &tbl[14];
    }

    for (i = 0; i < 10; i++, tbl++)
    {
        if (tbl->type == -1)
        {
            break;
        }

        ang = (tbl->angY + angY) & 0xFFFF;
        
        v.x = -(njSin(ang) * njCos(tbl->angX));
        v.y = njSin(tbl->angX);
        v.z = -(njCos(ang) * njCos(tbl->angX));
        
        ps.x = ofs->x + tbl->ofs.x;
        ps.y = ofs->y + tbl->ofs.y;
        ps.z = ofs->z + tbl->ofs.z;
        
        bhEne_SetBlood3(epw, lnk_obj, &ps, &v, blood_n[type], tex_id, tbl->type, tbl->wcnt);
    }
}

// 100% matching!
void bhEne_SetNikuhenEffect(BH_PWORK* epw, int type, NJS_POINT3* pos, NJS_POINT3* v, int tex_id)
{
    int eno;

    sys->ef.flg = 1;
    
    sys->ef.id = 362;
    
    sys->ef.type = type;
    
    sys->ef.px = pos->x;
    sys->ef.py = pos->y;
    sys->ef.pz = pos->z;
    
    sys->ef.sx = 2.0f + (-rand() / -2.1474836E9f);
    sys->ef.sy = sys->ef.sx;
    sys->ef.sz = 0;
    
    eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    
    if (eno != -1) 
    {
        eff[eno].stflg |= 0x20;
        
        eff[eno].txp[0] = epw->mlwP->texP;
        
        eff[eno].tex_id = tex_id;
        
        eff[eno].xn = v->x;
        eff[eno].yn = v->y;
        eff[eno].zn = v->z;
    }
}

// 100% matching!
void bhEne_SetNikuhenEffect2(BH_PWORK* epw, int type, NJS_POINT3* pos, int n, int tex_id)
{
    NJS_POINT3 v;
    NJS_POINT3 v2; 
    int angY; 
    int angZ; 
    int i;

    for (i = 0; i < n; i++)
    {
        njUnitMatrix(NULL);

        angZ = (rand() % 7281) - 3641;
        angY = (rand() % 7281) - 3641;
        
        njRotateXYZ(NULL, 0, angY, angZ);
        
        v2.x = -epw->dvx;
        v2.y = -epw->dvy;
        v2.z = -epw->dvz;
        
        njUnitVector(&v2);
        njCalcVector(NULL, &v2, &v);
        
        bhEne_SetNikuhenEffect(epw, type, pos, &v, tex_id);
    }
}

// 100% matching!
int bhEne_SetDFireEffect(BH_PWORK* epw, int no, BT_WORK* ltbl, int type)
{   
    WORK work[42]; 
    WORK* wp; 
    O_WORK* owk; 
    NJS_POINT3 vec; 
    NJS_POINT3 pos; 
    int obj_num; 
    int fmax; 
    int i; 

    obj_num = epw->mlwP->obj_num;
    
    if (obj_num > 42) 
    {
        return -1;
    }

    wp = work;
    
    for (i = 0; i < 42; i++, wp++)
    {
        wp->wk = 0;
        
        wp->indx = 0;
    }
    
    njGetTranslation(&epw->mlwP->owP[no].mtx, &pos);

    owk = epw->mlwP->owP;
    
    wp = work;
    
    for (i = 0; i < obj_num; i++, wp++, owk++)
    {
        wp->indx = i;

        if ((no != i) && (i != 0))
        {
            vec.x = pos.x - owk->mtx[12];
            vec.y = pos.y - owk->mtx[13];
            vec.z = pos.z - owk->mtx[14];
            
            wp->wk = njScalor2(&vec);
        }
        else 
        {
            wp->wk = 10000.0f;
        }
    }
    
    bhEne_QuickSort(work, 0, obj_num - 1);
    
    if (type == 2) 
    {
        fmax = 5;
        
        type = 1;
    }
    else
    {
        fmax = 2;
    }
    
    bhEne_SetDFireEffect2(epw, no, ltbl, type);
    
    for (i = 0; i < fmax; i++)
    {
        bhEne_SetDFireEffect2(epw, work[i].indx, ltbl, type);
    }
    
    return 0;
}

// 100% matching!
void bhEne_SetDFireEffect2(BH_PWORK* epw, int no, BT_WORK* ltbl, int type)
{
    NJS_POINT3 ofp; 
    NJS_POINT3 gpos; 
    int eno; 
    int time; 
    NJS_LINE line; 

    if ((epw->stflg & 0x100000)) 
    {
        line.px = epw->px;
        line.py = epw->py;
        line.pz = epw->pz; 
        
        line.vx = 0;
        line.vy = 20.0f;
        line.vz = 0;
        
        bhCheckL2Water(&line, &gpos);
        
        if (&gpos == NULL)
        {
            gpos.y = 0;
        }
    } 
    else 
    {
        gpos.y = -500.0f;
    }

    ltbl = &ltbl[no];
    
    sys->ef.id = 352;
    
    sys->ef.type = 0;
    
    sys->ef.flg = 1;
    
    sys->ef.px = 0;
    sys->ef.py = 0;
    sys->ef.pz = 0;
    
    sys->ef.ay = 0;

    time = rand() % 10;
    
    sys->ef.sy = sys->ef.sx = ltbl->size + (0.5f * (-rand() / -2.1474836E9f));
    sys->ef.sz = 0;
    
    ofp.x = ltbl->x + (ltbl->xlen - ((2.0f * ltbl->xlen) * (-rand() / -2.1474836E9f)));
    ofp.y = ltbl->y + (ltbl->ylen - ((2.0f * ltbl->ylen) * (-rand() / -2.1474836E9f)));
    
    if (bhDGCdirCheck2((NJS_VECTOR*)&epw->dvx, &epw->mlwP->owP[ltbl->lnk_obj]) == 0)
    {
        ofp.z = -ltbl->z;
    } 
    else 
    {
        ofp.z = ltbl->z;
    }
    
    sys->ef.type = type * 2;
    
    eno = bhSetEffectTb(&sys->ef, &ofp, (unsigned char*)epw, ltbl->lnk_obj);
    
    if (eno != -1) 
    {
        eff[eno].zn = ltbl->len;
        
        eff[eno].ct3 = time;
        
        eff[eno].shp_ct = gpos.y;
    }
    
    sys->ef.type = (type * 2) + 1;
    
    eno = bhSetEffectTb(&sys->ef, &ofp, (unsigned char*)epw, ltbl->lnk_obj);
    
    if (eno != -1)
    {
        eff[eno].zn = ltbl->len;
        
        eff[eno].ct3 = time;
        
        eff[eno].shp_ct = gpos.y;
    }
}

// 100% matching!
int bhEne_SetSanEffect(BH_PWORK* epw, int no, BT_WORK* ltbl)
{
    WORK work[42]; 
    WORK* wp;
    O_WORK* owk; 
    NJS_POINT3 vec; 
    NJS_POINT3 pos; 
    int obj_num; 
    int i;

    obj_num = epw->mlwP->obj_num;
    
    if (obj_num > 42) 
    {
        return -1;
    }
    
    wp = work;
    
    for (i = 0; i < 42; i++, wp++)
    {
        wp->wk = 0;
        
        wp->indx = 0;
    }
    
    njGetTranslation(&epw->mlwP->owP[no].mtx, &pos);
    
    wp = work;
    
    owk = epw->mlwP->owP;
    
    for (i = 0; i < obj_num; i++, wp++, owk++) 
    {
        wp->indx = i;
        
        if ((no != i) && (i != 0))
        {
            vec.x = pos.x - owk->mtx[12];
            vec.y = pos.y - owk->mtx[13];
            vec.z = pos.z - owk->mtx[14];
            
            wp->wk = njScalor2(&vec);
        } 
        else 
        {
            wp->wk = 10000.0f;
        }
    }
    
    bhEne_QuickSort(work, 0, obj_num - 1);
    
    bhEne_SetSanEffect2(epw, no, ltbl);
    
    wp = work;
    
    for (i = 0; i < 3; i++, wp++)
    {
        bhEne_SetSanEffect2(epw, wp->indx, ltbl);
    }
    
    return 0;
}

// 100% matching!
int bhEne_SetSanEffect2(BH_PWORK* epw, int no, BT_WORK* ltbl)
{
    O_WORK* owk;   
    NJS_POINT3 ofp; 

    sys->ef.id = 298;
    
    sys->ef.flg = 1;
    
    sys->ef.px = 0;
    sys->ef.py = 0;
    sys->ef.pz = 0;
    
    sys->ef.ay = 0;
    
    sys->ef.type = (short)(rand() % 8) + 12;

    owk = &epw->mlwP->owP[no];

    ltbl = &ltbl[no]; 
    
    sys->ef.sy = sys->ef.sx = 0.5f + (0.5f * (-rand() / -2.1474836E9f));
    sys->ef.sz = 0;
    
    ofp.x = ltbl->x + (ltbl->xlen - ((2.0f * ltbl->xlen) * (-rand() / -2.1474836E9f)));
    ofp.y = ltbl->y + (ltbl->ylen - ((2.0f * ltbl->ylen) * (-rand() / -2.1474836E9f)));
    ofp.z = 0;
    
    if (bhDGCdirCheck2((NJS_VECTOR*)&epw->dvx, owk) == 0) 
    {
        ofp.z = -ltbl->z;
    } 
    else 
    {
        ofp.z = ltbl->z;
    }
    
    return bhSetEffectTb(&sys->ef, &ofp, (unsigned char*)epw, ltbl->lnk_obj);
}

// 100% matching!
void bhEne_QuickSort(WORK* a, int first, int last)
{
    int i, j; 
    int indx; 
    float x; 
    float t; 
    WORK* swap_a, *swap_b; // not from DWARF

    if (first < last) 
    {
        x = a[(first + last) / 2].wk;
        
        for (i = first, j = last; ; )
        {
            for ( ; a[i].wk < x; i++);
            for ( ; a[j].wk > x; j--);
    
            if (j <= i) 
            {
                break;
            }
            
            swap_a = &a[i];
            swap_b = &a[j];
                
            t = swap_a->wk;
            
            indx = swap_a->indx;
            
            i++;
            j--;
            
            swap_a->wk = swap_b->wk;
            swap_a->indx = swap_b->indx;
            
            swap_b->wk = t; 
            swap_b->indx = indx;
        }
        
        if (first < (i - 1))
        {
            bhEne_QuickSort(a, first, i - 1);
        }
        
        if ((j + 1) < last) 
        {
            bhEne_QuickSort(a, j + 1, last);
        }
    }
}

// 100% matching!
int bhEne_ChgMtn(BH_PWORK* epw, unsigned int no, int frm, int rate) 
{
    epw->mtn_add = 0x10000;
    if (epw->mtn_no != no) 
    {
        epw->mtn_no = no;
        epw->frm_no = frm;
        epw->hokan_count = rate;
        epw->hokan_rate = 0;
        epw->mtn_md = 0x20;
        epw->flg = (int) (epw->flg & ~0x40000);
        epw->flg = (int) (epw->flg & ~0x2000000);
        return 0;
    }
    
    return -1;
}

// 100% matching!
int bhEne_CollisionCheckWall(BH_PWORK* pw, NJS_POINT3* ps, NJS_POINT3* pd, float ar, float ah)
{
    float x, y, z; 
    float r, h; 
    unsigned int flg; 

    x = pw->px;
    y = pw->py;
    z = pw->pz;
    
    h = pw->ah;
    r = pw->ar;
    
    pw->px = ps->x;
    pw->py = ps->y;
    pw->pz = ps->z;
    
    pw->ah = ah;
    pw->ar = ar;
    
    flg = pw->flg;
    
    pw->flg &= ~0x100;
    
    bhCheckDansa(pw);
    bhCheckWall(pw);
    
    pw->flg = flg;
    
    pd->x = pw->px - ps->x;
    pd->y = pw->py - ps->y;
    pd->z = pw->pz - ps->z;
    
    pw->px = x;
    pw->py = y;
    pw->pz = z;
    
    pw->ah = h;
    pw->ar = r;

    if ((pd->x != 0) || (pd->z != 0)) 
    {
        return 1;
    }
    
    return 0;
}

// 100% matching!
ATR_WORK* bhEne_CollisionCheckWall2(BH_PWORK* pw, NJS_POINT3* ps, NJS_POINT3* ops, NJS_POINT3* pd, float ar, float ah)
{
    ATR_WORK* hp;
    NJS_POINT3 pos; 
    unsigned int flg; 

    hp = NULL;
    
    pos.x = ps->x;
    pos.y = ps->y;
    pos.z = ps->z;
    
    flg = pw->flg;
    
    pw->flg &= ~0x100;
    
    bhCheckDansa(pw);
    
    if (bhCheckWallEx(pw, &pos, ops, ar, ah) != 0)
    {
        hp = bhCheckWallType(ps, pw->flg, ar, ah);
    }
    
    pw->flg = flg;
    
    pd->x = pos.x - ps->x;
    pd->y = pos.y - ps->y;
    pd->z = pos.z - ps->z;
    
    return hp;
}

// 100% matching!
ATR_WORK* bhEne_CheckDirWall(BH_PWORK* epw, int ang, float step) 
{
    NJS_POINT3* pos = (NJS_POINT3*)((char*)epw + 0x10);
    ATR_WORK* hp;

    hp = bhEne_CheckDirWall3(epw, pos, ang, step);
    return hp;
}

// 100% matching!
ATR_WORK* bhEne_CheckDirWall2(BH_PWORK* epw, int ang, float step)
{
    ATR_WORK* hp;
    NJS_POINT3 pos;

    pos.x = epw->px + epw->aox;
    pos.z = epw->pz + epw->aoz;
    pos.y = epw->py;
  
    hp = bhEne_CheckDirWall3(epw, &pos, ang, step);
    return hp;
}

// 100% matching!
ATR_WORK* bhEne_CheckDirWall3(BH_PWORK* epw, NJS_POINT3* pos, int ang, float step)
{
    int angle; // not from debugging symbols
    float float_angle; // not from debugging symbols

    ATR_WORK* hp;
	NJS_POINT3 ps;
    
    angle = (epw->ay + ang) & 0xffff;

    float_angle = step * njSin(angle);
    ps.x = pos->x - float_angle;
    
    float_angle = step * njCos(angle);
    ps.z = pos->z - float_angle;
    
    ps.y = pos->y;
    
    hp = bhCheckWallType(&ps, epw->flg, epw->ar, epw->ah);
    return hp;
}

// 100% matching!
int bhEne_CheckSideWall(BH_PWORK* epw, float step, int both) {  

    NJS_POINT3 *pos = (NJS_POINT3*)&epw->px;
    return bhEne_CheckSideWall3(epw, pos, step, both);
}

// 100% matching!
int bhEne_CheckSideWall2(BH_PWORK* epw, float step, int both)
{
    NJS_POINT3 pos;

    pos.x = epw->px + epw->aox;
    pos.z = epw->pz + epw->aoz;
    pos.y = epw->py;
    
    return bhEne_CheckSideWall3(epw, &pos, step, both);
}

// 100% matching!
int bhEne_CheckSideWall3(BH_PWORK* epw, NJS_POINT3* pos, float step, int both)
{
    int left_hit;
    int right_hit;

    right_hit = 0;
    left_hit = 0;
    
    if (bhEne_CheckDirWall3(epw, pos, -0x4000, step) != 0) 
    {
        left_hit = 1;
    }
    if (bhEne_CheckDirWall3(epw, pos, 0x4000, step) != 0) 
    {
        right_hit = -1;
    }

    if (left_hit != 0) 
    {
        if (right_hit != 0) 
        {
            return both;
        }
    }

    return left_hit + right_hit;
}

// 100% matching!
void bhEne_SetVibration(int no)
{
    switch (no) 
	{                               
        case 0:
            StartVibrationEx(1, 9);
            break;
        case 1:
            StartVibrationEx(1, 0xA);
            break;
        case 2:
            StartVibrationEx(1, 0xB);
            break;
    }
}

// 100% matching!
void bhEne_PlayerSePlay(BH_PWORK* epw, int no)
{
    if (!(epw->flg & 0x10000)) 
	{
        CallPlayerVoice(no);
    }
}

// 100% matching!
void bhEne_HitCheckParts(BH_PWORK* pp, NJS_POINT3* pos) {
    O_WORK* owk;
    NJS_VECTOR vec;
    float len;
    float slen;
    int i;

    owk = (O_WORK*)pp->mlwP->owP+1;
    len = -1.0f;
    
    for (i = 1; i < (int)(pp->mlwP->obj_num - 1); i++)
    {        
        vec.x = pos->x - owk->mtx[12];
        vec.y = pos->y - owk->mtx[13];
        vec.z = pos->z - owk->mtx[14];
        slen = njScalor2(&vec);

        if (len > slen || len == -1.0f)
        {
            len = slen;
            pp->djnt_no = i;
            pp->dvx = -vec.x;
            pp->dvy = -vec.y;
            pp->dvz = -vec.z;
        }
        
         owk++;
    }
    
    pp->dpx = pos->x;
    pp->dpy = pos->y;
    pp->dpz = pos->z;
}
