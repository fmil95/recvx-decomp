#include "system.h"

unsigned short pause_mes[6];
unsigned char FileWait;
unsigned char VibWait;
System* sys;
unsigned char* njpmemp;
Unknown19* hws;
VertexBuffer* _nj_vertex_buf_;
unsigned char* vwbmemp;
unsigned char* vebmemp;
unsigned char* freemem;
unsigned char PauseBtn;
unsigned char NowLoadDisp;
unsigned char Pause_Flag;
unsigned char pl_sleep_cnt;
BH_PWORK* plp;
BH_PWORK ply;
unsigned char* keepmem;
float BHD_ASPECT_Y;
float BHD_ASPECT_X;
unsigned char BackColorFlag;
_anon16 Ps2_pad;
int pd_port;
_anon22* rom;
_anon25 tbuf[0];
int SoftResetFlag;
float GameFar;
float GameNear;
_anon20 Pad_act[0];
unsigned int Ps2_rendertex_initflag;
unsigned int Ps2_albinoid_flag;
unsigned int Ps2_ice_flag;
_anon30 WpnTab[0];
float FontScaleCR;
float FontScaleX;
unsigned char FontSz[0];

/* 100% match */
int bhCalcVtxBuffer() { // Line 343, Address: 0x131b90
    return 0;
}

/* 100% match */
void bhChangeHWSetting() { // Line 350, Address: 0x131ba0
    sys->ss_flg ^= 2; // Line 351, Address: 0x131ba8, 0x131bb8
    if (sys->ss_flg & 2) { // Line 352, Address: 0x131bb4, 0x131bc0

        sys->fog_cngct = 3; // Line 354, Address: 0x131bd4
        hws->vtx_opq_a = 0x90000; // Line 355, Address: 0x131be4, 0x131bfc
        hws->vtx_opq_b = 0x4000; // Line 356, Address: 0x131bf0, 0x131c00
        hws->vtx_trs_a = 0x30000; // Line 357, Address: 0x131bf4, 0x131c0c
        hws->vtx_trs_b = 0x4000; // Line 358, Address: 0x131c18
        hws->vtx_punch = 0x3f00; // Line 359, Address: 0x131bf8, 0x131c24
    } // Line 360, Address: 0x131c2c
    else {
        sys->fog_cngct = 2; // Line 362, Address: 0x131c34
        hws->vtx_opq_a = -0x90000; // Line 363, Address: 0x131c44, 0x131c5c
        hws->vtx_opq_b = 0x8000; // Line 364, Address: 0x131c50, 0x131c60
        hws->vtx_trs_a = 0x50000; // Line 365, Address: 0x131c54, 0x131c6c
        hws->vtx_trs_b = 0x8000; // Line 366, Address: 0x131c78
        hws->vtx_punch = 0x7f00; // Line 367, Address: 0x131c58, 0x131c84
    }
    hws->vtx_total = bhCalcVtxBuffer(); // Line 369, Address: 0x131c90, 0x131ca4

    njpmemp = &freemem[0xbb0000 - hws->vtx_total]; // Line 371, Address: 0x131ca0, 0x131ca8
    npPlusInit(); // Line 372, Address: 0x131cc8

    vwbmemp = &freemem[0xbf0000 - hws->vtx_total]; // Line 374, Address: 0x131cd0, 0x131ce0, 0x131cf4

    vebmemp = &freemem[0xc40000 - hws->vtx_total]; // Line 376, Address: 0x131cdc, 0x131d04





    if (sys->gm_flg & 1) { // Line 382, Address: 0x131cec, 0x131d18
        njWaitVSync(); // Line 383, Address: 0x131d28
        njWaitVSync(); // Line 384, Address: 0x131d30
        njWaitVSync(); // Line 385, Address: 0x131d38
    }

    njChangeSystem(hws->mode, hws->frame, hws->count); // Line 388, Address: 0x131d40

    njSetVertexBuffer((VertexBuffer*)vebmemp, hws->vtx_total); // Line 390, Address: 0x131d58
    njInitVertexBuffer(hws->vtx_opq_a, hws->vtx_opq_b, hws->vtx_trs_a, hws->vtx_trs_b, hws->vtx_punch); // Line 391, Address: 0x131d70




    _nj_vertex_buf_ = (VertexBuffer*)vwbmemp; // Line 396, Address: 0x131d90, 0x131da0


    mwPlySetDispMode(hws->mode, hws->frame, hws->count, hws->vtx_opq_a < 0 ? 2 : hws->vtx_opq_b < 0 ? 2 : hws->vtx_trs_a < 0 ? 2 : hws->vtx_trs_b < 0 ? 2 : hws->vtx_punch < 0 ? 2 : 3); // Line 399, Address: 0x131d98, 0x131da8
    sys->endp = njpmemp; // Line 400, Address: 0x131e20




} // Line 405, Address: 0x131e3c

/* 99.93% match */
void bhInitSystem() { // Line 411, Address: 0x131e50
    unsigned int free;
    unsigned int size;




    
    bhClearVSync(); // Line 419, Address: 0x131e58
    
    sys->ss_flg &= ~0x40440; // Line 421, Address: 0x131e60, 0x131e7c, 0x131e84
    
    npSetMemory((unsigned char*)&sys->tk_flg, 175260, 0); // Line 423, Address: 0x131e70, 0x131e80, 0x131e8c
    sys->memp = freemem; // Line 424, Address: 0x131e98
    sys->endp = njpmemp; // Line 425, Address: 0x131eb4
    
    sys->memp += (int)&sys->save_end - (int)&sys->version; // Line 427, Address: 0x131ed0
    
    TypewriterKeepMemory(); // Line 429, Address: 0x131efc
    keepmem = sys->mempb = sys->memp; // Line 430, Address: 0x131f04, 0x131f18, 0x131f30
    
    sys->loop_ct = 1; // Line 432, Address: 0x131f10, 0x131f44, 0x131f54




    
    sys->p1per = 0; // Line 438, Address: 0x131f60
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    sys->pt_flg |= ~0; // Line 455, Address: 0x131f14, 0x131f74, 0x131f84
    
    sys->sp_flg |= ~0; // Line 457, Address: 0x131f24, 0x131f94, 0x131fa0, 0x131fac


    
    sys->ss_flg &= ~0x300; // Line 461, Address: 0x131f0c, 0x131f28, 0x131fa8, 0x131fb4
    plp = &ply; // Line 462, Address: 0x131fb8
    sys->plp = plp; // Line 463, Address: 0x131fd4


    
    sys->ef_pbnk = 32; // Line 467, Address: 0x131f4c, 0x131fe4
    syMallocStat((unsigned int*)&free, (unsigned int*)&size); // Line 468, Address: 0x131fec, 0x131ffc, 0x132008

    
    sys->fsize = free; // Line 471, Address: 0x131ff4, 0x132000, 0x132010
    
    njClipZ(-2.0f, -20000.0f); // Line 473, Address: 0x13201c
    if ((sys->ss_flg & 0x2)) { // Line 474, Address: 0x132048
        sys->fog_cngct = 3; // Line 475, Address: 0x132058
    } else {

        
        sys->fog_cngct = 2; // Line 479, Address: 0x132068
    }



    
    bhInitVSync(); // Line 485, Address: 0x132060, 0x13206c

    
    pl_sleep_cnt = 0; // Line 488, Address: 0x13207c
    bhFontScaleSet(1.0f, 1.0f, 1.0f); // Line 489, Address: 0x132084
    Pause_Flag = 0; // Line 490, Address: 0x13208c
    
    NowLoadDisp = 0; // Line 492, Address: 0x132094
    PauseBtn = 0;
}

// 
// Start address: 0x1320a0
void bhInitRoomChangeSystem()
{
	int k;
	int j;
	int i;
	// Line 500, Address: 0x1320a0, Func Offset: 0
	// Line 503, Address: 0x1320a8, Func Offset: 0x8
	// Line 519, Address: 0x1320b8, Func Offset: 0x18
	// Line 539, Address: 0x1320c0, Func Offset: 0x20
	// Line 503, Address: 0x1320c4, Func Offset: 0x24
	// Line 517, Address: 0x1320c8, Func Offset: 0x28
	// Line 544, Address: 0x1320cc, Func Offset: 0x2c
	// Line 503, Address: 0x1320d4, Func Offset: 0x34
	// Line 517, Address: 0x1320dc, Func Offset: 0x3c
	// Line 518, Address: 0x1320e4, Func Offset: 0x44
	// Line 519, Address: 0x1320f0, Func Offset: 0x50
	// Line 539, Address: 0x1320fc, Func Offset: 0x5c
	// Line 519, Address: 0x132100, Func Offset: 0x60
	// Line 539, Address: 0x132108, Func Offset: 0x68
	// Line 540, Address: 0x132110, Func Offset: 0x70
	// Line 542, Address: 0x13211c, Func Offset: 0x7c
	// Line 545, Address: 0x13214c, Func Offset: 0xac
	// Line 546, Address: 0x132158, Func Offset: 0xb8
	// Line 547, Address: 0x132160, Func Offset: 0xc0
	// Line 548, Address: 0x132168, Func Offset: 0xc8
	// Line 547, Address: 0x132170, Func Offset: 0xd0
	// Line 548, Address: 0x13217c, Func Offset: 0xdc
	// Line 549, Address: 0x132184, Func Offset: 0xe4
	// Line 550, Address: 0x132194, Func Offset: 0xf4
	// Line 552, Address: 0x1321a4, Func Offset: 0x104
	// Line 553, Address: 0x1321d4, Func Offset: 0x134
	// Line 555, Address: 0x132204, Func Offset: 0x164
	// Line 556, Address: 0x132230, Func Offset: 0x190
	// Line 557, Address: 0x13223c, Func Offset: 0x19c
	// Line 556, Address: 0x132244, Func Offset: 0x1a4
	// Line 557, Address: 0x132264, Func Offset: 0x1c4
	// Line 559, Address: 0x132270, Func Offset: 0x1d0
	// Line 565, Address: 0x132278, Func Offset: 0x1d8
	// Line 568, Address: 0x13227c, Func Offset: 0x1dc
	// Line 571, Address: 0x132280, Func Offset: 0x1e0
	// Line 559, Address: 0x132284, Func Offset: 0x1e4
	// Line 580, Address: 0x132298, Func Offset: 0x1f8
	// Line 581, Address: 0x1322a0, Func Offset: 0x200
	// Line 582, Address: 0x1322a4, Func Offset: 0x204
	// Line 559, Address: 0x1322ac, Func Offset: 0x20c
	// Line 561, Address: 0x1322cc, Func Offset: 0x22c
	// Line 563, Address: 0x13231c, Func Offset: 0x27c
	// Line 564, Address: 0x132330, Func Offset: 0x290
	// Line 565, Address: 0x132344, Func Offset: 0x2a4
	// Line 566, Address: 0x132358, Func Offset: 0x2b8
	// Line 567, Address: 0x13236c, Func Offset: 0x2cc
	// Line 568, Address: 0x132380, Func Offset: 0x2e0
	// Line 569, Address: 0x132394, Func Offset: 0x2f4
	// Line 570, Address: 0x1323a8, Func Offset: 0x308
	// Line 571, Address: 0x1323bc, Func Offset: 0x31c
	// Line 572, Address: 0x1323d0, Func Offset: 0x330
	// Line 573, Address: 0x1323e4, Func Offset: 0x344
	// Line 574, Address: 0x1323f8, Func Offset: 0x358
	// Line 575, Address: 0x13240c, Func Offset: 0x36c
	// Line 576, Address: 0x132420, Func Offset: 0x380
	// Line 577, Address: 0x132434, Func Offset: 0x394
	// Line 578, Address: 0x132448, Func Offset: 0x3a8
	// Line 580, Address: 0x13245c, Func Offset: 0x3bc
	// Line 581, Address: 0x132464, Func Offset: 0x3c4
	// Line 582, Address: 0x132468, Func Offset: 0x3c8
	// Line 584, Address: 0x132470, Func Offset: 0x3d0
	// Line 585, Address: 0x13249c, Func Offset: 0x3fc
	// Line 586, Address: 0x1324ac, Func Offset: 0x40c
	// Func End, Address: 0x1324b8, Func Offset: 0x418
}

/* 100% match */
void bhSysCallInit() { // Line 592, Address: 0x1324c0
    bhInitSystem(); // Line 593, Address: 0x1324c8

    
    sys->tk_flg = 0x300002; // Line 596, Address: 0x1324d0






    
} // Line 604, Address: 0x1324e4

/* 100% match */
void bhSysCallDiscChange() { // Line 610, Address: 0x1324f0
    njFogDisable(); // Line 611, Address: 0x1324f8
    njSetBackColor(0, 0, 0); // Line 612, Address: 0x132500



    if (Adv_ChangeDiscScreen() != 0) { // Line 616, Address: 0x132510
        
        njWaitVSync(); // Line 618, Address: 0x132520
        njSetPaletteMode(2); // Line 619, Address: 0x132528
        sys->tk_flg = sys->dcg_tkbak; // Line 620, Address: 0x132530
        sys->ts_flg = sys->dcg_tsbak; // Line 621, Address: 0x132548
    }













} // Line 636, Address: 0x132560

/* 100% match */
void bhSysCallSoundMuseum() { // Line 642, Address: 0x132570
    njFogDisable(); // Line 643, Address: 0x132578
    njSetBackColor(0, 0, 0); // Line 644, Address: 0x132580
    
    if (Adv_SoundMuseum() != 0) { // Line 646, Address: 0x132590
        
        sys->tk_flg = 0x300008; // Line 648, Address: 0x1325a0
    }



    
} // Line 654, Address: 0x1325b4

/* 100% match */
void bhSysCallWarning() { // Line 660, Address: 0x1325c0
    
    njFogDisable(); // Line 662, Address: 0x1325c8
    njSetBackColor(0, 0, 0); // Line 663, Address: 0x1325d0
    if (Adv_FirstWarningMessage() != 0) { // Line 664, Address: 0x1325e0



        
        sys->tk_flg = 0x300004; // Line 669, Address: 0x1325f0
    }




    
} // Line 676, Address: 0x132604

