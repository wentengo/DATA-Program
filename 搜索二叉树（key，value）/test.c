#include "binsearch.h"
void test()
{
	pBSTreeNode tree = NULL;
	BSTreeInsertR(&tree, "tree", "��");
	BSTreeInsertR(&tree, "sort", "����");
	BSTreeInsertR(&tree, "binary", "����");
	BSTreeInsertR(&tree, "return", "����");
	BSTreeInsertR(&tree, "hash", "��ϣ");
	BSTreeInsertR(&tree, "list", "����");
	//�ж�һ�������Ƿ�ƴд��ȷ 
	if (BSTreeFindR(tree, "tee") == NULL)
		printf("0\n");
	else
		printf("1\n");
	//ģ��ʵ��һ���򵥵���Ӣ������ֵ� 
	printf("%s\n", BSTreeFindR(tree, "tree")->_value);
	printf("%s\n", BSTreeFindR(tree, "return")->_value);
	printf("%s\n", BSTreeFindR(tree, "hash")->_value);
	printf("%s\n", BSTreeFindR(tree, "list")->_value);
	////log�ļ���������쳣�ظ���IP��ַ����ͳ�Ƴ�ÿ���쳣IP�����˶��ٴΣ�
	////��value��Ϊint��������
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