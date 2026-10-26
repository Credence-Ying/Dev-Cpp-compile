#include<stdio.h>

int main()
{
	for(int i = 100; i <= 999; i++)
	{
		if (i == i * i % 1000) printf("%d\n",i);
	}
	return 0;
}
