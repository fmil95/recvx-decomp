#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"

static int mka_ang[3];

static const char NormalTbl[64] = 
{
     0,  1,  2,  3,  4,  5,  6,  7,
     8,  9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55,
    56, 57, 58, 59, 60, 61, 62, 63
};
static const NJS_MKEY_A_MOD NullMka;

// 99.94% matching (matches on GC)
int bhSetMotion(BH_PWORK* ewP, int add, int mode, void* datP) 
{
    float rate;           
    unsigned int* flgP;   
    unsigned short* atrP; 
    int frm_num;          

    flgP = &ewP->mnwP[ewP->mtn_no].flg;
    
    if (ewP->mnwP[ewP->mtn_no].datP != NULL)
    {
        if ((mode & 0x20)) 
        {
            rate = (1.0f / ewP->hokan_count) - (0.000015258789f * ewP->hokan_rate);
        } 
        else
        {
            rate = 0.000015258789f * (65536 - ewP->hokan_rate);
        }
        
        if (((mode & 0x8)) || ((*flgP & 0x20))) 
        {
            if (ewP->hokan_count == 0)
            {
                SetMtnSlow(ewP, datP, mode);
            }
            else 
            {
                SetMtnSlowHokan(ewP, datP, mode, rate);
            }
        }
        else if ((*flgP & 0x10))
        {
            if (ewP->hokan_count == 0)
            {
                SetMtnNormal(ewP, datP, mode);
            } 
            else
            {
                SetMtnNormalHokan(ewP, datP, mode, rate);
            }
        } 
        else if (ewP->hokan_count == 0) 
        {
            SetMtnFast(ewP, datP, mode);
        }
        else 
        {
            SetMtnFastHokan(ewP, datP, mode, rate);
        }
        
        atrP = ewP->mnwP[ewP->mtn_no].atrP;
        
        if (atrP != NULL) 
        {
            ewP->mtn_attr = atrP[ewP->frm_no >> 16];
        }
        
        frm_num = ewP->mnwP[ewP->mtn_no].frm_num << 16;
        
        if (((mode & 0x1)) && (ewP->frm_mode != 0)) 
        {
            ewP->frm_no -= add;
        } 
        else 
        {
            ewP->frm_no += add;
        }
        
        if ((mode & 0x1)) 
        {
            if ((0 >= ewP->frm_no) || (ewP->frm_no >= ((frm_num - 32768) - 32768))) 
            {
                ewP->frm_mode = ~ewP->frm_mode;
            }
        }
        else 
        {
            if (ewP->frm_no < 0) 
            {
                ewP->frm_no += frm_num;
                
                return -1;
            }
            
            if (ewP->frm_no >= frm_num) 
            {
                ewP->frm_no -= frm_num;
                
                return 1;
            }
        }
    }
    
    return 0;
}

// 100% matching!
static void SetMtnNormal(BH_PWORK* ewP, char* datP, int mode) 
{
    int flp_s;        
    float flp_f;          
    int obj_no;           
    NJS_MDATA2_MOD* md2P; 
    O_WORK* owP;       
    NJS_MKEY_F_MOD* mkfP; 
    float* posP;         
    NJS_MKEY_A_MOD* mkaP; 
    int* dstP;          

    if (!(mode & 0x2)) 
    {
        datP = NormalTbl;
    }
   
    obj_no = ewP->mnwP[ewP->mtn_no].obj_num;
    md2P   = ewP->mnwP[ewP->mtn_no].md2P; 
    
    if ((mode & 0x2))
    {
        flp_s = -1;
        flp_f = -1.0f;
    } 
    else 
    {
        flp_s = 1;
        flp_f = 1.0f;
    }
    
    for ( ; obj_no > 0; datP++) 
    {
        owP = &ewP->mlwP->owP[*datP];
        
        if (!(owP->flg & 0x4)) 
        {
            if (md2P->p[0] != NULL)
            {
                posP = ewP->mlwP->objP[*datP].pos;
                
                mkfP = md2P->p[0];
                mkfP += ewP->frm_no / 65536;
                
                posP[0] = mkfP->key[0] * flp_f;
                posP[1] = mkfP->key[1];
                posP[2] = mkfP->key[2];
            }
            
            if (!(owP->flg & 0x2))
            {
                dstP = ewP->mlwP->objP[*datP].ang;
                
                if (md2P->p[1] != NULL) 
                {
                    mkaP = md2P->p[1];
                    mkaP += ewP->frm_no / 65536;
                    
                    dstP[0] = mkaP->key[0];
                    dstP[1] = mkaP->key[1] * flp_s;
                    dstP[2] = mkaP->key[2] * flp_s;
                } 
                else 
                {
                    dstP[0] = dstP[0] = dstP[0] = 0;
                }
            }
            
            md2P++;
            obj_no--;
        }
    }
}

