#include "game.h"
#include "main.h"

// 100% matching! 
void bhMainSequence()
{
    int i;

    if ((sys->cb_flg & 0x1)) 
    {
        bhStartDoorDemo();
    }
    
    if (sys->evt_tmd != 0) 
    {
        bhCheckEvtTimer();
    }
    
    for (i = 0; i < sys->loop_ct; i++)
    {
        sys->loop_now = i;
        
        if ((sys->cb_flg & 0x2)) 
        {
            bhControlScreenFade();
        }
            
        if (((sys->cb_flg & 0x4)) || (sys->cine_an)) 
        {
            bhControlCinesco();
        }
        
        bhControlEnemy();
        bhControlPlayer();
        bhControlEffect();
        bhControlObjItm();
            
        if (((sys->gm_flg & 0x40)) && ((sys->sp_flg & 0x40)) && (!(sys->st_flg & 0x1)))
        {
            bhSetPlEyeCamera();
        }
        
        bhControlCamera();
        bhControlLight();
            
        if (i == (sys->loop_ct - 1)) 
        {
            if ((sys->gm_flg & 0x200))
            {
                bhDrawSmallScreenRenderTexture();
            }
            
            if ((sys->gm_flg & 0x100)) 
            {
                bhDrawFullScreenRenderTexture();
            } 
            else 
            {
                bhAllDrawModel();
            }
            
            if ((sys->st_flg & 0x100)) 
            {
                sys->gm_flg |= 0x4000;
                
                njSetMatrix(cam.mtxb, cam.mtx);
                
                njMirror(cam.mtx, &sys->mr_pl);
                
                bhSetLight();
                
                bhEtcMirrorDrawModel();
                
                njSetMatrix(cam.mtx, cam.mtxb);
                
                sys->gm_flg &= ~0x4000;
            }
            
            if (sys->cine_an > 0) 
            {
                bhDrawCinesco();
            }
            
            if ((sys->st_flg & 0x800000)) 
            {
                bhDrawScope();
            }
            
            if ((sys->st_flg & 0x40000000))
            {
                bhDrawThermometer();
            }
            
            if (sys->fade_an > 0)
            {
                bhDrawScreenFade();
            }
        }
        
        if (((sys->st_flg & 0x200000)) && (!(sys->cb_flg & 0x1)))
        {
            sys->st_flg &= ~0x200080;
            
            if ((sys->cb_flg & 0x20000000))
            {
                sys->cb_flg |= 0x1000;
                
                sys->cb_flg &= ~0x20000000;
            }
            
            if (!(sys->cb_flg & 0x4))
            {
                sys->st_flg &= ~0x4;
            }
            
            sys->sp_flg = ~0x0;
            
            sys->pt_flg |= 0x3;
            
            if (!(sys->gm_flg & 0x20000)) 
            {
                sys->st_flg &= ~0x1;
                
                sys->gm_flg |= 0x800;
            }
            
            sys->pad_on = sys->pad_onb;
            sys->pad_ps = sys->pad_psb;
            sys->pad_old = sys->pad_oldb;
        }
        
        if (((sys->st_flg & 0x400000)) && (!(sys->cb_flg & 0x1))) 
        {
            if ((sys->cb_flg & 0x20000000)) 
            {
                sys->cb_flg |= 0x1000;
                
                sys->cb_flg &= ~0x20000000;
            }
            
            if ((sys->cb_flg & 0x200000)) 
            {
                sys->st_flg &= ~0x200;
            } 
            else 
            {
                sys->st_flg &= ~0x400200;
                
                if ((sys->st_flg & 0x2000)) 
                {
                    sys->sp_flg = ~0x0;
                    
                    sys->st_flg &= ~0x2200;
                    
                    if (!(sys->cb_flg & 0x4)) 
                    {
                        sys->st_flg &= ~0x4;
                    }
                    
                    sys->pad_on = sys->pad_onb;
                    sys->pad_ps = sys->pad_psb;
                    sys->pad_old = sys->pad_oldb;
                }
                
                if ((sys->st_flg & 0x80)) 
                {
                    sys->st_flg &= ~0x80;
                    
                    sys->pt_flg |= 0x3;
                    
                    if (!(sys->gm_flg & 0x20000))
                    {
                        sys->st_flg &= ~0x1;
                        
                        sys->gm_flg |= 0x800;
                    }
                }
            } 
        }
        
        if ((sys->cb_flg & 0x8)) 
        {
            sys->cb_flg &= ~0x8;
            
            sys->sp_flg = 0;
            
            sys->sp_flg |= 0x38;
            
            if (!(sys->exm_attr & 0x20)) 
            {
                sys->sp_flg |= 0x80;
            }
            
            if ((sys->exm_attr & 0x2)) 
            {
                sys->pt_flg &= ~0x1;
                
                rom->lgtp[1].flg &= ~0x2;
            }
            
            if ((sys->exm_attr & 0x4))
            {
                sys->pt_flg &= ~0x2;
            }
            
            if ((sys->exm_attr & 0x10)) 
            {
                sys->sp_flg |= 0x2;
            }
        }
        
        if ((sys->st_flg & 0x80))
        {
            if (((sys->gm_flg & 0x10000)) && ((sys->gm_flg & 0x20000))) 
            {
                sys->sp_flg |= 0x40;
            }
            
            if (((sys->pad_ps & 0x200)) && (!(sys->st_flg & 0x200))) 
            {
                sys->st_flg |= 0x200000;
            }
        }
        
        if ((sys->cb_flg & 0x20)) 
        {
            sys->cb_flg &= ~0x20;
            
            sys->sp_flg = 0;
            
            sys->sp_flg |= 0x30;
            
            if ((sys->st_flg & 0x80)) 
            {
                sys->sp_flg |= 0x8;
                
                if (!(sys->exm_attr & 0x20)) 
                {
                    sys->sp_flg |= 0x80;
                }
            }
            
            if ((sys->exm_attr & 0x10))
            {
                sys->sp_flg |= 0x2;
            }
        }
        
        if ((((sys->st_flg & 0x200)) && ((sys->st_flg & 0x4000)) && ((sys->st_flg & 0x1000))) && ((((sys->pad_ps & 0x800)) || ((sys->pad_ps & 0x1000))) || (((sys->cb_flg & 0x1000)) && (!(sys->cb_flg & 0x1)))))
        {
            sys->st_flg |= 0x400000;
            
            sys->cb_flg |= 0x2000;
            
            sys->cb_flg &= ~0x1000;
        }
        
        if ((sys->gm_flg & 0x1000))
        {
            if (!(sys->gm_flg & 0x10000)) 
            {
                bhSetFixedCut(sys->fixcno);
            } 
            else 
            {
                bhSetEventFixedCut(sys->fixcno, sys->fixkno);
            }
        }
        else if ((sys->gm_flg & 0x2000)) 
        {
            bhInitPlEyeCamera();
        }
        
        if (!(sys->gm_flg & 0x800))
        {
            bhCheckCut(0);
        }
        else 
        {
            bhCheckCut(1);
        }
        
        if (sys->loop_ct > 1) 
        {
            if ((sys->st_flg & 0x200)) 
            {
                if ((sys->ts_flg & 0x200)) 
                {
                    bhControlMessage(0);
                } 
                else
                {
                    bhControlMessage(1);
                }
            }
            
            bhControlEvent();
        }
    }
}

