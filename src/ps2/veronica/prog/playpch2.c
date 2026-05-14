#include "../../../ps2/veronica/prog/playpch2.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/weapon.h"

// 100% matching!
void bhCPM2_act_scp()
{
    NJS_POINT3 ps;   
    GA_WORK gap; 
    short bn;
    NJS_POINT3 pos;   
    EF_WORK* eft;
    NJS_POINT3 fps, fpsb;   
    
    switch (plp->mode3)
    {                              
    case 0:
        plp->flg |= 0xC0000;
        
        plp->mtn_no = PlMtnWpn[1];
        
        plp->hokan_rate = 65536;
        plp->hokan_count = 0;
        
        plp->mtn_add = 0;
        
        plp->frm_no = 0;
        
        ((EXP_WORK*)plp->exp0)->arp = 2.0f;
        
        plp->ct0 = 0;
        
        plp->mode3++;
    case 1:
        sys->pt_flg &= ~0x1;
        
        sys->gm_flg |= 0x80000;
        sys->st_flg |= 0x800000;
        
        if (!(sys->pad_on & 0x100)) 
        {
            ((SYS_WORK*)plp)->itm[95] &= ~0x40;
        }
        
        if ((!(sys->pad_on & 0x10)) && (plp->ct0 > 5)) 
        {
            if (!(sys->gm_flg & 0x1000000))
            {
                sys->gm_flg &= ~0x800C0;
            } 
            else 
            {
                sys->gm_flg &= ~0x80000;
                
                cam.ax = cam.axp = cam.pe_ax = 0;
            }
            
            sys->gm_flg |= 0x800;
            
            plp->mode2 = 0x44;
            plp->mode3 = 0;
            
            plp->at_flg = 0;
            return;
        }
        
        if (plp->ct0 > 5)
        {
            plp->at_flg |= 0x10;
        } 
        else
        {
            plp->ct0++;
        }
        
        bn = bhCheckBullet();
        
        if (((((sys->pad_on & 0x100)) && ((sys->pad_on & 0x10))) && ((!(plp->at_flg & 0x40)) && ((plp->at_flg & 0x10))) && (bn)) || ((((sys->pad_ps & 0x100)) && ((sys->pad_on & 0x10))) && ((!(plp->at_flg & 0x40)) && ((plp->at_flg & 0x10))) && (!bn)))
        {
            if (!bn) 
            {
                if ((bhSearchBullet() != 0) && ((sys->gm_flg & 0x40000)))
                {
                    sys->gm_flg &= ~0x40000;
                    
                    plp->mode2 = 0x46;
                    plp->mode3 = 0;
                    return;
                }
                
                njCalcPoint(&plp->mlwP->owP[9].mtx, (NJS_POINT3*)&WpnTab[plp->wpnr_no].wp_fps1, &pos);
                
                CallPlayerWeaponSeEx(&pos, 260, 0);
            }
            else
            {
                sys->gm_flg &= ~0x40000;
                
                plp->mode3 = 2;
                
                plp->at_flg &= ~0x10;
                plp->at_flg |=  0x40;
                
                ((EXP_WORK*)plp->exp0)->scp_ct = 0;
                return;
            }
        }

        break;
    case 2:
        plp->flg |= 0xC0000;
        
        plp->ct3 = plp->wax;
        
        plp->mode3++;
        
        if (((WpnTab[plp->wpnr_no].flg & 0x20000000)) && (WpnEffTab[plp->wpnr_no][2].flg != 0)) 
        {
            plp->way = plp->ay;
            plp->waz = 0;

            eft = &WpnEffTab[plp->wpnr_no][2];

            switch (plp->wpnr_no) 
            {
            case 18: 
                sys->ef_flg |= 0x2;
                
                eft->px = plp->mlwP->owP[5].mtx[12];
                eft->py = plp->mlwP->owP[5].mtx[13];
                eft->pz = plp->mlwP->owP[5].mtx[14];
                
                njUnitMatrix(NULL);
                
                njRotateXYZ(NULL, plp->wax, plp->way, plp->waz);
                
                fps.x = 0;
                fps.y = 0;
                fps.z = -2.5f;
                
                eft->ax = plp->wax;
                eft->ay = plp->way;
                
                njCalcVector(NULL, &fps, &fpsb);
                
                eft->px += fpsb.x;
                eft->py += fpsb.y;
                eft->pz += fpsb.z;
                
                bhSetEffectTb(eft, &fpsb, NULL, 0);
                
                if (sys->gm_mode == 3) 
                {
                    bhStFlg(sys->ev_flg, 75);
                }
            }
        }
        
        if ((WpnTab[plp->wpnr_no].flg & 0x10000000)) 
        {
            gap.at_flg = plp->at_flg;
            
            gap.wpn_no = plp->wpnr_no;
            
            gap.r = WpnTab[plp->wpnr_no].r;
            gap.l = WpnTab[plp->wpnr_no].l;
            
            gap.rn = WpnTab[plp->wpnr_no].rn;
            gap.rmax = WpnTab[plp->wpnr_no].rmax;
            
            gap.ax = plp->wax;
            gap.ay = plp->ay;
            
            plp->way = plp->ay;
            plp->waz = 0;
            
            njSetMatrix(NULL, &plp->mlwP->owP[5].mtx);
            
            ps.x =  0;
            ps.y =  1.5f;
            ps.z = -1.0f;
            
            njCalcPoint(&plp->mlwP->owP[5].mtx, &ps, (NJS_POINT3*)&gap.px);
            
            gap.gx = gap.px;
            gap.gy = gap.py;
            gap.gz = gap.pz;
            
            njUnitRotPortion(NULL);
            
            njRotateXYZ(NULL, plp->wax, plp->way, plp->waz);
            
            ps.x = 0;
            ps.y = 0;
            ps.z = -gap.l;
            
            njCalcVector(NULL, &ps, (NJS_VECTOR*)&gap.vx);
            
            bhCheckGunAtari(&gap);
            
            bhCountBullet();
        }
        
        if (WpnTab[plp->wpnr_no].vib_tp >= 0)
        {
            StartVibrationEx(0, WpnTab[plp->wpnr_no].vib_tp);
        }
        
        if (WpnTab[plp->wpnr_no].seno0 != 0)
        {
            CallPlayerWeaponSeEx((NJS_POINT3*)&plp->mlwP->owP[9].mtx[12], (unsigned short)WpnTab[plp->wpnr_no].seno0, 0);
            
            plp->stflg |= 0x100;
        }
    case 3:
        if ((((EXP_WORK*)plp->exp0)->scp_ct == WpnTab[plp->wpnr_no].ef_yct) && (WpnEffTab[plp->wpnr_no][3].flg != 0)) 
        {
            bhSetYakkyou(plp, plp->wpnr_no, 9, 0, plp->ay);
        }
        
        if (((EXP_WORK*)plp->exp0)->scp_ct >= 30) 
        {
            plp->at_flg |= 0x10;
            
            plp->wax = plp->ct3;
            
            plp->mtn_no = PlMtnWpn[1];
            
            plp->hokan_rate = 65536;
            plp->hokan_count = 0;
            
            plp->mtn_add = 0;
            
            plp->frm_no = 0;
            
            plp->ct0 = 0;
            
            plp->mode3 = 1;
        } 
        else 
        {
            if (!(sys->pad_on & 0x100)) 
            {
                plp->at_flg &= ~0x40;
            }
            
            plp->wax = (short)plp->ct3 + ((2048 - (((EXP_WORK*)plp->exp0)->scp_ct * 64)) * njSin((((EXP_WORK*)plp->exp0)->scp_ct * 1911) + 8192));
            
            ((EXP_WORK*)plp->exp0)->scp_ct++;
        }
    }

    if (plp->mode3 != 3) 
    {
        if (!(sys->pad_on & 0x80))
        {
            cam.ppers = 11832;
        }
        else
        {
            cam.ppers = 3640;
        }
        
        if ((sys->pad_on & 0x60)) 
        {
            plp->wax -= 4.0f * sys->pad_dy;
        }
        else if (sys->pad_ay >= 48) 
        {
            plp->wax -= 4.0f * (sys->pad_ay - 48);
        }
        else if (sys->pad_ay < -47) 
        {
            plp->wax -= 4.0f * (sys->pad_ay + 48);
        }
        
        if ((sys->pad_on & 0xC)) 
        {
            plp->ay -= 4.0f * sys->pad_dx;
        }
        else if (sys->pad_ax >= 48) 
        {
            plp->ay -= 4.0f * (sys->pad_ax - 48);
        }
        else if (sys->pad_ax < -47) 
        {
            plp->ay -= 4.0f * (sys->pad_ax + 48);
        }
        
        if (plp->wax > 8192)
        {
            plp->wax = 8192;
        }
        
        if (plp->wax < -8192) 
        {
            plp->wax = -8192;
        }
    }
    
    plp->waxp = plp->wax;
}
