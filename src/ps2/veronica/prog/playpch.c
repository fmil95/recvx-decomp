#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/playpch.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/weapon.h"

// 100% matching! 
void PlyPchInit(BH_PWORK* ewP)
{
    ewP->exp2 = bhGetFreeMemory(1712, 32);
}

// 
// Start address: 0x14a5e0
void PlyPchMain(BH_PWORK* ewP)
{
	int* dstP;
	int* atP;
	int dir;
	//npobj* objP;
	//_anon11* mlwP;
	//_anon3* ppP;
	char RouteArmLn_0[5];
	char RouteArmRn_0[5];
	// Line 101, Address: 0x14a5e0, Func Offset: 0
	// Line 111, Address: 0x14a5f4, Func Offset: 0x14
	// Line 108, Address: 0x14a600, Func Offset: 0x20
	// Line 111, Address: 0x14a608, Func Offset: 0x28
	// Line 112, Address: 0x14a638, Func Offset: 0x58
	// Line 115, Address: 0x14a654, Func Offset: 0x74
	// Line 116, Address: 0x14a664, Func Offset: 0x84
	// Line 118, Address: 0x14a674, Func Offset: 0x94
	// Line 126, Address: 0x14a678, Func Offset: 0x98
	// Line 120, Address: 0x14a680, Func Offset: 0xa0
	// Line 121, Address: 0x14a698, Func Offset: 0xb8
	// Line 123, Address: 0x14a6b0, Func Offset: 0xd0
	// Line 126, Address: 0x14a6bc, Func Offset: 0xdc
	// Line 127, Address: 0x14a6d0, Func Offset: 0xf0
	// Line 128, Address: 0x14a6e0, Func Offset: 0x100
	// Line 129, Address: 0x14a6f0, Func Offset: 0x110
	// Line 130, Address: 0x14a708, Func Offset: 0x128
	// Line 133, Address: 0x14a710, Func Offset: 0x130
	// Line 134, Address: 0x14a718, Func Offset: 0x138
	// Line 133, Address: 0x14a71c, Func Offset: 0x13c
	// Line 135, Address: 0x14a724, Func Offset: 0x144
	// Line 136, Address: 0x14a72c, Func Offset: 0x14c
	// Line 137, Address: 0x14a738, Func Offset: 0x158
	// Line 138, Address: 0x14a748, Func Offset: 0x168
	// Line 140, Address: 0x14a750, Func Offset: 0x170
	// Line 141, Address: 0x14a754, Func Offset: 0x174
	// Line 143, Address: 0x14a758, Func Offset: 0x178
	// Line 140, Address: 0x14a760, Func Offset: 0x180
	// Line 141, Address: 0x14a768, Func Offset: 0x188
	// Line 143, Address: 0x14a76c, Func Offset: 0x18c
	// Line 148, Address: 0x14a780, Func Offset: 0x1a0
	// Line 152, Address: 0x14a784, Func Offset: 0x1a4
	// Line 148, Address: 0x14a790, Func Offset: 0x1b0
	// Line 149, Address: 0x14a79c, Func Offset: 0x1bc
	// Line 152, Address: 0x14a7a8, Func Offset: 0x1c8
	// Line 153, Address: 0x14a7b0, Func Offset: 0x1d0
	// Line 155, Address: 0x14a7c0, Func Offset: 0x1e0
	// Line 156, Address: 0x14a7d0, Func Offset: 0x1f0
	// Line 159, Address: 0x14a7e0, Func Offset: 0x200
	// Line 163, Address: 0x14a7ec, Func Offset: 0x20c
	// Line 166, Address: 0x14a81c, Func Offset: 0x23c
	// Line 168, Address: 0x14a850, Func Offset: 0x270
	// Line 172, Address: 0x14a85c, Func Offset: 0x27c
	// Line 173, Address: 0x14a874, Func Offset: 0x294
	// Line 179, Address: 0x14a88c, Func Offset: 0x2ac
	// Line 180, Address: 0x14a8b8, Func Offset: 0x2d8
	// Line 181, Address: 0x14a8e4, Func Offset: 0x304
	// Line 183, Address: 0x14a908, Func Offset: 0x328
	// Line 185, Address: 0x14a914, Func Offset: 0x334
	// Line 192, Address: 0x14a920, Func Offset: 0x340
	// Line 190, Address: 0x14a924, Func Offset: 0x344
	// Line 192, Address: 0x14a928, Func Offset: 0x348
	// Line 193, Address: 0x14a92c, Func Offset: 0x34c
	// Line 185, Address: 0x14a930, Func Offset: 0x350
	// Line 193, Address: 0x14a938, Func Offset: 0x358
	// Line 192, Address: 0x14a93c, Func Offset: 0x35c
	// Line 185, Address: 0x14a940, Func Offset: 0x360
	// Line 192, Address: 0x14a94c, Func Offset: 0x36c
	// Line 193, Address: 0x14a950, Func Offset: 0x370
	// Line 194, Address: 0x14a958, Func Offset: 0x378
	// Line 198, Address: 0x14a960, Func Offset: 0x380
	// Line 199, Address: 0x14a964, Func Offset: 0x384
	// Line 194, Address: 0x14a96c, Func Offset: 0x38c
	// Line 195, Address: 0x14a984, Func Offset: 0x3a4
	// Line 196, Address: 0x14a9a0, Func Offset: 0x3c0
	// Line 198, Address: 0x14a9a8, Func Offset: 0x3c8
	// Line 199, Address: 0x14a9b4, Func Offset: 0x3d4
	// Line 200, Address: 0x14a9bc, Func Offset: 0x3dc
	// Line 201, Address: 0x14a9dc, Func Offset: 0x3fc
	// Line 202, Address: 0x14a9f8, Func Offset: 0x418
	// Line 206, Address: 0x14a9fc, Func Offset: 0x41c
	// Line 207, Address: 0x14aa04, Func Offset: 0x424
	// Line 208, Address: 0x14aa0c, Func Offset: 0x42c
	// Line 207, Address: 0x14aa10, Func Offset: 0x430
	// Line 208, Address: 0x14aa20, Func Offset: 0x440
	// Line 209, Address: 0x14aa28, Func Offset: 0x448
	// Line 208, Address: 0x14aa2c, Func Offset: 0x44c
	// Line 209, Address: 0x14aa3c, Func Offset: 0x45c
	// Line 210, Address: 0x14aa44, Func Offset: 0x464
	// Line 209, Address: 0x14aa48, Func Offset: 0x468
	// Line 210, Address: 0x14aa58, Func Offset: 0x478
	// Line 212, Address: 0x14aa70, Func Offset: 0x490
	// Line 213, Address: 0x14aa80, Func Offset: 0x4a0
	// Line 218, Address: 0x14aa84, Func Offset: 0x4a4
	// Func End, Address: 0x14aa9c, Func Offset: 0x4bc
	scePrintf("PlyPchMain - UNIMPLEMENTED!\n");
}

