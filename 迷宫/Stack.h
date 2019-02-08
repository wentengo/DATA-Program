#ifndef _STACK__H_
#define _STACK__H_

#include "stdio.h"
#include "assert.h"
#include "malloc.h"
#include "stdlib.h"
#include "Maze.h"

typedef struct Pos DataType;

typedef struct Stack
{
	DataType* _array;
	size_t _top;
	size_t _end;
}Stack;

void StackInit(Stack* s, int n);
void StackDestory(Stack* s);
void StackPush(Stack* s, int row, int col);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);

#endif