#include <iostream>
#include <vector>

using namespace std;


/*
https://cuijiahua.com/blog/2017/12/algorithm_3.html


希尔(Shell)排序又称为缩小增量排序，它是一种插入排序。它是直接插入排序算法的一种威力加强版。
希尔排序，也称递减增量排序算法，以其设计者希尔（Donald Shell）的名字命名，该算法由 1959 年公布。

*/
vector<int> ShellSort(vector<int> list) {
	vector<int> result = list;
	int n = static_cast<int>(result.size());
	for (int gap = n >> 1; gap > 0; gap >>= 1) {
		for (int i = gap; i < n; i++) {
			int temp = result[i];
			int j = i - gap;
			while (j >= 0 && result[j] > temp) {
				result[j + gap] = result[j];
				j -= gap;
			}
			result[j + gap] = temp;
		}
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

void example_3() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	
	vector<int> result;
	result = ShellSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}