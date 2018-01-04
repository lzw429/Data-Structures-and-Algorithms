// 设计在单链表中删除值相同的多余结点的算法
struct ListNode {
    int val;
    ListNode *next;
};

void del_redundant(ListNode *&head) {
    ListNode *p, *q, *s;
    for (ListNode *p = head->next; p != nullptr; p = p->next) {
        for (ListNode *q = p->next, s = p; q != nullptr;) {
            if (p->val == q->val)// q是多余结点
            {
                s.next = q->next;// s仅作为临时变量
                free(q);
                q = s.next;
            } else// q不是多余结点
            {
                s = q;//使得s是q前一个结点
                q = q->next;
            }
        }
    }
}