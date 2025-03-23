typedef struct NO_NAME_1
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
} NO_NAME_1;

typedef struct NO_NAME_2
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	NJS_CNK_OBJECT* objP;
	NJS_TEXLIST* texP;
	NO_NAME_1* owP;
} NO_NAME_2;

typedef struct NO_NAME_3
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	NJS_MDATA2* md2P;
	unsigned short* atrP;
} NO_NAME_3;

typedef struct NO_NAME_4
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	char flr_nob;
	unsigned char mdlver;
	unsigned char param;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	float ar;
	float aw;
	float ah;
	float ad;
	float car;
	float cah;
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	float gpx;
	float gpy;
	float gpz;
	float lox;
	float loy;
	float loz;
	float aox;
	float aoy;
	float aoz;
	float spd;
	unsigned int flg2;
	unsigned int mdflg;
	unsigned int stflg;
	unsigned int Dummy3;
	int draw_tp;
	int mdl_n;
	void* mskp;
	unsigned int Dummy[1];
	int* skp[16];
	NJS_CNK_OBJECT* mbp[16];
	NJS_TEXLIST* txp[16];
	NO_NAME_2 mdl[16];
	NO_NAME_2* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	NJS_CNK_OBJECT* obj_a;
	NJS_CNK_OBJECT* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	NO_NAME_3* mnwP;
	NO_NAME_3* mnwPb;
	unsigned int mtn_attr;
	unsigned int mtn_no;
	int frm_no;
	unsigned int frm_mode;
	int hokan_rate;
	unsigned int hokan_count;
	unsigned int hokan_ctbak;
	int mtn_add;
	unsigned int mtn_md;
	unsigned char* mtn_tp;
	int axp;
	int ayp;
	int azp;
	short psh_ct;
	short psh_idx;
	int idx_ct;
	int mtn_chk;
	float ofx;
	float ofy;
	float ofz;
	float sx;
	float sy;
	float sz;
	float sxb;
	float syb;
	float szb;
	float xn;
	float yn;
	float zn;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	unsigned char* objbak;
	NJS_SPHERE cspr;
	int pn;
	NJS_POLYGON_VTX* pvp;
	NJS_TEXTURE_VTX* tvp;
	NJS_POLYGON_VTX pv[4];
	NJS_TEXTURE_VTX tv[4];
	int bl_src;
	int bl_dst;
	int ani_ct;
	int tex_id;
	int aspd;
	unsigned int gidx;
	int bank;
	char jno[16];
	char hide[4];
	void(*func)(void*);
	int idx;
	int Dummy2;
} NO_NAME_4;

typedef struct NO_NAME_5
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
} NO_NAME_5;

typedef struct NO_NAME_6
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	short flr_no;
	unsigned short mdlver;
	float px;
	float py;
	float pz;
	float sx;
	float sy;
	float sz;
	short ay;
	short ax;
} NO_NAME_6;

typedef struct NO_NAME_7
{
	short jnt_a;
	short jnt_b;
	int cap_r;
} NO_NAME_7;

typedef struct BH_PWORK
{
	// total size: 0x580
    unsigned int flg; // offset 0x0, size 0x4
    unsigned short id; // offset 0x4, size 0x2
    unsigned short type; // offset 0x6, size 0x2
    char flr_no; // offset 0x8, size 0x1
    char flr_nob; // offset 0x9, size 0x1
    unsigned char mdlver; // offset 0xA, size 0x1
    unsigned char param; // offset 0xB, size 0x1
    unsigned char mode0; // offset 0xC, size 0x1
    unsigned char mode1; // offset 0xD, size 0x1
    unsigned char mode2; // offset 0xE, size 0x1
    unsigned char mode3; // offset 0xF, size 0x1
    float px; // offset 0x10, size 0x4
    float py; // offset 0x14, size 0x4
    float pz; // offset 0x18, size 0x4
    int ax; // offset 0x1C, size 0x4
    int ay; // offset 0x20, size 0x4
    int az; // offset 0x24, size 0x4
    float ar; // offset 0x28, size 0x4
    float aw; // offset 0x2C, size 0x4
    float ah; // offset 0x30, size 0x4
    float ad; // offset 0x34, size 0x4
    float car; // offset 0x38, size 0x4
    float cah; // offset 0x3C, size 0x4
    float pxb; // offset 0x40, size 0x4
    float pyb; // offset 0x44, size 0x4
    float pzb; // offset 0x48, size 0x4
    int axb; // offset 0x4C, size 0x4
    int ayb; // offset 0x50, size 0x4
    int azb; // offset 0x54, size 0x4
    float gpx; // offset 0x58, size 0x4
    float gpy; // offset 0x5C, size 0x4
    float gpz; // offset 0x60, size 0x4
    float lox; // offset 0x64, size 0x4
    float loy; // offset 0x68, size 0x4
    float loz; // offset 0x6C, size 0x4
    float aox; // offset 0x70, size 0x4
    float aoy; // offset 0x74, size 0x4
    float aoz; // offset 0x78, size 0x4
    float spd; // offset 0x7C, size 0x4
    unsigned int flg2; // offset 0x80, size 0x4
    unsigned int mdflg; // offset 0x84, size 0x4
    unsigned int stflg; // offset 0x88, size 0x4
    unsigned int Dummy3; // offset 0x8C, size 0x4
    int draw_tp; // offset 0x90, size 0x4
    int mdl_n; // offset 0x94, size 0x4
    void * mskp; // offset 0x98, size 0x4
    unsigned int Dummy[1]; // offset 0x9C, size 0x4
    int * skp[16]; // offset 0xA0, size 0x40
    NJS_CNK_OBJECT * mbp[16]; // offset 0xE0, size 0x40
	NJS_TEXLIST* txp[16]; // offset 0x120, size 0x40
	NO_NAME_2 mdl[16]; // offset 0x160, size 0x180
	NO_NAME_2* mlwP; // offset 0x2E0, size 0x4
	unsigned int mdl_no; // offset 0x2E4, size 0x4
    int lkono; // offset 0x2E8, size 0x4
    unsigned char * lkwkp; // offset 0x2EC, size 0x4
    unsigned char * exp0; // offset 0x2F0, size 0x4
    unsigned char * exp1; // offset 0x2F4, size 0x4
    unsigned char * exp2; // offset 0x2F8, size 0x4
    unsigned char * exp3; // offset 0x2FC, size 0x4
    unsigned char mtxbuf[64]; // offset 0x300, size 0x40
    float (* mtx)[16]; // offset 0x340, size 0x4
    NJS_CNK_OBJECT * obj_a; // offset 0x344, size 0x4
    NJS_CNK_OBJECT * obj_b; // offset 0x348, size 0x4
    float shp_ct; // offset 0x34C, size 0x4
    char clp_jno[8]; // offset 0x350, size 0x8
    int lok_jno; // offset 0x358, size 0x4
	NO_NAME_3* mnwP; // offset 0x35C, size 0x4
	NO_NAME_3* mnwPb; // offset 0x360, size 0x4
	unsigned int mtn_attr; // offset 0x364, size 0x4
    unsigned int mtn_no; // offset 0x368, size 0x4
    int frm_no; // offset 0x36C, size 0x4
    unsigned int frm_mode; // offset 0x370, size 0x4
    int hokan_rate; // offset 0x374, size 0x4
    unsigned int hokan_count; // offset 0x378, size 0x4
    unsigned int hokan_ctbak; // offset 0x37C, size 0x4
    int mtn_add; // offset 0x380, size 0x4
    unsigned int mtn_md; // offset 0x384, size 0x4
    unsigned char * mtn_tp; // offset 0x388, size 0x4
    int axp; // offset 0x38C, size 0x4
    int ayp; // offset 0x390, size 0x4
    int azp; // offset 0x394, size 0x4
    short psh_ct; // offset 0x398, size 0x2
    short psh_idx; // offset 0x39A, size 0x2
    int idx_ct; // offset 0x39C, size 0x4
    int mtn_chk; // offset 0x3A0, size 0x4
    float ofx; // offset 0x3A4, size 0x4
    float ofy; // offset 0x3A8, size 0x4
    float ofz; // offset 0x3AC, size 0x4
    float sx; // offset 0x3B0, size 0x4
    float sy; // offset 0x3B4, size 0x4
    float sz; // offset 0x3B8, size 0x4
    float sxb; // offset 0x3BC, size 0x4
    float syb; // offset 0x3C0, size 0x4
    float szb; // offset 0x3C4, size 0x4
    float xn; // offset 0x3C8, size 0x4
    float yn; // offset 0x3CC, size 0x4
    float zn; // offset 0x3D0, size 0x4
    int ct0; // offset 0x3D4, size 0x4
    int ct1; // offset 0x3D8, size 0x4
    int ct2; // offset 0x3DC, size 0x4
    int ct3; // offset 0x3E0, size 0x4
    int wpnr_no; // offset 0x3E4, size 0x4
    int wpnl_no; // offset 0x3E8, size 0x4
    unsigned int at_flg; // offset 0x3EC, size 0x4
	NJS_CAPSULE watr; // offset 0x3F0, size 0x1C
	NO_NAME_7* cpcl; // offset 0x40C, size 0x4
	short wax; // offset 0x410, size 0x2
    short way; // offset 0x412, size 0x2
    short waz; // offset 0x414, size 0x2
    short waxp; // offset 0x416, size 0x2
    short wayp; // offset 0x418, size 0x2
    short wazp; // offset 0x41A, size 0x2
    int hp; // offset 0x41C, size 0x4
    int dam[64]; // offset 0x420, size 0x100
    int djnt_no; // offset 0x520, size 0x4
    int cpcl_no; // offset 0x524, size 0x4
    int dax; // offset 0x528, size 0x4
    int day; // offset 0x52C, size 0x4
    float dpx; // offset 0x530, size 0x4
    float dpy; // offset 0x534, size 0x4
    float dpz; // offset 0x538, size 0x4
    float dvx; // offset 0x53C, size 0x4
    float dvy; // offset 0x540, size 0x4
    float dvz; // offset 0x544, size 0x4
    int flr_snd; // offset 0x548, size 0x4
    int ko_num; // offset 0x54C, size 0x4
    int footeff; // offset 0x550, size 0x4
    int src_no; // offset 0x554, size 0x4
    unsigned char * kdnp; // offset 0x558, size 0x4
    int kdnidx; // offset 0x55C, size 0x4
    void * dan_ap; // offset 0x560, size 0x4
    unsigned int comb_flg; // offset 0x564, size 0x4
    unsigned int comb_wep; // offset 0x568, size 0x4
    int comb_pnt; // offset 0x56C, size 0x4
    int comb_timeout; // offset 0x570, size 0x4
    int total_dam; // offset 0x574, size 0x4
    unsigned int Dummy2[2]; // offset 0x578, size 0x8
} BH_PWORK;

typedef struct NO_NAME_8
{
	unsigned int flg;
	unsigned int type;
	int aspd;
	int lkflg;
	int lkno;
	int lkono;
	int lsrc;
	float px;
	float py;
	float pz;
	float lx;
	float ly;
	float lz;
	float vx;
	float vy;
	float vz;
	float spc;
	float dif;
	float amb;
	float r;
	float g;
	float b;
	float nr;
	float fr;
	int iang;
	int oang;
	int ax;
	int ay;
	int az;
	unsigned int mode;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	float wpx;
	float wpy;
	float wpz;
	float wvx;
	float wvy;
	float wvz;
	float wspc;
	float wdif;
	float wamb;
	float wr;
	float wg;
	float wb;
	float wnr;
	float wfr;
	int wiang;
	int woang;
	int wax;
	int way;
	int waz;
	unsigned char* lkwkp;
	unsigned char* exp;
	NJS_LIGHT_PTR* light;
} NO_NAME_8;

typedef struct NO_NAME_9
{
	NJS_POINT3 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
} NO_NAME_9;

typedef struct NO_NAME_10
{
	unsigned char flg;
	unsigned char type;
	unsigned char id;
	char flr_no;
	unsigned int attr;
	float px;
	float py;
	float pz;
	float w;
	float h;
	float d;
	unsigned char prm0;
	unsigned char prm1;
	unsigned char prm2;
	unsigned char prm3;
} NO_NAME_10; 

typedef struct DOOR_WORK
{
	unsigned int flg;
	char stg_no;
	char rom_no;
	unsigned char pos_no;
	unsigned char dor_tp;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
} DOOR_WORK;

// similar but not quite like NJS_CAPSULE
typedef struct CONICAL_FRUSTUM
{
	NJS_POINT3 c1;
	NJS_POINT3 c2;
	float r1;
	float r2;
} CONICAL_FRUSTUM;

