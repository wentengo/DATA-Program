#include "hash.h"

void HashInit(HashTable* ht, int len)
{
	assert(ht);
	ht->_tables = (HashNode*)malloc(sizeof(HashNode)*len);
	for (int i = 0; i < len; i++)
		ht->_tables[i]._status = EMPTY;
	ht->_size = 0;
	ht->_len = len;
}

//HashTable HashCapacity(HashTable* ht, int len)//À©ÈÝ
//{
//	HashTable hash;
//	hash._tables = (HashNode*)malloc(sizeof(HashNode)*len * 2);
//	for (int i = 0; i < len; i++)
//		hash._tables[i]._status = EMPTY;
//	hash._len = len * 2;
//	hash._size = 0;
//	return hash;
//}

int HashInsert(HashTable* ht, KeyType key, ValueType value)
{
	assert(ht);
	int i;
	if (((ht->_size * 10) / ht->_len) == 7)
	{
		HashTable hash;
		//hash = HashCapacity(ht, ht->_len);
		HashInit(&hash, ht->_len * 2);
		for (i = 0; i < ht->_len; i++)
		{
			if (ht->_tables[i]._status == EXITS)
				HashInsert(&hash, ht->_tables[i]._key, 0);
		}
		HashInsert(&hash, key, value);
		ht->_tables = hash._tables;
		ht->_len = hash._len;
		ht->_size = hash._size;
		return 0;
	}
	else
	{
		i = key%ht->_len;
		while (ht->_tables[i]._status == EXITS)
		{
			if (i == ht->_len)
				i = 0;
			else
			{

				ht->_tables[i]._value++;
				i++;
			}
		}
		ht->_tables[i]._key = key;
		ht->_tables[i]._value = value;
		ht->_size++;
		ht->_tables[i]._status = EXITS;
		return 0;
	}
	return -1;
}

HashNode* HashFind(HashTable* ht, KeyType key)
{
	assert(ht);
	int i = key%ht->_len;
	while (ht->_tables[i]._status != EMPTY)
	{
		if (ht->_tables[i]._key == key)
		{
			if (ht->_tables[i]._status == DELETE)
				return NULL;
			else
				return &ht->_tables[i];
		}
		else
		{
			if (i == ht->_len)
				i = 0;
			else
				i++;
		}
	}
	return NULL;
}

int HashRemove(HashTable* ht, KeyType key)
{
	assert(ht);
	HashNode* h = HashFind(ht, key);
	if (h == NULL)
		return -1;
	h->_status = DELETE;
	return 0;
}

int HashDestory(HashTable* ht)
{
	assert(ht);
	free(ht->_tables);
	ht->_tables = NULL;
	ht->_len = ht->_size = 0;
}

void HashPrint(HashTable* ht)
{
	assert(ht);
	for (int i = 0; i < ht->_len; i++)
	{
		if (ht->_tables[i]._status == EXITS)
			printf("table[%d]:%d.%d\n", i, ht->_tables[i]._key, ht->_tables[i]._value);
		else
			printf("table[%d]:NULL.NULL\n",i);
	}
}

int HashSize(HashTable* ht)
{
	return ht->_size;
}

int HashEmpty(HashTable* ht)
{
	return ht->_size == 0 ? 0 : 1;
}