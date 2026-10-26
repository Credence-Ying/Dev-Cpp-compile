#include<stdio.h>

int year = 0, month = 0, day = 0;
int a[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ans = 0;

int main()
{
	scanf("%d%d%d", &year, &month, &day);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) a[2] = 29;
	for (int i = 1; i < month; i++)
	{
		ans += a[i];
	}
	ans += day;
	printf("%d", ans);
	return 0;
}
