#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*

https://cuijiahua.com/blog/2017/12/basis_24.html


输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。


深度优先搜索。
使用前序遍历，使用两个全局变量result和tmp，result来存放最终结果，tmp用来存放临时结果。
每次遍历，我们先把root的值压入tmp，然后判断当前root是否同时满足：

与给定数值相减为0；
左子树为空；
右子树为空。


*/




struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {}
};
class Solution 
{
public:
	std::vector<std::vector<int> > FindPath(TreeNode* root, int expectNumber)
	{
		if (root == NULL) 
		{
			return result;
		}

		tmp.push_back(root->val);
		if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL) {
			result.push_back(tmp);
		}

		//遍历左子树
		FindPath(root->left, expectNumber - root->val);
		//遍历右子树
		FindPath(root->right, expectNumber - root->val);

		tmp.pop_back();
		return result;
	}
private:
	std::vector<std::vector<int> > result;
	std::vector<int> tmp;
};


//此处没有构造二叉树，不运行程序
void example_5()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode* pRoot1 = NULL;
	TreeNode* pRoot2 = NULL;
	Solution* s = new Solution;
	std::vector<std::vector<int> > ret;
	try
	{

		ret = s->FindPath(pRoot1,20);

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
