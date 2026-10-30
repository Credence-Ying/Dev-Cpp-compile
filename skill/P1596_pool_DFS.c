#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int N,M;
char a[105][105];
bool visited[105][105] = {0};
int cnt = 0;
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1}; // usually used in questions of map
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0}; // eight directions are needed

bool inMap(int x,int y)
{
	if (x >= 0 && x < N && y >= 0 && y < M) return 1; // one should be noted is: x->N y->M; DO NOT MIX THEM; N->rows M->lists
	else return 0;
}

void dfs(int x,int y)
{
	visited[x][y] = 1; //tag the place we've arrived.
	for (int i = 0; i <= 7; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (inMap(tx,ty) == 1 && a[tx][ty] == 'W' && visited[tx][ty] == 0) dfs(tx,ty);
		// we just need the cnt so no backtracking operation is required
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", a[i]);
	for (int i = 0; i < N; i++) // scan through all the statistics
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 'W' && visited[i][j] == 0) // the decection of 'W' is concluded in the main function
			{
				cnt++;
				dfs(i,j); // dfs every new 'W'
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
