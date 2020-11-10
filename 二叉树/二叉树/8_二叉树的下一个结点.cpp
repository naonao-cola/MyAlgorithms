#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*


https://cuijiahua.com/blog/2018/01/basis_57.html

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。


如果一个结点有右子树，那么它的下一个结点就是它的右子树的最左子结点。

没有右子树的情形。如果结点是它父结点的左子结点，那么它的下一个结点就是它的父结点


如果一个结点既没有右子树，并且它还是父结点的右子结点，
沿着指向父结点的指针一直向上遍历，直到找到一个是它父结点的左子结点的结点。
如果这样的结点存在，那么这个结点的父结点就是我们要找的下一个结点。
*/








struct TreeLinkNode 
{
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL) {
			return NULL;
		}
		TreeLinkNode* pNext = NULL;
		// 当前结点有右子树，那么它的下一个结点就是它的右子树中最左子结点
		if (pNode->right != NULL) {
			TreeLinkNode* pRight = pNode->right;
			while (pRight->left != NULL) {
				pRight = pRight->left;
			}
			pNext = pRight;
		}
		// 当前结点无右子树，则需要找到一个是它父结点的左子树结点的结点
		else if (pNode->next != NULL) {
			// 当前结点
			TreeLinkNode* pCur = pNode;
			// 父节点
			TreeLinkNode* pPar = pNode->next;
			while (pPar != NULL && pCur == pPar->right) {
				pCur = pPar;
				pPar = pCur->next;
			}
			pNext = pPar;
		}
		return pNext;
	}
};


//此处没有构造二叉树，不运行程序
void example_8()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeLinkNode*  pRoot1 = NULL;
	
	Solution* s = new Solution;
	TreeLinkNode* ret;
	try
	{

		ret = s->GetNext(pRoot1);

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
