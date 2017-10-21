//�洢ϡ�����Ķ�����

enum Boolean { False, True };
struct Triple//����Ԫ�ؽ��
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
	MatrixNode *down, *right;//�У�����ָ��
	Boolean head;//������ͣ�False��������ͷ��True������ͷ
};

union {//����Ԫ�ؽ�����ͷ���
	Triple triple;
	MatrixNode *next;
	MatrixNode{ Boolean,Triple * };
};

MatrixNode::MatrixNode(Boolean b, Triple *t) {
	//�����㹹�캯��
	head = b;	//�������			
	if (b) { right = next = this; }
	else triple = *t;
}

typedef MatrixNode *MatrixNodePtr;
//һ��ָ������, ���ڽ���ϡ�����	

class Matrix {
	friend istream& operator >> (istream &, Matrix &);//��������
public:
	~Matrix();//��������
private:
	MatrixNode *headnode;//ϡ�����ı�ͷ
};

istream & operator>> (istream & is, Matrix & matrix) {
	Triple s;
	int p; //p = max{row, col};
	is >> s.row >> s.col >> s.value;//�������������������ͷ���Ԫ�ظ���
	if (s.row > s.col)
		p = s.row;
	else
		p = s.col;                  //ȡ�С���������
	matrix.headnode = new MatrixNode(False, &s);//���������ͷ���
	if (!p) {//�С�������Ϊ0
		matrix.headnode->right = matrix.headnode;//�����ʱ
	}
	return is;

	MatrixNodePtr *H = new MatrixNodePtr[p];
	//������ͷָ������, ָ�������ı�ͷ
	for (int i = 0; i < p; i++)
		H[i] = new MatrixNode(True, 0);
	int CurrentRow = 0;
	MatrixNode *last = H[0];    //��ǰ�������
	for (i = 0; i < s.value; i++) {	    //��������	
		Triple t;
		is >> t.row >> t.col >> t.value;
		//�������Ԫ�ص���Ԫ��
		if (t.row > CurrentRow) {
			//����кŴ��ڵ�ǰ�У��պϵ�ǰ��
			last->right = H[CurrentRow];
			CurrentRow = t.row;
			last = H[CurrentRow];
		}
		last = last->right = new MatrixNode(False, &t); //���뵱ǰ��
		H[t.col]->next = H[t.col]->next->down = last;   //���������� 	
	}
	last->right = H[CurrentRow];  //�պ����һ��
								  //�պϸ�������
	for (i = 0; i < s.col; i++)
		H[i]->next->down = H[i];
	//�������б�ͷ���
	for (i = 0; i < p - 1; i++)
		H[i]->next = H[i + 1];
	H[p - 1]->next = matrix.headnode;
	matrix.headnode->right = H[0];
	delete[] H;
	return is;
}
