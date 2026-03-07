#include "room.h"
#include "MdlPut.h"
#include "binfunc.h"
#include "camera.h"
#include "dread.h"
#include "effect.h"
#include "eneset.h"
#include "face.h"
#include "flag.h"
#include "hitchk.h"
#include "light.h"
#include "njplus.h"
#include "objitm.h"
#include "player.h"
#include "pwksub.h"
#include "screen.h"
#include "system.h"
#include "main.h"

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

/*// 
// Start address: 0x289cb0
void bhSetDoorDemo(unsigned int attr, int stg_no, int rom_no, unsigned int pos_no, unsigned int dor_tp)
{
	int etmf;
	// Line 937, Address: 0x289cb0, Func Offset: 0
	// Line 939, Address: 0x289cc0, Func Offset: 0x10
	// Line 938, Address: 0x289cc4, Func Offset: 0x14
	// Line 939, Address: 0x289cc8, Func Offset: 0x18
	// Line 937, Address: 0x289ccc, Func Offset: 0x1c
	// Line 939, Address: 0x289cd4, Func Offset: 0x24
	// Line 940, Address: 0x289cdc, Func Offset: 0x2c
	// Line 941, Address: 0x289cf8, Func Offset: 0x48
	// Line 943, Address: 0x289d00, Func Offset: 0x50
	// Line 941, Address: 0x289d04, Func Offset: 0x54
	// Line 943, Address: 0x289d08, Func Offset: 0x58
	// Line 941, Address: 0x289d0c, Func Offset: 0x5c
	// Line 942, Address: 0x289d10, Func Offset: 0x60
	// Line 941, Address: 0x289d14, Func Offset: 0x64
	// Line 942, Address: 0x289d1c, Func Offset: 0x6c
	// Line 943, Address: 0x289d24, Func Offset: 0x74
	// Line 942, Address: 0x289d28, Func Offset: 0x78
	// Line 943, Address: 0x289d30, Func Offset: 0x80
	// Line 944, Address: 0x289d38, Func Offset: 0x88
	// Line 943, Address: 0x289d3c, Func Offset: 0x8c
	// Line 944, Address: 0x289d44, Func Offset: 0x94
	// Line 945, Address: 0x289d54, Func Offset: 0xa4
	// Line 946, Address: 0x289d68, Func Offset: 0xb8
	// Line 947, Address: 0x289d7c, Func Offset: 0xcc
	// Line 948, Address: 0x289d90, Func Offset: 0xe0
	// Line 949, Address: 0x289da4, Func Offset: 0xf4
	// Line 951, Address: 0x289db8, Func Offset: 0x108
	// Line 952, Address: 0x289de4, Func Offset: 0x134
	// Line 953, Address: 0x289dec, Func Offset: 0x13c
	// Line 952, Address: 0x289df4, Func Offset: 0x144
	// Line 953, Address: 0x289dfc, Func Offset: 0x14c
	// Line 954, Address: 0x289e24, Func Offset: 0x174
	// Line 955, Address: 0x289e44, Func Offset: 0x194
	// Line 956, Address: 0x289e50, Func Offset: 0x1a0
	// Line 955, Address: 0x289e5c, Func Offset: 0x1ac
	// Line 956, Address: 0x289e64, Func Offset: 0x1b4
	// Line 957, Address: 0x289e6c, Func Offset: 0x1bc
	// Line 956, Address: 0x289e70, Func Offset: 0x1c0
	// Line 957, Address: 0x289e78, Func Offset: 0x1c8
	// Line 960, Address: 0x289e88, Func Offset: 0x1d8
	// Func End, Address: 0x289e90, Func Offset: 0x1e0
}*/

