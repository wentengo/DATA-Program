#include "head.h"

void Headprin(Heap* hp)
{
	int i = 0;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void Swap(HPDataType* a, HPDataType* b)//½»»»
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustDown(Heap* hp, int root)//µ÷¶Ñ
{
	assert(hp);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < hp->_size)
	{
		if (child+1<hp->_size&&hp->_a[child]<hp->_a[child+1])
			child++;
		if (hp->_a[child]>hp->_a[parent])
		{
			Swap(&hp->_a[child], &hp->_a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	int i = 0;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = 0;
	hp->_capacity = n;
	for (i = 0; i < n;i++)
	{
		hp->_a[i] = a[i];
		hp->_size++;
	}
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp, i);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	hp->_a[hp->_size++] = x;
	int n = ++hp->_capacity;
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp, i);
	}
}

void HeapPop(Heap* hp)
{
	assert(hp);
	hp->_a[0] = hp->_a[hp->_size - 1];
	int n=--hp->_capacity;
	--hp->_size;
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp, i);
	}
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size ? 0 : 1;
}

void Adjust(HPDataType* a,int i,int n)
{
	assert(a);
	int parent = i;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child < n&&a[child] < a[child + 1])
			++child;
		if (a[child]>a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

int HeapSort(HPDataType* a, int n)
{
	assert(a);
	for (int i = n - 1 / 2; i >= 0; i--)
	{
		Adjust(a, i, n);
	}
	return a;
}