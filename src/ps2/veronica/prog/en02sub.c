#include "../../../ps2/veronica/prog/en02sub.h"
#include "../../../ps2/veronica/prog/en02.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

typedef void (*bhEne02sub_Mode0_proc)(BH_PWORK* epw);
typedef void (*bhEne02sub_MoveMode2_proc)(BH_PWORK* epw);

static P_WORK Open[4] = 
{
    { 0x00000000, 0.0f    },
    { 0x00000006, 900.0f  },
    { 0x0000000A, 1000.0f },
    { 0x000003E7, 1000.0f }
};
static P_WORK Close[3] = 
{
    { 0x00000000, 1000.0f },
    { 0x0000000A, 0.0f    },
    { 0x000003E7, 0.0f    }
};
bhEne02sub_Mode0_proc bhEne02sub_Mode0[2] = 
{
	bhEne02sub_Init,
	bhEne02sub_Move
};
bhEne02sub_MoveMode2_proc bhEne02sub_MoveMode2[5] =
{
	bhEne02sub_MV00,
	bhEne02sub_MV01,
	bhEne02sub_MV02,
	bhEne02sub_MV03,
	bhEne02sub_MV04
};

// 100% matching!
void bhEne02sub(BH_PWORK* epw)
{
    bhEne02sub_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne02sub_Init(BH_PWORK* epw) 
{
    epw->mdflg |= 0x4;
    epw->mdflg |= 0x1;
    
    epw->flg2 |= 0x1;
    
    if (epw->type == 0) 
    {
        epw->car = 10.0f;
        epw->cah = 20.0f;
    }
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne02sub_Move(BH_PWORK* epw)
{
    bhEne02sub_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne02sub_MV00()
{

}

// 100% matching!
void bhEne02sub_MV01(BH_PWORK* epw)
{
	BH_PWORK* ep;

    switch (epw->mode3)
    { 
    case 0:
        epw->flg |= 0x48;
        
        epw->mdflg |= 0x2;
        epw->mdflg &= ~0x1;
        
        epw->ct0 = 0;
        
        ep = (BH_PWORK*)epw->lkwkp;
        
        epw->px = ep->px;
        epw->py = ep->py;
        epw->pz = ep->pz;
        
        epw->ay = (ep->ay + 32767) + 1;
        
        epw->car = 0.1f;
        
        epw->mode3++;
    case 1:
        epw->shp_ct = bhEne_GetShapeCnt(Open, epw->ct0);
        
        if (epw->ct0 > 30) 
        {
            epw->mode2 = 0;
        }
        
        epw->car += (10.0f - epw->car) / 16.0f;
        
        epw->ct0++;
        break;
    }
}

// 100% matching!
void bhEne02sub_MV02(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->mdflg |= 0x2;
        epw->mdflg &= ~0x1;
        
        epw->ct0 = 0;
        
        epw->car = 10.0f;
        
        epw->mode3++;
    case 1:
        epw->shp_ct = bhEne_GetShapeCnt(Close, epw->ct0);
        
        if (epw->ct0 > 10) 
        {
            epw->mdflg |= 0x1;
            epw->flg &= ~0x48;
            
            epw->mode2 = 0;
        }
        
        epw->car += -epw->car / 16.0f;
        
        epw->ct0++;
    }
}

// 100% matching!
void bhEne02sub_MV03(BH_PWORK* epw)
{
	BH_PWORK* ep;
    NJS_POINT3 pos;   

    ep = (BH_PWORK*)epw->lkwkp;
    
    switch (epw->mode3)
    {   
    case 0:
        epw->mdflg &= ~0x1;
            
        epw->yn = -2.0f;
        
        epw->ct0 = (int)(60.0f * (-rand() / -2.1474836E9f));
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            epw->mode3++;
        }
        
        break;
    case 2:
        if ((!(plp->flg & 0x4)) && (bhEne_AttackHitCheck(plp, (NJS_POINT3*)&epw->px, 5.0f)))
        {
            plp->flg |= 0x10004;
            plp->stflg |= 0x10000;
            
            plp->mode0 = 2;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
            
            plp->hp -= 20;
            
            if (plp->hp < 0) 
            {
                plp->hp = 0;
            }
        }
        
        epw->yn -= 0.4f;
        
        epw->py += epw->yn;
         
        if (epw->py < ep->py)
        {
            epw->py = ep->py;
            
            pos.x = epw->px;
            pos.z = epw->pz;
            pos.y = ep->py;
            
            bhEne02_SetSandEffect(ep, &pos, 7);
            
            epw->ct0 = 30;
            
            epw->mode3++;
        }
        
        break;
    case 3:
        epw->py -= 0.1f;
        
        if (epw->ct0-- == 0) 
        {
            epw->mdflg |= 0x1;
            
            epw->mode2 = 0;
        }

        break;
    }
}

// 100% matching!
void bhEne02sub_MV04(BH_PWORK* epw)
{
	BH_PWORK* ep;

    ep = (BH_PWORK*)epw->lkwkp;
    
    switch (epw->mode3)
    {                         
    case 0:
        epw->flg |= 0x48;
        epw->mdflg &= ~0x1;
        
        epw->ct0 = 0;
        
        epw->px = ep->px + (20.0f * njSin(ep->ay));
        epw->pz = ep->pz + (20.0f * njCos(ep->ay));
        
        epw->ax = 0;
        epw->ay = ep->ay;
        
        epw->yn = ep->py - 5.0f;
        
        epw->spd = 1.0f;
        
        epw->mode3++;
    case 1:
        epw->ax += 2184;
        
        bhAddSpeed(epw, 0);
        
        epw->py = epw->yn + (2.0f * njSin((epw->ct0 * 2184) - 16384));
        
        bhEne02_SetSandEffect(ep, (NJS_POINT3*)&epw->px, 8);
        
        if (epw->ct0++ > 30)
        {
            epw->mdflg |= 0x1;
            epw->flg &= ~0x40;
            
            epw->mode2 = 0;
        }
        
        break;
    }
}
