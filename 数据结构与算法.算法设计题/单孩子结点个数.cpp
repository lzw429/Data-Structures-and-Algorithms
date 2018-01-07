// 统计有单个孩子的结点个数
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int countSingleChild(TreeNode *root) {
    if (!root)
        return 0;
    if (root->left && !root->right || !root->left && root->right)
        return 1 + countSingleChild(root->left) + countSingleChild(root->right);
    if (root->left && root->right)
        return 0 + countSingleChild(root->left) + countSingleChild(root->right);
}