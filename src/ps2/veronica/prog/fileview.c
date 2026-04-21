#include "../../../ps2/veronica/prog/fileview.h"
#include "../../../ps2/veronica/prog/message.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_texture.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/sub1.h"
#include "../../../ps2/veronica/prog/main.h"

FV_WORK fvwork;

unsigned int fstbl[24] = 
{
    13,  4, 4,  5,
     5,  7, 3,  6,
     8,  4, 4, 13,
     1,  1, 6,  7,
     9,  5, 4,  4,
     6, 11, 7,  6
};
unsigned int fsheader[24] = 
{
      0,  14,  19,  24,
     30,  36,  44,  48,
     55,  64,  69,  74,
     88,  90,  92,  99,
    107, 117, 123, 128,
    133, 140, 152, 160
};
unsigned int wallpaper[24] = 
{
    159, 157, 151, 148,
    150, 153, 158, 151,
    147, 146, 146, 146,
    155, 154, 152, 147,
    147, 156, 149, 149,
    148, 149, 152, 152
};
typedef void (*FileViewMode_proc)();
FileViewMode_proc FileViewMode[5] = { FileSelect, FileViewInit, FileViewMain, FileViewExit, FileGetWait };

// 100% matching!
void ControlFileView()
{
    FileViewMode[fvwork.mode_00]();
    
    ReadFstx();
}

// 100% matching!
void FileSelect()
{
	FV_WORK* fv;

	fv = &fvwork;

    switch (fv->mode_01)                        
    {
    case 0:
        fv->mode_01 = 1;

        fv->filecsr = 0;

        SearchTag(1);
        break;
    case 1:
        SelectFile();
        break;
    case 2:
        SelectTag();
        break;
    }
}

// 74.29% matching
void FileFlagInit01()
{
    fvwork.mode_00 = 1;
    fvwork.mode_01 = 0;
    
    parts_22b[2].atr &= ~0x20;
    
    fvwork.afsmode &= 0x780;
    
    parts_22b[3].atr &= ~0x20;
    
    fvwork.page = 0;
   
    njClipZ(-2.0f, -20000.0f); 
}

// 100% matching!
void FileFlagInit()
{
	fvwork.mode_00 = 1;
    fvwork.mode_01 = 0;
    
    parts_22b[2].atr &= ~0x20;
    
    fvwork.afsmode &= 0x780;
    
    parts_22b[3].atr &= ~0x20;
}

// 100% matching!
void GetFile()
{
    FV_WORK* fv;
    S_WORK* st;
    unsigned int id;

    fv = &fvwork;

    st = &swork;

    if ((sys->cb_flg & 0x20000))
    {
        id = sys->sb_id;
    } 
    else
    {
        id = st->itemid;
    }
    
    fv->filenum = FileNumberSwitch(id);
    
    sys->itm[383] |= 1 << fv->filenum;
    
    fv->page = 0;
}

// 100% matching!
void FileViewInit()
{
    S_WORK* st;
    FV_WORK* fv;

    st = &swork;
    fv = &fvwork; 
    
    switch (fv->mode_01) 
    {                    
    case 0:
        if (((swork.statusflg & 0x40000)) && (!(sys->cb_flg & 0x20000)))
        {
            njReleaseTexture(&st->subtx_list);
            
            bhGarbageTexture(tbuf, 256);
            
            swork.statusflg &= ~0x40000;
            
            fv->mode_01 = 1;
            
            fv->tex_flg = 1;
        }
        else if ((sys->cb_flg & 0x20000)) 
        {
            njReleaseTexture(&st->subtx_list);
            
            bhGarbageTexture(tbuf, 256);
            
            fv->mode_01 = 1;
            
            fv->tex_flg = 1;
        }
        
        break;
    case 1:
        if ((fvwork.afsmode & 0x2)) 
        {
            fv->mode_01 = 2;
        }
        
        break;
    case 2:
        fv->fstx_list.textures = fv->fstx;
        fv->fstx_list.nbTexture = bhSetMemPvpTexture(&fv->fstx_list, fv->fsp, 0);
        
        njSetTexture(&fv->fstx_list);
        
        fv->page = 0;
        
        parts_22b[1].atr |= 0x20;
        
        swork.statusflg |= 0x800;
        swork.statusflg |= 0x2000000;
        
        fv->mode_00 = 2;
        fv->mode_01 = 0;
        
        fv->bufnum = 0;
        
        ViewCnt = 2;
        break;
    }
}

// 100% matching!
void FileViewMain()
{
    FV_WORK* fv;
    
    fv = &fvwork;

    switch (fv->mode_01) 
    {                   
    case 0:
        fv->mode_01 = 1;
    case 1:
        FileScrollSet();
        
        PageScroll();
        
        FileEtcDisplay();
        break;
    }
}

// 100% matching!
void FileViewExit()
{
    if ((sys->cb_flg & 0x20000)) 
    {
        FileExit00();
    }
    else
    {
        FileExit01();
    }
}

// 100% matching!
void FileExit00()
{
	swork.statusflg |= 0x80000;
}

