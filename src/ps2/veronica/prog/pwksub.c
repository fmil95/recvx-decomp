#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/light.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/main.h"

// 100% matching! 
unsigned char* bhGetFreeMemory(int size, int param) // second parameter is not present on the debugging symbols  
{
    unsigned char *temp; // not from the debugging symbols
    
    sys->memp = (unsigned char*)(((int)sys->memp + 63) & ~0x3F);
    
    if (((sys->memp + size) - freemem) > 12845056) 
    {
        return NULL;
    } 
    
    temp = sys->memp;
    
    npSetMemory(temp, size, 0);
    
    sys->memp += size;
    
    printf("malloc area = %x\n", sys->memp);
    
    return temp;
}

// 100% matching! 
void bhCalcLinkModel(BH_PWORK* pp)
{
	BH_PWORK* ep;
    O_WRK* op;
    int i;
    unsigned int flg; // not from DWARF

    flg = (unsigned int)pp & ~0x80000000;
    
    for (ep = ene, i = 0; i < sys->ewk_n; i++, ep++)
    {
        if ((((unsigned int)ep & ~0x80000000) != flg) && (((ep->flg & 0x1)) && ((ep->flg & 0x80))) && (((unsigned int)ep->lkwkp & ~0x80000000) == flg) && (ep->mlwP != NULL))
        {
            bhCalcModel(ep);
        }
    }
    
    for (op = sys->obwp, i = 0; i < rom->obj_n; i++, op++)
    {
        if ((((unsigned int)op & ~0x80000000) != flg) && (((op->flg & 0x1)) && ((op->flg & 0x80))) && (((unsigned int)op->lkwkp & ~0x80000000) == flg) && (op->mlwP != NULL))
        {
            bhCalcModel((BH_PWORK*)op);
        }
    }
    
    for (op = sys->itwp, i = 0; i < rom->itm_n; i++, op++)
    {
        if ((((unsigned int)op & ~0x80000000) != flg) && (((op->flg & 0x1)) && ((op->flg & 0x80))) && (((unsigned int)op->lkwkp & ~0x80000000) == flg) && (op->mlwP != NULL))
        {
            bhCalcModel((BH_PWORK*)op);
        }
    }
    
    for (op = eff, i = 0; i < 512; i++, op++)
    {
        if ((((op->flg & 0x1)) && ((op->flg & 0x80))) && (((unsigned int)op->lkwkp & ~0x80000000) == flg)) 
        {
            njSetMatrix(op->mtx, &((BH_PWORK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
            
            njTranslate(op->mtx, op->lox, op->loy, op->loz);
            njRotateXYZ(op->mtx, op->ax,  op->ay,  op->az);
        }
    }
}

// 100% matching!
void bhSetFloorNum(BH_PWORK* pp)
{
    int i;    
    int fno; 
    int fnow; 
    
    fnow = pp->flr_no;
    
    fno = 2;

    for (i = 0; i < 31; i++)
    {
        if (((rom->grand[i]) && (pp->py >= rom->grand[i])) || ((i == 2) && (pp->py >= rom->grand[i]))) 
        {
            fno = i;
        }
    }

    pp->flr_no = fno - 2;
    
    if (pp->flr_no != fnow)
    {
        pp->flr_nob = fnow;
    }
}

// 100% matching!
int bhCheckFloorNum(float py)
{
    int i;
    int fno;

    fno = 2;
    
    for (i = 0; i < 31; i++)
    {
        if (((rom->grand[i]) && (py >= rom->grand[i])) || ((i == 2) && (py >= rom->grand[i]))) 
        {
            fno = i;
        }
    }

    fno -= 2;
    
    return fno;
}

// 100% matching!
void bhAddSpeed(BH_PWORK* pp, int r)
{
    int angle; // not from DWARF

    angle = (pp->ay + r) & 0xFFFF;
    
    pp->px -= pp->spd * njSin(angle);
    pp->pz -= pp->spd * njCos(angle);
}

// 70.10% matching (matches on NGC)
int bhGetFrameNum(unsigned int fnm_old, unsigned int fnm_new, int fno_now)
{ 
    float fold, fnew; 
    int frm; 

    fold = fnm_old;
    fnew = fnm_new;

    fold = fnew * ((100.0f / fold) * (fno_now / 65536)); 
     
    frm = (int)(fold / 100.0f) * 65536; 
    
    if (frm < 0)
    {
        frm = 0;
    }

    if (frm > fnm_new) 
    {
        frm = fnm_new;
    }
  
    return frm;
}

// 100% matching!
int bhCalcLockEneYR(BH_PWORK* pp, int idx)
{
	BH_PWORK* ewp;
    NJS_POINT3 vec;   
    int yr;
    short aa;
    float px, pz;
    float ex, ez;

    ewp = &ene[idx];
    
    if ((pp->flg & 0x80000)) 
    {
        px = pp->mlwP->owP[21].mtx[12];
        pz = pp->mlwP->owP[21].mtx[14];
    }
    else 
    {
        px = pp->mlwP->owP[17].mtx[12];
        pz = pp->mlwP->owP[17].mtx[14];
    }
    
    ex = 0.5f * (ewp->watr.c1.x + ewp->watr.c2.x);
    ez = 0.5f * (ewp->watr.c1.z + ewp->watr.c2.z);
    
    vec.x = ex - px;
    vec.z = ez - pz;
    vec.y = 0;
    
    njUnitVector(&vec);
    
    aa = 10430.381f * atan2f(-vec.x, -vec.z);
    
    yr = (short)(aa - 24576);
    
    px -= 3.0f * njSin(yr);
    pz -= 3.0f * njCos(yr);
    
    vec.x = ex - px;
    vec.z = ez - pz;
    vec.y = 0;
    
    njUnitVector(&vec);
    
    return 10430.381f * atan2f(-vec.x, -vec.z);
}

// 100% matching!
int bhSearchNearEnemy(BH_PWORK* pp, int* r, float* h, int* id) 
{
    NJS_VECTOR vc0, vc1, vc2;  
    NJS_CAPSULE cap; 
    float a;         
    float er;      
    float ln;       
    float nr;        
    float ah;      
    float epx, epz;       
    BH_PWORK* epp; 
    int i;          
    int idx;         
    int ar;          
    int yr;          

    ar = *r;
    ah = *h;
    
    if (ar == 0) 
    {
        ar = 32768;
    }
    
    vc1.x = 0;
    vc1.y = 0;
    vc1.z = -1.0f;
    
    njUnitMatrix(NULL);
    
    njRotateY(NULL, pp->ay);
    njCalcVector(NULL, &vc1, &vc0);
    
    njRotateY(NULL, ar);
    njCalcVector(NULL, &vc1, &vc2);
    
    er = -njInnerProduct(&vc0, &vc2);
    
    cap.c1.x = pp->px;
    cap.c1.y = pp->py + ah;
    cap.c1.z = pp->pz;
    cap.r    = 0.1f;
    
    nr = 0;
    
    epp = ene;
    
    idx = -1;
    
    for (i = 0; i < sys->ewk_n; i++, epp++)
    {
        if ((((epp->flg & 0x1)) && ((epp->flg & 0x20)) && (!(epp->flg & 0x2)) && (!(epp->flg2 & 0x10))) && (!(epp->stflg & 0x41000000)) && ((!(epp->flg & 0x80)) || (!(((O_WRK*)epp->lkwkp)->stflg & 0x1000000)))) 
        {
            cap.c2.x = 0.5f * (epp->watr.c1.x + epp->watr.c2.x);
            cap.c2.y = 0.5f * (epp->watr.c1.y + epp->watr.c2.y);
            cap.c2.z = 0.5f * (epp->watr.c1.z + epp->watr.c2.z);
            
            vc1.x = pp->px - cap.c2.x;
            vc1.y = cap.c1.y - cap.c2.y;
            vc1.z = pp->pz - cap.c2.z;
            
            ln = njScalor(&vc1);
            
            vc1.y = 0;
            
            njUnitVector(&vc1);
            
            if ((njInnerProduct(&vc0, &vc1) < er) && (bhCheckC2WallN(&cap, 0x40000400) == 0) && ((ln < nr) || (nr == 0)))
            {
                epx = cap.c2.x;
                epz = cap.c2.z;
                
                nr = ln;
                
                idx = i;
            }
        }
    }
    
    if (idx != -1) 
    {
        *id = idx;
        
        epp = &ene[idx];
        
        if (pp == plp) 
        {
            epp->stflg |= 0x800;
        }
        
        vc0.x = epx - pp->px;
        vc0.y = 0;
        vc0.z = epz - pp->pz;
        
        njUnitVector(&vc0);

        yr = 10430.381f * atan2f(-vc0.x, -vc0.z);
        
        *r = yr;
        *h = nr;
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
int bhSearchNearEnemyB(NJS_POINT3* pos, int ay, int ar, float len)
{
    NJS_VECTOR vc0, vc1, vc2; 
    NJS_CAPSULE cap; 
    float a;       
    float er;     
    float ln;   
    BH_PWORK* epp;
    int i;          

    if (ar == 0)
    {
        ar = 32768;
    }
    
    vc1.x = 0;
    vc1.y = 0;
    vc1.z = -1.0f;
    
    njUnitMatrix(NULL);
    
    njRotateY(NULL, ay);
    njCalcVector(NULL,  &vc1, &vc0);
    
    njRotateY(NULL, ar);
    njCalcVector(NULL, &vc1, &vc2);
    
    er = -njInnerProduct(&vc0, &vc2);
    
    cap.c1.x = pos->x;
    cap.c1.y = pos->y;
    cap.c1.z = pos->z;
    
    cap.r = 0.1f;
     
    epp = ene;
    
    for (i = 0; i < sys->ewk_n; i++, epp++) 
    {
        if ((((epp->flg & 0x1)) && ((epp->flg & 0x20)) && (!(epp->flg & 0x8002)) && (!(epp->flg2 & 0x10)) && (!(epp->stflg & 0x41000000))) && ((!(epp->flg & 0x80)) || (!(((O_WRK*)epp->lkwkp)->stflg & 0x1000000))))
        {
            cap.c2.x = 0.5f * (epp->watr.c1.x + epp->watr.c2.x);
            cap.c2.y = 0.5f * (epp->watr.c1.y + epp->watr.c2.y); 
            cap.c2.z = 0.5f * (epp->watr.c1.z + epp->watr.c2.z);
            
            vc1.x = pos->x - cap.c2.x;
            vc1.y = 0;
            vc1.z = pos->z - cap.c2.z;
            
            ln = njScalor(&vc1);
            
            if (ln <= len) 
            {
                njUnitVector(&vc1);
                
                a = njInnerProduct(&vc0, &vc1);
                
                if ((a < er) && (bhCheckC2WallN(&cap, 0x400) == 0)) 
                {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

// 100% matching!
int bhSearchNearEnemy2(BH_PWORK* pp, int* r, float* h, int* id) 
{
    NJS_VECTOR vc0, vc1, vc2;  
    NJS_CAPSULE cap; 
    float epx, epy, epz;   
    float a;        
    float er;      
    float ln;        
    float nr;      
    BH_PWORK* epp;  
    int i;        
    int idx;      
    int ar;       
    int yr;      

    cap.c1.x = plp->px;
    cap.c1.y = EXP1_F(16);
    cap.c1.z = plp->pz;
    
    cap.r = 0.1f;
    
    ar = *r;
    
    if (ar == 0)
    {
        ar = 32768;
    }
    
    vc1.x = 0;
    vc1.y = 0;
    vc1.z = -1.0f;
    
    njUnitMatrix(NULL);
    
    njRotateY(NULL, pp->ay);
    njCalcVector(NULL, &vc1, &vc0);
    
    njRotateY(NULL, ar);
    njCalcVector(NULL, &vc1, &vc2);
    
    er = -njInnerProduct(&vc0, &vc2);
    
    epp = ene;
    
    nr = 0;
    
    idx = -1;
    
    for (i = 0; i < sys->ewk_n; i++, epp++) 
    {
        if (((epp->flg & 0x1)) && (!(epp->flg & 0x8000)) && (!(epp->stflg & 0x41000000)) && ((!(epp->flg & 0x80)) || (!(((O_WRK*)epp->lkwkp)->stflg & 0x1000000))))
        {
            if (epp->lok_jno == 0) 
            {
                epx = epp->px;
                epy = epp->py;
                epz = epp->pz;
            } 
            else
            {
                epx = epp->mlwP->owP[epp->lok_jno].mtx[12];
                epy = epp->mlwP->owP[epp->lok_jno].mtx[13];
                epz = epp->mlwP->owP[epp->lok_jno].mtx[14];
            }
            
            vc1.x = EXP1_F(12) - epx;
            vc1.y = EXP1_F(16) - epy;
            vc1.z = EXP1_F(20) - epz;
            
            ln = njScalor(&vc1);
            
            if ((njInnerProduct(&vc0, &vc1) < er) && ((ln < nr) || (nr == 0))) 
            {
                cap.c2.x = epx;
                cap.c2.y = epy;
                cap.c2.z = epz;
                
                nr = ln;
                
                idx = i;
            }
        }
    }
    
    if (idx != -1) 
    {
        *id = idx;
        
        if (bhCheckC2WallN(&cap, 0x400) != 0)
        {
            return 0;
        }
        
        vc0.x = cap.c2.x - EXP1_F(12);
        vc0.y = 0;
        vc0.z = cap.c2.z - EXP1_F(20);
        
        njUnitVector(&vc0);

        yr = 10430.381f * atan2f(-vc0.x, -vc0.z);
        
        *r = yr;
        *h = nr;
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
int bhSearchNextEnemy(BH_PWORK* pp, int r, float h)
{
    NJS_VECTOR vc0, vc1, vc2;  
    NJS_CAPSULE cap;  
    float a;           
    float er;         
    float ln;        
    BH_PWORK* epp;
    int i, j, k;           
    int id, idc;     
    int yr;         
    SC_WORK scw[128]; 

    if (r == 0) 
    {
        r = 32768;
    }
    
    vc1.x =  0;
    vc1.y =  0;
    vc1.z = -1.0f; 
    
    njUnitMatrix(NULL);
    
    njRotateY(NULL, pp->ay);
    njCalcVector(NULL, &vc1, &vc0);
    
    njRotateY(NULL, r);
    njCalcVector(NULL, &vc1, &vc2);
    
    er = -njInnerProduct(&vc0, &vc2);
    
    id = -1;
    idc = 0;
    
    cap.c1.x = pp->px; 
    cap.c1.y = pp->py + h;
    cap.c1.z = pp->pz;
    cap.r    = 0.1f;
    
    epp = ene;
    
    for (i = 0; i < sys->ewk_n; i++, epp++) 
    {
        if ((((epp->flg & 0x1)) && ((epp->flg & 0x20)) && (!(epp->flg & 0x2)) && (!(epp->flg2 & 0x10))) && (!(epp->stflg & 0x41000000)) && ((!(epp->flg & 0x80)) || (!(((O_WRK*)epp->lkwkp)->stflg & 0x1000000)))) 
        {
            cap.c2.x = 0.5f * (epp->watr.c1.x + epp->watr.c2.x);
            cap.c2.y = 0.5f * (epp->watr.c1.y + epp->watr.c2.y);
            cap.c2.z = 0.5f * (epp->watr.c1.z + epp->watr.c2.z);
            
            vc1.x = pp->px - cap.c2.x;
            vc1.y = cap.c1.y - cap.c2.y;
            vc1.z = pp->pz - cap.c2.z;
            
            ln = njScalor(&vc1);
            
            vc1.y = 0;  
            
            njUnitVector(&vc1);
            
            if ((njInnerProduct(&vc0, &vc1) < er) && (bhCheckC2WallN(&cap, 0x40000400) == 0)) 
            {
                if (idc > 0)
                {
                    for (j = 0; j < idc; j++)
                    {
                        if (scw[j].ln > ln) 
                        { 
                            for (k = idc; k > j; k--) 
                            {
                                scw[k] = scw[k - 1]; 
                            } 
                            
                            scw[j].idx = i;
                            scw[j].ln  = ln;
                            break;
                        } 
                    }
                    
                    if (j == idc) 
                    {
                        scw[idc].idx = i;
                        scw[idc].ln  = ln;
                    }
                } 
                else 
                {
                    scw[idc].idx = i;
                    scw[idc].ln  = ln;
                }
                
                idc++;
            } 
            else
            {
                epp->stflg &= ~0x800;
            }
        }
    }
    
    yr = -1;
    
    if (idc != 0) 
    {
        for (i = 0; i < idc; i++) 
        {
            if (!(ene[scw[i].idx].stflg & 0x800)) 
            {
                id = scw[i].idx;
                break;
            } 
        }
        
        if (id == -1) 
        {
            for (j = 0; j < idc; j++) 
            {
                ene[scw[j].idx].stflg &= ~0x800;
            }
            
            if ((idc > 1) && (scw[0].idx == pp->src_no)) 
            {
                id = scw[1].idx; 
            }
            else 
            {
                id = scw[0].idx;
            }
        }
        
        epp = &ene[id];
        
        pp->src_no = id;
        
        epp->stflg |= 0x800;
        
        vc0.x = (0.5f * (epp->watr.c1.x + epp->watr.c2.x)) - pp->px;
        vc0.y = 0;
        vc0.z = (0.5f * (epp->watr.c1.z + epp->watr.c2.z)) - pp->pz;
        
        njUnitVector(&vc0);
        
        yr = 10430.381f * atan2f(-vc0.x, -vc0.z);
        
        if (yr == -1) 
        {
            yr = -2;
        }
    }
    else 
    {
        yr = -1;
    }
    
    return yr;
}

// 100% matching!
int bhSearchPlayer(BH_PWORK* pp, int r) 
{
    NJS_VECTOR vc0, vc1, vc2; 
    float a, er;      
    int yr;       
 
    if (r == 0) 
    {
        r = 32768;
    }
    
    vc1.x = 0;
    vc1.y = 0;
    vc1.z = -1.0f;
    
    njUnitMatrix(NULL);
    
    njRotateY(NULL, pp->ay);
    njCalcVector(NULL, &vc1, &vc0);
    
    njRotateY(NULL, r);
    njCalcVector(NULL, &vc1, &vc2);
    
    er = -njInnerProduct(&vc0, &vc2);
    
    vc1.x = pp->px - plp->px;
    vc1.y = pp->py - plp->py;
    vc1.z = pp->pz - plp->pz;
    
    njUnitVector(&vc1);
    
    a = njInnerProduct(&vc0, &vc1);
    
    if (a < er)
    {
        vc0.x = plp->px - pp->px;
        vc0.z = plp->pz - pp->pz;
        
        yr = (int)(10430.381f * atan2f(-vc0.x, -vc0.z));
        
        if (yr == -1) 
        {
            yr = -2;
        }
    } 
    else 
    {
        yr = -1;
    }
    
    return yr;
}

// 100% matching!
int bhCheckL2Wall(NJS_LINE* lp, unsigned int flg, float* len) 
{
    ATR_WORK* hp;     
    NJS_BOX box;      
    NJS_CAPSULE cap, cap2;  
    NJS_LINE pl;      
    NJS_POINT3 ps;    
    NJS_POINT3 pt;   
    float* psp;      
    float px, py, pz;      
    float w, h, d;     
    float nr;   
    float ln;    
    float lr;        
    int i;         
    int wal_n;       
    int hit;      
    NJS_LINE cln;    

    psp = len;
    
    cap.c1.x = lp->px;
    cap.c1.y = lp->py;
    cap.c1.z = lp->pz;
    
    cap.c2.x = lp->px + lp->vx;
    cap.c2.y = lp->py + lp->vy;
    cap.c2.z = lp->pz + lp->vz; 
    
    cap.r = 0.01f;
    
    nr = njScalor((NJS_VECTOR*)&lp->vx);
    
    hit = 0;
    
    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++) 
    {
        if (i < rom->wal_n) 
        {
            hp = &rom->walp[i];
        } 
        else 
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if ((hp->flg & 0x1)) 
        {
            px = hp->px;
            py = hp->py;
            pz = hp->pz;
            
            w = hp->w;
            h = hp->h;
            d = hp->d;
            
            if (!h) 
            {
                h = rom->h;
            }

            switch (hp->type) 
            {                  
            case 0:                             
            case 1:                             
                if ((!(hp->type & 0x1)) || (!(flg & 0x400))) 
                {
                    box.v[0].x = px;
                    box.v[0].y = py + h;
                    box.v[0].z = pz + d;
                    
                    box.v[1].x = px;
                    box.v[1].y = py + h;
                    box.v[1].z = pz;
                    
                    box.v[2].x = px + w;
                    box.v[2].y = py + h;
                    box.v[2].z = pz;
                    
                    box.v[3].x = px + w;
                    box.v[3].y = py + h;
                    box.v[3].z = pz + d;
                    
                    box.v[4].x = px;
                    box.v[4].y = py;
                    box.v[4].z = pz + d;
                    
                    box.v[5].x = px;
                    box.v[5].y = py;
                    box.v[5].z = pz;
                    
                    box.v[6].x = px + w;
                    box.v[6].y = py;
                    box.v[6].z = pz;
                    
                    box.v[7].x = px + w;
                    box.v[7].y = py; 
                    box.v[7].z = pz + d;
                    
                    if (njCollisionCheckBC(&box, &cap) != 0)
                    {
                        pl.px = px;
                        pl.py = (py + h) - 0.1f;
                        pl.pz = pz;
                        
                        pl.vx = 0;
                        pl.vy = 1.0f;
                        pl.vz = 0;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt))
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz; 
                            
                            ln = njScalor(&ps);
                            
                            ps.x = pt.x - px;
                            ps.y = pt.y - py;
                            ps.z = pt.z - pz;
                            
                            if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y >= 0) && (ps.y <= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                            {
                                nr = ln;
                                
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                        
                        pl.px = px;
                        pl.py = 0.1f + py;
                        pl.pz = pz;
                        
                        pl.vx = 0;
                        pl.vy = -1.0f;
                        pl.vz = 0;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt)) 
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            ps.x = pt.x - px;
                            ps.y = pt.y - py;
                            ps.z = pt.z - pz;
                            
                            if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y >= 0) && (ps.y <= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                            {
                                nr = ln;
                                
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                        
                        pl.px = 0.1f + px;
                        pl.py = py;
                        pl.pz = pz;
                        
                        pl.vx = -1.0f;
                        pl.vy = 0;
                        pl.vz = 0;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt)) 
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            ps.x = pt.x - px;
                            ps.y = pt.y - py;
                            ps.z = pt.z - pz;
                            
                            if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y >= 0) && (ps.y <= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                            {
                                nr = ln;
                                
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                        
                        pl.px = (px + w) - 0.1f;
                        pl.py = py;
                        pl.pz = pz;
                        
                        pl.vx = 1.0f;
                        pl.vy = 0;
                        pl.vz = 0;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt)) 
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            ps.x = pt.x - px;
                            ps.y = pt.y - py;
                            ps.z = pt.z - pz;
                            
                            if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y >= 0) && (ps.y <= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                            {
                                nr = ln;
                                
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                        
                        pl.px = px; 
                        pl.py = py;
                        pl.pz = 0.1f + pz;
                        
                        pl.vx = 0;
                        pl.vy = 0;
                        pl.vz = -1.0f;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt))
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            ps.x = pt.x - px;
                            ps.y = pt.y - py;
                            ps.z = pt.z - pz;
                            
                            if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y >= 0) && (ps.y <= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                            {
                                nr = ln;
                                
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                        
                        pl.px = px;
                        pl.py = py;
                        pl.pz = (pz + d) - 0.1f;
                        
                        pl.vx = 0;
                        pl.vy = 0;
                        pl.vz = 1.0f;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt)) 
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            ps.x = pt.x - px;
                            ps.y = pt.y - py;
                            ps.z = pt.z - pz;
                            
                            if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y >= 0) && (ps.y <= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                            {
                                nr = ln;
                                
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                    }
                } 
                
                break;
            case 2:                             
            case 3:                             
                if ((!(hp->type & 0x1)) || (!(flg & 0x400)))
                {
                    cap2.c1.x = px;
                    cap2.c1.y = py;
                    cap2.c1.z = pz;
                    
                    cap2.c2.x = px;
                    cap2.c2.y = py + h;
                    cap2.c2.z = pz;
                    
                    cap2.r = w;
                    
                    if (npCollisionCheckCC(&cap2, &cap) != 0) 
                    {
                        pl.px = px;
                        pl.py = (py + h) - 0.1f;
                        pl.pz = pz;
                        
                        pl.vx = 0;
                        pl.vy = 1.0f;
                        pl.vz = 0;
                        
                        if (njIsParalellL2PL(lp, &pl) == 0) 
                        {
                            if (!njDistanceL2PL(lp, &pl, &pt)) 
                            {
                                ps.x = pt.x - lp->px;
                                ps.y = pt.y - lp->py;
                                ps.z = pt.z - lp->pz;
                                
                                ln = njScalor(&ps);
                                
                                ps.x = pt.x - px;
                                ps.y = 0;
                                ps.z = pt.z - pz;
                                
                                lr = njScalor(&ps);
                                
                                ps.y = pt.y - py;
                                
                                if (((lr < w) && (ln < nr)) && ((ps.y >= 0) && (ps.y <= h)))
                                {
                                    nr = ln;
                        
                                    sys->apos = pt;
                                    
                                    hit++;
                                    
                                    sys->ahtp = hp;
                                    
                                    cap.c2 = pt;
                                }
                            }
                            
                            pl.px = px;
                            pl.py = 0.1f + py;
                            pl.pz = pz;
                            
                            pl.vx = 0;
                            pl.vy = -1.0f;
                            pl.vz = 0;
                            
                            if (!njDistanceL2PL(lp, &pl, &pt)) 
                            {
                                ps.x = pt.x - lp->px;
                                ps.y = pt.y - lp->py;
                                ps.z = pt.z - lp->pz;
                                
                                ln = njScalor(&ps);
                                
                                ps.x = pt.x - px;
                                ps.y = 0;
                                ps.z = pt.z - pz;
                                
                                lr = njScalor((NJS_VECTOR*)&ps.x);
                                
                                ps.y = pt.y - py;
                                
                                if (((lr < w) && (ln < nr)) && ((ps.y >= 0) && (ps.y <= h)))
                                {
                                    nr = ln;
                        
                                    sys->apos = pt;
                                    
                                    hit++;
                                    
                                    sys->ahtp = hp;
                                    
                                    cap.c2 = pt;
                                }
                            }
                        }
                        
                        cln.px = px;
                        cln.py = py;
                        cln.pz = pz;
                        
                        cln.vx = 0;
                        cln.vy = h;
                        cln.vz = 0;
                        
                        njDistanceL2L(lp, &cln, &pt, &ps);
                        
                        ps.x = pt.x - px;
                        ps.y = 0;
                        ps.z = pt.z - pz;
                        
                        if (njScalor(&ps) < w) 
                        {
                            ps.x = lp->px - px;
                            ps.y = 0;
                            ps.z = lp->pz - pz;
                            
                            njUnitVector(&ps);
                            
                            pl.px = px + (ps.x * w);
                            pl.py = py;
                            pl.pz = pz + (ps.z * w);
                            
                            pl.vx = ps.x;
                            pl.vy = 0;
                            pl.vz = ps.z;
                            
                            if (!njDistanceL2PL(lp, &pl, &pt))
                            {
                                ps.x = pt.x - px;
                                ps.y = 0;
                                ps.z = pt.z - pz;
                                
                                njUnitVector(&ps);
                                
                                pt.x = px + (ps.x * w);
                                pt.z = pz + (ps.z * w);
                                
                                ps.x = pt.x - lp->px;
                                ps.y = pt.y - lp->py;
                                ps.z = pt.z - lp->pz;
                                
                                ln = njScalor(&ps); 
                                
                                ps.y = pt.y - py;
                                
                                if ((ln < nr) && ((ps.y >= 0) && (ps.y <= h))) 
                                {
                                    nr = ln;
                        
                                    sys->apos = pt;
                                    
                                    hit++;
                                    
                                    sys->ahtp = hp;
                                    
                                    cap.c2 = pt;
                                }
                            }
                        }
                    }
                }
                
                break;
            case 4:                             
            case 5:                             
                if ((!(hp->type & 0x1)) || (!(flg & 0x400))) 
                {
                    switch (hp->id) 
                    {
                    case 0:
                        box.v[0].x = px;
                        box.v[0].y = py + h;
                        box.v[0].z = pz + d;
                        
                        box.v[1].x = px;
                        box.v[1].y = py + h;
                        box.v[1].z = pz;
                        
                        box.v[2].x = px + w;
                        box.v[2].y = py + h;
                        box.v[2].z = pz;
                        
                        box.v[3].x = px + w;
                        box.v[3].y = py + h;
                        box.v[3].z = pz + d;
                        
                        box.v[4].x = px;
                        box.v[4].y = py;
                        box.v[4].z = pz + d;
                        
                        box.v[5].x = px;
                        box.v[5].y = py;
                        box.v[5].z = pz;
                        
                        box.v[6].x = px + w;
                        box.v[6].y = py; 
                        box.v[6].z = pz;
                        
                        box.v[7].x = px + w;
                        box.v[7].y = py;
                        box.v[7].z = pz + d;
                        break;
                    case 1:
                        box.v[0].x = px;
                        box.v[0].y = py + h;
                        box.v[0].z = pz;
                        
                        box.v[1].x = px;
                        box.v[1].y = py + h;
                        box.v[1].z = pz + d;
                        
                        box.v[2].x = px + w;
                        box.v[2].y = py + h;
                        box.v[2].z = pz + d;
                        
                        box.v[3].x = px + w;
                        box.v[3].y = py + h;
                        box.v[3].z = pz;
                        
                        box.v[4].x = px;
                        box.v[4].y = py;
                        box.v[4].z = pz;
                        
                        box.v[5].x = px;
                        box.v[5].y = py;
                        box.v[5].z = pz + d;
                        
                        box.v[6].x = px + w;
                        box.v[6].y = py;
                        box.v[6].z = pz + d;
                        
                        box.v[7].x = px + w;
                        box.v[7].y = py;
                        box.v[7].z = pz;
                        break;
                    case 2:
                        box.v[0].x = px + w;
                        box.v[0].y = py + h;
                        box.v[0].z = pz + d;
                        
                        box.v[1].x = px + w;
                        box.v[1].y = py + h;
                        box.v[1].z = pz;
                        
                        box.v[2].x = px;
                        box.v[2].y = py + h;
                        box.v[2].z = pz;
                        
                        box.v[3].x = px;
                        box.v[3].y = py + h;
                        box.v[3].z = pz + d;
                        
                        box.v[4].x = px + w;
                        box.v[4].y = py;
                        box.v[4].z = pz + d;
                        
                        box.v[5].x = px + w;
                        box.v[5].y = py;
                        box.v[5].z = pz;
                        
                        box.v[6].x = px;
                        box.v[6].y = py;
                        box.v[6].z = pz;
                        
                        box.v[7].x = px;
                        box.v[7].y = py;
                        box.v[7].z = pz + d;
                        break;
                    case 3:
                        box.v[0].x = px + w;
                        box.v[0].y = py + h;
                        box.v[0].z = pz;
                        
                        box.v[1].x = px + w;
                        box.v[1].y = py + h;
                        box.v[1].z = pz + d;
                        
                        box.v[2].x = px;
                        box.v[2].y = py + h;
                        box.v[2].z = pz + d;
                        
                        box.v[3].x = px;
                        box.v[3].y = py + h;
                        box.v[3].z = pz;
                        
                        box.v[4].x = px + w;
                        box.v[4].y = py;
                        box.v[4].z = pz;
                        
                        box.v[5].x = px + w;
                        box.v[5].y = py;
                        box.v[5].z = pz + d;
                        
                        box.v[6].x = px;
                        box.v[6].y = py;
                        box.v[6].z = pz + d;
                        
                        box.v[7].x = px;
                        box.v[7].y = py;
                        box.v[7].z = pz;
                        break;
                    }
                    
                    if (njCollisionCheckBC(&box, &cap) != 0) 
                    {
                        pl.px = px;
                        pl.py = (py + h) - 0.1f;
                        pl.pz = pz;
                        
                        pl.vx = 0;
                        pl.vy = 1.0f;
                        pl.vz = 0;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt)) 
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                            {
                                nr = ln;
                            
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                        
                        pl.px = px;
                        pl.py = 0.1f + py;
                        pl.pz = pz;
                        
                        pl.vx = 0;
                        pl.vy = -1.0f;
                        pl.vz = 0;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt)) 
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                            {
                                nr = ln;
                            
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                        
                        pl.px = px; 
                        pl.py = py;
                        
                        if (d >= 0) 
                        {
                            pl.pz = 0.1f + pz;
                        }
                        else 
                        {
                            pl.pz = pz - 0.1f;
                        }
                        
                        pl.vx = 0;
                        pl.vy = 0;
                        pl.vz = 1.0f;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt)) 
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                            {
                                nr = ln;
                            
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                        
                        if (w >= 0) 
                        {
                            pl.px = 0.1f + px;
                        } 
                        else 
                        {
                            pl.px = px - 0.1f;
                        }
                        
                        pl.py = py;
                        pl.pz = pz;
                        
                        pl.vx = 1.0f;
                        pl.vy = 0;
                        pl.vz = 0;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt)) 
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                            {
                                nr = ln;
                            
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                        
                        pl.px = px + w;
                        pl.pz = pz;
                        pl.py = py;
                        
                        pl.vy = 0;
                        
                        switch (hp->id) 
                        {  
                        case 0:  
                        case 3:
                            pl.vx = d;
                            pl.vz = w;
                            break;
                        case 1:  
                        case 2:
                            pl.vx = -d;
                            pl.vz = -w;
                            break;
                        }
                        
                        njUnitVector((NJS_VECTOR*)&pl.vx);
                        
                        pl.px -= 0.1f * pl.vx;
                        pl.pz -= 0.1f * pl.vz;
                        
                        if (!njDistanceL2PL(lp, &pl, &pt)) 
                        {
                            ps.x = pt.x - lp->px;
                            ps.y = pt.y - lp->py;
                            ps.z = pt.z - lp->pz;
                            
                            ln = njScalor(&ps);
                            
                            if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                            {
                                nr = ln;
                            
                                sys->apos = pt;
                                
                                hit++;
                                
                                sys->ahtp = hp;
                                
                                cap.c2 = pt;
                            }
                        }
                    }
                } 
                
                break;
            case 6:                             
                box.v[0].x = px;
                box.v[0].y = py + h;
                box.v[0].z = pz + d;
                
                box.v[1].x = px;
                box.v[1].y = py + h;
                box.v[1].z = pz;
                
                box.v[2].x = px + w;
                box.v[2].y = py + h;
                box.v[2].z = pz;
                
                box.v[3].x = px + w;
                box.v[3].y = py + h;
                box.v[3].z = pz + d;
                
                box.v[4].x = px;
                box.v[4].y = py;
                box.v[4].z = pz + d;
                
                box.v[5].x = px;
                box.v[5].y = py;
                box.v[5].z = pz;
                
                box.v[6].x = px + w;
                box.v[6].y = py;
                box.v[6].z = pz;
                
                box.v[7].x = px + w;
                box.v[7].y = py;
                box.v[7].z = pz + d;
                
                if (njCollisionCheckBC(&box, &cap) != 0) 
                {
                    switch (hp->id) 
                    {        
                    case 0:                     
                        pl.px = px;
                        pl.py = py;
                        pl.pz = pz;
                        
                        pl.vx = -h;
                        pl.vy = w;
                        pl.vz = 0;
                        
                        njUnitVector((NJS_VECTOR*)&pl.vx);
                        break;
                    case 1:                     
                        pl.px = px;
                        pl.py = py;
                        pl.pz = pz + d;
                        
                        pl.vx = 0;
                        pl.vy = d;
                        pl.vz = h;
                        
                        njUnitVector((NJS_VECTOR*)&pl.vx);
                        break;
                    case 2:                     
                        pl.px = px;
                        pl.py = py;
                        pl.pz = pz;
                        
                        pl.vx = 0;
                        pl.vy = d;
                        pl.vz = -h;
                        
                        njUnitVector((NJS_VECTOR*)&pl.vx);
                        break;
                    case 3:                     
                        pl.px = px + w;
                        pl.py = py;
                        pl.pz = pz;
                        
                        pl.vx = h;
                        pl.vy = w;
                        pl.vz = 0;
                        
                        njUnitVector((NJS_VECTOR*)&pl.vx);
                        break;
                    }
                    
                    if (!njDistanceL2PL(lp, &pl, &pt)) 
                    {
                        ps.x = pt.x - lp->px;
                        ps.y = pt.y - lp->py;
                        ps.z = pt.z - lp->pz;
                        
                        ln = njScalor(&ps);
                        
                        ps.x = pt.x - px;
                        ps.y = pt.y - py;
                        ps.z = pt.z - pz;
                        
                        if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y >= 0) && (ps.y <= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                        {
                            nr = ln;
                            
                            sys->apos = pt;
                            
                            hit++;
                            
                            sys->ahtp = hp;
                            
                            cap.c2 = pt;
                        } 
                    }
                }
                
                break;
            case 7:                             
                box.v[0].x = px;
                box.v[0].y = py - 0.1f;
                box.v[0].z = pz + d;
                
                box.v[1].x = px;
                box.v[1].y = py - 0.1f;
                box.v[1].z = pz;
                
                box.v[2].x = px + w;
                box.v[2].y = py - 0.1f;
                box.v[2].z = pz;
                
                box.v[3].x = px + w;
                box.v[3].y = py - 0.1f;
                box.v[3].z = pz + d;
                
                box.v[4].x = px;
                box.v[4].y = py + h;
                box.v[4].z = pz + d;
                
                box.v[5].x = px;
                box.v[5].y = py + h;
                box.v[5].z = pz;
                
                box.v[6].x = px + w;
                box.v[6].y = py + h;
                box.v[6].z = pz;
                
                box.v[7].x = px + w;
                box.v[7].y = py + h;
                box.v[7].z = pz + d;
                
                if (njCollisionCheckBC(&box, &cap) != 0) 
                {
                    pl.px = px;
                    pl.py = py - 0.1f;
                    pl.pz = pz;
                    
                    pl.vx = 0;
                    pl.vy = 1.0f;
                    pl.vz = 0;
                    
                    if (!njDistanceL2PL(lp, &pl, &pt)) 
                    {
                        ps.x = pt.x - lp->px;
                        ps.y = pt.y - lp->py;
                        ps.z = pt.z - lp->pz;
                        
                        ln = njScalor(&ps);
                        
                        ps.x = pt.x - px;
                        ps.y = pt.y - py;
                        ps.z = pt.z - pz;
                        
                        if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y <= 0) && (ps.y >= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                        {
                            nr = ln;
                            
                            sys->apos = pt;
                            
                            hit++;
                            
                            sys->ahtp = hp;
                            
                            cap.c2 = pt;
                        } 
                    }
                    
                    pl.px = px;
                    pl.py = 0.1f + (py + h);
                    pl.pz = pz;
                    
                    pl.vx = 0;
                    pl.vy = -1.0f;
                    pl.vz = 0;
                    
                    if (!njDistanceL2PL(lp, &pl, &pt)) 
                    {
                        ps.x = pt.x - lp->px;
                        ps.y = pt.y - lp->py;
                        ps.z = pt.z - lp->pz;
                        
                        ln = njScalor(&ps);
                        
                        ps.x = pt.x - px;
                        ps.y = pt.y - py;
                        ps.z = pt.z - pz;
                        
                        if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y <= 0) && (ps.y >= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                        {
                            nr = ln;
                            
                            sys->apos = pt;
                            
                            hit++;
                            
                            sys->ahtp = hp;
                            
                            cap.c2 = pt;
                        }
                    }
                    
                    pl.px = 0.1f + px;
                    pl.py = py;
                    pl.pz = pz;
                    
                    pl.vx = -1.0f;
                    pl.vy = 0;
                    pl.vz = 0;
                    
                    if (!njDistanceL2PL(lp, &pl, &pt)) 
                    {
                        ps.x = pt.x - lp->px;
                        ps.y = pt.y - lp->py;
                        ps.z = pt.z - lp->pz;
                        
                        ln = njScalor(&ps);
                        
                        ps.x = pt.x - px;
                        ps.y = pt.y - py;
                        ps.z = pt.z - pz;
                        
                        if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y <= 0) && (ps.y >= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                        {
                            nr = ln;
                            
                            sys->apos = pt;
                            
                            hit++;
                            
                            sys->ahtp = hp;
                            
                            cap.c2 = pt;
                        }
                    }
                    
                    pl.px = (px + w) - 0.1f;
                    pl.py = py;
                    pl.pz = pz;
                    
                    pl.vx = 1.0f;
                    pl.vy = 0;
                    pl.vz = 0;
                    
                    if (!njDistanceL2PL(lp, &pl, &pt)) 
                    {
                        ps.x = pt.x - lp->px;
                        ps.y = pt.y - lp->py;
                        ps.z = pt.z - lp->pz;
                        
                        ln = njScalor(&ps);
                        
                        ps.x = pt.x - px;
                        ps.y = pt.y - py;
                        ps.z = pt.z - pz;
                        
                        if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y <= 0) && (ps.y >= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                        {
                            nr = ln;
                            
                            sys->apos = pt;
                            
                            hit++;
                            
                            sys->ahtp = hp;
                            
                            cap.c2 = pt;
                        }
                    }
                    
                    pl.px = px;
                    pl.py = py;
                    pl.pz = 0.1f + pz;
                    
                    pl.vx = 0;
                    pl.vy = 0;
                    pl.vz = -1.0f;
                    
                    if (!njDistanceL2PL(lp, &pl, &pt)) 
                    {
                        ps.x = pt.x - lp->px;
                        ps.y = pt.y - lp->py;
                        ps.z = pt.z - lp->pz;
                        
                        ln = njScalor(&ps);
                        
                        ps.x = pt.x - px;
                        ps.y = pt.y - py;
                        ps.z = pt.z - pz;
                        
                        if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y <= 0) && (ps.y >= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                        {
                            nr = ln;
                            
                            sys->apos = pt;
                            
                            hit++;
                            
                            sys->ahtp = hp;
                            
                            cap.c2 = pt;
                        }
                    }
                    
                    pl.px = px;
                    pl.py = py;
                    pl.pz = (pz + d) - 0.1f;
                    
                    pl.vx = 0;
                    pl.vy = 0;
                    pl.vz = 1.0f;
                    
                    if (!njDistanceL2PL(lp, &pl, &pt)) 
                    {
                        ps.x = pt.x - lp->px;
                        ps.y = pt.y - lp->py;
                        ps.z = pt.z - lp->pz;
                        
                        ln = njScalor(&ps);
                        
                        ps.x = pt.x - px;
                        ps.y = pt.y - py;
                        ps.z = pt.z - pz;
                        
                        if (((ps.x >= 0) && (ps.x <= w)) && ((ps.y <= 0) && (ps.y >= h)) && ((ps.z >= 0) && (ps.z <= d)) && (ln < nr))
                        {
                            nr = ln;
                            
                            sys->apos = pt;
                            
                            hit++;
                            
                            sys->ahtp = hp;
                            
                            cap.c2 = pt;
                        }
                    }
                }
                
                break;
            }
        }
    }
    
    *psp = nr;
    
    if (hit == 0) 
    {
        sys->apos.x = lp->px + lp->vx;
        sys->apos.y = lp->py + lp->vy;
        sys->apos.z = lp->pz + lp->vz;
        
        sys->ahtp = NULL;
        
        return 0; 
    }
    
    return 1;
}

// 100% matching!
int bhCheckC2Wall(NJS_CAPSULE* cap) 
{
    ATR_WORK* hp;     
    NJS_BOX box;      
    NJS_CAPSULE cap2;
    NJS_LINE lp;    
    NJS_LINE pl;      
    NJS_POINT3 ps;  
    NJS_POINT3 pt;  
    NJS_POINT3 p[3]; 
    float* psp;      
    float px, py, pz;    
    float w, h, d;      
    float nr;     
    float ln;      
    int i;      
    int wal_n;       
    
    lp.px = cap->c1.x;
    lp.py = cap->c1.y;
    lp.pz = cap->c1.z;
    
    lp.vx = cap->c2.x - lp.px;
    lp.vy = cap->c2.y - lp.py;
    lp.vz = cap->c2.z - lp.pz;
    
    nr = njScalor((NJS_VECTOR*)&lp.vx); 
    
    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++) 
    {
        if (i < rom->wal_n) 
        {
            hp = &rom->walp[i];
        } 
        else
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if (((hp->flg & 0x1)) && (!(hp->attr & 0x10))) 
        {
            px = hp->px;
            py = hp->py;
            pz = hp->pz;
            
            w = hp->w;
            h = hp->h;
            d = hp->d;
            
            if (!h) 
            {
                h = rom->h;
            }
            
            switch (hp->type) 
            {                      
            case 0:
                box.v[0].x = px;
                box.v[0].y = py + h;
                box.v[0].z = pz + d;
                
                box.v[1].x = px;
                box.v[1].y = py + h;
                box.v[1].z = pz;
                
                box.v[2].x = px + w;
                box.v[2].y = py + h;
                box.v[2].z = pz;
                
                box.v[3].x = px + w;
                box.v[3].y = py + h;
                box.v[3].z = pz + d;
                
                box.v[4].x = px;
                box.v[4].y = py;
                box.v[4].z = pz + d;
                
                box.v[5].x = px;
                box.v[5].y = py;
                box.v[5].z = pz;
                
                box.v[6].x = px + w;
                box.v[6].y = py;
                box.v[6].z = pz;
                
                box.v[7].x = px + w;
                box.v[7].y = py;
                box.v[7].z = pz + d;
                
                if (njCollisionCheckBC(&box, cap) != 0)
                {
                    return 1;
                }
                
                break;
            case 2:
                cap2.c1.x = px;
                cap2.c1.y = py;
                cap2.c1.z = pz;
                
                cap2.c2.x = px;
                cap2.c2.y = py + h;
                cap2.c2.z = pz;
                
                cap2.r = w;
                
                if (npCollisionCheckCC(&cap2, cap) != 0)
                {
                    return 1;
                }
                
                break;
            case 4:
                pl.px = px;
                pl.py = (py + h) - 0.1f;
                pl.pz = pz;
                
                pl.vx = 0;
                pl.vy = 1.0f;
                pl.vz = 0;
                
                if (!njDistanceL2PL(&lp, &pl, &pt)) 
                {
                    ps.x = pt.x - lp.px;
                    ps.y = pt.y - lp.py;
                    ps.z = pt.z - lp.pz;
                    
                    if (njInnerProduct((NJS_VECTOR*)&lp.vx, &ps) > 0) 
                    {
                        ln = njScalor(&ps);
                        
                        if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                        {
                            return 1;
                        }
                    }
                }
                
                pl.px = px;
                pl.py = py;
                pl.pz = pz;
                
                pl.vx = 0;
                pl.vy = -1.0f;
                pl.vz = 0;
                
                if (!njDistanceL2PL(&lp, &pl, &pt)) 
                {
                    ps.x = pt.x - lp.px;
                    ps.y = pt.y - lp.py;
                    ps.z = pt.z - lp.pz;
                    
                    if (njInnerProduct((NJS_VECTOR*)&lp.vx, &ps) > 0) 
                    {
                        ln = njScalor(&ps);
                        
                        if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                        {
                            return 1;
                        }
                    }
                }
                
                p[0].x = px;
                p[0].y = py;
                p[0].z = pz;
                
                p[1].x = px + w;
                p[1].y = py;
                p[1].z = pz + d;
                
                p[2].x = px;
                p[2].y = py + h;
                p[2].z = pz;
                
                njGetPlaneNormal(p, (NJS_VECTOR*)&pl.vx);
                
                pl.px = px + (0.5f * w);
                pl.py = py + (0.5f * h);
                pl.pz = pz + (0.5f * d);
                
                njDistanceL2PL(&lp, &pl, &pt);
                
                ps.x = pt.x - lp.px;
                ps.y = pt.y - lp.py;
                ps.z = pt.z - lp.pz;
                
                if (njInnerProduct((NJS_VECTOR*)&lp.vx, &ps) > 0) 
                {
                    ln = njScalor(&ps);
                    
                    if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                    {
                        return 1;
                    }
                }
                
                p[0].x = px + w;
                p[0].y = py;
                p[0].z = pz;
                
                p[1].x = px;
                p[1].y = py;
                p[1].z = pz + d;
                
                p[2].x = px + w;
                p[2].y = py + h;
                p[2].z = pz;
                
                njGetPlaneNormal(p, (NJS_VECTOR*)&pl.vx);
                
                pl.px = px + (0.49f * w);
                pl.py = py + (0.5f  * h);
                pl.pz = pz + (0.49f * d);
                
                njDistanceL2PL(&lp, &pl, &pt);
                
                ps.x = pt.x - lp.px;
                ps.y = pt.y - lp.py;
                ps.z = pt.z - lp.pz;
                
                if (njInnerProduct((NJS_VECTOR*)&lp.vx, &ps) > 0) 
                {
                    ln = njScalor(&ps);
                    
                    if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                    {
                        return 1;
                    }
                }
                
                break;
            case 7:
                box.v[0].x = px;
                box.v[0].y = py - 0.1f;
                box.v[0].z = pz + d;
                
                box.v[1].x = px;
                box.v[1].y = py - 0.1f;
                box.v[1].z = pz;
                
                box.v[2].x = px + w;
                box.v[2].y = py - 0.1f;
                box.v[2].z = pz;
                
                box.v[3].x = px + w;
                box.v[3].y = py - 0.1f;
                box.v[3].z = pz + d;
                
                box.v[4].x = px;
                box.v[4].y = py + h;
                box.v[4].z = pz + d;
                
                box.v[5].x = px;
                box.v[5].y = py + h;
                box.v[5].z = pz;
                
                box.v[6].x = px + w;
                box.v[6].y = py + h;
                box.v[6].z = pz;
                
                box.v[7].x = px + w;
                box.v[7].y = py + h;
                box.v[7].z = pz + d;
                
                if (njCollisionCheckBC(&box, cap) != 0) 
                {
                    return 1;
                }
                
                break;
            }
        } 
    }
    
    return 0;
}

