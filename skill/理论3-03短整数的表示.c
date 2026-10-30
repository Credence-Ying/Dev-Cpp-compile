#include<stdio.h>
#include<limits.h>

void bit_printf(short x)
{
	int n = sizeof(short) * CHAR_BIT; // n = 2 * 8 == 16
	int mask = 1 << (n-1);
	
	for (int i = 1; i <= n; i++)
	{
		putchar((x & mask) ? '1' : '0'); //直接输出的是 '0' '1' 
		x <<= 1;
		if ((i % CHAR_BIT == 0) && i < n) putchar(' ');
	}
}

int main()
{
	short x;
	scanf("%hd", &x);
	bit_printf(x);
	return 0;
}
