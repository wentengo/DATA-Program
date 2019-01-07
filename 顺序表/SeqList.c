#include "SeqList.h"

//初始化 
void InitSeqList(PSeqList pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}
//尾部插入 
void PushBack(PSeqList pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->size == MAX)
	{
		return;
	}
	pSeq->Seq[pSeq->size] = data;
	pSeq->size++;
}
//尾部删除 
void PopBack(PSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
		return;
	pSeq->size--;
}
//头部插入 
void PushFront(PSeqList pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->size == MAX)
		return;
	int len = pSeq->size;
	while (len > 0)
	{
		pSeq->Seq[len] = pSeq->Seq[len - 1];
		len--;
	}
	pSeq->Seq[0] = data;
	pSeq->size++;
}
//头部删除 
void PopFront(PSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
		return;
	for (int i = 0; i + 1 < pSeq->size; i++)
	{
		pSeq->Seq[i] = pSeq->Seq[i + 1];
	}
	pSeq->size--;
}
//查找指定元素 
int Find(PSeqList pSeq, DataType data)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size;i++)
	{
		if (pSeq->Seq[i] == data)
			return i;
	}
	return -1;
}
//指定位置插入 
void Insert(PSeqList pSeq, int pos, DataType data)
{
	assert(pSeq);
	if (pos == 0)
		PushFront(pSeq, data);
	else
	{
		int len = pSeq->size;
		while (len >= pos)
		{
			pSeq->Seq[len] = pSeq->Seq[len - 1];
			len--;
		}
		pSeq->Seq[pos] = data;
		pSeq->size++;
	}
}
//删除指定位置元素 
void Erase(PSeqList pSeq, int pos)
{
	assert(pSeq);
	while (pos + 1 < pSeq->size)
	{
		pSeq->Seq[pos] = pSeq->Seq[pos + 1];
		pos++;
	}
	pSeq->size--;
}
//删除指定元素 
void Remove(PSeqList pSeq, DataType data)
{
	assert(pSeq);
	int count = Find(pSeq, data);
	while (count + 1 < pSeq->size)
	{
		pSeq->Seq[count] = pSeq->Seq[count + 1];
		count++;
	}
	pSeq->size--;
}
//删除所有的指定元素 
void RemoveAll(PSeqList pSeq, DataType data)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		if (pSeq->Seq[i] == data)
		{
			int j = i;
			Erase(pSeq, j);
			i--;
		}
	}
}
//返回顺序表的大小 
int Size(PSeqList pSeq)
{
	assert(pSeq);
	return pSeq->size;
}
//判断顺序表是否为空 
int Empty(PSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
		return 0;
	return 1;
}
//交换
void Swap(DataType* a, DataType* b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}
//冒泡排序 
void BubbleSort(PSeqList pSeq)
{
	assert(pSeq);
	for (int i = pSeq->size; i > 0; i--)
	{
		for (int j = 0; j+1 < i; j++)
		{
			if (pSeq->Seq[j]>pSeq->Seq[j + 1])
			{
				Swap(&pSeq->Seq[j], &pSeq->Seq[j + 1]);
			}
		}
	}
}
//选择排序 
void SelectSort(PSeqList pSeq)
{
	assert(pSeq);
	int count = 0;
	for (int i = 0; i < pSeq->size; i++)
	{
		count = i;
		for (int j = i + 1; j < pSeq->size; j++)
		{
			if (pSeq->Seq[j] < pSeq->Seq[count])
				count = j;
		}
		if (count != i)
			Swap(&pSeq->Seq[count], &pSeq->Seq[i]);
	}
}
//选择排序的优化 
void SelectSortOP(PSeqList pSeq)
{
	assert(pSeq);
	int left = 0;
	int right = pSeq->size - 1;
	int min = 0, max = 0;
	for (left = 0; left <= right; left++)
	{
		min = left;
		max = right;
		for (int i = left; i <= right; i++)
		{
			if (pSeq->Seq[i] < pSeq->Seq[min])
				min = i;
			if (pSeq->Seq[i]>pSeq->Seq[max])
				max = i;
		}
		if (min!=left)
			Swap(&pSeq->Seq[left], &pSeq->Seq[min]);
		if (max != right)
		{
			Swap(&pSeq->Seq[max], &pSeq->Seq[right]);
			right--;
		}
	}
}
//二分查找 
int BinarySearch(PSeqList pSeq, DataType data)
{
	assert(pSeq);
	int left = 0;
	int right = pSeq->size - 1;
	while (left <= right)
	{
		int tmp = (left + right) / 2;
		if (pSeq->Seq[tmp] == data)
			return tmp;
		if (pSeq->Seq[tmp] < data)
			left = tmp + 1;
		if (pSeq->Seq[tmp]>data)
			right = tmp - 1;
	}
	return -1;
}
//二分查找递归写法 
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d)
{
	assert(pSeq->size != 0);
	int tmp = (left + right) / 2;
	if (left > right)
		return -1;
	if (pSeq->Seq[tmp] == d)
		return tmp;
	if (pSeq->Seq[tmp] < d)
		return BinarySearch_R(pSeq, tmp + 1, right, d);
	if (pSeq->Seq[tmp] < d)
		return BinarySearch_R(pSeq, tmp, right - 1, d);
}
//打印 
void PrintSeqList(PSeqList pSeq)
{
	assert(pSeq->size != 0);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->Seq[i]);
	}
	printf("\n");
}