// 99.97% matching
int bhCheckC2WallN(NJS_CAPSULE* cap, unsigned int flg)
{
    ATR_WORK* hp;     
    NJS_BOX box;    
    NJS_CAPSULE cap2; 
    NJS_LINE lp;     
    NJS_LINE pl;      
    NJS_POINT3 ps;   
    NJS_POINT3 pt;    
    NJS_POINT3 p[3]; 
    float* psp;     
    float px, py, pz;       
    float w, h, d;     
    float nr;       
    float ln;       
    int i;          
    int wal_n;   
    
    lp.px = cap->c1.x;
    lp.py = cap->c1.y;
    lp.pz = cap->c1.z;
    
    lp.vx = cap->c2.x - lp.px;
    lp.vy = cap->c2.y - lp.py;
    lp.vz = cap->c2.z - lp.pz;
    
    nr = njScalor((NJS_VECTOR*)&lp.vx); 
    
    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++) 
    {
        if (i < rom->wal_n) 
        {
            hp = &rom->walp[i];
        } 
        else 
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if ((((hp->flg & 0x1)) && ((!(hp->attr & 0x2000000)) || (!(flg & 0x40000000)))))
        {
            px = hp->px;
            py = hp->py;
            pz = hp->pz;
            
            w = hp->w;
            h = hp->h;
            d = hp->d;
            
            if (!h) 
            {
                h = rom->h;
            }
            
            switch (hp->type) 
            {                      
            case 0:
            case 1:
                if ((!(hp->type & 0x1)) || (!(flg & 0x400))) 
                {
                    box.v[0].x = px;
                    box.v[0].y = py + h;
                    box.v[0].z = pz + d;
                    
                    box.v[1].x = px;
                    box.v[1].y = py + h;
                    box.v[1].z = pz;
                    
                    box.v[2].x = px + w;
                    box.v[2].y = py + h;
                    box.v[2].z = pz;
                    
                    box.v[3].x = px + w;
                    box.v[3].y = py + h;
                    box.v[3].z = pz + d;
                    
                    box.v[4].x = px;
                    box.v[4].y = py;
                    box.v[4].z = pz + d;
                    
                    box.v[5].x = px;
                    box.v[5].y = py;
                    box.v[5].z = pz;
                    
                    box.v[6].x = px + w;
                    box.v[6].y = py;
                    box.v[6].z = pz;
                    
                    box.v[7].x = px + w;
                    box.v[7].y = py;
                    box.v[7].z = pz + d;
                    
                    if (njCollisionCheckBC(&box, cap) != 0) 
                    {
                        return 1;
                    }
                }
                
                break;
            case 2:
            case 3:
                if ((!(hp->type & 0x1)) || (!(flg & 0x400))) 
                {
                    cap2.c1.x = px;
                    cap2.c1.y = py;
                    cap2.c1.z = pz;
                    
                    cap2.c2.x = px;
                    cap2.c2.y = py + h;
                    cap2.c2.z = pz;
                    
                    cap2.r = w;
                    
                    if (npCollisionCheckCC(&cap2, cap) != 0) 
                    {
                        return 1;
                    }
                }
                
                break;
            case 4:
            case 5:
                if ((!(hp->type & 0x1)) || (!(flg & 0x400))) 
                {
                    pl.px = px;
                    pl.py = (py + h) - 0.1f;
                    pl.pz = pz;
                    
                    pl.vx = 0;
                    pl.vy = 1.0f;
                    pl.vz = 0;
                    
                    if (!njDistanceL2PL(&lp, &pl, &pt))
                    {
                        ps.x = pt.x - lp.px;
                        ps.y = pt.y - lp.py;
                        ps.z = pt.z - lp.pz;
                        
                        if (njInnerProduct((NJS_VECTOR*)&lp.vx, &ps) > 0) 
                        {
                            ln = njScalor(&ps);
                            
                            if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                            {
                                return 1;
                            }
                        }
                    }
                    
                    pl.px = px;
                    pl.py = py;
                    pl.pz = pz;
                    
                    pl.vx = 0;
                    pl.vy = -1.0f;
                    pl.vz = 0;
                    
                    if (!njDistanceL2PL(&lp, &pl, &pt)) 
                    {
                        ps.x = pt.x - lp.px;
                        ps.y = pt.y - lp.py;
                        ps.z = pt.z - lp.pz;
                        
                        if (njInnerProduct((NJS_VECTOR*)&lp.vx, &ps) > 0) 
                        {
                            ln = njScalor(&ps);
                            
                            if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                            {
                                return 1;
                            }
                        }
                    }
                    
                    p[0].x = px;
                    p[0].y = py;
                    p[0].z = pz;
                    
                    p[1].x = px + w;
                    p[1].y = py;
                    p[1].z = pz + d;
                    
                    p[2].x = px;
                    p[2].y = py + h;
                    p[2].z = pz;
                    
                    njGetPlaneNormal(p, (NJS_VECTOR*)&pl.vx);
                    
                    pl.px = px + (0.5f * w);
                    pl.py = py + (0.5f * h);
                    pl.pz = pz + (0.5f * d);
                    
                    njDistanceL2PL(&lp, &pl, &pt);
                    
                    ps.x = pt.x - lp.px;
                    ps.y = pt.y - lp.py;
                    ps.z = pt.z - lp.pz;
                    
                    if (njInnerProduct((NJS_VECTOR*)&lp.vx, &ps) > 0) 
                    {
                        ln = njScalor(&ps);
                        
                        if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                        {
                            return 1;
                        }
                    }
                    
                    p[0].x = px + w;
                    p[0].y = py;
                    p[0].z = pz;
                    
                    p[1].x = px;
                    p[1].y = py;
                    p[1].z = pz + d;
                    
                    p[2].x = px + w;
                    p[2].y = py + h;
                    p[2].z = pz;
                    
                    njGetPlaneNormal(p, (NJS_VECTOR*)&pl.vx);
                    
                    pl.px = px + (0.49f * w);
                    pl.py = py + (0.5f  * h);
                    pl.pz = pz + (0.49f * d);
                    
                    njDistanceL2PL(&lp, &pl, &pt);
                    
                    ps.x = pt.x - lp.px;
                    ps.y = pt.y - lp.py;
                    ps.z = pt.z - lp.pz;
                    
                    if (njInnerProduct((NJS_VECTOR*)&lp.vx, &ps) > 0) 
                    {
                        ln = njScalor(&ps);
                        
                        if ((bhCheckInnerTriangle(hp, &pt, 0, 0) != 0) && (ln < nr)) 
                        {
                            return 1;
                        }
                    }
                }
                
                break;
            case 7:
                box.v[0].x = px;
                box.v[0].y = py - 0.1f;
                box.v[0].z = pz + d;
                
                box.v[1].x = px;
                box.v[1].y = py - 0.1f;
                box.v[1].z = pz;
                
                box.v[2].x = px + w;
                box.v[2].y = py - 0.1f;
                box.v[2].z = pz;
                
                box.v[3].x = px + w;
                box.v[3].y = py - 0.1f;
                box.v[3].z = pz + d;
                
                box.v[4].x = px;
                box.v[4].y = py + h;
                box.v[4].z = pz + d;
                
                box.v[5].x = px;
                box.v[5].y = py + h;
                box.v[5].z = pz;
                
                box.v[6].x = px + w;
                box.v[6].y = py + h;
                box.v[6].z = pz;
                
                box.v[7].x = px + w;
                box.v[7].y = py + h;
                box.v[7].z = pz + d;
                
                if (njCollisionCheckBC(&box, cap) != 0)
                {
                    return 1;
                }
                
                break;
            }
        } 
    }
    
    return 0;
}

