#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_48.html

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。


转换成二进制 进行 操作
*/



class Solution {
public:
	int Add(int num1, int num2)
	{
		return num2 ? Add(num1 ^ num2, (num1 & num2) << 1) : num1;
	}
};
void example_12()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 4,5,6,7,8,9 };

	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->Add(5,7);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << ret << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
