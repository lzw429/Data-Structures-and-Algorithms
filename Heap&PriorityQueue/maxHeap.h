
// ������ȼ����еĶ�ʵ��
// �̳��Գ����������� maxPriorityQueue

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
	maxHeap(int initialCapacity = 10); // ���췽��
	~maxHeap() { delete[] heap; } // ��������
	bool empty() const { return heapSize == 0; }
	int size() const
	{
		return heapSize;
	}
	const T& top()
	{
		// �������Ԫ��
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
maxHeap<T>::maxHeap(int initialCapacity)
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
void maxHeap<T>::push(const T& theElement)
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
	while (currentNode != 1 && heap[currentNode / 2] < theElement) //��������ֵС��theElement
	{
		// ���ܽ�Ԫ����ӵ� heap[currentNode]
		heap[currentNode] = heap[currentNode / 2]; // currentNode����㸳ֵ��currentNode
		currentNode /= 2;                          // �ƶ��������
	}
	// ΪtheElement�ҵ�λ��currentNode
	heap[currentNode] = theElement;
}

template<class T>
void maxHeap<T>::pop() // �ڶ����Ƴ����Ԫ��
{
	if (heapSize == 0) // �����Ϊ�գ�����NULL
		throw queueEmpty();

	// ɾ�����Ԫ��
	heap[1].~T();

	// ɾ�����һ��Ԫ�أ����½���
	T lastElement = heap[heapSize--];

	// �Ӹ���㿪ʼΪlastElement�ҵ�λ��
	int currentNode = 1,
		child = 2;     // currentNode���ӽ��
	while (child <= heapSize)
	{
		// ʹheap[child]ΪcurrentNode�Ľϴ���ӽ��
		if (child < heapSize && heap[child] < heap[child + 1])
			child++;

		// �ж��ܷ�lastElement����heap[currentNode]
		if (lastElement >= heap[child])
			break;   // �ܷ���

		 // ���ܷ���
		heap[currentNode] = heap[child]; // currentNode�Ľϴ��ӽ�㸳ֵ��currentNode
		currentNode = child;             // currentNode�ƶ������ӽ��
		child *= 2;
	}
	heap[currentNode] = lastElement;
}

template<class T>
void maxHeap<T>::initialize(T *theHeap, int theSize)
{
	// ������ theHeap[1:theSize] �ϳ�ʼ������
	delete[] heap; // ɾ����ǰ��
	heap = theHeap;
	heapSize = theSize;

	// ���ѣ�����rootΪ������������Ϊ����
	for (int root = heapSize / 2; root >= 1; root--)
	{
		T rootElement = heap[root];

		// �ҵ�λ���Է���rootElement
		int child = 2 * root; // child�ĸ������Ŀ��
							  // ΪrootElement��λ
		while (child <= heapSize)
		{
			// heap[child] Ӧ���ֵܽ���нϴ��
			if (child < heapSize && heap[child] < heap[child + 1])
				child++;

			// �ж��ܷ�rootElement����heap[child/2]
			if (rootElement >= heap[child])
				break;  // �ܷ���

			 // ���ܷ���
			heap[child / 2] = heap[child]; // ��root�Ľϴ��ӽ�㸳ֵ��root
			child *= 2;                    // child�����ƶ�
		}
		heap[child / 2] = rootElement;
	}
}

template<class T>
void maxHeap<T>::output(ostream& out) const
{// ����������������
	copy(heap + 1, heap + heapSize + 1, ostream_iterator<T>(cout, "  "));
}

// ���ز�����<<
template <class T>
ostream& operator<<(ostream& out, const maxHeap<T>& x)
{
	// ������x���������out
	x.output(out); return out;
}

#endif
