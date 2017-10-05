void SelectionSort(int arr[], int p, int r)
{
	for (int i = p; i < r; ++i)
	{
		int min = i;
		for (int j = i + 1; j < r; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}