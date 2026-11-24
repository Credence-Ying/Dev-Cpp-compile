#include<stdio.h>

#define SWAP(x, y)  { int t = x; x = y; y = t; }
//不建议这么写，仍然建议以do{}while(0)的写法来避免加分号出错

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	SWAP(a, b)
	printf("%d %d\n", a, b);
	return 0;
}