// 100% matching!
int bhCheckClipModel(BH_PWORK* pp)
{
    ML_WORK* mlwP; 
    NJS_POINT2 p2; 
    NJS_POINT3 p3; 
    int i;         
    int jno;       
    
    mlwP = pp->mlwP;
    
    if (mlwP == NULL)
    {
        return 1;
    }
    
    for (i = 0; i < 8; i++) 
    {
        if (pp->clp_jno[i] == -1)
        {
            break;
        }
        
        jno = pp->clp_jno[i];
        
        njProjectScreen(cam.mtx, (NJS_POINT3*)&mlwP->owP[jno].mtx[12], &p2);
        
        njCalcPoint(cam.mtx, (NJS_POINT3*)&mlwP->owP[jno].mtx[12], &p3);
        
        if (((p2.x > 1472.0f) && (p2.x < 2624.0f)) && ((p2.y > 1632.0f) && (p2.y < 2624.0f)) && (p3.z > -1.0f)) 
        {
            return 0;
        }
    }
    
    return 1;
}

// 100% matching!
int bhCheckClipPoint(NJS_POINT3* pos)
{
	NJS_POINT2 p2;
    NJS_POINT3 p3;
    
    njProjectScreen(cam.mtx, pos, &p2);
    
    njCalcPoint(cam.mtx, pos, &p3);
    
    if (((p2.x > 1472.0f) && (p2.x < 2624.0f)) && ((p2.y > 1632.0f) && (p2.y < 2624.0f)) && (p3.z > -1.0f))
    {
        return 0;
    }
    
    return 1;
}

