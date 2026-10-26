#include<stdio.h>

int n = 0;
int square[105];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i * i <= n; i++) square[i] = i * i;
	
	for (int k = 1; k * k <= n; k++)
	{
		for (int i = 1; i * i <= n; i++)
		{
			for (int j = 1; j * j <= n; j++)
			{
				if (square[k] == i * i * 10 + j * j) printf("%d ", square[k]);
			}
		}
	}
	return 0;
}
