#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_41.html

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

设定两个指针，一个指向第一个数，一个指向最后一个数，
在此之前需要设定第一个数和最后一个数的值，由于是正数序列，所以可以把第一个数设为1，最后一个数为2

*/



class Solution {
public:
	std::vector<std::vector<int> > FindContinuousSequence(int sum) {
		std::vector<std::vector<int> > result;
		// 高位指针和低位指针
		int phigh = 2, plow = 1;

		// 终止条件是phigh等于sum
		while (phigh > plow) {
			// 当前和，使用求和公式s = (a+b) * n / 2
			int curSum = (plow + phigh) * (phigh - plow + 1) >> 1;
			if (curSum < sum) {
				phigh++;
			}
			if (curSum == sum) {
				std::vector<int> temp;
				for (int i = plow; i <= phigh; i++) {
					temp.push_back(i);
				}
				result.push_back(temp);
				plow++;
			}
			if (curSum > sum) {
				plow++;
			}
		}
		return result;
	}
};


void example_7()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	Solution* s = new Solution;
	std::vector<std::vector<int> > ret;
	try
	{

		ret = s->FindContinuousSequence(100);

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
