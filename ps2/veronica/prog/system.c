// TODO: compile and link this file separatedly to remove the "system.c" include in main.c  

unsigned short pause_mes[6];
unsigned char FileWait;
unsigned char VibWait;
SYS_WORK* sys;
unsigned char* njpmemp;
HWS_WORK* hws;
NJS_VERTEX_BUF* _nj_vertex_buf_;
unsigned char* vwbmemp;
unsigned char* vebmemp;
unsigned char* freemem;
unsigned char PauseBtn;
unsigned char NowLoadDisp;
unsigned char Pause_Flag;
unsigned char pl_sleep_cnt;
BH_PWORK ply;
BH_PWORK* plp;
unsigned char* keepmem;
float BHD_ASPECT_Y;
float BHD_ASPECT_X;
unsigned char BackColorFlag;
PAD_INFO Ps2_pad;
int pd_port;
ROM_WORK* rom;
NJS_TEXMEMLIST tbuf[256];
int SoftResetFlag;
float GameFar;
float GameNear;
PAD_ACT Pad_act[20];
unsigned int Ps2_rendertex_initflag;
unsigned int Ps2_albinoid_flag;
unsigned int Ps2_ice_flag;
WPN_TAB WpnTab[23];
float FontScaleCR;
float FontScaleX;
unsigned char FontSz[126];

int bhCalcVtxBuffer();
void bhChangeHWSetting();
void bhInitSystem();
void bhInitRoomChangeSystem();
void bhSysCallInit();
void bhSysCallDiscChange();
void bhSysCallSoundMuseum();
void bhSysCallWarning();
void bhSysCallIpl();
void bhSysCallFirstmovie();
void bhSysCallTitle();
void bhSysCallOpening();
void bhFirstGameStart();
void bhSysCallPad();
void bhSysCallGame();
void bhCheckSubTask();
void bhSysCallEvent();
void bhSysCallMap();
void bhSysCallItemselect();
void bhSysCallDoordemo();
void bhSysCallMovie();
void bhSysCallEnding();
void bhSysCallGameover();
void bhSysCallTypewriter();
void bhSysCallOption();
void bhSysCallCompEvent();
void bhSysCallMonitor();
void bhSysCallSndMonitor();
void bhSysCallScreenSaver();
void bhReturnTitle();
void bhExitGame();
void bhSetEventTimer(int mode);
void EasyDispMessage(float PosY, unsigned int MessageNo);

// 100% matching!
int bhCalcVtxBuffer()
{ 
    return 0;
}

// 100% matching! 
void bhChangeHWSetting()
{ 
    sys->ss_flg ^= 2; 
    
    if ((sys->ss_flg & 0x2)) 
    { 
        sys->fog_cngct = 3;
        
        hws->vtx_opq_a = 589824; 
        hws->vtx_opq_b = 16384; 
        
        hws->vtx_trs_a = 196608; 
        hws->vtx_trs_b = 16384; 
        
        hws->vtx_punch = 16128; 
    }
    else 
    {
        sys->fog_cngct = 2; 
        
        hws->vtx_opq_a = -589824; 
        hws->vtx_opq_b = 32768; 
        
        hws->vtx_trs_a = 327680; 
        hws->vtx_trs_b = 32768; 
        
        hws->vtx_punch = 32512; 
    }
    
    hws->vtx_total = bhCalcVtxBuffer(); 

    njpmemp = &freemem[12255232 - hws->vtx_total]; 
    
    npPlusInit(); 

    vwbmemp = &freemem[12517376 - hws->vtx_total]; 
    vebmemp = &freemem[12845056 - hws->vtx_total]; 

    if ((sys->gm_flg & 0x1)) 
    { 
        njWaitVSync(); 
        njWaitVSync(); 
        njWaitVSync(); 
    }

    njChangeSystem(hws->mode, hws->frame, hws->count); 

    njSetVertexBuffer((unsigned int*)vebmemp, hws->vtx_total); 
    njInitVertexBuffer(hws->vtx_opq_a, hws->vtx_opq_b, hws->vtx_trs_a, hws->vtx_trs_b, hws->vtx_punch); 

    _nj_vertex_buf_ = (NJS_VERTEX_BUF*)vwbmemp; 

    mwPlySetDispMode(hws->mode, hws->frame, hws->count, (hws->vtx_opq_a < 0) ? 2 : (hws->vtx_opq_b < 0) ? 2 : (hws->vtx_trs_a < 0) ? 2 : (hws->vtx_trs_b < 0) ? 2 : (hws->vtx_punch < 0) ? 2 : 3); 
    
    sys->endp = njpmemp; 
} 

// 99.93% matching
void bhInitSystem()
{ 
    unsigned int free;
    unsigned int size;
    
    bhClearVSync(); 
    
    sys->ss_flg &= ~0x40440; 
    
    npSetMemory((unsigned char*)&sys->tk_flg, 175260, 0); 
    
    sys->memp = freemem; 
    sys->endp = njpmemp;
    
    sys->memp += (int)&sys->save_end - (int)&sys->version;
    
    TypewriterKeepMemory();
    
    keepmem = sys->mempb = sys->memp; 
    
    sys->loop_ct = 1; 
    
    sys->p1per = NULL; 
        
    sys->pt_flg |= ~0x0; 
    
    sys->sp_flg |= ~0x0;
    
    sys->ss_flg &= ~0x300; 
    
    plp = &ply; 
    
    sys->plp = plp; 
    
    sys->ef_pbnk = 32; 
    
    syMallocStat(&free, &size); 
    
    sys->fsize = free; 
    
    njClipZ(-2.0f, -20000.0f); 
    
    if ((sys->ss_flg & 0x2)) 
    { 
        sys->fog_cngct = 3; 
    } 
    else 
    {
        sys->fog_cngct = 2; 
    }

    bhInitVSync(); 

    pl_sleep_cnt = 0; 
    
    bhFontScaleSet(1.0f, 1.0f, 1.0f); 
    
    Pause_Flag = 0; 
    
    NowLoadDisp = 0; 
    
    PauseBtn = 0;
}

// 99.92% matching
void bhInitRoomChangeSystem()
{
    int i; 
    int j;
    int k;
	
    sys->gm_flg &= 0x9B8C00CB;
    
    sys->st_flg = 0;
    
    sys->rm_flg = 0;
    
    sys->cb_flg &= 0xAF8000BB;
    
    sys->pt_flg = ~0x0;
    
    sys->ef_flg = 0;
    
    sys->en_flg[3] = 0;
    sys->en_flg[2] = 0;
    sys->en_flg[1] = 0;
    sys->en_flg[0] = 0;
    
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 16; j++) 
        {
            for (k = 0; k < 16; k++) 
            {
                sys->et_lp[i][j][k] = NULL;
            }
        }
    } 
    
    for (i = 0; i < 1300; i++)
    {
        sys->ot_lp[i] = NULL;
    } 
    
    for (i = 0; i < 200; i++)
    {
        sys->it_lp[i] = NULL;
    } 
    
    for (i = sys->ef_ctb; i < 450; i++) 
    {
        sys->efm[i].flg &= ~0x200;
    } 
    
    sys->mflr_n = 0;
    
    sys->metc_n = 0;
    
    sys->mwal_n = 0;
    
    sys->pad_old = 0;
    
    sys->pad_ps = 0;
    
    sys->pad_oncpy = 0;
    
    sys->pad_on = 0;
    
    sys->gat_ct = 0;
    
    sys->ght_ct = 0;
    
    sys->loop_ct = 1;
    
    sys->txb_ct = 0;
    
    sys->txb_n = 0;
    
    sys->ren_gid = 2;
    
    sys->ren_n = 0;
    
    sys->ef_extn = 0;
    
    sys->ef_pbnk = 32;
    
    sys->yk_ct = 0;
    
    sys->bl_ct = 0;
    
    sys->com_flg = 0;
    
    sys->ond_cx = 0;
    
    sys->ond_n[0] = 1;
    sys->ond_n[1] = 0;
    sys->ond_n[2] = 0;
    
    BHD_ASPECT_X = 1.174f;
    BHD_ASPECT_Y = 1.0f;
    
    njSetAspect(BHD_ASPECT_X, BHD_ASPECT_Y);
    
    if ((sys->ss_flg & 0x2)) 
    {
        sys->fog_cngct = 3;
    } 
    else 
    {
        sys->fog_cngct = 2;
    }
}

