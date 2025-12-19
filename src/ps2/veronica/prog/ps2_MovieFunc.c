#include "ps2_MovieFunc.h"
#include "ps2_dummy.h"
#include "ps2_loadtim2.h"
#include "ps2_NaSystem.h"
#include "ps2_sfd_mw.h"
#include "ps2_sg_sd.h"
#include "main.h"

#include <string.h>

int isCountVblank;
/*int isFrameEnd;
int oddeven;
int handler_error;*/
static int __image_w__;
static int __image_h__;
long128* new_tags[64];
VideoDec videoDec;
int videoDecTh;
/*void* _gp;*/
char* videoDecStack;
/*void(*videoDecMain)(_anon17*);
_anon35 rmi;
unsigned int Ps2_vcount;
_anon30 infile;*/
VoTag* voBufTag;
VoData* voBufData;
READ_BUF* readBuf;
/*int(*pcmCallback)(_anon0*, _anon11*, void*);
int(*videoCallback)(_anon0*, _anon11*, void*);*/
AudioDec audioDec;
/*int iop_zero_buff;
int iop_buff;*/
unsigned char* audioBuff;
TimeStamp* timeStamp;
long128* viBufTag;
long128* viBufData;
/*int(*mpegTS)(_anon0*, _anon5*, void*);
int(*mpegRestartDMA)(_anon0*, _anon2*, void*);
int(*mpegStopDMA)(_anon0*, _anon2*, void*);
int(*mpegNodata)(_anon0*, _anon2*, void*);
int(*mpegError)(_anon0*, _anon1*, void*);*/
unsigned char* mpegWork;
int frd;
/*_anon41 mdSize;*/
unsigned char* Ps2_MOVIE = &Ps2_PBUFF[1179648]; 
/*<unknown fundamental type (0xa510)> test_tag[1400];
_anon24 db;*/

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

    //*tag++ = SCE_GS_SET_TEX0_2(0, 10, SCE_GS_PSMCT32, 10, 9, 0, SCE_GS_MODULATE, 0, SCE_GS_PSMCT32, 0, 0, 0); // TODO: match the function with this 
    *tag++ = 0xA64017780;
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

/*// 
// Start address: 0x2ecae0
int viBufModifyPts(_anon7* f, _anon8* new_ts)
{
	int loop;
	int datasize;
	int rd;
	_anon8* ts;
	// Line 1176, Address: 0x2ecae0, Func Offset: 0
	// Line 1178, Address: 0x2ecb00, Func Offset: 0x20
	// Line 1179, Address: 0x2ecb28, Func Offset: 0x48
	// Line 1178, Address: 0x2ecb2c, Func Offset: 0x4c
	// Line 1180, Address: 0x2ecb30, Func Offset: 0x50
	// Line 1182, Address: 0x2ecb34, Func Offset: 0x54
	// Line 1185, Address: 0x2ecb3c, Func Offset: 0x5c
	// Line 1186, Address: 0x2ecb50, Func Offset: 0x70
	// Line 1188, Address: 0x2ecb68, Func Offset: 0x88
	// Line 1190, Address: 0x2ecb80, Func Offset: 0xa0
	// Line 1192, Address: 0x2ecba0, Func Offset: 0xc0
	// Line 1193, Address: 0x2ecbb8, Func Offset: 0xd8
	// Line 1194, Address: 0x2ecbc4, Func Offset: 0xe4
	// Line 1196, Address: 0x2ecbd0, Func Offset: 0xf0
	// Line 1198, Address: 0x2ecbdc, Func Offset: 0xfc
	// Line 1199, Address: 0x2ecbe0, Func Offset: 0x100
	// Line 1200, Address: 0x2ecbe4, Func Offset: 0x104
	// Line 1201, Address: 0x2ecbe8, Func Offset: 0x108
	// Line 1202, Address: 0x2ecbec, Func Offset: 0x10c
	// Line 1203, Address: 0x2ecbf0, Func Offset: 0x110
	// Line 1205, Address: 0x2ecc04, Func Offset: 0x124
	// Line 1206, Address: 0x2ecc0c, Func Offset: 0x12c
	// Line 1207, Address: 0x2ecc10, Func Offset: 0x130
	// Line 1208, Address: 0x2ecc28, Func Offset: 0x148
	// Line 1211, Address: 0x2ecc30, Func Offset: 0x150
	// Line 1210, Address: 0x2ecc4c, Func Offset: 0x16c
	// Line 1211, Address: 0x2ecc50, Func Offset: 0x170
	// Func End, Address: 0x2ecc58, Func Offset: 0x178
}*/

