#ifndef _HEAD__H_
#define _HEAD__H_

#include <assert.h>
#include <malloc.h>
#include <stdio.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size; 
	int _capacity;
}Heap;

void Headprin(Heap* hp);
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
// 不要直接调Heap
int HeapSort(HPDataType* a, int n);

#endif