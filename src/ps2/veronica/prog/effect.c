#include "effect.h"
#include "binfunc.h"
#include "dread.h"
#include "effsub2.h"
#include "effsub3.h"
#include "hitchk.h"
#include "light.h"
#include "njplus.h"
#include "ps2_NaColi.h"
#include "ps2_NaDraw.h"
#include "ps2_NaDraw2D.h"
#include "ps2_NaMatrix.h"
#include "ps2_NaSystem.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_NinjaCnk.h"
#include "ps2_texture.h"
#include "main.h"

typedef void (*bhJumpEffect_proc)(O_WRK*);
typedef void (*bhJumpEffect0_proc)(O_WRK*);
typedef void (*bhJumpEffect2_proc)(O_WRK*);
typedef void (*bhJumpEffect3_proc)(O_WRK*);
typedef void (*bhJumpEffect4_proc)(O_WRK*);

// TODO: uncomment all this when all functions are linkeable 
bhJumpEffect_proc bhJumpEffect[150]/* = { bhEff000, bhEff001, bhEff002, bhEff003, bhEff004, bhEff005, bhEff006, bhEff007, bhEff008, bhEff009, bhEff010, bhEff011, bhEff012, bhEff013, bhEff014, bhEff015, bhEff016, bhEff017, bhEff018, bhEff019, bhEff2D, bhEff021, bhEff022, bhEff023, bhEff024, bhEff025, bhEff026, bhEff027, bhEff028, bhEff029, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEff085, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffFil, bhEffFil, bhEffFil, bhEffBG, bhEffBG, bhEffBG, bhEffBG, bhEffBG, bhEffBG, bhEffBG, bhEff100, bhEff101, bhEff102, bhEff103, bhEff104, bhEff105, bhEffDmy, bhEff107, bhEff108, bhEff109, bhEff110, bhEff111, bhEff112, bhEff113, bhEff114, bhEff115, bhEff116, bhEff117, bhEff118, bhEff119, bhEff120, bhEff121, bhEff122, bhEff123, bhEff124, bhEff125, bhEff126, bhEff127, bhEff128, bhEff129, bhEff130, bhEff131, bhEff132, bhEff133, bhEff134, bhEff135, bhEff136, bhEff137, bhEff138, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEff143, bhEff144, bhEff145, bhEff_Sub146, bhEff147, bhEff148, bhEff149 }*/; 
bhJumpEffect0_proc bhJumpEffect0[100]/* = { bhEff150, bhEff151, bhEff152, bhEff153, bhEff154, bhEff155, bhEff156, bhEff157, bhEff158, bhEff159, bhEff160, bhEff161, bhEff162, bhEff163, bhEff164, bhEff165, bhEff166, bhEff167, bhEff168, bhEff169, bhEff170, bhEff171, bhEff172, bhEff173, bhEff174, bhEff175, bhEff176, bhEff177, bhEff178, bhEff179, bhEff180, bhEff181, bhEff182, bhEff183, bhEff184, bhEff185, bhEff186, bhEff187, bhEff188, bhEff189, bhEff190, bhEff191, bhEff192, bhEff193, bhEff194, bhEff195, bhEff196, bhEff197, bhEff198, bhEff199, bhEff200, bhEff201, bhEff202, bhEff203, bhEff204, bhEff205, bhEff206, bhEff207, bhEff208, bhEff209, bhEff210, bhEff211, bhEff212, bhEff213, bhEff214, bhEff215, bhEff216, bhEff217, bhEff218, bhEff219, bhEff220, bhEff221, bhEff222, bhEff223, bhEff224, bhEff225, bhEff226, bhEff227, bhEff228, bhEff229, bhEff230, bhEff231, bhEff232, bhEff233, bhEff234, bhEff235, bhEff236, bhEff237, bhEff238, bhEff239, bhEff240, bhEff241, bhEff242, bhEff243, bhEff244, bhEff245, bhEff246, bhEff247, bhEff248, bhEff249 }*/; 
bhJumpEffect2_proc bhJumpEffect2[50]/* = { bhEff_E00_Mince, bhEff_E00_DropBlood, bhEff_E00_Fire, bhEff_E02_SandDust, bhEff_E02_SandParticle, bhEff_E02_SandParticle2, bhEff_E03_Acid, bhEff_E00_Acid, bhEff_E03_Shadow, bhEff_E05_Blood, bhEff_E06_Rinpun, bhEff_E11_SearchLight, bhEff_E12_FireManager, bhEff_E12_Fire, bhEff_E12_FireSpark, bhEff_E12_FrameLiquid, bhEff_E12_FloorBlood2, bhEff_E13_Fluid, bhEff_E14_Explosion, bhEff_E14_Fire, bhEff_E16_LaserSight, bhEff_E14_Fire2, bhEff_E00_Dust, bhEff_E14_Mucus, bhEff_E12_Fire2, bhEff_E12_Fire3, bhEff_E12_BintaEffControl, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEff_E00_Blood, bhEff_E00_BloodBurst, bhEff_E00_AcidGenerator, bhEff_DamagePoint }*/;
bhJumpEffect3_proc bhJumpEffect3[50]/* = { bhEff300, bhEff301, bhEff302, bhEff303, bhEff304, bhEff305, bhEff306, bhEff307, bhEff308, bhEff309, bhEff30a, bhEff30b, bhEff30c, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEff349 }*/; 
bhJumpEffect4_proc bhJumpEffect4[50]/* = { bhEff_Sub350, bhEff_Sub351, bhEff_Sub352, bhEff_Sub353, bhEff_Sub354, bhEff_Sub355, bhEff_Sub356, bhEff_Sub357, bhEffDmy, bhEffDmy, bhEff_Sub360, bhEff_Sub361, bhEff_Sub362, bhEff_Sub363, bhEff_Sub364, bhEff_Sub365, bhEff_Sub366, bhEff_Sub367, bhEff_Sub368, bhEff_Sub369, bhEff_Sub370, bhEff_Sub371, bhEff_Sub372, bhEff_Sub373, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEffDmy, bhEff_E21_Mark, bhEff_E15_Poison, bhEff_Sub398, bhEff_E21_Spark }*/;
const EFFECT_INFO ef_info[21] = { {1, 9}, {1, 0}, {0, 2}, {0, 4}, {0, 4}, {0, 4}, {0, 2}, {1, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 5}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 2}, {0, 1}, {0, 1}, {-1, 0} };
O_WORK* ef_Zanzo[6] = { 0 };

