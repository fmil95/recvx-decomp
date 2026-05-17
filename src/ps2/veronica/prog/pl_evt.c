#include "../../../ps2/veronica/prog/pl_evt.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/sdfunc.h"

unsigned char basic_motion_pl[32][2] = 
{
    { 0, 200 },
    { 0, 201 },
    { 0, 202 },
    { 0, 203 },
    { 0, 204 },
    { 1, 205 },
    { 1, 206 },
    { 1, 207 },
    { 1, 208 },
    { 1, 209 },
    { 0, 210 },
    { 0, 211 },
    { 0, 212 },
    { 0, 213 },
    { 0, 214 },
    { 1, 215 },
    { 1, 216 },
    { 1, 217 },
    { 1, 218 },
    { 1, 219 },
    { 0, 220 },
    { 0, 221 },
    { 0, 222 },
    { 0, 223 },
    { 0, 224 },
    { 1, 225 },
    { 1, 226 },
    { 1, 227 },
    { 1, 228 },
    { 1, 229 },
    { 0,   0 },
    { 0,   0 }
};
void (*bhCPM0_event_tbl[10])() = 
{
	pl_smove00,
	pl_smove01,
	pl_smove02,
	pl_smove03,
	pl_smove04,
	pl_smove05,
	pl_smove06,
	pl_smove07,
	pl_smove08,
	pl_smove00
};

// 100% matching!
void bhCPM0_event()
{
	bhCPM0_event_tbl[plp->mode2]();
}

// 100% matching!
void pl_smove00() 
{
    switch (plp->mode3)
    {                         
    case 0:
        plp->flg |= 0xD0000;
        
        EXP1_I(0) |= 0x4;
        
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][6];
        
        plp->hokan_rate = 49152;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;
        
        plp->frm_no = 0;
        
        ((EXP_WORK*)plp->exp0)->arp = 0;
        
        plp->mode3++;
    case 1:
        if (((unsigned int)plp->frm_no / 65536) >= (plp->mnwP[plp->mtn_no].frm_num - 1))
        {
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][6] + 1;
            
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->mode3 = 2;
        }
        
        break;
    case 2:
        break;
    }
}

// 100% matching!
void pl_smove01() 
{
    switch (plp->mode1)
    { 
    case 0:
        switch (plp->mode3)
        {
        case 0:
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][0];
            
            plp->hokan_rate = 32768;
            plp->hokan_count = 8;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            plp->ct3 = 0;
            
            ((EXP_WORK*)plp->exp0)->arp = 0;
            
            ((EXP_WORK*)plp->exp0)->spxn = 0.3f * (((EXP_WORK*)plp->exp0)->spx - plp->px);
            ((EXP_WORK*)plp->exp0)->spzn = 0.3f * (((EXP_WORK*)plp->exp0)->spz - plp->pz);
            
            plp->mode3++;
        case 1:
            if (plp->hokan_count == 0) 
            {
                plp->flg &= ~0xC0000;
            }
            else if (plp->hokan_count > 2) 
            {
                plp->px += ((EXP_WORK*)plp->exp0)->spxn;
                plp->pz += ((EXP_WORK*)plp->exp0)->spzn;
            }
        }
        
        break;
    case 1:
        switch (plp->mode3)
        {
        case 0:
            plp->flg &= ~0xC0000;
            
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][1];
            
            plp->hokan_rate = 32768;
            plp->hokan_count = 8;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            ((EXP_WORK*)plp->exp0)->arp = 0;
            
            plp->mode3++;
        case 1:
            break;
        }
        
        plp->ay -= (int)(182.04445f * (7.2f * ((EXP_WORK*)plp->exp0)->rtspd));
        
        plp->mtn_add = -65536;
        
        if (((plp->frm_no / 65536) == 1) || ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num / 2))) 
        {
            CallPlayerFootStepSe(plp->flr_snd, 0, 1);
        }
        
        break;
    case 2:
        switch (plp->mode3)
        {
        case 0:
            plp->flg &= ~0xC0000;
            
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][1];
            
            plp->hokan_rate = 32768;
            plp->hokan_count = 8;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = 0;
            
            ((EXP_WORK*)plp->exp0)->arp = 0;
            
            plp->mode3++;
            break;
        case 1:
            break;
        }
        
        plp->ay += (int)(182.04445f * (7.2f * ((EXP_WORK*)plp->exp0)->rtspd));
        
        plp->mtn_add = 65536;
        
        if (((plp->frm_no / 65536) == 1) || ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num / 2)))
        {
            CallPlayerFootStepSe(plp->flr_snd, 0, 1);
        }

        break;
    }
    
    plp->flg &= ~0x200000;
}

