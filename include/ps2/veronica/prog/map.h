#ifndef _MAP_H_
#define _MAP_H_

#include "types.h"

typedef enum enum_2
{
	MP_SET_GAME,
	MP_SET_EVENT,
	MP_SET_SUB
} enum_2;

typedef enum _mp_no 
{
    MP000 = 0,
    MP001 = 1,
    MP100 = 16,
    MP101 = 17,
    MP102 = 18,
    MP200 = 32,
    MP201 = 33,
    MP202 = 34,
    MP203 = 35,
    MP300 = 48,
    MP301 = 49,
    MP302 = 50,
    MP400 = 64,
    MP401 = 65,
    MP500 = 80,
    MP600 = 96,
    MP601 = 97,
    MP602 = 98,
    MP700 = 112,
    MP701 = 113,
    MP702 = 114,
    MP703 = 115,
    MP704 = 116,
    MP800 = 128,
    MP801 = 129,
    MP900 = 144,
    MP901 = 145,
    MP902 = 146,
    MP903 = 147,
    MP904 = 148,
    MP905 = 149,
    MPa00 = 160,
    MPa01 = 161,
    MPa02 = 162
} mp_no;

typedef enum _mp_set 
{
    MP_SET_SILHOUETTE = 0,
    MP_SET_ARROW_UP = 1,
    MP_SET_ARROW_DOWN = 2,
    MP_SET_ARROW_LEFT = 3,
    MP_SET_ARROW_RIGHT = 4,
    MP_SET_ARROW2_UP = 5,
    MP_SET_ARROW2_DOWN = 6,
    MP_SET_ARROW2_LEFT = 7,
    MP_SET_ARROW2_RIGHT = 8,
    MP_SET_LR_ZOOM = 9,
    MP_SET_TITLE = 10,
    MP_SET_NUM = 11,
} mp_set;

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

typedef enum _mp_spr 
{
    MP_SPR_SILHOUETTE = 0,
    MP_SPR_ARROW_DOWN = 1,
    MP_SPR_ARROW_UP = 2,
    MP_SPR_ARROW_LEFT = 3,
    MP_SPR_ARROW_RIGHT = 4,
    MP_SPR_X_BUTTON = 5,
    MP_SPR_B_BUTTON = 6,
    MP_SPR_A_BUTTON = 7,
    MP_SPR_LR_ZOOM = 8,
    MP_SPR_CHANGE = 9,
    MP_SPR_ITEM = 10,
    MP_SPR_BOX = 11,
    MP_SPR_SAVEPOINT = 12,
    MP_SPR_DIAMOND = 13,
    MP_SPR_10M_D = 14,
    MP_SPR_10M_L = 15,
    MP_SPR_0M = 16,
    MP_SPR_TITLE = 17,
    MP_SPR_NUM = 18
} mp_spr;

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

typedef struct FG_WORK
{
    // total size: 0x14
    int mode;           // offset 0x0, size 0x4
    int param0;         // offset 0x4, size 0x4
    NJS_POINT3 gge_pos; // offset 0x8, size 0xC
} FG_WORK;

typedef struct MD_WORK
{
    // total size: 0x10
    NJS_POINT3 pos; // offset 0x0, size 0xC
    mp_spr spr;     // offset 0xC, size 0x4
} MD_WORK;

typedef struct FM_WORK 
{
    // total size: 0x8
    int mode;     // offset 0x0, size 0x4
    MD_WORK* mdP; // offset 0x4, size 0x4
} FM_WORK;

typedef struct FSD_WORK
{
    // total size: 0x1C
    mp_mod* act_mdeP;   // offset 0x0, size 0x4
    int act_bit;        // offset 0x4, size 0x4
    mp_spr spr_no;      // offset 0x8, size 0x4
    int spr_col;        // offset 0xC, size 0x4
    NJS_POINT3 spr_pos; // offset 0x10, size 0xC
} FSD_WORK;

typedef struct FSC_WORK
{
    // total size: 0x8
    int spr_mde; // offset 0x0, size 0x4
    int count;   // offset 0x4, size 0x4
} FSC_WORK;

typedef struct FS_WORK 
{
    // total size: 0x28
    int mode;         // offset 0x0, size 0x4
    FSD_WORK spr_dsp; // offset 0x4, size 0x1C
    FSC_WORK spr_cnt; // offset 0x20, size 0x8
} FS_WORK;

typedef struct FC_WORK 
{
    // total size: 0x1C
    int mode;       // offset 0x0, size 0x4
    NJS_POINT3 pos; // offset 0x4, size 0xC
    int ang;        // offset 0x10, size 0x4
    float scl_x;    // offset 0x14, size 0x4
    float scl_y;    // offset 0x18, size 0x4
} FC_WORK;

typedef struct FS_WRK 
{
    // total size: 0x1C
    int mode;        // offset 0x0, size 0x4
    NJS_POINT2 pos0; // offset 0x4, size 0x8
    NJS_POINT2 pos1; // offset 0xC, size 0x8
    float rad;       // offset 0x14, size 0x4
    int ang;         // offset 0x18, size 0x4
} FS_WRK;

