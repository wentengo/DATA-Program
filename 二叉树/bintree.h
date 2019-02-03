#ifndef _BINTREE__H_
#define _BINTREE__H_

#include "stdio.h"
#include "malloc.h"
#include "assert.h"
#include "stdlib.h"
#include "Queue.h"
#include "Stack.h"

typedef char BTDataType;
typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTDataType data;
}BTNode;

BTNode* BTCreate(BTDataType* a, int n, int *pi);
void BTDestory(BTNode* *root);
int BTSize(BTNode* root);
int BTLeafSize(BTNode* root);
int BTLevelkSize(BTNode* root,int x);
BTNode* BTFind(BTNode* root,BTDataType x);
void BTPrevOrder(BTNode* root);
void BTInOrder(BTNode* root);
void BTPostOrder(BTNode* root);
void BTLeveOrder(BTNode* root);
int BTComplete(BTNode* root);
void BTPrevOrderNonR(BTNode* root);
void BTInOrderNonR(BTNode* root);
void BTPostOrderNonR(BTNode* root);

#endif