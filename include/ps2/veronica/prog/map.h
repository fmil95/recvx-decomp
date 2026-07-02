#ifndef _MAP_H_
#define _MAP_H_

#include "types.h"
#include "enums.h"

typedef enum _mp_mod 
{
    MP_MOD_FIRST       =  0,
    MP_MOD_IDX_READ    =  1,
    MP_MOD_IDX_ANALYZE =  2,
    MP_MOD_MAP_READ    =  3,
    MP_MOD_DAT_SET     =  4,
    MP_MOD_VEW_NORMAL  =  5,
    MP_MOD_VEW_ZOOM    =  6,
    MP_MOD_WAIT_NORMAL =  7,
    MP_MOD_WAIT_ZOOM   =  8,
    MP_MOD_EXIT        =  9,
    MP_MOD_WAIT        = 10,
    MP_MOD_WAIT_NOMAP  = 11,
    MP_MOD_UNKNOWN     = -1
} mp_mod;

typedef struct _tag_wrk_typ 
{
    // total size: 0x20
    int rom_no;                    // offset 0x0, size 0x4
    NJS_POINT3 pos;                // offset 0x4, size 0xC
    struct _tag_wrk_typ* tagPP[4]; // offset 0x10, size 0x10
} tag_wrk_typ;

typedef struct _func_wrk_typ 
{
    // total size: 0x40
    int mode;                            // offset 0x0, size 0x4
    int param0;                          // offset 0x4, size 0x4
    int param1;                          // offset 0x8, size 0x4
    int param2;                          // offset 0xC, size 0x4
    int FreeWrk[9];                      // offset 0x10, size 0x24
    int (*funcP)(struct _func_wrk_typ*); // offset 0x34, size 0x4
    struct _func_wrk_typ* prevP;         // offset 0x38, size 0x4
    struct _func_wrk_typ* nextP;         // offset 0x3C, size 0x4
} func_wrk_typ;

typedef struct _cnc_wrk_typ 
{
    // total size: 0x1C
    int status;                     // offset 0x0, size 0x4
    int map_no;                     // offset 0x4, size 0x4
    int flr_no;                     // offset 0x8, size 0x4
    struct _cnc_wrk_typ* flr_nextP; // offset 0xC, size 0x4
    struct _cnc_wrk_typ* flr_prevP; // offset 0x10, size 0x4
    struct _cnc_wrk_typ* map_nextP; // offset 0x14, size 0x4
    struct _cnc_wrk_typ* map_prevP; // offset 0x18, size 0x4
} cnc_wrk_typ;

typedef struct _map_nxt 
{
    // total size: 0x20
    int map_up;    // offset 0x0, size 0x4
    int flr_up;    // offset 0x4, size 0x4
    int map_down;  // offset 0x8, size 0x4
    int flr_down;  // offset 0xC, size 0x4
    int map_left;  // offset 0x10, size 0x4
    int flr_left;  // offset 0x14, size 0x4
    int map_right; // offset 0x18, size 0x4
    int flr_right; // offset 0x1C, size 0x4
} map_nxt;

