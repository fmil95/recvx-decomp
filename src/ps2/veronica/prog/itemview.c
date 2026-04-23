#include "../../../ps2/veronica/prog/item.h"
#include "../../../ps2/veronica/prog/itemview.h"
#include "../../../ps2/veronica/prog/binfunc.h"
#include "../../../ps2/veronica/prog/dread.h"
#include "../../../ps2/veronica/prog/fileview.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/message.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_texture.h"
#include "../../../ps2/veronica/prog/sub1.h"

static unsigned int* wp_;
static unsigned char flg[3];
static int ang_00[3];
static int ang_01[3];
static int ang_02[3];
static NJS_POINT3 vec_00;
static float check[16];
static float testf;
static NJS_VECTOR whd;

unsigned char (*actionprg[3])(SITEM* si) = 
{ 
	MdlAction00,
	MdlAction01,
	MdlAction02
};
static unsigned int ItemViewTypeTbl[168] = 
{
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 3, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2 
};
/*int ViewType;
FV_WORK fvwork;
DSP_WORK dsptbl[0];
S_WORK swork;
_anon24* sys;
SITEM sitem;
NJS_POINT3 hoseipos[0];
unsigned char itemflg[8][0];
unsigned short getmestbl[0];
_anon23 itemdata[0];
unsigned short mestbl[0];
short c_a[6][0];
_anon41 parts_10b[0];
unsigned short idsettbl[0];*/

// 100% matching!
void DrawSubItem(S_WORK* st, SITEM* si)
{
	NJS_MATRIX testtest; 
    STCAM_WRK* sc; 
    FV_WORK* fv; 
    DSP_WORK* dw_a; 
    NJS_POINT3 pos00;
    
    sc = &st_cam;
    fv = &fvwork;
    
    dw_a = &dsptbl[st->itemid];
    
    njPushMatrix(NULL);
    njSetMatrix(NULL, &sc->rotmat);
    njTransposeMatrix(NULL);
    
    switch (st->subcsr) 
    {
    case 0:
    case 1:
        st->subcsr = 2;
        
        njRotateX(NULL, (int)(182.04445f * -dw_a->ax) & 0xFFFF);
        njRotateY(NULL, (int)(182.04445f * -dw_a->ay) & 0xFFFF);
        njRotateZ(NULL, (int)(182.04445f * -dw_a->az) & 0xFFFF);
        break;
    case 2:
        njRotateX(NULL, sc->cax);
        njRotateY(NULL, sc->cay);
        njRotateZ(NULL, sc->caz);
        break;
    case 3:
        st->subcsr = 2;
        
        if (st->itemid == 105) 
        {
            njRotateX(NULL, 50245);
            njRotateY(NULL, 51519);
            njRotateZ(NULL, 1457);
        }
        else if (st->itemid == 30) 
        {
            njRotateX(NULL, 50245);
            njRotateY(NULL, 57709);
            njRotateZ(NULL, 42235);
        } 
        else 
        {
            njRotateX(NULL, 21846);
            njRotateY(NULL, 0);
            njRotateZ(NULL, 0);
        }
    }
    
    njTransposeMatrix(NULL);
    njGetMatrix(&sc->rotmat);
    njGetMatrix(&check);
    njPopMatrix(1);
    
    ang_01[0] = ang_00[0] = (int)(10430.381f * atan2f(check[6], check[10])) & 0xFFFF;
    ang_01[0] = ang_00[1] = (int)(10430.381f * asinf(-check[2])) & 0xFFFF;
    ang_01[0] = ang_00[2] = (int)(10430.381f * atan2f(check[1], check[0])) & 0xFFFF;
    
    si->mw.ang[0] = ang_00[0];
    si->mw.ang[1] = ang_00[1];
    si->mw.ang[2] = ang_00[2];
    
    ang_00[0] = ((ang_00[0] * 360) >> 16) & 0xFFFF;
    ang_00[1] = ((ang_00[1] * 360) >> 16) & 0xFFFF;
    ang_00[2] = ((ang_00[2] * 360) >> 16) & 0xFFFF;
    
    ang_02[0] = (int)(10430.381f * acosf(vec_00.x));
    ang_02[1] = (int)(10430.381f * acosf(vec_00.y));
    ang_02[2] = (int)(10430.381f * acosf(vec_00.z));
    
    ang_02[0] = ((ang_02[0] * 360) >> 16) & 0xFFFF;
    ang_02[1] = ((ang_02[1] * 360) >> 16) & 0xFFFF;
    ang_02[2] = ((ang_02[2] * 360) >> 16) & 0xFFFF;
    
    njPushMatrix(NULL);
    njTranslate(NULL, 0, 0, 0);
    njMultiMatrix(NULL, &sc->rotmat);
    njPushMatrix(NULL);
    njGetMatrix(&testtest);
    njUnitMatrix(NULL);
    njPushMatrix(NULL);
                  
    njCnkSetEasyMultiLight(1);
    njCnkSetEasyMultiLightPoint(1, 0, 0, 12.0f);
    njCnkSetEasyMultiLightRange(1, 4.0f, 140.0f);
    njCnkSetEasyMultiAmbient(0.4f, 0.4f, 0.4f);
    njCnkSetEasyMultiLightColor(1, 30.0f, 30.0f, 30.0f);
    
    njClearMatrix();
    
    njCnkSetEasyMultiLightMatrices();
    
    njPopMatrix(1);
    njSetMatrix(NULL, &testtest);

    njRotateX(NULL, si->mw.ax1);
    njRotateY(NULL, si->mw.ay1);
    njRotateZ(NULL, si->mw.az1);

    njPushMatrix(NULL);
    njTranslate(NULL, si->mw.pos.x, si->mw.pos.y, si->mw.pos.z);
    
    if (si->mw.rdid == 139) 
    {
        njScale(NULL, 0.58f, 0.58f, 0.58f);
    }
    else 
    {
        njScale(NULL, testf, testf, testf);
    }
    
    njSetTexture(si->mdl.texP);
    
    if (si->mw.rdid == 139) 
    {
        njPushMatrix(NULL);
        
        if ((!(fvwork.afsmode & 0x20)) || (fv->filecsr == 0))
        {
            njPushMatrix(NULL);
            njUnitMatrix(NULL);
            
            njRotateX(NULL, si->mdl.objP->child->ang[0]);
            njRotateY(NULL, si->mdl.objP->child->ang[1]);
            njRotateZ(NULL, si->mdl.objP->child->ang[2]);
            
            njCalcPoint(NULL, (NJS_POINT3*)si->mdl.objP->child->pos, &pos00);
            
            njPopMatrix(1);
            njTranslate(NULL, pos00.x, pos00.y, pos00.z);
            
            if (fv->filecsr == 0) 
            {
                njRotateY(NULL, fv->ang00);
            }
            
            njCnkEasyMultiDrawModel(si->mdl.objP->child->model);
            
            MakeTag(si->mdl.objP->child, 0);
        }
        
        njPopMatrix(1);
        njPushMatrix(NULL);
        
        if ((!(fvwork.afsmode & 0x20)) || (fv->filecsr == 2))
        {
            njPushMatrix(NULL);
            njUnitMatrix(NULL);
            
            njRotateX(NULL, si->mdl.objP->child->sibling->ang[0]);
            njRotateY(NULL, si->mdl.objP->child->sibling->ang[1]);
            njRotateZ(NULL, si->mdl.objP->child->sibling->ang[2]);
            
            njCalcPoint(0, (NJS_POINT3*)si->mdl.objP->child->sibling->pos, &pos00);
            
            njPopMatrix(1);
            njTranslate(NULL, pos00.x, pos00.y, pos00.z);
            
            if (fv->filecsr == 2) 
            {
                njRotateY(NULL, fv->ang00);
            }
            
            njCnkEasyMultiDrawModel(si->mdl.objP->child->sibling->model);
            
            MakeTag(si->mdl.objP->child->sibling, 2);
        }
        
        njPopMatrix(1);
        njPushMatrix(NULL);
        
        if ((!(fvwork.afsmode & 0x20)) || (fv->filecsr == 1))
        {
            njPushMatrix(NULL);
            njUnitMatrix(NULL);
            
            njRotateX(NULL, si->mdl.objP->child->sibling->sibling->ang[0]);
            njRotateY(NULL, si->mdl.objP->child->sibling->sibling->ang[1]);
            njRotateZ(NULL, si->mdl.objP->child->sibling->sibling->ang[2]);
            
            njCalcPoint(NULL, (NJS_POINT3*)si->mdl.objP->child->sibling->sibling->pos, &pos00);
            
            njPopMatrix(1);
            njTranslate(NULL, pos00.x, pos00.y, pos00.z);
            
            if (fv->filecsr == 1)
            {
                njRotateY(NULL, fv->ang00);
            }
            
            njCnkEasyMultiDrawModel(si->mdl.objP->child->sibling->sibling->model);
            
            MakeTag(si->mdl.objP->child->sibling->sibling, 1);
        }
        
        njPopMatrix(1);
    } 
    else 
    {
        ViewType = ItemViewTypeTbl[st->itemid];
        
        njCnkEasyMultiDrawObjectI(si->mdl.objP);
        
        if ((st->itemid == 33) || (st->itemid == 34) || (st->itemid == 142))
        {
            njTranslate(NULL, 0.1f, 1.0f, 0.2f);
            njPushMatrix(NULL);
            
            njCnkEasyMultiDrawObjectI(si->mdl.objP);
            
            njPopMatrix(1);
        }
    }
    
    njPopMatrix(1);
    njPopMatrix(1);
    njPopMatrix(1);
}