#pragma divbyzerocheck on 

// 99.97% matching
void pl_smove02()
{
    int fsnd;

    switch (plp->mode3)
    {
    case 0:
        plp->flg &= ~0xC0000;
        
        if (!(plp->flg & 0x800000))
        {
            plp->frm_no = 327680;
        }
        else 
        {
            plp->frm_no = bhGetFrameNum(plp->mnwP[plp->mtn_no].frm_num, plp->mnwP[PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][2]].frm_num, plp->frm_no);
        }
        
        plp->flg &= ~0x800000;
        
        EXP1_I(0) |= 0x4;
        
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][2];
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 2.0f;
        
        if ((plp->stflg & 0x100000))
        {
            bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
        }
        
        plp->mode3++;
    case 1:
        plp->spd = 0.18f + fabsf(0.15f * njCos((plp->frm_no / 65536) * (65536 / plp->mnwP[plp->mtn_no].frm_num)));
        
        if ((plp->stflg & 0x100000))
        {
            plp->spd *= 0.8f;
        }
        
        switch (plp->mode1)
        {
        case 1:
            plp->ay -= (int)(182.04445f * (4.0f * ((EXP_WORK*)plp->exp0)->rtspd));
            break;
        case 2:
            plp->ay += (int)(182.04445f * (4.0f * ((EXP_WORK*)plp->exp0)->rtspd));
            break;
        }
        
        if ((plp->frm_no / 65536) == PlFootSnd[sys->ply_id][0][0])
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[17].mtx[12], plp->mlwP->owP[17].mtx[14]);
            
            CallPlayerFootStepSe(fsnd, 0, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000)) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f);
            }
        }
        
        if (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][1][0])
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[21].mtx[12], plp->mlwP->owP[21].mtx[14]);
            
            CallPlayerFootStepSe(fsnd, 0, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000))
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
            }
        }
    }
    
    bhAddSpeed(plp, 0);
}

// 99.97% matching
void pl_smove03() 
{
    int fsnd;

    switch (plp->mode3)
    {
    case 0:
        plp->flg &= ~0xC0000;

        EXP1_I(0) |= 0x4;
        
        plp->frm_no = bhGetFrameNum(plp->mnwP[plp->mtn_no].frm_num, plp->mnwP[PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][3]].frm_num, plp->frm_no);
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][3];
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        ((EXP_WORK*)plp->exp0)->arp = 3.0f;
        
        plp->mode3++;
    case 1:
        plp->spd = 0.9f + fabsf(0.1f * njSin(((int)plp->frm_no / 65536) * (65536 / plp->mnwP[plp->mtn_no].frm_num)));
        
        if ((plp->stflg & 0x100000))
        {
            plp->spd *= 0.8f;
        }

        if (((EXP_WORK*)plp->exp0)->dmlvl == 2) 
        {
            plp->spd *= 0.8f;
        }
        
        switch (plp->mode1)
        {
        case 1:
            plp->ay -= (int)(182.04445f * (4.5f * ((EXP_WORK*)plp->exp0)->rtspd));
            break;
        case 2:
            plp->ay += (int)(182.04445f * (4.5f * ((EXP_WORK*)plp->exp0)->rtspd));
            break;
        }
        
        if (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][0][1])
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[17].mtx[12], plp->mlwP->owP[17].mtx[14]);
            
            CallPlayerFootStepSe(fsnd, 1, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000)) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 13);
                bhSetWaterSplash(plp, 15, 1, 1.6f, 1.6f, 1.6f);
            }
        }
        
        if (((int)plp->frm_no / 65536) == PlFootSnd[sys->ply_id][1][1])
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[21].mtx[12], plp->mlwP->owP[21].mtx[14]);
           
            CallPlayerFootStepSe(fsnd, 1, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000))
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 13);
                bhSetWaterSplash(plp, 19, 1, 1.6f, 1.6f, 1.6f);
            }
        }
    }
    
    bhAddSpeed(plp, 0);
}

