#include "bsw.h"

volatile unsigned long shared = 0;

TASK(Task1)
{
    unsigned long i;
    printfSerial("Task1 Begins....\n");
    for(i = 0; i < 2000000; ++i)
    {
        shared++;
    }

    printfSerial("Added 200000 to shared\n");
    printfSerial("counter = %lu\n", shared);
    printfSerial("Task1 Finishes....\n");


    TerminateTask();
}


TASK(Task2)
{
    
    static unsigned long i = 0;
    if(i < 1000) {
        shared++;
    } else if(i == 1000) {
        printfSerial("Added 1000 to shared\n");
    }
    ++i;
    TerminateTask();
}