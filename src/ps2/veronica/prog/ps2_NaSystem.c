#include "ps2_NaSystem.h"
#include "ps2_dummy.h"
#include "ps2_loadtim2.h"
#include "main.h"

void (* VsyncFunc)();
void (* EorFunc)();
unsigned int Ps2_vcount;
unsigned int Ps2_dbuff;
PS2_NJ_SAVE Ps2_nj_save_current;

// 100% matching!
void	njSetTextureMemorySize(Uint32 size )
{

}

// 100% matching!
void	njSetVertexBuffer(Uint32 *buffer,Sint32 size)
{

}

// 100% matching!
void	njInitSystem( Int, Int, Int )
{
    Ps2Init();
}

// 100% matching!
void	njInitVertexBuffer( Sint32 op, Sint32 om, Sint32 tp, Sint32 tm ,Sint32 pt)
{

}

// 100% matching!
void njWaitVSync(void) 
{

}

// 100% matching! 
void null_func()
{

}

// 100% matching! 
void Ps2InitFunc()
{ 
    EorFunc = null_func; 
    VsyncFunc = null_func; 
} 

// 100% matching! 
void 	njSetEORFunction( void (*func)(void) )
{
    if (func == NULL) 
    { 
        EorFunc = null_func; 
    } 
    else 
    {
        EorFunc = func; 
    }
} 

#pragma optimization_level 0

// 100% matching!
void Ps2SwapDBuff() 
{ 
    SyncPath(); 
    
    Ps2DrawOTag(); 
    Ps2ClearOT(); 
    
    SyncPath(); 

    EorFunc(); 
    
    while (Ps2_vcount < 2) 
    { 
        asm("nop");
        asm("nop");
    } 
    
    PS2_swap(); 
    
    sceGsSwapDBuffDc(&Db, Ps2_dbuff);
    
    Ps2_dbuff = (Ps2_dbuff + 1) & 0x1;
    
    Ps2_vcount = 0; 

    printf("TICK = %d\n", *(volatile unsigned int*)SR_CU0); 
    
    *(volatile unsigned int*)SR_CU0 = 0; 
    
    VsyncFunc(); 
} 

// 100% matching! 
int vsync_func(int) 
{
    Ps2_vcount++; 
    
    if ((((sys->tk_flg & 0x80)) && ((sys->gm_flg & 0x80000000))) && (sys->time < 216000000)) 
    {
        sys->time++;
    }
    
    ExitHandler(); 
} 

#pragma optimization_level reset

// 100% matching! 
void Ps2SetVSyncCounter()
{
    DisableIntc(2);
    
    AddIntcHandler(2, vsync_func, 0);
    
    EnableIntc(2);
}

// 100% matching! 
void	njSetVSyncFunction( void (*func)(void) )
{
    Ps2_vcount = 0; 
    
    if (func == NULL)
    { 
        VsyncFunc = null_func; 
    }
    else 
    {
        VsyncFunc = func; 
    }
} 

// 100% matching!
void	njExitSystem( void )
{

}

// 100% matching!
void	njSetBackColor( Uint32 col1, Uint32 col2, Uint32 col3 ) 
{
    unsigned long tmp; 

    tmp = SCE_GS_SET_RGBAQ((col1 >> 16) & 0xFF, (col1 >> 8) & 0xFF, col1 & 0xFF, (col1 >> 24) & 0xFF, 0); 
    
    *(unsigned long*)UNCACHED(&Db.clear0.rgbaq) = tmp; 
    *(unsigned long*)UNCACHED(&Db.clear1.rgbaq) = tmp; 
} 

// 100% matching! 
void	njTextureFilterMode( Int mode )
{
    Ps2_nj_save_current.mode = mode;
}

// 100% matching!
void    njPolygonCullingMode( Int mode )
{

}

