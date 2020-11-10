#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
/*


https://cuijiahua.com/blog/2017/12/basis_19.html

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
array[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}
则依次打印出数组：1，2，3，4，8，12，16，15，14，13，9，5，6，7，11，10。

将结果存入vector数组，从左到右，再从上到下，再从右到左，最后从下到上遍历。

*/

class Solution {
public:
	std::vector<int> printMatrix(std::vector<std::vector<int> > matrix) {
		std::size_t rows = matrix.size();			//行数
		std::size_t cols = matrix[0].size();		//列数
		std::vector<int> result;

		if (rows == 0 && cols == 0) {
			return result;
		}
		int left = 0, right = static_cast<int>(cols - 1), top = 0, bottom = static_cast<int>(rows - 1);

		while (left <= right && top <= bottom) {
			//从左到右
			for (int i = left; i <= right; ++i) {
				result.push_back(matrix[top][i]);
			}
			//从上到下
			for (int i = top + 1; i <= bottom; ++i) {
				result.push_back(matrix[i][right]);
			}
			//从右到左
			if (top != bottom) {
				for (int i = right - 1; i >= left; --i) {
					result.push_back(matrix[bottom][i]);
				}
			}
			//从下到上
			if (left != right) {
				for (int i = bottom - 1; i > top; --i) {
					result.push_back(matrix[i][left]);
				}
			}
			left++, top++, right--, bottom--;
		}
		return result;
	}
};



void example_3()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<std::vector<int> >  pRoot1 = { {1,2,3,4} ,{5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	
	Solution* s = new Solution;
	std::vector<int> ret;
	try
	{

		ret = s->printMatrix(pRoot1);

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
