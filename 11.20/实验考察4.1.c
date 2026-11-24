#include<stdio.h>

int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	int a[n+5];
	a[1] = 1, a[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		a[i] = a[i-1] + a[i-2];
	}
	for (int i = 1; i <= n; i++) cnt += (i % 2 == 1) ? a[i] : -a[i];
	printf("%d", cnt);
	return 0;
}
