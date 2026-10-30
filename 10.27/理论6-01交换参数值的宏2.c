#include<stdio.h>

#define SWAP(x, y)             \
    do {                       \
        int t = (x);           \
        (x) = (y);             \
        (y) = t;               \
    } while (0)
//define默认换行结束，每行用反斜杠\连接

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	SWAP(a,b);
	printf("%d %d", a, b);
	return 0;
}
