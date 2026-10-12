#ifndef _TYPES_H_
#define _TYPES_H_

#include "override_katana.h"
#include <ninja.h>
#include <sg_gd.h>
#include <sg_mw.h>
#include <sg_pdvib.h>
#include <sg_sycbl.h>
#include <sg_sd2.h>
#include <PREFIX_PS2_DEBUG.h>
#include <eetypes.h>
#include <eestruct.h>
#include <limits.h>
#include <libvu0.h>
#include <libcdvd.h>
#include <libipu.h>
#include <libmpeg.h>
#include <libgraph.h>
#include <libdma.h>
#include <libpad.h>
#include <libmc.h>
#include <libsdr.h>
#include <csl.h>
#include <libssyn.h>
#include <sif.h>
#include <sifrpc.h>
#include <sdrcmd.h>
#include <sdmacro.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxf.h>
#include "../../../cri/mwlib/ee/lib/libadxe/override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>

typedef struct {
	// total size: 0x8
    float x; // offset 0x0, size 0x4
    float z; // offset 0x4, size 0x4
} NJS_POINT2_XZ;

typedef struct O_WORK
{
	// total size: 0x50
    unsigned int flg;      // offset 0x0, size 0x4
    int dmy;               // offset 0x4, size 0x4
    unsigned int dummy[2]; // offset 0x8, size 0x8
    float mtx[16];         // offset 0x10, size 0x40
} O_WORK;

typedef struct ML_WORK
{
	// total size: 0x18
    unsigned int flg;     // offset 0x0, size 0x4
    unsigned int obj_num; // offset 0x4, size 0x4
    void* datP;           // offset 0x8, size 0x4
	NJS_CNK_OBJECT* objP; // offset 0xC, size 0x4
	NJS_TEXLIST* texP;    // offset 0x10, size 0x4
	O_WORK* owP;          // offset 0x14, size 0x4
} ML_WORK;

typedef struct NJS_MDATA2_MOD
{
    // total size: 0x8
    void* p[2]; // offset 0x0, size 0x8
} NJS_MDATA2_MOD; 

typedef struct MN_WORK
{
	// total size: 0x18
    unsigned int flg;     // offset 0x0, size 0x4
    unsigned int obj_num; // offset 0x4, size 0x4
    unsigned int frm_num; // offset 0x8, size 0x4
    void* datP;           // offset 0xC, size 0x4
	NJS_MDATA2_MOD* md2P; // offset 0x10, size 0x4
	unsigned short* atrP; // offset 0x14, size 0x4
} MN_WORK;

typedef struct O_WRK
{
	// total size: 0x4E0
    unsigned int flg;         // offset 0x0, size 0x4
    unsigned short id;        // offset 0x4, size 0x2
    unsigned short type;      // offset 0x6, size 0x2
    char flr_no;              // offset 0x8, size 0x1
    char flr_nob;             // offset 0x9, size 0x1
    unsigned char mdlver;     // offset 0xA, size 0x1
    unsigned char param;      // offset 0xB, size 0x1
    unsigned char mode0;      // offset 0xC, size 0x1
    unsigned char mode1;      // offset 0xD, size 0x1
    unsigned char mode2;      // offset 0xE, size 0x1
    unsigned char mode3;      // offset 0xF, size 0x1
    float px;                 // offset 0x10, size 0x4
    float py;                 // offset 0x14, size 0x4
    float pz;                 // offset 0x18, size 0x4
    int ax;                   // offset 0x1C, size 0x4
    int ay;                   // offset 0x20, size 0x4
    int az;                   // offset 0x24, size 0x4
    float ar;                 // offset 0x28, size 0x4
    float aw;                 // offset 0x2C, size 0x4
    float ah;                 // offset 0x30, size 0x4
    float ad;                 // offset 0x34, size 0x4
    float car;                // offset 0x38, size 0x4
    float cah;                // offset 0x3C, size 0x4
    float pxb;                // offset 0x40, size 0x4
    float pyb;                // offset 0x44, size 0x4
    float pzb;                // offset 0x48, size 0x4
    int axb;                  // offset 0x4C, size 0x4
    int ayb;                  // offset 0x50, size 0x4
    int azb;                  // offset 0x54, size 0x4
    float gpx;                // offset 0x58, size 0x4
    float gpy;                // offset 0x5C, size 0x4
    float gpz;                // offset 0x60, size 0x4
    float lox;                // offset 0x64, size 0x4
    float loy;                // offset 0x68, size 0x4
    float loz;                // offset 0x6C, size 0x4
    float aox;                // offset 0x70, size 0x4
    float aoy;                // offset 0x74, size 0x4
    float aoz;                // offset 0x78, size 0x4
    float spd;                // offset 0x7C, size 0x4
    unsigned int flg2;        // offset 0x80, size 0x4
    unsigned int mdflg;       // offset 0x84, size 0x4
    unsigned int stflg;       // offset 0x88, size 0x4
    unsigned int Dummy3;      // offset 0x8C, size 0x4
    int draw_tp;              // offset 0x90, size 0x4
    int mdl_n;                // offset 0x94, size 0x4
    void* mskp;               // offset 0x98, size 0x4
    unsigned int Dummy[1];    // offset 0x9C, size 0x4
    int* skp[16];             // offset 0xA0, size 0x40
    NJS_CNK_OBJECT* mbp[16];  // offset 0xE0, size 0x40
    NJS_TEXLIST* txp[16];     // offset 0x120, size 0x40
    ML_WORK mdl[16];          // offset 0x160, size 0x180
    ML_WORK* mlwP;            // offset 0x2E0, size 0x4
    unsigned int mdl_no;      // offset 0x2E4, size 0x4
    int lkono;                // offset 0x2E8, size 0x4
    unsigned char* lkwkp;     // offset 0x2EC, size 0x4
    unsigned char* exp0;      // offset 0x2F0, size 0x4
    unsigned char* exp1;      // offset 0x2F4, size 0x4
    unsigned char* exp2;      // offset 0x2F8, size 0x4
    unsigned char* exp3;      // offset 0x2FC, size 0x4
    unsigned char mtxbuf[64]; // offset 0x300, size 0x40
    float (*mtx)[16];         // offset 0x340, size 0x4
    NJS_CNK_OBJECT* obj_a;    // offset 0x344, size 0x4
    NJS_CNK_OBJECT* obj_b;    // offset 0x348, size 0x4
    float shp_ct;             // offset 0x34C, size 0x4
    char clp_jno[8];          // offset 0x350, size 0x8
    int lok_jno;              // offset 0x358, size 0x4
    MN_WORK* mnwP;            // offset 0x35C, size 0x4
    MN_WORK* mnwPb;           // offset 0x360, size 0x4
    unsigned int mtn_attr;    // offset 0x364, size 0x4
    unsigned int mtn_no;      // offset 0x368, size 0x4
    int frm_no;               // offset 0x36C, size 0x4
    unsigned int frm_mode;    // offset 0x370, size 0x4
    int hokan_rate;           // offset 0x374, size 0x4
    unsigned int hokan_count; // offset 0x378, size 0x4
    unsigned int hokan_ctbak; // offset 0x37C, size 0x4
    int mtn_add;              // offset 0x380, size 0x4
    unsigned int mtn_md;      // offset 0x384, size 0x4
    unsigned char* mtn_tp;    // offset 0x388, size 0x4
    int axp;                  // offset 0x38C, size 0x4
    int ayp;                  // offset 0x390, size 0x4
    int azp;                  // offset 0x394, size 0x4
    short psh_ct;             // offset 0x398, size 0x2
    short psh_idx;            // offset 0x39A, size 0x2
    int idx_ct;               // offset 0x39C, size 0x4
    int mtn_chk;              // offset 0x3A0, size 0x4
    float ofx;                // offset 0x3A4, size 0x4
    float ofy;                // offset 0x3A8, size 0x4
    float ofz;                // offset 0x3AC, size 0x4
    float sx;                 // offset 0x3B0, size 0x4
    float sy;                 // offset 0x3B4, size 0x4
    float sz;                 // offset 0x3B8, size 0x4
    float sxb;                // offset 0x3BC, size 0x4
    float syb;                // offset 0x3C0, size 0x4
    float szb;                // offset 0x3C4, size 0x4
    float xn;                 // offset 0x3C8, size 0x4
    float yn;                 // offset 0x3CC, size 0x4
    float zn;                 // offset 0x3D0, size 0x4
    int ct0;                  // offset 0x3D4, size 0x4
    int ct1;                  // offset 0x3D8, size 0x4
    int ct2;                  // offset 0x3DC, size 0x4
    int ct3;                  // offset 0x3E0, size 0x4
    unsigned char* objbak;    // offset 0x3E4, size 0x4
    NJS_SPHERE cspr;          // offset 0x3E8, size 0x10
    int pn;                   // offset 0x3F8, size 0x4
    NJS_POLYGON_VTX* pvp;     // offset 0x3FC, size 0x4
    NJS_TEXTURE_VTX* tvp;     // offset 0x400, size 0x4
    NJS_POLYGON_VTX pv[4];    // offset 0x404, size 0x40
    NJS_TEXTURE_VTX tv[4];    // offset 0x444, size 0x60
    int bl_src;               // offset 0x4A4, size 0x4
    int bl_dst;               // offset 0x4A8, size 0x4
    int ani_ct;               // offset 0x4AC, size 0x4
    int tex_id;               // offset 0x4B0, size 0x4
    int aspd;                 // offset 0x4B4, size 0x4
    unsigned int gidx;        // offset 0x4B8, size 0x4
    int bank;                 // offset 0x4BC, size 0x4
    char jno[16];             // offset 0x4C0, size 0x10
    char hide[4];             // offset 0x4D0, size 0x4
    void (*func)(void*);      // offset 0x4D4, size 0x4
    int idx;                  // offset 0x4D8, size 0x4
    int Dummy2;               // offset 0x4DC, size 0x4 
} O_WRK;

typedef struct TXB_WORK
{
	// total size: 0x14
    unsigned char* adr; // offset 0x0, size 0x4
    unsigned int gidx;  // offset 0x4, size 0x4
    unsigned int attr;  // offset 0x8, size 0x4
    unsigned int w;     // offset 0xC, size 0x4
    unsigned int h;     // offset 0x10, size 0x4
} TXB_WORK;

