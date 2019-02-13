#include "hashtable.h"

pHashNode BuyHashNode(KeyType key, ValueType value)
{
	pHashNode node = (pHashNode)malloc(sizeof(HashNode));
	node->_key = key;
	node->_value = value;
	node->_next = NULL;
	return node;
}

size_t HashFunc(KeyType key, size_t N)//确定下标
{
	return key % N;
}

size_t GetNextPrimeNum(size_t cur)//确定大小
{
	const int _PrimeSize = 28;
	static const unsigned long _PrimeList[28] = {
		53ul, 97ul, 193ul, 389ul, 769ul, 
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul, 
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul, 
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul, 
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul, 
		1610612741ul, 3221225473ul, 4294967291ul };
	for (int i = 0; i < _PrimeSize; i++)
	{
		if (_PrimeList[i] > cur)
			return _PrimeList[i];
	}
}

void HashTableInit(pHashTable ht,size_t x)
{
	assert(ht);
	ht->_tables = (pHashNode*)malloc(sizeof(pHashNode)*x);
	memset(ht->_tables, 0, sizeof(pHashNode)*x);
	ht->_size = 0;
	ht->_N = x;
}

int HashTableInsert(pHashTable ht, KeyType key, ValueType value)
{
	assert(ht);
	if (ht->_N == ht->_size)
	{
		HashTable newht;
		HashTableInit(&newht, GetNextPrimeNum(ht->_N));
		for (size_t i = 0; i < ht->_N; i++)
		{
			pHashNode cur = ht->_tables[i];
			size_t count = HashFunc(cur->_key, newht._N);
			while (cur != NULL)
			{
				cur->_value = 0;
				pHashNode next = cur->_next;
				cur->_next = newht._tables[count];
				newht._tables[count] = cur;
				while (cur->_next != NULL)
				{
					cur = cur->_next;
					cur->_value++;
				}
				cur = next;
			}
		}
		free(ht->_tables);
		ht->_tables = newht._tables;
		ht->_N = newht._N;
		ht->_size = newht._size;
	}
	size_t index = HashFunc(key, ht->_N);
	pHashNode node = BuyHashNode(key, value);
	if (HashTableFind(ht, key) != NULL)
		return -1;
	node->_next = ht->_tables[index];
	ht->_tables[index] = node;
	while (node->_next != NULL)
	{
		node = node->_next;
		node->_value++;
	}
	ht->_size++;
	return 0;
}

pHashNode HashTableFind(pHashTable ht, KeyType key)
{
	assert(ht);
	pHashNode node = ht->_tables[HashFunc(key, ht->_N)];
	while (node != NULL)
	{
		if (node->_key == key)
			return node;
		else
			node = node->_next;
	}
	return NULL;
}

int HashTableRemove(pHashTable ht, KeyType key)
{
	assert(ht);
	size_t index = HashFunc(key, ht->_N);
	pHashNode cur = ht->_tables[index];
	if (cur->_key == key)
	{
		ht->_tables[index] = ht->_tables[index]->_next;
		free(cur);
		ht->_size--;
		return 0;
	}
	while (cur->_next != NULL)
	{
		if (cur->_next->_key == key)
		{
			pHashNode tmp = cur->_next->_next;
			free(cur->_next);
			cur->_next = tmp;
			ht->_size--;
			return 0;
		}
		else
			cur = cur->_next;
	}
	return -1;
}

void HashTableDestory(pHashTable ht)
{
	assert(ht);
	for (size_t i = 0; i < ht->_N; i++)
	{
		while (ht->_tables[i])
		{
			pHashNode tmp = ht->_tables[i];
			ht->_tables[i] = ht->_tables[i]->_next;
			free(tmp);
		}
	}
	free(ht->_tables);
	ht->_size = 0;
	ht->_N = 0;
}

void Print(pHashTable ht)
{
	assert(ht);
	for (size_t i = 0; i < ht->_N; i++)
	{
		pHashNode node = ht->_tables[i];
		printf("table[%d]->", i);
		while (node != NULL)
		{
			printf("%d.%d->", node->_key, node->_value);
			node = node->_next;
		}
		printf("NULL\n");
	}
}