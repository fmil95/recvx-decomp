#include "../../../ps2/veronica/prog/room.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/binfunc.h"
#include "../../../ps2/veronica/prog/camera.h"
#include "../../../ps2/veronica/prog/dread.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/face.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/light.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/objitm.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/screen.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/system.h"
#include "../../../ps2/veronica/prog/main.h"

// 100% matching! 
void bhInitRoom()
{
    npSetMemory((unsigned char*)rom, sizeof(ROM_WORK), 0);
}

// 100% matching! 
void bhInitReadRDT()
{
    sys->gm_flg |= 0x2;
    
    bhInitRoomChangeSystem();
    bhInitCamera();
    bhInitEnemy();
    bhInitRoom();
    
    bhClearEffect();
}

// 100% matching! 
void bhSetRDT()
{
    bhSetRoom();
}

// 99.97% matching
void bhSetRoom()
{
    RDT_WORK* rh;          
    CUT_WORK* cp;         
    ETTY_WORK* ep;      
    EF_WRK* efp;          
    BH_PWORK* pwp;        
    O_WRK* owp;           
    int i;                
    int j;                 
    int k;                
    int nbTex;             
    unsigned int nbt;      
    unsigned int* mdlhed; 
    unsigned int* texhed; 
    unsigned int* romp;   
    unsigned char* datp;  
    unsigned char* reladr; 
    unsigned char* texdat; // not from the debugging symbols
    
    reladr = sys->rdtp;
    
    if (*(float*)&*reladr < 1.72f) 
    {
        sys->error |= 0x1;
        return;
    }
    
    njMemCopy(rom, &reladr[*(unsigned int*)(reladr + 16)], 1004);
    
    for (romp = (unsigned int*)rom; (unsigned int)romp < (unsigned int)&rom->dmp00; romp++) 
    {
        *romp = (unsigned int)sys->rdtp + *romp;
    }
    
    cp = rom->cutp;
    
    for (i = 0; i < rom->cut_n; i++, cp++)
    {
        cp->cuttp = (CUT_WRK*)&sys->rdtp[*(unsigned int*)&cp->cuttp];
    }
    
    rom->grand[31] = 0;
    
    datp = &sys->rdtp[*(unsigned int*)(reladr + 20)];
    
    npSetMemory((unsigned char*)&rom->mdl, sizeof(ML_WORK), 0);
    
    mdlhed = (unsigned int*)&sys->rdtp[*(unsigned int*)datp];
    
    datp += 4;
    
    bhMlbBinRealize(mdlhed, &rom->mdl); 
    
    npCnkFlatOff(rom->mdl.objP);
    
    for (i = 0; i < 100; i++) 
    {
        for (j = 0; j < 16; j++) 
        {
            for (k = 0; k < 16; k++) 
            {
                sys->et_lp[i][j][k] = NULL;
            }
        }
    } 
    
    ep = rom->enep;
    
    for (i = 0; i < rom->ene_n; i++, ep++) 
    {
        if ((ep->flg & 0x1)) 
        {
            mdlhed = (unsigned int*)&sys->rdtp[*(unsigned int*)datp];
            
            datp += 4;
            
            bhSetEneMdl((unsigned char*)mdlhed, ep, ep->mdlver, i);
        }
    }
    
    ep = &rom->objp[4];
    
    for (i = 4; i < rom->obj_n; i++, ep++)
    {
        mdlhed = (unsigned int*)&sys->rdtp[*(unsigned int*)datp];
        
        datp += 4;
        
        bhSetObjMdl((unsigned char*)mdlhed, ep, ep->id, i);
    }
    
    ep = rom->itmp;
    
    for (i = 0; i < rom->itm_n; i++, ep++) 
    {
        mdlhed = (unsigned int*)&sys->rdtp[*(unsigned int*)datp];
        
        datp += 4;
        
        bhSetItmMdl((unsigned char*)mdlhed, ep, ep->id, i); 
    }

    reladr += 28;
    
    rom->evtp = (EVT_WORK*)&sys->rdtp[*(unsigned int*)reladr];
    
    sys->txr_ct = 0;
    sys->txr_n = 0;

    reladr += 4;

    texdat = &sys->rdtp[*(unsigned int*)reladr];
    
    nbt = *(unsigned int*)texdat;
    
    reladr = texdat;
    
    texhed = (unsigned int*)&sys->rdtp[*(unsigned int*)(texdat + 4)];
    
    texdat += 8;
    
    if (rom->mdl.texP != NULL) 
    {
        sys->txlp[sys->txr_n] = rom->mdl.texP;
        sys->txdp[sys->txr_n] = (unsigned char*)texhed;
        
        sys->txloff[sys->txr_n] = 0;
        
        sys->txr_n++;
    }
    
    nbt--;
    
    pwp = ene;
    
    for (i = 0; i < rom->ene_n; i++, pwp++)
    {
        for (j = 0; j < pwp->mdl_n; j++)
        {
            if ((pwp->mdl[j].texP != NULL) && ((pwp->mdl[j].flg & 0x200)))
            {
                nbt--;
                
                texhed = (unsigned int*)&sys->rdtp[*(unsigned int*)texdat];
                
                texdat += 4;
                
                sys->txlp[sys->txr_n] = pwp->mdl[j].texP;
                sys->txdp[sys->txr_n] = (unsigned char*)texhed;
                
                sys->txloff[sys->txr_n] = 0;
                
                sys->txr_n++;
            }
        }
    }
    
    for (i = 0; i < 1300; i++) 
    {
        sys->ot_lp[i] = NULL;
    } 
    
    owp = &sys->obwp[4];
    
    for (i = 4; i < rom->obj_n; i++, owp++)
    {
        if (owp->mlwP->texP != NULL)
        {
            if (sys->ot_lp[owp->id] == NULL) 
            {
                nbt--;
                
                owp->mlwP->flg |= 0x200;
                
                sys->ot_lp[owp->id] = owp->mlwP->texP;
                
                texhed = (unsigned int*)&sys->rdtp[*(unsigned int*)texdat];
                
                texdat += 4;
                
                sys->txlp[sys->txr_n] = owp->mlwP->texP;
                sys->txdp[sys->txr_n] = (unsigned char*)texhed;
                
                sys->txloff[sys->txr_n] = 0;
                
                sys->txr_n++;
            } 
            else 
            {
                owp->mlwP->flg &= ~0x200;
                
                owp->mlwP->texP = sys->ot_lp[owp->id];
            }
        }
    }
    
    for (i = 0; i < 200; i++) 
    {
        sys->it_lp[i] = NULL;
    } 
    
    owp = sys->itwp;
    
    for (i = 0; i < rom->itm_n; i++, owp++) 
    {
        if (owp->mlwP->texP != NULL)
        {
            if (sys->it_lp[owp->id] == NULL) 
            {
                nbt--;
                
                owp->mlwP->flg |= 0x200;
                
                sys->it_lp[owp->id] = owp->mlwP->texP;
                
                texhed = (unsigned int*)&sys->rdtp[*(unsigned int*)texdat];
                
                texdat += 4;
                
                sys->txlp[sys->txr_n] = owp->mlwP->texP;
                sys->txdp[sys->txr_n] = (unsigned char*)texhed; 
                
                sys->txloff[sys->txr_n] = 0;
                
                sys->txr_n++;
            } 
            else 
            {
                owp->mlwP->flg &= ~0x200;
                
                owp->mlwP->texP = sys->it_lp[owp->id];
            }
        }
    }
    
    efp = rom->effp;
    
    for (i = 0; i < rom->eff_n; i++, efp++)
    {
        if (((efp->id >= 30) && (efp->id < 100)) || (efp->id >= 400))
        {
            sys->efm[efp->id].flg &= ~0x200;
        }
    }
    
    efp = rom->effp;
    
    for (i = 30; i < 100; i++)
    {
        sys->ef_tn[i] = 0;
    } 
    
    for (i = 400; i < 450; i++) 
    {
        sys->ef_tn[i] = 0;
    } 
    
    for (i = 0; i < rom->eff_n; i++, efp++)
    {
        if ((((efp->id >= 30) && (efp->id < 100)) || (efp->id >= 400)) && (!(sys->efm[efp->id].flg & 0x200))) 
        {
            sys->efm[efp->id].flg |= 0x200;
            
            texhed = (unsigned int*)&sys->rdtp[*(unsigned int*)texdat];
            
            texdat += 4;
            
            nbTex = bhSetMemPvpTexture(&sys->ef_tlist, (unsigned char*)texhed, sys->ef_ct);
            
            nbt--;
            
            sys->ef_extn += nbTex;
            
            sys->efm[efp->id].obj_num = sys->ef_ct;
            
            sys->ef_tn[efp->id] = sys->ef_ct;
            
            sys->ef_ct += nbTex;
            
            sys->ef_tlist.nbTexture = sys->ef_ct;
            
            sys->ef_pbkb[efp->id] = *(unsigned char*)(sys->ef_tlist.textures[sys->ef_tn[efp->id]].texaddr + 4);
        }
    }
    
    sys->memp = reladr;
}

