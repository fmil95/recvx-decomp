#include "effect.h"
#include "binfunc.h"
#include "dread.h"
#include "effsub2.h"
#include "effsub3.h"
#include "hitchk.h"
#include "light.h"
#include "njplus.h"
#include "ps2_NaDraw2D.h"
#include "ps2_NaMatrix.h"
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

// 
// Start address: 0x21d7d0
void bhDrawLinEffect(unsigned int* owp, int ct)
{
	//_anon0* op;
	//_anon24 col[2];
	//_anon37 pos[2];
	//_anon42 p3c;
	// Line 1501, Address: 0x21d7d0, Func Offset: 0
	// Line 1509, Address: 0x21d7e4, Func Offset: 0x14
	// Line 1501, Address: 0x21d7ec, Func Offset: 0x1c
	// Line 1509, Address: 0x21d7f0, Func Offset: 0x20
	// Line 1510, Address: 0x21d7f8, Func Offset: 0x28
	// Line 1511, Address: 0x21d800, Func Offset: 0x30
	// Line 1513, Address: 0x21d804, Func Offset: 0x34
	// Line 1517, Address: 0x21d850, Func Offset: 0x80
	// Line 1518, Address: 0x21d858, Func Offset: 0x88
	// Line 1520, Address: 0x21d860, Func Offset: 0x90
	// Line 1528, Address: 0x21d864, Func Offset: 0x94
	// Line 1529, Address: 0x21d868, Func Offset: 0x98
	// Line 1531, Address: 0x21d86c, Func Offset: 0x9c
	// Line 1520, Address: 0x21d870, Func Offset: 0xa0
	// Line 1521, Address: 0x21d874, Func Offset: 0xa4
	// Line 1522, Address: 0x21d87c, Func Offset: 0xac
	// Line 1523, Address: 0x21d884, Func Offset: 0xb4
	// Line 1524, Address: 0x21d88c, Func Offset: 0xbc
	// Line 1525, Address: 0x21d894, Func Offset: 0xc4
	// Line 1526, Address: 0x21d89c, Func Offset: 0xcc
	// Line 1527, Address: 0x21d8a4, Func Offset: 0xd4
	// Line 1528, Address: 0x21d8a8, Func Offset: 0xd8
	// Line 1529, Address: 0x21d8ac, Func Offset: 0xdc
	// Line 1530, Address: 0x21d8b0, Func Offset: 0xe0
	// Line 1527, Address: 0x21d8b4, Func Offset: 0xe4
	// Line 1532, Address: 0x21d8b8, Func Offset: 0xe8
	// Line 1533, Address: 0x21d8c0, Func Offset: 0xf0
	// Line 1534, Address: 0x21d8c8, Func Offset: 0xf8
	// Line 1535, Address: 0x21d8d0, Func Offset: 0x100
	// Line 1536, Address: 0x21d8dc, Func Offset: 0x10c
	// Line 1537, Address: 0x21d8e4, Func Offset: 0x114
	// Line 1538, Address: 0x21d8ec, Func Offset: 0x11c
	// Line 1539, Address: 0x21d8f8, Func Offset: 0x128
	// Line 1557, Address: 0x21d900, Func Offset: 0x130
	// Line 1558, Address: 0x21d90c, Func Offset: 0x13c
	// Line 1560, Address: 0x21d918, Func Offset: 0x148
	// Line 1562, Address: 0x21d928, Func Offset: 0x158
	// Line 1564, Address: 0x21d934, Func Offset: 0x164
	// Line 1566, Address: 0x21d940, Func Offset: 0x170
	// Line 1567, Address: 0x21d948, Func Offset: 0x178
	// Line 1568, Address: 0x21d958, Func Offset: 0x188
	// Func End, Address: 0x21d970, Func Offset: 0x1a0
}

