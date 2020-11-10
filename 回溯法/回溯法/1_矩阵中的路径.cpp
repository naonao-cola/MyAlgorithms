#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2018/02/basis_65.html
回溯法


请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如在下面的3x4的矩阵中包含一条字符串"bcced"的路径（路径中的字母用斜体表示）。
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

*/


class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows < 1 || cols < 1 || str == NULL) {
			return false;
		}
		bool* visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);
		int pathLength = 0;
		for (int row = 0; row < rows; row++) 
		{

			for (int col = 0; col < cols; col++) 
			{
				if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)) 
				{
					delete[] visited;
					return true;
				}
			}
		}
		delete[] visited;
		return false;
	}
private:
	bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited) 
	{
		if (str[pathLength] == '\0')
		{
			return true;
		}
		bool hasPath = false;
		if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col]) 
		{
			++pathLength;
			visited[row*cols + col] = true;
			hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);
			if (!hasPath)
			{
				--pathLength;
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}
};

void example_1()
{

	char array1[] = "abcesfcsadee";
	char array2[] = "bcced";

	Solution* s = new Solution;
	bool ret;
	try
	{

		ret = s->hasPath(array1, 3,4,array2);

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
