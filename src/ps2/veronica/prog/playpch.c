#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/playpch.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/weapon.h"

// 100% matching! 
void PlyPchInit(BH_PWORK* ewP)
{
    ewP->exp2 = bhGetFreeMemory(1712, 32);
}

// 100% matching!
void PlyPchMain(BH_PWORK* ewP) 
{
    PP_WORK* ppP;               
    ML_WORK* mlwP;            
    NJS_CNK_OBJECT* objP;       
    int dir;                     
    int* atP, *dstP;               
    static const char RouteArmRn_0[5] = { 1, 2, 6, 7, 0xFF }, RouteArmLn_0[5] = { 1, 2, 10, 11, 0xFF }; 
    
    ppP = (PP_WORK*)ewP->exp2;
    
    if ((WpnTab[plp->wpnr_no].flg & 0x800)) 
    {
        if ((plp->mode0 == 1) && (plp->mode1 != 0)) 
        {
            mlwP = plp->mlwP;
            
            if (plp->mode2 == 164) 
            {
                if (!(ppP->mode & 0x1)) 
                {
                    objP = mlwP->objP;
                    
                    *(NJS_POINT3*)&ppP->obj_l.ang[0] = *(NJS_POINT3*)&objP[11].ang[0];
                    *(NJS_POINT3*)&ppP->obj_r.ang[0] = *(NJS_POINT3*)&objP[7].ang[0];
                    
                    ppP->mode |= 0x1;
                    
                    EXP1_I(0) &= ~0x1E4;
                    
                    mlwP->owP[5].flg |= 0x2;
                    mlwP->owP[4].flg |= 0x2;
                    
                    if ((ppP->mode & 0x8)) 
                    {
                        ppP->hed_rate = 0;
                    } 
                    else 
                    {
                        ppP->hed_rate = 65536;
                    }
                }
                
                ppP->mode &= ~0x4;
                
                ppP->gun_delay = -1;
            } 
            else if ((plp->mode2 == 68) && (!(ppP->mode & 0x2)))
            {
                ppP->arm_dl = ppP->arm_dr = 0;
                
                ppP->mode |= 0x2;
                
                ppP->count = 12;
                
                EXP1_I(0) &= ~0x8;
            }
            
            mlwP->owP[7].flg  |= 0x2;
            mlwP->owP[11].flg |= 0x2;
            
            GetOneObjectMotion(ewP, 7, ppP->ang_tmp); 
            SetOneObjectMotion(ewP, &ppP->obj_r, ppP->ang_tmp);
            
            GetOneObjectMotion(ewP, 11, ppP->ang_tmp);
            SetOneObjectMotion(ewP, &ppP->obj_l, ppP->ang_tmp);
            
            if (ppP->count != 0)
            {
                ppP->arm_al += (short)(ppP->arm_dl - ppP->arm_al) / ppP->count;
                ppP->arm_ar += (short)(ppP->arm_dr - ppP->arm_ar) / ppP->count;
                
                ppP->count--;
            }
            
            MixSetToJointRot(mlwP->objP, (char*)RouteArmRn_0, &ppP->obj_r, ppP->arm_ar);
            MixSetToJointRot(mlwP->objP, (char*)RouteArmLn_0, &ppP->obj_l, ppP->arm_al);
            
            if ((sys->pad_on & 0x8))
            {
                ppP->hed_rate += 3276;
            }
            
            if ((sys->pad_on & 0x4))
            {
                ppP->hed_rate -= 3276;
            }
            
            if (ppP->hed_rate > 65536)
            {
                ppP->hed_rate = 65536;
            } 
            else if (ppP->hed_rate < 0) 
            {
                ppP->hed_rate = 0;
            }
            
            dir = (ppP->arm_dl + ((ppP->hed_rate * (ppP->arm_dr - ppP->arm_dl)) / 65536)) / 2;
            
            atP  = ppP->ang_tmp;
            dstP = plp->mlwP->objP[5].ang;
            
            GetOneObjectMotion(plp, 5, atP);
            
            dstP[0] += (short)(atP[0] - dstP[0]) / 4;
            dstP[1] += (short)(dir - dstP[1])    / 4;
            dstP[2] = atP[2];
            
            dstP = plp->mlwP->objP[4].ang;
            
            GetOneObjectMotion(plp, 4, atP);
            
            dstP[0] += (short)(atP[0] - dstP[0]) / 4;
            dstP[1] += (short)(dir - dstP[1])    / 4; 
            dstP[2] = atP[2]; 
        }
        else 
        { 
            plp->mlwP->owP[7].flg  &= ~0x2;
            plp->mlwP->owP[11].flg &= ~0x2;
            plp->mlwP->owP[5].flg  &= ~0x2;
            plp->mlwP->owP[4].flg  &= ~0x2;
            
            ppP->arm_dl = ppP->arm_dr = 0;
            ppP->arm_al = ppP->arm_ar = 0;
            
            ppP->mode = 0;
        }
    }
}

