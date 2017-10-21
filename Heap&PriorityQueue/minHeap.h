
// 最小优先级队列的堆实现
// 继承自抽象数据类型 minPriorityQueue

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
	int heapSize;       // 队列中元素个数
	int arrayLength;    // 数组长度 = 队列容量 + 1
	T *heap;            // 存储元素的数组
};

template<class T>
minHeap<T>::minHeap(int initialCapacity)
{// 构造函数
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
{// 添加元素，自底向上建堆

	// 装满时数组扩容
	if (heapSize == arrayLength - 1)
	{// 数组长度翻倍
		changeLength1D(heap, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	// 使用currentNode为被添加的theElement找位置
	// currentNode 从新叶结点开始
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] > theElement) //如果父结点值大于theElement
	{
		// 不能将元素添加到 heap[currentNode]
		heap[currentNode] = heap[currentNode / 2]; // currentNode父结点赋值给currentNode
		currentNode /= 2;                          // 移动到父结点
	}
	// 为theElement找到位置currentNode
	heap[currentNode] = theElement;
}

template<class T>
void minHeap<T>::pop() // 在堆中移除最小元素 
{
	if (heapSize == 0)   // 如果堆为空，返回NULL
		throw queueEmpty();

	// 删除最小元素
	heap[1].~T();

	// 删除最后一个元素，重新建堆
	T lastElement = heap[heapSize--];

	// 从根结点开始为lastElement找到位置
	int currentNode = 1,
		child = 2;     // currentNode的子结点
	while (child <= heapSize)
	{
		// 使heap[child]为currentNode的较小的子结点
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
