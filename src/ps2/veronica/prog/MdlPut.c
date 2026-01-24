#include "MdlPut.h"
#include "njplus.h"
#include "ps2_NaMatrix.h"
#include "ps2_NaTextureFunction.h"
#include "ps2_NinjaCnk.h"
#include "main.h"

void (*bhJumpCnkDraw[4])(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num) = 
{ 
	EasyMultiDrawTreeCnk, 
	SimpleMultiDrawTreeCnk, 
	EasyDrawTreeCnk, 
	SimpleDrawTreeCnk 
};

// 100% matching! 
void bhPutModel(BH_PWORK* ewP) 
{
    // these variables are arranged in an order different from the debugging symbols
    O_WORK* owP;       
    int draw_tp;       
    ML_WORK* mlwP;     
    unsigned int c3df; 
    
    mlwP = ewP->mlwP;
    owP = mlwP->owP;
    
    if (mlwP->texP != NULL) 
    {
        njSetTexture(mlwP->texP);
    }
    
    draw_tp = ewP->draw_tp;
    
    if (((sys->gm_flg & 0x80)) && (draw_tp < 2)) 
    {
        draw_tp += 2;
    }
    
    if ((mlwP->flg & 0x80))
    {
        if (ewP->skp[ewP->mdl_no] != NULL) 
        {
            npPushMdlstr(mlwP->objP, mlwP->obj_num);
            
            if ((ewP->mdflg & 0x100))
            {
                npCalcSkinFM(ewP, mlwP->obj_num, ewP->skp[ewP->mdl_no]);
            } 
            else 
            {
                npCalcSkin(ewP, mlwP->obj_num, ewP->skp[ewP->mdl_no]);
            }
            
            bhJumpCnkDraw[draw_tp](ewP, mlwP->objP, owP, mlwP->obj_num);
            
            if (((sys->st_flg & 0x100)) && (!(ewP->mdflg & 0x40))) 
            {
                njSetMatrix(cam.mtxb, cam.mtx);
                
                njMirror(cam.mtx, &sys->mr_pl);
                
                njSetMatrix(NULL, cam.mtx);
                
                njCnkSetEasyMultiLightMatrices();
                njCnkSetSimpleMultiLightMatrices();
                
                c3df = _nj_control_3d_flag_;
                
                njControl3D(c3df | 0x10000);
                
                bhJumpCnkDraw[draw_tp](ewP, mlwP->objP, owP, mlwP->obj_num);
                
                njControl3D(c3df);
                
                njSetMatrix(cam.mtx, cam.mtxb);
                njSetMatrix(NULL, cam.mtx);
                
                njCnkSetEasyMultiLightMatrices();
                njCnkSetSimpleMultiLightMatrices();
            }
            
            npPopMdlstr(mlwP->objP, mlwP->obj_num);
        }
        else 
        {
            bhJumpCnkDraw[draw_tp](ewP, mlwP->objP, owP, mlwP->obj_num);
            
            if (((sys->st_flg & 0x100)) && (!(ewP->mdflg & 0x40))) 
            {
                njSetMatrix(cam.mtxb, cam.mtx);
                
                njMirror(cam.mtx, &sys->mr_pl);
                
                njSetMatrix(NULL, cam.mtx);
                
                njCnkSetEasyMultiLightMatrices();
                njCnkSetSimpleMultiLightMatrices();

                c3df = _nj_control_3d_flag_;
                
                njControl3D(c3df | 0x10000);
                
                bhJumpCnkDraw[draw_tp](ewP, mlwP->objP, owP, mlwP->obj_num);
                
                njControl3D(c3df);
                
                njSetMatrix(cam.mtx, cam.mtxb);
                njSetMatrix(NULL, cam.mtx);
                
                njCnkSetEasyMultiLightMatrices();
                njCnkSetSimpleMultiLightMatrices();
            }
        }
    }
    else 
    {
        DrawTreeBsc(mlwP->objP, owP, mlwP->obj_num);
    }
}

// 100% matching!
static void DrawTreeBsc(NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num)
{
    for ( ; obj_num > 0; obj_num--, objP++, owP++) 
    {
        njPushMatrix(cam.mtx);
        njMultiMatrix(NULL, &owP->mtx);
        
        if ((objP->model != NULL) && (!(objP->evalflags & 0x8))) 
        {
            njDrawModel((NJS_MODEL*)objP->model);
        }
        
        njPopMatrixEx();
    } 
}

