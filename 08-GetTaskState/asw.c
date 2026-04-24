#include "bsw.h"
void printState(TaskType id)
{
    TaskStateType state;
    if(GetTaskState(id, &state) == E_OK)
    {
        switch(state) {
            case SUSPENDED:
                printfSerial("%d: suspended...", id);
                break;
            case READY:
                printfSerial("%d: ready...", id);
                break;
            case WAITING:
                printfSerial("%d: waiting...", id);
                break;
            case RUNNING:
                printfSerial("%d: running...", id);
                break;
        }
    }
}


TASK(Task1)
{
    TaskType id;
    printfSerial("Task1 begins.....");
    printState(Task1);
    printState(Task2);
    mdelay(3000);
    ActivateTask(Task2);
    printState(Task1);
    printState(Task2);
    mdelay(3000);
    GetTaskID(&id);
    printfSerial("Task Id = %d...", id);
    printfSerial("Task1 finishes......");
    ChainTask(TaskM);
}


TASK(Task2)
{
    TaskType id;
    printfSerial("Task2 beigns.......");
    printState(Task1);
    printState(Task2);
    mdelay(3000);
    GetTaskID(&id);
    printfSerial("Task ID = %d...", id);
    printfSerial("Task2 finishes.....");
    ChainTask(TaskM);
}

TASK(TaskM)
{
    printState(Task1);
    printState(Task2);
    TerminateTask();
}