// 
// Start address: 0x21d970
void bhDrawNtxEffect3D(unsigned int* owp, int ct)
{
	//_anon37 vec;
	//_anon37 pc;
	//_anon37 pb;
	//_anon37 pa;
	//_anon0* op;
	// Line 1574, Address: 0x21d970, Func Offset: 0
	// Line 1579, Address: 0x21d984, Func Offset: 0x14
	// Line 1580, Address: 0x21d994, Func Offset: 0x24
	// Line 1581, Address: 0x21d9a0, Func Offset: 0x30
	// Line 1582, Address: 0x21d9a8, Func Offset: 0x38
	// Line 1584, Address: 0x21d9ac, Func Offset: 0x3c
	// Line 1588, Address: 0x21d9f8, Func Offset: 0x88
	// Line 1589, Address: 0x21da00, Func Offset: 0x90
	// Line 1592, Address: 0x21da08, Func Offset: 0x98
	// Line 1593, Address: 0x21da18, Func Offset: 0xa8
	// Line 1595, Address: 0x21da28, Func Offset: 0xb8
	// Line 1597, Address: 0x21da38, Func Offset: 0xc8
	// Line 1598, Address: 0x21da40, Func Offset: 0xd0
	// Line 1600, Address: 0x21da60, Func Offset: 0xf0
	// Line 1601, Address: 0x21da6c, Func Offset: 0xfc
	// Line 1602, Address: 0x21da74, Func Offset: 0x104
	// Line 1603, Address: 0x21da80, Func Offset: 0x110
	// Line 1604, Address: 0x21da88, Func Offset: 0x118
	// Line 1608, Address: 0x21da90, Func Offset: 0x120
	// Line 1609, Address: 0x21dabc, Func Offset: 0x14c
	// Line 1610, Address: 0x21dad0, Func Offset: 0x160
	// Line 1611, Address: 0x21dae4, Func Offset: 0x174
	// Line 1612, Address: 0x21dae8, Func Offset: 0x178
	// Line 1613, Address: 0x21daf0, Func Offset: 0x180
	// Line 1614, Address: 0x21dafc, Func Offset: 0x18c
	// Line 1615, Address: 0x21db10, Func Offset: 0x1a0
	// Line 1616, Address: 0x21db18, Func Offset: 0x1a8
	// Line 1617, Address: 0x21db24, Func Offset: 0x1b4
	// Line 1618, Address: 0x21db3c, Func Offset: 0x1cc
	// Line 1619, Address: 0x21db68, Func Offset: 0x1f8
	// Line 1621, Address: 0x21db9c, Func Offset: 0x22c
	// Line 1622, Address: 0x21dba0, Func Offset: 0x230
	// Line 1624, Address: 0x21dbac, Func Offset: 0x23c
	// Line 1627, Address: 0x21dbc0, Func Offset: 0x250
	// Line 1628, Address: 0x21dbd0, Func Offset: 0x260
	// Line 1629, Address: 0x21dbe4, Func Offset: 0x274
	// Line 1630, Address: 0x21dbf8, Func Offset: 0x288
	// Line 1631, Address: 0x21dc08, Func Offset: 0x298
	// Line 1632, Address: 0x21dc1c, Func Offset: 0x2ac
	// Line 1633, Address: 0x21dc30, Func Offset: 0x2c0
	// Line 1634, Address: 0x21dc44, Func Offset: 0x2d4
	// Line 1635, Address: 0x21dc4c, Func Offset: 0x2dc
	// Line 1636, Address: 0x21dc68, Func Offset: 0x2f8
	// Line 1637, Address: 0x21dc70, Func Offset: 0x300
	// Line 1638, Address: 0x21dc78, Func Offset: 0x308
	// Line 1640, Address: 0x21dc80, Func Offset: 0x310
	// Line 1661, Address: 0x21dc90, Func Offset: 0x320
	// Line 1662, Address: 0x21dc9c, Func Offset: 0x32c
	// Line 1664, Address: 0x21dca8, Func Offset: 0x338
	// Line 1666, Address: 0x21dcb4, Func Offset: 0x344
	// Line 1668, Address: 0x21dcc0, Func Offset: 0x350
	// Line 1670, Address: 0x21dccc, Func Offset: 0x35c
	// Line 1671, Address: 0x21dcd4, Func Offset: 0x364
	// Line 1672, Address: 0x21dce8, Func Offset: 0x378
	// Line 1673, Address: 0x21dcf0, Func Offset: 0x380
	// Func End, Address: 0x21dd08, Func Offset: 0x398
}

