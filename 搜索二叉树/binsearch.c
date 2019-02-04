#include "binsearch.h"

pBSTNode BuyBSTNode(BSTDataType x)
{
	pBSTNode node = (pBSTNode)malloc(sizeof(BSTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
int BSTInsert(pBSTNode* tree, BSTDataType x)
{
	assert(tree);
	pBSTNode node = BuyBSTNode(x);
	if ((*tree) == NULL)
	{
		(*tree) = node;
		return 0;
	}
	else
	{
		pBSTNode t = *tree;
		while (t)
		{
			if (t->_data > x)
			{
				if (t->_left == NULL)
				{
					t->_left = node;
					return 0;
				}
				else
					t = t->_left;
			}
			else if (t->_data < x)
			{
				if (t->_right == NULL)
				{
					t->_right = node;
					return 0;
				}
				else
					t = t->_right;
			}
			else
				return -1;
		}
	}
}
const pBSTNode BSTFind(pBSTNode tree, BSTDataType x)
{
	assert(tree);
	while (tree)
	{
		if (tree->_data > x)
			tree = tree->_left;
		else if (tree->_data < x)
			tree = tree->_right;
		else
			return tree;
	}
	return NULL;
}
int BSTRemove(pBSTNode* tree, BSTDataType x)
{
	assert(tree);
	pBSTNode t = BSTFindR(*tree, x);
	if (t)
	{
		pBSTNode parent = NULL;
		pBSTNode cur = *tree;
		if (cur->_data != x)
		{
			while (cur->_left != t&&cur->_right != t)
			{
				if (cur->_data > x)
					cur = cur->_left;
				if (cur->_data < x)
					cur = cur->_right;
			}
			parent = cur;
		}
		//叶子结点
		if (t->_left == NULL&&t->_right == NULL)
		{
			if (parent == NULL)
				*tree = NULL;
			else if (parent->_left == t)
				parent->_left = NULL;
			else if (parent->_right == t)
				parent->_right = NULL;
		}
		//只有右孩子
		else if (t->_left == NULL&&t->_right != NULL)
		{
			if (parent == NULL)
				*tree = t->_right;
			else if (parent->_left == t)
				parent->_left = t->_right;
			else if (parent->_right == t)
				parent->_right = t->_right;
		}
		//只有左孩子
		else if (t->_left != NULL&&t->_right == NULL)
		{
			if (parent == NULL)
				*tree = t->_left;
			else if (parent->_left == t)
				parent->_left = t->_left;
			else if (parent->_right == t)
				parent->_right = t->_left;
		}
		//有左右孩子
		else
		{
			pBSTNode left = t->_left;
			pBSTNode lparent = t;
			while (left->_right != NULL)
			{
				lparent = left;
				left = left->_right;
			}
			t->_data = left->_data;
			if (lparent == t)
			{
				lparent->_left = NULL;
				lparent->_right = t->_right;
			}
			else
				lparent->_right = left->_left;
		}
		return 0;
	}
	else
		return -1;
	
}
void BSTDestory(pBSTNode* tree)
{
	assert(tree);
	pBSTNode cur = *tree;
	if (*tree == NULL)
		return;
	BSTDestory(&cur->_left);
	BSTDestory(&cur->_right);
	free(cur);
	cur = NULL;
}
int BSTInsertR(pBSTNode* tree, BSTDataType x)
{
	assert(tree);
	if ((*tree) == NULL)
	{
		*tree = BuyBSTNode(x);
		return 0;
	}
	if ((*tree)->_data>x)
		return BSTInsertR(&(*tree)->_left, x);
	else if ((*tree)->_data<x)
		return BSTInsertR(&(*tree)->_right, x);
	else
		return -1;
}
const pBSTNode BSTFindR(pBSTNode tree, BSTDataType x)
{
	assert(tree);
	if (tree == NULL)
		return NULL;
	if (tree->_data > x)
		return BSTFindR(tree->_left, x);
	else if (tree->_data < x)
		return BSTFindR(tree->_right, x);
	else
		return tree;
}
int BSTRemoveR(pBSTNode* tree, BSTDataType x)
{
	assert(tree);
	if (*tree == NULL)
		return -1;
	if ((*tree)->_data>x)
		return BSTRemoveR(&(*tree)->_left, x);
	else if ((*tree)->_data < x)
		return BSTRemoveR(&(*tree)->_right, x);
	else
	{
		if ((*tree)->_left == NULL)
			*tree = (*tree)->_right;
		else if ((*tree)->_right == NULL)
			*tree = (*tree)->_left;
		else
		{
			pBSTNode left = (*tree)->_left;
			while (left->_right != NULL)
				left = left->_right;
			(*tree)->_data = left->_data;
			return BSTRemoveR(&(*tree)->_left, left->_data);
		}
		return 0;
	}
}
void BSTInOrder(pBSTNode tree)
{
	if (tree == NULL)
		return;
	BSTInOrder(tree->_left);
	printf("%d ", tree->_data);
	BSTInOrder(tree->_right);
}