// 100% matching!
void bhFinishRoom()
{
    BH_PWORK* pwp; 
    O_WRK* owp; 
    RDT_WORK* rh; 
    int i; 
    int j; 
    unsigned int* mtnhed; 
    unsigned char* datp; 

    rh = (RDT_WORK*)sys->rdtp;

    for (i = 0; i < 128; i++)
    {
        sys->emtp[i] = NULL;
    }
    
    mtnhed = (unsigned int*)&sys->rdtp[rh->hed02];
    
    pwp = ene;
    
    sys->en_flg[3] = 0;
    sys->en_flg[2] = 0;
    sys->en_flg[1] = 0;
    sys->en_flg[0] = 0;
    
    for (i = 0; i < rom->ene_n; i++, pwp++) 
    {
        if (*mtnhed != 0) 
        {
            bhStFlg(sys->en_flg, pwp->id);
            
            bhSetEneMtn(&sys->rdtp[*mtnhed++], pwp, pwp->id);
        }
        else 
        {
            if (sys->emtp[pwp->id] != NULL) 
            {
                pwp->mnwP = sys->emtp[pwp->id];
                pwp->mnwPb = pwp->mnwP;
            }
            else 
            {
                sys->memp = (unsigned char*)(((int)sys->memp + 7) & ~0x7);
                
                pwp->mnwP = (MN_WORK*)sys->memp;
                
                sys->memp += 12288;
                
                npSetMemory((unsigned char*)pwp->mnwP, 12288, 0);
                
                pwp->mnwPb = pwp->mnwP;
                
                sys->emtp[pwp->id] = pwp->mnwP;
            }
            
            mtnhed++;
        }
    }
    
    if (*mtnhed != 0) 
    {
        bhSetRoomMtn(&sys->rdtp[*mtnhed++]);
    }
    else 
    {
        sys->memp = (unsigned char*)(((int)sys->memp + 0x7) & ~0x7);
        
        sys->rmthp = (MN_WORK*)sys->memp;
        
        mtnhed++;
        
        npSetMemory((unsigned char*)sys->rmthp, 12288, 0);
        
        sys->memp += 12288;
    }
    
    if (*mtnhed != 0) 
    {
        sys->mspp = &sys->rdtp[*mtnhed++];
    }
    else
    {
        mtnhed++;
        
        sys->mspp = NULL;
    }
    
    if (*mtnhed != 0) 
    {
        sys->lspp = &sys->rdtp[*mtnhed++];
    }
    else 
    {
        mtnhed++;
        
        sys->lspp = NULL;
    }
    
    pwp = ene;
    
    for (i = 0; i < rom->ene_n; i++, pwp++) 
    {
        for (j = 0; j < pwp->mdl_n; j++)
        {
            sys->memp = bhKeepObjWork(&pwp->mdl[j], sys->memp);
            
            bhCalcModel(pwp);
        }
        
        if (pwp->id > 90) 
        {
            bhInitMask(pwp);
        }
    }

    owp = sys->obwp + 4;
    
    for (i = 4; i < rom->obj_n; i++, owp++) 
    {
        sys->memp = bhKeepObjWork(owp->mlwP, sys->memp);   
    } 
    
    owp = sys->itwp;
    
    for (i = 0; i < rom->itm_n; i++, owp++) 
    {
        sys->memp = bhKeepObjWork(owp->mlwP, sys->memp);
    }
    
    bhInitLight();
    
    bhSetEffectTable();
    
    sys->gm_flg &= ~(0x8 | 0x1);
    
    sys->pad_on &= ~(0x8 | 0x4 | 0x2 | 0x1);
    
    bhResetAtariAttr();
    
    if ((sys->cb_flg & 0x800000)) 
    {
        sys->cb_flg &= ~0x800000;
        
        plp->flr_no = sys->flr_no;
        
        plp->stflg = sys->ply_stflg[sys->ply_id];
        
        plp->stflg |= 0x40000000;
        
        plp->px = plp->gpx = ((EXP_WORK*)plp->exp0)->spx = ((EXP_WORK*)plp->exp0)->plx = sys->ply_pos.x;
        plp->py = plp->gpy = ((EXP_WORK*)plp->exp0)->spy = ((EXP_WORK*)plp->exp0)->ply = sys->ply_pos.y;
        plp->pz = plp->gpz = ((EXP_WORK*)plp->exp0)->spz = ((EXP_WORK*)plp->exp0)->plz = sys->ply_pos.z;
        
        ((EXP_WORK*)plp->exp0)->bpx = ((EXP_WORK*)plp->exp0)->bpxb = plp->px;
        ((EXP_WORK*)plp->exp0)->bpy = ((EXP_WORK*)plp->exp0)->bpyb = plp->py + 12.5f;
        ((EXP_WORK*)plp->exp0)->bpz = ((EXP_WORK*)plp->exp0)->bpzb = plp->pz;
        
        plp->ay = sys->ply_ang;
        
        plp->wpnr_no = sys->ply_wno[sys->ply_id];
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        ((EXP_WORK*)plp->exp0)->arn = 0;
    }
    else if (rom->pos_n != 0)
    {
        plp->px = plp->gpx = ((EXP_WORK*)plp->exp0)->spx = ((EXP_WORK*)plp->exp0)->plx = rom->posp[sys->pos_no].px;
        plp->py = plp->gpy = ((EXP_WORK*)plp->exp0)->spy = ((EXP_WORK*)plp->exp0)->ply = rom->posp[sys->pos_no].py;
        plp->pz = plp->gpz = ((EXP_WORK*)plp->exp0)->spz = ((EXP_WORK*)plp->exp0)->plz = rom->posp[sys->pos_no].pz;
        
        ((EXP_WORK*)plp->exp0)->bpx = ((EXP_WORK*)plp->exp0)->bpxb = plp->px;
        ((EXP_WORK*)plp->exp0)->bpy = ((EXP_WORK*)plp->exp0)->bpyb = plp->py + 12.5f;
        ((EXP_WORK*)plp->exp0)->bpz = ((EXP_WORK*)plp->exp0)->bpzb = plp->pz;
        
        plp->ay = rom->posp[sys->pos_no].ay;
        
        bhSetFloorNum(plp);
        
        plp->py = plp->gpy = rom->grand[plp->flr_no + 2];
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        ((EXP_WORK*)plp->exp0)->arn = 0;
    }
    
    if ((sys->ss_flg & 0x100)) 
    {
        sys->fade_an = 255.0f;
        
        sys->fade_rn = 0;
        sys->fade_gn = 0;
        sys->fade_bn = 0;
        
        bhSetScreenFade(0, 10.0f);
        
        sys->sp_flg = 0xFFFFFFFF;
        
        sys->ss_flg &= ~0x100;
        
        pwp = plp;
        
        *(unsigned int*)&pwp->mode0 = 0;
    } 
    else 
    {
        bhInitRoomChangePlayer();
    }
    
    sys->sp_flg = 0xFFFFFFFF;
    
    sys->gm_flg |= 0x800;
    
    sys->stg_nob = sys->stg_no;
    sys->rom_nob = sys->rom_no;
    sys->pos_nob = sys->pos_no;
    
    sys->rcase_b = sys->rcase;
    
    sys->ts_flg |= 0x180;
}

