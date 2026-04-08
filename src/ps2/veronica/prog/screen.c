#include "../../../ps2/veronica/prog/screen.h"
#include "../../../ps2/veronica/prog/camera.h"
#include "../../../ps2/veronica/prog/cut.h"
#include "../../../ps2/veronica/prog/game.h"
#include "../../../ps2/veronica/prog/light.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaGraphics3D.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
/* #include "../../../ps2/veronica/prog/ps2_NaView.h" - the devs didn't include this originally */ 
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/main.h"

unsigned int Ps2_rendertex_initflag;

// 100% matching!
void bhSetScreenFade(unsigned int argb, float ct)
{
    sys->cb_flg |= 0x2;
    
    sys->fade_pbk = ((unsigned int)sys->fade_ap << 24) | ((unsigned int)sys->fade_rp << 16) | ((unsigned int)sys->fade_gp << 8) | (unsigned int)sys->fade_bp;
    
    sys->fade_ct = 0;
    
    if (ct <= 1.0f) 
    {
        sys->fade_hkn = 1.0f;
    } 
    else
    {
        sys->fade_hkn = 1.0f + ct;
    }
    
    sys->fade_ao = sys->fade_an;
    sys->fade_ro = sys->fade_rn;
    sys->fade_go = sys->fade_gn;
    sys->fade_bo = sys->fade_bn;
    
    sys->fade_ap = (argb >> 24);
    sys->fade_rp = (argb >> 16) & 0xFF;
    sys->fade_gp = (argb >> 8) & 0xFF;
    sys->fade_bp = argb & 0xFF;
}

// 100% matching!
void bhControlScreenFade()
{
    float hkn;

    hkn = sys->fade_hkn;
    
    if (hkn > 1.0f)
    {
        if (sys->fade_ct == 0)
        {
            sys->fade_ct += 1.0f;
            return;
        }
    }
    
    if (hkn == 1.0f)
    {
        sys->cb_flg &= ~0x2;
        
        sys->fade_an = sys->fade_ap;
        sys->fade_rn = sys->fade_rp;
        sys->fade_gn = sys->fade_gp;
        sys->fade_bn = sys->fade_bp;
        return;
    }
    
    hkn -= 1.0f;
    
    sys->fade_an += (sys->fade_ap - sys->fade_ao) / hkn;
    sys->fade_rn += (sys->fade_rp - sys->fade_ro) / hkn;
    sys->fade_gn += (sys->fade_gp - sys->fade_go) / hkn;
    sys->fade_bn += (sys->fade_bp - sys->fade_bo) / hkn;
    
    sys->fade_ct += 1.0f;
    
    if (sys->fade_ct >= hkn) 
    {
        sys->cb_flg &= ~0x2;
        
        sys->fade_an = sys->fade_ap;
        sys->fade_rn = sys->fade_rp;
        sys->fade_gn = sys->fade_gp;
        sys->fade_bn = sys->fade_bp;
    }
}

// 100% matching!
void bhDrawScreenFade()
{
    NJS_POINT2COL p2c;
    NJS_POINT2 p[4];  
    NJS_COLOR col[4];  
    unsigned int argb; 
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = NULL;
    
    p2c.num = 1;

    argb = (unsigned int)sys->fade_bn | (((unsigned int)sys->fade_gn << 8) | (((unsigned int)sys->fade_an << 24) | ((unsigned int)sys->fade_rn << 16)));
    
    ((int*)&p2c.col->color)[0] = argb;
    ((int*)&p2c.col->color)[1] = argb;
    ((int*)&p2c.col->color)[2] = argb;
    ((int*)&p2c.col->color)[3] = argb; 
    
    p[0].x = 0;
    p[0].y = 0;
    
    p[1].x = 640.0f;
    p[1].y = 0;
    
    p[2].x = 640.0f;
    p[2].y = 480.0f;
    
    p[3].x = 0;
    p[3].y = 480.0f;
    
    njDrawPolygon2D(&p2c, 4, -0.81f, 96);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
}

// 100% matching!
void bhInitScreenSaver()
{
    *(int*)&sys->ssv_md0 = 0;
    
    sys->ssv_tim = 0;
    
    sys->ssv_ct = 0;
    
    sys->ssv_hkn = 0;
    
    sys->ssv_ap = 0;
    sys->ssv_an = 0;
    sys->ssv_ao = 0;
}

