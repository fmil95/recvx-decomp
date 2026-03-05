#include "face.h"
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

// 
// Start address: 0x298250
void bhControlMask(BH_PWORK* pp)
{
	void* fbak;
	//_anon11* lip;
	//_anon2* fm;
	// Line 131, Address: 0x298250, Func Offset: 0
	// Line 136, Address: 0x298268, Func Offset: 0x18
	// Line 137, Address: 0x298274, Func Offset: 0x24
	// Line 140, Address: 0x298298, Func Offset: 0x48
	// Line 146, Address: 0x2982a0, Func Offset: 0x50
	// Line 143, Address: 0x2982a4, Func Offset: 0x54
	// Line 146, Address: 0x2982a8, Func Offset: 0x58
	// Line 147, Address: 0x2982b4, Func Offset: 0x64
	// Line 148, Address: 0x2982c0, Func Offset: 0x70
	// Line 150, Address: 0x2982e0, Func Offset: 0x90
	// Line 153, Address: 0x298308, Func Offset: 0xb8
	// Line 154, Address: 0x29831c, Func Offset: 0xcc
	// Line 155, Address: 0x298328, Func Offset: 0xd8
	// Line 156, Address: 0x29832c, Func Offset: 0xdc
	// Line 155, Address: 0x298330, Func Offset: 0xe0
	// Line 156, Address: 0x298334, Func Offset: 0xe4
	// Line 157, Address: 0x298340, Func Offset: 0xf0
	// Line 159, Address: 0x298364, Func Offset: 0x114
	// Line 160, Address: 0x29836c, Func Offset: 0x11c
	// Line 163, Address: 0x298370, Func Offset: 0x120
	// Line 160, Address: 0x298374, Func Offset: 0x124
	// Line 161, Address: 0x298380, Func Offset: 0x130
	// Line 162, Address: 0x29838c, Func Offset: 0x13c
	// Line 163, Address: 0x298394, Func Offset: 0x144
	// Line 164, Address: 0x2983a4, Func Offset: 0x154
	// Line 169, Address: 0x2983c4, Func Offset: 0x174
	// Line 170, Address: 0x2983d8, Func Offset: 0x188
	// Line 171, Address: 0x2983e4, Func Offset: 0x194
	// Line 174, Address: 0x2983e8, Func Offset: 0x198
	// Line 171, Address: 0x2983ec, Func Offset: 0x19c
	// Line 172, Address: 0x2983f0, Func Offset: 0x1a0
	// Line 173, Address: 0x2983f8, Func Offset: 0x1a8
	// Line 177, Address: 0x298400, Func Offset: 0x1b0
	// Line 178, Address: 0x298408, Func Offset: 0x1b8
	// Line 182, Address: 0x29840c, Func Offset: 0x1bc
	// Line 200, Address: 0x298420, Func Offset: 0x1d0
	// Line 203, Address: 0x29842c, Func Offset: 0x1dc
	// Line 210, Address: 0x298434, Func Offset: 0x1e4
	// Line 203, Address: 0x298440, Func Offset: 0x1f0
	// Line 204, Address: 0x298448, Func Offset: 0x1f8
	// Line 210, Address: 0x29844c, Func Offset: 0x1fc
	// Line 204, Address: 0x298450, Func Offset: 0x200
	// Line 207, Address: 0x298454, Func Offset: 0x204
	// Line 205, Address: 0x298458, Func Offset: 0x208
	// Line 207, Address: 0x29845c, Func Offset: 0x20c
	// Line 210, Address: 0x298464, Func Offset: 0x214
	// Line 211, Address: 0x29848c, Func Offset: 0x23c
	// Line 213, Address: 0x2984ac, Func Offset: 0x25c
	// Line 217, Address: 0x2984b0, Func Offset: 0x260
	// Line 219, Address: 0x2984c4, Func Offset: 0x274
	// Line 220, Address: 0x2984d0, Func Offset: 0x280
	// Line 221, Address: 0x2984dc, Func Offset: 0x28c
	// Line 222, Address: 0x2984f8, Func Offset: 0x2a8
	// Line 223, Address: 0x298508, Func Offset: 0x2b8
	// Line 224, Address: 0x298510, Func Offset: 0x2c0
	// Line 225, Address: 0x298528, Func Offset: 0x2d8
	// Line 226, Address: 0x298538, Func Offset: 0x2e8
	// Line 229, Address: 0x298540, Func Offset: 0x2f0
	// Line 230, Address: 0x298548, Func Offset: 0x2f8
	// Line 231, Address: 0x298558, Func Offset: 0x308
	// Line 237, Address: 0x298560, Func Offset: 0x310
	// Line 238, Address: 0x298574, Func Offset: 0x324
	// Line 240, Address: 0x29857c, Func Offset: 0x32c
	// Line 246, Address: 0x298580, Func Offset: 0x330
	// Line 238, Address: 0x298584, Func Offset: 0x334
	// Line 239, Address: 0x29858c, Func Offset: 0x33c
	// Line 240, Address: 0x298594, Func Offset: 0x344
	// Line 241, Address: 0x2985a4, Func Offset: 0x354
	// Line 242, Address: 0x2985b0, Func Offset: 0x360
	// Line 243, Address: 0x2985bc, Func Offset: 0x36c
	// Line 244, Address: 0x2985c8, Func Offset: 0x378
	// Line 245, Address: 0x2985d4, Func Offset: 0x384
	// Line 246, Address: 0x2985d8, Func Offset: 0x388
	// Line 276, Address: 0x2985e8, Func Offset: 0x398
	// Line 279, Address: 0x29862c, Func Offset: 0x3dc
	// Line 281, Address: 0x298634, Func Offset: 0x3e4
	// Line 282, Address: 0x298648, Func Offset: 0x3f8
	// Line 283, Address: 0x29865c, Func Offset: 0x40c
	// Line 284, Address: 0x298674, Func Offset: 0x424
	// Line 285, Address: 0x29868c, Func Offset: 0x43c
	// Line 286, Address: 0x2986a4, Func Offset: 0x454
	// Line 336, Address: 0x2986bc, Func Offset: 0x46c
	// Func End, Address: 0x2986d8, Func Offset: 0x488
	scePrintf("bhControlMask - UNIMPLEMENTED!\n");
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
