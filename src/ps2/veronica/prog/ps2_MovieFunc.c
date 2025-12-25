#include "ps2_MovieFunc.h"
#include "adxwrap.h"
#include "ps2_dummy.h"
#include "ps2_loadtim2.h"
#include "ps2_MovieWork.h"
#include "ps2_NaSystem.h"
#include "ps2_sfd_mw.h"
#include "ps2_sg_sd.h"
#include "main.h"

#include <string.h>

VoTag* voBufTag __attribute__((aligned(64)));
VoData* voBufData;
READ_BUF* readBuf;
unsigned char* audioBuff;
TimeStamp* timeStamp;
u_long128* viBufTag;
u_long128* viBufData;
unsigned char* mpegWork;
char* videoDecStack;
int videoDecTh;
int frd;
int movie_draw;
StrFile infile;
VideoDec videoDec __attribute__((aligned(64)));
AudioDec audioDec;
VoBuf voBuf __attribute__((aligned(64)));
u_long128 test_tag[1400] __attribute__((aligned(64)));
RMI_WORK rmi;
MDSIZE_WORK mdSize __attribute__((aligned(64)));
u_long128* new_tags[64] __attribute__((aligned(64)));
int isCountVblank;
static int __image_w__;
static int __image_h__;
/* unused below */
/*int isFrameEnd; 
int oddeven; 
int handler_error; 
sceGsDBuff db;*/

// 99.95% matching
void initAll()
{
    struct ThreadParam th_param;
    struct SemaParam param;

    rmi.uiContFlag = 0;
    
    rmi.uiContFlag |= 0x1;
    
    GetAllWorkMemory();
    
    *D_CTRL |= 0x3;
    
    FlushCache(0);

    readBuf->count = 0;
    
    readBuf->put = 0;
    
    readBuf->size = 16384;
    
    sceMpegInit();
    sceIpuInit();
    
    sceMpegCreate(&videoDec.mpeg, mpegWork, 508928);
    
    sceMpegAddCallback(&videoDec.mpeg, sceMpegCbError, (sceMpegCallback)mpegError, NULL);
    sceMpegAddCallback(&videoDec.mpeg, sceMpegCbNodata, mpegNodata, NULL);
    sceMpegAddCallback(&videoDec.mpeg, sceMpegCbStopDMA, mpegStopDMA, NULL);
    sceMpegAddCallback(&videoDec.mpeg, sceMpegCbRestartDMA, mpegRestartDMA, NULL);
    sceMpegAddCallback(&videoDec.mpeg, sceMpegCbTimeStamp, (sceMpegCallback)mpegTS, NULL);
    
    videoDec.state = VD_STATE_NORMAL;
    
    videoDec.vibuf.data = viBufData;
    
    videoDec.vibuf.tag = UncAddr(viBufTag);
    
    videoDec.vibuf.n = 32;
    
    videoDec.vibuf.buffSize = 65536;
    
    videoDec.vibuf.ts = timeStamp;
    videoDec.vibuf.n_ts = 64;
    
    param.initCount = 1;
    param.maxCount = 1;
    
    videoDec.vibuf.sema = CreateSema(&param);
    
    viBufReset(&videoDec.vibuf);
    
    videoDec.vibuf.totalBytes = 0;

    audioDec.state = AU_STATE_INIT;
    
    audioDec.hdrCount = 0;
    
    audioDec.data = audioBuff;
    
    audioDec.put = 0;
    
    audioDec.count = 0;
    
    audioDec.size = 24576;
    
    audioDec.totalBytes = 0;
    audioDec.totalBytesSent = 0;
    
    audioDec.iopBuffSize = 12288;
    
    audioDec.iopLastPos = 0;
    audioDec.iopPausePos = 0;
    
    audioDec.iopBuff = iop_buff;
    audioDec.iopZero = iop_zero_buff;
    
    sceMpegAddStrCallback(&videoDec.mpeg, sceMpegStrM2V, 0, (sceMpegCallback)videoCallback, &readBuf);
    sceMpegAddStrCallback(&videoDec.mpeg, sceMpegStrPCM, 0, (sceMpegCallback)pcmCallback, &readBuf);
    
    voBuf.data = UncAddr(voBufData);
    
    voBuf.tag = voBufTag;
    
    voBuf.size = 1;
    
    voBuf.count = 0;
    
    voBuf.write = 0;
    
    voBuf.tag->status = 0;
    
    rmi.readrest = infile.size;
    rmi.writerest = infile.size;
    
    rmi.button_old = 0;
    
    rmi.iMovieState = 1;
    rmi.iMovieFrame = Ps2_vcount;
    
    th_param.entry = videoDecMain;
    
    th_param.stack = videoDecStack;
    th_param.stackSize = 16384;
    
    th_param.initPriority = 1;
    
    th_param.gpReg = &_gp;
    
    th_param.option = 0;
    
    videoDecTh = CreateThread(&th_param);
    
    StartThread(videoDecTh, &videoDec);
}

#pragma divbyzerocheck on