// 99.62% matching
void bhInitEffect()
{
    int i;                 
    int j; // unused
    int poln;              
    int ef[16];           
    int sz;                
    unsigned char* dp;     
    unsigned char* refadr; // unused
    
    npSetMemoryL((unsigned int*)eff, sizeof(eff) / 4, 0);
    
    sys->bl_ct = sys->yk_ct = sys->ef_ct = 0;
    
    sys->eft_n = 0;
    
    dp = sys->memp;
    
    sz = *(int*)sys->memp;
    
    dp += 4;

    poln = 0;
    
    for (i = 0; ef_info[i].flg != -1; i++) 
    {
        sys->ef_tn[i] = sys->ef_ct;
        
        sys->ef_ct += ef_info[i].nbAnim;
        
        if ((ef_info[i].flg & 0x1))
        {
            bhMlbBinRealize(dp, (ML_WORK*)&sys->efm[i]);
            
            ef[poln++] = i;

            dp += sz;
            
            sz = *(int*)dp;
            
            dp += 4;
        }
    }
    
    sys->ef_tlist.textures = sys->ef_tex;
    
    sys->ef_tlist.nbTexture = 0;
    
    sys->ef_ct = bhSetMemPvpTexture(&sys->ef_tlist, (unsigned char*)(((int)dp + 31) & ~0x1F), 0);
    
    sys->ef_tlist.nbTexture = sys->ef_ct;
    
    sys->ef_ctb = sys->ef_ct;
    
    sys->memp = dp;
    
    for (i = 0; poln > i; i++)  
    {
        sys->memp = bhKeepObjWork((ML_WORK*)&sys->efm[ef[i]], sys->memp);
    }
    
    njSetTexture(&sys->ef_tlist);
    njSetPaletteBankNum(0, 0);
    
    for (i = 0; i < 30; i++) 
    {
        sys->ef_pbkb[i] = *(unsigned char*)(sys->ef_tlist.textures[sys->ef_tn[i]].texaddr + 4);
    } 
    
    sys->ss_flg |= 0x40;
}

// 100% matching!
void bhSetFontTexture(void* datp) 
{	
    unsigned char* dp;
	int i;
    int sz;
    
    if (!(sys->ss_flg & 0x40)) 
    { 	
        sz = *(int*)datp; 
        
        dp = (unsigned char*)datp + 4;
        
        for (i = 0; ef_info[i].flg != -1; i++)
        { 	
            if ((ef_info[i].flg & 0x1)) 
            {	
                dp += sz;           
                
                sz = *(int*)dp;         
                
                dp += 4;                
            }                          
        }                              
        
        dp = (unsigned char*)(((int)dp + 31) & ~0x1F);
        
        sys->ef_tlist.textures = sys->ef_tex;                  
        sys->ef_tlist.nbTexture = 0;                                        
        
        sys->ef_ct = bhSetMemPvpTexture(&sys->ef_tlist, dp, 0);
        
        sys->ef_tlist.nbTexture = 4;	                                      
        
        sys->ss_flg |= 0x40;	                            
    }
}

// 100% matching! 
void bhClearEffect()
{
    npSetMemoryL((unsigned int*)eff, sizeof(eff) / 4, 0);
}

// 100% matching! 
void bhClearEventEffect()
{
    bhClrEff_YT();
    bhClrEff_RY();
    bhClrEff_YG();
}

// 100% matching! 
void bhClrEff_YT()
{
    O_WRK* opp;
    int i;

    opp = eff;
    
    for (i = 0; i < 512; i++, opp++) 
    {
        if ((opp->flg & 0x1)) 
        {
            switch (opp->id) 
            {
            case 5:
            case 11:
            case 113:
            case 114:
            case 136:
            case 159:
            case 225:
            case 398:
                opp->flg = 0;
                break;
            case 22:
            case 24:
            case 25:
            case 27:
                opp->flg = 0;
                
                if (opp->exp0 != NULL) 
                {
                    *(unsigned int*)opp->exp0 = 0;
                }

                break;
            }
        }
    }
}

// 100% matching!
int bhPushEffectWork()
{
    unsigned int pssz;
    int nb; // not from the debugging symbols

    pssz = ((int)&sys->ob_nlgn - (int)&sys->ef_poln) + 0x9C000; 
    
    sys->ef_psp = (unsigned char*)((unsigned int)(sys->memp + 3) & ~0x3);

    if ((unsigned int)&sys->ef_psp[pssz] >= (unsigned int)sys->endp)
    {
        sys->ef_psp = NULL;
        
        return 0;
    }
    
    njMemCopy4(sys->ef_psp, eff, 0x27000);
    
    nb = (int)&sys->ob_nlgn - (int)&sys->ef_poln;
    
    njMemCopy4(sys->ef_psp + 0x9C000, &sys->ef_poln, (unsigned int)nb / 4);
    
    return 1;
}

// 100% matching!
void bhPopEffectWork()
{
    int nb; // not from the debugging symbols

    if (sys->ef_psp != NULL) 
    {
        njMemCopy4(eff, sys->ef_psp, 0x27000);
        
        nb = (int)&sys->ob_nlgn - (int)&sys->ef_poln;
        
        njMemCopy4(&sys->ef_poln, sys->ef_psp + 0x9C000, (unsigned int)nb / 4);
    }
}

// 100% matching!
unsigned int bhGetGidx(O_WRK* op)
{
    NJS_TEXLIST* tlp;
    NJS_TEXNAME* tnp;
    
    if (!(op->stflg & 0x20)) 
    {
        tlp = &sys->ef_tlist;
        
        tnp = &tlp->textures[sys->ef_tn[op->tex_id] + op->ani_ct];
    }
    else 
    {
        tlp = (NJS_TEXLIST*)&op->txp[0]->textures;
        
        tnp = &tlp->textures[op->tex_id + op->ani_ct];
    }
    
    return ((NJS_TEXMEMLIST*)tnp->texaddr)->globalIndex;
}

// 100% matching! 
O_WRK* bhSetExtraEffectWork() 
{
	O_WRK* op;
    int i;

    op = eff;
    
    for (i = 0; i < 512; i++, op++) 
    {
        if (!(op->flg & 0x3)) 
        {
            npSetMemoryL(&op->flg, sizeof(O_WRK) / 4, 0);
            
            op->flg = 2;
            
            return op;
        }
    }

    return NULL;
}

// 100% matching! 
void bhDeleteYakkyou()
{
    O_WRK* op;
    int i;
    
    op = eff;
    
    for (i = 0; i < 512; i++, op++)
    {
        if ((((op->flg & 0x1)) && (op->id == 0)) || (((op->flg & 0x1)) && (op->id == 7))) 
        {
            op->flg = 0;
        }
    } 
}

