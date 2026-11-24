#include<stdio.h>
#include<stdlib.h>

void rotate90(int *a, int *b, int n, int m)
{
	//要给b赋值所以按照b的m行n列读
	//b的第r行c列 == a的第m-1-r列c行
	for (int r = 0; r < m; r++)
		for (int c = 0; c < n; c++)
			*(b + r * n + c) = *(a + c * m + m - 1 - r);
}

int main()
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	
	//要能够处理任意大小的矩阵，申请动态存储
	int *a = (int *)malloc(n * m * sizeof(int));
	int *b = (int *)malloc(n * m * sizeof(int));
	if (a == NULL || b == NULL) return 1;
	
	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
			scanf("%d", a + m * r + c); //输入到这个内存对应的地方来
			
	rotate90(a, b, n, m);
	
	for (int r = 0; r < m; r++)
		for (int c = 0; c < n; c++)
			printf("%d%c", *(b + n * r + c), (c == n - 1) ? '\n' : ' ');
	
	free(a);
	free(b);
	return 0;
}
