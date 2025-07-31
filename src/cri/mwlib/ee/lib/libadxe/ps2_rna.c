
typedef struct _ps2_psj 
{
    Sint8  used;
    Sint8  unk1;
    Sint8  unk2;
    Sint8  unk3;
    void*  sjrtm;
    SJ     sji;
    void*  sjx;
    SJCK   ck;
} PS2PSJ_OBJ;

typedef PS2PSJ_OBJ *PS2PSJ; 

typedef struct _ps2_rna 
{
    Sint8  used;
    Sint8  unk1;
    Sint8  unk2;
    Sint8  unk3;
    Sint32 maxnch;
    PS2PSJ ps2psj[2];
    void*  dtr[2];
    SJ     sjo[2];
    void*  urpc;
    Sint8  playsw;
    Sint8  unk25;
    Sint8  nch;
    Sint8  nch2;
    Sint32 sfreq;
    Sint32 unk2C;
    Sint32 vol;
    Sint32 unk34;
    Sint32 pan[2];
    Sint32 pan2[2];
    Sint8  unk48;
    Sint8  plysw;
    Sint8  unk4A;
    Sint8  unk4B; 
    Sint32 unk4C;
    Sint32 datano;
} PS2RNA_OBJ;

typedef PS2RNA_OBJ *PS2RNA;

Sint32 ps2rna_init_cnt;
Sint32 ps2rna_max_voice;
PS2RNA_OBJ ps2rna_obj[8];
PS2PSJ_OBJ ps2psj_obj[8];
Sint8 ps2psj_alloc_flag;
void* ps2psj_iop_work0;
Sint32 ps2psj_iop_wksize;
void* ps2psj_iop_work;
Sint8 ps2psj_sjuni_eewk[][256];

PS2PSJ ps2rna_get_psj();
void ps2rna_release_psj(PS2PSJ ps2psj);

// 100% matching!
void PS2RNA_ClearBuf(PS2RNA ps2rna) 
{
    printf("PS2RNA_ClearBuf: not implemented\n");

    while (TRUE);
}

// 100% matching!
void PS2RNA_ClearOverflow(PS2RNA ps2rna) 
{
    printf("PS2RNA_ClearOverflow: not implemented\n");
    
    while (TRUE);
}

// 100% matching!
PS2RNA PS2RNA_Create(SJ* sjo, Sint32 maxnch)
{
    PS2RNA ps2rna;
    Sint32 i;
    Sint32 sjrtm[4]; 
    void*  unk; 

    for (i = 0; i < 8; i++)
    {
        ps2rna = &ps2rna_obj[i];

        if (ps2rna->used == FALSE) 
        {
            break;
        }
    }

    if (i == 8) 
    {
        return NULL;
    }
    
    memset(ps2rna, 0, sizeof(PS2RNA_OBJ));
    
    ps2rna->maxnch = maxnch;
    
    for (i = 0; i < maxnch; i++) 
    {
        ps2rna->ps2psj[i] = ps2rna_get_psj();
    }

    sjrtm[0] = maxnch;
    
    sjrtm[1] = 0;

    for (i = 0; i < maxnch; i++) 
    {
        sjrtm[2 + i] = (Sint32)ps2rna->ps2psj[i]->sjrtm;
    }
     
    ps2rna->urpc = DTX_CallUrpc(8, sjrtm, 4, &unk, 1);

    if (ps2rna->urpc == NULL)
    {
        printf("E0100401: can't create PS2RNA of IOP\n");
        
        return NULL;
    }
    
    for (i = 0; i < maxnch; i++)
    {
        ps2rna->dtr[i] = DTR_Create(sjo[i], ps2rna->ps2psj[i]->sji);
    }

    for (i = 0; i < maxnch; i++)
    {
        ps2rna->sjo[i] = sjo[i];
    } 
    
    ps2rna->playsw = 0;
    
    ps2rna->unk25 = 0;
    
    ps2rna->nch = maxnch;
    ps2rna->nch2 = maxnch; 
    
    ps2rna->vol = 0;
    
    ps2rna->unk34 = 0;

    for (i = 0; i < maxnch; i++)
    {
        ps2rna->pan[i] = 0;
        ps2rna->pan2[i] = 0;
    }

    ps2rna->unk48 = 0;
    
    ps2rna->plysw = 1;
    
    ps2rna->unk4C = 0;
    
    ps2rna->datano = SJ_GetNumData(sjo[0], 1) + SJ_GetNumData(sjo[0], 0);
    
    ps2rna->used = TRUE;
    
    return ps2rna;
}

