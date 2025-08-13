
typedef struct _dtr 
{
    Sint8   used;
    Sint8   unk1; 
    Sint8   unk2;
    Sint8   unk3;
    SJ      sjo;
    SJ      sji;
    Sint32  unkC;
    Sint32  unk10;
    Sint32  unk14;
    Sint32  unk18;
    Sint32  unk1C;
    Sint32  unk20;
    Sint32  unk24;
    Sint32  unk28;
    Sint32  unk2C;
    Sint32  unk30;
    Sint32  unk34;
    Sint32  unk38;
    Sint32  unk3C;
} DTR_OBJ;

typedef DTR_OBJ *DTR;

static DTR_OBJ dtr_obj[16] = { 0 };
static Sint32 dtr_init_cnt;

// 100% matching!
DTR DTR_Create(SJ sjo, SJ sji)
{
    DTR dtr;
    Sint32 i;

    SJCRS_Lock();

    for (i = 0; i < 16; i++)
    {
        dtr = &dtr_obj[i];

        if (dtr->used == FALSE) 
        {
            break;
        }
    }

    if (i == 16) 
    {
        dtr = NULL;
    } 
    else 
    {
        memset(dtr, 0, sizeof(DTR_OBJ));
        
        dtr->unk1 = 0;
        
        dtr->unk38 = 64;
        
        dtr->sjo = sjo;
        
        dtr->sji = sji;
        
        dtr->unk2 = 0;
        
        dtr->unk30 = 1;
        
        dtr->used = TRUE;
        
        dtr->unk34 = 0;
    }

    SJCRS_Unlock();
    
    return dtr;
}

// 100% matching!
void DTR_Destroy(DTR dtr) 
{
    SJCRS_Lock();
    
    dtr->used = FALSE;
    
    SJCRS_Unlock();
}

// DTR_ExecHndl

void DTR_ExecServer(void)
{
    scePrintf("DTR_ExecServer - UNIMPLEMENTED!\n");
}

// 100% matching!
void DTR_Finish(void) 
{
    dtr_init_cnt--;
}

// 100% matching!
void DTR_Init(void)
{
    printf("DTR_Init: in (%d)\n", dtr_init_cnt);
    
    if (dtr_init_cnt == 0)
    {
        memset(dtr_obj, 0, sizeof(dtr_obj));
    }
    
    dtr_init_cnt++;
    
    printf("DTR_Init: out\n");
}

void DTR_Start(void* dtr)
{
    scePrintf("DTR_Start - UNIMPLEMENTED!\n");
}

void DTR_Stop(void* dtr)
{
    scePrintf("DTR_Stop - UNIMPLEMENTED!\n");
}
