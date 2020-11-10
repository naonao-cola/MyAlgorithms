#include <iostream>
#include <vector>

using namespace std;
/*
https://cuijiahua.com/blog/2017/12/algorithm_4.html
快速排序是一种交换排序，它由C. A. R. Hoare在1962年提出。


快速排序的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分：分割点左边都是比它小的数，右边都是比它大的数。

然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
*/
int division(vector<int> &list, int left, int right) {
	// 以最左边的数(left)为基准
	int base = list[left];
	while (left < right) {
		// 从序列右端开始，向左遍历，直到找到小于base的数
		while (left < right && list[right] >= base)
			right--;
		// 找到了比base小的元素，将这个元素放到最左边的位置
		list[left] = list[right];

		// 从序列左端开始，向右遍历，直到找到大于base的数
		while (left < right && list[left] <= base)
			left++;
		// 找到了比base大的元素，将这个元素放到最右边的位置
		list[right] = list[left];
	}

	// 最后将base放到left位置。此时，left位置的左侧数值应该都比left小；
	// 而left位置的右侧数值应该都比left大。
	list[left] = base;
	return left;
}

// 快速排序
void QuickSort(vector<int> &list, int left, int right) {
	// 左下标一定小于右下标，否则就越界了
	if (left < right) {
		// 对数组进行分割，取出下次分割的基准标号
		int base = division(list, left, right);

		// 对“基准标号“左侧的一组数值进行递归的切割，以至于将这些数值完整的排序
		QuickSort(list, left, base - 1);

		// 对“基准标号“右侧的一组数值进行递归的切割，以至于将这些数值完整的排序
		QuickSort(list, base + 1, right);
	}
}

void example_4() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result = test;
	QuickSort(result, 0, static_cast<int>(result.size() - 1));
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}