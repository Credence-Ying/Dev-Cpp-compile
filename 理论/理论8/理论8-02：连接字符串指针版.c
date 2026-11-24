#include<stdio.h>

#define MAXN 10005

char *strnCat(char *dest, const char *src, int n)
{
	char *p = dest;
	const char *q = src;
	int cnt = 0;
	
	while (*p != '\0') p++; //此时p指向dest的\0
	
	while (cnt < n && *q != '\0')
	{
		*p = *q;
		p++;
		q++;
		cnt++;
	}
	
	return dest;
}


int main()
{
	char dest[MAXN]; //目标串
	char src[MAXN]; //源串
	int n = 0;
	
	scanf("%s", dest);
	scanf("%s", src);
	scanf("%d", &n);
	
	strnCat(dest, src, n); //等价于char *ans = strnCat(dest, src, n);
	printf("%s", dest); //函数里直接改变了dest，可以作为结果直接输出，也可以另开指针变量存结果
	return 0;
}