// 100% matching!
void bhSysCallInit() 
{ 
    bhInitSystem(); 

    sys->tk_flg = 0x300002; 
} 

// 100% matching! 
void bhSysCallDiscChange()
{ 
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  

    if (Adv_ChangeDiscScreen() != 0) 
    { 
        njWaitVSync(); 
        
        njSetPaletteMode(2); 
        
        sys->tk_flg = sys->dcg_tkbak; 
        sys->ts_flg = sys->dcg_tsbak; 
    }
} 

// 100% matching! 
void bhSysCallSoundMuseum() 
{ 
    njFogDisable();
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);
    
    if (Adv_SoundMuseum() != 0) 
    { 
        sys->tk_flg = 0x300008;
    }
} 

// 100% matching! 
void bhSysCallWarning()
{ 
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
    
    if (Adv_FirstWarningMessage() != 0)
    { 
        sys->tk_flg = 0x300004; 
    }
} 

// 100% matching! 
void bhSysCallIpl()
{ 
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);
    
    if (Adv_CapcomLogo() != 0)
    { 
        sys->tk_flg = 0x300008; 
    }
} 

// 100% matching! 
void bhSysCallFirstmovie() 
{
    njFogDisable();
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);
    
    switch (Adv_BioCvTitle()) 
    {
    case 1:
        sys->ss_flg |= 0x400200;
        
        sys->pdm_keytpb = sys->keytype;
        
        sys->keytype = 0;
        
        sys->tk_flg = 0x300010;
        break;
    case 2:
        sys->ss_flg &= ~0x200;
        sys->tk_flg = 0x300010;
        break;
    case 3:
        sys->ss_flg |= 0x200;
        sys->tk_flg = 0x308040;
        
        *(int*)&sys->typ_md0 = 0;
        break;
    case 4:
        sys->tk_flg = 0x310000;
        
        *(int*)&sys->typ_md0 = 0;
        break;
    case 5:
        sys->tk_flg = 0x380000;
        break;
    case 6:
        sys->ss_flg &= ~0x200;
        sys->tk_flg = 0x300010;
        break;
    }
}

// 100% matching! 
void bhSysCallTitle() 
{ 
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);
    
    sys->tk_flg = 0x300020; 
} 

// 100% matching! 
void bhSysCallOpening() 
{ 
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
    
    bhFirstGameStart(); 
} 

// 100% matching! 
void bhFirstGameStart()
{
    int i; 
    NJS_SCREEN scrn; 
    int hp; 
    
    sys->ss_flg |= 0x100;
    sys->ss_flg &= ~0xA0004000;
    
    njWaitVSync();
    
    njSetPaletteMode(2);
    
    scrn.dist = 500.0f;
    
    scrn.w = 640.0f;
    scrn.h = 480.0f;
    
    scrn.cx = 320.0f;
    scrn.cy = 240.0f;
    
    njSetScreen(&scrn);
    
    BHD_ASPECT_X = 1.174f;
    BHD_ASPECT_Y = 1.0f;
    
    njSetAspect(BHD_ASPECT_X, BHD_ASPECT_Y);
    
    sys->memp = keepmem;
    
    sys->obwp = (NO_NAME_4*)bhGetFreeMemory(39936, 32);
    sys->itwp = (NO_NAME_4*)bhGetFreeMemory(39936, 32);
    
    sys->mempb = sys->memp;
    
    sys->tk_flg |= 0x73DFC0;
    
    sys->ts_flg = 0x3DF80;
    
    if ((sys->ss_flg & 0x400000)) 
    {
        sys->ts_flg |= 0x40;
    }
    
    sys->tk_flg &= ~0x20;
    
    *(int*)&sys->mn_mode0 = 1;
    
    InitGameSoundSystem();
    
    sys->ond_cx = 0;
    
    sys->ond_n[0] = 1;
    sys->ond_n[1] = 0;
    sys->ond_n[2] = 0;
    
    if (!(sys->ss_flg & 0x400200))
    {
        if (sys->gm_mode == 2) 
        {
            hp = 320;
        }
        else 
        {
            hp = 160; 
        }
        
        for (i = 0; i < 4; i++)
        {
            sys->ply_hp[i] = hp;
            
            sys->ply_stflg[i] = 0x40000000;
            
            sys->ply_wno[i] = 0;
        } 
        
        if (sys->gm_mode < 3) 
        {
            sys->stg_no = 0;
            sys->rom_no = 0;
            
            sys->rcase = 0;
            
            sys->ply_id = 0;
        }
        else 
        {
            sys->stg_no = 5;
            sys->rom_no = 50;
            
            sys->rcase = 0;
            
            sys->ply_id = 3;
        }
    }
}

// 100% matching! 
void bhSysCallPad() 
{ 
    if ((sys->ss_flg & 0x40000000)) 
    { 
        sys->sp_flg = ~0x0; 
        sys->ss_flg &= ~0x40000000;
    }
    
    if ((sys->sp_flg & 0x20))
    {
        bhSetPad();
    }
    else
    {
        sys->pad_on = 0; 
    }

    if (((sys->cb_flg & 0x4)) || (((sys->tk_flg & 0x1000)) && (!(sys->ts_flg & 0x1000))))
    { 
        sys->pad_on &= 0x1188F; 
        sys->pad_ps &= 0x1188F; 
    }
} 

// 100% matching! 
void bhSysCallGame()
{
    sys->pfm_cts = syTmrGetCount();
    
    sys->loop_ct = 1;
    
    if (((!(sys->st_flg & 0x1C040008)) && (!(sys->ss_flg & 0x80000000))) && (((sys->cb_flg & 0x4)) && ((sys->pad_ps & 0x10000)) && (!(sys->cb_flg & 0x10000000)))) 
    {
        sys->cb_flg |= 0x10000000;
    }
    
    bhCheckSubTask();
    
    bhMainSequence();
    
    sys->gm_flg |= 0x20000000;
    
    sys->gfrm_ct++;
}

