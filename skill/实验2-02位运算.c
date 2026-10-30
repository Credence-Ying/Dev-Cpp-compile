#include<stdio.h>

int main()
{
	unsigned short x;
	int m, n;
	
	scanf("%hx %d %d", &x, &m, &n);
	
	if (m < 0 || m > 15 || n < 1 || n > 16 - m)
	{
		printf("error");
		return 0;
	} 
	
	unsigned short ans = ((x >> m) & ((1 << n) - 1)) << (16 - n);
	//把x向右移动m位
	//通过"按位与"操作 利用"最低n位全为1的掩码" 达到"保留最低n位 其他n位全清零"的效果
	//把上述操作之后的结果向左移动(16-n)位 达到"向左对齐"的效果
	
	
	printf("%hx", ans); //"%hx"是按照十六进制输出unsigned short整数
	return 0;
}
