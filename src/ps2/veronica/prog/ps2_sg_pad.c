#include "ps2_sg_pad.h" 
#include "padman.h"
#include "ps2_sg_pdvib.h"
#include "main.h"

unsigned int Old_sys_cnt;
static u_long128 Padd1[scePadDmaBufferMax] __attribute__((aligned(64)));
static u_long128 Padd2[scePadDmaBufferMax] __attribute__((aligned(64)));
PAD_STATUS Pad_status;
unsigned char Pad_rdata2[32];
unsigned char Pad_rdata1[32];
unsigned char ChkCnt;
unsigned char PadCnt;
PDS_PERIPHERALINFO pgp_info;
unsigned int Pad_state[2];
PAD_INFO c; /* unused */
PAD_STATUS Pad_status2; /* unused */

// 100% matching!
void pdInitPeripheral(Sint32 logic, void* recvbuf, void* sendbuf)
{
    Pad_status.routine_0 = 0;
    
    Pad_status.be_flag = 0;
    
    Pad_status.type = 0;
    
    Pad_status.act_data[0] = 0;
    Pad_status.act_data[1] = 1;
    Pad_status.act_data[2] = 255;
    Pad_status.act_data[3] = 255;
    Pad_status.act_data[4] = 255;
    Pad_status.act_data[5] = 255;
}

// 100% matching!
void pdExitPeripheral(void)
{ 
    int ret1;
    int ret2;

    ret1 = scePadPortClose(0, 0);
    
    if (ret1 != 1) 
    {
        return; 
    }

    ret2 = scePadPortClose(1, 0);
    
    if (ret2 != 1)
    {
        return;
    }
} 

// 97.66% matching
const PDS_PERIPHERAL* pdGetPeripheral(Uint32 port)
{
    static PDS_PERIPHERALINFO pp_info;
    static PDS_PERIPHERAL pp;
    PAD_WORK *pad_wk; 
    unsigned char *pad_data; 
    int temp; // not from the debugging symbols

    pad_wk = &Ps2_pad.pad1;
    
    pad_data = Pad_rdata1;
    
    if (port == 1) 
    {
        pad_data = Pad_rdata2;
        
        pad_wk = &Ps2_pad.pad2;
    }
    
    if (Ps2_sys_cnt != Old_sys_cnt) 
    {
        Ps2_pad_read();
        
        temp = 55541;
        
        pp.id = pad_data[1] / 16;
        
        pp.support = temp;
        
        pp.on = pad_wk->on;
        pp.off = ~pad_wk->on;
        
        pp.press = pad_wk->push;
        pp.release = pad_wk->release;
        
        pp.l = pad_data[16];
        pp.r = pad_data[17];
        
        pp.x1 = pad_data[6] - 128;
        pp.y1 = pad_data[7] - 128;
        
        pp_info.type = 1;
          
        pp.x2 = 0;
        pp.y2 = 0;
        
        pp.name = NULL;
        
        pp.old = 0;
        
        pp.info = &pp_info;

        Old_sys_cnt = Ps2_sys_cnt;
        
        pp_info.connector_dir[0] = 0;
        pp_info.connector_dir[1] = 0;
        
        Ps2_Read_Key(&pp, pad_wk);
        
        return &pp;
    }
    
    return &pp;
}

// 100% matching! 
const PDS_PERIPHERALINFO* pdGetPeripheralInfo(Uint32 port)
{
    pgp_info.type = 1;
    
    if (scePadGetState(0, 0) != 6) 
    {
        if (ChkCnt >= 3)
        {
            pgp_info.type = 0;
        } 
        else
        {
            ChkCnt++;
        }
        
        PadCnt = 3;
    } 
    else if (PadCnt != 0) 
    {
        PadCnt--;
        
        pgp_info.type = 0;
    }
    else if (scePadInfoMode(0, 0, 1, 0) != 7) 
    {
        pgp_info.type = 0;
    }
    else if (scePadInfoPressMode(0, 0) != 0) 
    {
        ChkCnt = 0;
    } 
    else 
    {
        pgp_info.type = 0;
    }
    
    return &pgp_info;
}

// 100% matching!
void pdSetMode(Sint32 mode)
{

}

