#include <stdio.h>

void Swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

// ʱ�临�Ӷȣ�
// ��� O(n) (�Ѿ�����) | ƽ�� O(n^2) | � O(n^2)���Ѿ����򣬵���)
// �ռ临�Ӷ� O(1)
// �ȶ��ԣ��ȶ��� array[j] == key ����ѭ�����ͱ�֤���ȶ���
// �� n �Ƚ�С��ʱ�� ���� ���������������
void InsertSort(int array[], int size) {
	// �����Ż���
	// for (int i = 1; i < size; i++) {
	for (int i = 0; i < size; i++) {
		// array[i] ����Ҫ��������ݣ����浽������ key
		// �� [0, i) ���Ѿ����������
		// ѭ���Ĺ��� j ~ [i - 1, 0] ���κ� key �Ƚ�
		// 1. array[j] <= key break
		// 2. array[j] > key array[j + 1] = array[j]
		// ѭ���������� array[j + 1] = key
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

// ʱ�临�Ӷ�
// ���(O(n)) | ƽ��(O(n^1.3) | ���O(n^2)
// �ռ临�Ӷ� O(1)
// �ȶ��ԣ����ȶ�	����ͬ������û����֤����һ�����飩
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

// ֱ��ѡ������
// ʱ�临�Ӷ�
// ��� | ƽ�� | ���	O(n^2)		(�����У�
// �ռ临�Ӷ� O(1)
// �ȶ��ԣ����ȶ�		{ 7, 8, 3a, 5, 3b } �����޷���֤3a ���� 3b ǰ
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
		// m ������������±���
		Swap(array + m, array + size - i - 1);
	}
}

// ������
// ʱ�临�Ӷ�
// ��� | ƽ�� | �	O(n*logn)	(������)
// �ռ临�Ӷ� O(1)
// �ȶ���: ���ȶ�	�ѵĹ�������Һ���û������
// �����
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

// ����
void CreateHeap(int array[], int size) {
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}
}

// ����
void HeapSort(int array[], int size) {
	CreateHeap(array, size);

	for (int i = 0; i < size; i++) {
		Swap(array, array + size - i - 1);
		AdjustDown(array, size - i - 1, 0);
	}
}

// ð������
// ʱ�临�Ӷ�
// ��� O(n) (�Ѿ�����) | ƽ�� | � O(n^2)
// �ռ临�Ӷ� O(1)
// �ȶ��ԣ��ȶ�
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

// ��������
// ���ܱ�֤ left һ���� 0
int Partion_1(int array[], int left, int right) {
	int begin = left;	// ��Ҫд�� begin = 0;
	int end = right;	// end ������ right - 1������ { 1��2, 3, 4 }

	while (begin < end) {
		// ��׼ֵ���ұߣ��������
		// ������ { 1, 7, 8, 4 }
		// array[begin] �� array[right] �Ƚϱ����� ==
		// ���� { 1, 1, 1 }
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}
		// ��ζ�� array[begin] > array[right]

		while (begin < end && array[end] >= array[right]) {
			end--;
		}
		// ��ζ�� array[end] < array[right]

		Swap(array + begin, array + end);
	}

	// ��ζ�����䱻�ֳ� 3 �ݣ��ֱ��� { С �� �� ��׼ֵ }
	Swap(array + begin, array + right);

	// ���ص�ǰ��׼ֵ�����±�
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
		// ������ֻ��һ����
		return;
	}

	if (left > right) {
		// ������û����
		return;
	}

	// ��׼ֵ�� array[right]
	int div;	// �����������ջ�׼ֵ���ڵ��±�
	div = Partion_1(array, left, right);	// ���� array[left, right]
									// ��С�ķ��󣬴�ķ���
									// ��������׼ֵ���ڵ��±�
	// ���䱻�ֳ� 
	// [left, div - 1] �Ȼ�׼ֵС	*
	// [div, div]	   ��׼ֵ		�Ѿ�������λ��
	// [div + 1, right] �Ȼ�׼ֵ��	*
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