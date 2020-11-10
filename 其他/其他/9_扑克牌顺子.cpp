#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_45.html

LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张😊)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,
并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。



满足如下条件才可以认为是顺子：

输入数据个数为5；
输入数据都在0-13之间；
没有相同的数字；
最大值与最小值的差值不大于5。
PS：大小王可以当成任意数。

利用一个flag记录每个数字出现的次数。
*/



class Solution {
public:
	bool IsContinuous(std::vector<int> numbers) {
		if (numbers.size() < 5) {
			return false;
		}
		int max = -1, min = 14;
		int flag = 0;
		for (int i = 0; i < numbers.size(); i++) {
			int curNum = numbers[i];
			if (curNum < 0 || curNum > 13) {
				return false;
			}
			// 大小王，可以模拟任意数
			if (curNum == 0) {
				continue;
			}

			// 如果数字出现了一次
			if (((flag >> curNum) & 1 )== 1) {
				return false;
			}

			// 按位保存数字出现次数，比如0110表示，0出现0次，1出现1次，2出现1次，3出现0次。
			flag |= 1 << curNum;

			// 更新最小值
			if (curNum < min) {
				min = curNum;
			}
			// 更新最大值
			if (curNum > max) {
				max = curNum;
			}
			// 超过范围一定不是顺子
			if (max - min >= 5) {
				return false;
			}
		}
		return true;
	}
};

void example_9()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 4,5,6,7,8,9};

	Solution* s = new Solution;
	bool ret;
	try
	{

		ret = s->IsContinuous(pRoot1);

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
