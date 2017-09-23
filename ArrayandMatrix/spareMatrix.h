template<class T>
class sparseMatrix {
public:
    void transpose(sparseMatrix<T> &);

    void add(sparseMatrix<T> &, sparseMatrix<T> &);

private:
    int rows;//矩阵行数
    int cols;//矩阵列数
    arrayList <matrixTerm<T>> terms;//非0项表，包含行、列、值
};

//重载输出操作符<<
template<class T>
ostream &operator<<(ostream &out, sparseMatrix<T> &x) {
    //将x放入输出流
    //输出矩阵特征
    out << "rows = " << x.rows << " columns = " << x.cols << endl;
    out << "nonzero terms = " << x.terms.size() << endl;

    //输出矩阵项，一行一个
    for (auto i = x.terms.begin(); i != x.terms.end(); ++i)
        out << "a(" << (*i).row << ',' << (*i).col << ") = " << (*i).value << endl;
    return out;
}

//重载输入操作符>>
template<class T>
istream &operator>>(istream &in, sparseMatrix<T> &x) {
    //输入一个稀疏矩阵
    //输入矩阵特征
    int numberOfTerms;
    cout << "Enter number of rows, columns, and #terms" << endl;
    in >> x.rows >> x.cols >> numberOfTerms;

    // 设置x.terms的大小，确保足够的容量
    x.terms.reSet(numberOfTerms);

    // 输入项
    matrixTerm <T> mTerm;
    for (int i = 0; i < numberOfTerms; i++) {
        cout << "Enter row, column, and value of term " << (i + 1) << endl;
        in >> mTerm.row >> mTerm.col >> mTerm.value;
        x.terms.set(i, mTerm);
    }

    return in;
}

//稀疏矩阵的转置
template<class T>
void sparseMatrix<T>::transpose(sparseMatrix<T> &b) {
    //转置后的矩阵存储在矩阵b中
    //设置转置矩阵特征
    b.cols = rows;
    b.rows = cols;
    b.terms.reSet(terms.size());

    //初始化以实现转置
    int *colSize = new int[cols + 1];//存储*this每列的非0项元素个数
    int *rowNext = new int[cols + 1];//存储插入的行数

    // 寻找*this中每一列的项的数目
    for (int i = 0; i <= cols; i++) // 初始化
        colSize[i] = 0;
    for (auto i = terms.begin(); i != terms.end(); i++)//计算非0项元素个数
        colSize[(*i).col]++;

    // 寻找b中每一行的起始点
    rowNext[1] = 0;//b的第一行从0开始
    for (int i = 2; i <= cols; i++)
        rowNext[i] = rowNext[i - 1] + colSize[i - 1];

    // 实施从*this到b的转置复制
    matrixTerm <T> mTerm;
    for (auto i = terms.begin(); i != terms.end(); i++) {
        int j = rowNext[(*i).col]++; // b中的位置，先赋值再自增
        mTerm.row = (*i).col;
        mTerm.col = (*i).row;
        mTerm.value = (*i).value;
        b.terms.set(j, mTerm);
    }
}

//两个稀疏矩阵相加
template<class T>
void sparseMatrix<T>::add(sparseMatrix<T> &b, sparseMatrix<T> &c) {
    //计算c = (*this) + b
    //检验相容性
    if (rows != b.rows || cols != b.cols)
        throw matrixSizeMismatch(); // 矩阵不相容

    // 设置结果矩阵c的特征
    c.rows = rows;
    c.cols = cols;
    c.terms.clear();
    int cSize = 0;

    // 定义*this 和 b 的迭代器
    auto it = terms.begin();
    auto ib = b.terms.begin();
    auto itEnd = terms.end();
    auto ibEnd = b.terms.end();

    // 遍历*this和b，把相关的项相加
    while (it != itEnd && ib != ibEnd) {
        // 行主索引加上每一项的列数
        int tIndex = (*it).row * cols + (*it).col;
        int bIndex = (*ib).row * cols + (*ib).col;

        if (tIndex < bIndex) {// b项在后
            c.terms.insert(cSize++, *it);
            it++;
        } else {
            if (tIndex == bIndex) {// 两项在同一位置
                // 仅当相加后不为0时加入c
                if ((*it).value + (*ib).value != 0) {
                    matrixTerm <T> mTerm;
                    mTerm.row = (*it).row;
                    mTerm.col = (*it).col;
                    mTerm.value = (*it).value + (*ib).value;
                    c.terms.insert(cSize++, mTerm);
                }
                it++;
                ib++;
            } else {// t项在后
                c.terms.insert(cSize++, *ib);
                ib++;
            }
        }
    }

    // 复制剩余项
    for (; it != itEnd; it++)
        c.terms.insert(cSize++, *it);
    for (; ib != ibEnd; ib++)
        c.terms.insert(cSize++, *ib);
}