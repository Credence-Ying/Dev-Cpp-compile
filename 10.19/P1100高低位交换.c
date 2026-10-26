#include<stdio.h>

unsigned int n = 0;
unsigned left, right;

int main()
{
	scanf("%u", &n);
	
	left = n & 0x0000ffff;
	right = n & 0xffff0000;
	
	n = (left << 16) | (right >> 16);
	
	printf("%u", n);
	return 0;
}
