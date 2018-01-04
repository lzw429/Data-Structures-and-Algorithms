// 设计在链式存储结构上交换二叉树中所有结点左右子树的算法。
struct bitree {
    bitree *left;
    bitree *right;
    int val;
};

void swap_left_right(bitree *root) {
    if (root == nullptr)
        return;
    swap_left_right(root->left);
    swap_left_right(root->right);
	bitree *t = root->left;
    root->left = root->right;
    root->right = t;
}