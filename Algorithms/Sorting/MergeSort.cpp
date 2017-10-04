#include<cstdio>
#define N 100000
int array[N], temp[N];
void merge(int A[], int left, int mid, int right, int temp[]);
void mergesort(int A[], int left, int right, int temp[]);

int main()
{
	int len;
	int m;//temp int
	scanf("%d", &len);
	for (m = 1; m <= len; m++)
		scanf("%d", &array[m]);
	mergesort(array, 1, len, temp);
	for (m = 1; m <= len; m++)
		printf("%d ", array[m]);
	return 0;
}

void merge(int A[], int left, int mid, int right, int temp[])
{
	//将 A[left...mid] 和 A[mid...right] 按序合并到 A[left...right]
	int i = left, j = mid + 1, t = left;//i指向数组左半部分，j指向数组右半部分
	while (t <= right)
	{
		if ((i <= mid) && ((j > right) || (A[i] <= A[j])))
			temp[t++] = A[i++];
		else
			temp[t++] = A[j++];
	}
	for (i = 1; i <= right; i++)//将合并后的temp[]复制回A[]
		A[i] = temp[i];
}

void mergesort(int A[], int left, int right, int temp[])
{
	if (left < right)//该条件不可缺少
	{
		int mid = (left + right) / 2;
		mergesort(A, left, mid, temp);//左子序列递归
		mergesort(A, mid + 1, right, temp);//右子序列递归
		merge(A, left, mid, right, temp);//排序
	}
}