#include "../../../ps2/veronica/prog/ps2_NaSprite.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"

// 100% matching!
void	njDrawSprite2D( NJS_SPRITE *sp, Int n, Float pri, Uint32 attr )
{
    int buff[32][4];
    int (*bp)[4];
    int col[4];
    float colf[4];
    unsigned long prim;
    float co, si;
    float xx;
    float xx1, xx2, xx3; // not from DWARF
    float yy1, yy2, yy3; // not from DWARF
    float yy;
    float temp; // not from DWARF
    short swap;
    NJS_TEXANIM* ap;
    int h_val, v_val;
    int shift_num;
    int val;
    NJS_TEXMEMLIST* tmp;
    short swap_a, swap_b, swap_c, swap_d, swap_e, swap_f, swap_g, swap_h; // not from DWARF

    bp = buff;

    ap = &sp->tanim[n];
    
    if (pri > -1.0f) 
    {
        pri = -1.0f;
    }
    
    tmp = (NJS_TEXMEMLIST*)sp->tlist->textures[ap->texid].texaddr;
    
    Ps2TexLoad(tmp);
    
    shift_num = Ps2BitCount(tmp->texinfo.texsurface.nWidth) - 4;
    
    if ((attr & NJD_SPRITE_HFLIP))
    {
        h_val = -8;
    } 
    else 
    {
        h_val = 8;
    }
    
    if ((attr & NJD_SPRITE_VFLIP))
    {
        v_val = -8;
    }
    else 
    {
        v_val = 8;
    }

    val = ap->u1 << shift_num;
    
    if ((h_val + val) < 0) 
    {
        swap_b = swap_a = 0;
    }
    else 
    {
        swap_b = swap_a = h_val + val;
    }

    val = ap->u2 << shift_num;
    
    if ((h_val + val) < 0) 
    {
        swap_d = swap_c = 0;
    } 
    else 
    {
        swap_d = swap_c = h_val + val;
    }

    val = ap->v1 << shift_num;
    
    if ((v_val + val) < 0) 
    {
        swap_f = swap_e = 0;
    } 
    else 
    {
        swap_f = swap_e = v_val + val;
    }

    val = ap->v2 << shift_num;
    
    if ((v_val + val) < 0) 
    {
        swap_h = swap_g = 0;
    } 
    else
    {
        swap_h = swap_g = v_val + val;
    }
    
    if ((attr & NJD_SPRITE_HFLIP))
    {
        swap = swap_b;
        swap_b = swap_d;
        swap_d = swap;
        
        swap = swap_f;
        swap_f = swap_e;
        swap_e = swap;

        swap = swap_a;
        swap_a = swap_c;
        swap_c = swap;
        
        swap = swap_h;
        swap_h = swap_g;
        swap_g = swap;
    }
    
    if ((attr & NJD_SPRITE_VFLIP))
    {
        swap = swap_b;
        swap_b = swap_a;
        swap_a = swap;
        
        swap = swap_f;
        swap_f = swap_h;
        swap_h = swap;

        swap = swap_d;
        swap_d = swap_c;
        swap_c = swap;
        
        swap = swap_e;
        swap_e = swap_g;
        swap_g = swap;
    }
    
    switch (((sp->ang + 0xFFFF) & 0xC000) / 16384) 
    {                         
    case 0:
        bp[0][0] = swap_b;
        bp[0][1] = swap_f - 16;
        bp[0][3] = 0; 
        
        bp[3][0] = swap_d;
        bp[3][1] = swap_e - 16;
        bp[3][3] = 0;
        
        bp[6][0] = swap_a;
        bp[6][1] = swap_h - 16;
        bp[6][3] = 0;
        
        bp[9][0] = swap_c;
        bp[9][1] = swap_g - 16;
        bp[9][3] = 0;
        break;
    case 1:
        bp[0][0] = swap_b;
        bp[0][1] = swap_f;
        bp[0][3] = 0;
        
        bp[3][0] = swap_d;
        bp[3][1] = swap_e;
        bp[3][3] = 0;
        
        bp[6][0] = swap_a;
        bp[6][1] = swap_h;
        bp[6][3] = 0;
        
        bp[9][0] = swap_c;
        bp[9][1] = swap_g;
        bp[9][3] = 0;
        break;
    case 2:
        bp[0][0] = swap_b;
        bp[0][1] = swap_f;
        bp[0][3] = 0;
        
        bp[3][0] = swap_d;
        bp[3][1] = swap_e;
        bp[3][3] = 0;
        
        bp[6][0] = swap_a;
        bp[6][1] = swap_h;
        bp[6][3] = 0;
        
        bp[9][0] = swap_c;
        bp[9][1] = swap_g;
        bp[9][3] = 0;
        break;
    case 3:
        bp[0][0] = swap_b;
        bp[0][1] = swap_f; 
        bp[0][3] = 0;
        
        bp[3][0] = swap_d;
        bp[3][1] = swap_e;
        bp[3][3] = 0;
        
        bp[6][0] = swap_a;
        bp[6][1] = swap_h;
        bp[6][3] = 0;
        
        bp[9][0] = swap_c;
        bp[9][1] = swap_g;
        bp[9][3] = 0;
        break;
    }
    
    *(float*)&bp[0][2] = 1.0f;
    *(float*)&bp[3][2] = 1.0f;
    *(float*)&bp[6][2] = 1.0f;
    *(float*)&bp[9][2] = 1.0f;
    
    if ((attr & NJD_SPRITE_COLOR)) 
    {
        colf[0] = 128.0f * fNaCnkConstantR;
        colf[1] = 128.0f * fNaCnkConstantG;
        colf[2] = 128.0f * fNaCnkConstantB;
        colf[3] = 128.0f * fNaCnkConstantA;

        sceVu0FTOI0Vector(col, colf);
        
        *(u_long128*)&bp[1][0] = *(u_long128*)&col;
        *(u_long128*)&bp[4][0] = *(u_long128*)&col;
        *(u_long128*)&bp[7][0] = *(u_long128*)&col;
        *(u_long128*)&bp[10][0] = *(u_long128*)&col;
    }
    else 
    {
        bp[1][0] = 128;
        bp[1][1] = 128;
        bp[1][2] = 128;
        bp[1][3] = 128;
        
        bp[4][0] = 128;
        bp[4][1] = 128;
        bp[4][2] = 128;
        bp[4][3] = 128;
        
        bp[7][0] = 128;
        bp[7][1] = 128;
        bp[7][2] = 128;
        bp[7][3] = 128;
        
        bp[10][0] = 128;
        bp[10][1] = 128;
        bp[10][2] = 128;
        bp[10][3] = 128;
    } 
    
    xx1 = xx = -ap->cx * sp->sx;
    xx3 = xx2 = sp->sx * (ap->sx - ap->cx);
    
    yy1 = yy = -ap->cy * sp->sy;
    yy3 = yy2 = sp->sy * (ap->sy - ap->cy);
    
    if ((attr & NJD_SPRITE_ANGLE))
    {
        co = cosf(0.0000958738f * sp->ang);
        si = sinf(0.0000958738f * sp->ang);
        
        temp = (co * xx1) - (si * yy1);
        
        yy1 = (si * xx1) + (co * yy1);
        xx1 = temp;

        temp = (co * xx3) - (si * yy);
        
        yy = (si * xx3) + (co * yy);
        xx3 = temp;

        temp = (si * xx) + (co * yy3);
        
        xx = (co * xx) - (si * yy3);
        yy3 = temp;

        temp = (si * xx2) + (co * yy2);
        
        xx2 = (co * xx2) - (si * yy2);
        yy2 = temp;
    }
    
    *(float*)&bp[2][0] = 1728.0f + (sp->p.x + xx1);
    *(float*)&bp[2][1] = 1808.0f + (sp->p.y + yy1);
    *(float*)&bp[2][2] = pri;
    *(float*)&bp[2][3] = 0;
    
    *(float*)&bp[5][0] = 1728.0f + (sp->p.x + xx3);
    *(float*)&bp[5][1] = 1808.0f + (sp->p.y + yy);
    *(float*)&bp[5][2] = pri;
    *(float*)&bp[5][3] = 0;
    
    *(float*)&bp[8][0] = 1728.0f + (sp->p.x + xx);
    *(float*)&bp[8][1] = 1808.0f + (sp->p.y + yy3);
    *(float*)&bp[8][2] = pri;
    *(float*)&bp[8][3] = 0;
    
    *(float*)&bp[11][0] = 1728.0f + (sp->p.x + xx2);
    *(float*)&bp[11][1] = 1808.0f + (sp->p.y + yy2);
    *(float*)&bp[11][2] = pri;
    *(float*)&bp[11][3] = 0;
    
    prim = SCE_GIF_SET_TAG(0, 0, 0, SCE_GS_SET_PRIM(SCE_GS_PRIM_TRISTRIP, SCE_GS_TRUE, SCE_GS_TRUE, SCE_GS_FALSE, SCE_GS_FALSE, SCE_GS_FALSE, SCE_GS_TRUE, SCE_GS_FALSE, SCE_GS_FALSE), 0, 0);
    
    if (!(attr & NJD_SPRITE_ALPHA))
    {
        printf("njDrawSprite2D ERROR\n");
        
        exit(0);
    }
    
    if ((attr & NJD_SPRITE_ALPHA))
    {
        prim |= SCE_GIF_SET_TAG(0, 0, 0, SCE_GS_SET_PRIM(SCE_GS_PRIM_POINT, SCE_GS_FALSE, SCE_GS_FALSE, SCE_GS_FALSE, SCE_GS_TRUE, SCE_GS_FALSE, SCE_GS_FALSE, SCE_GS_FALSE, SCE_GS_FALSE), 0, 0);
    }
    
    Ps2AddPrim2D(prim, &buff, 4);
}
