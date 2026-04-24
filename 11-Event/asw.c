#include "bsw.h"

ISR(ISRPin2)
{
    SetEvent(Task1, Event1);
}


ISR(ISRPin3)
{
    SetEvent(Task1, Event2);
}


TASK(Task1)
{
    EventMaskType mask;
    printfSerial("Task1 Begins...");
    printfSerial("Task1 Waits....");
    WaitEvent(Event1 | Event2);


    printfSerial("Task1 Wakes Up...");
    GetEvent(Task1, &mask);

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

    printfSerial("Task1 Finishes...");
    TerminateTask();
}