// 100% matching! 
void bhSetScreenSaver(unsigned int alpha, float ct)
{
    sys->ssv_md0 = 1;
    
    sys->ssv_ct = 0;
    
    sys->ssv_hkn = ct;
    
    sys->ssv_ao = sys->ssv_an;
    
    sys->ssv_ap = alpha;
}

// 100% matching! 
void bhControlScreenSaver()
{
    sys->ssv_an += (sys->ssv_ap - sys->ssv_ao) / sys->ssv_hkn;
    
    sys->ssv_ct += 1.0f;
    
    if (sys->ssv_ct >= sys->ssv_hkn) 
    {
        sys->ssv_md0 = 2;
        
        sys->ssv_an = sys->ssv_ap;
    }
}

// 100% matching!
void bhDrawScreenSaver()
{
    NJS_POLYGON_VTX pol[4];
    unsigned int argb; 
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);

    argb = (Uint32)sys->ssv_an << 24;
    
    pol[0].x = 0;
    pol[0].y = 0;
    pol[0].z = 1.25f;
    pol[0].col = argb;
    
    pol[1].x = 0;
    pol[1].y = 480.0f;
    pol[1].z = 1.25f;
    pol[1].col = argb;
    
    pol[2].x = 640.0f;
    pol[2].y = 0;
    pol[2].z = 1.25f;
    pol[2].col = argb;
    
    pol[3].x = 640.0f;
    pol[3].y = 480.0f;
    pol[3].z = 1.25f;
    pol[3].col = argb;
    
    njDrawPolygon(pol, 4, 1);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
}

// 100% matching!
void bhControlCinesco()
{   
    if (((sys->cb_flg & 0x4)) && (!(sys->cb_flg & 0x40))) 
    {
        sys->cine_ap = 1.0f;
    } 
    else
    {
        sys->cine_ap = 0;
    }
    
    sys->cine_an += 0.1f * (sys->cine_ap - sys->cine_an);
    
    if ((!(sys->cb_flg & 0x4)) && (sys->cine_an < 0.004f))
    {
        sys->cine_an = 0;
    }
}

// 100% matching!
void bhDrawCinesco()
{
    NJS_POINT2COL p2c;
    NJS_POINT2 p[4];  
    NJS_COLOR col[4];  
    unsigned int argb;

    if (!(sys->cb_flg & 0x40))
    {
        njColorBlendingMode(0, 8);
        njColorBlendingMode(1, 6);

        p2c.p = p;
        
        p2c.col = col;
        
        p2c.tex = NULL;
        
        p2c.num = 1;

        argb = (unsigned int)(255.0f * sys->cine_an) << 24;
    
        p2c.col[3].color = p2c.col[2].color = p2c.col[1].color = p2c.col[0].color = argb;

        p[0].x = 0;
        p[0].y = 0;

        p[1].x = 640.0f;
        p[1].y = 0;

        p[2].x = 640.0f;
        p[2].y = 48.0f;

        p[3].x = 0;
        p[3].y = 48.0f;

        njDrawPolygon2D(&p2c, 4, -0.9f, 96);

        p[0].y = 432.0f;
        p[1].y = 432.0f;
        p[2].y = 480.0f;
        p[3].y = 480.0f;

        njDrawPolygon2D(&p2c, 4, -0.9f, 96);
        
        njColorBlendingMode(0, 8);
        njColorBlendingMode(1, 6);
    }
}