// 98.30% matching (matches on NGC)
void bhSetWaterSplash(BH_PWORK* pp, int jno, int type, float sx, float sy, float sz)
{
    O_WORK* owp;  
    ATR_WORK* hp; 
    NJS_POINT3 ps; 
    NJS_POINT3* tmp, *tmp2; // not from DWARF

    owp = &pp->mlwP->owP[jno];
    
    tmp  = (NJS_POINT3*)&owp->mtx[12];
    tmp2 = (NJS_POINT3*)&owp->mtx[14];
    
    ps.x = owp->mtx[12];
    ps.y = pp->py;
    ps.z = owp->mtx[14];
    
    ps.y = bhGetGroundPosition(&ps);
    
    hp = bhCheckWater(&ps);
    
    if (hp != NULL) 
    {
        sys->ef.id  = 11;
        sys->ef.flg = 1;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = type;
        
        sys->ef.flr_no = 0;
        
        sys->ef.sx = sx;
        sys->ef.sy = sy;
        sys->ef.sz = sz;
        
        sys->ef.px = tmp->x;
        sys->ef.py = hp->py + hp->h;
        sys->ef.pz = tmp2->x;
        
        sys->ef.ay = pp->ay + 16384;
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        sys->ef.ay = pp->ay - 16384;
        bhSetEffectTb(&sys->ef, NULL, NULL, 1);
        
        sys->ef.ay = pp->ay + 32768; 
        bhSetEffectTb(&sys->ef, NULL, NULL, 2);
    }
}

