// 要求二叉树按二叉链表形式存储，写一个判别给定的二叉树是否为完全二叉树的算法。
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isCompleteBinaryTree(TreeNode *root) {
    if (!root)return true;
    if (!root->left && !root->right)return true;
    bool noChild = false;// 遍历到叶结点将设置为true
    queue <TreeNode> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (noChild) {
            if (cur->left || cur->right)
                return false;
        } else // if(!noChild)
        {
            if (cur->left) {
                q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                else noChild = true;
            } else if (cur->right)
                return false;
            else
                noChild = true;//第一个叶结点
        }
    }
}