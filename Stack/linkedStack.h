//定制链表栈

#ifndef linkedStack_
#define linkedStack_

#include "stack.h"
#include "chainNode.h"
#include "myExceptions.h"
#include <sstream>

using namespace std;

template<class T>
class linkedStack : public stack<T>
{
public:
	linkedStack(int initialCapacity = 10)//构造函数
	{
		stackTop = NULL; stackSize = 0;
	}
	~linkedStack();//析构函数
	bool empty() const
	{
		return stackSize == 0;
	}
	int size() const
	{
		return stackSize;
	}
	T& top()
	{
		if (stackSize == 0)
			throw stackEmpty();
		return stackTop->element;
	}
	void pop();
	void push(const T& theElement)
	{
		stackTop = new chainNode<T>(theElement, stackTop);
		stackSize++;
	}
private:
	chainNode<T>* stackTop;  // 栈顶指针
	int stackSize;           // 栈中元素个数
};

template<class T>
linkedStack<T>::~linkedStack()
{// 析构函数
	while (stackTop != NULL)
	{
		chainNode<T>* nextNode = stackTop->next;
		delete stackTop;// 删除栈顶结点
		stackTop = nextNode;
	}
}

template<class T>
void linkedStack<T>::pop()
{// 删除栈顶结点
	if (stackSize == 0)
		throw stackEmpty();

	chainNode<T>* nextNode = stackTop->next;
	delete stackTop;
	stackTop = nextNode;
	stackSize--;
}
#endif