// 100% matching!
void readMpeg()
{
    unsigned int uiReadError;
    int count; // not from the debugging symbols

    if ((rmi.iMovieState == 2) && ((!(rmi.uiContFlag & 0x2)) && (!(rmi.uiContFlag & 0x4)))) 
    {
        do
        {
            
        } while (sceGsSyncV(0) == 1);
        
        isCountVblank = 1;
        
        frd = 0;
        
        audioDecResume(&audioDec);
        
        rmi.uiContFlag = 0x4 | rmi.uiContFlag;
    }

    if ((rmi.putsize = (readBuf->size - readBuf->count)) != 0)
    {
        rmi.put_ptr = (unsigned char*)readBuf + readBuf->put;
    }
    
    if ((rmi.readrest > 0) && (rmi.putsize >= 16384)) 
    {
        rmi.count = sceCdStRead(8, (unsigned int*)rmi.put_ptr, STMBLK, &uiReadError);
        
        OutPutCdErrorCode(&uiReadError);
        
        rmi.count *= 2048;
        
        count = (rmi.count < (readBuf->size - readBuf->count)) ? rmi.count : readBuf->size - readBuf->count;
        
        readBuf->put = (readBuf->put + count) % readBuf->size;
        
        readBuf->count += count;
        
        rmi.readrest -= rmi.count;
    }
    
    WakeupThread(videoDecTh);
    
    rmi.getsize = readBuf->count;

    if (readBuf->count != 0)
    {
        rmi.get_ptr = (unsigned char*)readBuf + ((readBuf->size + (readBuf->put - readBuf->count)) % readBuf->size);
    }
    
    if (rmi.getsize > 0)
    {
        rmi.proceed = sceMpegDemuxPssRing(&videoDec.mpeg, rmi.get_ptr, rmi.getsize, (unsigned char*)readBuf, readBuf->size);
        
        readBufEndGet(readBuf, rmi.proceed);
        
        rmi.writerest -= rmi.proceed;
    }
    
    audioDecSendToIOP(&audioDec);
    
    if ((rmi.iMovieState == 1) && (voBuf.count == voBuf.size) && (audioDec.totalBytesSent >= audioDec.iopBuffSize)) 
    {
        rmi.iMovieState = 2;
    }
    
    if ((rmi.writerest < 5) || (videoDec.state != 0)) 
    {
        isCountVblank = 0;
        
        frd = 0;
        
        rmi.iMovieState = 3;
    }
}

#pragma divbyzerocheck off

// 100% matching!
int readBufEndGet(READ_BUF *b, int size)
{
    int size_ok;

    size_ok = min(b->count, size);

    b->count -= size_ok;

    return size_ok;
}

// 100% matching! 
void setImageTag(u_int *tags, void *image)
{
    int mbx = __image_w__ / 16;
    int mby = __image_h__ / 16; 
    int i; 
    u_long* /*const*/ tag; 
    const u_long giftag[2] = { SCE_GIF_SET_TAG(0, 0, 0, 0, 0, 1), 0x000000000000000EL }; 
    
    for (i = 0; i < mbx; i++)
    {
        D2_SyncTag();
        
        tag = (void*)((u_int)tags | UNCBASE);
        
        *tag++ = DMAcnt | 0x3;
        *tag++ = 0;

        *tag++ = giftag[0] | 0x2;
        *tag++ = giftag[1];
        
        *tag++ = SCE_GS_SET_BITBLTBUF(0, 0, 0, 909312 / 64, 5, 0); 
        *tag++ = SCE_GS_BITBLTBUF; 
        
        *tag++ = SCE_GS_SET_TRXREG(1 * 16, mby * 16);
        *tag++ = SCE_GS_TRXREG;
        
        *tag++ = DMAcnt | 0x4;
        *tag++ = 0;

        *tag++ = giftag[0] | 0x2;
        *tag++ = giftag[1];
        
        *tag++ = SCE_GS_SET_TRXPOS(0, 0, i * 16, 0, 0);
        *tag++ = SCE_GS_TRXPOS;
        
        *tag++ = SCE_GS_SET_TRXDIR(0);
        *tag++ = SCE_GS_TRXDIR;

        *tag++ = SCE_GIF_SET_TAG((mby * 1024) / 16, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_IMAGE, 0); 
        *tag++ = 0;

        *tag++ = (unsigned long)((unsigned int)image & 0xFFFFFF) << 32 | 0x30000000L | ((mby * 1024) / 16);
        *tag++ = 0;

        image = (unsigned char*)image + (mby * 1024);
        
        SyncPath();
        
        loadImage(tags);
    }
    
    D2_SyncTag();
}

// 100% matching! 
void vbrank_draw() 
{
    unsigned long* tag;
    const unsigned long giftag_eop[2] = { SCE_GIF_SET_TAG(0, 1, 0, 0, 0, 1), 0x000000000000000EL }; 
    int u, v; // not from the debugging symbols
    int y; // not from the debugging symbols
    int w, h; // not from the debugging symbols

    D2_SyncTag();
    
    tag = (void*)((u_int)new_tags | UNCBASE);
    
    u = (__image_w__ - 1) * 16;
    v = (__image_h__ - 1) * 16;
    
    y = (mdSize.sDispY + 1824) * 16; 
    
    w = mdSize.sWidth * 16;
    h = mdSize.sHeight * 16;
    
    *tag++ = DMAend | 0x9;
    *tag++ = 0;

    *tag++ = giftag_eop[0] | 0x8; 
    *tag++ = giftag_eop[1];
    
    *tag++ = 0;
    *tag++ = SCE_GS_TEXFLUSH;
    
    *tag++ = SCE_GS_SET_TEX1_1(0, 0, 1, 1, 0, 0, 0);
    *tag++ = SCE_GS_TEX1_2;

    *tag++ = SCE_GS_SET_TEX0_2(14208, 5, SCE_GS_PSMCT32, 9, 9, 0, SCE_GS_DECAL, 0, SCE_GS_PSMCT32, 0, 0, 0);
    *tag++ = SCE_GS_TEX0_2;

    *tag++ = SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 0, 0, 1, 1, 0);
    *tag++ = SCE_GS_PRIM; 

    *tag++ = SCE_GS_SET_UV(8, 8);
    *tag++ = SCE_GS_UV; 

    *tag++ = SCE_GS_SET_XYZ2(27648, y, 0);
    *tag++ = SCE_GS_XYZ2;

    *tag++ = SCE_GS_SET_UV(u + 8, v + 8);
    *tag++ = SCE_GS_UV; 

    *tag++ = SCE_GS_SET_XYZ2(w + 27648, y + h, 0);
    *tag++ = SCE_GS_XYZ2; 

    SyncPath();
    
    loadImage(new_tags);
    
    D2_SyncTag();
}

