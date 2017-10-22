// ��������

#include <iostream>
#include "minHeap.h"
#include "linkedBinaryTree.h"
#include "huffmanNode.h"

using namespace std;

template <class T>
linkedBinaryTree<int>* huffmanTree(T weight[], int n)
{
	// ����һ�鵥�����
	// ��Ȩֵ[1:n]��������������n >= 1
	huffmanNode<T> *hNode = new huffmanNode<T>[n + 1];
	linkedBinaryTree<int> emptyTree;
	for (int i = 1; i <= n; i++)
	{
		hNode[i].weight = weight[i];
		hNode[i].tree = new linkedBinaryTree<int>;
		hNode[i].tree->makeTree(i, emptyTree, emptyTree);
	}

	// ʹһ�鵥�����������С��
	minHeap<huffmanNode<T> > heap(1);
	heap.initialize(hNode, n);

	// ���ϴ���С����ȡ�������ϲ���ֱ��ʣ��һ����
	huffmanNode<T> w, x, y;
	linkedBinaryTree<int> *z;
	for (i = 1; i < n; i++)
	{
		// ����С����ȡ��Ȩ����С��������
		x = heap.top(); heap.pop();
		y = heap.top(); heap.pop();

		// �ϲ���һ����
		z = new linkedBinaryTree<int>;
		z->makeTree(0, *x.tree, *y.tree);
		w.weight = x.weight + y.weight;
		w.tree = z;
		heap.push(w);
		delete x.tree;
		delete y.tree;
	}

	return heap.top().tree;
}

int main(void)
{
	int a[11];
	int n = 10;
	for (int i = 1; i <= n; i++)
		a[i] = 2 * i;
	linkedBinaryTree<int> *x = huffmanTree(a, n);
	x->postOrderOutput();
	return 0;
}