// 100% matching!
void PS2RNA_Destroy(PS2RNA ps2rna)
{
    Sint32 ch;
    Sint32 sjrtm[1];  

    for (ch = 0; ch < ps2rna->maxnch; ch++)
    {
        if (ps2rna->dtr[ch] != NULL) 
        {
            DTR_Destroy(ps2rna->dtr[ch]);
        }
    }
    
    sjrtm[0] = (Sint32)ps2rna->urpc;  
    
    DTX_CallUrpc(9, &sjrtm, 1, 0, 0);
 
    for (ch = 0; ch < ps2rna->maxnch; ch++) 
    {
        if (ps2rna->ps2psj[ch] != NULL) 
        {
            ps2rna_release_psj(ps2rna->ps2psj[ch]);
        }
    }
    
    ps2rna->used = FALSE;
}

// 100% matching!
Sint32 PS2RNA_DiscardData(void)
{
    printf("PS2RNA_DiscardData: not implemented\n");

    while (TRUE); 
}

void PS2RNA_ExecHndl(PS2RNA ps2rna)
{
    scePrintf("PS2RNA_ExecHndl - UNIMPLEMENTED!\n");
}

// 100% matching!
void PS2RNA_ExecServer(void)
{
    PS2RNA ps2rna;
    Sint32 i;

    SJX_ExecServer();
    DTR_ExecServer();

    RNACRS_Lock();

    for (i = 0; i < 8; i++) 
    {
        ps2rna = &ps2rna_obj[i];

        if (ps2rna->used == TRUE)
        {
            PS2RNA_ExecHndl(ps2rna);
        }
    }

    RNACRS_Unlock();
}

// 100% matching!
void PS2RNA_Finish(void)
{
    if (--ps2rna_init_cnt == 0)
    {
        DTX_Finish();
        SJX_Finish();
        SJRMT_Finish();
    }
} 

// 100% matching!
void ps2rna_finish_psj()
{
    PS2PSJ psj;
    Sint32 i;

    for (i = 0; i < ps2rna_max_voice; i++) 
    {
        psj = &ps2psj_obj[i]; 

        if (psj->sjrtm != NULL) 
        {
            SJRMT_Destroy(psj->sjrtm);
        }

        if (psj->sji != NULL)
        {
            SJ_Destroy(psj->sji);
        }

        if (psj->sjx != NULL)
        {
            SJX_Destroy(psj->sjx);
        }

        memset(psj, 0, sizeof(PS2PSJ_OBJ));
    }

    if (ps2psj_alloc_flag == 1)
    {
        sceSifFreeIopHeap(ps2psj_iop_work0);
        
        ps2psj_iop_work0 = NULL;
        
        ps2psj_alloc_flag = 0;
    }
}

// 100% matching!
void PS2RNA_Flush(void) 
{
    printf("PS2RNA_Flush: not implemented\n");

    while (TRUE);
}

// 100% matching!
PS2PSJ ps2rna_get_psj()
{
    PS2PSJ psj;
    Sint32 i;

    psj = NULL;

    for (i = 0; i < ps2rna_max_voice; i++) 
    {
        psj = &ps2psj_obj[i];

        if (psj->used == FALSE) 
        {
            break;
        }
    }

    if (i == 8) 
    {
        return NULL;
    }

    SJ_Reset(psj->sji);
    
    SJ_PutChunk(psj->sji, 0, &psj->ck);
    
    SJRMT_Reset(psj->sjrtm);
    
    psj->used = TRUE;
    
    return psj;
}

