// �㷨���۵ڶ��� P.152
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