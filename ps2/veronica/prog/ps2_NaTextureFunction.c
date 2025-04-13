/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;

typedef char*(*type_3)(char*, int);

typedef unsigned int type_0[1024];
typedef unsigned int type_1[4096];
typedef char type_2[4];
typedef unsigned int type_4[27];

struct _anon0
{
	void* texaddr;
	_anon10 texsurface;
};

struct _anon1
{
	unsigned int globalIndex;
	unsigned int bank;
	unsigned int tspparambuffer;
	unsigned int texparambuffer;
	unsigned int texaddr;
	_anon0 texinfo;
	unsigned short count;
	unsigned short dummy;
};

struct _anon2
{
	_anon3* textures;
	unsigned int nbTexture;
};

struct _anon3
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon4
{
	char FileId[4];
	unsigned char FormatVersion;
	unsigned char FormatId;
	unsigned short Pictures;
	unsigned int Gindex;
	unsigned char OrgColorType;
	unsigned char OrgTexType;
	unsigned short ClutChange;
	unsigned int PalNum;
	unsigned int PalData[27];
	unsigned int TotalSize;
	unsigned int ClutSize;
	unsigned int ImageSize;
	unsigned short HeaderSize;
	unsigned short ClutColors;
	unsigned char PictFormat;
	unsigned char MipMapTextures;
	unsigned char ClutType;
	unsigned char ImageType;
	unsigned short ImageWidth;
	unsigned short ImageHeight;
	_anon6 GsTex0;
	_anon9 GsTex1;
	unsigned int GsRegs;
	unsigned int GsTexClut;
	_anon8 admin;
	unsigned int TpFlag;
	unsigned int ClampFlag;
};

struct _anon5
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon6
{
	struct
	{
		unsigned long TBP0 : 14;
		unsigned long TBW : 6;
		unsigned long PSM : 6;
		unsigned long TW : 4;
		unsigned long TH : 4;
		unsigned long TCC : 1;
		unsigned long TFX : 2;
		unsigned long CBP : 14;
		unsigned long CPSM : 4;
		unsigned long CSM : 1;
		unsigned long CSA : 5;
		unsigned long CLD : 3;
	};
};

struct _anon7
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon8
{
	unsigned int gindex;
	unsigned int size;
	unsigned int count;
	void* addr;
	void* before;
	void* after;
};

struct _anon9
{
	struct
	{
		unsigned long LCM : 1;
		unsigned long pad01 : 1;
		unsigned long MXL : 3;
		unsigned long MMAG : 1;
		unsigned long MMIN : 3;
		unsigned long MTBA : 1;
		unsigned long pad10 : 9;
		unsigned long L : 2;
		unsigned long pad21 : 11;
		unsigned long K : 12;
		unsigned long pad44 : 20;
	};
};

struct _anon10
{
	unsigned int Type;
	unsigned int BitDepth;
	unsigned int PixelFormat;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int TextureSize;
	unsigned int fSurfaceFlags;
	unsigned int* pSurface;
	unsigned int* pVirtual;
	unsigned int* pPhysical;
};*/

