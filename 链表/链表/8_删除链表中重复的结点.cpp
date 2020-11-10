

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

https://cuijiahua.com/blog/2018/01/basis_56.html
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5。


*/

namespace example_space_8
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

using namespace example_space_8;

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL) {
			return NULL;
		}
		// 指向当前结点前最晚访问过的不重复结点
		ListNode* pPre = NULL;
		// 指向当前处理的结点
		ListNode* pCur = pHead;
		// 指向当前结点后面的结点
		ListNode* pNext = NULL;

		while (pCur != NULL)
		{
			// 如果当前结点与下一个结点相同
			if (pCur->next != NULL && pCur->val == pCur->next->val) 
			{
				pNext = pCur->next;
				// 找到不重复的最后一个结点位置
				while (pNext->next != NULL && pNext->next->val == pCur->val) 
				{
					pNext = pNext->next;
				}
				// 如果pCur指向链表中第一个元素，pCur -> ... -> pNext ->... 
				// 要删除pCur到pNext, 将指向链表第一个元素的指针pHead指向pNext->next。
				if (pCur == pHead) 
				{
					pHead = pNext->next;
				}
				// 如果pCur不指向链表中第一个元素，pPre -> pCur ->...->pNext ->... 
				// 要删除pCur到pNext，即pPre->next = pNext->next
				else 
				{
					pPre->next = pNext->next;
				}
				// 向前移动
				pCur = pNext->next;
			}
			// 如果当前结点与下一个结点不相同
			else 
			{
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		return pHead;
	}
};

void main()
{

	//此处应写成数组
	//输入的数组有要求。
	//默认链表头有一个0
	LinkList* list = Create_LinkList();
	Insert_LinkList(list, &ListNode(3));
	Insert_LinkList(list, &ListNode(5));
	Insert_LinkList(list, &ListNode(7));
	Insert_LinkList(list, &ListNode(9));




	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	ListNode *ret;


	try
	{
		ret = s->deleteDuplication((ListNode*)list);
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
