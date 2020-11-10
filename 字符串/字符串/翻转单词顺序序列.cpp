
#include <string>
#include <iostream>
#include <algorithm>

/*
https://cuijiahua.com/blog/2018/01/basis_44.html
观察字符串变化规律，你会发现这道题很简单。只需要对每个单词做翻转，然后再整体做翻转就得到了正确的结果。
*/
class Solution {
public:
	std::string ReverseSentence(std::string str) {
		std::string result = str;
		std::size_t length = result.size();
		if (length == 0) {
			return "";
		}
		// 追加一个空格，作为反转标志位
		result += ' ';
		int mark = 0;
		// 根据空格，反转所有单词
		for (int i = 0; i < length + 1; i++) {
			if (result[i] == ' ') {
				Reverse(result, mark, i - 1);
				mark = i + 1;
			}
		}
		// 去掉添加的空格
		result = result.substr(0, length);
		// 整体反转
		Reverse(result, 0, static_cast<int>(length - 1));

		return result;
	}
private:
	//翻转字符
	void Reverse(std::string &str, int begin, int end) {
		while (begin < end) {
			std::swap(str[begin++], str[end--]);
		}
	}
};

void example_5()
{

	//此处应写成数组
	std::string str = "student. a am I";

	Solution* s = new Solution;
	std::string result;
	try
	{
		result = s->ReverseSentence(str);
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
