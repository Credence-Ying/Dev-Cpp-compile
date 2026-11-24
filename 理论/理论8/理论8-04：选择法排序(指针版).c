#include<stdio.h>

#define MAXN 10005

void selectionsort(int *a, int n)
{
	for (int *p = a; p < a + n - 1; p++)
	{
		int *minp = p;
		
		for (int *q = p + 1; q < a + n; q++)
		{
			if(*minp > *q) minp = q;
		}
		
		if(minp != p)
		{
			int t = *p;
			*p = *minp;
			*minp = t;
		}
	}
}

int main()
{
	int n = 0;
	int a[MAXN] = {0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]); //涉及到指针的用a[0]开始是好习惯
	
	selectionsort(a ,n);
	
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}