// 100% matching!
static void MixSetToJointRot(NJS_CNK_OBJECT* basP, char* rutP, NJS_CNK_OBJECT* objP, int yaw)
{
    NJS_MATRIX* mtx0P, *mtx1P;    
    NJS_CNK_OBJECT* tmpP; 
    
    mtx0P = &lcmat[0];
    mtx1P = &lcmat[1];

    njUnitMatrix(mtx0P);
    
    while (rutP[1] != -1) 
    {
        tmpP = &basP[rutP[0]];
        
        rutP++;
        
        njRotateXYZ(mtx0P, tmpP->ang[0], tmpP->ang[1], tmpP->ang[2]);
    }
    
    njSetMatrix(mtx1P, mtx0P);
    
    njRotateXYZ(mtx1P, objP->ang[0], objP->ang[1], objP->ang[2]);
    njInvertMatrix(mtx0P);
    
    njRotateY(mtx0P, yaw);
    njMultiMatrix(mtx0P, mtx1P); 
    
    basP = &basP[rutP[0]];
    
    basP->ang[0] = (int)(10430.381f * atan2f(mtx0P[0][6], mtx0P[0][10]));
    basP->ang[1] = (int)(10430.381f * asinf(-mtx0P[0][2]));
    basP->ang[2] = (int)(10430.381f * atan2f(mtx0P[0][1], mtx0P[0][0]));
}

// 100% matching!
static void GetOneObjectMotion(BH_PWORK* ewP, int obj_no, int* ang) 
{
    int flp;             
    char* rutP;          
    NJS_MKEY_A_MOD* mkaP; 
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

    if ((ewP->mtn_md & 0x2))
    {
        rutP = (char*)ewP->mtn_tp;
        
        flp = -1;
    }
    else
    {
        rutP = NormalTbl;
        
        flp = 1;
    }
    
    if (ewP->mnwP[ewP->mtn_no].md2P[rutP[obj_no]].p[1] != NULL)
    { 
        mkaP =  ewP->mnwP[ewP->mtn_no].md2P[rutP[obj_no]].p[1]; 
        mkaP += ewP->frm_no / 65536;
        
        ang[0] = mkaP->key[0];
        ang[1] = (mkaP->key[1] * flp); 
        ang[2] = (mkaP->key[2] * flp);
    } 
    else 
    {
        ang[0] = ang[1] = ang[2] = 0;
    }
}