// 
// Start address: 0x21dd10
void bhDrawTrsEffect3D(unsigned int* owp, int ct)
{
	//_anon37 vec;
	//_anon37 pc;
	//_anon37 pb;
	//_anon37 pa;
	//_anon0* op;
	// Line 1679, Address: 0x21dd10, Func Offset: 0
	// Line 1685, Address: 0x21dd24, Func Offset: 0x14
	// Line 1679, Address: 0x21dd2c, Func Offset: 0x1c
	// Line 1685, Address: 0x21dd30, Func Offset: 0x20
	// Line 1686, Address: 0x21dd38, Func Offset: 0x28
	// Line 1687, Address: 0x21dd40, Func Offset: 0x30
	// Line 1689, Address: 0x21dd44, Func Offset: 0x34
	// Line 1696, Address: 0x21de30, Func Offset: 0x120
	// Line 1697, Address: 0x21de38, Func Offset: 0x128
	// Line 1700, Address: 0x21de40, Func Offset: 0x130
	// Line 1701, Address: 0x21de50, Func Offset: 0x140
	// Line 1703, Address: 0x21de60, Func Offset: 0x150
	// Line 1705, Address: 0x21de70, Func Offset: 0x160
	// Line 1706, Address: 0x21de84, Func Offset: 0x174
	// Line 1707, Address: 0x21de8c, Func Offset: 0x17c
	// Line 1708, Address: 0x21de94, Func Offset: 0x184
	// Line 1709, Address: 0x21dea4, Func Offset: 0x194
	// Line 1722, Address: 0x21debc, Func Offset: 0x1ac
	// Line 1723, Address: 0x21dee8, Func Offset: 0x1d8
	// Line 1724, Address: 0x21def0, Func Offset: 0x1e0
	// Line 1726, Address: 0x21def8, Func Offset: 0x1e8
	// Line 1730, Address: 0x21df08, Func Offset: 0x1f8
	// Line 1731, Address: 0x21df10, Func Offset: 0x200
	// Line 1733, Address: 0x21df30, Func Offset: 0x220
	// Line 1734, Address: 0x21df3c, Func Offset: 0x22c
	// Line 1735, Address: 0x21df44, Func Offset: 0x234
	// Line 1736, Address: 0x21df50, Func Offset: 0x240
	// Line 1737, Address: 0x21df58, Func Offset: 0x248
	// Line 1741, Address: 0x21df60, Func Offset: 0x250
	// Line 1742, Address: 0x21df8c, Func Offset: 0x27c
	// Line 1743, Address: 0x21dfa0, Func Offset: 0x290
	// Line 1744, Address: 0x21dfb4, Func Offset: 0x2a4
	// Line 1745, Address: 0x21dfb8, Func Offset: 0x2a8
	// Line 1746, Address: 0x21dfc0, Func Offset: 0x2b0
	// Line 1747, Address: 0x21dfcc, Func Offset: 0x2bc
	// Line 1748, Address: 0x21dfe0, Func Offset: 0x2d0
	// Line 1749, Address: 0x21dfe8, Func Offset: 0x2d8
	// Line 1750, Address: 0x21dff4, Func Offset: 0x2e4
	// Line 1751, Address: 0x21e00c, Func Offset: 0x2fc
	// Line 1752, Address: 0x21e038, Func Offset: 0x328
	// Line 1754, Address: 0x21e06c, Func Offset: 0x35c
	// Line 1755, Address: 0x21e070, Func Offset: 0x360
	// Line 1757, Address: 0x21e07c, Func Offset: 0x36c
	// Line 1760, Address: 0x21e090, Func Offset: 0x380
	// Line 1761, Address: 0x21e0a0, Func Offset: 0x390
	// Line 1762, Address: 0x21e0b4, Func Offset: 0x3a4
	// Line 1763, Address: 0x21e0c8, Func Offset: 0x3b8
	// Line 1764, Address: 0x21e0d8, Func Offset: 0x3c8
	// Line 1765, Address: 0x21e0ec, Func Offset: 0x3dc
	// Line 1766, Address: 0x21e100, Func Offset: 0x3f0
	// Line 1767, Address: 0x21e114, Func Offset: 0x404
	// Line 1768, Address: 0x21e11c, Func Offset: 0x40c
	// Line 1769, Address: 0x21e138, Func Offset: 0x428
	// Line 1770, Address: 0x21e140, Func Offset: 0x430
	// Line 1771, Address: 0x21e148, Func Offset: 0x438
	// Line 1773, Address: 0x21e150, Func Offset: 0x440
	// Line 1788, Address: 0x21e160, Func Offset: 0x450
	// Line 1789, Address: 0x21e16c, Func Offset: 0x45c
	// Line 1793, Address: 0x21e178, Func Offset: 0x468
	// Line 1794, Address: 0x21e1a0, Func Offset: 0x490
	// Line 1795, Address: 0x21e1b0, Func Offset: 0x4a0
	// Line 1796, Address: 0x21e1b8, Func Offset: 0x4a8
	// Line 1800, Address: 0x21e1c8, Func Offset: 0x4b8
	// Line 1802, Address: 0x21e1d4, Func Offset: 0x4c4
	// Line 1804, Address: 0x21e1e0, Func Offset: 0x4d0
	// Line 1805, Address: 0x21e1e8, Func Offset: 0x4d8
	// Line 1806, Address: 0x21e1f8, Func Offset: 0x4e8
	// Func End, Address: 0x21e210, Func Offset: 0x500
}

