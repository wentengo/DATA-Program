#include "bintree.h"

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->left = node->right = NULL;
	node->data = x;
	return node;
}

BTNode* BTCreate(BTDataType* a, int n, int *pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);
		++(*pi);
		root->left = BTCreate(a, n, pi);
		++(*pi);
		root->right = BTCreate(a, n, pi);
		return root;
	}
	return NULL;
}

void BTDestory(BTNode* *root)
{
	BTNode* tmp;
	tmp = *root;
	BTDestory(&tmp->left);
	BTDestory(&tmp->right);
	free(root);
	tmp = NULL;
}

int BTSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BTSize(root->left) + BTSize(root->right) + 1;
}

int BTLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
	{
		return 1;
	}
	return BTLeafSize(root->left) + BTLeafSize(root->right);
}

int BTLevelkSize(BTNode* root, int x)
{
	if (root == NULL)
		return 0;
	if (x == 1)
		return 1;
	return BTLevelkSize(root->left, x - 1) + BTLevelkSize(root->right, x - 1);
}

BTNode* BTFind(BTNode* root, BTDataType x)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	ret = BTFind(root->left, x);
	if (ret)
		return ret;
	ret = BTFind(root->right, x);
	if (ret)
		return ret;
	return NULL;
}

void BTPrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c", root->data);
	BTPrevOrder(root->left);
	BTPrevOrder(root->right);
}

void BTInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BTInOrder(root->left);
	printf("%c", root->data);
	BTInOrder(root->right);
}

void BTPostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BTPostOrder(root->left);
	BTPostOrder(root->right);
	printf("%c", root->data);
}

void BTLeveOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	BTNode* front;
	if (root)
		QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		front = QueueFront(&q);
		printf("%c", front->data);
		QueuePop(&q);
		if (front->left!=NULL)
		{
			QueuePush(&q, front->left);
		}
		if (front->right!=NULL)
		{
			QueuePush(&q, front->right);
		}
	}
}
//ÅÐ¶ÏÍêÈ«¶þ²æÊ÷
int BTComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	BTNode* front;
	if (root)
		QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
			break;
	}
	while (QueueEmpty(&q))
	{
		front = QueueFront(&q);
		if (front)
		{
			QueueDestory(&q);
			return 0;
		}
		else
			QueuePop(&q);
	}
	return 1;
}

void BTPrevOrderNonR(BTNode* root)
{
	Stack s;
	StackInit(&s, 20);
	BTNode* top;
	BTNode* cur = root;
	while (cur || StackEmpty(&s)!=0)
	{
		while (cur)
		{
			printf("%c", cur->data);
			StackPush(&s, cur);
			cur = cur->left;
		}
		top = StackTop(&s);
		StackPop(&s);
		cur = top->right;
	}
	printf("\n");
}

void BTInOrderNonR(BTNode* root)
{
	Stack s;
	StackInit(&s, 20);
	BTNode* top;
	BTNode* cur = root;
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}
		
		top = StackTop(&s);
		printf("%c", top->data);

		StackPop(&s);
		cur = top->right;
	}
	printf("\n");
}

void BTPostOrderNonR(BTNode* root)
{
	Stack s;
	StackInit(&s, 20);
	BTNode* top, *prav=NULL;
	BTNode* cur = root;
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}
		top = StackTop(&s);
		if (top->right == NULL || top->right == prav)
		{
			printf("%c", top->data);
			prav = top;
			StackPop(&s);

		}
		else
		{
			cur = top->right;
		}
	}
	printf("\n");
}