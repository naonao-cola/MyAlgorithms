#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2017/11/basis_4.html

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

https://blog.csdn.net/qq_34840129/article/details/80619761
前序遍历：先访问根结点，再访问左子结点，最后访问右子结点。
中序遍历：先访问左子结点，再访问根结点，最后访问右子结点。
后序遍历：先访问左子结点，再访问右子结点，最后访问根结点。


前序遍历序列中，第一个数字总是树的根结点的值。在中序遍历序列中，
根结点的值在序列的中间，左子树的结点的值位于根结点的值的左边，而右子树的结点的值位于根结点的值的右边。
*/

//Definition for binary tree
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
		if (pre.size() == 0) {					//如果为空，返回NULL
			return NULL;
		}
		//依次是前序遍历左子树，前序遍历右子树，中序遍历左子树，中序遍历右子树
		std::vector<int> left_pre, right_pre, left_vin, right_vin;
		//前序遍历第一个节点一定为根节点
		TreeNode* head = new TreeNode(pre[0]);
		//找到中序遍历的根节点
		int root = 0;
		//遍历找到中序遍历根节点索引值
		for (int i = 0; i < pre.size(); i++) {
			if (pre[0] == vin[i]) {
				root = i;
				break;
			}
		}
		//利用中序遍历的根节点，对二叉树节点进行归并
		for (int i = 0; i < root; i++) {
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);			//前序遍历第一个为根节点
		}

		for (int i = root + 1; i < pre.size(); i++) {
			right_vin.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}

		//递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);
		return head;
	}
};
void example_1()
{

	std::vector<int> array1 = { 1,2,4,7,3,5,6,8};
	std::vector<int> array2 = { 4,7,2,1,5,3,8,6};

	Solution* s = new Solution;
	TreeNode* ret;
	try
	{

		ret = s->reConstructBinaryTree(array1, array2);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout <<" " << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
