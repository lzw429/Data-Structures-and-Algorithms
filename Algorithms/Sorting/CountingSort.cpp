// �㷨���۵ڶ��� P.99
// A�Ǳ��������飬B���ڴ����������C�ṩ��ʱ�洢��

void CountingSort(int A[], int B[], int k)//k��A[]��������
{
	int Asize = sizeof(A) / sizeof(A[0]);
	int C[k + 10];
	for (int i = 0; i <= k; ++i)
		C[i] = 0;
	for (int j = 0; j <= Asize; ++j)
		C[A[j]]++;
	//C[i]��������i��Ԫ�ظ���
	for (i = 1; i <= k; ++i)
	{
		C[i] += C[i - 1];
	}
	for (int j = Asize; j >= 1; --j)
	{
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}