// 100% matching!
void videoDecMain(VideoDec *vd)
{
    viBufReset(&vd->vibuf);

    voBuf.count = 0;
    
    voBuf.write = 0;

    decBs0(vd);

    while (voBuf.count);

    vd->state = VD_STATE_END;
}

// 100% matching!
int decBs0(VideoDec *vd)
{
    int status;
    int mpeg_param;
    
    status = 1;
    
    while (sceMpegIsEnd(&vd->mpeg) == 0) 
    {
        if (vd->state == VD_STATE_ABORT) 
        {
            status = -1;
            
            printf("decode thread: aborted\n");
            break;
        }

        mpeg_param = sceMpegGetPicture(&vd->mpeg, (sceIpuRGB32*)voBuf.data, 440);
        
        movie_draw = 1;
        
        if (mpeg_param < 0) 
        {
            printf("[ Error ] sceMpegGetPicture() decode error\n");
        }  
        else if (vd->mpeg.frameCount == 0) 
        {
            __image_w__ = vd->mpeg.width;
            __image_h__ = vd->mpeg.height;
            
            printf("size %dx%d\n", __image_w__, __image_h__);
        }
        
        voBufIncCount(&voBuf);
        
        SleepThread();
    }
    
    sceMpegReset(&vd->mpeg);
    
    return status;
}

// 100% matching!
static int copy2area(u_char *pd0, int d0, u_char *pd1, int d1, u_char *ps0, int s0, u_char *ps1, int s1)
{
    if ((d0 + d1) < (s0 + s1)) 
    {
        return 0;
    }

    if (s0 >= d0) 
    {
    	memcpy(pd0,	ps0, d0);
    	memcpy(pd1,	ps0 + d0, s0 - d0);
    	memcpy(pd1 + (s0 - d0), ps1, s1); 
    } 
    else if (s1 >= (d0 - s0)) 
    { 
	    memcpy(pd0, ps0, s0);
	    memcpy(pd0 + s0, ps1, d0 - s0);
	    memcpy(pd1,	ps1 + (d0 - s0), s1 - (d0 - s0));
    }
    else
    { 
        memcpy(pd0, ps0, s0);
        memcpy(pd0 + s0, ps1, s1);
    }
    
    return s0 + s1;
}

#pragma divbyzerocheck on

// 100% matching!
int audioDecSendToIOP(AudioDec *ad) 
{
    int pd0, pd1, d0, d1;
    u_char *ps0, *ps1;
    int s0, s1;
    int count_sent;
    int countAdj;
    int pos;

    count_sent = 0;

    pos = 0;

    switch (ad->state)
    {
    case AU_STATE_INIT:
    case AU_STATE_PAUSE:
        return 0;
    case AU_STATE_PRESET:
        pd0 = ad->iopBuff + (ad->totalBytesSent % ad->iopBuffSize);
        d0 = ad->iopBuffSize - ad->totalBytesSent;
        
        pd1 = 0;
        d1 = 0;
	    break;
    case AU_STATE_PLAY:
        pos = (sceSdRemote(1, rSdBlockTransStatus, SD_INIT_HOT) & 0xFFFFFF) - ad->iopBuff;
        
        iopGetArea(&pd0, &d0, &pd1, &d1, ad, pos);
	    break;
    }

    ps0 = ad->data + (((ad->put - ad->count) + ad->size) % ad->size);
    ps1 = ad->data;

    countAdj = (ad->count / UNIT_SIZE) * UNIT_SIZE;

    s0 = MIN(countAdj, (ad->data + ad->size) - ps0);
    s1 = countAdj - s0;

    if (((d0 + d1) >= UNIT_SIZE) && ((s0 + s1) >= UNIT_SIZE)) 
    {
    	count_sent = sendToIOP2area(pd0, d0, pd1, d1, ps0, s0, ps1, s1);
    }

    ad->count -= count_sent;

    ad->totalBytesSent += count_sent;
    
    ad->iopLastPos = (ad->iopLastPos + count_sent) % ad->iopBuffSize;

    return count_sent;
}

// 100% matching!
static void iopGetArea(int *pd0, int *d0, int *pd1, int *d1, AudioDec *ad, int pos)
{
    int len;

    len = (((pos + ad->iopBuffSize) - ad->iopLastPos) - UNIT_SIZE) % ad->iopBuffSize;

    len = (len / UNIT_SIZE) * UNIT_SIZE;

    if ((ad->iopBuffSize - ad->iopLastPos) >= len)
    { 
    	*pd0 = ad->iopBuff + ad->iopLastPos;
    	*d0 = len;
        
    	*pd1 = 0;
    	*d1 = 0;
    } 
    else 
    {			    
    	*pd0 = ad->iopBuff + ad->iopLastPos;
    	*d0 = ad->iopBuffSize - ad->iopLastPos;
        
    	*pd1 = ad->iopBuff;
    	*d1 = len - (ad->iopBuffSize - ad->iopLastPos);
    }
}

#pragma divbyzerocheck off

