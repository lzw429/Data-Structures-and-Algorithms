// �㷨���۵ڶ��� P.85
void QuickSort(int arr[], int p, int r)
{
	if (p < r)
	{
		q = Partition(arr, p, r);
		// ����
		QuickSort(arr, p, q - 1);
		QuickSort(arr, q + 1, r);
	}
}

int Partition(int arr[], int p, int r)
{
	int x = arr[r];//x�����һ��Ԫ�أ���Ϊ��׼pivot
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)// ����arr
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