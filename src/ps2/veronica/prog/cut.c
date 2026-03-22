#include "cut.h"
#include "camera.h"
#include "event.h"
#include "flag.h"
#include "ps2_event.h"
#include "ps2_NaMath.h"
#include "ps2_NaMatrix.h"
#include "ps2_NaView.h"
#include "main.h"

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

// 
// Start address: 0x27b900
void bhInitActiveCamera(int flg)
{
	//_anon28 sca;
	short ay;
	short ax;
	int yr;
	int xr;
	unsigned int attr;
	float d;
	float w;
	float pz;
	float py;
	float px;
	float nrz;
	float nrx;
	//_anon21* ci;
	//_anon10* cp;
	// Line 656, Address: 0x27b900, Func Offset: 0
	// Line 664, Address: 0x27b920, Func Offset: 0x20
	// Line 665, Address: 0x27b938, Func Offset: 0x38
	// Line 664, Address: 0x27b940, Func Offset: 0x40
	// Line 667, Address: 0x27b950, Func Offset: 0x50
	// Line 664, Address: 0x27b958, Func Offset: 0x58
	// Line 667, Address: 0x27b960, Func Offset: 0x60
	// Line 665, Address: 0x27b970, Func Offset: 0x70
	// Line 667, Address: 0x27b978, Func Offset: 0x78
	// Line 665, Address: 0x27b97c, Func Offset: 0x7c
	// Line 668, Address: 0x27b984, Func Offset: 0x84
	// Line 665, Address: 0x27b98c, Func Offset: 0x8c
	// Line 668, Address: 0x27b994, Func Offset: 0x94
	// Line 665, Address: 0x27b998, Func Offset: 0x98
	// Line 668, Address: 0x27b99c, Func Offset: 0x9c
	// Line 669, Address: 0x27b9b4, Func Offset: 0xb4
	// Line 671, Address: 0x27b9d0, Func Offset: 0xd0
	// Line 673, Address: 0x27b9e8, Func Offset: 0xe8
	// Line 674, Address: 0x27ba18, Func Offset: 0x118
	// Line 675, Address: 0x27ba24, Func Offset: 0x124
	// Line 676, Address: 0x27ba38, Func Offset: 0x138
	// Line 677, Address: 0x27ba40, Func Offset: 0x140
	// Line 676, Address: 0x27ba44, Func Offset: 0x144
	// Line 677, Address: 0x27ba48, Func Offset: 0x148
	// Line 678, Address: 0x27ba4c, Func Offset: 0x14c
	// Line 679, Address: 0x27ba54, Func Offset: 0x154
	// Line 680, Address: 0x27ba68, Func Offset: 0x168
	// Line 682, Address: 0x27ba74, Func Offset: 0x174
	// Line 683, Address: 0x27ba84, Func Offset: 0x184
	// Line 682, Address: 0x27ba88, Func Offset: 0x188
	// Line 683, Address: 0x27ba94, Func Offset: 0x194
	// Line 682, Address: 0x27ba98, Func Offset: 0x198
	// Line 683, Address: 0x27ba9c, Func Offset: 0x19c
	// Line 682, Address: 0x27baa0, Func Offset: 0x1a0
	// Line 684, Address: 0x27baa8, Func Offset: 0x1a8
	// Line 683, Address: 0x27baac, Func Offset: 0x1ac
	// Line 684, Address: 0x27bab0, Func Offset: 0x1b0
	// Line 683, Address: 0x27bab4, Func Offset: 0x1b4
	// Line 682, Address: 0x27bab8, Func Offset: 0x1b8
	// Line 683, Address: 0x27babc, Func Offset: 0x1bc
	// Line 684, Address: 0x27bac0, Func Offset: 0x1c0
	// Line 687, Address: 0x27bb00, Func Offset: 0x200
	// Line 688, Address: 0x27bb08, Func Offset: 0x208
	// Line 689, Address: 0x27bb10, Func Offset: 0x210
	// Line 693, Address: 0x27bb24, Func Offset: 0x224
	// Line 694, Address: 0x27bb54, Func Offset: 0x254
	// Line 695, Address: 0x27bb60, Func Offset: 0x260
	// Line 696, Address: 0x27bb74, Func Offset: 0x274
	// Line 697, Address: 0x27bb7c, Func Offset: 0x27c
	// Line 696, Address: 0x27bb80, Func Offset: 0x280
	// Line 697, Address: 0x27bb84, Func Offset: 0x284
	// Line 698, Address: 0x27bb88, Func Offset: 0x288
	// Line 699, Address: 0x27bb90, Func Offset: 0x290
	// Line 700, Address: 0x27bba4, Func Offset: 0x2a4
	// Line 702, Address: 0x27bbb0, Func Offset: 0x2b0
	// Line 703, Address: 0x27bbc0, Func Offset: 0x2c0
	// Line 702, Address: 0x27bbc4, Func Offset: 0x2c4
	// Line 703, Address: 0x27bbd0, Func Offset: 0x2d0
	// Line 702, Address: 0x27bbd4, Func Offset: 0x2d4
	// Line 703, Address: 0x27bbd8, Func Offset: 0x2d8
	// Line 702, Address: 0x27bbdc, Func Offset: 0x2dc
	// Line 704, Address: 0x27bbe4, Func Offset: 0x2e4
	// Line 703, Address: 0x27bbe8, Func Offset: 0x2e8
	// Line 704, Address: 0x27bbec, Func Offset: 0x2ec
	// Line 703, Address: 0x27bbf0, Func Offset: 0x2f0
	// Line 702, Address: 0x27bbf4, Func Offset: 0x2f4
	// Line 703, Address: 0x27bbf8, Func Offset: 0x2f8
	// Line 704, Address: 0x27bbfc, Func Offset: 0x2fc
	// Line 707, Address: 0x27bc3c, Func Offset: 0x33c
	// Line 708, Address: 0x27bc44, Func Offset: 0x344
	// Line 709, Address: 0x27bc4c, Func Offset: 0x34c
	// Line 713, Address: 0x27bc60, Func Offset: 0x360
	// Line 714, Address: 0x27bcb8, Func Offset: 0x3b8
	// Line 715, Address: 0x27bcc4, Func Offset: 0x3c4
	// Line 716, Address: 0x27bcd8, Func Offset: 0x3d8
	// Line 717, Address: 0x27bce0, Func Offset: 0x3e0
	// Line 716, Address: 0x27bce4, Func Offset: 0x3e4
	// Line 717, Address: 0x27bce8, Func Offset: 0x3e8
	// Line 718, Address: 0x27bcec, Func Offset: 0x3ec
	// Line 719, Address: 0x27bcf4, Func Offset: 0x3f4
	// Line 720, Address: 0x27bd08, Func Offset: 0x408
	// Line 722, Address: 0x27bd14, Func Offset: 0x414
	// Line 725, Address: 0x27bd5c, Func Offset: 0x45c
	// Line 726, Address: 0x27bd74, Func Offset: 0x474
	// Line 727, Address: 0x27bd7c, Func Offset: 0x47c
	// Line 731, Address: 0x27bda0, Func Offset: 0x4a0
	// Line 732, Address: 0x27bdd0, Func Offset: 0x4d0
	// Line 733, Address: 0x27bddc, Func Offset: 0x4dc
	// Line 734, Address: 0x27bdf0, Func Offset: 0x4f0
	// Line 735, Address: 0x27bdf8, Func Offset: 0x4f8
	// Line 734, Address: 0x27bdfc, Func Offset: 0x4fc
	// Line 735, Address: 0x27be00, Func Offset: 0x500
	// Line 736, Address: 0x27be04, Func Offset: 0x504
	// Line 737, Address: 0x27be0c, Func Offset: 0x50c
	// Line 738, Address: 0x27be20, Func Offset: 0x520
	// Line 740, Address: 0x27be2c, Func Offset: 0x52c
	// Line 743, Address: 0x27be74, Func Offset: 0x574
	// Line 744, Address: 0x27be94, Func Offset: 0x594
	// Line 745, Address: 0x27be9c, Func Offset: 0x59c
	// Line 749, Address: 0x27bec8, Func Offset: 0x5c8
	// Line 750, Address: 0x27bed8, Func Offset: 0x5d8
	// Line 751, Address: 0x27bee4, Func Offset: 0x5e4
	// Line 752, Address: 0x27bef8, Func Offset: 0x5f8
	// Line 753, Address: 0x27bf00, Func Offset: 0x600
	// Line 752, Address: 0x27bf04, Func Offset: 0x604
	// Line 753, Address: 0x27bf08, Func Offset: 0x608
	// Line 754, Address: 0x27bf0c, Func Offset: 0x60c
	// Line 755, Address: 0x27bf14, Func Offset: 0x614
	// Line 756, Address: 0x27bf28, Func Offset: 0x628
	// Line 758, Address: 0x27bf34, Func Offset: 0x634
	// Line 761, Address: 0x27bf7c, Func Offset: 0x67c
	// Line 762, Address: 0x27bf94, Func Offset: 0x694
	// Line 763, Address: 0x27bf9c, Func Offset: 0x69c
	// Line 767, Address: 0x27bfc0, Func Offset: 0x6c0
	// Line 769, Address: 0x27bfd0, Func Offset: 0x6d0
	// Line 770, Address: 0x27bfdc, Func Offset: 0x6dc
	// Line 771, Address: 0x27bff0, Func Offset: 0x6f0
	// Line 772, Address: 0x27bff8, Func Offset: 0x6f8
	// Line 771, Address: 0x27bffc, Func Offset: 0x6fc
	// Line 772, Address: 0x27c000, Func Offset: 0x700
	// Line 773, Address: 0x27c004, Func Offset: 0x704
	// Line 774, Address: 0x27c00c, Func Offset: 0x70c
	// Line 775, Address: 0x27c020, Func Offset: 0x720
	// Line 777, Address: 0x27c02c, Func Offset: 0x72c
	// Line 778, Address: 0x27c03c, Func Offset: 0x73c
	// Line 777, Address: 0x27c044, Func Offset: 0x744
	// Line 779, Address: 0x27c048, Func Offset: 0x748
	// Line 778, Address: 0x27c04c, Func Offset: 0x74c
	// Line 779, Address: 0x27c058, Func Offset: 0x758
	// Line 781, Address: 0x27c060, Func Offset: 0x760
	// Line 783, Address: 0x27c098, Func Offset: 0x798
	// Line 786, Address: 0x27c0e0, Func Offset: 0x7e0
	// Line 787, Address: 0x27c0e8, Func Offset: 0x7e8
	// Line 788, Address: 0x27c0f0, Func Offset: 0x7f0
	// Line 791, Address: 0x27c104, Func Offset: 0x804
	// Line 792, Address: 0x27c110, Func Offset: 0x810
	// Line 793, Address: 0x27c124, Func Offset: 0x824
	// Line 794, Address: 0x27c12c, Func Offset: 0x82c
	// Line 793, Address: 0x27c130, Func Offset: 0x830
	// Line 794, Address: 0x27c134, Func Offset: 0x834
	// Line 795, Address: 0x27c138, Func Offset: 0x838
	// Line 796, Address: 0x27c140, Func Offset: 0x840
	// Line 797, Address: 0x27c154, Func Offset: 0x854
	// Line 801, Address: 0x27c160, Func Offset: 0x860
	// Line 803, Address: 0x27c1a8, Func Offset: 0x8a8
	// Line 801, Address: 0x27c1ac, Func Offset: 0x8ac
	// Line 803, Address: 0x27c1b4, Func Offset: 0x8b4
	// Line 806, Address: 0x27c1f8, Func Offset: 0x8f8
	// Line 807, Address: 0x27c200, Func Offset: 0x900
	// Line 808, Address: 0x27c208, Func Offset: 0x908
	// Line 810, Address: 0x27c218, Func Offset: 0x918
	// Line 811, Address: 0x27c220, Func Offset: 0x920
	// Line 814, Address: 0x27c22c, Func Offset: 0x92c
	// Line 816, Address: 0x27c238, Func Offset: 0x938
	// Line 817, Address: 0x27c244, Func Offset: 0x944
	// Line 818, Address: 0x27c258, Func Offset: 0x958
	// Line 819, Address: 0x27c260, Func Offset: 0x960
	// Line 818, Address: 0x27c264, Func Offset: 0x964
	// Line 819, Address: 0x27c268, Func Offset: 0x968
	// Line 820, Address: 0x27c26c, Func Offset: 0x96c
	// Line 821, Address: 0x27c274, Func Offset: 0x974
	// Line 822, Address: 0x27c288, Func Offset: 0x988
	// Line 824, Address: 0x27c294, Func Offset: 0x994
	// Line 825, Address: 0x27c2a4, Func Offset: 0x9a4
	// Line 824, Address: 0x27c2ac, Func Offset: 0x9ac
	// Line 826, Address: 0x27c2b0, Func Offset: 0x9b0
	// Line 825, Address: 0x27c2b4, Func Offset: 0x9b4
	// Line 826, Address: 0x27c2c0, Func Offset: 0x9c0
	// Line 828, Address: 0x27c2c8, Func Offset: 0x9c8
	// Line 831, Address: 0x27c2f8, Func Offset: 0x9f8
	// Line 828, Address: 0x27c2fc, Func Offset: 0x9fc
	// Line 829, Address: 0x27c308, Func Offset: 0xa08
	// Line 831, Address: 0x27c310, Func Offset: 0xa10
	// Line 829, Address: 0x27c318, Func Offset: 0xa18
	// Line 831, Address: 0x27c31c, Func Offset: 0xa1c
	// Line 832, Address: 0x27c334, Func Offset: 0xa34
	// Line 833, Address: 0x27c350, Func Offset: 0xa50
	// Line 836, Address: 0x27c398, Func Offset: 0xa98
	// Line 837, Address: 0x27c3a0, Func Offset: 0xaa0
	// Line 838, Address: 0x27c3a8, Func Offset: 0xaa8
	// Line 842, Address: 0x27c3bc, Func Offset: 0xabc
	// Line 844, Address: 0x27c3c8, Func Offset: 0xac8
	// Line 845, Address: 0x27c3d4, Func Offset: 0xad4
	// Line 846, Address: 0x27c3e8, Func Offset: 0xae8
	// Line 847, Address: 0x27c3f0, Func Offset: 0xaf0
	// Line 846, Address: 0x27c3f4, Func Offset: 0xaf4
	// Line 847, Address: 0x27c3f8, Func Offset: 0xaf8
	// Line 848, Address: 0x27c3fc, Func Offset: 0xafc
	// Line 849, Address: 0x27c404, Func Offset: 0xb04
	// Line 850, Address: 0x27c418, Func Offset: 0xb18
	// Line 854, Address: 0x27c424, Func Offset: 0xb24
	// Line 857, Address: 0x27c46c, Func Offset: 0xb6c
	// Line 854, Address: 0x27c470, Func Offset: 0xb70
	// Line 855, Address: 0x27c47c, Func Offset: 0xb7c
	// Line 857, Address: 0x27c484, Func Offset: 0xb84
	// Line 855, Address: 0x27c48c, Func Offset: 0xb8c
	// Line 857, Address: 0x27c490, Func Offset: 0xb90
	// Line 858, Address: 0x27c4a8, Func Offset: 0xba8
	// Line 859, Address: 0x27c4c4, Func Offset: 0xbc4
	// Line 862, Address: 0x27c50c, Func Offset: 0xc0c
	// Line 863, Address: 0x27c514, Func Offset: 0xc14
	// Line 864, Address: 0x27c51c, Func Offset: 0xc1c
	// Line 867, Address: 0x27c52c, Func Offset: 0xc2c
	// Line 870, Address: 0x27c534, Func Offset: 0xc34
	// Line 872, Address: 0x27c540, Func Offset: 0xc40
	// Line 873, Address: 0x27c54c, Func Offset: 0xc4c
	// Line 874, Address: 0x27c560, Func Offset: 0xc60
	// Line 875, Address: 0x27c568, Func Offset: 0xc68
	// Line 874, Address: 0x27c56c, Func Offset: 0xc6c
	// Line 875, Address: 0x27c570, Func Offset: 0xc70
	// Line 876, Address: 0x27c574, Func Offset: 0xc74
	// Line 877, Address: 0x27c57c, Func Offset: 0xc7c
	// Line 878, Address: 0x27c590, Func Offset: 0xc90
	// Line 880, Address: 0x27c59c, Func Offset: 0xc9c
	// Line 881, Address: 0x27c5ac, Func Offset: 0xcac
	// Line 880, Address: 0x27c5b4, Func Offset: 0xcb4
	// Line 882, Address: 0x27c5b8, Func Offset: 0xcb8
	// Line 881, Address: 0x27c5bc, Func Offset: 0xcbc
	// Line 882, Address: 0x27c5c8, Func Offset: 0xcc8
	// Line 884, Address: 0x27c5d0, Func Offset: 0xcd0
	// Line 888, Address: 0x27c600, Func Offset: 0xd00
	// Line 884, Address: 0x27c604, Func Offset: 0xd04
	// Line 885, Address: 0x27c610, Func Offset: 0xd10
	// Line 886, Address: 0x27c618, Func Offset: 0xd18
	// Line 888, Address: 0x27c61c, Func Offset: 0xd1c
	// Line 885, Address: 0x27c624, Func Offset: 0xd24
	// Line 888, Address: 0x27c628, Func Offset: 0xd28
	// Line 889, Address: 0x27c638, Func Offset: 0xd38
	// Line 891, Address: 0x27c640, Func Offset: 0xd40
	// Line 892, Address: 0x27c654, Func Offset: 0xd54
	// Line 894, Address: 0x27c65c, Func Offset: 0xd5c
	// Line 897, Address: 0x27c6a4, Func Offset: 0xda4
	// Line 898, Address: 0x27c6ac, Func Offset: 0xdac
	// Line 899, Address: 0x27c6b4, Func Offset: 0xdb4
	// Line 903, Address: 0x27c6c8, Func Offset: 0xdc8
	// Line 905, Address: 0x27c6d4, Func Offset: 0xdd4
	// Line 906, Address: 0x27c6e0, Func Offset: 0xde0
	// Line 907, Address: 0x27c6f4, Func Offset: 0xdf4
	// Line 908, Address: 0x27c6fc, Func Offset: 0xdfc
	// Line 907, Address: 0x27c700, Func Offset: 0xe00
	// Line 908, Address: 0x27c704, Func Offset: 0xe04
	// Line 909, Address: 0x27c708, Func Offset: 0xe08
	// Line 910, Address: 0x27c710, Func Offset: 0xe10
	// Line 911, Address: 0x27c724, Func Offset: 0xe24
	// Line 915, Address: 0x27c730, Func Offset: 0xe30
	// Line 917, Address: 0x27c778, Func Offset: 0xe78
	// Line 915, Address: 0x27c77c, Func Offset: 0xe7c
	// Line 919, Address: 0x27c780, Func Offset: 0xe80
	// Line 915, Address: 0x27c784, Func Offset: 0xe84
	// Line 916, Address: 0x27c78c, Func Offset: 0xe8c
	// Line 919, Address: 0x27c798, Func Offset: 0xe98
	// Line 920, Address: 0x27c7b0, Func Offset: 0xeb0
	// Line 922, Address: 0x27c7b8, Func Offset: 0xeb8
	// Line 923, Address: 0x27c7cc, Func Offset: 0xecc
	// Line 925, Address: 0x27c7d4, Func Offset: 0xed4
	// Line 928, Address: 0x27c81c, Func Offset: 0xf1c
	// Line 929, Address: 0x27c824, Func Offset: 0xf24
	// Line 930, Address: 0x27c82c, Func Offset: 0xf2c
	// Line 936, Address: 0x27c840, Func Offset: 0xf40
	// Line 938, Address: 0x27c850, Func Offset: 0xf50
	// Line 939, Address: 0x27c858, Func Offset: 0xf58
	// Line 942, Address: 0x27c864, Func Offset: 0xf64
	// Line 940, Address: 0x27c868, Func Offset: 0xf68
	// Line 939, Address: 0x27c86c, Func Offset: 0xf6c
	// Line 940, Address: 0x27c870, Func Offset: 0xf70
	// Line 939, Address: 0x27c874, Func Offset: 0xf74
	// Line 940, Address: 0x27c878, Func Offset: 0xf78
	// Line 941, Address: 0x27c87c, Func Offset: 0xf7c
	// Line 940, Address: 0x27c884, Func Offset: 0xf84
	// Line 941, Address: 0x27c88c, Func Offset: 0xf8c
	// Line 942, Address: 0x27c894, Func Offset: 0xf94
	// Line 943, Address: 0x27c89c, Func Offset: 0xf9c
	// Line 945, Address: 0x27c8a8, Func Offset: 0xfa8
	// Line 946, Address: 0x27c8e0, Func Offset: 0xfe0
	// Line 947, Address: 0x27c904, Func Offset: 0x1004
	// Line 949, Address: 0x27c928, Func Offset: 0x1028
	// Func End, Address: 0x27c94c, Func Offset: 0x104c
	scePrintf("bhInitActiveCamera - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x27fd30
void bhControlPlEyeCamera(unsigned int attr)
{
	short ahkn;
	short ay;
	short ax;
	int ct;
	float hkn;
	//_anon21* ci;
	// Line 2123, Address: 0x27fd30, Func Offset: 0
	// Line 2130, Address: 0x27fd38, Func Offset: 0x8
	// Line 2132, Address: 0x27fd40, Func Offset: 0x10
	// Line 2130, Address: 0x27fd48, Func Offset: 0x18
	// Line 2132, Address: 0x27fd8c, Func Offset: 0x5c
	// Line 2137, Address: 0x27fd90, Func Offset: 0x60
	// Line 2130, Address: 0x27fd98, Func Offset: 0x68
	// Line 2132, Address: 0x27fd9c, Func Offset: 0x6c
	// Line 2138, Address: 0x27fda4, Func Offset: 0x74
	// Line 2132, Address: 0x27fda8, Func Offset: 0x78
	// Line 2136, Address: 0x27fdac, Func Offset: 0x7c
	// Line 2138, Address: 0x27fdb0, Func Offset: 0x80
	// Line 2136, Address: 0x27fdb8, Func Offset: 0x88
	// Line 2132, Address: 0x27fdbc, Func Offset: 0x8c
	// Line 2138, Address: 0x27fdc8, Func Offset: 0x98
	// Line 2140, Address: 0x27fdec, Func Offset: 0xbc
	// Line 2147, Address: 0x27fdf4, Func Offset: 0xc4
	// Line 2159, Address: 0x27fdf8, Func Offset: 0xc8
	// Line 2155, Address: 0x27fdfc, Func Offset: 0xcc
	// Line 2147, Address: 0x27fe04, Func Offset: 0xd4
	// Line 2140, Address: 0x27fe08, Func Offset: 0xd8
	// Line 2156, Address: 0x27fe10, Func Offset: 0xe0
	// Line 2159, Address: 0x27fe14, Func Offset: 0xe4
	// Line 2140, Address: 0x27fe18, Func Offset: 0xe8
	// Line 2144, Address: 0x27fe20, Func Offset: 0xf0
	// Line 2140, Address: 0x27fe24, Func Offset: 0xf4
	// Line 2141, Address: 0x27fe2c, Func Offset: 0xfc
	// Line 2142, Address: 0x27fe40, Func Offset: 0x110
	// Line 2143, Address: 0x27fe54, Func Offset: 0x124
	// Line 2144, Address: 0x27fe5c, Func Offset: 0x12c
	// Line 2145, Address: 0x27fe6c, Func Offset: 0x13c
	// Line 2147, Address: 0x27fe74, Func Offset: 0x144
	// Line 2148, Address: 0x27fe9c, Func Offset: 0x16c
	// Line 2149, Address: 0x27fec4, Func Offset: 0x194
	// Line 2155, Address: 0x27feec, Func Offset: 0x1bc
	// Line 2156, Address: 0x27fef4, Func Offset: 0x1c4
	// Line 2157, Address: 0x27fefc, Func Offset: 0x1cc
	// Line 2158, Address: 0x27ff04, Func Offset: 0x1d4
	// Line 2159, Address: 0x27ff0c, Func Offset: 0x1dc
	// Line 2160, Address: 0x27ff28, Func Offset: 0x1f8
	// Line 2159, Address: 0x27ff2c, Func Offset: 0x1fc
	// Line 2160, Address: 0x27ff3c, Func Offset: 0x20c
	// Line 2161, Address: 0x27ff40, Func Offset: 0x210
	// Line 2162, Address: 0x27ff48, Func Offset: 0x218
	// Line 2163, Address: 0x27ff50, Func Offset: 0x220
	// Line 2164, Address: 0x27ff6c, Func Offset: 0x23c
	// Line 2163, Address: 0x27ff70, Func Offset: 0x240
	// Line 2164, Address: 0x27ff80, Func Offset: 0x250
	// Line 2166, Address: 0x27ff84, Func Offset: 0x254
	// Line 2167, Address: 0x27ff8c, Func Offset: 0x25c
	// Line 2170, Address: 0x27ffb0, Func Offset: 0x280
	// Line 2168, Address: 0x27ffb4, Func Offset: 0x284
	// Line 2167, Address: 0x27ffb8, Func Offset: 0x288
	// Line 2170, Address: 0x27ffbc, Func Offset: 0x28c
	// Line 2167, Address: 0x27ffc0, Func Offset: 0x290
	// Line 2168, Address: 0x27ffcc, Func Offset: 0x29c
	// Line 2170, Address: 0x27ffd0, Func Offset: 0x2a0
	// Line 2174, Address: 0x27fff8, Func Offset: 0x2c8
	// Line 2175, Address: 0x28002c, Func Offset: 0x2fc
	// Line 2176, Address: 0x280040, Func Offset: 0x310
	// Line 2177, Address: 0x280054, Func Offset: 0x324
	// Line 2185, Address: 0x28005c, Func Offset: 0x32c
	// Line 2177, Address: 0x280060, Func Offset: 0x330
	// Line 2178, Address: 0x28006c, Func Offset: 0x33c
	// Line 2179, Address: 0x280080, Func Offset: 0x350
	// Line 2180, Address: 0x280094, Func Offset: 0x364
	// Line 2181, Address: 0x28009c, Func Offset: 0x36c
	// Line 2182, Address: 0x2800ac, Func Offset: 0x37c
	// Line 2183, Address: 0x2800b4, Func Offset: 0x384
	// Line 2184, Address: 0x2800c4, Func Offset: 0x394
	// Line 2185, Address: 0x2800d4, Func Offset: 0x3a4
	// Line 2187, Address: 0x2800d8, Func Offset: 0x3a8
	// Line 2189, Address: 0x2800e0, Func Offset: 0x3b0
	// Line 2190, Address: 0x2800e8, Func Offset: 0x3b8
	// Line 2191, Address: 0x2800fc, Func Offset: 0x3cc
	// Line 2192, Address: 0x280118, Func Offset: 0x3e8
	// Line 2194, Address: 0x280134, Func Offset: 0x404
	// Line 2195, Address: 0x280144, Func Offset: 0x414
	// Line 2204, Address: 0x28014c, Func Offset: 0x41c
	// Line 2195, Address: 0x280150, Func Offset: 0x420
	// Line 2196, Address: 0x28015c, Func Offset: 0x42c
	// Line 2197, Address: 0x280170, Func Offset: 0x440
	// Line 2199, Address: 0x280184, Func Offset: 0x454
	// Line 2200, Address: 0x28018c, Func Offset: 0x45c
	// Line 2201, Address: 0x2801b0, Func Offset: 0x480
	// Line 2202, Address: 0x2801b8, Func Offset: 0x488
	// Line 2203, Address: 0x2801c8, Func Offset: 0x498
	// Line 2204, Address: 0x2801cc, Func Offset: 0x49c
	// Line 2205, Address: 0x2801d4, Func Offset: 0x4a4
	// Line 2213, Address: 0x2801dc, Func Offset: 0x4ac
	// Line 2205, Address: 0x2801e0, Func Offset: 0x4b0
	// Line 2206, Address: 0x2801e4, Func Offset: 0x4b4
	// Line 2207, Address: 0x2801f0, Func Offset: 0x4c0
	// Line 2208, Address: 0x2801fc, Func Offset: 0x4cc
	// Line 2209, Address: 0x280208, Func Offset: 0x4d8
	// Line 2210, Address: 0x280214, Func Offset: 0x4e4
	// Line 2211, Address: 0x280220, Func Offset: 0x4f0
	// Line 2212, Address: 0x28022c, Func Offset: 0x4fc
	// Line 2213, Address: 0x280234, Func Offset: 0x504
	// Line 2214, Address: 0x28023c, Func Offset: 0x50c
	// Line 2215, Address: 0x280248, Func Offset: 0x518
	// Line 2217, Address: 0x28024c, Func Offset: 0x51c
	// Line 2220, Address: 0x280254, Func Offset: 0x524
	// Line 2230, Address: 0x280260, Func Offset: 0x530
	// Line 2220, Address: 0x280264, Func Offset: 0x534
	// Line 2230, Address: 0x280268, Func Offset: 0x538
	// Line 2220, Address: 0x28026c, Func Offset: 0x53c
	// Line 2221, Address: 0x28028c, Func Offset: 0x55c
	// Line 2222, Address: 0x2802b4, Func Offset: 0x584
	// Line 2228, Address: 0x2802dc, Func Offset: 0x5ac
	// Line 2229, Address: 0x2802e4, Func Offset: 0x5b4
	// Line 2230, Address: 0x2802ec, Func Offset: 0x5bc
	// Line 2231, Address: 0x280308, Func Offset: 0x5d8
	// Line 2230, Address: 0x28030c, Func Offset: 0x5dc
	// Line 2231, Address: 0x28031c, Func Offset: 0x5ec
	// Line 2232, Address: 0x280320, Func Offset: 0x5f0
	// Line 2233, Address: 0x280328, Func Offset: 0x5f8
	// Line 2234, Address: 0x280330, Func Offset: 0x600
	// Line 2235, Address: 0x28034c, Func Offset: 0x61c
	// Line 2234, Address: 0x280350, Func Offset: 0x620
	// Line 2235, Address: 0x280360, Func Offset: 0x630
	// Line 2237, Address: 0x280364, Func Offset: 0x634
	// Line 2238, Address: 0x28036c, Func Offset: 0x63c
	// Line 2241, Address: 0x280390, Func Offset: 0x660
	// Line 2239, Address: 0x280394, Func Offset: 0x664
	// Line 2238, Address: 0x280398, Func Offset: 0x668
	// Line 2241, Address: 0x28039c, Func Offset: 0x66c
	// Line 2238, Address: 0x2803a0, Func Offset: 0x670
	// Line 2239, Address: 0x2803ac, Func Offset: 0x67c
	// Line 2241, Address: 0x2803b0, Func Offset: 0x680
	// Line 2245, Address: 0x2803d8, Func Offset: 0x6a8
	// Line 2246, Address: 0x28040c, Func Offset: 0x6dc
	// Line 2247, Address: 0x280420, Func Offset: 0x6f0
	// Line 2248, Address: 0x280434, Func Offset: 0x704
	// Line 2256, Address: 0x28043c, Func Offset: 0x70c
	// Line 2248, Address: 0x280440, Func Offset: 0x710
	// Line 2249, Address: 0x280448, Func Offset: 0x718
	// Line 2250, Address: 0x280458, Func Offset: 0x728
	// Line 2251, Address: 0x280468, Func Offset: 0x738
	// Line 2252, Address: 0x280478, Func Offset: 0x748
	// Line 2253, Address: 0x280488, Func Offset: 0x758
	// Line 2254, Address: 0x280498, Func Offset: 0x768
	// Line 2255, Address: 0x2804a4, Func Offset: 0x774
	// Line 2256, Address: 0x2804b0, Func Offset: 0x780
	// Line 2260, Address: 0x2804c4, Func Offset: 0x794
	// Func End, Address: 0x2804d0, Func Offset: 0x7a0
	scePrintf("bhControlPlEyeCamera - UNIMPLEMENTED!\n");
}

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
    
    for (i = 0; i < rom->mdl.obj_num; i++)
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
