#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <functional> // gather less
/*


https://cuijiahua.com/blog/2018/02/basis_64.html

给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}。


使用一个双端队列deque处理 
应该在队列里存入数字在数组里的下标，而不是数值。
当一个数字的下标与当前处理的数字的下标之差大于或者相等于滑动窗口大小时，这个数字已经从窗口中滑出，可以从队列中删除。
*/

class Solution {
public:
	std::vector<int> maxInWindows(const std::vector<int>& num, unsigned int size)
	{
		std::vector<int> maxInWindows;
		// 数组大小要大于等于窗口大小，并且窗口大小大于等于1
		if (num.size() >= size && size >= 1) 
		{
			std::deque<int> index;
			for (unsigned int i = 0; i < size; i++) 
			{
				// 如果index非空，并且新添加的数字大于等于队列中最小的数字，则删除队列中最小的数字
				while (!index.empty() && num[i] >= num[index.back()]) 
				{
					index.pop_back();
				}
				index.push_back(i);
			}
			for (unsigned int i = size; i < num.size(); i++) 
			{
				maxInWindows.push_back(num[index.front()]);
				while (!index.empty() && num[i] >= num[index.back()]) 
				{
					index.pop_back();
				}
				// 控制窗口大小为size
				if (!index.empty() && index.front() <= int(i - size)) 
				{
					index.pop_front();
				}
				index.push_back(i);
			}
			maxInWindows.push_back(num[index.front()]);
		}
		return maxInWindows;
	}
};

void main()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 2,3,4,2,6,2,5,1 };

	
	Solution* s = new Solution;

	

	std::vector<int> ret;
	try
	{

		ret = s->maxInWindows(pRoot1,3);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << " "<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