typedef struct EF_WORK
{
	// total size: 0x28
    unsigned int flg;      // offset 0x0, size 0x4
    unsigned short id;     // offset 0x4, size 0x2
    unsigned short type;   // offset 0x6, size 0x2
    short flr_no;          // offset 0x8, size 0x2
    unsigned short mdlver; // offset 0xA, size 0x2
    float px;              // offset 0xC, size 0x4
    float py;              // offset 0x10, size 0x4
    float pz;              // offset 0x14, size 0x4
    float sx;              // offset 0x18, size 0x4
    float sy;              // offset 0x1C, size 0x4
    float sz;              // offset 0x20, size 0x4
    short ay;              // offset 0x24, size 0x2
    short ax;              // offset 0x26, size 0x2
} EF_WORK;

typedef struct CPCL
{
    // total size: 0x8
	short jnt_a; // offset 0x0, size 0x2
    short jnt_b; // offset 0x2, size 0x2
    int cap_r;   // offset 0x4, size 0x4
} CPCL;

typedef struct BH_PWORK
{
	// total size: 0x580
    unsigned int flg;         // offset 0x0, size 0x4
    unsigned short id;        // offset 0x4, size 0x2
    unsigned short type;      // offset 0x6, size 0x2
    char flr_no;              // offset 0x8, size 0x1
    char flr_nob;             // offset 0x9, size 0x1
    unsigned char mdlver;     // offset 0xA, size 0x1
    unsigned char param;      // offset 0xB, size 0x1
    unsigned char mode0;      // offset 0xC, size 0x1
    unsigned char mode1;      // offset 0xD, size 0x1
    unsigned char mode2;      // offset 0xE, size 0x1
    unsigned char mode3;      // offset 0xF, size 0x1
    float px;                 // offset 0x10, size 0x4
    float py;                 // offset 0x14, size 0x4
    float pz;                 // offset 0x18, size 0x4
    int ax;                   // offset 0x1C, size 0x4
    int ay;                   // offset 0x20, size 0x4
    int az;                   // offset 0x24, size 0x4
    float ar;                 // offset 0x28, size 0x4
    float aw;                 // offset 0x2C, size 0x4
    float ah;                 // offset 0x30, size 0x4
    float ad;                 // offset 0x34, size 0x4
    float car;                // offset 0x38, size 0x4
    float cah;                // offset 0x3C, size 0x4
    float pxb;                // offset 0x40, size 0x4
    float pyb;                // offset 0x44, size 0x4
    float pzb;                // offset 0x48, size 0x4
    int axb;                  // offset 0x4C, size 0x4
    int ayb;                  // offset 0x50, size 0x4
    int azb;                  // offset 0x54, size 0x4
    float gpx;                // offset 0x58, size 0x4
    float gpy;                // offset 0x5C, size 0x4
    float gpz;                // offset 0x60, size 0x4
    float lox;                // offset 0x64, size 0x4
    float loy;                // offset 0x68, size 0x4
    float loz;                // offset 0x6C, size 0x4
    float aox;                // offset 0x70, size 0x4
    float aoy;                // offset 0x74, size 0x4
    float aoz;                // offset 0x78, size 0x4
    float spd;                // offset 0x7C, size 0x4
    unsigned int flg2;        // offset 0x80, size 0x4
    unsigned int mdflg;       // offset 0x84, size 0x4
    unsigned int stflg;       // offset 0x88, size 0x4
    unsigned int Dummy3;      // offset 0x8C, size 0x4
    int draw_tp;              // offset 0x90, size 0x4
    int mdl_n;                // offset 0x94, size 0x4
    void* mskp;               // offset 0x98, size 0x4
    unsigned int Dummy[1];    // offset 0x9C, size 0x4
    int* skp[16];             // offset 0xA0, size 0x40
    NJS_CNK_OBJECT* mbp[16];  // offset 0xE0, size 0x40
	NJS_TEXLIST* txp[16];     // offset 0x120, size 0x40
	ML_WORK mdl[16];          // offset 0x160, size 0x180
	ML_WORK* mlwP;            // offset 0x2E0, size 0x4
	unsigned int mdl_no;      // offset 0x2E4, size 0x4
    int lkono;                // offset 0x2E8, size 0x4
    unsigned char* lkwkp;     // offset 0x2EC, size 0x4
    unsigned char* exp0;      // offset 0x2F0, size 0x4
    unsigned char* exp1;      // offset 0x2F4, size 0x4
    unsigned char* exp2;      // offset 0x2F8, size 0x4
    unsigned char* exp3;      // offset 0x2FC, size 0x4
    unsigned char mtxbuf[64]; // offset 0x300, size 0x40
    float (*mtx)[16];         // offset 0x340, size 0x4
    NJS_CNK_OBJECT* obj_a;    // offset 0x344, size 0x4
    NJS_CNK_OBJECT* obj_b;    // offset 0x348, size 0x4
    float shp_ct;             // offset 0x34C, size 0x4
    char clp_jno[8];          // offset 0x350, size 0x8
    int lok_jno;              // offset 0x358, size 0x4
	MN_WORK* mnwP;            // offset 0x35C, size 0x4
	MN_WORK* mnwPb;           // offset 0x360, size 0x4
	unsigned int mtn_attr;    // offset 0x364, size 0x4
    unsigned int mtn_no;      // offset 0x368, size 0x4
    int frm_no;               // offset 0x36C, size 0x4
    unsigned int frm_mode;    // offset 0x370, size 0x4
    int hokan_rate;           // offset 0x374, size 0x4
    unsigned int hokan_count; // offset 0x378, size 0x4
    unsigned int hokan_ctbak; // offset 0x37C, size 0x4
    int mtn_add;              // offset 0x380, size 0x4
    unsigned int mtn_md;      // offset 0x384, size 0x4
    unsigned char* mtn_tp;    // offset 0x388, size 0x4
    int axp;                  // offset 0x38C, size 0x4
    int ayp;                  // offset 0x390, size 0x4
    int azp;                  // offset 0x394, size 0x4
    short psh_ct;             // offset 0x398, size 0x2
    short psh_idx;            // offset 0x39A, size 0x2
    int idx_ct;               // offset 0x39C, size 0x4
    int mtn_chk;              // offset 0x3A0, size 0x4
    float ofx;                // offset 0x3A4, size 0x4
    float ofy;                // offset 0x3A8, size 0x4
    float ofz;                // offset 0x3AC, size 0x4
    float sx;                 // offset 0x3B0, size 0x4
    float sy;                 // offset 0x3B4, size 0x4
    float sz;                 // offset 0x3B8, size 0x4
    float sxb;                // offset 0x3BC, size 0x4
    float syb;                // offset 0x3C0, size 0x4
    float szb;                // offset 0x3C4, size 0x4
    float xn;                 // offset 0x3C8, size 0x4
    float yn;                 // offset 0x3CC, size 0x4
    float zn;                 // offset 0x3D0, size 0x4
    int ct0;                  // offset 0x3D4, size 0x4
    int ct1;                  // offset 0x3D8, size 0x4
    int ct2;                  // offset 0x3DC, size 0x4
    int ct3;                  // offset 0x3E0, size 0x4
    int wpnr_no;              // offset 0x3E4, size 0x4
    int wpnl_no;              // offset 0x3E8, size 0x4
    unsigned int at_flg;      // offset 0x3EC, size 0x4
	NJS_CAPSULE watr;         // offset 0x3F0, size 0x1C
	CPCL* cpcl;               // offset 0x40C, size 0x4
	short wax;                // offset 0x410, size 0x2
    short way;                // offset 0x412, size 0x2
    short waz;                // offset 0x414, size 0x2
    short waxp;               // offset 0x416, size 0x2
    short wayp;               // offset 0x418, size 0x2
    short wazp;               // offset 0x41A, size 0x2
    int hp;                   // offset 0x41C, size 0x4
    int dam[64];              // offset 0x420, size 0x100
    int djnt_no;              // offset 0x520, size 0x4
    int cpcl_no;              // offset 0x524, size 0x4
    int dax;                  // offset 0x528, size 0x4
    int day;                  // offset 0x52C, size 0x4
    float dpx;                // offset 0x530, size 0x4
    float dpy;                // offset 0x534, size 0x4
    float dpz;                // offset 0x538, size 0x4
    float dvx;                // offset 0x53C, size 0x4
    float dvy;                // offset 0x540, size 0x4
    float dvz;                // offset 0x544, size 0x4
    int flr_snd;              // offset 0x548, size 0x4
    int ko_num;               // offset 0x54C, size 0x4
    int footeff;              // offset 0x550, size 0x4
    int src_no;               // offset 0x554, size 0x4
    unsigned char* kdnp;      // offset 0x558, size 0x4
    int kdnidx;               // offset 0x55C, size 0x4
    void* dan_ap;             // offset 0x560, size 0x4
    unsigned int comb_flg;    // offset 0x564, size 0x4
    unsigned int comb_wep;    // offset 0x568, size 0x4
    int comb_pnt;             // offset 0x56C, size 0x4
    int comb_timeout;         // offset 0x570, size 0x4
    int total_dam;            // offset 0x574, size 0x4
    unsigned int Dummy2[2];   // offset 0x578, size 0x8
} BH_PWORK;

typedef struct LGT_WORK
{
	// total size: 0xE0
    unsigned int flg;     // offset 0x0, size 0x4
    unsigned int type;    // offset 0x4, size 0x4
    int aspd;             // offset 0x8, size 0x4
    int lkflg;            // offset 0xC, size 0x4
    int lkno;             // offset 0x10, size 0x4
    int lkono;            // offset 0x14, size 0x4
    int lsrc;             // offset 0x18, size 0x4
    float px;             // offset 0x1C, size 0x4
    float py;             // offset 0x20, size 0x4
    float pz;             // offset 0x24, size 0x4
    float lx;             // offset 0x28, size 0x4
    float ly;             // offset 0x2C, size 0x4
    float lz;             // offset 0x30, size 0x4
    float vx;             // offset 0x34, size 0x4
    float vy;             // offset 0x38, size 0x4
    float vz;             // offset 0x3C, size 0x4
    float spc;            // offset 0x40, size 0x4
    float dif;            // offset 0x44, size 0x4
    float amb;            // offset 0x48, size 0x4
    float r;              // offset 0x4C, size 0x4
    float g;              // offset 0x50, size 0x4
    float b;              // offset 0x54, size 0x4
    float nr;             // offset 0x58, size 0x4
    float fr;             // offset 0x5C, size 0x4
    int iang;             // offset 0x60, size 0x4
    int oang;             // offset 0x64, size 0x4
    int ax;               // offset 0x68, size 0x4
    int ay;               // offset 0x6C, size 0x4
    int az;               // offset 0x70, size 0x4
    unsigned int mode;    // offset 0x74, size 0x4
    int ct0;              // offset 0x78, size 0x4
    int ct1;              // offset 0x7C, size 0x4
    int ct2;              // offset 0x80, size 0x4
    int ct3;              // offset 0x84, size 0x4
    float wpx;            // offset 0x88, size 0x4
    float wpy;            // offset 0x8C, size 0x4
    float wpz;            // offset 0x90, size 0x4
    float wvx;            // offset 0x94, size 0x4
    float wvy;            // offset 0x98, size 0x4
    float wvz;            // offset 0x9C, size 0x4
    float wspc;           // offset 0xA0, size 0x4
    float wdif;           // offset 0xA4, size 0x4
    float wamb;           // offset 0xA8, size 0x4
    float wr;             // offset 0xAC, size 0x4
    float wg;             // offset 0xB0, size 0x4
    float wb;             // offset 0xB4, size 0x4
    float wnr;            // offset 0xB8, size 0x4
    float wfr;            // offset 0xBC, size 0x4
    int wiang;            // offset 0xC0, size 0x4
    int woang;            // offset 0xC4, size 0x4
    int wax;              // offset 0xC8, size 0x4
    int way;              // offset 0xCC, size 0x4
    int waz;              // offset 0xD0, size 0x4
    unsigned char* lkwkp; // offset 0xD4, size 0x4
    unsigned char* exp;   // offset 0xD8, size 0x4
	NJS_LIGHT_PTR* light; // offset 0xDC, size 0x4
} LGT_WORK;

