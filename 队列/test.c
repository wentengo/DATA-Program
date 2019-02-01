#include "Queue.h"
void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("%d\n", QueueBack(&q));
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueSize(&q));
}
int main()
{
	test();
	return 0;
}