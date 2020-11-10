
#include <string>
#include <iostream>
#include <algorithm>

/*
https://cuijiahua.com/blog/2018/01/basis_52.html

请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有
字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。

*/
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		// 指针为空，返回false
		if (str == NULL || pattern == NULL) {
			return false;
		}
		return matchCore(str, pattern);
	}
private:
	bool matchCore(char* str, char* pattern) {
		// 字符串和模式串都运行到了结尾，返回true
		if (*str == '\0' && *pattern == '\0') 
		{
			return true;
		}
		// 字符串没有到结尾，模式串到了，则返回false
		// 模式串没有到结尾，字符串到了，则根据后续判断进行，需要对'*'做处理
		if ((*str != '\0' && *pattern == '\0')) 
		{
			return false;
		}
		// 如果模式串的下一个字符是'*'，则进入状态机的匹配
		if (*(pattern + 1) == '*')
		{
			// 如果字符串和模式串相等，或者模式串是'.'，并且字符串没有到结尾，则继续匹配
			if (*str == *pattern || (*pattern == '.' && *str != '\0')) 
			{
				// 进入下一个状态，就是匹配到了一个
				return matchCore(str + 1, pattern + 2) ||
					// 保持当前状态，就是继续那这个'*'去匹配
					matchCore(str + 1, pattern) ||
					// 跳过这个'*'
					matchCore(str, pattern + 2);
			}
			// 如果字符串和模式串不相等，则跳过当前模式串的字符和'*'，进入新一轮的匹配
			else 
			{
				// 跳过这个'*'
				return matchCore(str, pattern + 2);
			}
		}
		// 如果字符串和模式串相等，或者模式串是'.'，并且字符串没有到结尾，则继续匹配
		if (*str == *pattern || (*pattern == '.' && *str != '\0')) 
		{
			return matchCore(str + 1, pattern + 1);
		}
		return false;
	}
};

void example_7()
{

	//此处应写成数组
	char str[] = "aaa";
	char pattern[] = "ab*ac*a";

	Solution* s = new Solution;
	bool result;
	try
	{
		result = s->match(str,pattern);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