// 100% matching!
void FileExit01()
{
    S_WORK* st;    
    FV_WORK* fv;       
    int num;         
    unsigned int* wp; 
    unsigned int* itm; 

    st = &swork;
    fv = &fvwork;

    sys->memp = st->sspb;
    
    if (st->itemid != 85) 
    {
        if ((swork.statusflg & 0x8000))
        {
            swork.statusflg |= 0x80;
            swork.statusflg |= 0x40;
            
            swork.statusflg &= ~0x10;
            swork.statusflg &= ~0x8000;
            
            st->testmode = 1;
            st->mode = 2;
            st->subscreenmode = 2;
            
            st->maincsr = 1;
        }
    } 
    else if (fv->mode_02 == 0) 
    {
        st->subscreenmode = 2;
        
        swork.statusflg |= 0x80;
        swork.statusflg &= ~0x10;
        
        st->mode = 1;
        st->testmode = 0;
        
        parts_10b[15].anim = 5;
        
        parts_22b[2].atr &= ~0x20;
        parts_22b[3].atr &= ~0x20;
        
        st->wait = 0;
        
        st->number = 0;
        
        st->flag = 0;
        
        fvwork.afsmode &= ~0x20;
    }
    
    if ((swork.statusflg & 0x40000000)) 
    {
        swork.statusflg &= ~0x40000000;
        
        st->maincsr = 1;

		wp = ItemSearch(145);
        
        EraseItem(wp);
        
        sys->ic_flg[15] |= 0x80000000;
        
        for (num = 0; num < 4; num++) 
        {
            if (num == st->maincsr) 
            {
                parts_00b[num + 11].parts_num = 13;
            } 
            else 
            {
                parts_00b[num + 11].anim = menuanim[0][num];
                parts_00b[num + 11].parts_num = 10;
                
                parts_00b[num].anim = 0;
                parts_00b[num].parts_num = 0;
            }
        } 
    }
    else if ((fv->filenum == 0) && (!(sys->ic_flg[15] & 0x80000000))) 
    {
        itm = sys->itm;
        
        for (num = 0; num < 192; num++, itm++) 
        {
            if (*itm == 0x910001) 
            {
                *itm = 0;
                break;
            } 
        } 
        
        sys->ic_flg[15] |= 0x80000000;
    }
}

// 100% matching!
int SearchTag(int dir)
{
    FV_WORK* fv;
    int tagbak;

    fv = &fvwork;

    tagbak = fv->tag;

    while (TRUE) 
    {
        if (!(sys->itm[383] & (1 << (fv->tag + (fv->filecsr * 8))))) 
        {
            fv->tag = (fv->tag + dir) & 0x7;
            
            if (fv->tag == tagbak) 
            {
                return 0;
            } 
        }
        else 
        {
            return 1;
        }
    }
}

