#include<stdio.h>
#include<stdbool.h>

int n = 0, m = 0;
char map [505][505]; // 地图：'#'墙 '.'路
bool vis[505][505]; // true = 这个格子"排过队了" 
int qx[255025], qy[255025]; // 队列！不用struct，两个数组分别存x和y
int head = 0, tail = 0;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", map[i] + 1);
	
	qx[tail] = 1;
	qy[tail] = 1;
	tail++;
	vis[1][1] = true;
	
	while(head < tail)
	{
		int x = qx[head];
		int y = qy[head];
		head++;
		
		if (x == n && y == m)
		{
			printf("Yes");
			return 0;
		}
		
		for(int i = 0; i <= 3; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[nx][ny] == '.' && !vis[nx][ny])
			{
				vis[nx][ny] = true;
				qx[tail] = nx;
				qy[tail] = ny;
				tail++;
			}
		}
		
	}
	printf("No");
	return 0;
}