typedef struct LGT_WRK
{
	// total size: 0x24
	unsigned int lgt_mod; // offset 0x0, size 0x4
	float col_r;          // offset 0x4, size 0x4
	float col_g;          // offset 0x8, size 0x4
	float col_b;          // offset 0xC, size 0x4
	NJS_POINT3 pos;       // offset 0x10, size 0xC
	float n_rang;         // offset 0x1C, size 0x4
	float f_rang;         // offset 0x20, size 0x4
} LGT_WRK; 

typedef struct LGT_WK 
{
    // total size: 0x74
    unsigned int flg;  // offset 0x0, size 0x4
    unsigned int type; // offset 0x4, size 0x4
    int aspd;          // offset 0x8, size 0x4
    int lkflg;         // offset 0xC, size 0x4
    int lkno;          // offset 0x10, size 0x4
    int lkono;         // offset 0x14, size 0x4
    int lsrc;          // offset 0x18, size 0x4
    float px;          // offset 0x1C, size 0x4
    float py;          // offset 0x20, size 0x4
    float pz;          // offset 0x24, size 0x4
    float lx;          // offset 0x28, size 0x4
    float ly;          // offset 0x2C, size 0x4
    float lz;          // offset 0x30, size 0x4
    float vx;          // offset 0x34, size 0x4
    float vy;          // offset 0x38, size 0x4
    float vz;          // offset 0x3C, size 0x4
    float spc;         // offset 0x40, size 0x4
    float dif;         // offset 0x44, size 0x4
    float amb;         // offset 0x48, size 0x4
    float r;           // offset 0x4C, size 0x4
    float g;           // offset 0x50, size 0x4
    float b;           // offset 0x54, size 0x4
    float nr;          // offset 0x58, size 0x4
    float fr;          // offset 0x5C, size 0x4
    int iang;          // offset 0x60, size 0x4
    int oang;          // offset 0x64, size 0x4
    int ax;            // offset 0x68, size 0x4
    int ay;            // offset 0x6C, size 0x4
    int az;            // offset 0x70, size 0x4
} LGT_WK;

typedef struct LPTB
{
    // total size: 0x20
	NJS_POINT3 ps; // offset 0x0, size 0xC
    float nr;      // offset 0xC, size 0x4
    float fr;      // offset 0x10, size 0x4
    float cr;      // offset 0x14, size 0x4
    float cg;      // offset 0x18, size 0x4
    float cb;      // offset 0x1C, size 0x4
} LPTB;

typedef struct ATR_WORK
{
	// total size: 0x24
    unsigned char flg;  // offset 0x0, size 0x1
    unsigned char type; // offset 0x1, size 0x1
    unsigned char id;   // offset 0x2, size 0x1
    char flr_no;        // offset 0x3, size 0x1
    unsigned int attr;  // offset 0x4, size 0x4
    float px;           // offset 0x8, size 0x4
    float py;           // offset 0xC, size 0x4
    float pz;           // offset 0x10, size 0x4
    float w;            // offset 0x14, size 0x4
    float h;            // offset 0x18, size 0x4
    float d;            // offset 0x1C, size 0x4
    unsigned char prm0; // offset 0x20, size 0x1
    unsigned char prm1; // offset 0x21, size 0x1
    unsigned char prm2; // offset 0x22, size 0x1
    unsigned char prm3; // offset 0x23, size 0x1
} ATR_WORK; 

typedef struct DOOR_WORK
{
	// total size: 0x1C
    unsigned int flg;     // offset 0x0, size 0x4
    char stg_no;          // offset 0x4, size 0x1
    char rom_no;          // offset 0x5, size 0x1
    unsigned char pos_no; // offset 0x6, size 0x1
    unsigned char dor_tp; // offset 0x7, size 0x1
    unsigned char mode0;  // offset 0x8, size 0x1
    unsigned char mode1;  // offset 0x9, size 0x1
    unsigned char mode2;  // offset 0xA, size 0x1
    unsigned char mode3;  // offset 0xB, size 0x1
    int ct0;              // offset 0xC, size 0x4
    int ct1;              // offset 0x10, size 0x4
    int ct2;              // offset 0x14, size 0x4
    int ct3;              // offset 0x18, size 0x4
} DOOR_WORK;

typedef struct EVT_WORK
{
	// total size: 0xC
    unsigned short* scd0; // offset 0x0, size 0x4
    unsigned short* scd1; // offset 0x4, size 0x4
    unsigned short* evd;  // offset 0x8, size 0x4
} EVT_WORK;

typedef struct NJS_POINT4
{
	// total size: 0x10
    float x; // offset 0x0, size 0x4
    float y; // offset 0x4, size 0x4
    float z; // offset 0x8, size 0x4
    float w; // offset 0xC, size 0x4
} NJS_POINT4; 

typedef struct POINT 
{
    // total size: 0x18
    float px; // offset 0x0, size 0x4
    float py; // offset 0x4, size 0x4
    float pz; // offset 0x8, size 0x4
    float ox; // offset 0xC, size 0x4
    float oy; // offset 0x10, size 0x4
    float oz; // offset 0x14, size 0x4
} POINT; 

typedef struct NODE
{
    // total size: 0x40
	sceVu0FVECTOR vertex; // offset 0x0, size 0x10
	sceVu0FVECTOR color;  // offset 0x10, size 0x10
	sceVu0FVECTOR texUV;  // offset 0x20, size 0x10
	sceVu0FVECTOR clipV;  // offset 0x30, size 0x10
} NODE;

typedef struct SCISSOR_NODE
{
    // total size: 0x310
	NODE node[12];        // offset 0x0, size 0x300
	unsigned int nodeNum; // offset 0x300, size 0x4
    float pad[3];         // offset 0x304, size 0xC
} SCISSOR_NODE;

typedef struct SCISSOR
{
    // total size: 0x940
	SCISSOR_NODE triangle;  // offset 0x0, size 0x310
	SCISSOR_NODE narray[2]; // offset 0x310, size 0x620
	SCISSOR_NODE* in;       // offset 0x930, size 0x4
	SCISSOR_NODE* out;      // offset 0x934, size 0x4
	unsigned int rotflag;   // offset 0x938, size 0x4
    unsigned int flipflag;  // offset 0x93C, size 0x4
} SCISSOR;

typedef struct VU1_STRIP_BUF
{
	// total size: 0x40
    float fU;    // offset 0x0, size 0x4
    float fV;    // offset 0x4, size 0x4
    float fPad0; // offset 0x8, size 0x4
    float fPad1; // offset 0xC, size 0x4
    float fIr;   // offset 0x10, size 0x4
    float fIg;   // offset 0x14, size 0x4
    float fIb;   // offset 0x18, size 0x4
    float fA;    // offset 0x1C, size 0x4
    float fVx;   // offset 0x20, size 0x4
    float fVy;   // offset 0x24, size 0x4
    float fVz;   // offset 0x28, size 0x4
    float fFog;  // offset 0x2C, size 0x4
    float fSx;   // offset 0x30, size 0x4
    float fSy;   // offset 0x34, size 0x4
    float fIz;   // offset 0x38, size 0x4
    float fNz;   // offset 0x3C, size 0x4
} VU1_STRIP_BUF;

typedef struct VU1_PRIM_BUF
{
    // total size: 0x30
    float fS;            // offset 0x0, size 0x4
    float fT;            // offset 0x4, size 0x4
    float fQ;            // offset 0x8, size 0x4
    unsigned int ulKick; // offset 0xC, size 0x4
    float fR;            // offset 0x10, size 0x4
    float fG;            // offset 0x14, size 0x4
    float fB;            // offset 0x18, size 0x4
    float fA;            // offset 0x1C, size 0x4
    float fX;            // offset 0x20, size 0x4
    float fY;            // offset 0x24, size 0x4
    float fZ;            // offset 0x28, size 0x4
    float fF;            // offset 0x2C, size 0x4
} VU1_PRIM_BUF;

typedef struct PAD_WRK
{
	// total size: 0x3C
    int PerType;         // offset 0x0, size 0x4
    int OldPerType;      // offset 0x4, size 0x4
    int PerTypeEx;       // offset 0x8, size 0x4
    unsigned int Flag;   // offset 0xC, size 0x4
    int SoftReset;       // offset 0x10, size 0x4
    unsigned int on;     // offset 0x14, size 0x4
    unsigned int press;  // offset 0x18, size 0x4
    unsigned int Rept;   // offset 0x1C, size 0x4
    unsigned int on2;    // offset 0x20, size 0x4
    unsigned int on2old; // offset 0x24, size 0x4
    unsigned int press2; // offset 0x28, size 0x4
    unsigned short l;    // offset 0x2C, size 0x2
    unsigned short r;    // offset 0x2E, size 0x2
    short x1;            // offset 0x30, size 0x2
    short y1;            // offset 0x32, size 0x2
    short x2;            // offset 0x34, size 0x2
    short y2;            // offset 0x36, size 0x2
    short Calibrate;     // offset 0x38, size 0x2
} PAD_WRK;

