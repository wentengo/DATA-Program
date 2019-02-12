#ifndef _HASH__H_
#define _HASH__H_

#include "stdio.h"
#include "assert.h"
#include "malloc.h"

typedef int KeyType;
typedef int ValueType;

enum Status
{
	EMPTY,   //��
	EXITS,   //�ǿ�
	DELETE,  //ɾ��
};

typedef struct HashNode
{
	enum Status _status;  //״̬
	KeyType _key;         //ֵ
	ValueType _value;     //��ͻ�Ĵ���
}HashNode;

typedef struct HashTable
{
	HashNode *_tables;
	int _size;   //��Чֵ
	int _len;    //��
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