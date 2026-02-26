#include "eneset.h"
/*#include "en01.h"
#include "en02.h"
#include "en03.h"
#include "en04.h"
#include "en05.h"
#include "en06.h"
#include "en07.h"
#include "en08.h"
#include "en09.h"
#include "en10.h"
#include "en11.h"
#include "en12.h"
#include "en13.h"
#include "en14.h"
#include "en15.h"
#include "en16.h"
#include "en17.h"
#include "en18.h"
#include "en19.h"
#include "en20.h"
#include "en21.h"
#include "en22.h"
#include "en23.h"
#include "en24.h"
#include "en25.h"
#include "en26.h"
#include "en27.h"
#include "en28.h"
#include "en29.h"
#include "en30.h"
#include "en53.h"
#include "en54.h"
#include "en55.h"
#include "en56.h"
#include "en71.h"*/
#include "MdlPut.h"
#include "Motion.h"
#include "effect.h"
#include "face.h"
#include "flag.h"
#include "hitchk.h"
#include "light.h"
#include "njplus.h"
#include "pwksub.h"
#include "sdfunc.h"
#include "subpl.h"
#include "weapon.h"
//#include "zonzon1.h"
#include "main.h"

typedef void (*JumpEnemy_proc)();

CPCL En00CapColTab[5] =
{
    { 0, 0,   35 },
    { 0, 50,  0  },
    { 0, 0,   35 },
    { 0, 100, 0  },
    { 0, 0,   0  },
};
JumpEnemy_proc bhJumpEnemy[100]/* = TODO: create headers for the en01, en02, etc., files.
{
	bhEne00,
	bhEne01,
	bhEne02,
	bhEne03,
	bhEne04,
	bhEne05,
	bhEne06,
	bhEne07,
	bhEne08,
	bhEne09,
	bhEne10,
	bhEne11,
	bhEne12,
	bhEne13,
	bhEne14,
	bhEne15,
	bhEne16,
	bhEne17,
	bhEne18,
	bhEne19,
	bhEne20,
	bhEne21,
	bhEne22,
	bhEne23,
	bhEne24,
	bhEne25,
	bhEne26,
	bhEne27,
	bhEne28,
	bhEne29,
	bhEne30,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhEne53,
	bhEne54,
	bhEne55,
	bhEne56,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhEne71,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl,
	bhSubpl
}*/;

// 100% matching! 
void bhInitEnemy()
{
    npSetMemory((unsigned char*)ene, 180224, 0);
}

// 100% matching!
BH_PWORK* bhSetEnemy(EGG_WORK* etp, int unused) // second parameter is not present on the debugging symbols
{
    BH_PWORK* epp;
    int i;
    
    epp = ene;
    
    for (i = 0; ; )
    {
        if (!(epp->flg & 0x1)) 
        {
            npSetMemory((unsigned char*)epp, sizeof(BH_PWORK), 0);
            
            epp->flg = etp->flg;
            
            epp->id = etp->id;
            
            if (epp->id > 40) 
            {
                epp->mdflg |= 0x20;
                
                switch (epp->id) 
                {                      
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                    epp->clp_jno[0] = 0;
                    epp->clp_jno[1] = 3;
                    epp->clp_jno[2] = 5;
                    epp->clp_jno[3] = 8;
                    epp->clp_jno[4] = 12;
                    epp->clp_jno[5] = 15;
                    epp->clp_jno[6] = 19;
                    epp->clp_jno[7] = -1;
                    break;
                case 91:
                case 92:
                case 93:
                case 94:
                case 95:
                case 96:
                case 97:
                case 98:
                    epp->clp_jno[0] = 0;
                    epp->clp_jno[1] = 3;
                    epp->clp_jno[2] = 5;
                    epp->clp_jno[3] = 17;
                    epp->clp_jno[4] = 21;
                    epp->clp_jno[5] = 24;
                    epp->clp_jno[6] = 28;
                    epp->clp_jno[7] = -1;
                    break;
                }
                
                epp->flg |= 0x8000;
            }
            
            if (epp->id > 90) 
            {
                epp->mdflg |= 0x100;
            }
            
            epp->type = etp->type;
            
            epp->flr_no = etp->flr_no;
            
            epp->mdlver = etp->mdlver;
            
            epp->px = etp->px;
            epp->py = etp->py;
            epp->pz = etp->pz;
            
            epp->ax = 0;
            epp->ay = etp->ay;
            epp->az = 0;
            
            epp->aoz = 0;
            epp->aoy = 0;
            epp->aox = 0;
            
            *(int*)&epp->mode0 = 0;
            
            epp->ct3 = 0;
            epp->ct2 = 0;
            epp->ct1 = 0;
            epp->ct0 = 0;
            
            epp->lkwkp = NULL;
            
            epp->exp0 = NULL;
            epp->exp1 = NULL;
            epp->exp2 = NULL;
            
            epp->idx_ct = i;
            
            epp->sxb = 1.0f;
            epp->sx = 1.0f;
            
            epp->syb = 1.0f;
            epp->sy = 1.0f;
            
            epp->szb = 1.0f;
            epp->sz = 1.0f;
            
            epp->obj_a = NULL;
            epp->obj_b = NULL;
            
            epp->shp_ct = 0;
            
            epp->mtx = (float(*)[16])epp->mtxbuf;
            
            epp->frm_no = 0;
            epp->mtn_no = 0;
            epp->mdl_no = 0;
            
            epp->hokan_count = 0;
            epp->hokan_rate = 0;
            
            epp->frm_mode = 0;
            
            epp->mtn_no = 0;
            epp->mtn_add = 65536;
            epp->mtn_md = 0;
            epp->mtn_tp = NULL;
            
            epp->at_flg = 0;
            
            epp->clp_jno[0] = 1;
            epp->clp_jno[1] = -1;
            
            bhSetFloorNum(epp);
            
            bhCheckEneWorkNum();
            
            return epp;
        }
        
        i++;
        epp++;
        
        if (i >= 128) 
        {
            bhCheckEneWorkNum();
            
            return NULL;
        }
    }
}

