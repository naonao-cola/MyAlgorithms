#include <iostream>
#include <vector>

using namespace std;


/*

https://cuijiahua.com/blog/2017/12/algorithm_5.html
简单选择排序是一种选择排序。
选择排序：每趟从待排序的记录中选出关键字最小的记录，顺序放在已排序的记录序列末尾，直到全部排序结束为止。

*/
// 简单选择排序
vector<int> SelectSort(vector<int> list) {
	// 需要遍历获得最小值的次数
	// 要注意一点，当要排序 N 个数，已经经过 N-1 次遍历后，已经是有序数列
	vector<int> result = list;
	for (int i = 0; i < result.size(); i++) {
		// 用来保存最小值得索引
		int index = i;
		// 用来保存最小值得索引
		for (int j = i + 1; j < result.size(); j++) {
			if (result[index] > result[j]) {
				index = j;
			}
		}
		if (index == i) {
			continue;
		}
		// 将找到的第i个小的数值放在第i个位置上
		swap(result[i], result[index]);
		cout << "第" << i + 1 << "趟:\t";
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

void example_5() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = SelectSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	system("pause");
}