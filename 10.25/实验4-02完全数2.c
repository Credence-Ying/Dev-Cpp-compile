#include<stdio.h>
#include<stdbool.h>

bool isperfect(int k)
{
	if (k <= 2) return false;
	
	int sum = 0;
	for (int i = 1; i <= k/2; i++)
	{
		if (k % i == 0) sum += i;
	}
	
	return sum == k;
}

void printperfect(int k)
{
	printf("%d=1", k);
	for (int i = 2; i <= k/2; i++)
	{
		if (k % i == 0) printf("+%d",i);
	}
	putchar('\n');
}

int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		if (isperfect(i)) printperfect(i);
	}
	return 0;
}
