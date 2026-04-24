#include "bsw.h"

TASK(Task1)
{
    printfSerial("Task1 begins.....");
    mdelay(3000);
    printfSerial("Task1 finishes......");
    TerminateTask();
}


TASK(Task2)
{
    printfSerial("Task2 beigns.......");
    mdelay(3000);
    printfSerial("Task2 finishes.....");
    TerminateTask();
}