#ifndef __LINKLIST_H__ 
#define __LINKLIST_H__ 

#include "stdio.h" 
#include "assert.h"
#include "string.h"
#include "malloc.h"
#include "stdlib.h"

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;
}List, *pList;

void InitLinkList(pList* pplist);
pList BuyNode(DataType d);
void DestroyLinkList(pList* pplist);
void PushBack(pList* pplist, DataType d);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType d);
void PopFront(pList* pplist);
pList Find(pList plist, DataType d);
void Insert(pList* pplist, pList pos, DataType d);
void Erase(pList* pplist, pList pos);
void Remove(pList* pplist, DataType d);
void RemoveAll(pList* pplist, DataType d);
void PrintLinkList(pList plist);
int GetListLength(pList plist);
void PrintTailToHead(pList plist);

#endif