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
        
        ax = -njArcTan2(py, d);
        
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
        
        ay = (-njArcTan2(cam.plx - cam.px, cam.plz - cam.pz) + 32767) + 1;
        
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
            
            xr = (short)-njArcTan2(py, d);
            
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
            
            yr = (short)(-njArcTan2(cam.plx - cam.px, cam.plz - cam.pz) + 32767 + 1); 
            
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
            
            ay = -njArcTan2(py, d);
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
            
            ax = (-njArcTan2(cam.plx - cam.px, cam.plz - cam.pz) + 32767) + 1;
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

// 99.52% matching
void bhControlActiveCamera() 
{
    CUT_WORK* cp;
    CAM_WRK* ci;
	float px, py, pz;
	float aa_spd;
	float fa0, fa1;
	unsigned int attr;
	int xr, yr;
	short ax, ay;
	short aa;
	float hkn;
	short ahkn;
    NJS_POINT3 sca;
    float inn;           // not from DWARF
    float len;           // not from DWARF
    short tmp, tmp2;     // not from DWARF
    short axn, ayn, azn; // not from DWARF
    short pers, ppers;   // not from DWARF
 
    cp = &rom->cutp[cam.ncut];
    ci = &cp->cam[cam.camver];
    
    if (((plp->mode0 == 1) && (plp->mode1 == 0) && (plp->mode2 != 13)) || (((plp->flg & 0x200000)) && (plp->mode0 != 7)))
    {
        if ((plp->stflg & 0x30))
        {
            cam.plx = plp->mlwP->owP->mtx[12];
            cam.ply = plp->mlwP->owP->mtx[13] + ci->h;
            cam.plz = plp->mlwP->owP->mtx[14];
        } 
        else 
        {
            cam.plx += 0.5f * (((float*)plp->exp0)[24] - cam.plx);
            cam.ply = rom->grand[plp->flr_no + 2] + ci->h;
            cam.plz += 0.5f * (((float*)plp->exp0)[26] - cam.plz); 
        }
    }
    else if (plp->mode0 == 7) 
    {
        cam.plx = plp->mlwP->owP->mtx[12];
        cam.ply = plp->mlwP->owP->mtx[13] + ci->h;
        cam.plz = plp->mlwP->owP->mtx[14];
    }
 
    attr = bhCheckCutAttribute(cam.plx, cam.plz, plp->flr_no);
    cam.attr = attr;
    
    if (cam.camver != 0) 
    {
        attr >>= 16;
    } 
    else 
    {
        attr &= 0xFFFF;
    }
    
    aa_spd = 0.01f * ci->aa_spd;
   
    if (((ci->w) && (cp->cw)) && (!(attr & 0x20)))
    {
        cam.pxp = (ci->px - (0.5f * ((0.01f * cp->cw) * ci->w))) + (ci->w * (0.01f * (cam.plx - cp->cx)));
    }
    
    if (((ci->d) && (cp->cd)) && (!(attr & 0x8))) 
    {
        cam.pzp = (ci->pz - (0.5f * ((0.01f * cp->cd) * ci->d))) + (ci->d * (0.01f * (cam.plz - cp->cz)));
    }
    
    if (((ci->y0) || (ci->y1) || (ci->y2) || (ci->y3)) && (!(attr & 0x10)))  
    {
        cam.pyp = ci->py + bhCalcActiveYpos(cp);
    } 

    if ((ci->flg & 0x4))
    {
        if (!(attr & 0x4)) 
        {
            px = cam.plx - cam.px;
            pz = cam.plz - cam.pz;
            
            fa0 = njSqrt((px * px) + (pz * pz));
            
            py = cam.ply - cam.py;
            
            ax = -njArcTan2(py, fa0);
            cam.axp = ax & 0xFFFF;
        }
        
        if (!(attr & 0x2)) 
        {
            ay = -njArcTan2(cam.plx - cam.px, cam.plz - cam.pz) + 32768;
            
            cam.ayp = ay & 0xFFFF;
        }
    } 
    else if (!(ci->flg & 0x1))
    {
        if ((ci->lax != 0) && (!(attr & 0x4)))
        {
            ax = ci->ax;
            
            px = cam.plx - cam.px;
            pz = cam.plz - cam.pz;
            
            fa0 = njSqrt((px * px) + (pz * pz));
            fa1 = cam.ply - cam.py;
            
            xr = tmp = -njArcTan2(fa1, fa0);
            
            aa = tmp - ax;
            
            if (aa < (short)-ci->lax) 
            {
                xr = ci->ax - ci->lax;
            }
            
            if ((short)ci->lax < aa) 
            {
                xr = ci->ax + ci->lax;
            }
            
            cam.axp = xr & 0xFFFF;
        }
        
        if ((ci->lay != 0) && (!(attr & 0x2)))
        {
            ay = ci->ay;
            
            px = cam.plx - cam.px;
            pz = cam.plz - cam.pz;
            
            yr = tmp = -njArcTan2(px, pz) + 32768;
            
            aa = tmp - ay;
            
            if (aa < (short)-ci->lay) 
            {
                yr = ci->ay - ci->lay;
            }
            
            if ((short)ci->lay < aa) 
            {
                yr = ci->ay + ci->lay;
            }
            
            cam.ayp = yr & 0xFFFF;
        }
    } 
    else 
    {
        if ((ci->lax != 0) && (!(attr & 0x4))) 
        {
            ax = ci->ax;
            
            px = cam.plx - cam.px;
            pz = cam.plz - cam.pz;
            
            fa0 = njSqrt((px * px) + (pz * pz));
            
            ay = -njArcTan2(cam.ply - cam.py, fa0);
            ay -= ax;
            
            xr  = cam.ax;
            axn = cam.ax;
            
            if (ay < (short)-ci->lax) 
            {
                xr = ci->ax + (ay + ci->lax);
                
                if (((short)xr - axn) > 0)
                {
                    xr = axn;
                }
            }
            else if ((short)ci->lax < ay) 
            {
                xr = (ay - ci->lax) + ci->ax;
                
                if (((short)xr - axn) < 0) 
                {
                    xr = axn;
                }
            }
            
            cam.axp = xr & 0xFFFF;
        }
        
        if ((ci->lay != 0) && (!(attr & 0x2)))
        {
            ay = ci->ay;
            
            px = cam.plx - cam.px;
            pz = cam.plz - cam.pz;
            
            ax = -njArcTan2(px, pz) + 32768;
            ax -= ay;
            
            yr  = cam.ay;
            ayn = cam.ay;
            
            if (ax < (short)-ci->lay) 
            {
                yr = ci->ay + (ax + ci->lay);
                
                if (((short)yr - ayn) > 0) 
                { 
                    yr = ayn; 
                }
            } 
            else if ((short)ci->lay < ax) 
            {
                yr = (ax - ci->lay) + ci->ay;
                
                if (((short)yr - ayn) < 0) 
                {
                    yr = ayn;
                }
            }
            
            cam.ayp = yr & 0xFFFF;
        }
    }
    
    if (((ci->laz0 != 0) || (ci->laz1 != 0) || (ci->laz2 != 0) || (ci->laz3 != 0)) && (!(attr & 0x1)))  
    {
        cam.azp = (short)ci->az + bhCalcActiveZang(cp);
    }
    
    if ((ci->flg & 0x20)) 
    {
        if (!(attr & 0x40)) 
        {
            cam.ppers = bhCalcActivePers(cp);
        }
    } 
    else 
    {
        cam.ppers = ci->pers;
    }
    
    if (!(cam.flg & 0x1)) 
    {   
        cam.px += ci->am_spd * (cam.pxp - cam.px);
        cam.py += ci->am_spd * (cam.pyp - cam.py);
        cam.pz += ci->am_spd * (cam.pzp - cam.pz);
        
        tmp2 = cam.axp;
        ax   = cam.ax;
        
        aa = tmp2 - ax;
        
        fa0 = NJM_ANG_DEG(ax);
        fa1 = NJM_ANG_DEG(aa) * aa_spd;
        
        fa0 += fa1;
        
        ax = NJM_DEG_ANG(fa0);

        cam.ax = ax;
        
        tmp2 = cam.ayp;
        ay   = cam.ay;
        
        aa = tmp2 - ay;
        
        fa0 = NJM_ANG_DEG(ay);
        fa1 = NJM_ANG_DEG(aa) * aa_spd;
        
        fa0 += fa1;
        
        ay = NJM_DEG_ANG(fa0);
        
        cam.ay = ay;
        
        tmp2 = cam.azp;
        azn  = cam.az;
        
        fa0 = NJM_ANG_DEG(azn);
        fa1 = NJM_ANG_DEG(tmp2 - azn);
        
        fa0 += fa1 * aa_spd;
        
        azn    = NJM_DEG_ANG(fa0);
        cam.az = azn;
        
        if (ci->ln != cam.ln) 
        {
            cam.ln += ci->am_spd * (ci->ln - cam.ln);
        }
        
        if (ci->pers != cam.pers)
        { 
            pers  = cam.pers;
            ppers = cam.ppers;
            
            fa0 = NJM_ANG_DEG(pers);
            fa1 = NJM_ANG_DEG(ppers - pers);
            
            fa0 += fa1 * aa_spd;
            
            pers     = NJM_DEG_ANG(fa0);
            cam.pers = pers;
        }
    } 
    else 
    {
        hkn = 1.0f / (ci->spd + 1);
      
        ahkn = ci->spd + 1;
        
        cam.px = cam.px + (cam.hct * (hkn * (cam.pxp - cam.px)));
        cam.py = cam.py + (cam.hct * (hkn * (cam.pyp - cam.py)));
        cam.pz = cam.pz + (cam.hct * (hkn * (cam.pzp - cam.pz)));

        if ((ci->flg & 0x4)) 
        { 
            short tmp, tmp2, tmp3; // not from DWARF
            float fa0, fa1;        // not from DWARF
            
            tmp  = cam.axp;
            tmp2 = cam.ax;
            
            tmp3 = tmp - tmp2;
            
            fa0 = NJM_ANG_DEG(tmp2);
            fa1 = NJM_ANG_DEG(tmp3) * aa_spd;
            
            fa0 += fa1;
            
            tmp3 = NJM_DEG_ANG(fa0);
            
            cam.ax = tmp3;
            
            tmp  = cam.ayp;
            tmp2 = cam.ay;
            
            tmp3 = tmp - tmp2;
            
            fa0 = NJM_ANG_DEG(tmp2);
            fa1 = NJM_ANG_DEG(tmp3) * aa_spd;
            
            fa0 += fa1;
            
            tmp3 = NJM_DEG_ANG(fa0);
            
            cam.ay = tmp3;
            
            tmp2 = cam.az;
            tmp  = cam.azp;
            
            fa0 = NJM_ANG_DEG(tmp2);
            fa1 = NJM_ANG_DEG(tmp - tmp2);
            
            fa0 += fa1 * aa_spd;
            
            tmp3 = NJM_DEG_ANG(fa0);
            
            cam.az = tmp3;
        } 
        else
        { 
            short tmp, tmp2, tmp3; // not from DWARF
            float fa0, fa1, fa2;   // not from DWARF
            
            tmp  = cam.axp;
            tmp2 = cam.ax;
            
            tmp3 = tmp - tmp2;
            
            fa2 = NJM_ANG_DEG(tmp2);
            fa1 = NJM_ANG_DEG(tmp3) * hkn;
            
            fa0  = fa1 * cam.hct;     
            fa2 += fa0;
            
            tmp3 = NJM_DEG_ANG(fa2);
            
            cam.ax = tmp3;
            
            tmp  = cam.ayp;
            tmp2 = cam.ay;
            
            tmp3 = tmp - tmp2;
            
            fa2 = NJM_ANG_DEG(tmp2);
            fa1 = NJM_ANG_DEG(tmp3) * hkn;
                 
            fa0  = fa1 * cam.hct;     
            fa2 += fa0;
            
            tmp3 = NJM_DEG_ANG(fa2);
            
            cam.ay = tmp3;
            
            tmp2 = cam.az;
            tmp  = cam.azp;
            
            fa2 = NJM_ANG_DEG(tmp2);
            fa1 = NJM_ANG_DEG(tmp - tmp2);
                 
            fa0  = fa1 * hkn;     
            fa2 += fa0 * cam.hct;
            
            tmp3 = NJM_DEG_ANG(fa2);
            
            cam.az = tmp3;
        }
        
        cam.ln += cam.hct * (hkn * (ci->ln - cam.ln));
        
        {
        short pers, ppers;   // not from DWARF
        float fa0, fa1, fa2; // not from DWARF
            
        pers  = cam.pers;
        ppers = cam.ppers;
            
        fa2 = NJM_ANG_DEG(pers);
        fa1 = NJM_ANG_DEG(ppers - pers);
            
        fa0  = fa1 * hkn;
        fa2 += fa0 * cam.hct;
        
        pers     = NJM_DEG_ANG(fa2);
        cam.pers = pers;
        
        cam.hct++;
        }
        
        if (cam.hct >= ahkn) 
        {
            cam.flg &= ~0x1;
        }
    }
    
    if ((ci->flg & 0xC0)) 
    {
        sys->gm_flg |= 0x10;
        
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