// 100% matching!
void bhCheckEneWorkNum()
{
    BH_PWORK* epp;
    int i;

    sys->ewk_n = 0;
    
    epp = ene;

    for (i = 0; i < 128; i++, epp++)
    {
        if ((epp->flg & 0x1))
        {
            sys->ewk_n = i + 1;
        }
    }
}

// 100% matching!
void bhControlEnemy()
{
    BH_PWORK* ep;
    unsigned int i;
    
    plp->ofz = 0;
    plp->ofx = 0;
    
    if ((sys->sp_flg & 0x2)) 
    {
        ep = ene;
        
        sys->en_objn = 0;
        
        for (i = 0; i < sys->ewk_n; i++, ep++)
        {
            sys->enow = i;
            
            if ((!(ep->stflg & 0x41000000)) && (((!(ep->flg & 0x80)) || (!(((BH_PWORK*)ep->lkwkp)->stflg & 0x1000000))) && ((ep->flg & 0x1))))
            {
                ep->pxb = ep->px;
                ep->pyb = ep->py;
                ep->pzb = ep->pz;
                
                ep->axb = ep->ax;
                ep->ayb = ep->ay;
                ep->azb = ep->az;
                
                if (ep->id > 90) 
                {
                    bhControlMask(ep);
                }
                
                bhJumpEnemy[ep->id](ep);
                
                bhEne_InitDamage(ep);
                
                if ((ep->flg & 0x80000000)) 
                {
                    sys->en_obj[sys->en_objn++] = ep;
                }
            }
        }
    }
}

