
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

// PS2RNA_ClearBuf
// PS2RNA_ClearOverflow

void* PS2RNA_Create(SJ* sjo, Sint32 maxnch)
{
    scePrintf("PS2RNA_Create - UNIMPLEMENTED!\n");
}

void PS2RNA_Destroy(void* ps2rna)
{
    scePrintf("PS2RNA_Destroy - UNIMPLEMENTED!\n");
}

Sint32 PS2RNA_DiscardData(void)
{
    scePrintf("PS2RNA_DiscardData - UNIMPLEMENTED!\n");
}

// PS2RNA_ExecHndl

void PS2RNA_ExecServer(void)
{
    scePrintf("PS2RNA_ExecServer - UNIMPLEMENTED!\n");
}

void PS2RNA_Finish(void)
{
    scePrintf("PS2RNA_Finish - UNIMPLEMENTED!\n");
}

// ps2rna_finish_psj
// PS2RNA_Flush
// ps2rna_get_psj

Sint32 PS2RNA_GetBitPerSmpl(void* ps2rna)
{
    scePrintf("PS2RNA_GetBitPerSmpl - UNIMPLEMENTED!\n");
}

Sint32 PS2RNA_GetNumData(void* ps2rna)
{
    scePrintf("PS2RNA_GetNumData - UNIMPLEMENTED!\n");
}

Sint32 PS2RNA_GetNumRoom(void* ps2rna)
{
    scePrintf("PS2RNA_GetNumRoom - UNIMPLEMENTED!\n");
}

Sint32 PS2RNA_GetOutPan(void* ps2rna)
{
    scePrintf("PS2RNA_GetOutPan - UNIMPLEMENTED!\n");
}

Sint32 PS2RNA_GetOutVol(void* ps2rna)
{
    scePrintf("PS2RNA_GetOutVol - UNIMPLEMENTED!\n");
}

Sint32 PS2RNA_GetSfreq(void* ps2rna)
{
    scePrintf("PS2RNA_GetSfreq - UNIMPLEMENTED!\n");
}

// PS2RNA_GetSjiop
// PS2RNA_GetSjtmp
// PS2RNA_GetStartSmpl

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

// PS2RNA_SetPcmType

void PS2RNA_SetPlaySw(void* ps2rna, Sint32 sw)
{
    scePrintf("PS2RNA_SetPlaySw - UNIMPLEMENTED!\n");
}

// 100% matching!
void PS2RNA_SetSfreq(PS2RNA ps2rna, Sint32 sfreq)
{
    ps2rna->sfreq = sfreq;
}

void PS2RNA_SetStartSmpl(void* ps2rna, Sint32 smpl)
{
    scePrintf("PS2RNA_SetStartSmpl - UNIMPLEMENTED!\n");
}

void PS2RNA_SetStmHdInfo(void* ps2rna, void* hinfo)
{
    scePrintf("PS2RNA_SetStmHdInfo - UNIMPLEMENTED!\n");
}

// PS2RNA_SetTotalNumSmpl

void PS2RNA_SetTransSw(void* ps2rna, Sint32 sw)
{
    scePrintf("PS2RNA_SetTransSw - UNIMPLEMENTED!\n");
}

// ps2rna_sndcbf

void PS2RNA_Start(void* ps2rna)
{
    scePrintf("PS2RNA_Start - UNIMPLEMENTED!\n");
}

void PS2RNA_Stop(void* ps2rna)
{
    scePrintf("PS2RNA_Stop - UNIMPLEMENTED!\n");
}
