#include "bitmap.h"

void test()
{
	BitMap bm;
	int arr[] = { 1, 3, 7, 4, 12, 16, 19, 13, 22, 18 };
	BitMapInit(&bm, 10);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		BitMapSet(&bm, arr[i]);
	}
	for (size_t j = 0; j < bm._range; j++)
	{
		printf("%d ", bm._bits[j]);
	}
	printf("\n");
	printf("%d\n", BitMapTest(&bm, 16));
	BitMapReset(&bm, 16);
	printf("%d\n", BitMapTest(&bm, 16));
}

int main()
{
	test();
	return 0;
}