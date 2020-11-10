
#include <iostream>
#include <exception>

class Solution
{
public:
	void replaceSpace(char *str, int length)
	{
		int i = 0;
		int numSpace = 0;
		while (str[i] != '\0')
		{
			if (str[i] == ' ')
				numSpace++;
			++i;
		}
		int newLen = i + numSpace * 2;
		for (int j = i; j >= 0, newLen >= 0;)
		{
			if (str[j] == ' ')
			{
				str[newLen--] = '0';
				str[newLen--] = '2';
				str[newLen--] = '%';
			}
			else
				str[newLen--] = str[j];
			j--;
		}
	}
};

void example_1()
{

	//此处应写成数组
	char str[15] = "We Are Happy";

	Solution* s = new Solution;
	try
	{
		s->replaceSpace(const_cast<char*>(str), 20);
	}
	catch (std::exception& e)
	{
		std::cout <<e.what()<< std::endl;
	}
	delete s;
	std::cout << str<< std::endl;
	system("pause");
	return;
}