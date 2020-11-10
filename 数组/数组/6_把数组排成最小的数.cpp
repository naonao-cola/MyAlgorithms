

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_32.html
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。


*/

class Solution {
public:
	std::string PrintMinNumber(std::vector<int> numbers) {
		size_t length = numbers.size();
		if (length == 0) {
			return "";
		}
		sort(numbers.begin(), numbers.end(), cmp);
		std::string res;
		for (size_t i = 0; i < length; i++) {
			res += std::to_string(numbers[i]);
		}
		return res;
	}
private:
	// 升序排序
	static bool cmp(int a, int b) {
		std::string A = std::to_string(a) + std::to_string(b);
		std::string B = std::to_string(b) + std::to_string(a);
		return A < B;
	}
};
void example_6()
{

	//此处应写成数组
	std::vector<int> array = { 3,32,321 };
	Solution* s = new Solution;
	std::string result;
	try
	{
		result = s->PrintMinNumber(array);
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