// 
// Start address: 0x21e210
void bhDrawOpqEffect3D(unsigned int* owp, int ct)
{
	//_anon37 vec;
	//_anon37 pc;
	//_anon37 pb;
	//_anon37 pa;
	//_anon0* op;
	// Line 1812, Address: 0x21e210, Func Offset: 0
	// Line 1819, Address: 0x21e228, Func Offset: 0x18
	// Line 1820, Address: 0x21e238, Func Offset: 0x28
	// Line 1821, Address: 0x21e244, Func Offset: 0x34
	// Line 1822, Address: 0x21e250, Func Offset: 0x40
	// Line 1823, Address: 0x21e258, Func Offset: 0x48
	// Line 1825, Address: 0x21e25c, Func Offset: 0x4c
	// Line 1830, Address: 0x21e2b8, Func Offset: 0xa8
	// Line 1831, Address: 0x21e2c0, Func Offset: 0xb0
	// Line 1834, Address: 0x21e2c8, Func Offset: 0xb8
	// Line 1835, Address: 0x21e2d8, Func Offset: 0xc8
	// Line 1837, Address: 0x21e2e8, Func Offset: 0xd8
	// Line 1839, Address: 0x21e2f8, Func Offset: 0xe8
	// Line 1840, Address: 0x21e30c, Func Offset: 0xfc
	// Line 1841, Address: 0x21e314, Func Offset: 0x104
	// Line 1842, Address: 0x21e31c, Func Offset: 0x10c
	// Line 1843, Address: 0x21e32c, Func Offset: 0x11c
	// Line 1854, Address: 0x21e344, Func Offset: 0x134
	// Line 1855, Address: 0x21e370, Func Offset: 0x160
	// Line 1856, Address: 0x21e378, Func Offset: 0x168
	// Line 1858, Address: 0x21e380, Func Offset: 0x170
	// Line 1862, Address: 0x21e390, Func Offset: 0x180
	// Line 1863, Address: 0x21e398, Func Offset: 0x188
	// Line 1865, Address: 0x21e3b8, Func Offset: 0x1a8
	// Line 1866, Address: 0x21e3c4, Func Offset: 0x1b4
	// Line 1867, Address: 0x21e3cc, Func Offset: 0x1bc
	// Line 1868, Address: 0x21e3d8, Func Offset: 0x1c8
	// Line 1869, Address: 0x21e3e0, Func Offset: 0x1d0
	// Line 1873, Address: 0x21e3e8, Func Offset: 0x1d8
	// Line 1874, Address: 0x21e414, Func Offset: 0x204
	// Line 1875, Address: 0x21e428, Func Offset: 0x218
	// Line 1876, Address: 0x21e43c, Func Offset: 0x22c
	// Line 1877, Address: 0x21e440, Func Offset: 0x230
	// Line 1878, Address: 0x21e448, Func Offset: 0x238
	// Line 1879, Address: 0x21e454, Func Offset: 0x244
	// Line 1880, Address: 0x21e468, Func Offset: 0x258
	// Line 1881, Address: 0x21e470, Func Offset: 0x260
	// Line 1882, Address: 0x21e47c, Func Offset: 0x26c
	// Line 1883, Address: 0x21e494, Func Offset: 0x284
	// Line 1884, Address: 0x21e4c0, Func Offset: 0x2b0
	// Line 1886, Address: 0x21e4f4, Func Offset: 0x2e4
	// Line 1887, Address: 0x21e4f8, Func Offset: 0x2e8
	// Line 1889, Address: 0x21e504, Func Offset: 0x2f4
	// Line 1892, Address: 0x21e518, Func Offset: 0x308
	// Line 1893, Address: 0x21e528, Func Offset: 0x318
	// Line 1894, Address: 0x21e53c, Func Offset: 0x32c
	// Line 1895, Address: 0x21e550, Func Offset: 0x340
	// Line 1896, Address: 0x21e560, Func Offset: 0x350
	// Line 1897, Address: 0x21e574, Func Offset: 0x364
	// Line 1898, Address: 0x21e588, Func Offset: 0x378
	// Line 1899, Address: 0x21e59c, Func Offset: 0x38c
	// Line 1900, Address: 0x21e5a4, Func Offset: 0x394
	// Line 1901, Address: 0x21e5c0, Func Offset: 0x3b0
	// Line 1902, Address: 0x21e5c8, Func Offset: 0x3b8
	// Line 1903, Address: 0x21e5d0, Func Offset: 0x3c0
	// Line 1905, Address: 0x21e5d8, Func Offset: 0x3c8
	// Line 1921, Address: 0x21e5e8, Func Offset: 0x3d8
	// Line 1922, Address: 0x21e5f8, Func Offset: 0x3e8
	// Line 1923, Address: 0x21e608, Func Offset: 0x3f8
	// Line 1924, Address: 0x21e610, Func Offset: 0x400
	// Line 1928, Address: 0x21e620, Func Offset: 0x410
	// Line 1929, Address: 0x21e628, Func Offset: 0x418
	// Line 1930, Address: 0x21e638, Func Offset: 0x428
	// Func End, Address: 0x21e650, Func Offset: 0x440
}

