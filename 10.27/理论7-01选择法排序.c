#include<stdio.h>
#include<stdbool.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	int a[1005] = {0}, min_idx = 0;
	bool vis[1005] = {0};
	
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i++)
	{
		min_idx = -1;
		
		for (int j = 1; j <= n; j++)
		{
			if(!vis[j] && (min_idx == -1 || a[min_idx] > a[j]))
			{
				min_idx = j;
			}
		}
		
		vis[min_idx] = 1;
		printf("%d ", a[min_idx]);
	}
	
	return 0;
}
