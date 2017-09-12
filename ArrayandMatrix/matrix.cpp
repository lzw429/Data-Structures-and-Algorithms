//矩阵类的声明
template<class T>
class matrix {
    friend ostream &operator<<(ostream &, const matrix<T> &);

public:
    matrix(int theRows = 0, int theColumns = 0);//构造函数
    matrix(const matrix<T> &);//复制构造函数
    ~matrix() { delete[]element; }//析构函数
    int rows() const { return theRows; }

    int columns() const { return theColumns; }

    T &operator()(int i, int j) const;

    matrix<T> &operator=(const matrix<T> &);

    matrix<T> operator+() const;

    matrix<T> operator+(const matrix<T> &) const;

    matrix<T> operator-() const;

    matrix<T> operator-(const matrix<T> &) const;

    matrix<T> operator*(const matrix<T> &) const;

    matrix<T> operator+=(const T &);

private:
    int theRows;
    int theColumns;
    T *element;//数组用指针保存
};

//矩阵类matrix的构造函数和复制构造函数
template<class T>
matrix<T>::matrix(int theRows, int theColumns) {
    //构造函数
    if (theRows < 0 || theColumns < 0)//检查参数合法性
        throw illegalParameterValue("Rows and columns must be >= 0.");
    if ((theRows == 0 || theColumns == 0) && (theColumns != 0 || theRows != 0))//其中有一个为零
        throw illegalParameterValue("Either both or neither rows and columns should be zero.");
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[theRows * theColumns];
};

template<class T>
matrix<T>::matrix(const matrix<T> &m) {
    //复制构造函数
    //创建矩阵
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[theRows * theColumns];

    //复制m的每个元素
    copy(m.element, m.element + theRows * theColumns, element);//start,end,target
}

//矩阵类matrix对赋值操作符=的重载
template<class T>
matrix<T> &matrix<T>::operator=(const matrix<T> &m) {
    if (this != &m)//不能复制自己
    {
        delete[]element;//析构当前成员
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T[theRows * theColumns];
        copy(m.element, m.element + theRows * theColumns, element);//start,end,target
        return *this;
    }
}

//矩阵类matrix对()操作符的重载，()操作符用于获取矩阵元素
template<class T>
T &matrix<T>::operator()(int i, int j) const {
    if (i < 1 || i > theRows || j < 1 || j > theColumns)//i取值范围是[1,theRows]，j取值范围是[1,theColumns]
        throw matrixIndexOutOfBounds();
    return element[(i - 1) * theColumns + j - 1];
}

//矩阵加法
template<class T>
matrix<T> matrix<T>::operator+(const matrix<T> &m) const {
    if (theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();
    matrix<T> w(theRows, theColumns);//构造要返回的矩阵
    for (int i = 0; i < theRows * theColumns; i++) {
        w.element[i] = element[i] + m.element[i];
    }
    return w;
}

//矩阵乘法
template<class T>
matrix<T> matrix<T>::operator*(const matrix<T> &m) const {
    if (theColumns != m.theRows)
        throw matrixSizeMismatch();
    matrix<T> w(theRows, m.theColumns);//构造要返回的矩阵
    int ct = 0, cm = 0, cw = 0;
    //ct遍历*this，cm遍历m，cw遍历w
    for (int i = 1; i <= theRows; i++) {
        //计算矩阵结果的第i行
        for (int j = 1; j <= m.theColumns; j++) {
            T sum = element[ct] * m.element[cm];//w(i,j)第一项
            for (int k = 2; k <= theColumns; k++)//累加w(i,j)余下所有项
            {
                ct++;//*this中第i行的下一项
                cm += m.theColumns;//m中第j列的下一项
                sum += element[ct] * m.element[cm];
            }
            w.element[cw++] = sum;//存储在w(i,j)
            
        }
    }
    return w;
}