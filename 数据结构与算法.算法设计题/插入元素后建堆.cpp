// 设关键字序列(k1，k2，…，kn-1)是堆，设计算法将关键字序列(k1，k2，…，kn-1，x)调整为堆。
void adjustheap(int r[], int n) {
    // 小根堆，n是插入x后堆的元素个数
    int j = n, i = j / 2, temp = r[j - 1];// 第j个元素是r[j-1]
    while (i >= 1) {
        if (r[i - 1] <= temp)
            break;// 已满足堆的要求
        else {
            r[j - 1] = r[i - 1];
            j = i;
            i = i / 2;
        }
    }
    r[j - 1] = temp;
}
