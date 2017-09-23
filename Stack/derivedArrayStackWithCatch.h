//栈是一种插入和删除操作都被限制在一端进行的线性表，可将数组线性表的右端定义为栈顶。

#ifndef derivedArrayStackWithCatch_
#define derivedArrayStackWithCatch_

#include "arrayList.h"
#include "stack.h"
#include "myExceptions.h"

using namespace std;

template<class T>
class derivedArrayStackWithCatch : private arrayList<T>,
	public stack<T>
{
public:
	derivedArrayStackWithCatch(int initialCapacity = 10)
		: arrayList<T>(initialCapacity) {}
	bool empty() const
	{
		return arrayList<T>::empty();
	}
	int size() const
	{
		return arrayList<T>::size();
	}
	T& top()
	{
		try { return get(arrayList<T>::size() - 1); }
		catch (illegalIndex)
		{
			throw stackEmpty();
		}
	}
	void pop()
	{
		try { erase(arrayList<T>::size() - 1); }
		catch (illegalIndex)
		{
			throw stackEmpty();
		}
	}
	void push(const T& theElement)
	{
		insert(arrayList<T>::size(), theElement);
	}
};

#endif
