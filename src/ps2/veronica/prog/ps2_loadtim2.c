#include "ps2_loadtim2.h"
#include "ps2_dummy.h"
#include "ps2_pxlconv.h"

//#include <string.h>

unsigned char clear_buff[1024];

// 100% matching! 
int Tim2CalcBufWidth(int psm, int w)
{
    switch (psm) 
    {
    case SCE_GS_PSMT8H:
    case SCE_GS_PSMT4HL:
    case SCE_GS_PSMT4HH:
    case SCE_GS_PSMCT32:
    case SCE_GS_PSMCT24:
    case SCE_GS_PSMZ32:
    case SCE_GS_PSMZ24:
    case SCE_GS_PSMCT16:
    case SCE_GS_PSMCT16S:
    case SCE_GS_PSMZ16:
    case SCE_GS_PSMZ16S:
        return (w + 63) / 64;
    case SCE_GS_PSMT8:
    case SCE_GS_PSMT4:
        w = (w + 63) / 64;
        
        if ((w & 0x1)) 
        {
            w++;
        }
        
        return w;
	}
    
	return 0;
}

// 100% matching! 
void Set_GsTex(TIM2_PICTUREHEADER* ph, unsigned long send_image_adr, unsigned long send_clut_adr)
{
    unsigned int i; 
    
    ph->GsTex0.CLD = 4;
    
    ph->GsTex0.CSA = 0;
    ph->GsTex0.CSM = 0;
    
    ph->GsTex0.CPSM = 0;
    
    ph->GsTex0.CBP = send_clut_adr;
    
    ph->GsTex0.TFX = 0;
    
    ph->GsTex0.TCC = 1;
    
    for (i = 0; (ph->ImageWidth != (1 << i)) && (i < 10); i++);
    
    if (ph->ImageWidth != (1 << i))
    {
        printf("This texture is not adequate size!!\n");
        
        exit(0); 
    }
    else 
    {
        ph->GsTex0.TW = i;
    }
    
    for (i = 0; (ph->ImageHeight != (1 << i)) && (i < 10); i++);
    
    if (ph->ImageHeight != (1 << i))
    {
        printf("This texture is not adequate size!!\n");
        
        exit(0);
    }
    else 
    {
        ph->GsTex0.TH = i;
    }
    
    switch (ph->ImageType) 
    {                            
    case TIM2_RGB16:
        ph->GsTex0.PSM = SCE_GS_PSMCT16; 
        break;
    case TIM2_RGB24:
        ph->GsTex0.PSM = SCE_GS_PSMCT24; 
        break;
    case TIM2_RGB32:
        ph->GsTex0.PSM = SCE_GS_PSMCT32; 
        break;
    case TIM2_IDTEX4:
        ph->GsTex0.PSM = SCE_GS_PSMT4; 
        break;
    case TIM2_IDTEX8:
        ph->GsTex0.PSM = SCE_GS_PSMT8;
        break;
    }

    ph->GsTex0.TBP0 = send_image_adr;
    
    ph->GsTex0.TBW = Tim2CalcBufWidth(ph->GsTex0.PSM, ph->ImageWidth);
}

// 100% matching! 
u_long128* MakeRenderTexHeader(void* tex_adr)
{
    TIM2_FILEHEADER* fHead; 
    TIM2_PICTUREHEADER* pHead; 
    unsigned char* work;     
    unsigned int fsize;    
    unsigned int psize;      
    unsigned int loop;        
    TIM2_PICTUREHEADER_EX *temp; // not from the debugging symbols

    work = tex_adr;
    
    temp = tex_adr;
    
    temp->ClampFlag = temp->TpFlag = 0;
    
    fHead = (TIM2_FILEHEADER*)tex_adr;
    
    strcpy(fHead->FileId, "TIM2");
    
    fHead->FormatVersion = 4;
    fHead->FormatId = 1;
    
    fHead->Pictures = 1;
    
    for (loop = 0; loop < 8; loop++)
    {
        fHead->Reserved[loop] = 0;
    }
    
    if (fHead->FormatId != 0)
    {
        fsize = 128;
        psize = 128;
        
        work += fsize;
    } 
    else 
    {
        fsize = 16;
        psize = 48;
        
        work += fsize;
    }

    pHead = (TIM2_PICTUREHEADER*)work;
    
    pHead->TotalSize = (fsize + 1048576) + psize;
    pHead->ClutSize = 0;
    pHead->ImageSize = 1048576;
    pHead->HeaderSize = psize;
    
    pHead->ClutColors = 0;
    
    pHead->PictFormat = 0;
    
    pHead->MipMapTextures = 1;
    
    pHead->ClutType = 0;
    pHead->ImageType = 3;
    
    pHead->ImageWidth = 512;
    pHead->ImageHeight = 512;
    
    pHead->GsTex0.TFX = 0;
    pHead->GsTex0.TCC = 1;
    pHead->GsTex0.TW = 8;
    pHead->GsTex0.TH = 8;
    pHead->GsTex0.PSM = 0;
    pHead->GsTex0.TBW = 8;
    
    work += psize;
    
    return (u_long128*)work;
}

