#include "linklist.h"

void InitLinkList(pList* pplist)
{
	assert(pplist);
	*pplist = NULL;
}
pList BuyNode(DataType d)
{
	pList node = (pList)malloc(sizeof(List));
	node->data = d;
	node->next = NULL;
	return node;
}
void DestroyLinkList(pList* pplist)
{
	assert(pplist);
	while ((*pplist)!=NULL)
	{
		PopBack(pplist);
	}
}
void PushBack(pList* pplist, DataType d)
{
	
	if (*pplist == NULL)
		*pplist = BuyNode(d);
	else
	{
		pList p = *pplist;
		while (p->next)
		{
			p = p->next;
		}
		p->next = BuyNode(d);
	}
}
void PopBack(pList* pplist)
{
	assert(pplist);
	if (*pplist == NULL)
		return;
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		pList tmp = *pplist;
		while (tmp->next->next)
		{
			tmp = tmp->next;
		}
		free(tmp->next);
		tmp->next = NULL;
	}
}
void PushFront(pList* pplist, DataType d)
{
	assert(pplist);
	pList p = BuyNode(d);
	p->next = *pplist;
	*pplist = p;
}
void PopFront(pList* pplist)
{
	assert(pplist);
	pList p;
	if (*pplist == NULL)
		return;
	else
	{
		p = (*pplist)->next;
		free(*pplist);
		*pplist = p;
	}
}
pList Find(pList plist, DataType d)
{
	assert(plist);
	while (plist)
	{
		if (plist->data == d)
			return plist;
		else
			plist = plist->next;
	}
	return NULL;
}
//在指定位置之前插入一个值 
void Insert(pList* pplist, pList pos, DataType d)
{
	assert(pplist);
	pList tmp = *pplist;
	while (tmp->next->data != pos->data)
	{
		tmp = tmp->next;
	}
	pos = tmp->next;
	tmp->next = BuyNode(d);
	tmp->next->next = pos;
}
//指定位置删除 
void Erase(pList* pplist, pList pos)
{
	assert(pplist);
	pList tmp = *pplist;
	if (tmp == NULL)
		return;
	if (tmp->next == NULL)
	{
		PopBack(pplist);
		return;
	}
	while (tmp->next != pos)
	{
		tmp = tmp->next;
	}
	pos = tmp->next->next;
	free(tmp->next);
	tmp->next = pos;
}
//删除指定元素
void Remove(pList* pplist, DataType d)
{
	assert(pplist);
	pList tmp = *pplist;
	if (tmp == NULL)
		return;
	if (tmp->next == NULL)
	{
		PopBack(pplist);
		return;
	}
	while (tmp->next->data != d)
	{
		tmp = tmp->next;
	}
	pList cur = tmp->next->next;
	free(tmp->next);
	tmp->next = cur;
}
//删除所有的指定元素
void RemoveAll(pList* pplist, DataType d)
{
	assert(pplist);
	pList tmp = *pplist;
	while (tmp->next)
	{
		if (tmp->data == d)
		{
			pList p = tmp->next;
			free(tmp);
			tmp = p;
		}
		else
		{
			if (tmp->next->data == d)
			{
				pList cur = tmp->next->next;
				free(tmp->next);
				tmp->next = cur;
			}
			else
				tmp = tmp->next;
		}
	}
}
//打印
void PrintLinkList(pList plist)
{
	assert(plist);
	while (plist)
	{
		printf("%d ", plist->data);
		plist=plist->next;
	}
	printf("\n");
}
//链表长
int GetListLength(pList plist)
{
	assert(plist);
	int count = 1;
	while (plist->next != NULL)
	{
		plist = plist->next;
		count++;
	}
	return count;
}
//逆序打印单项链表 
void PrintTailToHead(pList plist)
{
	assert(plist);
	pList tmp = NULL;
	while (plist->next != tmp)
	{
		pList cur = plist;
		while (cur->next->next != tmp)
		{
			cur = cur->next;
		}
		printf("%d ", cur->next->data);
		tmp = cur->next;
	}
	printf("%d\n", plist->data);
}