// 100% matching! 
static int sendToIOP2area(int pd0, int d0, int pd1, int d1, u_char *ps0, int s0, u_char *ps1, int s1)
{
    if ((d0 + d1) < (s0 + s1)) 
    {
        int diff;

        diff = (s0 + s1) - (d0 + d1);
        
    	if (diff >= s1)
        {
    	    s0 -= diff - s1;
    	    s1 = 0;
    	}
        else
        {
    	    s1 -= diff;
    	}
    }

    if (s0 >= d0)
    {
    	sendToIOP(pd0, ps0, d0);
    	sendToIOP(pd1, ps0 + d0, s0 - d0);
    	sendToIOP((pd1 + s0) - d0, ps1, s1);
    } 
    else if (s1 >= (d0 - s0)) 
    { 
        sendToIOP(pd0, ps0, s0);
        sendToIOP(pd0 + s0,	ps1, d0 - s0);
        sendToIOP(pd1, (ps1 + d0) - s0, s1 - (d0 - s0));
    }
    else 
    { 
        sendToIOP(pd0, ps0, s0);
        sendToIOP(pd0 + s0,	ps1, s1);
    }
    
    return s0 + s1;
}

// 100% matching! 
int sendToIOP(int dst, u_char *src, int size)
{
    sceSifDmaData transData; 
    u_int did; 
    int i; 
    int j; 
    u_int* data; 
    u_int* copy; 
    
    did = (u_int)src;
    
    if (size <= 0) 
    {
        return 0;
    }
    
    if (sound_flag != 0) 
    {
        FlushCache(0);
        
        copy = (u_int*)did + 128;
        
        data = (u_int*)did;
        
        for (i = 0; i < (size >> 10); i++) 
        {
            for (j = 0; j < 128; j++) 
            {
                *copy = *data;
                
                data++;
                copy++;
            }
            
            data += 128;
            copy += 128;
        }
    }
    
    transData.data = (u_int)src;
    transData.addr = (u_int)dst;
    
    transData.size = size;
    
    transData.mode = 0; 
    
    FlushCache(0);

    did = sceSifSetDma(&transData, 1);

    while (sceSifDmaStat(did) >= 0);

    return size;
}

// 100% matching!
void changeInputVolume(u_int val)
{
    sceSdRemote(1, rSdSetParam, AUTODMA_CH | SD_P_BVOLL, val & 0xFFFF);
    sceSdRemote(1, rSdSetParam, AUTODMA_CH | SD_P_BVOLR, val & 0xFFFF);
}

// 100% matching!
void setD3_CHCR(u_int val)
{
    DI();
    
    *D_ENABLEW = *D_ENABLER | 0x10000;	
    
    *D3_CHCR = val;
    
    *D_ENABLEW = *D_ENABLER & ~0x10000;	
    
    EI();
}

// 100% matching!
void setD4_CHCR(u_int val)
{
    DI();
    
    *D_ENABLEW = *D_ENABLER | 0x10000;	
    
    *D4_CHCR = val;
    
    *D_ENABLEW = *D_ENABLER & ~0x10000;	
    
    EI();
}

// 100% matching!
void scTag2(QWORD *q, void *addr, u_int id, u_int qwc)
{
    q->l[0] = ((u_long)(u_int)addr << 32) | ((u_long)id << 28) | (u_long)qwc;
}

// 100% matching! 
int viBufReset(ViBuf *f)
{
    int i;

    f->dmaStart = 0;
    f->dmaN = 0;
    
    f->readBytes = 0;
    
    f->isActive = TRUE;

    f->count_ts = 0;
    f->wt_ts = 0;
    
    for (i = 0; i < f->n_ts; i++) 
    {
    	f->ts[i].pts = TS_NONE;
    	f->ts[i].dts = TS_NONE;
        
    	f->ts[i].pos = 0;
        
    	f->ts[i].len = 0;
    }

    for (i = 0; i < f->n; i++)
    {
    	scTag2((QWORD*)(f->tag + i), DmaAddr((char*)f->data + (VIBUF_ELM_SIZE * i)), DMA_ID_REF, VIBUF_ELM_SIZE / 16);
    }
    
    scTag2((QWORD*)(f->tag + i), DmaAddr(f->tag), DMA_ID_NEXT, 0);

    *D4_QWC = 0;
    
    *D4_MADR = (u_int)DmaAddr(f->data);
    *D4_TADR = (u_int)DmaAddr(f->tag);
    
    setD4_CHCR((0 << 8) | (1 << 2) | 1);

    return TRUE;
}

// 100% matching! 
void *DmaAddr(void *val)
{
    return (void*)((u_int)val & UNCMASK);
}

#pragma divbyzerocheck on

// 100% matching! 
void viBufBeginPut(ViBuf *f, u_char **ptr0, int *len0, u_char **ptr1, int *len1)
{
    int es;
    int en;
    int fs;
    int fn;

    WAITSEMA(f->sema);

    fs = FS(f);
    fn = FN(f);

    es = (fs + f->readBytes) % f->buffSize;
    en = fn - f->readBytes;

    if ((f->buffSize - es) >= en) 
    {	
	    *ptr0 = (u_char*)f->data + es;
    	*len0 = en;
        
    	*ptr1 = NULL;
    	*len1 = 0;
    }
    else 
    {				
	    *ptr0 = (u_char*)f->data + es;
    	*len0 = f->buffSize - es;
        
    	*ptr1 = (u_char*)f->data;
    	*len1 = en - (f->buffSize - es);
    }

    SIGNALSEMA(f->sema);
}

#pragma divbyzerocheck off