/* 100% match */
void bhSysCallIpl() { // Line 682, Address: 0x132610
    njFogDisable(); // Line 683, Address: 0x132618
    njSetBackColor(0, 0, 0); // Line 684, Address: 0x132620
    
    if (Adv_CapcomLogo() != 0) { // Line 686, Address: 0x132630
        
        sys->tk_flg = 0x300008; // Line 688, Address: 0x132640
    }



    
} // Line 694, Address: 0x132654

// 
// Start address: 0x132660
void bhSysCallFirstmovie()
{
	// Line 700, Address: 0x132660, Func Offset: 0
	// Line 701, Address: 0x132668, Func Offset: 0x8
	// Line 702, Address: 0x132670, Func Offset: 0x10
	// Line 705, Address: 0x132680, Func Offset: 0x20
	// Line 709, Address: 0x1326b0, Func Offset: 0x50
	// Line 716, Address: 0x1326c0, Func Offset: 0x60
	// Line 709, Address: 0x1326c8, Func Offset: 0x68
	// Line 710, Address: 0x1326cc, Func Offset: 0x6c
	// Line 709, Address: 0x1326d0, Func Offset: 0x70
	// Line 710, Address: 0x1326d8, Func Offset: 0x78
	// Line 712, Address: 0x1326ec, Func Offset: 0x8c
	// Line 716, Address: 0x1326f8, Func Offset: 0x98
	// Line 720, Address: 0x132700, Func Offset: 0xa0
	// Line 723, Address: 0x132708, Func Offset: 0xa8
	// Line 724, Address: 0x132710, Func Offset: 0xb0
	// Line 723, Address: 0x132718, Func Offset: 0xb8
	// Line 724, Address: 0x132720, Func Offset: 0xc0
	// Line 723, Address: 0x132724, Func Offset: 0xc4
	// Line 724, Address: 0x13272c, Func Offset: 0xcc
	// Line 729, Address: 0x132730, Func Offset: 0xd0
	// Line 732, Address: 0x132738, Func Offset: 0xd8
	// Line 733, Address: 0x132740, Func Offset: 0xe0
	// Line 732, Address: 0x132748, Func Offset: 0xe8
	// Line 733, Address: 0x13274c, Func Offset: 0xec
	// Line 732, Address: 0x132750, Func Offset: 0xf0
	// Line 733, Address: 0x132758, Func Offset: 0xf8
	// Line 734, Address: 0x132760, Func Offset: 0x100
	// Line 735, Address: 0x132768, Func Offset: 0x108
	// Line 738, Address: 0x132770, Func Offset: 0x110
	// Line 739, Address: 0x132780, Func Offset: 0x120
	// Line 740, Address: 0x132788, Func Offset: 0x128
	// Line 743, Address: 0x132790, Func Offset: 0x130
	// Line 744, Address: 0x13279c, Func Offset: 0x13c
	// Line 747, Address: 0x1327a4, Func Offset: 0x144
	// Line 748, Address: 0x1327ac, Func Offset: 0x14c
	// Line 747, Address: 0x1327b4, Func Offset: 0x154
	// Line 748, Address: 0x1327bc, Func Offset: 0x15c
	// Line 747, Address: 0x1327c0, Func Offset: 0x160
	// Line 748, Address: 0x1327c8, Func Offset: 0x168
	// Line 762, Address: 0x1327d0, Func Offset: 0x170
	// Func End, Address: 0x1327dc, Func Offset: 0x17c
}

/* 100% match */
void bhSysCallTitle() { // Line 768, Address: 0x1327e0
    njFogDisable(); // Line 769, Address: 0x1327e8
    njSetBackColor(0, 0, 0); // Line 770, Address: 0x1327f0








    
    sys->tk_flg = 0x300020; // Line 780, Address: 0x132800
    
} // Line 782, Address: 0x132814

/* 100% match */
void bhSysCallOpening() { // Line 788, Address: 0x132820
    njFogDisable(); // Line 789, Address: 0x132828
    njSetBackColor(0, 0, 0); // Line 790, Address: 0x132830

    
    bhFirstGameStart(); // Line 793, Address: 0x132840
} // Line 794, Address: 0x132848

// 
// Start address: 0x132860
void bhFirstGameStart()
{
	int hp;
	int i;
	_anon7 scrn;
	// Line 800, Address: 0x132860, Func Offset: 0
	// Line 808, Address: 0x132868, Func Offset: 0x8
	// Line 809, Address: 0x132870, Func Offset: 0x10
	// Line 808, Address: 0x132878, Func Offset: 0x18
	// Line 809, Address: 0x13287c, Func Offset: 0x1c
	// Line 808, Address: 0x132880, Func Offset: 0x20
	// Line 809, Address: 0x132888, Func Offset: 0x28
	// Line 811, Address: 0x132894, Func Offset: 0x34
	// Line 812, Address: 0x13289c, Func Offset: 0x3c
	// Line 813, Address: 0x1328a4, Func Offset: 0x44
	// Line 814, Address: 0x1328ac, Func Offset: 0x4c
	// Line 815, Address: 0x1328b4, Func Offset: 0x54
	// Line 816, Address: 0x1328bc, Func Offset: 0x5c
	// Line 817, Address: 0x1328c4, Func Offset: 0x64
	// Line 818, Address: 0x1328c8, Func Offset: 0x68
	// Line 819, Address: 0x1328d4, Func Offset: 0x74
	// Line 821, Address: 0x1328e4, Func Offset: 0x84
	// Line 820, Address: 0x1328e8, Func Offset: 0x88
	// Line 821, Address: 0x1328f0, Func Offset: 0x90
	// Line 823, Address: 0x1328fc, Func Offset: 0x9c
	// Line 824, Address: 0x132904, Func Offset: 0xa4
	// Line 823, Address: 0x13290c, Func Offset: 0xac
	// Line 824, Address: 0x13291c, Func Offset: 0xbc
	// Line 825, Address: 0x13292c, Func Offset: 0xcc
	// Line 824, Address: 0x132934, Func Offset: 0xd4
	// Line 825, Address: 0x13293c, Func Offset: 0xdc
	// Line 854, Address: 0x13294c, Func Offset: 0xec
	// Line 880, Address: 0x132954, Func Offset: 0xf4
	// Line 891, Address: 0x13295c, Func Offset: 0xfc
	// Line 825, Address: 0x132960, Func Offset: 0x100
	// Line 826, Address: 0x13296c, Func Offset: 0x10c
	// Line 854, Address: 0x13298c, Func Offset: 0x12c
	// Line 880, Address: 0x132998, Func Offset: 0x138
	// Line 854, Address: 0x13299c, Func Offset: 0x13c
	// Line 880, Address: 0x1329a4, Func Offset: 0x144
	// Line 891, Address: 0x1329ac, Func Offset: 0x14c
	// Line 892, Address: 0x1329d0, Func Offset: 0x170
	// Line 893, Address: 0x1329dc, Func Offset: 0x17c
	// Line 892, Address: 0x1329e0, Func Offset: 0x180
	// Line 893, Address: 0x1329e4, Func Offset: 0x184
	// Line 892, Address: 0x1329e8, Func Offset: 0x188
	// Line 893, Address: 0x1329f0, Func Offset: 0x190
	// Line 895, Address: 0x132a00, Func Offset: 0x1a0
	// Line 897, Address: 0x132a08, Func Offset: 0x1a8
	// Line 901, Address: 0x132a10, Func Offset: 0x1b0
	// Line 898, Address: 0x132a14, Func Offset: 0x1b4
	// Line 901, Address: 0x132a18, Func Offset: 0x1b8
	// Line 897, Address: 0x132a1c, Func Offset: 0x1bc
	// Line 898, Address: 0x132a28, Func Offset: 0x1c8
	// Line 899, Address: 0x132a3c, Func Offset: 0x1dc
	// Line 900, Address: 0x132a50, Func Offset: 0x1f0
	// Line 901, Address: 0x132a64, Func Offset: 0x204
	// Line 908, Address: 0x132a7c, Func Offset: 0x21c
	// Line 909, Address: 0x132a94, Func Offset: 0x234
	// Line 910, Address: 0x132a98, Func Offset: 0x238
	// Line 912, Address: 0x132aa4, Func Offset: 0x244
	// Line 911, Address: 0x132aa8, Func Offset: 0x248
	// Line 912, Address: 0x132ab8, Func Offset: 0x258
	// Line 913, Address: 0x132ac0, Func Offset: 0x260
	// Line 912, Address: 0x132ac4, Func Offset: 0x264
	// Line 913, Address: 0x132acc, Func Offset: 0x26c
	// Line 914, Address: 0x132ad8, Func Offset: 0x278
	// Line 913, Address: 0x132adc, Func Offset: 0x27c
	// Line 914, Address: 0x132ae0, Func Offset: 0x280
	// Line 917, Address: 0x132aec, Func Offset: 0x28c
	// Line 918, Address: 0x132b04, Func Offset: 0x2a4
	// Line 919, Address: 0x132b08, Func Offset: 0x2a8
	// Line 920, Address: 0x132b14, Func Offset: 0x2b4
	// Line 921, Address: 0x132b20, Func Offset: 0x2c0
	// Line 922, Address: 0x132b28, Func Offset: 0x2c8
	// Line 923, Address: 0x132b30, Func Offset: 0x2d0
	// Line 924, Address: 0x132b38, Func Offset: 0x2d8
	// Line 926, Address: 0x132b44, Func Offset: 0x2e4
	// Line 924, Address: 0x132b48, Func Offset: 0x2e8
	// Line 925, Address: 0x132b4c, Func Offset: 0x2ec
	// Line 926, Address: 0x132b58, Func Offset: 0x2f8
	// Line 929, Address: 0x132b64, Func Offset: 0x304
	// Func End, Address: 0x132b70, Func Offset: 0x310
}

// 
// Start address: 0x132b70
void bhSysCallPad()
{
	// Line 935, Address: 0x132b70, Func Offset: 0
	// Line 936, Address: 0x132b78, Func Offset: 0x8
	// Line 937, Address: 0x132b94, Func Offset: 0x24
	// Line 938, Address: 0x132b9c, Func Offset: 0x2c
	// Line 941, Address: 0x132bb8, Func Offset: 0x48
	// Line 943, Address: 0x132be0, Func Offset: 0x70
	// Line 946, Address: 0x132bec, Func Offset: 0x7c
	// Line 947, Address: 0x132c24, Func Offset: 0xb4
	// Line 952, Address: 0x132c48, Func Offset: 0xd8
	// Line 1004, Address: 0x132c6c, Func Offset: 0xfc
	// Func End, Address: 0x132c78, Func Offset: 0x108
}

// 
// Start address: 0x132c80
void bhSysCallGame()
{
	// Line 1010, Address: 0x132c80, Func Offset: 0
	// Line 1021, Address: 0x132c88, Func Offset: 0x8
	// Line 1047, Address: 0x132c98, Func Offset: 0x18
	// Line 1044, Address: 0x132c9c, Func Offset: 0x1c
	// Line 1047, Address: 0x132ca0, Func Offset: 0x20
	// Line 1021, Address: 0x132ca4, Func Offset: 0x24
	// Line 1044, Address: 0x132cb0, Func Offset: 0x30
	// Line 1047, Address: 0x132cc4, Func Offset: 0x44
	// Line 1054, Address: 0x132d00, Func Offset: 0x80
	// Line 1055, Address: 0x132d2c, Func Offset: 0xac
	// Line 1059, Address: 0x132d38, Func Offset: 0xb8
	// Line 1064, Address: 0x132d40, Func Offset: 0xc0
	// Line 1066, Address: 0x132d48, Func Offset: 0xc8
	// Line 1160, Address: 0x132d58, Func Offset: 0xd8
	// Line 1066, Address: 0x132d5c, Func Offset: 0xdc
	// Line 1160, Address: 0x132d64, Func Offset: 0xe4
	// Line 1176, Address: 0x132d84, Func Offset: 0x104
	// Func End, Address: 0x132d90, Func Offset: 0x110
}

