#include "bintree.h"

void test()
{
	char array[] = { 'A', 'B', 'D', '#', '#', '#', 'C',
		'E', '#', '#', 'F', '#', '#' };
	int i = 0;
	BTNode*tree = BTCreate(array, sizeof(array) / sizeof(BTDataType), &i);
	/*printf("结点的个数：%d\n", BTSize(tree));
	printf("叶子结点的个数：%d\n", BTLeafSize(tree));
	printf("第K层结点的个数：%d\n", BTLevelkSize(tree, 2));
	printf("是否为完全二叉树？：%d\n", BTComplete(tree));*/
	/*BTPrevOrder(tree);
	printf("\n");
	BTInOrder(tree);
	printf("\n");
	BTPostOrder(tree);
	printf("\n");*/
	//BTPrevOrderNonR(tree);
	BTInOrderNonR(tree);
	//BTPostOrderNonR(tree);
	//BTLeveOrder(tree);
}

int main()
{
	test();
	return 0;
}