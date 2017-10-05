// 算法导论第二版 P.153
class BinarySearchTree
{
private:
	int key;
	BinarySearchTree *left;
	BinarySearchTree *right;
	BinarySearchTree *parent;
};

BinarySearchTree* TreeSearch(BinarySearchTree *x, int k)
{
	if (x == nullptr || k = x->key)
		return x;
	if (k < x->key)
		return TreeSearch(x->left, k);
	else
		return TreeSearch(x->right, k);
}

BinarySearchTree* IterativeTreeSearch(BinarySearchTree *x, int k)
{
	while (x != nullptr && k != x->key)
	{
		if (k < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

BinarySearchTree* TreeMaximum(BinarySearchTree *x)
{
	while (x->right != nullptr)
		x = x->right;
	return x;
}

BinarySearchTree* TreeMinimum(BinarySearchTree *x)
{
	while (x->left != nullptr)
		x = x->left;
	return x;
}

BinarySearchTree* TreeSuccessor(BinarySearchTree *x)
{
	if (x->right != nullptr)
		return TreeMinimum(x->right);

}

BinarySearchTree* TreePredecessor(BinarySearchTree *x)
{
	if (x->left != nullptr)
		return TreeMaximum(x->left);

}