// 100% matching!
void bhSetWaterSplash2(BH_PWORK* pp, NJS_POINT3* pos, int type, float sx, float sy, float sz)
{
    ATR_WORK* hp;  
    NJS_POINT3 ps; 

    ps.x = pos->x;
    ps.y = pp->py;
    ps.z = pos->z;
    
    ps.y = bhGetGroundPosition(&ps);
    
    hp = bhCheckWater(&ps);
    
    if (hp != NULL)
    {
        sys->ef.id  = 11;
        sys->ef.flg = 1;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = type;
        
        sys->ef.flr_no = 0;
        
        sys->ef.sx = sx;
        sys->ef.sy = sy;
        sys->ef.sz = sz;
        
        sys->ef.px = pos->x;
        sys->ef.py = hp->py + hp->h;
        sys->ef.pz = pos->z;
        
        sys->ef.ay = pp->ay + 16384;
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        sys->ef.ay = pp->ay - 16384;
        bhSetEffectTb(&sys->ef, NULL, NULL, 1);
        
        sys->ef.ay = pp->ay + 32768; 
        bhSetEffectTb(&sys->ef, NULL, NULL, 2);
    }
}

// 100% matching!
void bhSetWaterSplash3(NJS_POINT3* pos, int ang, int type, float sx, float sy, float sz)
{
    sys->ef.id  = 11;
    sys->ef.flg = 1;
    
    sys->ef.mdlver = 0;
    
    sys->ef.type = type;
    
    sys->ef.flr_no = 0;
    
    sys->ef.sx = sx;
    sys->ef.sy = sy;
    sys->ef.sz = sz;
    
    sys->ef.px = pos->x;
    sys->ef.py = pos->y;
    sys->ef.pz = pos->z;
    
    sys->ef.ay = ang + 16384;
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    
    sys->ef.ay = ang - 16384;
    bhSetEffectTb(&sys->ef, NULL, NULL, 1);
}