// 100% matching! 
void bhDrawPARAM2D(NJS_PRIM* prm, NJS_POINT2COL* p2c, float pri)
{
    p2c->p[0].x = prm->px + prm->x0;
    p2c->p[0].y = prm->py + prm->y0;
    
    p2c->p[1].x = prm->px + prm->x1;
    p2c->p[1].y = prm->py + prm->y0;
    
    p2c->p[2].x = prm->px + prm->x1;
    p2c->p[2].y = prm->py + prm->y1;
    
    p2c->p[3].x = prm->px + prm->x0;
    p2c->p[3].y = prm->py + prm->y1;
    
    p2c->tex = prm->uv;
    
    njDrawPolygon2D(p2c, 4, pri, 0x80000060);
}

// 100% matching!
int bhSetEffect(int effno, POINT* pnt, unsigned char* lkp, int lkono)
{
    O_WRK* opp;
    int i; 
    
    opp = eff;
    
    for (i = 0; ; )
    {
        if (!(opp->flg & 0x3))
        {
            npSetMemoryL(&opp->flg, sizeof(O_WRK) / 4, 0);
            
            opp->flg = 1;
            
            opp->id = effno;
            
            opp->type = 0;
            
            opp->tex_id = -1;
            
            opp->mdlver = 0;
            
            opp->flr_no = 0;
            
            opp->px = pnt->px;
            opp->py = pnt->py;
            opp->pz = pnt->pz;

            opp->lox = pnt->ox;
            opp->loy = pnt->oy;
            opp->loz = pnt->oz;
            
            opp->sx = 1.0f;
            opp->sy = 1.0f;
            opp->sz = 1.0f;
            
            opp->ax = 0;
            opp->ay = 0;
            opp->az = 0;
            
            opp->mlwP = &sys->efm[effno];
            
            if (lkp != NULL) 
            {
                opp->lkwkp = lkp;
                
                opp->flg |= 0x80;
            } 
            else 
            {
                opp->lkwkp = NULL;
            }
            
            opp->lkono = lkono;
            
            opp->mtx = (float(*)[16])opp->mtxbuf;
            
            opp->pvp = opp->pv;
            opp->tvp = opp->tv;
            
            opp->pn = 4;
            
            opp->tv[0].x = -1.0f;
            opp->tv[0].y = -1.0f;
            opp->tv[0].z = 0;
            
            opp->tv[1].x = 1.0f;
            opp->tv[1].y = -1.0f;
            opp->tv[1].z = 0;
            
            opp->tv[2].x = -1.0f;
            opp->tv[2].y = 1.0f;
            opp->tv[2].z = 0;
            
            opp->tv[3].x = 1.0f;
            opp->tv[3].y = 1.0f;
            opp->tv[3].z = 0;
            
            opp->tv[0].u = 0;
            opp->tv[0].v = 0;
            
            opp->tv[1].u = 1.0f;
            opp->tv[1].v = 0;
            
            opp->tv[2].u = 0;
            opp->tv[2].v = 1.0f;
            
            opp->tv[3].u = 1.0f;
            opp->tv[3].v = 1.0f;
            
            return i;
        }
        
        i++;
        opp++;
        
        if (i >= 512) 
        {
            return -1;
        }
    }
}

// 100% matching!
int bhSetEffectTb(EF_WORK* efp, NJS_POINT3* off, unsigned char* lkp, int lkono) 
{
    O_WRK* opp;
    int i;
    
    opp = eff;
    
    for (i = 0; ; )
    {
        if (!(opp->flg & 0x3))
        {
            npSetMemoryL(&opp->flg, sizeof(O_WRK) / 4, 0);
            
            opp->flg = efp->flg;
            
            opp->id = efp->id;
            
            opp->type = efp->type;
            
            opp->tex_id = -1;
            
            opp->mdlver = efp->mdlver;
            
            opp->flr_no = efp->flr_no;
            
            opp->px = efp->px;
            opp->py = efp->py;
            opp->pz = efp->pz;
            
            opp->sx = efp->sx;
            opp->sy = efp->sy;
            opp->sz = efp->sz;
            
            opp->sxb = efp->sx;
            opp->syb = efp->sy;
            opp->szb = efp->sz;
            
            opp->ax = efp->ax;
            opp->ay = efp->ay;
            opp->az = 0;
            
            opp->mlwP = &sys->efm[efp->id];
            
            if (off != NULL) 
            {
                opp->lox = off->x;
                opp->loy = off->y;
                opp->loz = off->z;
            }
            
            if (lkp != NULL) 
            {
                opp->lkwkp = lkp;
                
                opp->flg |= 0x80;
            } 
            else 
            {
                opp->lkwkp = NULL;
            }
            
            opp->lkono = lkono;
            
            opp->mtx = (float(*)[16])opp->mtxbuf;
            
            opp->pvp = opp->pv;
            opp->tvp = opp->tv;
            
            opp->pn = 4;
            
            opp->tv[0].x = -1.0f;
            opp->tv[0].y = -1.0f;
            opp->tv[0].z = 0;
            
            opp->tv[1].x = 1.0f;
            opp->tv[1].y = -1.0f;
            opp->tv[1].z = 0;
            
            opp->tv[2].x = -1.0f;
            opp->tv[2].y = 1.0f;
            opp->tv[2].z = 0;
            
            opp->tv[3].x = 1.0f;
            opp->tv[3].y = 1.0f;
            opp->tv[3].z = 0;
            
            opp->tv[0].u = 0;
            opp->tv[0].v = 0;
            
            opp->tv[1].u = 1.0f;
            opp->tv[1].v = 0;
            
            opp->tv[2].u = 0;
            opp->tv[2].v = 1.0f;
            
            opp->tv[3].u = 1.0f;
            opp->tv[3].v = 1.0f;
            
            return i;
        }
        
        i++;
        opp++;
        
        if (i >= 512) 
        {
            return -1;
        }
    }
}

