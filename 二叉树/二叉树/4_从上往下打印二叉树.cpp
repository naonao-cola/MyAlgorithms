#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*

https://cuijiahua.com/blog/2017/12/basis_22.html

从上往下打印出二叉树的每个节点，同层节点从左至右打印。
https://blog.csdn.net/qq_34840129/article/details/80619761
前序遍历：先访问根结点，再访问左子结点，最后访问右子结点。
中序遍历：先访问左子结点，再访问根结点，最后访问右子结点。
后序遍历：先访问左子结点，再访问右子结点，最后访问根结点。


使用队列实现
*/



struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	std::vector<int> PrintFromTopToBottom(TreeNode* root) 
	{
		TreeNode* fr;
		if (root == NULL) 
		{
			return result;
		}
		que.push(root);
		while (!que.empty()) 
		{
			fr = que.front();
			result.push_back(fr->val);
			if (fr->left != NULL) 
			{
				que.push(fr->left);
			}
			if (fr->right != NULL) 
			{
				que.push(fr->right);
			}
			que.pop();
		}
		return result;
	}
private:
	std::vector<int> result;
	std::queue<TreeNode*> que;
};


//此处没有构造二叉树，不运行程序
void example_4()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode* pRoot1 = NULL;
	TreeNode* pRoot2 = NULL;
	Solution* s = new Solution;
	std::vector<int> ret;
	try
	{

		ret = s->PrintFromTopToBottom(pRoot1);

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