// 100% matching!
void bhSetEneMdl(unsigned char* datp, ETTY_WORK* ep, int mdlno, int eno) 
{
    BH_PWORK* epp;       
    int dt;               
    int mdlver;           
    unsigned char* emdlp; 

    emdlp = datp;
    
    epp = bhSetEnemy((EGG_WORK*)ep, eno);
    
    epp->mlwP = (ML_WORK*)&epp->mdl;
    
    mdlver = -1;
    
    epp->mdl_n = 0;
    
    while ((dt = *(unsigned int*)emdlp) != -1) 
    {
        if (dt != 0)
        {
            emdlp += 4;
            
            switch (*(unsigned int*)emdlp) 
            {                     
            case 0x4B53414D:
                epp->mskp = emdlp;
                break;
            case SKIN_MAGIC:
                epp->skp[epp->mdl_n] = (int*)&emdlp[4];
                break;
            default:
                npSetMemory((unsigned char*)epp->mlwP, sizeof(ML_WORK), 0);
                
                bhMlbBinRealize(emdlp, epp->mlwP);
                
                if (epp->skp[epp->mdl_n] != NULL) 
                {
                    npSkinConvert(epp->mlwP->objP, epp->skp[epp->mdl_n]);
                }
                
                epp->mbp[epp->mdl_n] = epp->mlwP->objP;
                epp->txp[epp->mdl_n] = epp->mlwP->texP;
                
                if (epp->mlwP->texP != NULL) 
                {
                    mdlver++;
                    
                    if (sys->et_lp[ep->id][mdlno][mdlver] == 0) 
                    {
                        epp->mlwP->flg |= 0x200;
                        
                        sys->et_lp[ep->id][mdlno][mdlver] = epp->mlwP->texP;
                    } 
                    else
                    {
                        epp->mlwP->flg &= ~0x200;
                        
                        epp->mlwP->texP = sys->et_lp[ep->id][mdlno][mdlver];
                    }
                } 
                else
                {
                    epp->mlwP->flg &= ~0x200;
                    
                    if (mdlver >= 0) 
                    {
                        epp->mlwP->texP = sys->et_lp[ep->id][mdlno][mdlver];
                    }
                }
                
                epp->mdl_n++;
                epp->mlwP++;
                break;
            }
            
            emdlp = &emdlp[dt];
        }
        else 
        {
            emdlp += 4;
        }
    }
    
    epp->mlwP = epp->mdl;
}

