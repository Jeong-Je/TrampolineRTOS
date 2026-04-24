#include "bsw.h"

TASK(Task1)
{
    printfSerial("Task1 begins.....");
    mdelay(3000);
    ActivateTask(Task2);
    mdelay(3000);
    printfSerial("Task1 finishes......");
    
    TerminateTask();
}


TASK(Task2)
{
    printfSerial("Task2 beigns.......");
    mdelay(3000);
    printfSerial("Task2 finishes.....");
    
    ChainTask(Task3);
}

TASK(Task3)
{
    printfSerial("Task3 beigns.......");
    mdelay(3000);
    printfSerial("Task3 finishes.....");
    
    TerminateTask();
}