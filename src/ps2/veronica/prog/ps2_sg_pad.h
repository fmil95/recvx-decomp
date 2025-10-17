#ifndef _PS2_SG_PAD_H_
#define _PS2_SG_PAD_H_

void pdInitPeripheral(Sint32 logic, void* recvbuf, void* sendbuf);
void pdExitPeripheral(void);
const PDS_PERIPHERAL* pdGetPeripheral(Uint32 port);
const PDS_PERIPHERALINFO* pdGetPeripheralInfo(Uint32 port);
void pdSetMode(Sint32 mode);
void Ps2_pad_read();
void Ps2_Read_Key(PDS_PERIPHERAL* per, PAD_WORK* pad_wk);
void Ps2_MakeRepeatKey(unsigned int Id, PAD_WORK* pad_wk);
void Pad_set(PAD_WORK* pbt, unsigned short pad_num);
void Pad_init();

#endif