// 100% matching!
void SelectFile()
{
    FV_WORK* fv;
    S_WORK* st;
    SITEM* si;
    short i; 
    unsigned int tagbak; 

    fv = &fvwork;
    st = &swork;
    
    si = &sitem;
    
    si->mdl.objP->pos[1] = 0.5f;
    
    if ((!(swork.statusflg & 0x40)) && ((fv->mode_02 == 0) && (fv->z == 0))) 
    {
        parts_10b[13].col.r = 0.7f;
        parts_10b[13].col.g = 0.7f;
        parts_10b[13].col.b = 0.7f;
        
        parts_10b[14].col.r = 0.7f;
        parts_10b[14].col.g = 0.7f;
        parts_10b[14].col.b = 0.7f;
        
        if ((!(sys->pad_ps & 0x1800)) && (!(swork.statusflg & 0x40000000)))
        {
            swork.statusflg &= ~0x20000000;
            
            if (fv->roll == 0) 
            {
                if (((sys->pad_on & 0x4)) && (fv->j == 0))
                {
                    parts_10b[14].col.r = 1.0f;
                    parts_10b[14].col.g = 1.0f;
                    parts_10b[14].col.b = 1.0f;

                    fv->tag = 0;
                    
                    fv->filecsr++;
                    
                    fv->roll = 1;
                    
                    if (fv->filecsr > 2) 
                    {
                        fv->filecsr = 0;
                    }
                    
                    for (i = 0; i < 8; i++) 
                    {
                        fv->koma[i] = 2730;
                    }
                    
                    fv->z = 1;
                    
                    CallSystemSe(0, 6);
                }
                else if (((sys->pad_on & 0x8)) && (fv->j == 0)) 
                {
                    parts_10b[13].col.r = 1.0f;
                    parts_10b[13].col.g = 1.0f;
                    parts_10b[13].col.b = 1.0f;

                    fv->tag = 0;
                    
                    fv->filecsr--;
                    
                    fv->roll = 1;
                    
                    if (fv->filecsr < 0) 
                    {
                        fv->filecsr = 2;
                    }
                    
                    for (i = 0; i < 8; i++)
                    {
                        fv->koma[i] = -2730;
                    }
                    
                    fv->z = 1;
                    
                    CallSystemSe(0, 6);
                }
            }
        } 
        else if (fv->roll == 0)
        {
            if (((sys->pad_ps & 0x800)) || ((swork.statusflg & 0x40000000))) 
            {
                if (SearchTag(1) != 0)
                {
                    fv->z = 2;
                    
                    CallSystemSe(0, 3);
                    
                    for (i = 0; i < 6; i++) 
                    {
                        fv->koma2[i] = 1820;
                    }
                    
                    swork.statusflg |= 0x20000000;
                } 
                else 
                {
                    swork.statusflg &= ~0x20000000;
                }
            } 
            else if ((sys->pad_ps & 0x1000)) 
            {
                st->mode = 2;
                st->testmode = 1;
                
                st->maincsr = 1;
                
                st->number = 1;
                
                st->wait = 0;
                
                NameChangeSet(st);
                
                st->wn = 0;
                
                swork.statusflg |= 0x20000;
                
                CallSystemSe(0, 0);
            }
        }
    }
    
    switch (fv->z) 
    {                             
    case 1:                                         
        if ((short)fv->koma[fv->j] != 0) 
        {
            si->mdl.objP->child->ang[1] += fv->koma[fv->j];
            si->mdl.objP->child->sibling->ang[1] += fv->koma[fv->j];
            si->mdl.objP->child->sibling->sibling->ang[1] += fv->koma[fv->j];
            
            fv->j++;
            break;
        }
        
        si->mdl.objP->child->ang[1] = (short)((fv->filecsr * 21845) - 32768);
        si->mdl.objP->child->sibling->ang[1] = (short)((fv->filecsr * 21845) - 32768); 
        si->mdl.objP->child->sibling->sibling->ang[1] = (short)((fv->filecsr * 21845) - 32768);
        
        fv->roll = 0;
        
        fv->z = 0;
        fv->j = 0;
        
        for (i = 0; i < 16; i++)
        {
            fv->koma[i] = 0;
        }
        
        break;
    case 2:                                         
        if ((short)fv->koma2[fv->j] != 0) 
        {
            switch (fv->filecsr) 
            {               
            case 0:                                 
                si->mdl.objP->child->sibling->ang[1] += fv->koma2[fv->j];
                si->mdl.objP->child->sibling->sibling->ang[1] -= fv->koma2[fv->j];
                break;
            case 1:                                 
                si->mdl.objP->child->ang[1] += fv->koma2[fv->j];
                si->mdl.objP->child->sibling->ang[1] -= fv->koma2[fv->j];
                break;
            case 2:                                 
                si->mdl.objP->child->ang[1] -= fv->koma2[fv->j];
                si->mdl.objP->child->sibling->sibling->ang[1] += fv->koma2[fv->j];
                break;
            }
            
            fv->j++;
            break;
        }
        
        fv->j = 0;
        
        for (i = 0; i < 6; i++) 
        {
            fv->koma2[i] = 1820;
        }
        
        fv->z = 3;
        
        fvwork.afsmode |= 0x20;
        break;
    case 3:                                         
        if ((short)fv->koma2[fv->j] != 0) 
        {
            fv->ang00 -= fv->koma2[fv->j];
            
            fv->j++;
            break;
        }
        
        tagbak = fv->tag;
        
        fv->j = 0;
        
        for (i = 0; i < 6; i++) 
        {
            fv->koma2[i] = 0;
        }
        
        fv->z = 0;
        
        st->testmode = 9;
        
        while (TRUE)
        { 
            if (!(sys->itm[383] & (1 << (fv->tag + (fv->filecsr * 8))))) 
            {
                fv->tag++;
                
                if (fv->tag > 7) 
                {
                    fv->tag = 0;
                }
                
                if (fv->tag == tagbak) 
                {
                    break;
                }  
            }
            else
            {
                break;
            }
        }
        
        break;
    }
}

