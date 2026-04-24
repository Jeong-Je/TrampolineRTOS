#include "bsw.h"

TASK(Task1)
{
	printfSerial("Hello world\n");
	TerminateTask();
}