// 100% matching! 
void StoreRenderTex(void* tex_adr)
{
    sceGsStoreImage gs_simage; 
    int loop; 
    int l;
    u_long128* p; 
    u_long128* imagetop; 
    
    imagetop = MakeRenderTexHeader(tex_adr);
    
    l = 255;
    
    for (loop = 0; loop < 512; loop += l) 
    {
        p = &imagetop[loop * 128]; 
        
        if ((loop + l) > 512) 
        {
            l = 512 - loop;
        }
        
        sceGsSetDefStoreImage(&gs_simage, 0, 10, SCE_GS_PSMCT32, 0, loop, 512, l);
        
        FlushCache(0);
        
        sceGsExecStoreImage(&gs_simage, p);
    } 
    
    Ps2ScreenClear();
}

// 99.82% matching
int LoadToVram(unsigned long tbp, u_long128* addr, int tbw, int psm, int pos, int width, int height, int size) 
{
    static unsigned long data[64]; 
    unsigned long* pBuff; 
    
    pBuff = UncAddr(data);
    
    D2_SyncTag();
    
    *pBuff++ = DMAcnt | 6;
    *pBuff++ = 0;
    
    *pBuff++ = SCE_GIF_SET_TAG(1, SCE_GS_FALSE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 4);
    *pBuff++ = 0xEEEE;
    
    *pBuff++ = SCE_GS_SET_BITBLTBUF(0, 0, 0, tbp, tbw, psm);
    *pBuff++ = SCE_GS_BITBLTBUF;
    
    *pBuff++ = SCE_GS_SET_TRXPOS(0, 0, 0, pos, 0);
    *pBuff++ = SCE_GS_TRXPOS;
    
    *pBuff++ = SCE_GS_SET_TRXREG(width, height);
    *pBuff++ = SCE_GS_TRXREG;
    
    *pBuff++ = SCE_GS_SET_TRXDIR(0);
    *pBuff++ = SCE_GS_TRXDIR;
    
    *pBuff++ = SCE_GIF_SET_TAG(size, SCE_GS_FALSE, SCE_GS_FALSE, 0, SCE_GIF_IMAGE, 0);
    *pBuff++ = 0;
    
    *pBuff++ = (u_long)(DMAref | size) | ((u_long)addr << 32);
    *pBuff++ = 0;
    
    *pBuff++ = DMAend | 2;
    *pBuff++ = 0;
    
    *pBuff++ = SCE_GIF_SET_TAG(1, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1); 
    *pBuff++ = SCE_GIF_PACKED_AD;
    
    *pBuff++ = 0;
    *pBuff++ = SCE_GS_TEXFLUSH;
    
    D2_SyncTag();
    
    loadImage(data);
    
    return 0;
}

// 99.83% matching
int Send_1024_Clut_data(void* clt_adr, unsigned long send_clut_adr)
{
    static unsigned long data[64]; 
    unsigned long* pBuff;        
    unsigned int loop;            
    unsigned int clt_lp;          
    u_long128* pClut;            

    pClut = clt_adr;

    for (clt_lp = 0; clt_lp < 4; clt_lp++) 
    {
        for (loop = 0; loop < 16; loop++) 
        {
            D2_SyncTag();

            pBuff = (unsigned long*)UNCACHED(data);
            
            *pBuff++ = DMAcnt | 6;
            *pBuff++ = 0;

            *pBuff++ = SCE_GIF_SET_TAG(1, SCE_GS_FALSE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 4);
            *pBuff++ = 0xEEEE;

            *pBuff++ = SCE_GS_SET_BITBLTBUF(0, 0, SCE_GS_PSMCT32, send_clut_adr + (clt_lp * 4), 1, SCE_GS_PSMCT32);
            *pBuff++ = SCE_GS_BITBLTBUF;
            
            *pBuff++ = SCE_GS_SET_TRXPOS(0, 0, (loop & 1) * 8, (loop / 2) * 2, 0);
            *pBuff++ = SCE_GS_TRXPOS;
            
            *pBuff++ = SCE_GS_SET_TRXREG(8, 2);
            *pBuff++ = SCE_GS_TRXREG;
            
            *pBuff++ = SCE_GS_SET_TRXDIR(0);
            *pBuff++ = SCE_GS_TRXDIR;
            
            *pBuff++ = SCE_GIF_SET_TAG(64, SCE_GS_FALSE, SCE_GS_FALSE, 0, SCE_GIF_IMAGE, 0);
            *pBuff++ = 0;
            
            *pBuff++ = (unsigned long)(DMAref | 64) | ((unsigned long)pClut << 32);
            *pBuff++ = 0;
            
            *pBuff++ = DMAend | 2;
            *pBuff++ = 0;
            
            *pBuff++ = SCE_GIF_SET_TAG(1, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1); 
            *pBuff++ = SCE_GIF_PACKED_AD;
            
            *pBuff++ = 0;
            *pBuff++ = SCE_GS_TEXFLUSH;
            
            D2_SyncTag();
            
            loadImage(data);
            
            pClut += 4;
        }
    } 
} 

