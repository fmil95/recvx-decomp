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

// 100% matching!
void ItemModelCheck() 
{
    S_WORK* st;            
    SITEM* si;            
    STCAM_WRK* sc;     
    DSP_WORK* dw;       
    int c00, c01;             
    unsigned int* wp;    
    short* d_a;           
    unsigned short mesnum; 
    unsigned char x, y;       
    unsigned char chkcode; 
    static short at_ang;   

    st = &swork;
    si = &sitem; 
    sc = &st_cam; 
    
    dw = (DSP_WORK*)&dsptbl[st->itemid];
    
    x = 0;
    
    chkcode = 0;  
    
    if (!(sys->st_flg & 0x200)) 
    {
        if (!(swork.statusflg & 0x40)) 
        {
            if (!(sys->pad_ps & 0x1800)) 
            {
                swork.statusflg |= 0x100000;
                
                swork.statusflg &= ~0x20000000;
                
                parts_10b[11].col.r = 0.7f;
                parts_10b[11].col.g = 0.7f;
                parts_10b[11].col.b = 0.7f;
                
                parts_10b[11].col.r = 0.7f;
                parts_10b[12].col.g = 0.7f;
                parts_10b[12].col.b = 0.7f;
                
                parts_10b[13].col.r = 0.7f;
                parts_10b[13].col.g = 0.7f;
                parts_10b[13].col.b = 0.7f;
                
                parts_10b[14].col.r = 0.7f;
                parts_10b[14].col.g = 0.7f;
                parts_10b[14].col.b = 0.7f;
                
                if ((sys->pad_on & 0x4))
                {
                    sc->cay = -546;
                    
                    parts_10b[14].col.r = 1.0f;
                    parts_10b[14].col.g = 1.0f;
                    parts_10b[14].col.b = 1.0f;
                }
                else if ((sys->pad_on & 0x8)) 
                {
                    sc->cay = 546;
                    
                    parts_10b[13].col.r = 1.0f;
                    parts_10b[13].col.g = 1.0f;
                    parts_10b[13].col.b = 1.0f;
                } 
                else 
                {
                    sc->cay = 0;
                }
                
                if ((sys->pad_on & 0x1)) 
                {
                    sc->cax = 546;
                    
                    parts_10b[12].col.r = 1.0f;
                    parts_10b[12].col.g = 1.0f;
                    parts_10b[12].col.b = 1.0f;
                } 
                else if ((sys->pad_on & 0x2)) 
                {
                    sc->cax = -546;
                    
                    parts_10b[11].col.r = 1.0f;
                    parts_10b[11].col.g = 1.0f;
                    parts_10b[11].col.b = 1.0f;
                } 
                else 
                {
                    sc->cax = 0;
                }
                
                if ((sys->pad_on & 0x90))
                {
                    if ((sys->pad_on & 0x80))
                    {
                        if (sc->pos_1.z < 3.0f) 
                        {
                            sc->pos_1.z += 0.1f;
                        }
                    } 
                    else if (((sys->pad_on & 0x10)) && (sc->pos_1.z > -3.0f)) 
                    {
                        sc->pos_1.z -= 0.1f;
                    }
                }
            } 
            else
            {
                sc->cax = 0;
                sc->cay = 0;
                sc->caz = 0;
                
                if ((sys->pad_ps & 0x800)) 
                {
                    swork.statusflg |= 0x20000000;
                    
                    swork.statusflg &= ~0x100000;
                    
                    c01 = itemflg[dw->hide][4];
                    
                    c00 = c01 & 0xF;
                    c01 = (c01 & 0xF0) >> 4;
                    
                    if (c00 != 0)
                    {
                        for (x = 0; (x < c01) && (chkcode != 3); x++)
                        { 
                            d_a = (short*)c_a[c00 + x];
                            
                            for (y = 0, chkcode = 0; y < 3; y++)
                            {
                                chkcode += MdlDirChk(d_a, si->mw.ang[y]);
                                
                                d_a += 2;  
                            }
                        }
                        
                        x--;
                    }
                    
                    if ((st->itemid == 19) || ((st->itemid - 33) <= 1) || (st->itemid == 136) || (st->itemid == 142)) 
                    {
                        chkcode = 0;
                    }
                    
                    if (chkcode == 3) 
                    {
                        flg[2] = 0;
                        flg[1] = 0;
                        flg[0] = 0; 
                        
                        mesnum = mestbl[x + itemflg[dw->hide][5]];
                        
                        if ((mesnum & 0xFFF) == 181)
                        {
                            if (ItemSearch(50) != NULL) 
                            {
                                bhSetMessage(1, mesnum & 0xFFF);
                            } 
                            else 
                            {
                                bhSetMessage(1, 188);
                                
                                mesnum = 0;
                            }
                        }
                        else 
                        {
                            if (st->itemid != 106)
                            {
                                bhSetMessage(1, mesnum & 0xFFF);
                            }
                            
                            if ((mesnum & 0xFFF) == 72)
                            {
                                st->pip[st->listcsr_0] |= 0x80000000;
                            }
                        }
                        
                        if ((mesnum & 0xF000) == 0x2000) 
                        {
                            st->mesid = st->itemid;
                            
                            st->testmode = 4;
                            
                            at_ang = 0;
                        }
                        else if ((mesnum & 0xF000))
                        {
                            st->testmode = 6;
                            
                            if (st->itemid != 83)
                            {
                                at_ang = 0;
                            }
                        }
                    } 
                    else 
                    {
                        if (st->itemid != 82) 
                        {
                            bhSetMessage(1, st->itemid);
                            return;
                        }
                        
                        if ((unsigned char)st->pip[st->listcsr_0] != 0)
                        {
                            bhSetMessage(1, st->itemid);
                            return;
                        }
                        
                        bhSetMessage(1, 140);
                    }
                } 
                else if ((sys->pad_ps & 0x1000)) 
                {
                    st->mode = 1;
                    st->testmode = 1;
                    
                    NameChangeSet(st);
                    
                    st->wn = 0;
                    
                    swork.statusflg |= 0x20000;
                    
                    if (st->itemid == 30) 
                    {
                        wp = ItemSearch(st->itemid);
                        
                        st->itemid = 13;
                        
                        *wp = (st->itemid << 16) | itemdata[st->itemid].max;
                    }
                }
            }
        }
    } 
    else 
    {
        sc->cax = 0;
        sc->cay = 0;
        sc->caz = 0;
    }
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

// 100% matching!
void ItemModelChangeZoomOut()
{
    S_WORK* st;
    STCAM_WRK* sc;
    SITEM* si;
    DSP_WORK* dw;
    int chkang;
	
    st = &swork;
    sc = &st_cam;
    si = &sitem;

    st->actioncount--;
    
    sc->pos_0.z -= 3.2f;
    
    si->mw.ay1 += 4095;
    si->mw.az1 += 2047;
    
    if (st->actioncount == 0)
    {
        wp_ = &st->pip[st->listcsr_0];
        
        st->ips1 = st->itemid = idsettbl[st->mesid = itemflg[dsptbl[st->mesid].hide][6]];
        
        dw = (DSP_WORK*)&dsptbl[st->itemid];
        
        if (dw->hide != 0) 
        {
            MdlEvalflagsSet(dw->hide);
            
            dw = &dsptbl[st->itemid];
            
            testf = ModelScaleSet(si, itemflg[dw->hide][3]);
        }
        
        st->testmode = 1;
        
        si->mw.pos.x = hoseipos[itemflg[dw->hide][2]].x;
        si->mw.pos.y = hoseipos[itemflg[dw->hide][2]].y;
        si->mw.pos.z = hoseipos[itemflg[dw->hide][2]].z;
        
        st->actioncount = 32;
        
        njUnitMatrix(&sc->rotmat);
        njUnitMatrix(NULL);
        
        si->mw.ax1 = 0;
        si->mw.ay1 = 0;
        si->mw.az1 = 0;

        if ((st->itemid == 105) || (st->itemid == 30) || (st->itemid == 35))
        {
            chkang = 3;
        }
        else
        {
            chkang = 1;
        }
        
        st->subcsr = chkang;
        
        sc->pos_1.z = 0;
        
        sc->cay = 0;
        sc->caz = 0;
        
        si->mdl.objP->child->ang[0] = 0;
    }
}

// 100% matching!
void ItemModelMessageWait()
{
    S_WORK* st;
    DSP_WORK* dw;
	
    st = &swork;
    
    dw = (DSP_WORK*)&dsptbl[st->itemid];

    if (((sys->st_flg & 0x4000)) && ((sys->cb_flg & 0x1000))) 
    {
        sys->cb_flg &= ~0x1000;
        sys->st_flg &= ~0x200;
        
        switch (sys->mes_sel) 
        {                        
        case 100:
            st->mesid = st->itemid;
            
            if (itemflg[dw->hide][1] != 0) 
            {
                st->testmode = 4;
            } 
            else 
            {
                st->testmode = 5;
                
                st->actioncount = 32;
            } 
            
            break;
        case 101:
            st->testmode = 2;
            break;
        }
    }
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

// 100% matching!
void MakeTag(NJS_CNK_OBJECT* param, unsigned short flg) // first parameter is not present on DWARF
{
    S_WORK* st;     
    FV_WORK* fv;      
    NJS_POINT3 p[4]; 
    NJS_COLOR col[4]; 
    NJS_POINT3COL p3c;
    int i;             
    int tagcol;      
    float ypos, zpos;      

    st = &swork; 
    fv = &fvwork; 

    ypos = 1.2f;
    zpos = 0.04f;
    
    sys->itm[383] |= 0x1;
    
    if ((sys->ssd_flg & 0x1000)) 
    {
        sys->itm[383] |= 0x800;
    }

    for (i = 0; i < 8; i++) 
    {
        if (sys->itm[383] & (1 << (i + (unsigned int)(flg << 3)))) 
        {
            if (st->testmode == 9) 
            {
                if ((1 << (fv->tag + (fv->filecsr * 8))) & (sys->itm[383] & (1 << (i + (unsigned int)(flg << 3))))) 
                {
                    tagcol = 192;
                }
                else 
                {
                    tagcol = 128;
                }
            } 
            else 
            {
                SearchTag(1);
                
                if ((1 << (fv->tag + (fv->filecsr * 8))) & (sys->itm[383] & (1 << (i + (unsigned int)(flg << 3)))))
                {
                    tagcol = 192;
                }
                else 
                {
                    tagcol = 128;
                }
            }
            
            p3c.p = p;
            p3c.col = col;
            p3c.tex = NULL;
            p3c.num = 4;
            
            p[0].x = 0;
            p[0].y = ypos;
            p[0].z = zpos;
            
            p[1].x = p[0].x;
            p[1].y = 0.2f + p[0].y;
            p[1].z = p[0].z;
            
            p[2].x = 1.2f + p[0].x;
            p[2].y = 0.2f + p[0].y;
            p[2].z = p[0].z;
            
            p[3].x = 1.2f + p[0].x;
            p[3].y = p[0].y;
            p[3].z = p[0].z;
            
            col[0].argb.a = 0xFF;
            col[0].argb.b = col[0].argb.g = col[0].argb.r = tagcol;

            col[1].argb.a = 0xFF;
            col[1].argb.b = col[1].argb.g = col[1].argb.r = tagcol;

            col[2].argb.a = 0xFF;
            col[2].argb.b = col[2].argb.g = col[2].argb.r = tagcol;

            col[3].argb.a = 0xFF;
            col[3].argb.b = col[3].argb.g = col[3].argb.r = tagcol;

            njPushMatrix(NULL);
            
            njDrawPolygon3D(&p3c, 4, 32);
            
            njPopMatrix(1);
        }
        
        ypos -= 0.35f;
        zpos -= 0.02f;
    } 
}
