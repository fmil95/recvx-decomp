#include "binfunc.h"

// 100% matching!
int bhMlbBinRealize(void* bin_datP, ML_WORK* mlwP)
{
    unsigned int obj_num; 
    unsigned int tex_off; 
    unsigned int obj_off; 
    unsigned int status;  
    NJS_CNK_OBJECT* objP; 
    NJS_TEXNAME* namP;    
    unsigned int tex_num; 

    status = ((char*)bin_datP)[3];
    
    obj_num = ((unsigned short*)bin_datP)[3];
    
    tex_off = ((int*)bin_datP)[2];
    obj_off = ((int*)bin_datP)[3];
    
    mlwP->flg = 0;
    
    mlwP->obj_num = 0;
    
    mlwP->datP = bin_datP;
    mlwP->objP = NULL;
    mlwP->texP = NULL;
    mlwP->owP = NULL;
    
    bin_datP = (void*)((char*)bin_datP + ((unsigned short*)bin_datP)[2]);
    
    if (obj_off != -1) 
    {
        mlwP->flg = status;
        
        objP = (NJS_CNK_OBJECT*)((int)bin_datP + obj_off);
        
        mlwP->obj_num = obj_num;
        mlwP->objP = objP;
        
        for ( ; obj_num != 0; obj_num--, objP++) 
        {
            if (objP->child != (void*)-1) 
            {
                objP->child = (void*)((int)objP->child + (int)bin_datP);
            } 
            else 
            {
                objP->child = NULL;
            }
            
            if (objP->sibling != (void*)-1) 
            {
                objP->sibling = (void*)((int)objP->sibling + (int)bin_datP);
            }
            else 
            {
                objP->sibling = NULL;
            }
            
            if (objP->model != (void*)-1) 
            {
                objP->model = (void*)((int)objP->model + (int)bin_datP);
                
                if (!(status & 0x80))
                {
                    bhBscBinRealize((NJS_MODEL*)objP->model, (unsigned int)bin_datP);
                } 
                else
                {
                    bhCnkBinRealize(objP->model, (unsigned int)bin_datP); 
                }
            }
            else 
            {
                objP->model = NULL;
            }
        }
    }
    
    if (tex_off != -1)
    {
        mlwP->texP = (void*)((int)bin_datP + tex_off);
        
        mlwP->texP->textures = (NJS_TEXNAME*)((char*)mlwP->texP->textures + (int)bin_datP);
        
        namP = mlwP->texP->textures;
        
        for (tex_num = mlwP->texP->nbTexture; tex_num != 0; tex_num--, namP++) 
        {
            namP->filename = (void*)((char*)namP->filename + (int)bin_datP);
        }
    }
    
    return 1;
}

// 100% matching!
int bhBscBinRealize(NJS_MODEL* mdlP, unsigned int dat_off)
{
    NJS_MESHSET* mshP;
    unsigned int i;
    
    if ((mdlP->nbPoint & 0x80000000))
    {
        mdlP->nbPoint &= ~0x80000000;
        
        if ((int)mdlP->points != -1) 
        {
            mdlP->points = (NJS_POINT3*)((char*)mdlP->points + dat_off);
        }
        
        if ((int)mdlP->normals != -1) 
        {
            mdlP->normals = (NJS_VECTOR*)((char*)mdlP->normals + dat_off);
        }
        
        if ((int)mdlP->meshsets != -1) 
        {
            mshP = mdlP->meshsets = (NJS_MESHSET*)((char*)mdlP->meshsets + dat_off);
        }
        
        if ((int)mdlP->mats != -1)
        {
            mdlP->mats = (NJS_MATERIAL*)((char*)mdlP->mats + dat_off);
        }
        
        for (i = 0; i < mdlP->nbMeshset; i++, mshP++) 
        {
            if ((int)mshP->meshes != -1) 
            {
                mshP->meshes = (short*)((char*)mshP->meshes + dat_off);
            }
            
            if ((int)mshP->attrs != -1) 
            {
                mshP->attrs = (unsigned int*)((char*)mshP->attrs + dat_off);
            }
            else 
            {
                mshP->attrs = NULL;
            }
            
            if ((int)mshP->normals != -1)
            {
                mshP->normals = (NJS_VECTOR*)((char*)mshP->normals + dat_off);
            } 
            else
            {
                mshP->normals = NULL;
            }
            
            if ((int)mshP->vertcolor != -1) 
            {
                mshP->vertcolor = (NJS_COLOR*)((char*)mshP->vertcolor + dat_off);
            }
            else 
            {
                mshP->vertcolor = NULL;
            }
            
            if ((int)mshP->vertuv != -1) 
            {
                mshP->vertuv = (NJS_COLOR*)((char*)mshP->vertuv + dat_off);
            } 
            else
            {
                mshP->vertuv = NULL;
            }
        }
    }
    
    return 1;
}

// 100% matching!
int bhCnkBinRealize(NJS_CNK_MODEL* mdlP, unsigned int dat_off)
{
    if (mdlP->r < 0) 
    {
        mdlP->r = -mdlP->r; 
        
        if ((int)mdlP->vlist != -1)
        { 
            mdlP->vlist = (int*)((char*)mdlP->vlist + dat_off); 
        }
        
        if ((int)mdlP->plist != -1)
        {
            mdlP->plist = (short*)((char*)mdlP->plist + dat_off); 
        }
    }
    
    return 1; 
}

// 100% matching!
int bhMnbBinRealize(void* bin_datP, MN_WORK* mnwP)
{
    NJS_MOTION* mtnP;     
    NJS_MDATA2_MOD* md2P;
    void* dat_topP;     
    int i;               
    
    dat_topP = (void*)((int)bin_datP + ((unsigned short*)bin_datP)[2]);
    mtnP = (NJS_MOTION*)((int)dat_topP + ((int*)bin_datP)[2]);
    md2P = (NJS_MDATA2_MOD*)((int)mtnP->mdata + (int)dat_topP);
    
    mtnP->mdata = md2P;
    
    mnwP->flg = ((char*)bin_datP)[3];
    
    mnwP->obj_num = ((unsigned short*)bin_datP)[3];
    mnwP->frm_num = mtnP->nbFrame;
    
    mnwP->datP = bin_datP;
    mnwP->md2P = (NJS_MDATA2*)md2P;
    mnwP->atrP = NULL;
    
    if (((int*)bin_datP)[3] != -1) 
    {
        mnwP->atrP = (unsigned short*)((int)dat_topP + ((int*)bin_datP)[3]);
    }
    
    for (i = 0; i < ((unsigned short*)bin_datP)[3]; i++, md2P++)
    {
        if (md2P->p[0] == (void*)-1) 
        {
            md2P->p[0] = NULL;
        } 
        else 
        {
            md2P->p[0] = (void*)((char*)md2P->p[0] + (int)dat_topP);
        }
        
        if (md2P->p[1] == (void*)-1) 
        {
            md2P->p[1] = NULL;
        } 
        else 
        {
            md2P->p[1] = (void*)((char*)md2P->p[1] + (int)dat_topP);
        }
    }
    
    return 1;
}
