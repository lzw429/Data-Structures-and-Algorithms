// 算法导论第二版 P.153
class BinarySearchTree
{
private:
	int key;
	BinarySearchTree *left;
	BinarySearchTree *right;
	BinarySearchTree *parent;
};

BinarySearchTree* TreeSearch(BinarySearchTree *x, int k);
BinarySearchTree* IterativeTreeSearch(BinarySearchTree *x, int k);
BinarySearchTree* TreeMaximum(BinarySearchTree *x);
BinarySearchTree* TreeMinimum(BinarySearchTree *x);
BinarySearchTree* TreeSuccessor(BinarySearchTree *x);
BinarySearchTree* TreePredecessor(BinarySearchTree *x);
void TreeInsert(BinarySearchTree *T, BinarySearchTree *z);


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
	BinarySearchTree *y = x->parent;
	while (y != nullptr && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

BinarySearchTree* TreePredecessor(BinarySearchTree *x)
{
	if (x->left != nullptr)
		return TreeMaximum(x->left);
	while (y != nullptr && x == y->left)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

void TreeInsert(BinarySearchTree *T, BinarySearchTree *z)
{
	BinarySearchTree *y = nullptr;// 定位z的父结点
	BinarySearchTree *x = T;// root
	while (x != nullptr)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == nullptr)
		T = z;// Tree T was empty.
	else
	{
		if (z->key < y->key)
			y->left = z;
		else y->right = z;
	}
}

void TreeDelete(BinarySearchTree *T, BinarySearchTree *z)
{
	BinarySearchTree *y;
	if (z->left == nullptr || z->right == nullptr)
		y = z;
	else // 若z有子结点，要将它的子结点过继给其他结点
		y = TreeSuccessor(z);
	if (y->left != nullptr)
	{
		
	}
}