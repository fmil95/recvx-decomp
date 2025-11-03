#ifndef _MAIN_H_
#define _MAIN_H_

extern CAM_WORK cam;
extern ROM_WORK* rom;
extern float fVu1Projection;
extern sceVu0FMATRIX ClipMatrix2;
extern float _fNaViwClipNear;
extern float _fNaViwClipFar;
extern float fNaViwClipNear;
extern float fNaViwClipFar;
extern NJS_MATRIX NaViwViewMatrix;
extern NJS_SCREEN	_nj_screen_;
extern unsigned char* njpmemp;
extern NJS_MATRIX* cmat;
extern unsigned int palbuf[4096];
extern float Ps2_zbuff_a;
extern float Ps2_zbuff_b;
extern float SinTable[16384];
extern unsigned char Ps2_PBUFF[1835008];
extern sceGsDBuffDc Db;
extern PS2_GS_SAVE Ps2_gs_save;
extern SYS_WORK* sys;
extern void* Ps2_tex_buff;
extern unsigned int Ps2_current_texbreak;
extern MOV_INFO MovieInfo;
extern unsigned int Ps2_ice_flag;
extern unsigned int Ps2_current_texno;
extern NJS_TEXLIST* Ps2_current_texlist;
extern NJS_TEXMEMLIST* Ps2_current_texmemlist;
extern int iRingBufNum;
extern int iop_read_buff;

void njUserInit(void);
Sint32 njUserMain(void);
void njUserExit(void);

#endif
