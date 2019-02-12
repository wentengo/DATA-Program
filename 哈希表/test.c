#include "hash.h"

void test()
{
	HashTable hash;
	//HashNode* hn;
	HashInit(&hash, 10);
	HashInsert(&hash, 1, 0);
	HashInsert(&hash, 2, 0);
	HashInsert(&hash, 3, 0);
	HashInsert(&hash, 4, 0);
	HashInsert(&hash, 5, 0);
	HashInsert(&hash, 6, 0);
	HashInsert(&hash, 7, 0);
	HashInsert(&hash, 8, 0);
	HashInsert(&hash, 9, 0);
	HashInsert(&hash, 10, 0);
	HashInsert(&hash, 21, 0);
	//hn = HashFind(&hash, 10);
	HashPrint(&hash);
	//printf("%d\n", hash._len);
	//printf("%d\n", hn->_value);
	HashRemove(&hash, 21);
	HashPrint(&hash);
	printf("%d\n", HashSize(&hash));
	printf("%d\n", HashEmpty(&hash));
	HashDestory(&hash);

}

int main()
{
	test();
	return 0;
}