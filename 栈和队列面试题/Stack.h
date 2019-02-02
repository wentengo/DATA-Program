#ifndef _STACK__H_
#define _STACK__H_

#include "stdio.h"
#include "assert.h"
#include "malloc.h"

typedef int SDataType;

typedef struct Stack
{
	SDataType* _array;
	size_t _top;
	size_t _end;
}Stack;

void StackInit(Stack* s);
void StackDestory(Stack* s);
void StackPush(Stack* s, SDataType x);
void StackPop(Stack* s);
SDataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);

void STPush(Stack* q, Stack* p, SDataType x);
void STPop(Stack* q, Stack* p);
SDataType STMin(Stack*p);

int StackOrder(SDataType* a, SDataType* b, int x, int y);

#endif