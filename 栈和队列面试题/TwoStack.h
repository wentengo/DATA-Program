#ifndef _TWOSTACK__H_
#define _TWOTSTACK__H_

#include "stdio.h"
#include "assert.h"
#include "malloc.h"
#include "Stack.h"

typedef int TSDataType;

typedef struct TwoStack
{
	TSDataType* _array;
	size_t _top1;
	size_t _top2;
	int MAX;
}TwoStack;

void TwoStackInit(TwoStack* s);
void TwoStackDestory(TwoStack* s);
void TwoStackPush(TwoStack* s, SDataType x, int n);
void TwoStackPop(TwoStack* s, int n);
TSDataType TwoStackTop(TwoStack* s, int n);
int TwoStackSize(TwoStack* s);
int TwoStackEmpty(TwoStack* s);

#endif