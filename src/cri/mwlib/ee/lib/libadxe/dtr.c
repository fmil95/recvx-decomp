#include "dtr.h"

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
        
        dtr->stat = 0;
        
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

// 100% matching!
void DTR_ExecHndl(DTR dtr)
{
    SJCK cks;
    SJCK ck1;
    SJCK ckd;
    SJCK ck2;
    Sint32 nbyte;
    Uint8 temp;

    if (dtr->stat == 1) 
    {
        temp = dtr->unk2;

        if (dtr->unk2 == dtr->stat) 
        {
            if (sceSifDmaStat(dtr->id) < 0)
            {
                SJ_PutChunk(dtr->sjo, 0, &dtr->ck1);
                
                dtr->ck1.data = NULL;
                
                dtr->ck1.len = 0;
                
                SJ_PutChunk(dtr->sji, 1, &dtr->ck2);
                
                dtr->ck2.data = NULL;
                
                dtr->ck2.len = 0;
                
                dtr->unk2 = 0;
                
                dtr->unk3C += dtr->ck1.len;
    
                if (dtr->ck1.len != 0) 
                {
                    printf("DTR_ExecHndl: Internal Error\n");
    
                    while (TRUE);
                }
    
                temp = 0;
            } 
            else 
            {
                temp = dtr->unk2;
            }
        }
    
        if (temp == 0) 
        {
            SJ_GetChunk(dtr->sjo, 1, SJCK_LEN_MAX, &cks);
            SJ_GetChunk(dtr->sji, 0, SJCK_LEN_MAX, &ckd);
            
            nbyte = MIN(cks.len, ckd.len);
            nbyte = (nbyte / dtr->unk38) * dtr->unk38;
            
            SJ_SplitChunk(&cks, nbyte, &cks, &ck1);
            
            SJ_UngetChunk(dtr->sjo, 1, &ck1);
            
            SJ_SplitChunk(&ckd, nbyte, &ckd, &ck2);
            
            SJ_UngetChunk(dtr->sji, 0, &ck2);
        
            if (nbyte > 0) 
            {
                if ((cks.len & 0x3F))
                {
                    printf("DTR_ExecHndl: Internal Error len\n");
                    printf("cks.data=%08x, ckd.data=%08x, cks.len=%d\n", cks.data, ckd.data, cks.len);
            
                    while (TRUE);
                }
            
                if (((Sint32)cks.data & 0x3F)) 
                {
                    printf("DTR_ExecHndl: Internal Error cks.data\n");
                    printf("cks.data=%08x, ckd.data=%08x, cks.len=%d\n", cks.data, ckd.data, cks.len);
            
                    while (TRUE);
                }
                
                if (((Sint32)ckd.data & 0x3F)) 
                {
                    printf("DTR_ExecHndl: Internal Error ckd.data\n");
                    printf("cks.data=%08x, ckd.data=%08x, cks.len=%d\n", cks.data, ckd.data, cks.len);
            
                    while (TRUE);
                }
            
                SyncDCache(cks.data, cks.data + (cks.len - 1));
                
                dtr->sdd.data = (Sint32)cks.data & 0xFFFFFFF;
                
                dtr->sdd.addr = (Sint32)ckd.data;
                
                dtr->sdd.size = cks.len;
                
                dtr->sdd.mode = 0;
                
                dtr->id = sceSifSetDma(&dtr->sdd, 1);
            
                if (dtr->id == 0) 
                {
                    printf("E0101701 DTR_ExecHndl: can't use DMA\n");
                    
                    SJ_UngetChunk(dtr->sjo, 1, &cks);
                    SJ_UngetChunk(dtr->sji, 0, &ckd);
                } 
                else 
                {
                    dtr->ck1 = cks;
                    dtr->ck2 = ckd;
                    
                    dtr->unk2 = 1;
                }
            }
        }
    }
}

// 100% matching!
void DTR_ExecServer(void) 
{
    Sint32 i;

    for (i = 0; i < 16; i++)
    {
        if (dtr_obj[i].used == TRUE) 
        {
            DTR_ExecHndl(&dtr_obj[i]);
        } 
    }

    DTX_ExecServer();
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

// 100% matching!
void DTR_Start(DTR dtr) 
{
    dtr->unk3C = 0;
    
    dtr->stat = 1;
}

// 100% matching!
void DTR_Stop(DTR dtr)
{
    dtr->stat = 0;

    if (dtr->ck1.data != NULL)
    {
        SJ_UngetChunk(dtr->sjo, 1, &dtr->ck1);
    
        dtr->ck1.data = NULL;
        
        dtr->ck1.len = 0;
    }

    if (dtr->ck2.data != NULL)
    {
        SJ_UngetChunk(dtr->sji, 0, &dtr->ck2);
    
        dtr->ck2.data = NULL;
        
        dtr->ck2.len = 0;
    }
}
