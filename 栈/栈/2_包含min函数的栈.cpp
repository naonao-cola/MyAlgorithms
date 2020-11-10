#include <stack>
#include <exception>
#include <iostream>
/*

https://cuijiahua.com/blog/2017/12/basis_20.html

定义栈的数据结构，请在类型中实现一个能够得到栈最小元素的min函数。

*/
namespace example_space_2
{
	class Solution {
	public:
		void push(int value)
		{
			Data.push(value);
			if (Min.empty())
			{
				Min.push(value);
			}
			if (Min.top() > value)
			{
				Min.push(value);
			}
		}
		void pop() {
			if (Data.top() == Min.top()) {
				Min.pop();
			}
			Data.pop();
		}
		int top()
		{
			return Data.top();
		}
		int min()
		{
			return Min.top();
		}
	private:
		std::stack<int> Data;			//数据栈
		std::stack<int> Min;				//最小栈
	};
}

void example_2()
{
	using namespace example_space_2;
	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	int ret;
	try
	{
		s->push(2);
		s->push(5);
		s->push(9);
		ret = s->min();

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
