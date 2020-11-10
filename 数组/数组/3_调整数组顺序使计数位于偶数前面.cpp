

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <deque>
/*
https://cuijiahua.com/blog/2017/11/basis_13.html
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//创建双向队列，遍历数组，奇数前插入，偶数后插入。最后使用assign方法实现不同容器但相容的类型赋值。
*/

class Solution {
public:
	void reOrderArray(std::vector<int> &array)
	{
		std::deque<int> result;
		size_t num = array.size();
		for (size_t i = 0; i < num; i++) 
		{
			//奇数从后遍历
			if (array[num - i - 1] % 2 == 1) 
			{
				result.push_front(array[num - i - 1]);
			}
			//偶数从前遍历
			if (array[i] % 2 == 0) {
				result.push_back(array[i]);
			}
		}
		//实现不同容器但相容的类型赋值。
		array.assign(result.begin(), result.end());
	}
};
void example_3()
{

	//此处应写成数组
	std::vector<int> array = { 9,7,8,3,4,5 };
	Solution* s = new Solution;
	int result =0;
	try
	{
		result = 0;
		s->reOrderArray(array);
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
