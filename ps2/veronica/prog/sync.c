//void(*bhControlEOR)();
//void(*bhControlVSync)();
int OpenDriveTrayFlag;
ROM_WORK* rom;
CAM_WORK cam;
unsigned char BackColorFlag;
int pd_port;
unsigned int palbuf[4096];
unsigned char Pause_Flag;
int SoftResetFlag;

void bhInitVSync();
void bhClearVSync();
void bhControlVSync();
void bhControlEOR();
void bhCheckPadPort();
void bhCheckSoftReset();

// 100% matching! 
void bhInitVSync()
{
    njSetVSyncFunction(bhControlVSync);
    njSetEORFunction(bhControlEOR);
}

// 100% matching! 
void bhClearVSync()
{
    njSetVSyncFunction(NULL);
    njSetEORFunction(NULL);
}

// 100% matching! 
void bhControlVSync()
{
    ExecSoundSynchProgram();
    
    if (!(sys->ss_flg & 0x10000))
    {
        if ((OpenDriveTrayFlag == -1) || ((sys->ss_flg & 0x40000))) 
        {
            njUserExit();
        }
    } 
    else if ((!(sys->tk_flg & 0x40000)) && (OpenDriveTrayFlag == -1))
    {
        sys->ss_flg |= 0x40000;
    }
    
    sys->vsyc_flg++;
    sys->vsyc_ct++;
    
    if (sys->vsyc_ct >= 60) 
    {
        sys->vsyc_ct = 0;
        
        sys->gframe = sys->gfrm_ct;
        
        sys->gfrm_ct = 0;
    }
    
    if ((sys->tk_flg & 0x80))
    {
        if (bhCkFlg(sys->ev_flg, 3) != 0) 
        {
            if (sys->stv_tm < 216000000)
            {
                sys->stv_tm++;
            }
        }
        
        if (((sys->sp_flg & 0x200)) && (sys->evt_tim != 0) && (!(sys->ss_flg & 0x80000000))) 
        {
            sys->evt_tim -= 2;
            
            switch (sys->evt_tmd) 
            {                  
            case 1:
                if (bhCkFlg(sys->ev_flg, 69) == 0)
                {
                    sys->evt_tmd = 0;
                    sys->evt_tim = 0;
                }
                
                break;
            case 2:
                if (bhCkFlg(sys->ev_flg, 67) == 0)
                {
                    sys->evt_tmd = 0;
                    sys->evt_tim = 0;
                }
                
                break;
            case 3:
                if (bhCkFlg(sys->ev_flg, 70) == 0) 
                {
                    sys->evt_tmd = 0;
                    sys->evt_tim = 0;
                }
                
                break;
            }
        }
    }
}

