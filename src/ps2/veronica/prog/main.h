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
extern unsigned int StatusUpdateCounter;
extern unsigned int DiscOpenTrayFlag;
extern PAD_ACT Pad_act[20];
extern BUTTON_INFO ButtonInfo[5];
extern PAD_WRK Pad[4]; 
extern int SoftResetFlag;
extern PAD_INFO Ps2_pad;
extern unsigned int Ps2_sys_cnt;
extern int CurrentPortId;
extern char ADX_STREAM_BUFFER[471040];
extern int iop_data_buff;
extern SND_STATUS get_iop_snddata;
extern char sound_flag;
extern unsigned int SddFirstFlag;
extern char SdcGdDaVolume;
extern NO_NAME_4 eff[512];

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
extern int PatId[4];
extern int OpenDriveTrayFlag;
extern int pd_port;
extern unsigned char BackColorFlag;
extern unsigned char Pause_Flag;
extern unsigned char FontSz[126];
extern float FontScaleX;
extern float FontScaleCR;
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
extern unsigned char pl_sleep_cnt;
extern unsigned int Ps2_albinoid_flag;
extern CAM_WORK cam;
extern unsigned char* vebmemp;
extern unsigned char* keepmem;
extern BH_PWORK ply;
extern float BHD_ASPECT_X;
extern float BHD_ASPECT_Y;
extern unsigned char* Ps2_PXLCONV;
extern BH_PWORK ene[128];
extern unsigned int Ps2_quad_color;
extern int Ps2_quad_trans;
extern unsigned int Ps2_current_texno_bk;
extern NJS_TEXLIST* Ps2_current_texlist_bk;
extern int movie_draw;
extern u_long128 test_tag[1400];
extern VoBuf voBuf;
extern RMI_WORK rmi;

void njUserInit(void);
Sint32 njUserMain(void);
void njUserExit(void);

#endif