// 
// Start address: 0x132d90
void bhCheckSubTask()
{
	// Line 1182, Address: 0x132d90, Func Offset: 0
	// Line 1187, Address: 0x132d98, Func Offset: 0x8
	// Line 1196, Address: 0x132dec, Func Offset: 0x5c
	// Line 1198, Address: 0x132e0c, Func Offset: 0x7c
	// Line 1199, Address: 0x132e1c, Func Offset: 0x8c
	// Line 1200, Address: 0x132e20, Func Offset: 0x90
	// Line 1203, Address: 0x132e28, Func Offset: 0x98
	// Line 1204, Address: 0x132e30, Func Offset: 0xa0
	// Line 1202, Address: 0x132e38, Func Offset: 0xa8
	// Line 1200, Address: 0x132e3c, Func Offset: 0xac
	// Line 1201, Address: 0x132e40, Func Offset: 0xb0
	// Line 1204, Address: 0x132e48, Func Offset: 0xb8
	// Line 1201, Address: 0x132e4c, Func Offset: 0xbc
	// Line 1202, Address: 0x132e50, Func Offset: 0xc0
	// Line 1201, Address: 0x132e54, Func Offset: 0xc4
	// Line 1202, Address: 0x132e5c, Func Offset: 0xcc
	// Line 1203, Address: 0x132e64, Func Offset: 0xd4
	// Line 1202, Address: 0x132e68, Func Offset: 0xd8
	// Line 1203, Address: 0x132e70, Func Offset: 0xe0
	// Line 1204, Address: 0x132e7c, Func Offset: 0xec
	// Line 1205, Address: 0x132e84, Func Offset: 0xf4
	// Line 1206, Address: 0x132e88, Func Offset: 0xf8
	// Line 1209, Address: 0x132e90, Func Offset: 0x100
	// Line 1210, Address: 0x132e9c, Func Offset: 0x10c
	// Line 1211, Address: 0x132ea8, Func Offset: 0x118
	// Line 1212, Address: 0x132eb0, Func Offset: 0x120
	// Line 1216, Address: 0x132eb8, Func Offset: 0x128
	// Line 1213, Address: 0x132ec0, Func Offset: 0x130
	// Line 1216, Address: 0x132ec4, Func Offset: 0x134
	// Line 1212, Address: 0x132ec8, Func Offset: 0x138
	// Line 1213, Address: 0x132ed8, Func Offset: 0x148
	// Line 1214, Address: 0x132ef0, Func Offset: 0x160
	// Line 1215, Address: 0x132efc, Func Offset: 0x16c
	// Line 1216, Address: 0x132f0c, Func Offset: 0x17c
	// Line 1217, Address: 0x132f14, Func Offset: 0x184
	// Line 1218, Address: 0x132f18, Func Offset: 0x188
	// Line 1221, Address: 0x132f20, Func Offset: 0x190
	// Line 1233, Address: 0x132f70, Func Offset: 0x1e0
	// Line 1235, Address: 0x132f80, Func Offset: 0x1f0
	// Line 1238, Address: 0x132f8c, Func Offset: 0x1fc
	// Line 1239, Address: 0x132f94, Func Offset: 0x204
	// Line 1243, Address: 0x132f9c, Func Offset: 0x20c
	// Line 1240, Address: 0x132fa4, Func Offset: 0x214
	// Line 1243, Address: 0x132fa8, Func Offset: 0x218
	// Line 1239, Address: 0x132fac, Func Offset: 0x21c
	// Line 1240, Address: 0x132fb0, Func Offset: 0x220
	// Line 1239, Address: 0x132fb4, Func Offset: 0x224
	// Line 1240, Address: 0x132fbc, Func Offset: 0x22c
	// Line 1241, Address: 0x132fd0, Func Offset: 0x240
	// Line 1242, Address: 0x132fdc, Func Offset: 0x24c
	// Line 1243, Address: 0x132fec, Func Offset: 0x25c
	// Line 1244, Address: 0x132ff4, Func Offset: 0x264
	// Line 1245, Address: 0x132ff8, Func Offset: 0x268
	// Line 1251, Address: 0x133000, Func Offset: 0x270
	// Line 1258, Address: 0x133044, Func Offset: 0x2b4
	// Line 1259, Address: 0x13304c, Func Offset: 0x2bc
	// Line 1264, Address: 0x133054, Func Offset: 0x2c4
	// Line 1262, Address: 0x13305c, Func Offset: 0x2cc
	// Line 1263, Address: 0x133060, Func Offset: 0x2d0
	// Line 1259, Address: 0x133064, Func Offset: 0x2d4
	// Line 1260, Address: 0x133070, Func Offset: 0x2e0
	// Line 1264, Address: 0x133078, Func Offset: 0x2e8
	// Line 1260, Address: 0x13307c, Func Offset: 0x2ec
	// Line 1261, Address: 0x133080, Func Offset: 0x2f0
	// Line 1262, Address: 0x13308c, Func Offset: 0x2fc
	// Line 1261, Address: 0x133090, Func Offset: 0x300
	// Line 1262, Address: 0x133098, Func Offset: 0x308
	// Line 1263, Address: 0x1330a0, Func Offset: 0x310
	// Line 1262, Address: 0x1330a4, Func Offset: 0x314
	// Line 1263, Address: 0x1330ac, Func Offset: 0x31c
	// Line 1264, Address: 0x1330b8, Func Offset: 0x328
	// Line 1265, Address: 0x1330c0, Func Offset: 0x330
	// Line 1266, Address: 0x1330c4, Func Offset: 0x334
	// Line 1270, Address: 0x1330cc, Func Offset: 0x33c
	// Line 1279, Address: 0x1330f4, Func Offset: 0x364
	// Line 1280, Address: 0x1330fc, Func Offset: 0x36c
	// Line 1285, Address: 0x133104, Func Offset: 0x374
	// Line 1286, Address: 0x13310c, Func Offset: 0x37c
	// Line 1284, Address: 0x133114, Func Offset: 0x384
	// Line 1280, Address: 0x133118, Func Offset: 0x388
	// Line 1281, Address: 0x133128, Func Offset: 0x398
	// Line 1286, Address: 0x133130, Func Offset: 0x3a0
	// Line 1281, Address: 0x133134, Func Offset: 0x3a4
	// Line 1282, Address: 0x133138, Func Offset: 0x3a8
	// Line 1284, Address: 0x133144, Func Offset: 0x3b4
	// Line 1285, Address: 0x133150, Func Offset: 0x3c0
	// Line 1284, Address: 0x133154, Func Offset: 0x3c4
	// Line 1285, Address: 0x13315c, Func Offset: 0x3cc
	// Line 1286, Address: 0x133168, Func Offset: 0x3d8
	// Line 1288, Address: 0x133170, Func Offset: 0x3e0
	// Line 1290, Address: 0x13318c, Func Offset: 0x3fc
	// Line 1310, Address: 0x133194, Func Offset: 0x404
	// Func End, Address: 0x1331a0, Func Offset: 0x410
}

// 
// Start address: 0x1331a0
void bhSysCallEvent()
{
	unsigned int cb_flg;
	// Line 1316, Address: 0x1331a0, Func Offset: 0
	// Line 1318, Address: 0x1331ac, Func Offset: 0xc
	// Line 1325, Address: 0x1331cc, Func Offset: 0x2c
	// Line 1368, Address: 0x1332ac, Func Offset: 0x10c
	// Line 1370, Address: 0x1332b4, Func Offset: 0x114
	// Line 1377, Address: 0x1332bc, Func Offset: 0x11c
	// Line 1368, Address: 0x1332c0, Func Offset: 0x120
	// Line 1370, Address: 0x1332c8, Func Offset: 0x128
	// Line 1372, Address: 0x1332cc, Func Offset: 0x12c
	// Line 1373, Address: 0x1332e4, Func Offset: 0x144
	// Line 1374, Address: 0x133304, Func Offset: 0x164
	// Line 1375, Address: 0x133324, Func Offset: 0x184
	// Line 1376, Address: 0x133344, Func Offset: 0x1a4
	// Line 1377, Address: 0x133350, Func Offset: 0x1b0
	// Line 1378, Address: 0x133360, Func Offset: 0x1c0
	// Line 1381, Address: 0x133368, Func Offset: 0x1c8
	// Line 1384, Address: 0x13337c, Func Offset: 0x1dc
	// Line 1385, Address: 0x133390, Func Offset: 0x1f0
	// Line 1395, Address: 0x133394, Func Offset: 0x1f4
	// Line 1396, Address: 0x13339c, Func Offset: 0x1fc
	// Line 1399, Address: 0x1333c0, Func Offset: 0x220
	// Line 1409, Address: 0x1333c4, Func Offset: 0x224
	// Line 1399, Address: 0x1333c8, Func Offset: 0x228
	// Line 1400, Address: 0x1333cc, Func Offset: 0x22c
	// Line 1399, Address: 0x1333d0, Func Offset: 0x230
	// Line 1400, Address: 0x1333dc, Func Offset: 0x23c
	// Line 1401, Address: 0x1333f0, Func Offset: 0x250
	// Line 1402, Address: 0x133410, Func Offset: 0x270
	// Line 1403, Address: 0x133430, Func Offset: 0x290
	// Line 1404, Address: 0x133450, Func Offset: 0x2b0
	// Line 1405, Address: 0x133464, Func Offset: 0x2c4
	// Line 1406, Address: 0x133478, Func Offset: 0x2d8
	// Line 1409, Address: 0x13348c, Func Offset: 0x2ec
	// Line 1408, Address: 0x133494, Func Offset: 0x2f4
	// Line 1418, Address: 0x13349c, Func Offset: 0x2fc
	// Line 1419, Address: 0x1334b4, Func Offset: 0x314
	// Line 1420, Address: 0x1334d4, Func Offset: 0x334
	// Line 1423, Address: 0x1334dc, Func Offset: 0x33c
	// Line 1424, Address: 0x1334e4, Func Offset: 0x344
	// Line 1428, Address: 0x1334ec, Func Offset: 0x34c
	// Line 1429, Address: 0x133510, Func Offset: 0x370
	// Line 1430, Address: 0x133520, Func Offset: 0x380
	// Line 1431, Address: 0x133524, Func Offset: 0x384
	// Line 1429, Address: 0x13352c, Func Offset: 0x38c
	// Line 1430, Address: 0x133530, Func Offset: 0x390
	// Line 1429, Address: 0x133534, Func Offset: 0x394
	// Line 1430, Address: 0x13353c, Func Offset: 0x39c
	// Line 1431, Address: 0x133544, Func Offset: 0x3a4
	// Line 1430, Address: 0x133548, Func Offset: 0x3a8
	// Line 1431, Address: 0x133550, Func Offset: 0x3b0
	// Line 1432, Address: 0x133558, Func Offset: 0x3b8
	// Line 1431, Address: 0x13355c, Func Offset: 0x3bc
	// Line 1432, Address: 0x133564, Func Offset: 0x3c4
	// Line 1435, Address: 0x13356c, Func Offset: 0x3cc
	// Line 1436, Address: 0x133590, Func Offset: 0x3f0
	// Line 1439, Address: 0x1335a8, Func Offset: 0x408
	// Line 1440, Address: 0x1335c4, Func Offset: 0x424
	// Line 1449, Address: 0x1335c8, Func Offset: 0x428
	// Line 1441, Address: 0x1335d0, Func Offset: 0x430
	// Line 1447, Address: 0x1335d4, Func Offset: 0x434
	// Line 1440, Address: 0x1335d8, Func Offset: 0x438
	// Line 1441, Address: 0x1335e0, Func Offset: 0x440
	// Line 1461, Address: 0x1335e4, Func Offset: 0x444
	// Line 1451, Address: 0x1335e8, Func Offset: 0x448
	// Line 1461, Address: 0x1335ec, Func Offset: 0x44c
	// Line 1441, Address: 0x1335f0, Func Offset: 0x450
	// Line 1442, Address: 0x1335fc, Func Offset: 0x45c
	// Line 1443, Address: 0x133614, Func Offset: 0x474
	// Line 1447, Address: 0x13362c, Func Offset: 0x48c
	// Line 1449, Address: 0x133638, Func Offset: 0x498
	// Line 1451, Address: 0x133644, Func Offset: 0x4a4
	// Line 1449, Address: 0x133648, Func Offset: 0x4a8
	// Line 1451, Address: 0x133650, Func Offset: 0x4b0
	// Line 1461, Address: 0x133658, Func Offset: 0x4b8
	// Line 1451, Address: 0x13365c, Func Offset: 0x4bc
	// Line 1461, Address: 0x133664, Func Offset: 0x4c4
	// Line 1466, Address: 0x133674, Func Offset: 0x4d4
	// Func End, Address: 0x133684, Func Offset: 0x4e4
}

// 
// Start address: 0x133690
void bhSysCallMap()
{
	int bol;
	int bol;
	// Line 1472, Address: 0x133690, Func Offset: 0
	// Line 1473, Address: 0x13369c, Func Offset: 0xc
	// Line 1476, Address: 0x1336d8, Func Offset: 0x48
	// Line 1477, Address: 0x1336e8, Func Offset: 0x58
	// Line 1478, Address: 0x1336ec, Func Offset: 0x5c
	// Line 1477, Address: 0x1336f0, Func Offset: 0x60
	// Line 1478, Address: 0x1336f8, Func Offset: 0x68
	// Line 1479, Address: 0x133704, Func Offset: 0x74
	// Line 1481, Address: 0x13370c, Func Offset: 0x7c
	// Line 1482, Address: 0x133738, Func Offset: 0xa8
	// Line 1483, Address: 0x133744, Func Offset: 0xb4
	// Line 1485, Address: 0x13374c, Func Offset: 0xbc
	// Line 1487, Address: 0x13376c, Func Offset: 0xdc
	// Line 1491, Address: 0x133774, Func Offset: 0xe4
	// Line 1493, Address: 0x133780, Func Offset: 0xf0
	// Line 1494, Address: 0x1337a0, Func Offset: 0x110
	// Line 1495, Address: 0x1337d0, Func Offset: 0x140
	// Line 1497, Address: 0x1337d8, Func Offset: 0x148
	// Line 1498, Address: 0x1337e0, Func Offset: 0x150
	// Line 1504, Address: 0x133804, Func Offset: 0x174
	// Line 1505, Address: 0x133814, Func Offset: 0x184
	// Line 1509, Address: 0x133818, Func Offset: 0x188
	// Line 1504, Address: 0x13381c, Func Offset: 0x18c
	// Line 1505, Address: 0x133820, Func Offset: 0x190
	// Line 1511, Address: 0x133824, Func Offset: 0x194
	// Line 1504, Address: 0x133828, Func Offset: 0x198
	// Line 1505, Address: 0x133830, Func Offset: 0x1a0
	// Line 1506, Address: 0x133838, Func Offset: 0x1a8
	// Line 1508, Address: 0x133844, Func Offset: 0x1b4
	// Line 1506, Address: 0x133848, Func Offset: 0x1b8
	// Line 1508, Address: 0x133850, Func Offset: 0x1c0
	// Line 1509, Address: 0x133858, Func Offset: 0x1c8
	// Line 1508, Address: 0x13385c, Func Offset: 0x1cc
	// Line 1509, Address: 0x133864, Func Offset: 0x1d4
	// Line 1510, Address: 0x13386c, Func Offset: 0x1dc
	// Line 1509, Address: 0x133870, Func Offset: 0x1e0
	// Line 1510, Address: 0x133878, Func Offset: 0x1e8
	// Line 1511, Address: 0x133880, Func Offset: 0x1f0
	// Line 1510, Address: 0x133884, Func Offset: 0x1f4
	// Line 1511, Address: 0x13388c, Func Offset: 0x1fc
	// Line 1512, Address: 0x13389c, Func Offset: 0x20c
	// Line 1513, Address: 0x1338a8, Func Offset: 0x218
	// Line 1512, Address: 0x1338ac, Func Offset: 0x21c
	// Line 1513, Address: 0x1338b4, Func Offset: 0x224
	// Line 1514, Address: 0x1338d0, Func Offset: 0x240
	// Line 1515, Address: 0x1338f0, Func Offset: 0x260
	// Line 1516, Address: 0x1338f8, Func Offset: 0x268
	// Line 1521, Address: 0x133900, Func Offset: 0x270
	// Line 1523, Address: 0x133908, Func Offset: 0x278
	// Line 1524, Address: 0x133910, Func Offset: 0x280
	// Line 1523, Address: 0x133914, Func Offset: 0x284
	// Line 1524, Address: 0x13391c, Func Offset: 0x28c
	// Line 1525, Address: 0x133924, Func Offset: 0x294
	// Line 1526, Address: 0x13392c, Func Offset: 0x29c
	// Line 1531, Address: 0x133950, Func Offset: 0x2c0
	// Line 1533, Address: 0x13395c, Func Offset: 0x2cc
	// Line 1534, Address: 0x13397c, Func Offset: 0x2ec
	// Line 1535, Address: 0x1339ac, Func Offset: 0x31c
	// Line 1537, Address: 0x1339b4, Func Offset: 0x324
	// Line 1538, Address: 0x1339bc, Func Offset: 0x32c
	// Line 1544, Address: 0x1339e0, Func Offset: 0x350
	// Line 1546, Address: 0x133a00, Func Offset: 0x370
	// Line 1551, Address: 0x133a10, Func Offset: 0x380
	// Line 1546, Address: 0x133a14, Func Offset: 0x384
	// Line 1547, Address: 0x133a18, Func Offset: 0x388
	// Line 1546, Address: 0x133a1c, Func Offset: 0x38c
	// Line 1547, Address: 0x133a24, Func Offset: 0x394
	// Line 1550, Address: 0x133a2c, Func Offset: 0x39c
	// Line 1547, Address: 0x133a30, Func Offset: 0x3a0
	// Line 1550, Address: 0x133a38, Func Offset: 0x3a8
	// Line 1551, Address: 0x133a40, Func Offset: 0x3b0
	// Line 1550, Address: 0x133a44, Func Offset: 0x3b4
	// Line 1551, Address: 0x133a4c, Func Offset: 0x3bc
	// Line 1552, Address: 0x133a54, Func Offset: 0x3c4
	// Line 1551, Address: 0x133a58, Func Offset: 0x3c8
	// Line 1552, Address: 0x133a60, Func Offset: 0x3d0
	// Line 1557, Address: 0x133a70, Func Offset: 0x3e0
	// Line 1558, Address: 0x133a78, Func Offset: 0x3e8
	// Func End, Address: 0x133a88, Func Offset: 0x3f8
}