// 97.59% matching
void bhDrawScope()
{   
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];   
    NJS_POINT3 ps;     
    NJS_POINT3 as;     
    NJS_COLOR col[4];  
    NJS_COLOR uv[4];   
    unsigned int argb; 
    int i;             
    float px;          
    float bai;         

    if (!(cam.flg & 0x2)) 
    {
        njColorBlendingMode(0, 8);
        njColorBlendingMode(1, 6);
        
        njSetTexture((NJS_TEXLIST*)sys->obwp->mlwP->texP);
        njSetTextureNum(2);

        p2c.p = p;
        
        p2c.col = col;
        
        p2c.tex = uv;
        
        p2c.num = 1;
        
        if (sys->obwp->type != 13) 
        {
            argb = 0x20008000;
        } 
        else 
        {
            argb = 0x20804000;
        }

        col[3].color = col[2].color = col[1].color = col[0].color = argb;
        
        p[0].x = 0;
        p[0].y = 0;
        
        p[1].x = 640.0f;
        p[1].y = 0;
        
        p[2].x = 640.0f;
        p[2].y = 480.0f;
        
        p[3].x = 0;
        p[3].y = 480.0f;
        
        njDrawPolygon2D(&p2c, 4, -0.92f, 96);

        col[3].color = col[2].color = col[1].color = col[0].color = -1;
        
        uv[0].tex.u = 0;
        uv[0].tex.v = 160;

        uv[1].tex.u = 160;
        uv[1].tex.v = 160;

        uv[2].tex.u = 160;
        uv[2].tex.v = 192;

        uv[3].tex.u = 0;
        uv[3].tex.v = 192;
        
        p[0].x = 280.0f;
        p[0].y = 232.0f;
        
        p[1].x = 360.0f;
        p[1].y = 232.0f;
        
        p[2].x = 360.0f;
        p[2].y = 248.0f;
        
        p[3].x = 280.0f;
        p[3].y = 248.0f;
        
        njDrawPolygon2D(&p2c, 4, -0.91f, 0x80000060);
        
        uv[0].tex.u = 0;
        uv[0].tex.v = 64;

        uv[1].tex.u = 256;
        uv[1].tex.v = 64;

        uv[2].tex.u = 256;
        uv[2].tex.v = 112;

        uv[3].tex.u = 0;
        uv[3].tex.v = 112;
        
        njUnitMatrix(NULL);
        
        ps.y = 0;
        
        njRotateY(NULL, cam.pers - 11832);
        
        for (i = 0; i < 6; i++)
        {
            ps.x = -64.0f;
            ps.z = -128.0f;
            
            njCalcPoint(NULL, &ps, &as);
            
            p[0].x = 320.0f + as.x;
            p[0].y = 240.0f + as.z;
            
            ps.x = 64.0f;
            ps.z = -128.0f;
            
            njCalcPoint(NULL, &ps, &as);
            
            p[1].x = 320.0f + as.x;
            p[1].y = 240.0f + as.z;
            
            ps.x = 64.0f;
            ps.z = -104.0f;
            
            njCalcPoint(NULL, &ps, &as);
            
            p[2].x = 320.0f + as.x;
            p[2].y = 240.0f + as.z;
            
            ps.x = -64.0f;
            ps.z = -104.0f;
            
            njCalcPoint(NULL, &ps, &as);
            
            p[3].x = 320.0f + as.x;
            p[3].y = 240.0f + as.z;
            
            njDrawPolygon2D(&p2c, 4, -0.91f, 0x80000060);
            
            njRotateY(NULL, 10922);
        }
        
        uv[0].tex.u = 0;
        uv[0].tex.v = 112;

        uv[1].tex.u = 224;
        uv[1].tex.v = 112;

        uv[2].tex.u = 224;
        uv[2].tex.v = 160;

        uv[3].tex.u = 0;
        uv[3].tex.v = 160;
        
        njUnitMatrix(NULL);
        
        ps.y = 0;
        
        njRotateY(NULL, -(cam.pers - 11832));
        
        for (i = 0; i < 6; i++)
        {
            ps.x = -56.0f;
            ps.z = -112.0f;
            
            njCalcPoint(NULL, &ps, &as);
            
            p[0].x = 320.0f + as.x;
            p[0].y = 240.0f + as.z;
            
            ps.x = 56.0f;
            ps.z = -112.0f;
            
            njCalcPoint(NULL, &ps, &as);
            
            p[1].x = 320.0f + as.x;
            p[1].y = 240.0f + as.z;
            
            ps.x = 56.0f;
            ps.z = -88.0f;
            
            njCalcPoint(NULL, &ps, &as);
            
            p[2].x = 320.0f + as.x;
            p[2].y = 240.0f + as.z;
            
            ps.x = -56.0f;
            ps.z = -88.0f;
            
            njCalcPoint(NULL, &ps, &as);
            
            p[3].x = 320.0f + as.x;
            p[3].y = 240.0f + as.z;
            
            njDrawPolygon2D(&p2c, 4, -0.91f, 0x80000060);
            
            njRotateY(NULL, 10922);
        }
        
        px = 288.0f;
        
        bhDrawScopeNumber(px, 264.0f, 10);
        
        px += 16.0f;
        
        bai = 100.0f - (2.2222223f * ((0.005493164f * cam.pers) - 20.0f));
        
        bhDrawScopeNumber(px, 264.0f, bai / 100.0f);
        
        px += 16.0f;
        
        bhDrawScopeNumber(px, 264.0f, (int)(bai / 10.0f) % 10);
        
        px += 16.0f;
        
        bhDrawScopeNumber(px, 264.0f, (int)bai % 10);
        
        njColorBlendingMode(0, 8);
        njColorBlendingMode(1, 6);
    }
}