typedef struct SYS_WORK
{
	// total size: 0x2ACF0
    unsigned int ssd_ver; // offset 0x0, size 0x4
    unsigned int ssd_flg; // offset 0x4, size 0x4
    unsigned int ssd_reserve; // offset 0x8, size 0x4
    char keytype; // offset 0xC, size 0x1
    char adjust_x; // offset 0xD, size 0x1
    char adjust_y; // offset 0xE, size 0x1
    char vibration; // offset 0xF, size 0x1
    int best_tm[8]; // offset 0x10, size 0x20
    unsigned int sys_partid; // offset 0x30, size 0x4
    unsigned int itm_partid; // offset 0x34, size 0x4
    unsigned int fil_partid; // offset 0x38, size 0x4
    unsigned int dor_partid; // offset 0x3C, size 0x4
    unsigned int ss_flg; // offset 0x40, size 0x4
    int pdm_no; // offset 0x44, size 0x4
    unsigned int typ_flg; // offset 0x48, size 0x4
    unsigned short typ_md0; // offset 0x4C, size 0x2
    unsigned short typ_md1; // offset 0x4E, size 0x2
    void * typ_exp; // offset 0x50, size 0x4
    unsigned int tk_flg; // offset 0x54, size 0x4
    unsigned int ts_flg; // offset 0x58, size 0x4
    unsigned int gm_flg; // offset 0x5C, size 0x4
    unsigned int st_flg; // offset 0x60, size 0x4
    unsigned int cb_flg; // offset 0x64, size 0x4
    unsigned int rm_flg; // offset 0x68, size 0x4
    unsigned int pt_flg; // offset 0x6C, size 0x4
    unsigned int sp_flg; // offset 0x70, size 0x4
    unsigned int ef_flg; // offset 0x74, size 0x4
    unsigned int error; // offset 0x78, size 0x4
    unsigned int version; // offset 0x7C, size 0x4
    int save_ct; // offset 0x80, size 0x4
    char ply_id; // offset 0x84, size 0x1
    char stg_no; // offset 0x85, size 0x1
    char rom_no; // offset 0x86, size 0x1
    char rcase; // offset 0x87, size 0x1
    char pos_no; // offset 0x88, size 0x1
    char cut_no; // offset 0x89, size 0x1
    char flr_no; // offset 0x8A, size 0x1
    char reserve0; // offset 0x8B, size 0x1
    int gm_mode; // offset 0x8C, size 0x4
    unsigned int ev_flg[32]; // offset 0x90, size 0x80
    unsigned int it_flg[16]; // offset 0x110, size 0x40
    unsigned int ic_flg[16]; // offset 0x150, size 0x40
    unsigned int ed_flg[32]; // offset 0x190, size 0x80
    unsigned int ky_flg[16]; // offset 0x210, size 0x40
    unsigned int mp_flg[8]; // offset 0x250, size 0x20
    unsigned int itm[384]; // offset 0x270, size 0x600
    unsigned int ply_stflg[4]; // offset 0x870, size 0x10
	NJS_POINT3 ply_pos; // offset 0x880, size 0xC
	int ply_ang; // offset 0x88C, size 0x4
    char ply_wno[4]; // offset 0x890, size 0x4
    short ply_hp[4]; // offset 0x894, size 0x8
    unsigned char evt_posno[4]; // offset 0x89C, size 0x4
    int time; // offset 0x8A0, size 0x4
    int stv_tm; // offset 0x8A4, size 0x4
    short spray_ct; // offset 0x8A8, size 0x2
    short retry_ct; // offset 0x8AA, size 0x2
    short clear_ct; // offset 0x8AC, size 0x2
    short reserve1; // offset 0x8AE, size 0x2
    unsigned int save_end; // offset 0x8B0, size 0x4
    char stg_nob; // offset 0x8B4, size 0x1
    char rom_nob; // offset 0x8B5, size 0x1
    char pos_nob; // offset 0x8B6, size 0x1
    char rcase_b; // offset 0x8B7, size 0x1
    unsigned int en_flg[4]; // offset 0x8B8, size 0x10
	NJS_TEXLIST* et_lp[16][16][100]; // offset 0x8C8, size 0x19000
	NJS_TEXLIST* ot_lp[1300]; // offset 0x198C8, size 0x1450
	NJS_TEXLIST* it_lp[200]; // offset 0x1AD18, size 0x320
	int eft_n; // offset 0x1B038, size 0x4
	NJS_TEXLIST* eft_lp[8]; // offset 0x1B03C, size 0x20
	int loop_ct; // offset 0x1B05C, size 0x4
    int loop_now; // offset 0x1B060, size 0x4
    int cng_pid; // offset 0x1B064, size 0x4
	PDS_PERIPHERAL* p1per; // offset 0x1B068, size 0x4
	PDS_PERIPHERAL* p2per; // offset 0x1B06C, size 0x4
	PDS_PERIPHERAL* kbper; // offset 0x1B070, size 0x4
	PDS_PERIPHERAL* msper; // offset 0x1B074, size 0x4
	PDS_PERIPHERAL ms_per; // offset 0x1B078, size 0x34
	int pad_port; // offset 0x1B0AC, size 0x4
    unsigned int pad_on; // offset 0x1B0B0, size 0x4
    unsigned int pad_oncpy; // offset 0x1B0B4, size 0x4
    unsigned int pad_ps; // offset 0x1B0B8, size 0x4
    unsigned int pad_rs; // offset 0x1B0BC, size 0x4
    unsigned int pad_old; // offset 0x1B0C0, size 0x4
    unsigned int pad_onb; // offset 0x1B0C4, size 0x4
    unsigned int pad_psb; // offset 0x1B0C8, size 0x4
    unsigned int pad_oldb; // offset 0x1B0CC, size 0x4
    short pad_ax; // offset 0x1B0D0, size 0x2
    short pad_ay; // offset 0x1B0D2, size 0x2
    short pad_dx; // offset 0x1B0D4, size 0x2
    short pad_dy; // offset 0x1B0D6, size 0x2
    unsigned short pad_ar; // offset 0x1B0D8, size 0x2
    unsigned short pad_al; // offset 0x1B0DA, size 0x2
    int fixcno; // offset 0x1B0DC, size 0x4
    int fixkno; // offset 0x1B0E0, size 0x4
    unsigned int exm_attr; // offset 0x1B0E4, size 0x4
    short evc_no; // offset 0x1B0E8, size 0x2
    short evc_kn; // offset 0x1B0EA, size 0x2
    short evc_ono; // offset 0x1B0EC, size 0x2
    short evc_okn; // offset 0x1B0EE, size 0x2
    int evc_sc; // offset 0x1B0F0, size 0x4
    unsigned char mn_mode0; // offset 0x1B0F4, size 0x1
    unsigned char mn_mode1; // offset 0x1B0F5, size 0x1
    unsigned char mn_mode2; // offset 0x1B0F6, size 0x1
    unsigned char mn_mode3; // offset 0x1B0F7, size 0x1
    unsigned char mn_md0; // offset 0x1B0F8, size 0x1
    unsigned char mn_md1; // offset 0x1B0F9, size 0x1
    unsigned char mn_md2; // offset 0x1B0FA, size 0x1
    unsigned char mn_md3; // offset 0x1B0FB, size 0x1
    int mn_setct; // offset 0x1B0FC, size 0x4
    unsigned int mn_stack[8]; // offset 0x1B100, size 0x20
    unsigned int sdm_flg; // offset 0x1B120, size 0x4
    unsigned int sdm_mode; // offset 0x1B124, size 0x4
    unsigned char * ltc_bp; // offset 0x1B128, size 0x4
    unsigned int ltc_tsbak; // offset 0x1B12C, size 0x4
    int ewk_n; // offset 0x1B130, size 0x4
    unsigned int enow; // offset 0x1B134, size 0x4
    unsigned int onow; // offset 0x1B138, size 0x4
    unsigned int efnow; // offset 0x1B13C, size 0x4
    int vsyc_ct; // offset 0x1B140, size 0x4
    int vsyc_flg; // offset 0x1B144, size 0x4
    int fog_ct; // offset 0x1B148, size 0x4
    int bcl_ct; // offset 0x1B14C, size 0x4
    int gfrm_ct; // offset 0x1B150, size 0x4
    int gframe; // offset 0x1B154, size 0x4
    int eor_ct; // offset 0x1B158, size 0x4
    unsigned int pfm_cts; // offset 0x1B15C, size 0x4
    int evt_tmd; // offset 0x1B160, size 0x4
    int evt_tim; // offset 0x1B164, size 0x4
    int evt_tdg; // offset 0x1B168, size 0x4
    int evt_fcd; // offset 0x1B16C, size 0x4
    unsigned int evt_fcdct; // offset 0x1B170, size 0x4
    unsigned int fsize; // offset 0x1B174, size 0x4
    unsigned int rdtsz; // offset 0x1B178, size 0x4
    unsigned char * memp; // offset 0x1B17C, size 0x4
    unsigned char * mempb; // offset 0x1B180, size 0x4
    unsigned char * endp; // offset 0x1B184, size 0x4
    unsigned char * rdtp; // offset 0x1B188, size 0x4
    unsigned char * plmdlp; // offset 0x1B18C, size 0x4
    unsigned char * lmmdlp; // offset 0x1B190, size 0x4
    unsigned char * wrmdlp; // offset 0x1B194, size 0x4
    unsigned char * wlmdlp; // offset 0x1B198, size 0x4
    unsigned char * plmthp; // offset 0x1B19C, size 0x4
    unsigned char * plbmtp; // offset 0x1B1A0, size 0x4
    unsigned char * plwmtp; // offset 0x1B1A4, size 0x4
    unsigned char * plzmtp; // offset 0x1B1A8, size 0x4
    unsigned char * plemtp; // offset 0x1B1AC, size 0x4
    unsigned char * plexwp; // offset 0x1B1B0, size 0x4
    unsigned char * plhdwp; // offset 0x1B1B4, size 0x4
    unsigned char * pletcp; // offset 0x1B1B8, size 0x4
    unsigned char * subtxp; // offset 0x1B1BC, size 0x4
    unsigned char * doordp; // offset 0x1B1C0, size 0x4
    unsigned char * sbs_sp; // offset 0x1B1C4, size 0x4
	NO_NAME_4* obwp; // offset 0x1B1C8, size 0x4
	NO_NAME_4* itwp; // offset 0x1B1CC, size 0x4
	NO_NAME_3* emtp[128]; // offset 0x1B1D0, size 0x200
	NO_NAME_3* rmthp; // offset 0x1B3D0, size 0x4
	unsigned char * mspp; // offset 0x1B3D4, size 0x4
    unsigned char * lspp; // offset 0x1B3D8, size 0x4
    unsigned int * mes_ip; // offset 0x1B3DC, size 0x4
    unsigned int * mes_sp; // offset 0x1B3E0, size 0x4
    void * mes_tp; // offset 0x1B3E4, size 0x4
    short txr_n; // offset 0x1B3E8, size 0x2
    short txr_ct; // offset 0x1B3EA, size 0x2
	NJS_TEXLIST* txlp[256]; // offset 0x1B3EC, size 0x400
	unsigned char * txdp[256]; // offset 0x1B7EC, size 0x400
    short txloff[256]; // offset 0x1BBEC, size 0x200
    short txb_ct; // offset 0x1BDEC, size 0x2
    short txb_n; // offset 0x1BDEE, size 0x2
    short txb[256]; // offset 0x1BDF0, size 0x200
	NJS_TEXLIST* txblp[256]; // offset 0x1BFF0, size 0x400
	NO_NAME_5 txbp[256]; // offset 0x1C3F0, size 0x1400
	unsigned char* ef_psp; // offset 0x1D7F0, size 0x4
	NJS_TEXNAME ef_tex[450]; // offset 0x1D7F4, size 0x1518
	NJS_TEXLIST ef_tlist; // offset 0x1ED0C, size 0x8
	NO_NAME_6 ef; // offset 0x1ED14, size 0x28
	short efid[256]; // offset 0x1ED3C, size 0x200
	NO_NAME_2 efm[450]; // offset 0x1EF3C, size 0x2A30
	int ef_ct; // offset 0x2196C, size 0x4
    int ef_ctb; // offset 0x21970, size 0x4
    int ef_extn; // offset 0x21974, size 0x4
    int ef_tn[450]; // offset 0x21978, size 0x708
    unsigned char ef_pbkb[450]; // offset 0x22080, size 0x1C2
    int ef_pbnk; // offset 0x22244, size 0x4
    int ef_slow; // offset 0x22248, size 0x4
    int ef_ctrn; // offset 0x2224C, size 0x4
    int yk_ct; // offset 0x22250, size 0x4
    int mg_ct; // offset 0x22254, size 0x4
    int bl_ct; // offset 0x22258, size 0x4
    int windr; // offset 0x2225C, size 0x4
    float winds; // offset 0x22260, size 0x4
    int windrb; // offset 0x22264, size 0x4
    float windsb; // offset 0x22268, size 0x4
    unsigned int thunder; // offset 0x2226C, size 0x4
    float gas_py; // offset 0x22270, size 0x4
    int en_objn; // offset 0x22274, size 0x4
    BH_PWORK * en_obj[16]; // offset 0x22278, size 0x40
    int ef_poln; // offset 0x222B8, size 0x4
    int ef_mdfn; // offset 0x222BC, size 0x4
    int ef_linn; // offset 0x222C0, size 0x4
    int ef_ntxn; // offset 0x222C4, size 0x4
    int ef_trsn; // offset 0x222C8, size 0x4
    int ef_pncn; // offset 0x222CC, size 0x4
    int ef_opqn; // offset 0x222D0, size 0x4
    int ef_thln; // offset 0x222D4, size 0x4
    int ef_ntx2dn; // offset 0x222D8, size 0x4
    int ef_trs2dn; // offset 0x222DC, size 0x4
    int ef_pnc2dn; // offset 0x222E0, size 0x4
    int ef_fncn; // offset 0x222E4, size 0x4
	NO_NAME_4* ef_pol[512]; // offset 0x222E8, size 0x800
	NO_NAME_4* ef_mdf[128]; // offset 0x22AE8, size 0x200
	NO_NAME_4* ef_lin[512]; // offset 0x22CE8, size 0x800
	NO_NAME_4* ef_ntx[512]; // offset 0x234E8, size 0x800
	NO_NAME_4* ef_trs[512]; // offset 0x23CE8, size 0x800
	NO_NAME_4* ef_pnc[512]; // offset 0x244E8, size 0x800
	NO_NAME_4* ef_opq[512]; // offset 0x24CE8, size 0x800
	NO_NAME_4* ef_thl[512]; // offset 0x254E8, size 0x800
	NO_NAME_4* ef_ntx2d[128]; // offset 0x25CE8, size 0x200
	NO_NAME_4* ef_trs2d[128]; // offset 0x25EE8, size 0x200
	NO_NAME_4* ef_pnc2d[128]; // offset 0x260E8, size 0x200
	NO_NAME_4* ef_fnc[512]; // offset 0x262E8, size 0x800
	int ob_nlgn; // offset 0x26AE8, size 0x4
    int ob_hlgn; // offset 0x26AEC, size 0x4
    int ob_spcn; // offset 0x26AF0, size 0x4
	NO_NAME_4* ob_nlg[32]; // offset 0x26AF4, size 0x80
	NO_NAME_4* ob_hlg[32]; // offset 0x26B74, size 0x80
	NO_NAME_4* ob_spc[32]; // offset 0x26BF4, size 0x80
	unsigned int ren_gid; // offset 0x26C74, size 0x4
	NJS_TEXINFO ren_info; // offset 0x26C78, size 0x2C
	NJS_TEXNAME ren_tex[1]; // offset 0x26CA4, size 0xC
	NJS_TEXLIST ren_tlist; // offset 0x26CB0, size 0x8
	NJS_TEXTUREH_VTX rpb[256]; // offset 0x26CB8, size 0x1C00
	int ren_n; // offset 0x288B8, size 0x4
    int ren_idx[4]; // offset 0x288BC, size 0x10
    int wt_nbpt; // offset 0x288CC, size 0x4
    float wt_px; // offset 0x288D0, size 0x4
    float wt_pz; // offset 0x288D4, size 0x4
    int wt_xp; // offset 0x288D8, size 0x4
    int wt_zp; // offset 0x288DC, size 0x4
    int wt_minx; // offset 0x288E0, size 0x4
    int wt_minz; // offset 0x288E4, size 0x4
    int wt_maxx; // offset 0x288E8, size 0x4
    int wt_maxz; // offset 0x288EC, size 0x4
    unsigned char * wt_wvp; // offset 0x288F0, size 0x4
	NJS_PLANE mr_pl; // offset 0x288F4, size 0x18
	unsigned char * zan_memp; // offset 0x2890C, size 0x4
    unsigned char * zanp; // offset 0x28910, size 0x4
	NO_NAME_8* lgtp; // offset 0x28914, size 0x4
	float lg_vx; // offset 0x28918, size 0x4
    float lg_vy; // offset 0x2891C, size 0x4
    float lg_vz; // offset 0x28920, size 0x4
    float lg_r; // offset 0x28924, size 0x4
    float lg_g; // offset 0x28928, size 0x4
    float lg_b; // offset 0x2892C, size 0x4
    int lg_pnt; // offset 0x28930, size 0x4
	NO_NAME_9 lg_ptb[4]; // offset 0x28934, size 0x80
	int mes_idx; // offset 0x289B4, size 0x4
    unsigned int * mes_dp; // offset 0x289B8, size 0x4
    int mes_ct; // offset 0x289BC, size 0x4
    int mes_tim; // offset 0x289C0, size 0x4
    int mes_fls; // offset 0x289C4, size 0x4
    int mes_sel; // offset 0x289C8, size 0x4
    int mes_seln; // offset 0x289CC, size 0x4
	NJS_POINT2 mes_sps[16]; // offset 0x289D0, size 0x80
	int rt_sp; // offset 0x28A50, size 0x4
    unsigned char * rt_wp; // offset 0x28A54, size 0x4
    unsigned char * rt_dp; // offset 0x28A58, size 0x4
    unsigned char * rt_nw; // offset 0x28A5C, size 0x4
    unsigned char * rt_nx; // offset 0x28A60, size 0x4
    float * rt_ln; // offset 0x28A64, size 0x4
    BH_PWORK * plp; // offset 0x28A68, size 0x4
	NO_NAME_10* pl_htp; // offset 0x28A6C, size 0x4
	int costume; // offset 0x28A70, size 0x4
	NJS_POINT3 hd_pos; // offset 0x28A74, size 0xC
	NJS_POINT3 apos; // offset 0x28A80, size 0xC
	NO_NAME_10* ahtp; // offset 0x28A8C, size 0x4
	int mwal_n; // offset 0x28A90, size 0x4
    int metc_n; // offset 0x28A94, size 0x4
    int mflr_n; // offset 0x28A98, size 0x4
	NO_NAME_10 mwalp[64]; // offset 0x28A9C, size 0x900
	NO_NAME_10 metcp[64]; // offset 0x2939C, size 0x900
	NO_NAME_10 mflrp[64]; // offset 0x29C9C, size 0x900
	int dla_n; // offset 0x2A59C, size 0x4
	NO_NAME_10* htp; // offset 0x2A5A0, size 0x4
	int psh_snd; // offset 0x2A5A4, size 0x4
    int fog_cngct; // offset 0x2A5A8, size 0x4
    unsigned int fog_col; // offset 0x2A5AC, size 0x4
    float fog_nr; // offset 0x2A5B0, size 0x4
    float fog_fr; // offset 0x2A5B4, size 0x4
    float fade_ct; // offset 0x2A5B8, size 0x4
    float fade_hkn; // offset 0x2A5BC, size 0x4
    float fade_ao; // offset 0x2A5C0, size 0x4
    float fade_an; // offset 0x2A5C4, size 0x4
    float fade_ap; // offset 0x2A5C8, size 0x4
    float fade_ro; // offset 0x2A5CC, size 0x4
    float fade_rn; // offset 0x2A5D0, size 0x4
    float fade_rp; // offset 0x2A5D4, size 0x4
    float fade_go; // offset 0x2A5D8, size 0x4
    float fade_gn; // offset 0x2A5DC, size 0x4
    float fade_gp; // offset 0x2A5E0, size 0x4
    float fade_bo; // offset 0x2A5E4, size 0x4
    float fade_bn; // offset 0x2A5E8, size 0x4
    float fade_bp; // offset 0x2A5EC, size 0x4
    unsigned int fade_pbk; // offset 0x2A5F0, size 0x4
    unsigned short ssv_md0; // offset 0x2A5F4, size 0x2
    unsigned short ssv_md1; // offset 0x2A5F6, size 0x2
    int ssv_tim; // offset 0x2A5F8, size 0x4
    float ssv_ct; // offset 0x2A5FC, size 0x4
    float ssv_hkn; // offset 0x2A600, size 0x4
    float ssv_ao; // offset 0x2A604, size 0x4
    float ssv_an; // offset 0x2A608, size 0x4
    float ssv_ap; // offset 0x2A60C, size 0x4
    short fil_no; // offset 0x2A610, size 0x2
    short fil_rt; // offset 0x2A612, size 0x2
    float rvf_sc; // offset 0x2A614, size 0x4
    float rvf_sn; // offset 0x2A618, size 0x4
    unsigned int rvfc[4]; // offset 0x2A61C, size 0x10
    float cine_an; // offset 0x2A62C, size 0x4
    float cine_ap; // offset 0x2A630, size 0x4
    unsigned int sco_flg; // offset 0x2A634, size 0x4
    float amb_r[4]; // offset 0x2A638, size 0x10
    float amb_g[4]; // offset 0x2A648, size 0x10
    float amb_b[4]; // offset 0x2A658, size 0x10
    int sb_id; // offset 0x2A668, size 0x4
    int sb_cmd; // offset 0x2A66C, size 0x4
    int sb_rdid; // offset 0x2A670, size 0x4
    int sb_rdsz; // offset 0x2A674, size 0x4
    void * sb_rdp; // offset 0x2A678, size 0x4
    void * sb_mlb; // offset 0x2A67C, size 0x4
    void * sb_ppp; // offset 0x2A680, size 0x4
	NJS_TEXLIST* sb_tlist; // offset 0x2A684, size 0x4
	int ddmd; // offset 0x2A688, size 0x4
	DOOR_WORK door; // offset 0x2A68C, size 0x1C
	int mpmd; // offset 0x2A6A8, size 0x4
    int mp_prm[4]; // offset 0x2A6AC, size 0x10
    unsigned short gov_md0; // offset 0x2A6BC, size 0x2
    unsigned short gov_md1; // offset 0x2A6BE, size 0x2
    int gov_ct; // offset 0x2A6C0, size 0x4
    void * gov_exp; // offset 0x2A6C4, size 0x4
    unsigned int com_flg; // offset 0x2A6C8, size 0x4
    unsigned short com_md0; // offset 0x2A6CC, size 0x2
    unsigned short com_md1; // offset 0x2A6CE, size 0x2
    unsigned int com_num; // offset 0x2A6D0, size 0x4
    void * com_exp; // offset 0x2A6D4, size 0x4
    short ond_tnm; // offset 0x2A6D8, size 0x2
    short ond_ud; // offset 0x2A6DA, size 0x2
    char ond_cx; // offset 0x2A6DC, size 0x1
    char ond_n[3]; // offset 0x2A6DD, size 0x3
    unsigned char ufo_md; // offset 0x2A6E0, size 0x1
    unsigned char ufo_flg; // offset 0x2A6E1, size 0x1
    short ufo_oidx; // offset 0x2A6E2, size 0x2
	NJS_POINT3 ufo_pos; // offset 0x2A6E4, size 0xC
	unsigned int opt_flg; // offset 0x2A6F0, size 0x4
    unsigned short opt_md0; // offset 0x2A6F4, size 0x2
    unsigned short opt_md1; // offset 0x2A6F6, size 0x2
    void * opt_exp; // offset 0x2A6F8, size 0x4
    unsigned int etc_idx; // offset 0x2A6FC, size 0x4
    unsigned int flr_idx; // offset 0x2A700, size 0x4
    int mvi_no; // offset 0x2A704, size 0x4
    int mvi_tp; // offset 0x2A708, size 0x4
    unsigned short mvi_md; // offset 0x2A70C, size 0x2
    unsigned short mvi_flg; // offset 0x2A70E, size 0x2
    unsigned int mvi_tsb; // offset 0x2A710, size 0x4
    unsigned int mvi_spb; // offset 0x2A714, size 0x4
    unsigned char * mvi_memp; // offset 0x2A718, size 0x4
    unsigned int dcg_tkbak; // offset 0x2A71C, size 0x4
    unsigned int dcg_tsbak; // offset 0x2A720, size 0x4
    unsigned int pau_spbak; // offset 0x2A724, size 0x4
    unsigned int pau_pad_on; // offset 0x2A728, size 0x4
    unsigned int pau_pad_ps; // offset 0x2A72C, size 0x4
    unsigned int pau_pad_old; // offset 0x2A730, size 0x4
    unsigned char * pdm_dp; // offset 0x2A734, size 0x4
    unsigned char * pdm_pd; // offset 0x2A738, size 0x4
    int pdm_keytpb; // offset 0x2A73C, size 0x4
    int gat_ct; // offset 0x2A740, size 0x4
	CONICAL_FRUSTUM gatc[16]; // offset 0x2A744, size 0x200
	int ght_ct; // offset 0x2A944, size 0x4
    unsigned int ghtc[32]; // offset 0x2A948, size 0x80
	NJS_POINT3 ghtp[32]; // offset 0x2A9C8, size 0x180
	unsigned short db_md0; // offset 0x2AB48, size 0x2
    unsigned short db_md1; // offset 0x2AB4A, size 0x2
    char db_stgno; // offset 0x2AB4C, size 0x1
    char db_romno; // offset 0x2AB4D, size 0x1
    char db_rcase; // offset 0x2AB4E, size 0x1
    char db_muteki; // offset 0x2AB4F, size 0x1
    short db_px; // offset 0x2AB50, size 0x2
    short db_py; // offset 0x2AB52, size 0x2
    int db_mes; // offset 0x2AB54, size 0x4
    int calc_v; // offset 0x2AB58, size 0x4
    unsigned int brkfg; // offset 0x2AB5C, size 0x4
    char brkfg_typ[32]; // offset 0x2AB60, size 0x20
    short brkfg_bit[32]; // offset 0x2AB80, size 0x40
    unsigned int brkfg_tkb; // offset 0x2ABC0, size 0x4
    unsigned int brkfg_tsb; // offset 0x2ABC4, size 0x4
    int brkfg_ct; // offset 0x2ABC8, size 0x4
    unsigned int bmt_size; // offset 0x2ABCC, size 0x4
    unsigned int lmt_size; // offset 0x2ABD0, size 0x4
    unsigned int emt_size; // offset 0x2ABD4, size 0x4
    unsigned int wmt_size; // offset 0x2ABD8, size 0x4
    char mes[256]; // offset 0x2ABDC, size 0x100
    float sfx; // offset 0x2ACDC, size 0x4
    float sfy; // offset 0x2ACE0, size 0x4
    float sfxn; // offset 0x2ACE4, size 0x4
    float sfyn; // offset 0x2ACE8, size 0x4
    float sfct; // offset 0x2ACEC, size 0x4
} SYS_WORK;

