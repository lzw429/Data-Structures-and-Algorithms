//从derivedArrayList改进，线性表的下标检查、往回复制等操作是不必要的
//只需要关注线性表的右端

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
		return stackTop + 1;//下标从0开始，因此要加1
	}
	T& top()//返回栈顶元素的引用
	{
		if (stackTop == -1)
			throw stackEmpty();
		return stack[stackTop];
	}
	void pop()
	{
		if (stackTop == -1)
			throw stackEmpty();
		stack[stackTop--].~T();  // T的析构函数；栈顶减1
	}
	void push(const T& theElement);
private:
	int stackTop;         // 当前栈顶
	int arrayLength;      // 栈容量
	T *stack;           // 元素数组
};

template<class T>
arrayStack<T>::arrayStack(int initialCapacity)
{// 构造函数
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