// 99.87% matching
void Ps2_pad_read()
{
	unsigned int info; 
    PAD_INFO* pad; 
    int* temp; // not from the debugging symbols
    
    pad = &Ps2_pad;
    
    Pad_state[0] = scePadGetState(0, 0);
    
    if ((Pad_state[0] == 6) || (Pad_state[0] == 2))
    {
        if ((Pad_status.be_flag & 0x1))
        {
            info = Pad_status.type;
            
            if (info != scePadInfoMode(0, 0, 1, 0))
            {
                Pad_status.be_flag = 0;
                
                Pad_status.routine_0 = 0;
            }
            
            scePadRead(0, 0, Pad_rdata1);
        } 
        else 
        {
            switch (Pad_status.routine_0)
            {
            case 0:
                info = scePadInfoMode(0, 0, 1, 0);
                
                if ((info == 7) || (info == 4))
                {
                    Pad_status.routine_0 = 1;
                    
                    Pad_status.be_flag |= 0x2;
                }
                
                break;
            case 1:
                info = scePadInfoMode(0, 0, 2, 0);
                
                if (info == 2)
                {
                    Pad_status.be_flag |= 0x8;
                }
                
                Pad_status.routine_0 = 2;
                break;
            case 2:
                info = scePadSetMainMode(0, 0, 1, 3);
                
                if (info == 1)
                {
                    Pad_status.routine_0 = 3;
                }
                
                break;
            case 3:
                info = scePadGetReqState(0, 0);
                
                switch (info) 
                {
                case 1:
                    Pad_status.routine_0 = 2;
                    break;
                case 0:
                    Pad_status.routine_0 = 4;
                    
                    Pad_status.be_flag |= 0x10;
                    break;
                }
               
                break;
            case 4:
                info = scePadSetActAlign(0, 0, Pad_status.act_data);
                
                if (info != 0)
                {
                    Pad_status.routine_0 = 5;
                }
                
                break;
            case 5:
                info = scePadGetReqState(0, 0);
                
                switch (info) 
                {
                case 1:
                    Pad_status.routine_0 = 4;
                    break;
                case 0:
                    Pad_status.routine_0 = 6;
                    
                    Pad_status.be_flag |= 0x20;
                    break;
                }
            
                break;
            case 6:
                info = scePadInfoMode(0, 0, 1, 0);
                
                if (info == 7)
                {
                    Pad_status.be_flag |= 0x4;
                }
                
                Pad_status.routine_0 = 7;
                break;
            case 7:
                info = scePadInfoPressMode(0, 0);
                
                if (info != 0)
                {
                    info = scePadEnterPressMode(0, 0);
                    
                    if (info != 0) 
                    {
                        Pad_status.be_flag |= 0x4;
                    
                        Pad_status.routine_0 = 8;
                    }
                }
                
                break;
            case 8:
                info = scePadGetReqState(0, 0);
            
                switch (info) 
                {
                case 1:
                    Pad_status.routine_0 = 7;
                    break;
                case 0:
                    Pad_status.routine_0 = 9;
                    break;
                }
                
                break;
            case 9:
                Pad_status.be_flag |= 0x1;
                
                info = scePadInfoMode(0, 0, 1, 0);
                
                Pad_status.type = info;
                
                Pad_status.routine_0 = 0;
                break;
            }
            
            *(unsigned short*)(Pad_rdata1 + 2) = 65535;
        }
    }
    else if (Pad_state[0] == 0)
    {
        Pad_status.routine_0 = 0;
        
        Pad_status.be_flag = 0;
        
        *(unsigned short*)(Pad_rdata1 + 2) = 65535;
        
        *(int*)(Pad_rdata1 + 4) = 0x80808080;
    }
    else
    {
        *(unsigned short*)(Pad_rdata1 + 2) = 65535;
        
        *(int*)(Pad_rdata1 + 4) = 0x80808080;
    }
    
    if (!(Pad_status.be_flag & 0x4))
    {
        *(int*)(Pad_rdata1 + 4) = 0x80808080;
    }
    
    *(unsigned short*)(Pad_rdata1 + 2) ^= 65535;
    
    temp = (int*)(Pad_rdata1 + 4);
    
    *temp = ~*temp;
    
    Pad_set(&pad->pad1, 1);
    
    Ps2_pad_actuater();
}

