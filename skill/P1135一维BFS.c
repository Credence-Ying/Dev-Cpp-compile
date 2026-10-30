#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//这里有exit函数可以直接退出程序

int n = 0, a = 0, b = 0;
int k[205] = {0};
int cnt[205] = {0};
bool vis[205] = {0};
int head = 0, tail = 0;
int qx[205];

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
	
	qx[tail] = a;
	vis[a] = 1;
	tail++;
	
	while (head < tail)
	{
		int cx = qx[head++];
		
		if (cx == b)
		{
			printf("%d", cnt[cx]);
			return 0;
		}
		
		int n1 = cx + k[cx], n2 = cx - k[cx];
		if (n1 <= n && !vis[n1])
		{
			vis[n1] = 1;
			qx[tail++] = cx + k[cx];
			cnt[n1] = cnt[cx] + 1;
		}
		
		if (n2 >= 1 && !vis[n2])
		{
			vis[n2] = 1;
			qx[tail++] = cx - k[cx];
			cnt[n2] = cnt[cx] + 1;
		}
	}
	
	printf("-1");
	return 0;
}
