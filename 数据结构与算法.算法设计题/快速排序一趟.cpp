// 设有一组初始记录关键字序列K1到Kn，要求设计一个算法能在O(n)的时间复杂度内将线性表分为两部分，其中左半部分的每个关键字均小于K1，右半部分的每个关键字均大于K1
void quick_sort(int a[], int start, int end) {
    int pivot = a[start];
    int i = start, j;
    for (j = start + 1; j <= end - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a, i, j);
        }
        swap(a, i + 1, start);
    }
}

void swap(int &a[], int i, int j) {
    int t = a[j];
    a[j] = a[i];
    a[i] = t;
}