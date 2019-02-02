#include "twoqueuestack.h"

void StackByTwoQueueInit(StackByTwoQueue* s)
{
	QueueInit(&s->q1);
	QueueInit(&s->q2);
}

void StackByTwoQueuePush(StackByTwoQueue* s, QDataType x)
{
	assert(s);
	if (QueueEmpty(&s->q1))
		QueuePush(&s->q1, x);
	else
		QueuePush(&s->q2, x);
}

void StackByTwoQueuePop(StackByTwoQueue* s)
{
	assert(s);
	Queue in = s->q1;
	Queue out = s->q2;
	if (QueueEmpty(&s->q2))
	{
		in = s->q2;
		out = s->q1;
	}
	while (QueueFront(&in) == QueueBack(&in))
	{
		QueuePush(&out, QueueFront(&in));
		QueuePop(&in);
	}
	QueuePop(&in);
}

QDataType StackByTwoQueueTop(StackByTwoQueue* s)
{
	assert(s);
	if (QueueEmpty(&s->q1))
		return QueueBack(&s->q1);
	return QueueBack(&s->q2);
}

size_t StackByTwoQueueSize(StackByTwoQueue* s)
{
	assert(s);
	return (QueueSize(&s->q1) + QueueSize(&s->q2));
}

int StackByTwoQueueEmpty(StackByTwoQueue* s)
{
	assert(s);
	return (QueueEmpty(&s->q1) && QueueEmpty(&s->q2)) ? 0 : 1;
}
