#ifndef _MAIN_H_
#define _MAIN_H_

extern CAM_WORK cam;
extern ROM_WORK* rom;
extern unsigned char* njpmemp;
extern NJS_MATRIX* cmat;
extern SYS_WORK* sys;
extern O_WRK eff[512];
extern BH_PWORK* plp;
extern HWS_WORK* hws;
extern int pd_port;
extern unsigned char* freemem;
extern unsigned char* vwbmemp;
extern NJS_TEXMEMLIST tbuf[256];
extern unsigned char* vebmemp;
extern unsigned char* keepmem;
extern BH_PWORK ply;
extern float BHD_ASPECT_X;
extern float BHD_ASPECT_Y;
extern BH_PWORK ene[128];

void njUserInit(void);
Sint32 njUserMain(void);
void njUserExit(void);

#endif
