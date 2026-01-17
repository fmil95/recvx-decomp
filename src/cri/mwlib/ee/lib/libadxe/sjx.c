#include "sjx.h"
#include "dtx.h"

#include <stdio.h>
//#include <string.h>

Char8* volatile sjx_build = "\nSJX Ver 1.00 Build:Jan 26 2001 09:59:55\n";
Sint32 sjx_init_cnt = 0;
void *sjx_eewk = NULL;
void *sjx_iopwk = NULL;
SJX_OBJ sjx_obj[16] = { 0 };
DTX sjx_dtx = NULL;
Sint32 sjx_wklen = 0;
Sint8 sjx_ee_work[2256] = { 0 };

// 100% matching!
SJX SJX_Create(SJ sjsrc, SJ sjdst, Sint32 lin)
{
    Sint32 i;
	Sint32 arg[4];
	SJX sjx;

    for (i = 0; i < 16; i++) 
    {
        sjx = &sjx_obj[i];

        if (sjx->used == FALSE) 
        {
            break;
        }
    }
    
    if (i == 16) 
    {
        return NULL;
    }

    memset(sjx, 0, sizeof(SJX_OBJ));
    
    sjx->lin = lin;
    
    sjx->sjsrc = sjsrc;
    sjx->sjdst = sjdst;
    
    arg[0] = (Sint32)sjsrc;
    arg[1] = (Sint32)sjdst;
    arg[2] = lin;
    arg[3] = (Sint32)sjx;
    
    sjx->iopsjx = (void*)DTX_CallUrpc(SJX_DTXFNO_CREATE, arg, 4, arg, 1);
    
    if (sjx->iopsjx == NULL) 
    {
        printf("E0100401: can't create SJX of IOP\n");
        
        return NULL;
    }

    sjx->used = TRUE;
    
    return sjx;
}

// 100% matching!
void SJX_Destroy(SJX sjx)
{
    Sint32 arg[1];

    arg[0] = (Sint32)sjx->iopsjx;
    
    DTX_CallUrpc(SJX_DTXFNO_DESTROY, arg, 1, NULL, 0);
    
    sjx->used = FALSE;
}

// 100% matching!
void SJX_ExecServer(void) 
{
    DTX_ExecServer();
}

// 100% matching!
void SJX_Finish(void) 
{
    sjx_init_cnt--;
}

// 100% matching!
void SJX_Init(void)
{
    if (sjx_init_cnt == 0)
    {
        DTX_Init();
        
        sjx_wklen = 2176;
        
        sjx_eewk = (void*)(((Uint32)sjx_ee_work + 64) & ~0x3F);

        if (sjx_iopwk == NULL) 
        {
            sjx_iopwk = sceSifAllocIopHeap(2256);

            if (sjx_iopwk == NULL) 
            {
                printf("E0100301: SJX_Init can't allocate IOP Heap\n");
                
                while (TRUE);
            }
        }

        sjx_iopwk = (void*)(((Uint32)sjx_iopwk + 64) & ~0x3F); // casts added for MWCC compatibility
        
        sjx_dtx = DTX_Create(0, sjx_eewk, sjx_iopwk, sjx_wklen);

        if (sjx_dtx == NULL) 
        {
            printf("E0100302: SJX_Init can't create DTX\n");
            
            while (TRUE);
        }

        DTX_SetRcvCbf(sjx_dtx, sjx_rcvcbf, 0);
        DTX_SetSndCbf(sjx_dtx, sjx_sndcbf, 0);
    }

    sjx_init_cnt++;
}

// 100% matching!
void sjx_rcvcbf(void *obj, void *dt, Sint32 dtlen)
{
    SJX_DTXFMT *fmt;
	SJX_DTXCMD *cmd;
	Sint32 ncmd;
	Sint32 i;
	SJX sjx;
    
    fmt = dt;

    if (fmt == NULL) 
    {
        while (TRUE);
    }

    ncmd = fmt->ncmd;
    
    SJCRS_Lock();

    for (i = 0; i < ncmd; i++) 
    {
        cmd = &fmt->cmd[i];
        
        if (cmd->no == SJX_CMD_PUT_CHUNK)
        {
            sjx = (SJX)cmd->sj;
            
            if (cmd->xid == sjx->xid) 
            {
                SJ_PutChunk(sjx->sjsrc, cmd->lin, &cmd->ck);
            }
        }
    } 

    SJCRS_Unlock();
}

// 100% matching!
void SJX_Reset(SJX sjx)
{
    Sint32 arg[2];

    arg[0] = (Sint32)sjx->iopsjx;
    arg[1] = ++sjx->xid;
    
    DTX_CallUrpc(SJX_DTXFNO_RESET, arg, 2, NULL, 0);
}

// 100% matching!
void sjx_sndcbf(void *obj, void *dt, Sint32 dtlen)
{
    SJX_DTXFMT *fmt;
	SJX_DTXCMD *cmd;
	Sint32 i;
	Sint32 ncmd;
	SJCK ck;
    SJX sjx;

    fmt = dt;
    
    cmd = fmt->cmd;
    
    ncmd = 0;

    SJCRS_Lock();

    for (i = 0; i < 16; i++)
    {
        sjx = &sjx_obj[i];
        
        if (sjx->used == TRUE) 
        {
            for ( ; ; ncmd++) 
            {
                if (ncmd == 128) 
                {
                    goto label;
                }
    
                SJ_GetChunk(sjx->sjsrc, sjx->lin, SJCK_LEN_MAX, &ck);
    
                if (ck.len == 0)
                {
                    break;
                }
    
                cmd[ncmd].no = 0;
                
                cmd[ncmd].sj = sjx->iopsjx;
                
                cmd[ncmd].lin = sjx->lin;   
                
                cmd[ncmd].ck = ck;
                
                cmd[ncmd].xid = sjx->xid; 
            }
        }
    }

label:
    SJCRS_Unlock();  
    
    fmt->ncmd = ncmd;
}