// 
// Start address: 0x133a90
void bhSysCallItemselect()
{
	// Line 1564, Address: 0x133a90, Func Offset: 0
	// Line 1565, Address: 0x133a98, Func Offset: 0x8
	// Line 1566, Address: 0x133aa0, Func Offset: 0x10
	// Line 1567, Address: 0x133aa8, Func Offset: 0x18
	// Line 1568, Address: 0x133ab0, Func Offset: 0x20
	// Line 1570, Address: 0x133ad8, Func Offset: 0x48
	// Line 1571, Address: 0x133ae0, Func Offset: 0x50
	// Line 1572, Address: 0x133b00, Func Offset: 0x70
	// Line 1573, Address: 0x133b08, Func Offset: 0x78
	// Line 1574, Address: 0x133b20, Func Offset: 0x90
	// Line 1576, Address: 0x133b34, Func Offset: 0xa4
	// Line 1577, Address: 0x133b40, Func Offset: 0xb0
	// Line 1578, Address: 0x133b60, Func Offset: 0xd0
	// Func End, Address: 0x133b6c, Func Offset: 0xdc
}

// 
// Start address: 0x133b70
void bhSysCallDoordemo()
{
	unsigned int argb;
	int code;
	Door* ddp;
	// Line 1584, Address: 0x133b70, Func Offset: 0
	// Line 1586, Address: 0x133b84, Func Offset: 0x14
	// Line 1587, Address: 0x133b98, Func Offset: 0x28
	// Line 1590, Address: 0x133bc4, Func Offset: 0x54
	// Line 1591, Address: 0x133bf0, Func Offset: 0x80
	// Line 1592, Address: 0x133bf4, Func Offset: 0x84
	// Line 1594, Address: 0x133bfc, Func Offset: 0x8c
	// Line 1595, Address: 0x133c04, Func Offset: 0x94
	// Line 1602, Address: 0x133c10, Func Offset: 0xa0
	// Line 1603, Address: 0x133c20, Func Offset: 0xb0
	// Line 1604, Address: 0x133c2c, Func Offset: 0xbc
	// Line 1605, Address: 0x133c34, Func Offset: 0xc4
	// Line 1606, Address: 0x133c3c, Func Offset: 0xcc
	// Line 1610, Address: 0x133c48, Func Offset: 0xd8
	// Line 1611, Address: 0x133c50, Func Offset: 0xe0
	// Line 1620, Address: 0x133c54, Func Offset: 0xe4
	// Line 1623, Address: 0x133c5c, Func Offset: 0xec
	// Line 1625, Address: 0x133c6c, Func Offset: 0xfc
	// Line 1626, Address: 0x133c74, Func Offset: 0x104
	// Line 1627, Address: 0x133c84, Func Offset: 0x114
	// Line 1628, Address: 0x133c8c, Func Offset: 0x11c
	// Line 1629, Address: 0x133c90, Func Offset: 0x120
	// Line 1627, Address: 0x133c94, Func Offset: 0x124
	// Line 1628, Address: 0x133c98, Func Offset: 0x128
	// Line 1627, Address: 0x133c9c, Func Offset: 0x12c
	// Line 1628, Address: 0x133ca4, Func Offset: 0x134
	// Line 1629, Address: 0x133cac, Func Offset: 0x13c
	// Line 1628, Address: 0x133cb0, Func Offset: 0x140
	// Line 1629, Address: 0x133cb8, Func Offset: 0x148
	// Line 1630, Address: 0x133cc8, Func Offset: 0x158
	// Line 1632, Address: 0x133cd0, Func Offset: 0x160
	// Line 1635, Address: 0x133cd8, Func Offset: 0x168
	// Line 1636, Address: 0x133ce8, Func Offset: 0x178
	// Line 1638, Address: 0x133cf0, Func Offset: 0x180
	// Line 1640, Address: 0x133cf8, Func Offset: 0x188
	// Line 1642, Address: 0x133d28, Func Offset: 0x1b8
	// Line 1643, Address: 0x133d30, Func Offset: 0x1c0
	// Line 1647, Address: 0x133d38, Func Offset: 0x1c8
	// Line 1648, Address: 0x133d40, Func Offset: 0x1d0
	// Line 1652, Address: 0x133d4c, Func Offset: 0x1dc
	// Line 1654, Address: 0x133d5c, Func Offset: 0x1ec
	// Line 1655, Address: 0x133d64, Func Offset: 0x1f4
	// Line 1661, Address: 0x133d70, Func Offset: 0x200
	// Line 1662, Address: 0x133d80, Func Offset: 0x210
	// Line 1667, Address: 0x133d88, Func Offset: 0x218
	// Line 1670, Address: 0x133d98, Func Offset: 0x228
	// Line 1674, Address: 0x133da4, Func Offset: 0x234
	// Line 1678, Address: 0x133dfc, Func Offset: 0x28c
	// Line 1681, Address: 0x133e08, Func Offset: 0x298
	// Line 1683, Address: 0x133e10, Func Offset: 0x2a0
	// Line 1685, Address: 0x133e18, Func Offset: 0x2a8
	// Line 1687, Address: 0x133e48, Func Offset: 0x2d8
	// Line 1688, Address: 0x133e58, Func Offset: 0x2e8
	// Line 1689, Address: 0x133e60, Func Offset: 0x2f0
	// Line 1690, Address: 0x133e6c, Func Offset: 0x2fc
	// Line 1689, Address: 0x133e70, Func Offset: 0x300
	// Line 1690, Address: 0x133e74, Func Offset: 0x304
	// Line 1689, Address: 0x133e78, Func Offset: 0x308
	// Line 1690, Address: 0x133e80, Func Offset: 0x310
	// Line 1691, Address: 0x133e90, Func Offset: 0x320
	// Line 1693, Address: 0x133e98, Func Offset: 0x328
	// Line 1696, Address: 0x133ea0, Func Offset: 0x330
	// Line 1697, Address: 0x133eac, Func Offset: 0x33c
	// Line 1696, Address: 0x133eb0, Func Offset: 0x340
	// Line 1697, Address: 0x133eb8, Func Offset: 0x348
	// Line 1719, Address: 0x133ec8, Func Offset: 0x358
	// Func End, Address: 0x133ee0, Func Offset: 0x370
}

// 
// Start address: 0x133ee0
void bhSysCallMovie()
{
	unsigned int sz;
	// Line 1725, Address: 0x133ee0, Func Offset: 0
	// Line 1727, Address: 0x133ee8, Func Offset: 0x8
	// Line 1731, Address: 0x133f24, Func Offset: 0x44
	// Line 1732, Address: 0x133f2c, Func Offset: 0x4c
	// Line 1733, Address: 0x133f3c, Func Offset: 0x5c
	// Line 1734, Address: 0x133f54, Func Offset: 0x74
	// Line 1735, Address: 0x133f64, Func Offset: 0x84
	// Line 1736, Address: 0x133f6c, Func Offset: 0x8c
	// Line 1742, Address: 0x133f80, Func Offset: 0xa0
	// Line 1745, Address: 0x133f9c, Func Offset: 0xbc
	// Line 1742, Address: 0x133fa0, Func Offset: 0xc0
	// Line 1745, Address: 0x133fac, Func Offset: 0xcc
	// Line 1746, Address: 0x133fc8, Func Offset: 0xe8
	// Line 1747, Address: 0x133fe8, Func Offset: 0x108
	// Line 1749, Address: 0x133ff0, Func Offset: 0x110
	// Line 1750, Address: 0x134004, Func Offset: 0x124
	// Line 1751, Address: 0x13400c, Func Offset: 0x12c
	// Line 1753, Address: 0x13401c, Func Offset: 0x13c
	// Line 1754, Address: 0x134030, Func Offset: 0x150
	// Line 1755, Address: 0x13405c, Func Offset: 0x17c
	// Line 1756, Address: 0x13406c, Func Offset: 0x18c
	// Line 1758, Address: 0x13407c, Func Offset: 0x19c
	// Line 1760, Address: 0x134084, Func Offset: 0x1a4
	// Line 1764, Address: 0x1340b4, Func Offset: 0x1d4
	// Line 1765, Address: 0x1340d4, Func Offset: 0x1f4
	// Line 1767, Address: 0x1340dc, Func Offset: 0x1fc
	// Line 1768, Address: 0x1340f0, Func Offset: 0x210
	// Line 1769, Address: 0x1340f8, Func Offset: 0x218
	// Line 1771, Address: 0x134108, Func Offset: 0x228
	// Line 1773, Address: 0x134130, Func Offset: 0x250
	// Line 1774, Address: 0x134150, Func Offset: 0x270
	// Line 1776, Address: 0x134158, Func Offset: 0x278
	// Line 1777, Address: 0x13416c, Func Offset: 0x28c
	// Line 1778, Address: 0x134174, Func Offset: 0x294
	// Line 1780, Address: 0x134184, Func Offset: 0x2a4
	// Line 1782, Address: 0x1341c4, Func Offset: 0x2e4
	// Line 1783, Address: 0x1341cc, Func Offset: 0x2ec
	// Line 1786, Address: 0x1341d0, Func Offset: 0x2f0
	// Line 1782, Address: 0x1341dc, Func Offset: 0x2fc
	// Line 1783, Address: 0x1341e0, Func Offset: 0x300
	// Line 1782, Address: 0x1341e4, Func Offset: 0x304
	// Line 1783, Address: 0x1341ec, Func Offset: 0x30c
	// Line 1784, Address: 0x1341f4, Func Offset: 0x314
	// Line 1783, Address: 0x1341f8, Func Offset: 0x318
	// Line 1784, Address: 0x134200, Func Offset: 0x320
	// Line 1786, Address: 0x13420c, Func Offset: 0x32c
	// Line 1788, Address: 0x134214, Func Offset: 0x334
	// Line 1790, Address: 0x134234, Func Offset: 0x354
	// Line 1792, Address: 0x13423c, Func Offset: 0x35c
	// Line 1793, Address: 0x134248, Func Offset: 0x368
	// Line 1792, Address: 0x13424c, Func Offset: 0x36c
	// Line 1793, Address: 0x134250, Func Offset: 0x370
	// Line 1792, Address: 0x134254, Func Offset: 0x374
	// Line 1793, Address: 0x13425c, Func Offset: 0x37c
	// Line 1794, Address: 0x134268, Func Offset: 0x388
	// Line 1797, Address: 0x134270, Func Offset: 0x390
	// Line 1798, Address: 0x13427c, Func Offset: 0x39c
	// Line 1799, Address: 0x13428c, Func Offset: 0x3ac
	// Line 1800, Address: 0x134294, Func Offset: 0x3b4
	// Line 1801, Address: 0x1342a0, Func Offset: 0x3c0
	// Line 1800, Address: 0x1342a4, Func Offset: 0x3c4
	// Line 1801, Address: 0x1342ac, Func Offset: 0x3cc
	// Line 1802, Address: 0x1342b4, Func Offset: 0x3d4
	// Line 1805, Address: 0x1342cc, Func Offset: 0x3ec
	// Line 1807, Address: 0x1342d4, Func Offset: 0x3f4
	// Line 1808, Address: 0x1342dc, Func Offset: 0x3fc
	// Line 1809, Address: 0x1342ec, Func Offset: 0x40c
	// Line 1810, Address: 0x1342fc, Func Offset: 0x41c
	// Line 1811, Address: 0x13430c, Func Offset: 0x42c
	// Line 1810, Address: 0x134310, Func Offset: 0x430
	// Line 1811, Address: 0x134318, Func Offset: 0x438
	// Line 1813, Address: 0x134334, Func Offset: 0x454
	// Line 1815, Address: 0x13433c, Func Offset: 0x45c
	// Line 1816, Address: 0x134344, Func Offset: 0x464
	// Line 1817, Address: 0x134354, Func Offset: 0x474
	// Line 1819, Address: 0x134370, Func Offset: 0x490
	// Line 1821, Address: 0x13438c, Func Offset: 0x4ac
	// Line 1822, Address: 0x1343ac, Func Offset: 0x4cc
	// Line 1823, Address: 0x1343cc, Func Offset: 0x4ec
	// Line 1825, Address: 0x1343d4, Func Offset: 0x4f4
	// Line 1826, Address: 0x1343e4, Func Offset: 0x504
	// Line 1827, Address: 0x1343f0, Func Offset: 0x510
	// Line 1826, Address: 0x1343f4, Func Offset: 0x514
	// Line 1827, Address: 0x1343fc, Func Offset: 0x51c
	// Line 1828, Address: 0x134418, Func Offset: 0x538
	// Line 1829, Address: 0x134430, Func Offset: 0x550
	// Line 1832, Address: 0x134448, Func Offset: 0x568
	// Func End, Address: 0x134454, Func Offset: 0x574
}

