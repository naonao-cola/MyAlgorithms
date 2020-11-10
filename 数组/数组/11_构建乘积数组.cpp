

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_51.html
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。


//倒序循环中 size_t 与 int 的区别。
size_t是无符号的，size_t会把-1变为最大的整数
https://blog.csdn.net/weixin_43705457/article/details/106540180
*/

class Solution {
public:
	std::vector<int> multiply(const std::vector<int>& A)
	{
		size_t length = A.size();
		std::vector<int> B(length);
		if (length <= 0) 
		{
			return B;
		}
		B[0] = 1;
		for (int i = 1; i < length; i++) 
		{
			B[i] = B[i - 1] * A[i - 1];
		}
		int temp = 1;
		for (int i = static_cast<int>(length - 2); i >= 0; --i) 
		{
			temp *= A[i + 1];
			B[i] *= temp;
		}
		return B;
	}
};

void main()
{

	//此处应写成数组
	//输入的数组有要求。
	std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	std::vector<int> ret;
	ret.reserve(20);
	
	try
	{
		ret=s->multiply(array);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout<< " " << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
