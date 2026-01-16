#include "dread.h"
#include "binfunc.h"
#include "njplus.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_texture.h"
#include "pwksub.h"
#include "weapon.h"
#include "main.h"

/*char* mshp_tab[16]; - unused*/

// 100% matching!
void bhReadPlayerData()
{
    ML_WORK* mdlp;       
    MN_WORK* mtnp;       
    int i;                
    int plmdlsz;          
    unsigned int dt0;     
    unsigned int dt1;      
    unsigned char* datp;   
    unsigned char* plmdlp; 
    unsigned char* mempb;  
    unsigned char* plmtnp; 
    int temp; // not from the debugging symbols

    mempb = sys->memp;
    datp = sys->memp;
    
    dt0 = *(unsigned int*)datp;
    
    datp += 4;
    
    njMemCopy(sys->plmdlp, datp, dt0);
    
    plmdlp = sys->plmdlp;
    
    plp->mlwP = plp->mdl;
    
    mdlp = plp->mdl;
    
    plp->mdl_n = 0;
    
    while ((dt1 = *(unsigned int*)plmdlp) != -1)
    {
        if (dt1 != 0)
        {
            plmdlp += 4;
            
            if (*(unsigned int*)plmdlp == SKIN_MAGIC) 
            {
                plp->skp[plp->mdl_n] = (int*)&plmdlp[4];
            }
            else
            {
                bhMlbBinRealize(plmdlp, mdlp);
                
                if (plp->skp[plp->mdl_n] != NULL) 
                {
                    npSkinConvert(mdlp->objP, plp->skp[plp->mdl_n]);
                }
                
                plp->mbp[plp->mdl_n] = mdlp->objP;
                plp->txp[plp->mdl_n] = mdlp->texP;
                
                mdlp++;
                
                plp->mdl_n++;
            }
            
            plmdlp = &plmdlp[dt1];
        } 
        else 
        {
            plmdlp += 4;
        }
    }
    
    datp = &datp[dt0];  
    
    dt1 = *(unsigned int*)datp;
    
    datp += 4;
    
    njMemCopy(sys->plbmtp, datp, dt1);
    
    sys->bmt_size = dt1;
    
    plmtnp = sys->plbmtp;
    
    plp->mnwP = (MN_WORK*)sys->plmthp;
    plp->mnwPb = plp->mnwP;
    
    mtnp = plp->mnwP;
    
    while ((temp = *(unsigned int*)plmtnp) != -1) 
    {
        if (temp != 0) 
        {
            plmtnp += 4;
            
            bhMnbBinRealize(plmtnp, mtnp);
            
            plmtnp = &plmtnp[temp]; 
        } 
        else
        {
            mtnp->md2P = NULL;
            
            plmtnp += 4;
        }
        
        mtnp++;
    }

    datp = &datp[dt1];

    plmdlsz = *(unsigned int*)datp;
    
    datp += 4;
    
    njMemCopy(sys->plzmtp, datp, plmdlsz);
    
    datp = &datp[plmdlsz];
    
    for (i = 0; i < plp->mdl_n; i++) 
    {
        if (plp->mdl[i].texP != NULL) 
        {
            temp = *(unsigned int*)datp;
            
            if ((temp & 0x80000000)) 
            {
                datp += 4;
                
                datp = (unsigned char*)(((int)datp + 31) & ~0x1F);
                
                temp &= ~0x80000000;
            } 
            else 
            {
                datp += 4;
            }
            
            plp->mdl[i].flg |= 0x200;
            
            bhSetMemPvpTexture(plp->mdl[i].texP, datp, 0);
            
            datp = &datp[temp];
        } 
        else 
        {
            plp->mdl[i].flg &= ~0x200;
        }
    }
    
    sys->memp = (unsigned char*)(((int)&sys->plmdlp[dt0] + 256) & ~0xFF);
    
    for (i = 0; i < plp->mdl_n; i++) 
    {
        plp->mdl[i].owP = (O_WORK*)bhGetFreeMemory(plp->mdl[i].obj_num * sizeof(O_WORK), 32);
    }
    
    sys->hd_pos = *(NJS_POINT3*)&plp->mlwP->objP[5].pos;
    
    sys->memp = mempb;
}