// 100% matching! 
int Send_Tim2_dataEx(void* tim2_top_adr, unsigned long send_image_adr, unsigned long send_clut_adr)
{
    TIM2_PICTUREHEADER* pPhead;

    if (((unsigned char*)tim2_top_adr)[5] != 0) 
    {
        pPhead = (TIM2_PICTUREHEADER*)((int)tim2_top_adr + 128);
    }
    else
    {
        pPhead = (TIM2_PICTUREHEADER*)((int)tim2_top_adr + 16);
    }
    
    if ((pPhead->ClutType != 0) && (Clut_Load_Func(pPhead, send_clut_adr) < 0)) 
    {
        printf("Can't Load Clut\n");
        
        return -1;
    }
    else if (((pPhead->ImageWidth < 1024) && (pPhead->ImageHeight < 1024)) && ((pPhead->ImageWidth > 128) && (pPhead->ImageHeight > 128)) && ((pPhead->ImageType == 4) || (pPhead->ImageType == 5))) 
    {
        P32_Image_Load(pPhead, send_image_adr);
        
        Set_GsTex(pPhead, send_image_adr, send_clut_adr);
        
        return 1;
    }
    
    Tim2_Image_Load(pPhead, send_image_adr);
    
    Set_GsTex(pPhead, send_image_adr, send_clut_adr);
    
    return 2;
}

// 100% matching! 
int Clut_Load_Func(TIM2_PICTUREHEADER* ph, unsigned long clut_addr) 
{
    u_long128* pClut;
    int loop; 
    int h; 

    pClut = (u_long128*)((char*)ph + ph->HeaderSize + ph->ImageSize);

    switch ((ph->ClutType << 8) | ph->ImageType) 
    {
    case (TIM2_RGB32 << 8) | TIM2_IDTEX4:
    case (TIM2_RGB32 << 8) | TIM2_IDTEX8:
        for (loop = 0; loop < ph->ClutColors; loop += 256)
        {
            if ((ph->ClutColors - loop) < 256) 
            {
                h = (ph->ClutColors - loop) / 8;
            } 
            else 
            {
                h = 16;
            }
            
            LoadToVram(clut_addr, pClut, 1, SCE_GS_PSMCT32, 0, 16, h, 64);
        }
        
        break;
    default:
        return -1;
    }

    return 0;
}

// 100% matching!
int P32_Image_Load(TIM2_PICTUREHEADER* ph, unsigned long image_addr) 
{
    u_long128* pImage;
    int w;            
    int h;            
    int tbw;           
    int rrw;           
    int rrh;          
    int size;          

    w = ph->ImageWidth;
    h = ph->ImageHeight;

    size = ph->HeaderSize;

    pImage = (u_long128*)((char*)ph + size);

    tbw = w / 128;
    
    if (tbw == 0) 
    {
        tbw = 1;
    }

    rrw = w / 2;
    
    if (ph->ImageType == 5)
    {
        rrh = h / 2;
        
        size = (w * h) / 16;
    }
    else
    {
        rrh = h / 4;
        
        size = (w * h) / 32; 
    }
    
    LoadToVram(image_addr, pImage, tbw, 0, 0, rrw, rrh, size); 
    
    return 0;
}

#pragma divbyzerocheck on

