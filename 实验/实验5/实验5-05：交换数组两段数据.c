#include<stdio.h>

#define MAXN 10005

//int *x == x是一个指向int类型的指针 x中存的是一个int变量的地址
void swap_int(int *x, int *y) //定义*x和*y两个指针变量
{
	int t = *x; //运算中*是解指针，解除x指针把它指向的那个值赋给t
	*x = *y;
	*y = t;
}

void reverse(int a[], int l, int r) //把a[l]到a[r]中间段翻转
{
	while (l < r)
	{
		swap_int(&a[l], &a[r]); //把a[l]和a[r]的地址传过去交换
		l++;
		r--;
	}
}

void swap_segment(int a[],int m1, int n1, int m2, int n2)
{
	reverse(a, m1, n1);
	reverse(a, n1 + 1, m2 - 1);
	reverse(a, m2, n2);
	reverse(a, m1, n2);
}

int main()
{
	int n = 0;
	int a[MAXN];
	int m1, n1, m2, n2;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
	
	//A...B...C三次翻转得到Ar...Br...Cr再正题翻转得到结果 Ar指A_reverse
	
	swap_segment(a, m1, n1, m2, n2);
	
	for (int i = 0; i < n; i++)
	{
		if (i == 0) printf("%d", a[i]);
		else printf(" %d", a[i]);
	}
	
	return 0;
}
