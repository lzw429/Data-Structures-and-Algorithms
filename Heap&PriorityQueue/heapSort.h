// 堆排序数组a[1:n]
#ifndef heapSort_
#define heapSort_

#include "maxHeap.h"

using namespace std;

template <class T>
void heapSort(T a[], int n)
{
	//使用堆排序，排序数组a[1:n]
	//创建一个最大堆
	maxHeap<T> heap(1);
	heap.initialize(a, n);

	// 依次从最大堆提取
	for (int i = n - 1; i >= 1; i--)
	{
		T x = heap.top();
		heap.pop();
		a[i + 1] = x;
	}

	// 使堆原有的指针失效，堆仍存在于数组a中
	heap.deactivateArray();
}

#endif
