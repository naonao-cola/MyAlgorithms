

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
https://cuijiahua.com/blog/2017/12/basis_14.html
输入一个链表，输出该链表中倒数第k个结点。
*/

namespace example_space_2
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

using namespace example_space_2;
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0) {
			return NULL;
		}
		ListNode *pAhead = pListHead;
		ListNode *pBehind = pListHead;
		for (unsigned int i = 0; i < k - 1; i++) {
			if (pAhead->next != NULL) {
				pAhead = pAhead->next;
			}
			else {
				return NULL;
			}
		}
		while (pAhead->next != NULL) {
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		return pBehind;
	}
};

void example_2()
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
		ret = s->FindKthToTail((ListNode*)list,2);
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