// 99.69% matching
void bhCheckSubTask()
{
    if ((!(sys->ss_flg & 0x80000000)) && (!(sys->st_flg & 0x1C040008)) && (!(sys->cb_flg & 0x3)) && ((sys->ts_flg & 0x1000)))
    { 
        if (((plp->flg & 0x6)) && (!(sys->cb_flg & 0x4))) 
        {
            return; 
        }
        else if ((sys->cb_flg & 0x200000)) 
        { 
            *(int*)&sys->typ_md0 = 0; 
            
            sys->sp_flg = 0; 
            sys->sp_flg |= 0x30; 
            
            sys->st_flg |= 0x8000000; 
            
            sys->ts_flg &= ~0x8000; 
            
            bhSetScreenFade(0xFF000000, 5.0f); 
            
            BackColorFlag = 0; 
        }
        else if ((sys->cb_flg & 0x400000)) 
        { 
            sys->st_flg |= 0x4000000;
            
            bhKeepSpEvtComputer();
            
            *(int*)&sys->com_md0 = 0;
            
            *(int*)&sys->mn_mode0 = 7;
            
            sys->sp_flg = 0;
            sys->sp_flg |= 0x30;
            
            bhSetScreenFade(0xFF000000, 5.0f);
            
            BackColorFlag = 0;
        }
        else if (((!(sys->st_flg & 0x4)) && (!(sys->cb_flg & 0x4)) && ((!(sys->pad_on & 0x80)) && ((sys->pad_ps & 0x4000))) || ((sys->cb_flg & 0x64010))) && (!(sys->cb_flg & 0x2000000)) && (PauseBtn == 0))  
        { 
            AllStopEnemySe();
            
            sys->st_flg |= 0x8;
            
            *(int*)&sys->mn_mode0 = 5;
            
            sys->sp_flg = 0;
            sys->sp_flg |= 0x30;
            
            bhSetScreenFade(0xFF000000, 5.0f);
            
            BackColorFlag = 0;
        }
        else if (((sys->gm_mode < 3) && (!(sys->st_flg & 0x4)) && (!(sys->cb_flg & 0x4)) && ((sys->pad_ps & 0x2000))) || ((sys->cb_flg & 0x10000)))
        {
            AllStopEnemySe();
            
            sys->mpmd = 0;
            
            sys->sp_flg = 0;
            sys->sp_flg |= 0x10;
            
            sys->st_flg |= 0x40000;
            
            sys->ts_flg &= ~0x400;
            
            bhSetScreenFade(0xFF000000, 5.0f);
            
            BackColorFlag = 0;
        }
        else if ((!(sys->st_flg & 0x4)) && (!(sys->cb_flg & 0x4)) && ((sys->pad_ps & 0x8000)))
        { 
            AllStopEnemySe();
            
            *(int*)&sys->opt_md0 = 0;
            *(int*)&sys->typ_md0 = 0;
            
            sys->sp_flg = 0;
            
            sys->st_flg |= 0x10000000;
            
            sys->ts_flg &= ~0x10000;
            
            bhSetScreenFade(0xFF000000, 5.0f);
            
            njClipZ(-2.0f, -20000.0f);
            
            BackColorFlag = 0;
        }
        else
        {
            return; 
        }
    }
} 

// 100% matching! 
void bhSysCallEvent()
{
    unsigned int cb_flg;
    
    if (sys->loop_ct >= 2) 
    {
        return;
    }
    
    if (((sys->tk_flg & 0x80)) && ((!(sys->ts_flg & 0x80)) && ((sys->ts_flg & 0x3DE00) == 0x3DE00)) && (!(sys->tk_flg & 0x40000)) && (!(sys->cb_flg & 0x7)) && (!(sys->st_flg & 0x1C040208)) && ((!(sys->ss_flg & 0x20000000)) && (!(sys->ss_flg & 0x80400000))) && ((Pause_Flag != 0) || (((sys->pad_on & 0x80)) && ((sys->pad_ps & 0x20000)) && (PauseBtn == 0))))
    {
        sys->ss_flg |= 0x80000000;
        
        Pause_Flag = 1;
        
        sys->pau_spbak = sys->sp_flg;
        
        sys->pau_pad_on = sys->pad_on;
        sys->pau_pad_ps = sys->pad_ps;
        sys->pau_pad_old = sys->pad_old;
        
        sys->sp_flg = 0;
        
        sys->ssv_md0 = 10;
        return;
    }
    
    if (PauseBtn != 0) 
    {
        PauseBtn = 0;
    }
    
    if ((sys->ss_flg & 0x80000000)) 
    {
        sys->sp_flg = 0;
        
        pdGetPeripheral(0);
        
        if ((pd_port != -1) && ((Ps2_pad.pad1.push & 0x800))) 
        {
            sys->ss_flg &= ~0x80000000;
            
            sys->sp_flg = sys->pau_spbak;
            
            sys->pad_on = sys->pau_pad_on;
            sys->pad_ps = sys->pau_pad_ps;
            sys->pad_old = sys->pau_pad_old;
            
            sys->ssv_md0 = 0;
            sys->ssv_tim = 0;
            sys->ssv_an = 0;
            
            PauseBtn = 1;
            Pause_Flag = 0;
        }
        else
        {
            return;
        }
    }
    
    if ((sys->st_flg & 0x200))
    {
        if ((sys->ts_flg & 0x200)) 
        {
            bhControlMessage(0);
        } 
        else 
        {
            bhControlMessage(1);
        }
    }
    
    cb_flg = sys->cb_flg;
    
    bhControlEvent();
    
    if ((!(sys->cb_flg & 0x4)) && ((cb_flg & 0x4))) 
    {
        plp->flg &= ~0x10000;
        plp->stflg &= ~0x18000;
        
        sys->cb_flg &= ~0x10000000;
        
        plp->mode3 = 0;
    }
    
    if ((!(sys->cb_flg & 0x1)) && ((cb_flg & 0x1))) 
    {
        plp->stflg  &= ~0x80000000;
    }
    
    if ((sys->cb_flg & 0x4000000)) 
    {
        sys->sp_flg |= 0x20;
        
        sys->mvi_md = 0;
        
        sys->mvi_tsb = sys->ts_flg;
        sys->mvi_spb = sys->sp_flg;
        
        sys->sp_flg = 4;
        
        sys->cb_flg &= ~0x4000000;
        
        sys->ts_flg &= ~0x1000;
        sys->ts_flg |= 0x7CF00;
    }
}

// 100% matching! 
void bhSysCallMap()
{
    switch (sys->mpmd) 
    {
    case 0:
        if (!(sys->cb_flg & 0x2))
        {
            sys->sp_flg |= 0x20;
            
            sys->ts_flg |= 0x180;
            
            njFogDisable();
            
            if ((sys->cb_flg & 0x10000)) 
            {
                bhInitMap(MP_SET_EVENT);
            } 
            else 
            {
                bhInitMap(MP_SET_GAME);
            }
            
            bhSetMap();
            
            sys->mpmd++;
        }
        
        break;
    case 1:
    {
        int bol;
        
        bol = bhControlMap();
        
        if ((sys->cb_flg & 0x2)) 
        {
            bhControlScreenFade();
        }
        
        if (sys->fade_an > 0) 
        {
            bhDrawScreenFade();
        }
        
        if (bol != 0) 
        {
            break;
        }
        
        bhExitMap();
        
        sys->mpmd++;
    }
    case 2:
        sys->st_flg &= ~0x40000;
        
        sys->sp_flg = ~0x0;
        
        sys->st_flg &= ~0x40000;
        
        sys->ts_flg |= 0x400;
        sys->ts_flg &= ~0x180;
        
        sys->gm_flg |= 0x10;
        
        sys->bcl_ct = 1;
        
        sys->gm_flg |= 0x8000;
        
        if ((sys->st_flg & 0x2))
        {
            njFogEnable();
        }
        
        bhSetScreenFade(sys->fade_pbk, 3.0f);
        
        bhStandPlayerMotion();
        break;
    case 4:
        njFogDisable();
        
        sys->fade_pbk = 0;
        
        bhInitMap(MP_SET_SUB);
        
        bhSetMap();
        
        sys->mpmd++;
    case 5:
    {
        int bol;
       
        bol = bhControlMap();
        
        if ((sys->cb_flg & 0x2)) 
        {
            bhControlScreenFade();
        }
        
        if (sys->fade_an > 0) 
        {
            bhDrawScreenFade();
        }
        
        if (bol != 0) 
        {
            break;
        }
        
        bhExitMap();
        
        sys->mpmd++;
    }
    case 6:
        if ((sys->st_flg & 0x2))
        {
            njFogEnable();
        }
        
        sys->st_flg &= ~0x40000;
        
        sys->ts_flg |= 0x400;
        
        sys->tk_flg |= 0x200;
        
        sys->ts_flg &= ~0x200;
        
        sys->st_flg |= 0x8;
        break;
    }
    
    StatusMapFlagInit();
}

// 100% matching! 
void bhSysCallItemselect()
{
    njFogDisable();
    
    njPrintSize(16);
    
    ItemTaskCheck();
    
    if (!(sys->ts_flg & 0x200)) 
    {
        StatusMain();
    } 
    else 
    {
        bhDeleteYakkyou();
        
        bhSetScreenFade(3.0f, sys->fade_pbk);
        
        bhDrawScreenFade();
        
        sys->bcl_ct = 1;
        
        sys->gm_flg |= 0x8000;
    }
    
    njPrintSize(13);
    
    if ((sys->st_flg & 0x2))
    {
        njFogEnable();
    }
}

