// �㷨���۵����� P.95
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
	int pivot = arr[r];//pivot�����һ��Ԫ��
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)// ����arr��������С�ڵ���pivot��Ԫ�ؽ���������pivot��Ԫ��֮ǰ
	{
		if (arr[j] <= pivot)
		{
			i++; // ��֤arr[i]����֪�����һ��С�ڵ���pivot��Ԫ��
			swap(arr[i], arr[j]);
		}
	}// ��� arr[j] <= pivot, i++, ����arr[i]��arr[j], j++
	 // ��� arr[j] > pivot, j++
	swap(arr[i + 1], arr[r]);//arr[i+1]Ӧ���ڵ���arr[r]������
	return i + 1;
}