// 100% matching!
void Model_Read_Start()
{
	SITEM* si;

    si = &sitem;
    
    if ((si->mw.flg & 0x1))
    {
        sys->sb_rdp = si->keep;
        sys->sb_rdid = si->mw.rdid;
        
        sys->sb_ppp = NULL;
        
        *(int*)&sys->mn_mode0 = 6;
        
        si->mw.flg &= ~0x1;
        
        si->mw.flg |= 0x2;
    }
    
    if ((sys->sb_ppp != NULL) && ((si->mw.flg & 0x2))) 
    {
        si->mw.flg &= ~0x2;
        
        si->mw.mdl_p = sys->sb_mlb;
        si->mw.tex_p = sys->sb_ppp;
        
        si->keep += sys->sb_rdsz;
        
        swork.statusflg |= 0x400;
    }
}

// 100% matching!
void Model_Read_Set(S_WORK* st)
{
    SITEM* si;
	DSP_WORK* dw;
    unsigned char idx; // not from DWARF

    si = &sitem;

    if ((swork.statusflg & 0x400)) 
    {
        bhMlbBinRealize(si->mw.mdl_p, &si->mdl);
        
        bhSetMemPvpTexture(si->mdl.texP, si->mw.tex_p, 0);
        
        si->keep = bhKeepObjWork(&si->mdl, si->keep);
        
        swork.statusflg |= 0x200000;
        
        swork.statusflg &= ~0x400;
        
        CameraInit();
        
        st->subcsr = 0;
        
        if (si->mw.rdid == 139) 
        {
            st->itemid = 139;
        }
        
        dw = &dsptbl[st->itemid];
        
        FlagErase(si->mdl.objP);
        
        if (dw->hide != 0) 
        {
            MdlEvalflagsSet(dw->hide);
        }
        
        if (st->itemid == 55) 
        {
            LighterOpen(si->mdl.objP->child->child);
        }
        
        if (st->itemid == 139) 
        {
            FileSyu(si->mdl.objP->child);
        }
        
        testf = ModelScaleSet(si, itemflg[dw->hide][3]);
        
        idx = itemflg[dw->hide][2];
        
        si->mw.pos.x = hoseipos[idx].x;
        si->mw.pos.y = hoseipos[idx].y;
        si->mw.pos.z = hoseipos[idx].z;
        
        si->mw.ax1 = 0;
        si->mw.ay1 = 0;
        si->mw.az1 = 0;
    }
    
    if ((st->subscreenmode & 0x8))
    {
        if ((swork.statusflg & 0x200000)) 
        {
            swork.statusflg |= 0x10;
            
            swork.statusflg &= ~0x80;
            swork.statusflg &= ~0x200000;
            
            swork.statusflg |= 0x10000;
        }
    } 
    else if (((swork.statusflg & 0x8000)) && ((swork.statusflg & 0x200000))) 
    {
        swork.statusflg |= 0x10;
        
        swork.statusflg &= ~0x200000;
        
        swork.statusflg |= 0x10000;
        
        swork.statusflg &= ~0x80;
        swork.statusflg &= ~0x8000;
    }
}

