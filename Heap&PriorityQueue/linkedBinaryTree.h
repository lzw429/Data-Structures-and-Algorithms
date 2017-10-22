
// 由binaryTreeNode构成的链表实现的二叉树
// 派生自抽象类 binaryTree

#ifndef linkedBinaryTree_
#define linkedBinaryTree_

using namespace std;


#include <iostream>
#include "binaryTree.h"
#include "arrayQueue.h"
#include "binaryTreeNode.h"
#include "myExceptions.h"
#include "booster.h"


template<class E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E> >
{
public:
	linkedBinaryTree() { root = NULL; treeSize = 0; }
	~linkedBinaryTree() { erase(); };
	bool empty() const { return treeSize == 0; }
	int size() const { return treeSize; }
	E* rootElement() const;
	void makeTree(const E& element,
		linkedBinaryTree<E>&, linkedBinaryTree<E>&);
	linkedBinaryTree<E>& removeLeftSubtree();
	linkedBinaryTree<E>& removeRightSubtree();
	void preOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit; preOrder(root);
	}
	void inOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit; inOrder(root);
	}
	void postOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit; postOrder(root);
	}
	void levelOrder(void(*)(binaryTreeNode<E> *));
	void preOrderOutput() { preOrder(output); cout << endl; }
	void inOrderOutput() { inOrder(output); cout << endl; }
	void postOrderOutput() { postOrder(output); cout << endl; }
	void levelOrderOutput() { levelOrder(output); cout << endl; }
	void erase()
	{
		postOrder(dispose);
		root = NULL;
		treeSize = 0;
	}
	int height() const { return height(root); }
protected:
	binaryTreeNode<E> *root;                // 指向根结点的指针
	int treeSize;                           // 树中的结点个数
	static void(*visit)(binaryTreeNode<E>*);      // 遍历函数
	static int count;         // 用于计算子树中的结点个数
	static void preOrder(binaryTreeNode<E> *t);
	static void inOrder(binaryTreeNode<E> *t);
	static void postOrder(binaryTreeNode<E> *t);
	static void countNodes(binaryTreeNode<E> *t)
	{
		visit = addToCount;
		count = 0;
		preOrder(t);
	}
	static void dispose(binaryTreeNode<E> *t) { delete t; }
	static void output(binaryTreeNode<E> *t)
	{
		cout << t->element << ' ';
	}
	static void addToCount(binaryTreeNode<E> *t)
	{
		count++;
	}
	static int height(binaryTreeNode<E> *t);
};
// 以下代码应该工作但出现内部编译错误
// template <class E> void (*linkedBinaryTree<E>::visit)(binaryTreeNode<E>*);
// 所以以下明确的声明是用于我们的目的
void(*linkedBinaryTree<int>::visit)(binaryTreeNode<int>*);
void(*linkedBinaryTree<booster>::visit)(binaryTreeNode<booster>*);
void(*linkedBinaryTree<pair<int, int> >::visit)(binaryTreeNode<pair<int, int> >*);
void(*linkedBinaryTree<pair<const int, char> >::visit)(binaryTreeNode<pair<const int, char> >*);
void(*linkedBinaryTree<pair<const int, int> >::visit)(binaryTreeNode<pair<const int, int> >*);

template<class E>
E* linkedBinaryTree<E>::rootElement() const
{
	// 如果无根返回NULL；否则返回指向root的指针
	if (treeSize == 0)
		return NULL;  // 无根
	else
		return &root->element;
}

template<class E>
void linkedBinaryTree<E>::makeTree(const E& element,
	linkedBinaryTree<E>& left, linkedBinaryTree<E>& right)
{
	// 组合left、right和element，形成新的树
	// left、right和该树必须是不同的树
	// 创建组合树
	root = new binaryTreeNode<E>(element, left.root, right.root);
	treeSize = left.treeSize + right.treeSize + 1;

	// 拒绝从left和right访问该树
	left.root = right.root = NULL;
	left.treeSize = right.treeSize = 0;
}

template<class E>
linkedBinaryTree<E>& linkedBinaryTree<E>::removeLeftSubtree()
{
	// 删除并返回左子树
	// 先检查是否为空树
	if (treeSize == 0)
		throw emptyTree();

	// 分离左子树，保存到leftSubtree
	linkedBinaryTree<E> leftSubtree;
	leftSubtree.root = root->leftChild;
	count = 0;
	leftSubtree.treeSize = countNodes(leftSubtree.root);
	root->leftChild = NULL;
	treeSize -= leftSubtree.treeSize;

	return leftSubTree;
}

template<class E>
linkedBinaryTree<E>& linkedBinaryTree<E>::removeRightSubtree()
{
	// 删除并返回右子树
	// 先检查是否为空树
	if (treeSize == 0)
		throw emptyTree();

	// 分离右子树，保存到rightSubtree
	linkedBinaryTree<E> rightSubtree;
	rightSubtree.root = root->rightChild;
	count = 0;
	rightSubtree.treeSize = countNodes(rightSubtree.root);
	root->rightChild = NULL;
	treeSize -= rightSubtree.treeSize;

	return rightSubTree;
}

template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t)
{
	// 前序遍历
	if (t != NULL)
	{
		linkedBinaryTree<E>::visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::inOrder(binaryTreeNode<E> *t)
{
	// 中序遍历
	if (t != NULL)
	{
		inOrder(t->leftChild);
		linkedBinaryTree<E>::visit(t);
		inOrder(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::postOrder(binaryTreeNode<E> *t)
{
	// 后序遍历
	if (t != NULL)
	{
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		linkedBinaryTree<E>::visit(t);
	}
}

template <class E>
void linkedBinaryTree<E>::levelOrder(void(*theVisit)(binaryTreeNode<E> *))
{
	// 层次遍历
	arrayQueue<binaryTreeNode<E>*> q;
	binaryTreeNode<E> *t = root;
	while (t != NULL)
	{
		theVisit(t);  // 访问t

		// 将t的子结点放入队列
		if (t->leftChild != NULL)
			q.push(t->leftChild);
		if (t->rightChild != NULL)
			q.push(t->rightChild);

		// 获得下一个将访问的结点
		try { t = q.front(); }
		catch (queueEmpty) { return; }
		q.pop();
	}
}

template <class E>
int linkedBinaryTree<E>::height(binaryTreeNode<E> *t)
{
	// 返回以t为根的树的高度
	if (t == NULL)
		return 0;                    // 空树，高度为0
	int hl = height(t->leftChild);  // 左子树高度
	int hr = height(t->rightChild); // 右子树高度
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}

#endif
