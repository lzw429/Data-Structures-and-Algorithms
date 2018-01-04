// 设计判断单链表中元素是否是递增的算法
struct ListNode {
    ListNode *next;
    int val;
};

int isIncreasing(ListNode *head) {
    if (!head)
        return -1;// 不存在
    head = head->next;
    if (!head)
        return 1;// 是递增
    if (!head->next)
        return 1;// 是递增
    while (head && head->next) {
        if (head->val > head->next->val)
            return 0;// 非递增
        head = head->next;
    }
    return 1;
}