#include "Stack.h"
void test()
{
	Stack q;
	Stack p;
	StackInit(&q,20);
	StackInit(&p,20);
	/*StackPush(&q, 1);
	StackPush(&q, 2);
	StackPush(&q, 3);
	StackPush(&q, 5);
	printf("%d\n", StackTop(&q));
	printf("%d\n", StackSize(&q));
	printf("%d\n", StackEmpty(&q));*/
	STPush(&q, &p, 2);
	STPush(&q, &p, 3);
	STPush(&q, &p, 5);
	STPush(&q, &p, 6);
	STPush(&q, &p, 4);
	STPush(&q, &p, 1);
	printf("%d\n", STMin(&p));
	StackDestory(&q);
	StackDestory(&p);
}
int main()
{
	test();
	return 0;
}