// 100% matching! 
void bhSysCallDoordemo()
{
    DOOR_WORK* ddp;
    int code;
    unsigned int argb;

    ddp = &sys->door;

    switch (ddp->mode0)
    {
    case 0:
        if (((ddp->flg & 0x80000000)) || (sys->door.dor_tp == 255))
        {
            ddp->mode0 = 10;
            break;
        }
        
        bhInitDoor();
        
        ddp->mode0++;
    case 1:
        code = bhReadDoorData();
        
        if (code != 0)
        {
            if (code == 1) 
            {
                ddp->mode0++;
            } 
            else if (code != 2) 
            {
                bhExitDoor();
                
                ddp->mode0 = 10;
            }
        }
        
        break;
    case 2:
        if (!(sys->cb_flg & 0x2))
        {
            njFogDisable();
            
            njSetBackColor(0x00000000, 0x00000000, 0x00000000);
            
            sys->ts_flg |= 0x100 | 0x80;
            
            sys->st_flg &= ~0x2;
            
            sys->gm_flg &= ~0x10;
            
            ddp->mode0++;
        }
        
        break;
    case 3:
        sys->ts_flg &= ~0x100000;
        
        bhReleaseMainTexture();
        
        Ps2ClearOT();
        
        if (sys->fade_an > 0) 
        {
            bhDrawScreenFade();
        }
        
        ddp->mode0++;
        break;
    case 4:
        bhSetDoor();
        
        ddp->mode0++;
    case 5:
        code = bhControlDoor();
        
        if (code != 0) 
        {
            break;
        }
        
        bhExitDoor();
        
        ddp->mode0++;
    case 6:
        sys->ts_flg |= 0x800;
        break;
    case 10:
        if (!(sys->cb_flg & 0x2)) 
        {
            NowLoadDisp = 1;
            
            argb = ((unsigned int)sys->fade_ap << 24) | ((unsigned int)sys->fade_rp << 16) | ((unsigned int)sys->fade_gp << 8) | (unsigned int)sys->fade_bp;
          
            njSetBackColor(argb, argb, argb);
            
            bhReleaseMainTexture();
            
            Ps2ClearOT();
            
            if (sys->fade_an > 0) 
            {
                bhDrawScreenFade();
            }
            
            sys->ts_flg |= 0x100 | 0x80;
            
            njFogDisable();
            
            sys->st_flg &= ~0x2;
            
            sys->gm_flg &= ~0x10;
            
            ddp->mode0++;
        }
        
        break;
    case 11:
        sys->ts_flg &= ~0x100000;
        sys->ts_flg |= 0x800;
        break;
    }
}

// 100% matching!
void bhSysCallMovie()
{
    unsigned int sz;

    switch (sys->mvi_md) 
    {
    case 0:
        if (njCalcTexture(0) < 1048576) 
        {
            sys->mvi_flg = 1;
            
            sys->ts_flg |= 0x80;
        } 
        else 
        {
            sys->mvi_flg = 0;
        }
        
        sys->memp = (unsigned char*)(((int)sys->memp + 63) & ~0x3F);
        sys->mvi_memp = sys->memp;
        
        sys->mvi_md++;
        break;
    case 1:
        if (sys->mvi_flg != 0) 
        {
            njFogDisable();
            
            njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
            
            if (rom->mdl.texP != NULL) 
            {
                sys->memp = (unsigned char*)bhCopyTexmem2MainmemSub((NJS_TEXLIST*)rom->mdl.texP, (char*)sys->memp);
               
                njReleaseTexture((NJS_TEXLIST*)rom->mdl.texP);
                
                bhGarbageTexture(tbuf, 256);
               
                Ps2ClearOT();
               
                if (sys->fade_an > 0) 
                {
                    bhDrawScreenFade();
                }
            }
        }
        
        sys->mvi_md++;
        break;
    case 2:
        if (sys->mvi_flg != 0)
        {
            njFogDisable();
            
            njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
        }
        
        PlayStartMovieEx(sys->mvi_no, sys->mvi_tp, 1);
        
        sys->mvi_md++;
        break;
    case 3:
        if (sys->mvi_flg != 0)
        {
            njFogDisable();
            
            njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
        }

        switch (WaitPrePlayMovie(0)) 
        {
        case 0:
            sys->ts_flg |= 0x80;
            sys->ts_flg &= ~0x100;
            
            sys->sp_flg |= 0x30;
            
            njSetBackColor(0x00000000, 0x00000000, 0x00000000); 
            
            sys->mvi_md++;
            break;
        case 1:
            break;
        case 2:
            sys->ts_flg &= ~0x40;
            
            sys->mvi_md = 5;
            break;
        case 3:
            PlayStopMovieEx(0);
            
            RequestAllStopSoundEx(1, 1, 0);
            
            bhReturnTitle();
            
            sys->ss_flg &= ~0x1000;
            
            ClearSoftResetKeyFlag(-1);
            
            sys->ss_flg &= ~0x80000;
            break;
        }
        
        break;
    case 4:
        njFogDisable();
        
        njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
        
        if (PlayMovieMain(0) != 0) 
        {
            sys->ts_flg &= ~0x40;
            
            sys->mvi_md++;
        }
        
        break;
    case 5:
        njFogDisable();
        
        njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
        
        if ((sys->mvi_flg != 0) && (rom->mdl.texP != NULL))
        {
            bhCopyMainmem2Texmem((NJS_TEXLIST*)rom->mdl.texP);
        }
        
        sys->memp = sys->mvi_memp;
        
        sys->mvi_md++;
        break;
    case 6:
        sys->bcl_ct = 1;
        
        sys->gm_flg |= 0x8000;
        
        if ((sys->st_flg & 0x2))
        {
            njFogEnable(); 
        }
        
        sys->sp_flg = sys->mvi_spb;
        sys->ts_flg = sys->mvi_tsb;
        break;
    }
}

// 100% matching! 
void bhSysCallEnding() 
{ 
    ControlRanking();
}

// 100% matching! 
void bhSysCallGameover()
{ 
    bhControlGameOver();
}

// 100% matching! 
void bhSysCallTypewriter() 
{ 
    if ((sys->ts_flg & 0x80))
    { 
        njFogDisable(); 
    } 
    
    ControlTypewriter();
}

// 83.89% matching
void bhSysCallOption()
{ 
    if ((sys->tk_flg & 0x80)) 
    { 
        if (sys->opt_md0 != 0) 
        {
            asm("nop"); 
        } 
        else if (!(sys->cb_flg & 0x2))
        { 
            sys->ts_flg |= 0x180; 
            
            njFogDisable(); 
            
            sys->opt_md0 = 1;
        } 
        else
        {
            return;
        }
    } 
    
    if (Adv_GameOptionScreen() != 0) 
    { 
        if ((sys->tk_flg & 0x80))
        { 
            sys->st_flg &= ~0x10000000; 
            sys->sp_flg = ~0x0; 
            
            sys->ts_flg |= 0x10000; 
            sys->ts_flg &= ~0x180; 
            
            sys->gm_flg |= 0x10; 
            
            sys->bcl_ct = 1; 
            
            sys->gm_flg |= 0x8000; 
            
            if ((sys->st_flg & 0x2))
            {
                njFogEnable(); 
            }
            
            bhSetScreenFade(3.0f, sys->fade_pbk); 
            
            bhStandPlayerMotion(); 
            
            njClipZ(GameNear, GameFar); 
        } 
        else 
        { 
            if (SoftResetFlag == 1) 
            { 
                sys->ss_flg |= 0x100000; 
                
                ClearSoftResetKeyFlag(-1); 
            }
            
            sys->tk_flg = 0x300008; 
        }
    }
} 

// 100% matching! 
void bhSysCallCompEvent() 
{ 
    bhControlSpEvtComputer();
}

