#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*

https://cuijiahua.com/blog/2018/01/basis_38.html


输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。


求二叉树的深度。可以是递归的方法，属于DFS（深度优先搜索）；
另一种方法是按照层次遍历，属于BFS（广度优先搜索）。

*/





struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

//DFS,递归 深度优先搜索
class Solution 
{
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL) 
		{
			return 0;
		}
		//遍历所有节点
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return (left > right) ? (left + 1) : (right + 1);
	}
};


//BFS广度优先搜索
/*
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL) 
		{
			return 0;
		}
		std::queue<TreeNode*> que;
		int depth = 0;
		que.push(pRoot);
		
		//每搜索一层加1
		while (!que.empty()) 
		{
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) 
			{
				TreeNode* node = que.front();
				que.pop();
				if (node->left) 
				{
					que.push(node->left);
				}
				if (node->right) 
				{
					que.push(node->right);
				}
			}
		}
		return depth;
	}
};
*/
//此处没有构造二叉树，不运行程序
void example_6()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode* pRoot1 = NULL;
	TreeNode* pRoot2 = NULL;
	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->TreeDepth(pRoot1);

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
