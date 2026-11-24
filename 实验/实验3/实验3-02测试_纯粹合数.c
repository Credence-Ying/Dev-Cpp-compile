#include<stdio.h>
#include<stdbool.h>

bool judge(int k)
{
	if(k == 2) return false;
	for (int i = 2; i * i <= k; i++)
	{
		if (k % i == 0) return true;
	}
	return false;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ans = n;
	
	while(n > 1)
	{
		if(!judge(n))
		{
			printf("%d不是纯粹合数", ans);
			return 0;
		}
		n /= 10;
	}
	printf("%d是纯粹合数", ans);
	return 0;
}