#pragma divbyzerocheck on

// 100% matching! 
int IsPtsInRegion(int tgt, int pos, int len, int size)
{
    int tgt1;
    
    tgt1 = ((tgt + size) - pos) % size;
    
    return tgt1 < len;
}

#pragma divbyzerocheck off

/*// 
// Start address: 0x2ecc80
int viBufPutTs(_anon7* f, _anon8* ts)
{
	int ret;
	// Line 1217, Address: 0x2ecc80, Func Offset: 0
	// Line 1220, Address: 0x2ecc98, Func Offset: 0x18
	// Line 1222, Address: 0x2ecca8, Func Offset: 0x28
	// Line 1223, Address: 0x2eccbc, Func Offset: 0x3c
	// Line 1225, Address: 0x2eccc8, Func Offset: 0x48
	// Line 1227, Address: 0x2ecce0, Func Offset: 0x60
	// Line 1228, Address: 0x2eccfc, Func Offset: 0x7c
	// Line 1229, Address: 0x2ecd1c, Func Offset: 0x9c
	// Line 1230, Address: 0x2ecd3c, Func Offset: 0xbc
	// Line 1232, Address: 0x2ecd5c, Func Offset: 0xdc
	// Line 1233, Address: 0x2ecd68, Func Offset: 0xe8
	// Line 1235, Address: 0x2ecd88, Func Offset: 0x108
	// Line 1238, Address: 0x2ecd8c, Func Offset: 0x10c
	// Line 1240, Address: 0x2ecd94, Func Offset: 0x114
	// Line 1241, Address: 0x2ecd98, Func Offset: 0x118
	// Func End, Address: 0x2ecdb0, Func Offset: 0x130
}*/

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

/*// 
// Start address: 0x2ecec0
int videoDecPutTs(_anon17* vd, long pts_val, long dts_val, unsigned char* start, int len)
{
	_anon8 ts;
	// Line 1299, Address: 0x2ecec0, Func Offset: 0
	// Line 1303, Address: 0x2ecec8, Func Offset: 0x8
	// Line 1304, Address: 0x2ececc, Func Offset: 0xc
	// Line 1305, Address: 0x2eced0, Func Offset: 0x10
	// Line 1307, Address: 0x2eced4, Func Offset: 0x14
	// Line 1305, Address: 0x2ecedc, Func Offset: 0x1c
	// Line 1307, Address: 0x2ecee4, Func Offset: 0x24
	// Line 1308, Address: 0x2ecef0, Func Offset: 0x30
	// Func End, Address: 0x2ecefc, Func Offset: 0x3c
}

// 
// Start address: 0x2ecf00
void audioDecBeginPut(_anon12* ad, unsigned char** ptr0, int* len0, unsigned char** ptr1, int* len1)
{
	int len;
	// Line 1324, Address: 0x2ecf00, Func Offset: 0
	// Line 1325, Address: 0x2ecf0c, Func Offset: 0xc
	// Line 1326, Address: 0x2ecf14, Func Offset: 0x14
	// Line 1325, Address: 0x2ecf18, Func Offset: 0x18
	// Line 1326, Address: 0x2ecf20, Func Offset: 0x20
	// Line 1327, Address: 0x2ecf2c, Func Offset: 0x2c
	// Line 1328, Address: 0x2ecf34, Func Offset: 0x34
	// Line 1329, Address: 0x2ecf38, Func Offset: 0x38
	// Line 1336, Address: 0x2ecf40, Func Offset: 0x40
	// Line 1338, Address: 0x2ecf48, Func Offset: 0x48
	// Line 1336, Address: 0x2ecf4c, Func Offset: 0x4c
	// Line 1338, Address: 0x2ecf50, Func Offset: 0x50
	// Line 1339, Address: 0x2ecf60, Func Offset: 0x60
	// Line 1340, Address: 0x2ecf6c, Func Offset: 0x6c
	// Line 1341, Address: 0x2ecf70, Func Offset: 0x70
	// Line 1343, Address: 0x2ecf74, Func Offset: 0x74
	// Line 1344, Address: 0x2ecf7c, Func Offset: 0x7c
	// Line 1345, Address: 0x2ecf88, Func Offset: 0x88
	// Line 1346, Address: 0x2ecf98, Func Offset: 0x98
	// Line 1347, Address: 0x2ecfa0, Func Offset: 0xa0
	// Line 1349, Address: 0x2ecfb4, Func Offset: 0xb4
	// Func End, Address: 0x2ecfbc, Func Offset: 0xbc
}*/

