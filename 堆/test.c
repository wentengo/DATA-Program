#include "head.h"

void test()
{
	int a[] = { 3, 5, 4, 7, 1, 2 };
	Heap hp;
	int n = sizeof(a) / sizeof(a[0]);
	HeapInit(&hp, a, n);
	Headprin(&hp);
	/*HeapPush(&hp, 8);
	Headprin(&hp);
	HeapPush(&hp, 10);
	Headprin(&hp);
	HeapPush(&hp, 9);
	Headprin(&hp);
	HeapPush(&hp, 11);
	Headprin(&hp);
	HeapPop(&hp);
	Headprin(&hp);
	printf("%d\n", HeapTop(&hp));
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapEmpty(&hp));*/
	HeapDestory(&hp);
}

void test2()
{
	int a[] = { 3, 5, 4, 7, 1, 2 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	test();
	test2();
	return 0;
}