// 100% matching!
void bhSetWaterSplash4(NJS_POINT3* pos, int ang, int type, float sx, float sy, float sz) 
{
    sys->ef.id  = 11;
    sys->ef.flg = 1;
    
    sys->ef.mdlver = 0;
    
    sys->ef.type = type + 10;
    
    sys->ef.flr_no = 0;
    
    sys->ef.sx = sx;
    sys->ef.sy = sy;
    sys->ef.sz = sz;
    
    sys->ef.px = pos->x;
    sys->ef.py = pos->y;
    sys->ef.pz = pos->z;
    
    sys->ef.ay = ang + 16384;
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    
    sys->ef.ay = ang - 16384;
    bhSetEffectTb(&sys->ef, NULL, NULL, 1);
}

// 100% matching!
void bhSetGunFire(BH_PWORK* pp, int wno, int jno, int hand, int ang)
{
    EF_WORK* eft;   
    NJS_POINT3 ops, ps, ps2; 
    int i;         
    LGT_WORK* lp;   
    O_WRK* op;    
    NJS_LINE gline; 
    NJS_POINT3 wps; 
    ATR_WORK* wlp;  
    int walhit;   
    float len;     
    int eno;       // not from DWARF
    EF_WORK* eft2; // not from DWARF

    if ((WpnTab[wno].flg & 0x4)) 
    {
        lp = rom->lgtp;
        
        lp->flg = 3;
        
        lp->aspd = 0;
        
        if ((pp->stflg & 0x40000000)) 
        {
            lp->lkflg = 1;
            
            lp->lkno  = 0;
            lp->lkono = jno;
        } 
        else 
        {
            lp->lkflg = 2;
            
            lp->lkno  = pp->idx_ct;
            lp->lkono = jno;
        }
        
        lp->mode = 0;
        
        lp->lsrc = 4;
        
        lp->type = WpnTab[wno].ltp;
        
        lp->r = WpnTab[wno].lr / 40.0f;
        lp->g = WpnTab[wno].lg / 40.0f;
        lp->b = WpnTab[wno].lb / 40.0f;
        
        lp->nr = WpnTab[wno].lnr;
        lp->fr = WpnTab[wno].lfr;
        
        if (hand == 0) 
        {
            lp->lx = WpnTab[wno].wp_fps1.x;
        }
        else 
        {
            lp->lx = -WpnTab[wno].wp_fps1.x;
        }
        
        lp->ly = WpnTab[wno].wp_fps1.y;
        lp->lz = WpnTab[wno].wp_fps1.z;
        
        lp->light = NULL;
    }
    
    if (((pp->stflg & 0x40000000)) && (WpnTab[wno].vib_tp >= 0)) 
    {
        StartVibrationEx(0, WpnTab[wno].vib_tp);
    }
    
    eft = WpnEffTab[wno];
    
    if (eft->flg != 0) 
    {
        if (hand == 0) 
        {
            ops = WpnTab[wno].wp_fps1;
        } 
        else if (wno == 22)
        {
            ops.x = -2.7218f;
            ops.y =  0.1032f;
            ops.z = -4.205f;
        }
        else 
        {
            ops.x = -WpnTab[wno].wp_fps1.x;
            ops.y =  WpnTab[wno].wp_fps1.y;
            ops.z =  WpnTab[wno].wp_fps1.z; 
        }
        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, &ops, (NJS_POINT3*)&eft->px);
        
        switch (wno) 
        {                            
        case 11:                                     
            eft->ax = 0;
            break;
        case 12:                                    
            if ((sys->yk_ct % 3) == 0) 
            {
                eft->ax = 8192;
                
                eft->mdlver = 1;
            } 
            else 
            {
                eft->ax = 5461;
                
                eft->mdlver = 0;
            }
            
            break;
        case 8:                                     
            if ((sys->yk_ct % 3) == 0)
            {
                eft->ax = 8192;
                
                eft->mdlver = 1;
            }
            else
            {
                eft->ax = 8192;
                
                eft->mdlver = 0;
            }
            
            break;
        case 21:                                    
            eft->ay = 5461;
            
            eft->mdlver = 0;
            break;
        }
        
        if (!(eft->flg & 0x80)) 
        {
            eft->ay = ang + 16384;
            
            eno = bhSetEffectTb(eft, &ops, NULL, jno);
            
            if (eno != -1)
            {
                op = &eff[eno];
                
                njSetMatrix(op->mtx, &pp->mlwP->owP[jno].mtx);
                
                njTranslate(op->mtx, ops.x, ops.y, ops.z);
                
                if ((hand != 0) && (wno < 21))
                { 
                    njRotateY(op->mtx, 32768);
                }
                
                switch (wno) 
                {                      
                case 6:                             
                    if ((pp->at_flg & 0x100))
                    {
                        ps2.x = 1.0f;
                        ps2.y = 0;
                        ps2.z = 0;
                        
                        njCalcVector(&pp->mlwP->owP[jno].mtx, &ps2, &ps);
                        
                        bhSetEffGunSpark((NJS_POINT3*)&eft->px, &ps, 0xFFF8F8A0, 0x4CE04010, 1);
                    }
                    
                    break;
                case 13:                            
                    njRotateY(op->mtx, 8192);
                    break;
                case 14:                            
                case 15:                            
                case 16:                            
                case 17:                            
                    njRotateY(op->mtx, 9102);
                    break;
                case 22:                            
                    if (hand == 0)
                    {
                        njRotateXYZ(op->mtx, 4551, 2230, 1911);
                    } 
                    else 
                    {
                        njRotateXYZ(op->mtx, 49152, 20789, 62851);
                    }
                    
                    break;
                }
            }
        } 
        else 
        {
            if (hand == 0) 
            {
                eft->ay = 0;
            } 
            else 
            {
                eft->ay = -32768;
            }
            
            bhSetEffectTb(eft, &ops, (unsigned char*)pp, jno);
        }
    }
    
    if (WpnEffTab[wno][1].flg != 0) 
    {
        if (hand == 0) 
        {
            ops = WpnTab[wno].wp_fps2;
        } 
        else if (wno == 22)
        {
            ops.x = -2.7218f;
            ops.y =  0.1032f;
            ops.z = -4.205f;
        } 
        else
        {
            ops.x = -WpnTab[wno].wp_fps2.x;
            ops.y =  WpnTab[wno].wp_fps2.y;
            ops.z =  WpnTab[wno].wp_fps2.z;
        }
        
        eft2 = &WpnEffTab[wno][1];
        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, &ops, (NJS_POINT3*)&eft2->px);
        
        if (!(eft2->flg & 0x80)) 
        {
            ps.y = 0;
            ps.z = 0;
            
            if (hand == 0) 
            {
                ps.x = 0.1f * (float)eft2->flr_no;
            } 
            else 
            {
                ps.x = 0.1f * -(float)eft2->flr_no;
            }
            
            njCalcVector(&pp->mlwP->owP[jno].mtx, &ps, &ops);
            
            eft2->ay = ang;
            
            bhSetEffectTb(eft2, &ops, NULL, jno);
        }
        else
        {
            eft2->ay = 0;
            
            bhSetEffectTb(eft2, &ops, (unsigned char*)pp, jno);
        }
    }
    
    switch (wno) 
    {   
    case 8: 
    case 10: 
    case 12: 
    case 13: 
    case 14: 
    case 15: 
    case 16: 
    case 17: 
    case 18: 
    case 19: 
        break;
    case 3:                                         
    case 4:                                         
    case 5:                                         
    case 6:                                         
    case 7:           
    case 9:                                         
        if (hand == 0) 
        {
            ops = WpnTab[wno].wp_fps1;
        } 
        else 
        {
            ops.x = -WpnTab[wno].wp_fps1.x;
            ops.y =  WpnTab[wno].wp_fps1.y;
            ops.z =  WpnTab[wno].wp_fps1.z;
        }
        
        sys->ef.id = 3;
        
        sys->ef.flg  = 1;
        sys->ef.type = 0;
        
        sys->ef.flr_no = 2;
        
        sys->ef.mdlver = 1;
        
        sys->ef.ay = 0;
        sys->ef.ax = 0;
        
        sys->ef.px = 0;
        sys->ef.py = 0;
        sys->ef.pz = 0;
        
        sys->ef.sx = eft->sx;
        sys->ef.sy = eft->sy;
        sys->ef.sz = eft->sz;
        
        bhSetEffectTb(&sys->ef, &ops, (unsigned char*)pp, jno);
        break;
    case 11:                                         
        eft = &sys->ef;
        
        eft->id = 14;
        
        eft->type = 1;
        
        eft->flr_no = 0;
        
        eft->mdlver = 0;
        
        eft->ay = pp->ay;
        eft->ax = 0;
        
        eft->flg = 0x4100001;
        
        ps.x = WpnTab[wno].wp_fps1.x;
        ps.y = WpnTab[wno].wp_fps1.y;
        ps.z = WpnTab[wno].wp_fps1.z;
        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, &ps, (NJS_POINT3*)&eft->px);
        
        eft->sx = 1.0f;
        eft->sy = 1.0f;
        eft->sz = 1.0f;
        
        bhSetEffectTb(eft, NULL, NULL, 0);
        
        eft->id = 14;
        
        eft->type = 0;
        
        eft->ay = pp->ay;
        
        eft->flg = 0x4100001;
        
        ps.x = 1.5f + WpnTab[wno].wp_fps1.x;
        ps.y = WpnTab[wno].wp_fps1.y;
        ps.z = WpnTab[wno].wp_fps1.z;
        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, &ps, (NJS_POINT3*)&eft->px);
        
        eft->sx = 1.5f;
        eft->sy = 1.5f;
        eft->sz = 1.5f;
        
        bhSetEffectTb(eft, NULL, NULL, 0);
        
        eft->id = 14;
        
        eft->type = 2;
        
        eft->ay = pp->ay;
        
        eft->flg = 0x4100001;
        
        ps.x = 1.5f + WpnTab[wno].wp_fps1.x;
        ps.y = WpnTab[wno].wp_fps1.y;
        ps.z = WpnTab[wno].wp_fps1.z;
        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, &ps, (NJS_POINT3*)&eft->px);
        
        ps.x = 1.5f;
        ps.y = 0;
        ps.z = 0;
        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, &ps, &ops);
        
        ops.x -= pp->mlwP->owP[jno].mtx[12];
        ops.y -= pp->mlwP->owP[jno].mtx[13];
        ops.z -= pp->mlwP->owP[jno].mtx[14];
        
        eft->sx = 2.5f;
        eft->sy = 2.5f;
        eft->sz = 2.5f;
        
        bhSetEffectTb(eft, &ops, NULL, 0);
        
        ps.x = 1.51f + WpnTab[wno].wp_fps1.x;
        ps.y = WpnTab[wno].wp_fps1.y;
        ps.z = WpnTab[wno].wp_fps1.z;
        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, &ps, (NJS_POINT3*)&eft->px);
        
        bhSetEffectTb(eft, &ops, NULL, 0);
        
        eft->id = 14;
        
        eft->type = 3;
        
        eft->ay = 0;
        
        eft->flg = 0x4000001;
        
        if (sys->ply_id == 0)
        {
            ps.x = WpnTab[wno].wp_fps1.x;
            ps.y = WpnTab[wno].wp_fps1.y;
            ps.z = WpnTab[wno].wp_fps1.z;
        } 
        else 
        {
            ps.x = 6.9f;
            ps.y = 0;
            ps.z = -0.8385f;
        }
        
        eft->sx = 0.19f;
        eft->sy = 0.19f;
        eft->sz = 0.19f;
        
        bhSetEffectTb(eft, &ps, (unsigned char*)pp, jno);
        
        eft->id = 2;
        
        eft->type = 6;
        
        eft->flr_no = 0;
        
        eft->mdlver = 9;
        
        eft->ay = eft->ax = 0;
        
        eft->flg = 0x4100001;
        
        eft->sx = 1.0f;
        eft->sy = 1.0f;
        eft->sz = 1.0f;
        
        ps.x = 0.5f;
        ps.y = 0;
        ps.z = 0.4f;
        
        njSetMatrix(NULL, &pp->mlwP->owP[jno].mtx);
        
        for (i = 0; i < 8; i++) 
        {
            njCalcVector(NULL, &ps, &ps2);
            
            bhSetEffectTb(eft, &ps2, NULL, jno);
            
            njRotateX(NULL, 8192);
        } 
        
        break;
    case 20:                                        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, (NJS_POINT3*)&WpnTab[wno].wp_fps2, (NJS_POINT3*)&sys->ef.px);
        
        sys->ef.id = 27;
        
        sys->ef.flg  = 1;
        sys->ef.type = 0;
        
        sys->ef.mdlver = 0;
        
        sys->ef.flr_no = 0;
        
        sys->ef.sx = 1.0f;
        sys->ef.sy = 1.0f;
        sys->ef.sz = 0;
        
        sys->ef.ay = 0;
        sys->ef.ax = 0;
        
        ps.x = -3.0f;
        ps.y = 0;
        ps.z = 0;
        
        njSetMatrix(NULL, &pp->mlwP->owP[jno].mtx);
        
        njCalcVector(NULL, &ps, &ps2);
        
        bhSetEffectTb(&sys->ef, &ps2, NULL, 0);
        break;
    case 21:                                        
        ops = WpnTab[wno].wp_fps1; 
        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, &ops, (NJS_POINT3*)&gline.px);
        
        ops.x = ops.y = 0;
        ops.z = -1000.0f;
        
        njSetMatrix(NULL, &pp->mlwP->owP[jno].mtx);
        
        njRotateY(NULL, 36);
        njRotateX(NULL, -1547);
        
        njCalcVector(NULL, &ops, (NJS_VECTOR*)&gline.vx);
        
        if (bhCheckL2Wall(&gline, 0x400, &len) != 0) 
        {
            wps = sys->apos;
            wlp = sys->ahtp;
            
            walhit = 1;
        }
        else 
        {
            walhit = 0;
        }
        
        if ((walhit != 0) && (bhCheckWallAttrB89(wlp) != 0)) 
        {
            ps.x = -gline.vx;
            ps.y = -gline.vy; 
            ps.z = -gline.vz;
                
            bhSetEffGunSpark(&wps, &ps, 0xFFF8F8A0, 0x4CE04010, WpnTab[wno].hiteff - 4);
            
            if (wlp->prm0 == 1) 
            {
                sys->ef.id = 11;
                
                sys->ef.flg = 1;
                
                sys->ef.mdlver = 1; 
                
                sys->ef.type = 1;
                
                sys->ef.flr_no = 1;
                
                sys->ef.px = wps.x;
                sys->ef.py = wps.y;
                sys->ef.pz = wps.z;
                
                sys->ef.ax = 0;
                sys->ef.ay = 16384;
                
                sys->ef.sx = WpnTab[wno].ef_scale;
                sys->ef.sy = WpnTab[wno].ef_scale;
                sys->ef.sz = WpnTab[wno].ef_scale;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
                
                sys->ef.sx = 0.5f * WpnTab[wno].ef_scale;
                sys->ef.sy = 0.5f * WpnTab[wno].ef_scale;
                sys->ef.sz = 0.5f * WpnTab[wno].ef_scale;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
                
                sys->ef.ay = -16384;
                
                sys->ef.sx = WpnTab[wno].ef_scale;
                sys->ef.sy = WpnTab[wno].ef_scale;
                sys->ef.sz = WpnTab[wno].ef_scale;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 1);
                
                sys->ef.sx = 0.5f * WpnTab[wno].ef_scale;
                sys->ef.sy = 0.5f * WpnTab[wno].ef_scale;
                sys->ef.sz = 0.5f * WpnTab[wno].ef_scale;
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 1);
            }
        }

        break;
    }
}