// 98.23% matching (matches on GC)
void bhEne00(BH_PWORK* ep)
{
    ATR_WORK* hp; 
    NJS_POINT3 pos; 
    int i;          
    POINT pnt;      

    switch (ep->mode0)
    {       
    case 0:
        ep->flg |= 0x8120;
        ep->flg &= ~0x6;
        
        ep->flg2 |= 0x1;
        
        ep->mdflg &= ~0x1;
        ep->mdflg |= 0x20;
        
        ep->ar = 4.0f;
        ep->ah = 15.0f;
        
        ep->aox = 0;
        ep->aoy = 0;
        ep->aoz = 0;
        
        ep->car = 4.0f;
        ep->cah = 15.0f;
        
        ep->hp = 0;
        
        ep->cpcl = En00CapColTab;
        
        if (!(ep->flg2 & 0x80000000)) 
        {
            ep->flg2 |= 0x80000000;
            
            ep->ct0 = sys->mwal_n++;
            
            hp = &sys->mwalp[ep->ct0];
            
            hp->flg = 0x81;
            
            hp->type = 3;
            
            hp->flr_no = ep->flr_no;
            
            hp->attr = 8;
            
            hp->px = ep->px;
            hp->py = rom->grand[hp->flr_no + 2];
            hp->pz = ep->pz;
            
            hp->w = 3.5f;
            hp->h = 15.0f;
            
            hp->d = 0;
            
            hp->prm2 = 0;
            hp->prm1 = 0;
            hp->prm0 = 0;
            hp->prm3 = sys->enow;
            
            pnt.px = 0;
            pnt.py = 0;
            pnt.pz = 0;
            
            pnt.ox = 0;
            pnt.oy = 0;
            pnt.oz = 0;
            
            bhSetEffect(17, &pnt, (unsigned char*)ep, 0);
        } 
        else 
        {
            hp = &sys->mwalp[ep->ct0];
            
            hp->flg = 0x81;
            
            hp->attr = 8;
        }
        
        ep->mode0 = 1;
        break;
    case 1:
        hp = &sys->mwalp[ep->ct0];
        
        if (((ep->flg & 0x4)) && (ep->wpnr_no != 2))
        {
            pos.x = ep->px;
            pos.y = 10.0f + ep->py;
            pos.z = ep->pz;
            
            bhSetExplosion(&pos);
            
            ep->flg |= 0x2;
            
            ep->mdflg |= 0x1;
            
            ep->flg &= ~0x78;
            
            hp->flg &= ~0x1;
            
            ep->mode0 = 2;
        }
        
        hp->px = ep->px;
        hp->py = ep->py;
        hp->pz = ep->pz;
        break;
    case 2:
        break;
    }
   
    if ((ep->flg & 0x4)) 
    {
        for (i = 0; i < ep->mlwP->obj_num; i++) 
        {
            ep->dam[i] = 0;
        }
        
        ep->flg &= ~0x4;
    }
    
    if ((ep->flg & 0x40)) 
    {
        bhCheckPlayer(ep);
    }
    
    if ((ep->flg & 0x8)) 
    {
        bhCheckEnemies(ep);
    }
    
    if ((ep->flg & 0x10)) 
    {
        bhCheckWall(ep);
    }
    
    bhCalcModel(ep);
    
    ep->watr.c1.x = ep->mlwP->owP->mtx[12];
    ep->watr.c1.y = ep->mlwP->owP->mtx[13];
    ep->watr.c1.z = ep->mlwP->owP->mtx[14];
    
    ep->watr.c2.x = ep->watr.c1.x;
    ep->watr.c2.y = 15.0f + ep->watr.c1.y;
    ep->watr.c2.z = ep->watr.c1.z;
    
    ep->watr.r = ep->car;
}

