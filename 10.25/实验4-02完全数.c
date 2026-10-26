#include<stdio.h>
#include<stdbool.h>

int num = 0;
int a[10000] = {0};

bool isperfect(int k)
{
	num = 0;
	int cnt = 0;
	for (int i = 1; i <= k/2; i++)
	{
		if (k % i == 0)
		{
			num++;
			cnt += i;
			a[num] = i;
		} 
	}
	if (k == cnt) return true;
	else return false;
}

int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		if(isperfect(i))
		{
			printf("%d=", i);
			for (int j = 1; j < num; j++) printf("%d+", a[j]);
			printf("%d\n", a[num]);
			num = 0;
		}
	}
	return 0;
}