// 100% matching!
void bhDrawScopeNumber(float px, float py, int num)
{
    NJS_POINT2COL p2c;
    NJS_POINT2 p[4];
    NJS_COLOR col[4]; 
    NJS_COLOR uv[4];
    static short uv_tab[18][8] = { { 0  , 0 , 32 , 0 , 32 , 32, 0  , 32 },
                                   { 32 , 0 , 64 , 0 , 64 , 32, 32 , 32 },
                                   { 64 , 0 , 96 , 0 , 96 , 32, 64 , 32 },
                                   { 96 , 0 , 128, 0 , 128, 32, 96 , 32 },
                                   { 128, 0 , 160, 0 , 160, 32, 128, 32 },
                                   { 160, 0 , 192, 0 , 192, 32, 160, 32 },
                                   { 192, 0 , 224, 0 , 224, 32, 192, 32 },
                                   { 224, 0 , 256, 0 , 256, 32, 224, 32 },
                                   { 0  , 32, 32 , 32, 32 , 64, 0  , 64 },
                                   { 32 , 32, 64 , 32, 64 , 64, 32 , 64 },
                                   { 64 , 32, 96 , 32, 96 , 64, 64 , 64 },
                                   { 96 , 32, 128, 32, 128, 64, 96 , 64 },
                                   { 128, 32, 160, 32, 160, 64, 128, 64 },
                                   { 160, 32, 192, 32, 192, 64, 160, 64 },
                                   { 192, 32, 224, 32, 224, 64, 192, 64 },
                                   { 224, 32, 256, 32, 256, 64, 224, 64 },
                                   { 0  , 64, 32 , 64, 32 , 96, 0  , 96 },
                                   { 32 , 64, 64 , 64, 64 , 96, 32 , 96 } };
 
    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = uv;
    
    p2c.num = 1;
    
    col[3].color = col[2].color = col[1].color = col[0].color = -1;

    uv[0].tex.u = uv_tab[num][0];
    uv[0].tex.v = uv_tab[num][1];

    uv[1].tex.u = uv_tab[num][2] - 1;
    uv[1].tex.v = uv_tab[num][3];

    uv[2].tex.u = uv_tab[num][4] - 1;
    uv[2].tex.v = uv_tab[num][5] - 1;

    uv[3].tex.u = uv_tab[num][6];
    uv[3].tex.v = uv_tab[num][7] - 1;
    
    p[0].x = px;
    p[0].y = py;
    
    p[1].x = 16.0f + px;
    p[1].y = py;
    
    p[2].x = 16.0f + px;
    p[2].y = 16.0f + py;
    
    p[3].x = px;
    p[3].y = 16.0f + py;
    
    njDrawPolygon2D(&p2c, 4, -1.4f, 0x80000060);
}

