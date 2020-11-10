

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

https://cuijiahua.com/blog/2018/01/basis_36.html
输入两个链表，找出它们的第一个公共结点。

可以先让把长的链表的头砍掉，让两个链表长度相同，这样，
同时遍历也能找到公共结点。此时，时间复杂度O(m+n)，空间复杂度为O(MAX(m,n))。

*/

namespace example_space_6
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

using namespace example_space_6;

class Solution 
{
public:
	
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
	{
		// 如果有一个链表为空，则返回结果为空
		if (pHead1 == NULL || pHead2 == NULL) {
			return NULL;
		}
		// 获得两个链表的长度
		unsigned int len1 = GetListLength(pHead1);
		unsigned int len2 = GetListLength(pHead2);
		
		// 默认 pHead1 长， pHead2短，如果不是，再更改
		ListNode* pHeadLong = pHead1;
		ListNode* pHeadShort = pHead2;
		int LengthDif = len1 - len2;
		// 如果 pHead1 比 pHead2 小
		if (len1 < len2) {
			ListNode* pHeadLong = pHead2;
			ListNode* pHeadShort = pHead1;
			int LengthDif = len2 - len1;
		}
		// 将长链表的前面部分去掉，使两个链表等长
		for (int i = 0; i < LengthDif; i++) {
			pHeadLong = pHeadLong->next;
		}

		while (pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort) {
			pHeadLong = pHeadLong->next;
			pHeadShort = pHeadShort->next;
		}
		return pHeadLong;
	}
private:
	// 获得链表长度
	unsigned int GetListLength(ListNode* pHead) 
	{
		if (pHead == NULL) 
		{
			return 0;
		}
		unsigned int length = 1;
		while (pHead->next != NULL) 
		{
			pHead = pHead->next;
			length++;
		}
		return length;
	}
};

void example_6()
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
		ret = s->FindFirstCommonNode((ListNode*)list, (ListNode*)list1);
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
