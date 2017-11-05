
#ifndef IAVLNode_
#define IAVLNode_

template <class E, class K> class IndexedAVLtree;
template <class E, class K> class IndexedDAVLtree;
template <class T> class IndexedAVLList;

template <class E, class K>
class IAVLNode {
	friend IndexedAVLtree<E, K>;
	friend IndexedDAVLtree<E, K>;
	friend IndexedAVLList<E>;
public:
	IAVLNode() { LeftChild = RightChild = 0; }
	IAVLNode(const E& e)
	{
		data = e; bf = 0;
		LeftSize = 1;
		LeftChild = RightChild = 0;
	}
private:
	E data;
	int bf;                    // 平衡因子
	int LeftSize;              // 左子树大小
							   // 加1
	IAVLNode<E, K> *LeftChild,  // 左子树
		*RightChild; // 右子树
};

#endif
