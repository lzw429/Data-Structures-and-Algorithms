void BubbleSort(int arr[], int p, int r) {
    int i, j;
    bool sorted = true;
    for (i = p; i < r; ++i) {
        sorted = true;
        for (j = p; j < p + r - i - 1; ++j) //内层循环每次使最大数移到后面
        {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        }
        if (sorted)
            return;
    }
}