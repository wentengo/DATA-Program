#ifndef _BINSEARCH__H_
#define _BINSEARCH__H_

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int BSTDataType;

typedef struct BSTNode
{
	struct BSTNode* _left;
	struct BSTNode* _right;
	BSTDataType _data;
}BSTNode, *pBSTNode;

//·ÇµÝ¹é
pBSTNode BuyBSTNode(BSTDataType x);
int BSTInsert(pBSTNode* tree, BSTDataType x);
const pBSTNode BSTFind(pBSTNode tree, BSTDataType x);
int BSTRemove(pBSTNode* tree, BSTDataType x);
void BSTDestory(pBSTNode* tree);
// µÝ¹é 
int BSTInsertR(pBSTNode* tree, BSTDataType x);
const pBSTNode BSTFindR(pBSTNode tree, BSTDataType x);
int BSTRemoveR(pBSTNode* tree, BSTDataType x);

void BSTInOrder(pBSTNode tree);

#endif