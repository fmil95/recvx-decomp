
typedef struct _ps2_psj 
{
    Sint8  used;
    Sint8  unk1;
    Sint8  unk2;
    Sint8  unk3;
    void*  sjrtm;
    SJ     sj;
    void*  sjx;
    SJCK   ck;
} PS2PSJ_OBJ;

typedef PS2PSJ_OBJ *PS2PSJ;

typedef struct _ps2_adxrna 
{
    Sint32 unk0;
    Sint32 unk4;
    Sint32 unk8;
    Sint32 unkC;
    Sint32 unk10;
    Sint32 unk14;
    Sint32 unk18;
    Sint32 unk1C;
    Sint32 unk20;
    Sint16 unk24;
    Sint8  nch;
    Sint8  unk27;
    Sint32 sfreq;
    Sint32 unk2C;
    Sint32 vol;
    Sint32 unk34;
    Sint32 pan[2];
} PS2_ADXRNA;
typedef PS2_ADXRNA *PS2RNA;

Sint32 ps2rna_init_cnt;
Sint32 ps2rna_max_voice;
PS2PSJ_OBJ ps2psj_obj[];
Sint8 ps2psj_alloc_flag;
void* ps2psj_iop_work0;

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

void* PS2RNA_Create(SJ* sjo, Sint32 maxnch)
{
    scePrintf("PS2RNA_Create - UNIMPLEMENTED!\n");
}

void PS2RNA_Destroy(void* ps2rna)
{
    scePrintf("PS2RNA_Destroy - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 PS2RNA_DiscardData(void)
{
    printf("PS2RNA_DiscardData: not implemented\n");

    while (TRUE); 
}

// PS2RNA_ExecHndl

void PS2RNA_ExecServer(void)
{
    scePrintf("PS2RNA_ExecServer - UNIMPLEMENTED!\n");
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

        if (psj->sj != NULL)
        {
            SJ_Destroy(psj->sj);
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

    SJ_Reset(psj->sj);
    
    SJ_PutChunk(psj->sj, 0, &psj->ck);
    
    SJRMT_Reset(psj->sjrtm);
    
    psj->used = TRUE;
    
    return psj;
}

// 100% matching!
Sint32 PS2RNA_GetBitPerSmpl(PS2RNA ps2rna) 
{
    return 16;
}

Sint32 PS2RNA_GetNumData(void* ps2rna)
{
    scePrintf("PS2RNA_GetNumData - UNIMPLEMENTED!\n");
}

Sint32 PS2RNA_GetNumRoom(void* ps2rna)
{
    scePrintf("PS2RNA_GetNumRoom - UNIMPLEMENTED!\n");
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

// PS2RNA_GetSjiop
// PS2RNA_GetSjtmp

// 100% matching!
Sint32 PS2RNA_GetStartSmpl(PS2RNA ps2rna) 
{
    printf("PS2RNA_GetStartSmpl: not implemented\n");
    
    while (TRUE);
}

Sint32 PS2RNA_GetTime(void* ps2rna)
{
    scePrintf("PS2RNA_GetTime - UNIMPLEMENTED!\n");
}

void PS2RNA_Init(void)
{
    scePrintf("PS2RNA_Init - UNIMPLEMENTED!\n");
}

// ps2rna_init_psj
// PS2RNA_IsOverflow
// PS2RNA_IsPlySwOff
// ps2rna_rcvcbf
// ps2rna_release_psj

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

void PS2RNA_SetPlaySw(PS2RNA ps2rna, Sint32 sw)
{
    scePrintf("PS2RNA_SetPlaySw - UNIMPLEMENTED!\n");
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
