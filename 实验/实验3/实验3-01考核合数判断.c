#include<stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	for (int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			printf("%d是合数", n);
			return 0;
		}
	}
	printf("%d不是合数", n);
	return 0;
}