typedef struct MOV_INFO
{
    // total size: 0x1C
	unsigned char* mmp;        // offset 0x0, size 0x4
    float Vol;                 // offset 0x4, size 0x4
    float VolSpeed;            // offset 0x8, size 0x4
    float Fade;                // offset 0xC, size 0x4
    float FadeSpeed;           // offset 0x10, size 0x4
    short FrameCnt;            // offset 0x14, size 0x2
    char ExecMovieSystemFlag;  // offset 0x16, size 0x1
    char MovieCancelFlag;      // offset 0x17, size 0x1
    char MovieFadeFlag;        // offset 0x18, size 0x1
    char MovieFadeMode;        // offset 0x19, size 0x1
    char MovieSystemLastError; // offset 0x1A, size 0x1
} MOV_INFO;

typedef struct CAM_KEYF_WORK
{
	// total size: 0x80
    unsigned short flg;     // offset 0x0, size 0x2
    short frame;            // offset 0x2, size 0x2
    float px;               // offset 0x4, size 0x4
    float py;               // offset 0x8, size 0x4
    float pz;               // offset 0xC, size 0x4
    short ax;               // offset 0x10, size 0x2
    short ay;               // offset 0x12, size 0x2
    short az;               // offset 0x14, size 0x2
    short pers;             // offset 0x16, size 0x2
    unsigned int hidobj[8]; // offset 0x18, size 0x20
    unsigned int hidlgt[4]; // offset 0x38, size 0x10
    unsigned int fog_col;   // offset 0x48, size 0x4
    float fog_nr;           // offset 0x4C, size 0x4
    float fog_fr;           // offset 0x50, size 0x4
    short lkflg;            // offset 0x54, size 0x2
    short lkno;             // offset 0x56, size 0x2
    short lkono;            // offset 0x58, size 0x2
    short nxt_no;           // offset 0x5A, size 0x2
    float lx;               // offset 0x5C, size 0x4
    float ly;               // offset 0x60, size 0x4
    float lz;               // offset 0x64, size 0x4
    float prm_0;            // offset 0x68, size 0x4
    float prm_1;            // offset 0x6C, size 0x4
    float prm_2;            // offset 0x70, size 0x4
    float prm_3;            // offset 0x74, size 0x4
    float prm_4;            // offset 0x78, size 0x4
    unsigned char* recp;    // offset 0x7C, size 0x4
} CAM_KEYF_WORK;

typedef struct EVC_WORK
{
    // total size: 0x808
	unsigned short flg;     // offset 0x0, size 0x2
    unsigned short type;    // offset 0x2, size 0x2
    short nxt_no;           // offset 0x4, size 0x2
    short keyf_n;           // offset 0x6, size 0x2
	CAM_KEYF_WORK keyf[16]; // offset 0x8, size 0x800
} EVC_WORK;

typedef struct CAM_WRK
{
	// total size: 0xC4
    unsigned short flg;      // offset 0x0, size 0x2
    unsigned char lgtclip;   // offset 0x2, size 0x1
    char spd;                // offset 0x3, size 0x1
    float px;                // offset 0x4, size 0x4
    float py;                // offset 0x8, size 0x4
    float pz;                // offset 0xC, size 0x4
    float ln;                // offset 0x10, size 0x4
    float w;                 // offset 0x14, size 0x4
    float h;                 // offset 0x18, size 0x4
    float d;                 // offset 0x1C, size 0x4
    float y0;                // offset 0x20, size 0x4
    float y1;                // offset 0x24, size 0x4
    float y2;                // offset 0x28, size 0x4
    float y3;                // offset 0x2C, size 0x4
    float am_spd;            // offset 0x30, size 0x4
    int ax;                  // offset 0x34, size 0x4
    int ay;                  // offset 0x38, size 0x4
    int az;                  // offset 0x3C, size 0x4
    int lax;                 // offset 0x40, size 0x4
    int lay;                 // offset 0x44, size 0x4
    short laz0;              // offset 0x48, size 0x2
    short laz1;              // offset 0x4A, size 0x2
    short laz2;              // offset 0x4C, size 0x2
    short laz3;              // offset 0x4E, size 0x2
    char aa_spd;             // offset 0x50, size 0x1
    char fil_no;             // offset 0x51, size 0x1
    char fil_rt;             // offset 0x52, size 0x1
    char reserve;            // offset 0x53, size 0x1
    int pers;                // offset 0x54, size 0x4
    unsigned int hidobj[16]; // offset 0x58, size 0x40
    unsigned int hidlgt[8];  // offset 0x98, size 0x20
    unsigned int fog_col;    // offset 0xB8, size 0x4
    float fog_nr;            // offset 0xBC, size 0x4
    float fog_fr;            // offset 0xC0, size 0x4
} CAM_WRK;

typedef struct CUT_WRK
{
	// total size: 0x20
    unsigned int attr; // offset 0x0, size 0x4
    char flr_no;       // offset 0x4, size 0x1
    char reserve0;     // offset 0x5, size 0x1
    char reserve1;     // offset 0x6, size 0x1
    char atr_tp;       // offset 0x7, size 0x1
    float h;           // offset 0x8, size 0x4
    float dmy;         // offset 0xC, size 0x4
    float minx;        // offset 0x10, size 0x4
    float minz;        // offset 0x14, size 0x4
    float maxx;        // offset 0x18, size 0x4
    float maxz;        // offset 0x1C, size 0x4
} CUT_WRK;

typedef struct CUT_WORK
{
	// total size: 0x2A8
    unsigned char flg;      // offset 0x0, size 0x1
    unsigned char type;     // offset 0x1, size 0x1
    char flr_no;            // offset 0x2, size 0x1
    unsigned char ctab_n;   // offset 0x3, size 0x1
	CUT_WRK* cuttp;         // offset 0x4, size 0x4
	float cx;               // offset 0x8, size 0x4
    float cy;               // offset 0xC, size 0x4
    float cz;               // offset 0x10, size 0x4
    float cw;               // offset 0x14, size 0x4
    float ch;               // offset 0x18, size 0x4
    float cd;               // offset 0x1C, size 0x4
	CAM_WRK cam[2];         // offset 0x20, size 0x188
	unsigned char exd[256]; // offset 0x1A8, size 0x100
} CUT_WORK;

typedef struct ETTY_WORK
{
	// total size: 0x24
    unsigned int flg;     // offset 0x0, size 0x4
    unsigned short id;    // offset 0x4, size 0x2
    unsigned short type;  // offset 0x6, size 0x2
    char flr_no;          // offset 0x8, size 0x1
    unsigned char mdlver; // offset 0x9, size 0x1
    unsigned char wrk_no; // offset 0xA, size 0x1
    char prm1;            // offset 0xB, size 0x1
    float px;             // offset 0xC, size 0x4
    float py;             // offset 0x10, size 0x4
    float pz;             // offset 0x14, size 0x4
    short ax;             // offset 0x18, size 0x2
    short az;             // offset 0x1A, size 0x2
    short ay;             // offset 0x1C, size 0x2
    short aspd;           // offset 0x1E, size 0x2
    char hide[4];         // offset 0x20, size 0x4
} ETTY_WORK;

typedef struct EF_WRK
{
	// total size: 0x44
    unsigned int flg;      // offset 0x0, size 0x4
    unsigned short id;     // offset 0x4, size 0x2
    unsigned short type;   // offset 0x6, size 0x2
    short flr_no;          // offset 0x8, size 0x2
    unsigned short mdlver; // offset 0xA, size 0x2
    float px;              // offset 0xC, size 0x4
    float py;              // offset 0x10, size 0x4
    float pz;              // offset 0x14, size 0x4
    float sx;              // offset 0x18, size 0x4
    float sy;              // offset 0x1C, size 0x4
    float sz;              // offset 0x20, size 0x4
    short ay;              // offset 0x24, size 0x2
    short ax;              // offset 0x26, size 0x2
    int lkflg;             // offset 0x28, size 0x4
    int lkno;              // offset 0x2C, size 0x4
    int lkono;             // offset 0x30, size 0x4
    float lx;              // offset 0x34, size 0x4
    float ly;              // offset 0x38, size 0x4
    float lz;              // offset 0x3C, size 0x4
    int param;             // offset 0x40, size 0x4
} EF_WRK;

typedef struct POS
{
	// total size: 0x10
    float px; // offset 0x0, size 0x4
    float py; // offset 0x4, size 0x4
    float pz; // offset 0x8, size 0x4
    int ay;   // offset 0xC, size 0x4
} POS;

typedef struct CONFIGFILE 
{
    // total size: 0x34
    unsigned int ssd_ver;     // offset 0x0, size 0x4
    unsigned int ssd_flg;     // offset 0x4, size 0x4
    unsigned int ssd_reserve; // offset 0x8, size 0x4
    char keytype;             // offset 0xC, size 0x1
    char adjust_x;            // offset 0xD, size 0x1
    char adjust_y;            // offset 0xE, size 0x1
    char vibration;           // offset 0xF, size 0x1
    int best_tm[8];           // offset 0x10, size 0x20
    unsigned int Check_Sam;   // offset 0x30, size 0x4
} CONFIGFILE;

typedef struct ICON 
{
    // total size: 0x3C4
    unsigned char Head[4];       // offset 0x0, size 0x4
    unsigned short Reserv1;      // offset 0x4, size 0x2
    unsigned short OffsLF;       // offset 0x6, size 0x2
    unsigned int Reserv2;        // offset 0x8, size 0x4
    unsigned int TransRate;      // offset 0xC, size 0x4
    int BgColor[4][4];           // offset 0x10, size 0x40
    float LightDir[3][4];        // offset 0x50, size 0x30
    float LightColor[3][4];      // offset 0x80, size 0x30
    float Ambient[4];            // offset 0xB0, size 0x10
    unsigned char TitleName[68]; // offset 0xC0, size 0x44
    unsigned char FnameView[64]; // offset 0x104, size 0x40
    unsigned char FnameCopy[64]; // offset 0x144, size 0x40
    unsigned char FnameDel[64];  // offset 0x184, size 0x40
    unsigned char Reserve3[512]; // offset 0x1C4, size 0x200
} ICON;

typedef struct ICONINFORMATION 
{
    // total size: 0x3C4
    ICON icon; // offset 0x0, size 0x3C4
} ICONINFORMATION;

typedef struct MEMORYCARDPORT 
{
    // total size: 0x10
    int lCrntType;   // offset 0x0, size 0x4
    int lPrevType;   // offset 0x4, size 0x4
    int lFreeSize;   // offset 0x8, size 0x4
    int lFormatType; // offset 0xC, size 0x4
} MEMORYCARDPORT;

