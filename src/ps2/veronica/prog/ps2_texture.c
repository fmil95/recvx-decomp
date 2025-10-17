#include "ps2_texture.h"

/*char fname[128];*/
NJS_TEXINFO info;
NJS_TEXLIST tlist = { NULL, 1 }; 
SYS_WORK* sys;
/*char BIO_CURRENT[0];*/
unsigned int palbuf[4096];
/*_anon23 tbuf[0];
_anon6* rom;
BH_PWORK ene[0];*/
NO_NAME_17 Ps2_tex_save[2];
/*_anon23* Ps2_tex_info;

void ClutCopy(void* data, void* org_data);
void ClutCopy256(void* data, void* org_data);
int isVQ(unsigned char type);
int bhSetMemPvpTexture(_anon3* tlp, unsigned char* datp, int offset);
void bhReleaseMainTexture();
void Init_PS2_SAVE_TEX();
char* bhCopyTexmem2Mainmem(_anon3* tlp, char* adr);
char* bhCopyTexmem2MainmemSub(_anon3* tlp, char* adr);
void bhCopyMainmem2Texmem(_anon3* tlp);
void bhPushAllTexture();
void bhPopAllTexture();
void bhGarbageTexture(_anon23* addr, unsigned int n);*/

// 100% matching!
void ClutCopy(void* data, void* org_data)
{
    unsigned int i;
    
    for (i = 0; i < 8; i++) 
    {
        ((int*)data)[i] = ((int*)org_data)[i];
    }
    
    for (i = 8; i < 16; i++) 
    {
        ((int*)data)[i] = ((int*)org_data)[i + 8];
    } 
}

// 100% matching!
void ClutCopy256(void* data, void* org_data) 
{
    unsigned int i;   
    unsigned int *op;  
    unsigned int *dp;  
    unsigned int loop; 

    dp = data;
    op = org_data;
    
    for (loop = 0; loop < 8; loop++) 
    {
        for (i = 0; i < 8; i++)
        {
            dp[i] = op[i];
        }
        
        for (i = 8; i < 16; i++)
        {
            dp[i] = op[i + 8];
        }
        
        for (i = 16; i < 24; i++)
        {
            dp[i] = op[i - 8];
        } 
        
        for (i = 24; i < 32; i++)
        {
            dp[i] = op[i];
        }
        
        dp += 32;
        op += 32;
    }
}

// 100% matching!
int isVQ(unsigned char type)
{
    if ((type >= 5) && (type < 9))
    { 
        return 0;
    }
    
    return 1; 
} 

