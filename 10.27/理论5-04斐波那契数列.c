#include <stdio.h>

long F(int n) {
    if(n == 1 || n == 2) return 1;
    long long a = 1, b = 1, c = 0;
    for (int i = 3; i <= n; i++)
    {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%ld",F(n));
    return 0;
}
