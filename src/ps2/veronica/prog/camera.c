#include "camera.h"

CAM_WORK cam;
float cmmat[16];
float (* cmat)[16];

// 100% matching!
void bhInitCamera() {
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

// 100% matching
void bhControlCamera() {
    NJS_VECTOR pos = {0.0, 0.0, -1.0f};
    NJS_VECTOR ps;
    
    
    njSetPerspective(cam.pers);
    njSetMatrix(0,  cmat);
    njTranslate(0, 0, 0, -cam.ln);
    
    njRotateZ(0, cam.az);
    njRotateX(0, cam.ax);
    njRotateY(0, cam.ay);
    
    njTranslate(0, -(cam.px + cam.ofx),-(cam.py + cam.ofy), -(cam.pz + cam.ofz));
    njGetMatrix(cam.mtx);
    njUnitMatrix(0);
    
    njRotateY(0, cam.ay);
    njRotateX(0, cam.ax);
    njRotateZ(0, cam.az);
    
    njCalcVector(0, &pos, (NJS_VECTOR*)&cam.vx);
    cam.vx = -cam.vx;
    cam.vy = -cam.vy;
    
    njUnitMatrix(0);
    njTranslate(0, (cam.px + cam.ofx), (cam.py + cam.ofy), (cam.pz + cam.ofz));
    
    njRotateY(0, cam.ay);
    njRotateX(0, cam.ax);
    njRotateZ(0, cam.az);

    ps.y = 0;
    ps.x = 0;
    ps.z = -cam.ln;
    njCalcPoint(0, &ps, (NJS_VECTOR*)&cam.wpx);
}

// 100% matching
void bhMakeCameraVector() {
    NJS_VECTOR pos = {0x00000000, 0x00000000, 0xBF800000};
    
    njUnitMatrix(0);
    njRotateY(0, cam.ay);
    njRotateX(0, cam.ax);
    njRotateZ(0, cam.az);
    njCalcVector(0, &pos, (NJS_VECTOR*)(&cam.vx));
    cam.vx = -cam.vx;
    cam.vy = -cam.vy;
}

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
