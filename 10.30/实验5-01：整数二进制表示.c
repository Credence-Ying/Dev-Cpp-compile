#include<stdio.h>

int main()
{
	int n = 0;
	char c[33];
	scanf("%d", &n);
	
	unsigned int u = (unsigned int)n;
	
	for (int i = 0; i < 32; i++)
	{
		c[i] = ( (u >> (31 - i)) & 1u) ? '1' : '0';
	}
	c[32] = '\0';
	
	printf("%s", c);
	return 0;
}
