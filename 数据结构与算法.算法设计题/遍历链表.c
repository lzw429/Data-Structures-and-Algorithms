// 统计单链表HL中结点的值等于给定值X的结点数
int CountX(LNode *HL, ElemType x) {
    int count = 0;
    LNode *p = HL->next;
    while (p->next) {
        if (p->data == x)
            count++;
        p = p->next;
    }
    return count;
}