typedef struct MEMORYCARDSTATE 
{
    // total size: 0xA0
    unsigned int ulState;        // offset 0x0, size 0x4
    unsigned int ulError;        // offset 0x4, size 0x4
    unsigned int ulMcSubState;   // offset 0x8, size 0x4
    unsigned int ulFileSize;     // offset 0xC, size 0x4
    int lCurrentPort;            // offset 0x10, size 0x4
    int lOpenFileNumber;         // offset 0x14, size 0x4
    int lSelectFileNumber;       // offset 0x18, size 0x4
    int lOpenMode;               // offset 0x1C, size 0x4
    unsigned short usMcSysState; // offset 0x20, size 0x2
    void* vpAddr;                // offset 0x24, size 0x4
    char cCurrentDir[50];        // offset 0x28, size 0x32
    char cOpenFileName[32];      // offset 0x5A, size 0x20
    char cRetryCount;            // offset 0x7A, size 0x1
    char cMcCheckFlag;           // offset 0x7B, size 0x1
    char cCheckMcFlag;           // offset 0x7C, size 0x1
    MEMORYCARDPORT Port[2];      // offset 0x80, size 0x20
} MEMORYCARDSTATE;

typedef struct SAVEFILE 
{
    // total size: 0x838
    unsigned int version;       // offset 0x0, size 0x4
    int save_ct;                // offset 0x4, size 0x4
    char ply_id;                // offset 0x8, size 0x1
    char stg_no;                // offset 0x9, size 0x1
    char rom_no;                // offset 0xA, size 0x1
    char rcase;                 // offset 0xB, size 0x1
    char pos_no;                // offset 0xC, size 0x1
    char cut_no;                // offset 0xD, size 0x1
    char flr_no;                // offset 0xE, size 0x1
    char reserve0;              // offset 0xF, size 0x1
    int gm_mode;                // offset 0x10, size 0x4
    unsigned int ev_flg[32];    // offset 0x14, size 0x80
    unsigned int it_flg[16];    // offset 0x94, size 0x40
    unsigned int ic_flg[16];    // offset 0xD4, size 0x40
    unsigned int ed_flg[32];    // offset 0x114, size 0x80
    unsigned int ky_flg[16];    // offset 0x194, size 0x40
    unsigned int mp_flg[8];     // offset 0x1D4, size 0x20
    unsigned int itm[384];      // offset 0x1F4, size 0x600
    unsigned int ply_stflg[4];  // offset 0x7F4, size 0x10
    NJS_POINT3 ply_pos;         // offset 0x804, size 0xC
    int ply_ang;                // offset 0x810, size 0x4
    char ply_wno[4];            // offset 0x814, size 0x4
    short ply_hp[4];            // offset 0x818, size 0x8
    unsigned char evt_posno[4]; // offset 0x820, size 0x4
    int time;                   // offset 0x824, size 0x4
    int stv_tm;                 // offset 0x828, size 0x4
    short spray_ct;             // offset 0x82C, size 0x2
    short retry_ct;             // offset 0x82E, size 0x2
    short clear_ct;             // offset 0x830, size 0x2
    short reserve1;             // offset 0x832, size 0x2
    unsigned int CheckSam;      // offset 0x834, size 0x4
} SAVEFILE;

typedef struct SELECTFILEINFO
{
    // total size: 0x10
    int FileNumber; // offset 0x0, size 0x4
    int save_ct;    // offset 0x4, size 0x4
    int gm_mode;    // offset 0x8, size 0x4
    char ply_id;    // offset 0xC, size 0x1
    char saveroom;  // offset 0xD, size 0x1
} SELECTFILEINFO;

typedef struct SELECTFILEWINDOW 
{
    // total size: 0x28
    unsigned int ulFileState;       // offset 0x0, size 0x4
    SELECTFILEINFO* pRecordTop;     // offset 0x4, size 0x4
    int lRecordMax;                 // offset 0x8, size 0x4
    short slDispTopNumber;          // offset 0xC, size 0x2
    short slDispRecordNumber;       // offset 0xE, size 0x2
    short sMesCur;                  // offset 0x10, size 0x2
    short sCursol;                  // offset 0x12, size 0x2
    short sWaitMesTimer;            // offset 0x14, size 0x2
    float slLineNumber;             // offset 0x18, size 0x4
    int slDispWriteMesMax;          // offset 0x1C, size 0x4
    int slDispWriteMes;             // offset 0x20, size 0x4
    unsigned int ulfoundationColor; // offset 0x24, size 0x4
} SELECTFILEWINDOW;

typedef struct TIM2_PICTUREHEADER
{
	// total size: 0x30
    unsigned int TotalSize;       // offset 0x0, size 0x4
    unsigned int ClutSize;        // offset 0x4, size 0x4
    unsigned int ImageSize;       // offset 0x8, size 0x4
    unsigned short HeaderSize;    // offset 0xC, size 0x2
    unsigned short ClutColors;    // offset 0xE, size 0x2
    unsigned char PictFormat;     // offset 0x10, size 0x1
    unsigned char MipMapTextures; // offset 0x11, size 0x1
    unsigned char ClutType;       // offset 0x12, size 0x1
    unsigned char ImageType;      // offset 0x13, size 0x1
    unsigned short ImageWidth;    // offset 0x14, size 0x2
    unsigned short ImageHeight;   // offset 0x16, size 0x2
    sceGsTex0 GsTex0;             // offset 0x18, size 0x8
    sceGsTex1 GsTex1;             // offset 0x20, size 0x8
    unsigned int GsRegs;          // offset 0x28, size 0x4
    unsigned int GsTexClut;       // offset 0x2C, size 0x4
} TIM2_PICTUREHEADER;

typedef struct ADMIN 
{
    // total size: 0x18
    unsigned int gindex; // offset 0x0, size 0x4
    unsigned int size;   // offset 0x4, size 0x4
    unsigned int count;  // offset 0x8, size 0x4
    void* addr;          // offset 0xC, size 0x4
    void* before;        // offset 0x10, size 0x4
    void* after;         // offset 0x14, size 0x4
} ADMIN;

typedef struct TIM2_PICTUREHEADER_EX 
{
    // total size: 0xD0
    char FileId[4];               // offset 0x0, size 0x4
    unsigned char FormatVersion;  // offset 0x4, size 0x1
    unsigned char FormatId;       // offset 0x5, size 0x1
    unsigned short Pictures;      // offset 0x6, size 0x2
    unsigned int Gindex;          // offset 0x8, size 0x4
    unsigned char OrgColorType;   // offset 0xC, size 0x1
    unsigned char OrgTexType;     // offset 0xD, size 0x1
    unsigned short ClutChange;    // offset 0xE, size 0x2
    unsigned int PalNum;          // offset 0x10, size 0x4
    unsigned int PalData[27];     // offset 0x14, size 0x6C
    unsigned int TotalSize;       // offset 0x80, size 0x4
    unsigned int ClutSize;        // offset 0x84, size 0x4
    unsigned int ImageSize;       // offset 0x88, size 0x4
    unsigned short HeaderSize;    // offset 0x8C, size 0x2
    unsigned short ClutColors;    // offset 0x8E, size 0x2
    unsigned char PictFormat;     // offset 0x90, size 0x1
    unsigned char MipMapTextures; // offset 0x91, size 0x1
    unsigned char ClutType;       // offset 0x92, size 0x1
    unsigned char ImageType;      // offset 0x93, size 0x1
    unsigned short ImageWidth;    // offset 0x94, size 0x2
    unsigned short ImageHeight;   // offset 0x96, size 0x2
    sceGsTex0 GsTex0;             // offset 0x98, size 0x8
    sceGsTex1 GsTex1;             // offset 0xA0, size 0x8
    unsigned int GsRegs;          // offset 0xA8, size 0x4
    unsigned int GsTexClut;       // offset 0xAC, size 0x4
    ADMIN admin;                  // offset 0xB0, size 0x18
    unsigned int TpFlag;          // offset 0xC8, size 0x4
    unsigned int ClampFlag;       // offset 0xCC, size 0x4
} TIM2_PICTUREHEADER_EX;

typedef struct QUAD 
{
    // total size: 0x20
    float x1; // offset 0x0, size 0x4
    float y1; // offset 0x4, size 0x4
    float x2; // offset 0x8, size 0x4
    float y2; // offset 0xC, size 0x4
    float u1; // offset 0x10, size 0x4
    float v1; // offset 0x14, size 0x4
    float u2; // offset 0x18, size 0x4
    float v2; // offset 0x1C, size 0x4
} QUAD;

typedef struct COM_EVT_WORK 
{
    // total size: 0x5D88
    NJS_TEXNAME com_tex[3];    // offset 0x0, size 0x24
    NJS_TEXLIST com_tlist;     // offset 0x24, size 0x8
    unsigned int fcol;         // offset 0x2C, size 0x4
    float fsrc;                // offset 0x30, size 0x4
    float fdst;                // offset 0x34, size 0x4
    float fcal;                // offset 0x38, size 0x4
    float fcnt;                // offset 0x3C, size 0x4
    int ct0;                   // offset 0x40, size 0x4
    int ct1;                   // offset 0x44, size 0x4
    QUAD qt[512];              // offset 0x48, size 0x4000
    unsigned int qtbcol[512];  // offset 0x4048, size 0x800
    int qten[3];               // offset 0x4848, size 0xC
    int lnfg[128];             // offset 0x4854, size 0x200
    NJS_LINE line[128];        // offset 0x4A54, size 0xC00
    short lnct[128];           // offset 0x5654, size 0x100
    short mwin_alp;            // offset 0x5754, size 0x2
    short swin_alp;            // offset 0x5756, size 0x2
    short cwin_alp;            // offset 0x5758, size 0x2
    short chr_no;              // offset 0x575A, size 0x2
    short mtn_no;              // offset 0x575C, size 0x2
    short frm_no;              // offset 0x575E, size 0x2
    float cox;                 // offset 0x5760, size 0x4
    float coy;                 // offset 0x5764, size 0x4
    float coz;                 // offset 0x5768, size 0x4
    short cax;                 // offset 0x576C, size 0x2
    short cay;                 // offset 0x576E, size 0x2
    short caz;                 // offset 0x5770, size 0x2
    short caxn;                // offset 0x5772, size 0x2
    short cayn;                // offset 0x5774, size 0x2
    short cazn;                // offset 0x5776, size 0x2
    unsigned int txt[11][29];  // offset 0x5778, size 0x4FC
    unsigned int txflg;        // offset 0x5C74, size 0x4
    int txwait;                // offset 0x5C78, size 0x4
    int txmes;                 // offset 0x5C7C, size 0x4
    short tx;                  // offset 0x5C80, size 0x2
    short ty;                  // offset 0x5C82, size 0x2
    unsigned int txcol;        // offset 0x5C84, size 0x4
    int txsct;                 // offset 0x5C88, size 0x4
    int curct;                 // offset 0x5C8C, size 0x4
    unsigned int lcflg;        // offset 0x5C90, size 0x4
    short kx;                  // offset 0x5C94, size 0x2
    short ky;                  // offset 0x5C96, size 0x2
    short khk;                 // offset 0x5C98, size 0x2
    short krep;                // offset 0x5C9A, size 0x2
    short kbn;                 // offset 0x5C9C, size 0x2
    char wordmax;              // offset 0x5C9E, size 0x1
    char wordn;                // offset 0x5C9F, size 0x1
    short wdx;                 // offset 0x5CA0, size 0x2
    short wdy;                 // offset 0x5CA2, size 0x2
    unsigned char word[2][16]; // offset 0x5CA4, size 0x20
    unsigned char* mesp;       // offset 0x5CC4, size 0x4
    unsigned char* scp;        // offset 0x5CC8, size 0x4
    unsigned char* sclb[32];   // offset 0x5CCC, size 0x80
    int mes_no;                // offset 0x5D4C, size 0x4
    int mes_ln;                // offset 0x5D50, size 0x4
    int flash;                 // offset 0x5D54, size 0x4
    float bar[3][3];           // offset 0x5D58, size 0x24
    int bar_ct[3];             // offset 0x5D7C, size 0xC
} COM_EVT_WORK;

