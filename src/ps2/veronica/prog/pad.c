#include "pad.h"

unsigned int pad_tab_a[18];
unsigned int pad_tab_b[18];
unsigned int pad_tab_c[18];
unsigned int pad_tab_d[18];
unsigned int* pad_type[4] = { pad_tab_a, pad_tab_b, pad_tab_c, pad_tab_d };
unsigned short pdm_mes[10];
unsigned short pdm_palmes[19];
SYS_WORK* sys;
int pd_port;

void bhReturnTitle(); // TODO: remove this function declaration
// 100% matching!
void bhSetPad() 
{ 
	unsigned int* pd;
    int i;
    unsigned int pad;
    unsigned int pon;
    unsigned int argb;
    unsigned int padwork;
    
    if ((sys->ss_flg & 0x800000))
    { 
        if (!(sys->cb_flg & 0x2))
        { 
            sys->keytype = sys->pdm_keytpb; 
            
            njFogDisable();
            
            njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
            
            bhReturnTitle();
            
            sys->ss_flg &= ~0xC00000; 
            
            sys->pdm_no++;
            
            if (sys->pdm_no > 2) 
            {
                sys->pdm_no = 0; 
            }
        }
        
        return;  
    } 
    else if ((sys->ss_flg & 0x400000)) 
    { 
        if (pd_port == -1) 
        {
            sys->p1per = NULL;
        }
        else 
        {
            sys->p1per = njGetPeripheral(pd_port); 
        }
        
        pon = *(unsigned int*)sys->pdm_pd; 
        
        {
        unsigned int padtbl[18] = { 0x00000000, 0x00000800, 0x00000040, 0x00000100, 0x00001000, 0x00004000, 0x00008000, 0x00002000,
                                    0x00000000, 0x00000010, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
                                    0x00000004, 0x00000008 }; 
            
        if (pon != -1) 
        { 
            padwork = 0; 
            
            for (i = 0; i < 18; i++) 
            { 
                if ((pon & (1 << i))) 
                {
                    padwork |= padtbl[i];
                }
            }
            
            pon = padwork; 
        }
        }
        
        sys->pdm_pd += 4; 
        
        if ((pon == -1) || ((sys->p1per != NULL) && ((sys->p1per->on & 0x800)) && (!(sys->cb_flg & 0x2)))) 
        { 
            if (pon == -1) 
            {
                sys->ss_flg |= 0x200000;
            }
            
            sys->ss_flg |= 0x800000; 
            
            sys->sp_flg = 0;
            sys->sp_flg |= 0x20;
            
            bhSetScreenFade(0xFF000000, 10.0f); 
            
            RequestAllStopSoundEx(1, 1, 10);
            return; 
        }
        
        if (!(sys->cb_flg & 0x2)) 
        { 
            sys->mes_tp = pdm_mes;
            
            argb = ((int)(128.0f + (127.0f * njSin((sys->eor_ct & 0xF) * 2048))) << 24) | 0xE0E000; 
            
            bhDispMessageEx(320.0f - (bhMesLen(pdm_mes) / 2.0f), 88.0f, -0.9f, 2, 0, argb, 0);    
            bhDispMessageEx(320.0f - (bhMesLen(pdm_mes) / 2.0f), 88.0f, -0.9f, 2, 0, -2039808, 0); 
            
            sys->mes_tp = pdm_palmes; 
            
            bhDispMessageEx(320.0f - (bhMesLen(pdm_palmes) / 2.0f), 392.0f, -0.9f, 2, 0, argb, 0); 
        }
    }
    else
    { 
        if (pd_port == -1) 
        {
            sys->p1per = NULL; 
        }
        else 
        {
            sys->p1per = njGetPeripheral(pd_port);
        }
        
        if (sys->p1per == NULL) 
        { 
            sys->pad_on = sys->pad_oncpy = sys->pad_ps = sys->pad_old = 0; 
            
            sys->pad_ay = sys->pad_ax = sys->pad_al = sys->pad_ar = 0;
            return; 
        }
        
        pon = sys->p1per->on; 
        
        sys->pad_ar = sys->p1per->r; 
        sys->pad_al = sys->p1per->l; 
    
        sys->pad_ax = -sys->p1per->x1;
        sys->pad_ay = -sys->p1per->y1; 
    }
    
    sys->pad_old = sys->pad_on; 
    
    pad = 0; 
    
    pd = pad_type[sys->keytype]; 
    
    for (i = 0; i < 18; i++) 
    { 
        if ((pon & pd[i]))
        {
            pad |= 1 << i;
        }
    } 
    
    if (!(sys->gm_flg & 0x80001)) 
    { 
        if (sys->pad_ay > 63) 
        {
            pad |= 0x42;
        }
        
        if (sys->pad_ay < -63) 
        {
            pad |= 0x21;
        }
        
        if (sys->pad_ax > 63) 
        {
            pad |= 0x8;
        }
        
        if (sys->pad_ax < -63) 
        {
            pad |= 0x4; 
        }
    }
    
    if ((pad & 0x1)) 
    {
        pad &= ~0x42; 
    }
    
    if ((pad & 0x8)) 
    {
        pad &= ~0x4;
    }
    
    if ((pad & 0xC)) 
    { 
        if ((pad & 0x8)) 
        { 
            if (sys->pad_dx >= 0) 
            {
                sys->pad_dx += 4;
            }
            else 
            {
                sys->pad_dx = 0;
            }
        }
        
        if ((pad & 0x4)) 
        { 
            if (sys->pad_dx <= 0) 
            {
                sys->pad_dx -= 4;
            }
            else 
            {
                sys->pad_dx = 0;
            }
        }
        
        if (sys->pad_dx > 127) 
        {
            sys->pad_dx = 127;
        }
        
        if (sys->pad_dx < -128) 
        {
            sys->pad_dx = -128;
        }
    } 
    else
    { 
        sys->pad_dx = sys->pad_dx / 2; 
    }
    
    if ((pad & 0x3)) 
    { 
        if ((pad & 0x2))
        { 
            if (sys->pad_dy >= 0) 
            {
                sys->pad_dy += 4;
            }
            else 
            {
                sys->pad_dy = 0;
            }
        }
        
        if ((pad & 0x1)) 
        { 
            if (sys->pad_dy <= 0) 
            {
                sys->pad_dy -= 4;
            }
            else 
            {
                sys->pad_dy = 0;
            }
        }
        
        if (sys->pad_dy > 127) 
        {
            sys->pad_dy = 127;
        }
        
        if (sys->pad_dy < -128) 
        {
            sys->pad_dy = -128; 
        }
    } 
    else 
    { 
        sys->pad_dy = sys->pad_dy / 2; 
    }
    
    sys->pad_ps = pad & ~sys->pad_oncpy; 
    sys->pad_rs = pad ^ (sys->pad_oncpy | sys->pad_ps); 
    
    sys->pad_on = sys->pad_oncpy = pad; 
} 
