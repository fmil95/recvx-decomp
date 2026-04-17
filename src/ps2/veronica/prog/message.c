#include "../../../ps2/veronica/prog/message.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/main.h"

float FontScaleX;
float FontScaleY;
float FontScaleCR;
const float mes_spos[3][4] = 
{
    { 68.0f, 374.0f, 306.0f, 434.0f },
    { 44.0f, 342.0f, 212.0f, 432.0f },
    { 68.0f, 371.0f, 306.0f, 434.0f }
};
const unsigned char FontSz[126] = { 0x1c, 0x0e, 0x0e, 0x1c, 0x1c, 0x1c, 0x1c, 0x0e, 0x0e, 0x0e, 0x1c, 0x16, 0x0e, 0x14, 0x0e, 0x1c, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x0e, 0x0e, 0x1c, 0x1c, 0x1c, 0x14, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0e, 0x12, 0x1a, 0x14, 0x1c, 0x1a, 0x18, 0x16, 0x18, 0x18, 0x14, 0x14, 0x18, 0x16, 0x1c, 0x16, 0x16, 0x14, 0x0e, 0x1c, 0x0e, 0x1c, 0x14, 0x1c, 0x10, 0x10, 0x0c, 0x10, 0x0e, 0x0e, 0x12, 0x12, 0x0a, 0x0c, 0x12, 0x0a, 0x18, 0x12, 0x10, 0x10, 0x10, 0x0e, 0x0e, 0x0c, 0x12, 0x10, 0x14, 0x10, 0x10, 0x0e, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c };

// 100% matching! 
void bhSetMessage(int mes_typ, int mes_idx)
{
    switch (mes_typ) 
    {
    case 0:
        sys->mes_dp = rom->mesp;
        break;
    case 1:
        sys->mes_dp = sys->mes_sp;
        break;
    default:
        return;
    }
    
    sys->mes_idx = mes_idx + 1;
    
    sys->mes_dp = (unsigned int*)((unsigned char*)sys->mes_dp + sys->mes_dp[sys->mes_idx]);
    
    sys->mes_ct = 0;
    
    sys->mes_tim = 0;
    
    sys->mes_fls = 0;
    
    sys->mes_sel = 0;
    
    sys->st_flg |= 0x200;
    
    sys->st_flg &= ~(0x80000 | 0x8000 | 0x4000 | 0x1000 | 0x400 | 0x800);
    sys->cb_flg &= ~(0x20000000 | 0x2000 | 0x1000);
}

