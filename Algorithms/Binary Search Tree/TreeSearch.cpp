// 算法导论第二版 P.153
class BinarySearchTree
{
private:
	int key;
	BinarySearchTree *left;
	BinarySearchTree *right;
};
void TreeSearch(BinarySearchTree *x, int k)
{
	if (x == nullptr || k = x->key)
		return x;
	if (k < x->key)
		return TreeSearch(x->left, k);
	else
		return TreeSearch(x->right, k);
}