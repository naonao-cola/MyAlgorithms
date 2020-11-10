#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2018/01/basis_61.html

请实现两个函数，分别用来序列化和反序列化二叉树。

使用前序遍历来序列化和发序列化即可。只要自己写的程序格式对应上即可。
可以使用$符号表示NULL，同时每个结点之间，需要添加逗号，即','进行分隔。

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
	char* Serialize(TreeNode *root) 
	{
		if (!root) 
		{
			return NULL;
		}
		std::string str;
		SerializeCore(root, str);
		// 把str流中转换为字符串返回
		std::size_t length = str.length();
		char* res = new char[length + 1];
		// 把str流中转换为字符串返回
		for (int i = 0; i < length; i++) 
		{
			res[i] = str[i];
		}
		res[length] = '\0';
		return res;
	}
	TreeNode* Deserialize(char *str) 
	{
		if (!str) 
		{
			return NULL;
		}
		TreeNode* res = DeserializeCore(&str);
		return res;
	}
	void SerializeCore(TreeNode* root, std::string& str)
	{
		// 如果指针为空，表示左子节点或右子节点为空，则在序列中用#表示
		if (!root) 
		{
			str += '#';
			return;
		}
		std::string tmp = std::to_string(root->val);
		str += tmp;
		// 加逗号，用于区分每个结点
		str += ',';
		SerializeCore(root->left, str);
		SerializeCore(root->right, str);
	}
	// 递归时改变了str值使其指向后面的序列，因此要声明为char**
	TreeNode* DeserializeCore(char** str)
	{
		// 到达叶节点时，调用两次，都返回null，所以构建完毕，返回父节点的构建
		if (**str == '#') 
		{
			(*str)++;
			return NULL;
		}
		// 因为整数是用字符串表示，一个字符表示一位，先进行转换
		int num = 0;
		while (**str != ',' && **str != '\0')
		{
			num = num * 10 + ((**str) - '0');
			(*str)++;
		}
		TreeNode* root = new TreeNode(num);
		if (**str == '\0') 
		{
			return root;
		}
		else 
		{
			(*str)++;
		}
		root->left = DeserializeCore(str);
		root->right = DeserializeCore(str);
		return root;
	}
};

//此处没有构造二叉树，不运行程序
void main()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode*   pRoot1 = NULL;

	Solution* s = new Solution;
	char* ret;
	try
	{

		ret = s->Serialize(pRoot1);

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
