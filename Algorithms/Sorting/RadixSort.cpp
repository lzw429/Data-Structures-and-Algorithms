// 算法导论第二版 P.101
int maxbit(int arr[], int n)//辅助函数，求数据的最大位数，n是数组大小
{
	int max = arr[0];
	//先找出最大数，再求其位数
	for (int i = 1; i < n; ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}
	int d = 1;
	while (max >= 10)
	{
		max /= 10;
		++d;
	}
	return d;
}

void RadixSort(int arr[], int n)
{
	int d = maxbit(arr[], n); //d是数字最高位数
	int *tmp = new int[n];//临时存储排序结果
	int *count = new int[10];//计数器
	int i, j, k;
	int radix = 1;
	for (int i; i <= d; i++)//进行d次排序
	{
		//计数排序
		for (j = 0; j < 10; j++)
			count[j] = 0;//每次分配前清空计数器
		for (j = 0; j < n; j++)
		{
			k = (arr[j] / radix) % 10;
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] += count[j - 1];
		for (j = n - 1; j >= 0; j--)
		{
			k = (arr[j] / radix) % 10;
			tmp[count[k] - 1] = arr[j];
			count[k]--;
		}
		for (j = 0; j < n; j++)
			arr[j] = tmp[j];
		radix *= 10;
	}
	delete[]tmp;
	delete[]count;
}