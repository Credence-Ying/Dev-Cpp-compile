#include<stdio.h>

int main()
{
	unsigned long long ip = 0;
	while(scanf("%llu", &ip) == 1)
	{
		unsigned int v = (unsigned int)(ip & 0xFFFFFFFFULL);
		printf("%u.%u.%u.%u\n", 
				(v >> 24) & 0xff,
				(v >> 16) & 0xff,
				(v >> 8) & 0xff,
				v & 0xff);
	}

	return 0;
}
