#include <exception>
#include <iostream>

/*
https://cuijiahua.com/blog/2017/11/basis_9.html

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

当n=1时，结果为1；
当n=2时，结果为2；
当n=3时，结果为4；
以此类推，我们使用数学归纳法不难发现，跳法f(n)=2^(n-1)。

*/
class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 0) {
			return 0;
		}
		int total = 1;
		for (int i = 1; i < number; i++) {
			total *= 2;
		}
		return total;
	}
};

void example_3()
{


	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->jumpFloorII(10);

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

