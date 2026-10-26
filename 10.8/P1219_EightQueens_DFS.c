#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

int n;
int ans[15];      // ans[x] = y -> the queen is on (x,y)
bool col[15];     // set the queen row by row so we only have to tag the column(col)
bool diag1[30];   // the same (x+y) is on the same diagonal1 row
bool diag2[30];   // the same (x-y+n) is on the same diagonal2 row
int cnt = 0;      // the number of the answers这里能够显示中文

void dfs(int k)
{
	if (k > n)
	{
		cnt++;
		if(cnt <= 3){
			for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
			printf("\n");
		}
		return;
	}
	for (int i = 1; i <= n; i++) //row1 1->n
	{
		if (col[i] == 0 && diag1[k + i] == 0 && diag2[k - i + n] == 0)
		{
			ans[k] = i; // set the queen(k,i)
			col[i] = 1; // tag the column
			diag1[k + i] = 1;
			diag2[k - i + n] = 1; // tag the two diagonal rows
			
			dfs(k+1);
			
			col[i] = 0; 
			diag1[k + i] = 0;
			diag2[k - i + n] = 0; // the backtracking operation (cause we need to go through every case)
		}
	}
}

int main(){
	scanf("%d", &n);
	dfs(1);
	printf("%d", cnt);
	return 0;
}