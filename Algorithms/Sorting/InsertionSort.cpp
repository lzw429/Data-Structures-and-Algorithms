// �㷨���۵ڶ��� P.10

void InsertionSort(int arr[], int p, int r)
{
	int key;
	for (int j = 1; j <= r; ++j)
	{
		key = arr[j];
		//��arr[j]���뵽�������arr[0...j-1]
		int i = j - 1;//j֮ǰ���ź���
		while (i >= p && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}
}
