#ifndef _BINSEARCH__H_
#define _BINSEARCH__H_

#include "stdio.h"
#include "malloc.h"
#include "assert.h"
#include "string.h"

typedef char* KeyType;
typedef char* ValueType;
//统计异常IP将char*变为int计数

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	KeyType _key;
	ValueType _value;
}BSTreeNode, *pBSTreeNode;

pBSTreeNode BuyBSTreeNode(KeyType key, ValueType value);
int BSTreeInsertR(pBSTreeNode* tree, KeyType key, ValueType value);
pBSTreeNode BSTreeFindR(pBSTreeNode tree, KeyType key);
int BSTreeRemoveR(pBSTreeNode* tree, KeyType key);

#endif