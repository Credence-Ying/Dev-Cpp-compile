#include<stdio.h>

int n,m;
int a[5];

int main()
{
	scanf("%d", &n);
	m = n;
	if(n<100 || n >= 1000) printf("%d不是三位数", n);
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			a[i] = n % 10;
			n /= 10;
		}
		if(m == a[1] + a[2]*a[2]*a[2] + a[3]*a[3]*a[3]) printf("%d是水仙花数变种", m);
		else printf("%d不是水仙花数变种", m);
	}
	return 0;
}
