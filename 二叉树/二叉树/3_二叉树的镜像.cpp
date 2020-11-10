#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2017/12/basis_18.html

操作给定的二叉树，将其变换为源二叉树的镜像。

前序遍历：先访问根结点，再访问左子结点，最后访问右子结点。
中序遍历：先访问左子结点，再访问根结点，最后访问右子结点。
后序遍历：先访问左子结点，再访问右子结点，最后访问根结点。


第一步在树A中找到和B的根结点的值一样的结点R，
第二步再判断树A中以R为根节点的子树是不是包含和树B一样的结构。
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
	void Mirror(TreeNode *pRoot) {
		if ((pRoot == NULL) || (pRoot->left == NULL && pRoot->right == NULL)) {
			return;
		}

		//交换根节点的左右结点
		TreeNode *pTemp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = pTemp;

		//递归左子树
		if (pRoot->left) {
			Mirror(pRoot->left);
		}
		//递归右子树
		if (pRoot->right) {
			Mirror(pRoot->right);
		}
	}
};

//此处没有构造二叉树，不运行程序
void example_3()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode *pRoot = NULL;
	Solution* s = new Solution;
	
	try
	{

		 s->Mirror(pRoot);

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
