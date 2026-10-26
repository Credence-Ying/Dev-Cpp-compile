#include <stdio.h>

void quickSort(int a[], int left, int right) {
    if (left >= right) return; //左指针超过右指针时停止
    int pivot = a[left]; //第一个数拿出来作判断标准
    int L = left; //左指针
    int R = right; //右指针
    int hole = left; //坑的初始位置是最左侧
    while (L < R) {
    	
        while (L < R && a[R] >= pivot) R--;
        if (L < R) {
            a[hole] = a[R];
            hole = R;
            L++;
        }
        
        while (L < R && a[L] <= pivot) L++;
        if (L < R) {
            a[hole] = a[L];
            hole = L;
            R--;
        }
        
    }
    a[hole] = pivot;
    quickSort(a, left, hole - 1);
    quickSort(a, hole + 1, right); //递归
}

int main() {
    int a[100005]={0};
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    quickSort(a, 0, n - 1);
    
    printf("Result:");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
