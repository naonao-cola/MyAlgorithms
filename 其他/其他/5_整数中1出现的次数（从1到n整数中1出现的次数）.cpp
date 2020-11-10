#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2017/12/basis_31.html

输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如输入12，从1到12这些整数中包含1的数字有1，10，11和12，1一共出现了5次。



本文采用数学之美上面提出的方法，设定整数点（如1、10、100等等）作为位置点i（对应n的各位、十位、百位等等），
分别对每个数位上有多少包含1的点进行分析。

根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i

当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），
每一次都包含100个连续的点，即共有(a/10+1)*100个点的百位为1

当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，
则共有a/10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a/10*100）+(b+1)，这些点百位对应为1

当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）

综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1

之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
*/


//可以使用堆排序优化
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		// 统计次数
		int count = 0;
		for (int i = 1; i <= n; i *= 10) {
			// 计算高位和低位
			int a = n / i, b = n % i;
			count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
		}
		return count;
	}
};


void example_5()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->NumberOf1Between1AndN_Solution(31556);

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
