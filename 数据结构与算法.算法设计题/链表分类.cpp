// 设单链表中有仅三类字符的数据元素(大写字母、数字和其它字符)，要求利用原单链表中结点空间设计出三个单链表的算法，使每个单链表只包含同类字符。
struct ListNode {
    char data;
    ListNode *next;
};

void split(ListNode *head, ListNode *&upper_letter, ListNode *&num, ListNode *&other) {
    for (ListNode *p = head->next; p != nullptr; p = head) {
        head = p->next; // 使p按原单链表顺序遍历
        if ('A' <= p->data && p->data <= 'Z') {
            p->next = upper_letter->next;
            upper_letter->next = p;
        } else if ('0' <= p->data && p->data <= '9') {
            p->next = num->next;
            num->next = p;
        } else {
            p->next = other->next;
            other->next = p;
        }
    }
}