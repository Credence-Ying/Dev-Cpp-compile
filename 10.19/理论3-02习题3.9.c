#include<stdio.h>

int main()
{
	unsigned short k;
	unsigned short low, mid, high, ans;
	scanf("%hu", &k);
	
	//分别提取低4位，中8位，高4位
	low = k & ((1<<4)-1);
	mid = k & 0x0ff0;
	high = k & 0xf000;
	
	ans = (low<<12) | mid | (high>>12);
	printf("%hu\n", ans);
	return 0;
}
