/*typedef struct _anon0;
typedef struct _anon1;


typedef float type_0[16];
typedef float type_1[16][0];
typedef float type_2[3];
typedef float type_3[3][20];
typedef float type_4[3];
typedef float type_5[3][20];
typedef float type_6[3];
typedef float type_7[3][20];
typedef float type_8[3];
typedef float type_9[3][20];

struct _anon0
{
	float x;
	float y;
	float z;
};

struct _anon1
{
	unsigned int flg;
	int camver;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
	float wpx;
	float wpy;
	float wpz;
	float plx;
	float ply;
	float plz;
	float pxp;
	float pyp;
	float pzp;
	float ofx;
	float ofy;
	float ofz;
	int ax;
	int ay;
	int az;
	int axp;
	int ayp;
	int azp;
	float ln;
	float pln;
	float xr;
	float xn;
	float yr;
	float yn;
	int pers;
	int ppers;
	int ncut;
	int ocut;
	unsigned int ocflg;
	unsigned int attr;
	float mtx[16];
	float mtxb[16];
	int evc_no;
	int hct;
	int ct0;
	int ct1;
	int keyf_no;
	float frm;
	float spd;
	float pxn;
	float pyn;
	float pzn;
	int axn;
	int ayn;
	int azn;
	int pe_ax;
	int pe_pers;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float ips[3][20];
	float ian[3][20];
	float ipf[3][20];
	float icr[3][20];
};*/

CAM_WORK cam;
float cmmat[16];
/*
float cmat[16];

void bhInitCamera();
void bhControlCamera();
void bhMakeCameraVector();
void bhGetCameraPosition();*/

// 100% matching!
 void bhInitCamera(void) {
    npSetMemory((unsigned char*)&cam, 0x4AC, 0);
    cam.flg = 0;
    cam.ln = 0x100;
    cam.pers = 0x2000;
    cam.ncut = 0;
    cam.ocut = -1;
    cam.ocflg = 0;
    cam.attr = 0;
    cam.mtx = &cmmat;
    cam.mtxb = (&cmmat + 0x1);
    njUnitMatrix(cam.mtx);
    njUnitMatrix(cam.mtxb);
}

/*// 
// Start address: 0x279f50
void bhControlCamera()
{
	_anon0 ps;
	_anon0 pos;
	// Line 77, Address: 0x279f50, Func Offset: 0
	// Line 78, Address: 0x279f54, Func Offset: 0x4
	// Line 77, Address: 0x279f5c, Func Offset: 0xc
	// Line 78, Address: 0x279f60, Func Offset: 0x10
	// Line 80, Address: 0x279f6c, Func Offset: 0x1c
	// Line 78, Address: 0x279f70, Func Offset: 0x20
	// Line 80, Address: 0x279f78, Func Offset: 0x28
	// Line 81, Address: 0x279f80, Func Offset: 0x30
	// Line 82, Address: 0x279f90, Func Offset: 0x40
	// Line 101, Address: 0x279fac, Func Offset: 0x5c
	// Line 102, Address: 0x279fbc, Func Offset: 0x6c
	// Line 103, Address: 0x279fcc, Func Offset: 0x7c
	// Line 104, Address: 0x279fdc, Func Offset: 0x8c
	// Line 107, Address: 0x27a02c, Func Offset: 0xdc
	// Line 109, Address: 0x27a038, Func Offset: 0xe8
	// Line 110, Address: 0x27a040, Func Offset: 0xf0
	// Line 111, Address: 0x27a050, Func Offset: 0x100
	// Line 112, Address: 0x27a060, Func Offset: 0x110
	// Line 113, Address: 0x27a070, Func Offset: 0x120
	// Line 114, Address: 0x27a084, Func Offset: 0x134
	// Line 117, Address: 0x27a08c, Func Offset: 0x13c
	// Line 114, Address: 0x27a090, Func Offset: 0x140
	// Line 115, Address: 0x27a09c, Func Offset: 0x14c
	// Line 117, Address: 0x27a0ac, Func Offset: 0x15c
	// Line 118, Address: 0x27a0b4, Func Offset: 0x164
	// Line 119, Address: 0x27a0f8, Func Offset: 0x1a8
	// Line 120, Address: 0x27a108, Func Offset: 0x1b8
	// Line 121, Address: 0x27a118, Func Offset: 0x1c8
	// Line 123, Address: 0x27a128, Func Offset: 0x1d8
	// Line 122, Address: 0x27a130, Func Offset: 0x1e0
	// Line 124, Address: 0x27a134, Func Offset: 0x1e4
	// Line 122, Address: 0x27a138, Func Offset: 0x1e8
	// Line 124, Address: 0x27a13c, Func Offset: 0x1ec
	// Line 123, Address: 0x27a140, Func Offset: 0x1f0
	// Line 124, Address: 0x27a144, Func Offset: 0x1f4
	// Line 137, Address: 0x27a154, Func Offset: 0x204
	// Func End, Address: 0x27a160, Func Offset: 0x210
}

// 
// Start address: 0x27a160
void bhMakeCameraVector()
{
	_anon0 pos;
	// Line 143, Address: 0x27a160, Func Offset: 0
	// Line 144, Address: 0x27a164, Func Offset: 0x4
	// Line 143, Address: 0x27a16c, Func Offset: 0xc
	// Line 144, Address: 0x27a170, Func Offset: 0x10
	// Line 145, Address: 0x27a180, Func Offset: 0x20
	// Line 146, Address: 0x27a18c, Func Offset: 0x2c
	// Line 147, Address: 0x27a19c, Func Offset: 0x3c
	// Line 148, Address: 0x27a1ac, Func Offset: 0x4c
	// Line 149, Address: 0x27a1bc, Func Offset: 0x5c
	// Line 150, Address: 0x27a1d0, Func Offset: 0x70
	// Line 151, Address: 0x27a1e4, Func Offset: 0x84
	// Line 152, Address: 0x27a1f8, Func Offset: 0x98
	// Func End, Address: 0x27a204, Func Offset: 0xa4
}*/

// 100% matching!
void bhGetCameraPosition()
{
    NJS_POINT3 ps;

    njUnitMatrix(NULL);
    
    njTranslate(NULL, cam.px + cam.ofx, cam.py + cam.ofy, cam.pz + cam.ofz);
    
    njRotateY(NULL, cam.ay);
    njRotateX(NULL, cam.ax);
    njRotateZ(NULL, cam.az);

    ps.y = 0;
    ps.x = 0;
    ps.z = -cam.ln;

    njCalcPoint(NULL, &ps, (NJS_POINT3*)&cam.wpx);
}
