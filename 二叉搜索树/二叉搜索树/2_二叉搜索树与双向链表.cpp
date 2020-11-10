#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2017/12/basis_26.html

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。


//二叉搜索树
每个父节点都有两个子节点（子节点可能为空），左子节点比父节点小，右子节点比父节点大。
左结点的值<根结点的值<右结点的值


使用二叉树的中序遍历出来的数据的数序，就是排序的顺序。
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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		//用于记录双向链表尾结点
		TreeNode* pLastNodeInList = NULL;

		//开始转换结点
		ConvertNode(pRootOfTree, &pLastNodeInList);

		//pLastNodeInList指向双向链表的尾结点，我们需要重新返回头结点
		TreeNode* pHeadOfList = pLastNodeInList;
		while (pHeadOfList != NULL && pHeadOfList->left != NULL) {
			pHeadOfList = pHeadOfList->left;
		}
		return pHeadOfList;
	}

	void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList) {
		//叶结点直接返回
		if (pNode == NULL) {
			return;
		}
		TreeNode* pCurrent = pNode;
		//递归左子树
		if (pCurrent->left != NULL)
			ConvertNode(pCurrent->left, pLastNodeInList);

		//左指针
		pCurrent->left = *pLastNodeInList;
		//右指针
		if (*pLastNodeInList != NULL) {
			(*pLastNodeInList)->right = pCurrent;
		}
		//更新双向链表尾结点
		*pLastNodeInList = pCurrent;
		//递归右子树
		if (pCurrent->right != NULL) {
			ConvertNode(pCurrent->right, pLastNodeInList);
		}
	}
};

//此处未创建二叉树，程序编译通过，未运行
void example_2()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode*   pRoot1 = NULL;

	Solution* s = new Solution;
	TreeNode* ret;
	try
	{

		ret = s->Convert(pRoot1);

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