// 99.97% matching
void pl_smove04()
{
    int fsnd;

    switch (plp->mode3)
    {
    case 0:
        plp->flg &= ~0xC0000;

        EXP1_I(0) |= 0x4;

        if ((!(sys->pad_old & 0x1)) && (!(plp->flg & 0x800000))) 
        {
            plp->frm_no = 1638400;
        }
        else
        {
            plp->frm_no = bhGetFrameNum(plp->mnwP[plp->mtn_no].frm_num, plp->mnwP[PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][4]].frm_num, plp->frm_no);
        }

        plp->flg &= ~0x800000;
        
        plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][4];
        
        plp->hokan_rate  = 49152;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;
        
        plp->ct0 = 0;
        
        ((EXP_WORK*)plp->exp0)->arp = -1.0f;
        
        if ((plp->stflg & 0x100000)) 
        {
            bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
        }
        
        plp->mode3++;
    case 1:
        plp->spd = 0.14f + fabsf(0.15f * njCos((plp->frm_no / 65536) * (65536 / plp->mnwP[plp->mtn_no].frm_num)));
        
        if ((plp->stflg & 0x100000))
        {
            plp->spd *= 0.8f;
        }
        
        switch (plp->mode1)
        {
        case 1:
            plp->ay -= (int)(182.04445f * (4.0f * ((EXP_WORK*)plp->exp0)->rtspd));
            break;
        case 2:
            plp->ay += (int)(182.04445f * (4.0f * ((EXP_WORK*)plp->exp0)->rtspd));
            break;
        }
        
        if ((plp->frm_no / 65536) == PlFootSnd[sys->ply_id][0][2])
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[17].mtx[12], plp->mlwP->owP[17].mtx[14]);
            
            CallPlayerFootStepSe(fsnd, 0, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000)) 
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                bhSetWaterSplash(plp, 15, 0, 0.8f, 0.8f, 0.8f);
            }
        }
        
        if ((plp->frm_no / 65536) == PlFootSnd[sys->ply_id][1][2])
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[21].mtx[12], plp->mlwP->owP[21].mtx[14]);
            
            CallPlayerFootStepSe(fsnd, 0, 1);
            
            plp->stflg |= 0x200;
            
            if ((plp->stflg & 0x100000))
            {
                bhSetEffect(108, (POINT*)&plp->px, NULL, 10);
                bhSetWaterSplash(plp, 19, 0, 0.8f, 0.8f, 0.8f);
            }
        }
    }
    
    bhAddSpeed(plp, 32768);
}

#pragma divbyzerocheck off