// 100% matching!
int bhSetEffectEvt(int effno, POINT* pnt, unsigned short type, int ax, int ay)
{
    O_WRK* opp;
    int i; 
    
    opp = eff;
    
    for (i = 0; ; )
    {
        if (!(opp->flg & 0x3))
        {
            npSetMemoryL(&opp->flg, sizeof(O_WRK) / 4, 0);
            
            opp->flg = 1;
            
            opp->id = effno;
            
            opp->type = type;
            
            opp->tex_id = -1;
            
            opp->mdlver = 0;
            
            opp->flr_no = 0;
            
            opp->px = pnt->px;
            opp->py = pnt->py;
            opp->pz = pnt->pz;

            opp->lox = pnt->ox;
            opp->loy = pnt->oy;
            opp->loz = pnt->oz;
            
            opp->sx = 1.0f;
            opp->sy = 1.0f;
            opp->sz = 1.0f;
            
            opp->ax = ax;
            opp->ay = ay;
            opp->az = 0;
            
            opp->mlwP = &sys->efm[effno];

            opp->lkwkp = NULL;
            
            opp->lkono = 0;
            
            opp->mtx = (float(*)[16])opp->mtxbuf;
            
            opp->pvp = opp->pv;
            opp->tvp = opp->tv;
            
            opp->pn = 4;
            
            opp->tv[0].x = -1.0f;
            opp->tv[0].y = -1.0f;
            opp->tv[0].z = 0;
            
            opp->tv[1].x = 1.0f;
            opp->tv[1].y = -1.0f;
            opp->tv[1].z = 0;
            
            opp->tv[2].x = -1.0f;
            opp->tv[2].y = 1.0f;
            opp->tv[2].z = 0;
            
            opp->tv[3].x = 1.0f;
            opp->tv[3].y = 1.0f;
            opp->tv[3].z = 0;
            
            opp->tv[0].u = 0;
            opp->tv[0].v = 0;
            
            opp->tv[1].u = 1.0f;
            opp->tv[1].v = 0;
            
            opp->tv[2].u = 0;
            opp->tv[2].v = 1.0f;
            
            opp->tv[3].u = 1.0f;
            opp->tv[3].v = 1.0f;
            
            return i;
        }
        
        i++;
        opp++;
        
        if (i >= 512) 
        {
            return -1;
        }
    }
}

// 100% matching! 
int bhSetShadow(char* jtb, unsigned char* lkp, int lkono, float sx, float sy, float sz) 
{
    O_WRK* opp;
    int i;
    int j;
	
    opp = eff;
    
    for (i = 0; i < 512; i++, opp++)
    {
        if (!(opp->flg & 0x3)) 
        {
            npSetMemoryL(&opp->flg, sizeof(O_WRK) / 4, 0);
            
            opp->flg = 0x240001;
            
            opp->id = 1;
            
            if (jtb != NULL) 
            {
                opp->type = 0;
            } 
            else 
            {
                opp->type = 1;
            }
            
            opp->tex_id = -1;
            
            opp->mdlver = 0;
            
            opp->px = 0;
            opp->py = 0;
            opp->pz = 0;
            
            opp->sx = sx;
            opp->sy = sy;
            opp->sz = sz;
            
            opp->sxb = sx;
            opp->syb = sy;
            opp->szb = sz;
            
            opp->ax = 0;
            opp->ay = 0;
            opp->az = 0;
            
            opp->mlwP = &sys->efm[opp->id];
            
            if (lkp != NULL) 
            {
                opp->lkwkp = lkp;
                
                opp->flg |= 0x80;
            } 
            else 
            {
                opp->lkwkp = NULL;
            }
            
            opp->lkono = lkono;
            
            opp->mtx = (float(*)[16])opp->mtxbuf;
            
            opp->pvp = opp->pv;
            opp->tvp = opp->tv;
            
            if (jtb == NULL) 
            {
                opp->jno[0] = -1;
            }
            else 
            {
                for (j = 0; j < 15; j++) 
                {
                    opp->jno[j] = *jtb++;
                    
                    if (opp->jno[j] == -1)
                    {
                        break;
                    }
                }
            }
            
            return i;
        }
    }

    return -1;
}

// 100% matching!
void bhLinkBlood()
{

}

// 100% matching!
void bhControlEffect()
{
    O_WRK* op;    
    BH_PWORK* pp; 
    O_WORK* owp;  
    int i;        
    int* entp;    
    
    if (((sys->sp_flg & 0x8)) || ((sys->ef_flg & 0x1))) 
    {
        entp = &sys->ef_poln;
        
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        *entp++ = 0;
        
        ef_Zanzo[5] = NULL;
        ef_Zanzo[4] = NULL;
        ef_Zanzo[3] = NULL;
        ef_Zanzo[2] = NULL;
        ef_Zanzo[1] = NULL;
        ef_Zanzo[0] = NULL;
        
        sys->ef_ctrn = 0;
        
        op = eff;
        
        for (i = 0; i < 512; i++, op++)
        {
            sys->efnow = i;
            
            if (((op->flg & 0x1)) && (!(op->stflg & 0x1000000))) 
            {
                sys->ef_ctrn++;
                
                op->idx = i;
                
                if (op->id >= 400)
                {
                    op->flg = 0;
                } 
                else 
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
                        
                        if ((pp->flg & 0x1))
                        {
                            owp = &pp->mlwP->owP[op->lkono];
                            
                            if (owp != NULL) 
                            {
                                njCalcPoint(&owp->mtx, (NJS_POINT3*)&op->lox, (NJS_POINT3*)&op->px);
                            }
                        }
                    }
                    
                    if (op->id < 150) 
                    {
                        bhJumpEffect[op->id](op);
                    } 
                    else if (op->id < 250) 
                    {
                        bhJumpEffect0[op->id - 150](op);
                    } 
                    else if (op->id < 300)
                    {
                        bhJumpEffect2[op->id - 250](op);
                    } 
                    else if (op->id < 350) 
                    {
                        bhJumpEffect3[op->id - 300](op);
                    }
                    else 
                    {
                        bhJumpEffect4[op->id - 350](op);
                    }
                    
                    if ((op->flg & 0x10000)) 
                    {
                        bhCheckWall((BH_PWORK*)op);
                    }
                }
            }
        } 
    }
}

