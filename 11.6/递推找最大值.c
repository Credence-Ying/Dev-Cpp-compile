#include<stdio.h>

int max(int n)
{
	int m;
	scanf("%d", &m);
	if (m == 0) return m > n ? m : n; //输入0结束
	else return m > n ? max(m) : max(n); //保留大的那个
}

int main()
{
	printf("The max number is: %d.\n", max(0));
	return 0;
}