// 
// Start address: 0x2acf10
void SelectTag()
{
	int title;
	int tagbak;
	short i;
	//_anon26 mpos;
	//_anon14* si;
	FV_WORK* fv;
	S_WORK* st;
	// Line 648, Address: 0x2acf10, Func Offset: 0
	// Line 650, Address: 0x2acf20, Func Offset: 0x10
	// Line 657, Address: 0x2acf28, Func Offset: 0x18
	// Line 651, Address: 0x2acf2c, Func Offset: 0x1c
	// Line 657, Address: 0x2acf34, Func Offset: 0x24
	// Line 652, Address: 0x2acf38, Func Offset: 0x28
	// Line 657, Address: 0x2acf3c, Func Offset: 0x2c
	// Line 659, Address: 0x2acf58, Func Offset: 0x48
	// Line 663, Address: 0x2acf90, Func Offset: 0x80
	// Line 664, Address: 0x2acf9c, Func Offset: 0x8c
	// Line 667, Address: 0x2acfa4, Func Offset: 0x94
	// Line 669, Address: 0x2acfa8, Func Offset: 0x98
	// Line 666, Address: 0x2acfac, Func Offset: 0x9c
	// Line 667, Address: 0x2acfb8, Func Offset: 0xa8
	// Line 668, Address: 0x2acfc8, Func Offset: 0xb8
	// Line 669, Address: 0x2acfd4, Func Offset: 0xc4
	// Line 670, Address: 0x2acffc, Func Offset: 0xec
	// Line 671, Address: 0x2ad008, Func Offset: 0xf8
	// Line 674, Address: 0x2ad010, Func Offset: 0x100
	// Line 675, Address: 0x2ad01c, Func Offset: 0x10c
	// Line 680, Address: 0x2ad024, Func Offset: 0x114
	// Line 677, Address: 0x2ad028, Func Offset: 0x118
	// Line 678, Address: 0x2ad034, Func Offset: 0x124
	// Line 679, Address: 0x2ad048, Func Offset: 0x138
	// Line 680, Address: 0x2ad054, Func Offset: 0x144
	// Line 681, Address: 0x2ad07c, Func Offset: 0x16c
	// Line 686, Address: 0x2ad088, Func Offset: 0x178
	// Line 689, Address: 0x2ad0a8, Func Offset: 0x198
	// Line 694, Address: 0x2ad0b0, Func Offset: 0x1a0
	// Line 691, Address: 0x2ad0b8, Func Offset: 0x1a8
	// Line 692, Address: 0x2ad0bc, Func Offset: 0x1ac
	// Line 689, Address: 0x2ad0c0, Func Offset: 0x1b0
	// Line 690, Address: 0x2ad0cc, Func Offset: 0x1bc
	// Line 694, Address: 0x2ad0d0, Func Offset: 0x1c0
	// Line 691, Address: 0x2ad0dc, Func Offset: 0x1cc
	// Line 690, Address: 0x2ad0e0, Func Offset: 0x1d0
	// Line 694, Address: 0x2ad0e4, Func Offset: 0x1d4
	// Line 698, Address: 0x2ad0ec, Func Offset: 0x1dc
	// Line 700, Address: 0x2ad0f4, Func Offset: 0x1e4
	// Line 704, Address: 0x2ad118, Func Offset: 0x208
	// Line 705, Address: 0x2ad140, Func Offset: 0x230
	// Line 706, Address: 0x2ad14c, Func Offset: 0x23c
	// Line 707, Address: 0x2ad154, Func Offset: 0x244
	// Line 708, Address: 0x2ad15c, Func Offset: 0x24c
	// Line 711, Address: 0x2ad164, Func Offset: 0x254
	// Line 709, Address: 0x2ad168, Func Offset: 0x258
	// Line 708, Address: 0x2ad170, Func Offset: 0x260
	// Line 709, Address: 0x2ad17c, Func Offset: 0x26c
	// Line 710, Address: 0x2ad188, Func Offset: 0x278
	// Line 711, Address: 0x2ad18c, Func Offset: 0x27c
	// Line 712, Address: 0x2ad190, Func Offset: 0x280
	// Line 715, Address: 0x2ad1a4, Func Offset: 0x294
	// Line 716, Address: 0x2ad1b8, Func Offset: 0x2a8
	// Line 717, Address: 0x2ad1c4, Func Offset: 0x2b4
	// Line 719, Address: 0x2ad1d4, Func Offset: 0x2c4
	// Line 718, Address: 0x2ad1d8, Func Offset: 0x2c8
	// Line 719, Address: 0x2ad1dc, Func Offset: 0x2cc
	// Line 718, Address: 0x2ad1e0, Func Offset: 0x2d0
	// Line 719, Address: 0x2ad1e4, Func Offset: 0x2d4
	// Line 720, Address: 0x2ad1fc, Func Offset: 0x2ec
	// Line 723, Address: 0x2ad200, Func Offset: 0x2f0
	// Line 724, Address: 0x2ad208, Func Offset: 0x2f8
	// Line 725, Address: 0x2ad218, Func Offset: 0x308
	// Line 726, Address: 0x2ad230, Func Offset: 0x320
	// Line 727, Address: 0x2ad244, Func Offset: 0x334
	// Line 728, Address: 0x2ad24c, Func Offset: 0x33c
	// Line 730, Address: 0x2ad254, Func Offset: 0x344
	// Line 729, Address: 0x2ad258, Func Offset: 0x348
	// Line 730, Address: 0x2ad25c, Func Offset: 0x34c
	// Line 732, Address: 0x2ad268, Func Offset: 0x358
	// Line 731, Address: 0x2ad26c, Func Offset: 0x35c
	// Line 732, Address: 0x2ad270, Func Offset: 0x360
	// Line 731, Address: 0x2ad274, Func Offset: 0x364
	// Line 732, Address: 0x2ad278, Func Offset: 0x368
	// Line 733, Address: 0x2ad294, Func Offset: 0x384
	// Line 734, Address: 0x2ad29c, Func Offset: 0x38c
	// Line 736, Address: 0x2ad2b0, Func Offset: 0x3a0
	// Line 737, Address: 0x2ad2c4, Func Offset: 0x3b4
	// Line 738, Address: 0x2ad2dc, Func Offset: 0x3cc
	// Line 740, Address: 0x2ad300, Func Offset: 0x3f0
	// Line 741, Address: 0x2ad320, Func Offset: 0x410
	// Line 742, Address: 0x2ad348, Func Offset: 0x438
	// Line 744, Address: 0x2ad350, Func Offset: 0x440
	// Line 745, Address: 0x2ad36c, Func Offset: 0x45c
	// Line 746, Address: 0x2ad390, Func Offset: 0x480
	// Line 748, Address: 0x2ad398, Func Offset: 0x488
	// Line 749, Address: 0x2ad3b4, Func Offset: 0x4a4
	// Line 752, Address: 0x2ad3e0, Func Offset: 0x4d0
	// Line 753, Address: 0x2ad3e8, Func Offset: 0x4d8
	// Line 754, Address: 0x2ad3f0, Func Offset: 0x4e0
	// Line 755, Address: 0x2ad3f4, Func Offset: 0x4e4
	// Line 757, Address: 0x2ad400, Func Offset: 0x4f0
	// Line 756, Address: 0x2ad404, Func Offset: 0x4f4
	// Line 757, Address: 0x2ad408, Func Offset: 0x4f8
	// Line 756, Address: 0x2ad40c, Func Offset: 0x4fc
	// Line 757, Address: 0x2ad410, Func Offset: 0x500
	// Line 758, Address: 0x2ad42c, Func Offset: 0x51c
	// Line 759, Address: 0x2ad434, Func Offset: 0x524
	// Line 763, Address: 0x2ad438, Func Offset: 0x528
	// Func End, Address: 0x2ad44c, Func Offset: 0x53c
	scePrintf("SelectTag - UNIMPLEMENTED!\n");
}

