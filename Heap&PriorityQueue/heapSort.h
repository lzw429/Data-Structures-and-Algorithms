// ����������a[1:n]
#ifndef heapSort_
#define heapSort_

#include "maxHeap.h"

using namespace std;

template <class T>
void heapSort(T a[], int n)
{
	//ʹ�ö�������������a[1:n]
	//����һ������
	maxHeap<T> heap(1);
	heap.initialize(a, n);

	// ���δ�������ȡ
	for (int i = n - 1; i >= 1; i--)
	{
		T x = heap.top();
		heap.pop();
		a[i + 1] = x;
	}

	// ʹ��ԭ�е�ָ��ʧЧ�����Դ���������a��
	heap.deactivateArray();
}

#endif
