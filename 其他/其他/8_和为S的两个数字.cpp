#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_42.html

输入一个递增排序的数组和一个数字S，在数组中查找两个数，
是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

输出描述：
对应每个测试案例，输出两个数，小的先输出。


对于一个数组，我们可以定义两个指针，一个从左往右遍历（pleft），另一个从右往左遍历（pright）。
这么做的好处是，也保证了乘积最小。

*/



class Solution {
public:
	std::vector<int> FindNumbersWithSum(std::vector<int> array, int sum) {
		std::vector<int> result;
		std::size_t length = array.size();
		if (length < 1) {
			return result;
		}
		int pright = static_cast<int>(length - 1);
		int pleft = 0;

		while (pright > pleft) {
			int curSum = array[pleft] + array[pright];
			if (curSum == sum) {
				result.push_back(array[pleft]);
				result.push_back(array[pright]);
				break;
			}
			else if (curSum < sum) {
				pleft++;
			}
			else {
				pright--;
			}
		}
		return result;
	}
};


void example_8()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	Solution* s = new Solution;
	std::vector<int> ret;
	try
	{

		ret = s->FindNumbersWithSum(pRoot1,21);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
