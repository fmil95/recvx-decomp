#include "face.h"
#include "face_bh.h"
#include "pwksub.h"
#include "main.h"

// 100% matching!
void bhInitMask(BH_PWORK* pp)
{
    int i;
    int j; // not from DWARF
	MASK_WORK* fm;

    pp->exp0 = bhGetFreeMemory(1092, 32);
    pp->exp1 = bhGetFreeMemory(sizeof(MASK_WORK), 32);
    pp->exp2 = bhGetFreeMemory(sizeof(LIP_WORK), 32);

    if (pp->mskp == NULL) 
    {
        pp->mdflg &= ~0x100;
        
        pp->mlwP->owP[6].flg |= 0x4;
        pp->mlwP->owP[7].flg |= 0x4;
        pp->mlwP->owP[8].flg |= 0x4;
        pp->mlwP->owP[9].flg |= 0x4;
        pp->mlwP->owP[10].flg |= 0x4;
        return;
    }
    
    for (i = 0, j = 0; i < 256; j += 4) 
    {
        i++;
        
        ((int*)&pp->exp0[j])[9] = 0; 
    } 
    
    ((int*)pp->exp0)[2] = 0;
    ((int*)pp->exp0)[5] = 0;
    
    fm = (MASK_WORK*)pp->exp1;
    
    fmCnkInitContext(fm, pp->mskp, pp->mlwP->objP, pp->mlwP);
    
    fmCnkSetMode(fm, 1);
    
    ((int*)pp->exp0)[8] = fm->head->nFace;
    
    ((int*)pp->exp0)[265] = (unsigned int)fm->face; 
    ((int*)pp->exp0)[267] = (unsigned int)fm->face; 
    
    *(int*)(&pp->exp0[(*(int*)(pp->exp0 + 8)) * 4] + 36) = (int)fm->list;
    
    pp->mlwP->owP[6].flg |= 0x4;
    pp->mlwP->owP[7].flg |= 0x4;
    pp->mlwP->owP[8].flg |= 0x4;
    pp->mlwP->owP[9].flg |= 0x4;
    pp->mlwP->owP[10].flg |= 0x4;
    pp->mlwP->owP[11].flg |= 0x4;
    pp->mlwP->owP[12].flg |= 0x4;
    pp->mlwP->owP[13].flg |= 0x4;
    pp->mlwP->owP[14].flg |= 0x4;
    
    ((int*)pp->exp0)[3] = 0;
    
    ((LIP_WORK*)pp->exp2)->flag = 0;
    
    bhSetLip(pp, ((int*)pp->exp0)[3]);
    
    ((int*)pp->exp0)[0] = 0;
    ((int*)pp->exp0)[4] = 0;
    ((int*)pp->exp0)[6] = 0;
    ((int*)pp->exp0)[7] = 0;
    ((int*)pp->exp0)[1] = 1;
    ((int*)pp->exp0)[272] = 0;
    
    pp->ko_num = 0;
}

