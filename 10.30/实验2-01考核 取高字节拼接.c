#include<stdio.h>

unsigned short k = 0, p = 0;

int main()
{
	scanf("%hx %hx", &k, &p);
	
	unsigned short ans = ((p >> 8) & 0xFF) << 8 | ((k >> 8) & 0xFF);
	
	printf("%hx\n", ans);
	return 0;
}
