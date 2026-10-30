#include<stdio.h>

#define SWAP(x, y)  { int t = x; x = y; y = t; }


int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	SWAP(a, b)
	printf("%d %d\n", a, b);
	return 0;
}
