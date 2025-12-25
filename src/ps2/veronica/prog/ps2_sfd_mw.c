#include "ps2_sfd_mw.h"
#include "ps2_MovieFunc.h"
#include "ps2_NaSystem.h"
#include "main.h"

//#include <string.h>

MW_PLY_OBJ MwObj;
MWPLY MwHandle = &MwObj;
MWS_PLY_INIT_SFD __sfd_mw_conf__; /* unused */
MWD_IF Ps2Func = 
{ 
    ps2mwErrorStop, 
    ps2mwErrorStop, 
    ps2mwErrorStop, 
    ps2mwPlyVsyncHndl,  
    ps2mwPlyExecSvrHndl,
    ps2mwPlyDestroy,
    ps2mwPlyStartFname,
    ps2mwPlyStop,
    ps2mwPlyGetStat,
    ps2mwPlyGetTime,
    ps2mwPlyPause,
    ps2mwPlySetOutVol,
    ps2mwPlyGetOutVol,
    ps2mwErrorStop,
};

// 100% matching!
Sint32 mwPlyCalcWorkSofdec(Sint32 ftype, Sint32 max_bps, Sint32 max_sx, Sint32 max_sy, Sint32 nfb)
{

}

// 100% matching!
MWPLY ps2mwPlyCreateSofdec(MWS_PLY_CPRM_SFD* cprm, char* fname) 
{
    char read_name[256];
    int i;
    sceCdRMode mode;
    int loop;
    
    sceGsSyncV(0);
    sceGsSyncV(0);

    for (i = 0; i < strlen(fname); i++) 
    {
        if ((fname[i] >= 'a') && (fname[i] <= 'z')) 
        {
            fname[i] -= ' ';
        }
    }
    
    sprintf(read_name, "%s%s;1", "\\MOVIE\\", fname);
    
    infile.iopBuf = (unsigned char*)iop_read_buff;
    
    sceCdStInit(iRingBufNum * 16, iRingBufNum, (((unsigned int)infile.iopBuf + 15) / 16) * 16);

    while (sceCdSearchFile(&infile.fp, read_name) == 0)
    {
        printf("Cannot open '%s'(sceCdSearchFile)\n", read_name);

        while (sceCdPause() == 0) 
        {
            for (loop = 0; loop < 100000; loop++)
            {
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
            }
        }

        sceCdSync(16);

        for (loop = 0; loop < 100000; loop++)
        {
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
        }
    }
    
    printf("[%s] is open!\n", read_name);
    
    mode.trycount = 0;
    
    mode.spindlctrl = 0;
    
    mode.datapattern = 0;
    
    infile.size = infile.fp.size;
    
    sceCdStStart(infile.fp.lsn, &mode);
    
    Setps2FuncTbl(MwHandle);
    
    return MwHandle;
}

// 100% matching!
void mwPlyExecServer(void)
{
    movie_draw = 0;

    do 
    {
        readMpeg();
    } while ((movie_draw == 0) && (rmi.iMovieState != 3));
    
    sceGsSyncPath(0, 0);
    
    setImageTag((unsigned int*)test_tag, voBuf.data);
    
    vbrank_draw();
    
    voBuf.count--;
}

// 100% matching!
void mwPlyFinishSofdec(void)
{

}

// 100% matching!
Sint32 mwPlyGetBright(MWPLY mwply)
{

}

// 100% matching!
void mwPlyInitSofdec(MWS_PLY_INIT_SFD *iprm)
{

}

// 100% matching!
void mwPlyPreInitSofdec(void) 
{

}

// 100% matching!
void mwPlySetDispMode(Sint32 mode, Sint32 frame, Sint32 count, Sint32 latency)
{

}

// 100% matching!
void mwPlySetDispPos(MWPLY mwply, float lx, float ly) 
{
    mdSize.sDispX = lx;
    mdSize.sDispY = ly;
}

// 100% matching!
void mwPlySetFastHalfpel(MWPLY mwply, Sint32 sw) 
{

}

// 100% matching!
void mwPlyStartFrame(void)
{

}

// 100% matching!
void mwPlySetDispSize(MWPLY mwply, float sx, float sy)
{
    mdSize.sWidth = sx;
    mdSize.sHeight = sy;
}

// 100% matching!
void ps2mwPlyVsyncHndl(MWPLY ply)
{

}

// 100% matching!
void ps2mwPlyExecSvrHndl(MWPLY ply)
{

}

// 100% matching!
void ps2mwPlyDestroy(MWPLY ply)
{

}

// 100% matching!
void ps2mwPlyStartFname(MWPLY ply, Sint8 *fname)
{
    char nameBuf[256];
    char* dest;
    char* src;
    
    src = (char*)fname;
    
    initAll();
    
    memset(nameBuf, 0, sizeof(nameBuf));
    
    dest = nameBuf;
    
    while (*src != 0) 
    {
        *dest++ = *src++;
    }

    if (strcmp(nameBuf, "MV_016.PSS") == 0) 
    {
        rmi.MVCancelButton = 0x800;
    } 
    else 
    {
        rmi.MVCancelButton = 0x100;
    }
}

// 100% matching!
void ps2mwPlyStop(MWPLY ply)
{
    termAll();
}

// 100% matching!
MWE_PLY_STAT ps2mwPlyGetStat(MWPLY ply)
{
    return rmi.iMovieState;
}

// 100% matching!
void ps2mwPlyGetTime(MWPLY ply, Sint32 *ncount, Sint32 *tscale)
{
    *ncount = Ps2_vcount - rmi.iMovieFrame;
    
    *tscale = 29;
}

// 100% matching!
void ps2mwPlyPause(MWPLY ply, Sint32 sw)
{
    if (sw != 0) 
    {
        rmi.uiContFlag |= 0x2;
    }
    else 
    {
        rmi.uiContFlag &= ~0x2;
    }
}

// 100% matching!
void ps2mwPlySetOutVol(MWPLY ply, Sint32 vol)
{
    changeInputVolume(32.8 * (vol + 999));
}

// 100% matching!
Sint32 ps2mwPlyGetOutVol(MWPLY ply)
{

}

// 100% matching!
void ps2mwErrorStop()
{
    printf("-\nMW Error Stop...\nThis function is no supported...\n");
}

// 100% matching!
void Setps2FuncTbl(MWPLY mwply) 
{
    mwply->vtbl = &Ps2Func;
}
