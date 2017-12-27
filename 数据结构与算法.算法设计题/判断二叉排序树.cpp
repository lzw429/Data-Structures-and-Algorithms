// 设计判断二叉树是否为二叉排序树的算法
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isBST(TreeNode *root) {
    return isBST(root, nullptr, nullptr);
}

bool isBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
    if (root == nullptr)
        return true;
    if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        // BST不允许相等
        return false;
    return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
}