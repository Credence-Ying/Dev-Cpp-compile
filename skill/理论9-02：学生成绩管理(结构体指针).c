#include<stdio.h>

#define MAXN 10005

typedef struct
{
	int num;
	char name[20];
	int score;
}Student;

Student stu[MAXN];
Student *p;

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %19s %d", &stu[i].num, stu[i].name, &stu[i].score);
	
	p = &stu[n];
	
	for (int i = 1; i <= n; i++)
		printf("%d %s %d\n", stu[i].num, stu[i].name, stu[i].score);
		
	for (int i = 1; i <= n; i++)
	{
		printf("%d %s %d\n", p -> num, p -> name, p -> score); //p -> num等价于(*p).num等价于p[0].num
		p--;
	}
	return 0;
}
