#ifndef _HASH__H_
#define _HASH__H_

#include "stdio.h"
#include "assert.h"
#include "malloc.h"

typedef int KeyType;
typedef int ValueType;

enum Status
{
	EMPTY,   //空
	EXITS,   //非空
	DELETE,  //删除
};

typedef struct HashNode
{
	enum Status _status;  //状态
	KeyType _key;         //值
	ValueType _value;     //冲突的次数
}HashNode;

typedef struct HashTable
{
	HashNode *_tables;
	int _size;   //有效值
	int _len;    //表长
}HashTable;

void HashInit(HashTable* ht, int len);
int HashInsert(HashTable* ht, KeyType key, ValueType value);
HashNode* HashFind(HashTable* ht, KeyType key);
int HashRemove(HashTable* ht, KeyType key);
int HashDestory(HashTable* ht);
void HashPrint(HashTable* ht);
int HashSize(HashTable* ht);
int HashEmpty(HashTable* ht);

#endif