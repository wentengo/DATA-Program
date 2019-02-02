#ifndef _TWOQUEUESTACK__H_
#define _TWOQUEUESTACK__H_

#include "Queue.h"
#include "Stack.h"

typedef  int TQSDataType;
typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* s);
void StackByTwoQueuePush(StackByTwoQueue* s, QDataType x);
void StackByTwoQueuePop(StackByTwoQueue* s);
QDataType StackByTwoQueueTop(StackByTwoQueue* s);
size_t StackByTwoQueueSize(StackByTwoQueue* s);
int StackByTwoQueueEmpty(StackByTwoQueue* s);

#endif