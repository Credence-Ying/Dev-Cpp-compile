#include<stdio.h>

int n, m;
int mini, maxi;

int main()
{
	scanf("%d%d", &n, &m);
	int small = (n > m) ? m : n;
	for (int i = small; i >= 1; i--)
	{
		if (n % i == 0 && m % i == 0)
		{
			mini = i;
			break;
		}
	}
	
	maxi = n * m / mini;
	
	printf("%d %d", mini, maxi);
	return 0;
}
