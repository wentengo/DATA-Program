#include "Queue.h"
#include "Stack.h"
#include "twoqueuestack.h"
#include "twostackqueue.h"
#include "TwoStack.h"

void test()
{
	//Stack q;
	//Stack p;
	//StackInit(&q);
	//SDataType a[] = { 1, 2, 3, 4, 5 };
	//SDataType b[] = { 4, 5, 3, 1, 2 };
	//int x = sizeof(a) / sizeof(a[0]);
	//int y = sizeof(b) / sizeof(b[0]);

	//StackInit(&p);
	///*STPush(&q, &p, 2);
	//STPush(&q, &p, 3);
	//STPush(&q, &p, 5);
	//STPush(&q, &p, 6);
	//STPush(&q, &p, 4);
	//STPush(&q, &p, 1);
	//printf("%d", STMin(&p));*/
	//printf("%d\n", StackOrder(a,b,x,y));
	TwoStack q;
	TwoStackInit(&q);
	TwoStackPush(&q, 1, 1);
	TwoStackPush(&q, 2, 2);
	TwoStackPush(&q, 3, 1);
	TwoStackPush(&q, 4, 2);
	TwoStackPush(&q, 5, 1);
	TwoStackPush(&q, 6, 2);
	TwoStackPush(&q, 7, 1);
	TwoStackPush(&q, 9, 2);
	printf("%d%\n", TwoStackTop(&q, 2));
	printf("%d%\n", TwoStackSize(&q));
}

int main()
{
	test();
	return 0;
}