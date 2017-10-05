// �㷨���۵ڶ��� P.91
int Randomized_Partition(int arr[], int p, int r)
{
	int i = Random(p, r);
	swap(arr[r], arr[i]);
	return Partition(arr, p, r);
}

void Randomized_QuickSort(int arr[], int p, int r)
{
	if (p < r)
	{
		int q = Randomized_Partition(arr, p, r);
		Randomized_QuickSort(int arr[], int p, int q - 1);
		Randomized_QuickSort(int arr[], int q + 1, int r);
	}
}

int Partition(itn arr[], int p, int r)
{
	int x = arr[r];//���һ��Ԫ��
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(arr[i], arr[j]);//ʹ��arr[i]С�ڵ���arr[r]��arr[j]����arr[r]
		}
	}
	swap(arr[i + 1], arr[r]);//arr[i+1]Ӧ���ڵ���arr[r]������
	return i + 1;
}