// 100% matching!
static void SetOneObjectMotion(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, int* ang) 
{
    int* srcP;  
    float rate;
    short dlt;   
    int sum1;    
    static int tmpS[3], tmpD[3]; 
    
    if (ewP->hokan_count != 0) 
    {
        srcP = objP->ang;
        
        dlt = ang[0] - srcP[0];
        
        if (dlt < 0)
        {
            sum1 = -(dlt + (short)(dlt + 32768));
        } 
        else 
        {
            sum1 =   dlt + (short)(dlt + 32768);
        }
        
        dlt = ang[1] - srcP[1];
        
        if (dlt < 0)
        {
            sum1 -= dlt;
        } 
        else 
        {
            sum1 += dlt;
        }
        
        dlt = ang[1] - (32768 - srcP[1]);
        
        if (dlt < 0)
        {
            sum1 += dlt;
        }
        else 
        {
            sum1 -= dlt;
        }
        
        dlt = ang[2] - srcP[2];
        
        if (dlt < 0) 
        {
            sum1 -= dlt + (short)(dlt + 32768);
        } 
        else 
        {
            sum1 += dlt + (short)(dlt + 32768);
        }
        
        if (sum1 > 0) 
        {
            int* srcP;
            
            srcP = objP->ang;
            
            *srcP = 32768 + *srcP++;
            *srcP = 32768 - *srcP;
            *srcP = 32768 + *++srcP;
        }
        
        AngZyxToYzx(objP->ang, tmpS);
        AngZyxToYzx(ang,       tmpD);
        
        rate = 0.000015258789f * (65536 - ewP->hokan_rate);
        
        tmpS[0] += (int)(rate * (short)(tmpD[0] - tmpS[0]));
        tmpS[1] += (int)(rate * (short)(tmpD[1] - tmpS[1]));
        tmpS[2] += (int)(rate * (short)(tmpD[2] - tmpS[2]));
        
        AngYzxToZyx(tmpS, objP->ang);
    }
    else 
    {
        objP->ang[0] = ang[0];
        objP->ang[1] = ang[1];
        objP->ang[2] = ang[2];
    }
}

// 100% matching!
static search* bhSearchEnemy(BH_PWORK* pwP, int rng, float hgt)
{
    search* hedP, *lstP, *scnP, *prvP;    
    NJS_VECTOR vct0, vct1;
    BH_PWORK* ewP;  
    float p_cs;    
    float dst;       
    int i;          
    NJS_CAPSULE cap; 
    PP_WORK* ppP; // not from DWARF

    ppP = (PP_WORK*)pwP->exp2;
    
    ppP->sch_hed.nextP = NULL;
    ppP->sch_hed.dst   = 0;
    
    lstP = ppP->SchLst;
    hedP = &ppP->sch_hed;
    
    ppP->sch_hed.dir = 0;
    
    p_cs = njCos(rng); 
    
    njSinCos((pwP->ay + 32768), &vct0.x, &vct0.z);
    
    ewP = ene;
    
    vct0.y = 0;
    
    for (i = 0; i < sys->ewk_n; i++, ewP++)
    {
        if (((((ewP->flg & 0x1)) && ((ewP->flg & 0x20))) && ((!(ewP->flg2 & 0x10)) && (!(ewP->flg & 0x2))) && (!(ewP->stflg & 0x41000000))) && ((!(ewP->flg & 0x80)) || (!(((O_WRK*)ewP->lkwkp)->stflg & 0x1000000)))) 
        {
            vct1.x = 0.5f * (ewP->watr.c1.x + ewP->watr.c2.x);
            vct1.y = 0.5f * (ewP->watr.c1.y + ewP->watr.c2.y);
            vct1.z = 0.5f * (ewP->watr.c1.z + ewP->watr.c2.z);
            
            njSubVector(&vct1, (NJS_VECTOR*)&pwP->px);
            
            dst = njScalor(&vct1);
            
            if ((p_cs * dst) <= njInnerProduct(&vct0, &vct1)) 
            {
                cap.c1.x = cap.c2.x = pwP->px;
                cap.c1.y = cap.c2.y = pwP->py;
                cap.c1.z = cap.c2.z = pwP->pz;
                
                cap.c1.y += hgt;
                
                njAddVector(&cap.c2, &vct1);
                
                cap.r = 0.1f;
                
                if (bhCheckC2WallN(&cap, 0x40000400) == 0)  
                {
                    lstP->dir = (int)(10430.381f * atan2f(vct1.x, vct1.z)) + 32768;
                    lstP->dst = dst;                    
                    lstP->ewP = ewP;
                    lstP->idx = i;
                    
                    prvP = hedP; 
                    
                    for (scnP = hedP->nextP; scnP != NULL; scnP = scnP->nextP) 
                    {
                        if (scnP->dst >= dst) 
                        {
                            break;
                        }
                        
                        prvP = scnP;
                    }
                    
                    lstP->nextP = prvP->nextP;
                    prvP->nextP = lstP++;
                }
            }
        }
    }
    
    return hedP->nextP; 
}

