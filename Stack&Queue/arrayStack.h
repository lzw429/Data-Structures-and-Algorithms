//��derivedArrayList�Ľ������Ա���±��顢���ظ��ƵȲ����ǲ���Ҫ��
//ֻ��Ҫ��ע���Ա���Ҷ�

#ifndef arrayStack_
#define arrayStack_

#include "stack.h"
#include "myExceptions.h"
#include "changeLength1D.h"
#include <sstream>


template<class T>
class arrayStack : public stack<T>
{
public:
	arrayStack(int initialCapacity = 10);
	~arrayStack() { delete[] stack; }
	bool empty() const { return stackTop == -1; }
	int size() const
	{
		return stackTop + 1;//�±��0��ʼ�����Ҫ��1
	}
	T& top()//����ջ��Ԫ�ص�����
	{
		if (stackTop == -1)
			throw stackEmpty();
		return stack[stackTop];
	}
	void pop()
	{
		if (stackTop == -1)
			throw stackEmpty();
		stack[stackTop--].~T();  // T������������ջ����1
	}
	void push(const T& theElement);
private:
	int stackTop;         // ��ǰջ��
	int arrayLength;      // ջ����
	T *stack;           // Ԫ������
};

template<class T>
arrayStack<T>::arrayStack(int initialCapacity)
{// ���캯��
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}

template<class T>
void arrayStack<T>::push(const T& theElement)
{// Add theElement to stack.
	if (stackTop == arrayLength - 1)
	{// no space, double capacity
		changeLength1D(stack, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	// add at stack top
	stack[++stackTop] = theElement;
}
#endif