// 100% matching!
void bhDrawEffect()
{
    int i;

    njSetMatrix(NULL, cam.mtx);
    
    njControl3D(0x100);
    
    if (sys->ef_poln != 0) 
    {
        bhDrawPolEffect((unsigned int*)sys->ef_pol, sys->ef_poln);
    }
    
    njControl3D(0x2400);
    
    if (sys->ef_mdfn != 0) 
    {
        bhDrawMdfEffect((unsigned int*)sys->ef_mdf, sys->ef_mdfn);
    }
    
    njControl3D(0x100);
    
    if (sys->ef_linn != 0) 
    {
        bhDrawLinEffect((unsigned int*)sys->ef_lin, sys->ef_linn);
    }
    
    if (sys->ef_ntxn != 0) 
    {
        bhDrawNtxEffect3D((unsigned int*)sys->ef_ntx, sys->ef_ntxn);
    }
    
    if (sys->ef_trsn != 0) 
    {
        bhDrawTrsEffect3D((unsigned int*)sys->ef_trs, sys->ef_trsn);
    }
    
    njControl3D(0x4000);
    
    if (sys->ef_pncn != 0) 
    {
        bhDrawTrsEffect3D((unsigned int*)sys->ef_pnc, sys->ef_pncn);
    }
    
    njControl3D(0);
    
    if (sys->ef_opqn != 0) 
    {
        bhDrawOpqEffect3D((unsigned int*)sys->ef_opq, sys->ef_opqn);
    }
    
    if (sys->ef_thln != 0) 
    {
        bhDrawThlEffect3D((unsigned int*)sys->ef_thl, sys->ef_thln);
    }
    
    if (sys->ef_ntx2dn != 0) 
    {
        bhDrawNtxEffect2D((unsigned int*)sys->ef_ntx2d, sys->ef_ntx2dn);
    }
    
    if (sys->ef_trs2dn != 0) 
    {
        bhDrawTrsEffect2D((unsigned int*)sys->ef_trs2d, sys->ef_trs2dn);
    }
    
    njControl3D(0x4000);
    
    if (sys->ef_pnc2dn != 0) 
    {
        bhDrawTrsEffect2D((unsigned int*)sys->ef_pnc2d, sys->ef_pnc2dn);
    }
    
    njControl3D(0);
    
    if ((sys->ef_flg & 0x4))
    {
        bhSetHalfLight();
    }
    
    for (i = 0; i < sys->ef_fncn; i++)
    {
        sys->ef_fnc[i]->func(sys->ef_fnc[i]);
    }
    
    for (i = 5; 0 <= i; i--) 
    {
        if (ef_Zanzo[i] != NULL) 
        {
            ((O_WRK*)ef_Zanzo[i])->func(ef_Zanzo[i]);
        }
    }
    
    if ((sys->stg_no == 1) && (sys->rom_no == 9)) 
    {
        bhDrawThunder(sys->rom_no, sys);
    }
}

// 99.84% matching
void bhDrawPolEffect(unsigned int* owp, int ct)
{
    NJS_TEXNAME* tnp; 
    ML_WORK* mlp;     
    O_WRK* op;        

    njCnkSetEasyLightColor(1.0f, 1.0f, 1.0f);
    njCnkSetEasyLightIntensity(0.7f, 0.2f);
    njCnkSetEasyLight(0, 0.3f, 0.7f);
    
    while (ct--)
    { 
        njPushMatrixEx();
        
        op = (O_WRK*)*owp++;
        
        if (((op->flg & 0x1000000)) || ((op->stflg & 0x1000000)) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40))))
        {
            njPopMatrixEx();
        }
        else 
        {
            if ((op->flg & 0x20000000))
            {
                njTextureFilterMode(0);
            } 
            else 
            {
                njTextureFilterMode(1);
            }
            
            mlp = op->mlwP;
            
            if (!(op->stflg & 0x20))
            {
                tnp = sys->ef_tlist.textures;
                
                sys->ef_tlist.textures = &tnp[op->tex_id + op->ani_ct];
                
                njSetTexture(&sys->ef_tlist);
                njSetTextureNum(0);
            } 
            else 
            {
                njSetTexture(op->txp[0]);
                njSetTextureNum(0);
            }
            
            njPushMatrixEx();
            
            if (((op->flg & 0x200000)) || (!(op->flg & 0x80))) 
            {
                njUnitMatrix(NULL);
                
                njTranslateEx((NJS_POINT3*)&op->px);
                njRotateEx(&op->ax, 0);
                
                njGetMatrix(op->mtx);
            }
            else 
            {
                njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
                
                njTranslate(op->mtx, op->lox, op->loy, op->loz);
                njRotateXYZ(op->mtx, op->ax, op->ay, op->az);
            }
            
            njPopMatrixEx();
            njMultiMatrix(NULL, op->mtx);
        
            njScaleEx((NJS_POINT3*)&op->sx);
            
            njCnkEasyDrawModel(mlp->objP[op->mdlver].model);
            
            if (!(op->stflg & 0x20)) 
            {
                sys->ef_tlist.textures = tnp;
            }
            
            njPopMatrixEx();
        }
    }
}

// 100% matching!
void bhDrawMdfEffect(unsigned int* owp, int ct) 
{
    ML_WORK* mlp;
    O_WRK* op;

    Ps2ShadowStart();
    
    while (ct--)
    { 
        njPushMatrixEx();
        
        op = (O_WRK*)*owp++;
        
        if (((op->flg & 0x1000000)) || ((op->stflg & 0x1000000)) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40))))
        {
            njPopMatrixEx();
        }
        else 
        {
            mlp = op->mlwP;
            
            njPushMatrixEx();
            
            if (((op->flg & 0x200000)) || (!(op->flg & 0x80))) 
            {
                njUnitMatrix(NULL);
                
                njTranslateEx((NJS_POINT3*)&op->px);
                njRotateEx(&op->ax, 0);
                
                njGetMatrix(op->mtx);
            }
            else 
            {
                njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
                
                njTranslate(op->mtx, op->lox, op->loy, op->loz);
                njRotateXYZ(op->mtx, op->ax, op->ay, op->az);
            }
            
            njPopMatrixEx();
            njMultiMatrix(NULL, op->mtx);
            
            njScaleEx((NJS_POINT3*)&op->sx);
            
            Ps2ShadowMain0();
            
            lCnkModClipFace = 0;
            
            njCnkModDrawModel(mlp->objP[op->mdlver].model);
            
            Ps2ShadowMain1();
            
            lCnkModClipFace = 0x80000000;
            
            njCnkModDrawModel(mlp->objP[op->mdlver].model);
            
            Ps2ShadowDraw();
            
            njPopMatrixEx();
        }
    }
    
    Ps2ShadowEnd();
}

// 100% matching!
void bhDrawLinEffect(unsigned int* owp, int ct)
{
    NJS_POINT3COL p3c; 
    NJS_POINT3 pos[2]; 
    NJS_COLOR col[2];  
    O_WRK* op;         

    while (ct--) 
    {
        njPushMatrixEx();
        
        op = (O_WRK*)*owp++;
        
        if (((op->flg & 0x1000000)) || ((op->stflg & 0x1000000)) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40))))
        {
            njPopMatrixEx();
        } 
        else 
        {
            pos[0].x = op->pv[0].x;
            pos[0].y = op->pv[0].y;
            pos[0].z = op->pv[0].z; 
            
            pos[1].x = op->pv[1].x;
            pos[1].y = op->pv[1].y;
            pos[1].z = op->pv[1].z;
           
            col[0].color = op->pv[0].col;
            col[1].color = op->pv[1].col;
            
            p3c.p = pos;
            
            p3c.col = col;
            
            p3c.tex = NULL;
            
            p3c.num = 1;
            
            njPushMatrixEx();
            njUnitMatrix(NULL);
            
            njTranslateEx((NJS_POINT3*)&op->px);
            njRotateEx(&op->ax, 0);
            
            njGetMatrix(op->mtx);
            njPopMatrixEx();
            
            njMultiMatrix(NULL, op->mtx);
            njScaleEx((NJS_POINT3*)&op->sx);
            
            njColorBlendingMode(0, op->bl_src);
            njColorBlendingMode(1, op->bl_dst);
            
            njDrawLine3D(&p3c, op->pn, 0x40);
            
            njColorBlendingMode(0, 8);
            njColorBlendingMode(1, 6);
            
            njPopMatrixEx();
        }
    }
}

