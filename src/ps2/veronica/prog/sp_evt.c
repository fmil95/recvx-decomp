#include "sp_evt.h"

/*char* comevt_message_tst[27];
unsigned char comevt_script_tst[181];
_anon20 acs_no0[1];
char* comevt_message_no1[19];
unsigned char comevt_script_no1[141];
_anon20 acs_no1[8];
char* comevt_message_no2[17];
unsigned char comevt_script_no2[140];
_anon20 acs_no2[9];
char* comevt_message_no3[23];
unsigned char comevt_script_no3[126];
_anon20 acs_no3[8];
char* comevt_message_no4[20];
unsigned char comevt_script_no4[41];
unsigned char comevt_script_no5[83];
unsigned char comevt_script_no6[18];
_anon20 acs_no4[9];
char* comevt_message_no7[4];
unsigned char comevt_script_no7[40];
_anon20 acs_no7[8];
void* comevt_message_tab[8];
void* comevt_script_tab[8];
void* comevt_acs_tab[8];
void(*bhCtrSpEvtCom_mode0)()[3];
_anon11* sys;
unsigned int palbuf[0];
_anon12* rom;
float fNaViwClipFar;
float cmat[16];
BH_PWORK ene[0];
float fNaViwClipNear;

void bhControlSpEvtComputer();
void bhKeepSpEvtComputer();
void bhInitSpEvtComputer();
void bhMainSpEvtComputer();
void bhExitSpEvtComputer();
void bhEntrySpEvtComputer();
void bhDrawSpEvtComputer();
void bhDrawSpEvtComTime();
void bhDrawSpEvtComVal(int val, float px, float py);
void bhDrawSpEvtComBar(int barno, int col0, int col1);
void bhDrawSpEvtComCharacter();
void bhSetSpEvtComFade(float fdst, float fcnt);
void bhCalcSpEvtComFade();
void bhDrawSpEvtComFade();
void bhEntrySpEvtBoxLine(_anon41* line);
void bhDrawSpEvtBoxLine();
void bhClearComEvtText();
void bhInitComEvtScript();
void bhControlComEvtScript();
void bhControlComEvtKeyboard();*/

