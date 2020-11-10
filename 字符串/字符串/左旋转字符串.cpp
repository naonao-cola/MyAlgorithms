



#include <string>
#include <iostream>
#include <algorithm>

/*
https://cuijiahua.com/blog/2018/01/basis_43.html
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。

输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到的结果"cdefgab";

第一步：翻转字符串“ab”，得到"ba"；
第二步：翻转字符串"cdefg"，得到"gfedc"；
第三步：翻转字符串"bagfedc"，得到"cdefgab"；
*/
class Solution {
public:
	std::string LeftRotateString(std::string str, int n) {
		std::string result = str;
		std::size_t length = result.size();
		if (length < 0) {
			return NULL;
		}
		if ( n >=0 && n <= length) {
			int pFirstBegin = 0, pFirstEnd = n - 1;
			int pSecondBegin = n, pSecondEnd = static_cast<int>(length) - 1;
			ReverseString(result, pFirstBegin, pFirstEnd);
			ReverseString(result, pSecondBegin, pSecondEnd);
			ReverseString(result, pFirstBegin, pSecondEnd);
		}
		return result;
	}
private:
	void ReverseString(std::string &str, int begin, int end) {
		while (begin < end) {
			std::swap(str[begin++], str[end--]);
		}
	}
};

void example_4()
{

	//此处应写成数组
	std::string str = "abcXYZdef";

	Solution* s = new Solution;
	std::string result;
	try
	{
		result = s->LeftRotateString(str,3);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << result << std::endl;
	delete s;
	system("pause");
	return;
}

