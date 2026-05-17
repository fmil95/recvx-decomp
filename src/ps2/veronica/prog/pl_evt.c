#include "../../../ps2/veronica/prog/pl_evt.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"

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
typedef void (*bhCPM0_event_proc)();
bhCPM0_event_proc bhCPM0_event_tbl[10] = 
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

// 100% matching!
void pl_smove06()
{
    int fsnd;
    short ct0; // not from DWARF

    switch (plp->mode3)
    {                        
    case 0:
        plp->mtn_md &= ~0x2;
        
        plp->flg &= ~0xC0000;
        
        plp->frm_no = bhGetFrameNum(plp->mnwP[plp->mtn_no].frm_num, plp->mnwP[PlMtnAct[plp->wpnr_no][((EXP_WORK*)plp->exp0)->dmlvl][2]].frm_num, plp->frm_no);
        
        plp->flg &= ~0x800000;
        
        plp->mtn_no = PlMtnAct[plp->wpnr_no][((EXP_WORK*)plp->exp0)->dmlvl][2];
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 8;
        
        plp->mtn_add = 65536;
        
        plp->mode3++;
        
        plp->flg |= 0x200000;
    case 1:
        plp->spd = 0.18f + fabsf(0.15f * njCos((plp->frm_no / 65536) * (65536 / plp->mnwP[plp->mtn_no].frm_num)));

        ct0 = plp->ct0;
        
        plp->ay += bhSub_DirTarget(plp, 0.01f * (short)(plp->ct0 / 65536), 0.01f * ct0, 910);
        
        if ((plp->frm_no / 65536) == 17) 
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[17].mtx[12], plp->mlwP->owP[17].mtx[14]);
            
            CallPlayerFootStepSe(fsnd, 0, 1);
        }
        
        if ((plp->frm_no / 65536) == 35) 
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[21].mtx[12], plp->mlwP->owP[21].mtx[14]);
            
            CallPlayerFootStepSe(fsnd, 0, 1);
        }
        
        break;
    }
    
    bhAddSpeed(plp, 0);
}

// 100% matching!
void pl_smove07() 
{
    int fsnd;
    short ct0; // not from DWARF

    switch (plp->mode3)
    { 
    case 0:
        plp->flg &= ~0xC0000;
        
        plp->frm_no = bhGetFrameNum(plp->mnwP[plp->mtn_no].frm_num, plp->mnwP[PlMtnAct[plp->wpnr_no][((EXP_WORK*)plp->exp0)->dmlvl][3]].frm_num, plp->frm_no);
        plp->mtn_no = PlMtnAct[plp->wpnr_no][((EXP_WORK*)plp->exp0)->dmlvl][3];
        
        plp->hokan_rate  = 32768;
        plp->hokan_count = 4;
        
        plp->mtn_add = 65536;
        
        plp->mode3++;
    case 1:
        plp->spd = 0.9f + fabsf(0.10f * njSin((plp->frm_no / 65536) * (65536 / plp->mnwP[plp->mtn_no].frm_num)));

        ct0 = plp->ct0;
        
        plp->ay += bhSub_DirTarget(plp, 0.01f * (short)(plp->ct0 / 65536), 0.01f * ct0, 910);
        
        if ((plp->frm_no / 65536) == 10) 
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[17].mtx[12], plp->mlwP->owP[17].mtx[14]);
            
            CallPlayerFootStepSe(fsnd, 1, 1);
        }
        
        if ((plp->frm_no / 65536) == 0) 
        {
            fsnd = bhCheckFloorSound(plp, plp->flr_no, plp->mlwP->owP[21].mtx[12], plp->mlwP->owP[21].mtx[14]);
            
            CallPlayerFootStepSe(fsnd, 1, 1);
        }
        
        break;
    }
    
    bhAddSpeed(plp, 0);
}

#pragma divbyzerocheck off

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