// 
// Start address: 0x12f960
void SetMtnNormalHokan(BH_PWORK* ewP, char* datP, int mode, float rate)
{
	short dlt;
	int* dstP;
	int sum;
	//_anon3* mkaP;
	int* angP;
	float* posP;
	//_anon0* mkfP;
	//_anon6* owP;
	//_anon2* md2P;
	int obj_no;
	float flp_f;
	int flp_s;
	// Line 229, Address: 0x12f960, Func Offset: 0
	// Line 231, Address: 0x12f988, Func Offset: 0x28
	// Line 229, Address: 0x12f98c, Func Offset: 0x2c
	// Line 231, Address: 0x12f998, Func Offset: 0x38
	// Line 236, Address: 0x12f9a8, Func Offset: 0x48
	// Line 237, Address: 0x12f9c0, Func Offset: 0x60
	// Line 239, Address: 0x12f9c4, Func Offset: 0x64
	// Line 240, Address: 0x12f9cc, Func Offset: 0x6c
	// Line 241, Address: 0x12f9d4, Func Offset: 0x74
	// Line 242, Address: 0x12f9dc, Func Offset: 0x7c
	// Line 245, Address: 0x12f9e8, Func Offset: 0x88
	// Line 246, Address: 0x12f9f4, Func Offset: 0x94
	// Line 248, Address: 0x12fa10, Func Offset: 0xb0
	// Line 251, Address: 0x12fa20, Func Offset: 0xc0
	// Line 253, Address: 0x12fa24, Func Offset: 0xc4
	// Line 254, Address: 0x12fa2c, Func Offset: 0xcc
	// Line 256, Address: 0x12fa40, Func Offset: 0xe0
	// Line 254, Address: 0x12fa44, Func Offset: 0xe4
	// Line 256, Address: 0x12fa50, Func Offset: 0xf0
	// Line 259, Address: 0x12fa60, Func Offset: 0x100
	// Line 260, Address: 0x12fa68, Func Offset: 0x108
	// Line 261, Address: 0x12fa74, Func Offset: 0x114
	// Line 262, Address: 0x12fa7c, Func Offset: 0x11c
	// Line 263, Address: 0x12fa80, Func Offset: 0x120
	// Line 264, Address: 0x12fa88, Func Offset: 0x128
	// Line 265, Address: 0x12faa4, Func Offset: 0x144
	// Line 266, Address: 0x12fabc, Func Offset: 0x15c
	// Line 268, Address: 0x12fad4, Func Offset: 0x174
	// Line 271, Address: 0x12fad8, Func Offset: 0x178
	// Line 273, Address: 0x12fae8, Func Offset: 0x188
	// Line 278, Address: 0x12faf0, Func Offset: 0x190
	// Line 273, Address: 0x12faf4, Func Offset: 0x194
	// Line 280, Address: 0x12fb10, Func Offset: 0x1b0
	// Line 281, Address: 0x12fb34, Func Offset: 0x1d4
	// Line 286, Address: 0x12fb40, Func Offset: 0x1e0
	// Line 296, Address: 0x12fb48, Func Offset: 0x1e8
	// Line 286, Address: 0x12fb4c, Func Offset: 0x1ec
	// Line 287, Address: 0x12fb50, Func Offset: 0x1f0
	// Line 288, Address: 0x12fb60, Func Offset: 0x200
	// Line 299, Address: 0x12fb70, Func Offset: 0x210
	// Line 300, Address: 0x12fbac, Func Offset: 0x24c
	// Line 302, Address: 0x12fbc0, Func Offset: 0x260
	// Line 303, Address: 0x12fbd4, Func Offset: 0x274
	// Line 305, Address: 0x12fbe8, Func Offset: 0x288
	// Line 308, Address: 0x12fc10, Func Offset: 0x2b0
	// Line 309, Address: 0x12fc48, Func Offset: 0x2e8
	// Line 311, Address: 0x12fc60, Func Offset: 0x300
	// Line 314, Address: 0x12fc68, Func Offset: 0x308
	// Line 315, Address: 0x12fc70, Func Offset: 0x310
	// Line 314, Address: 0x12fc74, Func Offset: 0x314
	// Line 315, Address: 0x12fc80, Func Offset: 0x320
	// Line 316, Address: 0x12fc8c, Func Offset: 0x32c
	// Line 324, Address: 0x12fca0, Func Offset: 0x340
	// Line 325, Address: 0x12fcd0, Func Offset: 0x370
	// Line 324, Address: 0x12fcd4, Func Offset: 0x374
	// Line 325, Address: 0x12fcdc, Func Offset: 0x37c
	// Line 326, Address: 0x12fd08, Func Offset: 0x3a8
	// Line 325, Address: 0x12fd0c, Func Offset: 0x3ac
	// Line 326, Address: 0x12fd14, Func Offset: 0x3b4
	// Line 333, Address: 0x12fd48, Func Offset: 0x3e8
	// Line 332, Address: 0x12fd4c, Func Offset: 0x3ec
	// Line 334, Address: 0x12fd50, Func Offset: 0x3f0
	// Line 338, Address: 0x12fd58, Func Offset: 0x3f8
	// Line 339, Address: 0x12fd64, Func Offset: 0x404
	// Func End, Address: 0x12fd94, Func Offset: 0x434
	scePrintf("SetMtnNormalHokan - UNIMPLEMENTED!\n");
}

