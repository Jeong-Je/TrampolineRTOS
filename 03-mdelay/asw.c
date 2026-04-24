#include "bsw.h"

TASK(Task1)
{
	printfSerial("Hello world!\n");
	mdelay(3000);
	printfSerial("Goodbye world!\n");
	TerminateTask();
}