// 
// Start address: 0x2ecfc0
void termAll()
{
	// Line 1364, Address: 0x2ecfc0, Func Offset: 0
	// Line 1366, Address: 0x2ecfc4, Func Offset: 0x4
	// Line 1364, Address: 0x2ecfcc, Func Offset: 0xc
	// Line 1366, Address: 0x2ecfd0, Func Offset: 0x10
	// Line 1370, Address: 0x2ecfe4, Func Offset: 0x24
	// Line 1371, Address: 0x2ecff0, Func Offset: 0x30
	// Line 1383, Address: 0x2ecffc, Func Offset: 0x3c
	// Line 1384, Address: 0x2ed008, Func Offset: 0x48
	// Line 1390, Address: 0x2ed014, Func Offset: 0x54
	// Line 1394, Address: 0x2ed01c, Func Offset: 0x5c
	// Line 1404, Address: 0x2ed034, Func Offset: 0x74
	// Line 1405, Address: 0x2ed04c, Func Offset: 0x8c
	// Func End, Address: 0x2ed058, Func Offset: 0x98
	scePrintf("termAll - UNIMPLEMENTED!\n");
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

/*// 
// Start address: 0x2ed0b0
int videoDecDelete(_anon17* vd)
{
	// Line 1424, Address: 0x2ed0b0, Func Offset: 0
	// Line 1426, Address: 0x2ed0c0, Func Offset: 0x10
	// Line 1428, Address: 0x2ed0c8, Func Offset: 0x18
	// Line 1431, Address: 0x2ed0d0, Func Offset: 0x20
	// Line 1430, Address: 0x2ed0d8, Func Offset: 0x28
	// Line 1431, Address: 0x2ed0dc, Func Offset: 0x2c
	// Func End, Address: 0x2ed0e4, Func Offset: 0x34
}

// 
// Start address: 0x2ed0f0
int audioDecDelete()
{
	// Line 1436, Address: 0x2ed0f0, Func Offset: 0
	// Line 1438, Address: 0x2ed0f8, Func Offset: 0x8
	// Line 1440, Address: 0x2ed100, Func Offset: 0x10
	// Line 1439, Address: 0x2ed104, Func Offset: 0x14
	// Line 1440, Address: 0x2ed108, Func Offset: 0x18
	// Func End, Address: 0x2ed110, Func Offset: 0x20
}*/

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

// 
// Start address: 0x2ed2e0
void OutPutCdErrorCode(unsigned int* err)
{
	// Line 1499, Address: 0x2ed2e0, Func Offset: 0
	// Line 1500, Address: 0x2ed2f0, Func Offset: 0x10
	// Line 1505, Address: 0x2ed358, Func Offset: 0x78
	// Line 1506, Address: 0x2ed364, Func Offset: 0x84
	// Line 1508, Address: 0x2ed36c, Func Offset: 0x8c
	// Line 1509, Address: 0x2ed378, Func Offset: 0x98
	// Line 1511, Address: 0x2ed380, Func Offset: 0xa0
	// Line 1512, Address: 0x2ed38c, Func Offset: 0xac
	// Line 1514, Address: 0x2ed394, Func Offset: 0xb4
	// Line 1515, Address: 0x2ed3a0, Func Offset: 0xc0
	// Line 1517, Address: 0x2ed3a8, Func Offset: 0xc8
	// Line 1518, Address: 0x2ed3b4, Func Offset: 0xd4
	// Line 1520, Address: 0x2ed3bc, Func Offset: 0xdc
	// Line 1521, Address: 0x2ed3c8, Func Offset: 0xe8
	// Line 1523, Address: 0x2ed3d0, Func Offset: 0xf0
	// Line 1524, Address: 0x2ed3dc, Func Offset: 0xfc
	// Line 1526, Address: 0x2ed3e4, Func Offset: 0x104
	// Line 1529, Address: 0x2ed3f0, Func Offset: 0x110
	// Line 1531, Address: 0x2ed408, Func Offset: 0x128
	// Line 1539, Address: 0x2ed414, Func Offset: 0x134
	// Func End, Address: 0x2ed424, Func Offset: 0x144
	scePrintf("OutPutCdErrorCode - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ed430
int videoCallback(sceMpeg *mp, sceMpegCbDataStr *str, void *data)
{
	int len;
	int d1;
	int d0;
	unsigned char* pd1Unc;
	unsigned char* pd0Unc;
	unsigned char* pd1;
	unsigned char* pd0;
	int s1;
	int s0;
	unsigned char* ps0;
	//_anon16* rb;
	// Line 1551, Address: 0x2ed430, Func Offset: 0
	// Line 1555, Address: 0x2ed450, Func Offset: 0x20
	// Line 1553, Address: 0x2ed454, Func Offset: 0x24
	// Line 1555, Address: 0x2ed458, Func Offset: 0x28
	// Line 1552, Address: 0x2ed460, Func Offset: 0x30
	// Line 1555, Address: 0x2ed464, Func Offset: 0x34
	// Line 1556, Address: 0x2ed474, Func Offset: 0x44
	// Line 1565, Address: 0x2ed478, Func Offset: 0x48
	// Line 1567, Address: 0x2ed498, Func Offset: 0x68
	// Line 1568, Address: 0x2ed4a0, Func Offset: 0x70
	// Line 1570, Address: 0x2ed4ac, Func Offset: 0x7c
	// Line 1573, Address: 0x2ed4d4, Func Offset: 0xa4
	// Line 1574, Address: 0x2ed4dc, Func Offset: 0xac
	// Line 1575, Address: 0x2ed500, Func Offset: 0xd0
	// Line 1578, Address: 0x2ed50c, Func Offset: 0xdc
	// Line 1584, Address: 0x2ed51c, Func Offset: 0xec
	// Line 1585, Address: 0x2ed528, Func Offset: 0xf8
	// Func End, Address: 0x2ed54c, Func Offset: 0x11c
}

// 
// Start address: 0x2ed550
int pcmCallback(sceMpeg *mp, sceMpegCbDataStr *str, void *data)
{
	int hdr_add;
	int ret;
	unsigned int len;
	int d1;
	int d0;
	unsigned char* pd1;
	unsigned char* pd0;
	int s0;
	unsigned char* ps0;
	//_anon16* rb;
	// Line 1594, Address: 0x2ed550, Func Offset: 0
	// Line 1607, Address: 0x2ed568, Func Offset: 0x18
	// Line 1608, Address: 0x2ed56c, Func Offset: 0x1c
	// Line 1607, Address: 0x2ed570, Func Offset: 0x20
	// Line 1608, Address: 0x2ed574, Func Offset: 0x24
	// Line 1609, Address: 0x2ed584, Func Offset: 0x34
	// Line 1611, Address: 0x2ed588, Func Offset: 0x38
	// Line 1614, Address: 0x2ed58c, Func Offset: 0x3c
	// Line 1611, Address: 0x2ed590, Func Offset: 0x40
	// Line 1614, Address: 0x2ed594, Func Offset: 0x44
	// Line 1617, Address: 0x2ed5a4, Func Offset: 0x54
	// Line 1618, Address: 0x2ed5c0, Func Offset: 0x70
	// Line 1620, Address: 0x2ed5e4, Func Offset: 0x94
	// Line 1621, Address: 0x2ed5f4, Func Offset: 0xa4
	// Line 1623, Address: 0x2ed60c, Func Offset: 0xbc
	// Line 1625, Address: 0x2ed620, Func Offset: 0xd0
	// Line 1626, Address: 0x2ed634, Func Offset: 0xe4
	// Line 1629, Address: 0x2ed640, Func Offset: 0xf0
	// Line 1628, Address: 0x2ed648, Func Offset: 0xf8
	// Line 1629, Address: 0x2ed64c, Func Offset: 0xfc
	// Line 1630, Address: 0x2ed670, Func Offset: 0x120
	// Line 1631, Address: 0x2ed684, Func Offset: 0x134
	// Line 1632, Address: 0x2ed694, Func Offset: 0x144
	// Line 1633, Address: 0x2ed698, Func Offset: 0x148
	// Line 1635, Address: 0x2ed6a0, Func Offset: 0x150
	// Line 1636, Address: 0x2ed6c8, Func Offset: 0x178
	// Line 1637, Address: 0x2ed6dc, Func Offset: 0x18c
	// Line 1644, Address: 0x2ed6f0, Func Offset: 0x1a0
	// Line 1645, Address: 0x2ed6fc, Func Offset: 0x1ac
	// Func End, Address: 0x2ed718, Func Offset: 0x1c8
}

// 100% matching!
int mpegError(sceMpeg *mp, sceMpegCbDataError *cberror, void *anyData)
{
    printf("%s\n", cberror->errMessage);
    
    return 1;
}

// 
// Start address: 0x2ed750
int mpegNodata(sceMpeg *mp, sceMpegCbData *cbdata, void *anyData)
{
	int read_n;
	int read_start;
	int consume;
	int isNewData;
	unsigned int d4chcr;
	int last;
	int index;
	int i;
	// Line 1664, Address: 0x2ed750, Func Offset: 0
	// Line 1675, Address: 0x2ed76c, Func Offset: 0x1c
	// Line 1677, Address: 0x2ed774, Func Offset: 0x24
	// Line 1679, Address: 0x2ed780, Func Offset: 0x30
	// Line 1680, Address: 0x2ed790, Func Offset: 0x40
	// Line 1681, Address: 0x2ed79c, Func Offset: 0x4c
	// Line 1693, Address: 0x2ed7a4, Func Offset: 0x54
	// Line 1694, Address: 0x2ed7b0, Func Offset: 0x60
	// Line 1700, Address: 0x2ed7b8, Func Offset: 0x68
	// Line 1701, Address: 0x2ed7cc, Func Offset: 0x7c
	// Line 1702, Address: 0x2ed7f4, Func Offset: 0xa4
	// Line 1703, Address: 0x2ed810, Func Offset: 0xc0
	// Line 1709, Address: 0x2ed824, Func Offset: 0xd4
	// Line 1710, Address: 0x2ed84c, Func Offset: 0xfc
	// Line 1709, Address: 0x2ed854, Func Offset: 0x104
	// Line 1710, Address: 0x2ed858, Func Offset: 0x108
	// Line 1711, Address: 0x2ed85c, Func Offset: 0x10c
	// Line 1717, Address: 0x2ed874, Func Offset: 0x124
	// Line 1718, Address: 0x2ed87c, Func Offset: 0x12c
	// Line 1719, Address: 0x2ed8ac, Func Offset: 0x15c
	// Line 1718, Address: 0x2ed8b4, Func Offset: 0x164
	// Line 1719, Address: 0x2ed8b8, Func Offset: 0x168
	// Line 1725, Address: 0x2ed8dc, Func Offset: 0x18c
	// Line 1729, Address: 0x2ed8e0, Func Offset: 0x190
	// Line 1731, Address: 0x2ed8ec, Func Offset: 0x19c
	// Line 1737, Address: 0x2ed928, Func Offset: 0x1d8
	// Line 1738, Address: 0x2ed940, Func Offset: 0x1f0
	// Line 1737, Address: 0x2ed944, Func Offset: 0x1f4
	// Line 1738, Address: 0x2ed948, Func Offset: 0x1f8
	// Line 1740, Address: 0x2ed958, Func Offset: 0x208
	// Line 1746, Address: 0x2ed96c, Func Offset: 0x21c
	// Line 1747, Address: 0x2ed97c, Func Offset: 0x22c
	// Line 1748, Address: 0x2ed984, Func Offset: 0x234
	// Line 1750, Address: 0x2ed994, Func Offset: 0x244
	// Line 1753, Address: 0x2ed9a0, Func Offset: 0x250
	// Line 1755, Address: 0x2ed9ac, Func Offset: 0x25c
	// Line 1756, Address: 0x2ed9b0, Func Offset: 0x260
	// Func End, Address: 0x2ed9d0, Func Offset: 0x280
}

// 
// Start address: 0x2ed9d0
int mpegStopDMA(sceMpeg *mp, sceMpegCbData *cbdata, void *anyData)
{
	// Line 1763, Address: 0x2ed9d0, Func Offset: 0
	// Line 1764, Address: 0x2ed9d8, Func Offset: 0x8
	// Line 1768, Address: 0x2ed9e4, Func Offset: 0x14
	// Line 1766, Address: 0x2ed9e8, Func Offset: 0x18
	// Line 1768, Address: 0x2ed9ec, Func Offset: 0x1c
	// Line 1770, Address: 0x2ed9f4, Func Offset: 0x24
	// Line 1771, Address: 0x2eda04, Func Offset: 0x34
	// Line 1772, Address: 0x2eda14, Func Offset: 0x44
	// Line 1773, Address: 0x2eda24, Func Offset: 0x54
	// Line 1777, Address: 0x2eda34, Func Offset: 0x64
	// Line 1780, Address: 0x2eda50, Func Offset: 0x80
	// Line 1781, Address: 0x2eda58, Func Offset: 0x88
	// Line 1782, Address: 0x2eda68, Func Offset: 0x98
	// Line 1783, Address: 0x2eda78, Func Offset: 0xa8
	// Line 1785, Address: 0x2eda88, Func Offset: 0xb8
	// Line 1786, Address: 0x2eda98, Func Offset: 0xc8
	// Line 1788, Address: 0x2edaa8, Func Offset: 0xd8
	// Line 1791, Address: 0x2edab4, Func Offset: 0xe4
	// Line 1790, Address: 0x2edab8, Func Offset: 0xe8
	// Line 1791, Address: 0x2edabc, Func Offset: 0xec
	// Func End, Address: 0x2edac4, Func Offset: 0xf4
}

// 
// Start address: 0x2edad0
int mpegRestartDMA(sceMpeg *mp, sceMpegCbData *cbdata, void *anyData)
{
	int id;
	int index_next;
	int index;
	unsigned int d4chcr_next;
	unsigned int d4tadr_next;
	unsigned int d4qwc_next;
	unsigned int d4madr_next;
	int ifc;
	int fp;
	unsigned int bp;
	// Line 1797, Address: 0x2edad0, Func Offset: 0
	// Line 1798, Address: 0x2edaf4, Func Offset: 0x24
	// Line 1801, Address: 0x2edafc, Func Offset: 0x2c
	// Line 1799, Address: 0x2edb04, Func Offset: 0x34
	// Line 1800, Address: 0x2edb0c, Func Offset: 0x3c
	// Line 1801, Address: 0x2edb14, Func Offset: 0x44
	// Line 1802, Address: 0x2edb18, Func Offset: 0x48
	// Line 1798, Address: 0x2edb20, Func Offset: 0x50
	// Line 1803, Address: 0x2edb24, Func Offset: 0x54
	// Line 1802, Address: 0x2edb2c, Func Offset: 0x5c
	// Line 1801, Address: 0x2edb30, Func Offset: 0x60
	// Line 1804, Address: 0x2edb38, Func Offset: 0x68
	// Line 1809, Address: 0x2edb40, Func Offset: 0x70
	// Line 1814, Address: 0x2edb50, Func Offset: 0x80
	// Line 1815, Address: 0x2edb64, Func Offset: 0x94
	// Line 1816, Address: 0x2edb6c, Func Offset: 0x9c
	// Line 1817, Address: 0x2edb74, Func Offset: 0xa4
	// Line 1816, Address: 0x2edb7c, Func Offset: 0xac
	// Line 1817, Address: 0x2edb80, Func Offset: 0xb0
	// Line 1818, Address: 0x2edb88, Func Offset: 0xb8
	// Line 1822, Address: 0x2edbc0, Func Offset: 0xf0
	// Line 1818, Address: 0x2edbc8, Func Offset: 0xf8
	// Line 1822, Address: 0x2edbd4, Func Offset: 0x104
	// Line 1825, Address: 0x2edbd8, Func Offset: 0x108
	// Line 1822, Address: 0x2edbe0, Func Offset: 0x110
	// Line 1825, Address: 0x2edbf0, Func Offset: 0x120
	// Line 1826, Address: 0x2edc2c, Func Offset: 0x15c
	// Line 1827, Address: 0x2edc38, Func Offset: 0x168
	// Line 1829, Address: 0x2edc48, Func Offset: 0x178
	// Line 1831, Address: 0x2edc80, Func Offset: 0x1b0
	// Line 1832, Address: 0x2edc94, Func Offset: 0x1c4
	// Line 1831, Address: 0x2edca0, Func Offset: 0x1d0
	// Line 1833, Address: 0x2edca4, Func Offset: 0x1d4
	// Line 1832, Address: 0x2edcac, Func Offset: 0x1dc
	// Line 1833, Address: 0x2edcb8, Func Offset: 0x1e8
	// Line 1837, Address: 0x2edd00, Func Offset: 0x230
	// Line 1833, Address: 0x2edd08, Func Offset: 0x238
	// Line 1837, Address: 0x2edd24, Func Offset: 0x254
	// Line 1840, Address: 0x2edd38, Func Offset: 0x268
	// Line 1841, Address: 0x2edd68, Func Offset: 0x298
	// Line 1842, Address: 0x2edd70, Func Offset: 0x2a0
	// Line 1847, Address: 0x2edd84, Func Offset: 0x2b4
	// Line 1848, Address: 0x2edda4, Func Offset: 0x2d4
	// Line 1849, Address: 0x2eddac, Func Offset: 0x2dc
	// Line 1850, Address: 0x2eddbc, Func Offset: 0x2ec
	// Line 1853, Address: 0x2eddcc, Func Offset: 0x2fc
	// Line 1855, Address: 0x2edddc, Func Offset: 0x30c
	// Line 1857, Address: 0x2eddf8, Func Offset: 0x328
	// Line 1859, Address: 0x2ede00, Func Offset: 0x330
	// Line 1860, Address: 0x2ede1c, Func Offset: 0x34c
	// Line 1863, Address: 0x2ede20, Func Offset: 0x350
	// Line 1864, Address: 0x2ede28, Func Offset: 0x358
	// Line 1865, Address: 0x2ede30, Func Offset: 0x360
	// Line 1866, Address: 0x2ede38, Func Offset: 0x368
	// Line 1867, Address: 0x2ede48, Func Offset: 0x378
	// Line 1869, Address: 0x2ede50, Func Offset: 0x380
	// Line 1871, Address: 0x2ede58, Func Offset: 0x388
	// Line 1869, Address: 0x2ede5c, Func Offset: 0x38c
	// Line 1871, Address: 0x2ede64, Func Offset: 0x394
	// Line 1873, Address: 0x2ede6c, Func Offset: 0x39c
	// Line 1876, Address: 0x2ede78, Func Offset: 0x3a8
	// Line 1875, Address: 0x2ede98, Func Offset: 0x3c8
	// Line 1876, Address: 0x2ede9c, Func Offset: 0x3cc
	// Func End, Address: 0x2edea4, Func Offset: 0x3d4
}

// 
// Start address: 0x2edeb0
int mpegTS(sceMpeg *mp, sceMpegCbDataTimeStamp *cbts, void *anyData)
{
	int rd;
	int i;
	int tscount;
	int isEnd;
	int datasize;
	unsigned int stop;
	int ifc;
	int fp;
	int bp;
	unsigned int ipubp;
	unsigned int d4madr;
	// Line 1884, Address: 0x2edeb0, Func Offset: 0
	// Line 1886, Address: 0x2ededc, Func Offset: 0x2c
	// Line 1894, Address: 0x2edee8, Func Offset: 0x38
	// Line 1887, Address: 0x2edeec, Func Offset: 0x3c
	// Line 1888, Address: 0x2edef4, Func Offset: 0x44
	// Line 1889, Address: 0x2edefc, Func Offset: 0x4c
	// Line 1890, Address: 0x2edf04, Func Offset: 0x54
	// Line 1893, Address: 0x2edf0c, Func Offset: 0x5c
	// Line 1888, Address: 0x2edf14, Func Offset: 0x64
	// Line 1899, Address: 0x2edf18, Func Offset: 0x68
	// Line 1904, Address: 0x2edf28, Func Offset: 0x78
	// Line 1901, Address: 0x2edf48, Func Offset: 0x98
	// Line 1902, Address: 0x2edf4c, Func Offset: 0x9c
	// Line 1904, Address: 0x2edf50, Func Offset: 0xa0
	// Line 1906, Address: 0x2edf60, Func Offset: 0xb0
	// Line 1904, Address: 0x2edf68, Func Offset: 0xb8
	// Line 1909, Address: 0x2edf6c, Func Offset: 0xbc
	// Line 1911, Address: 0x2edf80, Func Offset: 0xd0
	// Line 1913, Address: 0x2edfa0, Func Offset: 0xf0
	// Line 1916, Address: 0x2edfd4, Func Offset: 0x124
	// Line 1918, Address: 0x2edfdc, Func Offset: 0x12c
	// Line 1916, Address: 0x2edfe0, Func Offset: 0x130
	// Line 1917, Address: 0x2edfe8, Func Offset: 0x138
	// Line 1919, Address: 0x2edfec, Func Offset: 0x13c
	// Line 1918, Address: 0x2edff0, Func Offset: 0x140
	// Line 1919, Address: 0x2edff4, Func Offset: 0x144
	// Line 1922, Address: 0x2ee000, Func Offset: 0x150
	// Line 1924, Address: 0x2ee030, Func Offset: 0x180
	// Line 1926, Address: 0x2ee050, Func Offset: 0x1a0
	// Line 1928, Address: 0x2ee05c, Func Offset: 0x1ac
	// Line 1929, Address: 0x2ee064, Func Offset: 0x1b4
	// Line 1931, Address: 0x2ee068, Func Offset: 0x1b8
	// Line 1930, Address: 0x2ee090, Func Offset: 0x1e0
	// Line 1931, Address: 0x2ee094, Func Offset: 0x1e4
	// Func End, Address: 0x2ee09c, Func Offset: 0x1ec
}
