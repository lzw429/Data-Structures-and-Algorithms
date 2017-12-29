// 设计在链式结构上实现简单选择排序的算法
struct ListNode {
    int val;
    ListNode *next;
};

void simpleSelectSort(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return;
    ListNode *cur = head->next;
    ListNode *min = cur;
    while (cur)//保证head到cur这段链表有序
    {

        cur = cur->next;
    }
}