typedef struct NO_NAME_12
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
} NO_NAME_12;

typedef struct HWS_WORK
{
	int mode;
	int frame;
	int count;
	int vtx_opq_a;
	int vtx_opq_b;
	int vtx_trs_a;
	int vtx_trs_b;
	int vtx_punch;
	int vtx_total;
} HWS_WORK;

typedef struct NO_NAME_14
{
	float pos[3];
	int* vlist;
	short* plist;
} NO_NAME_14;

typedef struct NP_WORK
{
	int* sknp;
	int obj_now;
	int obj_cnt;
	unsigned char* buff;
	unsigned char* bp;
	int* vlist[128];
	NJS_POINT3 op[128];
	NJS_CNK_OBJECT* cobj[128];
	int* sktp[128];
	int* vlp[128];
	NJS_MATRIX* mxp[128][10];
	void* wkp;
	unsigned char* buff2;
	unsigned char* bp2;
	NO_NAME_14 mdlstr2[128];
	int* vlp2[128];
	char mes[256];
} NP_WORK;

typedef struct NO_NAME_15
{
	unsigned char ucType;
	unsigned char ucAttr;
	unsigned short usSize;
	unsigned short usIndexOfs;
	unsigned short usIndexMax;
	unsigned char ucPadding[56];
} NO_NAME_15;