// 100% matching!
void FileScreenCancel()
{
    FV_WORK* fv;
    unsigned short i;
    unsigned short j;

    fv = &fvwork;
    
    if ((fv->afsmode & 0x80)) 
    {
        njReleaseTexture(&fv->fstx_list);
        
        bhGarbageTexture(tbuf, 256);
    }
    
    fvwork.afsmode &= ~0xB80;
    
    if (!(sys->cb_flg & 0x20000)) 
    {
        fvwork.afsmode |= 0x20;
    }

    for (i = 0; i < 12; i++) 
    {
        for (j = 0; j < 6; j++) 
        {
            cen_pos[i][j] = cen_pos99[i][j];
        }
    }

    parts_22b[0].atr &= ~0x20;
    
    fvwork.flg &= ~0x1;
    
    swork.statusflg &= ~0x800;
    
    parts_22b[1].atr &= ~0x20;
    parts_22b[2].atr &= ~0x20;
    parts_22b[3].atr &= ~0x20;
    parts_22b[4].atr &= ~0x20;
    
    parts_22b[4].color |= 0x8;
    
    fv->mode_00 = 3;
    fv->mode_01 = 0;

    if ((sys->cb_flg & 0x20000)) 
    {
        fv->mode_02 = 0;
    }
    else 
    {
        fv->mode_02 = 7;
    }
}

// 100% matching!
void FileScrollSet()
{
    S_WORK* st;
    FV_WORK* fv;
    int page_end;
	
    st = &swork;
    fv = &fvwork;

    page_end = 0;
    
    if (fv->filenum == 0) 
    {
        page_end = PlayPageCheck();
    }
    
    if ((fv->scrol == 3) || (fv->scrol == 4)) 
    {
        fv->bufnum = fv->page + 280;
        fv->bufnum = (fv->page + 280) + fsheader[fv->filenum];
    }
    
    if (((!(fvwork.afsmode & 0x800)) && (fv->scrol == 0) && (fv->mode_02 == 0)) && (!(swork.statusflg & 0x40))) 
    {
        if (fv->pagewait01 == 0)
        {
            if (!(sys->pad_ps & 0x1800)) 
            {
                if ((sys->pad_on & 0x8)) 
                {
                    if (fv->page != ((fstbl[fv->filenum] & 0xF) - page_end))
                    {
                        fv->scrol = 1;
                        
                        fv->move = 10;
                        
                        fv->page++;
                        
                        if (!(fv->page & 0x1))
                        {
                            fv->mode_02 = 3;
                            fv->mode_03 = 1;
                        }
                        
                        CallSystemSe(0, 4);
                        return;
                    }
                    
                    if (fv->page == ((fstbl[fv->filenum] & 0xF) - page_end)) 
                    {
                        parts_22b[4].color &= ~0x8;
                        parts_22b[4].atr &= ~0x4;
                        
                        parts_22b[4].col.a = 1.0f;
                        parts_22b[4].col.r = 1.0f;
                        parts_22b[4].col.g = 1.0f;
                        parts_22b[4].col.b = 1.0f;
                    }
                }
                else if (((sys->pad_on & 0x4)) && (fv->page != 0)) 
                {
                    if ((parts_22b[4].color & 0x8))
                    {
                        parts_22b[4].atr &= ~0x20;
                        
                        fv->scrol = 2;
                        
                        fv->move = 10;
                        
                        fv->page--;
                        
                        if ((fv->page & 0x1))
                        {
                            fv->mode_02 = 5;
                            fv->mode_03 = 1;
                        }
                        
                        CallSystemSe(0, 4);
                        return;
                    }
                    
                    fv->pagewait01 = 2;
                    
                    parts_22b[4].color |= 0x8;
                    parts_22b[4].atr |= 0x4;
                    
                    parts_22b[4].col.a = 1.0f;
                    parts_22b[4].col.r = 0.4f;
                    parts_22b[4].col.g = 0.4f;
                    parts_22b[4].col.b = 0.4f;
                }
            } 
            else 
            {
                if ((sys->pad_ps & 0x800)) 
                {
                    if (!(parts_22b[4].color & 0x8))
                    {
                        if (((sys->cb_flg & 0x20000)) || (st->itemid == 85)) 
                        {
                            fv->mode_00 = 4;
                            fv->mode_01 = 0;
                            
                            CallSystemSe(0, 3);
                            return;
                        }
                        else 
                        {
                            CallSystemSe(0, 3);
                            
                            FileScreenCancel();
                            return;
                        }
                    }
                }
                if ((sys->pad_ps & 0x1000)) 
                {
                    if (((sys->cb_flg & 0x20000)) || (st->itemid == 85)) 
                    {
                        fv->mode_00 = 4;
                        fv->mode_01 = 0;
                        
                        CallSystemSe(0, 3);
                        return;
                    } 
                    else 
                    {
                        FileScreenCancel();
                        
                        CallSystemSe(0, 0);
                        return;
                    }
                }
            }
        }
        else 
        {
            fv->pagewait01--;
        }
    }
}