// 100% matching! 
void viBufEndPut(ViBuf *f, int size)
{
    WAITSEMA(f->sema);

    f->readBytes += size;
    f->totalBytes += size;

    SIGNALSEMA(f->sema);
}

#pragma divbyzerocheck on

// 100% matching! 
int viBufModifyPts(ViBuf *f, TimeStamp *new_ts) 
{
    TimeStamp *ts;
    int rd;
    int datasize;
    int loop;

    rd = ((f->wt_ts - f->count_ts) + f->n_ts) % f->n_ts;

    datasize = VIBUF_ELM_SIZE * f->n;

    loop = 1;

    if (f->count_ts > 0) 
    {
    	while (loop) 
        {
    	    ts = f->ts + rd;
    
    	    if ((ts->len == 0) || (new_ts->len == 0)) 
            {
        		break;
    	    }
    
    	    if (IsPtsInRegion(ts->pos, new_ts->pos, new_ts->len, datasize) != 0) 
            {
                int len;

                len = MIN(ts->len, (new_ts->pos + new_ts->len) - ts->pos);
                
        		ts->pos = (ts->pos + len) % datasize;
                
        		ts->len -= len;
         
        		if (ts->len == 0) 
                {
        		    if (ts->pts >= 0) 
                    {
            			ts->pts = TS_NONE;
            			ts->dts = TS_NONE;
                        
            			ts->pos = 0;
                        
            			ts->len = 0;
        		    }
                    
        		    f->count_ts = MAX(f->count_ts - 1, 0);
        		}
            } 
            else 
            {
    		    loop = 0;
    	    }
    
    	    rd = (rd + 1) % f->n_ts;
    	}
    }

    return 0;
}

// 100% matching! 
int IsPtsInRegion(int tgt, int pos, int len, int size)
{
    int tgt1;
    
    tgt1 = ((tgt + size) - pos) % size;
    
    return tgt1 < len;
}

// 100% matching! 
int viBufPutTs(ViBuf *f, TimeStamp *ts)
{
    int ret;

    ret = 0;

    WAITSEMA(f->sema);

    if (f->count_ts < f->n_ts) 
    {
    	viBufModifyPts(f, ts);
    
    	if ((ts->pts >= 0) || (ts->dts >= 0)) 
        {
    	    f->ts[f->wt_ts].pts = ts->pts;
    	    f->ts[f->wt_ts].dts = ts->dts;
            
    	    f->ts[f->wt_ts].pos = ts->pos;
    	    
            f->ts[f->wt_ts].len = ts->len;
    
    	    f->count_ts++;
    	    
            f->wt_ts = (f->wt_ts + 1) % f->n_ts;
    	}
        
    	ret = 1;
    } 

    SIGNALSEMA(f->sema);

    return ret;
}

#pragma divbyzerocheck off

// 100% matching!
void voBufIncCount(VoBuf *f)
{
    DI();

    f->tag->status = VOBUF_STATUS_FULL;
    
    f->count++;
    
    EI();
}

// 100% matching!
void audioDecResume(AudioDec *ad)
{
    changeInputVolume(0);

    sceSdRemote(1, rSdBlockTrans, AUTODMA_CH, SD_TRANS_MODE_WRITE_FROM | SD_BLOCK_LOOP, ad->iopBuff, (ad->iopBuffSize / UNIT_SIZE) * UNIT_SIZE, ad->iopBuff + ad->iopPausePos);

    changeInputVolume(32767);

    ad->state = AU_STATE_PLAY;
}

// 100% matching! 
int getFIFOindex(ViBuf *f, void *addr)
{
    if (addr == DmaAddr(f->tag + (f->n + 1))) 
    {
	    return 0;
    } 
    else 
    {
	    return ((u_int)addr - (u_int)f->data) / VIBUF_ELM_SIZE;
    }
}

// 100% matching! 
int videoDecPutTs(VideoDec *vd, long pts_val, long dts_val, u_char *start, int len)
{
    TimeStamp ts;

    ts.pts = pts_val;
    ts.dts = dts_val;
    
    ts.pos = start - (u_char*)vd->vibuf.data;
    
    ts.len = len;
    
    return viBufPutTs(&videoDec.vibuf, &ts);
}

// 100% matching! 
void audioDecBeginPut(AudioDec *ad, u_char **ptr0, int *len0, u_char **ptr1, int *len1)
{
    int len;

    if (ad->state == AU_STATE_INIT)
    {
    	*ptr0 = (u_char*)&ad->sshd + ad->hdrCount;
    	*len0 = AU_HDR_SIZE - ad->hdrCount;
        
    	*ptr1 = ad->data;
    	*len1 = ad->size;
    
    	return;
    }

    len = ad->size - ad->count;

    if ((ad->size - ad->put) >= len) 
    {
    	*ptr0 = ad->data + ad->put;
    	*len0 = len;
        
    	*ptr1 = NULL;
    	*len1 = 0;
    } 
    else 
    {			   
    	*ptr0 = ad->data + ad->put;
    	*len0 = ad->size - ad->put;
        
    	*ptr1 = ad->data;
    	*len1 = len - (ad->size - ad->put);
    }
}

// 100% matching!
void termAll()
{
    sceSdRemote(1, 32992, AUTODMA_CH, SD_TRANS_MODE_STOP, 0, 0);
    
    TerminateThread(videoDecTh);
    DeleteThread(videoDecTh);

    videoDecDelete(&videoDec);
    audioDecDelete(&audioDec);
    
    sceCdStStop();
    
    memset(ADX_STREAM_BUFFER, 0, 469120);
    
    rmi.uiContFlag &= ~0x1;
}