typedef struct NO_NAME_15_NOPAD
{
	unsigned char ucType;
	unsigned char ucAttr;
	unsigned short usSize;
	unsigned short usIndexOfs;
	unsigned short usIndexMax;
} NO_NAME_15_NOPAD;

typedef struct NO_NAME_16
{
	float x;
	float y;
	float z;
	float w;
} NO_NAME_16;

typedef struct NO_NAME_11 /* @anon20 */ {
    // total size: 0x330
    struct /* @anon35 */ {
        // total size: 0x28
        struct /* @anon26 */ {
            // total size: 0x8
            unsigned int EN1 : 1; // offset 0x0, size 0x4
            unsigned int EN2 : 1; // offset 0x0, size 0x4
            unsigned int CRTMD : 3; // offset 0x0, size 0x4
            unsigned int MMOD : 1; // offset 0x0, size 0x4
            unsigned int AMOD : 1; // offset 0x0, size 0x4
            unsigned int SLBG : 1; // offset 0x0, size 0x4
            unsigned int ALP : 8; // offset 0x0, size 0x4
            unsigned int p0 : 16; // offset 0x0, size 0x4
            unsigned int p1; // offset 0x4, size 0x4
        } pmode; // offset 0x0, size 0x8
        struct /* @anon37 */ {
            // total size: 0x8
            unsigned int INT : 1; // offset 0x0, size 0x4
            unsigned int FFMD : 1; // offset 0x0, size 0x4
            unsigned int DPMS : 2; // offset 0x0, size 0x4
            unsigned int p0 : 28; // offset 0x0, size 0x4
            unsigned int p1; // offset 0x4, size 0x4
        } smode2; // offset 0x8, size 0x8
        struct /* @anon29 */ {
            // total size: 0x8
            unsigned int FBP : 9; // offset 0x0, size 0x4
            unsigned int FBW : 6; // offset 0x0, size 0x4
            unsigned int PSM : 5; // offset 0x0, size 0x4
            unsigned int p0 : 12; // offset 0x0, size 0x4
            unsigned int DBX : 11; // offset 0x4, size 0x4
            unsigned int DBY : 11; // offset 0x4, size 0x4
            unsigned int p1 : 10; // offset 0x4, size 0x4
        } dispfb; // offset 0x10, size 0x8
        struct /* @anon2 */ {
            // total size: 0x8
            unsigned int DX : 12; // offset 0x0, size 0x4
            unsigned int DY : 11; // offset 0x0, size 0x4
            unsigned int MAGH : 4; // offset 0x0, size 0x4
            unsigned int MAGV : 2; // offset 0x0, size 0x4
            unsigned int p0 : 3; // offset 0x0, size 0x4
            unsigned int DW : 12; // offset 0x4, size 0x4
            unsigned int DH : 11; // offset 0x4, size 0x4
            unsigned int p1 : 9; // offset 0x4, size 0x4
        } display; // offset 0x18, size 0x8
        struct /* @anon7 */ {
            // total size: 0x8
            unsigned int R : 8; // offset 0x0, size 0x4
            unsigned int G : 8; // offset 0x0, size 0x4
            unsigned int B : 8; // offset 0x0, size 0x4
            unsigned int p0 : 8; // offset 0x0, size 0x4
            unsigned int p1; // offset 0x4, size 0x4
        } bgcolor; // offset 0x20, size 0x8
    } disp[2]; // offset 0x0, size 0x50
    struct /* @anon23 */ {
        // total size: 0x10
        unsigned long NLOOP : 15; // offset 0x0, size 0x4
        unsigned long EOP : 1; // offset 0x0, size 0x4
        unsigned long pad16 : 16; // offset 0x0, size 0x4
        unsigned long id : 14; // offset 0x0, size 0x4
        unsigned long PRE : 1; // offset 0x0, size 0x4
        unsigned long PRIM : 11; // offset 0x0, size 0x4
        unsigned long FLG : 2; // offset 0x0, size 0x4
        unsigned long NREG : 4; // offset 0x0, size 0x4
        unsigned long REGS0 : 4; // offset 0x8, size 0x4
        unsigned long REGS1 : 4; // offset 0x8, size 0x4
        unsigned long REGS2 : 4; // offset 0x8, size 0x4
        unsigned long REGS3 : 4; // offset 0x8, size 0x4
        unsigned long REGS4 : 4; // offset 0x8, size 0x4
        unsigned long REGS5 : 4; // offset 0x8, size 0x4
        unsigned long REGS6 : 4; // offset 0x8, size 0x4
        unsigned long REGS7 : 4; // offset 0x8, size 0x4
        unsigned long REGS8 : 4; // offset 0x8, size 0x4
        unsigned long REGS9 : 4; // offset 0x8, size 0x4
        unsigned long REGS10 : 4; // offset 0x8, size 0x4
        unsigned long REGS11 : 4; // offset 0x8, size 0x4
        unsigned long REGS12 : 4; // offset 0x8, size 0x4
        unsigned long REGS13 : 4; // offset 0x8, size 0x4
        unsigned long REGS14 : 4; // offset 0x8, size 0x4
        unsigned long REGS15 : 4; // offset 0x8, size 0x4
    } giftag0; // offset 0x50, size 0x10
    struct /* @anon38 */ {
        // total size: 0x80
        struct /* @anon15 */ {
            // total size: 0x8
            unsigned long FBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 7; // offset 0x0, size 0x4
            unsigned long FBW : 6; // offset 0x0, size 0x4
            unsigned long pad22 : 2; // offset 0x0, size 0x4
            unsigned long PSM : 6; // offset 0x0, size 0x4
            unsigned long pad30 : 2; // offset 0x0, size 0x4
            unsigned long FBMSK : 32; // offset 0x0, size 0x4
        } frame1; // offset 0x0, size 0x8
        unsigned long frame1addr; // offset 0x8, size 0x4
        struct /* @anon30 */ {
            // total size: 0x8
            unsigned long ZBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 15; // offset 0x0, size 0x4
            unsigned long PSM : 4; // offset 0x0, size 0x4
            unsigned long pad28 : 4; // offset 0x0, size 0x4
            unsigned long ZMSK : 1; // offset 0x0, size 0x4
            unsigned long pad33 : 31; // offset 0x0, size 0x4
        } zbuf1; // offset 0x10, size 0x8
        signed long zbuf1addr; // offset 0x18, size 0x4
        struct /* @anon22 */ {
            // total size: 0x8
            unsigned long OFX : 16; // offset 0x0, size 0x4
            unsigned long pad16 : 16; // offset 0x0, size 0x4
            unsigned long OFY : 16; // offset 0x0, size 0x4
            unsigned long pad48 : 16; // offset 0x0, size 0x4
        } xyoffset1; // offset 0x20, size 0x8
        signed long xyoffset1addr; // offset 0x28, size 0x4
        struct /* @anon13 */ {
            // total size: 0x8
            unsigned long SCAX0 : 11; // offset 0x0, size 0x4
            unsigned long pad11 : 5; // offset 0x0, size 0x4
            unsigned long SCAX1 : 11; // offset 0x0, size 0x4
            unsigned long pad27 : 5; // offset 0x0, size 0x4
            unsigned long SCAY0 : 11; // offset 0x0, size 0x4
            unsigned long pad43 : 5; // offset 0x0, size 0x4
            unsigned long SCAY1 : 11; // offset 0x0, size 0x4
            unsigned long pad59 : 5; // offset 0x0, size 0x4
        } scissor1; // offset 0x30, size 0x8
        signed long scissor1addr; // offset 0x38, size 0x4
        struct /* @anon5 */ {
            // total size: 0x8
            unsigned long AC : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } prmodecont; // offset 0x40, size 0x8
        signed long prmodecontaddr; // offset 0x48, size 0x4
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned long CLAMP : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } colclamp; // offset 0x50, size 0x8
        signed long colclampaddr; // offset 0x58, size 0x4
        struct /* @anon10 */ {
            // total size: 0x8
            unsigned long DTHE : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } dthe; // offset 0x60, size 0x8
        signed long dtheaddr; // offset 0x68, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } test1; // offset 0x70, size 0x8
        signed long test1addr; // offset 0x78, size 0x4
    } draw01; // offset 0x60, size 0x80
    struct /* @anon8 */ {
        // total size: 0x80
        struct /* @anon15 */ {
            // total size: 0x8
            unsigned long FBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 7; // offset 0x0, size 0x4
            unsigned long FBW : 6; // offset 0x0, size 0x4
            unsigned long pad22 : 2; // offset 0x0, size 0x4
            unsigned long PSM : 6; // offset 0x0, size 0x4
            unsigned long pad30 : 2; // offset 0x0, size 0x4
            unsigned long FBMSK : 32; // offset 0x0, size 0x4
        } frame2; // offset 0x0, size 0x8
        unsigned long frame2addr; // offset 0x8, size 0x4
        struct /* @anon30 */ {
            // total size: 0x8
            unsigned long ZBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 15; // offset 0x0, size 0x4
            unsigned long PSM : 4; // offset 0x0, size 0x4
            unsigned long pad28 : 4; // offset 0x0, size 0x4
            unsigned long ZMSK : 1; // offset 0x0, size 0x4
            unsigned long pad33 : 31; // offset 0x0, size 0x4
        } zbuf2; // offset 0x10, size 0x8
        signed long zbuf2addr; // offset 0x18, size 0x4
        struct /* @anon22 */ {
            // total size: 0x8
            unsigned long OFX : 16; // offset 0x0, size 0x4
            unsigned long pad16 : 16; // offset 0x0, size 0x4
            unsigned long OFY : 16; // offset 0x0, size 0x4
            unsigned long pad48 : 16; // offset 0x0, size 0x4
        } xyoffset2; // offset 0x20, size 0x8
        signed long xyoffset2addr; // offset 0x28, size 0x4
        struct /* @anon13 */ {
            // total size: 0x8
            unsigned long SCAX0 : 11; // offset 0x0, size 0x4
            unsigned long pad11 : 5; // offset 0x0, size 0x4
            unsigned long SCAX1 : 11; // offset 0x0, size 0x4
            unsigned long pad27 : 5; // offset 0x0, size 0x4
            unsigned long SCAY0 : 11; // offset 0x0, size 0x4
            unsigned long pad43 : 5; // offset 0x0, size 0x4
            unsigned long SCAY1 : 11; // offset 0x0, size 0x4
            unsigned long pad59 : 5; // offset 0x0, size 0x4
        } scissor2; // offset 0x30, size 0x8
        signed long scissor2addr; // offset 0x38, size 0x4
        struct /* @anon5 */ {
            // total size: 0x8
            unsigned long AC : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } prmodecont; // offset 0x40, size 0x8
        signed long prmodecontaddr; // offset 0x48, size 0x4
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned long CLAMP : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } colclamp; // offset 0x50, size 0x8
        signed long colclampaddr; // offset 0x58, size 0x4
        struct /* @anon10 */ {
            // total size: 0x8
            unsigned long DTHE : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } dthe; // offset 0x60, size 0x8
        signed long dtheaddr; // offset 0x68, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } test2; // offset 0x70, size 0x8
        signed long test2addr; // offset 0x78, size 0x4
    } draw02; // offset 0xE0, size 0x80
    struct /* @anon14 */ {
        // total size: 0x60
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } testa; // offset 0x0, size 0x8
        signed long testaaddr; // offset 0x8, size 0x4
        struct /* @anon34 */ {
            // total size: 0x8
            unsigned long PRIM : 3; // offset 0x0, size 0x4
            unsigned long IIP : 1; // offset 0x0, size 0x4
            unsigned long TME : 1; // offset 0x0, size 0x4
            unsigned long FGE : 1; // offset 0x0, size 0x4
            unsigned long ABE : 1; // offset 0x0, size 0x4
            unsigned long AA1 : 1; // offset 0x0, size 0x4
            unsigned long FST : 1; // offset 0x0, size 0x4
            unsigned long CTXT : 1; // offset 0x0, size 0x4
            unsigned long FIX : 1; // offset 0x0, size 0x4
            unsigned long pad11 : 53; // offset 0x0, size 0x4
        } prim; // offset 0x10, size 0x8
        signed long primaddr; // offset 0x18, size 0x4
        struct /* @anon9 */ {
            // total size: 0x8
            unsigned int R : 8; // offset 0x0, size 0x4
            unsigned int G : 8; // offset 0x0, size 0x4
            unsigned int B : 8; // offset 0x0, size 0x4
            unsigned int A : 8; // offset 0x0, size 0x4
            float Q; // offset 0x4, size 0x4
        } rgbaq; // offset 0x20, size 0x8
        signed long rgbaqaddr; // offset 0x28, size 0x4
        struct /* @anon25 */ {
            // total size: 0x8
            unsigned long X : 16; // offset 0x0, size 0x4
            unsigned long Y : 16; // offset 0x0, size 0x4
            unsigned long Z : 32; // offset 0x0, size 0x4
        } xyz2a; // offset 0x30, size 0x8
        signed long xyz2aaddr; // offset 0x38, size 0x4
        struct /* @anon25 */ {
            // total size: 0x8
            unsigned long X : 16; // offset 0x0, size 0x4
            unsigned long Y : 16; // offset 0x0, size 0x4
            unsigned long Z : 32; // offset 0x0, size 0x4
        } xyz2b; // offset 0x40, size 0x8
        signed long xyz2baddr; // offset 0x48, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } testb; // offset 0x50, size 0x8
        signed long testbaddr; // offset 0x58, size 0x4
    } clear0; // offset 0x160, size 0x60
    struct /* @anon23 */ {
        // total size: 0x10
        unsigned long NLOOP : 15; // offset 0x0, size 0x4
        unsigned long EOP : 1; // offset 0x0, size 0x4
        unsigned long pad16 : 16; // offset 0x0, size 0x4
        unsigned long id : 14; // offset 0x0, size 0x4
        unsigned long PRE : 1; // offset 0x0, size 0x4
        unsigned long PRIM : 11; // offset 0x0, size 0x4
        unsigned long FLG : 2; // offset 0x0, size 0x4
        unsigned long NREG : 4; // offset 0x0, size 0x4
        unsigned long REGS0 : 4; // offset 0x8, size 0x4
        unsigned long REGS1 : 4; // offset 0x8, size 0x4
        unsigned long REGS2 : 4; // offset 0x8, size 0x4
        unsigned long REGS3 : 4; // offset 0x8, size 0x4
        unsigned long REGS4 : 4; // offset 0x8, size 0x4
        unsigned long REGS5 : 4; // offset 0x8, size 0x4
        unsigned long REGS6 : 4; // offset 0x8, size 0x4
        unsigned long REGS7 : 4; // offset 0x8, size 0x4
        unsigned long REGS8 : 4; // offset 0x8, size 0x4
        unsigned long REGS9 : 4; // offset 0x8, size 0x4
        unsigned long REGS10 : 4; // offset 0x8, size 0x4
        unsigned long REGS11 : 4; // offset 0x8, size 0x4
        unsigned long REGS12 : 4; // offset 0x8, size 0x4
        unsigned long REGS13 : 4; // offset 0x8, size 0x4
        unsigned long REGS14 : 4; // offset 0x8, size 0x4
        unsigned long REGS15 : 4; // offset 0x8, size 0x4
    } giftag1; // offset 0x1C0, size 0x10
    struct /* @anon38 */ {
        // total size: 0x80
        struct /* @anon15 */ {
            // total size: 0x8
            unsigned long FBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 7; // offset 0x0, size 0x4
            unsigned long FBW : 6; // offset 0x0, size 0x4
            unsigned long pad22 : 2; // offset 0x0, size 0x4
            unsigned long PSM : 6; // offset 0x0, size 0x4
            unsigned long pad30 : 2; // offset 0x0, size 0x4
            unsigned long FBMSK : 32; // offset 0x0, size 0x4
        } frame1; // offset 0x0, size 0x8
        unsigned long frame1addr; // offset 0x8, size 0x4
        struct /* @anon30 */ {
            // total size: 0x8
            unsigned long ZBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 15; // offset 0x0, size 0x4
            unsigned long PSM : 4; // offset 0x0, size 0x4
            unsigned long pad28 : 4; // offset 0x0, size 0x4
            unsigned long ZMSK : 1; // offset 0x0, size 0x4
            unsigned long pad33 : 31; // offset 0x0, size 0x4
        } zbuf1; // offset 0x10, size 0x8
        signed long zbuf1addr; // offset 0x18, size 0x4
        struct /* @anon22 */ {
            // total size: 0x8
            unsigned long OFX : 16; // offset 0x0, size 0x4
            unsigned long pad16 : 16; // offset 0x0, size 0x4
            unsigned long OFY : 16; // offset 0x0, size 0x4
            unsigned long pad48 : 16; // offset 0x0, size 0x4
        } xyoffset1; // offset 0x20, size 0x8
        signed long xyoffset1addr; // offset 0x28, size 0x4
        struct /* @anon13 */ {
            // total size: 0x8
            unsigned long SCAX0 : 11; // offset 0x0, size 0x4
            unsigned long pad11 : 5; // offset 0x0, size 0x4
            unsigned long SCAX1 : 11; // offset 0x0, size 0x4
            unsigned long pad27 : 5; // offset 0x0, size 0x4
            unsigned long SCAY0 : 11; // offset 0x0, size 0x4
            unsigned long pad43 : 5; // offset 0x0, size 0x4
            unsigned long SCAY1 : 11; // offset 0x0, size 0x4
            unsigned long pad59 : 5; // offset 0x0, size 0x4
        } scissor1; // offset 0x30, size 0x8
        signed long scissor1addr; // offset 0x38, size 0x4
        struct /* @anon5 */ {
            // total size: 0x8
            unsigned long AC : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } prmodecont; // offset 0x40, size 0x8
        signed long prmodecontaddr; // offset 0x48, size 0x4
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned long CLAMP : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } colclamp; // offset 0x50, size 0x8
        signed long colclampaddr; // offset 0x58, size 0x4
        struct /* @anon10 */ {
            // total size: 0x8
            unsigned long DTHE : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } dthe; // offset 0x60, size 0x8
        signed long dtheaddr; // offset 0x68, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } test1; // offset 0x70, size 0x8
        signed long test1addr; // offset 0x78, size 0x4
    } draw11; // offset 0x1D0, size 0x80
    struct /* @anon8 */ {
        // total size: 0x80
        struct /* @anon15 */ {
            // total size: 0x8
            unsigned long FBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 7; // offset 0x0, size 0x4
            unsigned long FBW : 6; // offset 0x0, size 0x4
            unsigned long pad22 : 2; // offset 0x0, size 0x4
            unsigned long PSM : 6; // offset 0x0, size 0x4
            unsigned long pad30 : 2; // offset 0x0, size 0x4
            unsigned long FBMSK : 32; // offset 0x0, size 0x4
        } frame2; // offset 0x0, size 0x8
        unsigned long frame2addr; // offset 0x8, size 0x4
        struct /* @anon30 */ {
            // total size: 0x8
            unsigned long ZBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 15; // offset 0x0, size 0x4
            unsigned long PSM : 4; // offset 0x0, size 0x4
            unsigned long pad28 : 4; // offset 0x0, size 0x4
            unsigned long ZMSK : 1; // offset 0x0, size 0x4
            unsigned long pad33 : 31; // offset 0x0, size 0x4
        } zbuf2; // offset 0x10, size 0x8
        signed long zbuf2addr; // offset 0x18, size 0x4
        struct /* @anon22 */ {
            // total size: 0x8
            unsigned long OFX : 16; // offset 0x0, size 0x4
            unsigned long pad16 : 16; // offset 0x0, size 0x4
            unsigned long OFY : 16; // offset 0x0, size 0x4
            unsigned long pad48 : 16; // offset 0x0, size 0x4
        } xyoffset2; // offset 0x20, size 0x8
        signed long xyoffset2addr; // offset 0x28, size 0x4
        struct /* @anon13 */ {
            // total size: 0x8
            unsigned long SCAX0 : 11; // offset 0x0, size 0x4
            unsigned long pad11 : 5; // offset 0x0, size 0x4
            unsigned long SCAX1 : 11; // offset 0x0, size 0x4
            unsigned long pad27 : 5; // offset 0x0, size 0x4
            unsigned long SCAY0 : 11; // offset 0x0, size 0x4
            unsigned long pad43 : 5; // offset 0x0, size 0x4
            unsigned long SCAY1 : 11; // offset 0x0, size 0x4
            unsigned long pad59 : 5; // offset 0x0, size 0x4
        } scissor2; // offset 0x30, size 0x8
        signed long scissor2addr; // offset 0x38, size 0x4
        struct /* @anon5 */ {
            // total size: 0x8
            unsigned long AC : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } prmodecont; // offset 0x40, size 0x8
        signed long prmodecontaddr; // offset 0x48, size 0x4
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned long CLAMP : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } colclamp; // offset 0x50, size 0x8
        signed long colclampaddr; // offset 0x58, size 0x4
        struct /* @anon10 */ {
            // total size: 0x8
            unsigned long DTHE : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } dthe; // offset 0x60, size 0x8
        signed long dtheaddr; // offset 0x68, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } test2; // offset 0x70, size 0x8
        signed long test2addr; // offset 0x78, size 0x4
    } draw12; // offset 0x250, size 0x80
    struct /* @anon14 */ {
        // total size: 0x60
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } testa; // offset 0x0, size 0x8
        signed long testaaddr; // offset 0x8, size 0x4
        struct /* @anon34 */ {
            // total size: 0x8
            unsigned long PRIM : 3; // offset 0x0, size 0x4
            unsigned long IIP : 1; // offset 0x0, size 0x4
            unsigned long TME : 1; // offset 0x0, size 0x4
            unsigned long FGE : 1; // offset 0x0, size 0x4
            unsigned long ABE : 1; // offset 0x0, size 0x4
            unsigned long AA1 : 1; // offset 0x0, size 0x4
            unsigned long FST : 1; // offset 0x0, size 0x4
            unsigned long CTXT : 1; // offset 0x0, size 0x4
            unsigned long FIX : 1; // offset 0x0, size 0x4
            unsigned long pad11 : 53; // offset 0x0, size 0x4
        } prim; // offset 0x10, size 0x8
        signed long primaddr; // offset 0x18, size 0x4
        struct /* @anon9 */ {
            // total size: 0x8
            unsigned int R : 8; // offset 0x0, size 0x4
            unsigned int G : 8; // offset 0x0, size 0x4
            unsigned int B : 8; // offset 0x0, size 0x4
            unsigned int A : 8; // offset 0x0, size 0x4
            float Q; // offset 0x4, size 0x4
        } rgbaq; // offset 0x20, size 0x8
        signed long rgbaqaddr; // offset 0x28, size 0x4
        struct /* @anon25 */ {
            // total size: 0x8
            unsigned long X : 16; // offset 0x0, size 0x4
            unsigned long Y : 16; // offset 0x0, size 0x4
            unsigned long Z : 32; // offset 0x0, size 0x4
        } xyz2a; // offset 0x30, size 0x8
        signed long xyz2aaddr; // offset 0x38, size 0x4
        struct /* @anon25 */ {
            // total size: 0x8
            unsigned long X : 16; // offset 0x0, size 0x4
            unsigned long Y : 16; // offset 0x0, size 0x4
            unsigned long Z : 32; // offset 0x0, size 0x4
        } xyz2b; // offset 0x40, size 0x8
        signed long xyz2baddr; // offset 0x48, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } testb; // offset 0x50, size 0x8
        signed long testbaddr; // offset 0x58, size 0x4
    } clear1; // offset 0x2D0, size 0x60
} NO_NAME_11; // size: 0x330, address: 0x112C7B0

