#include<stdio.h>
#include<stdbool.h>

int n, m;
int x, y;
int head = 0, tail = 0;
int qx[160005], qy[160005]; //400*400至少要开160000格子
int ans[405][405] = {0};
bool vis[405][405] = {0};

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);
	
	qx[tail] = x;
	qy[tail] = y;
	tail++;
	vis[x][y] = 1;
	ans[x][y] = 0;
	
	while(head < tail)
	{
		int cx = qx[head]; //取队首来操作
		int cy = qy[head];
		head++; //队首往后挪一位
		
		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(nx >= 1 && nx <=n && ny >= 1 && ny <=m && !vis[nx][ny])
			{
				qx[tail] = nx;
				qy[tail] = ny;
				vis[nx][ny] = 1;
				ans[nx][ny] = ans[cx][cy] + 1;
				tail++;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (vis[i][j] == 0) ans[i][j] = -1;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d ", ans[i][j]);
		}
		putchar('\n');
	}
	
	return 0;
}
