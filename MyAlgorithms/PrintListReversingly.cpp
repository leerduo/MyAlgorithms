#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

struct ListNode 
{
	int m_nValue;
	ListNode *m_pNext;
};

//从尾到头打印链表
void PrintListReversingly_Iteratively(ListNode *pHead)
{
	stack<ListNode*> nodes;
	ListNode *pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_pNext);
		nodes.pop();
	}
}

void PrintListReversingly_Recursively(ListNode *pHead)
{
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
		{
			PrintListReversingly_Recursively(pHead);
		}
		printf("%d\t", pHead->m_nValue);
	}
}

//链表的末尾添加一个结点 
void AddToTail(ListNode **pHead, int value)
{
	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;
	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext != NULL)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}
//在链表中找到第一个含有某值得结点并删除该结点的代码
void RemoveNode(ListNode **pHead, int value)
{
	if (pHead == NULL || *pHead == NULL)
	{
		return;
	}
	ListNode *pToBeDeleted = NULL;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}
		if (pNode->m_pNext !=NULL && pNode->m_pNext->m_nValue ==value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if (pToBeDeleted != NULL)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}