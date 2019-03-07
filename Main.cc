#include <stdio.h>

void Swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

// 时间复杂度：
// 最好 O(n) (已经有序) | 平均 O(n^2) | 最坏 O(n^2)（已经有序，倒序)
// 空间复杂度 O(1)
// 稳定性：稳定， array[j] == key 跳出循环，就保证了稳定性
// 在 n 比较小的时候 或者 大概率是有序的情况
void InsertSort(int array[], int size) {
	// 可以优化成
	// for (int i = 1; i < size; i++) {
	for (int i = 0; i < size; i++) {
		// array[i] 就是要插入的数据，保存到变量中 key
		// 从 [0, i) 是已经有序的区间
		// 循环的过程 j ~ [i - 1, 0] 依次和 key 比较
		// 1. array[j] <= key break
		// 2. array[j] > key array[j + 1] = array[j]
		// 循环结束后，让 array[j + 1] = key
		int key = array[i];
		int j;
		for (j = i - 1; j >= 0 && array[j] > key; j--) {
			array[j + 1] = array[j];
		}

		array[j + 1] = key;
	}
}

void InsertSortWithGap(int array[], int size, int gap) {
	// for (int i = gap; i < size; i++) {
	for (int i = 0; i < size; i++) {
		int key = array[i];
		int j;
		for (j = i - gap; j >= 0 && array[j] > key; j -= gap) {
			array[j + gap] = array[j];
		}

		array[j + gap] = key;
	}
}

// 时间复杂度
// 最好(O(n)) | 平均(O(n^1.3) | 最差O(n^2)
// 空间复杂度 O(1)
// 稳定性：不稳定	（相同的数，没法保证分在一个分组）
void ShellSort(int array[], int size) {
	int gap = size;
	while (1) {
		gap = (gap / 3) + 1;
		InsertSortWithGap(array, size, gap);
		if (gap == 1) {
			break;
		}
	}
}

// 直接选择排序
// 时间复杂度
// 最好 | 平均 | 最差	O(n^2)		(不敏感）
// 空间复杂度 O(1)
// 稳定性：不稳定		{ 7, 8, 3a, 5, 3b } 交换无法保证3a 还在 3b 前
void SelectSort(int array[], int size) {
	//  for (i = 1; i < size; i++) {
	for (int i = 0; i < size; i++) {
		// [0, size - i)
		int m = 0;
		// for (j = 1 ...)
		for (int j = 0; j < size - i; j++) {
			if (array[j] > array[m]) {
				m = j;
			}
		}
		// m 就是最大数的下标了
		Swap(array + m, array + size - i - 1);
	}
}

// 堆排序
// 时间复杂度
// 最好 | 平均 | 最坏	O(n*logn)	(不敏感)
// 空间复杂度 O(1)
// 稳定性: 不稳定	堆的过程里，左右孩子没法控制
// 建大堆
void AdjustDown(int array[], int size, int r) {
	int left = 2 * r + 1;
	int right = 2 * r + 2;
	if (left >= size) {
		return;
	}

	int m = left;
	if (right < size && array[right] > array[left]) {
		m = right;
	}

	if (array[r] >= array[m]) {
		return;
	}

	Swap(array + r, array + m);
	AdjustDown(array, size, m);
}

// 建堆
void CreateHeap(int array[], int size) {
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}
}

// 排序
void HeapSort(int array[], int size) {
	CreateHeap(array, size);

	for (int i = 0; i < size; i++) {
		Swap(array, array + size - i - 1);
		AdjustDown(array, size - i - 1, 0);
	}
}

// 冒泡排序
// 时间复杂度
// 最好 O(n) (已经有序) | 平均 | 最坏 O(n^2)
// 空间复杂度 O(1)
// 稳定性：稳定
void BubbleSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int sorted = 1;
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array + j, array + j + 1);
				sorted = 0;
			}
		}

		if (sorted == 1) {
			break;
		}
	}
}

// 快速排序
// 不能保证 left 一定是 0
int Partion_1(int array[], int left, int right) {
	int begin = left;	// 不要写成 begin = 0;
	int end = right;	// end 不能是 right - 1，反例 { 1，2, 3, 4 }

	while (begin < end) {
		// 基准值在右边，先走左边
		// 否则反例 { 1, 7, 8, 4 }
		// array[begin] 和 array[right] 比较必须有 ==
		// 反例 { 1, 1, 1 }
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}
		// 意味着 array[begin] > array[right]

		while (begin < end && array[end] >= array[right]) {
			end--;
		}
		// 意味着 array[end] < array[right]

		Swap(array + begin, array + end);
	}

	// 意味着区间被分成 3 份，分别是 { 小 ， 大， 基准值 }
	Swap(array + begin, array + right);

	// 返回当前基准值所在下标
	return begin;
}

int Partion_1(int array[], int left, int right) {
	int begin = left;
	int end = right;
	int pivot = array[right];

	while (begin < end) {
		while (begin < end && array[begin] <= pivot) {
			begin++;
		}

		array[end] = array[begin];

		while (begin < end && array[end] >= pivot) {
			end--;
		}

		array[begin] = array[end];
	}

	array[begin] = pivot;

	return begin;
}

int Partion_3(int array[], int left, int right) {
	int d = left;
	for (int i = left; i < right; i++) {
		if (array[i] < array[right]) {
			Swap(array + i, array + d);
			d++;
		}
	}

	Swap(array + d, array + right);
	return d;
}

// array[left, right]
void __QuickSort(int array[], int left, int right) {
	if (left == right) {
		// 区间内只有一个数
		return;
	}

	if (left > right) {
		// 区间内没有数
		return;
	}

	// 基准值是 array[right]
	int div;	// 用来保存最终基准值所在的下标
	div = Partion_1(array, left, right);	// 遍历 array[left, right]
									// 把小的放左，大的放右
									// 返回最后基准值所在的下标
	// 区间被分成 
	// [left, div - 1] 比基准值小	*
	// [div, div]	   基准值		已经在最终位置
	// [div + 1, right] 比基准值大	*
	__QuickSort(array, left, div - 1);
	__QuickSort(array, div + 1, right);
}

void QuickSort(int array[], int size) {
	__QuickSort(array, 0, size - 1);
}

int main() {
	int array[] = { 3, 9, 1, 4, 7, 8, 3, 5 };
	int size = sizeof(array) / sizeof(int);
	QuickSort(array, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}