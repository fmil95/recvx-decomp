#include "binfunc.h"

/*int bhMlbBinRealize(void* bin_datP, _anon10* mlwP);*/
int bhBscBinRealize(NJS_MODEL* mdlP, unsigned int dat_off);
int bhCnkBinRealize(NJS_CNK_MODEL* mdlP, unsigned int dat_off);
/*int bhMnbBinRealize(void* bin_datP, _anon0* mnwP);

// 
// Start address: 0x2c8720
int bhMlbBinRealize(void* bin_datP, _anon10* mlwP)
{
	_anon2* namP;
	unsigned int tex_num;
	npobj* objP;
	unsigned int status;
	unsigned int obj_off;
	unsigned int tex_off;
	unsigned int obj_num;
	// Line 52, Address: 0x2c8720, Func Offset: 0
	// Line 56, Address: 0x2c8740, Func Offset: 0x20
	// Line 57, Address: 0x2c8744, Func Offset: 0x24
	// Line 58, Address: 0x2c8748, Func Offset: 0x28
	// Line 59, Address: 0x2c874c, Func Offset: 0x2c
	// Line 74, Address: 0x2c8754, Func Offset: 0x34
	// Line 63, Address: 0x2c875c, Func Offset: 0x3c
	// Line 64, Address: 0x2c8760, Func Offset: 0x40
	// Line 65, Address: 0x2c8764, Func Offset: 0x44
	// Line 66, Address: 0x2c8768, Func Offset: 0x48
	// Line 67, Address: 0x2c876c, Func Offset: 0x4c
	// Line 68, Address: 0x2c8770, Func Offset: 0x50
	// Line 70, Address: 0x2c8774, Func Offset: 0x54
	// Line 74, Address: 0x2c8778, Func Offset: 0x58
	// Line 78, Address: 0x2c8780, Func Offset: 0x60
	// Line 76, Address: 0x2c8784, Func Offset: 0x64
	// Line 79, Address: 0x2c8788, Func Offset: 0x68
	// Line 83, Address: 0x2c878c, Func Offset: 0x6c
	// Line 85, Address: 0x2c8798, Func Offset: 0x78
	// Line 86, Address: 0x2c87a8, Func Offset: 0x88
	// Line 88, Address: 0x2c87b4, Func Offset: 0x94
	// Line 90, Address: 0x2c87b8, Func Offset: 0x98
	// Line 91, Address: 0x2c87c8, Func Offset: 0xa8
	// Line 93, Address: 0x2c87d4, Func Offset: 0xb4
	// Line 96, Address: 0x2c87d8, Func Offset: 0xb8
	// Line 97, Address: 0x2c87e8, Func Offset: 0xc8
	// Line 99, Address: 0x2c87ec, Func Offset: 0xcc
	// Line 100, Address: 0x2c87f4, Func Offset: 0xd4
	// Line 102, Address: 0x2c8808, Func Offset: 0xe8
	// Line 103, Address: 0x2c8814, Func Offset: 0xf4
	// Line 104, Address: 0x2c881c, Func Offset: 0xfc
	// Line 106, Address: 0x2c8820, Func Offset: 0x100
	// Line 108, Address: 0x2c882c, Func Offset: 0x10c
	// Line 111, Address: 0x2c8830, Func Offset: 0x110
	// Line 115, Address: 0x2c883c, Func Offset: 0x11c
	// Line 116, Address: 0x2c8844, Func Offset: 0x124
	// Line 119, Address: 0x2c8854, Func Offset: 0x134
	// Line 120, Address: 0x2c8858, Func Offset: 0x138
	// Line 121, Address: 0x2c885c, Func Offset: 0x13c
	// Line 122, Address: 0x2c8864, Func Offset: 0x144
	// Line 123, Address: 0x2c8868, Func Offset: 0x148
	// Line 122, Address: 0x2c886c, Func Offset: 0x14c
	// Line 123, Address: 0x2c8874, Func Offset: 0x154
	// Line 128, Address: 0x2c8880, Func Offset: 0x160
	// Line 127, Address: 0x2c889c, Func Offset: 0x17c
	// Line 128, Address: 0x2c88a0, Func Offset: 0x180
	// Func End, Address: 0x2c88a8, Func Offset: 0x188
}*/

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
