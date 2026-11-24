#include<stdio.h>

//二维数组在内存里也是连续存放的，所以可以用第11行的v来表示地址

int isidentity(int *p)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int v = *(p + 5 * i + j); //等价于p + (5 * i + j) * sizeof(int)
									  //v代表第i行j列的值
			if (i == j)
			{
				if (!v) return 0;
			}
			else
			{
				if (v) return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int a[5][5] = {0};
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &a[i][j]);
	
	printf("%d", isidentity(&a[0][0]));
	return 0;
}