// 99.70% matching
int bhSetMemPvpTexture(NJS_TEXLIST* tlp, unsigned char* datp, int offset)
{
    unsigned int pal[64]; 
    unsigned int palnum;  
    unsigned int VQflag;  
    unsigned int TEXflag; 
    unsigned int* clutp; 
    NJS_TEXNAME* tnp;    
    int sz;              
    int end;              
    int nbTex;            
    int palno;            
    int lop;             
    unsigned int code;    
    unsigned int gidx;    
    unsigned int attr;   
    unsigned short w;     
    unsigned short h;     
    unsigned short bk_id;
    unsigned short et_of; 
    unsigned short et_ct; 
    unsigned char* ap;   
    unsigned char* dp;    
    unsigned char* palp;  
    int* temp; // not from the debugging symbols

    palnum = 0; 
    
    nbTex = 0; 
    
    end = 1; 
    
    dp = datp; 
    
    tnp = &tlp->textures[offset]; 
    
    while (end != 0) 
    {
        code = ((int*)dp)[0]; 
        
        sz = ((int*)dp)[1];
        
        dp += 32; 
        
        ap = dp;
        
        dp += sz; 
        
        switch (code)
        {                        
        case -1:
            end = 0;
            break; 
        case MAKE_MAGIC('P', 'L', 'I', 0):
            if (sz != 0) 
            { 
                palnum = *((int*)ap)++; 
                
                for (lop = 0; lop < palnum; lop++, ap += 8) 
                { 
                    pal[lop] = ((int*)ap)[1]; 
                } 

                for (lop = 0; lop < palnum; lop++);
            }
            
            break; 
        case MAKE_MAGIC('T', 'I', 'M', '2'):
            Ps2CheckTextureAlpha(ap); 

            VQflag = isVQ(((TIM2_PICTUREHEADER*)ap)->PictFormat); 
            
            if (VQflag != 0) 
            {               
                gidx = ((TIM2_PICTUREHEADER*)ap)->Gindex;
                
                switch (((TIM2_PICTUREHEADER*)ap)->ImageType) 
                {              
                case 4:                             
                    attr = 0x500;
                    
                    et_ct = 16;
                    break;
                case 5:                            
                    attr = 0x700; 
                    
                    et_ct = 256; 
                    break; 
                default:                           
                    exit(0); 
                    break;
                }

                w = ((TIM2_PICTUREHEADER*)ap)->ImageWidth; 
                h = ((TIM2_PICTUREHEADER*)ap)->ImageHeight; 
                
                njSetTextureInfo(&info, (unsigned short*)ap, attr, w, h); 
                njSetTextureName(tnp, &info.texaddr, gidx, 0x40800000); 
                
                tlist.textures = tnp;
                
                tlist.nbTexture = 1; 
                
                njLoadTexture(&tlist);
                
                tnp++; 
                
                nbTex++; 
            }
            else 
            { 
                gidx = ((TIM2_PICTUREHEADER*)ap)->Gindex;
                
                switch (((TIM2_PICTUREHEADER*)ap)->ImageType) 
                {               
                case 4:                            
                    attr = 0x500; 
                    
                    et_ct = 16; 
                    break; 
                case 5:                             
                    attr = 0x700; 
                    
                    et_ct = 256; 
                    break; 
                default:                           
                    exit(0); 
                    break;
                    
                    (void)&palnum; // ???
                }
                
                w = ((TIM2_PICTUREHEADER*)ap)->ImageWidth; 
                h = ((TIM2_PICTUREHEADER*)ap)->ImageHeight; 
                
                ((TIM2_PICTUREHEADER*)ap)->PalNum = palnum; 
                
                clutp = (unsigned int*)((ap + ((TIM2_PICTUREHEADER*)ap)->ImageSize) + 256); 
                
                temp = (int*)((TIM2_PICTUREHEADER*)ap)->PalData;
                
                for (lop = 0; lop < palnum; lop++) 
                {
                    temp[lop] = ((int*)&pal[lop])[0];  
                    
                    TEXflag = ((unsigned char*)&pal[lop])[0]; 
                    
                    bk_id = ((unsigned char*)&pal[lop])[1]; 
                    
                    et_of = ((unsigned short*)&pal[lop])[1]; 
                    
                    if (bk_id == 255) 
                    { 
                        bk_id = sys->ef_pbnk; 
                        
                        sys->ef_pbnk += et_ct / 16;
                        
                        if (sys->ef_pbnk >= 64) 
                        {
                            sys->ef_pbnk -= 32; 
                        }
                    } 
                    
                    gidx &= 0x3FFFFFF; 
                    
                    gidx |= bk_id << 26; 

                    palno = et_of + ((bk_id & 0x3F) * 16);
                    
                    sz = (int)&palbuf[((bk_id / 64) * 64) * 16]; 
                    
                    palno *= 4; 
                    
                    palp = (unsigned char*)(palno + sz); 

                    if (et_ct == 256)
                    {
                        ClutCopy256(palp, clutp); 
                        
                        clutp += et_ct; 
                    } 
                    else 
                    { 
                        ClutCopy(palp, clutp); 
                        
                        clutp += et_ct * 2; 
                    }
                    
                    sys->gm_flg |= 0x4; 
                    
                    if (TEXflag == 0)
                    { 
                        if (lop == 0) 
                        { 
                            njSetTextureInfo(&info, (unsigned short*)ap, attr, w, h); 
                            njSetTextureName(tnp, &info.texaddr, (0, gidx) /* ??? */, 0x41000000); 
                        }
                        else 
                        { 
                            njSetTextureInfo(&info, (unsigned short*)ap, attr, w, h); 
                            njSetTextureName(tnp, &info.texaddr, gidx, 0x41010000);
                        }

                        tlist.textures = tnp; 
                        
                        tlist.nbTexture = 1; 
                        
                        njLoadTexture(&tlist); 

                        nbTex++; 
                        
                        tnp++;
                    }
                } 
            }
            
            break; 
        default:
            end = 0; 
        }
    } 
    
    return nbTex; 
} 