// 100% matching! 
static void EasyMultiDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num)
{
    for ( ; obj_num > 0; obj_num--, objP++, owP++) 
    {
        njPushMatrix(cam.mtx);
        
        if (!(objP->evalflags & 0x80000000))
        {
            njMultiMatrix(NULL, &owP->mtx);
        } 
        else 
        {
            njTranslate(NULL, ewP->px, ewP->py, ewP->pz);
        }
        
        if ((objP->model != NULL) && (!(objP->evalflags & 0x8)))
        {
            njCnkEasyMultiDrawModel(objP->model);
        }
        
        njPopMatrixEx();
    } 
}

// 100% matching! 
static void SimpleMultiDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num)
{
    for ( ; obj_num > 0; obj_num--, objP++, owP++) 
    {
        njPushMatrix(cam.mtx);
        
        if (!(objP->evalflags & 0x80000000))
        {
            njMultiMatrix(NULL, &owP->mtx);
        } 
        else 
        {
            njTranslate(NULL, ewP->px, ewP->py, ewP->pz);
        }
        
        if ((objP->model != NULL) && (!(objP->evalflags & 0x8)))
        {
            njCnkSimpleMultiDrawModel(objP->model);
        }
        
        njPopMatrixEx();
    } 
}

// 100% matching! 
static void EasyDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num)
{
    for ( ; obj_num > 0; obj_num--, objP++, owP++) 
    {
        njPushMatrix(cam.mtx);
        
        if (!(objP->evalflags & 0x80000000))
        {
            njMultiMatrix(NULL, &owP->mtx);
        } 
        else 
        {
            njTranslate(NULL, ewP->px, ewP->py, ewP->pz);
        }
        
        if ((objP->model != NULL) && (!(objP->evalflags & 0x8)))
        {
            njCnkEasyDrawModel(objP->model);
        }
        
        njPopMatrixEx();
    } 
}

// 100% matching! 
static void SimpleDrawTreeCnk(BH_PWORK* ewP, NJS_CNK_OBJECT* objP, O_WORK* owP, int obj_num)
{
    for ( ; obj_num > 0; obj_num--, objP++, owP++) 
    {
        njPushMatrix(cam.mtx);
        
        if (!(objP->evalflags & 0x80000000))
        {
            njMultiMatrix(NULL, &owP->mtx);
        } 
        else 
        {
            njTranslate(NULL, ewP->px, ewP->py, ewP->pz);
        }
        
        if ((objP->model != NULL) && (!(objP->evalflags & 0x8)))
        {
            njCnkSimpleDrawModel(objP->model);
        }
        
        njPopMatrixEx();
    } 
}

// 100% matching! 
void bhCalcModel(BH_PWORK* ewP) 
{
    if ((ewP->flg & 0x80))
    {
        njSetMatrix(ewP->mtx, &((BH_PWORK*)ewP->lkwkp)->mlwP->owP[ewP->lkono].mtx);
        
        njTranslate(ewP->mtx, ewP->lox, ewP->loy, ewP->loz);
        
        if ((ewP->flg & 0x1000)) 
        {
            njUnitRotPortion(ewP->mtx);
        }
        
        njRotateXYZ(ewP->mtx, ewP->ax, ewP->ay, ewP->az);
    }
    else if (!(ewP->flg & 0x1000))
    {
        njUnitMatrix(ewP->mtx);
        
        njTranslate(ewP->mtx, ewP->px, ewP->py, ewP->pz);
        
        njRotateXYZ(ewP->mtx, ewP->ax, ewP->ay, ewP->az);
    }
    
    bhCalcTree(ewP->mtx, ewP->mlwP);
}

// 100% matching!
void bhCalcTree(NJS_MATRIX* basP, ML_WORK* mlwP) 
{
    O_WORK* owP;
    NJS_CNK_OBJECT* objP;
    int obj_num;

    owP = mlwP->owP;
    objP = mlwP->objP;

    njPushMatrix(basP);

    if (basP == NULL)
    {
        njUnitMatrix(NULL);
    }

    obj_num = mlwP->obj_num;

    for ( ; obj_num > 0; obj_num--, objP++, owP++)
    {
        if (objP->sibling != NULL)
        {
            njPushMatrixEx();
        }

        njTranslate(NULL, objP->pos[0], objP->pos[1], objP->pos[2]);
        njRotateXYZ(NULL, objP->ang[0], objP->ang[1], objP->ang[2]);

        if (!(owP->flg & 0x1)) 
        {
            njGetMatrix(&owP->mtx);
        }
        else 
        {
            njSetMatrix(NULL, &owP->mtx);
        }

        if (objP->child == NULL)
        {
            njPopMatrixEx();
        }
    }

    njPopMatrixEx();
}
