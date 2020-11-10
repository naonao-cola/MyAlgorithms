#include <stack>
#include <exception>
#include <iostream>
/*

https://cuijiahua.com/blog/2017/11/basis_5.html
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

*/

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty()) {
			while (stack1.size() > 0) {
				int data = stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}
		int pop_element = stack2.top();
		stack2.pop();
		return pop_element;
	}

private:
	std::stack<int> stack1;
	std::stack<int> stack2;
};

void example_1()
{
	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	int ret;
	try
	{
	 s->push(2);
	 s->push(5);
	 s->push(9);
	 ret = s->pop();

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
