// 算法导论第二版 P.99
// A是被排序数组，B用于存放排序结果，C提供临时存储区

void CountingSort(int A[], int B[], int k)//k是A[]中最大的数
{
	int Asize = sizeof(A) / sizeof(A[0]);
	int C[k + 10];
	for (int i = 0; i <= k; ++i)
		C[i] = 0;
	for (int j = 0; j <= Asize; ++j)
		C[A[j]]++;
	//C[i]包含等于i的元素个数
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
