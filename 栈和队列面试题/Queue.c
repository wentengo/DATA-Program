#include "Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_head = (QueueNode*)malloc(sizeof(QueueNode));
	q->_tail = q->_head;
	q->_head->_next = NULL;
}

void QueueDestory(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_head;
	QueueNode* tmp;
	while (cur > q->_tail)
	{
		tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
}

void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
	p->_data = x;
	p->_next = NULL;
	q->_tail->_next = p;
	q->_tail = p;
}

void QueuePop(Queue* q)
{
	assert(q);
	if (q->_head == q->_tail)
	{
		return;
	}
	QueueNode* p = q->_head;
	q->_head = q->_head->_next;
	free(p);
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	return (q->_head == q->_tail) ? 0 : q->_head->_next->_data;

}

QDataType QueueBack(Queue* q)
{
	assert(q);
	return (q->_head == q->_tail) ? 0 : q->_tail->_data;
}

int QueueSize(Queue* q)
{
	assert(q);
	size_t sum = 0;
	QueueNode* cur = q->_head->_next;
	while (cur)
	{
		cur = cur->_next;
		sum++;
	}
	return sum;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return (q->_head == q->_tail) ? 0 : 1;
}