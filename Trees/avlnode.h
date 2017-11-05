

#ifndef AVLNode_
#define AVLNode_

template <class E, class K> class AVLtree;
template <class E, class K> class DAVLtree;

template <class E, class K>
class AVLNode {
	friend AVLtree<E, K>;
	friend DAVLtree<E, K>;
public:
	AVLNode() { LeftChild = RightChild = 0; }//构造方法
	AVLNode(const E& e)
	{
		data = e; bf = 0; LeftChild = RightChild = 0;
	}
private:
	E data;
	int bf;                   // 平衡因子balance factor
	AVLNode<E, K> *LeftChild,  // 左子树
		*RightChild; // 右子树
};

#endif
