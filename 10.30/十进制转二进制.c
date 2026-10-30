#include<stdio.h>

void dec2bin(int n)
{
	if (n > 1) dec2bin(n / 2);   // 先递归处理高位
	printf("%d", n % 2);         // 回来再输出本位
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	dec2bin(n);
	
	return 0;
}
