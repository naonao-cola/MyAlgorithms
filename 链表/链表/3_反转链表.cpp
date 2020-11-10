

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
/*
https://cuijiahua.com/blog/2017/12/basis_15.html
输入一个链表，反转链表后，输出链表的所有元素。。
*/

namespace example_space_3
{
	struct ListNode
	{
		int val;
		struct ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	struct LinkList
	{
		ListNode head;
		int size;
	};

	LinkList* Create_LinkList() {
		LinkList* list = (LinkList*)malloc(sizeof(LinkList));
		list->size = 0;
		list->head.next = NULL;
		return list;
	}

	bool Insert_LinkList(LinkList* list, ListNode* data)
	{

		//插到尾部
		int pos = list->size;
		ListNode* pCurrent = &(list->head);

		for (int i = 0; i < pos; i++)
		{
			pCurrent = pCurrent->next;
		}

		data->next = pCurrent->next;

		//pCurrent->val= data->val;
		pCurrent->next = data;
		(list->size)++;
		return true;
	}
}

using namespace example_space_3;

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* pReversedHead = NULL;
		ListNode* pNode = pHead;
		ListNode* pPrev = NULL;
		while (pNode != NULL) {
			ListNode* pNext = pNode->next;
			if (pNext == NULL) {
				pReversedHead = pNode;
			}
			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
		}
		return pReversedHead;
	}
};

void exapmle_3()
{

	//此处应写成数组
	//输入的数组有要求。
	//默认链表头有一个0
	LinkList* list = Create_LinkList();
	Insert_LinkList(list, &ListNode(67));
	Insert_LinkList(list, &ListNode(0));
	Insert_LinkList(list, &ListNode(24));
	Insert_LinkList(list, &ListNode(58));



	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	ListNode *ret;


	try
	{
		ret = s->ReverseList((ListNode*)list);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << " " << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