// 100% matching! 
void bhControlMessage(int mode) 
{
    NJS_POINT2 pos;
    unsigned short* dt;
    unsigned short cd, id;
    int mct, col, end;
    int itn;
    
    dt = (unsigned short*)sys->mes_dp;
    
    sys->mes_seln = 0;
    
    if ((mode == 0) && (((sys->tk_flg & 0x1000)) && (!(sys->ts_flg & 0x1000)))) 
    {
        mode = 2;
    }
    
    pos.x = mes_spos[mode][0];
    pos.y = mes_spos[mode][1];
    
    mct = 0;
    col = 0;
    end = 0;
    
    while (mct <= sys->mes_ct) 
    {
        cd = *dt++;
        
        switch (cd) 
        {
        case 65535:
            if (!(sys->st_flg & 0x800)) 
            {
                sys->st_flg |= 0x1000;
            }
            
            end = 1;
            
            sys->st_flg |= 0x4000;
            break;
        case 65280:
            pos.x = mes_spos[mode][0];
            
            pos.y += 30.0f * FontScaleCR;
            continue;
        case 65281:
            pos.x += 14.0f * FontScaleX;
            continue;
        case 65282:
            if ((sys->mes_tim != 0) || (((sys->st_flg & 0x4000)) || ((sys->st_flg & 0x800)))) 
            {
                dt++;
            }
            else 
            {
                sys->mes_tim = *dt++;
                
                if (sys->mes_tim == 0) 
                {
                    sys->st_flg |= 0x1000;
                    
                    end = 1;
                    break;
                }
                
                sys->st_flg |= 0x800;
            }
            
            continue;
        case 65283:
            id = *dt++;
            
            if (id == 65535) 
            { 
                id = sys->sb_id;
            }
            
            itn = bhDispItemName(&pos, id, 0, (sys->mes_ct - mct) + 1, -0.9f);
            
            if (itn == 0) 
            {
                end = 1;
                break;
            }
            
            mct += itn;
            continue;
        case 65284:
            if (!(sys->st_flg & 0x8000)) 
            {
                sys->st_flg |= 0x8000;
                
                sys->mes_ct += 65536;
            }
            
            sys->mes_sps[sys->mes_seln].x = pos.x;
            sys->mes_sps[sys->mes_seln].y = pos.y;
            
            sys->mes_seln++;
            
            pos.x += 28.0f * FontScaleX;
            continue;
        case 65024:
            if (mct >= sys->mes_ct) 
            { 
                sys->mes_ct += 65536;
            
                sys->st_flg |= 0x400;
            }
            
            continue;
        case 65025:
            col = 0;
            continue;
        case 65026:
            col = 1;
            continue;
        case 65027:
            col = 2;
            continue;
        case 65028:
            col = 3;
            continue;
        case 65029:
            col = 4;
            continue;
        case 65030:
            continue;
        case 65031:
            continue;
        case 65032:
            if (sys->mes_tim == 0) 
            {
                sys->mes_dp = (unsigned int*)dt;
                
                sys->st_flg &= ~0x800;
                
                end = 1;
            } 
            else 
            {
                end = 1;
            }
            
            break;
        case 65033:
            if (!(sys->st_flg & 0x80000)) 
            {
                sys->st_flg |= 0x80000;
                
                sys->mes_sel = sys->mes_seln;
            }
            
            continue;
        case 65034:
            continue;
        case 65035:
            continue;
        case 65036:
            continue;
        case 65037:
            continue;
        case 65038:
            continue;
        case 65039:
            continue;
        }
        
        if (end != 0) 
        { 
            break;
        }
        
        bhDispFont(&pos, cd, col, -0.9f);
        pos.x += FontScaleX * bhGetFontSize(cd);
        
        mct++;
    }
    
    if (sys->mes_tim == 0) 
    {
        if ((sys->st_flg & 0x8000)) 
        {
            if ((sys->pad_ps & 0x800)) 
            {
                if ((sys->st_flg & 0x8)) 
                { 
                    sys->mes_sel += 100;
                }
                
                sys->st_flg &= ~0x8000;
                
                if (!(sys->st_flg & 0x2000)) 
                {
                    sys->cb_flg |= 0x1000;
                    sys->st_flg |= 0x4000;
                } 
                else 
                {
                    if (((sys->gm_flg & 0x10000)) && ((sys->gm_flg & 0x20000))) 
                    {
                        sys->sp_flg |= 0x40;
                    }
                    
                    sys->cb_flg |= 0x20002000;
                    
                    if ((sys->st_flg & 0x80)) 
                    { 
                        sys->st_flg |= 0x200000;
                    }
                    
                    sys->st_flg |= 0x400000;
                }
                
                return;
            }
                
            sys->st_flg &= ~0x4000;
            
            if ((sys->pad_ps & 0x4)) 
            {
                sys->mes_sel--;
                
                sys->mes_fls = 0;
                
                CallSystemSe(0, 2);
            }
            
            if ((sys->pad_ps & 0x8)) 
            {
                sys->mes_sel++;
                
                sys->mes_fls = 0;
                
                CallSystemSe(0, 2);
            }
            
            if (sys->mes_sel >= sys->mes_seln) 
            { 
                sys->mes_sel = 0;
            }
            
            if (sys->mes_sel < 0) 
            {
                sys->mes_sel = sys->mes_seln - 1;
            }
            
            if (sys->mes_fls < 24) 
            {
                pos.x = sys->mes_sps[sys->mes_sel].x;
                pos.y = sys->mes_sps[sys->mes_sel].y;
                
                bhDispFont(&pos, 28, 0, -0.9f);
            }
            
            sys->mes_fls = (sys->mes_fls + 1) & 0x1F;
        }
        else if (((sys->st_flg & 0x4000)) && (!(sys->st_flg & 0x1000))) 
        {
            sys->st_flg &= ~0x200;
            sys->cb_flg |= 0x2000;
            
            if ((sys->st_flg & 0x2000))
            {
                sys->sp_flg = -1;
                
                sys->st_flg &= ~0x2204;
                
                sys->pad_on = sys->pad_onb;
                sys->pad_ps = sys->pad_psb;
                sys->pad_old = sys->pad_oldb;
            }
            
            return;
        }
        else if ((!(sys->st_flg & 0x4000)) && ((sys->st_flg & 0x1000))) 
        {
            if ((sys->pad_ps & 0x800))
            {
                sys->mes_dp = (unsigned int*)dt;
                
                sys->mes_ct = 0;
                sys->mes_tim = 0;
                sys->mes_fls = 0;
                sys->mes_sel = 0;
                
                sys->st_flg &= ~0x1000;
            }
            
            if (sys->mes_fls < 24) 
            {
                pos.x = mes_spos[mode][2];
                pos.y = mes_spos[mode][3];
                
                bhDispFont(&pos, 29, 0, -0.9f);
            }
            
            sys->mes_fls = (sys->mes_fls + 1) & 0x1F;
        }
        else if (((sys->pad_on & 0x800)) && (!(sys->st_flg & 0x400))) 
        {
            sys->mes_ct += 4;
        }
        else 
        {
            sys->mes_ct++;
        }
    } 
    else 
    {
        sys->mes_tim--;
    }
}

