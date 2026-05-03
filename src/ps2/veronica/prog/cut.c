#include "../../../ps2/veronica/prog/cut.h"
#include "../../../ps2/veronica/prog/camera.h"
#include "../../../ps2/veronica/prog/event.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/ps2_event.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaView.h"
#include "../../../ps2/veronica/prog/main.h"

// 100% matching!
void bhCheckCut(int flg)
{
    float gpx; 
    float gpz; 
    int pp;    
    int p0;   
    int p1;    
    int p2;   
    int p3;    
    
    sys->gm_flg &= ~0x20;
    
    if ((sys->sp_flg & 0x40))
    {
        if (!(sys->st_flg & 0x1))
        {
            if ((sys->gm_flg & 0x40))
            {
                if (flg != 0)
                {
                    sys->gm_flg &= ~0x800;
                    
                    if ((sys->st_flg & 0x800000)) 
                    {
                        sys->st_flg &= ~0x800000;
                        sys->gm_flg &= ~0x80000;
                        
                        sys->pt_flg |= 0x1;
                    }

                    if (rom->fog_nr <= rom->fog_fr) 
                    {
                        rom->fog_col = 0;
                        
                        rom->fog_nr = 0;
                        rom->fog_fr = -100.0f;
                    }
                    
                    cam.fog_col = rom->fog_col;
                    
                    cam.fog_nr = rom->fog_nr;
                    cam.fog_fr = rom->fog_fr;
                    
                    sys->fog_ct = 0;
                    
                    sys->gm_flg |= 0x10;
                    
                    cam.pe_ax = 0;
                    
                    cam.pe_pers = 11832;
                    
                    bhInitPlEyeCamera();
                }

                return;
            } 
            else 
            {
                if (flg != 0)
                {
                    sys->gm_flg &= ~0x800;
                    
                    if ((sys->st_flg & 0x800000)) 
                    {
                        sys->st_flg &= ~0x800000;
                        sys->gm_flg &= ~0x80000;
                        
                        sys->pt_flg |= 0x1;
                    }
                    
                    cam.ocut = cam.ncut;
                    
                    pp = bhCheckCutArea(plp->gpx, plp->gpz, plp->flr_no);
                    
                    if (pp != -1) 
                    {
                        cam.ncut = pp;
                    }
                    
                    bhSetCut(cam.ncut, 1);
                    
                    cam.ocflg = rom->cutp[cam.ncut].cam[cam.camver].flg;
                } 
                else
                {
                    pp = bhCheckCutArea(plp->gpx, plp->gpz, plp->flr_no);
                    
                    if ((pp != -1) && (pp != cam.ncut))
                    {
                        if (((plp->stflg & 0x30)) || (plp->mode0 == 7))
                        {
                            gpx = plp->mlwP->owP->mtx[12];
                            gpz = plp->mlwP->owP->mtx[14];
                        } 
                        else 
                        {
                            gpx = plp->gpx;
                            gpz = plp->gpz;
                        }
                        
                        p0 = bhCheckCutArea(gpx, gpz - 1.0f, plp->flr_no);
                        p1 = bhCheckCutArea(gpx, 1.0f + gpz, plp->flr_no);
                        p2 = bhCheckCutArea(gpx - 1.0f, gpz, plp->flr_no);
                        p3 = bhCheckCutArea(1.0f + gpx, gpz, plp->flr_no);
                        
                        if ((p0 != cam.ncut) && (p1 != cam.ncut) && (p2 != cam.ncut) && (p3 != cam.ncut))
                        {
                            cam.ocut = cam.ncut;
                            
                            cam.ocflg = rom->cutp[cam.ocut].cam[cam.camver].flg;
                            
                            cam.ncut = pp;
                            
                            bhSetCut(cam.ncut, 0);
                        }
                    }
                }
                
                if (!(cam.flg & 0x80000000))
                {
                    bhControlActiveCamera();
                }
            }
        } 
        else
        {
            switch (cam.flg & 0x46)
            {
            case 0x2:
                bhControlEventCamera();
                break;
            case 0x4:
                bhControlPlEyeCamera(0);
                break;
            case 0x40:
                bhControlMonitorCamera();
                break;
            }
        }
    }
}

// 100% matching!
int bhCheckCutArea(float px, float pz, char flr_no)
{
    CUT_WORK* cp;
    CUT_WRK* ct;
    int i;
    int j;
    
    cp = rom->cutp;
    
    for (i = 0; i < rom->cut_n; i++, cp++)
    {
        if ((cp->flg & 0x1)) 
        {
            ct = cp->cuttp;
            
            for (j = 0; j < cp->ctab_n; j++, ct++)
            {
                if (ct->flr_no == flr_no)
                {
                    if (ct->atr_tp == 0) 
                    {
                        if (((ct->minx <= px) && (ct->maxx > px)) && ((ct->minz <= pz) && (ct->maxz > pz)))
                        {
                            return i;
                        }
                    }
                    else if (bhCheckCutAreaInnerTriangle(px, pz, ct) != 0) 
                    {
                        return i;
                    }
                }
            }
        }
    }

    return -1;
}

// 100% matching!
int bhCheckCutAreaInnerTriangle(float px, float pz, CUT_WRK* ct)
{ 
    float d;
    NJS_POINT3 pos_0, pos_1, pos_2, pos_3; // not from DWARF
    
    if (((px < ct->minx) || (px > ct->maxx)) || ((pz < ct->minz) || (pz > ct->maxz))) 
    {
        return 0; 
    }
    
    switch (ct->atr_tp) 
    {                   
    case 1:
        pos_0.x = ct->maxx; 
        pos_0.z = ct->maxz; 
        
        pos_1.x = ct->minx; 
        pos_1.z = ct->minz; 
        break; 
    case 2: 
        pos_0.x = ct->minx; 
        pos_0.z = ct->maxz; 
        
        pos_1.x = ct->maxx; 
        pos_1.z = ct->minz;
        break; 
    case 3: 
        pos_0.x = ct->minx; 
        pos_0.z = ct->minz; 
        
        pos_1.x = ct->maxx; 
        pos_1.z = ct->maxz;
        break; 
    case 4: 
        pos_0.x = ct->maxx; 
        pos_0.z = ct->minz; 
        
        pos_1.x = ct->minx; 
        pos_1.z = ct->maxz; 
        break;
    }
    
    d = pos_1.z - pos_0.z; 
    
    pos_2.x = px - pos_0.x;
    pos_2.z = fabsf(d / ((pos_1.x - pos_0.x) / pos_2.x)); 
    
    if (fabsf((pos_0.z + d) - pz) <= pos_2.z) 
    { 
        return 0; 
    } 
    else 
    { 
        return 1; 
    }
} 

// 100% matching!
unsigned int bhCheckCutAttribute(float px, float pz, int flr_no)
{
    CUT_WORK* cp;
    CUT_WRK* ct;
    int i;
    int j;

    cp = rom->cutp;

    for (i = 0; i < rom->cut_n; i++, cp++)
    {
        if ((cam.ncut == i) && ((cp->flg & 0x1))) 
        {
            ct = cp->cuttp;
            
            for (j = 0; j < cp->ctab_n; j++, ct++) 
            {
                if (((ct->minx <= px) && (ct->maxx > px)) && ((ct->minz <= pz) && (ct->maxz > pz)) && (ct->flr_no == flr_no)) 
                {
                    return ct->attr;
                }
            }
        }
    }

    return cam.attr;
}

// 100% matching!
void bhSetCut(int cno, int flg)
{
    CAM_WRK* ci;
    LGT_WORK* lp; 
    NJS_CNK_OBJECT* obj; 
    unsigned int attr; 
    int i; 

    if ((sys->ts_flg & 0x200)) 
    {
        bhChangeViewClipRM();
        bhChangeClipVolumeRM();
        bhChangeBackColor();
    }
    
    cam.flg &= ~0x80000046;
    
    sys->gm_flg |= 0x20;
    
    if (!(sys->gm_flg & 0x1)) 
    {
        attr = bhCheckCutAttribute(plp->gpx, plp->gpz, plp->flr_no);
        
        cam.attr = attr;
        
        if ((attr & 0x8000)) 
        {
            cam.camver = 1;
        } 
        else 
        {
            cam.camver = 0;
        }
    }

    ci = (CAM_WRK*)&rom->cutp[cno].cam[cam.camver];
    
    for (i = 0; i < (int)rom->mdl.obj_num; i++)
    {
        obj = &rom->mdl.objP[i];

        if (obj->model != NULL) 
        {
            if (bhCkFlg(ci->hidobj, i) != 0)
            {
                obj->evalflags |= 0x8;
            }
            else
            {
                obj->evalflags &= ~0x8;
            }
        }
    }

    lp = (LGT_WORK*)&rom->lgtp[4];
    
    for (i = 4; i < rom->lgt_n; i++, lp++)
    {
        if (bhCkFlg(ci->hidlgt, i) != 0)
        {
            lp->flg &= ~0x2;
        }
        else 
        {
            lp->flg |= 0x2;
        }
    }
    
    cam.fog_col = ci->fog_col;
    
    cam.fog_nr = ci->fog_nr;
    cam.fog_fr = ci->fog_fr;

    if (((sys->st_flg & 0x2)) && ((ci->flg & 0x8)))
    {
        sys->fog_ct = sys->fog_cngct - 3;

        if (sys->fog_ct < 0)
        {
            sys->fog_ct = 0;
        }

        if ((sys->ef_flg & 0x10))
        {
            sys->ef_flg &= ~0x10;
           
            sys->fog_ct--;
        }

        sys->gm_flg |= 0x10;
    }
    else 
    {
        sys->fog_ct = 0;

        sys->gm_flg |= 0x10;
    }
    
    if ((((ci->flg & 0x2)) && (flg == 0)) || (((cam.ocflg & 0x2)) && (flg == 0))) 
    {
        cam.axp = ci->ax;
        cam.ayp = ci->ay;
        cam.azp = ci->az;
        
        cam.pxp = ci->px;
        cam.pyp = ci->py;
        cam.pzp = ci->pz;
        
        cam.flg |= 0x1;

        cam.hct = 0;
    }
    else 
    {
        cam.ax = cam.axp = ci->ax;
        cam.ay = cam.ayp = ci->ay;
        cam.az = cam.azp =  ci->az;
        
        cam.px = cam.pxp = ci->px;
        cam.py = cam.pyp = ci->py;
        cam.pz = cam.pzp = ci->pz;
        
        cam.pers = ci->pers;
        
        cam.ln = ci->ln;
        
        cam.flg &= ~0x1;

        cam.hct = 0;
    }
    
    if ((ci->flg & 0x8000))
    {
        cam.flg |= 0x8;
        
        sys->fil_no = ci->fil_no;
        sys->fil_rt = ci->fil_rt;
    }
    else 
    {
        cam.flg &= ~0x8;
    }
    
    if ((ci->flg & 0x200))
    {
        cam.flg |= 0x10;
    } 
    else
    {
        cam.flg &= ~0x10;
    }
    
    if ((ci->flg & 0x400)) 
    {
        cam.flg |= 0x20;
    }
    else
    {
        cam.flg &= ~0x20;
    }
    
    bhInitActiveCamera(flg);
    
    bhMakeCameraVector();
}

