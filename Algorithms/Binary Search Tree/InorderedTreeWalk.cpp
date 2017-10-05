// 算法导论第二版 P.152
class BinarySearchTree
{
private:
	int key;
	BinarySearchTree *left;
	BinarySearchTree *right;
	BinarySearchTree *parent;
};

void InorderedTreeWalk(BinarySearchTree *x)
{
	if (x != nullptr)
	{
		InorderedTreeWalk(x->left);
		cout << x->key;
		InorderedTreeWalk(x->right);
	}
}