// 100% matching!
static void MixSetToJointRot(NJS_CNK_OBJECT* basP, char* rutP, NJS_CNK_OBJECT* objP, int yaw)
{
    NJS_MATRIX* mtx0P, *mtx1P;    
    NJS_CNK_OBJECT* tmpP; 
    
    mtx0P = &lcmat[0];
    mtx1P = &lcmat[1];

    njUnitMatrix(mtx0P);
    
    while (rutP[1] != -1) 
    {
        tmpP = &basP[rutP[0]];
        
        rutP++;
        
        njRotateXYZ(mtx0P, tmpP->ang[0], tmpP->ang[1], tmpP->ang[2]);
    }
    
    njSetMatrix(mtx1P, mtx0P);
    
    njRotateXYZ(mtx1P, objP->ang[0], objP->ang[1], objP->ang[2]);
    njInvertMatrix(mtx0P);
    
    njRotateY(mtx0P, yaw);
    njMultiMatrix(mtx0P, mtx1P); 
    
    basP = &basP[rutP[0]];
    
    basP->ang[0] = (int)(10430.381f * atan2f(mtx0P[0][6], mtx0P[0][10]));
    basP->ang[1] = (int)(10430.381f * asinf(-mtx0P[0][2]));
    basP->ang[2] = (int)(10430.381f * atan2f(mtx0P[0][1], mtx0P[0][0]));
}

// 100% matching!
static void GetOneObjectMotion(BH_PWORK* ewP, int obj_no, int* ang) 
{
    int flp;             
    char* rutP;          
    NJS_MKEY_A_MOD* mkaP; 
    static const char NormalTbl[64] = 
	{
		0,  1,  2,  3,  4,  5,  6,  7,
		8,  9, 10, 11, 12, 13, 14, 15,
		16, 17, 18, 19, 20, 21, 22, 23,
		24, 25, 26, 27, 28, 29, 30, 31,
		32, 33, 34, 35, 36, 37, 38, 39,
		40, 41, 42, 43, 44, 45, 46, 47,
		48, 49, 50, 51, 52, 53, 54, 55,
		56, 57, 58, 59, 60, 61, 62, 63
	};

    if ((ewP->mtn_md & 0x2))
    {
        rutP = (char*)ewP->mtn_tp;
        
        flp = -1;
    }
    else
    {
        rutP = NormalTbl;
        
        flp = 1;
    }
    
    if (ewP->mnwP[ewP->mtn_no].md2P[rutP[obj_no]].p[1] != NULL)
    { 
        mkaP =  ewP->mnwP[ewP->mtn_no].md2P[rutP[obj_no]].p[1]; 
        mkaP += ewP->frm_no / 65536;
        
        ang[0] = mkaP->key[0];
        ang[1] = (mkaP->key[1] * flp); 
        ang[2] = (mkaP->key[2] * flp);
    } 
    else 
    {
        ang[0] = ang[1] = ang[2] = 0;
    }
}

// 100% matching!
static void SetOneObjectMotion(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, int* ang) 
{
    int* srcP;  
    float rate;
    short dlt;   
    int sum1;    
    static int tmpS[3], tmpD[3]; 
    
    if (ewP->hokan_count != 0) 
    {
        srcP = objP->ang;
        
        dlt = ang[0] - srcP[0];
        
        if (dlt < 0)
        {
            sum1 = -(dlt + (short)(dlt + 32768));
        } 
        else 
        {
            sum1 =   dlt + (short)(dlt + 32768);
        }
        
        dlt = ang[1] - srcP[1];
        
        if (dlt < 0)
        {
            sum1 -= dlt;
        } 
        else 
        {
            sum1 += dlt;
        }
        
        dlt = ang[1] - (32768 - srcP[1]);
        
        if (dlt < 0)
        {
            sum1 += dlt;
        }
        else 
        {
            sum1 -= dlt;
        }
        
        dlt = ang[2] - srcP[2];
        
        if (dlt < 0) 
        {
            sum1 -= dlt + (short)(dlt + 32768);
        } 
        else 
        {
            sum1 += dlt + (short)(dlt + 32768);
        }
        
        if (sum1 > 0) 
        {
            int* srcP;
            
            srcP = objP->ang;
            
            *srcP = 32768 + *srcP++;
            *srcP = 32768 - *srcP;
            *srcP = 32768 + *++srcP;
        }
        
        AngZyxToYzx(objP->ang, tmpS);
        AngZyxToYzx(ang,       tmpD);
        
        rate = 0.000015258789f * (65536 - ewP->hokan_rate);
        
        tmpS[0] += (int)(rate * (short)(tmpD[0] - tmpS[0]));
        tmpS[1] += (int)(rate * (short)(tmpD[1] - tmpS[1]));
        tmpS[2] += (int)(rate * (short)(tmpD[2] - tmpS[2]));
        
        AngYzxToZyx(tmpS, objP->ang);
    }
    else 
    {
        objP->ang[0] = ang[0];
        objP->ang[1] = ang[1];
        objP->ang[2] = ang[2];
    }
}

