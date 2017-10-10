#include<cstdio>

void Hanoi(int n, char A, char B, char C) {
    if (n > 1)
        Hanoi(n - 1, A, C, B);//上面n-1层从A移到B
    printf("Move %d disc from %c to %c\n", n, A, C);//最后一层A移到C
    if (n > 1)
        Hanoi(n - 1, B, A, C);//上面n-1层从B移到C
}

int main() {
    int n;
    freopen("date.out", "w", stdout);
    scanf("%d", &n);
    Hanoi(n, 'A', 'B', 'C');//将A通过B移到C.
    return 0;
}