typedef struct FADE
{
    // total size: 0x18
	int flg;        // offset 0x0, size 0x4
	float alpha;    // offset 0x4, size 0x4
	float alphaset; // offset 0x8, size 0x4
	float cnt00;    // offset 0xC, size 0x4
	float cnt01;    // offset 0x10, size 0x4
	float cnt02;    // offset 0x14, size 0x4
} FADE;

typedef struct Object 
{
    // total size: 0x38
    NJS_POINT3 pos;  // offset 0x0, size 0xC
    float Dist;      // offset 0xC, size 0x4
    int SeNo;        // offset 0x10, size 0x4
    char ReqFlag;    // offset 0x14, size 0x1
    char Prio;       // offset 0x15, size 0x1
    char SlotNo;     // offset 0x16, size 0x1
    char Type;       // offset 0x17, size 0x1
    char Pan;        // offset 0x18, size 0x1
    char Vol;        // offset 0x19, size 0x1
    int Flag;        // offset 0x1C, size 0x4
    int VolFadeP[3]; // offset 0x20, size 0xC
    int PanFadeP[3]; // offset 0x2C, size 0xC
} Object; 

typedef struct ObjectSlot
{
    // total size: 0xC
    int SeNo; // offset 0x0, size 0x4
    short Flag; // offset 0x4, size 0x2
    short FindFlag; // offset 0x6, size 0x2
    short Prio; // offset 0x8, size 0x2
    short ObjectNo; // offset 0xA, size 0x2
} ObjectSlot;

typedef struct NO_NAME_30 {
    int SeNo;
	short Timer;
	short ReqFlag;
} NO_NAME_30;

typedef struct SND_REQ
{
	unsigned int SlotNo;
	short PanDelayTime;
	short VolumeDelayTime;
	short Pitch;
	short PitchDelayTime;
	short Speed;
	short SpeedDelayTime;
	char BankNo;
	char ListNo;
	char Priority;
	char Pan;
	char Volume;
	char FxInput;
	char FxLevel;
} SND_REQ;

typedef struct NO_NAME_31
{
	unsigned char Flag;
} NO_NAME_31;

// TODO: find a struct on the DWARF similar to this one that could fit in Ps2AddPrim()
typedef struct UNKNOWN 
{
    int unk0;
    int unk4;
    float unk8;
    int unkC;
} UNKNOWN;

typedef struct ADV_VM_MSG
{
    // total size: 0x14
    float Sx;       // offset 0x0, size 0x4
    float Sy;       // offset 0x4, size 0x4
    int StartMsgNo; // offset 0x8, size 0x4
    int NaviMsgNo;  // offset 0xC, size 0x4
    int MsgType;    // offset 0x10, size 0x4
} ADV_VM_MSG;

typedef struct OPTION 
{
    // total size: 0x9
    char Item;         // offset 0x0, size 0x1
    char MaxItem;      // offset 0x1, size 0x1
    char Item2;        // offset 0x2, size 0x1
    char MaxItem2;     // offset 0x3, size 0x1
    char SelectFlag;   // offset 0x4, size 0x1
    char NextLevel;    // offset 0x5, size 0x1
    char ReturnLevel;  // offset 0x6, size 0x1
    char Switch;       // offset 0x7, size 0x1
    char NextFadeType; // offset 0x8, size 0x1
} OPTION;

typedef struct NJS_SCRVECTOR 
{
    // total size: 0x14
    float x;   // offset 0x0, size 0x4
    float y;   // offset 0x4, size 0x4
    float z;   // offset 0x8, size 0x4
    float iz;  // offset 0xC, size 0x4
    float fog; // offset 0x10, size 0x4
} NJS_SCRVECTOR;

typedef struct CHUNK_HEAD 
{
    // total size: 0x4
    unsigned char ucType;     // offset 0x0, size 0x1
    unsigned char ucHeadBits; // offset 0x1, size 0x1
    unsigned short usSize;    // offset 0x2, size 0x2
} CHUNK_HEAD;

typedef struct CNK_LIGHT
{
    // total size: 0x40
    unsigned int ulState; // offset 0x0, size 0x4
    unsigned int ulMode;  // offset 0x4, size 0x4
    float fNearRR;        // offset 0x8, size 0x4
    float fFarRR;         // offset 0xC, size 0x4
    float fR;             // offset 0x10, size 0x4
    float fG;             // offset 0x14, size 0x4
    float fB;             // offset 0x18, size 0x4
    float fI;             // offset 0x1C, size 0x4
    float fWx;            // offset 0x20, size 0x4
    float fWy;            // offset 0x24, size 0x4
    float fWz;            // offset 0x28, size 0x4
    float pad0;           // offset 0x2C, size 0x4
    float fCx;            // offset 0x30, size 0x4
    float fCy;            // offset 0x34, size 0x4
    float fCz;            // offset 0x38, size 0x4
    float pad1;           // offset 0x3C, size 0x4
} CNK_LIGHT;

typedef struct VU1_COLOR 
{
    // total size: 0x10
    float fR; // offset 0x0, size 0x4
    float fG; // offset 0x4, size 0x4
    float fB; // offset 0x8, size 0x4
    float fA; // offset 0xC, size 0x4
} VU1_COLOR;

typedef struct CNK_LIGHTING
{
    // total size: 0x40
    CNK_LIGHT* pLightTop; // offset 0x0, size 0x4
    int lLightMax;        // offset 0x4, size 0x4
    VU1_COLOR* pDiffuse;  // offset 0x8, size 0x4
    VU1_COLOR* pSpecula;  // offset 0xC, size 0x4
    VU1_COLOR* pAmbient;  // offset 0x10, size 0x4
    unsigned int pad[11]; // offset 0x14, size 0x2C
} CNK_LIGHTING; 

typedef struct PS2_PLANE
{
    // total size: 0x20
    sceVu0FVECTOR norm; // offset 0x0, size 0x10
    sceVu0FVECTOR pos;  // offset 0x10, size 0x10
} PS2_PLANE;

typedef struct IPU_HEADER
{
	// total size: 0x10
    int Frame_rate; // offset 0x0, size 0x4
    int Data_size;  // offset 0x4, size 0x4
    short Width;    // offset 0x8, size 0x2
    short Height;   // offset 0xA, size 0x2
    int Nframe;     // offset 0xC, size 0x4
} IPU_HEADER;

typedef struct READ_BUF
{
    // total size: 0x4020
	unsigned char data[16384]; // offset 0x0, size 0x4000
	IPU_HEADER Ipu_header;     // offset 0x4000, size 0x10
	int status;                // offset 0x4010, size 0x4
    int put;                   // offset 0x4014, size 0x4
    int count;                 // offset 0x4018, size 0x4
    int size;                  // offset 0x401C, size 0x4
} READ_BUF;

typedef struct SNDQUE
{
    // total size: 0x8
	int cmd;     // offset 0x0, size 0x4
	char vol;    // offset 0x4, size 0x1
	char pan;    // offset 0x5, size 0x1
	short pitch; // offset 0x6, size 0x2
} SNDQUE;

typedef struct SNDQUE_DATA
{
    // total size: 0x8
    int cmd;      // offset 0x0, size 0x4
    char data[4]; // offset 0x4, size 0x4
} SNDQUE_DATA;

typedef struct Enemy 
{
    // total size: 0x24
    NJS_POINT3 Pos;        // offset 0x0, size 0xC
    float Dist;            // offset 0xC, size 0x4
    int SeNo;              // offset 0x10, size 0x4
    int SeNoV;             // offset 0x14, size 0x4
    int FadeRate;          // offset 0x18, size 0x4
    char ReqFlag;          // offset 0x1C, size 0x1
    char ReqFlagV;         // offset 0x1D, size 0x1
    char CallFlag;         // offset 0x1E, size 0x1
    char CallFlagV;        // offset 0x1F, size 0x1
    char Prio;             // offset 0x20, size 0x1
    char Pan;              // offset 0x21, size 0x1
    char Vol;              // offset 0x22, size 0x1
    unsigned char VolType; // offset 0x23, size 0x1
} Enemy;

typedef struct EnemySlot
{
	// total size: 0xC
    int SeNo;               // offset 0x0, size 0x4
    unsigned short Flag;    // offset 0x4, size 0x2
    unsigned short Attrib;  // offset 0x6, size 0x2
    unsigned short Prio;    // offset 0x8, size 0x2
    unsigned short EnemyNo; // offset 0xA, size 0x2
} EnemySlot;

typedef struct WPNDAMAGE_WORK
{
    // total size: 0x14
	int flg; // offset 0x0, size 0x4
	int nm_act; // offset 0x4, size 0x4
	int nm_blood; // offset 0x8, size 0x4
	int cb_act; // offset 0xC, size 0x4
	int cb_blood; // offset 0x10, size 0x4
} WPNDAMAGE_WORK;

typedef struct COLBAR_DEF
{
	// total size: 0x8
    unsigned int col1; // offset 0x0, size 0x4
    unsigned int col2; // offset 0x4, size 0x4
} COLBAR_DEF;

