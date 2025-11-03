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

void njUserInit(void);
Sint32 njUserMain(void);
void njUserExit(void);

#endif
