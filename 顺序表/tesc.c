#include "SeqList.h"

void test()
{
	SeqList p;
	InitSeqList(&p);
	//PushBack(&p, 2);
	//PushFront(&p, 1);
	//PushBack(&p, 3);
	//PushBack(&p, 4);
	//PushBack(&p, 5);
	//PrintSeqList(&p);
	///*PopBack(&p);
	//PopFront(&p);*/
	//PrintSeqList(&p);
	//printf("%d\n", Find(&p, 2));
	//Insert(&p, 1, 9);
	//PrintSeqList(&p);
	////Erase(&p, 1);
	////Remove(&p, 9);
	//PrintSeqList(&p);
	//printf("%d\n", Empty(&p));
	PushBack(&p, 4);
	PushBack(&p, 3);
	PushBack(&p, 5);
	PushBack(&p, 2);
	PushBack(&p, 1);
	//BubbleSort(&p);
	//SelectSort(&p);
	SelectSortOP(&p);
	PrintSeqList(&p);
	printf("%d\n", BinarySearch(&p, 3));
	printf("%d\n", BinarySearch(&p, 10));
	printf("%d\n", BinarySearch_R(&p, 0, Size(&p), 3));

}

int main()
{
	test();
	return 0;
}