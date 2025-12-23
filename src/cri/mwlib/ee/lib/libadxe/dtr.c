#include "dtr.h"
#include "dtx.h"

#include <stdio.h>
#include <string.h>

#include <eetypes.h>
#include <eekernel.h>
#include <sifrpc.h>

Char8* volatile dtr_build = "\nDTR Ver.0.91 Build:Jan 26 2001 09:57:01\n";
Sint32 dtr_init_cnt = 0;
DTR_OBJ dtr_obj[16] = { 0 };

// 100% matching!
DTR DTR_Create(SJ sjsrc, SJ sjdst)
{
    Sint32 i;
    DTR dtr;

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
        
        dtr->stat = DTR_STAT_STOP;
        
        dtr->blklen = 64;
        
        dtr->sjsrc = sjsrc;
        dtr->sjdst = sjdst;
        
        dtr->trnflg = DTR_DTXFNO_CREATE;
        
        dtr->srclin = 1;
        dtr->dstlin = 0;
        
        dtr->used = TRUE;
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
	SJCK cks2;
	SJCK ckd;
	SJCK ckd2;
	Sint32 len;
    Uint8 temp;

    if (dtr->stat == DTR_STAT_EXEC) 
    {
        temp = dtr->trnflg;

        if (dtr->trnflg == dtr->stat) 
        {
            if (sceSifDmaStat(dtr->dma_id) < 0)
            {
                SJ_PutChunk(dtr->sjsrc, 0, &dtr->cks);
                
                dtr->cks.data = NULL;
                
                dtr->cks.len = 0;
                
                SJ_PutChunk(dtr->sjdst, 1, &dtr->ckd);
                
                dtr->ckd.data = NULL;
                
                dtr->ckd.len = 0;
                
                dtr->trnflg = DTR_DTXFNO_CREATE;
                
                dtr->total_tbyte += dtr->cks.len;
    
                if (dtr->cks.len != 0) 
                {
                    printf("DTR_ExecHndl: Internal Error\n");
    
                    while (TRUE);
                }
    
                temp = DTR_DTXFNO_CREATE;
            } 
            else 
            {
                temp = dtr->trnflg;
            }
        }
    
        if (temp == DTR_DTXFNO_CREATE) 
        {
            SJ_GetChunk(dtr->sjsrc, 1, SJCK_LEN_MAX, &cks);
            SJ_GetChunk(dtr->sjdst, 0, SJCK_LEN_MAX, &ckd);
            
            len = MIN(cks.len, ckd.len);
            len = (len / dtr->blklen) * dtr->blklen;
            
            SJ_SplitChunk(&cks, len, &cks, &cks2);
            
            SJ_UngetChunk(dtr->sjsrc, 1, &cks2);
            
            SJ_SplitChunk(&ckd, len, &ckd, &ckd2);
            
            SJ_UngetChunk(dtr->sjdst, 0, &ckd2);
        
            if (len > 0) 
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
                
                dtr->dma.data = (Sint32)cks.data & 0xFFFFFFF;
                
                dtr->dma.addr = (Sint32)ckd.data;
                
                dtr->dma.size = cks.len;
                
                dtr->dma.mode = 0;
                
                dtr->dma_id = sceSifSetDma(&dtr->dma, 1);
            
                if (dtr->dma_id == 0) 
                {
                    printf("E0101701 DTR_ExecHndl: can't use DMA\n");
                    
                    SJ_UngetChunk(dtr->sjsrc, 1, &cks);
                    SJ_UngetChunk(dtr->sjdst, 0, &ckd);
                } 
                else 
                {
                    dtr->cks = cks;
                    dtr->ckd = ckd;
                    
                    dtr->trnflg = DTR_DTXFNO_DESTROY;
                }
            }
        }
    }
}

// 100% matching!
void DTR_ExecServer(void) 
{
    Sint32 i;
    DTR dtr;

    for (i = 0; i < 16; i++)
    {
        dtr = &dtr_obj[i];
        
        if (dtr->used == TRUE) 
        {
            DTR_ExecHndl(dtr);
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
    dtr->total_tbyte = 0;
    
    dtr->stat = DTR_STAT_EXEC;
}

// 100% matching!
void DTR_Stop(DTR dtr)
{
    dtr->stat = DTR_STAT_STOP;

    if (dtr->cks.data != NULL)
    {
        SJ_UngetChunk(dtr->sjsrc, 1, &dtr->cks);
    
        dtr->cks.data = NULL;
        
        dtr->cks.len = 0;
    }

    if (dtr->ckd.data != NULL)
    {
        SJ_UngetChunk(dtr->sjdst, 0, &dtr->ckd);
    
        dtr->ckd.data = NULL;
        
        dtr->ckd.len = 0;
    }
}
