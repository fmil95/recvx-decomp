#ifndef _MAIN_H_
#define _MAIN_H_

extern CAM_WORK cam;
extern ROM_WORK* rom;
extern sceVu0FMATRIX ClipMatrix2;
extern float _fNaViwClipNear;
extern float _fNaViwClipFar;
extern float fNaViwClipNear;
extern float fNaViwClipFar;
extern NJS_MATRIX NaViwViewMatrix;
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
extern int iRingBufNum;
extern int iop_read_buff;
extern PAD_ACT Pad_act[20];
extern BUTTON_INFO ButtonInfo[5];
extern PAD_INFO Ps2_pad;
extern unsigned int Ps2_sys_cnt;
extern char sound_flag;
extern O_WRK eff[512];

// TODO: include sg_sybt.h and remove the below struct
struct tag_SYS_BT_SYSTEMID{                   /*                    */
    Sint32 nNo ;                              /*                    */
    Sint32 nAll ;                             /*                    */
    Sint8  szProduct[16];                     /*                    */
} ;                                           /*                    */
typedef struct tag_SYS_BT_SYSTEMID SYS_BT_SYSTEMID ;

extern SYS_BT_SYSTEMID BootDiscSystemId;
extern BH_PWORK* plp;
extern HWS_WORK* hws;
extern int pd_port;
extern unsigned char* freemem;
extern SELECTFILEWINDOW SelectFileWindow;
extern SELECTFILEINFO SelectFileInfo[15];
extern char* cpNameList[18];
extern ICONINFORMATION IconInfo;
extern MEMORYCARDSTATE McState;
extern SAVEFILE SaveFile;
extern CONFIGFILE ConfigFile;
extern unsigned char* vwbmemp;
extern NJS_TEXMEMLIST tbuf[256];
extern unsigned int Ps2_albinoid_flag;
extern CAM_WORK cam;
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