// 99.53% matching
static void SetMtnFast(BH_PWORK* ewP, char* datP, int mode)
{
    float* keyP, *posP;     
    int flp;         
    int obj_no;          
    NJS_MDATA2_MOD* md2P; 
    O_WORK* owP;        
    NJS_MKEY_A_MOD* mkaP;
    int* dstP;           
    
    if (!(mode & 0x2))
    {
        datP = NormalTbl;
    }
    
    keyP = &((float*)ewP->mnwP[ewP->mtn_no].md2P->p[0])[(ewP->frm_no / 65536) * 3];
    posP = ewP->mlwP->objP[*datP].pos;
    
    posP[0] = keyP[0] * (((mode & 0x2)) ? -1.0f : 1.0f);
    posP[1] = keyP[1]; 
    posP[2] = keyP[2];
    
    obj_no = ewP->mnwP[ewP->mtn_no].obj_num;
    md2P   = ewP->mnwP[ewP->mtn_no].md2P;
    
    if ((mode & 0x2)) 
    {
        flp = -1;
    }
    else 
    {
        flp = 1;
    }
    
    while (obj_no > 0)
    {
        owP = &ewP->mlwP->owP[*datP];
        
        if (!(owP->flg & 0x4)) 
        { 
            if (!(owP->flg & 0x2)) 
            {
                dstP = ewP->mlwP->objP[*datP].ang;
                
                if (md2P->p[1] != NULL) 
                {
                    mkaP =  md2P->p[1];
                    mkaP += ewP->frm_no / 65536;
                    
                    dstP[0] = mkaP->key[0];
                    dstP[1] = mkaP->key[1] * flp;
                    dstP[2] = mkaP->key[2] * flp; 
                } 
                else 
                {
                    dstP[0] = 0;
                    dstP[1] = 0;
                    dstP[2] = 0;
                }
            }
            
            md2P++;
            obj_no--;
        }
        
        datP++;
    }
}

