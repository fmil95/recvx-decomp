#include "ps2_texture.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_dummy.h"
#include "main.h"

static NJS_TEXINFO info;
PS2_TEX_SAVE Ps2_tex_save[2];
static NJS_TEXLIST tlist = { NULL, 1 }; 
/*char fname[128];
char BIO_CURRENT[0];
_anon23 tbuf[0];
_anon6* rom;
BH_PWORK ene[0];
_anon23* Ps2_tex_info;*/

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

            VQflag = isVQ(((TIM2_PICTUREHEADER_EX*)ap)->PictFormat); 
            
            if (VQflag != 0) 
            {               
                gidx = ((TIM2_PICTUREHEADER_EX*)ap)->Gindex;
                
                switch (((TIM2_PICTUREHEADER_EX*)ap)->ImageType) 
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

                w = ((TIM2_PICTUREHEADER_EX*)ap)->ImageWidth; 
                h = ((TIM2_PICTUREHEADER_EX*)ap)->ImageHeight; 
                
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
                gidx = ((TIM2_PICTUREHEADER_EX*)ap)->Gindex;
                
                switch (((TIM2_PICTUREHEADER_EX*)ap)->ImageType) 
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
                
                w = ((TIM2_PICTUREHEADER_EX*)ap)->ImageWidth; 
                h = ((TIM2_PICTUREHEADER_EX*)ap)->ImageHeight; 
                
                ((TIM2_PICTUREHEADER_EX*)ap)->PalNum = palnum; 
                
                clutp = (unsigned int*)((ap + ((TIM2_PICTUREHEADER_EX*)ap)->ImageSize) + 256); 
                
                temp = (int*)((TIM2_PICTUREHEADER_EX*)ap)->PalData;
                
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

// 100% matching!
void bhReleaseMainTexture()
{
    BH_PWORK* pp; 
    O_WRK* op; 
    int i; 
    int j; 

    if (rom->mdl.texP != NULL)
    {
        njReleaseTexture(rom->mdl.texP);
    }

    for (i = 0; i < rom->ene_n; i++)
    {
        pp = &ene[rom->enep[i].wrk_no];

        if ((pp->flg & 0x1)) 
        {
            for (j = 0; j < pp->mdl_n; j++)
            {
                if ((pp->mdl[j].texP != NULL) && ((pp->mdl[j].flg & 0x200))) 
                {
                    njReleaseTexture(pp->mdl[j].texP);
                }
            }
        }
    }

    op = &sys->obwp[4];
    
    for (i = 4; i < rom->obj_n; i++, op++)
    {
        if (((op->flg & 0x1)) && ((op->mdl->texP != NULL) && ((op->mdl->flg & 0x200))))
        {
            njReleaseTexture(op->mdl->texP);
        }
    }

    op = sys->itwp;
    
    for (i = 0; i < rom->itm_n; i++, op++)
    {
        if (((op->flg & 0x1)) && ((op->mdl->texP != NULL) && ((op->mdl->flg & 0x200)))) 
        {
            njReleaseTexture(op->mdl->texP);
        }
    }

    if (sys->ef_extn != 0)
    {
        sys->ef_tlist.textures = (NJS_TEXNAME*)&sys->ef_tex[sys->ef_ctb].filename;
        
        sys->ef_tlist.nbTexture = sys->ef_extn;
        
        njReleaseTexture(&sys->ef_tlist);
        
        sys->ef_tlist.textures = (NJS_TEXNAME*)&sys->ef_tex[0].filename;
        
        sys->ef_tlist.nbTexture = sys->ef_ctb;
    }

    if (sys->ren_tlist.nbTexture != 0)
    {
        njReleaseTexture(&sys->ren_tlist);
        
        sys->ren_tlist.nbTexture = 0;
    }
    
    bhGarbageTexture(tbuf, 256);
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

// 100% matching!
char* bhCopyTexmem2Mainmem(NJS_TEXLIST* tlp, char* adr)
{
    char* temp; // not from DWARF

    temp = bhCopyTexmem2MainmemSub(tlp, adr);
    
    njReleaseTexture(tlp);
    
    return temp;
}

// 100% matching!
char* bhCopyTexmem2MainmemSub(NJS_TEXLIST* tlp, char* adr) 
{ 
    unsigned int i;      
    unsigned int num;    
    NJS_TEXMEMLIST* tmp; 
    
    Ps2_tex_save->num = num = tlp->nbTexture; 
    
    // debug code?
    if (0) 
    { 
        (void)&i; 
        (void)&adr; 
    }
    
    njSetTexture(tlp);
    
    for (i = 0; i < num; i++) 
    {
        tmp = (NJS_TEXMEMLIST*)tlp->textures[i].texaddr; 
        
        Ps2_tex_save->tmem[i] = *tmp; 
        
        Ps2_tex_save->addr[i] = adr; 
        
        Ps2MemCopy4(adr, tmp->texinfo.texsurface.pSurface, tmp->texinfo.texsurface.TextureSize / 4); 
        
        adr += tmp->texinfo.texsurface.TextureSize; 
    } 
    
    return adr; 
} 

// 100% matching!
void bhCopyMainmem2Texmem(NJS_TEXLIST* tlp) 
{ 
    unsigned int i;       
    unsigned int num;     
    NJS_TEXMEMLIST* addr; 
    int no;               
    NJS_TEXMEMLIST* tmp;  

    // debug code?
    if (0) 
    {
        (void)&i;
    }
    
    addr = Ps2_tex_info; 
    
    Ps2_tex_save->num = num = tlp->nbTexture; 
    
    for (i = 0; i < num; i++) 
    {
        tmp = &Ps2_tex_save->tmem[i]; 
        
        if ((no = SearchNumber(Ps2_tex_save->tmem[i].globalIndex, Ps2_tex_save->tmem[i].bank)) >= 0) 
        { 
            addr[no].count++; 
            
            ((TIM2_PICTUREHEADER_EX*)addr[no].texinfo.texsurface.pSurface)->admin.count++; 
            
            tlp->textures[i].texaddr = (unsigned int)&addr[no]; 
        } 
        else 
        { 
            if ((no = SearchNullNumber()) >= 0) 
            { 
                tlp->textures[i].texaddr = (unsigned int)&addr[no]; 
            } 
            else
            { 
                exit(0);
            }
            
            addr[no] = *tmp; 
            
            addr[no].count = 1; 
            
            addr[no].texinfo.texaddr = Ps2_tex_save->addr[i]; 
            
            if (Ps2TextureMalloc(&addr[no]) < 0)
            { 
                exit(0);
            }
        }
    } 
    
    Ps2_tex_save->num = 0; 
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
