// 算法导论第二版 P.85
void QuickSort(int arr[], int p, int r)
{
	if (p < r)
	{
		q = Partition(arr, p, r);
		// 分治
		QuickSort(arr, p, q - 1);
		QuickSort(arr, q + 1, r);
	}
}

int Partition(itn arr[], int p, int r)
{
	int x = arr[r];//最后一个元素
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(arr[i], arr[j]);//使得arr[i]小于等于arr[r]，arr[j]大于arr[r]
		}
	}
	swap(arr[i + 1], arr[r]);//arr[i+1]应大于等于arr[r]，交换
	return i + 1;
}