// 100% matching
void bhAllDrawModel()
{
    njControl3D(0x2500);
    njSetCheapShadowMode(0x80);
    njCnkSetEasyMultiAmbient(rom->amb_r[rom->amb_rom], rom->amb_g[rom->amb_rom], rom->amb_b[rom->amb_rom]);
    njCnkSetSimpleMultiAmbient(rom->amb_r[rom->amb_rom], rom->amb_g[rom->amb_rom], rom->amb_b[rom->amb_rom]);
    if ((rom->mdl.texP != 0) && !(sys->error & 2)) {
        njSetTexture(rom->mdl.texP);
    }
    njSetMatrix(0, cam.mtx);
    if ((rom->mdl.objP != 0) && (sys->pt_flg & 0x20)) {
        if (sys->gm_flg & 0x80) {
            njCnkEasyDrawObject(rom->mdl.objP);
        } else {
            njCnkEasyMultiDrawObject(rom->mdl.objP);
        }
    }
    njControl3D(0x2400);
    if ((sys->en_objn != 0) && (sys->pt_flg & 2)) {
        bhDrawEneObject();
    }
    if ((Ps2_albinoid_flag != 0) && (sys->pt_flg & 0x10)) {
        bhDrawEffect();
    }
    bhDrawObjItm();
    njControl3D(0x100);
    njCnkSetEasyMultiAmbient(rom->amb_r[rom->amb_chr], rom->amb_g[rom->amb_chr], rom->amb_b[rom->amb_chr]);
    njCnkSetSimpleMultiAmbient(rom->amb_r[rom->amb_chr], rom->amb_g[rom->amb_chr], rom->amb_b[rom->amb_chr]);
    if (Ps2_albinoid_flag == 0) {
        if (sys->pt_flg & 0x10) {
            bhDrawEffect();
        }
    }
    njControl3D(0);
    bhSetHalfLight();
    if (sys->pt_flg & 2) {
        bhDrawEnemy();
    }
    njControl3D(0);
    if (((sys->pt_flg & 1) && !(plp->stflg & 0x01000000)) || ((plp->stflg & 0x01000000) && (pl_sleep_cnt != 0))) {
        if (pl_sleep_cnt != 0) {
            pl_sleep_cnt -= 1;
        }
        if (!(plp->mdflg & 1)) {
            if (!(plp->mdflg & 0x20)) {
                if (bhCheckClipModel(plp) == 0) {
                    bhPutModel(plp);
                }
            } else {
                bhPutModel(plp);
            }
        }
    }
    if ((rom->mdl.texP != 0) && !(sys->error & 2)) {
        njSetTexture(rom->mdl.texP);
    }
    njSetMatrix(0, cam.mtx);
    njControl3D(0x2400);
    bhDrawGeneralPurposeWater();
    njControl3D(0);
}

