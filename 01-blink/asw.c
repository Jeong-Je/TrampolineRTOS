#include "bsw.h"

TASK(Task1)
{
	digitalWrite(13, HIGH);
	mdelay(2000);
	digitalWrite(13,LOW);
	mdelay(2000);
	digitalWrite(13, HIGH);
	mdelay(2000);
	digitalWrite(13, LOW);
	TerminateTask();
}
