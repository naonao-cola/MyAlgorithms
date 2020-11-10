

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
https://cuijiahua.com/blog/2017/12/basis_25.html
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

思路：将复制的节点放到原来的后面，原链表是奇数，新链表是偶数
*/

//此篇不建新随机链表了
namespace example_space_5
{
	struct RandomListNode
	{
		int label;
		struct RandomListNode *next, *random;
		RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {}
	};

	struct RandomLinkList
	{
		RandomListNode head;
		int size;
	};

	RandomLinkList* Create_LinkList() {
		RandomLinkList* list = (RandomLinkList*)malloc(sizeof(RandomLinkList));
		list->size = 0;
		list->head.next = NULL;
		return list;
	}

	bool Insert_LinkList(RandomLinkList* list, RandomListNode* data)
	{

		//插到尾部
		int pos = list->size;
		RandomListNode* pCurrent = &(list->head);

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
using namespace  example_space_5;

class Solution {
public:

	//第一步，复制复杂指针的label和next
	void CloneNodes(RandomListNode* pHead) {
		RandomListNode* pNode = pHead;
		while (pNode != NULL) {
			RandomListNode* pCloned = new RandomListNode(0);
			pCloned->label = pNode->label;
			pCloned->next = pNode->next;
			pCloned->random = NULL;

			pNode->next = pCloned;
			pNode = pCloned->next;
		}
	}

	//第二步，处理复杂指针的random
	void ConnectSiblingNodes(RandomListNode* pHead) {
		RandomListNode* pNode = pHead;
		while (pNode != NULL) {
			RandomListNode* pCloned = pNode->next;
			if (pNode->random != NULL) {
				pCloned->random = pNode->random->next;
			}
			pNode = pCloned->next;
		}
	}

	//第三步，拆分复杂指针
	RandomListNode* ReconnectNodes(RandomListNode* pHead) {
		RandomListNode* pNode = pHead;
		RandomListNode* pClonedHead = NULL;
		RandomListNode* pClonedNode = NULL;

		if (pNode != NULL) {
			pClonedHead = pClonedNode = pNode->next;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}

		while (pNode != NULL) {
			pClonedNode->next = pNode->next;
			pClonedNode = pClonedNode->next;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}
		return pClonedHead;
	}

	RandomListNode* Clone(RandomListNode* pHead)
	{
		CloneNodes(pHead);
		ConnectSiblingNodes(pHead);
		return ReconnectNodes(pHead);
	}
};

void example_5()
{

	//此处应写成数组
	//输入的数组有要求。
	//默认链表头有一个0
	RandomLinkList* pHead = Create_LinkList();
	Insert_LinkList(pHead, &RandomListNode(3));
	Insert_LinkList(pHead, &RandomListNode(5));
	Insert_LinkList(pHead, &RandomListNode(7));
	Insert_LinkList(pHead, &RandomListNode(9));


	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	RandomListNode* ret;


	try
	{
		ret = s->Clone(&(pHead->head));
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