typedef struct BH_SCEWORK 
{
    // total size: 0x134
    unsigned char mode0;          // offset 0x0, size 0x1
    unsigned char mode1;          // offset 0x1, size 0x1
    unsigned char mode2;          // offset 0x2, size 0x1
    unsigned char mode3;          // offset 0x3, size 0x1
    unsigned char status;         // offset 0x4, size 0x1
    char loop;                    // offset 0x5, size 0x1
    BH_PWORK* work;               // offset 0x8, size 0x4
    unsigned char* data;          // offset 0xC, size 0x4
    unsigned char* lstack[6];     // offset 0x10, size 0x18
    unsigned char* lcondition[6]; // offset 0x28, size 0x18
    int cnt[4];                   // offset 0x40, size 0x10
    float addpx;                  // offset 0x50, size 0x4
    float addpy;                  // offset 0x54, size 0x4
    float addpz;                  // offset 0x58, size 0x4
    int addax;                    // offset 0x5C, size 0x4
    int adday;                    // offset 0x60, size 0x4
    int addaz;                    // offset 0x64, size 0x4
    float setpx;                  // offset 0x68, size 0x4
    float setpy;                  // offset 0x6C, size 0x4
    float setpz;                  // offset 0x70, size 0x4
    int setax;                    // offset 0x74, size 0x4
    int setay;                    // offset 0x78, size 0x4
    int setaz;                    // offset 0x7C, size 0x4
    unsigned char model_cno;      // offset 0x80, size 0x1
    unsigned char bpx;            // offset 0x81, size 0x1
    unsigned char bpy;            // offset 0x82, size 0x1
    unsigned char bpz;            // offset 0x83, size 0x1
    unsigned char bax;            // offset 0x84, size 0x1
    unsigned char bay;            // offset 0x85, size 0x1
    unsigned char baz;            // offset 0x86, size 0x1
    int wpnr_no;                  // offset 0x88, size 0x4
    int wpnl_no;                  // offset 0x8C, size 0x4
    int ev_eff_no;                // offset 0x90, size 0x4
    int cnt2;                     // offset 0x94, size 0x4
    int cnt3;                     // offset 0x98, size 0x4
    float ips[4][3];              // offset 0x9C, size 0x30
    float ian[4][3];              // offset 0xCC, size 0x30
    unsigned int mtn_md;          // offset 0xFC, size 0x4
    unsigned int mdflg;           // offset 0x100, size 0x4
    int hokan_rate;               // offset 0x104, size 0x4
    int bh_loop_cnt;              // offset 0x108, size 0x4
    float e_lgt[2][5];            // offset 0x10C, size 0x28
} BH_SCEWORK; 

typedef struct SDCOM_FUNCTBL
{
    // total size: 0x4
    void (*FuncName)(int); // offset 0x0, size 0x4
} SDCOM_FUNCTBL;

typedef struct STCAM_WRK
{
	// total size: 0xC0
    NJS_MATRIX cmat1;  // offset 0x0, size 0x40
    NJS_MATRIX rotmat; // offset 0x40, size 0x40
    NJS_POINT3 pos_0;  // offset 0x80, size 0xC
    NJS_POINT3 pos_1;  // offset 0x8C, size 0xC
    int ax;            // offset 0x98, size 0x4
    int ay;            // offset 0x9C, size 0x4
    int az;            // offset 0xA0, size 0x4
    int cax;           // offset 0xA4, size 0x4
    int cay;           // offset 0xA8, size 0x4
    int caz;           // offset 0xAC, size 0x4
    float dis;         // offset 0xB0, size 0x4
    float Dummy[3];    // offset 0xB4, size 0xC
} STCAM_WRK;

typedef struct FV_WORK
{
    // total size: 0xD0
	NJS_ARGB col;           // offset 0x0, size 0x10
	NJS_TEXNAME fstx[1];    // offset 0x10, size 0xC
	NJS_TEXLIST fstx_list;  // offset 0x1C, size 0x8
	NJS_TEXNAME fbtx[1];    // offset 0x24, size 0xC
	NJS_TEXLIST fbtx_list;  // offset 0x30, size 0x8
	int afsmode;            // offset 0x38, size 0x4
    int ang00;              // offset 0x3C, size 0x4
    int mode_00;            // offset 0x40, size 0x4
    int mode_01;            // offset 0x44, size 0x4
    int mode_02;            // offset 0x48, size 0x4
    int mode_03;            // offset 0x4C, size 0x4
    unsigned int page;      // offset 0x50, size 0x4
    int rdsz;               // offset 0x54, size 0x4
    int tag;                // offset 0x58, size 0x4
    int move;               // offset 0x5C, size 0x4
    unsigned int part_id;   // offset 0x60, size 0x4
    int filenum;            // offset 0x64, size 0x4
    int pagewait00;         // offset 0x68, size 0x4
    int pagewait01;         // offset 0x6C, size 0x4
    short bufnum;           // offset 0x70, size 0x2
    short filecsr;          // offset 0x72, size 0x2
    short roll;             // offset 0x74, size 0x2
    short j;                // offset 0x76, size 0x2
    short k;                // offset 0x78, size 0x2
    short z;                // offset 0x7A, size 0x2
    short koma[16];         // offset 0x7C, size 0x20
    short koma2[16];        // offset 0x9C, size 0x20
    unsigned char scrol;    // offset 0xBC, size 0x1
    unsigned char scrolcnt; // offset 0xBD, size 0x1
    unsigned char flg;      // offset 0xBE, size 0x1
    unsigned char* fsp;     // offset 0xC0, size 0x4
    unsigned char* fspr;    // offset 0xC4, size 0x4
    unsigned char* fspl;    // offset 0xC8, size 0x4
    unsigned short tex_flg; // offset 0xCC, size 0x2
} FV_WORK;

typedef struct PARTS
{
    // total size: 0x30
    float pos[3];            // offset 0x0, size 0xC
    short ang;               // offset 0xC, size 0x2
    unsigned char atr;       // offset 0xE, size 0x1
    char anim;               // offset 0xF, size 0x1
    unsigned char cen_no;    // offset 0x10, size 0x1
    unsigned char parts_num; // offset 0x11, size 0x1
    float move;              // offset 0x14, size 0x4
    unsigned char setnum;    // offset 0x18, size 0x1
    NJS_ARGB col;            // offset 0x1C, size 0x10
    unsigned char color;     // offset 0x2C, size 0x1
} PARTS;

typedef struct S_WORK
{
    // total size: 0xD8
	NJS_TEXNAME subtx[5];         // offset 0x0, size 0x3C
	NJS_TEXLIST subtx_list;       // offset 0x3C, size 0x8
	unsigned short subscreenmode; // offset 0x44, size 0x2
    unsigned int statusflg;       // offset 0x48, size 0x4
    unsigned short testmode;      // offset 0x4C, size 0x2
    unsigned int itmwrk;          // offset 0x50, size 0x4
    unsigned int itemid;          // offset 0x54, size 0x4
    unsigned short cmbitm;        // offset 0x58, size 0x2
    short open1;                  // offset 0x5A, size 0x2
    short open2;                  // offset 0x5C, size 0x2
    unsigned short mode;          // offset 0x5E, size 0x2
    short ips1;                   // offset 0x60, size 0x2
    short ipsdisp;                // offset 0x62, size 0x2
    unsigned int listcsr_0;       // offset 0x64, size 0x4
    unsigned int listcsr_1;       // offset 0x68, size 0x4
    unsigned int listcsr_2;       // offset 0x6C, size 0x4
    unsigned int listcsr_3;       // offset 0x70, size 0x4
    float color00;                // offset 0x74, size 0x4
    unsigned short colorcount;    // offset 0x78, size 0x2
    unsigned short colorflg;      // offset 0x7A, size 0x2
    unsigned char maincsr;        // offset 0x7C, size 0x1
    unsigned char subcsr;         // offset 0x7D, size 0x1
    unsigned int* pip;            // offset 0x80, size 0x4
    unsigned int* bxp;            // offset 0x84, size 0x4
    unsigned int* gb;             // offset 0x88, size 0x4
    unsigned char* ssp;           // offset 0x8C, size 0x4
    char wait_;                   // offset 0x90, size 0x1
    char wait;                    // offset 0x91, size 0x1
    char number;                  // offset 0x92, size 0x1
    char flag;                    // offset 0x93, size 0x1
    unsigned char hp;             // offset 0x94, size 0x1
    unsigned char abc;            // offset 0x95, size 0x1
    unsigned char dnum;           // offset 0x96, size 0x1
    char dflg;                    // offset 0x97, size 0x1
    unsigned char keywait;        // offset 0x98, size 0x1
    unsigned char boxwait;        // offset 0x99, size 0x1
    short actioncount;            // offset 0x9A, size 0x2
	NJS_SCREEN scr;               // offset 0x9C, size 0x14
	NJS_POINT2 clip[2];           // offset 0xB0, size 0x10
	unsigned char flgchk;         // offset 0xC0, size 0x1
    unsigned char flgtest;        // offset 0xC1, size 0x1
    unsigned char* sspb;          // offset 0xC4, size 0x4
    unsigned char sprflg;         // offset 0xC8, size 0x1
    char number_;                 // offset 0xC9, size 0x1
    char flag_;                   // offset 0xCA, size 0x1
    unsigned short mesid;         // offset 0xCC, size 0x2
    unsigned short taskloop;      // offset 0xCE, size 0x2
    unsigned short wn;            // offset 0xD0, size 0x2
    unsigned short wn_num;        // offset 0xD2, size 0x2
    unsigned char* subp;          // offset 0xD4, size 0x4
} S_WORK;

typedef struct MW
{
    // total size: 0x34
	NJS_POINT3 pos;     // offset 0x0, size 0xC
	void* tex_p;        // offset 0xC, size 0x4
    void* mdl_p;        // offset 0x10, size 0x4
    int ang[3];         // offset 0x14, size 0xC
    int rdid;           // offset 0x20, size 0x4
    int ax1;            // offset 0x24, size 0x4
    int ay1;            // offset 0x28, size 0x4
    int az1;            // offset 0x2C, size 0x4
    unsigned short flg; // offset 0x30, size 0x2
} MW;

typedef struct SITEM
{
    // total size: 0x54
	ML_WORK mdl;               // offset 0x0, size 0x18
	MW mw;                     // offset 0x18, size 0x34
	unsigned char* keep;       // offset 0x4C, size 0x4
    unsigned char* keepbackup; // offset 0x50, size 0x4
} SITEM;

typedef struct MDSIZE_WORK
{
	// total size: 0x8
    short sWidth;  // offset 0x0, size 0x2
    short sHeight; // offset 0x2, size 0x2
    short sDispX;  // offset 0x4, size 0x2
    short sDispY;  // offset 0x6, size 0x2
} MDSIZE_WORK;

