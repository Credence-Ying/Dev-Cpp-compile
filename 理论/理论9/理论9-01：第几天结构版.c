#include<stdio.h>
#include<string.h>

typedef struct
{
	int year;
	int month;
	int day;
}Date;

Date d;

int isleap(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return 1;
	else return 0;
}

int day_of_month(int y,int m)
{
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (m == 2 && isleap(y)) return 29;
	return days[m];
}

int main()
{
	scanf("%d%d%d", &d.year, &d.month, &d.day);
	
	if (d.month < 1 || d.month > 12)
	{
		printf("error\n");
		return 0;
	}
	
	if(d.day < 1 || d.day > day_of_month(d.year, d.month))
	{
		printf("error\n");
		return 0;
	}
	
	int sum = 0;
	for (int i = 1; i < d.month; i++) sum += day_of_month(d.year, i);
	sum += d.day;
	
	printf("%d", sum);
	return 0;
}