typedef struct NO_NAME_17
{
	unsigned int num;
	NJS_TEXMEMLIST tmem[256];
	void* addr[256];
} NO_NAME_17;

typedef struct LFOPEN_INFO
{
	// total size: 0x8
    unsigned int Flag; // offset 0x0, size 0x4
    GDFS GdFs; // offset 0x4, size 0x4
} LFOPEN_INFO;

typedef struct _HM _HM; 
struct _HM
{
	unsigned int Use_size;
	unsigned int Total_size;
	unsigned int dummy;
	_HM* pNext_work;
	unsigned int dummy64[12];
};

typedef struct NO_NAME_19
{
	unsigned short routine_0;
	unsigned short type;
	unsigned short act_lv[2];
	unsigned short be_flag;
	unsigned char act_data[8];
} NO_NAME_19;

typedef struct PLANE
{
	unsigned int xyzflag;
	unsigned int clipmask;
} PLANE;

typedef struct SCISSOR_PLANE
{
	PLANE plane[5];
	unsigned int planeNum;
} SCISSOR_PLANE;

typedef struct NODE
{
	sceVu0FVECTOR vertex;
	sceVu0FVECTOR color;
	sceVu0FVECTOR texUV;
	sceVu0FVECTOR clipV;
} NODE;

typedef struct SCISSOR_NODE
{
	NODE node[12];
	unsigned int nodeNum;
	float pad[3]; 
} SCISSOR_NODE;