// 100% matching!
void bhControlMask(BH_PWORK* pp)
{
    MASK_WORK* fm; 
    LIP_WORK* lip; 
    void* fbak;   

    if (pp->mskp != NULL) 
    {
        switch (((int*)pp->exp0)[1]) 
        {
        case 0:
            ((int*)pp->exp0)[1] = 1;
            break;
        case 1:
            fm = (MASK_WORK*)pp->exp1;
            lip = (LIP_WORK*)pp->exp2;
            
            if (!(pp->flg2 & 0x80)) 
            {
                ((int*)pp->exp0)[272]++;
                
                if (((int*)pp->exp0)[272] > 1)
                {
                    pp->flg2 |= 0x80;
                }
            }
            
            if ((sys->gm_flg & 0x200)) 
            {
                pp->flg2 &= ~0x80;
            }
            
            if ((((unsigned int*)pp->exp0)[0] & 0x8)) 
            {
                ((int*)pp->exp0)[0] &= ~0x8;
                
                ((int*)pp->exp0)[272] = 0;
                
                pp->flg2 &= ~0x80;
                
                if ((*(unsigned char*)((int*)pp->exp0)[266] == 0) || ((*(unsigned char*)((int*)pp->exp0)[266] & 0xFF) == pp->id)) 
                {
                    fm->fnum = *(int*)(((int*)pp->exp0)[266] + 4);
                    fm->face = (PARAM_WORK*)(((int*)pp->exp0)[266] + 8);
                    
                    fm->head->nFace = fm->fnum;
                    
                    ((int*)pp->exp0)[6] = ((int*)pp->exp0)[5];
                    
                    ((int*)pp->exp0)[7] = fmCnkGetLastFrame(fm);
                    
                    if (((int*)pp->exp0)[6] > ((int*)pp->exp0)[7]) 
                    {
                        ((int*)pp->exp0)[6] = 0;
                    }
                }
            }
            
            if ((((unsigned int*)pp->exp0)[0] & 0x4))
            {
                if (lip->flag == 0)
                {
                    lip->top = (unsigned char*)((int*)pp->exp0)[268];
                    
                    lip->ptr = lip->top;
                    
                    lip->cnt = 0;
                    
                    lip->time = 0;
                    
                    lip->flag = 1;
                }
            } 
            else
            {
                lip->flag = 0;
            }
            
            fmCnkSetCurrentFrame(fm, ((int*)pp->exp0)[6]);
            
            if (lip->flag != 0) 
            {
                pp->flg2 &= ~0x80;
                
                ((int*)pp->exp0)[272] = 0;
                
                fbak = fm->face;
                
                fm->face = (PARAM_WORK*)((int*)pp->exp0)[267];
                
                fmSetLipSyncParam(fm, (PARAM_WORK*)((unsigned char*)fm->face + (((int*)pp->exp0)[4] * 984)), lip, 0x3FFF000);
                
                if (lip->flag == 0) 
                {
                    ((int*)pp->exp0)[0] &= ~0x4;
                }
                
                fm->face = fbak;
            }
            
            if (((((unsigned int*)pp->exp0)[0] & 0x1)) && (!(((unsigned int*)pp->exp0)[0] & 0x10))) 
            {
                ((int*)pp->exp0)[6]++;
                
                if (((int*)pp->exp0)[6] >= ((int*)pp->exp0)[7])
                {
                    if (!(((unsigned int*)pp->exp0)[0] & 0x2)) 
                    {
                        ((int*)pp->exp0)[6] = ((int*)pp->exp0)[7] - 1;
                        
                        if (((int*)pp->exp0)[6] < 0) 
                        {
                            ((int*)pp->exp0)[6] = 0;
                        }
                        
                        ((int*)pp->exp0)[0] &= ~0x1;
                    } 
                    else 
                    {
                        ((int*)pp->exp0)[6] = 0;
                    }
                }
                else 
                {
                    pp->flg2 &= ~0x80;
                    
                    ((int*)pp->exp0)[272] = 0;
                }
            }
            
            if ((((unsigned int*)pp->exp0)[0] & 0x20))
            {
                pp->flg2 &= ~0x80;
                
                ((int*)pp->exp0)[272] = 0;
                
                ((int*)pp->exp0)[0] &= ~0x31;
                
                fm->fnum = ((int*)pp->exp0)[8];
                fm->face = (PARAM_WORK*)((int*)pp->exp0)[265];
                
                fm->head->nFace = fm->fnum;
                
                ((int*)pp->exp0)[267] = ((int*)pp->exp0)[265];
                ((int*)pp->exp0)[6] = 0;
                
                ((int*)pp->exp0)[7] = fmCnkGetLastFrame(fm);
            }
            
            if ((sys->loop_now == (sys->loop_ct - 1)) && (!(pp->flg2 & 0x80))) 
            {
                fmCnkCalcFace(fm);
                
                pp->mlwP->objP[7].ang[0] = fm->toothsrc->ang[0];
                pp->mlwP->objP[11].ang[0] = fm->tangorg->ang[0];
                
                pp->mlwP->objP[9].ang[0] = -fm->eyesrc[0]->ang[0];
                pp->mlwP->objP[9].ang[1] = -fm->eyesrc[0]->ang[1];
                
                pp->mlwP->objP[13].ang[0] = -fm->eyesrc[1]->ang[0];
                pp->mlwP->objP[13].ang[1] = -fm->eyesrc[1]->ang[1];
            }
            
            break;
        }
    }
}

// 100% matching!
int bhSetMask(BH_PWORK* pp, int msk_no, int frm_no)
{
    MASK_WORK* fm;        
    unsigned char* datp; 
    unsigned int sz;     
    int i;            

    fm = (MASK_WORK*)pp->exp1;

    ((int*)pp->exp0)[5] = frm_no;
    
    datp = sys->mspp;
    
    if ((datp == NULL) || (fm == NULL))
    {
        return 0;
    }
    
    i = msk_no + 1;
    
    while (i--) 
    {
        sz = *(unsigned int*)datp;
        
        if (sz == -1) 
        {
            return 0;
        }
        
        datp += 4;
        
        ((int*)pp->exp0)[266] = (int)datp;
        
        datp = &datp[sz]; 
    }
    
    ((int*)pp->exp0)[2] = msk_no;

    ((int*)pp->exp0)[0] |= 0x8;
    
    return 1;
}

// 100% matching!
int bhSetLip(BH_PWORK* pp, int mls_no)
{
    LIP_WORK* lip;        
    unsigned char* datp; 
    unsigned int sz;     
    int i;              
    
    datp = sys->lspp;
    
    lip = (LIP_WORK*)pp->exp2;
    
    if ((datp == NULL) || (lip == NULL))
    {
        return 0;
    }
    
    i = mls_no + 1;
    
    while (i--) 
    {
        sz = *(unsigned int*)datp;
        
        if (sz == -1) 
        {
            return 0;
        }
        
        datp += 4;
        
        ((int*)pp->exp0)[268] = (int)datp;
        
        datp = &datp[sz]; 
    }
    
    ((int*)pp->exp0)[3] = mls_no;
    
    return 1;
}
