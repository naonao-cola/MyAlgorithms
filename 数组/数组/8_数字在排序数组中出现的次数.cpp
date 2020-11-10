

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_37.html
统计一个数字在排序数组中出现的次数。
我们对数组data进行二分，如果数组中间的数字小于k，说明k应该出现在中间位置的右边；
如果数组中间的数字大于k，说明k应该出现在中间位置的左边；
如果数组中间的数字等于k，并且中间位置的前一个数字不等于k，说明这个中间数字就是数字k出现的第一个位置。

*/

class Solution {
public:
	//输入为排序序列，从小到大排序的容器
	int GetNumberOfK(std::vector<int> data, int k) {
		size_t length = data.size();
		if (length == 0) {
			return 0;
		}
		int first = GetFirstK(data, k, 0, static_cast<int>(length - 1));
		int last = GetLastK(data, k, 0, static_cast<int>(length - 1));
		if (first != -1 && last != -1) {
			return last - first + 1;
		}
		return 0;
	}
private:
	// 迭代实现找到第一个K
	int GetFirstK(std::vector<int> data, int k, int begin, int end) {
		if (begin > end) {
			return -1;
		}
		int middleIndex = (begin + end) >> 1;
		int middleData = data[middleIndex];

		if (middleData == k) {
			if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0) {
				return middleIndex;
			}
			else {
				end = middleIndex - 1;
			}
		}
		else if (middleData > k) {
			end = middleIndex - 1;
		}
		else {
			begin = middleIndex + 1;
		}
		return GetFirstK(data, k, begin, end);
	}
	// 循环实现找到最后一个K
	int GetLastK(std::vector<int> data, int k, int begin, int end) {
		size_t length = data.size();
		int middleIndex = (begin + end) >> 1;
		int middleData = data[middleIndex];

		while (begin <= end) {
			if (middleData == k) {
				if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1) {
					return middleIndex;
				}
				else {
					begin = middleIndex + 1;
				}
			}
			else if (middleData > k) {
				end = middleIndex - 1;
			}
			else {
				begin = middleIndex + 1;
			}
			middleIndex = (begin + end) >> 1;
			middleData = data[middleIndex];
		}
		return -1;
	}
};

void example_8()
{

	//此处应写成数组
	std::vector<int> array = { 4,5,6,7 };
	Solution* s = new Solution;
	int result;
	try
	{
		result = s->GetNumberOfK(array,7);
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