// 100% matching!
void CameraInit()
{
    njUnitMatrix(&st_cam.cmat1);
    njUnitMatrix(&st_cam.rotmat);
    
    st_cam.dis = 20;
    
    st_cam.pos_0.x = 0;
    st_cam.pos_0.y = 0;
    st_cam.pos_0.z = 12;
    
    st_cam.pos_1.x = 0;
    st_cam.pos_1.y = 0;
    st_cam.pos_1.z = 0;
    
    st_cam.ax = 0;
    st_cam.ay = 0;
    st_cam.az = 0;
    
    st_cam.cax = 0;
    st_cam.cay = 0;
    st_cam.caz = 0;
}

// 99.64% matching
void CameraSet()
{
    njClearMatrix();
    
    njUnitMatrix(NULL);
    
    njTranslate(NULL, st_cam.pos_0.x, st_cam.pos_0.y, -st_cam.pos_0.z + st_cam.pos_1.z);
    
    njRotateX(NULL, st_cam.ax);
    njRotateY(NULL, st_cam.ay);
    njRotateZ(NULL, st_cam.az);
    
    njTranslate(NULL, 0, 0, st_cam.dis);
    
    njGetMatrix(&st_cam.cmat1);
}

// 100% matching!
void ItemView()
{
	S_WORK* st;

    st = &swork;
    
    if (sitem.mw.rdid == 139)
    {
        st->itemid = 139;
    }
    
    switch (st->testmode)
    {
    case 0:
        if (st->itemid == 139)
        {
            st->testmode = 8;
        }
        else 
        {
            st->testmode = 2;
        }
        
        break;
    case 1:
        ItemModelChangeZoomIn();
        break;
    case 2:
        ItemModelCheck();
        break;
    case 4:
        ItemModelActionSet();
        break;
    case 5:
        ItemModelChangeZoomOut();
        break;
    case 6:
        ItemModelMessageWait();
        break;
    case 7:
        if (!(sys->st_flg & 0x200))
        {
            st->subscreenmode = 0x80;
            
            FileFlagInit();
            
            StatusToFileView();
            
            GetFile();
        }
        
        break;
    case 8:
        SelectFile();
        break;
    case 9:
        SelectTag();
        break;
    }
}

// 100% matching!
void ItemModelChangeZoomIn()
{
    S_WORK* st;
	STCAM_WRK* sc;

    st = &swork;
    sc = &st_cam;

    sc->pos_0.z += 3.2f;
    
    st->actioncount--;
    
    sitem.mw.ay1 += 4095;
    sitem.mw.az1 += 2047;
    
    if (st->actioncount == 0) 
    {
        sc->cay = 0;
        sc->caz = 0;
        
        st->testmode = 2;
        
        *wp_ = (st->ips1 << 16) | itemdata[st->ips1].max;
        
        bhSetMessage(1, getmestbl[st->mesid]);
            
        if (st->ips1 == 85)
        {
            st->testmode = 7;
        }
    }
}

