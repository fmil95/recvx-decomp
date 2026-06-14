#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/light.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
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

// 
// Start address: 0x153c40
void bhSetGunFire(BH_PWORK* pp, int wno, int jno, int hand, int ang)
{
	float len;
	int walhit;
	//_anon0* wlp;
	//_anon23 wps;
	//_anon41 gline;
	//_anon1* op;
	//_anon18* lp;
	int i;
	//_anon23 ps2;
	//_anon23 ps;
	//_anon23 ops;
	//_anon13* eft;
	// Line 2618, Address: 0x153c40, Func Offset: 0
	// Line 2624, Address: 0x153c60, Func Offset: 0x20
	// Line 2618, Address: 0x153c6c, Func Offset: 0x2c
	// Line 2624, Address: 0x153c70, Func Offset: 0x30
	// Line 2618, Address: 0x153c88, Func Offset: 0x48
	// Line 2624, Address: 0x153c8c, Func Offset: 0x4c
	// Line 2618, Address: 0x153c90, Func Offset: 0x50
	// Line 2624, Address: 0x153ca4, Func Offset: 0x64
	// Line 2626, Address: 0x153cb4, Func Offset: 0x74
	// Line 2627, Address: 0x153cbc, Func Offset: 0x7c
	// Line 2629, Address: 0x153cc0, Func Offset: 0x80
	// Line 2626, Address: 0x153cc4, Func Offset: 0x84
	// Line 2627, Address: 0x153cc8, Func Offset: 0x88
	// Line 2628, Address: 0x153ccc, Func Offset: 0x8c
	// Line 2629, Address: 0x153cd0, Func Offset: 0x90
	// Line 2630, Address: 0x153ce0, Func Offset: 0xa0
	// Line 2631, Address: 0x153ce8, Func Offset: 0xa8
	// Line 2633, Address: 0x153cec, Func Offset: 0xac
	// Line 2634, Address: 0x153cf4, Func Offset: 0xb4
	// Line 2635, Address: 0x153cfc, Func Offset: 0xbc
	// Line 2636, Address: 0x153d04, Func Offset: 0xc4
	// Line 2639, Address: 0x153d08, Func Offset: 0xc8
	// Line 2638, Address: 0x153d0c, Func Offset: 0xcc
	// Line 2639, Address: 0x153d10, Func Offset: 0xd0
	// Line 2640, Address: 0x153d14, Func Offset: 0xd4
	// Line 2641, Address: 0x153d24, Func Offset: 0xe4
	// Line 2640, Address: 0x153d30, Func Offset: 0xf0
	// Line 2641, Address: 0x153d34, Func Offset: 0xf4
	// Line 2642, Address: 0x153d78, Func Offset: 0x138
	// Line 2641, Address: 0x153d84, Func Offset: 0x144
	// Line 2642, Address: 0x153d88, Func Offset: 0x148
	// Line 2643, Address: 0x153dcc, Func Offset: 0x18c
	// Line 2642, Address: 0x153dd8, Func Offset: 0x198
	// Line 2643, Address: 0x153ddc, Func Offset: 0x19c
	// Line 2644, Address: 0x153e20, Func Offset: 0x1e0
	// Line 2643, Address: 0x153e2c, Func Offset: 0x1ec
	// Line 2644, Address: 0x153e30, Func Offset: 0x1f0
	// Line 2645, Address: 0x153e64, Func Offset: 0x224
	// Line 2644, Address: 0x153e70, Func Offset: 0x230
	// Line 2645, Address: 0x153e74, Func Offset: 0x234
	// Line 2646, Address: 0x153ea8, Func Offset: 0x268
	// Line 2647, Address: 0x153ec8, Func Offset: 0x288
	// Line 2648, Address: 0x153ee0, Func Offset: 0x2a0
	// Line 2649, Address: 0x153ef0, Func Offset: 0x2b0
	// Line 2648, Address: 0x153efc, Func Offset: 0x2bc
	// Line 2649, Address: 0x153f00, Func Offset: 0x2c0
	// Line 2650, Address: 0x153f08, Func Offset: 0x2c8
	// Line 2653, Address: 0x153f0c, Func Offset: 0x2cc
	// Line 2662, Address: 0x153f38, Func Offset: 0x2f8
	// Line 2670, Address: 0x153f40, Func Offset: 0x300
	// Line 2671, Address: 0x153f64, Func Offset: 0x324
	// Line 2672, Address: 0x153f6c, Func Offset: 0x32c
	// Line 2673, Address: 0x153f90, Func Offset: 0x350
	// Line 2674, Address: 0x153f98, Func Offset: 0x358
	// Line 2675, Address: 0x153fa4, Func Offset: 0x364
	// Line 2676, Address: 0x153fb0, Func Offset: 0x370
	// Line 2677, Address: 0x153fbc, Func Offset: 0x37c
	// Line 2678, Address: 0x153fc4, Func Offset: 0x384
	// Line 2679, Address: 0x153fcc, Func Offset: 0x38c
	// Line 2680, Address: 0x153fdc, Func Offset: 0x39c
	// Line 2679, Address: 0x153fe4, Func Offset: 0x3a4
	// Line 2680, Address: 0x153fe8, Func Offset: 0x3a8
	// Line 2679, Address: 0x153fec, Func Offset: 0x3ac
	// Line 2680, Address: 0x153ff0, Func Offset: 0x3b0
	// Line 2681, Address: 0x153ff4, Func Offset: 0x3b4
	// Line 2680, Address: 0x154000, Func Offset: 0x3c0
	// Line 2681, Address: 0x154004, Func Offset: 0x3c4
	// Line 2685, Address: 0x15400c, Func Offset: 0x3cc
	// Line 2686, Address: 0x154034, Func Offset: 0x3f4
	// Line 2689, Address: 0x15406c, Func Offset: 0x42c
	// Line 2691, Address: 0x154074, Func Offset: 0x434
	// Line 2692, Address: 0x1540a4, Func Offset: 0x464
	// Line 2693, Address: 0x1540ac, Func Offset: 0x46c
	// Line 2694, Address: 0x1540b0, Func Offset: 0x470
	// Line 2695, Address: 0x1540b8, Func Offset: 0x478
	// Line 2698, Address: 0x1540c0, Func Offset: 0x480
	// Line 2700, Address: 0x1540c8, Func Offset: 0x488
	// Line 2701, Address: 0x1540f8, Func Offset: 0x4b8
	// Line 2702, Address: 0x154100, Func Offset: 0x4c0
	// Line 2703, Address: 0x154104, Func Offset: 0x4c4
	// Line 2704, Address: 0x15410c, Func Offset: 0x4cc
	// Line 2707, Address: 0x154114, Func Offset: 0x4d4
	// Line 2716, Address: 0x15411c, Func Offset: 0x4dc
	// Line 2717, Address: 0x154124, Func Offset: 0x4e4
	// Line 2720, Address: 0x154128, Func Offset: 0x4e8
	// Line 2721, Address: 0x154138, Func Offset: 0x4f8
	// Line 2722, Address: 0x15413c, Func Offset: 0x4fc
	// Line 2721, Address: 0x15414c, Func Offset: 0x50c
	// Line 2722, Address: 0x154150, Func Offset: 0x510
	// Line 2724, Address: 0x154164, Func Offset: 0x524
	// Line 2725, Address: 0x154180, Func Offset: 0x540
	// Line 2724, Address: 0x154184, Func Offset: 0x544
	// Line 2725, Address: 0x154188, Func Offset: 0x548
	// Line 2736, Address: 0x15419c, Func Offset: 0x55c
	// Line 2737, Address: 0x1541b0, Func Offset: 0x570
	// Line 2738, Address: 0x1541d0, Func Offset: 0x590
	// Line 2740, Address: 0x15422c, Func Offset: 0x5ec
	// Line 2741, Address: 0x15423c, Func Offset: 0x5fc
	// Line 2742, Address: 0x154244, Func Offset: 0x604
	// Line 2743, Address: 0x154248, Func Offset: 0x608
	// Line 2744, Address: 0x15424c, Func Offset: 0x60c
	// Line 2746, Address: 0x154268, Func Offset: 0x628
	// Line 2748, Address: 0x154288, Func Offset: 0x648
	// Line 2750, Address: 0x154290, Func Offset: 0x650
	// Line 2751, Address: 0x15429c, Func Offset: 0x65c
	// Line 2757, Address: 0x1542a4, Func Offset: 0x664
	// Line 2758, Address: 0x1542b0, Func Offset: 0x670
	// Line 2760, Address: 0x1542b8, Func Offset: 0x678
	// Line 2761, Address: 0x1542c0, Func Offset: 0x680
	// Line 2762, Address: 0x1542d4, Func Offset: 0x694
	// Line 2763, Address: 0x1542dc, Func Offset: 0x69c
	// Line 2768, Address: 0x1542f0, Func Offset: 0x6b0
	// Line 2769, Address: 0x1542f8, Func Offset: 0x6b8
	// Line 2770, Address: 0x154308, Func Offset: 0x6c8
	// Line 2771, Address: 0x154310, Func Offset: 0x6d0
	// Line 2775, Address: 0x154324, Func Offset: 0x6e4
	// Line 2776, Address: 0x15433c, Func Offset: 0x6fc
	// Line 2777, Address: 0x154344, Func Offset: 0x704
	// Line 2778, Address: 0x154368, Func Offset: 0x728
	// Line 2779, Address: 0x154370, Func Offset: 0x730
	// Line 2780, Address: 0x15437c, Func Offset: 0x73c
	// Line 2781, Address: 0x154388, Func Offset: 0x748
	// Line 2782, Address: 0x154394, Func Offset: 0x754
	// Line 2783, Address: 0x15439c, Func Offset: 0x75c
	// Line 2784, Address: 0x1543a4, Func Offset: 0x764
	// Line 2785, Address: 0x1543b4, Func Offset: 0x774
	// Line 2784, Address: 0x1543bc, Func Offset: 0x77c
	// Line 2785, Address: 0x1543c0, Func Offset: 0x780
	// Line 2784, Address: 0x1543c4, Func Offset: 0x784
	// Line 2785, Address: 0x1543c8, Func Offset: 0x788
	// Line 2786, Address: 0x1543cc, Func Offset: 0x78c
	// Line 2785, Address: 0x1543d8, Func Offset: 0x798
	// Line 2786, Address: 0x1543dc, Func Offset: 0x79c
	// Line 2790, Address: 0x1543e4, Func Offset: 0x7a4
	// Line 2789, Address: 0x1543f4, Func Offset: 0x7b4
	// Line 2790, Address: 0x1543f8, Func Offset: 0x7b8
	// Line 2791, Address: 0x154410, Func Offset: 0x7d0
	// Line 2792, Address: 0x154420, Func Offset: 0x7e0
	// Line 2794, Address: 0x154424, Func Offset: 0x7e4
	// Line 2795, Address: 0x15442c, Func Offset: 0x7ec
	// Line 2797, Address: 0x154454, Func Offset: 0x814
	// Line 2798, Address: 0x15447c, Func Offset: 0x83c
	// Line 2799, Address: 0x154498, Func Offset: 0x858
	// Line 2800, Address: 0x15449c, Func Offset: 0x85c
	// Line 2801, Address: 0x1544b4, Func Offset: 0x874
	// Line 2803, Address: 0x1544bc, Func Offset: 0x87c
	// Line 2807, Address: 0x1544d4, Func Offset: 0x894
	// Line 2815, Address: 0x154500, Func Offset: 0x8c0
	// Line 2816, Address: 0x154508, Func Offset: 0x8c8
	// Line 2817, Address: 0x15452c, Func Offset: 0x8ec
	// Line 2818, Address: 0x154534, Func Offset: 0x8f4
	// Line 2819, Address: 0x154544, Func Offset: 0x904
	// Line 2818, Address: 0x15454c, Func Offset: 0x90c
	// Line 2819, Address: 0x154550, Func Offset: 0x910
	// Line 2818, Address: 0x154554, Func Offset: 0x914
	// Line 2819, Address: 0x154558, Func Offset: 0x918
	// Line 2820, Address: 0x15455c, Func Offset: 0x91c
	// Line 2819, Address: 0x154568, Func Offset: 0x928
	// Line 2820, Address: 0x15456c, Func Offset: 0x92c
	// Line 2823, Address: 0x154574, Func Offset: 0x934
	// Line 2824, Address: 0x154580, Func Offset: 0x940
	// Line 2826, Address: 0x154584, Func Offset: 0x944
	// Line 2823, Address: 0x154588, Func Offset: 0x948
	// Line 2824, Address: 0x154594, Func Offset: 0x954
	// Line 2836, Address: 0x15459c, Func Offset: 0x95c
	// Line 2824, Address: 0x1545a8, Func Offset: 0x968
	// Line 2825, Address: 0x1545b4, Func Offset: 0x974
	// Line 2826, Address: 0x1545c8, Func Offset: 0x988
	// Line 2827, Address: 0x1545dc, Func Offset: 0x99c
	// Line 2828, Address: 0x1545f0, Func Offset: 0x9b0
	// Line 2829, Address: 0x154604, Func Offset: 0x9c4
	// Line 2830, Address: 0x154618, Func Offset: 0x9d8
	// Line 2831, Address: 0x15462c, Func Offset: 0x9ec
	// Line 2832, Address: 0x154640, Func Offset: 0xa00
	// Line 2833, Address: 0x154654, Func Offset: 0xa14
	// Line 2834, Address: 0x15466c, Func Offset: 0xa2c
	// Line 2835, Address: 0x154684, Func Offset: 0xa44
	// Line 2836, Address: 0x15469c, Func Offset: 0xa5c
	// Line 2837, Address: 0x1546b4, Func Offset: 0xa74
	// Line 2841, Address: 0x1546bc, Func Offset: 0xa7c
	// Line 2842, Address: 0x1546c4, Func Offset: 0xa84
	// Line 2843, Address: 0x1546c8, Func Offset: 0xa88
	// Line 2848, Address: 0x1546cc, Func Offset: 0xa8c
	// Line 2841, Address: 0x1546d0, Func Offset: 0xa90
	// Line 2842, Address: 0x1546dc, Func Offset: 0xa9c
	// Line 2843, Address: 0x1546e0, Func Offset: 0xaa0
	// Line 2844, Address: 0x1546e4, Func Offset: 0xaa4
	// Line 2845, Address: 0x1546e8, Func Offset: 0xaa8
	// Line 2846, Address: 0x1546ec, Func Offset: 0xaac
	// Line 2848, Address: 0x1546f0, Func Offset: 0xab0
	// Line 2849, Address: 0x1546f4, Func Offset: 0xab4
	// Line 2846, Address: 0x154700, Func Offset: 0xac0
	// Line 2847, Address: 0x154704, Func Offset: 0xac4
	// Line 2848, Address: 0x154708, Func Offset: 0xac8
	// Line 2849, Address: 0x15470c, Func Offset: 0xacc
	// Line 2850, Address: 0x154710, Func Offset: 0xad0
	// Line 2849, Address: 0x15471c, Func Offset: 0xadc
	// Line 2850, Address: 0x154720, Func Offset: 0xae0
	// Line 2851, Address: 0x154724, Func Offset: 0xae4
	// Line 2850, Address: 0x15472c, Func Offset: 0xaec
	// Line 2851, Address: 0x154730, Func Offset: 0xaf0
	// Line 2850, Address: 0x154734, Func Offset: 0xaf4
	// Line 2852, Address: 0x154738, Func Offset: 0xaf8
	// Line 2851, Address: 0x154740, Func Offset: 0xb00
	// Line 2852, Address: 0x154748, Func Offset: 0xb08
	// Line 2851, Address: 0x154750, Func Offset: 0xb10
	// Line 2852, Address: 0x154754, Func Offset: 0xb14
	// Line 2854, Address: 0x15476c, Func Offset: 0xb2c
	// Line 2855, Address: 0x154774, Func Offset: 0xb34
	// Line 2856, Address: 0x154778, Func Offset: 0xb38
	// Line 2857, Address: 0x15477c, Func Offset: 0xb3c
	// Line 2859, Address: 0x154790, Func Offset: 0xb50
	// Line 2860, Address: 0x154798, Func Offset: 0xb58
	// Line 2861, Address: 0x15479c, Func Offset: 0xb5c
	// Line 2862, Address: 0x1547a0, Func Offset: 0xb60
	// Line 2863, Address: 0x1547a8, Func Offset: 0xb68
	// Line 2866, Address: 0x1547b0, Func Offset: 0xb70
	// Line 2861, Address: 0x1547b4, Func Offset: 0xb74
	// Line 2862, Address: 0x1547b8, Func Offset: 0xb78
	// Line 2863, Address: 0x1547bc, Func Offset: 0xb7c
	// Line 2866, Address: 0x1547c0, Func Offset: 0xb80
	// Line 2863, Address: 0x1547c4, Func Offset: 0xb84
	// Line 2864, Address: 0x1547cc, Func Offset: 0xb8c
	// Line 2865, Address: 0x1547d4, Func Offset: 0xb94
	// Line 2866, Address: 0x1547dc, Func Offset: 0xb9c
	// Line 2868, Address: 0x1547f0, Func Offset: 0xbb0
	// Line 2869, Address: 0x1547f8, Func Offset: 0xbb8
	// Line 2870, Address: 0x1547fc, Func Offset: 0xbbc
	// Line 2871, Address: 0x154800, Func Offset: 0xbc0
	// Line 2873, Address: 0x154814, Func Offset: 0xbd4
	// Line 2874, Address: 0x15481c, Func Offset: 0xbdc
	// Line 2875, Address: 0x154824, Func Offset: 0xbe4
	// Line 2876, Address: 0x154828, Func Offset: 0xbe8
	// Line 2877, Address: 0x154830, Func Offset: 0xbf0
	// Line 2880, Address: 0x154838, Func Offset: 0xbf8
	// Line 2875, Address: 0x15483c, Func Offset: 0xbfc
	// Line 2876, Address: 0x154840, Func Offset: 0xc00
	// Line 2877, Address: 0x154844, Func Offset: 0xc04
	// Line 2880, Address: 0x154848, Func Offset: 0xc08
	// Line 2877, Address: 0x15484c, Func Offset: 0xc0c
	// Line 2878, Address: 0x154854, Func Offset: 0xc14
	// Line 2879, Address: 0x15485c, Func Offset: 0xc1c
	// Line 2880, Address: 0x154864, Func Offset: 0xc24
	// Line 2882, Address: 0x154878, Func Offset: 0xc38
	// Line 2883, Address: 0x154880, Func Offset: 0xc40
	// Line 2884, Address: 0x154884, Func Offset: 0xc44
	// Line 2885, Address: 0x154888, Func Offset: 0xc48
	// Line 2887, Address: 0x1548a4, Func Offset: 0xc64
	// Line 2890, Address: 0x1548ac, Func Offset: 0xc6c
	// Line 2893, Address: 0x1548b0, Func Offset: 0xc70
	// Line 2887, Address: 0x1548b8, Func Offset: 0xc78
	// Line 2893, Address: 0x1548bc, Func Offset: 0xc7c
	// Line 2887, Address: 0x1548c4, Func Offset: 0xc84
	// Line 2888, Address: 0x1548d4, Func Offset: 0xc94
	// Line 2889, Address: 0x1548f0, Func Offset: 0xcb0
	// Line 2890, Address: 0x15490c, Func Offset: 0xccc
	// Line 2891, Address: 0x154910, Func Offset: 0xcd0
	// Line 2893, Address: 0x154914, Func Offset: 0xcd4
	// Line 2894, Address: 0x15491c, Func Offset: 0xcdc
	// Line 2897, Address: 0x15492c, Func Offset: 0xcec
	// Line 2894, Address: 0x154930, Func Offset: 0xcf0
	// Line 2897, Address: 0x154934, Func Offset: 0xcf4
	// Line 2894, Address: 0x154938, Func Offset: 0xcf8
	// Line 2895, Address: 0x15493c, Func Offset: 0xcfc
	// Line 2896, Address: 0x154944, Func Offset: 0xd04
	// Line 2897, Address: 0x15494c, Func Offset: 0xd0c
	// Line 2899, Address: 0x154960, Func Offset: 0xd20
	// Line 2901, Address: 0x154974, Func Offset: 0xd34
	// Line 2902, Address: 0x15497c, Func Offset: 0xd3c
	// Line 2904, Address: 0x154984, Func Offset: 0xd44
	// Line 2903, Address: 0x154988, Func Offset: 0xd48
	// Line 2904, Address: 0x15498c, Func Offset: 0xd4c
	// Line 2905, Address: 0x154994, Func Offset: 0xd54
	// Line 2906, Address: 0x1549a8, Func Offset: 0xd68
	// Line 2907, Address: 0x1549b0, Func Offset: 0xd70
	// Line 2908, Address: 0x1549b8, Func Offset: 0xd78
	// Line 2909, Address: 0x1549bc, Func Offset: 0xd7c
	// Line 2910, Address: 0x1549c4, Func Offset: 0xd84
	// Line 2912, Address: 0x1549d0, Func Offset: 0xd90
	// Line 2911, Address: 0x1549d4, Func Offset: 0xd94
	// Line 2912, Address: 0x1549d8, Func Offset: 0xd98
	// Line 2914, Address: 0x1549e0, Func Offset: 0xda0
	// Line 2915, Address: 0x1549ec, Func Offset: 0xdac
	// Line 2917, Address: 0x1549f0, Func Offset: 0xdb0
	// Line 2916, Address: 0x1549f4, Func Offset: 0xdb4
	// Line 2917, Address: 0x1549f8, Func Offset: 0xdb8
	// Line 2919, Address: 0x154a08, Func Offset: 0xdc8
	// Line 2920, Address: 0x154a10, Func Offset: 0xdd0
	// Line 2922, Address: 0x154a18, Func Offset: 0xdd8
	// Line 2921, Address: 0x154a1c, Func Offset: 0xddc
	// Line 2922, Address: 0x154a20, Func Offset: 0xde0
	// Line 2923, Address: 0x154a24, Func Offset: 0xde4
	// Line 2925, Address: 0x154a28, Func Offset: 0xde8
	// Line 2924, Address: 0x154a2c, Func Offset: 0xdec
	// Line 2925, Address: 0x154a30, Func Offset: 0xdf0
	// Line 2926, Address: 0x154a38, Func Offset: 0xdf8
	// Line 2927, Address: 0x154a40, Func Offset: 0xe00
	// Line 2928, Address: 0x154a44, Func Offset: 0xe04
	// Line 2929, Address: 0x154a48, Func Offset: 0xe08
	// Line 2931, Address: 0x154a50, Func Offset: 0xe10
	// Line 2930, Address: 0x154a54, Func Offset: 0xe14
	// Line 2931, Address: 0x154a58, Func Offset: 0xe18
	// Line 2932, Address: 0x154a60, Func Offset: 0xe20
	// Line 2933, Address: 0x154a78, Func Offset: 0xe38
	// Line 2934, Address: 0x154a7c, Func Offset: 0xe3c
	// Line 2935, Address: 0x154a8c, Func Offset: 0xe4c
	// Line 2936, Address: 0x154aa0, Func Offset: 0xe60
	// Line 2937, Address: 0x154aac, Func Offset: 0xe6c
	// Line 2938, Address: 0x154abc, Func Offset: 0xe7c
	// Line 2947, Address: 0x154ac4, Func Offset: 0xe84
	// Line 2950, Address: 0x154b00, Func Offset: 0xec0
	// Line 2951, Address: 0x154b0c, Func Offset: 0xecc
	// Line 2955, Address: 0x154b10, Func Offset: 0xed0
	// Line 2950, Address: 0x154b14, Func Offset: 0xed4
	// Line 2951, Address: 0x154b20, Func Offset: 0xee0
	// Line 2960, Address: 0x154b28, Func Offset: 0xee8
	// Line 2963, Address: 0x154b2c, Func Offset: 0xeec
	// Line 2951, Address: 0x154b30, Func Offset: 0xef0
	// Line 2952, Address: 0x154b3c, Func Offset: 0xefc
	// Line 2953, Address: 0x154b50, Func Offset: 0xf10
	// Line 2954, Address: 0x154b64, Func Offset: 0xf24
	// Line 2955, Address: 0x154b78, Func Offset: 0xf38
	// Line 2956, Address: 0x154b8c, Func Offset: 0xf4c
	// Line 2957, Address: 0x154ba0, Func Offset: 0xf60
	// Line 2958, Address: 0x154bb4, Func Offset: 0xf74
	// Line 2959, Address: 0x154bc8, Func Offset: 0xf88
	// Line 2960, Address: 0x154bdc, Func Offset: 0xf9c
	// Line 2961, Address: 0x154be0, Func Offset: 0xfa0
	// Line 2962, Address: 0x154be4, Func Offset: 0xfa4
	// Line 2963, Address: 0x154be8, Func Offset: 0xfa8
	// Line 2964, Address: 0x154bfc, Func Offset: 0xfbc
	// Line 2965, Address: 0x154c0c, Func Offset: 0xfcc
	// Line 2986, Address: 0x154c30, Func Offset: 0xff0
	// Line 2997, Address: 0x154c38, Func Offset: 0xff8
	// Line 2998, Address: 0x154c54, Func Offset: 0x1014
	// Line 2997, Address: 0x154c60, Func Offset: 0x1020
	// Line 2998, Address: 0x154c68, Func Offset: 0x1028
	// Line 2997, Address: 0x154c6c, Func Offset: 0x102c
	// Line 2998, Address: 0x154c70, Func Offset: 0x1030
	// Line 2999, Address: 0x154c84, Func Offset: 0x1044
	// Line 3000, Address: 0x154c8c, Func Offset: 0x104c
	// Line 3002, Address: 0x154c94, Func Offset: 0x1054
	// Line 3003, Address: 0x154cac, Func Offset: 0x106c
	// Line 3004, Address: 0x154cb8, Func Offset: 0x1078
	// Line 3005, Address: 0x154cc4, Func Offset: 0x1084
	// Line 3006, Address: 0x154cd8, Func Offset: 0x1098
	// Line 3007, Address: 0x154cf0, Func Offset: 0x10b0
	// Line 3009, Address: 0x154cfc, Func Offset: 0x10bc
	// Line 3007, Address: 0x154d00, Func Offset: 0x10c0
	// Line 3008, Address: 0x154d18, Func Offset: 0x10d8
	// Line 3007, Address: 0x154d20, Func Offset: 0x10e0
	// Line 3008, Address: 0x154d2c, Func Offset: 0x10ec
	// Line 3010, Address: 0x154d30, Func Offset: 0x10f0
	// Line 3011, Address: 0x154d38, Func Offset: 0x10f8
	// Line 3013, Address: 0x154d3c, Func Offset: 0x10fc
	// Line 3014, Address: 0x154d44, Func Offset: 0x1104
	// Line 3015, Address: 0x154d54, Func Offset: 0x1114
	// Line 3016, Address: 0x154d58, Func Offset: 0x1118
	// Line 3017, Address: 0x154d5c, Func Offset: 0x111c
	// Line 3020, Address: 0x154d60, Func Offset: 0x1120
	// Line 3015, Address: 0x154d68, Func Offset: 0x1128
	// Line 3016, Address: 0x154d70, Func Offset: 0x1130
	// Line 3017, Address: 0x154d78, Func Offset: 0x1138
	// Line 3020, Address: 0x154d7c, Func Offset: 0x113c
	// Line 3017, Address: 0x154d80, Func Offset: 0x1140
	// Line 3020, Address: 0x154d84, Func Offset: 0x1144
	// Line 3021, Address: 0x154da8, Func Offset: 0x1168
	// Line 3022, Address: 0x154dbc, Func Offset: 0x117c
	// Line 3032, Address: 0x154dc4, Func Offset: 0x1184
	// Line 3022, Address: 0x154dcc, Func Offset: 0x118c
	// Line 3032, Address: 0x154ddc, Func Offset: 0x119c
	// Line 3023, Address: 0x154de0, Func Offset: 0x11a0
	// Line 3031, Address: 0x154de8, Func Offset: 0x11a8
	// Line 3035, Address: 0x154dec, Func Offset: 0x11ac
	// Line 3023, Address: 0x154df8, Func Offset: 0x11b8
	// Line 3024, Address: 0x154e04, Func Offset: 0x11c4
	// Line 3025, Address: 0x154e18, Func Offset: 0x11d8
	// Line 3026, Address: 0x154e2c, Func Offset: 0x11ec
	// Line 3027, Address: 0x154e40, Func Offset: 0x1200
	// Line 3028, Address: 0x154e58, Func Offset: 0x1218
	// Line 3029, Address: 0x154e70, Func Offset: 0x1230
	// Line 3030, Address: 0x154e88, Func Offset: 0x1248
	// Line 3031, Address: 0x154e9c, Func Offset: 0x125c
	// Line 3032, Address: 0x154eb0, Func Offset: 0x1270
	// Line 3033, Address: 0x154ec8, Func Offset: 0x1288
	// Line 3034, Address: 0x154ee0, Func Offset: 0x12a0
	// Line 3035, Address: 0x154ef8, Func Offset: 0x12b8
	// Line 3036, Address: 0x154f10, Func Offset: 0x12d0
	// Line 3039, Address: 0x154f24, Func Offset: 0x12e4
	// Line 3036, Address: 0x154f30, Func Offset: 0x12f0
	// Line 3037, Address: 0x154f40, Func Offset: 0x1300
	// Line 3038, Address: 0x154f5c, Func Offset: 0x131c
	// Line 3039, Address: 0x154f78, Func Offset: 0x1338
	// Line 3040, Address: 0x154f90, Func Offset: 0x1350
	// Line 3044, Address: 0x154f9c, Func Offset: 0x135c
	// Line 3040, Address: 0x154fa4, Func Offset: 0x1364
	// Line 3041, Address: 0x154fb0, Func Offset: 0x1370
	// Line 3044, Address: 0x154fbc, Func Offset: 0x137c
	// Line 3041, Address: 0x154fc0, Func Offset: 0x1380
	// Line 3042, Address: 0x154fcc, Func Offset: 0x138c
	// Line 3043, Address: 0x154fe4, Func Offset: 0x13a4
	// Line 3044, Address: 0x154ffc, Func Offset: 0x13bc
	// Line 3045, Address: 0x155014, Func Offset: 0x13d4
	// Line 3048, Address: 0x155028, Func Offset: 0x13e8
	// Line 3045, Address: 0x155030, Func Offset: 0x13f0
	// Line 3048, Address: 0x155034, Func Offset: 0x13f4
	// Line 3045, Address: 0x155038, Func Offset: 0x13f8
	// Line 3046, Address: 0x155044, Func Offset: 0x1404
	// Line 3047, Address: 0x155060, Func Offset: 0x1420
	// Line 3048, Address: 0x15507c, Func Offset: 0x143c
	// Line 3055, Address: 0x155094, Func Offset: 0x1454
	// Func End, Address: 0x1550c4, Func Offset: 0x1484
	scePrintf("bhSetGunFire - UNIMPLEMENTED!\n");
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
