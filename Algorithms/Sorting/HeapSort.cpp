#include<iostream>
#include<algorithm>
using namespace std;

void max_heap(int arr[], int start, int end)
{
	int dad = start;//��0��ʼ
	int son = dad * 2 + 1;//dad->left
	while (son <= end)
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])//ѡ�������ӽ���и����
			son++;
		if (arr[dad] > arr[son])//������������ӽ�㣬�����ٵ���
			return;
		else//���򽻻����ӽ�����ݣ��ټ����ӽ�������Ƚ�
		{
			swap[arr[dad], arr[son]];
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len)
{
	//��ʼ���������һ������㿪ʼ����
	for (int i = len / 2 - 1; i >= 0; --i)
	{
		max_heap(arr, i, len - 1);
	}//��֤ÿ����㶼�����ӽ���
	//�Ƚ���һ��Ԫ�غ����źõ�Ԫ��ǰһλ�����������µ���
	for (int i = len - 1; i > 0; --i)
	{
		swap(arr[0], arr[i]);
		max_heap(arr, 0, i - 1);
	}
}