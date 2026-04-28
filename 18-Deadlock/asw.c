#include "bsw.h"
#include "mutex.h"

MutexType s1;
MutexType s2;

/*
직접 만든 GetMutex/ReleaseMutex를 사용하면 데드락이 발생함
OSEK의 GetResource / ReleaseResource를 사용하면 IPCP이 구현되어 있어
데드락이 발생하지 않음
*/

TASK(TaskH)
{
    printfSerial("<TaskH begins.>");
    mdelay(1000);
    printfSerial("TaskH : Try Lock(S1).");
    //GetMutex(&s1);
    GetResource(S1);
    printfSerial("TaskH : Get Lock(S1).");

    mdelay(3000);

    printfSerial("TaskH : Try Lock(S2).");
    //GetMutex(&s2);
    GetResource(S2);
    printfSerial("TaskH : Get Lock(S2).");

    printfSerial("TaskH : Release Lock(S2).");
    //ReleaseMutex(&s1);
    ReleaseResource(S2);
    printfSerial("TaskL : Release Lock(S1).");
    //ReleaseMutex(&s2);
    ReleaseResource(S1);
    mdelay(1000);
    printfSerial("<TaskH ends.>");

    TerminateTask();
}


TASK(TaskL)
{
    printfSerial("<TaskL begins.>");
    mdelay(1000);
    printfSerial("TaskL : Try Lock(S2).");
    //GetMutex(&s2);
    GetResource(S2);
    printfSerial("TaskL : Get Lock(S2).");

    mdelay(2000);

    printfSerial("TaskL : Try Lock(S1).");
    //GetMutex(&s1);
    GetResource(S1);
    printfSerial("TaskL : Get Lock(S1).");

    printfSerial("TaskL : Release Lock(S1).");
    //ReleaseMutex(&s2);
    ReleaseResource(S1);
    printfSerial("TaskL : Release Lock(S2).");
    //ReleaseMutex(&s1);
    ReleaseResource(S2);
    mdelay(1000);
    printfSerial("<TaskL ends.>");

    TerminateTask();
}

/* This task will be activated every second */
TASK(TickPrint)
{
    static long c = -4;
    printfSerial("\n%4ld: ", c++);

    if(c == -2) {
        InitMutex(&s1, Event1);
        InitMutex(&s2, Event2);
    }
    else if(c == 4) ActivateTask(TaskL);
    else if(c == 6) ActivateTask(TaskH);


    TerminateTask();
}