// 100% matching! 
void FileGetWait()
{
    FV_WORK* fv;

    fv = &fvwork;

    switch (fv->mode_01)
    {                             
    case 0:
        sys->sb_id = fv->filenum + 159;
        
        bhSetMessage(1, 152);
        
        fv->mode_01 = 1;

        parts_22b[0].atr &= ~0x20;
        parts_22b[1].atr &= ~0x20;
        parts_22b[2].atr &= ~0x20;
        parts_22b[3].atr &= ~0x20;
        parts_22b[4].atr &= ~0x20;
    case 1:
        if (((sys->st_flg & 0x4000)) && ((sys->st_flg & 0x1000)) && (((sys->pad_ps & 0x800)) || ((sys->pad_ps & 0x1000)) || ((sys->st_flg & 0x8000)))) 
        {
            sys->st_flg &= ~0x200;
           
            CallSystemSe(0, 3);
            
            sys->sb_id = 0;
            
            fv->mode_01 = 0;
            
            FileScreenCancel();
        }
        
        break;
    }
}

// 100% matching!
void PageScroll()
{
    FV_WORK* fv;
    int page_end;
    
    fv = &fvwork;  

    page_end = 0;
    
    if (fv->filenum == 0) 
    {
        page_end = PlayPageCheck();
    }
    
    if (!(fvwork.afsmode & 0x800)) 
    {
        if ((fv->scrol == 1) || (fv->scrol == 3)) 
        {
            if (fv->scrol == 3) 
            {
                if (fv->mode_02 == 0)
                {
                    parts_22b[0].pos[0] -= fv->move;
                    parts_22b[4].pos[0] -= fv->move;
                    
                    fv->move += fv->move;
                }
            } 
            else 
            {
                parts_22b[0].pos[0] -= fv->move;
                parts_22b[4].pos[0] -= fv->move;
                
                fv->move += fv->move;
            }
            
            if ((fv->move > 640.0f) && (fv->scrol == 1)) 
            {
                parts_22b[0].pos[0] = 708.0f;
                parts_22b[4].pos[0] = 1200.0f;
                
                if (fv->page == ((fstbl[fv->filenum] & 0xF) - page_end)) 
                {
                    parts_22b[4].atr |= 0x24;
                    parts_22b[4].color |= 0x8;
                    
                    parts_22b[4].col.a = 1.0f;
                    parts_22b[4].col.r = 0.4f;
                    parts_22b[4].col.g = 0.4f;
                    parts_22b[4].col.b = 0.4f;
                }
                
                fvwork.afsmode |= 0x800;
                
                fv->pagewait00 = 8;
                
                fv->scrol = 3;
                
                fv->move = 10;
                
                parts_22b->atr &= ~0x20;
            } 
            else if ((parts_22b->pos[0] < 0) && (fv->scrol == 3)) 
            {
                if ((fvwork.afsmode |= 0x4) != 0) 
                {
                    fvwork.afsmode &= ~0x4;
                    
                    swork.statusflg &= ~0x40;
                    
                    fv->pagewait01 = 2;
                }
                
                parts_22b[0].pos[0] = 68.0f;
                parts_22b[4].pos[0] = 560.0f;
                
                fv->scrol = 0;
                
                fv->move = 10;
            }
        } 
        else if ((fv->scrol == 2) || (fv->scrol == 4)) 
        {
            if (fv->scrol == 4)
            {
                if (fv->mode_02 == 0) 
                {
                    parts_22b[0].pos[0] += fv->move;
                    parts_22b[4].pos[0] += fv->move;
                    
                    fv->move += fv->move;
                }
            } 
            else 
            {
                parts_22b[0].pos[0] += fv->move;
                parts_22b[4].pos[0] += fv->move;
                
                fv->move += fv->move;
            }
            
            if ((fv->move > 640.0f) && (fv->scrol == 2)) 
            {
                parts_22b[0].pos[0] = -572.0f;
                parts_22b[4].pos[0] = -80.0f;
                
                fvwork.afsmode |= 0x800;
                
                fv->pagewait00 = 8;
                
                fv->move = 10;
                
                fv->scrol = 4;
                
                parts_22b->atr &= ~0x20;
            } 
            else if ((parts_22b->pos[0] > 0) && (fv->scrol == 4)) 
            {
                parts_22b[0].pos[0] = 68.0f;
                parts_22b[4].pos[0] = 560.0f;
                
                fv->scrol = 0;
                
                fv->move = 10;
            }
        }
    } 
    else if (GetReadFileStatus() == 1) 
    {
        return;
    } 
    else if (fv->pagewait00 == 0) 
    {
        fvwork.afsmode &= ~0x800;
        
        fv->pagewait01 = 2;
    }
    else 
    {
        fv->pagewait00--;
    }
    
    bhDispMessage(parts_22b->pos[0], 64.0f, -1.0f, 1, fv->bufnum, 0, 0);
}

