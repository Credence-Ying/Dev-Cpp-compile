#include<stdio.h>

long long n = 0;
int cnt = 0;
int temp = 0;
int max = 0;

int main()
{
	printf("请输入一个正整数：");
	scanf("%lld", &n);
	while(n > 0)
	{
		temp = n % 10;
		if (temp == 0) cnt++;
		if (temp > max) max = temp;
		n /= 10; //int 类型的正数运算方法是舍弃小数(无论正负)
	}
	printf("该数有%d个0,最大数字为%d", cnt, max);
	return 0;
}