// 
// Start address: 0x21e650
void bhDrawThlEffect3D(unsigned int* owp, int ct)
{
	int pt;
	float it;
	//_anon37 vc1;
	//_anon37 vc0;
	//_anon37 vec;
	//_anon37 pc;
	//_anon37 pb;
	//_anon37 pa;
	//_anon0* op;
	//_anon8* tvp;
	// Line 1936, Address: 0x21e650, Func Offset: 0
	// Line 1943, Address: 0x21e664, Func Offset: 0x14
	// Line 1936, Address: 0x21e668, Func Offset: 0x18
	// Line 1943, Address: 0x21e66c, Func Offset: 0x1c
	// Line 1936, Address: 0x21e670, Func Offset: 0x20
	// Line 1943, Address: 0x21e674, Func Offset: 0x24
	// Line 1944, Address: 0x21e67c, Func Offset: 0x2c
	// Line 1945, Address: 0x21e684, Func Offset: 0x34
	// Line 1947, Address: 0x21e688, Func Offset: 0x38
	// Line 1952, Address: 0x21e6e0, Func Offset: 0x90
	// Line 1953, Address: 0x21e6e8, Func Offset: 0x98
	// Line 1956, Address: 0x21e6f0, Func Offset: 0xa0
	// Line 1957, Address: 0x21e700, Func Offset: 0xb0
	// Line 1959, Address: 0x21e710, Func Offset: 0xc0
	// Line 1961, Address: 0x21e720, Func Offset: 0xd0
	// Line 1962, Address: 0x21e730, Func Offset: 0xe0
	// Line 1973, Address: 0x21e748, Func Offset: 0xf8
	// Line 1974, Address: 0x21e774, Func Offset: 0x124
	// Line 1975, Address: 0x21e77c, Func Offset: 0x12c
	// Line 1977, Address: 0x21e784, Func Offset: 0x134
	// Line 1978, Address: 0x21e794, Func Offset: 0x144
	// Line 1980, Address: 0x21e798, Func Offset: 0x148
	// Line 1981, Address: 0x21e7a0, Func Offset: 0x150
	// Line 1983, Address: 0x21e7c0, Func Offset: 0x170
	// Line 1984, Address: 0x21e7cc, Func Offset: 0x17c
	// Line 1985, Address: 0x21e7d4, Func Offset: 0x184
	// Line 1986, Address: 0x21e7e0, Func Offset: 0x190
	// Line 1987, Address: 0x21e7e8, Func Offset: 0x198
	// Line 1991, Address: 0x21e7f0, Func Offset: 0x1a0
	// Line 1992, Address: 0x21e81c, Func Offset: 0x1cc
	// Line 1993, Address: 0x21e830, Func Offset: 0x1e0
	// Line 1994, Address: 0x21e844, Func Offset: 0x1f4
	// Line 1995, Address: 0x21e848, Func Offset: 0x1f8
	// Line 1996, Address: 0x21e850, Func Offset: 0x200
	// Line 1997, Address: 0x21e85c, Func Offset: 0x20c
	// Line 1998, Address: 0x21e870, Func Offset: 0x220
	// Line 1999, Address: 0x21e878, Func Offset: 0x228
	// Line 2000, Address: 0x21e884, Func Offset: 0x234
	// Line 2001, Address: 0x21e89c, Func Offset: 0x24c
	// Line 2002, Address: 0x21e8c8, Func Offset: 0x278
	// Line 2004, Address: 0x21e8fc, Func Offset: 0x2ac
	// Line 2005, Address: 0x21e900, Func Offset: 0x2b0
	// Line 2008, Address: 0x21e90c, Func Offset: 0x2bc
	// Line 2011, Address: 0x21e920, Func Offset: 0x2d0
	// Line 2012, Address: 0x21e930, Func Offset: 0x2e0
	// Line 2013, Address: 0x21e940, Func Offset: 0x2f0
	// Line 2014, Address: 0x21e950, Func Offset: 0x300
	// Line 2015, Address: 0x21e960, Func Offset: 0x310
	// Line 2016, Address: 0x21e970, Func Offset: 0x320
	// Line 2017, Address: 0x21e980, Func Offset: 0x330
	// Line 2018, Address: 0x21e994, Func Offset: 0x344
	// Line 2019, Address: 0x21e99c, Func Offset: 0x34c
	// Line 2020, Address: 0x21e9b8, Func Offset: 0x368
	// Line 2021, Address: 0x21e9c0, Func Offset: 0x370
	// Line 2022, Address: 0x21e9c8, Func Offset: 0x378
	// Line 2024, Address: 0x21e9d0, Func Offset: 0x380
	// Line 2028, Address: 0x21e9e0, Func Offset: 0x390
	// Line 2032, Address: 0x21e9f4, Func Offset: 0x3a4
	// Line 2033, Address: 0x21e9fc, Func Offset: 0x3ac
	// Line 2034, Address: 0x21ea04, Func Offset: 0x3b4
	// Line 2035, Address: 0x21ea0c, Func Offset: 0x3bc
	// Line 2036, Address: 0x21ea14, Func Offset: 0x3c4
	// Line 2037, Address: 0x21ea28, Func Offset: 0x3d8
	// Line 2038, Address: 0x21ea38, Func Offset: 0x3e8
	// Line 2039, Address: 0x21ea50, Func Offset: 0x400
	// Line 2040, Address: 0x21ea90, Func Offset: 0x440
	// Line 2041, Address: 0x21eaac, Func Offset: 0x45c
	// Line 2042, Address: 0x21eab0, Func Offset: 0x460
	// Line 2044, Address: 0x21eab4, Func Offset: 0x464
	// Line 2045, Address: 0x21eabc, Func Offset: 0x46c
	// Line 2046, Address: 0x21eac0, Func Offset: 0x470
	// Line 2048, Address: 0x21ead8, Func Offset: 0x488
	// Line 2050, Address: 0x21eae4, Func Offset: 0x494
	// Line 2052, Address: 0x21eaf0, Func Offset: 0x4a0
	// Line 2053, Address: 0x21eb00, Func Offset: 0x4b0
	// Line 2056, Address: 0x21eb08, Func Offset: 0x4b8
	// Line 2057, Address: 0x21eb14, Func Offset: 0x4c4
	// Line 2059, Address: 0x21eb20, Func Offset: 0x4d0
	// Line 2061, Address: 0x21eb30, Func Offset: 0x4e0
	// Line 2063, Address: 0x21eb3c, Func Offset: 0x4ec
	// Line 2066, Address: 0x21eb48, Func Offset: 0x4f8
	// Line 2067, Address: 0x21eb50, Func Offset: 0x500
	// Line 2068, Address: 0x21eb60, Func Offset: 0x510
	// Func End, Address: 0x21eb7c, Func Offset: 0x52c
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