// 100% matching!
static search* bhSearchEnemy(BH_PWORK* pwP, int rng, float hgt)
{
    search* hedP, *lstP, *scnP, *prvP;    
    NJS_VECTOR vct0, vct1;
    BH_PWORK* ewP;  
    float p_cs;    
    float dst;       
    int i;          
    NJS_CAPSULE cap; 
    PP_WORK* ppP; // not from DWARF

    ppP = (PP_WORK*)pwP->exp2;
    
    ppP->sch_hed.nextP = NULL;
    ppP->sch_hed.dst   = 0;
    
    lstP = ppP->SchLst;
    hedP = &ppP->sch_hed;
    
    ppP->sch_hed.dir = 0;
    
    p_cs = njCos(rng); 
    
    njSinCos((pwP->ay + 32768), &vct0.x, &vct0.z);
    
    ewP = ene;
    
    vct0.y = 0;
    
    for (i = 0; i < sys->ewk_n; i++, ewP++)
    {
        if (((((ewP->flg & 0x1)) && ((ewP->flg & 0x20))) && ((!(ewP->flg2 & 0x10)) && (!(ewP->flg & 0x2))) && (!(ewP->stflg & 0x41000000))) && ((!(ewP->flg & 0x80)) || (!(((O_WRK*)ewP->lkwkp)->stflg & 0x1000000)))) 
        {
            vct1.x = 0.5f * (ewP->watr.c1.x + ewP->watr.c2.x);
            vct1.y = 0.5f * (ewP->watr.c1.y + ewP->watr.c2.y);
            vct1.z = 0.5f * (ewP->watr.c1.z + ewP->watr.c2.z);
            
            njSubVector(&vct1, (NJS_VECTOR*)&pwP->px);
            
            dst = njScalor(&vct1);
            
            if ((p_cs * dst) <= njInnerProduct(&vct0, &vct1)) 
            {
                cap.c1.x = cap.c2.x = pwP->px;
                cap.c1.y = cap.c2.y = pwP->py;
                cap.c1.z = cap.c2.z = pwP->pz;
                
                cap.c1.y += hgt;
                
                njAddVector(&cap.c2, &vct1);
                
                cap.r = 0.1f;
                
                if (bhCheckC2WallN(&cap, 0x40000400) == 0)  
                {
                    lstP->dir = (int)(10430.381f * atan2f(vct1.x, vct1.z)) + 32768;
                    lstP->dst = dst;                    
                    lstP->ewP = ewP;
                    lstP->idx = i;
                    
                    prvP = hedP; 
                    
                    for (scnP = hedP->nextP; scnP != NULL; scnP = scnP->nextP) 
                    {
                        if (scnP->dst >= dst) 
                        {
                            break;
                        }
                        
                        prvP = scnP;
                    }
                    
                    lstP->nextP = prvP->nextP;
                    prvP->nextP = lstP++;
                }
            }
        }
    }
    
    return hedP->nextP; 
}