// 100% matching! 
void bhDispFont(NJS_POINT2* pos, int code, int color, float pri)
{
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];   
    NJS_COLOR col[4];  
    NJS_COLOR uv[4];  
    
    njTextureFilterMode(0);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njSetTexture(&sys->ef_tlist);
    
    njSetTextureNum(code / 324);
    
    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = uv;
    
    p2c.num = 1;
    
    p[0].x = pos->x;
    p[0].y = pos->y;
    
    p[1].x = pos->x + (28.0f * FontScaleX);
    p[1].y = pos->y;
    
    p[2].x = pos->x + (28.0f * FontScaleX);
    p[2].y = pos->y + (28.0f * FontScaleY);
    
    p[3].x = pos->x;
    p[3].y = pos->y + (28.0f * FontScaleY);
    
    switch (color) 
    {                              
    case 1:
        col[0].color = 0xFF20E0FF;
        col[1].color = 0xFF20E0FF;
        col[2].color = 0xFF20E0FF;
        col[3].color = 0xFF20E0FF;
        break;
    case 2:
        col[0].color = 0xFFFF2020;
        col[1].color = 0xFFFF2020;
        col[2].color = 0xFFFF2020;
        col[3].color = 0xFFFF2020;
        break;
    case 3:
        col[0].color = 0xFF20FF20;
        col[1].color = 0xFF20FF20;
        col[2].color = 0xFF20FF20;
        col[3].color = 0xFF20FF20;
        break;
    case 4:
        col[0].color = 0xFF606060;
        col[1].color = 0xFF606060;
        col[2].color = 0xFF606060;
        col[3].color = 0xFF606060;
        break;
    default:
        col[0].color = 0xFFFFFFFF;
        col[1].color = 0xFFFFFFFF;
        col[2].color = 0xFFFFFFFF;
        col[3].color = 0xFFFFFFFF;
        break;
    }

    code %= 324;
    
    uv[0].tex.u = (code % 18) * 14;
    uv[0].tex.v = (code / 18) * 14;
    
    uv[1].tex.u = uv[0].tex.u + 14;
    uv[1].tex.v = uv[0].tex.v;
    
    uv[2].tex.u = uv[0].tex.u + 14;
    uv[2].tex.v = uv[0].tex.v + 14;
    
    uv[3].tex.u = uv[0].tex.u; 
    uv[3].tex.v = uv[0].tex.v + 14;
    
    njDrawPolygon2DM(&p2c, 4, pri, 0x80000060);
}

