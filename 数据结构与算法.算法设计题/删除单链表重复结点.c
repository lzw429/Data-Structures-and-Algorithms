// 设计在单链表中删除值相同的多余结点的算法
struct ListNode {
    int val;
    ListNode *next;
};

void del_redundant(ListNode *&head) {
    for (ListNode *p = head; p != nullptr; p = p->next) {
        for (ListNode *q = p->next; q != nullptr; q = q->next) {
            if (p->val == q->val)
        }
    }
}