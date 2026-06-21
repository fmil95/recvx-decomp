#ifndef _SP_EVT_H_
#define _SP_EVT_H_

#include "types.h"

void bhControlSpEvtComputer();
void bhKeepSpEvtComputer();
void bhInitSpEvtComputer();
void bhMainSpEvtComputer();
void bhExitSpEvtComputer();
void bhEntrySpEvtComputer();
void bhDrawSpEvtComputer();
void bhDrawSpEvtComTime();
void bhDrawSpEvtComVal(int val, float px, float py);
void bhDrawSpEvtComBar(int barno, int col0, int col1);
void bhDrawSpEvtComCharacter();
void bhSetSpEvtComFade(float fdst, float fcnt);
void bhCalcSpEvtComFade();
void bhDrawSpEvtComFade();
void bhEntrySpEvtBoxLine(NJS_LINE* line);
void bhDrawSpEvtBoxLine();
void bhClearComEvtText();
void bhInitComEvtScript();
void bhControlComEvtScript();
void bhControlComEvtKeyboard();

#endif