// 100% matching!
void FileEtcDisplay()
{
    FV_WORK* fv;
    int page_end;
	static unsigned short flg;
	static unsigned short count;

    fv = &fvwork;

    page_end = 0;
    
    if (fv->page == 0) 
    {
        fvwork.flg |= 0x1;
    } 
    else 
    {
        fvwork.flg &= ~0x1;
    }
    
    if (fv->filenum == 0) 
    { 
        page_end = PlayPageCheck(fv->filenum);
    }
    
    if ((fv->page != 0) && (fv->scrol == 0)) 
    {
        if (fv->page == ((fstbl[fv->filenum] & 0xF) - page_end)) 
        {
            if ((parts_22b[4].color & 0x8)) 
            {
                parts_22b[2].atr |= 0x20;
            } 
            else 
            {
                parts_22b[2].atr &= ~0x20;
            }
            
            parts_22b[3].atr &= ~0x20;
        } 
        else 
        {
            parts_22b[2].atr |= 0x20;
            parts_22b[3].atr |= 0x20;
        }
    }
    else if ((fv->scrol == 0) && ((fvwork.flg & 0x1)))
    {
        parts_22b[2].atr &= ~0x20;
        
        if (fv->page != ((fstbl[fv->filenum] & 0xF) - page_end)) 
        {
            if (fv->mode_02 == 0) 
            {
                parts_22b[3].atr |= 0x20;
            }
        } 
        else 
        {
            parts_22b[3].atr &= ~0x20;
        }
    } 
    else 
    {
        parts_22b[2].atr &= ~0x20;
        parts_22b[3].atr &= ~0x20;
    }
    
    count++;
    
    if (count > 4) 
    {
        count = 0;
        
        flg = (flg + 1) & 0x1;
    }
    
    if (count == 3) 
    {
        if (flg != 0) 
        {
            parts_22b[2].pos[0] -= 2.0f;
            parts_22b[3].pos[0] += 2.0f;
        } 
        else 
        {
            parts_22b[2].pos[0] += 2.0f;
            parts_22b[3].pos[0] -= 2.0f;
        }
    }
}

// 100% matching!
void StatusToFileView()
{
    FV_WORK* fv;
    unsigned short num1;

    fv = &fvwork;
    
    swork.statusflg |= 0x9002040;
    
    cen_pos[1][3] = -80.0f;
    cen_pos[2][2] = -448.0f;
    cen_pos[3][2] = 640.0f;
    cen_pos[4][2] = 808.0f;
    cen_pos[5][2] = 644.0f;
    cen_pos[6][3] = 484.0f;
    
    cen_pos[8][2] = -380.0f;
    cen_pos[9][2] = 644.0f;
    cen_pos[10][3] = -384.0f;
    cen_pos[11][2] = 660.0f;

    for (num1 = 1; num1 < 12; num1++) 
    {
        if (num1 != 3)
        {
            cen_pos[num1][4] = cen_pos[num1][2] - cen_pos[num1][0];
            cen_pos[num1][5] = cen_pos[num1][3] - cen_pos[num1][1];
        }
        else 
        {
            cen_pos[num1][4] = cen_pos[num1][2] - 352.0f;
        }
    }

    parts_22b[2].atr &= ~0x20;
    parts_22b[3].atr &= ~0x20;
    
    fv->mode_02 = 1;
}

