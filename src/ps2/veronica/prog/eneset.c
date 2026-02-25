#include "eneset.h"
#include "MdlPut.h"
#include "effect.h"
#include "face.h"
#include "hitchk.h"
#include "light.h"
#include "njplus.h"
#include "pwksub.h"
#include "weapon.h"
//#include "zonzon1.h"
#include "main.h"

typedef void (*JumpEnemy_proc)();

JumpEnemy_proc bhJumpEnemy[100]; // DATA
CPCL En00CapColTab[5]; // DATA

// 100% matching! 
void bhInitEnemy()
{
    npSetMemory((unsigned char*)ene, 180224, 0);
}

// 100% matching!
BH_PWORK* bhSetEnemy(EGG_WORK* etp, int unused) // second parameter is not present on the debugging symbols
{
    BH_PWORK* epp;
    int i;
    
    epp = ene;
    
    for (i = 0; ; )
    {
        if (!(epp->flg & 0x1)) 
        {
            npSetMemory((unsigned char*)epp, sizeof(BH_PWORK), 0);
            
            epp->flg = etp->flg;
            
            epp->id = etp->id;
            
            if (epp->id > 40) 
            {
                epp->mdflg |= 0x20;
                
                switch (epp->id) 
                {                      
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                    epp->clp_jno[0] = 0;
                    epp->clp_jno[1] = 3;
                    epp->clp_jno[2] = 5;
                    epp->clp_jno[3] = 8;
                    epp->clp_jno[4] = 12;
                    epp->clp_jno[5] = 15;
                    epp->clp_jno[6] = 19;
                    epp->clp_jno[7] = -1;
                    break;
                case 91:
                case 92:
                case 93:
                case 94:
                case 95:
                case 96:
                case 97:
                case 98:
                    epp->clp_jno[0] = 0;
                    epp->clp_jno[1] = 3;
                    epp->clp_jno[2] = 5;
                    epp->clp_jno[3] = 17;
                    epp->clp_jno[4] = 21;
                    epp->clp_jno[5] = 24;
                    epp->clp_jno[6] = 28;
                    epp->clp_jno[7] = -1;
                    break;
                }
                
                epp->flg |= 0x8000;
            }
            
            if (epp->id > 90) 
            {
                epp->mdflg |= 0x100;
            }
            
            epp->type = etp->type;
            
            epp->flr_no = etp->flr_no;
            
            epp->mdlver = etp->mdlver;
            
            epp->px = etp->px;
            epp->py = etp->py;
            epp->pz = etp->pz;
            
            epp->ax = 0;
            epp->ay = etp->ay;
            epp->az = 0;
            
            epp->aoz = 0;
            epp->aoy = 0;
            epp->aox = 0;
            
            *(int*)&epp->mode0 = 0;
            
            epp->ct3 = 0;
            epp->ct2 = 0;
            epp->ct1 = 0;
            epp->ct0 = 0;
            
            epp->lkwkp = NULL;
            
            epp->exp0 = NULL;
            epp->exp1 = NULL;
            epp->exp2 = NULL;
            
            epp->idx_ct = i;
            
            epp->sxb = 1.0f;
            epp->sx = 1.0f;
            
            epp->syb = 1.0f;
            epp->sy = 1.0f;
            
            epp->szb = 1.0f;
            epp->sz = 1.0f;
            
            epp->obj_a = NULL;
            epp->obj_b = NULL;
            
            epp->shp_ct = 0;
            
            epp->mtx = (float(*)[16])epp->mtxbuf;
            
            epp->frm_no = 0;
            epp->mtn_no = 0;
            epp->mdl_no = 0;
            
            epp->hokan_count = 0;
            epp->hokan_rate = 0;
            
            epp->frm_mode = 0;
            
            epp->mtn_no = 0;
            epp->mtn_add = 65536;
            epp->mtn_md = 0;
            epp->mtn_tp = NULL;
            
            epp->at_flg = 0;
            
            epp->clp_jno[0] = 1;
            epp->clp_jno[1] = -1;
            
            bhSetFloorNum(epp);
            
            bhCheckEneWorkNum();
            
            return epp;
        }
        
        i++;
        epp++;
        
        if (i >= 128) 
        {
            bhCheckEneWorkNum();
            
            return NULL;
        }
    }
}

