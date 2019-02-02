#ifndef _TWOSTACKQUEUE__H_
#define _TWOSTACKQUEUE__H_

#include "Queue.h"
#include "Stack.h"

typedef  int TSQDataType;
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* q);
void QueueByTwoStackPush(QueueByTwoStack* q, SDataType x);
void QueueByTwoStackPop(QueueByTwoStack* q);
TSQDataType QueueByTwoStackFront(QueueByTwoStack* q);
TSQDataType QueueByTwoStackBack(QueueByTwoStack* q);
size_t QueueByTwoStackSize(QueueByTwoStack* q);
int QueueByTwoStackEmpty(QueueByTwoStack* q);

#endif