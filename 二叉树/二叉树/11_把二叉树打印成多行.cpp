#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*


https://cuijiahua.com/blog/2018/01/basis_60.html

从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
与二叉树第10题一致

本题是先入先出，使用队列即可。
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
	std::vector<std::vector<int> > Print(TreeNode* pRoot) {
		std::vector<std::vector<int> > result;
		if (pRoot == NULL) {
			return result;
		}
		std::queue<TreeNode* > nodes[2];
		nodes[0].push(pRoot);
		while (!nodes[0].empty() || !nodes[1].empty()) {
			std::vector<int> v[2];
			while (!nodes[0].empty()) {
				v[0].push_back(nodes[0].front()->val);
				if (nodes[0].front()->left != NULL) {
					nodes[1].push(nodes[0].front()->left);
				}
				if (nodes[0].front()->right != NULL) {
					nodes[1].push(nodes[0].front()->right);
				}
				nodes[0].pop();
			}
			if (!v[0].empty()) {
				result.push_back(v[0]);
			}
			while (!nodes[1].empty()) {
				v[1].push_back(nodes[1].front()->val);
				if (nodes[1].front()->left != NULL) {
					nodes[0].push(nodes[1].front()->left);
				}
				if (nodes[1].front()->right != NULL) {
					nodes[0].push(nodes[1].front()->right);
				}
				nodes[1].pop();
			}
			if (!v[1].empty()) {
				result.push_back(v[1]);
			}
		}
		return result;
	}
};

//此处没有构造二叉树，不运行程序
void example_11()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode*   pRoot1 = NULL;

	Solution* s = new Solution;
	std::vector<std::vector<int> > ret;
	try
	{

		ret = s->Print(pRoot1);

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