// 100% matching! 
void bhSysCallMonitor()
{
    RDT_WORK* rh;      
    int i;                
    int sz;               
    unsigned char* datp;  
    unsigned int dt;      
    int vibnum;           
    int vibflg;           

    if ((sys->mn_mode0 != 0) && (sys->mn_setct < 8))
    {
        sys->mn_stack[sys->mn_setct++] = *(int*)&sys->mn_mode0;
        
        SET_SYS_MN_MODE(0, 0, 0, 0);
    }

    *(int*)&sys->mn_md0 = sys->mn_stack[0];

    switch (sys->mn_md0)
    {
    case 1:
        switch (sys->mn_md1) 
        {
        case 0:
            sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
            
            sys->sdm_flg = 0xE;
            
            if (!(sys->ss_flg & 0x400000)) 
            {
                sys->mn_md1 = 1;
            }
            else
            {
                sys->mn_md1 = 20;
            }
            
            break;
        case 1:
            sz = GetIsoFileSize("sysmes.ald"); 
            
            if (sz != 0) 
            {
                RequestReadIsoFile("sysmes.ald", sys->memp); 
                
                sys->mes_ip = (unsigned int*)sys->memp;
                
                sys->memp += sz;
                
                sys->doordp = bhGetFreeMemory(172032, 32);
                
                sys->mn_md1 = 2;
            }
            
            break;
        case 2:
            if (GetReadFileStatus() == 0) 
            {
                datp = (unsigned char*)sys->mes_ip; 
                
                dt = *sys->mes_ip; 
                
                datp += 4; 
                
                sys->mes_ip = (unsigned int*)datp; 
                
                datp += dt; 
                
                sys->mes_sp = (unsigned int*)(datp + 4);
                
                sys->mn_md1 = 3; 
            }
            
            break;
        case 3:
            if ((GetReadFileStatus() == 0) && (GetInsideFileSize(sys->sys_partid, 1) != 0)) 
            {
                sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                
                RequestReadInsideFile(sys->sys_partid, 1, sys->memp);
                
                sys->mn_md1 = 4;
            }
            
            break;
        case 4:
            if (GetReadFileStatus() == 0) 
            {
                bhInitObjItm();
                bhInitEffect();
                bhInitCamera();
                bhInitPlayer();
                bhInitEnemy();
                
                NowLoadDisp = 1;
                
                if (!(sys->ss_flg & 0x200)) 
                {
                    sys->mn_md1 = 5;
                }
                else
                {
                    sys->mn_md1 = 6;
                }
            }
            
            break;
        case 5:
            AllItemInit(0);
            
            sys->mn_md1 = 6;
            break;
        case 6:
            if ((GetReadFileStatus() == 0) && (GetInsideFileSize(sys->sys_partid, sys->ply_id + 10 + (sys->costume * 4)) != 0)) 
            {
                sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                
                RequestReadInsideFile(sys->sys_partid, sys->ply_id + 10 + (sys->costume * 4), sys->memp);
                
                sys->mn_md1 = 7;
            }
            
            break;
        case 7:
            if (GetReadFileStatus() == 0) 
            {
                bhReadPlayerData();
                
                sys->mn_md1 = 8;
            }
            
            break;
        case 8:
            if (GetInsideFileSize(sys->sys_partid, plp->wpnr_no + ((sys->ply_id * 30) + 20)) != 0) 
            {
                sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                
                RequestReadInsideFile(sys->sys_partid, plp->wpnr_no + ((sys->ply_id * 30) + 20), sys->memp);
                
                sys->mn_md1 = 9;
            }
            
            break;
        case 9:
            if (GetReadFileStatus() == 0) 
            {
                bhReadWeaponData();
                
                if ((sys->gm_flg & 0x400000)) 
                {
                    sys->sdm_flg |= 0x1;
                }
                
                sys->mn_md1 = 10;
            }
            
            break;
        case 10:
            sys->ss_flg &= ~0x200;
            
            if (!(sys->gm_flg & 0x400000)) 
            {
                SET_SYS_MN_MODE(4, 0, 0, 0);
            }
            else
            {
                if ((sys->sdm_flg & 0x1)) 
                {
                    break;
                }
                
                sys->gm_flg &= ~0x400000;
                
                plp->stflg &= ~0x1000000;
                
                bhResetPlayer();
            }
            
            SET_SYS_MN_MD(0, 0, 0, 0);
            break;
        case 20:
            i = ((sys->ss_flg & 0x1)) ? sys->pdm_no + 7 : sys->pdm_no + 4; 
            
            sz = GetInsideFileSize(sys->sys_partid, i); 
            
            if (sz != 0) 
            {
                RequestReadInsideFile(sys->sys_partid, i, sys->memp);
                
                sys->pdm_dp = sys->memp;
                
                sys->memp += sz;
                
                sys->mn_md1 = 21;
            }
            
            break;
        case 21:
            if (GetReadFileStatus() == 0) 
            {
                sz = (int)&sys->save_end - (int)&sys->version;
                
                njMemCopy(&sys->version, sys->pdm_dp, sz);
                
                sys->pdm_pd = &sys->pdm_dp[sz];
                
                sys->mn_md1 = 1;
            }
            
            break;
        }
        
        break;
    case 2:
        switch (sys->mn_md1) 
        {
        case 0:
            sys->memp = sys->mempb;
            
            sys->sdm_flg = 0;
            
            sys->mn_md1 = 1;
            break;
        case 1:
            sys->sdm_flg |= 0x2;
            
            sys->mn_md1 = 2;
            break;
        case 2:
            if (!(sys->gm_flg & 0x2)) 
            {
                sys->ts_flg |= 0x800;
                sys->ts_flg &= ~0x180;
                
                sys->gm_flg |= 0x80000000;
                
                sys->sdm_flg |= 0x1;
                
                sys->mn_md1 = 3;
            } 
            else 
            {
                SET_SYS_MN_MODE(4, 0, 0, 0);
                SET_SYS_MN_MD(0, 0, 0, 0);
            }
            
            break;
        case 3:
            if (!(sys->sdm_flg & 0x1)) 
            {
                SendSoundCommand(1);
                
                SET_SYS_MN_MD(0, 0, 0, 0);
            }
            
            break;
        }
        
        break;
    case 3:
        switch (sys->mn_md1) 
        {
        case 0:
            if ((GetReadFileStatus() != 1) && (GetInsideFileSize(sys->sys_partid, plp->wpnr_no + ((sys->ply_id * 30) + 20)) != 0)) 
            {
                sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                
                RequestReadInsideFile(sys->sys_partid, plp->wpnr_no + ((sys->ply_id * 30) + 20), sys->memp);
                
                sys->mn_md1 = 1;
            }
            
            break;
        case 1:
            if (GetReadFileStatus() == 0) 
            {
                bhReadWeaponData();
                
                RequestArmsSoundBank(WpnTab[plp->wpnr_no].snd_wpno);
                
                sys->mn_md1 = 2;
            }
            
            break;
        case 2:
            if (CheckTransEndSoundBank() != 0)
            {
                break;
            }
        case 3:
            SET_SYS_MN_MD(0, 0, 0, 0);
            break;
        }
        
        break;
    case 4:
        if ((!(sys->ss_flg & 0x400000)) && (((!(sys->ss_flg & 0x1)) && (sys->stg_no >= 6)) || (((sys->ss_flg & 0x1)) && (sys->stg_no < 6))))
        {
            sys->dcg_tkbak = sys->tk_flg;
            sys->dcg_tsbak = sys->ts_flg;
          
            sys->tk_flg = 0x240000;
            sys->ts_flg = 0;
        } 
        else 
        {
            if ((sys->stg_no == 7) && (sys->rom_no == 22)) 
            {
                sys->windr = 0;
                sys->winds = 0.0f;
            }
            
            switch (sys->mn_md1) 
            {
            case 0:
                if ((GetReadFileStatus() != 1) && (!(sys->cb_flg & 0x2))) 
                {
                    sprintf(sys->mes, "rm_%1d%02d%1d.rdx", sys->stg_no, sys->rom_no, sys->rcase); 
                    
                    sz = GetFileSize(sys->mes);
                    
                    if (sz != 0) 
                    {
                        bhInitReadRDT();
                        
                        sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64); 
                        sys->rdtp = (unsigned char*)ALIGN_DOWN((int)sys->endp - sz, 64); 
                        
                        RequestReadIsoFile(sys->mes, sys->rdtp);
                        
                        sys->mn_md1 = 1;
                        
                        if (((sys->stg_no == 9) && (sys->rom_no == 5)) || ((sys->stg_no == 9) && (sys->rom_no == 6)))
                        {
                            Ps2_ice_flag = 1;
                        }
                        else 
                        {
                            Ps2_ice_flag = 0;
                        }
                        
                        if ((sys->stg_no == 7) && (sys->rom_no == 10)) 
                        {
                            Ps2_albinoid_flag = 1;
                        }
                        else if ((sys->stg_no == 3) && (sys->rom_no == 6)) 
                        {
                            Ps2_albinoid_flag = 1;
                        } 
                        else 
                        {
                            Ps2_albinoid_flag = 0;
                        }
                        
                        if ((sys->stg_no == 1) && (sys->rom_no == 5)) 
                        {
                            Ps2_rendertex_initflag = 1;
                        } 
                        else 
                        {
                            Ps2_rendertex_initflag = 0;
                        }
                        
                        BackColorFlag = 0;
                    }
                }
                
                break;
            case 1: 
                vibflg = 0; 
                
                for (i = 0; i < 20; i++) 
                {
                    if (Pad_act[i].be_flag != 0)
                    {
                        sys->mn_md1 = 1;
                        
                        vibflg = 1; 
                    }
                }

                if (((vibflg == 0) || (--VibWait == 0)) && (GetReadFileStatus() == 0)) 
                {
                    FlushCache(0);
                    
                    sys->rdtsz = Expand((char*)sys->rdtp, sys->memp);
                    
                    sys->rdtp = sys->memp;
                    
                    sys->mn_md1 = 2;
                }
               
                break;
            case 2:
                sys->memp += sys->rdtsz;
                
                bhSetRDT();
                
                if ((sys->error & 0x1)) 
                {
                    sys->mn_md1 = 20;
                }
                else 
                {
                    sys->mn_md1 = 3;
                }
                
                break;
            case 3:
                if (sys->txr_n > sys->txr_ct)
                {
                    bhSetMemPvpTexture(sys->txlp[sys->txr_ct], sys->txdp[sys->txr_ct], sys->txloff[sys->txr_ct]);
                    
                    sys->txr_ct++;
                } 
                else 
                {
                    bhFinishRoom();
                    
                    if ((sys->cb_flg & 0x80)) 
                    {
                        plp->stflg &= 0x40000000 | 0x20000000 | 0x10000000 | 0x8000000 | 0x200000 | 0x80000;
                        
                        sys->ply_stflg[sys->ply_id] = plp->stflg;
                        
                        for (i = 0; i < plp->mdl_n; i++) 
                        {
                            if (plp->mdl[i].texP != NULL) 
                            {
                                njReleaseTexture(plp->mdl[i].texP);
                            }
                        }
                        
                        bhGarbageTexture(NULL, 0);
                        
                        sys->obwp[0].flg = 0;
                        sys->obwp[1].flg = 0; 
                        sys->obwp[2].flg = 0; 
                        sys->obwp[3].flg = 0;
                        
                        sys->ply_wno[sys->ply_id] = plp->wpnr_no;
                        sys->ply_hp[sys->ply_id] = plp->hp;
                        
                        sys->ply_id = sys->cng_pid;
                        
                        sys->mn_md1 = 4;
                    } 
                    else 
                    {
                        sys->mn_md1 = 10;
                    }
                }
                
                break;
            case 4:
                if ((GetReadFileStatus() != 1) && (GetInsideFileSize(sys->sys_partid, sys->ply_id + 10 + (sys->costume * 4)) != 0)) 
                {
                    sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                    
                    RequestReadInsideFile(sys->sys_partid, sys->ply_id + 10 + (sys->costume * 4), sys->memp);
                    
                    sys->mn_md1 = 5;
                }
                
                break;
            case 5:
                if (GetReadFileStatus() == 0) 
                {
                    bhReadPlayerData();
                    
                    bhResetPlayer();
                    
                    bhStandPlayerMotion();
                    
                    sys->sdm_flg |= 0x4;
                    
                    sys->mn_md1 = 6;
                }
                
                break;
            case 6:
                plp->wpnr_no = sys->ply_wno[sys->ply_id];
                
                if (GetInsideFileSize(sys->sys_partid, plp->wpnr_no + ((sys->ply_id * 30) + 20)) != 0) 
                {
                    sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                    
                    RequestReadInsideFile(sys->sys_partid, plp->wpnr_no + ((sys->ply_id * 30) + 20), sys->memp);
                    
                    sys->mn_md1 = 7;
                }
                
                break;
            case 7:
                if (GetReadFileStatus() == 0) 
                {
                    bhReadWeaponData();
                    
                    sys->sdm_flg |= 0x8;
                    
                    sys->mn_md1 = 10;
                }
                
                break;
            case 10:
                if (((sys->cb_flg & 0x80000000)) || ((sys->ss_flg & 0x400000))) 
                {
                    srand(1);
                }
                
                bhInitEvent();
                
                if ((sys->cb_flg & 0x80)) 
                {
                    sys->cb_flg &= ~0x80;
                    
                    if (sys->gm_mode < 3) 
                    {
                        bhPushGameData();
                    }
                }
                
                sys->sdm_flg |= 0x1;
                
                sys->ef_flg |= 0x1;
                
                sys->mn_md1 = 11;
                break;
            case 11:
                if ((!(sys->sdm_flg & 0x1)) && ((sys->ts_flg & 0x800)))
                {
                    if (((!(sys->ss_flg & 0x2)) && ((rom->flg & 0x1))) || (((sys->ss_flg & 0x2)) && (!(rom->flg & 0x1)))) 
                    {
                        sys->ltc_bp = sys->memp;
                        
                        bhPushAllTexture();
                        
                        sys->ltc_tsbak = sys->ts_flg;
                        
                        sys->ts_flg = ~0x0;
                        sys->ts_flg &= ~0x300000;
                        
                        sys->mn_md1 = 12;
                    } 
                    else 
                    {
                        sys->ltc_bp = NULL;
                        
                        sys->mn_md1 = 16;
                    }
                }
                
                break;
            case 12:
                sys->mn_md1 = 13;
                break;
            case 13:
                sys->mn_md1 = 14;
                break;
            case 14:
                sys->mn_md1 = 15;
                break;
            case 15:
                bhChangeHWSetting();
                
                bhPopAllTexture();
                
                sys->memp = sys->ltc_bp;
                
                sys->ts_flg = sys->ltc_tsbak;
                
                sys->mn_md1 = 16;
                break;
            case 16:
                SendSoundCommand(1);
                
                sys->fog_ct = sys->fog_cngct - 3;
                
                sys->ef_flg &= ~0x1;
                
                sys->ts_flg &= ~0x180;
                
                sys->bcl_ct = 1;
                
                if (sys->gm_mode < 3) 
                {
                    sys->gm_flg |= 0x80000000;
                }
                
                sys->gm_flg |= 0x8000;
                
                if ((sys->ss_flg & 0x400))
                {
                    sys->ss_flg &= ~0x400;
                    
                    bhPushGameData();
                }
                
                if ((sys->ss_flg & 0x400000)) 
                {
                    sys->ts_flg &= ~0x40;
                }
                
                NowLoadDisp = 0;
                
                SET_SYS_MN_MD(0, 0, 0, 0);
                break;
            case 20: 
                sys->error &= ~0x1;
                
                rh = (RDT_WORK*)sys->rdtp; 
                
                sprintf(sys->mes, "RDT version error."); 
        
                njPrintC(0x100006, sys->mes);
                
                sprintf(sys->mes, "Version   %4.2f", rh->ver); 
                
                njPrintC(0x100008, sys->mes);
                
                sprintf(sys->mes, "Name.     %s", rh->usrname); 
                
                njPrintC(0x100009, sys->mes);
                njPrintColor(0xFFE0E000);
                
                sprintf(sys->mes, "Final ver.%4.2f", 1.72f); 
                
                njPrintC(0x10000B, sys->mes);
                njPrintColor(0xFFE0E0E0);
                
                njPrintC(0x10000D, "Press start button."); 
                
                if ((sys->p1per->press & 0x800)) 
                {
                    sys->stg_no = sys->stg_nob;
                    sys->rom_no = sys->rom_nob;
                    sys->pos_no = sys->pos_nob;
                    
                    sys->rcase = sys->rcase_b;
                    
                    sys->mn_md1 = 0;
                }
                
                break;
            }
        }
        
        break;
    case 5:
        switch (sys->mn_md1) 
        {
        case 0:
            if (GetReadFileStatus() != 1) 
            {
                sys->sbs_sp = sys->memp;
                
                sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                
                if (rom->mdl.texP != NULL) 
                {
                    sys->memp = (unsigned char*)bhCopyTexmem2MainmemSub(rom->mdl.texP, (char*)sys->memp);
                }
                
                bhGarbageTexture(NULL, 0);
                
                sys->mn_md1 = 1;
            }
            
            break;
        case 1:
            if (GetInsideFileSize(sys->itm_partid, 145) != 0)
            {
                sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                
                RequestReadInsideFile(sys->itm_partid, 145, sys->memp);
                
                sys->subtxp = sys->memp;
                
                sys->mn_md1 = 2;
            }
            
            break;
        case 2:
            if ((!(sys->cb_flg & 0x2)) && (!(sys->ts_flg & 0x80))) 
            {
                sys->ts_flg |= 0x80;
                
                njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
            }

            if ((GetReadFileStatus() == 0) && (!(sys->cb_flg & 0x2))) 
            {
                if (rom->mdl.texP != NULL) 
                {
                    njReleaseTexture(rom->mdl.texP);
                   
                    bhGarbageTexture((NJS_TEXMEMLIST*)&tbuf, 256);
                    
                    Ps2ClearOT();
                    
                    if (sys->fade_an > 0) 
                    {
                        bhDrawScreenFade();
                    }
                }
                
                sys->mn_md1 = 3;
            }
            
            break;
        case 3:
            SbsTextureInit(3);
            
            sys->mn_md1 = 4;
            break;
        case 4:
            ItemTaskCheck(4);
            
            SET_SYS_MN_MD(0, 0, 0, 0);
            break;
        }
        
        break;
    case 6:
        switch (sys->mn_md1) 
        {
        case 0:
            if (GetReadFileStatus() != 1) 
            {
                sz = GetInsideFileSize(sys->itm_partid, sys->sb_rdid - 1);
                
                if (sz != 0) 
                {
                    sys->sb_rdsz = sz;
                    
                    RequestReadInsideFile(sys->itm_partid, sys->sb_rdid - 1, (unsigned char*)sys->sb_rdp);
                    
                    sys->mn_md1 = 1;
                    
                    FileWait = 16;
                }
            }
            
            break;
        case 1:
            if (FileWait != 0) 
            {
                FileWait--;
            }
            
            if ((GetReadFileStatus() == 0) && (FileWait == 0)) 
            {
                datp = sys->sb_rdp; 
                
                dt = *(int*)datp; 
                
                datp += 4; 
                
                sys->sb_mlb = datp; 
                
                datp += dt; 
                
                if ((*(int*)datp & 0x80000000)) 
                { 
                    datp = (unsigned char*)ALIGN_UP((int)(datp + 4), 32); 
                } 
                else 
                { 
                    datp += 4; 
                }
                
                sys->sb_ppp = datp; 
                
                SET_SYS_MN_MD(0, 0, 0, 0);
            }
        }
        
        break;
    case 7:
        switch (sys->mn_md1) 
        {
        case 0:
            if (GetReadFileStatus() != 1)
            {
                sys->sbs_sp = sys->memp;
                
                sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                
                if (rom->mdl.texP != NULL)
                {
                    sys->memp = (unsigned char*)bhCopyTexmem2MainmemSub(rom->mdl.texP, (char*)sys->memp);
                }
                
                bhGarbageTexture(NULL, 0);
                
                sys->mn_md1 = 1; 
        case 1: // this case is nested within case 0
            if (GetInsideFileSize(sys->sys_partid, 2) != 0) 
            {
                sys->memp = (unsigned char*)ALIGN_UP((int)sys->memp, 64);
                
                RequestReadInsideFile(sys->sys_partid, 2, sys->memp);
                
                sys->subtxp = sys->memp;
                
                sys->mn_md1 = 2;
            }
        }
        
        break;
        case 2:
            if ((!(sys->cb_flg & 0x2)) && (!(sys->ts_flg & 0x80)))
            {
                sys->ts_flg |= 0x80;
                
                njSetBackColor(0x00000000, 0x00000000, 0x00000000);
            }
            
            if ((GetReadFileStatus() == 0) && (!(sys->cb_flg & 0x2))) 
            {
                sys->mn_md1 = 3;
            }
            
            break;
        case 3:
            if (rom->mdl.texP != NULL) 
            {
                njReleaseTexture(rom->mdl.texP);
                
                bhGarbageTexture((NJS_TEXMEMLIST*)&tbuf, 256);
                
                Ps2ClearOT();
                
                if (sys->fade_an > 0) 
                {
                    bhDrawScreenFade();
                }
            }
            
            sys->ts_flg &= ~0x20000;
            
            SET_SYS_MN_MD(0, 0, 0, 0);
        }
        
        break;
    }

    sys->mn_stack[0] = *(int*)&sys->mn_md0;

    if ((sys->mn_md0 == 0) && (sys->mn_setct != 0)) 
    {
        sys->mn_setct--;
        
        for (i = 0; i < sys->mn_setct; i++) 
        {
            sys->mn_stack[i] = sys->mn_stack[i + 1];
        }
    }

    if ((sys->ef_flg & 0x1)) 
    {
        bhControlEffect();
    }

    if ((NowLoadDisp != 0) && (sys->mes_sp != NULL)) 
    {
        bhDispMessage(400.0f, 400.0f, -0.9f, 1, 491, 0, 0);
    } 
}

