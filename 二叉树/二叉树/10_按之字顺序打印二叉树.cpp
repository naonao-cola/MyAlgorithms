#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*


https://cuijiahua.com/blog/2018/01/basis_59.html

请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。


需要使用两个栈。我们在打印某一行结点时，把下一层的子结点保存到相应的栈里。
如果当前打印的是奇数层（第一层、第三层等），则先保存左子树结点再保存右子树结点到第一个栈里。
如果当前打印的是偶数层（第二层、第四层等），则则先保存右子树结点再保存左子树结点到第二个栈里。
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
	std::vector<std::vector<int> > Print(TreeNode* pRoot) {
		std::vector<std::vector<int> > result;
		if (pRoot == NULL) {
			return result;
		}
		std::stack<TreeNode* > s[2];
		s[0].push(pRoot);
		while (!s[0].empty() || !s[1].empty()) {
			std::vector<int> v[2];
			// 偶数行
			while (!s[0].empty()) {
				v[0].push_back(s[0].top()->val);
				if (s[0].top()->left != NULL) {
					s[1].push(s[0].top()->left);
				}
				if (s[0].top()->right != NULL) {
					s[1].push(s[0].top()->right);
				}
				s[0].pop();
			}
			if (!v[0].empty()) {
				result.push_back(v[0]);
			}
			// 奇数行
			while (!s[1].empty()) {
				v[1].push_back(s[1].top()->val);
				if (s[1].top()->right != NULL) {
					s[0].push(s[1].top()->right);
				}
				if (s[1].top()->left != NULL) {
					s[0].push(s[1].top()->left);
				}
				s[1].pop();
			}
			if (!v[1].empty()) {
				result.push_back(v[1]);
			}
		}
		return result;
	}
};

//此处没有构造二叉树，不运行程序
void example_10()
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