unsigned int Ps2_current_texbreak;
unsigned int Ps2_current_gindex;
unsigned int Ps2_texcontinue_no;
void* Ps2_free_last;
unsigned int Ps2_free_texmemsize;
void* Ps2_now_free;
NJS_TEXMEMLIST Ps2_last_tmlist;
NJS_TEXMEMLIST Ps2_1st_tmlist;
unsigned int Ps2_texmemlist_num;
NJS_TEXMEMLIST* Ps2_tex_info;
TIM2_PICTUREHEADER Ps2_tm_list_last;
TIM2_PICTUREHEADER Ps2_tm_list_1st;
void* Ps2_tex_buff;
unsigned int Ps2_current_texno;
NJS_TEXLIST* Ps2_current_texlist;
NJS_TEXMEMLIST* Ps2_current_texmemlist;
/*char*(*index)(char*, int);
unsigned int Ps2_render_width;
unsigned int palbuf[4096];
unsigned int Ps2_clut[1024];*/
void* Ps2_render_p;
/*int Ps2_tex3DEx_count;
_anon7* Ps2_tex3DEx_p;
int Ps2_tex3DEx_trans;
int Ps2_3DEx_count;
_anon5* Ps2_3DEx_p;
int Ps2_3DEx_trans;
unsigned int Ps2_quad_color;
int Ps2_quad_trans;
unsigned int Ps2_current_texno_bk;
_anon2* Ps2_current_texlist_bk;

void Ps2MemCopy4(void* vpDst, void* vpSrc, int lNum);
void njInitTextureBuffer();
void njInitTexture(_anon1* addr, unsigned int n);
void njExitTexture();
int SearchNumber(unsigned int global_index, unsigned int bank);
int SearchNullNumber();
int njLoadTexture(_anon2* texlist);
int njSetTexture(_anon2* texlist);
int njSetTextureNum(unsigned int n);
int njSetTextureNumG(unsigned int globalIndex);
int njSetTextureNumSys(unsigned int n);
void njReleaseTextureAll();
int njReleaseTexture(_anon2* texlist);
unsigned int njCalcTexture();
void njSetTextureInfo(_anon0* info, unsigned short* tex, int Type, int nWidth, int nHeight);
void njSetTextureName(_anon3* texname, void* addr, unsigned int globalIndex, unsigned int attr);
void njRenderTextureNum();
void njRenderTextureNumG(unsigned int globalIndex);
void njSetRenderWidth(unsigned int nWidth);
void njSetPaletteBankNum(unsigned int n, int bank);
void njSetPaletteMode();
unsigned int njGetPaletteMode();
void njSetPaletteData();
void njGarbageTexture();
unsigned int Ps2GetTim2Size(void* p);
int Ps2TextureMalloc(_anon1* p);
int Ps2TextureFree(_anon1* p);
int Ps2ReplaceTexAddr(unsigned int gindex, void* rep_addr);
int Ps2TextureGarbageCollectionAll();
int ring_check();*/

// 100% matching!
void Ps2MemCopy4(void* vpDst, void* vpSrc, int lNum)
{
    unsigned int* lpSrc;
    unsigned int* lpDst;
	
    lpDst = vpDst;
    lpSrc = vpSrc;
    
    while (lNum-- != 0)
    {
        *lpDst = *lpSrc;
        
        lpSrc++;
        lpDst++;
    } 
}

// 100% matching!
void	njInitTextureBuffer(Sint8 *addr,Uint32 size)
{

}

