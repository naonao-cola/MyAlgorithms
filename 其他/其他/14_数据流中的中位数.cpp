#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <functional> // gather less
/*


https://cuijiahua.com/blog/2018/02/basis_63.html

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

使用最大堆和最小堆实现。

最大堆：根结点的键值是所有堆结点键值中最大者，且每个结点的值都比其孩子的值大。
最小堆：根结点的键值是所有堆结点键值中最小者，且每个结点的值都比其孩子的值小。

保证最小堆的数据大于最大堆。

没怎么看懂
*/

namespace example_space_14
{
	class Solution
	{
	public:
		void Insert(int num)
		{
			// 如果已有数据为偶数，则放入最小堆
			if (((max.size() + min.size()) & 1) == 0)
			{
				// 如果插入的数字小于最大堆里的最大的数，则将数字插入最大堆
				// 并将最大堆中的最大的数字插入到最小堆
				//次数估计和别的文件串了，输出大小不确定，加命名空间限制
				//std::cout << max.size() << " " << min.size() << std::endl;
				if (max.size() > 0 && num < max[0])
				{
					// 插入数据插入到最大堆数组
					max.push_back(num);
					// 调整最大堆
					push_heap(max.begin(), max.end(), std::less<int>());
					// 拿出最大堆中的最大数
					num = max[0];
					// 删除最大堆的栈顶元素
					pop_heap(max.begin(), max.end(), std::less<int>());
					max.pop_back();
				}

				// 将数据插入最小堆数组
				min.push_back(num);
				// 调整最小堆
				push_heap(min.begin(), min.end(), std::greater<int>());
			}
			// 已有数据为奇数，则放入最大堆
			else
			{
				if (min.size() > 0 && num > min[0])
				{
					// 将数据插入最小堆
					min.push_back(num);
					// 调整最小堆
					push_heap(min.begin(), min.end(), std::greater<int>());
					// 拿出最小堆的最小数
					num = min[0];
					// 删除最小堆的栈顶元素
					pop_heap(min.begin(), min.end(), std::greater<int>());
					min.pop_back();
				}
				// 将数据插入最大堆
				max.push_back(num);
				push_heap(max.begin(), max.end(), std::less<int>());
			}
		}

		double GetMedian()
		{
			// 统计数据大小
			int size = static_cast<int>(min.size() + max.size());
			if (size == 0)
			{
				return 0;
			}
			// 如果数据为偶数
			if ((size & 1) == 0)
			{
				return (min[0] + max[0]) / 2.0;
			}
			// 奇数
			else
			{
				return min[0];
			}
		}

	private:
		// 使用vector建立最大堆和最小堆,min是最小堆数组,max是最大堆数组
		std::vector<int> min;
		std::vector<int> max;
	};
}//example_space_14

void example_14()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 4,5,6,7,8,9 };

	using namespace  example_space_14;
	Solution* s = new Solution;

	s->Insert(7);
	s->Insert(11);
	s->Insert(13);
	s->Insert(17);
	s->Insert(19);
	s->Insert(23);



	double ret;
	try
	{

		ret = s->GetMedian();

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << ret << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
