#ifndef _INTERVIEW__H_
#define _INTERVIEW__H_

#include "linklist.h"

//��������ĸ��ơ� 
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬 
//����һ��randomָ��ָ����������е�һ������ڵ����NULL�� 
//����Ҫ��ʵ�ָ�������������ظ��ƺ�������� 
typedef struct ComplexNode
{
	DataType _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
}ComplexNode, *pComplexNode;

pComplexNode BuyComplexNode(DataType x);
pComplexNode CopyList(ComplexNode* list);

void EraseNotTail(pList *plist);
pList JosephCycle(pList *plist, int num);
void ReverseList(pList *plist);
pList Merge(pList list, pList list2);
pList Merge_R(pList list1, pList list2);
pList FindMidNode(pList head);
pList FindLastKNode(pList head, int k);
pList CheckCycle(pList pList);
int GetCircleLength(pList meet);
pList GetCycleEntryNode(pList list, pList meetNode);
int CheckCross(pList list1, pList list2);
int CheckCrossPlus(pList list1, pList list2);
void UnionSet(pList list1, pList list2);

#endif