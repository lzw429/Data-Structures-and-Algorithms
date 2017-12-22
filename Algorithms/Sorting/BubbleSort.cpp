void BubbleSort(int arr[], int p, int r) {
    int i, j;
    bool sorted = false;
    for (i = p; i < r; ++i) {
        for (j = p; j < p + r - i; ++j) //内层循环每次使最大数移到后面
        {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                sorted = true;
            }
        }
        if (sorted)
            return;
    }
}