// 100% matching! 
void bhDispFontEx(NJS_POINT2* pos, int code, unsigned int argb, float pri)
{
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];   
    NJS_COLOR col[4];  
    NJS_COLOR uv[4];  
    
    njTextureFilterMode(0);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njSetTexture(&sys->ef_tlist);
    
    njSetTextureNum(code / 324);
    
    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = uv;
    
    p2c.num = 1;
    
    p[0].x = pos->x;
    p[0].y = pos->y;
    
    p[1].x = pos->x + (28.0f * FontScaleX);
    p[1].y = pos->y;
    
    p[2].x = pos->x + (28.0f * FontScaleX);
    p[2].y = pos->y + (28.0f * FontScaleY);
    
    p[3].x = pos->x;
    p[3].y = pos->y + (28.0f * FontScaleY);
    
    code %= 324;

    col[0].color = argb;
    col[1].color = argb;
    col[2].color = argb;
    col[3].color = argb;
    
    uv[0].tex.u = (code % 18) * 14;
    uv[0].tex.v = (code / 18) * 14;
    
    uv[1].tex.u = uv[0].tex.u + 14;
    uv[1].tex.v = uv[0].tex.v;
    
    uv[2].tex.u = uv[0].tex.u + 14;
    uv[2].tex.v = uv[0].tex.v + 14;
    
    uv[3].tex.u = uv[0].tex.u; 
    uv[3].tex.v = uv[0].tex.v + 14;
    
    njDrawPolygon2DM(&p2c, 4, pri, 0x80000060);
}

// 100% matching!
int bhDispItemName(NJS_POINT2* pos, int id, int color, int count, float pri)
{
    unsigned short* dp; 
    unsigned short cd;  
    int cflg;           
    int num;            

    num = 0;
    
    dp = (unsigned short*)((char*)sys->mes_ip + sys->mes_ip[id + 1]);
    
    if (count != 0) 
    { 
        cflg = 1;
    }
    else 
    {
        cflg = 0;
    }

    while (TRUE)
    {
        cd = *dp++;

        if (cd == 0xFFFF)
        {
            break;
        }
        
        if (cd != 0xFF01) 
        {
            bhDispFont(pos, cd, color, pri);
            
            pos->x += FontScaleX * bhGetFontSize(cd);
        } 
        else 
        {
            pos->x += 14.0f * FontScaleX;
        }
        
        num++;

        if ((cflg != 0) && (--count <= 0)) 
        {
            return 0;
        }
    } 

    return num;
}

// 100% matching! 
int bhDispMessage(float px, float py, float pri, int mes_typ, int mes_idx, int color, int count)
{
    NJS_POINT2 pos;      
    unsigned short* dp;  
    unsigned short cd;   
    int cflg;            
    int num;             
    unsigned int* mes_dp;
    float stx;          
    float sty;          

    switch (mes_typ) 
    {                           
    case 0:
        mes_dp = rom->mesp;
        
        dp = (unsigned short*)((char*)mes_dp + rom->mesp[mes_idx + 1]);
        break;
    case 1:
        mes_dp = sys->mes_sp;
        
        dp = (unsigned short*)((char*)mes_dp + sys->mes_sp[mes_idx + 1]);
        break;
    default:
        dp = sys->mes_tp;
        break;
    }
    
    pos.x = px;
    pos.y = py;
    
    num = 0;
    
    if (count == 0) 
    {
        cflg = 0;
    }
    else 
    {
        cflg = 1;
    }
    
    while (TRUE) 
    {
        cd = *dp++;
        
        switch (cd)
        {
        case 65280:
            pos.x = px;
            pos.y += 30.0f * FontScaleCR;
            continue;
        case 65281:
            pos.x += 14.0f * FontScaleX;
            continue;
        case 65282:
            dp++;
            continue;
        case 65283:
            dp++;
            continue;
        case 65284:
            pos.x += 28.0f * FontScaleX;
            continue;
        case 65024:
        case 65025:
        case 65026:
        case 65027:
        case 65028:
        case 65029:
        case 65030:
        case 65031:
        case 65032:
        case 65033:
        case 65034:
        case 65035:
        case 65036:
        case 65037:
        case 65038:
        case 65039:   
            continue;
        }
        
        if (cd == 65535) 
        {
            break;
        }
        
        bhDispFont(&pos, cd, color, pri);
        
        pos.x += FontScaleX * bhGetFontSize(cd);
        
        num++;
        
        if ((cflg != 0) && (--count <= 0)) 
        {
            return 0;
        }
    }
    
    return num;
}