// 100% matching! 
void bhSetEneMtn(unsigned char* datp, BH_PWORK* ep, int id)
{
    MN_WORK* mtnp;    
    int sz;          
    int mno;             
    unsigned char* emtnp; 
    unsigned int* memp; // not from the debugging symbols

    memp = (unsigned int*)&sys->memp;
    
    *memp = (*memp + 7) & ~0x7;
    
    ep->mnwP = (MN_WORK*)sys->memp;
    ep->mnwPb = ep->mnwP;
    
    mtnp = ep->mnwP;
    
    sys->memp += sizeof(MN_WORK) * 512;
    
    npSetMemory((unsigned char*)ep->mnwP, sizeof(MN_WORK) * 512, 0);
    
    sys->emtp[id] = ep->mnwP;
    
    for (mno = 0; (sz = *(unsigned int*)datp) != -1; mtnp++, mno++)
    {
        if (sz != 0)
        {
            datp += 4;
            
            bhMnbBinRealize(datp, mtnp);
            
            datp = &datp[sz];
        }
        else 
        {
            datp += 4;
        }
    }
}

// 100% matching!
void bhSetRoomMtn(unsigned char* datp)
{
    MN_WORK* mtnp;    
    int sz;          
    int mno;             
    unsigned char* emtnp; 
    unsigned int* memp; // not from the debugging symbols

    memp = (unsigned int*)&sys->memp;
    
    *memp = (*memp + 7) & ~0x7;
    
    sys->rmthp = (MN_WORK*)sys->memp;
    
    mtnp = sys->rmthp;
    
    sys->memp += sizeof(MN_WORK) * 512;
    
    npSetMemory((unsigned char*)sys->rmthp, sizeof(MN_WORK) * 512, 0);
    
    for (mno = 0; (sz = *(unsigned int*)datp) != -1; mtnp++, mno++)
    {
        if (sz != 0)
        {
            datp += 4;
            
            bhMnbBinRealize(datp, mtnp);
            
            datp = &datp[sz];
        }
        else 
        {
            datp += 4;
        }
    }
}