// 
// Start address: 0x2e6580
void bhReleaseMainTexture()
{
	int j;
	int i;
	//_anon0* op;
	BH_PWORK* pp;
	// Line 392, Address: 0x2e6580, Func Offset: 0
	// Line 397, Address: 0x2e659c, Func Offset: 0x1c
	// Line 399, Address: 0x2e65b8, Func Offset: 0x38
	// Line 400, Address: 0x2e65c4, Func Offset: 0x44
	// Line 401, Address: 0x2e65f0, Func Offset: 0x70
	// Line 402, Address: 0x2e6600, Func Offset: 0x80
	// Line 403, Address: 0x2e660c, Func Offset: 0x8c
	// Line 404, Address: 0x2e6628, Func Offset: 0xa8
	// Line 405, Address: 0x2e6634, Func Offset: 0xb4
	// Line 407, Address: 0x2e664c, Func Offset: 0xcc
	// Line 409, Address: 0x2e6668, Func Offset: 0xe8
	// Line 410, Address: 0x2e6670, Func Offset: 0xf0
	// Line 409, Address: 0x2e6674, Func Offset: 0xf4
	// Line 410, Address: 0x2e6680, Func Offset: 0x100
	// Line 411, Address: 0x2e6688, Func Offset: 0x108
	// Line 412, Address: 0x2e6698, Func Offset: 0x118
	// Line 413, Address: 0x2e66b4, Func Offset: 0x134
	// Line 414, Address: 0x2e66bc, Func Offset: 0x13c
	// Line 415, Address: 0x2e66c0, Func Offset: 0x140
	// Line 417, Address: 0x2e66e0, Func Offset: 0x160
	// Line 418, Address: 0x2e66f4, Func Offset: 0x174
	// Line 419, Address: 0x2e66fc, Func Offset: 0x17c
	// Line 420, Address: 0x2e670c, Func Offset: 0x18c
	// Line 421, Address: 0x2e6728, Func Offset: 0x1a8
	// Line 423, Address: 0x2e6730, Func Offset: 0x1b0
	// Line 425, Address: 0x2e6750, Func Offset: 0x1d0
	// Line 426, Address: 0x2e676c, Func Offset: 0x1ec
	// Line 427, Address: 0x2e67a0, Func Offset: 0x220
	// Line 428, Address: 0x2e67c0, Func Offset: 0x240
	// Line 429, Address: 0x2e67d8, Func Offset: 0x258
	// Line 430, Address: 0x2e67f8, Func Offset: 0x278
	// Line 432, Address: 0x2e6818, Func Offset: 0x298
	// Line 433, Address: 0x2e6834, Func Offset: 0x2b4
	// Line 434, Address: 0x2e6844, Func Offset: 0x2c4
	// Line 437, Address: 0x2e6858, Func Offset: 0x2d8
	// Line 438, Address: 0x2e6868, Func Offset: 0x2e8
	// Func End, Address: 0x2e6888, Func Offset: 0x308
	scePrintf("bhReleaseMainTexture - UNIMPLEMENTED!\n");
}

// 100% matching!
void Init_PS2_SAVE_TEX()
{
    unsigned int i;

    for (i = 0; i < 2; i++)
    {
        Ps2_tex_save[i].num = 0;
    } 
}

/*// 
// Start address: 0x2e68c0
char* bhCopyTexmem2Mainmem(_anon3* tlp, char* adr)
{
	// Line 464, Address: 0x2e68c0, Func Offset: 0
	// Line 465, Address: 0x2e68d0, Func Offset: 0x10
	// Line 466, Address: 0x2e68dc, Func Offset: 0x1c
	// Line 467, Address: 0x2e68e4, Func Offset: 0x24
	// Line 468, Address: 0x2e68e8, Func Offset: 0x28
	// Func End, Address: 0x2e68fc, Func Offset: 0x3c
}*/