// 100% matching!
void bhSetYakkyou(BH_PWORK* pp, int wno, int jno, int hand, int ang) // fifth parameter is not present on DWARF
{
    EF_WORK* eft;    
    NJS_POINT3 ops, wps, jps;  
    static short hr, hl = 1; 

    if (wno == 8) 
    {
        if (hand == 0) 
        {
            hr++;
            
            if ((hr & 0x1)) 
            {
                return;
            }
        } 
        else 
        {
            hl++;
            
            if ((hl & 0x1)) 
            {
                return;
            }
        }
    }
    
    eft = &WpnEffTab[wno][3];  
    
    eft->flg = 0x40601;
    
    eft->flr_no = sys->yk_ct; 

    if (hand == 0)
    {
        ops = WpnTab[wno].wp_cps;
        wps = WpnTab[wno].wp_fps1;
    } 
    else if (wno == 22) 
    {
        ops.x = -0.2784f;
        ops.y = -0.5401f;
        ops.z =  1.4173f;
        
        wps.x = -2.7218f;
        wps.y =  0.1032f;
        wps.z = -4.205f;
    } 
    else 
    {
        ops.x = -WpnTab[wno].wp_cps.x;
        ops.y =  WpnTab[wno].wp_cps.y; 
        ops.z =  WpnTab[wno].wp_cps.z;
        
        wps.x = -WpnTab[wno].wp_fps1.x;
        wps.y =  WpnTab[wno].wp_fps1.y;
        wps.z =  WpnTab[wno].wp_fps1.z; 
    }
    
    njCalcPoint(&pp->mlwP->owP[jno].mtx, &wps, &jps);
    
    jps.x = pp->mlwP->owP->mtx[12] - jps.x;
    jps.z = pp->mlwP->owP->mtx[14] - jps.z;
    
    eft->ay = (int)(10430.381f * atan2f(jps.x, jps.z));
    
    if (bhSetEffectTb(eft, &ops, (unsigned char*)pp, jno) >= 0) 
    {
        sys->yk_ct = (sys->yk_ct + 1) & 0x1F;
    }
    
    if (WpnEffTab[wno][2].flg != 0) 
    {
        if (hand == 0) 
        {
            ops = WpnTab[wno].wp_cps;
        }
        else
        {
            ops.x = -WpnTab[wno].wp_cps.x;
            ops.y =  WpnTab[wno].wp_cps.y;
            ops.z =  WpnTab[wno].wp_cps.z;
        }
        
        eft = &WpnEffTab[wno][2];
        
        ops.z += eft->sz; 
        
        njCalcPoint(&pp->mlwP->owP[jno].mtx, &ops, (NJS_POINT3*)&eft->px);
        
        if (!(eft->flg & 0x80)) 
        {
            bhSetEffectTb(eft, &ops, NULL, jno); 
        } 
        else 
        {
            bhSetEffectTb(eft, &ops, (unsigned char*)pp, jno);
        }
        
        switch (wno) 
        {
        case 12:
            sys->ef.px = eft->px;
            sys->ef.py = eft->py;
            sys->ef.pz = eft->pz;
            
            sys->ef.id = 2;
            
            sys->ef.flg  = 0x4100001;
            sys->ef.type = 5;
            
            sys->ef.flr_no = 0;
            
            sys->ef.mdlver = 2;
            
            sys->ef.sx = 1.2f;
            sys->ef.sy = 1.2f;
            sys->ef.sz = 1.2f;
            
            sys->ef.ax = 0;
            sys->ef.ay = 0;
            
            bhSetEffectTb(&sys->ef, &ops, NULL, jno);
            break;
        }
    } 
}