// 100% matching! 
int bhDispMessageEx(float px, float py, float pri, int mes_typ, int mes_idx, unsigned int argb, int count)
{
    NJS_POINT2 pos;      
    unsigned short* dp;  
    unsigned short cd;   
    int cflg;            
    int num;             
    unsigned int* mes_dp;
    float stx;          
    float sty;          

    switch (mes_typ) 
    {                           
    case 0:
        mes_dp = rom->mesp;
        
        dp = (unsigned short*)((char*)mes_dp + rom->mesp[mes_idx + 1]);
        break;
    case 1:
        mes_dp = sys->mes_sp;
        
        dp = (unsigned short*)((char*)mes_dp + sys->mes_sp[mes_idx + 1]);
        break;
    default:
        dp = sys->mes_tp;
        break;
    }
    
    pos.x = px;
    pos.y = py;
    
    num = 0;
    
    if (count == 0) 
    {
        cflg = 0;
    }
    else 
    {
        cflg = 1;
    }
    
    while (TRUE) 
    {
        cd = *dp++;
        
        switch (cd)
        {
        case 65280:
            pos.x = px;
            pos.y += 30.0f * FontScaleCR;
            continue;
        case 65281:
            pos.x += 14.0f * FontScaleX;
            
            if ((cflg != 0) && (--count <= 0)) 
            {
                return 0;
            }
            
            continue;
        case 65282:
            dp++;
            continue;
        case 65283:
            dp++;
            continue;
        case 65284:
            pos.x += 28.0f * FontScaleX;
            continue;
        case 65024:
        case 65025:
        case 65026:
        case 65027:
        case 65028:
        case 65029:
        case 65030:
        case 65031:
        case 65032:
        case 65033:
        case 65034:
        case 65035:
        case 65036:
        case 65037:
        case 65038:
        case 65039:   
            continue;
        }
        
        if (cd == 65535) 
        {
            break;
        }
        
        bhDispFontEx(&pos, cd, argb, pri);
        
        pos.x += FontScaleX * bhGetFontSize(cd);
        
        num++;
        
        if ((cflg != 0) && (--count <= 0)) 
        {
            return 0;
        }
    }
    
    return num;
}

