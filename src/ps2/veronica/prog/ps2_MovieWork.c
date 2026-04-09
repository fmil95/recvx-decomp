#include "../../../ps2/veronica/prog/ps2_MovieWork.h"

VoTag* voBufTag __attribute__((aligned(64)));
VoData* voBufData;
READ_BUF* readBuf;
unsigned char* audioBuff;
TimeStamp* timeStamp;
u_long128* viBufTag;
u_long128* viBufData;
unsigned char* mpegWork;
char* videoDecStack;
/*void* vpWorkMemoryTop; - unused */
