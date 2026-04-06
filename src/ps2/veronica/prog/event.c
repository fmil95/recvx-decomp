#include "event.h"
#include "MdlPut.h"
#include "Motion.h"
#include "cut.h"
#include "effect.h"
#include "effsub3.h"
#include "en02.h"
#include "en11.h"
#include "eneset.h"
#include "face.h"
#include "hitchk.h"
#include "message.h"
#include "player.h"
#include "ps2_NaColi.h"
#include "ps2_NaFog.h"
#include "ps2_NaMath.h"
#include "ps2_NaView.h"
#include "ps2_dummy.h"
#include "ps2_texture.h"
#include "pwksub.h"
#include "room.h"
#include "screen.h"
#include "sdfunc.h"
#include "sub1.h"
#include "system.h"
#include "main.h"

#pragma optimization_level 4 // TODO: remove this pragma and compile the file passing the -O4,p flag instead 

unsigned char* bhScePtr;
unsigned short* bhScdPtr;
unsigned short* bhScd2Ptr;
unsigned char* bhEvdPtr;
unsigned int* G_Sp;
int bhIfelFlg;
BH_SCEWORK* bhCetask;
BH_SCEWORK bhEtask[16];
unsigned int Event_T_timer;
float GameNear;
float GameFar;

BP_WORK evnt_BldTbl = 
{
    0.0f, 0.1f, 0.0f,
    0,
    0.0f, 0.08f,
    1.0f, 0.8f, 1.0f, 0.8f, 0.0f,
    0, 4, 8, 12, 0
};
BP_WORK evnt_BldTbl2 = 
{
    0.0f, 0.1f, 0.0f,
    0,
    0.0f, 0.07f,
    1.0f, 0.2f, 0.5f, 0.8f, 0.0f,
    1, 4, 12, 15, 0
};
unsigned int (*bhScenarioJmpT[256])() = 
{
	bhEnd, 
	bhIfelCk, 
	bhElseCk, 
	bhEndif, 
	bhCk, 
	bhSet, 
	bhCmpB, 
	bhCmpW, 
	bhSv, 
	bhSvW, 
	bhWalAtariSet, 
	bhEtcAtariSet, 
	bhFlrAtariSet, 
	bhDieCk, 
	bhItmCk, 
	bhUseItemClear, 
	bhUseItemCheck, 
	bhPlItemCheck, 
	bhCineSet, 
	bhCamSet, 
	bhEvtOn, 
	bhBgmOn, 
	bhBgmOff, 
	bhSeOn, 
	bhSeOff, 
	bhVoiceOn, 
	bhVoiceOff, 
	bhAdxCk, 
	bhBGSeOn, 
	bhBGSeOff, 
	bhAdxTimeCk, 
	bhMessageSet, 
	bhSetDispObj, 
	bhDieEventCk, 
	bhEneSetCk, 
	bhItmSetCk, 
	bhInitModelSet, 
	bhEtcAtariSet2, 
	bhArmsItemCheck, 
	bhArmsItemChange, 
	bhSubStatus, 
	bhCamPauseSet, 
	bhCamSet2, 
	bhMotionPauseSet, 
	bhEffectSet, 
	bhInitMotionPause, 
	bhMotionPauseSetPly, 
	bhInitSetKage, 
	bhInitMotionPauseEx, 
	bhPlItemLost, 
	bhObjLinkSet, 
	bhSetDoorCall, 
	bhObjLinkSetPly, 
	bhLightSet, 
	bhFadeSet, 
	bhRoomCaseNo, 
	bhFrameCheck, 
	bhCamInfoSet, 
	bhMutekiSetPl, 
	bhDefModelSet, 
	bhMaskSet, 
	bhLipSet, 
	bhMaskStart, 
	bhLipStart, 
	bhLookGsetPlStart, 
	bhLookGsetPlStop, 
	bhItmAspdSet, 
	bhEffDispSet, 
	bhEffAmbSet, 
	bhDelObjSe, 
	bhSetNextRoomBgm, 
	bhSetNextRoomBgSe, 
	bhFootSeCall, 
	bhWeaponSeCall, 
	bhYakkyouSet, 
	bhLightTypeSet, 
	bhFogColorSet, 
	bhPlItemBlockCk, 
	bhEffBloodSet, 
	bhCyoutenHenkeiSet, 
	bhSetObjMotion, 
	bhObjLinkSetObjEne, 
	bhObjLinkSetObjItem, 
	bhObjLinkSetEneItem, 
	bhObjLinkSetEneEne, 
	bhCyoutenHenkeiStart, 
	bhEffBloodPoolSet, 
	bhFixEventCamPly, 
	bhEffBloodPoolSet2, 
	bhObjLinkSetObjObj, 
	bhCamYureSet, 
	bhInitCamSet, 
	bhMesDispEndSet, 
	bhPadCheck, 
	bhMovieStart, 
	bhMovieStop, 
	bhTFrameCheck, 
	bhEventTimerClr, 
	bhCamCheck, 
	bhRandamSet, 
	bhPlCtr, 
	bhLoadWork, 
	bhObjCtr, 
	bhSubCtr, 
	bhLoadWork2, 
	bhCommonCtr, 
	bhEventSkipSet, 
	bhDelYakkyou, 
	bhObjAlphaSet, 
	bhCyodanSet, 
	bhHEffectSet, 
	bhObjLinkSetObjPly, 
	bhEffPush, 
	bhEffPop, 
	bhAreaSearchObj, 
	bhLightParameterCSet, 
	bhLightParameterStart, 
	bhInitMidiSlotSet, 
	bh3dSoundFlagSet, 
	bhSoundVolumeSet, 
	bhLightParameterSet, 
	bhEneSeOn, 
	bhEneSeOff, 
	bhWalAtariSet2, 
	bhFlrAtariSet2, 
	bhMotionPosSetEnePly, 
	bhKageSwSet, 
	bhSoundPanSet, 
	bhInitPonySet, 
	bhSubMapBusyCk, 
	bhSetDebugLoopEx, 
	bhSoundFadeOut, 
	bhCyoutenHenkeiSetEX, 
	bhCyoutenHenkeiStartEX, 
	bhEasySESet, 
	bhSoundFlagReSet, 
	bhEffUVSet, 
	bhPlayerChangeSet, 
	bhPlayerPoisonCk, 
	bhAddObjSe, 
	bhRandTest, 
	bhEvtComSet, 
	bhZombieUpDieCk, 
	bhFacePauseSet, 
	bhFaceReSet, 
	bhEffModeSet, 
	bhBGSeOff2, 
	bhBgmOff2, 
	bhBGSeOn2, 
	bhBgmOn2, 
	bhEffectSensyaSet, 
	bhEffectKokuenSet, 
	bhEffectSandSet, 
	bhEnemyHpUp, 
	bhFaceRep, 
	bhMovieCk, 
	bhSetItmMotion, 
	bhObjAspdSet, 
	bhPuruPuruFlagSet, 
	bhPuruPuruStart, 
	bhMapSystemOn, 
	bhTrapDamageSet, 
	bhEvtLighterFireSet, 
	bhObjLinkSetPlyItem, 
	bhPlayerKaidanMotion, 
	bhEneRenderSet, 
	bhBgmOnEx, 
	bhBgmOn2Ex, 
	bhFogParameterCSet, 
	bhFogParameterStart, 
	bhEffUVSet2, 
	bhBGColorSet, 
	bhMovieTimeCk, 
	bhEffTypeSet, 
	bhPlayerPoison2Cr, 
	bhPlyHandChange, 
	bhHEffectSet2, 
	bhObjDposCk, 
	bhItemGetGet, 
	bhEtcAtariEnePosSet, 
	bhEtcAtariEvtPosSet, 
	bhLoadWorkEx, 
	bhRoomSoundCase, 
	bhItemPlToSBox, 
	bhItemSBoxToIBox, 
	bhGrdPosSet, 
	bhGrdPosMoveCSet, 
	bhGrdPosMoveStart, 
	bhEvtKill, 
	bhReTryPointSet, 
	bhPlyDposCk, 
	bhPlItemLostEx, 
	bhCyodanSetEx, 
	bhArmsItemSet, 
	bhItemGetGetEx, 
	bhEffectSandSetMatsumoto, 
	bhVoiceWait, 
	bhVoiceStart, 
	bhGameOverSet, 
	bhPlItemChangeM, 
	bhEffBakuDrmSet, 
	bhPlItemTamaSet, 
	bhEffClearEvt, 
	bhEvtTimerSet, 
	bhEneLookFlgSet, 
	bhReturnTitleEvt, 
	bhSyukanModeSet, 
	bhExGameItemInit, 
	bhEneLifeSetM, 
	bhEffSSizeSet, 
	bhEffLinkOffsetSet, 
	bhRankingCall, 
	bhCallSysSe, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	dm0, 
	bhEwhile2, 
	bhComNext, 
	dm0, 
	dm0, 
	dm0, 
	bhSleep, 
	bhSleeping, 
	bhFor, 
	bhNext, 
	bhWhile, 
	bhEwhile, 
	bhEvtNext, 
	bhEvtEnd
};
/*unsigned char G_Mess_flag;
unsigned int Event_T_timer_bak;
unsigned int Event_C_timer;
unsigned int bhCetask_w[308];
unsigned int* G_Ework_ptr;
_anon23 bhEventWork2;
unsigned short* G_Pl_life;
unsigned short* G_Timer;
unsigned char bhEventWork[16];
unsigned int G_Common_flg[16];
unsigned int* G_Sp9;
unsigned int* G_Sp8;
unsigned int* G_Sp7;
unsigned int* G_Sp6;
unsigned int* G_Sp5;
unsigned int* G_Sp4;
unsigned int* G_Sp3;
unsigned int* G_Sp2;
unsigned int* G_Sp1;*/

// 100% matching!
void bhInitEvent()
{
    unsigned int v6;

    for (v6 = 0; v6 < 16; v6++) 
    {
        bhEtask[v6].status = 0;
        
        bhEtask[v6].wpnl_no = 0;
    }
    
    SendSoundCommand(3);
    
    bhControlEnemy();

    bhScdPtr = rom->evtp->scd0;
    bhScd2Ptr = rom->evtp->scd1;
    
    bhEvdPtr = (unsigned char*)rom->evtp->evd;
    
    bhCetask = bhEtask;
    
    bhIfelFlg = 0;
    
    Event_T_timer = 0;

    swork.pip = &sys->itm[sys->ply_id * 16];

    bhScenarioCheck((unsigned char*)bhScdPtr);
    
    sys->sp_flg |= 0x10;
    
    bhEventScheduler2();
    
    sys->sp_flg &= ~0x10;
    
    SendSoundCommand(4);
}

// 100% matching!
void bhControlEvent()
{
    bhScenarioCheck((unsigned char*)bhScd2Ptr);
    
    bhEventScheduler2();
}

// 100% matching!
unsigned int bhEnd()
{
	bhIfelFlg = 0;

	return 0;
}

// 100% matching!
unsigned int bhIfelCk()
{
    unsigned int v0; 

    v0 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    G_Sp = (unsigned int*)((int)bhScePtr + (v0 >> 8));
    
    G_Sp++;

    bhIfelFlg++;
    
    return 1;
}

// 100% matching!
unsigned int bhElseCk()
{
    G_Sp--;
    
    bhIfelFlg--;
    
    bhScePtr = &bhScePtr[bhScePtr[1]];
    
    return 1;
}