// 99.92% matching
static int SetLockOnDirection(int range, int count, int mode, int special) 
{
    PP_WORK* ppP; 
    search* topP, *lstP /* needs use */, *tgtP; 
    BH_PWORK* pwP; // not from DWARF 
    
    pwP = plp; 
    ppP = (PP_WORK*)pwP->exp2;
    
    if (mode == 0) 
    {
        ppP->endPP = ppP->LckTbl;
    }
    
    ppP->count = count;
    
    topP = bhSearchEnemy(pwP, range, pwP->mlwP[pwP->mdl_no].owP[5].mtx[13] - pwP->py);
    
    if (topP != NULL)
    {
        ppP->endPP = ppP->LckTbl;
        
        tgtP = topP;
        
        pwP->ayp = topP->dir;
        
        ppP->arm_dl = ppP->arm_dr = 0;
        
        if (special != 0) 
        {
            ppP->mode |= 0x4;
        }
        
        ppP->mode &= ~0x8;
        
        if (!(ppP->mode & 0x10))
        {
            while ((tgtP = tgtP->nextP) != NULL) 
            {
                if (((short)(tgtP->dir - topP->dir) >= -16384) && ((short)(tgtP->dir - topP->dir) <= 16384)) 
                {
                    pwP->ayp = pwP->ay + (((short)(((((short)(tgtP->dir - topP->dir) * 32768) / 65536) + topP->dir) - pwP->ay) * 57344) / 65536);
                    
                    if ((short)(tgtP->dir - topP->dir) > 0) 
                    {
                        ppP->arm_dl = (short)(tgtP->dir - pwP->ayp); 
                        ppP->arm_dr = (short)(topP->dir - pwP->ayp);
                    } 
                    else
                    {
                        ppP->arm_dl = (short)(topP->dir - pwP->ayp);
                        ppP->arm_dr = (short)(tgtP->dir - pwP->ayp);
                        
                        ppP->mode |= 0x8;
                    }
                    
                    break;
                }
            } 
        } 
        else 
        {
            tgtP = topP->nextP;
        }
        
        ppP->mode ^= 0x10;
        
        if (tgtP != NULL)
        {
            ppP->mode &= ~0x4;
        }
        
        *ppP->endPP++ = topP->ewP;
    }
    
    return (int)topP;
}

