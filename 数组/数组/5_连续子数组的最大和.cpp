

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
/*
https://cuijiahua.com/blog/2017/12/basis_30.html
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)


*/

class Solution {
public:
	int FindGreatestSumOfSubArray(std::vector<int> array) {
		if (array.empty()) {
			return 0;
		}
		// 初始化变量，maxSum为最大和，curSum为当前和
		int maxSum = array[0];
		int curSum = array[0];
		// 遍历所有元素
		for (size_t i = 1; i < array.size(); i++) {
			// 如果当前和小于等于0，说明之前的是负数，则抛弃前面的和，重新计算
			if (curSum <= 0) {
				curSum = array[i];
			}
			// 如果没有问题，直接累加
			else {
				curSum += array[i];
			}
			// 更新最大和
			if (curSum > maxSum) {
				maxSum = curSum;
			}
		}
		return maxSum;
	}
};
void example_5()
{

	//此处应写成数组
	std::vector<int> array = { 1,-2,3,10,-4,7,2,-5};
	Solution* s = new Solution;
	int result = 0;
	try
	{
		result = s->FindGreatestSumOfSubArray(array);
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