// 100% matching!
void ReadFstx() 
{
    S_WORK* st;
    FV_WORK* fv;
    int sz;
    unsigned int num;

    st = &swork;
    fv = &fvwork;

    fv->part_id = sys->itm_partid;
    
    if ((!(sys->cb_flg & 0x20000)) && (st->itemid != 85)) 
    {
        fv->filenum = fv->tag + (fv->filecsr * 8);
    }
    
    switch (fv->mode_02)
    {
    case 1:
        num = wallpaper[fv->filenum];
        
        fv->rdsz = GetInsideFileSize(fv->part_id, num);
        
        if (!(fvwork.afsmode & 0x80)) 
        {
            fv->fsp = bhGetFreeMemory(fv->rdsz, 32);
            
            fvwork.afsmode |= 0x80;
        }
        
        RequestReadInsideFile(fv->part_id, num, fv->fsp);
        
        fv->mode_02 = 2;
        break;
    case 2:
        if (GetReadFileStatus() == 0) 
        {
            fvwork.afsmode &= ~0x1;
            
            fv->mode_02 = 3;
            
            fvwork.afsmode |= 0x4;
            fvwork.afsmode |= 0x2;
            break;
        }
    default:
        break;
    case 3:
        if (GetReadFileStatus() != 1)
        {
            fv->mode_02 = 4;
        }
        
        break;
    case 4:
        if (fv->page > 1) 
        {
            fv->mode_02 = 0;
            break;
        }
        
        if ((fvwork.afsmode & 0x4)) 
        {
            fv->scrol = 3;
            
            fv->move = 10;
            
            parts_22b->pos[0] = 708.0f;
            parts_22b[4].pos[0] = 1200.0f;
            
            CallSystemSe(0, 4);
            
            fv->mode_02 = 0;
        }
        
        break;
    case 5:
        fv->mode_02 = 0;
        break;
    case 6:
        fv->mode_02 = 0;
        break;
    case 7:
        if (!(fvwork.afsmode & 0x400)) 
        {
            sz = GetInsideFileSize(sys->itm_partid, 145);
            
            st->ssp = bhGetFreeMemory(sz, 32);
            
            fvwork.afsmode |= 0x400;
        }
        
        RequestReadInsideFile(sys->itm_partid, 145, st->ssp);
        
        fv->mode_02 = 8;
        break;
    case 8:
        if (GetReadFileStatus() == 0) 
        {
            st->subtx_list.textures = st->subtx;
            st->subtx_list.nbTexture = 5;
            
            bhSetMemPvpTexture(&st->subtx_list, st->ssp, 0);
            
            fv->tex_flg = 0;
            
            njSetTexture(&st->subtx_list);
            
            swork.statusflg |= 0x2000;
            swork.statusflg |= 0x40;
            
            swork.statusflg &= ~0x1020000;
            
            fv->mode_02 = 0;
            
            fvwork.afsmode &= ~0x400;
            
            sys->memp = st->sspb;
            
            if (st->itemid != 85) 
            {
                st->testmode = 9;
                st->subscreenmode = 2;
                st->mode = 8;
            }
        }
        
        break;
    case 9:
        break;
    }
}

// 100% matching! 
unsigned int FileNumberSwitch(unsigned int num)
{
    unsigned int filenum;

    filenum = 0;
    
    switch (sys->rom_no + (sys->stg_no * 100)) 
    {                   
    case 7:
        if (num == 48) 
        {
            filenum = 8;
        }
        
        break;
    case 11:
        if (num == 47) 
        {
            filenum = 9;
        }
        
        break;
    case 108:
        if (num == 47) 
        {
            filenum = 10;
        }
        
        break;
    case 207:
        if (num == 135) 
        {
            filenum = 12;
        }
        
        if (num == 102) 
        {
            filenum = 18;
        }
        
        break;
    case 204:
        if (num == 134) 
        {
            filenum = 13;
        }
        
        break;
    case 106:
        if (num == 133) 
        {
            filenum = 14;
        }
        
        break;
    case 601:
    case 901:
        if (num == 48) 
        {
            filenum = 15;
        }
        
        break;
    case 604:
        if (num == 48) 
        {
            filenum = 16;
        }
        
        if (num == 132) 
        {
            filenum = 17;
        }
        
        break;
    case 607:
    case 907:
        if (num == 132) 
        {
            filenum = 17;
        }
        
        break;
    case 702:
        if (num == 102) 
        {
            filenum = 19;
        }
        
        break;
    case 922:
        if (num == 49) 
        {
            filenum = 20;
        }
        
        break;
    case 904:
        if (num == 102) 
        {
            filenum = 21;
        }
        
        if (num == 48) 
        {
            filenum = 16;
        }
        
        break;
    case 919:
        if (num == 133) 
        {
            filenum = 22;
        }
        
        break;
    case 918:
        if (num == 133) 
        {
            filenum = 23;
        }
        
        break;
    case 4:
        if (num == 132) 
        {
            filenum = 1;
        }
        
        break;
    case 9:
        if (num == 49) 
        {
            filenum = 3;
        }
        
        break;
    case 313:
    case 718:
        if (num == 132) 
        {
            filenum = 4;
        }
        
        break;
    case 104:
        if (num == 58) 
        {
            filenum = 5;
        }
        
        break;
    case 929:
        if (num == 125) 
        {
            filenum = 6;
        }
        
        break;
    case 712:
        if (num == 132) 
        {
            filenum = 7; 
        }
        
        break;
    case 551:
        filenum = 11;
        
        sys->ssd_flg |= 0x1000;
        break;
    default:
        filenum = 0;
        break;
    }
    
    if (num == 85) 
    {
        filenum = 2; 
    }
    
    return filenum; 
}

// 100% matching!
int PlayPageCheck()
{
    int page_end00;

    if (bhCkFlg(sys->ev_flg, 0x199) != 0) 
    {
        page_end00 = 0;
    }
    else if (bhCkFlg(sys->ev_flg, 0x2B) != 0)
    {
        page_end00 = 1;
    }
    else if (bhCkFlg(sys->ev_flg, 0x129) != 0) 
    {
        page_end00 = 2;
    }
    else if (bhCkFlg(sys->ev_flg, 0xE0) != 0) 
    {
        page_end00 = 4;
    }
    else if (bhCkFlg(sys->ev_flg, 0x96) != 0)
    {
        page_end00 = 6;
    } 
    else 
    {
        page_end00 = 7;
    }
    
    return page_end00;
}
