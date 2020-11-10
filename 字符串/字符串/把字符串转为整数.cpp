
#include <string>
#include <iostream>
#include <algorithm>

/*
https://cuijiahua.com/blog/2018/01/basis_49.html

将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述：
输入一个字符串,包括数字字母符号,可以为空
输出描述：
如果是合法的数值表达则返回该数字，否则返回0

*/
class Solution {
public:
	enum Status { kValid = 0, kInValid };
	//g_nstatus表示是否异常输出
	int g_nStatus = kValid;
	int StrToInt(std::string str) {
		g_nStatus = kInValid;
		long long num = 0;
		const char* cstr = str.c_str();
		// 判断是否为指针和是否为空字符串
		if (cstr != NULL && *cstr != '\0') {
			// 正负号标志位，默认是加号
			//用来表示负数
			bool minus = false;
			if (*cstr == '+') {
				cstr++;
			}
			else if (*cstr == '-') {
				minus = true;
				cstr++;
			}
			if (*cstr != '\0') {
				num = StrToIntCore(cstr, minus);
			}
		}
		return (int)num;
	}
private:
	long long StrToIntCore(const char* cstr, bool minus) 
	{
		long long num = 0;
		while (*cstr != '\0') 
		{
			// 判断是否是非法值
			if (*cstr >= '0' && *cstr <= '9') 
			{
				int flag = minus ? -1 : 1;
				num = num * 10 + flag * (*cstr - '0');
				// 判断是否溢出,32位
				if ((!minus && num > /*0x7fffffff*/INT_MAX) || (minus && num < (signed int)/*0x80000000*/INT_MIN))
				{
					num = 0;
					break;
				}
				cstr++;
			}
			else 
			{
				num = 0;
				break;
			}
		}
		// 判断是否正常结束
		if (*cstr == '\0') {
			g_nStatus = kValid;
		}
		return num;
	}
};

void example_6()
{

	//此处应写成数组
	std::string str = "+2147483647846168456132154213215154213518641321324532132";

	Solution* s = new Solution;
	int result;
	try
	{
		result = s->StrToInt(str);
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