// 
// Start address: 0x2aaa30
void ItemModelCheck()
{
	unsigned char chkcode;
	unsigned char y;
	unsigned char x;
	unsigned short mesnum;
	short* d_a;
	unsigned int* wp;
	int c01;
	int c00;
	DSP_WORK* dw;
	STCAM_WRK* sc;
	SITEM* si;
	S_WORK* st;
	short at_ang;
	// Line 656, Address: 0x2aaa30, Func Offset: 0
	// Line 660, Address: 0x2aaa5c, Func Offset: 0x2c
	// Line 657, Address: 0x2aaa64, Func Offset: 0x34
	// Line 658, Address: 0x2aaa6c, Func Offset: 0x3c
	// Line 671, Address: 0x2aaa74, Func Offset: 0x44
	// Line 660, Address: 0x2aaa7c, Func Offset: 0x4c
	// Line 671, Address: 0x2aaa8c, Func Offset: 0x5c
	// Line 659, Address: 0x2aaa90, Func Offset: 0x60
	// Line 660, Address: 0x2aaa94, Func Offset: 0x64
	// Line 659, Address: 0x2aaa98, Func Offset: 0x68
	// Line 668, Address: 0x2aaa9c, Func Offset: 0x6c
	// Line 671, Address: 0x2aaaa0, Func Offset: 0x70
	// Line 672, Address: 0x2aaaac, Func Offset: 0x7c
	// Line 673, Address: 0x2aaac0, Func Offset: 0x90
	// Line 676, Address: 0x2aaad8, Func Offset: 0xa8
	// Line 677, Address: 0x2aaae8, Func Offset: 0xb8
	// Line 679, Address: 0x2aaaf8, Func Offset: 0xc8
	// Line 677, Address: 0x2aab08, Func Offset: 0xd8
	// Line 680, Address: 0x2aab14, Func Offset: 0xe4
	// Line 681, Address: 0x2aab1c, Func Offset: 0xec
	// Line 682, Address: 0x2aab24, Func Offset: 0xf4
	// Line 683, Address: 0x2aab2c, Func Offset: 0xfc
	// Line 684, Address: 0x2aab34, Func Offset: 0x104
	// Line 685, Address: 0x2aab3c, Func Offset: 0x10c
	// Line 686, Address: 0x2aab44, Func Offset: 0x114
	// Line 687, Address: 0x2aab4c, Func Offset: 0x11c
	// Line 688, Address: 0x2aab54, Func Offset: 0x124
	// Line 689, Address: 0x2aab5c, Func Offset: 0x12c
	// Line 690, Address: 0x2aab64, Func Offset: 0x134
	// Line 691, Address: 0x2aab6c, Func Offset: 0x13c
	// Line 692, Address: 0x2aab84, Func Offset: 0x154
	// Line 693, Address: 0x2aab8c, Func Offset: 0x15c
	// Line 694, Address: 0x2aab98, Func Offset: 0x168
	// Line 695, Address: 0x2aaba0, Func Offset: 0x170
	// Line 696, Address: 0x2aaba4, Func Offset: 0x174
	// Line 697, Address: 0x2aabb8, Func Offset: 0x188
	// Line 698, Address: 0x2aabc0, Func Offset: 0x190
	// Line 699, Address: 0x2aabcc, Func Offset: 0x19c
	// Line 700, Address: 0x2aabd4, Func Offset: 0x1a4
	// Line 701, Address: 0x2aabd8, Func Offset: 0x1a8
	// Line 702, Address: 0x2aabe0, Func Offset: 0x1b0
	// Line 705, Address: 0x2aabe4, Func Offset: 0x1b4
	// Line 706, Address: 0x2aac04, Func Offset: 0x1d4
	// Line 707, Address: 0x2aac0c, Func Offset: 0x1dc
	// Line 708, Address: 0x2aac18, Func Offset: 0x1e8
	// Line 709, Address: 0x2aac20, Func Offset: 0x1f0
	// Line 710, Address: 0x2aac24, Func Offset: 0x1f4
	// Line 711, Address: 0x2aac38, Func Offset: 0x208
	// Line 712, Address: 0x2aac40, Func Offset: 0x210
	// Line 713, Address: 0x2aac4c, Func Offset: 0x21c
	// Line 714, Address: 0x2aac54, Func Offset: 0x224
	// Line 715, Address: 0x2aac58, Func Offset: 0x228
	// Line 716, Address: 0x2aac60, Func Offset: 0x230
	// Line 719, Address: 0x2aac64, Func Offset: 0x234
	// Line 720, Address: 0x2aac84, Func Offset: 0x254
	// Line 721, Address: 0x2aac90, Func Offset: 0x260
	// Line 722, Address: 0x2aacb0, Func Offset: 0x280
	// Line 724, Address: 0x2aacc4, Func Offset: 0x294
	// Line 725, Address: 0x2aacd8, Func Offset: 0x2a8
	// Line 726, Address: 0x2aacf8, Func Offset: 0x2c8
	// Line 799, Address: 0x2aad0c, Func Offset: 0x2dc
	// Line 800, Address: 0x2aad14, Func Offset: 0x2e4
	// Line 801, Address: 0x2aad18, Func Offset: 0x2e8
	// Line 802, Address: 0x2aad1c, Func Offset: 0x2ec
	// Line 803, Address: 0x2aad20, Func Offset: 0x2f0
	// Line 804, Address: 0x2aad40, Func Offset: 0x310
	// Line 805, Address: 0x2aad48, Func Offset: 0x318
	// Line 807, Address: 0x2aad50, Func Offset: 0x320
	// Line 804, Address: 0x2aad58, Func Offset: 0x328
	// Line 805, Address: 0x2aad68, Func Offset: 0x338
	// Line 807, Address: 0x2aad7c, Func Offset: 0x34c
	// Line 808, Address: 0x2aad94, Func Offset: 0x364
	// Line 809, Address: 0x2aad98, Func Offset: 0x368
	// Line 810, Address: 0x2aada0, Func Offset: 0x370
	// Line 811, Address: 0x2aada8, Func Offset: 0x378
	// Line 812, Address: 0x2aadc4, Func Offset: 0x394
	// Line 813, Address: 0x2aadd4, Func Offset: 0x3a4
	// Line 815, Address: 0x2aade8, Func Offset: 0x3b8
	// Line 814, Address: 0x2aadec, Func Offset: 0x3bc
	// Line 815, Address: 0x2aadf4, Func Offset: 0x3c4
	// Line 816, Address: 0x2aae08, Func Offset: 0x3d8
	// Line 817, Address: 0x2aae30, Func Offset: 0x400
	// Line 820, Address: 0x2aae38, Func Offset: 0x408
	// Line 824, Address: 0x2aae70, Func Offset: 0x440
	// Line 826, Address: 0x2aae74, Func Offset: 0x444
	// Line 827, Address: 0x2aae84, Func Offset: 0x454
	// Line 829, Address: 0x2aae98, Func Offset: 0x468
	// Line 827, Address: 0x2aae9c, Func Offset: 0x46c
	// Line 829, Address: 0x2aaea0, Func Offset: 0x470
	// Line 830, Address: 0x2aaed4, Func Offset: 0x4a4
	// Line 832, Address: 0x2aaee4, Func Offset: 0x4b4
	// Line 833, Address: 0x2aaef4, Func Offset: 0x4c4
	// Line 834, Address: 0x2aaf00, Func Offset: 0x4d0
	// Line 835, Address: 0x2aaf08, Func Offset: 0x4d8
	// Line 838, Address: 0x2aaf14, Func Offset: 0x4e4
	// Line 839, Address: 0x2aaf1c, Func Offset: 0x4ec
	// Line 840, Address: 0x2aaf38, Func Offset: 0x508
	// Line 841, Address: 0x2aaf44, Func Offset: 0x514
	// Line 845, Address: 0x2aaf64, Func Offset: 0x534
	// Line 846, Address: 0x2aaf78, Func Offset: 0x548
	// Line 847, Address: 0x2aaf7c, Func Offset: 0x54c
	// Line 848, Address: 0x2aaf80, Func Offset: 0x550
	// Line 846, Address: 0x2aaf84, Func Offset: 0x554
	// Line 847, Address: 0x2aaf88, Func Offset: 0x558
	// Line 849, Address: 0x2aaf8c, Func Offset: 0x55c
	// Line 850, Address: 0x2aaf94, Func Offset: 0x564
	// Line 851, Address: 0x2aaf9c, Func Offset: 0x56c
	// Line 852, Address: 0x2aafa4, Func Offset: 0x574
	// Line 853, Address: 0x2aafb4, Func Offset: 0x584
	// Line 857, Address: 0x2aafb8, Func Offset: 0x588
	// Line 859, Address: 0x2aafc0, Func Offset: 0x590
	// Line 860, Address: 0x2aafcc, Func Offset: 0x59c
	// Line 861, Address: 0x2aafd4, Func Offset: 0x5a4
	// Line 862, Address: 0x2aafdc, Func Offset: 0x5ac
	// Line 863, Address: 0x2aaff8, Func Offset: 0x5c8
	// Line 864, Address: 0x2ab000, Func Offset: 0x5d0
	// Line 865, Address: 0x2ab008, Func Offset: 0x5d8
	// Line 869, Address: 0x2ab014, Func Offset: 0x5e4
	// Line 870, Address: 0x2ab028, Func Offset: 0x5f8
	// Line 871, Address: 0x2ab030, Func Offset: 0x600
	// Line 872, Address: 0x2ab034, Func Offset: 0x604
	// Line 873, Address: 0x2ab03c, Func Offset: 0x60c
	// Line 874, Address: 0x2ab040, Func Offset: 0x610
	// Line 875, Address: 0x2ab04c, Func Offset: 0x61c
	// Line 874, Address: 0x2ab050, Func Offset: 0x620
	// Line 875, Address: 0x2ab05c, Func Offset: 0x62c
	// Line 876, Address: 0x2ab068, Func Offset: 0x638
	// Line 877, Address: 0x2ab070, Func Offset: 0x640
	// Line 878, Address: 0x2ab078, Func Offset: 0x648
	// Line 883, Address: 0x2ab0a0, Func Offset: 0x670
	// Line 884, Address: 0x2ab0a8, Func Offset: 0x678
	// Line 885, Address: 0x2ab0ac, Func Offset: 0x67c
	// Line 886, Address: 0x2ab0b0, Func Offset: 0x680
	// Line 888, Address: 0x2ab0b4, Func Offset: 0x684
	// Func End, Address: 0x2ab0e4, Func Offset: 0x6b4
	scePrintf("ItemModelCheck - UNIMPLEMENTED!\n");
}

