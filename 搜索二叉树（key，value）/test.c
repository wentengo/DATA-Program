#include "binsearch.h"
void test()
{
	pBSTreeNode tree = NULL;
	BSTreeInsertR(&tree, "tree", "树");
	BSTreeInsertR(&tree, "sort", "排序");
	BSTreeInsertR(&tree, "binary", "二分");
	BSTreeInsertR(&tree, "return", "返回");
	BSTreeInsertR(&tree, "hash", "哈希");
	BSTreeInsertR(&tree, "list", "链表");
	//判断一个单词是否拼写正确 
	if (BSTreeFindR(tree, "tee") == NULL)
		printf("0\n");
	else
		printf("1\n");
	//模拟实现一个简单的中英互译的字典 
	printf("%s\n", BSTreeFindR(tree, "tree")->_value);
	printf("%s\n", BSTreeFindR(tree, "return")->_value);
	printf("%s\n", BSTreeFindR(tree, "hash")->_value);
	printf("%s\n", BSTreeFindR(tree, "list")->_value);
	////log文件中有许多异常重复的IP地址，请统计出每个异常IP出现了多少次？
	////将value变为int计数即可
	//BSTreeInsertR(&tree, "1212.1213.123", 0);
	//BSTreeInsertR(&tree, "1212.1213.123", 0);
	//BSTreeInsertR(&tree, "1212.1213.123", 0);
	//BSTreeInsertR(&tree, "1245.1213.123", 0);
	//BSTreeInsertR(&tree, "1254.1213.123", 0);
	//BSTreeInsertR(&tree, "1245.1213.456", 0);
	//printf("%d\n", BSTreeFindR(tree, "1212.1213.123")->_value);
	//printf("%d\n", BSTreeFindR(tree, "1245.1213.123")->_value);
	//printf("%d\n", BSTreeFindR(tree, "1254.1213.123")->_value);
	//printf("%d\n", BSTreeFindR(tree, "1245.1213.456")->_value);
}
int main()
{
	test();
	return 0;
}