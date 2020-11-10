#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2017/12/basis_17.html

输入两颗二叉树A，B，判断B是不是A的子结构。（PS：我们约定空树不是任意一个树的子结构）。

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
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL && pRoot2 != NULL) 
		{
			if (pRoot1->val == pRoot2->val) {
				result = DoesTree1HasTree2(pRoot1, pRoot2);
			}
			if (!result) {
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!result) {
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}
private:
	bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL) {
			return true;
		}
		if (pRoot1 == NULL) {
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};


//此处没有构造二叉树，不运行程序
void example_2()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode* pRoot1 = NULL;
	TreeNode* pRoot2 = NULL;
	Solution* s = new Solution;
	bool ret;
	try
	{

		ret = s->HasSubtree(pRoot1, pRoot2);

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
