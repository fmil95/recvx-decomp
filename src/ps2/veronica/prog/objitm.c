#include "../../../ps2/veronica/prog/objitm.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/light.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaFog.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/screen.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/system.h"
#include "../../../ps2/veronica/prog/weapon.h"

#pragma optimization_level 4

void (*bhJumpObject[101])() = 
{
	bhObjDmy,
	bhObj001,
	bhObj002,
	bhObj003,
	bhObj004,
	bhObj005,
	bhObj006,
	bhObj007,
	bhObj008,
	bhObj009,
	bhObj010,
	bhObj011,
	bhObj012,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjItmBox
};
void (*bhJumpObject2[13])() = 
{
	bhObjClpn,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjDmy,
	bhObjWpn,
	bhObjClpn,
	bhObjWssg
};
unsigned int ulDrawGeneralPurposeWater;

// 100% matching! 
void bhInitObjItm()
{
    npSetMemory((unsigned char*)sys->obwp, 39936, 0);
    npSetMemory((unsigned char*)sys->itwp, 39936, 0);
}

// 100% matching!
O_WRK* bhSetObject(ETTY_WORK* otp, int no, unsigned char* lkp)
{
    O_WRK* opp;

    opp = &sys->obwp[no];
    
    npSetMemory((unsigned char*)opp, sizeof(O_WRK), 0);
    
    opp->flg = otp->flg;
    
    if ((opp->flg & 0x80000000)) 
    {
        opp->mdflg |= 0x10;
    }
    
    if ((opp->flg & 0x20000000)) 
    {
        opp->mdflg |= 0x40;
    }
    
    opp->id = otp->id;
    
    opp->type = (unsigned char)otp->type;
    
    opp->param = otp->type >> 8;
    
    opp->flr_no = otp->flr_no;
    
    opp->mdlver = otp->mdlver;
    
    opp->draw_tp = otp->prm1;
    
    opp->px = otp->px;
    opp->py = otp->py;
    opp->pz = otp->pz;
    
    opp->ax = otp->ax;
    opp->ay = otp->ay;
    opp->az = otp->az;
    
    opp->aspd = otp->aspd;
    
    opp->sx = opp->sxb = 1.0f;
    opp->sy = opp->syb = 1.0f;
    opp->sz = opp->szb = 1.0f;
    
    opp->hide[0] = otp->hide[0];
    opp->hide[1] = otp->hide[1];
    opp->hide[2] = otp->hide[2];
    opp->hide[3] = otp->hide[3];
    
    opp->lkwkp = lkp;
    
    opp->mtx = (void*)opp->mtxbuf;
    
    opp->clp_jno[0] = 0;
    opp->clp_jno[1] = -1;
    
    opp->idx_ct = no;
    
    return opp;
}

// 100% matching!
O_WRK* bhSetItem(ETTY_WORK* itp, int no, unsigned char* lkp)
{
    O_WRK* opp;

    opp = &sys->itwp[no];
    
    npSetMemory((unsigned char*)opp, sizeof(O_WRK), 0);
    
    opp->flg = itp->flg;
    
    if ((opp->flg & 0x80000000)) 
    {
        opp->mdflg |= 0x10;
    }
    
    if ((opp->flg & 0x20000000)) 
    {
        opp->mdflg |= 0x40;
    }
    
    opp->id = itp->id;
    
    opp->type = (unsigned char)itp->type;
    
    opp->param = itp->type >> 8;
    
    opp->flr_no = itp->flr_no;
    
    opp->mdlver = itp->mdlver;
    
    opp->draw_tp = itp->prm1;
    
    opp->px = itp->px;
    opp->py = itp->py;
    opp->pz = itp->pz;
    
    opp->ax = itp->ax;
    opp->ay = itp->ay;
    opp->az = itp->az;
    
    opp->aspd = itp->aspd;
    
    opp->sx = opp->sxb = 1.0f;
    opp->sy = opp->syb = 1.0f;
    opp->sz = opp->szb = 1.0f;
    
    opp->hide[0] = itp->hide[0];
    opp->hide[1] = itp->hide[1];
    opp->hide[2] = itp->hide[2];
    opp->hide[3] = itp->hide[3];
    
    opp->lkwkp = lkp;
    
    opp->mtx = (void*)opp->mtxbuf;
    
    opp->clp_jno[0] = 0;
    opp->clp_jno[1] = -1;
    
    opp->idx_ct = no;
    
    return opp;
}

// 100% matching!
void bhControlObjItm() 
{
    O_WRK* op;    
    BH_PWORK* pp; 
    int i;     
    int obj_n; 
	
    if ((sys->sp_flg & 0x4)) 
    {
        sys->ob_nlgn = 0;
        sys->ob_hlgn = 0;
        sys->ob_spcn = 0;
        
        op = sys->obwp;
        
        if ((sys->cb_flg & 0x40000000)) 
        {
            obj_n = 4;
        } 
        else 
        {
            obj_n = rom->obj_n;
        }
        
        for (i = 0; i < obj_n; i++, op++)
        {
            sys->onow = i;
            
            if ((op->flg & 0x80)) 
            {
                if ((((O_WRK*)op->lkwkp)->stflg & 0x1000000)) 
                {
                    op->stflg |= 0x1000000;
                } 
                else 
                {
                    op->stflg &= ~0x1000000; 
                }
            }
            
            if ((!(op->stflg & 0x1000000)) || (pl_sleep_cnt != 0))
            {
                if ((op->flg & 0x1))
                {
                    op->pxb = op->px;
                    op->pyb = op->py;
                    op->pzb = op->pz;
                    
                    op->axb = op->ax;
                    op->ayb = op->ay;
                    op->azb = op->az;
                    
                    if ((op->flg & 0x80)) 
                    {
                        pp = (BH_PWORK*)op->lkwkp;
                        
                        njCalcPoint(&pp->mlwP->owP[op->lkono].mtx, (NJS_POINT3*)&op->lox, (NJS_POINT3*)&op->px);
                        
                        if ((!(pp->flg & 0x10)) && ((op->flg & 0x10))) 
                        { 
                            op->flg &= ~0x10000;
                        }
                        else if ((op->flg & 0x10)) 
                        {
                            op->flg |= 0x10000;
                        }
                    }
                    
                    if ((op->flg & 0xC80000)) 
                    {
                        bhActionWeapon((BH_PWORK*)op);
                    }
                    
                    if (op->id >= 1200) 
                    {
                        bhJumpObject2[op->id - 1200](op);
                    } 
                    else
                    {
                        bhJumpObject[op->type]((BH_PWORK*)op);
                    }
                    
                    if ((!(op->mdflg & 0x1)) && (op->mlwP->objP != NULL)) 
                    {
                        if (op->id >= 1000) 
                        {
                            if ((((sys->pt_flg & 0x1)) && (op->id >= 1210)) || (((sys->pt_flg & 0x2)) && (op->id < 1210))) 
                            {
                                sys->ob_hlg[sys->ob_hlgn++] = op;
                            }
                        } 
                        else if ((sys->pt_flg & 0x4)) 
                        {
                            if ((op->type == 5) && (op->aspd != 0)) 
                            {
                                sys->ob_spc[sys->ob_spcn++] = op;
                            } 
                            else 
                            {
                                sys->ob_nlg[sys->ob_nlgn++] = op;
                            }
                        }
                    }
                    
                    if ((op->flg & 0x10000)) 
                    {
                        bhCheckWall((BH_PWORK*)op);
                    }
                    
                    if ((op->flg & 0x200000))
                    {
                        bhControlAlphaFadeObject(op);
                    }
                    
                    bhCalcModel((BH_PWORK*)op);
                }
            }
        }
        
        if (!(sys->cb_flg & 0x40000000))
        {
            op = sys->itwp;
            
            for (i = 0; i < rom->itm_n; i++, op++) 
            {
                if ((!(op->stflg & 0x1000000)) && ((op->flg & 0x1))) 
                {
                    op->pxb = op->px;
                    op->pyb = op->py;
                    op->pzb = op->pz;
                    
                    op->axb = op->ax;
                    op->ayb = op->ay;
                    op->azb = op->az;
                    
                    if (op->aspd != 0)
                    {
                        switch (op->ct0)
                        {        
                        case 1:
                            op->ct1++;
                            
                            if (op->ct1 > op->ct2)
                            {
                                op->mdflg |= 0x80;
                                
                                op->ayp = 0;
                                
                                op->ct1 = 0;
                                op->ct0++;
                            }
                            
                            break;
                        case 2:
                            op->ayp += 8192;
                            
                            op->ct1 = (op->ct1 + 1) & 7;
                            
                            if (op->ct1 == 0) 
                            {
                                op->mdflg &= ~0x80;
                                
                                op->ct0++;
                            }
                            
                            break;
                        default:
                            op->mdflg &= ~0x80;
                            
                            op->ct0 = 1;
                            op->ct1 = 0;
                            op->ct2 = (int)(30.0f * (-rand() / -2.1474836E9f)) + 60;
                            break;
                        }
                    }
                    
                    if ((op->flg & 0x200000)) 
                    {
                        bhControlAlphaFadeObject(op);
                    }
                    
                    bhCalcModel((BH_PWORK*)op);
                }
            }
        }
    }
}

