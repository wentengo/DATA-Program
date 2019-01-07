#include "SeqList.h"

//��ʼ�� 
void InitSeqList(PSeqList pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}
//β������ 
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
//β��ɾ�� 
void PopBack(PSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
		return;
	pSeq->size--;
}
//ͷ������ 
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
//ͷ��ɾ�� 
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
//����ָ��Ԫ�� 
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
//ָ��λ�ò��� 
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
//ɾ��ָ��λ��Ԫ�� 
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
//ɾ��ָ��Ԫ�� 
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
//ɾ�����е�ָ��Ԫ�� 
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
//����˳���Ĵ�С 
int Size(PSeqList pSeq)
{
	assert(pSeq);
	return pSeq->size;
}
//�ж�˳����Ƿ�Ϊ�� 
int Empty(PSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
		return 0;
	return 1;
}
//����
void Swap(DataType* a, DataType* b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}
//ð������ 
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
//ѡ������ 
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
//ѡ��������Ż� 
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
//���ֲ��� 
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
//���ֲ��ҵݹ�д�� 
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
//��ӡ 
void PrintSeqList(PSeqList pSeq)
{
	assert(pSeq->size != 0);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->Seq[i]);
	}
	printf("\n");
}