// 
// Start address: 0x289e90
void bhStartDoorDemo()
{
	int etmf;
	//_anon18* ddp;
	// Line 966, Address: 0x289e90, Func Offset: 0
	// Line 967, Address: 0x289e9c, Func Offset: 0xc
	// Line 969, Address: 0x289ea4, Func Offset: 0x14
	// Line 967, Address: 0x289ea8, Func Offset: 0x18
	// Line 969, Address: 0x289eb4, Func Offset: 0x24
	// Line 972, Address: 0x289ed8, Func Offset: 0x48
	// Line 974, Address: 0x289ee8, Func Offset: 0x58
	// Line 976, Address: 0x289ef0, Func Offset: 0x60
	// Line 981, Address: 0x289ef8, Func Offset: 0x68
	// Line 982, Address: 0x289efc, Func Offset: 0x6c
	// Line 984, Address: 0x289f00, Func Offset: 0x70
	// Line 976, Address: 0x289f04, Func Offset: 0x74
	// Line 977, Address: 0x289f14, Func Offset: 0x84
	// Line 978, Address: 0x289f28, Func Offset: 0x98
	// Line 979, Address: 0x289f3c, Func Offset: 0xac
	// Line 980, Address: 0x289f50, Func Offset: 0xc0
	// Line 981, Address: 0x289f64, Func Offset: 0xd4
	// Line 982, Address: 0x289f70, Func Offset: 0xe0
	// Line 981, Address: 0x289f74, Func Offset: 0xe4
	// Line 982, Address: 0x289f7c, Func Offset: 0xec
	// Line 984, Address: 0x289f84, Func Offset: 0xf4
	// Line 982, Address: 0x289f88, Func Offset: 0xf8
	// Line 984, Address: 0x289f90, Func Offset: 0x100
	// Line 986, Address: 0x289f98, Func Offset: 0x108
	// Line 985, Address: 0x289f9c, Func Offset: 0x10c
	// Line 986, Address: 0x289fa0, Func Offset: 0x110
	// Line 984, Address: 0x289fa4, Func Offset: 0x114
	// Line 986, Address: 0x289fac, Func Offset: 0x11c
	// Line 987, Address: 0x289fb4, Func Offset: 0x124
	// Line 988, Address: 0x289fd0, Func Offset: 0x140
	// Line 1007, Address: 0x289fd8, Func Offset: 0x148
	// Line 1009, Address: 0x289fdc, Func Offset: 0x14c
	// Line 988, Address: 0x289fe0, Func Offset: 0x150
	// Line 989, Address: 0x28a000, Func Offset: 0x170
	// Line 990, Address: 0x28a020, Func Offset: 0x190
	// Line 991, Address: 0x28a02c, Func Offset: 0x19c
	// Line 992, Address: 0x28a038, Func Offset: 0x1a8
	// Line 991, Address: 0x28a03c, Func Offset: 0x1ac
	// Line 992, Address: 0x28a040, Func Offset: 0x1b0
	// Line 993, Address: 0x28a048, Func Offset: 0x1b8
	// Line 992, Address: 0x28a04c, Func Offset: 0x1bc
	// Line 993, Address: 0x28a050, Func Offset: 0x1c0
	// Line 1007, Address: 0x28a058, Func Offset: 0x1c8
	// Line 993, Address: 0x28a05c, Func Offset: 0x1cc
	// Line 1007, Address: 0x28a060, Func Offset: 0x1d0
	// Line 1009, Address: 0x28a074, Func Offset: 0x1e4
	// Line 1010, Address: 0x28a084, Func Offset: 0x1f4
	// Line 1012, Address: 0x28a08c, Func Offset: 0x1fc
	// Line 1024, Address: 0x28a09c, Func Offset: 0x20c
	// Line 1025, Address: 0x28a0ac, Func Offset: 0x21c
	// Line 1027, Address: 0x28a0b4, Func Offset: 0x224
	// Line 1028, Address: 0x28a0b8, Func Offset: 0x228
	// Line 1029, Address: 0x28a0bc, Func Offset: 0x22c
	// Line 1025, Address: 0x28a0c0, Func Offset: 0x230
	// Line 1027, Address: 0x28a0cc, Func Offset: 0x23c
	// Line 1028, Address: 0x28a0d8, Func Offset: 0x248
	// Line 1027, Address: 0x28a0dc, Func Offset: 0x24c
	// Line 1028, Address: 0x28a0e4, Func Offset: 0x254
	// Line 1029, Address: 0x28a0e8, Func Offset: 0x258
	// Line 1033, Address: 0x28a0f0, Func Offset: 0x260
	// Func End, Address: 0x28a100, Func Offset: 0x270
	scePrintf("bhStartDoorDemo - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x28a100
void bhPushGameData()
{
	// Line 1061, Address: 0x28a100, Func Offset: 0
	// Line 1070, Address: 0x28a10c, Func Offset: 0xc
	// Line 1061, Address: 0x28a110, Func Offset: 0x10
	// Line 1062, Address: 0x28a114, Func Offset: 0x14
	// Line 1070, Address: 0x28a128, Func Offset: 0x28
	// Line 1062, Address: 0x28a12c, Func Offset: 0x2c
	// Line 1070, Address: 0x28a130, Func Offset: 0x30
	// Line 1071, Address: 0x28a140, Func Offset: 0x40
	// Line 1070, Address: 0x28a144, Func Offset: 0x44
	// Line 1071, Address: 0x28a158, Func Offset: 0x58
	// Line 1072, Address: 0x28a168, Func Offset: 0x68
	// Line 1071, Address: 0x28a16c, Func Offset: 0x6c
	// Line 1072, Address: 0x28a170, Func Offset: 0x70
	// Line 1073, Address: 0x28a180, Func Offset: 0x80
	// Line 1072, Address: 0x28a184, Func Offset: 0x84
	// Line 1073, Address: 0x28a188, Func Offset: 0x88
	// Line 1074, Address: 0x28a198, Func Offset: 0x98
	// Line 1073, Address: 0x28a19c, Func Offset: 0x9c
	// Line 1074, Address: 0x28a1a0, Func Offset: 0xa0
	// Line 1075, Address: 0x28a1b0, Func Offset: 0xb0
	// Line 1074, Address: 0x28a1b4, Func Offset: 0xb4
	// Line 1075, Address: 0x28a1b8, Func Offset: 0xb8
	// Line 1076, Address: 0x28a1c8, Func Offset: 0xc8
	// Line 1075, Address: 0x28a1cc, Func Offset: 0xcc
	// Line 1076, Address: 0x28a1d8, Func Offset: 0xd8
	// Line 1079, Address: 0x28a1e8, Func Offset: 0xe8
	// Line 1076, Address: 0x28a1ec, Func Offset: 0xec
	// Line 1079, Address: 0x28a1fc, Func Offset: 0xfc
	// Func End, Address: 0x28a218, Func Offset: 0x118
	scePrintf("bhPushGameData - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x28a220
void bhPopGameData()
{
	// Line 1089, Address: 0x28a220, Func Offset: 0
	// Line 1093, Address: 0x28a228, Func Offset: 0x8
	// Line 1094, Address: 0x28a23c, Func Offset: 0x1c
	// Line 1096, Address: 0x28a244, Func Offset: 0x24
	// Line 1098, Address: 0x28a264, Func Offset: 0x44
	// Line 1099, Address: 0x28a28c, Func Offset: 0x6c
	// Line 1101, Address: 0x28a294, Func Offset: 0x74
	// Line 1104, Address: 0x28a29c, Func Offset: 0x7c
	// Line 1099, Address: 0x28a2a4, Func Offset: 0x84
	// Line 1100, Address: 0x28a2a8, Func Offset: 0x88
	// Line 1099, Address: 0x28a2ac, Func Offset: 0x8c
	// Line 1100, Address: 0x28a2b4, Func Offset: 0x94
	// Line 1101, Address: 0x28a2bc, Func Offset: 0x9c
	// Line 1100, Address: 0x28a2c0, Func Offset: 0xa0
	// Line 1101, Address: 0x28a2c8, Func Offset: 0xa8
	// Line 1102, Address: 0x28a2d0, Func Offset: 0xb0
	// Line 1104, Address: 0x28a2dc, Func Offset: 0xbc
	// Line 1105, Address: 0x28a2f0, Func Offset: 0xd0
	// Func End, Address: 0x28a2fc, Func Offset: 0xdc
	scePrintf("bhPopGameData - UNIMPLEMENTED!\n");
}
