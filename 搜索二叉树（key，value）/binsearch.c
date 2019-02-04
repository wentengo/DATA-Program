#include "binsearch.h"

pBSTreeNode BuyBSTreeNode(KeyType key, ValueType value)
{
	pBSTreeNode node = (pBSTreeNode)malloc(sizeof(BSTreeNode));
	node->_key = key;
	node->_value = value;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}

int BSTreeInsertR(pBSTreeNode *tree, KeyType key, ValueType value)
{
	assert(tree);
	if (*tree == NULL)
	{
		*tree = BuyBSTreeNode(key, value);
		return 0;
	}
	if (strcmp((*tree)->_key , key)>0)
		return BSTreeInsertR(&(*tree)->_left, key, value);
	else if (strcmp((*tree)->_key, key)<0)
		return BSTreeInsertR(&(*tree)->_right, key, value);
	else
	{
		//(*tree)->_value++;
		return -1;
	}
}

pBSTreeNode BSTreeFindR(pBSTreeNode tree, KeyType key)
{
	if (tree == NULL)
		return NULL;
	if (strcmp((*tree)._key, key)>0)
		return BSTreeFindR(tree->_left, key);
	else if (strcmp((*tree)._key, key)<0)
		return BSTreeFindR(tree->_right, key);
	else
	{
		//tree->_value++;(统计异常IP用)
		return tree;
	}
}

int BSTreeRemoveR(pBSTreeNode *tree, KeyType key)
{
	assert(tree);
	if (*tree == NULL)
		return -1;
	if (strcmp((*tree)->_key, key)>0)
		return BSTreeRemoveR(&(*tree)->_left, key);
	else if (strcmp((*tree)->_key, key)<0)
		return BSTreeRemoveR(&(*tree)->_right, key);
	else
	{
		if ((*tree)->_left == NULL)
			*tree = (*tree)->_right;
		else if ((*tree)->_right == NULL)
			*tree = (*tree)->_left;
		else
		{
			pBSTreeNode left = (*tree)->_left;
			while (left->_right != NULL)
				left = left->_right;
			(*tree)->_key = left->_key;
			(*tree)->_value = left->_value;
			return BSTreeRemoveR(&(*tree)->_left, left->_key);
		}
		return 0;
	}
}