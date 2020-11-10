#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_33.html

把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

丑数应该是另一个丑数乘以2、3或者5的结果（1除外）。因此我们可以创建一个数组，
里面的数字是排好序的丑数，每一个丑数都是前面的丑数乘以2、3或者5得到的。

*/


//1，2，3，4，5，6都是丑数。所以当index小于7的时候，直接返回index即可。
class Solution {
public:
	int GetUglyNumber_Solution(int index)
	{
		if (index < 7) {
			return index;
		}
		std::vector<int> res(index);
		for (int i = 0; i < 6; i++) 
		{
			res[i] = i + 1;
		}
		int t2 = 3, t3 = 2, t5 = 1;
		for (int i = 6; i < index; i++) 
		{
			res[i] = std::min(res[t2] * 2, std::min(res[t3] * 3, res[t5] * 5));
			while (res[i] >= res[t2] * 2) 
			{
				t2++;
			}
			while (res[i] >= res[t3] * 3)
			{
				t3++;
			}
			while (res[i] >= res[t5] * 5)
			{
				t5++;
			}
		}
		return res[index - 1];
	}
};


void example_6()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->GetUglyNumber_Solution(7);

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
