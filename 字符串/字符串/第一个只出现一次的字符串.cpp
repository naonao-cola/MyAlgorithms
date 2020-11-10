
#include <map>
#include <iostream>
#include <string>

/*
https://cuijiahua.com/blog/2018/01/basis_34.html
建立一个哈希表，第一次扫描的时候，统计每个字符的出现次数。
第二次扫描的时候，如果该字符出现的次数为1，则返回这个字符的位置。
*/
class Solution {
public:
	int FirstNotRepeatingChar(std::string str) {
		std::size_t length = str.size();
		if (length == 0) {
			return -1;
		}
		std::map<char, int> item;
		for (int i = 0; i < length; i++) {
			item[str[i]]++;
		}
		for (int i = 0; i < length; i++) {
			if (item[str[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};

void example_3()
{

	//此处应写成数组
	std::string str = "cdefgdsafdjsafhdjgadkfjiwerjwfvnaf";

	Solution* s = new Solution;
	int result;
	try
	{
		result = s->FirstNotRepeatingChar(str);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << result<< std::endl;
	delete s;
	system("pause");
	return;
}