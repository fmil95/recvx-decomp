#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaFog.h"
#include "../../../ps2/veronica/prog/ps2_NaGraphics3D.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMem.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_NinjaPtcl.h"

#pragma divbyzerocheck on 

static unsigned int owk_scn_noG;

static void (*FuncTbl[4])(O_WRK* oP) = 
{
	NULL,
	bhEff_PtclSpriteDrawB,
	bhEff_PtclLineDraw,
	NULL
};

EFF302PRM_WORK Eff302Prm[20] = 
{
    { 1.0f, -0.08f,  20.0f, 0.5f, 0.5f,  0.025f, 16, {  0,  2,  4,  6,  8, 10 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.4f,   0.0f,  45.0f, 1.0f, 1.0f,  0.025f, 20, {  0,  1,  8,  9, 16, 17 }, { 0.0f, -0.06533334, 0.0f } },
    { 1.2f, -0.08f,  10.0f, 0.5f, 0.5f,  0.025f, 16, {  0,  0,  0,  0,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 1.0f, -0.05f,  60.0f, 0.5f, 0.5f,  0.025f, 24, {  0,  0,  0,  0,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.4f,   0.0f,  45.0f, 1.0f, 1.0f,  0.025f, 20, { -1, -1,  0,  0,  1,  1 }, { 0.0f, -0.06533334, 0.0f } },
    { 0.5f, -0.05f,  55.0f, 0.1f, 0.8f,   0.01f,  5, { -1, -1, -1, -1, -1,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.6f, -0.05f,  50.0f, 0.1f, 0.8f,   0.02f,  7, { -1, -1, -1, -1, -1,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.7f, -0.05f,  45.0f, 0.1f, 0.8f,   0.03f,  9, { -1, -1, -1, -1, -1,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 1.0f, -0.01f,  20.0f, 0.1f, 0.8f,   0.03f, 12, { -1, -1, -1, -1,  0,  1 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.8f, -0.05f,  20.0f, 0.5f, 0.5f,  0.025f, 12, { -1, -1, -1, -1,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.3f,   0.0f, 360.0f, 1.0f, 1.0f,  0.025f, 16, {  0,  0,  0,  0,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.3f,   0.0f,  45.0f, 0.0f, 1.0f,  0.025f,  7, { -1, -1, -1, -1, -1,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.2f,   0.0f, 360.0f, 1.0f, 1.0f,  0.025f, 12, {  0,  0,  0,  0,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.3f,   0.0f, 180.0f, 0.5f, 0.5f,  0.025f, 16, {  0,  2,  4,  6,  8, 10 }, { 0.0f, -0.03266667, 0.0f } },
    { 1.0f, -0.08f, 360.0f, 1.0f, 1.0f,  0.035f,  9, {  0,  0,  2,  2,  5,  5 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.4f,   0.0f, 150.0f, 1.0f, 1.0f,   0.04f, 16, {  0,  0,  2,  2,  5,  5 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.4f, -0.02f,  60.0f, 1.0f, 1.0f,   0.04f, 10, { -1,  0,  0,  0,  1,  1 }, { 0.0f, -0.016333334,0.0f } },
    { 0.5f, -0.04f,  45.0f, 1.0f, 1.0f,  0.045f, 10, {  0,  0,  1,  2,  3,  5 }, { 0.0f, -0.06533334, 0.0f } },
    { 0.8f, -0.05f,  60.0f, 0.5f, 1.0f,   0.05f, 12, {  0,  0,  1,  1,  2,  3 }, { 0.0f, -0.098000005,0.0f } },
    { 0.4f,   0.0f,  60.0f, 0.5f, 0.5f, 0.0055f, 40, { -1, -1,  0,  0,  1,  1 }, { 0.0f, -0.02f,      0.0f } }
};

static const UV_WORK Tex5uv[9] = 
{
    { 0.09375f, 0.15625f, 0.12500f, 0.12500f },   
    { 0.46875f, 0.00000f, 0.15625f, 0.15625f },   
    { 0.37500f, 0.15625f, 0.15625f, 0.15625f },   
    { 0.00000f, 0.00000f, 0.15625f, 0.15625f },   
    { 0.00000f, 0.15625f, 0.09375f, 0.09375f },   
    { 0.21875f, 0.15625f, 0.15625f, 0.15625f },   
    { 0.65625f, 0.84375f, 0.12500f, 0.15625f },   
    { 0.81250f, 0.59375f, 0.18750f, 0.18750f },   
    { 0.78125f, 0.78125f, 0.21875f, 0.21875f }   
};

// 100% matching!
static O_WRK* AllocOwork()
{
    O_WRK* oP;
    int o_no;

    o_no = owk_scn_noG;
    
    for (oP = &eff[o_no]; o_no < 512; o_no++, oP++) 
    {
        if (!(oP->flg & 0x3))
        {
            npSetMemory((unsigned char*)oP, sizeof(*oP), 0);
            
            oP->flg = 0x2;
            
            owk_scn_noG = o_no + 1;
            
            return oP;
        }
    }
    
    return NULL;
}

// 100% matching!
O_WRK* AllocOworkOne()
{
    O_WRK* oP;
    int o_no;

    o_no = 512;

    oP = eff;
    
    for ( ; o_no > 0; o_no--, oP++) 
    {
        if (!(oP->flg & 0x3))
        {
            npSetMemory((unsigned char*)oP, sizeof(*oP), 0);
            
            oP->flg = 0x2;
            
            return oP;
        }
    }
    
    return NULL;
}

// 100% matching!
void bhClrEff_RY()
{
    O_WRK* oP;
	int i;

    oP = eff;
    
    for (i = 0; i < 512; i++, oP++) 
    {
        if ((oP->flg & 0x1))
        {
            switch (oP->id) 
            {                     
            case 301:
                oP->flg = 0;
                break;
            case 302:
                *(int*)oP->exp1 = 0;
                *(int*)oP->exp0 = 0;
                
                oP->flg = 0;
                break;
            }
        }
    }
}

// 100% matching!
int bhSetBloodPoolLnk(BH_PWORK* ewP, NJS_POINT3* posP, int ay, BP_WORK* tabP, int pal_bnk)
{
    O_WRK* o0P, *o1P;    
    int eff_no;     
    E17_WORK* e17P; 
    
    if ((o0P = AllocOworkOne()) != NULL) 
    {
        if ((o1P = AllocOworkOne()) != NULL)
        {
            e17P = (E17_WORK*)o1P;

			eff_no = 300;
            
            o0P->flg = 0x200001;
            
            o0P->id   = eff_no;
            o0P->type = 0;
            
            o0P->tex_id = 17;
            
            o0P->mdlver = 0;
            
            o0P->flr_no = 0;
            
            *(NJS_POINT3*)&o0P->px = *posP;
            
            o0P->py += 0.01f;
            
            njAddVector((NJS_VECTOR*)&o0P->px, &tabP->off_pos);
            
            o0P->py += 0.001f * sys->bl_ct;
            
            sys->bl_ct = (sys->bl_ct + 1) & 0x1FF;
            
            o0P->lox = o0P->loy = o0P->loz = 0;
            o0P->sx  = o0P->sy  = o0P->sz  = 1.0f;
            o0P->ax  = o0P->ay  = o0P->az  = 0;
            
            o0P->mlwP = &sys->efm[300];
            
            o0P->lkwkp = (unsigned char*)ewP;
            o0P->lkono = 0;
            
            o0P->mtx = (NJS_MATRIX*)o0P->mtxbuf;
            
            o0P->pvp = o0P->pv;
            o0P->tvp = e17P->tv_buf;
            
            o0P->pn = 16;
            
            o0P->bl_src = 8;
            o0P->bl_dst = 6;
            
            o0P->ani_ct = pal_bnk;
            
            o0P->exp0 = (unsigned char*)e17P;
            
            o0P->mode0 = 0;
            
            e17P->eff_dir = ay;
            
            e17P->srd_dir = tabP->srd_dir;
            e17P->srd_pos = tabP->srd_pos;
            
            e17P->bld_spd = tabP->bld_spd;
            
            e17P->srt_spd[0] = tabP->srt_spd[0];
            e17P->srt_spd[1] = tabP->srt_spd[1];
            e17P->srt_spd[2] = tabP->srt_spd[2];
            e17P->srt_spd[3] = tabP->srt_spd[3];
            e17P->srt_spd[4] = tabP->srt_spd[4];
            
            e17P->srt_vtx[0] = tabP->srt_dir[0];
            e17P->srt_vtx[1] = tabP->srt_dir[1];
            e17P->srt_vtx[2] = tabP->srt_dir[2];
            e17P->srt_vtx[3] = tabP->srt_dir[3];
            e17P->srt_vtx[4] = tabP->srt_dir[4];
            
            return 1;
        }
        
        o0P->flg = 0;
    }
    
    return 0;
}

// 99.53% matching
void bhEff300(O_WRK* oP)
{
    static const int VtxTbl[16] = 
    {
        0, 1, 3, 5, 7, 9, 11, 13, 15, 14, 12, 10, 8, 6, 4, 2
    };
    E17_WORK* e17P; 

    e17P = (E17_WORK*)oP->exp0;

    switch (oP->mode0) 
    {
    case 0:
    {
        NJS_POINT3 center;    
        float spd;           
        int ang;            
        int tmp; // not from DWARF
        NJS_TEXTURE_VTX* tvP;
        NJS_POINT3* spdP;    
        int i;               
        
        spd = e17P->srd_pos * e17P->bld_spd;
        ang = e17P->srd_dir;
        
        center.x = spd * -njCos(ang);
        center.y = 0;
        center.z = spd * njSin(ang);

        tvP  = &e17P->tv_buf[0];
        spdP = &e17P->tv_spd[0];
        
        ang = e17P->eff_dir + 16384;
        
        for (i = 0; i < 16; i++, tvP++, spdP++) 
        {
            tmp = 4096 * i;
            
            spd = e17P->bld_spd;
            
            if (!(i & 0x1)) 
            {
                tmp *= -1;
            }
            
            ang += tmp;
            
            tvP->x = tvP->y = tvP->z = 0;
            
            tvP->u = 0.5f + (0.5f * njCos(ang));
            tvP->v = 0.5f + (0.5f * njSin(ang));
            
            tvP->col = 0xF0808080;
            
            spdP->x = spd * njCos(ang);
            spdP->y = 0;
            spdP->z = spd * -njSin(ang);
            
            njSubVector(spdP, &center);
        }
        
        oP->ct0 = 0;
        
        oP->mode0++;
        break;
    }
    case 1:
    {
        int ang;             
        int tmp;             
        float spd;           
        NJS_POINT3* addP;    
        NJS_TEXTURE_VTX* tvP; 
        int i;               
        int srt_no;           
        
        addP = &e17P->tv_spd[0];
        tvP  = &e17P->tv_buf[0];
        
        for (i = 0; i < 16; ) 
        {
            njAddVector((NJS_VECTOR*)&tvP->x, addP);
            
            addP->x *= 0.98f;
            addP->z *= 0.98f;
            
            i++;
            tvP++;
            addP++;
        }
        
        for (srt_no = 0; srt_no < 5; srt_no++) 
        {
            float spd;     
            
            spd = e17P->srt_spd[srt_no];
            
            if (spd != 0) 
            {
                NJS_POINT3 add;
                NJS_TEXTURE_VTX* tvP; 
                int pnt;              
                NJS_POINT3 pos;       

                tvP = e17P->tv_buf;
                
                pnt = e17P->srt_vtx[srt_no];
                
                add = e17P->tv_spd[VtxTbl[pnt]];
                
                pos = *(NJS_POINT3*)&oP->px;
                
                njAddVector(&pos, (NJS_VECTOR*)&tvP[VtxTbl[pnt & 0xF]].x);
                
                if (bhCheckWallType(&pos, 0, 0.2f, 0) != NULL) 
                {
                    e17P->srt_spd[srt_no] = 0;
                } 
                else 
                {
                    add.x *= spd;
                    add.z *= spd;
                    
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[pnt & 0xF]].x,       &add);
                    
                    add.x *= 0.9f;
                    add.z *= 0.9f;
                    
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt + 1) & 0xF]].x, &add);
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt - 1) & 0xF]].x, &add);
                    
                    add.x *= 0.4f;
                    add.z *= 0.4f;
                    
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt + 2) & 0xF]].x, &add);
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt - 2) & 0xF]].x, &add);
                    
                    add.x *= 0.2f;
                    add.z *= 0.2f;
                    
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt + 3) & 0xF]].x, &add);
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt - 3) & 0xF]].x, &add);
                }
            }
        }
         
        if (oP->ct0++ > 256) 
        {
            oP->mode0++;
            
            oP->ct0 = 0;
        }
    }
    case 2:
    {
        BH_PWORK* ewP; 
        
        ewP = (BH_PWORK*)oP->lkwkp;
        
        if ((ewP == NULL) || ((!(ewP->stflg & 0x1000000)) && ((sys->pt_flg & 0x2)))) 
        {
            sys->ef_trs[sys->ef_trsn++] = oP;
        }
        
        break;
    }
    } 
}