// 
// Start address: 0x12ff50
void SetMtnFastHokan(BH_PWORK* ewP, char* datP, int mode, float rate)
{
	short dlt;
	int* dstP;
	int sum;
	//_anon3* mkaP;
	int* angP;
	//_anon6* owP;
	//_anon2* md2P;
	int obj_no;
	int flp;
	float* posP;
	float* keyP;
	//float flp;
	int tmpS[3];
	int tmpD[3];
	// Line 418, Address: 0x12ff50, Func Offset: 0
	// Line 420, Address: 0x12ff74, Func Offset: 0x24
	// Line 425, Address: 0x12ff90, Func Offset: 0x40
	// Line 426, Address: 0x12ff94, Func Offset: 0x44
	// Line 425, Address: 0x12ff98, Func Offset: 0x48
	// Line 426, Address: 0x12ffa0, Func Offset: 0x50
	// Line 425, Address: 0x12ffa4, Func Offset: 0x54
	// Line 426, Address: 0x12ffac, Func Offset: 0x5c
	// Line 425, Address: 0x12ffb0, Func Offset: 0x60
	// Line 426, Address: 0x12ffd0, Func Offset: 0x80
	// Line 425, Address: 0x12ffe8, Func Offset: 0x98
	// Line 428, Address: 0x12ffec, Func Offset: 0x9c
	// Line 430, Address: 0x13000c, Func Offset: 0xbc
	// Line 431, Address: 0x130018, Func Offset: 0xc8
	// Line 432, Address: 0x130024, Func Offset: 0xd4
	// Line 433, Address: 0x13002c, Func Offset: 0xdc
	// Line 434, Address: 0x130030, Func Offset: 0xe0
	// Line 435, Address: 0x130038, Func Offset: 0xe8
	// Line 436, Address: 0x130054, Func Offset: 0x104
	// Line 437, Address: 0x13006c, Func Offset: 0x11c
	// Line 444, Address: 0x130084, Func Offset: 0x134
	// Line 447, Address: 0x130088, Func Offset: 0x138
	// Line 444, Address: 0x13008c, Func Offset: 0x13c
	// Line 447, Address: 0x130090, Func Offset: 0x140
	// Line 444, Address: 0x130098, Func Offset: 0x148
	// Line 449, Address: 0x1300ac, Func Offset: 0x15c
	// Line 450, Address: 0x1300b4, Func Offset: 0x164
	// Line 452, Address: 0x1300d0, Func Offset: 0x180
	// Line 453, Address: 0x1300e0, Func Offset: 0x190
	// Line 454, Address: 0x1300ec, Func Offset: 0x19c
	// Line 459, Address: 0x130100, Func Offset: 0x1b0
	// Line 454, Address: 0x130104, Func Offset: 0x1b4
	// Line 461, Address: 0x13010c, Func Offset: 0x1bc
	// Line 462, Address: 0x130130, Func Offset: 0x1e0
	// Line 467, Address: 0x130138, Func Offset: 0x1e8
	// Line 477, Address: 0x130140, Func Offset: 0x1f0
	// Line 467, Address: 0x130144, Func Offset: 0x1f4
	// Line 468, Address: 0x130148, Func Offset: 0x1f8
	// Line 469, Address: 0x130158, Func Offset: 0x208
	// Line 480, Address: 0x130168, Func Offset: 0x218
	// Line 481, Address: 0x1301a4, Func Offset: 0x254
	// Line 483, Address: 0x1301b8, Func Offset: 0x268
	// Line 484, Address: 0x1301cc, Func Offset: 0x27c
	// Line 486, Address: 0x1301e0, Func Offset: 0x290
	// Line 489, Address: 0x130208, Func Offset: 0x2b8
	// Line 490, Address: 0x130240, Func Offset: 0x2f0
	// Line 492, Address: 0x130258, Func Offset: 0x308
	// Line 495, Address: 0x130260, Func Offset: 0x310
	// Line 496, Address: 0x130268, Func Offset: 0x318
	// Line 495, Address: 0x13026c, Func Offset: 0x31c
	// Line 496, Address: 0x130278, Func Offset: 0x328
	// Line 497, Address: 0x130284, Func Offset: 0x334
	// Line 501, Address: 0x130298, Func Offset: 0x348
	// Line 506, Address: 0x1302a8, Func Offset: 0x358
	// Line 507, Address: 0x1302d8, Func Offset: 0x388
	// Line 506, Address: 0x1302dc, Func Offset: 0x38c
	// Line 507, Address: 0x1302e4, Func Offset: 0x394
	// Line 508, Address: 0x130310, Func Offset: 0x3c0
	// Line 507, Address: 0x130314, Func Offset: 0x3c4
	// Line 508, Address: 0x13031c, Func Offset: 0x3cc
	// Line 509, Address: 0x13034c, Func Offset: 0x3fc
	// Line 513, Address: 0x130354, Func Offset: 0x404
	// Line 514, Address: 0x130364, Func Offset: 0x414
	// Line 519, Address: 0x130378, Func Offset: 0x428
	// Line 520, Address: 0x1303b0, Func Offset: 0x460
	// Line 519, Address: 0x1303b8, Func Offset: 0x468
	// Line 520, Address: 0x1303c4, Func Offset: 0x474
	// Line 521, Address: 0x1303f4, Func Offset: 0x4a4
	// Line 520, Address: 0x1303fc, Func Offset: 0x4ac
	// Line 521, Address: 0x130408, Func Offset: 0x4b8
	// Line 523, Address: 0x130438, Func Offset: 0x4e8
	// Line 521, Address: 0x130444, Func Offset: 0x4f4
	// Line 523, Address: 0x13044c, Func Offset: 0x4fc
	// Line 526, Address: 0x130454, Func Offset: 0x504
	// Line 527, Address: 0x130458, Func Offset: 0x508
	// Line 528, Address: 0x13045c, Func Offset: 0x50c
	// Line 530, Address: 0x130460, Func Offset: 0x510
	// Line 534, Address: 0x130470, Func Offset: 0x520
	// Line 535, Address: 0x13047c, Func Offset: 0x52c
	// Func End, Address: 0x1304a4, Func Offset: 0x554
	scePrintf("SetMtnFastHokan - UNIMPLEMENTED!\n");
}

