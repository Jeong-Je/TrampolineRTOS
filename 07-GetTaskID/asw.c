#include "bsw.h"

TASK(Task1)
{
    TaskType id;
    printfSerial("Task1 begins.....");
    mdelay(3000);
    ActivateTask(Task2);
    mdelay(3000);
    GetTaskID(&id);
    printfSerial("Task Id = %d...", id);
    printfSerial("Task1 finishes......");
    TerminateTask();
}


TASK(Task2)
{
    TaskType id;
    printfSerial("Task2 beigns.......");
    mdelay(3000);
    GetTaskID(&id);
    printfSerial("Task ID = %d...", id);
    printfSerial("Task2 finishes.....");
    TerminateTask();
}