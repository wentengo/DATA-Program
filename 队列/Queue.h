#ifndef _QUEUE__H_
#define _QUEUE__H_

#include "stdio.h"
#include "assert.h"
#include "malloc.h"

typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;//∂”Õ∑
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* q);
void QueueDestory(Queue* q);
void QueuePush(Queue* q, DataType x);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
int QueueEmpty(Queue* q);

#endif