// 100% matching
void bhAllEasyDrawModel()
{
    njControl3D(0x18100);
    njSetCnkBlendMode(0);
    njCnkSetEasyMultiAmbient(rom->amb_r[rom->amb_rom], rom->amb_g[rom->amb_rom], rom->amb_b[rom->amb_rom]);
    njCnkSetSimpleMultiAmbient(rom->amb_r[rom->amb_rom], rom->amb_g[rom->amb_rom], rom->amb_b[rom->amb_rom]);
    if ((rom->mdl.texP != 0) && !(sys->error & 2)) {
        njSetTexture(rom->mdl.texP);
    }
    njSetMatrix(0, cam.mtx);
    if ((rom->mdl.objP != 0) && (sys->pt_flg & 0x20)) {
        if (sys->gm_flg & 0x80) {
            njCnkEasyDrawObject(rom->mdl.objP);
        } else {
            njCnkEasyMultiDrawObject(rom->mdl.objP); 
        }
    }
    bhDrawObjItm();
    njControl3D(0x10000);
    if (sys->pt_flg & 0x2) {
        bhDrawEnemy();
    }
}

// 100% matching
void bhEtcMirrorDrawModel()
{
    bhSetHideObject(4);
    njControl3D(0x12500);
    njSetCheapShadowMode(0x80);
    njCnkSetEasyMultiAmbient(rom->amb_r[rom->amb_rom], rom->amb_g[rom->amb_rom], rom->amb_b[rom->amb_rom]);
    njCnkSetSimpleMultiAmbient(rom->amb_r[rom->amb_rom], rom->amb_g[rom->amb_rom], rom->amb_b[rom->amb_rom]);
    if ((rom->mdl.texP != 0) && !(sys->error & 2)) {
        njSetTexture(rom->mdl.texP);
    }
    njSetMatrix(0, cam.mtx);
    if ((rom->mdl.objP != 0) && (sys->pt_flg & 0x20)) {
        if (sys->gm_flg & 0x80) {
            njCnkEasyDrawObject(rom->mdl.objP);
        } else {
            njCnkEasyMultiDrawObject(rom->mdl.objP); 
        }
    }
    bhSetHideObject(0);
    njControl3D(0x100);
    if (sys->pt_flg & 0x10) {
        bhDrawEffect();
    }
}