/* 100% match */
void bhSysCallEnding() { // Line 1839, Address: 0x134460
    ControlRanking();
}

/* 100% match */
void bhSysCallGameover() { // Line 1847, Address: 0x134470
    bhControlGameOver();
}

/* 100% match */
void bhSysCallTypewriter() { // Line 1854, Address: 0x134480
    if ((sys->ts_flg & 0x80)) { // Line 1855, Address: 0x134488
        njFogDisable(); // Line 1856, Address: 0x1344a8
    } // Line 1857, Address: 0x1344b0
    ControlTypewriter();
}

// 
// Start address: 0x1344c0
void bhSysCallOption()
{
	// Line 1863, Address: 0x1344c0, Func Offset: 0
	// Line 1865, Address: 0x1344c8, Func Offset: 0x8
	// Line 1866, Address: 0x1344e0, Func Offset: 0x20
	// Line 1868, Address: 0x1344f8, Func Offset: 0x38
	// Line 1869, Address: 0x134508, Func Offset: 0x48
	// Line 1870, Address: 0x134510, Func Offset: 0x50
	// Line 1871, Address: 0x134518, Func Offset: 0x58
	// Line 1879, Address: 0x134530, Func Offset: 0x70
	// Line 1881, Address: 0x134540, Func Offset: 0x80
	// Line 1883, Address: 0x134554, Func Offset: 0x94
	// Line 1884, Address: 0x134560, Func Offset: 0xa0
	// Line 1883, Address: 0x134568, Func Offset: 0xa8
	// Line 1884, Address: 0x134570, Func Offset: 0xb0
	// Line 1885, Address: 0x134574, Func Offset: 0xb4
	// Line 1886, Address: 0x134578, Func Offset: 0xb8
	// Line 1888, Address: 0x13457c, Func Offset: 0xbc
	// Line 1884, Address: 0x134580, Func Offset: 0xc0
	// Line 1885, Address: 0x134584, Func Offset: 0xc4
	// Line 1886, Address: 0x134590, Func Offset: 0xd0
	// Line 1885, Address: 0x134594, Func Offset: 0xd4
	// Line 1886, Address: 0x13459c, Func Offset: 0xdc
	// Line 1887, Address: 0x1345a4, Func Offset: 0xe4
	// Line 1886, Address: 0x1345a8, Func Offset: 0xe8
	// Line 1887, Address: 0x1345b0, Func Offset: 0xf0
	// Line 1888, Address: 0x1345b8, Func Offset: 0xf8
	// Line 1887, Address: 0x1345bc, Func Offset: 0xfc
	// Line 1888, Address: 0x1345c4, Func Offset: 0x104
	// Line 1889, Address: 0x1345d4, Func Offset: 0x114
	// Line 1890, Address: 0x1345e0, Func Offset: 0x120
	// Line 1889, Address: 0x1345e4, Func Offset: 0x124
	// Line 1890, Address: 0x1345ec, Func Offset: 0x12c
	// Line 1891, Address: 0x134608, Func Offset: 0x148
	// Line 1892, Address: 0x134628, Func Offset: 0x168
	// Line 1894, Address: 0x134630, Func Offset: 0x170
	// Line 1896, Address: 0x134644, Func Offset: 0x184
	// Line 1898, Address: 0x13464c, Func Offset: 0x18c
	// Line 1899, Address: 0x13465c, Func Offset: 0x19c
	// Line 1900, Address: 0x134664, Func Offset: 0x1a4
	// Line 1899, Address: 0x134668, Func Offset: 0x1a8
	// Line 1900, Address: 0x13466c, Func Offset: 0x1ac
	// Line 1902, Address: 0x134674, Func Offset: 0x1b4
	// Line 1905, Address: 0x134688, Func Offset: 0x1c8
	// Func End, Address: 0x134694, Func Offset: 0x1d4
}

/* 100% match */
void bhSysCallCompEvent() { // Line 1912, Address: 0x1346a0
    bhControlSpEvtComputer();
}

