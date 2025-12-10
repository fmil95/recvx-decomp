#include "ps2_NaTextureFunction.h"
#include "ps2_dummy.h"
#include "ps2_loadtim2.h"
#include "ps2_texture.h"
#include "main.h"

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
TIM2_PICTUREHEADER_EX Ps2_tm_list_last;
TIM2_PICTUREHEADER_EX Ps2_tm_list_1st;
void* Ps2_tex_buff;
char* index(char*, int);
/*unsigned int Ps2_render_width;
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
_anon2* Ps2_current_texlist_bk;*/

// 100% matching!
void Ps2MemCopy4(void* vpDst, void* vpSrc, int lNum)
{
    unsigned int* lpSrc;
    unsigned int* lpDst;
	
    lpDst = (unsigned int*)vpDst;
    lpSrc = (unsigned int*)vpSrc;
    
    while (lNum-- != 0)
    {
        *lpDst++ = *lpSrc++;
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
                    
                    ((TIM2_PICTUREHEADER_EX*)addr[no].texinfo.texsurface.pSurface)->admin.count++;
                    
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
                
                ((TIM2_PICTUREHEADER_EX*)addr[no].texinfo.texsurface.pSurface)->admin.count++;
                
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

/* ERROR: This function is currently writing garbage in the emulator because Ps2_current_texlist doesn't get properly set */
// 100% matching! 
Sint32	njSetTextureNum(Uint32 n)
{
    if (Ps2_current_texlist->nbTexture <= n) 
    {
        n = 0;
    }
    
    Ps2_current_texno = n;
    
    Ps2_current_texmemlist = (NJS_TEXMEMLIST*)Ps2_current_texlist->textures[n].texaddr;
    
    Ps2_current_gindex = ((TIM2_PICTUREHEADER_EX*)(Ps2_current_texmemlist->texinfo.texsurface.pSurface))->Gindex; 
    
    Ps2TexLoad(Ps2_current_texmemlist);
}

// 100% matching!
Sint32	njSetTextureNumG(Uint32 globalIndex)
{
    int no;

    no = SearchNumber(globalIndex, -1);
    
    if (no >= 0) 
    {
        Ps2_current_gindex = globalIndex;
        Ps2_current_texmemlist = &Ps2_tex_info[no];
        
        Ps2TexLoad(Ps2_current_texmemlist);
    }
    else 
    {
        printf("Ps2GlobalIndexTexLoad ERROR!!! %08x\n", &index);
        
        exit(0);
    }
}

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

// 100% matching! 
Sint32	njReleaseTexture(NJS_TEXLIST *texlist)
{
	int i;
    unsigned int tex_num;
    NJS_TEXMEMLIST* p;

    Ps2_current_texbreak = 1;
    
    tex_num = texlist->nbTexture;
    
    for (i = 0; i < tex_num; i++)
    {
        p = (NJS_TEXMEMLIST*)texlist->textures[i].texaddr;
        
        if (p->globalIndex != -1)
        {
            p->count--;
            
            ((TIM2_PICTUREHEADER_EX*)p->texinfo.texsurface.pSurface)->admin.count--;
            
            if (p->count == 0) 
            {
                Ps2TextureFree(p);
                
                p->globalIndex = -1;
    
                p->bank = -1;
                
                p->tspparambuffer = 0;
                p->texparambuffer = 0;
                
                p->texaddr = 0;
                
                p->texinfo.texaddr = NULL;
                
                p->texinfo.texsurface.Type = 0;
                
                p->texinfo.texsurface.BitDepth = 0;
                
                p->texinfo.texsurface.PixelFormat = 0;
                
                p->texinfo.texsurface.nWidth = 0;
                p->texinfo.texsurface.nHeight = 0;
                
                p->texinfo.texsurface.fSurfaceFlags = 0;
                
                p->count = 0;
                
                p->dummy = 0;
            }
        }
    } 
    
    ring_check();
}

// 100% matching! 
Uint32	njCalcTexture(Uint32 flag)
{
    return 1048576;
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

// 100% matching!
Uint32	njGetPaletteMode(void)
{

}

// 100% matching!
void 	njSetPaletteData(Sint32 offset,Sint32 count,void* data)
{
    Send_1024_Clut_data(palbuf, 0x3FF0);
}

// 100% matching!
void	njGarbageTexture(NJS_TEXMEMLIST *addr,Uint32 n)
{
    Ps2TextureGarbageCollectionAll();
}

// 100% matching!
unsigned int Ps2GetTim2Size(void* p) 
{
    return ((TIM2_PICTUREHEADER_EX*)p)->TotalSize + 128;
}

// 100% matching!
int Ps2TextureMalloc(NJS_TEXMEMLIST* p)
{
	unsigned int size; 
    TIM2_PICTUREHEADER_EX* timp; 
    TIM2_PICTUREHEADER_EX* last2; 

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

// 100% matching!
int Ps2TextureFree(NJS_TEXMEMLIST* p) 
{
    unsigned int size; 
    TIM2_PICTUREHEADER_EX* before; 
    TIM2_PICTUREHEADER_EX* after; 
    TIM2_PICTUREHEADER_EX* timp; 
    unsigned int* temp; // not from the debugging symbols
    unsigned int* temp2; // not from the debugging symbols

    (void)&temp; // FAKE

    Ps2_current_texbreak = 1;
    
    ring_check();
    
    temp = p->texinfo.texsurface.pSurface;
    
    timp = (TIM2_PICTUREHEADER_EX*)temp;
    
    temp2 = &timp->admin.count;
    
    size = p->texinfo.texsurface.TextureSize;
    
    if (*temp2 == 0) 
    {
        before = timp->admin.before;
        after = timp->admin.after;
        
        before->admin.after = after;
        after->admin.before = before;
        
        timp->admin.gindex = 0;
        
        timp->admin.size = 0;
        
        *temp2 = 0;
        
        timp->admin.addr = NULL;
        
        timp->admin.before = NULL;
        timp->admin.after = NULL;
        
        p->texinfo.texsurface.TextureSize = 0;
        
        p->texinfo.texsurface.pSurface = NULL;
        
        Ps2_free_texmemsize += size;
    }
    
    ring_check();
    
    return 1;
}

// 100% matching!
int Ps2ReplaceTexAddr(unsigned int gindex, void* rep_addr)
{
    unsigned int i; 
    unsigned int n;
    NJS_TEXMEMLIST* addr; 
    int count; 

    n = n = Ps2_texmemlist_num;
    
    count = 0;
    
    for (i = 0; i < n; i++)
    {
        addr = &Ps2_tex_info[i];
        
        if (addr->globalIndex == gindex) 
        {
            count++;
            
            addr->texinfo.texsurface.pSurface = rep_addr;
        }
    } 

    return count;
}

// 100% matching!
int Ps2TextureGarbageCollectionAll()
{
    TIM2_PICTUREHEADER_EX* p; 
    TIM2_PICTUREHEADER_EX* after2; 
    unsigned int size; 
    unsigned char* real_p; 
    TIM2_PICTUREHEADER_EX* temp; // not from the debugging symbols
    
    ring_check();
    
    for (p = &Ps2_tm_list_1st; p->admin.after != &Ps2_tm_list_last; p = (TIM2_PICTUREHEADER_EX*)real_p)
    {
        if (0) // FAKE
        {
            &p != NULL;
        }
        
        temp = p->admin.after; 
        
        after2 = temp->admin.after; 

        real_p = (unsigned char*)((int)p->admin.addr + p->admin.size); 

        if (((TIM2_PICTUREHEADER_EX*)real_p != temp) && (temp != &Ps2_tm_list_last))
        {
            after2->admin.before = real_p; 
            
            temp->admin.addr = real_p;  
            
            p->admin.after = real_p;

            after2 = (TIM2_PICTUREHEADER_EX*)real_p;

            size = temp->admin.size / 4;

            Ps2MemCopy4(real_p, temp, size);
        
            Ps2ReplaceTexAddr(after2->admin.gindex, real_p);
        }
    }

    ring_check();

    p = Ps2_tm_list_last.admin.before;
    
    size = p->admin.size;
    
    Ps2_now_free = (void*)((int)p->admin.addr + size);

    return 1;
}

// 100% matching!
int ring_check()
{
    TIM2_PICTUREHEADER_EX* after;
    TIM2_PICTUREHEADER_EX* p;

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