// 100% matching!
void	njInitTexture(NJS_TEXMEMLIST *addr,Uint32 n) 
{	
    int i;
    
    Init_PS2_SAVE_TEX();

    Ps2_tm_list_1st.admin.gindex = -1; 
    
    Ps2_tm_list_1st.admin.size = 0;                  
    
    Ps2_tm_list_1st.admin.addr = Ps2_tex_buff;      
    
    Ps2_tm_list_1st.admin.before = (void*)-1;
    Ps2_tm_list_1st.admin.after = &Ps2_tm_list_last;   
    
    Ps2_tm_list_last.admin.gindex = -1;                
    
    Ps2_tm_list_last.admin.size = 0;               
    
    Ps2_tm_list_last.admin.addr = (void*)-1;           
    
    Ps2_tm_list_last.admin.before = &Ps2_tm_list_1st;  
    Ps2_tm_list_last.admin.after = (void*)-1;
    
    Ps2_tex_info = addr;  
    
    Ps2_texmemlist_num = n;                  
    
    Ps2_1st_tmlist.texinfo.texsurface.TextureSize = 0;                  
    
    Ps2_1st_tmlist.texinfo.texsurface.pSurface = Ps2_tex_buff;       
    Ps2_1st_tmlist.texinfo.texsurface.pVirtual = (unsigned int*)-1;    
    Ps2_1st_tmlist.texinfo.texsurface.pPhysical = (unsigned int*)&Ps2_last_tmlist;      
    
    Ps2_last_tmlist.texinfo.texsurface.pSurface = (unsigned int*)-1;             
    Ps2_last_tmlist.texinfo.texsurface.pVirtual = (unsigned int*)&Ps2_1st_tmlist;      
    Ps2_last_tmlist.texinfo.texsurface.pPhysical = (unsigned int*)-1;  
    
    Ps2_now_free = Ps2_tex_buff;               
    
    Ps2_free_texmemsize = 10485760;             
    
    Ps2_free_last = (unsigned char*)Ps2_tex_buff + Ps2_free_texmemsize;    
    
    Ps2_texcontinue_no = 0;                      
    
    Ps2_current_gindex = 0;                      
    
    Ps2_current_texbreak = 1;                    
    
    for (i = 0; i < n; i++) 
    {	
        addr[i].globalIndex = -1;
        
        addr[i].bank = -1;
        
        addr[i].tspparambuffer = 0;
        addr[i].texparambuffer = 0;
        
        addr[i].texaddr = 0;
        
        addr[i].texinfo.texaddr = NULL;
        
        addr[i].texinfo.texsurface.Type = 0;
        
        addr[i].texinfo.texsurface.BitDepth = 0;
        
        addr[i].texinfo.texsurface.PixelFormat = 0;
        
        addr[i].texinfo.texsurface.nWidth = 0;
        addr[i].texinfo.texsurface.nHeight = 0;
        
        addr[i].texinfo.texsurface.TextureSize = 0;
        
        addr[i].texinfo.texsurface.fSurfaceFlags = 0;
        
        addr[i].texinfo.texsurface.pSurface = NULL;
        addr[i].texinfo.texsurface.pVirtual = NULL;
        addr[i].texinfo.texsurface.pPhysical = NULL;
        
        addr[i].count = 0;
        
        addr[i].dummy = 0;
    }
}

// 100% matching!
void	njExitTexture(void)
{

}

// 100% matching!
int SearchNumber(unsigned int global_index, unsigned int bank)
{
    unsigned int i;
    unsigned int n;
    NJS_TEXMEMLIST* addr;

    n = i = -1;
    
    if (global_index == n) 
    {
        return -1;   
    }

    addr = Ps2_tex_info;
    
    n = Ps2_texmemlist_num;
    
    for (i = 0; i < n; ++i) 
    {
        if ((global_index == addr[i].globalIndex) && ((bank == addr[i].bank) || (bank == -1)))
        {
            return i;
        }
    }
    
    return -1;
}

// 100% matching!
int SearchNullNumber() 
{
    unsigned int i;
    unsigned int n;
    NJS_TEXMEMLIST* addr;
    
    addr = Ps2_tex_info;

    n = n = Ps2_texmemlist_num;
    
    for (i = 0; i < n; ++i) 
    {
        if (addr[i].count == 0) 
        {
            return i;
        }
    }
    
    return -1;
}

