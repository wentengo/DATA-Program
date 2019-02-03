#ifndef _STACK__H_
#define _STACK__H_

#include "stdio.h"
#include "assert.h"
#include "malloc.h"

typedef struct BTNode* SDataType;

typedef struct Stack
{
	SDataType* _array;
	size_t _top;
	size_t _end;
}Stack;

void StackInit(Stack* s, int n);
void StackDestory(Stack* s);
void StackPush(Stack* s, SDataType x);
void StackPop(Stack* s);
SDataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);

#endif