// 100% matching!
static void SetMtnSlow(BH_PWORK* ewP, char* datP, int mode)
{
    float frac;          
    MN_WORK* mnwP;     
    int src_no, dst_no;         
    int flp_s;         
    float flp_f;        
    int obj_no;          
    NJS_MDATA2_MOD* md2P; 
    O_WORK* owP;        
    NJS_MKEY_F_MOD* mkfP;
    float* posP;         
    int* angP;           
    NJS_MKEY_A_MOD* mkaP; 

    frac = 0.000015258789f * (ewP->frm_no & 0xFFFF);
    
    src_no = ewP->frm_no / 65536;
    
    mnwP = &ewP->mnwP[ewP->mtn_no];
    
    dst_no = src_no + 1;
    
    if (dst_no >= mnwP->frm_num)
    {
        dst_no = 0;
    }
    
    if (!(mode & 0x2)) 
    {
        datP = NormalTbl;
    }
    
    obj_no = mnwP->obj_num;
    md2P   = mnwP->md2P;
    
    if ((mode & 0x2))
    {
        flp_s = -1;
        flp_f = -1.0f;
    } 
    else 
    {
        flp_s = 1;
        flp_f = 1.0f;
    }
    
    for ( ; obj_no > 0; datP++) 
    {
        owP = &ewP->mlwP->owP[*datP];
        
        if (!(owP->flg & 0x4)) 
        {
            mkfP = md2P->p[0];
            
            if (mkfP != NULL)
            {
                float* srcP, *dstP; 

                srcP = mkfP[src_no].key; 
                dstP = mkfP[dst_no].key;

                posP = ewP->mlwP->objP[*datP].pos;
                
                posP[0] = flp_f * (srcP[0] + (frac * (dstP[0] - srcP[0])));
                posP[1] = srcP[1]          + (frac * (dstP[1] - srcP[1]));
                posP[2] = srcP[2]          + (frac * (dstP[2] - srcP[2]));
            }
            
            if (!(owP->flg & 0x2)) 
            {
                mkaP = md2P->p[1];
                
                angP = ewP->mlwP->objP[*datP].ang;
                
                if (mkaP != NULL) 
                {
                    short* srcP, *dstP;         
                    
                    srcP = (short*)mkaP[src_no].key; 
                    dstP = (short*)mkaP[dst_no].key;

                    angP[0] = srcP[0]          + (frac * (short)(dstP[0] - srcP[0]));
                    angP[1] = flp_s * (srcP[1] + (frac * (short)(dstP[1] - srcP[1])));
                    angP[2] = flp_s * (srcP[2] + (frac * (short)(dstP[2] - srcP[2])));
                } 
                else
                {
                    angP[0] = angP[0] = angP[0] = 0;
                }
            }
            
            md2P++;
            obj_no--;
        }
    } 
}

