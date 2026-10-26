#include<stdio.h>
#include<stdbool.h>

int a[15] = {0};
int cnt = 0;

bool isjudge(int k) //判断是否含5
{
	while(k > 0) //此处若改为10则56会出错
	{
		if (k % 10 == 5) return true;
		k /= 10;
	}
	return false;
}

int main()
{
	for (int i = 1; i <= 10; i++) scanf("%d", &a[i]);
	
	for (int i = 1; i <= 10; i++)
	{
		if(a[i] <= 10000 && a[i] % 7 == 0 && isjudge(a[i]))
		{
			printf("%d ", a[i]);
			cnt++;
		}
	}
	if(cnt == 0) printf("0");
	
	return 0;
}
