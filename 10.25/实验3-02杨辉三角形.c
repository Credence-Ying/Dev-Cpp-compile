#include<stdio.h>

int n;

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < n + 2 * (n - i); j++) putchar(' ');
		
		int c = 1;
		printf("%-4d", c);
		
		for (int j = 1; j <= i; j++)
		{
			c = c * (i - j + 1) / j;
			printf("%-4d", c);
		}
		
		putchar('\n');
	}
	
	return 0;
}
