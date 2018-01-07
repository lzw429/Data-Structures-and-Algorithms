// 统计有两个孩子的结点个数
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int countTwoChildren(TreeNode *root) {
    if (!root)
        return 0;
    if (root->left == nullptr || root->right == nullptr)
        return 0 + countTwoChildren(root->left) + countTwoChildren(root->right);
    if (root->left && root->right)
        return 1 + countTwoChildren(root->left) + countTwoChildren(root->right);
}