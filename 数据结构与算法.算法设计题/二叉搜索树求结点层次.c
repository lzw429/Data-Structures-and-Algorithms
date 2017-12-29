// 设计求结点在二叉搜索树中层次的算法。
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int layer(TreeNode *root, int val) {
    // 根结点算作第1层
    int res = 0;
    if (root != nullptr) {
        res++;
        if (root->key == val)
            return res;
        else if (root->key > val)
            return res + layer(root->left, val);
        else
            return res + layer(root->right, val);
    }
    return res;
}