typedef struct SCISSOR
{
	SCISSOR_NODE triangle;
	SCISSOR_NODE narray[2];
	SCISSOR_NODE* in;
	SCISSOR_NODE* out;
	unsigned int rotflag;
	unsigned int flipflag;
} SCISSOR;

typedef struct VU1_STRIP_BUF
{
	float fU;
	float fV;
	float fPad0;
	float fPad1;
	float fIr;
	float fIg;
	float fIb;
	float fA;
	float fVx;
	float fVy;
	float fVz;
	float fFog;
	float fSx;
	float fSy;
	float fIz;
	float fNz;
} VU1_STRIP_BUF;

typedef struct PAD_WORK
{
	// total size: 0x42
    unsigned short on; // offset 0x0, size 0x2
    unsigned short old; // offset 0x2, size 0x2
    unsigned short push; // offset 0x4, size 0x2
    unsigned short release; // offset 0x6, size 0x2
    short send; // offset 0x8, size 0x2
    unsigned short ad_flag; // offset 0xA, size 0x2
    unsigned char buff[2]; // offset 0xC, size 0x2
    unsigned short onon; // offset 0xE, size 0x2
    unsigned short repeat; // offset 0x10, size 0x2
    char time1[16]; // offset 0x12, size 0x10
    char time2[16]; // offset 0x22, size 0x10
    unsigned char rh; // offset 0x32, size 0x1
    unsigned char rv; // offset 0x33, size 0x1
    unsigned char lh; // offset 0x34, size 0x1
    unsigned char lv; // offset 0x35, size 0x1
    unsigned char au; // offset 0x36, size 0x1
    unsigned char ad; // offset 0x37, size 0x1
    unsigned char al; // offset 0x38, size 0x1
    unsigned char ar; // offset 0x39, size 0x1
    unsigned char abu; // offset 0x3A, size 0x1
    unsigned char abd; // offset 0x3B, size 0x1
    unsigned char abl; // offset 0x3C, size 0x1
    unsigned char abr; // offset 0x3D, size 0x1
    unsigned char al1; // offset 0x3E, size 0x1
    unsigned char al2; // offset 0x3F, size 0x1
    unsigned char ar1; // offset 0x40, size 0x1
    unsigned char ar2; // offset 0x41, size 0x1
} PAD_WORK;

typedef struct PAD_INFO
{
	// total size: 0x3C
    int PerType; // offset 0x0, size 0x4
    int OldPerType; // offset 0x4, size 0x4
    int PerTypeEx; // offset 0x8, size 0x4
    unsigned int Flag; // offset 0xC, size 0x4
    int SoftReset; // offset 0x10, size 0x4
    unsigned int on; // offset 0x14, size 0x4
    unsigned int press; // offset 0x18, size 0x4
    unsigned int Rept; // offset 0x1C, size 0x4
    unsigned int on2; // offset 0x20, size 0x4
    unsigned int on2old; // offset 0x24, size 0x4
    unsigned int press2; // offset 0x28, size 0x4
    unsigned short l; // offset 0x2C, size 0x2
    unsigned short r; // offset 0x2E, size 0x2
    short x1; // offset 0x30, size 0x2
    short y1; // offset 0x32, size 0x2
    short x2; // offset 0x34, size 0x2
    short y2; // offset 0x36, size 0x2
    short Calibrate; // offset 0x38, size 0x2
} PAD_INFO;

typedef struct DVDISO_DATA
{
	char* file_name;
	//char* link_file; original field from the debugging symbols, the below version matches better
    char** link_file;
} DVDISO_DATA;

typedef struct PS2_NJ_SAVE
{
	unsigned char mode_bk[2]; // offset 0x0, size 0x2
    unsigned char set_last; // offset 0x2, size 0x1
    unsigned char dc_alpha; // offset 0x3, size 0x1
    int mode; // offset 0x4, size 0x4
} PS2_NJ_SAVE;

typedef struct PS2_GS_SAVE
{
	unsigned long SC_TAG[2]; // offset 0x0, size 0x8
    unsigned long GIF_TAG[2]; // offset 0x10, size 0x8
    unsigned long TEX0; // offset 0x20, size 0x4
    unsigned long TEX0_TAG; // offset 0x28, size 0x4
    unsigned long TEX0_NEXT; // offset 0x30, size 0x4
    unsigned long TEX0_NEXT_TAG; // offset 0x38, size 0x4
    unsigned long TEX1; // offset 0x40, size 0x4
    unsigned long TEX1_TAG; // offset 0x48, size 0x4
    unsigned long CLAMP; // offset 0x50, size 0x4
    unsigned long CLAMP_TAG; // offset 0x58, size 0x4
    unsigned long TEST; // offset 0x60, size 0x4
    unsigned long TEST_TAG; // offset 0x68, size 0x4
    unsigned long FOGCOL; // offset 0x70, size 0x4
    unsigned long FOGCOL_TAG; // offset 0x78, size 0x4
    unsigned long ALPHA; // offset 0x80, size 0x4
    unsigned long ALPHA_TAG; // offset 0x88, size 0x4
    unsigned long FBA; // offset 0x90, size 0x4
    unsigned long FBA_TAG; // offset 0x98, size 0x4
    unsigned long SCISSOR; // offset 0xA0, size 0x4
    unsigned long SCISSOR_TAG; // offset 0xA8, size 0x4
    unsigned char mode_bk[2]; // offset 0xB0, size 0x2
    unsigned char set_last; // offset 0xB2, size 0x1
    unsigned char dc_alpha; // offset 0xB3, size 0x1
    unsigned int pad32; // offset 0xB4, size 0x4
    unsigned long pad64; // offset 0xB8, size 0x4
} PS2_GS_SAVE;

#define SCR_WIDTH 640
#define SCR_HEIGHT 224

#define GS_X_COORD(x) ((2048 - (SCR_WIDTH / 2) + x) * 16)
#define GS_Y_COORD(y) ((2048 - (SCR_HEIGHT / 2) + y) * 16)

#define WORKBASE (0x70000000)

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

typedef struct PS2_OT_LIST
{
    int pad; // TODO: this is actually an empty struct 
} PS2_OT_LIST;

typedef struct PS2_OT
{
	NJS_TEXMEMLIST* tp;
	unsigned char mode_bk[2];
	unsigned char set_last;
	unsigned char dc_alpha;
	PS2_OT_LIST* op;
	void* p;
	unsigned long ALPHA;
	unsigned long TEX0;
	unsigned long TEX0_NEXT;
	unsigned int bank;
	unsigned int pad;
} PS2_OT;

typedef struct MOV_INFO
{
	unsigned char * mmp; // offset 0x0, size 0x4
    float Vol; // offset 0x4, size 0x4
    float VolSpeed; // offset 0x8, size 0x4
    float Fade; // offset 0xC, size 0x4
    float FadeSpeed; // offset 0x10, size 0x4
    short FrameCnt; // offset 0x14, size 0x2
    char ExecMovieSystemFlag; // offset 0x16, size 0x1
    char MovieCancelFlag; // offset 0x17, size 0x1
    char MovieFadeFlag; // offset 0x18, size 0x1
    char MovieFadeMode; // offset 0x19, size 0x1
    char MovieSystemLastError; // offset 0x1A, size 0x1
} MOV_INFO;

typedef struct PS2_TP_TAG
{
	unsigned long GIF_TAG[2]; // offset 0x0, size 0x8
    unsigned long TEX0; // offset 0x10, size 0x4
    unsigned long TEX0_TAG; // offset 0x18, size 0x4
    unsigned long TEX0_NEXT; // offset 0x20, size 0x4
    unsigned long TEX0_NEXT_TAG; // offset 0x28, size 0x4
    unsigned long CLAMP; // offset 0x30, size 0x4
    unsigned long CLAMP_TAG; // offset 0x38, size 0x4
} PS2_TP_TAG;

typedef struct PS2_TP_CACHE
{
	void * tp; // offset 0x0, size 0x4
    unsigned int bank; // offset 0x4, size 0x4
    unsigned int tex_addr; // offset 0x8, size 0x4
    unsigned int clt_addr; // offset 0xC, size 0x4
} PS2_TP_CACHE;

#define DMAref              (3<<28)

#define SCE_GS_CLAMP            (1)

typedef struct BUF_QUEUE 
{
    char* from;               
    unsigned char* to;        
} BUF_QUEUE;

typedef struct EXPAND_STATUS 
{
    char active;              
    char mode;                
} EXPAND_STATUS;

typedef union EXPAND_CTRL 
{
    EXPAND_STATUS sb;      
    short check;              
} EXPAND_CTRL;

typedef union EXPAND_FLAG
{
    struct 
    {
        EXPAND_CTRL uw; 
        char in;              
        char out;             
    } sl;
    int abort;               
} EXPAND_FLAG;

typedef struct EXPAND_CTRL_BUF
{
    EXPAND_FLAG flag;        
    int code;                    
    int counter;                 
    int repeat;                  
    unsigned char* offset;       
    char* source;               
    unsigned char* destination;  
    BUF_QUEUE que[2];         
} EXPAND_CTRL_BUF;

typedef struct ADX_WORK
{
	// total size: 0x10
	unsigned int MaxChannel; // offset 0x0, size 0x4
    unsigned int MaxSampleRate; // offset 0x4, size 0x4
    int RecoverType; // offset 0x8, size 0x4
    int ReloadSector; // offset 0xC, size 0x4
} ADX_WORK;

typedef struct SND_CMD
{
	// total size: 0x8
	int MaxCommand; // offset 0x0, size 0x4
    unsigned char ComTbl[2]; // offset 0x4, size 0x2
} SND_CMD;

typedef struct NO_NAME_20
{
	// total size: 0x30
	unsigned int Flag; // offset 0x0, size 0x4
    int FadeFunc; // offset 0x4, size 0x4
    int FadeCntMax; // offset 0x8, size 0x4
    float Volume; // offset 0xC, size 0x4
    float VolSpeed; // offset 0x10, size 0x4
    float VolLast; // offset 0x14, size 0x4
    float LimitMaxVol; // offset 0x18, size 0x4
    int PanFunc; // offset 0x1C, size 0x4
    int PanCntMax; // offset 0x20, size 0x4
    float Pan; // offset 0x24, size 0x4
    float PanSpeed; // offset 0x28, size 0x4
    float PanLast; // offset 0x2C, size 0x4
} NO_NAME_20;

typedef struct RM_SNDENV
{
	// total size: 0x10
	char VolPlayerVoice; // offset 0x0, size 0x1
    char VolPlayerAction; // offset 0x1, size 0x1
    char VolWeaponSe; // offset 0x2, size 0x1
    char VolCartridgeSe; // offset 0x3, size 0x1
    char VolEnemySe; // offset 0x4, size 0x1
    char VolBgSe0; // offset 0x5, size 0x1
    char VolBgSe1; // offset 0x6, size 0x1
    char VolObjectSe; // offset 0x7, size 0x1
    char VolEventSe; // offset 0x8, size 0x1
    char RoomFxLevel; // offset 0x9, size 0x1
    char RoomFxProg; // offset 0xA, size 0x1
    char MaxEventSeSlots; // offset 0xB, size 0x1
    char MaxObjectSeSlots; // offset 0xC, size 0x1
    char Dummy1; // offset 0xD, size 0x1
    char Dummy2; // offset 0xE, size 0x1
    char Dummy3; // offset 0xF, size 0x1
} RM_SNDENV;

typedef struct PRM_INFO
{
	// total size: 0x20
	int mode; // offset 0x0, size 0x4
    int frame; // offset 0x4, size 0x4
    int count; // offset 0x8, size 0x4
    int latency; // offset 0xC, size 0x4
    int rsv[4]; // offset 0x10, size 0x10
} PRM_INFO;

typedef struct REPEAT_INFO
{
	// total size: 0xC
    unsigned int WaitFlag; // offset 0x0, size 0x4
    unsigned int WaitCnt; // offset 0x4, size 0x4
    unsigned int Key; // offset 0x8, size 0x4
} REPEAT_INFO;

