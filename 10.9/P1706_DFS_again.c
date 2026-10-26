#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int n;
int a[15];
bool used[15]={0};

void dfs(int k)
{
	if (k > n)
	{
		for (int i = 1; i <= n; i++) printf("%5d", a[i]);
		printf("\n");
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			a[k] = i;
			dfs(k+1);
			used[i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}