// 100% matching!
void bhDrawGeneralPurposeWater()
{
    int i;
    
    if ((sys->pt_flg & 0x4))
    {
        for (i = 0; i < sys->ob_spcn; i++)
        {
            if ((((sys->stg_no == 1) && (sys->rom_no == 13)) && (i == 0)) 
            || (((sys->stg_no == 3) && (sys->rom_no == 6)) && (i == 0)) 
            || (((sys->stg_no == 7) && (sys->rom_no == 6)) && (i == 0)) 
            || (((sys->stg_no == 7) && (sys->rom_no == 10)) && (i == 0)) 
            || (((sys->stg_no == 9) && (sys->rom_no == 11)) && (i == 0)))
            {
                ulDrawGeneralPurposeWater = 1;
                
                bhDrawSpObject(sys->ob_spc[i]);
                
                ulDrawGeneralPurposeWater = 0;
            }
        }
    }
}

// 100% matching!
void bhDrawObjItm() 
{
    O_WRK* op;   
    int i;     
    NJS_VECTOR vec; 
    float its;    

    if ((sys->pt_flg & 0x4)) 
    {
        if (!(sys->st_flg & 0x20)) 
        {
            bhSetLight();
        }
        
        njCnkSetEasyMultiAmbient(rom->amb_r[rom->amb_obj], rom->amb_g[rom->amb_obj], rom->amb_b[rom->amb_obj]);
        njCnkSetSimpleMultiAmbient(rom->amb_r[rom->amb_obj], rom->amb_g[rom->amb_obj], rom->amb_b[rom->amb_obj]);
        
        for (i = 0; i < sys->ob_nlgn; i++) 
        {
            bhDrawObject(sys->ob_nlg[i]);
        }
        
        if (!(sys->st_flg & 0x20)) 
        {
            bhSetHalfLight();
        }
        
        njCnkSetEasyMultiAmbient(rom->amb_r[rom->amb_chr], rom->amb_g[rom->amb_chr], rom->amb_b[rom->amb_chr]);
        njCnkSetSimpleMultiAmbient(rom->amb_r[rom->amb_chr], rom->amb_g[rom->amb_chr], rom->amb_b[rom->amb_chr]);
        
        for (i = 0; i < sys->ob_hlgn; i++) 
        {
            bhDrawObject(sys->ob_hlg[i]);
        }
        
        for (i = 0; i < sys->ob_spcn; i++) 
        {
            if ((((sys->stg_no != 1) || (sys->rom_no != 13)) || (i != 0)) && (((sys->stg_no != 3) || (sys->rom_no != 6)) || (i != 0)) && (((sys->stg_no != 7) ||(sys->rom_no != 6)) || (i != 0)) && (((sys->stg_no != 7) || (sys->rom_no != 10)) || (i != 0)) && (((sys->stg_no != 9) || (sys->rom_no != 11)) || (i != 0)))
            {
                bhDrawSpObject(sys->ob_spc[i]);
            } 
        }
    }
    
    if (!(sys->st_flg & 0x20)) 
    {
        bhSetLight();
    }
    
    njCnkSetEasyMultiAmbient(rom->amb_r[rom->amb_itm], rom->amb_g[rom->amb_itm], rom->amb_b[rom->amb_itm]);
    njCnkSetSimpleMultiAmbient(rom->amb_r[rom->amb_itm], rom->amb_g[rom->amb_itm], rom->amb_b[rom->amb_itm]);
    
    njControl3D(0x100);
    
    if ((sys->pt_flg & 0x8))
    {
        op = sys->itwp;
        
        for (i = 0; i < rom->itm_n; i++, op++) 
        {
            if (!(op->stflg & 0x1000000)) 
            {
                if ((op->flg & 0x1))
                {
                    if (!(op->mdflg & 0x1)) 
                    {
                        if (((!(op->flg & 0x40000000)) || ((sys->gm_flg & 0x40)) || ((cam.flg & 0x46))) || ((cam.ncut == op->hide[0]) || (cam.ncut == op->hide[1]) || (cam.ncut == op->hide[2]) || (cam.ncut == op->hide[3]))) 
                        {
                            if (((op->mdflg & 0x10)) && ((sys->st_flg & 0x2))) 
                            {
                                njFogDisable();
                            }
                                
                            if ((op->mdflg & 0x80)) 
                            {
                                its = 0.1f * op->aspd;
                                
                                bhGetLightVector(57344, op->ayp, 0, &vec);
                                
                                njSetMatrix(NULL, cam.mtx);
                                
                                njCnkSetEasyMultiLightVector(vec.x, vec.y, vec.z);
                                njCnkSetEasyMultiLightColor(1, its, its, its);
                                njCnkSetEasyMultiLightSwitch(1, 1);
                                njCnkSetEasyMultiLightMatrices();
                                
                                njCnkSetSimpleMultiLightVector(vec.x, vec.y, vec.z);
                                njCnkSetSimpleMultiLightColor(1, its, its, its);
                                njCnkSetSimpleMultiLightSwitch(1, 1);
                                njCnkSetSimpleMultiLightMatrices();
                            } 
                            else
                            {
                                njSetMatrix(NULL, cam.mtx);
                                
                                if (!(sys->st_flg & 0x10000)) 
                                {
                                    njCnkSetEasyMultiLightColor(1, 0, 0, 0);
                                    njCnkSetEasyMultiLightSwitch(1, 0);
                                    
                                    njCnkSetSimpleMultiLightColor(1, 0, 0, 0);
                                    njCnkSetSimpleMultiLightSwitch(1, 0);
                                } 
                                else 
                                {
                                    njCnkSetEasyMultiLightColor(1, sys->lg_r, sys->lg_g, sys->lg_b);
                                    njCnkSetEasyMultiLightVector(sys->lg_vx, sys->lg_vy, sys->lg_vz);
                                    njCnkSetEasyMultiLightSwitch(1, 1);
                                    njCnkSetEasyMultiLightMatrices();
                                    
                                    njCnkSetSimpleMultiLightColor(1, sys->lg_r, sys->lg_g, sys->lg_b);
                                    njCnkSetSimpleMultiLightVector(sys->lg_vx, sys->lg_vy, sys->lg_vz);
                                    njCnkSetSimpleMultiLightSwitch(1, 1);
                                    njCnkSetSimpleMultiLightMatrices();
                                }
                            }
                            
                            if (op->mlwP->objP != NULL) 
                            {
                                bhPutModel((BH_PWORK*)op);
                            }
                            
                            if (((op->mdflg & 0x10)) && ((sys->st_flg & 0x2)))
                            {
                                njFogEnable();
                            }
                        }
                    }
                }
            }
        }
    }
}

// 100% matching! 
void bhDrawObject(O_WRK* op) 
{
    O_WRK* opp; // not from DWARF
    
    if ((op->flg & 0x80))
    {
        opp = (O_WRK*)op->lkwkp;
        
        if ((opp->stflg & 0x1000000)) 
        {
            op->stflg |= 0x1000000;
        }
        else
        {
            op->stflg &= ~0x1000000;
        }

        if (!((op->id < 1210) || ((sys->pt_flg & 0x1)))) 
        {
            return;
        }
    }

    if ((((op->stflg & 0x1000000)) && (pl_sleep_cnt == 0)) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40)))) 
    {
        return;
    }
    
    if ((!(op->flg & 0x40000000)) || ((sys->gm_flg & 0x40)) || ((cam.flg & 0x46)) || ((cam.ncut == op->hide[0]) || (cam.ncut == op->hide[1]) || (cam.ncut == op->hide[2]) || (cam.ncut == op->hide[3])))
    {
        if ((op->mdflg & 0x8)) 
        {
            njControl3D(0x2500);
        }
        
        if (((op->mdflg & 0x10)) && ((sys->st_flg & 0x2))) 
        {
            njFogDisable();
        }
        
        bhPutModel((BH_PWORK*)op);
        
        njControl3D(0x100);
        
        if (((op->mdflg & 0x10)) && ((sys->st_flg & 0x2))) 
        {
            njFogEnable();
        }
    }
}

