
// 最大优先级队列的堆实现
// 继承自抽象数据类型 maxPriorityQueue

#ifndef maxHeap_
#define maxHeap_

#include "maxPriorityQueue.h"
#include "myExceptions.h"
#include "changeLength1D.h"
#include <sstream>
#include <algorithm>

using namespace std;

template<class T>
class maxHeap : public maxPriorityQueue<T>
{
public:
	maxHeap(int initialCapacity = 10); // 构造方法
	~maxHeap() { delete[] heap; } // 析构方法
	bool empty() const { return heapSize == 0; }
	int size() const
	{
		return heapSize;
	}
	const T& top()
	{
		// 返回最大元素
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
maxHeap<T>::maxHeap(int initialCapacity)
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
void maxHeap<T>::push(const T& theElement)
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
	while (currentNode != 1 && heap[currentNode / 2] < theElement) //如果父结点值小于theElement
	{
		// 不能将元素添加到 heap[currentNode]
		heap[currentNode] = heap[currentNode / 2]; // currentNode父结点赋值给currentNode
		currentNode /= 2;                          // 移动到父结点
	}
	// 为theElement找到位置currentNode
	heap[currentNode] = theElement;
}

template<class T>
void maxHeap<T>::pop() // 在堆中移除最大元素
{
	if (heapSize == 0) // 如果堆为空，返回NULL
		throw queueEmpty();

	// 删除最大元素
	heap[1].~T();

	// 删除最后一个元素，重新建堆
	T lastElement = heap[heapSize--];

	// 从根结点开始为lastElement找到位置
	int currentNode = 1,
		child = 2;     // currentNode的子结点
	while (child <= heapSize)
	{
		// 使heap[child]为currentNode的较大的子结点
		if (child < heapSize && heap[child] < heap[child + 1])
			child++;

		// 判断能否将lastElement放入heap[currentNode]
		if (lastElement >= heap[child])
			break;   // 能放入

		 // 不能放入
		heap[currentNode] = heap[child]; // currentNode的较大子结点赋值给currentNode
		currentNode = child;             // currentNode移动到其子结点
		child *= 2;
	}
	heap[currentNode] = lastElement;
}

template<class T>
void maxHeap<T>::initialize(T *theHeap, int theSize)
{
	// 在数组 theHeap[1:theSize] 上初始化最大堆
	delete[] heap; // 删除当前堆
	heap = theHeap;
	heapSize = theSize;

	// 建堆，将以root为根的子树调整为最大堆
	for (int root = heapSize / 2; root >= 1; root--)
	{
		T rootElement = heap[root];

		// 找到位置以放入rootElement
		int child = 2 * root; // child的父结点是目标
							  // 为rootElement定位
		while (child <= heapSize)
		{
			// heap[child] 应是兄弟结点中较大的
			if (child < heapSize && heap[child] < heap[child + 1])
				child++;

			// 判断能否将rootElement放入heap[child/2]
			if (rootElement >= heap[child])
				break;  // 能放入

			 // 不能放入
			heap[child / 2] = heap[child]; // 将root的较大子结点赋值给root
			child *= 2;                    // child向下移动
		}
		heap[child / 2] = rootElement;
	}
}

template<class T>
void maxHeap<T>::output(ostream& out) const
{// 将数组放入流，输出
	copy(heap + 1, heap + heapSize + 1, ostream_iterator<T>(cout, "  "));
}

// 重载操作符<<
template <class T>
ostream& operator<<(ostream& out, const maxHeap<T>& x)
{
	// 将最大堆x放入输出流out
	x.output(out); return out;
}

#endif
