// 改变数组长度

#ifndef changeLength1D_
#define changeLength1D_

#include "myExceptions.h"

using namespace std;

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParameterValue("new length must be >= 0");

	T* temp = new T[newLength];              // 新数组
	int number = min(oldLength, newLength);  // 复制的元素个数
	copy(a, a + number, temp);
	delete[] a;                             // 析构原内存
	a = temp;
}

#endif
