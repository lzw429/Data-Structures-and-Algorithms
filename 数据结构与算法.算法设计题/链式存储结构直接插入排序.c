// 在链式存储结构上设计直接插入排序算法
struct ListNode {
    int val;
    ListNode *next;
};

void StraightInsortSort(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return;
    ListNode *pre = head;
    ListNode *cur = head->next;
    while (cur) {
        if (cur->next && cur->val > cur->next->val) // 需要将cur->next调整位置
        {
            while (pre->next && pre->next->val < cur->next->val)
                pre = pre->next; // 找到cur->next的位置
            // 将cur->next插入到pre之后
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            pre = head;
        } else // 不需要将cur->next调整位置
            cur = cur->next;
    }
}