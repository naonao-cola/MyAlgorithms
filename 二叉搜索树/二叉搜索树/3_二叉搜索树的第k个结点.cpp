#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2018/01/basis_62.html

给定一颗二叉搜索树，请找出其中的第k大的结点。例如，在下图中，按结点数值大小顺序第三个结点的值为4。


//二叉搜索树
每个父节点都有两个子节点（子节点可能为空），左子节点比父节点小，右子节点比父节点大。
左结点的值<根结点的值<右结点的值


使用中序遍历，则得到的序列式为{2,3,4,5,6,7,8}。因此，只需要用中序遍历一棵二叉搜索树，就很容易找出它的第k大结点。
*/



struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k == 0) {
			return NULL;
		}
		return KthNodeCore(pRoot, k);
	}
private:
	TreeNode* KthNodeCore(TreeNode* pRoot, int &k) {
		TreeNode* target = NULL;
		// 先遍历左结点
		if (pRoot->left != NULL) {
			target = KthNodeCore(pRoot->left, k);
		}
		// 如果没有找到target，则继续减小k，如果k等于1，说明到了第k大的数
		if (target == NULL) {
			if (k == 1) {
				target = pRoot;
			}
			k--;
		}
		// 如果没有找到target，继续找右结点
		if (pRoot->right != NULL && target == NULL) {
			target = KthNodeCore(pRoot->right, k);
		}
		return target;
	}
};

//此处未创建二叉树，程序编译通过，未运行
void main()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode*   pRoot1 = NULL;

	Solution* s = new Solution;
	TreeNode* ret;
	try
	{

		ret = s->KthNode(pRoot1,3);

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