// 100% matching!
Sint32 PS2RNA_GetBitPerSmpl(PS2RNA ps2rna) 
{
    return 16;
}

// 100% matching! 
Sint32 PS2RNA_GetNumData(PS2RNA ps2rna)
{
    return (Uint32)(16384 - SJ_GetNumData(ps2rna->ps2psj[0]->sji, 0)) >> 1;
}

// 100% matching! 
Sint32 PS2RNA_GetNumRoom(PS2RNA ps2rna)
{
    return (Uint32)SJ_GetNumData(ps2rna->ps2psj[0]->sji, 0) >> 1;
} 

// 100% matching!
Sint32 PS2RNA_GetOutPan(PS2RNA ps2rna, Sint32 ch)
{
    return ps2rna->pan[ch];
}

// 100% matching!
Sint32 PS2RNA_GetOutVol(PS2RNA ps2rna)
{
    return ps2rna->vol;
}

// 100% matching!
Sint32 PS2RNA_GetSfreq(PS2RNA ps2rna) 
{
    return ps2rna->sfreq;
}

// 100% matching!
void* PS2RNA_GetSjiop(PS2RNA ps2rna, Sint32 ch) 
{
    return ps2rna->ps2psj[ch]->sjrtm; 
}

// PS2RNA_GetSjtmp

// 100% matching!
Sint32 PS2RNA_GetStartSmpl(PS2RNA ps2rna) 
{
    printf("PS2RNA_GetStartSmpl: not implemented\n");
    
    while (TRUE);
}

// 100% matching! 
void PS2RNA_GetTime(PS2RNA ps2rna, Sint32 *ncount, Sint32 *tscale)
{
    *ncount = 0;
    
    *tscale = 48000;
}

void PS2RNA_Init(void)
{
    scePrintf("PS2RNA_Init - UNIMPLEMENTED!\n");
}

// 100% matching!
void ps2rna_init_psj(void) 
{
    PS2PSJ psj;
    Sint8* wk;
    Sint32 i;

    if (ps2psj_iop_work0 == NULL) 
    {
        ps2psj_iop_work0 = sceSifAllocIopHeap(ps2psj_iop_wksize + 64);
        
        ps2psj_iop_work = (void*)(((Sint32)ps2psj_iop_work0 + 64) & 0xFFFFFFC0);
        
        ps2psj_alloc_flag = 1;
    }

    memset(ps2psj_obj, 0, sizeof(ps2psj_obj));
    
    wk = ps2psj_iop_work;

    for (i = 0; i < ps2rna_max_voice; i++) 
    {
        psj = &ps2psj_obj[i];
        
        psj->used = FALSE;

        if (((Sint32)wk & 0x3F))
        {
            printf("E0110101: ps2rna_init_psj wk size error\n");
            
            while (TRUE);
        }

        psj->sjrtm = SJUNI_CreateRmt(1, wk, 256);

        if (psj->sjrtm == NULL) 
        {
            printf("E0110102: ps2rna_init_psj: can't creat SJUNI_CreaetRmt\n");
            
            while (TRUE);
        }

        wk += 256;
        
        if (((Sint32)wk & 0x3F)) 
        {
            printf("E0110103: ps2rna_init_psj: wk size error\n");
            
            while (TRUE);
        }

        psj->sji = SJUNI_Create(1, ps2psj_sjuni_eewk[i], 256);

        if (psj->sji == NULL) 
        {
            printf("E0110104: ps2rna_init_psj: can't creat SJUNI_Creaet\n");
            
            while (TRUE);
        }

        psj->ck.len = 16384;
        
        psj->ck.data = wk;
        
        wk += 16384;
        
        SJ_PutChunk(psj->sji, 0, &psj->ck);
        
        psj->sjx = SJX_Create(psj->sji, psj->sjrtm, 1);
        
        if (psj->sjx == NULL) 
        {
            printf("E0110105: ps2rna_init_psj: can't creat SJX_Create\n");
            
            while (TRUE);
        }
    }
} 