// 100% matching! 
void bhSetFixedCut(int cno)
{
    CAM_WRK* ci;

    cam.flg &= ~0x80000000;
    
    sys->gm_flg &= ~0x1000;
    sys->gm_flg |= 0x20;
    
    sys->st_flg |= 0x1;
    
    ci = (CAM_WRK*)&rom->cutp[cno].cam[cam.camver];
    
    bhSetHideObjLgt(cno);
    
    cam.fog_col = ci->fog_col;
    
    cam.fog_nr = ci->fog_nr;
    cam.fog_fr = ci->fog_fr;

    if (((sys->st_flg & 0x2)) && ((ci->flg & 0x8))) 
    {
        sys->fog_ct = sys->fog_cngct - 3;
            
        if (sys->fog_ct < 0)
        {
            sys->fog_ct = 0;
        }

        sys->gm_flg |= 0x10; 
    }
    else 
    {
        sys->fog_ct = 0;
        
        sys->gm_flg |= 0x10; 
    }
    
    cam.ocut = cam.ncut;
    cam.ncut = cno;
    
    cam.ax = cam.axp = ci->ax;
    cam.ay = cam.ayp = ci->ay;
    cam.az = cam.azp = ci->az;
    
    cam.px = cam.pxp = ci->px;
    cam.py = cam.pyp = ci->py;
    cam.pz = cam.pzp = ci->pz;
    
    cam.pers = cam.ppers = ci->pers;
    
    cam.ln = cam.pln = ci->ln;
    
    cam.flg &= ~0x1;
    
    cam.hct = 0;
    
    if ((ci->flg & 0x8000)) 
    {
        cam.flg |= 0x8;
        
        sys->fil_no = ci->fil_no;
        sys->fil_rt = ci->fil_rt;
    } 
    else 
    {
        cam.flg &= ~0x8;
    }
    
    if ((ci->flg & 0x200)) 
    {
        cam.flg |= 0x10;
    } 
    else 
    {
        cam.flg &= ~0x10;
    }
    
    if ((ci->flg & 0x400)) 
    {
        cam.flg |= 0x20;
    }
    else 
    {
        cam.flg &= ~0x20;
    }
    
    if ((sys->ts_flg & 0x200)) 
    {
        bhChangeViewClipRM();
        bhChangeClipVolumeRM();
        bhChangeBackColor();
    }
}

// 100% matching!
void bhSetRenderCut(int cno)
{
    CAM_WRK* ci;

    ci = (CAM_WRK*)&rom->cutp[cno].cam;
    
    cam.ncut = cno;
    
    cam.camver = 0;
    
    bhSetHideObjLgt(cno);
    
    cam.ax = cam.axp = ci->ax;
    cam.ay = cam.ayp = ci->ay;
    cam.az = cam.azp = ci->az;
    
    cam.px = cam.pxp = ci->px;
    cam.py = cam.pyp = ci->py;
    cam.pz = cam.pzp = ci->pz;
    
    cam.pers = ci->pers;
    
    cam.ln = ci->ln;
}

// 100% matching!
void bhSetHideObjLgt(int cno)
{
    CAM_WRK* ci;
    LGT_WORK* lp;
    NJS_CNK_OBJECT* obj;
    int i;

    ci = (CAM_WRK*)&rom->cutp[cno].cam[cam.camver];

    for (i = 0; i < (int)rom->mdl.obj_num; i++)
    {
        obj = &rom->mdl.objP[i];
        
        if (obj->model != NULL)
        {
            if (bhCkFlg(ci->hidobj, i) != 0)
            {
                obj->evalflags |= 0x8;
            }
            else
            {
                obj->evalflags &= ~0x8;
            }
        }
    }

    lp = (LGT_WORK*)&rom->lgtp[4];
    
    for (i = 4; i < rom->lgt_n; i++, lp++)
    {
        if (bhCkFlg(ci->hidlgt, i) != 0) 
        {
            lp->flg &= ~0x2;
        } 
        else 
        {
            lp->flg |= 0x2;
        }
    }
}

// 99.51% matching
void bhSetHideObject(int offset)
{   
    NJS_CNK_OBJECT* obj; 
    int i;               
    unsigned int* flg; // not from DWARF

    if (((sys->st_flg & 0x1)) && ((cam.flg & 0x2)))
    {
        flg = &rom->evcp[cam.evc_no].keyf[cam.keyf_no].hidobj[offset]; 
        
        for (i = 0; i < (int)rom->mdl.obj_num; i++)
        {
            obj = &rom->mdl.objP[i];

            if (obj->model != NULL)
            {
                if (bhCkFlg(flg, i) != 0)
                {
                    obj->evalflags |= 0x8;
                }
                else
                {
                    obj->evalflags &= ~0x8;
                }
            }
        }
    }
    else 
    {
        flg = &rom->cutp[cam.ncut].cam[cam.camver].hidobj[offset]; 
      
        for (i = 0; i < (int)rom->mdl.obj_num; i++)
        {
            obj = &rom->mdl.objP[i];
    
            if (obj->model != NULL)
            {
                if (bhCkFlg(flg, i) != 0)
                {
                    obj->evalflags |= 0x8;
                }
                else
                {
                    obj->evalflags &= ~0x8;
                }
            }
        }
    }
}

// TODO: remove these and call njArcTan2 directly, which currently gets called incorrectly from ninjaapi.h
#define NJD_PI_MOD  3.141592f
#define NJM_RAD_ANG_MOD(n)  ((Angle)((n) * (65536.0f / (2 * NJD_PI_MOD))))
#define njArcTan2_MOD(y,x)   ((Angle)NJM_RAD_ANG_MOD(atan2f ((Float)(y),(Float)(x)) ))