// 99.91% matching
int Tim2_Image_Load(TIM2_PICTUREHEADER* ph, unsigned long image_addr)
{
    static int psmtbl[3] = { SCE_GS_PSMCT32, SCE_GS_PSMT4, SCE_GS_PSMT8 };
    u_long128* pImage;   
    u_long128* p;        
    int psm;              
    int w;             
    int h;                
    int n;                
    int l;                
    int i;               
    int tbw;           
    int param;            
  
    psm = psmtbl[ph->ImageType - 3];

    w = ph->ImageWidth;
    h = ph->ImageHeight;
    
    tbw = (w + 63) / 64;

    pImage = (u_long128*)((char*)ph + ph->HeaderSize);
    
    if (((psm == SCE_GS_PSMT8) || (psm == SCE_GS_PSMT4)) && ((tbw & 0x1))) 
    {
        tbw++;
    }
    
    switch (psm) 
    {                         
    case SCE_GS_PSMCT32:
        param = 2;
        
        n = w * 4;
        break;
    case SCE_GS_PSMT8:
        param = 4;
        
        n = w;
        break;
    case SCE_GS_PSMT4:
        param = 5;
        
        n = w / 2;
        break;
    }
    
    if (ph->ImageSize > (32764 * 16)) 
    {
        l = (32764 * 16) / n;
        
        for (i = 0; i < h; i += l) 
        {
            p = (u_long128*)((char*)pImage + (n * i)); 
            
            if ((i + l) > h) 
            {
                l = h - i;
            }
            
            LoadToVram(image_addr, p, tbw, psm, i, w, l, (psm == SCE_GS_PSMCT32) ? ((w * l) << 2) >> 4 : (w * l) >> param);
        } 
    } 
    else 
    {
        LoadToVram(image_addr, pImage, tbw, psm, 0, w, h, (w * h) >> param);
    }
    
    return 0;
}

#pragma divbyzerocheck off

// 100% matching!
void Ps2PxlconvCheck(void* timadr)
{
    TIM2_PICTUREHEADER* ph; 

    if (((unsigned char*)timadr)[5] == 0) 
    {
        ph = (TIM2_PICTUREHEADER*)((int)timadr + 16);
    }
    else 
    {
        ph = (TIM2_PICTUREHEADER*)((int)timadr + 128);
    }
    
    if (((ph->ImageWidth < 1024) && (ph->ImageHeight < 1024)) && ((ph->ImageWidth > 128) && (ph->ImageHeight > 128)) && ((ph->ImageType == 5) || (ph->ImageType == 4)))
    {
        Tim2_Format_Check(timadr); 
    }
}

// 100% matching! 
void SyncPath()
{
    unsigned int tmp;

    tmp = DGET_D_PCR(); 
    
    DPUT_D_PCR(DGET_D_PCR() & 0x2); 
    
    asm volatile (bc0t label_0f1); 

label_0b1:
    asm volatile 
    {
        bc0f label_0b1
        nop
    }

label_0f1:    
    DPUT_D_PCR(DGET_D_PCR() | tmp); 

    tmp = DGET_D_PCR(); 

    DPUT_D_PCR(DGET_D_PCR() & 0x4); 
    
    asm volatile (bc0t label_0f2); 

label_0b2:
    asm volatile 
    {
        bc0f label_0b2
        nop
    }
    
label_0f2:
    DPUT_D_PCR(DGET_D_PCR() | tmp); 

    while (DGET_VIF1_STAT() & 0x1F000003); 

    asm volatile 
    {
        loop:
        cfc2 a2, vi29
        
        andi v0, a2, 0x100
        bnez v0, loop
    }
    
    while (DGET_GIF_STAT() & 0xC00); 
} 

// 100% matching! 
void D2_SyncTag()
{
    unsigned int tmp;

    tmp = DGET_D_PCR(); 
    
    DPUT_D_PCR(DGET_D_PCR() & 0x4); 
    
    if ((DGET_D_PCR() & 0x4)) 
    { 
        asm volatile (bc0t label_0f); 
    
    label_0b:
        asm volatile 
        {
            bc0f label_0b
            nop
        }
    }

label_0f:
    DPUT_D_PCR(DGET_D_PCR() | tmp); 
}

// 100% matching! 
void loadImage(void* tags)
{
    asm volatile (bc0t label_0f); 
    
label_0b:
    asm volatile 
    {
        bc0f label_0b
        nop
    }

label_0f:
    DPUT_D_PCR(4); 
    DPUT_D_STAT(4); 

    DPUT_D2_TADR((int)tags); 
    DPUT_D2_CHCR(261); 
} 

// 100% matching!
void ClearVram()
{
    long128* p;
    int i;
    sceGsLoadImage li;

    for (i = 0; i < 1024; i++)
    {
        clear_buff[i] = 0;
    }
    
    p = (long128*)&clear_buff;
    
    for (i = 0; i < 16384UL; i++)
    {
        sceGsSetDefLoadImage(&li, i * 4, 4, 0, 0, 0, 16, 16);
        
        FlushCache(0);
        
        sceGsExecLoadImage(&li, p);
        
        sceGsSyncPath(0, 0);
    }
}