// 100% matching!
void bhDrawNtxEffect3D(unsigned int* owp, int ct)
{
    O_WRK* op;      
    NJS_POINT3 pa;  
    NJS_POINT3 pb;  
    NJS_POINT3 pc;  
    NJS_VECTOR vec; 
    
    njDrawPolygon3DExStart(1);
    
    while (ct--) 
    {
        njPushMatrixEx();
        
        op = (O_WRK*)*owp++;
        
        if (((op->flg & 0x1000000)) || ((op->stflg & 0x1000000)) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40))))
        {
            njPopMatrixEx();
        } 
        else 
        { 
            if ((op->flg & 0x20000000)) 
            {
                njTextureFilterMode(0);
            } 
            else 
            {
                njTextureFilterMode(1);
            }
            
            njPushMatrixEx();
            
            if ((!(op->flg & 0x80)) || ((op->flg & 0x200000))) 
            {
                njUnitMatrix(NULL);
            
                njTranslateEx((NJS_POINT3*)&op->px);
                njRotateEx(&op->ax, 0);
            
                njGetMatrix(op->mtx);
            } 
            else 
            {
                njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
            
                njTranslate(op->mtx, op->lox, op->loy, op->loz);
                njRotateXYZ(op->mtx, op->ax, op->ay, op->az);
            }
            
            njPopMatrixEx();
            
            njMultiMatrix(NULL, op->mtx);
            
            if ((op->flg & 0x100000)) 
            {
                njUnitRotPortion(NULL);
                
                njRotateZ(NULL, op->az);
                
                if ((sys->gm_flg & 0x4000)) 
                {
                    if (sys->mr_pl.vx) 
                    {
                        njRotateY(NULL, 32768);
                    }
                    
                    if (sys->mr_pl.vy) 
                    {
                        njRotateX(NULL, 32768);
                    }
                }
            }
            
            njScaleEx((NJS_POINT3*)&op->sx);
            
            if ((op->flg & 0x20000)) 
            {
                njCalcPoint(NULL, (NJS_POINT3*)op->pvp, &pa);
                njCalcPoint(NULL, (NJS_POINT3*)&op->pvp[1], &pb);
                njCalcPoint(NULL, (NJS_POINT3*)&op->pvp[2], &pc);
                
                njProjectScreen(NULL, (NJS_POINT3*)op->pvp, (NJS_POINT2*)&pa);
                njProjectScreen(NULL, (NJS_POINT3*)&op->pvp[1], (NJS_POINT2*)&pb);
                njProjectScreen(NULL, (NJS_POINT3*)&op->pvp[2], (NJS_POINT2*)&pc);
                
                njGetPlaneNormal2(&pa, &pb, &pc, &vec);
                
                njUnitVector(&vec);
                
                if (vec.z < 0)
                {
                    op->stflg |= 0x10;
                    
                    njPopMatrixEx();
                } 
                else 
                {
                    op->stflg &= ~0x10;
                    goto label;
                }
            } 
            else 
            {
label:
                njColorBlendingMode(0, op->bl_src);
                njColorBlendingMode(1, op->bl_dst);
                
                njDrawPolygon3DExSetData(op->pvp, op->pn);
                
                njColorBlendingMode(0, 8);
                njColorBlendingMode(1, 6);
                
                njPopMatrixEx();
            }
        } 
    }
    
    njDrawPolygon3DExEnd();
}

// 100% matching!
void bhDrawTrsEffect3D(unsigned int* owp, int ct) 
{
    O_WRK* op;      
    NJS_POINT3 pa;  
    NJS_POINT3 pb;  
    NJS_POINT3 pc;  
    NJS_VECTOR vec; 
    
    while (ct--) 
    {
        njPushMatrixEx();
        
        op = (O_WRK*)*owp++;
        
        if ((((op->flg & 0x1000000)) || ((op->stflg & 0x1000000)) || (op->tex_id < 0)) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40)))
        || ((!(sys->sp_flg & 0x8)) && ((op->id == 9) && (op->type == 2)) && ((plp->stflg & 0x1000000)))
        || ((!(sys->sp_flg & 0x8)) && ((op->id == 9) && (op->type == 2)) && ((plp->mdflg & 0x1)))) 
        {
            njPopMatrixEx();
        } 
        else 
        { 
            if ((op->flg & 0x20000000)) 
            {
                njTextureFilterMode(0);
            }
            else 
            {
                njTextureFilterMode(1);
            }
            
            if ((op->flg & 0x800000)) 
            {
                njSetTextureNumG(op->gidx);
            } 
            else if (!(op->stflg & 0x20)) 
            {
                njSetTexture(&sys->ef_tlist);
                njSetTextureNum(sys->ef_tn[op->tex_id] + op->ani_ct);
            } 
            else 
            {
                njSetTexture(op->txp[0]);
                njSetTextureNum(op->tex_id + op->ani_ct);
            }
            
            njPushMatrixEx();
            
            if ((!(op->flg & 0x80)) || ((op->flg & 0x200000)))
            { 
                njUnitMatrix(NULL);
    
                njTranslateEx((NJS_POINT3*)&op->px); 
                njRotateEx(&op->ax, 0);
        
                njGetMatrix(op->mtx); 
            } 
            else
            {
                njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
        
                njTranslate(op->mtx, op->lox, op->loy, op->loz);
                njRotateXYZ(op->mtx, op->ax, op->ay, op->az);
            }
            
            njPopMatrixEx();
            njMultiMatrix(NULL, op->mtx);
            
            if ((op->flg & 0x100000)) 
            {
                njUnitRotPortion(NULL);
                njRotateZ(NULL, op->az);
                
                if ((sys->gm_flg & 0x4000)) 
                {
                    if (sys->mr_pl.vx)
                    {
                        njRotateY(NULL, 32768);
                    }
                    
                    if (sys->mr_pl.vy) 
                    {
                        njRotateX(NULL, 32768);
                    }
                }
            }
            
            njScaleEx((NJS_POINT3*)&op->sx);
            
            if ((op->flg & 0x20000))
            {
                njCalcPoint(NULL, (NJS_POINT3*)op->tvp, &pa);
                njCalcPoint(NULL, (NJS_POINT3*)&op->tvp[1], &pb);
                njCalcPoint(NULL, (NJS_POINT3*)&op->tvp[2], &pc);
                
                njProjectScreen(NULL, (NJS_POINT3*)op->tvp, (NJS_POINT2*)&pa);
                njProjectScreen(NULL, (NJS_POINT3*)&op->tvp[1], (NJS_POINT2*)&pb);
                njProjectScreen(NULL, (NJS_POINT3*)&op->tvp[2], (NJS_POINT2*)&pc);
                
                njGetPlaneNormal2(&pa, &pb, &pc, &vec);
                
                njUnitVector(&vec);
                
                if (vec.z < 0)
                {
                    op->stflg |= 0x10;
                    
                    njPopMatrixEx();
                } 
                else 
                {
                    op->stflg &= ~0x10;
                    goto label;
                }
            } 
            else 
            {
label:
                njColorBlendingMode(0, op->bl_src);
                njColorBlendingMode(1, op->bl_dst);
                
                if ((op->id == 128) || (op->id == 353) || (op->id == 123)) 
                {
                    njDrawTexture3DEx1P(op->tvp, op->pn, 1);
                } 
                else 
                {
                    njDrawTexture3DEx(op->tvp, op->pn, 1);
                }
                
                njColorBlendingMode(0, 8);
                njColorBlendingMode(1, 6);
                
                njPopMatrixEx();
            }
        } 
    }
}

