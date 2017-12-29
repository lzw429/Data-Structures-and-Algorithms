// 算法导论第三版 P.95
template<class T, class Iterator>
void QuickSort(Iterator first, Iterator last) {
    if (first < last) {
        Iterator mid = Partition(first, last);
        QuickSort(first, mid - 1);
        QuickSort(mid + 1, last);
    }
}

Iterator Partition(Iterator first, Iterator last) {
    T pivot = *last;
    Iterator i = first - 1; // 不要尝试访问*(first-1)
    for (Iterator j = first; j <= last - 1; ++j) {
        if (*j.key <= pivot.key) {
            // 将所有小于等于pivot的元素，交换到大于pivot的元素之前
            i++;
            swap(i, j);
        }
    }
    // 如果*j.key <= pivot.key，i++，交换*i和*j，j++
    // 如果*j.key > pivot.key，j++
    swap(i + 1, last);
    return i + 1;
}

void swap(Iterator i, Iterator j) {
    T tmp = *i;
    *i = *j;
    *j = tmp;
}