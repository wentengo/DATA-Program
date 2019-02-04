#include "binsearch.h"

void test()
{
	pBSTNode tree = NULL;
	printf("%d\n", BSTInsertR(&tree, 10));
	printf("%d\n", BSTInsertR(&tree, 5));
	printf("%d\n", BSTInsertR(&tree, 6));
	printf("%d\n", BSTInsertR(&tree, 7));
	printf("%d\n", BSTInsertR(&tree, 3));
	printf("%d\n", BSTInsertR(&tree, 2));
	printf("%d\n", BSTInsertR(&tree, 4));
	printf("%d\n", BSTInsertR(&tree, 11));
	printf("%d\n", BSTInsertR(&tree, 12));
	printf("%d\n", BSTInsertR(&tree, 13));

	BSTInOrder(tree);
	printf("\n");
	BSTRemoveR(&tree, 3);
	BSTInOrder(tree);
	printf("\n");
	BSTDestory(&tree);
}

int main()
{
	test();
	return 0;
}