// 100% matching! 
void bhSysCallSndMonitor()
{
    if (((!(sys->ss_flg & 0x120000)) && (!(sys->tk_flg & 0x3F))) && (SoftResetFlag == 1)) 
    {
        if ((sys->ss_flg & 0x400000))
        {
            return;
        }
        
        PlayStopMovieEx(0);
        
        RequestAllStopSoundEx(1, 1, 0);
        
        bhReturnTitle();
        
        sys->ss_flg &= ~0x1000;
        
        ClearSoftResetKeyFlag(-1);
        
        sys->ss_flg &= ~0x80000;
        sys->ss_flg |= 0x100000; 
    }
    
    if ((sys->sdm_flg & 0x1)) 
    {
        switch (sys->sdm_mode) 
        {
        case 0:
            if (!(sys->sdm_flg & 0x2)) 
            {
                sys->sdm_mode = 2;
            }
            else if (CheckTransEndSoundBank() == 0)
            {
                RequestRoomSoundBank(sys->stg_no, sys->rom_no, GetRoomSoundCaseNo());
                
                sys->sdm_mode = 1;
            }
            
            break;
        case 1:
            if (CheckTransEndSoundBank() == 0) 
            {
                sys->sdm_mode = 2;
            }
            
            break;
        case 2:
            if (!(sys->sdm_flg & 0x4)) 
            {
                sys->sdm_mode = 4;
            } 
            else if (CheckTransEndSoundBank() == 0) 
            {
                RequestPlayerVoiceSoundBank(sys->ply_id);
                
                sys->sdm_mode = 3;
            }
            
            break;
        case 3:
            if (CheckTransEndSoundBank() == 0) 
            {
                sys->sdm_mode = 4;
            }
            
            break;
        case 4:
            if (!(sys->sdm_flg & 0x8)) 
            {
                sys->sdm_mode = 10;
            } 
            else if (CheckTransEndSoundBank() == 0) 
            {
                RequestArmsSoundBank(WpnTab[plp->wpnr_no].snd_wpno);
                
                sys->sdm_mode = 5;
            }
            
            break;
        case 5:
            if (CheckTransEndSoundBank() == 0) 
            {
                sys->sdm_mode = 10;
            }
            
            break;
        case 10:
            sys->sdm_flg = 0;
            *(unsigned int*)&sys->sdm_mode = 0;
            break;
        }
    }

    ExecSoundSystemMonitor();
}

