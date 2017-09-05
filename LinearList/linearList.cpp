//一个线性表的抽象类
template<class T>
class linearList {
public:
    virtual ~ linearList() {};//析构函数
    virtual bool empty() const = 0;//const 表示该函数不能修改成员变量，=0表示这是纯虚函数（可理解为java中的抽象函数）
    //返回true，当且仅当线性表为空

    virtual int size() const =0;
    //返回线性表的元素个数

    virtual T &get(int theIndex) const =0;
    //返回索引为theIndex的元素

    virtual int indexOf(const T &TheElement) const =0;
    //返回元素theElement第一次出现时的索引

    virtual void erase(int theIndex) =0;
    //删除索引为theIndex的元素

    virtual void insert(int theIndex, const T &theElement) =0;
    //把theElement插入线性表中索引为theIndex的位置上

    virtual void output(ostream &out) const =0;
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
    detele [] a; //释放老数组的内存空间
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
    if (initialCapacity < 1)
    {

    }
}
