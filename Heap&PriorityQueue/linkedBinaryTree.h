
// ��binaryTreeNode���ɵ�����ʵ�ֵĶ�����
// �����Գ����� binaryTree

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
	binaryTreeNode<E> *root;                // ָ�������ָ��
	int treeSize;                           // ���еĽ�����
	static void(*visit)(binaryTreeNode<E>*);      // ��������
	static int count;         // ���ڼ��������еĽ�����
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
// ���´���Ӧ�ù����������ڲ��������
// template <class E> void (*linkedBinaryTree<E>::visit)(binaryTreeNode<E>*);
// ����������ȷ���������������ǵ�Ŀ��
void(*linkedBinaryTree<int>::visit)(binaryTreeNode<int>*);
void(*linkedBinaryTree<booster>::visit)(binaryTreeNode<booster>*);
void(*linkedBinaryTree<pair<int, int> >::visit)(binaryTreeNode<pair<int, int> >*);
void(*linkedBinaryTree<pair<const int, char> >::visit)(binaryTreeNode<pair<const int, char> >*);
void(*linkedBinaryTree<pair<const int, int> >::visit)(binaryTreeNode<pair<const int, int> >*);

template<class E>
E* linkedBinaryTree<E>::rootElement() const
{
	// ����޸�����NULL�����򷵻�ָ��root��ָ��
	if (treeSize == 0)
		return NULL;  // �޸�
	else
		return &root->element;
}

template<class E>
void linkedBinaryTree<E>::makeTree(const E& element,
	linkedBinaryTree<E>& left, linkedBinaryTree<E>& right)
{
	// ���left��right��element���γ��µ���
	// left��right�͸��������ǲ�ͬ����
	// ���������
	root = new binaryTreeNode<E>(element, left.root, right.root);
	treeSize = left.treeSize + right.treeSize + 1;

	// �ܾ���left��right���ʸ���
	left.root = right.root = NULL;
	left.treeSize = right.treeSize = 0;
}

template<class E>
linkedBinaryTree<E>& linkedBinaryTree<E>::removeLeftSubtree()
{
	// ɾ��������������
	// �ȼ���Ƿ�Ϊ����
	if (treeSize == 0)
		throw emptyTree();

	// ���������������浽leftSubtree
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
	// ɾ��������������
	// �ȼ���Ƿ�Ϊ����
	if (treeSize == 0)
		throw emptyTree();

	// ���������������浽rightSubtree
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
	// ǰ�����
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
	// �������
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
	// �������
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
	// ��α���
	arrayQueue<binaryTreeNode<E>*> q;
	binaryTreeNode<E> *t = root;
	while (t != NULL)
	{
		theVisit(t);  // ����t

		// ��t���ӽ��������
		if (t->leftChild != NULL)
			q.push(t->leftChild);
		if (t->rightChild != NULL)
			q.push(t->rightChild);

		// �����һ�������ʵĽ��
		try { t = q.front(); }
		catch (queueEmpty) { return; }
		q.pop();
	}
}

template <class E>
int linkedBinaryTree<E>::height(binaryTreeNode<E> *t)
{
	// ������tΪ�������ĸ߶�
	if (t == NULL)
		return 0;                    // �������߶�Ϊ0
	int hl = height(t->leftChild);  // �������߶�
	int hr = height(t->rightChild); // �������߶�
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}

#endif