// 
// Start address: 0x1346b0
void bhSysCallMonitor()
{
	int vibflg;
	int vibnum;
	unsigned int dt;
	unsigned char* datp;
	int sz;
	int i;
	_anon47* rh;
	// Line 1922, Address: 0x1346b0, Func Offset: 0
	// Line 1930, Address: 0x1346c0, Func Offset: 0x10
	// Line 1931, Address: 0x1346fc, Func Offset: 0x4c
	// Line 1932, Address: 0x13471c, Func Offset: 0x6c
	// Line 1934, Address: 0x134734, Func Offset: 0x84
	// Line 1935, Address: 0x134758, Func Offset: 0xa8
	// Line 1943, Address: 0x134794, Func Offset: 0xe4
	// Line 1949, Address: 0x134840, Func Offset: 0x190
	// Line 1952, Address: 0x134854, Func Offset: 0x1a4
	// Line 1949, Address: 0x13485c, Func Offset: 0x1ac
	// Line 1952, Address: 0x134868, Func Offset: 0x1b8
	// Line 1953, Address: 0x13486c, Func Offset: 0x1bc
	// Line 1952, Address: 0x134870, Func Offset: 0x1c0
	// Line 1953, Address: 0x13487c, Func Offset: 0x1cc
	// Line 1954, Address: 0x1348a4, Func Offset: 0x1f4
	// Line 1955, Address: 0x1348ac, Func Offset: 0x1fc
	// Line 1996, Address: 0x1348b4, Func Offset: 0x204
	// Line 1997, Address: 0x1348c4, Func Offset: 0x214
	// Line 1998, Address: 0x1348cc, Func Offset: 0x21c
	// Line 1999, Address: 0x1348ec, Func Offset: 0x23c
	// Line 2001, Address: 0x1348f4, Func Offset: 0x244
	// Line 1999, Address: 0x134900, Func Offset: 0x250
	// Line 2000, Address: 0x134918, Func Offset: 0x268
	// Line 2001, Address: 0x134938, Func Offset: 0x288
	// Line 2002, Address: 0x134948, Func Offset: 0x298
	// Line 2001, Address: 0x13494c, Func Offset: 0x29c
	// Line 2002, Address: 0x134958, Func Offset: 0x2a8
	// Line 2015, Address: 0x134968, Func Offset: 0x2b8
	// Line 2017, Address: 0x134970, Func Offset: 0x2c0
	// Line 2018, Address: 0x134980, Func Offset: 0x2d0
	// Line 2026, Address: 0x134988, Func Offset: 0x2d8
	// Line 2018, Address: 0x13498c, Func Offset: 0x2dc
	// Line 2025, Address: 0x13499c, Func Offset: 0x2ec
	// Line 2019, Address: 0x1349a0, Func Offset: 0x2f0
	// Line 2020, Address: 0x1349a4, Func Offset: 0x2f4
	// Line 2021, Address: 0x1349a8, Func Offset: 0x2f8
	// Line 2022, Address: 0x1349ac, Func Offset: 0x2fc
	// Line 2025, Address: 0x1349b0, Func Offset: 0x300
	// Line 2026, Address: 0x1349c4, Func Offset: 0x314
	// Line 2027, Address: 0x1349d4, Func Offset: 0x324
	// Line 2029, Address: 0x1349dc, Func Offset: 0x32c
	// Line 2030, Address: 0x1349ec, Func Offset: 0x33c
	// Line 2031, Address: 0x134a00, Func Offset: 0x350
	// Line 2036, Address: 0x134a08, Func Offset: 0x358
	// Line 2039, Address: 0x134a24, Func Offset: 0x374
	// Line 2036, Address: 0x134a28, Func Offset: 0x378
	// Line 2039, Address: 0x134a34, Func Offset: 0x384
	// Line 2040, Address: 0x134a50, Func Offset: 0x3a0
	// Line 2042, Address: 0x134a64, Func Offset: 0x3b4
	// Line 2044, Address: 0x134a6c, Func Offset: 0x3bc
	// Line 2045, Address: 0x134a7c, Func Offset: 0x3cc
	// Line 2046, Address: 0x134a84, Func Offset: 0x3d4
	// Line 2047, Address: 0x134a8c, Func Offset: 0x3dc
	// Line 2048, Address: 0x134a94, Func Offset: 0x3e4
	// Line 2049, Address: 0x134a9c, Func Offset: 0x3ec
	// Line 2053, Address: 0x134aa4, Func Offset: 0x3f4
	// Line 2051, Address: 0x134aac, Func Offset: 0x3fc
	// Line 2053, Address: 0x134ab8, Func Offset: 0x408
	// Line 2054, Address: 0x134adc, Func Offset: 0x42c
	// Line 2055, Address: 0x134ae8, Func Offset: 0x438
	// Line 2057, Address: 0x134af0, Func Offset: 0x440
	// Line 2058, Address: 0x134afc, Func Offset: 0x44c
	// Line 2059, Address: 0x134b10, Func Offset: 0x460
	// Line 2062, Address: 0x134b18, Func Offset: 0x468
	// Line 2063, Address: 0x134b28, Func Offset: 0x478
	// Line 2065, Address: 0x134b54, Func Offset: 0x4a4
	// Line 2070, Address: 0x134b5c, Func Offset: 0x4ac
	// Line 2073, Address: 0x134b78, Func Offset: 0x4c8
	// Line 2070, Address: 0x134b7c, Func Offset: 0x4cc
	// Line 2073, Address: 0x134b88, Func Offset: 0x4d8
	// Line 2076, Address: 0x134bbc, Func Offset: 0x50c
	// Line 2078, Address: 0x134bd0, Func Offset: 0x520
	// Line 2080, Address: 0x134bd8, Func Offset: 0x528
	// Line 2081, Address: 0x134be8, Func Offset: 0x538
	// Line 2082, Address: 0x134bf0, Func Offset: 0x540
	// Line 2083, Address: 0x134c04, Func Offset: 0x554
	// Line 2085, Address: 0x134c0c, Func Offset: 0x55c
	// Line 2087, Address: 0x134c38, Func Offset: 0x588
	// Line 2092, Address: 0x134c40, Func Offset: 0x590
	// Line 2095, Address: 0x134c5c, Func Offset: 0x5ac
	// Line 2092, Address: 0x134c60, Func Offset: 0x5b0
	// Line 2095, Address: 0x134c6c, Func Offset: 0x5bc
	// Line 2098, Address: 0x134ca8, Func Offset: 0x5f8
	// Line 2100, Address: 0x134cbc, Func Offset: 0x60c
	// Line 2102, Address: 0x134cc4, Func Offset: 0x614
	// Line 2103, Address: 0x134cd4, Func Offset: 0x624
	// Line 2105, Address: 0x134cdc, Func Offset: 0x62c
	// Line 2109, Address: 0x134d14, Func Offset: 0x664
	// Line 2110, Address: 0x134d28, Func Offset: 0x678
	// Line 2112, Address: 0x134d30, Func Offset: 0x680
	// Line 2114, Address: 0x134d38, Func Offset: 0x688
	// Line 2112, Address: 0x134d40, Func Offset: 0x690
	// Line 2114, Address: 0x134d48, Func Offset: 0x698
	// Line 2116, Address: 0x134d74, Func Offset: 0x6c4
	// Line 2117, Address: 0x134d8c, Func Offset: 0x6dc
	// Line 2118, Address: 0x134d98, Func Offset: 0x6e8
	// Line 2117, Address: 0x134da4, Func Offset: 0x6f4
	// Line 2118, Address: 0x134dac, Func Offset: 0x6fc
	// Line 2119, Address: 0x134db8, Func Offset: 0x708
	// Line 2121, Address: 0x134dc0, Func Offset: 0x710
	// Line 2138, Address: 0x134dd4, Func Offset: 0x724
	// Line 2152, Address: 0x134ddc, Func Offset: 0x72c
	// Line 2153, Address: 0x134e00, Func Offset: 0x750
	// Line 2154, Address: 0x134e10, Func Offset: 0x760
	// Line 2155, Address: 0x134e18, Func Offset: 0x768
	// Line 2156, Address: 0x134e38, Func Offset: 0x788
	// Line 2158, Address: 0x134e40, Func Offset: 0x790
	// Line 2156, Address: 0x134e44, Func Offset: 0x794
	// Line 2157, Address: 0x134e5c, Func Offset: 0x7ac
	// Line 2158, Address: 0x134e80, Func Offset: 0x7d0
	// Line 2161, Address: 0x134e90, Func Offset: 0x7e0
	// Line 2163, Address: 0x134e98, Func Offset: 0x7e8
	// Line 2164, Address: 0x134ea8, Func Offset: 0x7f8
	// Line 2165, Address: 0x134eb0, Func Offset: 0x800
	// Line 2164, Address: 0x134ebc, Func Offset: 0x80c
	// Line 2165, Address: 0x134ec8, Func Offset: 0x818
	// Line 2166, Address: 0x134ed0, Func Offset: 0x820
	// Line 2167, Address: 0x134ed8, Func Offset: 0x828
	// Line 2166, Address: 0x134edc, Func Offset: 0x82c
	// Line 2167, Address: 0x134ef8, Func Offset: 0x848
	// Line 2170, Address: 0x134f08, Func Offset: 0x858
	// Line 2175, Address: 0x134f10, Func Offset: 0x860
	// Line 2180, Address: 0x134f50, Func Offset: 0x8a0
	// Line 2182, Address: 0x134f68, Func Offset: 0x8b8
	// Line 2183, Address: 0x134f7c, Func Offset: 0x8cc
	// Line 2184, Address: 0x134f8c, Func Offset: 0x8dc
	// Line 2186, Address: 0x134f94, Func Offset: 0x8e4
	// Line 2187, Address: 0x134fb0, Func Offset: 0x900
	// Line 2188, Address: 0x134fc0, Func Offset: 0x910
	// Line 2190, Address: 0x134fc8, Func Offset: 0x918
	// Line 2191, Address: 0x134fd8, Func Offset: 0x928
	// Line 2192, Address: 0x134fdc, Func Offset: 0x92c
	// Line 2193, Address: 0x134fe4, Func Offset: 0x934
	// Line 2191, Address: 0x134fe8, Func Offset: 0x938
	// Line 2192, Address: 0x134ff0, Func Offset: 0x940
	// Line 2193, Address: 0x134ff8, Func Offset: 0x948
	// Line 2192, Address: 0x134ffc, Func Offset: 0x94c
	// Line 2193, Address: 0x135004, Func Offset: 0x954
	// Line 2194, Address: 0x13500c, Func Offset: 0x95c
	// Line 2193, Address: 0x135010, Func Offset: 0x960
	// Line 2194, Address: 0x135018, Func Offset: 0x968
	// Line 2195, Address: 0x135038, Func Offset: 0x988
	// Line 2196, Address: 0x135048, Func Offset: 0x998
	// Line 2197, Address: 0x135050, Func Offset: 0x9a0
	// Line 2198, Address: 0x135064, Func Offset: 0x9b4
	// Line 2200, Address: 0x135078, Func Offset: 0x9c8
	// Line 2202, Address: 0x135080, Func Offset: 0x9d0
	// Line 2204, Address: 0x135098, Func Offset: 0x9e8
	// Line 2205, Address: 0x1350a0, Func Offset: 0x9f0
	// Line 2208, Address: 0x1350b4, Func Offset: 0xa04
	// Line 2213, Address: 0x1350bc, Func Offset: 0xa0c
	// Line 2215, Address: 0x1350fc, Func Offset: 0xa4c
	// Line 2216, Address: 0x135110, Func Offset: 0xa60
	// Line 2218, Address: 0x135144, Func Offset: 0xa94
	// Line 2223, Address: 0x13514c, Func Offset: 0xa9c
	// Line 2226, Address: 0x135168, Func Offset: 0xab8
	// Line 2223, Address: 0x13516c, Func Offset: 0xabc
	// Line 2226, Address: 0x135178, Func Offset: 0xac8
	// Line 2229, Address: 0x1351b4, Func Offset: 0xb04
	// Line 2231, Address: 0x1351c8, Func Offset: 0xb18
	// Line 2233, Address: 0x1351d0, Func Offset: 0xb20
	// Line 2234, Address: 0x1351e0, Func Offset: 0xb30
	// Line 2235, Address: 0x1351e8, Func Offset: 0xb38
	// Line 2236, Address: 0x13521c, Func Offset: 0xb6c
	// Line 2237, Address: 0x135230, Func Offset: 0xb80
	// Line 2239, Address: 0x135238, Func Offset: 0xb88
	// Line 2241, Address: 0x135248, Func Offset: 0xb98
	// Line 2244, Address: 0x13525c, Func Offset: 0xbac
	// Line 2249, Address: 0x135264, Func Offset: 0xbb4
	// Line 2250, Address: 0x135278, Func Offset: 0xbc8
	// Line 2253, Address: 0x1352ac, Func Offset: 0xbfc
	// Line 2255, Address: 0x1352b8, Func Offset: 0xc08
	// Line 2253, Address: 0x1352bc, Func Offset: 0xc0c
	// Line 2254, Address: 0x1352c0, Func Offset: 0xc10
	// Line 2255, Address: 0x1352d8, Func Offset: 0xc28
	// Line 2256, Address: 0x1352e4, Func Offset: 0xc34
	// Line 2257, Address: 0x1352ec, Func Offset: 0xc3c
	// Line 2263, Address: 0x1352f4, Func Offset: 0xc44
	// Line 2265, Address: 0x135314, Func Offset: 0xc64
	// Line 2266, Address: 0x135320, Func Offset: 0xc70
	// Line 2270, Address: 0x135334, Func Offset: 0xc84
	// Line 2295, Address: 0x135374, Func Offset: 0xcc4
	// Line 2299, Address: 0x1353a0, Func Offset: 0xcf0
	// Line 2308, Address: 0x1353c4, Func Offset: 0xd14
	// Line 2309, Address: 0x1353e0, Func Offset: 0xd30
	// Line 2310, Address: 0x1353e8, Func Offset: 0xd38
	// Line 2316, Address: 0x1353f0, Func Offset: 0xd40
	// Line 2317, Address: 0x13540c, Func Offset: 0xd5c
	// Line 2316, Address: 0x135410, Func Offset: 0xd60
	// Line 2317, Address: 0x13541c, Func Offset: 0xd6c
	// Line 2320, Address: 0x135440, Func Offset: 0xd90
	// Line 2321, Address: 0x135464, Func Offset: 0xdb4
	// Line 2333, Address: 0x135470, Func Offset: 0xdc0
	// Line 2321, Address: 0x135474, Func Offset: 0xdc4
	// Line 2333, Address: 0x135480, Func Offset: 0xdd0
	// Line 2335, Address: 0x1354c0, Func Offset: 0xe10
	// Line 2336, Address: 0x1354c8, Func Offset: 0xe18
	// Line 2337, Address: 0x1354d0, Func Offset: 0xe20
	// Line 2341, Address: 0x1354d8, Func Offset: 0xe28
	// Line 2342, Address: 0x1354f8, Func Offset: 0xe48
	// Line 2343, Address: 0x135500, Func Offset: 0xe50
	// Line 2344, Address: 0x135524, Func Offset: 0xe74
	// Line 2345, Address: 0x13552c, Func Offset: 0xe7c
	// Line 2346, Address: 0x135534, Func Offset: 0xe84
	// Line 2349, Address: 0x13553c, Func Offset: 0xe8c
	// Line 2350, Address: 0x13555c, Func Offset: 0xeac
	// Line 2351, Address: 0x135560, Func Offset: 0xeb0
	// Line 2352, Address: 0x135568, Func Offset: 0xeb8
	// Line 2355, Address: 0x135570, Func Offset: 0xec0
	// Line 2378, Address: 0x135574, Func Offset: 0xec4
	// Line 2382, Address: 0x135584, Func Offset: 0xed4
	// Line 2384, Address: 0x135588, Func Offset: 0xed8
	// Line 2386, Address: 0x13558c, Func Offset: 0xedc
	// Line 2385, Address: 0x135590, Func Offset: 0xee0
	// Line 2386, Address: 0x13559c, Func Offset: 0xeec
	// Line 2387, Address: 0x1355a4, Func Offset: 0xef4
	// Line 2386, Address: 0x1355a8, Func Offset: 0xef8
	// Line 2388, Address: 0x1355b4, Func Offset: 0xf04
	// Line 2389, Address: 0x1355b8, Func Offset: 0xf08
	// Line 2391, Address: 0x1355c8, Func Offset: 0xf18
	// Line 2394, Address: 0x1355f0, Func Offset: 0xf40
	// Line 2429, Address: 0x135600, Func Offset: 0xf50
	// Line 2431, Address: 0x135608, Func Offset: 0xf58
	// Line 2438, Address: 0x135634, Func Offset: 0xf84
	// Line 2431, Address: 0x135638, Func Offset: 0xf88
	// Line 2437, Address: 0x135644, Func Offset: 0xf94
	// Line 2438, Address: 0x135664, Func Offset: 0xfb4
	// Line 2439, Address: 0x135674, Func Offset: 0xfc4
	// Line 2449, Address: 0x13567c, Func Offset: 0xfcc
	// Line 2450, Address: 0x1356a0, Func Offset: 0xff0
	// Line 2451, Address: 0x1356a8, Func Offset: 0xff8
	// Line 2452, Address: 0x1356d4, Func Offset: 0x1024
	// Line 2453, Address: 0x1356e0, Func Offset: 0x1030
	// Line 2460, Address: 0x1356e8, Func Offset: 0x1038
	// Line 2461, Address: 0x13570c, Func Offset: 0x105c
	// Line 2464, Address: 0x135744, Func Offset: 0x1094
	// Line 2465, Address: 0x135764, Func Offset: 0x10b4
	// Line 2466, Address: 0x13576c, Func Offset: 0x10bc
	// Line 2467, Address: 0x135774, Func Offset: 0x10c4
	// Line 2468, Address: 0x13578c, Func Offset: 0x10dc
	// Line 2476, Address: 0x135798, Func Offset: 0x10e8
	// Line 2468, Address: 0x1357a0, Func Offset: 0x10f0
	// Line 2475, Address: 0x1357a4, Func Offset: 0x10f4
	// Line 2468, Address: 0x1357a8, Func Offset: 0x10f8
	// Line 2475, Address: 0x1357b0, Func Offset: 0x1100
	// Line 2476, Address: 0x1357cc, Func Offset: 0x111c
	// Line 2477, Address: 0x1357d4, Func Offset: 0x1124
	// Line 2478, Address: 0x1357f4, Func Offset: 0x1144
	// Line 2480, Address: 0x135810, Func Offset: 0x1160
	// Line 2482, Address: 0x13581c, Func Offset: 0x116c
	// Line 2489, Address: 0x135824, Func Offset: 0x1174
	// Line 2482, Address: 0x135828, Func Offset: 0x1178
	// Line 2483, Address: 0x135838, Func Offset: 0x1188
	// Line 2484, Address: 0x135850, Func Offset: 0x11a0
	// Line 2485, Address: 0x135868, Func Offset: 0x11b8
	// Line 2486, Address: 0x135880, Func Offset: 0x11d0
	// Line 2487, Address: 0x135894, Func Offset: 0x11e4
	// Line 2486, Address: 0x135898, Func Offset: 0x11e8
	// Line 2487, Address: 0x1358a4, Func Offset: 0x11f4
	// Line 2488, Address: 0x1358b4, Func Offset: 0x1204
	// Line 2487, Address: 0x1358b8, Func Offset: 0x1208
	// Line 2488, Address: 0x1358c8, Func Offset: 0x1218
	// Line 2489, Address: 0x1358dc, Func Offset: 0x122c
	// Line 2490, Address: 0x1358ec, Func Offset: 0x123c
	// Line 2491, Address: 0x1358f4, Func Offset: 0x1244
	// Line 2493, Address: 0x135900, Func Offset: 0x1250
	// Line 2495, Address: 0x135908, Func Offset: 0x1258
	// Line 2496, Address: 0x13591c, Func Offset: 0x126c
	// Line 2498, Address: 0x135948, Func Offset: 0x1298
	// Line 2503, Address: 0x135950, Func Offset: 0x12a0
	// Line 2506, Address: 0x13596c, Func Offset: 0x12bc
	// Line 2503, Address: 0x135970, Func Offset: 0x12c0
	// Line 2506, Address: 0x13597c, Func Offset: 0x12cc
	// Line 2509, Address: 0x1359b0, Func Offset: 0x1300
	// Line 2511, Address: 0x1359c4, Func Offset: 0x1314
	// Line 2513, Address: 0x1359cc, Func Offset: 0x131c
	// Line 2514, Address: 0x1359dc, Func Offset: 0x132c
	// Line 2515, Address: 0x1359e4, Func Offset: 0x1334
	// Line 2516, Address: 0x1359ec, Func Offset: 0x133c
	// Line 2517, Address: 0x1359f4, Func Offset: 0x1344
	// Line 2518, Address: 0x1359fc, Func Offset: 0x134c
	// Line 2517, Address: 0x135a00, Func Offset: 0x1350
	// Line 2518, Address: 0x135a1c, Func Offset: 0x136c
	// Line 2519, Address: 0x135a2c, Func Offset: 0x137c
	// Line 2521, Address: 0x135a34, Func Offset: 0x1384
	// Line 2522, Address: 0x135a48, Func Offset: 0x1398
	// Line 2521, Address: 0x135a4c, Func Offset: 0x139c
	// Line 2522, Address: 0x135a50, Func Offset: 0x13a0
	// Line 2524, Address: 0x135a80, Func Offset: 0x13d0
	// Line 2529, Address: 0x135a88, Func Offset: 0x13d8
	// Line 2532, Address: 0x135aa4, Func Offset: 0x13f4
	// Line 2529, Address: 0x135aa8, Func Offset: 0x13f8
	// Line 2532, Address: 0x135ab4, Func Offset: 0x1404
	// Line 2535, Address: 0x135af0, Func Offset: 0x1440
	// Line 2537, Address: 0x135b04, Func Offset: 0x1454
	// Line 2539, Address: 0x135b0c, Func Offset: 0x145c
	// Line 2540, Address: 0x135b1c, Func Offset: 0x146c
	// Line 2541, Address: 0x135b24, Func Offset: 0x1474
	// Line 2542, Address: 0x135b2c, Func Offset: 0x147c
	// Line 2541, Address: 0x135b30, Func Offset: 0x1480
	// Line 2542, Address: 0x135b4c, Func Offset: 0x149c
	// Line 2543, Address: 0x135b5c, Func Offset: 0x14ac
	// Line 2545, Address: 0x135b64, Func Offset: 0x14b4
	// Line 2546, Address: 0x135b98, Func Offset: 0x14e8
	// Line 2547, Address: 0x135ba0, Func Offset: 0x14f0
	// Line 2548, Address: 0x135bbc, Func Offset: 0x150c
	// Line 2549, Address: 0x135bc4, Func Offset: 0x1514
	// Line 2548, Address: 0x135bc8, Func Offset: 0x1518
	// Line 2549, Address: 0x135bd0, Func Offset: 0x1520
	// Line 2551, Address: 0x135bec, Func Offset: 0x153c
	// Line 2553, Address: 0x135bf4, Func Offset: 0x1544
	// Line 2551, Address: 0x135bf8, Func Offset: 0x1548
	// Line 2552, Address: 0x135c14, Func Offset: 0x1564
	// Line 2553, Address: 0x135c20, Func Offset: 0x1570
	// Line 2552, Address: 0x135c24, Func Offset: 0x1574
	// Line 2553, Address: 0x135c2c, Func Offset: 0x157c
	// Line 2554, Address: 0x135c38, Func Offset: 0x1588
	// Line 2556, Address: 0x135c40, Func Offset: 0x1590
	// Line 2557, Address: 0x135c58, Func Offset: 0x15a8
	// Line 2565, Address: 0x135c68, Func Offset: 0x15b8
	// Line 2567, Address: 0x135cb0, Func Offset: 0x1600
	// Line 2569, Address: 0x135cc4, Func Offset: 0x1614
	// Line 2571, Address: 0x135ccc, Func Offset: 0x161c
	// Line 2573, Address: 0x135cd4, Func Offset: 0x1624
	// Line 2572, Address: 0x135cd8, Func Offset: 0x1628
	// Line 2573, Address: 0x135cdc, Func Offset: 0x162c
	// Line 2574, Address: 0x135ce0, Func Offset: 0x1630
	// Line 2571, Address: 0x135ce4, Func Offset: 0x1634
	// Line 2572, Address: 0x135cf4, Func Offset: 0x1644
	// Line 2573, Address: 0x135d00, Func Offset: 0x1650
	// Line 2574, Address: 0x135d0c, Func Offset: 0x165c
	// Line 2573, Address: 0x135d10, Func Offset: 0x1660
	// Line 2574, Address: 0x135d18, Func Offset: 0x1668
	// Line 2575, Address: 0x135d24, Func Offset: 0x1674
	// Line 2576, Address: 0x135d2c, Func Offset: 0x167c
	// Line 2577, Address: 0x135d38, Func Offset: 0x1688
	// Line 2580, Address: 0x135d4c, Func Offset: 0x169c
	// Line 2582, Address: 0x135d54, Func Offset: 0x16a4
	// Line 2583, Address: 0x135d58, Func Offset: 0x16a8
	// Line 2585, Address: 0x135d60, Func Offset: 0x16b0
	// Line 2586, Address: 0x135d64, Func Offset: 0x16b4
	// Line 2588, Address: 0x135d6c, Func Offset: 0x16bc
	// Line 2589, Address: 0x135d70, Func Offset: 0x16c0
	// Line 2591, Address: 0x135d78, Func Offset: 0x16c8
	// Line 2592, Address: 0x135d80, Func Offset: 0x16d0
	// Line 2593, Address: 0x135d88, Func Offset: 0x16d8
	// Line 2595, Address: 0x135d90, Func Offset: 0x16e0
	// Line 2593, Address: 0x135d94, Func Offset: 0x16e4
	// Line 2594, Address: 0x135dac, Func Offset: 0x16fc
	// Line 2595, Address: 0x135dc4, Func Offset: 0x1714
	// Line 2596, Address: 0x135dd4, Func Offset: 0x1724
	// Line 2598, Address: 0x135ddc, Func Offset: 0x172c
	// Line 2604, Address: 0x135de4, Func Offset: 0x1734
	// Line 2606, Address: 0x135dec, Func Offset: 0x173c
	// Line 2607, Address: 0x135df0, Func Offset: 0x1740
	// Line 2608, Address: 0x135df4, Func Offset: 0x1744
	// Line 2604, Address: 0x135df8, Func Offset: 0x1748
	// Line 2606, Address: 0x135e14, Func Offset: 0x1764
	// Line 2607, Address: 0x135e20, Func Offset: 0x1770
	// Line 2606, Address: 0x135e24, Func Offset: 0x1774
	// Line 2607, Address: 0x135e2c, Func Offset: 0x177c
	// Line 2608, Address: 0x135e34, Func Offset: 0x1784
	// Line 2607, Address: 0x135e38, Func Offset: 0x1788
	// Line 2608, Address: 0x135e40, Func Offset: 0x1790
	// Line 2609, Address: 0x135e50, Func Offset: 0x17a0
	// Line 2610, Address: 0x135e78, Func Offset: 0x17c8
	// Line 2611, Address: 0x135e84, Func Offset: 0x17d4
	// Line 2610, Address: 0x135e88, Func Offset: 0x17d8
	// Line 2611, Address: 0x135e90, Func Offset: 0x17e0
	// Line 2612, Address: 0x135ea8, Func Offset: 0x17f8
	// Line 2613, Address: 0x135eb4, Func Offset: 0x1804
	// Line 2633, Address: 0x135ebc, Func Offset: 0x180c
	// Line 2635, Address: 0x135ed8, Func Offset: 0x1828
	// Line 2639, Address: 0x135ee8, Func Offset: 0x1838
	// Line 2641, Address: 0x135ef0, Func Offset: 0x1840
	// Line 2642, Address: 0x135f04, Func Offset: 0x1854
	// Line 2644, Address: 0x135f0c, Func Offset: 0x185c
	// Line 2646, Address: 0x135f10, Func Offset: 0x1860
	// Line 2644, Address: 0x135f14, Func Offset: 0x1864
	// Line 2646, Address: 0x135f18, Func Offset: 0x1868
	// Line 2644, Address: 0x135f1c, Func Offset: 0x186c
	// Line 2645, Address: 0x135f24, Func Offset: 0x1874
	// Line 2646, Address: 0x135f38, Func Offset: 0x1888
	// Line 2647, Address: 0x135f48, Func Offset: 0x1898
	// Line 2648, Address: 0x135f68, Func Offset: 0x18b8
	// Line 2649, Address: 0x135f94, Func Offset: 0x18e4
	// Line 2650, Address: 0x135fb4, Func Offset: 0x1904
	// Line 2651, Address: 0x135fd8, Func Offset: 0x1928
	// Line 2652, Address: 0x135ff8, Func Offset: 0x1948
	// Line 2653, Address: 0x136004, Func Offset: 0x1954
	// Line 2654, Address: 0x13603c, Func Offset: 0x198c
	// Line 2655, Address: 0x13605c, Func Offset: 0x19ac
	// Line 2656, Address: 0x136068, Func Offset: 0x19b8
	// Line 2657, Address: 0x13607c, Func Offset: 0x19cc
	// Line 2658, Address: 0x1360a0, Func Offset: 0x19f0
	// Line 2659, Address: 0x1360a4, Func Offset: 0x19f4
	// Line 2658, Address: 0x1360a8, Func Offset: 0x19f8
	// Line 2659, Address: 0x1360ac, Func Offset: 0x19fc
	// Line 2660, Address: 0x1360b4, Func Offset: 0x1a04
	// Line 2659, Address: 0x1360b8, Func Offset: 0x1a08
	// Line 2660, Address: 0x1360bc, Func Offset: 0x1a0c
	// Line 2661, Address: 0x1360c4, Func Offset: 0x1a14
	// Line 2660, Address: 0x1360c8, Func Offset: 0x1a18
	// Line 2661, Address: 0x1360cc, Func Offset: 0x1a1c
	// Line 2662, Address: 0x1360d4, Func Offset: 0x1a24
	// Line 2661, Address: 0x1360d8, Func Offset: 0x1a28
	// Line 2662, Address: 0x1360dc, Func Offset: 0x1a2c
	// Line 2666, Address: 0x1360e8, Func Offset: 0x1a38
	// Line 2671, Address: 0x1360f0, Func Offset: 0x1a40
	// Line 2673, Address: 0x13613c, Func Offset: 0x1a8c
	// Line 2674, Address: 0x136150, Func Offset: 0x1aa0
	// Line 2679, Address: 0x136158, Func Offset: 0x1aa8
	// Line 2674, Address: 0x13615c, Func Offset: 0x1aac
	// Line 2679, Address: 0x136174, Func Offset: 0x1ac4
	// Line 2682, Address: 0x13618c, Func Offset: 0x1adc
	// Line 2679, Address: 0x136190, Func Offset: 0x1ae0
	// Line 2682, Address: 0x13619c, Func Offset: 0x1aec
	// Line 2684, Address: 0x1361d8, Func Offset: 0x1b28
	// Line 2686, Address: 0x1361e4, Func Offset: 0x1b34
	// Line 2687, Address: 0x1361f8, Func Offset: 0x1b48
	// Line 2689, Address: 0x136200, Func Offset: 0x1b50
	// Line 2690, Address: 0x13620c, Func Offset: 0x1b5c
	// Line 2695, Address: 0x136214, Func Offset: 0x1b64
	// Line 2698, Address: 0x136230, Func Offset: 0x1b80
	// Line 2695, Address: 0x136234, Func Offset: 0x1b84
	// Line 2698, Address: 0x136240, Func Offset: 0x1b90
	// Line 2699, Address: 0x13625c, Func Offset: 0x1bac
	// Line 2700, Address: 0x136264, Func Offset: 0x1bb4
	// Line 2699, Address: 0x136268, Func Offset: 0x1bb8
	// Line 2700, Address: 0x136280, Func Offset: 0x1bd0
	// Line 2710, Address: 0x136290, Func Offset: 0x1be0
	// Line 2712, Address: 0x136298, Func Offset: 0x1be8
	// Line 2713, Address: 0x1362b8, Func Offset: 0x1c08
	// Line 2714, Address: 0x1362bc, Func Offset: 0x1c0c
	// Line 2713, Address: 0x1362c8, Func Offset: 0x1c18
	// Line 2714, Address: 0x1362cc, Func Offset: 0x1c1c
	// Line 2716, Address: 0x1362d4, Func Offset: 0x1c24
	// Line 2719, Address: 0x1362fc, Func Offset: 0x1c4c
	// Line 2720, Address: 0x136310, Func Offset: 0x1c60
	// Line 2721, Address: 0x136318, Func Offset: 0x1c68
	// Line 2723, Address: 0x136328, Func Offset: 0x1c78
	// Line 2725, Address: 0x136330, Func Offset: 0x1c80
	// Line 2728, Address: 0x136360, Func Offset: 0x1cb0
	// Line 2729, Address: 0x136374, Func Offset: 0x1cc4
	// Line 2731, Address: 0x13637c, Func Offset: 0x1ccc
	// Line 2732, Address: 0x136384, Func Offset: 0x1cd4
	// Line 2733, Address: 0x136398, Func Offset: 0x1ce8
	// Line 2735, Address: 0x1363a0, Func Offset: 0x1cf0
	// Line 2736, Address: 0x1363a8, Func Offset: 0x1cf8
	// Line 2739, Address: 0x1363bc, Func Offset: 0x1d0c
	// Line 2744, Address: 0x1363c4, Func Offset: 0x1d14
	// Line 2746, Address: 0x1363ec, Func Offset: 0x1d3c
	// Line 2748, Address: 0x136400, Func Offset: 0x1d50
	// Line 2749, Address: 0x136420, Func Offset: 0x1d70
	// Line 2750, Address: 0x136428, Func Offset: 0x1d78
	// Line 2751, Address: 0x13643c, Func Offset: 0x1d8c
	// Line 2754, Address: 0x136468, Func Offset: 0x1db8
	// Line 2762, Address: 0x136474, Func Offset: 0x1dc4
	// Line 2754, Address: 0x136478, Func Offset: 0x1dc8
	// Line 2762, Address: 0x136484, Func Offset: 0x1dd4
	// Line 2764, Address: 0x136488, Func Offset: 0x1dd8
	// Line 2766, Address: 0x136490, Func Offset: 0x1de0
	// Line 2767, Address: 0x1364ac, Func Offset: 0x1dfc
	// Line 2770, Address: 0x1364cc, Func Offset: 0x1e1c
	// Line 2777, Address: 0x1364d4, Func Offset: 0x1e24
	// Line 2770, Address: 0x1364d8, Func Offset: 0x1e28
	// Line 2771, Address: 0x1364e4, Func Offset: 0x1e34
	// Line 2773, Address: 0x1364e8, Func Offset: 0x1e38
	// Line 2772, Address: 0x1364f0, Func Offset: 0x1e40
	// Line 2773, Address: 0x1364f4, Func Offset: 0x1e44
	// Line 2774, Address: 0x1364f8, Func Offset: 0x1e48
	// Line 2777, Address: 0x1364fc, Func Offset: 0x1e4c
	// Line 2781, Address: 0x13650c, Func Offset: 0x1e5c
	// Line 2787, Address: 0x136518, Func Offset: 0x1e68
	// Line 2788, Address: 0x136520, Func Offset: 0x1e70
	// Line 2790, Address: 0x136524, Func Offset: 0x1e74
	// Line 2791, Address: 0x136538, Func Offset: 0x1e88
	// Line 2794, Address: 0x13654c, Func Offset: 0x1e9c
	// Line 2799, Address: 0x136554, Func Offset: 0x1ea4
	// Line 2801, Address: 0x136594, Func Offset: 0x1ee4
	// Line 2802, Address: 0x1365a8, Func Offset: 0x1ef8
	// Line 2807, Address: 0x1365b0, Func Offset: 0x1f00
	// Line 2802, Address: 0x1365b4, Func Offset: 0x1f04
	// Line 2807, Address: 0x1365cc, Func Offset: 0x1f1c
	// Line 2810, Address: 0x1365e4, Func Offset: 0x1f34
	// Line 2807, Address: 0x1365e8, Func Offset: 0x1f38
	// Line 2810, Address: 0x1365f4, Func Offset: 0x1f44
	// Line 2812, Address: 0x136630, Func Offset: 0x1f80
	// Line 2814, Address: 0x13663c, Func Offset: 0x1f8c
	// Line 2816, Address: 0x136654, Func Offset: 0x1fa4
	// Line 2817, Address: 0x136668, Func Offset: 0x1fb8
	// Line 2822, Address: 0x136670, Func Offset: 0x1fc0
	// Line 2825, Address: 0x13668c, Func Offset: 0x1fdc
	// Line 2822, Address: 0x136690, Func Offset: 0x1fe0
	// Line 2825, Address: 0x13669c, Func Offset: 0x1fec
	// Line 2826, Address: 0x1366b8, Func Offset: 0x2008
	// Line 2827, Address: 0x1366c0, Func Offset: 0x2010
	// Line 2826, Address: 0x1366c4, Func Offset: 0x2014
	// Line 2827, Address: 0x1366dc, Func Offset: 0x202c
	// Line 2829, Address: 0x1366ec, Func Offset: 0x203c
	// Line 2831, Address: 0x1366f4, Func Offset: 0x2044
	// Line 2832, Address: 0x136714, Func Offset: 0x2064
	// Line 2833, Address: 0x136718, Func Offset: 0x2068
	// Line 2832, Address: 0x136724, Func Offset: 0x2074
	// Line 2833, Address: 0x136728, Func Offset: 0x2078
	// Line 2835, Address: 0x136730, Func Offset: 0x2080
	// Line 2837, Address: 0x136758, Func Offset: 0x20a8
	// Line 2838, Address: 0x136764, Func Offset: 0x20b4
	// Line 2841, Address: 0x13676c, Func Offset: 0x20bc
	// Line 2842, Address: 0x136780, Func Offset: 0x20d0
	// Line 2843, Address: 0x136788, Func Offset: 0x20d8
	// Line 2845, Address: 0x136798, Func Offset: 0x20e8
	// Line 2847, Address: 0x1367a0, Func Offset: 0x20f0
	// Line 2850, Address: 0x1367d0, Func Offset: 0x2120
	// Line 2851, Address: 0x1367e4, Func Offset: 0x2134
	// Line 2850, Address: 0x1367e8, Func Offset: 0x2138
	// Line 2851, Address: 0x1367f0, Func Offset: 0x2140
	// Line 2859, Address: 0x136804, Func Offset: 0x2154
	// Line 2860, Address: 0x136828, Func Offset: 0x2178
	// Line 2861, Address: 0x13685c, Func Offset: 0x21ac
	// Line 2862, Address: 0x136864, Func Offset: 0x21b4
	// Line 2863, Address: 0x136870, Func Offset: 0x21c0
	// Line 2864, Address: 0x136884, Func Offset: 0x21d4
	// Line 2863, Address: 0x136888, Func Offset: 0x21d8
	// Line 2864, Address: 0x136894, Func Offset: 0x21e4
	// Line 2867, Address: 0x1368b8, Func Offset: 0x2208
	// Line 2877, Address: 0x1368d8, Func Offset: 0x2228
	// Line 2878, Address: 0x136904, Func Offset: 0x2254
	// Line 2903, Address: 0x136930, Func Offset: 0x2280
	// Func End, Address: 0x136944, Func Offset: 0x2294
}

