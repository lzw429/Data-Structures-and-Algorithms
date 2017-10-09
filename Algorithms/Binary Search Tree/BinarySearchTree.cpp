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

void Transplant(BinarySearchTree *T, BinarySearchTree *u, BinarySearchTree *v)//用一棵以v为根的子树替换一棵以u为根的子树，结点u的父结点变为结点v的父结点
{
	if (u->parent == nullptr)
		T = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else u->parent->right = v;
	if (v != nullptr)
		v->parent = u->parent;
}

void TreeDelete(BinarySearchTree *T, BinarySearchTree *z)
{
	if (z->left == nullptr)
		Transplant(T, z, z->right);
	else if (z->right = nullptr)
		Transplant(T, z, z->left);
	else
	{
		BinarySearchTree *y = TreeMinimum(z->right);//将使y代替z
		if (y->parent != z)
		{
			Transplant(T, y, y->right);//y将离开原位
			y->right = z->right;//y继承z的右子结点
			y->right->parent = y;//使右子结点认识新的父结点
		}
		Transplant(T, z, y);
		y->left = z->left;//y继承z的左子结点
		y->left->parent->y;//使左子结点认识新的父结点
	}
}