// 100% matching!
void ItemModelActionSet() 
{
    S_WORK* st;
    DSP_WORK* dw;

    st = &swork;
    
    dw = (DSP_WORK*)&dsptbl[st->itemid];
	
    swork.statusflg |= 0x20000000;
    
    if ((actionprg - 1)[itemflg[dw->hide][1]](&sitem))
    {
        st->testmode = 5;
        
        st->actioncount = 32;
    }
}

// 
// Start address: 0x2ab1a0
void ItemModelChangeZoomOut()
{
	int chkang;
	DSP_WORK* dw;
	SITEM* si;
	STCAM_WRK* sc;
	S_WORK* st;
	// Line 906, Address: 0x2ab1a0, Func Offset: 0
	// Line 915, Address: 0x2ab1b8, Func Offset: 0x18
	// Line 907, Address: 0x2ab1c0, Func Offset: 0x20
	// Line 908, Address: 0x2ab1c8, Func Offset: 0x28
	// Line 916, Address: 0x2ab1d0, Func Offset: 0x30
	// Line 909, Address: 0x2ab1d8, Func Offset: 0x38
	// Line 915, Address: 0x2ab1e0, Func Offset: 0x40
	// Line 918, Address: 0x2ab1e4, Func Offset: 0x44
	// Line 915, Address: 0x2ab1ec, Func Offset: 0x4c
	// Line 916, Address: 0x2ab1f4, Func Offset: 0x54
	// Line 918, Address: 0x2ab200, Func Offset: 0x60
	// Line 916, Address: 0x2ab204, Func Offset: 0x64
	// Line 918, Address: 0x2ab208, Func Offset: 0x68
	// Line 919, Address: 0x2ab210, Func Offset: 0x70
	// Line 921, Address: 0x2ab218, Func Offset: 0x78
	// Line 919, Address: 0x2ab220, Func Offset: 0x80
	// Line 916, Address: 0x2ab224, Func Offset: 0x84
	// Line 919, Address: 0x2ab22c, Func Offset: 0x8c
	// Line 921, Address: 0x2ab230, Func Offset: 0x90
	// Line 924, Address: 0x2ab238, Func Offset: 0x98
	// Line 927, Address: 0x2ab240, Func Offset: 0xa0
	// Line 924, Address: 0x2ab248, Func Offset: 0xa8
	// Line 927, Address: 0x2ab258, Func Offset: 0xb8
	// Line 928, Address: 0x2ab264, Func Offset: 0xc4
	// Line 927, Address: 0x2ab26c, Func Offset: 0xcc
	// Line 929, Address: 0x2ab278, Func Offset: 0xd8
	// Line 927, Address: 0x2ab280, Func Offset: 0xe0
	// Line 928, Address: 0x2ab290, Func Offset: 0xf0
	// Line 929, Address: 0x2ab2a4, Func Offset: 0x104
	// Line 932, Address: 0x2ab2b0, Func Offset: 0x110
	// Line 933, Address: 0x2ab2bc, Func Offset: 0x11c
	// Line 934, Address: 0x2ab2c4, Func Offset: 0x124
	// Line 936, Address: 0x2ab2d0, Func Offset: 0x130
	// Line 934, Address: 0x2ab2d8, Func Offset: 0x138
	// Line 936, Address: 0x2ab2e0, Func Offset: 0x140
	// Line 938, Address: 0x2ab300, Func Offset: 0x160
	// Line 939, Address: 0x2ab308, Func Offset: 0x168
	// Line 940, Address: 0x2ab328, Func Offset: 0x188
	// Line 939, Address: 0x2ab338, Func Offset: 0x198
	// Line 943, Address: 0x2ab34c, Func Offset: 0x1ac
	// Line 939, Address: 0x2ab350, Func Offset: 0x1b0
	// Line 940, Address: 0x2ab354, Func Offset: 0x1b4
	// Line 941, Address: 0x2ab358, Func Offset: 0x1b8
	// Line 940, Address: 0x2ab368, Func Offset: 0x1c8
	// Line 942, Address: 0x2ab374, Func Offset: 0x1d4
	// Line 940, Address: 0x2ab378, Func Offset: 0x1d8
	// Line 941, Address: 0x2ab390, Func Offset: 0x1f0
	// Line 943, Address: 0x2ab3b8, Func Offset: 0x218
	// Line 944, Address: 0x2ab3c0, Func Offset: 0x220
	// Line 946, Address: 0x2ab3c8, Func Offset: 0x228
	// Line 947, Address: 0x2ab3cc, Func Offset: 0x22c
	// Line 948, Address: 0x2ab3d0, Func Offset: 0x230
	// Line 949, Address: 0x2ab3d4, Func Offset: 0x234
	// Line 952, Address: 0x2ab3fc, Func Offset: 0x25c
	// Line 953, Address: 0x2ab400, Func Offset: 0x260
	// Line 954, Address: 0x2ab408, Func Offset: 0x268
	// Line 957, Address: 0x2ab410, Func Offset: 0x270
	// Line 958, Address: 0x2ab414, Func Offset: 0x274
	// Line 959, Address: 0x2ab418, Func Offset: 0x278
	// Line 960, Address: 0x2ab41c, Func Offset: 0x27c
	// Line 962, Address: 0x2ab428, Func Offset: 0x288
	// Func End, Address: 0x2ab444, Func Offset: 0x2a4
	scePrintf("ItemModelChangeZoomOut - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ab450
void ItemModelMessageWait()
{
	DSP_WORK* dw;
	S_WORK* st;
	// Line 966, Address: 0x2ab450, Func Offset: 0
	// Line 965, Address: 0x2ab45c, Func Offset: 0xc
	// Line 966, Address: 0x2ab460, Func Offset: 0x10
	// Line 968, Address: 0x2ab464, Func Offset: 0x14
	// Line 966, Address: 0x2ab46c, Func Offset: 0x1c
	// Line 968, Address: 0x2ab474, Func Offset: 0x24
	// Line 969, Address: 0x2ab494, Func Offset: 0x44
	// Line 970, Address: 0x2ab49c, Func Offset: 0x4c
	// Line 969, Address: 0x2ab4a4, Func Offset: 0x54
	// Line 970, Address: 0x2ab4ac, Func Offset: 0x5c
	// Line 971, Address: 0x2ab4b0, Func Offset: 0x60
	// Line 970, Address: 0x2ab4b4, Func Offset: 0x64
	// Line 971, Address: 0x2ab4b8, Func Offset: 0x68
	// Line 970, Address: 0x2ab4bc, Func Offset: 0x6c
	// Line 971, Address: 0x2ab4c4, Func Offset: 0x74
	// Line 973, Address: 0x2ab4f0, Func Offset: 0xa0
	// Line 975, Address: 0x2ab4f4, Func Offset: 0xa4
	// Line 973, Address: 0x2ab4fc, Func Offset: 0xac
	// Line 975, Address: 0x2ab500, Func Offset: 0xb0
	// Line 976, Address: 0x2ab518, Func Offset: 0xc8
	// Line 977, Address: 0x2ab51c, Func Offset: 0xcc
	// Line 978, Address: 0x2ab524, Func Offset: 0xd4
	// Line 979, Address: 0x2ab52c, Func Offset: 0xdc
	// Line 981, Address: 0x2ab530, Func Offset: 0xe0
	// Line 983, Address: 0x2ab538, Func Offset: 0xe8
	// Line 987, Address: 0x2ab540, Func Offset: 0xf0
	// Func End, Address: 0x2ab548, Func Offset: 0xf8
	scePrintf("ItemModelMessageWait - UNIMPLEMENTED!\n");
}

// 100% matching!
unsigned char MdlDirChk(short* dirang, short mdlang) 
{ 
    int ang; // not from DWARF
    
    if (dirang[0] != 0) 
    {
        mdlang = (mdlang + dirang[0]) & 0xFFFF;
        ang = mdlang - dirang[1];
        
        if ((ang & 0xFFFF) > ((short)dirang[0] * 2)) 
        {
            return 0;
        }
        
        return 1;
    }

    return 1;
} 

// 100% matching!
unsigned char MdlAction00(SITEM* si)
{
    switch (swork.maincsr) 
    {                
    case 0:
        swork.maincsr = 2;
        break;
    case 1:
        break;
    case 2:
        si->mdl.objP->child->child->child->ang[0] += 1456;
        si->mdl.objP->child->ang[0] -= 728;
        
        if (si->mdl.objP->child->child->child->ang[0] >= 32768) 
        {
            swork.maincsr = 3;
        }
        
        if (si->mw.pos.y > -0.76f) 
        {
            si->mw.pos.y -= 0.05f;
            
            if (si->mw.pos.y < -0.76f) 
            {
                si->mw.pos.y = -0.76f;
            }
        }
        
        break;
    case 3:
        return 1;
    }

    return 0;
}

// 100% matching!
unsigned char MdlAction01(SITEM* si) 
{
    switch (swork.maincsr) 
    {                        
    case 0:                                         
        swork.maincsr = 1;
    case 1:                                         
        if (swork.itemid == 128)
        {                                  
            si->mdl.objP->child->child->child->child->child->ang[0] += 1456;
            si->mdl.objP->child->ang[0] -= 728;
            
            if (si->mdl.objP->child->child->child->child->child->ang[0] >= 32768) 
            {
                swork.maincsr = 2;
            }
        }
        else if (swork.itemid == 63)
        {  
            si->mdl.objP->child->child->child->child->ang[0] += 1456;
            si->mdl.objP->child->ang[0] -= 728;
            
            if (si->mdl.objP->child->child->child->child->ang[0] >= 32768) 
            {
                swork.maincsr = 2;
            }
        }
        else if (swork.itemid == 129) 
        {  
            si->mdl.objP->child->child->child->ang[0] += 1456;
            si->mdl.objP->child->ang[0] -= 728;
            
            if (si->mdl.objP->child->child->child->ang[0] >= 32768) 
            {
                swork.maincsr = 2;
            }
        }
        else
        {                                    
            si->mdl.objP->child->child->child->ang[0] += 1456;
            si->mdl.objP->child->ang[0] -= 728;
            
            if (si->mdl.objP->child->child->child->ang[0] >= 32768) 
            {
                swork.maincsr = 2;
            }
        }
        
        if (si->mw.pos.y > -0.76f) 
        {
            si->mw.pos.y -= 0.05f;
            
            if (si->mw.pos.y < -0.76f) 
            {
                si->mw.pos.y = -0.76f;
            }
        }

        break;
    case 2:                                         
        return 1;
    }

    return 0;
}

// 100% matching!
unsigned char MdlAction02(SITEM* si)
{
    switch (swork.maincsr) 
    {                   
    case 0:
        swork.maincsr = 1;
    case 1:
        si->mdl.objP->child->child->child->ang[2] += 1456;
        si->mdl.objP->child->ang[2] -= 728;
        
        if (si->mdl.objP->child->child->child->ang[2] >= 32768) 
        {
            swork.maincsr = 2;
        }
        
        if (si->mw.pos.y > -0.76f) 
        {
            si->mw.pos.y -= 0.05f;
            
            if (si->mw.pos.y < -0.76f) 
            {
                si->mw.pos.y = -0.76f;
            }
        }
        
        break;
    case 2:
        return 1;
    }

    return 0;
}

// 100% matching!
void MdlEvalflagsSet(unsigned short evalchk)
{
	MdlHideCheck(sitem.mdl.objP, itemflg[(unsigned short)evalchk][0], 1);
}

// 100% matching!
void MdlHideCheck(NJS_CNK_OBJECT* op, unsigned char el, unsigned char chk)
{
    if (el & chk) 
    {
        op->evalflags |= 0x8;
        
        el &= ~chk;
        
        chk *= 2;
        
        if ((el != 0) && (op->child != NULL)) 
        {
            MdlHideCheck(op->child, el, chk);
        } 
        
        if ((el != 0) && (op->sibling != NULL))
        {
            MdlHideCheck(op->sibling, el, chk);
        }
    }
    else if (el) 
    {
        chk *= 2;
        
        if (op->child != NULL)
        { 
            MdlHideCheck(op->child, el, chk);
        }
        
        if (op->sibling != NULL) 
        {
            MdlHideCheck(op->sibling, el, chk);
        }
    }
}

// 100% matching!
float ModelScaleSet(SITEM* itemmodel, int flg)
{
    float scale00;

    if (flg != 0) 
    {
        itemmodel->mdl.objP->pos[2] = itemmodel->mdl.objP->pos[1] = itemmodel->mdl.objP->pos[0] = 0;

        itemmodel->mdl.objP->child->pos[2] = itemmodel->mdl.objP->child->pos[1] = itemmodel->mdl.objP->child->pos[0] = 0;
    }
    
    npGetWHDSize(itemmodel->mdl.objP, &whd);
    
    scale00 = njScalor(&whd);
   
    if ((itemmodel->mw.rdid != 1) && (itemmodel->mw.rdid != 2) && (itemmodel->mw.rdid != 3) && (itemmodel->mw.rdid != 4) && (itemmodel->mw.rdid != 6) && (itemmodel->mw.rdid != 10) && (itemmodel->mw.rdid != 11) && (itemmodel->mw.rdid != 103)) 
    {
        return 1.52f / scale00;
    }
    
    return 1.84f / scale00;
}

// 100% matching! 
void FlagErase(NJS_CNK_OBJECT* op) 
{
    op->evalflags &= ~0x2;
    op->evalflags &= ~0x1;
    
    if (op->child != NULL) 
    {
        FlagErase(op->child);
    }

    if (op->sibling != NULL) 
    {
        FlagErase(op->sibling);
    }
}

// 100% matching!
void LighterOpen(NJS_CNK_OBJECT* object) 
{
    object->ang[2] = 29127;
}

// 100% matching!
void FileSyu(NJS_CNK_OBJECT* op)
{
    op->ang[0] = 32768;
    op->ang[1] = 32768;
    
    op->sibling->ang[0] = 32768;
    op->sibling->sibling->ang[0] = 32768;
    
    op->sibling->ang[1] = 32768;
    op->sibling->sibling->ang[1] = 32768;
}

// 
// Start address: 0x2abd20
void MakeTag(NJS_CNK_OBJECT* param, unsigned short flg) // first parameter is not present on DWARF
{
	float zpos;
	float ypos;
	int tagcol;
	int i;
	//_anon38 p3c;
	//_anon18 col[4];
	NJS_POINT3 p[4];
	FV_WORK* fv;
	S_WORK* st;
	// Line 1254, Address: 0x2abd20, Func Offset: 0
	// Line 1256, Address: 0x2abd3c, Func Offset: 0x1c
	// Line 1258, Address: 0x2abd44, Func Offset: 0x24
	// Line 1254, Address: 0x2abd4c, Func Offset: 0x2c
	// Line 1275, Address: 0x2abd50, Func Offset: 0x30
	// Line 1254, Address: 0x2abd54, Func Offset: 0x34
	// Line 1277, Address: 0x2abd58, Func Offset: 0x38
	// Line 1275, Address: 0x2abd5c, Func Offset: 0x3c
	// Line 1277, Address: 0x2abd60, Func Offset: 0x40
	// Line 1275, Address: 0x2abd64, Func Offset: 0x44
	// Line 1278, Address: 0x2abd74, Func Offset: 0x54
	// Line 1277, Address: 0x2abd78, Func Offset: 0x58
	// Line 1278, Address: 0x2abd84, Func Offset: 0x64
	// Line 1279, Address: 0x2abd98, Func Offset: 0x78
	// Line 1282, Address: 0x2abdac, Func Offset: 0x8c
	// Line 1284, Address: 0x2abdb0, Func Offset: 0x90
	// Line 1285, Address: 0x2abdd4, Func Offset: 0xb4
	// Line 1286, Address: 0x2abde4, Func Offset: 0xc4
	// Line 1289, Address: 0x2abe04, Func Offset: 0xe4
	// Line 1290, Address: 0x2abe0c, Func Offset: 0xec
	// Line 1292, Address: 0x2abe10, Func Offset: 0xf0
	// Line 1293, Address: 0x2abe18, Func Offset: 0xf8
	// Line 1295, Address: 0x2abe20, Func Offset: 0x100
	// Line 1298, Address: 0x2abe54, Func Offset: 0x134
	// Line 1299, Address: 0x2abe5c, Func Offset: 0x13c
	// Line 1303, Address: 0x2abe60, Func Offset: 0x140
	// Line 1304, Address: 0x2abe68, Func Offset: 0x148
	// Line 1306, Address: 0x2abe70, Func Offset: 0x150
	// Line 1305, Address: 0x2abe74, Func Offset: 0x154
	// Line 1306, Address: 0x2abe78, Func Offset: 0x158
	// Line 1309, Address: 0x2abe7c, Func Offset: 0x15c
	// Line 1308, Address: 0x2abe80, Func Offset: 0x160
	// Line 1310, Address: 0x2abe84, Func Offset: 0x164
	// Line 1309, Address: 0x2abe88, Func Offset: 0x168
	// Line 1310, Address: 0x2abe8c, Func Offset: 0x16c
	// Line 1311, Address: 0x2abe90, Func Offset: 0x170
	// Line 1312, Address: 0x2abe94, Func Offset: 0x174
	// Line 1340, Address: 0x2abea0, Func Offset: 0x180
	// Line 1314, Address: 0x2abea4, Func Offset: 0x184
	// Line 1311, Address: 0x2abea8, Func Offset: 0x188
	// Line 1312, Address: 0x2abeac, Func Offset: 0x18c
	// Line 1314, Address: 0x2abeb0, Func Offset: 0x190
	// Line 1321, Address: 0x2abeb8, Func Offset: 0x198
	// Line 1312, Address: 0x2abebc, Func Offset: 0x19c
	// Line 1313, Address: 0x2abec4, Func Offset: 0x1a4
	// Line 1314, Address: 0x2abecc, Func Offset: 0x1ac
	// Line 1315, Address: 0x2abed8, Func Offset: 0x1b8
	// Line 1316, Address: 0x2abee4, Func Offset: 0x1c4
	// Line 1317, Address: 0x2abeec, Func Offset: 0x1cc
	// Line 1318, Address: 0x2abef8, Func Offset: 0x1d8
	// Line 1319, Address: 0x2abf00, Func Offset: 0x1e0
	// Line 1321, Address: 0x2abf04, Func Offset: 0x1e4
	// Line 1322, Address: 0x2abf08, Func Offset: 0x1e8
	// Line 1323, Address: 0x2abf0c, Func Offset: 0x1ec
	// Line 1324, Address: 0x2abf10, Func Offset: 0x1f0
	// Line 1326, Address: 0x2abf14, Func Offset: 0x1f4
	// Line 1327, Address: 0x2abf18, Func Offset: 0x1f8
	// Line 1328, Address: 0x2abf1c, Func Offset: 0x1fc
	// Line 1329, Address: 0x2abf20, Func Offset: 0x200
	// Line 1331, Address: 0x2abf24, Func Offset: 0x204
	// Line 1332, Address: 0x2abf28, Func Offset: 0x208
	// Line 1333, Address: 0x2abf2c, Func Offset: 0x20c
	// Line 1334, Address: 0x2abf30, Func Offset: 0x210
	// Line 1336, Address: 0x2abf34, Func Offset: 0x214
	// Line 1337, Address: 0x2abf38, Func Offset: 0x218
	// Line 1338, Address: 0x2abf3c, Func Offset: 0x21c
	// Line 1319, Address: 0x2abf40, Func Offset: 0x220
	// Line 1340, Address: 0x2abf44, Func Offset: 0x224
	// Line 1341, Address: 0x2abf4c, Func Offset: 0x22c
	// Line 1342, Address: 0x2abf5c, Func Offset: 0x23c
	// Line 1343, Address: 0x2abf64, Func Offset: 0x244
	// Line 1344, Address: 0x2abf68, Func Offset: 0x248
	// Line 1346, Address: 0x2abf74, Func Offset: 0x254
	// Line 1344, Address: 0x2abf78, Func Offset: 0x258
	// Line 1345, Address: 0x2abf7c, Func Offset: 0x25c
	// Line 1346, Address: 0x2abf88, Func Offset: 0x268
	// Line 1348, Address: 0x2abf94, Func Offset: 0x274
	// Func End, Address: 0x2abfbc, Func Offset: 0x29c
	scePrintf("MakeTag - UNIMPLEMENTED!\n");
}
