

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
/*
https://cuijiahua.com/blog/2017/11/basis_6.html
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

*/

class Solution {
public:
	int minNumberInRotateArray(std::vector<int> rotateArray) {
		size_t size = rotateArray.size();							//数组长度
		if (size == 0) {
			return 0;
		}
		size_t left = 0;											//左指针
		size_t right = size - 1;									//右指针
		size_t mid = 0;											//中间指针
		while (rotateArray[left] >= rotateArray[right]) {			//确保旋转
			if (right - left == 1) {								//左右指针相邻
				mid = right;
				break;
			}
			mid = left + (right - left) / 2;					//计算中间指针位置
																//特殊情况：如果无法确定中间元素是属于前面还是后面的递增子数组，只能顺序查找
			if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]) {
				return MinInOrder(rotateArray, left, right);
			}
			//中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面
			if (rotateArray[mid] >= rotateArray[left]) {
				left = mid;
			}
			//中间元素位于后面的递增子数组，此时最小元素位于中间元素的前面
			else {
				right = mid;
			}
		}
		return rotateArray[mid];
	}
private:
	//顺序寻找最小值
	int MinInOrder(std::vector<int> &num, size_t left, size_t right) {
		int result = num[left];
		for (size_t i = left + 1; i < right; i++) {
			if (num[i] < result) {
				result = num[i];
			}
		}
		return result;
	}
};

void example_2()
{

	//此处应写成数组
	std::vector<int> array = {9,7,8,3,4,5};
	Solution* s = new Solution;
	int result;
	try
	{
		result = s->minNumberInRotateArray( array);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
