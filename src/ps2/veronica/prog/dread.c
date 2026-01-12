#include "dread.h"
#include "binfunc.h"
#include "njplus.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_texture.h"
#include "weapon.h"
#include "main.h"

/*char* mshp_tab[16];
_anon18* sys;
BH_PWORK* plp;
_anon11* rom;
char BIO_CURRENT[0];*/

// 
// Start address: 0x2c9ca0
void bhReadPlayerData()
{
	unsigned char* plmtnp;
	unsigned char* mempb;
	unsigned char* plmdlp;
	unsigned char* datp;
	unsigned int dt1;
	unsigned int dt0;
	int plmdlsz;
	int i;
	//_anon4* mtnp;
	//_anon13* mdlp;
	// Line 81, Address: 0x2c9ca0, Func Offset: 0
	// Line 89, Address: 0x2c9cc4, Func Offset: 0x24
	// Line 98, Address: 0x2c9cd8, Func Offset: 0x38
	// Line 96, Address: 0x2c9cdc, Func Offset: 0x3c
	// Line 98, Address: 0x2c9ce0, Func Offset: 0x40
	// Line 89, Address: 0x2c9ce4, Func Offset: 0x44
	// Line 98, Address: 0x2c9ce8, Func Offset: 0x48
	// Line 97, Address: 0x2c9cec, Func Offset: 0x4c
	// Line 98, Address: 0x2c9cf0, Func Offset: 0x50
	// Line 101, Address: 0x2c9cfc, Func Offset: 0x5c
	// Line 102, Address: 0x2c9d04, Func Offset: 0x64
	// Line 101, Address: 0x2c9d0c, Func Offset: 0x6c
	// Line 102, Address: 0x2c9d18, Func Offset: 0x78
	// Line 103, Address: 0x2c9d20, Func Offset: 0x80
	// Line 105, Address: 0x2c9d2c, Func Offset: 0x8c
	// Line 106, Address: 0x2c9d34, Func Offset: 0x94
	// Line 107, Address: 0x2c9d3c, Func Offset: 0x9c
	// Line 108, Address: 0x2c9d40, Func Offset: 0xa0
	// Line 109, Address: 0x2c9d54, Func Offset: 0xb4
	// Line 110, Address: 0x2c9d6c, Func Offset: 0xcc
	// Line 111, Address: 0x2c9d74, Func Offset: 0xd4
	// Line 112, Address: 0x2c9d80, Func Offset: 0xe0
	// Line 113, Address: 0x2c9da0, Func Offset: 0x100
	// Line 115, Address: 0x2c9da8, Func Offset: 0x108
	// Line 116, Address: 0x2c9db8, Func Offset: 0x118
	// Line 115, Address: 0x2c9dbc, Func Offset: 0x11c
	// Line 116, Address: 0x2c9dc8, Func Offset: 0x128
	// Line 119, Address: 0x2c9dd4, Func Offset: 0x134
	// Line 118, Address: 0x2c9dd8, Func Offset: 0x138
	// Line 116, Address: 0x2c9ddc, Func Offset: 0x13c
	// Line 119, Address: 0x2c9de8, Func Offset: 0x148
	// Line 122, Address: 0x2c9df8, Func Offset: 0x158
	// Line 123, Address: 0x2c9e00, Func Offset: 0x160
	// Line 125, Address: 0x2c9e04, Func Offset: 0x164
	// Line 131, Address: 0x2c9e18, Func Offset: 0x178
	// Line 127, Address: 0x2c9e20, Func Offset: 0x180
	// Line 129, Address: 0x2c9e24, Func Offset: 0x184
	// Line 131, Address: 0x2c9e28, Func Offset: 0x188
	// Line 130, Address: 0x2c9e34, Func Offset: 0x194
	// Line 131, Address: 0x2c9e38, Func Offset: 0x198
	// Line 132, Address: 0x2c9e44, Func Offset: 0x1a4
	// Line 134, Address: 0x2c9e58, Func Offset: 0x1b8
	// Line 135, Address: 0x2c9e60, Func Offset: 0x1c0
	// Line 134, Address: 0x2c9e68, Func Offset: 0x1c8
	// Line 135, Address: 0x2c9e74, Func Offset: 0x1d4
	// Line 136, Address: 0x2c9e84, Func Offset: 0x1e4
	// Line 137, Address: 0x2c9e90, Func Offset: 0x1f0
	// Line 136, Address: 0x2c9e94, Func Offset: 0x1f4
	// Line 137, Address: 0x2c9e98, Func Offset: 0x1f8
	// Line 138, Address: 0x2c9e9c, Func Offset: 0x1fc
	// Line 139, Address: 0x2c9ea4, Func Offset: 0x204
	// Line 140, Address: 0x2c9eac, Func Offset: 0x20c
	// Line 141, Address: 0x2c9eb0, Func Offset: 0x210
	// Line 144, Address: 0x2c9ebc, Func Offset: 0x21c
	// Line 146, Address: 0x2c9ec4, Func Offset: 0x224
	// Line 145, Address: 0x2c9ec8, Func Offset: 0x228
	// Line 147, Address: 0x2c9ecc, Func Offset: 0x22c
	// Line 148, Address: 0x2c9ed0, Func Offset: 0x230
	// Line 149, Address: 0x2c9ed4, Func Offset: 0x234
	// Line 155, Address: 0x2c9ee8, Func Offset: 0x248
	// Line 151, Address: 0x2c9ef0, Func Offset: 0x250
	// Line 153, Address: 0x2c9ef4, Func Offset: 0x254
	// Line 155, Address: 0x2c9ef8, Func Offset: 0x258
	// Line 154, Address: 0x2c9f04, Func Offset: 0x264
	// Line 155, Address: 0x2c9f08, Func Offset: 0x268
	// Line 157, Address: 0x2c9f14, Func Offset: 0x274
	// Line 160, Address: 0x2c9f18, Func Offset: 0x278
	// Line 161, Address: 0x2c9f24, Func Offset: 0x284
	// Line 162, Address: 0x2c9f34, Func Offset: 0x294
	// Line 163, Address: 0x2c9f38, Func Offset: 0x298
	// Line 165, Address: 0x2c9f48, Func Offset: 0x2a8
	// Line 166, Address: 0x2c9f54, Func Offset: 0x2b4
	// Line 165, Address: 0x2c9f58, Func Offset: 0x2b8
	// Line 167, Address: 0x2c9f5c, Func Offset: 0x2bc
	// Line 168, Address: 0x2c9f64, Func Offset: 0x2c4
	// Line 171, Address: 0x2c9f68, Func Offset: 0x2c8
	// Line 172, Address: 0x2c9f6c, Func Offset: 0x2cc
	// Line 171, Address: 0x2c9f74, Func Offset: 0x2d4
	// Line 172, Address: 0x2c9f7c, Func Offset: 0x2dc
	// Line 175, Address: 0x2c9f90, Func Offset: 0x2f0
	// Line 176, Address: 0x2c9f98, Func Offset: 0x2f8
	// Line 178, Address: 0x2c9fac, Func Offset: 0x30c
	// Line 180, Address: 0x2c9fc8, Func Offset: 0x328
	// Line 181, Address: 0x2c9fd4, Func Offset: 0x334
	// Line 180, Address: 0x2c9fdc, Func Offset: 0x33c
	// Line 181, Address: 0x2c9ffc, Func Offset: 0x35c
	// Line 182, Address: 0x2ca004, Func Offset: 0x364
	// Line 184, Address: 0x2ca028, Func Offset: 0x388
	// Line 182, Address: 0x2ca02c, Func Offset: 0x38c
	// Line 184, Address: 0x2ca038, Func Offset: 0x398
	// Line 186, Address: 0x2ca050, Func Offset: 0x3b0
	// Line 188, Address: 0x2ca078, Func Offset: 0x3d8
	// Line 186, Address: 0x2ca07c, Func Offset: 0x3dc
	// Line 188, Address: 0x2ca088, Func Offset: 0x3e8
	// Line 189, Address: 0x2ca098, Func Offset: 0x3f8
	// Func End, Address: 0x2ca0c0, Func Offset: 0x420
	scePrintf("bhReadPlayerData - UNIMPLEMENTED!\n");
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
