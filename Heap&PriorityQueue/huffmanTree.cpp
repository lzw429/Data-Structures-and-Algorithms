// 哈夫曼树

#include <iostream>
#include "minHeap.h"
#include "linkedBinaryTree.h"
#include "huffmanNode.h"

using namespace std;

template <class T>
linkedBinaryTree<int>* huffmanTree(T weight[], int n)
{
	// 创建一组单结点树
	// 以权值[1:n]创建哈夫曼树，n >= 1
	huffmanNode<T> *hNode = new huffmanNode<T>[n + 1];
	linkedBinaryTree<int> emptyTree;
	for (int i = 1; i <= n; i++)
	{
		hNode[i].weight = weight[i];
		hNode[i].tree = new linkedBinaryTree<int>;
		hNode[i].tree->makeTree(i, emptyTree, emptyTree);
	}

	// 使一组单结点树构成最小堆
	minHeap<huffmanNode<T> > heap(1);
	heap.initialize(hNode, n);

	// 不断从最小堆提取两棵树合并，直到剩下一棵树
	huffmanNode<T> w, x, y;
	linkedBinaryTree<int> *z;
	for (i = 1; i < n; i++)
	{
		// 从最小堆中取出权重最小的两棵树
		x = heap.top(); heap.pop();
		y = heap.top(); heap.pop();

		// 合并成一棵树
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
