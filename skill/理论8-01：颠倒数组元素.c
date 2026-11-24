#include<stdio.h>

void swap(int *l, int *r)
{
	int t = 0;
	while(l < r)
	{
		t = *l;
		*l = *r;
		*r = t;
		l++; r--;
	}
}

int main()
{
	int n = 0;
	int x[10005] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	
	swap(&x[1], &x[n]);
	
	for (int i = 1; i <= n; i++)
	{
		if(i < n) printf("%d ", x[i]);
		else printf("%d", x[i]);
	}
	return 0;
}
