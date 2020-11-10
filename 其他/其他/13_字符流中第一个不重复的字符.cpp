#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_54.html

请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

将字节流保存起来，通过哈希表统计字符流中每个字符出现的次数，
顺便将字符流保存在string中，然后再遍历string，从哈希表中找到第一个出现一次的字符。
*/



class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		s += ch;
		count[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		std::size_t length = s.size();
		for (int i = 0; i < length; i++) {
			if (count[s[i]] == 1) {
				return s[i];
			}
		}
		return '#';
	}
private:
	std::string s;
	int count[256] = { 0 };
};


void example_13()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 4,5,6,7,8,9 };

	Solution* s = new Solution;
	s->Insert('g');
	s->Insert('o');
	s->Insert('o');
	s->Insert('g');
	s->Insert('l');
	s->Insert('e');



	char ret;
	try
	{

		ret = s->FirstAppearingOnce();

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