// 100% matching!
void Ps2_Read_Key(PDS_PERIPHERAL* per, PAD_WORK* pad_wk)
{
    unsigned int i; 
    unsigned int j; 
    PAD_WRK* pp;   
    
    pp = Pad;
    
    for (i = 0; i < 4; i++) 
    {
        pp[i].OldPerType = pp[i].PerType;
        
        if (per->info->type == 0) 
        {
            pp[i].PerType = 0;
        } 
        else if ((per->info->type & 0x40)) 
        {
            pp[i].PerType = 6;
        } 
        else if ((per->info->type & 0x80))
        {
            pp[i].PerType = 5;
        } 
        else
        {
            pp[i].PerType = -1;
            
            if ((per->info->type & 0x1)) 
            { 
                for (j = 0; ButtonInfo[j].Button != 0; j++)
                {
                    if (ButtonInfo[j].Button == (ButtonInfo[j].Button & per->support)) 
                    {
                        pp[i].PerType = ButtonInfo[j].Type;
                        break;
                    }
                } 
            }
        }
        
        if (pp[i].PerType == 1) 
        {
            pp[i].PerTypeEx = 1;
            
            pp[i].on = per->on;
            
            pp[i].press = per->press;
            
            pp[i].l = per->l;
            pp[i].r = per->r;
            
            pp[i].x1 = per->x1;
            pp[i].y1 = per->y1;
            
            pp[i].x2 = per->x2;
            pp[i].y2 = per->y2;
            
            if (pp[i].Calibrate >= 0) 
            {
                pp[i].on2old = pp[i].on2;
                
                pp[i].on2 = 0;
                
                if (pp[i].x1 < (-64 - pp[i].Calibrate)) 
                {
                    pp[i].on2 |= 0x2000;
                }
                
                if (pp[i].x1 > (pp[i].Calibrate + 64)) 
                {
                    pp[i].on2 |= 0x8000;
                }
                
                if (pp[i].y1 < (-64 - pp[i].Calibrate)) 
                {
                    pp[i].on2 |= 0x4000;
                }
                
                if (pp[i].y1 < (pp[i].Calibrate + 64)) 
                {
                    pp[i].on2 |= 0x1000;
                }
                
                pp[i].press2 = ~pp[i].on2old & pp[i].on2;
                
                pp[i].on |= pp[i].on2;
                
                if (((pp[i].on & 0x1000)) && ((pp[i].on & 0x4000))) 
                {
                    pp[i].on &= ~0x4000;
                }
                
                if (((pp[i].on & 0x8000)) && ((pp[i].on & 0x2000))) 
                {
                    pp[i].on &= ~0x2000;
                }
                
                pp[i].press |= pp[i].press2;
                
                if (((pp[i].press & 0x1000)) && ((pp[i].press & 0x4000))) 
                {
                    pp[i].press &= ~0x4000;
                }
                
                if (((pp[i].press & 0x8000)) && ((pp[i].press & 0x2000))) 
                {
                    pp[i].press &= ~0x2000;
                }
            }
        }
        else
        {
            pp[i].PerTypeEx = 0;
            
            pp[i].on = 0;
            
            pp[i].press = 0;
            
            pp[i].l = 0;
            pp[i].r = 0;
            
            pp[i].x1 = 0;
            pp[i].y1 = 0;
            
            pp[i].x2 = 0;
            pp[i].y2 = 0;
        }
        
        Ps2_MakeRepeatKey(i, pad_wk);
    } 
    
    if (Pad[CurrentPortId].SoftReset != 0)
    {
        SoftResetFlag = 1;
    }
}

// 100% matching!
void Ps2_MakeRepeatKey(unsigned int Id, PAD_WORK* pad_wk)
{
    Pad[Id].Rept = pad_wk->onon;
}

// 100% matching!
void Pad_set(PAD_WORK* pbt, unsigned short pad_num)
{
    short i; 
    unsigned char* pad_data; 
	
    pad_data = Pad_rdata1;
    
    if (pad_num == 2) 
    {
        pad_data = Pad_rdata2;
    }
    
    pbt->old = pbt->on;
    
    pbt->on = (pad_data[2] << 8) | pad_data[3];
    
    if (pbt->lh > 192) 
    {
        pbt->on |= 0x8000;
    }
    
    if (pbt->lh < 64) 
    {
        pbt->on |= 0x2000;
    }
    
    if (pbt->lv > 192)
    {
        pbt->on |= 0x1000;
    }
    
    if (pbt->lv < 64) 
    {
        pbt->on |= 0x4000;
    }
    
    pbt->push = pbt->on & (pbt->on ^ pbt->old);
    
    pbt->release = pbt->old & (pbt->on ^ pbt->old);
    
    pbt->rh = pad_data[4];
    pbt->rv = pad_data[5];
    
    pbt->lh = pad_data[6];
    pbt->lv = pad_data[7];
    
    pbt->ar = pad_data[8];
    pbt->al = pad_data[9];
    
    pbt->au = pad_data[10];
    pbt->ad = pad_data[11];
    
    pbt->abu = pad_data[12];
    pbt->abr = pad_data[13];
    
    pbt->abd = pad_data[14];
    pbt->abl = pad_data[15];
    
    pbt->al1 = pad_data[16];
    pbt->al2 = pad_data[17];
    
    pbt->ar1 = pad_data[18];
    pbt->ar2 = pad_data[19];
    
    i = 15;
    
    do 
    {
        if ((1 << i) & ((pbt->on & pbt->push))) 
        {
            pbt->time1[i] = 10;
            
            pbt->onon |= 1 << i;
            
            pbt->time2[i] = 20;
            
            pbt->repeat |= 1 << i;
        } 
        else if ((pbt->on & (1 << i))) 
        { 
            if (pbt->time1[i] != 0) 
            {
                pbt->time1[i]--;
                
                pbt->onon &= ~(1 << i);
            } 
            else
            {
                pbt->time1[i] = 2;
                
                pbt->onon |= 1 << i;
            }
            
            if (pbt->time2[i] != 0) 
            {
                pbt->time2[i]--;
                
                pbt->repeat &= ~(1 << i);
            } 
            else 
            {
                pbt->time2[i] = 4;
                
                pbt->repeat |= 1 << i;
            }
        } 
        else 
        {
            pbt->onon &= ~(1 << i);
            
            pbt->time1[i] = 0;
            
            pbt->repeat &= ~(1 << i);
            
            pbt->time2[i] = 0;
        }
        
        i--;
    } while (i >= 0);
}

// 100% matching! 
void Pad_init()
{
    while (scePadInit(0) == 0);
    
    scePadPortOpen(0, 0, Padd1);
    scePadPortOpen(1, 0, Padd2);
}
