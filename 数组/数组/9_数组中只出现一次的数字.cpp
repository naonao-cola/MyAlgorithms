

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_40.html
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。


异或：不同的为1，相同的为0
*/

class Solution {
public:
	void FindNumsAppearOnce(std::vector<int> data, int* num1, int *num2) {
		size_t length = data.size();
		if (length < 2) {
			return;
		}

		// 对原始数组每个元素求异或
		int resultExclusiveOR = 0;
		for (int i = 0; i < length; ++i) {
			resultExclusiveOR ^= data[i];
		}

		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

		*num1 = *num2 = 0;
		for (int j = 0; j < length; j++) {
			if (IsBit1(data[j], indexOf1)) {
				*num1 ^= data[j];
			}
			else {
				*num2 ^= data[j];
			}
		}
	}
private:
	// 找到二进制数num第一个为1的位数，比如0010，第一个为1的位数是2。
	unsigned int FindFirstBitIs1(int num) {
		unsigned int indexBit = 0;
		// 只判断一个字节的
		while ((num & 1) == 0 && (indexBit < 8 * sizeof(unsigned int))) {
			num = num >> 1;
			indexBit++;
		}
		return indexBit;
	}
	// 判断第indexBit位是否为1
	bool IsBit1(int num, unsigned int indexBit) {
		num = num >> indexBit;
		return (num & 1);
	}
};

void example_9()
{

	//此处应写成数组
	std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	int *num1=new int, *num2=new int;
	try
	{
		s->FindNumsAppearOnce(array, num1, num2);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *num1<<" "<<*num2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	delete num1;
	delete num2;
	system("pause");
	return;
}
