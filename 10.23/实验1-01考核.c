#include<stdio.h>

int n = 0;
int count = 0, min = 0;

int main()
{
	scanf("%d", &n);
	min = n % 10;
	
	while(n > 0)
	{
		if(n % 10 == 8) count++;
		if(min > (n % 10)) min = n % 10;
		n /= 10;
	}
	
	printf("该数有%d个8，最小数字是%d\n", count, min);
	return 0;
}