// 100% matching!
void bhCPM2_act_suw_pch()
{
    search* lstP;

    switch (plp->mode3)
    {
    case 0:
        if (SetLockOnDirection(32768, 8, 0, 0) != 0) 
        {
            plp->flg |= 0x100000;
            
            ((EXP_WORK*)plp->exp0)->yrct = 8;
        }
        
        plp->flg    &= ~0xC0000;
        plp->at_flg &= ~0x10;
        
        plp->mtn_no = PlMtnWpn[0];
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 2.0f;
        
        plp->frm_no = 0;
        
        if (!bhCheckBullet()) 
        {
            sys->gm_flg |= 0x40000;
        }
        
        plp->mode3++;
    case 1:
        if (plp->hokan_count == 0) 
        {
            plp->flg |= 0xC0000;
            
            if ((WpnTab[plp->wpnr_no].flg & 0x4000000)) 
            {
                plp->flg &= ~0x80000;
            }
        }
        else 
        {
            plp->flg |= 0x200000;
        }
        
        if (((unsigned int)plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 4)) 
        {
            plp->at_flg &= ~0x1;
        }
        
        if ((plp->mnwP[plp->mtn_no].frm_num - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->mtn_add = 0;
        
            plp->mode2 = 65;
            plp->mode3 = 0;
            
            plp->at_flg = 2;
            
            plp->hokan_count = 8;
            
            plp->wax  = 0;
            plp->waxp = 0;
            return;
        } 
        else 
        {
            if (!(WpnTab[plp->wpnr_no].flg & 0x1)) 
            {
                if (((sys->pad_on & 0x20)) && (!(plp->at_flg & 0x1))) 
                {
                    plp->mode2 = 66;
                    plp->mode3 = 0;
                    
                    plp->at_flg = 4;
                    
                    plp->hokan_count = 8;
                    
                    plp->wax  = 0;
                    plp->waxp = 8192;
                    return;
                }
                
                if (((sys->pad_on & 0x40)) && (!(plp->at_flg & 0x1))) 
                {
                    plp->mode2 = 67;
                    plp->mode3 = 0;
                    
                    plp->at_flg = 0x8;
                    
                    plp->hokan_count = 8;
                    
                    plp->wax  = 0;
                    plp->waxp = -8192;
                    return;
                }
            }
        }
    }
    
    if ((sys->pad_on & 0x8))
    {
        plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
    }
    
    if ((sys->pad_on & 0x4)) 
    {
        plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
    }
}

// 100% matching!
void bhCPM2_act_wsc_pch()
{

}

// 100% matching!
void bhCPM2_act_atk_pch()
{
    PP_WORK* ppP;   
    const WPN_TAB* wt;   
    EF_WORK* wet;  
    search* lstP; // needs use   
  
    ppP = (PP_WORK*)plp->exp2;
    
    wt  = &WpnTab[plp->wpnr_no];
    wet = WpnEffTab[plp->wpnr_no]; 

    if ((!(wt->flg & 0x40)) || (((wt->flg & 0x200)) && (bhCkFlg(sys->ev_flg, 74) != 0))) 
    {
        switch (plp->mode3)
        {
        case 0:
        {
            GA_WORK* gaP;   
            
            plp->flg |= 0xC0000;
            
            if ((wt->flg & 0x8000000)) 
            {
                plp->flg &= ~0x80000;
            } 
            
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->mtn_no = PlMtnWpn[4];
                break;
            case 4:
                plp->mtn_no = PlMtnWpn[4] + 5;
                break;
            case 8:
                plp->mtn_no = PlMtnWpn[4] + 10;
                break;
            }
            
            plp->hokan_rate = 65536.0f * wt->hrate; 
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3++; 

            ppP->gun_delay = 2;

            if ((wt->flg & 0x2))
            {
                sys->obwp->flg |= 0x80000;
                
                sys->obwp->mode0 = 0;
            }

            gaP = CheckGunHit(wt, 9, ((PP_WORK*)plp->exp2)->arm_dr + plp->ay);
            
            bhCountBullet(); 
            
            if (wt->seno0 != 0) 
            {
                CallPlayerWeaponSeEx((NJS_POINT3*)&gaP->px, (unsigned int)wt->seno0, 0);
                
                if (!(wt->flg & 0x100))
                { 
                    plp->stflg |= 0x100;
                }
            }
        }
        case 1:
            if (((plp->frm_no / 65536) == (wt->ef_yct - 2)) && (plp->wpnr_no == 11))
            {
                CallPlayerWeaponSeEx((NJS_POINT3*)&plp->mlwP->owP[9].mtx[12], wt->seno1, 0);
            } 

            if (((plp->frm_no / 65536) == wt->ef_yct) && (wet[3].flg != 0))  
            {
                bhSetYakkyou(plp, plp->wpnr_no, 9, 0, ppP->arm_dr + plp->ay);
            } 
            
            if (((((plp->at_flg & 0x10)) && (!(plp->at_flg & 0x40))) && (((sys->pad_on & 0x100)) && ((sys->pad_on & 0x10)))) || ((plp->mnwP[plp->mtn_no].frm_num - 1) <= (plp->frm_no / 65536)))
            { 
                if ((wt->flg & 0x400))
                {
                    plp->mode2 = 70;
                    plp->mode3 = 0;
                    return;
                }
                
                switch (plp->at_flg & 0xE)
                {
                case 2:
                    plp->mode2 = 65;
                    break;
                case 4:
                    plp->mode2 = 66;
                    break;
                case 8:
                    plp->mode2 = 67;
                    break;
                }
                
                plp->hokan_count = 1;
                
                switch (((wt->flg & 0x1)) ? sys->pad_on & 0x10 : sys->pad_on & 0x70)
                {
                case 0x10:
                    if (!(plp->at_flg & 0x2)) 
                    {
                        plp->hokan_count = 12;
                    }
                    
                    break;
                case 0x30:
                    if (!(plp->at_flg & 0x4)) 
                    {
                        plp->hokan_count = 12;
                    }
                    
                    break;
                case 0x50:
                    if (!(plp->at_flg & 0x8)) 
                    {
                        plp->hokan_count = 12;
                    }

                    break;
                }
                
                plp->mode3 = 0;
                return;
            }
            
            if ((plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - wt->at_cct)) 
            {
                plp->at_flg |= 0x10;
            }
            
            if (!(sys->pad_on & 0x100)) 
            {
                plp->at_flg &= ~0x40;
            }
        default:
            plp->wax += (plp->waxp - plp->wax) / 4;
            
            if ((sys->pad_on & 0x8)) 
            {
                plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
            }
            
            if ((sys->pad_on & 0x4)) 
            {
                plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
            }
        }
    } 
    else 
    {
        if ((plp->ct0 >= wt->fend_ct) && (plp->mode3 == 2)) 
        {
            plp->mode3 = 1;
            
            plp->ct0 = 0;
            plp->ct1++;
        } 
        else 
        {
            plp->ct0++;
        }
        
        switch (plp->mode3) 
        {
        case 0:
            plp->flg |= 0xC0000;
            
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->mtn_no = PlMtnWpn[4];
                
                if ((((PP_WORK*)plp->exp2)->mode & 0x4)) 
                { 
                    plp->mtn_no += 17;
                } 
                
                break;
            case 4:
                plp->mtn_no = PlMtnWpn[4] + 5;
                break;
            case 8:
                plp->mtn_no = PlMtnWpn[4] + 10;
                break;
            }
            
            plp->hokan_rate = 65536.0f * wt->hrate;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->ct0 = plp->ct1 = 0;
            
            plp->mode3 = 1;
        case 1:
        {
            GA_WORK* gaP; 
                
            bhSetGunFire(plp, plp->wpnr_no, 9, 0, ppP->arm_dr + plp->ay);

            ppP->gun_delay = 2; 
            
            if ((wt->flg & 0x2)) 
            {
                sys->obwp->flg |= 0x80000;
                
                sys->obwp->mode0 = 0;
            }

            gaP = CheckGunHit(wt, 9, ((PP_WORK*)plp->exp2)->arm_dr + plp->ay);
            
            if (bhCountBullet() == 0)
            {
                sys->gm_flg |= 0x40000;
                
                plp->mode3 = 3;

                plp->at_flg &= ~0x10;
                
                if (!(wt->flg & 0x200)) 
                {
                    switch (plp->at_flg & 0xE)
                    {
                    case 2:
                        plp->mtn_no = 102;
                        break;
                    case 4:
                        plp->mtn_no = 107;
                        break;
                    case 8:
                        plp->mtn_no = 112;
                        break;
                    }
                }
                
                break;
            } 
            
            if (wt->seno0 != 0)
            {
                CallPlayerWeaponSeEx((NJS_POINT3*)&gaP->px, (unsigned short)wt->seno0, 0);
                
                if (!(wt->flg & 0x100)) 
                {
                    plp->stflg |= 0x100;
                }
            }
            
            plp->mode3 = 2;
        }
        case 2:
            if ((plp->ct0 == wt->ef_yct) && (wet[3].flg != 0)) 
            {
                bhSetYakkyou(plp, plp->wpnr_no, 9, 0, ppP->arm_dr + plp->ay);
            } 
            
            if (((!(sys->pad_on & 0x100)) || (!(sys->pad_on & 0x10))) || (((wt->flg & 0x200)) && (plp->ct1 > 1))) 
            {
                plp->mode3 = 3;
                
                plp->ct1 = 0;
                
                if ((wt->flg & 0x200)) 
                {
                    plp->at_flg |= 0x40;
                }
                else 
                {
                    plp->at_flg &= ~0x40;
                    
                    switch (plp->at_flg & 0xE)
                    {
                    case 2:
                        plp->mtn_no = 102;
                        
                        if ((((PP_WORK*)plp->exp2)->mode & 0x4)) 
                        {
                            plp->mtn_no += 17;
                        }
                        
                        break;
                    case 4:
                        plp->mtn_no = 107;
                        break;
                    case 8:
                        plp->mtn_no = 112;
                        break;
                    }
                }
            }

            break;
        case 3:
            if ((plp->ct0 == wt->ef_yct) && (wet[3].flg != 0)) 
            {
                bhSetYakkyou(plp, plp->wpnr_no, 9, 0, ppP->arm_dr + plp->ay);
            }
            
            if (!(sys->pad_on & 0x100)) 
            {
                plp->at_flg &= ~0x40;
            }
            
            plp->at_flg |= 0x10;
            
            if ((plp->flg & 0x400000)) 
            {
                switch (plp->at_flg & 0xE)
                {
                case 2:
                    plp->mode2 = 65;
                    
                    plp->mtn_no = PlMtnWpn[1];
                    
                    plp->waxp = 0;
                    
                    ppP = (PP_WORK*)plp->exp2;
                    
                    if ((ppP->mode & 0x4)) 
                    {
                        plp->mtn_no += 13;
                    }
                    
                    break;
                case 4:
                    plp->mode2 = 66;
                    
                    plp->mtn_no = PlMtnWpn[2];
                    
                    plp->waxp = 8192;
                    break;
                case 8:
                    plp->mode2 = 67;
                    
                    plp->mtn_no = PlMtnWpn[3];
                    
                    plp->waxp = -8192;
                    break;
                }
                
                plp->mode3 = 0;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 0;
                return;
            }
            
            break;
        case 4:
            plp->hokan_count = 12;
            plp->hokan_rate  = 45875;
            
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->mode2 = 65;

                plp->mtn_no = PlMtnWpn[1];
                
                plp->waxp = 0;
                
                ppP = (PP_WORK*)plp->exp2;
                
                if ((ppP->mode & 0x4)) 
                {
                    plp->mtn_no += 13;
                }
                
                break;
            case 4:
                plp->mode2 = 66;
                
                plp->mtn_no = PlMtnWpn[2];
                
                plp->waxp = 8192;
                break;
            case 8:
                plp->mode2 = 67;
                
                plp->mtn_no = PlMtnWpn[3];
                
                plp->waxp = -8192;
                break;
            }
            
            plp->mode3 = 0;
            return;
        }
        
        if ((plp->mode3 >= 3) && (!(sys->gm_flg & 0x40000)) && (((sys->pad_on & 0x100)) && ((sys->pad_on & 0x10))) && (((plp->at_flg & 0x10)) && (!(plp->at_flg & 0x40))))
        {
            plp->mode3 = 0;
            
            plp->hokan_count = 0;
        }
        
        plp->wax += (plp->waxp - plp->wax) / 4;
        
        switch (sys->pad_on & 0x70)
        {
        case 0x10:
            if (!(plp->at_flg & 0x2)) 
            {
                plp->at_flg &= ~0xE;
                plp->at_flg |=  0x2;
                
                plp->mtn_no = PlMtnWpn[4];
    
                plp->hokan_count = 20;
                
                plp->frm_no = 0;
                
                plp->hokan_ctbak = plp->hokan_count;
                
                plp->waxp = 0;
    
                if ((((PP_WORK*)plp->exp2)->mode & 0x4)) 
                {
                    plp->mtn_no += 17;
                }
                
                if (plp->mode3 == 3) 
                {
                    plp->mode3 = 4;
                }
            }
            
            break;
        case 0x30:
            if (!(plp->at_flg & 0x4)) 
            {
                plp->at_flg &= ~0xE;
                plp->at_flg |=  0x4;
                
                plp->mtn_no = PlMtnWpn[4] + 5;
                
                plp->hokan_count = 20;
                
                plp->frm_no = 0;
                
                plp->hokan_ctbak = plp->hokan_count;
                
                plp->waxp = 8192;
                
                if (plp->mode3 == 3) 
                {
                    plp->mode3 = 4;
                }
            }
            
            break;
        case 0x50:
            if (!(plp->at_flg & 0x8)) 
            {
                plp->at_flg &= ~0xE;
                plp->at_flg |=  0x8;
                
                plp->mtn_no = PlMtnWpn[4] + 10;
                
                plp->hokan_count = 20;
                
                plp->frm_no = 0;
                
                plp->hokan_ctbak = plp->hokan_count;
                
                plp->waxp = -8192;
                
                if (plp->mode3 == 3) 
                {
                    plp->mode3 = 4;
                }
            }
    
            break;
        }
            
        if ((sys->pad_on & 0x8)) 
        {
            plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
        }
        
        if ((sys->pad_on & 0x4))
        {
            plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
        }
        
        if (((sys->pad_ps & 0x80)) && (SetLockOnDirection(16384, 6, 1, 0) != 0)) 
        {
            plp->flg |= 0x100000;
            
            ((EXP_WORK*)plp->exp0)->yrct = 4;
        } 
    }

    if (ppP->gun_delay == 0) 
    {
        CheckGunHit(wt, 13, ppP->arm_dl + plp->ay);
        
        bhSetGunFire(plp, plp->wpnr_no, 13, 1, ppP->arm_dl + plp->ay);
        bhSetYakkyou(plp, plp->wpnr_no, 13, 1, ppP->arm_dl + plp->ay);
        
        ppP->gun_delay = -1; 
    }
    else if (ppP->gun_delay > 0) 
    {
        ppP->gun_delay--; 
    }
    if ((plp->at_flg & 0xE) != 0x2) 
    {
        ppP = (PP_WORK*)plp->exp2;
        
        ppP->mode &= ~0x14;
    }
}

