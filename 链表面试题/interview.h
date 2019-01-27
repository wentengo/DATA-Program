#ifndef _INTERVIEW__H_
#define _INTERVIEW__H_

#include "linklist.h"

//复杂链表的复制。 
//一个链表的每个节点，有一个指向next指针指向下一个节点， 
//还有一个random指针指向这个链表中的一个随机节点或者NULL， 
//现在要求实现复制这个链表，返回复制后的新链表。 
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