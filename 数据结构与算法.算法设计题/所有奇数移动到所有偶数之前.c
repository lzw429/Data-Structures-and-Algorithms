// 设计将所有奇数移到所有偶数之前的算法
void oddBeforeEven(int arr[]) {
    int i = -1, j;
    for (j = 0; j < len; j++) {
        if (arr[j] % 2 == 1) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
}