// 99.76% matching 
void bhInitActiveCamera(int flg)
{
    CUT_WORK* cp;     
    CAM_WRK* ci;      
    float nrx, nrz;      
    float px, py, pz;        
    float w, d;          
    unsigned int attr;
    int xr, yr;            
    short ax, ay;         
    NJS_POINT3 sca;    
    float inn; // not from DWARF
    float len; // not from DWARF
    
    cp = &rom->cutp[cam.ncut];
    
    ci = &cp->cam[cam.camver]; 
    
    cam.plx = ((float*)plp->exp0)[24] = plp->gpx;
    cam.ply = ((float*)plp->exp0)[25] = plp->gpy + ci->h;
    cam.plz = ((float*)plp->exp0)[26] = plp->gpz;
    
    attr = bhCheckCutAttribute(plp->gpx, plp->gpz, plp->flr_no);
    
    if ((ci->w) && (cp->cw)) 
    {
        if ((attr & 0x20))
        {
            bhCheckNearAttrOffCutRange(cp, 32, &nrx, &nrz);
            
            cam.plx = nrx;
            cam.plz = nrz;
        } 
        else 
        {
            cam.plx = plp->gpx;
            cam.plz = plp->gpz;
        }
        
        px = ci->px - (0.5f * ((0.01f * cp->cw) * ci->w));
        
        w = ((cam.plx - cp->cx) * 0.01f) * ci->w;
        
        if ((((ci->flg & 0x2)) && (flg == 0)) || (((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4))) 
        {
            cam.pxp = px + w;
        } 
        else 
        {
            cam.px = cam.pxp = px + w;
        }
    }
    
    if ((ci->d) && (cp->cd)) 
    {
        if ((attr & 0x8))
        {
            bhCheckNearAttrOffCutRange(cp, 8, &nrx, &nrz);
            
            cam.plx = nrx;
            cam.plz = nrz;
        }
        else 
        {
            cam.plx = plp->gpx;
            cam.plz = plp->gpz;
        }
        
        pz = ci->pz - (0.5f * ((0.01f * cp->cd) * ci->d));
        
        d = ((cam.plz - cp->cz) * 0.01f) * ci->d;
        
        if ((((ci->flg & 0x2)) && (flg == 0)) || (((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4)))
        {
            cam.pzp = pz + d;
        } 
        else 
        {
            cam.pz = cam.pzp = pz + d;
        }
    }
    
    if ((ci->y0) || (ci->y1) || (ci->y2) || (ci->y3)) 
    {
        if ((attr & 0x10)) 
        {
            bhCheckNearAttrOffCutRange(cp, 16, &nrx, &nrz);
            
            cam.plx = nrx;
            cam.plz = nrz;
        } 
        else 
        {
            cam.plx = plp->gpx;
            cam.plz = plp->gpz;
        }
        
        if ((((ci->flg & 0x2)) && (flg == 0)) || ((((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4))))
        {
            cam.pyp = ci->py + bhCalcActiveYpos(cp);
        } 
        else 
        {
            cam.py = cam.pyp = ci->py + bhCalcActiveYpos(cp);
        }
    }
    
    if ((ci->laz0 != 0) || (ci->laz1 != 0) || (ci->laz2 != 0) || (ci->laz3 != 0)) 
    {
        if ((attr & 0x1)) 
        {
            bhCheckNearAttrOffCutRange(cp, 1, &nrx, &nrz);
            
            cam.plx = nrx;
            cam.plz = nrz;
        } 
        else 
        {
            cam.plx = plp->gpx;
            cam.plz = plp->gpz;
        }
        
        if ((((ci->flg & 0x2)) && (flg == 0)) || ((((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4)))) 
        {
            cam.azp = (short)ci->az + bhCalcActiveZang(cp);
        } 
        else 
        {
            cam.az = cam.azp = (short)ci->az + bhCalcActiveZang(cp);
        }   
    }
    
    if ((ci->flg & 0x20)) 
    {
        if ((attr & 0x40))
        {
            bhCheckNearAttrOffCutRange(cp, 64, &nrx, &nrz);
            
            cam.plx = nrx;
            cam.plz = nrz;
        } 
        else 
        {
            cam.plx = plp->gpx;
            cam.plz = plp->gpz;
        }
        
        if ((((ci->flg & 0x2)) && (flg == 0)) || ((((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4)))) 
        {
            cam.ppers = bhCalcActivePers(cp);
        } 
        else 
        {
            cam.pers = cam.ppers = bhCalcActivePers(cp);
        }
    }
    
    if ((ci->flg & 0x4)) 
    {
        if ((attr & 0x4)) 
        {
            bhCheckNearAttrOffCutRange(cp, 4, &nrx, &nrz);
            
            cam.plx = nrx;
            cam.plz = nrz;
        } 
        else 
        {
            cam.plx = plp->gpx;
            cam.plz = plp->gpz;
        }
        
        px = cam.plx - cam.px;
        pz = cam.plz - cam.pz;
        
        d = njSqrt((px * px) + (pz * pz));
        
        py = cam.ply - cam.py;
        
        ax = -njArcTan2_MOD(py, d);
        
        if ((((ci->flg & 0x2)) && (flg == 0)) || ((((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4)))) 
        {
            cam.axp = (unsigned short)ax; 
        } 
        else 
        {
            cam.ax = cam.axp = (unsigned short)ax;
        }
        
        if ((attr & 0x2))
        {
            bhCheckNearAttrOffCutRange(cp, 2, &nrx, &nrz);
            
            cam.plx = nrx;
            cam.plz = nrz;
        } 
        else 
        {
            cam.plx = plp->gpx;
            cam.plz = plp->gpz;
        }
        
        ay = (-njArcTan2_MOD(cam.plx - cam.px, cam.plz - cam.pz) + 32767) + 1;
        
        if ((((ci->flg & 0x2)) && (flg == 0)) || ((((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4)))) 
        {
            cam.ayp = (unsigned short)ay;
        } 
        else 
        {
            cam.ay = cam.ayp = (unsigned short)ay;
        }
    }
    else if (!(ci->flg & 0x1)) 
    {
        if (ci->lax != 0)
        { 
            ax = ci->ax;
                            
            if ((attr & 0x4)) 
            {
                bhCheckNearAttrOffCutRange(cp, 4, &nrx, &nrz);
                
                cam.plx = nrx;
                cam.plz = nrz;
            } 
            else 
            {
                cam.plx = plp->gpx;
                cam.plz = plp->gpz;
            }
                            
            px = cam.plx - cam.px;
            pz = cam.plz - cam.pz;
            
            d = njSqrt((px * px) + (pz * pz));
            
            py = cam.ply - cam.py;
            
            xr = (short)-njArcTan2_MOD(py, d);
            
            ax = xr - ax;
            
            if (ax < (short)-ci->lax) 
            { 
                xr = ci->ax - ci->lax; 
            }
            
            if ((short)ci->lax < ax) 
            { 
                xr = ci->ax + ci->lax; 
            }
                            
            if ((((ci->flg & 0x2)) && (flg == 0)) || ((((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4))))
            {
                cam.axp = (unsigned short)xr;
            } 
            else 
            {
                cam.ax = cam.axp = (unsigned short)xr;  
            }
        }
        
        if (ci->lay != 0) 
        {
            ay = ci->ay;
            
            if ((attr & 0x2)) 
            {
                bhCheckNearAttrOffCutRange(cp, 2, &nrx, &nrz);
                
                cam.plx = nrx;
                cam.plz = nrz;
            } 
            else 
            {
                cam.plx = plp->gpx; 
                cam.plz = plp->gpz;
            }
            
            yr = (short)(-njArcTan2_MOD(cam.plx - cam.px, cam.plz - cam.pz) + 32767 + 1); 
            
            ay = yr - ay;
            
            if (ay < (short)-ci->lay) 
            {
                yr = ci->ay - ci->lay;
            }
            
            if ((short)ci->lay < ay) 
            { 
                yr = ci->ay + ci->lay;
            }
            
            if ((((ci->flg & 0x2)) && (flg == 0)) || ((((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4)))) 
            {
                cam.ayp = (unsigned short)yr; 
            } 
            else 
            {
                cam.ay = cam.ayp = (unsigned short)yr;
            }
        }
    }
    else 
    {
        if (ci->lax != 0) 
        {
            ax = ci->ax;
            
            if ((attr & 0x4)) 
            {
                bhCheckNearAttrOffCutRange(cp, 4, &nrx, &nrz);
                
                cam.plx = nrx;
                cam.plz = nrz;
            } 
            else 
            {
                cam.plx = plp->gpx;
                cam.plz = plp->gpz;
            }
            
            px = cam.plx - cam.px;
            pz = cam.plz - cam.pz;
            
            d = njSqrt((px * px) + (pz * pz));
            
            py = cam.ply - cam.py;
            
            ay = -njArcTan2_MOD(py, d);
            ay -= ax;
            
            yr = ci->ax;
            
            if (ay < (short)-ci->lax) 
            {
                yr = ci->ax + (ay + ci->lax);
            }
            
            if ((short)ci->lax < ay) 
            {
                yr = ci->ax + (ay - ci->lax);
            }
            
            if ((((ci->flg & 0x2)) && (flg == 0)) || ((((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4)))) 
            {
                cam.axp = (unsigned short)yr;
            } 
            else 
            {
                cam.ax = cam.axp = (unsigned short)yr;
            }
        }
      
        if (ci->lay != 0) 
        {
            ay = ci->ay;
            
            if ((attr & 0x2)) 
            {
                bhCheckNearAttrOffCutRange(cp, 2, &nrx, &nrz);
                
                cam.plx = nrx;
                cam.plz = nrz;
            } 
            else 
            {
                cam.plx = plp->gpx;
                cam.plz = plp->gpz;
            }
            
            ax = (-njArcTan2_MOD(cam.plx - cam.px, cam.plz - cam.pz) + 32767) + 1;
            ax -= ay;
            
            yr = ci->ay;
            
            if (ax < (short)-ci->lay) 
            {
                yr = ci->ay + (ax + ci->lay);
            }
            
            if ((short)ci->lay < ax) 
            {
                yr = ci->ay + (ax - ci->lay);
            } 
            
            if ((((ci->flg & 0x2)) && (flg == 0)) || ((((cam.ocflg & 0x2)) && (flg == 0)) || ((cam.flg & 0x4)))) 
            {
                cam.ayp = (unsigned short)yr;
            } 
            else 
            {
                cam.ay = cam.ayp = (unsigned short)yr;
            }
        }
    }
    
    if ((ci->flg & 0xC0)) 
    {
        bhGetCameraPosition();
        
        sca.x = cam.wpx - ci->px;
        sca.y = cam.wpy - ci->py;
        sca.z = cam.wpz - ci->pz;
        
        len = njScalor(&sca);
        
        njUnitVector(&sca);
        
        if (len) 
        {
            inn = njInnerProduct((NJS_VECTOR*)&cam.vx, &sca);
        }
        else 
        { 
            inn = 1.0f;
        }
        
        if ((ci->flg & 0x40)) 
        { 
            cam.fog_nr = ci->fog_nr + (len * inn);
        }
        
        if ((ci->flg & 0x80)) 
        { 
            cam.fog_fr = ci->fog_fr + (len * inn);
        }
    }
}

// 100% matching!
void bhCheckNearAttrOffCutRange(CUT_WORK* cp, unsigned int sft, float* px, float* pz)
{
    CUT_WRK* ct;
    int i; 
    float xx; 
    float zz; 
    float hx; 
    float hz; 
    float ln; 
    float nr;
    
    ct = cp->cuttp;
    
    nr = 10000.0f;

    for (i = 0; i < cp->ctab_n; i++, ct++)
    {
        if ((!(ct->attr & sft)) && (ct->atr_tp == 0))
        {
            xx = 0.5f * (ct->maxx + ct->minx);
            zz = 0.5f * (ct->maxz + ct->minz);

            hx = plp->gpx - xx;
            hz = plp->gpz - ct->minz;
            
            ln = njSqrt((hx * hx) + (hz * hz));

            if (ln < nr)
            {
                nr = ln;
                
                *px = xx;
                *pz = ct->minz;
            }

            hx = plp->gpx - ct->minx;
            hz = plp->gpz - zz;
            
            ln = njSqrt((hx * hx) + (hz * hz));

            if (ln < nr) 
            {
                nr = ln;
                
                *px = ct->minx;
                *pz = zz;
            }

            hx = plp->gpx - ct->maxx;
            hz = plp->gpz - zz;
            
            ln = njSqrt((hx * hx) + (hz * hz));

            if (ln < nr) 
            {
                nr = ln;
                
                *px = ct->maxx;
                *pz = zz;
            }

            hx = plp->gpx - xx;
            hz = plp->gpz - ct->maxz;
            
            ln = njSqrt((hx * hx) + (hz * hz));

            if ((ln < nr) && (!(ct->attr & sft))) 
            {
                nr = ln;
                
                *px = xx;
                *pz = ct->maxz;
            }
        }
    }
}

// 
// Start address: 0x27cb60
void bhControlActiveCamera()
{
	//_anon28 sca;
	short ahkn;
	float hkn;
	short aa;
	short ay;
	short ax;
	int yr;
	int xr;
	unsigned int attr;
	float fa1;
	float fa0;
	float aa_spd;
	float pz;
	float py;
	float px;
	//_anon21* ci;
	//_anon10* cp;
	// Line 1011, Address: 0x27cb60, Func Offset: 0
	// Line 1019, Address: 0x27cb80, Func Offset: 0x20
	// Line 1022, Address: 0x27cb88, Func Offset: 0x28
	// Line 1019, Address: 0x27cb8c, Func Offset: 0x2c
	// Line 1020, Address: 0x27cb98, Func Offset: 0x38
	// Line 1019, Address: 0x27cba0, Func Offset: 0x40
	// Line 1022, Address: 0x27cbb0, Func Offset: 0x50
	// Line 1019, Address: 0x27cbb8, Func Offset: 0x58
	// Line 1020, Address: 0x27cbc0, Func Offset: 0x60
	// Line 1022, Address: 0x27cbd8, Func Offset: 0x78
	// Line 1024, Address: 0x27cc20, Func Offset: 0xc0
	// Line 1026, Address: 0x27cc30, Func Offset: 0xd0
	// Line 1027, Address: 0x27cc44, Func Offset: 0xe4
	// Line 1028, Address: 0x27cc60, Func Offset: 0x100
	// Line 1029, Address: 0x27cc70, Func Offset: 0x110
	// Line 1031, Address: 0x27cc78, Func Offset: 0x118
	// Line 1033, Address: 0x27cca4, Func Offset: 0x144
	// Line 1034, Address: 0x27ccc4, Func Offset: 0x164
	// Line 1036, Address: 0x27cce4, Func Offset: 0x184
	// Line 1037, Address: 0x27ccec, Func Offset: 0x18c
	// Line 1039, Address: 0x27ccf8, Func Offset: 0x198
	// Line 1040, Address: 0x27cd0c, Func Offset: 0x1ac
	// Line 1041, Address: 0x27cd28, Func Offset: 0x1c8
	// Line 1047, Address: 0x27cd3c, Func Offset: 0x1dc
	// Line 1048, Address: 0x27cd58, Func Offset: 0x1f8
	// Line 1049, Address: 0x27cd60, Func Offset: 0x200
	// Line 1052, Address: 0x27cd70, Func Offset: 0x210
	// Line 1053, Address: 0x27cd78, Func Offset: 0x218
	// Line 1056, Address: 0x27cd7c, Func Offset: 0x21c
	// Line 1070, Address: 0x27cd88, Func Offset: 0x228
	// Line 1056, Address: 0x27cd90, Func Offset: 0x230
	// Line 1070, Address: 0x27cda0, Func Offset: 0x240
	// Line 1073, Address: 0x27cdd0, Func Offset: 0x270
	// Line 1077, Address: 0x27ce10, Func Offset: 0x2b0
	// Line 1080, Address: 0x27ce4c, Func Offset: 0x2ec
	// Line 1084, Address: 0x27ce98, Func Offset: 0x338
	// Line 1085, Address: 0x27cef0, Func Offset: 0x390
	// Line 1086, Address: 0x27cefc, Func Offset: 0x39c
	// Line 1094, Address: 0x27cf14, Func Offset: 0x3b4
	// Line 1096, Address: 0x27cf24, Func Offset: 0x3c4
	// Line 1097, Address: 0x27cf30, Func Offset: 0x3d0
	// Line 1098, Address: 0x27cf40, Func Offset: 0x3e0
	// Line 1097, Address: 0x27cf48, Func Offset: 0x3e8
	// Line 1099, Address: 0x27cf4c, Func Offset: 0x3ec
	// Line 1098, Address: 0x27cf50, Func Offset: 0x3f0
	// Line 1099, Address: 0x27cf5c, Func Offset: 0x3fc
	// Line 1101, Address: 0x27cf64, Func Offset: 0x404
	// Line 1103, Address: 0x27cfa0, Func Offset: 0x440
	// Line 1107, Address: 0x27cfac, Func Offset: 0x44c
	// Line 1110, Address: 0x27cfb8, Func Offset: 0x458
	// Line 1112, Address: 0x27d00c, Func Offset: 0x4ac
	// Line 1115, Address: 0x27d014, Func Offset: 0x4b4
	// Line 1117, Address: 0x27d01c, Func Offset: 0x4bc
	// Line 1120, Address: 0x27d028, Func Offset: 0x4c8
	// Line 1121, Address: 0x27d034, Func Offset: 0x4d4
	// Line 1123, Address: 0x27d040, Func Offset: 0x4e0
	// Line 1122, Address: 0x27d048, Func Offset: 0x4e8
	// Line 1123, Address: 0x27d04c, Func Offset: 0x4ec
	// Line 1124, Address: 0x27d054, Func Offset: 0x4f4
	// Line 1123, Address: 0x27d05c, Func Offset: 0x4fc
	// Line 1125, Address: 0x27d060, Func Offset: 0x500
	// Line 1124, Address: 0x27d064, Func Offset: 0x504
	// Line 1125, Address: 0x27d070, Func Offset: 0x510
	// Line 1127, Address: 0x27d078, Func Offset: 0x518
	// Line 1130, Address: 0x27d0a8, Func Offset: 0x548
	// Line 1127, Address: 0x27d0ac, Func Offset: 0x54c
	// Line 1128, Address: 0x27d0b8, Func Offset: 0x558
	// Line 1130, Address: 0x27d0c0, Func Offset: 0x560
	// Line 1128, Address: 0x27d0c8, Func Offset: 0x568
	// Line 1130, Address: 0x27d0cc, Func Offset: 0x56c
	// Line 1131, Address: 0x27d0e4, Func Offset: 0x584
	// Line 1132, Address: 0x27d100, Func Offset: 0x5a0
	// Line 1137, Address: 0x27d10c, Func Offset: 0x5ac
	// Line 1138, Address: 0x27d118, Func Offset: 0x5b8
	// Line 1142, Address: 0x27d124, Func Offset: 0x5c4
	// Line 1139, Address: 0x27d12c, Func Offset: 0x5cc
	// Line 1142, Address: 0x27d130, Func Offset: 0x5d0
	// Line 1145, Address: 0x27d170, Func Offset: 0x610
	// Line 1142, Address: 0x27d174, Func Offset: 0x614
	// Line 1143, Address: 0x27d180, Func Offset: 0x620
	// Line 1145, Address: 0x27d188, Func Offset: 0x628
	// Line 1143, Address: 0x27d190, Func Offset: 0x630
	// Line 1145, Address: 0x27d194, Func Offset: 0x634
	// Line 1146, Address: 0x27d1ac, Func Offset: 0x64c
	// Line 1147, Address: 0x27d1c8, Func Offset: 0x668
	// Line 1151, Address: 0x27d1d0, Func Offset: 0x670
	// Line 1154, Address: 0x27d1d8, Func Offset: 0x678
	// Line 1155, Address: 0x27d1e4, Func Offset: 0x684
	// Line 1157, Address: 0x27d1f0, Func Offset: 0x690
	// Line 1156, Address: 0x27d1f8, Func Offset: 0x698
	// Line 1157, Address: 0x27d1fc, Func Offset: 0x69c
	// Line 1158, Address: 0x27d204, Func Offset: 0x6a4
	// Line 1157, Address: 0x27d20c, Func Offset: 0x6ac
	// Line 1159, Address: 0x27d210, Func Offset: 0x6b0
	// Line 1158, Address: 0x27d214, Func Offset: 0x6b4
	// Line 1159, Address: 0x27d220, Func Offset: 0x6c0
	// Line 1161, Address: 0x27d228, Func Offset: 0x6c8
	// Line 1163, Address: 0x27d258, Func Offset: 0x6f8
	// Line 1161, Address: 0x27d260, Func Offset: 0x700
	// Line 1165, Address: 0x27d26c, Func Offset: 0x70c
	// Line 1162, Address: 0x27d270, Func Offset: 0x710
	// Line 1164, Address: 0x27d274, Func Offset: 0x714
	// Line 1162, Address: 0x27d27c, Func Offset: 0x71c
	// Line 1165, Address: 0x27d284, Func Offset: 0x724
	// Line 1166, Address: 0x27d29c, Func Offset: 0x73c
	// Line 1167, Address: 0x27d2a4, Func Offset: 0x744
	// Line 1166, Address: 0x27d2ac, Func Offset: 0x74c
	// Line 1167, Address: 0x27d2b0, Func Offset: 0x750
	// Line 1168, Address: 0x27d2c4, Func Offset: 0x764
	// Line 1169, Address: 0x27d2cc, Func Offset: 0x76c
	// Line 1170, Address: 0x27d2e0, Func Offset: 0x780
	// Line 1171, Address: 0x27d2e8, Func Offset: 0x788
	// Line 1170, Address: 0x27d2f0, Func Offset: 0x790
	// Line 1171, Address: 0x27d2f4, Func Offset: 0x794
	// Line 1174, Address: 0x27d30c, Func Offset: 0x7ac
	// Line 1179, Address: 0x27d318, Func Offset: 0x7b8
	// Line 1180, Address: 0x27d324, Func Offset: 0x7c4
	// Line 1184, Address: 0x27d330, Func Offset: 0x7d0
	// Line 1181, Address: 0x27d338, Func Offset: 0x7d8
	// Line 1184, Address: 0x27d33c, Func Offset: 0x7dc
	// Line 1186, Address: 0x27d374, Func Offset: 0x814
	// Line 1184, Address: 0x27d37c, Func Offset: 0x81c
	// Line 1188, Address: 0x27d384, Func Offset: 0x824
	// Line 1184, Address: 0x27d388, Func Offset: 0x828
	// Line 1187, Address: 0x27d38c, Func Offset: 0x82c
	// Line 1184, Address: 0x27d390, Func Offset: 0x830
	// Line 1185, Address: 0x27d398, Func Offset: 0x838
	// Line 1188, Address: 0x27d3a0, Func Offset: 0x840
	// Line 1187, Address: 0x27d3a8, Func Offset: 0x848
	// Line 1185, Address: 0x27d3ac, Func Offset: 0x84c
	// Line 1188, Address: 0x27d3b0, Func Offset: 0x850
	// Line 1189, Address: 0x27d3c0, Func Offset: 0x860
	// Line 1190, Address: 0x27d3c8, Func Offset: 0x868
	// Line 1189, Address: 0x27d3d0, Func Offset: 0x870
	// Line 1190, Address: 0x27d3d4, Func Offset: 0x874
	// Line 1191, Address: 0x27d3e8, Func Offset: 0x888
	// Line 1192, Address: 0x27d3f0, Func Offset: 0x890
	// Line 1193, Address: 0x27d404, Func Offset: 0x8a4
	// Line 1194, Address: 0x27d40c, Func Offset: 0x8ac
	// Line 1193, Address: 0x27d414, Func Offset: 0x8b4
	// Line 1194, Address: 0x27d418, Func Offset: 0x8b8
	// Line 1197, Address: 0x27d430, Func Offset: 0x8d0
	// Line 1204, Address: 0x27d43c, Func Offset: 0x8dc
	// Line 1205, Address: 0x27d46c, Func Offset: 0x90c
	// Line 1206, Address: 0x27d478, Func Offset: 0x918
	// Line 1211, Address: 0x27d498, Func Offset: 0x938
	// Line 1212, Address: 0x27d4a8, Func Offset: 0x948
	// Line 1213, Address: 0x27d4b4, Func Offset: 0x954
	// Line 1215, Address: 0x27d4c8, Func Offset: 0x968
	// Line 1216, Address: 0x27d4d0, Func Offset: 0x970
	// Line 1219, Address: 0x27d4dc, Func Offset: 0x97c
	// Line 1221, Address: 0x27d4f0, Func Offset: 0x990
	// Line 1227, Address: 0x27d4f8, Func Offset: 0x998
	// Line 1221, Address: 0x27d500, Func Offset: 0x9a0
	// Line 1230, Address: 0x27d504, Func Offset: 0x9a4
	// Line 1221, Address: 0x27d50c, Func Offset: 0x9ac
	// Line 1222, Address: 0x27d528, Func Offset: 0x9c8
	// Line 1230, Address: 0x27d534, Func Offset: 0x9d4
	// Line 1222, Address: 0x27d538, Func Offset: 0x9d8
	// Line 1223, Address: 0x27d554, Func Offset: 0x9f4
	// Line 1224, Address: 0x27d57c, Func Offset: 0xa1c
	// Line 1225, Address: 0x27d584, Func Offset: 0xa24
	// Line 1226, Address: 0x27d58c, Func Offset: 0xa2c
	// Line 1228, Address: 0x27d598, Func Offset: 0xa38
	// Line 1227, Address: 0x27d59c, Func Offset: 0xa3c
	// Line 1228, Address: 0x27d5a0, Func Offset: 0xa40
	// Line 1227, Address: 0x27d5a4, Func Offset: 0xa44
	// Line 1228, Address: 0x27d5a8, Func Offset: 0xa48
	// Line 1227, Address: 0x27d5ac, Func Offset: 0xa4c
	// Line 1228, Address: 0x27d5b0, Func Offset: 0xa50
	// Line 1229, Address: 0x27d5b4, Func Offset: 0xa54
	// Line 1230, Address: 0x27d5b8, Func Offset: 0xa58
	// Line 1232, Address: 0x27d5c8, Func Offset: 0xa68
	// Line 1233, Address: 0x27d5d0, Func Offset: 0xa70
	// Line 1236, Address: 0x27d5d8, Func Offset: 0xa78
	// Line 1239, Address: 0x27d5e0, Func Offset: 0xa80
	// Line 1234, Address: 0x27d5e8, Func Offset: 0xa88
	// Line 1239, Address: 0x27d5f0, Func Offset: 0xa90
	// Line 1235, Address: 0x27d5f4, Func Offset: 0xa94
	// Line 1237, Address: 0x27d600, Func Offset: 0xaa0
	// Line 1236, Address: 0x27d604, Func Offset: 0xaa4
	// Line 1237, Address: 0x27d608, Func Offset: 0xaa8
	// Line 1236, Address: 0x27d60c, Func Offset: 0xaac
	// Line 1237, Address: 0x27d610, Func Offset: 0xab0
	// Line 1236, Address: 0x27d614, Func Offset: 0xab4
	// Line 1237, Address: 0x27d618, Func Offset: 0xab8
	// Line 1238, Address: 0x27d61c, Func Offset: 0xabc
	// Line 1239, Address: 0x27d620, Func Offset: 0xac0
	// Line 1241, Address: 0x27d630, Func Offset: 0xad0
	// Line 1243, Address: 0x27d638, Func Offset: 0xad8
	// Line 1245, Address: 0x27d640, Func Offset: 0xae0
	// Line 1250, Address: 0x27d648, Func Offset: 0xae8
	// Line 1245, Address: 0x27d650, Func Offset: 0xaf0
	// Line 1247, Address: 0x27d654, Func Offset: 0xaf4
	// Line 1245, Address: 0x27d658, Func Offset: 0xaf8
	// Line 1247, Address: 0x27d65c, Func Offset: 0xafc
	// Line 1245, Address: 0x27d660, Func Offset: 0xb00
	// Line 1250, Address: 0x27d664, Func Offset: 0xb04
	// Line 1247, Address: 0x27d668, Func Offset: 0xb08
	// Line 1250, Address: 0x27d684, Func Offset: 0xb24
	// Line 1251, Address: 0x27d69c, Func Offset: 0xb3c
	// Line 1252, Address: 0x27d6b8, Func Offset: 0xb58
	// Line 1254, Address: 0x27d6d0, Func Offset: 0xb70
	// Line 1256, Address: 0x27d6e4, Func Offset: 0xb84
	// Line 1258, Address: 0x27d6ec, Func Offset: 0xb8c
	// Line 1262, Address: 0x27d6f4, Func Offset: 0xb94
	// Line 1258, Address: 0x27d6fc, Func Offset: 0xb9c
	// Line 1260, Address: 0x27d700, Func Offset: 0xba0
	// Line 1258, Address: 0x27d704, Func Offset: 0xba4
	// Line 1260, Address: 0x27d708, Func Offset: 0xba8
	// Line 1258, Address: 0x27d70c, Func Offset: 0xbac
	// Line 1262, Address: 0x27d710, Func Offset: 0xbb0
	// Line 1260, Address: 0x27d714, Func Offset: 0xbb4
	// Line 1262, Address: 0x27d730, Func Offset: 0xbd0
	// Line 1265, Address: 0x27d744, Func Offset: 0xbe4
	// Line 1270, Address: 0x27d74c, Func Offset: 0xbec
	// Line 1276, Address: 0x27d758, Func Offset: 0xbf8
	// Line 1270, Address: 0x27d760, Func Offset: 0xc00
	// Line 1274, Address: 0x27d768, Func Offset: 0xc08
	// Line 1270, Address: 0x27d76c, Func Offset: 0xc0c
	// Line 1276, Address: 0x27d770, Func Offset: 0xc10
	// Line 1270, Address: 0x27d778, Func Offset: 0xc18
	// Line 1276, Address: 0x27d77c, Func Offset: 0xc1c
	// Line 1277, Address: 0x27d7a0, Func Offset: 0xc40
	// Line 1278, Address: 0x27d7d4, Func Offset: 0xc74
	// Line 1284, Address: 0x27d808, Func Offset: 0xca8
	// Line 1285, Address: 0x27d818, Func Offset: 0xcb8
	// Line 1288, Address: 0x27d820, Func Offset: 0xcc0
	// Line 1291, Address: 0x27d828, Func Offset: 0xcc8
	// Line 1286, Address: 0x27d830, Func Offset: 0xcd0
	// Line 1291, Address: 0x27d838, Func Offset: 0xcd8
	// Line 1287, Address: 0x27d83c, Func Offset: 0xcdc
	// Line 1289, Address: 0x27d848, Func Offset: 0xce8
	// Line 1288, Address: 0x27d84c, Func Offset: 0xcec
	// Line 1289, Address: 0x27d850, Func Offset: 0xcf0
	// Line 1288, Address: 0x27d854, Func Offset: 0xcf4
	// Line 1289, Address: 0x27d858, Func Offset: 0xcf8
	// Line 1288, Address: 0x27d85c, Func Offset: 0xcfc
	// Line 1289, Address: 0x27d860, Func Offset: 0xd00
	// Line 1290, Address: 0x27d864, Func Offset: 0xd04
	// Line 1291, Address: 0x27d868, Func Offset: 0xd08
	// Line 1293, Address: 0x27d878, Func Offset: 0xd18
	// Line 1294, Address: 0x27d880, Func Offset: 0xd20
	// Line 1297, Address: 0x27d888, Func Offset: 0xd28
	// Line 1300, Address: 0x27d890, Func Offset: 0xd30
	// Line 1295, Address: 0x27d898, Func Offset: 0xd38
	// Line 1300, Address: 0x27d8a0, Func Offset: 0xd40
	// Line 1296, Address: 0x27d8a4, Func Offset: 0xd44
	// Line 1298, Address: 0x27d8b0, Func Offset: 0xd50
	// Line 1297, Address: 0x27d8b4, Func Offset: 0xd54
	// Line 1298, Address: 0x27d8b8, Func Offset: 0xd58
	// Line 1297, Address: 0x27d8bc, Func Offset: 0xd5c
	// Line 1298, Address: 0x27d8c0, Func Offset: 0xd60
	// Line 1297, Address: 0x27d8c4, Func Offset: 0xd64
	// Line 1298, Address: 0x27d8c8, Func Offset: 0xd68
	// Line 1299, Address: 0x27d8cc, Func Offset: 0xd6c
	// Line 1300, Address: 0x27d8d0, Func Offset: 0xd70
	// Line 1302, Address: 0x27d8e0, Func Offset: 0xd80
	// Line 1304, Address: 0x27d8e8, Func Offset: 0xd88
	// Line 1306, Address: 0x27d8f0, Func Offset: 0xd90
	// Line 1311, Address: 0x27d8f8, Func Offset: 0xd98
	// Line 1306, Address: 0x27d900, Func Offset: 0xda0
	// Line 1308, Address: 0x27d904, Func Offset: 0xda4
	// Line 1306, Address: 0x27d908, Func Offset: 0xda8
	// Line 1308, Address: 0x27d90c, Func Offset: 0xdac
	// Line 1306, Address: 0x27d910, Func Offset: 0xdb0
	// Line 1311, Address: 0x27d914, Func Offset: 0xdb4
	// Line 1308, Address: 0x27d918, Func Offset: 0xdb8
	// Line 1311, Address: 0x27d934, Func Offset: 0xdd4
	// Line 1312, Address: 0x27d948, Func Offset: 0xde8
	// Line 1313, Address: 0x27d950, Func Offset: 0xdf0
	// Line 1316, Address: 0x27d958, Func Offset: 0xdf8
	// Line 1323, Address: 0x27d960, Func Offset: 0xe00
	// Line 1314, Address: 0x27d968, Func Offset: 0xe08
	// Line 1315, Address: 0x27d970, Func Offset: 0xe10
	// Line 1318, Address: 0x27d97c, Func Offset: 0xe1c
	// Line 1322, Address: 0x27d980, Func Offset: 0xe20
	// Line 1318, Address: 0x27d984, Func Offset: 0xe24
	// Line 1322, Address: 0x27d988, Func Offset: 0xe28
	// Line 1318, Address: 0x27d98c, Func Offset: 0xe2c
	// Line 1316, Address: 0x27d990, Func Offset: 0xe30
	// Line 1322, Address: 0x27d994, Func Offset: 0xe34
	// Line 1316, Address: 0x27d998, Func Offset: 0xe38
	// Line 1318, Address: 0x27d99c, Func Offset: 0xe3c
	// Line 1316, Address: 0x27d9a0, Func Offset: 0xe40
	// Line 1322, Address: 0x27d9a4, Func Offset: 0xe44
	// Line 1323, Address: 0x27d9ac, Func Offset: 0xe4c
	// Line 1325, Address: 0x27d9c0, Func Offset: 0xe60
	// Line 1326, Address: 0x27d9c8, Func Offset: 0xe68
	// Line 1329, Address: 0x27d9d0, Func Offset: 0xe70
	// Line 1336, Address: 0x27d9d8, Func Offset: 0xe78
	// Line 1327, Address: 0x27d9e0, Func Offset: 0xe80
	// Line 1328, Address: 0x27d9e8, Func Offset: 0xe88
	// Line 1331, Address: 0x27d9f4, Func Offset: 0xe94
	// Line 1335, Address: 0x27d9f8, Func Offset: 0xe98
	// Line 1331, Address: 0x27d9fc, Func Offset: 0xe9c
	// Line 1335, Address: 0x27da00, Func Offset: 0xea0
	// Line 1331, Address: 0x27da04, Func Offset: 0xea4
	// Line 1329, Address: 0x27da08, Func Offset: 0xea8
	// Line 1335, Address: 0x27da0c, Func Offset: 0xeac
	// Line 1329, Address: 0x27da10, Func Offset: 0xeb0
	// Line 1331, Address: 0x27da14, Func Offset: 0xeb4
	// Line 1329, Address: 0x27da18, Func Offset: 0xeb8
	// Line 1335, Address: 0x27da1c, Func Offset: 0xebc
	// Line 1336, Address: 0x27da24, Func Offset: 0xec4
	// Line 1338, Address: 0x27da38, Func Offset: 0xed8
	// Line 1340, Address: 0x27da40, Func Offset: 0xee0
	// Line 1342, Address: 0x27da48, Func Offset: 0xee8
	// Line 1351, Address: 0x27da50, Func Offset: 0xef0
	// Line 1342, Address: 0x27da58, Func Offset: 0xef8
	// Line 1348, Address: 0x27da5c, Func Offset: 0xefc
	// Line 1342, Address: 0x27da60, Func Offset: 0xf00
	// Line 1348, Address: 0x27da64, Func Offset: 0xf04
	// Line 1342, Address: 0x27da68, Func Offset: 0xf08
	// Line 1348, Address: 0x27da6c, Func Offset: 0xf0c
	// Line 1351, Address: 0x27da74, Func Offset: 0xf14
	// Line 1348, Address: 0x27da78, Func Offset: 0xf18
	// Line 1351, Address: 0x27da98, Func Offset: 0xf38
	// Line 1354, Address: 0x27dab0, Func Offset: 0xf50
	// Line 1361, Address: 0x27dabc, Func Offset: 0xf5c
	// Line 1369, Address: 0x27dac4, Func Offset: 0xf64
	// Line 1354, Address: 0x27dac8, Func Offset: 0xf68
	// Line 1369, Address: 0x27dad4, Func Offset: 0xf74
	// Line 1354, Address: 0x27dad8, Func Offset: 0xf78
	// Line 1359, Address: 0x27daf0, Func Offset: 0xf90
	// Line 1369, Address: 0x27daf8, Func Offset: 0xf98
	// Line 1361, Address: 0x27dafc, Func Offset: 0xf9c
	// Line 1367, Address: 0x27db00, Func Offset: 0xfa0
	// Line 1361, Address: 0x27db08, Func Offset: 0xfa8
	// Line 1367, Address: 0x27db0c, Func Offset: 0xfac
	// Line 1361, Address: 0x27db10, Func Offset: 0xfb0
	// Line 1367, Address: 0x27db14, Func Offset: 0xfb4
	// Line 1369, Address: 0x27db3c, Func Offset: 0xfdc
	// Line 1372, Address: 0x27db54, Func Offset: 0xff4
	// Line 1377, Address: 0x27db5c, Func Offset: 0xffc
	// Line 1372, Address: 0x27db64, Func Offset: 0x1004
	// Line 1377, Address: 0x27db70, Func Offset: 0x1010
	// Line 1379, Address: 0x27db84, Func Offset: 0x1024
	// Line 1383, Address: 0x27db9c, Func Offset: 0x103c
	// Line 1385, Address: 0x27dbac, Func Offset: 0x104c
	// Line 1389, Address: 0x27dbb4, Func Offset: 0x1054
	// Line 1385, Address: 0x27dbb8, Func Offset: 0x1058
	// Line 1386, Address: 0x27dbbc, Func Offset: 0x105c
	// Line 1385, Address: 0x27dbc0, Func Offset: 0x1060
	// Line 1386, Address: 0x27dbc8, Func Offset: 0x1068
	// Line 1387, Address: 0x27dbd0, Func Offset: 0x1070
	// Line 1386, Address: 0x27dbd4, Func Offset: 0x1074
	// Line 1387, Address: 0x27dbd8, Func Offset: 0x1078
	// Line 1386, Address: 0x27dbdc, Func Offset: 0x107c
	// Line 1387, Address: 0x27dbe0, Func Offset: 0x1080
	// Line 1388, Address: 0x27dbe4, Func Offset: 0x1084
	// Line 1387, Address: 0x27dbec, Func Offset: 0x108c
	// Line 1388, Address: 0x27dbf4, Func Offset: 0x1094
	// Line 1389, Address: 0x27dbfc, Func Offset: 0x109c
	// Line 1390, Address: 0x27dc04, Func Offset: 0x10a4
	// Line 1392, Address: 0x27dc10, Func Offset: 0x10b0
	// Line 1393, Address: 0x27dc48, Func Offset: 0x10e8
	// Line 1394, Address: 0x27dc6c, Func Offset: 0x110c
	// Line 1401, Address: 0x27dc90, Func Offset: 0x1130
	// Func End, Address: 0x27dcb4, Func Offset: 0x1154
	scePrintf("bhControlActiveCamera - UNIMPLEMENTED!\n");
}

// 100% matching! 
void bhSetEventCamera(int evc_no, int key_no)
{
    CAM_KEYF_WORK* kfp;
    NJS_POINT3 pos;
    float px;
    float pz;

    sys->gm_flg |= 0x20;
    
    sys->evc_ono = sys->evc_no;
    sys->evc_okn = sys->evc_kn;
    
    sys->evc_no = evc_no;
    sys->evc_kn = key_no;
    
    cam.keyf_no = key_no;
    
    kfp = &rom->evcp[evc_no].keyf[key_no];
    
    cam.plx = plp->px;
    cam.plz = plp->pz;
    
    cam.px = cam.pxp = kfp->px;
    cam.py = cam.pyp = kfp->py;
    cam.pz = cam.pzp = kfp->pz;
    
    cam.ax = cam.axp = kfp->ax;
    cam.ay = cam.ayp = kfp->ay;
    cam.az = cam.azp = kfp->az;
    
    cam.ln = 0;
    
    cam.pers = kfp->pers;
    
    if (kfp->lkflg != 0)  
    {
        bhGetEvtCamLockPosition(kfp, &pos);
        
        cam.ax = cam.axp = -(int)(10430.381f * atan2f(pos.y - cam.py, njSqrt(((pos.x - cam.px) * (pos.x - cam.px)) + ((pos.z - cam.pz) * (pos.z - cam.pz)))));
        cam.ay = cam.ayp = -(int)(10430.381f * atan2f(pos.x - cam.px, pos.z - cam.pz)) + 32768; 
    }
    
    *(int*)&cam.mode0 = 0;
    
    cam.flg |= 0x2;
    
    sys->st_flg |= 0x1;
    
    bhSetEventHideObjLgt(evc_no, key_no);
    
    if (((sys->st_flg & 0x2)) && ((kfp->flg & 0x8))) 
    {
        cam.fog_col = kfp->fog_col;
        
        cam.fog_nr = kfp->fog_nr;
        cam.fog_fr = kfp->fog_fr;
        
        sys->fog_ct = sys->fog_cngct - 4;
        
        if (sys->fog_ct < 0) 
        {
            sys->fog_ct = 0;
        }
    } 
    else 
    {
        cam.fog_col = kfp->fog_col;
        
        cam.fog_nr = kfp->fog_nr;
        cam.fog_fr = kfp->fog_fr;
        
        sys->fog_ct = 0;
    }
    
    sys->gm_flg |= 0x10;
    
    cam.flg &= ~0x38;
    
    bhChangeBackColorEvt();
}

// 100% matching!
void bhSetEventFixedCut(int cno, int kno)
{
    CAM_KEYF_WORK* kfp;

    sys->gm_flg &= ~0x1000;
    sys->gm_flg |= 0x20;
    
    sys->evc_ono = cno;
    sys->evc_okn = kno;
    
    cam.evc_no = cno;
    
    sys->evc_no = cno;
    sys->evc_kn = kno;
    
    cam.keyf_no = kno;
    
    kfp = &rom->evcp[cno].keyf[kno];
    
    cam.plx = plp->px;
    cam.plz = plp->pz;
    
    cam.px = cam.pxp = kfp->px;
    cam.py = cam.pyp = kfp->py;
    cam.pz = cam.pzp = kfp->pz;
    
    cam.ax = cam.axp = kfp->ax;
    cam.ay = cam.ayp = kfp->ay;
    cam.az = cam.azp = kfp->az;
    
    cam.ln = 0;
    
    cam.pers = kfp->pers;
    
    *(int*)&cam.mode0 = 0;
    
    cam.flg |= 0x2;
    
    sys->st_flg |= 0x1;
    
    bhSetEventHideObjLgt(cno, kno);
    
    if (((sys->st_flg & 0x2)) && ((kfp->flg & 0x8)))
    {
        cam.fog_col = kfp->fog_col;
        
        cam.fog_nr = kfp->fog_nr;
        cam.fog_fr = kfp->fog_fr;
        
        sys->fog_ct = sys->fog_cngct - 4;
        
        if (sys->fog_ct < 0) 
        {
            sys->fog_ct = 0;
        }
    }
    else 
    {
        cam.fog_col = kfp->fog_col;
        
        cam.fog_nr = kfp->fog_nr;
        cam.fog_fr = kfp->fog_fr;
        
        sys->fog_ct = 0;
    }
    
    sys->gm_flg |= 0x10;
    
    cam.flg &= ~0x38;
    
    bhChangeViewClip(sys->stg_no, sys->rom_no, sys->rcase, cam.evc_no);
    bhChangeClipVolume(sys->stg_no, sys->rom_no, sys->rcase, cam.evc_no);
    
    bhChangeBackColorEvt();
}

// 100% matching!
void bhSetEventHideObjLgt(int cno, int kno)
{
    NJS_CNK_OBJECT* obj;
    CAM_KEYF_WORK* kfp;
    LGT_WORK* lp;
    int i; 

    kfp = &rom->evcp[cno].keyf[kno];

    for (i = 0; i < (int)rom->mdl.obj_num; i++)
    {
        obj = &rom->mdl.objP[i];

        if (obj->model != NULL)
        {
            if (bhCkFlg(kfp->hidobj, i) != 0)
            {
                obj->evalflags |= 0x8;
            }
            else
            {
                obj->evalflags &= ~0x8;
            }
        }
    }

    lp = rom->evlp;
    
    for (i = 0; i < rom->evl_n; i++, lp++)
    {
        if (bhCkFlg(kfp->hidlgt, i) != 0)
        {
            lp->flg &= ~0x2;
        }
        else
        {
            lp->flg |= 0x2;
        }
    }
}

// 100% matching!
void bhInitEventCamera()
{
    EVC_WORK* ecp, *jecp;
    CAM_KEYF_WORK* kfp, *jkfp;
    float* ps, *an, *pf, *cr;
    float fax, fay, faz;
    unsigned int r;  
    unsigned int g, b; // not from DWARF  
    int i, j;   
    short ax0, ax1;
    short ay0, ay1;
    short az0, az1;
    
    ecp = &rom->evcp[cam.evc_no];
    
    if (cam.evc_no == (ecp->nxt_no - 1))
    {
        jecp = &rom->evcp[ecp->nxt_no - 1];
        
        kfp = &jecp->keyf[jecp->keyf_n - 1];
        jkfp = jecp->keyf;
    }
    else
    {
        kfp = ecp->keyf;
        
        if (ecp->nxt_no != 0) 
        {
            jecp = &rom->evcp[ecp->nxt_no - 1];
            
            jkfp = jecp->keyf;
        }
    }
    
    ax1 = kfp->ax;
    ay1 = kfp->ay;
    az1 = kfp->az;
    
    fax = 0.005493164f * ax1;
    fay = 0.005493164f * ay1; 
    faz = 0.005493164f * az1;
    
    ps = cam.ips[0];
    an = cam.ian[0];
    pf = cam.ipf[0];
    cr = cam.icr[0];
    
    *ps++ = kfp->px;
    *ps++ = kfp->py;
    *ps++ = kfp->pz;
    
    *an++ = fax; 
    *an++ = fay;
    *an++ = faz;
    
    *pf++ = 0.005493164f * kfp->pers;
    *pf++ = kfp->fog_nr;
    *pf++ = kfp->fog_fr;
    
    r = kfp->fog_col;
    g = kfp->fog_col;
    b = kfp->fog_col;
    
    *cr++ = (r & 0xFF0000) >> 16;
    *cr++ = (g & 0x00FF00) >> 8;
    *cr++ = (b & 0x0000FF) >> 0;
    
    if (ecp->nxt_no != 0)
    {
        kfp = ecp->keyf;
        
        ax1 = kfp->ax;
        ay1 = kfp->ay;
        az1 = kfp->az;
        
        fax = 0.005493164f * ax1;
        fay = 0.005493164f * ay1;
        faz = 0.005493164f * az1;
    }
    
    for (i = 1, j = 0; i < 20; i++) 
    {
        *ps++ = kfp->px;
        *ps++ = kfp->py;
        *ps++ = kfp->pz;
        
        *an++ = fax;
        *an++ = fay;
        *an++ = faz;
        
        *pf++ = 0.005493164f * kfp->pers;
        *pf++ = kfp->fog_nr;
        *pf++ = kfp->fog_fr;
        
        r = kfp->fog_col;
        g = kfp->fog_col;
        b = kfp->fog_col;
        
        *cr++ = (r & 0xFF0000) >> 16;
        *cr++ = (g & 0x00FF00) >> 8;
        *cr++ = (b & 0x0000FF) >> 0;
        
        if (i < ecp->keyf_n)
        {
            ax0 = ax1;
            ay0 = ay1;
            az0 = az1;
            
            kfp++;
            
            ax1 = kfp->ax;
            ay1 = kfp->ay;
            az1 = kfp->az;
            
            fax += 0.005493164f * (ax1 - ax0);
            fay += 0.005493164f * (ay1 - ay0);
            faz += 0.005493164f * (az1 - az0);
        } 
        else if ((ecp->nxt_no != 0) && (j < jecp->keyf_n)) 
        {
            kfp = jkfp;
            
            jkfp++;
            j++;
            
            ax0 = ax1; 
            ay0 = ay1;
            az0 = az1;
            
            ax1 = kfp->ax;
            ay1 = kfp->ay;
            az1 = kfp->az;
            
            fax += 0.005493164f * (ax1 - ax0);
            fay += 0.005493164f * (ay1 - ay0);
            faz += 0.005493164f * (az1 - az0); 
        }
    } 
}

// 100% matching!
void bhControlEventCamera()
{
    EVC_WORK* ecp;      
    CAM_KEYF_WORK* kfp; 
    NJS_POINT3 pos;     
    float ans[3];      
    float px;          
    float pz;           
    
    switch (cam.mode0)
    {
    case 0:
        sys->st_flg |= 0x10;
        
        if ((sys->st_flg & 0x800000)) 
        {
            sys->st_flg &= ~0x800000;
            sys->gm_flg &= ~0x80000;
            
            sys->pt_flg |= 0x1;
        }
        
        cam.flg &= ~0x8;
        
        cam.ct0 = 0;
        
        cam.frm = 0;
        
        cam.mode0 = 1;
        
        bhInitEventCamera();
        
        sys->gm_flg |= 0x10;
        
        bhSetEventHideObjLgt(cam.evc_no, cam.keyf_no);
    case 1:
        ecp = &rom->evcp[cam.evc_no];
        
        kfp = &ecp->keyf[cam.keyf_no];
        
        bhCheckEvtCamLockPosition();
        
        if (kfp->frame != 0) 
        {
            cam.frm = (1.0f / kfp->frame) * cam.ct0;
        }
        else 
        {
            cam.frm = 0;
        }
        
        njOverhauserSpline(cam.ips[cam.keyf_no], ans, NULL, cam.frm);
        
        cam.px = ans[0];
        cam.py = ans[1];
        cam.pz = ans[2];
        
        njOverhauserSpline(cam.ian[cam.keyf_no], ans, NULL, cam.frm);
       
        cam.ax = 182.04445f * ans[0];
        cam.ay = 182.04445f * ans[1];
        cam.az = 182.04445f * ans[2];
        
        if (!(((kfp->lkflg == 0) || ((short)kfp->lkflg != kfp[1].lkflg)) || ((kfp->lkno != kfp[1].lkno) || (kfp->lkono != kfp[1].lkono)) || ((kfp->lx != kfp[1].lx) || (kfp->ly != kfp[1].ly) || (kfp->lz != kfp[1].lz))) || ((kfp->lkflg != 0) && (ecp->keyf_n == 1))) 
        {
            bhGetEvtCamLockPosition(kfp, &pos);

            px = pos.x - cam.px;
            pz = pos.z - cam.pz;
            
            cam.ax = -(int)(10430.381f * atan2f(pos.y - cam.py, njSqrt((px * px) + (pz * pz))));
            cam.ay = (-(int)(10430.381f * atan2f(pos.x - cam.px, pos.z - cam.pz)) + 32767) + 1;
        }
        
        njOverhauserSpline(cam.ipf[cam.keyf_no], ans, NULL, cam.frm);

        cam.pers = 182.04445f * ans[0];
        
        cam.fog_nr = ans[1];
        cam.fog_fr = ans[2];
        
        njOverhauserSpline(cam.icr[cam.keyf_no], ans, NULL, cam.frm);
        
        if (ans[0] < 0)
        {
            ans[0] = 0;
        }
        
        if (ans[0] > 255.0f) 
        {
            ans[0] = 255.0f;
        }
        
        if (ans[1] < 0) 
        {
            ans[1] = 0;
        }
        
        if (ans[1] > 255.0f) 
        {
            ans[1] = 255.0f;
        }
        
        if (ans[2] < 0) 
        {
            ans[2] = 0;
        }
        
        if (ans[2] > 255.0f) 
        {
            ans[2] = 255.0f;
        }
        
        cam.fog_col = ((unsigned int)ans[0] << 16) | ((unsigned int)ans[1] << 8) | ((unsigned int)ans[2] << 0);
        
        if (!(sys->st_flg & 0x80)) 
        {
            cam.ct0++;
        }
        
        if (kfp->frame <= cam.ct0) 
        {
            cam.ct0 = 0;
            
            cam.frm = 0;
            
            cam.keyf_no++;
            
            if (cam.keyf_no >= (ecp->keyf_n - 1))
            {
                if (ecp->nxt_no == 0) 
                {
                    if (cam.keyf_no >= ecp->keyf_n)
                    {
                        cam.keyf_no = ecp->keyf_n - 1;
                    }
                    
                    cam.mode0 = 2;
                    break;
                }
                
                if (cam.keyf_no >= ecp->keyf_n)
                {
                    cam.evc_no = (short)ecp->nxt_no - 1;
                    cam.keyf_no = 0;
                    
                    bhInitEventCamera();
                }
            }
            
            bhSetEventHideObjLgt(cam.evc_no, cam.keyf_no);
        }
        
        break;
    case 2:
        if (!(sys->gm_flg & 0x1)) 
        {
            sys->st_flg &= ~0x10;
            
            kfp = &rom->evcp[cam.evc_no].keyf[cam.keyf_no];
            
            bhCheckEvtCamLockPosition();
            
            cam.frm = 0;
            
            njOverhauserSpline(cam.ips[cam.keyf_no], ans, NULL, cam.frm);
            
            cam.px = ans[0];
            cam.py = ans[1];
            cam.pz = ans[2];
            
            njOverhauserSpline(cam.ian[cam.keyf_no], ans, NULL, cam.frm);
            
            cam.ax = 182.04445f * ans[0];
            cam.ay = 182.04445f * ans[1];
            cam.az = 182.04445f * ans[2];
            
            if (((kfp->lkflg != 0) && ((short)kfp->lkflg == kfp[1].lkflg)) && ((kfp->lkno == kfp[1].lkno) && (kfp->lkono == kfp[1].lkono)) && ((kfp->lx == kfp[1].lx) && (kfp->ly == kfp[1].ly) && (kfp->lz == kfp[1].lz)))
            {
                bhGetEvtCamLockPosition(kfp, &pos);

                px = pos.x - cam.px;
                pz = pos.z - cam.pz;
                
                cam.ax = -(int)(10430.381f * atan2f(pos.y - cam.py, njSqrt((px * px) + (pz * pz)))); 
                cam.ay = (-(int)(10430.381f * atan2f(pos.x - cam.px, pos.z - cam.pz)) + 32767) + 1;
            }
            
            njOverhauserSpline(cam.ipf[cam.keyf_no], ans, NULL, cam.frm);
            
            cam.pers = 182.04445f * ans[0];
            
            cam.fog_nr = ans[1];
            cam.fog_fr = ans[2];
            
            njOverhauserSpline(cam.icr[cam.keyf_no], ans, NULL, cam.frm);
            
            if (ans[0] < 0)
            {
                ans[0] = 0;
            }
            
            if (ans[0] > 255.0f) 
            {
                ans[0] = 255.0f;
            }
            
            if (ans[1] < 0) 
            {
                ans[1] = 0;
            }
            
            if (ans[1] > 255.0f) 
            {
                ans[1] = 255.0f;
            }
            
            if (ans[2] < 0) 
            {
                ans[2] = 0;
            }
            
            if (ans[2] > 255.0f) 
            {
                ans[2] = 255.0f;
            }
            
            cam.fog_col = ((unsigned int)ans[0] << 16) | ((unsigned int)ans[1] << 8) | ((unsigned int)ans[2] << 0);
        }
        
        break;
    }
}

// 100% matching!
void bhCheckEvtCamLockPosition()
{
    NJS_POINT3 pos;     
    EVC_WORK* ecp;      
    EVC_WORK* jecp;      
    CAM_KEYF_WORK* kfp;  
    CAM_KEYF_WORK* jkfp; 
    float* an;          
    float px;           
    float pz;            
    float fax;           
    float fay;           
    float faz;           
    int i;               
    int j;               
    short ax0;           
    short ax1;           
    short ay0;           
    short ay1;           
    short az0;           
    short az1;          
    static short ax;     
    static short ay;    
    static short az;    

    ecp = &rom->evcp[cam.evc_no];
    
    if (cam.evc_no == (ecp->nxt_no - 1))
    {
        jecp = &rom->evcp[ecp->nxt_no - 1];
        
        kfp = &jecp->keyf[jecp->keyf_n - 1];
        jkfp = jecp->keyf;
    }
    else
    {
        kfp = ecp->keyf;
        
        if (ecp->nxt_no != 0) 
        {
            jecp = &rom->evcp[ecp->nxt_no - 1];
            
            jkfp = jecp->keyf;
        }
    }
    
    if (kfp->lkflg != 0) 
    {
        bhGetEvtCamLockPosition(kfp, &pos);
        
        ax1 = -(int)(10430.381f * atan2f(pos.y - kfp->py, njSqrt(((pos.x - kfp->px) * (pos.x - kfp->px)) + ((pos.z - kfp->pz) * (pos.z - kfp->pz)))));
        ay1 = -(int)(10430.381f * atan2f(pos.x - kfp->px, pos.z - kfp->pz)) + (32767 + 1);
    } 
    else 
    {
        ax1 = kfp->ax;
        ay1 = kfp->ay;
    }
    
    az1 = kfp->az;

    fax = 0.005493164f * ax1;
    fay = 0.005493164f * ay1;
    faz = 0.005493164f * az1;

    an = cam.ian[0];
    
    *an++ = fax;
    *an++ = fay;
    *an++ = faz;  
    
    if (ecp->nxt_no != 0) 
    {
        kfp = ecp->keyf;
        
        if (kfp->lkflg != 0) 
        {
            bhGetEvtCamLockPosition(kfp, &pos);
            
            ax1 = -(int)(10430.381f * atan2f(pos.y - kfp->py, njSqrt(((pos.x - kfp->px) * (pos.x - kfp->px)) + ((pos.z - kfp->pz) * (pos.z - kfp->pz)))));
            ay1 = -(int)(10430.381f * atan2f(pos.x - kfp->px, pos.z - kfp->pz)) + (32767 + 1);
        } 
        else 
        {
            ax1 = kfp->ax;
            ay1 = kfp->ay;
        }
        
        az1 = kfp->az;

        fax = 0.005493164f * ax1;
        fay = 0.005493164f * ay1;
        faz = 0.005493164f * az1;
    }
    
    for (i = 1, j = 0; i < 20; i++)  
    {
        *an++ = fax;
        *an++ = fay;
        *an++ = faz;
        
        if (i < ecp->keyf_n) 
        {
            kfp++;
            
            ax0 = ax1;
            ay0 = ay1;
            az0 = az1;
            
            if (kfp->lkflg != 0) 
            {
                bhGetEvtCamLockPosition(kfp, &pos);
                
                ax1 = -(int)(10430.381f * atan2f(pos.y - kfp->py, njSqrt(((pos.x - kfp->px) * (pos.x - kfp->px)) + ((pos.z - kfp->pz) * (pos.z - kfp->pz)))));
                ay1 = -(int)(10430.381f * atan2f(pos.x - kfp->px, pos.z - kfp->pz)) + (32767 + 1);
            } 
            else
            { 
                ax1 = kfp->ax;
                ay1 = kfp->ay;
            }
            
            az1 = kfp->az;
            
            ax = ax1 - ax0;
            ay = ay1 - ay0;
            az = az1 - az0;

            fax += 0.005493164f * ax;
            fay += 0.005493164f * ay;
            faz += 0.005493164f * az;
        }
        else if ((ecp->nxt_no != 0) && (j < jecp->keyf_n)) 
        {
            kfp = jkfp;
            
            jkfp++;
            j++;
            
            ax0 = ax1;
            ay0 = ay1;
            az0 = az1;
            
            if (kfp->lkflg != 0)
            {
                bhGetEvtCamLockPosition(kfp, &pos);
                
                ax1 = -(int)(10430.381f * atan2f(pos.y - kfp->py, njSqrt(((pos.x - kfp->px) * (pos.x - kfp->px)) + ((pos.z - kfp->pz) * (pos.z - kfp->pz)))));
                ay1 = -(int)(10430.381f * atan2f(pos.x - kfp->px, pos.z - kfp->pz)) + (32767 + 1);
            } 
            else 
            {
                ax1 = kfp->ax;
                ay1 = kfp->ay;
            }
            
            az1 = kfp->az;
            
            ax = ax1 - ax0;
            ay = ay1 - ay0;
            az = az1 - az0;

            fax += 0.005493164f * ax;
            fay += 0.005493164f * ay;
            faz += 0.005493164f * az;
        }
    }
}

// 100% matching! 
void bhGetEvtCamLockPosition(CAM_KEYF_WORK* kfp, NJS_POINT3* pos) 
{
    BH_PWORK* pwp;
    POS* psp;
    
    switch (kfp->lkflg) 
    {
    case 1:
        kfp->lkno = 0;
        
        pwp = plp; 
        break;
    case 2:
        if (rom->ene_n <= kfp->lkno) 
        {
            kfp->lkno = 0;
        }

        pwp = &ene[kfp->lkno];
        break;
    case 3:
        if (rom->obj_n <= kfp->lkno) 
        {
            kfp->lkno = 0;
        }
        
        pwp = (BH_PWORK*)&sys->obwp[kfp->lkno];
        break;
    case 4:
        if (rom->itm_n <= kfp->lkno) 
        {
            kfp->lkno = 0;
        } 
        
        pwp = (BH_PWORK*)&sys->itwp[kfp->lkno];
        break;
    case 5:
        if (rom->eff_n <= kfp->lkno) 
        {
            kfp->lkno = 0;
        }
        
        pwp = (BH_PWORK*)&eff[sys->efid[kfp->lkno]];
        break;
    case 6:
        kfp->lkono = 0;
        
        if (rom->pos_n <= kfp->lkno) 
        {
            kfp->lkno = 0;
        }
        
        psp = &rom->posp[kfp->lkno];
        
        pos->x = psp->px + kfp->lx;
        pos->y = psp->py + kfp->ly;
        pos->z = psp->pz + kfp->lz;
        break;
    }
    
    if (kfp->lkflg < 6) 
    {
        if (pwp->mlwP->obj_num <= kfp->lkono)
        {
            kfp->lkono = 0;
        }
        
        if (kfp->lkono == 0) 
        {
            njCalcPoint(pwp->mtx, (NJS_POINT3*)&kfp->lx, pos);
        }
        else 
        {
            njCalcPoint(&pwp->mlwP->owP[(short)kfp->lkono].mtx, (NJS_POINT3*)&kfp->lx, pos);
        }
    }
}

#pragma divbyzerocheck on 

// 99.84% matching
void bhControlPlEyeCamera(unsigned int attr) 
{
    CAM_WRK* ci; 
    float hkn;   
    int ct;    
    short ax, ay;  
    short ahkn; 

    ci = &rom->cutp[cam.ncut].cam[cam.camver];
    
    hkn = 1.0f / (ci->spd + 1);
    ahkn = ci->spd + 1;
    
    ct = cam.ct0;
    
    switch (cam.mode0) 
    {                         
    case 0:
        cam.pxp = plp->mlwP->owP[5].mtx[12];
        cam.pyp = plp->mlwP->owP[5].mtx[13];
        cam.pzp = plp->mlwP->owP[5].mtx[14];
        
        cam.axp = 0;
        cam.ayp = -plp->ay;
        cam.azp = 0;
        
        cam.px = cam.px + (ct * (hkn * (cam.pxp - cam.px)));
        cam.py = cam.py + (ct * (hkn * (cam.pyp - cam.py)));
        cam.pz = cam.pz + (ct * (hkn * (cam.pzp - cam.pz)));
        
        cam.pln = -2.2f;
        
        cam.ppers = 11832;
        
        cam.ax = (short)((short)cam.ax + (ct * (((short)((short)cam.axp - (short)cam.ax)) / ahkn)));
        cam.ay = (short)((short)cam.ay + (ct * (((short)((short)cam.ayp - (short)cam.ay)) / ahkn)));
        cam.az = (short)((short)cam.az + (ct * (((short)((short)cam.azp - (short)cam.az)) / ahkn)));
        
        cam.ln = cam.ln + (ct * (hkn * (cam.pln - cam.ln)));
        
        cam.pers = cam.pers + (ct * ((cam.ppers - cam.pers) / ahkn));
        
        cam.ct0++;
        
        if (cam.ct0 >= ahkn) 
        {
            cam.px = plp->mlwP->owP[5].mtx[12];
            cam.py = plp->mlwP->owP[5].mtx[13];
            cam.pz = plp->mlwP->owP[5].mtx[14];
            
            cam.ax = 0;
            cam.ay = -plp->ay;
            cam.az = 0;
            
            cam.ln = cam.pln;
            
            cam.pers = cam.ppers;
            
            cam.mode0 = 1;
        }
        
        break;
    case 1:
        cam.axp = 0;
        
        if (plp->mode1 != 0) 
        {
            if ((plp->at_flg & 0x4)) 
            {
                cam.axp = 57344;
            }
            
            if ((plp->at_flg & 0x8)) 
            {
                cam.axp = 7281;
            }
        }
        
        cam.ln = -2.2f;
        
        cam.px = plp->mlwP->owP[5].mtx[12];
        cam.py = plp->mlwP->owP[5].mtx[13];
        cam.pz = plp->mlwP->owP[5].mtx[14];
        
        cam.ax = (short)((short)cam.ax + ((short)(((short)cam.axp - (short)cam.ax) / 4)));
        cam.ay = -plp->ay;
        cam.az = 0;
        
        if (!(attr & 0x4000)) 
        {
            cam.axp = ci->ax;
            cam.ayp = ci->ay;
            cam.azp = ci->az;
            
            cam.pxp = ci->px;
            cam.pyp = ci->py;
            cam.pzp = ci->pz;
            
            cam.pln = ci->ln;
            
            cam.ppers = ci->pers;
            
            bhInitActiveCamera(0);
            
            cam.mode0 = 2;
            
            cam.ct0 = 0;
        }
        
        break;
    case 2:
        cam.px = cam.px + (ct * (hkn * (cam.pxp - cam.px)));
        cam.py = cam.py + (ct * (hkn * (cam.pyp - cam.py)));
        cam.pz = cam.pz + (ct * (hkn * (cam.pzp - cam.pz)));
        
        cam.ax = (short)((short)cam.ax + (ct * (((short)((short)cam.axp - (short)cam.ax)) / ahkn)));
        cam.ay = (short)((short)cam.ay + (ct * (((short)((short)cam.ayp - (short)cam.ay)) / ahkn)));
        cam.az = (short)((short)cam.az + (ct * (((short)((short)cam.azp - (short)cam.az)) / ahkn)));
        
        cam.ln = cam.ln + (ct * (hkn * (cam.pln - cam.ln)));
        
        cam.pers = cam.pers + (ct * ((cam.ppers - cam.pers) / ahkn));
        
        cam.ct0++;
        
        if (cam.ct0 >= ahkn) 
        {
            cam.ax = cam.axp;
            cam.ay = cam.ayp;
            cam.az = cam.azp;
            
            cam.px = cam.pxp;
            cam.py = cam.pyp;
            cam.pz = cam.pzp;
            
            cam.ln = ci->ln;
            
            cam.pers = ci->pers;
            
            cam.flg &= ~0x4;
        }
        
        break;
    }
}

#pragma divbyzerocheck off 

// 100% matching!
void bhInitPlEyeCamera()
{
    NJS_CNK_OBJECT* obj;
    LGT_WORK* lp;
    int i;

    sys->gm_flg &= ~0x2000;
    
    if ((plp->flg & 0x4)) 
    {
        if (!(sys->gm_flg & 0x1000000))
        {
            sys->gm_flg &= ~0x40;
            sys->gm_flg &= ~0x80;
            sys->gm_flg |= 0x800;
        }
        
        sys->st_flg &= ~0x800000;
        sys->gm_flg &= ~0x80000;
        
        sys->pt_flg |= 0x1;
        return;
    }
    
    sys->gm_flg |= 0x20;
    sys->gm_flg |= 0xC0;
    
    cam.px = cam.plx = cam.pxp = plp->mlwP->owP[5].mtx[12];
    cam.py = cam.pyp = plp->mlwP->owP[5].mtx[13];
    cam.pz = cam.plz = cam.pzp = plp->mlwP->owP[5].mtx[14];
    
    cam.ax = cam.axp = cam.pe_ax;
    cam.ay = cam.ayp = plp->ay;
    cam.az = cam.azp = 0;
    
    cam.ln = 0;
    
    cam.pers = 11832;
    cam.ppers = cam.pe_pers;
    
    *(int*)&cam.mode0 = 0;
    
    sys->st_flg &= ~0x1;
    
    for (i = 0; i < (int)rom->mdl.obj_num; i++)
    {
        obj = &rom->mdl.objP[i];
        
        if (obj->model != NULL)
        {
            obj->evalflags &= ~0x8;
        }
    }

    lp = (LGT_WORK*)&rom->lgtp[4];
    
    for (i = 4; i < rom->lgt_n; i++, lp++)
    {
        lp->flg &= ~0x2;
    }
    
    if ((sys->st_flg & 0x2))
    {
        cam.fog_col = rom->fog_col;
        
        cam.fog_nr = rom->fog_nr;
        cam.fog_fr = rom->fog_fr;
        
        sys->fog_ct = sys->fog_cngct - 4;

        if (sys->fog_ct < 0) 
        {
            sys->fog_ct = 0;
        }
    } 
    else 
    {
        cam.fog_col = rom->fog_col;
        
        cam.fog_nr = rom->fog_nr;
        cam.fog_fr = rom->fog_fr;
        
        sys->fog_ct = 0;
    }
    
    sys->gm_flg |= 0x10;

    if ((plp->wpnr_no == 10) || (plp->wpnr_no == 19))
    {
        njClipZ(-1.1f, -20000.0f);
    }
    else
    {
        njClipZ(-1.0f, -20000.0f);
    }
}

// 100% matching! 
void bhSetPlEyeCamera()
{
    NJS_POINT3 pos; 
    short ay; 
    short axn;       
    
    if ((sys->st_flg & 0x800000)) 
    {
        cam.ln = 0;
        
        pos.x = 0;
        pos.y = 1.5f;
        pos.z = -1.0f;
        
        njCalcPoint(&plp->mlwP->owP[5].mtx, &pos, (NJS_POINT3*)&cam.px);
        
        cam.ax = -plp->wax;
        cam.ay = -plp->ay;
        cam.az = 0;
        
        axn = cam.pers;
        ay = cam.ppers;
        
        if (ABS(ay - axn) < 364) 
        {
            cam.pers = cam.ppers;
        }
        else
        {
            if (axn > ay) 
            {
                axn -= 364;
            }
            else 
            {
                axn += 364;
            }
            
            cam.pers = axn;
        }
    }
    else 
    { 
        cam.axp = 0;
        
        ay = 2048;
        
        if ((plp->mode0 == 1) && (plp->mode1 != 0)) 
        {
            cam.axp = -plp->wax;
            
            ay = 0;
        }
    
        cam.ln = 0;
        
        pos.x = 0;
        pos.y = 1.5f;
        pos.z = -1.0f;
        
        njCalcPoint(&plp->mlwP->owP[5].mtx, &pos, (NJS_POINT3*)&cam.px);
        
        axn = cam.ax;
        ay = (cam.axp + ay) - axn;
        
        axn += ay / 4;
        
        cam.ax = axn;
        cam.ay = -plp->ay;
        cam.az = 0;
        
        if (ABS(ay) < 182)
        {
            axn = cam.pers;
            
            axn += ((short)cam.ppers - axn) / 4;
            
            cam.pers = axn;
        }
    }
}

// 100% matching!
void bhControlMonitorCamera()
{

}

// 100% matching!
float bhCalcActiveYpos(CUT_WORK* cp)
{
    CAM_WRK* ci;
    float yy0;
	
    ci = &cp->cam[cam.camver];

    yy0 = ci->y0 + ((cam.plz - cp->cz) * ((ci->y2 - ci->y0) / cp->cd));
    
    return yy0 + ((cam.plx - cp->cx) * (((ci->y1 + ((cam.plz - cp->cz) * ((ci->y3 - ci->y1) / cp->cd))) - yy0) / cp->cw));
}

// 99.14% matching (matches on GC)
short bhCalcActiveZang(CUT_WORK* cp)
{
    CAM_WRK* ci; 
    float laz0;
    float laz1; 
    float ag0;  
    
    ci = &cp->cam[cam.camver];
    
    laz0 = ci->laz0;
    laz1 = ci->laz1;
    
    ag0 = laz0 + ((cam.plz - cp->cz) * ((ci->laz2 - laz0) / cp->cd));
    
    return ag0 + ((cam.plx - cp->cx) * (((laz1 + ((cam.plz - cp->cz) * ((ci->laz3 - laz1) / cp->cd))) - ag0) / cp->cw));
}

// 100% matching!
short bhCalcActivePers(CUT_WORK* cp)
{
    float lap0;       
    float lap1;         
    float ag0;          
    unsigned char* psp; 
    
    psp = (unsigned char*)&cp->cam[cam.camver].pers;
    
    lap0 = (int)(182.04445f * *psp++);
    lap1 = (int)(182.04445f * *psp++);
   
    ag0 = lap0 + ((cam.plz - cp->cz) * (((int)(182.04445f * *psp++) - lap0) / cp->cd));
   
    return ag0 + ((cam.plx - cp->cx) * (((lap1 + ((cam.plz - cp->cz) * (((int)(182.04445f * *psp) - lap1) / cp->cd))) - ag0) / cp->cw));
}