// 100% matching!
void PS2RNA_IsOverflow(PS2RNA ps2rna) 
{
    printf("PS2RNA_IsOverflow: not implemented\n");

    while (TRUE);
}

// 100% matching!
Sint32 PS2RNA_IsPlySwOff(PS2RNA ps2rna) 
{
    Sint32 ret;

    ret = 0;
    
    if (PS2RNA_GetNumData(ps2rna) <= 0) 
    {
        ret = ps2rna->playsw == 1;
    }
    
    return ret;
}

// ps2rna_rcvcbf

// 100% matching!
void ps2rna_release_psj(PS2PSJ ps2psj) 
{
    ps2psj->used = FALSE;
}

// 100% matching!
void PS2RNA_SetBitPerSmpl(PS2RNA ps2rna, Sint32 bps) 
{
    if (bps != 16) 
    {
        printf("PS2RNA_SetBitPerSmpl: not support %d bps\n");
        
        while (TRUE);
    }
}

// 100% matching!
void PS2RNA_SetNumChan(PS2RNA ps2rna, Sint32 nch)
{
    ps2rna->nch = nch; 
}

// 100% matching!
void PS2RNA_SetOutPan(PS2RNA ps2rna, Sint32 ch, Sint32 pan)
{
    Sint32 _pan;

    _pan = pan;

    if (_pan < -15)
    {
        _pan = -15;
    }

    if (_pan > 15) 
    {
        _pan = 15;
    }
    
    ps2rna->pan[ch] = _pan;
}

// 100% matching!
void PS2RNA_SetOutVol(PS2RNA ps2rna, Sint32 vol) 
{
    if (vol > 0) 
    {
        vol = 0;
    }

    if (vol < -999) 
    {
        vol = -999;
    }

    ps2rna->vol = vol; 
}

// 100% matching!
void PS2RNA_SetPcmType(PS2RNA ps2rna, Sint32 type)
{
    printf("PS2RNA_SetPcmType: not implemented\n");

    while (TRUE);
}

// 100% matching!
void PS2RNA_SetPlaySw(PS2RNA ps2rna, Sint32 sw)
{
    Sint32 ch;

    ps2rna->playsw = sw;
    
    if (sw == 0) 
    {
        for (ch = 0; ch < ps2rna->maxnch; ch++) 
        {
            SJ_Reset(ps2rna->ps2psj[ch]->sji);
            
            SJ_PutChunk(ps2rna->ps2psj[ch]->sji, 0, &ps2rna->ps2psj[ch]->ck);
            
            SJRMT_Reset(ps2rna->ps2psj[ch]->sjrtm); 
        }
    }
}

// 100% matching!
void PS2RNA_SetSfreq(PS2RNA ps2rna, Sint32 sfreq)
{
    ps2rna->sfreq = sfreq;
}

// 100% matching!
void PS2RNA_SetStartSmpl(PS2RNA ps2rna, Sint32 smpl) 
{
    printf("PS2RNA_SetStartSmpl: not implemented\n");

    while (TRUE);
}

// 100% matching!
void PS2RNA_SetStmHdInfo(PS2RNA ps2rna, void* hinfo) 
{
    printf("PS2RNA_SetStmHdInfo: not implemented\n");

    while (TRUE);
}

// 100% matching!
void PS2RNA_SetTotalNumSmpl(PS2RNA ps2rna, Sint32 nsmpl) 
{
    printf("PS2RNA_SetTotalNumSmpl: not implemented\n");

    while (TRUE);
}

void PS2RNA_SetTransSw(PS2RNA ps2rna, Sint32 sw)
{
    scePrintf("PS2RNA_SetTransSw - UNIMPLEMENTED!\n");
}

// ps2rna_sndcbf

// 100% matching!
void PS2RNA_Start(PS2RNA ps2rna) 
{
    printf("PS2RNA_Start: not implemented\n");

    while (TRUE);
}

// 100% matching!
void PS2RNA_Stop(PS2RNA ps2rna) 
{
    PS2RNA_SetTransSw(ps2rna, 0);
    PS2RNA_SetPlaySw(ps2rna, 0);
}
