

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
https://cuijiahua.com/blog/2017/12/basis_16.html
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

namespace example_space_4
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

using namespace example_space_4;

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		//判断指针是否为空
		if (pHead1 == NULL) {
			return pHead2;
		}
		else if (pHead2 == NULL) {
			return pHead1;
		}
		ListNode* pMergedHead = NULL;
		if (pHead1->val < pHead2->val) {
			pMergedHead = pHead1;
			pMergedHead->next = Merge(pHead1->next, pHead2);
		}
		else {
			pMergedHead = pHead2;
			pMergedHead->next = Merge(pHead1, pHead2->next);
		}
		return pMergedHead;
	}
};

void example_4()
{

	//此处应写成数组
	//输入的数组有要求。
	//默认链表头有一个0
	LinkList* list = Create_LinkList();
	Insert_LinkList(list, &ListNode(3));
	Insert_LinkList(list, &ListNode(5));
	Insert_LinkList(list, &ListNode(7));
	Insert_LinkList(list, &ListNode(9));


	LinkList* list1 = Create_LinkList();
	Insert_LinkList(list, &ListNode(11));
	Insert_LinkList(list, &ListNode(13));
	Insert_LinkList(list, &ListNode(15));
	Insert_LinkList(list, &ListNode(17));

	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	ListNode *ret;


	try
	{
		ret = s->Merge((ListNode*)list,(ListNode*)list1);
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
