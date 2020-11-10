#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2017/12/basis_29.html

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

最简单的方法就是先排序，然后在遍历输出最小的K个数，方法简单粗暴。

*/


//可以使用堆排序优化
class Solution {
public:
	std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k) {
		std::vector<int> result;
		if (input.empty() || k > input.size()) {
			return result;
		}
		std::sort(input.begin(), input.end());
		for (int i = 0; i < k; ++i) {
			result.push_back(input[i]);
		}
		return result;
	}
};


void example_4()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = {  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

	Solution* s = new Solution;
	std::vector<int> ret;
	try
	{

		ret = s->GetLeastNumbers_Solution(pRoot1,4);

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