// 100% matching!
void bhDrawSpObject(O_WRK* op) 
{
    LGT_WORK* lp;
    NJS_VECTOR vec;

    if (!((!(op->flg & 0x40000000)) || ((sys->gm_flg & 0x40)) || ((cam.flg & 0x46)) || ((cam.ncut == op->hide[0]) || (cam.ncut == op->hide[1]) || (cam.ncut == op->hide[2]) || (cam.ncut == op->hide[3]))))
    {
        return;
    }

    switch (op->type) 
    {
    case 5:
        lp = &rom->lgtp[op->aspd];
        
        if (op->draw_tp == 0) 
        {
            njSetMatrix(NULL, cam.mtx);
            
            njCnkSetEasyMultiLightVector(lp->vx, lp->vy, lp->vz);
            njCnkSetEasyMultiLightColor(1, lp->r, lp->g, lp->b);
            njCnkSetEasyMultiLightSwitch(1, 1);
            njCnkSetEasyMultiLightMatrices();
        } 
        else 
        {
            njCalcVector(cam.mtx, (NJS_VECTOR*)&lp->vx, &vec);
            
            njCnkSetEasyLightColor(lp->r, lp->g, lp->b);
            njCnkSetEasyLightIntensity(1.0f, 0.2f);
            njCnkSetEasyLight(vec.x, vec.y, vec.z);
        }
        
        bhPutModel((BH_PWORK*)op);
    }
}

// 100% matching!
void bhSetAlphaFadeObject(O_WRK* op, int jntno, int jnt_n, int alpha, int count)
{
	int* iwk;
	float* fwk;

	op->flg |= 0x200000;

	iwk = (int*)&op->pv[0];

    iwk[0] = jntno;
    iwk[1] = jnt_n;

	fwk = (float*)&op->pv[1];

    fwk[0] = alpha;
    fwk[1] = count;
}

// 91.58% matching
void bhControlAlphaFadeObject(O_WRK* op) 
{ 
    NJS_CNK_OBJECT* objp; 
    int* iwk;            
    float* fwk;        
    int i;              
    int jnt_n;         
    float na;            
    float alpha;         
    float count;     
    
    iwk =   (int*)&op->pv[0];
    fwk = (float*)&op->pv[1];
    
    jnt_n = iwk[1]; 
    
    na    = fwk[0]; 
    count = fwk[1]; 
    
    objp = &op->mlwP->objP[iwk[0]]; 
    
    for (i = 0; i < jnt_n; i++, objp++) 
    { 
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8)))
        { 
            alpha =  ((unsigned char*)&objp->model->plist[2])[3]; 
            alpha += (na - alpha) / count; 
            
            if (alpha < 0)
            {
                alpha = 0; 
            }
            
            if (alpha > 255.0f) 
            {
                alpha = 255.0f; 
            }
            
            npSetAllMatAlphaColor(objp, 1, (unsigned int)alpha); 
        }
    }
    
    count -= 1.0f; 
    
    if (count <= 0) 
    {
        op->flg &= ~0x200000; 
    }
    
    fwk[1] = count; 
} 

// 100% matching!
void bhObjDmy()
{

}

// 100% matching!
void bhObjItmBox(O_WRK* op)
{
    switch (op->mode0) 
    {                            
    case 0:
        op->ct0 = 0;
        
        op->mode0 = 1;
        
        CallSystemSe(0, 0x80000240);
    case 1:
        op->ct0 += 384;
        
        if (op->ct0 > 15360) 
        {
            op->mode0 = 2;
        }
        
        op->ax = -((int)(182.04445f * (80.0f * njSin(op->ct0))) & 0xFFFF);
        break;
    case 2:
        sys->cb_flg |= 0x40000;
        
        op->mode0 = 3;
        break;
    case 3:
        plp->stflg &= ~0x10000;
        
        op->ax = 0;
        
        op->type = 0;
        break;
    }
}

// 100% matching!
void bhObj001(O_WRK* op) 
{
    NJS_POINT3 pos; 
    ATR_WORK* hp; 
    int pcflg;     
    
    switch (op->mode0) 
    {                              
    case 0:                                         
        if ((op->flg & 0x100000)) 
        {
            op->mode0 = 1;
            break;
        }
        
        op->flg   |= 0x102000;
        op->mdflg |= 0x8;
        
        switch (op->aspd) 
        {                          
        case 0:                                     
        case 6:                                     
            op->aw = 4.5f;
            op->ah = 7.99f;
            op->ad = 4.5f;
            
            op->pn = 1;
            break;
        case 1:                                     
            op->aw = 2.5f;
            op->ah = 19.9f;
            op->ad = 6.0f;
            
            op->pn = 0;
            break;
        case 2:                                     
            op->aw = 3.5f;
            op->ah = 29.9f;
            op->ad = 3.5f;
            
            op->pn = 0;
            break;
        case 3:                                     
            op->aw = 3.0f;
            op->ah = 18.0f;
            op->ad = 7.5f;
            
            op->pn = 0;
            break;
        case 4:                                     
            op->aw = 5.0f;
            op->ah = 10.0f;
            op->ad = 2.5f;
            
            op->pn = 0;
            break;
        case 5:                                     
            op->aw = 2.5f;
            op->ah = 10.0f;
            op->ad = 5.0f;
            
            op->pn = 0;
            break;
        case 7:                                     
            op->aw = 2.25f;
            op->ah = 8.5f;
            op->ad = 5.5f;
            
            op->pn = 0;
            break;
        }
        
        op->ct0 = sys->mwal_n++;
        
        hp = &sys->mwalp[op->ct0];
        
        hp->flg = 0x81;
        hp->type = 0;
        
        hp->flr_no = op->flr_no;
        
        hp->attr = 0x10002;
        
        hp->px = op->px - op->aw;
        hp->py = rom->grand[hp->flr_no + 2];
        hp->pz = op->pz - op->ad;
        
        hp->w = 2.0f * op->aw;
        hp->h = op->ah;
        hp->d = 2.0f * op->ad;
        
        hp->prm0 = hp->prm1 = hp->prm2 = 0;
        hp->prm3 = sys->onow;
        
        if (op->pn != 0) 
        {
            op->ani_ct = sys->mwal_n++;
            
            hp = &sys->mwalp[op->ani_ct];
            
            hp->flg = 0x81;
            hp->type = 7;
            
            hp->flr_no = bhCheckFloorNum(9.0f + op->py);
            
            hp->attr = 1;
            
            hp->px = op->px - op->aw;
            hp->py = rom->grand[hp->flr_no + 2];
            hp->pz = op->pz - op->ad;
            
            hp->w =  2.0f * op->aw;
            hp->h = -1.0f;
            hp->d =  2.0f * op->ad;
            
            hp->prm0 = hp->prm1 = hp->prm2 = 0;
            hp->prm3 = sys->onow;
            
            op->ct1 = sys->metc_n++;
            
            hp = &sys->metcp[op->ct1];
            
            hp->flg = 0x81;
            hp->type = 2;
            
            hp->flr_no = op->flr_no;
            
            hp->attr = 0;
            
            hp->px = op->px - op->aw;
            hp->py = rom->grand[hp->flr_no + 2];
            hp->pz = op->pz - op->ad;
            
            hp->w = 2.0f * op->aw;
            hp->h = 0;
            hp->d = 2.0f * op->ad;
            
            hp->prm0 = hp->prm1 = hp->prm2 = hp->prm3 = 0;
            
            op->ct2 = sys->metc_n++;
            
            hp = &sys->metcp[op->ct2];
            
            hp->flg = 0x81;
            hp->type = 2;
            
            hp->flr_no = bhCheckFloorNum(9.0f + op->py);
            
            hp->attr = 0;
            
            hp->px = op->px - op->aw;
            hp->py = rom->grand[hp->flr_no + 2];
            hp->pz = op->pz - op->ad;
            
            hp->w = 2.0f * op->aw;
            hp->h = 0;
            hp->d = 2.0f * op->ad;
            
            hp->prm0 = 1;
            hp->prm1 = hp->prm2 = hp->prm3 = 0;
            
            op->ct3 = sys->mflr_n++;
            
            hp = &sys->mflrp[op->ct3];
            
            hp->flg = 0x81;
            hp->type = 1;
            
            hp->flr_no = bhCheckFloorNum(9.0f + op->py);
            
            hp->attr = 0;
            
            hp->px = (op->px - op->aw) - 4.0f;
            hp->py = rom->grand[hp->flr_no + 2];
            hp->pz = (op->pz - op->ad) - 4.0f;
            
            hp->w = 8.0f + (2.0f * op->aw);
            hp->h = 0;
            hp->d = 8.0f + (2.0f * op->ad);
            
            hp->prm0 = op->param;
            hp->prm1 = hp->prm2 = hp->prm3 = 0;
        }
        
        op->mode0 = 1;
    case 1:                                         
        hp = &sys->mwalp[op->ct0];
        
        hp->attr &= ~0x3C0000;
        
        pos.x = op->px;
        pos.y = op->py;
        pos.z = (op->pz - op->ad) - 0.2f;
        
        if (bhCheckWallType2(&pos, op->flg, op->aw - 0.1f, 0.1f, op->ah, op->idx_ct) != NULL) 
        {
            hp->attr |= 0x40000;
        }
        
        pos.x = op->px;
        pos.y = op->py;
        pos.z = 0.2f + (op->pz + op->ad);
        
        if (bhCheckWallType2(&pos, op->flg, op->aw - 0.1f, 0.1f, op->ah, op->idx_ct) != NULL) 
        {
            hp->attr |= 0x100000;
        }
        
        pos.x = 0.2f + (op->px + op->aw);
        pos.y = op->py;
        pos.z = op->pz;
        
        if (bhCheckWallType2(&pos, op->flg, 0.1f, op->ad - 0.1f, op->ah, op->idx_ct) != NULL) 
        {
            hp->attr |= 0x80000;
        }
        
        pos.x = (op->px - op->aw) - 0.2f;
        pos.y = op->py;
        pos.z = op->pz;
        
        if (bhCheckWallType2(&pos, op->flg, 0.1f, op->ad - 0.1f, op->ah, op->idx_ct) != NULL) 
        {
            hp->attr |= 0x200000;
        }
        
        if ((hp->attr & 0x20000)) 
        {
            if (plp->psh_idx != (op->ct0 + rom->wal_n)) 
            {
                plp->mode3 = 6;
                
                hp->attr &= ~0x20000;
            }
            else
            {
                switch (op->aspd) 
                {                    
                case 0:                                 
                    sys->psh_snd = 527;
                    break;
                case 6:                                 
                    sys->psh_snd = 528;
                    break;
                case 1:                                 
                case 3:                                 
                    sys->psh_snd = 529;
                    break;
                case 2:                                 
                    sys->psh_snd = 531;
                    break;
                case 4:                                 
                case 5:                                 
                    sys->psh_snd = 532;
                    break;
                default:                                
                    sys->psh_snd = 527;
                    break; 
                }
                
                if (((plp->stflg & 0x80)) && (plp->mode3 == 5)) 
                {
                    op->px -= plp->spd * njSin(plp->ay);
                    op->pz -= plp->spd * njCos(plp->ay);
                    
                    bhCheckWall2Box((BH_PWORK*)op);
                    
                    pcflg = 0;
                    
                    switch (plp->ay & 0xC000) 
                    {                
                    case 0:                           
                        if ((hp->attr & 0x40000))
                        {
                            pcflg = 1;
                        }
                        
                        break;
                    case 0x4000:                        
                        if ((hp->attr & 0x200000)) 
                        {
                            pcflg = 1;
                        }
                        
                        break;
                    case 0x8000:                        
                        if ((hp->attr & 0x100000))
                        {
                            pcflg = 1;
                        }
                        
                        break;
                    case 0xC000:                        
                        if ((hp->attr & 0x80000)) 
                        {
                            pcflg = 1;
                        }
                        
                        break;
                    }
                    
                    if (pcflg != 0) 
                    {
                        plp->mode3 = 6;
                    }
                } 
                else 
                {
                    hp->attr &= ~0x20000;
                }
            }
        }

        hp->px = op->px - op->aw;
        hp->pz = op->pz - op->ad;
        
        if (op->pn != 0) 
        {
            hp = &sys->mwalp[op->ani_ct];
            
            hp->px = op->px - op->aw;
            hp->pz = op->pz - op->ad;
            
            hp = &sys->metcp[op->ct1];
            
            hp->px = op->px - op->aw;
            hp->pz = op->pz - op->ad;
            
            hp = &sys->metcp[op->ct2];
            
            hp->px = op->px - op->aw;
            hp->pz = op->pz - op->ad;
            
            hp = &sys->mflrp[op->ct3];
            
            hp->px = (op->px - op->aw) - 4.0f;
            hp->pz = (op->pz - op->ad) - 4.0f;
        }
        
        break;
    }
}

