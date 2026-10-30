#include<stdio.h>
#include<stdbool.h>

int n;
char map[35][35];
int head = 0, tail = 0;
int qx[1200], qy[1200];
bool vis[35][35] = {0};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

//思路：从边界的0向内扩散，扩不到的就是被包起来的

void push(int x, int y) //后续用到数次入队操作，干脆直接定义为函数
{
	if (vis[x][y]) return; //看过了就不入队了
	vis[x][y] = 1;
	qx[tail] = x;
	qy[tail] = y;
	tail++;
}

int main(void)
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n ; j++) scanf(" %c", &map[i][j]); //" %c"前导空格跳过空格和换行很重要
	
	//四条边界上所有的0都要作为BFS的起点，此处的初始化跟单点初始化不一样
	for (int i = 1; i <= n; i++)
	{
		if (map[1][i] == '0') push(1, i); //上
		if (map[n][i] == '0') push(n, i); //下
		if (map[i][1] == '0') push(i, 1); //左
		if (map[i][n] == '0') push(i, n); //右
	}
	
	while(head < tail)
	{
		int cx = qx[head]; //取队首操作
		int cy = qy[head];
		head++;
		
		for (int i = 0; i <= 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 1 || nx > n || ny < 1 || ny > n) continue; //continue跳出本次循环开始下一次,break则会结束整个循环
			if(vis[nx][ny]) continue;
			if(map[nx][ny] == '1') continue;
			push(nx, ny);
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n ;j++)
		{
			if (map[i][j] == '0' && !vis[i][j]) putchar('2');
			else putchar(map[i][j]);
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
