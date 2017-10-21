
// ��С���ȼ����еĶ�ʵ��
// �̳��Գ����������� minPriorityQueue

#ifndef minHeap_
#define minHeap_

#include "minPriorityQueue.h"
#include "myExceptions.h"
#include "changeLength1D.h"
#include <sstream>
#include <algorithm>

using namespace std;

template<class T>
class minHeap : public minPriorityQueue<T>
{
public:
	minHeap(int initialCapacity = 10);
	~minHeap() { delete[] heap; }
	bool empty() const { return heapSize == 0; }
	int size() const
	{
		return heapSize;
	}
	const T& top()
	{// return min element
		if (heapSize == 0)
			throw queueEmpty();
		return heap[1];
	}
	void pop();
	void push(const T&);
	void initialize(T *, int);
	void deactivateArray()
	{
		heap = NULL; arrayLength = heapSize = 0;
	}
	void output(ostream& out) const;
private:
	int heapSize;       // ������Ԫ�ظ���
	int arrayLength;    // ���鳤�� = �������� + 1
	T *heap;            // �洢Ԫ�ص�����
};

template<class T>
minHeap<T>::minHeap(int initialCapacity)
{// ���캯��
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity + 1;
	heap = new T[arrayLength];
	heapSize = 0;
}

template<class T>
void minHeap<T>::push(const T& theElement)
{// ���Ԫ�أ��Ե����Ͻ���

	// װ��ʱ��������
	if (heapSize == arrayLength - 1)
	{// ���鳤�ȷ���
		changeLength1D(heap, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	// ʹ��currentNodeΪ����ӵ�theElement��λ��
	// currentNode ����Ҷ��㿪ʼ
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] > theElement) //��������ֵ����theElement
	{
		// ���ܽ�Ԫ����ӵ� heap[currentNode]
		heap[currentNode] = heap[currentNode / 2]; // currentNode����㸳ֵ��currentNode
		currentNode /= 2;                          // �ƶ��������
	}
	// ΪtheElement�ҵ�λ��currentNode
	heap[currentNode] = theElement;
}

template<class T>
void minHeap<T>::pop() // �ڶ����Ƴ���СԪ�� 
{
	if (heapSize == 0)   // �����Ϊ�գ�����NULL
		throw queueEmpty();

	// ɾ����СԪ��
	heap[1].~T();

	// ɾ�����һ��Ԫ�أ����½���
	T lastElement = heap[heapSize--];

	// �Ӹ���㿪ʼΪlastElement�ҵ�λ��
	int currentNode = 1,
		child = 2;     // currentNode���ӽ��
	while (child <= heapSize)
	{
		// ʹheap[child]ΪcurrentNode�Ľ�С���ӽ��
		if (child < heapSize && heap[child] > heap[child + 1])
			child++;

		// can we put lastElement in heap[currentNode]?
		if (lastElement <= heap[child])
			break;   // yes

		 // no
		heap[currentNode] = heap[child]; // move child up
		currentNode = child;             // move down a level
		child *= 2;
	}
	heap[currentNode] = lastElement;
}

template<class T>
void minHeap<T>::initialize(T *theHeap, int theSize)
{// Initialize max heap to element array theHeap[1:theSize].
	delete[] heap;
	heap = theHeap;
	heapSize = theSize;

	// heapify
	for (int root = heapSize / 2; root >= 1; root--)
	{
		T rootElement = heap[root];

		// find place to put rootElement
		int child = 2 * root; // parent of child is target
							  // location for rootElement
		while (child <= heapSize)
		{
			// heap[child] should be smaller sibling
			if (child < heapSize && heap[child] > heap[child + 1])
				child++;

			// can we put rootElement in heap[child/2]?
			if (rootElement <= heap[child])
				break;  // yes

			 // no
			heap[child / 2] = heap[child]; // move child up
			child *= 2;                    // move down a level
		}
		heap[child / 2] = rootElement;
	}
}

template<class T>
void minHeap<T>::output(ostream& out) const
{// Put the array into the stream out.
	copy(heap + 1, heap + heapSize + 1, ostream_iterator<T>(cout, "  "));
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const minHeap<T>& x)
{
	x.output(out); return out;
}

#endif
