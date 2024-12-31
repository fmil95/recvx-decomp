#include "types.h"

PDS_PERIPHERAL* njGetPeripheral(unsigned int port);

// 100% matching!
PDS_PERIPHERAL* njGetPeripheral(unsigned int port) 
{ 
    pdGetPeripheral(port);
}
