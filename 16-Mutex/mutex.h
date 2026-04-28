#ifndef MUTEX_H_
#define MUTEX_H_

#define LOCKED 1
#define UNLOCKED 0

typedef struct _MutexType {
    int flag;
    int has_waiter;
    EventMaskType event;
    TaskType waiting_task;
} MutexType;


void InitMutex(MutexType *mutex, EventMaskType event);

void GetMutex(MutexType *mutex);

void ReleaseMutex(MutexType *mutex);

#endif