// 
// Start address: 0x2e6900
char* bhCopyTexmem2MainmemSub(NJS_TEXLIST* tlp, char* adr)
{
	//_anon23* tmp;
	unsigned int num;
	unsigned int i;
	// Line 474, Address: 0x2e6900, Func Offset: 0
	// Line 483, Address: 0x2e6924, Func Offset: 0x24
	// Line 489, Address: 0x2e6930, Func Offset: 0x30
	// Line 490, Address: 0x2e6948, Func Offset: 0x48
	// Line 492, Address: 0x2e6954, Func Offset: 0x54
	// Line 493, Address: 0x2e6958, Func Offset: 0x58
	// Line 492, Address: 0x2e6960, Func Offset: 0x60
	// Line 493, Address: 0x2e6968, Func Offset: 0x68
	// Line 499, Address: 0x2e698c, Func Offset: 0x8c
	// Line 500, Address: 0x2e6994, Func Offset: 0x94
	// Line 503, Address: 0x2e69a4, Func Offset: 0xa4
	// Line 502, Address: 0x2e69a8, Func Offset: 0xa8
	// Line 503, Address: 0x2e69b8, Func Offset: 0xb8
	// Line 502, Address: 0x2e69bc, Func Offset: 0xbc
	// Line 503, Address: 0x2e69c8, Func Offset: 0xc8
	// Line 504, Address: 0x2e69e0, Func Offset: 0xe0
	// Line 505, Address: 0x2e69e4, Func Offset: 0xe4
	// Func End, Address: 0x2e6a08, Func Offset: 0x108
	scePrintf("bhCopyTexmem2MainmemSub - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2e6a10
void bhCopyMainmem2Texmem(NJS_TEXLIST* tlp)
{
	//_anon23* tmp;
	int no;
	//_anon23* addr;
	unsigned int num;
	unsigned int i;
	// Line 515, Address: 0x2e6a10, Func Offset: 0
	// Line 526, Address: 0x2e6a38, Func Offset: 0x28
	// Line 527, Address: 0x2e6a40, Func Offset: 0x30
	// Line 528, Address: 0x2e6a64, Func Offset: 0x54
	// Line 537, Address: 0x2e6a6c, Func Offset: 0x5c
	// Line 538, Address: 0x2e6a84, Func Offset: 0x74
	// Line 540, Address: 0x2e6aa0, Func Offset: 0x90
	// Line 542, Address: 0x2e6ab0, Func Offset: 0xa0
	// Line 543, Address: 0x2e6ab8, Func Offset: 0xa8
	// Line 544, Address: 0x2e6ac0, Func Offset: 0xb0
	// Line 545, Address: 0x2e6ad0, Func Offset: 0xc0
	// Line 546, Address: 0x2e6ae8, Func Offset: 0xd8
	// Line 547, Address: 0x2e6af0, Func Offset: 0xe0
	// Line 549, Address: 0x2e6af8, Func Offset: 0xe8
	// Line 550, Address: 0x2e6b2c, Func Offset: 0x11c
	// Line 551, Address: 0x2e6b34, Func Offset: 0x124
	// Line 553, Address: 0x2e6b38, Func Offset: 0x128
	// Line 554, Address: 0x2e6b48, Func Offset: 0x138
	// Line 558, Address: 0x2e6b50, Func Offset: 0x140
	// Line 554, Address: 0x2e6b54, Func Offset: 0x144
	// Line 558, Address: 0x2e6b60, Func Offset: 0x150
	// Line 559, Address: 0x2e6b78, Func Offset: 0x168
	// Line 560, Address: 0x2e6b80, Func Offset: 0x170
	// Func End, Address: 0x2e6bac, Func Offset: 0x19c
	scePrintf("bhCopyMainmem2Texmem - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhPushAllTexture()
{

}

// 100% matching!
void bhPopAllTexture() 
{

}

// 100% matching!
void bhGarbageTexture(NJS_TEXMEMLIST* addr, unsigned int n) 
{
    njGarbageTexture(addr, n);
}
