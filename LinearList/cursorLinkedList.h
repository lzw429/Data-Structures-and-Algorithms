//Linked Lists: Cursor Implementation
//连续空间中用游标实现链表
//第0位存储freelist位置；第1位是header，存储有数据的首个结点的位置
#define SpaceSize 1000
typedef struct
{
	ElementType data;
	int next;
} Node, CursorSpace[SpaceSize];

int CursorAlloc(void)
{
	int p; //pointer
	p = CursorSpace[0].next;//当前空闲位
	CursorSpace[0].next = CursorSpace[p].next;//新的空闲位
	return p;
}

void CursorFree(int p)
{
	int i = 1;
	while (CursorSpace[i].next != p)//i是p之前的一位
		i = CursorSpace[i].next;
	CursorSpace[i].next = CursorSpace[p].next;
	CursorSpace[p].next = CursorSpace[0].next;
	CursorSpace[0].next = p;//p成为当前空闲位
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