typedef struct _map_wrk 
{
    // total size: 0x5D8
    int status;                       // offset 0x0, size 0x4
    mp_mod map_mode;                  // offset 0x4, size 0x4
    int time;                         // offset 0x8, size 0x4
    int fil_mode;                     // offset 0xC, size 0x4
    int prti_no;                      // offset 0x10, size 0x4
    int slot_no;                      // offset 0x14, size 0x4
    unsigned int pad_ps;              // offset 0x18, size 0x4
    float pad_al;                     // offset 0x1C, size 0x4
    float pad_ar;                     // offset 0x20, size 0x4
    float pad_ax;                     // offset 0x24, size 0x4
    float pad_ay;                     // offset 0x28, size 0x4
    int map_no;                       // offset 0x2C, size 0x4
    int stg_no;                       // offset 0x30, size 0x4
    int rom_no;                       // offset 0x34, size 0x4
    int flr_no;                       // offset 0x38, size 0x4
    int map_flr;                      // offset 0x3C, size 0x4
    int ply_stg;                      // offset 0x40, size 0x4
    int ply_rom;                      // offset 0x44, size 0x4
    int ply_flr;                      // offset 0x48, size 0x4
    ML_WORK map_mdl;                  // offset 0x4C, size 0x18
    NJS_CNK_OBJECT* map_objP;         // offset 0x64, size 0x4
    ML_WORK MrkMdl[8];                // offset 0x68, size 0xC0
    NJS_POINT3 vew_pos;               // offset 0x128, size 0xC
    int vew_ang[3];                   // offset 0x134, size 0xC
    float vew_zom;                    // offset 0x140, size 0x4
    NJS_POINT3 vew_max;               // offset 0x144, size 0xC
    NJS_POINT3 vew_min;               // offset 0x150, size 0xC
    NJS_MATRIX* vew_mtxP;             // offset 0x15C, size 0x4
    char Vew_Mtx[64];                 // offset 0x160, size 0x40
    NJS_POINT3 vew_pos_bak;           // offset 0x1A0, size 0xC
    float vew_zom_bak;                // offset 0x1AC, size 0x4
    int cur_rom;                      // offset 0x1B0, size 0x4
    int chk_rom;                      // offset 0x1B4, size 0x4
    NJS_CNK_OBJECT* cur_objP;         // offset 0x1B8, size 0x4
    NJS_MATRIX* cur_mtxP;             // offset 0x1BC, size 0x4
    NJS_MATRIX* rom_mtxP;             // offset 0x1C0, size 0x4
    NJS_MATRIX* tmp_mtxP;             // offset 0x1C4, size 0x4
    unsigned int Dummy2[2];           // offset 0x1C8, size 0x8
    char Rom_Mtx[192];                // offset 0x1D0, size 0xC0
    short* map_cdeP;                  // offset 0x290, size 0x4
    int cde_bol;                      // offset 0x294, size 0x4
    NJS_POINT2 bck_p0;                // offset 0x298, size 0x8
    NJS_POINT2 bck_p1;                // offset 0x2A0, size 0x8
    float bck_depth;                  // offset 0x2A8, size 0x4
    float map_scale;                  // offset 0x2AC, size 0x4
    float lgt_scale;                  // offset 0x2B0, size 0x4
    void* mem_bakP;                   // offset 0x2B4, size 0x4
    void* rom_bakP;                   // offset 0x2B8, size 0x4
    void* map_bufP;                   // offset 0x2BC, size 0x4
    void* tex_pacP;                   // offset 0x2C0, size 0x4
    NJS_TEXLIST* rom_texP;            // offset 0x2C4, size 0x4
    NJS_TEXLIST* map_texP;            // offset 0x2C8, size 0x4
    NJS_TEXLIST* stg_texP;            // offset 0x2CC, size 0x4
    float ar;                         // offset 0x2D0, size 0x4
    float ag;                         // offset 0x2D4, size 0x4
    float ab;                         // offset 0x2D8, size 0x4
    float pr;                         // offset 0x2DC, size 0x4
    float pg;                         // offset 0x2E0, size 0x4
    float pb;                         // offset 0x2E4, size 0x4
    int pitch;                        // offset 0x2E8, size 0x4
    int yaw;                          // offset 0x2EC, size 0x4
    NJS_ARGB MapPal[32];              // offset 0x2F0, size 0x200
    NJS_COLOR MapCol[3];              // offset 0x4F0, size 0xC
    struct _func_wrk_typ* busy_funcP; // offset 0x4FC, size 0x4
    struct _func_wrk_typ* free_funcP; // offset 0x500, size 0x4
    NJS_SPRITE map_spr;               // offset 0x504, size 0x20
    NJS_ARGB map_mtr;                 // offset 0x524, size 0x10
    int bnk_mde;                      // offset 0x534, size 0x4
    int bnk_stg;                      // offset 0x538, size 0x4
    int bnk_flr;                      // offset 0x53C, size 0x4
    int bnk_rom;                      // offset 0x540, size 0x4
    int bnk_pal;                      // offset 0x544, size 0x4
    int bnk_tag_rom;                  // offset 0x548, size 0x4
    int bnk_tag_pal;                  // offset 0x54C, size 0x4
    int bnk_tag_pal_wal;              // offset 0x550, size 0x4
    unsigned int* mes_bufPP[10];      // offset 0x554, size 0x28
    struct _tag_wrk_typ* tag_wrkP;    // offset 0x57C, size 0x4
    struct _tag_wrk_typ* cur_tagP;    // offset 0x580, size 0x4
    struct _tag_wrk_typ* fcs_tagP;    // offset 0x584, size 0x4
    int tag_num;                      // offset 0x588, size 0x4
    float dst_zom;                    // offset 0x58C, size 0x4
    NJS_POINT3 dst_pos;               // offset 0x590, size 0xC
    map_nxt map_nxt;                  // offset 0x59C, size 0x20
    struct _cnc_wrk_typ* cnc_wrkP;    // offset 0x5BC, size 0x4
    struct _cnc_wrk_typ* cnc_hedP;    // offset 0x5C0, size 0x4
    struct _cnc_wrk_typ* cur_cncP;    // offset 0x5C4, size 0x4
    int cnc_map;                      // offset 0x5C8, size 0x4
    int cnc_flr;                      // offset 0x5CC, size 0x4
    unsigned int Dummy3[2];           // offset 0x5D0, size 0x8
} map_wrk;