// 100% matching!
void pl_smove05()
{
    switch (plp->mode3)
    { 
    case 0:
        plp->mtn_md &= ~0x2;
        
        plp->hokan_rate = 49152;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;
        
        switch (plp->ct0)
        {
        case 0:
            plp->mode3 = 1;
            break;
        case 1:
            plp->mode3 = 3;
            break;
        case 2:
            plp->mode3 = 4;
            break;
        }
        
        plp->mtn_no = basic_motion_pl[plp->mode1][1];
        break;
    case 1:
        if ((plp->mnwP[plp->mtn_no].frm_num - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;

            plp->mtn_add = 65536;
            
            plp->mode3 = 2;
        }
        
        break;
    case 2:
        break;
    case 3:
        if ((plp->ct2 - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->mtn_add = 65536;
            
            plp->frm_no = (plp->ct2 - 2) * 65536;
        }
        
        break;
    case 4:
        plp->ct2 = (unsigned int)plp->frm_no / 65536;
        
        plp->frm_no = (plp->ct2 - 1) * 65536;
        break;
    }
}

// 
// Start address: 0x1736c0
void pl_smove06()
{
	int fsnd;
	// Line 644, Address: 0x1736c0, Func Offset: 0
	// Line 649, Address: 0x1736c8, Func Offset: 0x8
	// Line 651, Address: 0x1736f0, Func Offset: 0x30
	// Line 652, Address: 0x1736f8, Func Offset: 0x38
	// Line 651, Address: 0x173704, Func Offset: 0x44
	// Line 652, Address: 0x17370c, Func Offset: 0x4c
	// Line 653, Address: 0x173710, Func Offset: 0x50
	// Line 652, Address: 0x173718, Func Offset: 0x58
	// Line 653, Address: 0x17371c, Func Offset: 0x5c
	// Line 652, Address: 0x173720, Func Offset: 0x60
	// Line 653, Address: 0x173728, Func Offset: 0x68
	// Line 656, Address: 0x1737a8, Func Offset: 0xe8
	// Line 658, Address: 0x1737b0, Func Offset: 0xf0
	// Line 653, Address: 0x1737b8, Func Offset: 0xf8
	// Line 656, Address: 0x1737bc, Func Offset: 0xfc
	// Line 659, Address: 0x1737c4, Func Offset: 0x104
	// Line 660, Address: 0x1737c8, Func Offset: 0x108
	// Line 661, Address: 0x1737cc, Func Offset: 0x10c
	// Line 663, Address: 0x1737d0, Func Offset: 0x110
	// Line 656, Address: 0x1737d4, Func Offset: 0x114
	// Line 658, Address: 0x1737d8, Func Offset: 0x118
	// Line 656, Address: 0x1737dc, Func Offset: 0x11c
	// Line 658, Address: 0x1737e4, Func Offset: 0x124
	// Line 659, Address: 0x1737f0, Func Offset: 0x130
	// Line 658, Address: 0x1737f4, Func Offset: 0x134
	// Line 659, Address: 0x173828, Func Offset: 0x168
	// Line 660, Address: 0x173830, Func Offset: 0x170
	// Line 661, Address: 0x17383c, Func Offset: 0x17c
	// Line 662, Address: 0x173848, Func Offset: 0x188
	// Line 663, Address: 0x173854, Func Offset: 0x194
	// Line 662, Address: 0x173858, Func Offset: 0x198
	// Line 663, Address: 0x173860, Func Offset: 0x1a0
	// Line 665, Address: 0x173870, Func Offset: 0x1b0
	// Line 672, Address: 0x1738e4, Func Offset: 0x224
	// Line 665, Address: 0x1738f8, Func Offset: 0x238
	// Line 672, Address: 0x1738fc, Func Offset: 0x23c
	// Line 688, Address: 0x17393c, Func Offset: 0x27c
	// Line 672, Address: 0x173940, Func Offset: 0x280
	// Line 688, Address: 0x173944, Func Offset: 0x284
	// Line 672, Address: 0x173948, Func Offset: 0x288
	// Line 688, Address: 0x173950, Func Offset: 0x290
	// Line 689, Address: 0x173964, Func Offset: 0x2a4
	// Line 692, Address: 0x17397c, Func Offset: 0x2bc
	// Line 695, Address: 0x17398c, Func Offset: 0x2cc
	// Line 696, Address: 0x1739a8, Func Offset: 0x2e8
	// Line 699, Address: 0x1739c0, Func Offset: 0x300
	// Line 703, Address: 0x1739d0, Func Offset: 0x310
	// Line 705, Address: 0x1739e0, Func Offset: 0x320
	// Func End, Address: 0x1739ec, Func Offset: 0x32c
	scePrintf("pl_smove06 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1739f0
void pl_smove07()
{
	int fsnd;
	// Line 715, Address: 0x1739f0, Func Offset: 0
	// Line 720, Address: 0x1739f8, Func Offset: 0x8
	// Line 722, Address: 0x173a20, Func Offset: 0x30
	// Line 723, Address: 0x173a2c, Func Offset: 0x3c
	// Line 722, Address: 0x173a34, Func Offset: 0x44
	// Line 723, Address: 0x173a3c, Func Offset: 0x4c
	// Line 726, Address: 0x173ac0, Func Offset: 0xd0
	// Line 727, Address: 0x173ac8, Func Offset: 0xd8
	// Line 728, Address: 0x173acc, Func Offset: 0xdc
	// Line 723, Address: 0x173ad0, Func Offset: 0xe0
	// Line 726, Address: 0x173ad4, Func Offset: 0xe4
	// Line 729, Address: 0x173adc, Func Offset: 0xec
	// Line 726, Address: 0x173ae0, Func Offset: 0xf0
	// Line 727, Address: 0x173ae8, Func Offset: 0xf8
	// Line 726, Address: 0x173aec, Func Offset: 0xfc
	// Line 727, Address: 0x173b20, Func Offset: 0x130
	// Line 728, Address: 0x173b28, Func Offset: 0x138
	// Line 729, Address: 0x173b34, Func Offset: 0x144
	// Line 730, Address: 0x173b40, Func Offset: 0x150
	// Line 732, Address: 0x173b54, Func Offset: 0x164
	// Line 739, Address: 0x173bc8, Func Offset: 0x1d8
	// Line 732, Address: 0x173bdc, Func Offset: 0x1ec
	// Line 739, Address: 0x173be0, Func Offset: 0x1f0
	// Line 755, Address: 0x173c20, Func Offset: 0x230
	// Line 739, Address: 0x173c24, Func Offset: 0x234
	// Line 755, Address: 0x173c28, Func Offset: 0x238
	// Line 739, Address: 0x173c2c, Func Offset: 0x23c
	// Line 755, Address: 0x173c34, Func Offset: 0x244
	// Line 756, Address: 0x173c48, Func Offset: 0x258
	// Line 759, Address: 0x173c60, Func Offset: 0x270
	// Line 762, Address: 0x173c70, Func Offset: 0x280
	// Line 763, Address: 0x173c88, Func Offset: 0x298
	// Line 766, Address: 0x173ca0, Func Offset: 0x2b0
	// Line 770, Address: 0x173cb0, Func Offset: 0x2c0
	// Line 771, Address: 0x173cc0, Func Offset: 0x2d0
	// Func End, Address: 0x173ccc, Func Offset: 0x2dc
	scePrintf("pl_smove07 - UNIMPLEMENTED!\n");
}

// 100% matching!
void pl_smove08()
{
    switch (plp->mode3)
    { 
    case 0:
        plp->mtn_md &= ~0x2;
        
        plp->hokan_rate = 49152;
        
        switch (plp->ct0)
        {
        case 0:
            plp->mode3 = 1;
            break;
        case 1:
            plp->mode3 = 3;
            break;
        case 2:
            plp->mode3 = 4;
            break;
        }
        
        plp->mtn_no = plp->mode1;
        
        if (plp->mode1 == 42) 
        {
            plp->mtn_no = PlMtnAct[((EXP_WORK*)plp->exp0)->wpntp][((EXP_WORK*)plp->exp0)->dmlvl][0];
        }
        
        break;
    case 1:
        if ((plp->mnwP[plp->mtn_no].frm_num - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->mode3 = 2;
        }
        
        break;
    case 2:
        break;
    case 3:
        if ((plp->ct2 - 1) <= ((unsigned int)plp->frm_no / 65536))
        {
            plp->hokan_rate = 49152;
            plp->hokan_count = 4;
            
            plp->frm_no = (plp->ct2 - 2) * 65536;
        }
        
        break;
    case 4:
        plp->ct2 = (unsigned int)plp->frm_no / 65536;
        
        plp->frm_no = (plp->ct2 - 1) * 65536;
        break;
    }
}