// 100% matching!
void bhObj002(O_WRK* op)
{
	op->ay += (int)(182.04445f * (0.5f * op->aspd)) & 0xFFFF;
}

// 100% matching!
void bhObj003(O_WRK* op)
{
	op->az = (int)(65536.0f * njSin(op->ct0)) / 32;

    op->ct0 += 1024;
}

// 100% matching!
void bhObj004(O_WRK* op)
{
    switch (op->mode0) 
    {                            
    case 0:
        op->px = 0;
        op->py = 0;
        op->pz = 0;
        
        npChangeMatAlphaColor(op->mlwP->objP, op->mlwP->obj_num, 0);
        
        op->mode0 = 1;
        break;
    case 1:
        npChangeMatAlphaColor(op->mlwP->objP, op->mlwP->obj_num, sys->thunder);
        break;
    }
}

// 
// Start address: 0x285680
void bhObj005(O_WRK* op)
{
	//_anon36* pOrg;
	//_anon36* pCnk;
	float* wty;
	int wt_zp;
	int zp;
	int xp;
	int nb;
	int j;
	int i;
	//_anon7* pp;
	//_anon7* ps;
	//_anon5* cmd;
	// Line 1072, Address: 0x285680, Func Offset: 0
	// Line 1089, Address: 0x2856a0, Func Offset: 0x20
	// Line 1091, Address: 0x2856c0, Func Offset: 0x40
	// Line 1092, Address: 0x2856d8, Func Offset: 0x58
	// Line 1093, Address: 0x2856f8, Func Offset: 0x78
	// Line 1094, Address: 0x2856fc, Func Offset: 0x7c
	// Line 1097, Address: 0x285704, Func Offset: 0x84
	// Line 1106, Address: 0x285708, Func Offset: 0x88
	// Line 1108, Address: 0x285710, Func Offset: 0x90
	// Line 1097, Address: 0x285714, Func Offset: 0x94
	// Line 1098, Address: 0x28571c, Func Offset: 0x9c
	// Line 1101, Address: 0x285720, Func Offset: 0xa0
	// Line 1102, Address: 0x285724, Func Offset: 0xa4
	// Line 1103, Address: 0x285728, Func Offset: 0xa8
	// Line 1106, Address: 0x28572c, Func Offset: 0xac
	// Line 1107, Address: 0x285734, Func Offset: 0xb4
	// Line 1108, Address: 0x285738, Func Offset: 0xb8
	// Line 1109, Address: 0x285740, Func Offset: 0xc0
	// Line 1110, Address: 0x285760, Func Offset: 0xe0
	// Line 1111, Address: 0x285764, Func Offset: 0xe4
	// Line 1113, Address: 0x285770, Func Offset: 0xf0
	// Line 1114, Address: 0x285790, Func Offset: 0x110
	// Line 1115, Address: 0x285794, Func Offset: 0x114
	// Line 1117, Address: 0x2857a0, Func Offset: 0x120
	// Line 1118, Address: 0x2857a4, Func Offset: 0x124
	// Line 1119, Address: 0x2857a8, Func Offset: 0x128
	// Line 1156, Address: 0x2857bc, Func Offset: 0x13c
	// Line 1157, Address: 0x2857cc, Func Offset: 0x14c
	// Line 1156, Address: 0x2857d4, Func Offset: 0x154
	// Line 1157, Address: 0x2857d8, Func Offset: 0x158
	// Line 1158, Address: 0x2857e0, Func Offset: 0x160
	// Line 1157, Address: 0x2857e8, Func Offset: 0x168
	// Line 1168, Address: 0x2857ec, Func Offset: 0x16c
	// Line 1158, Address: 0x2857f0, Func Offset: 0x170
	// Line 1168, Address: 0x2857f4, Func Offset: 0x174
	// Line 1158, Address: 0x2857f8, Func Offset: 0x178
	// Line 1159, Address: 0x285804, Func Offset: 0x184
	// Line 1168, Address: 0x285810, Func Offset: 0x190
	// Line 1159, Address: 0x285814, Func Offset: 0x194
	// Line 1160, Address: 0x285820, Func Offset: 0x1a0
	// Line 1161, Address: 0x285838, Func Offset: 0x1b8
	// Line 1162, Address: 0x28584c, Func Offset: 0x1cc
	// Line 1163, Address: 0x285860, Func Offset: 0x1e0
	// Line 1164, Address: 0x285874, Func Offset: 0x1f4
	// Line 1165, Address: 0x285888, Func Offset: 0x208
	// Line 1166, Address: 0x28589c, Func Offset: 0x21c
	// Line 1168, Address: 0x2858ac, Func Offset: 0x22c
	// Line 1169, Address: 0x2858b8, Func Offset: 0x238
	// Line 1172, Address: 0x2858c0, Func Offset: 0x240
	// Line 1169, Address: 0x2858c4, Func Offset: 0x244
	// Line 1172, Address: 0x2858c8, Func Offset: 0x248
	// Line 1169, Address: 0x2858d0, Func Offset: 0x250
	// Line 1171, Address: 0x2858dc, Func Offset: 0x25c
	// Line 1172, Address: 0x2858e0, Func Offset: 0x260
	// Line 1174, Address: 0x2858ec, Func Offset: 0x26c
	// Line 1173, Address: 0x2858f4, Func Offset: 0x274
	// Line 1174, Address: 0x2858fc, Func Offset: 0x27c
	// Line 1175, Address: 0x285908, Func Offset: 0x288
	// Line 1179, Address: 0x28590c, Func Offset: 0x28c
	// Line 1180, Address: 0x285918, Func Offset: 0x298
	// Line 1181, Address: 0x28592c, Func Offset: 0x2ac
	// Line 1182, Address: 0x285934, Func Offset: 0x2b4
	// Line 1183, Address: 0x285940, Func Offset: 0x2c0
	// Line 1187, Address: 0x285948, Func Offset: 0x2c8
	// Line 1183, Address: 0x28594c, Func Offset: 0x2cc
	// Line 1184, Address: 0x285968, Func Offset: 0x2e8
	// Line 1185, Address: 0x28596c, Func Offset: 0x2ec
	// Line 1186, Address: 0x285970, Func Offset: 0x2f0
	// Line 1187, Address: 0x285974, Func Offset: 0x2f4
	// Line 1189, Address: 0x285988, Func Offset: 0x308
	// Line 1190, Address: 0x285990, Func Offset: 0x310
	// Line 1189, Address: 0x285994, Func Offset: 0x314
	// Line 1191, Address: 0x2859a0, Func Offset: 0x320
	// Line 1195, Address: 0x2859a8, Func Offset: 0x328
	// Line 1197, Address: 0x2859d4, Func Offset: 0x354
	// Line 1198, Address: 0x2859ec, Func Offset: 0x36c
	// Line 1200, Address: 0x2859f4, Func Offset: 0x374
	// Line 1201, Address: 0x285a0c, Func Offset: 0x38c
	// Line 1203, Address: 0x285a14, Func Offset: 0x394
	// Line 1204, Address: 0x285a2c, Func Offset: 0x3ac
	// Line 1206, Address: 0x285a34, Func Offset: 0x3b4
	// Line 1207, Address: 0x285a4c, Func Offset: 0x3cc
	// Line 1209, Address: 0x285a54, Func Offset: 0x3d4
	// Line 1210, Address: 0x285a6c, Func Offset: 0x3ec
	// Line 1212, Address: 0x285a74, Func Offset: 0x3f4
	// Line 1213, Address: 0x285a8c, Func Offset: 0x40c
	// Line 1215, Address: 0x285a94, Func Offset: 0x414
	// Line 1216, Address: 0x285aac, Func Offset: 0x42c
	// Line 1218, Address: 0x285ab4, Func Offset: 0x434
	// Line 1219, Address: 0x285acc, Func Offset: 0x44c
	// Line 1221, Address: 0x285ad4, Func Offset: 0x454
	// Line 1222, Address: 0x285aec, Func Offset: 0x46c
	// Line 1224, Address: 0x285af4, Func Offset: 0x474
	// Line 1225, Address: 0x285b0c, Func Offset: 0x48c
	// Line 1227, Address: 0x285b14, Func Offset: 0x494
	// Line 1228, Address: 0x285b2c, Func Offset: 0x4ac
	// Line 1230, Address: 0x285b34, Func Offset: 0x4b4
	// Line 1231, Address: 0x285b4c, Func Offset: 0x4cc
	// Line 1233, Address: 0x285b54, Func Offset: 0x4d4
	// Line 1234, Address: 0x285b6c, Func Offset: 0x4ec
	// Line 1236, Address: 0x285b74, Func Offset: 0x4f4
	// Line 1237, Address: 0x285b8c, Func Offset: 0x50c
	// Line 1239, Address: 0x285b94, Func Offset: 0x514
	// Line 1240, Address: 0x285bac, Func Offset: 0x52c
	// Line 1242, Address: 0x285bb4, Func Offset: 0x534
	// Line 1245, Address: 0x285bcc, Func Offset: 0x54c
	// Line 1284, Address: 0x285bd0, Func Offset: 0x550
	// Line 1245, Address: 0x285bd4, Func Offset: 0x554
	// Line 1284, Address: 0x285be0, Func Offset: 0x560
	// Line 1286, Address: 0x285be4, Func Offset: 0x564
	// Line 1287, Address: 0x285be8, Func Offset: 0x568
	// Line 1675, Address: 0x285bec, Func Offset: 0x56c
	// Line 1284, Address: 0x285bf0, Func Offset: 0x570
	// Line 1292, Address: 0x285bfc, Func Offset: 0x57c
	// Line 1293, Address: 0x285c00, Func Offset: 0x580
	// Line 1285, Address: 0x285c04, Func Offset: 0x584
	// Line 1284, Address: 0x285c10, Func Offset: 0x590
	// Line 1677, Address: 0x285c14, Func Offset: 0x594
	// Line 1679, Address: 0x285c1c, Func Offset: 0x59c
	// Line 1680, Address: 0x285c28, Func Offset: 0x5a8
	// Line 1682, Address: 0x285c30, Func Offset: 0x5b0
	// Line 1683, Address: 0x285c34, Func Offset: 0x5b4
	// Line 1684, Address: 0x285c38, Func Offset: 0x5b8
	// Line 1685, Address: 0x285c3c, Func Offset: 0x5bc
	// Line 1686, Address: 0x285c40, Func Offset: 0x5c0
	// Line 1687, Address: 0x285c44, Func Offset: 0x5c4
	// Line 1688, Address: 0x285c48, Func Offset: 0x5c8
	// Line 1689, Address: 0x285c4c, Func Offset: 0x5cc
	// Line 1691, Address: 0x285c50, Func Offset: 0x5d0
	// Line 1692, Address: 0x285c54, Func Offset: 0x5d4
	// Line 1693, Address: 0x285c58, Func Offset: 0x5d8
	// Line 1694, Address: 0x285c5c, Func Offset: 0x5dc
	// Line 1695, Address: 0x285c60, Func Offset: 0x5e0
	// Line 1696, Address: 0x285c64, Func Offset: 0x5e4
	// Line 1697, Address: 0x285c68, Func Offset: 0x5e8
	// Line 1699, Address: 0x285c6c, Func Offset: 0x5ec
	// Line 1700, Address: 0x285c70, Func Offset: 0x5f0
	// Line 1701, Address: 0x285c74, Func Offset: 0x5f4
	// Line 1702, Address: 0x285c78, Func Offset: 0x5f8
	// Line 1703, Address: 0x285c7c, Func Offset: 0x5fc
	// Line 1704, Address: 0x285c80, Func Offset: 0x600
	// Line 1705, Address: 0x285c84, Func Offset: 0x604
	// Line 1706, Address: 0x285c88, Func Offset: 0x608
	// Line 1707, Address: 0x285c8c, Func Offset: 0x60c
	// Line 1709, Address: 0x285c94, Func Offset: 0x614
	// Line 1710, Address: 0x285c98, Func Offset: 0x618
	// Line 1711, Address: 0x285c9c, Func Offset: 0x61c
	// Line 1712, Address: 0x285ca0, Func Offset: 0x620
	// Line 1713, Address: 0x285ca4, Func Offset: 0x624
	// Line 1714, Address: 0x285ca8, Func Offset: 0x628
	// Line 1715, Address: 0x285cac, Func Offset: 0x62c
	// Line 1716, Address: 0x285cb0, Func Offset: 0x630
	// Line 1717, Address: 0x285cb4, Func Offset: 0x634
	// Line 1718, Address: 0x285cb8, Func Offset: 0x638
	// Line 1719, Address: 0x285cbc, Func Offset: 0x63c
	// Line 1720, Address: 0x285cc0, Func Offset: 0x640
	// Line 1721, Address: 0x285cc4, Func Offset: 0x644
	// Line 1722, Address: 0x285cc8, Func Offset: 0x648
	// Line 1723, Address: 0x285ccc, Func Offset: 0x64c
	// Line 1811, Address: 0x285cd4, Func Offset: 0x654
	// Line 1812, Address: 0x285d00, Func Offset: 0x680
	// Line 1813, Address: 0x285d04, Func Offset: 0x684
	// Line 1814, Address: 0x285d08, Func Offset: 0x688
	// Line 1815, Address: 0x285d0c, Func Offset: 0x68c
	// Line 1816, Address: 0x285d10, Func Offset: 0x690
	// Line 1817, Address: 0x285d14, Func Offset: 0x694
	// Line 1819, Address: 0x285d1c, Func Offset: 0x69c
	// Line 1820, Address: 0x285d20, Func Offset: 0x6a0
	// Line 1821, Address: 0x285d24, Func Offset: 0x6a4
	// Line 1822, Address: 0x285d28, Func Offset: 0x6a8
	// Line 1823, Address: 0x285d2c, Func Offset: 0x6ac
	// Line 1824, Address: 0x285d30, Func Offset: 0x6b0
	// Line 1825, Address: 0x285d34, Func Offset: 0x6b4
	// Line 1826, Address: 0x285d38, Func Offset: 0x6b8
	// Line 1827, Address: 0x285d3c, Func Offset: 0x6bc
	// Line 1828, Address: 0x285d40, Func Offset: 0x6c0
	// Line 1829, Address: 0x285d44, Func Offset: 0x6c4
	// Line 1830, Address: 0x285d48, Func Offset: 0x6c8
	// Line 1831, Address: 0x285d4c, Func Offset: 0x6cc
	// Line 1832, Address: 0x285d50, Func Offset: 0x6d0
	// Line 1833, Address: 0x285d54, Func Offset: 0x6d4
	// Line 1834, Address: 0x285d58, Func Offset: 0x6d8
	// Line 1836, Address: 0x285d5c, Func Offset: 0x6dc
	// Line 1837, Address: 0x285d64, Func Offset: 0x6e4
	// Line 1838, Address: 0x285d68, Func Offset: 0x6e8
	// Line 1840, Address: 0x285d6c, Func Offset: 0x6ec
	// Line 1841, Address: 0x285d74, Func Offset: 0x6f4
	// Line 1842, Address: 0x285d78, Func Offset: 0x6f8
	// Line 1843, Address: 0x285d7c, Func Offset: 0x6fc
	// Line 1844, Address: 0x285d80, Func Offset: 0x700
	// Line 1846, Address: 0x285d84, Func Offset: 0x704
	// Line 1858, Address: 0x285d8c, Func Offset: 0x70c
	// Func End, Address: 0x285db0, Func Offset: 0x730
	scePrintf("bhObj005 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhObj006(O_WRK* op) 
{
    NJS_CNK_OBJECT* obp; 
    NJS_POINT3 ps, ps0;       
    NJS_LINE line;      
    float len;           
    LGT_WORK* lp;        

    line.px = op->px;
    line.py = op->py; 
    line.pz = op->pz;
    
    ps.x = 0;
    ps.y = 0; 
    ps.z = -1.0f;
    
    njUnitMatrix(NULL);
    
    njRotateXYZ(NULL, op->ax, op->ay, op->az);
    
    obp = op->mlwP->objP;
    
    njRotateXYZ(NULL, obp[0].ang[0], obp[0].ang[1], obp[0].ang[2]);
    njRotateXYZ(NULL, obp[1].ang[0], obp[1].ang[1], obp[1].ang[2]);
    
    njCalcVector(NULL, &ps, (NJS_VECTOR*)&line.vx);
    
    ps0.x = op->px + line.vx;
    ps0.y = op->py + line.vy;
    ps0.z = op->pz + line.vz;
    
    njGetPlaneNormal2((NJS_VECTOR*)&cam.wpx, (NJS_VECTOR*)&op->px, &ps0, (NJS_POINT3*)&ps);
    
    njUnitVector(&ps);
    njUnitMatrix(NULL);
    
    njTranslate(NULL, op->px, op->py, op->pz);
    njRotateXYZ(NULL, op->ax, op->ay, op->az);
    
    obp = op->mlwP->objP;
    
    njRotateXYZ(NULL, obp[0].ang[0], obp[0].ang[1], obp[0].ang[2]);
    njRotateXYZ(NULL, obp[1].ang[0], obp[1].ang[1], obp[1].ang[2]);
    
    npClrTranslate();
    
    njTransposeMatrix(NULL);
    
    njCalcPoint(NULL, &ps, &ps0);
    
    op->mlwP->objP[2].ang[2] = -(int)(10430.381f * atan2f(-ps0.x, -ps0.y)) - 16384;
    
    if (op->aspd > 0) 
    {
        lp = &rom->evlp[op->aspd];
        
        line.vx *= 200.0f;
        line.vy *= 200.0f;
        line.vz *= 200.0f;
        
        ps.x = ps.y = 0;
        
        if (bhCheckL2Wall(&line, 1024, &len) != 0)
        {
            ps.z = -(len - 30.0f);
            
            if (ps.z > 0)
            {
                ps.z = 0;
            }
            
            lp->nr = 0.1f * len;
            
            if (lp->nr < 10.0f) 
            {
                lp->nr = 10.0f;
            }
            
            lp->fr = 10.0f + lp->nr;
        } 
        else 
        {
            ps.z = -170.0f;
            
            lp->nr = 20.0f;
            lp->fr = 30.0f;
        }
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, op->az);
        
        obp = op->mlwP->objP;
        
        njRotateXYZ(NULL, obp[0].ang[0], obp[0].ang[1], obp[0].ang[2]);
        njRotateXYZ(NULL, obp[1].ang[0], obp[1].ang[1], obp[1].ang[2]);
        
        njCalcPoint(NULL, &ps, &ps0);
        
        lp->px = op->px + ps0.x;
        lp->py = op->py + ps0.y;
        lp->pz = op->pz + ps0.z;
    }
}

// 100% matching!
void bhObj007(O_WRK* op) 
{
    NJS_LINE lin;   
    NJS_POINT3 ps0, ps1, ps2; 
    float len0, len1, len2;  
    float inn;   

    if ((op->py >= 1.0f) && (op->mode0 != 4)) 
    {
        switch (op->mode0) 
        {                     
        case 0:
            op->ct0 = 0;
            
            op->mode0 = 1;
            break;
        case 1:
            lin.px = op->px;
            lin.py = 0;
            lin.pz = op->pz;
            
            lin.vx = -njSin((op->ay + 32767) + 1);
            lin.vy = 0;
            lin.vz = -njCos((op->ay + 32767) + 1);
            
            njDistanceP2L((NJS_POINT3*)&plp->px, &lin, &ps0);
            
            ps2 = ps0;
            
            ps0.x -= op->px;
            ps0.y = 0;
            ps0.z -= op->pz;
             
            len0 = njScalor(&ps0);
            
            njUnitVector(&ps0);
            
            if (len0 > 10.0f) 
            {
                len0 = 10.0f;
                
                ps2.x = op->px + (10.0f * lin.vx);
                ps2.z = op->pz + (10.0f * lin.vz);
            }
            
            ps1.x = plp->px - op->px;
            ps1.y = 0;
            ps1.z = plp->pz - op->pz;
            
            len1 = njScalor(&ps1);
            
            njUnitVector(&ps1);
            
            inn = njInnerProduct((NJS_VECTOR*)&lin.vx, &ps1);
            
            ps0.x = plp->px - ps2.x;
            ps0.y = 0;
            ps0.z = plp->pz - ps2.z;
            
            len2 = njScalor(&ps0);
            
            njUnitVector(&ps0);
            
            if ((inn > 0) && (((len0 + plp->ar) >= len1) && (len2 < plp->ar))) 
            {
                plp->px = PEXP0_F(72) = ps2.x + (ps0.x * plp->ar);
                plp->pz = PEXP0_F(80) = ps2.z + (ps0.z * plp->ar);
                
                ps1.x = -njSin(plp->ay);
                ps1.y = 0;
                ps1.z = -njCos(plp->ay); 
                
                inn = njInnerProduct(&ps0, &ps1);
                
                if ((len0 < 8.4f) && (inn < -0.7f) && ((sys->pad_on & 0x1)) && (!(plp->stflg & 0x80))) 
                {
                    if ((plp->mode2 == 3) || (plp->mode2 == 4) || (plp->mode2 == 5))
                    {
                        op->ct0++;
                        
                        if (op->ct0 > 5) 
                        {
                            ps0.x = -njSin(op->ay + 16384);
                            ps0.y = 0;
                            ps0.z = -njCos(op->ay + 16384);
                            
                            if (njInnerProduct(&ps0, &ps1) > 0) 
                            {
                                plp->azp = op->ay + 16384;
                                
                                op->mode0 = 2;
                            } 
                            else
                            {
                                plp->azp = op->ay - 16384;
                                
                                op->mode0 = 3;
                            }
                            
                            plp->stflg |= 0x80;
                            
                            plp->mode2 = 0x16;
                            plp->mode3 = 0;
                            
                            op->spd = len0;
                        }
                    }
                } 
                else 
                {
                    op->ct0 = 0;
                }
            }
            
            break;
        case 2:
            if (plp->mode3 == 5)
            {
                if (!(sys->pad_on & 0x1))
                {
                    op->mode0 = 1;
                    
                    op->ct0 = 0;
                    break;
                }
                
                op->ay -= (int)(182.04445f * njSin(((plp->frm_no / 65536) * 819) & 0x7FFF)) & 0xFFFF;
                
                plp->ay = op->ay + 16384;
                
                ps0.x = op->px - (op->spd * njSin((op->ay + 32767) + 1));
                ps0.z = op->pz - (op->spd * njCos((op->ay + 32767) + 1));
                
                plp->px = PEXP0_F(72) = ps0.x - (plp->ar * njSin(op->ay - 16384));
                plp->pz = PEXP0_F(80) = ps0.z - (plp->ar * njCos(op->ay - 16384));
                
                if (ABS((short)op->ay) < 182)
                {
                    op->ay = 0;
                    
                    plp->mode3 = 6;
                    op->mode0 = 4;
                    
                    bhStFlg(sys->ev_flg, 2);
                }
            } 
            else if (!(plp->stflg & 0x80)) 
            {
                op->mode0 = 1;
                
                op->ct0 = 0;
            }
            
            break;
        case 3:
            if (plp->mode3 == 5) 
            {
                if (!(sys->pad_on & 0x1)) 
                {
                    op->mode0 = 1;
                    
                    op->ct0 = 0;
                    break;
                }
                
                op->ay += (int)(182.04445f * njSin(((plp->frm_no / 65536) * 819) & 0x7FFF)) & 0xFFFF;
                
                plp->ay = op->ay - 16384;
                
                ps0.x = op->px - (op->spd * njSin((op->ay + 32767) + 1));
                ps0.z = op->pz - (op->spd * njCos((op->ay + 32767) + 1));
                
                plp->px = PEXP0_F(72) = ps0.x - (plp->ar * njSin(op->ay + 16384));
                plp->pz = PEXP0_F(80) = ps0.z - (plp->ar * njCos(op->ay + 16384));
                
                if (ABS((short)op->ay) < 182) 
                {
                    op->ay = 0;
                    
                    plp->mode3 = 6;
                    op->mode0 = 4;
                    
                    bhStFlg(sys->ev_flg, 2);
                }
            } 
            else if (!(plp->stflg & 0x80))
            {
                op->mode0 = 1;
                
                op->ct0 = 0;
            }
            
            break;
        }
    }
}

// 100% matching!
void bhObj008(O_WRK* op) 
{
    ATR_WORK* hp;
    
    if (op->mode0 == 0) 
    {
        if ((op->flg & 0x100000)) 
        {
            op->mode0 = 1;
            return;
        }
        
        op->flg |= 0x100000;
        
        op->gpx = op->px;
        op->gpy = op->py;
        op->gpz = op->pz;
        
        op->ct0 = sys->mwal_n++;
        
        hp = &sys->mwalp[op->ct0];
        
        hp->flg = 129;
        hp->type = 0;
        
        hp->flr_no = op->flr_no;
        
        hp->attr = 0;
        
        hp->px = op->px - 6.0f;
        hp->py = rom->grand[hp->flr_no + 2];
        hp->pz = op->pz - 11.0f;
        
        hp->w = 12.0f;
        hp->h = 20.0f;
        hp->d = 22.0f;
        
        hp->prm3 = 0;
        hp->prm2 = 0;
        hp->prm1 = 0;
        hp->prm0 = 0;
        
        op->mode0 = 1;
        return;
    }
    
    hp = &sys->mwalp[op->ct0];
    
    hp->px = op->mlwP->owP->mtx[12] - 6.0f;
    hp->py = op->mlwP->owP->mtx[13]; 
    hp->pz = op->mlwP->owP->mtx[14] - 11.0f;
}

// 100% matching!
void bhObj009(O_WRK* op)
{
    POS* ptp;    
    NJS_VECTOR vec; 
    float ln;     

    if (bhCkFlg(&sys->rm_flg, 31) != 0) 
    {
        switch (op->mode0) 
        {
        case 1:
            ptp = rom->posp;
            
            op->px = op->gpx;
            op->pz = op->gpz;
            
            op->ay += (op->ayp - op->ay) / 16;
            
            vec.x = ptp[op->ct0 + 1].px - ptp[op->ct0].px;
            vec.y = 0;
            vec.z = ptp[op->ct0 + 1].pz - ptp[op->ct0].pz;
            
            ln = njSqrt((vec.x * vec.x) + (vec.z * vec.z));
            
            njUnitVector(&vec);
            
            op->px += 0.25f * vec.x;
            op->pz += 0.25f * vec.z;
            
            op->gpx = op->px;
            op->gpz = op->pz; 
            
            op->spd += 0.25f;
            
            if (op->spd >= ln) 
            {
                op->ct0++;
                
                op->spd = 0;
                
                op->ayp = ptp[op->ct0 + 1].ay - 16384;
                
                if ((op->ayp & 0xFF00) != (op->ay & 0xFF00)) 
                {
                    op->xn = 0.8f;
                }
                
                if (op->ct0 >= 14) 
                {
                    op->ct0 = 7;
                    
                    op->px = ptp[op->ct0].px;
                    op->pz = ptp[op->ct0].pz;
                    
                    op->gpx = op->px;
                    op->gpz = op->pz;
                    
                    op->ay = op->ayp = ptp[op->ct0].ay - 16384;
                    
                    if (bhCkFlg(sys->ev_flg, 60) != 0) 
                    {
                        bhCrFlg(&sys->rm_flg, 31);
                        
                        op->ct1 = 0;
                        
                        op->mode0 = 2;
                        break;
                    }
                    
                    op->mode1 = 1;
                    
                    bhSetScreenFade(sys->fade_pbk, 30.0f);
                }
            }
            
            op->px = op->gpx + ((op->xn - (0.5f * op->xn)) * (-rand() / -2.1474836E9f));
            op->pz = op->gpz + ((op->xn - (0.5f * op->xn)) * (-rand() / -2.1474836E9f));
            
            if (op->xn > 0)
            {
                op->xn *= 0.9f;
                
                if (op->xn < 0.1f) 
                {
                    op->xn = 0;
                }
            }
            
            if ((op->ct0 == 13) && (op->spd >= (0.5f * ln)) && (op->ct2 == 0)) 
            {
                op->ct2++;
                
                bhSetScreenFade(0xFF000000, 30.0f);
            }
            
            if ((op->mode1 != 0) && (op->ct0 == 11) && (op->spd >= (0.75f * ln))) 
            {
                bhCrFlg(&sys->rm_flg, 31);
                
                op->mode0 = 0;
            }
        }
    } 
    else 
    {
        switch (op->mode0) 
        {                          
        case 0:
            ptp = rom->posp;
            
            vec.x = ptp[12].px - ptp[11].px;
            vec.z = ptp[12].pz - ptp[11].pz;
            
            op->spd = 0.75f * njSqrt((vec.x * vec.x) + (vec.z * vec.z));
            
            op->px = ptp[11].px + (0.75f * vec.x);
            op->pz = ptp[11].pz + (0.75f * vec.z);
            
            op->gpx = op->px;
            op->gpz = op->pz;
            
            op->ay  = 0;
            op->ayp = ptp[12].ay - 16384;
            
            op->zn = 0;
            op->xn = 0;
            
            op->ct0 = 11;
            op->ct2 = 0;
            op->ct1 = 0;
            
            op->mode0 = 1;
            op->mode1 = 0;
            break;
        case 2:
            op->ct1++;
            
            if (op->ct1 >= 4) 
            {
                bhSetScreenFade(sys->fade_pbk, 20.0f);
                
                *(int*)&op->mode0 = 0;
            }
            
            break;
        }
    }
}

// 100% matching!
void bhObj010(O_WRK* op)
{
	if (bhCkFlg(&sys->rm_flg, 31) != 0)
    {
        npSetOffsetUV(op->mlwP->objP->model, 32, 0);

        op->ct0 = (op->ct0 + 32) & 0x3FF;

        if (op->ct0 == 0)
        {
            npSetOffsetUV(op->mlwP->objP->model, -1024, 0);
        }
    }
}

// 100% matching!
void bhObj011(O_WRK* op)
{
	op->mdflg |= 0x8;
}

// 100% matching!
void bhObj012(O_WRK* op) 
{
    ATR_WORK* hp;
    
    if (op->mode0 == 0) 
    {
        if ((op->flg & 0x100000)) 
        {
            op->mode0 = 1;
            return;
        }
        
        op->flg |= 0x100000;
        
        op->ct0 = sys->mwal_n++;
        
        hp = &sys->mwalp[op->ct0];
        
        hp->flg = 129;
        hp->type = 2;
        
        hp->flr_no = op->flr_no;
        
        hp->attr = 0x1000000;
        
        hp->px = op->px;
        hp->py = rom->grand[hp->flr_no + 2];
        hp->pz = op->pz;
        
        hp->w = 4.0f;
        hp->h = 15.0f;
        hp->d = 0;
        
        hp->prm2 = 0;
        hp->prm1 = 0;
        hp->prm0 = 0;
        hp->prm3 = sys->onow;
        
        op->mode0 = 1;
        return;
    }
    
    hp = &sys->mwalp[op->ct0];
    
    hp->px = op->mlwP->owP->mtx[12]; 
    hp->py = op->mlwP->owP->mtx[13];
    hp->pz = op->mlwP->owP->mtx[14];
}

// 99.96% matching
void bhObjClpn(O_WRK* op)
{
    BH_PWORK* pp;   
    HAIR_WORK* hair; 
    int i;      
    short ax, ay;   
    short rx, ry;        
    NJS_POINT3* p3p, *g3p, *psp; 
    NJS_POINT3 ps1, ps2, ps3, ps4, ps5;  
    float px, py, pz; // px is not from DWARF
    float ln;       
    float tmp;        // not from DWARF
    
    if (((op->flg & 0x80)) && (op->mode0 != 2))
    {
        switch (op->mode0) 
        {                          
        case 0:
            op->flg |= 0x1000;
            
            if (!(op->flg & 0x100000))
            {
                op->flg |= 0x100000;
                
                if (op->lkwkp == (unsigned char*)plp) 
                {
                    op->exp0 = &sys->pletcp[4096];
                    op->exp3 = sys->pletcp;
                }
                else 
                {
                    op->exp0 = bhGetFreeMemory(0x4000, 32);
                    op->exp3 = bhGetFreeMemory(0x1000, 32);
                }
            }
            
            op->ct0 = 0;
            op->ct1 = 0;
            op->ct2 = 0;
            op->ct3 = 0;
            
            p3p = (NJS_POINT3*)op->exp0;
            
            for (i = 128; i-- != 0; p3p++) 
            {
                p3p->x = 0;
                p3p->y = 0; 
                p3p->z = 0;
            } 
            
            op->xn  = op->yn  = op->zn  = 0;
            op->gpx = op->gpy = op->gpz = 0;
            
            op->spd = 0;
            
            op->mode0 = 1;
            break;
        case 1:
            pp = (BH_PWORK*)op->lkwkp;
            
            hair = (HAIR_WORK*)op->exp3;
            
            if ((pp->flg2 & 0x2))
            {
                pp->flg2 &= ~0x2;
                
                npSetMemoryL((unsigned int*)op->exp0, 0x1000, 0);
                npSetMemory(op->exp3, sizeof(HAIR_WORK), 0);
                
                p3p = (NJS_POINT3*)op->exp0;
                
                for (i = 128; i-- != 0; p3p++) 
                {
                    p3p->x = 0;
                    p3p->y = 0;
                    p3p->z = 0;
                } 
                
                op->xn  = op->yn  = op->zn  = 0;
                op->gpx = op->gpy = op->gpz = 0;
                
                op->spd = 0;
            }
            
            bhCalcHair(op, pp);

            p3p = (NJS_POINT3*)op->exp0 + op->ct0;
            
            tmp = -hair->spx * 0.25f;
            py  = -hair->spy * 0.25f;
            pz  = -hair->spz * 0.25f;
            
            op->xn += 0.333f * (tmp - op->xn);
            op->yn += 0.333f * (py  - op->yn);
            op->zn += 0.333f * (pz  - op->zn);  
            
            px = op->mlwP->owP->mtx[12];
            py = op->mlwP->owP->mtx[13];
            pz = op->mlwP->owP->mtx[14];
            
            p3p->x = op->xn;
            p3p->y = op->yn;
            p3p->z = op->zn;
            
            g3p = (NJS_POINT3*)&op->exp0[4096]; 
            psp = (NJS_POINT3*)&op->exp0[8192];

            rx = 0;
            ry = 0;
            
            for (i = 0; i < 4; psp++, g3p++, i++) 
            {
                p3p = (NJS_POINT3*)op->exp0 + ((op->ct0 - (3 * i)) & 0x7F);
                
                njUnitMatrix(NULL);
                
                njRotateY(NULL, hair->ay);
                
                njCalcPoint(NULL, p3p, &ps1);
                
                if ((pp->flg2 & 0x100))
                {
                    g3p->x = px;
                    g3p->y = py - 1.0f;
                    g3p->z = pz;
                } 
                else
                {
                    g3p->x = px + ps1.x;
                    
                    op->spd += p3p->y;
                    op->spd -= 0.333f;
                    
                    if (op->spd > 0.5f)
                    {
                        op->spd = 0.5f;
                    }
                    
                    if (op->spd < -0.5f)
                    {
                        op->spd = -0.5f;
                    }
                    
                    g3p->y = op->spd + (py + ps1.y);
                    g3p->z = pz + ps1.z;
                }
                
                ps2.x = 0;
                ps2.y = 1.0f;
                ps2.z = 0; 
                
                njCalcPoint(&pp->mlwP->owP[5].mtx, &ps2, &ps3);
                
                ps2.x = g3p->x - ps3.x;
                ps2.y = g3p->y - ps3.y;
                ps2.z = g3p->z - ps3.z;
                
                ln = njSqrt((ps2.x * ps2.x) + (ps2.z * ps2.z));
                
                if (ln < 1.0f) 
                {
                    ps2.y = 0;
                        
                    njUnitVector(&ps2);
                    
                    g3p->x = ps3.x + ps2.x;
                    g3p->z = ps3.z + ps2.z; 
                }
                
                psp->x += 0.333f * (g3p->x - psp->x);
                psp->y += 0.333f * (g3p->y - psp->y);
                psp->z += 0.333f * (g3p->z - psp->z);
                
                ps1.x = psp->x - px;
                ps1.y = psp->y - py;
                ps1.z = psp->z - pz;
                
                if (njScalor(&ps1) > 0.5f)
                {
                    njUnitVector(&ps1);
                    
                    ps1.x *= 0.5f;
                    ps1.y *= 0.5f;
                    ps1.z *= 0.5f;
                    
                    psp->x = px + ps1.x;
                    psp->y = py + ps1.y;
                    psp->z = pz + ps1.z;
                }
                
                ps4.x =  0;
                ps4.y =  1.8f;
                ps4.z = -0.3f;
                
                njCalcPoint(&pp->mlwP->owP[5].mtx, &ps4, &ps5);
                
                ps5.y = ps3.y;
                
                ps2.x = psp->x - ps5.x;
                ps2.y = psp->y - ps5.y;
                ps2.z = psp->z - ps5.z;
                
                ln = njSqrt((ps2.x * ps2.x) + (ps2.z * ps2.z));
                
                if (ln < 1.3f) 
                {
                    ps2.y = 0;
                        
                    njUnitVector(&ps2);
                    
                    psp->x = ps5.x + (1.3f * ps2.x);
                    psp->z = ps5.z + (1.3f * ps2.z);
                }
                
                ps1.x = psp->x - px;
                ps1.y = psp->y - py;
                ps1.z = psp->z - pz;
                
                if (njScalor(&ps1) > 0.5f) 
                {
                    njUnitVector(&ps1);
                    
                    ps1.x *= 0.5f;
                    ps1.y *= 0.5f;
                    ps1.z *= 0.5f;
                    
                    psp->x = px + ps1.x;
                    psp->y = py + ps1.y;
                    psp->z = pz + ps1.z;
                }
                
                njUnitMatrix(NULL);
                
                njRotateX(NULL, rx);
                njRotateY(NULL, ry);
                
                njCalcPoint(NULL, &ps1, &ps3);
                
                ay = 10430.381f * atan2f(ps3.x, 0.1f + ps3.z);
                ry -= ay;
                
                op->mlwP->objP[i].ang[1] = ay;
                
                ax = 182.04445f * (150.0f * -ps3.y);
                rx -= ax;
                
                op->mlwP->objP[i].ang[0] = ax;
                
                px = psp->x;
                py = psp->y;
                pz = psp->z;
                
                op->pv[i].x = px;
                op->pv[i].y = py;  
                op->pv[i].z = pz;
            }
            
            op->ct0 = (op->ct0 + 1) & 0x7F;
            break;
        }
    }
}

// 100% matching!
void bhObjWssg()
{

}
