#include "Stack.h"

void StackInit(Stack* s)
{
	assert(s);
	s->_array = (SDataType*)malloc(sizeof(SDataType));
	s->_top = 0;
	s->_end = sizeof(SDataType);
}

void StackDestory(Stack* s)
{
	assert(s);
	s->_array = NULL;
	s->_end = s->_top=0;
}

void StackPush(Stack* s, SDataType x)
{
	assert(s);
	SDataType* p;
	if (s->_end != 0 &&s->_top == s->_end)
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

void STPush(Stack* q, Stack* p, SDataType x)
{
	assert(q);
	assert(p);
	StackPush(q, x);
	if (StackEmpty(p) == 0 || StackTop(p) > x)
	{
		StackPush(p, x);
	}
}

void STPop(Stack* q, Stack* p)
{
	assert(q);
	assert(p);
	if (StackTop(q) == StackTop(p))
	{
		StackPop(q);
		StackPop(p);
	}
	else
		StackPop(q);
}

SDataType STMin(Stack* p)
{
	assert(p);
	return StackTop(p);
}

int StackOrder(SDataType* a,SDataType* b,int x,int y)
{
	assert(a);
	assert(b);
	Stack s;
	StackInit(&s);
	int i = 1, j = 0;
	StackPush(&s, a[0]);
	while (j < y)
	{
		if (i < x)
		{
			if (StackTop(&s) != b[j])
			{
				StackPush(&s, a[i]);
				i++;
			}
			else
			{
				StackPop(&s);
				j++;
			}
		}
		else
		{
			if (StackTop(&s) == b[j])
			{
				StackPop(&s);
				j++;
			}
			if (StackEmpty(&s) != 0 && StackTop(&s) != b[j])
				return 0;
		}
	}
	if (StackEmpty(&s) == 0)
		return 1;
}