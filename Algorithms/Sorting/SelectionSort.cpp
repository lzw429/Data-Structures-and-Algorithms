void SelectionSort(int arr[], int p, int r)
{
	for (int i = p; i < r; ++i)
	{
		int min = i; // i之前的数是有序的
		for (int j = i + 1; j < r; j++)
		{
			if (arr[j] < arr[min]) // 选出无序部分最小的数
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}