// 100% matching!
void bhCheckEneWorkNum()
{
    BH_PWORK* epp;
    int i;

    sys->ewk_n = 0;
    
    epp = ene;

    for (i = 0; i < 128; i++, epp++)
    {
        if ((epp->flg & 0x1))
        {
            sys->ewk_n = i + 1;
        }
    }
}

// 100% matching!
void bhControlEnemy()
{
    BH_PWORK* ep;
    unsigned int i;
    
    plp->ofz = 0;
    plp->ofx = 0;
    
    if ((sys->sp_flg & 0x2)) 
    {
        ep = ene;
        
        sys->en_objn = 0;
        
        for (i = 0; i < sys->ewk_n; i++, ep++)
        {
            sys->enow = i;
            
            if ((!(ep->stflg & 0x41000000)) && (((!(ep->flg & 0x80)) || (!(((BH_PWORK*)ep->lkwkp)->stflg & 0x1000000))) && ((ep->flg & 0x1))))
            {
                ep->pxb = ep->px;
                ep->pyb = ep->py;
                ep->pzb = ep->pz;
                
                ep->axb = ep->ax;
                ep->ayb = ep->ay;
                ep->azb = ep->az;
                
                if (ep->id > 90) 
                {
                    bhControlMask(ep);
                }
                
                bhJumpEnemy[ep->id](ep);
                
                bhEne_InitDamage(ep);
                
                if ((ep->flg & 0x80000000)) 
                {
                    sys->en_obj[sys->en_objn++] = ep;
                }
            }
        }
    }
}

// 98.23% matching (matches on GC)
void bhEne00(BH_PWORK* ep)
{
    ATR_WORK* hp; 
    NJS_POINT3 pos; 
    int i;          
    POINT pnt;      

    switch (ep->mode0)
    {       
    case 0:
        ep->flg |= 0x8120;
        ep->flg &= ~0x6;
        
        ep->flg2 |= 0x1;
        
        ep->mdflg &= ~0x1;
        ep->mdflg |= 0x20;
        
        ep->ar = 4.0f;
        ep->ah = 15.0f;
        
        ep->aox = 0;
        ep->aoy = 0;
        ep->aoz = 0;
        
        ep->car = 4.0f;
        ep->cah = 15.0f;
        
        ep->hp = 0;
        
        ep->cpcl = En00CapColTab;
        
        if (!(ep->flg2 & 0x80000000)) 
        {
            ep->flg2 |= 0x80000000;
            
            ep->ct0 = sys->mwal_n++;
            
            hp = &sys->mwalp[ep->ct0];
            
            hp->flg = 0x81;
            
            hp->type = 3;
            
            hp->flr_no = ep->flr_no;
            
            hp->attr = 8;
            
            hp->px = ep->px;
            hp->py = rom->grand[hp->flr_no + 2];
            hp->pz = ep->pz;
            
            hp->w = 3.5f;
            hp->h = 15.0f;
            
            hp->d = 0;
            
            hp->prm2 = 0;
            hp->prm1 = 0;
            hp->prm0 = 0;
            hp->prm3 = sys->enow;
            
            pnt.px = 0;
            pnt.py = 0;
            pnt.pz = 0;
            
            pnt.ox = 0;
            pnt.oy = 0;
            pnt.oz = 0;
            
            bhSetEffect(17, &pnt, (unsigned char*)ep, 0);
        } 
        else 
        {
            hp = &sys->mwalp[ep->ct0];
            
            hp->flg = 0x81;
            
            hp->attr = 8;
        }
        
        ep->mode0 = 1;
        break;
    case 1:
        hp = &sys->mwalp[ep->ct0];
        
        if (((ep->flg & 0x4)) && (ep->wpnr_no != 2))
        {
            pos.x = ep->px;
            pos.y = 10.0f + ep->py;
            pos.z = ep->pz;
            
            bhSetExplosion(&pos);
            
            ep->flg |= 0x2;
            
            ep->mdflg |= 0x1;
            
            ep->flg &= ~0x78;
            
            hp->flg &= ~0x1;
            
            ep->mode0 = 2;
        }
        
        hp->px = ep->px;
        hp->py = ep->py;
        hp->pz = ep->pz;
        break;
    case 2:
        break;
    }
   
    if ((ep->flg & 0x4)) 
    {
        for (i = 0; i < ep->mlwP->obj_num; i++) 
        {
            ep->dam[i] = 0;
        }
        
        ep->flg &= ~0x4;
    }
    
    if ((ep->flg & 0x40)) 
    {
        bhCheckPlayer(ep);
    }
    
    if ((ep->flg & 0x8)) 
    {
        bhCheckEnemies(ep);
    }
    
    if ((ep->flg & 0x10)) 
    {
        bhCheckWall(ep);
    }
    
    bhCalcModel(ep);
    
    ep->watr.c1.x = ep->mlwP->owP->mtx[12];
    ep->watr.c1.y = ep->mlwP->owP->mtx[13];
    ep->watr.c1.z = ep->mlwP->owP->mtx[14];
    
    ep->watr.c2.x = ep->watr.c1.x;
    ep->watr.c2.y = 15.0f + ep->watr.c1.y;
    ep->watr.c2.z = ep->watr.c1.z;
    
    ep->watr.r = ep->car;
}

