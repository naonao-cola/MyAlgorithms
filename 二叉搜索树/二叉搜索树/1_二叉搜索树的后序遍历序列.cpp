#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2017/12/basis_23.html

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes，否则输出No。假设输入的数组的任意两个数字都互不相同。

//二叉搜索树
每个父节点都有两个子节点（子节点可能为空），左子节点比父节点小，右子节点比父节点大。

//后序遍历
左右根

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
	bool VerifySquenceOfBST(std::vector<int> sequence) {
		return bst(sequence, 0, static_cast<int>(sequence.size() - 1));
	}
private:
	bool bst(std::vector<int> seq, int begin, int end) {
		if (seq.empty() || begin > end) {
			return false;
		}

		//根结点
		int root = seq[end];

		//在二叉搜索树中左子树的结点小于根结点
		int i = begin;
		for (; i < end; ++i) {
			if (seq[i] > root) {
				break;
			}
		}

		//在二叉搜索书中右子树的结点大于根结点
		for (int j = i; j < end; ++j) {
			if (seq[j] < root) {
				return false;
			}
		}

		//判断左子树是不是二叉搜索树
		bool left = true;
		if (i > begin) {
			left = bst(seq, begin, i - 1);
		}

		//判断右子树是不是二叉搜索树
		bool right = true;
		if (i < end - 1) {
			right = bst(seq, i, end - 1);
		}

		return left && right;
	}
};


void example_1()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>   pRoot1 = {5,7,6,9,11,10,8};

	Solution* s = new Solution;
	bool ret;
	try
	{

		ret = s->VerifySquenceOfBST(pRoot1);

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
