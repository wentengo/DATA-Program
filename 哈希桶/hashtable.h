#ifndef _HASHTABLE__H_
#define _HASHTABLE__H_

#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "stdlib.h"

#define MAX 10

typedef int KeyType;
typedef int ValueType;

typedef struct HashNode
{
	KeyType _key;
	ValueType _value;
	struct HashNode* _next;
}HashNode, *pHashNode;

typedef struct HashTable
{
	pHashNode *_tables;
	size_t _size;
	size_t _N;
}HashTable, *pHashTable;

pHashNode BuyHashNode(KeyType key, ValueType value);
size_t HashFunc(KeyType key, size_t N);
size_t GetNextPrimeNum(size_t cur);
void HashTableInit(pHashTable ht, size_t x);
int HashTableInsert(pHashTable ht, KeyType key, ValueType value);
pHashNode HashTableFind(pHashTable ht, KeyType key);
int HashTableRemove(pHashTable ht, KeyType key);
void HashTableDestory(pHashTable ht);
void Print(pHashTable ht);

#endif