// 
// Start address: 0x2bd050
void bhControlSpEvtComputer()
{
	// Line 93, Address: 0x2bd050, Func Offset: 0
	// Func End, Address: 0x2bd080, Func Offset: 0x30
	scePrintf("bhControlSpEvtComputer - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2bd080
void bhKeepSpEvtComputer()
{
	// Line 100, Address: 0x2bd080, Func Offset: 0
	// Line 101, Address: 0x2bd088, Func Offset: 0x8
	// Line 103, Address: 0x2bd0ac, Func Offset: 0x2c
	// Line 104, Address: 0x2bd0b4, Func Offset: 0x34
	// Line 106, Address: 0x2bd0d4, Func Offset: 0x54
	// Func End, Address: 0x2bd0e0, Func Offset: 0x60
	scePrintf("bhKeepSpEvtComputer - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2bd0e0
void bhInitSpEvtComputer()
{
	int i;
	_anon7* ce;
	// Line 112, Address: 0x2bd0e0, Func Offset: 0
	// Line 116, Address: 0x2bd0f4, Func Offset: 0x14
	// Line 119, Address: 0x2bd0fc, Func Offset: 0x1c
	// Line 116, Address: 0x2bd104, Func Offset: 0x24
	// Line 118, Address: 0x2bd120, Func Offset: 0x40
	// Line 119, Address: 0x2bd134, Func Offset: 0x54
	// Line 121, Address: 0x2bd13c, Func Offset: 0x5c
	// Line 124, Address: 0x2bd144, Func Offset: 0x64
	// Line 121, Address: 0x2bd148, Func Offset: 0x68
	// Line 124, Address: 0x2bd14c, Func Offset: 0x6c
	// Line 121, Address: 0x2bd150, Func Offset: 0x70
	// Line 122, Address: 0x2bd15c, Func Offset: 0x7c
	// Line 124, Address: 0x2bd170, Func Offset: 0x90
	// Line 125, Address: 0x2bd190, Func Offset: 0xb0
	// Line 127, Address: 0x2bd198, Func Offset: 0xb8
	// Line 129, Address: 0x2bd1b0, Func Offset: 0xd0
	// Line 130, Address: 0x2bd1b4, Func Offset: 0xd4
	// Line 132, Address: 0x2bd1d8, Func Offset: 0xf8
	// Line 133, Address: 0x2bd1e0, Func Offset: 0x100
	// Line 134, Address: 0x2bd1e8, Func Offset: 0x108
	// Line 136, Address: 0x2bd1fc, Func Offset: 0x11c
	// Line 138, Address: 0x2bd204, Func Offset: 0x124
	// Line 139, Address: 0x2bd210, Func Offset: 0x130
	// Line 141, Address: 0x2bd21c, Func Offset: 0x13c
	// Line 143, Address: 0x2bd224, Func Offset: 0x144
	// Line 144, Address: 0x2bd290, Func Offset: 0x1b0
	// Line 145, Address: 0x2bd2cc, Func Offset: 0x1ec
	// Line 144, Address: 0x2bd2d0, Func Offset: 0x1f0
	// Line 145, Address: 0x2bd2d4, Func Offset: 0x1f4
	// Line 144, Address: 0x2bd2d8, Func Offset: 0x1f8
	// Line 145, Address: 0x2bd2dc, Func Offset: 0x1fc
	// Line 146, Address: 0x2bd2e4, Func Offset: 0x204
	// Line 148, Address: 0x2bd320, Func Offset: 0x240
	// Line 149, Address: 0x2bd354, Func Offset: 0x274
	// Func End, Address: 0x2bd36c, Func Offset: 0x28c
}

// 
// Start address: 0x2bd370
void bhMainSpEvtComputer()
{
	_anon41 line;
	_anon7* ce;
	// Line 156, Address: 0x2bd370, Func Offset: 0
	// Line 157, Address: 0x2bd37c, Func Offset: 0xc
	// Line 160, Address: 0x2bd384, Func Offset: 0x14
	// Line 157, Address: 0x2bd388, Func Offset: 0x18
	// Line 160, Address: 0x2bd394, Func Offset: 0x24
	// Line 162, Address: 0x2bd464, Func Offset: 0xf4
	// Line 163, Address: 0x2bd47c, Func Offset: 0x10c
	// Line 164, Address: 0x2bd484, Func Offset: 0x114
	// Line 165, Address: 0x2bd494, Func Offset: 0x124
	// Line 170, Address: 0x2bd498, Func Offset: 0x128
	// Line 171, Address: 0x2bd4a0, Func Offset: 0x130
	// Line 172, Address: 0x2bd4a4, Func Offset: 0x134
	// Line 173, Address: 0x2bd4c4, Func Offset: 0x154
	// Line 174, Address: 0x2bd4d8, Func Offset: 0x168
	// Line 173, Address: 0x2bd4dc, Func Offset: 0x16c
	// Line 174, Address: 0x2bd4e0, Func Offset: 0x170
	// Line 175, Address: 0x2bd4e8, Func Offset: 0x178
	// Line 176, Address: 0x2bd4f4, Func Offset: 0x184
	// Line 177, Address: 0x2bd504, Func Offset: 0x194
	// Line 178, Address: 0x2bd528, Func Offset: 0x1b8
	// Line 181, Address: 0x2bd54c, Func Offset: 0x1dc
	// Line 183, Address: 0x2bd554, Func Offset: 0x1e4
	// Line 184, Address: 0x2bd560, Func Offset: 0x1f0
	// Line 185, Address: 0x2bd57c, Func Offset: 0x20c
	// Line 186, Address: 0x2bd58c, Func Offset: 0x21c
	// Line 187, Address: 0x2bd598, Func Offset: 0x228
	// Line 186, Address: 0x2bd59c, Func Offset: 0x22c
	// Line 189, Address: 0x2bd5a8, Func Offset: 0x238
	// Line 191, Address: 0x2bd5b0, Func Offset: 0x240
	// Line 192, Address: 0x2bd5b8, Func Offset: 0x248
	// Line 193, Address: 0x2bd5c0, Func Offset: 0x250
	// Line 194, Address: 0x2bd5e0, Func Offset: 0x270
	// Line 195, Address: 0x2bd5f4, Func Offset: 0x284
	// Line 194, Address: 0x2bd5f8, Func Offset: 0x288
	// Line 195, Address: 0x2bd5fc, Func Offset: 0x28c
	// Line 196, Address: 0x2bd604, Func Offset: 0x294
	// Line 197, Address: 0x2bd610, Func Offset: 0x2a0
	// Line 198, Address: 0x2bd620, Func Offset: 0x2b0
	// Line 201, Address: 0x2bd644, Func Offset: 0x2d4
	// Line 203, Address: 0x2bd64c, Func Offset: 0x2dc
	// Line 204, Address: 0x2bd658, Func Offset: 0x2e8
	// Line 205, Address: 0x2bd674, Func Offset: 0x304
	// Line 206, Address: 0x2bd684, Func Offset: 0x314
	// Line 207, Address: 0x2bd690, Func Offset: 0x320
	// Line 206, Address: 0x2bd694, Func Offset: 0x324
	// Line 209, Address: 0x2bd6a0, Func Offset: 0x330
	// Line 211, Address: 0x2bd6a8, Func Offset: 0x338
	// Line 212, Address: 0x2bd6b0, Func Offset: 0x340
	// Line 213, Address: 0x2bd6b8, Func Offset: 0x348
	// Line 214, Address: 0x2bd6d8, Func Offset: 0x368
	// Line 215, Address: 0x2bd6ec, Func Offset: 0x37c
	// Line 214, Address: 0x2bd6f0, Func Offset: 0x380
	// Line 215, Address: 0x2bd6f4, Func Offset: 0x384
	// Line 216, Address: 0x2bd6fc, Func Offset: 0x38c
	// Line 217, Address: 0x2bd708, Func Offset: 0x398
	// Line 218, Address: 0x2bd718, Func Offset: 0x3a8
	// Line 219, Address: 0x2bd73c, Func Offset: 0x3cc
	// Line 222, Address: 0x2bd760, Func Offset: 0x3f0
	// Line 224, Address: 0x2bd768, Func Offset: 0x3f8
	// Line 225, Address: 0x2bd774, Func Offset: 0x404
	// Line 226, Address: 0x2bd790, Func Offset: 0x420
	// Line 227, Address: 0x2bd7a0, Func Offset: 0x430
	// Line 228, Address: 0x2bd7ac, Func Offset: 0x43c
	// Line 227, Address: 0x2bd7b0, Func Offset: 0x440
	// Line 230, Address: 0x2bd7bc, Func Offset: 0x44c
	// Line 235, Address: 0x2bd7c4, Func Offset: 0x454
	// Line 237, Address: 0x2bd7cc, Func Offset: 0x45c
	// Line 238, Address: 0x2bd7fc, Func Offset: 0x48c
	// Line 241, Address: 0x2bd804, Func Offset: 0x494
	// Line 244, Address: 0x2bd83c, Func Offset: 0x4cc
	// Line 245, Address: 0x2bd840, Func Offset: 0x4d0
	// Line 246, Address: 0x2bd854, Func Offset: 0x4e4
	// Line 253, Address: 0x2bd85c, Func Offset: 0x4ec
	// Line 254, Address: 0x2bd860, Func Offset: 0x4f0
	// Line 255, Address: 0x2bd864, Func Offset: 0x4f4
	// Line 253, Address: 0x2bd868, Func Offset: 0x4f8
	// Line 254, Address: 0x2bd870, Func Offset: 0x500
	// Line 255, Address: 0x2bd874, Func Offset: 0x504
	// Line 256, Address: 0x2bd878, Func Offset: 0x508
	// Line 257, Address: 0x2bd894, Func Offset: 0x524
	// Line 258, Address: 0x2bd8a4, Func Offset: 0x534
	// Line 257, Address: 0x2bd8a8, Func Offset: 0x538
	// Line 258, Address: 0x2bd8ac, Func Offset: 0x53c
	// Line 259, Address: 0x2bd8b4, Func Offset: 0x544
	// Line 260, Address: 0x2bd8d0, Func Offset: 0x560
	// Line 261, Address: 0x2bd8dc, Func Offset: 0x56c
	// Line 264, Address: 0x2bd8f4, Func Offset: 0x584
	// Line 269, Address: 0x2bd8fc, Func Offset: 0x58c
	// Line 270, Address: 0x2bd900, Func Offset: 0x590
	// Line 271, Address: 0x2bd904, Func Offset: 0x594
	// Line 269, Address: 0x2bd908, Func Offset: 0x598
	// Line 270, Address: 0x2bd910, Func Offset: 0x5a0
	// Line 271, Address: 0x2bd914, Func Offset: 0x5a4
	// Line 272, Address: 0x2bd918, Func Offset: 0x5a8
	// Line 273, Address: 0x2bd934, Func Offset: 0x5c4
	// Line 274, Address: 0x2bd944, Func Offset: 0x5d4
	// Line 273, Address: 0x2bd948, Func Offset: 0x5d8
	// Line 274, Address: 0x2bd94c, Func Offset: 0x5dc
	// Line 275, Address: 0x2bd954, Func Offset: 0x5e4
	// Line 276, Address: 0x2bd970, Func Offset: 0x600
	// Line 277, Address: 0x2bd97c, Func Offset: 0x60c
	// Line 280, Address: 0x2bd994, Func Offset: 0x624
	// Line 285, Address: 0x2bd99c, Func Offset: 0x62c
	// Line 286, Address: 0x2bd9bc, Func Offset: 0x64c
	// Line 287, Address: 0x2bd9dc, Func Offset: 0x66c
	// Line 288, Address: 0x2bd9e4, Func Offset: 0x674
	// Line 287, Address: 0x2bd9e8, Func Offset: 0x678
	// Line 288, Address: 0x2bd9ec, Func Offset: 0x67c
	// Line 289, Address: 0x2bd9f0, Func Offset: 0x680
	// Line 290, Address: 0x2bda00, Func Offset: 0x690
	// Line 292, Address: 0x2bda08, Func Offset: 0x698
	// Line 293, Address: 0x2bda10, Func Offset: 0x6a0
	// Line 294, Address: 0x2bda20, Func Offset: 0x6b0
	// Line 295, Address: 0x2bda40, Func Offset: 0x6d0
	// Line 297, Address: 0x2bda48, Func Offset: 0x6d8
	// Line 298, Address: 0x2bda4c, Func Offset: 0x6dc
	// Line 299, Address: 0x2bda50, Func Offset: 0x6e0
	// Line 297, Address: 0x2bda54, Func Offset: 0x6e4
	// Line 298, Address: 0x2bda5c, Func Offset: 0x6ec
	// Line 299, Address: 0x2bda60, Func Offset: 0x6f0
	// Line 300, Address: 0x2bda64, Func Offset: 0x6f4
	// Line 301, Address: 0x2bda80, Func Offset: 0x710
	// Line 302, Address: 0x2bda90, Func Offset: 0x720
	// Line 301, Address: 0x2bda94, Func Offset: 0x724
	// Line 302, Address: 0x2bda98, Func Offset: 0x728
	// Line 303, Address: 0x2bdaa0, Func Offset: 0x730
	// Line 304, Address: 0x2bdabc, Func Offset: 0x74c
	// Line 305, Address: 0x2bdac8, Func Offset: 0x758
	// Line 307, Address: 0x2bdad0, Func Offset: 0x760
	// Line 305, Address: 0x2bdad4, Func Offset: 0x764
	// Line 306, Address: 0x2bdaf0, Func Offset: 0x780
	// Line 309, Address: 0x2bdaf4, Func Offset: 0x784
	// Line 311, Address: 0x2bdafc, Func Offset: 0x78c
	// Line 313, Address: 0x2bdb18, Func Offset: 0x7a8
	// Line 312, Address: 0x2bdb1c, Func Offset: 0x7ac
	// Line 313, Address: 0x2bdb20, Func Offset: 0x7b0
	// Line 314, Address: 0x2bdb24, Func Offset: 0x7b4
	// Line 315, Address: 0x2bdb34, Func Offset: 0x7c4
	// Line 317, Address: 0x2bdb3c, Func Offset: 0x7cc
	// Line 318, Address: 0x2bdb48, Func Offset: 0x7d8
	// Line 319, Address: 0x2bdb50, Func Offset: 0x7e0
	// Line 320, Address: 0x2bdb60, Func Offset: 0x7f0
	// Line 321, Address: 0x2bdb80, Func Offset: 0x810
	// Line 323, Address: 0x2bdb88, Func Offset: 0x818
	// Line 324, Address: 0x2bdb8c, Func Offset: 0x81c
	// Line 325, Address: 0x2bdb90, Func Offset: 0x820
	// Line 323, Address: 0x2bdb94, Func Offset: 0x824
	// Line 324, Address: 0x2bdb9c, Func Offset: 0x82c
	// Line 325, Address: 0x2bdba0, Func Offset: 0x830
	// Line 326, Address: 0x2bdba4, Func Offset: 0x834
	// Line 327, Address: 0x2bdbc0, Func Offset: 0x850
	// Line 328, Address: 0x2bdbd0, Func Offset: 0x860
	// Line 327, Address: 0x2bdbd4, Func Offset: 0x864
	// Line 328, Address: 0x2bdbd8, Func Offset: 0x868
	// Line 329, Address: 0x2bdbe0, Func Offset: 0x870
	// Line 330, Address: 0x2bdbfc, Func Offset: 0x88c
	// Line 331, Address: 0x2bdc08, Func Offset: 0x898
	// Line 334, Address: 0x2bdc10, Func Offset: 0x8a0
	// Line 333, Address: 0x2bdc18, Func Offset: 0x8a8
	// Line 334, Address: 0x2bdc1c, Func Offset: 0x8ac
	// Line 331, Address: 0x2bdc20, Func Offset: 0x8b0
	// Line 332, Address: 0x2bdc3c, Func Offset: 0x8cc
	// Line 334, Address: 0x2bdc40, Func Offset: 0x8d0
	// Line 336, Address: 0x2bdc48, Func Offset: 0x8d8
	// Line 338, Address: 0x2bdc50, Func Offset: 0x8e0
	// Line 339, Address: 0x2bdc6c, Func Offset: 0x8fc
	// Line 340, Address: 0x2bdc74, Func Offset: 0x904
	// Line 342, Address: 0x2bdc7c, Func Offset: 0x90c
	// Line 343, Address: 0x2bdc80, Func Offset: 0x910
	// Line 342, Address: 0x2bdc84, Func Offset: 0x914
	// Line 343, Address: 0x2bdc8c, Func Offset: 0x91c
	// Line 344, Address: 0x2bdc90, Func Offset: 0x920
	// Line 345, Address: 0x2bdc94, Func Offset: 0x924
	// Line 346, Address: 0x2bdcb0, Func Offset: 0x940
	// Line 347, Address: 0x2bdcc0, Func Offset: 0x950
	// Line 346, Address: 0x2bdcc4, Func Offset: 0x954
	// Line 347, Address: 0x2bdcc8, Func Offset: 0x958
	// Line 348, Address: 0x2bdcd0, Func Offset: 0x960
	// Line 349, Address: 0x2bdcec, Func Offset: 0x97c
	// Line 350, Address: 0x2bdcf8, Func Offset: 0x988
	// Line 351, Address: 0x2bdd10, Func Offset: 0x9a0
	// Line 352, Address: 0x2bdd28, Func Offset: 0x9b8
	// Line 355, Address: 0x2bdd2c, Func Offset: 0x9bc
	// Line 360, Address: 0x2bdd34, Func Offset: 0x9c4
	// Line 361, Address: 0x2bdd4c, Func Offset: 0x9dc
	// Line 362, Address: 0x2bdd5c, Func Offset: 0x9ec
	// Line 367, Address: 0x2bdd64, Func Offset: 0x9f4
	// Line 369, Address: 0x2bdd6c, Func Offset: 0x9fc
	// Line 371, Address: 0x2bdd94, Func Offset: 0xa24
	// Line 373, Address: 0x2bdda8, Func Offset: 0xa38
	// Line 375, Address: 0x2bddb0, Func Offset: 0xa40
	// Line 376, Address: 0x2bddb8, Func Offset: 0xa48
	// Func End, Address: 0x2bddc8, Func Offset: 0xa58
}

// 
// Start address: 0x2bddd0
void bhExitSpEvtComputer()
{
	_anon7* ce;
	// Line 382, Address: 0x2bddd0, Func Offset: 0
	// Line 383, Address: 0x2bdddc, Func Offset: 0xc
	// Line 384, Address: 0x2bddf0, Func Offset: 0x20
	// Line 386, Address: 0x2bde10, Func Offset: 0x40
	// Line 388, Address: 0x2bde1c, Func Offset: 0x4c
	// Line 391, Address: 0x2bde28, Func Offset: 0x58
	// Line 393, Address: 0x2bde44, Func Offset: 0x74
	// Line 394, Address: 0x2bde5c, Func Offset: 0x8c
	// Line 396, Address: 0x2bde64, Func Offset: 0x94
	// Line 394, Address: 0x2bde6c, Func Offset: 0x9c
	// Line 396, Address: 0x2bde70, Func Offset: 0xa0
	// Line 394, Address: 0x2bde74, Func Offset: 0xa4
	// Line 396, Address: 0x2bde7c, Func Offset: 0xac
	// Line 398, Address: 0x2bde90, Func Offset: 0xc0
	// Line 401, Address: 0x2bde9c, Func Offset: 0xcc
	// Line 402, Address: 0x2bdea4, Func Offset: 0xd4
	// Line 398, Address: 0x2bdea8, Func Offset: 0xd8
	// Line 399, Address: 0x2bdeac, Func Offset: 0xdc
	// Line 402, Address: 0x2bdeb4, Func Offset: 0xe4
	// Line 403, Address: 0x2bdeb8, Func Offset: 0xe8
	// Line 404, Address: 0x2bdebc, Func Offset: 0xec
	// Line 399, Address: 0x2bdec0, Func Offset: 0xf0
	// Line 400, Address: 0x2bdecc, Func Offset: 0xfc
	// Line 401, Address: 0x2bded8, Func Offset: 0x108
	// Line 400, Address: 0x2bdedc, Func Offset: 0x10c
	// Line 401, Address: 0x2bdee4, Func Offset: 0x114
	// Line 402, Address: 0x2bdeec, Func Offset: 0x11c
	// Line 401, Address: 0x2bdef0, Func Offset: 0x120
	// Line 402, Address: 0x2bdef8, Func Offset: 0x128
	// Line 403, Address: 0x2bdf00, Func Offset: 0x130
	// Line 402, Address: 0x2bdf04, Func Offset: 0x134
	// Line 403, Address: 0x2bdf0c, Func Offset: 0x13c
	// Line 404, Address: 0x2bdf14, Func Offset: 0x144
	// Line 403, Address: 0x2bdf18, Func Offset: 0x148
	// Line 404, Address: 0x2bdf20, Func Offset: 0x150
	// Line 406, Address: 0x2bdf28, Func Offset: 0x158
	// Line 404, Address: 0x2bdf2c, Func Offset: 0x15c
	// Line 406, Address: 0x2bdf34, Func Offset: 0x164
	// Line 408, Address: 0x2bdf4c, Func Offset: 0x17c
	// Line 409, Address: 0x2bdf54, Func Offset: 0x184
	// Func End, Address: 0x2bdf64, Func Offset: 0x194
}

// 
// Start address: 0x2bdf70
void bhEntrySpEvtComputer()
{
	float on;
	float cy;
	unsigned int a;
	unsigned int asc;
	unsigned int dat;
	int qtect;
	int j;
	int i;
	_anon7* ce;
	unsigned int* qtbcol;
	_anon20* tbl;
	_anon20* qt;
	// Line 416, Address: 0x2bdf70, Func Offset: 0
	// Line 419, Address: 0x2bdf8c, Func Offset: 0x1c
	// Line 429, Address: 0x2bdf94, Func Offset: 0x24
	// Line 430, Address: 0x2bdf98, Func Offset: 0x28
	// Line 419, Address: 0x2bdf9c, Func Offset: 0x2c
	// Line 427, Address: 0x2bdfa8, Func Offset: 0x38
	// Line 428, Address: 0x2bdfac, Func Offset: 0x3c
	// Line 429, Address: 0x2bdfb0, Func Offset: 0x40
	// Line 430, Address: 0x2bdfb4, Func Offset: 0x44
	// Line 431, Address: 0x2bdfb8, Func Offset: 0x48
	// Line 423, Address: 0x2bdfc0, Func Offset: 0x50
	// Line 431, Address: 0x2bdfc4, Func Offset: 0x54
	// Line 432, Address: 0x2bdfdc, Func Offset: 0x6c
	// Line 433, Address: 0x2bdfe0, Func Offset: 0x70
	// Line 434, Address: 0x2bdfe4, Func Offset: 0x74
	// Line 435, Address: 0x2bdfec, Func Offset: 0x7c
	// Line 436, Address: 0x2bdff0, Func Offset: 0x80
	// Line 437, Address: 0x2bdff8, Func Offset: 0x88
	// Line 438, Address: 0x2bdffc, Func Offset: 0x8c
	// Line 439, Address: 0x2be004, Func Offset: 0x94
	// Line 440, Address: 0x2be00c, Func Offset: 0x9c
	// Line 443, Address: 0x2be014, Func Offset: 0xa4
	// Line 445, Address: 0x2be020, Func Offset: 0xb0
	// Line 449, Address: 0x2be028, Func Offset: 0xb8
	// Line 450, Address: 0x2be030, Func Offset: 0xc0
	// Line 451, Address: 0x2be034, Func Offset: 0xc4
	// Line 452, Address: 0x2be03c, Func Offset: 0xcc
	// Line 453, Address: 0x2be044, Func Offset: 0xd4
	// Line 454, Address: 0x2be048, Func Offset: 0xd8
	// Line 455, Address: 0x2be050, Func Offset: 0xe0
	// Line 456, Address: 0x2be058, Func Offset: 0xe8
	// Line 458, Address: 0x2be060, Func Offset: 0xf0
	// Line 463, Address: 0x2be06c, Func Offset: 0xfc
	// Line 461, Address: 0x2be070, Func Offset: 0x100
	// Line 463, Address: 0x2be074, Func Offset: 0x104
	// Line 458, Address: 0x2be078, Func Offset: 0x108
	// Line 461, Address: 0x2be084, Func Offset: 0x114
	// Line 462, Address: 0x2be088, Func Offset: 0x118
	// Line 463, Address: 0x2be08c, Func Offset: 0x11c
	// Line 464, Address: 0x2be090, Func Offset: 0x120
	// Line 465, Address: 0x2be098, Func Offset: 0x128
	// Line 466, Address: 0x2be09c, Func Offset: 0x12c
	// Line 467, Address: 0x2be0a0, Func Offset: 0x130
	// Line 468, Address: 0x2be0a8, Func Offset: 0x138
	// Line 470, Address: 0x2be0ac, Func Offset: 0x13c
	// Line 469, Address: 0x2be0b8, Func Offset: 0x148
	// Line 448, Address: 0x2be0bc, Func Offset: 0x14c
	// Line 470, Address: 0x2be0c0, Func Offset: 0x150
	// Line 473, Address: 0x2be0dc, Func Offset: 0x16c
	// Line 470, Address: 0x2be0e4, Func Offset: 0x174
	// Line 473, Address: 0x2be0e8, Func Offset: 0x178
	// Line 474, Address: 0x2be100, Func Offset: 0x190
	// Line 475, Address: 0x2be108, Func Offset: 0x198
	// Line 476, Address: 0x2be110, Func Offset: 0x1a0
	// Line 477, Address: 0x2be118, Func Offset: 0x1a8
	// Line 478, Address: 0x2be120, Func Offset: 0x1b0
	// Line 479, Address: 0x2be124, Func Offset: 0x1b4
	// Line 480, Address: 0x2be12c, Func Offset: 0x1bc
	// Line 481, Address: 0x2be134, Func Offset: 0x1c4
	// Line 483, Address: 0x2be138, Func Offset: 0x1c8
	// Line 485, Address: 0x2be150, Func Offset: 0x1e0
	// Line 486, Address: 0x2be160, Func Offset: 0x1f0
	// Line 487, Address: 0x2be16c, Func Offset: 0x1fc
	// Line 488, Address: 0x2be174, Func Offset: 0x204
	// Line 489, Address: 0x2be180, Func Offset: 0x210
	// Line 491, Address: 0x2be1bc, Func Offset: 0x24c
	// Line 494, Address: 0x2be1c8, Func Offset: 0x258
	// Line 491, Address: 0x2be1cc, Func Offset: 0x25c
	// Line 492, Address: 0x2be1d0, Func Offset: 0x260
	// Line 493, Address: 0x2be1d8, Func Offset: 0x268
	// Line 491, Address: 0x2be1dc, Func Offset: 0x26c
	// Line 492, Address: 0x2be1e0, Func Offset: 0x270
	// Line 493, Address: 0x2be1e4, Func Offset: 0x274
	// Line 492, Address: 0x2be1e8, Func Offset: 0x278
	// Line 495, Address: 0x2be1ec, Func Offset: 0x27c
	// Line 496, Address: 0x2be1f4, Func Offset: 0x284
	// Line 492, Address: 0x2be1f8, Func Offset: 0x288
	// Line 493, Address: 0x2be1fc, Func Offset: 0x28c
	// Line 494, Address: 0x2be200, Func Offset: 0x290
	// Line 496, Address: 0x2be204, Func Offset: 0x294
	// Line 497, Address: 0x2be208, Func Offset: 0x298
	// Line 493, Address: 0x2be210, Func Offset: 0x2a0
	// Line 498, Address: 0x2be214, Func Offset: 0x2a4
	// Line 493, Address: 0x2be218, Func Offset: 0x2a8
	// Line 494, Address: 0x2be220, Func Offset: 0x2b0
	// Line 498, Address: 0x2be224, Func Offset: 0x2b4
	// Line 494, Address: 0x2be228, Func Offset: 0x2b8
	// Line 495, Address: 0x2be234, Func Offset: 0x2c4
	// Line 496, Address: 0x2be238, Func Offset: 0x2c8
	// Line 497, Address: 0x2be23c, Func Offset: 0x2cc
	// Line 498, Address: 0x2be248, Func Offset: 0x2d8
	// Line 499, Address: 0x2be250, Func Offset: 0x2e0
	// Line 501, Address: 0x2be258, Func Offset: 0x2e8
	// Line 502, Address: 0x2be27c, Func Offset: 0x30c
	// Line 503, Address: 0x2be284, Func Offset: 0x314
	// Line 504, Address: 0x2be288, Func Offset: 0x318
	// Line 501, Address: 0x2be28c, Func Offset: 0x31c
	// Line 505, Address: 0x2be298, Func Offset: 0x328
	// Line 507, Address: 0x2be29c, Func Offset: 0x32c
	// Line 508, Address: 0x2be2a0, Func Offset: 0x330
	// Line 501, Address: 0x2be2a4, Func Offset: 0x334
	// Line 507, Address: 0x2be2b0, Func Offset: 0x340
	// Line 508, Address: 0x2be2b4, Func Offset: 0x344
	// Line 502, Address: 0x2be2b8, Func Offset: 0x348
	// Line 503, Address: 0x2be2c4, Func Offset: 0x354
	// Line 504, Address: 0x2be2c8, Func Offset: 0x358
	// Line 505, Address: 0x2be2cc, Func Offset: 0x35c
	// Line 502, Address: 0x2be2d0, Func Offset: 0x360
	// Line 503, Address: 0x2be2f8, Func Offset: 0x388
	// Line 504, Address: 0x2be308, Func Offset: 0x398
	// Line 505, Address: 0x2be318, Func Offset: 0x3a8
	// Line 506, Address: 0x2be348, Func Offset: 0x3d8
	// Line 507, Address: 0x2be370, Func Offset: 0x400
	// Line 508, Address: 0x2be37c, Func Offset: 0x40c
	// Line 511, Address: 0x2be388, Func Offset: 0x418
	// Line 510, Address: 0x2be38c, Func Offset: 0x41c
	// Line 511, Address: 0x2be390, Func Offset: 0x420
	// Line 512, Address: 0x2be3b0, Func Offset: 0x440
	// Line 511, Address: 0x2be3b4, Func Offset: 0x444
	// Line 512, Address: 0x2be3b8, Func Offset: 0x448
	// Line 513, Address: 0x2be3c0, Func Offset: 0x450
	// Line 512, Address: 0x2be3c4, Func Offset: 0x454
	// Line 516, Address: 0x2be3dc, Func Offset: 0x46c
	// Line 517, Address: 0x2be3fc, Func Offset: 0x48c
	// Line 518, Address: 0x2be404, Func Offset: 0x494
	// Line 519, Address: 0x2be40c, Func Offset: 0x49c
	// Line 520, Address: 0x2be414, Func Offset: 0x4a4
	// Line 521, Address: 0x2be41c, Func Offset: 0x4ac
	// Line 522, Address: 0x2be420, Func Offset: 0x4b0
	// Line 523, Address: 0x2be424, Func Offset: 0x4b4
	// Line 524, Address: 0x2be42c, Func Offset: 0x4bc
	// Line 526, Address: 0x2be430, Func Offset: 0x4c0
	// Line 528, Address: 0x2be434, Func Offset: 0x4c4
	// Line 529, Address: 0x2be438, Func Offset: 0x4c8
	// Line 530, Address: 0x2be43c, Func Offset: 0x4cc
	// Line 531, Address: 0x2be440, Func Offset: 0x4d0
	// Line 534, Address: 0x2be444, Func Offset: 0x4d4
	// Line 526, Address: 0x2be448, Func Offset: 0x4d8
	// Line 528, Address: 0x2be454, Func Offset: 0x4e4
	// Line 529, Address: 0x2be458, Func Offset: 0x4e8
	// Line 530, Address: 0x2be45c, Func Offset: 0x4ec
	// Line 531, Address: 0x2be460, Func Offset: 0x4f0
	// Line 532, Address: 0x2be464, Func Offset: 0x4f4
	// Line 533, Address: 0x2be468, Func Offset: 0x4f8
	// Line 534, Address: 0x2be46c, Func Offset: 0x4fc
	// Line 535, Address: 0x2be470, Func Offset: 0x500
	// Line 537, Address: 0x2be478, Func Offset: 0x508
	// Line 536, Address: 0x2be484, Func Offset: 0x514
	// Line 538, Address: 0x2be488, Func Offset: 0x518
	// Line 537, Address: 0x2be48c, Func Offset: 0x51c
	// Line 541, Address: 0x2be49c, Func Offset: 0x52c
	// Line 542, Address: 0x2be4ac, Func Offset: 0x53c
	// Line 543, Address: 0x2be4b8, Func Offset: 0x548
	// Line 544, Address: 0x2be4c8, Func Offset: 0x558
	// Line 545, Address: 0x2be4d0, Func Offset: 0x560
	// Line 546, Address: 0x2be4d4, Func Offset: 0x564
	// Line 544, Address: 0x2be4dc, Func Offset: 0x56c
	// Line 546, Address: 0x2be4e0, Func Offset: 0x570
	// Line 547, Address: 0x2be4ec, Func Offset: 0x57c
	// Line 548, Address: 0x2be4fc, Func Offset: 0x58c
	// Line 549, Address: 0x2be504, Func Offset: 0x594
	// Line 551, Address: 0x2be50c, Func Offset: 0x59c
	// Line 552, Address: 0x2be514, Func Offset: 0x5a4
	// Line 554, Address: 0x2be518, Func Offset: 0x5a8
	// Line 555, Address: 0x2be52c, Func Offset: 0x5bc
	// Line 556, Address: 0x2be560, Func Offset: 0x5f0
	// Line 557, Address: 0x2be564, Func Offset: 0x5f4
	// Line 558, Address: 0x2be568, Func Offset: 0x5f8
	// Line 559, Address: 0x2be570, Func Offset: 0x600
	// Line 561, Address: 0x2be57c, Func Offset: 0x60c
	// Line 559, Address: 0x2be580, Func Offset: 0x610
	// Line 562, Address: 0x2be584, Func Offset: 0x614
	// Line 563, Address: 0x2be588, Func Offset: 0x618
	// Line 559, Address: 0x2be58c, Func Offset: 0x61c
	// Line 561, Address: 0x2be590, Func Offset: 0x620
	// Line 559, Address: 0x2be598, Func Offset: 0x628
	// Line 563, Address: 0x2be59c, Func Offset: 0x62c
	// Line 559, Address: 0x2be5a0, Func Offset: 0x630
	// Line 560, Address: 0x2be5b0, Func Offset: 0x640
	// Line 561, Address: 0x2be5b4, Func Offset: 0x644
	// Line 562, Address: 0x2be5b8, Func Offset: 0x648
	// Line 561, Address: 0x2be5bc, Func Offset: 0x64c
	// Line 562, Address: 0x2be5c4, Func Offset: 0x654
	// Line 563, Address: 0x2be5cc, Func Offset: 0x65c
	// Line 564, Address: 0x2be604, Func Offset: 0x694
	// Line 563, Address: 0x2be608, Func Offset: 0x698
	// Line 564, Address: 0x2be60c, Func Offset: 0x69c
	// Line 565, Address: 0x2be650, Func Offset: 0x6e0
	// Line 564, Address: 0x2be654, Func Offset: 0x6e4
	// Line 565, Address: 0x2be658, Func Offset: 0x6e8
	// Line 564, Address: 0x2be65c, Func Offset: 0x6ec
	// Line 565, Address: 0x2be664, Func Offset: 0x6f4
	// Line 566, Address: 0x2be69c, Func Offset: 0x72c
	// Line 565, Address: 0x2be6a0, Func Offset: 0x730
	// Line 566, Address: 0x2be6ac, Func Offset: 0x73c
	// Line 572, Address: 0x2be6e4, Func Offset: 0x774
	// Line 566, Address: 0x2be6e8, Func Offset: 0x778
	// Line 568, Address: 0x2be6ec, Func Offset: 0x77c
	// Line 572, Address: 0x2be6f0, Func Offset: 0x780
	// Line 568, Address: 0x2be6f4, Func Offset: 0x784
	// Line 572, Address: 0x2be6f8, Func Offset: 0x788
	// Line 568, Address: 0x2be6fc, Func Offset: 0x78c
	// Line 572, Address: 0x2be700, Func Offset: 0x790
	// Line 573, Address: 0x2be730, Func Offset: 0x7c0
	// Line 566, Address: 0x2be734, Func Offset: 0x7c4
	// Line 572, Address: 0x2be738, Func Offset: 0x7c8
	// Line 567, Address: 0x2be73c, Func Offset: 0x7cc
	// Line 573, Address: 0x2be740, Func Offset: 0x7d0
	// Line 574, Address: 0x2be748, Func Offset: 0x7d8
	// Line 575, Address: 0x2be74c, Func Offset: 0x7dc
	// Line 576, Address: 0x2be760, Func Offset: 0x7f0
	// Line 577, Address: 0x2be764, Func Offset: 0x7f4
	// Line 576, Address: 0x2be768, Func Offset: 0x7f8
	// Line 577, Address: 0x2be774, Func Offset: 0x804
	// Line 579, Address: 0x2be780, Func Offset: 0x810
	// Line 580, Address: 0x2be784, Func Offset: 0x814
	// Line 581, Address: 0x2be788, Func Offset: 0x818
	// Line 579, Address: 0x2be790, Func Offset: 0x820
	// Line 581, Address: 0x2be794, Func Offset: 0x824
	// Line 582, Address: 0x2be79c, Func Offset: 0x82c
	// Line 581, Address: 0x2be7a4, Func Offset: 0x834
	// Line 582, Address: 0x2be7a8, Func Offset: 0x838
	// Line 584, Address: 0x2be7b0, Func Offset: 0x840
	// Line 586, Address: 0x2be7bc, Func Offset: 0x84c
	// Line 584, Address: 0x2be7c0, Func Offset: 0x850
	// Line 585, Address: 0x2be7d0, Func Offset: 0x860
	// Line 584, Address: 0x2be7d4, Func Offset: 0x864
	// Line 587, Address: 0x2be7d8, Func Offset: 0x868
	// Line 588, Address: 0x2be7dc, Func Offset: 0x86c
	// Line 589, Address: 0x2be7e0, Func Offset: 0x870
	// Line 590, Address: 0x2be7e4, Func Offset: 0x874
	// Line 584, Address: 0x2be7e8, Func Offset: 0x878
	// Line 586, Address: 0x2be7f0, Func Offset: 0x880
	// Line 584, Address: 0x2be7f4, Func Offset: 0x884
	// Line 585, Address: 0x2be7f8, Func Offset: 0x888
	// Line 587, Address: 0x2be7fc, Func Offset: 0x88c
	// Line 585, Address: 0x2be800, Func Offset: 0x890
	// Line 591, Address: 0x2be804, Func Offset: 0x894
	// Line 585, Address: 0x2be808, Func Offset: 0x898
	// Line 586, Address: 0x2be830, Func Offset: 0x8c0
	// Line 587, Address: 0x2be83c, Func Offset: 0x8cc
	// Line 588, Address: 0x2be848, Func Offset: 0x8d8
	// Line 589, Address: 0x2be84c, Func Offset: 0x8dc
	// Line 590, Address: 0x2be850, Func Offset: 0x8e0
	// Line 591, Address: 0x2be854, Func Offset: 0x8e4
	// Line 593, Address: 0x2be858, Func Offset: 0x8e8
	// Line 594, Address: 0x2be878, Func Offset: 0x908
	// Line 595, Address: 0x2be8a8, Func Offset: 0x938
	// Line 596, Address: 0x2be8c4, Func Offset: 0x954
	// Line 598, Address: 0x2be8cc, Func Offset: 0x95c
	// Line 602, Address: 0x2be8d0, Func Offset: 0x960
	// Line 599, Address: 0x2be8d4, Func Offset: 0x964
	// Line 604, Address: 0x2be8d8, Func Offset: 0x968
	// Line 605, Address: 0x2be8dc, Func Offset: 0x96c
	// Line 598, Address: 0x2be8e0, Func Offset: 0x970
	// Line 599, Address: 0x2be8ec, Func Offset: 0x97c
	// Line 603, Address: 0x2be8f0, Func Offset: 0x980
	// Line 604, Address: 0x2be8f4, Func Offset: 0x984
	// Line 606, Address: 0x2be8f8, Func Offset: 0x988
	// Line 605, Address: 0x2be8fc, Func Offset: 0x98c
	// Line 606, Address: 0x2be900, Func Offset: 0x990
	// Line 608, Address: 0x2be904, Func Offset: 0x994
	// Line 607, Address: 0x2be908, Func Offset: 0x998
	// Line 608, Address: 0x2be90c, Func Offset: 0x99c
	// Line 609, Address: 0x2be910, Func Offset: 0x9a0
	// Line 610, Address: 0x2be918, Func Offset: 0x9a8
	// Line 612, Address: 0x2be91c, Func Offset: 0x9ac
	// Line 610, Address: 0x2be920, Func Offset: 0x9b0
	// Line 612, Address: 0x2be924, Func Offset: 0x9b4
	// Line 614, Address: 0x2be928, Func Offset: 0x9b8
	// Line 615, Address: 0x2be92c, Func Offset: 0x9bc
	// Line 616, Address: 0x2be930, Func Offset: 0x9c0
	// Line 617, Address: 0x2be938, Func Offset: 0x9c8
	// Line 618, Address: 0x2be93c, Func Offset: 0x9cc
	// Line 619, Address: 0x2be940, Func Offset: 0x9d0
	// Line 620, Address: 0x2be944, Func Offset: 0x9d4
	// Line 621, Address: 0x2be94c, Func Offset: 0x9dc
	// Line 623, Address: 0x2be950, Func Offset: 0x9e0
	// Line 627, Address: 0x2be954, Func Offset: 0x9e4
	// Line 622, Address: 0x2be95c, Func Offset: 0x9ec
	// Line 623, Address: 0x2be960, Func Offset: 0x9f0
	// Line 624, Address: 0x2be964, Func Offset: 0x9f4
	// Line 627, Address: 0x2be968, Func Offset: 0x9f8
	// Line 626, Address: 0x2be97c, Func Offset: 0xa0c
	// Line 627, Address: 0x2be980, Func Offset: 0xa10
	// Line 645, Address: 0x2be990, Func Offset: 0xa20
	// Line 646, Address: 0x2be998, Func Offset: 0xa28
	// Line 629, Address: 0x2be99c, Func Offset: 0xa2c
	// Line 646, Address: 0x2be9a0, Func Offset: 0xa30
	// Line 629, Address: 0x2be9a4, Func Offset: 0xa34
	// Line 630, Address: 0x2be9b8, Func Offset: 0xa48
	// Line 631, Address: 0x2be9c8, Func Offset: 0xa58
	// Line 633, Address: 0x2be9cc, Func Offset: 0xa5c
	// Line 635, Address: 0x2be9d4, Func Offset: 0xa64
	// Line 636, Address: 0x2be9d8, Func Offset: 0xa68
	// Line 637, Address: 0x2be9e0, Func Offset: 0xa70
	// Line 638, Address: 0x2be9e8, Func Offset: 0xa78
	// Line 639, Address: 0x2be9f0, Func Offset: 0xa80
	// Line 640, Address: 0x2be9f8, Func Offset: 0xa88
	// Line 641, Address: 0x2bea00, Func Offset: 0xa90
	// Line 642, Address: 0x2bea08, Func Offset: 0xa98
	// Line 644, Address: 0x2bea10, Func Offset: 0xaa0
	// Line 645, Address: 0x2bea18, Func Offset: 0xaa8
	// Line 646, Address: 0x2bea34, Func Offset: 0xac4
	// Line 647, Address: 0x2bea38, Func Offset: 0xac8
	// Line 648, Address: 0x2bea40, Func Offset: 0xad0
	// Line 650, Address: 0x2bea48, Func Offset: 0xad8
	// Line 651, Address: 0x2bea4c, Func Offset: 0xadc
	// Line 653, Address: 0x2bea50, Func Offset: 0xae0
	// Line 655, Address: 0x2bea58, Func Offset: 0xae8
	// Line 657, Address: 0x2bea5c, Func Offset: 0xaec
	// Line 658, Address: 0x2bea68, Func Offset: 0xaf8
	// Func End, Address: 0x2bea88, Func Offset: 0xb18
}

// 
// Start address: 0x2bea90
void bhDrawSpEvtComputer()
{
	float pri;
	int j;
	int i;
	_anon7* ce;
	unsigned int* qtbcol;
	_anon20* qt;
	_anon37 sp[2];
	// Line 665, Address: 0x2bea90, Func Offset: 0
	// Line 669, Address: 0x2beac0, Func Offset: 0x30
	// Line 672, Address: 0x2bead4, Func Offset: 0x44
	// Line 677, Address: 0x2beadc, Func Offset: 0x4c
	// Line 676, Address: 0x2beae0, Func Offset: 0x50
	// Line 677, Address: 0x2beae4, Func Offset: 0x54
	// Line 678, Address: 0x2beae8, Func Offset: 0x58
	// Line 679, Address: 0x2beaf4, Func Offset: 0x64
	// Line 680, Address: 0x2beafc, Func Offset: 0x6c
	// Line 673, Address: 0x2beb00, Func Offset: 0x70
	// Line 674, Address: 0x2beb04, Func Offset: 0x74
	// Line 679, Address: 0x2beb08, Func Offset: 0x78
	// Line 680, Address: 0x2beb0c, Func Offset: 0x7c
	// Line 681, Address: 0x2beb14, Func Offset: 0x84
	// Line 682, Address: 0x2beb1c, Func Offset: 0x8c
	// Line 683, Address: 0x2beb28, Func Offset: 0x98
	// Line 686, Address: 0x2beb3c, Func Offset: 0xac
	// Line 689, Address: 0x2beb44, Func Offset: 0xb4
	// Line 690, Address: 0x2beb4c, Func Offset: 0xbc
	// Line 691, Address: 0x2beb58, Func Offset: 0xc8
	// Line 695, Address: 0x2beb68, Func Offset: 0xd8
	// Line 696, Address: 0x2beb74, Func Offset: 0xe4
	// Line 700, Address: 0x2beb88, Func Offset: 0xf8
	// Line 697, Address: 0x2beb90, Func Offset: 0x100
	// Line 700, Address: 0x2beb94, Func Offset: 0x104
	// Line 701, Address: 0x2bebac, Func Offset: 0x11c
	// Line 702, Address: 0x2bebb8, Func Offset: 0x128
	// Line 705, Address: 0x2bebcc, Func Offset: 0x13c
	// Line 706, Address: 0x2bebd8, Func Offset: 0x148
	// Line 707, Address: 0x2bebec, Func Offset: 0x15c
	// Line 708, Address: 0x2bebf0, Func Offset: 0x160
	// Line 711, Address: 0x2bebf4, Func Offset: 0x164
	// Line 712, Address: 0x2bec14, Func Offset: 0x184
	// Line 713, Address: 0x2bec20, Func Offset: 0x190
	// Line 716, Address: 0x2bec34, Func Offset: 0x1a4
	// Line 717, Address: 0x2bec40, Func Offset: 0x1b0
	// Line 718, Address: 0x2bec54, Func Offset: 0x1c4
	// Line 719, Address: 0x2bec58, Func Offset: 0x1c8
	// Line 721, Address: 0x2bec5c, Func Offset: 0x1cc
	// Line 723, Address: 0x2bec64, Func Offset: 0x1d4
	// Line 725, Address: 0x2bec84, Func Offset: 0x1f4
	// Line 726, Address: 0x2bec8c, Func Offset: 0x1fc
	// Line 727, Address: 0x2bec98, Func Offset: 0x208
	// Line 728, Address: 0x2beca0, Func Offset: 0x210
	// Line 729, Address: 0x2beca4, Func Offset: 0x214
	// Line 730, Address: 0x2becb4, Func Offset: 0x224
	// Line 732, Address: 0x2becbc, Func Offset: 0x22c
	// Line 731, Address: 0x2becc0, Func Offset: 0x230
	// Line 732, Address: 0x2becc4, Func Offset: 0x234
	// Line 733, Address: 0x2becc8, Func Offset: 0x238
	// Line 734, Address: 0x2becd0, Func Offset: 0x240
	// Line 735, Address: 0x2becd4, Func Offset: 0x244
	// Line 734, Address: 0x2becd8, Func Offset: 0x248
	// Line 735, Address: 0x2becdc, Func Offset: 0x24c
	// Line 738, Address: 0x2bece4, Func Offset: 0x254
	// Line 739, Address: 0x2becf0, Func Offset: 0x260
	// Line 740, Address: 0x2becf8, Func Offset: 0x268
	// Line 741, Address: 0x2bed00, Func Offset: 0x270
	// Line 742, Address: 0x2bed0c, Func Offset: 0x27c
	// Line 743, Address: 0x2bed18, Func Offset: 0x288
	// Line 744, Address: 0x2bed2c, Func Offset: 0x29c
	// Line 745, Address: 0x2bed30, Func Offset: 0x2a0
	// Line 746, Address: 0x2bed34, Func Offset: 0x2a4
	// Line 747, Address: 0x2bed38, Func Offset: 0x2a8
	// Line 748, Address: 0x2bed48, Func Offset: 0x2b8
	// Line 750, Address: 0x2bed58, Func Offset: 0x2c8
	// Line 751, Address: 0x2bed64, Func Offset: 0x2d4
	// Line 752, Address: 0x2bed78, Func Offset: 0x2e8
	// Line 754, Address: 0x2bed7c, Func Offset: 0x2ec
	// Line 756, Address: 0x2bed84, Func Offset: 0x2f4
	// Line 757, Address: 0x2bed90, Func Offset: 0x300
	// Line 758, Address: 0x2bed98, Func Offset: 0x308
	// Line 759, Address: 0x2beda0, Func Offset: 0x310
	// Line 760, Address: 0x2bedac, Func Offset: 0x31c
	// Line 761, Address: 0x2bedb8, Func Offset: 0x328
	// Line 762, Address: 0x2bedc4, Func Offset: 0x334
	// Line 761, Address: 0x2bedc8, Func Offset: 0x338
	// Line 763, Address: 0x2bedcc, Func Offset: 0x33c
	// Line 764, Address: 0x2bedd0, Func Offset: 0x340
	// Line 765, Address: 0x2bede8, Func Offset: 0x358
	// Line 768, Address: 0x2bedf0, Func Offset: 0x360
	// Line 767, Address: 0x2bedf4, Func Offset: 0x364
	// Line 768, Address: 0x2bedf8, Func Offset: 0x368
	// Line 769, Address: 0x2bedfc, Func Offset: 0x36c
	// Line 770, Address: 0x2bee04, Func Offset: 0x374
	// Line 771, Address: 0x2bee08, Func Offset: 0x378
	// Line 770, Address: 0x2bee0c, Func Offset: 0x37c
	// Line 771, Address: 0x2bee10, Func Offset: 0x380
	// Line 773, Address: 0x2bee18, Func Offset: 0x388
	// Line 775, Address: 0x2bee20, Func Offset: 0x390
	// Line 777, Address: 0x2bee2c, Func Offset: 0x39c
	// Line 778, Address: 0x2bee3c, Func Offset: 0x3ac
	// Line 779, Address: 0x2beea8, Func Offset: 0x418
	// Line 780, Address: 0x2beecc, Func Offset: 0x43c
	// Line 781, Address: 0x2beedc, Func Offset: 0x44c
	// Line 783, Address: 0x2beef4, Func Offset: 0x464
	// Line 785, Address: 0x2bef10, Func Offset: 0x480
	// Line 783, Address: 0x2bef18, Func Offset: 0x488
	// Line 785, Address: 0x2bef1c, Func Offset: 0x48c
	// Line 786, Address: 0x2bef24, Func Offset: 0x494
	// Line 787, Address: 0x2bef34, Func Offset: 0x4a4
	// Line 788, Address: 0x2bef44, Func Offset: 0x4b4
	// Line 790, Address: 0x2bef54, Func Offset: 0x4c4
	// Line 796, Address: 0x2bef74, Func Offset: 0x4e4
	// Line 800, Address: 0x2befbc, Func Offset: 0x52c
	// Func End, Address: 0x2beff0, Func Offset: 0x560
}

// 
// Start address: 0x2beff0
void bhDrawSpEvtComTime()
{
	int sec;
	int min;
	int hour;
	_SYS_RTC_DATE date;
	// Line 807, Address: 0x2beff0, Func Offset: 0
	// Line 811, Address: 0x2bf004, Func Offset: 0x14
	// Line 812, Address: 0x2bf024, Func Offset: 0x34
	// Line 813, Address: 0x2bf028, Func Offset: 0x38
	// Line 815, Address: 0x2bf02c, Func Offset: 0x3c
	// Line 816, Address: 0x2bf034, Func Offset: 0x44
	// Line 817, Address: 0x2bf040, Func Offset: 0x50
	// Line 818, Address: 0x2bf044, Func Offset: 0x54
	// Line 819, Address: 0x2bf048, Func Offset: 0x58
	// Line 840, Address: 0x2bf050, Func Offset: 0x60
	// Line 841, Address: 0x2bf080, Func Offset: 0x90
	// Line 845, Address: 0x2bf0a8, Func Offset: 0xb8
	// Line 846, Address: 0x2bf0d8, Func Offset: 0xe8
	// Line 850, Address: 0x2bf0fc, Func Offset: 0x10c
	// Line 854, Address: 0x2bf114, Func Offset: 0x124
	// Line 855, Address: 0x2bf14c, Func Offset: 0x15c
	// Line 856, Address: 0x2bf174, Func Offset: 0x184
	// Func End, Address: 0x2bf18c, Func Offset: 0x19c
}

// 
// Start address: 0x2bf190
void bhDrawSpEvtComVal(int val, float px, float py)
{
	_anon20 qt;
	// Line 867, Address: 0x2bf190, Func Offset: 0
	// Line 863, Address: 0x2bf198, Func Offset: 0x8
	// Line 867, Address: 0x2bf19c, Func Offset: 0xc
	// Line 863, Address: 0x2bf1a0, Func Offset: 0x10
	// Line 865, Address: 0x2bf1a4, Func Offset: 0x14
	// Line 866, Address: 0x2bf1a8, Func Offset: 0x18
	// Line 868, Address: 0x2bf1ac, Func Offset: 0x1c
	// Line 867, Address: 0x2bf1b0, Func Offset: 0x20
	// Line 868, Address: 0x2bf1b4, Func Offset: 0x24
	// Line 869, Address: 0x2bf1b8, Func Offset: 0x28
	// Line 868, Address: 0x2bf1bc, Func Offset: 0x2c
	// Line 869, Address: 0x2bf1c0, Func Offset: 0x30
	// Line 870, Address: 0x2bf1e0, Func Offset: 0x50
	// Line 869, Address: 0x2bf1e4, Func Offset: 0x54
	// Line 870, Address: 0x2bf1ec, Func Offset: 0x5c
	// Line 871, Address: 0x2bf1f4, Func Offset: 0x64
	// Line 869, Address: 0x2bf1f8, Func Offset: 0x68
	// Line 870, Address: 0x2bf1fc, Func Offset: 0x6c
	// Line 869, Address: 0x2bf200, Func Offset: 0x70
	// Line 870, Address: 0x2bf208, Func Offset: 0x78
	// Line 872, Address: 0x2bf210, Func Offset: 0x80
	// Line 873, Address: 0x2bf214, Func Offset: 0x84
	// Line 869, Address: 0x2bf218, Func Offset: 0x88
	// Line 870, Address: 0x2bf21c, Func Offset: 0x8c
	// Line 871, Address: 0x2bf220, Func Offset: 0x90
	// Line 870, Address: 0x2bf224, Func Offset: 0x94
	// Line 871, Address: 0x2bf230, Func Offset: 0xa0
	// Line 872, Address: 0x2bf234, Func Offset: 0xa4
	// Line 871, Address: 0x2bf23c, Func Offset: 0xac
	// Line 872, Address: 0x2bf244, Func Offset: 0xb4
	// Line 873, Address: 0x2bf24c, Func Offset: 0xbc
	// Line 874, Address: 0x2bf254, Func Offset: 0xc4
	// Line 875, Address: 0x2bf264, Func Offset: 0xd4
	// Line 876, Address: 0x2bf278, Func Offset: 0xe8
	// Line 877, Address: 0x2bf280, Func Offset: 0xf0
	// Func End, Address: 0x2bf28c, Func Offset: 0xfc
}

// 
// Start address: 0x2bf290
void bhDrawSpEvtComBar(int barno, int col0, int col1)
{
	_anon7* ce;
	_anon20 qt;
	// Line 884, Address: 0x2bf290, Func Offset: 0
	// Line 886, Address: 0x2bf2bc, Func Offset: 0x2c
	// Line 887, Address: 0x2bf2c8, Func Offset: 0x38
	// Line 886, Address: 0x2bf2d0, Func Offset: 0x40
	// Line 887, Address: 0x2bf2dc, Func Offset: 0x4c
	// Line 888, Address: 0x2bf2e4, Func Offset: 0x54
	// Line 889, Address: 0x2bf2ec, Func Offset: 0x5c
	// Line 890, Address: 0x2bf300, Func Offset: 0x70
	// Line 889, Address: 0x2bf304, Func Offset: 0x74
	// Line 890, Address: 0x2bf308, Func Offset: 0x78
	// Line 889, Address: 0x2bf30c, Func Offset: 0x7c
	// Line 890, Address: 0x2bf310, Func Offset: 0x80
	// Line 889, Address: 0x2bf314, Func Offset: 0x84
	// Line 890, Address: 0x2bf318, Func Offset: 0x88
	// Line 893, Address: 0x2bf324, Func Offset: 0x94
	// Line 892, Address: 0x2bf328, Func Offset: 0x98
	// Line 893, Address: 0x2bf330, Func Offset: 0xa0
	// Line 890, Address: 0x2bf334, Func Offset: 0xa4
	// Line 891, Address: 0x2bf338, Func Offset: 0xa8
	// Line 894, Address: 0x2bf33c, Func Offset: 0xac
	// Line 895, Address: 0x2bf340, Func Offset: 0xb0
	// Line 891, Address: 0x2bf344, Func Offset: 0xb4
	// Line 896, Address: 0x2bf348, Func Offset: 0xb8
	// Line 893, Address: 0x2bf34c, Func Offset: 0xbc
	// Line 890, Address: 0x2bf354, Func Offset: 0xc4
	// Line 893, Address: 0x2bf35c, Func Offset: 0xcc
	// Line 891, Address: 0x2bf364, Func Offset: 0xd4
	// Line 893, Address: 0x2bf368, Func Offset: 0xd8
	// Line 895, Address: 0x2bf36c, Func Offset: 0xdc
	// Line 893, Address: 0x2bf370, Func Offset: 0xe0
	// Line 891, Address: 0x2bf374, Func Offset: 0xe4
	// Line 894, Address: 0x2bf378, Func Offset: 0xe8
	// Line 896, Address: 0x2bf37c, Func Offset: 0xec
	// Line 891, Address: 0x2bf380, Func Offset: 0xf0
	// Line 895, Address: 0x2bf388, Func Offset: 0xf8
	// Line 893, Address: 0x2bf38c, Func Offset: 0xfc
	// Line 895, Address: 0x2bf390, Func Offset: 0x100
	// Line 892, Address: 0x2bf394, Func Offset: 0x104
	// Line 896, Address: 0x2bf398, Func Offset: 0x108
	// Line 893, Address: 0x2bf39c, Func Offset: 0x10c
	// Line 895, Address: 0x2bf3a4, Func Offset: 0x114
	// Line 894, Address: 0x2bf3a8, Func Offset: 0x118
	// Line 895, Address: 0x2bf3ac, Func Offset: 0x11c
	// Line 896, Address: 0x2bf3b4, Func Offset: 0x124
	// Line 897, Address: 0x2bf3bc, Func Offset: 0x12c
	// Line 899, Address: 0x2bf3d0, Func Offset: 0x140
	// Line 898, Address: 0x2bf3d4, Func Offset: 0x144
	// Line 899, Address: 0x2bf3dc, Func Offset: 0x14c
	// Line 901, Address: 0x2bf3e0, Func Offset: 0x150
	// Line 903, Address: 0x2bf3e4, Func Offset: 0x154
	// Line 900, Address: 0x2bf3ec, Func Offset: 0x15c
	// Line 901, Address: 0x2bf3f0, Func Offset: 0x160
	// Line 899, Address: 0x2bf3f4, Func Offset: 0x164
	// Line 903, Address: 0x2bf3f8, Func Offset: 0x168
	// Line 900, Address: 0x2bf400, Func Offset: 0x170
	// Line 903, Address: 0x2bf404, Func Offset: 0x174
	// Line 900, Address: 0x2bf408, Func Offset: 0x178
	// Line 903, Address: 0x2bf40c, Func Offset: 0x17c
	// Line 906, Address: 0x2bf410, Func Offset: 0x180
	// Line 900, Address: 0x2bf418, Func Offset: 0x188
	// Line 905, Address: 0x2bf41c, Func Offset: 0x18c
	// Line 900, Address: 0x2bf420, Func Offset: 0x190
	// Line 903, Address: 0x2bf424, Func Offset: 0x194
	// Line 902, Address: 0x2bf428, Func Offset: 0x198
	// Line 904, Address: 0x2bf42c, Func Offset: 0x19c
	// Line 900, Address: 0x2bf430, Func Offset: 0x1a0
	// Line 905, Address: 0x2bf434, Func Offset: 0x1a4
	// Line 903, Address: 0x2bf438, Func Offset: 0x1a8
	// Line 905, Address: 0x2bf43c, Func Offset: 0x1ac
	// Line 901, Address: 0x2bf440, Func Offset: 0x1b0
	// Line 906, Address: 0x2bf448, Func Offset: 0x1b8
	// Line 903, Address: 0x2bf44c, Func Offset: 0x1bc
	// Line 901, Address: 0x2bf450, Func Offset: 0x1c0
	// Line 902, Address: 0x2bf458, Func Offset: 0x1c8
	// Line 903, Address: 0x2bf45c, Func Offset: 0x1cc
	// Line 905, Address: 0x2bf460, Func Offset: 0x1d0
	// Line 904, Address: 0x2bf464, Func Offset: 0x1d4
	// Line 905, Address: 0x2bf468, Func Offset: 0x1d8
	// Line 906, Address: 0x2bf470, Func Offset: 0x1e0
	// Line 907, Address: 0x2bf478, Func Offset: 0x1e8
	// Line 908, Address: 0x2bf48c, Func Offset: 0x1fc
	// Line 909, Address: 0x2bf494, Func Offset: 0x204
	// Func End, Address: 0x2bf4c4, Func Offset: 0x234
}

// 
// Start address: 0x2bf4d0
void bhDrawSpEvtComCharacter()
{
	float near;
	BH_PWORK* pp;
	_anon5 scrn;
	_anon7* ce;
	// Line 915, Address: 0x2bf4d0, Func Offset: 0
	// Line 916, Address: 0x2bf4f4, Func Offset: 0x24
	// Line 923, Address: 0x2bf4fc, Func Offset: 0x2c
	// Line 922, Address: 0x2bf504, Func Offset: 0x34
	// Line 923, Address: 0x2bf50c, Func Offset: 0x3c
	// Line 916, Address: 0x2bf514, Func Offset: 0x44
	// Line 923, Address: 0x2bf51c, Func Offset: 0x4c
	// Line 926, Address: 0x2bf524, Func Offset: 0x54
	// Line 927, Address: 0x2bf52c, Func Offset: 0x5c
	// Line 928, Address: 0x2bf538, Func Offset: 0x68
	// Line 929, Address: 0x2bf544, Func Offset: 0x74
	// Line 930, Address: 0x2bf550, Func Offset: 0x80
	// Line 931, Address: 0x2bf558, Func Offset: 0x88
	// Line 933, Address: 0x2bf564, Func Offset: 0x94
	// Line 934, Address: 0x2bf578, Func Offset: 0xa8
	// Line 933, Address: 0x2bf57c, Func Offset: 0xac
	// Line 934, Address: 0x2bf5ac, Func Offset: 0xdc
	// Line 935, Address: 0x2bf5b0, Func Offset: 0xe0
	// Line 936, Address: 0x2bf5b8, Func Offset: 0xe8
	// Line 937, Address: 0x2bf5c4, Func Offset: 0xf4
	// Line 939, Address: 0x2bf5d0, Func Offset: 0x100
	// Line 940, Address: 0x2bf5e8, Func Offset: 0x118
	// Line 949, Address: 0x2bf5f4, Func Offset: 0x124
	// Line 953, Address: 0x2bf5f8, Func Offset: 0x128
	// Line 949, Address: 0x2bf5fc, Func Offset: 0x12c
	// Line 950, Address: 0x2bf604, Func Offset: 0x134
	// Line 951, Address: 0x2bf610, Func Offset: 0x140
	// Line 953, Address: 0x2bf61c, Func Offset: 0x14c
	// Line 954, Address: 0x2bf628, Func Offset: 0x158
	// Line 955, Address: 0x2bf640, Func Offset: 0x170
	// Line 957, Address: 0x2bf65c, Func Offset: 0x18c
	// Line 967, Address: 0x2bf67c, Func Offset: 0x1ac
	// Line 968, Address: 0x2bf690, Func Offset: 0x1c0
	// Line 970, Address: 0x2bf6a4, Func Offset: 0x1d4
	// Line 971, Address: 0x2bf6c0, Func Offset: 0x1f0
	// Line 974, Address: 0x2bf6d8, Func Offset: 0x208
	// Line 976, Address: 0x2bf6e4, Func Offset: 0x214
	// Line 977, Address: 0x2bf6f4, Func Offset: 0x224
	// Line 978, Address: 0x2bf704, Func Offset: 0x234
	// Line 983, Address: 0x2bf714, Func Offset: 0x244
	// Line 984, Address: 0x2bf72c, Func Offset: 0x25c
	// Line 987, Address: 0x2bf738, Func Offset: 0x268
	// Line 988, Address: 0x2bf744, Func Offset: 0x274
	// Line 989, Address: 0x2bf74c, Func Offset: 0x27c
	// Line 990, Address: 0x2bf754, Func Offset: 0x284
	// Line 991, Address: 0x2bf75c, Func Offset: 0x28c
	// Line 992, Address: 0x2bf760, Func Offset: 0x290
	// Line 994, Address: 0x2bf76c, Func Offset: 0x29c
	// Line 996, Address: 0x2bf77c, Func Offset: 0x2ac
	// Func End, Address: 0x2bf7a4, Func Offset: 0x2d4
}

// 
// Start address: 0x2bf7b0
void bhSetSpEvtComFade(float fdst, float fcnt)
{
	_anon7* ce;
	// Line 1003, Address: 0x2bf7b0, Func Offset: 0
	// Line 1004, Address: 0x2bf7c4, Func Offset: 0x14
	// Line 1005, Address: 0x2bf7c8, Func Offset: 0x18
	// Line 1007, Address: 0x2bf7cc, Func Offset: 0x1c
	// Line 1005, Address: 0x2bf7d0, Func Offset: 0x20
	// Line 1006, Address: 0x2bf7dc, Func Offset: 0x2c
	// Line 1007, Address: 0x2bf7e0, Func Offset: 0x30
	// Line 1008, Address: 0x2bf7fc, Func Offset: 0x4c
	// Func End, Address: 0x2bf804, Func Offset: 0x54
}

// 
// Start address: 0x2bf810
void bhCalcSpEvtComFade()
{
	int nn;
	_anon7* ce;
	// Line 1014, Address: 0x2bf810, Func Offset: 0
	// Line 1019, Address: 0x2bf814, Func Offset: 0x4
	// Line 1014, Address: 0x2bf818, Func Offset: 0x8
	// Line 1015, Address: 0x2bf820, Func Offset: 0x10
	// Line 1018, Address: 0x2bf828, Func Offset: 0x18
	// Line 1015, Address: 0x2bf830, Func Offset: 0x20
	// Line 1017, Address: 0x2bf83c, Func Offset: 0x2c
	// Line 1018, Address: 0x2bf84c, Func Offset: 0x3c
	// Line 1019, Address: 0x2bf854, Func Offset: 0x44
	// Line 1020, Address: 0x2bf864, Func Offset: 0x54
	// Line 1021, Address: 0x2bf88c, Func Offset: 0x7c
	// Line 1023, Address: 0x2bf894, Func Offset: 0x84
	// Line 1024, Address: 0x2bf8ac, Func Offset: 0x9c
	// Line 1025, Address: 0x2bf8b8, Func Offset: 0xa8
	// Line 1026, Address: 0x2bf8c8, Func Offset: 0xb8
	// Line 1027, Address: 0x2bf8d0, Func Offset: 0xc0
	// Func End, Address: 0x2bf8e0, Func Offset: 0xd0
}

// 
// Start address: 0x2bf8e0
void bhDrawSpEvtComFade()
{
	_anon26 col[4];
	_anon37 p[4];
	_anon43 p2c;
	_anon7* ce;
	// Line 1033, Address: 0x2bf8e0, Func Offset: 0
	// Line 1034, Address: 0x2bf8e8, Func Offset: 0x8
	// Line 1038, Address: 0x2bf8f0, Func Offset: 0x10
	// Line 1039, Address: 0x2bf8f4, Func Offset: 0x14
	// Line 1034, Address: 0x2bf8fc, Func Offset: 0x1c
	// Line 1054, Address: 0x2bf908, Func Offset: 0x28
	// Line 1041, Address: 0x2bf910, Func Offset: 0x30
	// Line 1054, Address: 0x2bf914, Func Offset: 0x34
	// Line 1048, Address: 0x2bf918, Func Offset: 0x38
	// Line 1038, Address: 0x2bf91c, Func Offset: 0x3c
	// Line 1039, Address: 0x2bf920, Func Offset: 0x40
	// Line 1040, Address: 0x2bf924, Func Offset: 0x44
	// Line 1041, Address: 0x2bf928, Func Offset: 0x48
	// Line 1042, Address: 0x2bf92c, Func Offset: 0x4c
	// Line 1051, Address: 0x2bf934, Func Offset: 0x54
	// Line 1054, Address: 0x2bf938, Func Offset: 0x58
	// Line 1042, Address: 0x2bf940, Func Offset: 0x60
	// Line 1043, Address: 0x2bf944, Func Offset: 0x64
	// Line 1054, Address: 0x2bf94c, Func Offset: 0x6c
	// Line 1043, Address: 0x2bf950, Func Offset: 0x70
	// Line 1044, Address: 0x2bf954, Func Offset: 0x74
	// Line 1045, Address: 0x2bf960, Func Offset: 0x80
	// Line 1046, Address: 0x2bf96c, Func Offset: 0x8c
	// Line 1047, Address: 0x2bf970, Func Offset: 0x90
	// Line 1048, Address: 0x2bf974, Func Offset: 0x94
	// Line 1049, Address: 0x2bf978, Func Offset: 0x98
	// Line 1050, Address: 0x2bf97c, Func Offset: 0x9c
	// Line 1051, Address: 0x2bf980, Func Offset: 0xa0
	// Line 1052, Address: 0x2bf984, Func Offset: 0xa4
	// Line 1054, Address: 0x2bf988, Func Offset: 0xa8
	// Line 1055, Address: 0x2bf990, Func Offset: 0xb0
	// Func End, Address: 0x2bf99c, Func Offset: 0xbc
}

// 
// Start address: 0x2bf9a0
void bhEntrySpEvtBoxLine(_anon41* line)
{
	int i;
	_anon7* ce;
	// Line 1062, Address: 0x2bf9a0, Func Offset: 0
	// Line 1064, Address: 0x2bf9a8, Func Offset: 0x8
	// Line 1062, Address: 0x2bf9ac, Func Offset: 0xc
	// Line 1065, Address: 0x2bf9bc, Func Offset: 0x1c
	// Line 1066, Address: 0x2bf9cc, Func Offset: 0x2c
	// Line 1067, Address: 0x2bf9dc, Func Offset: 0x3c
	// Line 1073, Address: 0x2bf9f0, Func Offset: 0x50
	// Line 1067, Address: 0x2bf9f4, Func Offset: 0x54
	// Line 1068, Address: 0x2bf9f8, Func Offset: 0x58
	// Line 1073, Address: 0x2bf9fc, Func Offset: 0x5c
	// Line 1068, Address: 0x2bfa00, Func Offset: 0x60
	// Line 1069, Address: 0x2bfa04, Func Offset: 0x64
	// Line 1070, Address: 0x2bfa0c, Func Offset: 0x6c
	// Line 1071, Address: 0x2bfa14, Func Offset: 0x74
	// Line 1072, Address: 0x2bfa1c, Func Offset: 0x7c
	// Line 1074, Address: 0x2bfa24, Func Offset: 0x84
	// Line 1076, Address: 0x2bfa2c, Func Offset: 0x8c
	// Line 1077, Address: 0x2bfa40, Func Offset: 0xa0
	// Func End, Address: 0x2bfa48, Func Offset: 0xa8
}

// 
// Start address: 0x2bfa50
void bhDrawSpEvtBoxLine()
{
	unsigned int argb;
	int i;
	_anon26 col[4];
	_anon37 p[4];
	_anon43 p2c;
	_anon7* ce;
	// Line 1083, Address: 0x2bfa50, Func Offset: 0
	// Line 1084, Address: 0x2bfa6c, Func Offset: 0x1c
	// Line 1090, Address: 0x2bfa74, Func Offset: 0x24
	// Line 1091, Address: 0x2bfa78, Func Offset: 0x28
	// Line 1084, Address: 0x2bfa80, Func Offset: 0x30
	// Line 1093, Address: 0x2bfa8c, Func Offset: 0x3c
	// Line 1094, Address: 0x2bfa90, Func Offset: 0x40
	// Line 1090, Address: 0x2bfa94, Func Offset: 0x44
	// Line 1091, Address: 0x2bfa98, Func Offset: 0x48
	// Line 1092, Address: 0x2bfa9c, Func Offset: 0x4c
	// Line 1093, Address: 0x2bfaa0, Func Offset: 0x50
	// Line 1095, Address: 0x2bfaac, Func Offset: 0x5c
	// Line 1096, Address: 0x2bfabc, Func Offset: 0x6c
	// Line 1109, Address: 0x2bfac0, Func Offset: 0x70
	// Line 1097, Address: 0x2bfacc, Func Offset: 0x7c
	// Line 1109, Address: 0x2bfad0, Func Offset: 0x80
	// Line 1096, Address: 0x2bfad4, Func Offset: 0x84
	// Line 1097, Address: 0x2bfaec, Func Offset: 0x9c
	// Line 1098, Address: 0x2bfaf0, Func Offset: 0xa0
	// Line 1109, Address: 0x2bfaf4, Func Offset: 0xa4
	// Line 1098, Address: 0x2bfafc, Func Offset: 0xac
	// Line 1099, Address: 0x2bfb00, Func Offset: 0xb0
	// Line 1100, Address: 0x2bfb08, Func Offset: 0xb8
	// Line 1101, Address: 0x2bfb10, Func Offset: 0xc0
	// Line 1102, Address: 0x2bfb18, Func Offset: 0xc8
	// Line 1103, Address: 0x2bfb20, Func Offset: 0xd0
	// Line 1104, Address: 0x2bfb30, Func Offset: 0xe0
	// Line 1105, Address: 0x2bfb38, Func Offset: 0xe8
	// Line 1106, Address: 0x2bfb48, Func Offset: 0xf8
	// Line 1107, Address: 0x2bfb58, Func Offset: 0x108
	// Line 1108, Address: 0x2bfb60, Func Offset: 0x110
	// Line 1109, Address: 0x2bfb6c, Func Offset: 0x11c
	// Line 1110, Address: 0x2bfb74, Func Offset: 0x124
	// Line 1111, Address: 0x2bfb80, Func Offset: 0x130
	// Line 1113, Address: 0x2bfb90, Func Offset: 0x140
	// Line 1111, Address: 0x2bfb98, Func Offset: 0x148
	// Line 1113, Address: 0x2bfba0, Func Offset: 0x150
	// Line 1114, Address: 0x2bfba8, Func Offset: 0x158
	// Func End, Address: 0x2bfbc8, Func Offset: 0x178
}

// 
// Start address: 0x2bfbd0
void bhClearComEvtText()
{
	// Line 1122, Address: 0x2bfbd0, Func Offset: 0
	// Func End, Address: 0x2bfbf4, Func Offset: 0x24
}

// 
// Start address: 0x2bfc00
void bhInitComEvtScript()
{
	int end;
	unsigned char cmd;
	unsigned char* scp;
	_anon7* ce;
	// Line 1129, Address: 0x2bfc00, Func Offset: 0
	// Line 1130, Address: 0x2bfc14, Func Offset: 0x14
	// Line 1133, Address: 0x2bfc1c, Func Offset: 0x1c
	// Line 1135, Address: 0x2bfc24, Func Offset: 0x24
	// Line 1130, Address: 0x2bfc28, Func Offset: 0x28
	// Line 1131, Address: 0x2bfc34, Func Offset: 0x34
	// Line 1133, Address: 0x2bfc38, Func Offset: 0x38
	// Line 1134, Address: 0x2bfc3c, Func Offset: 0x3c
	// Line 1138, Address: 0x2bfc40, Func Offset: 0x40
	// Line 1137, Address: 0x2bfc78, Func Offset: 0x78
	// Line 1138, Address: 0x2bfc7c, Func Offset: 0x7c
	// Line 1140, Address: 0x2bfcf4, Func Offset: 0xf4
	// Line 1141, Address: 0x2bfcf8, Func Offset: 0xf8
	// Line 1143, Address: 0x2bfd00, Func Offset: 0x100
	// Line 1144, Address: 0x2bfd04, Func Offset: 0x104
	// Line 1148, Address: 0x2bfd0c, Func Offset: 0x10c
	// Line 1149, Address: 0x2bfd10, Func Offset: 0x110
	// Line 1151, Address: 0x2bfd18, Func Offset: 0x118
	// Line 1152, Address: 0x2bfd1c, Func Offset: 0x11c
	// Line 1155, Address: 0x2bfd24, Func Offset: 0x124
	// Line 1156, Address: 0x2bfd28, Func Offset: 0x128
	// Line 1160, Address: 0x2bfd30, Func Offset: 0x130
	// Line 1161, Address: 0x2bfd34, Func Offset: 0x134
	// Line 1163, Address: 0x2bfd3c, Func Offset: 0x13c
	// Line 1164, Address: 0x2bfd4c, Func Offset: 0x14c
	// Line 1165, Address: 0x2bfd50, Func Offset: 0x150
	// Line 1167, Address: 0x2bfd58, Func Offset: 0x158
	// Line 1168, Address: 0x2bfd5c, Func Offset: 0x15c
	// Line 1171, Address: 0x2bfd64, Func Offset: 0x164
	// Line 1172, Address: 0x2bfd68, Func Offset: 0x168
	// Line 1177, Address: 0x2bfd70, Func Offset: 0x170
	// Line 1178, Address: 0x2bfd74, Func Offset: 0x174
	// Line 1181, Address: 0x2bfd7c, Func Offset: 0x17c
	// Line 1182, Address: 0x2bfd80, Func Offset: 0x180
	// Line 1185, Address: 0x2bfd88, Func Offset: 0x188
	// Line 1186, Address: 0x2bfd8c, Func Offset: 0x18c
	// Line 1189, Address: 0x2bfd94, Func Offset: 0x194
	// Line 1190, Address: 0x2bfd98, Func Offset: 0x198
	// Line 1192, Address: 0x2bfda0, Func Offset: 0x1a0
	// Line 1194, Address: 0x2bfda4, Func Offset: 0x1a4
	// Line 1195, Address: 0x2bfda8, Func Offset: 0x1a8
	// Line 1196, Address: 0x2bfdb0, Func Offset: 0x1b0
	// Func End, Address: 0x2bfdc8, Func Offset: 0x1c8
}

// 
// Start address: 0x2bfdd0
void bhControlComEvtScript()
{
	char* wcpb;
	char* wcpa;
	unsigned short flgno;
	unsigned int* mstb;
	unsigned int bit;
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char cmd;
	_anon7* ce;
	// Line 1202, Address: 0x2bfdd0, Func Offset: 0
	// Line 1203, Address: 0x2bfde0, Func Offset: 0x10
	// Line 1209, Address: 0x2bfdf4, Func Offset: 0x24
	// Line 1211, Address: 0x2bfe24, Func Offset: 0x54
	// Line 1212, Address: 0x2bfe2c, Func Offset: 0x5c
	// Line 1213, Address: 0x2bfe38, Func Offset: 0x68
	// Line 1215, Address: 0x2bfe50, Func Offset: 0x80
	// Line 1217, Address: 0x2bfe5c, Func Offset: 0x8c
	// Line 1219, Address: 0x2bfe64, Func Offset: 0x94
	// Line 1220, Address: 0x2bfe6c, Func Offset: 0x9c
	// Line 1221, Address: 0x2bfe74, Func Offset: 0xa4
	// Line 1222, Address: 0x2bfe78, Func Offset: 0xa8
	// Line 1221, Address: 0x2bfe84, Func Offset: 0xb4
	// Line 1222, Address: 0x2bfec4, Func Offset: 0xf4
	// Line 1223, Address: 0x2bfecc, Func Offset: 0xfc
	// Line 1224, Address: 0x2bfed8, Func Offset: 0x108
	// Line 1227, Address: 0x2bfef8, Func Offset: 0x128
	// Line 1228, Address: 0x2bff04, Func Offset: 0x134
	// Line 1229, Address: 0x2bff08, Func Offset: 0x138
	// Line 1231, Address: 0x2bff10, Func Offset: 0x140
	// Line 1232, Address: 0x2bff20, Func Offset: 0x150
	// Line 1234, Address: 0x2bff48, Func Offset: 0x178
	// Line 1237, Address: 0x2bff4c, Func Offset: 0x17c
	// Line 1234, Address: 0x2bff58, Func Offset: 0x188
	// Line 1235, Address: 0x2bff60, Func Offset: 0x190
	// Line 1237, Address: 0x2bff74, Func Offset: 0x1a4
	// Line 1238, Address: 0x2bffa0, Func Offset: 0x1d0
	// Line 1240, Address: 0x2bffa8, Func Offset: 0x1d8
	// Line 1241, Address: 0x2bffb8, Func Offset: 0x1e8
	// Line 1243, Address: 0x2bffc0, Func Offset: 0x1f0
	// Line 1244, Address: 0x2bffc8, Func Offset: 0x1f8
	// Line 1246, Address: 0x2bffd0, Func Offset: 0x200
	// Line 1247, Address: 0x2bffe0, Func Offset: 0x210
	// Line 1249, Address: 0x2bffe4, Func Offset: 0x214
	// Line 1247, Address: 0x2bffec, Func Offset: 0x21c
	// Line 1248, Address: 0x2bfff8, Func Offset: 0x228
	// Line 1249, Address: 0x2bfffc, Func Offset: 0x22c
	// Line 1248, Address: 0x2c0008, Func Offset: 0x238
	// Line 1249, Address: 0x2c0014, Func Offset: 0x244
	// Line 1250, Address: 0x2c0020, Func Offset: 0x250
	// Line 1252, Address: 0x2c0028, Func Offset: 0x258
	// Line 1253, Address: 0x2c002c, Func Offset: 0x25c
	// Line 1252, Address: 0x2c0038, Func Offset: 0x268
	// Line 1253, Address: 0x2c0078, Func Offset: 0x2a8
	// Line 1254, Address: 0x2c0080, Func Offset: 0x2b0
	// Line 1255, Address: 0x2c0088, Func Offset: 0x2b8
	// Line 1257, Address: 0x2c0090, Func Offset: 0x2c0
	// Line 1258, Address: 0x2c00a4, Func Offset: 0x2d4
	// Line 1259, Address: 0x2c00e4, Func Offset: 0x314
	// Line 1260, Address: 0x2c0108, Func Offset: 0x338
	// Line 1262, Address: 0x2c010c, Func Offset: 0x33c
	// Line 1265, Address: 0x2c0110, Func Offset: 0x340
	// Line 1267, Address: 0x2c0114, Func Offset: 0x344
	// Line 1260, Address: 0x2c0118, Func Offset: 0x348
	// Line 1261, Address: 0x2c011c, Func Offset: 0x34c
	// Line 1272, Address: 0x2c0120, Func Offset: 0x350
	// Line 1261, Address: 0x2c012c, Func Offset: 0x35c
	// Line 1262, Address: 0x2c0130, Func Offset: 0x360
	// Line 1263, Address: 0x2c0150, Func Offset: 0x380
	// Line 1264, Address: 0x2c015c, Func Offset: 0x38c
	// Line 1265, Address: 0x2c0168, Func Offset: 0x398
	// Line 1266, Address: 0x2c016c, Func Offset: 0x39c
	// Line 1267, Address: 0x2c0170, Func Offset: 0x3a0
	// Line 1268, Address: 0x2c0174, Func Offset: 0x3a4
	// Line 1269, Address: 0x2c0178, Func Offset: 0x3a8
	// Line 1270, Address: 0x2c017c, Func Offset: 0x3ac
	// Line 1272, Address: 0x2c0180, Func Offset: 0x3b0
	// Line 1273, Address: 0x2c0188, Func Offset: 0x3b8
	// Line 1274, Address: 0x2c019c, Func Offset: 0x3cc
	// Line 1276, Address: 0x2c01a4, Func Offset: 0x3d4
	// Line 1278, Address: 0x2c01ac, Func Offset: 0x3dc
	// Line 1276, Address: 0x2c01b0, Func Offset: 0x3e0
	// Line 1278, Address: 0x2c01b4, Func Offset: 0x3e4
	// Line 1277, Address: 0x2c01b8, Func Offset: 0x3e8
	// Line 1276, Address: 0x2c01bc, Func Offset: 0x3ec
	// Line 1278, Address: 0x2c01c8, Func Offset: 0x3f8
	// Line 1276, Address: 0x2c01cc, Func Offset: 0x3fc
	// Line 1278, Address: 0x2c01dc, Func Offset: 0x40c
	// Line 1279, Address: 0x2c01e4, Func Offset: 0x414
	// Line 1280, Address: 0x2c01f8, Func Offset: 0x428
	// Line 1283, Address: 0x2c0200, Func Offset: 0x430
	// Line 1284, Address: 0x2c0214, Func Offset: 0x444
	// Line 1285, Address: 0x2c0228, Func Offset: 0x458
	// Line 1287, Address: 0x2c0230, Func Offset: 0x460
	// Line 1289, Address: 0x2c0238, Func Offset: 0x468
	// Line 1287, Address: 0x2c023c, Func Offset: 0x46c
	// Line 1289, Address: 0x2c0240, Func Offset: 0x470
	// Line 1288, Address: 0x2c0244, Func Offset: 0x474
	// Line 1287, Address: 0x2c0248, Func Offset: 0x478
	// Line 1289, Address: 0x2c0254, Func Offset: 0x484
	// Line 1287, Address: 0x2c0258, Func Offset: 0x488
	// Line 1289, Address: 0x2c0268, Func Offset: 0x498
	// Line 1290, Address: 0x2c0270, Func Offset: 0x4a0
	// Line 1291, Address: 0x2c0284, Func Offset: 0x4b4
	// Line 1293, Address: 0x2c028c, Func Offset: 0x4bc
	// Line 1294, Address: 0x2c0294, Func Offset: 0x4c4
	// Line 1296, Address: 0x2c029c, Func Offset: 0x4cc
	// Line 1297, Address: 0x2c02ac, Func Offset: 0x4dc
	// Line 1296, Address: 0x2c02b0, Func Offset: 0x4e0
	// Line 1297, Address: 0x2c02bc, Func Offset: 0x4ec
	// Line 1296, Address: 0x2c02c0, Func Offset: 0x4f0
	// Line 1297, Address: 0x2c02cc, Func Offset: 0x4fc
	// Line 1298, Address: 0x2c02d4, Func Offset: 0x504
	// Line 1297, Address: 0x2c02d8, Func Offset: 0x508
	// Line 1298, Address: 0x2c02e4, Func Offset: 0x514
	// Line 1299, Address: 0x2c02f8, Func Offset: 0x528
	// Line 1298, Address: 0x2c02fc, Func Offset: 0x52c
	// Line 1299, Address: 0x2c0300, Func Offset: 0x530
	// Line 1300, Address: 0x2c0308, Func Offset: 0x538
	// Line 1301, Address: 0x2c0318, Func Offset: 0x548
	// Line 1304, Address: 0x2c0328, Func Offset: 0x558
	// Line 1305, Address: 0x2c0330, Func Offset: 0x560
	// Line 1309, Address: 0x2c0344, Func Offset: 0x574
	// Line 1311, Address: 0x2c034c, Func Offset: 0x57c
	// Line 1312, Address: 0x2c0354, Func Offset: 0x584
	// Line 1314, Address: 0x2c035c, Func Offset: 0x58c
	// Line 1315, Address: 0x2c0378, Func Offset: 0x5a8
	// Line 1317, Address: 0x2c0380, Func Offset: 0x5b0
	// Line 1318, Address: 0x2c0384, Func Offset: 0x5b4
	// Line 1317, Address: 0x2c0388, Func Offset: 0x5b8
	// Line 1318, Address: 0x2c0394, Func Offset: 0x5c4
	// Line 1320, Address: 0x2c03a8, Func Offset: 0x5d8
	// Line 1323, Address: 0x2c03cc, Func Offset: 0x5fc
	// Line 1324, Address: 0x2c03d4, Func Offset: 0x604
	// Line 1326, Address: 0x2c03dc, Func Offset: 0x60c
	// Line 1335, Address: 0x2c03e4, Func Offset: 0x614
	// Line 1336, Address: 0x2c03ec, Func Offset: 0x61c
	// Line 1337, Address: 0x2c03f4, Func Offset: 0x624
	// Line 1326, Address: 0x2c03f8, Func Offset: 0x628
	// Line 1327, Address: 0x2c0414, Func Offset: 0x644
	// Line 1328, Address: 0x2c0428, Func Offset: 0x658
	// Line 1329, Address: 0x2c0440, Func Offset: 0x670
	// Line 1330, Address: 0x2c0458, Func Offset: 0x688
	// Line 1334, Address: 0x2c0470, Func Offset: 0x6a0
	// Line 1335, Address: 0x2c0474, Func Offset: 0x6a4
	// Line 1336, Address: 0x2c0478, Func Offset: 0x6a8
	// Line 1337, Address: 0x2c047c, Func Offset: 0x6ac
	// Line 1338, Address: 0x2c0480, Func Offset: 0x6b0
	// Line 1340, Address: 0x2c0484, Func Offset: 0x6b4
	// Line 1342, Address: 0x2c048c, Func Offset: 0x6bc
	// Line 1343, Address: 0x2c04a0, Func Offset: 0x6d0
	// Line 1344, Address: 0x2c04b0, Func Offset: 0x6e0
	// Line 1346, Address: 0x2c04b8, Func Offset: 0x6e8
	// Line 1348, Address: 0x2c04bc, Func Offset: 0x6ec
	// Line 1346, Address: 0x2c04c0, Func Offset: 0x6f0
	// Line 1347, Address: 0x2c04cc, Func Offset: 0x6fc
	// Line 1348, Address: 0x2c04dc, Func Offset: 0x70c
	// Line 1347, Address: 0x2c04e0, Func Offset: 0x710
	// Line 1348, Address: 0x2c04e8, Func Offset: 0x718
	// Line 1349, Address: 0x2c04f4, Func Offset: 0x724
	// Line 1351, Address: 0x2c04fc, Func Offset: 0x72c
	// Line 1353, Address: 0x2c0500, Func Offset: 0x730
	// Line 1351, Address: 0x2c0504, Func Offset: 0x734
	// Line 1352, Address: 0x2c0514, Func Offset: 0x744
	// Line 1353, Address: 0x2c0528, Func Offset: 0x758
	// Line 1354, Address: 0x2c0544, Func Offset: 0x774
	// Line 1356, Address: 0x2c054c, Func Offset: 0x77c
	// Line 1357, Address: 0x2c0570, Func Offset: 0x7a0
	// Line 1360, Address: 0x2c0578, Func Offset: 0x7a8
	// Line 1362, Address: 0x2c0580, Func Offset: 0x7b0
	// Line 1363, Address: 0x2c05a4, Func Offset: 0x7d4
	// Line 1365, Address: 0x2c05ac, Func Offset: 0x7dc
	// Line 1366, Address: 0x2c05cc, Func Offset: 0x7fc
	// Line 1368, Address: 0x2c05d4, Func Offset: 0x804
	// Line 1369, Address: 0x2c05e4, Func Offset: 0x814
	// Line 1370, Address: 0x2c05e8, Func Offset: 0x818
	// Line 1371, Address: 0x2c05f4, Func Offset: 0x824
	// Line 1373, Address: 0x2c0604, Func Offset: 0x834
	// Line 1374, Address: 0x2c0608, Func Offset: 0x838
	// Line 1377, Address: 0x2c0614, Func Offset: 0x844
	// Line 1379, Address: 0x2c061c, Func Offset: 0x84c
	// Line 1380, Address: 0x2c0620, Func Offset: 0x850
	// Line 1383, Address: 0x2c0638, Func Offset: 0x868
	// Func End, Address: 0x2c064c, Func Offset: 0x87c
}

// 
// Start address: 0x2c0650
void bhControlComEvtKeyboard()
{
	int adt;
	int sel;
	int i;
	_anon7* ce;
	// Line 1389, Address: 0x2c0650, Func Offset: 0
	// Line 1390, Address: 0x2c0660, Func Offset: 0x10
	// Line 1395, Address: 0x2c0674, Func Offset: 0x24
	// Line 1397, Address: 0x2c06ac, Func Offset: 0x5c
	// Line 1398, Address: 0x2c06b8, Func Offset: 0x68
	// Line 1399, Address: 0x2c06c8, Func Offset: 0x78
	// Line 1400, Address: 0x2c06cc, Func Offset: 0x7c
	// Line 1403, Address: 0x2c06d4, Func Offset: 0x84
	// Line 1404, Address: 0x2c06d8, Func Offset: 0x88
	// Line 1406, Address: 0x2c06dc, Func Offset: 0x8c
	// Line 1407, Address: 0x2c0708, Func Offset: 0xb8
	// Line 1408, Address: 0x2c0714, Func Offset: 0xc4
	// Line 1409, Address: 0x2c0724, Func Offset: 0xd4
	// Line 1411, Address: 0x2c072c, Func Offset: 0xdc
	// Line 1412, Address: 0x2c073c, Func Offset: 0xec
	// Line 1413, Address: 0x2c074c, Func Offset: 0xfc
	// Line 1414, Address: 0x2c0750, Func Offset: 0x100
	// Line 1417, Address: 0x2c0758, Func Offset: 0x108
	// Line 1418, Address: 0x2c075c, Func Offset: 0x10c
	// Line 1420, Address: 0x2c0760, Func Offset: 0x110
	// Line 1422, Address: 0x2c0764, Func Offset: 0x114
	// Line 1420, Address: 0x2c0770, Func Offset: 0x120
	// Line 1421, Address: 0x2c0778, Func Offset: 0x128
	// Line 1422, Address: 0x2c0780, Func Offset: 0x130
	// Line 1423, Address: 0x2c0788, Func Offset: 0x138
	// Line 1425, Address: 0x2c0790, Func Offset: 0x140
	// Line 1426, Address: 0x2c07a0, Func Offset: 0x150
	// Line 1427, Address: 0x2c07b0, Func Offset: 0x160
	// Line 1428, Address: 0x2c07b4, Func Offset: 0x164
	// Line 1431, Address: 0x2c07bc, Func Offset: 0x16c
	// Line 1432, Address: 0x2c07c0, Func Offset: 0x170
	// Line 1434, Address: 0x2c07c4, Func Offset: 0x174
	// Line 1435, Address: 0x2c07c8, Func Offset: 0x178
	// Line 1434, Address: 0x2c07d4, Func Offset: 0x184
	// Line 1435, Address: 0x2c07d8, Func Offset: 0x188
	// Line 1436, Address: 0x2c07e0, Func Offset: 0x190
	// Line 1438, Address: 0x2c07e8, Func Offset: 0x198
	// Line 1439, Address: 0x2c07f8, Func Offset: 0x1a8
	// Line 1440, Address: 0x2c0808, Func Offset: 0x1b8
	// Line 1441, Address: 0x2c080c, Func Offset: 0x1bc
	// Line 1444, Address: 0x2c0814, Func Offset: 0x1c4
	// Line 1445, Address: 0x2c0818, Func Offset: 0x1c8
	// Line 1447, Address: 0x2c081c, Func Offset: 0x1cc
	// Line 1449, Address: 0x2c0820, Func Offset: 0x1d0
	// Line 1447, Address: 0x2c082c, Func Offset: 0x1dc
	// Line 1448, Address: 0x2c0834, Func Offset: 0x1e4
	// Line 1449, Address: 0x2c083c, Func Offset: 0x1ec
	// Line 1450, Address: 0x2c0844, Func Offset: 0x1f4
	// Line 1452, Address: 0x2c084c, Func Offset: 0x1fc
	// Line 1453, Address: 0x2c085c, Func Offset: 0x20c
	// Line 1454, Address: 0x2c086c, Func Offset: 0x21c
	// Line 1455, Address: 0x2c0870, Func Offset: 0x220
	// Line 1458, Address: 0x2c0878, Func Offset: 0x228
	// Line 1459, Address: 0x2c087c, Func Offset: 0x22c
	// Line 1461, Address: 0x2c0880, Func Offset: 0x230
	// Line 1462, Address: 0x2c08ac, Func Offset: 0x25c
	// Line 1463, Address: 0x2c08b8, Func Offset: 0x268
	// Line 1464, Address: 0x2c08c8, Func Offset: 0x278
	// Line 1466, Address: 0x2c08d0, Func Offset: 0x280
	// Line 1467, Address: 0x2c08e0, Func Offset: 0x290
	// Line 1468, Address: 0x2c08f0, Func Offset: 0x2a0
	// Line 1469, Address: 0x2c08f4, Func Offset: 0x2a4
	// Line 1472, Address: 0x2c08fc, Func Offset: 0x2ac
	// Line 1473, Address: 0x2c0900, Func Offset: 0x2b0
	// Line 1475, Address: 0x2c0904, Func Offset: 0x2b4
	// Line 1477, Address: 0x2c0908, Func Offset: 0x2b8
	// Line 1475, Address: 0x2c0914, Func Offset: 0x2c4
	// Line 1476, Address: 0x2c091c, Func Offset: 0x2cc
	// Line 1477, Address: 0x2c0924, Func Offset: 0x2d4
	// Line 1478, Address: 0x2c092c, Func Offset: 0x2dc
	// Line 1480, Address: 0x2c0934, Func Offset: 0x2e4
	// Line 1481, Address: 0x2c0944, Func Offset: 0x2f4
	// Line 1482, Address: 0x2c0954, Func Offset: 0x304
	// Line 1483, Address: 0x2c0958, Func Offset: 0x308
	// Line 1486, Address: 0x2c0960, Func Offset: 0x310
	// Line 1487, Address: 0x2c0964, Func Offset: 0x314
	// Line 1489, Address: 0x2c0968, Func Offset: 0x318
	// Line 1490, Address: 0x2c096c, Func Offset: 0x31c
	// Line 1489, Address: 0x2c0978, Func Offset: 0x328
	// Line 1490, Address: 0x2c097c, Func Offset: 0x32c
	// Line 1491, Address: 0x2c0984, Func Offset: 0x334
	// Line 1493, Address: 0x2c098c, Func Offset: 0x33c
	// Line 1494, Address: 0x2c099c, Func Offset: 0x34c
	// Line 1495, Address: 0x2c09ac, Func Offset: 0x35c
	// Line 1496, Address: 0x2c09b0, Func Offset: 0x360
	// Line 1499, Address: 0x2c09b8, Func Offset: 0x368
	// Line 1500, Address: 0x2c09bc, Func Offset: 0x36c
	// Line 1502, Address: 0x2c09c0, Func Offset: 0x370
	// Line 1504, Address: 0x2c09c4, Func Offset: 0x374
	// Line 1502, Address: 0x2c09d0, Func Offset: 0x380
	// Line 1503, Address: 0x2c09d8, Func Offset: 0x388
	// Line 1504, Address: 0x2c09e0, Func Offset: 0x390
	// Line 1505, Address: 0x2c09e8, Func Offset: 0x398
	// Line 1507, Address: 0x2c09f0, Func Offset: 0x3a0
	// Line 1508, Address: 0x2c09f8, Func Offset: 0x3a8
	// Line 1511, Address: 0x2c09fc, Func Offset: 0x3ac
	// Line 1512, Address: 0x2c0a10, Func Offset: 0x3c0
	// Line 1513, Address: 0x2c0a24, Func Offset: 0x3d4
	// Line 1514, Address: 0x2c0a38, Func Offset: 0x3e8
	// Line 1516, Address: 0x2c0a4c, Func Offset: 0x3fc
	// Line 1518, Address: 0x2c0a6c, Func Offset: 0x41c
	// Line 1520, Address: 0x2c0a70, Func Offset: 0x420
	// Line 1518, Address: 0x2c0a74, Func Offset: 0x424
	// Line 1519, Address: 0x2c0a7c, Func Offset: 0x42c
	// Line 1520, Address: 0x2c0a94, Func Offset: 0x444
	// Line 1522, Address: 0x2c0ac8, Func Offset: 0x478
	// Line 1523, Address: 0x2c0acc, Func Offset: 0x47c
	// Line 1524, Address: 0x2c0ae0, Func Offset: 0x490
	// Line 1526, Address: 0x2c0ae8, Func Offset: 0x498
	// Line 1527, Address: 0x2c0af4, Func Offset: 0x4a4
	// Line 1528, Address: 0x2c0b04, Func Offset: 0x4b4
	// Line 1529, Address: 0x2c0b10, Func Offset: 0x4c0
	// Line 1530, Address: 0x2c0b28, Func Offset: 0x4d8
	// Line 1531, Address: 0x2c0b34, Func Offset: 0x4e4
	// Line 1532, Address: 0x2c0b60, Func Offset: 0x510
	// Line 1535, Address: 0x2c0b68, Func Offset: 0x518
	// Line 1536, Address: 0x2c0b78, Func Offset: 0x528
	// Line 1537, Address: 0x2c0b88, Func Offset: 0x538
	// Line 1539, Address: 0x2c0b94, Func Offset: 0x544
	// Line 1541, Address: 0x2c0b9c, Func Offset: 0x54c
	// Line 1542, Address: 0x2c0bac, Func Offset: 0x55c
	// Line 1543, Address: 0x2c0bc0, Func Offset: 0x570
	// Line 1545, Address: 0x2c0bcc, Func Offset: 0x57c
	// Line 1546, Address: 0x2c0be4, Func Offset: 0x594
	// Line 1548, Address: 0x2c0bec, Func Offset: 0x59c
	// Line 1550, Address: 0x2c0bf8, Func Offset: 0x5a8
	// Line 1551, Address: 0x2c0c00, Func Offset: 0x5b0
	// Line 1553, Address: 0x2c0c0c, Func Offset: 0x5bc
	// Line 1554, Address: 0x2c0c14, Func Offset: 0x5c4
	// Line 1557, Address: 0x2c0c18, Func Offset: 0x5c8
	// Line 1559, Address: 0x2c0c1c, Func Offset: 0x5cc
	// Line 1560, Address: 0x2c0c24, Func Offset: 0x5d4
	// Line 1559, Address: 0x2c0c28, Func Offset: 0x5d8
	// Line 1560, Address: 0x2c0c54, Func Offset: 0x604
	// Line 1561, Address: 0x2c0c6c, Func Offset: 0x61c
	// Line 1562, Address: 0x2c0c84, Func Offset: 0x634
	// Line 1563, Address: 0x2c0c90, Func Offset: 0x640
	// Line 1568, Address: 0x2c0c9c, Func Offset: 0x64c
	// Line 1569, Address: 0x2c0cbc, Func Offset: 0x66c
	// Line 1570, Address: 0x2c0cc4, Func Offset: 0x674
	// Line 1571, Address: 0x2c0d00, Func Offset: 0x6b0
	// Line 1572, Address: 0x2c0d0c, Func Offset: 0x6bc
	// Line 1573, Address: 0x2c0d10, Func Offset: 0x6c0
	// Line 1575, Address: 0x2c0d28, Func Offset: 0x6d8
	// Func End, Address: 0x2c0d3c, Func Offset: 0x6ec
}*/

