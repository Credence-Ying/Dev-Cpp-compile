#include<stdio.h>

/*
int *p;这里的*是在定义p为一个指针
int t = *p;这里的*是在解指针,这一步会将指针p对应的值赋给t
int *x = &t;这里的&是取指针的意思，会将变量t对应的地址赋给x
此时有 *x == *p
*/

/*
void swap(int a, int b)
{
	int t = a;
	a = b;
	b = t; 
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	printf("%d %d", n, m);
	swap(n,m);
	printf("%d %d", n, m);
	return 0;
}
*/  
//会发现上述程序行不通，因为swap只是改变了局部函数a,b(形参)而本尊n,m(实参)并没有被改变
//下面的程序采用指针写法，直接将n,m的指针位置传给swap函数，这样就能够改变main函数中变量的值了

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t; 
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	printf("%d %d", n, m);
	swap(&n,&m);
	printf("%d %d", n, m);
	return 0;
}
