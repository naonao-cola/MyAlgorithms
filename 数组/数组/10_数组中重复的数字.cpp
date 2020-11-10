

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_50.html
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是第一个重复的数字2。


*/

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		// 非法输入
		if (numbers == NULL || length <= 0) {
			return false;
		}
		// 非法输入
		for (int i = 0; i < length; i++) {
			if (numbers[i] < 0 || numbers[i] > length - 1) {
				return false;
			}
		}
		// 遍历查找第一个重复的数
		for (int i = 0; i < length; i++)
		{
			while (numbers[i] != i) 
			{
				if (numbers[i] == numbers[numbers[i]]) 
				{
					*duplication = numbers[i];
					return true;
				}
				std::swap(numbers[i], numbers[numbers[i]]);
			}
		}
		return false;
	}
};

void example_10()
{

	//此处应写成数组
	//输入的数组有要求。
	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	int array[] = { 2,3,1,0,2,5,3 };
	int *num = new int;
	try
	{
		s->duplicate(array, 7, num);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *num << " "<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	delete num;
	
	system("pause");
	return;
}