// 100% matching!
static void SetMtnSlowHokan(BH_PWORK* ewP, char* datP, int mode, float rate)
{
    float frac;         
    MN_WORK* mnwP;      
    int src_no, dst_no;        
    int flp_s;           
    float flp_f;         
    int obj_no;           
    NJS_MDATA2_MOD* md2P; 
    O_WORK* owP;        
    NJS_MKEY_F_MOD* mkfP; 
    float* posP;         
    int* angP;            
    NJS_MKEY_A_MOD* mkaP; 
    int* bufP;            
    int sum;            
    int* dstP;       
    short dlt;           

    frac = 0.000015258789f * (ewP->frm_no & 0xFFFF);
    
    src_no = ewP->frm_no / 65536;
    
    mnwP = &ewP->mnwP[ewP->mtn_no];
    
    dst_no = src_no + 1;
    
    if (dst_no >= mnwP->frm_num) 
    {
        dst_no = 0;
    }
    
    if (!(mode & 0x2)) 
    {
        datP = NormalTbl;
    }
    
    obj_no = mnwP->obj_num;
    md2P   = mnwP->md2P;
    
    if ((mode & 0x2)) 
    {
        flp_s = -1;
        flp_f = -1.0f;
    } 
    else 
    {
        flp_s = 1;
        flp_f = 1.0f;
    }
    
    for ( ; obj_no > 0; datP++)
    { 
        owP = &ewP->mlwP->owP[*datP];
        
        if (!(owP->flg & 0x4)) 
        {
            mkfP = md2P->p[0];
            
            if (mkfP != NULL) 
            {
                float* srcP, *dstP;         
                
                srcP = mkfP[src_no].key;
                dstP = mkfP[dst_no].key;
                
                posP = ewP->mlwP->objP[*datP].pos;
                
                if ((mode & 0x100)) 
                {
                    posP[0] = flp_f * (srcP[0] + (frac * (dstP[0] - srcP[0])));
                    posP[1] = srcP[1]          + (frac * (dstP[1] - srcP[1]));
                    posP[2] = srcP[2]          + (frac * (dstP[2] - srcP[2]));
                } 
                else 
                {
                    posP[0] += rate * ((flp_f *  (srcP[0] + (frac * (dstP[0] - srcP[0])))) - posP[0]);
                    posP[1] += rate           * ((srcP[1] + (frac * (dstP[1] - srcP[1])))  - posP[1]);
                    posP[2] += rate           * ((srcP[2] + (frac * (dstP[2] - srcP[2])))  - posP[2]);
                }
            }
            
            if (!(owP->flg & 0x2)) 
            {
                angP = ewP->mlwP->objP[*datP].ang;
                bufP = mka_ang;
                
                mkaP = md2P->p[1];
                
                if (mkaP != NULL) 
                {
                    short* srcP, *dstP;    
                    
                    srcP = (short*)mkaP[src_no].key;
                    dstP = (short*)mkaP[dst_no].key;
                    
                    bufP[0] = srcP[0]          + (frac * (short)(dstP[0] - srcP[0]));
                    bufP[1] = flp_s * (srcP[1] + (frac * (short)(dstP[1] - srcP[1])));
                    bufP[2] = flp_s * (srcP[2] + (frac * (short)(dstP[2] - srcP[2])));
                } 
                else 
                {
                    bufP[0] = bufP[0] = bufP[0] = 0;
                } 
                
                dstP = mka_ang;
                
                dlt = dstP[0] - angP[0];
                
                if (dlt < 0) 
                {
                    sum = -(dlt + (short)(dlt + 32768));
                } 
                else 
                {
                    sum = dlt + (short)(dlt + 32768);
                }
                
                dlt = dstP[1] - angP[1]; 
                
                if (dlt < 0)
                {
                    sum -= dlt;
                } 
                else 
                {
                    sum += dlt;
                }
                
                dlt = dstP[1] - (32768 - angP[1]);
                
                if (dlt < 0) 
                {
                    sum += dlt;
                } 
                else 
                {
                    sum -= dlt;
                }
                
                dlt = dstP[2] - angP[2]; 
                
                if (dlt < 0)
                {
                    sum -= dlt + (short)(dlt + 32768);
                } 
                else 
                {
                    sum += dlt + (short)(dlt + 32768);
                }
                
                if (sum > 0) 
                { 
                    int* srcP; // not from DWARF

                    srcP = angP;
                    
                    *srcP = 32768 + *srcP++;
                    *srcP = 32768 - *srcP;
                    *srcP = 32768 + *++srcP;
                }
                
                angP[0] += (int)(rate * (short)(mka_ang[0] - angP[0]));
                angP[1] += (int)(rate * (short)(mka_ang[1] - angP[1])); 
                angP[2] += (int)(rate * (short)(mka_ang[2] - angP[2]));
            }
            
            md2P++;
            obj_no--;
        }
    }
    
    ewP->hokan_count--;
}