// 100% matching! 
void bhDrawThermometer()
{
    NJS_POINT2COL p2c;
    NJS_POINT2 p[4];
    NJS_COLOR col[4]; 
    NJS_COLOR uv[4];
    unsigned int argb; 
    float px; 
    float py; 
    static int ten;

    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ond_tnm);

    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = uv;
    
    p2c.num = 1;

    col[3].color = col[2].color = col[1].color = col[0].color = -1;

    uv[0].tex.u = 0;
    uv[0].tex.v = 0;

    uv[1].tex.u = 216;
    uv[1].tex.v = 0;

    uv[2].tex.u = 216;
    uv[2].tex.v = 144;

    uv[3].tex.u = 0;
    uv[3].tex.v = 144;

    p[0].x = 216.0f;
    p[0].y = 100.0f;
    
    p[1].x = 432.0f;
    p[1].y = 100.0f;
    
    p[2].x = 432.0f;
    p[2].y = 244.0f;
    
    p[3].x = 216.0f;
    p[3].y = 244.0f;
    
    njDrawPolygon2D(&p2c, 4, -0.95f, 0x80000060);
    
    if (sys->ond_cx == 3) 
    {
        argb = ((int)(255.0f * njSin(ten)) << 24) | 0xFFFF00;
        
        ten = (ten + 4096) & 0x7FFF;
        
        col[3].color = col[2].color = col[1].color = col[0].color = argb;

        uv[0].tex.u = 176;
        uv[0].tex.v = 104;
    
        uv[1].tex.u = 192;
        uv[1].tex.v = 104;
    
        uv[2].tex.u = 192;
        uv[2].tex.v = 120;
    
        uv[3].tex.u = 176;
        uv[3].tex.v = 120;

        p[0].x = 392.0f;
        p[0].y = 204.0f;
        
        p[1].x = 408.0f;
        p[1].y = 204.0f;
        
        p[2].x = 408.0f;
        p[2].y = 220.0f;
        
        p[3].x = 392.0f;
        p[3].y = 220.0f;
        
        njDrawPolygon2D(&p2c, 4, -0.94f, 0x80000060);
    }
    
    if (sys->ond_ud != 0) 
    {
        col[3].color = col[2].color = col[1].color = col[0].color = -256;
        
        if (sys->ond_ud > 0) 
        {
            py = 0;

            uv[0].tex.u = 160;
            uv[0].tex.v = 168;
        
            uv[1].tex.u = 176;
            uv[1].tex.v = 168;
        
            uv[2].tex.u = 176;
            uv[2].tex.v = 184;
        
            uv[3].tex.u = 160;
            uv[3].tex.v = 184;
        } 
        else 
        {
            py = 72.0f;

            uv[0].tex.u = 176;
            uv[0].tex.v = 168;
        
            uv[1].tex.u = 192;
            uv[1].tex.v = 168;
        
            uv[2].tex.u = 192;
            uv[2].tex.v = 184;
        
            uv[3].tex.u = 176;
            uv[3].tex.v = 184;
        }
        
        p[0].x = 248.0f + (48.0f * sys->ond_cx);
        p[0].y = 128.0f + py;
        
        p[1].x = 264.0f + (48.0f * sys->ond_cx);
        p[1].y = 128.0f + py;
        
        p[2].x = 264.0f + (48.0f * sys->ond_cx);
        p[2].y = 144.0f + py;
        
        p[3].x = 248.0f + (48.0f * sys->ond_cx);
        p[3].y = 144.0f + py;
        
        njDrawPolygon2D(&p2c, 4, -0.94f, 0x80000060);
    }

    px = 240.0f;
    
    if (sys->ond_cx == 0) 
    {
        argb = -0x3FE0;
    }
    else
    {
        argb = 0xA0808080;
    }
    
    bhDrawThermoNumber(px, 146.0f, sys->ond_n[0], argb);

    px += 48.0f;
    
    if (sys->ond_cx == 1) 
    {
        argb = -0x3FE0;
    }
    else
    {
        argb = 0xA0808080;
    }
    
    bhDrawThermoNumber(px, 146.0f, sys->ond_n[1], argb);

    px += 48.0f;
    
    if (sys->ond_cx == 2)
    {
        argb = -0x3FE0;
    }
    else 
    {
        argb = 0xA0808080;
    }
    
    bhDrawThermoNumber(px, 146.0f, sys->ond_n[2], argb);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
}

