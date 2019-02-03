#include "Stack.h"

void StackInit(Stack* s, int n)
{
	assert(s);
	s->_array = (SDataType*)malloc(sizeof(SDataType)*n);
	s->_top = 0;
	s->_end = n;
}

void StackDestory(Stack* s)
{
	assert(s);
	free(s);
	s->_array = NULL;
	s->_end = s->_top=0;
}

void StackPush(Stack* s, SDataType x)
{
	assert(s);
	SDataType* p;
	if (s->_top == s->_end)
	{
		p = (SDataType*)realloc(s->_array, sizeof(SDataType)* 2);
		if (p != NULL)
		{
			s->_array = p;
		}
		s->_end = 2 * s->_end;
	}
	s->_array[s->_top] = x;
	s->_top++;
}

void StackPop(Stack* s)
{
	assert(s);
	if (s->_top == 0)
		return;
	s->_top--;
}

SDataType StackTop(Stack* s)
{
	assert(s);
	return s->_array[s->_top - 1];
}

size_t StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}

int StackEmpty(Stack* s)
{
	assert(s);
	return s->_top == 0 ? 0 : 1;
}