/*// 
// Start address: 0x175030
void bhEne56(BH_PWORK* ep)
{
	_anon32 pos;
	_anon0* op;
	// Line 746, Address: 0x175030, Func Offset: 0
	// Line 749, Address: 0x175040, Func Offset: 0x10
	// Line 750, Address: 0x175044, Func Offset: 0x14
	// Line 749, Address: 0x175048, Func Offset: 0x18
	// Line 750, Address: 0x175050, Func Offset: 0x20
	// Line 752, Address: 0x175078, Func Offset: 0x48
	// Line 753, Address: 0x17507c, Func Offset: 0x4c
	// Line 757, Address: 0x175080, Func Offset: 0x50
	// Line 761, Address: 0x175084, Func Offset: 0x54
	// Line 762, Address: 0x175088, Func Offset: 0x58
	// Line 752, Address: 0x17508c, Func Offset: 0x5c
	// Line 753, Address: 0x175094, Func Offset: 0x64
	// Line 754, Address: 0x1750a8, Func Offset: 0x78
	// Line 755, Address: 0x1750ac, Func Offset: 0x7c
	// Line 756, Address: 0x1750b0, Func Offset: 0x80
	// Line 757, Address: 0x1750b4, Func Offset: 0x84
	// Line 758, Address: 0x1750b8, Func Offset: 0x88
	// Line 759, Address: 0x1750bc, Func Offset: 0x8c
	// Line 760, Address: 0x1750c0, Func Offset: 0x90
	// Line 761, Address: 0x1750c4, Func Offset: 0x94
	// Line 762, Address: 0x1750d8, Func Offset: 0xa8
	// Line 763, Address: 0x1750f0, Func Offset: 0xc0
	// Line 765, Address: 0x1750f8, Func Offset: 0xc8
	// Line 763, Address: 0x1750fc, Func Offset: 0xcc
	// Line 765, Address: 0x175100, Func Offset: 0xd0
	// Line 764, Address: 0x175104, Func Offset: 0xd4
	// Line 763, Address: 0x175108, Func Offset: 0xd8
	// Line 764, Address: 0x175118, Func Offset: 0xe8
	// Line 765, Address: 0x175130, Func Offset: 0x100
	// Line 766, Address: 0x175144, Func Offset: 0x114
	// Line 767, Address: 0x17514c, Func Offset: 0x11c
	// Line 768, Address: 0x175158, Func Offset: 0x128
	// Line 769, Address: 0x17515c, Func Offset: 0x12c
	// Line 767, Address: 0x175160, Func Offset: 0x130
	// Line 768, Address: 0x175170, Func Offset: 0x140
	// Line 769, Address: 0x175188, Func Offset: 0x158
	// Line 772, Address: 0x1751a0, Func Offset: 0x170
	// Line 773, Address: 0x1751b0, Func Offset: 0x180
	// Line 774, Address: 0x1751d8, Func Offset: 0x1a8
	// Line 776, Address: 0x1751e4, Func Offset: 0x1b4
	// Line 777, Address: 0x175200, Func Offset: 0x1d0
	// Line 781, Address: 0x175208, Func Offset: 0x1d8
	// Line 784, Address: 0x17520c, Func Offset: 0x1dc
	// Line 777, Address: 0x175210, Func Offset: 0x1e0
	// Line 778, Address: 0x175240, Func Offset: 0x210
	// Line 779, Address: 0x17524c, Func Offset: 0x21c
	// Line 780, Address: 0x175250, Func Offset: 0x220
	// Line 781, Address: 0x175254, Func Offset: 0x224
	// Line 782, Address: 0x175258, Func Offset: 0x228
	// Line 783, Address: 0x17525c, Func Offset: 0x22c
	// Line 785, Address: 0x175260, Func Offset: 0x230
	// Line 787, Address: 0x175268, Func Offset: 0x238
	// Line 790, Address: 0x175270, Func Offset: 0x240
	// Line 793, Address: 0x175278, Func Offset: 0x248
	// Line 790, Address: 0x17527c, Func Offset: 0x24c
	// Line 791, Address: 0x17528c, Func Offset: 0x25c
	// Line 792, Address: 0x1752a4, Func Offset: 0x274
	// Line 793, Address: 0x1752bc, Func Offset: 0x28c
	// Line 794, Address: 0x1752cc, Func Offset: 0x29c
	// Line 795, Address: 0x1752d4, Func Offset: 0x2a4
	// Line 797, Address: 0x175310, Func Offset: 0x2e0
	// Line 798, Address: 0x175324, Func Offset: 0x2f4
	// Line 799, Address: 0x175328, Func Offset: 0x2f8
	// Line 801, Address: 0x175330, Func Offset: 0x300
	// Line 803, Address: 0x175334, Func Offset: 0x304
	// Line 805, Address: 0x17533c, Func Offset: 0x30c
	// Line 807, Address: 0x17535c, Func Offset: 0x32c
	// Line 809, Address: 0x175364, Func Offset: 0x334
	// Line 810, Address: 0x175368, Func Offset: 0x338
	// Line 809, Address: 0x175374, Func Offset: 0x344
	// Line 811, Address: 0x17537c, Func Offset: 0x34c
	// Line 812, Address: 0x175388, Func Offset: 0x358
	// Line 809, Address: 0x17538c, Func Offset: 0x35c
	// Line 812, Address: 0x175398, Func Offset: 0x368
	// Line 809, Address: 0x1753a8, Func Offset: 0x378
	// Line 810, Address: 0x1753b4, Func Offset: 0x384
	// Line 811, Address: 0x1753c0, Func Offset: 0x390
	// Line 812, Address: 0x1753c8, Func Offset: 0x398
	// Line 813, Address: 0x1753d8, Func Offset: 0x3a8
	// Line 814, Address: 0x1753ec, Func Offset: 0x3bc
	// Line 816, Address: 0x1753f4, Func Offset: 0x3c4
	// Line 817, Address: 0x1753f8, Func Offset: 0x3c8
	// Line 816, Address: 0x175404, Func Offset: 0x3d4
	// Line 818, Address: 0x17540c, Func Offset: 0x3dc
	// Line 819, Address: 0x175414, Func Offset: 0x3e4
	// Line 816, Address: 0x175420, Func Offset: 0x3f0
	// Line 819, Address: 0x17542c, Func Offset: 0x3fc
	// Line 816, Address: 0x175434, Func Offset: 0x404
	// Line 817, Address: 0x175440, Func Offset: 0x410
	// Line 818, Address: 0x17544c, Func Offset: 0x41c
	// Line 819, Address: 0x175454, Func Offset: 0x424
	// Line 820, Address: 0x175464, Func Offset: 0x434
	// Line 821, Address: 0x175478, Func Offset: 0x448
	// Line 823, Address: 0x175480, Func Offset: 0x450
	// Line 824, Address: 0x175484, Func Offset: 0x454
	// Line 823, Address: 0x175490, Func Offset: 0x460
	// Line 825, Address: 0x175498, Func Offset: 0x468
	// Line 826, Address: 0x1754a0, Func Offset: 0x470
	// Line 823, Address: 0x1754ac, Func Offset: 0x47c
	// Line 826, Address: 0x1754b8, Func Offset: 0x488
	// Line 823, Address: 0x1754c0, Func Offset: 0x490
	// Line 824, Address: 0x1754cc, Func Offset: 0x49c
	// Line 825, Address: 0x1754d8, Func Offset: 0x4a8
	// Line 826, Address: 0x1754e0, Func Offset: 0x4b0
	// Line 827, Address: 0x1754f0, Func Offset: 0x4c0
	// Line 828, Address: 0x175504, Func Offset: 0x4d4
	// Line 830, Address: 0x17550c, Func Offset: 0x4dc
	// Line 831, Address: 0x175510, Func Offset: 0x4e0
	// Line 830, Address: 0x17551c, Func Offset: 0x4ec
	// Line 832, Address: 0x175524, Func Offset: 0x4f4
	// Line 833, Address: 0x17552c, Func Offset: 0x4fc
	// Line 830, Address: 0x175538, Func Offset: 0x508
	// Line 833, Address: 0x175544, Func Offset: 0x514
	// Line 830, Address: 0x17554c, Func Offset: 0x51c
	// Line 831, Address: 0x175558, Func Offset: 0x528
	// Line 832, Address: 0x175564, Func Offset: 0x534
	// Line 833, Address: 0x17556c, Func Offset: 0x53c
	// Line 834, Address: 0x17557c, Func Offset: 0x54c
	// Line 835, Address: 0x175590, Func Offset: 0x560
	// Line 841, Address: 0x175598, Func Offset: 0x568
	// Line 842, Address: 0x1755b8, Func Offset: 0x588
	// Line 843, Address: 0x1755bc, Func Offset: 0x58c
	// Line 844, Address: 0x1755d8, Func Offset: 0x5a8
	// Line 845, Address: 0x175634, Func Offset: 0x604
	// Line 848, Address: 0x175638, Func Offset: 0x608
	// Line 850, Address: 0x175640, Func Offset: 0x610
	// Line 851, Address: 0x175658, Func Offset: 0x628
	// Line 850, Address: 0x175660, Func Offset: 0x630
	// Line 851, Address: 0x175668, Func Offset: 0x638
	// Line 850, Address: 0x17566c, Func Offset: 0x63c
	// Line 851, Address: 0x175678, Func Offset: 0x648
	// Line 852, Address: 0x175680, Func Offset: 0x650
	// Line 853, Address: 0x175690, Func Offset: 0x660
	// Line 854, Address: 0x175698, Func Offset: 0x668
	// Line 855, Address: 0x17569c, Func Offset: 0x66c
	// Line 856, Address: 0x1756a0, Func Offset: 0x670
	// Line 857, Address: 0x1756b0, Func Offset: 0x680
	// Line 858, Address: 0x1756c0, Func Offset: 0x690
	// Line 860, Address: 0x1756c4, Func Offset: 0x694
	// Line 861, Address: 0x175704, Func Offset: 0x6d4
	// Line 867, Address: 0x17570c, Func Offset: 0x6dc
	// Line 861, Address: 0x175714, Func Offset: 0x6e4
	// Line 862, Address: 0x17571c, Func Offset: 0x6ec
	// Line 863, Address: 0x17572c, Func Offset: 0x6fc
	// Line 864, Address: 0x17573c, Func Offset: 0x70c
	// Line 865, Address: 0x17574c, Func Offset: 0x71c
	// Line 866, Address: 0x175750, Func Offset: 0x720
	// Line 867, Address: 0x175754, Func Offset: 0x724
	// Line 870, Address: 0x175760, Func Offset: 0x730
	// Line 872, Address: 0x175768, Func Offset: 0x738
	// Line 873, Address: 0x175774, Func Offset: 0x744
	// Line 872, Address: 0x175778, Func Offset: 0x748
	// Line 873, Address: 0x17579c, Func Offset: 0x76c
	// Line 875, Address: 0x1757c4, Func Offset: 0x794
	// Line 876, Address: 0x1757cc, Func Offset: 0x79c
	// Line 875, Address: 0x1757d8, Func Offset: 0x7a8
	// Line 876, Address: 0x1757e0, Func Offset: 0x7b0
	// Line 877, Address: 0x17580c, Func Offset: 0x7dc
	// Line 878, Address: 0x175828, Func Offset: 0x7f8
	// Line 879, Address: 0x175830, Func Offset: 0x800
	// Line 880, Address: 0x175838, Func Offset: 0x808
	// Line 882, Address: 0x175848, Func Offset: 0x818
	// Line 884, Address: 0x175850, Func Offset: 0x820
	// Line 885, Address: 0x175868, Func Offset: 0x838
	// Line 886, Address: 0x175870, Func Offset: 0x840
	// Line 884, Address: 0x175878, Func Offset: 0x848
	// Line 885, Address: 0x17588c, Func Offset: 0x85c
	// Line 886, Address: 0x175894, Func Offset: 0x864
	// Line 885, Address: 0x17589c, Func Offset: 0x86c
	// Line 886, Address: 0x1758a0, Func Offset: 0x870
	// Line 887, Address: 0x1758b0, Func Offset: 0x880
	// Line 888, Address: 0x1758b8, Func Offset: 0x888
	// Line 897, Address: 0x1758bc, Func Offset: 0x88c
	// Line 899, Address: 0x1758c4, Func Offset: 0x894
	// Line 900, Address: 0x1758cc, Func Offset: 0x89c
	// Line 901, Address: 0x1758dc, Func Offset: 0x8ac
	// Line 932, Address: 0x1758e4, Func Offset: 0x8b4
	// Func End, Address: 0x1758f8, Func Offset: 0x8c8
}*/

