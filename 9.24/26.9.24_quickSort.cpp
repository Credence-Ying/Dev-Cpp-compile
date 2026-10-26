#include<bits/stdc++.h>
using namespace std;

void quickSort(int a[],int left,int right) {
    if (left >= right) return;

    int pivot = a[left];
    int L = left;
    int R = right;
    int hole = left;
    while (L < R) {
        while (L<R && a[R]>=pivot) R--;
        if (L < R) {
            a[hole]=a[R];
            hole=R;
            L++;
        }

        while (L<R && a[L]<=pivot) L++;
        if (L<R) {
            a[hole]=a[L];
            hole=L;
            R--;
        }
    }
    a[hole]=pivot;

    quickSort(a,left,hole-1);
    quickSort(a,hole+1,right);
}


int main () {
    int n=0,a[1005]={0};
    cin>>n;
    for (int i = 0; i <= n-1; i++) cin>>a[i];
    quickSort(a,0,n-1);
    for (int i = 0; i <= n-1; i++) cout<<a[i]<<" ";
    return 0;
}