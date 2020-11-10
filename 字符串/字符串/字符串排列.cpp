
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*

https://cuijiahua.com/blog/2017/12/basis_27.html
分别把第一个字符a和后面的b、c等字符交换的情形。首先固定第一个字符，求后面所有字符的排列。这个时候我们仍把后面的所有字符分为两部分：
后面的字符的第一个字符，以及这个字符之后的所有字符。然后把第一个字符逐一和它后面的字符交换。
*/
class Solution {
public:
	vector<string> Permutation(string str) {
		//判断输入
		if (str.length() == 0) {
			return result;
		}
		PermutationCore(str, 0);
		//对结果进行排序
		sort(result.begin(), result.end());
		return result;
	}

private:
	void PermutationCore(string str, int begin) {
		//递归结束的条件：第一位和最后一位交换完成
		if (begin == str.length()) {
			result.push_back(str);
			return;
		}
		for (int i = begin; i < str.length(); i++) {
			//如果字符串相同，则不交换
			if (i != begin && str[i] == str[begin]) {
				continue;
			}
			//位置交换
			swap(str[begin], str[i]);
			//递归调用，前面begin+1的位置不变，后面的字符串全排列
			PermutationCore(str, begin + 1);
		}
	}
	vector<string> result;
};

void example_2()
{

	//此处应写成数组
	string str = "cdefg";

	Solution* s = new Solution;
	vector<string> result;
	try
	{
		result=s->Permutation(str);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete s;
	system("pause");
	return;
}