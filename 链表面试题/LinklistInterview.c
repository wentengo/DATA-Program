#include "interview.h"

//ɾ��һ����ͷ������ķ�β�ڵ� 
void EraseNotTail(pList *plist)
{
	assert(plist);
	if (*plist == NULL)
		return;
	while ((*plist)->next != NULL)
		PopFront(plist);
}

//������ʵ��Լɪ�� 
pList JosephCycle(pList *plist, int num)
{
	assert(plist);
	pList jlist = NULL;
	pList list = *plist;
	while (list->next != NULL)
		list = list->next;
	list->next = *plist;
	list = *plist;
	while (list != list->next)
	{
		for (int i = 1; i < num - 1; i++)
			list = list->next;
		PushBack(&jlist, list->next->data);
		list->next = list->next->next;
		list = list->next;
	}
	PushBack(&jlist, list->data);
	return jlist;
}

//����/��ת������ 
void ReverseList(pList* plist)
{
	assert(plist);
	pList tmp = NULL;
	pList count = *plist;
	pList c = count;
	while ((c)->next != tmp)
	{
		pList cur = c;
		while (cur->next->next != tmp)
		{
			cur = cur->next;
		}
		if (count == c)
		{
			*plist = cur->next;
			count = *plist;
		}
		else
		{
			count->next = cur->next;
			count->next->next = NULL;
			count = count->next;
		}
		tmp = cur->next;
	}
	count->next = c;
	count->next->next = NULL;
}

//�ϲ�������������,�ϲ�����Ȼ����(�ǵݹ�)
pList Merge(pList list1, pList list2)
{
	assert(list1);
	assert(list2);
	pList list = NULL;
	pList l = NULL;
	if (list1 == NULL&&list2 == NULL)
		return NULL;
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	if (list1->data < list2->data)
	{
		list = list1;
		l = list;
		list1 = list->next;
	}
	else
	{
		list = list2;
		l = list;
		list2 = list2->next;
	}
	while (list1 != NULL&&list2 != NULL)
	{
		if (list1->data < list2->data)
		{
			list->next = list1;
			list1 = list1->next;
		}
		else
		{
			list->next = list2;
			list2 = list2->next;
		}
		list = list->next;
	}
	if (list1 == NULL)
		list->next = list2;
	else
		list->next = list1;
	return l;
}

//�ϲ�������������,�ϲ�����Ȼ����(�ݹ�)
pList Merge_R(pList list1, pList list2)
{
	pList list = NULL;
	if (list1 == NULL&&list2 == NULL)
		return NULL;
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	if (list1->data > list2->data)
	{
		list = list2;
		list->next = Merge_R(list1, list2->next);
	}
	else
	{
		list = list1;
		list->next = Merge_R(list1->next, list2);
	}
	return list;
}

//���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
pList FindMidNode(pList head)
{
	assert(head);
	pList cur = head;
	while (head != NULL&&cur->next != NULL)
	{
		cur = cur->next->next;
		if (cur == NULL)
			break;
		head = head->next;
	}
	return head;
}

//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
pList FindLastKNode(pList head, int k)
{
	assert(head);
	assert(k != 0);
	pList cur = head;
	while ((k--)-1)
	{
		cur = cur->next;
		if (cur == NULL)
			return NULL;
	}
	while (head != NULL&&cur->next != NULL)
	{
		cur = cur->next;
		head = head->next;
	}
	return head;
}

//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ� 
//�ж��Ƿ����
pList CheckCycle(pList plist)
{
	assert(plist);
	pList list = NULL;
	if (plist->next == NULL || plist->next->next == NULL)
		return NULL;
	else
		list = plist->next->next;
	while (list->next != NULL&&list->next->next != NULL)
	{
		if (plist == list)
			return plist;
		else
		{
			plist = plist->next;
			list = list->next->next;
		}
	}
	return NULL;
}

//����
int GetCircleLength(pList meet)
{
	assert(meet);
	pList list1 = meet;
	pList list2 = meet;
	int x = 0;
	while (list1->next!=list2->next->next)
	{
		list1 = list1->next;
		list2 = list2->next->next;
		x++;
	}
	return x + 1;
}

//�������
pList GetCycleEntryNode(pList list, pList meetNode)
{
	assert(list);
	assert(meetNode);
	int n = GetCircleLength(meetNode);
	pList cur = list;
	while (n--)
		cur = cur->next;
	while (cur != list)
	{
		cur = cur->next;
		list = list->next;
	}
	return list;
}

//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 
int CheckCross(pList list1, pList list2)
{
	assert(list1);
	assert(list2);
	while (list1)
	{
		pList cur = list2;
		while (cur)
		{
			if (cur->data = list1->data)
				return list1->data;
			else
				cur = cur->next;
		}
		list1 = list1->next;
	}
	return -1;
}

//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 
int CheckCrossPlus(pList list1, pList list2)
{
	assert(list1);
	assert(list2);
	pList MeetList1 = CheckCycle(list1);
	pList MeetList2 = CheckCycle(list2);
	if ((MeetList1 == NULL&&MeetList2 != NULL) || (MeetList1 != NULL&&MeetList2 == NULL))
		return -1;
	else if (MeetList1 == NULL && MeetList2 == NULL)
		return CheckCross(list1, list2);
	else
	{
		pList ENlist1 = GetCycleEntryNode(list1, MeetList1);
		pList ENlist2 = GetCycleEntryNode(list2, MeetList2);
		int n1 = GetCircleLength(MeetList1);
		int n2 = GetCircleLength(MeetList2);
		if (n1 != n2)
			return -1;
		if (ENlist1 == ENlist2)
		{
			while (list1 != ENlist1)
			{
				pList cur = list2;
				while (cur != ENlist2)
				{
					if (cur->data = list1->data)
						return list1->data;
					else
						cur = cur->next;
				}
				list1 = list1->next;
			}
			return ENlist1->data;
		}
		else
		{
			pList cur = ENlist1->next;
			while (cur != ENlist1)
			{
				if (cur == ENlist2)
					return cur->data;
				else
				{
					cur = cur->next;
					ENlist2 = ENlist2->next->next;
				}
			}
			return -1;
		}
	}
}

//����������������(�)�� 
void UnionSet(pList list1, pList list2)
{
	assert(list1);
	assert(list2);
	while (list1 != NULL&&list2 != NULL)
	{
		while (list1->data >= list2->data)
		{
			if (list1->data == list2->data)
				printf("%d ", list1->data);
			list2 = list2->next;
		}
		list1 = list1->next;
	}
	printf("\n");
}

//���Ƹ�������
pComplexNode BuyComplexNode(DataType x)
{
	pComplexNode node = (pComplexNode)malloc(sizeof(ComplexNode));
	assert(node);
	node->_next = NULL;
	node->_random = NULL;
	node->_data = x;
	return node;
}

pComplexNode CopyList(pComplexNode list)
{
	assert(list);
	pComplexNode cur = list;
	pComplexNode tmp = NULL;
	pComplexNode t = NULL;
	while (cur != NULL)
	{
		pComplexNode node = BuyComplexNode(cur->_data);
		node->_next = cur->_next;
		cur->_next = node;
		cur = cur->_next->_next;
	}
	cur = list;
	while (cur != NULL)
	{
		if (cur->_random == NULL)
			cur->_next->_random = NULL;
		else
			cur->_next->_random = cur->_random->_next;
		cur = cur->_next->_next;
	}
	tmp = list->_next;
	t = tmp;
	while (tmp->_next != NULL)
	{
		tmp->_next = tmp->_next->_next;
		tmp = tmp->_next;
	}
	return tmp;
}