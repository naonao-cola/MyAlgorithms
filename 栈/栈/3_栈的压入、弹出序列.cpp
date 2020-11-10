#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2017/12/basis_21.html

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）

*/
namespace example_space_3
{
	class Solution {
	public:
		bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) 
		{
			if (pushV.size() == 0) 
			{
				return false;
			}
			for (int i = 0, j = 0; i < pushV.size(); i++) 
			{
				stackData.push(pushV[i]);
				while (j < popV.size() && stackData.top() == popV[j]) 
				{
					stackData.pop();
					j++;
				}
			}
			return stackData.empty();
		}
	private:
		std::stack<int> stackData;
	};
}

void main()
{
	using namespace example_space_3;
	std::vector<int> array1 = { 1,2,3,4,5};
	std::vector<int> array2 = { 4,5,3,2,1 };
	
	Solution* s = new Solution;
	bool ret;
	try
	{
		
		ret = s->IsPopOrder(array1, array2);

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
