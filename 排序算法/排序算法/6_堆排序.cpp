#include <iostream>
#include <vector>

using namespace std;
/*
https://cuijiahua.com/blog/2018/01/algorithm_6.html

堆排序是一种选择排序。
选择排序：每趟从待排序的记录中选出关键字最小的记录，顺序放在已排序的记录序列末尾，直到全部排序结束为止。

属于二叉树的应用
*/
void HeapAdjust(vector<int> &list, int parent, int length) {
	int temp = list[parent];					// temp保存当前父节点
	int child = 2 * parent + 1;					// 先获得左孩子

	while (child < length) {
		// 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
		if (child + 1 < length && list[child] < list[child + 1]) {
			child++;
		}

		// 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
		if (temp >= list[child]) {
			break;
		}

		// 把孩子结点的值赋给父结点
		list[parent] = list[child];

		// 选取孩子结点的左孩子结点,继续向下筛选
		parent = child;
		child = 2 * parent + 1;
	}
	list[parent] = temp;
}

vector<int> HeadSort(vector<int> list) {
	int length = static_cast<int>(list.size());
	// 循环建立初始堆
	for (int i = length / 2 - 1; i >= 0; i--) {
		HeapAdjust(list, i, length);
	}

	// 进行n-1次循环，完成排序
	for (int i = length - 1; i > 0; i--) {
		// 最后一个元素和第一元素进行交换
		int temp = list[i];
		list[i] = list[0];
		list[0] = temp;

		// 筛选 R[0] 结点，得到i-1个结点的堆
		HeapAdjust(list, 0, i);
		cout << "第" << length - i << "趟排序:";
		for (int i = 0; i < list.size(); i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
	return list;
}

void example_6() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前:";
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = HeadSort(test);
	cout << "排序后:";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}