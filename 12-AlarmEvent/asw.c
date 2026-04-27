#include "bsw.h"

TASK(Task1)
{
    printfSerial("Task1 begins...");
    mdelay(3000);
    printfSerial("Task1 finishes...");
    TerminateTask();
}


TASK(Task2)
{
    ActivateTask(Task3);
    EventMaskType mask;
    printfSerial("Task2 Begins...");
    printfSerial("Task2 Waits....");
    WaitEvent(Event1 | Event2);


    printfSerial("Task2 Wakes Up...");
    GetEvent(Task2, &mask);

    if(mask & Event1)
    {
        printfSerial("[Event1]");
        ClearEvent(Event1);
    }


    if(mask & Event2)
    {
        
        printfSerial("[Event2]");
        ClearEvent(Event2);
    }

    printfSerial("Task2 Finishes...");
    TerminateTask();
}

TASK(Task3)
{
    digitalWrite(13, HIGH);
    // mdelay(1000);
    // digitalWrite(13, LOW);
    TerminateTask();
}