// 96.70% matching (matches on GC)
void bhSetObjMdl(unsigned char* datp, ETTY_WORK* ep, int mdlno, int eno) // third parameter is not present on the debugging symbols
{
    O_WRK* epp;
    int sz;

    epp = bhSetObject(ep, eno, NULL);
    
    if (epp != NULL)
    {
        npSetMemory((unsigned char*)epp->mdl, sizeof(O_WRK) / 50, 0);
        
        if (((unsigned char*)datp[0] == (unsigned char*)'M') && ((unsigned char*)datp[1] == (unsigned char*)'D') && ((unsigned char*)datp[2] == (unsigned char*)'L')) 
        {
            bhMlbBinRealize(datp, epp->mdl);
        }
        else 
        {
            sz = *(unsigned int*)datp;
            
            epp->skp[0] = (int*)&datp[8];
            
            datp += sz + 8;
            
            bhMlbBinRealize(datp, epp->mdl);
            
            npSkinConvert(epp->mdl->objP, epp->skp[0]);
        }
        
        epp->mlwP = epp->mdl;
    }
}

// 93.40% matching (matches on GC)
void bhSetItmMdl(unsigned char* datp, ETTY_WORK* ep, int mdlno, int eno) // third parameter is not present on the debugging symbols
{
    O_WRK* epp;

    epp = bhSetItem(ep, eno, NULL);
    
    if (epp != NULL) 
    {
        npSetMemory((unsigned char*)epp->mdl, sizeof(O_WRK) / 50, 0);
        
        bhMlbBinRealize(datp, epp->mdl);
        
        epp->mlwP = epp->mdl;
    }
}

