#include "twostackqueue.h"

void QueueByTwoStackInit(QueueByTwoStack* q)
{
	StackInit(&q->s1);
	StackInit(&q->s2);
}

void QueueByTwoStackPush(QueueByTwoStack* q, SDataType x)
{
	assert(q);
	StackPush(&q->s1, x);
}

void QueueByTwoStackPop(QueueByTwoStack* q)
{
	assert(q);
	if (StackEmpty(&q->s2))
	{
		while (StackEmpty(&q->s1))
		{
			StackPush(&q->s2, StackTop(&q->s1));
			StackPop(&q->s1);
		}
	}
	StackPop(&q->s2);
}

TSQDataType QueueByTwoStackFront(QueueByTwoStack* q)
{
	assert(q);
	if (StackEmpty(&q->s2))
	{
		while (StackEmpty(&q->s1))
		{
			StackPush(&q->s2, StackTop(&q->s1));
			StackPop(&q->s1);
		}
	}
	return StackTop(&q->s2);
}

TSQDataType QueueByTwoStackBack(QueueByTwoStack* q)
{
	assert(q);

	if (StackEmpty(&q->s1))
	{
		while (StackEmpty(&q->s2))
		{
			StackPush(&q->s1, StackTop(&q->s2));
			StackPop(&q->s2);
		}
	}
	return StackTop(&q->s1);
}

size_t QueueByTwoStackSize(QueueByTwoStack* q)
{
	assert(q);
	return (StackSize(&q->s1) + StackSize(&q->s2));
}

int QueueByTwoStackEmpty(QueueByTwoStack* q)
{
	assert(q);
	return (StackEmpty(&q->s1) && StackEmpty(&q->s2)) ? 0 : 1;
}