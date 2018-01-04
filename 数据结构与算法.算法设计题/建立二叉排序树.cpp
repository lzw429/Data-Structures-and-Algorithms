// 在链式存储结构上建立一棵二叉排序树
#define LEN 100
struct bitree {
    bitree *left;
    bitree *right;
    int val;
};

void insertBST(bitree *&root, int val) //注意是对指针的引用
{
    if (root == nullptr) // 树为空
    {
        root = (bitree *) malloc(sizeof(bitree));
        root->val = val;
        root->left = root->right = nullptr;
    } else if (root->val > val) // 新结点必然插入到BST的叶结点
        insertBST(root->left, val);
    else
        insertBST(root->right, val);
}

void createBST(bitree *&root) {
    for (int i = 0; i < LEN; i++)
        insertBST(root, rand());
}