#include "bsw.h"

TASK(Task1)
{
    printfSerial("Task1 begins...");
    mdelay(8000);
    printfSerial("Task1 finishes...");
    TerminateTask();
}


TASK(Task2)
{
    printfSerial("Task2 begins...");
    mdelay(3000);
    printfSerial("Task2 finishes...");
    TerminateTask();
}

static const char* error_to_string(StatusType error)
{
    switch(error)
    {
        case E_OK: return "E_OK";
        case E_OS_ACCESS: return "E_OS_ACCESS";
        case E_OS_CALLEVEL: return "E_OS_CALLEVEL";
        case E_OS_ID: return "E_OS_ID";
        case E_OS_LIMIT: return "E_OS_LIMIT";
        case E_OS_NOFUNC: return "E_OS_NOFUNC";
        case E_OS_RESOURCE: return "E_OS_RESOURCE";
        case E_OS_STATE: return "E_OS_STATE";
        case E_OS_VALUE: return "E_OS_VALUE";
        default: return "UNKNOWN_ERROR";
    }
}


void ErrorHook(StatusType error)
{
    printOut("[ErrorHook: ");
    printOut(error_to_string(error));
    printOut("]");
}
