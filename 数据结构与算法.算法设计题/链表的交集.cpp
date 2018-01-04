// 设有集合A和集合B，要求设计生成集合C=A∩B的算法，其中集合A、B和C用链式存储结构表示
struct ListNode {
    int val;
    ListNode *next;
};

ListNode *intersection(ListNode *A, ListNode *B) {
    ListNode *C = (ListNode *) malloc(sizeof(ListNode));
    for (ListNode *i = A; i != nullptr; i = i->next) {
        for (ListNode *j = B; j != nullptr; j = j->next) {
            if (i->val == j->val) {
                ListNode *next = (ListNode *) malloc(sizeof(ListNode));
                next->val = i->val;
                next->next = C->next;
                C->next = next;
            }
        }
    }
    return C;
}