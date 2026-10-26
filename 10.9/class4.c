#include<stdio.h>

int n;

int isPerfect(int k)
{
	int sum = 0;
	for (int i = 1; i <= k/2; i++)
	{
		if(k % i == 0) sum += i;
	}
	if (sum == k) return 1;
	else return 0;
	
}

int main()
{
	scanf("%d", &n);
	printf("%d内的完数有:", n);
	for (int i = 1; i <= n; i++)
	{
		if(isPerfect(i) == 1) printf("%d ", i);
	}
	return 0;
}