// 
// Start address: 0x136950
void bhSysCallSndMonitor()
{
	// Line 2909, Address: 0x136950, Func Offset: 0
	// Line 2913, Address: 0x13695c, Func Offset: 0xc
	// Line 2921, Address: 0x136988, Func Offset: 0x38
	// Line 2922, Address: 0x13699c, Func Offset: 0x4c
	// Line 2928, Address: 0x1369ac, Func Offset: 0x5c
	// Line 2929, Address: 0x1369b4, Func Offset: 0x64
	// Line 2930, Address: 0x1369c4, Func Offset: 0x74
	// Line 2931, Address: 0x1369cc, Func Offset: 0x7c
	// Line 2932, Address: 0x1369d8, Func Offset: 0x88
	// Line 2931, Address: 0x1369dc, Func Offset: 0x8c
	// Line 2932, Address: 0x1369e4, Func Offset: 0x94
	// Line 2933, Address: 0x1369ec, Func Offset: 0x9c
	// Line 2934, Address: 0x1369fc, Func Offset: 0xac
	// Line 2933, Address: 0x136a00, Func Offset: 0xb0
	// Line 2934, Address: 0x136a04, Func Offset: 0xb4
	// Line 2933, Address: 0x136a08, Func Offset: 0xb8
	// Line 2934, Address: 0x136a10, Func Offset: 0xc0
	// Line 2940, Address: 0x136a20, Func Offset: 0xd0
	// Line 2941, Address: 0x136a44, Func Offset: 0xf4
	// Line 2943, Address: 0x136aac, Func Offset: 0x15c
	// Line 2945, Address: 0x136ab8, Func Offset: 0x168
	// Line 2947, Address: 0x136ac0, Func Offset: 0x170
	// Line 2948, Address: 0x136ad0, Func Offset: 0x180
	// Line 2949, Address: 0x136aec, Func Offset: 0x19c
	// Line 2950, Address: 0x136b00, Func Offset: 0x1b0
	// Line 2952, Address: 0x136b08, Func Offset: 0x1b8
	// Line 2953, Address: 0x136b18, Func Offset: 0x1c8
	// Line 2954, Address: 0x136b2c, Func Offset: 0x1dc
	// Line 2956, Address: 0x136b34, Func Offset: 0x1e4
	// Line 2958, Address: 0x136b40, Func Offset: 0x1f0
	// Line 2960, Address: 0x136b48, Func Offset: 0x1f8
	// Line 2961, Address: 0x136b58, Func Offset: 0x208
	// Line 2962, Address: 0x136b68, Func Offset: 0x218
	// Line 2963, Address: 0x136b7c, Func Offset: 0x22c
	// Line 2965, Address: 0x136b84, Func Offset: 0x234
	// Line 2966, Address: 0x136b94, Func Offset: 0x244
	// Line 2967, Address: 0x136ba8, Func Offset: 0x258
	// Line 2969, Address: 0x136bb0, Func Offset: 0x260
	// Line 2971, Address: 0x136bbc, Func Offset: 0x26c
	// Line 2973, Address: 0x136bc4, Func Offset: 0x274
	// Line 2974, Address: 0x136bd4, Func Offset: 0x284
	// Line 2975, Address: 0x136c08, Func Offset: 0x2b8
	// Line 2976, Address: 0x136c1c, Func Offset: 0x2cc
	// Line 2978, Address: 0x136c24, Func Offset: 0x2d4
	// Line 2979, Address: 0x136c34, Func Offset: 0x2e4
	// Line 2980, Address: 0x136c48, Func Offset: 0x2f8
	// Line 2982, Address: 0x136c50, Func Offset: 0x300
	// Line 2983, Address: 0x136c54, Func Offset: 0x304
	// Line 2988, Address: 0x136c6c, Func Offset: 0x31c
	// Line 2989, Address: 0x136c74, Func Offset: 0x324
	// Func End, Address: 0x136c84, Func Offset: 0x334
}