// 100% matching! 
void bhReadWeaponData()
{
    O_WRK* op;             
    int sz;              
    int msz;               
    int wpn_no;            
    unsigned char* dp;   
    unsigned char* mp;   
    MN_WORK* mtnp;         
    int mtsz;              
    unsigned char* plmtnp; 
    int temp; // not from the debugging symbols

    wpn_no = plp->wpnr_no;
    
    dp = sys->memp;
    
    msz = *(unsigned int*)dp;
    
    dp += 4;
    
    op = sys->obwp;
    
    if ((!(sys->ss_flg & 0x100)) && (op->mlwP->texP != NULL)) 
    {
        njReleaseTexture(op->mlwP->texP);
        
        bhGarbageTexture(NULL, 0);
    }
    
    if (msz != 0) 
    {
        mp = sys->wrmdlp;
        
        npCopyMemory(mp, dp, msz);
        
        bhSetWeapon(op, wpn_no, 0);
        
        op->mlwP = op->mdl;
        
        bhMlbBinRealize(mp, op->mlwP);
    }
    
    dp = &dp[msz];
    
    temp = *(unsigned int*)dp;
    
    if ((temp & 0x80000000))
    {
        dp += 4;
        
        dp = (unsigned char*)(((int)dp + 63) & ~0x3F);
        
        temp &= ~0x80000000;
    }
    else 
    {
        dp += 4;
    }
    
    if (temp != 0) 
    {
        if (op->mlwP->texP != NULL)
        {
            op->mlwP->flg |= 0x200;
            
            bhSetMemPvpTexture(op->mlwP->texP, dp, 0);
        }
        
        op->mlwP->owP = (O_WORK*)(((int)&mp[msz] + 255) & ~0xFF);
        
        memset(op->mlwP->owP, 0, op->mlwP->obj_num * 80);
        
        op->mdl_no = 0;
    }
    
    dp = &dp[temp];
    
    msz = *(unsigned int*)dp;
    
    dp += 4;
    
    op = &sys->obwp[1]; 
    
    if ((!(sys->ss_flg & 0x100)) && (op->mlwP->texP != NULL))
    {
        njReleaseTexture(op->mlwP->texP);
        
        bhGarbageTexture(NULL, 0);
    }
    
    if (msz != 0) 
    {
        mp = sys->wlmdlp;
        
        npCopyMemory(mp, dp, msz);
        
        bhSetWeapon(op, wpn_no, 1);
        
        op->mlwP = op->mdl;
        
        bhMlbBinRealize(mp, op->mlwP);
    }
    
    dp = &dp[msz];
    
    sz = *(unsigned int*)dp;
    
    if ((sz & 0x80000000))
    {
        dp += 4;
        
        dp = (unsigned char*)(((int)dp + 63) & ~0x3F);
        
        sz &= ~0x80000000;
    }
    else  
    {
        dp += 4;
    }
    
    if (sz != 0)
    {
        if (op->mlwP->texP != NULL)
        {
            op->mlwP->flg |= 0x200;
            
            bhSetMemPvpTexture(op->mlwP->texP, dp, 0);
        }
        
        op->mlwP->owP = (O_WORK*)(((int)&mp[msz] + 255) & ~0xFF);
        
        memset(op->mlwP->owP, 0, op->mlwP->obj_num * 80);
        
        op->mdl_no = 0;
    }
    
    dp = &dp[sz];
    
    sz = *(unsigned int*)dp;
    
    if (sz != 0) 
    {
        plmtnp = sys->plwmtp;

        dp += 4;
        
        npCopyMemory(plmtnp, dp, sz);
        
        sys->wmt_size = sz;
        
        for (mtnp = &plp->mnwP[100]; (mtsz = *(unsigned int*)plmtnp) != -1; mtnp++) 
        {
            if (mtsz != 0) 
            {
                dp = plmtnp + 4;
                
                bhMnbBinRealize(dp, mtnp);
                
                plmtnp = &dp[mtsz];
            } 
            else 
            {
                plmtnp += 4;
            }
        }
    }
}

// 94.11% matching
unsigned char* bhKeepObjWork(ML_WORK* mp, unsigned char* sp)
{
    unsigned char* owp; // not from the debugging symbols

    owp = (unsigned char*)(((int)sp + 15) & ~0xF);
    
    mp->owP = (O_WORK*)owp;
    
    memset(owp, 0, mp->obj_num * 80);
    
    owp += mp->obj_num * 80;
    
    return owp;
}
