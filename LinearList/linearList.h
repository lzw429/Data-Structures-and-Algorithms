//一个线性表的抽象类
template<class T>
class linearList {
public:
	virtual ~linearList() {};//析构函数
	virtual bool empty() const = 0;//const 表示该函数不能修改成员变量，=0表示这是纯虚函数（可理解为java中的抽象函数）
	//返回true，当且仅当线性表为空

	virtual int size() const = 0;
	//返回线性表的元素个数

	virtual T &get(int theIndex) const = 0;
	//返回索引为theIndex的元素

	virtual int indexOf(const T &TheElement) const = 0;
	//返回元素theElement第一次出现时的索引

	virtual void erase(int theIndex) = 0;
	//删除索引为theIndex的元素

	virtual void insert(int theIndex, const T &theElement) = 0;
	//把theElement插入线性表中索引为theIndex的位置上

	virtual void output(ostream &out) const = 0;
	//把线性表插入输出流out
};

//改变一个一维数组的长度
template<class T>
void changeLength1D(T *&a, int oldLength, int newLength) {
	if (newLength < 0)
		throw illegealParameterValue("new length must be >= 0");
	T *temp = new T(newLength);
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	detele[] a; //释放老数组的内存空间
	a = temp;
}

//类arrayList的定义
template<class T>
class arrayList : public linearList<T> {
public:
	//构造函数，复制构造函数和析构函数
	arrayList(int initialCapacity = 10);

	arrayList(const arrayList<T> &);

	~arrayList() { delete[] element; }

	//ADT方法
	bool empty() const { return listSize == 0; }

	int size() const { return listSize; }

	T &get(int theIndex) const;

	int indexOf(const T &theElement) const;

	void erase(int theIndex);

	void insert(int theIndex, const T &theElement);

	void output(ostream &out) const;

	//其他方法
	int capacity() const { return arrayLength; }

protected:
	void checkIndex(int theIndex) const;
	//若索引theIndex无效，则抛出异常

	T *element;         //存储线性表元素的一维数组
	int arrayLength;    //一维数组的容量
	int listSize;       //线性表的元素个数
};

//类arrayList的构造函数
template<class T>
arrayList<T>::arrayList(int initialCapacity) {
	//构造函数
	if (initialCapacity < 1) {
		ostringstream s;
		s << "Initial capacity =" << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;//初始容量
	element = new T[arrayLength];
	listSize = 0;//元素个数
}

template <class T>
arrayList<T>::arrayList(const arrayList<T> &theList) {
	//复制构造函数
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}

//checkIndex、get和indexOf
template <class T>
void arrarList<T>::checkIndex(int theIndex)const
{
	//确定索引 theIndex 在0 和 listSize - 1之间
	if(theIndex<0||theIndex>=listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}
}

template<class T>
T& arrayList<T>::get(int theIndex)const
{
	//返回索引为 theIndex 的元素
	//若此元素不存在，则抛出异常
	checkIndex(theIndex);
	return element(theIndex);
}

template<class T>
int arrayList<T>::indexOf(const T& theElement)const;
{
	//返回元素theElement第一次出现时的索引
	//若该元素不存在，则返回-1

	//查找元素theElement
	int theIndex = (int)(find(element, element + listSize, theElement) - element);

	//确定元素theElement是否找到
	if (theIndex == listSize)
		//没有找到
		return -1;
	else return theIndex;
}

//删除索引为theIndex的元素
template<class T>
void arrayList<T>::erase(int theIndex)
{
	//删除其索引为theIndex的元素
	//如果该元素不存在，则抛出异常illegalIndex
	checkIndex(theIndex);

	//有效索引，移动其索引大于theIndex的元素
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();//调用析构函数
}

//在索引theIndex的位置上插入一个元素
template<class T>
void arrayList<T>::insert(int theIndex,const T& theElement)
{
	if(theIndex<0||theIndex>=listSize)
	{
		//无效索引
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

	//有效索引，确定数组是否已满
	if(listSize==arrayLength)
	{
		//数组空间已满，数组长度倍增
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	//把元素向右移动一个位置
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}

//把一个线性表插入输出流
template<class T>
void arrayList<T>::output(cout->out)const
{
	//把线性表插入输出流
	copy(element, element + listSize, ostream_iterator<T>(cout, " "));
}
//重载流插入符<<
template<class T>
ostream &operator<< (ostream &out,const arrayList<T> &x)
{
	x.output(out); return out;
}