typedef struct FZ_WORK 
{
    // total size: 0x2C
    int mode;               // offset 0x0, size 0x4
    int time;               // offset 0x4, size 0x4
    const NJS_POINT2* dstP; // offset 0x8, size 0x4
    NJS_POINT2 pos_a0;      // offset 0xC, size 0x8
    NJS_POINT2 pos_a1;      // offset 0x14, size 0x8
    NJS_POINT2 pos_b0;      // offset 0x1C, size 0x8
    NJS_POINT2 pos_b1;      // offset 0x24, size 0x8
} FZ_WORK;

typedef struct FI_WORK 
{
    // total size: 0x1C
    int mode;        // offset 0x0, size 0x4
    NJS_POINT3 pos0; // offset 0x4, size 0xC
    NJS_POINT2 pos1; // offset 0x10, size 0x8
    int time;        // offset 0x18, size 0x4
} FI_WORK;

typedef struct FT_WRK
{
    // total size: 0x8
    float label;  // offset 0x0, size 0x4
    short map_no; // offset 0x4, size 0x2
    short flr_no; // offset 0x6, size 0x2
} FT_WRK;

typedef struct SS_WORK 
{
    // total size: 0x1C
    mp_spr spr_no;      // offset 0x0, size 0x4
    void* funcP;        // offset 0x4, size 0x4
    int act_bit;        // offset 0x8, size 0x4
    int spr_col;        // offset 0xC, size 0x4
    NJS_POINT3 spr_pos; // offset 0x10, size 0xC
} SS_WORK;

typedef struct MA_WORK
{
    // total size: 0x10
    int mrk_no;   // offset 0x0, size 0x4
    float scale;  // offset 0x4, size 0x4
    float offset; // offset 0x8, size 0x4
    int pal_no;   // offset 0xC, size 0x4
} MA_WORK;

void bhInitMap(enum_2 set_mod);
void bhSetMap();
void bhExitMap();
static int bhReadMapData(char* namP);
static void MapCnvStatus2Flag();
int bhControlMap();
static void MapPadMain();
static void MapViewMain();
static void MapLightMain();
static void MapPaletteMain();
static void MapCodeProcess();
static void MapBoolSet(int bol, int mod);
static void MapDrawMarker(int mrk_no, NJS_POINT3* posP, int pal_no);
static void MapDrawBackground(float depth, NJS_POINT2* p0P, NJS_POINT2* p1P);
static void MapDrawSprite(NJS_POINT3* posP, int col, mp_spr spr_no);
static int MapGetFloorNo(void* datP, int rom_no, float pos_y);
static void MapPurgeTree(ML_WORK* mlwP);
static void MapFuncInit(int func_num);
static func_wrk_typ* MapFuncAlloc(int(*funcP)(func_wrk_typ*), int param0);
static void MapFuncFree(func_wrk_typ* fwP);
static void MapFuncDel(func_wrk_typ* fwP);
static func_wrk_typ* MapFuncIns(func_wrk_typ* bsP, func_wrk_typ* fwP);
static void MapFuncExec();
static int FsubMapDraw(func_wrk_typ* fwP);
static int FsubBackDraw();
static void MapEntrySprite(mp_set set_no, int mode);
static int FsprSpriteDraw(FS_WORK* fsP);
static int FsprSilhouetteDraw(FS_WORK* fsP);
static int FsprArrowDraw(FS_WORK* fsP);
static int FsprArrowDraw2(FS_WORK* fsP);
static FT_WORK* MapEntryTask(int(*tskP)(FTS_WORK*), mp_mod chg_mde, int param0);
static int FsubTaskMain(FT_WORK* ftP);
static int FtskMapWait();
static int FtskMapExit();
static int FtskMapRead(FTS_WORK* ftsP);
static int FtskMapNormal(FTS_WORK* ftsP);
static int FtskMapZoom(FTS_WORK* ftsP);
static int FsubGaugeDrawZ(FG_WORK* fgP);
static int FsubGaugeDrawX(FG_WORK* fgP);
static int FsubGaugeDraw(FG_WORK* fgP);
static void MapTagInit(int tag_num);
static void MapTagEntry(NJS_MATRIX* basP, int rom_no, NJS_POINT3* posP);
static tag_wrk_typ* MapTagConnect(int rom_no);
static tag_wrk_typ* MapTagCenter();
static void MapDrawLine2(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal);
static void MapDrawLine(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal);
static void MapDrawFill(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal);
static void MapDrawPolyFill(NJS_POINT2* pnt, float pri, int pal);
static void MapDrawMessage(int rom, float x, float y);
static int FsubZoomCursor(FZ_WORK* fzP);
static int FsubZoomInfomation(FI_WORK* fiP);
static NJS_COLOR MapCnvArgb2Color(NJS_ARGB* argbP);
static int FsubZoomScreen(FS_WRK* fsP);
static int FsubCompass(FC_WORK* fcP);
static int FsubModeMessage(FM_WORK* fmP);
static void MapCncInit(int map_num, int flr_num);
static cnc_wrk_typ* MapCncGet(int map_no, int flr_no);
static void MapCnc(mp_no dst, mp_no src, int status);
static void MapCncConnect(const unsigned short* datP);
static map_nxt* MapCheckNextMap(map_nxt* mnP);
static int GetGameMode();

#endif