// 100% matching!
int viBufDelete(ViBuf *f)
{
    setD4_CHCR((0 << 8) | (1 << 2) | 1);
    
    *D4_QWC = 0;
    
    *D4_MADR = 0;
    *D4_TADR = 0;

    DeleteSema(f->sema);
    
    return TRUE;
}

// 100% matching!
int videoDecDelete(VideoDec *vd)
{
    viBufDelete(&vd->vibuf);
    sceMpegDelete(&vd->mpeg);

    return 1;
}

// 100% matching!
int audioDecDelete(AudioDec *ad)
{
    changeInputVolume(0);
    
    return 1;
}

// 100% matching!
int GetAllWorkMemory()
{	              
    SyncPath();            
    
    Ps2DrawOTag();           
    
    SyncPath();          
    
    Ps2ClearOT();                           
    
    FlushCache(0);                          
    
    memset(ADX_STREAM_BUFFER, 0, 469120);    

    (char*)voBufData = ADX_STREAM_BUFFER;    
    
    (char*)readBuf = &ADX_STREAM_BUFFER[450560];    
    
	(char*)viBufTag = &ADX_STREAM_BUFFER[467008];   
    
	(char*)timeStamp = &ADX_STREAM_BUFFER[467584];   
    
	(unsigned char*)viBufData = Ps2_MOVIE;             
    
	audioBuff = (unsigned char*)&viBufData[4096];       
    
	(unsigned char*)videoDecStack = &audioBuff[24576];  
    
	mpegWork = (unsigned char*)&videoDecStack[16384];     
    
	(unsigned char*)voBufTag = &mpegWork[508928];              
    
	printf("mpegWorkAddr      = %x :size %x\n", mpegWork, 508928);
	printf("voBufDataAddr     = %x :size %x\n", voBufData, 450560);
	printf("viBufTagAddr      = %x :size %x\n", viBufTag, 576);
	printf("viBufDataAddr     = %x :size %x\n", viBufData, 65536);
	printf("readBufAddr       = %x :size %x\n", readBuf, 16448);
	printf("audioBufAddr      = %x :size %x\n", audioBuff, 24576);
	printf("videoDecStackAddr = %x :size %x\n", videoDecStack, 16384);
	printf("timeStampAddr     = %x :size %x\n", timeStamp, 1536);
	printf("---\n");
    
    return 0;
}

// 100% matching!
void OutPutCdErrorCode(unsigned int* err) 
{
    switch (*err) 
    {                         
    case 0:
        break;
    case -1:
        printf("[FAIL]");
        break;
    case 50:
        printf("[EOM]");
        break;
    case 49:
        printf("[TRMOPN]");
        break;
    case 48:
        printf("READ MISS!!\n");
        break;
    case 20:
        printf("[CUD]");
        break;
    case 19:
        printf("[NORDY]");
        break;
    case 1:
        printf("[ABRT]");
        break;
    default:
        printf("UnknownError");
        break;
    }

    if ((*err != 0) && (*err != 48))
    {
        printf(" [READ CD ERROR] (in OutPutCdErrorCode)\n");
    }
}

// 100% matching!
int videoCallback(sceMpeg *mp, sceMpegCbDataStr *str, void *data)
{
    READ_BUF *rb;
    u_char *ps0, *ps1;
    int s0, s1;
    u_char *pd0, *pd1;
    u_char *pd0Unc, *pd1Unc;
    int d0, d1;
    int len;

    rb = (READ_BUF*)data;

    ps0 = str->data;
    ps1 = rb->data;

    s0 = MIN(str->len, (rb->data + rb->size) - str->data);
    s1 = str->len - s0;

    viBufBeginPut(&videoDec.vibuf, &pd0, &d0, &pd1, &d1);
    
    pd0Unc = UncAddr(pd0);
    pd1Unc = UncAddr(pd1);

    len = copy2area(pd0Unc, d0, pd1Unc, d1, ps0, s0, ps1, s1);

    if ((len > 0) && (videoDecPutTs(&videoDec, str->pts, str->dts, pd0, len) == 0)) 
    {
        printf("[ Error ] pts buffer overflow\n");
    }

    viBufEndPut(&videoDec.vibuf, len);

    return (len > 0) ? 1 : 0;
}

#pragma divbyzerocheck on

// 100% matching!
int pcmCallback(sceMpeg *mp, sceMpegCbDataStr *str, void *data) 
{
    READ_BUF *rb;
    u_char *ps0, *ps1;
    int s0, s1;
    u_char *pd0, *pd1;
    int d0, d1;
    int len;
    int ret;

    rb = data;

    ps0 = str->data;
    ps1 = rb->data;

    ps0 = &str->data[4];
    
    if (ps0 >= (rb->data + rb->size)) 
    {
        ps0 -= rb->size;
    }
    
    len = str->len - 4;
    
    s0 = MIN((u_int)len, (rb->data + rb->size) - ps0);
    s1 = len - s0;
    
    ps1 = rb->data;
    
    audioDecBeginPut(&audioDec, &pd0, &d0, &pd1, &d1);
    
    ret = copy2area(pd0, d0, pd1, d1, ps0, s0, ps1, s1);
    
    if (audioDec.state == AU_STATE_INIT) 
    {
        int hdr_add;

        hdr_add = MIN(AU_HDR_SIZE - audioDec.hdrCount, ret);
        
        audioDec.hdrCount += hdr_add;
        
        if (audioDec.hdrCount >= AU_HDR_SIZE) 
        {
            audioDec.state = AU_STATE_PRESET;
        }
        
        ret -= hdr_add;
        
        audioDec.put = (audioDec.put + ret) % audioDec.size;
        
        audioDec.count += ret;
        
        audioDec.totalBytes += ret;
        
        ret += hdr_add;
    } 
    else 
    {
        audioDec.put = (audioDec.put + ret) % audioDec.size;
        
        audioDec.count += ret;
        
        audioDec.totalBytes += ret;
    }
    
    return (ret > 0) ? 1 : 0;
}

