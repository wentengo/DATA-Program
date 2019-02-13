#include "hashtable.h"

void test()
{
	HashTable hash;
	HashTableInit(&hash, MAX);
	//HashTableInsert(&hash, 10, 0);
	//printf("%d\n",HashTableInsert(&hash, 10, 0));
	HashTableInsert(&hash, 1, 0);
	HashTableInsert(&hash, 2, 0);
	HashTableInsert(&hash, 3, 0);
	HashTableInsert(&hash, 4, 0);
	HashTableInsert(&hash, 5, 0);
	HashTableInsert(&hash, 6, 0);
	HashTableInsert(&hash, 7, 0);
	HashTableInsert(&hash, 8, 0);
	HashTableInsert(&hash, 9, 0);
	HashTableInsert(&hash, 10, 0);
	HashTableInsert(&hash, 11, 0);
	Print(&hash);
	/*HashTableRemove(&hash, 20);
	Print(&hash);*/
	/*pHashNode node=HashTableFind(&hash, 10);
	printf("%d.%d\n", node->_key, node->_value);*/
	HashTableDestory(&hash);
}

int main()
{
	test();
	return 0;
}