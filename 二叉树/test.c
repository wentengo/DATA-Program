#include "bintree.h"

void test()
{
	char array[] = { 'A', 'B', 'D', '#', '#', '#', 'C',
		'E', '#', '#', 'F', '#', '#' };
	int i = 0;
	BTNode*tree = BTCreate(array, sizeof(array) / sizeof(BTDataType), &i);
	/*printf("���ĸ�����%d\n", BTSize(tree));
	printf("Ҷ�ӽ��ĸ�����%d\n", BTLeafSize(tree));
	printf("��K����ĸ�����%d\n", BTLevelkSize(tree, 2));
	printf("�Ƿ�Ϊ��ȫ����������%d\n", BTComplete(tree));*/
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