// 100% matching!
static GA_WORK* CheckGunHit(const WPN_TAB* wtP, int obj_no, int yaw)
{
    NJS_POINT3 ps;
    static GA_WORK gap;
    
    gap.at_flg = plp->at_flg;
    
    gap.wpn_no = plp->wpnr_no;
    
    gap.r = wtP->r;
    gap.l = wtP->l;
    
    gap.rn = wtP->rn;
    gap.rmax = wtP->rmax;
    
    gap.ax = plp->wax;
    gap.ay = yaw;
    
    plp->way = yaw;
    plp->waz = 0;
    
    ps.x = ps.y = 0;
    ps.z = WpnTab[plp->wpnr_no].wp_fps1.z; 
    
    njCalcPoint(&plp->mlwP->owP[obj_no].mtx, &ps, (NJS_POINT3*)&gap.gx);
    
    *(NJS_POINT3*)&gap.px = *(NJS_POINT3*)&gap.gx;
    gap.py = 11.0f + plp->py;
    
    njUnitRotPortion(NULL);
    
    njRotateXYZ(NULL, plp->wax, yaw, plp->waz);
    
    ps.x = ps.y = 0;
    ps.z = -gap.l;
    
    njCalcVector(NULL, &ps, (NJS_VECTOR*)&gap.vx);
    
    bhCheckGunAtari(&gap);
    
    return &gap;
}

