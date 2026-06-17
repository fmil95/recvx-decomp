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

// 99.52% matching
static void SetMtnNormalHokan(BH_PWORK* ewP, char* datP, int mode, float rate) 
{
    // modified order of local variables in regards to DWARF
    int* dstP;         
    int obj_no;        
    int flp_s;            
    float flp_f;         
    int* angP;          
    NJS_MDATA2_MOD* md2P; 
    O_WORK* owP;          
    NJS_MKEY_F_MOD* mkfP; 
    float* posP;          
    NJS_MKEY_A_MOD* mkaP; 
    int sum;              
    int* srcP; // not from DWARF
    short dlt;            
    
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
    
    for ( ; obj_no > 0; obj_no--, md2P++, datP++)
    {
        owP = &ewP->mlwP->owP[*datP];
        
        if (!(owP->flg & 0x4)) 
        {
            mkfP = md2P->p[0];
            
            if (mkfP != NULL) 
            {
                posP = ewP->mlwP->objP[*datP].pos;
                
                mkfP += ewP->frm_no / 65536;
                
                if ((mode & 0x100))
                {
                    posP[0] = mkfP->key[0] * flp_f;
                    posP[1] = mkfP->key[1];
                    posP[2] = mkfP->key[2];
                } 
                else 
                {
                    posP[0] += rate * ((mkfP->key[0] * flp_f) - posP[0]);
                    posP[1] += rate *  (mkfP->key[1]          - posP[1]);
                    posP[2] += rate *  (mkfP->key[2]          - posP[2]);
                }
            }
            
            if (!(owP->flg & 0x2)) 
            {
                mkaP = md2P->p[1];
                angP = ewP->mlwP->objP[*datP].ang;
                
                if (mkaP != NULL)
                {
                    mkaP = &mkaP[(int)ewP->frm_no / 65536];
                }
                else 
                {
                    mkaP = &NullMka; 
                }
                
                mka_ang[0] = mkaP->key[0];
                mka_ang[1] = mkaP->key[1] * flp_s;
                mka_ang[2] = mkaP->key[2] * flp_s;
                
                dstP = mka_ang;
                
                dlt = dstP[0] - angP[0];
                
                if (dlt < 0) 
                {
                    sum = -(dlt + (short)(dlt + 32768));
                } 
                else 
                {
                    sum =   dlt + (short)(dlt + 32768);
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
                    srcP = angP;
                    
                    *srcP = 32768 + *srcP++;
                    *srcP = 32768 - *srcP;
                    *srcP = 32768 + *++srcP;
                }
                
                angP[0] += (int)(rate * (short)(mka_ang[0] - angP[0]));
                angP[1] += (int)(rate * (short)(mka_ang[1] - angP[1]));
                angP[2] += (int)(rate * (short)(mka_ang[2] - angP[2]));
            }
        }
    }
    
    ewP->hokan_count--;
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

// 99.41% matching
static void SetMtnFastHokan(BH_PWORK* ewP, char* datP, int mode, float rate) 
{
    float flp;           
    float* keyP, *posP;          

    if (!(mode & 0x2)) 
    {
        datP = NormalTbl;
    }
    
    keyP = &((float*)ewP->mnwP[ewP->mtn_no].md2P->p[0])[(ewP->frm_no / 65536) * 3];
    posP = ewP->mlwP->objP[*datP].pos;  
    
    if ((mode & 0x2))
    {
        flp = -1.0f;
    }
    else 
    {
        flp = 1.0f;
    }
    
    if ((mode & 0x100)) 
    {
        posP[0] = keyP[0] * flp;
        posP[1] = keyP[1];
        posP[2] = keyP[2];
    } 
    else 
    {
        posP[0] += rate * ((keyP[0] * flp) - posP[0]);
        posP[1] += rate *  (keyP[1]        - posP[1]);
        posP[2] += rate *  (keyP[2]        - posP[2]);
    } 
    
    {
    int flp;             
    int obj_no;           
    NJS_MDATA2_MOD* md2P; 

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
    
    for ( ; obj_no > 0; datP++)
    { 
        O_WORK* owP;        
        
        owP = &ewP->mlwP->owP[*datP];
        
        if (!(owP->flg & 0x4)) 
        {
            if (!(owP->flg & 0x2)) 
            {
                int* angP;       
                NJS_MKEY_A_MOD* mkaP; 
                int sum;             
                int* srcP, *dstP; // srcP is not from DWARF
                short dlt;           
                static int tmpS[3], tmpD[3];  
                
                angP = ewP->mlwP->objP[*datP].ang;
                mkaP = md2P->p[1];
                
                if (mkaP != NULL) 
                {
                    mkaP = &mkaP[ewP->frm_no / 65536];
                } 
                else 
                {
                    mkaP = &NullMka;
                }
                
                mka_ang[0] = mkaP->key[0];
                mka_ang[1] = mkaP->key[1] * flp;
                mka_ang[2] = mkaP->key[2] * flp;
                
                dstP = mka_ang;
                
                dlt = dstP[0] - angP[0];
                
                if (dlt < 0)
                {
                    sum = -(dlt + (short)(dlt + 32768));
                } 
                else 
                {
                    sum =   dlt + (short)(dlt + 32768);
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
                    srcP = angP;
                    
                    *srcP = 32768 + *srcP++;
                    *srcP = 32768 - *srcP;
                    *srcP = 32768 + *++srcP;
                }
                
                if (!(owP->flg & 0x8))
                {
                    angP[0] += (int)(rate * (short)(mka_ang[0] - angP[0]));
                    angP[1] += (int)(rate * (short)(mka_ang[1] - angP[1]));
                    angP[2] += (int)(rate * (short)(mka_ang[2] - angP[2]));
                } 
                else 
                {
                    AngZyxToYzx(angP,    tmpS);
                    AngZyxToYzx(mka_ang, tmpD);
                    
                    tmpS[0] += (int)(rate * (short)(tmpD[0] - tmpS[0]));
                    tmpS[1] += (int)(rate * (short)(tmpD[1] - tmpS[1]));
                    tmpS[2] += (int)(rate * (short)(tmpD[2] - tmpS[2]));
                    
                    AngYzxToZyx(tmpS, angP);
                }
            }
            
            md2P++;
            
            obj_no--; 
        }
    }
    } 
        
    ewP->hokan_count--;
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
