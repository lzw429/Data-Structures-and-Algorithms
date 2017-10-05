// 算法导论第二版 P.10

void InsertionSort(int arr[], int p, int r)
{
	int key;
	for (int j = 1; j <= r; ++j)
	{
		key = arr[j];
		//将arr[j]插入到已排序的arr[0...j-1]
		int i = j - 1;//j之前已排好序
		while (i >= p && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}
}
