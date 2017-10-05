void BubbleSort(int arr[], int p, int r)
{
	int i, j;
	for (i = p; i <= r; ++i)
	{
		for (j = p; j < r - i; ++j)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}