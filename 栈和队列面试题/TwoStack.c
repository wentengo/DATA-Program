#include "TwoStack.h"

void TwoStackInit(TwoStack* s, int x)
{
	assert(s);
	s->_array = (TSDataType*)malloc(sizeof(TSDataType)*x);
	s->_top1 = 0;
	s->MAX = x;
	s->_top2 = s->MAX;
}

void TwoStackDestory(TwoStack* s)
{
	assert(s);
	s->_array = NULL;
	s->MAX = s->_top1 = s->_top2 = 0;
}

void TwoStackPush(TwoStack* s, TSDataType x, int n)
{
	assert(s);
	TSDataType* p;
	if (s->_top1 == s->_top2)
	{
		p = (TSDataType*)realloc(s->_array, sizeof(TSDataType)* 2);
		if (p != NULL)
		{
			s->_array = p;
		}
		s->MAX = 2 * s->MAX;
	}
	if (n == 1)
	{
		s->_array[s->_top1] = x;
		s->_top1++;
	}
	if (n == 2)
	{
		s->_array[s->_top2] = x;
		s->_top2--;
	}
}

void TwoStackPop(TwoStack* s, int n)
{
	assert(s);
	if (n == 1)
	{
		if (s->_top1 == 0)
			return;
		s->_top1--;
	}
	if (n == 2)
	{
		if (s->_top2 == 0)
			return;
		s->_top2++;
	}
}

TSDataType TwoStackTop(TwoStack* s, int n)
{
	assert(s);
	if (n == 1)
		return s->_array[s->_top1 - 1];
	if (n == 2)
		return s->_array[s->_top2 + 1];
}

int TwoStackSize(TwoStack* s)
{
	assert(s);
	return s->_top1 + (s->MAX - s->_top2);
}

int TwoStackEmpty(TwoStack* s)
{
	assert(s);
	return s->_top1 == 0 && s->_top2 == s->MAX ? 0 : 1;
}