// 100% matching!
void bhDrawThermoNumber(float px, float py, int num, unsigned int argb)
{
    NJS_POINT2COL p2c;
    NJS_POINT2 p[4];
    NJS_COLOR col[4]; 
    NJS_COLOR uv[4];
    static short uv_tab[10][8] = { { 0  , 160, 32 , 160, 32 , 208, 0  , 208 },
                                   { 32 , 160, 64 , 160, 64 , 208, 32 , 208 },
                                   { 64 , 160, 96 , 160, 96 , 208, 64 , 208 },
                                   { 96 , 160, 128, 160, 128, 208, 96 , 208 },
                                   { 128, 160, 160, 160, 160, 208, 128, 208 },
                                   { 0  , 208, 32 , 208, 32 , 256, 0  , 256 },
                                   { 32 , 208, 64 , 208, 64 , 256, 32 , 256 },
                                   { 64 , 208, 96 , 208, 96 , 256, 64 , 256 },
                                   { 96 , 208, 128, 208, 128, 256, 96 , 256 },
                                   { 128, 208, 160, 208, 160, 256, 128, 256 } };

    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = uv;
    
    p2c.num = 1;

    col[3].color = col[2].color = col[1].color = col[0].color = argb;
    
    uv[0].tex.u = uv_tab[num][0];
    uv[0].tex.v = uv_tab[num][1];

    uv[1].tex.u = uv_tab[num][2] - 1;
    uv[1].tex.v = uv_tab[num][3];

    uv[2].tex.u = uv_tab[num][4] - 1;
    uv[2].tex.v = uv_tab[num][5] - 1;

    uv[3].tex.u = uv_tab[num][6];
    uv[3].tex.v = uv_tab[num][7] - 1;
    
    p[0].x = px;
    p[0].y = py;
    
    p[1].x = 32.0f + px;
    p[1].y = py;
    
    p[2].x = 32.0f + px;
    p[2].y = 48.0f + py;
    
    p[3].x = px;
    p[3].y = 48.0f + py;
    
    njDrawPolygon2D(&p2c, 4, -0.94f, 0x80000060);
}

// 100% matching!
void bhDrawFullScreenRenderTexture()
{
    NJS_TEXTUREH_VTX tvh[32]; 
    int y;                    
    int y1;                   
    NJS_SCREEN scr_tex;      
    int i; // not from the debugging symbols
    
    njSetRenderWidth(512);
    njSetPerspective(cam.pers);
    
    scr_tex.dist = 0.8f * _nj_screen_.dist;
    
    scr_tex.w = 512.0f;
    scr_tex.h = 480.0f;
    
    scr_tex.cx = 256.0f;
    scr_tex.cy = 240.0f;
    
    njSetScreen(&scr_tex);
    
    bhAllDrawModel();
    
    SyncPath();
    
    Ps2DrawOTag();
    
    Ps2ClearOT();
    
    njSetTexture(&sys->ren_tlist);
    
    scr_tex.w = 640.0f;
    scr_tex.h = 480.0f;
    
    scr_tex.cx = 320.0f;
    scr_tex.cy = 240.0f;
    
    njSetScreen(&scr_tex);
    
    njRenderTextureNum(0);
    njSetTextureNum(0);
    
    njTextureFilterMode(0);
    
    for (i = 0; i < 15; i++)
    {
        y = i * 16;
        y1 = (i + 1) * 16;
        
        tvh[0] = sys->rpb[y++];
        tvh[1] = sys->rpb[y1++];
        
        tvh[2] = sys->rpb[y++];
        tvh[3] = sys->rpb[y1++];
        
        tvh[4] = sys->rpb[y++];
        tvh[5] = sys->rpb[y1++];
        
        tvh[6] = sys->rpb[y++];
        tvh[7] = sys->rpb[y1++];
        
        tvh[8] = sys->rpb[y++];
        tvh[9] = sys->rpb[y1++];
        
        tvh[10] = sys->rpb[y++];
        tvh[11] = sys->rpb[y1++];
        
        tvh[12] = sys->rpb[y++];
        tvh[13] = sys->rpb[y1++];
        
        tvh[14] = sys->rpb[y++];
        tvh[15] = sys->rpb[y1++];
        
        tvh[16] = sys->rpb[y++];
        tvh[17] = sys->rpb[y1++];
        
        tvh[18] = sys->rpb[y++];
        tvh[19] = sys->rpb[y1++];
        
        tvh[20] = sys->rpb[y++];
        tvh[21] = sys->rpb[y1++];
        
        tvh[22] = sys->rpb[y++];
        tvh[23] = sys->rpb[y1++];
        
        tvh[24] = sys->rpb[y++];
        tvh[25] = sys->rpb[y1++];
        
        tvh[26] = sys->rpb[y++];
        tvh[27] = sys->rpb[y1++];
        
        tvh[28] = sys->rpb[y++];
        tvh[29] = sys->rpb[y1++];
        
        tvh[30] = sys->rpb[y++];
        tvh[31] = sys->rpb[y1++]; 
        
        njDrawTextureH(tvh, 32, 1, 0);
    } 
    
    njTextureFilterMode(1);
}

