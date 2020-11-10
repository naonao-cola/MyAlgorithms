

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_35.html
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007。


*/

class Solution {
public:
	int InversePairs(std::vector<int> data)
	{
		if (data.size() == 0)
		{
			return 0;
		}
		// 排序的辅助数组
		std::vector<int> copy;
		for (int i = 0; i < data.size(); ++i) 
		{
			copy.push_back(data[i]);
		}
		return InversePairsCore(data, copy, 0, static_cast<int>(data.size() - 1)) % 1000000007;
	}

	long InversePairsCore(std::vector<int> &data, std::vector<int> &copy, int begin, int end)
	{
		// 如果指向相同位置，则没有逆序对。
		if (begin == end) {
			copy[begin] = data[end];
			return 0;
		}
		// 求中点
		int mid = (end + begin) >> 1;
		// 使data左半段有序，并返回左半段逆序对的数目
		long leftCount = InversePairsCore(copy, data, begin, mid);
		// 使data右半段有序，并返回右半段逆序对的数目
		long rightCount = InversePairsCore(copy, data, mid + 1, end);

		int i = mid; // i初始化为前半段最后一个数字的下标
		int j = end; // j初始化为后半段最后一个数字的下标
		int indexcopy = end; // 辅助数组复制的数组的最后一个数字的下标
		long count = 0; // 计数，逆序对的个数，注意类型

		while (i >= begin && j >= mid + 1) 
		{
			if (data[i] > data[j])
			{
				copy[indexcopy--] = data[i--];
				count += j - mid;
			}
			else 
			{
				copy[indexcopy--] = data[j--];
			}
		}
		for (; i >= begin; --i) 
		{
			copy[indexcopy--] = data[i];
		}
		for (; j >= mid + 1; --j) 
		{
			copy[indexcopy--] = data[j];
		}
		return leftCount + rightCount + count;
	}
};
void example_7()
{

	//此处应写成数组
	std::vector<int> array = { 7,6,5,4 };
	Solution* s = new Solution;
	int result;
	try
	{
		result = s->InversePairs(array);
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
