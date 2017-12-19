// 算法导论第三版 P.95
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

int Partition(int arr[], int p, int r)
{
	int pivot = arr[r];//pivot是最后一个元素
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)// 遍历arr，将所有小于等于pivot的元素交换到大于pivot的元素之前
	{
		if (arr[j] <= pivot)
		{
			i++; // 保证arr[i]是已知的最后一个小于等于pivot的元素
			swap(arr[i], arr[j]);
		}
	}// 如果 arr[j] <= pivot, i++, 交换arr[i]和arr[j], j++
	 // 如果 arr[j] > pivot, j++
	swap(arr[i + 1], arr[r]);//arr[i+1]应大于等于arr[r]，交换
	return i + 1;
}