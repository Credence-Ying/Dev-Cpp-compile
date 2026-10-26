#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double swift = 1;
double add = 1;
double pi = 0;
double temp = 1;

int main()
{
	while(fabs(temp) >= 0.00001) //abs是取int型的绝对值，fabs是取double型的绝对值，分别定义在stdlib.h和math.h中
	{
		pi += 4 * temp;
		swift = -swift;
		add += 2;
		temp = swift / add;
	}
	printf("%f", pi);
	return 0;
}