typedef struct ADV_WORK
{
	// total size: 0xD8
    int PatId; // offset 0x0, size 0x4
    int Mode; // offset 0x4, size 0x4
    int Mode2; // offset 0x8, size 0x4
    int NextMode; // offset 0xC, size 0x4
    int NextReturnCode; // offset 0x10, size 0x4
    int PortId; // offset 0x14, size 0x4
    int OptIndex; // offset 0x18, size 0x4
    int OptLevel; // offset 0x1C, size 0x4
    int NextOptLevel; // offset 0x20, size 0x4
    int OptScrX; // offset 0x24, size 0x4
    int OptScrY; // offset 0x28, size 0x4
    unsigned int PalNo; // offset 0x2C, size 0x4
    unsigned int PalMode; // offset 0x30, size 0x4
    unsigned int FontBaseColor; // offset 0x34, size 0x4
    unsigned char * SysMemPtr; // offset 0x38, size 0x4
    unsigned char * MsgPtr; // offset 0x3C, size 0x4
    unsigned char * ptr[8]; // offset 0x40, size 0x20
    float Timer; // offset 0x60, size 0x4
    float FadeRate; // offset 0x64, size 0x4
    float FadeSpeed; // offset 0x68, size 0x4
    float SaverTimer; // offset 0x6C, size 0x4
    float SaverRate; // offset 0x70, size 0x4
    float FlushCount; // offset 0x74, size 0x4
    float FlushSpeed; // offset 0x78, size 0x4
    float FlushCount2; // offset 0x7C, size 0x4
    float FlushSpeed2; // offset 0x80, size 0x4
    float ScrollPlatePosX[2][2]; // offset 0x84, size 0x10
    char Active; // offset 0x94, size 0x1
    char AppMode; // offset 0x95, size 0x1
    char ExtraFlag; // offset 0x96, size 0x1
    char FadeType; // offset 0x97, size 0x1
    char SaverCommand; // offset 0x98, size 0x1
    char Count; // offset 0x99, size 0x1
    char LastLevel; // offset 0x9A, size 0x1
    char FromTitle; // offset 0x9B, size 0x1
    char CurrentDiscId; // offset 0x9C, size 0x1
    char NextDiscId; // offset 0x9D, size 0x1
    char ErrorId; // offset 0x9E, size 0x1
    unsigned char ErrorMsgFlushCount; // offset 0x9F, size 0x1
    char AnimId; // offset 0xA0, size 0x1
    unsigned char AnimTime; // offset 0xA1, size 0x1
    char GenFlag; // offset 0xA2, size 0x1
    char PalFlag; // offset 0xA3, size 0x1
    char SrFlag; // offset 0xA4, size 0x1
    char OptFadeType; // offset 0xA5, size 0x1
    char TexFlag; // offset 0xA6, size 0x1
    char SoundMode; // offset 0xA7, size 0x1
    char vibration; // offset 0xA8, size 0x1
    char keytype; // offset 0xA9, size 0x1
    char adjust_x; // offset 0xAA, size 0x1
    char adjust_y; // offset 0xAB, size 0x1
    char OptSaveFlag; // offset 0xAC, size 0x1
    char vMode; // offset 0xAD, size 0x1
    char DriveNo; // offset 0xAE, size 0x1
    char MsgNo; // offset 0xAF, size 0x1
    char DepthLevel; // offset 0xB0, size 0x1
    char OldVmOpMode; // offset 0xB1, size 0x1
    char VmOpMode; // offset 0xB2, size 0x1
    char SetTexture[2]; // offset 0xB3, size 0x2
    char KeyCommandCount[7]; // offset 0xB5, size 0x7
    char Cursor[3]; // offset 0xBC, size 0x3
    char CursorMax[3]; // offset 0xBF, size 0x3
    char CursorFlag[4][4]; // offset 0xC2, size 0x10
    char ModeCommandId[4]; // offset 0xD2, size 0x4
} ADV_WORK;

typedef struct AFS_PATINFO
{
    // total size: 0x10
    char * AfsFileName; // offset 0x0, size 0x4
    int PartitionId; // offset 0x4, size 0x4
    int MaxInsideFileNum; // offset 0x8, size 0x4
    unsigned char * pInfoWork; // offset 0xC, size 0x4
} AFS_PATINFO;

typedef struct ADXT_SPRM
{
	// total size: 0x1C
    char * fname; // offset 0x0, size 0x4
    char * fpc; // offset 0x4, size 0x4
    int size; // offset 0x8, size 0x4
    int nrtry; // offset 0xC, size 0x4
    int speed; // offset 0x10, size 0x4
    int dtype; // offset 0x14, size 0x4
    int opmode; // offset 0x18, size 0x4
} ADXT_SPRM;

typedef struct AFS_INFO
{
	// total size: 0xC
    unsigned char * pInfoPart; // offset 0x0, size 0x4
    unsigned int PartAreaSize; // offset 0x4, size 0x4
    unsigned int Flag; // offset 0x8, size 0x4
} AFS_INFO;

typedef struct ADXF_INFO
{
	// total size: 0x10
    ADX_FS * Handle; // offset 0x0, size 0x4
    unsigned char * pAdxFWork; // offset 0x4, size 0x4
    unsigned int Flag; // offset 0x8, size 0x4
    int Mode; // offset 0xC, size 0x4
} ADXF_INFO;

typedef struct ADXT_INFO
{
	// total size: 0x40
    ADX_TALK * Handle; // offset 0x0, size 0x4
    unsigned char * pAdxTWork; // offset 0x4, size 0x4
    int WorkSize; // offset 0x8, size 0x4
    unsigned int Flag; // offset 0xC, size 0x4
    int FadeFunc; // offset 0x10, size 0x4
    int FadeCntMax; // offset 0x14, size 0x4
    float Volume; // offset 0x18, size 0x4
    float VolSpeed; // offset 0x1C, size 0x4
    float VolLast; // offset 0x20, size 0x4
    float VolSave; // offset 0x24, size 0x4
    float LimitMaxVol; // offset 0x28, size 0x4
    int PanFunc; // offset 0x2C, size 0x4
    int PanCntMax; // offset 0x30, size 0x4
    float Pan; // offset 0x34, size 0x4
    float PanSpeed; // offset 0x38, size 0x4
    float PanLast; // offset 0x3C, size 0x4
} ADXT_INFO;

typedef struct PAD_ACT
{
	// total size: 0x10
    unsigned char be_flag; // offset 0x0, size 0x1
    unsigned char level; // offset 0x1, size 0x1
    unsigned char start; // offset 0x2, size 0x1
    unsigned char end; // offset 0x3, size 0x1
    unsigned short delay; // offset 0x4, size 0x2
    unsigned short time; // offset 0x6, size 0x2
    unsigned short add; // offset 0x8, size 0x2
    short f_level; // offset 0xA, size 0x2
    short f_add; // offset 0xC, size 0x2
    char data[2]; // offset 0xE, size 0x2
} PAD_ACT;

typedef struct WPN_TAB
{
	// total size: 0x68
    unsigned int flg; // offset 0x0, size 0x4
    unsigned int atack_ct; // offset 0x4, size 0x4
    unsigned int fend_ct; // offset 0x8, size 0x4
    unsigned int at_cct; // offset 0xC, size 0x4
    short ef_yct; // offset 0x10, size 0x2
    short act_ct0; // offset 0x12, size 0x2
    short act_ct1; // offset 0x14, size 0x2
    short act_ct2; // offset 0x16, size 0x2
    float r; // offset 0x18, size 0x4
    float l; // offset 0x1C, size 0x4
    float rn; // offset 0x20, size 0x4
    float rmax; // offset 0x24, size 0x4
	NJS_POINT3 wp_fps1; // offset 0x28, size 0xC
	NJS_POINT3 wp_fps2; // offset 0x34, size 0xC
	NJS_POINT3 wp_cps; // offset 0x40, size 0xC
	unsigned char ltp; // offset 0x4C, size 0x1
    unsigned char lr; // offset 0x4D, size 0x1
    unsigned char lg; // offset 0x4E, size 0x1
    unsigned char lb; // offset 0x4F, size 0x1
    unsigned short lnr; // offset 0x50, size 0x2
    unsigned short lfr; // offset 0x52, size 0x2
    float hrate; // offset 0x54, size 0x4
    float ef_scale; // offset 0x58, size 0x4
    short snd_wpno; // offset 0x5C, size 0x2
    short hiteff; // offset 0x5E, size 0x2
    unsigned short seno0; // offset 0x60, size 0x2
    unsigned short seno1; // offset 0x62, size 0x2
    char vib_tp; // offset 0x64, size 0x1
    char vib_ct; // offset 0x65, size 0x1
    char reserve1; // offset 0x66, size 0x1
    char reserve2; // offset 0x67, size 0x1
} WPN_TAB;

typedef struct BUTTON_INFO
{
	// total size: 0x8
    int Type; // offset 0x0, size 0x4
    unsigned int Button; // offset 0x4, size 0x4
} BUTTON_INFO;

typedef struct NO_NAME_21
{
	unsigned short flg;
	short frame;
	float px;
	float py;
	float pz;
	short ax;
	short ay;
	short az;
	short pers;
	unsigned int hidobj[8];
	unsigned int hidlgt[4];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	short lkflg;
	short lkno;
	short lkono;
	short nxt_no;
	float lx;
	float ly;
	float lz;
	float prm_0;
	float prm_1;
	float prm_2;
	float prm_3;
	float prm_4;
	unsigned char* recp;
} NO_NAME_21;

typedef struct NO_NAME_22
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	NO_NAME_21 keyf[16];
} NO_NAME_22;

typedef struct NO_NAME_23
{
	unsigned short flg;
	unsigned char lgtclip;
	char spd;
	float px;
	float py;
	float pz;
	float ln;
	float w;
	float h;
	float d;
	float y0;
	float y1;
	float y2;
	float y3;
	float am_spd;
	int ax;
	int ay;
	int az;
	int lax;
	int lay;
	short laz0;
	short laz1;
	short laz2;
	short laz3;
	char aa_spd;
	char fil_no;
	char fil_rt;
	char reserve;
	int pers;
	unsigned int hidobj[16];
	unsigned int hidlgt[8];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
} NO_NAME_23;

typedef struct NO_NAME_24
{
	unsigned int attr;
	char flr_no;
	char reserve0;
	char reserve1;
	char atr_tp;
	float h;
	float dmy;
	float minx;
	float minz;
	float maxx;
	float maxz;
} NO_NAME_24;

typedef struct NO_NAME_25
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	NO_NAME_24* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	NO_NAME_23 cam[2];
	unsigned char exd[256];
} NO_NAME_25;

typedef struct NO_NAME_26
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	unsigned char mdlver;
	unsigned char wrk_no;
	char prm1;
	float px;
	float py;
	float pz;
	short ax;
	short az;
	short ay;
	short aspd;
	char hide[4];
} NO_NAME_26;

typedef struct NO_NAME_27
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	short flr_no;
	unsigned short mdlver;
	float px;
	float py;
	float pz;
	float sx;
	float sy;
	float sz;
	short ay;
	short ax;
	int lkflg;
	int lkno;
	int lkono;
	float lx;
	float ly;
	float lz;
	int param;
} NO_NAME_27;

typedef struct NO_NAME_28
{
	float px;
	float py;
	float pz;
	int ay;
} NO_NAME_28;

typedef struct ROM_WORK
{
    // total size: 0x3EC
	NO_NAME_25* cutp; // offset 0x0, size 0x4
	NO_NAME_8* lgtp; // offset 0x4, size 0x4
	NO_NAME_26* enep; // offset 0x8, size 0x4
	NO_NAME_26* objp; // offset 0xC, size 0x4
	NO_NAME_26* itmp; // offset 0x10, size 0x4
	NO_NAME_27* effp; // offset 0x14, size 0x4
	NO_NAME_10* walp; // offset 0x18, size 0x4
	NO_NAME_10* etcp; // offset 0x1C, size 0x4
	NO_NAME_10* flrp; // offset 0x20, size 0x4
	NO_NAME_28* posp; // offset 0x24, size 0x4
	NO_NAME_10* rutp; // offset 0x28, size 0x4
	unsigned char* ruttp; // offset 0x2C, size 0x4
	NO_NAME_12* evtp; // offset 0x30, size 0x4
	NO_NAME_22* evcp; // offset 0x34, size 0x4
	unsigned int* mesp; // offset 0x38, size 0x4
	NO_NAME_8* evlp; // offset 0x3C, size 0x4
	unsigned char* dmp00; // offset 0x40, size 0x4
    unsigned char* dmp01; // offset 0x44, size 0x4
    unsigned char* dmp02; // offset 0x48, size 0x4
    unsigned char* dmp03; // offset 0x4C, size 0x4
    unsigned char* dmp04; // offset 0x50, size 0x4
    unsigned char* dmp05; // offset 0x54, size 0x4
    unsigned char* dmp06; // offset 0x58, size 0x4
    unsigned char* dmp07; // offset 0x5C, size 0x4
    unsigned char* dmp08; // offset 0x60, size 0x4
    unsigned char* dmp09; // offset 0x64, size 0x4
    unsigned char* dmp10; // offset 0x68, size 0x4
    unsigned char* dmp11; // offset 0x6C, size 0x4
    unsigned char* dmp12; // offset 0x70, size 0x4
    unsigned char* dmp13; // offset 0x74, size 0x4
    unsigned char* dmp14; // offset 0x78, size 0x4
    unsigned char* dmp15; // offset 0x7C, size 0x4
    int cut_n; // offset 0x80, size 0x4
    int lgt_n; // offset 0x84, size 0x4
    int ene_n; // offset 0x88, size 0x4
    int obj_n; // offset 0x8C, size 0x4
    int itm_n; // offset 0x90, size 0x4
    int eff_n; // offset 0x94, size 0x4
    int wal_n; // offset 0x98, size 0x4
    int etc_n; // offset 0x9C, size 0x4
    int flr_n; // offset 0xA0, size 0x4
    int pos_n; // offset 0xA4, size 0x4
    int rut_n; // offset 0xA8, size 0x4
    int evc_n; // offset 0xAC, size 0x4
    int mes_n; // offset 0xB0, size 0x4
    int evl_n; // offset 0xB4, size 0x4
    int dmy00; // offset 0xB8, size 0x4
    int dmy01; // offset 0xBC, size 0x4
    int dmy02; // offset 0xC0, size 0x4
    int dmy03; // offset 0xC4, size 0x4
    int dmy04; // offset 0xC8, size 0x4
    int dmy05; // offset 0xCC, size 0x4
    int dmy06; // offset 0xD0, size 0x4
    int dmy07; // offset 0xD4, size 0x4
    int dmy08; // offset 0xD8, size 0x4
    int dmy09; // offset 0xDC, size 0x4
    int dmy10; // offset 0xE0, size 0x4
    int dmy11; // offset 0xE4, size 0x4
    int dmy12; // offset 0xE8, size 0x4
    int dmy13; // offset 0xEC, size 0x4
    int dmy14; // offset 0xF0, size 0x4
    int dmy15; // offset 0xF4, size 0x4
    int dmy16; // offset 0xF8, size 0x4
    int dmy17; // offset 0xFC, size 0x4
    unsigned int flg; // offset 0x100, size 0x4
    unsigned int bak_col; // offset 0x104, size 0x4
    unsigned int fog_col; // offset 0x108, size 0x4
    float fog_nr; // offset 0x10C, size 0x4
    float fog_fr; // offset 0x110, size 0x4
    float w; // offset 0x114, size 0x4
    float h; // offset 0x118, size 0x4
    float d; // offset 0x11C, size 0x4
    float grand[32]; // offset 0x120, size 0x80
	NO_NAME_2 mdl; // offset 0x1A0, size 0x18
	float fog[128]; // offset 0x1B8, size 0x200
    char amb_rom; // offset 0x3B8, size 0x1
    char amb_chr; // offset 0x3B9, size 0x1
    char amb_obj; // offset 0x3BA, size 0x1
    char amb_itm; // offset 0x3BB, size 0x1
    float amb_r[4]; // offset 0x3BC, size 0x10
    float amb_g[4]; // offset 0x3CC, size 0x10
    float amb_b[4]; // offset 0x3DC, size 0x10
} ROM_WORK;