// 100% matching!
Sint32	njLoadTexture(NJS_TEXLIST *texlist)
{
    int j;
    int no; 
    int cont_no;
    unsigned int tex_num;
    unsigned int g_index;
    unsigned int bank; 
    unsigned int attr;
    NJS_TEXMEMLIST* addr; 
    
    no = Ps2_texcontinue_no;
    
    tex_num = texlist->nbTexture;
    
    addr = Ps2_tex_info;
    
    ring_check();
    
    g_index = -1;
    
    for (j = 0; j < tex_num; j++) 
    {
        attr = texlist->textures[j].attr;
        
        cont_no = -1;
        
        if ((attr & 0x40000000))
        {
            if ((attr & 0x800000))
            {
                g_index = texlist->textures[j].texaddr;
            } 
            else if ((attr & 0x1000000)) 
            {
                if ((attr & 0x10000)) 
                {
                    bank = texlist->textures[j].texaddr >> 26;
                    
                    if ((cont_no = SearchNullNumber()) >= 0)
                    {
                        texlist->textures[j].texaddr = (unsigned int)&addr[cont_no];
                    }
                    else 
                    {
                        exit(0);
                    }

                    addr[cont_no] = *(NJS_TEXMEMLIST*)texlist->textures[j - 1].texaddr;
                    
                    addr[cont_no].count = 1;
                    
                    addr[cont_no].bank = bank;
                    
                    ((TIM2_PICTUREHEADER*)addr[no].texinfo.texsurface.pSurface)->admin.count++;
                    
                    continue;
                }
                else
                {
                    g_index = texlist->textures[j].texaddr;
                    
                    cont_no = texlist->textures[j].texaddr >> 26;
                    
                    g_index &= 0x3FFFFFF;
                }
            }

            if ((no = SearchNumber(g_index, cont_no)) >= 0) 
            {
                addr[no].count++;
                
                ((TIM2_PICTUREHEADER*)addr[no].texinfo.texsurface.pSurface)->admin.count++;
                
                texlist->textures[j].texaddr = (unsigned int)&addr[no];
            } 
            else 
            {
                if ((no = SearchNullNumber()) >= 0) 
                {
                    texlist->textures[j].texaddr = (unsigned int)&addr[no];
                } 
                else
                {
                    exit(0);
                }

                addr[no].count = 1;
                
                addr[no].globalIndex = g_index;
                
                addr[no].bank = cont_no;
                
                addr[no].tspparambuffer = 0;
                addr[no].texparambuffer = 0;
                
                addr[no].texaddr = 2;
                
                addr[no].texinfo.texaddr = ((NJS_TEXINFO*)texlist->textures[j].filename)->texaddr;
               
                addr[no].texinfo.texsurface.Type = ((NJS_TEXINFO*)texlist->textures[j].filename)->texsurface.Type;
               
                addr[no].texinfo.texsurface.BitDepth = 0;
              
                addr[no].texinfo.texsurface.PixelFormat = 0;
               
                addr[no].texinfo.texsurface.nWidth = ((NJS_TEXINFO*)texlist->textures[j].filename)->texsurface.nWidth;
                addr[no].texinfo.texsurface.nHeight = ((NJS_TEXINFO*)texlist->textures[j].filename)->texsurface.nHeight;
             
                addr[no].texinfo.texsurface.TextureSize = 0;
                
                addr[no].texinfo.texsurface.fSurfaceFlags = 0;
                
                addr[no].texinfo.texsurface.pSurface = NULL;
                addr[no].texinfo.texsurface.pVirtual = NULL;
                addr[no].texinfo.texsurface.pPhysical = NULL;
                
                if (Ps2TextureMalloc(&addr[no]) < 0) 
                {
                    exit(0);
                }
            }
        } 
        else 
        {
            exit(0);
        }
    }
    
    ring_check();
    
    return 1;
}

// 100% matching! 
Sint32	njSetTexture(NJS_TEXLIST *texlist)
{
    if (texlist != NULL) 
    {
        Ps2_current_texlist = texlist;
        
        Ps2_current_texno = 0;
    }
}

// 100% matching! 
Sint32	njSetTextureNum(Uint32 n)
{
    if (Ps2_current_texlist->nbTexture <= n) 
    {
        n = 0;
    }
    
    Ps2_current_texno = n;
    
    Ps2_current_texmemlist = (NJS_TEXMEMLIST*)Ps2_current_texlist->textures[n].texaddr;
    
    Ps2_current_gindex = ((TIM2_PICTUREHEADER*)(Ps2_current_texmemlist->texinfo.texsurface.pSurface))->Gindex; 
    
    Ps2TexLoad(Ps2_current_texmemlist);
}