// 100% matching!
unsigned int bhEndif()
{
    G_Sp--;
    
    bhIfelFlg--;
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int dm0()
{
	return 0;
}

// 100% matching! 
unsigned int bhCk()
{
    int* v0;     
    int v1;           
    unsigned int v2, v3;  
    unsigned char v4;  
    unsigned char* a0; 
    
    a0 = bhScePtr;
    
    v2 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    switch (v2 >> 8)
    {
    case 1:
        v0 = (int*)sys->ev_flg; 
        break;
    case 2:
        v0 = (int*)sys->ky_flg; 
        break;
    case 3:
        v0 = (int*)sys->ed_flg; 
        break;
    case 4:
        v0 = (int*)&sys->rm_flg; 
        break;
    case 5:
        v0 = (int*)&sys->st_flg; 
        break;
    case 6:
        v0 = (int*)&sys->sp_flg; 
        break;
    case 7:
        v0 = (int*)sys->it_flg; 
        break;
    case 8:
        v0 = (int*)sys->mp_flg; 
        break;
    case 9:
        v0 = (int*)sys->ic_flg; 
        break;
    case 11:
        v0 = (int*)&sys->gm_flg; 
        break;
    case 12:
        v0 = (int*)&sys->ts_flg; 
        break;
    case 10:
        v0 = (int*)&sys->cb_flg;

        a0 += 4;
        
        v4 = *a0;

        a0 -= 2;
        
        switch (*a0) 
        {                        
        case 23:                                    
            if (sys->etc_idx != v4) 
            {
                bhScePtr += 4;
                
                return 0;
            }
            
            break;
        case 22:                                    
            if (sys->flr_idx != v4) 
            {
                bhScePtr += 4;
                
                return 0;
            }
            
            break;
        }
        
        break;
    case 13:
        v0 = (int*)&plp->flg; 
        break;
    case 14:
        v0 = (int*)&plp->stflg; 
        break;
    case 15:                                        
        v0 = (int*)&plp->flg2; 
        break;
    case 16:
        v0 = (int*)&sys->ssd_flg; 
        break; 
    }
    
    v3 = *(unsigned short*)bhScePtr;
    
    v2 = v0[(v3 & 0x3FF) >> 5];
    
    bhScePtr += 2;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    v1 >>= 8;
    
    return v1 ^ (((int)(v2 << (v3 & 0x1F))) < 0);
}

// 100% matching!
unsigned int bhSet()
{
    int v0;             
    int* a0;            
    unsigned int v1;   
    unsigned short* a1; 
    
    a1 = (unsigned short*)bhScePtr;

    a1 += 3;
    
    bhScePtr = (unsigned char*)a1;

    a1 -= 3;
    
    switch (*a1 >> 8) 
    {                              
    case 1:                                         
        a0 = (int*)&sys->ev_flg; 
		break;
    case 2:                                         
        a0 = (int*)&sys->ky_flg; 
		break;
    case 3:                                         
        a0 = (int*)&sys->ed_flg; 
		break;
    case 4:                                         
        a0 = (int*)&sys->rm_flg; 
		break; 
    case 5:                                         
        a0 = (int*)&sys->st_flg; 
		break;
    case 6:                                         
        a0 = (int*)&sys->sp_flg; 
		break;
    case 7:
        a0 = (int*)sys->it_flg; 
		break;
    case 8:
        a0 = (int*)sys->mp_flg; 
		break;
    case 9:
        a0 = (int*)sys->ic_flg; 
		break;
    case 11:
        a0 = (int*)&sys->gm_flg; 
		break;
    case 12:
        a0 = (int*)&sys->ts_flg; 
		break;
    case 10:
        a0 = (int*)&sys->cb_flg; 
		break;
    case 13:
        a0 = (int*)plp; 
		break;
    case 14:
        a0 = (int*)&plp->stflg; 
		break;
    case 15:
        a0 = (int*)&plp->flg2; 
		break;
    case 16:
        a0 = (int*)&sys->ssd_flg; 
		break;
    case 0:
        break;
    }

    a1++; 
    
    v1 = *a1;
    
    a0 += (v1 & 0x3E0) >> 5;
    
    v0 = v1 & 0x1F;
    
    a1++;
    
    v1 = *a1;
    
    switch (v1 >> 8) 
    {                            
    case 0:                                         
        *a0 |= 0x80000000 >> v0;
        
        return 1;
    case 1:                                         
        *a0 &= ~(0x80000000 >> v0);
        
        return 1;
    case 2:                                         
        *a0 ^= 0x80000000 >> v0;
        
        return 1;
    case 3:                                         
        *a0 |= 0xFFFFFFFF >> v0;
        
        return 1;
    case 4:                                         
        *a0 &= ~(0xFFFFFFFF >> v0);
        
        return 1;
    case 5:                                         
        *a0 ^= 0xFFFFFFFF >> v0;
        
        return 1;
    }
}

// 100% matching!
unsigned int bhCmpB()
{
    unsigned int v0, v1, v2, v3; 
    
    bhScePtr++;
    
    v3 = *bhScePtr;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;

    switch (v3) 
    {
    case 0: 
        v0 = sys->stg_no; 
        break;
    case 1: 
        v0 = sys->rom_no; 
        break;
    case 2: 
        v0 = cam.ncut; 
        break;
    case 15: 
        v0 = sys->pos_no; 
        break;
    case 8: 
        v0 = sys->sb_id; 
        break;
    case 17: 
        v0 = bhEtask->wpnl_no; 
        break;
    case 21: 
        v0 = sys->rcase; 
        break;
    case 23: 
        v0 = sys->gm_mode; 
        break;
    case 24: 
        v0 = sys->ply_id;
        break;
    case 25: 
        v0 = sys->costume; 
        break;
    }

    switch (v2)
    {
    case 0: 
        return v0 == v1; 
    case 1: 
        return v0 > v1; 
    case 2: 
        return v0 >= v1; 
    case 3: 
        return v0 < v1; 
    case 4: 
        return v0 <= v1; 
    case 5: 
        return v0 != v1; 
    }
}

// 100% matching! 
unsigned int bhCmpW()
{
    int v0, v1, v2, v3, v4;
    ETTY_WORK* enep; // not from DWARF
    BH_PWORK* e_ep;  // not from DWARF

    bhScePtr++;
    
    v4 = *bhScePtr;
    
    bhScePtr++;
    
    v3 = *bhScePtr;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    switch (v3) 
    {                              
    case 5:          
        v0 = plp->hp;
        break;
    case 7:    
        v0 = sys->mes_sel;
        break;
    case 9:       
        v0 = sys->stv_tm;  
        break;
    case 10:                
        enep = &rom->enep[v4];
        e_ep = &ene[enep->wrk_no];
        
        v0 = e_ep->hp;
        break;
    }
    
    switch (v2) 
    {                              
    case 0:                                         
        return v0 == v1;
    case 1:                                         
        return v1 < v0;
    case 2:                                         
        return v0 >= v1;
    case 3:                                         
        return v0 < v1;
    case 4:                                         
        return v1 >= v0;
    case 5:                                         
        return v0 != v1; 
    }
}

// 100% matching!
unsigned int bhSv()
{   
    unsigned int v0, v1;

    bhScePtr++;
    
    v0 = *bhScePtr;

    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr += 2;
    
    switch (v0) 
    {
    case 0:
        sys->stg_no = v1;
        break;
    case 1:
        sys->rom_no = v1;
        break;
    case 2:
        cam.ncut = v1;
        break;
    case 16:
        plp->flr_no = v1;
        break;
    case 8:
        sys->sb_id = v1;
        break;
    case 18:
        plp->wpnr_no = v1;
        
        sys->ply_wno[sys->ply_id] = v1;
        break;
    case 15:
        sys->pos_no = v1;
        break;
    case 19:
        sys->ef_slow = v1;
        break;
    case 20:
        sys->etc_idx = v1;
        break;
    case 21:
        sys->rcase = v1;
        break;
    case 22:
        sys->itm[sys->ply_id * 16] = v1;
        break;
    case 25:
        sys->costume = v1;
        break;
    }
    
    return 1;
}

// 100% matching! 
unsigned int bhSvW() 
{
    int v0, v1;  
    BH_PWORK* enep; // not from DWARF

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    switch (v0) 
    {
    case 5: 
        plp->hp = v1;
        break;
    case 9: 
        sys->stv_tm = v1; 
        break;
    case 11:
        v1 *= -1;
        
        enep = &ene[rom->enep[0].wrk_no]; 
        
        enep->hp = v1;
        break;
    case 12:
        v1 *= -1;
        
        enep = &ene[rom->enep[1].wrk_no];
        
        enep->hp = v1;
        break;
    case 13:
        v1 *= -1;
        
        enep = &ene[rom->enep[2].wrk_no]; 
        
        enep->hp = v1;
        break;
    case 14:
        v1 *= -1;
        
        enep = &ene[rom->enep[3].wrk_no];
        
        enep->hp = v1;
        break;
    case 15:
        v1 *= -1;
        
        enep = &ene[rom->enep[4].wrk_no]; 
        
        enep->hp = v1;
        break;
    }

    return 1;
}

// 100% matching!
unsigned int bhEvtOn()
{
    unsigned int v0;

    bhScePtr += 2;
    
    v0 = *(unsigned short*)bhScePtr;
    
    Event_exec(v0 & 0xFF, v0 >> 8);
    
    bhScePtr += 2;
    
    return 1;
}

// 99.88% matching
unsigned int bhCamSet()
{
	unsigned int v0, v1, v2;

    cam.flg &= ~0x46;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    switch (v0) 
    {     
    case 0:
        cam.evc_no = v1;
        cam.keyf_no = v2;
        
        bhSetEventCamera(v1, v2);
        
        bhChangeViewClip(sys->stg_no, sys->rom_no, sys->rcase, cam.evc_no);
        bhChangeClipVolume(sys->stg_no, sys->rom_no, sys->rcase, cam.evc_no);
        break;
    case 1:
        sys->st_flg &= ~0x1;
        
        bhCheckCut(1);
        
        if ((sys->ts_flg & 0x200))
        {
            if ((sys->gm_flg & 0x40)) 
            {
                njClipZ(-1.0f, -20000.0f);
            } 
            else 
            {
                njClipZ(GameNear, GameFar);
            }
        } 
        else 
        {
            njClipZ(-1.0f, -99.0f);
        }
        
        break;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhCamSet2()
{
    unsigned int v0, v1;
	
    cam.flg &= ~0x46;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;
    bhScePtr++;
    
    switch (v0) 
    { 
    case 0:
        sys->st_flg |= 0x1;
        sys->gm_flg |= 0x1000;
        
        sys->fixcno = v1;
        
        bhSetFixedCut(sys->fixcno);
        break;
    case 1:
        sys->st_flg &= ~0x1;
        sys->gm_flg &= ~0x1000;
        break;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhCamPauseSet()
{
    unsigned int v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    switch (v0)
    {                      
    case 0:
        cam.mode0 = 3;
        break;
    case 1:
        cam.mode0 = 1;
        break;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhMessageSet()
{
	unsigned int v0, v1, v2;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;

    v2 = *bhScePtr;
    
    if (v0 == 0) 
    {
        if (v2 == 0)
        {
            sys->sp_flg &= ~0x7;
        }
        
        bhSetMessage(0, v1);
    } 
    else 
    {
        sys->sp_flg |= 0x7;
    }

    bhScePtr++;
    
    return 1;
}

// 100% matching!
unsigned int bhBgmOn()
{
    int v0, v1;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;

    v1 *= 10;
    
    bhScePtr++;
    bhScePtr++;
    
    PlayBgm(v0, v1);
    
    return 1;
}

// 100% matching!
unsigned int bhBgmOff() 
{
    unsigned int v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    StopBgm(v0 * 10);
    
    return 1;
}

// 100% matching!
unsigned int bhSeOn()
{
    unsigned int v0, v1, v2, v3, v4; 
    NJS_POINT3 pPos; 
    BH_PWORK* e_ep; 
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v3 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    v4 = *bhScePtr;
    
    bhScePtr += 2;
    
    switch (v1)
    {
    case 0:
        pPos.x = plp->mlwP->owP->mtx[12];
        pPos.y = plp->mlwP->owP->mtx[13];
        pPos.z = plp->mlwP->owP->mtx[14];
        break;
    case 1:
        enep = &rom->enep[v2];
        
        e_ep = &ene[enep->wrk_no];
        
        pPos.x = e_ep->mlwP->owP->mtx[12];
        pPos.y = e_ep->mlwP->owP->mtx[13];
        pPos.z = e_ep->mlwP->owP->mtx[14];
        break;
    case 2:
        e_ep = (BH_PWORK*)&sys->obwp[v2];
    
        pPos.x = e_ep->mlwP->owP->mtx[12];
        pPos.y = e_ep->mlwP->owP->mtx[13];
        pPos.z = e_ep->mlwP->owP->mtx[14];
        break;
    }
    
    CallNativeEventSe(v0, &pPos, v3, v4);
    
    return 1;
}

// 100% matching!
unsigned int bhSeOff()
{
    unsigned char v0;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    StopNativeEventSe(v0);
    
    return 1;
}

// 100% matching!
unsigned int bhBGSeOn()
{
    unsigned int v0, v1, v2;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    v2 = *bhScePtr;
    
    bhScePtr += 2;
    
    CallBackGroundSeEx(v0, v1, v2 * 10);
    
    return 1;
}

// 100% matching!
unsigned int bhBGSeOff()
{
	unsigned char v0;
    unsigned int v2;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr += 2;
    
    StopBackGroundSeEx(v0, v2 * 10);
    
    return 1;
}

// 100% matching!
unsigned int bhUseItemCheck()
{
    unsigned char v0;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    if ((sys->cb_flg & 0x400)) 
    {
        return sys->sb_id == v0;
    }
    
    return 0;
}

// 100% matching!
unsigned int bhArmsItemCheck()
{
    int v0;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    return plp->wpnr_no == v0;
}

// 100% matching!
unsigned int bhArmsItemChange()
{
    int v0;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    plp->wpnr_no = v0;
    
    sys->ply_wno[sys->ply_id] = v0;
    
    *(int*)&sys->mn_mode0 = 3;
    
    return 1;
}

// 100% matching!
unsigned int bhPlItemLost()
{
    unsigned int cnt;
    int v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;

    for (cnt = (sys->ply_id * 16) + 2; cnt < ((sys->ply_id * 16) + 12); cnt++) 
    {
        if (v0 == (unsigned char)(sys->itm[cnt] >> 16)) 
        {
            sys->itm[cnt] = 0;
            
            if (((cnt - (sys->ply_id * 16)) <= sys->itm[sys->ply_id * 16]) && (sys->itm[sys->ply_id * 16] != 0)) 
            {
                if (sys->itm[sys->ply_id * 16] == cnt) 
                {
                    sys->itm[sys->ply_id * 16] = 0;
                } 
                else
                {
                    sys->itm[sys->ply_id * 16]--;
                }
            }
            
            for ( ; cnt < ((sys->ply_id * 16) + 12); cnt++) 
            {
                sys->itm[cnt] = sys->itm[cnt + 1];
            }
            
            return 1;
        }
    }
    
    return 1;
}

// 100% matching! 
unsigned int bhUseItemClear()
{
	bhScePtr += 2;

	sys->cb_flg &= ~0x400;

	return 0;
}

// 100% matching!
unsigned int bhPlItemCheck()
{
    unsigned int cnt;
    unsigned char v0;         

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;

    for (cnt = (sys->ply_id * 16) + 1; cnt < ((sys->ply_id * 16) + 12); cnt++) 
    {
        if (v0 == (unsigned char)(sys->itm[cnt] >> 16)) 
        {
            if (((unsigned char)(sys->itm[cnt] >> 16) == 72) && ((sys->itm[cnt] >> 16) != 72)) 
            {
                sys->rm_flg |= 0x10000;
            }
            
            return 1;
        }
    }
    
    return 0;
}

// 100% matching!
unsigned int bhMovieStart()
{
    unsigned int v0;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    bhScePtr += 2;
    
    sys->mvi_no = v0;
    
    sys->cb_flg |= 0x4000000;
    
    return 1;
}

// 100% matching! 
unsigned int bhMovieStop()
{
	bhScePtr += 2;

	sys->cb_flg &= ~0x4000000;

	return 1;
}

// 100% matching!
unsigned int bhVoiceOn()
{
	unsigned int v0, v1, v2, v3, v4;
	NJS_POINT3 pPos;
    BH_PWORK* e_ep;
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;
    
    v0 = *bhScePtr;    
    
    bhScePtr++;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v3 = *bhScePtr;
    
    v3 *= 10;
    
    bhScePtr++;
    
    v4 = *bhScePtr;
    
    bhScePtr += 2;
    
    if (bhCetask->mode2 != 0) 
    {
        bhCetask->mode2 = 0;
        
        StopVoice(0);
    }
    
    switch (v0) 
    {
    case 0:
        pPos.x = plp->mlwP->owP->mtx[12];
        pPos.y = plp->mlwP->owP->mtx[13];
        pPos.z = plp->mlwP->owP->mtx[14];
        break;
    case 1:
        enep = &rom->enep[v4];
        e_ep = &ene[enep->wrk_no];  
        
        pPos.x = e_ep->mlwP->owP->mtx[12];
        pPos.y = e_ep->mlwP->owP->mtx[13];
        pPos.z = e_ep->mlwP->owP->mtx[14];
        break;
    case 2:
        e_ep = (BH_PWORK*)&sys->obwp[v4];
        
        pPos.x = e_ep->mlwP->owP->mtx[12];
        pPos.y = e_ep->mlwP->owP->mtx[13];
        pPos.z = e_ep->mlwP->owP->mtx[14];
        break;
    }
    
    bhCetask->mode2 = 1;
    
    PlayVoice(v1, &pPos, v2, v3);
    
    return 1;
}

// 100% matching!
unsigned int bhVoiceOff()
{
    unsigned int v0;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    bhCetask->mode2 = 0;
    
    StopVoice(v0 * 10);
    
    return 1;
}

// 100% matching!
unsigned int bhAdxCk() 
{
    unsigned int v1;
    unsigned int ret;

    bhScePtr++;
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr += 2;
    
    ret = *bhScePtr;
    
    bhScePtr += 2;
    
    return CheckPlayEndAdx(v1);
}

// 100% matching!
unsigned int bhAdxTimeCk() 
{
	unsigned int v0, v1, v2;
    unsigned int ret;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    v2 = *bhScePtr;
    
    bhScePtr += 2;
    
    ret = GetTimeAdx(v0);
    
    switch (v2) 
    {
    case 0:
        if (ret == v1) 
        {
            ret = 0;
        }
        else
        {
            ret = 1;
        }
        
        break;
    case 1:
        if (ret > v1) 
        {
            ret = 0;
        }
        else 
        {
            ret = 1;
        }
        
        break;
    case 2:
        if (ret >= v1) 
        {
            ret = 0;
        }
        else 
        {
            ret = 1;
        }
        
        break;
    case 3:
        if (ret < v1) 
        {
            ret = 0;
        }
        else 
        {
            ret = 1;
        }
        
        break;
    case 4:
        if (ret > v1) 
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
        
        break;
    case 5:
        if (ret != v1)
        {
            ret = 0;
        }
        else 
        {
            ret = 1;
        }
        
        break;
    }
    
    return ret;
}

// 100% matching!
unsigned int bhCineSet()
{
    unsigned int v0;
  
    bhScePtr++;
    
    v0 = *bhScePtr;

    bhScePtr++;
    
    switch (v0)
    {
    case 0:
        sys->cb_flg &= ~0x40;
        sys->cb_flg |= 0x4;
        
        sys->st_flg |= 0x4;
        break;
    case 1:
        if ((sys->cb_flg & 0x40))
        {
            sys->cine_ap = 0;
            sys->cine_an = 0;
        }
        
        sys->cb_flg &= ~0x4;
        sys->st_flg &= ~0x4;
        
        sys->sp_flg |= ~0;
        break;
    case 2:
        sys->cb_flg &= ~0x4;
        sys->st_flg &= ~0x4;
        
        sys->cine_ap = 0;
        sys->cine_an = 0;
        break;
    case 3:
        sys->cb_flg |= 0x4;
        sys->cb_flg |= 0x40;
        
        sys->st_flg |= 0x4;
        break;
    case 4:
        sys->cb_flg &= ~0x40;
        sys->cb_flg &= ~0x4;
        
        sys->st_flg &= ~0x4;
        sys->sp_flg |= ~0;
        
        sys->cine_ap = 0;
        sys->cine_an = 0;
        break;
    case 5:
        sys->cb_flg &= ~0x40;
        sys->cb_flg |= 0x4;
        
        sys->st_flg |= 0x4;
        
        sys->cine_ap = 0;
        sys->cine_an = 0;
    }
    
    return 1;
}

// 100% matching! 
unsigned int bhWalAtariSet()
{
    unsigned int v0, v1;
    ATR_WORK* e_walp;

    bhScePtr++;
    
    v0 = *bhScePtr;    
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr += 2;
    
    e_walp = rom->walp;
    
    e_walp += v0;
    
    if (v1 != 0) 
    {
        e_walp->flg &= ~0x1;
    }
    else 
    {
        e_walp->flg |= 0x1;
    }
    
    return 1;
}

// 100% matching! 
unsigned int bhEtcAtariSet() 
{
    unsigned int v0, v1;
    ATR_WORK* e_etcp;

    bhScePtr++;
    
    v0 = *bhScePtr;    
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr += 2;
    
    e_etcp = rom->etcp;
    
    e_etcp += v0;
    
    if (v1 != 0) 
    {
        e_etcp->flg &= ~0x1;
    }
    else 
    {
        e_etcp->flg |= 0x1;
    }
    
    return 1;
}

// 100% matching! 
unsigned int bhFlrAtariSet()
{
    unsigned int v0, v1;
    ATR_WORK* e_flrp;

    bhScePtr++;
    
    v0 = *bhScePtr;    
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr += 2;
    
    e_flrp = rom->flrp;
    
    e_flrp += v0;
    
    if (v1 != 0) 
    {
        e_flrp->flg &= ~0x1;
    }
    else 
    {
        e_flrp->flg |= 0x1;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhSubStatus()
{
    bhScePtr += 2;
    
    sys->ts_flg |= 0x200;
    
    return 1;
}

// 100% matching!
unsigned int bhMotionPauseSet()
{
    unsigned int v0;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    switch (v0) 
    {
    case 0:
        bhCetask->work->mode3 = 4;
        
        if (bhCetask->work->id == 1)
        {
            ((BH_PWORK*)bhCetask->work->exp1)->mode3 = 4;
        }
        
        break;
    case 1:
        bhCetask->work->mode3 = 1;
        
        if (bhCetask->work->id == 1) 
        {
            ((BH_PWORK*)bhCetask->work->exp1)->mode3 = 1;
        }

        break;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhMotionPauseSetPly()
{
    unsigned int v0;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    switch (v0) 
    {
    case 0:
        sys->sp_flg &= ~0x1;
        break;
    case 1:
        sys->sp_flg |= 0x1;
        break;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhInitMotionPause()
{
    unsigned int v0;
    BH_PWORK* e_ep;
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;

    enep = &rom->enep[v0];
    e_ep = &ene[enep->wrk_no];
    
    e_ep->mode0 = 5;
    e_ep->mode3 = 4;
    
    if (e_ep->id == 1) 
    {
        ((BH_PWORK*)e_ep->exp1)->mode0 = 5;
        ((BH_PWORK*)e_ep->exp1)->mode3 = 4;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhInitMotionPauseEx()
{
    unsigned int v0, v1;
    BH_PWORK* e_ep;
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr += 2;

    enep = &rom->enep[v0];
    e_ep = &ene[enep->wrk_no];
    
    e_ep->mode0 = 5;
    e_ep->mode3 = 4;
    
    e_ep->frm_no = 0;
    e_ep->mtn_no = v1;
    
    e_ep->mnwP = sys->rmthp;
    
    if (e_ep->id == 1) 
    {
        ((BH_PWORK*)e_ep->exp1)->mode0 = 5;
        ((BH_PWORK*)e_ep->exp1)->mode3 = 4;
        
        ((BH_PWORK*)e_ep->exp1)->frm_no = 0;
        ((BH_PWORK*)e_ep->exp1)->mtn_no = v1;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhEffectSet()
{
	unsigned int v0, v1;
    POINT pnt;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr++;
    bhScePtr++;
    
    switch (v0) 
    {                      
    case 0:
        pnt.pz = 0;
        pnt.py = 0;
        pnt.px = 0;
        
        pnt.oz = 0;
        pnt.oy = 0;
        pnt.ox = 0;
        
        bhCetask->ev_eff_no = bhSetEffect(v1, &pnt, NULL, 0);
        break;
    case 1:
        pnt.pz = 0;
        pnt.py = 0;
        pnt.px = 0;
        
        pnt.oz = 0;
        pnt.oy = 0;
        pnt.ox = 0;
        
        bhCetask->ev_eff_no = bhSetEffect(v1, &pnt, NULL, 0);
        break;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhEffectSensyaSet()
{
    POINT pnt;

    pnt.pz = 0;
    pnt.py = 0;
    pnt.px = 0;
    
    pnt.oz = 0;
    pnt.oy = 0;
    pnt.ox = 0;
    
    bhScePtr++;
    bhScePtr++;
    
    bhCetask->ev_eff_no = bhSetEffect(120, &pnt, (unsigned char*)bhCetask->work, 0);
    
    return 1;
}

// 100% matching!
unsigned int bhEffectKokuenSet()
{
    int v0;

    sys->ef.id = 2;
    
    sys->ef.flg = 1;
    
    sys->ef.mdlver = 0;
    
    sys->ef.type = 1;
    
    sys->ef.flr_no = 0;
    
    sys->ef.sx = 4.0f;
    sys->ef.sy = 4.0f;
    sys->ef.sz = 4.0f;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    if (bhCetask->bpx == 0) 
    {
        sys->ef.px = (*(unsigned short*)bhScePtr / 100.0f) + bhEtask[v0].work->mlwP->objP->pos[0];
    } 
    else 
    {
        sys->ef.px = (-1.0f * (*(unsigned short*)bhScePtr / 100.0f)) + bhEtask[v0].work->mlwP->objP->pos[0];
    }
    
    bhScePtr += 2;
    
    if (bhCetask->bpy == 0) 
    {
        sys->ef.py = *(unsigned short*)bhScePtr / 100.0f;
    } 
    else 
    {
        sys->ef.py = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    }
    
    bhScePtr += 2;
    
    if (bhCetask->bpz == 0)
    {
        sys->ef.pz = (*(unsigned short*)bhScePtr / 100.0f) + bhEtask[v0].work->mlwP->objP->pos[2];
    } 
    else 
    {
        sys->ef.pz = (-1.0f * (*(unsigned short*)bhScePtr / 100.0f)) + bhEtask[v0].work->mlwP->objP->pos[2];
    }
    
    bhScePtr += 2;
    
    sys->ef.ay = 0;
    
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    
    return 1;
}

// 100% matching!
unsigned int bhDieCk() 
{
    int* v0;
    unsigned int v2;
    unsigned char* a0;
    ETTY_WORK* e_enep;
    int v1; // not from DWARF

    a0 = bhScePtr;
    
    bhScePtr++;
    bhScePtr++;
    
    v2 = *(unsigned short*)bhScePtr;

    v0 = (int*)&sys->ed_flg;

    if (((v0[(v2 & 0x3FF) >> 5] << (v2 & 0x1F)) < 0) ^ 1)
    {
        e_enep = &rom->enep[*++a0]; 

        if ((ene[e_enep->wrk_no].flg & 0x2)) 
        {
            v1 = v2 & 0x1F;
            
            v0[(v2 & 0x3E0) >> 5] |= 0x80000000 >> v1;
            
            bhScePtr += 2;
            
            return 1;
        }
    }
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhItmCk() 
{
    int* v0;
    int v1;
    unsigned int v2, v4, v5; 
    ATR_WORK* e_etcp;
    O_WRK* op; // not from DWARF
    
    bhScePtr++; 
    bhScePtr++;
    
    v2 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    v4 = *bhScePtr;
    
    bhScePtr++;
    
    v5 = *bhScePtr;
    
    (void)&sys->cb_flg;
    
    bhScePtr++;
    
    if (sys->etc_idx != v4) 
    {
        return 1;
    }
    
    if ((sys->cb_flg & 0x800)) 
    { 
        v0 = (int*)&sys->it_flg;
        
        if (((v0[(v2 & 0x3FF) >> 5] << (v2 & 0x1F)) < 0) ^ 1) 
        {
            e_etcp = rom->etcp;
            
            e_etcp += v4;
            
            if (v5 == 0) 
            {
                e_etcp->flg &= ~0x1;
            }
            
            op = &sys->itwp[e_etcp->prm0];
            
            op->stflg |= 0x1000000;
            
            v0 = (int*)&sys->it_flg;
          
            v0 += (v2 & 0x3E0) >> 5;
            
            v1 = v2 & 0x1F;
            
            *v0 |= 0x80000000 >> v1;
            
            v0 = (int*)&sys->ic_flg;
            
            v0 += (v2 & 0x1E0) >> 5;
            
            v1 = v2 & 0x1F;
            
            *v0 &= ~(0x80000000 >> v1);
        }
    }
    else 
    { 
        v0 = (int*)&sys->it_flg;
        
        if (((v0[(v2 & 0x3FF) >> 5] << (v2 & 0x1F)) < 0) ^ 1)
        {
            v0 = (int*)&sys->ic_flg;
            
            v0 += (v2 & 0x3E0) >> 5;
            
            v1 = v2 & 0x1F;
            
            *v0 |= 0x80000000 >> v1;
        }
    }
    
    sys->cb_flg &= ~0x800;
    
    return 1;
}

// 100% matching!
unsigned int bhObjLinkSet()
{
    int v1;
    int v0, v2;      // not from DWARF
    BH_PWORK* e_ep;  // not from DWARF
    ETTY_WORK* enep; // not from DWARF
    
    bhScePtr++;
    
    v0 = *bhScePtr;    
    
    bhScePtr++; 
    
    v1 = *bhScePtr;
   
    enep = &rom->enep[v0];
    e_ep = &ene[enep->wrk_no];
    
    sys->obwp[v1].lkwkp = (unsigned char*)e_ep;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    sys->obwp[v1].lkono = v2;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    if (v2 == 0)
    {
        sys->obwp[v1].flg |= 0x80;
    } 
    else 
    {
        sys->obwp[v1].flg &= ~0x80;
    }
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
 
    if ((v2 & 0x1)) 
    {
        sys->obwp[v1].lox = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        sys->obwp[v1].lox = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;

    if ((v2 & 0x2))
    {
        sys->obwp[v1].loy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        sys->obwp[v1].loy = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    if ((v2 & 0x4)) 
    {
        sys->obwp[v1].loz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        sys->obwp[v1].loz = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhSetObjMotion()
{
    BH_PWORK* ob_ep;
    unsigned char* a0;

    a0 = bhScePtr;

    bhScePtr++;
    bhScePtr++;

    ob_ep = (BH_PWORK*)&sys->obwp[*++a0];
    
    if ((ob_ep->mode3 == 1) && ((sys->sp_flg & 0x4)))
    {
        bhSetMotion(ob_ep, (int)ob_ep->mtn_add, ob_ep->mtn_md, ob_ep->mtn_tp);
        
        bhCalcModel(ob_ep);
    }
    
    return 1;
}

// 100% matching!
unsigned int bhSetDispObj()
{
    int v0, v1, v2;
    BH_PWORK* e_workp;
    ETTY_WORK* enep; // not from DWARF
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    switch (v1) 
    {
    case 0:
        e_workp = plp;
        break;
    case 1:
        enep = &rom->enep[v0];
        e_workp = &ene[enep->wrk_no];
        break;
    case 2:
        e_workp = (BH_PWORK*)&sys->obwp[v0];
        break;
    case 3:
        e_workp = (BH_PWORK*)&sys->itwp[v0];
        break;
    }
    
    if (v2 == 0) 
    {
        e_workp->mdflg |= 0x1;
    }
    else 
    {
        e_workp->mdflg &= ~0x1;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhSetDoorCall()
{
    int v0, v1;
    unsigned int v2, v3, v4;

    bhScePtr += 2;
    
    v0 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    v1 = *bhScePtr;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v3 = *bhScePtr;
    
    bhScePtr++;
    
    v4 = *bhScePtr;
    
    bhScePtr++;
    
    bhSetDoorDemo(v0, v1, v2, v3, v4);
    
    return 1;
}

// 100% matching!
unsigned int bhDieEventCk() 
{
    unsigned int v3;
    unsigned int v2;
    unsigned int die_cnt;
    int* v1;              // not from DWARF

    bhScePtr++;
    
    v2 = *bhScePtr; 

    bhScePtr++;
    
    v3 = *(unsigned short*)bhScePtr; 

    die_cnt = 0;

    for ( ; v2 != 0; v2--)
    {
        v1 = (int*)&sys->ed_flg;
        
        if (!(((v1[((v3 + (v2 - 1)) & 0x1FF) >> 5] << ((v3 + (v2 - 1)) & 0x1F)) < 0) ^ 1)) 
        {
            die_cnt++;
        }
    }

    bhScePtr += 2;
    
    v3 = *bhScePtr;

    bhScePtr++;
    
    v2 = *bhScePtr;

    bhScePtr++;
    
    switch (v3) 
    {
    case 0: 
        return die_cnt == v2; 
    case 1: 
        return die_cnt > v2; 
    case 2: 
        return die_cnt >= v2; 
    case 3: 
        return die_cnt < v2; 
    case 4: 
        return die_cnt <= v2;
    case 5: 
        return die_cnt != v2; 
    }
}

// 100% matching!
unsigned int bhSetDebugLoopEx()
{
    sys->st_flg |= 0x10;
    
    bhScePtr += 2;
    
    cam.ct0 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2; 
    
    cam.frm = 0;
    
    cam.mode0 = 1;
    
    bhInitEventCamera();
    
    sys->gm_flg |= 0x10;
    
    bhSetEventHideObjLgt(cam.evc_no, cam.keyf_no);
    
    if (!(sys->gm_flg & 0x800)) 
    {
        bhCheckCut(0);
    }
    else 
    {
        bhCheckCut(1);
    }
    
    return 1;
}

// 98.88% matching (matches on GC)
unsigned int bhInitSetKage()
{
	unsigned int v0, v1;
    BH_PWORK* e_ep;
    ETTY_WORK* enep; // not from DWARF
     
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr += 2;
    
    enep = &rom->enep[v0];
    e_ep = &ene[enep->wrk_no];
    
    if (!(e_ep->flg & 0x800))
    {
        e_ep->flg |= 0x800;
        
        switch (v1) 
        {                        
        case 0:
            bhSetShadow(NULL, (unsigned char*)e_ep, 1, 4.5f, 4.0f, 3.5f);
            break;
        case 1:
            bhSetShadow(NULL, (unsigned char*)e_ep, 1, 4.5f, 4.0f, 3.5f);
            break;
        case 2:
            bhSetShadow(NULL, (unsigned char*)e_ep, 1, 4.5f, 4.0f, 3.5f);
            break;
        case 3:
            bhSetShadow(NULL, (unsigned char*)e_ep, 1, 4.5f, 4.0f, 3.5f);
            break;
        case 4:
            bhSetShadow(NULL, (unsigned char*)e_ep, 1, 6.5f, 4.0f, 4.5f);
            break;
        }
    }
    
    return 1;
}

// 100% matching!
unsigned int bhObjLinkSetPly()
{
    int v1;
    int v0; // not from DWARF

    bhScePtr += 2;
    
    v0 = *bhScePtr;
    
    sys->obwp[v0].lkwkp = (unsigned char*)plp;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    sys->obwp[v0].lkono = v1;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    if (v1 == 0)
    {
        sys->obwp[v0].flg |= 0x80;
    } 
    else 
    {
        sys->obwp[v0].flg &= ~0x80;
    }
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;
    
    if ((v1 & 0x1)) 
    {
        sys->obwp[v0].lox = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        sys->obwp[v0].lox = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;

    if ((v1 & 0x2))
    {
        sys->obwp[v0].loy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        sys->obwp[v0].loy = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    if ((v1 & 0x4)) 
    {
        sys->obwp[v0].loz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        sys->obwp[v0].loz = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhSetNextRoomBgm()
{
    int v0;
    int v1; // not from DWARF

    bhScePtr++;
    bhScePtr++;

    v0 = *bhScePtr;
    
    NextSoundInfo.ComNextBgm = v0;
    
    bhScePtr++;

    v0 = *bhScePtr;
    
    NextSoundInfo.PointNextBgm = v0;
    
    bhScePtr++;
    
    NextSoundInfo.OfsPointBgm = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    NextSoundInfo.NextBgmNo = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;
    
    NextSoundInfo.FadeNextBgm = v1 * 10;
    
    return 1;
}

// 100% matching!
unsigned int bhSetNextRoomBgSe()
{
    int v0, v1;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    NextSoundInfo.ComNextBgSe[v0] = v1;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    NextSoundInfo.PointNextBgSe[v0] = v1;
    
    bhScePtr++;
    
    NextSoundInfo.OfsPointBgSe[v0] = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    NextSoundInfo.NextBgSeNo[v0] = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    NextSoundInfo.FadeNextBgSe[v0] = *bhScePtr * 10;
    
    bhScePtr++;
    
    if (*bhScePtr == 0) 
    {
        NextSoundInfo.SetNextBgSeFlag[v0] = 1;
    }
    else 
    {
        NextSoundInfo.SetNextBgSeFlag[v0] = 0;
    }
    
    bhScePtr++;
    
    return 1;
}

// 100% matching!
unsigned int bhFootSeCall()
{
	int fsnd, flr_no;
    int v0, v1, v2, v3, v4, v5, v6;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v3 = *bhScePtr;
    
    bhScePtr++;
    
    v4 = *bhScePtr;
    
    bhScePtr++;
    
    if (bhCetask->work != NULL)
    {
        flr_no = bhCheckFloorNum(bhCetask->work->mlwP->owP[v4].mtx[13]);
        
        if (v1 != 0) 
        {   
            fsnd = bhCheckFloorSound(bhCetask->work, flr_no, bhCetask->work->mlwP->owP[(int)v4].mtx[12], bhCetask->work->mlwP->owP[(int)v4].mtx[14]);
        } 
        else 
        {
            fsnd = bhCheckFloorSound(bhCetask->work, flr_no, bhCetask->work->mlwP->owP[v4].mtx[12], bhCetask->work->mlwP->owP[v4].mtx[14]);
        }
        
        v5 = 0;
        
        if (v0 == 0) 
        {
            v5 = 1;
        }

        CallPlayerFootStepSeEx(fsnd, v3, v5, v2, (NJS_POINT3*)&bhCetask->work->mlwP->owP[v4].mtx[12]);
    }
    
    return 1;
}

// 100% matching!
unsigned int bhEneSetCk()
{
	unsigned int v2;
    unsigned char* a0;
    ETTY_WORK* e_enep;
    BH_PWORK* e_ep; // not from DWARF
    int* v0;        // not from DWARF

    a0 = bhScePtr;
    
    bhScePtr = &a0[1];
    
    bhScePtr++;

    v0 = (int*)&sys->ed_flg;
    
    v2 = *(unsigned short*)bhScePtr;
 
    if (!(((v0[(v2 & 0x1FF) >> 5] << (v2 & 0x1F)) < 0) ^ 1)) 
    {
        e_enep = &rom->enep[*++a0];
        e_ep = &ene[e_enep->wrk_no];
        
        e_ep->stflg |= 0x1000000;
    }
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhItmSetCk() 
{
	unsigned int v2, v3, v4, v5;
    ATR_WORK* e_etcp;
    int* v0;   // not from DWARF
    O_WRK* op; // not from DWARF

    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v3 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;

    v4 = *bhScePtr;
    
    bhScePtr++;
    
    v5 = *bhScePtr;
    
    bhScePtr++;
    
    v0 = (int*)&sys->it_flg;
        
    if (!(((v0[(v3 & 0x1FF) >> 5] << (v3 & 0x1F)) < 0) ^ 1)) 
    {
        e_etcp = rom->etcp;

		e_etcp += v4;
        
        if (v5 == 0) 
        {
            e_etcp->flg &= ~0x1;
        }

        op = &sys->itwp[v2];
        
        op->stflg |= 0x1000000;
    } 
    else 
    {
        e_etcp = rom->etcp;

		e_etcp += v4;
        
        e_etcp->flg |= 0x1;
    }
    
    return 1;
}

// 100% matching! 
unsigned int bhInitModelSet()
{
    unsigned int v2, v3, v4; 
    BH_PWORK* e_ep;  
    O_WRK* e_ip;     
    ETTY_WORK* enep; // not from DWARF
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v3 = *bhScePtr;
    
    bhScePtr++;
    
    v4 = *bhScePtr;
    
    bhScePtr++;
    
    switch (v2) 
    {                       
    case 0:
        if (v4 == 0) 
        {
            plp->stflg |= 0x1000000;
            
            if (((sys->stg_no == 9) && (sys->rom_no == 30)) && (sys->rcase == 2)) 
            {
                pl_sleep_cnt = 2;
            }
        }
        else 
        {
            plp->stflg &= ~0x1000000;
        }
        
        break;
    case 1:
        enep = &rom->enep[v3];
        e_ep = &ene[enep->wrk_no];
        
        if (v4 == 0) 
        {
            e_ep->stflg |= 0x1000000;
            e_ep->flg |= 0x8000;
        } 
        else
        {
            e_ep->stflg &= ~0x1000000;
            
            if (!(e_ep->flg & 0x80000000))
            {
                e_ep->flg &= ~0x8000;
            }
        }
        
        break;
    case 2:
        e_ip = &sys->obwp[v3];
        
        if (v4 == 0) 
        {
            e_ip->stflg |= 0x1000000;
        } 
        else 
        {
            e_ip->stflg &= ~0x1000000;
        }
        
        break;
    case 3:
        e_ip = &sys->itwp[v3];
        
        if (v4 == 0) 
        {
            e_ip->stflg |= 0x1000000;
        } 
        else 
        {
            e_ip->stflg &= ~0x1000000;
        }
        
        break;
    }
    
    return 1;
}

// 100% matching! 
unsigned int bhEtcAtariSet2() 
{
	unsigned int v1;
    ATR_WORK* e_etcp;
    unsigned int v0; // not from DWARF
    
    bhScePtr++;
    
    e_etcp = rom->etcp;
    
    e_etcp += *bhScePtr;
    
    bhScePtr++;
    
    v0 = *(unsigned short*)bhScePtr;
    
    e_etcp->attr = v0;
    
    bhScePtr += 2;
    
    v0 = *bhScePtr;
    
    e_etcp->prm0 = v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    e_etcp->prm1 = v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    e_etcp->prm2 = v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    e_etcp->prm3 = v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    e_etcp->type = v0;
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching! 
unsigned int bhLightSet()
{
	int v0, v1, v2;
    LGT_WORK* lp;
    
    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;
    
    if (v0 == 0) 
	{
        lp = &rom->lgtp[v1];
    } 
	else 
	{
        lp = &rom->evlp[v1];
    }
    
    if (v2 == 0) 
	{
        lp->flg |= 0x1;
    } 
	else 
	{
        lp->flg &= ~0x1;
    }

    return 1;
}

// 100% matching!
unsigned int bhWeaponSeCall()
{
	int v0, v1, v2, v3, v4, v5, v6, v7, v8;
    BH_PWORK* e_ep;
	ETTY_WORK* enep; // not from DWARF
    
    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v7 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;

    v5 = *bhScePtr;

    bhScePtr++;

    v8 = *bhScePtr;

    bhScePtr += 2;
    
    if ((v4 & 0x2)) 
	{
        v5 = -v5;
    }

    v6 = 182.04445f * v5;
    
    switch (v0) 
	{
	case 0:
		if (v2 == 0) 
		{
			if (WpnTab[plp->wpnr_no].seno0 != 0) 
			{
				CallPlayerWeaponSeEx((NJS_POINT3*)&plp->mlwP->owP[13].mtx[12], WpnTab[plp->wpnr_no].seno0, v8);
			}
			
			bhSetGunFire(plp, plp->wpnr_no, 13, v2, v6);
		} 
		else 
		{
			if (WpnTab[plp->wpnr_no].seno0 != 0) 
			{
				CallPlayerWeaponSeEx((NJS_POINT3*)&plp->mlwP->owP[9].mtx[12], WpnTab[plp->wpnr_no].seno0, v8);
			}

			bhSetGunFire(plp, plp->wpnr_no, 9, v2, v6);
		}

		break;
	case 1:
		enep = &rom->enep[v7];
		e_ep = &ene[enep->wrk_no];

		if (v2 == 0) 
		{
			if (WpnTab[plp->wpnr_no].seno0 != 0) 
			{
				CallPlayerWeaponSeEx((NJS_POINT3*)&e_ep->mlwP->owP[v1].mtx[12], WpnTab[plp->wpnr_no].seno0, v8);
			}
			
			bhSetGunFire(e_ep, v3, v1, v2, v6);
		} 
		else 
		{
			if (WpnTab[plp->wpnr_no].seno0 != 0) 
			{
				CallPlayerWeaponSeEx((NJS_POINT3*)&e_ep->mlwP->owP[v1].mtx[12], WpnTab[plp->wpnr_no].seno0, v8);
			}
			
			bhSetGunFire(e_ep, v3, v1, v2, v6);
		}

		break;
	case 2:
		if (v2 == 0) 
		{
			bhSetGunFire(plp, plp->wpnr_no, 13, v2, v6);
		} 
		else 
		{
			bhSetGunFire(plp, plp->wpnr_no, 9, v2, v6);
		}

		break;
	case 3:
		enep = &rom->enep[v7];
		e_ep = &ene[enep->wrk_no];

		if (v2 == 0) 
		{
			bhSetGunFire(e_ep, v3, v1, v2, v6);
		} 
		else
		{
			bhSetGunFire(e_ep, v3, v1, v2, v6);
		}

		break;
    }

    return 1;
}

// 100% matching!
unsigned int bhYakkyouSet()
{
	int v0, v1, v2, v3, v4, v5, v6, v7;
	ETTY_WORK* enep; // not from DWARF
    BH_PWORK* e_ep;
    
    bhScePtr++;
	
    v0 = *bhScePtr;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    v7 = *bhScePtr;

    bhScePtr++;

    v5 = *bhScePtr;

    bhScePtr++;
    
    if ((v7 & 0x2)) 
	{
        v5 = -v5;
    }

    v6 = 182.04445f * v5;
    
    switch (v0)
	{
	case 0:
		if (v2 == 0) 
		{
			bhSetYakkyou(plp, plp->wpnr_no, 13, v2, v6);
		} 
		else 
		{
			bhSetYakkyou(plp, plp->wpnr_no, 9, v2, v6);
		}

		break;
	case 1:
		enep = &rom->enep[v4];
		e_ep = &ene[enep->wrk_no];

		if (v2 == 0) 
		{
			bhSetYakkyou(e_ep, v3, v1, v2, v6);
		} 
		else 
		{
			bhSetYakkyou(e_ep, v3, v1, v2, v6);
		}

		break;
    }

    return 1;
}

// 100% matching!
unsigned int bhFadeSet()
{
	int v0, v1, v2, v3, v4;

	bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;
    
    bhSetScreenFade(v3 | ((v2 << 8) | ((v0 << 24) | (v1 << 16))), v4);
 
    return 1;
}

// 100% matching! 
unsigned int bhRoomCaseNo()
{
	int v0;

	bhScePtr++;

	v0 = *bhScePtr;

	bhScePtr++;

	sys->rcase = v0;
	
	return 1;
}

// 100% matching! 
unsigned int bhFrameCheck()
{
	int v0, v1;
	unsigned int v2, v3;
	int v4, v5;
	O_WRK* e_ip;     // not from DWARF
    ETTY_WORK* enep; // not from DWARF
    BH_PWORK* e_ep;  // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;  

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;

    v4 = v3 << 16;
    
    if (v2 != 0) 
	{
    	v4 += 32767 + 1;
    }
    
    switch (v0) 
	{
	case 0:
		v5 = plp->frm_no;
		break;
	case 1:
		enep = &rom->enep[v1];
		e_ep = &ene[enep->wrk_no];

		v5 = e_ep->frm_no;
		break;
	case 2:
		e_ip = &sys->obwp[v1];

		v5 = e_ip->frm_no;
		break;
    }
    
    if (v5 >= v4)
	{
		return 0;
	}

	return 1;
}

// 100% matching!
unsigned int bhCamInfoSet()
{
	unsigned int v0, v1;
	CUT_WORK* cp;

	bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
    
    cp = &rom->cutp[v1];
    
    if (v0 == 0) 
	{
        cp->flg |= 0x1;
    } 
	else 
	{
        cp->flg &= ~0x1;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhMaskSet()
{
	int v1, v2;
	int v0;          // not from DWARF
	ETTY_WORK* enep; // not from DWARF
    BH_PWORK* e_ep;  // not from DWARF

	bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    enep = &rom->enep[v1];
    e_ep = &ene[enep->wrk_no];

    bhSetMask(e_ep, v2, 0);
    
    return 1;
}

// 100% matching!
unsigned int bhLipSet()
{
	int v0, v1, v2;
	BH_PWORK* pp;
	ETTY_WORK* enep; // not from DWARF

	bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    enep = &rom->enep[v1];
    pp = &ene[enep->wrk_no];
    
    ((int*)pp->exp0)[4] = v0;
    
    bhSetLip(pp, v2);
    
    return 1;
}

// 100% matching!
unsigned int bhMaskStart()
{
	int v1;
	unsigned int v2;
	BH_PWORK* pp;
	int v0;          // not from DWARF
	ETTY_WORK* enep; // not from DWARF
	
	bhScePtr++;
    
	v0 = *bhScePtr;
    
	bhScePtr++;
    
	v1 = *bhScePtr;
    
	bhScePtr++;
    
	v2 = *bhScePtr;

    bhScePtr++;

    enep = &rom->enep[v1];
    pp = &ene[enep->wrk_no];
    
    if (v2 == 0) 
	{
        ((int*)pp->exp0)[0] |= 0x1;
    } 
	else 
	{
        ((int*)pp->exp0)[0] &= ~0x1;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhLipStart()
{
	int v1;
	unsigned int v2;
	BH_PWORK* pp;
	int v0;          // not from DWARF
	ETTY_WORK* enep; // not from DWARF
	
	bhScePtr++;
    
	v0 = *bhScePtr;
    
	bhScePtr++;
    
	v1 = *bhScePtr;
    
	bhScePtr++;
    
	v2 = *bhScePtr;

    bhScePtr++;

    enep = &rom->enep[v1];
    pp = &ene[enep->wrk_no];
    
    if (v2 == 0) 
	{
        ((int*)pp->exp0)[0] |= 0x4;
    } 
	else 
	{
        ((int*)pp->exp0)[0] &= ~0x4;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhMutekiSetPl()
{
	int v0;

	bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;
    
    if (v0 == 0) 
	{
        plp->flg &= ~0x4;
    } 
	else 
	{
        plp->flg |= 0x4;
    }

    return 1;
}

// 100% matching!
unsigned int bhLookGsetPlStart()
{
	int v1;

	bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;
    
    ((int*)plp->exp1)[0] |= 0x18;

    ((int*)plp->exp1)[16] = 1;
    
    if ((v1 & 0x1)) 
	{
        ((float*)plp->exp1)[18] = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        ((float*)plp->exp1)[18] = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x2)) 
	{
        ((float*)plp->exp1)[19] = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else
	{
        ((float*)plp->exp1)[19] = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x4)) 
	{
        ((float*)plp->exp1)[20] = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else
	{
        ((float*)plp->exp1)[20] = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;

    return 1;
}

// 100% matching!
unsigned int bhLookGsetPlStop()
{
	int* v0; // not from DWARF

	bhScePtr += 2;

	v0 = (int*)plp->exp1;
	
	*v0 &= ~0x18;

	return 1;
}

// 100% matching!
unsigned int bhSoundFadeOut() 
{
    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhDefModelSet()
{
    int v0, v1;
	unsigned int v2, v3;
    BH_PWORK* epw;
    ETTY_WORK* e_enep; // not from DWARF
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v3 = *bhScePtr;
    
    bhScePtr += 2;
    
    switch (v0)
    {                          
    case 0: 
        epw = plp;
        break;
    case 1:
        e_enep = &rom->enep[v1];
        epw = &ene[e_enep->wrk_no];
        break;
    case 2:
        epw = (BH_PWORK*)&sys->obwp[v1];
        break; 
    }
    
    if (v3 == 0)
    {
        epw->mlwP->objP[v2].evalflags |= 0x8;
    } 
    else
    {
        epw->mlwP->objP[v2].evalflags &= ~0x8; 
    }
    
    return 1;
}

// 100% matching!
unsigned int bhItmAspdSet()
{
	unsigned int v0, v1;
	O_WRK* op; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
    
    op = &sys->itwp[v0];

    op->aspd = v1;
    
    return 1;
}

// 100% matching!
unsigned int bhEffDispSet()
{
	unsigned int v0, v1;
	O_WRK* e_ep;

	bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
    
    e_ep = &eff[sys->efid[v0]];

    if (v1 == 0) 
	{
        e_ep->stflg |= 0x1000000;
    } 
	else 
	{
        e_ep->stflg &= ~0x1000000;
    }

    return 1;
}

// 100% matching!
unsigned int bhEffAmbSet()
{
	unsigned int v0, v1, v2, v3;
    
    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr += 2;
    
    rom->amb_r[v3] = 0.1f * v0;
    rom->amb_g[v3] = 0.1f * v1;
    rom->amb_b[v3] = 0.1f * v2;

    return 1;
}

// 100% matching!
unsigned int bhObjLinkSetObjEne()
{
	int v0, v1;
    BH_PWORK* e_ep;
	int v2;          // not from DWARF
    ETTY_WORK* enep; // not from DWARF
    
    bhScePtr++;
    
    v0 = *bhScePtr;    
    
    bhScePtr++; 
    
    v1 = *bhScePtr;

    enep = &rom->enep[v1];

    e_ep = (BH_PWORK*)&ene[enep->wrk_no];
    
    e_ep->lkwkp = (unsigned char*)&sys->obwp[v0]; 
    
    bhScePtr++; 
    
    v2 = *bhScePtr;
    
    e_ep->lkono = v2;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    if (v2 == 0)
    {
        e_ep->flg |= 0x80;
    } 
    else 
    {
        e_ep->flg &= ~0x80;
    }
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
 
    if ((v2 & 0x1)) 
    {
        e_ep->lox = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        e_ep->lox = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;

    if ((v2 & 0x2))
    {
        e_ep->loy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        e_ep->loy = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    if ((v2 & 0x4)) 
    {
        e_ep->loz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        e_ep->loz = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching! 
unsigned int bhObjLinkSetObjItem()
{
	int v1;
	int v0, v2;      // not from DWARF
    
    bhScePtr++;
    
    v0 = *bhScePtr;    
    
    bhScePtr++; 
    
    v1 = *bhScePtr;
    
    sys->itwp[v1].lkwkp = (unsigned char*)&sys->obwp[v0]; 
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    sys->itwp[v1].lkono = v2;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    if (v2 == 0)
    {
        sys->itwp[v1].flg |= 0x80;
    } 
    else 
    {
        sys->itwp[v1].flg &= ~0x80;
    }
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
 
    if ((v2 & 0x1)) 
    {
        sys->itwp[v1].lox = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        sys->itwp[v1].lox = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;

    if ((v2 & 0x2))
    {
        sys->itwp[v1].loy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        sys->itwp[v1].loy = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    if ((v2 & 0x4)) 
    {
        sys->itwp[v1].loz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        sys->itwp[v1].loz = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching! 
unsigned int bhObjLinkSetEneItem()
{
	int v1;
    int v0, v2;      // not from DWARF
    BH_PWORK* e_ep;  // not from DWARF
    ETTY_WORK* enep; // not from DWARF
    
    bhScePtr++;
    
    v0 = *bhScePtr;    
    
    bhScePtr++; 
    
    v1 = *bhScePtr;
   
    enep = &rom->enep[v0];
    e_ep = &ene[enep->wrk_no];
    
    sys->itwp[v1].lkwkp = (unsigned char*)e_ep;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    sys->itwp[v1].lkono = v2;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    if (v2 == 0)
    {
        sys->itwp[v1].flg |= 0x80;
    } 
    else 
    {
        sys->itwp[v1].flg &= ~0x80;
    }
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
 
    if ((v2 & 0x1)) 
    {
        sys->itwp[v1].lox = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        sys->itwp[v1].lox = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;

    if ((v2 & 0x2))
    {
        sys->itwp[v1].loy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        sys->itwp[v1].loy = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    if ((v2 & 0x4)) 
    {
        sys->itwp[v1].loz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        sys->itwp[v1].loz = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhObjLinkSetEneEne()
{
    int v0, v1;
	BH_PWORK* e_ep2;
	int v2;          // not from DWARF
    ETTY_WORK* enep; // not from DWARF
    
    bhScePtr++;
    
    v0 = *bhScePtr;    
    
    bhScePtr++; 
    
    v1 = *bhScePtr;

    enep = &rom->enep[v1]; 

    e_ep2 = &ene[enep->wrk_no];

    enep = &rom->enep[v0]; 
    
    e_ep2->lkwkp = (unsigned char*)&ene[enep->wrk_no]; 
    
    bhScePtr++; 
    
    v2 = *bhScePtr;
    
    e_ep2->lkono = v2;
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    if (v2 == 0)
    {
        e_ep2->flg |= 0x80;
    } 
    else 
    {
        e_ep2->flg &= ~0x80;
    }
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
 
    if ((v2 & 0x1)) 
    {
        e_ep2->lox = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        e_ep2->lox = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;

    if ((v2 & 0x2))
    {
        e_ep2->loy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        e_ep2->loy = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    if ((v2 & 0x4)) 
    {
        e_ep2->loz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else
    {
        e_ep2->loz = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhDelObjSe()
{
	int v0;

	bhScePtr++;

	v0 = *bhScePtr;

	bhScePtr++;

	FreeObjectSe(v0);

	return 1;
}

// 
// Start address: 0x15c930
unsigned int bhLightTypeSet()
{
	//_anon11* lp;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 3764, Address: 0x15c930, Func Offset: 0
	// Line 3780, Address: 0x15c938, Func Offset: 0x8
	// Line 3776, Address: 0x15c93c, Func Offset: 0xc
	// Line 3764, Address: 0x15c944, Func Offset: 0x14
	// Line 3765, Address: 0x15c950, Func Offset: 0x20
	// Line 3766, Address: 0x15c95c, Func Offset: 0x2c
	// Line 3767, Address: 0x15c968, Func Offset: 0x38
	// Line 3776, Address: 0x15c970, Func Offset: 0x40
	// Line 3767, Address: 0x15c97c, Func Offset: 0x4c
	// Line 3768, Address: 0x15c980, Func Offset: 0x50
	// Line 3769, Address: 0x15c98c, Func Offset: 0x5c
	// Line 3770, Address: 0x15c998, Func Offset: 0x68
	// Line 3776, Address: 0x15c9a4, Func Offset: 0x74
	// Line 3777, Address: 0x15c9ac, Func Offset: 0x7c
	// Line 3781, Address: 0x15c9b0, Func Offset: 0x80
	// Func End, Address: 0x15c9b8, Func Offset: 0x88
	scePrintf("bhLightTypeSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15c9c0
unsigned int bhFogColorSet()
{
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 3792, Address: 0x15c9c0, Func Offset: 0
	// Line 3793, Address: 0x15c9d4, Func Offset: 0x14
	// Line 3794, Address: 0x15c9e0, Func Offset: 0x20
	// Line 3795, Address: 0x15c9ec, Func Offset: 0x2c
	// Line 3796, Address: 0x15c9f8, Func Offset: 0x38
	// Line 3797, Address: 0x15ca04, Func Offset: 0x44
	// Line 3798, Address: 0x15ca10, Func Offset: 0x50
	// Line 3799, Address: 0x15ca1c, Func Offset: 0x5c
	// Line 3800, Address: 0x15ca28, Func Offset: 0x68
	// Line 3801, Address: 0x15ca34, Func Offset: 0x74
	// Line 3802, Address: 0x15ca40, Func Offset: 0x80
	// Line 3804, Address: 0x15ca48, Func Offset: 0x88
	// Line 3805, Address: 0x15ca50, Func Offset: 0x90
	// Line 3806, Address: 0x15ca70, Func Offset: 0xb0
	// Line 3805, Address: 0x15ca74, Func Offset: 0xb4
	// Line 3806, Address: 0x15ca80, Func Offset: 0xc0
	// Line 3807, Address: 0x15ca8c, Func Offset: 0xcc
	// Line 3806, Address: 0x15ca90, Func Offset: 0xd0
	// Line 3807, Address: 0x15ca98, Func Offset: 0xd8
	// Line 3808, Address: 0x15caa4, Func Offset: 0xe4
	// Line 3809, Address: 0x15caac, Func Offset: 0xec
	// Line 3810, Address: 0x15cac0, Func Offset: 0x100
	// Line 3809, Address: 0x15cac4, Func Offset: 0x104
	// Line 3810, Address: 0x15cacc, Func Offset: 0x10c
	// Line 3815, Address: 0x15cadc, Func Offset: 0x11c
	// Func End, Address: 0x15cae4, Func Offset: 0x124
	scePrintf("bhFogColorSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15caf0
unsigned int bhEffectSandSet()
{
	//_anon39 pos;
	BH_PWORK* epw;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 3824, Address: 0x15caf0, Func Offset: 0
	// Line 3832, Address: 0x15caf8, Func Offset: 0x8
	// Line 3845, Address: 0x15cb00, Func Offset: 0x10
	// Line 3832, Address: 0x15cb10, Func Offset: 0x20
	// Line 3833, Address: 0x15cb1c, Func Offset: 0x2c
	// Line 3834, Address: 0x15cb28, Func Offset: 0x38
	// Line 3835, Address: 0x15cb34, Func Offset: 0x44
	// Line 3845, Address: 0x15cb3c, Func Offset: 0x4c
	// Line 3835, Address: 0x15cb48, Func Offset: 0x58
	// Line 3836, Address: 0x15cb4c, Func Offset: 0x5c
	// Line 3837, Address: 0x15cb58, Func Offset: 0x68
	// Line 3838, Address: 0x15cb64, Func Offset: 0x74
	// Line 3845, Address: 0x15cb70, Func Offset: 0x80
	// Line 3847, Address: 0x15cb90, Func Offset: 0xa0
	// Line 3849, Address: 0x15cb98, Func Offset: 0xa8
	// Line 3850, Address: 0x15cba4, Func Offset: 0xb4
	// Line 3851, Address: 0x15cc00, Func Offset: 0x110
	// Line 3852, Address: 0x15cc08, Func Offset: 0x118
	// Line 3854, Address: 0x15cc58, Func Offset: 0x168
	// Line 3857, Address: 0x15cc60, Func Offset: 0x170
	// Line 3854, Address: 0x15cc64, Func Offset: 0x174
	// Line 3857, Address: 0x15cc6c, Func Offset: 0x17c
	// Line 3858, Address: 0x15cc74, Func Offset: 0x184
	// Line 3859, Address: 0x15ccd0, Func Offset: 0x1e0
	// Line 3860, Address: 0x15ccd8, Func Offset: 0x1e8
	// Line 3862, Address: 0x15cd28, Func Offset: 0x238
	// Line 3865, Address: 0x15cd30, Func Offset: 0x240
	// Line 3862, Address: 0x15cd34, Func Offset: 0x244
	// Line 3865, Address: 0x15cd3c, Func Offset: 0x24c
	// Line 3866, Address: 0x15cd44, Func Offset: 0x254
	// Line 3867, Address: 0x15cda0, Func Offset: 0x2b0
	// Line 3868, Address: 0x15cda8, Func Offset: 0x2b8
	// Line 3870, Address: 0x15cdf8, Func Offset: 0x308
	// Line 3871, Address: 0x15ce08, Func Offset: 0x318
	// Line 3876, Address: 0x15ce10, Func Offset: 0x320
	// Line 3878, Address: 0x15cec8, Func Offset: 0x3d8
	// Line 3884, Address: 0x15ced0, Func Offset: 0x3e0
	// Line 3878, Address: 0x15ced4, Func Offset: 0x3e4
	// Line 3884, Address: 0x15cedc, Func Offset: 0x3ec
	// Line 3886, Address: 0x15cf90, Func Offset: 0x4a0
	// Line 3892, Address: 0x15cf98, Func Offset: 0x4a8
	// Line 3886, Address: 0x15cf9c, Func Offset: 0x4ac
	// Line 3892, Address: 0x15cfa4, Func Offset: 0x4b4
	// Line 3894, Address: 0x15d058, Func Offset: 0x568
	// Line 3895, Address: 0x15d06c, Func Offset: 0x57c
	// Line 3897, Address: 0x15d078, Func Offset: 0x588
	// Line 3898, Address: 0x15d07c, Func Offset: 0x58c
	// Line 3901, Address: 0x15d088, Func Offset: 0x598
	// Line 3904, Address: 0x15d090, Func Offset: 0x5a0
	// Line 3901, Address: 0x15d094, Func Offset: 0x5a4
	// Line 3902, Address: 0x15d098, Func Offset: 0x5a8
	// Line 3904, Address: 0x15d0a0, Func Offset: 0x5b0
	// Line 3907, Address: 0x15d0a8, Func Offset: 0x5b8
	// Line 3906, Address: 0x15d0ac, Func Offset: 0x5bc
	// Line 3907, Address: 0x15d0b0, Func Offset: 0x5c0
	// Func End, Address: 0x15d0b8, Func Offset: 0x5c8
	scePrintf("bhEffectSandSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15d0c0
unsigned int bhPlItemBlockCk()
{
	int v1;
	int v0;
	unsigned int wicnt;
	unsigned int icnt;
	unsigned int cnt;
	// Line 3919, Address: 0x15d0c0, Func Offset: 0
	// Line 3925, Address: 0x15d0c8, Func Offset: 0x8
	// Line 3919, Address: 0x15d0d4, Func Offset: 0x14
	// Line 3920, Address: 0x15d0e0, Func Offset: 0x20
	// Line 3921, Address: 0x15d0ec, Func Offset: 0x2c
	// Line 3922, Address: 0x15d0f8, Func Offset: 0x38
	// Line 3923, Address: 0x15d104, Func Offset: 0x44
	// Line 3925, Address: 0x15d110, Func Offset: 0x50
	// Line 3926, Address: 0x15d120, Func Offset: 0x60
	// Line 3927, Address: 0x15d15c, Func Offset: 0x9c
	// Line 3928, Address: 0x15d168, Func Offset: 0xa8
	// Line 3929, Address: 0x15d16c, Func Offset: 0xac
	// Line 3930, Address: 0x15d170, Func Offset: 0xb0
	// Line 3938, Address: 0x15d1b0, Func Offset: 0xf0
	// Line 3940, Address: 0x15d1b4, Func Offset: 0xf4
	// Line 3938, Address: 0x15d1b8, Func Offset: 0xf8
	// Line 3941, Address: 0x15d1bc, Func Offset: 0xfc
	// Line 3942, Address: 0x15d1cc, Func Offset: 0x10c
	// Line 3943, Address: 0x15d1d4, Func Offset: 0x114
	// Line 3944, Address: 0x15d210, Func Offset: 0x150
	// Line 3945, Address: 0x15d21c, Func Offset: 0x15c
	// Line 3947, Address: 0x15d220, Func Offset: 0x160
	// Line 3955, Address: 0x15d260, Func Offset: 0x1a0
	// Line 3957, Address: 0x15d264, Func Offset: 0x1a4
	// Line 3955, Address: 0x15d268, Func Offset: 0x1a8
	// Line 3958, Address: 0x15d26c, Func Offset: 0x1ac
	// Line 3959, Address: 0x15d27c, Func Offset: 0x1bc
	// Line 3963, Address: 0x15d280, Func Offset: 0x1c0
	// Line 3964, Address: 0x15d2a8, Func Offset: 0x1e8
	// Line 3965, Address: 0x15d2b4, Func Offset: 0x1f4
	// Line 3966, Address: 0x15d2bc, Func Offset: 0x1fc
	// Line 3967, Address: 0x15d2c8, Func Offset: 0x208
	// Line 3968, Address: 0x15d2d0, Func Offset: 0x210
	// Line 3969, Address: 0x15d2dc, Func Offset: 0x21c
	// Line 3971, Address: 0x15d2e8, Func Offset: 0x228
	// Line 3972, Address: 0x15d2ec, Func Offset: 0x22c
	// Func End, Address: 0x15d2f4, Func Offset: 0x234
	scePrintf("bhPlItemBlockCk - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15d300
unsigned int bhEffBloodSet()
{
	//_anon39 ofp;
	BH_PWORK* epw;
	int v2;
	int v1;
	int v0;
	// Line 3981, Address: 0x15d300, Func Offset: 0
	// Line 3987, Address: 0x15d310, Func Offset: 0x10
	// Line 4000, Address: 0x15d318, Func Offset: 0x18
	// Line 3987, Address: 0x15d328, Func Offset: 0x28
	// Line 3988, Address: 0x15d334, Func Offset: 0x34
	// Line 3989, Address: 0x15d340, Func Offset: 0x40
	// Line 3990, Address: 0x15d34c, Func Offset: 0x4c
	// Line 4000, Address: 0x15d354, Func Offset: 0x54
	// Line 3990, Address: 0x15d360, Func Offset: 0x60
	// Line 3991, Address: 0x15d364, Func Offset: 0x64
	// Line 3992, Address: 0x15d370, Func Offset: 0x70
	// Line 3993, Address: 0x15d37c, Func Offset: 0x7c
	// Line 4000, Address: 0x15d388, Func Offset: 0x88
	// Line 4004, Address: 0x15d394, Func Offset: 0x94
	// Line 4000, Address: 0x15d398, Func Offset: 0x98
	// Line 4004, Address: 0x15d3b0, Func Offset: 0xb0
	// Line 4005, Address: 0x15d3b8, Func Offset: 0xb8
	// Line 4006, Address: 0x15d414, Func Offset: 0x114
	// Line 4007, Address: 0x15d41c, Func Offset: 0x11c
	// Line 4009, Address: 0x15d46c, Func Offset: 0x16c
	// Line 4012, Address: 0x15d474, Func Offset: 0x174
	// Line 4009, Address: 0x15d478, Func Offset: 0x178
	// Line 4012, Address: 0x15d480, Func Offset: 0x180
	// Line 4013, Address: 0x15d488, Func Offset: 0x188
	// Line 4014, Address: 0x15d4e4, Func Offset: 0x1e4
	// Line 4015, Address: 0x15d4ec, Func Offset: 0x1ec
	// Line 4017, Address: 0x15d53c, Func Offset: 0x23c
	// Line 4020, Address: 0x15d544, Func Offset: 0x244
	// Line 4017, Address: 0x15d548, Func Offset: 0x248
	// Line 4020, Address: 0x15d550, Func Offset: 0x250
	// Line 4021, Address: 0x15d558, Func Offset: 0x258
	// Line 4022, Address: 0x15d5b4, Func Offset: 0x2b4
	// Line 4023, Address: 0x15d5bc, Func Offset: 0x2bc
	// Line 4025, Address: 0x15d60c, Func Offset: 0x30c
	// Line 4027, Address: 0x15d620, Func Offset: 0x320
	// Line 4028, Address: 0x15d62c, Func Offset: 0x32c
	// Line 4029, Address: 0x15d638, Func Offset: 0x338
	// Line 4030, Address: 0x15d644, Func Offset: 0x344
	// Line 4034, Address: 0x15d650, Func Offset: 0x350
	// Line 4031, Address: 0x15d654, Func Offset: 0x354
	// Line 4032, Address: 0x15d660, Func Offset: 0x360
	// Line 4034, Address: 0x15d668, Func Offset: 0x368
	// Line 4035, Address: 0x15d670, Func Offset: 0x370
	// Line 4039, Address: 0x15d674, Func Offset: 0x374
	// Line 4043, Address: 0x15d6b4, Func Offset: 0x3b4
	// Line 4042, Address: 0x15d6c0, Func Offset: 0x3c0
	// Line 4043, Address: 0x15d6c4, Func Offset: 0x3c4
	// Func End, Address: 0x15d6cc, Func Offset: 0x3cc
	scePrintf("bhEffBloodSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15d6d0
unsigned int bhEffBloodPoolSet()
{
	int ang;
	//_anon39 gpos;
	BH_PWORK* epw;
	int v2;
	int v1;
	int v0;
	// Line 4051, Address: 0x15d6d0, Func Offset: 0
	// Line 4058, Address: 0x15d6e8, Func Offset: 0x18
	// Line 4071, Address: 0x15d6f0, Func Offset: 0x20
	// Line 4074, Address: 0x15d6f8, Func Offset: 0x28
	// Line 4071, Address: 0x15d6fc, Func Offset: 0x2c
	// Line 4058, Address: 0x15d704, Func Offset: 0x34
	// Line 4059, Address: 0x15d710, Func Offset: 0x40
	// Line 4060, Address: 0x15d71c, Func Offset: 0x4c
	// Line 4061, Address: 0x15d728, Func Offset: 0x58
	// Line 4071, Address: 0x15d730, Func Offset: 0x60
	// Line 4061, Address: 0x15d73c, Func Offset: 0x6c
	// Line 4062, Address: 0x15d740, Func Offset: 0x70
	// Line 4063, Address: 0x15d74c, Func Offset: 0x7c
	// Line 4064, Address: 0x15d758, Func Offset: 0x88
	// Line 4071, Address: 0x15d764, Func Offset: 0x94
	// Line 4074, Address: 0x15d788, Func Offset: 0xb8
	// Line 4076, Address: 0x15d7ac, Func Offset: 0xdc
	// Line 4077, Address: 0x15d7b8, Func Offset: 0xe8
	// Line 4076, Address: 0x15d7bc, Func Offset: 0xec
	// Line 4077, Address: 0x15d7c0, Func Offset: 0xf0
	// Line 4076, Address: 0x15d7c4, Func Offset: 0xf4
	// Line 4077, Address: 0x15d7d4, Func Offset: 0x104
	// Line 4078, Address: 0x15d7e4, Func Offset: 0x114
	// Line 4079, Address: 0x15d7f4, Func Offset: 0x124
	// Line 4083, Address: 0x15d80c, Func Offset: 0x13c
	// Line 4085, Address: 0x15d82c, Func Offset: 0x15c
	// Line 4087, Address: 0x15d834, Func Offset: 0x164
	// Line 4088, Address: 0x15d840, Func Offset: 0x170
	// Line 4087, Address: 0x15d844, Func Offset: 0x174
	// Line 4088, Address: 0x15d848, Func Offset: 0x178
	// Line 4087, Address: 0x15d84c, Func Offset: 0x17c
	// Line 4088, Address: 0x15d850, Func Offset: 0x180
	// Line 4089, Address: 0x15d860, Func Offset: 0x190
	// Line 4090, Address: 0x15d870, Func Offset: 0x1a0
	// Line 4094, Address: 0x15d888, Func Offset: 0x1b8
	// Line 4095, Address: 0x15d8a8, Func Offset: 0x1d8
	// Line 4097, Address: 0x15d8b0, Func Offset: 0x1e0
	// Line 4098, Address: 0x15d8bc, Func Offset: 0x1ec
	// Line 4097, Address: 0x15d8c0, Func Offset: 0x1f0
	// Line 4098, Address: 0x15d8c4, Func Offset: 0x1f4
	// Line 4097, Address: 0x15d8c8, Func Offset: 0x1f8
	// Line 4098, Address: 0x15d8cc, Func Offset: 0x1fc
	// Line 4099, Address: 0x15d8dc, Func Offset: 0x20c
	// Line 4100, Address: 0x15d8ec, Func Offset: 0x21c
	// Line 4101, Address: 0x15d904, Func Offset: 0x234
	// Line 4106, Address: 0x15d924, Func Offset: 0x254
	// Line 4105, Address: 0x15d938, Func Offset: 0x268
	// Line 4106, Address: 0x15d93c, Func Offset: 0x26c
	// Func End, Address: 0x15d944, Func Offset: 0x274
	scePrintf("bhEffBloodPoolSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15d950
unsigned int bhEffBloodPoolSet2()
{
	int ang;
	//_anon39 gpos;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 4115, Address: 0x15d950, Func Offset: 0
	// Line 4122, Address: 0x15d964, Func Offset: 0x14
	// Line 4123, Address: 0x15d978, Func Offset: 0x28
	// Line 4124, Address: 0x15d984, Func Offset: 0x34
	// Line 4127, Address: 0x15d990, Func Offset: 0x40
	// Line 4128, Address: 0x15d99c, Func Offset: 0x4c
	// Line 4129, Address: 0x15d9f8, Func Offset: 0xa8
	// Line 4130, Address: 0x15da00, Func Offset: 0xb0
	// Line 4132, Address: 0x15da50, Func Offset: 0x100
	// Line 4135, Address: 0x15da58, Func Offset: 0x108
	// Line 4132, Address: 0x15da5c, Func Offset: 0x10c
	// Line 4135, Address: 0x15da64, Func Offset: 0x114
	// Line 4136, Address: 0x15da6c, Func Offset: 0x11c
	// Line 4137, Address: 0x15dac8, Func Offset: 0x178
	// Line 4138, Address: 0x15dad0, Func Offset: 0x180
	// Line 4140, Address: 0x15db20, Func Offset: 0x1d0
	// Line 4143, Address: 0x15db28, Func Offset: 0x1d8
	// Line 4140, Address: 0x15db2c, Func Offset: 0x1dc
	// Line 4143, Address: 0x15db34, Func Offset: 0x1e4
	// Line 4144, Address: 0x15db3c, Func Offset: 0x1ec
	// Line 4145, Address: 0x15db98, Func Offset: 0x248
	// Line 4146, Address: 0x15dba0, Func Offset: 0x250
	// Line 4148, Address: 0x15dbf0, Func Offset: 0x2a0
	// Line 4151, Address: 0x15dc04, Func Offset: 0x2b4
	// Line 4152, Address: 0x15dc18, Func Offset: 0x2c8
	// Line 4153, Address: 0x15dc24, Func Offset: 0x2d4
	// Line 4154, Address: 0x15dc30, Func Offset: 0x2e0
	// Line 4159, Address: 0x15dc38, Func Offset: 0x2e8
	// Line 4154, Address: 0x15dc3c, Func Offset: 0x2ec
	// Line 4155, Address: 0x15dc40, Func Offset: 0x2f0
	// Line 4156, Address: 0x15dc4c, Func Offset: 0x2fc
	// Line 4157, Address: 0x15dc58, Func Offset: 0x308
	// Line 4159, Address: 0x15dc60, Func Offset: 0x310
	// Line 4160, Address: 0x15dc68, Func Offset: 0x318
	// Line 4163, Address: 0x15dc6c, Func Offset: 0x31c
	// Line 4165, Address: 0x15dc94, Func Offset: 0x344
	// Line 4167, Address: 0x15dcd0, Func Offset: 0x380
	// Line 4168, Address: 0x15dcdc, Func Offset: 0x38c
	// Line 4167, Address: 0x15dce4, Func Offset: 0x394
	// Line 4168, Address: 0x15dce8, Func Offset: 0x398
	// Line 4170, Address: 0x15dcf4, Func Offset: 0x3a4
	// Line 4168, Address: 0x15dd00, Func Offset: 0x3b0
	// Line 4170, Address: 0x15dd04, Func Offset: 0x3b4
	// Line 4172, Address: 0x15dd18, Func Offset: 0x3c8
	// Line 4174, Address: 0x15dd20, Func Offset: 0x3d0
	// Line 4175, Address: 0x15dd50, Func Offset: 0x400
	// Line 4176, Address: 0x15dd5c, Func Offset: 0x40c
	// Line 4175, Address: 0x15dd64, Func Offset: 0x414
	// Line 4176, Address: 0x15dd68, Func Offset: 0x418
	// Line 4177, Address: 0x15dd74, Func Offset: 0x424
	// Line 4176, Address: 0x15dd80, Func Offset: 0x430
	// Line 4177, Address: 0x15dd84, Func Offset: 0x434
	// Line 4178, Address: 0x15dd98, Func Offset: 0x448
	// Line 4180, Address: 0x15dda0, Func Offset: 0x450
	// Line 4181, Address: 0x15ddd0, Func Offset: 0x480
	// Line 4182, Address: 0x15dddc, Func Offset: 0x48c
	// Line 4181, Address: 0x15dde4, Func Offset: 0x494
	// Line 4182, Address: 0x15dde8, Func Offset: 0x498
	// Line 4183, Address: 0x15ddf4, Func Offset: 0x4a4
	// Line 4182, Address: 0x15de00, Func Offset: 0x4b0
	// Line 4183, Address: 0x15de04, Func Offset: 0x4b4
	// Line 4187, Address: 0x15de18, Func Offset: 0x4c8
	// Line 4186, Address: 0x15de28, Func Offset: 0x4d8
	// Line 4187, Address: 0x15de2c, Func Offset: 0x4dc
	// Func End, Address: 0x15de34, Func Offset: 0x4e4
	scePrintf("bhEffBloodPoolSet2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15de40
unsigned int bhCyoutenHenkeiSet()
{
	BH_PWORK* epw;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 4202, Address: 0x15de40, Func Offset: 0
	// Line 4212, Address: 0x15de48, Func Offset: 0x8
	// Line 4202, Address: 0x15de4c, Func Offset: 0xc
	// Line 4203, Address: 0x15de58, Func Offset: 0x18
	// Line 4204, Address: 0x15de64, Func Offset: 0x24
	// Line 4205, Address: 0x15de70, Func Offset: 0x30
	// Line 4206, Address: 0x15de7c, Func Offset: 0x3c
	// Line 4207, Address: 0x15de88, Func Offset: 0x48
	// Line 4208, Address: 0x15de94, Func Offset: 0x54
	// Line 4209, Address: 0x15dea0, Func Offset: 0x60
	// Line 4210, Address: 0x15deac, Func Offset: 0x6c
	// Line 4212, Address: 0x15deb4, Func Offset: 0x74
	// Line 4214, Address: 0x15decc, Func Offset: 0x8c
	// Line 4215, Address: 0x15ded0, Func Offset: 0x90
	// Line 4221, Address: 0x15ded8, Func Offset: 0x98
	// Line 4226, Address: 0x15df18, Func Offset: 0xd8
	// Line 4229, Address: 0x15df28, Func Offset: 0xe8
	// Line 4239, Address: 0x15df30, Func Offset: 0xf0
	// Line 4226, Address: 0x15df34, Func Offset: 0xf4
	// Line 4228, Address: 0x15df38, Func Offset: 0xf8
	// Line 4229, Address: 0x15df40, Func Offset: 0x100
	// Line 4240, Address: 0x15df44, Func Offset: 0x104
	// Func End, Address: 0x15df4c, Func Offset: 0x10c
	scePrintf("bhCyoutenHenkeiSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15df50
unsigned int bhCyoutenHenkeiStart()
{
	// Line 4251, Address: 0x15df50, Func Offset: 0
	// Line 4258, Address: 0x15df58, Func Offset: 0x8
	// Line 4251, Address: 0x15df60, Func Offset: 0x10
	// Line 4253, Address: 0x15df6c, Func Offset: 0x1c
	// Line 4258, Address: 0x15df80, Func Offset: 0x30
	// Line 4259, Address: 0x15df8c, Func Offset: 0x3c
	// Line 4260, Address: 0x15df90, Func Offset: 0x40
	// Line 4259, Address: 0x15df9c, Func Offset: 0x4c
	// Line 4260, Address: 0x15dfa4, Func Offset: 0x54
	// Line 4263, Address: 0x15dfcc, Func Offset: 0x7c
	// Line 4264, Address: 0x15dfd0, Func Offset: 0x80
	// Func End, Address: 0x15dfd8, Func Offset: 0x88
	scePrintf("bhCyoutenHenkeiStart - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15dfe0
unsigned int bhFixEventCamPly()
{
	int v0;
	// Line 4275, Address: 0x15dfe0, Func Offset: 0
	// Line 4276, Address: 0x15dff4, Func Offset: 0x14
	// Line 4277, Address: 0x15e000, Func Offset: 0x20
	// Line 4279, Address: 0x15e008, Func Offset: 0x28
	// Line 4280, Address: 0x15e010, Func Offset: 0x30
	// Line 4281, Address: 0x15e024, Func Offset: 0x44
	// Line 4282, Address: 0x15e02c, Func Offset: 0x4c
	// Line 4285, Address: 0x15e048, Func Offset: 0x68
	// Func End, Address: 0x15e050, Func Offset: 0x70
	scePrintf("bhFixEventCamPly - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15e050
unsigned int bhObjLinkSetObjObj()
{
	int v4;
	int v1;
	int v0;
	// Line 4300, Address: 0x15e050, Func Offset: 0
	// Line 4311, Address: 0x15e058, Func Offset: 0x8
	// Line 4300, Address: 0x15e060, Func Offset: 0x10
	// Line 4301, Address: 0x15e06c, Func Offset: 0x1c
	// Line 4302, Address: 0x15e078, Func Offset: 0x28
	// Line 4303, Address: 0x15e084, Func Offset: 0x34
	// Line 4311, Address: 0x15e08c, Func Offset: 0x3c
	// Line 4303, Address: 0x15e09c, Func Offset: 0x4c
	// Line 4311, Address: 0x15e0a0, Func Offset: 0x50
	// Line 4304, Address: 0x15e0a4, Func Offset: 0x54
	// Line 4311, Address: 0x15e0b0, Func Offset: 0x60
	// Line 4314, Address: 0x15e0dc, Func Offset: 0x8c
	// Line 4316, Address: 0x15e104, Func Offset: 0xb4
	// Line 4318, Address: 0x15e118, Func Offset: 0xc8
	// Line 4319, Address: 0x15e12c, Func Offset: 0xdc
	// Line 4320, Address: 0x15e14c, Func Offset: 0xfc
	// Line 4321, Address: 0x15e154, Func Offset: 0x104
	// Line 4323, Address: 0x15e17c, Func Offset: 0x12c
	// Line 4324, Address: 0x15e190, Func Offset: 0x140
	// Line 4326, Address: 0x15e19c, Func Offset: 0x14c
	// Line 4329, Address: 0x15e1a8, Func Offset: 0x158
	// Line 4330, Address: 0x15e1b4, Func Offset: 0x164
	// Line 4331, Address: 0x15e224, Func Offset: 0x1d4
	// Line 4332, Address: 0x15e22c, Func Offset: 0x1dc
	// Line 4334, Address: 0x15e290, Func Offset: 0x240
	// Line 4337, Address: 0x15e298, Func Offset: 0x248
	// Line 4334, Address: 0x15e29c, Func Offset: 0x24c
	// Line 4337, Address: 0x15e2a4, Func Offset: 0x254
	// Line 4338, Address: 0x15e2ac, Func Offset: 0x25c
	// Line 4339, Address: 0x15e31c, Func Offset: 0x2cc
	// Line 4340, Address: 0x15e324, Func Offset: 0x2d4
	// Line 4342, Address: 0x15e388, Func Offset: 0x338
	// Line 4345, Address: 0x15e390, Func Offset: 0x340
	// Line 4342, Address: 0x15e394, Func Offset: 0x344
	// Line 4345, Address: 0x15e39c, Func Offset: 0x34c
	// Line 4346, Address: 0x15e3a4, Func Offset: 0x354
	// Line 4347, Address: 0x15e414, Func Offset: 0x3c4
	// Line 4348, Address: 0x15e41c, Func Offset: 0x3cc
	// Line 4350, Address: 0x15e480, Func Offset: 0x430
	// Line 4352, Address: 0x15e488, Func Offset: 0x438
	// Line 4350, Address: 0x15e48c, Func Offset: 0x43c
	// Line 4353, Address: 0x15e494, Func Offset: 0x444
	// Func End, Address: 0x15e49c, Func Offset: 0x44c
	scePrintf("bhObjLinkSetObjObj - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15e4a0
unsigned int bhCamYureSet()
{
	int v1;
	int v0;
	// Line 4361, Address: 0x15e4a0, Func Offset: 0
	// Line 4364, Address: 0x15e4b0, Func Offset: 0x10
	// Line 4365, Address: 0x15e4c4, Func Offset: 0x24
	// Line 4366, Address: 0x15e4d0, Func Offset: 0x30
	// Line 4367, Address: 0x15e4dc, Func Offset: 0x3c
	// Line 4368, Address: 0x15e4e8, Func Offset: 0x48
	// Line 4370, Address: 0x15e4f0, Func Offset: 0x50
	// Line 4372, Address: 0x15e4f8, Func Offset: 0x58
	// Line 4373, Address: 0x15e53c, Func Offset: 0x9c
	// Line 4374, Address: 0x15e568, Func Offset: 0xc8
	// Line 4375, Address: 0x15e594, Func Offset: 0xf4
	// Line 4376, Address: 0x15e59c, Func Offset: 0xfc
	// Line 4377, Address: 0x15e5a4, Func Offset: 0x104
	// Line 4378, Address: 0x15e5ac, Func Offset: 0x10c
	// Line 4381, Address: 0x15e5b4, Func Offset: 0x114
	// Line 4380, Address: 0x15e5c0, Func Offset: 0x120
	// Line 4381, Address: 0x15e5c4, Func Offset: 0x124
	// Func End, Address: 0x15e5cc, Func Offset: 0x12c
	scePrintf("bhCamYureSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15e5d0
unsigned int bhInitCamSet()
{
	// Line 4389, Address: 0x15e5d0, Func Offset: 0
	// Line 4390, Address: 0x15e5d8, Func Offset: 0x8
	// Line 4396, Address: 0x15e5e0, Func Offset: 0x10
	// Line 4398, Address: 0x15e5e4, Func Offset: 0x14
	// Line 4392, Address: 0x15e5e8, Func Offset: 0x18
	// Line 4390, Address: 0x15e5f0, Func Offset: 0x20
	// Line 4392, Address: 0x15e5fc, Func Offset: 0x2c
	// Line 4393, Address: 0x15e600, Func Offset: 0x30
	// Line 4392, Address: 0x15e604, Func Offset: 0x34
	// Line 4393, Address: 0x15e608, Func Offset: 0x38
	// Line 4394, Address: 0x15e610, Func Offset: 0x40
	// Line 4393, Address: 0x15e614, Func Offset: 0x44
	// Line 4394, Address: 0x15e618, Func Offset: 0x48
	// Line 4396, Address: 0x15e620, Func Offset: 0x50
	// Line 4394, Address: 0x15e624, Func Offset: 0x54
	// Line 4396, Address: 0x15e628, Func Offset: 0x58
	// Line 4398, Address: 0x15e634, Func Offset: 0x64
	// Line 4399, Address: 0x15e63c, Func Offset: 0x6c
	// Line 4400, Address: 0x15e644, Func Offset: 0x74
	// Line 4402, Address: 0x15e64c, Func Offset: 0x7c
	// Line 4401, Address: 0x15e650, Func Offset: 0x80
	// Line 4402, Address: 0x15e654, Func Offset: 0x84
	// Func End, Address: 0x15e65c, Func Offset: 0x8c
	scePrintf("bhInitCamSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15e660
unsigned int bhMesDispEndSet()
{
	// Line 4411, Address: 0x15e660, Func Offset: 0
	// Line 4416, Address: 0x15e668, Func Offset: 0x8
	// Line 4417, Address: 0x15e66c, Func Offset: 0xc
	// Line 4412, Address: 0x15e670, Func Offset: 0x10
	// Line 4411, Address: 0x15e678, Func Offset: 0x18
	// Line 4412, Address: 0x15e684, Func Offset: 0x24
	// Line 4413, Address: 0x15e690, Func Offset: 0x30
	// Line 4414, Address: 0x15e6a4, Func Offset: 0x44
	// Line 4415, Address: 0x15e6b8, Func Offset: 0x58
	// Line 4416, Address: 0x15e6cc, Func Offset: 0x6c
	// Line 4418, Address: 0x15e6dc, Func Offset: 0x7c
	// Func End, Address: 0x15e6e4, Func Offset: 0x84
	scePrintf("bhMesDispEndSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15e6f0
unsigned int bhPadCheck()
{
	int v1;
	int v0;
	// Line 4434, Address: 0x15e6f0, Func Offset: 0
	// Line 4444, Address: 0x15e6f8, Func Offset: 0x8
	// Line 4434, Address: 0x15e700, Func Offset: 0x10
	// Line 4435, Address: 0x15e70c, Func Offset: 0x1c
	// Line 4436, Address: 0x15e718, Func Offset: 0x28
	// Line 4437, Address: 0x15e724, Func Offset: 0x34
	// Line 4438, Address: 0x15e730, Func Offset: 0x40
	// Line 4444, Address: 0x15e73c, Func Offset: 0x4c
	// Line 4446, Address: 0x15e74c, Func Offset: 0x5c
	// Line 4448, Address: 0x15e774, Func Offset: 0x84
	// Line 4450, Address: 0x15e7a0, Func Offset: 0xb0
	// Line 4454, Address: 0x15e7a8, Func Offset: 0xb8
	// Line 4456, Address: 0x15e7e0, Func Offset: 0xf0
	// Line 4460, Address: 0x15e7e8, Func Offset: 0xf8
	// Line 4462, Address: 0x15e814, Func Offset: 0x124
	// Line 4464, Address: 0x15e81c, Func Offset: 0x12c
	// Line 4466, Address: 0x15e840, Func Offset: 0x150
	// Line 4470, Address: 0x15e848, Func Offset: 0x158
	// Line 4472, Address: 0x15e868, Func Offset: 0x178
	// Line 4476, Address: 0x15e870, Func Offset: 0x180
	// Line 4478, Address: 0x15e89c, Func Offset: 0x1ac
	// Line 4482, Address: 0x15e8a4, Func Offset: 0x1b4
	// Line 4484, Address: 0x15e8c4, Func Offset: 0x1d4
	// Line 4486, Address: 0x15e8cc, Func Offset: 0x1dc
	// Line 4488, Address: 0x15e8ec, Func Offset: 0x1fc
	// Line 4492, Address: 0x15e8f4, Func Offset: 0x204
	// Line 4494, Address: 0x15e930, Func Offset: 0x240
	// Line 4499, Address: 0x15e938, Func Offset: 0x248
	// Line 4500, Address: 0x15e93c, Func Offset: 0x24c
	// Func End, Address: 0x15e944, Func Offset: 0x254
	scePrintf("bhPadCheck - UNIMPLEMENTED!\n");
}

// 100% matching!
unsigned int bhTFrameCheck()
{
	int v0;

	bhScePtr += 4;

	v0 = *(unsigned short*)bhScePtr;

	bhScePtr += 2;
	
	if (Event_T_timer >= v0) 
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}

// 100% matching! 
unsigned int bhEventTimerClr()
{
	Event_T_timer = 0;

	bhScePtr += 2;

	return 1;
}

// 
// Start address: 0x15e9d0
unsigned int bhCamCheck()
{
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 4542, Address: 0x15e9d0, Func Offset: 0
	// Line 4551, Address: 0x15e9d8, Func Offset: 0x8
	// Line 4542, Address: 0x15e9e0, Func Offset: 0x10
	// Line 4543, Address: 0x15e9ec, Func Offset: 0x1c
	// Line 4544, Address: 0x15e9f8, Func Offset: 0x28
	// Line 4545, Address: 0x15ea04, Func Offset: 0x34
	// Line 4546, Address: 0x15ea10, Func Offset: 0x40
	// Line 4547, Address: 0x15ea1c, Func Offset: 0x4c
	// Line 4548, Address: 0x15ea28, Func Offset: 0x58
	// Line 4549, Address: 0x15ea34, Func Offset: 0x64
	// Line 4551, Address: 0x15ea48, Func Offset: 0x78
	// Line 4552, Address: 0x15ea60, Func Offset: 0x90
	// Line 4553, Address: 0x15ea70, Func Offset: 0xa0
	// Line 4554, Address: 0x15ea84, Func Offset: 0xb4
	// Line 4555, Address: 0x15ea94, Func Offset: 0xc4
	// Line 4556, Address: 0x15ea9c, Func Offset: 0xcc
	// Line 4557, Address: 0x15eaac, Func Offset: 0xdc
	// Line 4560, Address: 0x15eab4, Func Offset: 0xe4
	// Line 4565, Address: 0x15eac0, Func Offset: 0xf0
	// Line 4566, Address: 0x15eac4, Func Offset: 0xf4
	// Func End, Address: 0x15eacc, Func Offset: 0xfc
	scePrintf("bhCamCheck - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15ead0
unsigned int bhRandamSet()
{
	int v1;
	int v0;
	// Line 4574, Address: 0x15ead0, Func Offset: 0
	// Line 4578, Address: 0x15eadc, Func Offset: 0xc
	// Line 4579, Address: 0x15eaf0, Func Offset: 0x20
	// Line 4580, Address: 0x15eafc, Func Offset: 0x2c
	// Line 4582, Address: 0x15eb04, Func Offset: 0x34
	// Line 4583, Address: 0x15eb40, Func Offset: 0x70
	// Line 4584, Address: 0x15eb54, Func Offset: 0x84
	// Line 4583, Address: 0x15eb58, Func Offset: 0x88
	// Line 4585, Address: 0x15eb5c, Func Offset: 0x8c
	// Func End, Address: 0x15eb6c, Func Offset: 0x9c
	scePrintf("bhRandamSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15eb70
unsigned int bhEventSkipSet()
{
	int v0;
	// Line 4596, Address: 0x15eb70, Func Offset: 0
	// Line 4597, Address: 0x15eb84, Func Offset: 0x14
	// Line 4598, Address: 0x15eb90, Func Offset: 0x20
	// Line 4600, Address: 0x15eb98, Func Offset: 0x28
	// Line 4601, Address: 0x15eba0, Func Offset: 0x30
	// Line 4602, Address: 0x15ebb4, Func Offset: 0x44
	// Line 4603, Address: 0x15ebbc, Func Offset: 0x4c
	// Line 4606, Address: 0x15ebd8, Func Offset: 0x68
	// Func End, Address: 0x15ebe0, Func Offset: 0x70
	scePrintf("bhEventSkipSet - UNIMPLEMENTED!\n");
}

// 100% matching!
unsigned int bhDelYakkyou()
{
	bhScePtr += 2;

	bhDeleteYakkyou();

	return 1;
}

// 
// Start address: 0x15ec10
unsigned int bhObjAlphaSet()
{
	//_anon0* op;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 4627, Address: 0x15ec10, Func Offset: 0
	// Line 4631, Address: 0x15ec18, Func Offset: 0x8
	// Line 4645, Address: 0x15ec20, Func Offset: 0x10
	// Line 4631, Address: 0x15ec24, Func Offset: 0x14
	// Line 4632, Address: 0x15ec30, Func Offset: 0x20
	// Line 4633, Address: 0x15ec3c, Func Offset: 0x2c
	// Line 4634, Address: 0x15ec48, Func Offset: 0x38
	// Line 4635, Address: 0x15ec54, Func Offset: 0x44
	// Line 4636, Address: 0x15ec60, Func Offset: 0x50
	// Line 4637, Address: 0x15ec6c, Func Offset: 0x5c
	// Line 4638, Address: 0x15ec78, Func Offset: 0x68
	// Line 4639, Address: 0x15ec84, Func Offset: 0x74
	// Line 4640, Address: 0x15ec90, Func Offset: 0x80
	// Line 4641, Address: 0x15ec9c, Func Offset: 0x8c
	// Line 4642, Address: 0x15eca8, Func Offset: 0x98
	// Line 4643, Address: 0x15ecb4, Func Offset: 0xa4
	// Line 4645, Address: 0x15ecbc, Func Offset: 0xac
	// Line 4650, Address: 0x15ecd8, Func Offset: 0xc8
	// Line 4651, Address: 0x15ed00, Func Offset: 0xf0
	// Line 4656, Address: 0x15ed08, Func Offset: 0xf8
	// Line 4659, Address: 0x15ed34, Func Offset: 0x124
	// Line 4661, Address: 0x15ed3c, Func Offset: 0x12c
	// Line 4660, Address: 0x15ed40, Func Offset: 0x130
	// Line 4661, Address: 0x15ed44, Func Offset: 0x134
	// Func End, Address: 0x15ed4c, Func Offset: 0x13c
	scePrintf("bhObjAlphaSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15ed50
unsigned int bhCyodanSet()
{
	int wp_hef;
	//_anon39 wps;
	//_anon39 ps;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 4671, Address: 0x15ed50, Func Offset: 0
	// Line 4678, Address: 0x15ed58, Func Offset: 0x8
	// Line 4679, Address: 0x15ed6c, Func Offset: 0x1c
	// Line 4680, Address: 0x15ed78, Func Offset: 0x28
	// Line 4681, Address: 0x15ed84, Func Offset: 0x34
	// Line 4682, Address: 0x15ed90, Func Offset: 0x40
	// Line 4683, Address: 0x15ed9c, Func Offset: 0x4c
	// Line 4684, Address: 0x15eda8, Func Offset: 0x58
	// Line 4685, Address: 0x15edb4, Func Offset: 0x64
	// Line 4686, Address: 0x15edc0, Func Offset: 0x70
	// Line 4687, Address: 0x15edcc, Func Offset: 0x7c
	// Line 4688, Address: 0x15edd8, Func Offset: 0x88
	// Line 4691, Address: 0x15ede4, Func Offset: 0x94
	// Line 4692, Address: 0x15edf0, Func Offset: 0xa0
	// Line 4693, Address: 0x15ee4c, Func Offset: 0xfc
	// Line 4694, Address: 0x15ee54, Func Offset: 0x104
	// Line 4696, Address: 0x15eea4, Func Offset: 0x154
	// Line 4699, Address: 0x15eeac, Func Offset: 0x15c
	// Line 4696, Address: 0x15eeb0, Func Offset: 0x160
	// Line 4699, Address: 0x15eeb8, Func Offset: 0x168
	// Line 4700, Address: 0x15eec0, Func Offset: 0x170
	// Line 4701, Address: 0x15ef1c, Func Offset: 0x1cc
	// Line 4702, Address: 0x15ef24, Func Offset: 0x1d4
	// Line 4704, Address: 0x15ef74, Func Offset: 0x224
	// Line 4707, Address: 0x15ef7c, Func Offset: 0x22c
	// Line 4704, Address: 0x15ef80, Func Offset: 0x230
	// Line 4707, Address: 0x15ef88, Func Offset: 0x238
	// Line 4708, Address: 0x15ef90, Func Offset: 0x240
	// Line 4709, Address: 0x15efec, Func Offset: 0x29c
	// Line 4710, Address: 0x15eff4, Func Offset: 0x2a4
	// Line 4712, Address: 0x15f044, Func Offset: 0x2f4
	// Line 4717, Address: 0x15f04c, Func Offset: 0x2fc
	// Line 4712, Address: 0x15f054, Func Offset: 0x304
	// Line 4714, Address: 0x15f060, Func Offset: 0x310
	// Line 4715, Address: 0x15f06c, Func Offset: 0x31c
	// Line 4717, Address: 0x15f078, Func Offset: 0x328
	// Line 4719, Address: 0x15f084, Func Offset: 0x334
	// Line 4717, Address: 0x15f088, Func Offset: 0x338
	// Line 4719, Address: 0x15f08c, Func Offset: 0x33c
	// Line 4717, Address: 0x15f090, Func Offset: 0x340
	// Line 4719, Address: 0x15f09c, Func Offset: 0x34c
	// Line 4720, Address: 0x15f0a0, Func Offset: 0x350
	// Line 4723, Address: 0x15f0a8, Func Offset: 0x358
	// Line 4724, Address: 0x15f0b4, Func Offset: 0x364
	// Line 4725, Address: 0x15f110, Func Offset: 0x3c0
	// Line 4726, Address: 0x15f118, Func Offset: 0x3c8
	// Line 4728, Address: 0x15f168, Func Offset: 0x418
	// Line 4731, Address: 0x15f170, Func Offset: 0x420
	// Line 4728, Address: 0x15f174, Func Offset: 0x424
	// Line 4731, Address: 0x15f17c, Func Offset: 0x42c
	// Line 4732, Address: 0x15f184, Func Offset: 0x434
	// Line 4733, Address: 0x15f1e0, Func Offset: 0x490
	// Line 4734, Address: 0x15f1e8, Func Offset: 0x498
	// Line 4736, Address: 0x15f238, Func Offset: 0x4e8
	// Line 4739, Address: 0x15f240, Func Offset: 0x4f0
	// Line 4736, Address: 0x15f244, Func Offset: 0x4f4
	// Line 4739, Address: 0x15f24c, Func Offset: 0x4fc
	// Line 4740, Address: 0x15f254, Func Offset: 0x504
	// Line 4741, Address: 0x15f2b0, Func Offset: 0x560
	// Line 4742, Address: 0x15f2b8, Func Offset: 0x568
	// Line 4746, Address: 0x15f308, Func Offset: 0x5b8
	// Line 4744, Address: 0x15f320, Func Offset: 0x5d0
	// Line 4746, Address: 0x15f328, Func Offset: 0x5d8
	// Line 4744, Address: 0x15f334, Func Offset: 0x5e4
	// Line 4746, Address: 0x15f33c, Func Offset: 0x5ec
	// Line 4748, Address: 0x15f348, Func Offset: 0x5f8
	// Line 4747, Address: 0x15f34c, Func Offset: 0x5fc
	// Line 4748, Address: 0x15f350, Func Offset: 0x600
	// Func End, Address: 0x15f358, Func Offset: 0x608
	scePrintf("bhCyodanSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15f360
unsigned int bhHEffectSet()
{
	//_anon53 pnt;
	int ay;
	int ax;
	int v3;
	int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 4759, Address: 0x15f360, Func Offset: 0
	// Line 4765, Address: 0x15f374, Func Offset: 0x14
	// Line 4766, Address: 0x15f388, Func Offset: 0x28
	// Line 4767, Address: 0x15f394, Func Offset: 0x34
	// Line 4768, Address: 0x15f3a0, Func Offset: 0x40
	// Line 4769, Address: 0x15f3ac, Func Offset: 0x4c
	// Line 4772, Address: 0x15f3b8, Func Offset: 0x58
	// Line 4773, Address: 0x15f3c4, Func Offset: 0x64
	// Line 4774, Address: 0x15f420, Func Offset: 0xc0
	// Line 4775, Address: 0x15f428, Func Offset: 0xc8
	// Line 4777, Address: 0x15f478, Func Offset: 0x118
	// Line 4780, Address: 0x15f480, Func Offset: 0x120
	// Line 4777, Address: 0x15f484, Func Offset: 0x124
	// Line 4780, Address: 0x15f48c, Func Offset: 0x12c
	// Line 4781, Address: 0x15f494, Func Offset: 0x134
	// Line 4782, Address: 0x15f4f0, Func Offset: 0x190
	// Line 4783, Address: 0x15f4f8, Func Offset: 0x198
	// Line 4785, Address: 0x15f548, Func Offset: 0x1e8
	// Line 4788, Address: 0x15f550, Func Offset: 0x1f0
	// Line 4785, Address: 0x15f554, Func Offset: 0x1f4
	// Line 4788, Address: 0x15f55c, Func Offset: 0x1fc
	// Line 4789, Address: 0x15f564, Func Offset: 0x204
	// Line 4790, Address: 0x15f5c0, Func Offset: 0x260
	// Line 4791, Address: 0x15f5c8, Func Offset: 0x268
	// Line 4793, Address: 0x15f618, Func Offset: 0x2b8
	// Line 4795, Address: 0x15f62c, Func Offset: 0x2cc
	// Line 4796, Address: 0x15f638, Func Offset: 0x2d8
	// Line 4797, Address: 0x15f644, Func Offset: 0x2e4
	// Line 4799, Address: 0x15f64c, Func Offset: 0x2ec
	// Line 4800, Address: 0x15f658, Func Offset: 0x2f8
	// Line 4802, Address: 0x15f65c, Func Offset: 0x2fc
	// Line 4804, Address: 0x15f678, Func Offset: 0x318
	// Line 4802, Address: 0x15f680, Func Offset: 0x320
	// Line 4806, Address: 0x15f684, Func Offset: 0x324
	// Line 4804, Address: 0x15f688, Func Offset: 0x328
	// Line 4805, Address: 0x15f694, Func Offset: 0x334
	// Line 4806, Address: 0x15f69c, Func Offset: 0x33c
	// Line 4807, Address: 0x15f6a4, Func Offset: 0x344
	// Line 4809, Address: 0x15f6a8, Func Offset: 0x348
	// Line 4812, Address: 0x15f6c4, Func Offset: 0x364
	// Line 4813, Address: 0x15f6d8, Func Offset: 0x378
	// Line 4814, Address: 0x15f6e4, Func Offset: 0x384
	// Line 4817, Address: 0x15f6f0, Func Offset: 0x390
	// Line 4818, Address: 0x15f6fc, Func Offset: 0x39c
	// Line 4819, Address: 0x15f758, Func Offset: 0x3f8
	// Line 4820, Address: 0x15f760, Func Offset: 0x400
	// Line 4822, Address: 0x15f7b0, Func Offset: 0x450
	// Line 4825, Address: 0x15f7b8, Func Offset: 0x458
	// Line 4822, Address: 0x15f7bc, Func Offset: 0x45c
	// Line 4825, Address: 0x15f7c4, Func Offset: 0x464
	// Line 4826, Address: 0x15f7cc, Func Offset: 0x46c
	// Line 4827, Address: 0x15f828, Func Offset: 0x4c8
	// Line 4828, Address: 0x15f830, Func Offset: 0x4d0
	// Line 4830, Address: 0x15f880, Func Offset: 0x520
	// Line 4833, Address: 0x15f888, Func Offset: 0x528
	// Line 4830, Address: 0x15f88c, Func Offset: 0x52c
	// Line 4833, Address: 0x15f894, Func Offset: 0x534
	// Line 4834, Address: 0x15f89c, Func Offset: 0x53c
	// Line 4835, Address: 0x15f8f8, Func Offset: 0x598
	// Line 4836, Address: 0x15f900, Func Offset: 0x5a0
	// Line 4843, Address: 0x15f950, Func Offset: 0x5f0
	// Line 4838, Address: 0x15f954, Func Offset: 0x5f4
	// Line 4843, Address: 0x15f95c, Func Offset: 0x5fc
	// Line 4838, Address: 0x15f968, Func Offset: 0x608
	// Line 4839, Address: 0x15f974, Func Offset: 0x614
	// Line 4840, Address: 0x15f980, Func Offset: 0x620
	// Line 4843, Address: 0x15f988, Func Offset: 0x628
	// Line 4845, Address: 0x15f990, Func Offset: 0x630
	// Line 4844, Address: 0x15f9a0, Func Offset: 0x640
	// Line 4845, Address: 0x15f9a4, Func Offset: 0x644
	// Func End, Address: 0x15f9ac, Func Offset: 0x64c
	scePrintf("bhHEffectSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x15f9b0
unsigned int bhObjLinkSetObjPly()
{
	int v1;
	// Line 4857, Address: 0x15f9b0, Func Offset: 0
	// Line 4861, Address: 0x15f9b8, Func Offset: 0x8
	// Line 4857, Address: 0x15f9c0, Func Offset: 0x10
	// Line 4861, Address: 0x15f9c4, Func Offset: 0x14
	// Line 4857, Address: 0x15f9cc, Func Offset: 0x1c
	// Line 4861, Address: 0x15f9d4, Func Offset: 0x24
	// Line 4867, Address: 0x15f9ec, Func Offset: 0x3c
	// Line 4861, Address: 0x15f9f0, Func Offset: 0x40
	// Line 4867, Address: 0x15fa0c, Func Offset: 0x5c
	// Line 4869, Address: 0x15fa10, Func Offset: 0x60
	// Line 4867, Address: 0x15fa18, Func Offset: 0x68
	// Line 4868, Address: 0x15fa24, Func Offset: 0x74
	// Line 4871, Address: 0x15fa30, Func Offset: 0x80
	// Line 4869, Address: 0x15fa34, Func Offset: 0x84
	// Line 4871, Address: 0x15fa38, Func Offset: 0x88
	// Line 4873, Address: 0x15fa48, Func Offset: 0x98
	// Line 4874, Address: 0x15fa5c, Func Offset: 0xac
	// Line 4875, Address: 0x15fa6c, Func Offset: 0xbc
	// Line 4876, Address: 0x15fa74, Func Offset: 0xc4
	// Line 4878, Address: 0x15fa8c, Func Offset: 0xdc
	// Line 4879, Address: 0x15faa0, Func Offset: 0xf0
	// Line 4881, Address: 0x15faac, Func Offset: 0xfc
	// Line 4884, Address: 0x15fab8, Func Offset: 0x108
	// Line 4885, Address: 0x15fac4, Func Offset: 0x114
	// Line 4886, Address: 0x15fb24, Func Offset: 0x174
	// Line 4887, Address: 0x15fb2c, Func Offset: 0x17c
	// Line 4889, Address: 0x15fb80, Func Offset: 0x1d0
	// Line 4892, Address: 0x15fb88, Func Offset: 0x1d8
	// Line 4889, Address: 0x15fb8c, Func Offset: 0x1dc
	// Line 4892, Address: 0x15fb94, Func Offset: 0x1e4
	// Line 4893, Address: 0x15fb9c, Func Offset: 0x1ec
	// Line 4894, Address: 0x15fbfc, Func Offset: 0x24c
	// Line 4895, Address: 0x15fc04, Func Offset: 0x254
	// Line 4897, Address: 0x15fc58, Func Offset: 0x2a8
	// Line 4900, Address: 0x15fc60, Func Offset: 0x2b0
	// Line 4897, Address: 0x15fc64, Func Offset: 0x2b4
	// Line 4900, Address: 0x15fc6c, Func Offset: 0x2bc
	// Line 4901, Address: 0x15fc74, Func Offset: 0x2c4
	// Line 4902, Address: 0x15fcd4, Func Offset: 0x324
	// Line 4903, Address: 0x15fcdc, Func Offset: 0x32c
	// Line 4905, Address: 0x15fd30, Func Offset: 0x380
	// Line 4907, Address: 0x15fd38, Func Offset: 0x388
	// Line 4905, Address: 0x15fd3c, Func Offset: 0x38c
	// Line 4908, Address: 0x15fd44, Func Offset: 0x394
	// Func End, Address: 0x15fd4c, Func Offset: 0x39c
	scePrintf("bhObjLinkSetObjPly - UNIMPLEMENTED!\n");
}

// 100% matching!
unsigned int bhEffPush()
{
	bhScePtr += 2;

	bhPushEffectWork();

	return 1;
}

// 100% matching!
unsigned int bhEffPop()
{
	bhScePtr += 2;

	bhPopEffectWork();

	return 1;
}

// 
// Start address: 0x15fdb0
unsigned int bhAreaSearchObj()
{
	float w_pz2;
	float w_px2;
	float w_pz1;
	float w_px1;
	BH_PWORK* e_workp;
	int v2;
	int v0;
	// Line 4948, Address: 0x15fdb0, Func Offset: 0
	// Line 4953, Address: 0x15fdb8, Func Offset: 0x8
	// Line 4948, Address: 0x15fdbc, Func Offset: 0xc
	// Line 4949, Address: 0x15fdc8, Func Offset: 0x18
	// Line 4950, Address: 0x15fdd4, Func Offset: 0x24
	// Line 4953, Address: 0x15fde0, Func Offset: 0x30
	// Line 4955, Address: 0x15fe1c, Func Offset: 0x6c
	// Line 4956, Address: 0x15fe20, Func Offset: 0x70
	// Line 4962, Address: 0x15fe28, Func Offset: 0x78
	// Line 4963, Address: 0x15fe64, Func Offset: 0xb4
	// Line 4968, Address: 0x15fe6c, Func Offset: 0xbc
	// Line 4969, Address: 0x15fe94, Func Offset: 0xe4
	// Line 4974, Address: 0x15fe9c, Func Offset: 0xec
	// Line 4978, Address: 0x15fec8, Func Offset: 0x118
	// Line 4979, Address: 0x15fedc, Func Offset: 0x12c
	// Line 4980, Address: 0x15fee8, Func Offset: 0x138
	// Line 4984, Address: 0x15fef4, Func Offset: 0x144
	// Line 4985, Address: 0x15ffac, Func Offset: 0x1fc
	// Line 4988, Address: 0x15ffb4, Func Offset: 0x204
	// Line 4985, Address: 0x15ffb8, Func Offset: 0x208
	// Line 4988, Address: 0x15ffc0, Func Offset: 0x210
	// Line 4989, Address: 0x160074, Func Offset: 0x2c4
	// Line 4991, Address: 0x160088, Func Offset: 0x2d8
	// Line 4992, Address: 0x16009c, Func Offset: 0x2ec
	// Line 4993, Address: 0x1600a8, Func Offset: 0x2f8
	// Line 4997, Address: 0x1600b4, Func Offset: 0x304
	// Line 4998, Address: 0x16016c, Func Offset: 0x3bc
	// Line 5001, Address: 0x160174, Func Offset: 0x3c4
	// Line 4998, Address: 0x160178, Func Offset: 0x3c8
	// Line 5001, Address: 0x160180, Func Offset: 0x3d0
	// Line 5002, Address: 0x160234, Func Offset: 0x484
	// Line 5004, Address: 0x160248, Func Offset: 0x498
	// Line 5007, Address: 0x160290, Func Offset: 0x4e0
	// Line 5009, Address: 0x160298, Func Offset: 0x4e8
	// Line 5010, Address: 0x16029c, Func Offset: 0x4ec
	// Func End, Address: 0x1602a4, Func Offset: 0x4f4
	scePrintf("bhAreaSearchObj - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1602b0
unsigned int bhLightParameterCSet()
{
	int v9;
	int v8;
	int v7;
	int v6;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5022, Address: 0x1602b0, Func Offset: 0
	// Line 5045, Address: 0x1602b8, Func Offset: 0x8
	// Line 5057, Address: 0x1602c0, Func Offset: 0x10
	// Line 5045, Address: 0x1602c4, Func Offset: 0x14
	// Line 5022, Address: 0x1602cc, Func Offset: 0x1c
	// Line 5023, Address: 0x1602d8, Func Offset: 0x28
	// Line 5024, Address: 0x1602e4, Func Offset: 0x34
	// Line 5045, Address: 0x1602ec, Func Offset: 0x3c
	// Line 5024, Address: 0x1602f0, Func Offset: 0x40
	// Line 5025, Address: 0x1602f4, Func Offset: 0x44
	// Line 5045, Address: 0x1602fc, Func Offset: 0x4c
	// Line 5025, Address: 0x160300, Func Offset: 0x50
	// Line 5026, Address: 0x160304, Func Offset: 0x54
	// Line 5045, Address: 0x160308, Func Offset: 0x58
	// Line 5026, Address: 0x16030c, Func Offset: 0x5c
	// Line 5027, Address: 0x160314, Func Offset: 0x64
	// Line 5028, Address: 0x160320, Func Offset: 0x70
	// Line 5029, Address: 0x16032c, Func Offset: 0x7c
	// Line 5046, Address: 0x160338, Func Offset: 0x88
	// Line 5047, Address: 0x16033c, Func Offset: 0x8c
	// Line 5046, Address: 0x160344, Func Offset: 0x94
	// Line 5030, Address: 0x160348, Func Offset: 0x98
	// Line 5031, Address: 0x160354, Func Offset: 0xa4
	// Line 5046, Address: 0x16035c, Func Offset: 0xac
	// Line 5031, Address: 0x160360, Func Offset: 0xb0
	// Line 5032, Address: 0x160364, Func Offset: 0xb4
	// Line 5034, Address: 0x160370, Func Offset: 0xc0
	// Line 5035, Address: 0x16037c, Func Offset: 0xcc
	// Line 5036, Address: 0x160388, Func Offset: 0xd8
	// Line 5047, Address: 0x160390, Func Offset: 0xe0
	// Line 5036, Address: 0x160394, Func Offset: 0xe4
	// Line 5047, Address: 0x160398, Func Offset: 0xe8
	// Line 5037, Address: 0x16039c, Func Offset: 0xec
	// Line 5038, Address: 0x1603a8, Func Offset: 0xf8
	// Line 5039, Address: 0x1603b4, Func Offset: 0x104
	// Line 5040, Address: 0x1603c0, Func Offset: 0x110
	// Line 5048, Address: 0x1603cc, Func Offset: 0x11c
	// Line 5049, Address: 0x1603d0, Func Offset: 0x120
	// Line 5048, Address: 0x1603d8, Func Offset: 0x128
	// Line 5041, Address: 0x1603dc, Func Offset: 0x12c
	// Line 5042, Address: 0x1603e8, Func Offset: 0x138
	// Line 5049, Address: 0x1603f0, Func Offset: 0x140
	// Line 5042, Address: 0x1603f4, Func Offset: 0x144
	// Line 5048, Address: 0x1603f8, Func Offset: 0x148
	// Line 5043, Address: 0x1603fc, Func Offset: 0x14c
	// Line 5045, Address: 0x160408, Func Offset: 0x158
	// Line 5046, Address: 0x16040c, Func Offset: 0x15c
	// Line 5047, Address: 0x160418, Func Offset: 0x168
	// Line 5048, Address: 0x160424, Func Offset: 0x174
	// Line 5049, Address: 0x16042c, Func Offset: 0x17c
	// Line 5048, Address: 0x160430, Func Offset: 0x180
	// Line 5049, Address: 0x160434, Func Offset: 0x184
	// Line 5051, Address: 0x16043c, Func Offset: 0x18c
	// Line 5049, Address: 0x160440, Func Offset: 0x190
	// Line 5051, Address: 0x160444, Func Offset: 0x194
	// Line 5052, Address: 0x160448, Func Offset: 0x198
	// Line 5051, Address: 0x160450, Func Offset: 0x1a0
	// Line 5052, Address: 0x16045c, Func Offset: 0x1ac
	// Line 5051, Address: 0x160460, Func Offset: 0x1b0
	// Line 5052, Address: 0x160464, Func Offset: 0x1b4
	// Line 5053, Address: 0x160470, Func Offset: 0x1c0
	// Line 5052, Address: 0x160474, Func Offset: 0x1c4
	// Line 5053, Address: 0x160478, Func Offset: 0x1c8
	// Line 5054, Address: 0x16047c, Func Offset: 0x1cc
	// Line 5053, Address: 0x160484, Func Offset: 0x1d4
	// Line 5054, Address: 0x160490, Func Offset: 0x1e0
	// Line 5053, Address: 0x160498, Func Offset: 0x1e8
	// Line 5054, Address: 0x16049c, Func Offset: 0x1ec
	// Line 5055, Address: 0x1604a4, Func Offset: 0x1f4
	// Line 5054, Address: 0x1604a8, Func Offset: 0x1f8
	// Line 5055, Address: 0x1604ac, Func Offset: 0x1fc
	// Line 5058, Address: 0x1604c4, Func Offset: 0x214
	// Func End, Address: 0x1604cc, Func Offset: 0x21c
	scePrintf("bhLightParameterCSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1604d0
unsigned int bhLightParameterStart()
{
	float frm;
	float ans[3];
	float ips_w[3][4];
	//_anon11* lp;
	unsigned int v1;
	unsigned int v0;
	// Line 5066, Address: 0x1604d0, Func Offset: 0
	// Line 5074, Address: 0x1604f0, Func Offset: 0x20
	// Line 5075, Address: 0x160504, Func Offset: 0x34
	// Line 5076, Address: 0x160510, Func Offset: 0x40
	// Line 5077, Address: 0x16051c, Func Offset: 0x4c
	// Line 5078, Address: 0x160528, Func Offset: 0x58
	// Line 5089, Address: 0x160530, Func Offset: 0x60
	// Line 5093, Address: 0x160574, Func Offset: 0xa4
	// Line 5102, Address: 0x16057c, Func Offset: 0xac
	// Line 5094, Address: 0x160580, Func Offset: 0xb0
	// Line 5102, Address: 0x160584, Func Offset: 0xb4
	// Line 5096, Address: 0x160588, Func Offset: 0xb8
	// Line 5093, Address: 0x16058c, Func Offset: 0xbc
	// Line 5097, Address: 0x160590, Func Offset: 0xc0
	// Line 5103, Address: 0x160594, Func Offset: 0xc4
	// Line 5093, Address: 0x16059c, Func Offset: 0xcc
	// Line 5094, Address: 0x1605a0, Func Offset: 0xd0
	// Line 5103, Address: 0x1605a4, Func Offset: 0xd4
	// Line 5094, Address: 0x1605a8, Func Offset: 0xd8
	// Line 5096, Address: 0x1605ac, Func Offset: 0xdc
	// Line 5097, Address: 0x1605b4, Func Offset: 0xe4
	// Line 5099, Address: 0x1605bc, Func Offset: 0xec
	// Line 5100, Address: 0x1605c4, Func Offset: 0xf4
	// Line 5102, Address: 0x1605cc, Func Offset: 0xfc
	// Line 5103, Address: 0x1605e4, Func Offset: 0x114
	// Line 5104, Address: 0x1605ec, Func Offset: 0x11c
	// Line 5105, Address: 0x1605f0, Func Offset: 0x120
	// Line 5114, Address: 0x1605f4, Func Offset: 0x124
	// Line 5108, Address: 0x1605f8, Func Offset: 0x128
	// Line 5114, Address: 0x1605fc, Func Offset: 0x12c
	// Line 5104, Address: 0x160600, Func Offset: 0x130
	// Line 5105, Address: 0x160604, Func Offset: 0x134
	// Line 5114, Address: 0x160608, Func Offset: 0x138
	// Line 5105, Address: 0x160610, Func Offset: 0x140
	// Line 5106, Address: 0x160614, Func Offset: 0x144
	// Line 5108, Address: 0x16061c, Func Offset: 0x14c
	// Line 5109, Address: 0x160628, Func Offset: 0x158
	// Line 5111, Address: 0x160630, Func Offset: 0x160
	// Line 5112, Address: 0x160638, Func Offset: 0x168
	// Line 5114, Address: 0x16063c, Func Offset: 0x16c
	// Line 5115, Address: 0x160644, Func Offset: 0x174
	// Line 5118, Address: 0x160648, Func Offset: 0x178
	// Line 5115, Address: 0x16064c, Func Offset: 0x17c
	// Line 5116, Address: 0x160650, Func Offset: 0x180
	// Line 5119, Address: 0x160658, Func Offset: 0x188
	// Func End, Address: 0x16067c, Func Offset: 0x1ac
	scePrintf("bhLightParameterStart - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x160680
unsigned int bhInitMidiSlotSet()
{
	int v1;
	int v0;
	// Line 5128, Address: 0x160680, Func Offset: 0
	// Line 5131, Address: 0x160688, Func Offset: 0x8
	// Line 5132, Address: 0x16069c, Func Offset: 0x1c
	// Line 5133, Address: 0x1606a8, Func Offset: 0x28
	// Line 5134, Address: 0x1606b4, Func Offset: 0x34
	// Line 5135, Address: 0x1606c0, Func Offset: 0x40
	// Line 5137, Address: 0x1606c8, Func Offset: 0x48
	// Line 5140, Address: 0x1606d0, Func Offset: 0x50
	// Line 5139, Address: 0x1606d4, Func Offset: 0x54
	// Line 5140, Address: 0x1606d8, Func Offset: 0x58
	// Func End, Address: 0x1606e0, Func Offset: 0x60
	scePrintf("bhInitMidiSlotSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1606e0
unsigned int bh3dSoundFlagSet()
{
	int v2;
	int v1;
	int v0;
	// Line 5148, Address: 0x1606e0, Func Offset: 0
	// Line 5151, Address: 0x1606e8, Func Offset: 0x8
	// Line 5152, Address: 0x1606fc, Func Offset: 0x1c
	// Line 5153, Address: 0x160708, Func Offset: 0x28
	// Line 5154, Address: 0x160714, Func Offset: 0x34
	// Line 5155, Address: 0x160720, Func Offset: 0x40
	// Line 5156, Address: 0x16072c, Func Offset: 0x4c
	// Line 5157, Address: 0x160738, Func Offset: 0x58
	// Line 5159, Address: 0x160740, Func Offset: 0x60
	// Line 5162, Address: 0x160748, Func Offset: 0x68
	// Line 5161, Address: 0x16074c, Func Offset: 0x6c
	// Line 5162, Address: 0x160750, Func Offset: 0x70
	// Func End, Address: 0x160758, Func Offset: 0x78
	scePrintf("bh3dSoundFlagSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x160760
unsigned int bhSoundVolumeSet()
{
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5171, Address: 0x160760, Func Offset: 0
	// Line 5175, Address: 0x160768, Func Offset: 0x8
	// Line 5176, Address: 0x16077c, Func Offset: 0x1c
	// Line 5177, Address: 0x160788, Func Offset: 0x28
	// Line 5178, Address: 0x160794, Func Offset: 0x34
	// Line 5179, Address: 0x1607a0, Func Offset: 0x40
	// Line 5180, Address: 0x1607ac, Func Offset: 0x4c
	// Line 5182, Address: 0x1607b8, Func Offset: 0x58
	// Line 5183, Address: 0x1607c4, Func Offset: 0x64
	// Line 5181, Address: 0x1607cc, Func Offset: 0x6c
	// Line 5183, Address: 0x1607d0, Func Offset: 0x70
	// Line 5185, Address: 0x1607d4, Func Offset: 0x74
	// Line 5186, Address: 0x1607e0, Func Offset: 0x80
	// Line 5184, Address: 0x1607e8, Func Offset: 0x88
	// Line 5186, Address: 0x1607ec, Func Offset: 0x8c
	// Line 5187, Address: 0x1607f0, Func Offset: 0x90
	// Line 5189, Address: 0x1607f8, Func Offset: 0x98
	// Line 5192, Address: 0x160800, Func Offset: 0xa0
	// Line 5191, Address: 0x160804, Func Offset: 0xa4
	// Line 5192, Address: 0x160808, Func Offset: 0xa8
	// Func End, Address: 0x160810, Func Offset: 0xb0
	scePrintf("bhSoundVolumeSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x160810
unsigned int bhLightParameterSet()
{
	//_anon11* lp;
	int v6;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5205, Address: 0x160810, Func Offset: 0
	// Line 5206, Address: 0x160824, Func Offset: 0x14
	// Line 5207, Address: 0x160830, Func Offset: 0x20
	// Line 5208, Address: 0x16083c, Func Offset: 0x2c
	// Line 5209, Address: 0x160848, Func Offset: 0x38
	// Line 5210, Address: 0x160854, Func Offset: 0x44
	// Line 5211, Address: 0x160860, Func Offset: 0x50
	// Line 5212, Address: 0x16086c, Func Offset: 0x5c
	// Line 5213, Address: 0x160878, Func Offset: 0x68
	// Line 5214, Address: 0x160884, Func Offset: 0x74
	// Line 5215, Address: 0x160890, Func Offset: 0x80
	// Line 5216, Address: 0x16089c, Func Offset: 0x8c
	// Line 5217, Address: 0x1608a8, Func Offset: 0x98
	// Line 5218, Address: 0x1608b4, Func Offset: 0xa4
	// Line 5219, Address: 0x1608c0, Func Offset: 0xb0
	// Line 5230, Address: 0x1608c8, Func Offset: 0xb8
	// Line 5233, Address: 0x16090c, Func Offset: 0xfc
	// Line 5234, Address: 0x160910, Func Offset: 0x100
	// Line 5233, Address: 0x160918, Func Offset: 0x108
	// Line 5239, Address: 0x160920, Func Offset: 0x110
	// Line 5233, Address: 0x160924, Func Offset: 0x114
	// Line 5234, Address: 0x160928, Func Offset: 0x118
	// Line 5233, Address: 0x16092c, Func Offset: 0x11c
	// Line 5234, Address: 0x160934, Func Offset: 0x124
	// Line 5235, Address: 0x16093c, Func Offset: 0x12c
	// Line 5236, Address: 0x160940, Func Offset: 0x130
	// Line 5235, Address: 0x160948, Func Offset: 0x138
	// Line 5236, Address: 0x16094c, Func Offset: 0x13c
	// Line 5235, Address: 0x160950, Func Offset: 0x140
	// Line 5236, Address: 0x160954, Func Offset: 0x144
	// Line 5235, Address: 0x160958, Func Offset: 0x148
	// Line 5236, Address: 0x16095c, Func Offset: 0x14c
	// Line 5237, Address: 0x160960, Func Offset: 0x150
	// Line 5240, Address: 0x160978, Func Offset: 0x168
	// Func End, Address: 0x160980, Func Offset: 0x170
	scePrintf("bhLightParameterSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x160980
unsigned int bhEneSeOn()
{
	BH_PWORK* epw;
	//_anon39 pPos;
	unsigned int v3;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 5248, Address: 0x160980, Func Offset: 0
	// Line 5254, Address: 0x160988, Func Offset: 0x8
	// Line 5269, Address: 0x160990, Func Offset: 0x10
	// Line 5275, Address: 0x160998, Func Offset: 0x18
	// Line 5269, Address: 0x16099c, Func Offset: 0x1c
	// Line 5254, Address: 0x1609a4, Func Offset: 0x24
	// Line 5255, Address: 0x1609b0, Func Offset: 0x30
	// Line 5256, Address: 0x1609bc, Func Offset: 0x3c
	// Line 5257, Address: 0x1609c8, Func Offset: 0x48
	// Line 5258, Address: 0x1609d4, Func Offset: 0x54
	// Line 5259, Address: 0x1609e0, Func Offset: 0x60
	// Line 5269, Address: 0x1609e8, Func Offset: 0x68
	// Line 5259, Address: 0x1609f4, Func Offset: 0x74
	// Line 5260, Address: 0x1609f8, Func Offset: 0x78
	// Line 5261, Address: 0x160a04, Func Offset: 0x84
	// Line 5271, Address: 0x160a0c, Func Offset: 0x8c
	// Line 5261, Address: 0x160a1c, Func Offset: 0x9c
	// Line 5262, Address: 0x160a20, Func Offset: 0xa0
	// Line 5271, Address: 0x160a24, Func Offset: 0xa4
	// Line 5262, Address: 0x160a28, Func Offset: 0xa8
	// Line 5269, Address: 0x160a30, Func Offset: 0xb0
	// Line 5271, Address: 0x160a54, Func Offset: 0xd4
	// Line 5272, Address: 0x160a68, Func Offset: 0xe8
	// Line 5273, Address: 0x160a7c, Func Offset: 0xfc
	// Line 5275, Address: 0x160a8c, Func Offset: 0x10c
	// Line 5278, Address: 0x160a94, Func Offset: 0x114
	// Line 5277, Address: 0x160a98, Func Offset: 0x118
	// Line 5278, Address: 0x160a9c, Func Offset: 0x11c
	// Func End, Address: 0x160aa4, Func Offset: 0x124
	scePrintf("bhEneSeOn - UNIMPLEMENTED!\n");
}

// 100% matching!
unsigned int bhEneSeOff()
{
	unsigned char v0;

	bhScePtr++;
	
	v0 = *bhScePtr;

	bhScePtr++;

	StopEnemySe(v0);

	return 1;
}

// 
// Start address: 0x160b00
unsigned int bhWalAtariSet2()
{
	//_anon6* e_walp;
	unsigned int v1;
	// Line 5309, Address: 0x160b00, Func Offset: 0
	// Line 5344, Address: 0x160b08, Func Offset: 0x8
	// Line 5316, Address: 0x160b0c, Func Offset: 0xc
	// Line 5309, Address: 0x160b14, Func Offset: 0x14
	// Line 5317, Address: 0x160b20, Func Offset: 0x20
	// Line 5316, Address: 0x160b28, Func Offset: 0x28
	// Line 5317, Address: 0x160b2c, Func Offset: 0x2c
	// Line 5319, Address: 0x160b30, Func Offset: 0x30
	// Line 5317, Address: 0x160b3c, Func Offset: 0x3c
	// Line 5320, Address: 0x160b44, Func Offset: 0x44
	// Line 5317, Address: 0x160b4c, Func Offset: 0x4c
	// Line 5320, Address: 0x160b54, Func Offset: 0x54
	// Line 5323, Address: 0x160b58, Func Offset: 0x58
	// Line 5321, Address: 0x160b5c, Func Offset: 0x5c
	// Line 5323, Address: 0x160b60, Func Offset: 0x60
	// Line 5324, Address: 0x160b70, Func Offset: 0x70
	// Line 5327, Address: 0x160b7c, Func Offset: 0x7c
	// Line 5325, Address: 0x160b80, Func Offset: 0x80
	// Line 5327, Address: 0x160b84, Func Offset: 0x84
	// Line 5328, Address: 0x160b94, Func Offset: 0x94
	// Line 5331, Address: 0x160ba0, Func Offset: 0xa0
	// Line 5329, Address: 0x160ba4, Func Offset: 0xa4
	// Line 5331, Address: 0x160ba8, Func Offset: 0xa8
	// Line 5332, Address: 0x160bb8, Func Offset: 0xb8
	// Line 5335, Address: 0x160bc4, Func Offset: 0xc4
	// Line 5333, Address: 0x160bc8, Func Offset: 0xc8
	// Line 5335, Address: 0x160bcc, Func Offset: 0xcc
	// Line 5336, Address: 0x160bdc, Func Offset: 0xdc
	// Line 5339, Address: 0x160be8, Func Offset: 0xe8
	// Line 5337, Address: 0x160bec, Func Offset: 0xec
	// Line 5339, Address: 0x160bf0, Func Offset: 0xf0
	// Line 5340, Address: 0x160c00, Func Offset: 0x100
	// Line 5342, Address: 0x160c0c, Func Offset: 0x10c
	// Line 5341, Address: 0x160c10, Func Offset: 0x110
	// Line 5342, Address: 0x160c14, Func Offset: 0x114
	// Line 5345, Address: 0x160c20, Func Offset: 0x120
	// Func End, Address: 0x160c28, Func Offset: 0x128
	scePrintf("bhWalAtariSet2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x160c30
unsigned int bhFlrAtariSet2()
{
	//_anon6* e_flrp;
	unsigned int v1;
	// Line 5359, Address: 0x160c30, Func Offset: 0
	// Line 5394, Address: 0x160c38, Func Offset: 0x8
	// Line 5366, Address: 0x160c3c, Func Offset: 0xc
	// Line 5359, Address: 0x160c44, Func Offset: 0x14
	// Line 5367, Address: 0x160c50, Func Offset: 0x20
	// Line 5366, Address: 0x160c58, Func Offset: 0x28
	// Line 5367, Address: 0x160c5c, Func Offset: 0x2c
	// Line 5369, Address: 0x160c60, Func Offset: 0x30
	// Line 5367, Address: 0x160c6c, Func Offset: 0x3c
	// Line 5370, Address: 0x160c74, Func Offset: 0x44
	// Line 5367, Address: 0x160c7c, Func Offset: 0x4c
	// Line 5370, Address: 0x160c84, Func Offset: 0x54
	// Line 5373, Address: 0x160c88, Func Offset: 0x58
	// Line 5371, Address: 0x160c8c, Func Offset: 0x5c
	// Line 5373, Address: 0x160c90, Func Offset: 0x60
	// Line 5374, Address: 0x160ca0, Func Offset: 0x70
	// Line 5377, Address: 0x160cac, Func Offset: 0x7c
	// Line 5375, Address: 0x160cb0, Func Offset: 0x80
	// Line 5377, Address: 0x160cb4, Func Offset: 0x84
	// Line 5378, Address: 0x160cc4, Func Offset: 0x94
	// Line 5381, Address: 0x160cd0, Func Offset: 0xa0
	// Line 5379, Address: 0x160cd4, Func Offset: 0xa4
	// Line 5381, Address: 0x160cd8, Func Offset: 0xa8
	// Line 5382, Address: 0x160ce8, Func Offset: 0xb8
	// Line 5385, Address: 0x160cf4, Func Offset: 0xc4
	// Line 5383, Address: 0x160cf8, Func Offset: 0xc8
	// Line 5385, Address: 0x160cfc, Func Offset: 0xcc
	// Line 5386, Address: 0x160d0c, Func Offset: 0xdc
	// Line 5389, Address: 0x160d18, Func Offset: 0xe8
	// Line 5387, Address: 0x160d1c, Func Offset: 0xec
	// Line 5389, Address: 0x160d20, Func Offset: 0xf0
	// Line 5390, Address: 0x160d30, Func Offset: 0x100
	// Line 5392, Address: 0x160d3c, Func Offset: 0x10c
	// Line 5391, Address: 0x160d40, Func Offset: 0x110
	// Line 5392, Address: 0x160d44, Func Offset: 0x114
	// Line 5395, Address: 0x160d50, Func Offset: 0x120
	// Func End, Address: 0x160d58, Func Offset: 0x128
	scePrintf("bhFlrAtariSet2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x160d60
unsigned int bhMotionPosSetEnePly()
{
	short ay;
	BH_PWORK* e_workp;
	int v1;
	int v0;
	// Line 5403, Address: 0x160d60, Func Offset: 0
	// Line 5411, Address: 0x160d6c, Func Offset: 0xc
	// Line 5421, Address: 0x160d74, Func Offset: 0x14
	// Line 5411, Address: 0x160d84, Func Offset: 0x24
	// Line 5427, Address: 0x160d88, Func Offset: 0x28
	// Line 5411, Address: 0x160d90, Func Offset: 0x30
	// Line 5412, Address: 0x160d98, Func Offset: 0x38
	// Line 5413, Address: 0x160da4, Func Offset: 0x44
	// Line 5414, Address: 0x160db0, Func Offset: 0x50
	// Line 5421, Address: 0x160db8, Func Offset: 0x58
	// Line 5414, Address: 0x160dc8, Func Offset: 0x68
	// Line 5423, Address: 0x160dcc, Func Offset: 0x6c
	// Line 5421, Address: 0x160dd0, Func Offset: 0x70
	// Line 5423, Address: 0x160dd8, Func Offset: 0x78
	// Line 5431, Address: 0x160de0, Func Offset: 0x80
	// Line 5421, Address: 0x160de4, Func Offset: 0x84
	// Line 5425, Address: 0x160dec, Func Offset: 0x8c
	// Line 5421, Address: 0x160df4, Func Offset: 0x94
	// Line 5425, Address: 0x160e04, Func Offset: 0xa4
	// Line 5427, Address: 0x160e10, Func Offset: 0xb0
	// Line 5428, Address: 0x160e14, Func Offset: 0xb4
	// Line 5427, Address: 0x160e18, Func Offset: 0xb8
	// Line 5428, Address: 0x160e24, Func Offset: 0xc4
	// Line 5431, Address: 0x160e3c, Func Offset: 0xdc
	// Line 5428, Address: 0x160e40, Func Offset: 0xe0
	// Line 5431, Address: 0x160e44, Func Offset: 0xe4
	// Line 5432, Address: 0x160e58, Func Offset: 0xf8
	// Line 5431, Address: 0x160e5c, Func Offset: 0xfc
	// Line 5432, Address: 0x160e60, Func Offset: 0x100
	// Line 5435, Address: 0x160e68, Func Offset: 0x108
	// Line 5432, Address: 0x160e6c, Func Offset: 0x10c
	// Line 5435, Address: 0x160e70, Func Offset: 0x110
	// Line 5437, Address: 0x160e88, Func Offset: 0x128
	// Line 5438, Address: 0x160e98, Func Offset: 0x138
	// Line 5437, Address: 0x160e9c, Func Offset: 0x13c
	// Line 5438, Address: 0x160ea4, Func Offset: 0x144
	// Line 5450, Address: 0x160ebc, Func Offset: 0x15c
	// Line 5438, Address: 0x160ec0, Func Offset: 0x160
	// Line 5442, Address: 0x160ec4, Func Offset: 0x164
	// Line 5450, Address: 0x160ec8, Func Offset: 0x168
	// Line 5442, Address: 0x160ecc, Func Offset: 0x16c
	// Line 5450, Address: 0x160edc, Func Offset: 0x17c
	// Line 5442, Address: 0x160ee0, Func Offset: 0x180
	// Line 5450, Address: 0x160efc, Func Offset: 0x19c
	// Line 5451, Address: 0x160f18, Func Offset: 0x1b8
	// Line 5455, Address: 0x160f24, Func Offset: 0x1c4
	// Line 5451, Address: 0x160f28, Func Offset: 0x1c8
	// Line 5455, Address: 0x160f2c, Func Offset: 0x1cc
	// Line 5458, Address: 0x160f34, Func Offset: 0x1d4
	// Line 5457, Address: 0x160f3c, Func Offset: 0x1dc
	// Line 5458, Address: 0x160f40, Func Offset: 0x1e0
	// Func End, Address: 0x160f48, Func Offset: 0x1e8
	scePrintf("bhMotionPosSetEnePly - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x160f50
unsigned int bhKageSwSet()
{
	//_anon0* e_ip;
	BH_PWORK* e_ep;
	unsigned int v4;
	unsigned int v3;
	unsigned int v2;
	// Line 5475, Address: 0x160f50, Func Offset: 0
	// Line 5483, Address: 0x160f58, Func Offset: 0x8
	// Line 5475, Address: 0x160f5c, Func Offset: 0xc
	// Line 5476, Address: 0x160f68, Func Offset: 0x18
	// Line 5477, Address: 0x160f74, Func Offset: 0x24
	// Line 5478, Address: 0x160f80, Func Offset: 0x30
	// Line 5479, Address: 0x160f8c, Func Offset: 0x3c
	// Line 5480, Address: 0x160f98, Func Offset: 0x48
	// Line 5481, Address: 0x160fa4, Func Offset: 0x54
	// Line 5483, Address: 0x160fac, Func Offset: 0x5c
	// Line 5485, Address: 0x160fdc, Func Offset: 0x8c
	// Line 5486, Address: 0x160fe4, Func Offset: 0x94
	// Line 5487, Address: 0x160ff4, Func Offset: 0xa4
	// Line 5488, Address: 0x160ffc, Func Offset: 0xac
	// Line 5490, Address: 0x161010, Func Offset: 0xc0
	// Line 5496, Address: 0x161018, Func Offset: 0xc8
	// Line 5497, Address: 0x161054, Func Offset: 0x104
	// Line 5498, Address: 0x16105c, Func Offset: 0x10c
	// Line 5499, Address: 0x161064, Func Offset: 0x114
	// Line 5500, Address: 0x16106c, Func Offset: 0x11c
	// Line 5502, Address: 0x161078, Func Offset: 0x128
	// Line 5507, Address: 0x161080, Func Offset: 0x130
	// Line 5508, Address: 0x1610a8, Func Offset: 0x158
	// Line 5509, Address: 0x1610b0, Func Offset: 0x160
	// Line 5510, Address: 0x1610b8, Func Offset: 0x168
	// Line 5511, Address: 0x1610c0, Func Offset: 0x170
	// Line 5513, Address: 0x1610cc, Func Offset: 0x17c
	// Line 5518, Address: 0x1610d4, Func Offset: 0x184
	// Line 5519, Address: 0x1610fc, Func Offset: 0x1ac
	// Line 5520, Address: 0x161104, Func Offset: 0x1b4
	// Line 5521, Address: 0x16110c, Func Offset: 0x1bc
	// Line 5522, Address: 0x161114, Func Offset: 0x1c4
	// Line 5526, Address: 0x161124, Func Offset: 0x1d4
	// Line 5527, Address: 0x161128, Func Offset: 0x1d8
	// Func End, Address: 0x161130, Func Offset: 0x1e0
	scePrintf("bhKageSwSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x161130
unsigned int bhSoundPanSet()
{
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5536, Address: 0x161130, Func Offset: 0
	// Line 5540, Address: 0x161138, Func Offset: 0x8
	// Line 5541, Address: 0x16114c, Func Offset: 0x1c
	// Line 5542, Address: 0x161158, Func Offset: 0x28
	// Line 5543, Address: 0x161164, Func Offset: 0x34
	// Line 5544, Address: 0x161170, Func Offset: 0x40
	// Line 5545, Address: 0x16117c, Func Offset: 0x4c
	// Line 5547, Address: 0x161188, Func Offset: 0x58
	// Line 5548, Address: 0x161194, Func Offset: 0x64
	// Line 5554, Address: 0x16119c, Func Offset: 0x6c
	// Line 5548, Address: 0x1611a0, Func Offset: 0x70
	// Line 5550, Address: 0x1611a4, Func Offset: 0x74
	// Line 5551, Address: 0x1611b0, Func Offset: 0x80
	// Line 5554, Address: 0x1611b8, Func Offset: 0x88
	// Line 5551, Address: 0x1611bc, Func Offset: 0x8c
	// Line 5552, Address: 0x1611c0, Func Offset: 0x90
	// Line 5554, Address: 0x1611c8, Func Offset: 0x98
	// Line 5557, Address: 0x1611d0, Func Offset: 0xa0
	// Line 5556, Address: 0x1611d4, Func Offset: 0xa4
	// Line 5557, Address: 0x1611d8, Func Offset: 0xa8
	// Func End, Address: 0x1611e0, Func Offset: 0xb0
	scePrintf("bhSoundPanSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1611e0
unsigned int bhInitPonySet()
{
	unsigned int v3;
	unsigned int v2;
	// Line 5573, Address: 0x1611e0, Func Offset: 0
	// Line 5579, Address: 0x1611e8, Func Offset: 0x8
	// Line 5573, Address: 0x1611ec, Func Offset: 0xc
	// Line 5574, Address: 0x1611f8, Func Offset: 0x18
	// Line 5575, Address: 0x161204, Func Offset: 0x24
	// Line 5576, Address: 0x161210, Func Offset: 0x30
	// Line 5577, Address: 0x16121c, Func Offset: 0x3c
	// Line 5579, Address: 0x161224, Func Offset: 0x44
	// Line 5581, Address: 0x16123c, Func Offset: 0x5c
	// Line 5582, Address: 0x16124c, Func Offset: 0x6c
	// Line 5586, Address: 0x161254, Func Offset: 0x74
	// Line 5589, Address: 0x1612a0, Func Offset: 0xc0
	// Line 5590, Address: 0x1612a4, Func Offset: 0xc4
	// Func End, Address: 0x1612ac, Func Offset: 0xcc
	scePrintf("bhInitPonySet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1612b0
unsigned int bhCyoutenHenkeiSetEX()
{
	BH_PWORK* epw;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5605, Address: 0x1612b0, Func Offset: 0
	// Line 5617, Address: 0x1612b8, Func Offset: 0x8
	// Line 5605, Address: 0x1612bc, Func Offset: 0xc
	// Line 5606, Address: 0x1612c8, Func Offset: 0x18
	// Line 5607, Address: 0x1612d4, Func Offset: 0x24
	// Line 5608, Address: 0x1612e0, Func Offset: 0x30
	// Line 5609, Address: 0x1612ec, Func Offset: 0x3c
	// Line 5610, Address: 0x1612f8, Func Offset: 0x48
	// Line 5611, Address: 0x161304, Func Offset: 0x54
	// Line 5612, Address: 0x161310, Func Offset: 0x60
	// Line 5613, Address: 0x16131c, Func Offset: 0x6c
	// Line 5614, Address: 0x161328, Func Offset: 0x78
	// Line 5615, Address: 0x161334, Func Offset: 0x84
	// Line 5617, Address: 0x16133c, Func Offset: 0x8c
	// Line 5619, Address: 0x161354, Func Offset: 0xa4
	// Line 5620, Address: 0x161358, Func Offset: 0xa8
	// Line 5626, Address: 0x161360, Func Offset: 0xb0
	// Line 5631, Address: 0x1613a0, Func Offset: 0xf0
	// Line 5639, Address: 0x1613a8, Func Offset: 0xf8
	// Line 5631, Address: 0x1613ac, Func Offset: 0xfc
	// Line 5634, Address: 0x1613b4, Func Offset: 0x104
	// Line 5639, Address: 0x1613bc, Func Offset: 0x10c
	// Line 5642, Address: 0x1613c0, Func Offset: 0x110
	// Line 5631, Address: 0x1613c4, Func Offset: 0x114
	// Line 5633, Address: 0x1613c8, Func Offset: 0x118
	// Line 5634, Address: 0x1613d0, Func Offset: 0x120
	// Line 5638, Address: 0x1613d8, Func Offset: 0x128
	// Line 5643, Address: 0x1613e4, Func Offset: 0x134
	// Func End, Address: 0x1613ec, Func Offset: 0x13c
	scePrintf("bhCyoutenHenkeiSetEX - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1613f0
unsigned int bhCyoutenHenkeiStartEX()
{
	float frm1;
	float frm0;
	int v0;
	// Line 5656, Address: 0x1613f0, Func Offset: 0
	// Line 5662, Address: 0x1613f8, Func Offset: 0x8
	// Line 5667, Address: 0x161400, Func Offset: 0x10
	// Line 5656, Address: 0x161408, Func Offset: 0x18
	// Line 5658, Address: 0x161414, Func Offset: 0x24
	// Line 5659, Address: 0x161420, Func Offset: 0x30
	// Line 5661, Address: 0x161424, Func Offset: 0x34
	// Line 5659, Address: 0x161428, Func Offset: 0x38
	// Line 5661, Address: 0x16142c, Func Offset: 0x3c
	// Line 5659, Address: 0x161430, Func Offset: 0x40
	// Line 5667, Address: 0x161434, Func Offset: 0x44
	// Line 5668, Address: 0x161440, Func Offset: 0x50
	// Line 5669, Address: 0x161444, Func Offset: 0x54
	// Line 5668, Address: 0x161448, Func Offset: 0x58
	// Line 5669, Address: 0x161450, Func Offset: 0x60
	// Line 5672, Address: 0x16147c, Func Offset: 0x8c
	// Func End, Address: 0x161484, Func Offset: 0x94
	scePrintf("bhCyoutenHenkeiStartEX - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x161490
unsigned int bhEasySESet()
{
	BH_PWORK* epw;
	//_anon1 gp;
	int v8;
	int v7;
	int v6;
	int v5;
	int v4;
	// Line 5685, Address: 0x161490, Func Offset: 0
	// Line 5695, Address: 0x161498, Func Offset: 0x8
	// Line 5700, Address: 0x1614a0, Func Offset: 0x10
	// Line 5703, Address: 0x1614a4, Func Offset: 0x14
	// Line 5706, Address: 0x1614a8, Func Offset: 0x18
	// Line 5695, Address: 0x1614ac, Func Offset: 0x1c
	// Line 5696, Address: 0x1614b8, Func Offset: 0x28
	// Line 5709, Address: 0x1614c0, Func Offset: 0x30
	// Line 5724, Address: 0x1614c4, Func Offset: 0x34
	// Line 5696, Address: 0x1614c8, Func Offset: 0x38
	// Line 5697, Address: 0x1614cc, Func Offset: 0x3c
	// Line 5698, Address: 0x1614d8, Func Offset: 0x48
	// Line 5696, Address: 0x1614e0, Func Offset: 0x50
	// Line 5698, Address: 0x1614e4, Func Offset: 0x54
	// Line 5699, Address: 0x1614e8, Func Offset: 0x58
	// Line 5700, Address: 0x1614f4, Func Offset: 0x64
	// Line 5698, Address: 0x1614fc, Func Offset: 0x6c
	// Line 5700, Address: 0x161500, Func Offset: 0x70
	// Line 5702, Address: 0x161504, Func Offset: 0x74
	// Line 5700, Address: 0x161508, Func Offset: 0x78
	// Line 5701, Address: 0x16150c, Func Offset: 0x7c
	// Line 5702, Address: 0x161518, Func Offset: 0x88
	// Line 5703, Address: 0x161528, Func Offset: 0x98
	// Line 5705, Address: 0x161534, Func Offset: 0xa4
	// Line 5703, Address: 0x161538, Func Offset: 0xa8
	// Line 5704, Address: 0x16153c, Func Offset: 0xac
	// Line 5705, Address: 0x161548, Func Offset: 0xb8
	// Line 5706, Address: 0x161558, Func Offset: 0xc8
	// Line 5708, Address: 0x161564, Func Offset: 0xd4
	// Line 5706, Address: 0x161568, Func Offset: 0xd8
	// Line 5707, Address: 0x16156c, Func Offset: 0xdc
	// Line 5708, Address: 0x161578, Func Offset: 0xe8
	// Line 5709, Address: 0x161588, Func Offset: 0xf8
	// Line 5711, Address: 0x161594, Func Offset: 0x104
	// Line 5709, Address: 0x161598, Func Offset: 0x108
	// Line 5710, Address: 0x16159c, Func Offset: 0x10c
	// Line 5711, Address: 0x1615a8, Func Offset: 0x118
	// Line 5712, Address: 0x1615b8, Func Offset: 0x128
	// Line 5713, Address: 0x1615c4, Func Offset: 0x134
	// Line 5714, Address: 0x1615d0, Func Offset: 0x140
	// Line 5712, Address: 0x1615d8, Func Offset: 0x148
	// Line 5714, Address: 0x1615dc, Func Offset: 0x14c
	// Line 5715, Address: 0x1615e0, Func Offset: 0x150
	// Line 5717, Address: 0x1615ec, Func Offset: 0x15c
	// Line 5718, Address: 0x1615f8, Func Offset: 0x168
	// Line 5719, Address: 0x161604, Func Offset: 0x174
	// Line 5720, Address: 0x161610, Func Offset: 0x180
	// Line 5721, Address: 0x16161c, Func Offset: 0x18c
	// Line 5722, Address: 0x161628, Func Offset: 0x198
	// Line 5724, Address: 0x161630, Func Offset: 0x1a0
	// Line 5726, Address: 0x161660, Func Offset: 0x1d0
	// Line 5727, Address: 0x161664, Func Offset: 0x1d4
	// Line 5730, Address: 0x16166c, Func Offset: 0x1dc
	// Line 5731, Address: 0x1616a8, Func Offset: 0x218
	// Line 5733, Address: 0x1616b0, Func Offset: 0x220
	// Line 5734, Address: 0x1616d8, Func Offset: 0x248
	// Line 5736, Address: 0x1616e0, Func Offset: 0x250
	// Line 5766, Address: 0x16170c, Func Offset: 0x27c
	// Line 5773, Address: 0x161714, Func Offset: 0x284
	// Line 5766, Address: 0x161724, Func Offset: 0x294
	// Line 5767, Address: 0x161728, Func Offset: 0x298
	// Line 5768, Address: 0x161734, Func Offset: 0x2a4
	// Line 5769, Address: 0x161740, Func Offset: 0x2b0
	// Line 5768, Address: 0x161748, Func Offset: 0x2b8
	// Line 5769, Address: 0x16174c, Func Offset: 0x2bc
	// Line 5773, Address: 0x161750, Func Offset: 0x2c0
	// Line 5780, Address: 0x161764, Func Offset: 0x2d4
	// Line 5779, Address: 0x161768, Func Offset: 0x2d8
	// Line 5780, Address: 0x16176c, Func Offset: 0x2dc
	// Func End, Address: 0x161774, Func Offset: 0x2e4
	scePrintf("bhEasySESet - UNIMPLEMENTED!\n");
}

// 100% matching!
unsigned int bhSoundFlagReSet()
{
	bhScePtr += 2;

	Reset3dSoundFlag();

	return 1;
}

// 
// Start address: 0x1617b0
unsigned int bhEffUVSet()
{
	//_anon0* e_ep;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5804, Address: 0x1617b0, Func Offset: 0
	// Line 5820, Address: 0x1617b8, Func Offset: 0x8
	// Line 5822, Address: 0x1617c0, Func Offset: 0x10
	// Line 5820, Address: 0x1617c8, Func Offset: 0x18
	// Line 5804, Address: 0x1617d0, Func Offset: 0x20
	// Line 5834, Address: 0x1617d4, Func Offset: 0x24
	// Line 5804, Address: 0x1617d8, Func Offset: 0x28
	// Line 5805, Address: 0x1617e0, Func Offset: 0x30
	// Line 5806, Address: 0x1617ec, Func Offset: 0x3c
	// Line 5820, Address: 0x1617f8, Func Offset: 0x48
	// Line 5807, Address: 0x161800, Func Offset: 0x50
	// Line 5808, Address: 0x16180c, Func Offset: 0x5c
	// Line 5822, Address: 0x161810, Func Offset: 0x60
	// Line 5808, Address: 0x161814, Func Offset: 0x64
	// Line 5822, Address: 0x161818, Func Offset: 0x68
	// Line 5808, Address: 0x16181c, Func Offset: 0x6c
	// Line 5809, Address: 0x161820, Func Offset: 0x70
	// Line 5822, Address: 0x161828, Func Offset: 0x78
	// Line 5809, Address: 0x16182c, Func Offset: 0x7c
	// Line 5810, Address: 0x161830, Func Offset: 0x80
	// Line 5811, Address: 0x16183c, Func Offset: 0x8c
	// Line 5812, Address: 0x161848, Func Offset: 0x98
	// Line 5813, Address: 0x161854, Func Offset: 0xa4
	// Line 5825, Address: 0x16185c, Func Offset: 0xac
	// Line 5823, Address: 0x161860, Func Offset: 0xb0
	// Line 5825, Address: 0x161868, Func Offset: 0xb8
	// Line 5813, Address: 0x16186c, Func Offset: 0xbc
	// Line 5814, Address: 0x161870, Func Offset: 0xc0
	// Line 5825, Address: 0x161874, Func Offset: 0xc4
	// Line 5814, Address: 0x161878, Func Offset: 0xc8
	// Line 5820, Address: 0x161880, Func Offset: 0xd0
	// Line 5822, Address: 0x1618a4, Func Offset: 0xf4
	// Line 5823, Address: 0x1618a8, Func Offset: 0xf8
	// Line 5829, Address: 0x1618ac, Func Offset: 0xfc
	// Line 5823, Address: 0x1618b4, Func Offset: 0x104
	// Line 5829, Address: 0x1618b8, Func Offset: 0x108
	// Line 5823, Address: 0x1618bc, Func Offset: 0x10c
	// Line 5825, Address: 0x1618c0, Func Offset: 0x110
	// Line 5826, Address: 0x1618c4, Func Offset: 0x114
	// Line 5828, Address: 0x1618c8, Func Offset: 0x118
	// Line 5829, Address: 0x1618cc, Func Offset: 0x11c
	// Line 5831, Address: 0x1618d4, Func Offset: 0x124
	// Line 5835, Address: 0x1618d8, Func Offset: 0x128
	// Func End, Address: 0x1618e0, Func Offset: 0x130
	scePrintf("bhEffUVSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1618e0
unsigned int bhPlayerChangeSet()
{
	int v0;
	// Line 5846, Address: 0x1618e0, Func Offset: 0
	// Line 5853, Address: 0x1618e8, Func Offset: 0x8
	// Line 5850, Address: 0x1618ec, Func Offset: 0xc
	// Line 5846, Address: 0x1618f4, Func Offset: 0x14
	// Line 5847, Address: 0x161900, Func Offset: 0x20
	// Line 5848, Address: 0x16190c, Func Offset: 0x2c
	// Line 5850, Address: 0x161918, Func Offset: 0x38
	// Line 5851, Address: 0x161924, Func Offset: 0x44
	// Line 5854, Address: 0x161934, Func Offset: 0x54
	// Func End, Address: 0x16193c, Func Offset: 0x5c
	scePrintf("bhPlayerChangeSet - UNIMPLEMENTED!\n");
}

// 100% matching!
unsigned int bhPlayerPoisonCk()
{
	int v0;

	bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;
    
    if ((plp->stflg & 0x200000)) 
    {
        if (v0 == 0) 
        {
            return 1;
        } 
        else 
        {
            return 0;
        }
    }

    if (v0 == 0) 
    { 
        return 0;
    }
    else 
    {
        return 1;
    }
}

// 100% matching!
unsigned int bhAddObjSe()
{
	int v0, v1, v2, v3;
    NJS_POINT3 pPos;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;
    
    if ((v2 & 0x1)) 
    {
        pPos.x = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        pPos.x = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;

    if ((v2 & 0x2)) 
    {
        pPos.y = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        pPos.y = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v2 & 0x4)) 
    {
        pPos.z = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        pPos.z = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;    

    v3 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;
    
    RegistObjectSe(v0, &pPos, v3, v1);

    return 1;
}

// 100% matching!
unsigned int bhRandTest()
{
	int v0;
    unsigned int v1;
    unsigned int v2; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *(unsigned short*)bhScePtr;

    v1 <<= 16;

    bhScePtr += 2;

    v2 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;

    v1 |= v2;
    
    if (v0 == 0) 
    {
        srand(v1);

        bhEtask->addpx = -rand() / -2.1474836E9f;
        
        bhEtask->wpnl_no = *(int*)&bhEtask->addpx;
    } 
    else 
    {
        bhEtask->addpx = -rand() / -2.1474836E9f;
        
        bhEtask->wpnl_no = *(int*)&bhEtask->addpx;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhEvtComSet()
{
	int v0;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;
    
    sys->cb_flg |= 0x400000;

    sys->com_num = v0;
    
    return 1;
}

// 100% matching!
unsigned int bhZombieUpDieCk()
{
	int v0, v1;
    BH_PWORK* e_ep;
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;
    
    enep = &rom->enep[v0];
    e_ep = &ene[enep->wrk_no];

    if ((e_ep->id == 1) && ((((int*)e_ep->exp1)[0] & 0x2)))
    {
        bhFlagSet(4, v1, 0);
    }

    return 1;
}

// 100% matching!
unsigned int bhFacePauseSet()
{
	int v1, v2;
    BH_PWORK* pp;
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr += 2;
    
    enep = &rom->enep[v1];
    pp = &ene[enep->wrk_no];

    if (v2 == 0) 
    {
        ((int*)pp->exp0)[0] |= 0x10;
    } 
    else 
    {
        ((int*)pp->exp0)[0] &= ~0x10;
    }

    return 1;
}

// 100% matching!
unsigned int bhFaceReSet()
{
	int v1;
    BH_PWORK* pp;    // not from DWARF
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;
    
    enep = &rom->enep[v1];
    pp = &ene[enep->wrk_no];

    ((int*)pp->exp0)[0] |= 0x20;

    return 1;
}

// 100% matching!
unsigned int bhEffModeSet()
{
	int v0, v1;
    O_WRK* op; // not from DWARF
    
    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
   
    op = &eff[sys->efid[v0]];

    op->mode1 = v1;
    
    return 1;
}

// 100% matching!
unsigned int bhEnemyHpUp()
{
	int v0, v1;
    BH_PWORK* e_ep;
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;
    
    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
    
    enep = &rom->enep[v0];
    e_ep = &ene[enep->wrk_no];
    
    e_ep->hp = e_ep->hp + ((e_ep->hp / 100) * v1);

    return 1;
}

// 100% matching!
unsigned int bhFaceRep()
{
	int v0, v1;
    BH_PWORK* pp;
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
    
    enep = &rom->enep[v0];
    pp = &ene[enep->wrk_no];
    
    if (v1 == 0) 
    {
        ((int*)pp->exp0)[0] |= 0x2;
    } 
    else 
    {
        ((int*)pp->exp0)[0] &= ~0x2;
    }

    return 1;
}

// 100% matching!
unsigned int bhBGSeOff2()
{
	unsigned int v0;

	bhScePtr++;

	v0 = *bhScePtr;

	bhScePtr++;

	StopBackGroundSe2(v0);

	return 1;
}

// 100% matching!
unsigned int bhBgmOff2()
{
	bhScePtr += 2;

	StopBgm2();

	return 1;
}

// 100% matching!
unsigned int bhBGSeOn2()
{
	unsigned int v0, v1;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    CallBackGroundSe2(v0, v1);
    
    return 1;
}

// 100% matching!
unsigned int bhBgmOn2()
{
    int v0, v1, v2;

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    v2 = -45;
    
    bhScePtr += 2;

    if (v1 != 0)
    {
        v2 = -45;
    }
    
    PlayBgm2(v0, v2);
    
    return 1;
}

// 100% matching!
unsigned int bhMovieCk()
{
	int v0;
    int ret;

    bhScePtr += 2;
    bhScePtr += 2;

    bhScePtr++;
    bhScePtr++;

    v0 = CheckPlayEndMovie();

    if (v0 == 0) 
    {
        ret = 0;
    } 
    else 
    {
        ret = 1;
    }

    return ret;
}

// 100% matching!
unsigned int bhSetItmMotion()
{
    BH_PWORK* ob_ep;
	unsigned char* a0;

	a0 = bhScePtr;

    bhScePtr++;
    bhScePtr++;
    
    ob_ep = (BH_PWORK*)&sys->itwp[*++a0];
    
    if ((ob_ep->mode3 == 1) && ((sys->sp_flg & 0x4))) 
    {
        bhSetMotion(ob_ep, (int)ob_ep->mtn_add, ob_ep->mtn_md, ob_ep->mtn_tp);
    
        bhCalcModel(ob_ep);
    }
    
    return 1;
}

// 100% matching!
unsigned int bhObjAspdSet()
{
	unsigned int v0, v1;
    O_WRK* op; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
   
    op = &sys->obwp[v0];

    op->aspd = v1;
    
    return 1;
}

// 100% matching!
unsigned int bhPuruPuruFlagSet()
{
	unsigned int v0;

	bhScePtr++;

	v0 = *bhScePtr;

	bhScePtr++;
	
	if (v0 == 0) 
	{
		SetEventVibrationMode(1);
	}
	else
	{
		SetEventVibrationMode(0);
	}

	return 1;
}

// 100% matching!
unsigned int bhPuruPuruStart()
{
	unsigned int v0;

	bhScePtr++;

	v0 = *bhScePtr;

	bhScePtr++;

	StartVibrationEx(2, v0);

	return 1;
}

// 100% matching!
unsigned int bhSubMapBusyCk()
{
    unsigned int v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    if (((sys->st_flg & 0x40000)) || ((sys->st_flg & 0x8))) 
    {
        if (v0 != 0)
        {
            return 0;
        }
        else 
        {
            return 1;
        }
    }
    
    if (v0 == 0) 
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

// 100% matching!
unsigned int bhMapSystemOn()
{
	unsigned int v0, v1, v2, v3;

    bhScePtr++;
    
    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr += 2;
    
    sys->mp_prm[0] = v0;
    sys->mp_prm[1] = v1;
    sys->mp_prm[2] = v3;
    sys->mp_prm[3] = v2;

    sys->cb_flg |= 0x10000;

    return 1;
}

// 100% matching! 
unsigned int bhTrapDamageSet()
{
    unsigned int v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    if (v0 == 0) 
    {
        plp->stflg |= 0x1000;
    } 
    else 
    {
        plp->stflg &= ~0x1000;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhEvtLighterFireSet()
{
	unsigned int v0, v1;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
    
    bhSetLighterFire(&sys->obwp[v0], v1);
    
    return 1;
}

// 100% matching!
unsigned int bhObjLinkSetPlyItem()
{
	int v1;
    int v0; // not from DWARF
    
    bhScePtr += 2;
    
    v1 = *bhScePtr;
    
    sys->itwp[v1].lkwkp = (unsigned char*)plp;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    sys->itwp[v1].lkono = v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    if (v0 == 0) 
    {
        sys->itwp[v1].flg |= 0x80;
    } 
    else 
    {
        sys->itwp[v1].flg &= ~0x80;
    }
    
    bhScePtr++;

    v0 = *bhScePtr;
    
    bhScePtr++;

    if ((v0 & 0x1)) 
    {
        sys->itwp[v1].lox = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        sys->itwp[v1].lox = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v0 & 0x2)) 
    {
        sys->itwp[v1].loy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        sys->itwp[v1].loy = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v0 & 0x4)) 
    {
        sys->itwp[v1].loz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    }
    else 
    {
        sys->itwp[v1].loz = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhPlayerKaidanMotion()
{
	unsigned int v0, v1;

	bhScePtr++;

	v0 = *bhScePtr;

	bhScePtr++;

	v1 = *bhScePtr;

	bhScePtr += 2;

	bhKaidanPlayerMotion(v0, v1);
	
	return 1;
}

// 100% matching!
unsigned int bhEneRenderSet()
{
	unsigned int v0, v1;
    BH_PWORK* epw;
    ETTY_WORK* enep; // not from DWARF
    
    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
    
    enep = &rom->enep[v0];
    epw = &ene[enep->wrk_no];
    
    if (v1 == 0) 
    {
        epw->mdflg |= 0x200;
    } 
    else 
    {
        epw->mdflg &= ~0x200;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhBgmOnEx()
{
	int v0, v1, v2;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    v1 *= 10;

    bhScePtr++;

    v2 = *bhScePtr;

    v2 *= -1;

    bhScePtr++;

    PlayBgmEx(v0, v1, v2);

    return 1;
}

// 100% matching!
unsigned int bhBgmOn2Ex()
{
	int v0, v1;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    v1 *= -1;

    bhScePtr += 2;

    PlayBgm2(v0, v1);

    return 1;
}

// 100% matching!
unsigned int bhFogParameterCSet()
{
	int v0, v1, v2, v3, v4, v5, v6, v7;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;

    v5 = *bhScePtr;

    bhScePtr++;

    v6 = *bhScePtr;

    bhScePtr++;

    v7 = *bhScePtr;

    bhScePtr += 2;
    
    bhCetask->e_lgt[0][0] = v0;
    bhCetask->e_lgt[0][1] = v1;
    bhCetask->e_lgt[0][2] = v2;
    bhCetask->e_lgt[0][3] = v3;
    
    bhCetask->e_lgt[1][0] = v4;
    bhCetask->e_lgt[1][1] = v5;
    bhCetask->e_lgt[1][2] = v6;
    bhCetask->e_lgt[1][3] = v7;
    
    return 1;
}

// 100% matching!
unsigned int bhFogParameterStart()
{
	unsigned int v0, v1, v2;
    float ips_w[4][3]; 
    float ans[3]; 
    float frm; 

    bhScePtr += 2;
    
    ips_w[0][0] = bhCetask->e_lgt[1][0];
    ips_w[1][0] = bhCetask->e_lgt[0][0];
    
    ips_w[0][1] = bhCetask->e_lgt[1][1];
    ips_w[1][1] = bhCetask->e_lgt[0][1];
    
    ips_w[0][2] = bhCetask->e_lgt[1][2];
    ips_w[1][2] = bhCetask->e_lgt[0][2];
    
    frm = (1.0f / bhCetask->cnt3) * bhCetask->cnt2;
    
    njLinear(ips_w[0], ans, NULL, frm);

    v0 = ans[0];
    v1 = ans[1];
    v2 = ans[2];
    
    ips_w[0][0] = bhCetask->e_lgt[1][3];
    ips_w[1][0] = bhCetask->e_lgt[0][3];
    
    njLinear(ips_w[0], ans, NULL, frm);
    
    sys->fog_col = (unsigned int)ans[0] | ((v2 << 8) | ((v0 << 24) | (v1 << 16)));

    sys->st_flg |= 0x100000;
    sys->gm_flg |= 0x10;
    
    return 0;
}

// 100% matching!
unsigned int bhEffUVSet2()
{
	int v0, v1, v2, v3, v4;
    NJS_TEXTUREH_VTX* tvp;
    O_WRK* op; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;

    v2 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;

    v3 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;

    v4 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;
    
    op = &eff[sys->efid[v0]];

    tvp = (NJS_TEXTUREH_VTX*)op->pvp;
    
    tvp[0].u = v1 / 512.0f;
    tvp[0].v = v2 / 512.0f;
    
    tvp[1].u = v3 / 512.0f;
    tvp[1].v = v2 / 512.0f;
    
    tvp[2].u = v1 / 512.0f;
    tvp[2].v = v4 / 512.0f;
    
    tvp[3].u = v3 / 512.0f;
    tvp[3].v = v4 / 512.0f;
    
    return 1;
}

// 100% matching!
unsigned int bhBGColorSet()
{
	int v0, v1, v2, v3, v4;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;
    
    sys->gm_flg |= 0x8000;

    rom->bak_col = v3 | ((v2 << 8) | ((v0 << 24) | (v1 << 16)));

    sys->bcl_ct = v4;

    return 1;
}

// 100% matching!
unsigned int bhMovieTimeCk()
{
	unsigned int v1, v2, ret, ret2;
    unsigned int v0; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;

    v2 = *bhScePtr;

    bhScePtr += 2;
    
    ret2 = CheckPlayEndMovie();

    if (ret2 == 0) 
    {
        return 1;
    }
    
    ret = GetTimeMoive();
    
    switch (v2) 
    {
    case 0:
        if (ret == v1) 
        {
             ret = 0; 
        }
        else 
        {
             ret = 1; 
        }

        break;
    case 1:
        if (ret > v1) 
        { 
            ret = 0; 
        }
        else 
        { 
            ret = 1; 
        }

        break;
    case 2:
        if (ret >= v1) 
        { 
            ret = 0; 
        }
        else 
        { 
            ret = 1; 
        }

        break;
    case 3:
        if (ret < v1) 
        { 
            ret = 0; 
        }
        else 
        { 
            ret = 1; 
        }

        break;
    case 4:
        if (ret <= v1) 
        { 
            ret = 0;
        }
        else 
        { 
            ret = 1; 
        }

        break;
    case 5:
        if (ret != v1) 
        { 
            ret = 0; 
        }
        else 
        { 
            ret = 1; 
        }

        break;
    }

    return ret;
}

// 100% matching!
unsigned int bhEffTypeSet()
{
	unsigned int v0, v1;
    O_WRK* op; // not from DWARF

    bhScePtr++;
    
    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;
  
    op = &eff[sys->efid[v0]];

    op->type = v1;
    
    return 1;
}

// 100% matching!
unsigned int bhPlayerPoison2Cr()
{
	bhScePtr += 2;

	sys->ply_stflg[0] &= ~0x200000;

	return 1;
}

// 100% matching! 
unsigned int bhPlyHandChange()
{
    int v1;
    O_WORK* owk;
    int v0, v2; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    sys->obwp[v0].lkwkp = (unsigned char*)plp;
    
    bhScePtr++;

    v1 = *bhScePtr;

    sys->obwp[v1].lkwkp = (unsigned char*)plp;
    
    sys->obwp[v0].lkono = 9;
    sys->obwp[v1].lkono = 13;
    
    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    if (v2 == 0) 
    {
        sys->obwp[v0].stflg &= ~0x1000000;
        sys->obwp[v1].stflg &= ~0x1000000;

        sys->obwp[v0].flg |= 0x80;
        sys->obwp[v1].flg |= 0x80;

        sys->obwp[0].mdflg |= 0x1;
        sys->obwp[1].mdflg |= 0x1;

        if (plp->wpnr_no == 1) 
        {
            bhEtask[1].wpnr_no = 1;
            plp->wpnr_no = 0;

            sys->ply_wno[sys->ply_id] = 0;

            owk = plp->mdl->owP;
            owk += 7;
            owk->flg &= ~0x2;

            owk = plp->mdl->owP;
            owk += 8;
            owk->flg &= ~0x2;

            owk = plp->mdl->owP;
            owk += 9;
            owk->flg &= ~0x2;
        }
    } 
    else 
    {
        sys->obwp[v0].flg &= ~0x80;
        sys->obwp[v1].flg &= ~0x80;

        sys->obwp[0].mdflg &= ~0x1;
        sys->obwp[1].mdflg &= ~0x1;

        sys->obwp[v0].stflg |= 0x1000000;
        sys->obwp[v1].stflg |= 0x1000000;

        if (bhEtask[1].wpnr_no == 1) 
        {
            bhEtask[1].wpnr_no = 0;
            plp->wpnr_no = 1;

            sys->ply_wno[sys->ply_id] = 1;
            
            owk = plp->mdl->owP;
            owk += 7;
            owk->flg |= 0x2;

            owk = plp->mdl->owP;
            owk += 8;
            owk->flg |= 0x2;

            owk = plp->mdl->owP;
            owk += 9;
            owk->flg |= 0x2;
        }
    }
    
    return 1;
}

// 100% matching!
unsigned int bhHEffectSet2()
{
    int v2, v3, v4;
    EF_WORK *eft;
    
    eft = &sys->ef;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;

    eft->type = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;
    
    if ((v2 & 0x1)) 
    {
        eft->px = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        eft->px = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v2 & 0x2)) 
    {
        eft->py = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        eft->py = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v2 & 0x4)) 
    {
        eft->pz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        eft->pz = *(unsigned short*)bhScePtr / 100.0f;
    }
    
    bhScePtr += 2;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    v3 = *bhScePtr;
    
    if ((v2 & 0x1)) 
    {
        v3 = -v3;
    }
    
    eft->ax = v3 * (65536.0f / 360.0f);

    bhScePtr++;

    v3 = *bhScePtr;
    
    if ((v2 & 0x2)) 
    {
        v3 = -v3;
    }
    
    eft->ay = v3 * (65536.0f / 360.0f);
    
    bhScePtr++;
    
    v2 = *bhScePtr;
    
    bhScePtr++;
    
    if ((v2 & 0x1)) 
    {
        eft->sx = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        eft->sx = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v2 & 0x2)) 
    {
        eft->sy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        eft->sy = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v2 & 0x4)) 
    {
        eft->sz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
    else 
    {
        eft->sz = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;

    eft->id = *(unsigned short*)bhScePtr;

    bhScePtr += 2;
    
    eft->flg = 1;

    eft->flr_no = 0;

    eft->mdlver = 0;
    
    bhSetEffectTb(eft, NULL, NULL, v4);
    
    return 1;
}

// 100% matching!
unsigned int bhObjDposCk()
{
	int v0, v1, v2, v3, v4;
	int eay, eay2;
    BH_PWORK *e_ep;
    NJS_CNK_OBJECT *objP;
	ETTY_WORK *enep; // not from DWARF
    O_WRK *op;       // not from DWARF
    
    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;
    
    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;
    
    if (v4 == 0) 
	{
        if ((v1 & 0x2)) 
		{
            if (v2 != 0) 
			{
                v2 -= 360;
            }
        }

        eay = v2 * (65536.0f / 360.0f);
        eay2 = v3 * (65536.0f / 360.0f);
        
        op = &sys->obwp[v0];

        op->ay = (short)op->ay;

        if (eay != (unsigned short)op->ay) 
		{
            if (eay < (unsigned short)op->ay)
			{
                op->ay -= (short)eay2;

                if (eay >= (unsigned short)op->ay) 
				{
                    op->ay = (unsigned short)eay;

                    return 0;
                }

                return 1;
            }

            if ((unsigned short)op->ay < eay) 
			{
                op->ay += (short)eay2;

                if (eay <= (unsigned short)op->ay) 
				{
                    op->ay = (unsigned short)eay;

                    return 0;
                }

                return 1;
            }
        }
    } 
	else 
	{
        if ((v1 & 0x2)) 
		{
            v2 = -v2;
        }

        eay = v2 * (65536.0f / 360.0f); 
		eay = (short)eay;

        eay2 = v3 * (65536.0f / 360.0f);
		eay2 = (short)eay2;
        
        enep = &rom->enep[v0];
        e_ep = &ene[enep->wrk_no];

        objP = e_ep->mdl->objP;
        objP += v4;
        
        objP->ang[0] = (short)objP->ang[0];

        if (eay != objP->ang[0]) 
		{
            if (eay < objP->ang[0]) 
			{
                objP->ang[0] -= eay2;

                if (eay >= objP->ang[0]) 
				{
                    objP->ang[0] = eay;

                    return 0;
                }

                return 1;
            }

            if (objP->ang[0] < eay) 
			{
                objP->ang[0] += eay2;

                if (eay <= objP->ang[0]) 
				{
                    objP->ang[0] = eay;

                    return 0;
                }

                return 1;
            }
        }
    }
    
    return 0;
}

// 100% matching!
unsigned int bhItemGetGet()
{
	int v0, v1, v2;
    
    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;
    
    sys->itm[(v0 * 16) + 2] = v1 << 16;

    if (v1 == 34) 
	{
        sys->itm[(v0 * 16) + 2] += 500;
    }

    switch (v2) 
	{
	case 0:
		sys->itm[v0 * 16] = 2;
		
		if (v1 == 34) 
		{
			sys->ply_wno[v0] = 8;
		}

		break;
	case 2:
		sys->itm[(v0 * 16) + 2] |= 0x8000000;
		
		sys->itm[v0 * 16] = 2;

		if (v1 == 34) 
		{
			sys->ply_wno[v0] = 8;
		}

		break;
    }

    return 1;
}

// 100% matching!
unsigned int bhEtcAtariEnePosSet()
{
	int v0, v1, v2, v3, v4, v5;
    ATR_WORK *e_etcp;
    BH_PWORK *epw;
    POS *e_posp;
    float sw1, sw2;
    unsigned int cnt, cnt2;
	ETTY_WORK *enep; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;

    v5 = *bhScePtr;

    bhScePtr += 2;
    
    enep = &rom->enep[v0];
    epw = &ene[enep->wrk_no];
    
    e_etcp = rom->etcp;
    e_etcp += v1;
    
    e_posp = rom->posp;
    e_posp += v2;
    
    sw2 = njDistanceP2P((NJS_POINT3*)e_posp, (NJS_POINT3*)&epw->mlwP->owP[v5].mtx[12]);

    for (cnt = v2, cnt2 = v2; cnt < v3; cnt++, e_posp++) 
	{
        sw1 = njDistanceP2P((NJS_POINT3*)e_posp, (NJS_POINT3*)&epw->mlwP->owP[v5].mtx[12]);

        if (sw1 < sw2) 
		{
            sw2 = sw1;
            cnt2 = cnt;
        }
    }

    e_posp = rom->posp;
    e_posp += cnt2;
    
    e_etcp->px = e_posp->px - (e_etcp->w / 2.0f);
    e_etcp->py = e_posp->py;
    e_etcp->pz = e_posp->pz - (e_etcp->d / 2.0f);
    
    sys->evt_posno[v4] = cnt2;
    
    return 1;
}

// 100% matching!
unsigned int bhEtcAtariEvtPosSet()
{
    int v0, v1, v3;
    ATR_WORK* e_etcp;
    POS* e_posp;
    BH_PWORK* epw;
	int v2;    // not from DWARF
    O_WRK* op; // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;
    
    e_etcp = rom->etcp;
    e_etcp += v1;

    e_posp = rom->posp;

    e_posp += sys->evt_posno[v0];
    
    e_etcp->px = e_posp->px - (e_etcp->w / 2.0f);
    e_etcp->py = e_posp->py;
    e_etcp->pz = e_posp->pz - (e_etcp->d / 2.0f);
    
    op = &sys->itwp[v3];
    
    op->px = e_posp->px;
    op->py = e_posp->py;
    op->pz = e_posp->pz;
    
    return 1;
}

// 100% matching!
unsigned int bhRoomSoundCase()
{
	int v0;

	bhScePtr++;
	
	v0 = *bhScePtr;

	bhScePtr++;

	SetRoomSoundCaseNo(v0);

	return 1;
}

// 100% matching!
unsigned int bhItemPlToSBox()
{
	unsigned int cnt, cnt2;
    int v0;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;
    
    for (cnt = 12 * 16; cnt < 256; cnt++)
	{
        sys->itm[cnt] = 0;
    }
    
    for (cnt = (v0 * 16) + 2, cnt2 = 12 * 16; cnt < ((v0 * 16) + 16); cnt++, cnt2++) 
	{
        sys->itm[cnt2] = sys->itm[cnt];
        sys->itm[cnt] = 0;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhItemSBoxToIBox()
{
	unsigned int cnt, cnt2;

    bhScePtr += 2;
    
    for (cnt = 4 * 16, cnt2 = 12 * 16; (cnt < (12 * 16)) || (cnt2 < (13 * 16)); cnt++) 
	{
        if (sys->itm[cnt2] == 0) 
		{ 
			break;
		}

        if (sys->itm[cnt] == 0) 
		{
            sys->itm[cnt] = sys->itm[cnt2];
            sys->itm[cnt2] = 0;

            cnt2++;
        }
    }
    
    return 1;
}

// 100% matching!
unsigned int bhGrdPosSet()
{
	unsigned int v1;
    ATR_WORK* e_walp;
	unsigned int v0; // not from DWARF
 
    bhScePtr++;
 
    e_walp = rom->walp;

    e_walp += *bhScePtr;
    
    bhScePtr += 2;

    v1 = *bhScePtr;

    bhScePtr++;
    
    if ((v1 & 0x1)) 
	{
        e_walp->px = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        e_walp->px = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x2)) 
	{
        e_walp->py = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        e_walp->py = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x4)) 
	{
        e_walp->pz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        e_walp->pz = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhGrdPosMoveCSet()
{
	int v0, v1;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;
    
    if ((v0 & 0x1)) 
	{
        bhCetask->e_lgt[0][0] = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        bhCetask->e_lgt[0][0] = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;

    if ((v0 & 0x2)) 
	{
        bhCetask->e_lgt[0][1] = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        bhCetask->e_lgt[0][1] = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v0 & 0x4)) 
	{
        bhCetask->e_lgt[0][2] = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        bhCetask->e_lgt[0][2] = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;
    
    if ((v1 & 0x1)) 
	{
        bhCetask->e_lgt[1][0] = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        bhCetask->e_lgt[1][0] = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x2)) 
	{
        bhCetask->e_lgt[1][1] = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        bhCetask->e_lgt[1][1] = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x4)) 
	{
        bhCetask->e_lgt[1][2] = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    }
	else 
	{
        bhCetask->e_lgt[1][2] = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhGrdPosMoveStart()
{
	ATR_WORK* e_walp;
    float ips_w[4][3]; 
    float ans[3]; 
    
    bhScePtr++;
    
    e_walp = rom->walp;
	
    e_walp += *bhScePtr;

    bhScePtr++;
    
    ips_w[0][0] = bhCetask->e_lgt[1][0];
    ips_w[1][0] = bhCetask->e_lgt[1][0];
    ips_w[2][0] = bhCetask->e_lgt[0][0];
    ips_w[3][0] = bhCetask->e_lgt[0][0];
    
    ips_w[0][1] = bhCetask->e_lgt[1][1];
    ips_w[1][1] = bhCetask->e_lgt[1][1];
    ips_w[2][1] = bhCetask->e_lgt[0][1];
    ips_w[3][1] = bhCetask->e_lgt[0][1];
    
    ips_w[0][2] = bhCetask->e_lgt[1][2];
    ips_w[1][2] = bhCetask->e_lgt[1][2];
    ips_w[2][2] = bhCetask->e_lgt[0][2];
    ips_w[3][2] = bhCetask->e_lgt[0][2];
    
    njOverhauserSpline((float*)ips_w, (float*)ans, NULL, (1.0f / bhCetask->cnt3) * bhCetask->cnt2);
    
    e_walp->px = ans[0];
    e_walp->py = ans[1];
    e_walp->pz = ans[2];
    
    return 0;
}

// 100% matching!
unsigned int bhEvtKill()
{
	unsigned int v0;

	bhScePtr++;
	
	v0 = *bhScePtr;

	bhScePtr++;

	bhEtask[v0].status = 0;

	return 1;
}

// 100% matching!
unsigned int bhReTryPointSet()
{
	bhScePtr += 2;

	bhPushGameData();

	return 1;
}

// 100% matching!
unsigned int bhPlyDposCk()
{
	int v1, v2, v3; 
    int eay, eay2;
    BH_PWORK* e_ep;
	int v0, v4; // not from DWARF
    
    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;
    
    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;

    if (((v1 & 0x2)) && (v2 != 0))
	{
		v2 -= 360;
    }

    eay = v2 * (65536.0f / 360.0f);
    eay2 = v3 * (65536.0f / 360.0f);
    
    e_ep = plp;

    e_ep->ay = (short)e_ep->ay;

    if (eay != (unsigned short)e_ep->ay) 
	{
        if (eay < (unsigned short)e_ep->ay) 
		{
            e_ep->ay -= (short)eay2;

            if (eay >= (unsigned short)e_ep->ay) 
			{
                e_ep->ay = (unsigned short)eay;

                return 0;
            }

            return 1;
        }

        if ((unsigned short)e_ep->ay < eay) 
		{
            e_ep->ay += (short)eay2;

            if (eay <= (unsigned short)e_ep->ay) 
			{
                e_ep->ay = (unsigned short)eay;

                return 0;
            }

            return 1;
        }
    }

    return 0;
}

// 100% matching!
unsigned int bhPlItemLostEx()
{
	unsigned int cnt, cnt2;
    int v0, v1;
  
    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr += 2;

    cnt2 = v1 + (14 * 16);

    for (cnt = (sys->ply_id * 16) + 2; cnt < ((sys->ply_id * 16) + 12); cnt++) 
	{
        if (v0 == (unsigned char)(sys->itm[cnt] >> 16)) 
		{
            sys->itm[cnt2] = sys->itm[cnt];
            sys->itm[cnt] = 0;
            
			if ((sys->itm[sys->ply_id * 16] >= (cnt - (sys->ply_id * 16))) && (sys->itm[sys->ply_id * 16] != 0)) 
			{
                if (sys->itm[sys->ply_id * 16] == cnt) 
				{
                    sys->itm[sys->ply_id * 16] = 0;
                } 
				else
				{
                    sys->itm[sys->ply_id * 16]--;
                }
            }

            for ( ; cnt < ((sys->ply_id * 16) + 12); cnt++) 
			{
                sys->itm[cnt] = sys->itm[cnt + 1];
            }

            return 1;
        }
    }

    return 1;
}

// 100% matching!
unsigned int bhCyodanSetEx()
{
    int v0, v1, v2, v3, v4, v5;
    int w0, w1, w2, w3, w4, w5, w6, w7;
    NJS_POINT3 ps, wps;
    int wp_hef;
    BH_PWORK* e_ep;
	ETTY_WORK* enep; // not from DWARF
   
    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    w0 = *bhScePtr;

    bhScePtr++;

    w1 = *bhScePtr;

    bhScePtr++;

    w2 = *bhScePtr;

    bhScePtr++;

    w3 = *bhScePtr;

    bhScePtr++;

    v4 = *bhScePtr;

    bhScePtr++;
    
    if ((v4 & 0x1)) 
	{
        wps.x = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else
	{
        wps.x = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v4 & 0x2)) 
	{
         wps.y = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
         wps.y = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v4 & 0x4)) 
	{
         wps.z = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
         wps.z = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    v5 = *bhScePtr;

    bhScePtr++;

    wp_hef = WpnTab[v5].hiteff;
    
    v4 = *bhScePtr;

    bhScePtr++;
    
    if ((v4 & 0x1)) 
	{
        ps.x = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        ps.x = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v4 & 0x2)) 
	{
        ps.y = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        ps.y = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v4 & 0x4)) 
	{
        ps.z = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        ps.z = *(unsigned short*)bhScePtr / 100.0f;
    }
	
    bhScePtr += 2;
    
    w4 = *bhScePtr;

    bhScePtr++;

    w5 = *bhScePtr;

    bhScePtr++;

    w6 = *bhScePtr;

    bhScePtr += 2;
    
    switch (w4) 
	{
	case 1:
		enep = &rom->enep[w5];
		e_ep = &ene[enep->wrk_no];
		
		wps.x += e_ep->mlwP->owP[w6].mtx[12];
		wps.y += e_ep->mlwP->owP[w6].mtx[13];
		wps.z += e_ep->mlwP->owP[w6].mtx[14];
		break;
	case 2:
		e_ep = (BH_PWORK*)&sys->obwp[w5];
	
		wps.x += e_ep->mlwP->owP[w6].mtx[12];
		wps.y += e_ep->mlwP->owP[w6].mtx[13];
		wps.z += e_ep->mlwP->owP[w6].mtx[14];
		break;
    }
    
    bhSetEffParticleMk2(NULL, 0, &wps, &ps, v3 | ((v2 << 8) | ((v0 << 24) | (v1 << 16))), w3 | ((w2 << 8) | ((w0 << 24) | (w1 << 16))), wp_hef);
    
	return 1;
}

// 100% matching!
unsigned int bhArmsItemSet() 
{
    unsigned int cnt, icnt, wicnt;
    int v0;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;
    
    if ((sys->gm_flg & 0x8000000))
	{
        for (wicnt = 0, icnt = 2, cnt = (sys->ply_id * 16) + 2; cnt < ((sys->ply_id * 16) + 12); cnt++, icnt++) 
		{
            if ((unsigned char)(sys->itm[cnt] >> 16) == v0) 
			{
                wicnt = icnt;
                break;
            }
        }
    } 
	else 
	{
        for (wicnt = 0, icnt = 2, cnt = (sys->ply_id * 16) + 2; cnt < ((sys->ply_id * 16) + 10); cnt++, icnt++) 
		{
            if ((unsigned char)(sys->itm[cnt] >> 16) == v0) 
			{
                wicnt = icnt;
                break;
            }
        }
    }
 
    if (wicnt != 0) 
	{
        sys->itm[sys->ply_id * 16] = wicnt;
    }

    return 1;
}

// 100% matching!
unsigned int bhItemGetGetEx()
{
	unsigned int cnt, icnt, wicnt;
    int v0, v1, v2, v3;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr++;

    v2 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;
    
    if ((sys->gm_flg & 0x8000000)) 
	{
        for (wicnt = 0, icnt = 2, cnt = (v0 * 16) + 2; cnt < ((v0 * 16) + 12); cnt++, icnt++) 
		{
            if (sys->itm[cnt] == 0) 
			{
                wicnt = icnt;
                break;
            }
        }
    } 
	else 
	{
        for (wicnt = 0, icnt = 2, cnt = (v0 * 16) + 2; cnt < ((v0 * 16) + 10); cnt++, icnt++) 
		{
            if (sys->itm[cnt] == 0) 
			{
                wicnt = icnt;
                break;
            }
        }
    }
 
    if (wicnt != 0) 
	{
        sys->itm[cnt] = v1 << 16;

        sys->itm[cnt] |= v2;

        if (v1 == 33) 
		{
            sys->itm[v0 * 16]++;
        }

        if (v3 == 0) 
		{
            sys->itm[v0 * 16] = wicnt;
        }
    }
    
    return 1;
}

// 100% matching!
unsigned int bhEffectSandSetMatsumoto()
{
	int v0, v1, v2;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *bhScePtr;
	
    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    bhEne02_SetSandEffectEV(v0, v1, v2);
    
    return 1;
}

// 100% matching!
unsigned int bhVoiceWait()
{
    unsigned int v0, v1, v2, v3, v4;
    NJS_POINT3 pPos;
    BH_PWORK* e_ep;
    O_WRK* op;       // not from DWARF
    ETTY_WORK* enep; // not from DWARF

    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;
    
    v2 = *bhScePtr;

    bhScePtr++;
    
    v3 = *bhScePtr * 10;
    
    bhScePtr++;
    
    v4 = *bhScePtr;

    bhScePtr++;
    bhScePtr++;

    if (bhCetask->mode2 != 0) 
    {
        bhCetask->mode2 = 0;
        
        StopVoice(0);
    }

    switch (v0) 
    {
    case 0:
        pPos.x = plp->mlwP->owP->mtx[12];
        pPos.y = plp->mlwP->owP->mtx[13];
        pPos.z = plp->mlwP->owP->mtx[14];
        break;
    case 1:
        enep = &rom->enep[v4];
        e_ep = &ene[enep->wrk_no];
        
        pPos.x = e_ep->mlwP->owP->mtx[12];
        pPos.y = e_ep->mlwP->owP->mtx[13];
        pPos.z = e_ep->mlwP->owP->mtx[14];
        break;
    case 2:
        op = &sys->obwp[v4];
        
        pPos.x = op->mlwP->owP->mtx[12];
        pPos.y = op->mlwP->owP->mtx[13];
        pPos.z = op->mlwP->owP->mtx[14];
        break;
    }

    bhCetask->mode2 = 1;
    
    PlayVoiceEx(v1, &pPos, v2, v3, 1);
    
    return 1;
}

// 100% matching! 
unsigned int bhVoiceStart()
{
	bhScePtr += 2;

	ContinuePlayVoice();

	return 1;
}

// 100% matching!
unsigned int bhGameOverSet()
{
	bhScePtr += 2;

	sys->ts_flg &= ~0x4000;

	*(int*)&sys->gov_md0 = 0;

	return 1;
}

// 100% matching!
unsigned int bhPlItemChangeM()
{
    unsigned int cnt;
    int v0, v1;
 
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *bhScePtr;
    
    bhScePtr += 2;

    for (cnt = (sys->ply_id * 16) + 2; cnt < ((sys->ply_id * 16) + 12); cnt++) 
    {
        if (v0 == (unsigned char)(sys->itm[cnt] >> 16))
        {
            sys->itm[cnt] = v1 << 16;

            return 1;
        }
    }

    return 1;
}

// 100% matching!
unsigned int bhEffBakuDrmSet()
{
	int v2;
    NJS_VECTOR pPos;

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    if ((v2 & 0x1)) 
	{
        pPos.x = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        pPos.x = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v2 & 0x2)) 
	{
        pPos.y = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        pPos.y = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v2 & 0x4)) 
	{
        pPos.z = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        pPos.z = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    bhSetExplosionEffect(&pPos);
    
    return 1;
}

// 100% matching!
unsigned int bhPlItemTamaSet()
{
    unsigned int cnt;
    int v0, v1;
 
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    v1 = *(unsigned short*)bhScePtr;
    
    bhScePtr += 2;

    for (cnt = (sys->ply_id * 16) + 2; cnt < ((sys->ply_id * 16) + 12); cnt++) 
    {
        if (v0 == (unsigned char)(sys->itm[cnt] >> 16))
        {
            sys->itm[cnt] = (v0 << 16) + v1;

            return 1;
        }
    }

    return 1;
}

// 100% matching! 
unsigned int bhEffClearEvt()
{
	bhScePtr += 2;

	bhClearEventEffect();

	return 1;
}

// 100% matching!
unsigned int bhEvtTimerSet()
{
	int v0;

	bhScePtr++;

	v0 = *bhScePtr;
    
    bhScePtr++;

	bhSetEventTimer(v0);

	return 1;
}

// 100% matching!
unsigned int bhEneLookFlgSet()
{
    unsigned int v2, v3;
    BH_PWORK* e_ep;
	ETTY_WORK* enep; // not from DWARF

    bhScePtr++;

    v2 = *bhScePtr;

    bhScePtr++;

    v3 = *bhScePtr;

    bhScePtr += 2;
    
    enep = &rom->enep[v2];
    e_ep = &ene[enep->wrk_no];

    if (v3 == 0) 
	{
        e_ep->flg &= ~0x8000;
    } 
	else 
	{
        e_ep->flg |= 0x8000;
    }

    return 1;
}

// 100% matching!
unsigned int bhReturnTitleEvt()
{
    bhScePtr += 2;
    
    RequestAllStopSoundEx(1, 1, 0);
    
    bhReturnTitle();
    
    sys->ss_flg &= ~0x1000;
    
    return 1;
}

// 100% matching!
unsigned int bhSyukanModeSet() 
{
    unsigned int v0;
    
    bhScePtr++;
    
    v0 = *bhScePtr;
    
    bhScePtr++;
    
    if (v0 == 0) 
    {
        sys->gm_flg |= 0x1000000;
        
        cam.pe_ax = 0;
        cam.pe_pers = 11832;
        
        sys->gm_flg |= 0x2000;
        sys->st_flg &= ~0x1;
        
        cam.axp = 0;
        cam.ax = 0;
    } 
    else
    {
        sys->gm_flg &= ~0x10000C0;
        sys->gm_flg |= 0x800;
    }
    
    return 1;
}

// 100% matching!
unsigned int bhExGameItemInit()
{
	bhScePtr += 2;

	ExtraGameItemInit();

	return 1;
}

// 100% matching!
unsigned int bhEneLifeSetM()
{
    int v0, v1;
    ETTY_WORK* enep; // not from DWARF
    BH_PWORK* e_ep;  // not from DWARF

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr++;

    v1 = *(unsigned short*)bhScePtr;

    bhScePtr += 2;
    
    enep = &rom->enep[v0];
    e_ep = &ene[enep->wrk_no];

    e_ep->hp = v1;
    
    return 1;
}

// 100% matching!
unsigned int bhEffSSizeSet()
{
	int v0, v1;
    O_WRK* e_ep;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr += 2;

    v1 = *bhScePtr;

    bhScePtr++;
    
    e_ep = &eff[sys->efid[v0]];
    
    if ((v1 & 0x1)) 
	{
        e_ep->sxb = e_ep->sx = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        e_ep->sxb = e_ep->sx = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x2)) 
	{
        e_ep->syb = e_ep->sy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        e_ep->syb = e_ep->sy = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x4)) 
	{
        e_ep->szb = e_ep->sz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        e_ep->szb = e_ep->sz = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    return 1;
}

// 100% matching!
unsigned int bhEffLinkOffsetSet()
{
	int v0, v1;
    O_WRK* e_ep;

    bhScePtr++;

    v0 = *bhScePtr;

    bhScePtr += 2;

    v1 = *bhScePtr;

    bhScePtr++;
    
    e_ep = &eff[sys->efid[v0]];
    
    if ((v1 & 0x1)) 
	{
        e_ep->lox = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    }
	else
	{
        e_ep->lox = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x2)) 
	{
        e_ep->loy = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        e_ep->loy = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    if ((v1 & 0x4)) 
	{
        e_ep->loz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
    } 
	else 
	{
        e_ep->loz = *(unsigned short*)bhScePtr / 100.0f;
    }

    bhScePtr += 2;
    
    return 1;
}

// 100% matching! 
unsigned int bhRankingCall()
{
	bhScePtr += 2;
    
    sys->ss_flg |= 0x20000;
    
    njFogDisable();
    
    njSetBackColor(0, 0, 0);
    
    bhReleaseMainTexture();
    
    Ps2ClearOT();
    
    if (sys->fade_an > 0) 
    {
        bhDrawScreenFade();
    }
    
    sys->tk_flg = 0x702040;
    sys->ts_flg = 0;
    
    sys->typ_md0 = 0;
    sys->typ_flg = 0;
    
    sys->ssv_tim = 0;
    
    sys->memp = sys->mempb;
    
    sys->ss_flg &= ~0x20000;
    
    return 1;
}

// 100% matching!
unsigned int bhCallSysSe()
{
	int v0;
	
	bhScePtr += 2;

	v0 = *(unsigned short*)bhScePtr;

	bhScePtr += 2;

	CallSystemSe(0, v0);

	return 1;
}

// 100% matching! 
unsigned int bhSleep()
{
    bhCetask->loop++;
    
    bhCetask->cnt[bhCetask->loop] = *(unsigned short*)&bhScePtr[2];
    
    bhScePtr++;
    
    if (--bhCetask->cnt[bhCetask->loop] == 0) 
    {
        bhScePtr += 3;
        
        bhCetask->loop--;
    }
    
    return 0;
}

// 100% matching!
unsigned int bhSleeping()
{
	if (--bhCetask->cnt[bhCetask->loop] == 0) 
	{
		bhScePtr += 3;

		bhCetask->loop--;
	}

	return 0;
}

// 100% matching! 
unsigned int bhWhile()
{
    bhCetask->loop++;
    
    bhCetask->lcondition[bhCetask->loop] = &bhScePtr[2];
    
    bhScePtr = &bhScePtr[bhScePtr[1]];
    
    bhCetask->lstack[bhCetask->loop] = bhScePtr;
    
    return 1;
}

// 100% matching! 
unsigned int bhEwhile() 
{
    bhCetask->data = bhScePtr;
    
    bhScePtr = bhCetask->lcondition[bhCetask->loop];

    if (bhScenarioJmpT[*bhScePtr]() != 0) 
    {
        bhScePtr = bhCetask->lstack[bhCetask->loop];
    } 
    else 
    {
        bhScePtr = bhCetask->data;
        
        bhScePtr++;
        
        bhCetask->loop--;
        
        return 0;
    }

    return 1;
}

// 100% matching! 
unsigned int bhEwhile2()
{
	bhCetask->data = bhScePtr;
    
    bhScePtr = bhCetask->lcondition[bhCetask->loop];

    if (bhScenarioJmpT[*bhScePtr]() != 0) 
    {
        bhScePtr = bhCetask->lstack[bhCetask->loop];
    } 
    else 
    {
        bhScePtr = bhCetask->data;
        
        bhScePtr++;
        
        bhCetask->loop--;
        
        return 1;
    }

    return 1;
}

// 100% matching! 
unsigned int bhEvtNext()
{
	*bhScePtr++;

	return 0;
}

// 100% matching! 
unsigned int bhComNext()
{
	*bhScePtr++;

	return 1;
}

// 100% matching! 
unsigned int bhEvtEnd()
{
	bhCetask->status = 0;

	*bhScePtr++;
	*bhScePtr++;

	return 0;
}

// 100% matching! 
unsigned int bhFor()
{
    bhCetask->loop++;
    
    bhCetask->cnt3 = bhCetask->cnt2 = bhCetask->cnt[bhCetask->loop] = *(short*)&bhScePtr[2];
    
    bhScePtr += 4;
    
    bhCetask->lstack[bhCetask->loop] = bhScePtr;
    
    return 1;
}

// 100% matching! 
unsigned int bhNext()
{
    if (--bhCetask->cnt[bhCetask->loop] != 0) 
    {
        bhCetask->cnt2 = bhCetask->cnt[bhCetask->loop];
        
        bhScePtr = bhCetask->lstack[bhCetask->loop];
    }
    else 
    {
        bhScePtr++;
        bhScePtr++;
        
        bhCetask->loop--;
        
        return 1;
    }

    return 1;
}

// 100% matching!
unsigned int bhPlCtr()
{
	bhCetask->mode0 = 1;

	bhScePtr++;
    
    Player_controll();
    
    return 1;
}

// 100% matching!
int Player_controll() 
{
    switch (*bhScePtr) 
    {
    case 150:
        bhScePtr++;
        
        if (*bhScePtr == 0) 
        {
            ((int*)plp->exp1)[0] |= 0x1E0;
            ((int*)plp->exp1)[0] &= ~0x14;
        } 
        else 
        {
            ((int*)plp->exp1)[0] |= 0x14;
        }
        
        bhScePtr += 2;
        break;
    case 129:
    {
        unsigned int v0; 
        unsigned short *a0;    
        
        bhScePtr++;
        
        a0 = (unsigned short*)bhScePtr;
        
        bhScePtr = (unsigned char*)&a0[3];
        
        v0 = *bhScePtr;
        
        bhScePtr++;
        
        ((int*)bhCetask->work->exp1)[24] = (int)(v0 * (65536.0f / 360.0f)) >> 1;
        
        v0 = *bhScePtr;
        
        bhScePtr++;
        
        ((int*)bhCetask->work->exp1)[25] = (int)(v0 * (65536.0f / 360.0f)) >> 1;
        
        v0 = *bhScePtr;
        
        bhScePtr++;
        
        ((int*)bhCetask->work->exp1)[26] = (int)(v0 * (65536.0f / 360.0f)) >> 1;
        
        v0 = *bhScePtr;
        
        bhScePtr++;
        
        ((char*)bhCetask->work->exp1)[120] = v0;
            
        if (!(((unsigned char*)bhCetask->work->exp1)[120] & 0x1)) 
        {
            ((int*)bhCetask->work->exp1)[27] = 0;
            ((int*)bhCetask->work->exp1)[28] = 0;
            ((int*)bhCetask->work->exp1)[29] = 0;
        }
            
        if ((((unsigned char*)bhCetask->work->exp1)[120] & 0x40)) 
        {
            ((int*)bhCetask->work->exp1)[21] = -(*a0++ >> 1) * (65536.0f / 360.0f);
        } 
        else
        {
            ((int*)bhCetask->work->exp1)[21] = (*a0++ >> 1) * (65536.0f / 360.0f);
        }
        
        if ((((unsigned char*)bhCetask->work->exp1)[120] & 0x20))
        {
            ((int*)bhCetask->work->exp1)[22] = -(*a0++ >> 1) * (65536.0f / 360.0f);
        } 
        else 
        {
            ((int*)bhCetask->work->exp1)[22] = (*a0++ >> 1) * (65536.0f / 360.0f);
        }
        
        ((int*)bhCetask->work->exp1)[23] = (*a0++ >> 1) * (65536.0f / 360.0f);
        break;
    }
    case 130:
        ((unsigned char*)bhCetask->work->exp1)[120] = 0;
        
        bhScePtr++;
        break;
    case 141:
    {
        unsigned int v0, v1, v2;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhScePtr++;
        
        v1 = *bhScePtr;
        
        bhScePtr++;
        
        v2 = *bhScePtr;
        
        bhScePtr++;
        bhScePtr++;
        
        ((int*)bhCetask->work->exp1)[0] |= 0x1C;
            
        ((int*)bhCetask->work->exp1)[16] = v0;
        
        ((short*)bhCetask->work->exp1)[34] = v1;
        ((short*)bhCetask->work->exp1)[35] = v2;
        break;
    }
    case 142:
        ((int*)bhCetask->work->exp1)[0] |= 0x1E0;
        ((int*)bhCetask->work->exp1)[0] &= ~0x1C;
        
        bhScePtr++;
        break;
    case 131:
    {
        unsigned int v0, v1; 
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhScePtr++;
        
        v1 = *bhScePtr;
        
        bhScePtr++;
        
        if (bhCetask->work->mode2 == v0)
        {
            bhCetask->work->mode3 = 1;
        }
        else 
        {
            bhCetask->work->mode3 = 0;
        }
        
        bhCetask->work->mode0 = 7;
        bhCetask->work->mode1 = v1;
        bhCetask->work->mode2 = v0;
        
        if (bhCetask->work->mode2 == 1) 
        {
            bhCetask->work->mode3 = 0;
        }
        
        break;
    }
    case 140:
    {
        unsigned int v0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhScePtr++;
        bhScePtr++;
            
        if (bhCetask->work->mode2 == v0) 
        {
            bhCetask->work->mode3 = 1;
        } 
        else 
        {
            bhCetask->work->mode3 = 0;
        }

        bhCetask->work->mode0 = 7;
        bhCetask->work->mode2 = v0 + 4;
        
        v0 = *(unsigned short*)bhScePtr;
        
        if (bhCetask->bpx == 0) 
        {
            bhCetask->work->ct0 = v0 << 16;
        } 
        else 
        {
            bhCetask->work->ct0 = (v0 * -1) << 16;
        }
        
        bhScePtr += 2;
        
        v0 = *(unsigned short*)bhScePtr;
        
        if (bhCetask->bpz == 0) 
        {
            bhCetask->work->ct0 |= v0;
        } 
        else 
        {
            bhCetask->work->ct0 |= v0 * -1;
        }
        
        bhScePtr += 2;
        break;
    }
    case 12:
        bhScePtr++;
        
        bhCetask->bpx = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->bpy = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->bpz = *bhScePtr;
        
        bhScePtr++;
        bhScePtr++;
        break;
    case 13:
        bhScePtr++;
        
        bhCetask->bax = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->bay = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->baz = *bhScePtr;
        
        bhScePtr++;
        bhScePtr++;
        break;
    case 132:
    {
        unsigned int v0;
        
        bhCetask->work->mnwP = (MN_WORK*)sys->plmthp;
        
        bhCetask->work->mode0 = 7;
        bhCetask->work->mode2 = 5;
        bhCetask->work->mode3 = 0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhCetask->work->mode1 = v0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhCetask->work->ct0 = v0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhCetask->work->ct1 = v0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhCetask->work->ct2 = v0;
        
        bhScePtr++;
        break;
    }
    case 143:
    {
        unsigned int v0;
        
        bhCetask->work->mnwP = (MN_WORK*)sys->plmthp;
        
        bhCetask->work->mode0 = 7;
        bhCetask->work->mode2 = 5;
    
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhCetask->work->mode3 = v0;
        
        bhScePtr++;
        bhScePtr++;
        break;
    }
    case 145:
    {
        unsigned int v0;
        
        bhCetask->work->mtn_add = 32768;
        
        bhCetask->work->mnwP = sys->rmthp;
    
        bhCetask->work->mode0 = 7;
        bhCetask->work->mode2 = 8;
        bhCetask->work->mode3 = 0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhCetask->work->mode1 = v0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhCetask->work->ct0 = v0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhCetask->work->ct1 = v0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhCetask->work->ct2 = v0;
        
        bhScePtr++;
        break;
    }
    case 137:
    {
        unsigned int v0; 
        POS *e_posp;
        
        bhCetask->work->mode0 = 7;
        bhCetask->work->mode1 = 0;
        bhCetask->work->mode2 = 1;
        bhCetask->work->mode3 = 0;
        
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        e_posp = rom->posp;
        e_posp += v0;
        
        bhCetask->work->py = e_posp->py;
        
        bhSetFloorNum(bhCetask->work);
        
        bhCetask->work->px = e_posp->px;
        bhCetask->work->py = e_posp->py;
        bhCetask->work->pz = e_posp->pz;
        
        bhCetask->work->ay = e_posp->ay;
        
        bhScePtr += 2;
        break;
    }
    case 128:
        bhCetask->work->mtn_add = 65536;
        
        bhCetask->work->flg |= 0x10;
        
        bhCetask->work->mnwP = (MN_WORK*)sys->plmthp;
        
        bhCetask->work->mode0 = 1;
        bhCetask->work->mode1 = 0;
        bhCetask->work->mode2 = 0;
        bhCetask->work->mode3 = 0;
        
        bhCetask->work->stflg &= ~0x10000;
        bhCetask->work->flg &= ~0x210000;
    case 139:
        bhCetask->mode1 = 0;
        
        bhScePtr++;
        
        bhCetask->mode0 = 0;
        break;
    case 7:
        bhScePtr++;
        
        if (bhCetask->bpx == 0) 
        {
            bhCetask->work->px = *(unsigned short*)bhScePtr / 100.0f;
        } 
        else 
        {
            bhCetask->work->px = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
        }
        
        ((float*)plp->exp0)[18] = bhCetask->work->pxb = bhCetask->work->px;
        
        bhScePtr += 2;
        
        if (bhCetask->bpy == 0) 
        {
            bhCetask->work->py = *(unsigned short*)bhScePtr / 100.0f;
        } 
        else 
        {
            bhCetask->work->py = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
        }
        
        bhCetask->work->pyb = bhCetask->work->py;
        
        bhCetask->work->flr_no = bhCheckFloorNum(bhCetask->work->py);
        
        bhScePtr += 2;
        
        if (bhCetask->bpz == 0)
        {
            bhCetask->work->pz = *(unsigned short*)bhScePtr / 100.0f;
        } 
        else 
        {
            bhCetask->work->pz = -1.0f * (*(unsigned short*)bhScePtr / 100.0f);
        }
        
        ((float*)plp->exp0)[20] = bhCetask->work->pzb = bhCetask->work->pz;
        
        bhScePtr += 2;
        break;
    case 52:
        bhScePtr++;
        
        bhStandPlayerMotion();
        break;
    case 0:
        bhScePtr++;
        break;
    }
}

// 100% matching!
unsigned int bhObjCtr()
{
    bhScePtr++;
    
    Obj_controll();
    
    return 1;
}

// 100% matching!
int Obj_controll()
{
    unsigned char v0;

    v0 = *bhScePtr;
    
    switch (v0)
    {                       
    case 20:
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhScePtr += 2;

        bhCetask->work->px += bhEtask[v0].work->mlwP->objP->pos[0];
        bhCetask->work->pz += bhEtask[v0].work->mlwP->objP->pos[2];
        break;
    case 1:
        bhCetask->mode1 = 0;
        
        bhScePtr++;
        break;
    default:
        return;
    }
}

// 100% matching!
unsigned int bhSubCtr()
{
    bhScePtr++;
    
    Sub_controll();
    
    return 1;
}

// 100% matching!
int Sub_controll()
{
	switch (*bhScePtr)
    {
    case 128:
        if (bhCetask->work != NULL) 
        {
            bhCetask->work->mnwP = sys->emtp[bhCetask->work->id];
            
            bhCetask->work->mode0 = 1;
            bhCetask->work->mode2 = 0;
            
            *(char*)&bhCetask->work->ct2 = 0;
            
            bhCetask->work->stflg &= ~0x10000;
            bhCetask->work->flg &= ~0x200000;
        } 
        else 
        {
            printf("Sub_controll NULL work!!\n");
            
            while (TRUE);
        }
    case 139:
        bhCetask->mode1 = 0;
        
        bhScePtr++;
        
        bhCetask->mode0 = 0;
        break;
    case 144:
        bhCetask->work->mode0 = 1;
        bhCetask->work->mode2 = 0;
        bhCetask->work->mode3 = 3;
        
        *(char*)&bhCetask->work->ct2 = 0; 
        
        bhCetask->work->stflg &= ~0x10000;
        bhCetask->work->flg &= ~0x200000;
        
        bhCetask->mode1 = 0;
        
        bhScePtr++;
        
        bhCetask->mode0 = 0;
        break;
    case 143:
        bhCetask->work->mnwP = sys->emtp[bhCetask->work->id];
        
        bhScePtr++;
        
        bhCetask->work->mode0 = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->work->mode1 = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->work->mode2 = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->work->mode3 = 0;
        
        *(unsigned char*)&bhCetask->work->type = *bhScePtr; 
        
        bhScePtr++;
        
        *(char*)&bhCetask->work->ct2 = 0; 
        
        bhCetask->work->stflg &= ~0x10000;
        bhCetask->work->flg &= ~0x200000;
        
        bhCetask->mode1 = 0;
        bhCetask->mode0 = 0;
        
        if (bhCetask->work->id == 1)
        {
            ((char*)bhCetask->work->exp1)[12] = 1;
            ((void**)bhCetask->work->exp1)[215] = sys->emtp[bhCetask->work->id];
        }
        
        bhCetask->work->mtn_md = bhCetask->mtn_md;
        bhCetask->work->mdflg = bhCetask->mdflg;
        
        bhCetask->work->hokan_rate = bhCetask->hokan_rate;
        break;
    case 146:
        bhCetask->work->mnwP = sys->emtp[bhCetask->work->id];
        
        bhScePtr++;
        
        bhCetask->work->mode0 = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->work->mode1 = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->work->mode2 = *bhScePtr;
        
        bhScePtr++;
        
        *(unsigned char*)&bhCetask->work->type = *bhScePtr; 
        
        bhScePtr++;
        
        bhCetask->work->mode3 = *bhScePtr;
        
        bhScePtr += 2;
        
        *(char*)&bhCetask->work->ct2 = 0; 
        
        bhCetask->work->stflg &= ~0x10000;
        bhCetask->work->flg &= ~0x200000;
        
        bhCetask->mode1 = 0;
        bhCetask->mode0 = 0;
        
        if (bhCetask->work->id == 1) 
        {
            ((char*)bhCetask->work->exp1)[12] = 1;
            ((void**)bhCetask->work->exp1)[215] = sys->emtp[bhCetask->work->id];
        }
        
        bhCetask->work->mtn_md = bhCetask->mtn_md;
        
		bhCetask->work->hokan_rate = bhCetask->hokan_rate;
        break;
    case 147:
        bhScePtr++;
        
        bhCetask->work->mode0 = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->work->mode1 = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->work->mode2 = *bhScePtr;
        
        bhScePtr++;
        
        bhCetask->work->mode3 = *bhScePtr;
        
        bhScePtr++;
        
        *(unsigned char*)&bhCetask->work->type = *bhScePtr; 
        
        bhScePtr += 2;
        break;
    case 148:
    {
        int v0;
            
        bhScePtr++;
        
        v0 = *bhScePtr;
    
        bhScePtr += 2;
        
        bhEne11_LightControl(bhCetask->work, v0);
        break;
    }
    case 149:
    {
        int v0;
            
        bhScePtr++;
        
        v0 = *bhScePtr;
        
        bhScePtr += 2;
        
        if (v0 == 0) 
        {
            bhCetask->work->flg &= ~0x10000;
        } 
        else
        {
            bhCetask->work->flg |= 0x10000;
        }
        
        break;
    }
    case 0:
        bhScePtr++;
        break;
    }
}

// 100% matching!
unsigned int bhCommonCtr()
{
	bhScePtr++;
    
    Common_controll();
    
    return 1;
}

// 100% matching!
int Common_controll()
{
    switch (*bhScePtr)
    {
        case 53:
        {
            int v0; 
            
            bhScePtr++;
            v0 = bhScePtr[0];
            bhScePtr += 2;
            bhCetask->work->mtn_md |= 0x20;
            if (bhCetask->work->id == 0x1) 
            {
                ((BH_PWORK *)bhCetask->work->exp1)->mtn_md |= 0x20;
            }
            if (v0 == 0) 
            {
                bhCetask->work->mtn_md |= 0x8;
                if (bhCetask->work->id == 0x1) 
                {
                    ((BH_PWORK *)bhCetask->work->exp1)->mtn_md |= 0x8;
                }
            } 
            else 
            {
                bhCetask->work->mtn_md &= ~8;
                if (bhCetask->work->id == 0x1) 
                {
                    ((BH_PWORK *)bhCetask->work->exp1)->mtn_md &= ~8;
                }
            }
        }
        break;
        case 51:
        {
            int v0; 
            int v1; 
            int v2; 
            BH_PWORK* epw; 
            POS* e_posp; 
            ETTY_WORK* temp; // not from the debugging symbols
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            v2 = *bhScePtr;
            bhScePtr += 2;
            temp = &rom->enep[v0];
            
            epw = &ene[temp->wrk_no];
            e_posp = rom->posp;
            e_posp += sys->evt_posno[v2];
            bhCetask->ips[0x0][0x0] = epw->mlwP->owP[v1].mtx[0xc];
            bhCetask->ips[0x0][0x1] = epw->mlwP->owP[v1].mtx[0xd];
            bhCetask->ips[0x0][0x2] = epw->mlwP->owP[v1].mtx[0xe];
            bhCetask->ips[0x1][0x0] = epw->mlwP->owP[v1].mtx[0xc];
            bhCetask->ips[0x1][0x1] = epw->mlwP->owP[v1].mtx[0xd];
            bhCetask->ips[0x1][0x2] = epw->mlwP->owP[v1].mtx[0xe];
            bhCetask->ips[0x2][0x0] = e_posp->px - (e_posp->px - epw->mlwP->owP[v1].mtx[0xc]) / 2.0f;
            bhCetask->ips[0x2][0x1] = e_posp->py;
            bhCetask->ips[0x2][0x2] = e_posp->pz - (e_posp->pz - epw->mlwP->owP[v1].mtx[0xe]) / 2.0f;
            bhCetask->ips[0x3][0x0] = epw->mlwP->owP[v1].mtx[0xc];
            bhCetask->ips[0x3][0x1] = epw->mlwP->owP[v1].mtx[0xd] * -1.0f;
            bhCetask->ips[0x3][0x2] = epw->mlwP->owP[v1].mtx[0xe];
        }
        break;
        case 52:
        {
            int v0; 
            POS* e_posp; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhScePtr += 2;
            e_posp = rom->posp;
            e_posp += sys->evt_posno[v0];
            bhCetask->ips[0x0][0x0] = bhCetask->work->px;
            bhCetask->ips[0x0][0x1] = bhCetask->work->py;
            bhCetask->ips[0x0][0x2] = bhCetask->work->pz;
            bhCetask->ips[0x1][0x0] = e_posp->px;
            bhCetask->ips[0x1][0x1] = e_posp->py;
            bhCetask->ips[0x1][0x2] = e_posp->pz;
        }
        break;
        case 50:
            bhScePtr++;
            *(unsigned char *)&bhCetask->work->type = *bhScePtr;
            bhScePtr += 2;
        break;
        case 47:
            bhScePtr++;
            bhCalcModel(bhCetask->work);
        break;
        case 43:
        {
            float ips_w[4][3]; 
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0;
            int v1; 
            int v2; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            v2 = *bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x0][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            ian_w[0x0][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x0][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ips_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ips_w[0x1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                if ((v1 & 0x1) != 0x0) 
                {
                    bhCetask->work->px = ans[0x0];
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    bhCetask->work->py = ans[0x1];
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    bhCetask->work->pz = ans[0x2];
                }
            }
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                if ((v1 & 0x1) != 0x0) 
                {
                    objP->pos[0x0] = ans[0x0];
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    objP->pos[0x1] = ans[0x1];
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    objP->pos[0x2] = ans[0x2];
                }
            }
            if (v0 == '\0')
            {
                njOverhauserSpline(ian_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ian_w[0x1],ans,0,frm);
            }
                
            if (bhCetask->model_cno == 0x0) 
            {
                if ((v2 & 0x1) != 0x0) 
                {
                    bhCetask->work->ax = ans[0x0] * 182.04445f;
                }
                if ((v2 & 0x2) != 0x0) 
                {
                    bhCetask->work->ay = ans[0x1] * 182.04445f;
                }
                if ((v2 & 0x4) != 0x0) 
                {
                    bhCetask->work->az = ans[0x2] * 182.04445f;
                }
            }
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                if ((v2 & 0x1) != 0x0) 
                {
                    objP->ang[0x0] = ans[0x0] * 182.04445f;
                }
                if ((v2 & 0x2) != 0x0) 
                {
                    objP->ang[0x1] = ans[0x1] * 182.04445f;
                }
                if ((v2 & 0x4) != 0x0) 
                {
                    objP->ang[0x2] = ans[0x2] * 182.04445f;
                }
            }
        }
        break;
        case 44:
        {
            float ips_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x0][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ips_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ips_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                if ((v1 & 0x1) != 0x0) 
                {
                    bhCetask->work->px = ans[0];
                }
                if ((v1 & 0x2) != 0x0)
                {
                    bhCetask->work->py = ans[1];
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    bhCetask->work->pz = ans[2];
                }
            } 
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                if ((v1 & 0x1) != 0x0) 
                {
                    objP->pos[0] = ans[0];
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    objP->pos[1] = ans[1];
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    objP->pos[2] = ans[2];
                }
            }
        }
        break;
        case 45:
        {
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            bhScePtr++;
            ian_w[0x0][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x0][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ian_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ian_w[1],ans,0,frm);
            }
                
            if (bhCetask->model_cno == 0x0) 
            {
                if ((v1 & 0x1) != 0x0) 
                {
                    bhCetask->work->ax = ans[0] * 182.04445f;
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    bhCetask->work->ay = ans[1] * 182.04445f;
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    bhCetask->work->az = ans[2] * 182.04445f;
                }
            } 
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                if ((v1 & 0x1) != 0x0) 
                {
                    objP->ang[0] = ans[0] * 182.04445f;
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    objP->ang[1] = ans[1] * 182.04445f;
                }
                if ((v1 & 0x4) != 0x0)
                {
                    objP->ang[2] = ans[2] * 182.04445f;
                }
            }
        }
        break;
        case 42:
        {
            int v0; 
            int v1; 
            O_WORK* owk; 
            
            owk = bhCetask->work->mdl->owP;
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            owk += v1;
            if (v0 == '\0') 
            {
                owk->flg |= 0x2;
                break;
            }
            else 
            {
                owk->flg &= ~2;
            }
        }
        break;
        case 41:
            bhScePtr++;
            if (*(unsigned short *)bhScePtr == 0x0) 
            {
                bhCetask->work->flg &= ~0x40000;
            }
            else 
            {
                bhCetask->work->flg |= 0x40000;
            }
            bhScePtr += 2;
        break;
        case 46:
            bhScePtr++;
            if (*(unsigned short *)bhScePtr == 0x0) 
            {
                bhCetask->work->flg &= ~0x20;
            }
            else 
            {
                bhCetask->work->flg |= 0x20;
            }
            bhScePtr += 2;
        break;
        case 40:
        {
            int v0; // not from the debugging symbols
            
            bhScePtr++;
            v0 = *(unsigned short *)bhScePtr;
            bhCetask->work->frm_no = v0 << 0x10;
            if (bhCetask->work->id == 0x1) 
            {
                ((BH_PWORK *)bhCetask->work->exp1)->frm_no = v0 << 0x10;
            }
            bhScePtr += 2;
        }
        break;
        case 28:
        {
            float ips_w[4][3]; 
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x0][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            ian_w[0x0][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x0][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ips_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ips_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->px = ans[0];
                bhCetask->work->py = ans[1];
                bhCetask->work->pz = ans[2];
            }
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->pos[0] = ans[0];
                objP->pos[1] = ans[1];
                objP->pos[2] = ans[2];
            }
            
            if (v0 == '\0') 
            {
                njOverhauserSpline(ian_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ian_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->ax = ans[0] * 182.04445f;
                bhCetask->work->ay = ans[1] * 182.04445f;
                bhCetask->work->az = ans[2] * 182.04445f;
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->ang[0] = ans[0] * 182.04445f;
                objP->ang[1] = ans[1] * 182.04445f;
                objP->ang[2] = ans[2] * 182.04445f;
            }
        }
        break;
        case 30:
        {
            float ips_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x0][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ips_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ips_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->px = ans[0];
                bhCetask->work->py = ans[1];
                bhCetask->work->pz = ans[2];
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->pos[0] = ans[0];
                objP->pos[1] = ans[1];
                objP->pos[2] = ans[2];
            }
        }
        break;
        case 31:
        {
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            ian_w[0x0][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x0][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ian_w[0],ans,0,frm);
            }
            else
            {
                njLinear(ian_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->ax = ans[0] * 182.04445f;
                bhCetask->work->ay = ans[1] * 182.04445f;
                bhCetask->work->az = ans[2] * 182.04445f;
            } 
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->ang[0] = ans[0] * 182.04445f;
                objP->ang[1] = ans[1] * 182.04445f;
                objP->ang[2] = ans[2] * 182.04445f;
            }
        }
        break;
        case 29:
        {
            float ips_w[4][3]; 
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            
            bhScePtr++;
            bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x3][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x2][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x3][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x2][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x3][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x2][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            ian_w[0x0][0x0] = bhCetask->ian[0x3][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x2][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x3][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x2][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x3][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x2][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            njOverhauserSpline(ips_w[0],ans,0,frm);
            
            if (bhCetask->model_cno == 0x0)
            {
                bhCetask->work->px = ans[0];
                bhCetask->work->py = ans[1];
                bhCetask->work->pz = ans[2];
            }
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->pos[0] = ans[0];
                objP->pos[1] = ans[1];
                objP->pos[2] = ans[2];
            }
            
            njOverhauserSpline(ian_w[0],ans,0,frm); 
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->ax = ans[0] * 182.04445f;
                bhCetask->work->ay = ans[1] * 182.04445f;
                bhCetask->work->az = ans[2] * 182.04445f;
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->ang[0] = ans[0] * 182.04445f;
                objP->ang[1] = ans[1] * 182.04445f;
                objP->ang[2] = ans[2] * 182.04445f;
            }
        }
        break;
        case 32:
        {
            float ips_w[4][3]; 
            float ans[3]; 

            bhScePtr++;
            bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x3][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x2][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x3][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x2][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x3][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x2][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            
            njOverhauserSpline(ips_w[0],ans,0,1.0f / bhCetask->cnt3 * bhCetask->cnt2);
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->px = ans[0];
                bhCetask->work->py = ans[1];
                bhCetask->work->pz = ans[2];
            } 
            else 
            {
                NJS_CNK_OBJECT* objP;
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->pos[0] = ans[0];
                objP->pos[1] = ans[1];
                objP->pos[2] = ans[2];
            }
        }
        break;
        case 33:
        {
            float ian_w[4][3]; 
            float ans[3]; 
            
            bhScePtr++;
            bhScePtr++;
            ian_w[0x0][0x0] = bhCetask->ian[0x3][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x2][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x3][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x2][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x3][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x2][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            
            njOverhauserSpline(ian_w[0],ans,0,1.0f / bhCetask->cnt3 * bhCetask->cnt2);
            
            if (bhCetask->model_cno == 0x0) 
            { 
                bhCetask->work->ax = ans[0] * 182.04445f;
                bhCetask->work->ay = ans[1] * 182.04445f;
                bhCetask->work->az = ans[2] * 182.04445f;
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->ang[0] = ans[0] * 182.04445f;
                objP->ang[1] = ans[1] * 182.04445f;
                objP->ang[2] = ans[2] * 182.04445f;
            }
        }
        break;
        case 26:
        {
            int v0; 
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            
            if (v1 & 0x1)
            {
                bhCetask->ips[v0][0x0] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->ips[v0][0x0] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
            
            if (v1 & 0x2) 
            {
                bhCetask->ips[v0][0x1] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->ips[v0][0x1] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
            
            if (v1 & 0x4) 
            {
                bhCetask->ips[v0][0x2] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->ips[v0][0x2] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
        }
        break;
        case 27:
        {
            int v0; 
            int v1; 
            int v2; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            
            v2 = *bhScePtr;
            if ((v1 & 0x1) != 0x0) 
            {
                v2 = -v2;
            }
            bhCetask->ian[v0][0x0] = v2;
            bhScePtr++;
            
            v2 = *bhScePtr;
            if ((v1 & 0x2) != 0x0) 
            {
                v2 = -v2;
            }
            bhCetask->ian[v0][0x1] = v2;
            bhScePtr++;
            
            v2 = *bhScePtr;
            if ((v1 & 0x4) != 0x0) 
            {
                v2 = -v2;
            }
            bhCetask->ian[v0][0x2] = v2;
            bhScePtr += 2;
        }
        break;
        case 48:
        {
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhScePtr += 2;
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->ips[v0][0x0] = bhCetask->work->px;
                bhCetask->ips[v0][0x1] = bhCetask->work->py;
                bhCetask->ips[v0][0x2] = bhCetask->work->pz;
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                bhCetask->ips[v0][0x0] = objP->pos[0];
                bhCetask->ips[v0][0x1] = objP->pos[1];
                bhCetask->ips[v0][0x2] = objP->pos[2];
            }
        }
        break;
        case 49:
        {
            int v0;
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            bhCetask->ian[v0][0x0] = *(short *)&bhCetask->work->ax * 0.005493164f;
            bhCetask->ian[v0][0x1] = *(short *)&bhCetask->work->ay * 0.005493164f;
            bhCetask->ian[v0][0x2] = *(short *)&bhCetask->work->az * 0.005493164f;
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->ian[v0][0x0] = *(short *)&bhCetask->work->ax * 0.005493164f;
                bhCetask->ian[v0][0x1] = *(short *)&bhCetask->work->ay * 0.005493164f;
                bhCetask->ian[v0][0x2] = *(short *)&bhCetask->work->az * 0.005493164f;
            }
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                bhCetask->ian[v0][0x0] = *(short *)&objP->ang[0] * 0.005493164f;
                bhCetask->ian[v0][0x1] = *(short *)&objP->ang[1] * 0.005493164f;
                bhCetask->ian[v0][0x2] = *(short *)&objP->ang[2] * 0.005493164f;
            }
            
            if (bhCetask->ian[v0][0x0] < 0.0f) 
            {
                bhCetask->ian[v0][0x0] += 360.0f;
            }
            
            if (v1 == '\0') 
            {
                if (bhCetask->ian[v0][0x1] < 0.0f) 
                {
                    bhCetask->ian[v0][0x1] += 360.0f;
                }
            }
            else 
            {
                if (bhCetask->ian[v0][0x1] > 180.0f) 
                {
                    bhCetask->ian[v0][0x1] -= 360.0f;
                }
            }
            
            if (bhCetask->ian[v0][0x2] < 0.0f) 
            {
                bhCetask->ian[v0][0x2] += 360.0f;
            }
        }
        break;
        case 25:
        {
            unsigned int v0; 
            unsigned int t1; 
            
            bhScePtr++;
            switch(*bhScePtr) 
            {
                case 1:
                case 2:
                    bhCetask->work->mtn_add = 0x10000;
                    break;
                case 0:
                case 3:
                case 8:
                    bhCetask->work->mtn_add = 0x8000;
                    break;
                case 4:
                    bhCetask->work->mtn_add = 0x5555;
                    break;
                case 5:
                case 9:
                    bhCetask->work->mtn_add = 0x4000;
                    break;
                case 6:
                    bhCetask->work->mtn_add = 0x3333;
                    break;
                case 7:
                case 10:
                    bhCetask->work->mtn_add = 0x2aaa;
                    break;
                case 11:
                    bhCetask->work->mtn_add = 0x2000;
                    break;
                case 12:
                    bhCetask->work->mtn_add = 0x1999;
                    break;
                case 13:
                    bhCetask->work->mtn_add = 0x1555;
                    break;
                case 14:
                    bhCetask->work->mtn_add = 0x2492;
                    break;
                case 15:
                    bhCetask->work->mtn_add = 0x2000;
                    break;
                case 16:
                    bhCetask->work->mtn_add = 0x1c71;
                    break;
                case 17:
                    bhCetask->work->mtn_add = 0x1999;
                    break;
                case 18:
                    bhCetask->work->mtn_add = 0x1745;
                    break;
                case 19:
                    bhCetask->work->mtn_add = 0x1555;
                    break;
                case 20:
                    bhCetask->work->mtn_add = 0x1249;
                    break;
                case 21:
                    bhCetask->work->mtn_add = 0x1000;
                    break;
                case 22:
                    bhCetask->work->mtn_add = 0xe38;
                    break;
                case 23:
                    bhCetask->work->mtn_add = 0xccc;
                    break;
                case 24:
                    bhCetask->work->mtn_add = 0xba2;
                    break;
                case 25:
                    bhCetask->work->mtn_add = 0xaaa;
                    break;
            }
            
            bhScePtr++;
            switch (*bhScePtr) 
            {
                case 0:
                    bhCetask->work->mnwP = (MN_WORK*)sys->plmthp;
                    bhCetask->work->mode0 = '\a';
                    bhCetask->work->mode2 = '\b';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    bhCetask->work->mode1 = *bhScePtr++;
                    bhCetask->work->ct0 = *bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = v0;
                    bhScePtr++;
                    
                    t1 = *bhScePtr;
                    bhCetask->work->ct2 = t1;
                    
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 0x8;
                    } 
                    else 
                    {
                        bhCetask->work->hokan_count = 0x8;
                        bhCetask->work->mtn_md &= ~8;
                    }
                    bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                break;
                case 1:
                    bhCetask->work->mnwP = sys->emtp[bhCetask->work->id];
                    bhCetask->work->mode0 = '\x01';
                    bhCetask->work->mode2 = '\0';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    t1 = *bhScePtr;
                    *(unsigned char*)&bhCetask->work->mtn_no = t1;
                    bhCetask->work->mode1 = t1;
                    
                    bhCetask->work->mtn_md = bhCetask->mtn_md;
                    bhCetask->work->hokan_rate = bhCetask->hokan_rate;
                    
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mode0 = 6;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x20;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_no = t1 + 0xc8;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x8;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_add = bhCetask->work->mtn_add;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_rate = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_no = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_mode = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->mnwP = sys->emtp[bhCetask->work->id];
                    }
                    
                    bhScePtr++;
                    if (*bhScePtr == '\0') 
                    {
                        bhCetask->work->mode0 = '\x01';
                    } 
                    else 
                    {
                        bhCetask->work->mode0 = '\x05';
                    }
                    
                    bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = v0;
                    
                    bhScePtr++;
                    t1 = *bhScePtr;
                    if (t1 > 8) 
                    {
                        bhCetask->work->ct2 = 0xa;
                    } 
                    else 
                    {
                        bhCetask->work->ct2 = t1;
                    }
                    
                    bhScePtr++;
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 8;
                        if (bhCetask->work->id == 0x1)
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x0;
                        }
                    } 
                    else if (t1 > 0x8) 
                    {
                        bhCetask->work->hokan_count = t1;
                        if (bhCetask->work->id == 0x1) 
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = t1;
                        }
                    } 
                    else 
                    {
                        bhCetask->work->hokan_count = 0x8;
                        bhCetask->work->mtn_md &= ~8;
                    }
                    bhCetask->work->frm_no = 0x0;
                break;
            }
                
            switch(v0) 
            {
                case 0x0:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x2:
                    bhSetMotion(bhCetask->work,0,0,0);
                    break;
                case 0x3:
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x4:
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x5:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x6:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x7:
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
            }
        }
        break;
        case 35:
        {
            unsigned int v0; 
            unsigned int t1; 
            
            bhScePtr++;
            switch(*bhScePtr)
            {
                case 1:
                case 2:
                    bhCetask->work->mtn_add = 0x10000;
                    break;
                case 0:
                case 3:
                case 8:
                    bhCetask->work->mtn_add = 0x8000;
                    break;
                case 4:
                    bhCetask->work->mtn_add = 0x5555;
                    break;
                case 5:
                case 9:
                    bhCetask->work->mtn_add = 0x4000;
                    break;
                case 6:
                    bhCetask->work->mtn_add = 0x3333;
                    break;
                case 7:
                case 10:
                    bhCetask->work->mtn_add = 0x2aaa;
                    break;
                case 11:
                    bhCetask->work->mtn_add = 0x2000;
                    break;
                case 12:
                    bhCetask->work->mtn_add = 0x1999;
                    break;
                case 13:
                    bhCetask->work->mtn_add = 0x1555;
                    break;
                case 14:
                    bhCetask->work->mtn_add = 0x2492;
                    break;
                case 15:
                    bhCetask->work->mtn_add = 0x2000;
                    break;
                case 16:
                    bhCetask->work->mtn_add = 0x1c71;
                    break;
                case 17:
                    bhCetask->work->mtn_add = 0x1999;
                    break;
                case 18:
                    bhCetask->work->mtn_add = 0x1745;
                    break;
                case 19:
                    bhCetask->work->mtn_add = 0x1555;
                    break;
                case 20:
                    bhCetask->work->mtn_add = 0x1249;
                    break;
                case 21:
                    bhCetask->work->mtn_add = 0x1000;
                    break;
                case 22:
                    bhCetask->work->mtn_add = 0xe38;
                    break;
                case 23:
                    bhCetask->work->mtn_add = 0xccc;
                    break;
                case 24:
                    bhCetask->work->mtn_add = 0xba2;
                    break;
                case 25:
                    bhCetask->work->mtn_add = 0xaaa;
                    break;
            }
            
            bhScePtr++;
            switch (*bhScePtr) 
            {
                case 0:
                    bhCetask->work->mnwP = (MN_WORK*)sys->plmthp;
                    bhCetask->work->mode0 = '\a';
                    bhCetask->work->mode2 = '\b';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    bhCetask->work->mode1 = *bhScePtr;
                    
                    bhScePtr++;
                    bhCetask->work->ct0 = *bhScePtr;
                    
                    bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = v0;
                    bhScePtr++;

                    t1 = *bhScePtr;
                    bhCetask->work->ct2 = t1;
                    
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                    } 
                    else 
                    {
                        bhCetask->work->hokan_count = 0x8;
                    }
                    bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                break;
                case 1:
                    bhCetask->work->mnwP = sys->emtp[bhCetask->work->id];
                    bhCetask->work->mode0 = '\x01';
                    bhCetask->work->mode2 = '\0';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    t1 = *bhScePtr;
                    *(unsigned char*)&bhCetask->work->mtn_no = t1;
                    bhCetask->work->mode1 = t1;
                    
                    bhCetask->work->mtn_md = bhCetask->mtn_md;
                    bhCetask->work->hokan_rate = bhCetask->hokan_rate;
                    
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mode0 = 6;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x20;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_no = t1 + 1;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x8;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_add = bhCetask->work->mtn_add;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_rate = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_no = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_mode = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->mnwP = sys->emtp[bhCetask->work->id];
                    }
                    
                    bhScePtr++;
                    if (*bhScePtr == '\0') 
                    {
                        bhCetask->work->mode0 = '\x01';
                        *(unsigned char *)&bhCetask->work->ct2 = 0x1;
                    } 
                    else
                    {
                        bhCetask->work->mode0 = '\x05';
                        *(unsigned char *)&bhCetask->work->ct2 = 0x3;
                    }

                    t1 = *bhScePtr;
                    if (bhCetask->bpx == '\0') 
                    {
                        bhCetask->work->ct0 = t1 << 0x10;
                    }
                    else
                    {
                        bhCetask->work->ct0 = (t1 * -1) << 0x10;
                    }
                    
                    bhScePtr++;
                    v0 = *bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                    bhScePtr += 2;
                break;
            }
            
            switch(v0) 
            {
                case 0x0:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x2:
                    bhSetMotion(bhCetask->work,0,0,0);
                    break;
                case 0x3:
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x4:
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x5:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x6:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x7:
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
            }
        }
        break;
        case 24:
        {
            unsigned int v0; 
            unsigned int t0; 
            unsigned int t1; 
            
            bhCetask->work->mnwP = sys->rmthp;
            bhScePtr++;
            t0 = false;
            switch(*bhScePtr) 
            {
                case 1:
                case 2:
                    t0 = true;
                    bhCetask->work->mtn_add = 0x10000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x20;
                    }
                    break;
                case 0:
                case 3:
                case 8:
                    bhCetask->work->mtn_add = 0x8000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 4:
                    bhCetask->work->mtn_add = 0x5555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 5:
                case 9:
                    bhCetask->work->mtn_add = 0x4000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 6:
                    bhCetask->work->mtn_add = 0x3333;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 7:
                case 10:
                    bhCetask->work->mtn_add = 0x2aaa;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 11:
                    bhCetask->work->mtn_add = 0x2000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 12:
                    bhCetask->work->mtn_add = 0x1999;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 13:
                    bhCetask->work->mtn_add = 0x1555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 14:
                    bhCetask->work->mtn_add = 0x2492;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 15:
                    bhCetask->work->mtn_add = 0x2000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 16:
                    bhCetask->work->mtn_add = 0x1c71;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 17:
                    bhCetask->work->mtn_add = 0x1999;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 18:
                    bhCetask->work->mtn_add = 0x1745;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 19:
                    bhCetask->work->mtn_add = 0x1555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 20:
                    bhCetask->work->mtn_add = 0x1249;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 21:
                    bhCetask->work->mtn_add = 0x1000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 22:
                    bhCetask->work->mtn_add = 0xe38;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 23:
                    bhCetask->work->mtn_add = 0xccc;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 24:
                    bhCetask->work->mtn_add = 0xba2;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 25:
                    bhCetask->work->mtn_add = 0xaaa;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
            }

            bhScePtr++;

            switch(*bhScePtr) 
            {
                case 0:
                    bhCetask->work->mode0 = '\a';
                    bhCetask->work->mode2 = '\b';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    bhCetask->work->mode1 = *bhScePtr++;
                    bhCetask->work->ct0 = *bhScePtr++;
                    
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = *bhScePtr++;
                    
                    t1 = *bhScePtr;
                    bhCetask->work->ct2 = t1;
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    else
                    {
                        bhCetask->work->hokan_count = 0x8;
                    }
                    
                    bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                break;
                case 1:
                    bhCetask->work->mode0 = '\x01';
                    bhCetask->work->mode2 = '\0';
                    bhCetask->work->mode3 = '\0';
                    bhScePtr++;
                    t1 = *bhScePtr;
                    *(unsigned char *)&bhCetask->work->mtn_no = t1;
                    bhCetask->work->mode1 = t1;
                    bhCetask->work->mtn_md = 0x20;
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    bhCetask->work->hokan_rate = 0x0;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mode0 = '\x06';
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_no = t1 + 0x1;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x8;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_add = bhCetask->work->mtn_add;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_rate = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_no = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_mode = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->mnwP = sys->rmthp;
                    }
                    
                    bhScePtr++;
                    if (*bhScePtr == '\0') 
                    {
                        bhCetask->work->mode0 = '\x01';
                    }
                    else 
                    {
                        bhCetask->work->mode0 = '\x05';
                    }
                    
                    bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = *bhScePtr;
                    bhScePtr++;
                    
                    t1 = *bhScePtr;
                    if (t1 > 0x8)
                    {
                        bhCetask->work->ct2 = 0xa;
                    }
                    else 
                    {
                        bhCetask->work->ct2 = t1;
                    }
                    
                    if (t1 == 0x6)
                    {
                        if (bhCetask->work->id == 0x1) 
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x0;
                        }
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    else if (0x8 < t1) 
                    {
                        bhCetask->work->hokan_count = t1;
                        if (bhCetask->work->id == 0x1)
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = t1;
                        }
                    }
                    bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                break;
                case 2:
                case 3:
                    bhScePtr++;
                    t1 = *bhScePtr;
                    bhCetask->work->mode3 = '\x01';
                    bhCetask->work->mtn_md = 0x20;
                    if (!t0)
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    bhCetask->work->mtn_no = t1;
                    bhCetask->work->hokan_rate = 0x0;
                    bhCetask->work->frm_no = 0x0;
                    bhCetask->work->frm_mode = 0x0;
                    bhScePtr++;
                    bhScePtr++;
                    v0 = *bhScePtr++;
                    t1 = *bhScePtr;
                    bhCetask->work->hokan_count = 0x8;
                    if (t1 == '\x06') 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    bhScePtr++;
                break;
            }
            
            switch(v0) 
            {
                case 0x0:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x1:
                    break;
                case 0x2:
                    bhSetMotion(bhCetask->work,0,0,0);
                    break;
                case 0x3:
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x4:
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x5:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x6:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x7:
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
            }
        }
        break;
        case 34:
        {
            unsigned int v0; 
            unsigned int t0; 
            unsigned int t1; 
            
            bhCetask->work->mnwP = sys->rmthp;
            t0 = false;
            bhScePtr++;
            switch(*bhScePtr) 
            {
                case 1:
                case 2:
                    t0 = true;
                    bhCetask->work->mtn_add = 0x10000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x20;
                    }
                    break;
                case 0:
                case 3:
                case 8:
                    bhCetask->work->mtn_add = 0x8000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 4:
                    bhCetask->work->mtn_add = 0x5555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 5:
                case 9:
                    bhCetask->work->mtn_add = 0x4000;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 6:
                    bhCetask->work->mtn_add = 0x3333;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 7:
                case 10:
                    bhCetask->work->mtn_add = 0x2aaa;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 11:
                    bhCetask->work->mtn_add = 0x2000;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 12:
                    bhCetask->work->mtn_add = 0x1999;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 13:
                    bhCetask->work->mtn_add = 0x1555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 14:
                    bhCetask->work->mtn_add = 0x2492;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 15:
                    bhCetask->work->mtn_add = 0x2000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 16:
                    bhCetask->work->mtn_add = 0x1c71;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 17:
                    bhCetask->work->mtn_add = 0x1999;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 18:
                    bhCetask->work->mtn_add = 0x1745;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 19:
                    bhCetask->work->mtn_add = 0x1555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 20:
                    bhCetask->work->mtn_add = 0x1249;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 21:
                    bhCetask->work->mtn_add = 0x1000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 22:
                    bhCetask->work->mtn_add = 0xe38;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 23:
                    bhCetask->work->mtn_add = 0xccc;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 24:
                    bhCetask->work->mtn_add = 0xba2;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 25:
                    bhCetask->work->mtn_add = 0xaaa;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
            }

            bhScePtr++;

            switch(*bhScePtr) 
            {
                case 0:
                    bhCetask->work->mode0 = '\a';
                    bhCetask->work->mode2 = '\b';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    bhCetask->work->mode1 = *bhScePtr++;
                    bhCetask->work->ct0 = *bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = *bhScePtr++;
                    
                    t1 = *bhScePtr;
                    bhCetask->work->ct2 = t1;
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 0x8;
                    } 
                    else
                    {
                        bhCetask->work->hokan_count = 0x8;
                    }
                    
                    bhScePtr++;
                    bhCetask->work->frm_no = *(unsigned short *)bhScePtr << 0x10;
                    bhScePtr += 2;
                break;
                case 1:
                    bhCetask->work->mode0 = '\x01';
                    bhCetask->work->mode2 = '\0';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    t1 = *bhScePtr;
                    *(unsigned char *)&bhCetask->work->mtn_no = t1;
                    bhCetask->work->mode1 = t1;
                    bhCetask->work->mtn_md = 0x20;
                    
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    
                    bhCetask->work->hokan_rate = 0x0;
                    bhScePtr++;
                    if (*bhScePtr == '\0')
                    {
                        bhCetask->work->mode0 = '\x01';
                    }
                    else 
                    {
                        bhCetask->work->mode0 = '\x05';
                    }
                    
                    bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = *bhScePtr++;
                    t1 = *bhScePtr;
                    if (t1 > 8) 
                    {
                        bhCetask->work->ct2 = 0xa;
                    }
                    else 
                    {
                        bhCetask->work->ct2 = t1;
                    }
                    
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x8;
                    }
                    
                    if (t1 == 0x6) 
                    {
                        if (bhCetask->work->id == 0x1) 
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x0;
                        }
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    else if (0x8 < t1) 
                    {
                        bhCetask->work->hokan_count = t1;
                        if (bhCetask->work->id == 0x1) 
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = t1;
                        }
                    }
                    
                    bhScePtr++;
                    bhCetask->work->frm_no = *(unsigned short *)bhScePtr << 0x10;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mode0 = '\x06';
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_no = bhCetask->work->mtn_no + 0x1;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_add = bhCetask->work->mtn_add;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_rate = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_no = bhCetask->work->frm_no;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_mode = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->mnwP = sys->rmthp;
                    }
                    bhScePtr += 2;
                break;
                case 2:
                case 3:
                    bhScePtr++;
                    t1 = *bhScePtr;
                    bhCetask->work->mode3 = '\x01';
                    bhCetask->work->mtn_md = 0x20;
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    bhCetask->work->mtn_no = t1;
                    bhCetask->work->hokan_rate = 0x0;
                    bhCetask->work->frm_no = 0x0;
                    bhCetask->work->frm_mode = 0x0;
                    bhScePtr++;
                    bhScePtr++;
                    v0 = *bhScePtr++;
                    t1 = *bhScePtr;
                    bhCetask->work->hokan_count = 0x8;
                    if (t1 == '\x06') 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |=  0x8;
                    }
                    bhScePtr++;
                    bhCetask->work->frm_no = *(unsigned short *)bhScePtr << 0x10;
                    bhScePtr += 2;
                break;
            }
            
            switch(v0) 
            {
                case 0x0:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x2:
                    bhSetMotion(bhCetask->work,0,0,0);
                    break;
                case 0x3:
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x4:
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x5:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x6:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x7:
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
            }
        }
        break;
        case 23:
        {
            unsigned int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhScePtr += 2;

            switch(v0) 
            {
                case 0:
                bhCetask->work->flg &= ~0x118;
                break;
                case 1:
                bhCetask->work->flg |= 0x118;
                break;
                case 2:
                bhCetask->work->flg &= ~0x18;
                break;
                case 3:
                bhCetask->work->flg |= 0x18;
                break;
            }
        }
        break;
        case 0x5:
            bhScePtr++;
            bhCetask->addpx = *bhScePtr++ * 0.1f;
            bhCetask->addpy = *bhScePtr++ * 0.1f;
            bhCetask->addpz = *bhScePtr++ * 0.1f;
            bhScePtr++;
        break;
        case 0x6:
        {
            unsigned int v0; 
    
			bhScePtr++;
			v0 = *bhScePtr;
			bhCetask->addax = (int)(v0 * (65536.0f / 360.0f)) >> 0x1;
			bhScePtr++;
			v0 = *bhScePtr;
			bhCetask->adday = (int)(v0 * (65536.0f / 360.0f)) >> 0x1;
			bhScePtr++;
			v0 = *bhScePtr;
			bhCetask->addaz = (int)(v0 * (65536.0f / 360.0f)) >> 0x1;
			bhScePtr++;
			bhScePtr++;
        }
        break;
        case 0xC:
            bhScePtr++;
            bhCetask->bpx = *bhScePtr++;
            bhCetask->bpy = *bhScePtr++;
            bhCetask->bpz = *bhScePtr++;
            bhScePtr++;
        break;
        case 0xD:
            bhScePtr++;
            bhCetask->bax = *bhScePtr++;
            bhCetask->bay = *bhScePtr++;
            bhCetask->baz = *bhScePtr++;
            bhScePtr++;
        break;
        case 7:
            bhScePtr++;
            if (bhCetask->bpx == '\0') 
            {
                bhCetask->work->px = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                bhCetask->work->px = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhCetask->work->pxb = bhCetask->work->px;
            bhScePtr += 2;
            if (bhCetask->bpy == '\0') 
            {
                bhCetask->work->py = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                bhCetask->work->py = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhCetask->work->pyb = bhCetask->work->py;
            bhCetask->work->flr_no = bhCheckFloorNum(bhCetask->work->py);
            bhScePtr += 2;
            if (bhCetask->bpz == '\0') 
            {
                bhCetask->work->pz = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                bhCetask->work->pz = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhCetask->work->pzb = bhCetask->work->pz;
            bhScePtr += 2;
        break;
        case 11:
        {
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            if (bhCetask->bax != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->ax = v0 * 182.04445f;
            bhCetask->work->axb = bhCetask->work->ax;
            bhScePtr++;
            v0 = *bhScePtr;
            if (bhCetask->bay != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->ay = v0 * 182.04445f;
            bhCetask->work->ayb = bhCetask->work->ay;
            bhScePtr++;
            v0 = *bhScePtr;
            if (bhCetask->baz != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->az = v0 * 182.04445f;
            bhCetask->work->azb = bhCetask->work->az;
            bhScePtr += 2;
        }
        break;
        case 8:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            
            bhScePtr++;
            if (bhCetask->bpx == '\0') 
            {
                objP->pos[0] = *(unsigned short *)bhScePtr / 100.0f;
            }
            else
            {
                objP->pos[0] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhScePtr += 2;
            if (bhCetask->bpy == '\0') 
            {
                objP->pos[1] = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                objP->pos[1] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhScePtr += 2;
            if (bhCetask->bpz == '\0')
            {
                objP->pos[2] = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                objP->pos[2] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhScePtr += 2;
        }
        break;
        case 9:
        {
            int v1; 
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            bhScePtr++;
            v1 = *bhScePtr;
            if (bhCetask->bax != '\0') 
            {
                v1 = -v1;
            }
            objP->ang[0] = v1 * 182.04445f;
            bhScePtr++;
            v1 = *bhScePtr;
            if (bhCetask->bay != '\0') 
            {
                v1 = -v1;
            }
            objP->ang[1] = v1 * 182.04445f;
            bhScePtr++;
            v1 = *bhScePtr;
            if (bhCetask->baz != '\0')
            {
                v1 = -v1;
            }
            objP->ang[2] = v1 * 182.04445f;
            bhScePtr += 2;
        }
        break;
        case 2:
            if (bhCetask->bpx == '\0')
            {
                bhCetask->work->px += bhCetask->addpx;
            }
            else
            {
                bhCetask->work->px -= bhCetask->addpx;
            }
            if (bhCetask->bpy == '\0')
            {
                bhCetask->work->py += bhCetask->addpy;
            }
            else 
            {
                bhCetask->work->py -= bhCetask->addpy;
            }
            if (bhCetask->bpz == '\0') 
            {
                bhCetask->work->pz += bhCetask->addpz;
            }
            else
            {
                bhCetask->work->pz -= bhCetask->addpz;
            }
            bhScePtr++;
            bhScePtr++;
        break;
        case 3:
            if (bhCetask->bax == '\0')
            {
                bhCetask->work->ax += bhCetask->addax;
            }
            else 
            {
                bhCetask->work->ax -= bhCetask->addax;
            }
            if (bhCetask->bay == '\0') 
            {
                bhCetask->work->ay += bhCetask->adday;
            }
            else 
            {
                bhCetask->work->ay -= bhCetask->adday;
            }
            if (bhCetask->baz == '\0')
            {
                bhCetask->work->az += bhCetask->addaz;
            }
            else
            {
                bhCetask->work->az -= bhCetask->addaz;
            }
            bhScePtr++;
            bhScePtr++;
        break;
        case 4:
            if (bhCetask->bpx == '\0') 
            {
                bhCetask->work->px += bhCetask->addpx;
            }
            else 
            {
                bhCetask->work->px -= bhCetask->addpx;
            }
            if (bhCetask->bpy == '\0') 
            {
                bhCetask->work->py += bhCetask->addpy;
            }
            else 
            {
                bhCetask->work->py -= bhCetask->addpy;
            }
            if (bhCetask->bpz == '\0') 
            {
                bhCetask->work->pz += bhCetask->addpz;
            }
            else 
            {
                bhCetask->work->pz -= bhCetask->addpz;
            }
            if (bhCetask->bax == '\0') 
            {
                bhCetask->work->ax += bhCetask->addax;
            }
            else
            {
                bhCetask->work->ax -= bhCetask->addax;
            }
            if (bhCetask->bay == '\0') 
            {
                bhCetask->work->ay += bhCetask->adday;
            }
            else 
            {
                bhCetask->work->ay -= bhCetask->adday;
            }
            if (bhCetask->baz == '\0') 
            {
                bhCetask->work->az += bhCetask->addaz;
            }
            else 
            {
                bhCetask->work->az -= bhCetask->addaz;
            }
            bhScePtr++;
            bhScePtr++;
        break;
        case 17:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            
            if (bhCetask->bpx == '\0') 
            {
                objP->pos[0] += bhCetask->addpx;
            }
            else 
            {
                objP->pos[0] -= bhCetask->addpx;
            }
            if (bhCetask->bpy == '\0') 
            {
                objP->pos[1] += bhCetask->addpy;
            }
            else 
            {
                objP->pos[1] -= bhCetask->addpy;
            }
            if (bhCetask->bpz == '\0') 
            {
                objP->pos[2] += bhCetask->addpz;
            }
            else
            {
                objP->pos[2] -= bhCetask->addpz;
            }
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 18:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            
            if (bhCetask->bax == '\0')
            {
                objP->ang[0] += bhCetask->addax;
            }
            else
            {
                objP->ang[0] -= bhCetask->addax;
            }
            if (bhCetask->bay == '\0') 
            {
                objP->ang[1] += bhCetask->adday;
            }
            else 
            {
                objP->ang[1] -= bhCetask->adday;
            }
            if (bhCetask->baz == '\0')
            {
                objP->ang[2] += bhCetask->addaz;
            }
            else 
            {
                objP->ang[2] -= bhCetask->addaz;
            }
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 19:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            if (bhCetask->bpx == '\0') 
            {
                objP->pos[0] += bhCetask->addpx;
            }
            else 
            {
                objP->pos[0] -= bhCetask->addpx;
            }
            if (bhCetask->bpy == '\0') 
            {
                objP->pos[1] += bhCetask->addpy;
            }
            else
            {
                objP->pos[1] -= bhCetask->addpy;
            }
            if (bhCetask->bpz == '\0') 
            {
                objP->pos[2] += bhCetask->addpz;
            }
            else
            {
                objP->pos[2] -= bhCetask->addpz;
            }
            if (bhCetask->bax == '\0') 
            {
                objP->ang[0] += bhCetask->addax;
            }
            else 
            {
                objP->ang[0] -= bhCetask->addax;
            }
            if (bhCetask->bay == '\0') 
            {
                objP->ang[1] += bhCetask->adday;
            }
            else
            {
                objP->ang[1] -= bhCetask->adday;
            }
            if (bhCetask->baz == '\0') 
            {
                objP->ang[2] += bhCetask->addaz;
            }
            else 
            {
                objP->ang[2] -= bhCetask->addaz;
            }
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 22:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            
            bhScePtr++;
            switch(*bhScePtr) 
            {
                case 0:
                    bhScePtr += 2;
                    if (bhCetask->bpx == '\0') 
                    {
                        objP->pos[0] = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        objP->pos[0] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
                case 1:
                    bhScePtr += 2;
                    if (bhCetask->bpy == '\0') 
                    {
                        objP->pos[1] = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        objP->pos[1] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
                case 2:
                    bhScePtr += 2;
                    if (bhCetask->bpz == '\0') 
                    {
                        objP->pos[2] = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        objP->pos[2] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
            }
        }
        break;
        case 10:
            bhScePtr++;
            
            switch(*bhScePtr) 
            {
                case 0:
                    bhScePtr += 2;
                    if (bhCetask->bpx == '\0') 
                    {
                        bhCetask->work->px = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        bhCetask->work->px = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
                case 1:
                    bhScePtr += 2;
                    if (bhCetask->bpy == '\0') 
                    {
                        bhCetask->work->py = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        bhCetask->work->py = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
                case 2:
                    bhScePtr += 2;
                    if (bhCetask->bpz == '\0') 
                    {
                        bhCetask->work->pz = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        bhCetask->work->pz = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
            }
        break;
        case 132:
            bhCetask->work->mode0 = '\x01';
            bhCetask->work->mode2 = '\0';
            bhCetask->work->mode3 = '\0';
            
            bhScePtr++;
            bhCetask->work->mode1 = *bhScePtr++;
            
            if (*bhScePtr == '\0') 
            {
                bhCetask->work->mode0 = '\x01';
            }
            else 
            {
                bhCetask->work->mode0 = '\x05';
            }

            bhScePtr++;
            bhCetask->work->ct1 = *bhScePtr++;
            bhCetask->work->ct2 = *bhScePtr++;
        break;
        case 140:
        {
            unsigned int v0; 
            
            bhCetask->work->mode2 = '\0';
            bhCetask->work->mode3 = '\0';
            
            bhScePtr++;
            bhCetask->work->mode1 = *bhScePtr++;
            
            if (*bhScePtr == '\0') 
            {
                bhCetask->work->mode0 = '\x01';
                *(unsigned char *)&bhCetask->work->ct2 = 0x1;
            }
            else 
            {
                bhCetask->work->mode0 = '\x05';
                *(unsigned char *)&bhCetask->work->ct2 = 0x3;
            }
            
            bhScePtr++;
            v0 = *(unsigned short *)bhScePtr;
            if (bhCetask->bpx == '\0') 
            {
                bhCetask->work->ct0 = v0 << 0x10;
            }
            else
            {
                bhCetask->work->ct0 = (v0 * -1) << 0x10;
            }
            
            bhScePtr += 2;
            v0 = *(unsigned short *)bhScePtr;
            if (bhCetask->bpz == '\0') 
            {
                bhCetask->work->ct0 |= v0;
            }
            else 
            {
                bhCetask->work->ct0 |= v0 * -1;
            }
            bhScePtr += 2;
        }
        break;
        case 141:
            bhCetask->work->mode0 = '\x05';
            bhCetask->work->mode2 = '\0';
            bhCetask->work->mode3 = '\0';
            
            bhScePtr++;
            bhCetask->work->mode1 = *bhScePtr++;
            bhCetask->work->ct0 = *bhScePtr++;
            bhCetask->work->ct1 = *bhScePtr++;
            bhCetask->work->ct2 = *bhScePtr++;
        break;
        case 14:
        {
            unsigned int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhCetask->work->ct3 = v0;
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 21:
        {
            unsigned int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhCetask->work->ct1 = v0;
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 15:
        {
            int v0; 
            
            bhScePtr++;
            v0 = (unsigned int)*bhScePtr;
            if (bhCetask->bax != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->ax = v0 * 182.04445f;
            bhCetask->work->axb = bhCetask->work->ax;
            bhCetask->work->mlwP->objP->ang[0x0] = v0 * 182.04445f;
            bhScePtr++;
            v0 = (unsigned int)*bhScePtr;
            if (bhCetask->bay != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->ay = v0 * 182.04445f;
            bhCetask->work->ayb = bhCetask->work->ay;
            bhCetask->work->mlwP->objP->ang[0x1] = v0 * 182.04445f;
            bhScePtr++;
            v0 = (unsigned int)*bhScePtr;
            if (bhCetask->baz != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->az = v0 * 182.04445f;
            bhCetask->work->azb = bhCetask->work->az;
            bhCetask->work->mlwP->objP->ang[0x2] = v0 * 182.04445f;
            bhScePtr += 2;
        }
        break;
        case 16:
        {
            int v0;
            int v1; 
            unsigned char* a0; 
            
            bhScePtr++;
            a0 = bhScePtr;
            
            v0 = a0[0];
            v1 = a0[3];
            if ((v1 & 0x1) != 0x0)
            {
                v0 = -v0;
            }
            bhCetask->work->mlwP->objP[0x1].ang[0x0] = v0 * 182.04445f;
            bhScePtr++;
            v0 = *bhScePtr;
            if ((v1 & 0x2) != 0x0) 
            {
                v0 = -v0;
            }
            bhCetask->work->mlwP->objP[0x1].ang[0x1] = v0 * 182.04445f;
            bhScePtr++;
            v0 = *bhScePtr;
            if ((v1 & 0x4) != 0x0)
            {
                v0 = -v0;
            }
            bhCetask->work->mlwP->objP[0x1].ang[0x2] = v0 * 182.04445f;
            bhScePtr += 2;
        }
        break;
        case 36:
            bhCetask->work->mlwP->objP->pos[0x0] = 0.0f;
            bhCetask->work->mlwP->objP->pos[0x1] = 0.0f;
            bhCetask->work->mlwP->objP->pos[0x2] = 0.0f; 
            bhScePtr++;
        break;
        case 38:
        {
            int v0; 
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            
            if ((v1 & 0x1) != 0x0)
            {
                bhCetask->work->mlwP->objP[v0].pos[0x0] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else
            {
                bhCetask->work->mlwP->objP[v0].pos[0x0] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
            if ((v1 & 0x2) != 0x0)
            {
                bhCetask->work->mlwP->objP[v0].pos[0x1] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->work->mlwP->objP[v0].pos[0x1] = *(unsigned short *)bhScePtr / 100.0f;
            }
            
            bhScePtr += 2;
            if ((v1 & 0x4) != 0x0) 
            {
                bhCetask->work->mlwP->objP[v0].pos[0x2] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->work->mlwP->objP[v0].pos[0x2] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
        }
        break;
        case 0:
            bhScePtr++;
        break;
    }
}

// 100% matching! 
unsigned int bhLoadWork()
{
    ETTY_WORK* e_enep;

    bhScePtr++;
    
    switch (*bhScePtr) 
    {                         
    case 0:
        bhCetask->work = plp;
        
        bhCetask->work->mode0 = 7;
        bhCetask->work->mode2 = 0;
        bhCetask->work->mode2 = 0; // strange this wasn't optimized out
        
        *(unsigned char*)&bhCetask->work->mtn_no = 42;
        
        bhCetask->work->stflg |= 0x10000;
        bhCetask->work->stflg &= ~0x80;
        
        bhCetask->model_cno = 0;
        
        bhCetask->work->flg |= 0x10000;
        
        bhScePtr += 3;
        break;
    case 1:
    {
        unsigned char* a0;
        
        a0 = bhScePtr;
        
        bhScePtr++;
        bhScePtr += 2;
        
        e_enep = &rom->enep[*++a0];
        
        bhCetask->work = &ene[e_enep->wrk_no];
        
        bhCetask->model_cno = *++a0;
        
        bhCetask->mtn_md = bhCetask->work->mtn_md;
        bhCetask->mdflg = bhCetask->work->mdflg;
        
        bhCetask->hokan_rate = bhCetask->work->hokan_rate;
        break;
    }
    case 2:
    {
        unsigned char* a0;
        
        a0 = bhScePtr;
        
        bhScePtr++;
        bhScePtr += 2;
        
        bhCetask->work = (BH_PWORK*)&sys->obwp[*++a0];
        
        bhCetask->model_cno = *++a0;
        break;
    }
    case 3:
    {
        unsigned char* a0;
        
        a0 = bhScePtr;
        
        bhScePtr++;
        bhScePtr += 2;
        
        bhCetask->work = (BH_PWORK*)&sys->itwp[*++a0];
        
        bhCetask->model_cno = 0;
        break;
    }
    case 4:
    {
        unsigned char* a0;
        
        a0 = bhScePtr;
        
        bhScePtr++;
        bhScePtr += 2;
        
        bhCetask->work = (BH_PWORK*)&eff[sys->efid[*++a0]];
        
        bhCetask->model_cno = 0;
        break;
    }
    }
    
    return 1;
}

// 100% matching! 
unsigned int bhLoadWorkEx()
{
    ETTY_WORK* e_enep;

    bhScePtr++;
    
    switch (*bhScePtr) 
    {                         
    case 0:
        bhEtask->work = plp;
        
        bhEtask->work->mode0 = 7;
        bhEtask->work->mode2 = 0;
        bhEtask->work->mode2 = 0; // strange this wasn't optimized out
        
        *(unsigned char*)&bhEtask->work->mtn_no = 42;
        
        bhEtask->work->stflg |= 0x10000;
        bhEtask->work->stflg &= ~0x80;
        
        bhEtask->work->flg |= 0x10000;

        bhEtask->model_cno = 0;
        
        bhScePtr += 3;
        break;
    case 1:
    {
        unsigned char* a0;
        
        a0 = bhScePtr;
        
        bhScePtr++;
        bhScePtr += 2;
        
        e_enep = &rom->enep[*++a0];
        
        bhEtask->work = &ene[e_enep->wrk_no];
        
        bhEtask->model_cno = *++a0;
        
        bhEtask->mtn_md = bhEtask->work->mtn_md;
        bhEtask->mdflg = bhEtask->work->mdflg;
        
        bhEtask->hokan_rate = bhEtask->work->hokan_rate;
        break;
    }
    case 2:
    {
        unsigned char* a0;
        
        a0 = bhScePtr;
        
        bhScePtr++;
        bhScePtr += 2;
        
        bhEtask->work = (BH_PWORK*)&sys->obwp[*++a0];
        
        bhEtask->model_cno = *++a0;
        break;
    }
    case 3:
    {
        unsigned char* a0;
        
        a0 = bhScePtr;
        
        bhScePtr++;
        bhScePtr += 2;
        
        bhEtask->work = (BH_PWORK*)&sys->itwp[*++a0];
        
        bhEtask->model_cno = 0;
        break;
    }
    case 4:
    {
        unsigned char* a0;
        
        a0 = bhScePtr;
        
        bhScePtr++;
        bhScePtr += 2;
        
        bhEtask->work = (BH_PWORK*)&eff[sys->efid[*++a0]];
        
        bhEtask->model_cno = 0;
        break;
    }
    }
    
    return 1;
}

// 100% matching! 
unsigned int bhLoadWork2()
{
    ETTY_WORK* e_enep;
    unsigned int tk_no;

    bhScePtr++;
    
    switch (*bhScePtr) 
    {                             
    case 0:
        bhCetask->work = plp;
        
        bhCetask->work->mode0 = 7;
        
        bhCetask->work->stflg |= 0x10000;
        bhCetask->work->flg |= 0x10000;
        
        bhCetask->model_cno = 0;
        break;
    case 1:
    {
        unsigned char* a0;
        
        a0 = bhScePtr;
        
        e_enep = &rom->enep[*++a0]; 
        
        bhCetask->work = &ene[e_enep->wrk_no];
        break;
    }
    case 2:
    {
        unsigned char* a0; 
        
        a0 = bhScePtr;
        
        a0++;
        
        tk_no = *++a0;
        
        bhEtask[tk_no].work = (BH_PWORK*)&sys->obwp[*++a0];
        
        bhEtask[tk_no].model_cno = *++a0;
        break;
    }
    }
    
    bhScePtr += 5;
    
    return 1;
}

// 100% matching!
int Event_init(BH_SCEWORK* a0, unsigned int evt_id) 
{
    a0->status = 1;
    
    *(short*)&a0->mode0 = 0;
    
    a0->data = (unsigned char*)rom->evtp;
    a0->data = (unsigned char*)a0->data + ((int*)rom->evtp)[evt_id + ((sizeof(EVT_WORK) / 4) - 1)];
    
    a0->loop = -1;
    
    a0->ips[0][0] = 0;
    a0->ips[0][1] = 0;
    a0->ips[0][2] = 0;
    
    a0->ips[1][0] = 0;
    a0->ips[1][1] = 0;
    a0->ips[1][2] = 0;
    
    a0->ips[2][0] = 0;
    a0->ips[2][1] = 0;
    a0->ips[2][2] = 0;
    
    a0->ips[3][0] = 0;
    a0->ips[3][1] = 0;
    a0->ips[3][2] = 0;
    
    a0->ian[0][0] = 0;
    a0->ian[0][1] = 0;
    a0->ian[0][2] = 0;
    
    a0->ian[1][0] = 0;
    a0->ian[1][1] = 0;
    a0->ian[1][2] = 0;
    
    a0->ian[2][0] = 0;
    a0->ian[2][1] = 0;
    a0->ian[2][2] = 0;
    
    a0->ian[3][0] = 0;
    a0->ian[3][1] = 0;
    a0->ian[3][2] = 0;
}

// 100% matching!
int Event_exec(unsigned int task_level, unsigned int evt_id)
{
    if (task_level >= 16)
    {
        task_level = 0;
        
        while ((bhEtask[task_level].status != 0) && (task_level != 15))
        {
            task_level++;
        }
    }

    return Event_init(&bhEtask[task_level], evt_id);
}

// 100% matching!
int bhEventScheduler2()
{
    unsigned int level;      
    unsigned int t_time_flg; 
    unsigned char* gsp; // not from DWARF
    BH_SCEWORK* scep;   // not from DWARF

    if ((sys->sp_flg & 0x10)) 
    {
        scep = bhEtask;
        
        t_time_flg = 0;
        
        for (level = 0; level < 16; level++, scep++) 
        {
            bhCetask = scep;
            
            if (scep->status != 0) 
            {
                if (t_time_flg == 0) 
                {
                    Event_T_timer++;
                }
                
                t_time_flg = 1;
                
                bhScePtr = scep->data;
                
                while (TRUE) 
                {
                    while (bhScenarioJmpT[*bhScePtr]() != 0);
                    
                    if (bhIfelFlg <= 0)
                    {
                        break;
                    }
                    
                    gsp = (unsigned char*)--G_Sp;
                    
                    bhIfelFlg--;
                    
                    bhScePtr = gsp;
                }
                
                bhCetask->data = bhScePtr;
            }
        } 
    }
}

// 100% matching!
void bhScenarioCheck(unsigned char* next_ptr)
{
    unsigned char* gsp; // not from DWARF
    
    bhScePtr = (unsigned char*)rom->evtp;
    
    bhIfelFlg = 0;
    
    bhScePtr = &bhScePtr[(int)next_ptr];

    while (TRUE) 
    {
        while (bhScenarioJmpT[*bhScePtr]() != 0);
        
        if (bhIfelFlg <= 0)
        {
            break;
        }
        
        gsp = (unsigned char*)--G_Sp;
        
        bhIfelFlg--;
        
        bhScePtr = gsp;
    }
}

// 100% matching!
unsigned int bhFlagCk(unsigned char type, unsigned int cnt, unsigned char flag) 
{
    int* v0;

    switch (type) 
    {
    case 1:
        v0 = (int*)sys->ev_flg;
        break;
    case 2:
        v0 = (int*)sys->ky_flg;
        break;
    case 3:
        v0 = (int*)sys->ed_flg;
        break;
    case 4:
        v0 = (int*)&sys->rm_flg;
        break;
    case 5:
        v0 = (int*)&sys->st_flg;
        break;
    case 6:
        v0 = (int*)&sys->sp_flg;
        break;
    case 7:
        v0 = (int*)sys->it_flg;
        break;
    case 8:
        v0 = (int*)sys->mp_flg;
        break;
    case 9:
        v0 = (int*)sys->ic_flg;
        break;
    case 11:
        v0 = (int*)&sys->gm_flg;
        break;
    }
    
    return flag ^ (v0[(cnt & 0x3FF) >> 5] << (cnt & 0x1F)) < 0;
}

// 100% matching! 
unsigned int bhFlagSet(unsigned char type, unsigned int cnt, unsigned char flag)
{
    int* v0;
    int v1; 
    
    switch (type) 
    {
    case 1:
        v0 = (int*)&sys->ev_flg;
        break;
    case 2:
        v0 = (int*)&sys->ky_flg;
        break;
    case 3:
        v0 = (int*)&sys->ed_flg;
        break;
    case 4:
        v0 = (int*)&sys->rm_flg;
        break;
    case 5:
        v0 = (int*)&sys->st_flg;
        break;
    case 6:
        v0 = (int*)&sys->sp_flg;
        break;
    case 7:
        v0 = (int*)&sys->it_flg;
        break;
    case 8:
        v0 = (int*)&sys->mp_flg;
        break;
    case 9:
        v0 = (int*)&sys->ic_flg;
        break;
    case 11:
        v0 = (int*)&sys->gm_flg;
        break;
    }

    v0 = &v0[(cnt & 0x3E0) >> 5]; 
    
    cnt &= 0x1F;

    switch (flag) 
    {     
    case 0:          
        v1 = 0x80000000 >> cnt;
        
        *v0 |= v1;
        
        return 1;
    case 1:         
        v1 = ~(0x80000000 >> cnt);
            
        *v0 &= v1;
        
        return 1;
    case 2:            
        v1 = 0x80000000 >> cnt;
        
        *v0 ^= v1;
        
        return 1;
    }
}

// 100% matching!
void bhChangeViewClip(char stg_no, char rom_no, char rcase, int evc_no)
{
    int i;
    float near, far;
    static VIEW_CLIP* ViewClipTbl;
    static VIEW_CLIP ViewClipSt0[8] =
	{
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -24.0f,      /* far */ -5000.0f  }, 
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 4,  /* near */ -25.0f,      /* far */ -20000.0f }, 
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 12, /* near */ -9.0f,       /* far */ -20000.0f }, 
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 3,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 23, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 29, /* near */ -10.0f,      /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt1[15] =
	{
        { /* room */ 0,  /* rcase */ 2,  /* evc_no */ 8,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 2,  /* evc_no */ 33, /* near */ -10.0f,      /* far */ -20000.0f }, 
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 5,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 8,  /* near */ -4.0f,       /* far */ -20000.0f }, 
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 11, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 15, /* near */ -1.9f,       /* far */ -20000.0f }, 
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 17, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 34, /* near */ -1.1f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 16, /* near */ -20.0f,      /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 20, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 21, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 23, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 29, /* near */ -1.5f,       /* far */ -20000.0f }, 
        { /* room */ 12, /* rcase */ 2,  /* evc_no */ 13, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt2[10] = 
	{
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 12, /* near */ -5.0f,       /* far */ -20000.0f }, 
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 8,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -10.0f,      /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 7,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 8,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 19, /* near */ -1.8f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 20, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 22, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt3[21] = 
	{
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 3,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 5,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 7,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 31, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 40, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 1,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 9,  /* near */ -1.01f,      /* far */ -5000.0f  }, 
        { /* room */ 8,  /* rcase */ 0,  /* evc_no */ 7,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 18, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 21, /* near */ -1.7f,       /* far */ -20000.0f }, 
        { /* room */ 13, /* rcase */ 0,  /* evc_no */ 28, /* near */ -20.799999f, /* far */ -20000.0f }, 
        { /* room */ 14, /* rcase */ 0,  /* evc_no */ 7,  /* near */ -5.0f,       /* far */ -20000.0f }, 
        { /* room */ 14, /* rcase */ 0,  /* evc_no */ 8,  /* near */ -1.1f,       /* far */ -20000.0f }, 
        { /* room */ 23, /* rcase */ 0,  /* evc_no */ 11, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 24, /* rcase */ 0,  /* evc_no */ 4,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 24, /* rcase */ 0,  /* evc_no */ 5,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 24, /* rcase */ 0,  /* evc_no */ 6,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 24, /* rcase */ 0,  /* evc_no */ 9,  /* near */ -60.0f,      /* far */ -20000.0f }, 
        { /* room */ 24, /* rcase */ 0,  /* evc_no */ 11, /* near */ -1.5f,       /* far */ -20000.0f }, 
        { /* room */ 24, /* rcase */ 0,  /* evc_no */ 28, /* near */ -26.0f,      /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt4[3] = 
	{
        { /* room */ 1,  /* rcase */ 0,  /* evc_no */ 8,  /* near */ -10.0f,      /* far */ -1000.0f  }, 
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 3,  /* near */ -20.0f,      /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt5[10] = 
	{
        { /* room */ 0,  /* rcase */ 1,  /* evc_no */ 1,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 1,  /* evc_no */ 9,  /* near */ -10.0f,      /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 1,  /* evc_no */ 11, /* near */ -60.0f,      /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 1,  /* evc_no */ 17, /* near */ -20.0f,      /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 1,  /* evc_no */ 19, /* near */ -10.0f,      /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 1,  /* evc_no */ 21, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 1,  /* rcase */ 0,  /* evc_no */ 26, /* near */ -1.5599999f, /* far */ -20000.0f }, 
        { /* room */ 1,  /* rcase */ 0,  /* evc_no */ 30, /* near */ -1.2f,       /* far */ -20000.0f }, 
        { /* room */ 1,  /* rcase */ 0,  /* evc_no */ 32, /* near */ -1.01f,      /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt6[16] = 
	{
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 10, /* near */ -10.0f,      /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 8,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 40, /* near */ -44.0f,      /* far */ -20000.0f }, 
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 17, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 18, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 20, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 21, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 35, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 1,  /* evc_no */ 13, /* near */ -1.2f,       /* far */ -20000.0f }, 
        { /* room */ 6,  /* rcase */ 0,  /* evc_no */ 7,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 16, /* near */ -1.1f,       /* far */ -20000.0f }, 
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 17, /* near */ -5.0f,       /* far */ -20000.0f }, 
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 19, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 30, /* near */ -1.01f,      /* far */ -20000.0f }, 
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 32, /* near */ -550.0f,     /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt7[9] = 
	{
        { /* room */ 7,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 7,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -5.0f,       /* far */ -20000.0f }, 
        { /* room */ 7,  /* rcase */ 0,  /* evc_no */ 4,  /* near */ -20.0f,      /* far */ -20000.0f }, 
        { /* room */ 7,  /* rcase */ 0,  /* evc_no */ 15, /* near */ -1.5f,       /* far */ -20000.0f }, 
        { /* room */ 7,  /* rcase */ 0,  /* evc_no */ 26, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 8,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -1.01f,      /* far */ -20000.0f }, 
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 5,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 24, /* rcase */ 0,  /* evc_no */ 2,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt8[4] = 
	{
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -1.01f,      /* far */ -20000.0f }, 
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 4,  /* near */ -35.0f,      /* far */ -20000.0f }, 
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 9,  /* near */ -1.1f,       /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt9[27] = 
	{
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 4,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 8,  /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 14, /* near */ -10.0f,      /* far */ -20000.0f }, 
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 34, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 4,  /* near */ -1.1f,       /* far */ -20000.0f }, 
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 6,  /* near */ -27.0f,      /* far */ -20000.0f }, 
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 16, /* near */ -35.0f,      /* far */ -8000.0f  }, 
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 28, /* near */ -125.0f,     /* far */ -20000.0f }, 
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 43, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 58, /* near */ -5.0f,       /* far */ -20000.0f }, 
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 61, /* near */ -30.0f,      /* far */ -20000.0f }, 
        { /* room */ 16, /* rcase */ 0,  /* evc_no */ 0,  /* near */ -10.0f,      /* far */ -1000.0f  }, 
        { /* room */ 28, /* rcase */ 0,  /* evc_no */ 10, /* near */ -1.01f,      /* far */ -170.0f   }, 
        { /* room */ 28, /* rcase */ 0,  /* evc_no */ 34, /* near */ -2.0f,       /* far */ -183.0f   }, 
        { /* room */ 29, /* rcase */ 0,  /* evc_no */ 3,  /* near */ -1.2f,       /* far */ -20000.0f }, 
        { /* room */ 32, /* rcase */ 1,  /* evc_no */ 41, /* near */ -1.01f,      /* far */ -20000.0f }, 
        { /* room */ 34, /* rcase */ 0,  /* evc_no */ 13, /* near */ -150.0f,     /* far */ -20000.0f }, 
        { /* room */ 34, /* rcase */ 0,  /* evc_no */ 27, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 35, /* rcase */ 0,  /* evc_no */ 11, /* near */ -10.0f,      /* far */ -20000.0f }, 
        { /* room */ 35, /* rcase */ 0,  /* evc_no */ 20, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 35, /* rcase */ 0,  /* evc_no */ 26, /* near */ -1.01f,      /* far */ -20000.0f }, 
        { /* room */ 35, /* rcase */ 0,  /* evc_no */ 41, /* near */ -1.2f,       /* far */ -20000.0f }, 
        { /* room */ 35, /* rcase */ 0,  /* evc_no */ 48, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 37, /* rcase */ 0,  /* evc_no */ 33, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ 37, /* rcase */ 0,  /* evc_no */ 62, /* near */ -1.0f,       /* far */ -20000.0f }, 
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,        /* far */ 0.0f      }
    };
    static VIEW_CLIP* ViewClipStage[10] = 
	{
        ViewClipSt0,
        ViewClipSt1,
        ViewClipSt2,
        ViewClipSt3,
        ViewClipSt4,
        ViewClipSt5,
        ViewClipSt6,
        ViewClipSt7,
        ViewClipSt8,
        ViewClipSt9
    };
    
    if ((sys->ts_flg & 0x200)) 
	{
        near = -2.0f;
        far = -20000.0f;
    } 
	else 
	{
        near = -1.0f;
        far = -99.0f;
    }

	for (i = 0, ViewClipTbl = ViewClipStage[stg_no]; ; i++) 
	{
        if (((rom_no == ViewClipTbl[i].room) && (rcase == ViewClipTbl[i].rcase)) && (evc_no == ViewClipTbl[i].evc_no)) 
		{
            near = ViewClipTbl[i].near;
            far = ViewClipTbl[i].far;
            break;
        } 
		else if (ViewClipTbl[i].room < 0) 
		{
            break;
        }
    }
    
    njClipZ(near, far);
        
    if ((stg_no == 9) && (rom_no == 5)) 
	{
        if (evc_no == 36) 
		{
			Ps2_ice_flag = 0;
		}
        else 
		{
			Ps2_ice_flag = 1;
		}
    }
}

// 100% matching!
void bhChangeViewClipRM()
{
	int i;
    static VIEW_CLIP* ViewClipTbl;
    static VIEW_CLIP ViewClipSt0[9] = 
	{
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -10.0f,     /* far */ -1000.0f  },
        { /* room */ 1,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -1.5,       /* far */ -20000.0f },
        { /* room */ 1,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -1.01f,     /* far */ -20000.0f },
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 4,  /* near */ -4.0f,      /* far */ -20000.0f },
        { /* room */ 2,  /* rcase */ 1,  /* evc_no */ 4,  /* near */ -4.0f,      /* far */ -20000.0f },
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 1,  /* near */ -8.72,      /* far */ -20000.0f },
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 2,  /* near */ -5.0f,      /* far */ -20000.0f },
        { /* room */ 16, /* rcase */ 0,  /* evc_no */ 2,  /* near */ -6.0f,      /* far */ -20000.0f },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt1[6] = 
	{
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 6,  /* near */ -10.0f,     /* far */ -1000.0f  },
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -10.0f,     /* far */ -1000.0f  },
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -22.0f,     /* far */ -20000.0f },
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -20.0f,     /* far */ -20000.0f },
        { /* room */ 11, /* rcase */ 0,  /* evc_no */ 2,  /* near */ -10.0f,     /* far */ -20000.0f },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt2[6] = 
	{
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -10.0f,     /* far */ -1000.0f  },
        { /* room */ 2,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -10.0f,     /* far */ -1000.0f  },
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -3.1199999, /* far */ -20000.0f },
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -10.0f,     /* far */ -2000.0f  },
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -10.0f,     /* far */ -1000.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt3[5] = 
	{
        { /* room */ 7,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -3.5,       /* far */ -20000.0f },
        { /* room */ 8,  /* rcase */ 0,  /* evc_no */ 5,  /* near */ -1.0f,      /* far */ -20000.0f },
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 8,  /* near */ -9.0f,      /* far */ -20000.0f },
        { /* room */ 15, /* rcase */ 0,  /* evc_no */ 1,  /* near */ -1.0f,      /* far */ -600.0f   },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt4[5] = 
	{
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -4.0f,      /* far */ -20000.0f },
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -22.0f,     /* far */ -20000.0f },
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -22.0f,     /* far */ -20000.0f },
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 3,  /* near */ -15.0f,     /* far */ -20000.0f },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt5[4] = 
	{
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -10.0f,     /* far */ -1000.0f  },
        { /* room */ 1,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -1.1,       /* far */ -20000.0f },
        { /* room */ 51, /* rcase */ 0,  /* evc_no */ 2,  /* near */ -10.0f,     /* far */ -20000.0f },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt6[7] = 
	{
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -44.0f,     /* far */ -20000.0f },
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -1.0f,      /* far */ -1000.0f  },
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -1.4,       /* far */ -20000.0f },
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -20.0f,     /* far */ -20000.0f },
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -25.5,      /* far */ -1000.0f  },
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 3,  /* near */ -25.5,      /* far */ -1000.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt7[4] = 
	{
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -15.0f,     /* far */ -20000.0f },
        { /* room */ 15, /* rcase */ 0,  /* evc_no */ 1,  /* near */ -10.0f,     /* far */ -20000.0f },
        { /* room */ 16, /* rcase */ 0,  /* evc_no */ 3,  /* near */ -10.0f,     /* far */ -20000.0f },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt8[2] = 
	{
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -4.0f,      /* far */ -20000.0f },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP ViewClipSt9[13] = 
	{
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -44.0f,     /* far */ -20000.0f },
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -1.0f,      /* far */ -20000.0f },
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -1.0f,      /* far */ -20000.0f },
        { /* room */ 4,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ -20.0f,     /* far */ -20000.0f },
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ -10.0f,     /* far */ -1000.0f  },
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -10.0f,     /* far */ -20000.0f },
        { /* room */ 8,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ -11.33,     /* far */ -20000.0f },
        { /* room */ 12, /* rcase */ 0,  /* evc_no */ 1,  /* near */ -3.4,       /* far */ -20000.0f },
        { /* room */ 14, /* rcase */ 0,  /* evc_no */ 0,  /* near */ -10.0f,     /* far */ -20000.0f },
        { /* room */ 14, /* rcase */ 0,  /* evc_no */ 2,  /* near */ -12.0f,     /* far */ -20000.0f },
        { /* room */ 15, /* rcase */ 0,  /* evc_no */ 3,  /* near */ -4.0f,      /* far */ -1000.0f  },
        { /* room */ 22, /* rcase */ 0,  /* evc_no */ 0,  /* near */ -5.0f,      /* far */ -20000.0f },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,       /* far */ 0.0f      }
    };
    static VIEW_CLIP* ViewClipStage[10] =
	{
        ViewClipSt0,
        ViewClipSt1,
        ViewClipSt2,
        ViewClipSt3,
        ViewClipSt4,
        ViewClipSt5,
        ViewClipSt6,
        ViewClipSt7,
        ViewClipSt8,
        ViewClipSt9
    };

    GameNear = -2.0f;
    GameFar = -20000.0f;

    if (!(cam.flg & 0x40)) 
	{
        for (i = 0, ViewClipTbl = ViewClipStage[sys->stg_no]; ; i++) 
		{
            if ((sys->rom_no == ViewClipTbl[i].room) && (cam.ncut == ViewClipTbl[i].evc_no)) 
			{
                GameNear = ViewClipTbl[i].near;
                GameFar = ViewClipTbl[i].far;
                break;
            } 
			else if (ViewClipTbl[i].room < 0) 
			{
                break;
            }
        }
    } 
	else 
	{
        GameNear = -1.0f;
    }
    
    njClipZ(GameNear, GameFar);
    
    if ((sys->stg_no == 9) && (sys->rom_no == 5)) 
	{
        Ps2_ice_flag = 1;
    }
}

// 100% matching!
void bhChangeClipVolume(char stg_no, char rom_no, char rcase, int evc_no)
{
	int i;
	float x, y;
	static VIEW_CLIP* ViewClipTbl;
    static VIEW_CLIP ViewClipSt0[1] = 
	{
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt1[1] = 
	{
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt2[1] = 
	{
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt3[2] = 
	{
        { /* room */ 15, /* rcase */ 0,  /* evc_no */ 3,  /* near */ -320.0f, /* far */ -240.0f },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt4[1] = 
	{
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt5[2] = 
	{
        { /* room */ 0,  /* rcase */ 1,  /* evc_no */ 0,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt6[3] = 
	{
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 24, /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 10, /* rcase */ 0,  /* evc_no */ 30, /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt7[1] = 
	{
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt8[1] = 
	{
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt9[4] = 
	{
        { /* room */ 28, /* rcase */ 0,  /* evc_no */ 7,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 29, /* rcase */ 0,  /* evc_no */ 0,  /* near */ -320.0f, /* far */ -240.0f },
        { /* room */ 35, /* rcase */ 0,  /* evc_no */ 45, /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP* ViewClipStage[10] = 
	{
        ViewClipSt0,
        ViewClipSt1,
        ViewClipSt2,
        ViewClipSt3,
        ViewClipSt4,
        ViewClipSt5,
        ViewClipSt6,
        ViewClipSt7,
        ViewClipSt8,
        ViewClipSt9
    };
    
    x = 320.0f;
    y = 240.0f;

    for (i = 0, ViewClipTbl = ViewClipStage[stg_no]; ; i++) 
	{
        if (((rom_no == ViewClipTbl[i].room) && (rcase == ViewClipTbl[i].rcase)) && (evc_no == ViewClipTbl[i].evc_no)) 
		{
            x = ViewClipTbl[i].near;
            y = ViewClipTbl[i].far;
            break;
        } 
		else if (ViewClipTbl[i].room < 0) 
		{
            break;
        }
    }

    _Make_ClipVolume(x, y);
}

// 100% matching!
void bhChangeClipVolumeRM()
{
    int i;
	float x, y;
	static VIEW_CLIP* ViewClipTbl;
    static VIEW_CLIP ViewClipSt0[5] =
	{
        { /* room */ 7,  /* rcase */ 0,  /* evc_no */ 6,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 15, /* rcase */ 0,  /* evc_no */ 0,  /* near */ 1740.0f, /* far */ 1740.0f },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt1[3] = 
	{
        { /* room */ 0,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 6,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt2[1] = 
	{
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt3[4] = 
	{
        { /* room */ 8,  /* rcase */ 0,  /* evc_no */ 7,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 12, /* rcase */ 0,  /* evc_no */ 3,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 16, /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt4[1] = 
	{
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt5[5] = 
	{
        { /* room */ 54, /* rcase */ 0,  /* evc_no */ 7,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 63, /* rcase */ 0,  /* evc_no */ 3,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 66, /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 68, /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt6[5] = 
	{
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt7[8] = 
	{
        { /* room */ 3,  /* rcase */ 1,  /* evc_no */ 3,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 7,  /* rcase */ 0,  /* evc_no */ 5,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 8,  /* rcase */ 0,  /* evc_no */ 3,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 8,  /* rcase */ 0,  /* evc_no */ 4,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 9,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 20, /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 22, /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt8[1] = 
	{
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP ViewClipSt9[15] = 
	{
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 3,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 0,  /* near */ 1740.0f, /* far */ 1740.0f },
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1740.0f, /* far */ 1740.0f },
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 2,  /* near */ 1740.0f, /* far */ 1740.0f },
        { /* room */ 5,  /* rcase */ 0,  /* evc_no */ 3,  /* near */ 1740.0f, /* far */ 1740.0f },
        { /* room */ 12, /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1740.0f, /* far */ 1740.0f },
        { /* room */ 12, /* rcase */ 0,  /* evc_no */ 2,  /* near */ 1740.0f, /* far */ 1740.0f },
        { /* room */ 15, /* rcase */ 0,  /* evc_no */ 3,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 15, /* rcase */ 0,  /* evc_no */ 8,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 18, /* rcase */ 0,  /* evc_no */ 1,  /* near */ 1740.0f, /* far */ 1740.0f },
        { /* room */ 32, /* rcase */ 0,  /* evc_no */ 8,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ 32, /* rcase */ 1,  /* evc_no */ 8,  /* near */ 1024.0f, /* far */ 960.0f  },
        { /* room */ -1, /* rcase */ -1, /* evc_no */ -1, /* near */ 0.0f,    /* far */ 0.0f    }
    };
    static VIEW_CLIP* ViewClipStage[10] = 
	{
        ViewClipSt0,
        ViewClipSt1,
        ViewClipSt2,
        ViewClipSt3,
        ViewClipSt4,
        ViewClipSt5,
        ViewClipSt6,
        ViewClipSt7,
        ViewClipSt8,
        ViewClipSt9
    };

    x = 320.0f;
    y = 240.0f;

    for (i = 0, ViewClipTbl = ViewClipStage[sys->stg_no]; ; i++)
	{
        if ((sys->rom_no == ViewClipTbl[i].room) && (cam.ncut == ViewClipTbl[i].evc_no)) 
		{
            x = ViewClipTbl[i].near;
            y = ViewClipTbl[i].far;
            break;
        } 
		else if (ViewClipTbl[i].room < 0) 
		{
            break;
        }
    }
	
    _Make_ClipVolume(x, y);
}