// 100% matching!
void bhFixPosition(BH_PWORK* ewP, char* datP)
{
    NJS_POINT3 pos; 

    bhCalcFixOffset(ewP, datP, NULL, &pos);
    
    ewP->px -= pos.x;
    ewP->pz -= pos.z;
}

// 100% matching! 
void bhCalcFixOffset(BH_PWORK* ewP, char* datP, NJS_POINT3* offP, NJS_POINT3* rtnP)
{
    ML_WORK* mlwP;           
    NJS_CNK_OBJECT* objP;      
    NJS_POINT3 src;      
    NJS_POINT3 dst;          
    static const NJS_POINT3 off = { 0 }; 
    
    mlwP = ewP->mlwP;
    
    if (offP == NULL) 
    {
        offP = &off;
    }
    
    njPushMatrixEx();
    
    if ((ewP->flg & 0x80))
    {
        njSetMatrix(NULL, &((BH_PWORK*)ewP->lkwkp)->mlwP->owP[ewP->lkono].mtx);
        
        njTranslate(NULL, ewP->lox, ewP->loy, ewP->loz);
        njRotateXYZ(NULL, ewP->ax, ewP->ay, ewP->az);
    }
    else
    {
        njUnitMatrix(NULL);
        
        njTranslate(NULL, ewP->px, ewP->py, ewP->pz);
        njRotateXYZ(NULL, ewP->ax, ewP->ay, ewP->az);
    }
    
    while (*datP != -1)
    {
        objP = &mlwP->objP[*datP++];
        
        njTranslate(NULL, objP->pos[0], objP->pos[1], objP->pos[2]);
        njRotateXYZ(NULL, objP->ang[0], objP->ang[1], objP->ang[2]);
    }
    
    njCalcPoint(NULL, offP, &dst);
    njCalcPoint(&mlwP->owP[datP[-1]].mtx, offP, &src);
    
    njSubVector(&dst, &src);
    
    *rtnP = dst;
    
    njPopMatrixEx();
}

