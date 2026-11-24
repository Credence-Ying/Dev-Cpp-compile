#include<stdio.h>

void move(int n, int a, int b, int c)
{
	static int i = 1;
	if (n == 1)
		printf("step%d:%c->%c\n", i++, a, c);
	else
	{
		move(n - 1, a, c, b); //把n-1个盘子从A挪到B，通过C来周转
		printf("step%d:%c->%c\n",i++, a, c);
		move(n - 1, b, a, c); //把n-1个盘子从B挪到C，通过A来周转
		//把一大坨放到中转站->移动最大盘到目标->把那一大坨放过去
	}
}

int main()
{
	move(8, 'A', 'B', 'C');
	return 0;
}
