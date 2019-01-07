#define _CRT_SECURE_NO_WARNINGS
#ifndef _SeqList__h_
#define _SeqList__h_

#include "stdio.h"
#include "string.h"
#include "assert.h"

#define MAX 10

typedef int DataType;
typedef struct SeqList
{
	DataType Seq[MAX];
	int size;
}SeqList, *PSeqList;

void InitSeqList(PSeqList pSeq);
void PushBack(PSeqList pSeq, DataType data); 
void PopBack(PSeqList pSeq); 
void PushFront(PSeqList pSeq, DataType data);
void PopFront(PSeqList pSeq);
int Find(PSeqList pSeq, DataType data);
void Insert(PSeqList pSeq, int pos, DataType data);
void Erase(PSeqList pSeq, int pos);
void Remove(PSeqList pSeq, DataType data);
void RemoveAll(PSeqList pSeq, DataType data);
int Size(PSeqList pSeq);
int Empty(PSeqList pSeq);
void BubbleSort(PSeqList pSeq);
void SelectSort(PSeqList pSeq);
void SelectSortOP(PSeqList pSeq);
int BinarySearch(PSeqList pSeq, DataType data);
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d);
void PrintSeqList(PSeqList pSeq);

#endif