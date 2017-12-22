// 设计判断两个二叉树是否相同的算法
struct bitree {
    int val;
    bitree *left;
    bitree *right;
};

int compare(bitree *t1, bitree *t2) {
    if (t1 == nullptr && t2 == nullptr)
        return 0;//相同
    if (t1 == nullptr || t2 == nullptr || (t1.val != t2.val))
        return 1;//不相同
    return compare(t1->left, t2->left) || compare(t1->right, t2->right);
}