// 99.98% matching
void bhControlEOR()
{
    sys->eor_ct++;
    
    if ((sys->gm_flg & 0x4))
    {
        sys->gm_flg &= ~0x4;
        
        njSetPaletteData(0, 1024, &palbuf);
    }
    
    bhCheckPadPort();
    
    sys->pad_port = pd_port;
    
    if ((!(sys->ts_flg & 0x200)) || (!(sys->ts_flg & 0x400)) || (!(sys->ts_flg & 0x800)) || (!(sys->ts_flg & 0x1000)) || (!(sys->ts_flg & 0x4000)) || (!(sys->ts_flg & 0x8000)) || (!(sys->ts_flg & 0x10000)) || (!(sys->ts_flg & 0x20000)) || ((sys->ts_flg & 0x80)))
    {
        return;
    }
    
    if ((sys->gm_flg & 0x8000)) 
    {
        if (sys->bcl_ct != 0) 
        {
            sys->bcl_ct--;
        }
        else 
        {
            sys->gm_flg &= ~0x8000;
            
            BackColorFlag = 1;
            
            if (!(sys->st_flg & 0x1))
            {
                bhChangeBackColor();
            } 
            else 
            {
                bhChangeBackColorEvt();
            }
        }
    }
    
    if ((sys->gm_flg & 0x200000)) 
    {
        njFogDisable();
    } 
    else if ((sys->gm_flg & 0x10)) 
    {
        if ((sys->gm_flg & 0x40)) 
        {
            if (sys->fog_ct != 0) 
            {
                sys->fog_ct--;
            } 
            else 
            {
                sys->gm_flg &= ~0x10;
                
                if (!(sys->st_flg & 0x100000)) 
                {
                    njSetFogColor(cam.fog_col);
                } 
                else 
                {
                    njSetFogColor(sys->fog_col & 0xFFFFFF);
                }
                
                njGenerateFogTable3(rom->fog, cam.fog_nr, cam.fog_fr);
                
                njSetFogTable(rom->fog);
                
                njFogEnable();
                
                sys->st_flg |= 0x2;
            }
        } 
        else if ((cam.flg & 0x2))
        {
            NO_NAME_21 *temp; // not from the debugging symbols
            
            if (sys->fog_ct != 0)
            {
                sys->fog_ct--;
                return;
            }

            temp = &rom->evcp[cam.evc_no].keyf[cam.keyf_no];
            
            if ((temp->flg & 0x8)) 
            {
                if (!(sys->st_flg & 0x100000)) 
                {
                    njSetFogColor(cam.fog_col);
                } 
                else 
                {
                    njSetFogColor(sys->fog_col & 0xFFFFFF);
                }
                
                njGenerateFogTable3(rom->fog, cam.fog_nr, cam.fog_fr);
                
                njSetFogTable(rom->fog);
                
                njFogEnable();
                
                sys->st_flg |= 0x2;
            } 
            else 
            {
                njFogDisable();
                
                sys->st_flg &= ~0x2;
            }
        }
        else 
        {
            if (sys->fog_ct != 0) 
            {
                sys->fog_ct--;
            }
            
            if (sys->fog_ct <= 0) 
            {
                NO_NAME_23 *temp; // not from the debugging symbols
                
                sys->gm_flg &= ~0x10;

                temp = &rom->cutp[cam.ncut].cam[cam.camver];
                
                if ((temp->flg & 0x8)) 
                {
                    if (!(sys->st_flg & 0x100000)) 
                    {
                        njSetFogColor(cam.fog_col);
                    } 
                    else
                    {
                        njSetFogColor(sys->fog_col & 0xFFFFFF);
                    }
                    
                    njGenerateFogTable3(rom->fog, cam.fog_nr, cam.fog_fr);
                    
                    njSetFogTable(rom->fog);
                    
                    njFogEnable();
                    
                    sys->st_flg |= 0x2;
                } 
                else 
                {
                    njFogDisable();
                    
                    sys->st_flg &= ~0x2;
                }
            }
        }
    }
}

// 100% matching! 
void bhCheckPadPort()
{
    const PDS_PERIPHERALINFO* info;
    
    info = pdGetPeripheralInfo(0);

    if ((info->type & 0x1)) 
    {
        pd_port = 0;
    }
    else 
    {
        pd_port = -1;
        
        if (((sys->tk_flg & 0x80)) && ((!(sys->ts_flg & 0x80)) && ((sys->ts_flg & 0x3DE00) == 0x3DE00)) && (!(sys->st_flg & 0x1C040208)) && (!(sys->cb_flg & 0x7)) && (!(sys->tk_flg & 0x40000)) && ((!(sys->ss_flg & 0x20000000)) && (!(sys->ss_flg & 0x80400000)))) 
        {
            Pause_Flag = 1;
        }
    }
}

// 100% matching!
void bhCheckSoftReset()
{
    if (((!(sys->ss_flg & 0x20000)) && ((sys->tk_flg & 0x3F)) || (!(sys->ss_flg & 0x20000)) && ((sys->ss_flg & 0x400000))) && (SoftResetFlag == 1))
    {
        njUserExit();
    }
}
