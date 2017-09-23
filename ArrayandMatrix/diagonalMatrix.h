//类diagonalMatrix的声明
template<class T>
class diagonalMatrix {
public:
    diagonalMatrix(int theN = 10);

    ~diagonalMatrix() { delete[] element; }

    T get(int i, int j) const;

    void set(int, int, const T &);

private:
    int n;//矩阵维数
    T *element;//存储对角矩阵的一维数组
};

//构造函数
template<class T>
diagonalMatrix<T>::diagonalMatrix(int theN) {
    // validate theN
    if (theN < 1)
        throw illegalParameterValue("Matrix size must be > 0");

    n = theN;
    element = new T[n];
}

template<class T>
T diagonalMatrix<T>::get(int i, int j) const {// 返回对角矩阵(i,j)的元素
    // 验证参数
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    if (i == j)
        return element[i - 1];   // 对角元素
    else
        return 0;              // 非对角元素
}

template<class T>
void diagonalMatrix<T>::set(int i, int j, const T &newValue) {// 存储元素到对角矩阵(i,j)
    // 验证参数
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    if (i == j)
        //保存元素
        element[i - 1] = newValue;
    else
        //要存储元素在非对角线，值必须为0
    if (newValue != 0)
        throw illegalParameterValue("nondiagonal elements must be zero");
}