// 96.48% matching
void bhSysCallScreenSaver()
{
    NJS_POINT2 pos; 
    int col; 
    
    switch (sys->ssv_md0) 
    {                        
    case 0:
        if (sys->p1per != NULL)
        {
            if ((sys->p1per->on != 0) || ((sys->p1per->x1 > 48) || (sys->p1per->x1 < -48) || (sys->p1per->y1 > 48) || (sys->p1per->y1 < -48)) || (((sys->cb_flg & 0x4)) && (!(sys->cb_flg & 0x40))) || ((plp->stflg & 0x40000)))
            {
                sys->ssv_tim = 0;
            }
            else 
            {
                sys->ssv_tim++;
            }
        } 
        else 
        {
            sys->ssv_tim++;
        }
        
        if (sys->ssv_tim >= 10800) 
        {
            bhSetScreenSaver(128, 300.0f);
        }
        
        break;
    case 1:
        bhControlScreenSaver();
    case 2:
        if ((sys->p1per != NULL) && ((sys->p1per->on != 0) || ((sys->p1per->x1 > 48) || (sys->p1per->x1 < -48) || (sys->p1per->y1 > 48) || (sys->p1per->y1 < -48))))
        {
            bhInitScreenSaver();
        }
        
        break;
    case 10:
        sys->ssv_an = 64.0f;
        
        sys->mes_tp = pause_mes;
        
        bhDispMessage(280.0f, 188.0f, -0.9f, 2, 0, 0, 0);
        
        if (pd_port != -1) 
        {
            EasyDispMessage(244.0f, 493);
        } 
        else 
        {
            bhFontScaleSet(0.71f, 1.0f, 1.0f);
            
            EasyDispMessage(244.0f, 492);
            
            bhFontScaleSet(1.0f, 1.0f, 1.0f);
        }
    }
    
    if (sys->ssv_an > 0) 
    {
        bhDrawScreenSaver();
    }
    
    if ((sys->evt_tim != 0) && (((sys->sp_flg & 0x200)) && ((sys->ss_flg & 0x40)))) 
    {
        if (sys->evt_tmd == 3)
        {
            if (sys->evt_fcd >= sys->evt_tim) 
            {
                if (sys->evt_fcdct == 0) 
                {
                    sys->evt_fcd = 600;
                }
                else 
                {
                    sys->evt_fcd -= 60;
                }
                
                if ((!(sys->ts_flg & 0x80)) && (!(sys->cb_flg & 0x1))) 
                {
                    CallSystemVoice(sys->evt_fcdct);
                }
                
                sys->evt_fcdct++;
            }
        }
        
        pos.x = 222.0f;
        pos.y = 76.0f;
        
        col = (sys->evt_tim < sys->evt_tdg) ? 2 : 3;
        
        if (bhCkFlg(sys->ed_flg, 349) == 0)
        {
            bhDispTime(&pos, 7, sys->evt_tim, col, -0.9f);
        }
    }
    
    if ((sys->gm_mode == 3) && (((sys->sp_flg & 0x200)) && (!(sys->ts_flg & 0x80)) && ((sys->gm_flg & 0x80000000)))) 
    {
        NJS_POINT2 pos; 
        
        pos.x = 222.0f;
        pos.y = 76.0f;  
        
        bhDispTime(&pos, 7, sys->time, 3, -0.9f); 
    }
}