// 
// Start address: 0x136c90
void bhSysCallScreenSaver()
{
	Point pos;
	int col;
	Point pos;
	// Line 2997, Address: 0x136c90, Func Offset: 0
	// Line 3001, Address: 0x136c9c, Func Offset: 0xc
	// Line 3006, Address: 0x136ce4, Func Offset: 0x54
	// Line 3007, Address: 0x136cf8, Func Offset: 0x68
	// Line 3020, Address: 0x136d74, Func Offset: 0xe4
	// Line 3022, Address: 0x136d84, Func Offset: 0xf4
	// Line 3023, Address: 0x136d9c, Func Offset: 0x10c
	// Line 3024, Address: 0x136da4, Func Offset: 0x114
	// Line 3033, Address: 0x136dc0, Func Offset: 0x130
	// Line 3038, Address: 0x136de0, Func Offset: 0x150
	// Line 3041, Address: 0x136df0, Func Offset: 0x160
	// Line 3043, Address: 0x136df8, Func Offset: 0x168
	// Line 3052, Address: 0x136e00, Func Offset: 0x170
	// Line 3057, Address: 0x136e1c, Func Offset: 0x18c
	// Line 3063, Address: 0x136e60, Func Offset: 0x1d0
	// Line 3067, Address: 0x136e68, Func Offset: 0x1d8
	// Line 3071, Address: 0x136e70, Func Offset: 0x1e0
	// Line 3072, Address: 0x136e80, Func Offset: 0x1f0
	// Line 3080, Address: 0x136e90, Func Offset: 0x200
	// Line 3072, Address: 0x136ea4, Func Offset: 0x214
	// Line 3080, Address: 0x136ea8, Func Offset: 0x218
	// Line 3072, Address: 0x136eac, Func Offset: 0x21c
	// Line 3080, Address: 0x136eb4, Func Offset: 0x224
	// Line 3081, Address: 0x136ecc, Func Offset: 0x23c
	// Line 3082, Address: 0x136ee0, Func Offset: 0x250
	// Line 3083, Address: 0x136ef0, Func Offset: 0x260
	// Line 3084, Address: 0x136ef8, Func Offset: 0x268
	// Line 3085, Address: 0x136f14, Func Offset: 0x284
	// Line 3086, Address: 0x136f24, Func Offset: 0x294
	// Line 3105, Address: 0x136f3c, Func Offset: 0x2ac
	// Line 3107, Address: 0x136f6c, Func Offset: 0x2dc
	// Line 3110, Address: 0x136fa8, Func Offset: 0x318
	// Line 3112, Address: 0x136fdc, Func Offset: 0x34c
	// Line 3113, Address: 0x136ffc, Func Offset: 0x36c
	// Line 3117, Address: 0x137004, Func Offset: 0x374
	// Line 3119, Address: 0x13702c, Func Offset: 0x39c
	// Line 3120, Address: 0x13703c, Func Offset: 0x3ac
	// Line 3125, Address: 0x137060, Func Offset: 0x3d0
	// Line 3122, Address: 0x137068, Func Offset: 0x3d8
	// Line 3123, Address: 0x137070, Func Offset: 0x3e0
	// Line 3125, Address: 0x137078, Func Offset: 0x3e8
	// Line 3129, Address: 0x13708c, Func Offset: 0x3fc
	// Line 3125, Address: 0x137090, Func Offset: 0x400
	// Line 3129, Address: 0x13709c, Func Offset: 0x40c
	// Line 3125, Address: 0x1370a0, Func Offset: 0x410
	// Line 3129, Address: 0x1370a4, Func Offset: 0x414
	// Line 3130, Address: 0x1370b4, Func Offset: 0x424
	// Line 3140, Address: 0x1370e4, Func Offset: 0x454
	// Line 3142, Address: 0x13711c, Func Offset: 0x48c
	// Line 3144, Address: 0x137130, Func Offset: 0x4a0
	// Line 3145, Address: 0x137138, Func Offset: 0x4a8
	// Line 3146, Address: 0x137140, Func Offset: 0x4b0
	// Line 3149, Address: 0x13715c, Func Offset: 0x4cc
	// Func End, Address: 0x13716c, Func Offset: 0x4dc
}

/* 100% match */
void bhReturnTitle() { // Line 3155, Address: 0x137170
    sys->ss_flg |= 0x20000; // Line 3156, Address: 0x137178
    bhExitGame(); // Line 3157, Address: 0x13718c
    if (!(sys->ss_flg & 0x200000)) { // Line 3158, Address: 0x137194
        sys->tk_flg = 0x300008; // Line 3159, Address: 0x1371b0
    } else { // Line 3160, Address: 0x1371b8
        sys->ss_flg &= ~0x200000; // Line 3161, Address: 0x1371c0, 0x1371d8
        sys->tk_flg = 0x300004; // Line 3162, Address: 0x1371e0
    }
    sys->ts_flg = 0; // Line 3164, Address: 0x1371e8, 0x1371f8
    sys->ss_flg &= ~0x20000; // Line 3165, Address: 0x1371f0, 0x1371fc, 0x13720c
    sys->ss_flg |= 0x1000; // Line 3166, Address: 0x137214
} // Line 3167, Address: 0x137224

/* 100% match */
void bhExitGame() { // Line 3173, Address: 0x137230
    if ((sys->ss_flg & 0x2)) { // Line 3174, Address: 0x137238
        njWaitVSync(); // Line 3175, Address: 0x137250
        njWaitVSync(); // Line 3176, Address: 0x137258
        njWaitVSync(); // Line 3177, Address: 0x137260
        bhChangeHWSetting(); // Line 3178, Address: 0x137268
    } else { // Line 3179, Address: 0x137270
        njWaitVSync(); // Line 3180, Address: 0x137278
    }



    
    njReleaseTextureAll(); // Line 3186, Address: 0x137280
    njGarbageTexture(&tbuf, 256); // Line 3187, Address: 0x137288


    
    njSetBackColor(0, 0, 0); // Line 3191, Address: 0x137298
    bhInitSystem(); // Line 3192, Address: 0x1372a8
} // Line 3193, Address: 0x1372b0

/* 100% match */
void bhSetEventTimer(int mode) { // Line 3204, Address: 0x1372c0
    sys->evt_tmd = mode + 1; // Line 3205, Address: 0x1372c8, 0x1372d8
    switch (mode) { // Line 3206, Address: 0x1372d4, 0x1372e0
        case 0:
            bhStFlg(&sys->ev_flg[0], 69); // Line 3208, Address: 0x137304
            sys->evt_tim = 2700; // Line 3209, Address: 0x137318, 0x137328
            sys->evt_tdg = 900; // Line 3210, Address: 0x137324, 0x137334
            break; // Line 3211, Address: 0x137344
        case 1:
            bhStFlg(&sys->ev_flg[0], 67); // Line 3213, Address: 0x13734c
            sys->evt_tim = 18000; // Line 3214, Address: 0x137360, 0x137370
            sys->evt_tdg = 3600; // Line 3215, Address: 0x13736c, 0x13737c
            break; // Line 3216, Address: 0x13738c
        case 2:
            bhStFlg(&sys->ev_flg[0], 70); // Line 3218, Address: 0x137394
            sys->evt_tim = 18000; // Line 3219, Address: 0x1373a8, 0x1373bc
            sys->evt_tdg = 3600; // Line 3220, Address: 0x1373b4, 0x1373c8
            sys->evt_fcd = 900; // Line 3221, Address: 0x1373b8, 0x1373dc
            sys->evt_fcdct = 0; // Line 3222, Address: 0x1373f0
            break;
    }
} // Line 3225, Address: 0x137404

/* 99.13% match - needs line numbers */
void EasyDispMessage(float PosY, unsigned int MessageNo) { 
    unsigned int* mes_dp;
	float SizeX;
	int SearchFlag;
	int LoopFlag;
	float sy;
	int y;
	int x;
	unsigned short* nmp;
	unsigned short* mp;
	unsigned char* dmp;
	unsigned short* smp; // changed type in regards to dwarf2cpp's output

    LoopFlag = 1; 
    
    smp = (void*)((int)sys->mes_sp + sys->mes_sp[MessageNo + 1]); 
    
    dmp = syMalloc(1024); 
    
    memcpy(dmp, smp, 1024); 
    
    for (nmp = (void*)dmp, y = 0; LoopFlag != 0; nmp = (void*)mes_dp, y++) { 
        SizeX = 0.0f; 
        
        SearchFlag = 1;
        
        for (x = 0, smp = nmp; SearchFlag != 0; smp++, x++) { 
            switch (*smp) { 
            case 0xFFFF:
                LoopFlag = 0; 
                SearchFlag = 0;
                break; 
            case 0xFF00:
                mes_dp = (void*)(smp + 1); 
                *smp = 0xFFFF; 
                SearchFlag = 0; 
                break; 
            case 0xFF01:
                SizeX += 14.0f * FontScaleX;
                break; 
            default: 
                SizeX += FontScaleX * FontSz[*smp]; 
                break; 
            }
        }
        
        sys->mes_tp = (int*)nmp;
        
        SizeX /= 2.0f;
        
        bhDispMessage(320.0f - SizeX, PosY, -1, 2, 0, 0, 0);
        
        PosY += 30 * FontScaleCR;
    } 
    
    syFree(dmp); 
}