// 
// Start address: 0x14b260
static int SetLockOnDirection(int range, int count, int mode, int special)
{
	//_search* tgtP;
	//_search* lstP;
	//_search* topP;
	//_anon3* ppP;
	// Line 495, Address: 0x14b260, Func Offset: 0
	// Line 496, Address: 0x14b274, Func Offset: 0x14
	// Line 501, Address: 0x14b280, Func Offset: 0x20
	// Line 502, Address: 0x14b290, Func Offset: 0x30
	// Line 504, Address: 0x14b294, Func Offset: 0x34
	// Line 506, Address: 0x14b2c8, Func Offset: 0x68
	// Line 509, Address: 0x14b2d0, Func Offset: 0x70
	// Line 538, Address: 0x14b2d8, Func Offset: 0x78
	// Line 535, Address: 0x14b2dc, Func Offset: 0x7c
	// Line 538, Address: 0x14b2e0, Func Offset: 0x80
	// Line 539, Address: 0x14b2e4, Func Offset: 0x84
	// Line 541, Address: 0x14b2e8, Func Offset: 0x88
	// Line 543, Address: 0x14b2fc, Func Offset: 0x9c
	// Line 546, Address: 0x14b30c, Func Offset: 0xac
	// Line 550, Address: 0x14b31c, Func Offset: 0xbc
	// Line 555, Address: 0x14b324, Func Offset: 0xc4
	// Line 557, Address: 0x14b338, Func Offset: 0xd8
	// Line 559, Address: 0x14b350, Func Offset: 0xf0
	// Line 560, Address: 0x14b358, Func Offset: 0xf8
	// Line 561, Address: 0x14b35c, Func Offset: 0xfc
	// Line 562, Address: 0x14b36c, Func Offset: 0x10c
	// Line 563, Address: 0x14b37c, Func Offset: 0x11c
	// Line 565, Address: 0x14b384, Func Offset: 0x124
	// Line 568, Address: 0x14b398, Func Offset: 0x138
	// Line 569, Address: 0x14b3a0, Func Offset: 0x140
	// Line 570, Address: 0x14b3b4, Func Offset: 0x154
	// Line 571, Address: 0x14b3c8, Func Offset: 0x168
	// Line 572, Address: 0x14b3d0, Func Offset: 0x170
	// Line 573, Address: 0x14b3e4, Func Offset: 0x184
	// Line 575, Address: 0x14b3fc, Func Offset: 0x19c
	// Line 578, Address: 0x14b404, Func Offset: 0x1a4
	// Line 580, Address: 0x14b40c, Func Offset: 0x1ac
	// Line 582, Address: 0x14b418, Func Offset: 0x1b8
	// Line 583, Address: 0x14b420, Func Offset: 0x1c0
	// Line 586, Address: 0x14b428, Func Offset: 0x1c8
	// Line 589, Address: 0x14b430, Func Offset: 0x1d0
	// Line 593, Address: 0x14b448, Func Offset: 0x1e8
	// Line 597, Address: 0x14b45c, Func Offset: 0x1fc
	// Func End, Address: 0x14b474, Func Offset: 0x214
	scePrintf("SetLockOnDirection - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhCPM2_act_suw_pch()
{
    search* lstP;

    switch (plp->mode3)
    {
    case 0:
        if (SetLockOnDirection(32768, 8, 0, 0) != 0) 
        {
            plp->flg |= 0x100000;
            
            ((EXP_WORK*)plp->exp0)->yrct = 8;
        }
        
        plp->flg    &= ~0xC0000;
        plp->at_flg &= ~0x10;
        
        plp->mtn_no = PlMtnWpn[0];
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 2.0f;
        
        plp->frm_no = 0;
        
        if (!bhCheckBullet()) 
        {
            sys->gm_flg |= 0x40000;
        }
        
        plp->mode3++;
    case 1:
        if (plp->hokan_count == 0) 
        {
            plp->flg |= 0xC0000;
            
            if ((WpnTab[plp->wpnr_no].flg & 0x4000000)) 
            {
                plp->flg &= ~0x80000;
            }
        }
        else 
        {
            plp->flg |= 0x200000;
        }
        
        if (((unsigned int)plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 4)) 
        {
            plp->at_flg &= ~0x1;
        }
        
        if ((plp->mnwP[plp->mtn_no].frm_num - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->mtn_add = 0;
        
            plp->mode2 = 65;
            plp->mode3 = 0;
            
            plp->at_flg = 2;
            
            plp->hokan_count = 8;
            
            plp->wax  = 0;
            plp->waxp = 0;
            return;
        } 
        else 
        {
            if (!(WpnTab[plp->wpnr_no].flg & 0x1)) 
            {
                if (((sys->pad_on & 0x20)) && (!(plp->at_flg & 0x1))) 
                {
                    plp->mode2 = 66;
                    plp->mode3 = 0;
                    
                    plp->at_flg = 4;
                    
                    plp->hokan_count = 8;
                    
                    plp->wax  = 0;
                    plp->waxp = 8192;
                    return;
                }
                
                if (((sys->pad_on & 0x40)) && (!(plp->at_flg & 0x1))) 
                {
                    plp->mode2 = 67;
                    plp->mode3 = 0;
                    
                    plp->at_flg = 0x8;
                    
                    plp->hokan_count = 8;
                    
                    plp->wax  = 0;
                    plp->waxp = -8192;
                    return;
                }
            }
        }
    }
    
    if ((sys->pad_on & 0x8))
    {
        plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
    }
    
    if ((sys->pad_on & 0x4)) 
    {
        plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
    }
}

// 100% matching!
void bhCPM2_act_wsc_pch()
{

}

// 100% matching!
void bhCPM2_act_atk_pch()
{
    PP_WORK* ppP;   
    const WPN_TAB* wt;   
    EF_WORK* wet;  
    search* lstP; // needs use   
  
    ppP = (PP_WORK*)plp->exp2;
    
    wt  = &WpnTab[plp->wpnr_no];
    wet = WpnEffTab[plp->wpnr_no]; 

    if ((!(wt->flg & 0x40)) || (((wt->flg & 0x200)) && (bhCkFlg(sys->ev_flg, 74) != 0))) 
    {
        switch (plp->mode3)
        {
        case 0:
        {
            GA_WORK* gaP;   
            
            plp->flg |= 0xC0000;
            
            if ((wt->flg & 0x8000000)) 
            {
                plp->flg &= ~0x80000;
            } 
            
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->mtn_no = PlMtnWpn[4];
                break;
            case 4:
                plp->mtn_no = PlMtnWpn[4] + 5;
                break;
            case 8:
                plp->mtn_no = PlMtnWpn[4] + 10;
                break;
            }
            
            plp->hokan_rate = 65536.0f * wt->hrate; 
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3++; 

            ppP->gun_delay = 2;

            if ((wt->flg & 0x2))
            {
                sys->obwp->flg |= 0x80000;
                
                sys->obwp->mode0 = 0;
            }

            gaP = CheckGunHit(wt, 9, ((PP_WORK*)plp->exp2)->arm_dr + plp->ay);
            
            bhCountBullet(); 
            
            if (wt->seno0 != 0) 
            {
                CallPlayerWeaponSeEx((NJS_POINT3*)&gaP->px, (unsigned int)wt->seno0, 0);
                
                if (!(wt->flg & 0x100))
                { 
                    plp->stflg |= 0x100;
                }
            }
        }
        case 1:
            if (((plp->frm_no / 65536) == (wt->ef_yct - 2)) && (plp->wpnr_no == 11))
            {
                CallPlayerWeaponSeEx((NJS_POINT3*)&plp->mlwP->owP[9].mtx[12], wt->seno1, 0);
            } 

            if (((plp->frm_no / 65536) == wt->ef_yct) && (wet[3].flg != 0))  
            {
                bhSetYakkyou(plp, plp->wpnr_no, 9, 0, ppP->arm_dr + plp->ay);
            } 
            
            if (((((plp->at_flg & 0x10)) && (!(plp->at_flg & 0x40))) && (((sys->pad_on & 0x100)) && ((sys->pad_on & 0x10)))) || ((plp->mnwP[plp->mtn_no].frm_num - 1) <= (plp->frm_no / 65536)))
            { 
                if ((wt->flg & 0x400))
                {
                    plp->mode2 = 70;
                    plp->mode3 = 0;
                    return;
                }
                
                switch (plp->at_flg & 0xE)
                {
                case 2:
                    plp->mode2 = 65;
                    break;
                case 4:
                    plp->mode2 = 66;
                    break;
                case 8:
                    plp->mode2 = 67;
                    break;
                }
                
                plp->hokan_count = 1;
                
                switch (((wt->flg & 0x1)) ? sys->pad_on & 0x10 : sys->pad_on & 0x70)
                {
                case 0x10:
                    if (!(plp->at_flg & 0x2)) 
                    {
                        plp->hokan_count = 12;
                    }
                    
                    break;
                case 0x30:
                    if (!(plp->at_flg & 0x4)) 
                    {
                        plp->hokan_count = 12;
                    }
                    
                    break;
                case 0x50:
                    if (!(plp->at_flg & 0x8)) 
                    {
                        plp->hokan_count = 12;
                    }

                    break;
                }
                
                plp->mode3 = 0;
                return;
            }
            
            if ((plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - wt->at_cct)) 
            {
                plp->at_flg |= 0x10;
            }
            
            if (!(sys->pad_on & 0x100)) 
            {
                plp->at_flg &= ~0x40;
            }
        default:
            plp->wax += (plp->waxp - plp->wax) / 4;
            
            if ((sys->pad_on & 0x8)) 
            {
                plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
            }
            
            if ((sys->pad_on & 0x4)) 
            {
                plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
            }
        }
    } 
    else 
    {
        if ((plp->ct0 >= wt->fend_ct) && (plp->mode3 == 2)) 
        {
            plp->mode3 = 1;
            
            plp->ct0 = 0;
            plp->ct1++;
        } 
        else 
        {
            plp->ct0++;
        }
        
        switch (plp->mode3) 
        {
        case 0:
            plp->flg |= 0xC0000;
            
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->mtn_no = PlMtnWpn[4];
                
                if ((((PP_WORK*)plp->exp2)->mode & 0x4)) 
                { 
                    plp->mtn_no += 17;
                } 
                
                break;
            case 4:
                plp->mtn_no = PlMtnWpn[4] + 5;
                break;
            case 8:
                plp->mtn_no = PlMtnWpn[4] + 10;
                break;
            }
            
            plp->hokan_rate = 65536.0f * wt->hrate;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->ct0 = plp->ct1 = 0;
            
            plp->mode3 = 1;
        case 1:
        {
            GA_WORK* gaP; 
                
            bhSetGunFire(plp, plp->wpnr_no, 9, 0, ppP->arm_dr + plp->ay);

            ppP->gun_delay = 2; 
            
            if ((wt->flg & 0x2)) 
            {
                sys->obwp->flg |= 0x80000;
                
                sys->obwp->mode0 = 0;
            }

            gaP = CheckGunHit(wt, 9, ((PP_WORK*)plp->exp2)->arm_dr + plp->ay);
            
            if (bhCountBullet() == 0)
            {
                sys->gm_flg |= 0x40000;
                
                plp->mode3 = 3;

                plp->at_flg &= ~0x10;
                
                if (!(wt->flg & 0x200)) 
                {
                    switch (plp->at_flg & 0xE)
                    {
                    case 2:
                        plp->mtn_no = 102;
                        break;
                    case 4:
                        plp->mtn_no = 107;
                        break;
                    case 8:
                        plp->mtn_no = 112;
                        break;
                    }
                }
                
                break;
            } 
            
            if (wt->seno0 != 0)
            {
                CallPlayerWeaponSeEx((NJS_POINT3*)&gaP->px, (unsigned short)wt->seno0, 0);
                
                if (!(wt->flg & 0x100)) 
                {
                    plp->stflg |= 0x100;
                }
            }
            
            plp->mode3 = 2;
        }
        case 2:
            if ((plp->ct0 == wt->ef_yct) && (wet[3].flg != 0)) 
            {
                bhSetYakkyou(plp, plp->wpnr_no, 9, 0, ppP->arm_dr + plp->ay);
            } 
            
            if (((!(sys->pad_on & 0x100)) || (!(sys->pad_on & 0x10))) || (((wt->flg & 0x200)) && (plp->ct1 > 1))) 
            {
                plp->mode3 = 3;
                
                plp->ct1 = 0;
                
                if ((wt->flg & 0x200)) 
                {
                    plp->at_flg |= 0x40;
                }
                else 
                {
                    plp->at_flg &= ~0x40;
                    
                    switch (plp->at_flg & 0xE)
                    {
                    case 2:
                        plp->mtn_no = 102;
                        
                        if ((((PP_WORK*)plp->exp2)->mode & 0x4)) 
                        {
                            plp->mtn_no += 17;
                        }
                        
                        break;
                    case 4:
                        plp->mtn_no = 107;
                        break;
                    case 8:
                        plp->mtn_no = 112;
                        break;
                    }
                }
            }

            break;
        case 3:
            if ((plp->ct0 == wt->ef_yct) && (wet[3].flg != 0)) 
            {
                bhSetYakkyou(plp, plp->wpnr_no, 9, 0, ppP->arm_dr + plp->ay);
            }
            
            if (!(sys->pad_on & 0x100)) 
            {
                plp->at_flg &= ~0x40;
            }
            
            plp->at_flg |= 0x10;
            
            if ((plp->flg & 0x400000)) 
            {
                switch (plp->at_flg & 0xE)
                {
                case 2:
                    plp->mode2 = 65;
                    
                    plp->mtn_no = PlMtnWpn[1];
                    
                    plp->waxp = 0;
                    
                    ppP = (PP_WORK*)plp->exp2;
                    
                    if ((ppP->mode & 0x4)) 
                    {
                        plp->mtn_no += 13;
                    }
                    
                    break;
                case 4:
                    plp->mode2 = 66;
                    
                    plp->mtn_no = PlMtnWpn[2];
                    
                    plp->waxp = 8192;
                    break;
                case 8:
                    plp->mode2 = 67;
                    
                    plp->mtn_no = PlMtnWpn[3];
                    
                    plp->waxp = -8192;
                    break;
                }
                
                plp->mode3 = 0;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 0;
                return;
            }
            
            break;
        case 4:
            plp->hokan_count = 12;
            plp->hokan_rate  = 45875;
            
            switch (plp->at_flg & 0xE)
            {
            case 2:
                plp->mode2 = 65;

                plp->mtn_no = PlMtnWpn[1];
                
                plp->waxp = 0;
                
                ppP = (PP_WORK*)plp->exp2;
                
                if ((ppP->mode & 0x4)) 
                {
                    plp->mtn_no += 13;
                }
                
                break;
            case 4:
                plp->mode2 = 66;
                
                plp->mtn_no = PlMtnWpn[2];
                
                plp->waxp = 8192;
                break;
            case 8:
                plp->mode2 = 67;
                
                plp->mtn_no = PlMtnWpn[3];
                
                plp->waxp = -8192;
                break;
            }
            
            plp->mode3 = 0;
            return;
        }
        
        if ((plp->mode3 >= 3) && (!(sys->gm_flg & 0x40000)) && (((sys->pad_on & 0x100)) && ((sys->pad_on & 0x10))) && (((plp->at_flg & 0x10)) && (!(plp->at_flg & 0x40))))
        {
            plp->mode3 = 0;
            
            plp->hokan_count = 0;
        }
        
        plp->wax += (plp->waxp - plp->wax) / 4;
        
        switch (sys->pad_on & 0x70)
        {
        case 0x10:
            if (!(plp->at_flg & 0x2)) 
            {
                plp->at_flg &= ~0xE;
                plp->at_flg |=  0x2;
                
                plp->mtn_no = PlMtnWpn[4];
    
                plp->hokan_count = 20;
                
                plp->frm_no = 0;
                
                plp->hokan_ctbak = plp->hokan_count;
                
                plp->waxp = 0;
    
                if ((((PP_WORK*)plp->exp2)->mode & 0x4)) 
                {
                    plp->mtn_no += 17;
                }
                
                if (plp->mode3 == 3) 
                {
                    plp->mode3 = 4;
                }
            }
            
            break;
        case 0x30:
            if (!(plp->at_flg & 0x4)) 
            {
                plp->at_flg &= ~0xE;
                plp->at_flg |=  0x4;
                
                plp->mtn_no = PlMtnWpn[4] + 5;
                
                plp->hokan_count = 20;
                
                plp->frm_no = 0;
                
                plp->hokan_ctbak = plp->hokan_count;
                
                plp->waxp = 8192;
                
                if (plp->mode3 == 3) 
                {
                    plp->mode3 = 4;
                }
            }
            
            break;
        case 0x50:
            if (!(plp->at_flg & 0x8)) 
            {
                plp->at_flg &= ~0xE;
                plp->at_flg |=  0x8;
                
                plp->mtn_no = PlMtnWpn[4] + 10;
                
                plp->hokan_count = 20;
                
                plp->frm_no = 0;
                
                plp->hokan_ctbak = plp->hokan_count;
                
                plp->waxp = -8192;
                
                if (plp->mode3 == 3) 
                {
                    plp->mode3 = 4;
                }
            }
    
            break;
        }
            
        if ((sys->pad_on & 0x8)) 
        {
            plp->ay -= (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
        }
        
        if ((sys->pad_on & 0x4))
        {
            plp->ay += (int)(182.04445f * (2.4f * ((EXP_WORK*)plp->exp0)->rtspd));
        }
        
        if (((sys->pad_ps & 0x80)) && (SetLockOnDirection(16384, 6, 1, 0) != 0)) 
        {
            plp->flg |= 0x100000;
            
            ((EXP_WORK*)plp->exp0)->yrct = 4;
        } 
    }

    if (ppP->gun_delay == 0) 
    {
        CheckGunHit(wt, 13, ppP->arm_dl + plp->ay);
        
        bhSetGunFire(plp, plp->wpnr_no, 13, 1, ppP->arm_dl + plp->ay);
        bhSetYakkyou(plp, plp->wpnr_no, 13, 1, ppP->arm_dl + plp->ay);
        
        ppP->gun_delay = -1; 
    }
    else if (ppP->gun_delay > 0) 
    {
        ppP->gun_delay--; 
    }
    if ((plp->at_flg & 0xE) != 0x2) 
    {
        ppP = (PP_WORK*)plp->exp2;
        
        ppP->mode &= ~0x14;
    }
}

// 100% matching!
static GA_WORK* CheckGunHit(const WPN_TAB* wtP, int obj_no, int yaw)
{
    NJS_POINT3 ps;
    static GA_WORK gap;
    
    gap.at_flg = plp->at_flg;
    
    gap.wpn_no = plp->wpnr_no;
    
    gap.r = wtP->r;
    gap.l = wtP->l;
    
    gap.rn = wtP->rn;
    gap.rmax = wtP->rmax;
    
    gap.ax = plp->wax;
    gap.ay = yaw;
    
    plp->way = yaw;
    plp->waz = 0;
    
    ps.x = ps.y = 0;
    ps.z = WpnTab[plp->wpnr_no].wp_fps1.z; 
    
    njCalcPoint(&plp->mlwP->owP[obj_no].mtx, &ps, (NJS_POINT3*)&gap.gx);
    
    *(NJS_POINT3*)&gap.px = *(NJS_POINT3*)&gap.gx;
    gap.py = 11.0f + plp->py;
    
    njUnitRotPortion(NULL);
    
    njRotateXYZ(NULL, plp->wax, yaw, plp->waz);
    
    ps.x = ps.y = 0;
    ps.z = -gap.l;
    
    njCalcVector(NULL, &ps, (NJS_VECTOR*)&gap.vx);
    
    bhCheckGunAtari(&gap);
    
    return &gap;
}

// 100% matching!
void bhCPM2_SearchPch() 
{
    search* lstP; // needs use
    PP_WORK* ppP;
    int special; // not from DWARF

    special = sys->ply_id == 2;
    
    if (special != 0) 
    {
        special = plp->wpnr_no == 8;
    }
    
    if (special != 0)
    {
        special = (plp->at_flg & 0xE) == 2;
    }
    
    if (SetLockOnDirection(16384, 8, 1, special) != 0) 
    {
        plp->flg |= 0x100000;
        
        PEXP0_I(4) = 8;
        
        ppP = (PP_WORK*)plp->exp2;
        
        if ((ppP->mode & 0x8)) 
        {
            ppP->hed_rate = 0;
        } 
        else 
        {
            ppP->hed_rate = 65536;
        }
        
        if (((ppP->mode & 0x4)) && ((plp->at_flg & 0xE) == 2))
        {
            plp->mtn_no = 117;
            
            plp->hokan_count = 8;
            plp->hokan_rate  = 39321;  
        }
    }
}

// 
// Start address: 0x14cf60
void bhArmIkMdk(BH_PWORK* ewP, int bas_no, NJS_POINT3* effP, int rot)
{
	//npobj* obj1P;
	//npobj* obj0P;
	//_anon27* vtP;
	//_anon27* vb1P;
	//_anon27* vyP;
	//_anon27* vhP;
	float l01;
	float lb0;
	float lb1;
	int Ta;
	//_anon27 vu;
	// Line 1235, Address: 0x14cf60, Func Offset: 0
	// Line 1241, Address: 0x14cf8c, Func Offset: 0x2c
	// Line 1235, Address: 0x14cf90, Func Offset: 0x30
	// Line 1241, Address: 0x14cf94, Func Offset: 0x34
	// Line 1235, Address: 0x14cf98, Func Offset: 0x38
	// Line 1242, Address: 0x14cfa0, Func Offset: 0x40
	// Line 1235, Address: 0x14cfa4, Func Offset: 0x44
	// Line 1242, Address: 0x14cfa8, Func Offset: 0x48
	// Line 1235, Address: 0x14cfac, Func Offset: 0x4c
	// Line 1250, Address: 0x14cfb0, Func Offset: 0x50
	// Line 1245, Address: 0x14cfb4, Func Offset: 0x54
	// Line 1243, Address: 0x14cfc4, Func Offset: 0x64
	// Line 1250, Address: 0x14cfcc, Func Offset: 0x6c
	// Line 1245, Address: 0x14cfd0, Func Offset: 0x70
	// Line 1244, Address: 0x14cfd4, Func Offset: 0x74
	// Line 1245, Address: 0x14cfdc, Func Offset: 0x7c
	// Line 1250, Address: 0x14cff8, Func Offset: 0x98
	// Line 1245, Address: 0x14d00c, Func Offset: 0xac
	// Line 1250, Address: 0x14d010, Func Offset: 0xb0
	// Line 1252, Address: 0x14d018, Func Offset: 0xb8
	// Line 1253, Address: 0x14d020, Func Offset: 0xc0
	// Line 1254, Address: 0x14d02c, Func Offset: 0xcc
	// Line 1256, Address: 0x14d03c, Func Offset: 0xdc
	// Line 1257, Address: 0x14d048, Func Offset: 0xe8
	// Line 1258, Address: 0x14d054, Func Offset: 0xf4
	// Line 1261, Address: 0x14d05c, Func Offset: 0xfc
	// Line 1260, Address: 0x14d060, Func Offset: 0x100
	// Line 1263, Address: 0x14d064, Func Offset: 0x104
	// Line 1264, Address: 0x14d078, Func Offset: 0x118
	// Line 1266, Address: 0x14d080, Func Offset: 0x120
	// Line 1267, Address: 0x14d090, Func Offset: 0x130
	// Line 1269, Address: 0x14d098, Func Offset: 0x138
	// Line 1271, Address: 0x14d0a8, Func Offset: 0x148
	// Line 1273, Address: 0x14d0f4, Func Offset: 0x194
	// Line 1274, Address: 0x14d104, Func Offset: 0x1a4
	// Line 1282, Address: 0x14d108, Func Offset: 0x1a8
	// Line 1274, Address: 0x14d118, Func Offset: 0x1b8
	// Line 1275, Address: 0x14d120, Func Offset: 0x1c0
	// Line 1276, Address: 0x14d124, Func Offset: 0x1c4
	// Line 1282, Address: 0x14d12c, Func Offset: 0x1cc
	// Line 1283, Address: 0x14d134, Func Offset: 0x1d4
	// Line 1285, Address: 0x14d13c, Func Offset: 0x1dc
	// Line 1286, Address: 0x14d14c, Func Offset: 0x1ec
	// Line 1288, Address: 0x14d154, Func Offset: 0x1f4
	// Line 1289, Address: 0x14d178, Func Offset: 0x218
	// Line 1290, Address: 0x14d19c, Func Offset: 0x23c
	// Line 1291, Address: 0x14d1bc, Func Offset: 0x25c
	// Line 1290, Address: 0x14d1c0, Func Offset: 0x260
	// Line 1291, Address: 0x14d1c4, Func Offset: 0x264
	// Line 1293, Address: 0x14d204, Func Offset: 0x2a4
	// Line 1295, Address: 0x14d20c, Func Offset: 0x2ac
	// Func End, Address: 0x14d250, Func Offset: 0x2f0
	scePrintf("bhArmIkMdk - UNIMPLEMENTED!\n");
}
