#include<stdio.h>

const int n = 4;
int m = 0;
int a[1005][4] = {0};

void scan(int a[][4], int top, int bottom, int left, int right)
{
	//注意top虽然是上面但是数字较小
	if (top > bottom || left > right) return;
	
	for (int i = left; i <= right; i++)	printf("%d ", a[top][i]); //上边从左到右
	for (int i = top + 1; i <= bottom; i++) printf("%d ", a[i][right]); //右边界从上到下
	
	if (bottom > top) //若bottom==top则不用扫下边界了
	{
		for (int i = right - 1; i >= left; i--) printf("%d ", a[bottom][i]);
	}
	if (right > left)
		for (int i = bottom - 1; i > top; i--) printf("%d ", a[i][left]);
	
	scan(a, top + 1, bottom - 1, left + 1, right - 1);
}

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	
	scan(a, 0, m - 1, 0, 3);
	return 0;
}