typedef enum _enum_2
{
	MP_SET_GAME,
	MP_SET_EVENT,
	MP_SET_SUB
} _enum_2;

typedef struct PAD_WRK
{
    // total size: 0x84
	PAD_WORK pad1; // offset 0x0, size 0x42
	PAD_WORK pad2; // offset 0x42, size 0x42
} PAD_WRK;

typedef struct CAM_WORK 
{
    // total size: 0x4AC
    unsigned int flg; // offset 0x0, size 0x4
    int camver; // offset 0x4, size 0x4
    unsigned char mode0; // offset 0x8, size 0x1
    unsigned char mode1; // offset 0x9, size 0x1
    unsigned char mode2; // offset 0xA, size 0x1
    unsigned char mode3; // offset 0xB, size 0x1
    float px; // offset 0xC, size 0x4
    float py; // offset 0x10, size 0x4
    float pz; // offset 0x14, size 0x4
    float vx; // offset 0x18, size 0x4
    float vy; // offset 0x1C, size 0x4
    float vz; // offset 0x20, size 0x4
    float wpx; // offset 0x24, size 0x4
    float wpy; // offset 0x28, size 0x4
    float wpz; // offset 0x2C, size 0x4
    float plx; // offset 0x30, size 0x4
    float ply; // offset 0x34, size 0x4
    float plz; // offset 0x38, size 0x4
    float pxp; // offset 0x3C, size 0x4
    float pyp; // offset 0x40, size 0x4
    float pzp; // offset 0x44, size 0x4
    float ofx; // offset 0x48, size 0x4
    float ofy; // offset 0x4C, size 0x4
    float ofz; // offset 0x50, size 0x4
    int ax; // offset 0x54, size 0x4
    int ay; // offset 0x58, size 0x4
    int az; // offset 0x5C, size 0x4
    int axp; // offset 0x60, size 0x4
    int ayp; // offset 0x64, size 0x4
    int azp; // offset 0x68, size 0x4
    float ln; // offset 0x6C, size 0x4
    float pln; // offset 0x70, size 0x4
    float xr; // offset 0x74, size 0x4
    float xn; // offset 0x78, size 0x4
    float yr; // offset 0x7C, size 0x4
    float yn; // offset 0x80, size 0x4
    int pers; // offset 0x84, size 0x4
    int ppers; // offset 0x88, size 0x4
    int ncut; // offset 0x8C, size 0x4
    int ocut; // offset 0x90, size 0x4
    unsigned int ocflg; // offset 0x94, size 0x4
    unsigned int attr; // offset 0x98, size 0x4
    float (* mtx)[16]; // offset 0x9C, size 0x4
    float (* mtxb)[16]; // offset 0xA0, size 0x4
    int evc_no; // offset 0xA4, size 0x4
    int hct; // offset 0xA8, size 0x4
    int ct0; // offset 0xAC, size 0x4
    int ct1; // offset 0xB0, size 0x4
    int keyf_no; // offset 0xB4, size 0x4
    float frm; // offset 0xB8, size 0x4
    float spd; // offset 0xBC, size 0x4
    float pxn; // offset 0xC0, size 0x4
    float pyn; // offset 0xC4, size 0x4
    float pzn; // offset 0xC8, size 0x4
    int axn; // offset 0xCC, size 0x4
    int ayn; // offset 0xD0, size 0x4
    int azn; // offset 0xD4, size 0x4
    int pe_ax; // offset 0xD8, size 0x4
    int pe_pers; // offset 0xDC, size 0x4
    unsigned int fog_col; // offset 0xE0, size 0x4
    float fog_nr; // offset 0xE4, size 0x4
    float fog_fr; // offset 0xE8, size 0x4
    float ips[20][3]; // offset 0xEC, size 0xF0
    float ian[20][3]; // offset 0x1DC, size 0xF0
    float ipf[20][3]; // offset 0x2CC, size 0xF0
    float icr[20][3]; // offset 0x3BC, size 0xF0
} CAM_WORK;

struct tagCONFIGFILE {
    // total size: 0x34
    unsigned int ssd_ver; // offset 0x0, size 0x4
    unsigned int ssd_flg; // offset 0x4, size 0x4
    unsigned int ssd_reserve; // offset 0x8, size 0x4
    signed char keytype; // offset 0xC, size 0x1
    signed char adjust_x; // offset 0xD, size 0x1
    signed char adjust_y; // offset 0xE, size 0x1
    signed char vibration; // offset 0xF, size 0x1
    signed int best_tm[8]; // offset 0x10, size 0x20
    unsigned int Check_Sam; // offset 0x30, size 0x4
};

struct tagSAVEFILE {
    // total size: 0x838
    unsigned int version; // offset 0x0, size 0x4
    signed int save_ct; // offset 0x4, size 0x4
    signed char ply_id; // offset 0x8, size 0x1
    signed char stg_no; // offset 0x9, size 0x1
    signed char rom_no; // offset 0xA, size 0x1
    signed char rcase; // offset 0xB, size 0x1
    signed char pos_no; // offset 0xC, size 0x1
    signed char cut_no; // offset 0xD, size 0x1
    signed char flr_no; // offset 0xE, size 0x1
    signed char reserve0; // offset 0xF, size 0x1
    signed int gm_mode; // offset 0x10, size 0x4
    unsigned int ev_flg[32]; // offset 0x14, size 0x80
    unsigned int it_flg[16]; // offset 0x94, size 0x40
    unsigned int ic_flg[16]; // offset 0xD4, size 0x40
    unsigned int ed_flg[32]; // offset 0x114, size 0x80
    unsigned int ky_flg[16]; // offset 0x194, size 0x40
    unsigned int mp_flg[8]; // offset 0x1D4, size 0x20
    unsigned int itm[384]; // offset 0x1F4, size 0x600
    unsigned int ply_stflg[4]; // offset 0x7F4, size 0x10
    struct /* @anon32 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } ply_pos; // offset 0x804, size 0xC
    signed int ply_ang; // offset 0x810, size 0x4
    signed char ply_wno[4]; // offset 0x814, size 0x4
    signed short ply_hp[4]; // offset 0x818, size 0x8
    unsigned char evt_posno[4]; // offset 0x820, size 0x4
    signed int time; // offset 0x824, size 0x4
    signed int stv_tm; // offset 0x828, size 0x4
    signed short spray_ct; // offset 0x82C, size 0x2
    signed short retry_ct; // offset 0x82E, size 0x2
    signed short clear_ct; // offset 0x830, size 0x2
    signed short reserve1; // offset 0x832, size 0x2
    unsigned int CheckSam; // offset 0x834, size 0x4
};

struct tagICONINFORMATION {
    // total size: 0x3C4
    struct /* @anon18 */ {
        // total size: 0x3C4
        unsigned char Head[4]; // offset 0x0, size 0x4
        unsigned short Reserv1; // offset 0x4, size 0x2
        unsigned short OffsLF; // offset 0x6, size 0x2
        unsigned int Reserv2; // offset 0x8, size 0x4
        unsigned int TransRate; // offset 0xC, size 0x4
        signed int BgColor[4][4]; // offset 0x10, size 0x40
        float LightDir[3][4]; // offset 0x50, size 0x30
        float LightColor[3][4]; // offset 0x80, size 0x30
        float Ambient[4]; // offset 0xB0, size 0x10
        unsigned char TitleName[68]; // offset 0xC0, size 0x44
        unsigned char FnameView[64]; // offset 0x104, size 0x40
        unsigned char FnameCopy[64]; // offset 0x144, size 0x40
        unsigned char FnameDel[64]; // offset 0x184, size 0x40
        unsigned char Reserve3[512]; // offset 0x1C4, size 0x200
    } icon; // offset 0x0, size 0x3C4
};

struct tagMEMORYCARDPORT {
    // total size: 0x10
    signed int lCrntType; // offset 0x0, size 0x4
    signed int lPrevType; // offset 0x4, size 0x4
    signed int lFreeSize; // offset 0x8, size 0x4
    signed int lFormatType; // offset 0xC, size 0x4
};

struct tagMEMORYCARDSTATE {
    // total size: 0xA0
    unsigned int ulState; // offset 0x0, size 0x4
    unsigned int ulError; // offset 0x4, size 0x4
    unsigned int ulMcSubState; // offset 0x8, size 0x4
    unsigned int ulFileSize; // offset 0xC, size 0x4
    signed int lCurrentPort; // offset 0x10, size 0x4
    signed int lOpenFileNumber; // offset 0x14, size 0x4
    signed int lSelectFileNumber; // offset 0x18, size 0x4
    signed int lOpenMode; // offset 0x1C, size 0x4
    unsigned short usMcSysState; // offset 0x20, size 0x2
    void * vpAddr; // offset 0x24, size 0x4
    signed char cCurrentDir[50]; // offset 0x28, size 0x32
    signed char cOpenFileName[32]; // offset 0x5A, size 0x20
    signed char cRetryCount; // offset 0x7A, size 0x1
    signed char cMcCheckFlag; // offset 0x7B, size 0x1
    signed char cCheckMcFlag; // offset 0x7C, size 0x1
    struct tagMEMORYCARDPORT Port[2]; // offset 0x80, size 0x20
};

struct tagSELECTFILEINFO {
    // total size: 0x10
    signed int FileNumber; // offset 0x0, size 0x4
    signed int save_ct; // offset 0x4, size 0x4
    signed int gm_mode; // offset 0x8, size 0x4
    signed char ply_id; // offset 0xC, size 0x1
    signed char saveroom; // offset 0xD, size 0x1
};

struct tagSELECTFILEWINDOW {
    // total size: 0x28
    unsigned int ulFileState; // offset 0x0, size 0x4
    struct tagSELECTFILEINFO * pRecordTop; // offset 0x4, size 0x4
    signed int lRecordMax; // offset 0x8, size 0x4
    signed short slDispTopNumber; // offset 0xC, size 0x2
    signed short slDispRecordNumber; // offset 0xE, size 0x2
    signed short sMesCur; // offset 0x10, size 0x2
    signed short sCursol; // offset 0x12, size 0x2
    signed short sWaitMesTimer; // offset 0x14, size 0x2
    float slLineNumber; // offset 0x18, size 0x4
    signed int slDispWriteMesMax; // offset 0x1C, size 0x4
    signed int slDispWriteMes; // offset 0x20, size 0x4
    unsigned int ulfoundationColor; // offset 0x24, size 0x4
};

struct tagSYSLOAD_SCREEN {
    // total size: 0x38
    unsigned int ulState; // offset 0x0, size 0x4
    unsigned int ulSubState; // offset 0x4, size 0x4
    unsigned int ulMemCheckCountTimer; // offset 0x8, size 0x4
    unsigned int ulFileSize; // offset 0xC, size 0x4
    unsigned short usExitFlag; // offset 0x10, size 0x2
    unsigned short usLoopCount; // offset 0x12, size 0x2
    signed int lCardState; // offset 0x14, size 0x4
    signed char cMesFlag; // offset 0x18, size 0x1
    struct tagCONFIGFILE * pConfigFile; // offset 0x1C, size 0x4
    struct tagSAVEFILE * pSaveFile; // offset 0x20, size 0x4
    struct tagICONINFORMATION * pIconInfo; // offset 0x24, size 0x4
    struct tagMEMORYCARDSTATE * pMcState; // offset 0x28, size 0x4
    struct tagSELECTFILEINFO * pSelectFileInfo; // offset 0x2C, size 0x4
    struct tagSELECTFILEWINDOW * pSelectFileWindow; // offset 0x30, size 0x4
    void * vpReadBuffer; // offset 0x34, size 0x4
};