// 99.96% matching
void bhEne56(BH_PWORK* ep)
{
	O_WRK* op;    
    NJS_POINT3 pos; 

    ep->flg |= 0x8000;
    
    switch (ep->mode0)
    {
    case 0:
        ep->mdflg |= 0x20;
        
        ep->mnwP = sys->rmthp;
        
        ep->mtn_no = 0;
        ep->mtn_md = 0; 
        ep->mtn_tp = 0;
        
        ep->hokan_rate = 32768;
        ep->hokan_count = 0;
        
        ep->mtn_add = 0;
        
        ep->frm_no = 0;
        
        sys->ufo_oidx = 4;
        
        if (bhCkFlg(sys->ev_flg, 0x3B) != 0) 
        {
            ep->px = sys->ufo_pos.x = 13.0f;
            ep->py = sys->ufo_pos.y = -15.0f;
            ep->pz = sys->ufo_pos.z = 11.6f;
        }
        else 
        {
            ep->px = sys->ufo_pos.x = 47.0f;
            ep->py = sys->ufo_pos.y = -15.0f;
            ep->pz = sys->ufo_pos.z = 60.0f;
        }
        
        if (!(ep->flg & 0x800)) 
        {
            ep->ct3 = bhSetShadow(NULL, (unsigned char*)ep, 1, 12.0f, 10.0f, 12.0f);
            
            ep->flg |= 0x800;
        }
        
        if (bhCkFlg(sys->ev_flg, 0x3B) != 0) 
        {
            op = &sys->obwp[sys->ufo_oidx];
            
            op->flg |= 0x80;
            
            op->lkono = 0;
            
            op->lox = 0;
            op->loy = 42.0f;
            op->loz = 0;
            
            op->lkwkp = (unsigned char*)ep;
            
            ep->mode0 = 2;
            break;
        }
        
        ep->mode0 = 1;
    case 1:
        ep->px = sys->ufo_pos.x;
        ep->py = sys->ufo_pos.y;
        ep->pz = sys->ufo_pos.z;
        
        bhSetMotion(ep, (int)ep->mtn_add, ep->mtn_md, NULL);
        
        bhCalcModel(ep);
        
        switch (sys->ufo_md) 
        {
        case 0:
            if (bhCkFlg(sys->ev_flg, 0x3B) != 0)
            {
                ep->mode0 = 2;
            }
            else
            {
                ep->mtn_add = 0;
                
                ep->frm_no = 0;
            }
            
            break;
        case 1:
            if ((ep->frm_no / 65536) < 40)
            {
                ep->mtn_add = 65536;
            }
            else
            {
                ep->mtn_add = 0;
            }
            
            break;
        case 2:
            pos = *(NJS_POINT3*)&ep->mlwP->owP[3].mtx[12];
            
            pos.x -= 0.6f;
            pos.y -= 10.0f;
            
            if (bhCheckWallType(&pos, 0, 2.0f, 3.0f) != NULL) 
            {
                sys->ufo_md = 3;
                break;
            }
            
            pos = *(NJS_POINT3*)&ep->mlwP->owP[5].mtx[12];
            
            pos.x -= 0.6f;
            pos.y -= 10.0f;
            
            if (bhCheckWallType(&pos, 0, 2.0f, 3.0f) != NULL) 
            {
                sys->ufo_md = 3;
                break;
            }
            
            pos = *(NJS_POINT3*)&ep->mlwP->owP[7].mtx[12];
            
            pos.x += 0.6f;
            pos.y -= 10.0f;
            
            if (bhCheckWallType(&pos, 0, 2.0f, 3.0f) != NULL) 
            {
                sys->ufo_md = 3;
                break;
            }
            
            pos = *(NJS_POINT3*)&ep->mlwP->owP[9].mtx[12];
            
            pos.x += 0.6f;
            pos.y -= 10.0f;
            
            if (bhCheckWallType(&pos, 0, 2.0f, 3.0f) != NULL) 
            {
                sys->ufo_md = 3;
            }
            
            break;
        case 4:
            if ((ep->frm_no / 65536) < 70)
            {
                ep->mtn_add = 65536;
            }
            else
            {
                ep->mtn_add = 0;
            }
            
            if ((sys->ufo_flg != 0) && ((sys->obwp[sys->ufo_oidx].px - ep->mlwP->owP[7].mtx[12]) < 9.0f)) 
            {
                sys->obwp[sys->ufo_oidx].px = ep->mlwP->owP[7].mtx[12] + 9.0f;
            }
            
            break;
        case 5:
            op = &sys->obwp[sys->ufo_oidx];
            
            if (sys->ufo_flg != 0)
            {
                if (!(op->flg & 0x80)) 
                {
                    op->flg |= 0x80;
                    
                    op->lkono = 0;
                    
                    op->lox = 0;
                    op->loy = op->py - ep->py;
                    op->loz = op->pz - ep->pz;
                    
                    op->lkwkp = (unsigned char*)ep;
                }
                
                if ((sys->ufo_flg == 1) && (ep->py >= -35.0f)) 
                {
                    op->flg &= ~0x80;
                    
                    op->px = op->mlwP->owP->mtx[12];
                    op->py = op->mlwP->owP->mtx[13];
                    op->pz = op->mlwP->owP->mtx[14];
                    
                    op->mode1 = 0;
                    
                    op->yn = 0;
                    
                    sys->ufo_md = 6;
                }
            }
            
            break;
        case 6:
            op = &sys->obwp[sys->ufo_oidx];
            
            switch (op->mode1) 
            {
            case 0:
                op->py = op->py + op->yn;
                
                if (op->yn > -1.0f) 
                {
                    op->yn -= 0.2f;
                }
                
                if (op->py <= 0) 
                {
                    op->yn = 1.0f;
                    
                    op->mode1 = 1;
                    
                    CallSystemSe(0, 0x80000211);
                }
                
                break;
            case 1:
                op->py = op->yn * (-rand() / -2.1474836e+09f);
                
                op->yn *= 0.8f;
                
                if (op->yn < 0.1f)
                {
                    op->mode1 = 2;
                    
                    op->py = 0;
                    
                    op->yn = 0;
                }
                
                break;
            case 2:
                break;
            }
            
            break;
        }
        
        break;
    case 2:
        ep->frm_no = 0x460000;
        
        bhSetMotion(ep, 0, ep->mtn_md, NULL);
        
        bhCalcModel(ep);
        break;
    }
}

