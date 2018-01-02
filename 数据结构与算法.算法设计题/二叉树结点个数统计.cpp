// 设计一个在链式存储结构上统计二叉树结点个数的算法
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int count(TreeNode *root) {
    if (!root)
        return 0;
    return 1 + count(root->left) + count(root->right);
}