typedef struct ID_WORK
{
    // total size: 0x2
    unsigned char itm_no; // offset 0x0, size 0x1
    unsigned char flg_no; // offset 0x1, size 0x1
} ID_WORK;

typedef struct FTS_WORK
{
	// total size: 0x10
    int param0; // offset 0x0, size 0x4
    int param1; // offset 0x4, size 0x4
    int param2; // offset 0x8, size 0x4
    int param3; // offset 0xC, size 0x4
} FTS_WORK;

typedef struct FT_WORK 
{
    // total size: 0x20
    int mode;               // offset 0x0, size 0x4
    mp_mod* map_mdeP;       // offset 0x4, size 0x4
    int chg_mde;            // offset 0x8, size 0x4
    int (*tskP)(FTS_WORK*); // offset 0xC, size 0x4
    FTS_WORK tsk_sub;       // offset 0x10, size 0x10
} FT_WORK;

void bhInitMap(enum_2 set_mod);
void bhSetMap();
void bhExitMap();
int bhReadMapData(char* namP);
void MapCnvStatus2Flag();
int bhControlMap();
void MapPadMain();
void MapViewMain();
void MapLightMain();
void MapPaletteMain();
void MapCodeProcess();
void MapBoolSet(int bol, int mod);
void MapDrawMarker(int mrk_no, NJS_POINT3* posP, int pal_no);
void MapDrawBackground(float depth, NJS_POINT2* p0P, NJS_POINT2* p1P);
/*void MapDrawSprite(NJS_POINT3* posP, int col, _enum_4 spr_no);*/
int MapGetFloorNo(void* datP, int rom_no, float pos_y);
void MapPurgeTree(ML_WORK* mlwP);
void MapFuncInit(int func_num);
func_wrk_typ* MapFuncAlloc(int(*funcP)(func_wrk_typ*), int param0);
void MapFuncFree(func_wrk_typ* fwP);
void MapFuncDel(func_wrk_typ* fwP);
func_wrk_typ* MapFuncIns(func_wrk_typ* bsP, func_wrk_typ* fwP);
void MapFuncExec();
int FsubMapDraw(func_wrk_typ* fwP);
int FsubBackDraw();
/*void MapEntrySprite(_enum_0 set_no, int mode);
int FsprSpriteDraw(_anon22* fsP);
int FsprSilhouetteDraw(_anon22* fsP);
int FsprArrowDraw(_anon22* fsP);
int FsprArrowDraw2(_anon22* fsP);
FT_WORK* MapEntryTask(int(*tskP)(_anon35*), mp_mod chg_mde, int param0)*/;
int FsubTaskMain(FT_WORK* ftP);
int FtskMapWait();
int FtskMapExit();
/*int FtskMapRead(_anon35* ftsP);
int FtskMapNormal(_anon35* ftsP);
int FtskMapZoom(_anon35* ftsP);
int FsubGaugeDrawZ(_anon3* fgP);
int FsubGaugeDrawX(_anon3* fgP);
int FsubGaugeDraw(_anon3* fgP);*/
void MapTagInit(int tag_num);
void MapTagEntry(NJS_MATRIX* basP, int rom_no, NJS_POINT3* posP);
tag_wrk_typ* MapTagConnect(int rom_no);
tag_wrk_typ* MapTagCenter();
void MapDrawLine2(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal);
void MapDrawLine(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal);
void MapDrawFill(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal);
static void MapDrawPolyFill(NJS_POINT2* pnt, float pri, int pal);
void MapDrawMessage();
/*int FsubZoomCursor(_anon8* fzP);
int FsubZoomInfomation(_anon21* fiP);
_anon39 MapCnvArgb2Color(_anon11* argbP);
int FsubZoomScreen(_anon30* fsP);
int FsubCompass(_anon38* fcP);
int FsubModeMessage(_anon49* fmP);*/
void MapCncInit(int map_num, int flr_num);
/*_cnc_wrk_typ* MapCncGet(int map_no, int flr_no);
void MapCnc(_enum_3 dst, _enum_3 src, int status);*/
void MapCncConnect(unsigned short* datP);
map_nxt* MapCheckNextMap(map_nxt* mnP);
static int GetGameMode();

#endif
