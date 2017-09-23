//存储稀疏矩阵的多链表

enum Boolean { False, True };
struct Triple//矩阵元素结点
{
	int row, col;
	float value;
};

class Matrix;
class MatrixNode
{
	friend class Matrix;
	friend istream &operator>>(istream &, Matrix &);
private:
	MatrixNode *down, *right;//列，行链指针
	Boolean head;//结点类型；False：非链表头，True：链表头
};

union {//矩阵元素结点或链头结点
	Triple triple;
	MatrixNode *next;
	MatrixNode{ Boolean,Triple * };
};

MatrixNode::MatrixNode(Boolean b, Triple *t) {
	//矩阵结点构造函数
	head = b;	//结点类型			
	if (b) { right = next = this; }
	else triple = *t;
}

typedef MatrixNode *MatrixNodePtr;
//一个指针数组, 用于建立稀疏矩阵	

class Matrix {
	friend istream& operator >> (istream &, Matrix &);//矩阵输入
public:
	~Matrix();//析构函数
private:
	MatrixNode *headnode;//稀疏矩阵的表头
};

istream & operator>> (istream & is, Matrix & matrix) {
	Triple s;
	int p; //p = max{row, col};
	is >> s.row >> s.col >> s.value;//输入矩阵的行数、列数和非零元素个数
	if (s.row > s.col)
		p = s.row;
	else
		p = s.col;                  //取行、列数大者
	matrix.headnode = new MatrixNode(False, &s);//整个矩阵表头结点
	if (!p) {//行、列数均为0
		matrix.headnode->right = matrix.headnode;//零矩阵时
	}
	return is;

	MatrixNodePtr *H = new MatrixNodePtr[p];
	//建立表头指针数组, 指向各链表的表头
	for (int i = 0; i < p; i++)
		H[i] = new MatrixNode(True, 0);
	int CurrentRow = 0;
	MatrixNode *last = H[0];    //当前行最后结点
	for (i = 0; i < s.value; i++) {	    //建立矩阵	
		Triple t;
		is >> t.row >> t.col >> t.value;
		//输入非零元素的三元组
		if (t.row > CurrentRow) {
			//如果行号大于当前行，闭合当前行
			last->right = H[CurrentRow];
			CurrentRow = t.row;
			last = H[CurrentRow];
		}
		last = last->right = new MatrixNode(False, &t); //链入当前行
		H[t.col]->next = H[t.col]->next->down = last;   //链入列链表 	
	}
	last->right = H[CurrentRow];  //闭合最后一行
								  //闭合各列链表
	for (i = 0; i < s.col; i++)
		H[i]->next->down = H[i];
	//链接所有表头结点
	for (i = 0; i < p - 1; i++)
		H[i]->next = H[i + 1];
	H[p - 1]->next = matrix.headnode;
	matrix.headnode->right = H[0];
	delete[] H;
	return is;
}
