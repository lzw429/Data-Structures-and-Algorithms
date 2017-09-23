//Linked Lists: Cursor Implementation
//�����ռ������α�ʵ������
//��0λ�洢freelistλ�ã���1λ��header���洢�����ݵ��׸�����λ��
#define SpaceSize 1000
typedef struct
{
	ElementType data;
	int next;
} Node, CursorSpace[SpaceSize];

int CursorAlloc(void)
{
	int p; //pointer
	p = CursorSpace[0].next;//��ǰ����λ
	CursorSpace[0].next = CursorSpace[p].next;//�µĿ���λ
	return p;
}

void CursorFree(int p)
{
	int i = 1;
	while (CursorSpace[i].next != p)//i��p֮ǰ��һλ
		i = CursorSpace[i].next;
	CursorSpace[i].next = CursorSpace[p].next;
	CursorSpace[p].next = CursorSpace[0].next;
	CursorSpace[0].next = p;//p��Ϊ��ǰ����λ
}

bool isTail(int r)
{
	return CursorSpace[r].next = header;
}

Status Insert(elementType e, List L, int p)
{
	int Tmpcell;
	Tmpcell = CursorAlloc();
	if (Tmpcell == 0)
		return ERROR;
	CursorSpace[Tmpcell].data = e;
	CursorSpace[Tmpcell].next = CursorSpace[p].next;
	CursorSpace[p].next = Tmpcell;
	return OK;
}