// 91.30% matching (matches on NGC)
void bhSetMagazine(BH_PWORK* pp, int wno, int jno, int hand, int ang)
{
    EF_WORK* eft;  
    NJS_POINT3 ops; 
    
    eft = &sys->ef;

    eft->id  = 7;
    eft->flg = 0x40001;
    
    eft->type = 0;
    
    eft->flr_no = sys->mg_ct;
    
    eft->ay = ang + 16384;
    eft->ax = 0;
    
    eft->sx = 1.0f;
    eft->sy = 1.0f;
    eft->sz = 1.0f;
    
    switch (wno) 
    {                                 
    case 12:
        eft->mdlver = 1;
        
        ops.x = 2.2f;
        ops.y = 0;
        ops.z = 0;
        break;
    case 13:
        eft->mdlver = 2;
        
        ops.x = 1.8f;
        ops.y = 0;
        ops.z = -1.0f;
        break;
    default:
        eft->mdlver = 0;
        
        if (hand == 0)
        {
            ops.x = 1.0f;
            ops.y = 0;
            ops.z = 0;
        } 
        else 
        {
            ops.x = -0.5f;
            ops.y = 0;
            ops.z = 0;
        }
        
        break;
    }
    
    if (bhSetEffectTb(eft, &ops, (unsigned char*)pp, jno) >= 0) 
    {
        sys->mg_ct = (sys->mg_ct + 1) & 7;
    }
}

// 100% matching! 
void bhSetLighterFire(O_WRK* op, int flg)
{
    if (flg == 0)
    {
        sys->ef.id  = 9;
        sys->ef.flg = 0x4100001;
        
        sys->ef.type = 3;
        
        sys->ef.px = op->px;
        sys->ef.py = op->py;
        sys->ef.pz = op->pz;
        
        sys->ef.sx = 0.5f;
        sys->ef.sy = 0.5f;
        sys->ef.sz = 0.5f;
        
        sys->ef.ay = sys->ef.ax = 0;
        
        bhSetEffectTb(&sys->ef, (NJS_POINT3*)&WpnTab[1].wp_fps1, (unsigned char*)op, 0);
        
        lgttab->ct2 = 3; 
        lgttab->ct3 = op->idx_ct;
        
        lgttab->wpx = 0;
        
        bhSetLightTab((LGT_WORK*)&lgttab->mode, 1);
        
        rom->lgtp[1].flg |= 0x2;
        sys->st_flg      |= 0x20000000;
    } 
    else 
    {
        rom->lgtp[1].flg &= ~0x2;
        sys->st_flg      &= ~0x20000000;
    }
}