// 99.90% matching
void bhEff301(O_WRK* oP)
{
	static const Eff301PRM_WORK Eff301Prm[7] = 
	{
		{ 0xFFC0C0C0, 30.0f,  90.0f },
		{ 0xFFC0C0C0, 30.0f,  90.0f },
		{ 0xFFC0C0C0, 30.0f,  60.0f },
		{ 0xFFC0C0C0, 50.0f,  60.0f },
		{ 0xFFC0C0C0, 50.0f,  30.0f },
		{ 0xFFC0C0C0, 50.0f,  30.0f },
		{ 0xFFC0C0C0, 50.0f, 270.0f }
	};
	static const unsigned char AnmTbl[4][2] = 
	{
		{ 3, 6 }, { 4, 7 }, { 5, 8 }, { 3, 6 }
	};
    const Eff301PRM_WORK* prmP; 
    ATR_WORK* htP;        
    int ax, ay;              
    float rng;         
    NJS_POINT3 pos;       
    float adj;           
    
    if ((sys->gm_flg & 0x2000000))
    {
        oP->flg = 0;
        return;
    }
    
    switch (oP->mode0) 
    {                  
    case 0:
        prmP = &Eff301Prm[oP->type]; 
        
        oP->tex_id = 5;
        
        oP->flg = 0x200001;
        
        oP->bl_src = 8;
        oP->bl_dst = 6;
        
        oP->ani_ct = oP->mdlver;
        
        ax = oP->ax + (int)(182.04445f * (0.5f * (prmP->ang_rand * ((-rand() / -2.1474836E9f) - 0.5f))));
        ay = oP->ay + (int)(182.04445f *         (prmP->ang_rand * ((-rand() / -2.1474836E9f) - 0.5f)));
        
        rng = prmP->vtx_range;
        
        oP->ayp = ay;
        
        adj = -njSin(ay) * njCos(ax);
        
        oP->aox = rng * adj;
        oP->aoy = rng * njSin(ax);
        
        adj = -njCos(ay) * njCos(ax);
        
        oP->aoz = rng * adj;
        
        if ((oP->mdlver == 0) && (bhCheckCamWall2D((NJS_POINT3*)&oP->px, (NJS_POINT3*)&oP->aox, &pos, 16.0f, 12.0f) != 0) && ((10.0f < pos.z) && (pos.z < rng)) && (!(cam.flg & 0x10)))
        {
            oP->spd = pos.z;
            
            *(NJS_POINT3*)&oP->aox = pos;
            
            oP->aoz = 0;
            
            oP->xn = oP->yn = 0;
            oP->zn = -1.0f;
            
            oP->shp_ct = 1.0f + (2.0f * (-rand() / -2.1474836E9f));
            
            oP->exp0 = (unsigned char*)AnmTbl[(ax + ay) & 3];
            oP->exp1 = NULL;
            
            oP->ct0 = 0;
            oP->ct1 = ((int)(0.05f * oP->spd) + (ax + ay)) & 3;
            oP->ct2 = oP->exp0[1];
            oP->ct3 = prmP->color + 0xC0000000;
            
            oP->mode0++;
        }
        else
        {
            njAddVector((NJS_VECTOR*)&oP->aox, (NJS_VECTOR*)&oP->px);
            
            if ((htP = bhCollisionCheckLine2((NJS_POINT3*)&oP->px, (NJS_POINT3*)&oP->aox, 0x4400, -1)) != NULL) 
            {
                if (!(htP->flg & 0x10)) 
                {
                    oP->shp_ct = 1.0f + (2.0f * (-rand() / -2.1474836E9f));
                    
                    oP->spd = njDistanceP2P((NJS_POINT3*)&oP->px, (NJS_POINT3*)&oP->aox);
                    
                    bhGetHitCollisionNormal((NJS_POINT3*)&oP->xn);
                    
                    oP->exp0 = (unsigned char*)AnmTbl[(ax + ay) & 3];
                    oP->exp1 = &htP->flg;
                    
                    oP->ct0 = 0;
                    oP->ct1 = 0.1f * (int)oP->spd;
                    oP->ct2 = oP->exp0[0];
                    oP->ct3 = prmP->color;
                    
                    oP->mode0++;
                } 
                else 
                {
                    oP->flg = 0;
                }
            }
            else 
            {
                oP->flg = 0;
            }
        }
        
        break;
    case 1:
        if (oP->ct1 > 0) 
        {
            oP->ct1--;
        } 
        else 
        {
            adj = 0.01f + (0.001f * sys->bl_ct);
            
            sys->bl_ct = (sys->bl_ct + 1) & 0x1FF;
            
            njUnitVector((NJS_VECTOR*)&oP->xn);
            
            oP->px = oP->aox + (oP->xn * adj);
            oP->py = oP->aoy + (oP->yn * adj);
            oP->pz = oP->aoz + (oP->zn * adj);
            
            if (oP->exp1 == NULL) 
            {
                oP->mode0 = 24;
            }
            else if (oP->exp1[1] == 6)
            {
                oP->mode0 = 16;
            } 
            else if (!oP->yn) 
            {
                oP->mode0 = 8;
            } 
            else if ((htP = bhCheckWater((NJS_POINT3*)&oP->px)) != NULL) 
            { 
                oP->exp1 = &htP->flg;
                
                oP->py += 0.5f * (htP->h * (-rand() / -2.1474836E9f));
                
                oP->mode0 = 12;
            }
            else 
            {
                oP->mode0 = 4;
            }
        }
        
        break;
    case 4:
    {
        float off_set;     
        
        oP->ax = -16384;
        oP->ay = oP->ayp;
        
        off_set = 0.05f * oP->spd;
        
        oP->tv[0].y += off_set;
        oP->tv[1].y += off_set;
        oP->tv[2].y += off_set;
        oP->tv[3].y += off_set;
        
        oP->ct2 = oP->exp0[0];
        
        oP->mode0++;
    }
    case 5:
        oP->sxb *= 1.5f;
        oP->syb *= 1.5f;
        
        if (oP->sxb > oP->shp_ct)
        {
            oP->mode0++;
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    case 6:
        oP->ct3 += 0xFE000000;
        
        oP->sxb += 0.01f;
        oP->syb += 0.01f;
        
        if ((unsigned int)oP->ct3 < 0x2000000) 
        {
            oP->flg = 0;
            break;
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    case 8:
        oP->ax = 10430.381f * asinf(oP->yn);
        oP->ay = 10430.381f * atan2f(oP->xn, oP->zn);
        
        oP->tv[0].y = oP->tv[1].y = -2.0f;
        oP->tv[2].y = oP->tv[3].y = 0;
        
        oP->ct2 = oP->exp0[1];
        
        oP->mode0++;
    case 9:
        oP->sxb *= 1.5f;
        oP->syb *= 1.5f;
        
        if (oP->sxb > oP->shp_ct) 
        {
            oP->mode0++;
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    case 10:
        oP->ct3 += 0xFE000000;
        
        oP->sxb -= 0.005f;
        oP->syb += 0.03f;
        
        if ((unsigned int)oP->ct3 < 0x2000000) 
        {
            oP->flg = 0;
            break;
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    case 12:
    {
        int ay; 
        
        oP->flg |= 0x100000;
        
        oP->ct3 &= 0xFFFFFF;
        oP->ct3 |= 0xC0000000;
        
        ay = oP->ayp + (int)(182.04445f * (240.0f * ((-rand() / -2.1474836E9f) - 0.5f)));
        
        oP->aox = 0.03f * -njSin(ay);
        oP->aoy = 0.01f;
        oP->aoz = 0.03f * -njCos(ay);
        
        oP->mode0++;
    }
    case 13:
        oP->sxb *= 1.5f;
        oP->syb *= 1.5f;
        
        if (oP->sxb > oP->shp_ct)
        {
            oP->mode0++;
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    case 14:
        oP->ct3 += 0xFF000000;
        
        oP->sxb += 0.02f;
        oP->syb += 0.02f;
        
        if ((unsigned int)oP->ct3 < 0x1000000)
        {
            oP->flg = 0;
        } 
        else 
        {
            sys->ef_trs[sys->ef_trsn++] = oP;
        }
        
        njAddVector((NJS_VECTOR*)&oP->px, (NJS_VECTOR*)&oP->aox);
        break;
    case 16:
        oP->ax = -(int)(10430.381f * asinf(oP->yn));
        oP->ay =        10430.381f * atan2f(oP->xn, oP->zn);
        
        oP->ct2 = oP->exp0[0];
        
        oP->mode0++;
    case 17:
        oP->sxb *= 1.5f;
        oP->syb *= 1.5f;
        
        if (oP->sxb > oP->shp_ct) 
        {
            oP->mode0 = 6;
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    case 24:
    {
        float siz_x, siz_y; 
        
        oP->gidx = bhGetGidx(oP);
        
        oP->tv[0].z = oP->tv[1].z = oP->tv[2].z = oP->tv[3].z = 1.0f + oP->pz;
        
        oP->sxb *= 1.5f;
        oP->syb *= 1.5f;
        
        siz_x =         30.0f * oP->sxb;
        siz_y = 2.0f * (30.0f * oP->syb);
        
        oP->tv[0].x = oP->px + siz_x;
        oP->tv[0].y = oP->py + siz_y;
        
        oP->tv[1].x = oP->px - siz_x;
        oP->tv[1].y = oP->py + siz_y;
        
        oP->tv[2].x = oP->px + siz_x;
        oP->tv[2].y = oP->py;
        
        oP->tv[3].x = oP->px - siz_x;
        oP->tv[3].y = oP->py;
        
        if (oP->sxb > oP->shp_ct) 
        {
            oP->mode0++;
        }
        
        if (!(sys->gm_flg & 0x20)) 
        {
            sys->ef_trs2d[sys->ef_trs2dn++] = oP;
        } 
        else 
        {
            oP->flg = 0;
        }
        
        break;
    }
    case 25:
    {
        float siz_x, siz_y; 
            
        oP->ct3 += 0xFE000000;
        
        oP->sxb -= 0.01f;
        oP->syb += 0.03f;
        
        siz_x =         30.0f * oP->sxb;
        siz_y = 2.0f * (30.0f * oP->syb);
        
        oP->tv[0].x = oP->px + siz_x;
        oP->tv[0].y = oP->py + siz_y;
        
        oP->tv[1].x = oP->px - siz_x;
        oP->tv[1].y = oP->py + siz_y;
        
        oP->tv[2].x = oP->px + siz_x; 
        oP->tv[2].y = oP->py;
        
        oP->tv[3].x = oP->px - siz_x;
        oP->tv[3].y = oP->py;
        
        if ((!(sys->gm_flg & 0x20)) && ((unsigned int)oP->ct3 > 0x2000000)) 
        {
            sys->ef_trs2d[sys->ef_trs2dn++] = oP;
        }
        else 
        {
            oP->flg = 0;
        }
        
        break;
    }
    }
    
    {
    const UV_WORK* uvP; 
    
    uvP = &Tex5uv[oP->ct2];
        
    oP->sx = oP->sxb + uvP->xs;
    oP->sy = oP->syb + uvP->ys;
        
    oP->tv[0].u = uvP->u + uvP->xs;
    oP->tv[0].v = uvP->v + uvP->ys;
        
    oP->tv[1].u = uvP->u;
    oP->tv[1].v = uvP->v + uvP->ys;
        
    oP->tv[2].u = uvP->u + uvP->xs;
    oP->tv[2].v = uvP->v;
        
    oP->tv[3].u = uvP->u;
    oP->tv[3].v = uvP->v;
        
    oP->tv[0].col = oP->tv[1].col = oP->tv[2].col = oP->tv[3].col = oP->ct3;
    }
}

static const PD_WORK PtclDat00[2] = 
{ 
	{ 0, 255, 1 }, { 0, 224, 1 } 
};
static const PD_WORK PtclDat01[2] = 
{ 
	{ 1, 255, 1 }, { 1, 224, 1 } 
};
static const PD_WORK PtclDat02[2] = 
{ 
	{ 2, 255, 1 }, { 3, 224, 1 } 
};
static const PD_WORK PtclDat03[1] = 
{ 
	{ 4, 255, 1 } 
};
static const PD_WORK PtclDat04[2] = 
{ 
	{ 5, 255, 2 }, { 11, 128, 1 } 
};
static const PD_WORK PtclDat05[2] = 
{ 
	{ 6, 255, 2 }, { 11, 128, 1 } 
};
static const PD_WORK PtclDat06[2] = 
{ 
	{ 7, 255, 2 }, { 11, 128, 1 } 
};
static const PD_WORK PtclDat07[2] = 
{ 
	{ 8, 255, 2 }, { 11, 128, 1 } 
};
static const PD_WORK PtclDat08[1] = 
{ 
	{ 9, 255, 1 } 
};
static const PD_WORK PtclDat09[2] = 
{ 
	{ 10, 255, 1 }, { 10, 224, 1 } 
};
static const PD_WORK PtclDat10[1] = 
{ 
	{ 12, 255, 1 } 
};
static const PD_WORK PtclDat11[1] = 
{ 
	{ 13, 255, 1 } 
};
static const PD_WORK PtclDat12[2] = 
{ 
	{ 14, 255, 1 }, { 14, 160, 1 } 
};
static const PD_WORK PtclDat13[2] = 
{ 
	{ 15, 255, 1 }, { 15, 160, 1 } 
};
static const PD_WORK PtclDat14[1] = 
{ 
	{ 16, 255, 1 } 
};
static const PD_WORK PtclDat15[2] = 
{ 
	{ 17, 255, 1 }, { 17, 160, 1 } 
};
static const PD_WORK PtclDat16[2] = 
{ 
	{ 18, 255, 1 }, { 18, 160, 1 } 
};
static const PD_WORK PtclDat17[1] = 
{ 
	{ 0, 255, 1 } 
};
static const PD_WORK PtclDat18[1] = 
{ 
	{ 19, 255, 1 } 
};

static const PT_WORK PtclTbl[19] = 
{
    { 2, PtclDat00 },
    { 2, PtclDat01 },
    { 2, PtclDat02 },
    { 1, PtclDat03 },
    { 2, PtclDat04 },
    { 2, PtclDat05 },
    { 2, PtclDat06 },
    { 2, PtclDat07 },
    { 1, PtclDat08 },
    { 2, PtclDat09 },
    { 1, PtclDat10 },
    { 1, PtclDat11 },
    { 2, PtclDat12 },
    { 2, PtclDat13 },
    { 1, PtclDat14 },
    { 2, PtclDat15 },
    { 2, PtclDat16 },
    { 1, PtclDat17 },
    { 1, PtclDat18 }
};

// 100% matching!
O_WRK* bhSetEffParticle(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int color, int typ_no)
{
   PT_WORK* ptP;    
    PD_WORK* pdP;  
    O_WRK* oP;        
    E02_WORK* e02aP; 
    int set_no; // different position than DWARF     
    E02_WRK* e02bP;   
    unsigned int tmp; 
    
	ptP = (PT_WORK*)&PtclTbl[typ_no];
    pdP = ptP->pdP;
    
    owk_scn_noG = 0;

    for (set_no = ptP->set_num; set_no > 0; set_no--, pdP++)  
    {
        oP = AllocOwork();
        
        e02aP = (E02_WORK*)AllocOwork();
        e02bP = (E02_WRK*)AllocOwork();

        if ((oP == NULL) || (e02aP == NULL) || (e02bP == NULL)) 
        {
            if (oP != NULL) 
            {
                oP->flg = 0;
            }
            
            if (e02aP != NULL) 
            {
                e02aP->flg = 0;
            }
            
            if (e02bP != NULL) 
            {
                e02bP->flg = 0;
            }
            
            return NULL;
        }

        oP->exp0 = (unsigned char*)e02aP;
        oP->exp1 = (unsigned char*)e02bP;
        
        oP->func = (void*)FuncTbl[pdP->drw_typ];
        
        oP->type = pdP->mov_no;
        
        oP->id = 302;
        
        oP->txp[0] = &sys->ef_tlist;
        
        oP->tex_id = sys->ef_tn[4];
        
        oP->mtn_attr = (((color   & 0xFF00FF) * (pdP->col_lv + 1)) >> 8) & 0xFF00FF;
        oP->mtn_attr |= ((((color & 0xFF00)   * (pdP->col_lv + 1)) >> 8) & 0xFF00) | 0xFF000000;
        
        oP->mtn_no = (oP->mtn_attr & 0xFFFFFF) | 0x20000000;

        if (ewP != NULL)
        {
            oP->flg = 0x81;
            
            oP->lkwkp = (unsigned char*)ewP;
            oP->lkono = lnk_no;
            
            if (offP != NULL) 
            {
                *(NJS_POINT3*)&oP->lox = *offP;
            }
            else 
            {
                oP->lox = oP->loy = oP->loz = 0;
            }
        }
        else 
        {
            oP->flg = 1;
            
            oP->lkwkp = NULL;
            oP->lkono = lnk_no;
            
            *(NJS_POINT3*)&oP->px = *offP;
        }

        oP->mtx = (NJS_MATRIX*)oP->mtxbuf;
        
        *(NJS_POINT3*)&oP->xn = *dirP;
        
        njUnitVector((NJS_VECTOR*)&oP->xn);
    }

    return oP;
}

// 100% matching!
O_WRK* bhSetEffParticleMk2(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no)
{
    PT_WORK* ptP;    
    PD_WORK* pdP;  
    O_WRK* oP;        
    E02_WORK* e02aP; 
    int set_no; // different position than DWARF     
    E02_WRK* e02bP;   
    unsigned int tmp; 
    
	ptP = (PT_WORK*)&PtclTbl[typ_no];
    pdP = ptP->pdP;
    
    owk_scn_noG = 0;

    for (set_no = ptP->set_num; set_no > 0; set_no--, pdP++) 
    {
        oP = AllocOwork();
        
        e02aP = (E02_WORK*)AllocOwork();
        e02bP = (E02_WRK*)AllocOwork();

        if ((oP == NULL) || (e02aP == NULL) || (e02bP == NULL)) 
        {
            if (oP != NULL) 
            {
                oP->flg = 0;
            }
            
            if (e02aP != NULL) 
            {
                e02aP->flg = 0;
            }
            
            if (e02bP != NULL) 
            {
                e02bP->flg = 0;
            }
            
            return NULL;
        }

        oP->exp0 = (unsigned char*)e02aP;
        oP->exp1 = (unsigned char*)e02bP;
        
        oP->func = (void*)FuncTbl[pdP->drw_typ];
        
        oP->type = pdP->mov_no;
        
        oP->id = 302;
        
        oP->txp[0] = &sys->ef_tlist;
        
        oP->tex_id = sys->ef_tn[4];
        
        oP->mtn_attr = (((src_col   & 0xFF00FF) * (pdP->col_lv + 1)) >> 8) & 0xFF00FF;
        oP->mtn_attr |= ((((src_col & 0xFF00)   * (pdP->col_lv + 1)) >> 8) & 0xFF00) | 0xFF000000;
        
        oP->mtn_no = dst_col; 

        if (ewP != NULL)
        {
            oP->flg = 0x81;
            
            oP->lkwkp = (unsigned char*)ewP;
            oP->lkono = lnk_no;
            
            if (offP != NULL) 
            {
                *(NJS_POINT3*)&oP->lox = *offP;
            }
            else 
            {
                oP->lox = oP->loy = oP->loz = 0;
            }
        }
        else 
        {
            oP->flg = 1;
            
            oP->lkwkp = NULL;
            oP->lkono = lnk_no;
            
            *(NJS_POINT3*)&oP->px = *offP;
        }

        oP->mtx = (NJS_MATRIX*)oP->mtxbuf;
        
        *(NJS_POINT3*)&oP->xn = *dirP;
        
        njUnitVector((NJS_VECTOR*)&oP->xn);
    }

    return oP;
}

// 99.94% matching
void bhEff302(O_WRK* oP) 
{
    switch (oP->mode0) 
    {
    case 0:
    {
        E02_WORK* e02aP;     
        E02_WRK* e02bP;      
        EFF302PRM_WORK* prmP; 
        int i;               
        int* timP;          
        NJS_POINT3** bufPP;  
        float** spdPP;       
        NJS_POINT3* dirP;     
        int ax, ay, az;               
        int tmp;             
        int src, dst;              
        int cnt;            
        int* addP, *subP;          
        
        e02aP = (E02_WORK*)oP->exp0;
        e02bP = (E02_WRK*)oP->exp1;
        
        prmP = &Eff302Prm[oP->type];

        e02aP->stg_num = 0;
        e02aP->vtx_num = 0;
        
        e02aP->stg_stt = 0;
        
        e02aP->src_col = oP->mtn_attr;
        e02aP->dst_col = oP->mtn_no;

        e02aP->vtx_speed   = prmP->vtx_speed;
        e02aP->vtx_accel   = prmP->vtx_accel;
        e02aP->vtx_gravity = prmP->vtx_gravity;
        
        e02aP->stg_erase = prmP->stg_erase;
        
        e02aP->pos_rand = prmP->pos_rand;
        e02aP->spd_rand = prmP->spd_rand;

        e02aP->pos_bak = *(NJS_POINT3*)&oP->px;

        e02aP->scale = prmP->vtx_scale;
        
        e02aP->scl_add_1st = prmP->vtx_scale;
        e02aP->scl_add_2nd = -0.5f * prmP->vtx_scale;

        timP = e02aP->stg_tim;
        
        bufPP = e02aP->stg_buf;
        spdPP = e02aP->stg_spd;

        for (i = 0; i < 6; i++, timP++, bufPP++, spdPP++) 
        {
            *timP = -prmP->stg_timer[i];
            
            *bufPP = &e02bP->vtx_pos[i * 16];
            *spdPP = &e02aP->vtx_spd[i * 16];
            
            if (*timP > 0)
            {
                e02aP->stg_stt = i + 1;
            }
        }

        dirP = e02aP->vtx_dir;
        
        for (i = 16; i > 0; i--, dirP++) 
        {
            ax = 182.04445f * (prmP->ang_rand * ((-rand() / -2.1474836E9f) - 0.5f)); 
            ay = 182.04445f * (prmP->ang_rand * ((-rand() / -2.1474836E9f) - 0.5f)); 
            az = 182.04445f * (prmP->ang_rand * ((-rand() / -2.1474836E9f) - 0.5f)); 

            *dirP = *(NJS_POINT3*)&oP->xn;

            njUnitMatrix(lcmat);
            
            njRotateXYZ(lcmat, ax, ay, az);
            njCalcVector(lcmat, dirP, dirP);
        }

        cnt = e02aP->stg_erase;
        
        src = e02aP->src_col;
        dst = e02aP->dst_col;
        
        addP = &e02aP->col_add;
        subP = &e02aP->col_sub;

        tmp = ((dst & 0xFF) - (src & 0xFF)) / cnt;
        
        if (tmp < 0) 
        {
            *subP = (~tmp + 1) & 0xFF;
        }
        else 
        {
            *addP = tmp        & 0xFF;
        }

        tmp = ((dst & 0xFF00) - (src & 0xFF00)) / cnt;
        
        if (tmp < 0) 
        {
            *subP |= (~tmp + 256) & 0xFF00;
        }
        else 
        {
            *addP |= tmp          & 0xFF00;
        }

        tmp = ((dst & 0xFF0000) - (src & 0xFF0000)) / cnt;
        
        if (tmp < 0) 
        {
            *subP |= (~tmp + 65536) & 0xFF0000;
        }
        else
        {
            *addP |= tmp            & 0xFF0000;
        }

        src >>= 16;
        dst >>= 16;

        tmp = ((dst & 0xFF00) - (src & 0xFF00)) / cnt;
        
        if (tmp < 0) 
        {
            *subP |= ((~tmp + 256) & 0xFF00) << 16;
        }
        else 
        {
            *addP |= (tmp          & 0xFF00) << 16;
        }

        oP->mode0++;
        break; 
    }
    case 1:
    {
        E02_WORK* e02aP;  
        int stg_no;      
        int* timP;       
        NJS_POINT3* grvP; 
        int i;            
        NJS_POINT3* posP; 
        float* spdP;      
        float b_spd, p_rnd, s_rnd;     
        int vtx_num, stg_vtx;      
        
        e02aP = (E02_WORK*)oP->exp0;

        stg_no = e02aP->stg_stt;
        
        timP = &e02aP->stg_tim[stg_no];
        grvP = &e02aP->stg_grv[stg_no];
    
        for (; stg_no < 6; stg_no++, timP++, grvP++) 
        {
            if (*timP >= 0)
            {
                if (*timP == 0)
                {
                    posP = e02aP->stg_buf[stg_no];
                    spdP = e02aP->stg_spd[stg_no];
                    
                    b_spd = e02aP->vtx_speed;
                    p_rnd = e02aP->pos_rand;
                    s_rnd = e02aP->spd_rand;
    
                    for (i = 16; i > 0; i--, posP++) 
                    {
                        *posP = *(NJS_POINT3*)&oP->px;
    
                        posP->x += p_rnd * ((-rand() / -2.1474836E9f) - 0.5f);
                        posP->y += p_rnd * ((-rand() / -2.1474836E9f) - 0.5f);
                        posP->z += p_rnd * ((-rand() / -2.1474836E9f) - 0.5f);
    
                        *spdP++ = b_spd - (s_rnd * (b_spd * ((-rand() / -2.1474836E9f) - 0.5f)));
                    }
    
                    e02aP->stg_num++;
                    e02aP->vtx_num += 16;
                    
                    e02aP->stg_col[stg_no] = e02aP->src_col;
                    e02aP->stg_scl[stg_no] = e02aP->scale;
                }
                else if (*timP < e02aP->stg_erase) 
                {
                    njAddVector(grvP, &e02aP->vtx_gravity);
    
                    e02aP->stg_col[stg_no] += e02aP->col_add;
                    e02aP->stg_col[stg_no] -= e02aP->col_sub;
    
                    if (*timP < (e02aP->stg_erase / 2)) 
                    {
                        e02aP->stg_scl[stg_no] += e02aP->scl_add_1st;
                    }
                    else 
                    {
                        e02aP->stg_scl[stg_no] += e02aP->scl_add_2nd;
                    }
                } 
                else if (*timP == e02aP->stg_erase)
                {
                    e02aP->stg_num--;
                    e02aP->vtx_num -= 16;
                    
                    e02aP->stg_stt = stg_no + 1;
                }
            }
            
            (*timP)++;
        }
    
        if (e02aP->stg_num > 0) 
        {
            NJS_POINT3* posP, *grvP, *dirP;
            float* spdP;      
            int stg_stt;     
            NJS_POINT3* dP;  
            float spd;       

            stg_stt = e02aP->stg_stt;
            
            posP = e02aP->stg_buf[stg_stt];
            spdP = e02aP->stg_spd[stg_stt];
            
            grvP = &e02aP->stg_grv[stg_stt]; 
            
            dirP = e02aP->vtx_dir;
    
            if (e02aP->vtx_num != 0) 
            {
                e02aP->vtx_bufP = posP;
    
                sys->ef_fnc[sys->ef_fncn++] = oP;
    
                for (vtx_num = e02aP->vtx_num - 1; vtx_num >= 0; grvP++) 
                {
                    for (stg_vtx = 16; stg_vtx > 0; stg_vtx--) 
                    {
                        spd = *spdP;
    
                        dP = &dirP[vtx_num & 0xF];
                        
                        posP->x += dP->x * spd;
                        posP->y += dP->y * spd;
                        posP->z += dP->z * spd;
    
                        njAddVector(posP, grvP);
    
                        vtx_num--;
                        
                        posP++;
    
                        *spdP++ = spd + e02aP->vtx_accel;
                    }
                }
            }
        } 
        else 
        {
            *(int*)oP->exp0 = *(int*)oP->exp1 = 0;
            
            oP->flg = 0;
        }
        
        break;
    }
    }
}

// 100% matching!
static void bhEff_PtclSpriteDrawB(O_WRK* oP)
{
    E02_WORK* e02aP;  
    int stg_no, stg_num;       
    float scl;        
    NJS_POINT3* bufP; 

    e02aP = (E02_WORK*)oP->exp0;
    
    njGetSystemAttr((NJS_SYS_ATTR*)&e02aP->atr_bak);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njTextureFilterMode(0);
    
    njSetMatrix(NULL, cam.mtx);
    njSetTexture(oP->txp[0]);
    
    if ((e02aP->stg_num != 0) && (e02aP->stg_num != 0)) 
    {
        // empty
    } 
    
    stg_num = e02aP->stg_num;
    stg_no  = e02aP->stg_stt;
    
    for (; stg_num > 0; stg_num--, stg_no++)
    {
        scl  = e02aP->stg_scl[stg_no];
        bufP = e02aP->stg_buf[stg_no];
        
        njPtclSpriteStart(oP->tex_id + (e02aP->stg_tim[stg_no] & 3), e02aP->stg_col[stg_no], 1);
        
        njPtclDrawSprite(&bufP[0],  4, scl, scl);
        njPtclDrawSprite(&bufP[4],  4, scl, scl);
        njPtclDrawSprite(&bufP[8],  4, scl, scl);
        njPtclDrawSprite(&bufP[12], 4, scl, scl);
        
        njPtclSpriteEnd();
    } 
    
    njSetSystemAttr((NJS_SYS_ATTR*)&e02aP->atr_bak);
}

// 100% matching!
static void bhEff_PtclLineDraw(O_WRK* oP)
{
    E02_WORK* e02aP;     
    int stg_num, stg_no;       
    NJS_POINT3COL* p3cP; 
    int* colP;          
    int col;             
    int i;              
    float* spdP;        
    NJS_POINT3* dirP, *p3P, *grvP;    
    NJS_POINT3 vct;      
    float spd, scl;         
    float* pntP;        
    
    e02aP = (E02_WORK*)oP->exp0;
    
    njSetMatrix(NULL, cam.mtx);

    stg_num = e02aP->stg_num;
    stg_no  = e02aP->stg_stt;

    p3cP = &e02aP->lne_p3c;

    e02aP->lne_p3c.p   = e02aP->lne_pnt;
    e02aP->lne_p3c.col = e02aP->lne_col;
    e02aP->lne_p3c.tex = NULL;
    e02aP->lne_p3c.num = 1;

    for (; stg_num > 0; stg_no++, stg_num--) 
    {
        col = e02aP->stg_col[stg_no];
        
        dirP = &e02aP->vtx_dir[15];
        grvP = &e02aP->stg_grv[stg_no];

        e02aP->lne_col[0].color = col & 0xFFFFFF;
        e02aP->lne_col[1].color = col;

        spdP = e02aP->stg_spd[stg_no];
        p3P  = e02aP->stg_buf[stg_no];

        for (i = 0; i < 16; i++) 
        {
            spd = *spdP;

            scl = spd * e02aP->scale;
             
            pntP = (float*)e02aP->lne_pnt;
            
            scl = scl * 100.0f;
            
            *pntP++ = p3P->x;
            *pntP++ = p3P->y;
            *pntP++ = p3P->z;

            vct.x = dirP->x * spd;
            vct.y = dirP->y * spd;
            vct.z = dirP->z * spd;

            njAddVector(&vct, grvP);

            *pntP++ = p3P->x + (vct.x * scl);
            *pntP++ = p3P->y + (vct.y * scl);
            *pntP++ = p3P->z + (vct.z * scl);

            njDrawLine3D(p3cP, p3cP->num, 0x40);

            p3P++;
            spdP++;
            dirP--;
        }
    } 
}

// 99.66% matching
void bhEff303(O_WRK* oP)
{
    ANM_WORK* anmP; 
    DSP_WRK* dspP;  
    const PRM_WORK* prmP;
	static const PRM_WORK PrmTbl[8] =
	{
		{ 3, 0xC0C0C0C0, 0.01f,  -1 },
		{ 4, 0xC0C0C0C0, 0.02f,  -1 },
		{ 5, 0xC0C0C0C0, 0.04f,  -1 },
		{ 3, 0xC0C0C0C0, 0.08f,  -1 },
		{ 3, 0xC0F0F0F0, 0.75f, 228 },
		{ 4, 0xC0808080, 0.75f, 198 },
		{ 5, 0xC0C0C0C0, 0.75f, 208 },
		{ 3, 0xC0808080, 0.75f, 160 }
	};

    anmP = (ANM_WORK*)((char*)oP + 1028);
    dspP =  (DSP_WRK*)((char*)oP + 1060);

    switch (oP->mode0)
    {                              
    case 0: 
        prmP = &PrmTbl[oP->type];
        
        sys->bl_ct = (sys->bl_ct + 1) & 0x1FF;
        
        oP->py += 0.001f * sys->bl_ct;
        
        oP->tex_id = 5;
        
        oP->flg = 0x200001;
        
        oP->bl_src = 8;
        oP->bl_dst = 6;
        
        oP->sx = oP->sy = oP->sz = 0;
        
        oP->spd = prmP->speed;
        
        oP->frm_no   = prmP->time;
        oP->frm_mode = 16;
        
        oP->sxb *= 2.0f;
        oP->szb *= 2.0f;
        
        oP->ani_ct = oP->mdlver;
        
        oP->tvp = dspP->VtxBuf;
        
        oP->ax += 16384;
        
        anmP->uv_tabP = (UV_WORK*)Tex5uv;
        
        anmP->anm_no = prmP->anm_no;
        
        ryRapAnmColSet(anmP, prmP->color, prmP->color & 0xFFFFFF, oP->frm_mode);
        ryRapDspSet((NJS_POINT3*)&oP->px, dspP, 1.0f);
        ryRapTexAnm(anmP, dspP, FALSE);
        
        oP->mode0++;
        break;
    case 1:
        if ((oP->sxb - oP->sx) < 0.01f) 
        {
            oP->mode0++;
        } 
        else 
        {
            oP->sx += oP->spd * (oP->sxb - oP->sx);
            oP->sy += oP->spd * (oP->szb - oP->sy);
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    case 2:
        sys->ef_trs[sys->ef_trsn++] = oP;
        
        if ((oP->frm_no > 0) && (--oP->frm_no == 0))
        {
            oP->mode0++;
        }
        
        break;
    case 3:
        if ((int)--oP->frm_mode >= 0) 
        {
            anmP->color += anmP->col_add;
            anmP->color -= anmP->col_sub;
            
            ryRapTexAnm(anmP, dspP, FALSE);
            
            sys->ef_trs[sys->ef_trsn++] = oP;
        }
        else 
        {
            oP->flg = 0;
        }
        
        break;
    }
}

// 100% matching!
static int bhCheckCamWall2D(NJS_POINT3* srcP, NJS_POINT3* vctP, NJS_POINT3* rtnP, float rng_x, float rng_y)
{
    NJS_LINE lne;
	static const NJS_PLANE pln = 
	{
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};
    
    njCalcPoint(cam.mtx,  srcP, (NJS_POINT3*)&lne.px);
    njCalcVector(cam.mtx, vctP, (NJS_VECTOR*)&lne.vx);
    
    if ((njInnerProduct((NJS_VECTOR*)&pln.vx, (NJS_VECTOR*)&lne.vx) < 0.0f) && (!njDistanceL2PL(&lne, &pln, rtnP)))
    {
        if (((-rng_x < rtnP->x) && (rtnP->x < rng_x)) && ((-rng_y < rtnP->y) && (rtnP->y < rng_y)))
        {
            rtnP->z = njDistanceP2P((NJS_POINT3*)&lne.px, rtnP);
            
            rtnP->x = 320.0f + (320.0f * (rtnP->x / rng_x));
            rtnP->y = 240.0f + (240.0f * (rtnP->y / rng_y));
            
            return 1;
        }
    }
    
    return 0;
}

// 100% matching!
O_WRK* rySetShadow(BH_PWORK* ewP, int obj0, int obj1, int obj2, float off_a, float off_b)
{
	O_WRK* oP;
    O_WORK* owP;
            
    oP = AllocOworkOne();
    
    if (oP != NULL) 
    {
        oP->flg = 0x8240001;
        
        oP->id   = 304;
        oP->type = 0;
        
        oP->tex_id = -1;
        
        oP->mdlver = 0;
        
        oP->sx = oP->sy = oP->sz = 1.0f;
        oP->ax = oP->ay = oP->az = 0;
        oP->px = oP->py = oP->pz = 0;
        
        oP->mlwP = &sys->efm[1];
        
        oP->lkwkp = (unsigned char*)ewP;
        oP->lkono = 0;
        
        oP->mtx = (NJS_MATRIX*)oP->mtxbuf;
        
        oP->xn = off_a;
        oP->zn = off_b;
        
        owP = ewP->mlwP->owP;
        
        oP->ct0 = (int)&owP[obj0].mtx[12]; // this doesn't look too healthy
        oP->ct1 = (int)&owP[obj1].mtx[12];
        oP->ct2 = (int)&owP[obj2].mtx[12];
    }
    
    return oP;
}

// 100% matching!
void bhEff304(O_WRK* oP) 
{
    NJS_POINT3 pp;   
    NJS_POINT3* paP, *pbP; 
    float ra, rb;        
    NJS_POINT3* p0P, *p1P; 
    float tmp;      
    NJS_POINT3* p2P; 
    //float tmp; // needs using
    NJS_VECTOR vct;  
    NJS_POINT3 pos;  
    NJS_POINT3 dlt; 
    BH_PWORK* ewP;   

    p0P = (NJS_POINT3*)oP->ct0;
    p1P = (NJS_POINT3*)oP->ct1;
    
    pp.x = (p0P->x + p1P->x) * 0.5f;
    pp.y = (p0P->y + p1P->y) * 0.5f;
    pp.z = (p0P->z + p1P->z) * 0.5f;
    
    p2P = (NJS_POINT3*)oP->ct2;

    ra =   p1P->x - p0P->x;
    ra *=  p1P->x - p0P->x;
    ra += (p1P->z - p0P->z) * (p1P->z - p0P->z); 
    
    rb =  (p2P->x - pp.x) * (p2P->x - pp.x);
    rb += (p2P->z - pp.z) * (p2P->z - pp.z);

    if (rb > ra) 
    {
        tmp = ra;
        
        ra = rb;
        rb = tmp;
        
        p1P = &pp;
        p0P = p2P;
    }

    ra = njSqrt(ra);
    rb = njSqrt(rb);

    vct = *p0P;
    
    njSubVector(&vct, p1P);
    
    oP->ay = -(int)(10430.381f * atan2f(vct.z, vct.x));

    oP->sx = (oP->sx + (ra + oP->xn)) * 0.5f;
    oP->sz = (oP->sz + (rb + oP->zn)) * 0.5f;

    pos = *p0P;
    
    dlt.x = (pos.x + p1P->x) * 0.5f;
    dlt.y = (pos.y + p1P->y) * 0.5f;
    dlt.z = (pos.z + p1P->z) * 0.5f;

    if (njDistanceP2P(&dlt, (NJS_POINT3*)&oP->px) < rb)
    {
        oP->px = (oP->px + dlt.x) * 0.5f;
        oP->py = (oP->py + dlt.y) * 0.5f;
        oP->pz = (oP->pz + dlt.z) * 0.5f;
    }
    else
    {
        *(NJS_POINT3*)&oP->px = dlt;
    }

    if (oP->type == 0) 
    {
        oP->py = bhGetGroundPosition((NJS_POINT3*)&oP->px);
    }

    ewP = (BH_PWORK*)oP->lkwkp;
    
    if (!(ewP->flg & 0x1)) 
    {
        oP->flg = 0;
    }
    else if ((((ewP->stflg & 0x8)) || ((ewP->stflg & 0x1000000))) || ((ewP->mdflg & 0x1)))
    {
        oP->flg |= 0x1000000;
    }
    else
    {
        oP->flg &= ~0x1000000;
        
        sys->ef_mdf[sys->ef_mdfn++] = oP;
    }
}

// 100% matching!
void bhEff305(O_WRK* oP) 
{
	static const Eff305PRM_WORK Eff305Prm[4] = 
	{
		{ 0x70F0C080, 0.1f, -0.01f, 16, 1.5f, 1.5f, 3.0f },
		{ 0x70F0C080, 0.1f, -0.01f, 20, 1.5f, 2.0f, 3.0f },
		{ 0x70F0C080, 0.1f, -0.01f, 24, 1.5f, 2.5f, 3.5f },
		{ 0x70F0C080, 0.1f, -0.01f, 28, 1.5f, 3.0f, 3.5f }
	};
	static const UV_WORK Tex2uv[8] = 
	{
		{ 0.12500000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.25000000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.37500000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.50000000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.62500000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.75000000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.87500000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.87500000f, 0.00000000f, 0.12109375f, 0.12109375f } 
	};

    switch (oP->mode0)
    {                     
    case 0:
    {
        const Eff305PRM_WORK* prmP;
        NJS_POINT3 vct;       
        float dst;           
        int ay, ax;              
        
        oP->flg = 0x4300001;
        
        oP->tex_id = 2;
        
        oP->ani_ct = 0;
        
        oP->bl_src = 8;
        oP->bl_dst = 10;
        
        prmP = &Eff305Prm[oP->type];
        
        oP->spd = prmP->speed;
        
        oP->shp_ct = prmP->accel;
        
        oP->ct0 = prmP->time;
        oP->ct1 = prmP->color;
        oP->ct2 = (prmP->color / oP->ct0) & 0xFF000000;
        oP->ct3 = 0;
        
        oP->sx = oP->sy = prmP->src_scl;
        
        oP->sx *= oP->sxb;
        oP->sy *= oP->syb;
        
        oP->lox = oP->loy = prmP->dst_scl;
        
        oP->lox = ((oP->lox * oP->sxb) - oP->sx) / oP->ct0;
        oP->loy = ((oP->loy * oP->syb) - oP->sy) / oP->ct0;
        
        oP->xn = oP->yn = oP->zn = 0;
        
        oP->gpx = oP->gpy = 0.1f * sys->winds;
        
        dst = prmP->offset;
        
        vct = *(NJS_POINT3*)&cam.wpx;
        
        njSubVector(&vct, (NJS_VECTOR*)&oP->px);
        
        njUnitVector(&vct);
        
        oP->px += vct.x * dst;
        oP->py += vct.y * dst;
        oP->pz += vct.z * dst;
        
        ay = oP->ay;
        ax = oP->ax;
        
        oP->aox = -njSin(ay) * njCos(ax);
        oP->aoy =  njSin(ax);
        oP->aoz = -njCos(ay) * njCos(ax);
        
        oP->mode0++;
    }
    case 1:
    {
        float spd;        
        int ay;           
        float sp;          
        const UV_WORK* uvP;        
        NJS_TEXTURE_VTX* tvP; 
        unsigned int col;    
        
        if (oP->ct0-- <= 0) 
        {
            oP->flg = 0;
            break;
        }
        
        spd = oP->spd;
        
        oP->px += oP->aox * spd;
        oP->py += oP->aoy * spd;
        oP->pz += oP->aoz * spd;
        
        njAddVector((NJS_VECTOR*)&oP->px, (NJS_VECTOR*)&oP->xn);
        
        oP->yn -= -0.0054444447f;
        
        spd += oP->shp_ct;
        
        if (spd > 0)
        {
            oP->spd = spd; 
        }
        
        sp = oP->gpx;
        
        ay = sys->windr;
        
        oP->px += sp * -njSin(ay);
        oP->pz += sp * -njCos(ay);
        
        oP->gpx += oP->gpy;
        
        col = oP->ct1;
        
        uvP = &Tex2uv[oP->ct3];
        
        oP->tv[0].u   = uvP->u;
        oP->tv[0].v   = uvP->v;
        oP->tv[0].col = col;
        
        oP->tv[1].u   = uvP->u + uvP->xs;
        oP->tv[1].v   = uvP->v;
        oP->tv[1].col = col;
        
        oP->tv[2].u   = uvP->u;
        oP->tv[2].v   = uvP->v + uvP->ys;
        oP->tv[2].col = col;
        
        oP->tv[3].u   = uvP->u + uvP->xs;
        oP->tv[3].v   = uvP->v + uvP->ys;
        oP->tv[3].col = col;
        
        oP->ct1 -= oP->ct2;
        
        oP->sx += oP->lox;
        oP->sy += oP->loy;
        
        if (oP->ct3 < 7) 
        {
            oP->ct3++;
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    }
    }
}

// 100% matching!
void bhEff306(O_WRK* oP)
{
	static const int ColTbl[4] = 
	{
		0xFFF0F0F0, 0xFF808080, 0xFFD0D0D0, 0xFFC0C0C0
	};
	static const UV_WORK Tex8uv[10] = 
	{
		{    0.0f,    0.0f, 0.18359375f, 0.18359375f },
		{ 0.1875f,    0.0f, 0.18359375f, 0.18359375f },
		{  0.375f,    0.0f, 0.18359375f, 0.18359375f },
		{ 0.5625f,    0.0f, 0.18359375f, 0.18359375f },
		{   0.75f,    0.0f, 0.18359375f, 0.18359375f },
		{    0.0f, 0.1875f, 0.18359375f, 0.18359375f },
		{ 0.1875f, 0.1875f, 0.18359375f, 0.18359375f },
		{  0.375f, 0.1875f, 0.18359375f, 0.18359375f },
		{ 0.5625f, 0.1875f, 0.18359375f, 0.18359375f },
		{   0.75f, 0.1875f, 0.18359375f, 0.18359375f }
	};
	static const UV_WORK Tex9uv[10] = 
	{
		{  0.0f,  0.0f, 0.24609375f, 0.24609375f },
		{ 0.25f,  0.0f, 0.24609375f, 0.24609375f },
		{  0.5f,  0.0f, 0.24609375f, 0.24609375f },
		{ 0.75f,  0.0f, 0.24609375f, 0.24609375f },
		{  0.0f, 0.25f, 0.24609375f, 0.24609375f },
		{ 0.25f, 0.25f, 0.24609375f, 0.24609375f },
		{  0.5f, 0.25f, 0.24609375f, 0.24609375f },
		{ 0.75f, 0.25f, 0.24609375f, 0.24609375f },
		{  0.0f,  0.5f, 0.24609375f, 0.24609375f },
		{ 0.25f,  0.5f, 0.24609375f, 0.24609375f }
	};
	static UV_WORK* TexTab[10] = 
	{
		NULL, NULL, NULL, NULL, 
		NULL, NULL, NULL, NULL, 
		Tex8uv, Tex9uv
	};
	static const Eff306PRM_WORK Eff306Prm[8] = 
	{
		{ 8, 0,  4,  32, 3.0f, 0.2f, 1.5f },
		{ 8, 0,  4,  48, 3.0f, 0.2f, 1.5f },
		{ 8, 2,  8,  64, 3.0f, 0.3f, 2.0f },
		{ 8, 2,  8,  80, 3.0f, 0.3f, 2.0f },
		{ 8, 1, 16,  96, 3.0f, 0.5f, 2.5f },
		{ 8, 1, 16, 112, 3.0f, 0.5f, 2.5f },
		{ 8, 0,  4,  48, 3.0f, 0.2f, 1.0f },
		{ 8, 0,  4,  32, 3.0f, 0.2f, 1.0f }
	};
    const Eff306PRM_WORK* prmP; 
    float dst_scl;        
    float rnd;            
    NJS_POINT3 vct;       
    float dst;           
    const UV_WORK* uvP;       
    NJS_TEXTURE_VTX* tvP; 
    unsigned int col;     

    switch (oP->mode0) 
    {                            
    case 0:
        oP->flg = 0x4300001;
        
        oP->ani_ct = 0;
        
        oP->bl_src = 8;
        oP->bl_dst = 10;
        
        if (oP->mdlver != 0) 
        {
            oP->type = (int)(255.0f * (-rand() / -2.1474836E9f)) & 7;
        }
        
        prmP = &Eff306Prm[oP->type];
        
        dst_scl = prmP->dst_scl;
        
        oP->tex_id = prmP->tex_id;
        
        oP->exp0 = (unsigned char*)TexTab[oP->tex_id];
        
        oP->ct0 = oP->mtn_no = prmP->time0;
        oP->ct1 = prmP->wait;
        oP->ct2 = prmP->time1;
        
        oP->sx = oP->sy = oP->sz = oP->sxb = prmP->src_scl;
        
        oP->syb = (dst_scl - prmP->src_scl) / prmP->time0;
        
        oP->spd = prmP->offset;
        
        oP->axp = 0;
        oP->ayp = (int)(5461.0f * (-rand() / -2.1474836E9f)) + 10922;
        
        oP->ct3 = oP->ayp & 7;
        
        oP->mode0++;
    case 1:
    case 3:
        if (oP->ct1 > 0) 
        {
            oP->ct1--;
        } 
        else
        {
            oP->sxb += oP->syb;
            
            njCalcPoint(&((O_WRK*)oP->lkwkp)->mlwP->owP[oP->lkono].mtx, (NJS_POINT3*)&oP->lox, (NJS_POINT3*)&oP->px);
            
            sys->ef_trs[sys->ef_trsn++] = oP;
            
            if (oP->ct0-- < 0) 
            {
                oP->mode0++;
            }
        }
        
        break;
    case 2:
        njCalcPoint(&((O_WRK*)oP->lkwkp)->mlwP->owP[oP->lkono].mtx, (NJS_POINT3*)&oP->lox, (NJS_POINT3*)&oP->px);
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        
        if (oP->ct2-- < 0) 
        {
            oP->ct0 = oP->mtn_no;
            
            oP->syb *= -1.0f;
            
            oP->mode0++;
        }
        
        break;
    case 4:
        oP->flg = 0;
        break;
    }
    
    if (oP->mode0 != 4) 
    {
        rnd = 0.1f * njSin(oP->axp += oP->ayp);
        
        oP->sx = oP->sxb * (1.0f + rnd);
        oP->sy = oP->sxb * (1.0f - rnd);
        
        dst = oP->spd;
        
        vct = *(NJS_POINT3*)&cam.wpx;
        
        njSubVector(&vct, (NJS_VECTOR*)&oP->px);
        
        njUnitVector(&vct);
        
        oP->px += vct.x * dst;
        oP->py += vct.y * dst;
        oP->pz += vct.z * dst;
        
        uvP = (UV_WORK*)oP->exp0 + oP->ct3;
        
        col = ColTbl[(oP->axp >> 13) & 3];
    
        tvP = oP->tv;
        
        tvP->u   = uvP->u;
        tvP->v   = uvP->v;
        tvP->col = col;

        tvP++;
        
        tvP->u   = uvP->u + uvP->xs;
        tvP->v   = uvP->v;
        tvP->col = col;

        tvP++;
        
        tvP->u   = uvP->u;
        tvP->v   = uvP->v + uvP->ys;
        tvP->col = col;

        tvP++;
        
        tvP->u   = uvP->u + uvP->xs;
        tvP->v   = uvP->v + uvP->ys;
        tvP->col = col;
        
        if (++oP->ct3 > 9) 
        {
            oP->ct3 -= 9;
        }
    }
}

// 100% matching!
OR_WORK* bhSetRapEff(int eff_no, void* datP, int lng_siz)
{
    OR_WORK* orP;
    
    if ((orP = (OR_WORK*)AllocOworkOne()) != NULL) 
    {
        orP->flg = 1;
        
        orP->id = eff_no;
        
        if (datP != NULL) 
        {
            njMemCopy4(&orP->free4, datP, lng_siz);
        }
    }
    
    return orP;
}

// 100% matching!
void bhEff307(OR_WORK* orP) 
{
    R07_WORK* r07P;       

    r07P = (R07_WORK*)&orP->free4;

    switch (r07P->mode0) 
    {
    case 0:
        orP->func = (void*)bhEff307Drw;
        
        r07P->vtx_top = 0;
        
        r07P->spl_frm = 0;
        r07P->tex_frm = 1.0f / r07P->eff_prm.tim;
        
        r07P->mode0++;
        
        r07P->wnd_acl = 0.01f * sys->winds;
    case 1:
        if ((r07P->eff_prm.tim-- != 0) && (r07P->vtx_num < 17)) 
        {
            int vtx; 
            
            vtx = r07P->vtx_num;
            
            njCalcPoint(r07P->eff_prm.mtxP, &r07P->eff_prm.src, &r07P->VtxBufS[vtx]);
            njCalcPoint(r07P->eff_prm.mtxP, &r07P->eff_prm.dst, &r07P->VtxBufD[vtx]);
            
            r07P->VtxDir[vtx] = r07P->VtxBufD[vtx];
            
            njSubVector(&r07P->VtxDir[vtx], &r07P->VtxBufS[vtx]);

            njUnitVector(&r07P->VtxDir[vtx]);
            
            r07P->VtxAlp[vtx] = (unsigned int)r07P->eff_prm.col >> 24;
            
            r07P->VtxDir[vtx].x *= 0.1f;
            r07P->VtxDir[vtx].y *= 0.1f;
            r07P->VtxDir[vtx].z *= 0.1f;
            
            r07P->VtxBufS[vtx + 1] = r07P->VtxBufS[vtx];
            r07P->VtxBufD[vtx + 1] = r07P->VtxBufD[vtx];
            
            r07P->WndSpd[vtx] = 0;
            
            r07P->vtx_num = vtx + 1;
            break;
        }
        
        r07P->mode0++;
        break;
    case 2:
        break;
    }

    if (r07P->vtx_num >= 2) 
    {
        int idx;          
        NJS_VECTOR* vctP; 
        NJS_POINT3 wnd;   
        int ay;          
        float sp;  
        
        idx = r07P->vtx_top;

        vctP = &r07P->VtxDir[idx];
        
        for (; idx <= r07P->vtx_num; idx++, vctP++) 
        {
            njAddVector(&r07P->VtxBufS[idx], vctP);
            njAddVector(&r07P->VtxBufS[idx], vctP);
            njAddVector(&r07P->VtxBufD[idx], vctP);

            vctP->x *= 0.98f;
            vctP->y *= 0.98f;
            vctP->z *= 0.98f;
            
            sp = r07P->WndSpd[idx];
            
            ay = sys->windr;

            wnd.x = sp * -njSin(ay);
            wnd.y = 0;
            wnd.z = sp * -njCos(ay);

            r07P->WndSpd[idx] = sp + r07P->wnd_acl;

            njAddVector(&r07P->VtxBufS[idx], &wnd);
            njAddVector(&r07P->VtxBufD[idx], &wnd);
        }
    }

    {
    int idx;
    int flg;   
    int* alpP, *colP; 
        
    flg = 0;
        
    alpP = r07P->VtxAlp; 
    colP = r07P->VtxCol;
        
    for (idx = 0; idx <= r07P->vtx_num; idx++, alpP++, colP++) 
    {
        if ((idx & 0x1)) 
        {
            *alpP -= 32;
        } 
        else
        {
            *alpP -= 16;
        }
    
        if (*alpP < 0) 
        {
            *alpP = 0;
        }
        else 
        {
            flg = -1;
        }
    
        *colP = (r07P->eff_prm.col & 0xFFFFFF) | (*alpP << 24);
    }

    if (r07P->vtx_num >= 3) 
    {
        if (flg == 0) 
        {
            orP->flg = 0;
        } 
        else 
        {
            sys->ef_fnc[sys->ef_fncn++] = (O_WRK*)orP;
        }
    }
    }
}

// 100% matching!
void bhEff307Drw(OR_WORK* orP) 
{
    R07_WORK* r07P; 
    int vtx;       
    int tgr;        
    int idx;       
    float frm;    
    float tu_l, tu_r;     
    int col;       
     
    r07P = (R07_WORK*)orP->free4;
    
    vtx = r07P->vtx_num;
    
    njTextureFilterMode(1);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 10);
    
    njFogDisable();

    if (r07P->eff_prm.texP != NULL) 
    {
        njSetTexture(r07P->eff_prm.texP);
        njSetTextureNum(r07P->eff_prm.tex_id);
    }

    frm = 0;
    
    tgr = 0;
    idx = 0;
    
    njOverhauserSpline((float*)&r07P->VtxBufS[0].x, (float*)&r07P->poly[0].x, NULL, 0);
    njOverhauserSpline((float*)&r07P->VtxBufD[0].x, (float*)&r07P->poly[1].x, NULL, 0);

    while (TRUE)
    {
        frm += r07P->eff_prm.frm_inc;
        
        if (frm > 1.0f) 
        {
            frm -= 1.0f;
            
            idx++;
        }

        if (idx > (vtx - 3))
        {
            break;
        }

        tgr ^= 2;

        njOverhauserSpline((float*)&r07P->VtxBufS[idx].x, (float*)&r07P->poly[tgr].x,     NULL, frm);
        njOverhauserSpline((float*)&r07P->VtxBufD[idx].x, (float*)&r07P->poly[tgr + 1].x, NULL, frm);

        if (r07P->eff_prm.texP != NULL)
        {
            if ((tgr & 0x2)) 
            {
                tu_l = frm;
                tu_r = frm - r07P->eff_prm.frm_inc;
            } 
            else 
            {
                tu_r = frm;
                tu_l = frm - r07P->eff_prm.frm_inc;
            }

            col = ryLinerColor(r07P->VtxCol[idx], r07P->VtxCol[idx + 1], tu_r);
            
            r07P->poly[0].col = r07P->poly[1].col = col;

            col = ryLinerColor(r07P->VtxCol[idx], r07P->VtxCol[idx + 1], tu_l);
            
            r07P->poly[2].col = r07P->poly[3].col = col;

            r07P->poly[0].u = tu_l;
            r07P->poly[0].v = 0;
            
            r07P->poly[1].u = tu_l;
            r07P->poly[1].v = 1.0f;

            r07P->poly[2].u = tu_r;
            r07P->poly[2].v = 0;
            
            r07P->poly[3].u = tu_r;
            r07P->poly[3].v = 1.0f;

            njDrawTexture3DEx(r07P->poly, 4, 1);
        } 
        else
        {
            col = ryLinerColor(r07P->VtxCol[idx], r07P->VtxCol[idx + 1], frm);
            
            npDrawPlane((NJS_POINT3*)&r07P->poly[0].x, (NJS_POINT3*)&r07P->poly[1].x, (NJS_POINT3*)&r07P->poly[3].x, (NJS_POINT3*)&r07P->poly[2].x, col);
        }
    }
    
    njFogEnable();
}

// 100% matching!
void bhSetEffGunSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no)
{
    OR_WORK* orP;
    PMB_WORK* pmbP;
	static const Eff308PRM_WORK Eff308Prm[4] = 
	{
		{  8,                0.5f, 0.9800000190734863f, 1.0f,  5, 55.0f, 0.800000011920929f, 4, -0.03266666829586029f },
		{ 10, 0.6000000238418579f, 0.9800000190734863f, 2.0f,  7, 50.0f, 0.800000011920929f, 4, -0.03266666829586029f },
		{ 12,  0.699999988079071f, 0.9800000190734863f, 3.0f,  9, 45.0f, 0.800000011920929f, 4, -0.03266666829586029f },
		{ 12,                1.0f, 0.9800000190734863f, 3.0f, 12, 20.0f, 0.800000011920929f, 4, -0.03266666829586029f }
	};
    
    orP = bhSetRapEff(308, (void*)&Eff308Prm[typ_no], 9);
    
    if (orP != NULL) 
    {
        pmbP = (PMB_WORK*)((char*)orP + 180);
        
        pmbP->vtx_pos = *posP;
        pmbP->vtx_dir = *dirP;
        
        pmbP->col_src = src_col;
        pmbP->col_dst = dst_col;
        
        pmbP->gnd_hgh = posP->y - 100.0f;
    }
}

// 100% matching!
void bhSetEffSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no)
{
    OR_WORK* orP;
    PMB_WORK* pmbP;
    LGT_WORK* lP;
	static const Eff308PRM_WORK Eff308Prm[2] = 
	{
		{ 16,  1.0f, 0.9800000190734863f, 4.0f, 16, 120.0f, 1.899999976158142f, 16, -0.09800000488758087f },
		{ 16, 0.75f, 0.9800000190734863f, 4.0f, 16, 180.0f, 1.899999976158142f, 16, -0.09800000488758087f }
	};
    
    orP = bhSetRapEff(308, (void*)&Eff308Prm[typ_no], 9);
    
    if (orP != NULL) 
    {
        pmbP = (PMB_WORK*)orP->free4 + 1;

        pmbP->vtx_pos = *posP;
        pmbP->vtx_dir = *dirP;
        
        pmbP->col_src = src_col;
        pmbP->col_dst = dst_col;
        
        pmbP->gnd_hgh = bhGetGroundPosition(posP);
        
        lP = &rom->lgtp[2];
        
        if (!(lP->flg & 0x1)) 
        {
            lP->ct0 = 0;
            
            lP->lkono = 0;
            
            lP->vx = lP->vy = lP->vz = 0;
        }
        
        lP->lkono++;
        
        lP->flg |= 0x3;
        
        lP->type = 13;
        
        lP->aspd = 16;
        
        lP->lkflg = 0;
        lP->lsrc  = 4;
        
        lP->nr = 15.0f;
        lP->fr = 30.0f;
        
        *(NJS_POINT3*)&lP->vx = *dirP;
        *(NJS_POINT3*)&lP->px = *posP;
        
        lP->r = 3.0f;
        lP->g = 1.8f;
        lP->b = 0.7f;
    }
}

// 99.95% matching
void bhEff308(OR_WORK* orP) 
{
    R08_WORK* r08P;     
    PMB_WORK* pmbP;     
    
    r08P = (R08_WORK*)orP->free4;
    pmbP = &r08P->prm_b;
    
    switch (r08P->mode) 
    {
    case 0:
    {
        NJS_POINT3* dirP; 
        int ax, ay;         
        int i; // modified DWARF position 
        float sp;         
        
        njUnitVector(&pmbP->vtx_dir);
        
        orP->func = (void*)bhEff308Drw;
        
        dirP = r08P->VtxDir;
        
        for (i = r08P->prm_a.vtx_num; i > 0; i--, dirP++) 
        {
            ax = 182.04445f * (r08P->prm_a.ang_rand * ((-rand() / -2147483648.0f) - 0.5f));
            ay = 182.04445f * (r08P->prm_a.ang_rand * ((-rand() / -2147483648.0f) - 0.5f));
            
            sp = r08P->prm_a.speed + (r08P->prm_a.spd_rand * ((-rand() / -2147483648.0f) - 0.5f));
    
            njUnitMatrix(lcmat);
            
            njRotateY(lcmat, ay);
            njRotateX(lcmat, ax);
            
            njCalcVector(lcmat, &pmbP->vtx_dir, dirP);
    
            dirP->x *= sp;
            dirP->y *= sp;
            dirP->z *= sp;
        }
    
        {
        NJS_POINT3* vtxP;   
        unsigned int* colP; 
        int i; // modified DWARF position 
        
        vtxP = (NJS_POINT3*)r08P->VtxBuf;
        colP = (unsigned int*)r08P->VtxCol;
            
        for (i = r08P->prm_a.vtx_num; i > 0; i--, vtxP += 2, colP += 2) 
        {
            vtxP[0] = pmbP->vtx_pos;
            
            colP[0] = pmbP->col_src;
            colP[1] = pmbP->col_dst & 0xFFFFFF;
        }
        }
        
        {
        int i;     
        int* timP, *addP, *subP; 
        int tmp;  
        int tim;      // modified DWARF position 
        int src, dst; // modified DWARF position 
        
        timP = r08P->TimBuf;
            
        addP = r08P->ColAdd;
        subP = r08P->ColSub;
            
        for (i = r08P->prm_a.vtx_num; i > 0; i--, timP++, addP++, subP++) 
        {
            *timP = tim = r08P->prm_a.time + (int)(r08P->prm_a.tim_rand * (-rand() / -2147483648.0f));
        
            src = pmbP->col_src;
            dst = pmbP->col_dst;
        
            tmp = ((dst & 0xFF) - (src & 0xFF)) / tim;
            
            if (tmp < 0) 
            {
                *subP  = ~tmp & 0xFF;
            }
            else        
            {
                *addP  = tmp  & 0xFF;
            }
        
            tmp = ((dst & 0xFF00) - (src & 0xFF00)) / tim;
            
            if (tmp < 0)
            {
                *subP |= ~tmp & 0xFF00;
            }
            else        
            {
                *addP |= tmp  & 0xFF00;
            }
        
            tmp = ((dst & 0xFF0000) - (src & 0xFF0000)) / tim;
            
            if (tmp < 0) 
            {
                *subP |= ~tmp & 0xFF0000;
            }
            else         
            {
                *addP |= tmp  & 0xFF0000;
            }
    
            src >>= 16;
            dst >>= 16;
            
            tmp = ((dst & 0xFF00) - (src & 0xFF00)) / tim;
            
            if (tmp < 0) 
            { 
                *subP |= (~tmp & 0xFF00) << 16; 
            }
            else         
            { 
                *addP |= (tmp  & 0xFF00) << 16;
            }
        }
        }
        
        r08P->wnd_spd = 0;
        r08P->wnd_acl = 0.01f * sys->winds;
        
        r08P->mode++;
    }
    case 1:
    {
        int i;           
        NJS_POINT3 wnd;    
        NJS_POINT3* vtxP, *dirP;  
        unsigned int* colP; 
        int ay;             
        float sp;           
        
        r08P->drw_num = 0;
    
        sp = r08P->wnd_spd;
        
        ay = sys->windr;

        vtxP = (NJS_POINT3*)r08P->VtxBuf;
        dirP = r08P->VtxDir;
        colP = (unsigned int*)r08P->VtxCol;
    
        wnd.x = sp * -njSin(ay);
        wnd.y = 0;
        wnd.z = sp * -njCos(ay);
    
        r08P->wnd_spd = sp + r08P->wnd_acl;
        
        for (i = 0; i < r08P->prm_a.vtx_num; i++, vtxP += 2, dirP++, colP += 2) 
        {
            if (r08P->TimBuf[i] > 0)
            {
                r08P->TimBuf[i]--;
                
                r08P->drw_num++;
                
                vtxP[1] = vtxP[0];
                
                njAddVector(vtxP, dirP);
                njAddVector(vtxP, &wnd);
                
                dirP->x *= r08P->prm_a.accel;
                dirP->y *= r08P->prm_a.accel;
                dirP->z *= r08P->prm_a.accel;
                
                dirP->y += r08P->prm_a.gravity;
                
                colP[0] += r08P->ColAdd[i];
                colP[0] -= r08P->ColSub[i];
                
                if (vtxP[0].y < pmbP->gnd_hgh) 
                {
                    dirP->y *= -0.5f;
                    
                    vtxP[0].y = pmbP->gnd_hgh;
                }
            }
        }
        
        if (r08P->drw_num == 0) 
        {
            orP->flg = 0;
        }
        else 
        {
            sys->ef_fnc[sys->ef_fncn++] = (O_WRK*)orP;
        }
    }
    }
}

// 100% matching!
void bhEff308Drw(OR_WORK* orP) 
{
    R08_WORK* r08P;      
    int i;               
    NJS_POINT3COL* p3cP; 
    int* timP;          
   
    r08P = (R08_WORK*)orP->free4;
    
    njSetMatrix(NULL, cam.mtx);
    
    p3cP = &r08P->lne_p3c;
    timP = r08P->TimBuf;
    
    for (i = 0; i < r08P->prm_a.vtx_num; i++, timP++)
    {
        if (*timP != 0) 
        {
            p3cP->p   = r08P->VtxBuf[i];
            p3cP->col = (NJS_COLOR*)r08P->VtxCol[i];
            p3cP->tex = NULL;
            p3cP->num = 1;
            
            njDrawLine3D(p3cP, p3cP->num, 0x40);
        }
    }
}

// 100% matching!
static int ryLinerColor(int src_col, int dst_col, float rate)
{
    int rte; 
    int tmp; 
    int col; 
    
    rte = 256.0f * rate;
    
    col = (src_col  + ((rte * ((dst_col & 0xFF)     - (src_col & 0xFF)))     >> 8)) & 0xFF;
    col |= (src_col + ((rte * ((dst_col & 0xFF00)   - (src_col & 0xFF00)))   >> 8)) & 0xFF00;
    col |= (src_col + ((rte * ((dst_col & 0xFF0000) - (src_col & 0xFF0000))) >> 8)) & 0xFF0000;
    
    dst_col >>= 8;
    
    tmp = dst_col & 0xFF0000;
    
    src_col >>= 8;
    
    col |= ((src_col + ((rte * (tmp - (src_col & 0xFF0000))) >> 8)) << 8) & 0xFF000000;
    
    return col;
}

// 100% matching!
OR_WORK* rySetEffBlood(NJS_MATRIX* mtxP, NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no)
{
    OR_WORK* orP; 
    PMB_WRK* pmbP;
    int mode;     
    R09_WORK* r09P; 
    static const Eff309PRM_WORK Eff309Prm[6] = 
	{
		{  0.5f, 0.98f, 4.0f,   1.0f, { 0, 0, 2,  5, -1, -1, -1, -1 }, 55.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 0 },
		{  0.5f, 0.98f, 2.0f,   1.1f, { 0, 0, 0,  1,  1,  2, -1, -1 }, 60.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 0 },
		{ 0.75f, 0.75f, 1.5f, 1.125f, { 0, 1, 2,  5,  6,  7, -1, -1 }, 45.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 0 },
		{  0.5f, 0.98f, 4.0f,   1.0f, { 0, 2, 5, -1, -1, -1, -1, -1 }, 55.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 2 },
		{  0.5f, 0.98f, 2.0f,   1.1f, { 0, 0, 1,  1,  2, -1, -1, -1 }, 60.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 2 },
		{ 0.75f, 0.75f, 1.5f, 1.125f, { 0, 1, 5,  6,  7, -1, -1, -1 }, 45.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 2 }
	};
    
    mode = 0;
    
    if ((typ_no & 0x80000000)) 
    {
        mode |= 0x1;
    }
    
    if ((typ_no & 0x40000000)) 
    {
        mode |= 0x2;
    }

	typ_no &= 0x3FFFFFFF;
    
    orP = bhSetRapEff(309, (void*)&Eff309Prm[typ_no], 12);
    
    if (orP != NULL)
    {
        pmbP = (PMB_WRK*)((char*)orP + 192);
        
        pmbP->vtx_mtxP = mtxP;
        pmbP->vtx_pos  = *posP;
        pmbP->vtx_dir  = *dirP;
            
        r09P = (R09_WORK*)orP->free4;
        
        r09P->texP   = &sys->ef_tlist;
        r09P->tex_id = sys->ef_tn[5];
        
        r09P->type = mode;
    }
    
    return orP;
}

// 99.88% matching
void bhEff309(OR_WORK* orP) 
{
    R09_WORK* r09P;   
    PMB_WRK* pmbP;    
    static const UV_WORK Tex5Buv[12] = 
	{
		{ 0.1875f, 0.4375f, 0.12109375f, 0.12109375f },
		{ 0.0625f, 0.4375f, 0.12109375f, 0.12109375f },
		{ 0.8125f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.6875f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.5625f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.4375f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.3125f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.1875f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.4375f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.3125f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.1875f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.0625f, 0.3125f, 0.12109375f, 0.12109375f }
	};
    
    r09P = (R09_WORK*)orP->free4;
    pmbP = &r09P->prm_b;

    if (r09P->mode != 2) 
    {
        switch (r09P->mode) 
        {
        case 0:
        {
            int i;           
            rap_tex_typ* rtP;  

            rtP = r09P->RapTex;
            
            orP->func = (void*)bhEff309Drw;
            
            r09P->freeP = rtP;
            
            for (i = 5; i > 0; i--, rtP++) 
            {
                rtP->mode  = 0;
                rtP->nextP = &rtP[1];
            }
            
            rtP->mode  = 0;
            rtP->nextP = NULL;
            
            njSetMatrix(lcmat, pmbP->vtx_mtxP);
            
            njInvertMatrix(lcmat);
            
            if (!(r09P->type & 0x1)) 
            {
                njCalcPoint(lcmat, &pmbP->vtx_pos, &pmbP->vtx_pos);
            }
            
            if (!(r09P->type & 0x2)) 
            {
                njCalcVector(lcmat, &pmbP->vtx_dir, &pmbP->vtx_dir);
            }
            
            njUnitVector(&pmbP->vtx_dir);
            
            r09P->mode++;
        }
        case 1:
        {
            int i;      
            char* timP; 

            timP = r09P->prm_a.SetTim;
            
            for (i = 6; i > 0; i--, timP++)
            {
                if ((*timP)-- == 0) 
                {
                    rap_tex_typ* rtP; 
                    NJS_POINT3 pos;  
                    NJS_POINT3* dirP; 
                    float sp;         

                    rtP         = r09P->freeP;
                    r09P->freeP = rtP->nextP;
                    
                    rtP->mode = -1;
                    
                    njCalcPoint(pmbP->vtx_mtxP, &pmbP->vtx_pos, &pos);
                    
                    ryRapDspSet(&pos, &rtP->dsp_wrk, r09P->prm_a.scale);
                    
                    njSetMatrix(lcmat, pmbP->vtx_mtxP);
                    
                    njRotateY(lcmat, 182.04445f * (r09P->prm_a.ang_rand * ((-rand() / -2147483648.0f) - 0.5f)));
                    njRotateX(lcmat, 182.04445f * (r09P->prm_a.ang_rand * ((-rand() / -2147483648.0f) - 0.5f)));
                    
                    dirP = &rtP->mov_wrk.vtx_vel;
                    
                    sp = r09P->prm_a.speed + (r09P->prm_a.spd_rand * ((-rand() / -2147483648.0f) - 0.5f));
                    
                    njCalcVector(lcmat, &pmbP->vtx_dir, dirP);
                    
                    dirP->x *= sp;
                    dirP->y *= sp;
                    dirP->z *= sp;
                    
                    rtP->anm_wrk.uv_tabP = (UV_WORK*)Tex5Buv;
                    rtP->anm_wrk.anm_no  = 12;
                    
                    ryRapAnmColSet(&rtP->anm_wrk, r09P->prm_a.col_src, r09P->prm_a.col_dst, 12);
                }
            }
            
            break;
        }
        }
    }
    
    {
        int i;            
        rap_tex_typ* rtP; 

        rtP = r09P->RapTex;
        
        r09P->busyP = NULL;
        
        for (i = 5; i > 0; i--, rtP++) 
        {
            if (rtP->mode != 0)
            {
                NJS_POINT3* dirP; 
                float acl;        

                dirP = &rtP->mov_wrk.vtx_vel; 
                
                acl = r09P->prm_a.accel;
                
                njAddVector(&rtP->dsp_wrk.vtx_pos, dirP);
                
                dirP->x *= acl;
                dirP->y *= acl;
                dirP->z *= acl;
                
                dirP->y += r09P->prm_a.gravity;
                
                rtP->dsp_wrk.vtx_scl *= r09P->prm_a.scl_accel;
                
                if (ryRapTexAnm(&rtP->anm_wrk, &rtP->dsp_wrk, 1) >= 0) 
                {
                    rtP->nextP  = r09P->busyP;
                    r09P->busyP = rtP;
                } 
                else
                {
                    rtP->mode = 0;
                }
            }
        }
    }
    
    if (r09P->busyP == NULL) 
    {
        orP->flg = 0;
    }
    else 
    {
        sys->ef_fnc[sys->ef_fncn++] = (O_WRK*)orP;
    }
} 

// 100% matching!
void bhEff309Drw(OR_WORK* orP) 
{
    R09_WORK* r09P;

    r09P = (R09_WORK*)orP->free4;
    
    njTextureFilterMode(1);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    ryRapTexDrw(r09P->texP, r09P->tex_id + r09P->prm_a.pal_bank, r09P->busyP);
}

// 100% matching!
static void ryRapTexDrw(NJS_TEXLIST* texP, int tex_id, rap_tex_typ* rtP)
{
	NJS_POINT3 scl;
    
    njSetTexture(texP);
    njSetTextureNum(tex_id);
    
    njDrawTexture3DExStart(1);
    
    njPushMatrixEx();
    
    for (; rtP != NULL; rtP = rtP->nextP) 
    {
        njSetMatrix(NULL, cam.mtx);
        
        njTranslateV(NULL, &rtP->dsp_wrk.vtx_pos);
        njUnitRotPortion(NULL);
        
        scl.x = scl.y = scl.z = rtP->dsp_wrk.vtx_scl;
        
        njScaleEx(&scl);
        
        njDrawTexture3DExSetData(rtP->dsp_wrk.VtxBuf, 4);
    } 
    
    njPopMatrixEx();
    
    njDrawTexture3DExEnd();
}

// 100% matching!
static int ryRapTexAnm(ANM_WORK* anmP, DSP_WRK* dspP, int bol)
{
    int anm_no; 
    UV_WORK* uvP; 
    float* tvP;   
    unsigned int col; 
    
    anm_no = anmP->anm_no;
    
    if (anm_no >= 0) 
    {
        col = anmP->color;
        
        uvP = &anmP->uv_tabP[anm_no];
        tvP = &dspP->VtxBuf->u; 
        
        *tvP++     = uvP->u;
        *tvP++     = uvP->v;
        *(int*)tvP = col;

        tvP += 4;
        
        *tvP++     = uvP->u;
        *tvP++     = uvP->v + uvP->ys;
        *(int*)tvP = col;

        tvP += 4;
        
        *tvP++     = uvP->u + uvP->xs;
        *tvP++     = uvP->v;
        *(int*)tvP = col;

        tvP += 4;
        
        *tvP++     = uvP->u + uvP->xs;
        *tvP++     = uvP->v + uvP->ys;
        *(int*)tvP = col;
        
        if (bol != FALSE) 
        {
            anmP->anm_no--;
            
            anmP->color += anmP->col_add;
            anmP->color -= anmP->col_sub;
        }
    }
    
    return anm_no;
}

// 100% matching!
static void ryRapDspSet(NJS_POINT3* posP, DSP_WRK* dspP, float scl)
{
    float* vbP;
    float tmp; // not from DWARF

    tmp = 0.5f;
    
    dspP->vtx_scl = scl;
    dspP->vtx_pos = *posP;

    vbP = &dspP->VtxBuf->x;  
    
    *vbP++ = -tmp;
    *vbP++ = tmp;
    *vbP   = 0;

    vbP += 4;  
    
    *vbP++ = -tmp;
    *vbP++ = -tmp;
    *vbP   = 0;

    vbP += 4;
    
    *vbP++ = tmp;
    *vbP++ = tmp;
    *vbP   = 0;

    vbP += 4;
    
    *vbP++ = tmp;
    *vbP++ = -tmp;
    *vbP   = 0;
}

// 100% matching!
static void ryRapAnmColSet(ANM_WORK* anmP, int src_col, int dst_col, int col_cnt)
{
    int tmp;            
    unsigned int* addP, *subP; 
    
    addP = (unsigned int*)&anmP->col_add; 
    subP = (unsigned int*)&anmP->col_sub; 
    
    anmP->color = src_col;      
    
    tmp = ((dst_col & 0xFF)     - (src_col & 0xFF))     / col_cnt;
    
    if (tmp < 0)
    {
        *subP = ~tmp & 0xFF;
    } 
    else 
    {
        *addP = tmp  & 0xFF;
    }
    
    tmp = ((dst_col & 0xFF00)   - (src_col & 0xFF00))   / col_cnt;
    
    if (tmp < 0) 
    {
        *subP |= ~tmp & 0xFF00;
    }
    else 
    {
        *addP |= tmp  & 0xFF00;
    }
    
    tmp = ((dst_col & 0xFF0000) - (src_col & 0xFF0000)) / col_cnt;
    
    if (tmp < 0) 
    {
        *subP |= ~tmp & 0xFF0000;
    }
    else
    {
        *addP |= tmp  & 0xFF0000;
    }
    
    src_col >>= 16;
    dst_col >>= 16;
    
    tmp = ((dst_col & 0xFF00)   - (src_col & 0xFF00))   / col_cnt;
    
    if (tmp < 0) 
    {
        *subP |= (~tmp & 0xFF00) << 16;
    } 
    else 
    {
        *addP |= (tmp & 0xFF00)  << 16;
    }
}

// 100% matching!
void bhEff30a(OR_WORK* orP)
{
    R0A_WORK* r0aP; 

    r0aP = (R0A_WORK*)orP->free4; 

    switch (r0aP->prm_a.type) 
    {                               
    case 0:                                        
        break;
    case 1:                                        
        cam.ofx = cam.ofy = cam.ofz = 0; 
        break;
    case 2:                                        
        if ((sys->cb_flg & 0x4)) 
        {
            *(int*)orP = 0; 
            break;
        }
        
        if ((sys->sp_flg & 0x1))
        {
            switch (r0aP->mode)
            {                      
            case 0:                                 
                r0aP->ang_x = r0aP->ang_y = r0aP->prm_a.ang_fst;
                
                r0aP->mode++;
            case 1:                                 
                njSetMatrix(lcmat, cam.mtx);
                
                r0aP->off_pos.y = r0aP->prm_a.y_rang * njSin(r0aP->ang_y);
                r0aP->off_pos.x = r0aP->prm_a.x_rang * njCos(r0aP->ang_x);
                
                r0aP->off_pos.z = 0; 
                
                njCalcVector(lcmat, &r0aP->off_pos, &r0aP->off_pos);
                
                r0aP->ang_x += r0aP->prm_a.add_ax;
                r0aP->ang_y += r0aP->prm_a.add_ay;
                
                r0aP->prm_a.x_rang *= r0aP->prm_a.x_rate;
                r0aP->prm_a.y_rang *= r0aP->prm_a.y_rate;
                
                if ((r0aP->prm_a.x_rang + r0aP->prm_a.y_rang) < 0.01f) 
                {
                    r0aP->dst_pos.x = r0aP->dst_pos.y = r0aP->dst_pos.z = 0;
                    
                    *(int*)orP = 0; 
                }
                
                break;
            }
            
            njAddVector((NJS_VECTOR*)&cam.ofx, &r0aP->off_pos);
        }
        
        break;
    }
}

// 100% matching!
void bhEff349(OR_WORK* orP) 
{
    R49_WORK* r49P;
    
    r49P = (R49_WORK*)orP->free4;

    if (r49P->fnc_prcP != NULL) 
    {
        r49P->fnc_prcP(&r49P->free);
    }
    
    if (r49P->fnc_drwP != NULL) 
    {
        orP->func                   = (void*)r49P->fnc_drwP;
        sys->ef_fnc[sys->ef_fncn++] = (O_WRK*)orP;
    }
}

// 100% matching!
OR_WORK* rySetEffBlood2(NJS_MATRIX* mtxP, NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no)
{
    OR_WORK* orP;
    PMB_WRK* pmbP;
    int mode;
    R0B_WORK* r0bP;
    EFF30bPRM_WORK Eff30bPrm[6] = 
	{
		{ 0.25f, 0.5f, 0.8f, 15.0f, 0.02f, 16, 0xF0802000, 0xF0400000, -0.03266667f,  56, 16, 0.96f },
		{  0.4f, 1.0f, 0.9f, 25.0f, 0.05f, 16, 0xF0802000, 0xF0400000, -0.03266667f,  56, 16, 0.96f },
		{  0.4f, 4.0f, 0.8f, 40.0f, 0.05f, 16, 0xF0802000, 0xF0400000, -0.03266667f, 448,  0, 0.98f },
		{  1.0f, 2.0f, 0.8f, 20.0f,  0.1f,  8, 0xF0004030, 0xF0404020, -0.03266667f,  56, 16,  0.9f },
		{  1.5f, 3.0f, 0.8f, 20.0f, 0.08f, 12, 0xF0004030, 0xF0404020, -0.03266667f,  56, 16, 0.98f },
		{  2.0f, 4.0f, 0.8f, 30.0f, 0.06f, 16, 0xF0104030, 0xF0404020, -0.03266667f,  56, 16, 0.99f }
	};
    
    mode = 0;
    
    if ((typ_no & 0x80000000)) 
    {
        mode |= 0x1;
    }
    
    if ((typ_no & 0x40000000)) 
    {
        mode |= 0x2;
    }

	typ_no &= 0x3FFFFFFF;
    
    orP = bhSetRapEff(311, (void*)&Eff30bPrm[typ_no], 12);
    
    if (orP != NULL)
    {
        pmbP = (PMB_WRK*)((char*)orP + 192);
        
        pmbP->vtx_mtxP = mtxP;
        pmbP->vtx_pos  = *posP;
        pmbP->vtx_dir  = *dirP;
            
        r0bP = (R0B_WORK*)orP->free4;
        
        r0bP->texP   = &sys->ef_tlist;
        r0bP->tex_id = sys->ef_tn[4];
        
        r0bP->type = mode;
    }
    
    return orP;
}

// 99.92% matching
void bhEff30b(OR_WORK* orP) 
{
    R0B_WORK* r0bP;      
    PMB_WRK* pmbP;       

    r0bP = (R0B_WORK*)orP->free4;
    pmbP = &r0bP->prm_b;

    switch (r0bP->mode) 
    {
    case 0:
    {
        eff30b_vtx_buf_typ* vbP; 
        int num;                 
        
        orP->func = (void*)bhEff30bDrw;
        
        r0bP->time = r0bP->prm_a.eff_erase;
        
        r0bP->eff_scale = 1.0f;

        njSetMatrix(lcmat, pmbP->vtx_mtxP);
        njInvertMatrix(lcmat);

        if (!(r0bP->type & 0x1)) 
        {
            njCalcPoint(lcmat, &pmbP->vtx_pos, &pmbP->vtx_pos);
        }

        if (!(r0bP->type & 0x2)) 
        {
            njCalcVector(lcmat, &pmbP->vtx_dir, &pmbP->vtx_dir);
        }
        
        njUnitVector(&pmbP->vtx_dir);

        num = (unsigned int)(r0bP->prm_a.vtx_num + 27) / 28; 

        owk_scn_noG = 0;
        
        if ((r0bP->vtx_bufP = vbP = (eff30b_vtx_buf_typ*)AllocOwork()) != NULL) 
        {
            for (; num > 1; num--) 
            {
                vbP->nextP = (eff30b_vtx_buf_typ*)AllocOwork();
                
                vbP = vbP->nextP;
                
                if (vbP == NULL) 
                {
                    break;
                }
            }
        }
        else 
        {
            orP->flg = 0;
        }

        r0bP->mode++;
    }
    case 1:
    {
        eff30b_vtx_buf_typ* vbP; 
        int num;                 
        VTXBUF_WORK* vtxP;     
        float rng;            
        float min, max;              
        NJS_POINT3* dirP;      
        int rx, ry, rz; // not from DWARF
            
        for (vbP = r0bP->vtx_bufP; vbP != NULL; vbP = vbP->nextP) 
        {
            vtxP = vbP->VtxBuf;
            
            for (num = 28; num > 0; num--, vtxP++) 
            {
                if (vtxP->time == 0) 
                {                
                    vtxP->time = r0bP->prm_a.vtx_erase / 2;
                    vtxP->time += (int)(vtxP->time * (-rand() / -2147483648.0f));
                    
                    vtxP->scl_time = vtxP->time / 2;

                    rng = r0bP->prm_a.ang_rand * r0bP->eff_scale;
                    
                    rx = (((-rand() / -2147483648.0f) - 0.5f) * rng) * 182.04445f;
                    ry = (((-rand() / -2147483648.0f) - 0.5f) * rng) * 182.04445f;
                    rz = (((-rand() / -2147483648.0f) - 0.5f) * rng) * 182.04445f; 

                    njUnitMatrix(lcmat);
                    
                    njRotateXYZ(lcmat, rx, ry, rz);
                    njCalcPoint(pmbP->vtx_mtxP, &pmbP->vtx_pos, &vtxP->pos);
                    
                    min = r0bP->prm_a.vtx_sp_min;
                    max = r0bP->prm_a.vtx_sp_max;
                    
                    dirP = &vtxP->dir;

                    njCalcVector(lcmat, &pmbP->vtx_dir, dirP);
                    njCalcVector(pmbP->vtx_mtxP, dirP,  dirP);

                    vtxP->spd = min + ((max - min) * (-rand() / -2147483648.0f));
                    vtxP->spd *= r0bP->eff_scale;
                    
                    vtxP->grv = 0;
                    
                    vtxP->col = ryLinerColor(r0bP->prm_a.col_src, r0bP->prm_a.col_dst, -rand() / -2147483648.0f);
                    
                    vtxP->scl = 0;
                }

                vtxP->time--;
                
                vtxP->pos.x +=              vtxP->dir.x * vtxP->spd;
                vtxP->pos.y += vtxP->grv + (vtxP->dir.y * vtxP->spd);
                vtxP->pos.z +=              vtxP->dir.z * vtxP->spd;
                
                vtxP->spd *= r0bP->prm_a.vtx_accel;
                
                vtxP->grv += r0bP->prm_a.vtx_gravity;

                if (vtxP->time > vtxP->scl_time) 
                {
                    vtxP->scl += r0bP->prm_a.vtx_scale;
                }
                else 
                {
                    vtxP->scl += r0bP->prm_a.vtx_scale * -0.5f;
                }
            }
        }

        if (r0bP->time > 0) 
        {
            r0bP->time--;
        }
        else 
        {
            r0bP->eff_scale *= r0bP->prm_a.eff_rate;
        }

        if (r0bP->eff_scale > 0.1f) 
        {
            sys->ef_fnc[sys->ef_fncn++] = (O_WRK*)orP;
        } 
        else 
        {
            eff30b_vtx_buf_typ* vbP; 
            
            orP->flg = 0;
            
            for (vbP = r0bP->vtx_bufP; vbP != NULL; vbP = vbP->nextP) 
            {
                vbP->flg = 0;
            }
        }
        
        break;
    }
    }
}

// 100% matching!
static void bhEff30bDrw(OR_WORK* orP)
{
    R0B_WORK* r0bP;          
    VTXBUF_WORK* vtxP;      
    int num;                
    eff30b_vtx_buf_typ* vbP; 
    float scl;             
    static NJS_TEXTURE_VTX VtxBuf[4] = 
	{
		{ -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0x00000000 },
		{ -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0x00000000 },
		{  1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 0x00000000 },
		{  1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0x00000000 }
	};
    
    r0bP = (R0B_WORK*)orP->free4;
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njTextureFilterMode(0);
    
    njSetMatrix(NULL, cam.mtx);
    njSetTexture(r0bP->texP);
    
    njPushMatrixEx();
    
    vbP = r0bP->vtx_bufP;
    
    if (vbP != NULL) 
    {
        num = 28;
        
        do 
        {
            vtxP = vbP->VtxBuf;
            
            do 
            {
                scl = vtxP->scl * r0bP->eff_scale;
                
                njSetMatrix(NULL, cam.mtx);
                
                njTranslateV(NULL, &vtxP->pos);
                njUnitRotPortion(NULL);
                
                njScale(NULL, scl, scl, scl);
                
                VtxBuf[0].col = VtxBuf[1].col = VtxBuf[2].col = VtxBuf[3].col = vtxP->col;
                
                njSetTextureNum(r0bP->tex_id + (vtxP->time & 3));
                
                njDrawTexture3DEx(VtxBuf, 4, 1);
                
                num--;
                vtxP++;
            } while (num > 0);
            
            vbP = vbP->nextP;
            num = 28;
        } while (vbP != NULL);
    }
    
    njPopMatrixEx();
}

// 100% matching!
void bhEff30c(OR_WORK* orP) 
{
    R0_WK* r0cP;
    
    r0cP = (R0_WK*)orP->free4; 

    switch (r0cP->mode) 
    {                              
    case 0:
        orP->func = (void*)bhEff30cDrw;
        
        r0cP->erase = -1;
        
        r0cP->mtxP = (NJS_MATRIX*)r0cP->mtx_buf;
        
        r0cP->mode++;
    case 1:
        njSetMatrix(r0cP->mtxP, r0cP->prm.mtxP);
        
        njTranslate(r0cP->mtxP, r0cP->prm.pos[0], r0cP->prm.pos[1], r0cP->prm.pos[2]);
        njRotateXYZ(r0cP->mtxP, r0cP->prm.ang[0], r0cP->prm.ang[1], r0cP->prm.ang[2]);
        
        if (r0cP->erase == 0) 
        {
            *(int*)orP = 0; 
        }
        else 
		{
        	sys->ef_fnc[sys->ef_fncn++] = (O_WRK*)orP;
		}
		
        break;
    }
}

// 100% matching!
static void bhEff30cDrw(OR_WORK* orP)
{
    R0_WK* r0cP;
    
    r0cP = (R0_WK*)orP->free4;

    if (r0cP->prm.texP != NULL) 
    {
        njSetTexture(r0cP->prm.texP);
    }
    
    njPushMatrix(cam.mtx);
    njMultiMatrix(NULL, r0cP->mtxP);
    
    njCnkEasyMultiDrawModel((NJS_CNK_MODEL*)r0cP->prm.mdlP);
    
    njPopMatrixEx();
}