// 99.79% matching
void bhDispTime(NJS_POINT2 *pos, unsigned int flg, int time, int color, float pri) 
{ 
    static int ntb[10] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    NJS_POINT2 dps;
    int hour;
    int min;
    int sec;
    int msc;
    unsigned short cd;

    dps.x = pos->x; 
    dps.y = pos->y; 
    
    hour = time / 216000; 
    
    if (sys->gm_mode == 3) 
    { 
        if (hour >= 1) 
        {
            hour = 0; 
            
            min = 59; 
            sec = 59;
            msc = 99; 
        } 
        else
        {
            hour = 0;
            
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
            msc = ((time % 60) * 10) / 6; 
        }
    } 
    else 
    {
        if (hour > 99) 
        {
            hour = 99; 
            
            min = 59; 
            sec = 59;
        } 
        else 
        { 
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
        }
        
        msc = ((time % 60) * 10) / 6; 
    }

    if ((flg & 0x8)) 
    { 
        bhDispFont(&dps, ntb[hour / 10], color, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFont(&dps, ntb[hour % 10], color, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFont(&dps, 26, color, pri); 
        dps.x += FontScaleX * bhGetFontSize(26);       
    }
    
    if ((flg & 0x4)) 
    { 
        if (((!(flg & 0x8)) && (min / 10)) || ((flg & 0x8))) 
        { 
            bhDispFont(&dps, ntb[min / 10], color, pri);
        }
        
        dps.x += FontScaleX * 20.0f;
        
        bhDispFont(&dps, ntb[min % 10], color, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        if ((flg & 0x8)) 
        {
            cd = 26;
        }
        else 
        {
            cd = 7;
        }
        
        bhDispFont(&dps, cd, color, pri); 
        dps.x += FontScaleX * bhGetFontSize(cd); 
    }
    
    if ((flg & 0x2)) 
    { 
        bhDispFont(&dps, ntb[sec / 10], color, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFont(&dps, ntb[sec % 10], color, pri);
        dps.x += FontScaleX * 20.0f;
        
        if (!(flg & 0x8)) 
        {
            bhDispFont(&dps, 2, color, pri);
            dps.x += FontScaleX * bhGetFontSize(2);
        }
    }
    
    if ((flg & 0x1))
    { 
        bhDispFont(&dps, ntb[msc / 10], color, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFont(&dps, ntb[msc % 10], color, pri);
    }
}

// 99.79% matching
void bhDispTimeEx(NJS_POINT2* pos, unsigned int flg, int time, unsigned int argb, float pri)
{ 
    static int ntb[10] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    NJS_POINT2 dps;
    int hour;
    int min;
    int sec;
    int msc;
    unsigned short cd;

    dps.x = pos->x; 
    dps.y = pos->y; 
    
    hour = time / 216000; 
    
    if (sys->gm_mode == 3) 
    { 
        if (hour >= 1) 
        {
            hour = 0; 
            
            min = 59; 
            sec = 59;
            msc = 99; 
        } 
        else
        {
            hour = 0;
            
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
            msc = ((time % 60) * 10) / 6; 
        }
    } 
    else 
    {
        if (hour > 99) 
        {
            hour = 99; 
            
            min = 59; 
            sec = 59;
        } 
        else 
        { 
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
        }
        
        msc = ((time % 60) * 10) / 6; 
    }

    if ((flg & 0x8)) 
    { 
        bhDispFontEx(&dps, ntb[hour / 10], argb, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFontEx(&dps, ntb[hour % 10], argb, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFontEx(&dps, 26, argb, pri); 
        dps.x += FontScaleX * bhGetFontSize(26);       
    }
    
    if ((flg & 0x4)) 
    { 
        if (((!(flg & 0x8)) && (min / 10)) || ((flg & 0x8))) 
        { 
            bhDispFontEx(&dps, ntb[min / 10], argb, pri);
        }
        
        dps.x += FontScaleX * 20.0f;
        
        bhDispFontEx(&dps, ntb[min % 10], argb, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        if ((flg & 0x8)) 
        {
            cd = 26;
        }
        else 
        {
            cd = 7;
        }
        
        bhDispFontEx(&dps, cd, argb, pri); 
        dps.x += FontScaleX * bhGetFontSize(cd); 
    }
    
    if ((flg & 0x2)) 
    { 
        bhDispFontEx(&dps, ntb[sec / 10], argb, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFontEx(&dps, ntb[sec % 10], argb, pri);
        dps.x += FontScaleX * 20.0f;
        
        if (!(flg & 0x8)) 
        {
            bhDispFontEx(&dps, 2, argb, pri);
            dps.x += FontScaleX * bhGetFontSize(2);
        }
    }
    
    if ((flg & 0x1))
    { 
        bhDispFontEx(&dps, ntb[msc / 10], argb, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFontEx(&dps, ntb[msc % 10], argb, pri);
    }
}

// 100% matching!
float bhGetFontSize(unsigned short code)
{
    if (code >= 108) 
    {
        return 0;
    }
    
    return FontSz[code];
}

// 100% matching!
float bhMesLen(unsigned short* dp)
{
    unsigned short cd; 
    float len; 
    
    len = 0;

    while (TRUE) 
    {
        cd = *dp++;

        switch (cd) 
        {
        case 65280:
            continue;
        case 65281:
            len += FontScaleX * 14.0f;
            continue;
        case 65282:
            dp++;
            continue;
        case 65283:
            dp++;
            continue;
        case 65284:
        case 65024:
        case 65025:
        case 65026:
        case 65027:
        case 65028:
        case 65029:
        case 65030:
        case 65031:
        case 65032:
        case 65033:
        case 65034:
        case 65035:
        case 65036:
        case 65037:
        case 65038:
        case 65039:  
            continue;
        }

        if (cd == 65535) 
        {
            break;
        }
        
        len += FontScaleX * bhGetFontSize(cd);
    }

    return len;
}

// 100% matching! 
void bhFontScaleSet(float ScaleX, float ScaleY, float ScaleCR) 
{
    FontScaleX = ScaleX; 
    FontScaleY = ScaleY; 
    
    FontScaleCR = ScaleCR; 
}
