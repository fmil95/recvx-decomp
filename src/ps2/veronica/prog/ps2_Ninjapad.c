#include "ps2_Ninjapad.h"

// 100% matching!
const NJS_PERIPHERAL* njGetPeripheral(Uint32 port)
{ 
    return pdGetPeripheral(port);
}