#pragma divbyzerocheck off

// 100% matching!
int mpegError(sceMpeg *mp, sceMpegCbDataError *cberror, void *anyData)
{
    printf("%s\n", cberror->errMessage);
    
    return 1;
}

#pragma divbyzerocheck on

// 100% matching!
int mpegNodata(sceMpeg *mp, sceMpegCbData *cbdata, void *anyData) 
{
    int i;
    int index;
    int last;
    unsigned int d4chcr;
    int isNewData;
    int consume;
    int read_start, read_n;

    isNewData = 0;

    SleepThread();

    WaitSema(videoDec.vibuf.sema);

    if (videoDec.vibuf.isActive == FALSE) 
    {
        printf("[ Error ] DMA ADD not active\n");
        
        return FALSE;
    }

    setD4_CHCR((DMA_ID_REFE << 28) | (0 << 8) | (1 << 2) | 1);
    
    d4chcr = *D4_CHCR;

    index = getFIFOindex(&videoDec.vibuf, (void*)*D4_MADR);
    
    consume = ((index + videoDec.vibuf.n) - videoDec.vibuf.dmaStart) % videoDec.vibuf.n;
    
    videoDec.vibuf.dmaStart = (videoDec.vibuf.dmaStart + consume) % videoDec.vibuf.n;
    videoDec.vibuf.dmaN -= consume;

    read_start = (videoDec.vibuf.dmaStart + videoDec.vibuf.dmaN) % videoDec.vibuf.n;
    read_n = videoDec.vibuf.readBytes / VIBUF_ELM_SIZE;
    
    videoDec.vibuf.readBytes %= VIBUF_ELM_SIZE;

    if (read_n > 0) 
    {
    	last = (((videoDec.vibuf.dmaStart + videoDec.vibuf.dmaN) - 1) + videoDec.vibuf.n) % videoDec.vibuf.n;
    	
        scTag2((QWORD*)(videoDec.vibuf.tag + last), (char*)videoDec.vibuf.data + (VIBUF_ELM_SIZE * last), DMA_ID_REF, VIBUF_ELM_SIZE / 16);
    	
        isNewData = 1;
    }

    index = read_start;
    
    for (i = 0; i < read_n; i++) 
    {
    	scTag2((QWORD*)(videoDec.vibuf.tag + index), (char*)videoDec.vibuf.data + (VIBUF_ELM_SIZE * index), (i == (read_n - 1)) ? DMA_ID_REFE : DMA_ID_REF, VIBUF_ELM_SIZE / 16);
        
    	index = (index + 1) % videoDec.vibuf.n;
    }

    videoDec.vibuf.dmaN += read_n;

    if (videoDec.vibuf.dmaN != 0) 
    {
    	if (isNewData != 0) 
        {
    	    d4chcr = (d4chcr & 0xFFFFFFF) | (DMA_ID_REF << 28);
    	}
        
    	setD4_CHCR(d4chcr | 0x100);
    }

    SignalSema(videoDec.vibuf.sema);

    return 1;
}

#pragma divbyzerocheck off

// 100% matching!
int mpegStopDMA(sceMpeg *mp, sceMpegCbData *cbdata, void *anyData)
{
    WaitSema(videoDec.vibuf.sema);
    
    videoDec.vibuf.isActive = FALSE;
    
    setD4_CHCR((0 << 8) | (1 << 2) | 1);		

    videoDec.vibuf.env.d4madr = *D4_MADR;
    videoDec.vibuf.env.d4tadr = *D4_TADR;
    
    videoDec.vibuf.env.d4qwc = *D4_QWC;
    
    videoDec.vibuf.env.d4chcr = *D4_CHCR;

    while (DGET_IPU_CTRL() & 0xF0);

    setD3_CHCR((0 << 8) | 0);		
    
    videoDec.vibuf.env.d3madr = *D3_MADR;
    
    videoDec.vibuf.env.d3qwc = *D3_QWC;
    
    videoDec.vibuf.env.d3chcr = *D3_CHCR;

    videoDec.vibuf.env.ipubp = DGET_IPU_BP();
    videoDec.vibuf.env.ipuctrl = DGET_IPU_CTRL();

    SignalSema(videoDec.vibuf.sema);

    return 1;
}

#pragma divbyzerocheck on 