typedef struct CNK_PRIM_BUF 
{
    // total size: 0x30
    float fS;            // offset 0x0, size 0x4
    float fT;            // offset 0x4, size 0x4
    float fQ;            // offset 0x8, size 0x4
    unsigned int ulKick; // offset 0xC, size 0x4
    float fR;            // offset 0x10, size 0x4
    float fG;            // offset 0x14, size 0x4
    float fB;            // offset 0x18, size 0x4
    float fA;            // offset 0x1C, size 0x4
    float fX;            // offset 0x20, size 0x4
    float fY;            // offset 0x24, size 0x4
    float fZ;            // offset 0x28, size 0x4
    float fF;            // offset 0x2C, size 0x4
} CNK_PRIM_BUF;

typedef struct NJS_PRIM
{
    // total size: 0x28
    float px;        // offset 0x0, size 0x4
    float py;        // offset 0x4, size 0x4
    float x0;        // offset 0x8, size 0x4
    float y0;        // offset 0xC, size 0x4
    float x1;        // offset 0x10, size 0x4
    float y1;        // offset 0x14, size 0x4
    NJS_COLOR uv[4]; // offset 0x18, size 0x10
} NJS_PRIM;

typedef struct NJS_MKEY 
{
    // total size: 0xC
    float key[3]; // offset 0x0, size 0xC
} NJS_MKEY;

typedef struct UV_WORK 
{
    // total size: 0x10
    float u;  // offset 0x0, size 0x4
    float v;  // offset 0x4, size 0x4
    float xs; // offset 0x8, size 0x4
    float ys; // offset 0xC, size 0x4
} UV_WORK;

typedef struct EFF_ANIM 
{
    // total size: 0x4
    short ptrn;  // offset 0x0, size 0x2
    short timer; // offset 0x2, size 0x2
} EFF_ANIM;

typedef struct BP_WORK 
{
    // total size: 0x40
    NJS_POINT3 off_pos; // offset 0x0, size 0xC
    int srd_dir;        // offset 0xC, size 0x4
    float srd_pos;      // offset 0x10, size 0x4
    float bld_spd;      // offset 0x14, size 0x4
    float srt_spd[5];   // offset 0x18, size 0x14
    int srt_dir[5];     // offset 0x2C, size 0x14
} BP_WORK;

typedef struct GA_WORK 
{
    // total size: 0x44
    float px;            // offset 0x0, size 0x4
    float py;            // offset 0x4, size 0x4
    float pz;            // offset 0x8, size 0x4
    float vx;            // offset 0xC, size 0x4
    float vy;            // offset 0x10, size 0x4
    float vz;            // offset 0x14, size 0x4
    float gx;            // offset 0x18, size 0x4
    float gy;            // offset 0x1C, size 0x4
    float gz;            // offset 0x20, size 0x4
    unsigned int at_flg; // offset 0x24, size 0x4
    int wpn_no;          // offset 0x28, size 0x4
    float r;             // offset 0x2C, size 0x4
    float l;             // offset 0x30, size 0x4
    float rn;            // offset 0x34, size 0x4
    float rmax;          // offset 0x38, size 0x4
    int ax;              // offset 0x3C, size 0x4
    int ay;              // offset 0x40, size 0x4
} GA_WORK;

typedef struct BLOOD_TBL
{
    // total size: 0x1C
    int flg; // offset 0x0, size 0x4
    NJS_POINT3 ofp; // offset 0x4, size 0xC
    float rx; // offset 0x10, size 0x4
    float ry; // offset 0x14, size 0x4
    float rz; // offset 0x18, size 0x4
} BLOOD_TBL;

typedef struct DMG_REACT
{
    // total size: 0x7
	char type[3]; // offset 0x0, size 0x3
	char bloodstain[3]; // offset 0x3, size 0x3
	char exef; // offset 0x6, size 0x1
} DMG_REACT;

typedef struct STG_WORK 
{
    // total size: 0x4
    char stg_no;  // offset 0x0, size 0x1
    char rom_no;  // offset 0x1, size 0x1
    char flr_no;  // offset 0x2, size 0x1
    char ene_max; // offset 0x3, size 0x1
} STG_WORK;

// constant definition for ClutType, ImageType in picture header
enum TIM2_gattr_type {
	TIM2_NONE = 0,			// no CLUT (for ClutType)
	TIM2_RGB16,				// 16 bit color (for both of ClutType, ImageType)
	TIM2_RGB24,				// 24 bit color (for ImageType)
	TIM2_RGB32,				// 32 bit color (for ClutType, ImageType)
	TIM2_IDTEX4,			// 16 color texture (for ImageType)
	TIM2_IDTEX8				// 256 color texture (for ImageType)
};

typedef struct {
    int isOnCD;		
    int size;
    sceCdlFILE fp;	
    unsigned char* iopBuf;
    int fd;		
} StrFile;

typedef struct {
    long pts;
    long dts;
    int pos;
    int len;
} TimeStamp;

/* vobuf.h */

#define N_VOBUF 5

#define VOBUF_STATUS_    0
#define VOBUF_STATUS_TOPDONE  1
#define VOBUF_STATUS_FULL     2

#define MAX_WIDTH 720
#define MAX_HEIGHT 480

#define N_LDTAGS (MAX_WIDTH/16 * MAX_HEIGHT/16 * 6 + 10)

#define bound(val, x) ((((val) + (x) - 1) / (x))*(x))

typedef struct {
    u_char v[MAX_WIDTH * MAX_HEIGHT * 4];
} VoData;

typedef struct {
    int status;		// status
    int dummy[15];	// this is to adjust D$ line
    u_int v[N_VOBUF][bound((N_LDTAGS+100)*4, 64)];
} VoTag;

typedef struct {
    VoData *data;	    // data array
    VoTag *tag;		    // tag array for path3 transfer
    volatile int write;	    // write position
    volatile int count;	    // the number of images in VoBuf
    int size;		    // total number of elements in VoBuf
} VoBuf;

/* vibuf.c */

#define DMA_ID_REFE	0
#define DMA_ID_NEXT	2
#define DMA_ID_REF	3

#define WAITSEMA(v) WaitSema(v)
#define SIGNALSEMA(v) SignalSema(v)

#define REST	2

#define TAG_ADDR(i)	((u_int)DmaAddr(f->tag + i))
#define DATA_ADDR(i)	((u_int)f->data + VIBUF_ELM_SIZE * (i))
#define WRAP_ADDR(addr) ((u_int)(f->data)     + (((u_int)(addr) - (u_int)(f->data)) % (VIBUF_ELM_SIZE * f->n)))

// custom macros
#define TAG_ADDR_EX(i)	((u_int)DmaAddr(videoDec.vibuf.tag + i))
#define DATA_ADDR_EX(i)	((u_int)videoDec.vibuf.data + VIBUF_ELM_SIZE * (i))
#define WRAP_ADDR_EX(addr) ((u_int)(videoDec.vibuf.data)     + (((u_int)(addr) - (u_int)(videoDec.vibuf.data)) % (VIBUF_ELM_SIZE * videoDec.vibuf.n)))

#define IsInRegion(i,start,len,n)  (     (0 <= (((i) + (n) - (start)) % (n))) &&     ((((i) + (n) - (start)) % (n)) < (len)))

#define FS(f)	((f->dmaStart + f->dmaN) * VIBUF_ELM_SIZE)
#define FN(f)	((f->n - REST -  f->dmaN) * VIBUF_ELM_SIZE)

typedef union {
    u_long128	q;
    u_long 	l[2];
    u_int  	i[4];
    u_short	s[8];
    u_char	c[16];
} QWORD;

#define SCE_GS_ALPHA_AS         (0)
#define SCE_GS_ALPHA_AD         (1)
#define SCE_GS_ALPHA_FIX        (2)

#define SCR_WIDTH 640
#define SCR_HEIGHT 224

#define GS_X_COORD(x) ((2048 - (SCR_WIDTH / 2) + x) * 16)
#define GS_Y_COORD(y) ((2048 - (SCR_HEIGHT / 2) + y) * 16)

#define SCR_WIDTH2 640
#define SCR_HEIGHT2 480

#define GS_X_COORD_MOD(x) ((2048 - (SCR_WIDTH2 / 2) + x) * 16)
#define GS_Y_COORD_MOD(y) ((2048 - (SCR_HEIGHT2 / 2) + y) * 16)

#define GS_COORD(v) ((unsigned int)((v) * 16))

#define WORKBASE (0x70000000)

#define DMAnext             (2<<28)
#define DMAend  (7<<28)

#define    SCE_GS_FALSE         (0)
#define    SCE_GS_TRUE          (1)

#define SCE_GS_ALPHA_NEVER      (0)

#define    SCE_GS_AFAIL_KEEP    (0)
#define    SCE_GS_AFAIL_FB_ONLY (1)

#define SCE_GS_DEPTH_ALWAYS     (1)
#define SCE_GS_DEPTH_GEQUAL     (2)
#define SCE_GS_ALPHA_GEQUAL     (5)
#define SCE_GS_ALPHA_GREATER    (6)

#define SCE_GS_ALPHA_CS         (0)
#define SCE_GS_ALPHA_CD         (1)

#define SCE_GS_ALPHA_FIX        (2)

#define DMArefe             (0<<28)
#define DMAcnt              (1<<28)
#define DMAnext             (2<<28)
#define DMAref              (3<<28)
#define DMArefs             (4<<28)
#define DMAcall             (5<<28)
#define DMAret              (6<<28)
#define DMAend              (7<<28)

#define SCE_GS_CLAMP            (1)

#define SCE_GS_REPEAT           (0)

#define DISP_WIDTH 640
#define DISP_HEIGHT 480

#define UNCACHED_BASE 0x20000000
#define UNCACHED(x) ((u_int)(x)|UNCACHED_BASE)

// TODO: include the following define from cpureg.h
#define	SR_CU0		0x10000000	/* Coprocessor 0 usable */

#define UNCMASK 0x0fffffff
#define UNCBASE 0x20000000

#define PP_NARG(...) \
    PP_NARG_(__VA_ARGS__, PP_RSEQ_N())

#define PP_NARG_(...) \
    PP_ARG_N(__VA_ARGS__)

#define PP_ARG_N( \
     _1,_2,_3,_4,_5,_6,_7,_8,_9,_10, \
    _11,_12,_13,_14,_15,_16,N,...) N

#define PP_RSEQ_N() \
    16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define CAT(a,b) CAT_(a,b)
#define CAT_(a,b) a##b

#define GIF_REGLIST(...) \
    CAT(GIF_REGLIST_, PP_NARG(__VA_ARGS__))(__VA_ARGS__)

#define GIF_REGLIST_3(a0,a1,a2) \
    ((long)(a0) << (0 * 4)) | \
    ((long)(a1) << (1 * 4)) | \
    ((long)(a2) << (2 * 4))

#endif