// 100% matching!
void bhGetObjMotion(BH_PWORK* ewP, int obj_no, float* pos, int* ang)
{
    float f_flp;        
    int s_flp;         
    char* rutP;        
    NJS_MDATA2_MOD* md2P;
    NJS_MKEY_F_MOD* mkfP;
    NJS_MKEY_A_MOD* mkaP;
    
    if ((ewP->mtn_md & 0x2)) 
    {
        f_flp = -1.0f;
        s_flp = -1;
        
        rutP = (char*)&ewP->mtn_tp[obj_no];
    }
    else 
    {
        f_flp = 1.0f;
        s_flp = 1;
        
        rutP = (char*)&NormalTbl[obj_no];
    }

    md2P = &ewP->mnwP[ewP->mtn_no].md2P[*rutP];
    
    mkfP = (NJS_MKEY_F_MOD*)md2P->p[0];
    mkaP = (NJS_MKEY_A_MOD*)md2P->p[1]; 
    
    if (mkaP != NULL) 
    {
        mkaP += ewP->frm_no / 65536; 
        mkfP += ewP->frm_no / 65536;
        
        pos[0] = mkfP->key[0] * f_flp;
        pos[1] = mkfP->key[1];
        pos[2] = mkfP->key[2];
        
        ang[0] = mkaP->key[0];
        ang[1] = mkaP->key[1] * s_flp;
        ang[2] = mkaP->key[2] * s_flp;
    }
    else 
    {
        pos[0] = pos[1] = pos[2] = 0;
        ang[0] = ang[1] = ang[2] = 0;
    }
}

// 100% matching!
void AngZyxToYzx(int* zyx, int* yzx)
{ 
	float fSin0;
	float fSin1;
	float fSin2;
	float fCos0;
	float fCos1;
	float fCos2;
    float b;
    
    njSinCos(zyx[0], &fSin0, &fCos0); 
    njSinCos(zyx[1], &fSin1, &fCos1); 
    njSinCos(zyx[2], &fSin2, &fCos2); 

    b = fSin2 * fSin1; 
    
    yzx[0] = 10430.381f * atan2f((fCos2 * fSin0) - (b * fCos0), (fCos2 * fCos0) + (b * fSin0)); 
    yzx[1] = 10430.381f * atan2f(fSin1, fCos2 * fCos1); 
    yzx[2] = 10430.381f * asinf(fSin2 * fCos1); 
} 

// 100% matching!
void AngYzxToZyx(int* yzx, int* zyx)
{ 
	float fSin0;
	float fSin1;
	float fSin2;
	float fCos0;
	float fCos1;
	float fCos2;
    float b;
    
    njSinCos(yzx[0], &fSin0, &fCos0); 
    njSinCos(yzx[1], &fSin1, &fCos1); 
    njSinCos(yzx[2], &fSin2, &fCos2); 

    b = fSin1 * fSin2;
    
    zyx[0] = 10430.381f * atan2f((fCos1 * fSin0) + (b * fCos0), (fCos1 * fCos0) - (b * fSin0));
    zyx[1] = 10430.381f * asinf(fSin1 * fCos2);
    zyx[2] = 10430.381f * atan2f(fSin2, fCos1 * fCos2);
}