// 100% matching! 
void bhReturnTitle()
{ 
    sys->ss_flg |= 0x20000; 
    
    bhExitGame(); 
    
    if (!(sys->ss_flg & 0x200000))
    { 
        sys->tk_flg = 0x300008;
    } 
    else 
    { 
        sys->ss_flg &= ~0x200000; 
        sys->tk_flg = 0x300004; 
    }
    
    sys->ts_flg = 0; 
    
    sys->ss_flg &= ~0x20000; 
    sys->ss_flg |= 0x1000; 
} 

// 100% matching! 
void bhExitGame()
{ 
    if ((sys->ss_flg & 0x2)) 
    { 
        njWaitVSync();
        njWaitVSync();
        njWaitVSync(); 
        
        bhChangeHWSetting(); 
    } 
    else
    { 
        njWaitVSync(); 
    }
    
    njReleaseTextureAll(); 
    
    njGarbageTexture(tbuf, 256); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
    
    bhInitSystem(); 
} 

// 100% matching! 
void bhSetEventTimer(int mode)
{ 
    sys->evt_tmd = mode + 1; 
    
    switch (mode) 
    { 
    case 0:
        bhStFlg(sys->ev_flg, 0x45); 
        
        sys->evt_tim = 2700; 
        
        sys->evt_tdg = 900; 
        break; 
    case 1:
        bhStFlg(sys->ev_flg, 0x43); 
        
        sys->evt_tim = 18000; 
        
        sys->evt_tdg = 3600; 
        break; 
    case 2:
        bhStFlg(sys->ev_flg, 0x46); 
        
        sys->evt_tim = 18000; 
        
        sys->evt_tdg = 3600; 
        
        sys->evt_fcd = 900; 
        sys->evt_fcdct = 0; 
        break;
    }
} 

// 100% matching! 
void EasyDispMessage(float PosY, unsigned int MessageNo)
{ 
    unsigned char* dmp;
    unsigned char* smp;
    unsigned short* mp;
    unsigned short* nmp;
    unsigned int* mes_dp;
    int x;
    int y;
    float sy;
    int LoopFlag = 1;
    int SearchFlag;
    float SizeX;
    
    smp = (unsigned char*)sys->mes_sp; 
    smp = (unsigned char*)(smp + sys->mes_sp[MessageNo + 1]); 
    
    dmp = syMalloc(1024); 
    
    memcpy(dmp, smp, 1024); 

    nmp = (unsigned short*)dmp; 
    
    for (y = 0; LoopFlag != 0; y++)
    { 
        SizeX = 0; 
        
        SearchFlag = 1;
        
        for (x = 0; SearchFlag != 0; x++) 
        { 
            switch (nmp[x]) 
            { 
            case 65535:
                LoopFlag = 0; 
                SearchFlag = 0;
                break; 
            case 65280:
                nmp[x] = 65535; 
                
                mes_dp = (unsigned int*)(&nmp[x] + 1); 
                
                SearchFlag = 0; 
                break; 
            case 65281:
                SizeX += 14.0f * FontScaleX; 
                break; 
            default: 
                SizeX += FontScaleX * FontSz[nmp[x]]; 
                break; 
            } 
        } 
        
        sys->mes_tp = nmp; 
        
        bhDispMessage(320.0f - (SizeX / 2.0f), PosY, -1.0f, 2, 0, 0, 0);    
        
        PosY += 30.0f * FontScaleCR;
        
        nmp = (unsigned short*)mes_dp; 
    } 
    
    syFree(dmp); 
} 
