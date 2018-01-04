// 设计计算二叉树中所有结点值之和的算法
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int sum(TreeNode *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->val;
    return root->val + sum(root->left) + sum(root->right);
}