/*// 
// Start address: 0x2e21d0
int njSetTextureNumG(unsigned int globalIndex)
{
	int no;
	// Line 463, Address: 0x2e21d0, Func Offset: 0
	// Line 469, Address: 0x2e21dc, Func Offset: 0xc
	// Line 470, Address: 0x2e21e8, Func Offset: 0x18
	// Line 472, Address: 0x2e21f0, Func Offset: 0x20
	// Line 474, Address: 0x2e21f4, Func Offset: 0x24
	// Line 472, Address: 0x2e21f8, Func Offset: 0x28
	// Line 474, Address: 0x2e21fc, Func Offset: 0x2c
	// Line 478, Address: 0x2e2218, Func Offset: 0x48
	// Line 480, Address: 0x2e2224, Func Offset: 0x54
	// Line 481, Address: 0x2e222c, Func Offset: 0x5c
	// Line 483, Address: 0x2e2248, Func Offset: 0x78
	// Func End, Address: 0x2e2258, Func Offset: 0x88
}*/

// 100% matching!
int njSetTextureNumSys(unsigned int n)
{
    Ps2TexLoad((NJS_TEXMEMLIST*)Ps2_current_texlist->textures[n].texaddr);
}

// 100% matching!
void	njReleaseTextureAll(void)
{
    njInitTexture(Ps2_tex_info, Ps2_texmemlist_num);
}

