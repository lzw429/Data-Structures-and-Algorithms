// 设计在顺序有序表中实现二分查找的算法
struct record {
    int key;
    int others;
};

int BinarySearch(record arr[], int target)// 返回arr索引
{
    int n;//arr元素个数
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid].key == k)
            return mid;
        else if (arr[mid].key > k)
            high = mid - 1;
        else low = mid + 1;
    }
    return -1;//未找到
}