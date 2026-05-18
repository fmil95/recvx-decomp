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

// 
// Start address: 0x2872b0
void bhObjClpn(O_WRK* op)
{
	float ln;
	float pz;
	float py;
	//_anon32 ps5;
	//_anon32 ps4;
	//_anon32 ps3;
	//_anon32 ps2;
	//_anon32 ps1;
	//_anon32* psp;
	//_anon32* g3p;
	//_anon32* p3p;
	short ry;
	short rx;
	short ay;
	short ax;
	int i;
	//_anon35* hair;
	BH_PWORK* pp;
	// Line 2547, Address: 0x2872b0, Func Offset: 0
	// Line 2556, Address: 0x2872e8, Func Offset: 0x38
	// Line 2557, Address: 0x2872f8, Func Offset: 0x48
	// Line 2559, Address: 0x287324, Func Offset: 0x74
	// Line 2560, Address: 0x28732c, Func Offset: 0x7c
	// Line 2561, Address: 0x287340, Func Offset: 0x90
	// Line 2562, Address: 0x287348, Func Offset: 0x98
	// Line 2563, Address: 0x28735c, Func Offset: 0xac
	// Line 2564, Address: 0x287378, Func Offset: 0xc8
	// Line 2565, Address: 0x28738c, Func Offset: 0xdc
	// Line 2566, Address: 0x287394, Func Offset: 0xe4
	// Line 2567, Address: 0x2873a0, Func Offset: 0xf0
	// Line 2570, Address: 0x2873b4, Func Offset: 0x104
	// Line 2571, Address: 0x2873b8, Func Offset: 0x108
	// Line 2572, Address: 0x2873bc, Func Offset: 0x10c
	// Line 2573, Address: 0x2873c0, Func Offset: 0x110
	// Line 2574, Address: 0x2873c4, Func Offset: 0x114
	// Line 2575, Address: 0x2873c8, Func Offset: 0x118
	// Line 2576, Address: 0x2873cc, Func Offset: 0x11c
	// Line 2577, Address: 0x2873d8, Func Offset: 0x128
	// Line 2578, Address: 0x2873dc, Func Offset: 0x12c
	// Line 2579, Address: 0x2873e0, Func Offset: 0x130
	// Line 2581, Address: 0x2873e4, Func Offset: 0x134
	// Line 2580, Address: 0x2873e8, Func Offset: 0x138
	// Line 2581, Address: 0x2873ec, Func Offset: 0x13c
	// Line 2582, Address: 0x2873f8, Func Offset: 0x148
	// Line 2583, Address: 0x287404, Func Offset: 0x154
	// Line 2585, Address: 0x287410, Func Offset: 0x160
	// Line 2584, Address: 0x287414, Func Offset: 0x164
	// Line 2586, Address: 0x287418, Func Offset: 0x168
	// Line 2589, Address: 0x287420, Func Offset: 0x170
	// Line 2588, Address: 0x287424, Func Offset: 0x174
	// Line 2590, Address: 0x287428, Func Offset: 0x178
	// Line 2588, Address: 0x28742c, Func Offset: 0x17c
	// Line 2590, Address: 0x287430, Func Offset: 0x180
	// Line 2591, Address: 0x28743c, Func Offset: 0x18c
	// Line 2593, Address: 0x287448, Func Offset: 0x198
	// Line 2594, Address: 0x287458, Func Offset: 0x1a8
	// Line 2595, Address: 0x287468, Func Offset: 0x1b8
	// Line 2596, Address: 0x28746c, Func Offset: 0x1bc
	// Line 2597, Address: 0x287470, Func Offset: 0x1c0
	// Line 2598, Address: 0x28747c, Func Offset: 0x1cc
	// Line 2599, Address: 0x287480, Func Offset: 0x1d0
	// Line 2600, Address: 0x287484, Func Offset: 0x1d4
	// Line 2602, Address: 0x287488, Func Offset: 0x1d8
	// Line 2601, Address: 0x28748c, Func Offset: 0x1dc
	// Line 2602, Address: 0x287490, Func Offset: 0x1e0
	// Line 2603, Address: 0x287498, Func Offset: 0x1e8
	// Line 2604, Address: 0x2874a4, Func Offset: 0x1f4
	// Line 2605, Address: 0x2874b0, Func Offset: 0x200
	// Line 2607, Address: 0x2874b4, Func Offset: 0x204
	// Line 2610, Address: 0x2874c0, Func Offset: 0x210
	// Line 2608, Address: 0x2874c4, Func Offset: 0x214
	// Line 2630, Address: 0x2874cc, Func Offset: 0x21c
	// Line 2631, Address: 0x2874d0, Func Offset: 0x220
	// Line 2634, Address: 0x2874d4, Func Offset: 0x224
	// Line 2610, Address: 0x2874d8, Func Offset: 0x228
	// Line 2611, Address: 0x2874f4, Func Offset: 0x244
	// Line 2610, Address: 0x2874f8, Func Offset: 0x248
	// Line 2611, Address: 0x2874fc, Func Offset: 0x24c
	// Line 2620, Address: 0x287500, Func Offset: 0x250
	// Line 2611, Address: 0x287508, Func Offset: 0x258
	// Line 2608, Address: 0x28750c, Func Offset: 0x25c
	// Line 2620, Address: 0x287510, Func Offset: 0x260
	// Line 2608, Address: 0x287514, Func Offset: 0x264
	// Line 2620, Address: 0x287518, Func Offset: 0x268
	// Line 2608, Address: 0x28751c, Func Offset: 0x26c
	// Line 2620, Address: 0x287524, Func Offset: 0x274
	// Line 2611, Address: 0x287528, Func Offset: 0x278
	// Line 2620, Address: 0x28752c, Func Offset: 0x27c
	// Line 2621, Address: 0x287548, Func Offset: 0x298
	// Line 2622, Address: 0x28755c, Func Offset: 0x2ac
	// Line 2623, Address: 0x287570, Func Offset: 0x2c0
	// Line 2626, Address: 0x287574, Func Offset: 0x2c4
	// Line 2623, Address: 0x287578, Func Offset: 0x2c8
	// Line 2624, Address: 0x287580, Func Offset: 0x2d0
	// Line 2625, Address: 0x287584, Func Offset: 0x2d4
	// Line 2626, Address: 0x287588, Func Offset: 0x2d8
	// Line 2627, Address: 0x28758c, Func Offset: 0x2dc
	// Line 2628, Address: 0x287594, Func Offset: 0x2e4
	// Line 2632, Address: 0x28759c, Func Offset: 0x2ec
	// Line 2633, Address: 0x2875a4, Func Offset: 0x2f4
	// Line 2637, Address: 0x2875a8, Func Offset: 0x2f8
	// Line 2639, Address: 0x2875b4, Func Offset: 0x304
	// Line 2637, Address: 0x2875b8, Func Offset: 0x308
	// Line 2639, Address: 0x2875cc, Func Offset: 0x31c
	// Line 2640, Address: 0x2875d4, Func Offset: 0x324
	// Line 2641, Address: 0x2875e4, Func Offset: 0x334
	// Line 2642, Address: 0x2875f4, Func Offset: 0x344
	// Line 2644, Address: 0x287604, Func Offset: 0x354
	// Line 2643, Address: 0x28760c, Func Offset: 0x35c
	// Line 2644, Address: 0x287610, Func Offset: 0x360
	// Line 2646, Address: 0x287618, Func Offset: 0x368
	// Line 2648, Address: 0x287620, Func Offset: 0x370
	// Line 2651, Address: 0x287624, Func Offset: 0x374
	// Line 2652, Address: 0x287630, Func Offset: 0x380
	// Line 2648, Address: 0x287634, Func Offset: 0x384
	// Line 2650, Address: 0x28763c, Func Offset: 0x38c
	// Line 2652, Address: 0x287644, Func Offset: 0x394
	// Line 2650, Address: 0x287648, Func Offset: 0x398
	// Line 2651, Address: 0x28764c, Func Offset: 0x39c
	// Line 2650, Address: 0x287650, Func Offset: 0x3a0
	// Line 2652, Address: 0x287654, Func Offset: 0x3a4
	// Line 2653, Address: 0x287668, Func Offset: 0x3b8
	// Line 2654, Address: 0x287690, Func Offset: 0x3e0
	// Line 2656, Address: 0x2876a4, Func Offset: 0x3f4
	// Line 2660, Address: 0x2876b0, Func Offset: 0x400
	// Line 2659, Address: 0x2876b4, Func Offset: 0x404
	// Line 2660, Address: 0x2876b8, Func Offset: 0x408
	// Line 2661, Address: 0x2876bc, Func Offset: 0x40c
	// Line 2660, Address: 0x2876c0, Func Offset: 0x410
	// Line 2661, Address: 0x2876c4, Func Offset: 0x414
	// Line 2662, Address: 0x2876c8, Func Offset: 0x418
	// Line 2663, Address: 0x2876e0, Func Offset: 0x430
	// Line 2664, Address: 0x2876e8, Func Offset: 0x438
	// Line 2663, Address: 0x2876ec, Func Offset: 0x43c
	// Line 2664, Address: 0x2876f4, Func Offset: 0x444
	// Line 2665, Address: 0x287708, Func Offset: 0x458
	// Line 2666, Address: 0x28771c, Func Offset: 0x46c
	// Line 2667, Address: 0x287730, Func Offset: 0x480
	// Line 2668, Address: 0x28774c, Func Offset: 0x49c
	// Line 2669, Address: 0x287750, Func Offset: 0x4a0
	// Line 2670, Address: 0x28775c, Func Offset: 0x4ac
	// Line 2671, Address: 0x287764, Func Offset: 0x4b4
	// Line 2670, Address: 0x287768, Func Offset: 0x4b8
	// Line 2671, Address: 0x287770, Func Offset: 0x4c0
	// Line 2673, Address: 0x287780, Func Offset: 0x4d0
	// Line 2677, Address: 0x287794, Func Offset: 0x4e4
	// Line 2673, Address: 0x287798, Func Offset: 0x4e8
	// Line 2678, Address: 0x28779c, Func Offset: 0x4ec
	// Line 2679, Address: 0x2877a0, Func Offset: 0x4f0
	// Line 2673, Address: 0x2877a4, Func Offset: 0x4f4
	// Line 2674, Address: 0x2877b0, Func Offset: 0x500
	// Line 2675, Address: 0x2877c8, Func Offset: 0x518
	// Line 2676, Address: 0x2877e0, Func Offset: 0x530
	// Line 2677, Address: 0x2877ec, Func Offset: 0x53c
	// Line 2678, Address: 0x2877f8, Func Offset: 0x548
	// Line 2679, Address: 0x287800, Func Offset: 0x550
	// Line 2680, Address: 0x287824, Func Offset: 0x574
	// Line 2681, Address: 0x28782c, Func Offset: 0x57c
	// Line 2682, Address: 0x287844, Func Offset: 0x594
	// Line 2683, Address: 0x287850, Func Offset: 0x5a0
	// Line 2684, Address: 0x28785c, Func Offset: 0x5ac
	// Line 2685, Address: 0x287868, Func Offset: 0x5b8
	// Line 2686, Address: 0x287874, Func Offset: 0x5c4
	// Line 2690, Address: 0x287880, Func Offset: 0x5d0
	// Line 2689, Address: 0x287884, Func Offset: 0x5d4
	// Line 2690, Address: 0x287888, Func Offset: 0x5d8
	// Line 2691, Address: 0x287890, Func Offset: 0x5e0
	// Line 2692, Address: 0x28789c, Func Offset: 0x5ec
	// Line 2693, Address: 0x2878b4, Func Offset: 0x604
	// Line 2698, Address: 0x2878c4, Func Offset: 0x614
	// Line 2699, Address: 0x2878d4, Func Offset: 0x624
	// Line 2700, Address: 0x2878e8, Func Offset: 0x638
	// Line 2701, Address: 0x2878fc, Func Offset: 0x64c
	// Line 2702, Address: 0x287910, Func Offset: 0x660
	// Line 2703, Address: 0x287930, Func Offset: 0x680
	// Line 2704, Address: 0x287934, Func Offset: 0x684
	// Line 2705, Address: 0x287940, Func Offset: 0x690
	// Line 2706, Address: 0x287954, Func Offset: 0x6a4
	// Line 2705, Address: 0x287958, Func Offset: 0x6a8
	// Line 2706, Address: 0x287964, Func Offset: 0x6b4
	// Line 2708, Address: 0x287978, Func Offset: 0x6c8
	// Line 2711, Address: 0x28797c, Func Offset: 0x6cc
	// Line 2708, Address: 0x287980, Func Offset: 0x6d0
	// Line 2709, Address: 0x287988, Func Offset: 0x6d8
	// Line 2710, Address: 0x287994, Func Offset: 0x6e4
	// Line 2711, Address: 0x28799c, Func Offset: 0x6ec
	// Line 2712, Address: 0x2879c0, Func Offset: 0x710
	// Line 2713, Address: 0x2879c8, Func Offset: 0x718
	// Line 2714, Address: 0x2879e0, Func Offset: 0x730
	// Line 2715, Address: 0x2879ec, Func Offset: 0x73c
	// Line 2716, Address: 0x2879f8, Func Offset: 0x748
	// Line 2717, Address: 0x287a04, Func Offset: 0x754
	// Line 2718, Address: 0x287a10, Func Offset: 0x760
	// Line 2719, Address: 0x287a1c, Func Offset: 0x76c
	// Line 2721, Address: 0x287a20, Func Offset: 0x770
	// Line 2722, Address: 0x287a2c, Func Offset: 0x77c
	// Line 2723, Address: 0x287a3c, Func Offset: 0x78c
	// Line 2724, Address: 0x287a4c, Func Offset: 0x79c
	// Line 2726, Address: 0x287a5c, Func Offset: 0x7ac
	// Line 2727, Address: 0x287a94, Func Offset: 0x7e4
	// Line 2726, Address: 0x287a98, Func Offset: 0x7e8
	// Line 2728, Address: 0x287a9c, Func Offset: 0x7ec
	// Line 2727, Address: 0x287aa0, Func Offset: 0x7f0
	// Line 2731, Address: 0x287aa8, Func Offset: 0x7f8
	// Line 2728, Address: 0x287abc, Func Offset: 0x80c
	// Line 2731, Address: 0x287ac8, Func Offset: 0x818
	// Line 2732, Address: 0x287ae0, Func Offset: 0x830
	// Line 2731, Address: 0x287ae4, Func Offset: 0x834
	// Line 2733, Address: 0x287aec, Func Offset: 0x83c
	// Line 2740, Address: 0x287af0, Func Offset: 0x840
	// Line 2732, Address: 0x287af4, Func Offset: 0x844
	// Line 2740, Address: 0x287afc, Func Offset: 0x84c
	// Line 2733, Address: 0x287b00, Func Offset: 0x850
	// Line 2740, Address: 0x287b04, Func Offset: 0x854
	// Line 2741, Address: 0x287b0c, Func Offset: 0x85c
	// Line 2733, Address: 0x287b10, Func Offset: 0x860
	// Line 2735, Address: 0x287b18, Func Offset: 0x868
	// Line 2736, Address: 0x287b1c, Func Offset: 0x86c
	// Line 2741, Address: 0x287b20, Func Offset: 0x870
	// Line 2737, Address: 0x287b24, Func Offset: 0x874
	// Line 2741, Address: 0x287b28, Func Offset: 0x878
	// Line 2740, Address: 0x287b30, Func Offset: 0x880
	// Line 2738, Address: 0x287b34, Func Offset: 0x884
	// Line 2739, Address: 0x287b38, Func Offset: 0x888
	// Line 2740, Address: 0x287b3c, Func Offset: 0x88c
	// Line 2741, Address: 0x287b40, Func Offset: 0x890
	// Line 2740, Address: 0x287b44, Func Offset: 0x894
	// Line 2741, Address: 0x287b48, Func Offset: 0x898
	// Line 2742, Address: 0x287b50, Func Offset: 0x8a0
	// Line 2747, Address: 0x287b60, Func Offset: 0x8b0
	// Func End, Address: 0x287b9c, Func Offset: 0x8ec
	scePrintf("bhObjClpn - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhObjWssg()
{

}