// 100% matching!
int mpegRestartDMA(sceMpeg *mp, sceMpegCbData *cbdata, void *anyData)
{
    unsigned int bp;
    int fp;
    int ifc;
    unsigned int d4madr_next, d4qwc_next, d4tadr_next, d4chcr_next;
    int index, index_next;
    int id;

    fp = (videoDec.vibuf.env.ipubp >> 16) & 0x3;
    bp = videoDec.vibuf.env.ipubp & 0x7F;

    ifc = (videoDec.vibuf.env.ipubp >> 8) & 0xF;

    d4madr_next = videoDec.vibuf.env.d4madr - ((fp + ifc) << 4);
    d4qwc_next = videoDec.vibuf.env.d4qwc + (fp + ifc);
    d4tadr_next = videoDec.vibuf.env.d4tadr;
    d4chcr_next = videoDec.vibuf.env.d4chcr | 0x100;

    WaitSema(videoDec.vibuf.sema);

    if (d4madr_next < (unsigned int)videoDec.vibuf.data) 
    {
	    d4qwc_next = (DATA_ADDR_EX(0) - d4madr_next) >> 4;
        
    	d4madr_next += videoDec.vibuf.n * VIBUF_ELM_SIZE;
	    d4tadr_next = TAG_ADDR_EX(0);
        
	    id = ((videoDec.vibuf.env.d4madr == DATA_ADDR_EX(0)) || (videoDec.vibuf.env.d4madr == DATA_ADDR_EX(videoDec.vibuf.n))) ? DMA_ID_REFE : DMA_ID_REF;
	    
        d4chcr_next = (videoDec.vibuf.env.d4chcr & 0xFFFFFFF) | (id << 28) | 0x100;

    	if (!IsInRegion(0, videoDec.vibuf.dmaStart, videoDec.vibuf.dmaN, videoDec.vibuf.n)) 
        {
    	    videoDec.vibuf.dmaStart = videoDec.vibuf.n - 1;
    	    videoDec.vibuf.dmaN++;
    	}
    } 
    else if ((index = getFIFOindex(&videoDec.vibuf, (void*)videoDec.vibuf.env.d4madr)) != (index_next = getFIFOindex(&videoDec.vibuf, (void*)d4madr_next))) 
    {
        d4tadr_next = TAG_ADDR_EX(index);
        d4qwc_next = (DATA_ADDR_EX(index) - d4madr_next) >> 4;
        
        id = (WRAP_ADDR_EX(videoDec.vibuf.env.d4madr) == DATA_ADDR_EX((videoDec.vibuf.dmaStart + videoDec.vibuf.dmaN) % videoDec.vibuf.n)) ? DMA_ID_REFE : DMA_ID_REF;

        d4chcr_next = (videoDec.vibuf.env.d4chcr & 0xFFFFFFF) | (id << 28) | 0x100;
    
        if (!IsInRegion(index_next, videoDec.vibuf.dmaStart, videoDec.vibuf.dmaN, videoDec.vibuf.n)) 
        {
            videoDec.vibuf.dmaStart = index_next;
            videoDec.vibuf.dmaN++;
        }
    }

    if ((videoDec.vibuf.env.d3madr != 0) && (videoDec.vibuf.env.d3qwc != 0)) 
    {
    	*D3_MADR = videoDec.vibuf.env.d3madr;
        
    	*D3_QWC = videoDec.vibuf.env.d3qwc;
    	
        setD3_CHCR(videoDec.vibuf.env.d3chcr | 0x100);
    }

    if (videoDec.vibuf.dmaN != 0) 
    {
    	while (sceIpuIsBusy());
        
    	sceIpuBCLR(bp);
    	
        while (sceIpuIsBusy());
    }

    *D4_MADR = d4madr_next;
    *D4_TADR = d4tadr_next;
    
    *D4_QWC = d4qwc_next;
    
    if (videoDec.vibuf.dmaN != 0) 
    {
	    setD4_CHCR(d4chcr_next);
    }

    *IPU_CTRL = videoDec.vibuf.env.ipuctrl;

    videoDec.vibuf.isActive = TRUE;

    SignalSema(videoDec.vibuf.sema);

    return TRUE;
}

// 100% matching!
int mpegTS(sceMpeg *mp, sceMpegCbDataTimeStamp *cbts, void *anyData)
{
    unsigned int d4madr;
    unsigned int ipubp;
    int bp;
    int fp;
    int ifc;
    unsigned int stop;
    int datasize;
    int isEnd;
    int tscount;
    int i;
    TimeStamp ts; // not from the debugging symbols
    unsigned int d4madr_next; // not from the debugging symbols
    int wt; // not from the debugging symbols
    
    d4madr = *D4_MADR;

    ipubp = DGET_IPU_BP();

    bp = videoDec.vibuf.env.ipubp & 0x7F;

    fp = (ipubp >> 16) & 0x3;

    ifc = (ipubp >> 8) & 0xF;

    d4madr_next = d4madr - ((fp + ifc) << 4);

    datasize = VIBUF_ELM_SIZE * videoDec.vibuf.n;

    isEnd = 0;

    WaitSema(videoDec.vibuf.sema);

    ts.pts = TS_NONE;
    ts.dts = TS_NONE;

    stop = (((d4madr_next + (bp >> 3)) + datasize) - (int)videoDec.vibuf.data) % datasize;

    tscount = videoDec.vibuf.count_ts;
    wt = videoDec.vibuf.wt_ts;

    for (i = 0; (i < tscount) && (isEnd == 0); i++) 
    {
        int rd;

        rd = (((wt - tscount) + videoDec.vibuf.n_ts) + i) % videoDec.vibuf.n_ts;
        
        if (IsPtsInRegion(stop, videoDec.vibuf.ts[rd].pos, videoDec.vibuf.ts[rd].len, datasize) != 0)
        {
            ts.pts = videoDec.vibuf.ts[rd].pts;
            ts.dts = videoDec.vibuf.ts[rd].dts;
            
            videoDec.vibuf.ts[rd].pts = TS_NONE;
            videoDec.vibuf.ts[rd].dts = TS_NONE;
        
            isEnd = 1;
            
            videoDec.vibuf.count_ts -= MIN(videoDec.vibuf.count_ts, 1);
        }
    }

    SignalSema(videoDec.vibuf.sema);
    
    cbts->pts = ts.pts;
    cbts->dts = ts.dts;
    
    return 1;
}

#pragma divbyzerocheck off
