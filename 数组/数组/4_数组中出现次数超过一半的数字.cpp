

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
/*
https://cuijiahua.com/blog/2017/12/basis_28.html
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

///可以考虑在遍历数组的时候保存两个值：一个是数组的一个数字，一个是次数。
///当我们遍历到下一个数字的时候，如果下一个数字和我们之前保存的数字相同，则次数加1；
///如果下一个数字和我们之前保存的数字不同，则次数减1。如果次数为零，我们需要保存下一个数字，并把次数设为1。
///由于我们要找的数字出现的次数比其他所有数字出现的次数之和还要多，那么要找的数字肯定是最后一次把次数设为1时对应的数字。
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(std::vector<int> numbers) {
		if (numbers.empty()) {
			return 0;
		}
		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
		int result = numbers[0];
		int times = 1;
		for (size_t i = 1; i < numbers.size(); ++i)
		{
			if (times == 0) 
			{
				// 更新result的值为当前元素，并置次数为1
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result) 
			{
				times++;
			}
			else 
			{
				times--;
			}
		}
		// 判断result是否符合条件，即出现次数大于数组长度的一半
		times = 0;
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == result) {
				times++;
			}
		}
		return (times > (numbers.size() >> 1)) ? result : 0;
	}
};
void example_4()
{

	//此处应写成数组
	std::vector<int> array = { 1,2,3,2,2,2,5,4,2 };
	Solution* s = new Solution;
	int result = 0;
	try
	{
		result = s->MoreThanHalfNum_Solution(array);
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
