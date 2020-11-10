

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

https://cuijiahua.com/blog/2018/01/basis_55.html
一个链表中包含环，请找出该链表的环的入口结点。

双指针进行；

//确定环的节点
可以使用快慢指针，一个每次走一步，一个每次走两步。如果两个指针相遇，表明链表中存在环，并且两个指针相遇的结点一定在环中。
随后，我们就从相遇的这个环中结点出发，一边继续向前移动一边计数，当再次回到这个结点时，就可以得到环中结点数目了。
*/

namespace example_space_7
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

using namespace example_space_7;

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL) {
			return NULL;
		}
		ListNode* meetingnode = MeetingNode(pHead);
		if (meetingnode == NULL) {
			return NULL;
		}
		// 回环链表结点个数
		int nodesloop = 1;
		// 找到环中结点个数
		ListNode* pNode1 = meetingnode;
		while (pNode1->next != meetingnode)
		{
			pNode1 = pNode1->next;
			nodesloop++;
		}
		pNode1 = pHead;
		// 第一个指针向前移动nodesloop步
		for (int i = 0; i < nodesloop; i++) 
		{
			pNode1 = pNode1->next;
		}
		// 两个指针同时移动，找到环入口
		ListNode* pNode2 = pHead;
		while (pNode1 != pNode2) {
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		return pNode1;
	}
private:
	// 使用快慢指针，找到任意的一个环中结点
	ListNode* MeetingNode(ListNode* pHead) 
	{
		ListNode* pSlow = pHead->next;
		if (pSlow == NULL) {
			return NULL;
		}
		ListNode* pFast = pSlow->next;
		while (pFast != NULL && pSlow != NULL) {
			if (pFast == pSlow) {
				return pFast;
			}
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (pFast != NULL) {
				pFast = pFast->next;
			}
		}
		return NULL;
	}
};

void example_7()
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
		ret = s->EntryNodeOfLoop((ListNode*)list);
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