// 100% matching!
void bhDrawOpqEffect3D(unsigned int* owp, int ct)
{
    O_WRK* op;      
    NJS_POINT3 pa;  
    NJS_POINT3 pb;  
    NJS_POINT3 pc;  
    NJS_VECTOR vec; 

    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    while (ct--) 
    {
        njPushMatrixEx();
        
        op = (O_WRK*)*owp++;
        
        if ((((op->flg & 0x1000000)) || ((op->stflg & 0x1000000)) || (op->tex_id < 0)) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40)))) 
        {
            njPopMatrixEx();
        } 
        else 
        { 
            if ((op->flg & 0x20000000)) 
            {
                njTextureFilterMode(0);
            }
            else 
            {
                njTextureFilterMode(1);
            }
            
            if ((op->flg & 0x800000)) 
            {
                njSetTextureNumG(op->gidx);
            } 
            else if (!(op->stflg & 0x20)) 
            {
                njSetTexture(&sys->ef_tlist);
                njSetTextureNum(sys->ef_tn[op->tex_id] + op->ani_ct);
            } 
            else 
            {
                njSetTexture(op->txp[0]);
                njSetTextureNum(op->tex_id + op->ani_ct);
            }
            
            njPushMatrixEx();
            
            if ((!(op->flg & 0x80)) || ((op->flg & 0x200000)))
            { 
                njUnitMatrix(NULL);
    
                njTranslateEx((NJS_POINT3*)&op->px); 
                njRotateEx(&op->ax, 0);
        
                njGetMatrix(op->mtx); 
            } 
            else
            {
                njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
        
                njTranslate(op->mtx, op->lox, op->loy, op->loz);
                njRotateXYZ(op->mtx, op->ax, op->ay, op->az);
            }
            
            njPopMatrixEx();
            njMultiMatrix(NULL, op->mtx);
            
            if ((op->flg & 0x100000)) 
            {
                njUnitRotPortion(NULL);
                njRotateZ(NULL, op->az);
                
                if ((sys->gm_flg & 0x4000)) 
                {
                    if (sys->mr_pl.vx)
                    {
                        njRotateY(NULL, 32768);
                    }
                    
                    if (sys->mr_pl.vy) 
                    {
                        njRotateX(NULL, 32768);
                    }
                }
            }
            
            njScaleEx((NJS_POINT3*)&op->sx);
            
            if ((op->flg & 0x20000))
            {
                njCalcPoint(NULL, (NJS_POINT3*)op->tvp, &pa);
                njCalcPoint(NULL, (NJS_POINT3*)&op->tvp[1], &pb);
                njCalcPoint(NULL, (NJS_POINT3*)&op->tvp[2], &pc);
                
                njProjectScreen(NULL, (NJS_POINT3*)op->tvp, (NJS_POINT2*)&pa);
                njProjectScreen(NULL, (NJS_POINT3*)&op->tvp[1], (NJS_POINT2*)&pb);
                njProjectScreen(NULL, (NJS_POINT3*)&op->tvp[2], (NJS_POINT2*)&pc);
                
                njGetPlaneNormal2(&pa, &pb, &pc, &vec);
                
                njUnitVector(&vec);
                
                if (vec.z < 0)
                {
                    op->stflg |= 0x10;
                    
                    njPopMatrixEx();
                } 
                else 
                {
                    op->stflg &= ~0x10;
                    goto label;
                }
            } 
            else 
            {
label:
                if (op->id == 204) 
                {
                    njDrawTexture3DEx1P(op->tvp, op->pn, 1);
                } 
                else 
                {
                    njDrawTexture3DEx(op->tvp, op->pn, 1);
                }
                
                njPopMatrixEx();
            }
        } 
    }
}