// 99.91% matching 
void njColorBlendingModeSys(int s_mode, int d_mode) // this function is not on this KATANA release
{ 
    static unsigned long alpha_tbl[13][12] = // TODO: double-check that these values are all correct
    {
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x8000000068,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x1000000026,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x44,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x44,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x48,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x44,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x48,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x46,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x46,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0x46,
    		0x0,
    	},
    	{
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    		0xFFFFFFFF,
    	},
    };
    unsigned long alpha_value;
    
    Ps2_gs_save.mode_bk[0] = s_mode; 
    Ps2_gs_save.mode_bk[1] = d_mode; 
    
    Ps2_gs_save.set_last = Ps2_nj_save_current.set_last;
    
    Ps2_gs_save.dc_alpha = 0; 
    
    if (Ps2_gs_save.mode_bk[Ps2_gs_save.set_last] < 2) 
    { 
        if (Ps2_gs_save.mode_bk[Ps2_gs_save.set_last] == 0)
        { 
            alpha_value = 1; 
        }
        else
        { 
            alpha_value = 68; 
        }
    } 
    else if ((Ps2_gs_save.mode_bk[0] < 2) || (Ps2_gs_save.mode_bk[1] < 2)) 
    { 
        return;
    }
    else 
    {
        alpha_value = alpha_tbl[Ps2_gs_save.mode_bk[0]][Ps2_gs_save.mode_bk[1]]; 
    }
    
    if (alpha_value == ULONG_MAX) 
    { 
        printf("CALL ISHIKAWA ! ALPHA ERROR !!!!!!! MODE %d %d", Ps2_gs_save.mode_bk[0], Ps2_gs_save.mode_bk[1]); 
        
        while (TRUE); 
    }
    
    D2_SyncTag(); 
    
    ((u_long*)WORKBASE)[0] = DMAend | 0x4; 
    ((u_long*)WORKBASE)[1] = 0; 

    ((u_long*)WORKBASE)[2] = SCE_GIF_SET_TAG(3, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1); 
    ((u_long*)WORKBASE)[3] = SCE_GIF_PACKED_AD; 
    
    ((u_long*)WORKBASE)[4] = Ps2_gs_save.ALPHA = alpha_value; 
    ((u_long*)WORKBASE)[5] = SCE_GS_ALPHA_1; 
    
    ((u_long*)WORKBASE)[6] = 0; 
    ((u_long*)WORKBASE)[7] = SCE_GS_PABE; 
    
    ((u_long*)WORKBASE)[8] = Ps2_gs_save.FBA = 0; 
    ((u_long*)WORKBASE)[9] = SCE_GS_FBA_1; 
    
    loadImage((void*)0xF0000000); 
    
    SyncPath(); 
} 

// 100% matching! 
void    njColorBlendingMode( Int target, Int mode ) 
{
    Ps2_nj_save_current.mode_bk[target] = mode; 
    
    Ps2_nj_save_current.set_last = target; 
    
    Ps2_nj_save_current.dc_alpha = 0; 
    
    njColorBlendingModeSys(Ps2_nj_save_current.mode_bk[0], Ps2_nj_save_current.mode_bk[1]); 
}

// 100% matching!
void    njTextureShadingMode( Int mode )
{

}

// 100% matching! 
void    njSetCheapShadowMode( Int mode )
{

}

// 99.95% matching 
void	njUserClipping(Int mode ,NJS_POINT2 *p)
{ 
    unsigned long* np; // changed the original var name from the debugging symbols 
    sceVu0FVECTOR posf;
    sceVu0IVECTOR posi;

    np = (unsigned long*)WORKBASE;
    
    D2_SyncTag(); 
    
    *np++ = DMAend | 0x2; 
    *np++ = 0; 
    
    *np++ = SCE_GIF_SET_TAG(1, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1); 
    *np++ = SCE_GIF_PACKED_AD; 

    if (mode == 2)
    { 
        posf[0] = p[0].x * 32.0f; 
        posf[1] = p[0].y * 32.0f; 
        
        posf[2] = p[1].x * 32.0f; 
        posf[3] = p[1].y * 32.0f; 
        
        sceVu0FTOI0Vector(posi, posf); 
        
        *np++ = Ps2_gs_save.SCISSOR = SCE_GS_SET_SCISSOR(posi[0], posi[2] + 32, posi[1], posi[3] + 32); 
    } 
    else if (mode == 0) 
    { 
        *np++ = Ps2_gs_save.SCISSOR = SCE_GS_SET_SCISSOR(0, DISP_WIDTH, 0, DISP_HEIGHT); 
    } 
    else
    { 
        printf("njUserClipping ERROR!\n"); 
        
        exit(0); 
    }
    
    *np++ = SCE_GS_SCISSOR_1; 
    
    loadImage((void*)0xF0000000); 
    
    D2_SyncTag(); 
}

// 100% matching!
void    njGetSystemAttr(NJS_SYS_ATTR *attr)
{
    *(PS2_NJ_SAVE*)attr = Ps2_nj_save_current;
}

// 100% matching!
void    njSetSystemAttr(NJS_SYS_ATTR *attr)
{ 
    Ps2_nj_save_current = *(PS2_NJ_SAVE*)attr; 
} 

// 100% matching! 
void    njChangeSystem( Int mode, Int frame, Int count )
{
    printf("ChangeSystem\n");
}

// 100% matching!
void	njAdjustDisplay(Sint32 xadjust,Sint32 yadjust )
{ 
    if (xadjust < -100) 
    {
        xadjust = -100;
    }
    
    if (xadjust > 640) 
    {
        xadjust = 640; 
    }
    
    if (yadjust < -15) 
    {
        yadjust = -15; 
    }
    
    if (yadjust > 240) 
    {
        yadjust = 240; 
    }
    
    Db.disp[0].display.DX = (xadjust * 3) + 636; 
    Db.disp[0].display.DY = (yadjust * 2) + 32; 
    
    Db.disp[1].display.DX = (xadjust * 3) + 636; 
    Db.disp[1].display.DY = (yadjust * 2) + 32; 
    
    FlushCache(0);
}

// 100% matching!
void	njSetBorderColor(Uint32 color )
{

}