// 100% matching!
void bhDrawEnemy() 
{
    BH_PWORK* ep;
    int i;
    unsigned int argb;
    
    ep = ene;
    
    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if ((((ep->flg & 0x1)) && (!(ep->flg & 0x80000000))) && (!(ep->stflg & 0x41000000)) && (((sys->st_flg & 0x20)) || (!(ep->mdflg & 0x200))) && ((!(ep->flg & 0x80)) || (!(((BH_PWORK*)ep->lkwkp)->stflg & 0x1000000))))
        {
            if ((ep->mdflg & 0x4)) 
            {
                bhCalcModel(ep);
            }
            
            if ((((ep->mdflg & 0x20)) || (bhCheckClipModel(ep) == 0)) && (!(ep->mdflg & 0x1)) && (ep->mlwP->objP != NULL)) 
            {
                if ((sys->st_flg & 0x20))
                {
                    bhPutModel(ep);
                }
                else
                {
                    if ((sys->gm_flg & 0x1000040)) 
                    {
                        if ((ep->mdflg & 0x400))
                        {
                            argb = npGetMatColor(ep->mlwP->objP, ep->mlwP->obj_num) & 0xFF;
                            
                            if (argb >= 0)
                            {
                                bhSetEasyDirLight(argb / 255.0f);
                            }
                            else
                            {
                                bhSetEasyDirLight((2.0f * ((argb >> 1) | (argb & 0x1))) / 255.0f);
                            }
                        }
                        else 
                        {
                            bhSetEasyDirLight(0.6f);
                        }
                    }
                    
                    if ((ep->mdflg & 0x2))
                    {
                        npPushMdlstr2(ep->obj_a, ep->mlwP->obj_num);
                        
                        npCalcMorphing(ep->obj_a, ep->obj_b, ep->shp_ct, ep->mlwP->obj_num);
                        
                        ep->mlwP->objP = ep->obj_a;
                        
                        bhPutModel(ep);
                        
                        npPopMdlstr2(ep->obj_a, ep->mlwP->obj_num);
                    } 
                    else 
                    {
                        bhPutModel(ep);
                    }
                }
            }
        }
    }
}

// 100% matching!
void bhDrawEneObject()
{
    BH_PWORK* ep;
    int i;
	
    for (i = 0; i < sys->en_objn; i++) 
    {
        ep = sys->en_obj[i];
        
        if (((ep->flg & 0x1)) && (!(ep->stflg & 0x41000000)))
        {
            if ((ep->mdflg & 0x4))
            {
                bhCalcModel(ep);
            }
            
            if ((((ep->mdflg & 0x20)) || (bhCheckClipModel(ep) == 0)) && (ep->mlwP->objP != NULL) && (!(ep->mdflg & 0x1)))
            {
                if ((ep->mdflg & 0x2)) 
                {
                    npPushMdlstr2(ep->obj_a, ep->mlwP->obj_num);
                    
                    npCalcMorphing(ep->obj_a, ep->obj_b, ep->shp_ct, ep->mlwP->obj_num);
                    
                    ep->mlwP->objP = ep->obj_a;
                    
                    bhPutModel(ep);
                    
                    npPopMdlstr2(ep->obj_a, ep->mlwP->obj_num);
                }
                else 
                {
                    bhPutModel(ep);
                }
            }
        }
    }
}

// 100% matching!
void* bhEne_CallocWork(int size)
{
    unsigned char* ret_addr; 
    unsigned char* addr;     

    if ((&sys->memp[size] - sys->mempb) > 0xC40000)
    {
        return NULL;
    }
    
    sys->memp = (unsigned char*)(((unsigned int)sys->memp + 63) & ~0x3F);
    
    ret_addr = sys->memp;

    addr = ret_addr; 
    
    sys->memp = &ret_addr[size];
    
    while (size-- != 0) 
    {
        *addr++ = 0;
    } 
    
    return ret_addr;
}

// 100% matching!
void bhEne_SetCallFunc(void(*func)(BH_PWORK*), unsigned int no)
{
    bhJumpEnemy[no] = func;
}
