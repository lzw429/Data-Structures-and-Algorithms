#include<iostream>
#include<algorithm>
using namespace std;

void max_heap(int arr[], int start, int end)
{
	int dad = start;//从0开始
	int son = dad * 2 + 1;//dad->left
	while (son <= end)
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])//选择两个子结点中更大的
			son++;
		if (arr[dad] > arr[son])//如果父结点大于子结点，不必再调整
			return;
		else//否则交换父子结点内容，再继续子结点和孙结点比较
		{
			swap[arr[dad], arr[son]];
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len)
{
	//初始化，从最后一个父结点开始调整
	for (int i = len / 2 - 1; i >= 0; --i)
	{
		max_heap(arr, i, len - 1);
	}//保证每个结点都比其子结点大
	//先将第一个元素和已排好的元素前一位交换，再重新调整
	for (int i = len - 1; i > 0; --i)
	{
		swap(arr[0], arr[i]);
		max_heap(arr, 0, i - 1);
	}
}