// 100% matching!
void bhDrawThlEffect3D(unsigned int* owp, int ct)
{
    NJS_TEXTUREH_VTX* tvp; 
    O_WRK* op;             
    NJS_POINT3 pa;         
    NJS_POINT3 pb;         
    NJS_POINT3 pc;         
    NJS_POINT3 vec;        
    NJS_POINT3 vc0;        
    NJS_POINT3 vc1;        
    float it;              
    int pt;                
    
    while (ct--) 
    {
        njPushMatrixEx();
        
        op = (O_WRK*)*owp++;
        
        if ((((op->flg & 0x1000000)) || ((op->stflg & 0x1000000)) || (op->tex_id < 0)) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40)))) 
        {
            njPopMatrixEx();
        } 
        else 
        { 
            if ((op->flg & 0x20000000)) 
            {
                njTextureFilterMode(0);
            }
            else 
            {
                njTextureFilterMode(1);
            }
            
            if (!(op->stflg & 0x20)) 
            {
                njSetTexture(&sys->ef_tlist);
                njSetTextureNum(sys->ef_tn[op->tex_id] + op->ani_ct);
            }
            else
            {
                njSetTexture(op->txp[0]);
                njSetTextureNum(op->tex_id + op->ani_ct);
            }
            
            njPushMatrixEx();
            
            if ((!(op->flg & 0x80)) || ((op->flg & 0x200000))) 
            {
                njUnitMatrix(NULL);
                
                njTranslateEx((NJS_POINT3*)&op->px);
                njRotateEx(&op->ax, 0);
                
                njGetMatrix(op->mtx);
            }
            else 
            {
                njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
                
                njTranslate(op->mtx, op->lox, op->loy, op->loz);
                njRotateXYZ(op->mtx, op->ax, op->ay, op->az);
            }
            
            njPopMatrixEx();
            njMultiMatrix(NULL, op->mtx);
            
            if ((op->flg & 0x100000)) 
            {
                njUnitRotPortion(NULL);
                njRotateZ(NULL, op->az);
                
                if ((sys->gm_flg & 0x4000)) 
                {
                    if (sys->mr_pl.vx)
                    {
                        njRotateY(NULL, 32768);
                    }
                    
                    if (sys->mr_pl.vy) 
                    {
                        njRotateX(NULL, 32768);
                    }
                }
            }
            
            njScaleEx((NJS_POINT3*)&op->sx);

            tvp = (NJS_TEXTUREH_VTX*)op->tvp;
            
            if ((op->flg & 0x20000)) 
            {
                njCalcPoint(NULL, (NJS_POINT3*)tvp, &pa);
                njCalcPoint(NULL, (NJS_POINT3*)&tvp[1], &pb);
                njCalcPoint(NULL, (NJS_POINT3*)&tvp[2], &pc);
                
                njProjectScreen(NULL, (NJS_POINT3*)tvp, (NJS_POINT2*)&pa);
                njProjectScreen(NULL, (NJS_POINT3*)&tvp[1], (NJS_POINT2*)&pb);
                njProjectScreen(NULL, (NJS_POINT3*)&tvp[2], (NJS_POINT2*)&pc);
                
                njGetPlaneNormal2(&pa, &pb, &pc, &vec);
                
                njUnitVector(&vec);
                
                if (vec.z < 0)
                {
                    op->stflg |= 0x10;
                    
                    njPopMatrixEx();
                } 
                else 
                {
                    op->stflg &= ~0x10;
                    goto label;
                }
            } 
            else 
            {
label:
                if ((op->flg & 0x2000000)) 
                {
                    njPushMatrixEx();
                    
                    vc0.y = 0;
                    vc0.x = 0;
                    vc0.z = -1.0f;
                    
                    njUnitMatrix(NULL);
                    njRotateXYZ(NULL, op->ax, op->ay, 0);
                    
                    njCalcVector(NULL, &vc0, &vc1);
                    
                    it = fabsf(njInnerProduct((NJS_VECTOR*)&vc1, (NJS_VECTOR*)&cam.vx));
                    
                    pt = (int)(128.0f * njCos((int)(182.04445f * (360.0f * it)) & 0xFFFF)) + 127;
                    
                    tvp[3].ocol = tvp[2].ocol = tvp[1].ocol = tvp->ocol = pt | ((pt << 8) | ((pt << 24) | (pt << 16)));
                    
                    njPopMatrixEx();
                }
                
                if ((op->bl_src == 0) && (op->bl_dst == 0)) 
                {
                    njColorBlendingMode(0, 8);
                    njColorBlendingMode(1, 6);
                    
                    njDrawTexture3DHEx(tvp, op->pn, 0);
                }
                else
                {
                    njColorBlendingMode(0, op->bl_src);
                    njColorBlendingMode(1, op->bl_dst);
                    
                    njDrawTexture3DHEx(tvp, op->pn, 1);
                    
                    njColorBlendingMode(0, 8);
                    njColorBlendingMode(1, 6);
                }
                
                njPopMatrixEx();
            }
        }
    }
}

// 
// Start address: 0x21eb80
void bhDrawNtxEffect2D(unsigned int* owp, int ct)
{
	//_anon0* op;
	// Line 2074, Address: 0x21eb80, Func Offset: 0
	// Line 2076, Address: 0x21eb94, Func Offset: 0x14
	// Line 2077, Address: 0x21eba4, Func Offset: 0x24
	// Line 2079, Address: 0x21eba8, Func Offset: 0x28
	// Line 2082, Address: 0x21ebf4, Func Offset: 0x74
	// Line 2084, Address: 0x21ebf8, Func Offset: 0x78
	// Line 2085, Address: 0x21ec08, Func Offset: 0x88
	// Line 2086, Address: 0x21ec18, Func Offset: 0x98
	// Func End, Address: 0x21ec2c, Func Offset: 0xac
}

// 
// Start address: 0x21ec30
void bhDrawTrsEffect2D(unsigned int* owp, int ct)
{
	//_anon0* op;
	// Line 2092, Address: 0x21ec30, Func Offset: 0
	// Line 2094, Address: 0x21ec44, Func Offset: 0x14
	// Line 2092, Address: 0x21ec4c, Func Offset: 0x1c
	// Line 2094, Address: 0x21ec50, Func Offset: 0x20
	// Line 2095, Address: 0x21ec58, Func Offset: 0x28
	// Line 2097, Address: 0x21ec5c, Func Offset: 0x2c
	// Line 2101, Address: 0x21ecb4, Func Offset: 0x84
	// Line 2103, Address: 0x21ecb8, Func Offset: 0x88
	// Line 2104, Address: 0x21ecc8, Func Offset: 0x98
	// Line 2106, Address: 0x21ecd8, Func Offset: 0xa8
	// Line 2108, Address: 0x21ece8, Func Offset: 0xb8
	// Line 2109, Address: 0x21ecf4, Func Offset: 0xc4
	// Line 2111, Address: 0x21ed00, Func Offset: 0xd0
	// Line 2113, Address: 0x21ed14, Func Offset: 0xe4
	// Line 2115, Address: 0x21ed20, Func Offset: 0xf0
	// Line 2117, Address: 0x21ed2c, Func Offset: 0xfc
	// Line 2118, Address: 0x21ed40, Func Offset: 0x110
	// Func End, Address: 0x21ed58, Func Offset: 0x128
}

// 
// Start address: 0x21ed60
void bhDrawThunder()
{
	int i;
	//_anon40* p;
	//_anon40 p1[4];
	//_anon40 p2[4];
	// Line 2125, Address: 0x21ed60, Func Offset: 0
	// Line 2142, Address: 0x21ed6c, Func Offset: 0xc
	// Line 2181, Address: 0x21ed94, Func Offset: 0x34
	// Line 2182, Address: 0x21ed9c, Func Offset: 0x3c
	// Line 2183, Address: 0x21eda8, Func Offset: 0x48
	// Line 2182, Address: 0x21edb0, Func Offset: 0x50
	// Line 2183, Address: 0x21edd4, Func Offset: 0x74
	// Line 2185, Address: 0x21eddc, Func Offset: 0x7c
	// Line 2187, Address: 0x21ede8, Func Offset: 0x88
	// Line 2190, Address: 0x21edf4, Func Offset: 0x94
	// Line 2191, Address: 0x21ee04, Func Offset: 0xa4
	// Func End, Address: 0x21ee14, Func Offset: 0xb4
}