// 100% matching!
void bhCPM2_SearchPch() 
{
    search* lstP; // needs use
    PP_WORK* ppP;
    int special; // not from DWARF

    special = sys->ply_id == 2;
    
    if (special != 0) 
    {
        special = plp->wpnr_no == 8;
    }
    
    if (special != 0)
    {
        special = (plp->at_flg & 0xE) == 2;
    }
    
    if (SetLockOnDirection(16384, 8, 1, special) != 0) 
    {
        plp->flg |= 0x100000;
        
        PEXP0_I(4) = 8;
        
        ppP = (PP_WORK*)plp->exp2;
        
        if ((ppP->mode & 0x8)) 
        {
            ppP->hed_rate = 0;
        } 
        else 
        {
            ppP->hed_rate = 65536;
        }
        
        if (((ppP->mode & 0x4)) && ((plp->at_flg & 0xE) == 2))
        {
            plp->mtn_no = 117;
            
            plp->hokan_count = 8;
            plp->hokan_rate  = 39321;  
        }
    }
}

// 100% matching! 
void bhArmIkMdk(BH_PWORK* ewP, int bas_no, NJS_POINT3* effP, int rot)
{
    int Ta; // needs use               
    float lb1, lb0;           
    float l01;            
    NJS_POINT3* vhP, *vyP, *vb1P, *vtP;      
    NJS_CNK_OBJECT* obj0P, *obj1P; 
    NJS_CNK_OBJECT* basP; // not from DWARF 
    static NJS_POINT3 vu = { 0, 1.0f, 0 };

    vhP =  (NJS_VECTOR*)&lcmat[0][0];
    vyP =  (NJS_VECTOR*)&lcmat[0][4]; 
    vb1P = (NJS_VECTOR*)&lcmat[0][8]; 
    vtP =  (NJS_VECTOR*)&lcmat[0][12]; 
    
    basP = &plp->mlwP->objP[bas_no];
    
    obj0P = &basP[1];
    obj1P = &basP[2];
    
    njPushMatrix(&ewP->mlwP->owP[bas_no].mtx);
    njInvertMatrix(NULL);
    
    njGetMatrix(lcmat);
    
    njCalcPoint(NULL, effP, vb1P);
    
    njSubVector(vb1P, (NJS_VECTOR*)obj0P->pos);
    
    lb1 = njScalor(vb1P);
    
    njUnitVector(vb1P);
    
    l01 =  basP[3].pos[0];
    lb0 = obj1P[0].pos[0]; 
    
    njOuterProduct(&vu, vb1P, vyP);
    njUnitVector(vyP);
    
    njOuterProduct(vb1P, vyP, vhP);
    njUnitVector(vhP);
    
    njRotateZ(lcmat, rot);
    
    njSinCos((int)(10430.381f * acosf(((((lb1 * lb1) + (lb0 * lb0)) - (l01 * l01)) / ((2.0f * lb1) * lb0)))), &vtP->x, &vtP->z);
    
    vtP->x *= lb0;
    vtP->y = 0;
    vtP->z *= lb0;
    
    njCalcVector(lcmat, vtP, vtP);
    njUnitVector(vtP);
    
    njOuterProduct(vtP, vyP, vb1P);
    njUnitVector(vb1P);
    
    obj0P->ang[2] = (int)(10430.381f * atan2f(vtP->y, vtP->x));
    obj0P->ang[1] = (int)(10430.381f * asinf(-vtP->z));
    
    obj0P->ang[0] = (int)(10430.381f * atan2f(vyP->z, vb1P->z));
    obj1P->ang[1] = (int)(10430.381f * acosf((((lb1 * lb1) - (lb0 * lb0)) - (l01 * l01)) / ((2.0f * lb0) * l01)));
    
    njPopMatrixEx();
}