// 100% matching!
void bhDrawEnemy() 
{
    BH_PWORK* ep;
    int i;
    unsigned int argb;
    
    ep = ene;
    
    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if ((((ep->flg & 0x1)) && (!(ep->flg & 0x80000000))) && (!(ep->stflg & 0x41000000)) && (((sys->st_flg & 0x20)) || (!(ep->mdflg & 0x200))) && ((!(ep->flg & 0x80)) || (!(((BH_PWORK*)ep->lkwkp)->stflg & 0x1000000))))
        {
            if ((ep->mdflg & 0x4)) 
            {
                bhCalcModel(ep);
            }
            
            if ((((ep->mdflg & 0x20)) || (bhCheckClipModel(ep) == 0)) && (!(ep->mdflg & 0x1)) && (ep->mlwP->objP != NULL)) 
            {
                if ((sys->st_flg & 0x20))
                {
                    bhPutModel(ep);
                }
                else
                {
                    if ((sys->gm_flg & 0x1000040)) 
                    {
                        if ((ep->mdflg & 0x400))
                        {
                            argb = npGetMatColor(ep->mlwP->objP, ep->mlwP->obj_num) & 0xFF;
                            
                            if (argb >= 0)
                            {
                                bhSetEasyDirLight(argb / 255.0f);
                            }
                            else
                            {
                                bhSetEasyDirLight((2.0f * ((argb >> 1) | (argb & 0x1))) / 255.0f);
                            }
                        }
                        else 
                        {
                            bhSetEasyDirLight(0.6f);
                        }
                    }
                    
                    if ((ep->mdflg & 0x2))
                    {
                        npPushMdlstr2(ep->obj_a, ep->mlwP->obj_num);
                        
                        npCalcMorphing(ep->obj_a, ep->obj_b, ep->shp_ct, ep->mlwP->obj_num);
                        
                        ep->mlwP->objP = ep->obj_a;
                        
                        bhPutModel(ep);
                        
                        npPopMdlstr2(ep->obj_a, ep->mlwP->obj_num);
                    } 
                    else 
                    {
                        bhPutModel(ep);
                    }
                }
            }
        }
    }
}