// 
// Start address: 0x2e22b0
Sint32	njReleaseTexture(NJS_TEXLIST *texlist)
{
	//_anon1* p;
	unsigned int tex_num;
	int i;
	// Line 517, Address: 0x2e22b0, Func Offset: 0
	// Line 523, Address: 0x2e22cc, Func Offset: 0x1c
	// Line 553, Address: 0x2e22d8, Func Offset: 0x28
	// Line 555, Address: 0x2e22e0, Func Offset: 0x30
	// Line 556, Address: 0x2e22f0, Func Offset: 0x40
	// Line 557, Address: 0x2e22f4, Func Offset: 0x44
	// Line 556, Address: 0x2e22f8, Func Offset: 0x48
	// Line 557, Address: 0x2e2300, Func Offset: 0x50
	// Line 558, Address: 0x2e230c, Func Offset: 0x5c
	// Line 560, Address: 0x2e2318, Func Offset: 0x68
	// Line 561, Address: 0x2e2328, Func Offset: 0x78
	// Line 562, Address: 0x2e2334, Func Offset: 0x84
	// Line 564, Address: 0x2e233c, Func Offset: 0x8c
	// Line 565, Address: 0x2e2344, Func Offset: 0x94
	// Line 566, Address: 0x2e2348, Func Offset: 0x98
	// Line 567, Address: 0x2e234c, Func Offset: 0x9c
	// Line 568, Address: 0x2e2350, Func Offset: 0xa0
	// Line 569, Address: 0x2e2354, Func Offset: 0xa4
	// Line 570, Address: 0x2e2358, Func Offset: 0xa8
	// Line 571, Address: 0x2e235c, Func Offset: 0xac
	// Line 572, Address: 0x2e2360, Func Offset: 0xb0
	// Line 573, Address: 0x2e2364, Func Offset: 0xb4
	// Line 574, Address: 0x2e2368, Func Offset: 0xb8
	// Line 576, Address: 0x2e236c, Func Offset: 0xbc
	// Line 580, Address: 0x2e2370, Func Offset: 0xc0
	// Line 581, Address: 0x2e2374, Func Offset: 0xc4
	// Line 583, Address: 0x2e2378, Func Offset: 0xc8
	// Line 612, Address: 0x2e2388, Func Offset: 0xd8
	// Line 613, Address: 0x2e2390, Func Offset: 0xe0
	// Func End, Address: 0x2e23b0, Func Offset: 0x100
	scePrintf("njReleaseTexture - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2e23b0
Uint32	njCalcTexture(Uint32 flag)
{
	// Line 628, Address: 0x2e23b0, Func Offset: 0
	// Func End, Address: 0x2e23b8, Func Offset: 0x8
	scePrintf("njCalcTexture - UNIMPLEMENTED!\n");
}

// 100% matching!
void	njSetTextureInfo(NJS_TEXINFO *info,Uint16 *tex,Sint32 Type,Sint32 nWidth,Sint32 nHeight) 
{
    info->texaddr = tex;
    
    info->texsurface.Type = Type << 16;
    
    info->texsurface.nWidth = nWidth;
    info->texsurface.nHeight = nHeight;
}

// 100% matching!
void	njSetTextureName(NJS_TEXNAME *texname,void *addr,Uint32 globalIndex,Uint32 attr) 
{
    texname->filename = addr;
    
    texname->attr = attr;
    
    texname->texaddr = globalIndex;
}

/*// 
// Start address: 0x2e23f0
void njRenderTextureNum()
{
	// Line 696, Address: 0x2e23f0, Func Offset: 0
	// Func End, Address: 0x2e2420, Func Offset: 0x30
}

// 
// Start address: 0x2e2420
void njRenderTextureNumG(unsigned int globalIndex)
{
	int no;
	// Line 710, Address: 0x2e2420, Func Offset: 0
	// Line 714, Address: 0x2e2428, Func Offset: 0x8
	// Line 715, Address: 0x2e2430, Func Offset: 0x10
	// Line 716, Address: 0x2e2438, Func Offset: 0x18
	// Line 717, Address: 0x2e2458, Func Offset: 0x38
	// Line 718, Address: 0x2e2460, Func Offset: 0x40
	// Line 725, Address: 0x2e247c, Func Offset: 0x5c
	// Func End, Address: 0x2e2488, Func Offset: 0x68
}

// 
// Start address: 0x2e2490
void njSetRenderWidth(unsigned int nWidth)
{
	// Line 737, Address: 0x2e2490, Func Offset: 0
	// Line 739, Address: 0x2e2494, Func Offset: 0x4
	// Func End, Address: 0x2e249c, Func Offset: 0xc
}

// 
// Start address: 0x2e24a0
void njSetPaletteBankNum(unsigned int n, int bank)
{
	// Line 753, Address: 0x2e24a0, Func Offset: 0
	// Line 758, Address: 0x2e24c0, Func Offset: 0x20
	// Func End, Address: 0x2e24c8, Func Offset: 0x28
}*/

// 100% matching!
void 	njSetPaletteMode(Uint32 mode) 
{

}

/*// 
// Start address: 0x2e24e0
unsigned int njGetPaletteMode()
{
	// Line 782, Address: 0x2e24e0, Func Offset: 0
	// Func End, Address: 0x2e24e8, Func Offset: 0x8
}*/

// 
// Start address: 0x2e24f0
void 	njSetPaletteData(Sint32 offset,Sint32 count,void* data)
{
	// Line 793, Address: 0x2e24f0, Func Offset: 0
	// Func End, Address: 0x2e2500, Func Offset: 0x10
	scePrintf("njSetPaletteData - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2e2500
void	njGarbageTexture(NJS_TEXMEMLIST *addr,Uint32 n)
{
	// Line 825, Address: 0x2e2500, Func Offset: 0
	// Func End, Address: 0x2e2508, Func Offset: 0x8
	scePrintf("njGarbageTexture - UNIMPLEMENTED!\n");
}

// 100% matching!
unsigned int Ps2GetTim2Size(void* p) 
{
    return ((TIM2_PICTUREHEADER*)p)->TotalSize + 128;
}

// 100% matching!
int Ps2TextureMalloc(NJS_TEXMEMLIST* p)
{
	unsigned int size; 
    TIM2_PICTUREHEADER* timp; 
    TIM2_PICTUREHEADER* last2; 

    if ((p->texinfo.texsurface.Type >> 24) == 11) 
    {
        size = 1048832;
        
        if ((unsigned int)((int)Ps2_now_free + size) >= (unsigned int)Ps2_free_last)
        {
            return -1;
        }
        
        StoreRenderTex(Ps2_now_free);
        
        timp = p->texinfo.texaddr = Ps2_now_free;
        
        timp->admin.size = p->texinfo.texsurface.TextureSize = size;
        
        timp->admin.gindex = p->globalIndex;
        
        last2 = Ps2_tm_list_last.admin.before;
        
        timp->admin.before = Ps2_tm_list_last.admin.before;
        timp->admin.after = &Ps2_tm_list_last;
        
        last2->admin.after = Ps2_now_free;
        
        Ps2_tm_list_last.admin.before = Ps2_now_free;
        
        timp->admin.count = 1;
        
        timp->admin.addr = p->texinfo.texsurface.pSurface = Ps2_now_free;
        
        Ps2_render_p = Ps2_now_free;
        
        p->tspparambuffer = 16384;
        
        Ps2_free_texmemsize -= size;
        
        Ps2_now_free = (void*)((char*)Ps2_now_free + size);
        
        return 1;
    }
    
    timp = p->texinfo.texaddr;
    
    size = Ps2GetTim2Size(timp);
    
    if ((unsigned int)((int)Ps2_now_free + size) >= (unsigned int)Ps2_free_last) 
    {
        return -1;
    }
    
    timp->admin.size = p->texinfo.texsurface.TextureSize = size;
    
    timp->admin.gindex = p->globalIndex;
    
    last2 = Ps2_tm_list_last.admin.before;
    
    timp->admin.before = last2;
    timp->admin.after = &Ps2_tm_list_last;
    
    last2->admin.after = Ps2_now_free;
    
    Ps2_tm_list_last.admin.before = Ps2_now_free;
    
    timp->admin.count = 1;
    
    timp->admin.addr = p->texinfo.texsurface.pSurface = Ps2_now_free;
    
    Ps2MemCopy4(Ps2_now_free, p->texinfo.texaddr, size >> 2);
    
    p->tspparambuffer = Ps2CheckTextureAlpha(Ps2_now_free);
    
    Ps2_free_texmemsize -= size;
    
    Ps2_now_free = (void*)((int)Ps2_now_free + size);
    
    return 1;
}

/*// 
// Start address: 0x2e2740
int Ps2TextureFree(_anon1* p)
{
	_anon4* timp;
	_anon4* after;
	_anon4* before;
	unsigned int size;
	// Line 944, Address: 0x2e2740, Func Offset: 0
	// Line 948, Address: 0x2e274c, Func Offset: 0xc
	// Line 949, Address: 0x2e2758, Func Offset: 0x18
	// Line 950, Address: 0x2e2760, Func Offset: 0x20
	// Line 952, Address: 0x2e2768, Func Offset: 0x28
	// Line 951, Address: 0x2e276c, Func Offset: 0x2c
	// Line 952, Address: 0x2e2770, Func Offset: 0x30
	// Line 954, Address: 0x2e277c, Func Offset: 0x3c
	// Line 955, Address: 0x2e2780, Func Offset: 0x40
	// Line 968, Address: 0x2e2784, Func Offset: 0x44
	// Line 956, Address: 0x2e2788, Func Offset: 0x48
	// Line 957, Address: 0x2e278c, Func Offset: 0x4c
	// Line 959, Address: 0x2e2790, Func Offset: 0x50
	// Line 960, Address: 0x2e2794, Func Offset: 0x54
	// Line 961, Address: 0x2e2798, Func Offset: 0x58
	// Line 962, Address: 0x2e279c, Func Offset: 0x5c
	// Line 963, Address: 0x2e27a0, Func Offset: 0x60
	// Line 964, Address: 0x2e27a4, Func Offset: 0x64
	// Line 965, Address: 0x2e27a8, Func Offset: 0x68
	// Line 966, Address: 0x2e27ac, Func Offset: 0x6c
	// Line 968, Address: 0x2e27b0, Func Offset: 0x70
	// Line 974, Address: 0x2e27c0, Func Offset: 0x80
	// Line 976, Address: 0x2e27c8, Func Offset: 0x88
	// Line 975, Address: 0x2e27d0, Func Offset: 0x90
	// Line 976, Address: 0x2e27d4, Func Offset: 0x94
	// Func End, Address: 0x2e27dc, Func Offset: 0x9c
}

// 
// Start address: 0x2e27e0
int Ps2ReplaceTexAddr(unsigned int gindex, void* rep_addr)
{
	int count;
	_anon1* addr;
	unsigned int n;
	unsigned int i;
	// Line 987, Address: 0x2e27e0, Func Offset: 0
	// Line 988, Address: 0x2e27e8, Func Offset: 0x8
	// Line 990, Address: 0x2e27ec, Func Offset: 0xc
	// Line 991, Address: 0x2e27fc, Func Offset: 0x1c
	// Line 992, Address: 0x2e2808, Func Offset: 0x28
	// Line 994, Address: 0x2e2814, Func Offset: 0x34
	// Line 993, Address: 0x2e2818, Func Offset: 0x38
	// Line 995, Address: 0x2e281c, Func Offset: 0x3c
	// Line 996, Address: 0x2e2820, Func Offset: 0x40
	// Line 998, Address: 0x2e2830, Func Offset: 0x50
	// Func End, Address: 0x2e2838, Func Offset: 0x58
}

// 
// Start address: 0x2e2840
int Ps2TextureGarbageCollectionAll()
{
	unsigned char* real_p;
	unsigned int size;
	_anon4* after2;
	_anon4* p;
	// Line 1003, Address: 0x2e2840, Func Offset: 0
	// Line 1008, Address: 0x2e2848, Func Offset: 0x8
	// Line 1009, Address: 0x2e2850, Func Offset: 0x10
	// Line 1010, Address: 0x2e2858, Func Offset: 0x18
	// Line 1014, Address: 0x2e2860, Func Offset: 0x20
	// Line 1015, Address: 0x2e286c, Func Offset: 0x2c
	// Line 1016, Address: 0x2e2874, Func Offset: 0x34
	// Line 1017, Address: 0x2e2884, Func Offset: 0x44
	// Line 1018, Address: 0x2e2888, Func Offset: 0x48
	// Line 1019, Address: 0x2e288c, Func Offset: 0x4c
	// Line 1020, Address: 0x2e2890, Func Offset: 0x50
	// Line 1028, Address: 0x2e28a0, Func Offset: 0x60
	// Line 1030, Address: 0x2e28ac, Func Offset: 0x6c
	// Line 1031, Address: 0x2e28b0, Func Offset: 0x70
	// Line 1032, Address: 0x2e28b4, Func Offset: 0x74
	// Line 1033, Address: 0x2e28d0, Func Offset: 0x90
	// Line 1035, Address: 0x2e28d8, Func Offset: 0x98
	// Line 1041, Address: 0x2e28e0, Func Offset: 0xa0
	// Line 1036, Address: 0x2e28e4, Func Offset: 0xa4
	// Line 1038, Address: 0x2e28e8, Func Offset: 0xa8
	// Line 1042, Address: 0x2e28f8, Func Offset: 0xb8
	// Func End, Address: 0x2e2908, Func Offset: 0xc8
}*/

// 100% matching!
int ring_check()
{
    TIM2_PICTUREHEADER* after;
    TIM2_PICTUREHEADER* p;

    p = &Ps2_tm_list_1st;
  
    do 
    {
        p = p->admin.after;
        
        if (p == &Ps2_tm_list_last) 
        {
            return;
        }
    } while (*(int*)p->FileId == MAKE_MAGIC('T', 'I', 'M', '2'));

    after = p;
    
    return printf("RING ERROR %x\n", after->admin.addr);
}