// 100% matching!
void bhSetEffectTable()
{
    EF_WRK* ep; 
    int i;      
    
    ep = rom->effp;
    
    for (i = 0; i < rom->eff_n; i++, ep++) 
    {
        sys->efid[i] = bhSetEffectTb((EF_WORK*)ep, NULL, NULL, 0);
        
        bhSetEffectLink(ep, i);
    }
}

// 100% matching! 
void bhSetEffectLink(EF_WRK* efp, int efid)
{
    BH_PWORK* pwp;
    O_WRK* op;
    
    switch (efp->lkflg)
    {
    case 0:
        efp->lz = 0;
        efp->ly = 0;
        efp->lx = 0;
        break;
    case 1:
        efp->lkno = 0;
        
        pwp = plp;
        break;
    case 2:
        if (rom->ene_n <= efp->lkno)
        {
            efp->lkno = 0;
        }
        
        pwp = &ene[efp->lkno];
        break;
    case 3:
        if (rom->obj_n <= efp->lkno)
        {
            efp->lkno = 0;
        }
        
        pwp = (BH_PWORK*)&sys->obwp[efp->lkno];
        break;
    case 4:
        if (rom->itm_n <= efp->lkno)
        {
            efp->lkno = 0;
        }
        
        pwp = (BH_PWORK*)&sys->itwp[efp->lkno];
        break;
    case 5:
        if (rom->eff_n <= efp->lkno)
        {
            efp->lkno = 0;
        }
        
        pwp = (BH_PWORK*)&eff[sys->efid[efp->lkno]];
        break;
    }
    
    op = &eff[sys->efid[efid]]; 
    
    if (efp->lkflg != 0) 
    {
        if (!(pwp->flg & 0x1))
        {
            op->flg &= ~0x80;
        }
        else
        {
            op->flg |= 0x80;
            
            op->lkwkp = (unsigned char*)pwp;
            
            if (pwp->mlwP->obj_num <= efp->lkono)
            {
                efp->lkono = 0;
            }
            
            op->lkono = efp->lkono;
            
            op->lox = efp->lx;
            op->loy = efp->ly;
            op->loz = efp->lz; 
            
            if (efp->lkono == 0)
            {
                njCalcPoint(pwp->mtx, (NJS_POINT3*)&efp->lx, (NJS_POINT3*)&efp->px);
            }
            else
            {
                njCalcPoint((NJS_MATRIX*)pwp->mlwP->owP[efp->lkono].mtx, (NJS_POINT3*)&efp->lx, (NJS_POINT3*)&efp->px);
            }
        }
    }
    else 
    {
        op->flg &= ~0x80;
        
        op->lkono = efp->lkono;
    }
}

