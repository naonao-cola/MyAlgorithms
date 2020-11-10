

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
https://cuijiahua.com/blog/2017/11/basis_3.html
输入一个链表，返回一个反序的链表。

*/

namespace example_space_1
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

bool Insert_LinkList(LinkList* list,ListNode* data) 
{
	
	//插到尾部
	int pos = list->size;
	ListNode* pCurrent = &(list->head);
	
	for (int i=0;i<pos;i++)
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

using namespace example_space_1;

class Solution {
public:
	std::vector<int> printListFromTailToHead(ListNode* head) {
		std::stack<int> nodes;
		std::vector<int> result;
		ListNode* node = head;
		while (node != NULL) {
			nodes.push(node->val);
			node = node->next;
		}

		while (!nodes.empty()) {
			result.push_back(nodes.top());
			nodes.pop();
		}
		return result;
	}
};

void example_1()
{

	
	//此处应写成数组
	//输入的数组有要求。
	//默认链表头有一个0
	LinkList* list=Create_LinkList();
	Insert_LinkList(list, &ListNode(67));
	Insert_LinkList(list, &ListNode(0));
	Insert_LinkList(list, &ListNode(24));
	Insert_LinkList(list, &ListNode(58));

	

	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	std::vector<int> ret;
	

	try
	{
		ret = s->printListFromTailToHead((ListNode*)list);
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