// 100% matching!
void bhDrawEneObject()
{
    BH_PWORK* ep;
    int i;
	
    for (i = 0; i < sys->en_objn; i++) 
    {
        ep = sys->en_obj[i];
        
        if (((ep->flg & 0x1)) && (!(ep->stflg & 0x41000000)))
        {
            if ((ep->mdflg & 0x4))
            {
                bhCalcModel(ep);
            }
            
            if ((((ep->mdflg & 0x20)) || (bhCheckClipModel(ep) == 0)) && (ep->mlwP->objP != NULL) && (!(ep->mdflg & 0x1)))
            {
                if ((ep->mdflg & 0x2)) 
                {
                    npPushMdlstr2(ep->obj_a, ep->mlwP->obj_num);
                    
                    npCalcMorphing(ep->obj_a, ep->obj_b, ep->shp_ct, ep->mlwP->obj_num);
                    
                    ep->mlwP->objP = ep->obj_a;
                    
                    bhPutModel(ep);
                    
                    npPopMdlstr2(ep->obj_a, ep->mlwP->obj_num);
                }
                else 
                {
                    bhPutModel(ep);
                }
            }
        }
    }
}

// 100% matching!
void* bhEne_CallocWork(int size)
{
    unsigned char* ret_addr; 
    unsigned char* addr;     

    if ((&sys->memp[size] - sys->mempb) > 0xC40000)
    {
        return NULL;
    }
    
    sys->memp = (unsigned char*)(((unsigned int)sys->memp + 63) & ~0x3F);
    
    ret_addr = sys->memp;

    addr = ret_addr; 
    
    sys->memp = &ret_addr[size];
    
    while (size-- != 0) 
    {
        *addr++ = 0;
    } 
    
    return ret_addr;
}

// 100% matching!
void bhEne_SetCallFunc(void(*func)(BH_PWORK*), unsigned int no)
{
    bhJumpEnemy[no] = func;
}