// 100% matching!
void bhSetDoorDemo(unsigned int attr, int stg_no, int rom_no, unsigned int pos_no, unsigned int dor_tp) 
{
    int etmf; 

    if ((sys->sp_flg & 0x200)) 
    {
        etmf = 1;
    } 
    else 
    {
        etmf = 0;
    }
    
    sys->sp_flg = 0;
    
    sys->sp_flg |= 0x48;
    
    if (etmf != 0) 
    {
        sys->sp_flg |= 0x200;
    }
    
    plp->stflg |= 0x80010000;
    
    sys->cb_flg |= 0x1;
    sys->st_flg &= ~0x400200;

    sys->ddmd = 0;
    
    sys->door.flg = attr;
    
    sys->door.stg_no = stg_no;
    sys->door.rom_no = rom_no;
    sys->door.pos_no = pos_no;
    
    sys->door.dor_tp = dor_tp;
    
    if (((sys->gm_flg & 0x40)) && ((sys->st_flg & 0x800000))) 
    {
        sys->gm_flg &= ~0x40;
        
        if (!(sys->gm_flg & 0x1000000)) 
        {
            sys->gm_flg &= ~0x80;
        }
        
        if ((sys->st_flg & 0x800000))
        {
            sys->st_flg &= ~0x800000;
            sys->gm_flg &= ~0x80000;
            
            sys->pt_flg |= 0x1;
        }
    }
}

// 100% matching!
void bhStartDoorDemo()
{
    DOOR_WORK* ddp;
    int etmf;
	
    ddp = &sys->door;
    
    switch (sys->ddmd)
    {                
    case 0:
        bhSetScreenFade(0xFF000000, 10.0f);
        
        SendSoundCommand(2);
        
        *(int*)&sys->door.mode0 = 0;
        
        sys->door.ct0 = 0;
        sys->door.ct1 = 0;
        sys->door.ct2 = 0;
        sys->door.ct3 = 0;
        
        sys->ts_flg |= 0x100000;
        sys->ts_flg &= ~0x800;
        
        if ((sys->sp_flg & 0x200)) 
        {
            etmf = 1;
        } 
        else 
        {
            etmf = 0;
        }
        
        sys->sp_flg = 0;
        
        sys->sp_flg |= 0x48;
        
        if (etmf != 0) 
        {
            sys->sp_flg |= 0x200;
        }
        
        sys->pad_ps = 0;
        sys->pad_on = 0;
        
        sys->ef_ct = sys->ef_ctb;
        
        sys->error = 0;
        
        sys->stg_no = ddp->stg_no;
        sys->rom_no = ddp->rom_no;
        sys->pos_no = ddp->pos_no;
        
        *(int*)&sys->mn_mode0 = 2;
        
        sys->ddmd = 1;
        break;
    case 1:
        if ((sys->ts_flg & 0x800)) 
        {
            bhSetScreenFade(0, 5.0f);
            
            sys->fade_pbk = 0;
            
            sys->cb_flg &= ~0x1;
            
            sys->sp_flg = -1;
            
            bhCheckCut(1);
        }
        
        break;
    }
}

// 100% matching!
void bhPushGameData()
{
    sys->version = 10;
    
    sys->flr_no = plp->flr_no;
    
    sys->ply_stflg[sys->ply_id] = plp->stflg & 0x78280000;
    
    sys->ply_pos.x = plp->px;
    sys->ply_pos.y = plp->py;
    sys->ply_pos.z = plp->pz;
    
    sys->ply_ang = plp->ay;
    
    sys->ply_wno[sys->ply_id] = plp->wpnr_no;
    sys->ply_hp[sys->ply_id] = plp->hp;
    
    npCopyMemory(freemem, (unsigned char*)&sys->version, (int)&sys->save_end - (int)&sys->version);
}

// 100% matching!
void bhPopGameData()
{
    sys->ss_flg |= 0x20000;
    
    bhExitGame();
    
    npCopyMemory((unsigned char*)&sys->version, freemem, (int)&sys->save_end - (int)&sys->version);
    
    if (sys->retry_ct < 99) 
    {
        sys->retry_ct++;
    }
    
    sys->gm_flg |= 0x2;
    sys->ss_flg |= 0x200;
    
    sys->tk_flg = 0x300020;
    sys->ts_flg = 0;
    
    sys->ss_flg &= ~0x20000;
}