// 98.72% matching
void bhDrawSmallScreenRenderTexture()
{
    O_WRK* op;           
    CAM_WORK cambk;      
    unsigned int gm_flg; 
    float dist;          
    NJS_SCREEN scr_tex;  

    if ((Ps2_rendertex_initflag == 0) && ((!(sys->st_flg & 0x1)) && (sys->stg_no != 7)))
    {
        if ((sys->gm_flg & 0x20))
        {
            Ps2_rendertex_initflag = 1;
        }
        else
        {
            PS2_Render_tex_sub_flag = 1;
            return;
        }
    }

    op = &eff[sys->ren_idx[0]];
    
    if ((bhCheckClipPoint((NJS_POINT3*)&op->px) == 0) && (!(op->stflg & 0x10))) 
    {
        gm_flg = sys->gm_flg;
        
        sys->gm_flg |= 0x80;

        dist = _nj_screen_.dist;
        
        njSetRenderWidth(512);
        njSetMatrix(&lcmat[10], cam.mtx);
        njSetMatrix(&lcmat[11], cam.mtxb);

        cambk = cam;
        
        bhSetRenderCut(op->type);
        
        bhControlCamera();
        
        scr_tex.dist = 0.8f * _nj_screen_.dist;
        
        scr_tex.w = 512.0f;
        scr_tex.h = 512.0f;
        
        scr_tex.cx = 256.0f;
        scr_tex.cy = 256.0f;
        
        njSetScreen(&scr_tex);
        
        if (sys->stg_no == 7)
        {
            njCnkSetEasyLightColor(0.3f, 0.3f, 1.0f);
            njCnkSetEasyLightIntensity(4.0f, 0.5f);
            njCnkSetEasyLight(0.35f, -0.15f, 0.5f);
            
            njCnkSetSimpleLightColor(0.3f, 0.3f, 1.0f);
            njCnkSetSimpleLightIntensity(4.0f, 0.5f);
            njCnkSetSimpleLight(0.35f, -0.15f, 0.5f);
        } 
        else 
        {
            njCnkSetEasyLightColor(1.0f, 1.0f, 1.0f);
            njCnkSetEasyLightIntensity(1.0f, 0.2f);
            njCnkSetEasyLight(0, 0.3f, 0.7f);
            
            njCnkSetSimpleLightColor(1.0f, 1.0f, 1.0f);
            njCnkSetSimpleLightIntensity(1.0f, 0.2f);
            njCnkSetSimpleLight(0, 0.3f, 0.7f);
        }
        
        sys->st_flg |= 0x20;
        
        bhAllEasyDrawModel();
        
        Ps2DrawOTag();
        
        Ps2ClearOT();
        
        sys->st_flg &= ~0x20;
        
        njSetTexture(&sys->ef_tlist);
        
        if (sys->stg_no == 7)
        {
            njRenderTextureNumG(2);
        }
        else 
        {
            Ps2_rendertex_initflag = 0;
            
            PS2_Render_Tex_Sub();
        }
        
        scr_tex.w = 640.0f;
        scr_tex.h = 480.0f;
        
        scr_tex.cx = 320.0f;
        scr_tex.cy = 240.0f;
        
        njSetScreen(&scr_tex);
        
        cam = cambk;
        
        njSetMatrix(cam.mtx, &lcmat[10]);
        njSetMatrix(cam.mtxb, &lcmat[11]);        
        njSetScreenProjection(dist);
        
        Ps2CalcScreenCone();
        
        sys->gm_flg = gm_flg;
        
        if ((cam.flg & 0x2)) 
        {
            bhSetEventHideObjLgt(cam.evc_no, cam.keyf_no);
        } 
        else 
        {
            bhSetHideObjLgt(cam.ncut);
        }
        
        bhSetLight();
    }
}
