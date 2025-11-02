#include "ps2_NinjaPtcl.h"

unsigned int Ps2_ptcl_poly_col;
int Ps2_ptcl_spr_flag;
unsigned int Ps2_ptcl_spr_col;

// 100% matching!
void	njPtclPolygonStart( Uint32 col ) 
{
    Ps2_ptcl_poly_col = col; 
}

// 100% matching!
void	njPtclPolygonEnd( void )
{

}

// 100% matching!
void	njPtclDrawPolygon( NJS_POINT3 *p, Sint32 n, Float h ) 
{ 
    float invz; 
    float buff[256][4]; 
    float (* bp)[4];
    unsigned int i; 
    unsigned int col; 
    NJS_SCRVECTOR scr; 
    
    bp = (void*)&buff; 
    
    col = Ps2_ptcl_poly_col; 
    
    for (i = 0; i < n; i++) 
    { 
        *(unsigned int*)&bp[1][0] = ((col >> 16) & 0xFF) + 1; 
        *(unsigned int*)&bp[1][1] = ((col >> 8) & 0xFF) + 1; 
        *(unsigned int*)&bp[1][2] = (col & 0xFF) + 1; 
        *(unsigned int*)&bp[1][3] = (((col >> 24) & 0xFF) + 1) / 2; 
        
        *(unsigned int*)&bp[4][0] = ((col >> 16) & 0xFF) + 1; 
        *(unsigned int*)&bp[4][1] = ((col >> 8) & 0xFF) + 1; 
        *(unsigned int*)&bp[4][2] = (col & 0xFF) + 1;
        *(unsigned int*)&bp[4][3] = (((col >> 24) & 0xFF) + 1) / 2; 
            
        njRotTransPers(&p[i], &scr); 
        
        invz = scr.iz; 
        
        bp[2][0] = scr.x - h; 
        bp[2][1] = scr.y - h;
        bp[2][2] = scr.z; 
        bp[2][3] = scr.fog;
        
        bp[5][0] = scr.x + h; 
        bp[5][1] = scr.y + h; 
        bp[5][2] = scr.z; 
        bp[5][3] = scr.fog; 
        
        bp[0][0] = 0; 
        bp[0][1] = 0;
        bp[0][2] = invz; 
        bp[0][3] = 0; 
        
        bp[3][0] = invz; 
        bp[3][1] = invz; 
        bp[3][2] = invz;  
        bp[3][3] = 0; 
        
        bp += 6; 
    }
    
    if (Ps2_ptcl_spr_flag == 1) 
    { 
        Ps2AddPrim3D(0x33000000000000, &buff, n); 
    } 
    else 
    {
        Ps2AddPrim3D(0x13000000000000, &buff, n);
    } 
}

// 100% matching!
void	njPtclSpriteStart( Sint32 texid, Uint32 col, Sint32 flag )
{ 
    Ps2_ptcl_spr_col = col; 
    Ps2_ptcl_spr_flag = flag;
    
    njSetTextureNumSys(texid); 
}

// 100% matching!
void	njPtclSpriteEnd( void ) 
{

}

// 100% matching!
void	njPtclDrawSprite( NJS_POINT3 *p, Sint32 n, Float w, Float h ) 
{ 
    float invz; 
    float buff[256][4]; 
    float (* bp)[4];
    unsigned int i; 
    unsigned int col; 
    NJS_SCRVECTOR scr; 
    
    bp = (void*)&buff; 
    
    col = Ps2_ptcl_spr_col; 
    
    for (i = 0; i < n; i++) 
    { 
        *(unsigned int*)&bp[1][0] = (((col >> 16) & 0xFF) + 1) / 2;
        *(unsigned int*)&bp[1][1] = (((col >> 8) & 0xFF) + 1) / 2; 
        *(unsigned int*)&bp[1][2] = ((col & 0xFF) + 1) / 2; 
        *(unsigned int*)&bp[1][3] = (((col >> 24) & 0xFF) + 1) / 2; 
        
        *(unsigned int*)&bp[4][0] = (((col >> 16) & 0xFF) + 1) / 2; 
        *(unsigned int*)&bp[4][1] = (((col >> 8) & 0xFF) + 1) / 2; 
        *(unsigned int*)&bp[4][2] = ((col & 0xFF) + 1) / 2; 
        *(unsigned int*)&bp[4][3] = (((col >> 24) & 0xFF) + 1) / 2; 
            
        njRotTransPers(&p[i], &scr); 
        
        invz = scr.iz; 
        
        bp[2][0] = scr.x - (invz * (w * _nj_screen_.dist)); 
        bp[2][1] = scr.y - (invz * (h * _nj_screen_.dist)); 
        bp[2][2] = scr.z; 
        bp[2][3] = scr.fog; 
        
        bp[5][0] = scr.x + (invz * (w * _nj_screen_.dist)); 
        bp[5][1] = scr.y + (invz * (h * _nj_screen_.dist)); 
        bp[5][2] = scr.z; 
        bp[5][3] = scr.fog; 
        
        bp[0][0] = 0; 
        bp[0][1] = 0;
        bp[0][2] = invz; 
        bp[0][3] = 0; 
        
        bp[3][0] = invz; 
        bp[3][1] = invz; 
        bp[3][2] = invz;  
        bp[3][3] = 0; 
        
        bp += 6; 
    }
    
    if (Ps2_ptcl_spr_flag == 1) 
    { 
        Ps2AddPrim3D(0x3B000000000000, &buff, n); 
    } 
    else 
    {
        Ps2AddPrim3D(0x1B000000000000, &buff, n);
    } 
}
